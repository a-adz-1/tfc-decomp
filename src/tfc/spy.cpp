/***
*
*	Team Fortress Classic: Spy (feign death and disguise)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"
#include "tf_defs.h"

// Can't disguise or feign while glowing (e.g. from powerups)
#define SPY_GLOW_EFFECTS	( EF_BRIGHTFIELD | EF_DIMLIGHT )

// Not if a live player (other than us) or a building is too close
BOOL CBasePlayer::CanFeign( void )
{
	CBaseEntity *pEnt = NULL;
	while ( ( pEnt = UTIL_FindEntityInSphere( pEnt, pev->origin, 64 ) ) != NULL )
	{
		if ( ( pEnt->pev->flags & FL_CLIENT ) && pEnt->IsAlive() && pEnt != this )
			return FALSE;
		if ( pEnt->Classify() == CLASS_MACHINE )
			return FALSE;
	}
	return TRUE;
}

void CBasePlayer::TeamFortress_SpyFeignDeath( BOOL bSilent )
{
	if ( m_flNextAttack > 0 )
		return;

	m_flNextAttack = 0.5;

	if ( !is_feigning )
	{
		if ( is_unableto_spy_or_teleport == TRUE )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Feign_unable" );
			return;
		}

		if ( !( pev->flags & FL_ONGROUND ) && !pev->waterlevel )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Feign_air" );
			return;
		}

		if ( !CanFeign() )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Feign_onspy" );
			return;
		}

		// Crouched: need room to drop to the full "dead" height
		if ( pev->flags & FL_DUCKING )
		{
			Vector vecOrigin = pev->origin;
			if ( pev->flags & FL_ONGROUND )
				vecOrigin = vecOrigin + Vector( 0, 0, 18 );

			TraceResult tr;
			UTIL_TraceHull( vecOrigin, vecOrigin, dont_ignore_monsters, human_hull, edict(), &tr );
			if ( tr.fStartSolid )
			{
				ClientPrint( pev, HUD_PRINTCENTER, "#Feign_noroom" );
				return;
			}

			if ( pev->flags & FL_ONGROUND )
				pev->origin = pev->origin + Vector( 0, 0, 18 );
		}

		m_iRespawnFrames = 0;
		SetAnimation( PLAYER_FEIGN );

		tfstate |= TFSTATE_CANT_MOVE;
		immune_to_check = gpGlobals->time + 5;
		TeamFortress_SetSpeed();

		pev->deadflag = DEAD_FEIGNING;
		is_feigning = TRUE;
		invisible_finished = 0;
		TeamFortress_SetSkin();

		if ( m_pActiveItem )
		{
			m_pActiveItem->Holster( 0 );
			pev->viewmodel = 0;
			pev->weaponmodel = 0;
		}

		UTIL_SetSize( pev, Vector( -16, -16, -36 ), Vector( 16, 16, -32 ) );
		pev->view_ofs = Vector( 0, 0, 4 );
		pev->movetype = MOVETYPE_TOSS;
		pev->flags &= ~FL_ONGROUND;

		if ( pev->velocity.z < 10 )
			pev->velocity.z += RANDOM_FLOAT( 0, 300 );

		if ( !bSilent )
			DeathSound();

		pev->angles.x = 0;
		pev->angles.z = 0;

		// Drop carried goal items as if dead
		for ( CBaseEntity *pItem = UTIL_FindEntityByClassname( NULL, "item_tfgoal" ); pItem; pItem = UTIL_FindEntityByClassname( pItem, "item_tfgoal" ) )
		{
			if ( pItem->pev->owner != edict() )
				continue;

			if ( !( pItem->goal_activation & TFGI_KEEP ) || has_disconnected == TRUE )
				tfgoalitem_RemoveFromPlayer( pItem, this, 0 );

			if ( CTF_Map == TRUE )
			{
				if ( pItem->goal_no == 1 )
				{
					UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s LOST the BLUE flag!\n", STRING( pev->netname ) ) );
					UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Dropped_Blue_Flag\"\n",
						STRING( pev->netname ), GETPLAYERUSERID( edict() ), GETPLAYERAUTHID( edict() ),
						team_no ? GetTeamName( team_no ) : "SPECTATOR" );
				}
				else if ( pItem->goal_no == 2 )
				{
					UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s LOST the RED flag!\n", STRING( pev->netname ) ) );
					UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Dropped_Red_Flag\"\n",
						STRING( pev->netname ), GETPLAYERUSERID( edict() ), GETPLAYERAUTHID( edict() ),
						team_no ? GetTeamName( team_no ) : "SPECTATOR" );
				}
			}
		}

		pev->iuser3 = TRUE;
	}
	else
	{
		// Get up
		if ( !CanFeign() )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Feign_unabletogetup" );
			return;
		}

		is_feigning = FALSE;
		pev->velocity = g_vecZero;

		if ( !( pev->flags & FL_DUCKING ) )
			UTIL_SetSize( pev, Vector( -16, -16, -36 ), Vector( 16, 16, 36 ) );
		else
			UTIL_SetSize( pev, Vector( -16, -16, -18 ), Vector( 16, 16, 18 ) );

		pev->view_ofs = Vector( 0, 0, 28 );
		pev->movetype = MOVETYPE_WALK;
		pev->deadflag = DEAD_NO;
		pev->flags &= ~FL_ONGROUND;

		tfstate &= ~TFSTATE_CANT_MOVE;
		TeamFortress_SetSpeed();

		if ( m_pActiveItem )
			m_pActiveItem->Deploy();

		pev->framerate = -1;	// play the feign animation backwards to stand up
		m_iRespawnFrames = 0;
		SetAnimation( PLAYER_FEIGN );

		pev->iuser3 = FALSE;
	}
}

void CBasePlayer::Spy_RemoveDisguise( void )
{
	if ( pev->playerclass != PC_SPY )
		return;

	if ( undercover_team || undercover_skin )
		ClientPrint( pev, HUD_PRINTCENTER, "#Disguise_Lost" );

	undercover_team = 0;
	undercover_skin = 0;
	is_undercover = FALSE;
	immune_to_check = gpGlobals->time + 10;

	TeamFortress_SetSkin();
	TeamFortress_SpyCalcName();
	Spy_ResetExternalWeaponModel();

	if ( current_menu == MENU_SPY || current_menu == MENU_SPY_SKIN || current_menu == MENU_SPY_COLOR )
		ResetMenu();

	CBaseEntity *pTimer = FindTimer( TF_TIMER_DISGUISE );
	if ( pTimer )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Disguise_stop" );
		UTIL_Remove( pTimer );
	}
}

// What other players see the disguised spy holding, per disguise class
const struct
{
	char *szWeaponModel;
	char *szAnimExt;
} SpyFakeWeaponArray[] =
{
	{ "", "" },
	{ "models/p_nailgun.mdl", "mp5" },			// scout
	{ "models/p_sniper.mdl", "shotgun" },		// sniper
	{ "models/p_srpg.mdl", "rpg" },				// soldier
	{ "models/p_glauncher.mdl", "mp5" },		// demoman
	{ "models/p_snailgun.mdl", "mp5" },			// medic
	{ "models/p_mini.mdl", "ac" },				// hwguy
	{ "models/p_egon.mdl", "egon" },			// pyro
	{ "models/p_knife.mdl", "knife" },			// spy
	{ "models/p_9mmhandgun.mdl", "onehanded" },	// engineer
	{ "", "" },
};

void CBasePlayer::Spy_DisguiseExternalWeaponModel( void )
{
	if ( pev->playerclass != PC_SPY || !is_undercover || !undercover_skin )
		return;
	if ( undercover_skin < PC_SCOUT || undercover_skin > PC_ENGINEER || is_feigning )
		return;

	pev->weaponmodel = MAKE_STRING( SpyFakeWeaponArray[ undercover_skin ].szWeaponModel );
	strcpy( m_szAnimExtention, SpyFakeWeaponArray[ undercover_skin ].szAnimExt );
	m_iCurrentAnimationState = 0;
}

void CBasePlayer::Spy_ResetExternalWeaponModel( void )
{
	if ( is_feigning )
		return;

	pev->weaponmodel = MAKE_STRING( m_pszSavedWeaponModel );
	strcpy( m_szAnimExtention, m_szSavedAnimExtention );
	m_iCurrentAnimationState = 0;
}

// "disguise" command: open the menu, or cancel a disguise in progress
void CBasePlayer::TeamFortress_SpyGoUndercover( void )
{
	if ( ( pev->effects & SPY_GLOW_EFFECTS ) || is_unableto_spy_or_teleport == TRUE )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Spy_unable" );
		return;
	}

	if ( is_undercover != 2 )
	{
		current_menu = MENU_SPY;
		return;
	}

	ClientPrint( pev, HUD_PRINTCENTER, "#Disguise_stop" );

	CBaseEntity *pTimer = FindTimer( TF_TIMER_DISGUISE );
	if ( pTimer )
		UTIL_Remove( pTimer );

	is_undercover = FALSE;
}

// Pick the player whose name the disguised spy shows
void CBasePlayer::TeamFortress_SpyCalcName( void )
{
	CBaseEntity *pLast = undercover_target;
	undercover_target = NULL;

	if ( !undercover_team )
		return;

	// Prefer someone on that team playing that class (not the last one)
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
		if ( pPlayer && pPlayer != pLast && pPlayer->team_no == undercover_team && pPlayer->pev->playerclass == undercover_skin )
		{
			undercover_target = pPlayer;
			return;
		}
	}

	// Otherwise anyone on that team
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
		if ( pPlayer && pPlayer->team_no == undercover_team )
		{
			undercover_target = pPlayer;
			return;
		}
	}
}

void CBasePlayer::TeamFortress_SpyChangeSkin( int iClass )
{
	int iDisguiseTime = 4;
	int iTeam = m_iTeamToDisguiseAs;

	// Team change requested at the same time
	if ( iTeam )
	{
		// Enemy colours take longer
		if ( undercover_team != iTeam )
			iDisguiseTime = ( team_no != iTeam ) ? 8 : 4;

		if ( iClass == PC_SPY || undercover_skin == iClass )
			m_iTeamToDisguiseAs = 0;	// colour only: let ChangeColor start its own timer

		TeamFortress_SpyChangeColor( iTeam );
		m_iTeamToDisguiseAs = 0;
	}

	if ( iClass == PC_SPY && team_no == iTeam )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Disguise_resetclass" );
		undercover_skin = 0;
		undercover_team = 0;
		is_undercover = FALSE;
		Spy_ResetExternalWeaponModel();
		TeamFortress_SetSkin();
		return;
	}

	if ( undercover_skin == iClass )
		return;

	if ( ( pev->effects & SPY_GLOW_EFFECTS ) || is_unableto_spy_or_teleport == TRUE )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Spy_unable" );
		return;
	}

	ClientPrint( pev, HUD_PRINTCENTER, "#Disguise_start" );
	is_undercover = 2;	// disguising

	CBaseEntity *pTimer = FindTimer( TF_TIMER_DISGUISE );
	if ( pTimer )
		UTIL_Remove( pTimer );

	pTimer = CreateTimer( TF_TIMER_DISGUISE );
	pTimer->SetThink( &CBaseEntity::Timer_SpyUndercoverThink );
	pTimer->pev->nextthink = gpGlobals->time + iDisguiseTime;
	pTimer->pev->skin = iClass;
	pTimer->team_no = iTeam;
}

void CBasePlayer::TeamFortress_SpyChangeColor( int iTeamNo )
{
	if ( team_no == iTeamNo )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Disguise_resetteam" );
		undercover_team = 0;
		if ( !undercover_skin )
			is_undercover = FALSE;
		TeamFortress_SetSkin();
		return;
	}

	// A class change in progress will set the colour with its own timer
	if ( m_iTeamToDisguiseAs || undercover_team == iTeamNo )
		return;

	if ( ( pev->effects & SPY_GLOW_EFFECTS ) || is_unableto_spy_or_teleport == TRUE )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Spy_unable" );
		return;
	}

	ClientPrint( pev, HUD_PRINTCENTER, "#Disguise_start" );
	is_undercover = 2;

	CBaseEntity *pTimer = CreateTimer( TF_TIMER_DISGUISE );
	pTimer->SetThink( &CBaseEntity::Timer_SpyUndercoverThink );
	pTimer->pev->nextthink = gpGlobals->time + 4;
	pTimer->team_no = iTeamNo;
}

void CBasePlayer::TeamFortress_SpyDisguiseEnemy( BOOL bEnemy, int iClass )
{
	int iTeam;

	if ( bEnemy )
	{
		iTeam = 1;
		if ( number_of_teams > 1 )
		{
			do
			{
				iTeam = RANDOM_LONG( 1, (int)number_of_teams );
			} while ( iTeam == team_no );
		}
	}
	else
	{
		iTeam = team_no;
	}

	TeamFortress_SpyDisguise( iTeam, iClass );
}

void CBasePlayer::TeamFortress_SpyDisguise( int iTeam, int iClass )
{
	static float flLastDisguesChange;	// sic

	// at most once a second (shared by all players)
	if ( gpGlobals->time < flLastDisguesChange )
		flLastDisguesChange = 0;

	if ( gpGlobals->time - flLastDisguesChange < 1 )
		return;

	flLastDisguesChange = gpGlobals->time;

	if ( iTeam > number_of_teams || iTeam <= 0 )
		return;
	if ( iClass < PC_SCOUT || iClass > PC_ENGINEER )
		return;

	if ( ( pev->effects & SPY_GLOW_EFFECTS ) || is_unableto_spy_or_teleport == TRUE )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Spy_unable" );
		return;
	}

	m_iTeamToDisguiseAs = iTeam;
	TeamFortress_SpyChangeSkin( iClass );
}
