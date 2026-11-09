/***
*
*	Team Fortress Classic: Engineer building
*	(placing and destroying dispensers, sentry guns and teleporters,
*	func_nobuild)
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

// iparam1 of the building event when a building is removed
#define BUILDING_EVENT_DESTROYED	1024

// Destroy all of eng's buildings of this classname. Buildings stuck in solid
// or sky (can't be reached) refund 100 metal.
void DestroyBuilding( CBaseEntity *eng, char *bld )
{
	for ( CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, bld ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, bld ) )
	{
		if ( (CBaseEntity *)pEnt->real_owner != eng )
			continue;

		int iContents = UTIL_PointContents( pEnt->pev->origin );
		if ( iContents == CONTENTS_SKY || iContents == CONTENTS_SOLID )
		{
			eng->ammo_cells += 100;
			((CBasePlayer *)eng)->TeamFortress_CheckClassStats();
		}

		pEnt->TakeDamage( pEnt->pev, pEnt->pev, 500, 0 );
	}
}

void DestroyTeleporter( CBaseEntity *eng, int type )
{
	for ( CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" ) )
	{
		if ( (CBaseEntity *)pEnt->real_owner != eng || ((CTFTeleporter *)pEnt)->m_iType != type )
			continue;

		int iContents = UTIL_PointContents( pEnt->pev->origin );
		if ( iContents == CONTENTS_SKY || iContents == CONTENTS_SOLID )
		{
			eng->ammo_cells += 100;
			((CBasePlayer *)eng)->TeamFortress_CheckClassStats();
		}

		pEnt->TakeDamage( pEnt->pev, pEnt->pev, 500, 0 );
	}
}

static void BuildingRemovedEvent( CBaseEntity *pBuilding )
{
	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pBuilding->edict(), pBuilding->m_usBuildingEvent, 0.0,
		(float *)&pBuilding->pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );
}

// Remove all of this engineer's buildings (class change, disconnect...)
void CBasePlayer::TeamFortress_RemoveBuildings( void )
{
	CBaseEntity *pEnt;

	for ( pEnt = UTIL_FindEntityByClassname( NULL, "building_dispenser" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "building_dispenser" ) )
	{
		if ( (CBaseEntity *)pEnt->real_owner != this )
			continue;

		if ( !no_dispenser_message )
			ClientPrint( pev, HUD_PRINTCENTER, "#Dispenser_destroyed" );
		no_dispenser_message = FALSE;
		has_dispenser = FALSE;

		BuildingRemovedEvent( pEnt );
		dremove( pEnt );
	}

	for ( pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" ) )
	{
		if ( (CBaseEntity *)pEnt->real_owner != this || ((CTFTeleporter *)pEnt)->m_iType != BUILD_TELEPORTER_ENTRANCE )
			continue;

		if ( !no_entry_teleporter_message )
			ClientPrint( pev, HUD_PRINTCENTER, "#Teleporter_Entrance_Destroyed" );
		no_entry_teleporter_message = FALSE;
		has_entry_teleporter = FALSE;

		BuildingRemovedEvent( pEnt );
		dremove( pEnt );
	}

	for ( pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" ) )
	{
		if ( (CBaseEntity *)pEnt->real_owner != this || ((CTFTeleporter *)pEnt)->m_iType != BUILD_TELEPORTER_EXIT )
			continue;

		if ( !no_exit_teleporter_message )
			ClientPrint( pev, HUD_PRINTCENTER, "#Teleporter_Exit_Destroyed" );
		no_exit_teleporter_message = FALSE;
		has_exit_teleporter = FALSE;

		BuildingRemovedEvent( pEnt );
		dremove( pEnt );
	}

	for ( pEnt = UTIL_FindEntityByClassname( NULL, "building_sentrygun" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "building_sentrygun" ) )
	{
		if ( (CBaseEntity *)pEnt->real_owner != this )
			continue;

		if ( !no_sentry_message )
			ClientPrint( pev, HUD_PRINTCENTER, "#Sentry_destroyed" );
		has_sentry = FALSE;
		no_sentry_message = FALSE;

		BuildingRemovedEvent( pEnt );

		// Close the menu of anyone using this sentry
		for ( int i = 1; i <= gpGlobals->maxClients; i++ )
		{
			CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
			if ( pPlayer && (CBaseEntity *)pPlayer->building == pEnt )
			{
				pPlayer->ResetMenu();
				pPlayer->building = NULL;
			}
		}

		dremove( pEnt );
		break;
	}

	for ( pEnt = UTIL_FindEntityByClassname( NULL, "building_sentrygun_base" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "building_sentrygun_base" ) )
	{
		if ( (CBaseEntity *)pEnt->real_owner == this )
		{
			dremove( pEnt );
			break;
		}
	}
}

// "build" command / impulse: open the build menu, build, or cancel building
void CBasePlayer::TeamFortress_EngineerBuild( int iBuildingNo )
{
	if ( !IsAlive() || gpGlobals->time < cb_prematch_time )
		return;

	if ( !( pev->flags & FL_ONGROUND ) )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Build_air" );
		return;
	}

	if ( !is_building )
	{
		if ( iBuildingNo > 0 )
		{
			TeamFortress_Build( iBuildingNo );
			return;
		}

		if ( ammo_cells < BUILD_COST_DISPENSER && !has_dispenser && !has_sentry )
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_nometal" );
		else
			current_menu = MENU_ENGINEER;
	}
	else if ( is_building == TRUE )
	{
		// Cancel the building in progress
		ClientPrint( pev, HUD_PRINTCENTER, "#Build_stop" );

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
}

// Returns 0 if pIgnore can build here, 1 if there's no room, 2 if inside a func_nobuild
int CBaseEntity::CheckArea( CBaseEntity *pIgnore )
{
	Vector vecOrigin = pev->origin;

	int iContents = UTIL_PointContents( vecOrigin );
	if ( iContents != CONTENTS_WATER && iContents != CONTENTS_EMPTY )
		return 1;

	// Builder must be able to see the spot
	Vector vecTarget = pev->origin;
	if ( pIgnore->pev->flags & FL_DUCKING )
		vecTarget = vecTarget + Vector( 0, 0, 18 );

	TraceResult tr;
	UTIL_TraceLine( pIgnore->EyePosition(), vecTarget, ignore_monsters, pIgnore->edict(), &tr );
	if ( tr.flFraction != 1.0 || tr.fAllSolid == 1 )
		return 1;

	UTIL_TraceHull( vecTarget, vecTarget, ignore_monsters, large_hull, edict(), &tr );
	if ( tr.flFraction != 1.0 || tr.fAllSolid == 1 )
		return 1;

	// Anything solid in the way?
	CBaseEntity *pEnt = NULL;
	while ( ( pEnt = UTIL_FindEntityInSphere( pEnt, pev->origin, 48 ) ) != NULL )
	{
		if ( pEnt != this && pEnt != pIgnore && pEnt->pev->solid >= SOLID_BBOX )
			return 1;
	}

	for ( pEnt = UTIL_FindEntityByClassname( NULL, "func_nobuild" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "func_nobuild" ) )
	{
		if ( vecOrigin.x >= pEnt->pev->mins.x && vecOrigin.y >= pEnt->pev->mins.y && vecOrigin.z >= pEnt->pev->mins.z &&
			vecOrigin.x <= pEnt->pev->maxs.x && vecOrigin.y <= pEnt->pev->maxs.y && vecOrigin.z <= pEnt->pev->maxs.z )
		{
			return 2;
		}
	}

	// Needs ground under it
	UTIL_TraceLine( vecOrigin, vecOrigin + Vector( 0, 0, -64 ), dont_ignore_monsters, edict(), &tr );
	if ( tr.flFraction == 1.0 )
		return 1;

	return 0;
}

void CBasePlayer::TeamFortress_Build( int iBuildingID )
{
	// Build 64 units in front of the player
	UTIL_MakeAimVectors( pev->angles );
	Vector vecDir = gpGlobals->v_forward;
	vecDir.z = 0;
	Vector vecPos = pev->origin + vecDir.Normalize() * 64;
	vecPos.x = (int)vecPos.x;
	vecPos.y = (int)vecPos.y;

	if ( current_menu == MENU_ENGINEER )
	{
		ResetMenu();
		pev->impulse = 0;
	}

	float flBuildTime;

	if ( iBuildingID == BUILD_DISPENSER )
	{
		if ( has_dispenser )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_onedispenser" );
			return;
		}
		if ( ammo_cells < BUILD_COST_DISPENSER )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_notenoughmetal" );
			return;
		}

		building = CTFDispenser::CreateDispenser( vecPos, pev->v_angle, this );
		flBuildTime = BUILD_TIME_DISPENSER;
	}
	else if ( iBuildingID == BUILD_SENTRYGUN )
	{
		if ( has_sentry )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_onesentry" );
			return;
		}
		if ( ammo_cells < BUILD_COST_SENTRYGUN )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_notenoughmetal" );
			return;
		}

		building = CTFSentrygunBase::CreateSentryBase( vecPos, pev->v_angle, this );
		flBuildTime = BUILD_TIME_SENTRYGUN;
	}
	else if ( iBuildingID == BUILD_TELEPORTER_ENTRANCE )
	{
		if ( has_entry_teleporter )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_entryteleporter" );
			return;
		}
		if ( ammo_cells < BUILD_COST_TELEPORTER )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_notenoughmetal" );
			return;
		}

		building = CTFTeleporter::CreateTeleporter( vecPos, pev->v_angle, this, BUILD_TELEPORTER_ENTRANCE );
		flBuildTime = BUILD_TIME_TELEPORTER;
	}
	else if ( iBuildingID == BUILD_TELEPORTER_EXIT )
	{
		if ( has_exit_teleporter )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_exitteleporter" );
			return;
		}
		if ( ammo_cells < BUILD_COST_TELEPORTER )
		{
			ClientPrint( pev, HUD_PRINTCENTER, "#Build_notenoughmetal" );
			return;
		}

		building = CTFTeleporter::CreateTeleporter( vecPos, pev->v_angle, this, BUILD_TELEPORTER_EXIT );
		flBuildTime = BUILD_TIME_TELEPORTER;
	}
	else
	{
		return;
	}

	int iArea = building->CheckArea( this );
	if ( iArea == 0 )
	{
		if ( pev->flags & FL_ONGROUND )
		{
			// Start building: the engineer can't move until it's done
			is_building = TRUE;
			tfstate |= TFSTATE_CANT_MOVE;
			immune_to_check = gpGlobals->time + 5;
			TeamFortress_SetSpeed();

			if ( m_pActiveItem )
				m_pActiveItem->Holster( 0 );

			CBaseEntity *pTimer = CreateTimer( TF_TIMER_BUILD );
			pTimer->SetThink( &CBaseEntity::Timer_FinishedBuilding );
			pTimer->pev->nextthink = gpGlobals->time + flBuildTime;

			EMIT_SOUND_DYN( edict(), CHAN_STATIC, "weapons/building.wav", 0.98, ATTN_NORM, 0, 125 );
			return;
		}

		ClientPrint( pev, HUD_PRINTCENTER, "#Build_air" );
	}
	else if ( iArea == 2 )
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Build_nobuild" );
	}
	else
	{
		ClientPrint( pev, HUD_PRINTCENTER, "#Build_noroom" );
	}

	UTIL_Remove( building );
	building = NULL;
}

// Drop a building that has nothing under it
void CBaseEntity::CheckBelowBuilding( int iDist )
{
	Vector vecEnd = pev->origin;
	vecEnd.z -= iDist;
	Vector vecSrc = pev->origin + Vector( 0, 0, 3 );

	TraceResult tr;
	UTIL_TraceLine( vecSrc, vecEnd, dont_ignore_monsters, edict(), &tr );

	if ( tr.flFraction == 1.0 )
	{
		pev->movetype = MOVETYPE_TOSS;
		pev->flags &= ~FL_ONGROUND;
	}
}

//=========================================================
// func_nobuild: brush area engineers can't build in
//=========================================================
class CNoBuildArea : public CBaseEntity
{
public:
	void Spawn( void );
};

LINK_ENTITY_TO_CLASS( func_nobuild, CNoBuildArea );

void CNoBuildArea::Spawn( void )
{
	pev->solid = SOLID_TRIGGER;
	pev->movetype = MOVETYPE_NONE;
	pev->effects |= EF_NODRAW;

	SET_MODEL( ENT( pev ), STRING( pev->model ) );
	UTIL_SetSize( pev, pev->mins, pev->maxs );
	UTIL_SetOrigin( pev, pev->origin );
}
