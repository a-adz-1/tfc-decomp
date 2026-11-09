/***
*
*	Team Fortress Classic: Railgun (Engineer)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	Shared between server and client weapon prediction; no CLIENT_DLL
*	differences in this file.
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

enum railgun_e {
	RAIL_IDLE = 0,
	RAIL_FIRE,
	RAIL_DRAW,
	RAIL_HOLSTER,
};

LINK_ENTITY_TO_CLASS( tf_weapon_railgun, CTFRailgun );

void CTFRailgun::Spawn( void )
{
	pev->classname = MAKE_STRING( "tf_weapon_railgun" );
	Precache();
	m_iId = WEAPON_GLOCK;	// sic: left over from the HL glock; GetItemInfo sets WEAPON_LASER
	SET_MODEL( ENT( pev ), "models/w_gauss.mdl" );

	m_iDefaultAmmo = GLOCK_DEFAULT_GIVE;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFRailgun::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_railgun.mdl" );
	PRECACHE_MODEL( "models/w_gauss.mdl" );
	PRECACHE_MODEL( "models/p_9mmhandgun.mdl" );
	PRECACHE_MODEL( "models/p_9mmhandgun2.mdl" );

	PRECACHE_SOUND( "weapons/railgun.wav" );

	m_usFireRail = PRECACHE_EVENT( 1, "events/wpn/tf_rail.sc" );
}

int CTFRailgun::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "9mm";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_nails;
	else
		p->iAmmo1 = 50;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 1;
	p->iPosition = 2;
	p->iFlags = 0;
	p->iId = m_iId = WEAPON_LASER;
	p->iWeight = 10;
	return 1;
}

BOOL CTFRailgun::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_railgun.mdl", "models/p_9mmhandgun.mdl", RAIL_DRAW, "onehanded", 1 );
}

void CTFRailgun::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_nails <= 0 )
	{
		PlayEmptySound();
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.2 );
		return;
	}

	m_pPlayer->m_iWeaponVolume = NORMAL_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = NORMAL_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireRail );

	m_pPlayer->pev->effects |= EF_MUZZLEFLASH;
	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );

	UTIL_MakeVectors( m_pPlayer->pev->v_angle );
	Vector vecSrc = m_pPlayer->pev->origin + m_pPlayer->pev->view_ofs + gpGlobals->v_right * 2 + gpGlobals->v_up * -4;

	CTFNailgunNail::CreateRailgunNail( vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this );
	DB_LogShots( 1 );

	m_pPlayer->ammo_nails--;

	m_flNextPrimaryAttack = GetNextAttackDelay( 0.4 );
	m_flTimeWeaponIdle = 12.5;
}

void CTFRailgun::Reload( void )
{
}

void CTFRailgun::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle > 0 )
		return;

	m_flTimeWeaponIdle = 12.5;
	SendWeaponAnim( RAIL_IDLE, 1 );
}
