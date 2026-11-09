/***
*
*	Team Fortress Classic: Tranquiliser gun (Spy)
*
*	Reconstructed from tfc.so (legacy) / client.so (25th), DWARF-guided.
*	Built from the HL glock (same animation enum).
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

enum glock_e {
	GLOCK_IDLE1 = 0,
	GLOCK_IDLE2,
	GLOCK_IDLE3,
	GLOCK_SHOOT,
	GLOCK_SHOOT_EMPTY,
	GLOCK_RELOAD,
	GLOCK_RELOAD_NOT_EMPTY,
	GLOCK_DRAW,
	GLOCK_HOLSTER,
	GLOCK_ADD_SILENCER
};

LINK_ENTITY_TO_CLASS( tf_weapon_tranq, CTFTranq );

void CTFTranq::Spawn( void )
{
	pev->classname = MAKE_STRING( "tf_weapon_tranq" );
	Precache();
	m_iId = WEAPON_GLOCK;	// sic: HL leftover; GetItemInfo sets WEAPON_TRANQ
	m_iDefaultAmmo = GLOCK_DEFAULT_GIVE;

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFTranq::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_pistol.mdl" );
	PRECACHE_MODEL( "models/p_spygun.mdl" );
	PRECACHE_MODEL( "models/p_9mmhandgun2.mdl" );

	PRECACHE_SOUND( "weapons/dartgun.wav" );

	m_usFireTranquilizer = PRECACHE_EVENT( 1, "events/wpn/tf_tranq.sc" );
}

int CTFTranq::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "buckshot";
	if ( m_pPlayer )
		p->iAmmo1 = m_pPlayer->maxammo_shells;
	else
		p->iAmmo1 = 40;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 1;
	p->iPosition = 4;
	p->iFlags = 0;
	p->iId = m_iId = WEAPON_TRANQ;
	p->iWeight = 10;
	return 1;
}

BOOL CTFTranq::Deploy( void )
{
	pev->body = 1;

	BOOL bResult = DefaultDeploy( "models/v_tfc_pistol.mdl", "models/p_spygun.mdl", GLOCK_DRAW, "onehanded", 1 );
	if ( bResult )
		SendWeaponAnim( GLOCK_DRAW, 0 );

	return bResult;
}

void CTFTranq::PrimaryAttack( void )
{
	if ( m_pPlayer->ammo_shells <= 0 )
	{
		PlayEmptySound();
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.2 );
		return;
	}

	m_pPlayer->m_iWeaponVolume = NORMAL_GUN_VOLUME;
	m_pPlayer->m_iWeaponFlash = NORMAL_GUN_FLASH;

	PLAYBACK_EVENT( FEV_NOTHOST, m_pPlayer->edict(), m_usFireTranquilizer );

	m_pPlayer->pev->effects |= EF_MUZZLEFLASH;
	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );

	CTFNailgunNail::CreateTranqNail( m_pPlayer->GetGunPosition(), m_pPlayer->pev->v_angle, m_pPlayer, this );
	DB_LogShots( 1 );

	m_pPlayer->ammo_shells--;

	m_flNextPrimaryAttack = GetNextAttackDelay( 1.5 );
	m_flTimeWeaponIdle = 12.5;
}

void CTFTranq::Reload( void )
{
}

void CTFTranq::WeaponIdle( void )
{
	ResetEmptySound();

	if ( m_flTimeWeaponIdle > 0 )
		return;

	int iAnim;
	int i = UTIL_SharedRandomLong( m_pPlayer->random_seed, 0, 3 );

	if ( i % 3 == 0 )
	{
		iAnim = GLOCK_IDLE3;
		m_flTimeWeaponIdle = 49.0 / 16;
	}
	else if ( ( i + 1 ) % 3 == 0 )
	{
		iAnim = GLOCK_IDLE1;
		m_flTimeWeaponIdle = 60.0 / 16;
	}
	else
	{
		iAnim = GLOCK_IDLE2;
		m_flTimeWeaponIdle = 40.0 / 16;
	}

	SendWeaponAnim( iAnim, 1 );
}

//=========================================================
// Tranquiliser dart hit
//=========================================================
void CTFNailgunNail::TranqTouch( CBaseEntity *pOther )
{
	if ( pOther->pev->takedamage )
	{
		CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

		if ( pOther->Classify() == CLASS_PLAYER &&
			( !pOwner->IsAlly( pOther ) || !( (int)gpGlobals->teamplay & TEAMPLAY_TEAMDAMAGE ) ) )
		{
			if ( !( pOther->tfstate & TFSTATE_TRANQUILISED ) )
			{
				ClientPrint( pOther->pev, HUD_PRINTNOTIFY, "#Spy_tranq" );
				pOther->tfstate |= TFSTATE_TRANQUILISED;

#ifndef CLIENT_DLL
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Spy_Tranq\" against \"%s<%i><%s><%s>\"\n",
					STRING( pOwner->pev->netname ),
					GETPLAYERUSERID( pOwner->edict() ),
					GETPLAYERAUTHID( pOwner->edict() ),
					pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR",
					STRING( pOther->pev->netname ),
					GETPLAYERUSERID( pOther->edict() ),
					GETPLAYERAUTHID( pOther->edict() ),
					pOther->team_no ? GetTeamName( pOther->team_no ) : "SPECTATOR" );
#endif

				CBaseEntity *pTimer = pOther->CreateTimer( TF_TIMER_TRANQUILISATION );
				pTimer->pev->nextthink = gpGlobals->time + 15;
				pTimer->SetThink( &CBaseEntity::Timer_Tranquilisation );
				pTimer->team_no = pOwner->team_no;

				((CBasePlayer *)pOther)->TeamFortress_SetSpeed();
			}
			else
			{
				// Already tranquilised: restart the timer
				CBaseEntity *pTimer = pOther->FindTimer( TF_TIMER_TRANQUILISATION );
				if ( pTimer )
					pTimer->pev->nextthink = gpGlobals->time + 15;
			}
		}

		pOther->TakeDamage( pev, pOwner->pev, 20, DMG_TRANQ | DMG_NAIL );
	}

	SUB_Remove();
}
