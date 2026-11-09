/***
*
*	Team Fortress Classic: Incendiary cannon (Pyro)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	The rocket itself (CTFIncendiaryCRocket) is implemented in pyro.cpp.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "weapons.h"
#include "nodes.h"
#include "player.h"
#include "tf_defs.h"

enum rpg_e {
	RPG_IDLE = 0,
	RPG_FIDGET,
	RPG_RELOAD,		// to reload
	RPG_FIRE2,		// to empty
	RPG_HOLSTER1,	// loaded
	RPG_DRAW1,		// loaded
	RPG_HOLSTER2,	// unloaded
	RPG_DRAW_UL,	// unloaded
	RPG_IDLE_UL,	// unloaded idle
	RPG_FIDGET_UL,	// unloaded fidget
};

LINK_ENTITY_TO_CLASS( tf_weapon_ic, CTFIncendiaryC );
LINK_ENTITY_TO_CLASS( tf_ic_rocket, CTFIncendiaryCRocket );

void CTFIncendiaryC::Reload( void )
{
}

void CTFIncendiaryC::Spawn( void )
{
	Precache();
	m_iId = WEAPON_RPG;		// sic: HL leftover; GetItemInfo sets WEAPON_INCENDIARY
	current_ammo = NULL;
	SET_MODEL( ENT( pev ), "models/w_rpg.mdl" );
	m_iDefaultAmmo = 50;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFIncendiaryC::Precache( void )
{
	PRECACHE_MODEL( "models/w_rpg.mdl" );
	PRECACHE_MODEL( "models/v_rpg.mdl" );
	PRECACHE_MODEL( "models/p_rpg.mdl" );
	PRECACHE_MODEL( "models/p_rpg2.mdl" );

	PRECACHE_SOUND( "items/9mmclip1.wav" );

	UTIL_PrecacheOther( "tf_ic_rocket" );

	PRECACHE_SOUND( "weapons/rocketfire1.wav" );
	PRECACHE_SOUND( "weapons/glauncher.wav" );

	m_usFireIC = PRECACHE_EVENT( 1, "events/wpn/tf_ic.sc" );
}

int CTFIncendiaryC::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "rockets";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_rockets;
	else
		p->iAmmo1 = 20;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 4;
	p->iPosition = 2;
	p->iId = m_iId = WEAPON_INCENDIARY;
	p->iFlags = 0;
	p->iWeight = 20;
	return 1;
}

int CTFIncendiaryC::AddToPlayer( CBasePlayer *pPlayer )
{
	if ( CBasePlayerWeapon::AddToPlayer( pPlayer ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgWeapPickup, NULL, pPlayer->pev );
			WRITE_BYTE( m_iId );
		MESSAGE_END();

		current_ammo = &m_pPlayer->ammo_rockets;
		return TRUE;
	}
	return FALSE;
}

BOOL CTFIncendiaryC::Deploy( void )
{
	if ( m_pPlayer->ammo_rockets )
		return DefaultDeploy( "models/v_rpg.mdl", "models/p_rpg.mdl", RPG_DRAW1, "rpg", 1 );

	return DefaultDeploy( "models/v_tfc_rpg.mdl", "models/p_rpg.mdl", RPG_DRAW_UL, "rpg", 1 );
}

BOOL CTFIncendiaryC::CanHolster( void )
{
	return TRUE;
}

void CTFIncendiaryC::Holster( int skiplocal )
{
	m_fInReload = FALSE;
	m_pPlayer->m_flNextAttack = 0.5;
	SendWeaponAnim( RPG_HOLSTER1, 1 );
}

void CTFIncendiaryC::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_rockets <= 0 )
	{
		PlayEmptySound();
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = BRIGHT_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireIC );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->GetGunPosition() + gpGlobals->v_forward * 16 + gpGlobals->v_right * 8 + gpGlobals->v_up * -8;

	CTFIncendiaryCRocket::CreateRpgRocket( vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this );
	DB_LogShots( 1 );

	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	m_pPlayer->ammo_rockets--;

	m_flNextPrimaryAttack = GetNextAttackDelay( 1.2 );
	m_flTimeWeaponIdle = 1.2;
}

void CTFIncendiaryC::SecondaryAttack( void )
{
}

void CTFIncendiaryC::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle > 0 )
		return;

	if ( m_pPlayer->ammo_rockets < 1 )
	{
		m_flTimeWeaponIdle = 1.0;
		return;
	}

	m_flTimeWeaponIdle = 3.0;
	SendWeaponAnim( RPG_FIDGET, 1 );
}
