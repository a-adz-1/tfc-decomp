/***
*
*	Team Fortress Classic: projectiles (nails, rockets, flame bursts,
*	grenade launcher grenades and pipebombs, laser spot)
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
#include "gamerules.h"
#include "tf_defs.h"

extern short sModelIndexFlameThrowerFlame;

LINK_ENTITY_TO_CLASS( tf_nailgun_nail, CTFNailgunNail );

// Work out where a rocket will hit and when, for client side prediction
void UTIL_ParametricRocket( entvars_t *pev, Vector vecOrigin, Vector vecAngles, edict_t *owner )
{
	pev->startpos = vecOrigin;

	// Trace out line to end pos
	TraceResult tr;
	UTIL_MakeVectors( vecAngles );
	UTIL_TraceLine( pev->startpos, pev->startpos + gpGlobals->v_forward * 8192, ignore_monsters, owner, &tr );
	pev->endpos = tr.vecEndPos;

	// Now compute how long it will take based on current velocity
	Vector vecTravel = pev->endpos - pev->startpos;
	float travelTime = 0.0;
	if ( pev->velocity.Length() > 0 )
		travelTime = vecTravel.Length() / pev->velocity.Length();

	pev->starttime = gpGlobals->time;
	pev->impacttime = gpGlobals->time + travelTime;
}

//=========================================================
// Nails
//=========================================================
CTFNailgunNail *CTFNailgunNail::CreateNail( BOOL fSendClientNail, Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher, BOOL fMakeClientNail )
{
	CTFNailgunNail *pNail = GetClassPtr( (CTFNailgunNail *)NULL );

	UTIL_SetOrigin( pNail->pev, vecOrigin );
	pNail->pev->angles = vecAngles;
	pNail->pev->owner = pOwner->edict();
	pNail->Spawn();
	pNail->SetTouch( &CTFNailgunNail::NailTouch );
	pNail->pev->dmg = 9;

	if ( fMakeClientNail )
	{
		// The client draws its own predicted nail
		pNail->pev->effects |= EF_NODRAW;

		edict_t *pOwner = pNail->pev->owner;
		int indexOwner = ENTINDEX( pOwner );

		if ( fSendClientNail )
			UTIL_ClientProjectile( pNail->pev->origin, pNail->pev->velocity, g_sModelIndexNail, indexOwner, 6 );
	}

	return pNail;
}

CTFNailgunNail *CTFNailgunNail::CreateSuperNail( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher )
{
	CTFNailgunNail *pNail = CreateNail( FALSE, vecOrigin, vecAngles, pOwner, pLauncher, TRUE );
	pNail->deathtype = MAKE_STRING( "supernails" );
	pNail->pev->dmg = 13;
	return pNail;
}

// pOwner is the nail grenade; its owner gets the kills
CTFNailgunNail *CTFNailgunNail::CreateNailGrenNail( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pNailGren )
{
	CBaseEntity *pRealOwner = CBaseEntity::Instance( pOwner->pev->owner );

	CTFNailgunNail *pNail = CreateNail( FALSE, vecOrigin, vecAngles, pRealOwner, pNailGren, TRUE );
	pNail->real_owner = pRealOwner;
	pNail->pev->owner = pOwner->edict();	// don't hit the grenade
	pNail->pev->classname = MAKE_STRING( "tf_weapon_nailgrenadenail" );
	pNail->deathtype = MAKE_STRING( "nailgrenade" );
	pNail->pev->dmg = 18;
	pNail->team_no = pOwner->team_no;
	return pNail;
}

CTFNailgunNail *CTFNailgunNail::CreateTranqNail( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher )
{
	CTFNailgunNail *pNail = CreateNail( FALSE, vecOrigin, vecAngles, pOwner, pLauncher, FALSE );

	UTIL_MakeVectors( pNail->pev->angles );
	pNail->pev->velocity = gpGlobals->v_forward * 1500;

	pNail->pev->effects |= EF_NODRAW;
	edict_t *pNailAvoid = pNail->pev->owner;
	int indexOwner = ENTINDEX( pNailAvoid );

	pNail->SetTouch( &CTFNailgunNail::TranqTouch );
	return pNail;
}

CTFNailgunNail *CTFNailgunNail::CreateRailgunNail( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher )
{
	CTFNailgunNail *pNail = CreateNail( FALSE, vecOrigin, vecAngles, pOwner, pLauncher, FALSE );

	pNail->SetTouch( &CTFNailgunNail::RailgunNailTouch );
	pNail->deathtype = MAKE_STRING( "railgun" );

	UTIL_MakeVectors( vecAngles );
	pNail->pev->velocity = gpGlobals->v_forward * 1500;
	pNail->m_vecPreviousVelocity = pNail->pev->velocity;

	pNail->pev->effects |= EF_NODRAW;
	edict_t *pNailAvoid = pNail->pev->owner;
	int indexOwner = ENTINDEX( pNailAvoid );

	return pNail;
}

void CTFNailgunNail::Spawn( void )
{
	Precache();

	pev->movetype = MOVETYPE_FLYMISSILE;
	pev->solid = SOLID_BBOX;

	SET_MODEL( ENT( pev ), "models/rpgrocket.mdl" );
	UTIL_SetSize( pev, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
	UTIL_SetOrigin( pev, pev->origin );

	pev->classname = MAKE_STRING( "tf_nailgun_nail" );
	deathtype = MAKE_STRING( "nails" );

	UTIL_MakeVectors( pev->angles );
	pev->velocity = gpGlobals->v_forward * 1000;
	pev->gravity = 0.5;

	pev->nextthink = gpGlobals->time + 6;
	SetThink( &CBaseEntity::SUB_Remove );
}

void CTFNailgunNail::NailTouch( CBaseEntity *pOther )
{
	entvars_t *pevOwner;

	// Nail grenade nails credit the thrower
	if ( real_owner )
		pevOwner = real_owner->pev;
	else
		pevOwner = VARS( pev->owner );

	if ( pOther && pOther->pev->takedamage )
	{
		if ( pOther->TakeDamage( pev, pevOwner, pev->dmg, DMG_SLASH ) )
			SpawnBlood( pev->origin, pOther->BloodColor(), pev->dmg );
	}

	// Nails pass through each other
	if ( pOther->pev->modelindex != pev->modelindex )
		SUB_Remove();
}

void CTFNailgunNail::Precache( void )
{
	PRECACHE_MODEL( "models/rpgrocket.mdl" );
	PRECACHE_SOUND( "weapons/rocket1.wav" );
}

void CTFNailgunNail::RailgunNailTouch( CBaseEntity *pOther )
{
	if ( pOther->pev->takedamage )
	{
		CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );
		CBaseEntity *pEnemy = CBaseEntity::Instance( pev->enemy );

		if ( pOther->TakeDamage( pev, pOwner->pev, 25, DMG_ENERGYBEAM ) )
			SpawnBlood( pev->origin, pOther->BloodColor(), pev->dmg );
	}

	SUB_Remove();
}

void CTFNailgunNail::RailgunNail_Think( void )
{
	pev->velocity = pev->oldorigin;
	SetTouch( &CTFNailgunNail::RailgunNailTouch );
	pev->nextthink = gpGlobals->time + 1;
	SetThink( &CBaseEntity::SUB_Remove );
}

//=========================================================
// Flamethrower burst (invisible; the client draws the flame)
//=========================================================
LINK_ENTITY_TO_CLASS( tf_flamethrower_burst, CTFFlamethrowerBurst );

CTFFlamethrowerBurst *CTFFlamethrowerBurst::CreateBurst( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFFlamethrower *pLauncher )
{
	CTFFlamethrowerBurst *pBurst = GetClassPtr( (CTFFlamethrowerBurst *)NULL );

	UTIL_SetOrigin( pBurst->pev, vecOrigin );
	pBurst->pev->angles = vecAngles;
	pBurst->pev->owner = pOwner->edict();
	pBurst->Spawn();
	pBurst->SetTouch( &CTFFlamethrowerBurst::BurstTouch );

	return pBurst;
}

void CTFFlamethrowerBurst::Spawn( void )
{
	Precache();

	pev->movetype = MOVETYPE_FLYMISSILE;
	pev->solid = SOLID_BBOX;

	SET_MODEL( ENT( pev ), "models/rpgrocket.mdl" );
	pev->effects |= EF_NODRAW;
	UTIL_SetSize( pev, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
	UTIL_SetOrigin( pev, pev->origin );

	pev->classname = MAKE_STRING( "tf_flamethrower_burst" );
	deathtype = MAKE_STRING( "flames" );

	pev->angles.x -= 30;
	UTIL_MakeVectors( pev->angles );
	pev->angles.x = -( pev->angles.x + 30 );
	UTIL_MakeAimVectors( pev->angles );

	pev->velocity = gpGlobals->v_forward * 600;
	pev->gravity = 0.5;

	edict_t *pOwner = pev->owner;
	int indexOwner = ENTINDEX( pOwner );

	pev->nextthink = gpGlobals->time + 1;
	SetThink( &CBaseEntity::SUB_Remove );
}

void CTFFlamethrowerBurst::BurstTouch( CBaseEntity *pOther )
{
	entvars_t *pevOwner = VARS( pev->owner );

	if ( pOther && pOther->pev->takedamage )
		pOther->TakeDamage( pev, pevOwner, 15, DMG_BURN | DMG_IGNITE );

	SUB_Remove();
}

void CTFFlamethrowerBurst::Precache( void )
{
	PRECACHE_MODEL( "models/rpgrocket.mdl" );
	m_iTrail = PRECACHE_MODEL( "sprites/smoke.spr" );
	PRECACHE_SOUND( "weapons/rocket1.wav" );
	sModelIndexFlameThrowerFlame = PRECACHE_MODEL( "sprites/fthrow.spr" );
}

//=========================================================
// Incendiary cannon rocket
//=========================================================
CTFIncendiaryCRocket *CTFIncendiaryCRocket::CreateRpgRocket( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFIncendiaryC *pLauncher )
{
	CTFIncendiaryCRocket *pRocket = GetClassPtr( (CTFIncendiaryCRocket *)NULL );

	UTIL_SetOrigin( pRocket->pev, vecOrigin );
	pRocket->pev->angles = vecAngles;
	pRocket->Spawn();
	pRocket->SetTouch( &CTFIncendiaryCRocket::RocketTouch );
	pRocket->pev->owner = pOwner->edict();
	pRocket->pev->effects |= EF_LIGHT;

	// red trail
	MESSAGE_BEGIN( MSG_BROADCAST, SVC_TEMPENTITY );
		WRITE_BYTE( TE_BEAMFOLLOW );
		WRITE_SHORT( pRocket->entindex() );	// entity
		WRITE_SHORT( pRocket->m_iTrail );	// model
		WRITE_BYTE( 30 );	// life
		WRITE_BYTE( 5 );	// width
		WRITE_BYTE( 224 );	// r, g, b
		WRITE_BYTE( 32 );
		WRITE_BYTE( 32 );
		WRITE_BYTE( 200 );	// brightness
	MESSAGE_END();

	UTIL_ParametricRocket( pRocket->pev, vecOrigin, vecAngles, pOwner->edict() );

	return pRocket;
}

void CTFIncendiaryCRocket::Spawn( void )
{
	Precache();

	pev->movetype = MOVETYPE_FLYMISSILE;
	pev->solid = SOLID_BBOX;

	SET_MODEL( ENT( pev ), "models/rpgrocket.mdl" );
	UTIL_SetSize( pev, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
	UTIL_SetOrigin( pev, pev->origin );

	pev->classname = MAKE_STRING( "tf_rpg_rocket" );	// sic: same as the RPG's
	deathtype = MAKE_STRING( "rocket" );

	pev->angles.x -= 30;
	UTIL_MakeVectors( pev->angles );
	pev->angles.x = -( pev->angles.x + 30 );
	UTIL_MakeAimVectors( pev->angles );

	pev->velocity = gpGlobals->v_forward * 600;
	pev->gravity = 0.5;

	pev->nextthink = gpGlobals->time + 5;
	SetThink( &CBaseEntity::SUB_Remove );
}

void CTFIncendiaryCRocket::RocketTouch( CBaseEntity *pOther )
{
	pev->dmg = RANDOM_FLOAT( 0, 20 ) + 10;
	m_flExplosionScale = pev->dmg * 0.5;
	m_bDontSpark = TRUE;
	m_flSmokeScale = pev->dmg + 30;

	entvars_t *pevOwner = VARS( pev->owner );

	// Direct hit sets them alight
	if ( pOther && pOther->pev->takedamage )
		pOther->TakeDamage( pev, pevOwner, pev->dmg, DMG_BLAST | DMG_IGNITE );

	STOP_SOUND( edict(), CHAN_VOICE, "weapons/rocket1.wav" );
	ExplodeTouch( pOther );
}

void CTFIncendiaryCRocket::RadiusDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType )
{
	::RadiusDamage( pev->origin, pevInflictor, pevAttacker, 15, 180, iClassIgnore, bitsDamageType | DMG_IGNITE | DMG_RADIUS_MAX | DMG_WALLPIERCING );
}

void CTFIncendiaryCRocket::Precache( void )
{
	PRECACHE_MODEL( "models/rpgrocket.mdl" );
	m_iTrail = PRECACHE_MODEL( "sprites/smoke.spr" );
	PRECACHE_SOUND( "weapons/rocket1.wav" );
	PRECACHE_SOUND( "weapons/sgun1.wav" );
	UTIL_PrecacheOther( "tf_flame" );
}

//=========================================================
// RPG rocket
//=========================================================
CTFRpgRocket *CTFRpgRocket::CreateRpgRocket( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFRpg *pLauncher )
{
	CTFRpgRocket *pRocket = GetClassPtr( (CTFRpgRocket *)NULL );

	UTIL_SetOrigin( pRocket->pev, vecOrigin );
	pRocket->pev->angles = vecAngles;
	pRocket->Spawn();
	pRocket->SetTouch( &CTFRpgRocket::RocketTouch );
	pRocket->pev->owner = pOwner->edict();
	pRocket->pev->effects |= EF_LIGHT;

	// rocket trail
	MESSAGE_BEGIN( MSG_BROADCAST, SVC_TEMPENTITY );
		WRITE_BYTE( TE_BEAMFOLLOW );
		WRITE_SHORT( pRocket->entindex() );	// entity
		WRITE_SHORT( pRocket->m_iTrail );	// model
		WRITE_BYTE( 10 );	// life
		WRITE_BYTE( 5 );	// width
		WRITE_BYTE( 224 );	// r, g, b
		WRITE_BYTE( 224 );
		WRITE_BYTE( 255 );
		WRITE_BYTE( 128 );	// brightness
	MESSAGE_END();

	UTIL_ParametricRocket( pRocket->pev, vecOrigin, vecAngles, pOwner->edict() );

	return pRocket;
}

void CTFRpgRocket::Spawn( void )
{
	Precache();

	pev->movetype = MOVETYPE_FLYMISSILE;
	pev->solid = SOLID_BBOX;
	m_bDontSpark = TRUE;
	m_bDontSmoke = TRUE;

	SET_MODEL( ENT( pev ), "models/rpgrocket.mdl" );
	UTIL_SetSize( pev, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
	UTIL_SetOrigin( pev, pev->origin );

	pev->classname = MAKE_STRING( "tf_rpg_rocket" );
	deathtype = MAKE_STRING( "rocket" );

	pev->angles.x -= 30;
	UTIL_MakeVectors( pev->angles );
	pev->angles.x = -( pev->angles.x + 30 );
	UTIL_MakeAimVectors( pev->angles );

	pev->velocity = gpGlobals->v_forward * 900;
	pev->gravity = 0.5;

	pev->nextthink = gpGlobals->time + 5;
	SetThink( &CBaseEntity::SUB_Remove );
}

void CTFRpgRocket::RocketTouch( CBaseEntity *pOther )
{
	pev->dmg = RANDOM_FLOAT( 0, 20 ) + 92;
	STOP_SOUND( edict(), CHAN_VOICE, "weapons/rocket1.wav" );
	ExplodeTouch( pOther );
}

void CTFRpgRocket::RadiusDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType )
{
	::RadiusDamage( pev->origin, pevInflictor, pevAttacker, flDamage, flDamage, iClassIgnore, bitsDamageType | DMG_RADIUS_QUAKE );
}

void CTFRpgRocket::Precache( void )
{
	PRECACHE_MODEL( "models/rpgrocket.mdl" );
	m_iTrail = PRECACHE_MODEL( "sprites/smoke.spr" );
	PRECACHE_SOUND( "weapons/rocket1.wav" );
}

//=========================================================
// Rocket ammo box
//=========================================================
class CTFRpgAmmo : public CBasePlayerAmmo
{
	void Spawn( void );
	void Precache( void );
	BOOL AddAmmo( CBaseEntity *pOther );
};

void CTFRpgAmmo::Spawn( void )
{
	Precache();
	SET_MODEL( ENT( pev ), "models/w_rpgammo.mdl" );
	CBasePlayerAmmo::Spawn();
}

void CTFRpgAmmo::Precache( void )
{
	PRECACHE_MODEL( "models/w_rpgammo.mdl" );
	PRECACHE_SOUND( "items/9mmclip1.wav" );
}

BOOL CTFRpgAmmo::AddAmmo( CBaseEntity *pOther )
{
	int iGive;

	if ( g_pGameRules->IsMultiplayer() )
		iGive = 2;	// hand out more ammo per rocket in multiplayer
	else
		iGive = 1;

	if ( pOther->GiveAmmo( iGive, "rockets", 5 ) != -1 )
	{
		EMIT_SOUND( ENT( pev ), CHAN_ITEM, "items/9mmclip1.wav", 1, ATTN_NORM );
		return TRUE;
	}
	return FALSE;
}

LINK_ENTITY_TO_CLASS( tf_ammo_rpgclip, CTFRpgAmmo );

//=========================================================
// Grenade launcher grenades and pipebombs
//=========================================================
LINK_ENTITY_TO_CLASS( tf_gl_grenade, CTFGrenade );

// Birthday mode: half the grenades are presents
BOOL CGrenade::setBirthdayModel( void )
{
	if ( birthday && RANDOM_FLOAT( 0, 1 ) < 0.5 )
	{
		SET_MODEL( ENT( pev ), "models/presentsm.mdl" );
		return TRUE;
	}
	return FALSE;
}

void CGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
		SET_MODEL( ENT( pev ), "models/w_grenade.mdl" );
}

CTFGrenade *CTFGrenade::CreateTFGrenade( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFGrenadeLauncher *pLauncher )
{
	CTFGrenade *pGrenade = GetClassPtr( (CTFGrenade *)NULL );

	UTIL_SetOrigin( pGrenade->pev, vecOrigin );
	pGrenade->pev->angles = vecAngles;
	pGrenade->Spawn();
	pGrenade->SetTouch( &CTFGrenade::GrenadeTouch );
	pGrenade->pev->owner = pOwner->edict();
	pGrenade->team_no = pOwner->team_no;
	pGrenade->pev->classname = MAKE_STRING( "tf_gl_grenade" );
	pGrenade->deathtype = MAKE_STRING( "gl_grenade" );
	pGrenade->m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_gren.sc" );

	MESSAGE_BEGIN( MSG_BROADCAST, SVC_TEMPENTITY );
		WRITE_BYTE( TE_BEAMFOLLOW );
		WRITE_SHORT( pGrenade->entindex() );	// entity
		WRITE_SHORT( pGrenade->m_iTrail );	// model
		WRITE_BYTE( 15 );	// life
		WRITE_BYTE( 5 );	// width
		WRITE_BYTE( 224 );	// r, g, b
		WRITE_BYTE( 224 );
		WRITE_BYTE( 255 );
		WRITE_BYTE( 80 );	// brightness
	MESSAGE_END();

	return pGrenade;
}

CTFGrenade *CTFGrenade::CreateTFPipebomb( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFGrenadeLauncher *pLauncher )
{
	CTFGrenade *pGrenade = GetClassPtr( (CTFGrenade *)NULL );

	UTIL_SetOrigin( pGrenade->pev, vecOrigin );
	pGrenade->pev->angles = vecAngles;
	pGrenade->Spawn();
	pGrenade->SetTouch( &CGrenade::BounceTouch );
	pGrenade->pev->owner = pOwner->edict();
	pGrenade->team_no = pOwner->team_no;
	pGrenade->pev->classname = MAKE_STRING( "tf_gl_pipebomb" );
	pGrenade->deathtype = MAKE_STRING( "pipebomb" );

	if ( !strcmp( STRING( pGrenade->pev->model ), "models/pipebomb.mdl" ) )
		pGrenade->pev->skin = 0;

	// Pipebombs go off by themselves after two minutes
	pGrenade->pev->nextthink = gpGlobals->time + 120;
	pGrenade->SetThink( &CTFGrenade::PipebombDetonate );
	pGrenade->m_flCreationTime = gpGlobals->time;

	MESSAGE_BEGIN( MSG_BROADCAST, SVC_TEMPENTITY );
		WRITE_BYTE( TE_BEAMFOLLOW );
		WRITE_SHORT( pGrenade->entindex() );	// entity
		WRITE_SHORT( pGrenade->m_iTrail );	// model
		WRITE_BYTE( 10 );	// life
		WRITE_BYTE( 5 );	// width
		WRITE_BYTE( 224 );	// r, g, b
		WRITE_BYTE( 224 );
		WRITE_BYTE( 255 );
		WRITE_BYTE( 80 );	// brightness
	MESSAGE_END();

	// Only 8 pipebombs each; the oldest goes off
	if ( pOwner->Classify() == CLASS_PLAYER )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)pOwner;
		if ( ++pPlayer->m_iPipebombCount > 8 )
			pPlayer->ExplodeOldPipebomb( FALSE, TRUE );
	}

	return pGrenade;
}

void CTFGrenade::Spawn( void )
{
	Precache();

	pev->movetype = MOVETYPE_BOUNCE;
	pev->solid = SOLID_BBOX;
	pev->gravity = 1;
	pev->friction = 0.5;
	m_bDontSpark = TRUE;
	m_bDontSmoke = TRUE;

	setModel();
	UTIL_SetSize( pev, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
	UTIL_SetOrigin( pev, pev->origin );

	UTIL_MakeVectors( pev->angles );
	pev->velocity = gpGlobals->v_forward * 600 + gpGlobals->v_up * 200
		+ gpGlobals->v_right * RANDOM_FLOAT( -10, 10 ) + gpGlobals->v_up * RANDOM_FLOAT( -10, 10 );
	pev->avelocity = Vector( 300, 300, 300 );

	pev->nextthink = gpGlobals->time + 2.5;
	SetThink( &CGrenade::Detonate );
	pev->dmg = 120;
}

void CTFGrenade::setModel( void )
{
	if ( !setBirthdayModel() )
	{
		SET_MODEL( ENT( pev ), "models/pipebomb.mdl" );
		pev->skin = 1;
	}
}

void CTFGrenade::PipebombDetonate( void )
{
	TraceResult tr;
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	if ( pOwner->Classify() == CLASS_PLAYER )
		((CBasePlayer *)pOwner)->m_iPipebombCount--;

	Vector vecSpot = pev->origin + Vector( 0, 0, 8 );
	UTIL_TraceLine( vecSpot, vecSpot + Vector( 0, 0, -32 ), ignore_monsters, ENT( pev ), &tr );

	Explode( &tr, DMG_BLAST | DMG_RADIUS_QUAKE );
}

// EMP sets pipebombs off
void CTFGrenade::TeamFortress_TakeEMPBlast( entvars_t *pevGren )
{
	if ( !strcmp( STRING( pev->classname ), "tf_gl_pipebomb" ) )
		pev->nextthink = gpGlobals->time + 0.1;
}

void CTFGrenade::GrenadeTouch( CBaseEntity *pOther )
{
	// Grenades go off on contact with players
	if ( pOther && pOther->pev->takedamage == DAMAGE_AIM )
	{
		entvars_t *pevOwner = VARS( pev->owner );
		ExplodeTouch( pOther );
		return;
	}

	BounceSound();

	if ( pev->flags & FL_ONGROUND )
	{
		// add a bit of static friction
		pev->velocity = pev->velocity * 0.75;
		if ( pev->velocity.Length() <= 20 )
			pev->avelocity = g_vecZero;
	}
}

void CTFGrenade::RadiusDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType )
{
	::RadiusDamage( pev->origin, pevInflictor, pevAttacker, flDamage, flDamage, iClassIgnore, bitsDamageType | DMG_RADIUS_QUAKE );
}

void CTFGrenade::Precache( void )
{
	PRECACHE_MODEL( "models/rpgrocket.mdl" );
	m_iTrail = PRECACHE_MODEL( "sprites/smoke.spr" );
	PRECACHE_SOUND( "weapons/rocket1.wav" );
	m_usExplode = PRECACHE_EVENT( 1, "events/explode/tf_pipe.sc" );
}

//=========================================================
// Laser spot (sniper rifle)
//=========================================================
LINK_ENTITY_TO_CLASS( laser_spot, CLaserSpot );

CLaserSpot *CLaserSpot::CreateSpot( void )
{
	CLaserSpot *pSpot = GetClassPtr( (CLaserSpot *)NULL );
	pSpot->Spawn();
	pSpot->pev->classname = MAKE_STRING( "laser_spot" );
	return pSpot;
}

void CLaserSpot::Spawn( void )
{
	Precache();
	pev->movetype = MOVETYPE_NONE;
	pev->solid = SOLID_NOT;

	pev->rendermode = kRenderGlow;
	pev->renderfx = kRenderFxNoDissipation;
	pev->renderamt = 255;

	SET_MODEL( ENT( pev ), "sprites/laserdot.spr" );
	UTIL_SetOrigin( pev, pev->origin );
}

// Hide the dot for a while
void CLaserSpot::Suspend( float flSuspendTime )
{
	pev->effects |= EF_NODRAW;

	SetThink( &CLaserSpot::Revive );
	pev->nextthink = gpGlobals->time + flSuspendTime;
}

void CLaserSpot::Revive( void )
{
	pev->effects &= ~EF_NODRAW;
	SetThink( NULL );
}

void CLaserSpot::Precache( void )
{
	PRECACHE_MODEL( "sprites/laserdot.spr" );
}
