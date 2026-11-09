/***
*
*	Team Fortress Classic: Engineer dispenser
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "player.h"
#include "weapons.h"
#include "effects.h"
#include "tf_defs.h"

#define BUILDING_EVENT_DESTROYED	1024

LINK_ENTITY_TO_CLASS( building_dispenser, CTFDispenser );

void CTFDispenser::Spawn( void )
{
	Precache();

	pev->classname = MAKE_STRING( "building_dispenser" );
	pev->solid = SOLID_BBOX;
	pev->movetype = MOVETYPE_TOSS;
	pev->flags &= ~FL_ONGROUND;
	pev->velocity = Vector( 0, 0, 8 );
	pev->max_health = 150;
	pev->health = pev->max_health;
	pev->takedamage = DAMAGE_NO;
	pev->flags |= FL_MONSTER;

	SET_MODEL( ENT( pev ), "models/dispenser.mdl" );
	UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 24 ) );
}

// Removed by the owner (dismantled, changed class, left the game)
void CTFDispenser::Remove( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( real_owner->edict() );

	if ( !pOwner->no_dispenser_message )
		ClientPrint( pOwner->pev, HUD_PRINTCENTER, "#Dispenser_destroyed" );

	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
		(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

	UTIL_LogPrintf( "\"<-1><><>\" triggered \"Dispenser_destroyed\" against \"%s<%i><%s><%s>\"\n",
		STRING( pOwner->pev->netname ),
		GETPLAYERUSERID( pOwner->edict() ),
		GETPLAYERAUTHID( pOwner->edict() ),
		pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

	pOwner->no_dispenser_message = 0;
	pOwner->has_dispenser = FALSE;

	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLOSION );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_SHORT( g_sModelIndexFireball );
		WRITE_BYTE( 30 );	// scale * 10
		WRITE_BYTE( 15 );	// framerate
		WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
	MESSAGE_END();

	dremove( this );
}

void CTFDispenser::Precache( void )
{
	PRECACHE_MODEL( "models/dispenser.mdl" );
	m_iShardIndex = PRECACHE_MODEL( "models/computergibs.mdl" );
	m_usBuildingEvent = PRECACHE_EVENT( 1, "events/misc/tf_buildingevent.sc" );
}

CTFDispenser *CTFDispenser::CreateDispenser( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner )
{
	CTFDispenser *pBase = GetClassPtr( (CTFDispenser *)NULL );

	UTIL_SetOrigin( pBase->pev, vecOrigin );
	pBase->pev->angles = g_vecZero;
	pBase->pev->angles.y = UTIL_AngleMod( pOwner->pev->angles.y + 180 );	// face the engineer
	pBase->Spawn();

	pBase->real_owner = pOwner;
	pBase->team_no = pOwner->team_no;
	pBase->m_iDestroyed = FALSE;
	pBase->m_flNextUseTime = gpGlobals->time + 3;

	return pBase;
}

// Called when the build timer runs out
void CTFDispenser::Finished( void )
{
	real_owner->has_dispenser = TRUE;
	ClientPrint( real_owner->pev, HUD_PRINTNOTIFY, "#Dispenser_finish" );
	teamsprint( team_no, real_owner, HUD_PRINTNOTIFY, "#Dispenser_built", STRING( real_owner->pev->netname ) );

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Built_Dispenser\"\n",
		STRING( real_owner->pev->netname ),
		GETPLAYERUSERID( real_owner->edict() ),
		GETPLAYERAUTHID( real_owner->edict() ),
		real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );

	real_owner->ammo_cells -= 100;

	pev->takedamage = DAMAGE_AIM;
	SetTouch( &CTFDispenser::DispenserTouch );
	SetThink( &CTFDispenser::DispenserThink );
	pev->nextthink = gpGlobals->time + 0.1;
	m_flNextRefillTime = gpGlobals->time + 12;

	pev->movetype = MOVETYPE_TOSS;
	pev->velocity = Vector( 0, 0, 8 );
	pev->flags &= ~FL_ONGROUND;

	// The engineer puts a quarter of his ammo in, then keeps 75% of what
	// went in (sic: not of what he had left), so building gains ammo overall
	ammo_shells = ceil( real_owner->ammo_shells * 0.25 );
	ammo_nails = ceil( real_owner->ammo_nails * 0.25 );
	ammo_rockets = ceil( real_owner->ammo_rockets * 0.25 );
	ammo_cells = ceil( real_owner->ammo_cells * 0.25 );
	pev->armorvalue = ceil( real_owner->pev->armorvalue * 0.25 );

	real_owner->ammo_shells = ceil( ammo_shells * 0.75 );
	real_owner->ammo_nails = ceil( ammo_nails * 0.75 );
	real_owner->ammo_rockets = ceil( ammo_rockets * 0.75 );
	real_owner->ammo_cells = ceil( ammo_cells * 0.75 );
	real_owner->pev->armorvalue = ceil( pev->armorvalue * 0.75 );

	m_vOldOrigin = pev->origin;

	EMIT_SOUND( ENT( pev ), CHAN_WEAPON, "weapons/turrset.wav", 1, ATTN_NORM );
}

// Death-notice weapon name for building kill logs (HL ClientKill style)
void GetWeapon( entvars_t *pevInflictor, entvars_t *pKiller, char *weapon )
{
	CBaseEntity *Killer = CBaseEntity::Instance( pKiller );
	const char *killer_weapon_name = "world";
	int killer_index = 0;

	if ( pKiller->flags & FL_CLIENT )
	{
		killer_index = ENTINDEX( ENT( pKiller ) );

		if ( pevInflictor )
		{
			if ( pevInflictor == pKiller )
			{
				// If the inflictor is the killer, then it must be their current weapon doing the damage
				CBasePlayer *pPlayer = (CBasePlayer *)CBaseEntity::Instance( pKiller );

				if ( pPlayer->m_pActiveItem )
				{
					if ( pPlayer->m_pActiveItem->deathtype )
					{
						killer_weapon_name = STRING( pPlayer->m_pActiveItem->deathtype );
					}
					else
					{
						ItemInfo II;
						if ( pPlayer->m_pActiveItem->GetItemInfo( &II ) )
							killer_weapon_name = II.pszName;
					}
				}
			}
			else
			{
				CBaseEntity *pEnt = CBaseEntity::Instance( pevInflictor );
				if ( pEnt && pEnt->deathtype )
					killer_weapon_name = STRING( pEnt->deathtype );
				else
					killer_weapon_name = STRING( pevInflictor->classname );	// it's just that easy
			}
		}
	}
	else
	{
		CBaseEntity *pEnt = CBaseEntity::Instance( pevInflictor );
		if ( pEnt && pEnt->deathtype )
			killer_weapon_name = STRING( pEnt->deathtype );
		else
			killer_weapon_name = STRING( pevInflictor->classname );
	}

	// strip the monster_* or weapon_* from the inflictor's classname
	if ( strncmp( killer_weapon_name, "weapon_", 7 ) == 0 )
		killer_weapon_name += 7;
	else if ( strncmp( killer_weapon_name, "tf_weapon_", 10 ) == 0 )
		killer_weapon_name += 10;
	else if ( strncmp( killer_weapon_name, "monster_", 8 ) == 0 )
		killer_weapon_name += 8;
	else if ( strncmp( killer_weapon_name, "func_", 5 ) == 0 )
		killer_weapon_name += 5;

	strcpy( weapon, killer_weapon_name );
}

void CTFDispenser::Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib )
{
	char weapon[30];

	if ( m_iDestroyed )
		return;

	if ( !((CBasePlayer *)(CBaseEntity *)real_owner)->no_dispenser_message )
		ClientPrint( real_owner->pev, HUD_PRINTCENTER, "#Dispenser_destroyed" );

	real_owner->has_dispenser = FALSE;
	((CBasePlayer *)(CBaseEntity *)real_owner)->no_dispenser_message = 0;

	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
		(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

	SetThink( &CTFDispenser::Dispenser_Explode );
	pev->nextthink = gpGlobals->time + 0.1;

	if ( pevAttacker && (int)real_owner )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)CBaseEntity::Instance( pevAttacker );

		GetWeapon( pevInflictor, pevAttacker, weapon );

		if ( pevAttacker == pevInflictor )
		{
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Dispenser_Destroyed\"\n",
				STRING( real_owner->pev->netname ),
				GETPLAYERUSERID( real_owner->edict() ),
				GETPLAYERAUTHID( real_owner->edict() ),
				real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );
		}
		else if ( pevAttacker != real_owner->pev )
		{
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Dispenser_Destroyed\" against \"%s<%i><%s><%s>\" with \"%s\"\n",
				STRING( pevAttacker->netname ),
				GETPLAYERUSERID( ENT( pevAttacker ) ),
				GETPLAYERAUTHID( ENT( pevAttacker ) ),
				pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
				STRING( real_owner->pev->netname ),
				GETPLAYERUSERID( real_owner->edict() ),
				GETPLAYERAUTHID( real_owner->edict() ),
				real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR",
				weapon );
		}
	}

	m_iDestroyed = TRUE;
}

void CTFDispenser::Dispenser_Explode( void )
{
	MESSAGE_BEGIN( MSG_PVS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLODEMODEL );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_COORD( 400 );	// velocity
		WRITE_SHORT( m_iShardIndex );
		WRITE_SHORT( 10 );	// count
		WRITE_BYTE( 25 );	// life
	MESSAGE_END();

	// No damage if the owner left the game
	if ( real_owner->has_disconnected != TRUE )
	{
		float flDamage = ammo_cells + ammo_rockets * 1.5 + 25;
		if ( flDamage > 250 )
			flDamage = 250;

		RadiusDamage( pev, real_owner->pev, flDamage, CLASS_NONE, DMG_BLAST | DMG_RADIUS_QUAKE );
	}

	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLOSION );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_SHORT( g_sModelIndexFireball );
		WRITE_BYTE( 30 );	// scale * 10
		WRITE_BYTE( 15 );	// framerate
		WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
	MESSAGE_END();

	dremove( this );
}

//=========================================================
// Refill thinker: tops a player up once a second while
// they stand at the dispenser
//=========================================================
class CDispenserRefillThinker : public CBaseEntity
{
public:
	void Spawn( void );
	void Think( void );
	void StartRefillingPlayer( CBaseEntity *pPlayer, CTFDispenser *pDispenser, float flStartTime );

private:
	EHANDLE m_hDispenser;
	EHANDLE m_hPlayer;
	Vector m_InitialUsePoint;
};

void CDispenserRefillThinker::Spawn( void )
{
	pev->classname = MAKE_STRING( "timer" );
	timer_type = TF_TIMER_DISPENSERREFILL;
}

void CDispenserRefillThinker::Think( void )
{
	CBasePlayer *pl = (CBasePlayer *)(CBaseEntity *)m_hPlayer;
	CTFDispenser *disp = (CTFDispenser *)(CBaseEntity *)m_hDispenser;
	bool bDestroyTimer = true;

	if ( disp && pl && disp->m_flNextUseTime <= gpGlobals->time + 1.5 )
	{
		// Stop once the player walks away
		Vector moved = pl->pev->origin - m_InitialUsePoint;
		if ( moved.Length() <= 24 && disp->RefillPlayer( pl ) )
		{
			pev->nextthink = gpGlobals->time + 1;
			bDestroyTimer = false;
		}
	}

	if ( bDestroyTimer )
		UTIL_Remove( this );
}

void CDispenserRefillThinker::StartRefillingPlayer( CBaseEntity *pPlayer, CTFDispenser *pDispenser, float flStartTime )
{
	pev->nextthink = gpGlobals->time + flStartTime;
	m_hDispenser = pDispenser;
	m_hPlayer = pPlayer;
	m_InitialUsePoint = pPlayer->pev->origin;
}

LINK_ENTITY_TO_CLASS( dispenser_refill_timer, CDispenserRefillThinker );

void CTFDispenser::DispenserTouch( CBaseEntity *pOther )
{
	if ( !( pOther->pev->flags & FL_CLIENT ) )
		return;

	// Let the engineer know an enemy is helping himself
	if ( pOther->team_no && pOther->team_no != team_no )
		ClientPrint( real_owner->pev, HUD_PRINTCENTER, "#Dispenser_used" );

	if ( m_flNextUseTime > gpGlobals->time )
		return;

	// sic: looks for a timer owned by the dispenser, but the thinker never sets an owner
	if ( !FindTimer( TF_TIMER_DISPENSERREFILL ) )
	{
		// Spawn() is never called, so the thinker keeps its default classname
		CDispenserRefillThinker *pTimer = GetClassPtr( (CDispenserRefillThinker *)NULL );
		pTimer->StartRefillingPlayer( pOther, this, 0.2 );
	}

	m_flNextUseTime = gpGlobals->time + 1;
}

BOOL CTFDispenser::RefillPlayer( CBasePlayer *pPlayer )
{
	if ( !ammo_shells && !ammo_nails && !ammo_rockets && !ammo_cells && !pev->armorvalue )
	{
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Dispenser_empty" );
		return FALSE;
	}

	int iShells = min( pPlayer->maxammo_shells - pPlayer->ammo_shells, min( ammo_shells, 20 ) );
	ammo_shells -= iShells;

	int iNails = min( min( pPlayer->maxammo_nails - pPlayer->ammo_nails, 20 ), ammo_nails );
	ammo_nails -= iNails;

	int iRockets = min( min( pPlayer->maxammo_rockets - pPlayer->ammo_rockets, 10 ), ammo_rockets );
	ammo_rockets -= iRockets;

	// Engineers get a lot more metal
	int iCells;
	if ( pPlayer->pev->playerclass == PC_ENGINEER )
		iCells = min( min( pPlayer->maxammo_cells - pPlayer->ammo_cells, 75 ), ammo_cells );
	else
		iCells = min( min( pPlayer->maxammo_cells - pPlayer->ammo_cells, 10 ), ammo_cells );
	ammo_cells -= iCells;

	pPlayer->GiveTFAmmo( iShells, iNails, iRockets, iCells );

	int am = min( min( pPlayer->maxarmor - pPlayer->pev->armorvalue, pev->armorvalue ), 20.0f );
	pev->armorvalue -= am;
	pPlayer->pev->armorvalue += am;

	// sic: sets the dispenser's armour type, not the player's
	if ( pev->armortype == 0 )
	{
		pev->armortype = 0.3;
		items |= IT_ARMOR1;
	}

	int totalam = iShells + iNails + iRockets + iCells + am;
	if ( totalam )
		EMIT_SOUND( ENT( pPlayer->pev ), CHAN_ITEM, "items/ammopickup2.wav", 1, ATTN_NORM );

	return totalam != 0;
}

void CTFDispenser::DispenserThink( void )
{
	CheckBelowBuilding( 24 );
	UpdateEntityEvents( this );
	DoDamageEffects( pev, pev->max_health * 0.66, pev->max_health * 0.33 );

	// Slowly generate ammo
	if ( gpGlobals->time > m_flNextRefillTime )
	{
		ammo_shells += 20;
		ammo_cells += 20;
		ammo_nails += 30;
		ammo_rockets += 15;
		pev->armorvalue += 50;

		if ( ammo_shells > 400 )
			ammo_shells = 400;
		if ( ammo_nails > 600 )
			ammo_nails = 600;
		if ( ammo_rockets > 300 )
			ammo_rockets = 300;
		if ( ammo_cells > 400 )
			ammo_cells = 400;
		if ( pev->armorvalue > 500 )
			pev->armorvalue = 500;

		m_flNextRefillTime = gpGlobals->time + 12;
	}

	pev->nextthink = gpGlobals->time + 0.1;
}

// The owner used the dispenser: repair it, or else put ammo in
BOOL CTFDispenser::EngineerUse( CBasePlayer *pPlayer )
{
	m_flNextUseTime = gpGlobals->time + 3;

	float metalcost = ( pev->max_health - pev->health ) / 5;
	if ( metalcost )
	{
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Menu_RepairDisp" );

		if ( metalcost > pPlayer->ammo_cells )
			metalcost = pPlayer->ammo_cells;
		pPlayer->ammo_cells -= metalcost;
		pev->health += metalcost * 5;
		return TRUE;
	}

	float am;
	int putInCount = 0;

	am = min( min( pPlayer->ammo_shells, 40 ), 400 - ammo_shells );
	pPlayer->ammo_shells -= am;
	ammo_shells += am;
	putInCount += am;

	am = min( min( pPlayer->ammo_nails, 40 ), 600 - ammo_nails );
	pPlayer->ammo_nails -= am;
	ammo_nails += am;
	putInCount += am;

	am = min( min( pPlayer->ammo_rockets, 10 ), 300 - ammo_rockets );
	pPlayer->ammo_rockets -= am;
	ammo_rockets += am;
	putInCount += am;

	am = min( min( pPlayer->ammo_cells, 40 ), 400 - ammo_cells );
	pPlayer->ammo_cells -= am;
	ammo_cells += am;
	putInCount += am;

	if ( putInCount < 1 )
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Dispenser_AmmoNoMore" );
	else
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Menu_AmmoDisp" );

	ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Dispenser_has",
		UTIL_dtos1( (int)pev->health ),
		UTIL_dtos2( ammo_rockets ),
		UTIL_dtos3( (int)pev->armorvalue ),
		UTIL_dtos4( ammo_cells ) );

	return TRUE;
}

void CTFDispenser::TeamFortress_TakeEMPBlast( entvars_t *pevGren )
{
	CBaseEntity *pThrower = CBaseEntity::Instance( pevGren->owner );
	CBaseEntity *pGrenade = CBaseEntity::Instance( pevGren );

	// Allies' EMPs only hurt it with team damage on, but the owner's always do
	if ( !( (int)gpGlobals->teamplay & ( TEAMPLAY_HALFDIRECT | TEAMPLAY_NODIRECT | TEAMPLAY_HALFEXPLOSIVE | TEAMPLAY_NOEXPLOSIVE ) )
		|| !IsAlly( pThrower ) || (CBaseEntity *)real_owner == pThrower )
	{
		TakeDamage( pevGren, pThrower->pev, 200, DMG_BLAST );
	}
}
