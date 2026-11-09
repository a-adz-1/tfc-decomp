	/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
/*

===== player.cpp ========================================================

  functions dealing with the player

*/

#include "extdll.h"
#include "util.h"

#include "cbase.h"
#include "player.h"
#include "trains.h"
#include "nodes.h"
#include "weapons.h"
#include "soundent.h"
#include "monsters.h"
#include "shake.h"
#include "decals.h"
#include "gamerules.h"
#include "game.h"
#include "pm_shared.h"
#include "hltv.h"
#include "tf_defs.h"
#include "pm_materials.h"
#include "client.h"
#include "tf_wpn_grenades.h"

// #define DUCKFIX

extern DLL_GLOBAL ULONG		g_ulModelIndexPlayer;
extern DLL_GLOBAL BOOL		g_fGameOver;
extern DLL_GLOBAL	BOOL	g_fDrawLines;
int gEvilImpulse101;
extern DLL_GLOBAL int		g_iSkillLevel, gDisplayTitle;
 

BOOL gInitHUD = TRUE; 

extern void CopyToBodyQue(entvars_t* pev);
extern void respawn(entvars_t *pev, BOOL fCopyCorpse);
extern Vector VecBModelOrigin(entvars_t *pevBModel );
extern edict_t *EntSelectSpawnPoint( edict_t *player );


// the world node graph
extern CGraph	WorldGraph;

#define TRAIN_ACTIVE	0x80 
#define TRAIN_NEW		0xc0
#define TRAIN_OFF		0x00
#define TRAIN_NEUTRAL	0x01
#define TRAIN_SLOW		0x02
#define TRAIN_MEDIUM	0x03
#define TRAIN_FAST		0x04 
#define TRAIN_BACK		0x05

#define	FLASH_DRAIN_TIME	 1.2 //100 units/3 minutes
#define	FLASH_CHARGE_TIME	 0.2 // 100 units/20 seconds  (seconds per unit)

// Global Savedata for player
TYPEDESCRIPTION	CBasePlayer::m_playerSaveData[] = 
{
	DEFINE_FIELD( CBasePlayer, m_flFlashLightTime, FIELD_TIME ),
	DEFINE_FIELD( CBasePlayer, m_iFlashBattery, FIELD_INTEGER ),

	DEFINE_FIELD( CBasePlayer, m_afButtonLast, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_afButtonPressed, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_afButtonReleased, FIELD_INTEGER ),

	DEFINE_ARRAY( CBasePlayer, m_rgItems, FIELD_INTEGER, MAX_ITEMS ),
	DEFINE_FIELD( CBasePlayer, m_afPhysicsFlags, FIELD_INTEGER ),

	DEFINE_FIELD( CBasePlayer, m_flTimeStepSound, FIELD_TIME ),
	DEFINE_FIELD( CBasePlayer, m_flTimeWeaponIdle, FIELD_TIME ),
	DEFINE_FIELD( CBasePlayer, m_flSwimTime, FIELD_TIME ),
	DEFINE_FIELD( CBasePlayer, m_flDuckTime, FIELD_TIME ),
	DEFINE_FIELD( CBasePlayer, m_flWallJumpTime, FIELD_TIME ),

	DEFINE_FIELD( CBasePlayer, m_flSuitUpdate, FIELD_TIME ),
	DEFINE_ARRAY( CBasePlayer, m_rgSuitPlayList, FIELD_INTEGER, CSUITPLAYLIST ),
	DEFINE_FIELD( CBasePlayer, m_iSuitPlayNext, FIELD_INTEGER ),
	DEFINE_ARRAY( CBasePlayer, m_rgiSuitNoRepeat, FIELD_INTEGER, CSUITNOREPEAT ),
	DEFINE_ARRAY( CBasePlayer, m_rgflSuitNoRepeatTime, FIELD_TIME, CSUITNOREPEAT ),
	DEFINE_FIELD( CBasePlayer, m_lastDamageAmount, FIELD_INTEGER ),

	DEFINE_ARRAY( CBasePlayer, m_rgpPlayerItems, FIELD_CLASSPTR, MAX_ITEM_TYPES ),
	DEFINE_FIELD( CBasePlayer, m_pActiveItem, FIELD_CLASSPTR ),
	DEFINE_FIELD( CBasePlayer, m_pLastItem, FIELD_CLASSPTR ),
	
	DEFINE_ARRAY( CBasePlayer, m_rgAmmo, FIELD_INTEGER, MAX_AMMO_SLOTS ),
	DEFINE_FIELD( CBasePlayer, m_idrowndmg, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_idrownrestored, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_tSneaking, FIELD_TIME ),

	DEFINE_FIELD( CBasePlayer, m_iTrain, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_bitsHUDDamage, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_flFallVelocity, FIELD_FLOAT ),
	DEFINE_FIELD( CBasePlayer, m_iTargetVolume, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_iWeaponVolume, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_iExtraSoundTypes, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_iWeaponFlash, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_fLongJump, FIELD_BOOLEAN ),
	DEFINE_FIELD( CBasePlayer, m_fInitHUD, FIELD_BOOLEAN ),
	DEFINE_FIELD( CBasePlayer, m_tbdPrev, FIELD_TIME ),

	DEFINE_FIELD( CBasePlayer, m_pTank, FIELD_EHANDLE ),
	DEFINE_FIELD( CBasePlayer, m_iHideHUD, FIELD_INTEGER ),
	DEFINE_FIELD( CBasePlayer, m_iFOV, FIELD_INTEGER ),
	
	//DEFINE_FIELD( CBasePlayer, m_fDeadTime, FIELD_FLOAT ), // only used in multiplayer games
	//DEFINE_FIELD( CBasePlayer, m_fGameHUDInitialized, FIELD_INTEGER ), // only used in multiplayer games
	//DEFINE_FIELD( CBasePlayer, m_flStopExtraSoundTime, FIELD_TIME ),
	//DEFINE_FIELD( CBasePlayer, m_fKnownItem, FIELD_INTEGER ), // reset to zero on load
	//DEFINE_FIELD( CBasePlayer, m_iPlayerSound, FIELD_INTEGER ),	// Don't restore, set in Precache()
	//DEFINE_FIELD( CBasePlayer, m_pentSndLast, FIELD_EDICT ),	// Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_flSndRoomtype, FIELD_FLOAT ),	// Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_flSndRange, FIELD_FLOAT ),	// Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_fNewAmmo, FIELD_INTEGER ), // Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_flgeigerRange, FIELD_FLOAT ),	// Don't restore, reset in Precache()
	//DEFINE_FIELD( CBasePlayer, m_flgeigerDelay, FIELD_FLOAT ),	// Don't restore, reset in Precache()
	//DEFINE_FIELD( CBasePlayer, m_igeigerRangePrev, FIELD_FLOAT ),	// Don't restore, reset in Precache()
	//DEFINE_FIELD( CBasePlayer, m_iStepLeft, FIELD_INTEGER ), // Don't need to restore
	//DEFINE_ARRAY( CBasePlayer, m_szTextureName, FIELD_CHARACTER, CBTEXTURENAMEMAX ), // Don't need to restore
	//DEFINE_FIELD( CBasePlayer, m_chTextureType, FIELD_CHARACTER ), // Don't need to restore
	//DEFINE_FIELD( CBasePlayer, m_fNoPlayerSound, FIELD_BOOLEAN ), // Don't need to restore, debug
	//DEFINE_FIELD( CBasePlayer, m_iUpdateTime, FIELD_INTEGER ), // Don't need to restore
	//DEFINE_FIELD( CBasePlayer, m_iClientHealth, FIELD_INTEGER ), // Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_iClientBattery, FIELD_INTEGER ), // Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_iClientHideHUD, FIELD_INTEGER ), // Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_fWeapon, FIELD_BOOLEAN ),  // Don't restore, client needs reset
	//DEFINE_FIELD( CBasePlayer, m_nCustomSprayFrames, FIELD_INTEGER ), // Don't restore, depends on server message after spawning and only matters in multiplayer
	//DEFINE_FIELD( CBasePlayer, m_vecAutoAim, FIELD_VECTOR ), // Don't save/restore - this is recomputed
	//DEFINE_ARRAY( CBasePlayer, m_rgAmmoLast, FIELD_INTEGER, MAX_AMMO_SLOTS ), // Don't need to restore
	//DEFINE_FIELD( CBasePlayer, m_fOnTarget, FIELD_BOOLEAN ), // Don't need to restore
	//DEFINE_FIELD( CBasePlayer, m_nCustomSprayFrames, FIELD_INTEGER ), // Don't need to restore
	
};	


int giPrecacheGrunt = 0;
int gmsgSelAmmo = 0;
int gmsgCurWeapon = 0;
int gmsgGeigerRange = 0;
int gmsgFlashlight = 0;
int gmsgFlashBattery = 0;
int gmsgHealth = 0;
int gmsgDamage = 0;
int gmsgBattery = 0;
int gmsgGrenades = 0;
int gmsgSetSecAmmoIcon = 0;
int gmsgTrain = 0;
int gmsgItems = 0;
int gmsgConcuss = 0;
int gmsgHudText = 0;
int gmsgSayText = 0;
int gmsgStatusIcon = 0;
int gmsgTextMsg = 0;
int gmsgSpecHealth = 0;
int gmsgStatusText = 0;
int gmsgStatusValue = 0;
int gmsgWeaponList = 0;
int gmsgResetHUD = 0;
int gmsgInitHUD = 0;
int gmsgViewMode = 0;
int gmsgShowGameTitle = 0;
int gmsgDeathMsg = 0;
int gmsgScoreInfo = 0;
int gmsgTeamInfo = 0;
int gmsgTeamScore = 0;
int gmsgGameMode = 0;
int gmsgMOTD = 0;
int gmsgServerName = 0;
int gmsgAmmoPickup = 0;
int gmsgWeapPickup = 0;
int gmsgItemPickup = 0;
int gmsgHideWeapon = 0;
int gmsgSetCurWeap = 0;
int gmsgSetFOV = 0;
int gmsgShowMenu = 0;
int gmsgShake = 0;
int gmsgFade = 0;
int gmsgAmmoX = 0;
int gmsgBench = 0;
int gmsgSpectator = 0;
int gmsgAllowSpec = 0;
int gmsgSpecFade = 0;
int gmsgResetFade = 0;
int gmsgValidClasses = 0;
int gmsgTeamNames = 0;
int gmsgFeignState = 0;
int gmsgDetpackState = 0;
int gmsgVGUIMenu = 0;
int gmsgBuildState = 0;
int gmsgRandomPC = 0;


void LinkUserMessages( void )
{
	// Already taken care of?
	if ( gmsgHealth )
		return;

	gmsgSelAmmo = REG_USER_MSG( "SelAmmo", 4 );
	gmsgCurWeapon = REG_USER_MSG( "CurWeapon", 3 );
	gmsgGeigerRange = REG_USER_MSG( "Geiger", 1 );
	gmsgFlashlight = REG_USER_MSG( "Flashlight", 2 );
	gmsgFlashBattery = REG_USER_MSG( "FlashBat", 1 );
	gmsgHealth = REG_USER_MSG( "Health", 1 );
	gmsgDamage = REG_USER_MSG( "Damage", 12 );
	gmsgBattery = REG_USER_MSG( "Battery", 4 );
	gmsgGrenades = REG_USER_MSG( "SecAmmoVal", 2 );
	gmsgSetSecAmmoIcon = REG_USER_MSG( "SecAmmoIcon", -1 );
	gmsgTrain = REG_USER_MSG( "Train", 1 );
	gmsgItems = REG_USER_MSG( "Items", 4 );
	gmsgConcuss = REG_USER_MSG( "Concuss", 1 );
	gmsgHudText = REG_USER_MSG( "HudText", -1 );
	gmsgSayText = REG_USER_MSG( "SayText", -1 );
	gmsgStatusIcon = REG_USER_MSG( "StatusIcon", -1 );
	gmsgTextMsg = REG_USER_MSG( "TextMsg", -1 );
	gmsgSpecHealth = REG_USER_MSG( "SpecHealth", 1 );
	gmsgStatusText = REG_USER_MSG( "StatusText", -1 );
	gmsgStatusValue = REG_USER_MSG( "StatusValue", 3 );
	gmsgWeaponList = REG_USER_MSG( "WeaponList", -1 );
	gmsgResetHUD = REG_USER_MSG( "ResetHUD", 1 );
	gmsgInitHUD = REG_USER_MSG( "InitHUD", 0 );
	gmsgViewMode = REG_USER_MSG( "ViewMode", 0 );
	gmsgShowGameTitle = REG_USER_MSG( "GameTitle", 1 );
	gmsgDeathMsg = REG_USER_MSG( "DeathMsg", -1 );
	gmsgScoreInfo = REG_USER_MSG( "ScoreInfo", 9 );
	gmsgTeamInfo = REG_USER_MSG( "TeamInfo", -1 );
	gmsgTeamScore = REG_USER_MSG( "TeamScore", -1 );
	gmsgGameMode = REG_USER_MSG( "GameMode", 1 );
	gmsgMOTD = REG_USER_MSG( "MOTD", -1 );
	gmsgServerName = REG_USER_MSG( "ServerName", -1 );
	gmsgAmmoPickup = REG_USER_MSG( "AmmoPickup", 2 );
	gmsgWeapPickup = REG_USER_MSG( "WeapPickup", 1 );
	gmsgItemPickup = REG_USER_MSG( "ItemPickup", -1 );
	gmsgHideWeapon = REG_USER_MSG( "HideWeapon", 1 );
	gmsgSetFOV = REG_USER_MSG( "SetFOV", 1 );
	gmsgShowMenu = REG_USER_MSG( "ShowMenu", -1 );
	gmsgShake = REG_USER_MSG( "ScreenShake", sizeof(ScreenShake) );
	gmsgFade = REG_USER_MSG( "ScreenFade", sizeof(ScreenFade) );
	gmsgAmmoX = REG_USER_MSG( "AmmoX", 2 );
	gmsgBench = REG_USER_MSG( "Bench", 1 );
	gmsgSpectator = REG_USER_MSG( "Spectator", 2 );
	gmsgAllowSpec = REG_USER_MSG( "AllowSpec", 1 );
	gmsgSpecFade = REG_USER_MSG( "SpecFade", 6 );
	gmsgResetFade = REG_USER_MSG( "ResetFade", 0 );
	gmsgValidClasses = REG_USER_MSG( "ValClass", 10 );
	gmsgTeamNames = REG_USER_MSG( "TeamNames", -1 );
	gmsgFeignState = REG_USER_MSG( "Feign", 1 );
	gmsgDetpackState = REG_USER_MSG( "Detpack", 1 );
	gmsgVGUIMenu = REG_USER_MSG( "VGUIMenu", -1 );
	gmsgBuildState = REG_USER_MSG( "BuildSt", 2 );
	gmsgRandomPC = REG_USER_MSG( "RandomPC", 1 );
}

LINK_ENTITY_TO_CLASS( player, CBasePlayer );


// Damage per unit of ammo, for the stats file
float AmmoDamage( const char *pName )
{
	if ( !pName )
		return 0;

	if ( !strcmp( pName, "9mm" ) )
		return gSkillData.plrDmg9MM;
	if ( !strcmp( pName, "357" ) )
		return gSkillData.plrDmg357;
	if ( !strcmp( pName, "ARgrenades" ) )
		return gSkillData.plrDmgM203Grenade;
	if ( !strcmp( pName, "buckshot" ) )
		return gSkillData.plrDmgBuckshot;
	if ( !strcmp( pName, "bolts" ) )
		return gSkillData.plrDmgCrossbowMonster;
	if ( !strcmp( pName, "rockets" ) )
		return gSkillData.plrDmgRPG;
	if ( !strcmp( pName, "uranium" ) )
		return gSkillData.plrDmgGauss;
	if ( !strcmp( pName, "Hand Grenade" ) )
		return gSkillData.plrDmgHandGrenade;
	if ( !strcmp( pName, "Satchel Charge" ) )
		return gSkillData.plrDmgSatchel;
	if ( !strcmp( pName, "Trip Mine" ) )
		return gSkillData.plrDmgTripmine;

	return 0;
}


void UpdateStatsFile( float dataTime, char *pMapname, float health, float ammo, int skillLevel )
{
	FILE *fp;

	fp = fopen( "stats.txt", "a" );
	if ( !fp )
		return;
	fprintf( fp, "%6.2f, %6.2f, %6.2f, %s, %2d\n", dataTime, health, ammo, pMapname, skillLevel );
	fclose( fp );
}


#define AMMO_THRESHOLD		10			// This much ammo goes by before it is "interesting"
#define HEALTH_THRESHOLD	10			// Same for health
#define OUTPUT_LATENCY		3			// This many seconds for ammo/health to settle

typedef struct
{
	int		lastAmmo;
	float	lastHealth;
	float	lastOutputTime;	// NOTE: these times are in "game" time -- a running total of elapsed time since the game started
	float	nextOutputTime;
	float	dataTime;
	float	gameTime;
	float	lastGameTime;
} TESTSTATS;

TESTSTATS gStats = {0,0,0,0,0,0,0};

void UpdateStats( CBasePlayer *pPlayer )
{
	int i;

	int ammoCount[ MAX_AMMO_SLOTS ];
	memcpy( ammoCount, pPlayer->m_rgAmmo, MAX_AMMO_SLOTS * sizeof( int ) );

	// Keep a running time, so the graph doesn't overlap

	if ( gpGlobals->time < gStats.lastGameTime )	// Changed level or died, don't b0rk
	{
		gStats.lastGameTime = gpGlobals->time;
		gStats.dataTime = gStats.gameTime;
	}

	gStats.gameTime += gpGlobals->time - gStats.lastGameTime;
	gStats.lastGameTime = gpGlobals->time;

	for ( i = 0; i < MAX_ITEM_TYPES; i++ )
	{
		CBasePlayerItem *p = pPlayer->m_rgpPlayerItems[i];
		while ( p )
		{
			ItemInfo II;

			memset( &II, 0, sizeof( II ) );
			p->GetItemInfo( &II );

			int index = pPlayer->GetAmmoIndex( II.pszAmmo1 );
			if ( index >= 0 )
				ammoCount[ index ] += ( (CBasePlayerWeapon *)p )->m_iClip;

			p = p->m_pNext;
		}
	}

	float ammo = 0;
	for ( i = 1; i < MAX_AMMO_SLOTS; i++ )
	{
		ammo += ammoCount[i] * AmmoDamage( CBasePlayerItem::AmmoInfoArray[i].pszName );
	}

	float health = pPlayer->pev->health + pPlayer->pev->armorvalue * 2;	// Armor is 2X health
	float ammoDelta = fabs( ammo - gStats.lastAmmo );
	float healthDelta = fabs( health - gStats.lastHealth );
	int forceWrite = 0;
	if ( health <= 0 && gStats.lastHealth > 0 )
		forceWrite = 1;

	if ( ( ammoDelta > AMMO_THRESHOLD || healthDelta > HEALTH_THRESHOLD ) && !forceWrite )
	{
		if ( gStats.nextOutputTime == 0 )
			gStats.dataTime = gStats.gameTime;

		gStats.lastAmmo = ammo;
		gStats.lastHealth = health;

		gStats.nextOutputTime = gStats.gameTime + OUTPUT_LATENCY;
	}
	else if ( ( gStats.nextOutputTime != 0 && gStats.nextOutputTime < gStats.gameTime ) || forceWrite )
	{
		UpdateStatsFile( gStats.dataTime, (char *)STRING( gpGlobals->mapname ), health, ammo, (int)CVAR_GET_FLOAT( "skill" ) );

		gStats.lastAmmo = ammo;
		gStats.lastHealth = health;
		gStats.lastOutputTime = gStats.gameTime;
		gStats.nextOutputTime = 0;
	}
}


void CBasePlayer :: PainSound( void )
{
	if ( pev->health < 0 )
		return;

	// Drowning
	if ( pev->watertype == CONTENTS_WATER && pev->waterlevel == 3 )
	{
		if ( RANDOM_FLOAT( 0, 1 ) > 0.5 )
			EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/drown1.wav", 1, ATTN_NORM );
		else
			EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/drown2.wav", 1, ATTN_NORM );
		return;
	}

	if ( pev->pain_finished > gpGlobals->time )
	{
		axhitme = 0;
		return;
	}

	pev->pain_finished = gpGlobals->time + 0.5;

	// Hit by an axe
	if ( axhitme == 1 )
	{
		axhitme = 0;
		EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/axhit1.wav", 1, ATTN_NORM );
		return;
	}

	int rs = RANDOM_LONG( 1, 6 );
	pev->noise = MAKE_STRING( "" );
	if ( rs == 1 )
		pev->noise = MAKE_STRING( "player/pain1.wav" );
	else if ( rs == 2 )
		pev->noise = MAKE_STRING( "player/pain2.wav" );
	else if ( rs == 3 )
		pev->noise = MAKE_STRING( "player/pain3.wav" );
	else if ( rs == 4 )
		pev->noise = MAKE_STRING( "player/pain4.wav" );
	else if ( rs == 5 )
		pev->noise = MAKE_STRING( "player/pain5.wav" );
	else
		pev->noise = MAKE_STRING( "player/pain6.wav" );

	EMIT_SOUND( ENT( pev ), CHAN_VOICE, STRING( pev->noise ), 1, ATTN_NORM );
}

/* 
 *
 */
Vector VecVelocityForDamage( float flDamage )
{
	Vector vec( RANDOM_FLOAT( -100, 100 ), RANDOM_FLOAT( -100, 100 ), RANDOM_FLOAT( 200, 300 ) );

	if ( flDamage > -50 )
		vec = vec * 0.7;
	else if ( flDamage > -200 )
		vec = vec * 2;
	else
		vec = vec * 10;

	return vec;
}

int TrainSpeed( int iSpeed, int iMax )
{
	float fSpeed, fMax;
	int iRet = 0;

	fMax = (float)iMax;
	fSpeed = iSpeed;

	fSpeed = fSpeed / fMax;

	if ( iSpeed < 0 )
		iRet = TRAIN_BACK;
	else if ( iSpeed == 0 )
		iRet = TRAIN_NEUTRAL;
	else if ( fSpeed < 0.33 )
		iRet = TRAIN_SLOW;
	else if ( fSpeed < 0.66 )
		iRet = TRAIN_MEDIUM;
	else
		iRet = TRAIN_FAST;

	return iRet;
}

CBasePlayer::CBasePlayer( void )
{
	m_nFirstSpawn = TRUE;
	m_pszLastItem = NULL;
	m_DB_LastTimingTestTime = g_engfuncs.pfnTime() + 5;
}

void CBasePlayer :: DeathSound( void )
{
	// water death sounds
	if ( pev->waterlevel == 3 )
	{
		EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/h2odeath.wav", 1, ATTN_NONE );
		return;
	}

	switch ( RANDOM_LONG( 1, 4 ) )
	{
	case 1:
		EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/death1.wav", 1, ATTN_NORM );
		break;
	case 2:
		EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/death3.wav", 1, ATTN_NORM );
		break;
	case 3:
		EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/death4.wav", 1, ATTN_NORM );
		break;
	case 4:
		EMIT_SOUND( ENT( pev ), CHAN_VOICE, "player/death5.wav", 1, ATTN_NORM );
		break;
	}
}

// override takehealth
// bitsDamageType indicates type of damage healed. 
int CBasePlayer :: TakeHealth( float flHealth, int bitsDamageType )
{
	int iResult;

	// TFC: medikit heals past max health, and cures time-based damage
	if ( bitsDamageType & DMG_IGNORE_MAXHEALTH )
	{
		m_bitsDamageType &= ~( bitsDamageType & 0xff003fff );	// clears the healed time-based types
		pev->health += flHealth;
		iResult = TRUE;
	}
	else
	{
		iResult = CBaseMonster::TakeHealth( flHealth, bitsDamageType );
	}

	// Health heals leg damage
	if ( leg_damage > 0 )
	{
		if ( pev->health >= pev->max_health - 5 )
		{
			leg_damage = 0;
		}
		else
		{
			leg_damage -= ( pev->health + flHealth ) / 20;
			if ( leg_damage < 1 )
				leg_damage = 0;
		}

		TeamFortress_SetSpeed();
		iResult = TRUE;
	}

	return iResult;
}

//=========================================================
// TraceAttack
//=========================================================
void CBasePlayer :: TraceAttack( entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType )
{
	if ( !pev->takedamage )
		return;

	m_LastHitGroup = ptr->iHitgroup;

	CBasePlayer *pOther = (CBasePlayer *)CBaseEntity::Instance( pevAttacker );

	// Sniper rifle: headshots double, legshots slow you down
	if ( bitsDamageType & DMG_AIMED )
	{
		if ( ptr->iHitgroup == HITGROUP_HEAD )
		{
			flDamage *= 2;
			ClientPrint( pOther->pev, HUD_PRINTNOTIFY, "#Sniper_headshot" );
			pOther->deathtype = MAKE_STRING( "headshot" );
		}
		else if ( ptr->iHitgroup == HITGROUP_LEFTLEG || ptr->iHitgroup == HITGROUP_RIGHTLEG )
		{
			if ( !IsAlly( pOther ) || pOther == this || !( (int)gpGlobals->teamplay & TEAMPLAY_TEAMDAMAGE ) )
			{
				flDamage /= 2;
				leg_damage++;
				TeamFortress_SetSpeed();
				ClientPrint( pev, HUD_PRINTNOTIFY, "#Sniper_leginjury" );
			}
			ClientPrint( pOther->pev, HUD_PRINTNOTIFY, "#Sniper_legshot" );
		}
	}

	// No blood from teammates when team damage is off
	if ( IsAlly( pOther ) && pOther != this )
	{
		if ( bitsDamageType & DMG_BLAST )
		{
			if ( (int)gpGlobals->teamplay & TEAMPLAY_NOEXPLOSIVE )
			{
				goto nobleed;
			}
		}
		else if ( (int)gpGlobals->teamplay & TEAMPLAY_NODIRECT )
		{
			goto nobleed;
		}
	}

	SpawnBlood( ptr->vecEndPos, BloodColor(), flDamage );// a little surface blood.
	TraceBleed( flDamage, vecDir, ptr, bitsDamageType );

nobleed:
	AddMultiDamage( pevAttacker, this, flDamage, bitsDamageType );
}

/*
	Take some damage.  
	NOTE: each call to TakeDamage with bitsDamageType set to a time-based damage
	type will cause the damage time countdown to be reset.  Thus the ongoing effects of poison, radiation
	etc are implemented with subsequent calls to TakeDamage using DMG_GENERIC.
*/

#define ARMOR_RATIO	 0.2	// Armor Takes 80% of the damage
#define ARMOR_BONUS  0.5	// Each Point of Armor is work 1/x points of health

// Damage totals for the damage prototype (PrototypeWriteDamage)
float gfPrototypeLastTime;
float gfPrototypeLessDamage;
float gfPrototypeExtraDamage;
float gfPrototypeTotalDamage;

int CBasePlayer :: TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType )
{
	// have suit diagnose the problem - ie: report damage type
	int bitsDamage = bitsDamageType;
	int fTookDamage;
	BOOL bAttackerIsPlayer = FALSE;

	if ( !IsAlive() )
		return 0;

	// No damage during a ceasefire
	if ( cease_fire )
		return 0;

	CBaseEntity *pAttacker = CBaseEntity::Instance( pevAttacker );
	if ( !pAttacker )
		return 0;

	if ( pAttacker->Classify() == CLASS_PLAYER )
	{
		// Players without a team can't hurt anyone
		if ( !pAttacker->team_no )
			return 0;

		flDamage *= 0.9;

		// Quad damage
		if ( pAttacker->super_damage_finished > gpGlobals->time )
			flDamage *= 4;

		bAttackerIsPlayer = TRUE;
	}

	if ( tfc_balance_teams.value || tfc_balance_scores.value )
		flDamage = TeamEqualiseDamage( this, pAttacker, flDamage );

	int iDamage = flDamage;
	m_lastDamageAmount = iDamage;

	// Armor classes halve some damage types
	float take = flDamage;
	if ( armorclass )
	{
		if ( ( armorclass & AT_SAVESHOT ) && ( bitsDamageType & DMG_BULLET ) )
			take *= 0.5;
		if ( ( armorclass & AT_SAVENAIL ) && ( bitsDamageType & DMG_SLASH ) )
			take *= 0.5;
		if ( ( armorclass & AT_SAVEEXPLOSION ) && ( bitsDamageType & DMG_BLAST ) )
			take *= 0.5;
		if ( ( armorclass & AT_SAVEELECTRICITY ) && ( bitsDamageType & DMG_SHOCK ) )
			take *= 0.5;
		if ( ( armorclass & AT_SAVEFIRE ) && ( bitsDamageType & DMG_BURN ) )
			take *= 0.5;
	}

	// Armor
	if ( !( bitsDamageType & DMG_IGNOREARMOR ) )
	{
		float save = floor( pev->armortype * take );
		float armorUsed = save;

		// Team armor damage settings
		if ( bAttackerIsPlayer && IsAlly( pAttacker ) && pAttacker != this )
		{
			if ( bitsDamageType & DMG_BLAST )
			{
				if ( (int)gpGlobals->teamplay & TEAMPLAY_NOEXPARMOR )
					armorUsed = 0;
				else if ( (int)gpGlobals->teamplay & TEAMPLAY_HALFEXPARMOR )
					armorUsed = save * 0.5;
			}
			else
			{
				if ( (int)gpGlobals->teamplay & TEAMPLAY_NODIRECTARMOR )
					armorUsed = 0;
				else if ( (int)gpGlobals->teamplay & TEAMPLAY_HALFDIRECTARMOR )
					armorUsed = save * 0.5;
			}
		}

		// Armor used up
		if ( armorUsed >= pev->armorvalue )
		{
			save = pev->armortype * pev->armorvalue;
			armorUsed = pev->armorvalue;
			pev->armortype = 0;
			items &= ~( IT_ARMOR1 | IT_ARMOR2 | IT_ARMOR3 );
			armorclass = 0;
		}

		pev->armorvalue -= armorUsed;
		take -= save;
	}

	// Knockback
	if ( pevAttacker != pevInflictor && pevInflictor && pev->movetype == MOVETYPE_WALK &&
		 !( tfstate & TFSTATE_CANT_MOVE ) && pev->deadflag != 5 && !( bitsDamageType & DMG_SLASH ) )
	{
		immune_to_check = gpGlobals->time + flDamage / 20;

		Vector vecDir = pev->origin - ( pevInflictor->absmin + pevInflictor->absmax ) * 0.5;
		vecDir = vecDir.Normalize();

		// Heavies barely move
		if ( pev->playerclass == PC_HVYWEAP )
		{
			if ( flDamage > 50 )
				iDamage = iDamage / 4;
			else
				iDamage = 0;
		}

		// Small hits from someone else push harder
		if ( iDamage < 60 && bAttackerIsPlayer && pAttacker != this )
			pev->velocity = pev->velocity + vecDir * iDamage * 11;
		else
			pev->velocity = pev->velocity + vecDir * iDamage * 8;
	}

	// Invulnerable
	if ( invincible_finished >= gpGlobals->time )
	{
		if ( m_fInvincSound < gpGlobals->time )
		{
			EMIT_SOUND( ENT( pev ), CHAN_VOICE, "items/protect3.wav", 1, ATTN_NORM );
			m_fInvincSound = gpGlobals->time + 2;
		}
		return 0;
	}

	// Can't hurt yourself with this type
	if ( ( bitsDamageType & DMG_FREEZE ) && pAttacker == this )
		return 0;

	float flTake = (int)ceil( take );
	fTookDamage = CBaseMonster::TakeDamage( pevInflictor, pevAttacker, flTake, bitsDamageType );
	gfPrototypeTotalDamage += take;

	// Mirror team damage back onto the attacker (never for spies, who may be disguised)
	if ( bAttackerIsPlayer && IsAlly( pAttacker ) && pAttacker != this && pev->playerclass != PC_SPY )
	{
		if ( bitsDamageType & DMG_BLAST )
		{
			if ( (int)gpGlobals->teamplay & TEAMPLAY_FULLEXPMIRROR )
				pAttacker->TakeDamage( pAttacker->pev, pAttacker->pev, flTake, DMG_IGNOREARMOR );
			else if ( (int)gpGlobals->teamplay & TEAMPLAY_HALFEXPMIRROR )
				pAttacker->TakeDamage( pAttacker->pev, pAttacker->pev, (int)ceil( take ) / 2, DMG_IGNOREARMOR );
		}
		else
		{
			if ( (int)gpGlobals->teamplay & TEAMPLAY_FULLDIRMIRROR )
				pAttacker->TakeDamage( pAttacker->pev, pAttacker->pev, flTake, DMG_IGNOREARMOR );
			else if ( (int)gpGlobals->teamplay & TEAMPLAY_HALFDIRMIRROR )
				pAttacker->TakeDamage( pAttacker->pev, pAttacker->pev, (int)ceil( take ) / 2, DMG_IGNOREARMOR );
		}
	}

	// reset damage time countdown for each type of time based damage player just sustained
	for ( int i = 0; i < CDMG_TIMEBASED; i++ )
		if ( bitsDamageType & ( DMG_PARALYZE << i ) )
			m_rgbTimeBasedDamage[i] = 0;

	// tell director about it
	MESSAGE_BEGIN( MSG_SPEC, SVC_DIRECTOR );
		WRITE_BYTE( 9 );	// command length in bytes
		WRITE_BYTE( DRC_CMD_EVENT );	// take damage event
		WRITE_SHORT( ENTINDEX( this->edict() ) );	// index number of primary entity
		WRITE_SHORT( ENTINDEX( ENT( pevInflictor ) ) );	// index number of secondary entity
		WRITE_LONG( 5 );   // eventflags (priority and flags)
	MESSAGE_END();

	// how bad is it, doc?
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( !pPlayer || pPlayer->m_hObserverTarget != this )
			continue;

		// Spectators watching this player see their health
		MESSAGE_BEGIN( MSG_ONE, gmsgSpecHealth, NULL, pPlayer->edict() );
			WRITE_BYTE( pev->health > 0 ? (int)pev->health : 0 );
		MESSAGE_END();
	}

	m_bitsDamageType |= bitsDamage; // Save this so we can report it to the client
	m_bitsHUDDamage = -1;  // make sure the damage bits get resent

	// The HL suit reports are gone; only burning remains
	BOOL ffound = TRUE;
	while ( ffound && fTookDamage && bitsDamage )
	{
		ffound = FALSE;

		if ( bitsDamage & DMG_CLUB )
		{
			bitsDamage &= ~DMG_CLUB;
			ffound = TRUE;
		}
		if ( bitsDamage & ( DMG_FALL | DMG_CRUSH ) )
		{
			bitsDamage &= ~( DMG_FALL | DMG_CRUSH );
			ffound = TRUE;
		}
		if ( bitsDamage & DMG_BULLET )
		{
			bitsDamage &= ~DMG_BULLET;
			ffound = TRUE;
		}
		if ( bitsDamage & DMG_SLASH )
		{
			bitsDamage &= ~DMG_SLASH;
			ffound = TRUE;
		}
		if ( bitsDamage & DMG_SONIC )
		{
			bitsDamage &= ~DMG_SONIC;
			ffound = TRUE;
		}
		if ( bitsDamage & ( DMG_POISON | DMG_PARALYZE ) )
		{
			bitsDamage &= ~( DMG_POISON | DMG_PARALYZE );
			ffound = TRUE;
		}
		if ( bitsDamage & DMG_ACID )
		{
			bitsDamage &= ~DMG_ACID;
			ffound = TRUE;
		}
		if ( bitsDamage & DMG_NERVEGAS )
		{
			bitsDamage &= ~DMG_NERVEGAS;
			ffound = TRUE;
		}
		if ( bitsDamage & DMG_RADIATION )
		{
			bitsDamage &= ~DMG_RADIATION;
			ffound = TRUE;
		}
		if ( bitsDamage & DMG_SHOCK )
		{
			bitsDamage &= ~DMG_SHOCK;
			ffound = TRUE;
		}

		// Set on fire, unless under water
		if ( ( bitsDamage & DMG_IGNITE ) && pev->waterlevel < 2 )
			Ignite( pevInflictor, pevAttacker );
	}

	pev->punchangle.x = -2;

	return fTookDamage;
}

//=========================================================
// PackDeadPlayerItems - call this when a player dies to
// pack up the appropriate weapons and ammo items, and to
// destroy anything that shouldn't be packed.
//
// This is pretty brute force :(
//=========================================================
void CBasePlayer::PackDeadPlayerItems( void )
{
	int iWeaponRules;
	int iAmmoRules;
	int i;
	CBasePlayerItem *rgpPackWeapons[ 20 ];// 20 hardcoded for now. How to determine exactly how many weapons we have?
	int iPackAmmo[ MAX_AMMO_SLOTS + 1 ];
	int iPW = 0;// index into packweapons array
	int iPA = 0;// index into packammo array

	memset( rgpPackWeapons, 0, sizeof( rgpPackWeapons ) );
	memset( iPackAmmo, -1, sizeof( iPackAmmo ) );

	// TFC: nothing is dropped just after prematch ends
	if ( gpGlobals->time >= cb_prematch_time + 3 )
	{
		// get the game rules
		iWeaponRules = g_pGameRules->DeadPlayerWeapons( this );
		iAmmoRules = g_pGameRules->DeadPlayerAmmo( this );

		if ( iWeaponRules != GR_PLR_DROP_GUN_NO || iAmmoRules != GR_PLR_DROP_AMMO_NO )
		{
			// go through all of the weapons and make a list of the ones to pack
			for ( i = 0; i < MAX_ITEM_TYPES; i++ )
			{
				CBasePlayerItem *pPlayerItem = m_rgpPlayerItems[ i ];
				while ( pPlayerItem )
				{
					switch ( iWeaponRules )
					{
					case GR_PLR_DROP_GUN_ACTIVE:
						if ( m_pActiveItem && pPlayerItem == m_pActiveItem )
						{
							// this is the active item. Pack it.
							rgpPackWeapons[ iPW++ ] = pPlayerItem;
						}
						break;

					case GR_PLR_DROP_GUN_ALL:
						rgpPackWeapons[ iPW++ ] = pPlayerItem;
						break;

					default:
						break;
					}

					pPlayerItem = pPlayerItem->m_pNext;
				}
			}

			// now go through ammo and make a list of which types to pack.
			if ( iAmmoRules != GR_PLR_DROP_AMMO_NO )
			{
				for ( i = 0; i < MAX_AMMO_SLOTS; i++ )
				{
					if ( m_rgAmmo[ i ] > 0 )
					{
						// player has some ammo of this type.
						switch ( iAmmoRules )
						{
						case GR_PLR_DROP_AMMO_ALL:
							iPackAmmo[ iPA++ ] = i;
							break;

						case GR_PLR_DROP_AMMO_ACTIVE:
							if ( m_pActiveItem && i == m_pActiveItem->PrimaryAmmoIndex() )
							{
								// this is the primary ammo type for the active weapon
								iPackAmmo[ iPA++ ] = i;
							}
							else if ( m_pActiveItem && i == m_pActiveItem->SecondaryAmmoIndex() )
							{
								// this is the secondary ammo type for the active weapon
								iPackAmmo[ iPA++ ] = i;
							}
							break;

						default:
							break;
						}
					}
				}
			}

			// create a box to pack the stuff into.
			CWeaponBox *pWeaponBox = (CWeaponBox *)CBaseEntity::Create( "weaponbox", pev->origin, pev->angles, edict() );

			pWeaponBox->pev->angles.x = 0;// don't let weaponbox tilt.
			pWeaponBox->pev->angles.z = 0;

			pWeaponBox->SetThink( &CWeaponBox::Kill );
			pWeaponBox->pev->nextthink = gpGlobals->time + 120;

			// back these two lists up to their first elements
			iPA = 0;
			iPW = 0;

			// pack the ammo
			while ( iPackAmmo[ iPA ] != -1 )
			{
				pWeaponBox->PackAmmo( MAKE_STRING( CBasePlayerItem::AmmoInfoArray[ iPackAmmo[ iPA ] ].pszName ), m_rgAmmo[ iPackAmmo[ iPA ] ] );
				iPA++;
			}

			// now pack all of the items in the lists
			while ( rgpPackWeapons[ iPW ] )
			{
				// weapon unhooked from the player. Pack it into der box.
				pWeaponBox->PackWeapon( rgpPackWeapons[ iPW ] );

				iPW++;
			}

			// TFC: the box holds the player's TF ammo and armor
			if ( iAmmoRules != GR_PLR_DROP_AMMO_NO )
			{
				pWeaponBox->ammo_shells = ammo_shells;
				pWeaponBox->ammo_nails = ammo_nails;
				pWeaponBox->ammo_rockets = ammo_rockets;
				pWeaponBox->ammo_cells = ammo_cells;
				pWeaponBox->pev->armorvalue = pev->armorvalue;
			}

			pWeaponBox->pev->velocity = pev->velocity * 1.2;// weaponbox has player's velocity, then some.
		}
	}

	RemoveAllItems( FALSE );// now strip off everything that wasn't handled by the code above.
}

void CBasePlayer::RemoveAllItems( BOOL removeSuit )
{
	if (m_pActiveItem)
	{
		ResetAutoaim( );
		m_pActiveItem->Holster( );
		m_pActiveItem = NULL;
	}

	// TFC: remember the last weapon by name, for "lastinv" after respawning
	if ( m_pLastItem )
		m_pszLastItem = m_pLastItem->DB_GetItemName();
	m_pLastItem = NULL;

	if ( m_pTank != NULL )
	{
		m_pTank->Use( this, this, USE_OFF, 0 );
		m_pTank = NULL;
	}

	int i;
	CBasePlayerItem *pPendingItem;
	for (i = 0; i < MAX_ITEM_TYPES; i++)
	{
		m_pActiveItem = m_rgpPlayerItems[i];
		while (m_pActiveItem)
		{
			pPendingItem = m_pActiveItem->m_pNext; 
			m_pActiveItem->Drop( );
			m_pActiveItem = pPendingItem;
		}
		m_rgpPlayerItems[i] = NULL;
	}
	m_pActiveItem = NULL;

	pev->viewmodel		= 0;
	pev->weaponmodel	= 0;
	
	if ( removeSuit )
		pev->weapons = 0;
	else
		pev->weapons &= ~WEAPON_ALLWEAPONS;

	for ( i = 0; i < MAX_AMMO_SLOTS;i++)
		m_rgAmmo[i] = 0;

	UpdateClientData();
	// send Selected Weapon Message to our client
	MESSAGE_BEGIN( MSG_ONE, gmsgCurWeapon, NULL, pev );
		WRITE_BYTE(0);
		WRITE_BYTE(0);
		WRITE_BYTE(0);
	MESSAGE_END();
}

/*
 * GLOBALS ASSUMED SET:  g_ulModelIndexPlayer
 *
 * ENTITY_METHOD(PlayerDie)
 */
entvars_t *g_pevLastInflictor;  // Set in combat.cpp.  Used to pass the damage inflictor for death messages.
								// Better solution:  Add as parameter to all Killed() functions.

void CBasePlayer::Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib )
{
	CSound *pSound;

	// Remove anything attached to the player model (flames, etc.)
	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_KILLPLAYERATTACHMENTS );
		WRITE_BYTE( (BYTE)ENTINDEX( edict() ) );
	MESSAGE_END();

	m_nFirstSpawn = FALSE;
	pev->iuser3 = 0;

	// Holster weapon immediately, to allow it to cleanup
	if ( m_pActiveItem )
		m_pActiveItem->Holster( );

	g_pGameRules->PlayerKilled( this, pevAttacker, g_pevLastInflictor );

	if ( m_pTank != NULL )
	{
		m_pTank->Use( this, this, USE_OFF, 0 );
		m_pTank = NULL;
	}

	// this client isn't going to be thinking for a while, so reset the sound until they respawn
	pSound = CSoundEnt::SoundPointerForIndex( CSoundEnt::ClientSoundIndex( edict() ) );
	{
		if ( pSound )
		{
			pSound->Reset();
		}
	}

	SetAnimation( PLAYER_DIE );

	// Powerups end
	items &= ~IT_INVISIBILITY;
	invisible_finished = 0;
	invincible_finished = 0;
	super_damage_finished = 0;
	radsuit_finished = 0;
	pev->modelindex = g_ulModelIndexPlayer;    // don't use eyes

	if ( m_iBeingTeleported )
		PlayerStoppedTeleporting( this );

	// Died of an infection you gave yourself: the medic who infected you gets the frag
	if ( ( tfstate & TFSTATE_INFECTED ) && pev->enemy == pev->pContainingEntity )
	{
		CBaseEntity *pTimer = FindTimer( TF_TIMER_INFECTION );
		if ( pTimer )
		{
			CBaseEntity *pInfector = CBaseEntity::Instance( pTimer->pev->enemy );
			pInfector->real_frags++;
			if ( pInfector->team_no )
				teamfrags[ pInfector->team_no ]++;
			pInfector->pev->frags = pInfector->real_frags;
		}
	}

	TeamFortress_RemoveTimers();
	ResetMenu();

	tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );

	pev->deadflag = DEAD_DYING;
	pev->movetype = MOVETYPE_TOSS;
	ClearBits( pev->flags, FL_ONGROUND );
	if ( pev->velocity.z < 10 )
		pev->velocity.z += RANDOM_FLOAT( 0, 300 );

	// clear out the suit message cache so we don't keep chattering
	if ( pev->weapons & ( 1 << WEAPON_SUIT ) )
	{
		if ( !g_pGameRules->IsMultiplayer() )
		{
			for ( int i = 0; i < CSUITPLAYLIST; i++ )
				m_rgSuitPlayList[i] = 0;
		}
	}

	// send "health" update message to zero
	m_iClientHealth = 0;
	MESSAGE_BEGIN( MSG_ONE, gmsgHealth, NULL, pev );
		WRITE_BYTE( m_iClientHealth );
	MESSAGE_END();

	// Tell Ammo Hud that the player is dead
	MESSAGE_BEGIN( MSG_ONE, gmsgCurWeapon, NULL, pev );
		WRITE_BYTE( 0 );
		WRITE_BYTE( 0XFF );
		WRITE_BYTE( 0xFF );
	MESSAGE_END();

	// reset FOV
	m_iFOV = m_iClientFOV = 0;
	pev->fov = 0;

	MESSAGE_BEGIN( MSG_ONE, gmsgSetFOV, NULL, pev );
		WRITE_BYTE( 0 );
	MESSAGE_END();

	if ( ( pev->health < -40 && iGib != GIB_NEVER ) || iGib == GIB_ALWAYS )
	{
		pev->solid = SOLID_NOT;
		GibMonster();	// This clears pev->model
		pev->effects |= EF_NODRAW;
	}
	else
	{
		DeathSound();

		is_detpacking = FALSE;

		pev->angles.x = 0;
		pev->angles.z = 0;

		m_iRespawnFrames = 0;
		SetThink( &CBasePlayer::PlayerDeathThink );
		pev->nextthink = gpGlobals->time + 0.1;
	}

	// a suicide (ClientKill just armed the suicide timer) waits it out
	TeamFortress_SetupRespawn( m_fNextSuicideTime > gpGlobals->time );
}


// Set the activity based on an event or current state
// TFC: animation names for the sequence cache (m_iCurrentAnimationState)
char *g_PlayerAnimationNames[] =
{
	"",
	"ref_aim_%s",
	"crouch_aim_%s",
	"ref_shoot_%s",
	"crouch_shoot_%s",
	"ref_aim_sniper",
	"crouch_aim_sniper",
	"deep_idle",
};

#define ANIM_REF_AIM			1
#define ANIM_CROUCH_AIM			2
#define ANIM_REF_SHOOT			3
#define ANIM_CROUCH_SHOOT		4
#define ANIM_REF_AIM_SNIPER		5
#define ANIM_CROUCH_AIM_SNIPER	6

// Looks up (and caches) the sequence for one of the animation names
static int LookupAnimationState( CBasePlayer *pPlayer, int iState )
{
	if ( pPlayer->m_iCurrentAnimationState != iState || !pPlayer->m_iCurrentAnimationSequence )
	{
		char szAnim[64];
		sprintf( szAnim, g_PlayerAnimationNames[iState], pPlayer->m_szAnimExtention );
		pPlayer->m_iCurrentAnimationSequence = pPlayer->LookupSequence( szAnim );
		pPlayer->m_iCurrentAnimationState = iState;
	}

	return pPlayer->m_iCurrentAnimationSequence;
}

void CBasePlayer::SetAnimation( PLAYER_ANIM playerAnim )
{
	int animDesired;
	float speed;

	speed = pev->velocity.Length2D();

	if ( pev->flags & FL_FROZEN )
	{
		speed = 0;
		playerAnim = PLAYER_IDLE;
	}

	switch ( playerAnim )
	{
	case PLAYER_JUMP:
		m_IdealActivity = ACT_HOP;
		break;

	case PLAYER_SUPERJUMP:
		m_IdealActivity = ACT_LEAP;
		break;

	case PLAYER_DIE:
		m_IdealActivity = ACT_DIESIMPLE;
		m_IdealActivity = GetDeathActivity( );
		break;

	case PLAYER_ATTACK1:
		switch ( m_Activity )
		{
		case ACT_HOVER:
		case ACT_SWIM:
		case ACT_HOP:
		case ACT_LEAP:
		case ACT_DIESIMPLE:
			m_IdealActivity = m_Activity;
			break;
		default:
			m_IdealActivity = ACT_RANGE_ATTACK1;
			break;
		}
		break;

	// TFC: spy feigning death picks a random death
	case PLAYER_FEIGN:
		{
			Activity act;
			switch ( RANDOM_LONG( 0, 7 ) )
			{
			case 0:		act = ACT_DIESIMPLE; break;
			case 1:		act = ACT_DIEBACKWARD; break;
			case 2:		act = ACT_DIEFORWARD; break;
			case 3:		act = ACT_DIEVIOLENT; break;
			case 4:		act = ACT_DIE_HEADSHOT; break;
			case 5:		act = ACT_DIE_CHESTSHOT; break;
			case 6:		act = ACT_DIE_GUTSHOT; break;
			default:	act = ACT_DIE_BACKSHOT; break;
			}
			m_IdealActivity = act;

			// Not every model has every death
			if ( LookupActivity( act ) == -1 )
				m_IdealActivity = ACT_DIESIMPLE;
		}
		break;

	case PLAYER_IDLE:
	case PLAYER_WALK:
		if ( !FBitSet( pev->flags, FL_ONGROUND ) && ( m_Activity == ACT_HOP || m_Activity == ACT_LEAP ) )	// Still jumping
		{
			m_IdealActivity = m_Activity;
		}
		else if ( pev->waterlevel > 1 )
		{
			if ( speed == 0 )
				m_IdealActivity = ACT_HOVER;
			else
				m_IdealActivity = ACT_SWIM;
		}
		else
		{
			m_IdealActivity = ACT_WALK;
		}
		break;
	}

	switch ( m_IdealActivity )
	{
	case ACT_HOVER:
	case ACT_LEAP:
	case ACT_SWIM:
	case ACT_HOP:
	case ACT_DIESIMPLE:
	default:
		if ( m_Activity == m_IdealActivity )
			return;
		m_Activity = m_IdealActivity;

		animDesired = LookupActivity( m_Activity );
		// Already using the desired animation?
		if ( pev->sequence == animDesired )
			return;

		pev->gaitsequence = 0;
		pev->sequence = animDesired;
		pev->frame = 0;
		ResetSequenceInfo( );
		return;

	case ACT_RANGE_ATTACK1:
		animDesired = LookupAnimationState( this, FBitSet( pev->flags, FL_DUCKING ) ? ANIM_CROUCH_SHOOT : ANIM_REF_SHOOT );
		if ( animDesired == -1 )
			animDesired = 0;

		if ( pev->sequence != animDesired || !m_fSequenceLoops )
		{
			pev->frame = 0;
		}

		if ( !m_fSequenceLoops )
		{
			pev->effects |= EF_NOINTERP;
		}

		m_Activity = m_IdealActivity;

		pev->sequence = animDesired;
		ResetSequenceInfo( );
		break;

	case ACT_WALK:
		if ( m_Activity != ACT_RANGE_ATTACK1 || m_fSequenceFinished )
		{
			// Snipers aiming hold the rifle up
			if ( pev->playerclass == PC_SNIPER && ( tfstate & TFSTATE_AIMING ) )
				animDesired = LookupAnimationState( this, FBitSet( pev->flags, FL_DUCKING ) ? ANIM_CROUCH_AIM_SNIPER : ANIM_REF_AIM_SNIPER );
			else
				animDesired = LookupAnimationState( this, FBitSet( pev->flags, FL_DUCKING ) ? ANIM_CROUCH_AIM : ANIM_REF_AIM );

			if ( animDesired == -1 )
				animDesired = 0;
			m_Activity = ACT_WALK;
		}
		else
		{
			animDesired = pev->sequence;
		}
	}

	if ( FBitSet( pev->flags, FL_DUCKING ) )
	{
		if ( speed == 0 )
		{
			pev->gaitsequence = LookupActivity( ACT_CROUCHIDLE );
			// pev->gaitsequence = LookupActivity( ACT_CROUCH );
		}
		else
		{
			pev->gaitsequence = LookupActivity( ACT_CROUCH );
		}
	}
	else if ( speed > 220 )
	{
		pev->gaitsequence = LookupActivity( ACT_RUN );
	}
	else if ( speed > 0 )
	{
		pev->gaitsequence = LookupActivity( ACT_WALK );
	}
	else
	{
		// pev->gaitsequence = LookupActivity( ACT_WALK );
		pev->gaitsequence = LookupSequence( "deep_idle" );
	}

	// Already using the desired animation?
	if ( pev->sequence == animDesired )
		return;

	//ALERT( at_console, "Set animation to %d\n", animDesired );
	// Reset to first frame of desired animation
	pev->sequence = animDesired;
	pev->frame = 0;
	ResetSequenceInfo( );
}



/*
===========
WaterMove
============
*/
#define AIRTIME	12		// lung full of air lasts this many seconds

void CBasePlayer::WaterMove()
{
	int air;

	if (pev->movetype == MOVETYPE_NOCLIP)
		return;

	if (pev->health < 0)
		return;

	// waterlevel 0 - not in water
	// waterlevel 1 - feet in water
	// waterlevel 2 - waist in water
	// waterlevel 3 - head in water

	if (pev->waterlevel != 3) 
	{
		// not underwater
		
		// play 'up for air' sound
		if (pev->air_finished < gpGlobals->time)
			EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/pl_wade1.wav", 1, ATTN_NORM);
		else if (pev->air_finished < gpGlobals->time + 9)
			EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/pl_wade2.wav", 1, ATTN_NORM);

		pev->air_finished = gpGlobals->time + AIRTIME;
		pev->dmg = 2;

		// if we took drowning damage, give it back slowly
		if (m_idrowndmg > m_idrownrestored)
		{
			// set drowning damage bit.  hack - dmg_drownrecover actually
			// makes the time based damage code 'give back' health over time.
			// make sure counter is cleared so we start count correctly.
			
			// NOTE: this actually causes the count to continue restarting
			// until all drowning damage is healed.

			m_bitsDamageType |= DMG_DROWNRECOVER;
			m_bitsDamageType &= ~DMG_DROWN;
			m_rgbTimeBasedDamage[itbd_DrownRecover] = 0;
		}

	}
	else
	{	// fully under water
		// stop restoring damage while underwater
		m_bitsDamageType &= ~DMG_DROWNRECOVER;
		m_rgbTimeBasedDamage[itbd_DrownRecover] = 0;

		if (pev->air_finished < gpGlobals->time)		// drown!
		{
			if (pev->pain_finished < gpGlobals->time)
			{
				// take drowning damage
				pev->dmg += 1;
				if (pev->dmg > 5)
					pev->dmg = 5;
				TakeDamage(VARS(eoNullEntity), VARS(eoNullEntity), pev->dmg, DMG_DROWN);
				pev->pain_finished = gpGlobals->time + 1;
				
				// track drowning damage, give it back when
				// player finally takes a breath

				m_idrowndmg += pev->dmg;
			} 
		}
		else
		{
			m_bitsDamageType &= ~DMG_DROWN;
		}
	}

	if (!pev->waterlevel)
	{
		if (FBitSet(pev->flags, FL_INWATER))
		{       
			ClearBits(pev->flags, FL_INWATER);
		}
		return;
	}
	
	// make bubbles

	air = (int)(pev->air_finished - gpGlobals->time);
	if (!RANDOM_LONG(0,0x1f) && RANDOM_LONG(0,AIRTIME-1) >= air)
	{
		switch (RANDOM_LONG(0,3))
			{
			case 0:	EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim1.wav", 0.8, ATTN_NORM); break;
			case 1:	EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim2.wav", 0.8, ATTN_NORM); break;
			case 2:	EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim3.wav", 0.8, ATTN_NORM); break;
			case 3:	EMIT_SOUND(ENT(pev), CHAN_BODY, "player/pl_swim4.wav", 0.8, ATTN_NORM); break;
		}
	}

	if (pev->watertype == CONTENT_LAVA)		// do damage
	{
		if (pev->dmgtime < gpGlobals->time)
			TakeDamage(VARS(eoNullEntity), VARS(eoNullEntity), 10 * pev->waterlevel, DMG_BURN);
	}
	else if (pev->watertype == CONTENT_SLIME)		// do damage
	{
		pev->dmgtime = gpGlobals->time + 1;
		TakeDamage(VARS(eoNullEntity), VARS(eoNullEntity), 4 * pev->waterlevel, DMG_ACID);
	}
	
	if (!FBitSet(pev->flags, FL_INWATER))
	{
		SetBits(pev->flags, FL_INWATER);
		pev->dmgtime = 0;
	}
}


// TRUE if the player is attached to a ladder
BOOL CBasePlayer::IsOnLadder( void )
{ 
	return ( pev->movetype == MOVETYPE_FLY );
}

void CBasePlayer::PlayerDeathThink( void )
{
	float flForward;

	is_detpacking = FALSE;

	if ( FBitSet( pev->flags, FL_ONGROUND ) )
	{
		flForward = pev->velocity.Length() - 20;
		if ( flForward <= 0 )
			pev->velocity = g_vecZero;
		else
			pev->velocity = flForward * pev->velocity.Normalize();
	}

	if ( pev->modelindex && ( !m_fSequenceFinished ) && ( pev->deadflag == 5 || pev->deadflag == DEAD_DYING ) )
	{
		StudioFrameAdvance( );

		m_iRespawnFrames++;				// Note, these aren't necessarily real "frames", so behavior is dependent on # of client movement commands
		if ( m_iRespawnFrames < 120 )   // Animations should be no longer than this
			return;
	}

	// once we're done animating our death and we're on the ground, we want to set movetype to None so our dead body won't do collisions and stuff anymore
	// this prevents a bug where the dead body would go to a player's head if he walked over it while the dead player was clicking their button to respawn
	if ( pev->movetype != MOVETYPE_NONE && FBitSet( pev->flags, FL_ONGROUND ) )
		pev->movetype = MOVETYPE_NONE;

	// deadflag 5: the death animation is held
	if ( pev->deadflag == 5 )
	{
		pev->framerate = 0;
		pev->effects |= EF_NOINTERP;
		pev->framerate = 0.0;
		return;
	}

	if ( HasWeapons() && m_fDontPackItemsUntil < gpGlobals->time )
	{
		// we drop the guns here because weapons that have an area effect and can kill their user
		// will sometimes crash coming back from CBasePlayer::Killed() if they kill their owner because the
		// player class sometimes is freed. It's safer to manipulate the weapons once we know
		// we aren't calling into any of their code anymore through the player pointer.
		PackDeadPlayerItems();
	}

	if ( pev->deadflag == DEAD_DYING )
	{
		pev->deadflag = DEAD_DEAD;
		pev->solid = SOLID_NOT;
	}

	StopAnimation();

	pev->effects |= EF_NOINTERP;
	pev->framerate = 0.0;

	BOOL fAnyButtonDown = ( pev->button & ~IN_SCORE );

	// wait for all buttons released
	if ( pev->deadflag == DEAD_DEAD )
	{
		if ( !fAnyButtonDown )
		{
			if ( g_pGameRules->FPlayerCanRespawn( this ) )
			{
				m_fDeadTime = gpGlobals->time;
				pev->deadflag = DEAD_RESPAWNABLE;
			}

			tfstate &= ~TFSTATE_RESPAWN_READY;
		}
		return;
	}

	// TFC: pressing a button marks the player ready; they respawn once the delay is over
	if ( fAnyButtonDown )
		tfstate |= TFSTATE_RESPAWN_READY;

	if ( ( tfstate & TFSTATE_RESPAWN_READY ) && respawn_time <= gpGlobals->time )
	{
		pev->button = 0;
		m_iRespawnFrames = 0;
		pev->solid = SOLID_SLIDEBOX;

		//ALERT(at_console, "Respawn\n");

		respawn( pev, !( m_afPhysicsFlags & PFLAG_OBSERVER ) && pev->deadflag );// don't copy a corpse if we're in deathcam.
		pev->nextthink = -1;
	}
}

//=========================================================
// StartDeathCam - find an intermission spot and send the
// player off into observer mode
//=========================================================
void CBasePlayer::StartDeathCam( void )
{
	edict_t *pSpot, *pNewSpot;
	int iRand;

	if ( pev->view_ofs == g_vecZero )
	{
		// don't accept subsequent attempts to StartDeathCam()
		return;
	}

	pSpot = FIND_ENTITY_BY_CLASSNAME( NULL, "info_intermission");	

	if ( !FNullEnt( pSpot ) )
	{
		// at least one intermission spot in the world.
		iRand = RANDOM_LONG( 0, 3 );

		while ( iRand > 0 )
		{
			pNewSpot = FIND_ENTITY_BY_CLASSNAME( pSpot, "info_intermission");
			
			if ( pNewSpot )
			{
				pSpot = pNewSpot;
			}

			iRand--;
		}

		CopyToBodyQue( pev );

		// TFC: become a spectator at the intermission spot
		StartObserver( pSpot->v.origin, pSpot->v.v_angle );
	}
	else
	{
		// no intermission spot. Push them up in the air, looking down at their corpse
		TraceResult tr;
		CopyToBodyQue( pev );
		UTIL_TraceLine( pev->origin, pev->origin + Vector( 0, 0, 128 ), ignore_monsters, edict(), &tr );

		StartObserver( tr.vecEndPos, UTIL_VecToAngles( tr.vecEndPos - pev->origin ) );
	}
}

void CBasePlayer::StartObserver( Vector vecPosition, Vector vecViewAngle )
{
	// clear any clientside entities attached to this player
	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_KILLPLAYERATTACHMENTS );
		WRITE_BYTE( (BYTE)entindex() );
	MESSAGE_END();

	// Holster weapon immediately, to allow it to cleanup
	if (m_pActiveItem)
		m_pActiveItem->Holster( );

	if ( m_pTank != NULL )
	{
		m_pTank->Use( this, this, USE_OFF, 0 );
		m_pTank = NULL;
	}

	// TFC: stop any teleport in progress
	if ( m_iBeingTeleported )
		PlayerStoppedTeleporting( this );
	TeleporterResetEffects( this );

	// TFC: lose powerups
	items = 0;
	invisible_finished = 0;
	invincible_finished = 0;
	super_damage_finished = 0;
	radsuit_finished = 0;

	// an infected player leaving gives the medic who infected them the frag
	if ( ( tfstate & TFSTATE_INFECTED ) && pev->enemy == edict() )
	{
		CBaseEntity *pTimer = FindTimer( TF_TIMER_INFECTION );
		if ( pTimer )
			( (CBasePlayer *)CBaseEntity::Instance( pTimer->pev->enemy ) )->TF_AddFrags( 1 );
	}

	// clear out the suit message cache so we don't keep chattering
	SetSuitUpdate(NULL, FALSE, 0);

	// Tell Ammo Hud that the player is dead
	MESSAGE_BEGIN( MSG_ONE, gmsgCurWeapon, NULL, pev );
		WRITE_BYTE(0);
		WRITE_BYTE(0XFF);
		WRITE_BYTE(0xFF);
	MESSAGE_END();

	// reset FOV
	m_iFOV = m_iClientFOV = 0;
	pev->fov = m_iFOV;
	MESSAGE_BEGIN( MSG_ONE, gmsgSetFOV, NULL, pev );
		WRITE_BYTE(0);
	MESSAGE_END();

	// Setup flags
	m_iHideHUD = (HIDEHUD_HEALTH | HIDEHUD_WEAPONS);
	m_afPhysicsFlags |= PFLAG_OBSERVER;
	pev->effects = EF_NODRAW;
	pev->view_ofs = g_vecZero;
	pev->angles = pev->v_angle = vecViewAngle;
	pev->fixangle = TRUE;
	pev->solid = SOLID_NOT;
	pev->takedamage = DAMAGE_NO;
	pev->movetype = MOVETYPE_NONE;
	ClearBits( m_afPhysicsFlags, PFLAG_DUCKING );
	ClearBits( pev->flags, FL_DUCKING );
	pev->deadflag = DEAD_RESPAWNABLE;
	pev->health = 1;

	// TFC: leave the team, taking this player's frags off the team score
	current_menu = 0;
	respawn_time = 0;

	// Clear out the status bar
	m_fInitHUD = TRUE;

	if ( team_no )
		teamfrags[team_no] -= real_frags;
	real_frags = 0;
	pev->frags = 0;

	int iOldTeam = team_no;
	team_no = 0;
	pev->team =  0;
	MESSAGE_BEGIN( MSG_ALL, gmsgTeamInfo );
		WRITE_BYTE( ENTINDEX(edict()) );
		WRITE_STRING( "" );
	MESSAGE_END();
	TeamFortress_TeamIncreaseScore( iOldTeam, 0 );

	pev->playerclass = 0;
	tfstate &= ~( TFSTATE_RANDOMPC | TFSTATE_GRENTHROWING );

	// Remove all the player's stuff
	RemoveAllItems( FALSE );
	CleanupOnPlayerDisconnection();

	// Move them to the new position
	UTIL_SetOrigin( pev, vecPosition );

	// Find a player to watch
	m_flNextObserverInput = 0;
	Observer_SetMode( m_iObserverLastMode );

	tfstate = 0;
	TeamFortress_SetSpeed();

	// Tell all clients this player is now a spectator
	MESSAGE_BEGIN( MSG_ALL, gmsgSpectator );
		WRITE_BYTE( ENTINDEX( edict() ) );
		WRITE_BYTE( 1 );
	MESSAGE_END();
}

// 
// PlayerUse - handles USE keypress
//
#define	PLAYER_SEARCH_RADIUS	(float)64

void CBasePlayer::PlayerUse ( void )
{
	if ( IsObserver() )
		return;

	// Was use pressed or released?
	if ( ! ((pev->button | m_afButtonPressed | m_afButtonReleased) & IN_USE) )
		return;

	// Hit Use on a train?
	if ( m_afButtonPressed & IN_USE )
	{
		if ( m_pTank != NULL )
		{
			// Stop controlling the tank
			// TODO: Send HUD Update
			m_pTank->Use( this, this, USE_OFF, 0 );
			m_pTank = NULL;
			return;
		}
		else
		{
			if ( m_afPhysicsFlags & PFLAG_ONTRAIN )
			{
				m_afPhysicsFlags &= ~PFLAG_ONTRAIN;
				m_iTrain = TRAIN_NEW|TRAIN_OFF;
				return;
			}
			else
			{	// Start controlling the train!
				CBaseEntity *pTrain = CBaseEntity::Instance( pev->groundentity );

				if ( pTrain && !(pev->button & IN_JUMP) && FBitSet(pev->flags, FL_ONGROUND) && (pTrain->ObjectCaps() & FCAP_DIRECTIONAL_USE) && pTrain->OnControls(pev) )
				{
					m_afPhysicsFlags |= PFLAG_ONTRAIN;
					m_iTrain = TrainSpeed(pTrain->pev->speed, pTrain->pev->impulse);
					m_iTrain |= TRAIN_NEW;
					EMIT_SOUND( ENT(pev), CHAN_ITEM, "plats/train_use1.wav", 0.8, ATTN_NORM);
					return;
				}
			}
		}
	}

	CBaseEntity *pObject = NULL;
	CBaseEntity *pClosest = NULL;
	Vector		vecLOS;
	float flMaxDot = VIEW_FIELD_NARROW;
	float flDot;

	UTIL_MakeVectors ( pev->v_angle );// so we know which way we are facing
	
	while ((pObject = UTIL_FindEntityInSphere( pObject, pev->origin, PLAYER_SEARCH_RADIUS )) != NULL)
	{

		if (pObject->ObjectCaps() & (FCAP_IMPULSE_USE | FCAP_CONTINUOUS_USE | FCAP_ONOFF_USE))
		{
			// !!!PERFORMANCE- should this check be done on a per case basis AFTER we've determined that
			// this object is actually usable? This dot is being done for every object within PLAYER_SEARCH_RADIUS
			// when player hits the use key. How many objects can be in that area, anyway? (sjb)
			vecLOS = (VecBModelOrigin( pObject->pev ) - (pev->origin + pev->view_ofs));
			
			// This essentially moves the origin of the target to the corner nearest the player to test to see 
			// if it's "hull" is in the view cone
			vecLOS = UTIL_ClampVectorToBox( vecLOS, pObject->pev->size * 0.5 );
			
			flDot = DotProduct (vecLOS , gpGlobals->v_forward);
			if (flDot > flMaxDot )
			{// only if the item is in front of the user
				pClosest = pObject;
				flMaxDot = flDot;
//				ALERT( at_console, "%s : %f\n", STRING( pObject->pev->classname ), flDot );
			}
//			ALERT( at_console, "%s : %f\n", STRING( pObject->pev->classname ), flDot );
		}
	}
	pObject = pClosest;

	// Found an object
	if (pObject )
	{
		//!!!UNDONE: traceline here to prevent USEing buttons through walls			
		int caps = pObject->ObjectCaps();

		if ( m_afButtonPressed & IN_USE )
			EMIT_SOUND( ENT(pev), CHAN_ITEM, "common/wpn_select.wav", 0.4, ATTN_NORM);

		if ( ( (pev->button & IN_USE) && (caps & FCAP_CONTINUOUS_USE) ) ||
			 ( (m_afButtonPressed & IN_USE) && (caps & (FCAP_IMPULSE_USE|FCAP_ONOFF_USE)) ) )
		{
			if ( caps & FCAP_CONTINUOUS_USE )
				m_afPhysicsFlags |= PFLAG_USING;

			pObject->Use( this, this, USE_SET, 1 );
		}
		// UNDONE: Send different USE codes for ON/OFF.  Cache last ONOFF_USE object to send 'off' if you turn away
		else if ( (m_afButtonReleased & IN_USE) && (pObject->ObjectCaps() & FCAP_ONOFF_USE) )	// BUGBUG This is an "off" use
		{
			pObject->Use( this, this, USE_SET, 0 );
		}
	}
	else
	{
		if ( m_afButtonPressed & IN_USE )
			EMIT_SOUND( ENT(pev), CHAN_ITEM, "common/wpn_denyselect.wav", 0.4, ATTN_NORM);
	}
}



void CBasePlayer::Jump()
{
	if (FBitSet(pev->flags, FL_WATERJUMP))
		return;
	
	if (pev->waterlevel >= 2)
	{
		return;
	}

	// jump velocity is sqrt( height * gravity * 2)

	// If this isn't the first frame pressing the jump button, break out.
	if ( !FBitSet( m_afButtonPressed, IN_JUMP ) )
		return;         // don't pogo stick

	if ( !(pev->flags & FL_ONGROUND) || !pev->groundentity )
	{
		return;
	}

// many features in this function use v_forward, so makevectors now.
	UTIL_MakeVectors (pev->angles);

	// ClearBits(pev->flags, FL_ONGROUND);		// don't stairwalk
	
	SetAnimation( PLAYER_JUMP );

	if ( ( FBitSet( pev->flags, FL_DUCKING ) || ( m_afPhysicsFlags & PFLAG_DUCKING ) ) &&
		m_fLongJump &&
		( pev->button & IN_DUCK ) &&
		( gpGlobals->time - m_flDuckTime < 1 ) &&
		pev->velocity.Length() > 50 )
	{
		SetAnimation( PLAYER_SUPERJUMP );
	}

	// If you're standing on a conveyor, add it's velocity to yours (for momentum)
	entvars_t *pevGround = VARS(pev->groundentity);
	if ( pevGround && (pevGround->flags & FL_CONVEYOR) )
	{
		pev->velocity = pev->velocity + pev->basevelocity;
	}
}



// This is a glorious hack to find free space when you've crouched into some solid space
// Our crouching collisions do not work correctly for some reason and this is easier
// than fixing the problem :(
void FixPlayerCrouchStuck( edict_t *pPlayer )
{
	TraceResult trace;

	// Move up as many as 18 pixels if the player is stuck.
	for ( int i = 0; i < 18; i++ )
	{
		UTIL_TraceHull( pPlayer->v.origin, pPlayer->v.origin, dont_ignore_monsters, head_hull, pPlayer, &trace );
		if ( trace.fStartSolid )
			pPlayer->v.origin.z ++;
		else
			break;
	}
}

void CBasePlayer::Duck( )
{
	if (pev->button & IN_DUCK) 
	{
		if ( m_IdealActivity != ACT_LEAP )
		{
			SetAnimation( PLAYER_WALK );
		}
	}
}

//
// ID's player as such.
//
int  CBasePlayer::Classify ( void )
{
	return CLASS_PLAYER;
}





//Player ID










#define CLIMB_SHAKE_FREQUENCY	22	// how many frames in between screen shakes when climbing
#define	MAX_CLIMB_SPEED			200	// fastest vertical climbing speed possible
#define	CLIMB_SPEED_DEC			15	// climbing deceleration rate
#define	CLIMB_PUNCH_X			-7  // how far to 'punch' client X axis when climbing
#define CLIMB_PUNCH_Z			7	// how far to 'punch' client Z axis when climbing

void CBasePlayer::PreThink(void)
{
	int buttonsChanged = (m_afButtonLast ^ pev->button);	// These buttons have changed this frame
	
	// Debounced button codes for pressed/released
	// UNDONE: Do we need auto-repeat?
	m_afButtonPressed =  buttonsChanged & pev->button;		// The changed ones still down are "pressed"
	m_afButtonReleased = buttonsChanged & (~pev->button);	// The ones not down are "released"

	// TFC: jump on the team menu auto-assigns a team
	if ( current_menu == MENU_TEAM && ( m_afButtonPressed & IN_JUMP ) )
	{
		ResetMenu();
		TeamFortress_TeamPutPlayerInTeam();
		m_afButtonPressed &= ~IN_JUMP;
	}

	g_pGameRules->PlayerThink( this );

	if ( g_fGameOver )
		return;         // intermission or finale

	// using something slows you down
	if ( ( pev->flags & FL_ONGROUND ) && ( ( m_afPhysicsFlags & PFLAG_USING ) || ( m_afButtonPressed & IN_USE ) ) )
	{
		pev->velocity = pev->velocity * 0.3;
		m_afPhysicsFlags &= ~PFLAG_USING;
	}

	ItemPreFrame( );
	WaterMove();

	m_iHideHUD |= HIDEHUD_FLASHLIGHT;	// no flashlight in TFC

	// JOHN: checks if new client data (for HUD and view control) needs to be sent to the client
	UpdateClientData();
	
	CheckTimeBasedDamage();

	// Observer Button Handling
	if ( IsObserver() )
	{
		Observer_HandleButtons();
		Observer_CheckTarget();
		Observer_CheckProperties();
		pev->impulse = 0;
		return;
	}

	// TFC: jumping into water puts you out
	if ( pev->waterlevel > 1 && numflames > 0 )
	{
		EMIT_SOUND( ENT(pev), CHAN_ITEM, "ambience/steamburst1.wav", 1, ATTN_NORM );
		numflames = 0;
	}

	if ( m_flTeleporterEffectEndTime && m_flTeleporterEffectEndTime <= gpGlobals->time )
		TeleporterResetGlowshell( this );

	if (pev->deadflag >= DEAD_DYING)
	{
		PlayerDeathThink();
		return;
	}

	// So the correct flags get sent to client asap.
	//
	if ( m_afPhysicsFlags & PFLAG_ONTRAIN )
		pev->flags |= FL_ONTRAIN;
	else 
		pev->flags &= ~FL_ONTRAIN;

	// Train speed control
	if ( m_afPhysicsFlags & PFLAG_ONTRAIN )
	{
		CBaseEntity *pTrain = CBaseEntity::Instance( pev->groundentity );
		float vel;
		
		if ( !pTrain )
		{
			TraceResult trainTrace;
			// Maybe this is on the other side of a level transition
			UTIL_TraceLine( pev->origin, pev->origin + Vector(0,0,-38), ignore_monsters, ENT(pev), &trainTrace );

			// HACKHACK - Just look for the func_tracktrain classname
			if ( trainTrace.flFraction != 1.0 && trainTrace.pHit )
			pTrain = CBaseEntity::Instance( trainTrace.pHit );


			if ( !pTrain || !(pTrain->ObjectCaps() & FCAP_DIRECTIONAL_USE) || !pTrain->OnControls(pev) )
			{
				//ALERT( at_error, "In train mode with no train!\n" );
				m_afPhysicsFlags &= ~PFLAG_ONTRAIN;
				m_iTrain = TRAIN_NEW|TRAIN_OFF;
				return;
			}
		}
		else if ( !FBitSet( pev->flags, FL_ONGROUND ) || FBitSet( pTrain->pev->spawnflags, SF_TRACKTRAIN_NOCONTROL ) || (pev->button & (IN_MOVELEFT|IN_MOVERIGHT) ) )
		{
			// Turn off the train if you jump, strafe, or the train controls go dead
			m_afPhysicsFlags &= ~PFLAG_ONTRAIN;
			m_iTrain = TRAIN_NEW|TRAIN_OFF;
			return;
		}

		pev->velocity = g_vecZero;
		vel = 0;
		if ( m_afButtonPressed & IN_FORWARD )
		{
			vel = 1;
			pTrain->Use( this, this, USE_SET, (float)vel );
		}
		else if ( m_afButtonPressed & IN_BACK )
		{
			vel = -1;
			pTrain->Use( this, this, USE_SET, (float)vel );
		}

		if (vel)
		{
			m_iTrain = TrainSpeed(pTrain->pev->speed, pTrain->pev->impulse);
			m_iTrain |= TRAIN_ACTIVE|TRAIN_NEW;
		}

	} else if (m_iTrain & TRAIN_ACTIVE)
		m_iTrain = TRAIN_NEW; // turn off train

	// TFC: no jumping while flying, in cease fire, building, setting a detpack or feigning
	if ( ( pev->button & IN_JUMP ) && pev->movetype != MOVETYPE_FLY && !cease_fire && !is_building && !is_detpacking && !is_feigning )
	{
		// If on a ladder, jump off the ladder
		// else Jump
		Jump();
	}


	// If trying to duck, already ducked, or in the process of ducking
	if ((pev->button & IN_DUCK) || FBitSet(pev->flags,FL_DUCKING) || (m_afPhysicsFlags & PFLAG_DUCKING) )
		Duck();

	// play a footstep sound if needed
	if ( g_pGameRules->PlayFootstepSounds( this, 1.0 ) && gpGlobals->time > m_flTimeStepSound && !( pev->flags & FL_FROZEN ) )
		UpdateStepSound();

	if ( !FBitSet ( pev->flags, FL_ONGROUND ) )
	{
		m_flFallVelocity = -pev->velocity.z;
	}

	// StudioFrameAdvance( );//!!!HACKHACK!!! Can't be hit by traceline when not animating?

	// Clear out ladder pointer
	m_hEnemy = NULL;

	if ( m_afPhysicsFlags & PFLAG_ONBARNACLE )
	{
		pev->velocity = g_vecZero;
	}
}
/* Time based Damage works as follows: 
	1) There are several types of timebased damage:

		#define DMG_PARALYZE		(1 << 14)	// slows affected creature down
		#define DMG_NERVEGAS		(1 << 15)	// nerve toxins, very bad
		#define DMG_POISON			(1 << 16)	// blood poisioning
		#define DMG_RADIATION		(1 << 17)	// radiation exposure
		#define DMG_DROWNRECOVER	(1 << 18)	// drown recovery
		#define DMG_ACID			(1 << 19)	// toxic chemicals or acid burns
		#define DMG_SLOWBURN		(1 << 20)	// in an oven
		#define DMG_SLOWFREEZE		(1 << 21)	// in a subzero freezer

	2) A new hit inflicting tbd restarts the tbd counter - each monster has an 8bit counter,
		per damage type. The counter is decremented every second, so the maximum time 
		an effect will last is 255/60 = 4.25 minutes.  Of course, staying within the radius
		of a damaging effect like fire, nervegas, radiation will continually reset the counter to max.

	3) Every second that a tbd counter is running, the player takes damage.  The damage
		is determined by the type of tdb.  
			Paralyze		- 1/2 movement rate, 30 second duration.
			Nervegas		- 5 points per second, 16 second duration = 80 points max dose.
			Poison			- 2 points per second, 25 second duration = 50 points max dose.
			Radiation		- 1 point per second, 50 second duration = 50 points max dose.
			Drown			- 5 points per second, 2 second duration.
			Acid/Chemical	- 5 points per second, 10 second duration = 50 points max.
			Burn			- 10 points per second, 2 second duration.
			Freeze			- 3 points per second, 10 second duration = 30 points max.

	4) Certain actions or countermeasures counteract the damaging effects of tbds:

		Armor/Heater/Cooler - Chemical(acid),burn, freeze all do damage to armor power, then to body
							- recharged by suit recharger
		Air In Lungs		- drowning damage is done to air in lungs first, then to body
							- recharged by poking head out of water
							- 10 seconds if swiming fast
		Air In SCUBA		- drowning damage is done to air in tanks first, then to body
							- 2 minutes in tanks. Need new tank once empty.
		Radiation Syringe	- Each syringe full provides protection vs one radiation dosage
		Antitoxin Syringe	- Each syringe full provides protection vs one poisoning (nervegas or poison).
		Health kit			- Immediate stop to acid/chemical, fire or freeze damage.
		Radiation Shower	- Immediate stop to radiation damage, acid/chemical or fire damage.
		
	
*/

// If player is taking time based damage, continue doing damage to player -
// this simulates the effect of being poisoned, gassed, dosed with radiation etc -
// anything that continues to do damage even after the initial contact stops.
// Update all time based damage counters, and shut off any that are done.

// The m_bitsDamageType bit MUST be set if any damage is to be taken.
// This routine will detect the initial on value of the m_bitsDamageType
// and init the appropriate counter.  Only processes damage every second.

//#define PARALYZE_DURATION	30		// number of 2 second intervals to take damage
//#define PARALYZE_DAMAGE		0.0		// damage to take each 2 second interval

//#define NERVEGAS_DURATION	16
//#define NERVEGAS_DAMAGE		5.0

//#define POISON_DURATION		25
//#define POISON_DAMAGE		2.0

//#define RADIATION_DURATION	50
//#define RADIATION_DAMAGE	1.0

//#define ACID_DURATION		10
//#define ACID_DAMAGE			5.0

//#define SLOWBURN_DURATION	2
//#define SLOWBURN_DAMAGE		1.0

//#define SLOWFREEZE_DURATION	1.0
//#define SLOWFREEZE_DAMAGE	3.0

/* */


void CBasePlayer::CheckTimeBasedDamage() 
{
	int i;
	BYTE bDuration = 0;

	static float gtbdPrev = 0.0;

	// TFC: the concussion wobble fades out over its duration
	if ( m_flConcStartTime + m_flConcDuration > gpGlobals->time )
		m_iConcussion = (int)( m_iConcStartVal * ( ( m_flConcStartTime + m_flConcDuration - gpGlobals->time ) / m_flConcDuration ) );
	else
		m_iConcussion = 0;

	if (!(m_bitsDamageType & DMG_TIMEBASED))
		return;

	// only check for time based damage approx. every 2 seconds
	if (abs(gpGlobals->time - m_tbdPrev) < 2.0)
		return;
	
	m_tbdPrev = gpGlobals->time;

	for (i = 0; i < CDMG_TIMEBASED; i++)
	{
		// make sure bit is set for damage type
		if (m_bitsDamageType & (DMG_PARALYZE << i))
		{
			switch (i)
			{
			case itbd_Paralyze:
				// UNDONE - flag movement as half-speed
				bDuration = PARALYZE_DURATION;
				break;
			case itbd_NerveGas:
//				TakeDamage(pev, pev, NERVEGAS_DAMAGE, DMG_GENERIC);	
				bDuration = NERVEGAS_DURATION;
				break;
			case itbd_Poison:
				TakeDamage(pev, pev, POISON_DAMAGE, DMG_GENERIC);
				bDuration = POISON_DURATION;
				break;
			case itbd_Radiation:
//				TakeDamage(pev, pev, RADIATION_DAMAGE, DMG_GENERIC);
				bDuration = RADIATION_DURATION;
				break;
			case itbd_DrownRecover:
				// NOTE: this hack is actually used to RESTORE health
				// after the player has been drowning and finally takes a breath
				if (m_idrowndmg > m_idrownrestored)
				{
					int idif = min(m_idrowndmg - m_idrownrestored, 10);

					TakeHealth(idif, DMG_GENERIC);
					m_idrownrestored += idif;
				}
				bDuration = 4;	// get up to 5*10 = 50 points back
				break;
			case itbd_Acid:
//				TakeDamage(pev, pev, ACID_DAMAGE, DMG_GENERIC);
				bDuration = ACID_DURATION;
				break;
			case itbd_SlowBurn:
//				TakeDamage(pev, pev, SLOWBURN_DAMAGE, DMG_GENERIC);
				bDuration = SLOWBURN_DURATION;
				break;
			case itbd_SlowFreeze:
//				TakeDamage(pev, pev, SLOWFREEZE_DAMAGE, DMG_GENERIC);
				bDuration = SLOWFREEZE_DURATION;
				break;
			default:
				bDuration = 0;
			}

			if (m_rgbTimeBasedDamage[i])
			{
				// use up an antitoxin on poison or nervegas after a few seconds of damage					
				if (((i == itbd_NerveGas) && (m_rgbTimeBasedDamage[i] < NERVEGAS_DURATION)) ||
					((i == itbd_Poison)   && (m_rgbTimeBasedDamage[i] < POISON_DURATION)))
				{
					if (m_rgItems[ITEM_ANTIDOTE])
					{
						m_rgbTimeBasedDamage[i] = 0;
						m_rgItems[ITEM_ANTIDOTE]--;
						SetSuitUpdate("!HEV_HEAL4", FALSE, SUIT_REPEAT_OK);
					}
				}


				// decrement damage duration, detect when done.
				if (!m_rgbTimeBasedDamage[i] || --m_rgbTimeBasedDamage[i] == 0)
				{
					m_rgbTimeBasedDamage[i] = 0;
					// if we're done, clear damage bits
					m_bitsDamageType &= ~(DMG_PARALYZE << i);	
				}
			}
			else
				// first time taking this damage type - init damage duration
				m_rgbTimeBasedDamage[i] = bDuration;
		}
	}
}

/*
THE POWER SUIT

The Suit provides 3 main functions: Protection, Notification and Augmentation. 
Some functions are automatic, some require power. 
The player gets the suit shortly after getting off the train in C1A0 and it stays
with him for the entire game.

Protection

	Heat/Cold
		When the player enters a hot/cold area, the heating/cooling indicator on the suit 
		will come on and the battery will drain while the player stays in the area. 
		After the battery is dead, the player starts to take damage. 
		This feature is built into the suit and is automatically engaged.
	Radiation Syringe
		This will cause the player to be immune from the effects of radiation for N seconds. Single use item.
	Anti-Toxin Syringe
		This will cure the player from being poisoned. Single use item.
	Health
		Small (1st aid kits, food, etc.)
		Large (boxes on walls)
	Armor
		The armor works using energy to create a protective field that deflects a
		percentage of damage projectile and explosive attacks. After the armor has been deployed,
		it will attempt to recharge itself to full capacity with the energy reserves from the battery.
		It takes the armor N seconds to fully charge. 

Notification (via the HUD)

x	Health
x	Ammo  
x	Automatic Health Care
		Notifies the player when automatic healing has been engaged. 
x	Geiger counter
		Classic Geiger counter sound and status bar at top of HUD 
		alerts player to dangerous levels of radiation. This is not visible when radiation levels are normal.
x	Poison
	Armor
		Displays the current level of armor. 

Augmentation 

	Reanimation (w/adrenaline)
		Causes the player to come back to life after he has been dead for 3 seconds. 
		Will not work if player was gibbed. Single use.
	Long Jump
		Used by hitting the ??? key(s). Caused the player to further than normal.
	SCUBA	
		Used automatically after picked up and after player enters the water. 
		Works for N seconds. Single use.	
	
Things powered by the battery

	Armor		
		Uses N watts for every M units of damage.
	Heat/Cool	
		Uses N watts for every second in hot/cold area.
	Long Jump	
		Uses N watts for every jump.
	Alien Cloak	
		Uses N watts for each use. Each use lasts M seconds.
	Alien Shield	
		Augments armor. Reduces Armor drain by one half
 
*/

// if in range of radiation source, ping geiger counter

#define GEIGERDELAY 0.25

void CBasePlayer :: UpdateGeigerCounter( void )
{
	BYTE range;

	// delay per update ie: don't flood net with these msgs
	if (gpGlobals->time < m_flgeigerDelay)
		return;

	m_flgeigerDelay = gpGlobals->time + GEIGERDELAY;
		
	// send range to radition source to client

	range = (BYTE) (m_flgeigerRange / 4);

	if (range != m_igeigerRangePrev)
	{
		m_igeigerRangePrev = range;

		MESSAGE_BEGIN( MSG_ONE, gmsgGeigerRange, NULL, pev );
			WRITE_BYTE( range );
		MESSAGE_END();
	}

	// reset counter and semaphore
	if (!RANDOM_LONG(0,3))
		m_flgeigerRange = 1000;

}

/*
================
CheckSuitUpdate

Play suit update if it's time
================
*/

#define SUITUPDATETIME	3.5
#define SUITFIRSTUPDATETIME 0.1

void CBasePlayer::CheckSuitUpdate()
{
	int i;
	int isentence = 0;
	int isearch = m_iSuitPlayNext;
	
	// Ignore suit updates if no suit
	if ( !(pev->weapons & (1<<WEAPON_SUIT)) )
		return;

	// if in range of radiation source, ping geiger counter
	UpdateGeigerCounter();

	if ( g_pGameRules->IsMultiplayer() )
	{
		// don't bother updating HEV voice in multiplayer.
		return;
	}

	if ( gpGlobals->time >= m_flSuitUpdate && m_flSuitUpdate > 0)
	{
		// play a sentence off of the end of the queue
		for (i = 0; i < CSUITPLAYLIST; i++)
			{
			if (isentence = m_rgSuitPlayList[isearch])
				break;
			
			if (++isearch == CSUITPLAYLIST)
				isearch = 0;
			}

		if (isentence)
		{
			m_rgSuitPlayList[isearch] = 0;
			if (isentence > 0)
			{
				// play sentence number

				char sentence[CBSENTENCENAME_MAX+1];
				strcpy(sentence, "!");
				strcat(sentence, gszallsentencenames[isentence]);
				EMIT_SOUND_SUIT(ENT(pev), sentence);
			}
			else
			{
				// play sentence group
				EMIT_GROUPID_SUIT(ENT(pev), -isentence);
			}
		m_flSuitUpdate = gpGlobals->time + SUITUPDATETIME;
		}
		else
			// queue is empty, don't check 
			m_flSuitUpdate = 0;
	}
}
 
// add sentence to suit playlist queue. if fgroup is true, then
// name is a sentence group (HEV_AA), otherwise name is a specific
// sentence name ie: !HEV_AA0.  If iNoRepeat is specified in
// seconds, then we won't repeat playback of this word or sentence
// for at least that number of seconds.

void CBasePlayer::SetSuitUpdate(char *name, int fgroup, int iNoRepeatTime)
{
	int i;
	int isentence;
	int iempty = -1;
	
	
	// Ignore suit updates if no suit
	if ( !(pev->weapons & (1<<WEAPON_SUIT)) )
		return;

	if ( g_pGameRules->IsMultiplayer() )
	{
		// due to static channel design, etc. We don't play HEV sounds in multiplayer right now.
		return;
	}

	// if name == NULL, then clear out the queue

	if (!name)
	{
		for (i = 0; i < CSUITPLAYLIST; i++)
			m_rgSuitPlayList[i] = 0;
		return;
	}
	// get sentence or group number
	if (!fgroup)
	{
		isentence = SENTENCEG_Lookup(name, NULL);
		if (isentence < 0)
			return;
	}
	else
		// mark group number as negative
		isentence = -SENTENCEG_GetIndex(name);

	// check norepeat list - this list lets us cancel
	// the playback of words or sentences that have already
	// been played within a certain time.

	for (i = 0; i < CSUITNOREPEAT; i++)
	{
		if (isentence == m_rgiSuitNoRepeat[i])
			{
			// this sentence or group is already in 
			// the norepeat list

			if (m_rgflSuitNoRepeatTime[i] < gpGlobals->time)
				{
				// norepeat time has expired, clear it out
				m_rgiSuitNoRepeat[i] = 0;
				m_rgflSuitNoRepeatTime[i] = 0.0;
				iempty = i;
				break;
				}
			else
				{
				// don't play, still marked as norepeat
				return;
				}
			}
		// keep track of empty slot
		if (!m_rgiSuitNoRepeat[i])
			iempty = i;
	}

	// sentence is not in norepeat list, save if norepeat time was given

	if (iNoRepeatTime)
	{
		if (iempty < 0)
			iempty = RANDOM_LONG(0, CSUITNOREPEAT-1); // pick random slot to take over
		m_rgiSuitNoRepeat[iempty] = isentence;
		m_rgflSuitNoRepeatTime[iempty] = iNoRepeatTime + gpGlobals->time;
	}

	// find empty spot in queue, or overwrite last spot
	
	m_rgSuitPlayList[m_iSuitPlayNext++] = isentence;
	if (m_iSuitPlayNext == CSUITPLAYLIST)
		m_iSuitPlayNext = 0;

	if (m_flSuitUpdate <= gpGlobals->time)
	{
		if (m_flSuitUpdate == 0)
			// play queue is empty, don't delay too long before playback
			m_flSuitUpdate = gpGlobals->time + SUITFIRSTUPDATETIME;
		else 
			m_flSuitUpdate = gpGlobals->time + SUITUPDATETIME; 
	}

}



//=========================================================
// UpdatePlayerSound - updates the position of the player's
// reserved sound slot in the sound list.
//=========================================================
void CBasePlayer :: UpdatePlayerSound ( void )
{
	int iBodyVolume;
	int iVolume;
	CSound *pSound;

	pSound = CSoundEnt::SoundPointerForIndex( CSoundEnt :: ClientSoundIndex( edict() ) );

	if ( !pSound )
	{
		ALERT ( at_console, "Client lost reserved sound!\n" );
		return;
	}

	pSound->m_iType = bits_SOUND_NONE;

	// now calculate the best target volume for the sound. If the player's weapon
	// is louder than his body/movement, use the weapon volume, else, use the body volume.
	
	if ( FBitSet ( pev->flags, FL_ONGROUND ) )
	{	
		iBodyVolume = pev->velocity.Length(); 

		// clamp the noise that can be made by the body, in case a push trigger,
		// weapon recoil, or anything shoves the player abnormally fast. 
		if ( iBodyVolume > 512 )
		{
			iBodyVolume = 512;
		}
	}
	else
	{
		iBodyVolume = 0;
	}

	if ( pev->button & IN_JUMP )
	{
		iBodyVolume += 100;
	}

// convert player move speed and actions into sound audible by monsters.
	if ( m_iWeaponVolume > iBodyVolume )
	{
		m_iTargetVolume = m_iWeaponVolume;

		// OR in the bits for COMBAT sound if the weapon is being louder than the player. 
		pSound->m_iType |= bits_SOUND_COMBAT;
	}
	else
	{
		m_iTargetVolume = iBodyVolume;
	}

	// decay weapon volume over time so bits_SOUND_COMBAT stays set for a while
	m_iWeaponVolume -= 250 * gpGlobals->frametime;
	if ( m_iWeaponVolume < 0 )
	{
		iVolume = 0;
	}


	// if target volume is greater than the player sound's current volume, we paste the new volume in 
	// immediately. If target is less than the current volume, current volume is not set immediately to the
	// lower volume, rather works itself towards target volume over time. This gives monsters a much better chance
	// to hear a sound, especially if they don't listen every frame.
	iVolume = pSound->m_iVolume;

	if ( m_iTargetVolume > iVolume )
	{
		iVolume = m_iTargetVolume;
	}
	else if ( iVolume > m_iTargetVolume )
	{
		iVolume -= 250 * gpGlobals->frametime;

		if ( iVolume < m_iTargetVolume )
		{
			iVolume = 0;
		}
	}

	if ( m_fNoPlayerSound )
	{
		// debugging flag, lets players move around and shoot without monsters hearing.
		iVolume = 0;
	}

	if ( gpGlobals->time > m_flStopExtraSoundTime )
	{
		// since the extra sound that a weapon emits only lasts for one client frame, we keep that sound around for a server frame or two 
		// after actual emission to make sure it gets heard.
		m_iExtraSoundTypes = 0;
	}

	if ( pSound )
	{
		pSound->m_vecOrigin = pev->origin;
		pSound->m_iType |= ( bits_SOUND_PLAYER | m_iExtraSoundTypes );
		pSound->m_iVolume = iVolume;
	}

	// keep track of virtual muzzle flash
	m_iWeaponFlash -= 256 * gpGlobals->frametime;
	if (m_iWeaponFlash < 0)
		m_iWeaponFlash = 0;

	//UTIL_MakeVectors ( pev->angles );
	//gpGlobals->v_forward.z = 0;

	// Below are a couple of useful little bits that make it easier to determine just how much noise the 
	// player is making. 
	// UTIL_ParticleEffect ( pev->origin + gpGlobals->v_forward * iVolume, g_vecZero, 255, 25 );
	//ALERT ( at_console, "%d/%d\n", iVolume, m_iTargetVolume );
}


void CBasePlayer::PostThink()
{
	if ( g_fGameOver )
		goto pt_end;         // intermission or finale

	Player_Menu();

	if ( !IsAlive() || pev->deadflag == 5 )
		goto pt_end;

	// Handle Tank controlling
	if ( m_pTank != NULL )
	{ // if they've moved too far from the gun,  or selected a weapon, unuse the gun
		if ( m_pTank->OnControls( pev ) && !pev->weaponmodel )
		{
			m_pTank->Use( this, this, USE_SET, 2 );	// try fire the gun
		}
		else
		{  // they've moved off the platform
			m_pTank->Use( this, this, USE_OFF, 0 );
			m_pTank = NULL;
		}
	}

	// do weapon stuff (not while building, setting a detpack, feigning or ceasefired)
	if ( !cease_fire && !is_building && !is_detpacking && !is_feigning && m_pTank == NULL && m_flNextAttack <= 0 )
	{
		ImpulseCommands();

		if ( m_pActiveItem )
			m_pActiveItem->ItemPostFrame();
	}

	// check to see if player landed hard enough to make a sound
	// falling farther than half of the maximum safe distance, but not as far a max safe distance will
	// play a bootscrape sound, and no damage will be inflicted. Fallling a distance shorter than half
	// of maximum safe distance will make no sound. Falling farther than max safe distance will play a
	// fallpain sound, and damage will be inflicted based on how far the player fell

	if ( ( FBitSet( pev->flags, FL_ONGROUND ) ) && ( pev->health > 0 ) && m_flFallVelocity >= PLAYER_FALL_PUNCH_THRESHHOLD )
	{
		if ( pev->watertype != CONTENT_WATER && m_flFallVelocity > PLAYER_MAX_SAFE_FALL_SPEED )
		{
			// TFC: damage scales with speed; scouts take half, heavies half again more
			float flFallDamage = m_flFallVelocity / 300 * 5;

			if ( pev->playerclass == PC_SCOUT )
				flFallDamage *= 0.5;
			else if ( pev->playerclass == PC_HVYWEAP )
				flFallDamage *= 1.5;

			if ( flFallDamage > pev->health )
			{//splat
				// note: play on item channel because we play footstep landing on body channel
				EMIT_SOUND( ENT( pev ), CHAN_ITEM, "common/bodysplat.wav", 1, ATTN_NORM );
			}

			if ( flFallDamage > 0 )
			{
				TakeDamage( VARS( eoNullEntity ), VARS( eoNullEntity ), flFallDamage, DMG_FALL | DMG_IGNOREARMOR );
				pev->punchangle.x = 0;
			}
		}

		// landing footstep
		m_flTimeStepSound = 0;
		UpdateStepSound();

		if ( IsAlive() )
		{
			SetAnimation( PLAYER_WALK );
		}
	}

	if ( FBitSet( pev->flags, FL_ONGROUND ) )
	{
		if ( m_flFallVelocity > 64 && !g_pGameRules->IsMultiplayer() )
		{
			CSoundEnt::InsertSound( bits_SOUND_PLAYER, pev->origin, m_flFallVelocity, 0.2 );
			// ALERT( at_console, "fall %f\n", m_flFallVelocity );
		}
		m_flFallVelocity = 0;
	}

	// select the proper animation for the player character
	if ( IsAlive() )
	{
		if ( !pev->velocity.x && !pev->velocity.y )
			SetAnimation( PLAYER_IDLE );
		else if ( ( pev->velocity.x || pev->velocity.y ) && ( FBitSet( pev->flags, FL_ONGROUND ) || pev->waterlevel > 1 ) )
			SetAnimation( PLAYER_WALK );
	}

	StudioFrameAdvance( );
	CheckPowerups();

	UpdatePlayerSound();

pt_end:
	// Decay timers on weapons
	// go through all of the weapons and make a list of the ones to pack
	for ( int i = 0; i < MAX_ITEM_TYPES; i++ )
	{
		CBasePlayerItem *pPlayerItem = m_rgpPlayerItems[ i ];

		while ( pPlayerItem )
		{
			CBasePlayerWeapon *gun;

			gun = (CBasePlayerWeapon *)pPlayerItem->GetWeaponPtr();

			if ( gun )
			{
				gun->m_flNextPrimaryAttack = max( gun->m_flNextPrimaryAttack - gpGlobals->frametime, -1.0f );
				gun->m_fNextAimBonus = max( gun->m_fNextAimBonus - gpGlobals->frametime, -1.0f );
				gun->m_flNextSecondaryAttack = max( gun->m_flNextSecondaryAttack - gpGlobals->frametime, -0.001f );
				gun->m_flNextReload = max( gun->m_flNextReload - gpGlobals->frametime, -0.001f );

				if ( gun->m_flPumpTime != 1000 )
				{
					gun->m_flPumpTime = max( gun->m_flPumpTime - gpGlobals->frametime, -0.001f );
				}

				if ( gun->m_flTimeWeaponIdle != 1000 )
				{
					gun->m_flTimeWeaponIdle = max( gun->m_flTimeWeaponIdle - gpGlobals->frametime, -0.001f );
				}
			}

			pPlayerItem = pPlayerItem->m_pNext;
		}
	}

	m_flNextAttack -= gpGlobals->frametime;
	if ( m_flNextAttack < -0.001 )
		m_flNextAttack = -0.001;

	// Track button info so we can detect 'pressed' and 'released' buttons next frame
	m_afButtonLast = pev->button;
}


// checks if the spot is clear of players
// TFC: a spawn point is free if no player is within 96 units
BOOL IsSpawnPointValid( Vector &pos )
{
	CBaseEntity *ent = NULL;

	while ( ( ent = UTIL_FindEntityInSphere( ent, pos, 96 ) ) != NULL )
	{
		// if ent is a client, don't spawn on 'em
		if ( ent->IsPlayer() )
			return FALSE;
	}

	return TRUE;
}


DLL_GLOBAL CBaseEntity	*g_pLastSpawn;
inline int FNullEnt( CBaseEntity *ent ) { return (ent == NULL) || FNullEnt( ent->edict() ); }

/*
============
EntSelectSpawnPoint

Returns the entity to spawn at

USES AND SETS GLOBAL g_pLastSpawn
============
*/
edict_t *EntSelectSpawnPoint( edict_t *player )
{
	CBaseEntity *pSpot;

	CBaseEntity *pPlayer = CBaseEntity::Instance( player );

	// TFC: team spawn points first
	if ( pPlayer->team_no )
	{
		pSpot = pPlayer->FindTeamSpawnPoint();
		if ( pSpot && !FNullEnt( pSpot->edict() ) )
			return pSpot->edict();
	}

	// choose a info_player_deathmatch point
	if ( g_pGameRules->IsCoOp() )
	{
		pSpot = UTIL_FindEntityByClassname( g_pLastSpawn, "info_player_coop" );
		if ( !FNullEnt( pSpot ) )
			goto ReturnSpot;
		pSpot = UTIL_FindEntityByClassname( g_pLastSpawn, "info_player_start" );
		if ( !FNullEnt( pSpot ) )
			goto ReturnSpot;
	}
	else if ( g_pGameRules->IsDeathmatch() )
	{
		pSpot = g_pLastSpawn;
		// Randomize the start spot
		for ( int i = RANDOM_LONG( 1, 5 ); i > 0; i-- )
			pSpot = UTIL_FindEntityByClassname( pSpot, "info_player_deathmatch" );
		if ( FNullEnt( pSpot ) )  // skip over the null point
			pSpot = UTIL_FindEntityByClassname( pSpot, "info_player_deathmatch" );

		CBaseEntity *pFirstSpot = pSpot;

		do
		{
			if ( pSpot )
			{
				// check if pSpot is valid
				if ( IsSpawnPointValid( pSpot->pev->origin ) )
				{
					if ( pSpot->pev->origin == Vector( 0, 0, 0 ) )
					{
						pSpot = UTIL_FindEntityByClassname( pSpot, "info_player_deathmatch" );
						continue;
					}

					// if so, go to pSpot
					goto ReturnSpot;
				}
			}
			// increment pSpot
			pSpot = UTIL_FindEntityByClassname( pSpot, "info_player_deathmatch" );
		} while ( pSpot != pFirstSpot ); // loop if we're not back to the start

		// we haven't found a place to spawn yet,  so kill any guy at the first spawn point and spawn there
		if ( !FNullEnt( pSpot ) )
		{
			CBaseEntity *ent = NULL;
			while ( ( ent = UTIL_FindEntityInSphere( ent, pSpot->pev->origin, 128 ) ) != NULL )
			{
				// if ent is a client, kill em (unless they are ourselves)
				if ( ent->IsPlayer() && !( ent->edict() == player ) )
					ent->TakeDamage( VARS( INDEXENT( 0 ) ), VARS( INDEXENT( 0 ) ), 300, DMG_GENERIC );
			}
			goto ReturnSpot;
		}
	}

	// If startspot is set, (re)spawn there.
	if ( FStringNull( gpGlobals->startspot ) || !strlen( STRING( gpGlobals->startspot ) ) )
	{
		pSpot = UTIL_FindEntityByClassname( NULL, "info_player_start" );
		if ( !FNullEnt( pSpot ) )
			goto ReturnSpot;
	}
	else
	{
		pSpot = UTIL_FindEntityByTargetname( NULL, STRING( gpGlobals->startspot ) );
		if ( !FNullEnt( pSpot ) )
			goto ReturnSpot;
	}

ReturnSpot:
	if ( FNullEnt( pSpot ) )
	{
		ALERT( at_error, "PutClientInServer: no info_player_start on level" );
		return INDEXENT( 0 );
	}

	g_pLastSpawn = pSpot;
	return pSpot->edict();
}

// Bit in illegalclasses[] for a playerclass
static int ClassIllegalBit( int pc )
{
	switch ( pc )
	{
	case PC_SCOUT:		return TF_ILL_SCOUT;
	case PC_SNIPER:		return TF_ILL_SNIPER;
	case PC_SOLDIER:	return TF_ILL_SOLDIER;
	case PC_DEMOMAN:	return TF_ILL_DEMOMAN;
	case PC_MEDIC:		return TF_ILL_MEDIC;
	case PC_HVYWEAP:	return TF_ILL_HVYWEP;
	case PC_PYRO:		return TF_ILL_PYRO;
	case PC_SPY:		return TF_ILL_SPY;
	case PC_ENGINEER:	return TF_ILL_ENGINEER;
	case PC_RANDOM:		return TF_ILL_RANDOMPC;
	}
	return 0;
}

void CBasePlayer::Spawn( void )
{
	pev->classname		= MAKE_STRING( "player" );
	pev->health			= 100;
	pev->armorvalue		= 0;
	pev->solid			= SOLID_SLIDEBOX;
	pev->movetype		= MOVETYPE_WALK;
	pev->max_health		= pev->health;
	pev->flags			&= FL_PROXY;	// keep proxy flag sey by engine
	pev->flags			|= FL_CLIENT;
	pev->air_finished	= gpGlobals->time + 12;
	pev->dmg			= 2;				// initial water damage
	pev->effects		= 0;
	pev->deadflag		= DEAD_NO;
	pev->dmg_take		= 0;
	pev->dmg_save		= 0;
	pev->friction		= 1.0;
	pev->gravity		= 1.0;
	m_fLongJump			= FALSE;// no longjump module.
	m_iFOV				= 0;// init field of view.
	m_bitsHUDDamage		= -1;
	m_bitsDamageType	= 0;
	m_afPhysicsFlags	= 0;
	pev->fov			= 0;
	m_iClientFOV		= -1; // make sure fov reset is sent
	m_flNextDecalTime	= 0;// let this player decal as soon as he spawns.
	m_flSafetyCheckTime	= 0;
	pev->iuser3			= 0;

	TeleporterResetEffects( this );

	// Tell the client's movement code this is TFC, and who is allied with whom
	g_engfuncs.pfnSetPhysicsKeyValue( edict(), "tfc", "1" );

	char szAllies[32];
	sprintf( szAllies, "%u", ( teamallies[0] & 0x1f ) | ( ( teamallies[1] & 0x1f ) << 5 ) | ( ( teamallies[2] & 0x1f ) << 10 ) |
							 ( ( teamallies[3] & 0x1f ) << 15 ) | ( ( teamallies[4] & 0x1f ) << 20 ) );
	g_engfuncs.pfnSetPhysicsKeyValue( edict(), "ta", szAllies );

	m_flgeigerDelay = gpGlobals->time + 2.0;	// wait a few seconds until user-defined message registrations
												// are recieved by all clients

	m_flTimeStepSound	= 0;
	m_iStepLeft = 0;
	m_flFieldOfView		= 0.5;// some monsters use this to determine whether or not the player is looking at them.

	m_bloodColor	= BLOOD_COLOR_RED;
	m_flNextAttack	= 0;
	StartSneaking();

	m_iFlashBattery = 99;
	m_flFlashLightTime = 1; // force first message
	m_iBeingTeleported = FALSE;

	items = 0;
	m_MenuStringBuffer[0] = 0;
	menu_displaytime = 0;
	menu_refreshtime = 0;
	current_menu = MENU_DEFAULT;

	// dont let uninitialized value here hurt the player
	m_flFallVelocity = 0;
	m_flConcDuration = 0;
	m_flConcStartTime = 0;

	super_damage_finished = 0;
	radsuit_finished = 0;
	invisible_finished = 0;
	invincible_finished = 0;
	m_iTeamToDisguiseAs = 0;
	m_flNextSBarUpdateTime = 0;
	numflames = 0;
	m_iClientIsFeigning = -1;
	m_iClientIsDetpacking = -1;
	immune_to_check = gpGlobals->time + 10;
	m_iClientBuildState = -1;
	m_iClientRandomPC = -1;

	SET_VIEW( edict(), edict() );

	// Class picked while dead
	if ( nextpc )
	{
		pev->playerclass = nextpc;
		nextpc = 0;

		if ( pev->playerclass == PC_RANDOM )
			tfstate |= TFSTATE_RANDOMPC;
		else
			tfstate &= ~TFSTATE_RANDOMPC;
	}

	int oldtfstate = tfstate;
	if ( oldtfstate & TFSTATE_RANDOMPC )
	{
		// Random playerclass: a legal class that's different from the last one
		int oldclass = pev->playerclass;
		int pc;
		do
		{
			pev->playerclass = (int)floor( RANDOM_FLOAT( 0, 9 ) ) + 1;
			pc = pev->playerclass;

			if ( pc == PC_SPY && spy_off == TRUE )
				continue;

			int iBit = ClassIllegalBit( pc );
			if ( ( illegalclasses[0] & iBit ) || ( illegalclasses[ team_no ] & iBit ) || pc == oldclass )
				continue;

			if ( ClassIsRestricted( team_no, pc ) )
				continue;

			break;
		} while ( 1 );

		m_pszLastItem = NULL;
		tfstate = TFSTATE_RANDOMPC;
		m_nFirstSpawn = TRUE;
	}
	else
	{
		tfstate = 0;
	}

	// Zoom preference survives respawning
	if ( oldtfstate & TFSTATE_ZOOMOFF )
		tfstate |= TFSTATE_ZOOMOFF;

	TeamFortress_ExecClassScript();

	if ( pev->playerclass != PC_ENGINEER )
		Engineer_RemoveBuildings();

	pev->takedamage = DAMAGE_AIM;

	TeamFortress_PrintClassName( pev->playerclass );

	TeamFortress_SetEquipment();
	TeamFortress_SetHealth();
	TeamFortress_SetSpeed();
	TeamFortress_SetSkin();

	building_wait = 0;
	sniper_zoom = 0;

	// Chat spam protection
	m_cSpamPoints = 0;
	m_flGagTime = -1;
	m_flLastTalkTime = gpGlobals->time;

	SetTouch( &CBasePlayer::PlayerTouch );

	// Clan battle ID
	if ( tf_id )
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_battleid", UTIL_dtos1( tf_id ) );

	g_pGameRules->GetPlayerSpawnSpot( this );

	pev->sequence = LookupActivity( ACT_IDLE );

	if ( FBitSet( pev->flags, FL_DUCKING ) )
		UTIL_SetSize( pev, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX );
	else
		UTIL_SetSize( pev, VEC_HULL_MIN, VEC_HULL_MAX );

	pev->view_ofs = VEC_VIEW;
	Precache();
	m_HackedGunPos		= Vector( 0, 32, 0 );

	if ( m_iPlayerSound == SOUNDLIST_EMPTY )
	{
		ALERT( at_console, "Couldn't alloc player sound slot!\n" );
	}

	m_fNoPlayerSound = FALSE;// normal sound behavior.

	m_fInitHUD = TRUE;
	m_iClientHideHUD = -1;  // force this to be recalculated
	m_fWeapon = FALSE;
	m_pClientActiveItem = NULL;
	m_iClientBattery = -1;
	m_iMaxArmor = -1;
	cl_no_grenades_1 = -1;
	cl_no_grenades_2 = -1;

	// reset all ammo values to 0
	memset( m_rgAmmo, 0, sizeof( m_rgAmmo ) );
	memset( m_rgAmmoLast, 0, sizeof( m_rgAmmoLast ) );  // client ammo values also have to be reset  (the death hud clear messages does on the client side)

	m_lastx = m_lasty = 0;

	g_pGameRules->PlayerSpawn( this );
}

void CBasePlayer::TeamFortress_ExecClassScript( void )
{
	if ( pev->playerclass != PC_RANDOM && pev->playerclass != PC_UNDEFINED && pev->playerclass != lastpc )
	{
		lastpc = pev->playerclass;

		// The client runs the class's config script
		if ( exec_scripts )
		{
			MESSAGE_BEGIN( MSG_ONE, SVC_TFC_EXECCLASS, NULL, pev );
				WRITE_BYTE( 1 );
				WRITE_BYTE( pev->playerclass );
			MESSAGE_END();
		}
	}
}


void CBasePlayer :: Precache( void )
{
	// in the event that the player JUST spawned, and the level node graph
	// was loaded, fix all of the node graph pointers before the game starts.
	
	// !!!BUGBUG - now that we have multiplayer, this needs to be moved!
	if ( WorldGraph.m_fGraphPresent && !WorldGraph.m_fGraphPointersSet )
	{
		if ( !WorldGraph.FSetGraphPointers() )
		{
			ALERT ( at_console, "**Graph pointers were not set!\n");
		}
		else
		{
			ALERT ( at_console, "**Graph Pointers Set!\n" );
		} 
	}

	// SOUNDS / MODELS ARE PRECACHED in ClientPrecache() (game specific)
	// because they need to precache before any clients have connected

	// init geiger counter vars during spawn and each time
	// we cross a level transition

	m_flgeigerRange = 1000;
	m_igeigerRangePrev = 1000;

	m_bitsDamageType = 0;
	m_bitsHUDDamage = -1;

	m_iClientBattery = -1;

	m_iTrain = TRAIN_NEW;

	// Make sure any necessary user messages have been registered
	LinkUserMessages();

	m_iUpdateTime = 5;  // won't update for 1/2 a second

	if ( gInitHUD )
		m_fInitHUD = TRUE;
}


int CBasePlayer::Save( CSave &save )
{
	if ( !CBaseMonster::Save(save) )
		return 0;

	return save.WriteFields( "PLAYER", this, m_playerSaveData, ARRAYSIZE(m_playerSaveData) );
}


//
// Marks everything as new so the player will resend this to the hud.
//
void CBasePlayer::RenewItems(void)
{

}


int CBasePlayer::Restore( CRestore &restore )
{
	if ( !CBaseMonster::Restore( restore ) )
		return 0;

	int status = restore.ReadFields( "PLAYER", this, m_playerSaveData, ARRAYSIZE( m_playerSaveData ) );

	SAVERESTOREDATA *pSaveData = (SAVERESTOREDATA *)gpGlobals->pSaveData;
	// landmark isn't present.
	if ( !pSaveData->fUseLandmark )
	{
		ALERT( at_console, "No Landmark:%s\n", pSaveData->szLandmarkName );

		// default to normal spawn
		edict_t* pentSpawnSpot = EntSelectSpawnPoint( edict() );
		pev->origin = VARS( pentSpawnSpot )->origin + Vector( 0, 0, 1 );
		pev->angles = VARS( pentSpawnSpot )->angles;
	}
	pev->v_angle.z = 0;	// Clear out roll
	pev->angles = pev->v_angle;

	pev->fixangle = TRUE;           // turn this way immediately

// Copied from spawn() for now
	m_bloodColor	= BLOOD_COLOR_RED;

	g_ulModelIndexPlayer = pev->modelindex;

	if ( FBitSet( pev->flags, FL_DUCKING ) )
		UTIL_SetSize( pev, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX );
	else
		UTIL_SetSize( pev, VEC_HULL_MIN, VEC_HULL_MAX );

	return status;
}



void CBasePlayer::SelectNextItem( int iItem )
{
	CBasePlayerItem *pItem;

	pItem = m_rgpPlayerItems[ iItem ];
	
	if (!pItem)
		return;

	if (pItem == m_pActiveItem)
	{
		// select the next one in the chain
		pItem = m_pActiveItem->m_pNext; 
		if (! pItem)
		{
			return;
		}

		CBasePlayerItem *pLast;
		pLast = pItem;
		while (pLast->m_pNext)
			pLast = pLast->m_pNext;

		// relink chain
		pLast->m_pNext = m_pActiveItem;
		m_pActiveItem->m_pNext = NULL;
		m_rgpPlayerItems[ iItem ] = pItem;
	}

	ResetAutoaim( );

	// FIX, this needs to queue them up and delay
	if (m_pActiveItem)
	{
		m_pActiveItem->Holster( );
	}
	
	m_pActiveItem = pItem;

	if (m_pActiveItem)
	{
		m_pActiveItem->Deploy( );
		m_pActiveItem->UpdateItemInfo( );
	}
}

void CBasePlayer::SelectItem(const char *pstr)
{
	if (!pstr)
		return;

	CBasePlayerItem *pItem = NULL;

	for (int i = 0; i < MAX_ITEM_TYPES; i++)
	{
		if (m_rgpPlayerItems[i])
		{
			pItem = m_rgpPlayerItems[i];
	
			while (pItem)
			{
				if (FClassnameIs(pItem->pev, pstr))
					break;
				pItem = pItem->m_pNext;
			}
		}

		if (pItem)
			break;
	}

	if (!pItem)
		return;

	
	if (pItem == m_pActiveItem)
		return;

	ResetAutoaim( );

	// FIX, this needs to queue them up and delay
	if (m_pActiveItem)
		m_pActiveItem->Holster( );
	
	m_pLastItem = m_pActiveItem;
	m_pActiveItem = pItem;

	if (m_pActiveItem)
	{
		m_pActiveItem->Deploy( );
		m_pActiveItem->UpdateItemInfo( );
	}
}


void CBasePlayer::SelectLastItem(void)
{
	if (!m_pLastItem)
	{
		return;
	}

	if ( m_pActiveItem && !m_pActiveItem->CanHolster() )
	{
		return;
	}

	ResetAutoaim( );

	// FIX, this needs to queue them up and delay
	if (m_pActiveItem)
		m_pActiveItem->Holster( );
	
	CBasePlayerItem *pTemp = m_pActiveItem;
	m_pActiveItem = m_pLastItem;
	m_pLastItem = pTemp;
	m_pActiveItem->Deploy( );
	m_pActiveItem->UpdateItemInfo( );
}

//==============================================
// HasWeapons - do I have any weapons at all?
//==============================================
BOOL CBasePlayer::HasWeapons( void )
{
	int i;

	for ( i = 0 ; i < MAX_ITEM_TYPES ; i++ )
	{
		if ( m_rgpPlayerItems[ i ] )
		{
			return TRUE;
		}
	}

	return FALSE;
}

void CBasePlayer::SelectPrevItem( int iItem )
{
}




//==============================================
// !!!UNDONE:ultra temporary SprayCan entity to apply
// decal frame at a time. For PreAlpha CD
//==============================================
class CSprayCan : public CBaseEntity
{
public:
	void	Spawn ( entvars_t *pevOwner );
	void	Think( void );

	virtual int	ObjectCaps( void ) { return FCAP_DONT_SAVE; }
};

void CSprayCan::Spawn ( entvars_t *pevOwner )
{
	pev->origin = pevOwner->origin + Vector ( 0 , 0 , 32 );
	pev->angles = pevOwner->v_angle;
	pev->owner = ENT(pevOwner);
	pev->frame = 0;

	pev->nextthink = gpGlobals->time + 0.1;
	EMIT_SOUND(ENT(pev), CHAN_VOICE, "player/sprayer.wav", 1, ATTN_NORM);
}

void CSprayCan::Think( void )
{
	TraceResult	tr;	
	int playernum;
	int nFrames;
	CBasePlayer *pPlayer;
	
	pPlayer = (CBasePlayer *)GET_PRIVATE(pev->owner);

	if (pPlayer)
		nFrames = pPlayer->GetCustomDecalFrames();
	else
		nFrames = -1;

	playernum = ENTINDEX(pev->owner);
	
	// ALERT(at_console, "Spray by player %i, %i of %i\n", playernum, (int)(pev->frame + 1), nFrames);

	UTIL_MakeVectors(pev->angles);
	UTIL_TraceLine ( pev->origin, pev->origin + gpGlobals->v_forward * 128, ignore_monsters, pev->owner, & tr);

	// No customization present.
	if (nFrames == -1)
	{
		UTIL_DecalTrace( &tr, DECAL_LAMBDA6 );
		UTIL_Remove( this );
	}
	else
	{
		UTIL_PlayerDecalTrace( &tr, playernum, pev->frame, TRUE );
		// Just painted last custom frame.
		if ( pev->frame++ >= (nFrames - 1))
			UTIL_Remove( this );
	}

	pev->nextthink = gpGlobals->time + 0.1;
}

class	CBloodSplat : public CBaseEntity
{
public:
	void	Spawn ( entvars_t *pevOwner );
	void	Spray ( void );
};

void CBloodSplat::Spawn ( entvars_t *pevOwner )
{
	pev->origin = pevOwner->origin + Vector ( 0 , 0 , 32 );
	pev->angles = pevOwner->v_angle;
	pev->owner = ENT(pevOwner);

	SetThink ( &CBloodSplat::Spray );
	pev->nextthink = gpGlobals->time + 0.1;
}

void CBloodSplat::Spray ( void )
{
	TraceResult	tr;	
	
	if ( g_Language != LANGUAGE_GERMAN )
	{
		UTIL_MakeVectors(pev->angles);
		UTIL_TraceLine ( pev->origin, pev->origin + gpGlobals->v_forward * 128, ignore_monsters, pev->owner, & tr);

		UTIL_BloodDecalTrace( &tr, BLOOD_COLOR_RED );
	}
	SetThink ( &CBloodSplat::SUB_Remove );
	pev->nextthink = gpGlobals->time + 0.1;
}

//==============================================



void CBasePlayer::GiveNamedItem( char *pszName )
{
	edict_t	*pent;

	int istr = MAKE_STRING(pszName);

	pent = CREATE_NAMED_ENTITY(istr);
	if ( FNullEnt( pent ) )
	{
		ALERT ( at_console, "NULL Ent in GiveNamedItem!\n" );
		return;
	}
	VARS( pent )->origin = pev->origin;
	pent->v.spawnflags |= SF_NORESPAWN;

	DispatchSpawn( pent );
	DispatchTouch( pent, ENT( pev ) );
}



CBaseEntity *FindEntityForward( CBaseEntity *pMe )
{
	TraceResult tr;

	UTIL_MakeVectors(pMe->pev->v_angle);
	UTIL_TraceLine(pMe->pev->origin + pMe->pev->view_ofs,pMe->pev->origin + pMe->pev->view_ofs + gpGlobals->v_forward * 8192,dont_ignore_monsters, pMe->edict(), &tr );
	if ( tr.flFraction != 1.0 && !FNullEnt( tr.pHit) )
	{
		CBaseEntity *pHit = CBaseEntity::Instance( tr.pHit );
		return pHit;
	}
	return NULL;
}


BOOL CBasePlayer :: FlashlightIsOn( void )
{
	return FBitSet(pev->effects, EF_DIMLIGHT);
}


void CBasePlayer :: FlashlightTurnOn( void )
{
	if ( !g_pGameRules->FAllowFlashlight() )
	{
		return;
	}

	if ( (pev->weapons & (1<<WEAPON_SUIT)) )
	{
		EMIT_SOUND_DYN( ENT(pev), CHAN_WEAPON, SOUND_FLASHLIGHT_ON, 1.0, ATTN_NORM, 0, PITCH_NORM );
		SetBits(pev->effects, EF_DIMLIGHT);
		MESSAGE_BEGIN( MSG_ONE, gmsgFlashlight, NULL, pev );
		WRITE_BYTE(1);
		WRITE_BYTE(m_iFlashBattery);
		MESSAGE_END();

		m_flFlashLightTime = FLASH_DRAIN_TIME + gpGlobals->time;

	}
}


void CBasePlayer :: FlashlightTurnOff( void )
{
	EMIT_SOUND_DYN( ENT(pev), CHAN_WEAPON, SOUND_FLASHLIGHT_OFF, 1.0, ATTN_NORM, 0, PITCH_NORM );
    ClearBits(pev->effects, EF_DIMLIGHT);
	MESSAGE_BEGIN( MSG_ONE, gmsgFlashlight, NULL, pev );
	WRITE_BYTE(0);
	WRITE_BYTE(m_iFlashBattery);
	MESSAGE_END();

	m_flFlashLightTime = FLASH_CHARGE_TIME + gpGlobals->time;

}

/*
===============
ForceClientDllUpdate

When recording a demo, we need to have the server tell us the entire client state
so that the client side .dll can behave correctly.
Reset stuff so that the state is transmitted.
===============
*/
void CBasePlayer :: ForceClientDllUpdate( void )
{
	m_iClientHealth  = -1;
	m_iClientBattery = -1;
	m_iTrain |= TRAIN_NEW;  // Force new train message.
	m_fWeapon = FALSE;          // Force weapon send
	m_fKnownItem = FALSE;    // Force weaponinit messages.
	m_fInitHUD = TRUE;		// Force HUD gmsgResetHUD message

	// Now force all the necessary messages
	//  to be sent.
	UpdateClientData();
}

/*
============
ImpulseCommands
============
*/
int gmsgLogo = 0;

void CBasePlayer::ImpulseCommands( )
{
	TraceResult	tr;// UNDONE: kill me! This is temporary for PreAlpha CDs

	// Handle use events
	PlayerUse();

	int iImpulse = (int)pev->impulse;
	switch ( iImpulse )
	{
	case 99:
		{
			// Toggle the logo
			if ( !gmsgLogo )
			{
				gmsgLogo = REG_USER_MSG( "Logo", 1 );

				MESSAGE_BEGIN( MSG_ONE, gmsgLogo, NULL, pev );
					WRITE_BYTE( 1 );
				MESSAGE_END();
			}
			else
			{
				MESSAGE_BEGIN( MSG_ONE, gmsgLogo, NULL, pev );
					WRITE_BYTE( 0 );
				MESSAGE_END();

				gmsgLogo = 0;
			}
			break;
		}
	case 50:
		m_iHideHUD |= HIDEHUD_ALL;
		break;

	case 100:
		// temporary flashlight for level designers
		if ( FlashlightIsOn() )
		{
			FlashlightTurnOff();
		}
		else
		{
			FlashlightTurnOn();
		}
		break;

	case 201:// paint decal

		if ( gpGlobals->time < m_flNextDecalTime )
		{
			// too early!
			break;
		}

		UTIL_MakeVectors( pev->v_angle );
		UTIL_TraceLine( pev->origin + pev->view_ofs, pev->origin + pev->view_ofs + gpGlobals->v_forward * 128, ignore_monsters, ENT( pev ), &tr );

		if ( tr.flFraction != 1.0 )
		{// line hit something, so paint a decal
			m_flNextDecalTime = gpGlobals->time + decalfrequency.value;
			CSprayCan *pCan = GetClassPtr( (CSprayCan *)NULL );
			pCan->Spawn( pev );
		}

		break;

	default:
		// check all of the cheat impulse commands now
		CheatImpulseCommands( iImpulse );
		break;
	}

	pev->impulse = 0;
}

//=========================================================
//=========================================================
void CBasePlayer::CheatImpulseCommands( int iImpulse )
{
	// TFC: only the debugging impulses are left
	if ( CVAR_GET_FLOAT( "sv_cheats" ) == 0 )
		return;

	switch ( iImpulse )
	{
	case 104:
		// Dump all of the global state varaibles (and global entity names)
		gGlobalState.DumpGlobals();
		break;

	case 107:
		{
			TraceResult tr;

			edict_t *pWorld = g_engfuncs.pfnPEntityOfEntIndex( 0 );

			Vector start = pev->origin + pev->view_ofs;
			Vector end = start + gpGlobals->v_forward * 1024;
			UTIL_TraceLine( start, end, ignore_monsters, edict(), &tr );
			if ( tr.pHit )
				pWorld = tr.pHit;
			const char *pTextureName = TRACE_TEXTURE( pWorld, start, end );
			if ( pTextureName )
				ALERT( at_console, "Texture: %s\n", pTextureName );
		}
		break;

	case 195:// show shortest paths for entire level to nearest node
		{
			Create( "node_viewer_fly", pev->origin, pev->angles );
		}
		break;

	case 196:// show shortest paths for entire level to nearest node
		{
			Create( "node_viewer_large", pev->origin, pev->angles );
		}
		break;

	case 197:// show shortest paths for entire level to nearest node
		{
			Create( "node_viewer_human", pev->origin, pev->angles );
		}
		break;

	case 199:// show nearest node and all connections
		{
			ALERT( at_console, "%d\n", WorldGraph.FindNearestNode( pev->origin, bits_NODE_GROUP_REALM ) );
			WorldGraph.ShowNodeConnections( WorldGraph.FindNearestNode( pev->origin, bits_NODE_GROUP_REALM ) );
		}
		break;
	}
}

//
// Add a weapon to the player (Item == Weapon == Selectable Object)
//
int CBasePlayer::AddPlayerItem( CBasePlayerItem *pItem )
{
	CBasePlayerItem *pInsert;
	
	pInsert = m_rgpPlayerItems[pItem->iItemSlot()];

	while (pInsert)
	{
		if (FClassnameIs( pInsert->pev, STRING( pItem->pev->classname) ))
		{
			if (pItem->AddDuplicate( pInsert ))
			{
				g_pGameRules->PlayerGotWeapon ( this, pItem );
				pItem->CheckRespawn();

				// ugly hack to update clip w/o an update clip message
				pInsert->UpdateItemInfo( );
				if (m_pActiveItem)
					m_pActiveItem->UpdateItemInfo( );

				pItem->Kill( );
			}
			else if (gEvilImpulse101)
			{
				// FIXME: remove anyway for deathmatch testing
				pItem->Kill( );
			}
			return FALSE;
		}
		pInsert = pInsert->m_pNext;
	}


	if (pItem->AddToPlayer( this ))
	{
		g_pGameRules->PlayerGotWeapon ( this, pItem );
		pItem->CheckRespawn();

		pItem->m_pNext = m_rgpPlayerItems[pItem->iItemSlot()];
		m_rgpPlayerItems[pItem->iItemSlot()] = pItem;

		// should we switch to this item?
		if ( g_pGameRules->FShouldSwitchWeapon( this, pItem ) )
		{
			SwitchWeapon( pItem );
		}

		return TRUE;
	}
	else if (gEvilImpulse101)
	{
		// FIXME: remove anyway for deathmatch testing
		pItem->Kill( );
	}
	return FALSE;
}



int CBasePlayer::RemovePlayerItem( CBasePlayerItem *pItem )
{
	if (m_pActiveItem == pItem)
	{
		ResetAutoaim( );
		pItem->Holster( );
		pItem->pev->nextthink = 0;// crowbar may be trying to swing again, etc.
		pItem->SetThink( NULL );
		m_pActiveItem = NULL;
		pev->viewmodel = 0;
		pev->weaponmodel = 0;
	}
	if ( m_pLastItem == pItem )
		m_pLastItem = NULL;

	CBasePlayerItem *pPrev = m_rgpPlayerItems[pItem->iItemSlot()];

	if (pPrev == pItem)
	{
		m_rgpPlayerItems[pItem->iItemSlot()] = pItem->m_pNext;
		return TRUE;
	}
	else
	{
		while (pPrev && pPrev->m_pNext != pItem)
		{
			pPrev = pPrev->m_pNext;
		}
		if (pPrev)
		{
			pPrev->m_pNext = pItem->m_pNext;
			return TRUE;
		}
	}
	return FALSE;
}


//
// Returns the unique ID for the ammo, or -1 if error
//
int CBasePlayer :: GiveAmmo( int iCount, char *szName, int iMax, int *pIndex )
{
	if ( !szName )
	{
		// no ammo.
		return -1;
	}

	if ( !g_pGameRules->CanHaveAmmo( this, szName, iMax ) )
	{
		// game rules say I can't have any more of this ammo type.
		return -1;
	}

	int i = GetAmmoIndex( szName );

	if ( i < 0 || i >= MAX_AMMO_SLOTS )
		return -1;

	int iAdd = min( iCount, iMax - m_rgAmmo[i] );
	if ( iAdd < 1 )
		return i;

	m_rgAmmo[ i ] += iAdd;

	// TFC sends no AmmoPickup message here
	if ( pIndex )
		*pIndex = i;

	return i;
}


/*
============
ItemPreFrame

Called every frame by the player PreThink
============
*/
void CBasePlayer::ItemPreFrame()
{
#if defined( CLIENT_WEAPONS )
    if ( m_flNextAttack > 0 )
#else
    if ( gpGlobals->time < m_flNextAttack )
#endif
	{
		return;
	}

	if (!m_pActiveItem)
		return;

	m_pActiveItem->ItemPreFrame( );
}


/*
============
ItemPostFrame

Called every frame by the player PostThink
============
*/
void CBasePlayer::ItemPostFrame()
{
	static int fInSelect = FALSE;

	// check if the player is using a tank
	if ( m_pTank != NULL )
		return;

#if defined( CLIENT_WEAPONS )
    if ( m_flNextAttack > 0 )
#else
    if ( gpGlobals->time < m_flNextAttack )
#endif
	{
		return;
	}

	ImpulseCommands();

	if (!m_pActiveItem)
		return;

	m_pActiveItem->ItemPostFrame( );
}

int CBasePlayer::AmmoInventory( int iAmmoIndex )
{
	if (iAmmoIndex == -1)
	{
		return -1;
	}

	return m_rgAmmo[ iAmmoIndex ];
}

int CBasePlayer::GetAmmoIndex(const char *psz)
{
	int i;

	if (!psz)
		return -1;

	for (i = 1; i < MAX_AMMO_SLOTS; i++)
	{
		if ( !CBasePlayerItem::AmmoInfoArray[i].pszName )
			continue;

		if (stricmp( psz, CBasePlayerItem::AmmoInfoArray[i].pszName ) == 0)
			return i;
	}

	return -1;
}

// Called from UpdateClientData
// makes sure the client has all the necessary ammo info,  if values have changed
// TFC: ammo slots of the four TF ammo types, found once
static int rocket_slot;
static int cell_slot;
static int shell_slot;
static int nail_slot;

void CBasePlayer::SendAmmoUpdate(void)
{
	// find which HL ammo slots carry the TF ammo types
	if ( !rocket_slot || !cell_slot )
	{
		for ( int i = 0; i < MAX_AMMO_SLOTS; i++ )
		{
			const char *pszName = CBasePlayerItem::AmmoInfoArray[i].pszName;
			if ( !pszName || !*pszName )
				continue;

			if ( !strcmp( pszName, "rockets" ) )
				rocket_slot = i;
			else if ( !strcmp( pszName, "uranium" ) )
				cell_slot = i;
			else if ( !strcmp( pszName, "buckshot" ) )
				shell_slot = i;
			else if ( !strcmp( pszName, "9mm" ) )
				nail_slot = i;
		}
	}

	// the weapons read m_rgAmmo, the TF code keeps ammo_* up to date
	m_rgAmmo[rocket_slot] = ammo_rockets;
	m_rgAmmo[cell_slot] = ammo_cells;
	m_rgAmmo[shell_slot] = ammo_shells;
	m_rgAmmo[nail_slot] = ammo_nails;

	for (int i=0; i < MAX_AMMO_SLOTS;i++)
	{
		if (m_rgAmmo[i] != m_rgAmmoLast[i])
		{
			m_rgAmmoLast[i] = m_rgAmmo[i];

			// send "Ammo" update message
			MESSAGE_BEGIN( MSG_ONE, gmsgAmmoX, NULL, pev );
				WRITE_BYTE( i );
				WRITE_BYTE( max( min( m_rgAmmo[i], 254 ), 0 ) );  // clamp the value to one byte
			MESSAGE_END();
		}
	}
}

/*
=========================================================
	UpdateClientData

resends any changed player HUD info to the client.
Called every frame by PlayerPreThink
Also called at start of demo recording and playback by
ForceClientDllUpdate to ensure the demo gets messages
reflecting all of the HUD state info.
=========================================================
*/
void CBasePlayer :: UpdateClientData( void )
{
	if ( m_fInitHUD )
	{
		m_fInitHUD = FALSE;
		gInitHUD = FALSE;

		MESSAGE_BEGIN( MSG_ONE, gmsgResetHUD, NULL, pev );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		if ( !m_fGameHUDInitialized )
		{
			m_bSentBuildingEvents = FALSE;

			MESSAGE_BEGIN( MSG_ONE, gmsgInitHUD, NULL, pev );
			MESSAGE_END();

			// Secondary ammo is grenades
			MESSAGE_BEGIN( MSG_ONE, gmsgSetSecAmmoIcon, NULL, pev );
				WRITE_STRING( "grenade" );
			MESSAGE_END();

			g_pGameRules->InitHUD( this );
			m_fGameHUDInitialized = TRUE;
			m_iObserverLastMode = OBS_ROAMING;
		}

		TeamFortress_InitStatusBar();

		// Resend all the ammo
		for ( int i = 0; i < MAX_AMMO_SLOTS; i++ )
			m_rgAmmoLast[i] = -1;
	}

	// Message saved up by the spawn point until the client is ready
	if ( delayed_spawn_message )
	{
		UTIL_ShowMessage( STRING( delayed_spawn_message ), edict() );
		delayed_spawn_message = 0;
	}

	if ( m_iHideHUD != m_iClientHideHUD )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgHideWeapon, NULL, pev );
			WRITE_BYTE( m_iHideHUD );
		MESSAGE_END();

		m_iClientHideHUD = m_iHideHUD;
	}

	if ( m_iFOV != m_iClientFOV )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgSetFOV, NULL, pev );
			WRITE_BYTE( m_iFOV );
		MESSAGE_END();

		// cache FOV change at end of function, so weapon updates can see that FOV has changed
		m_iClientFOV = m_iFOV;
	}

	if ( pev->health != m_iClientHealth )
	{
		int iHealth = max( pev->health, 0.0f );  // make sure that no negative health values are sent
		if ( pev->health > 255 )
			iHealth = 255;
		if ( pev->health > 0.0f && pev->health <= 1.0f )
			iHealth = 1;

		// send "health" update message
		MESSAGE_BEGIN( MSG_ONE, gmsgHealth, NULL, pev );
			WRITE_BYTE( iHealth );
		MESSAGE_END();

		m_iClientHealth = pev->health;
	}

	if ( pev->dmg_take || pev->dmg_save || m_bitsHUDDamage != m_bitsDamageType )
	{
		// Comes from inside me if not set
		Vector damageOrigin = pev->origin;
		// send "damage" message
		// causes screen to flash, and pain compass to show direction of damage
		edict_t *other = pev->dmg_inflictor;
		if ( other )
		{
			CBaseEntity *pEntity = CBaseEntity::Instance( other );
			if ( pEntity )
				damageOrigin = pEntity->Center();
		}

		MESSAGE_BEGIN( MSG_ONE, gmsgDamage, NULL, pev );
			WRITE_BYTE( pev->dmg_save );
			WRITE_BYTE( pev->dmg_take );
			WRITE_LONG( m_bitsDamageType );
			WRITE_COORD( damageOrigin.x );
			WRITE_COORD( damageOrigin.y );
			WRITE_COORD( damageOrigin.z );
		MESSAGE_END();

		pev->dmg_take = 0;
		pev->dmg_save = 0;
		m_bitsHUDDamage = m_bitsDamageType;

		// Clear off non-time-based damage indicators
		m_bitsDamageType &= 0x7fc000;
	}

	// Primed grenade icon
	if ( ( tfstate & TFSTATE_GRENPRIMED ) != fClientGrenadePrimed )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pev );
			WRITE_BYTE( tfstate & TFSTATE_GRENPRIMED );
			WRITE_CHAR( 100 );
			WRITE_CHAR( 95 );
			WRITE_STRING( m_iszGrenadeName ? STRING( m_iszGrenadeName ) : "normalgrenade" );
			WRITE_BYTE( 255 );
			WRITE_BYTE( 160 );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		fClientGrenadePrimed = tfstate & TFSTATE_GRENPRIMED;
		if ( !fClientGrenadePrimed )
			m_iszGrenadeName = 0;
	}

	// Update all the items
	if ( m_pActiveItem )
		m_pActiveItem->UpdateClientData( this );

	// Cache and client weapon change
	m_pClientActiveItem = m_pActiveItem;

	// Update Status Bar
	if ( m_flNextSBarUpdateTime < gpGlobals->time )
	{
		UpdateLowPriorityClientData();
		TeamFortress_UpdateStatusBar();
		m_flNextSBarUpdateTime = gpGlobals->time + 0.2;
	}

	UpdateClientCommandMenu();
}



//=========================================================
// FBecomeProne - Overridden for the player to set the proper
// physics flags when a barnacle grabs player.
//=========================================================
BOOL CBasePlayer :: FBecomeProne ( void )
{
	m_afPhysicsFlags |= PFLAG_ONBARNACLE;
	return TRUE;
}

//=========================================================
// BarnacleVictimBitten - bad name for a function that is called
// by Barnacle victims when the barnacle pulls their head
// into its mouth. For the player, just die.
//=========================================================
void CBasePlayer :: BarnacleVictimBitten ( entvars_t *pevBarnacle )
{
	TakeDamage ( pevBarnacle, pevBarnacle, pev->health + pev->armorvalue, DMG_SLASH | DMG_ALWAYSGIB );
}

//=========================================================
// BarnacleVictimReleased - overridden for player who has
// physics flags concerns. 
//=========================================================
void CBasePlayer :: BarnacleVictimReleased ( void )
{
	m_afPhysicsFlags &= ~PFLAG_ONBARNACLE;
}


//=========================================================
// Illumination 
// return player light level plus virtual muzzle flash
//=========================================================
int CBasePlayer :: Illumination( void )
{
	int iIllum = CBaseEntity::Illumination( );

	iIllum += m_iWeaponFlash;
	if (iIllum > 255)
		return 255;
	return iIllum;
}


void CBasePlayer :: EnableControl(BOOL fControl)
{
	if (!fControl)
		pev->flags |= FL_FROZEN;
	else
		pev->flags &= ~FL_FROZEN;

}


#define DOT_1DEGREE   0.9998476951564
#define DOT_2DEGREE   0.9993908270191
#define DOT_3DEGREE   0.9986295347546
#define DOT_4DEGREE   0.9975640502598
#define DOT_5DEGREE   0.9961946980917
#define DOT_6DEGREE   0.9945218953683
#define DOT_7DEGREE   0.9925461516413
#define DOT_8DEGREE   0.9902680687416
#define DOT_9DEGREE   0.9876883405951
#define DOT_10DEGREE  0.9848077530122
#define DOT_15DEGREE  0.9659258262891
#define DOT_20DEGREE  0.9396926207859
#define DOT_25DEGREE  0.9063077870367

// TFC: no autoaim, just the view direction
Vector CBasePlayer :: GetAutoaimVector( float flDelta )
{
	UTIL_MakeVectors( pev->v_angle + pev->punchangle );
	return gpGlobals->v_forward;
}


Vector CBasePlayer :: AutoaimDeflection( Vector &vecSrc, float flDist, float flDelta  )
{
	edict_t		*pEdict = g_engfuncs.pfnPEntityOfEntIndex( 1 );

	// TFC: autoaim is always off
	m_fOnTarget = FALSE;
	return g_vecZero;
}


void CBasePlayer :: ResetAutoaim( )
{
	if ( m_vecAutoAim.x != 0 || m_vecAutoAim.y != 0 )
	{
		m_vecAutoAim = Vector( 0, 0, 0 );
		SET_CROSSHAIRANGLE( edict(), 0, 0 );
	}
	m_fOnTarget = FALSE;
}

/*
=============
SetCustomDecalFrames

  UNDONE:  Determine real frame limit, 8 is a placeholder.
  Note:  -1 means no custom frames present.
=============
*/
void CBasePlayer :: SetCustomDecalFrames( int nFrames )
{
	if (nFrames > 0 &&
		nFrames < 8)
		m_nCustomSprayFrames = nFrames;
	else
		m_nCustomSprayFrames = -1;
}

/*
=============
GetCustomDecalFrames

  Returns the # of custom frames this player's custom clan logo contains.
=============
*/
int CBasePlayer :: GetCustomDecalFrames( void )
{
	return m_nCustomSprayFrames;
}


//=========================================================
// DropPlayerItem - drop the named item, or if no name,
// the active item. 
//=========================================================
void CBasePlayer::DropPlayerItem ( char *pszItemName )
{
	if ( !g_pGameRules->IsMultiplayer() || (weaponstay.value > 0) )
	{
		// no dropping in single player.
		return;
	}

	if ( !strlen( pszItemName ) )
	{
		// if this string has no length, the client didn't type a name!
		// assume player wants to drop the active item.
		// make the string null to make future operations in this function easier
		pszItemName = NULL;
	} 

	CBasePlayerItem *pWeapon;
	int i;

	for ( i = 0 ; i < MAX_ITEM_TYPES ; i++ )
	{
		pWeapon = m_rgpPlayerItems[ i ];

		while ( pWeapon )
		{
			if ( pszItemName )
			{
				// try to match by name. 
				if ( !strcmp( pszItemName, STRING( pWeapon->pev->classname ) ) )
				{
					// match! 
					break;
				}
			}
			else
			{
				// trying to drop active item
				if ( pWeapon == m_pActiveItem )
				{
					// active item!
					break;
				}
			}

			pWeapon = pWeapon->m_pNext; 
		}

		
		// if we land here with a valid pWeapon pointer, that's because we found the 
		// item we want to drop and hit a BREAK;  pWeapon is the item.
		if ( pWeapon )
		{
			if ( !g_pGameRules->GetNextBestWeapon( this, pWeapon ) )
				return; // can't drop the item they asked for, may be our last item or something we can't holster

			UTIL_MakeVectors ( pev->angles ); 

			pev->weapons &= ~(1<<pWeapon->m_iId);// take item off hud

			CWeaponBox *pWeaponBox = (CWeaponBox *)CBaseEntity::Create( "weaponbox", pev->origin + gpGlobals->v_forward * 10, pev->angles, edict() );
			pWeaponBox->pev->angles.x = 0;
			pWeaponBox->pev->angles.z = 0;
			pWeaponBox->PackWeapon( pWeapon );
			pWeaponBox->pev->velocity = gpGlobals->v_forward * 300 + gpGlobals->v_forward * 100;
			
			// drop half of the ammo for this weapon.
			int	iAmmoIndex;

			iAmmoIndex = GetAmmoIndex ( pWeapon->pszAmmo1() ); // ???
			
			if ( iAmmoIndex != -1 )
			{
				// this weapon weapon uses ammo, so pack an appropriate amount.
				if ( pWeapon->iFlags() & ITEM_FLAG_EXHAUSTIBLE )
				{
					// pack up all the ammo, this weapon is its own ammo type
					pWeaponBox->PackAmmo( MAKE_STRING(pWeapon->pszAmmo1()), m_rgAmmo[ iAmmoIndex ] );
					m_rgAmmo[ iAmmoIndex ] = 0; 

				}
				else
				{
					// pack half of the ammo
					pWeaponBox->PackAmmo( MAKE_STRING(pWeapon->pszAmmo1()), m_rgAmmo[ iAmmoIndex ] / 2 );
					m_rgAmmo[ iAmmoIndex ] /= 2; 
				}

			}

			return;// we're done, so stop searching with the FOR loop.
		}
	}
}

//=========================================================
// HasPlayerItem Does the player already have this item?
//=========================================================
BOOL CBasePlayer::HasPlayerItem( CBasePlayerItem *pCheckItem )
{
	CBasePlayerItem *pItem = m_rgpPlayerItems[pCheckItem->iItemSlot()];

	while (pItem)
	{
		if (FClassnameIs( pItem->pev, STRING( pCheckItem->pev->classname) ))
		{
			return TRUE;
		}
		pItem = pItem->m_pNext;
	}

	return FALSE;
}

//=========================================================
// HasNamedPlayerItem Does the player already have this item?
//=========================================================
BOOL CBasePlayer::HasNamedPlayerItem( char *pszItemName )
{
	CBasePlayerItem *pItem;
	int i;
 
	for ( i = 0 ; i < MAX_ITEM_TYPES ; i++ )
	{
		pItem = m_rgpPlayerItems[ i ];
		
		while (pItem)
		{
			if ( !strcmp( pszItemName, STRING( pItem->pev->classname ) ) )
			{
				return TRUE;
			}
			pItem = pItem->m_pNext;
		}
	}

	return FALSE;
}

//=========================================================
// HasPlayerItemFromID
// Just compare IDs, rather than classnames
//=========================================================

//=========================================================
// 
//=========================================================
BOOL CBasePlayer :: SwitchWeapon( CBasePlayerItem *pWeapon ) 
{
	if ( !pWeapon->CanDeploy() )
	{
		return FALSE;
	}
	
	ResetAutoaim( );
	
	if (m_pActiveItem)
	{
		m_pActiveItem->Holster( );
	}

	m_pActiveItem = pWeapon;
	pWeapon->Deploy( );

	return TRUE;
}

//=========================================================
// Dead HEV suit prop
//=========================================================
class CDeadHEV : public CBaseMonster 
{
public:
	void Spawn( void );
	int	Classify ( void ) { return	CLASS_HUMAN_MILITARY; }

	void KeyValue( KeyValueData *pkvd );

	int	m_iPose;// which sequence to display	-- temporary, don't need to save
	static char *m_szPoses[4];
};

char *CDeadHEV::m_szPoses[] = { "deadback", "deadsitting", "deadstomach", "deadtable" };

void CDeadHEV::KeyValue( KeyValueData *pkvd )
{
	if (FStrEq(pkvd->szKeyName, "pose"))
	{
		m_iPose = atoi(pkvd->szValue);
		pkvd->fHandled = TRUE;
	}
	else 
		CBaseMonster::KeyValue( pkvd );
}

LINK_ENTITY_TO_CLASS( monster_hevsuit_dead, CDeadHEV );

//=========================================================
// ********** DeadHEV SPAWN **********
//=========================================================
void CDeadHEV :: Spawn( void )
{
	PRECACHE_MODEL("models/player.mdl");
	SET_MODEL(ENT(pev), "models/player.mdl");

	pev->effects		= 0;
	pev->yaw_speed		= 8;
	pev->sequence		= 0;
	pev->body			= 1;
	m_bloodColor		= BLOOD_COLOR_RED;

	pev->sequence = LookupSequence( m_szPoses[m_iPose] );

	if (pev->sequence == -1)
	{
		ALERT ( at_console, "Dead hevsuit with bad pose\n" );
		pev->sequence = 0;
		pev->effects = EF_BRIGHTFIELD;
	}

	// Corpses have less health
	pev->health			= 8;

	MonsterInitDead();
}


class CStripWeapons : public CPointEntity
{
public:
	void	Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );

private:
};

LINK_ENTITY_TO_CLASS( player_weaponstrip, CStripWeapons );

void CStripWeapons :: Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	CBasePlayer *pPlayer = NULL;

	if ( pActivator && pActivator->IsPlayer() )
	{
		pPlayer = (CBasePlayer *)pActivator;
	}
	else if ( !g_pGameRules->IsDeathmatch() )
	{
		pPlayer = (CBasePlayer *)CBaseEntity::Instance( g_engfuncs.pfnPEntityOfEntIndex( 1 ) );
	}

	if ( pPlayer )
		pPlayer->RemoveAllItems( FALSE );
}


class CRevertSaved : public CPointEntity
{
public:
	void	Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void	EXPORT MessageThink( void );
	void	EXPORT LoadThink( void );
	void	KeyValue( KeyValueData *pkvd );

	virtual int		Save( CSave &save );
	virtual int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];

	inline	float	Duration( void ) { return pev->dmg_take; }
	inline	float	HoldTime( void ) { return pev->dmg_save; }
	inline	float	MessageTime( void ) { return m_messageTime; }
	inline	float	LoadTime( void ) { return m_loadTime; }

	inline	void	SetDuration( float duration ) { pev->dmg_take = duration; }
	inline	void	SetHoldTime( float hold ) { pev->dmg_save = hold; }
	inline	void	SetMessageTime( float time ) { m_messageTime = time; }
	inline	void	SetLoadTime( float time ) { m_loadTime = time; }

private:
	float	m_messageTime;
	float	m_loadTime;
};

LINK_ENTITY_TO_CLASS( player_loadsaved, CRevertSaved );

TYPEDESCRIPTION	CRevertSaved::m_SaveData[] = 
{
	DEFINE_FIELD( CRevertSaved, m_messageTime, FIELD_FLOAT ),	// These are not actual times, but durations, so save as floats
	DEFINE_FIELD( CRevertSaved, m_loadTime, FIELD_FLOAT ),
};

IMPLEMENT_SAVERESTORE( CRevertSaved, CPointEntity );

void CRevertSaved :: KeyValue( KeyValueData *pkvd )
{
	if (FStrEq(pkvd->szKeyName, "duration"))
	{
		SetDuration( atof(pkvd->szValue) );
		pkvd->fHandled = TRUE;
	}
	else if (FStrEq(pkvd->szKeyName, "holdtime"))
	{
		SetHoldTime( atof(pkvd->szValue) );
		pkvd->fHandled = TRUE;
	}
	else if (FStrEq(pkvd->szKeyName, "messagetime"))
	{
		SetMessageTime( atof(pkvd->szValue) );
		pkvd->fHandled = TRUE;
	}
	else if (FStrEq(pkvd->szKeyName, "loadtime"))
	{
		SetLoadTime( atof(pkvd->szValue) );
		pkvd->fHandled = TRUE;
	}
	else 
		CPointEntity::KeyValue( pkvd );
}

void CRevertSaved :: Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	UTIL_ScreenFadeAll( pev->rendercolor, Duration(), HoldTime(), pev->renderamt, FFADE_OUT );
	pev->nextthink = gpGlobals->time + MessageTime();
	SetThink( &CRevertSaved::MessageThink );
}


void CRevertSaved :: MessageThink( void )
{
	UTIL_ShowMessageAll( STRING(pev->message) );
	float nextThink = LoadTime() - MessageTime();
	if ( nextThink > 0 ) 
	{
		pev->nextthink = gpGlobals->time + nextThink;
		SetThink( &CRevertSaved::LoadThink );
	}
	else
		LoadThink();
}


void CRevertSaved :: LoadThink( void )
{
	if ( !gpGlobals->deathmatch )
	{
		SERVER_COMMAND("reload\n");
	}
}


//=========================================================
// Multiplayer intermission spots.
//=========================================================
class CInfoIntermission:public CPointEntity
{
	void Spawn( void );
	void Think( void );
};

void CInfoIntermission::Spawn( void )
{
	UTIL_SetOrigin( pev, pev->origin );
	pev->solid = SOLID_NOT;
	pev->effects = EF_NODRAW;
	pev->v_angle = g_vecZero;

	pev->nextthink = gpGlobals->time + 2;// let targets spawn!

}

void CInfoIntermission::Think ( void )
{
	edict_t *pTarget;

	// find my target
	pTarget = FIND_ENTITY_BY_TARGETNAME( NULL, STRING(pev->target) );

	if ( !FNullEnt(pTarget) )
	{
		pev->v_angle = UTIL_VecToAngles( (pTarget->v.origin - pev->origin).Normalize() );
		pev->v_angle.x = -pev->v_angle.x;
	}
}

LINK_ENTITY_TO_CLASS( info_intermission, CInfoIntermission );


//=========================================================
// TFC player functions
//=========================================================

// Player left the server: remove everything they own and stop anyone watching or copying them
void CBasePlayer::CleanupOnPlayerDisconnection( void )
{
	CBaseEntity *pEnt;

	TeamFortress_RemoveTimers();

	if ( tfstate & TFSTATE_GRENPRIMED )
	{
		bRemoveGrenade = TRUE;
		tfstate &= ~TFSTATE_GRENPRIMED;
	}

	// Lingering grenades and rockets
	RemoveOwnedEnt( "tf_weapon_napalmgrenade" );
	RemoveOwnedEnt( "tf_weapon_nailgrenade" );
	RemoveOwnedEnt( "tf_weapon_gasgrenade" );
	RemoveOwnedEnt( "tf_weapon_caltrop" );
	RemoveOwnedEnt( "tf_rpg_rocket" );
	RemoveOwnedEnt( "tf_ic_rocket" );

	TeamFortress_RemoveDetpacks();

	no_sentry_message = TRUE;
	no_dispenser_message = TRUE;
	no_entry_teleporter_message = TRUE;
	no_exit_teleporter_message = TRUE;
	Engineer_RemoveBuildings();

	// Detpacks: free anyone disarming ours, stop disarming anyone else's
	pEnt = UTIL_FindEntityByClassname( NULL, "detpack" );
	while ( pEnt )
	{
		if ( pEnt->weaponmode == 1 && pEnt->pev->enemy == edict() )
			pEnt->weaponmode = 0;

		if ( pEnt->pev->owner == edict() )
		{
			if ( pEnt->weaponmode == 1 && !FNullEnt( pEnt->pev->enemy ) )
			{
				CBasePlayer *pDisarmer = (CBasePlayer *)CBaseEntity::Instance( pEnt->pev->enemy );
				pDisarmer->tfstate &= ~TFSTATE_CANT_MOVE;
				pDisarmer->TeamFortress_SetSpeed();
				UTIL_Remove( pDisarmer->FindTimer( TF_TIMER_DETPACKDISARM ) );
			}

			pEnt->SetThink( &CBaseEntity::SUB_Remove );
			pEnt->pev->nextthink = gpGlobals->time;
		}

		pEnt = UTIL_FindEntityByClassname( pEnt, "detpack" );
	}

	CBasePlayer *pPlayer = NULL;
	while ( ( pPlayer = (CBasePlayer *)UTIL_FindEntityByClassname( pPlayer, "player" ) ) != NULL )
	{
		if ( FNullEnt( pPlayer->edict() ) )
			break;

		if ( !pPlayer->pev || pPlayer == this )
			continue;

		// Spies disguised as us need a new name
		if ( pPlayer->pev->playerclass == PC_SPY && pPlayer->undercover_target == this )
			pPlayer->TeamFortress_SpyCalcName();

		// Spectators watching us look elsewhere
		if ( pPlayer->m_hObserverTarget == this )
		{
			int iMode = pPlayer->pev->iuser1;
			pPlayer->pev->iuser1 = 0;
			pPlayer->m_hObserverTarget = NULL;
			pPlayer->Observer_SetMode( iMode );
		}
	}
}

#define STEP_CONCRETE	0		// default step sound
#define STEP_METAL		1		// metal floor
#define STEP_DIRT		2		// dirt, sand, rock
#define STEP_VENT		3		// ventilation duct
#define STEP_GRATE		4		// metal grating
#define STEP_TILE		5		// floor tiles
#define STEP_SLOSH		6		// shallow liquid puddle
#define STEP_WADE		7		// wading in liquid
#define STEP_LADDER		8		// climbing ladder

// Play a footstep sound for this surface
void CBasePlayer::PlayStepSound( int step, float fvol )
{
	static int iSkipStep = 0;

	if ( !g_pGameRules->PlayFootstepSounds( this, fvol ) )
		return;

	// irand - 0,1 for right foot, 2,3 for left foot
	// used to alternate left and right foot
	int irand = RANDOM_LONG( 0, 1 ) + ( m_iStepLeft * 2 );

	m_iStepLeft = !m_iStepLeft;

	switch ( step )
	{
	default:
	case STEP_CONCRETE:
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_step1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_step3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_step2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_step4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_METAL:
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_metal1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_metal3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_metal2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_metal4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_DIRT:
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_dirt1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_dirt3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_dirt2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_dirt4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_VENT:
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_duct1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_duct3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_duct2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_duct4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_GRATE:
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_grate1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_grate3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_grate2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_grate4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_TILE:
		if ( !RANDOM_LONG( 0, 4 ) )
			irand = 4;
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_tile1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_tile3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_tile2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_tile4.wav", fvol, ATTN_NORM );	break;
		case 4: EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_tile5.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_SLOSH:
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_slosh1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_slosh3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_slosh2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_slosh4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_WADE:
		if ( iSkipStep == 0 )
		{
			iSkipStep++;
			break;
		}

		if ( iSkipStep++ == 3 )
		{
			iSkipStep = 0;
		}

		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_wade1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_wade2.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_wade3.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_wade4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	case STEP_LADDER:
		switch ( irand )
		{
		// right foot
		case 0:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_ladder1.wav", fvol, ATTN_NORM );	break;
		case 1:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_ladder3.wav", fvol, ATTN_NORM );	break;
		// left foot
		case 2:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_ladder2.wav", fvol, ATTN_NORM );	break;
		case 3:	EMIT_SOUND( ENT( pev ), CHAN_BODY, "player/pl_ladder4.wav", fvol, ATTN_NORM );	break;
		}
		break;
	}
}

// Simple mapping from texture type character to step type
int MapTextureTypeStepType( char chTextureType )
{
	switch ( chTextureType )
	{
	default:
	case CHAR_TEX_CONCRETE:	return STEP_CONCRETE;
	case CHAR_TEX_METAL:	return STEP_METAL;
	case CHAR_TEX_DIRT:		return STEP_DIRT;
	case CHAR_TEX_VENT:		return STEP_VENT;
	case CHAR_TEX_GRATE:	return STEP_GRATE;
	case CHAR_TEX_TILE:		return STEP_TILE;
	case CHAR_TEX_SLOSH:	return STEP_SLOSH;
	}
}

// Glow from teleporting wears off
void CBasePlayer::TeleporterEffectThink( void )
{
	if ( m_flTeleporterEffectEndTime && m_flTeleporterEffectEndTime <= gpGlobals->time )
		TeleporterResetGlowshell( this );
}

// Track the texture under the player and the time of the next footstep.
// TFC: the client plays the footstep sounds.
void CBasePlayer::UpdateStepSound( void )
{
	float speed;
	float velrun;
	float velwalk;
	float flduck;
	int fLadder;

	if ( !g_pGameRules->PlayFootstepSounds( this, 1.0 ) )
		return;

	if ( m_flTimeStepSound > gpGlobals->time )
		return;

	if ( pev->flags & FL_FROZEN )
		return;

	speed = pev->velocity.Length();

	// determine if we are on a ladder
	fLadder = ( pev->movetype == MOVETYPE_FLY );// IsOnLadder();

	// UNDONE: need defined numbers for run, walk, crouch, crouch run velocities!!!!
	if ( FBitSet( pev->flags, FL_DUCKING ) || fLadder )
	{
		velwalk = 60;		// These constants should be based on cl_movespeedkey * cl_forwardspeed somehow
		velrun = 80;		// UNDONE: Move walking to server
		flduck = 0.1;
	}
	else
	{
		velwalk = 120;
		velrun = 210;
		flduck = 0.0;
	}

	// ALERT (at_console, "vel: %f\n", vecVel.Length());

	// if we're on a ladder or on the ground, and we're moving fast enough,
	// play step sound.  Also, if m_flTimeStepSound is zero, get the new
	// sound right away - we just landed, so play the step sound.

	if ( ( fLadder || FBitSet( pev->flags, FL_ONGROUND ) ) &&
		 pev->velocity != g_vecZero &&
		 ( speed >= velwalk || !m_flTimeStepSound ) )
	{
		SetAnimation( PLAYER_WALK );

		Vector center = ( pev->absmin + pev->absmax ) * 0.5;
		Vector knee = Vector( center.x, center.y, pev->absmin.z + ( pev->absmax.z - pev->absmin.z ) * 0.2 );
		Vector feet = Vector( center.x, center.y, pev->absmin.z );

		if ( fLadder )
		{
			m_flTimeStepSound = gpGlobals->time + 0.35 + flduck;
		}
		else if ( UTIL_PointContents( knee ) == CONTENTS_WATER )
		{
			m_flTimeStepSound = gpGlobals->time + 0.6 + flduck;
		}
		else
		{
			if ( UTIL_PointContents( feet ) != CONTENTS_WATER )
			{
				// find texture under player, if different from current texture,
				// get material type
				Vector start = Vector( center.x, center.y, pev->absmin.z + 4 );
				Vector end = Vector( center.x, center.y, pev->absmin.z - 24 );
				const char *pTextureName = TRACE_TEXTURE( pev->groundentity, start, end );

				if ( pTextureName )
				{
					// strip leading '-0' or '{' or '!'
					if ( *pTextureName == '-' )
						pTextureName += 2;
					if ( *pTextureName == '{' || *pTextureName == '!' )
						pTextureName++;

					if ( _strnicmp( pTextureName, m_szTextureName, CBTEXTURENAMEMAX - 1 ) )
					{
						char szbuffer[64];
						strcpy( szbuffer, pTextureName );
						szbuffer[CBTEXTURENAMEMAX - 1] = 0;
						strcpy( m_szTextureName, szbuffer );

						// get texture type
						m_chTextureType = TEXTURETYPE_Find( m_szTextureName );
					}
				}
			}

			m_flTimeStepSound = gpGlobals->time + ( speed < velrun ? 0.4 : 0.3 ) + flduck;
		}
	}
}

// Count down the powerups, warning shortly before they run out.
// Powerups given by goal items (TFSTATE_*) never run out while carried.
void CBasePlayer::CheckPowerups( void )
{
	BOOL bInvis = FALSE;
	BOOL bGlow = FALSE;
	BOOL bInvinc = FALSE;
	BOOL bQuad = FALSE;

	if ( pev->health <= 0 )
		return;

	pev->modelindex = g_ulModelIndexPlayer;    // don't use eyes

	// Invisibility
	if ( invisible_finished )
	{
		if ( tfstate & TFSTATE_INVISIBLE )
			invisible_finished = gpGlobals->time + 10;

		if ( invisible_finished < gpGlobals->time + 3 && !m_bLostInvisSound )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Item_ringfade" );
			EMIT_SOUND( ENT( pev ), CHAN_VOICE, "items/inv2.wav", 1, ATTN_NORM );
			m_bLostInvisSound = TRUE;
		}

		bInvis = ( invisible_finished >= gpGlobals->time );
		if ( !bInvis )
		{
			m_bLostInvisSound = FALSE;
			items &= ~IT_INVISIBILITY;
			invisible_finished = 0;
			pev->rendermode = kRenderNormal;
			pev->renderfx = kRenderFxNone;
			pev->renderamt = 0;
		}
	}

	// Invincibility
	if ( invincible_finished )
	{
		if ( tfstate & TFSTATE_INVINCIBLE )
			invincible_finished = gpGlobals->time + 10;

		if ( invincible_finished < gpGlobals->time + 3 && !m_bLostInvincSound )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Item_pentfade" );
			EMIT_SOUND( ENT( pev ), CHAN_VOICE, "items/protect2.wav", 1, ATTN_NORM );
			m_bLostInvincSound = TRUE;
		}

		if ( invincible_finished >= gpGlobals->time )
		{
			bGlow = TRUE;
			bInvinc = TRUE;
		}
		else
		{
			m_bLostInvincSound = FALSE;
			items &= ~IT_INVULNERABILITY;
			invincible_finished = 0;
			pev->renderfx = kRenderFxNone;
			pev->rendercolor = g_vecZero;
			pev->renderamt = 0;
		}
	}

	// Quad damage
	if ( super_damage_finished )
	{
		if ( tfstate & TFSTATE_QUAD )
			super_damage_finished = gpGlobals->time + 10;

		if ( super_damage_finished < gpGlobals->time + 3 && !m_bLostSuperSound )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Item_quadfade" );
			EMIT_SOUND( ENT( pev ), CHAN_VOICE, "items/damage3.wav", 1, ATTN_NORM );
			m_bLostSuperSound = TRUE;
		}

		if ( super_damage_finished >= gpGlobals->time )
		{
			bGlow = TRUE;
			bQuad = TRUE;
		}
		else
		{
			items &= ~IT_QUAD;
			m_bLostSuperSound = FALSE;
			super_damage_finished = 0;
			pev->renderfx = kRenderFxNone;
			pev->rendercolor = g_vecZero;
			pev->renderamt = 0;
		}
	}

	// Environment suit
	if ( radsuit_finished )
	{
		pev->air_finished = gpGlobals->time + 12;		// don't drown

		if ( tfstate & TFSTATE_RADSUIT )
			radsuit_finished = gpGlobals->time + 10;

		if ( radsuit_finished < gpGlobals->time + 3 && !m_bLostRadSound )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Item_suitfade" );
			EMIT_SOUND( ENT( pev ), CHAN_VOICE, "FVox/hev_shutdown.wav", 1, ATTN_NORM );
			m_bLostRadSound = TRUE;
		}

		if ( radsuit_finished < gpGlobals->time )
		{
			items &= ~IT_SUIT;
			radsuit_finished = 0;
			m_bLostRadSound = FALSE;
		}
	}

	// Glow: red for invulnerable, blue for quad, purple for both
	if ( bGlow && pev->renderfx == kRenderFxNone )
	{
		pev->renderfx = kRenderFxGlowShell;
		pev->renderamt = 100;

		if ( bQuad && bInvinc )
			pev->rendercolor = Vector( 255, 128, 255 );
		else if ( bInvinc )
			pev->rendercolor = Vector( 255, 128, 0 );
		else if ( bQuad )
			pev->rendercolor = Vector( 128, 128, 255 );
	}

	// Invisible players shimmer
	if ( bInvis )
	{
		pev->rendermode = kRenderTransAdd;
		pev->renderamt = (int)RANDOM_FLOAT( 1, 255 );
	}
}

// Tell the client it picked up some ammo
void SendAmmoPickupMessage( entvars_t *MsgDst, char *AmmoName, int AmmoAmount )
{
	if ( AmmoAmount <= 0 )
		return;

	MESSAGE_BEGIN( MSG_ONE, gmsgAmmoPickup, NULL, MsgDst );
		WRITE_BYTE( CBasePlayer::GetAmmoIndex( AmmoName ) );		// ammo ID
		WRITE_BYTE( AmmoAmount );		// amount
	MESSAGE_END();
}

// TFC ammo, capped at the class maximums. The HUD shows TF ammo using the
// HL ammo types: shells = buckshot, nails = 9mm, rockets, cells = uranium.
BOOL CBasePlayer::GiveTFAmmo( int shells, int nails, int rockets, int cells )
{
	ammo_shells += shells;
	if ( ammo_shells > maxammo_shells )
	{
		shells -= ammo_shells - maxammo_shells;
		ammo_shells = maxammo_shells;
	}

	ammo_nails += nails;
	if ( ammo_nails > maxammo_nails )
	{
		nails -= ammo_nails - maxammo_nails;
		ammo_nails = maxammo_nails;
	}

	ammo_rockets += rockets;
	if ( ammo_rockets > maxammo_rockets )
	{
		rockets -= ammo_rockets - maxammo_rockets;
		ammo_rockets = maxammo_rockets;
	}

	ammo_cells += cells;
	if ( ammo_cells > maxammo_cells )
	{
		cells -= ammo_cells - maxammo_cells;
		ammo_cells = maxammo_cells;
	}

	if ( !shells && !nails && !rockets && !cells )
		return FALSE;

	SendAmmoPickupMessage( pev, "buckshot", shells );
	SendAmmoPickupMessage( pev, "9mm", nails );
	SendAmmoPickupMessage( pev, "rockets", rockets );
	SendAmmoPickupMessage( pev, "uranium", cells );

	return TRUE;
}

// HUD info that doesn't need sending every frame
void CBasePlayer::UpdateLowPriorityClientData( void )
{
	if ( gDisplayTitle )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgShowGameTitle, NULL, pev );
			WRITE_BYTE( 0 );
		MESSAGE_END();
		gDisplayTitle = 0;
	}

	// Concussion wobble
	if ( m_iConcussion != m_iClientConcussion )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgConcuss, NULL, pev );
			WRITE_BYTE( m_iConcussion );
		MESSAGE_END();

		m_iClientConcussion = m_iConcussion;
	}

	// Armor and its class maximum
	if ( (int)pev->armorvalue != m_iClientBattery || (int)maxarmor != m_iMaxArmor )
	{
		m_iClientBattery = pev->armorvalue;
		m_iMaxArmor = maxarmor;

		MESSAGE_BEGIN( MSG_ONE, gmsgBattery, NULL, pev );
			WRITE_SHORT( (int)pev->armorvalue );
			WRITE_SHORT( (int)maxarmor );
		MESSAGE_END();
	}

	// Grenades
	if ( no_grenades_1 != cl_no_grenades_1 )
	{
		cl_no_grenades_1 = no_grenades_1;

		MESSAGE_BEGIN( MSG_ONE, gmsgGrenades, NULL, pev );
			WRITE_BYTE( 0 );
			WRITE_BYTE( no_grenades_1 );
		MESSAGE_END();
	}

	if ( no_grenades_2 != cl_no_grenades_2 )
	{
		cl_no_grenades_2 = no_grenades_2;

		MESSAGE_BEGIN( MSG_ONE, gmsgGrenades, NULL, pev );
			WRITE_BYTE( 1 );
			WRITE_BYTE( no_grenades_2 );
		MESSAGE_END();
	}

	// Scoreboard
	if ( m_iClientFrags != pev->frags || m_iClientDeaths != m_iDeaths || m_iClientPlayerClass != pev->playerclass || m_iClientTeam != pev->team )
	{
		MESSAGE_BEGIN( MSG_ALL, gmsgScoreInfo );
			WRITE_BYTE( ENTINDEX( edict() ) );
			WRITE_SHORT( pev->frags );
			WRITE_SHORT( m_iDeaths );
			WRITE_SHORT( pev->playerclass );
			WRITE_SHORT( pev->team );
		MESSAGE_END();

		m_iClientPlayerClass = pev->playerclass;
		m_iClientTeam = pev->team;
		m_iClientDeaths = m_iDeaths;
		m_iClientFrags = pev->frags;
	}

	if ( m_iTrain & TRAIN_NEW )
	{
		// send "health" update message
		MESSAGE_BEGIN( MSG_ONE, gmsgTrain, NULL, pev );
			WRITE_BYTE( m_iTrain & 0xF );
		MESSAGE_END();

		m_iTrain &= ~TRAIN_NEW;
	}

	// Status icons: leg damage, tranquilised, hallucinating
	if ( old_leg_damage != leg_damage )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pev );
			WRITE_BYTE( leg_damage > 0 );
			WRITE_STRING( "dmg_caltrop" );
			WRITE_BYTE( 255 );
			WRITE_BYTE( 160 );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		old_leg_damage = leg_damage;
	}

	if ( ( ( tfstate & TFSTATE_TRANQUILISED ) != 0 ) != ( clientTranq != 0 ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pev );
			WRITE_BYTE( ( tfstate & TFSTATE_TRANQUILISED ) != 0 );
			WRITE_STRING( "dmg_tranq" );
			WRITE_BYTE( 255 );
			WRITE_BYTE( 160 );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		clientTranq = ( tfstate & TFSTATE_TRANQUILISED ) ? 1 : 0;
	}

	if ( ( ( tfstate & TFSTATE_HALLUCINATING ) != 0 ) != ( clientHalluc != 0 ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pev );
			WRITE_BYTE( ( tfstate & TFSTATE_HALLUCINATING ) != 0 );
			WRITE_STRING( "dmg_haluc" );
			WRITE_BYTE( 255 );
			WRITE_BYTE( 160 );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		clientHalluc = ( tfstate & TFSTATE_HALLUCINATING ) ? 1 : 0;
	}

	// Flag icons for carried keys
	if ( items != m_iClientItems )
	{
		int iGained = ( items ^ m_iClientItems ) & items;
		int iLost = ( items ^ m_iClientItems ) & m_iClientItems;
		m_iClientItems = items;

		static const struct { int bit; const char *name; int r, g, b; } s_Flags[] =
		{
			{ IT_KEY1, "flag_blue",   0,   0,   255 },
			{ IT_KEY2, "flag_red",    255, 0,   0 },
			{ IT_KEY3, "flag_yellow", 255, 160, 0 },
			{ IT_KEY4, "flag_green",  0,   255, 0 },
		};

		for ( int i = 0; i < ARRAYSIZE( s_Flags ); i++ )
		{
			if ( iGained & s_Flags[i].bit )
			{
				MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pev );
					WRITE_BYTE( 1 );
					WRITE_STRING( s_Flags[i].name );
					WRITE_BYTE( s_Flags[i].r );
					WRITE_BYTE( s_Flags[i].g );
					WRITE_BYTE( s_Flags[i].b );
				MESSAGE_END();
			}
			else if ( iLost & s_Flags[i].bit )
			{
				MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pev );
					WRITE_BYTE( 0 );
					WRITE_STRING( s_Flags[i].name );
				MESSAGE_END();
			}
		}
	}

	if ( !m_fKnownItem )
	{
		m_fKnownItem = TRUE;

	// WeaponInit Message
	// byte  = # of weapons
	//
	// for each weapon:
	// byte		name str length (not including null)
	// bytes... name
	// byte		Ammo Type
	// byte		Ammo2 Type
	// byte		bucket
	// byte		bucket pos
	// byte		flags
	// ????		Icons

		// Send ALL the weapon info now
		for ( int i = 0; i < MAX_WEAPONS; i++ )
		{
			ItemInfo &II = CBasePlayerItem::ItemInfoArray[i];

			if ( !II.iId )
				continue;

			const char *pszName;
			if ( !II.pszName )
				pszName = "Empty";
			else
				pszName = II.pszName;

			MESSAGE_BEGIN( MSG_ONE, gmsgWeaponList, NULL, pev );
				WRITE_STRING( pszName );			// string	weapon name
				WRITE_BYTE( GetAmmoIndex( II.pszAmmo1 ) );	// byte		Ammo Type
				WRITE_BYTE( II.iAmmo1 );				// byte     Max Ammo 1
				WRITE_BYTE( GetAmmoIndex( II.pszAmmo2 ) );	// byte		Ammo2 Type
				WRITE_BYTE( II.iAmmo2 );				// byte     Max Ammo 2
				WRITE_BYTE( II.iSlot );					// byte		bucket
				WRITE_BYTE( II.iPosition );				// byte		bucket pos
				WRITE_BYTE( II.iId );					// byte		id (bit index into pev->weapons)
				WRITE_BYTE( II.iFlags );				// byte		Flags
			MESSAGE_END();
		}
	}

	SendAmmoUpdate();

	// Update all the items
	for ( int i = 0; i < MAX_ITEM_TYPES; i++ )
	{
		if ( m_rgpPlayerItems[i] )  // each item updates it's successors
			m_rgpPlayerItems[i]->UpdateClientData( this );
	}
}

// Spectating allowed, as last told to the clients
int g_ClientsAllowSpectator = 0;

// Build menu state bits (BuildSt message): BS_* in tf_defs.h

// State the client's command menu (VGUI) needs
void CBasePlayer::UpdateClientCommandMenu( void )
{
	if ( !m_bUpdatedCommandMenu )
	{
		m_bUpdatedCommandMenu = TRUE;

		// Classes each team can use (-1: civilians only)
		MESSAGE_BEGIN( MSG_ONE, gmsgValidClasses, NULL, pev );
			for ( int i = 0; i <= 4; i++ )
			{
				if ( TeamFortress_TeamIsCivilian( i ) )
					WRITE_SHORT( -1 );
				else
					WRITE_SHORT( illegalclasses[i] );
			}
		MESSAGE_END();

		// Team names, localized when they're the standard ones
		MESSAGE_BEGIN( MSG_ONE, gmsgTeamNames, NULL, pev );
			WRITE_BYTE( number_of_teams );
			for ( int i = 1; i <= 4; i++ )
			{
				char *pszTeam = GetTeamName( i );

				if ( !stricmp( pszTeam, "Blue" ) )
					WRITE_STRING( "#Team_Blue" );
				else if ( !stricmp( pszTeam, "Red" ) )
					WRITE_STRING( "#Team_Red" );
				else if ( !stricmp( pszTeam, "Yellow" ) )
					WRITE_STRING( "#Team_Yellow" );
				else if ( !stricmp( pszTeam, "Green" ) )
					WRITE_STRING( "#Team_Green" );
				else
					WRITE_STRING( pszTeam );
			}
		MESSAGE_END();

		g_ClientsAllowSpectator = allow_spectators.value;
		MESSAGE_BEGIN( MSG_ONE, gmsgAllowSpec, NULL, pev );
			WRITE_BYTE( g_ClientsAllowSpectator != 0 );
		MESSAGE_END();
	}

	if ( m_iClientIsFeigning != is_feigning )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgFeignState, NULL, pev );
			WRITE_BYTE( is_feigning );
		MESSAGE_END();

		m_iClientIsFeigning = is_feigning;
	}

	// Detpack: 0 none, 1 setting one, 2 have one
	if ( m_iClientIsDetpacking != is_detpacking || m_iClientDetpackAmmo != ammo_detpack )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgDetpackState, NULL, pev );
			if ( is_detpacking )
				WRITE_BYTE( 1 );
			else if ( ammo_detpack )
				WRITE_BYTE( 2 );
			else
				WRITE_BYTE( 0 );
		MESSAGE_END();

		m_iClientIsDetpacking = is_detpacking;
		m_iClientDetpackAmmo = ammo_detpack;
	}

	// Engineer buildings: built, or enough metal to build
	int iBuildState = is_building ? BS_BUILDING : 0;

	if ( has_sentry )
		iBuildState |= BS_HAS_SENTRYGUN;
	else if ( ammo_cells >= BUILD_COST_SENTRYGUN )
		iBuildState |= BS_CANB_SENTRYGUN;

	if ( has_dispenser )
		iBuildState |= BS_HAS_DISPENSER;
	else if ( ammo_cells >= BUILD_COST_DISPENSER )
		iBuildState |= BS_CANB_DISPENSER;

	if ( has_entry_teleporter )
		iBuildState |= BS_HAS_ENTRY_TELEPORTER;
	else if ( ammo_cells >= BUILD_COST_TELEPORTER )
		iBuildState |= BS_CANB_ENTRY_TELEPORTER;

	if ( has_exit_teleporter )
		iBuildState |= BS_HAS_EXIT_TELEPORTER;
	else if ( ammo_cells >= BUILD_COST_TELEPORTER )
		iBuildState |= BS_CANB_EXIT_TELEPORTER;

	if ( m_iClientBuildState != iBuildState )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgBuildState, NULL, pev );
			WRITE_SHORT( iBuildState );
		MESSAGE_END();

		m_iClientBuildState = iBuildState;
	}

	if ( m_iClientRandomPC != ( tfstate & TFSTATE_RANDOMPC ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgRandomPC, NULL, pev );
			WRITE_BYTE( tfstate & TFSTATE_RANDOMPC );
		MESSAGE_END();

		m_iClientRandomPC = tfstate & TFSTATE_RANDOMPC;
	}

	if ( g_ClientsAllowSpectator != allow_spectators.value )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgAllowSpec, NULL, pev );
			WRITE_BYTE( allow_spectators.value != 0 );
		MESSAGE_END();

		g_ClientsAllowSpectator = allow_spectators.value;
	}
}

// Can the player pick any class at all?
BOOL CBasePlayer::PositionAvailable( void )
{
	for ( int i = PC_SCOUT; i <= PC_ENGINEER; i++ )
	{
		if ( !CantChange( i, FALSE ) )
			return TRUE;
	}

	return FALSE;
}

// Is this class banned for the player's team, or full?
BOOL CBasePlayer::CantChange( int iClassNo, BOOL showMessage )
{
	if ( !( spy_off == TRUE && iClassNo == PC_SPY ) )
	{
		int iBit = ClassIllegalBit( iClassNo );

		if ( !( illegalclasses[0] & iBit ) && !( illegalclasses[ team_no ] & iBit ) || iClassNo == PC_CIVILIAN )
		{
			if ( !ClassIsRestricted( team_no, iClassNo ) )
				return FALSE;

			if ( showMessage )
				ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_enoughofclass" );
			return TRUE;
		}
	}

	if ( showMessage )
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_cantplayclass" );

	TeamFortress_DisplayLegalClasses();
	return TRUE;
}

void CBasePlayer::TeamFortress_PrintClassName( int pc )
{
	ClientPrint( pev, HUD_PRINTNOTIFY, UTIL_VarArgs( "#%s", sClassNames[pc] ) );
}

// Pick a class, or change class at the next respawn
void CBasePlayer::ChangeClass( int iClassNo )
{
	// Already this class: cancel a pending change
	if ( pev->playerclass == iClassNo )
	{
		if ( nextpc )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_changeclass", UTIL_VarArgs( "#%s", sClassNames[ pev->playerclass ] ) );
			nextpc = 0;
		}
		return;
	}

	if ( nextpc == iClassNo )
		return;

	if ( pev->playerclass && gpGlobals->time < m_fNextTeamOrClassChange )
		return;

	int iAutoKill = atoi( g_engfuncs.pfnInfoKeyValue( g_engfuncs.pfnGetInfoKeyBuffer( edict() ), "hud_classautokill" ) );

	if ( !PositionAvailable() )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_enoughofclass" );
		Menu_Class();
		return;
	}

	if ( TeamFortress_TeamIsCivilian( team_no ) && iClassNo != PC_CIVILIAN )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_nochangeclass" );
		return;
	}

	// Changing class: takes effect when they respawn
	if ( pev->playerclass )
	{
		if ( CantChange( iClassNo, TRUE ) )
			return;

		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_changeclass", UTIL_VarArgs( "#%s", sClassNames[iClassNo] ) );
		nextpc = iClassNo;

		// Kill themselves to change straight away
		if ( iAutoKill && pev->deadflag == DEAD_NO )
			ClientKill( edict() );

		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" changed role to \"%s\"\n",
			STRING( pev->netname ),
			GETPLAYERUSERID( edict() ),
			GETPLAYERAUTHID( edict() ),
			team_no ? GetTeamName( team_no ) : "SPECTATOR",
			sClassNames[iClassNo] );

		m_nFirstSpawn = TRUE;
		m_pszLastItem = NULL;
		immune_to_check = gpGlobals->time + 10;
		ResetMenu();
		m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
		return;
	}

	// First class: must be in a team
	if ( gpGlobals->teamplay && !team_no )
	{
		if ( gpGlobals->time <= 30 || !tfc_autoteam.value )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_mustteam" );
			return;
		}

		if ( !TeamFortress_TeamPutPlayerInTeam() )
			return;
	}

	if ( lives == 0 )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_nolives" );
		return;
	}

	if ( CantChange( iClassNo, TRUE ) )
	{
		Menu_Class();
		return;
	}

	if ( iClassNo == PC_RANDOM )
	{
		// Try classes at random until a legal one comes up, or all have been tried
		int iTried = 0xfe00;
		do
		{
			pev->playerclass = (int)floor( RANDOM_FLOAT( 0, 9 ) ) + 1;
			int pc = pev->playerclass;

			if ( !( pc == PC_SPY && spy_off == TRUE ) )
			{
				int iBit = ClassIllegalBit( pc );
				if ( !( illegalclasses[0] & iBit ) && !( illegalclasses[ team_no ] & iBit ) && !ClassIsRestricted( team_no, pc ) )
					break;
			}

			iTried |= ( 1 << ( pc - 1 ) ) & 0xffff;
		} while ( iTried != 0xffff );

		if ( CantChange( pev->playerclass, FALSE ) )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_enoughofclass" );
			pev->playerclass = 0;
			Menu_Class();
			return;
		}

		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_random" );
		tfstate |= TFSTATE_RANDOMPC;
	}

	m_nFirstSpawn = TRUE;
	m_pszLastItem = NULL;
	ResetMenu();
	m_fInitHUD = TRUE;
	m_iClientHideHUD = -1;
	m_iClientConcussion = -1;
	m_SbarString0[0] = '\n';
	m_SbarString1[0] = '\n';
	m_SbarString2[0] = '\n';
	if ( iClassNo != PC_RANDOM )
		pev->playerclass = iClassNo;
	nextpc = 0;

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" changed role to \"%s\"\n",
		STRING( pev->netname ),
		GETPLAYERUSERID( edict() ),
		GETPLAYERAUTHID( edict() ),
		team_no ? GetTeamName( team_no ) : "SPECTATOR",
		sClassNames[iClassNo] );

	// Leave spectator mode
	if ( pev->iuser1 || pev->iuser2 )
	{
		MESSAGE_BEGIN( MSG_ALL, gmsgSpectator );
			WRITE_BYTE( ENTINDEX( edict() ) );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		MESSAGE_BEGIN( MSG_ONE, gmsgResetFade, NULL, pev );
		MESSAGE_END();

		pev->iuser1 = pev->iuser2 = 0;
	}

	m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
	m_hObserverTarget = NULL;

	// Into the game
	pev->weapons |= ( 1 << WEAPON_SUIT );
	m_iHideHUD = 0;

	TeamFortress_SetEquipment();
	TeamFortress_SetHealth();
	TeamFortress_SetSpeed();
	TeamFortress_SetSkin();

	pev->takedamage = DAMAGE_AIM;
	pev->solid = SOLID_SLIDEBOX;
	pev->movetype = MOVETYPE_WALK;
	pev->flags = FL_CLIENT | FL_ONGROUND;
	pev->waterlevel = 0;
	pev->air_finished = gpGlobals->time + 12;
	pev->effects &= ~EF_NODRAW;
	pev->view_ofs = VEC_VIEW;
	pev->deadflag = DEAD_NO;
	m_flFallVelocity = 0;
	pev->sequence = LookupActivity( ACT_IDLE );

	if ( FBitSet( pev->flags, FL_DUCKING ) )
		UTIL_SetSize( pev, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX );
	else
		UTIL_SetSize( pev, VEC_HULL_MIN, VEC_HULL_MAX );

	TeamFortress_ExecClassScript();

	g_pGameRules->GetPlayerSpawnSpot( this );
}

// The player picks up the last weapon they had when they respawn
void CBasePlayer::SetLastWeapon( void )
{
	m_pLastItem = NULL;

	if ( m_nFirstSpawn || !m_pszLastItem )
		return;

	for ( int i = 0; i < MAX_ITEM_TYPES; i++ )
	{
		CBasePlayerItem *pItem = m_rgpPlayerItems[i];
		while ( pItem )
		{
			const char *pszName = CBasePlayerItem::ItemInfoArray[ pItem->m_iId ].pszName;
			if ( pszName && !strcmp( pszName, m_pszLastItem ) )
			{
				m_pLastItem = pItem;
				return;
			}

			pItem = pItem->m_pNext;
		}
	}
}

// Give the player their class's weapons, ammo, armor and grenades
void CBasePlayer::TeamFortress_SetEquipment( void )
{
	// Keys carried over from goal items
	int iOldItems = tf_items;

	items = 0;
	last_weaponmode = 0;
	last_weapon = 0;
	current_weapon = 0;
	weapons_carried = 0;
	tf_items = 0;
	if ( pev->playerclass != PC_SCOUT )
		tf_items_flags = 0;
	maxammo_medikit = 0;
	undercover_skin = 0;
	undercover_team = 0;
	ammo_medikit = 0;
	tfstate &= ~TFSTATE_RELOADING;
	armorclass = 0;
	is_building = 0;
	is_detpacking = 0;
	is_undercover = 0;
	is_feigning = 0;
	is_unableto_spy_or_teleport = 0;
	ammo_detpack = 0;
	maxammo_detpack = 0;
	items_allowed = 0;
	armor_allowed = 0;
	maxarmor = 0;
	weaponmode = 0;
	respawn_time = 0;
	heat = 0;

	if ( !team_no )
		lives = -1;

	items = iOldItems & ( IT_KEY1 | IT_KEY2 );

	switch ( pev->playerclass )
	{
	case PC_SCOUT:
		ammo_shells = 25;
		ammo_nails = 100;
		ammo_rockets = 0;
		ammo_cells = 50;
		maxammo_shells = 50;
		maxammo_nails = 200;
		maxammo_rockets = 25;
		maxammo_cells = 100;
		no_grenades_1 = 2;
		no_grenades_2 = 3;
		tp_grenades_1 = GR_TYPE_CALTROP;
		tp_grenades_2 = GR_TYPE_CONCUSSION;
		tf_items = NIT_SCANNER;
		ScannerOn = 0;
		if ( tf_items_flags <= 0 )
			tf_items_flags |= NIT_SCANNER_ENEMY;
		pev->armortype = 0.3;
		pev->armorvalue = 25;
		items |= IT_SHOTGUN | IT_NAILGUN;
		weapons_carried = WEAP_AXE | WEAP_SHOTGUN | WEAP_NAILGUN;
		items_allowed = WEAP_AXE | WEAP_SHOTGUN | WEAP_NAILGUN;
		armor_allowed = 0.3;
		maxarmor = 50;
		current_weapon = WEAP_NAILGUN;

		GiveNamedItem( "tf_weapon_axe" );
		GiveNamedItem( "tf_weapon_shotgun" );
		GiveNamedItem( "tf_weapon_ng" );
		ammo_shells -= 8;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_ng" );
		break;

	case PC_SNIPER:
		ammo_shells = 60;
		ammo_nails = 50;
		ammo_rockets = 0;
		ammo_cells = 0;
		maxammo_shells = 75;
		maxammo_nails = 100;
		maxammo_rockets = 25;
		maxammo_cells = 50;
		no_grenades_1 = 2;
		no_grenades_2 = 0;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_NONE;
		pev->armortype = 0.3;
		pev->armorvalue = 25;
		items |= IT_SHOTGUN | IT_SUPER_SHOTGUN | IT_NAILGUN;
		weapons_carried = WEAP_AXE | WEAP_SNIPER_RIFLE | WEAP_AUTO_RIFLE | WEAP_NAILGUN;
		items_allowed = WEAP_AXE | WEAP_SNIPER_RIFLE | WEAP_AUTO_RIFLE | WEAP_NAILGUN;
		armor_allowed = 0.3;
		maxarmor = 50;
		current_weapon = WEAP_SNIPER_RIFLE;

		GiveNamedItem( "tf_weapon_axe" );
		GiveNamedItem( "tf_weapon_ng" );
		GiveNamedItem( "tf_weapon_sniperrifle" );
		GiveNamedItem( "tf_weapon_autorifle" );
		SwitchWeapon( "tf_weapon_sniperrifle" );
		break;

	case PC_SOLDIER:
		ammo_shells = 50;
		ammo_nails = 0;
		ammo_rockets = 10;
		ammo_cells = 0;
		maxammo_shells = 100;
		maxammo_nails = 100;
		maxammo_rockets = 50;
		maxammo_cells = 50;
		no_grenades_1 = 2;
		no_grenades_2 = 1;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_NAIL;
		pev->armortype = 0.8;
		pev->armorvalue = 100;
		items |= IT_SHOTGUN | IT_SUPER_SHOTGUN | IT_ROCKET_LAUNCHER;
		weapons_carried = WEAP_AXE | WEAP_SHOTGUN | WEAP_SUPER_SHOTGUN | WEAP_ROCKET_LAUNCHER;
		items_allowed = WEAP_AXE | WEAP_SHOTGUN | WEAP_SUPER_SHOTGUN | WEAP_ROCKET_LAUNCHER;
		armor_allowed = 0.8;
		maxarmor = 200;
		current_weapon = WEAP_ROCKET_LAUNCHER;

		GiveNamedItem( "tf_weapon_axe" );
		GiveNamedItem( "tf_weapon_shotgun" );
		GiveNamedItem( "tf_weapon_supershotgun" );
		GiveNamedItem( "tf_weapon_rpg" );
		ammo_shells -= 24;	// loaded into the weapons
		ammo_rockets -= 4;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_rpg" );
		break;

	case PC_DEMOMAN:
		ammo_shells = 30;
		ammo_nails = 0;
		ammo_rockets = 20;
		ammo_cells = 0;
		maxammo_shells = 75;
		maxammo_nails = 50;
		maxammo_rockets = 50;
		maxammo_cells = 50;
		ammo_detpack = 1;
		maxammo_detpack = 1;
		no_grenades_1 = 2;
		no_grenades_2 = 2;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_MIRV;
		pev->armortype = 0.6;
		pev->armorvalue = 50;
		items |= IT_SHOTGUN | IT_GRENADE_LAUNCHER;
		weapons_carried = WEAP_AXE | WEAP_SHOTGUN | WEAP_GRENADE_LAUNCHER | WEAP_DETPACK;
		items_allowed = WEAP_AXE | WEAP_SHOTGUN | WEAP_GRENADE_LAUNCHER | WEAP_DETPACK;
		armor_allowed = 0.6;
		maxarmor = 120;
		current_weapon = WEAP_GRENADE_LAUNCHER;
		m_iGLClip = 6;

		GiveNamedItem( "tf_weapon_axe" );
		GiveNamedItem( "tf_weapon_shotgun" );
		GiveNamedItem( "tf_weapon_gl" );
		GiveNamedItem( "tf_weapon_pl" );
		ammo_shells -= 8;	// loaded into the weapons
		ammo_rockets -= 6;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_gl" );
		break;

	case PC_MEDIC:
		ammo_shells = 50;
		ammo_nails = 50;
		ammo_rockets = 0;
		ammo_cells = 0;
		maxammo_shells = 75;
		maxammo_nails = 150;
		maxammo_rockets = 25;
		maxammo_cells = 50;
		no_grenades_1 = 2;
		no_grenades_2 = 2;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_CONCUSSION;
		pev->armortype = 0.3;
		pev->armorvalue = 50;
		items |= IT_SHOTGUN | IT_SUPER_SHOTGUN | IT_SUPER_NAILGUN;
		weapons_carried = WEAP_BIOWEAPON | WEAP_MEDIKIT | WEAP_SHOTGUN | WEAP_SUPER_SHOTGUN | WEAP_SUPER_NAILGUN;
		items_allowed = WEAP_BIOWEAPON | WEAP_MEDIKIT | WEAP_SHOTGUN | WEAP_SUPER_SHOTGUN | WEAP_SUPER_NAILGUN;
		armor_allowed = 0.6;
		maxarmor = 100;
		current_weapon = WEAP_SUPER_NAILGUN;
		ammo_medikit = 50;
		maxammo_medikit = 100;

		// Medics regenerate health
		{
			CBaseEntity *pTimer = CreateTimer( TF_TIMER_REGENERATION );
			pTimer->pev->nextthink = gpGlobals->time + 3;
			pTimer->SetThink( &CBaseEntity::Timer_Regeneration );
		}

		GiveNamedItem( "tf_weapon_medikit" );
		GiveNamedItem( "tf_weapon_shotgun" );
		GiveNamedItem( "tf_weapon_supershotgun" );
		GiveNamedItem( "tf_weapon_superng" );
		ammo_shells -= 24;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_superng" );
		break;

	case PC_HVYWEAP:
		ammo_shells = 200;
		ammo_nails = 0;
		ammo_rockets = 0;
		ammo_cells = 30;
		maxammo_shells = 200;
		maxammo_nails = 200;
		maxammo_rockets = 25;
		maxammo_cells = 50;
		no_grenades_1 = 2;
		no_grenades_2 = 1;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_MIRV;
		pev->armortype = 0.8;
		pev->armorvalue = 150;
		items |= IT_SHOTGUN | IT_SUPER_SHOTGUN | IT_ROCKET_LAUNCHER;
		weapons_carried = WEAP_AXE | WEAP_SHOTGUN | WEAP_SUPER_SHOTGUN | WEAP_ASSAULT_CANNON;
		items_allowed = WEAP_AXE | WEAP_SHOTGUN | WEAP_SUPER_SHOTGUN | WEAP_ASSAULT_CANNON;
		armor_allowed = 0.8;
		maxarmor = 300;
		current_weapon = WEAP_ASSAULT_CANNON;

		GiveNamedItem( "tf_weapon_axe" );
		GiveNamedItem( "tf_weapon_shotgun" );
		GiveNamedItem( "tf_weapon_supershotgun" );
		GiveNamedItem( "tf_weapon_ac" );
		ammo_shells -= 24;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_ac" );
		break;

	case PC_PYRO:
		ammo_shells = 20;
		ammo_nails = 0;
		ammo_rockets = 5;
		ammo_cells = 120;
		maxammo_shells = 40;
		maxammo_nails = 50;
		maxammo_rockets = 20;
		maxammo_cells = 200;
		no_grenades_1 = 2;
		no_grenades_2 = 4;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_NAPALM;
		armorclass = AT_SAVEFIRE;
		pev->armortype = 0.6;
		pev->armorvalue = 50;
		items |= IT_SHOTGUN | IT_GRENADE_LAUNCHER | IT_ROCKET_LAUNCHER;
		weapons_carried = WEAP_AXE | WEAP_SHOTGUN | WEAP_FLAMETHROWER | WEAP_INCENDIARY;
		items_allowed = WEAP_AXE | WEAP_SHOTGUN | WEAP_FLAMETHROWER | WEAP_INCENDIARY;
		armor_allowed = 0.6;
		maxarmor = 150;
		current_weapon = WEAP_FLAMETHROWER;

		GiveNamedItem( "tf_weapon_axe" );
		GiveNamedItem( "tf_weapon_shotgun" );
		GiveNamedItem( "tf_weapon_ic" );
		GiveNamedItem( "tf_weapon_flamethrower" );
		ammo_shells -= 8;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_flamethrower" );
		break;

	case PC_CIVILIAN:
		ammo_shells = 0;
		ammo_nails = 0;
		ammo_rockets = 0;
		ammo_cells = 0;
		maxammo_shells = 0;
		maxammo_nails = 0;
		maxammo_rockets = 0;
		maxammo_cells = 0;
		no_grenades_1 = 0;
		no_grenades_2 = 0;
		tp_grenades_1 = GR_TYPE_NONE;
		tp_grenades_2 = GR_TYPE_NONE;
		pev->armortype = 0;
		pev->armorvalue = 0;
		items = 0;
		weapons_carried = WEAP_AXE;
		items_allowed = WEAP_AXE;
		armor_allowed = 0;
		maxarmor = 0;
		current_weapon = WEAP_AXE;

		GiveNamedItem( "tf_weapon_axe" );
		SwitchWeapon( "tf_weapon_axe" );
		break;

	case PC_SPY:
		ammo_shells = 40;
		ammo_nails = 50;
		ammo_rockets = 0;
		ammo_cells = 10;
		maxammo_shells = 40;
		maxammo_nails = 100;
		maxammo_rockets = 15;
		maxammo_cells = 30;
		no_grenades_1 = 2;
		no_grenades_2 = 2;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_GAS;
		pev->armortype = 0.6;
		pev->armorvalue = 25;
		items |= IT_SHOTGUN | IT_SUPER_SHOTGUN | IT_NAILGUN;
		weapons_carried = WEAP_AXE | WEAP_SUPER_SHOTGUN | WEAP_NAILGUN | WEAP_TRANQ;
		items_allowed = WEAP_AXE | WEAP_SUPER_SHOTGUN | WEAP_NAILGUN | WEAP_TRANQ;
		armor_allowed = 0.6;
		maxarmor = 100;
		current_weapon = WEAP_TRANQ;

		GiveNamedItem( "tf_weapon_knife" );
		GiveNamedItem( "tf_weapon_supershotgun" );
		GiveNamedItem( "tf_weapon_tranq" );
		GiveNamedItem( "tf_weapon_ng" );
		ammo_shells -= 16;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_tranq" );
		break;

	case PC_ENGINEER:
		ammo_shells = 20;
		ammo_nails = 25;
		ammo_rockets = 0;
		ammo_cells = 100;
		maxammo_shells = 50;
		maxammo_nails = 50;
		maxammo_rockets = 30;
		maxammo_cells = 200;
		no_grenades_1 = 2;
		no_grenades_2 = 2;
		tp_grenades_1 = GR_TYPE_NORMAL;
		tp_grenades_2 = GR_TYPE_EMP;
		pev->armortype = 0.3;
		pev->armorvalue = 25;
		items |= IT_SHOTGUN | IT_SUPER_SHOTGUN;
		weapons_carried = WEAP_SPANNER | WEAP_SUPER_SHOTGUN | WEAP_LASER;
		items_allowed = WEAP_SPANNER | WEAP_SUPER_SHOTGUN | WEAP_LASER;
		armor_allowed = 0.6;
		maxarmor = 50;
		current_weapon = WEAP_LASER;

		GiveNamedItem( "tf_weapon_spanner" );
		GiveNamedItem( "tf_weapon_railgun" );
		GiveNamedItem( "tf_weapon_supershotgun" );
		ammo_shells -= 16;	// loaded into the weapons
		SwitchWeapon( "tf_weapon_railgun" );
		break;

	case PC_UNDEFINED:
		// Observer until a class is picked
		ammo_shells = 0;
		ammo_nails = 0;
		ammo_rockets = 0;
		ammo_cells = 0;
		items = 0;
		no_grenades_1 = 0;
		no_grenades_2 = 0;
		tp_grenades_1 = 0;
		tp_grenades_2 = 0;
		pev->armortype = 0;
		pev->armorvalue = 0;
		weapons_carried = 0;
		current_weapon = 0;

		pev->flags &= FL_PROXY;
		pev->flags |= FL_CLIENT | FL_NOTARGET;
		pev->waterlevel = 3;
		pev->takedamage = DAMAGE_NO;
		pev->solid = SOLID_NOT;
		pev->movetype = MOVETYPE_NOCLIP;
		pev->modelindex = 0;
		tfstate |= TFSTATE_RELOADING;
		pev->effects |= EF_NODRAW;
		break;
	}

	SetLastWeapon();

	// Armor type item
	if ( pev->armortype >= 0.8 )
		items |= IT_ARMOR3;
	else if ( pev->armortype >= 0.6 )
		items |= IT_ARMOR2;
	else if ( pev->armortype >= 0.3 )
		items |= IT_ARMOR1;

	// Observers have no HUD
	if ( pev->playerclass == PC_UNDEFINED && !pev->iuser1 )
		m_iHideHUD |= HIDEHUD_ALL;
	else
		m_iHideHUD &= ~HIDEHUD_ALL;
}

// Switch to the weapon with this name
BOOL CBasePlayer::SwitchWeapon( const char *szWeaponName )
{
	for ( int i = 0; i < MAX_ITEM_TYPES; i++ )
	{
		CBasePlayerItem *pItem = m_rgpPlayerItems[i];
		while ( pItem )
		{
			const char *pszName = CBasePlayerItem::ItemInfoArray[ pItem->m_iId ].pszName;
			if ( pszName && !strcmp( pszName, szWeaponName ) )
				return SwitchWeapon( pItem );

			pItem = pItem->m_pNext;
		}
	}

	return FALSE;
}

// Max health for the class
void CBasePlayer::TeamFortress_SetHealth( void )
{
	switch ( pev->playerclass )
	{
	case PC_SCOUT:		pev->max_health = 75; break;
	case PC_SNIPER:		pev->max_health = 90; break;
	case PC_SOLDIER:	pev->max_health = 100; break;
	case PC_DEMOMAN:	pev->max_health = 90; break;
	case PC_MEDIC:		pev->max_health = 90; break;
	case PC_HVYWEAP:	pev->max_health = 100; break;
	case PC_PYRO:		pev->max_health = 100; break;
	case PC_CIVILIAN:	pev->max_health = 50; break;
	case PC_SPY:		pev->max_health = 90; break;
	case PC_ENGINEER:	pev->max_health = 80; break;
	case PC_UNDEFINED:
		pev->max_health = 1;
		pev->takedamage = DAMAGE_NO;
		break;
	}

	pev->health = pev->max_health;
}

// Max speed for the class, slowed by flags, leg wounds, tranquilisers and aiming
void CBasePlayer::TeamFortress_SetSpeed( void )
{
	float flMaxSpeed;

	// Observers
	if ( pev->iuser1 )
	{
		pev->maxspeed = ( pev->iuser1 == OBS_ROAMING ) ? 400 : 0;
		return;
	}

	// Frozen (setting a detpack, end of round) or no class
	if ( ( tfstate & TFSTATE_CANT_MOVE ) || !pev->playerclass )
	{
		pev->velocity = g_vecZero;
		pev->maxspeed = 1;
		return;
	}

	switch ( pev->playerclass )
	{
	case PC_SCOUT:		flMaxSpeed = 400; break;
	case PC_SNIPER:		flMaxSpeed = 300; break;
	case PC_SOLDIER:	flMaxSpeed = 240; break;
	case PC_DEMOMAN:	flMaxSpeed = 280; break;
	case PC_MEDIC:		flMaxSpeed = 320; break;
	case PC_HVYWEAP:	flMaxSpeed = 230; break;
	case PC_PYRO:		flMaxSpeed = 300; break;
	case PC_CIVILIAN:	flMaxSpeed = 240; break;
	default:			flMaxSpeed = 300; break;
	}

	// Carried goal items
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->pev->owner == edict() )
		{
			if ( pEnt->goal_activation & TFGI_SLOW )
				flMaxSpeed *= 0.5;
			else if ( pEnt->speed_reduction )
				flMaxSpeed *= pEnt->speed_reduction / 100.0;
		}

		pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
	}

	if ( tfstate & TFSTATE_TRANQUILISED )
		flMaxSpeed *= 0.5;

	// Leg wounds: 10% slower each, up to 6
	if ( leg_damage )
	{
		if ( leg_damage > 6 )
		{
			leg_damage = 6;
			flMaxSpeed *= 0.4;
		}
		else
			flMaxSpeed *= ( 10 - leg_damage ) / 10;
	}

	// Snipers aiming walk slowly
	if ( ( tfstate & TFSTATE_AIMING ) && flMaxSpeed > 80 )
		flMaxSpeed = 80;

	pev->maxspeed = flMaxSpeed;
}

// Model and team colors
void CBasePlayer::TeamFortress_SetSkin( void )
{
	char *infobuffer = g_engfuncs.pfnGetInfoKeyBuffer( edict() );
	int iClass = pev->playerclass;
	int iTeam = team_no;

	immune_to_check = gpGlobals->time + 10;

	// Disguised spies look like their disguise
	if ( pev->playerclass == PC_SPY )
	{
		if ( undercover_skin )
			iClass = undercover_skin;
		if ( undercover_team )
			iTeam = undercover_team;
	}

	if ( replacement_model )
	{
		g_engfuncs.pfnSetClientKeyValue( ENTINDEX( edict() ), infobuffer, "model", UTIL_VarArgs( "%s", STRING( replacement_model ) ) );
	}
	else
	{
		// The model's hull comes from the scout model
		SET_MODEL( edict(), "models/player/scout/scout.mdl" );

		if ( !sOldClassModelFiles[iClass] )
			pev->effects |= EF_NODRAW;
		else
			g_engfuncs.pfnSetClientKeyValue( ENTINDEX( edict() ), infobuffer, "model", sClassModels[iClass] );
	}

	if ( team_no )
	{
		g_engfuncs.pfnSetClientKeyValue( ENTINDEX( edict() ), infobuffer, "topcolor", UTIL_VarArgs( "%d", teamcolors[iTeam][iClass].topColor ) );
		g_engfuncs.pfnSetClientKeyValue( ENTINDEX( edict() ), infobuffer, "bottomcolor", UTIL_VarArgs( "%d", teamcolors[iTeam][iClass].bottomColor ) );
	}

	if ( FBitSet( pev->flags, FL_DUCKING ) )
		UTIL_SetSize( pev, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX );
	else
		UTIL_SetSize( pev, VEC_HULL_MIN, VEC_HULL_MAX );

	g_ulModelIndexPlayer = pev->modelindex;
}

BOOL CBasePlayer::IsLegalClass( int pc )
{
	if ( pc == PC_SPY && spy_off == TRUE )
		return FALSE;

	int iBit = ClassIllegalBit( pc );
	return !( illegalclasses[0] & iBit ) && !( illegalclasses[ team_no ] & iBit );
}

void CBasePlayer::TeamFortress_DisplayLegalClasses( void )
{
	static const struct { int bit; const char *name; } s_Classes[] =
	{
		{ TF_ILL_SCOUT,		"#Scout" },
		{ TF_ILL_SNIPER,	"#Sniper" },
		{ TF_ILL_SOLDIER,	"#Soldier" },
		{ TF_ILL_DEMOMAN,	"#Demoman" },
		{ TF_ILL_MEDIC,		"#Medic" },
		{ TF_ILL_HVYWEP,	"#HWGuy" },
		{ TF_ILL_PYRO,		"#Pyro" },
		{ TF_ILL_SPY,		"#Spy" },
		{ TF_ILL_ENGINEER,	"#Engineer" },
		{ TF_ILL_RANDOMPC,	"#RandomPC" },
	};

	ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_legalclasses" );

	int iTeamIllegal = illegalclasses[ team_no ];
	for ( int i = 0; i < ARRAYSIZE( s_Classes ); i++ )
	{
		if ( !( illegalclasses[0] & s_Classes[i].bit ) && !( iTeamIllegal & s_Classes[i].bit ) )
			ClientPrint( pev, HUD_PRINTNOTIFY, s_Classes[i].name );
	}
}

// The client runs the map's config script
void CBasePlayer::TeamFortress_ExecMapScript( void )
{
	if ( !exec_map_scripts )
		return;

	MESSAGE_BEGIN( MSG_ONE, SVC_TFC_EXECCLASS, NULL, pev );
		WRITE_BYTE( 0 );
	MESSAGE_END();
}

// Auto-team: the team with the fewest players that has room
BOOL CBasePlayer::TeamFortress_TeamPutPlayerInTeam( void )
{
	float flTeam = ceil( RANDOM_FLOAT( 0, number_of_teams ) );
	if ( flTeam == 0 )
		flTeam = number_of_teams;

	int iLowest = 33;
	for ( int i = 1; i < number_of_teams + 1; i++ )
	{
		// Don't count ourselves
		int iPlayers = TeamFortress_TeamGetNoPlayers( i ) - ( pev->team == i );

		if ( iPlayers < iLowest && iPlayers < teammaxplayers[i] )
		{
			flTeam = i;
			iLowest = iPlayers;
		}
	}

	return TeamFortress_TeamSet( (int)flTeam );
}

// Join a team (or change team, which kills the player)
BOOL CBasePlayer::TeamFortress_TeamSet( int tno )
{
	if ( team_no > 0 && team_no == tno )
		return FALSE;

	if ( !gpGlobals->teamplay )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_noteams" );
		return FALSE;
	}

	if ( tno > number_of_teams && number_of_teams != 0 )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "Game_onlyteams", UTIL_dtos1( number_of_teams ) );
		return FALSE;
	}

	if ( pev->deadflag == DEAD_DYING )
		return FALSE;

	if ( gpGlobals->time < m_fNextTeamOrClassChange )
		return FALSE;

	if ( TeamFortress_TeamGetNoPlayers( tno ) >= teammaxplayers[tno] )
	{
		if ( !team_no )
			Menu_Team();

		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_teamfull" );
		return FALSE;
	}

	if ( team_no <= 0 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_joinedteam", STRING( pev->netname ), UTIL_dtos1( tno ) );
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" joined team \"%s\"\n",
			STRING( pev->netname ),
			GETPLAYERUSERID( edict() ),
			GETPLAYERAUTHID( edict() ),
			team_no ? GetTeamName( team_no ) : "SPECTATOR",
			tno ? GetTeamName( tno ) : "SPECTATOR" );
	}
	else
	{
		// Changing team: lose everything and die
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_changedteam", STRING( pev->netname ), UTIL_dtos1( tno ) );
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" joined team \"%s\"\n",
			STRING( pev->netname ),
			GETPLAYERUSERID( edict() ),
			GETPLAYERAUTHID( edict() ),
			team_no ? GetTeamName( team_no ) : "SPECTATOR",
			tno ? GetTeamName( tno ) : "SPECTATOR" );

		if ( tfstate & TFSTATE_GRENPRIMED )
		{
			bRemoveGrenade = TRUE;
			tfstate &= ~TFSTATE_GRENPRIMED;
		}

		TeamFortress_RemoveBuildings();
		TeamFortress_RemoveDetpacks();
		TeamFortress_RemoveLiveGrenades();

		RemoveOwnedEnt( "tf_rpg_rocket" );
		RemoveOwnedEnt( "tf_ic_rocket" );

		pev->playerclass = 0;
		m_bitsDamageType &= 0xff003fff;
		m_fInitHUD = TRUE;
		m_fWeapon = FALSE;
		nextpc = 0;

		// The medic who infected us gets the frag
		if ( tfstate & TFSTATE_INFECTED )
		{
			CBaseEntity *pTimer = FindTimer( TF_TIMER_INFECTION );
			if ( pTimer )
			{
				CBaseEntity *pInfector = CBaseEntity::Instance( pTimer->pev->enemy );
				pInfector->real_frags++;
				if ( pInfector->team_no )
					teamfrags[ pInfector->team_no ]++;
				pInfector->pev->frags = pInfector->real_frags;
			}
		}

		tfstate = 0;
		RemoveAllItems( FALSE );
		m_fDontPackItemsUntil = gpGlobals->time + 0.2;

		pev->health = 0;
		Killed( NULL, pev, GIB_NEVER );

		// Changing team isn't a death
		real_frags++;
		pev->frags = real_frags;
		m_iDeaths--;
	}

	m_nFirstSpawn = TRUE;
	m_pszLastItem = NULL;
	team_no = tno;
	pev->team = tno;
	lives = teamlives[tno];
	m_fNextTeamOrClassChange = gpGlobals->time + 1.0;

	// Tell everyone
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
		if ( pPlayer )
		{
			MESSAGE_BEGIN( MSG_ONE, gmsgTeamInfo, NULL, pPlayer->pev );
				WRITE_BYTE( ENTINDEX( edict() ) );
				WRITE_STRING( g_pGameRules->GetTeamID( this ) );
			MESSAGE_END();
		}
	}

	TeamFortress_TeamIncreaseScore( team_no, 0 );
	TeamFortress_SetSkin();
	Menu_Class();
	return TRUE;
}

// Tell the player which classes their teammates are playing
void CBasePlayer::TeamFortress_TeamShowMemberClasses( void )
{
	BOOL bFound = FALSE;

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pOther = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( !pOther || pOther == this )
			continue;

		if ( IsAlly( pOther ) )
		{
			if ( !bFound )
				ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_others" );

			bFound = TRUE;
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_othersdetails", STRING( pOther->pev->netname ), UTIL_VarArgs( "#%s", sClassNames[ pOther->pev->playerclass ] ) );
		}
	}

	if ( !bFound )
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_noothers" );
}

// Destroy everything the engineer has built, or is building
void CBasePlayer::Engineer_RemoveBuildings( void )
{
	if ( is_building == TRUE )
	{
		tfstate &= ~TFSTATE_CANT_MOVE;
		TeamFortress_SetSpeed();

		CBaseEntity *pTimer = FindTimer( TF_TIMER_BUILD );
		if ( pTimer )
			dremove( pTimer );

		UTIL_Remove( building );
		building = NULL;
		is_building = FALSE;

		EMIT_SOUND_DYN( edict(), CHAN_STATIC, "weapons/building.wav", 0, 0, SND_STOP, PITCH_NORM );

		if ( m_pActiveItem )
			m_pActiveItem->Deploy();
	}

	DestroyBuilding( this, "building_dispenser" );
	DestroyBuilding( this, "building_sentrygun" );
	DestroyTeleporter( this, BUILD_TELEPORTER_ENTRANCE );
	DestroyTeleporter( this, BUILD_TELEPORTER_EXIT );
}

void CBasePlayer::TeamFortress_RemoveLiveGrenades( void )
{
	RemoveOwnedEnt( "tf_weapon_napalmgrenade" );
	RemoveOwnedEnt( "tf_weapon_nailgrenade" );
	RemoveOwnedEnt( "tf_weapon_gasgrenade" );
	RemoveOwnedEnt( "tf_weapon_caltrop" );
}

void CBasePlayer::TeamFortress_RemoveRockets( void )
{
	RemoveOwnedEnt( "tf_rpg_rocket" );
	RemoveOwnedEnt( "tf_ic_rocket" );
}

// Remove every entity of this class that the player owns
void CBasePlayer::RemoveOwnedEnt( char *pEntName )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, pEntName );
	while ( pEnt )
	{
		if ( pEnt->pev->owner == edict() )
			pEnt->pev->flags |= FL_KILLME;

		pEnt = UTIL_FindEntityByClassname( pEnt, pEntName );
	}
}

// Set the player on fire
void CBasePlayer::Ignite( entvars_t *pevInflictor, entvars_t *pevAttacker )
{
	TakeDamage( pevInflictor, pevAttacker, 6, DMG_BURN );

	if ( gpGlobals->time < cb_prematch_time )
		return;

	// Burning hard enough already: make the flames last longer
	if ( numflames >= 4 )
	{
		tfstate |= TFSTATE_RESET_FLAMETIME;
		return;
	}

	// Pyro armor protects
	if ( ( armorclass & AT_SAVEFIRE ) && pev->armorvalue > 0 )
		return;

	CBaseEntity *pOther = CBaseEntity::Instance( pevAttacker );

	// No team fire damage
	if ( ( (int)gpGlobals->teamplay & TEAMPLAY_NOEXPLOSIVE ) && IsAlly( pOther ) )
		return;

	numflames++;
	ClientPrint( pev, HUD_PRINTCENTER, "#Pyro_onfire" );
	EMIT_SOUND( ENT( pev ), CHAN_VOICE, "ambience/flameburst1.wav", 1, ATTN_NORM );

	if ( numflames == 1 )
	{
		CTFFlame *pFlame = CTFFlame::FlameSpawn( pOther, this );
		pFlame->pev->effects &= ~EF_NODRAW;
	}
}

void CBasePlayer::TF_AddFrags( int iFrags )
{
	real_frags += iFrags;
	if ( team_no )
		teamfrags[ team_no ] += iFrags;
	pev->frags = real_frags;
}

// Remove timers and states when the player dies or changes team
void CBasePlayer::TeamFortress_RemoveTimers( void )
{
	leg_damage = 0;
	is_undercover = 0;

	if ( tfstate & TFSTATE_AIMING )
	{
		tfstate &= ~TFSTATE_AIMING;
		TeamFortress_SetSpeed();
		heat = 0;
	}

	// Building in progress
	if ( is_building && building != NULL )
		UTIL_Remove( building );
	is_building = 0;
	building = NULL;

	tfstate &= ~TFSTATE_INFECTED;
	tfstate &= ~TFSTATE_HALLUCINATING;

	// All timers, except ones keeping gas grenades going
	CBaseEntity *pTimer;
	while ( ( pTimer = FindTimer( TF_TIMER_ANY ) ) != NULL )
	{
		if ( pTimer->no_active_gas_grens <= 0 )
			pTimer->SUB_Remove();
	}

	// Drop carried goal items
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->pev->owner == edict() )
		{
			if ( !( pEnt->goal_activation & TFGI_KEEP ) )
				tfgoalitem_RemoveFromPlayer( pEnt, this, GI_DROP_PLAYERDEATH );

			if ( CTF_Map == TRUE )
			{
				const char *pszTeam = team_no ? GetTeamName( team_no ) : "SPECTATOR";

				if ( pEnt->goal_no == CTF_FLAG1 )
				{
					UTIL_ClientPrintAll( HUD_PRINTCENTER, UTIL_VarArgs( "%s LOST the BLUE flag!\n", STRING( pev->netname ) ) );
					UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Dropped_Blue_Flag\"\n", STRING( pev->netname ), GETPLAYERUSERID( edict() ), GETPLAYERAUTHID( edict() ), pszTeam );
				}
				else if ( pEnt->goal_no == CTF_FLAG2 )
				{
					UTIL_ClientPrintAll( HUD_PRINTCENTER, UTIL_VarArgs( "%s LOST the RED flag!\n", STRING( pev->netname ) ) );
					UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Dropped_Red_Flag\"\n", STRING( pev->netname ), GETPLAYERUSERID( edict() ), GETPLAYERAUTHID( edict() ), pszTeam );
				}
			}
		}

		pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
	}

	// Stop disarming detpacks
	pEnt = UTIL_FindEntityByClassname( NULL, "detpack" );
	while ( pEnt )
	{
		if ( pEnt->weaponmode == 1 && pEnt->pev->enemy == edict() )
			pEnt->weaponmode = 0;

		pEnt = UTIL_FindEntityByClassname( pEnt, "detpack" );
	}

	ExplodeOldPipebomb( TRUE, TRUE );

	item_list = 0;
	ResetMenu();

	pev->renderfx = kRenderFxNone;
	pev->rendercolor = g_vecZero;
	pev->renderamt = 0;
	pev->rendermode = kRenderNormal;
	pev->framerate = 1;
}

// Work out when the player can respawn, and count down their lives
void CBasePlayer::TeamFortress_SetupRespawn( BOOL bSuicided )
{
	if ( respawn_time > gpGlobals->time )
		return;

	m_idrownrestored = 0;
	m_idrowndmg = 0;
	m_rgbTimeBasedDamage[itbd_DrownRecover] = 0;

	// already waiting to respawn
	if ( respawn_time > gpGlobals->time )
		return;

	float flDelay = tfc_respawndelay.value;

	if ( gpGlobals->time + 1 > cb_prematch_time )
	{
		// Suicides cost a life and wait for the suicide delay
		if ( bSuicided )
		{
			if ( lives > 0 )
				lives--;
			flDelay = m_fNextSuicideTime - gpGlobals->time;
		}

		if ( lives != -1 )
		{
			if ( lives > 0 )
				lives--;

			if ( lives == 0 )
			{
				ClientPrint( pev, HUD_PRINTCENTER, "#Game_nolives" );
				StartDeathCam();
				return;
			}

			if ( lives == 1 )
				ClientPrint( pev, HUD_PRINTCENTER, "#Game_lastlife" );
			else
				ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_Xlives", UTIL_dtos1( lives ) );
		}
	}

	respawn_time = gpGlobals->time + flDelay;

	if ( flDelay > 3 )
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_tillrespawn", UTIL_dtos1( flDelay ) );
}

// Keep armor, ammo, grenades and health inside the class limits
void CBasePlayer::TeamFortress_CheckClassStats( void )
{
	// Armor
	if ( pev->armortype > armor_allowed )
		pev->armortype = armor_allowed;
	if ( pev->armorvalue > maxarmor )
		pev->armorvalue = maxarmor;
	if ( pev->armortype < 0 )
		pev->armortype = 0;
	if ( pev->armorvalue < 0 )
		pev->armorvalue = 0;

	// Ammo
	if ( ammo_shells > maxammo_shells )
		ammo_shells = maxammo_shells;
	if ( ammo_shells < 0 )
		ammo_shells = 0;
	if ( ammo_nails > maxammo_nails )
		ammo_nails = maxammo_nails;
	if ( ammo_nails < 0 )
		ammo_nails = 0;
	if ( ammo_rockets > maxammo_rockets )
		ammo_rockets = maxammo_rockets;
	if ( ammo_rockets < 0 )
		ammo_rockets = 0;
	if ( ammo_cells > maxammo_cells )
		ammo_cells = maxammo_cells;
	if ( ammo_cells < 0 )
		ammo_cells = 0;
	if ( ammo_medikit > maxammo_medikit )
		ammo_medikit = maxammo_medikit;
	if ( ammo_medikit < 0 )
		ammo_medikit = 0;
	if ( ammo_detpack > maxammo_detpack )
		ammo_detpack = maxammo_detpack;
	if ( ammo_detpack < 0 )
		ammo_detpack = 0;

	// Grenades: 4 of most kinds, fewer of the strong ones
	if ( no_grenades_1 < 0 )
		no_grenades_1 = 0;
	if ( no_grenades_2 < 0 )
		no_grenades_2 = 0;
	if ( no_grenades_1 > 4 )
		no_grenades_1 = 4;
	if ( no_grenades_2 > 4 )
		no_grenades_2 = 4;

	if ( tp_grenades_1 == GR_TYPE_NAIL && no_grenades_1 > 2 )
		no_grenades_1 = 2;
	if ( tp_grenades_2 == GR_TYPE_NAIL && no_grenades_2 > 2 )
		no_grenades_2 = 2;
	if ( tp_grenades_1 == GR_TYPE_MIRV && no_grenades_1 > 2 )
		no_grenades_1 = 2;
	if ( tp_grenades_2 == GR_TYPE_MIRV && no_grenades_2 > 2 )
		no_grenades_2 = 2;
	if ( tp_grenades_1 == GR_TYPE_CONCUSSION && no_grenades_1 > 3 )
		no_grenades_1 = 3;
	if ( tp_grenades_2 == GR_TYPE_CONCUSSION && no_grenades_2 > 3 )
		no_grenades_2 = 3;
	if ( tp_grenades_1 == GR_TYPE_CALTROP && no_grenades_1 > 3 )
		no_grenades_1 = 3;
	if ( tp_grenades_2 == GR_TYPE_CALTROP && no_grenades_2 > 3 )
		no_grenades_2 = 3;

	// Health (megahealth can go over)
	if ( pev->health > pev->max_health && !( items & IT_SUPERHEALTH ) )
		pev->health = pev->max_health;
	if ( pev->health < 0 )
		pev->health = 0;

	// Armor type item
	items &= ~( IT_ARMOR1 | IT_ARMOR2 | IT_ARMOR3 );
	if ( pev->armortype >= 0.8 )
		items |= IT_ARMOR3;
	else if ( pev->armortype >= 0.6 )
		items |= IT_ARMOR2;
	else if ( pev->armortype >= 0.3 )
		items |= IT_ARMOR1;
}

// Move the player to a spawn point without killing them (goal result)
void CBasePlayer::ForceRespawn( void )
{
	forced_spawn = TRUE;

	MESSAGE_BEGIN( MSG_ALL, SVC_TEMPENTITY );
		WRITE_BYTE( TE_KILLPLAYERATTACHMENTS );
		WRITE_BYTE( (BYTE)ENTINDEX( edict() ) );
	MESSAGE_END();

	// Stop feigning
	if ( is_feigning )
	{
		is_feigning = FALSE;
		pev->velocity = g_vecZero;
		pev->view_ofs = VEC_VIEW;
		pev->movetype = MOVETYPE_WALK;
		pev->deadflag = DEAD_NO;
		pev->flags &= ~FL_ONGROUND;

		if ( m_pActiveItem )
			m_pActiveItem->Deploy();

		pev->framerate = -1;
		m_iRespawnFrames = 0;
		SetAnimation( PLAYER_FEIGN );
	}

	if ( m_pTank != NULL )
	{
		m_pTank->Use( this, this, USE_OFF, 0 );
		m_pTank = NULL;
	}

	m_flTimeStepSound = 0;
	m_iStepLeft = 0;
	m_flFallVelocity = 0;

	invincible_finished = 0;
	invisible_finished = 0;
	radsuit_finished = 0;
	super_damage_finished = 0;
	numflames = 0;
	m_flConcDuration = 0;
	m_flConcStartTime = 0;
	m_flNextSBarUpdateTime = gpGlobals->time + 1;

	if ( tfstate & TFSTATE_GRENPRIMED )
	{
		tfstate &= ~TFSTATE_GRENPRIMED;
		bRemoveGrenade = TRUE;
	}

	if ( tfstate & TFSTATE_RANDOMPC )
		tfstate = ( tfstate & TFSTATE_AIMING ) | TFSTATE_RANDOMPC;
	else
		tfstate &= TFSTATE_AIMING;

	TeamFortress_ExecClassScript();
	TeamFortress_SetSpeed();

	g_pGameRules->GetPlayerSpawnSpot( this );

	pev->sequence = LookupActivity( ACT_IDLE );

	if ( FBitSet( pev->flags, FL_DUCKING ) )
		UTIL_SetSize( pev, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX );
	else
		UTIL_SetSize( pev, VEC_HULL_MIN, VEC_HULL_MAX );
}

// Drop the goal items that can be dropped, if there's room in front
void CBasePlayer::DropGoalItems( void )
{
	TraceResult tr;

	UTIL_MakeVectors( pev->v_angle );
	Vector vecSrc = GetGunPosition();
	Vector vecEnd = vecSrc + gpGlobals->v_forward * 32;
	UTIL_TraceHull( vecSrc, vecEnd, dont_ignore_monsters, human_hull, edict(), &tr );

	if ( tr.flFraction != 1.0 )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Dropitems_noroom" );
		return;
	}

	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
	while ( pEnt )
	{
		if ( pEnt->pev->owner == edict() && ( pEnt->goal_activation & TFGI_CANBEDROPPED ) )
			tfgoalitem_RemoveFromPlayer( pEnt, this, GI_DROP_PLAYERDROP );

		pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
	}
}

// An engineer hit this player with a spanner: repair armor with cells
BOOL CBasePlayer::EngineerUse( CBasePlayer *pPlayer )
{
	if ( pev->armortype == 0 )
		pev->armortype = armor_allowed;

	// 5 armor per cell, at most 10 cells a hit
	int iCells = min( pPlayer->ammo_cells, 10 );
	int iArmor = iCells * 5;

	if ( maxarmor - pev->armorvalue < iArmor )
	{
		iArmor = maxarmor - pev->armorvalue;
		iCells = ceil( iArmor * 0.25 );
	}

	if ( iArmor > 0 )
	{
		pev->armorvalue += iArmor;
		if ( pev->armorvalue > maxarmor )
			pev->armorvalue = maxarmor;

		pPlayer->ammo_cells -= iCells;
		EMIT_SOUND( ENT( pPlayer->pev ), CHAN_WEAPON, "items/r_item2.wav", 1, ATTN_NORM );
	}

	return TRUE;
}

// The class special key
void CBasePlayer::UseSpecialSkill( void )
{
	if ( !IsAlive() )
		return;

	switch ( pev->playerclass )
	{
	case PC_SCOUT:
		TeamFortress_DisplayDetectionItems();
		break;

	case PC_SNIPER:
		// Zoom
		if ( m_pActiveItem && FClassnameIs( m_pActiveItem->pev, "tf_weapon_sniperrifle" ) &&
			 ( (CBasePlayerWeapon *)m_pActiveItem )->m_flNextSecondaryAttack <= 0 )
			( (CBasePlayerWeapon *)m_pActiveItem )->SecondaryAttack();
		break;

	case PC_SOLDIER:
		if ( m_pActiveItem )
			( (CBasePlayerWeapon *)m_pActiveItem )->Reload();
		break;

	case PC_DEMOMAN:
		// Detonate pipebombs
		if ( m_pActiveItem && ( (CBasePlayerWeapon *)m_pActiveItem )->m_flNextPrimaryAttack <= 0 )
			ExplodeOldPipebomb( TRUE, FALSE );
		break;

	case PC_MEDIC:
		SelectItem( "tf_weapon_medikit" );
		break;

	case PC_HVYWEAP:
		SelectItem( "tf_weapon_ac" );
		break;

	case PC_PYRO:
		SelectItem( "tf_weapon_flamethrower" );
		break;

	case PC_SPY:
		TeamFortress_SpyGoUndercover();
		break;

	case PC_ENGINEER:
		TeamFortress_EngineerBuild( 0 );
		break;
	}
}

// EMP damage from the ammo carried (engineers' metal doesn't explode)
void CBasePlayer::TeamFortress_CalcEMPDmgRad( float &damage, float &radius )
{
	radius = ammo_shells * 0.75 + ammo_rockets * 1.5;
	if ( pev->playerclass != PC_ENGINEER )
		radius += ammo_cells * 1.5;
	damage = radius;
}

// Hit by an EMP grenade: a quarter of the ammo explodes
void CBasePlayer::TeamFortress_TakeEMPBlast( entvars_t *pevGren )
{
	CBaseEntity *pOther = CBaseEntity::Instance( pevGren->owner );

	if ( !pev->playerclass )
		return;

	// No team damage
	if ( ( (int)gpGlobals->teamplay & TEAMPLAY_NOEXPLOSIVE ) && IsAlly( pOther ) && this != pOther )
		return;

	float flDamage, flRadius;
	TeamFortress_CalcEMPDmgRad( flDamage, flRadius );

	ammo_shells -= ceil( ammo_shells * 0.25 );
	ammo_rockets -= ceil( ammo_rockets * 0.25 );
	if ( pev->playerclass != PC_ENGINEER )
		ammo_cells -= ceil( ammo_cells * 0.25 );

	if ( flDamage > 0 )
		TeamFortress_EMPExplode( pevGren, flDamage, flRadius );
}

// Concussion grenade: knocked about and dizzy
void CBasePlayer::TeamFortress_TakeConcussionBlast( entvars_t *pevGren, float bouncemax )
{
	if ( !IsAlive() || !pev->playerclass )
		return;

	CBaseEntity *pOther = CBaseEntity::Instance( pevGren );

	Vector vecDir = pev->origin - pevGren->origin;
	float flDist = vecDir.Length();
	float flMult = ( bouncemax - flDist * 0.5 ) * 0.03;

	// Right on top of it: just slow down
	if ( flDist < 16 )
		vecDir = pev->velocity * 0.33;

	pev->velocity = vecDir;
	pev->velocity.x *= flMult;
	pev->velocity.y *= flMult;
	pev->velocity.z = flMult * pev->velocity.z * 1.5;

	// Teammates are thrown but not concussed
	if ( ( (int)gpGlobals->teamplay & TEAMPLAY_TEAMDAMAGE ) && team_no > 0 && IsAlly( pOther ) && pevGren->owner != edict() )
		return;

	MESSAGE_BEGIN( MSG_ONE, gmsgDamage, NULL, pev );
		WRITE_BYTE( 0 );
		WRITE_BYTE( 0 );
		WRITE_LONG( DMG_SONIC );
		WRITE_COORD( pevGren->origin.x );
		WRITE_COORD( pevGren->origin.y );
		WRITE_COORD( pevGren->origin.z );
	MESSAGE_END();

	TeamFortress_Concuss( pevGren );

	CBaseEntity *pThrower = CBaseEntity::Instance( pevGren->owner );
	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Concussion_Grenade\" against \"%s<%i><%s><%s>\"\n",
		STRING( pThrower->pev->netname ),
		GETPLAYERUSERID( pevGren->owner ),
		GETPLAYERAUTHID( pevGren->owner ),
		pThrower->team_no ? GetTeamName( pThrower->team_no ) : "SPECTATOR",
		STRING( pev->netname ),
		GETPLAYERUSERID( edict() ),
		GETPLAYERAUTHID( edict() ),
		team_no ? GetTeamName( team_no ) : "SPECTATOR" );
}

// Start the dizzy effect (medics recover twice as fast)
void CBasePlayer::TeamFortress_Concuss( entvars_t *pevGren )
{
	m_iConcussion = 100;
	m_iConcStartVal = 100;
	m_flConcDuration = 15;
	m_flConcStartTime = gpGlobals->time;

	if ( pev->playerclass == PC_MEDIC )
		m_flConcDuration = 7;
}

void CBasePlayer::TeamFortress_ThrowPrimedGrenade( void )
{
	if ( tfstate & TFSTATE_GRENPRIMED )
		tfstate |= TFSTATE_GRENTHROWING;
}

// Prime a grenade of the first or second type
void CBasePlayer::TeamFortress_PrimeGrenade( int iWhichType )
{
	if ( tfstate & ( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING ) )
		return;

	if ( !IsAlive() )
		return;

	int iType;
	int *piCount;
	if ( iWhichType == 1 )
	{
		iType = tp_grenades_1;
		piCount = &no_grenades_1;
	}
	else
	{
		iType = tp_grenades_2;
		piCount = &no_grenades_2;
	}

	if ( *piCount <= 0 )
		return;

	switch ( iType )
	{
	case GR_TYPE_NORMAL:		CTFNormalGrenade::Prime( this ); break;
	case GR_TYPE_CONCUSSION:	CTFConcussionGrenade::Prime( this ); break;
	case GR_TYPE_NAIL:			CTFNailGrenade::Prime( this ); break;
	case GR_TYPE_MIRV:			CTFMirvGrenade::Prime( this ); break;
	case GR_TYPE_NAPALM:		CTFNapalmGrenade::Prime( this ); break;
	case GR_TYPE_GAS:			CTFGasGrenade::Prime( this ); break;
	case GR_TYPE_EMP:			CTFEMPGrenade::Prime( this ); break;
	case GR_TYPE_CALTROP:		CTFCaltropGrenade::Prime( this ); break;
	default:
		return;
	}

	(*piCount)--;
	m_iPrimedGrenType = iWhichType;
	tfstate |= TFSTATE_GRENPRIMED;
	EMIT_SOUND( ENT( pev ), CHAN_WEAPON, "weapons/ax1.wav", 0.9, ATTN_NORM );
}

// Scouts and spies uncover enemy spies by touching them
void CBasePlayer::CheckUncoveringSpies( CBasePlayer *pPlayer )
{
	if ( pev->playerclass != PC_SCOUT && pev->playerclass != PC_SPY )
		return;

	if ( IsAlly( pPlayer ) )
		return;

	if ( !pPlayer->undercover_team && !pPlayer->undercover_skin )
		return;

	TF_AddFrags( 1 );
	pPlayer->Spy_RemoveDisguise();

	UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Spy_uncovered", STRING( pev->netname ) );
	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Discovered_Spy\" against \"%s<%i><%s><%s>\"\n",
		STRING( pev->netname ),
		GETPLAYERUSERID( edict() ),
		GETPLAYERAUTHID( edict() ),
		team_no ? GetTeamName( team_no ) : "SPECTATOR",
		STRING( pPlayer->pev->netname ),
		GETPLAYERUSERID( pPlayer->edict() ),
		GETPLAYERAUTHID( pPlayer->edict() ),
		pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR" );
}

// Play a sentence to this player only
void CBasePlayer::ClientHearVox( const char *pSentence )
{
	MESSAGE_BEGIN( MSG_ONE, SVC_STUFFTEXT, NULL, pev );
		if ( *pSentence == '#' )
			WRITE_STRING( UTIL_VarArgs( "spk %s\n", pSentence ) );
		else
			WRITE_STRING( UTIL_VarArgs( "spk \"%s\"\n", pSentence ) );
	MESSAGE_END();
}

void CBasePlayer::PlayerTouch( CBaseEntity *pOther )
{
	if ( pOther->Classify() != CLASS_PLAYER )
		return;

	CBasePlayer *pPlayer = (CBasePlayer *)pOther;

	if ( pev->playerclass == PC_SPY || pOther->pev->playerclass == PC_SPY )
	{
		CheckUncoveringSpies( pPlayer );
		pPlayer->CheckUncoveringSpies( this );
	}

	if ( !IsAlly( pOther ) )
		return;

	// Push slow teammates out of the way, especially when carrying the flag
	if ( pOther->pev->velocity.Length() >= 50 )
		return;

	if ( pev->velocity.Length() <= 55 && !( items & ( IT_KEY1 | IT_KEY2 ) ) )
		return;

	TraceResult tr;
	UTIL_MakeVectors( pev->v_angle );
	UTIL_TraceLine( pev->origin, pev->origin + gpGlobals->v_forward * 24, dont_ignore_monsters, edict(), &tr );

	if ( FNullEnt( tr.pHit ) )
		return;

	if ( CBaseEntity::Instance( tr.pHit ) != pOther )
		return;

	if ( items & ( IT_KEY1 | IT_KEY2 ) )
	{
		pOther->pev->velocity = pOther->pev->velocity + pev->velocity.Normalize() * 120;
	}
	else
	{
		// Flag carriers don't get pushed
		if ( pOther->items & ( IT_KEY1 | IT_KEY2 ) )
			return;

		pOther->pev->velocity = pOther->pev->velocity + pev->velocity.Normalize() * 30;
	}
}

const char *CBasePlayer::DB_GetPlayerClassName( void )
{
	return sClassNames[ pev->playerclass ];
}

// Damage balancing debug output
void PrototypeWriteDamage( void )
{
	FILE *fp = fopen( "prototype.txt", "a" );
	if ( !fp )
		return;

	fprintf( fp, "%6.2f : Damages %6.2f %6.2f %6.2f : Factors %6.2f %6.2f %6.2f %6.2f\n",
		gpGlobals->time, gfPrototypeTotalDamage, gfPrototypeExtraDamage, gfPrototypeLessDamage,
		teamadvantage[1], teamadvantage[2], teamadvantage[3], teamadvantage[4] );
	fclose( fp );
}
