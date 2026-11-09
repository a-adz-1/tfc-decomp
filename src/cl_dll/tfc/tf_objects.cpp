/***
*
*	Team Fortress Classic: client-side objects (the sniper's laser dot)
*
*	Reconstructed from client.so (25th Anniversary), DWARF-guided.
*
****/
#include "../hud.h"
#include "../cl_util.h"
#include "../demo.h"
#include "../bench.h"

#include "demo_api.h"
#include "const.h"
#include "entity_state.h"
#include "cl_entity.h"

#include "pm_defs.h"
#include "event_api.h"
#include "entity_types.h"
#include "r_efx.h"

#define TF_DEFS_ONLY
#include "tf_defs.h"

extern Vector g_aimorg;
extern float g_fZAdjust;

extern int g_demosniper;
extern int g_demosniperdamage;
extern float g_demosniperorg[3];
extern float g_demosniperangles[3];

void HUD_GetLastOrg( float *org );
int HUD_NeedSpot( int *damage );

/*
=====================
HUD_CreateSniperDot

Put the laser dot where the sniper's aim hits. Returns 1 with the dot's
position in dotorigin if it was drawn.
=====================
*/
int HUD_CreateSniperDot( int damage, Vector viewangles, Vector origin, float *dotorigin )
{
	int iret = 0;
	static cl_entity_t dot;
	int index;

	memset( &dot, 0, sizeof( dot ) );

	dot.model = gEngfuncs.CL_LoadModel( Bench_Active() ? "sprites/ppdemodot.spr" : "sprites/laserdot.spr", &index );
	if ( !dot.model )
		return 0;

	cl_entity_t *player = gEngfuncs.GetLocalPlayer();
	if ( !player )
		return 0;

	dot.curstate.movetype = MOVETYPE_NONE;
	dot.curstate.solid = SOLID_NOT;
	dot.curstate.modelindex = index;
	dot.curstate.rendermode = kRenderGlow;
	dot.curstate.renderfx = kRenderFxNoDissipation;
	dot.curstate.renderamt = damage;

	Vector forward, right, up;
	gEngfuncs.pfnAngleVectors( viewangles, forward, right, up );

	Vector farpoint = origin + 8192 * forward;

	pmtrace_t tr;
	gEngfuncs.pEventAPI->EV_SetUpPlayerPrediction( false, true );
	gEngfuncs.pEventAPI->EV_PushPMStates();
	gEngfuncs.pEventAPI->EV_SetSolidPlayers( player->index - 1 );
	gEngfuncs.pEventAPI->EV_SetTraceHull( 2 );
	gEngfuncs.pEventAPI->EV_PlayerTrace( origin, farpoint, PM_STUDIO_BOX, -1, &tr );

	if ( tr.fraction != 1.0 )
	{
		int end_contents = gEngfuncs.PM_PointContents( tr.endpos, NULL );

		// not on the sky, and not through the water's surface
		if ( end_contents != CONTENTS_SKY )
		{
			int inwater1 = gEngfuncs.PM_PointContents( origin, NULL ) == CONTENTS_WATER;
			int inwater2 = end_contents == CONTENTS_WATER;

			if ( inwater1 == inwater2 )
			{
				static float fZAdjust = 0;
				static float fLastTime;

				// the benchmark makes the dot wobble
				if ( Bench_Active() && Bench_InStage( THIRD_STAGE ) )
				{
					float fRate = Bench_GetPowerPlay() ? 4.0 : 8.0;
					float fBounds = Bench_GetPowerPlay() ? 8.0 : 15.0;
					float dt = gHUD.m_flTime - fLastTime;

					if ( dt > 0 && dt < 1.0 )
					{
						fZAdjust += gEngfuncs.pfnRandomFloat( -fRate, fRate );
						fZAdjust = min( fBounds, fZAdjust );
						fZAdjust = max( -fBounds, fZAdjust );

						tr.endpos.z += fZAdjust;
						g_fZAdjust = fZAdjust;
					}

					fLastTime = gHUD.m_flTime;
				}

				dot.origin = tr.endpos;
				dot.curstate.origin = tr.endpos;
				dot.prevstate = dot.curstate;

				gEngfuncs.CL_CreateVisibleEntity( ET_NORMAL, &dot );

				VectorCopy( dot.origin, dotorigin );
				iret = 1;
			}
		}
	}

	gEngfuncs.pEventAPI->EV_PopPMStates();
	return iret;
}

/*
=====================
Game_AddObjects

Add game specific, client-side objects here
=====================
*/
void Game_AddObjects( void )
{
	int tfc = atoi( gEngfuncs.PhysInfo_ValueForKey( "tfc" ) );
	cl_entity_t *player = gEngfuncs.GetLocalPlayer();
	int damage;

	if ( tfc && player && ( player->curstate.playerclass == PC_SNIPER || Bench_InStage( THIRD_STAGE ) ) )
	{
		if ( HUD_NeedSpot( &damage ) )
		{
			Vector viewangles, origin, dot_origin;

			gEngfuncs.GetViewAngles( viewangles );
			HUD_GetLastOrg( origin );

			if ( Bench_InStage( THIRD_STAGE ) )
				damage = 250;

			if ( HUD_CreateSniperDot( damage, viewangles, origin, dot_origin ) )
				Bench_SpotPosition( dot_origin, g_aimorg );

			if ( gEngfuncs.pDemoAPI->IsRecording() )
			{
				int i = 0;
				unsigned char buf[ 100 ];

				*(int *)&buf[ i ] = 1;
				i += sizeof( int );
				*(int *)&buf[ i ] = damage;
				i += sizeof( int );
				memcpy( &buf[ i ], viewangles, 3 * sizeof( float ) );
				i += 3 * sizeof( float );
				memcpy( &buf[ i ], origin, 3 * sizeof( float ) );
				i += 3 * sizeof( float );

				Demo_WriteBuffer( TYPE_SNIPERDOT, i, buf );
			}
		}
		else if ( gEngfuncs.pDemoAPI->IsRecording() )
		{
			int i = 0;
			unsigned char buf[ 100 ];

			*(int *)&buf[ i ] = 0;
			i += sizeof( int );

			Demo_WriteBuffer( TYPE_SNIPERDOT, i, buf );
		}
	}

	// play back a recorded dot
	if ( gEngfuncs.pDemoAPI->IsPlayingback() && g_demosniper )
	{
		Vector dummy;
		HUD_CreateSniperDot( g_demosniperdamage, g_demosniperangles, g_demosniperorg, dummy );
	}
}
