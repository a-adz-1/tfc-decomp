// Movement reference harness: runs TFC's own player movement (PM_Move from a
// tfc.so) through a scripted scenario in a simple brush world, and prints
// the player state after every command. Fortress United's C# movement port
// must reproduce these traces (its tests/MovementTests reads the same
// scenario files and compares against the output).
//
// usage: movetest <tfc.so> <scenario.txt> > trace.txt
//
// The world code here (brush sweeps, contents, ladders, RNG) must stay
// identical to Fortress United's tests/MovementTests/TestWorld.cs; it is
// built with SSE floats (build.sh) so its arithmetic matches C# bit for bit.
// Only the movement code inside tfc.so runs on the x87 FPU.

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

#include "extdll.h"
#include "pm_defs.h"
#include "pm_movevars.h"

// ---------------------------------------------------------------------------
// World: convex brushes (solid / water) and ladder boxes

enum { C_SOLID, C_WATER, C_LADDER };

struct Plane { float n[3]; float d; };
struct Brush { int contents; std::vector<Plane> planes; float mins[3], maxs[3]; };

static std::vector<Brush> g_brushes;
static std::vector<Brush> g_ladders;

static const float DIST_EPSILON = 0.03125f;

static Brush BoxBrush( int contents, const float *mins, const float *maxs )
{
	Brush b;
	b.contents = contents;
	for ( int i = 0; i < 3; i++ ) { b.mins[i] = mins[i]; b.maxs[i] = maxs[i]; }
	for ( int i = 0; i < 3; i++ )
	{
		Plane p = { { 0, 0, 0 }, 0 };
		p.n[i] = 1; p.d = maxs[i];
		b.planes.push_back( p );
		Plane q = { { 0, 0, 0 }, 0 };
		q.n[i] = -1; q.d = -mins[i];
		b.planes.push_back( q );
	}
	return b;
}

struct Trace
{
	int allsolid, startsolid;
	float fraction;
	float endpos[3];
	float normal[3];
	float dist;
	int ent;
};

// Sweep a box (mins/maxs relative to the moving point) through one brush.
static void TraceBrush( const Brush &b, const float *start, const float *end, const float *mins, const float *maxs, Trace &tr )
{
	float enterFrac = -1, leaveFrac = 1;
	int startout = 0, getout = 0;
	const Plane *clip = NULL;
	float clipDist = 0;

	for ( size_t i = 0; i < b.planes.size(); i++ )
	{
		const Plane &p = b.planes[i];
		// push the plane out by the box's support point
		float ofs0 = p.n[0] < 0 ? maxs[0] : mins[0];
		float ofs1 = p.n[1] < 0 ? maxs[1] : mins[1];
		float ofs2 = p.n[2] < 0 ? maxs[2] : mins[2];
		float dist = p.d - ( ofs0 * p.n[0] + ofs1 * p.n[1] + ofs2 * p.n[2] );
		float d1 = start[0] * p.n[0] + start[1] * p.n[1] + start[2] * p.n[2] - dist;
		float d2 = end[0] * p.n[0] + end[1] * p.n[1] + end[2] * p.n[2] - dist;

		if ( d2 > 0 ) getout = 1;
		if ( d1 > 0 ) startout = 1;

		// completely in front of this plane: no hit
		if ( d1 > 0 && ( d2 >= DIST_EPSILON || d2 >= d1 ) )
			return;
		// completely behind: keep going
		if ( d1 <= 0 && d2 <= 0 )
			continue;

		if ( d1 > d2 )
		{
			float f = ( d1 - DIST_EPSILON ) / ( d1 - d2 );
			if ( f < 0 ) f = 0;
			if ( f > enterFrac ) { enterFrac = f; clip = &p; clipDist = dist; }
		}
		else
		{
			float f = ( d1 + DIST_EPSILON ) / ( d1 - d2 );
			if ( f > 1 ) f = 1;
			if ( f < leaveFrac ) leaveFrac = f;
		}
	}

	if ( !startout )
	{
		tr.startsolid = 1;
		tr.ent = 0;
		if ( !getout )
		{
			tr.allsolid = 1;
			tr.fraction = 0;
		}
		return;
	}

	if ( enterFrac < leaveFrac && enterFrac > -1 && enterFrac < tr.fraction )
	{
		if ( enterFrac < 0 ) enterFrac = 0;
		tr.fraction = enterFrac;
		tr.normal[0] = clip->n[0]; tr.normal[1] = clip->n[1]; tr.normal[2] = clip->n[2];
		tr.dist = clipDist;
		tr.ent = 0;
	}
}

static Trace TraceWorld( const float *start, const float *end, const float *mins, const float *maxs, int contents )
{
	Trace tr;
	memset( &tr, 0, sizeof( tr ) );
	tr.fraction = 1;
	tr.ent = -1;
	for ( size_t i = 0; i < g_brushes.size(); i++ )
		if ( g_brushes[i].contents == contents )
			TraceBrush( g_brushes[i], start, end, mins, maxs, tr );
	for ( int i = 0; i < 3; i++ )
		tr.endpos[i] = start[i] + tr.fraction * ( end[i] - start[i] );
	return tr;
}

static int InsideBrush( const Brush &b, const float *p )
{
	for ( size_t i = 0; i < b.planes.size(); i++ )
	{
		const Plane &pl = b.planes[i];
		if ( p[0] * pl.n[0] + p[1] * pl.n[1] + p[2] * pl.n[2] - pl.d > 0 )
			return 0;
	}
	return 1;
}

// ---------------------------------------------------------------------------
// Engine callbacks for pmove

static playermove_t g_pm;
static movevars_t g_mv;
static unsigned int g_seed = 12345;
static double g_time = 0;

static int RandomLong( int lo, int hi )
{
	g_seed = g_seed * 1103515245u + 12345u;
	unsigned int range = (unsigned int)( hi - lo + 1 );
	return lo + (int)( ( g_seed >> 16 ) % range );
}

static float RandomFloat( float lo, float hi )
{
	g_seed = g_seed * 1103515245u + 12345u;
	return lo + ( hi - lo ) * ( ( g_seed >> 16 ) & 0x7fff ) / 32767.0f;
}

static pmtrace_t ToPm( const Trace &t )
{
	pmtrace_t r;
	memset( &r, 0, sizeof( r ) );
	r.allsolid = t.allsolid;
	r.startsolid = t.startsolid;
	r.inopen = t.fraction == 1 && !t.startsolid;
	r.fraction = t.fraction;
	for ( int i = 0; i < 3; i++ ) { r.endpos[i] = t.endpos[i]; r.plane.normal[i] = t.normal[i]; }
	r.plane.dist = t.dist;
	r.ent = t.ent;
	return r;
}

static pmtrace_t PM_PlayerTrace( float *start, float *end, int traceFlags, int ignore_pe )
{
	Trace t = TraceWorld( start, end, g_pm.player_mins[g_pm.usehull], g_pm.player_maxs[g_pm.usehull], C_SOLID );
	return ToPm( t );
}

static int PointContents( const float *p )
{
	for ( size_t i = 0; i < g_brushes.size(); i++ )
		if ( g_brushes[i].contents == C_SOLID && InsideBrush( g_brushes[i], p ) )
			return CONTENTS_SOLID;
	for ( size_t i = 0; i < g_brushes.size(); i++ )
		if ( g_brushes[i].contents == C_WATER && InsideBrush( g_brushes[i], p ) )
			return CONTENTS_WATER;
	return CONTENTS_EMPTY;
}

static int PM_PointContents( float *p, int *truecontents )
{
	int c = PointContents( p );
	if ( truecontents )
		*truecontents = c;
	return c;
}

static int PM_TestPlayerPosition( float *pos, pmtrace_t *ptrace )
{
	Trace t = TraceWorld( pos, pos, g_pm.player_mins[g_pm.usehull], g_pm.player_maxs[g_pm.usehull], C_SOLID );
	if ( ptrace )
		*ptrace = ToPm( t );
	return t.startsolid ? 0 : -1;
}

static const char *PM_Info_ValueForKey( const char *s, const char *key )
{
	static char value[4][256];
	static int which = 0;
	char pkey[256];
	char *o;
	which = ( which + 1 ) & 3;
	if ( *s == '\\' ) s++;
	while ( 1 )
	{
		o = pkey;
		while ( *s != '\\' ) { if ( !*s ) return ""; *o++ = *s++; }
		*o = 0; s++;
		o = value[which];
		while ( *s != '\\' && *s ) *o++ = *s++;
		*o = 0;
		if ( !strcmp( key, pkey ) ) return value[which];
		if ( !*s ) return "";
		s++;
	}
}

// Ladders: moveents with a fake model; the hull pointer carries the ladder index
struct FakeHull { void *clipnodes; void *planes; int firstclipnode; int lastclipnode; vec3_t clip_mins, clip_maxs; };
static FakeHull g_ladderHull[MAX_MOVEENTS];
static int g_fakeModel[MAX_MOVEENTS];

static int PM_GetModelType( struct model_s *mod ) { return 0; } // mod_brush

static void PM_GetModelBounds( struct model_s *mod, float *mins, float *maxs )
{
	int i = (int)( (int *)mod - g_fakeModel );
	for ( int k = 0; k < 3; k++ ) { mins[k] = g_ladders[i].mins[k]; maxs[k] = g_ladders[i].maxs[k]; }
}

static void *PM_HullForBsp( physent_t *pe, float *offset )
{
	int i = (int)( pe - g_pm.moveents );
	offset[0] = offset[1] = offset[2] = 0;
	g_ladderHull[i].firstclipnode = i;
	return &g_ladderHull[i];
}

// Is the player's current hull touching ladder i at point p?
static int LadderOverlap( int i, const float *p )
{
	const float *hmin = g_pm.player_mins[g_pm.usehull], *hmax = g_pm.player_maxs[g_pm.usehull];
	for ( int k = 0; k < 3; k++ )
	{
		if ( !( p[k] > g_ladders[i].mins[k] - hmax[k] && p[k] < g_ladders[i].maxs[k] - hmin[k] ) )
			return 0;
	}
	return 1;
}

static int PM_HullPointContents( struct hull_s *hull, int num, float *p )
{
	return LadderOverlap( num, p ) ? CONTENTS_SOLID : CONTENTS_EMPTY;
}

static float PM_TraceModel( physent_t *pe, float *start, float *end, trace_t *trace )
{
	int i = (int)( (int *)pe->model - g_fakeModel );
	static const float zero[3] = { 0, 0, 0 };
	Trace t;
	memset( &t, 0, sizeof( t ) );
	t.fraction = 1; t.ent = -1;
	TraceBrush( g_ladders[i], start, end, zero, zero, t );
	for ( int k = 0; k < 3; k++ ) t.endpos[k] = start[k] + t.fraction * ( end[k] - start[k] );
	memset( trace, 0, sizeof( *trace ) );
	trace->allsolid = t.allsolid; trace->startsolid = t.startsolid;
	trace->fraction = t.fraction;
	for ( int k = 0; k < 3; k++ ) { trace->endpos[k] = t.endpos[k]; trace->plane.normal[k] = t.normal[k]; }
	trace->plane.dist = t.dist;
	return t.fraction;
}

static void PM_PlaySound( int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch ) {}
static const char *PM_TraceTexture( int ground, float *vstart, float *vend ) { return ""; }
static void PM_StuckTouch( int hitent, pmtrace_t *ptraceresult ) {}
static double Sys_FloatTime( void ) { return g_time; }
static void Con_NPrintf( int idx, char *fmt, ... ) {}
static void Con_DPrintf( char *fmt, ... ) {}
static void Con_Printf( char *fmt, ... ) {}
static byte *COM_LoadFile( char *path, int usehunk, int *pLength ) { if ( pLength ) *pLength = 0; return NULL; }
static char *memfgets( byte *pMemFile, int fileSize, int *pFilePos, char *pBuffer, int bufferSize ) { return NULL; }
static void COM_FreeFile( void *buffer ) {}
static int COM_FileSize( char *filename ) { return 0; }

// ---------------------------------------------------------------------------
// Scenario

struct Cmd { int count, msec; float angles[3]; float dangles[3]; float fwd, side, up; int buttons; };

static void Fail( const char *msg, const char *line )
{
	fprintf( stderr, "%s: %s\n", msg, line );
	exit( 1 );
}

int main( int argc, char **argv )
{
	if ( argc != 3 )
	{
		fprintf( stderr, "usage: movetest <tfc.so> <scenario.txt>\n" );
		return 1;
	}

	void *lib = dlopen( argv[1], RTLD_NOW );
	if ( !lib ) { fprintf( stderr, "dlopen: %s\n", dlerror() ); return 1; }
	typedef int ( *GETAPI2 )( DLL_FUNCTIONS *, int * );
	GETAPI2 getapi2 = (GETAPI2)dlsym( lib, "GetEntityAPI2" );
	DLL_FUNCTIONS dll;
	memset( &dll, 0, sizeof( dll ) );
	int version = INTERFACE_VERSION;
	if ( !getapi2 )
	{	// a client.so: its HUD_PlayerMove/HUD_PlayerMoveInit exports call PM_Move/PM_Init
		dll.pfnPM_Move = (void (*)( struct playermove_s *, qboolean ))dlsym( lib, "HUD_PlayerMove" );
		dll.pfnPM_Init = (void (*)( struct playermove_s * ))dlsym( lib, "HUD_PlayerMoveInit" );
	}
	else if ( !getapi2( &dll, &version ) )
		dll.pfnPM_Move = NULL;
	if ( !dll.pfnPM_Move || !dll.pfnPM_Init )
	{
		fprintf( stderr, "no PM_Move in %s\n", argv[1] );
		return 1;
	}

	// Defaults (TFC server values)
	memset( &g_mv, 0, sizeof( g_mv ) );
	g_mv.gravity = 800; g_mv.stopspeed = 100; g_mv.maxspeed = 500; g_mv.accelerate = 10;
	g_mv.airaccelerate = 10; g_mv.wateraccelerate = 10; g_mv.friction = 4; g_mv.edgefriction = 2;
	g_mv.waterfriction = 1; g_mv.entgravity = 1; g_mv.bounce = 1; g_mv.stepsize = 18;
	g_mv.maxvelocity = 2000; g_mv.rollangle = 0; g_mv.rollspeed = 200;

	memset( &g_pm, 0, sizeof( g_pm ) );
	g_pm.player_index = 0;
	g_pm.server = 1;
	g_pm.multiplayer = 1;
	g_pm.movevars = &g_mv;
	g_pm.movetype = MOVETYPE_WALK;
	g_pm.onground = -1;
	g_pm.gravity = 1;
	g_pm.friction = 1;
	g_pm.view_ofs[2] = 28;
	g_pm.maxspeed = 400;
	g_pm.clientmaxspeed = 400;
	float hmins[4][3] = { { -16, -16, -36 }, { -16, -16, -18 }, { 0, 0, 0 }, { -32, -32, -32 } };
	float hmaxs[4][3] = { { 16, 16, 36 }, { 16, 16, 18 }, { 0, 0, 0 }, { 32, 32, 32 } };
	memcpy( g_pm.player_mins, hmins, sizeof( hmins ) );
	memcpy( g_pm.player_maxs, hmaxs, sizeof( hmaxs ) );
	g_pm.numphysent = 1;
	strcpy( g_pm.physents[0].name, "world" );
	g_pm.physents[0].model = (struct model_s *)&g_fakeModel[0];
	strcpy( g_pm.physinfo, "" );

	g_pm.PM_Info_ValueForKey = PM_Info_ValueForKey;
	g_pm.PM_TestPlayerPosition = PM_TestPlayerPosition;
	g_pm.Con_NPrintf = Con_NPrintf;
	g_pm.Con_DPrintf = Con_DPrintf;
	g_pm.Con_Printf = Con_Printf;
	g_pm.Sys_FloatTime = Sys_FloatTime;
	g_pm.PM_StuckTouch = PM_StuckTouch;
	g_pm.PM_PointContents = PM_PointContents;
	g_pm.PM_TruePointContents = NULL;
	g_pm.PM_HullPointContents = PM_HullPointContents;
	g_pm.PM_PlayerTrace = PM_PlayerTrace;
	g_pm.PM_TraceTexture = PM_TraceTexture;
	g_pm.RandomLong = RandomLong;
	g_pm.RandomFloat = RandomFloat;
	g_pm.PM_GetModelType = PM_GetModelType;
	g_pm.PM_GetModelBounds = PM_GetModelBounds;
	g_pm.PM_HullForBsp = PM_HullForBsp;
	g_pm.PM_TraceModel = PM_TraceModel;
	g_pm.COM_FileSize = COM_FileSize;
	g_pm.COM_LoadFile = COM_LoadFile;
	g_pm.COM_FreeFile = COM_FreeFile;
	g_pm.memfgets = memfgets;
	g_pm.PM_PlaySound = PM_PlaySound;
	g_pm.runfuncs = 1;

	std::vector<Cmd> cmds;
	FILE *f = fopen( argv[2], "r" );
	if ( !f ) { perror( argv[2] ); return 1; }
	char line[1024];
	while ( fgets( line, sizeof( line ), f ) )
	{
		char *hash = strchr( line, '#' );
		if ( hash ) *hash = 0;
		char word[64];
		if ( sscanf( line, "%63s", word ) != 1 )
			continue;
		const char *rest = line + strspn( line, " \t" ) + strlen( word );

		if ( !strcmp( word, "box" ) || !strcmp( word, "water" ) || !strcmp( word, "ladder" ) )
		{
			float mn[3], mx[3];
			if ( sscanf( rest, "%f %f %f %f %f %f", &mn[0], &mn[1], &mn[2], &mx[0], &mx[1], &mx[2] ) != 6 )
				Fail( "bad box", line );
			if ( !strcmp( word, "ladder" ) )
				g_ladders.push_back( BoxBrush( C_LADDER, mn, mx ) );
			else
				g_brushes.push_back( BoxBrush( !strcmp( word, "box" ) ? C_SOLID : C_WATER, mn, mx ) );
		}
		else if ( !strcmp( word, "brush" ) )
		{
			// brush nx ny nz d nx ny nz d ... (solid convex brush from planes)
			Brush b;
			b.contents = C_SOLID;
			const char *p = rest;
			Plane pl;
			int used;
			while ( sscanf( p, "%f %f %f %f%n", &pl.n[0], &pl.n[1], &pl.n[2], &pl.d, &used ) == 4 )
			{
				b.planes.push_back( pl );
				p += used;
			}
			if ( b.planes.size() < 4 ) Fail( "bad brush", line );
			g_brushes.push_back( b );
		}
		else if ( !strcmp( word, "origin" ) )
			sscanf( rest, "%f %f %f", &g_pm.origin[0], &g_pm.origin[1], &g_pm.origin[2] );
		else if ( !strcmp( word, "velocity" ) )
			sscanf( rest, "%f %f %f", &g_pm.velocity[0], &g_pm.velocity[1], &g_pm.velocity[2] );
		else if ( !strcmp( word, "maxspeed" ) )
		{
			sscanf( rest, "%f", &g_pm.maxspeed );
			g_pm.clientmaxspeed = g_pm.maxspeed;
		}
		else if ( !strcmp( word, "physinfo" ) )
		{
			char k[64], v[64];
			if ( sscanf( rest, "%63s %63s", k, v ) != 2 ) Fail( "bad physinfo", line );
			strcat( g_pm.physinfo, "\\" ); strcat( g_pm.physinfo, k );
			strcat( g_pm.physinfo, "\\" ); strcat( g_pm.physinfo, v );
		}
		else if ( !strcmp( word, "movevar" ) )
		{
			char k[64]; float v;
			if ( sscanf( rest, "%63s %f", k, &v ) != 2 ) Fail( "bad movevar", line );
			if ( !strcmp( k, "gravity" ) ) g_mv.gravity = v;
			else if ( !strcmp( k, "airaccelerate" ) ) g_mv.airaccelerate = v;
			else if ( !strcmp( k, "accelerate" ) ) g_mv.accelerate = v;
			else if ( !strcmp( k, "friction" ) ) g_mv.friction = v;
			else if ( !strcmp( k, "maxvelocity" ) ) g_mv.maxvelocity = v;
			else if ( !strcmp( k, "stepsize" ) ) g_mv.stepsize = v;
			else Fail( "unknown movevar", line );
		}
		else if ( !strcmp( word, "cmd" ) )
		{
			// cmd count msec pitch yaw roll forward side up buttons [dpitch dyaw droll]
			Cmd c;
			memset( &c, 0, sizeof( c ) );
			int n = sscanf( rest, "%d %d %f %f %f %f %f %f %i %f %f %f", &c.count, &c.msec,
				&c.angles[0], &c.angles[1], &c.angles[2], &c.fwd, &c.side, &c.up, &c.buttons,
				&c.dangles[0], &c.dangles[1], &c.dangles[2] );
			if ( n != 9 && n != 12 ) Fail( "bad cmd", line );
			cmds.push_back( c );
		}
		else
			Fail( "unknown keyword", line );
	}
	fclose( f );

	for ( int i = 0; i < (int)g_ladders.size(); i++ )
	{
		physent_t *pe = &g_pm.moveents[i];
		memset( pe, 0, sizeof( *pe ) );
		strcpy( pe->name, "ladder" );
		pe->model = (struct model_s *)&g_fakeModel[i];
		pe->skin = CONTENTS_LADDER;
	}
	g_pm.nummoveent = (int)g_ladders.size();

	dll.pfnPM_Init( &g_pm );

	int tick = 0;
	for ( size_t ci = 0; ci < cmds.size(); ci++ )
	{
		Cmd &c = cmds[ci];
		float angles[3] = { c.angles[0], c.angles[1], c.angles[2] };
		for ( int k = 0; k < c.count; k++ )
		{
			memset( &g_pm.cmd, 0, sizeof( g_pm.cmd ) );
			g_pm.cmd.msec = (byte)c.msec;
			for ( int a = 0; a < 3; a++ ) g_pm.cmd.viewangles[a] = angles[a];
			g_pm.cmd.forwardmove = c.fwd;
			g_pm.cmd.sidemove = c.side;
			g_pm.cmd.upmove = c.up;
			g_pm.cmd.buttons = (unsigned short)c.buttons;
			g_pm.oldangles[0] = g_pm.angles[0]; g_pm.oldangles[1] = g_pm.angles[1]; g_pm.oldangles[2] = g_pm.angles[2];
			g_pm.time = (float)( g_time * 1000.0 );

			dll.pfnPM_Move( &g_pm, 1 );

			g_time += c.msec / 1000.0;
			for ( int a = 0; a < 3; a++ ) angles[a] += c.dangles[a];

			printf( "%d %.9g %.9g %.9g %.9g %.9g %.9g %d %d %d %d %.9g %d\n", tick,
				g_pm.origin[0], g_pm.origin[1], g_pm.origin[2],
				g_pm.velocity[0], g_pm.velocity[1], g_pm.velocity[2],
				g_pm.flags & ( FL_ONGROUND | FL_DUCKING | FL_WATERJUMP ), g_pm.onground,
				g_pm.waterlevel, g_pm.usehull, g_pm.view_ofs[2], g_pm.movetype );
			tick++;
		}
	}
	return 0;
}
