/***
*
*	Team Fortress Classic: in-game admin (tfc_adminpwd) and team-kill autokick
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "tf_defs.h"

void KickPlayer( CBaseEntity *pTarget );
void BanPlayer( CBaseEntity *pTarget );

// Player typed "admin <password>"
void CBasePlayer::AdminAccess( char *pPassword )
{
	if ( !pPassword || !*pPassword )
		return;

	if ( !tfc_adminpwd.string || !*tfc_adminpwd.string )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_nopassword" );
		return;
	}

	if ( !strcmp( tfc_adminpwd.string, pPassword ) )
	{
		is_admin = TRUE;
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_access" );
		return;
	}

	ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_badpassword" );
}

void CBasePlayer::Admin_CountPlayers( void )
{
	ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_noplayers", UTIL_dtos1( TeamFortress_GetNoPlayers() ) );

	for ( int i = 1; i <= 4; i++ )
	{
		if ( number_of_teams > i - 1 )
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_noteamplayers", UTIL_dtos1( i ), UTIL_dtos2( TeamFortress_TeamGetNoPlayers( i ) ) );
	}
}

void CBasePlayer::Admin_ListIPs( void )
{
	if ( TeamFortress_GetNoPlayers() < 2 )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_gameempty" );
		return;
	}

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( pPlayer )
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_listip", STRING( pPlayer->pev->netname ), STRING( pPlayer->ip ) );
	}

	ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_endlist" );
}

// Step admin_use to the next player that can be kicked/banned
void CBasePlayer::Admin_CycleDeal( void )
{
	if ( TeamFortress_GetNoPlayers() < 2 )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_gameempty" );
		admin_use = NULL;
		admin_mode = 0;
		return;
	}

	int i = 0;
	if ( admin_use )
		i = ENTINDEX( admin_use->edict() ) + 1;

	for ( ; i <= gpGlobals->maxClients; i++ )
	{
		admin_use = UTIL_PlayerByIndex( i );
		if ( admin_use && (CBaseEntity *)admin_use != this )
		{
			admin_mode = 1;
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_kickban", STRING( admin_use->pev->netname ), STRING( admin_use->ip ) );
			return;
		}
	}

	admin_mode = 0;
	ClientPrint( pev, HUD_PRINTNOTIFY, "#Admin_endlist" );
}

void CBasePlayer::Admin_DoKick( void )
{
	if ( !admin_use )
		return;

	UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Admin_kick", STRING( admin_use->pev->netname ), STRING( pev->netname ) );

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Admin_Kick\" against \"%s<%i><%s><%s>\"\n",
		STRING( pev->netname ),
		GETPLAYERUSERID( edict() ),
		GETPLAYERAUTHID( edict() ),
		team_no ? GetTeamName( team_no ) : "SPECTATOR",
		STRING( admin_use->pev->netname ),
		GETPLAYERUSERID( admin_use->edict() ),
		GETPLAYERAUTHID( admin_use->edict() ),
		admin_use->team_no ? GetTeamName( admin_use->team_no ) : "SPECTATOR" );

	KickPlayer( admin_use );

	admin_mode = 0;
	admin_use = NULL;
}

void CBasePlayer::Admin_DoBan( void )
{
	if ( !admin_use )
		return;

	UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Admin_ban", STRING( admin_use->pev->netname ), STRING( pev->netname ) );

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Admin_Ban\" against \"%s<%i><%s><%s>\"\n",
		STRING( pev->netname ),
		GETPLAYERUSERID( edict() ),
		GETPLAYERAUTHID( edict() ),
		team_no ? GetTeamName( team_no ) : "SPECTATOR",
		STRING( admin_use->pev->netname ),
		GETPLAYERUSERID( admin_use->edict() ),
		GETPLAYERAUTHID( admin_use->edict() ),
		admin_use->team_no ? GetTeamName( admin_use->team_no ) : "SPECTATOR" );

	BanPlayer( admin_use );

	admin_mode = 0;
	admin_use = NULL;
}

// Toggle a ceasefire: everyone frozen and unable to fire
void Admin_CeaseFire( void )
{
	if ( !cease_fire )
	{
		cease_fire = TRUE;
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Admin_ceasefire" );

		for ( int i = 1; i <= gpGlobals->maxClients; i++ )
		{
			CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
			if ( pPlayer )
			{
				pPlayer->pev->iuser4 = TRUE;
				pPlayer->tfstate |= TFSTATE_CANT_MOVE;
				pPlayer->immune_to_check = gpGlobals->time + 10;
				pPlayer->TeamFortress_SetSpeed();
			}
		}
	}
	else
	{
		cease_fire = FALSE;
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_resumefire" );
		UTIL_LogPrintf( "World triggered \"Resume_Fire\"\n" );

		for ( int i = 1; i <= gpGlobals->maxClients; i++ )
		{
			CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
			if ( pPlayer )
			{
				pPlayer->pev->iuser4 = FALSE;
				pPlayer->tfstate &= ~TFSTATE_CANT_MOVE;
				pPlayer->immune_to_check = gpGlobals->time + 10;
				pPlayer->TeamFortress_SetSpeed();
			}
		}
	}
}

// Called after a teamkill: ban on reaching tfc_autokick_kills
void CBasePlayer::CheckAutoKick( void )
{
	if ( teamkills >= autokick_kills && autokick_kills != 0 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#AKick_kicked", STRING( pev->netname ) );

		UTIL_LogPrintf( "\"<-1><><>\" triggered \"Auto_Kick_For_TK\" against \"%s<%i><%s><%s>\"\n",
			STRING( pev->netname ),
			GETPLAYERUSERID( edict() ),
			GETPLAYERAUTHID( edict() ),
			team_no ? GetTeamName( team_no ) : "SPECTATOR" );

		BanPlayer( this );
		return;
	}

	if ( autokick_kills == 0 )
		return;

	// One more teamkill and you're out
	if ( teamkills == autokick_kills - 1 )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#AKick_warn" );
		ClientPrint( pev, HUD_PRINTNOTIFY, "#AKick_warn" );
	}

	// Already have a timer running to forgive the teamkills?
	CBaseEntity *pTimer = UTIL_FindEntityByClassname( NULL, "ak_timer" );
	while ( pTimer )
	{
		if ( pTimer->pev->owner == edict() )
			return;
		pTimer = UTIL_FindEntityByClassname( pTimer, "ak_timer" );
	}

	pTimer = CreateTimer( TF_TIMER_ANY );
	pTimer->pev->classname = MAKE_STRING( "ak_timer" );
	pTimer->SetThink( &CBaseEntity::Timer_AutokickThink );
	pTimer->pev->nextthink = gpGlobals->time + tfc_autokick_time.value;
}

void KickPlayer( CBaseEntity *pTarget )
{
	int iUserID = GETPLAYERUSERID( pTarget->edict() );
	if ( iUserID != -1 )
		SERVER_COMMAND( UTIL_VarArgs( "kick # %d\n", iUserID ) );
}

// 30 minute ban by authid and ip, then kick
void BanPlayer( CBaseEntity *pTarget )
{
	SERVER_COMMAND( UTIL_VarArgs( "banid 30 %s kick\n", GETPLAYERAUTHID( pTarget->edict() ) ) );
	SERVER_COMMAND( UTIL_VarArgs( "addip 30 %s\n", STRING( pTarget->ip ) ) );
	KickPlayer( pTarget );
}

void CBasePlayer::Admin_Changelevel( void )
{
	char command[ 256 ];

	if ( CMD_ARGC() != 2 )
		return;

	sprintf( command, "changelevel %s\n", CMD_ARGV( 1 ) );
	SERVER_COMMAND( command );
}
