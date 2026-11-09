/***
*
*	Team Fortress Classic: Flamethrower (Pyro)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	The flame burst projectile (CTFFlamethrowerBurst) lives in pyro.cpp.
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

enum flamethrower_e {
	FLAME_IDLE1 = 0,
	FLAME_FIDGET1,
	FLAME_NONE1,
	FLAME_NONE2,
	FLAME_NONE3,
	FLAME_FIRE1,
	FLAME_FIRE2,
	FLAME_FIRE3,
	FLAME_FIRE4,
	FLAME_DRAW,
	FLAME_HOLSTER,
};

short sModelIndexFlameThrowerFlame;

LINK_ENTITY_TO_CLASS( tf_weapon_flamethrower, CTFFlamethrower );

void CTFFlamethrower::Reload( void )
{
}

void CTFFlamethrower::Spawn( void )
{
	current_ammo = NULL;
	Precache();
	m_iId = WEAPON_EGON;	// sic: HL leftover; GetItemInfo sets WEAPON_FLAMETHROWER
	SET_MODEL( ENT( pev ), "models/w_egon.mdl" );
	m_iDefaultAmmo = 50;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFFlamethrower::Precache( void )
{
	PRECACHE_MODEL( "models/w_egon.mdl" );
	PRECACHE_MODEL( "models/v_flame.mdl" );
	PRECACHE_MODEL( "models/p_egon.mdl" );
	PRECACHE_MODEL( "models/p_egon2.mdl" );
	PRECACHE_MODEL( "models/w_9mmclip.mdl" );

	PRECACHE_SOUND( "items/9mmclip1.wav" );
	PRECACHE_SOUND( "weapons/flmfire2.wav" );

	UTIL_PrecacheOther( "tf_flamethrower_burst" );

	m_usFireFlame = PRECACHE_EVENT( 1, "events/wpn/tf_flame.sc" );
}

int CTFFlamethrower::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "uranium";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_cells;
	else
		p->iAmmo1 = 200;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 3;
	p->iPosition = 2;
	p->iId = m_iId = WEAPON_FLAMETHROWER;
	p->iFlags = 0;
	p->iWeight = 20;
	return 1;
}

int CTFFlamethrower::AddToPlayer( CBasePlayer *pPlayer )
{
	if ( CBasePlayerWeapon::AddToPlayer( pPlayer ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgWeapPickup, NULL, pPlayer->pev );
			WRITE_BYTE( m_iId );
		MESSAGE_END();

		current_ammo = &m_pPlayer->ammo_cells;
		return TRUE;
	}
	return FALSE;
}

BOOL CTFFlamethrower::Deploy( void )
{
	return DefaultDeploy( "models/v_flame.mdl", "models/p_egon.mdl", FLAME_DRAW, "egon", 1 );
}

BOOL CTFFlamethrower::CanHolster( void )
{
	return TRUE;
}

void CTFFlamethrower::Holster( int skiplocal )
{
	m_fInReload = FALSE;
	m_pPlayer->m_flNextAttack = 0.5;
	SendWeaponAnim( FLAME_HOLSTER, 1 );
}

void CTFFlamethrower::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_cells <= 0 )
	{
		PlayEmptySound();
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = BRIGHT_GUN_FLASH;

	PLAYBACK_EVENT_FULL( FEV_NOTHOST, m_pPlayer->edict(), m_usFireFlame, 0.0,
		(float *)&m_pPlayer->pev->origin, (float *)&m_pPlayer->pev->angles, 0.0, 0.0,
		0, 0, m_pPlayer->pev->waterlevel > 2, 0 );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->GetGunPosition() + gpGlobals->v_forward * 16 + gpGlobals->v_right * 8 + gpGlobals->v_up * -8;

	if ( m_pPlayer->pev->waterlevel < 3 )
	{
		CTFFlamethrowerBurst::CreateBurst( vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this );
		DB_LogShots( 1 );
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.15 );
		m_flTimeWeaponIdle = 0.15;
	}
	else
	{
		// No flames underwater
		m_flNextPrimaryAttack = GetNextAttackDelay( 1.0 );
		m_flTimeWeaponIdle = 1.0;
	}

	m_pPlayer->ammo_cells--;
}

void CTFFlamethrower::SecondaryAttack( void )
{
}

void CTFFlamethrower::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle > 0 )
		return;

	int iAnim;
	if ( UTIL_SharedRandomLong( m_pPlayer->random_seed, 0, 4 ) == 0 )
	{
		iAnim = FLAME_FIDGET1;
		m_flTimeWeaponIdle = 3.0;
	}
	else
	{
		iAnim = FLAME_IDLE1;
		m_flTimeWeaponIdle = 12.5;
	}

	SendWeaponAnim( iAnim, 1 );
}
