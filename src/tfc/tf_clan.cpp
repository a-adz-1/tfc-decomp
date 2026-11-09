/***
*
*	Team Fortress Classic: clan battle support
*	(battle IDs and ghosts for reconnecting players, prematch countdown,
*	ceasefire, end of match results)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "tf_defs.h"

float g_fNextPrematchAlert;

// Holds a disconnected player's team, class and score during a clan battle
class CGhost : public CBaseEntity
{
};

LINK_ENTITY_TO_CLASS( ghost, CGhost );

void LogMatchResults( int *iNoPlayers, int *iUnaccountedFrags, BOOL bDraw );

void CBasePlayer::CreateGhost( void )
{
	CBaseEntity *pGhost = CBaseEntity::Create( "ghost", g_vecZero, g_vecZero, edict() );

	pGhost->tf_id = tf_id;
	pGhost->team_no = team_no;
	pGhost->pev->frags = pev->frags;
	pGhost->real_frags = real_frags;
	pGhost->pev->netname = pev->netname;
	pGhost->pev->playerclass = pev->playerclass;

	if ( tfstate & TFSTATE_RANDOMPC )
		pGhost->tfstate = TFSTATE_RANDOMPC;
}

CGhost *FindGhost( int iGhostID )
{
	CBaseEntity *pGhost = UTIL_FindEntityByClassname( NULL, "ghost" );
	while ( pGhost )
	{
		if ( pGhost->tf_id == iGhostID )
			break;
		pGhost = UTIL_FindEntityByClassname( pGhost, "ghost" );
	}
	return (CGhost *)pGhost;
}

// The battle ID is kept in the client's "tf_id" userinfo key
int GetBattleID( edict_t *pEntity )
{
	int iID = 0;

	char *pszID = g_engfuncs.pfnInfoKeyValue( g_engfuncs.pfnGetInfoKeyBuffer( pEntity ), "tf_id" );
	if ( pszID && *pszID )
		sscanf( pszID, "%d", &iID );

	return iID;
}

void CBasePlayer::ConnectDuringBattle( void )
{
	int iID = GetBattleID( edict() );

	if ( iID )
	{
		CGhost *pGhost = FindGhost( iID );
		if ( pGhost )
		{
			// Rejoining: restore the player from their ghost
			ClientPrint( pev, HUD_PRINTCENTER, "#Game_welcomeback" );
			tf_id = iID;
			TeamFortress_TeamSet( pGhost->team_no );
			pev->frags = pGhost->pev->frags;
			real_frags = pGhost->real_frags;
			pev->frags = real_frags;
			pev->playerclass = pGhost->pev->playerclass;
			tfstate = pGhost->tfstate;
			ResetMenu();
			UTIL_Remove( pGhost );
			return;
		}
	}

	CreateBattleID();
}

void CBasePlayer::CreateBattleID( void )
{
	if ( !tfc_clanbattle.value )
		return;

	last_id = last_id + RANDOM_FLOAT( 20, 40 );
	tf_id = last_id;

	g_engfuncs.pfnSetClientKeyValue( ENTINDEX( edict() ), g_engfuncs.pfnGetInfoKeyBuffer( edict() ), "tf_id", UTIL_VarArgs( "%d", tf_id ) );
	ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_battleid", UTIL_dtos1( tf_id ) );
}

// Called each frame during the prematch period
void Display_Prematch( void )
{
	if ( gpGlobals->time < g_fNextPrematchAlert )
		return;

	int iTime = (int)ceil( cb_prematch_time - gpGlobals->time );
	int iMins = iTime / 60;

	if ( iTime % 60 == 0 && iTime >= 120 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_minsleft", UTIL_dtos1( iMins ) );
		g_fNextPrematchAlert = gpGlobals->time + ( iTime - 60 );
		return;
	}

	if ( iTime == 60 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_oneminleft" );
		g_fNextPrematchAlert = gpGlobals->time + 30;
	}
	else if ( iTime == 30 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_thirtysecleft" );
		g_fNextPrematchAlert = gpGlobals->time + 20;
	}
	else if ( iTime >= 2 && iTime <= 10 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_secsleft", UTIL_dtos1( iTime ) );
		g_fNextPrematchAlert = gpGlobals->time + 1;
	}
	else if ( iTime == 1 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_onesec" );
		g_fNextPrematchAlert = gpGlobals->time + 1;
	}
	else if ( iTime <= 0 )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_matchbegin" );
		UTIL_LogPrintf( "World triggered \"Match_Begins_Now\"\n" );

		if ( tfc_clanbattle_locked.value )
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_matchlocked" );

		for ( int i = 1; i <= 4; i++ )
		{
			teamscores[i] = 0;
			teamfrags[i] = 0;
		}

		cb_prematch_time = 0;

		// Everyone respawns with a clean score
		for ( int i = 1; i <= gpGlobals->maxClients; i++ )
		{
			CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
			if ( !pPlayer )
				continue;

			if ( !pPlayer->tf_id )
				pPlayer->CreateBattleID();

			pPlayer->TeamFortress_RemoveTimers();
			pPlayer->TakeDamage( pPlayer->pev, pPlayer->pev, 10000, DMG_IGNOREARMOR | DMG_NEVERGIB );
			pPlayer->pev->frags = 0;
			pPlayer->real_frags = 0;
			pPlayer->m_iDeaths = 0;
		}

		// Remove all grenades
		CBaseEntity *pGrenade = UTIL_FindEntityByClassname( NULL, "grenade" );
		while ( pGrenade )
		{
			pGrenade->SetThink( &CBaseEntity::SUB_Remove );
			pGrenade->pev->nextthink = gpGlobals->time;
			pGrenade = UTIL_FindEntityByClassname( pGrenade, "grenade" );
		}
	}
}

// Called while a ceasefire is active
void Check_Ceasefire( void )
{
	if ( gpGlobals->time > cb_ceasefire_time && initial_cease_fire )
	{
		// The prematch ceasefire has run out
		if ( cease_fire )
		{
			initial_cease_fire = FALSE;
			cease_fire = FALSE;
		}
	}
	else if ( cease_fire )
	{
		last_cease_fire = cease_fire;
		return;
	}

	if ( !no_cease_fire_text )
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

	last_cease_fire = cease_fire;
}

void DumpClanScores( void )
{
	int iNoPlayers[5];
	int iUnaccountedFrags[5];

	BOOL bDraw = TeamFortress_SortTeams();

	for ( int i = 0; i <= 4; i++ )
	{
		iNoPlayers[i] = TeamFortress_TeamGetNoPlayers( i );
		iUnaccountedFrags[i] = 0;
	}

	// Team frags not explained by the players still in the game
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( pPlayer )
			iUnaccountedFrags[ pPlayer->team_no ] += pPlayer->real_frags;
	}

	for ( int i = 0; i <= 4; i++ )
		iUnaccountedFrags[i] = teamfrags[i] - iUnaccountedFrags[i];

	UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_results" );
	LogMatchResults( iNoPlayers, iUnaccountedFrags, bDraw );

	if ( !bDraw )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_winner", GetTeamName( g_iOrderedTeams[1] ), GetTeamName( g_iOrderedTeams[2] ) );

		if ( number_of_teams > 3 )
		{
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_losers4", GetTeamName( g_iOrderedTeams[3] ) );
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_losers3", GetTeamName( g_iOrderedTeams[4] ) );
		}
		else if ( number_of_teams > 2 )
		{
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_losers3", GetTeamName( g_iOrderedTeams[3] ) );
		}
	}
	else
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_draw" );
	}

	for ( int i = 1; i <= number_of_teams; i++ )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_team", UTIL_dtos1( i ), UTIL_dtos2( TeamFortress_TeamGetNoPlayers( i ) ) );
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Match_teamdump", UTIL_dtos1( teamfrags[i] ), UTIL_dtos2( iUnaccountedFrags[i] ), UTIL_dtos3( teamscores[i] ) );
	}
}

void LogMatchResults( int *iNoPlayers, int *iUnaccountedFrags, BOOL bDraw )
{
	char szLine[ 500 ];
	char szAllies[ 128 ];
	char szAlly[ 32 ];

	for ( int tno = 1; tno <= number_of_teams; tno++ )
	{
		szAllies[0] = 0;

		sprintf( szLine, "Team \"%s\" scored \"%s\" with \"%s\" %s (kills \"%s\") (kills_unaccounted \"%s\")",
			GetTeamName( tno ),
			UTIL_dtos1( teamscores[tno] ),
			UTIL_dtos2( TeamFortress_TeamGetNoPlayers( tno ) ),
			TeamFortress_TeamGetNoPlayers( tno ) == 1 ? "player" : "players",
			UTIL_dtos3( teamfrags[tno] ),
			UTIL_dtos4( iUnaccountedFrags[tno] ) );

		if ( number_of_teams > 1 )
		{
			BOOL bAllies = FALSE;

			// Note: the original stops before the last team (i < number_of_teams)
			for ( int i = 1; i < number_of_teams; i++ )
			{
				if ( teamallies[tno] & ( 1 << ( i - 1 ) ) )
				{
					sprintf( szAlly, "<%s>", GetTeamName( i ) );
					strcat( szAllies, szAlly );
					bAllies = TRUE;
				}
			}

			if ( bAllies )
			{
				strcat( szLine, " (allies \"" );
				strcat( szLine, szAllies );
				strcat( szLine, "\")" );
			}
		}

		strcat( szLine, "\n" );
		UTIL_LogPrintf( szLine );
	}
}
