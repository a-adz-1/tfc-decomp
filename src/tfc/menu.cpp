/***
*
*	Team Fortress Classic: player menus (team/class VGUI, spy, engineer)
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
#include "tf_defs.h"

#define BUILDING_EVENT_DESTROYED	1024

extern int gmsgVGUIMenu;
extern cvar_t tfc_autoteam;

static char cbuf[512];

// Print to every player on team tno (sic: ignore is never checked)
void teamsprint( int tno, CBaseEntity *ignore, int msg_dest, const char *st, const char *param1, const char *param2, const char *param3 )
{
	if ( tno == 0 )
		return;

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *client = UTIL_PlayerByIndex( i );
		if ( client && client->IsAlly( tno ) )
			ClientPrint( client->pev, msg_dest, st, param1, param2, param3 );
	}
}

float anglemod( float v )
{
	while ( v >= 360 )
		v = v - 360;
	while ( v < 0 )
		v = v + 360;
	return v;
}

char *infokey( CBasePlayer *pl, const char *key )
{
	if ( !key || !pl )
		return "";

	return g_engfuncs.pfnInfoKeyValue( g_engfuncs.pfnGetInfoKeyBuffer( pl->edict() ), key );
}

void CBasePlayer::ResetMenu( void )
{
	m_MenuStringBuffer[0] = 0;
	menu_displaytime = 0;
	menu_refreshtime = 0;
	current_menu = MENU_DEFAULT;
}

// Text menus are no longer sent to the client (VGUI replaced them); this
// only keeps track of what would be on screen
void MenuPrint( CBasePlayer *pl, const char *msg, int allowed, int display_time )
{
	// Don't resend the same menu while it's still up
	if ( gpGlobals->time < pl->m_MenuUpdateTime && pl->m_MenuSelectionBuffer == allowed && !strcmp( msg, pl->m_MenuStringBuffer ) )
		return;

	pl->m_MenuUpdateTime = gpGlobals->time + 10;
	strncpy( pl->m_MenuStringBuffer, msg, sizeof( pl->m_MenuStringBuffer ) );
	pl->m_MenuSelectionBuffer = allowed;

	// Split into the 50 character chunks the old ShowMenu message took
	char *msg_portion = msg;
	char sbuf[51];
	while ( strlen( msg_portion ) >= 50 )
	{
		strncpy( sbuf, msg_portion, 50 );
		sbuf[50] = 0;
		msg_portion += 50;
	}
}

void CBasePlayer::Player_Menu( void )
{
	if ( !m_bDisplayedMOTD )
	{
		g_pGameRules->SendMOTDToClient( edict() );
		Menu_Team();
		m_bDisplayedMOTD = TRUE;
	}

	if ( current_menu == 0 || current_menu == MENU_TEAM )
	{
		// Players who haven't joined a team (and aren't observing) get the team menu back
		if ( !pev->playerclass && !pev->team && !pev->iuser1 )
		{
			if ( !m_flSafetyCheckTime )
			{
				m_flSafetyCheckTime = gpGlobals->time + 2;
			}
			else if ( m_flSafetyCheckTime < gpGlobals->time )
			{
				Menu_Team();
				m_flSafetyCheckTime = 0;
				return;
			}
		}

		if ( current_menu == 0 )
		{
			menu_refreshtime = 0;
			return;
		}
	}
	else
	{
		m_flSafetyCheckTime = 0;
	}

	if ( menu_refreshtime > gpGlobals->time )
	{
		if ( menu_refreshtime >= gpGlobals->time + 2 )
			menu_refreshtime = gpGlobals->time + 2;
		return;
	}

	menu_refreshtime = gpGlobals->time + 2;

	if ( current_menu == MENU_INTRO )
	{
		Menu_Intro();
		if ( menu_displaytime <= 4 )
		{
			menu_displaytime++;
			return;
		}
		ResetMenu();
	}
	else if ( current_menu == MENU_CLASSHELP )
	{
		Menu_ClassHelp();
		if ( menu_displaytime <= 7.5 )
		{
			menu_displaytime++;
			return;
		}
		ResetMenu();
	}
	else if ( current_menu == MENU_SPY )
		Menu_Spy();
	else if ( current_menu == MENU_SPY_SKIN )
		Menu_Spy_Skin();
	else if ( current_menu == MENU_SPY_COLOR )
		Menu_Spy_Color();
	else if ( current_menu == MENU_ENGINEER )
		Menu_Engineer();
	else if ( current_menu == MENU_ENGINEER_FIX_SENTRYGUN )
		Menu_EngineerFix_SentryGun();
	else if ( current_menu == MENU_DISPENSER )
		Menu_Dispenser();
	else if ( current_menu == MENU_REPEATHELP )
	{
		Menu_RepeatHelp();
		current_menu = MENU_DEFAULT;
	}
	else if ( current_menu == MENU_TEAM || current_menu == MENU_CLASS )
	{
		// VGUI menus, nothing to refresh
	}
	else
	{
		current_menu = 0;
		menu_refreshtime = 0;
	}
}

void CBasePlayer::Menu_MapBriefing( void )
{
	BOOL bDisplayBriefing = TRUE;
	char *infobuffer = g_engfuncs.pfnGetInfoKeyBuffer( edict() );
	char *st = g_engfuncs.pfnInfoKeyValue( infobuffer, "dm" );

	// Players can turn the briefing off with setinfo dm 0
	if ( st && *st && ( !strcmp( st, "0" ) || !strcmp( st, "off" ) ) )
		bDisplayBriefing = FALSE;

	if ( !bDisplayBriefing )
		return;

	MESSAGE_BEGIN( MSG_ONE, gmsgVGUIMenu, NULL, pev );
		WRITE_BYTE( MENU_MAPBRIEFING );
		WRITE_STRING( STRING( gpGlobals->mapname ) );
	MESSAGE_END();
}

void CBasePlayer::Menu_Team( void )
{
	// Late joiners may be put in a team automatically
	if ( gpGlobals->time > 30 && tfc_autoteam.value && g_pGameRules->IsTeamplay() && TeamFortress_TeamPutPlayerInTeam() )
		return;

	current_menu = MENU_TEAM;

	MESSAGE_BEGIN( MSG_ONE, gmsgVGUIMenu, NULL, pev );
		WRITE_BYTE( MENU_TEAM );
	MESSAGE_END();
}

void CBasePlayer::Menu_Class( void )
{
	current_menu = MENU_CLASS;

	MESSAGE_BEGIN( MSG_ONE, gmsgVGUIMenu, NULL, pev );
		WRITE_BYTE( MENU_CLASS );
	MESSAGE_END();
}

void CBasePlayer::Menu_RepeatHelp( void )
{
	MenuPrint( this, "#Menu_repeathelp" );
}

void CBasePlayer::Menu_Input( float inp )
{
	if ( current_menu == MENU_SPY )
		Menu_Spy_Input( inp );
	else if ( current_menu == MENU_SPY_SKIN )
		Menu_Spy_Skin_Input( inp );
	else if ( current_menu == MENU_SPY_COLOR )
		Menu_Spy_Color_Input( inp );
	else if ( current_menu == MENU_ENGINEER )
		Menu_Engineer_Input( inp );
	else if ( current_menu == MENU_ENGINEER_FIX_MORTAR )
		Menu_EngineerFix_Mortar_Input( inp );
	else if ( current_menu == MENU_ENGINEER_FIX_SENTRYGUN )
		Menu_EngineerFix_SentryGun_Input( inp );
	else if ( current_menu == MENU_DISPENSER )
		Menu_Dispenser_Input( inp );
	else if ( current_menu == MENU_CLASSHELP )
		Menu_ClassHelp_Input( inp );
}

void CBasePlayer::Menu_Intro( void )
{
	char *st1 = "Welcome to TeamFortress v2.9 Beta\nby TeamFortress Software\n======================================\nwww.planetquake.com/teamfortress";
	MenuPrint( this, st1 );
}

void CBasePlayer::Menu_ClassHelp( void )
{
	int playerclass = pev->playerclass;

	if ( playerclass == PC_SCOUT )
		MenuPrint( this, "#Help_scout" );
	else if ( playerclass == PC_SNIPER )
		MenuPrint( this, "#Help_sniper" );
	else if ( playerclass == PC_SOLDIER )
		MenuPrint( this, "#Help_soldier" );
	else if ( playerclass == PC_DEMOMAN )
		MenuPrint( this, "#Help_demoman" );
	else if ( playerclass == PC_MEDIC )
		MenuPrint( this, "#Help_medic" );
	else if ( playerclass == PC_HVYWEAP )
		MenuPrint( this, "#Help_hwguy" );
	else if ( playerclass == PC_PYRO )
		MenuPrint( this, "#Help_pyro" );
	else if ( playerclass == PC_SPY )
		MenuPrint( this, "#Help_spy" );
	else if ( playerclass == PC_ENGINEER )
		MenuPrint( this, "#Help_engineer" );
}

void CBasePlayer::Menu_ClassHelp_Input( float inp )
{
	ResetMenu();
}

//=========================================================
// Spy
//=========================================================
void CBasePlayer::Menu_Spy( void )
{
	// Can't disguise while glowing
	if ( ( pev->effects & ( EF_BRIGHTFIELD | EF_BRIGHTLIGHT ) ) || is_unableto_spy_or_teleport == TRUE )
	{
		ResetMenu();
		return;
	}

	if ( is_feigning )
	{
		if ( undercover_team )
		{
			if ( undercover_skin )
				MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n" );
			else
				MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n" );
		}
		else if ( undercover_skin )
			MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Spy_resetskin \n5. #Nothing \n\n" );
		else
			MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_stopfeign \n4. #Nothing \n\n" );
	}
	else
	{
		if ( undercover_team )
		{
			if ( undercover_skin )
				MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskinandcolor \n5. #Nothing \n\n" );
			else
				MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetcolor \n5. #Nothing \n\n" );
		}
		else if ( undercover_skin )
			MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Spy_resetskin \n5. #Nothing \n\n" );
		else
			MenuPrint( this, "#Action \n1. #Spy_changeskin \n2. #Spy_changecolor \n3. #Spy_startfeign \n4. #Nothing \n\n" );
	}
}

void CBasePlayer::Menu_Spy_Input( float inp )
{
	if ( inp == 1 || inp == 2 )
	{
		if ( pev->effects & ( EF_BRIGHTFIELD | EF_BRIGHTLIGHT ) )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Spy_glowing" );
			ResetMenu();
			pev->impulse = 0;
			return;
		}
		if ( is_unableto_spy_or_teleport == TRUE )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Spy_unable" );
			ResetMenu();
			pev->impulse = 0;
			return;
		}
	}

	if ( inp == 1 )
	{
		Menu_Spy_Skin();
		current_menu = MENU_SPY_SKIN;
		menu_displaytime = 0;
		pev->impulse = 0;
		return;
	}
	else if ( inp == 2 )
	{
		Menu_Spy_Color();
		current_menu = MENU_SPY_COLOR;
		menu_displaytime = 0;
		pev->impulse = 0;
		return;
	}
	else if ( inp == 3 )
	{
		TeamFortress_SpyFeignDeath( FALSE );
	}
	else if ( inp == 4 )
	{
		Spy_RemoveDisguise();
	}
	else if ( inp == 5 )
	{
		// Only "Nothing" when there's a reset option in slot 4
		if ( !undercover_team && !undercover_skin )
			return;
	}
	else
	{
		return;
	}

	ResetMenu();
	pev->impulse = 0;
}

void CBasePlayer::Menu_Spy_Skin( void )
{
	MenuPrint( this, "#Spy_skinmenu \n1. #Scout \n2. #Sniper \n3. #Soldier \n4. #Demoman \n5. #Medic \n6. #HWGuy \n7. #Pyro \n8. #Spy \n9. #Engineer \n\n" );
}

void CBasePlayer::Menu_Spy_Skin_Input( float inp )
{
	if ( inp < 10 && inp > 0 )
	{
		TeamFortress_SpyChangeSkin( inp );
		ResetMenu();
		pev->impulse = 0;
	}
}

void CBasePlayer::Menu_Spy_Color( void )
{
	if ( number_of_teams == 0 )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Game_nocolorchange" );
		ResetMenu();
		pev->impulse = 0;
		return;
	}

	if ( number_of_teams == 1 )
		MenuPrint( this, "#Spy_colormenu \n\n1. #BlueTeam \n\n" );
	else if ( number_of_teams == 2 )
		MenuPrint( this, "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n\n" );
	else if ( number_of_teams == 3 )
		MenuPrint( this, "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n\n" );
	else
		MenuPrint( this, "#Spy_colormenu \n\n1. #BlueTeam \n2. #RedTeam \n3. #YellowTeam \n4. #GreenTeam \n\n" );
}

void CBasePlayer::Menu_Spy_Color_Input( float inp )
{
	if ( inp >= 1 && inp <= number_of_teams )
	{
		TeamFortress_SpyChangeColor( inp );
		ResetMenu();
		pev->impulse = 0;
	}
}

//=========================================================
// Engineer
//=========================================================
void CBasePlayer::Menu_Engineer( void )
{
	char *s_action = "#Action \n";
	char *s_disp;
	char *s_sentry;
	char *s_dismantle;
	char *s_rotate;
	char *s_dismantledisp;
	char *s_nothing = "5. #Nothing \n\n";

	if ( has_dispenser )
		s_disp = "7. #Menu_DetDisp \n";
	else if ( ammo_cells >= 100 )
		s_disp = "1. #Menu_BuildDisp \n";
	else
		s_disp = "\n";

	if ( has_sentry )
		s_sentry = "8. #Menu_DetSentry \n";
	else if ( ammo_cells >= 130 )
		s_sentry = "2. #Menu_BuildSentry \n";
	else
		s_sentry = "\n";

	if ( has_sentry )
	{
		s_dismantle = "3. #Menu_DismantleSentry \n";
		s_rotate = "4. #Menu_RotateSentry \n";
	}
	else
	{
		s_dismantle = "\n";
		s_rotate = "\n";
	}

	if ( has_dispenser )
		s_dismantledisp = "9. #Menu_DismantleDisp \n";
	else
		s_dismantledisp = "\n";

	sprintf( cbuf, "%s%s%s%s%s%s%s", s_action, s_disp, s_sentry, s_dismantle, s_rotate, s_dismantledisp, s_nothing );
	MenuPrint( this, cbuf );
}

void CBasePlayer::Menu_Engineer_Input( float inp )
{
	if ( inp == 1 && ammo_cells >= 100 && has_dispenser != TRUE )
	{
		TeamFortress_EngineerBuild( BUILD_DISPENSER );
		ResetMenu();
		pev->impulse = 0;
	}
	else if ( inp == 2 && ammo_cells >= 130 && has_sentry != TRUE )
	{
		TeamFortress_EngineerBuild( BUILD_SENTRYGUN );
		ResetMenu();
		pev->impulse = 0;
	}
	else if ( ( inp == 3 || inp == 4 || inp == 6 ) && has_sentry == TRUE )
	{
		ResetMenu();
		pev->impulse = 0;

		CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_sentrygun" );
		while ( pEnt && (CBaseEntity *)pEnt->real_owner != this )
			pEnt = UTIL_FindEntityByClassname( pEnt, "building_sentrygun" );

		if ( !pEnt )
			return;

		if ( inp == 3 )
		{
			// Dismantle: get most of the metal back
			if ( ( pev->origin - pEnt->pev->origin ).Length() > 128 )
			{
				ClientPrint( pev, HUD_PRINTCENTER, "#Sentry_DistDismantle" );
				return;
			}

			ClientPrint( pev, HUD_PRINTNOTIFY, "#Sentry_dismantle" );
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Sentry_Dismantle\"\n",
				STRING( pev->netname ),
				GETPLAYERUSERID( edict() ),
				GETPLAYERAUTHID( edict() ),
				team_no ? GetTeamName( team_no ) : "SPECTATOR" );

			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEnt->edict(), pEnt->m_usBuildingEvent, 0.0,
				(float *)&pEnt->pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

			ammo_cells += pEnt->weapon * 65;	// 65 per sentry level
			TeamFortress_CheckClassStats();
			dremove( pEnt->m_pOtherSection );
			dremove( pEnt );
			has_sentry = FALSE;
		}
		else if ( inp == 4 )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Sentry_rotate" );
			pEnt->m_iRightBound = anglemod( pEnt->m_iRightBound + 45 );
			pEnt->m_iLeftBound = anglemod( pEnt->m_iLeftBound + 45 );
		}
		else if ( inp == 6 )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Sentry_rotate180" );
			pEnt->m_iRightBound = anglemod( pEnt->m_iRightBound + 180 );
			pEnt->m_iLeftBound = anglemod( pEnt->m_iLeftBound + 180 );
		}
	}
	else if ( inp == 7 && has_dispenser == TRUE )
	{
		DestroyBuilding( this, "building_dispenser" );
		ResetMenu();
		pev->impulse = 0;
	}
	else if ( inp == 8 && has_sentry == TRUE )
	{
		DestroyBuilding( this, "building_sentrygun" );
		ResetMenu();
		pev->impulse = 0;
	}
	else if ( inp == 9 && has_dispenser == TRUE )
	{
		ResetMenu();
		pev->impulse = 0;

		CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_dispenser" );
		while ( pEnt && (CBaseEntity *)pEnt->real_owner != this )
			pEnt = UTIL_FindEntityByClassname( pEnt, "building_dispenser" );

		if ( !pEnt )
			return;

		if ( ( pev->origin - pEnt->pev->origin ).Length() > 128 )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Dispenser_DistDismantle" );
			return;
		}

		ClientPrint( pev, HUD_PRINTNOTIFY, "#Dispenser_dismantle" );
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Dispenser_Dismantle\"\n",
			STRING( pev->netname ),
			GETPLAYERUSERID( edict() ),
			GETPLAYERAUTHID( edict() ),
			team_no ? GetTeamName( team_no ) : "SPECTATOR" );

		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEnt->edict(), pEnt->m_usBuildingEvent, 0.0,
			(float *)&pEnt->pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

		ammo_cells += 50;
		TeamFortress_CheckClassStats();
		dremove( pEnt );
		has_dispenser = FALSE;
	}
	else if ( inp == 10 && has_entry_teleporter == TRUE )
	{
		ResetMenu();
		pev->impulse = 0;

		CTFTeleporter *pEnt = (CTFTeleporter *)UTIL_FindEntityByClassname( NULL, "building_teleporter" );
		while ( pEnt && ( (CBaseEntity *)pEnt->real_owner != this || pEnt->m_iType != BUILD_TELEPORTER_ENTRANCE ) )
			pEnt = (CTFTeleporter *)UTIL_FindEntityByClassname( pEnt, "building_teleporter" );

		if ( !pEnt )
			return;

		if ( ( pev->origin - pEnt->pev->origin ).Length() > 128 )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Teleporter_DistDismantle" );
			return;
		}

		// Not while someone is using either end
		CTFTeleporter *pMatch = pEnt->FindMatch();
		if ( pEnt->m_pPlayer || ( pMatch && pMatch->m_pPlayer ) )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Teleporter_UseDismantle" );
			return;
		}

		ClientPrint( pev, HUD_PRINTNOTIFY, "#Teleporter_entrance_dismantle" );
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Teleporter_Entrance_Dismantle\"\n",
			STRING( pev->netname ),
			GETPLAYERUSERID( edict() ),
			GETPLAYERAUTHID( edict() ),
			team_no ? GetTeamName( team_no ) : "SPECTATOR" );

		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEnt->edict(), pEnt->m_usBuildingEvent, 0.0,
			(float *)&pEnt->pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

		ammo_cells += 62;
		TeamFortress_CheckClassStats();
		dremove( pEnt );
		has_entry_teleporter = FALSE;
	}
	else if ( inp == 11 && has_exit_teleporter == TRUE )
	{
		ResetMenu();
		pev->impulse = 0;

		CTFTeleporter *pEnt = (CTFTeleporter *)UTIL_FindEntityByClassname( NULL, "building_teleporter" );
		while ( pEnt && ( (CBaseEntity *)pEnt->real_owner != this || pEnt->m_iType != BUILD_TELEPORTER_EXIT ) )
			pEnt = (CTFTeleporter *)UTIL_FindEntityByClassname( pEnt, "building_teleporter" );

		if ( !pEnt )
			return;

		if ( ( pev->origin - pEnt->pev->origin ).Length() > 128 )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Teleporter_DistDismantle" );
			return;
		}

		CTFTeleporter *pMatch = pEnt->FindMatch();
		if ( pEnt->m_pPlayer || ( pMatch && pMatch->m_pPlayer ) )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Teleporter_UseDismantle" );
			return;
		}

		ClientPrint( pev, HUD_PRINTNOTIFY, "#Teleporter_exit_dismantle" );
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Teleporter_Exit_Dismantle\"\n",
			STRING( pev->netname ),
			GETPLAYERUSERID( edict() ),
			GETPLAYERAUTHID( edict() ),
			team_no ? GetTeamName( team_no ) : "SPECTATOR" );

		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEnt->edict(), pEnt->m_usBuildingEvent, 0.0,
			(float *)&pEnt->pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

		ammo_cells += 62;
		TeamFortress_CheckClassStats();
		dremove( pEnt );
		has_exit_teleporter = FALSE;
	}
	else if ( inp == 5 )
	{
		ResetMenu();
		pev->impulse = 0;
	}
}

void CBasePlayer::Menu_EngineerFix_Dispenser( void )
{
	MenuPrint( this, "#Action  \n1. #Menu_AmmoDisp \n2. #Menu_ArmorDisp \n3. #Menu_RepairDisp \n4. #Menu_DismantleDisp \n5. #Nothing \n\n" );
}

void CBasePlayer::Menu_EngineerFix_Dispenser_Input( float inp )
{
}

void CBasePlayer::Menu_EngineerFix_SentryGun( void )
{
	if ( !building )
		return;

	if ( building->weapon < 3 && ammo_cells >= 130 )
		MenuPrint( this, "#Action  \n1. #Menu_AmmoSentry \n2. #Menu_UpgradeSentry \n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n" );
	else
		MenuPrint( this, "#Action  \n1. #Menu_AmmoSentry \n\n3. #Menu_RepairSentry \n4. #Menu_DismantleSentry \n5. #Nothing \n\n6. #Menu_RotateSentry \n" );
}

void CBasePlayer::Menu_EngineerFix_SentryGun_Input( float inp )
{
	if ( !building )
	{
		ResetMenu();
		return;
	}

	if ( !building->real_owner || !building->real_owner->has_sentry )
	{
		ResetMenu();
		building = NULL;
		return;
	}

	if ( inp == 1 )
	{
		// Put shells (and rockets for a level 3) in
		float am = min( (float)ammo_shells, 40.0f );
		if ( am > building->maxammo_shells - building->ammo_shells )
			am = building->maxammo_shells - building->ammo_shells;
		ammo_shells -= am;
		building->ammo_shells += am;

		if ( building->weapon == 3 )
		{
			am = min( (float)ammo_rockets, 20.0f );
			if ( am > building->maxammo_rockets - building->ammo_rockets )
				am = building->maxammo_rockets - building->ammo_rockets;
			ammo_rockets -= am;
			building->ammo_rockets += am;
		}
	}
	else if ( building->weapon < 3 && inp == 2 )
	{
		if ( ammo_cells >= 130 )
		{
			ammo_cells -= 130;
			((CTFSentrygun *)(CBaseEntity *)building)->Upgrade();
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Sentry_upgrade", UTIL_dtos1( building->weapon ) );
		}
	}
	else if ( inp == 3 )
	{
		// Repair: 1 cell per 5 health
		float metalcost = ( building->pev->max_health - building->pev->health ) / 5;
		if ( metalcost > ammo_cells )
			metalcost = ammo_cells;
		ammo_cells -= metalcost;
		building->pev->health += metalcost * 5;
	}
	else if ( inp == 4 )
	{
		if ( building->real_owner )
		{
			if ( (CBaseEntity *)building->real_owner != this )
				return;
			building->real_owner->has_sentry = FALSE;
		}

		ClientPrint( pev, HUD_PRINTNOTIFY, "#Sentry_dismantle" );
		ammo_cells += 65;
		TeamFortress_CheckClassStats();

		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, building->edict(), building->m_usBuildingEvent, 0.0,
			(float *)&building->pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

		dremove( building->m_pOtherSection );
		dremove( building );
	}
	else if ( inp == 6 )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Sentry_rotate" );
		building->m_iRightBound = anglemod( building->m_iRightBound + 45 );
		building->m_iLeftBound = anglemod( building->m_iLeftBound + 45 );
	}

	if ( inp >= 1 && inp <= 6 )
	{
		ResetMenu();
		pev->impulse = 0;
		building = NULL;

		if ( pev->armorvalue == 0 )
		{
			pev->armortype = 0;
			items &= ~( IT_ARMOR1 | IT_ARMOR2 | IT_ARMOR3 );
			armorclass = 0;
		}
	}
}

void CBasePlayer::Menu_EngineerFix_Mortar( void )
{
}

void CBasePlayer::Menu_EngineerFix_Mortar_Input( float inp )
{
	if ( inp >= 1 && inp <= 5 )
	{
		ResetMenu();
		pev->impulse = 0;

		if ( pev->armorvalue == 0 )
		{
			pev->armortype = 0;
			items &= ~( IT_ARMOR1 | IT_ARMOR2 | IT_ARMOR3 );
			armorclass = 0;
		}
	}
}

void CBasePlayer::Menu_Dispenser( void )
{
	MenuPrint( this, "#Menu_Dispenser" );
}

void CBasePlayer::Menu_Dispenser_Input( float inp )
{
}
