/***
*
*	Team Fortress Classic: Sniper rifle (Sniper)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*
*	Hold fire to aim (only when nearly still): damage charges from 50 up to
*	400 and a laser dot shows where you are aiming. Release to fire; you must
*	be on the ground.
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

LINK_ENTITY_TO_CLASS( tf_weapon_sniperrifle, CTFSniperRifle );

void CTFSniperRifle::Spawn( void )
{
	m_fAimedDamage = 0;
	Precache();
	m_iId = WEAPON_CROSSBOW;	// sic: HL leftover; GetItemInfo sets WEAPON_SNIPER_RIFLE
	m_iDefaultAmmo = CROSSBOW_DEFAULT_GIVE;
	m_fNextAimBonus = -1;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

int CTFSniperRifle::AddToPlayer( CBasePlayer *pPlayer )
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

void CTFSniperRifle::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_sniper.mdl" );
	PRECACHE_MODEL( "models/p_sniper.mdl" );
	PRECACHE_MODEL( "models/p_sniper2.mdl" );

	PRECACHE_SOUND( "ambience/rifle1.wav" );

	m_usFireSniper = PRECACHE_EVENT( 1, "events/wpn/tf_sniper.sc" );
	m_usSniperHit = PRECACHE_EVENT( 1, "events/wpn/tf_sniperhit.sc" );
}

int CTFSniperRifle::GetItemInfo( ItemInfo *p )
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
	p->iSlot = 1;
	p->iPosition = 1;
	p->iId = m_iId = WEAPON_SNIPER_RIFLE;
	p->iFlags = 0;
	p->iWeight = 10;
	return 1;
}

BOOL CTFSniperRifle::Deploy( void )
{
	if ( DefaultDeploy( "models/v_tfc_sniper.mdl", "models/p_sniper.mdl", SRIFLE_DRAW, "autosniper", 1 ) )
	{
		m_pSpot = NULL;
		m_flTimeWeaponIdle = 0.5;
		m_fAimedDamage = 0;
		m_iSpotActive = 0;
		return TRUE;
	}
	return FALSE;
}

void CTFSniperRifle::Holster( int skiplocal )
{
	m_fInReload = FALSE;

	if ( m_fInZoom )
		SecondaryAttack();	// unzoom

	m_pPlayer->tfstate &= ~TFSTATE_AIMING;
	m_pPlayer->TeamFortress_SetSpeed();

	if ( m_pSpot )
	{
		m_pSpot->Killed( NULL, NULL, GIB_NEVER );
		m_pSpot = NULL;
	}

	m_fAimedDamage = 0;
	m_pPlayer->m_flNextAttack = 0.5;
	SendWeaponAnim( SRIFLE_HOLSTER, 1 );
}

// Move the laser dot to where the player is aiming
void CTFSniperRifle::UpdateSpot( void )
{
	if ( !m_iSpotActive )
		return;

	if ( !m_pSpot )
	{
		m_pSpot = CLaserSpot::CreateSpot();
		m_pSpot->pev->flags |= FL_SKIPLOCALHOST;
		m_pSpot->pev->owner = m_pPlayer->edict();
	}

	UTIL_MakeVectors( m_pPlayer->pev->v_angle );
	Vector vecSrc = m_pPlayer->GetGunPosition();
	Vector vecEnd = vecSrc + gpGlobals->v_forward * 8192;

	TraceResult tr;
	UTIL_TraceLine( vecSrc, vecEnd, dont_ignore_monsters, m_pPlayer->edict(), &tr );

	UTIL_SetOrigin( m_pSpot->pev, tr.vecEndPos );

	// brighter as the shot charges
	m_pSpot->pev->renderamt = m_fAimedDamage * 0.25 + 150;
}

void CTFSniperRifle::ItemPostFrame( void )
{
	ItemInfo info;
	GetItemInfo( &info );

	if ( ( m_pPlayer->pev->button & IN_ATTACK2 ) && m_flNextSecondaryAttack <= 0 )
	{
		if ( info.pszAmmo2 && !m_pPlayer->m_rgAmmo[ SecondaryAmmoIndex() ] )
			m_fFireOnEmpty = TRUE;

		SecondaryAttack();
		m_pPlayer->pev->button &= ~IN_ATTACK2;
	}
	else if ( ( m_pPlayer->m_afButtonReleased & IN_ATTACK ) && m_flNextPrimaryAttack <= 0 )
	{
		// Released fire: shoot if we were aiming
		if ( m_pPlayer->tfstate & TFSTATE_AIMING )
		{
			m_pPlayer->tfstate &= ~TFSTATE_AIMING;
			m_pPlayer->TeamFortress_SetSpeed();

			if ( m_pPlayer->pev->flags & FL_ONGROUND )
				PrimaryAttack();
			else
				ClientPrint( m_pPlayer->pev, HUD_PRINTCENTER, "#Sniper_cantfire" );

			m_iSpotActive = 0;
			if ( m_pSpot )
				m_pSpot->Killed( NULL, NULL, GIB_NEVER );
			m_pSpot = NULL;
			m_fAimedDamage = 0;
		}
	}
	else if ( ( m_pPlayer->pev->button & IN_ATTACK ) && m_flNextPrimaryAttack <= 0 )
	{
		if ( !( m_pPlayer->tfstate & TFSTATE_AIMING ) )
		{
			// Start aiming, only if (almost) standing still
			if ( m_pPlayer->pev->velocity.Length2D() <= 50 )
			{
				m_iSpotActive = 1;
				m_fAimedDamage = 50;
				m_fNextAimBonus = 0;
				m_pPlayer->tfstate |= TFSTATE_AIMING;
				m_pPlayer->TeamFortress_SetSpeed();
				SendWeaponAnim( SRIFLE_AIM, 1 );
				m_flTimeWeaponIdle = 1000;
			}
		}
		else
		{
			// Charging: m_fNextAimBonus counts down from 0 with the weapon
			// timers, so this adds 50 damage per second up to 400
			m_iSpotActive = 1;
			if ( m_fAimedDamage < 400 )
			{
				m_fAimedDamage = m_fAimedDamage + -m_fNextAimBonus * 50;
				m_fNextAimBonus = 0;
			}
			UpdateSpot();
		}
	}
	else if ( !( m_pPlayer->pev->button & ( IN_ATTACK | IN_ATTACK2 ) ) )
	{
		// no fire buttons down
		m_fFireOnEmpty = FALSE;

		if ( !IsUseable() && m_flNextPrimaryAttack < 0 )
		{
			// weapon isn't useable, switch.
			if ( !( info.iFlags & ITEM_FLAG_NOAUTOSWITCHEMPTY ) && UTIL_GetNextBestWeapon( m_pPlayer, this ) )
			{
				m_flNextPrimaryAttack = GetNextAttackDelay( 0.3 );
				return;
			}
		}
		else
		{
			// weapon is useable. Reload if empty and weapon has waited as long as it has to after firing
			if ( m_iClip == 0 && !( info.iFlags & ITEM_FLAG_NOAUTORELOAD ) && m_flNextPrimaryAttack < 0 )
			{
				Reload();
				return;
			}
		}

		WeaponIdle();
		return;
	}

	// catch all
	if ( ShouldWeaponIdle() )
		WeaponIdle();
}

void CTFSniperRifle::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_shells < 1 )
	{
		PlayEmptySound();
		return;
	}

	m_pPlayer->m_iWeaponVolume = QUIET_GUN_VOLUME;

	PLAYBACK_EVENT_FULL( FEV_NOTHOST, m_pPlayer->edict(), m_usFireSniper, 0.0,
		(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, (int)m_fAimedDamage, 0, 0, 0 );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
	m_flTimeWeaponIdle = 0.5;

	UTIL_MakeVectors( m_pPlayer->pev->v_angle + m_pPlayer->pev->punchangle );

	Vector vecSrc = m_pPlayer->GetGunPosition() - gpGlobals->v_up * 2;
	Vector vecEnd = vecSrc + gpGlobals->v_forward * 8192;

	TraceResult tr;
	UTIL_TraceLine( vecSrc, vecEnd, dont_ignore_monsters, m_pPlayer->edict(), &tr );

	// Hit sound: volume (iparam1), hit (bparam1), gibbed (bparam2)
	int iVolume, bHit, bGibbed;

	if ( tr.flFraction == 1.0 )
	{
		iVolume = 25;
		bHit = 0;
		bGibbed = 0;
	}
	else
	{
		CBaseEntity *pHit = CBaseEntity::Instance( tr.pHit );
		if ( !pHit )
			goto done;

		string_t iSavedDeathType = deathtype;

		ClearMultiDamage();
		pHit->TraceAttack( m_pPlayer->pev, m_fAimedDamage, gpGlobals->v_forward, &tr, DMG_BULLET | DMG_AIMED );

		// Headshot etc. set by TraceAttack
		if ( m_pPlayer->deathtype )
			deathtype = m_pPlayer->deathtype;

		ApplyMultiDamage( pev, m_pPlayer->pev );

		deathtype = iSavedDeathType;
		m_pPlayer->deathtype = 0;

		BOOL bPlayer = FClassnameIs( pHit->pev, "player" );

		// Louder the closer the hit
		iVolume = bPlayer ? 85 : 60;
		int iMaxVolume = bPlayer ? 100 : 90;
		float flDist = ( tr.vecEndPos - vecSrc ).Length();
		if ( flDist <= 1024 )
		{
			iVolume = (int)( iVolume + ( 1 - flDist / 1024 ) * ( bPlayer ? 15 : 30 ) );
			if ( iVolume > iMaxVolume )
				iVolume = iMaxVolume;
		}

		if ( !bPlayer )
		{
			PLAYBACK_EVENT_FULL( FEV_GLOBAL | FEV_HOSTONLY | FEV_SERVER, m_pPlayer->edict(), m_usSniperHit, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, iVolume, 0, 0, 0 );
		}

		bGibbed = pHit->pev->health < -40;
		if ( bGibbed )
			iVolume = 0;

		bHit = 1;
	}

	PLAYBACK_EVENT_FULL( FEV_HOSTONLY | FEV_SERVER, m_pPlayer->edict(), m_usSniperHit, 0.0,
		(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, iVolume, 0, bHit, bGibbed );

done:
	m_pPlayer->ammo_shells--;
	DB_LogShots( 1 );

	m_flNextPrimaryAttack = GetNextAttackDelay( 1.5 );
}

// Zoom toggle
void CTFSniperRifle::SecondaryAttack( void )
{
	if ( !m_fInZoom )
	{
		m_pPlayer->m_iFOV = 20;
		m_pPlayer->pev->fov = 20;
		m_fInZoom = TRUE;
	}
	else
	{
		m_pPlayer->m_iFOV = 0;
		m_pPlayer->pev->fov = 0;
		m_fInZoom = FALSE;
	}

	pev->nextthink = gpGlobals->time + 0.1;
	m_flNextSecondaryAttack = 0.3;
}

void CTFSniperRifle::Reload( void )
{
}

void CTFSniperRifle::WeaponIdle( void )
{
	UpdateSpot();
	ResetEmptySound();

	if ( m_flTimeWeaponIdle < 0 && !( m_pPlayer->tfstate & TFSTATE_AIMING ) )
	{
		SendWeaponAnim( SRIFLE_IDLE, 1 );
		m_flTimeWeaponIdle = 12.5;
	}
}
