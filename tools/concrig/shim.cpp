// Conc/frag ground-truth rig: a game DLL shim that runs the real tfc.so
// unchanged and drives one fake client through scripted grenade jumps.
//
// The shim is linked against the game library (DT_NEEDED, rpath $ORIGIN),
// so the engine's dlsym() lookups of entity classes on the shim's handle
// fall through to tfc.so. Only GiveFnptrsToDll, GetEntityAPI(2) and
// GetNewDLLFunctions are exported; everything else is hidden, so nothing
// here interposes on tfc.so's own symbols. It wraps:
//   - Cmd_Argc/Argv/Args, to send the fake client's console commands
//     (jointeam, class, +gren1/+gren2) through the game's ClientCommand;
//   - StartFrame, to issue the fake client's usercmds (RunPlayerMove) at a
//     fixed client frame rate and log the player state every server frame.
//
// Configuration (environment):
//   CONCRIG_PLAN   trial list, one per line: <move> <jump> [phase_ms]
//                  move: stand | run;  jump: none | <ms before the blast>
//                  The first trial must be "stand none" (it measures when
//                  the held grenade goes off; jumps are timed from it).
//   CONCRIG_OUT    output prefix: <out>.frames.csv and <out>.trials.csv
//   CONCRIG_CLASS  scout | medic | soldier | ...   (default scout)
//   CONCRIG_GREN   1 or 2: which grenade slot to hold (default 2)
//   CONCRIG_FPS    client frame rate: one usercmd every 1000/fps ms (default 100)
//   CONCRIG_FWD    forwardmove while running (default 400)
//   CONCRIG_HEALTH health at the start of each trial (default: the class's)
//   CONCRIG_GRENCLASS classname of the held grenade (default: concussiongrenade
//                  for slot 2, normalgrenade for slot 1; empgrenade for the EMP)
//   CONCRIG_AMMO   shells,rockets,cells set at the start of each trial (an EMP's
//                  blast comes from the ammo carried)
//   CONCRIG_FLOOR  1: when the held grenade is let go (ExplodeInHand, one frame
//                  before it goes off) move it to the floor under the player's
//                  feet, as if it had been dropped there and was lying under him
//   CONCRIG_PROJ   rocket | pipe: no hand grenade; instead, CONCRIG_PROJ_DELAY s
//                  (default 0.5) after the "prime" the shim makes one of the player's
//                  own projectiles with the game's own code (CTFRpgRocket::CreateRpgRocket,
//                  CTFGrenade::CreateTFPipebomb) on the floor under his feet (straight
//                  down from where his feet are, so he can be in the air): a rocket 4
//                  above the floor flying straight down at 900, or a pipebomb lying on the
//                  floor set to go off. Either goes off in that frame's entity physics, after
//                  that frame's usercmd (a jump timed 0 ms comes in that usercmd).
//
//   CONCRIG_SLIDE  "x y z vx vy vz secs": no grenade; each trial puts the player at
//                  x y z with that velocity and runs no-key usercmds for secs, logging
//                  every frame (the ramp-slide runs; map from CONCRIG_RAMP). Usercmd
//                  lengths are whole ms with the fraction carried, as a real client's.
//
// When the plan is done the shim runs "quit".

#include "extdll.h"
#include "in_buttons.h"
#include <dlfcn.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#define EXPORT extern "C" __attribute__( ( visibility( "default" ) ) )

namespace {

enginefuncs_t eng;          // the engine's table (ours to call)
enginefuncs_t gameEng;      // the copy handed to tfc.so (Cmd_* wrapped)
globalvars_t *gv;
DLL_FUNCTIONS game;         // tfc.so's table
void *gameLib;

// --- fake console commands -------------------------------------------------
bool fakeCmd;
std::vector<std::string> fakeArgv;
std::string fakeArgs;

int CmdArgc() { return fakeCmd ? (int)fakeArgv.size() : eng.pfnCmd_Argc(); }
const char *CmdArgv( int i )
{
	if ( !fakeCmd ) return eng.pfnCmd_Argv( i );
	return i < (int)fakeArgv.size() ? fakeArgv[i].c_str() : "";
}
const char *CmdArgs() { return fakeCmd ? fakeArgs.c_str() : eng.pfnCmd_Args(); }

void ClientCmd( edict_t *e, const char *a0, const char *a1 = NULL )
{
	fakeArgv.clear();
	fakeArgv.push_back( a0 );
	fakeArgs = "";
	if ( a1 ) { fakeArgv.push_back( a1 ); fakeArgs = a1; }
	fakeCmd = true;
	game.pfnClientCommand( e );
	fakeCmd = false;
}

// --- private data offsets (CBaseEntity, from src/tfc/layout_checks.cpp) -----
const int OFS_NO_GRENADES_1 = 72, OFS_NO_GRENADES_2 = 76;
const int OFS_AMMO_SHELLS = 228, OFS_AMMO_CELLS = 244, OFS_AMMO_ROCKETS = 252;
int &PrivInt( edict_t *e, int ofs ) { return *(int *)( (char *)e->pvPrivateData + ofs ); }

// --- configuration -----------------------------------------------------------
struct Trial { bool run, duck, jduck; int jumpMs; int phaseMs; };
std::vector<Trial> plan;
std::string outPrefix, className = "scout";
int grenSlot = 2, fps = 100;
bool slide;                     // CONCRIG_SLIDE runs
Vector slidePos, slideVel;
float slideSecs;
double msecCarry;
std::string grenClass;
int ammoShells = -1, ammoRockets = -1, ammoCells = -1;
bool grenToFloor;
std::string projKind;       // "", "rocket" or "pipe"
float projDelay = 0.5f;
float fwdSpeed = 400;
FILE *fFrames, *fTrials;

const char *Env( const char *k, const char *d ) { const char *v = getenv( k ); return v && *v ? v : d; }

void LoadConfig()
{
	className = Env( "CONCRIG_CLASS", "scout" );
	grenSlot = atoi( Env( "CONCRIG_GREN", "2" ) );
	fps = atoi( Env( "CONCRIG_FPS", "100" ) );
	fwdSpeed = atof( Env( "CONCRIG_FWD", "400" ) );
	outPrefix = Env( "CONCRIG_OUT", "concrig" );
	grenClass = Env( "CONCRIG_GRENCLASS", grenSlot == 2 ? "concussiongrenade" : "normalgrenade" );
	sscanf( Env( "CONCRIG_AMMO", "" ), "%d,%d,%d", &ammoShells, &ammoRockets, &ammoCells );
	grenToFloor = atoi( Env( "CONCRIG_FLOOR", "0" ) ) != 0;
	projKind = Env( "CONCRIG_PROJ", "" );
	projDelay = atof( Env( "CONCRIG_PROJ_DELAY", "0.5" ) );
	slide = sscanf( Env( "CONCRIG_SLIDE", "" ), "%f %f %f %f %f %f %f", &slidePos.x, &slidePos.y, &slidePos.z,
		&slideVel.x, &slideVel.y, &slideVel.z, &slideSecs ) == 7;
	FILE *f = fopen( Env( "CONCRIG_PLAN", "plan.txt" ), "r" );
	char line[256];
	while ( f && fgets( line, sizeof( line ), f ) )
	{
		char mv[32] = "", jp[32] = "";
		int ph = 0;
		if ( line[0] == '#' || sscanf( line, "%31s %31s %d", mv, jp, &ph ) < 2 ) continue;
		Trial t;
		t.run = !strncmp( mv, "run", 3 );
		t.jduck = strstr( mv, "jduck" ) != NULL;  // standjduck / runjduck: duck held from the jump on
		t.duck = !t.jduck && strstr( mv, "duck" ) != NULL;   // standduck / runduck: duck held all trial
		t.jumpMs = !strcmp( jp, "none" ) ? -1 : atoi( jp );
		t.phaseMs = ph;
		plan.push_back( t );
	}
	if ( f ) fclose( f );
}

// --- the driver --------------------------------------------------------------
enum Stage { S_NONE, S_JOIN, S_SPAWNWAIT, S_SETTLE, S_PRIMED, S_FLIGHT, S_SLIDE, S_DONE };
Stage stage = S_NONE;
edict_t *bot;
float stageStart;
int frameNo;
float lastCmdTime;          // sim time of the last usercmd
double cmdPeriod;           // seconds per usercmd
double nextCmd;             // sim time the next usercmd is due

// per trial
int ti = -1;
float tPrime, detOffset = -1;   // detOffset: calibrated prime->detonation time
bool perFrame;                  // one usercmd per server frame (fps == tick)
bool armedNow;                  // the held grenade was set off in the last frame
float tJump;
edict_t *gren;
Vector grenArmed, grenLast, detPos, vPreDet, vPostCmd, startPos;
bool armed, detonated, leftGround;
float tDet, peakZ, zGround, tLand, hpBefore, apBefore;
Vector landPos, vAfter;
float spawnArmor, spawnHealth;
int flightFrames;
float prevTime;
float primeAt;       // sim time to prime the grenade (settle stage)
int tick;      // sim time of the previous server frame

Vector Origin( edict_t *e ) { return e->v.origin; }

void Teleport( edict_t *e, const Vector &o )
{
	eng.pfnSetOrigin( e, (float *)&o );
	e->v.velocity = Vector( 0, 0, 0 );
	e->v.basevelocity = Vector( 0, 0, 0 );
}

void ResetPlayer()
{
	// CONCRIG_HEALTH: a held frag kills a medic; more health keeps the run
	// going without changing the push (knockback depends on damage and armor)
	float hp = atof( Env( "CONCRIG_HEALTH", "0" ) );
	bot->v.health = hp > 0 ? hp : spawnHealth;
	bot->v.armorvalue = spawnArmor;
	PrivInt( bot, OFS_NO_GRENADES_1 ) = 4;
	PrivInt( bot, OFS_NO_GRENADES_2 ) = 4;
	if ( ammoShells >= 0 ) PrivInt( bot, OFS_AMMO_SHELLS ) = ammoShells;
	if ( ammoRockets >= 0 ) PrivInt( bot, OFS_AMMO_ROCKETS ) = ammoRockets;
	if ( ammoCells >= 0 ) PrivInt( bot, OFS_AMMO_CELLS ) = ammoCells;
	bot->v.punchangle = Vector( 0, 0, 0 );
}

void RunCmd( float fwd, unsigned short buttons, int msec )
{
	Vector ang( 0, 0, 0 );
	eng.pfnRunPlayerMove( bot, (float *)&ang, fwd, 0, 0, buttons, 0, (byte)msec );
}

edict_t *FindGrenade()
{
	const char *cls = grenClass.c_str();
	edict_t *e = NULL, *best = NULL;
	for ( ;; )
	{
		e = eng.pfnFindEntityByString( e, "classname", cls );
		if ( !e || eng.pfnEntOffsetOfPEntity( e ) == 0 ) break;
		if ( e->v.owner == bot ) best = e;
	}
	return best;
}

// The game's own projectile makers. Their Vector arguments are passed by
// reference (Vector has a copy constructor), so they take pointers here.
typedef void *( *CreateProjFn )( const Vector *, const Vector *, void *, void * );
void *GameSym( const char *name );

edict_t *EntityEdict( void *ent )
{
	// CBaseEntity: the vtable, then pev
	entvars_t *pev = *(entvars_t **)( (char *)ent + 4 );
	return pev ? pev->pContainingEntity : NULL;
}

// A rocket or pipebomb of the player's own on the floor under his feet, set to go off
// in this frame's entity physics
edict_t *MakeProjectile()
{
	Vector feet = bot->v.origin;
	feet.z += bot->v.mins.z;
	TraceResult tr;
	Vector down = feet - Vector( 0, 0, 4096 );
	eng.pfnTraceLine( (float *)&feet, (float *)&down, 1, bot, &tr );   // 1: ignore monsters
	Vector ground = tr.vecEndPos;
	Vector ang( 0, 0, 0 );
	void *owner = bot->pvPrivateData;
	edict_t *e = NULL;
	if ( projKind == "rocket" )
	{
		static CreateProjFn make = (CreateProjFn)GameSym( "_ZN12CTFRpgRocket15CreateRpgRocketE6VectorS0_P11CBaseEntityP6CTFRpg" );
		Vector o = ground + Vector( 0, 0, 4 );
		ang.x = 90;
		e = make ? EntityEdict( make( &o, &ang, owner, NULL ) ) : NULL;
		if ( e ) { eng.pfnSetOrigin( e, (float *)&o ); e->v.velocity = Vector( 0, 0, -900 ); }
	}
	else
	{
		static CreateProjFn make = (CreateProjFn)GameSym( "_ZN10CTFGrenade16CreateTFPipebombE6VectorS0_P11CBaseEntityP18CTFGrenadeLauncher" );
		e = make ? EntityEdict( make( &ground, &ang, owner, NULL ) ) : NULL;
		if ( e )
		{
			eng.pfnSetOrigin( e, (float *)&ground );
			e->v.velocity = Vector( 0, 0, 0 );
			e->v.avelocity = Vector( 0, 0, 0 );
			e->v.flags |= FL_ONGROUND;
			e->v.nextthink = gv->time;   // PipebombDetonate, as when he sets it off
		}
	}
	if ( !e ) eng.pfnServerPrint( "concrig: could not make the projectile\n" );
	return e;
}

void StartTrial()
{
	ti++;
	if ( ti >= (int)plan.size() )
	{
		stage = S_DONE;
		fclose( fFrames ); fclose( fTrials );
		eng.pfnServerCommand( (char *)"quit\n" );
		return;
	}
	if ( slide )
	{
		Teleport( bot, slidePos );
		ResetPlayer();
		bot->v.velocity = slideVel;
		bot->v.flags &= ~FL_ONGROUND;
		tPrime = gv->time;
		stage = S_SLIDE;
		stageStart = gv->time;
		return;
	}
	const Trial &t = plan[ti];
	startPos = Vector( t.run ? -3900 : -2000, 0, 40 );
	Teleport( bot, startPos );
	ResetPlayer();
	stage = S_SETTLE;
	stageStart = gv->time;
	primeAt = -1;
}

void BeginPrime()
{
	const Trial &t = plan[ti];
	ResetPlayer();
	hpBefore = bot->v.health; apBefore = bot->v.armorvalue;
	zGround = bot->v.origin.z;
	if ( projKind.empty() ) ClientCmd( bot, grenSlot == 2 ? "+gren2" : "+gren1" );
	tPrime = gv->time;
	tJump = -1;
	gren = NULL; armed = detonated = leftGround = false;
	peakZ = zGround; tDet = tLand = -1; flightFrames = 0;
	stage = S_PRIMED;
	stageStart = gv->time;
}

void FinishTrial()
{
	const Trial &t = plan[ti];
	Vector hd = landPos - detPos; hd.z = 0;
	float vh = sqrt( vAfter.x * vAfter.x + vAfter.y * vAfter.y );
	float d = ( detPos - grenLast ).Length();
	fprintf( fTrials, "%d,%s,%d,%d,%s,%d,%d,%.4f,%.4f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.1f,%.1f,%.1f,%.1f\n",
		ti, className.c_str(), tick, fps, t.jduck ? ( t.run ? "runjduck" : "standjduck" ) : t.duck ? ( t.run ? "runduck" : "standduck" ) : t.run ? "run" : "stand", t.jumpMs, t.phaseMs,
		tDet - tPrime, tJump >= 0 ? tDet - tJump : -1.0f,
		d,
		vPreDet.x, vPreDet.y, vPreDet.z, vAfter.x, vAfter.y, vAfter.z, vh,
		peakZ - zGround, hd.Length(), tLand > 0 ? tLand - tDet : -1.0f, landPos.x, detPos.x,
		hpBefore, bot->v.health, apBefore, bot->v.armorvalue );
	fflush( fTrials );
	if ( ti == 0 ) detOffset = tDet - tPrime;
	StartTrial();
}

void LogFrame( const char *tag )
{
	edict_t *e = bot;
	fprintf( fFrames, "%d,%d,%.5f,%.5f,%.5f,%s,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%d,%d,%.1f\n",
		ti, frameNo, gv->time, gv->time - tPrime, gv->frametime, tag,
		e->v.origin.x, e->v.origin.y, e->v.origin.z,
		e->v.velocity.x, e->v.velocity.y, e->v.velocity.z,
		( e->v.flags & FL_ONGROUND ) ? 1 : 0, (int)e->v.button, e->v.health );
}

void Drive()
{
	frameNo++;
	switch ( stage )
	{
	case S_NONE:
		if ( gv->time < 1.0 ) return;
		{
			LoadConfig();
			fFrames = fopen( ( outPrefix + ".frames.csv" ).c_str(), "w" );
			fTrials = fopen( ( outPrefix + ".trials.csv" ).c_str(), "w" );
			fprintf( fFrames, "trial,frame,time,trel,frametime,tag,ox,oy,oz,vx,vy,vz,onground,buttons,health\n" );
			fprintf( fTrials, "trial,class,tick,fps,move,jump_ms,phase_ms,det_after_prime,det_after_jump,dist,"
				"vpre_x,vpre_y,vpre_z,vpost_x,vpost_y,vpost_z,vpost_h,peak,land_dist,flight_time,land_x,det_x,"
				"hp_before,hp_after,ap_before,ap_after\n" );
			cmdPeriod = 1.0 / fps;
			tick = atoi( Env( "CONCRIG_TICK", "0" ) );
			perFrame = fps == tick;
			bot = eng.pfnCreateFakeClient( "rig" );
			char reject[128];
			game.pfnClientConnect( bot, "rig", "127.0.0.1", reject );
			game.pfnClientPutInServer( bot );
			stage = S_JOIN; stageStart = gv->time;
			nextCmd = gv->time;
		}
		return;
	default: break;
	}
	if ( stage == S_DONE ) return;

	// state after the last frame's physics (blast lands between cmds)
	if ( stage == S_PRIMED || stage == S_FLIGHT || stage == S_SLIDE ) LogFrame( "pre" );

	armedNow = false;
	if ( stage == S_PRIMED && !projKind.empty() && !armed && gv->time >= tPrime + projDelay - 0.0002 )
	{
		gren = MakeProjectile();
		if ( gren ) { armed = armedNow = true; grenArmed = grenLast = gren->v.origin; }
	}
	if ( stage == S_PRIMED )
	{
		if ( !gren && projKind.empty() ) gren = FindGrenade();
		if ( gren && !gren->free )
		{
			if ( !armed && gren->v.movetype == MOVETYPE_BOUNCE )
			{
				armed = armedNow = true;
				if ( grenToFloor )
				{
					// lying on the floor under his feet (a point entity at rest sits on it)
					Vector o = bot->v.origin;
					o.z += bot->v.mins.z;
					eng.pfnSetOrigin( gren, (float *)&o );
					gren->v.velocity = Vector( 0, 0, 0 );
				}
				grenArmed = gren->v.origin;
			}
			if ( armed ) grenLast = gren->v.origin;
		}
		bool gone = gren && ( gren->free || ( gren->v.flags & FL_KILLME ) || ( gren->v.effects & EF_NODRAW ) || !gren->v.owner );
		if ( armed && gone )
		{
			// went off during the previous frame's entity physics
			detonated = true;
			detPos = bot->v.origin;
			tDet = prevTime;
			vAfter = bot->v.velocity;
			stage = S_FLIGHT;
			stageStart = gv->time;
		}
	}

	// usercmds due this frame. With fps == tick there is exactly one per
	// server frame; otherwise they run on a fixed cadence in sim time.
	const Trial *t = ti >= 0 && ti < (int)plan.size() ? &plan[ti] : NULL;
	bool wantJump = false;
	if ( stage == S_PRIMED && t && t->jumpMs >= 0 && tJump < 0 )
	{
		if ( t->jumpMs == 0 )
			wantJump = armedNow;   // goes off in this frame's entity physics
		else if ( detOffset > 0 )
			wantJump = gv->time >= tPrime + detOffset - t->jumpMs / 1000.0 - 0.5 * ( perFrame ? gv->frametime : cmdPeriod );
	}
	bool due = perFrame || gv->time >= nextCmd - 0.0002;
	if ( wantJump && !due ) { due = true; nextCmd = gv->time; }   // the jump cmd lands in this frame
	while ( due )
	{
		float fwd = 0;
		unsigned short buttons = 0;
		if ( t && t->run && ( stage == S_PRIMED || stage == S_FLIGHT ) ) { fwd = fwdSpeed; buttons |= IN_FORWARD; }
		if ( t && t->duck && ( stage == S_PRIMED || stage == S_FLIGHT ) ) buttons |= IN_DUCK;
		if ( t && t->jduck && ( wantJump || tJump >= 0 ) && ( stage == S_PRIMED || stage == S_FLIGHT ) ) buttons |= IN_DUCK;
		if ( wantJump ) { buttons |= IN_JUMP; tJump = gv->time; wantJump = false; }
		int msec = (int)( cmdPeriod * 1000 + 0.5 );
		if ( slide )
		{
			msec = (int)( cmdPeriod * 1000 );
			msecCarry += cmdPeriod * 1000 - msec;
			if ( msecCarry > 1 ) { msecCarry -= 1; msec++; }
		}
		RunCmd( fwd, buttons, msec );
		nextCmd += cmdPeriod;
		lastCmdTime = gv->time;
		due = !perFrame && gv->time >= nextCmd - 0.0002;
	}

	switch ( stage )
	{
	case S_JOIN:
		if ( gv->time - stageStart > 0.5 && gv->time - stageStart < 0.6 )
			ClientCmd( bot, "jointeam", "1" );
		if ( gv->time - stageStart > 1.0 )
		{
			ClientCmd( bot, className.c_str() );
			stage = S_SPAWNWAIT; stageStart = gv->time;
		}
		break;
	case S_SPAWNWAIT:
		if ( bot->v.health > 0 && bot->v.playerclass && bot->v.movetype == MOVETYPE_WALK && gv->time - stageStart > 3 )
		{
			spawnHealth = bot->v.health;
			spawnArmor = bot->v.armorvalue;
			eng.pfnServerPrint( "concrig: player spawned\n" );
			StartTrial();
		}
		break;
	case S_SETTLE:
		// at rest on the floor for a second, then prime on a cmd frame
		// (the prime comes phase_ms after a usercmd)
		if ( primeAt < 0 && gv->time - stageStart > 1.0 && ( bot->v.flags & FL_ONGROUND ) && lastCmdTime == gv->time )
			primeAt = gv->time + plan[ti].phaseMs / 1000.0;
		if ( primeAt >= 0 && gv->time >= primeAt - 0.0002 )
			BeginPrime();
		break;
	case S_SLIDE:
		if ( gv->time - stageStart > slideSecs ) StartTrial();
		break;
	case S_PRIMED:
		vPreDet = bot->v.velocity;
		if ( gv->time - tPrime > 6 ) { eng.pfnServerPrint( "concrig: grenade never went off\n" ); FinishTrial(); }
		break;
	case S_FLIGHT:
		if ( bot->v.origin.z > peakZ ) peakZ = bot->v.origin.z;
		if ( !( bot->v.flags & FL_ONGROUND ) ) leftGround = true;
		if ( ( leftGround && ( bot->v.flags & FL_ONGROUND ) ) || gv->time - stageStart > 6 || ( !leftGround && gv->time - stageStart > 0.5 ) )
		{
			tLand = gv->time;
			landPos = bot->v.origin;
			if ( !leftGround ) tLand = tDet;
			FinishTrial();
		}
		break;
	default: break;
	}
	if ( stage == S_PRIMED || stage == S_FLIGHT || stage == S_SLIDE ) LogFrame( "cmd" );
}

void StartFrameHook()
{
	// sv.time; after a usercmd gpGlobals->time is left at the client's time
	// base (the end of this frame), so keep the frame start
	float t0 = gv->time;
	Drive();
	prevTime = t0;
	game.pfnStartFrame();
}

typedef void ( *GiveFnptrsFn )( enginefuncs_t *, globalvars_t * );
typedef int ( *GetAPIFn )( DLL_FUNCTIONS *, int );
typedef int ( *GetAPI2Fn )( DLL_FUNCTIONS *, int * );
typedef int ( *GetNewFn )( NEW_DLL_FUNCTIONS *, int * );

void *GameSym( const char *name )
{
	if ( !gameLib ) gameLib = dlopen( "tfc_game.so", RTLD_NOW | RTLD_NOLOAD );
	return gameLib ? dlsym( gameLib, name ) : NULL;
}

} // namespace

EXPORT void GiveFnptrsToDll( enginefuncs_t *pengfuncs, globalvars_t *pGlobals )
{
	memcpy( &eng, pengfuncs, sizeof( eng ) );
	memcpy( &gameEng, pengfuncs, sizeof( gameEng ) );
	gameEng.pfnCmd_Argc = CmdArgc;
	gameEng.pfnCmd_Argv = CmdArgv;
	gameEng.pfnCmd_Args = CmdArgs;
	gv = pGlobals;
	( (GiveFnptrsFn)GameSym( "GiveFnptrsToDll" ) )( &gameEng, pGlobals );
}

// CONCRIG_PMSO: a library whose GetEntityAPI2 gives its own PM_Move/PM_Init (e.g. OTFC Movement
// Fixes' test/pmtest.so) runs player movement instead of the game's
static void Hook( DLL_FUNCTIONS *out )
{
	out->pfnStartFrame = StartFrameHook;
	const char *pm = getenv( "CONCRIG_PMSO" );
	if ( pm && *pm )
	{
		void *lib = dlopen( pm, RTLD_NOW | RTLD_LOCAL );
		GetAPI2Fn get = lib ? (GetAPI2Fn)dlsym( lib, "GetEntityAPI2" ) : NULL;
		DLL_FUNCTIONS t;
		int v = INTERFACE_VERSION;
		if ( get && get( &t, &v ) ) { out->pfnPM_Move = t.pfnPM_Move; out->pfnPM_Init = t.pfnPM_Init; }
		else eng.pfnServerPrint( "concrig: could not load CONCRIG_PMSO\n" );
	}
}

EXPORT int GetEntityAPI( DLL_FUNCTIONS *pFunctionTable, int interfaceVersion )
{
	if ( !( (GetAPIFn)GameSym( "GetEntityAPI" ) )( &game, interfaceVersion ) ) return 0;
	memcpy( pFunctionTable, &game, sizeof( game ) );
	Hook( pFunctionTable );
	return 1;
}

EXPORT int GetEntityAPI2( DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion )
{
	if ( !( (GetAPI2Fn)GameSym( "GetEntityAPI2" ) )( &game, interfaceVersion ) ) return 0;
	memcpy( pFunctionTable, &game, sizeof( game ) );
	Hook( pFunctionTable );
	return 1;
}

EXPORT int GetNewDLLFunctions( NEW_DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion )
{
	GetNewFn f = (GetNewFn)GameSym( "GetNewDLLFunctions" );
	return f ? f( pFunctionTable, interfaceVersion ) : 0;
}
