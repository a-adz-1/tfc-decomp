/***
*
*	Team Fortress Classic: Auto Rifle (Sniper)
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

// Shared by the sniper rifle and auto rifle (same view model)
enum srifle_e {
	SRIFLE_IDLE = 0,
	SRIFLE_AIM,
	SRIFLE_FIRE,
	SRIFLE_DRAW,
	SRIFLE_HOLSTER,
	ARIFLE_IDLE,
	ARIFLE_FIRE,
	ARIFLE_DRAW,
	ARIFLE_HOLSTER,
};

LINK_ENTITY_TO_CLASS( tf_weapon_autorifle, CTFAutoRifle );

void CTFAutoRifle::Spawn( void )
{
	pev->classname = MAKE_STRING( "tf_weapon_autorifle" );
	Precache();
	m_iId = WEAPON_CROSSBOW;	// sic: HL leftover; GetItemInfo sets WEAPON_AUTO_RIFLE
	m_iDefaultAmmo = CROSSBOW_DEFAULT_GIVE;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

int CTFAutoRifle::AddToPlayer( CBasePlayer *pPlayer )
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

void CTFAutoRifle::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_sniper.mdl" );
	PRECACHE_MODEL( "models/p_sniper.mdl" );
	PRECACHE_MODEL( "models/p_sniper2.mdl" );

	PRECACHE_SOUND( "weapons/sniper.wav" );

	m_usFireAutoRifle = PRECACHE_EVENT( 1, "events/wpn/tf_ar.sc" );
}

int CTFAutoRifle::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "buckshot";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_shells;
	else
		p->iAmmo1 = 75;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 2;
	p->iPosition = 1;
	p->iId = m_iId = WEAPON_AUTO_RIFLE;
	p->iFlags = 0;
	p->iWeight = 10;
	return 1;
}

BOOL CTFAutoRifle::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_sniper.mdl", "models/p_sniper.mdl", ARIFLE_DRAW, "autosniper", 1 );
}

void CTFAutoRifle::Holster( int skiplocal )
{
	m_fInReload = FALSE;
	m_pPlayer->m_flNextAttack = 0.5;
	SendWeaponAnim( ARIFLE_HOLSTER, 1 );
}

void CTFAutoRifle::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_shells <= 0 )
	{
		m_flNextPrimaryAttack = GetNextAttackDelay( 5.0 );
		m_flTimeWeaponIdle = 1.0;
		SendWeaponAnim( SRIFLE_IDLE, 1 );
		PlayEmptySound();
		return;
	}

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireAutoRifle );

	m_pPlayer->m_iWeaponVolume = NORMAL_GUN_VOLUME;
	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	m_flTimeWeaponIdle = 0.2;

	UTIL_MakeVectors( m_pPlayer->pev->v_angle + m_pPlayer->pev->punchangle );

	Vector vecSrc = m_pPlayer->GetGunPosition() - gpGlobals->v_up * 2;
	Vector vecEnd = vecSrc + gpGlobals->v_forward * 8192;

	TraceResult tr;
	UTIL_TraceLine( vecSrc, vecEnd, dont_ignore_monsters, m_pPlayer->edict(), &tr );
	DB_LogShots( 1 );

	if ( tr.flFraction != 1.0 )
	{
		CBaseEntity *pHit = CBaseEntity::Instance( tr.pHit );
		if ( pHit )
		{
			ClearMultiDamage();
			pHit->TraceAttack( m_pPlayer->pev, 8, gpGlobals->v_forward, &tr, DMG_BULLET );
			ApplyMultiDamage( pev, m_pPlayer->pev );
		}
	}

	m_pPlayer->ammo_shells--;
	m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 );
}

void CTFAutoRifle::Reload( void )
{
}

void CTFAutoRifle::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle < 0 )
	{
		SendWeaponAnim( ARIFLE_IDLE, 1 );
		m_flTimeWeaponIdle = 12.5;
	}
}
