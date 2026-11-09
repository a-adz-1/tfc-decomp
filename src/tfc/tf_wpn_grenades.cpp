/***
*
*	Team Fortress Classic: hand grenades (normal, concussion, MIRV, nail,
*	napalm, EMP, hallucination gas, caltrops)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "weapons.h"
#include "player.h"
#include "game.h"
#include "soundent.h"
#include "gamerules.h"
#include "tf_defs.h"
#include "tf_wpn_grenades.h"

extern int gmsgStatusIcon;

LINK_ENTITY_TO_CLASS( tf_weapon_concussiongrenade, CTFConcussionGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_genericprimedgrenade, CTFPrimeGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_caltropgrenade, CTFCaltropGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_normalgrenade, CTFNormalGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_napalmgrenade, CTFNapalmGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_nailgrenade, CTFNailGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_mirvgrenade, CTFMirvGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_gasgrenade, CTFGasGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_empgrenade, CTFEMPGrenade );
LINK_ENTITY_TO_CLASS( tf_weapon_mirvbomblet, CTFBomblet );
LINK_ENTITY_TO_CLASS( tf_weapon_caltrop, CTFCaltrop );

int CTFEMPGrenade::BlastTexture;
int CTFConcussionGrenade::BlastTexture;

//=========================================================
// Primed grenade base: held until thrown or it goes off
//=========================================================
void CTFPrimeGrenade::Spawn( void )
{
	pev->movetype = MOVETYPE_BOUNCE;
	pev->solid = SOLID_BBOX;

	setModel();
	setName();
	setDamage();
	setRadius();

	UTIL_SetSize( pev, g_vecZero, g_vecZero );

	m_bDontSpark = FALSE;
	m_bDontSmoke = TRUE;
	m_fRegisteredSound = FALSE;
	m_flSmokeScale = 0;
	m_flExplosionScale = 0;

	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );
	team_no = pOwner->team_no;
}

// EMP sets primed grenades off immediately
void CTFPrimeGrenade::TakeEMPBlast( entvars_t *pevGren )
{
	SetThink( &CTFPrimeGrenade::GrenadePrimed );
	heat = gpGlobals->time;
}

void CTFPrimeGrenade::InitPriming( CBaseEntity *pOwner )
{
	pev->owner = pOwner->edict();
	SetThink( &CTFPrimeGrenade::GrenadePrimed );
	team_no = pOwner->team_no;
	pev->nextthink = gpGlobals->time + getPinTime();
	heat = gpGlobals->time + getPrimeTime() + getPinTime();
	team_no = pOwner->team_no;
	TF_GrenadeRing( pev, team_no );

	// Clear the HUD icon of the last grenade primed
	if ( pOwner->m_iszGrenadeName )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pOwner->edict() );
			WRITE_BYTE( 0 );
			WRITE_CHAR( 100 );
			WRITE_CHAR( 95 );
			WRITE_STRING( pOwner->m_iszGrenadeName ? STRING( pOwner->m_iszGrenadeName ) : "normalgrenade" );
			WRITE_BYTE( 255 );
			WRITE_BYTE( 160 );
			WRITE_BYTE( 0 );
		MESSAGE_END();
	}

	pOwner->m_iszGrenadeName = pev->classname;
}

BOOL CTFPrimeGrenade::canPrime( CBaseEntity *pOwner )
{
	return !( pOwner->tfstate & TFSTATE_GRENPRIMED );
}

void CTFPrimeGrenade::Precache( void )
{
	PRECACHE_MODEL( "models/presentsm.mdl" );
	g_sModelIndexGrenade = PRECACHE_MODEL( "models/w_grenade.mdl" );
	PRECACHE_MODEL( "models/v_grenade.mdl" );
	PRECACHE_MODEL( "models/p_grenade.mdl" );
	PRECACHE_MODEL( "models/p_grenade2.mdl" );
	PRECACHE_MODEL( "models/w_grenadeT.mdl" );
}

// Held too long
void CTFPrimeGrenade::ExplodeInHand( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	Spawn();
	UTIL_SetOrigin( pev, pOwner->pev->origin );
	pev->velocity = g_vecZero;
	pev->angles = UTIL_VecToAngles( pev->velocity );
	pev->dmgtime = heat;

	SetThink( &CGrenade::Detonate );
	pev->nextthink = gpGlobals->time;
}

// Thrower died holding it: drop it
void CTFPrimeGrenade::DeadThrow( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	Spawn();
	UTIL_SetOrigin( pev, pOwner->pev->origin );
	pev->velocity = Vector( 0, 0, 30 );
	pev->angles = UTIL_VecToAngles( pev->velocity );
	pev->avelocity = g_vecZero;

	SetTouch( &CGrenade::BounceTouch );
	pev->dmgtime = heat;
	SetThink( &CGrenade::TumbleThink );
	pev->nextthink = gpGlobals->time + 0.1;

	pev->sequence = RANDOM_LONG( 3, 6 );
	pev->framerate = 1.0;
	pev->gravity = 0.81;
	pev->friction = 0.6;
}

void CTFPrimeGrenade::Throw( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	Spawn();

	UTIL_MakeVectors( pOwner->pev->v_angle );
	pev->velocity = gpGlobals->v_forward * 600 + gpGlobals->v_up * ( 200 + RANDOM_FLOAT( -10, 10 ) ) + gpGlobals->v_right * RANDOM_FLOAT( -10, 10 );
	pev->avelocity = g_vecZero;

	UTIL_SetOrigin( pev, pOwner->pev->origin );

	SetTouch( &CGrenade::BounceTouch );
	pev->dmgtime = heat;
	SetThink( &CGrenade::TumbleThink );
	pev->nextthink = gpGlobals->time + 0.1;

	pev->framerate = 1.0;
	pev->gravity = 0.81;
	pev->friction = 0.6;
}

void CTFPrimeGrenade::GrenadePrimed( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	// Class changed / grenades removed
	if ( pOwner->bRemoveGrenade )
	{
		pOwner->tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );
		pOwner->bRemoveGrenade = FALSE;
		dremove( this );
		return;
	}

	// Still held
	if ( !( pOwner->tfstate & TFSTATE_GRENTHROWING ) && pOwner->IsAlive() )
	{
		pev->nextthink = gpGlobals->time + 0.01;
		if ( heat < gpGlobals->time )
		{
			pOwner->tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );
			ExplodeInHand();
		}
		return;
	}

	pOwner->tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );

	if ( pOwner->IsAlive() )
		Throw();
	else
		DeadThrow();
}

//=========================================================
// Normal grenade
//=========================================================
CGrenade *CTFNormalGrenade::Prime( CBaseEntity *pOwner )
{
	CTFNormalGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFNormalGrenade *)NULL );
		pGrenade->pev->classname = MAKE_STRING( "normalgrenade" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFNormalGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( InNoGrenadeZone( pev->origin ) )
		return;

	if ( !m_usExplode )
		m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_normalgren.sc" );

	CGrenade::Explode( pTrace, bitsDamageType | DMG_RADIUS_QUAKE );
}

void CTFNormalGrenade::Precache( void )
{
	PRECACHE_MODEL( "models/presentsm.mdl" );
	g_sModelIndexGrenade = PRECACHE_MODEL( "models/w_grenade.mdl" );
	PRECACHE_MODEL( "models/v_grenade.mdl" );
	PRECACHE_MODEL( "models/p_grenade.mdl" );
	PRECACHE_MODEL( "models/p_grenade2.mdl" );
	PRECACHE_MODEL( "models/w_grenadeT.mdl" );
}

//=========================================================
// Concussion grenade
//=========================================================
CGrenade *CTFConcussionGrenade::Prime( CBaseEntity *pOwner )
{
	CTFConcussionGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFConcussionGrenade *)NULL );
		pGrenade->pev->classname = MAKE_STRING( "concussiongrenade" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFConcussionGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( InNoGrenadeZone( pev->origin ) )
		return;

	if ( !m_usExplode )
		m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_concuss.sc" );

	PLAYBACK_EVENT_FULL( 0, NULL, m_usExplode, 0.0, (float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

	CBaseEntity *pEntity = NULL;
	while ( ( pEntity = UTIL_FindEntityInSphere( pEntity, pev->origin, blastRadius ) ) != NULL )
		pEntity->TeamFortress_TakeConcussionBlast( pev, blastRadius );

	UTIL_Remove( this );
}

void CTFConcussionGrenade::Precache( void )
{
	BlastTexture = PRECACHE_MODEL( "sprites/shockwave.spr" );
	PRECACHE_MODEL( "models/conc_grenade.mdl" );
	PRECACHE_SOUND( "weapons/concgren_blast1.wav" );
	PRECACHE_SOUND( "weapons/concgren_blast2.wav" );
	PRECACHE_SOUND( "weapons/concgren_blast3.wav" );
	m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_concuss.sc" );
}

void CTFConcussionGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/conc_grenade.mdl" );
}

//=========================================================
// MIRV grenade: explodes and throws out 4 bomblets
//=========================================================
void CTFMirvGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/mirv_grenade.mdl" );
}

CGrenade *CTFMirvGrenade::Prime( CBaseEntity *pOwner )
{
	CTFMirvGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFMirvGrenade *)NULL );
		pGrenade->pev->classname = MAKE_STRING( "mirvgrenade" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFMirvGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( InNoGrenadeZone( pev->origin ) )
		return;

	if ( !m_usExplode )
		m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_mirvmain.sc" );

	for ( int i = 0; i < 4; i++ )
	{
		CTFBomblet *bomblet = GetClassPtr( (CTFBomblet *)NULL );
		bomblet->m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_mirv.sc" );
		bomblet->LaunchFromMirv( this );
	}

	CGrenade::Explode( pTrace, bitsDamageType | DMG_RADIUS_QUAKE );
}

void CTFMirvGrenade::Precache( void )
{
	g_sModelIndexMirvGrenade = PRECACHE_MODEL( "models/mirv_grenade.mdl" );
	PRECACHE_MODEL( "models/bomblet.mdl" );
}

void CTFBomblet::LaunchFromMirv( CTFMirvGrenade *pMirvGren )
{
	Vector vecSrc = pMirvGren->pev->origin + Vector( 0, 0, 32 );
	Vector vecVelocity = Vector( RANDOM_FLOAT( -75, 75 ) * 2, RANDOM_FLOAT( -75, 75 ) * 2, RANDOM_FLOAT( 0, 40 ) * 5 );

	Spawn();
	UTIL_SetOrigin( pev, vecSrc );
	pev->velocity = vecVelocity;
	TF_GrenadeRing( pev, pMirvGren->team_no );
	pev->avelocity = g_vecZero;
	pev->angles = UTIL_VecToAngles( pev->velocity );
	pev->owner = pMirvGren->pev->owner;

	SetTouch( &CGrenade::BounceTouch );
	team_no = pMirvGren->team_no;
	pev->dmgtime = gpGlobals->time + 2 + RANDOM_FLOAT( 0, 1 );
	SetThink( &CGrenade::TumbleThink );
	pev->nextthink = gpGlobals->time + 0.1;

	pev->sequence = RANDOM_LONG( 3, 6 );
	pev->framerate = 1.0;
	pev->gravity = 0.5;
	pev->friction = 0.8;
	pev->solid = SOLID_TRIGGER;

	UTIL_SetOrigin( pev, vecSrc );
}

void CTFBomblet::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( !m_usExplode )
		m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_normalgren.sc" );

	CGrenade::Explode( pTrace, bitsDamageType | DMG_RADIUS_QUAKE );
}

void CTFBomblet::setModel( void )
{
	SET_MODEL( ENT( pev ), "models/bomblet.mdl" );
}

//=========================================================
// Nail grenade: rises, spins and sprays nails, then explodes
//=========================================================
void CTFNailGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/ngrenade.mdl" );
}

CGrenade *CTFNailGrenade::Prime( CBaseEntity *pOwner )
{
	CTFNailGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFNailGrenade *)NULL );
		pGrenade->pev->classname = MAKE_STRING( "nailgrenade" );
		pGrenade->deathtype = MAKE_STRING( "nailgrenade" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFNailGrenade::FinishedExplode( void )
{
	TraceResult tr;
	Vector vecSpot = pev->origin + Vector( 0, 0, 8 );
	UTIL_TraceLine( vecSpot, vecSpot + Vector( 0, 0, -40 ), ignore_monsters, ENT( pev ), &tr );

	if ( !m_usExplode )
		m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_ng.sc" );

	CGrenade::Explode( &tr, DMG_BLAST | DMG_RADIUS_QUAKE );

	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );
}

void CTFNailGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( InNoGrenadeZone( pev->origin ) )
		return;

	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	// Float up a bit
	pev->movetype = MOVETYPE_FLY;
	pev->solid = SOLID_NOT;

	TraceResult tr;
	UTIL_TraceLine( pev->origin, pev->origin + Vector( 0, 0, 32 ), ignore_monsters, ENT( pev ), &tr );
	UTIL_SetOrigin( pev, tr.vecEndPos );

	SetTouch( NULL );
	pev->flags &= ~FL_ONGROUND;
	pev->angles = g_vecZero;
	pev->effects |= EF_NOINTERP;
	pev->velocity = g_vecZero;

	pev->nextthink = gpGlobals->time + 0.4;
	SetThink( &CTFNailGrenade::NailGrenadeNailEm );
}

void CTFNailGrenade::NailGrenadeNailEm( void )
{
	pev->nextthink = gpGlobals->time + 0.1;
	SetThink( &CTFNailGrenade::NailGrenadeLaunchNail );
	pev->playerclass = 0;	// counts the bursts
}

// 4 nails every 0.1s, turning 30-40 degrees each time, 40 bursts
void CTFNailGrenade::NailGrenadeLaunchNail( void )
{
	float j = RANDOM_FLOAT( 30, 40 );

	{
		static unsigned short m_usNailGrenade = 0;
		if ( !m_usNailGrenade )
			m_usNailGrenade = PRECACHE_EVENT( 1, "events/explode/tf_nailgren.sc" );

		// The client draws the nails from the angle and owner packed in iparam1
		int owner = ENTINDEX( pev->owner ) - 1;
		int angle = (int)( pev->angles.y * 4 ) & 0x7FF;
		unsigned short usVal = 0;
		if ( owner >= 0 && owner < gpGlobals->maxClients )
			usVal = (short)( owner << 11 );

		PLAYBACK_EVENT_FULL( 0, edict(), m_usNailGrenade, 0.0, (float *)&g_vecZero, (float *)&g_vecZero, j, 0.0, angle | usVal, 0, 0, 0 );
	}

	for ( int i = 0; i < 4; i++ )
	{
		pev->angles.y = UTIL_AngleMod( pev->angles.y + j );
		UTIL_MakeVectors( pev->angles );
		Vector nailorigin = pev->origin + gpGlobals->v_forward * 12;

		CTFNailgunNail::CreateNailGrenNail( nailorigin, pev->angles, this, this );
	}

	pev->playerclass++;
	pev->nextthink = gpGlobals->time + 0.1;

	if ( pev->playerclass > 40 )
		SetThink( &CTFNailGrenade::FinishedExplode );
}

void CTFNailGrenade::Precache( void )
{
	g_sModelIndexNailGrenade = PRECACHE_MODEL( "models/ngrenade.mdl" );
}

//=========================================================
// Caltrop canister: opens straight away, scatters 6 caltrops
//=========================================================
void CTFCaltropGrenade::InitPriming( CBaseEntity *pOwner )
{
	pev->owner = pOwner->edict();
	SetThink( &CTFCaltropGrenade::CaltropGrenadePrimed );
	pev->nextthink = gpGlobals->time + getPinTime();
	heat = gpGlobals->time + getPrimeTime() + getPinTime();
	team_no = pOwner->team_no;
	TF_GrenadeRing( pev, team_no );

	if ( pOwner->m_iszGrenadeName )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusIcon, NULL, pOwner->edict() );
			WRITE_BYTE( 0 );
			WRITE_CHAR( 100 );
			WRITE_CHAR( 95 );
			WRITE_STRING( pOwner->m_iszGrenadeName ? STRING( pOwner->m_iszGrenadeName ) : "normalgrenade" );
			WRITE_BYTE( 255 );
			WRITE_BYTE( 160 );
			WRITE_BYTE( 0 );
		MESSAGE_END();
	}

	pOwner->m_iszGrenadeName = pev->classname;
}

void CTFCaltropGrenade::CaltropGrenadePrimed( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	if ( pOwner->bRemoveGrenade )
	{
		pOwner->tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );
		pOwner->bRemoveGrenade = FALSE;
		dremove( this );
		return;
	}

	if ( !( pOwner->tfstate & TFSTATE_GRENTHROWING ) )
	{
		pev->nextthink = gpGlobals->time + 0.1;
		if ( gpGlobals->time <= heat )
			return;
	}

	pOwner->tfstate &= ~( TFSTATE_GRENPRIMED | TFSTATE_GRENTHROWING );

	pev->velocity = g_vecZero;
	pev->avelocity = g_vecZero;
	setDamage();
	pev->dmgtime = heat;

	SetThink( &CGrenade::Detonate );
	pev->nextthink = gpGlobals->time;

	pev->sequence = RANDOM_LONG( 3, 6 );
	pev->framerate = 1.0;
	pev->gravity = 0.5;
	pev->friction = 0.8;

	setModel();
}

CGrenade *CTFCaltropGrenade::Prime( CBaseEntity *pOwner )
{
	CTFCaltropGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFCaltropGrenade *)NULL );
		pGrenade->pev->classname = MAKE_STRING( "caltrop" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFCaltropGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	CBaseEntity *pEntity = CBaseEntity::Instance( pev->owner );
	if ( pEntity && InNoGrenadeZone( pEntity->pev->origin ) )
		return;

	ClientPrint( VARS( pev->owner ), HUD_PRINTNOTIFY, "#Caltrop_exc" );

	for ( int i = 0; i < 6; i++ )
	{
		CTFCaltrop *pc = GetClassPtr( (CTFCaltrop *)NULL );
		pc->ScatterDrop( CBaseEntity::Instance( pev->owner ) );
	}

	UTIL_Remove( this );
}

// Not affected by EMP
void CTFCaltropGrenade::TakeEMPBlast( entvars_t *pevGren )
{
}

void CTFCaltropGrenade::Precache( void )
{
	PRECACHE_MODEL( "models/presentsm.mdl" );
	g_sModelIndexGrenade = PRECACHE_MODEL( "models/w_grenade.mdl" );
	PRECACHE_MODEL( "models/v_grenade.mdl" );
	PRECACHE_MODEL( "models/p_grenade.mdl" );
	PRECACHE_MODEL( "models/p_grenade2.mdl" );
	PRECACHE_MODEL( "models/w_grenadeT.mdl" );
}

void CTFCaltropGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/w_grenade.mdl" );
}

void CTFCaltrop::ScatterDrop( CBaseEntity *pThrower )
{
	Vector vecSrc;

	if ( !pThrower )
	{
		vecSrc = g_vecZero;
		Spawn();
		pev->classname = MAKE_STRING( "tf_weapon_caltrop" );
	}
	else
	{
		vecSrc = pThrower->pev->origin;
		Spawn();
		team_no = pThrower->team_no;
		pev->classname = MAKE_STRING( "tf_weapon_caltrop" );
		pev->owner = pThrower->edict();
	}

	SET_MODEL( ENT( pev ), "models/caltrop.mdl" );
	UTIL_SetSize( pev, Vector( -4, -4, -8 ), Vector( 4, 4, 4 ) );

	pev->angles = g_vecZero;
	pev->angles.x = RANDOM_FLOAT( 0, 360 );
	// the original evaluates these right to left: z, y, x
	pev->velocity.z = RANDOM_FLOAT( 150, 200 );
	pev->velocity.y = RANDOM_FLOAT( -150, 150 );
	pev->velocity.x = RANDOM_FLOAT( -150, 150 );
	pev->avelocity.z = RANDOM_FLOAT( -400, 400 );
	pev->avelocity.y = RANDOM_FLOAT( -400, 400 );
	pev->avelocity.x = RANDOM_FLOAT( -400, 400 );
	pev->gravity = 0.5;
	pev->friction = 0.8;
	pev->movetype = MOVETYPE_TOSS;
	pev->solid = SOLID_TRIGGER;

	UTIL_SetOrigin( pev, vecSrc );

	m_flRemovalTime = gpGlobals->time + RANDOM_FLOAT( 10, 15 );
	SetThink( &CTFCaltrop::CaltropScatterThink );
	pev->nextthink = gpGlobals->time;
}

void CTFCaltrop::setModel( void )
{
	SET_MODEL( ENT( pev ), "models/caltrop.mdl" );
}

// Players walking on them take 10 and get leg damage
void CTFCaltrop::CaltropTouch( CBaseEntity *pOther )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	if ( !pOther->IsPlayer() || !( pOther->pev->flags & FL_ONGROUND ) )
		return;
	if ( !pOther->IsAlive() )
		return;

	if ( !IsAlly( pOther ) || pOther == pOwner
		|| !( (int)gpGlobals->teamplay & ( TEAMPLAY_HALFDIRECT | TEAMPLAY_NODIRECT | TEAMPLAY_HALFEXPLOSIVE | TEAMPLAY_NOEXPLOSIVE ) ) )
	{
		pOther->leg_damage += 2;
		((CBasePlayer *)pOther)->TeamFortress_SetSpeed();
		pOther->TakeDamage( pev, VARS( pev->owner ), 10, DMG_CALTROP );

		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Caltrop_Grenade\" against \"%s<%i><%s><%s>\"\n",
			STRING( pOwner->pev->netname ),
			GETPLAYERUSERID( pev->owner ),
			GETPLAYERAUTHID( pev->owner ),
			pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR",
			STRING( pOther->pev->netname ),
			GETPLAYERUSERID( pOther->edict() ),
			GETPLAYERAUTHID( pOther->edict() ),
			pOther->team_no ? GetTeamName( pOther->team_no ) : "SPECTATOR" );
	}

	UTIL_Remove( this );
}

void CTFCaltrop::CanisterTouch( CBaseEntity *pOther )
{
	if ( pev->velocity == g_vecZero )
		pev->avelocity = g_vecZero;
}

// Become sharp once landed
void CTFCaltrop::CaltropScatterThink( void )
{
	pev->nextthink = gpGlobals->time + 0.2;

	if ( m_flRemovalTime < gpGlobals->time )
	{
		SetThink( &CBaseEntity::SUB_Remove );
		return;
	}

	if ( !( pev->flags & FL_ONGROUND ) )
	{
		SetTouch( &CTFCaltrop::CanisterTouch );
		return;
	}

	pev->solid = SOLID_TRIGGER;
	SetTouch( &CTFCaltrop::CaltropTouch );
	pev->angles = Vector( 90, 90, 90 );
	pev->avelocity = g_vecZero;
	pev->velocity = pev->avelocity;
	UTIL_SetOrigin( pev, pev->origin );
}

void CTFCaltrop::Precache( void )
{
	PRECACHE_MODEL( "models/caltrop.mdl" );
}

//=========================================================
// Napalm grenade: burns for 7 seconds
//=========================================================
CGrenade *CTFNapalmGrenade::Prime( CBaseEntity *pOwner )
{
	CTFNapalmGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFNapalmGrenade *)NULL );
		pGrenade->numExplosionsLeft = 7;
		pGrenade->pev->classname = MAKE_STRING( "napalmgrenade" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFNapalmGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( InNoGrenadeZone( pev->origin ) )
		return;

	pev->solid = SOLID_NOT;
	pev->takedamage = DAMAGE_NO;
	m_bitsDamageType = bitsDamageType;
	m_flDamageTime = gpGlobals->time;
	m_flEffectTime = gpGlobals->time;

	CSoundEnt::InsertSound( bits_SOUND_COMBAT, pev->origin, NORMAL_EXPLOSION_VOLUME, 0.5 );

	pev->velocity = g_vecZero;

	// Pull out of the wall
	Vector OldPos = pev->origin;
	if ( pTrace->flFraction != 1.0 )
	{
		float flOffset = pev->dmg;
		if ( flOffset >= 24 )
			flOffset -= 24;
		pev->origin = pTrace->vecEndPos + pTrace->vecPlaneNormal * flOffset * 0.6;
	}

	int iContents = UTIL_PointContents( pev->origin );
	if ( iContents == CONTENTS_SOLID )
	{
		pev->origin = OldPos;
		if ( UTIL_PointContents( pev->origin ) == CONTENTS_SOLID )
		{
			UTIL_Remove( this );
			return;
		}
	}

	if ( !m_usExplode )
		m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_fire.sc" );

	PLAYBACK_EVENT_FULL( 0, NULL, m_usExplode, 0.0, (float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

	pev->effects |= EF_NODRAW;
	SetThink( &CTFNapalmGrenade::Burn );
	pev->nextthink = gpGlobals->time;
}

void CTFNapalmGrenade::Burn( void )
{
	pev->nextthink = gpGlobals->time + 0.1;

	// Damage once a second
	if ( m_flDamageTime <= gpGlobals->time )
	{
		EMIT_SOUND( ENT( pev ), CHAN_WEAPON, "ambience/fire1.wav", 1, ATTN_NORM );

		::RadiusDamage( pev->origin, pev, VARS( pev->owner ), pev->dmg, blastRadius, CLASS_NONE, m_bitsDamageType | DMG_IGNITE | DMG_RADIUS_MAX );

		CBaseEntity *pEnt = CBaseEntity::Instance( pev->owner );

		if ( --numExplosionsLeft < 1 )
			UTIL_Remove( this );
		else
			m_flDamageTime += 1;
	}

	// Flames every half second
	if ( m_flEffectTime <= gpGlobals->time )
	{
		static unsigned short m_usBurn = 0;
		if ( !m_usBurn )
			m_usBurn = PRECACHE_EVENT( 1, "events/explode/tf_burn.sc" );

		PLAYBACK_EVENT_FULL( 0, edict(), m_usBurn, 0.0, (float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );
		m_flEffectTime += 0.5;
	}
}

void CTFNapalmGrenade::Precache( void )
{
	PRECACHE_SOUND( "weapons/flmgrexp.wav" );
	g_sModelIndexNapalmGrenade = PRECACHE_MODEL( "models/napalm.mdl" );
}

void CTFNapalmGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/napalm.mdl" );
}

//=========================================================
// EMP grenade
//=========================================================
CGrenade *CTFEMPGrenade::Prime( CBaseEntity *pOwner )
{
	CTFEMPGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFEMPGrenade *)NULL );
		pGrenade->pev->classname = MAKE_STRING( "empgrenade" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFEMPGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( InNoGrenadeZone( pev->origin ) )
		return;

	if ( !m_usExplode )
		m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_emp.sc" );

	PLAYBACK_EVENT_FULL( 0, NULL, m_usExplode, 0.0, (float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );

	pev->solid = SOLID_NOT;
	UTIL_SetOrigin( pev, pev->origin );

	CBaseEntity *pEntity = NULL;
	while ( ( pEntity = UTIL_FindEntityInSphere( pEntity, pev->origin, blastRadius ) ) != NULL )
		pEntity->TeamFortress_TakeEMPBlast( pev );

	UTIL_Remove( this );
}

void CTFEMPGrenade::Precache( void )
{
	BlastTexture = PRECACHE_MODEL( "sprites/shockwave.spr" );
	PRECACHE_SOUND( "weapons/emp_1.wav" );
	PRECACHE_MODEL( "models/emp_grenade.mdl" );
	m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_emp.sc" );
}

void CTFEMPGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/emp_grenade.mdl" );
}

//=========================================================
// Hallucination gas grenade
//=========================================================
CGrenade *CTFGasGrenade::Prime( CBaseEntity *pOwner )
{
	CTFGasGrenade *pGrenade = NULL;

	if ( canPrime( pOwner ) )
	{
		pGrenade = GetClassPtr( (CTFGasGrenade *)NULL );
		pGrenade->pev->classname = MAKE_STRING( "gasgrenade" );
		pGrenade->InitPriming( pOwner );
	}

	return pGrenade;
}

void CTFGasGrenade::Explode( TraceResult *pTrace, int bitsDamageType )
{
	if ( InNoGrenadeZone( pev->origin ) )
		return;

	gasCharges = 20;
	SetThink( &CTFGasGrenade::GasThePlace );
	pev->nextthink = gpGlobals->time + 0.1;
}

// 20 puffs, 0.75s apart
void CTFGasGrenade::GasThePlace( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	if ( !( gasCharges & 1 ) )
	{
		if ( !m_usExplode )
			m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_gas.sc" );

		PLAYBACK_EVENT_FULL( 0, NULL, m_usExplode, 0.0, (float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, 0, 0, 0, 0 );
	}

	CBaseEntity *pEntity = NULL;
	while ( ( pEntity = UTIL_FindEntityInSphere( pEntity, pev->origin, blastRadius ) ) != NULL )
	{
		if ( !pEntity->pev->playerclass )
			continue;

		pEntity->TakeDamage( pev, VARS( pev->owner ), 10, DMG_HALLUC | DMG_RADIUS_QUAKE | DMG_NEVERGIB );

		if ( !pEntity->IsPlayer() )
			continue;

		if ( IsAlly( pEntity ) && pEntity != pOwner
			&& ( (int)gpGlobals->teamplay & ( TEAMPLAY_HALFDIRECT | TEAMPLAY_NODIRECT | TEAMPLAY_HALFEXPLOSIVE | TEAMPLAY_NOEXPLOSIVE ) ) )
			continue;

		if ( !( pEntity->tfstate & TFSTATE_HALLUCINATING ) )
		{
			pEntity->tfstate |= TFSTATE_HALLUCINATING;

			CBaseEntity *pTimer = pEntity->CreateTimer( TF_TIMER_HALLUCINATION );
			pTimer->pev->nextthink = gpGlobals->time + 0.3;
			pTimer->SetThink( &CBaseEntity::Timer_Hallucination );
			pTimer->pev->owner = pEntity->edict();
			pTimer->pev->health = 150;
			pTimer->team_no = pEntity->team_no;

			CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Hallucination_Grenade\" against \"%s<%i><%s><%s>\"\n",
				STRING( pOwner->pev->netname ),
				GETPLAYERUSERID( pev->owner ),
				GETPLAYERAUTHID( pev->owner ),
				pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR",
				STRING( pEntity->pev->netname ),
				GETPLAYERUSERID( pEntity->edict() ),
				GETPLAYERAUTHID( pEntity->edict() ),
				pEntity->team_no ? GetTeamName( pEntity->team_no ) : "SPECTATOR" );
		}
		else
		{
			// Already tripping: top it up (sic: at least 150, not +25 capped)
			CBaseEntity *pTimer = pEntity->FindTimer( TF_TIMER_HALLUCINATION );
			if ( pTimer && pTimer->pev && !FNullEnt( pTimer->edict() ) )
			{
				pTimer->pev->health += 25;
				if ( pTimer->pev->health < 150 )
					pTimer->pev->health = 150;
				pTimer->pev->nextthink = gpGlobals->time + 0.3;
			}
		}
	}

	if ( --gasCharges == 0 )
	{
		UTIL_Remove( this );
		return;
	}

	pev->nextthink = gpGlobals->time + 0.75;
}

void CTFGasGrenade::Precache( void )
{
	PRECACHE_MODEL( "models/spy_grenade.mdl" );
}

void CTFGasGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/spy_grenade.mdl" );
}
