/***
*
*	Team Fortress Classic: Quake-style map items
*	(health, armour, ammo boxes, powerups)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "items.h"
#include "weapons.h"
#include "gamerules.h"
#include "tf_defs.h"

extern int gmsgItemPickup;

// item_health spawnflags
#define H_ROTTEN	1	// small medkit
#define H_MEGA		2	// megahealth (can go over max)

// Respawn the item or remove it, then fire its targets
static void ItemPickedUp( CItem *pItem )
{
	if ( g_pGameRules->ItemShouldRespawn( pItem ) )
		pItem->Respawn();
	else
		UTIL_Remove( pItem );

	pItem->SUB_UseTargets( pItem, USE_TOGGLE, 0 );
}

//=========================================================
// Health
//=========================================================
class CItemHealth : public CItem
{
public:
	void Spawn( void );
	void Precache( void );
	BOOL MyTouch( CBasePlayer *pPlayer );

	int m_iHealAmount;
	int m_iHealType;	// 1 = megahealth
};

LINK_ENTITY_TO_CLASS( item_health, CItemHealth );

void CItemHealth::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	Precache();
	SET_MODEL( ENT( pev ), "models/w_medkit.mdl" );
	CItem::Spawn();

	if ( !m_flRespawnTime )
		m_flRespawnTime = 20;

	if ( pev->spawnflags & H_ROTTEN )
	{
		pev->noise = MAKE_STRING( "items/smallmedkit1.wav" );
		m_iHealAmount = 15;
		m_iHealType = 0;
	}
	else if ( pev->spawnflags & H_MEGA )
	{
		pev->noise = MAKE_STRING( "items/r_item1.wav" );
		m_iHealAmount = 100;
		m_iHealType = 1;
	}
	else
	{
		pev->noise = MAKE_STRING( "items/health1.wav" );
		m_iHealAmount = 25;
		m_iHealType = 0;
	}
}

void CItemHealth::Precache( void )
{
	PRECACHE_MODEL( "models/w_medkit.mdl" );
	PRECACHE_SOUND( "items/health1.wav" );
	PRECACHE_SOUND( "items/r_item1.wav" );
	PRECACHE_SOUND( "items/smallmedkit1.wav" );
}

BOOL CItemHealth::MyTouch( CBasePlayer *pPlayer )
{
	if ( m_iHealType == 1 )
	{
		// Megahealth: up to 250, then rots back down. Infected players
		// don't get the health, but large packs still cure them below.
		if ( !( pPlayer->tfstate & TFSTATE_INFECTED ) )
		{
			if ( pPlayer->pev->health >= 250 )
				return FALSE;
			if ( !pPlayer->TakeHealth( m_iHealAmount, DMG_IGNORE_MAXHEALTH ) )
				return FALSE;

			pPlayer->items |= IT_SUPERHEALTH;

			CBaseEntity *pTimer = pPlayer->CreateTimer( TF_TIMER_ROTHEALTH );
			pTimer->pev->nextthink = gpGlobals->time + 5;
			pTimer->SetThink( &CBaseEntity::Timer_HealthRot );
			pTimer->pev->enemy = edict();

			// ItemTouch respawns it
			SUB_UseTargets( this, USE_TOGGLE, 0 );
			return TRUE;
		}
	}
	else
	{
		if ( !pPlayer->TakeHealth( m_iHealAmount, 0 ) )
			return FALSE;
	}

	// large packs cure infection
	if ( ( pPlayer->tfstate & TFSTATE_INFECTED ) && m_iHealAmount > 80 )
	{
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Item_medhealed" );
		pPlayer->tfstate &= ~TFSTATE_INFECTED;
	}

	ItemPickedUp( this );
	return TRUE;
}

//=========================================================
// Armour
//=========================================================
class CItemArmor : public CItem
{
public:
	BOOL MyTouch( CBasePlayer *pPlayer );
	int CalculateBit( float flArmorType );

	float m_flArmorCount;
	float m_flArmorType;	// fraction of damage absorbed
};

int CItemArmor::CalculateBit( float flArmorType )
{
	if ( flArmorType == 0.3f )
		return IT_ARMOR1;
	if ( flArmorType == 0.6f )
		return IT_ARMOR2;
	if ( flArmorType == 0.8f )
		return IT_ARMOR3;

	ALERT( at_error, "Bad ArmorType.\n" );
	return 0;
}

BOOL CItemArmor::MyTouch( CBasePlayer *pPlayer )
{
	// Engineers also pick armour up for metal
	if ( pPlayer->pev->armorvalue >= pPlayer->maxarmor &&
		( pPlayer->pev->playerclass != PC_ENGINEER || pPlayer->ammo_cells >= pPlayer->maxammo_cells ) )
		return FALSE;

	// Note: the original compares armorvalue, not armortype, here
	float flType = m_flArmorType;
	if ( pPlayer->pev->armorvalue > flType )
		flType = pPlayer->pev->armorvalue;
	if ( flType > pPlayer->armor_allowed )
		flType = pPlayer->armor_allowed;

	int iBit = CalculateBit( flType );

	float flCount = m_flArmorCount;
	if ( flCount > pPlayer->maxarmor )
	{
		flCount = pPlayer->maxarmor;

		// Excess becomes metal
		if ( pPlayer->pev->playerclass == PC_ENGINEER && pPlayer->ammo_cells < pPlayer->maxammo_cells )
		{
			int iCells = (int)( (int)m_flArmorCount - pPlayer->maxarmor + pPlayer->ammo_cells );
			pPlayer->ammo_cells = min( iCells, pPlayer->maxammo_cells );
		}
	}

	pPlayer->pev->armortype = flType;
	pPlayer->pev->armorvalue = min( flCount + pPlayer->pev->armorvalue, pPlayer->maxarmor );
	pPlayer->items = ( pPlayer->items & ~( IT_ARMOR1 | IT_ARMOR2 | IT_ARMOR3 ) ) | iBit;

	if ( armorclass > 0 )
		pPlayer->armorclass = armorclass;

	EMIT_SOUND_DYN( pPlayer->edict(), CHAN_ITEM, "items/armoron_1.wav", 1, ATTN_NORM, 0, PITCH_NORM );

	ItemPickedUp( this );
	return TRUE;
}

class CItemArmorGreen : public CItemArmor
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_armor1, CItemArmorGreen );

void CItemArmorGreen::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	Precache();
	SET_MODEL( ENT( pev ), "models/g_armor.mdl" );
	CItem::Spawn();
	m_flArmorCount = 100;
	m_flArmorType = 0.3;
}

void CItemArmorGreen::Precache( void )
{
	PRECACHE_MODEL( "models/g_armor.mdl" );
	PRECACHE_SOUND( "items/armoron_1.wav" );
}

class CItemArmorYellow : public CItemArmor
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_armor2, CItemArmorYellow );

void CItemArmorYellow::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	Precache();
	SET_MODEL( ENT( pev ), "models/y_armor.mdl" );
	CItem::Spawn();
	m_flArmorCount = 150;
	m_flArmorType = 0.6;
}

void CItemArmorYellow::Precache( void )
{
	PRECACHE_MODEL( "models/y_armor.mdl" );
	PRECACHE_SOUND( "items/armoron_1.wav" );
}

class CItemArmorRed : public CItemArmor
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_armor3, CItemArmorRed );

void CItemArmorRed::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	Precache();
	SET_MODEL( ENT( pev ), "models/r_armor.mdl" );
	CItem::Spawn();
	m_flArmorCount = 200;
	m_flArmorType = 0.8;
}

void CItemArmorRed::Precache( void )
{
	PRECACHE_MODEL( "models/r_armor.mdl" );
	PRECACHE_SOUND( "items/armoron_1.wav" );
}

//=========================================================
// Ammo boxes. spawnflags 1 = large box (double ammo)
//=========================================================
class CItemAmmo : public CItem
{
public:
	void Spawn( void );
	void Precache( void );
	BOOL MyTouch( CBasePlayer *pPlayer );
	virtual BOOL GetGrenadePossibility( CBasePlayer *pPlayer );

	string_t m_isSmallBox;	// model names
	string_t m_isLargeBox;
};

BOOL CItemAmmo::GetGrenadePossibility( CBasePlayer *pPlayer )
{
	return FALSE;
}

void CItemAmmo::Spawn( void )
{
	CItem::Spawn();
	PRECACHE_SOUND( "items/gunpickup2.wav" );

	if ( pev->spawnflags & 1 )
	{
		SET_MODEL( ENT( pev ), STRING( m_isLargeBox ) );
		ammo_shells *= 2;
		ammo_nails *= 2;
		ammo_rockets *= 2;
		ammo_cells *= 2;
	}
	else
	{
		SET_MODEL( ENT( pev ), STRING( m_isSmallBox ) );
	}

	UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 16 ) );
}

void CItemAmmo::Precache( void )
{
	PRECACHE_SOUND( "items/gunpickup2.wav" );
}

BOOL CItemAmmo::MyTouch( CBasePlayer *pPlayer )
{
	BOOL bGotGrenade = GetGrenadePossibility( pPlayer );

	if ( pPlayer->GiveTFAmmo( ammo_shells, ammo_nails, ammo_rockets, ammo_cells ) )
	{
		EMIT_SOUND_DYN( pPlayer->edict(), CHAN_ITEM, "items/gunpickup2.wav", 1, ATTN_NORM, 0, PITCH_NORM );
	}
	else
	{
		if ( !bGotGrenade )
			return FALSE;
		EMIT_SOUND_DYN( pPlayer->edict(), CHAN_ITEM, "items/gunpickup2.wav", 1, ATTN_NORM, 0, PITCH_NORM );
	}

	if ( bGotGrenade )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgItemPickup, NULL, pPlayer->pev );
			WRITE_STRING( "grenade" );
		MESSAGE_END();
	}

	ItemPickedUp( this );
	return TRUE;
}

class CItemAmmoShells : public CItemAmmo
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_shells, CItemAmmoShells );

void CItemAmmoShells::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	m_isSmallBox = MAKE_STRING( "models/w_shotbox.mdl" );
	m_isLargeBox = MAKE_STRING( "models/w_shotbox.mdl" );
	pev->netname = MAKE_STRING( "shells" );
	ammo_shells = 20;
	Precache();
	CItemAmmo::Spawn();
}

void CItemAmmoShells::Precache( void )
{
	PRECACHE_MODEL( "models/w_shotbox.mdl" );
}

class CItemAmmoNails : public CItemAmmo
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_spikes, CItemAmmoNails );

void CItemAmmoNails::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	m_isSmallBox = MAKE_STRING( "models/w_crossbow_clip.mdl" );
	m_isLargeBox = MAKE_STRING( "models/w_crossbow_clip.mdl" );
	pev->netname = MAKE_STRING( "nails" );
	ammo_nails = 25;
	Precache();
	CItemAmmo::Spawn();
}

void CItemAmmoNails::Precache( void )
{
	PRECACHE_MODEL( "models/w_crossbow_clip.mdl" );
}

class CItemAmmoRockets : public CItemAmmo
{
public:
	void Spawn( void );
	void Precache( void );
	BOOL GetGrenadePossibility( CBasePlayer *pPlayer );
};

LINK_ENTITY_TO_CLASS( item_rockets, CItemAmmoRockets );

void CItemAmmoRockets::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	m_isSmallBox = MAKE_STRING( "models/w_rpgammo.mdl" );
	m_isLargeBox = MAKE_STRING( "models/w_rpgammo.mdl" );
	pev->netname = MAKE_STRING( "rockets" );
	ammo_rockets = 5;
	Precache();
	CItemAmmo::Spawn();
}

void CItemAmmoRockets::Precache( void )
{
	PRECACHE_MODEL( "models/w_rpgammo.mdl" );
}

// Rocket boxes have a 50% chance of a grenade, split between the two types
BOOL CItemAmmoRockets::GetGrenadePossibility( CBasePlayer *pPlayer )
{
	if ( RANDOM_FLOAT( 0, 1 ) < 0.5 )
		return FALSE;

	int iMax;

	if ( RANDOM_FLOAT( 0, 1 ) < 0.5 )
	{
		switch ( pPlayer->tp_grenades_1 )
		{
		case GR_TYPE_NAIL:
		case GR_TYPE_MIRV:		iMax = 2; break;
		case GR_TYPE_CALTROP:	iMax = 3; break;
		case GR_TYPE_NONE:		return FALSE;
		default:				iMax = 4; break;
		}

		if ( pPlayer->no_grenades_1 >= iMax )
			return FALSE;
		pPlayer->no_grenades_1++;
	}
	else
	{
		switch ( pPlayer->tp_grenades_2 )
		{
		case GR_TYPE_NAIL:
		case GR_TYPE_MIRV:		iMax = 2; break;
		case GR_TYPE_CONCUSSION: iMax = 3; break;
		case GR_TYPE_NONE:		return FALSE;
		default:				iMax = 4; break;
		}

		if ( pPlayer->no_grenades_2 >= iMax )
			return FALSE;
		pPlayer->no_grenades_2++;
	}

	return TRUE;
}

class CItemAmmoCells : public CItemAmmo
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_cells, CItemAmmoCells );

void CItemAmmoCells::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	m_isSmallBox = MAKE_STRING( "models/w_battery.mdl" );
	m_isLargeBox = MAKE_STRING( "models/w_battery.mdl" );
	pev->netname = MAKE_STRING( "cells" );
	ammo_cells = 5;
	Precache();
	CItemAmmo::Spawn();
}

void CItemAmmoCells::Precache( void )
{
	PRECACHE_MODEL( "models/w_battery.mdl" );
}

//=========================================================
// Powerups (Quake artifacts)
//=========================================================
class CItemPowerup : public CItem
{
public:
	void Spawn( void );
	BOOL MyTouch( CBasePlayer *pPlayer );
};

void CItemPowerup::Spawn( void )
{
	if ( !CheckExistence() )
	{
		dremove( this );
		return;
	}

	Precache();
	CItem::Spawn();
	UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 16 ) );
}

// The item's own *_finished fields hold the duration
BOOL CItemPowerup::MyTouch( CBasePlayer *pPlayer )
{
	EMIT_SOUND_DYN( pPlayer->edict(), CHAN_ITEM, STRING( pev->noise ), 1, ATTN_NORM, 0, PITCH_NORM );

	pPlayer->items |= items;

	if ( invincible_finished )
		pPlayer->invincible_finished = gpGlobals->time + invincible_finished;
	if ( radsuit_finished )
		pPlayer->radsuit_finished = gpGlobals->time + radsuit_finished;
	if ( invisible_finished )
		pPlayer->invisible_finished = gpGlobals->time + invisible_finished;
	if ( super_damage_finished )
		pPlayer->super_damage_finished = gpGlobals->time + super_damage_finished;

	pPlayer->pev->renderfx = kRenderFxNone;

	ItemPickedUp( this );
	return TRUE;
}

class CItemPowerupInvincible : public CItemPowerup
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_artifact_invulnerability, CItemPowerupInvincible );

void CItemPowerupInvincible::Spawn( void )
{
	Precache();
	CItemPowerup::Spawn();

	if ( !m_flRespawnTime )
		m_flRespawnTime = 300;

	invincible_finished = 30;
	SET_MODEL( ENT( pev ), "models/pent.mdl" );
	pev->netname = MAKE_STRING( "Pentagram of Protection" );
	pev->noise = MAKE_STRING( "items/protect.wav" );
	items = IT_INVULNERABILITY;
}

void CItemPowerupInvincible::Precache( void )
{
	PRECACHE_MODEL( "models/pent.mdl" );
	PRECACHE_SOUND( "items/protect.wav" );
	PRECACHE_SOUND( "items/protect2.wav" );
	PRECACHE_SOUND( "items/protect3.wav" );
}

class CItemPowerupRadsuit : public CItemPowerup
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_artifact_envirosuit, CItemPowerupRadsuit );

void CItemPowerupRadsuit::Spawn( void )
{
	Precache();
	CItemPowerup::Spawn();

	if ( !m_flRespawnTime )
		m_flRespawnTime = 60;

	radsuit_finished = 30;
	SET_MODEL( ENT( pev ), "models/w_suit.mdl" );
	pev->netname = MAKE_STRING( "Biosuit" );
	pev->noise = MAKE_STRING( "FVox/HEV_logon.wav" );
	items = IT_SUIT;
}

void CItemPowerupRadsuit::Precache( void )
{
	PRECACHE_MODEL( "models/w_suit.mdl" );
	PRECACHE_SOUND( "FVox/HEV_logon.wav" );
	PRECACHE_SOUND( "FVox/hev_shutdown.wav" );
}

class CItemPowerupInvisibility : public CItemPowerup
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_artifact_invisibility, CItemPowerupInvisibility );

void CItemPowerupInvisibility::Spawn( void )
{
	Precache();
	CItemPowerup::Spawn();

	if ( !m_flRespawnTime )
		m_flRespawnTime = 300;

	invisible_finished = 30;
	SET_MODEL( ENT( pev ), "models/invis.mdl" );
	pev->netname = MAKE_STRING( "Ring of Shadows" );
	pev->noise = MAKE_STRING( "items/inv1.wav" );
	items = IT_INVISIBILITY;
}

void CItemPowerupInvisibility::Precache( void )
{
	PRECACHE_MODEL( "models/invis.mdl" );
	PRECACHE_SOUND( "items/inv1.wav" );
	PRECACHE_SOUND( "items/inv2.wav" );
	PRECACHE_SOUND( "items/inv3.wav" );
}

class CItemPowerupQuad : public CItemPowerup
{
public:
	void Spawn( void );
	void Precache( void );
};

LINK_ENTITY_TO_CLASS( item_artifact_super_damage, CItemPowerupQuad );

void CItemPowerupQuad::Spawn( void )
{
	Precache();
	CItemPowerup::Spawn();

	if ( !m_flRespawnTime )
		m_flRespawnTime = 60;

	super_damage_finished = 30;
	SET_MODEL( ENT( pev ), "models/quad.mdl" );
	pev->netname = MAKE_STRING( "Quad Damage" );
	pev->noise = MAKE_STRING( "items/damage.wav" );
	items = IT_QUAD;
}

void CItemPowerupQuad::Precache( void )
{
	PRECACHE_MODEL( "models/quad.mdl" );
	PRECACHE_SOUND( "items/damage.wav" );
	PRECACHE_SOUND( "items/damage2.wav" );
	PRECACHE_SOUND( "items/damage3.wav" );
}
