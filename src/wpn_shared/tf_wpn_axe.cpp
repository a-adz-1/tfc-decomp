/***
*
*	Team Fortress Classic: melee weapons (axe/umbrella, spanner, knife, medikit)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
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

extern void FindHullIntersection( const Vector &vecSrc, TraceResult &tr, float *mins, float *maxs, edict_t *pEntity );

#define	CROWBAR_BODYHIT_VOLUME 128
#define	CROWBAR_WALLHIT_VOLUME 512

enum crowbar_e {
	CROWBAR_IDLE = 0,
	CROWBAR_DRAW,
	CROWBAR_HOLSTER,
	CROWBAR_ATTACK1HIT,
	CROWBAR_ATTACK1MISS,
	CROWBAR_ATTACK2MISS,
	CROWBAR_ATTACK2HIT,
	CROWBAR_ATTACK3MISS,
	CROWBAR_ATTACK3HIT
};

enum spanner_e {
	SPANNER_IDLE = 0,
	SPANNER_ATTACK1,
	SPANNER_ATTACK2,
	SPANNER_USE,
	SPANNER_DRAW,
	SPANNER_HOLSTER
};

enum knife_e {
	KNIFE_IDLE1 = 0,
	KNIFE_IDLE2,
	KNIFE_ATTACK1,
	KNIFE_ATTACK2,
	KNIFE_DRAW,
	KNIFE_HOLSTER
};

enum medikit_e {
	MEDIKIT_IDLE1 = 0,
	MEDIKIT_IDLE2,
	MEDIKIT_USE_LONG,
	MEDIKIT_USE_SHORT,
	MEDIKIT_HOLSTER,
	MEDIKIT_DRAW
};

// PlayAnim types
#define ANIM_ATTACK_HIT		0
#define ANIM_ATTACK_MISS	1

LINK_ENTITY_TO_CLASS( tf_weapon_axe, CTFAxe );
LINK_ENTITY_TO_CLASS( tf_weapon_knife, CTFKnife );
LINK_ENTITY_TO_CLASS( tf_weapon_spanner, CTFSpanner );
LINK_ENTITY_TO_CLASS( tf_weapon_medikit, CTFMedikit );

//=========================================================
// Axe (civilians get the umbrella)
//=========================================================
void CTFAxe::Spawn( void )
{
	Precache();
	m_iId = WEAPON_AXE;
	m_iClip = -1;
	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
}

void CTFAxe::Precache( void )
{
	PRECACHE_MODEL( "models/v_umbrella.mdl" );
	PRECACHE_MODEL( "models/p_umbrella.mdl" );
	PRECACHE_MODEL( "models/v_tfc_crowbar.mdl" );
	PRECACHE_MODEL( "models/p_crowbar.mdl" );
	PRECACHE_MODEL( "models/p_crowbar2.mdl" );
	PRECACHE_SOUND( "weapons/cbar_hit1.wav" );
	PRECACHE_SOUND( "weapons/cbar_hit2.wav" );
	PRECACHE_SOUND( "weapons/cbar_hitbod1.wav" );
	PRECACHE_SOUND( "weapons/cbar_hitbod2.wav" );
	PRECACHE_SOUND( "weapons/cbar_hitbod3.wav" );
	PRECACHE_SOUND( "weapons/cbar_miss1.wav" );

	classid = 3;	// tells the shared event which melee weapon swung

	m_usAxe = PRECACHE_EVENT( 1, "events/wpn/tf_axe.sc" );
	m_usAxeDecal = PRECACHE_EVENT( 1, "events/wpn/tf_axedecal.sc" );
}

int CTFAxe::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = NULL;
	p->iAmmo1 = -1;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 0;
	p->iPosition = 3;
	p->iId = m_iId = WEAPON_AXE;
	p->iWeight = 0;
	return 1;
}

BOOL CTFAxe::Deploy( void )
{
	if ( m_pPlayer && m_pPlayer->pev->playerclass == PC_CIVILIAN )
		return DefaultDeploy( "models/v_umbrella.mdl", "models/p_umbrella.mdl", CROWBAR_DRAW, "crowbar", 1 );

	return DefaultDeploy( "models/v_tfc_crowbar.mdl", "models/p_crowbar.mdl", CROWBAR_DRAW, "crowbar", 1 );
}

void CTFAxe::Holster( int skiplocal )
{
	m_pPlayer->m_flNextAttack = UTIL_WeaponTimeBase() + 0.5;
	SendWeaponAnim( CROWBAR_HOLSTER );
}

// Animations, sounds and decals are all done client side by the axe events
void CTFAxe::PlayAnim( int iAnimType )
{
}

void CTFAxe::PlaySound( int iSoundType, float fSoundData )
{
}

void CTFAxe::PlayDecal( void )
{
}

#ifdef CLIENT_DLL
// The client predicts the swing with a plain line trace; only the server
// falls back to a hull trace when the line misses.
void CTFAxe::PrimaryAttack( void )
{
	int fDidHit = FALSE;
	TraceResult tr;

	m_bHullHit = FALSE;

	UTIL_MakeVectors( m_pPlayer->pev->v_angle );
	Vector vecSrc = m_pPlayer->GetGunPosition();
	Vector vecEnd = vecSrc + gpGlobals->v_forward * 32;

	UTIL_TraceLine( vecSrc, vecEnd, dont_ignore_monsters, ENT( m_pPlayer->pev ), &tr );

	DB_LogShots( 1 );

	PLAYBACK_EVENT_FULL( FEV_NOTHOST, m_pPlayer->edict(), m_usAxe, 0.0,
		(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, classid, 0, 0, 0 );

	if ( tr.flFraction >= 1.0 )
	{
		// miss
		m_bHullHit = TRUE;
		m_flNextPrimaryAttack = GetNextAttackDelay( 0.4 );
		m_flTimeWeaponIdle = UTIL_WeaponTimeBase() + 5;
		m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
		return;
	}

	// hit
	CBaseEntity *pEntity = CBaseEntity::Instance( tr.pHit );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );

	fDidHit = AxeHit( pEntity, gpGlobals->v_forward, &tr );

	m_flNextPrimaryAttack = GetNextAttackDelay( 0.4 );
	m_flTimeWeaponIdle = UTIL_WeaponTimeBase() + 5;

	// play thwack, smack, or dong sound
	float flVol = 1.0;
	int fHitWorld = TRUE;

	if ( fDidHit && pEntity && pEntity->Classify() != CLASS_NONE && pEntity->Classify() != CLASS_MACHINE )
	{
		m_pPlayer->m_iWeaponVolume = CROWBAR_BODYHIT_VOLUME;
		if ( !pEntity->IsAlive() )
			return;

		flVol = 0.1;
		fHitWorld = FALSE;
	}

	m_trHit = tr;
	SetThink( &CTFAxe::Smack );
	pev->nextthink = gpGlobals->time + 0.2;

	m_pPlayer->m_iWeaponVolume = flVol * CROWBAR_WALLHIT_VOLUME;
}
#else
void CTFAxe::PrimaryAttack( void )
{
	int fDidHit = FALSE;
	TraceResult tr;

	m_bHullHit = FALSE;

	UTIL_MakeVectors( m_pPlayer->pev->v_angle );
	Vector vecSrc = m_pPlayer->GetGunPosition();
	Vector vecEnd = vecSrc + gpGlobals->v_forward * 32;

	UTIL_TraceLine( vecSrc, vecEnd, dont_ignore_monsters, ENT( m_pPlayer->pev ), &tr );

	DB_LogShots( 1 );

	PLAYBACK_EVENT_FULL( FEV_NOTHOST, m_pPlayer->edict(), m_usAxe, 0.0,
		(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, classid, 0, 0, 0 );

	if ( tr.flFraction >= 1.0 )
	{
		m_bHullHit = TRUE;

		UTIL_TraceHull( vecSrc, vecEnd, dont_ignore_monsters, head_hull, ENT( m_pPlayer->pev ), &tr );
		if ( tr.flFraction < 1.0 )
		{
			// Calculate the point of intersection of the line (or hull) and the object we hit
			// This is and approximation of the "best" intersection
			CBaseEntity *pHit = CBaseEntity::Instance( tr.pHit );
			if ( !pHit || pHit->IsBSPModel() )
				FindHullIntersection( vecSrc, tr, VEC_DUCK_HULL_MIN, VEC_DUCK_HULL_MAX, m_pPlayer->edict() );
			vecEnd = tr.vecEndPos;	// This is the point on the actual surface (the hull could have hit space)
		}

		if ( tr.flFraction >= 1.0 )
		{
			// miss
			m_flNextPrimaryAttack = GetNextAttackDelay( 0.4 );
			m_flTimeWeaponIdle = UTIL_WeaponTimeBase() + 5;
			m_pPlayer->SetAnimation( PLAYER_ATTACK1 );
			return;
		}
	}

	// hit
	CBaseEntity *pEntity = CBaseEntity::Instance( tr.pHit );

	m_pPlayer->SetAnimation( PLAYER_ATTACK1 );

	fDidHit = AxeHit( pEntity, gpGlobals->v_forward, &tr );

	m_flNextPrimaryAttack = GetNextAttackDelay( 0.4 );
	m_flTimeWeaponIdle = UTIL_WeaponTimeBase() + 5;

	// play thwack, smack, or dong sound
	float flVol = 1.0;
	int fHitWorld = TRUE;

	if ( fDidHit && pEntity && pEntity->Classify() != CLASS_NONE && pEntity->Classify() != CLASS_MACHINE )
	{
		m_pPlayer->m_iWeaponVolume = CROWBAR_BODYHIT_VOLUME;
		if ( !pEntity->IsAlive() )
			return;

		flVol = 0.1;
		fHitWorld = FALSE;
	}

	m_trHit = tr;
	SetThink( &CTFAxe::Smack );
	pev->nextthink = gpGlobals->time + 0.2;

	m_pPlayer->m_iWeaponVolume = flVol * CROWBAR_WALLHIT_VOLUME;
}
#endif

void CTFAxe::Smack( void )
{
	PlayDecal();
}

// Axe and knife damage. Spies backstab for extra damage that ignores armour.
BOOL CTFAxe::AxeHit( CBaseEntity *pTarget, Vector vecDir, TraceResult *ptr )
{
	ClearMultiDamage();

	if ( m_pPlayer->pev->playerclass == PC_SPY && !strcmp( STRING( pTarget->pev->classname ), "player" ) )
	{
		// Is the victim facing away from us?
		UTIL_MakeVectors( pTarget->pev->v_angle );
		Vector vecDef = gpGlobals->v_right;
		UTIL_MakeVectors( m_pPlayer->pev->v_angle );
		float flResult = vecDef.x * gpGlobals->v_forward.y - vecDef.y * gpGlobals->v_forward.x;

		if ( flResult <= 0 )
			pTarget->TraceAttack( m_pPlayer->pev, 40, vecDir, ptr, DMG_CLUB );
		else if ( !m_bHullHit )
			pTarget->TraceAttack( m_pPlayer->pev, 60, vecDir, ptr, DMG_CLUB | DMG_IGNOREARMOR );
		else
			pTarget->TraceAttack( m_pPlayer->pev, 120, vecDir, ptr, DMG_CLUB | DMG_IGNOREARMOR );
	}
	else
	{
		pTarget->TraceAttack( m_pPlayer->pev, 20, vecDir, ptr, DMG_CLUB );
	}

	ApplyMultiDamage( m_pPlayer->pev, m_pPlayer->pev );
	return TRUE;
}

//=========================================================
// Spanner
//=========================================================
void CTFSpanner::Spawn( void )
{
	Precache();
	m_iId = WEAPON_SPANNER;
	m_iClip = -1;
	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
	classid = 1;
}

void CTFSpanner::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_spanner.mdl" );
	PRECACHE_MODEL( "models/p_spanner.mdl" );
	PRECACHE_MODEL( "models/p_spanner2.mdl" );

	m_usAxe = PRECACHE_EVENT( 1, "events/wpn/tf_axe.sc" );
	m_usAxeDecal = PRECACHE_EVENT( 1, "events/wpn/tf_axedecal.sc" );
}

BOOL CTFSpanner::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_spanner.mdl", "models/p_spanner.mdl", SPANNER_DRAW, "crowbar", 1 );
}

void CTFSpanner::Holster( int skiplocal )
{
	m_pPlayer->m_flNextAttack = UTIL_WeaponTimeBase() + 0.5;
	SendWeaponAnim( SPANNER_HOLSTER );
}

// Spanner goals trigger, friendly buildings get repaired / restocked
BOOL CTFSpanner::AxeHit( CBaseEntity *pTarget, Vector vecDir, TraceResult *ptr )
{
	if ( pTarget->goal_activation & TFGA_SPANNER )
	{
		pTarget->do_triggerwork = TRUE;
		pTarget->Use( m_pPlayer, m_pPlayer, USE_TOGGLE, 8 );
		pTarget->do_triggerwork = FALSE;
		return TRUE;
	}

	if ( m_pPlayer->IsAlly( pTarget ) )
		return pTarget->EngineerUse( m_pPlayer ) != FALSE;

	ClearMultiDamage();
	pTarget->TraceAttack( m_pPlayer->pev, 20, vecDir, ptr, DMG_CLUB );
	ApplyMultiDamage( m_pPlayer->pev, m_pPlayer->pev );
	return TRUE;
}

int CTFSpanner::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = "uranium";	// cells
	p->iAmmo1 = -1;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 0;
	p->iPosition = 2;
	p->iId = m_iId = WEAPON_SPANNER;
	p->iWeight = 0;
	return 1;
}

void CTFSpanner::PlayAnim( int iAnimType )
{
	if ( iAnimType == ANIM_ATTACK_HIT )
		SendWeaponAnim( SPANNER_ATTACK1 );
	else if ( iAnimType == ANIM_ATTACK_MISS )
		SendWeaponAnim( SPANNER_USE );
}

void CTFSpanner::WeaponIdle( void )
{
	if ( m_flTimeWeaponIdle > UTIL_WeaponTimeBase() )
		return;

	m_flTimeWeaponIdle = UTIL_WeaponTimeBase() + 12.5;
	SendWeaponAnim( SPANNER_IDLE );
}

//=========================================================
// Knife (damage is CTFAxe::AxeHit's spy backstab)
//=========================================================
void CTFKnife::Spawn( void )
{
	Precache();
	m_iClip = -1;
	m_iId = WEAPON_KNIFE;
	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
	classid = 0;
}

void CTFKnife::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_knife.mdl" );
	PRECACHE_MODEL( "models/p_knife.mdl" );
	PRECACHE_MODEL( "models/p_knife2.mdl" );

	m_usAxe = PRECACHE_EVENT( 1, "events/wpn/tf_axe.sc" );
	m_usAxeDecal = PRECACHE_EVENT( 1, "events/wpn/tf_axedecal.sc" );
	m_usKnife = PRECACHE_EVENT( 1, "events/wpn/tf_knife.sc" );
}

BOOL CTFKnife::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_knife.mdl", "models/p_knife.mdl", KNIFE_DRAW, "knife", 1 );
}

void CTFKnife::Holster( int skiplocal )
{
	m_pPlayer->m_flNextAttack = UTIL_WeaponTimeBase() + 0.5;
	SendWeaponAnim( KNIFE_HOLSTER );
}

int CTFKnife::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = NULL;
	p->iAmmo1 = -1;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 0;
	p->iPosition = 4;
	p->iId = m_iId = WEAPON_KNIFE;
	p->iWeight = 0;
	return 1;
}

void CTFKnife::PlayAnim( int iAnimType )
{
	switch ( iAnimType )
	{
	case ANIM_ATTACK_HIT:
	case ANIM_ATTACK_MISS:
		SendWeaponAnim( KNIFE_ATTACK1 );
		break;
	}
}

void CTFKnife::WeaponIdle( void )
{
	if ( m_flTimeWeaponIdle > UTIL_WeaponTimeBase() )
		return;

	m_flTimeWeaponIdle = UTIL_WeaponTimeBase() + 7.5;

	switch ( RANDOM_LONG( 0, 1 ) )
	{
	case 0:
		SendWeaponAnim( KNIFE_IDLE1 );
		break;
	case 1:
		SendWeaponAnim( KNIFE_IDLE2 );
		break;
	}
}

//=========================================================
// Medikit: heals and cures team mates, infects enemies
//=========================================================
void CTFMedikit::Spawn( void )
{
	Precache();
	m_iClip = -1;
	m_iId = WEAPON_MEDIKIT;
	pev->solid = SOLID_TRIGGER;
	SetTouch( &CBasePlayerItem::DefaultTouch );
	classid = 2;
}

void CTFMedikit::Precache( void )
{
	PRECACHE_MODEL( "models/v_tfc_medkit.mdl" );
	PRECACHE_MODEL( "models/p_medkit.mdl" );
	PRECACHE_MODEL( "models/p_medkit2.mdl" );

	m_usAxe = PRECACHE_EVENT( 1, "events/wpn/tf_axe.sc" );
	m_usAxeDecal = PRECACHE_EVENT( 1, "events/wpn/tf_axedecal.sc" );
	m_usNormalShot = PRECACHE_EVENT( 1, "events/wpn/tf_mednormal.sc" );
	m_usSuperShot = PRECACHE_EVENT( 1, "events/wpn/tf_medsuper.sc" );
	m_usSteamShot = PRECACHE_EVENT( 1, "events/wpn/tf_medsteam.sc" );
}

BOOL CTFMedikit::Deploy( void )
{
	return DefaultDeploy( "models/v_tfc_medkit.mdl", "models/p_medkit.mdl", MEDIKIT_DRAW, "medkit", 1 );
}

void CTFMedikit::Holster( int skiplocal )
{
	m_pPlayer->m_flNextAttack = UTIL_WeaponTimeBase() + 0.5;
	SendWeaponAnim( MEDIKIT_HOLSTER );
}

#ifdef CLIENT_DLL
// The client's copy keeps the older medikit: no logging, no infection or
// health rot timers, and infecting an enemy does no damage.
BOOL CTFMedikit::AxeHit( CBaseEntity *pTarget, Vector vecDir, TraceResult *ptr )
{
	if ( strcmp( STRING( pTarget->pev->classname ), "player" ) )
		return FALSE;
	if ( pTarget->pev->health <= 0 )
		return FALSE;

	if ( m_pPlayer->IsAlly( pTarget ) )
	{
		// Cure concussion
		CBaseEntity *pTimer = pTarget->FindTimer( TF_TIMER_CONCUSSION );
		if ( pTimer )
		{
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_cureconc", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );

			if ( pTimer->team_no != m_pPlayer->team_no )
				m_pPlayer->TF_AddFrags( 1 );

			pTimer->pev->nextthink = gpGlobals->time;
			pTimer->SetThink( &CBaseEntity::SUB_Remove );
		}

		// Cure hallucinations
		if ( pTarget->tfstate & TFSTATE_HALLUCINATING )
		{
			pTimer = pTarget->FindTimer( TF_TIMER_HALLUCINATION );
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_curehalluc", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );

			if ( pTimer->team_no != m_pPlayer->team_no )
				m_pPlayer->TF_AddFrags( 1 );

			pTarget->tfstate &= ~TFSTATE_HALLUCINATING;
			pTimer->pev->nextthink = gpGlobals->time;
			pTimer->SetThink( &CBaseEntity::SUB_Remove );
		}

		// Cure tranquilisation
		if ( pTarget->tfstate & TFSTATE_TRANQUILISED )
		{
			pTimer = pTarget->FindTimer( TF_TIMER_TRANQUILISATION );
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_curetranq", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );

			if ( pTimer->team_no != m_pPlayer->team_no )
				m_pPlayer->TF_AddFrags( 1 );

			pTarget->tfstate &= ~TFSTATE_TRANQUILISED;
			((CBasePlayer *)pTarget)->TeamFortress_SetSpeed();
			pTimer->pev->nextthink = gpGlobals->time;
			pTimer->SetThink( &CBaseEntity::SUB_Remove );
		}

		// Cure infection
		if ( pTarget->tfstate & TFSTATE_INFECTED )
		{
			int fDmg = pTarget->pev->health / 2;
			SpawnBlood( pTarget->pev->origin, pTarget->BloodColor(), fDmg );
		}

		// Put out fire
		if ( pTarget->numflames > 0 )
		{
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_curefire", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );

			pTarget->numflames = 0;

			PLAYBACK_EVENT_FULL( 0, m_pPlayer->edict(), m_usSteamShot, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );
		}

		if ( pTarget->pev->health < pTarget->pev->max_health )
		{
			PLAYBACK_EVENT_FULL( 0, m_pPlayer->edict(), m_usNormalShot, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

			pTarget->TakeHealth( 200, DMG_GENERIC );
		}
		else if ( pTarget->pev->health < pTarget->pev->max_health + 50 )
		{
			PLAYBACK_EVENT_FULL( 0, m_pPlayer->edict(), m_usSuperShot, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

			pTarget->TakeHealth( 5, DMG_GENERIC );

			if ( !( pTarget->items & IT_SUPERHEALTH ) )
				pTarget->items |= IT_SUPERHEALTH;
		}

		return TRUE;
	}

	// Enemy: infect them
	ClearMultiDamage();
	pTarget->TraceAttack( m_pPlayer->pev, 0, vecDir, ptr, DMG_CLUB );
	ApplyMultiDamage( m_pPlayer->pev, m_pPlayer->pev );

	if ( !( pTarget->tfstate & TFSTATE_INFECTED ) && pTarget->pev->playerclass != PC_MEDIC && gpGlobals->time >= cb_prematch_time )
	{
		pTarget->tfstate |= TFSTATE_INFECTED;
		pTarget->infection_team_no = m_pPlayer->team_no;
	}

	return TRUE;
}
#else
BOOL CTFMedikit::AxeHit( CBaseEntity *pTarget, Vector vecDir, TraceResult *ptr )
{
	if ( strcmp( STRING( pTarget->pev->classname ), "player" ) )
		return FALSE;
	if ( pTarget->pev->health <= 0 )
		return FALSE;

	if ( m_pPlayer->IsAlly( pTarget ) )
	{
		// Cure concussion
		CBaseEntity *pTimer = pTarget->FindTimer( TF_TIMER_CONCUSSION );
		if ( pTimer )
		{
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_cureconc", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Concussion\" against \"%s<%i><%s><%s>\"\n",
				STRING( m_pPlayer->pev->netname ),
				GETPLAYERUSERID( m_pPlayer->edict() ),
				GETPLAYERAUTHID( m_pPlayer->edict() ),
				m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
				STRING( pTarget->pev->netname ),
				GETPLAYERUSERID( pTarget->edict() ),
				GETPLAYERAUTHID( pTarget->edict() ),
				pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );

			// A frag for curing an enemy's grenade
			if ( pTimer->team_no != m_pPlayer->team_no )
				m_pPlayer->TF_AddFrags( 1 );

			pTimer->pev->nextthink = gpGlobals->time;
			pTimer->SetThink( &CBaseEntity::SUB_Remove );
		}

		// Cure hallucinations
		if ( pTarget->tfstate & TFSTATE_HALLUCINATING )
		{
			pTimer = pTarget->FindTimer( TF_TIMER_HALLUCINATION );
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_curehalluc", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Hallucinations\" against \"%s<%i><%s><%s>\"\n",
				STRING( m_pPlayer->pev->netname ),
				GETPLAYERUSERID( m_pPlayer->edict() ),
				GETPLAYERAUTHID( m_pPlayer->edict() ),
				m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
				STRING( pTarget->pev->netname ),
				GETPLAYERUSERID( pTarget->edict() ),
				GETPLAYERAUTHID( pTarget->edict() ),
				pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );

			if ( pTimer->team_no != m_pPlayer->team_no )
				m_pPlayer->TF_AddFrags( 1 );

			pTarget->tfstate &= ~TFSTATE_HALLUCINATING;
			pTimer->pev->nextthink = gpGlobals->time;
			pTimer->SetThink( &CBaseEntity::SUB_Remove );
		}

		// Cure tranquilisation
		if ( pTarget->tfstate & TFSTATE_TRANQUILISED )
		{
			pTimer = pTarget->FindTimer( TF_TIMER_TRANQUILISATION );
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_curetranq", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Tranquilisation\" against \"%s<%i><%s><%s>\"\n",
				STRING( m_pPlayer->pev->netname ),
				GETPLAYERUSERID( m_pPlayer->edict() ),
				GETPLAYERAUTHID( m_pPlayer->edict() ),
				m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
				STRING( pTarget->pev->netname ),
				GETPLAYERUSERID( pTarget->edict() ),
				GETPLAYERAUTHID( pTarget->edict() ),
				pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );

			if ( pTimer->team_no != m_pPlayer->team_no )
				m_pPlayer->TF_AddFrags( 1 );

			pTarget->tfstate &= ~TFSTATE_TRANQUILISED;
			((CBasePlayer *)pTarget)->TeamFortress_SetSpeed();
			pTimer->pev->nextthink = gpGlobals->time;
			pTimer->SetThink( &CBaseEntity::SUB_Remove );
		}

		// Cure infection: costs the patient half their health
		if ( pTarget->tfstate & TFSTATE_INFECTED )
		{
			int fDmg = pTarget->pev->health / 2;
			SpawnBlood( pTarget->pev->origin, pTarget->BloodColor(), fDmg );

			pTimer = pTarget->FindTimer( TF_TIMER_INFECTION );
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_cureinfection", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Cured_Infection\" against \"%s<%i><%s><%s>\"\n",
				STRING( m_pPlayer->pev->netname ),
				GETPLAYERUSERID( m_pPlayer->edict() ),
				GETPLAYERAUTHID( m_pPlayer->edict() ),
				m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
				STRING( pTarget->pev->netname ),
				GETPLAYERUSERID( pTarget->edict() ),
				GETPLAYERAUTHID( pTarget->edict() ),
				pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );

			if ( pTimer->team_no != m_pPlayer->team_no )
				m_pPlayer->TF_AddFrags( 1 );

			// The infecting medic gets the credit if this kills them
			CBaseEntity *pOwner = CBaseEntity::Instance( pTimer->pev->owner );
			pTarget->TakeDamage( pev, pOwner->pev, fDmg, DMG_IGNOREARMOR | DMG_NERVEGAS );

			pTarget->tfstate &= ~TFSTATE_INFECTED;
			pTimer->pev->nextthink = gpGlobals->time;
			pTimer->SetThink( &CBaseEntity::SUB_Remove );
		}

		// Put out fire
		if ( pTarget->numflames > 0 )
		{
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Medic_curefire", STRING( m_pPlayer->pev->netname ), STRING( pTarget->pev->netname ) );
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Doused_Fire\" against \"%s<%i><%s><%s>\"\n",
				STRING( m_pPlayer->pev->netname ),
				GETPLAYERUSERID( m_pPlayer->edict() ),
				GETPLAYERAUTHID( m_pPlayer->edict() ),
				m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
				STRING( pTarget->pev->netname ),
				GETPLAYERUSERID( pTarget->edict() ),
				GETPLAYERAUTHID( pTarget->edict() ),
				pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );

			pTarget->numflames = 0;

			PLAYBACK_EVENT_FULL( 0, m_pPlayer->edict(), m_usSteamShot, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );
		}

		if ( pTarget->pev->health < pTarget->pev->max_health )
		{
			// Heal up to max health
			PLAYBACK_EVENT_FULL( 0, m_pPlayer->edict(), m_usNormalShot, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

			pTarget->TakeHealth( 200, DMG_GENERIC );

			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n",
				STRING( m_pPlayer->pev->netname ),
				GETPLAYERUSERID( m_pPlayer->edict() ),
				GETPLAYERAUTHID( m_pPlayer->edict() ),
				m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
				STRING( pTarget->pev->netname ),
				GETPLAYERUSERID( pTarget->edict() ),
				GETPLAYERAUTHID( pTarget->edict() ),
				pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );
		}
		else if ( pTarget->pev->health < pTarget->pev->max_health + 50 )
		{
			// Overheal by 5 at a time; the extra rots away again
			PLAYBACK_EVENT_FULL( 0, m_pPlayer->edict(), m_usSuperShot, 0.0,
				(float *)&g_vecZero, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

			pTarget->TakeHealth( 5, DMG_IGNORE_MAXHEALTH );

			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Heal\" against \"%s<%i><%s><%s>\"\n",
				STRING( m_pPlayer->pev->netname ),
				GETPLAYERUSERID( m_pPlayer->edict() ),
				GETPLAYERAUTHID( m_pPlayer->edict() ),
				m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
				STRING( pTarget->pev->netname ),
				GETPLAYERUSERID( pTarget->edict() ),
				GETPLAYERAUTHID( pTarget->edict() ),
				pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );

			if ( !( pTarget->items & IT_SUPERHEALTH ) )
			{
				pTarget->items |= IT_SUPERHEALTH;
				CBaseEntity *pRotTimer = pTarget->CreateTimer( TF_TIMER_ROTHEALTH );
				pRotTimer->pev->nextthink = gpGlobals->time + 5;
				pRotTimer->SetThink( &CBaseEntity::Timer_HealthRot );
			}
		}

		return TRUE;
	}

	// Enemy: a light hit, and infect them
	ClearMultiDamage();
	pTarget->TraceAttack( m_pPlayer->pev, 10, vecDir, ptr, DMG_CLUB );
	ApplyMultiDamage( m_pPlayer->pev, m_pPlayer->pev );

	if ( pTarget->tfstate & TFSTATE_INFECTED )
		return TRUE;
	if ( pTarget->pev->playerclass == PC_MEDIC )	// medics are immune
		return TRUE;
	if ( gpGlobals->time < cb_prematch_time )
		return TRUE;
	if ( pTarget->pev->deadflag != DEAD_FEIGNING && pTarget->pev->deadflag != DEAD_NO )
		return TRUE;

	pTarget->tfstate |= TFSTATE_INFECTED;

	CBaseEntity *pTimer = pTarget->CreateTimer( TF_TIMER_INFECTION );
	pTimer->pev->nextthink = gpGlobals->time + 2;
	pTimer->SetThink( &CBaseEntity::Timer_Infection );
	pTimer->pev->enemy = m_pPlayer->edict();
	pTarget->infection_team_no = m_pPlayer->team_no;

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Medic_Infection\" against \"%s<%i><%s><%s>\"\n",
		STRING( m_pPlayer->pev->netname ),
		GETPLAYERUSERID( m_pPlayer->edict() ),
		GETPLAYERAUTHID( m_pPlayer->edict() ),
		m_pPlayer->team_no ? GetTeamName( m_pPlayer->team_no ) : "SPECTATOR",
		STRING( pTarget->pev->netname ),
		GETPLAYERUSERID( pTarget->edict() ),
		GETPLAYERAUTHID( pTarget->edict() ),
		pTarget->team_no ? GetTeamName( pTarget->team_no ) : "SPECTATOR" );

	return TRUE;
}
#endif

int CTFMedikit::GetItemInfo( ItemInfo *p )
{
	p->pszName = STRING( pev->classname );
	p->pszAmmo1 = NULL;
	p->iAmmo1 = -1;
	p->pszAmmo2 = NULL;
	p->iAmmo2 = -1;
	p->iMaxClip = WEAPON_NOCLIP;
	p->iSlot = 0;
	p->iPosition = 1;
	p->iId = m_iId = WEAPON_MEDIKIT;
	p->iWeight = 0;
	return 1;
}

void CTFMedikit::PlayAnim( int iAnimType )
{
	if ( iAnimType == ANIM_ATTACK_HIT )
		SendWeaponAnim( MEDIKIT_USE_LONG );
	else if ( iAnimType == ANIM_ATTACK_MISS )
		SendWeaponAnim( MEDIKIT_USE_SHORT );
}

void CTFMedikit::PlaySound( int iSoundType, float fSoundData )
{
}

void CTFMedikit::PlayDecal( void )
{
}

void CTFMedikit::WeaponIdle( void )
{
	if ( m_flTimeWeaponIdle > UTIL_WeaponTimeBase() )
		return;

	m_flTimeWeaponIdle = UTIL_WeaponTimeBase() + 7.5;

	switch ( RANDOM_LONG( 0, 1 ) )
	{
	case 0:
		SendWeaponAnim( MEDIKIT_IDLE1 );
		break;
	case 1:
		SendWeaponAnim( MEDIKIT_IDLE2 );
		break;
	}
}
