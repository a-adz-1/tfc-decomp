/***
*
*	Team Fortress Classic game rules.
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"
#include "gamerules.h"
#include "teamplay_gamerules.h"
#include "items.h"
#include "tf_defs.h"
#include "tf_gamerules.h"

extern int g_fGameOver;

// Voice: teammates and allied teams can hear each other
class TFGameMgrHelper : public IVoiceGameMgrHelper
{
public:
	virtual bool CanPlayerHearPlayer( CBasePlayer *pPlayer1, CBasePlayer *pPlayer2 )
	{
		if ( pPlayer1->team_no == pPlayer2->team_no )
			return true;

		return ( teamallies[ pPlayer1->team_no ] & ( 1 << ( pPlayer2->team_no - 1 ) ) ) != 0;
	}
};

static TFGameMgrHelper g_GameMgrHelper;

CTeamFortress::CTeamFortress()
{
	m_VoiceGameMgr.Init( &g_GameMgrHelper, gpGlobals->maxClients );
}

void CTeamFortress::Think( void )
{
	m_VoiceGameMgr.Update( gpGlobals->frametime );
	CHalfLifeMultiplay::Think();
}

BOOL CTeamFortress::IsTeamplay( void )
{
	return gpGlobals->teamplay > 0;
}

void CTeamFortress::PlayerSpawn( CBasePlayer *pPlayer )
{
	pPlayer->pev->weapons |= ( 1 << WEAPON_SUIT );
}

extern int gmsgTeamInfo;

#define SVC_STUFFTEXT	9	// engine message: run text in the client console

BOOL CTeamFortress::ClientConnected( edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[ 128 ] )
{
	m_VoiceGameMgr.ClientConnected( pEntity );

	// Server settings are read when the first client connects
	if ( !g_bFirstClient )
	{
		g_bFirstClient = TRUE;
		ParseTFServerSettings();
	}

	// New player starts with no team
	MESSAGE_BEGIN( MSG_ALL, gmsgTeamInfo );
		WRITE_BYTE( ENTINDEX( pEntity ) );
		WRITE_STRING( "" );
	MESSAGE_END();

	MESSAGE_BEGIN( MSG_ONE, SVC_STUFFTEXT, NULL, pEntity );
		WRITE_STRING( UTIL_VarArgs( "cl_forwardspeed %d\ncl_backspeed %d\ncl_sidespeed %d\n", 400, 400, 400 ) );
	MESSAGE_END();

	return CHalfLifeMultiplay::ClientConnected( pEntity, pszName, pszAddress, szRejectReason );
}

BOOL CTeamFortress::ClientCommand( CBasePlayer *pPlayer, const char *pcmd )
{
	if ( m_VoiceGameMgr.ClientCommand( pPlayer, pcmd ) )
		return TRUE;

	return CHalfLifeTeamplay::ClientCommand( pPlayer, pcmd );
}

extern int gmsgViewMode;

void CTeamFortress::InitHUD( CBasePlayer *pl )
{
	CHalfLifeTeamplay::InitHUD( pl );

	UTIL_LogPrintf( "\"%s<%i><%s><>\" entered the game\n",
		STRING( pl->pev->netname ), GETPLAYERUSERID( pl->edict() ), GETPLAYERAUTHID( pl->edict() ) );
	UTIL_LogPrintf( "\"%s<%i><%s><>\" joined team \"SPECTATOR\"\n",
		STRING( pl->pev->netname ), GETPLAYERUSERID( pl->edict() ), GETPLAYERAUTHID( pl->edict() ) );

	// Send everyone's team scores
	for ( int i = 1; i <= number_of_teams; i++ )
		TeamFortress_TeamIncreaseScore( i, 0 );

	pl->TeamFortress_ExecMapScript();
	pl->m_bDisplayedMOTD = FALSE;

	if ( CVAR_GET_FLOAT( "sv_cheats" ) == 0 )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgViewMode, NULL, pl->edict() );
		MESSAGE_END();
	}
}

// "1" or "on" in a userinfo key turns the option on
static BOOL IsOn( const char *pszValue )
{
	return !strcmp( pszValue, "1" ) || !strcmp( pszValue, "on" );
}

void CTeamFortress::ClientUserInfoChanged( CBasePlayer *pPlayer, char *infobuffer )
{
	pPlayer->TeamFortress_SetSkin();

	// exec_class: run <class>.cfg on class change
	pPlayer->exec_scripts = FALSE;
	char *pszValue = g_engfuncs.pfnInfoKeyValue( infobuffer, "ec" );
	if ( ( pszValue && *pszValue ) ||
		( ( pszValue = g_engfuncs.pfnInfoKeyValue( infobuffer, "exec_class" ) ) && *pszValue ) )
	{
		if ( IsOn( pszValue ) )
			pPlayer->exec_scripts = TRUE;
	}

	// exec_map: run <map>.cfg on map change.
	// Note: the original never assigns the "exec_map" lookup (only "em" works).
	pPlayer->exec_map_scripts = FALSE;
	pszValue = g_engfuncs.pfnInfoKeyValue( infobuffer, "em" );
	if ( ( pszValue && *pszValue ) ||
		( g_engfuncs.pfnInfoKeyValue( infobuffer, "exec_map" ) && *pszValue ) )
	{
		if ( IsOn( pszValue ) )
			pPlayer->exec_map_scripts = TRUE;
	}

	pPlayer->display_class_briefing = FALSE;

	// take_sshot: screenshot at the end of the map
	pPlayer->take_screenshots = FALSE;
	pszValue = g_engfuncs.pfnInfoKeyValue( infobuffer, "take_sshot" );
	if ( ( pszValue && *pszValue ) ||
		( ( pszValue = g_engfuncs.pfnInfoKeyValue( infobuffer, "ts" ) ) && *pszValue ) )
	{
		if ( IsOn( pszValue ) )
			pPlayer->take_screenshots = TRUE;
	}

	// cl_lb: local blood
	pPlayer->local_blood = TRUE;
	pszValue = g_engfuncs.pfnInfoKeyValue( infobuffer, "cl_lb" );
	if ( pszValue && *pszValue )
		pPlayer->local_blood = atoi( pszValue ) != 0;
}

int CTeamFortress::DeadPlayerWeapons( CBasePlayer *pPlayer )
{
	return GR_PLR_DROP_GUN_NO;
}

int CTeamFortress::DeadPlayerAmmo( CBasePlayer *pPlayer )
{
	return GR_PLR_DROP_AMMO_ALL;
}

float CTeamFortress::FlItemRespawnTime( CItem *pItem )
{
	return gpGlobals->time + pItem->m_flRespawnTime;
}

BOOL CTeamFortress::CanHaveItem( CBasePlayer *pPlayer, CItem *pItem )
{
	if ( pPlayer->is_feigning || ( pPlayer->tfstate & ( TFSTATE_CANT_MOVE | TFSTATE_AIMING ) ) )
		return FALSE;

	if ( gpGlobals->time < cb_prematch_time )
		return FALSE;

	return ActivationSucceeded( pItem, pPlayer, NULL ) != 0;
}

char *CTeamFortress::GetTeamID( CBaseEntity *pEntity )
{
	return GetTeamName( pEntity->team_no );
}

#define MAX_INTERMISSION_TIME	120

extern cvar_t mp_chattime;

void CTeamFortress::GoToIntermission( void )
{
	if ( g_fGameOver )
		return;

	MESSAGE_BEGIN( MSG_ALL, SVC_INTERMISSION );
	MESSAGE_END();

	DumpClanScores();
	clan_scores_dumped = 1;

	int time = (int)CVAR_GET_FLOAT( "mp_chattime" );
	if ( time < 1 )
		CVAR_SET_STRING( "mp_chattime", "1" );
	else if ( time > MAX_INTERMISSION_TIME )
		CVAR_SET_STRING( "mp_chattime", UTIL_dtos1( MAX_INTERMISSION_TIME ) );

	m_flIntermissionEndTime = gpGlobals->time + ( (int)mp_chattime.value );
	m_iEndIntermissionButtonHit = FALSE;
	g_fGameOver = TRUE;
	m_flIntermissionStartTime = gpGlobals->time;
}
