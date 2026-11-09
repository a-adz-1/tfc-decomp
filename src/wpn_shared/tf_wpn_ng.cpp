/***
*
*	Team Fortress Classic: Nailgun and Super nailgun
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	Built from the HL MP5 (same animation enum). The nails themselves are
*	in tf_wpn_nails.cpp.
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

enum mp5_e {
	MP5_LONGIDLE = 0,
	MP5_IDLE1,
	MP5_LAUNCH,
	MP5_RELOAD,
	MP5_DEPLOY,
	MP5_FIRE1,
	MP5_FIRE2,
	MP5_FIRE3,
};

LINK_ENTITY_TO_CLASS( tf_weapon_ng, CTFNailgun );
LINK_ENTITY_TO_CLASS( tf_weapon_superng, CTFSuperNailgun );

void CTFNailgun::Reload( void )
{
}

void CTFNailgun::Spawn( void )
{
	current_ammo = NULL;
	Precache();
	m_iId = WEAPON_MP5;		// sic: HL leftover; GetItemInfo sets WEAPON_NAILGUN
	m_iDefaultAmmo = 50;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFNailgun::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_nailgun.mdl" );
	PRECACHE_MODEL( "models/v_tfc_supernailgun.mdl" );
	PRECACHE_MODEL( "models/p_nailgun.mdl" );
	PRECACHE_MODEL( "models/p_nailgun2.mdl" );
	PRECACHE_MODEL( "models/p_snailgun.mdl" );
	PRECACHE_MODEL( "models/p_snailgun2.mdl" );

	PRECACHE_SOUND( "items/9mmclip1.wav" );
	PRECACHE_SOUND( "items/clipinsert1.wav" );
	PRECACHE_SOUND( "items/cliprelease1.wav" );
	PRECACHE_SOUND( "weapons/airgun_1.wav" );
	PRECACHE_SOUND( "weapons/spike2.wav" );
	PRECACHE_SOUND( "weapons/357_cock1.wav" );

	m_usFireNailGun = PRECACHE_EVENT( 1, "events/wpn/tf_nail.sc" );
}

int CTFNailgun::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "9mm";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_nails;
	else
		p->iAmmo1 = 200;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = 0;
	p->iSlot = 3;
	p->iPosition = 4;
	p->iId = m_iId = WEAPON_NAILGUN;
	p->iFlags = 0;
	p->iWeight = 15;
	return 1;
}

int CTFNailgun::AddToPlayer( CBasePlayer *pPlayer )
{
	if ( CBasePlayerWeapon::AddToPlayer( pPlayer ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgWeapPickup, NULL, pPlayer->pev );
			WRITE_BYTE( m_iId );
		MESSAGE_END();

		current_ammo = &m_pPlayer->ammo_nails;
		return TRUE;
	}
	return FALSE;
}

BOOL CTFNailgun::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_nailgun.mdl", "models/p_nailgun.mdl", MP5_DEPLOY, "mp5", 1 );
}

BOOL CTFSuperNailgun::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_supernailgun.mdl", "models/p_snailgun.mdl", MP5_DEPLOY, "mp5", 1 );
}

void CTFNailgun::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_nails <= 0 )
	{
		PlayEmptySound();
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = BRIGHT_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireNailGun );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->pev->origin + m_pPlayer->pev->view_ofs + gpGlobals->v_right * 2 + gpGlobals->v_up * -4;

	CTFNailgunNail::CreateNail( FALSE, vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this, TRUE );
	DB_LogShots( 1 );

	m_pPlayer->ammo_nails--;
	if ( m_pPlayer->ammo_nails < 0 )
		m_pPlayer->ammo_nails = 0;

	m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 );
	m_flTimeWeaponIdle = 10.0;
}

void CTFNailgun::SecondaryAttack( void )
{
}

void CTFNailgun::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle > 0 )
		return;

	m_flTimeWeaponIdle = 15.0;
	SendWeaponAnim( MP5_IDLE1, 1 );
}

void CTFSuperNailgun::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_nails <= 0 )
	{
		PlayEmptySound();
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = BRIGHT_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireSuperNailGun );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->pev->origin + m_pPlayer->pev->view_ofs + gpGlobals->v_right * 2 + gpGlobals->v_up * -4;

	// Low on ammo: fires ordinary nails
	if ( m_pPlayer->ammo_nails < 4 )
		CTFNailgunNail::CreateNail( FALSE, vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this, TRUE );
	else
		CTFNailgunNail::CreateSuperNail( vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this );

	DB_LogShots( 1 );

	m_pPlayer->ammo_nails -= 2;
	if ( m_pPlayer->ammo_nails < 0 )
		m_pPlayer->ammo_nails = 0;

	m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 );
	m_flTimeWeaponIdle = 10.0;
}

int CTFSuperNailgun::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "9mm";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_nails;
	else
		p->iAmmo1 = 150;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = 0;
	p->iSlot = 3;
	p->iPosition = 1;
	p->iId = m_iId = WEAPON_SUPER_NAILGUN;
	p->iFlags = 0;
	p->iWeight = 15;
	return 1;
}

void CTFSuperNailgun::Precache( void )
{
	CTFNailgun::Precache();
	m_usFireSuperNailGun = PRECACHE_EVENT( 1, "events/wpn/tf_snail.sc" );
}
