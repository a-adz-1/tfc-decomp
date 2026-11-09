/***
*
*	Team Fortress Classic: client-side weapon and explosion effects
*
*	Reconstructed from client.so (25th Anniversary), DWARF-guided.
*
****/
#include "hud.h"
#include "cl_util.h"
#include "const.h"
#include "entity_state.h"
#include "cl_entity.h"
#include "entity_types.h"
#include "usercmd.h"
#include "pm_defs.h"
#include "pm_materials.h"

#include "eventscripts.h"
#include "ev_hldm.h"

#include "r_efx.h"
#include "event_api.h"
#include "event_args.h"
#include "in_defs.h"

#include <string.h>

#include "r_studioint.h"
#include "com_model.h"

#include "particleman.h"
extern IParticleMan *g_pParticleMan;
extern globalvars_t *gpGlobals;
extern "C" int PM_GetPhysEntInfo( int ent );

#define TF_DEFS_ONLY
#include "tf_defs.h"

extern engine_studio_api_t IEngineStudio;

extern "C"
{
#include "pm_shared.h"
float anglemod( float a );
}

void V_PunchAxis( int axis, float punch );
void VectorAngles( const float *forward, float *angles );

extern cvar_t *cl_lw;
extern cvar_t *cl_gibcount;
extern cvar_t *cl_giblife;
extern cvar_t *cl_gibvelscale;
extern cvar_t *cl_localblood;

// Assault cannon spin state, per player
int g_bACSpinning[ 32 ];
static float g_flSpinUpTime[ 32 ];
static float g_flSpinDownTime[ 32 ];

static int tracerCount[ 32 ];

#define BLOOD_COLOR_RED		247
#define DONT_BLEED			-1

#define SND_CHANGE_PITCH	(1<<7)		// duplicated in protocol.h change sound pitch

extern "C"
{
void EV_FireTFCShotgun( struct event_args_s *args );
void EV_ReloadTFCShotgun( struct event_args_s *args );
void EV_PumpTFCShotgun( struct event_args_s *args );
void EV_FireTFCNailgun( struct event_args_s *args );
void EV_FireTFCAutoRifle( struct event_args_s *args );
void EV_FireTFCSuperShotgun( struct event_args_s *args );
void EV_FireTFCSuperNailgun( struct event_args_s *args );
void EV_TFC_Assault_WindUp( struct event_args_s *args );
void EV_TFC_Assault_WindDown( struct event_args_s *args );
void EV_TFC_Assault_Start( struct event_args_s *args );
void EV_TFC_Assault_Fire( struct event_args_s *args );
void EV_TFC_Assault_StartSpin( struct event_args_s *args );
void EV_TFC_Assault_Spin( struct event_args_s *args );
void EV_TFC_Flame_Fire( struct event_args_s *args );
void EV_TFC_Knife( struct event_args_s *args );
void EV_TFC_Tranquilizer( struct event_args_s *args );
void EV_TFC_Railgun( struct event_args_s *args );
void EV_TFC_DoorGoUp( struct event_args_s *args );
void EV_TFC_DoorGoDown( struct event_args_s *args );
void EV_TFC_DoorHitTop( struct event_args_s *args );
void EV_TFC_DoorHitBottom( struct event_args_s *args );
void EV_TFC_Explosion( struct event_args_s *args );
void EV_TFC_Grenade( struct event_args_s *args );
void EV_TFC_EngineerGrenade( struct event_args_s *args );
void EV_TFC_Concussion( struct event_args_s *args );
void EV_TFC_NormalGrenade( struct event_args_s *args );
void EV_TFC_MirvGrenadeMain( struct event_args_s *args );
void EV_TFC_MirvGrenade( struct event_args_s *args );
void EV_TFC_NapalmFire( struct event_args_s *args );
void EV_TFC_NapalmBurn( struct event_args_s *args );
void EV_TFC_Gas( struct event_args_s *args );
void EV_TFC_EMP( struct event_args_s *args );
void EV_TFC_NailgrenadeNail( struct event_args_s *args );
void EV_TFC_NailGrenade( struct event_args_s *args );
void EV_TFC_FireRPG( struct event_args_s *args );
void EV_TFC_FireIC( struct event_args_s *args );
void EV_TFC_SniperHit( struct event_args_s *args );
void EV_FireTFCSniper( struct event_args_s *args );
void EV_TFC_GrenadeLauncher( struct event_args_s *args );
void EV_TFC_PipeLauncher( struct event_args_s *args );
void EV_TFC_Axe( struct event_args_s *args );
void EV_TFC_AxeDecal( struct event_args_s *args );
void EV_TFC_SteamShot( struct event_args_s *args );
void EV_TFC_NormalShot( struct event_args_s *args );
void EV_TFC_SuperShot( struct event_args_s *args );
void EV_TFC_Gibs( struct event_args_s *args );
void EV_Benchmark( struct event_args_s *args );
void EV_TFC_BuildingEvent( struct event_args_s *args );
}

//======================
//	    HELPERS
//======================

// play a strike sound based on the texture that was hit by the attack traceline.  VecSrc/VecEnd are the
// original traceline endpoints used by the attacker, iBulletType is the type of bullet that hit the texture.
// returns volume of strike instrument (crowbar) to play
float EV_TFC_PlayTextureSound( int idx, pmtrace_t *ptr, float *vecSrc, float *vecEnd, int iBulletType )
{
	// hit the world, try to play sound based on texture material type
	char chTextureType = CHAR_TEX_CONCRETE;
	float fvol;
	float fvolbar;
	char *rgsz[4];
	int cnt;
	float fattn = ATTN_NORM;
	int entity;
	char *pTextureName;
	char texname[ 64 ];
	char szbuffer[ 64 ];

	entity = gEngfuncs.pEventAPI->EV_IndexFromTrace( ptr );

	chTextureType = 0;

	if ( entity >= 1 && entity <= gEngfuncs.GetMaxClients() )
	{
		// hit body
		chTextureType = CHAR_TEX_FLESH;
	}
	else if ( entity == 0 )
	{
		// get texture from entity or world (world is ent(0))
		pTextureName = (char *)gEngfuncs.pEventAPI->EV_TraceTexture( ptr->ent, vecSrc, vecEnd );

		if ( pTextureName )
		{
			strcpy( texname, pTextureName );
			pTextureName = texname;

			// strip leading '-0' or '+0~' or '{' or '!'
			if ( *pTextureName == '-' || *pTextureName == '+' )
			{
				pTextureName += 2;
			}

			if ( *pTextureName == '{' || *pTextureName == '!' || *pTextureName == '~' || *pTextureName == ' ' )
			{
				pTextureName++;
			}

			// '}}'
			strcpy( szbuffer, pTextureName );
			szbuffer[ CBTEXTURENAMEMAX - 1 ] = 0;

			// get texture type
			chTextureType = PM_FindTextureType( szbuffer );
		}
	}

	switch ( chTextureType )
	{
	default:
	case CHAR_TEX_CONCRETE: fvol = 0.9;	fvolbar = 0.6;
		rgsz[0] = "player/pl_step1.wav";
		rgsz[1] = "player/pl_step2.wav";
		cnt = 2;
		break;
	case CHAR_TEX_METAL: fvol = 0.9; fvolbar = 0.3;
		rgsz[0] = "player/pl_metal1.wav";
		rgsz[1] = "player/pl_metal2.wav";
		cnt = 2;
		break;
	case CHAR_TEX_DIRT:	fvol = 0.9; fvolbar = 0.1;
		rgsz[0] = "player/pl_dirt1.wav";
		rgsz[1] = "player/pl_dirt2.wav";
		rgsz[2] = "player/pl_dirt3.wav";
		cnt = 3;
		break;
	case CHAR_TEX_VENT:	fvol = 0.5; fvolbar = 0.3;
		rgsz[0] = "player/pl_duct1.wav";
		rgsz[1] = "player/pl_duct1.wav";
		cnt = 2;
		break;
	case CHAR_TEX_GRATE: fvol = 0.9; fvolbar = 0.5;
		rgsz[0] = "player/pl_grate1.wav";
		rgsz[1] = "player/pl_grate4.wav";
		cnt = 2;
		break;
	case CHAR_TEX_TILE:	fvol = 0.8; fvolbar = 0.2;
		rgsz[0] = "player/pl_tile1.wav";
		rgsz[1] = "player/pl_tile3.wav";
		rgsz[2] = "player/pl_tile2.wav";
		rgsz[3] = "player/pl_tile4.wav";
		cnt = 4;
		break;
	case CHAR_TEX_SLOSH: fvol = 0.9; fvolbar = 0.0;
		rgsz[0] = "player/pl_slosh1.wav";
		rgsz[1] = "player/pl_slosh3.wav";
		rgsz[2] = "player/pl_slosh2.wav";
		rgsz[3] = "player/pl_slosh4.wav";
		cnt = 4;
		break;
	case CHAR_TEX_WOOD: fvol = 0.9; fvolbar = 0.2;
		rgsz[0] = "debris/wood1.wav";
		rgsz[1] = "debris/wood2.wav";
		rgsz[2] = "debris/wood3.wav";
		cnt = 3;
		break;
	case CHAR_TEX_GLASS:
	case CHAR_TEX_COMPUTER:
		fvol = 0.8; fvolbar = 0.2;
		rgsz[0] = "debris/glass1.wav";
		rgsz[1] = "debris/glass2.wav";
		rgsz[2] = "debris/glass3.wav";
		cnt = 3;
		break;
	case CHAR_TEX_FLESH:
		if ( iBulletType == BULLET_PLAYER_CROWBAR )
			return 0.0; // crowbar already makes this sound
		fvol = 1.0;	fvolbar = 0.2;
		rgsz[0] = "weapons/bullet_hit1.wav";
		rgsz[1] = "weapons/bullet_hit2.wav";
		fattn = 1.0;
		cnt = 2;
		break;
	}

	// did we hit a breakable?
	if ( chTextureType == CHAR_TEX_COMPUTER && ptr->fraction != 1.0 && gEngfuncs.pfnRandomLong( 0, 1 ) )
	{
		// play random spark if computer
		gEngfuncs.pEfxAPI->R_SparkEffect( ptr->endpos, 8, -200, 200 );

		float flVolume = gEngfuncs.pfnRandomFloat( 0.7, 1.0 );
		switch ( gEngfuncs.pfnRandomLong( 0, 1 ) )
		{
		case 0: gEngfuncs.pEventAPI->EV_PlaySound( 0, ptr->endpos, CHAN_STATIC, "buttons/spark5.wav", flVolume, ATTN_NORM, 0, 100 ); break;
		case 1: gEngfuncs.pEventAPI->EV_PlaySound( 0, ptr->endpos, CHAN_STATIC, "buttons/spark6.wav", flVolume, ATTN_NORM, 0, 100 ); break;
		}
	}

	// play material hit sound
	gEngfuncs.pEventAPI->EV_PlaySound( 0, ptr->endpos, CHAN_STATIC, rgsz[ gEngfuncs.pfnRandomLong( 0, cnt - 1 ) ], fvol, fattn, 0, 96 + gEngfuncs.pfnRandomLong( 0, 0xf ) );
	return fvolbar;
}

char *EV_TFC_DamageDecal( int entity, int bitsDamageType )
{
	static char decalname[ 32 ];
	int idx;
	physent_t *pe;

	decalname[ 0 ] = 0;

	pe = gEngfuncs.pEventAPI->EV_GetPhysent( entity );
	if ( pe && pe->rendermode != kRenderTransAlpha )
	{
		if ( pe->rendermode != kRenderNormal )
		{
			sprintf( decalname, "{bproof1" );
		}
		else
		{
			idx = gEngfuncs.pfnRandomLong( 0, 4 );
			sprintf( decalname, "{shot%i", idx + 1 );
		}
	}
	return decalname;
}

void EV_TFC_GunshotDecalTrace( pmtrace_t *pTrace, char *decalName )
{
	int iRand;
	physent_t *pe;

	if ( !decalName || !decalName[0] || pTrace->fraction == 1.0 )
		return;

	gEngfuncs.pEfxAPI->R_BulletImpactParticles( pTrace->endpos );

	iRand = gEngfuncs.pfnRandomLong( 0, 0x7FFF );
	if ( iRand < ( 0x7fff / 2 ) )// not every bullet makes a sound.
	{
		switch ( iRand % 5 )
		{
		case 0:	gEngfuncs.pEventAPI->EV_PlaySound( -1, pTrace->endpos, 0, "weapons/ric1.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
		case 1:	gEngfuncs.pEventAPI->EV_PlaySound( -1, pTrace->endpos, 0, "weapons/ric2.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
		case 2:	gEngfuncs.pEventAPI->EV_PlaySound( -1, pTrace->endpos, 0, "weapons/ric3.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
		case 3:	gEngfuncs.pEventAPI->EV_PlaySound( -1, pTrace->endpos, 0, "weapons/ric4.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
		case 4:	gEngfuncs.pEventAPI->EV_PlaySound( -1, pTrace->endpos, 0, "weapons/ric5.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
		}
	}

	pe = gEngfuncs.pEventAPI->EV_GetPhysent( pTrace->ent );

	// Only decal brush models such as the world etc.
	if ( pe && ( pe->solid == SOLID_BSP || pe->movetype == MOVETYPE_PUSHSTEP ) )
	{
		if ( CVAR_GET_FLOAT( "r_decals" ) )
		{
			gEngfuncs.pEfxAPI->R_DecalShoot(
				gEngfuncs.pEfxAPI->Draw_DecalIndex( gEngfuncs.pEfxAPI->Draw_DecalIndexFromName( decalName ) ),
				gEngfuncs.pEventAPI->EV_IndexFromTrace( pTrace ), 0, pTrace->endpos, 0 );
		}
	}
}

void EV_TFC_DecalTrace( pmtrace_t *pTrace, char *decalName )
{
	physent_t *pe;

	if ( !decalName || !decalName[0] )
		return;

	pe = gEngfuncs.pEventAPI->EV_GetPhysent( pTrace->ent );

	// Only decal brush models such as the world etc.
	if ( pe && ( pe->solid == SOLID_BSP || pe->movetype == MOVETYPE_PUSHSTEP ) )
	{
		if ( CVAR_GET_FLOAT( "r_decals" ) )
		{
			gEngfuncs.pEfxAPI->R_DecalShoot(
				gEngfuncs.pEfxAPI->Draw_DecalIndex( gEngfuncs.pEfxAPI->Draw_DecalIndexFromName( decalName ) ),
				gEngfuncs.pEventAPI->EV_IndexFromTrace( pTrace ), 0, pTrace->endpos, 0 );
		}
	}
}

void EV_TFC_DecalGunshot( pmtrace_t *pTrace, int iBulletType )
{
	physent_t *pe;

	pe = gEngfuncs.pEventAPI->EV_GetPhysent( pTrace->ent );

	if ( pe && ( pe->solid == SOLID_BSP || pe->movetype == MOVETYPE_PUSHSTEP ) )
	{
		switch ( iBulletType )
		{
		case BULLET_PLAYER_CROWBAR:
			EV_TFC_DecalTrace( pTrace, EV_TFC_DamageDecal( pTrace->ent, DMG_CLUB ) );
			break;
		case BULLET_PLAYER_TF_ASSAULT:
			EV_TFC_GunshotDecalTrace( pTrace, "hwshot1" );
			break;
		case BULLET_MONSTER_12MM:
		default:
			// smoke and decal
			EV_TFC_GunshotDecalTrace( pTrace, EV_TFC_DamageDecal( pTrace->ent, DMG_BULLET ) );
			break;
		}
	}
}

int EV_TFC_CheckTracer( int idx, float *vecSrc, float *end, float *forward, float *right, int iBulletType, int iTracerFreq, int *tracerCount )
{
	int tracer = 0;
	int i;
	qboolean player = idx >= 1 && idx <= gEngfuncs.GetMaxClients() ? true : false;

	if ( iTracerFreq != 0 && ( (*tracerCount)++ % iTracerFreq ) == 0 )
	{
		vec3_t vecTracerSrc;

		if ( player )
		{
			vec3_t offset( 0, 0, -4 );

			// adjust tracer position for player
			for ( i = 0; i < 3; i++ )
			{
				vecTracerSrc[ i ] = vecSrc[ i ] + offset[ i ] + right[ i ] * 2 + forward[ i ] * 16;
			}
		}
		else
		{
			VectorCopy( vecSrc, vecTracerSrc );
		}

		if ( iTracerFreq != 1 )		// guns that always trace also always decal
			tracer = 1;

		// shotgun pellets don't draw tracers
		if ( iBulletType != BULLET_PLAYER_TF_BUCKSHOT )
			EV_CreateTracer( vecTracerSrc, end );
	}

	return tracer;
}

int EV_TFC_ShouldShowBlood( int color )
{
	if ( color != DONT_BLEED )
	{
		if ( color == BLOOD_COLOR_RED )
		{
			if ( CVAR_GET_FLOAT( "violence_hblood" ) != 0 )
				return 1;
		}
		else
		{
			if ( CVAR_GET_FLOAT( "violence_ablood" ) != 0 )
				return 1;
		}
	}
	return 0;
}

void EV_TFC_BloodDrips( float *origin, int color, int amount )
{
	if ( !EV_TFC_ShouldShowBlood( color ) )
		return;

	if ( color == DONT_BLEED || amount == 0 )
		return;

	if ( gEngfuncs.GetMaxClients() > 1 )
		amount *= 2;

	if ( amount > 255 )
		amount = 255;

	int iSprayIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/bloodspray.spr" );
	int iDropIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/blood.spr" );

	gEngfuncs.pEfxAPI->R_BloodSprite( origin, color, iSprayIndex, iDropIndex, min( max( 3, amount / 10 ), 16 ) );
}

void EV_TFC_RandomBloodVector( float *direction )
{
	direction[0] = gEngfuncs.pfnRandomFloat( -1, 1 );
	direction[1] = gEngfuncs.pfnRandomFloat( -1, 1 );
	direction[2] = gEngfuncs.pfnRandomFloat( 0, 1 );
}

void EV_TFC_BloodDecalTrace( pmtrace_t *pTrace, int bloodColor )
{
	char decalname[ 32 ];
	int idx = gEngfuncs.pfnRandomLong( 0, 5 );

	if ( !EV_TFC_ShouldShowBlood( bloodColor ) )
		return;

	if ( bloodColor == BLOOD_COLOR_RED )
		sprintf( decalname, "{blood%i", idx + 1 );
	else
		sprintf( decalname, "{yblood%i", idx + 1 );

	EV_TFC_DecalTrace( pTrace, decalname );
}

void EV_TFC_TraceBleed( float flDamage, float *vecDir, pmtrace_t *ptr, int bitsDamageType, int bloodcolor )
{
	if ( flDamage == 0 )
		return;

	if ( bloodcolor == DONT_BLEED )
		return;

	if ( !( bitsDamageType & ( DMG_CRUSH | DMG_BULLET | DMG_SLASH | DMG_BLAST | DMG_CLUB | DMG_MORTAR ) ) )
		return;

	// make blood decal on the wall!
	pmtrace_t Bloodtr;
	vec3_t vecTraceDir, vecEnd;
	float flNoise;
	int cCount;
	int i;

	if ( flDamage < 10 )
	{
		flNoise = 0.1;
		cCount = 1;
	}
	else if ( flDamage < 25 )
	{
		flNoise = 0.2;
		cCount = 2;
	}
	else
	{
		flNoise = 0.3;
		cCount = 4;
	}

	for ( i = 0; i < cCount; i++ )
	{
		VectorScale( vecDir, -1, vecTraceDir );// trace in the opposite direction the shot came from (the direction the shot is going)

		vecTraceDir[0] += gEngfuncs.pfnRandomFloat( -flNoise, flNoise );
		vecTraceDir[1] += gEngfuncs.pfnRandomFloat( -flNoise, flNoise );
		vecTraceDir[2] += gEngfuncs.pfnRandomFloat( -flNoise, flNoise );

		VectorMA( ptr->endpos, -172, vecTraceDir, vecEnd );

		gEngfuncs.pEventAPI->EV_PlayerTrace( ptr->endpos, vecEnd, PM_STUDIO_BOX, -1, &Bloodtr );

		if ( Bloodtr.fraction != 1.0 )
		{
			EV_TFC_BloodDecalTrace( &Bloodtr, bloodcolor );
		}
	}
}

void EV_TFC_SpawnBlood( float *vecSpot, int bloodColor, float flDamage )
{
	EV_TFC_BloodDrips( vecSpot, bloodColor, (int)flDamage );
}

int EV_TFC_GetTeamIndex( int idx )
{
	if ( idx >= 1 && idx <= gEngfuncs.GetMaxClients() )
	{
		cl_entity_t *ent = GetEntity( idx );
		if ( ent )
			return ent->curstate.team;
	}

	return -1;
}

int EV_TFC_IsAllyTeam( int iTeam1, int iTeam2 )
{
	// "ta" holds each team's allies, 5 bits per team
	int iAllies = atoi( gEngfuncs.PhysInfo_ValueForKey( "ta" ) );
	int teamallies[ 5 ];

	teamallies[ 0 ] = iAllies & 0x1f;
	teamallies[ 1 ] = ( iAllies >> 5 ) & 0x1f;
	teamallies[ 2 ] = ( iAllies >> 10 ) & 0x1f;
	teamallies[ 3 ] = ( iAllies >> 15 ) & 0x1f;
	teamallies[ 4 ] = ( iAllies >> 20 ) & 0x1f;

	return ( iTeam1 == iTeam2 ) | ( ( teamallies[ iTeam1 ] >> ( iTeam2 - 1 ) ) & 1 );
}

int EV_TFC_IsAlly( int idx1, int idx2 )
{
	int iTeam1 = EV_TFC_GetTeamIndex( idx1 );
	int iTeam2 = EV_TFC_GetTeamIndex( idx2 );

	if ( iTeam1 < 1 || iTeam2 < 1 )
		return 0;

	if ( !gEngfuncs.GetLocalPlayer() )
		return 0;

	if ( iTeam1 > 4 || iTeam2 > 4 )
		return 0;

	return EV_TFC_IsAllyTeam( iTeam1, iTeam2 );
}

void EV_TFC_TraceAttack( int idx, float flDamage, float *vecDir, pmtrace_t *ptr, int bitsDamageType )
{
	vec3_t vecOrigin, vecScaled;

	if ( cl_localblood && !cl_localblood->value )
		return;

	VectorScale( vecDir, -4, vecScaled );
	VectorSubtract( ptr->endpos, vecScaled, vecOrigin );

	int iHit = gEngfuncs.pEventAPI->EV_IndexFromTrace( ptr );
	if ( iHit >= 1 && iHit <= gEngfuncs.GetMaxClients() )
	{
		int iHitTeam = EV_TFC_GetTeamIndex( iHit );

		// teammates don't bleed
		if ( EV_TFC_GetTeamIndex( idx ) != iHitTeam )
			EV_TFC_SpawnBlood( vecOrigin, BLOOD_COLOR_RED, flDamage );
	}
}

/*
================
EV_TFC_FireBullets

Go to the trouble of combining multiple pellets into a single damage call.
================
*/
void EV_TFC_FireBullets( int idx, float *forward, float *right, float *up, int cShots, float *vecSrc, float *vecDirShooting, float *vecSpread, float flDistance, int iBulletType, int iTracerFreq, int *tracerCount, int iDamage )
{
	int i;
	pmtrace_t tr;
	int iShot;
	int tracer;
	int iShotsHit = 0;

	for ( iShot = 1; iShot <= cShots; iShot++ )
	{
		vec3_t vecDir, vecEnd;
		float x, y, z;

		do {
			x = gEngfuncs.pfnRandomFloat( -0.5, 0.5 ) + gEngfuncs.pfnRandomFloat( -0.5, 0.5 );
			y = gEngfuncs.pfnRandomFloat( -0.5, 0.5 ) + gEngfuncs.pfnRandomFloat( -0.5, 0.5 );
			z = x * x + y * y;
		} while ( z > 1 );

		for ( i = 0; i < 3; i++ )
		{
			vecDir[i] = vecDirShooting[i] + x * vecSpread[0] * right[ i ] + y * vecSpread[1] * up[ i ];
			vecEnd[i] = vecSrc[ i ] + flDistance * vecDir[ i ];
		}

		gEngfuncs.pEventAPI->EV_SetUpPlayerPrediction( false, true );

		// Store off the old count
		gEngfuncs.pEventAPI->EV_PushPMStates();

		// Now add in all of the players.
		gEngfuncs.pEventAPI->EV_SetSolidPlayers ( idx - 1 );

		gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
		gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_STUDIO_BOX, -1, &tr );

		tracer = EV_TFC_CheckTracer( idx, vecSrc, tr.endpos, forward, right, iBulletType, iTracerFreq, tracerCount );

		// do damage, paint decals
		if ( tr.fraction != 1.0 )
		{
			if ( !iDamage )
			{
				switch ( iBulletType )
				{
				default:
				case BULLET_PLAYER_MP5:
				case BULLET_PLAYER_357:
					if ( !tracer )
					{
						EV_TFC_PlayTextureSound( idx, &tr, vecSrc, vecEnd, iBulletType );
						EV_TFC_DecalGunshot( &tr, iBulletType );
					}
					break;
				case BULLET_PLAYER_BUCKSHOT:
					if ( !tracer )
					{
						EV_TFC_DecalGunshot( &tr, iBulletType );
					}
					break;
				}
			}
			else if ( cShots == 1 )
			{
				EV_TFC_TraceAttack( idx, iDamage, vecDir, &tr, DMG_BULLET );
				EV_TFC_PlayTextureSound( idx, &tr, vecSrc, vecEnd, iBulletType );
				EV_TFC_DecalGunshot( &tr, iBulletType );
				gEngfuncs.pEventAPI->EV_PopPMStates();
				break;
			}
			else
			{
				// pellets: blood now, one combined decal pass below
				EV_TFC_TraceAttack( idx, iDamage, vecDir, &tr, DMG_BULLET );
				iShotsHit++;
			}
		}

		gEngfuncs.pEventAPI->EV_PopPMStates();
	}

	if ( iShotsHit )
	{
		int decals[ 5 ];
		char decalname[ 32 ];

		for ( i = 0; i < 5; i++ )
		{
			sprintf( decalname, "{shot%i", i + 1 );
			decals[ i ] = gEngfuncs.pEfxAPI->Draw_DecalIndexFromName( decalname );
		}

		vec3_t vecSpread2( vecSpread[0], vecSpread[1], 0.0f );
		gEngfuncs.pEfxAPI->R_MultiGunshot( vecSrc, vecDirShooting, vecSpread2, iShotsHit, 5, decals );
	}
}

//======================
//	   SHOTGUN START
//======================
void EV_FireTFCShotgun( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t velocity;

	vec3_t ShellVelocity;
	vec3_t ShellOrigin;
	int shell;
	vec3_t vecSrc, vecAiming;
	vec3_t up, right, forward;
	float vecSpread[ 3 ];

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );
	VectorCopy( args->velocity, velocity );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	shell = gEngfuncs.pEventAPI->EV_FindModelIndex( "models/shotgunshell.mdl" );// brass shell

	if ( EV_IsLocal( idx ) )
	{
		// Add muzzle flash to current weapon model
		EV_MuzzleFlash();
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 1, 2 );
	}

	EV_GetDefaultShellInfo( args, origin, velocity, ShellVelocity, ShellOrigin, forward, right, up, 20, -12, 4 );

	EV_EjectBrass( ShellOrigin, ShellVelocity, angles[ YAW ], shell, TE_BOUNCE_SHOTSHELL );

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/sbarrel1.wav", gEngfuncs.pfnRandomFloat( 0.95, 1.0 ), ATTN_NORM, 0, 93 + gEngfuncs.pfnRandomLong( 0, 0x1f ) );

	EV_GetGunPosition( args, vecSrc, origin );
	VectorCopy( forward, vecAiming );

	vecSpread[0] = 0.04;
	vecSpread[1] = 0.04;
	vecSpread[2] = 0;

	EV_TFC_FireBullets( idx, forward, right, up, 6, vecSrc, vecAiming, vecSpread, 2048, BULLET_PLAYER_TF_BUCKSHOT, 0, &tracerCount[ idx - 1 ], 4 );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -2.0 );
	}
}

void EV_ReloadTFCShotgun( event_args_t *args )
{
	int idx;
	vec3_t origin;

	idx = args->entindex;
	VectorCopy( args->origin, origin );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 3, 2 );
	}

	if ( gEngfuncs.pfnRandomLong( 0, 1 ) )
		gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/reload1.wav", 1, ATTN_NORM, 0, 85 + gEngfuncs.pfnRandomLong( 0, 0x1f ) );
	else
		gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/reload3.wav", 1, ATTN_NORM, 0, 85 + gEngfuncs.pfnRandomLong( 0, 0x1f ) );
}

void EV_PumpTFCShotgun( event_args_t *args )
{
	int idx;
	vec3_t origin;

	idx = args->entindex;
	VectorCopy( args->origin, origin );

	if ( args->bparam1 && EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 4, 2 );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/scock1.wav", 1, ATTN_NORM, 0, 95 + gEngfuncs.pfnRandomLong( 0, 0x1f ) );
}

//======================
//	   NAILGUN START
//======================
void EV_TFC_NailTouch( struct tempent_s *ent, pmtrace_t *ptr )
{
	physent_t *pe = gEngfuncs.pEventAPI->EV_GetPhysent( ptr->ent );

	if ( pe && ( pe->solid == SOLID_BSP || pe->movetype == MOVETYPE_PUSHSTEP ) )
	{
		char decalname[ 32 ];
		decalname[ 0 ] = 0;
		sprintf( decalname, "{shot%i", gEngfuncs.pfnRandomLong( 0, 4 ) + 1 );
		EV_TFC_GunshotDecalTrace( ptr, decalname );
	}
}

void EV_TFC_TranqNailTouch( struct tempent_s *ent, pmtrace_t *ptr )
{
	char decalname[ 32 ];
	int bHitPlayer = gEngfuncs.pEventAPI->EV_IndexFromTrace( ptr ) > 0 && gEngfuncs.pEventAPI->EV_IndexFromTrace( ptr ) <= gEngfuncs.GetMaxClients();

	decalname[ 0 ] = 0;
	sprintf( decalname, "{shot%i", gEngfuncs.pfnRandomLong( 0, 4 ) + 1 );

	// darts stick in people, not in walls
	if ( bHitPlayer )
		return;

	physent_t *pe = gEngfuncs.pEventAPI->EV_GetPhysent( ptr->ent );
	if ( pe && ( pe->solid == SOLID_BSP || pe->movetype == MOVETYPE_PUSHSTEP ) )
	{
		EV_TFC_GunshotDecalTrace( ptr, decalname );
	}
}

float EV_TFC_WaterLevel( float *position, float minz, float maxz )
{
	vec3_t midUp;
	float diff;

	VectorCopy( position, midUp );
	midUp[2] = minz;

	if ( gEngfuncs.PM_PointContents( midUp, NULL ) != CONTENTS_WATER )
		return minz;

	midUp[2] = maxz;
	if ( gEngfuncs.PM_PointContents( midUp, NULL ) == CONTENTS_WATER )
		return maxz;

	diff = maxz - minz;
	while ( diff > 1.0 )
	{
		midUp[2] = minz + diff / 2.0;
		if ( gEngfuncs.PM_PointContents( midUp, NULL ) == CONTENTS_WATER )
		{
			minz = midUp[2];
		}
		else
		{
			maxz = midUp[2];
		}
		diff = maxz - minz;
	}

	return midUp[2];
}

void EV_TFC_BubbleTrail( float *from, float *to, int count, int modelindex )
{
	float flHeight = EV_TFC_WaterLevel( from, from[2], from[2] + 256 );
	flHeight = flHeight - from[2];

	if ( flHeight < 8 )
	{
		flHeight = EV_TFC_WaterLevel( to, to[2], to[2] + 256 );
		flHeight = flHeight - to[2];
		if ( flHeight < 8 )
			return;

		// UNDONE: do a ploink sound
		flHeight = flHeight + to[2] - from[2];
	}

	if ( count > 255 )
		count = 255;

	gEngfuncs.pEfxAPI->R_BubbleTrail( from, to, flHeight, modelindex, count, 8 );
}

void EV_TFC_ClientProjectile( float *vecOrigin, float *vecVelocity, short sModelIndex, int iOwnerIndex, int iLife, void ( *hitcallback )( struct tempent_s *ent, struct pmtrace_s *ptr ) )
{
	gEngfuncs.pEfxAPI->R_Projectile( vecOrigin, vecVelocity, sModelIndex, iLife, iOwnerIndex, hitcallback );
}

void EV_FireTFCNailgun( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecVelocity;
	short sModelIndex;

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	sModelIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "models/nail.mdl" );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 5, 2 );
	}

	EV_GetGunPosition( args, vecSrc, origin );
	VectorMA( vecSrc, -4, up, vecSrc );
	VectorMA( vecSrc, 2, right, vecSrc );

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/airgun_1.wav", gEngfuncs.pfnRandomFloat( 0.95, 1.0 ), ATTN_NORM, 0, 93 + gEngfuncs.pfnRandomLong( 0, 0x1f ) );

	VectorScale( forward, 1000, vecVelocity );
	EV_TFC_ClientProjectile( vecSrc, vecVelocity, sModelIndex, idx, 6, EV_TFC_NailTouch );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -1.0 );
	}
}

//======================
//	   AUTO RIFLE
//======================
void EV_FireTFCAutoRifle( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecEnd, vecAiming;
	pmtrace_t tr;

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 6, 2 );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/sniper.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );

	EV_GetGunPosition( args, vecSrc, origin );
	VectorCopy( forward, vecAiming );
	VectorMA( vecSrc, 8192, vecAiming, vecEnd );

	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetSolidPlayers( idx - 1 );
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_STUDIO_BOX, -1, &tr );

	if ( tr.fraction != 1.0 )
	{
		EV_TFC_TraceAttack( idx, 8, vecAiming, &tr, DMG_BULLET );
		EV_TFC_PlayTextureSound( idx, &tr, vecSrc, vecEnd, BULLET_PLAYER_357 );
		EV_TFC_DecalGunshot( &tr, BULLET_PLAYER_357 );
	}

	gEngfuncs.pEventAPI->EV_PopPMStates();
}

//======================
//	 SUPER SHOTGUN
//======================
void EV_FireTFCSuperShotgun( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t velocity;

	vec3_t ShellVelocity;
	vec3_t ShellOrigin;
	int shell;
	vec3_t vecSrc, vecAiming;
	vec3_t up, right, forward;
	float vecSpread[ 3 ];

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );
	VectorCopy( args->velocity, velocity );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	shell = gEngfuncs.pEventAPI->EV_FindModelIndex( "models/shotgunshell.mdl" );// brass shell

	if ( EV_IsLocal( idx ) )
	{
		// Add muzzle flash to current weapon model
		EV_MuzzleFlash();
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 1, 2 );
	}

	EV_GetDefaultShellInfo( args, origin, velocity, ShellVelocity, ShellOrigin, forward, right, up, 20, -12, 4 );

	EV_EjectBrass( ShellOrigin, ShellVelocity, angles[ YAW ], shell, TE_BOUNCE_SHOTSHELL );

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/shotgn2.wav", gEngfuncs.pfnRandomFloat( 0.95, 1.0 ), ATTN_NORM, 0, 93 + gEngfuncs.pfnRandomLong( 0, 0x1f ) );

	EV_GetGunPosition( args, vecSrc, origin );
	VectorCopy( forward, vecAiming );

	vecSpread[0] = 0.04;
	vecSpread[1] = 0.04;
	vecSpread[2] = 0;

	EV_TFC_FireBullets( idx, forward, right, up, 14, vecSrc, vecAiming, vecSpread, 2048, BULLET_PLAYER_TF_BUCKSHOT, 4, &tracerCount[ idx - 1 ], 4 );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -4.0 );
	}
}

//======================
//	 SUPER NAILGUN
//======================
void EV_FireTFCSuperNailgun( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecVelocity;
	short sModelIndex;

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	sModelIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "models/nail.mdl" );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 5, 2 );
	}

	EV_GetGunPosition( args, vecSrc, origin );
	VectorMA( vecSrc, -4, up, vecSrc );
	VectorMA( vecSrc, 2, right, vecSrc );

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/spike2.wav", 1.0, ATTN_NORM, 0, 94 + gEngfuncs.pfnRandomLong( 0, 0xf ) );

	VectorScale( forward, 1000, vecVelocity );
	EV_TFC_ClientProjectile( vecSrc, vecVelocity, sModelIndex, idx, 6, EV_TFC_NailTouch );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -1.0 );
	}
}

//======================
//	 ASSAULT CANNON
//======================
void EV_TFC_Assault_WindUp( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	g_flSpinDownTime[ idx - 1 ] = 0.0;
	g_flSpinUpTime[ idx - 1 ] = gEngfuncs.GetClientTime() + 3.5;

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 2, 2 );
	}

	g_bACSpinning[ idx - 1 ] = 0;

	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan2.wav" );
	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan4.wav" );
	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_WEAPON, "weapons/asscan3.wav" );
	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/asscan1.wav", 0.98, ATTN_NORM, 0, 125 );
}

void EV_TFC_Assault_WindDown( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	if ( g_flSpinUpTime[ idx - 1 ] == 0.0 )
	{
		g_flSpinDownTime[ idx - 1 ] = gEngfuncs.GetClientTime() + 3.0;
	}

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 3, 2 );
	}

	g_bACSpinning[ idx - 1 ] = 0;

	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan2.wav" );
	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan4.wav" );
	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_WEAPON, "weapons/asscan1.wav" );

	if ( !args->bparam1 )
		gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/asscan3.wav", 0.98, ATTN_NORM, 0, 125 );
}

void EV_TFC_Assault_Start( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	g_flSpinDownTime[ idx - 1 ] = 0.0;
	g_flSpinUpTime[ idx - 1 ] = 0.0;
	g_bACSpinning[ idx - 1 ] = 0;

	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan2.wav" );
	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan4.wav" );
	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_STATIC, "weapons/asscan2.wav", 0.98, ATTN_NORM, 0, 125 );
}

void EV_TFC_Assault_Fire( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t velocity;
	int bEjectShell;

	vec3_t ShellVelocity;
	vec3_t ShellOrigin;
	int shell;
	vec3_t vecSrc, vecAiming;
	vec3_t up, right, forward;
	float vecSpread[ 3 ];

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );
	VectorCopy( args->velocity, velocity );
	bEjectShell = args->bparam1;

	shell = gEngfuncs.pEventAPI->EV_FindModelIndex( "models/shell.mdl" );// brass shell

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	if ( EV_IsLocal( idx ) )
	{
		// Add muzzle flash to current weapon model
		EV_MuzzleFlash();
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 4, 2 );
	}

	g_bACSpinning[ idx - 1 ] = 0;

	if ( bEjectShell )
	{
		EV_GetDefaultShellInfo( args, origin, velocity, ShellVelocity, ShellOrigin, forward, right, up, 15, -25, 6 );
		EV_EjectBrass( ShellOrigin, ShellVelocity, angles[ YAW ], shell, TE_BOUNCE_SHELL );
	}

	EV_GetGunPosition( args, vecSrc, origin );
	VectorCopy( forward, vecAiming );

	// from the barrel
	vecSrc = vecSrc + right * 2 + up * -4;

	vecSpread[0] = 0.1;
	vecSpread[1] = 0.1;
	vecSpread[2] = 0;

	EV_TFC_FireBullets( idx, forward, right, up, 5, vecSrc, vecAiming, vecSpread, 8192, BULLET_PLAYER_TF_ASSAULT, 8, &tracerCount[ idx - 1 ], 8 );
}

void EV_TFC_Assault_StartSpin( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	g_bACSpinning[ idx - 1 ] = 1;

	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan2.wav" );
	gEngfuncs.pEventAPI->EV_StopSound( idx, CHAN_STATIC, "weapons/asscan4.wav" );
	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_STATIC, "weapons/asscan4.wav", 0.98, ATTN_NORM, 0, 125 );
}

void EV_TFC_Assault_Spin( event_args_t *args )
{
	int idx = args->entindex;

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 4, 2 );
	}

	g_bACSpinning[ idx - 1 ] = 1;
}

//======================
//	   FLAMETHROWER
//======================
void EV_TFC_Flame_Fire( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecEnd, vecVelocity;
	int bUnderwater;
	short sFlameIndex, sBubbleIndex;

	bUnderwater = args->bparam1;
	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	sFlameIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/fthrow.spr" );
	sBubbleIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/bubble.spr" );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 5, 2 );
	}

	EV_GetGunPosition( args, vecSrc, origin );
	VectorMA( vecSrc, -8, up, vecSrc );
	VectorMA( vecSrc, 8, right, vecSrc );
	VectorMA( vecSrc, 16, forward, vecSrc );

	if ( !bUnderwater )
	{
		VectorScale( forward, 600, vecVelocity );
		EV_TFC_ClientProjectile( vecSrc, vecVelocity, sFlameIndex, idx, 1, NULL );
		gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/flmfire2.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );
	}
	else
	{
		// under water it just makes bubbles
		VectorMA( vecSrc, 128, forward, vecEnd );
		EV_TFC_BubbleTrail( vecSrc, vecEnd, 4, sBubbleIndex );
	}
}

//======================
//	   KNIFE
//======================
void EV_TFC_Knife( event_args_t *args )
{
}

//======================
//	   TRANQUILISER
//======================
void EV_TFC_Tranquilizer( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecVelocity;
	short sModelIndex;

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	sModelIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "models/nail.mdl" );

	if ( EV_IsLocal( idx ) )
	{
		EV_MuzzleFlash();
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 3, 1 );
	}

	EV_GetGunPosition( args, vecSrc, origin );
	VectorMA( vecSrc, -4, up, vecSrc );
	VectorMA( vecSrc, 2, right, vecSrc );

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/dartgun.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );

	VectorScale( forward, 1500, vecVelocity );
	EV_TFC_ClientProjectile( vecSrc, vecVelocity, sModelIndex, idx, 6, EV_TFC_TranqNailTouch );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -2.0 );
	}
}

//======================
//	   RAILGUN
//======================
void EV_TFC_RailDie( struct particle_s *particle )
{
	vec3_t vecDir, vecBack, vecSrc, vecEnd;
	pmtrace_t tr;
	int idx;

	if ( !particle )
		return;

	VectorCopy( particle->vel, vecDir );
	idx = particle->context;

	VectorNormalize( vecDir );
	VectorCopy( vecDir, vecBack );
	VectorInverse( vecBack );

	// trace back along the flight path to find what the nail hit
	VectorMA( particle->org, 128, vecBack, vecSrc );
	VectorMA( vecSrc, 256, vecDir, vecEnd );

	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetSolidPlayers( idx - 1 );
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_STUDIO_BOX, -1, &tr );

	if ( tr.ent != -1 )
	{
		physent_t *pe = gEngfuncs.pEventAPI->EV_GetPhysent( tr.ent );

		if ( EV_IsPlayer( gEngfuncs.pEventAPI->EV_IndexFromTrace( &tr ) ) && !EV_TFC_IsAlly( gEngfuncs.pEventAPI->EV_IndexFromTrace( &tr ), idx ) )
		{
			if ( cl_localblood && cl_localblood->value )
				EV_TFC_SpawnBlood( tr.endpos, BLOOD_COLOR_RED, 25 );
		}
		else if ( pe && ( pe->solid == SOLID_BSP || pe->movetype == MOVETYPE_PUSHSTEP ) )
		{
			char decalname[ 32 ];
			decalname[ 0 ] = 0;
			sprintf( decalname, "{shot%i", gEngfuncs.pfnRandomLong( 0, 4 ) + 1 );
			EV_TFC_GunshotDecalTrace( &tr, decalname );
		}
	}

	gEngfuncs.pEventAPI->EV_PopPMStates();
}

void EV_TFC_Railgun( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecStart, vecEnd, vecDelta, vecVelocity;
	pmtrace_t tr;

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	gEngfuncs.pEventAPI->EV_FindModelIndex( "models/nail.mdl" );

	if ( EV_IsLocal( idx ) )
	{
		EV_MuzzleFlash();
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 1, 2 );
	}

	EV_GetGunPosition( args, vecSrc, origin );
	VectorMA( vecSrc, -4, up, vecSrc );
	VectorMA( vecSrc, 2, right, vecSrc );

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/railgun.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );

	VectorCopy( vecSrc, vecStart );
	VectorMA( vecStart, 4096, forward, vecEnd );

	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetSolidPlayers( idx - 1 );
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecStart, vecEnd, PM_STUDIO_BOX, -1, &tr );

	// a tracer that lives as long as the nail takes to get there
	VectorSubtract( tr.endpos, vecStart, vecDelta );
	float flDist = Length( vecDelta );
	VectorScale( forward, 1500, vecVelocity );
	gEngfuncs.pEfxAPI->R_UserTracerParticle( vecSrc, vecVelocity, flDist / 1500.0, 2, 1.0, idx, EV_TFC_RailDie );

	gEngfuncs.pEventAPI->EV_PopPMStates();

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -2.0 );
	}
}

//======================
//	   DOORS
//======================
#define DOOR_SOUND_MOVE		0
#define DOOR_SOUND_STOP		1

char *EV_TFC_LookupDoorSound( int type, int index )
{
	static char sound[ 32 ];

	strcpy( sound, "common/null.wav" );

	// movement sound in the high byte, stop sound in the low one
	if ( type == DOOR_SOUND_MOVE )
	{
		switch ( ( index >> 8 ) & 0xff )
		{
		default:
		case 0:	strcpy( sound, "common/null.wav" ); break;
		case 1:	strcpy( sound, "doors/doormove1.wav" ); break;
		case 2:	strcpy( sound, "doors/doormove2.wav" ); break;
		case 3:	strcpy( sound, "doors/doormove3.wav" ); break;
		case 4:	strcpy( sound, "doors/doormove4.wav" ); break;
		case 5:	strcpy( sound, "doors/doormove5.wav" ); break;
		case 6:	strcpy( sound, "doors/doormove6.wav" ); break;
		case 7:	strcpy( sound, "doors/doormove7.wav" ); break;
		case 8:	strcpy( sound, "doors/doormove8.wav" ); break;
		case 9:	strcpy( sound, "doors/doormove9.wav" ); break;
		case 10: strcpy( sound, "doors/doormove10.wav" ); break;
		}
	}
	else if ( type == DOOR_SOUND_STOP )
	{
		switch ( index & 0xff )
		{
		default:
		case 0:	strcpy( sound, "common/null.wav" ); break;
		case 1:	strcpy( sound, "doors/doorstop1.wav" ); break;
		case 2:	strcpy( sound, "doors/doorstop2.wav" ); break;
		case 3:	strcpy( sound, "doors/doorstop3.wav" ); break;
		case 4:	strcpy( sound, "doors/doorstop4.wav" ); break;
		case 5:	strcpy( sound, "doors/doorstop5.wav" ); break;
		case 6:	strcpy( sound, "doors/doorstop6.wav" ); break;
		case 7:	strcpy( sound, "doors/doorstop7.wav" ); break;
		case 8:	strcpy( sound, "doors/doorstop8.wav" ); break;
		}
	}

	return sound;
}

void EV_TFC_DoorGoUp( event_args_t *args )
{
	gEngfuncs.pEventAPI->EV_StopSound( -1, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_MOVE, args->iparam1 ) );
	gEngfuncs.pEventAPI->EV_PlaySound( -1, args->origin, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_MOVE, args->iparam1 ), 1.0, ATTN_NORM, 0, PITCH_NORM );
}

void EV_TFC_DoorGoDown( event_args_t *args )
{
	gEngfuncs.pEventAPI->EV_StopSound( -1, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_MOVE, args->iparam1 ) );
	gEngfuncs.pEventAPI->EV_PlaySound( -1, args->origin, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_MOVE, args->iparam1 ), 1.0, ATTN_NORM, 0, PITCH_NORM );
}

void EV_TFC_DoorHitTop( event_args_t *args )
{
	gEngfuncs.pEventAPI->EV_StopSound( -1, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_MOVE, args->iparam1 ) );
	gEngfuncs.pEventAPI->EV_PlaySound( -1, args->origin, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_STOP, args->iparam1 ), 1.0, ATTN_NORM, 0, PITCH_NORM );
}

void EV_TFC_DoorHitBottom( event_args_t *args )
{
	gEngfuncs.pEventAPI->EV_StopSound( -1, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_MOVE, args->iparam1 ) );
	gEngfuncs.pEventAPI->EV_PlaySound( -1, args->origin, CHAN_STATIC, EV_TFC_LookupDoorSound( DOOR_SOUND_STOP, args->iparam1 ), 1.0, ATTN_NORM, 0, PITCH_NORM );
}

//======================
//	   EXPLOSIONS
//======================
void EV_TFC_Explode( float *org, int dmg, float fExplosionScale, qboolean bDontSpark, pmtrace_t *pTrace, int bitsDamageType )
{
	vec3_t vecSpot;
	int iContents;
	qboolean bInSolid = false;

	VectorCopy( org, vecSpot );

	// Pull out of the wall a bit
	if ( pTrace->fraction != 1.0 )
	{
		int iPull = dmg;
		if ( dmg >= 24 )
			iPull = dmg - 24;

		VectorMA( pTrace->endpos, iPull * 0.6, pTrace->plane.normal, vecSpot );
	}

	iContents = gEngfuncs.PM_PointContents( vecSpot, NULL );
	if ( iContents == CONTENTS_SOLID )
	{
		iContents = gEngfuncs.PM_PointContents( org, NULL );
		bInSolid = ( iContents == CONTENTS_SOLID );
	}

	if ( fExplosionScale == 0 )
		fExplosionScale = ( dmg - 50 ) * 0.6;

	gEngfuncs.pEfxAPI->R_Explosion( vecSpot, gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/explode01.spr" ), fExplosionScale * 0.1, 15, TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );

	if ( !bInSolid )
	{
		if ( gEngfuncs.pfnRandomFloat( 0, 1 ) < 0.5 )
			EV_TFC_DecalTrace( pTrace, "{scorch1" );
		else
			EV_TFC_DecalTrace( pTrace, "{scorch2" );
	}

	gEngfuncs.pfnRandomFloat( 0, 1 );
	switch ( gEngfuncs.pfnRandomLong( 0, 2 ) )
	{
	case 0:	gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSpot, CHAN_VOICE, "weapons/debris1.wav", 0.55, ATTN_NORM, 0, PITCH_NORM ); break;
	case 1:	gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSpot, CHAN_VOICE, "weapons/debris2.wav", 0.55, ATTN_NORM, 0, PITCH_NORM ); break;
	case 2:	gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSpot, CHAN_VOICE, "weapons/debris3.wav", 0.55, ATTN_NORM, 0, PITCH_NORM ); break;
	}

	if ( iContents != CONTENTS_WATER && !bDontSpark )
	{
		int sparkCount = gEngfuncs.pfnRandomLong( 0, 3 );
		for ( int i = 0; i < sparkCount; i++ )
			gEngfuncs.pEfxAPI->R_SparkShower( vecSpot );
	}
}

// trace down a bit under the explosion for the scorch mark
static void EV_TFC_TraceDown( float *origin, pmtrace_t *tr )
{
	vec3_t vecSrc, vecEnd;

	vecSrc = Vector( origin ) + Vector( 0, 0, 8 );
	vecEnd = vecSrc + Vector( 0, 0, -40 );

	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_STUDIO_BOX, -1, tr );
	gEngfuncs.pEventAPI->EV_PopPMStates();
}

void EV_TFC_Explosion( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_Explode( origin, 120, 0, true, &tr, DMG_BLAST | DMG_IGNOREARMOR );
}

void EV_TFC_Grenade( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_Explode( origin, 120, 0, true, &tr, DMG_BLAST );
}

void EV_TFC_EngineerGrenade( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_Explode( origin, 180, 78, true, &tr, DMG_BLAST );
}

void EV_TFC_Concussion( event_args_t *args )
{
	vec3_t origin, vecStart, vecEnd;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	int iShockwave = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/shockwave.spr" );
	EV_TFC_TraceDown( origin, &tr );

	switch ( gEngfuncs.pfnRandomLong( 0, 2 ) )
	{
	case 0:	gEngfuncs.pEventAPI->EV_PlaySound( -1, origin, CHAN_VOICE, "weapons/concgren_blast1.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
	case 1:	gEngfuncs.pEventAPI->EV_PlaySound( -1, origin, CHAN_VOICE, "weapons/concgren_blast2.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
	case 2:	gEngfuncs.pEventAPI->EV_PlaySound( -1, origin, CHAN_VOICE, "weapons/concgren_blast3.wav", 1.0, ATTN_NORM, 0, PITCH_NORM ); break;
	}

	// white ring
	vecStart = Vector( origin[0], origin[1], origin[2] + 16 );
	vecEnd = Vector( vecStart[0], vecStart[1], vecStart[2] + 600 );
	gEngfuncs.pEfxAPI->R_BeamCirclePoints( TE_BEAMCYLINDER, vecStart, vecEnd, iShockwave, 0.2, 70, 0, 1.0, 0, 0, 0, 1.0, 1.0, 1.0 );
}

void EV_TFC_NormalGrenade( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_Explode( origin, 180, 0, true, &tr, DMG_BLAST );
}

void EV_TFC_MirvGrenadeMain( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_Explode( origin, 180, 0, true, &tr, DMG_BLAST );
}

void EV_TFC_MirvGrenade( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_Explode( origin, 180, 0, true, &tr, DMG_BLAST );
}

void EV_TFC_ExplodeFire( float *org, int dmg, qboolean bDontSpark, pmtrace_t *pTrace, int bitsDamageType )
{
	vec3_t vecSpot;
	int iContents;

	VectorCopy( org, vecSpot );

	// Pull out of the wall a bit
	if ( pTrace->fraction != 1.0 )
	{
		if ( dmg >= 24 )
			dmg -= 24;

		VectorMA( pTrace->endpos, dmg * 0.6, pTrace->plane.normal, vecSpot );
	}

	iContents = gEngfuncs.PM_PointContents( vecSpot, NULL );
	if ( iContents == CONTENTS_SOLID )
	{
		iContents = gEngfuncs.PM_PointContents( org, NULL );
		if ( iContents == CONTENTS_SOLID )
			return;
	}

	gEngfuncs.pEfxAPI->R_Explosion( vecSpot, gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/explode01.spr" ), 3.0, 15, TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );

	if ( gEngfuncs.pfnRandomFloat( 0, 1 ) < 0.5 )
		EV_TFC_DecalTrace( pTrace, "{scorch1" );
	else
		EV_TFC_DecalTrace( pTrace, "{scorch2" );

	gEngfuncs.pfnRandomFloat( 0, 1 );
	switch ( gEngfuncs.pfnRandomLong( 0, 2 ) )
	{
	case 0:	gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSpot, CHAN_VOICE, "weapons/debris1.wav", 0.55, ATTN_NORM, 0, PITCH_NORM ); break;
	case 1:	gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSpot, CHAN_VOICE, "weapons/debris2.wav", 0.55, ATTN_NORM, 0, PITCH_NORM ); break;
	case 2:	gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSpot, CHAN_VOICE, "weapons/debris3.wav", 0.55, ATTN_NORM, 0, PITCH_NORM ); break;
	}

	if ( iContents != CONTENTS_WATER && !bDontSpark )
	{
		int sparkCount = gEngfuncs.pfnRandomLong( 0, 3 );
		for ( int i = 0; i < sparkCount; i++ )
			gEngfuncs.pEfxAPI->R_SparkShower( vecSpot );
	}
}

void EV_TFC_NapalmFire( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_ExplodeFire( origin, 20, true, &tr, DMG_BLAST | DMG_IGNOREARMOR );
}

void EV_TFC_NapalmBurn( event_args_t *args )
{
	vec3_t origin;
	VectorCopy( args->origin, origin );

	int iFlame = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/playerflame.spr" );
	gEngfuncs.pEfxAPI->R_FireField( origin, 100, iFlame, 12, TEFIRE_FLAG_ALLFLOAT | TEFIRE_FLAG_ALPHA, 0.8 );
}

void EV_TFC_Gas( event_args_t *args )
{
	vec3_t origin;
	VectorCopy( args->origin, origin );

	gEngfuncs.pEfxAPI->R_ParticleBurst( origin, 240, 195, 2.0 );
}

void EV_TFC_EMP( event_args_t *args )
{
	vec3_t origin, vecStart, vecEnd;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	int iShockwave = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/shockwave.spr" );
	EV_TFC_TraceDown( origin, &tr );

	gEngfuncs.pEventAPI->EV_PlaySound( -1, origin, CHAN_VOICE, "weapons/emp_1.wav", 1.0, ATTN_NORM, 0, PITCH_NORM );

	// yellow ring
	vecStart = Vector( origin[0], origin[1], origin[2] + 16 );
	vecEnd = Vector( vecStart[0], vecStart[1], vecStart[2] + 600 );
	gEngfuncs.pEfxAPI->R_BeamCirclePoints( TE_BEAMCYLINDER, vecStart, vecEnd, iShockwave, 0.2, 70, 0, 1.0, 0, 0, 0, 1.0, 1.0, 0.0 );
}

void EV_TFC_NailgrenadeNail( event_args_t *args )
{
	vec3_t origin, angles, forward, vecSrc, vecVelocity;
	float flStep = args->fparam1;
	int iParam = args->iparam1;

	VectorCopy( args->origin, origin );

	// the grenade's yaw in 1/4 degrees, and its owner, packed into iparam1
	angles[0] = 0;
	angles[1] = ( iParam & 0x7ff ) * 0.25;
	angles[2] = 0;

	short sModelIndex = gEngfuncs.pEventAPI->EV_FindModelIndex( "models/nail.mdl" );

	for ( int i = 0; i < 4; i++ )
	{
		angles[1] = anglemod( flStep + angles[1] );
		gEngfuncs.pfnAngleVectors( angles, forward, NULL, NULL );

		VectorMA( origin, 12, forward, vecSrc );
		VectorScale( forward, 1000, vecVelocity );

		EV_TFC_ClientProjectile( vecSrc, vecVelocity, sModelIndex, ( iParam >> 11 ) & 0x1f, 6, EV_TFC_NailTouch );

		if ( gEngfuncs.pfnRandomLong( 0, 5 ) == 0 )
		{
			if ( gEngfuncs.pfnRandomLong( 0, 1 ) == 0 )
				gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSrc, CHAN_WEAPON, "weapons/airgun_1.wav", 1.0, ATTN_NORM, 0, 94 + gEngfuncs.pfnRandomLong( 0, 0xf ) );
			else
				gEngfuncs.pEventAPI->EV_PlaySound( -1, vecSrc, CHAN_WEAPON, "weapons/spike2.wav", 1.0, ATTN_NORM, 0, 94 + gEngfuncs.pfnRandomLong( 0, 0xf ) );
		}
	}
}

void EV_TFC_NailGrenade( event_args_t *args )
{
	vec3_t origin;
	pmtrace_t tr;

	VectorCopy( args->origin, origin );
	EV_TFC_TraceDown( origin, &tr );
	EV_TFC_Explode( origin, 180, 78, true, &tr, DMG_BLAST );
}

//======================
//	   ROCKETS
//======================
void EV_TFC_FireRPG( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 2, 2 );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/rocketfire1.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );
	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/glauncher.wav", 0.7, ATTN_NORM, 0, PITCH_NORM );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -5.0 );
	}
}

void EV_TFC_FireIC( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 3, 2 );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/sgun1.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -5.0 );
	}
}

//======================
//	   SNIPER RIFLE
//======================
void EV_TFC_SniperHit( event_args_s *args )
{
	vec3_t origin;
	char sz[ 256 ];

	VectorCopy( args->origin, origin );
	int idx = args->entindex;
	float flVolume = (float)args->iparam1 / 100.0;

	if ( args->bparam2 )
	{
		// head shot
		strcpy( sz, "common/bodysplat.wav" );
		flVolume = 1.0;
	}
	else if ( args->bparam1 )
	{
		strcpy( sz, "weapons/bullet_hit2.wav" );
	}
	else
	{
		strcpy( sz, "weapons/ric3.wav" );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_STATIC, sz, flVolume, ATTN_NORM, 0, PITCH_NORM );
}

void EV_FireTFCSniper( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecEnd, vecAiming;
	pmtrace_t tr;
	int iDamage;

	iDamage = args->iparam1;
	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 2, 2 );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "ambience/rifle1.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );

	EV_GetGunPosition( args, vecSrc, origin );
	VectorCopy( forward, vecAiming );
	VectorMA( vecSrc, 2, up, vecSrc );
	VectorMA( vecSrc, 8192, vecAiming, vecEnd );

	gEngfuncs.pEventAPI->EV_SetUpPlayerPrediction( false, true );
	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetSolidPlayers( idx - 1 );
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_STUDIO_BOX, -1, &tr );
	gEngfuncs.pEventAPI->EV_PopPMStates();

	if ( tr.fraction != 1.0 )
	{
		if ( EV_IsPlayer( gEngfuncs.pEventAPI->EV_IndexFromTrace( &tr ) ) )
			EV_TFC_TraceAttack( idx, iDamage, vecAiming, &tr, DMG_BULLET );

		EV_TFC_PlayTextureSound( idx, &tr, vecSrc, vecEnd, BULLET_PLAYER_357 );
		EV_TFC_DecalGunshot( &tr, BULLET_PLAYER_357 );
	}
}

//======================
//	   LAUNCHERS
//======================
void EV_TFC_GrenadeLauncher( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 2, 2 );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/glauncher.wav", 0.7, ATTN_NORM, 0, PITCH_NORM );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -2.0 );
	}
}

void EV_TFC_PipeLauncher( event_args_t *args )
{
	int idx = args->entindex;
	vec3_t origin;
	VectorCopy( args->origin, origin );

	if ( EV_IsLocal( idx ) )
	{
		gEngfuncs.pEventAPI->EV_WeaponAnimation( 3, 2 );
	}

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/glauncher.wav", 0.7, ATTN_NORM, 0, PITCH_NORM );

	if ( EV_IsLocal( idx ) )
	{
		V_PunchAxis( 0, -2.0 );
	}
}

//======================
//	   MELEE
//======================
#define AXE_ANIM_MISS		0
#define AXE_ANIM_HIT		1

#define AXE_SOUND_MISS		0
#define AXE_SOUND_HITBODY	1
#define AXE_SOUND_HITWALL	2

// classid sent with the axe event
#define AXE_CLASS_KNIFE		0
#define AXE_CLASS_SPANNER	1
#define AXE_CLASS_MEDIKIT	2
#define AXE_CLASS_CROWBAR	3

static pmtrace_t g_tr_decal[ 32 ];
static pmtrace_t *gp_tr_decal[ 32 ];

int EV_TFC_PlayKnifeAnim( int iAnimType )
{
	switch ( iAnimType )
	{
	case AXE_ANIM_MISS:
	case AXE_ANIM_HIT:
		return 2;
	}
	return -1;
}

int EV_TFC_PlayMedkitAnim( int iAnimType )
{
	switch ( iAnimType )
	{
	case AXE_ANIM_MISS:	return 2;
	case AXE_ANIM_HIT:	return 3;
	}
	return -1;
}

int EV_TFC_PlaySpannerAnim( int iAnimType )
{
	switch ( iAnimType )
	{
	case AXE_ANIM_MISS:	return 1;
	case AXE_ANIM_HIT:	return 3;
	}
	return -1;
}

int EV_TFC_PlayCrowbarAnim( int iAnimType )
{
	static int m_iSwing;

	switch ( iAnimType )
	{
	case AXE_ANIM_MISS:
		switch ( ( m_iSwing++ ) % 3 )
		{
		case 0:	return 4;
		case 1:	return 5;
		case 2:	return 7;
		}
		break;
	case AXE_ANIM_HIT:
		switch ( ( m_iSwing++ ) % 2 )
		{
		case 0:	return 6;
		case 1:	return 8;
		default: return 3;
		}
		break;
	}
	return -1;
}

void EV_TFC_PlayAxeAnim( int idx, int classid, int iAnimType )
{
	int iAnim = -1;

	if ( !EV_IsLocal( idx ) )
		return;

	switch ( classid )
	{
	case AXE_CLASS_KNIFE:	iAnim = EV_TFC_PlayKnifeAnim( iAnimType ); break;
	case AXE_CLASS_SPANNER:	iAnim = EV_TFC_PlaySpannerAnim( iAnimType ); break;
	case AXE_CLASS_MEDIKIT:	iAnim = EV_TFC_PlayMedkitAnim( iAnimType ); break;
	case AXE_CLASS_CROWBAR:	iAnim = EV_TFC_PlayCrowbarAnim( iAnimType ); break;
	}

	if ( iAnim == -1 )
		return;

	if ( EV_IsLocal( idx ) )
		gEngfuncs.pEventAPI->EV_WeaponAnimation( iAnim, 2 );
}

void EV_TFC_PlayAxeSound( int idx, int classid, float *origin, int iSoundType, float fSoundData )
{
	// the medikit is silent
	if ( classid == AXE_CLASS_MEDIKIT )
		return;

	switch ( iSoundType )
	{
	case AXE_SOUND_MISS:
		gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/cbar_miss1.wav", 1, ATTN_NORM, 0, 94 + gEngfuncs.pfnRandomLong( 0, 0xF ) );
		break;
	case AXE_SOUND_HITBODY:
		switch ( gEngfuncs.pfnRandomLong( 0, 2 ) )
		{
		case 0:	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/cbar_hitbod1.wav", 1, ATTN_NORM, 0, PITCH_NORM ); break;
		case 1:	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/cbar_hitbod2.wav", 1, ATTN_NORM, 0, PITCH_NORM ); break;
		case 2:	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "weapons/cbar_hitbod3.wav", 1, ATTN_NORM, 0, PITCH_NORM ); break;
		}
		break;
	case AXE_SOUND_HITWALL:
		switch ( gEngfuncs.pfnRandomLong( 0, 1 ) )
		{
		case 0:	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/cbar_hit1.wav", fSoundData, ATTN_NORM, 0, 98 + gEngfuncs.pfnRandomLong( 0, 3 ) ); break;
		case 1:	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_ITEM, "weapons/cbar_hit2.wav", fSoundData, ATTN_NORM, 0, 98 + gEngfuncs.pfnRandomLong( 0, 3 ) ); break;
		}
		break;
	}
}

int EV_TFC_AxeHit( int idx, float *origin, float *forward, float *right, int entity, float *vecDir, pmtrace_t *ptr )
{
	cl_entity_t *ent;

	if ( entity >= 1 && entity <= gEngfuncs.GetMaxClients() && ( ent = GetEntity( entity - 1 ) ) != NULL && ent->curstate.playerclass == PC_SPY )
	{
		vec3_t vecForward, vecRight, vecUp;
		int iAnim;

		// from behind?
		gEngfuncs.pfnAngleVectors( ent->curstate.angles, vecForward, vecRight, vecUp );
		if ( vecUp[0] * forward[1] - forward[0] * vecUp[1] <= 0 )
		{
			iAnim = 2;
			EV_TFC_TraceAttack( idx, 40, vecDir, ptr, DMG_CLUB );
		}
		else
		{
			iAnim = 3;
			EV_TFC_TraceAttack( idx, 120, vecDir, ptr, DMG_CLUB );
		}

		if ( EV_IsLocal( idx ) )
			gEngfuncs.pEventAPI->EV_WeaponAnimation( iAnim, 2 );
	}
	else
	{
		EV_TFC_TraceAttack( idx, 20, vecDir, ptr, DMG_CLUB );
	}

	return 1;
}

int EV_TFC_Spanner( int idx, float *origin, float *forward, float *right, int entity, float *vecDir, pmtrace_t *ptr )
{
	// no harm to teammates
	if ( EV_TFC_IsAlly( idx, entity ) )
		return 1;

	EV_TFC_TraceAttack( idx, 20, vecDir, ptr, DMG_CLUB );
	return 1;
}

int EV_TFC_Medkit( int idx, float *origin, float *forward, float *right, int entity, float *vecDir, pmtrace_t *ptr )
{
	if ( entity >= 1 && entity <= gEngfuncs.GetMaxClients() )
	{
		cl_entity_t *ent = GetEntity( entity - 1 );

		// enemies get infected
		if ( !EV_TFC_IsAlly( idx, entity ) )
		{
			EV_TFC_TraceAttack( idx, 10, vecDir, ptr, DMG_CLUB );

			if ( ent->curstate.playerclass != PC_MEDIC )
				gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_VOICE, "player/death2.wav", 1, ATTN_NORM, 0, PITCH_NORM );
		}
		return 1;
	}
	return 0;
}

void EV_TFC_Axe( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecEnd;
	pmtrace_t tr, tr2;
	int classid;
	int entity;
	int bHit;

	classid = args->iparam1;
	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	EV_GetGunPosition( args, vecSrc, origin );
	VectorMA( vecSrc, 32, forward, vecEnd );

	gEngfuncs.pEventAPI->EV_SetUpPlayerPrediction( false, true );
	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetSolidPlayers( idx - 1 );
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_NORMAL, -1, &tr );

	if ( tr.fraction >= 1.0 )
	{
		// try a fatter trace
		gEngfuncs.pEventAPI->EV_SetTraceHull( 1 );
		gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_NORMAL, -1, &tr2 );
		if ( tr2.fraction < 1.0 )
			tr = tr2;
	}

	gEngfuncs.pEventAPI->EV_PopPMStates();

	gp_tr_decal[ idx - 1 ] = NULL;

	if ( tr.fraction >= 1.0 )
	{
		// miss
		EV_TFC_PlayAxeAnim( idx, classid, AXE_ANIM_MISS );
		EV_TFC_PlayAxeSound( idx, classid, origin, AXE_SOUND_MISS, 1.0 );
		return;
	}

	// remember the trace for the delayed decal event
	g_tr_decal[ idx - 1 ] = tr;
	gp_tr_decal[ idx - 1 ] = &g_tr_decal[ idx - 1 ];

	EV_TFC_PlayAxeAnim( idx, classid, AXE_ANIM_HIT );

	entity = gEngfuncs.pEventAPI->EV_IndexFromTrace( &tr );

	switch ( classid )
	{
	case AXE_CLASS_KNIFE:
	case AXE_CLASS_CROWBAR:
		bHit = EV_TFC_AxeHit( idx, origin, forward, right, entity, forward, &tr );
		break;
	case AXE_CLASS_SPANNER:
		bHit = EV_TFC_Spanner( idx, origin, forward, right, entity, forward, &tr );
		break;
	case AXE_CLASS_MEDIKIT:
		// no decal from the medikit
		gp_tr_decal[ idx - 1 ] = NULL;
		bHit = EV_TFC_Medkit( idx, origin, forward, right, entity, forward, &tr );
		break;
	default:
		bHit = 0;
		break;
	}

	if ( gp_tr_decal[ idx - 1 ] )
	{
		gEngfuncs.pEventAPI->EV_PlaybackEvent( idx, NULL, gEngfuncs.pEventAPI->EV_PrecacheEvent( 1, "events/wpn/tf_axedecal.sc" ), 0.2, origin, angles, 0, 0, 0, 0, 0, 0 );
	}

	if ( !bHit )
		return;

	float fvolbar;
	int iSoundType;

	if ( EV_IsPlayer( entity ) )
	{
		fvolbar = 0;
		iSoundType = AXE_SOUND_HITBODY;
	}
	else
	{
		fvolbar = EV_TFC_PlayTextureSound( idx, &tr, vecSrc, vecSrc, BULLET_PLAYER_CROWBAR );

		// also play crowbar strike in multiplayer
		if ( gEngfuncs.GetMaxClients() > 1 )
			fvolbar = 1;

		iSoundType = AXE_SOUND_HITWALL;
	}

	EV_TFC_PlayAxeSound( idx, classid, origin, iSoundType, fvolbar );
}

void EV_TFC_AxeDecal( event_args_t *args )
{
	int idx = args->entindex - 1;
	pmtrace_t *pTrace = gp_tr_decal[ idx ];

	if ( pTrace )
	{
		EV_TFC_DecalGunshot( pTrace, BULLET_PLAYER_CROWBAR );
		gp_tr_decal[ idx ] = NULL;
	}
}

//======================
//	   MEDIKIT SHOTS
//======================
void EV_TFC_SteamShot( event_args_t *args )
{
	vec3_t origin;
	VectorCopy( args->origin, origin );
	gEngfuncs.pEventAPI->EV_PlaySound( args->entindex, origin, CHAN_ITEM, "ambience/steamburst1.wav", 1, ATTN_NORM, 0, PITCH_NORM );
}

void EV_TFC_NormalShot( event_args_t *args )
{
	vec3_t origin;
	VectorCopy( args->origin, origin );
	gEngfuncs.pEventAPI->EV_PlaySound( args->entindex, origin, CHAN_ITEM, "items/medshot4.wav", 1, ATTN_NORM, 0, PITCH_NORM );
}

void EV_TFC_SuperShot( event_args_t *args )
{
	vec3_t origin;
	VectorCopy( args->origin, origin );
	gEngfuncs.pEventAPI->EV_PlaySound( args->entindex, origin, CHAN_ITEM, "items/medshot5.wav", 1, ATTN_NORM, 0, PITCH_NORM );
}

//======================
//	   GIBS
//======================
void EV_TFC_GibTouchCallback( struct tempent_s *ent, pmtrace_t *ptr )
{
	// leave some blood where it lands, a few times
	if ( Length( ent->entity.baseline.origin ) > 0 && ent->entity.curstate.team > 0 )
	{
		char decalname[ 32 ];
		int idx = gEngfuncs.pfnRandomLong( 0, 5 );

		if ( CVAR_GET_FLOAT( "violence_hblood" ) != 0 )
		{
			sprintf( decalname, "{blood%i", idx + 1 );
			EV_TFC_DecalTrace( ptr, decalname );
		}

		ent->entity.curstate.team--;
	}
}

// playerclass holds the gib's state: 0 flying, 1 resting, 2 start fading, 3 fading, 4 gone
void EV_TFC_GibCallback( struct tempent_s *ent, float frametime, float currenttime )
{
	float flSpeed = Length( ent->entity.baseline.origin );

	switch ( ent->entity.curstate.playerclass )
	{
	case 1:
		ent->entity.baseline.fuser1 -= frametime;
		if ( ent->entity.baseline.fuser1 <= 0 )
			ent->entity.curstate.playerclass = 2;
		ent->die = gEngfuncs.GetClientTime() + 1.0;
		break;
	case 2:
		ent->entity.curstate.playerclass = 3;
		ent->entity.curstate.renderamt = 255;
		ent->entity.curstate.rendermode = kRenderTransTexture;
		ent->die = gEngfuncs.GetClientTime() + 2.5;
		break;
	case 3:
		if ( ent->entity.curstate.renderamt > 7 )
		{
			ent->die = gEngfuncs.GetClientTime() + 1.0;
			ent->entity.curstate.renderamt -= frametime * 70;
		}
		else
		{
			ent->entity.curstate.renderamt = 0;
			ent->die = gEngfuncs.GetClientTime() + 0.2;
			ent->entity.curstate.playerclass = 4;
		}
		break;
	case 4:
		break;
	default:
		if ( flSpeed == 0 )
		{
			// came to rest
			ent->entity.curstate.playerclass = 1;
			ent->entity.baseline.fuser1 = cl_giblife->value;
		}
		ent->die = gEngfuncs.GetClientTime() + 1.0;
		break;
	}
}

void EV_TFC_GibVelocityCheck( float *vel )
{
	float flLength = Length( vel );
	if ( flLength > 1500 )
		VectorScale( vel, 1500 / flLength, vel );
}

TEMPENTITY *EV_TFC_CreateGib( float *origin, float *attackdir, int multiplier, int ishead )
{
	int modelindex;
	vec3_t mins, maxs;
	float flMultiplier;
	float flScale;

	model_t *mdl = gEngfuncs.CL_LoadModel( "models/hgibs.mdl", &modelindex );
	if ( !mdl )
		return NULL;

	if ( multiplier == 1 )
		flMultiplier = 0.7;
	else if ( multiplier == 2 )
		flMultiplier = 2.0;
	else
		flMultiplier = 4.0;

	flScale = cl_gibvelscale->value;

	gEngfuncs.pEventAPI->EV_LocalPlayerBounds( 0, mins, maxs );

	TEMPENTITY *gib = gEngfuncs.pEfxAPI->CL_TentEntAllocCustom( origin, mdl, 0, EV_TFC_GibCallback );
	if ( !gib )
		return NULL;

	if ( ishead )
		gib->entity.curstate.body = 0;
	else
		gib->entity.curstate.body = gEngfuncs.pfnRandomLong( 1, 5 );

	// somewhere inside the body
	for ( int i = 0; i < 3; i++ )
		gib->entity.origin[ i ] += ( maxs[ i ] - mins[ i ] ) * 0.5 * gEngfuncs.pfnRandomFloat( -1, 1 );

	if ( !ishead )
	{
		VectorScale( attackdir, -1, gib->entity.curstate.velocity );
		for ( int i = 0; i < 3; i++ )
		{
			gib->entity.curstate.velocity[ i ] += gEngfuncs.pfnRandomFloat( -0.25, 0.25 );
			gib->entity.curstate.velocity[ i ] *= gEngfuncs.pfnRandomFloat( 300, 400 ) * ( flMultiplier * flScale );
		}

		gib->entity.baseline.angles[0] = gEngfuncs.pfnRandomFloat( 100, 200 );
		gib->entity.baseline.angles[1] = gEngfuncs.pfnRandomFloat( 100, 200 );
	}
	else
	{
		gib->entity.curstate.velocity[0] = gEngfuncs.pfnRandomFloat( -100, 100 );
		gib->entity.curstate.velocity[1] = gEngfuncs.pfnRandomFloat( -100, 100 );
		gib->entity.curstate.velocity[2] = gEngfuncs.pfnRandomFloat( 200, 300 );

		gib->entity.baseline.angles[0] = gEngfuncs.pfnRandomFloat( 100, 200 );
		gib->entity.baseline.angles[1] = gEngfuncs.pfnRandomFloat( 100, 300 );
	}

	EV_TFC_GibVelocityCheck( gib->entity.curstate.velocity );

	gib->flags |= FTENT_GRAVITY | FTENT_ROTATE | FTENT_COLLIDEWORLD;
	gib->die += 1.0;
	VectorCopy( gib->entity.curstate.velocity, gib->entity.baseline.origin );
	gib->entity.curstate.solid = SOLID_NOT;
	gib->entity.curstate.playerclass = 0;
	gib->hitcallback = EV_TFC_GibTouchCallback;
	gib->entity.curstate.team = 5;		// blood decals left to make

	return gib;
}

void EV_TFC_Gibs( event_args_t *args )
{
	vec3_t origin, attackdir;
	int multiplier;

	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, attackdir );
	multiplier = args->iparam1;

	gEngfuncs.pEventAPI->EV_PlaySound( args->entindex, origin, CHAN_WEAPON, "common/bodysplat.wav", 1, ATTN_NORM, 0, PITCH_NORM );

	int iCount = (int)cl_gibcount->value;
	if ( iCount > 0 )
	{
		if ( iCount > 64 )
			iCount = 64;

		for ( int i = 0; i < iCount; i++ )
			EV_TFC_CreateGib( origin, attackdir, multiplier, 0 );
	}

	EV_TFC_CreateGib( origin, attackdir, multiplier, 1 );
}

//======================
//	   BENCHMARK
//======================
extern float g_fZAdjust;
float g_nTime;

void EV_TFC_BenchmarkWallMark( pmtrace_t *pTrace, char *decalName )
{
	if ( !decalName || !decalName[0] || pTrace->fraction == 1.0 )
		return;

	pTrace->endpos[2] += g_fZAdjust;

	if ( CVAR_GET_FLOAT( "r_decals" ) )
	{
		gEngfuncs.pEfxAPI->R_DecalShoot(
			gEngfuncs.pEfxAPI->Draw_DecalIndex( gEngfuncs.pEfxAPI->Draw_DecalIndexFromName( decalName ) ),
			0, 0, pTrace->endpos, 0 );
	}
}

void EV_TFC_BenchMarkTrace( pmtrace_t *pTrace )
{
	physent_t *pe = gEngfuncs.pEventAPI->EV_GetPhysent( pTrace->ent );

	if ( pe && ( pe->solid == SOLID_BSP || pe->movetype == MOVETYPE_PUSHSTEP ) && pTrace->fraction != 1.0 )
	{
		pTrace->endpos[2] += g_fZAdjust;

		if ( CVAR_GET_FLOAT( "r_decals" ) )
		{
			gEngfuncs.pEfxAPI->R_DecalShoot(
				gEngfuncs.pEfxAPI->Draw_DecalIndex( gEngfuncs.pEfxAPI->Draw_DecalIndexFromName( "{dot" ) ),
				0, 0, pTrace->endpos, 0 );
		}
	}
}

void EV_Benchmark( event_args_t *args )
{
	int idx;
	vec3_t origin;
	vec3_t angles;
	vec3_t up, right, forward;
	vec3_t vecSrc, vecEnd, vecAiming;
	pmtrace_t tr;

	idx = args->entindex;
	VectorCopy( args->origin, origin );
	VectorCopy( args->angles, angles );

	gEngfuncs.pfnAngleVectors( angles, forward, right, up );

	EV_IsLocal( idx );

	gEngfuncs.pEventAPI->EV_PlaySound( idx, origin, CHAN_WEAPON, "common/wpn_select.wav", 0.9, ATTN_NORM, 0, PITCH_NORM );

	EV_GetGunPosition( args, vecSrc, origin );
	VectorCopy( forward, vecAiming );
	VectorMA( vecSrc, 2, up, vecSrc );
	VectorMA( vecSrc, 8192, vecAiming, vecEnd );

	gEngfuncs.pEventAPI->EV_SetUpPlayerPrediction( false, true );
	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetSolidPlayers( idx - 1 );
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecSrc, vecEnd, PM_STUDIO_BOX, -1, &tr );
	gEngfuncs.pEventAPI->EV_PopPMStates();

	if ( tr.fraction != 1.0 && g_nTime < gEngfuncs.GetClientTime() )
	{
		EV_TFC_BenchMarkTrace( &tr );
		g_nTime = gEngfuncs.GetClientTime() + 0.05;
	}
}

//======================
//	   BUILDINGS
//======================
// Engineer buildings send one event when they change; we keep a list of
// them and run their effects (sparks, smoke, teleporter rings) every 0.1s.

// bits in the event's iparam1
#define BUILDING_SPARKS			( 1 << 0 )
#define BUILDING_SMOKE			( 1 << 1 )
#define TELEPORTER_ENTRY_RINGS	( 1 << 2 )
#define TELEPORTER_EXIT_RINGS	( 1 << 3 )
#define TELEPORTER_AMBIENT		( 1 << 4 )
#define TELEPORTER_READY		( 1 << 5 )
#define TELEPORTER_IN			( 1 << 6 )
#define TELEPORTER_OUT			( 1 << 7 )
#define BUILDING_MOVED			( 1 << 8 )
#define TELEPORTER_PARTICLES	( 1 << 9 )
#define BUILDING_REMOVE			( 1 << 10 )
#define BUILDING_NEWINDEX		( 1 << 11 )

typedef struct eventnode_s
{
	event_args_t *data;
	struct eventnode_s *prev;
	struct eventnode_s *next;
} eventnode_t;

eventnode_t *g_pEventListHead = NULL;
float g_flNextEventListThink = 0;

Vector g_vRed( 255, 0, 0 );
Vector g_vBlue( 0, 0, 255 );
Vector g_vYellow( 255, 255, 0 );
Vector g_vGreen( 0, 255, 0 );
Vector g_vBlack( 0, 0, 0 );

void DoSparkSmokeEffect( event_args_t *args );
void DoTeleporterRings( event_args_t *args );
void DoTeleporterParticles( event_args_t *args );
void PlayTeleporterAmbientSound( event_args_t *args );
void CheckEventsFinished( eventnode_t *node );

eventnode_t *FindEntity( int index )
{
	eventnode_t *node = g_pEventListHead;

	while ( node )
	{
		if ( node->data->entindex == index )
			return node;

		node = node->next;
	}

	return NULL;
}

void AddEvent( eventnode_t *node )
{
	if ( !node )
		return;

	if ( !g_pEventListHead )
	{
		g_pEventListHead = node;
		node->next = NULL;
		node->prev = NULL;
		return;
	}

	eventnode_t *last = g_pEventListHead;
	while ( last->next )
		last = last->next;

	node->prev = last;
	node->next = NULL;
	last->next = node;
}

void RemoveEvent( eventnode_t *node )
{
	if ( !node || !g_pEventListHead )
		return;

	if ( node == g_pEventListHead )
	{
		g_pEventListHead = NULL;
		if ( node->next )
		{
			node->next->prev = NULL;
			g_pEventListHead = node->next;
		}
	}
	else if ( node->next && node->prev )
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	else
	{
		node->prev->next = NULL;
	}

	free( node );
}

void EV_TFC_BuildingEvent( event_args_t *args )
{
	if ( !args )
		return;

	eventnode_t *node = FindEntity( args->entindex );

	if ( node )
	{
		if ( args->bparam1 == 1 )
		{
			// more effects for a building we know
			node->data->iparam1 |= args->iparam1;
			node->data->iparam2 = args->iparam2;

			if ( args->iparam1 & TELEPORTER_PARTICLES )
				node->data->bparam2 = args->bparam2;

			if ( args->iparam1 & BUILDING_NEWINDEX )
			{
				node->data->entindex = (int)args->fparam1;
				node->data->iparam1 &= ~BUILDING_NEWINDEX;
			}
			return;
		}

		if ( args->iparam1 & BUILDING_MOVED )
		{
			VectorCopy( args->origin, node->data->origin );
			return;
		}

		if ( !( args->iparam1 & BUILDING_REMOVE ) )
		{
			// turn off some effects
			node->data->iparam1 &= ~args->iparam1;

			if ( args->iparam1 & TELEPORTER_PARTICLES )
				node->data->bparam2 = 0;

			if ( node->data->iparam1 )
				return;
		}

		RemoveEvent( node );
		return;
	}

	if ( args->bparam1 )
	{
		// a new building
		node = new eventnode_t;
		if ( !node )
			return;

		node->data = NULL;
		node->prev = NULL;
		node->next = NULL;

		node->data = new event_args_t;
		if ( !node->data )
		{
			delete node;
			return;
		}

		memcpy( node->data, args, sizeof( event_args_t ) );

		if ( args->iparam1 & BUILDING_NEWINDEX )
		{
			node->data->iparam1 = args->iparam1 & ~BUILDING_NEWINDEX;
			node->data->entindex = (int)args->fparam1;
		}

		AddEvent( node );
	}
}

void ClearEventList( void )
{
	eventnode_t *node = g_pEventListHead;

	while ( node )
	{
		eventnode_t *next = node->next;
		delete node->data;
		delete node;
		node = next;
	}

	g_pEventListHead = NULL;
	g_flNextEventListThink = 0;
}

void RunEventList( void )
{
	if ( g_flNextEventListThink && gpGlobals->time < g_flNextEventListThink )
		return;

	g_flNextEventListThink = gpGlobals->time + 0.1;

	eventnode_t *node = g_pEventListHead;
	while ( node )
	{
		eventnode_t *next = node->next;

		if ( node->data->iparam1 & TELEPORTER_AMBIENT )
			PlayTeleporterAmbientSound( node->data );

		if ( node->data->iparam1 & TELEPORTER_OUT )
		{
			gEngfuncs.pEventAPI->EV_PlaySound( -1, node->data->origin, CHAN_STATIC, "misc/teleport_out.wav", 1.0, 0.5, 0, PITCH_NORM );
			node->data->iparam1 &= ~TELEPORTER_OUT;
			node->data->iparam1 |= TELEPORTER_ENTRY_RINGS;
		}

		if ( node->data->iparam1 & TELEPORTER_IN )
		{
			gEngfuncs.pEventAPI->EV_PlaySound( -1, node->data->origin, CHAN_STATIC, "misc/teleport_in.wav", 1.0, 0.5, 0, PITCH_NORM );
			node->data->iparam1 &= ~TELEPORTER_IN;
			node->data->iparam1 |= TELEPORTER_EXIT_RINGS;
		}

		if ( node->data->iparam1 & TELEPORTER_READY )
		{
			gEngfuncs.pEventAPI->EV_PlaySound( -1, node->data->origin, CHAN_STATIC, "misc/teleport_ready.wav", 1.0, 0.5, 0, PITCH_NORM );
			node->data->iparam1 &= ~TELEPORTER_READY;
		}

		if ( node->data->iparam1 & BUILDING_SPARKS )
			DoSparkSmokeEffect( node->data );

		if ( node->data->iparam1 & ( TELEPORTER_ENTRY_RINGS | TELEPORTER_EXIT_RINGS ) )
			DoTeleporterRings( node->data );

		if ( node->data->iparam1 & TELEPORTER_PARTICLES )
			DoTeleporterParticles( node->data );

		CheckEventsFinished( node );

		node = next;
	}
}

void RandomSparkSound( float *origin )
{
	float flVolume = gEngfuncs.pfnRandomFloat( 0.2, 0.45 );
	char *pszSound;

	switch ( (int)( gEngfuncs.pfnRandomFloat( 0, 1 ) * 6 ) )
	{
	case 0:	pszSound = "buttons/spark1.wav"; break;
	case 1:	pszSound = "buttons/spark2.wav"; break;
	case 2:	pszSound = "buttons/spark3.wav"; break;
	case 3:	pszSound = "buttons/spark4.wav"; break;
	case 4:	pszSound = "buttons/spark5.wav"; break;
	default: pszSound = "buttons/spark6.wav"; break;
	}

	gEngfuncs.pEventAPI->EV_PlaySound( -1, origin, CHAN_STATIC, pszSound, flVolume, ATTN_NORM, 0, PITCH_NORM );
}

void DoSparkSmokeEffect( event_args_t *args )
{
	if ( !args )
		return;

	if ( gEngfuncs.pfnRandomFloat( 0, 1 ) <= 0.8 )
		return;

	// spark from a random point back onto the building
	vec3_t vecOrigin, vecStart;
	pmtrace_t tr;

	VectorCopy( args->origin, vecOrigin );
	vecStart = vecOrigin + Vector( gEngfuncs.pfnRandomLong( -50, 50 ), gEngfuncs.pfnRandomLong( -50, 50 ), gEngfuncs.pfnRandomLong( 15, 50 ) );

	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( vecStart, vecOrigin, PM_NORMAL, -1, &tr );
	gEngfuncs.pEventAPI->EV_PopPMStates();

	if ( args->entindex != PM_GetPhysEntInfo( tr.ent ) )
		return;

	gEngfuncs.pEfxAPI->R_SparkEffect( tr.endpos, 8, -200, 200 );
	RandomSparkSound( tr.endpos );

	if ( args->iparam1 & BUILDING_SMOKE )
	{
		tr.endpos[2] -= 8;
		TEMPENTITY *pSmoke = gEngfuncs.pEfxAPI->R_DefaultSprite( tr.endpos, gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/steam1.spr" ), 15 );
		gEngfuncs.pEfxAPI->R_Sprite_Smoke( pSmoke, 0.8 );
	}
}

Vector *GetTeamColor( int team_no )
{
	switch ( team_no )
	{
	case 1:	return &g_vBlue;
	case 2:	return &g_vRed;
	case 3:	return &g_vYellow;
	case 4:	return &g_vGreen;
	}
	return &g_vBlack;
}

void DoTeleporterRings( event_args_t *args )
{
	static int iEntryCount = 0;
	static int iExitCount = 6;
	float flOffset;

	if ( !args )
		return;

	int iModel = gEngfuncs.pEventAPI->EV_FindModelIndex( "sprites/shellchrome.spr" );

	// rings climb up out of the entrance, and come down into the exit
	if ( args->iparam1 & TELEPORTER_ENTRY_RINGS )
	{
		if ( ++iEntryCount > 6 )
			iEntryCount = 0;
		flOffset = 98 - iEntryCount * 14;
	}
	else
	{
		if ( --iExitCount < 0 )
			iExitCount = 6;
		flOffset = 98 - iExitCount * 14;
	}

	vec3_t vecStart, vecEnd;
	vecStart = Vector( args->origin[0], args->origin[1], args->origin[2] + flOffset );
	vecEnd = Vector( vecStart[0], vecStart[1], vecStart[2] + 125 );

	Vector *pColor = GetTeamColor( args->iparam2 );
	gEngfuncs.pEfxAPI->R_BeamCirclePoints( TE_BEAMCYLINDER, vecStart, vecEnd, iModel, 0.2, 10, 0, 1.0, 0, 0, 0, pColor->x, pColor->y, pColor->z );
}

void DoTeleporterParticles( event_args_t *args )
{
	if ( !args )
		return;

	model_t *pSprite = gEngfuncs.GetSpritePointer( gEngfuncs.pfnSPR_Load( "sprites/particle.spr" ) );
	if ( !pSprite )
		return;

	int iCount = gEngfuncs.pfnRandomLong( 10, 15 );
	for ( int i = 0; i < iCount; i++ )
	{
		Vector vecOrigin = args->origin;
		vecOrigin.x += gEngfuncs.pfnRandomLong( -15, 15 );
		vecOrigin.y += gEngfuncs.pfnRandomLong( -15, 15 );

		if ( args->bparam2 )
			vecOrigin.z += 98;
		else
			vecOrigin.z += 12;

		Vector vecAngles( gEngfuncs.pfnRandomFloat( 0, 255 ), gEngfuncs.pfnRandomFloat( 0, 255 ), gEngfuncs.pfnRandomFloat( 0, 255 ) );

		CBaseParticle *pParticle = new CBaseParticle;
		if ( !pParticle )
			return;

		pParticle->InitializeSprite( vecOrigin, Vector( 0, 0, 1 ), pSprite, 3.0, 255.0 );

		pParticle->m_vAngles = vecAngles;
		pParticle->m_flGravity = 0;
		pParticle->m_iRendermode = kRenderTransAlpha;
		pParticle->m_flFadeSpeed = 10;
		pParticle->m_iFrame = 0;
		pParticle->m_flScaleSpeed = 0;
		pParticle->m_flMass = gEngfuncs.pfnRandomFloat( 0, 0.5 );
		pParticle->SetCollisionFlags( TRI_COLLIDEWORLD );
		pParticle->SetLightFlag( LIGHT_NONE );
		pParticle->SetCullFlag( CULL_PVS | CULL_FRUSTUM_PLANE );
		pParticle->m_vColor = Vector( 0, 255, 0 );
		pParticle->m_flDieTime = gpGlobals->time + 0.75;

		// up out of the entrance, down into the exit
		if ( args->bparam2 )
			pParticle->m_vVelocity = Vector( 0, 0, gEngfuncs.pfnRandomLong( -50, 50 ) - 75 );
		else
			pParticle->m_vVelocity = Vector( 0, 0, gEngfuncs.pfnRandomLong( -50, 50 ) + 75 );
	}
}

void PlayTeleporterAmbientSound( event_args_t *args )
{
	if ( !args )
		return;

	if ( args->fparam2 && args->fparam2 > gpGlobals->time )
		return;

	if ( gEngfuncs.pfnRandomFloat( 0, 1 ) > 0.98 )
	{
		args->fparam2 = gpGlobals->time + 6;
		gEngfuncs.pEventAPI->EV_PlaySound( -1, args->origin, CHAN_STATIC, "misc/teleport_ready.wav", 1.0, 0.5, 0, PITCH_NORM );
	}
}

void CheckEventsFinished( eventnode_t *node )
{
	if ( node && !node->data->iparam1 )
		RemoveEvent( node );
}
