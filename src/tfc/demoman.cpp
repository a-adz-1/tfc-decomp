/***
*
*	Team Fortress Classic: Demoman detpack
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"
#include "effects.h"
#include "tf_defs.h"

LINK_ENTITY_TO_CLASS( detpack, CDetpack );

void CDetpack::Spawn( void )
{
	Precache();

	bAlternateLight = FALSE;
	bTicked = FALSE;

	pev->movetype = MOVETYPE_TOSS;
	pev->solid = SOLID_BBOX;
	m_pBlinkSprite = NULL;

	if ( birthday )
		SET_MODEL( ENT( pev ), "models/presentlg.mdl" );
	else
		SET_MODEL( ENT( pev ), "models/detpack.mdl" );

	SetTouch( &CDetpack::DetpackTouch );
	SetThink( &CDetpack::DetpackThink );
	pev->nextthink = gpGlobals->time + 0.1;

	UTIL_SetSize( pev, Vector( -4, -4, -4 ), Vector( 4, 4, 4 ) );
	UTIL_SetOrigin( pev, pev->origin );

	weaponmode = 0;	// set to 1 while being disarmed (pev->enemy is the disarmer)

	EMIT_SOUND_DYN( edict(), CHAN_WEAPON, "weapons/mine_activate.wav", 1, ATTN_NORM, 0, PITCH_NORM );
}

// Enemy scouts disarm detpacks by touching them
void CDetpack::DetpackTouch( CBaseEntity *pOther )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	if ( pOther->Classify() != CLASS_PLAYER || pOther->pev->playerclass != PC_SCOUT )
		return;
	if ( !pOther->IsAlive() || pOwner->IsAlly( pOther ) )
		return;

	if ( birthday == 1 )
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Detpack_disarm_bday", STRING( pOther->pev->netname ), STRING( pOwner->pev->netname ) );
	else
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Detpack_disarm", STRING( pOwner->pev->netname ), STRING( pOther->pev->netname ) );

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%s><%s>\"\n",
		STRING( pOther->pev->netname ),
		GETPLAYERUSERID( pOther->edict() ),
		GETPLAYERAUTHID( pOther->edict() ),
		pOther->team_no ? GetTeamName( pOther->team_no ) : "SPECTATOR",
		STRING( pOwner->pev->netname ),
		GETPLAYERUSERID( pOwner->edict() ),
		GETPLAYERAUTHID( pOwner->edict() ),
		pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

	((CBasePlayer *)pOther)->TF_AddFrags( 1 );
	dremove( this );
}

// EMP sets the detpack off in 1-3 seconds
void CDetpack::TeamFortress_TakeEMPBlast( entvars_t *pevGren )
{
	pev->health = gpGlobals->time + 1 + RANDOM_FLOAT( 0, 2 );
}

// pev->health holds the time the detpack goes off
void CDetpack::DetpackThink( void )
{
	if ( pev->health && pev->health <= gpGlobals->time + 0.9 )
	{
		DetpackExplode();
		return;
	}

	CheckBelowBuilding( 8 );

	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	int iTime = (int)( pev->health - gpGlobals->time );
	pev->nextthink = gpGlobals->time + 1;

	if ( iTime > 10 )
		return;

	ClientPrint( pOwner->pev, HUD_PRINTNOTIFY, "#Detpack_countdown", UTIL_dtos1( iTime ) );

	if ( iTime > 5 )
		return;

	if ( !bTicked )
	{
		EMIT_SOUND_DYN( edict(), CHAN_WEAPON, "weapons/mine_charge.wav", 1, ATTN_NORM, 0, PITCH_NORM );
		bTicked = TRUE;

		// blinking red light for the last five seconds
		m_pBlinkSprite = CSprite::SpriteCreate( "sprites/flare3.spr", pev->origin + Vector( 0, 0, 64 ), FALSE );
		m_pBlinkSprite->pev->rendermode = kRenderGlow;
		m_pBlinkSprite->pev->rendercolor = Vector( 255, 0, 0 );
		m_pBlinkSprite->pev->renderamt = 0;
		m_pBlinkSprite->pev->renderfx = kRenderFxNoDissipation;
	}
	else if ( iTime != 5 )
	{
		if ( bAlternateLight )
		{
			bAlternateLight = FALSE;
			m_pBlinkSprite->pev->renderamt = 0;
		}
		else
		{
			bAlternateLight = TRUE;
			m_pBlinkSprite->pev->renderamt = 64;
		}
	}
}

void CDetpack::Precache( void )
{
	PRECACHE_MODEL( "models/presentlg.mdl" );
	PRECACHE_MODEL( "models/detpack.mdl" );
	PRECACHE_MODEL( "sprites/flare3.spr" );

	PRECACHE_SOUND( "weapons/mortarhit.wav" );
	PRECACHE_SOUND( "weapons/mine_activate.wav" );
	PRECACHE_SOUND( "weapons/mine_charge.wav" );
}

// A door closed on the detpack: give it back
void CDetpack::Remove( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	pOwner->ammo_detpack++;
	ClientPrint( pOwner->pev, HUD_PRINTCENTER, "#Detpack_blocking_door_destroyed" );

	UTIL_LogPrintf( "\"<-1><><>\" triggered \"Detpack_blocking_door_destroyed\" against \"%s<%i><%s><%s>\"\n",
		STRING( pOwner->pev->netname ),
		GETPLAYERUSERID( pOwner->edict() ),
		GETPLAYERAUTHID( pOwner->edict() ),
		pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

	if ( m_pBlinkSprite )
		dremove( m_pBlinkSprite );

	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLOSION );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_SHORT( g_sModelIndexSmoke );
		WRITE_BYTE( 30 );	// scale
		WRITE_BYTE( 15 );	// framerate
		WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
	MESSAGE_END();

	dremove( this );
}

void CDetpack::DetpackExplode( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	int iContents = UTIL_PointContents( pev->origin );
	if ( iContents == CONTENTS_SKY || iContents == CONTENTS_SOLID || pOwner->has_disconnected == TRUE )
	{
		ClientPrint( pOwner->pev, HUD_PRINTNOTIFY, "#Detpack_fizzle" );

		UTIL_LogPrintf( "\"<-1><><>\" triggered \"Detpack_Fizzle\" against \"%s<%i><%s><%s>\"\n",
			STRING( pOwner->pev->netname ),
			GETPLAYERUSERID( pOwner->edict() ),
			GETPLAYERAUTHID( pOwner->edict() ),
			pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );
	}
	else
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#FITH" );	// "Fire in the hole!"
		EMIT_SOUND_DYN( edict(), CHAN_WEAPON, "weapons/mortarhit.wav", 1, ATTN_NORM, 0, PITCH_NORM );

		if ( birthday )
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#SpreadsCheer", STRING( pOwner->pev->netname ) );

		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Detpack_Explode\"\n",
			STRING( pOwner->pev->netname ),
			GETPLAYERUSERID( pOwner->edict() ),
			GETPLAYERAUTHID( pOwner->edict() ),
			pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

		// Quake TF style blast: goals within 1500, damage within 700, line of sight only
		CBaseEntity *pEnt = NULL;
		while ( ( pEnt = UTIL_FindEntityInSphere( pEnt, pev->origin, WEAP_DETPACK_GOAL_SIZE ) ) != NULL )
		{
			TraceResult tr;
			UTIL_TraceLine( pev->origin, pEnt->Center() + pEnt->pev->view_ofs, dont_ignore_monsters, edict(), &tr );

			if ( tr.flFraction < 1.0 && tr.pHit != pEnt->edict() )
				continue;

			if ( FClassnameIs( pEnt->pev, "info_tfgoal" ) )
			{
				if ( ( pEnt->goal_activation & TFGA_TOUCH_DETPACK ) && pEnt->search_time == 0 )
					ActivateDoResults( pEnt, (CBasePlayer *)pOwner, pEnt );
			}
			else if ( pEnt->pev->takedamage )
			{
				if ( ( pEnt->pev->origin - pev->origin ).Length() > WEAP_DETPACK_SIZE )
					continue;

				Vector vecCenter = pEnt->pev->origin + ( pEnt->pev->mins + pEnt->pev->maxs ) * 0.5;
				float flPoints = 0.5 * ( pev->origin - vecCenter ).Length();
				if ( flPoints < 0 )
					flPoints = 0;
				flPoints = WEAP_DETPACK_SIZE - flPoints;

				if ( flPoints )
					pEnt->TakeDamage( pev, pOwner->pev, flPoints * 2, DMG_BLAST );
			}
		}

		MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
			WRITE_BYTE( TE_EXPLOSION );
			WRITE_COORD( pev->origin.x );
			WRITE_COORD( pev->origin.y );
			WRITE_COORD( pev->origin.z );
			WRITE_SHORT( g_sModelIndexFireball );
			WRITE_BYTE( 50 );	// scale
			WRITE_BYTE( 15 );	// framerate
			WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
		MESSAGE_END();
	}

	// Free a scout who was disarming it
	if ( weaponmode == 1 )
	{
		CBaseEntity *pDisarmer = CBaseEntity::Instance( pev->enemy );
		pDisarmer->tfstate &= ~TFSTATE_CANT_MOVE;
		((CBasePlayer *)pDisarmer)->TeamFortress_SetSpeed();

		CBaseEntity *pTimer = pDisarmer->FindTimer( TF_TIMER_DETPACKDISARM );
		if ( pTimer )
			dremove( pTimer );
	}

	if ( m_pBlinkSprite )
		dremove( m_pBlinkSprite );

	dremove( this );
}

// "detstart <time>"
void CBasePlayer::TeamFortress_SetDetpack( int iTimer )
{
	if ( !( weapons_carried & WEAP_DETPACK ) )
		return;
	if ( ammo_detpack < 1 )
		return;

	// Not on top of other things
	CBaseEntity *pEnt = NULL;
	while ( ( pEnt = UTIL_FindEntityInSphere( pEnt, pev->origin, 65 ) ) != NULL )
	{
		if ( FClassnameIs( pEnt->pev, "player" ) && pEnt != this && !( pEnt->pev->effects & EF_NODRAW ) )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_someone" );
			return;
		}
		if ( FClassnameIs( pEnt->pev, "building_sentrygun" ) )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_sentry" );
			return;
		}
		if ( FClassnameIs( pEnt->pev, "building_dispenser" ) )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_dispenser" );
			return;
		}
		if ( FClassnameIs( pEnt->pev, "building_teleporter" ) )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_teleporter" );
			return;
		}
		if ( FClassnameIs( pEnt->pev, "detpack" ) )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_stack" );
			return;
		}
	}

	if ( !( pev->flags & FL_ONGROUND ) )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_air" );
		return;
	}

	// One at a time
	for ( pEnt = UTIL_FindEntityByClassname( NULL, "detpack" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "detpack" ) )
	{
		if ( pEnt->pev->owner == edict() )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_oneactive" );
			return;
		}
	}

	if ( iTimer < 5 )
	{
		ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_fivesec" );
		return;
	}

	// Start setting it: the demoman can't move for 3 seconds
	ammo_detpack--;
	is_detpacking = TRUE;
	tfstate |= TFSTATE_CANT_MOVE;
	immune_to_check = gpGlobals->time + 10;
	TeamFortress_SetSpeed();

	m_pActiveItem->Holster( 0 );
	pev->weaponmodel = 0;

	ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_set", UTIL_dtos1( iTimer ) );

	CBaseEntity *pTimer = CreateTimer( TF_TIMER_DETPACKSET );
	pTimer->pev->nextthink = gpGlobals->time + WEAP_DETPACK_SETTIME;
	pTimer->SetThink( &CBaseEntity::Timer_DetpackSet );
	pTimer->pev->health = iTimer;
}

// "detstop": cancel while still setting it
void CBasePlayer::TeamFortress_DetpackStop( void )
{
	CBaseEntity *pTimer = FindTimer( TF_TIMER_DETPACKSET );
	if ( !pTimer )
		return;

	ClientPrint( pev, HUD_PRINTNOTIFY, "#Detpack_retrieve" );
	ammo_detpack++;
	dremove( pTimer );

	tfstate &= ~TFSTATE_CANT_MOVE;
	is_detpacking = FALSE;
	TeamFortress_SetSpeed();

	m_pActiveItem->Deploy();
}

BOOL CBasePlayer::TeamFortress_RemoveDetpacks( void )
{
	for ( CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "detpack" ); pEnt; pEnt = UTIL_FindEntityByClassname( pEnt, "detpack" ) )
	{
		if ( pEnt->pev->owner == edict() )
		{
			dremove( pEnt );
			return TRUE;
		}
	}
	return FALSE;
}
