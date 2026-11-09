/***
*
*	Team Fortress Classic: Shotgun and Super (double barrel) shotgun
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	Built from the HL shotgun (same animation enum).
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

enum shotgun_e {
	SHOTGUN_IDLE = 0,
	SHOTGUN_FIRE,
	SHOTGUN_FIRE2,
	SHOTGUN_RELOAD,
	SHOTGUN_PUMP,
	SHOTGUN_START_RELOAD,
	SHOTGUN_DRAW,
	SHOTGUN_HOLSTER,
	SHOTGUN_IDLE4,
	SHOTGUN_IDLE_DEEP
};

#define TF_SHOTGUN_SPREAD	Vector( 0.04, 0.04, 0 )

LINK_ENTITY_TO_CLASS( tf_weapon_shotgun, CTFShotgun );
LINK_ENTITY_TO_CLASS( tf_weapon_supershotgun, CTFSuperShotgun );

void CTFShotgun::Spawn( void )
{
	Precache();
	m_iId = WEAPON_TF_SHOTGUN;
	current_ammo = NULL;
	m_iDefaultAmmo = 8;
	m_iMaxClipSize = 8;
	m_iShellsReloaded = 1;
	m_fReloadTime = 0.25;
	m_flPumpTime = 1000;	// no pump pending

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFShotgun::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_12gauge.mdl" );
	PRECACHE_MODEL( "models/p_smallshotgun.mdl" );
	PRECACHE_MODEL( "models/p_shotgun2.mdl" );

	m_iShell = PRECACHE_MODEL( "models/shotgunshell.mdl" );

	PRECACHE_SOUND( "weapons/dbarrel1.wav" );
	PRECACHE_SOUND( "weapons/sbarrel1.wav" );
	PRECACHE_SOUND( "weapons/reload1.wav" );
	PRECACHE_SOUND( "weapons/reload3.wav" );
	PRECACHE_SOUND( "weapons/357_cock1.wav" );
	PRECACHE_SOUND( "weapons/scock1.wav" );
	PRECACHE_SOUND( "weapons/shotgn2.wav" );

	m_usFireShotgun = PRECACHE_EVENT( 1, "events/wpn/tf_sg.sc" );
	m_usReloadShotgun = PRECACHE_EVENT( 1, "events/wpn/tf_sgreload.sc" );
	m_usPumpShotgun = PRECACHE_EVENT( 1, "events/wpn/tf_sgpump.sc" );
}

int CTFShotgun::AddToPlayer( CBasePlayer *pPlayer )
{
	if ( CBasePlayerWeapon::AddToPlayer( pPlayer ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgWeapPickup, NULL, pPlayer->pev );
			WRITE_BYTE( m_iId );
		MESSAGE_END();

		current_ammo = &m_pPlayer->ammo_shells;
		return TRUE;
	}
	return FALSE;
}

int CTFShotgun::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "buckshot";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_shells;
	else
		p->iAmmo1 = 200;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iSlot = 1;
	p->iPosition = 3;
	p->iFlags = 0;
	p->iMaxClip = m_iMaxClipSize;
	p->iId = m_iId = WEAPON_TF_SHOTGUN;
	p->iWeight = 15;
	return 1;
}

BOOL CTFShotgun::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_12gauge.mdl", "models/p_smallshotgun.mdl", SHOTGUN_DRAW, "shotgun", 1 );
}

void CTFShotgun::PrimaryAttack( void )
{
	if ( m_iClip <= 0 )
	{
		Reload();
		if ( m_iClip == 0 )
			PlayEmptySound();
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = NORMAL_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireShotgun );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );

	Vector vecSrc = m_pPlayer->GetGunPosition();
	Vector vecAiming = m_pPlayer->GetAutoaimVector( AUTOAIM_5DEGREES );

	m_pPlayer->FireBullets( 6, vecSrc, vecAiming, TF_SHOTGUN_SPREAD, 2048, BULLET_PLAYER_TF_BUCKSHOT, 0, 4, NULL );
	DB_LogShots( 1 );

	if ( !m_iClip && m_pPlayer->ammo_shells <= 0 )
		m_pPlayer->SetSuitUpdate( "!HEV_AMO0", FALSE, 0 );

	m_iClip--;
	m_pPlayer->pev->effects |= EF_MUZZLEFLASH;

	m_fInSpecialReload = 0;
	m_flTimeWeaponIdle = 5.0;
	m_pPlayer->tfstate &= ~TFSTATE_RELOADING;

	m_flPumpTime = 0.5;
	m_flNextPrimaryAttack = GetNextAttackDelay( 0.5 );
}

void CTFShotgun::SecondaryAttack( void )
{
}

// Shells load m_iShellsReloaded at a time
void CTFShotgun::Reload( void )
{
	if ( m_pPlayer->ammo_shells < m_iShellsReloaded || m_iClip == m_iMaxClipSize )
		return;

	if ( m_flNextReload > 0 || m_flNextPrimaryAttack > 0 )
		return;

	if ( m_fInSpecialReload == 0 )
	{
		// start reload
		SendWeaponAnim( SHOTGUN_START_RELOAD, 1 );
		m_pPlayer->tfstate |= TFSTATE_RELOADING;
		m_fInSpecialReload = 1;
		m_pPlayer->m_flNextAttack = 0.1;
		m_flTimeWeaponIdle = 0.1;
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 );
		m_flNextSecondaryAttack = 0.1;
	}
	else if ( m_fInSpecialReload == 1 )
	{
		if ( m_flTimeWeaponIdle > 0 )
			return;

		// load
		m_fInSpecialReload = 2;
		PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usReloadShotgun );
		m_flNextReload = m_fReloadTime;
		m_flTimeWeaponIdle = m_fReloadTime;
	}
	else
	{
		m_iClip += m_iShellsReloaded;
		m_pPlayer->ammo_shells -= m_iShellsReloaded;
		m_fInSpecialReload = 1;
		m_pPlayer->tfstate &= ~TFSTATE_RELOADING;
	}
}

void CTFShotgun::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle >= 0 )
		return;

	if ( m_iClip == 0 && m_fInSpecialReload == 0 && m_pPlayer->ammo_shells >= m_iShellsReloaded )
	{
		Reload();
	}
	else if ( m_fInSpecialReload != 0 )
	{
		if ( m_iClip != m_iMaxClipSize && m_pPlayer->ammo_shells >= m_iShellsReloaded )
		{
			Reload();
		}
		else
		{
			// reload finished: pump
			PLAYBACK_EVENT_FULL( FEV_NOTHOST, m_pPlayer->edict(), m_usPumpShotgun, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 1, 0 );
			m_fInSpecialReload = 0;
			m_flTimeWeaponIdle = 1.5;
		}
	}
	else
	{
		int iAnim;
		int iRand = UTIL_SharedRandomLong( m_pPlayer->random_seed, 0, 20 );

		if ( iRand % 5 == 0 )
		{
			if ( iRand % 20 == 0 )
			{
				iAnim = SHOTGUN_IDLE;
				m_flTimeWeaponIdle = 20.0 / 9.0;
			}
			else
			{
				iAnim = SHOTGUN_IDLE4;
				m_flTimeWeaponIdle = 20.0 / 9.5;
			}
		}
		else
		{
			iAnim = SHOTGUN_IDLE_DEEP;
			m_flTimeWeaponIdle = 5.0;
		}

		SendWeaponAnim( iAnim, 1 );
	}
}

// Pump half a second after firing
void CTFShotgun::ItemPostFrame( void )
{
	if ( m_flPumpTime != 1000 && m_flPumpTime < 0 )
	{
		PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usPumpShotgun );
		m_flPumpTime = 1000;
	}

	CBasePlayerWeapon::ItemPostFrame();
}

//=========================================================
// Super shotgun
//=========================================================
void CTFSuperShotgun::Spawn( void )
{
	Precache();
	m_iId = WEAPON_TF_SHOTGUN;	// GetItemInfo sets WEAPON_SUPER_SHOTGUN
	current_ammo = NULL;
	m_flPumpTime = 1000;

	pev->solid = SOLID_TRIGGER;

	m_iDefaultAmmo = 16;
	m_iMaxClipSize = 16;

	SetTouch( &CBasePlayerItem::DefaultTouch );

	m_fReloadTime = 0.375;
	m_iShellsReloaded = 2;
}

void CTFSuperShotgun::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_shotgun.mdl" );
	PRECACHE_MODEL( "models/p_shotgun.mdl" );
	PRECACHE_MODEL( "models/p_shotgun2.mdl" );

	m_iShell = PRECACHE_MODEL( "models/shotgunshell.mdl" );

	PRECACHE_SOUND( "weapons/dbarrel1.wav" );
	PRECACHE_SOUND( "weapons/sbarrel1.wav" );
	PRECACHE_SOUND( "weapons/reload1.wav" );
	PRECACHE_SOUND( "weapons/reload3.wav" );
	PRECACHE_SOUND( "weapons/357_cock1.wav" );
	PRECACHE_SOUND( "weapons/scock1.wav" );
	PRECACHE_SOUND( "weapons/shotgn2.wav" );

	m_usFireSuperShotgun = PRECACHE_EVENT( 1, "events/wpn/tf_ssg.sc" );
	m_usReloadShotgun = PRECACHE_EVENT( 1, "events/wpn/tf_sgreload.sc" );
	m_usPumpShotgun = PRECACHE_EVENT( 1, "events/wpn/tf_sgpump.sc" );
}

int CTFSuperShotgun::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "buckshot";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_shells;
	else
		p->iAmmo1 = 200;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iSlot = 2;
	p->iPosition = 2;
	p->iFlags = 0;
	p->iMaxClip = m_iMaxClipSize;
	p->iId = m_iId = WEAPON_SUPER_SHOTGUN;
	p->iWeight = 15;
	return 1;
}

void CTFSuperShotgun::PrimaryAttack( void )
{
	if ( m_iClip <= 0 )
	{
		Reload();
		if ( m_iClip == 0 )
			PlayEmptySound();
		return;
	}

	// One shell left: fires as a single barrel shotgun
	if ( m_iClip == 1 )
	{
		CTFShotgun::PrimaryAttack();
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = NORMAL_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireSuperShotgun );

	m_pPlayer->pev->effects |= EF_MUZZLEFLASH;
	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );

	Vector vecSrc = m_pPlayer->GetGunPosition();
	Vector vecAiming = m_pPlayer->GetAutoaimVector( AUTOAIM_5DEGREES );

	m_pPlayer->FireBullets( 14, vecSrc, vecAiming, TF_SHOTGUN_SPREAD, 2048, BULLET_PLAYER_TF_BUCKSHOT, 0, 4, NULL );
	DB_LogShots( 1 );

	if ( !m_iClip && m_pPlayer->ammo_shells <= 0 )
		m_pPlayer->SetSuitUpdate( "!HEV_AMO0", FALSE, 0 );

	m_iClip -= 2;

	m_fInSpecialReload = 0;
	m_flTimeWeaponIdle = 5.0;

	m_flPumpTime = 0.7;
	m_flNextPrimaryAttack = GetNextAttackDelay( 0.7 );
}

BOOL CTFSuperShotgun::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_shotgun.mdl", "models/p_shotgun.mdl", SHOTGUN_DRAW, "shotgun", 1 );
}
