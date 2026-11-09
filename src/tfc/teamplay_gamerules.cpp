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
//
// teamplay_gamerules.cpp
//
#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"player.h"
#include	"weapons.h"
#include	"gamerules.h"
#include	"teamplay_gamerules.h"
#include	"game.h"
#include	"tf_defs.h"

extern int gmsgDeathMsg;	// client dll messages
extern int gmsgGameMode;
extern int gmsgTeamInfo;

// TFC: teams come from the map (tfort.cpp); this class only handles
// team-friendly damage, scoring and death messages

CHalfLifeTeamplay :: CHalfLifeTeamplay()
{
	m_DisableDeathMessages = FALSE;
	m_DisableDeathPenalty = FALSE;
}

void CHalfLifeTeamplay :: PlayerSpawn( CBasePlayer *pPlayer )
{
	if ( g_pGameRules->IsTeamplay() )
	{
		pPlayer->pev->weapons |= ( 1 << WEAPON_SUIT );
		return;
	}

	CHalfLifeMultiplay::PlayerSpawn( pPlayer );
}

BOOL CHalfLifeTeamplay :: ClientCommand( CBasePlayer *pPlayer, const char *pcmd )
{
	g_pGameRules->IsTeamplay();
	return CHalfLifeMultiplay::ClientCommand( pPlayer, pcmd );
}

void CHalfLifeTeamplay :: UpdateGameMode( CBasePlayer *pPlayer )
{
	if ( g_pGameRules->IsTeamplay() )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgGameMode, NULL, pPlayer->edict() );
			WRITE_BYTE( 1 );  // game mode teamplay
		MESSAGE_END();
		return;
	}

	CHalfLifeMultiplay::UpdateGameMode( pPlayer );
}

void CHalfLifeTeamplay::InitHUD( CBasePlayer *pPlayer )
{
	if ( !g_pGameRules->IsTeamplay() )
	{
		CHalfLifeMultiplay::InitHUD( pPlayer );
		return;
	}

	CHalfLifeMultiplay::InitHUD( pPlayer );

	// Send everyone's team to the new client
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *plr = CBaseEntity::Instance( INDEXENT( i ) );
		if ( plr )
		{
			MESSAGE_BEGIN( MSG_ONE, gmsgTeamInfo, NULL, pPlayer->edict() );
				WRITE_BYTE( ENTINDEX( plr->edict() ) );
				WRITE_STRING( g_pGameRules->GetTeamID( plr ) );
			MESSAGE_END();
		}
	}
}

void CHalfLifeTeamplay::ClientUserInfoChanged( CBasePlayer *pPlayer, char *infobuffer )
{
}

//=========================================================
// Deathnotice. 
//=========================================================
void CHalfLifeTeamplay::DeathNotice( CBasePlayer *pVictim, entvars_t *pKiller, entvars_t *pevInflictor )
{
	if ( !g_pGameRules->IsTeamplay() )
	{
		CHalfLifeMultiplay::DeathNotice( pVictim, pKiller, pevInflictor );
		return;
	}

	if ( m_DisableDeathMessages )
		return;

	if ( pVictim && pKiller && pKiller->flags & FL_CLIENT )
	{
		CBasePlayer *pk = (CBasePlayer *)CBaseEntity::Instance( pKiller );

		if ( pk )
		{
			if ( ( pk != pVictim ) && ( PlayerRelationship( pVictim, pk ) == GR_TEAMMATE ) )
			{
				MESSAGE_BEGIN( MSG_ALL, gmsgDeathMsg );
					WRITE_BYTE( ENTINDEX( ENT( pKiller ) ) );		// the killer
					WRITE_BYTE( ENTINDEX( pVictim->edict() ) );	// the victim
					WRITE_STRING( "teammate" );		// flag this as a teammate kill
				MESSAGE_END();

				char szWeapon[42];
				GetWeapon( pevInflictor, pKiller, szWeapon );

				CBaseEntity *pKillerEnt = CBaseEntity::Instance( pKiller );
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
					STRING( pKiller->netname ),
					GETPLAYERUSERID( ENT( pKiller ) ),
					GETPLAYERAUTHID( ENT( pKiller ) ),
					pKillerEnt->team_no ? GetTeamName( pKillerEnt->team_no ) : "SPECTATOR",
					STRING( pVictim->pev->netname ),
					GETPLAYERUSERID( pVictim->edict() ),
					GETPLAYERAUTHID( pVictim->edict() ),
					pVictim->team_no ? GetTeamName( pVictim->team_no ) : "SPECTATOR",
					szWeapon );

				// Killing a disguised spy isn't a teamkill
				if ( !pVictim->undercover_team )
				{
					pk->teamkills++;
					pk->CheckAutoKick();
				}
				return;
			}
		}
	}

	CHalfLifeMultiplay::DeathNotice( pVictim, pKiller, pevInflictor );
}

//=========================================================
//=========================================================
void CHalfLifeTeamplay :: PlayerKilled( CBasePlayer *pVictim, entvars_t *pKiller, entvars_t *pInflictor )
{
	if ( g_pGameRules->IsTeamplay() && m_DisableDeathPenalty )
		return;

	CHalfLifeMultiplay::PlayerKilled( pVictim, pKiller, pInflictor );
}

//=========================================================
// IsTeamplay
//=========================================================
BOOL CHalfLifeTeamplay::IsTeamplay( void )
{
	return TRUE;
}

BOOL CHalfLifeTeamplay::FPlayerCanTakeDamage( CBasePlayer *pPlayer, CBaseEntity *pAttacker )
{
	if ( g_pGameRules->IsTeamplay() && pAttacker && PlayerRelationship( pPlayer, pAttacker ) == GR_TEAMMATE )
	{
		// my teammate hit me.
		if ( ( CVAR_GET_FLOAT( "mp_friendlyfire" ) == 0 ) && ( pAttacker != pPlayer ) )
		{
			// friendly fire is off, and this hit came from someone other than myself,  then don't get hurt
			return FALSE;
		}
	}

	return CHalfLifeMultiplay::FPlayerCanTakeDamage( pPlayer, pAttacker );
}

//=========================================================
//=========================================================
int CHalfLifeTeamplay::PlayerRelationship( CBasePlayer *pPlayer, CBaseEntity *pTarget )
{
	if ( !g_pGameRules->IsTeamplay() )
		return CHalfLifeMultiplay::PlayerRelationship( pPlayer, pTarget );

	// half life multiplay has a simple concept of Player Relationships.
	// you are either on another player's team, or you are not.
	if ( !pPlayer || !pTarget || !( pTarget->pev->flags & FL_CLIENT ) )
		return GR_NOTTEAMMATE;

	if ( ( *GetTeamID( pPlayer ) != '\0' ) && ( *GetTeamID( pTarget ) != '\0' ) && !stricmp( GetTeamID( pPlayer ), GetTeamID( pTarget ) ) )
	{
		return GR_TEAMMATE;
	}

	// TFC: allied teams count as teammates
	return pPlayer->IsAlly( pTarget ) ? GR_TEAMMATE : GR_NOTTEAMMATE;
}

//=========================================================
//=========================================================
BOOL CHalfLifeTeamplay::ShouldAutoAim( CBasePlayer *pPlayer, edict_t *target )
{
	if ( !g_pGameRules->IsTeamplay() )
		return TRUE;

	// always autoaim, unless target is a teammate
	CBaseEntity *pTgt = CBaseEntity::Instance( target );
	if ( pTgt && pTgt->IsPlayer() )
	{
		if ( PlayerRelationship( pPlayer, pTgt ) == GR_TEAMMATE )
			return FALSE; // don't autoaim at teammates
	}

	return TRUE;
}

//=========================================================
//=========================================================
int CHalfLifeTeamplay::IPointsForKill( CBasePlayer *pAttacker, CBasePlayer *pKilled )
{
	if ( !g_pGameRules->IsTeamplay() )
		return CHalfLifeMultiplay::IPointsForKill( pAttacker, pKilled );

	if ( !pKilled )
		return 0;

	if ( !pAttacker )
		return 1;

	if ( pAttacker != pKilled && PlayerRelationship( pAttacker, pKilled ) == GR_TEAMMATE )
		return -1;

	return 1;
}

//=========================================================
//=========================================================
char *CHalfLifeTeamplay::GetTeamID( CBaseEntity *pEntity )
{
	g_pGameRules->IsTeamplay();
	return "";
}
