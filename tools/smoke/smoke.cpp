// Smoke test for a TFC server DLL without the game engine.
//
// Loads tfc.so with a minimal fake engine (entities, strings, cvars, user
// messages, traces that never hit), then:
//   1. GiveFnptrsToDll / GetEntityAPI2 / GetNewDLLFunctions / GameInit
//   2. worldspawn + every exported entity class: create, KeyValue, Spawn
//   3. ServerActivate, a client connects, joins a team and class, and the
//      server runs frames (StartFrame, PlayerPreThink/PostThink, think
//      functions of every entity).
// A crash prints the step and entity it happened in, then the run goes on
// with the next item.
//
// Build: tools/smoke/build.sh   Run: build/smoke build/tfc.so [names.txt]
#include <dlfcn.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

#include "extdll.h"

#define MAX_EDICTS 2048

static edict_t g_edicts[MAX_EDICTS];
static int g_numEdicts = 1;
static globalvars_t g_globals;
static enginefuncs_t g_eng;
static DLL_FUNCTIONS g_dll;
static NEW_DLL_FUNCTIONS g_newdll;
static void *g_lib;
static char *g_strings;
static int g_stringUsed = 1;
static std::vector<cvar_t *> g_cvars;
static std::vector<std::pair<std::string, std::string> > g_engineCvars;
static int g_userMsgs = 64;
static int g_precache;
static const char *g_step = "start";
static std::string g_entity;
static std::vector<std::string> g_cmdArgv;
static std::string g_cmdArgs;
static int g_crashes;
static sigjmp_buf g_jump;
static int g_verbose;

//=========================================================
// strings
//=========================================================
static int AllocString( const char *s )
{
	int len = strlen( s ) + 1;
	if ( g_stringUsed + len > 16 * 1024 * 1024 )
	{
		fprintf( stderr, "string arena full\n" );
		exit( 2 );
	}
	memcpy( g_strings + g_stringUsed, s, len );
	int idx = g_stringUsed;
	g_stringUsed += len;
	return idx;
}

static const char *SzFromIndex( int i ) { return g_strings + i; }
static const char *Str( string_t i ) { return g_strings + i; }

//=========================================================
// edicts
//=========================================================
static edict_t *NewEdict( void )
{
	int start = g_globals.maxClients + 1;
	for ( int i = start; i < g_numEdicts; i++ )
	{
		if ( g_edicts[i].free )
		{
			memset( &g_edicts[i], 0, sizeof( edict_t ) );
			g_edicts[i].v.pContainingEntity = &g_edicts[i];
			return &g_edicts[i];
		}
	}
	if ( g_numEdicts >= MAX_EDICTS )
	{
		fprintf( stderr, "out of edicts\n" );
		exit( 2 );
	}
	edict_t *e = &g_edicts[g_numEdicts++];
	memset( e, 0, sizeof( edict_t ) );
	e->v.pContainingEntity = e;
	return e;
}

static int IndexOfEdict( const edict_t *e ) { return e ? (int)( e - g_edicts ) : 0; }
static edict_t *PEntityOfEntIndex( int i ) { return ( i >= 0 && i < g_numEdicts ) ? &g_edicts[i] : NULL; }
static int EntOffsetOfPEntity( const edict_t *e ) { return e ? (int)( (const char *)e - (const char *)g_edicts ) : 0; }
static edict_t *PEntityOfEntOffset( int off ) { return (edict_t *)( (char *)g_edicts + off ); }
static entvars_t *GetVarsOfEnt( edict_t *e ) { return &e->v; }
static edict_t *FindEntityByVars( entvars_t *v ) { return v->pContainingEntity; }
static edict_t *CreateEntity( void ) { return NewEdict(); }

static void FreeEntPrivateData( edict_t *e )
{
	if ( e->pvPrivateData )
	{
		if ( g_newdll.pfnOnFreeEntPrivateData )
			g_newdll.pfnOnFreeEntPrivateData( e );
		free( e->pvPrivateData );
		e->pvPrivateData = NULL;
	}
}

static void RemoveEntity( edict_t *e )
{
	if ( !e || e == g_edicts )
		return;
	if ( getenv( "SMOKE_TRACE" ) && g_globals.time > 1.05 )
		printf( "  t=%.1f remove %s\n", g_globals.time, Str( e->v.classname ) );
	FreeEntPrivateData( e );
	e->free = 1;
	e->v.flags = 0;
	e->v.classname = 0;
}

static void *PvAllocEntPrivateData( edict_t *e, int32 cb )
{
	FreeEntPrivateData( e );
	e->pvPrivateData = calloc( 1, cb );
	return e->pvPrivateData;
}

static void *PvEntPrivateData( edict_t *e ) { return e ? e->pvPrivateData : NULL; }

typedef void ( *LINK_ENTITY_FUNC )( entvars_t * );

static edict_t *CreateNamedEntity( int className )
{
	const char *name = Str( className );
	LINK_ENTITY_FUNC f = (LINK_ENTITY_FUNC)dlsym( g_lib, name );
	if ( !f )
	{
		if ( g_verbose )
			fprintf( stderr, "  no entity function for %s\n", name );
		return NULL;
	}
	edict_t *e = NewEdict();
	e->v.classname = className;
	f( &e->v );
	return e;
}

static edict_t *FindEntityByString( edict_t *start, const char *field, const char *value )
{
	int i = start ? IndexOfEdict( start ) + 1 : 1;
	for ( ; i < g_numEdicts; i++ )
	{
		edict_t *e = &g_edicts[i];
		if ( e->free )
			continue;
		string_t s = 0;
		if ( !strcmp( field, "classname" ) )
			s = e->v.classname;
		else if ( !strcmp( field, "targetname" ) )
			s = e->v.targetname;
		else if ( !strcmp( field, "target" ) )
			s = e->v.target;
		else if ( !strcmp( field, "netname" ) )
			s = e->v.netname;
		else if ( !strcmp( field, "message" ) )
			s = e->v.message;
		if ( s && !strcmp( Str( s ), value ) )
			return e;
	}
	return &g_edicts[0];
}

static edict_t *FindEntityInSphere( edict_t *start, const float *org, float rad )
{
	int i = start ? IndexOfEdict( start ) + 1 : 1;
	for ( ; i < g_numEdicts; i++ )
	{
		edict_t *e = &g_edicts[i];
		if ( e->free || !e->pvPrivateData )
			continue;
		float d = 0;
		for ( int j = 0; j < 3; j++ )
		{
			float c = org[j] - ( e->v.origin[j] );
			d += c * c;
		}
		if ( sqrtf( d ) <= rad )
			return e;
	}
	return &g_edicts[0];
}

static edict_t *FindClientInPVS( edict_t *e ) { return &g_edicts[0]; }
static edict_t *EntitiesInPVS( edict_t *e ) { return &g_edicts[0]; }
static int NumberOfEntities( void ) { return g_numEdicts; }

//=========================================================
// math
//=========================================================
static void AngleVectors( const float *angles, float *forward, float *right, float *up )
{
	float sr, sp, sy, cr, cp, cy;
	float a = angles[1] * ( M_PI * 2 / 360 );
	sy = sinf( a ); cy = cosf( a );
	a = angles[0] * ( M_PI * 2 / 360 );
	sp = sinf( a ); cp = cosf( a );
	a = angles[2] * ( M_PI * 2 / 360 );
	sr = sinf( a ); cr = cosf( a );
	if ( forward ) { forward[0] = cp * cy; forward[1] = cp * sy; forward[2] = -sp; }
	if ( right ) { right[0] = -1 * sr * sp * cy + -1 * cr * -sy; right[1] = -1 * sr * sp * sy + -1 * cr * cy; right[2] = -1 * sr * cp; }
	if ( up ) { up[0] = cr * sp * cy + -sr * -sy; up[1] = cr * sp * sy + -sr * cy; up[2] = cr * cp; }
}

static void MakeVectors( const float *angles )
{
	AngleVectors( angles, g_globals.v_forward, g_globals.v_right, g_globals.v_up );
}

static float VecToYaw( const float *v )
{
	if ( v[1] == 0 && v[0] == 0 )
		return 0;
	float yaw = atan2f( v[1], v[0] ) * 180 / M_PI;
	if ( yaw < 0 )
		yaw += 360;
	return yaw;
}

static void VecToAngles( const float *v, float *out )
{
	float yaw = VecToYaw( v ), pitch;
	float forward = sqrtf( v[0] * v[0] + v[1] * v[1] );
	pitch = atan2f( v[2], forward ) * 180 / M_PI;
	if ( pitch < 0 )
		pitch += 360;
	out[0] = pitch; out[1] = yaw; out[2] = 0;
}

//=========================================================
// traces: no world geometry; rays hit the bounding boxes of solid
// entities (SOLID_BBOX / SOLID_SLIDEBOX) so hitscan weapons work
//=========================================================
static void ClearTrace( const float *v1, const float *v2, TraceResult *tr )
{
	memset( tr, 0, sizeof( *tr ) );
	tr->flFraction = 1.0;
	tr->fInOpen = 1;
	tr->vecEndPos = Vector( (float *)v2 );
	tr->pHit = &g_edicts[0];
}

static bool RayBox( const float *a, const float *b, const Vector &mins, const Vector &maxs, float *frac, int *axis, int *side )
{
	float t0 = 0, t1 = 1;
	int ax = -1, sd = 0;
	for ( int i = 0; i < 3; i++ )
	{
		float d = b[i] - a[i];
		if ( fabsf( d ) < 1e-6f )
		{
			if ( a[i] < mins[i] || a[i] > maxs[i] )
				return false;
			continue;
		}
		float n = ( mins[i] - a[i] ) / d, f = ( maxs[i] - a[i] ) / d;
		int s = -1;
		if ( n > f ) { float t = n; n = f; f = t; s = 1; }
		if ( n > t0 ) { t0 = n; ax = i; sd = s; }
		if ( f < t1 ) t1 = f;
		if ( t0 > t1 )
			return false;
	}
	*frac = t0; *axis = ax; *side = sd;
	return true;
}

static void TraceAgainstEntities( const float *v1, const float *v2, int fNoMonsters, edict_t *skip, TraceResult *tr )
{
	ClearTrace( v1, v2, tr );

	// the world is a floor at z = 0
	if ( v1[2] >= 0 && v2[2] < 0 )
	{
		float f = v1[2] / ( v1[2] - v2[2] );
		tr->flFraction = f;
		for ( int j = 0; j < 3; j++ )
			tr->vecEndPos[j] = v1[j] + ( v2[j] - v1[j] ) * f;
		tr->vecPlaneNormal = Vector( 0, 0, 1 );
		tr->pHit = &g_edicts[0];
		tr->fInOpen = 0;
	}

	if ( fNoMonsters == 1 )
		return;
	edict_t *owner = skip ? skip->v.owner : NULL;
	for ( int i = 1; i < g_numEdicts; i++ )
	{
		edict_t *e = &g_edicts[i];
		if ( e->free || e == skip || ( owner && e == owner ) || ( skip && e->v.owner == skip ) )
			continue;
		if ( e->v.solid != SOLID_BBOX && e->v.solid != SOLID_SLIDEBOX )
			continue;
		float f; int ax, sd;
		if ( RayBox( v1, v2, e->v.origin + e->v.mins, e->v.origin + e->v.maxs, &f, &ax, &sd ) && f < tr->flFraction )
		{
			if ( f == 0 && ax < 0 )
			{
				tr->fStartSolid = 1;
				ax = 2;
			}
			tr->flFraction = f;
			for ( int j = 0; j < 3; j++ )
				tr->vecEndPos[j] = v1[j] + ( v2[j] - v1[j] ) * f;
			tr->vecPlaneNormal = Vector( 0, 0, 0 );
			if ( ax >= 0 )
				tr->vecPlaneNormal[ax] = (float)sd;
			tr->pHit = e;
			tr->iHitgroup = 2; // chest
		}
	}
}

static void TraceLine( const float *v1, const float *v2, int fNoMonsters, edict_t *skip, TraceResult *tr ) { TraceAgainstEntities( v1, v2, fNoMonsters, skip, tr ); }
static void TraceHull( const float *v1, const float *v2, int fNoMonsters, int, edict_t *skip, TraceResult *tr ) { TraceAgainstEntities( v1, v2, fNoMonsters, skip, tr ); }
static void TraceModel( const float *v1, const float *v2, int, edict_t *, TraceResult *tr ) { ClearTrace( v1, v2, tr ); }
static int TraceMonsterHull( edict_t *e, const float *v1, const float *v2, int fNoMonsters, edict_t *skip, TraceResult *tr ) { TraceAgainstEntities( v1, v2, fNoMonsters, skip, tr ); return tr->flFraction < 1; }
static void TraceToss( edict_t *e, edict_t *, TraceResult *tr ) { ClearTrace( e->v.origin, e->v.origin, tr ); }
static void TraceSphere( const float *v1, const float *v2, int fNoMonsters, float, edict_t *skip, TraceResult *tr ) { TraceAgainstEntities( v1, v2, fNoMonsters, skip, tr ); }
static const char *TraceTexture( edict_t *, const float *, const float * ) { return NULL; }
static int PointContents( const float * ) { return -1; } // CONTENTS_EMPTY

//=========================================================
// precache / models
//=========================================================
static int Precache( char *s )
{
	if ( getenv( "SMOKE_MSG" ) )
		printf( "precache %d %s\n", g_precache + 1, s );
	return ++g_precache;
}
static int ModelIndex( const char *m ) { return 1; }
static int ModelFrames( int ) { return 1; }
// SMOKE_MAP: brush model bounds from the BSP's model lump
struct BspModel { float mins[3], maxs[3], origin[3]; int headnode[4], visleafs, firstface, numfaces; };
static std::vector<BspModel> g_bspModels;

static void SetModel( edict_t *e, const char *m )
{
	e->v.model = AllocString( m );
	e->v.modelindex = 1;
	if ( m && m[0] == '*' )
	{
		size_t i = atoi( m + 1 );
		if ( i < g_bspModels.size() )
		{
			e->v.modelindex = i + 1;
			e->v.mins = Vector( g_bspModels[i].mins );
			e->v.maxs = Vector( g_bspModels[i].maxs );
			e->v.size = e->v.maxs - e->v.mins;
			e->v.absmin = e->v.origin + e->v.mins;
			e->v.absmax = e->v.origin + e->v.maxs;
		}
	}
}

// SMOKE_MAP: the BSP's entity lump as a list of key/value lists
typedef std::vector<std::pair<std::string, std::string> > MapEntity;
static std::vector<MapEntity> LoadBsp( const char *path )
{
	std::vector<MapEntity> ents;
	FILE *f = fopen( path, "rb" );
	if ( !f )
	{
		fprintf( stderr, "can't open %s\n", path );
		exit( 1 );
	}
	int hdr[1 + 15 * 2];
	if ( fread( hdr, sizeof( hdr ), 1, f ) != 1 || hdr[0] != 30 )
	{
		fprintf( stderr, "%s: not a v30 BSP\n", path );
		exit( 1 );
	}
	std::string text( hdr[2], 0 );
	fseek( f, hdr[1], SEEK_SET );
	if ( fread( &text[0], 1, text.size(), f ) != text.size() )
		exit( 1 );
	g_bspModels.resize( hdr[1 + 14 * 2 + 1] / sizeof( BspModel ) );
	fseek( f, hdr[1 + 14 * 2], SEEK_SET );
	if ( !g_bspModels.empty() && fread( &g_bspModels[0], sizeof( BspModel ), g_bspModels.size(), f ) != g_bspModels.size() )
		exit( 1 );
	fclose( f );

	size_t p = 0;
	auto token = [&]( std::string &out ) -> bool {
		while ( p < text.size() && ( isspace( (unsigned char)text[p] ) || text[p] == 0 ) ) p++;
		if ( p >= text.size() ) return false;
		if ( text[p] == '"' )
		{
			size_t e = text.find( '"', p + 1 );
			if ( e == std::string::npos ) e = text.size();
			out = text.substr( p + 1, e - p - 1 );
			p = e + 1;
		}
		else
			out = text.substr( p++, 1 );
		return true;
	};
	std::string t, k, v;
	while ( token( t ) )
	{
		if ( t != "{" ) break;
		MapEntity ent;
		while ( token( k ) && k != "}" )
		{
			token( v );
			ent.push_back( std::make_pair( k, v ) );
		}
		ents.push_back( ent );
	}
	return ents;
}

static std::string EntValue( const MapEntity &e, const char *key )
{
	for ( size_t i = 0; i < e.size(); i++ )
		if ( e[i].first == key )
			return e[i].second;
	return "";
}

static void KeyValue( edict_t *e, const char *cls, const char *key, const char *value );

// what the engine does with each key before DispatchKeyValue
static void MapKeyValue( edict_t *e, const char *cls, const std::string &key, const std::string &value )
{
	if ( key == "classname" )
		return;
	if ( key == "angle" )
	{
		float a = atof( value.c_str() );
		char buf[64];
		if ( a == -1 ) snprintf( buf, sizeof( buf ), "-90 0 0" );
		else if ( a == -2 ) snprintf( buf, sizeof( buf ), "90 0 0" );
		else snprintf( buf, sizeof( buf ), "0 %g 0", a );
		KeyValue( e, cls, "angles", buf );
		return;
	}
	KeyValue( e, cls, key.c_str(), value.c_str() );
}
static void SetSize( edict_t *e, const float *mins, const float *maxs )
{
	e->v.mins = Vector( (float *)mins );
	e->v.maxs = Vector( (float *)maxs );
	e->v.size = e->v.maxs - e->v.mins;
}
static void SetOrigin( edict_t *e, const float *o )
{
	e->v.origin = Vector( (float *)o );
	e->v.absmin = e->v.origin + e->v.mins;
	e->v.absmax = e->v.origin + e->v.maxs;
}
static void *GetModelPtr( edict_t * ) { return NULL; }
static unsigned short PrecacheEvent( int, const char * ) { return 1; }
static int DecalIndex( const char * ) { return 1; }
static int DropToFloor( edict_t * ) { return 1; }
static int EntIsOnFloor( edict_t * ) { return 1; }
static int WalkMove( edict_t *, float, float, int ) { return 1; }
static int GetEntityIllum( edict_t * ) { return 128; }

//=========================================================
// cvars
//=========================================================
static cvar_t *FindCvar( const char *name )
{
	for ( size_t i = 0; i < g_cvars.size(); i++ )
		if ( !strcasecmp( g_cvars[i]->name, name ) )
			return g_cvars[i];
	return NULL;
}

static std::string *FindEngineCvar( const char *name )
{
	for ( size_t i = 0; i < g_engineCvars.size(); i++ )
		if ( !strcasecmp( g_engineCvars[i].first.c_str(), name ) )
			return &g_engineCvars[i].second;
	return NULL;
}

static void CVarRegister( cvar_t *c )
{
	if ( !FindCvar( c->name ) )
	{
		c->value = atof( c->string );
		g_cvars.push_back( c );
	}
}

static float CVarGetFloat( const char *name )
{
	cvar_t *c = FindCvar( name );
	if ( c )
		return c->value;
	std::string *s = FindEngineCvar( name );
	return s ? atof( s->c_str() ) : 0;
}

static const char *CVarGetString( const char *name )
{
	cvar_t *c = FindCvar( name );
	if ( c )
		return c->string;
	std::string *s = FindEngineCvar( name );
	return s ? s->c_str() : "";
}

static void CVarSetString( const char *name, const char *value )
{
	cvar_t *c = FindCvar( name );
	if ( c )
	{
		c->string = strdup( value );
		c->value = atof( value );
		return;
	}
	std::string *s = FindEngineCvar( name );
	if ( s )
		*s = value;
	else
		g_engineCvars.push_back( std::make_pair( std::string( name ), std::string( value ) ) );
}

static void CVarSetFloat( const char *name, float v )
{
	char buf[64];
	snprintf( buf, sizeof( buf ), "%g", v );
	CVarSetString( name, buf );
}

static void Cvar_DirectSet( cvar_t *c, char *value )
{
	c->string = strdup( value );
	c->value = atof( value );
}

static cvar_t *CVarGetPointer( const char *name ) { return FindCvar( name ); }

//=========================================================
// output
//=========================================================
static void AlertMessage( ALERT_TYPE t, char *fmt, ... )
{
	if ( !g_verbose && t != at_error )
		return;
	va_list ap;
	va_start( ap, fmt );
	fprintf( stderr, "  [alert %d] ", t );
	vfprintf( stderr, fmt, ap );
	va_end( ap );
}

static void EngineFprintf( void *f, char *fmt, ... )
{
	va_list ap;
	va_start( ap, fmt );
	vfprintf( stderr, fmt, ap );
	va_end( ap );
}

static void ServerPrint( const char *s )
{
	if ( g_verbose )
		fprintf( stderr, "  [print] %s", s );
}

static void ClientPrintf( edict_t *, PRINT_TYPE, const char *s )
{
	if ( g_verbose )
		fprintf( stderr, "  [client] %s", s );
}

static void ServerCommand( char *s )
{
	if ( g_verbose )
		fprintf( stderr, "  [servercmd] %s", s );
}

static void ClientCommand( edict_t *, char *fmt, ... ) {}

//=========================================================
// messages
//=========================================================
// SMOKE_MSG: every network message, by type name, with its payload
static int g_msgDepth;
static std::string g_msg;
static std::vector<std::string> g_msgNames;
static void MessageBegin( int dest, int type, const float *org, edict_t *ed )
{
	if ( g_msgDepth )
	{
		fprintf( stderr, "  !! MESSAGE_BEGIN inside a message (step %s, entity %s)\n", g_step, g_entity.c_str() );
		g_crashes++;
	}
	g_msgDepth = 1;
	if ( getenv( "SMOKE_MSG" ) )
	{
		char buf[96];
		const char *name = ( type > 64 && type - 65 < (int)g_msgNames.size() ) ? g_msgNames[type - 65].c_str() : NULL;
		if ( name )
			snprintf( buf, sizeof( buf ), "msg %d %s to %d:", dest, name, ed ? (int)( ed - g_edicts ) : -1 );
		else
			snprintf( buf, sizeof( buf ), "msg %d svc%d to %d:", dest, type, ed ? (int)( ed - g_edicts ) : -1 );
		g_msg = buf;
		if ( org )
		{
			snprintf( buf, sizeof( buf ), " @%g,%g,%g", org[0], org[1], org[2] );
			g_msg += buf;
		}
	}
}
static void MessageEnd( void )
{
	g_msgDepth = 0;
	if ( getenv( "SMOKE_MSG" ) )
		printf( "  t=%.2f %s\n", g_globals.time, g_msg.c_str() );
}
static void MsgAppend( const char *fmt, ... )
{
	if ( !getenv( "SMOKE_MSG" ) )
		return;
	char buf[300];
	va_list ap;
	va_start( ap, fmt );
	vsnprintf( buf, sizeof( buf ), fmt, ap );
	va_end( ap );
	g_msg += buf;
}
static void WriteByte( int v ) { MsgAppend( " b%d", v & 0xff ); }
static void WriteChar( int v ) { MsgAppend( " c%d", (signed char)v ); }
static void WriteShort( int v ) { MsgAppend( " s%d", (short)v ); }
static void WriteLong( int v ) { MsgAppend( " l%d", v ); }
static void WriteEntity( int v ) { MsgAppend( " e%d", v ); }
static void WriteAngle( float v ) { MsgAppend( " a%d", (int)( v * 256 / 360 ) & 255 ); }
static void WriteCoord( float v ) { MsgAppend( " f%d", (int)( v * 8 ) ); }	// 1/8 unit, as sent
static void WriteString( const char *v ) { MsgAppend( " \"%s\"", v ? v : "(null)" ); }
static int RegUserMsg( const char *name, int size )
{
	g_msgNames.push_back( name );
	if ( getenv( "SMOKE_MSG" ) )
		printf( "usermsg %d %s size %d\n", g_userMsgs + 1, name, size );
	return ++g_userMsgs;
}

//=========================================================
// commands
//=========================================================
static const char *Cmd_Args( void ) { return g_cmdArgs.c_str(); }
static const char *Cmd_Argv( int i ) { return ( i >= 0 && i < (int)g_cmdArgv.size() ) ? g_cmdArgv[i].c_str() : ""; }
static int Cmd_Argc( void ) { return g_cmdArgv.size(); }

//=========================================================
// misc
//=========================================================
static int g_rngLog = -1;
static int32 RandomLong( int32 lo, int32 hi )
{
	if ( g_rngLog < 0 ) g_rngLog = getenv( "SMOKE_RNG" ) != NULL;
	int32 r = hi <= lo ? lo : lo + rand() % ( hi - lo + 1 );
	if ( g_rngLog ) printf( "  rng t=%.1f L(%d,%d)=%d [%s %s]\n", g_globals.time, lo, hi, r, g_step, g_entity.c_str() );
	return r;
}
static float RandomFloat( float lo, float hi )
{
	if ( g_rngLog < 0 ) g_rngLog = getenv( "SMOKE_RNG" ) != NULL;
	float r = lo + ( hi - lo ) * ( rand() / (float)RAND_MAX );
	if ( g_rngLog ) printf( "  rng t=%.1f F(%g,%g)=%g [%s %s]\n", g_globals.time, lo, hi, r, g_step, g_entity.c_str() );
	return r;
}
static float Time( void ) { return g_globals.time; }
static byte *LoadFileForMe( char *, int *len ) { if ( len ) *len = 0; return NULL; }
static void FreeFile( void * ) {}
static void GetGameDir( char *dir ) { strcpy( dir, "tfc" ); }
static char g_infoBuffers[MAX_EDICTS][256];
static char *GetInfoKeyBuffer( edict_t *e ) { return g_infoBuffers[IndexOfEdict( e )]; }

static char *InfoKeyValue( char *buf, char *key )
{
	static char out[4][128];
	static int which;
	char *r = out[which = ( which + 1 ) & 3];
	r[0] = 0;
	std::string s = buf ? buf : "";
	std::string k = std::string( "\\" ) + key + "\\";
	size_t p = s.find( k );
	if ( p != std::string::npos )
	{
		p += k.size();
		size_t e = s.find( '\\', p );
		strncpy( r, s.substr( p, e == std::string::npos ? std::string::npos : e - p ).c_str(), 127 );
		r[127] = 0;
	}
	return r;
}

static void SetKeyValue( char *buf, char *key, char *value )
{
	std::string s = buf;
	std::string k = std::string( "\\" ) + key + "\\";
	size_t p = s.find( k );
	if ( p != std::string::npos )
	{
		size_t e = s.find( '\\', p + k.size() );
		s.erase( p, e == std::string::npos ? std::string::npos : e - p );
	}
	s += k + value;
	strncpy( buf, s.c_str(), 255 );
	buf[255] = 0;
}

static void SetClientKeyValue( int, char *buf, char *key, char *value ) { SetKeyValue( buf, key, value ); }
static void Info_RemoveKey( char *, const char * ) {}
static int IsMapValid( char * ) { return 1; }
static int IsDedicatedServer( void ) { return 1; }
static int GetPlayerUserId( edict_t *e ) { return IndexOfEdict( e ); }
static unsigned int GetPlayerWONId( edict_t *e ) { return IndexOfEdict( e ); }
static const char *GetPlayerAuthId( edict_t * ) { return "STEAM_ID_LAN"; }
static const char *GetPhysicsKeyValue( const edict_t *, const char * ) { return ""; }
static const char *GetPhysicsInfoString( const edict_t * ) { return ""; }
static unsigned char g_pvs[MAX_EDICTS / 8 + 64];
static unsigned char *SetFatPVS( float * ) { memset( g_pvs, 0xff, sizeof( g_pvs ) ); return g_pvs; }
static int CheckVisibility( const edict_t *, unsigned char * ) { return 1; }
static int CanSkipPlayer( const edict_t * ) { return 0; }
static int GetCurrentPlayer( void ) { return 0; }
static int CheckParm( const char *, char ** ) { return 0; }
static void GetPlayerStats( const edict_t *, int *ping, int *loss ) { *ping = 0; *loss = 0; }
static const char *NameForFunction( uint32 ) { return ""; }
static uint32 FunctionFromName( const char * ) { return 0; }
static qboolean VoiceGet( int, int ) { return 1; }
static qboolean VoiceSet( int, int, qboolean ) { return 1; }
static int GetFileSize( char * ) { return 0; }
static int CompareFileTime( char *, char *, int *c ) { *c = 0; return 0; }
static edict_t *CreateFakeClient( const char * ) { return NULL; }

// everything else: does nothing, returns 0
static int Nop( void ) { return 0; }

static void InitEngine( void )
{
	void **slots = (void **)&g_eng;
	for ( size_t i = 0; i < sizeof( g_eng ) / sizeof( void * ); i++ )
		slots[i] = (void *)Nop;

#define E( field, fn ) g_eng.field = ( decltype( g_eng.field ) )( fn )
	E( pfnPrecacheModel, Precache ); E( pfnPrecacheSound, Precache ); E( pfnPrecacheGeneric, Precache );
	E( pfnSetModel, SetModel ); E( pfnModelIndex, ModelIndex ); E( pfnModelFrames, ModelFrames );
	E( pfnSetSize, SetSize ); E( pfnSetOrigin, SetOrigin );
	E( pfnVecToYaw, VecToYaw ); E( pfnVecToAngles, VecToAngles );
	E( pfnFindEntityByString, FindEntityByString ); E( pfnGetEntityIllum, GetEntityIllum );
	E( pfnFindEntityInSphere, FindEntityInSphere ); E( pfnFindClientInPVS, FindClientInPVS );
	E( pfnEntitiesInPVS, EntitiesInPVS ); E( pfnMakeVectors, MakeVectors ); E( pfnAngleVectors, AngleVectors );
	E( pfnCreateEntity, CreateEntity ); E( pfnRemoveEntity, RemoveEntity ); E( pfnCreateNamedEntity, CreateNamedEntity );
	E( pfnEntIsOnFloor, EntIsOnFloor ); E( pfnDropToFloor, DropToFloor ); E( pfnWalkMove, WalkMove );
	E( pfnTraceLine, TraceLine ); E( pfnTraceToss, TraceToss ); E( pfnTraceMonsterHull, TraceMonsterHull );
	E( pfnTraceHull, TraceHull ); E( pfnTraceModel, TraceModel ); E( pfnTraceTexture, TraceTexture );
	E( pfnTraceSphere, TraceSphere );
	E( pfnServerCommand, ServerCommand ); E( pfnClientCommand, ClientCommand );
	E( pfnDecalIndex, DecalIndex ); E( pfnPointContents, PointContents );
	E( pfnMessageBegin, MessageBegin ); E( pfnMessageEnd, MessageEnd );
	E( pfnWriteByte, WriteByte ); E( pfnWriteChar, WriteChar ); E( pfnWriteShort, WriteShort ); E( pfnWriteLong, WriteLong );
	E( pfnWriteAngle, WriteAngle ); E( pfnWriteCoord, WriteCoord ); E( pfnWriteString, WriteString ); E( pfnWriteEntity, WriteEntity );
	E( pfnCVarRegister, CVarRegister ); E( pfnCvar_RegisterVariable, CVarRegister );
	E( pfnCVarGetFloat, CVarGetFloat ); E( pfnCVarGetString, CVarGetString );
	E( pfnCVarSetFloat, CVarSetFloat ); E( pfnCVarSetString, CVarSetString );
	E( pfnCvar_DirectSet, Cvar_DirectSet ); E( pfnCVarGetPointer, CVarGetPointer );
	E( pfnAlertMessage, AlertMessage ); E( pfnEngineFprintf, EngineFprintf );
	E( pfnPvAllocEntPrivateData, PvAllocEntPrivateData ); E( pfnPvEntPrivateData, PvEntPrivateData );
	E( pfnFreeEntPrivateData, FreeEntPrivateData );
	E( pfnSzFromIndex, SzFromIndex ); E( pfnAllocString, AllocString );
	E( pfnGetVarsOfEnt, GetVarsOfEnt ); E( pfnPEntityOfEntOffset, PEntityOfEntOffset );
	E( pfnEntOffsetOfPEntity, EntOffsetOfPEntity ); E( pfnIndexOfEdict, IndexOfEdict );
	E( pfnPEntityOfEntIndex, PEntityOfEntIndex ); E( pfnPEntityOfEntIndexAllEntities, PEntityOfEntIndex );
	E( pfnFindEntityByVars, FindEntityByVars ); E( pfnGetModelPtr, GetModelPtr );
	E( pfnRegUserMsg, RegUserMsg ); E( pfnFunctionFromName, FunctionFromName ); E( pfnNameForFunction, NameForFunction );
	E( pfnClientPrintf, ClientPrintf ); E( pfnServerPrint, ServerPrint );
	E( pfnCmd_Args, Cmd_Args ); E( pfnCmd_Argv, Cmd_Argv ); E( pfnCmd_Argc, Cmd_Argc );
	E( pfnRandomLong, RandomLong ); E( pfnRandomFloat, RandomFloat ); E( pfnTime, Time );
	E( pfnLoadFileForMe, LoadFileForMe ); E( pfnFreeFile, FreeFile ); E( pfnCompareFileTime, CompareFileTime );
	E( pfnGetGameDir, GetGameDir ); E( pfnCreateFakeClient, CreateFakeClient );
	E( pfnNumberOfEntities, NumberOfEntities ); E( pfnGetInfoKeyBuffer, GetInfoKeyBuffer );
	E( pfnInfoKeyValue, InfoKeyValue ); E( pfnSetKeyValue, SetKeyValue ); E( pfnSetClientKeyValue, SetClientKeyValue );
	E( pfnIsMapValid, IsMapValid ); E( pfnGetPlayerUserId, GetPlayerUserId ); E( pfnIsDedicatedServer, IsDedicatedServer );
	E( pfnGetPlayerWONId, GetPlayerWONId ); E( pfnInfo_RemoveKey, Info_RemoveKey );
	E( pfnGetPhysicsKeyValue, GetPhysicsKeyValue ); E( pfnGetPhysicsInfoString, GetPhysicsInfoString );
	E( pfnPrecacheEvent, PrecacheEvent ); E( pfnSetFatPVS, SetFatPVS ); E( pfnSetFatPAS, SetFatPVS );
	E( pfnCheckVisibility, CheckVisibility ); E( pfnCanSkipPlayer, CanSkipPlayer ); E( pfnGetCurrentPlayer, GetCurrentPlayer );
	E( pfnGetPlayerStats, GetPlayerStats ); E( pfnVoice_GetClientListening, VoiceGet ); E( pfnVoice_SetClientListening, VoiceSet );
	E( pfnGetPlayerAuthId, GetPlayerAuthId ); E( pfnGetFileSize, GetFileSize ); E( pfnCheckParm, CheckParm );
#undef E
}

//=========================================================
// crash handling
//=========================================================
static void OnCrash( int sig )
{
	siglongjmp( g_jump, sig );
}

#define GUARD( step, name, body )                                                   \
	do {                                                                            \
		g_step = step;                                                              \
		g_entity = name;                                                            \
		g_msgDepth = 0;                                                             \
		int _sig = sigsetjmp( g_jump, 1 );                                          \
		if ( _sig == 0 ) { body; }                                                  \
		else { g_crashes++; fprintf( stderr, "CRASH (signal %d) in %s: %s\n", _sig, step, g_entity.c_str() ); } \
	} while ( 0 )

static void KeyValue( edict_t *e, const char *cls, const char *key, const char *value )
{
	KeyValueData kvd;
	kvd.szClassName = (char *)cls;
	kvd.szKeyName = (char *)key;
	kvd.szValue = (char *)value;
	kvd.fHandled = 0;
	g_dll.pfnKeyValue( e, &kvd );
}

static void RunThinks( void )
{
	for ( int i = 1; i < g_numEdicts; i++ )
	{
		edict_t *e = &g_edicts[i];
		if ( e->free || !e->pvPrivateData )
			continue;
		if ( e->v.nextthink > 0 && e->v.nextthink <= g_globals.time )
		{
			e->v.nextthink = 0;
			float h = g_edicts[1].v.health;
			GUARD( "Think", Str( e->v.classname ), g_dll.pfnThink( e ) );
			if ( getenv( "SMOKE_TRACE" ) && g_edicts[1].v.health != h )
				printf( "  t=%.1f health %g -> %g by think of %s (#%d)\n", g_globals.time, h, g_edicts[1].v.health, Str( e->v.classname ), i );
		}
		if ( e->v.flags & FL_KILLME )
			RemoveEntity( e );
	}
}

//=========================================================
// minimal physics for projectiles: fly/toss/bounce with a floor at z=0,
// hits on solid entity boxes call both touch functions like the engine
//=========================================================
static void RunPhysics( void )
{
	float ft = g_globals.frametime;
	for ( int i = g_globals.maxClients + 1; i < g_numEdicts; i++ )
	{
		edict_t *e = &g_edicts[i];
		if ( e->free || !e->pvPrivateData )
			continue;
		int mt = e->v.movetype;
		if ( mt != MOVETYPE_FLY && mt != MOVETYPE_TOSS && mt != MOVETYPE_BOUNCE && mt != MOVETYPE_FLYMISSILE && mt != MOVETYPE_BOUNCEMISSILE )
			continue;
		if ( ( mt == MOVETYPE_TOSS || mt == MOVETYPE_BOUNCE ) && !( e->v.flags & FL_ONGROUND ) )
			e->v.velocity.z -= ( e->v.gravity ? e->v.gravity : 1.0f ) * 800 * ft;
		e->v.angles = e->v.angles + e->v.avelocity * ft;
		if ( e->v.velocity == Vector( 0, 0, 0 ) )
			continue;
		Vector start = e->v.origin, end = start + e->v.velocity * ft;
		TraceResult tr;
		edict_t *skip = e;
		TraceAgainstEntities( start, end, 0, skip, &tr );
		// floor
		float floorz = -e->v.mins.z;
		if ( end.z < floorz && ( tr.flFraction == 1.0 || start.z + ( end.z - start.z ) * tr.flFraction < floorz ) )
		{
			float f = ( start.z - floorz ) / ( start.z - end.z );
			if ( f < 0 ) f = 0;
			tr.flFraction = f;
			tr.vecEndPos = start + ( end - start ) * f;
			tr.vecPlaneNormal = Vector( 0, 0, 1 );
			tr.pHit = &g_edicts[0];
		}
		e->v.origin = tr.vecEndPos;
		SetOrigin( e, e->v.origin );
		if ( tr.flFraction < 1.0 && !tr.fStartSolid )
		{
			edict_t *hit = tr.pHit;
			std::string cls = Str( e->v.classname );
			if ( getenv( "SMOKE_TRACE" ) )
				printf( "  t=%.2f %s hits %s at %.0f,%.0f,%.0f\n", g_globals.time, cls.c_str(),
					hit == &g_edicts[0] ? "world" : Str( hit->v.classname ), tr.vecEndPos.x, tr.vecEndPos.y, tr.vecEndPos.z );
			GUARD( "Touch", cls.c_str(), g_dll.pfnTouch( e, hit ) );
			if ( !e->free && hit && hit->pvPrivateData && hit != &g_edicts[0] )
				GUARD( "Touch", Str( hit->v.classname ), g_dll.pfnTouch( hit, e ) );
			if ( getenv( "SMOKE_TRACE" ) && hit && hit != &g_edicts[0] )
				printf( "    -> %s hp=%g ap=%g dmg_take=%g vel=%.1f,%.1f,%.1f\n", Str( hit->v.classname ), hit->v.health,
					hit->v.armorvalue, hit->v.dmg_take, hit->v.velocity.x, hit->v.velocity.y, hit->v.velocity.z );
			if ( e->free )
				continue;
			if ( e->v.movetype == MOVETYPE_BOUNCE || e->v.movetype == MOVETYPE_BOUNCEMISSILE || e->v.movetype == MOVETYPE_TOSS )
			{
				float backoff = e->v.movetype == MOVETYPE_TOSS ? 1.0f : 1.5f;
				float d = DotProduct( e->v.velocity, tr.vecPlaneNormal ) * backoff;
				e->v.velocity = e->v.velocity - tr.vecPlaneNormal * d;
				if ( tr.vecPlaneNormal.z > 0.7 && ( e->v.velocity.z < 60 || e->v.movetype == MOVETYPE_TOSS ) )
				{
					e->v.flags |= FL_ONGROUND;
					e->v.groundentity = hit;
					e->v.velocity = Vector( 0, 0, 0 );
					e->v.avelocity = Vector( 0, 0, 0 );
				}
			}
			else
				e->v.velocity = Vector( 0, 0, 0 );
		}
		if ( e->v.flags & FL_KILLME )
			RemoveEntity( e );
	}
}

// the engine's SV_TouchLinks: triggers overlapping a client get touched by it
static void TouchTriggers( edict_t *cl )
{
	if ( cl->free || !cl->pvPrivateData || cl->v.deadflag != DEAD_NO )
		return;
	Vector cmin = cl->v.origin + cl->v.mins, cmax = cl->v.origin + cl->v.maxs;
	for ( int i = g_globals.maxClients + 1; i < g_numEdicts; i++ )
	{
		edict_t *e = &g_edicts[i];
		if ( e->free || !e->pvPrivateData || e->v.solid != SOLID_TRIGGER )
			continue;
		Vector emin = e->v.origin + e->v.mins, emax = e->v.origin + e->v.maxs;
		if ( emin.x > cmax.x || emin.y > cmax.y || emin.z > cmax.z || emax.x < cmin.x || emax.y < cmin.y || emax.z < cmin.z )
			continue;
		if ( getenv( "SMOKE_TRACE" ) )
			printf( "  t=%.2f %s touches %d %s\n", g_globals.time, Str( cl->v.netname ), i, Str( e->v.classname ) );
		GUARD( "Touch", Str( e->v.classname ), g_dll.pfnTouch( e, cl ) );
		if ( e->v.flags & FL_KILLME )
			RemoveEntity( e );
	}
}

static void Command( edict_t *ent, const char *line )
{
	if ( getenv( "SMOKE_TRACE" ) )
		printf( "  t=%.2f cmd %d: %s\n", g_globals.time, IndexOfEdict( ent ), line );
	if ( getenv( "SMOKE_PROBE" ) && ent->pvPrivateData )
	{
		char *pd = (char *)ent->pvPrivateData;
		printf( "  probe nextattack=%g feigning=%d unable=%d deadflag=%d flags=%x\n", *(float *)( pd + 1652 ),
			*(int *)( pd + 116 ), *(int *)( pd + 120 ), ent->v.deadflag, ent->v.flags );
		for ( edict_t *e = NULL; ( e = FindEntityInSphere( e, ent->v.origin, 64 ) ) != NULL && e != &g_edicts[0]; )
		{
			if ( !e->pvPrivateData )
				continue;
			typedef int ( *CLASSIFY )( void * );
			CLASSIFY fn = ( *(CLASSIFY **)e->pvPrivateData )[10];
			printf( "    near %d %s classify=%d\n", IndexOfEdict( e ), Str( e->v.classname ), fn( e->pvPrivateData ) );
		}
	}
	if ( getenv( "SMOKE_BREAK" ) && !strcmp( line, getenv( "SMOKE_BREAK" ) ) && g_globals.time >= atof( getenv( "SMOKE_BREAK_T" ) ? getenv( "SMOKE_BREAK_T" ) : "0" ) )
		raise( SIGTRAP );
	if ( !strcmp( line, "kill" ) )
	{
		GUARD( "ClientKill", "", g_dll.pfnClientKill( ent ) );
		return;
	}
	g_cmdArgv.clear();
	g_cmdArgs = "";
	std::string s = line;
	size_t p = 0;
	while ( p < s.size() )
	{
		while ( p < s.size() && s[p] == ' ' ) p++;
		size_t e = s.find( ' ', p );
		if ( e == std::string::npos ) e = s.size();
		if ( e > p ) g_cmdArgv.push_back( s.substr( p, e - p ) );
		p = e;
	}
	size_t sp = s.find( ' ' );
	if ( sp != std::string::npos )
		g_cmdArgs = s.substr( sp + 1 );
	GUARD( "ClientCommand", line, g_dll.pfnClientCommand( ent ) );
}

int main( int argc, char **argv )
{
	if ( argc < 2 )
	{
		fprintf( stderr, "usage: smoke tfc.so [-v]\n" );
		return 2;
	}
	g_verbose = argc > 2 && !strcmp( argv[2], "-v" );

	g_strings = (char *)calloc( 1, 16 * 1024 * 1024 );
	g_globals.pStringBase = g_strings;
	g_globals.maxClients = 8;
	g_globals.maxEntities = MAX_EDICTS;
	g_globals.time = 1.0;
	g_globals.frametime = 0.125;	// exact in binary: keeps timer arithmetic free of rounding noise
	g_globals.deathmatch = 1;
	const char *mapPath = getenv( "SMOKE_MAP" );
	std::vector<MapEntity> mapEnts;
	if ( mapPath )
	{
		mapEnts = LoadBsp( mapPath );
		std::string mn = mapPath;
		mn = mn.substr( mn.find_last_of( '/' ) + 1 );
		mn = mn.substr( 0, mn.find( '.' ) );
		g_globals.mapname = AllocString( mn.c_str() );
		printf( "map %s: %d entities, %d brush models\n", mn.c_str(), (int)mapEnts.size(), (int)g_bspModels.size() );
	}
	else
		g_globals.mapname = AllocString( "2fort" );
	g_edicts[0].v.pContainingEntity = &g_edicts[0];
	g_numEdicts = g_globals.maxClients + 1;
	for ( int i = 1; i <= g_globals.maxClients; i++ )
	{
		g_edicts[i].v.pContainingEntity = &g_edicts[i];
		g_edicts[i].free = 1;
	}
	CVarSetString( "deathmatch", "1" );
	CVarSetString( "sv_gravity", "800" );
	CVarSetString( "hostname", "smoke" );
	CVarSetString( "mapcyclefile", "mapcycle.txt" );

	InitEngine();

	struct sigaction sa;
	memset( &sa, 0, sizeof( sa ) );
	sa.sa_handler = OnCrash;
	sa.sa_flags = SA_NODEFER;
	if ( !getenv( "SMOKE_NOCATCH" ) )
		sigaction( SIGSEGV, &sa, NULL );
	sigaction( SIGFPE, &sa, NULL );
	sigaction( SIGBUS, &sa, NULL );
	sigaction( SIGILL, &sa, NULL );
	sigaction( SIGABRT, &sa, NULL );

	g_lib = dlopen( argv[1], RTLD_NOW );
	if ( !g_lib )
	{
		fprintf( stderr, "dlopen: %s\n", dlerror() );
		return 1;
	}

	typedef void ( *GIVEFNPTRS )( enginefuncs_t *, globalvars_t * );
	typedef int ( *GETAPI2 )( DLL_FUNCTIONS *, int * );
	typedef int ( *GETNEWAPI )( NEW_DLL_FUNCTIONS *, int * );
	GIVEFNPTRS give = (GIVEFNPTRS)dlsym( g_lib, "GiveFnptrsToDll" );
	GETAPI2 getapi2 = (GETAPI2)dlsym( g_lib, "GetEntityAPI2" );
	GETNEWAPI getnew = (GETNEWAPI)dlsym( g_lib, "GetNewDLLFunctions" );
	if ( !give || !getapi2 )
	{
		fprintf( stderr, "missing GiveFnptrsToDll/GetEntityAPI2\n" );
		return 1;
	}
	give( &g_eng, &g_globals );
	int ver = INTERFACE_VERSION;
	if ( !getapi2( &g_dll, &ver ) )
	{
		fprintf( stderr, "GetEntityAPI2 refused version %d\n", ver );
		return 1;
	}
	int nver = NEW_DLL_FUNCTIONS_VERSION;
	if ( getnew )
		getnew( &g_newdll, &nver );
	printf( "API ok: %d cvars before GameInit\n", (int)g_cvars.size() );

	GUARD( "GameInit", "", g_dll.pfnGameInit() );
	printf( "GameInit: %d cvars registered\n", (int)g_cvars.size() );

	// world
	edict_t *world = &g_edicts[0];
	world->free = 0;
	world->v.classname = AllocString( "worldspawn" );
	GUARD( "worldspawn", "worldspawn", {
		( (LINK_ENTITY_FUNC)dlsym( g_lib, "worldspawn" ) )( &world->v );
		if ( mapPath && !mapEnts.empty() )
		{
			for ( size_t k = 0; k < mapEnts[0].size(); k++ )
				MapKeyValue( world, "worldspawn", mapEnts[0][k].first, mapEnts[0][k].second );
			SetModel( world, "*0" );
		}
		else
		{
			KeyValue( world, "worldspawn", "wad", "tfc.wad" );
			KeyValue( world, "worldspawn", "skyname", "tornsky" );
		}
		g_dll.pfnSpawn( world );
	} );

	// SMOKE_MAP: the map's own entities, in file order, like ED_LoadFromFile
	int spawned = 0;
	for ( size_t m = 1; mapPath && m < mapEnts.size(); m++ )
	{
		std::string cls = EntValue( mapEnts[m], "classname" );
		const char *n = cls.c_str();
		edict_t *e = NULL;
		GUARD( "create", n, e = CreateNamedEntity( AllocString( n ) ) );
		if ( !e || !e->pvPrivateData )
		{
			printf( "no entity class %s\n", n );
			if ( e ) RemoveEntity( e );
			continue;
		}
		GUARD( "keyvalue", n, {
			for ( size_t k = 0; k < mapEnts[m].size(); k++ )
				MapKeyValue( e, n, mapEnts[m][k].first, mapEnts[m][k].second );
		} );
		int rc = 0;
		GUARD( "spawn", n, {
			rc = g_dll.pfnSpawn( e );
			if ( rc < 0 )
				RemoveEntity( e );
			else
				spawned++;
		} );
		if ( getenv( "SMOKE_TRACE" ) )
			printf( "spawn %d %-24s rc=%d solid=%d movetype=%d flags=%x health=%g model=%s takedamage=%g effects=%x render=%d/%g"
				" size=%g,%g,%g origin=%g,%g,%g nextthink=%d free=%d\n", IndexOfEdict( e ), n, rc, e->v.solid, e->v.movetype, e->v.flags,
				e->v.health, Str( e->v.model ), e->v.takedamage, e->v.effects, e->v.rendermode, e->v.renderamt,
				e->v.size.x, e->v.size.y, e->v.size.z, e->v.origin.x, e->v.origin.y, e->v.origin.z, e->v.nextthink > 0,
				e->free || ( e->v.flags & FL_KILLME ) ? 1 : 0 );
	}

	// every exported entity
	FILE *nm = mapPath ? NULL : popen( ( std::string( "nm -D --defined-only " ) + argv[1] + " | awk '$2==\"T\" && $3 !~ /^_/ {print $3}'" ).c_str(), "r" );
	std::vector<std::string> names;
	char line[256];
	while ( nm && fgets( line, sizeof( line ), nm ) )
	{
		line[strcspn( line, "\n" )] = 0;
		std::string n = line;
		static const char *api[] = { "GiveFnptrsToDll", "GetEntityAPI", "GetEntityAPI2", "GetNewDLLFunctions",
			"Server_GetBlendingInterface", "CreateInterface", "worldspawn", "info_tfdetect",
			"info_player_teamspawn", "i_p_t", NULL };
		bool skip = false;
		for ( int i = 0; api[i]; i++ )
			if ( n == api[i] ) skip = true;
		if ( n.empty() || isupper( (unsigned char)n[0] ) )
			skip = true;
		if ( !skip )
			names.push_back( n );
	}
	if ( nm )
		pclose( nm );

	// a minimal 2-team map: detect entity and one spawn point per team
	struct MapEnt { const char *cls; const char *kv[32]; };
	static const MapEnt mapents[] = {
		{ "info_tfdetect", { "origin", "0 0 0", "number_of_teams", "2", "team1_name", "blue", "team2_name", "red", NULL } },
		// blue spawns away from where the blues stand, so respawns don't telefrag
		{ "info_player_teamspawn", { "origin", "-600 400 36", "team_no", "1", NULL } },
		{ "info_player_teamspawn", { "origin", "300 0 36", "team_no", "2", NULL } },
		{ "info_player_teamspawn", { "origin", "-600 -400 36", "team_no", "1", NULL } },
		// red flag at the blue player's spot: blue picks it up, drops it on
		// death, and captures it at the goal next to him (returns the flag)
		{ "item_tfgoal", { "origin", "-300 0 36", "goal_no", "1", "team_no", "1", "owned_by", "2",
			"goal_activation", "4613", "goal_effects", "1", "mdl", "models/flag.mdl", "netname", "red_flag", NULL } },
		{ "info_tfgoal", { "origin", "-300 200 36", "goal_no", "2", "team_no", "1", "items_allowed", "1",
			"goal_activation", "1", "goal_effects", "1", "goal_min", "-16 -16 -24", "goal_max", "16 16 32",
			"count", "10", "frags", "10", "return_item_no", "1", "wait", "1", "netname", "red_cap", NULL } },
		// a resupply goal under the blue player: cells for engineer buildings
		{ "info_tfgoal", { "origin", "-300 0 36", "goal_no", "3", "goal_activation", "1", "goal_effects", "1",
			"goal_min", "-16 -16 -24", "goal_max", "16 16 32", "ammo_cells", "200", "wait", "5", "netname", "resupply", NULL } },
		// a health kit where the red player stands
		{ "item_healthkit", { "origin", "300 0 0", NULL } },
	};
	for ( size_t m = 0; !mapPath && m < sizeof( mapents ) / sizeof( mapents[0] ); m++ )
	{
		const char *n = mapents[m].cls;
		edict_t *e = NULL;
		GUARD( "create", n, e = CreateNamedEntity( AllocString( n ) ) );
		if ( !e || !e->pvPrivateData )
			continue;
		GUARD( "keyvalue", n, {
			for ( int k = 0; mapents[m].kv[k]; k += 2 )
				KeyValue( e, n, mapents[m].kv[k], mapents[m].kv[k + 1] );
		} );
		GUARD( "spawn", n, g_dll.pfnSpawn( e ) );
	}

	for ( size_t i = 0; i < names.size(); i++ )
	{
		const char *n = names[i].c_str();
		edict_t *e = NULL;
		GUARD( "create", n, e = CreateNamedEntity( AllocString( n ) ) );
		if ( !e || !e->pvPrivateData )
			continue;
		GUARD( "keyvalue", n, {
			KeyValue( e, n, "origin", "0 2000 64" );	// away from the players' firing line
			KeyValue( e, n, "angles", "0 90 0" );
			KeyValue( e, n, "targetname", "smoketarget" );
			KeyValue( e, n, "team_no", "1" );
			KeyValue( e, n, "goal_no", "1" );
		} );
		int rc = 0;
		GUARD( "spawn", n, {
			rc = g_dll.pfnSpawn( e );
			if ( rc < 0 )
				RemoveEntity( e );
			else
				spawned++;
		} );
		if ( getenv( "SMOKE_TRACE" ) )
			printf( "spawn %-32s rc=%d solid=%d movetype=%d flags=%x health=%g model=%s takedamage=%g effects=%x"
				" render=%d/%g/%d skin=%d body=%d seq=%d frame=%g size=%g,%g,%g nextthink=%d dmg=%g speed=%g gravity=%g\n",
				n, rc, e->v.solid, e->v.movetype, e->v.flags, e->v.health, Str( e->v.model ), e->v.takedamage,
				e->v.effects, e->v.rendermode, e->v.renderamt, e->v.renderfx, e->v.skin, e->v.body, e->v.sequence,
				e->v.frame, e->v.size.x, e->v.size.y, e->v.size.z, e->v.nextthink > 0, e->v.dmg, e->v.speed, e->v.gravity );
	}
	printf( "spawned %d of %d entity classes, %d edicts in use\n", spawned, (int)names.size(), g_numEdicts );

	GUARD( "ServerActivate", "", g_dll.pfnServerActivate( g_edicts, g_numEdicts, g_globals.maxClients ) );

	// two clients join opposite teams, cycle through every class and shoot each other
	// smoker (blue) and target (red) fight; buddy (blue) is smoker's teammate
	const int NCL = 3;
	edict_t *cls[NCL] = { &g_edicts[1], &g_edicts[2], &g_edicts[3] };
	const char *names2[NCL] = { "smoker", "target", "buddy" };
	for ( int c = 0; c < NCL; c++ )
	{
		edict_t *cl = cls[c];
		memset( cl, 0, sizeof( *cl ) );
		cl->v.pContainingEntity = cl;
		cl->free = 0;
		snprintf( g_infoBuffers[c + 1], sizeof( g_infoBuffers[0] ), "\\name\\%s\\model\\scout\\topcolor\\0\\bottomcolor\\0", names2[c] );
		cl->v.netname = AllocString( names2[c] );
		char reject[128] = "";
		int ok = 0;
		char address[32];
		strcpy( address, "127.0.0.1:27005" );	// the game writes into it
		GUARD( "ClientConnect", names2[c], ok = g_dll.pfnClientConnect( cl, names2[c], address, reject ) );
		printf( "ClientConnect %s: %s %s\n", names2[c], ok ? "accepted" : "rejected", reject );
		GUARD( "ClientPutInServer", names2[c], g_dll.pfnClientPutInServer( cl ) );
		GUARD( "ClientUserInfoChanged", names2[c], g_dll.pfnClientUserInfoChanged( cl, g_infoBuffers[c + 1] ) );
	}

	static const char *classcmd[] = { "scout", "sniper", "soldier", "demoman", "medic", "hwguy", "pyro", "spy", "engineer" };
	// class abilities, at fixed phases of each round (cmd sent to the first player)
	struct Timed { int phase; const char *cmd; };
	static const Timed extra[] = {
		{ 138, "tf_weapon_axe" }, { 138, "tf_weapon_medikit" }, { 138, "tf_weapon_spanner" }, { 138, "tf_weapon_knife" },
		{ 159, "lastinv" }, { 160, "+det5" }, { 166, "tf_weapon_axe" }, { 166, "tf_weapon_medikit" }, { 166, "tf_weapon_spanner" },
		{ 166, "tf_weapon_knife" }, { 196, "lastinv" },
		{ 280, "say hello" }, { 281, "slot1" }, { 282, "slot2" }, { 283, "slot3" }, { 284, "slot4" },
		{ 285, "reload" }, { 286, "+gren2" }, { 294, "-gren2" }, { 296, "+gren1" }, { 300, "-gren1" },
		{ 302, "disguise 5 2" }, { 303, "feign" }, { 306, "feign" }, { 307, "build 2" }, { 320, "build 1" },
		{ 340, "saveme" }, { 341, "dropitems" }, { 342, "discard" }, { 343, "_special" }, { 344, "detpipe" },
		{ 0, NULL } };
	Command( cls[0], "jointeam 1" );
	Command( cls[1], "jointeam 2" );
	Command( cls[2], "jointeam 1" );

	const int ROUND = 400;	// kill at 2, respawn by ~130, abilities 160+, fight 200-260
	int frames = 9 * ROUND;
	for ( int frame = 0; frame < frames; frame++ )
	{
		g_globals.time += g_globals.frametime;
		int phase = frame % ROUND;
		if ( phase == 0 )
		{
			const char *cmd = classcmd[frame / ROUND];
			Command( cls[0], cmd );
			Command( cls[1], classcmd[8 - frame / ROUND] );
			Command( cls[2], classcmd[( frame / ROUND + 4 ) % 9] );
		}
		if ( phase == 2 && frame >= ROUND )
		{
			// class changes apply on respawn
			Command( cls[0], "kill" );
			Command( cls[1], "kill" );
			Command( cls[2], "kill" );
		}
		for ( int x = 0; extra[x].cmd; x++ )
			if ( extra[x].phase == phase )
				Command( cls[0], extra[x].cmd );
		if ( phase == 166 )
		{
			Command( cls[1], "tf_weapon_axe" );
			Command( cls[1], "tf_weapon_medikit" );
			Command( cls[1], "tf_weapon_spanner" );
			Command( cls[1], "tf_weapon_knife" );
		}
		if ( phase == 196 )
			Command( cls[1], "lastinv" );

		// stand apart, face each other; hold attack half the time
		for ( int c = 0; c < NCL; c++ )
		{
			edict_t *cl = cls[c];
			if ( cl->v.deadflag == DEAD_NO && cl->v.health > 0 )
			{
				// the blue player walks to the capture point late in each round
				bool cap = !c && phase >= 322 && phase < 338;
				// melee range for a while so crowbars, medikits, spanners and knives connect
				bool melee = phase >= 168 && phase < 196;
				// the buddy waits off to the side, and steps in front of smoker
				// while he swings his melee weapon at it (heals, repairs, ally hits)
				bool ally = phase >= 138 && phase < 160;
				if ( !mapPath && c == 2 )
				{
					cl->v.origin = ally ? Vector( -260, 0, 36 ) : Vector( -300, -200, 36 );
					cl->v.v_angle = cl->v.angles = Vector( 0, 0, 0 );
				}
				else if ( !mapPath )
				{
					cl->v.origin = Vector( melee ? ( c ? 20 : -20 ) : ( c ? 300 : -300 ), cap ? 200 : 0, 36 );
					cl->v.v_angle = cl->v.angles = Vector( 0, c ? 180 : 0, 0 );
				}
				SetOrigin( cl, cl->v.origin );	// on a real map, stay at the spawn point
				cl->v.flags |= FL_ONGROUND;
				cl->v.velocity = Vector( 0, 0, 0 );	// standing still (no player movement code here)
				bool fight = ( phase > 200 && phase < 260 ) || ( phase > 170 && phase < 194 );
				bool swing = c == 0 && phase > 141 && phase < 158;
				cl->v.button = ( c != 2 && ( fight || swing ) && ( frame & 4 ) ) ? IN_ATTACK : 0;
			}
			else
			{
				// dead bodies land; keep tapping fire to respawn
				cl->v.flags |= FL_ONGROUND;
				cl->v.velocity = Vector( 0, 0, 0 );
				cl->v.button = ( frame & 1 ) ? IN_ATTACK : 0;
			}
		}

		GUARD( "StartFrame", "", g_dll.pfnStartFrame() );
		for ( int c = 0; c < NCL; c++ )
		{
			GUARD( "PlayerPreThink", names2[c], g_dll.pfnPlayerPreThink( cls[c] ) );
		}
		RunThinks();
		RunPhysics();
		for ( int c = 0; c < NCL; c++ )
			TouchTriggers( cls[c] );
		if ( getenv( "SMOKE_TRACE" ) )
		{
			// entities created this frame
			static string_t lastcls[MAX_EDICTS];
			for ( int i = 1; i < g_numEdicts; i++ )
			{
				string_t c = ( g_edicts[i].free || !g_edicts[i].pvPrivateData ) ? 0 : g_edicts[i].v.classname;
				if ( c && c != lastcls[i] )
					printf( "  f%d new %s owner=%d\n", frame, Str( c ), IndexOfEdict( g_edicts[i].v.owner ) );
				lastcls[i] = c;
			}
			static string_t lastw[NCL];
			for ( int c = 0; c < NCL; c++ )
				if ( cls[c]->v.weaponmodel != lastw[c] )
				{
					printf( "  f%d %s weaponmodel -> %s\n", frame, names2[c], Str( cls[c]->v.weaponmodel ) );
					lastw[c] = cls[c]->v.weaponmodel;
				}
		}
		for ( int c = 0; c < NCL; c++ )
		{
			GUARD( "PlayerPostThink", names2[c], g_dll.pfnPlayerPostThink( cls[c] ) );
		}

		if ( getenv( "SMOKE_TRACE" ) && frame % 10 == 0 )
		{
			int live = 0;
			for ( int i = 1; i < g_numEdicts; i++ )
				if ( !g_edicts[i].free && g_edicts[i].pvPrivateData )
					live++;
			for ( int c = 0; c < NCL; c++ )
			{
				edict_t *cl = cls[c];
				printf( "f%03d %s class=%d team=%d hp=%g ap=%g at=%g wpn=%x frags=%g dead=%d speed=%g vel=%.0f,%.0f,%.0f "
					"eff=%x model=%s wmodel=%s live=%d\n", frame, names2[c], cl->v.playerclass, cl->v.team, cl->v.health,
					cl->v.armorvalue, cl->v.armortype, cl->v.weapons, cl->v.frags, cl->v.deadflag, cl->v.maxspeed,
					cl->v.velocity.x, cl->v.velocity.y, cl->v.velocity.z, cl->v.effects, Str( cl->v.model ),
					Str( cl->v.weaponmodel ), live );
			}
		}
	}

	edict_t *cl = cls[0];
	printf( "ran %d frames: %s class %d team %d health %.0f frags %.0f; %s health %.0f frags %.0f\n", frames, names2[0],
		cl->v.playerclass, cl->v.team, cl->v.health, cl->v.frags, names2[1], cls[1]->v.health, cls[1]->v.frags );

	if ( getenv( "SMOKE_TRACE" ) )
	{
		std::vector<std::string> live;
		for ( int i = 1; i < g_numEdicts; i++ )
			if ( !g_edicts[i].free && g_edicts[i].pvPrivateData )
				live.push_back( Str( g_edicts[i].v.classname ) );
		std::sort( live.begin(), live.end() );
		for ( size_t i = 0; i < live.size(); i++ )
			printf( "live %s\n", live[i].c_str() );
	}

	for ( int c = 0; c < NCL; c++ )
		GUARD( "ClientDisconnect", names2[c], g_dll.pfnClientDisconnect( cls[c] ) );
	GUARD( "ServerDeactivate", "", g_dll.pfnServerDeactivate() );

	printf( "%s: %d crash(es)\n", g_crashes ? "FAIL" : "PASS", g_crashes );
	return g_crashes ? 1 : 0;
}
