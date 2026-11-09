/***
*
*	Team Fortress Classic: Grenade launcher and Pipebomb launcher (Demoman)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	Both share one view model and the player's m_iGLClip, so the clip
*	carries over when switching between them. The grenades are in
*	tf_wpn_grenades.cpp.
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

enum gl_e {
	GL_IDLE = 0,
	PL_IDLE,
	GL_FIRE,
	PL_FIRE,
	GL_RELOAD_DN,
	GL_RELOAD_UP,
	PL_RELOAD_DN,
	PL_RELOAD_UP,
	GL_DRAW,
	PL_DRAW,
	GL_HOLSTER,
	PL_HOLSTER,
};

#define TF_GL_MAX_CLIP		6

LINK_ENTITY_TO_CLASS( tf_weapon_gl, CTFGrenadeLauncher );
LINK_ENTITY_TO_CLASS( tf_weapon_pl, CTFPipebombLauncher );

void CTFGrenadeLauncher::Spawn( void )
{
	current_ammo = NULL;
	Precache();
	m_iId = WEAPON_MP5;		// sic: HL leftover; GetItemInfo sets WEAPON_GRENADE_LAUNCHER

	m_iAnim_Deploy = GL_DRAW;
	m_iAnim_Holster = GL_HOLSTER;
	m_iAnim_Idle = GL_IDLE;
	m_iAnim_ReloadDown = GL_RELOAD_DN;
	m_iAnim_ReloadUp = GL_RELOAD_UP;

	m_iDefaultAmmo = 50;
	m_fReloadTime = 0.6666667;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFGrenadeLauncher::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfgl.mdl" );
	PRECACHE_MODEL( "models/p_glauncher.mdl" );
	PRECACHE_MODEL( "models/p_glauncher2.mdl" );
	PRECACHE_MODEL( "models/pipebomb.mdl" );

	PRECACHE_SOUND( "items/9mmclip1.wav" );
	PRECACHE_SOUND( "items/clipinsert1.wav" );
	PRECACHE_SOUND( "items/cliprelease1.wav" );
	PRECACHE_SOUND( "weapons/hks1.wav" );
	PRECACHE_SOUND( "weapons/hks2.wav" );
	PRECACHE_SOUND( "weapons/hks3.wav" );
	PRECACHE_SOUND( "weapons/glauncher.wav" );
	PRECACHE_SOUND( "weapons/glauncher2.wav" );
	PRECACHE_SOUND( "weapons/357_cock1.wav" );

	m_usFireGL = PRECACHE_EVENT( 1, "events/wpn/tf_gl.sc" );
	PRECACHE_EVENT( 1, "events/wpn/tf_pipel.sc" );
}

int CTFGrenadeLauncher::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "rockets";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_rockets;
	else
		p->iAmmo1 = 50;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = TF_GL_MAX_CLIP;
	p->iSlot = 3;
	p->iPosition = 3;
	p->iId = m_iId = WEAPON_GRENADE_LAUNCHER;
	p->iFlags = 0;
	p->iWeight = 15;
	return 1;
}

int CTFGrenadeLauncher::AddToPlayer( CBasePlayer *pPlayer )
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

BOOL CTFGrenadeLauncher::Deploy( void )
{
	m_iClip = m_pPlayer->m_iGLClip;
	return DefaultDeploy( "models/v_tfgl.mdl", "models/p_glauncher.mdl", m_iAnim_Deploy, "mp5", 1 );
}

void CTFGrenadeLauncher::Holster( int skiplocal )
{
	m_pPlayer->m_iGLClip = m_iClip;
	m_pPlayer->tfstate &= ~TFSTATE_RELOADING;
	m_fInSpecialReload = 0;
	m_flTimeWeaponIdle = 1000;
	m_pPlayer->m_flNextAttack = 0.5;
	SendWeaponAnim( m_iAnim_Holster, 1 );
}

void CTFGrenadeLauncher::PrimaryAttack( void )
{
	if ( m_iClip == 0 )
	{
		SendWeaponAnim( m_iAnim_Idle, 1 );
		m_flNextPrimaryAttack = GetNextAttackDelay( 1.0 );
		PlayEmptySound();
		m_fInSpecialReload = 0;
		m_pPlayer->tfstate &= ~TFSTATE_RELOADING;
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = BRIGHT_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireGL );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->GetGunPosition() + gpGlobals->v_right * 8 + gpGlobals->v_up * -16;

	CTFGrenade::CreateTFGrenade( vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this );
	DB_LogShots( 1 );

	m_fInSpecialReload = 0;
	m_pPlayer->tfstate &= ~TFSTATE_RELOADING;

	m_flNextSecondaryAttack = 0.6;
	m_iClip--;
	m_flNextPrimaryAttack = 0.6;
	m_flTimeWeaponIdle = 0.6;
}

void CTFGrenadeLauncher::SecondaryAttack( void )
{
}

// Grenades load one at a time
void CTFGrenadeLauncher::Reload( void )
{
	if ( m_pPlayer->ammo_rockets == 0 || m_iClip == TF_GL_MAX_CLIP )
		return;

	if ( m_flNextReload > 0 || m_flNextPrimaryAttack > 0 )
		return;

	if ( m_fInSpecialReload == 0 )
	{
		m_fInSpecialReload = 1;
		m_pPlayer->tfstate |= TFSTATE_RELOADING;
		SendWeaponAnim( m_iAnim_ReloadDown, 1 );
		m_pPlayer->m_flNextAttack = 0.1;
		m_flTimeWeaponIdle = 0.1;
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.1 );
		m_flNextSecondaryAttack = 0.1;
	}
	else if ( m_fInSpecialReload == 1 )
	{
		if ( m_flTimeWeaponIdle > 0 )
			return;

		m_fInSpecialReload = 2;
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

void CTFGrenadeLauncher::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle > 0 )
		return;

	if ( m_iClip == 0 && m_fInSpecialReload == 0 && m_pPlayer->ammo_rockets > 0 )
	{
		Reload();
	}
	else if ( m_fInSpecialReload != 0 )
	{
		if ( m_iClip != TF_GL_MAX_CLIP && m_pPlayer->ammo_rockets > 0 )
		{
			Reload();
		}
		else
		{
			SendWeaponAnim( m_iAnim_ReloadUp, 1 );
			m_fInSpecialReload = 0;
			m_flTimeWeaponIdle = 1.5;
		}
	}
	else
	{
		m_flTimeWeaponIdle = 3.0;
		SendWeaponAnim( m_iAnim_Idle, 1 );
	}
}

//=========================================================
// Pipebomb launcher
//=========================================================
void CTFPipebombLauncher::Spawn( void )
{
	current_ammo = NULL;
	Precache();
	m_iId = WEAPON_MP5;		// sic: HL leftover; GetItemInfo sets WEAPON_PIPEBOMB_LAUNCHER
	m_iDefaultAmmo = 50;
	m_fReloadTime = 0.6666667;

	pev->solid = SOLID_TRIGGER;

	m_iAnim_Holster = PL_HOLSTER;
	m_iAnim_Idle = PL_IDLE;
	m_iAnim_ReloadDown = PL_RELOAD_DN;
	m_iAnim_ReloadUp = PL_RELOAD_UP;

	SetTouch( &CBasePlayerItem::DefaultTouch );
	m_iAnim_Deploy = PL_DRAW;

	m_usFireGL = PRECACHE_EVENT( 1, "events/wpn/tf_pipel.sc" );
}

void CTFPipebombLauncher::PrimaryAttack( void )
{
	if ( m_iClip == 0 )
	{
		// Unlike the grenade launcher, reloads straight away
		Reload();
		if ( m_pPlayer->ammo_rockets == 0 )
		{
			PlayEmptySound();
			SendWeaponAnim( m_iAnim_Idle, 1 );
			m_flNextPrimaryAttack = GetNextAttackDelay( 1.0 );
		}
		return;
	}

	m_pPlayer->m_iWeaponVolume = LOUD_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = BRIGHT_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireGL );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	UTIL_MakeVectors( m_pPlayer->pev->v_angle );

	Vector vecSrc = m_pPlayer->GetGunPosition() + gpGlobals->v_right * 8 + gpGlobals->v_up * -16;

	CTFGrenade::CreateTFPipebomb( vecSrc, m_pPlayer->pev->v_angle, m_pPlayer, this );
	DB_LogShots( 1 );

	m_fInSpecialReload = 0;
	m_pPlayer->tfstate &= ~TFSTATE_RELOADING;

	m_iClip--;
	m_flNextPrimaryAttack = GetNextAttackDelay( 0.6 );
	m_flTimeWeaponIdle = 0.6;
}

int CTFPipebombLauncher::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "rockets";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_rockets;
	else
		p->iAmmo1 = 50;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = TF_GL_MAX_CLIP;
	p->iSlot = 4;
	p->iPosition = 4;
	p->iId = m_iId = WEAPON_PIPEBOMB_LAUNCHER;
	p->iFlags = 0;
	p->iWeight = 15;
	return 1;
}
