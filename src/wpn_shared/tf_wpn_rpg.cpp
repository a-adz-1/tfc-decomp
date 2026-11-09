/***
*
*	Team Fortress Classic: Rocket launcher (Soldier)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	The rocket itself (CTFRpgRocket) is implemented in tf_wpn_nails.cpp.
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
	RPG_FIRE,
	RPG_HOLSTER,
	RPG_DRAW,
	RPG_HOLSTER_UL,
	RPG_DRAW_UL,
	RPG_RELOAD_START,
	RPG_RELOAD,
	RPG_RELOAD_END,
	RPG_IDLE_UL,
	RPG_FIDGET_UL,
};

#define TF_RPG_MAX_CLIP		4

LINK_ENTITY_TO_CLASS( tf_weapon_rpg, CTFRpg );
LINK_ENTITY_TO_CLASS( tf_rpg_rocket, CTFRpgRocket );

// Rockets load one at a time, like the HL shotgun
void CTFRpg::Reload( void )
{
	if ( m_pPlayer->ammo_rockets == 0 || m_iClip == TF_RPG_MAX_CLIP )
		return;

	if ( m_flNextReload > 0 || m_flNextPrimaryAttack > 0 )
		return;

	if ( m_fInSpecialReload == 0 )
	{
		// start reload
		SendWeaponAnim( RPG_RELOAD_START, 1 );
		m_pPlayer->tfstate |= TFSTATE_RELOADING;
		m_fInSpecialReload = 1;
		m_pPlayer->m_flNextAttack = 0.1;
		m_flTimeWeaponIdle = 0.1;
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 );
		m_flNextSecondaryAttack = 0.1;
	}
	else if ( m_fInSpecialReload == 1 )
	{
		if ( m_flTimeWeaponIdle > gpGlobals->time )
			return;

		// load one rocket
		m_fInSpecialReload = 2;
		SendWeaponAnim( RPG_RELOAD, 1 );
		m_flNextReload = m_fReloadTime;
		m_flTimeWeaponIdle = m_fReloadTime;
	}
	else
	{
		m_iClip++;
		m_pPlayer->ammo_rockets--;
		m_fInSpecialReload = 1;
		m_pPlayer->tfstate &= ~TFSTATE_RELOADING;
	}
}

void CTFRpg::Spawn( void )
{
	current_ammo = NULL;
	Precache();
	m_iId = WEAPON_RPG;		// sic: HL leftover; GetItemInfo sets WEAPON_ROCKET_LAUNCHER
	SET_MODEL( ENT( pev ), "models/w_rpg.mdl" );
	m_iDefaultAmmo = 50;
	m_fReloadTime = 1.25;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFRpg::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_rpg.mdl" );
	PRECACHE_MODEL( "models/p_srpg.mdl" );
	PRECACHE_MODEL( "models/p_rpg2.mdl" );

	PRECACHE_SOUND( "items/9mmclip1.wav" );

	UTIL_PrecacheOther( "tf_rpg_rocket" );

	PRECACHE_SOUND( "weapons/rocketfire1.wav" );
	PRECACHE_SOUND( "weapons/glauncher.wav" );

	m_usFireRPG = PRECACHE_EVENT( 1, "events/wpn/tf_rpg.sc" );
}

int CTFRpg::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "rockets";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_rockets;
	else
		p->iAmmo1 = 50;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = TF_RPG_MAX_CLIP;
	p->iSlot = 4;
	p->iPosition = 1;
	p->iId = m_iId = WEAPON_ROCKET_LAUNCHER;
	p->iFlags = 0;
	p->iWeight = 20;
	return 1;
}

int CTFRpg::AddToPlayer( CBasePlayer *pPlayer )
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

BOOL CTFRpg::Deploy( void )
{
	if ( m_iClip )
		return DefaultDeploy( "models/v_tfc_rpg.mdl", "models/p_srpg.mdl", RPG_DRAW, "rpg", 1 );

	return DefaultDeploy( "models/v_tfc_rpg.mdl", "models/p_srpg.mdl", RPG_DRAW_UL, "rpg", 1 );
}

BOOL CTFRpg::CanHolster( void )
{
	return TRUE;
}

void CTFRpg::Holster( int skiplocal )
{
	m_pPlayer->tfstate &= ~TFSTATE_RELOADING;
	m_fInSpecialReload = 0;
	m_pPlayer->m_flNextAttack = 0.5;
	SendWeaponAnim( RPG_HOLSTER, 1 );
}

void CTFRpg::PrimaryAttack( void )
{
	if ( !m_iClip )
	{
		PlayEmptySound();
		Reload();
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = BRIGHT_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireRPG );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->GetGunPosition() + gpGlobals->v_forward * 16 + gpGlobals->v_right * 8 + gpGlobals->v_up * -8;

	CTFRpgRocket::CreateRpgRocket( vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this );
	DB_LogShots( 1 );

	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	// Firing cancels a reload in progress
	m_fInSpecialReload = 0;
	m_pPlayer->tfstate &= ~TFSTATE_RELOADING;

	m_iClip--;

	m_flNextPrimaryAttack = GetNextAttackDelay( 0.8 );
	m_flTimeWeaponIdle = 0.8;
	ResetEmptySound();
}

void CTFRpg::SecondaryAttack( void )
{
}

void CTFRpg::WeaponIdle( void )
{
	if ( m_flTimeWeaponIdle > 0 )
		return;

	if ( m_iClip == 0 && m_fInSpecialReload == 0 && m_pPlayer->ammo_rockets > 0 )
	{
		// empty: start reloading on its own
		Reload();
	}
	else if ( m_fInSpecialReload != 0 )
	{
		if ( m_iClip != TF_RPG_MAX_CLIP && m_pPlayer->ammo_rockets > 0 )
		{
			Reload();
		}
		else
		{
			// reload finished
			SendWeaponAnim( RPG_RELOAD_END, 1 );
			m_fInSpecialReload = 0;
			m_flTimeWeaponIdle = 1.5;
		}
	}
	else
	{
		if ( m_pPlayer->current_ammo )
		{
			m_flTimeWeaponIdle = 3.0;
			ResetEmptySound();
			SendWeaponAnim( m_iClip ? RPG_FIDGET : RPG_FIDGET_UL, 1 );
		}
		else
		{
			m_flTimeWeaponIdle = 1.0;
		}
	}
}
