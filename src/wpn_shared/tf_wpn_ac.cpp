/***
*
*	Team Fortress Classic: Assault cannon (Heavy Weapons Guy)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
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

enum ac_e {
	AC_IDLE1 = 0,
	AC_IDLE2,
	AC_SPINUP,
	AC_SPINDOWN,
	AC_FIRE,
	AC_DEPLOY,
	AC_HOLSTER,
};

// m_iWeaponState values (names not in DWARF; values from the code)
#define AC_STATE_IDLE		0
#define AC_STATE_WINDUP		1	// spinning up, can't fire yet
#define AC_STATE_FIRING		2
#define AC_STATE_SPINNING	3	// barrel spinning with no ammo

LINK_ENTITY_TO_CLASS( tf_weapon_ac, CTFAssaultC );

void CTFAssaultC::Spawn( void )
{
	pev->classname = MAKE_STRING( "tf_weapon_ac" );
	Precache();
	m_iId = WEAPON_MP5;		// sic: HL leftover; GetItemInfo sets WEAPON_ASSAULT_CANNON
	m_iDefaultAmmo = MP5_DEFAULT_GIVE;
	m_iWeaponState = AC_STATE_IDLE;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFAssaultC::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfac.mdl" );
	PRECACHE_MODEL( "models/p_mini.mdl" );
	PRECACHE_MODEL( "models/p_mini2.mdl" );

	m_iShell = PRECACHE_MODEL( "models/shell.mdl" );

	PRECACHE_SOUND( "weapons/357_cock1.wav" );
	PRECACHE_SOUND( "weapons/asscan1.wav" );
	PRECACHE_SOUND( "weapons/asscan2.wav" );
	PRECACHE_SOUND( "weapons/asscan3.wav" );
	PRECACHE_SOUND( "weapons/asscan4.wav" );

	m_usWindUp = PRECACHE_EVENT( 1, "events/wpn/tf_acwu.sc" );
	m_usWindDown = PRECACHE_EVENT( 1, "events/wpn/tf_acwd.sc" );
	m_usFire = PRECACHE_EVENT( 1, "events/wpn/tf_acfire.sc" );
	m_usStartSpin = PRECACHE_EVENT( 1, "events/wpn/tf_acsspin.sc" );
	m_usSpin = PRECACHE_EVENT( 1, "events/wpn/tf_acspin.sc" );
	m_usACStart = PRECACHE_EVENT( 1, "events/wpn/tf_acstart.sc" );
}

int CTFAssaultC::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "buckshot";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_shells;
	else
		p->iAmmo1 = 200;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 4;
	p->iPosition = 3;
	p->iFlags = 0;
	p->iId = m_iId = WEAPON_ASSAULT_CANNON;
	p->iWeight = 15;
	return 1;
}

int CTFAssaultC::AddToPlayer( CBasePlayer *pPlayer )
{
	if ( CBasePlayerWeapon::AddToPlayer( pPlayer ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgWeapPickup, NULL, pPlayer->pev );
			WRITE_BYTE( m_iId );
		MESSAGE_END();
		return TRUE;
	}
	return FALSE;
}

void CTFAssaultC::Holster( int skiplocal )
{
	WindDown( true );
	m_fInReload = FALSE;
	m_pPlayer->m_flNextAttack = 0.1;
	SendWeaponAnim( AC_HOLSTER, 1 );
}

BOOL CTFAssaultC::Deploy( void )
{
	return DefaultDeploy( "models/v_tfac.mdl", "models/p_mini.mdl", AC_DEPLOY, "ac", 1 );
}

void CTFAssaultC::Fire( void )
{
	if ( m_flNextPrimaryAttack > 0 )
		return;

	PLAYBACK_EVENT_FULL( FEV_NOTHOST | FEV_UPDATE, m_pPlayer->edict(), m_usFire, 0.0,
		(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, m_pPlayer->ammo_shells & 1, 0 );

	m_pPlayer->m_iWeaponVolume = NORMAL_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = NORMAL_GUN_FLASH;
	m_pPlayer->pev->effects |= EF_MUZZLEFLASH;
	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );

	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->pev->origin + m_pPlayer->pev->view_ofs + gpGlobals->v_right * 2 + gpGlobals->v_up * -4;
	Vector vecAiming = m_pPlayer->GetAutoaimVector( AUTOAIM_5DEGREES );

	m_pPlayer->FireBullets( 5, vecSrc, vecAiming, Vector( 0.1, 0.1, 0 ), 8192, BULLET_PLAYER_TF_ASSAULT, 8, 7, NULL );
	DB_LogShots( 1 );

	m_pPlayer->ammo_shells--;
}

void CTFAssaultC::StartSpin( void )
{
	PLAYBACK_EVENT_FULL( FEV_NOTHOST | FEV_RELIABLE | FEV_GLOBAL, m_pPlayer->edict(), m_usStartSpin, 0.0,
		(float *)&m_pPlayer->pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

	m_iWeaponState = AC_STATE_SPINNING;
	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	m_pPlayer->pev->effects &= ~EF_MUZZLEFLASH;
}

void CTFAssaultC::Spin( void )
{
	PLAYBACK_EVENT_FULL( FEV_NOTHOST | FEV_RELIABLE | FEV_GLOBAL, m_pPlayer->edict(), m_usSpin, 0.0,
		(float *)&m_pPlayer->pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
}

void CTFAssaultC::WindUp( void )
{
	if ( !( m_pPlayer->pev->button & IN_ATTACK ) )
		return;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usWindUp );

	m_iWeaponState = AC_STATE_WINDUP;
	m_pPlayer->tfstate |= TFSTATE_AIMING;	// slows the heavy down
	m_pPlayer->TeamFortress_SetSpeed();
}

void CTFAssaultC::WindDown( bool bFromHolster )
{
	PLAYBACK_EVENT_FULL( FEV_NOTHOST | FEV_RELIABLE | FEV_GLOBAL, m_pPlayer->edict(), m_usWindDown, 0.0,
		(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, bFromHolster, 0 );

	m_iWeaponState = AC_STATE_IDLE;
	m_pPlayer->tfstate &= ~TFSTATE_AIMING;
	m_pPlayer->TeamFortress_SetSpeed();
	m_flTimeWeaponIdle = 2.0;
}

void CTFAssaultC::PrimaryAttack( void )
{
	switch ( m_iWeaponState )
	{
	case AC_STATE_FIRING:
		if ( m_pPlayer->ammo_shells < 1 )
			StartSpin();
		else
			Fire();
		break;

	case AC_STATE_SPINNING:
		if ( m_pPlayer->ammo_shells < 1 )
			Spin();
		else
			m_iWeaponState = AC_STATE_WINDUP;	// got ammo again
		break;

	case AC_STATE_WINDUP:
		if ( m_flNextPrimaryAttack <= 0 )
		{
			PLAYBACK_EVENT_FULL( FEV_NOTHOST | FEV_RELIABLE | FEV_GLOBAL, m_pPlayer->edict(), m_usACStart, 0.0,
				(float *)&m_pPlayer->pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );
			m_iWeaponState = AC_STATE_FIRING;
		}
		return;

	default:
		WindUp();
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.5 );
		m_flTimeWeaponIdle = 0.6;
		return;
	}

	m_flTimeWeaponIdle = m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 );
}

void CTFAssaultC::Reload( void )
{
}

void CTFAssaultC::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle > 0 )
		return;

	if ( m_iWeaponState != AC_STATE_IDLE )
	{
		WindDown( false );
		return;
	}

	SendWeaponAnim( UTIL_SharedRandomLong( m_pPlayer->random_seed, 0, 1 ) ? AC_IDLE1 : AC_IDLE2, 1 );
	m_flTimeWeaponIdle = 12.5;
}
