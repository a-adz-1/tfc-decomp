/***
*
*	Team Fortress Classic: Engineer sentry gun and its base
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "player.h"
#include "weapons.h"
#include "effects.h"
#include "tf_defs.h"

#define BUILDING_EVENT_DESTROYED	1024

// Range bands (from QuakeWorld TF)
#define RANGE_MELEE		0
#define RANGE_NEAR		1
#define RANGE_MID		2
#define RANGE_FAR		3

extern int gmsgDeathMsg;

LINK_ENTITY_TO_CLASS( building_sentrygun, CTFSentrygun );
LINK_ENTITY_TO_CLASS( building_sentrygun_base, CTFSentrygunBase );

//=========================================================
// Base: what the engineer builds; the gun sits on top
//=========================================================
void CTFSentrygunBase::Spawn( void )
{
	pev->classname = MAKE_STRING( "building_sentrygun_base" );
	pev->movetype = MOVETYPE_TOSS;
	pev->solid = SOLID_BBOX;
	pev->flags &= ~FL_ONGROUND;
	pev->velocity = Vector( 0, 0, 8 );
	pev->flags |= FL_MONSTER;

	SET_MODEL( ENT( pev ), "models/base.mdl" );
	UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 48 ) );
}

void CTFSentrygunBase::Remove( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( real_owner->edict() );

	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_sentrygun" );
	while ( pEnt )
	{
		if ( (CBaseEntity *)pEnt->real_owner == pOwner )
		{
			if ( !pOwner->no_sentry_message )
				ClientPrint( pOwner->pev, HUD_PRINTCENTER, "#Sentry_destroyed" );

			UTIL_LogPrintf( "\"<-1><><>\" triggered \"Sentry_destroyed\" against \"%s<%i><%s><%s>\"\n",
				STRING( pOwner->pev->netname ),
				GETPLAYERUSERID( pOwner->edict() ),
				GETPLAYERAUTHID( pOwner->edict() ),
				pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

			pOwner->has_sentry = FALSE;
			pOwner->no_sentry_message = 0;

			// Close anyone's sentry menu for it
			for ( int i = 1; i <= gpGlobals->maxClients; i++ )
			{
				CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
				if ( pPlayer && (CBaseEntity *)pPlayer->building == pEnt )
				{
					pPlayer->ResetMenu();
					pPlayer->building = NULL;
				}
			}

			dremove( pEnt );
			break;
		}
		pEnt = UTIL_FindEntityByClassname( pEnt, "building_sentrygun" );
	}

	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLOSION );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_SHORT( g_sModelIndexFireball );
		WRITE_BYTE( 30 );	// scale * 10
		WRITE_BYTE( 15 );	// framerate
		WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
	MESSAGE_END();

	dremove( this );
}

CTFSentrygunBase *CTFSentrygunBase::CreateSentryBase( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner )
{
	CTFSentrygunBase *pBase = GetClassPtr( (CTFSentrygunBase *)NULL );

	UTIL_SetOrigin( pBase->pev, vecOrigin );
	pBase->pev->angles = g_vecZero;
	pBase->pev->angles.y = UTIL_AngleMod( pOwner->pev->angles.y + 180 );	// face the engineer
	pBase->Spawn();
	pBase->real_owner = pOwner;
	pBase->team_no = pOwner->team_no;

	return pBase;
}

// Hits on the base hurt the gun, except explosions (they reach the gun anyway)
int CTFSentrygunBase::TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType )
{
	if ( m_pOtherSection && !( bitsDamageType & ( DMG_BLAST | DMG_RADIUS_MAX | DMG_RADIUS_QUAKE ) ) )
		return m_pOtherSection->TakeDamage( pevInflictor, pevAttacker, flDamage, bitsDamageType );

	return 0;
}

// Called when the build timer runs out: put the gun on the base
void CTFSentrygunBase::Finished( void )
{
	real_owner->has_sentry = TRUE;
	ClientPrint( real_owner->pev, HUD_PRINTNOTIFY, "#Sentry_finish" );
	teamsprint( team_no, real_owner, HUD_PRINTNOTIFY, "#Sentry_built", STRING( real_owner->pev->netname ) );

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Sentry_Built_Level_1\"\n",
		STRING( real_owner->pev->netname ),
		GETPLAYERUSERID( real_owner->edict() ),
		GETPLAYERAUTHID( real_owner->edict() ),
		real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );

	pev->takedamage = DAMAGE_AIM;
	real_owner->ammo_cells -= BUILD_COST_SENTRYGUN;
	UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 4 ) );

	CTFSentrygun *pSentry = GetClassPtr( (CTFSentrygun *)NULL );
	pSentry->Spawn();
	pSentry->real_owner = real_owner;
	pSentry->team_no = team_no;

	int topColor = teamcolors[team_no][10].topColor;
	pSentry->pev->colormap = topColor | ( ( ( topColor + 10 ) & 0xFF ) << 8 );

	pSentry->m_pOtherSection = this;
	m_pOtherSection = pSentry;

	UTIL_SetOrigin( pSentry->pev, pev->origin + Vector( 0, 0, 21.2 ) );
	pSentry->pev->angles.y = pev->angles.y;
	pSentry->m_vecCurAngles.y = UTIL_AngleMod( pSentry->pev->angles.y );

	// Sweep 50 degrees either side of where it faces
	pSentry->m_iRightBound = UTIL_AngleMod( (int)pSentry->pev->angles.y - 50 );
	pSentry->m_iLeftBound = UTIL_AngleMod( (int)pSentry->pev->angles.y + 50 );
	if ( pSentry->m_iRightBound > pSentry->m_iLeftBound )
	{
		pSentry->m_iRightBound = pSentry->m_iLeftBound;
		pSentry->m_iLeftBound = UTIL_AngleMod( (int)pSentry->pev->angles.y - 50 );
	}

	pSentry->m_vecCurAngles.x = 0;
	pSentry->m_vecGoalAngles.x = 0;
	pSentry->m_bTurningRight = TRUE;
	pSentry->m_vecGoalAngles.y = pSentry->m_iRightBound;

	pSentry->m_vOldOrigin = pSentry->pev->origin;

	EMIT_SOUND( pSentry->edict(), CHAN_ITEM, "weapons/turrset.wav", 1, ATTN_NORM );

	pSentry->m_flNextCheck = gpGlobals->time + 0.1;
}

//=========================================================
// Sentry gun
//=========================================================
void CTFSentrygun::Spawn( void )
{
	Precache();

	pev->classname = MAKE_STRING( "building_sentrygun" );
	pev->health = 150;
	pev->max_health = pev->health;
	pev->movetype = MOVETYPE_FLY;
	pev->sequence = 0;
	pev->frame = 0;
	pev->solid = SOLID_SLIDEBOX;
	pev->takedamage = DAMAGE_AIM;
	pev->view_ofs = Vector( 0, 0, 22 );
	deathtype = MAKE_STRING( "sentrygun" );

	weapon = 1;	// level
	m_iRightBound = 45;
	m_iLeftBound = 315;
	m_iBaseTurnRate = 6;
	m_vecCurDishAngles = g_vecZero;
	maxammo_rockets = 20;
	m_flFieldOfView = 0.7;
	ammo_shells = 25;
	maxammo_shells = 100;

	pev->flags |= FL_MONSTER;

	SET_MODEL( ENT( pev ), "models/sentry1.mdl" );
	UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 48 ) );

	SetBoneController( 0, 0 );
	SetBoneController( 1, 0 );

	m_hEnemy = NULL;
	SetThink( &CTFSentrygun::SentryRotate );
	pev->nextthink = gpGlobals->time + 0.5;
}

void CTFSentrygun::Precache( void )
{
	PRECACHE_MODEL( "models/sentry1.mdl" );
	PRECACHE_MODEL( "models/sentry2.mdl" );
	PRECACHE_MODEL( "models/sentry3.mdl" );
	PRECACHE_MODEL( "models/base.mdl" );
	PRECACHE_MODEL( "sprites/shellchrome.spr" );
	PRECACHE_SOUND( "weapons/turridle.wav" );
	PRECACHE_SOUND( "weapons/turrspot.wav" );
	PRECACHE_SOUND( "weapons/turrset.wav" );
	PRECACHE_SOUND( "weapons/rocketfire1.wav" );
	PRECACHE_SOUND( "weapons/pl_gun3.wav" );
	m_usBuildingEvent = PRECACHE_EVENT( 1, "events/misc/tf_buildingevent.sc" );
}

// Removed by the owner (dismantled, changed class, left the game)
void CTFSentrygun::Remove( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( real_owner->edict() );

	if ( !pOwner->no_sentry_message )
		ClientPrint( pOwner->pev, HUD_PRINTCENTER, "#Sentry_destroyed" );

	UTIL_LogPrintf( "\"<-1><><>\" triggered \"Sentry_destroyed\" against \"%s<%i><%s><%s>\"\n",
		STRING( pOwner->pev->netname ),
		GETPLAYERUSERID( pOwner->edict() ),
		GETPLAYERAUTHID( pOwner->edict() ),
		pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
		(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

	pOwner->has_sentry = FALSE;
	pOwner->no_sentry_message = 0;

	// Close anyone's sentry menu for it
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( pPlayer && (CBaseEntity *)pPlayer->building == this )
		{
			pPlayer->ResetMenu();
			pPlayer->building = NULL;
		}
	}

	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLOSION );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_SHORT( g_sModelIndexFireball );
		WRITE_BYTE( 30 );	// scale * 10
		WRITE_BYTE( 15 );	// framerate
		WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
	MESSAGE_END();

	dremove( this );

	// And the base
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_sentrygun_base" );
	while ( pEnt )
	{
		if ( (CBaseEntity *)pEnt->real_owner == pOwner )
		{
			dremove( pEnt );
			return;
		}
		pEnt = UTIL_FindEntityByClassname( pEnt, "building_sentrygun_base" );
	}
}

void CTFSentrygun::SetSentryAnim( TFTURRET_ANIM anim )
{
	if ( pev->sequence == anim )
		return;

	switch ( anim )
	{
	case TFTURRET_ANIM_FIRE:
	case TFTURRET_ANIM_SPIN:
		if ( pev->sequence != TFTURRET_ANIM_FIRE && pev->sequence != TFTURRET_ANIM_SPIN )
			pev->frame = 0;
		break;
	default:
		pev->frame = 0;
		break;
	}

	pev->sequence = anim;
	ResetSequenceInfo();
}

// Fade out the damage glow shell
void CTFSentrygun::CheckShield( void )
{
	pev->renderamt -= 40;
	if ( pev->renderamt <= 0 )
	{
		pev->renderfx = kRenderFxNone;
		pev->renderamt = 0;
		pev->rendercolor = g_vecZero;
	}
}

// Idle: sweep between the bounds looking for targets
void CTFSentrygun::SentryRotate( void )
{
	SetSentryAnim( TFTURRET_ANIM_SPIN );
	StudioFrameAdvance();
	DoDamageEffects( pev, pev->max_health * 0.66, pev->max_health * 0.33 );

	if ( m_flNextCheck < gpGlobals->time )
	{
		if ( !CheckSentry() )
			return;
		m_flNextCheck = gpGlobals->time + 3;
	}

	if ( pev->renderfx )
		CheckShield();

	pev->nextthink = gpGlobals->time + 0.1;

	if ( FindTarget() || MoveTurret() )
		return;

	m_pOtherSection->CheckBelowBuilding( 24 );
	UpdateEntityEvents( this );

	if ( RANDOM_FLOAT( 0, 1 ) < 0.1 )
		EMIT_SOUND( ENT( pev ), CHAN_ITEM, "weapons/turridle.wav", 1, ATTN_NORM );

	if ( m_bTurningRight )
	{
		m_bTurningRight = FALSE;
		m_vecGoalAngles.y = m_iLeftBound;
	}
	else
	{
		m_bTurningRight = TRUE;
		m_vecGoalAngles.y = m_iRightBound;
	}

	if ( RANDOM_FLOAT( 0, 1 ) < 0.3 )
		m_vecGoalAngles.x = (int)RANDOM_FLOAT( -10, 10 );
}

BOOL CTFSentrygun::FindTarget( void )
{
	CBaseEntity *pTarget;
	int iRange;

	// Players first
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		pTarget = UTIL_PlayerByIndex( i );
		if ( !pTarget || pTarget == (CBaseEntity *)real_owner || !ValidTarget( pTarget ) )
			continue;

		iRange = Range( pTarget );
		if ( iRange == RANGE_FAR )
			continue;
		if ( iRange == RANGE_MID && !FInViewCone( pTarget ) )
			continue;

		m_hEnemy = pTarget;
		FoundTarget();
		return TRUE;
	}

	// Then enemy teleporters
	pTarget = UTIL_FindEntityByClassname( NULL, "building_teleporter" );
	while ( pTarget )
	{
		if ( ValidTarget( pTarget ) )
		{
			iRange = Range( pTarget );
			if ( iRange != RANGE_FAR && ( iRange != RANGE_MID || FInViewCone( pTarget ) ) )
			{
				m_hEnemy = pTarget;
				FoundTarget();
				return TRUE;
			}
		}
		pTarget = UTIL_FindEntityByClassname( pTarget, "building_teleporter" );
	}

	return FALSE;
}

int CTFSentrygun::Range( CBaseEntity *pTarget )
{
	Vector vecOrg = pev->origin + pev->view_ofs;
	Vector vecTargetOrg = pTarget->pev->origin + pTarget->pev->view_ofs;
	int iDist = ( vecTargetOrg - vecOrg ).Length();

	if ( iDist < 120 )
		return RANGE_MELEE;
	if ( iDist < 500 )
		return RANGE_NEAR;
	if ( iDist < 1000 )
		return RANGE_MID;
	return RANGE_FAR;
}

BOOL CTFSentrygun::ValidTarget( CBaseEntity *pTarget )
{
	if ( !pTarget || !pTarget->IsAlive() || pTarget->is_feigning )
		return FALSE;

	// Spies disguised as our team are ignored
	if ( gpGlobals->teamplay && team_no )
	{
		if ( IsAlly( pTarget ) )
			return FALSE;
		if ( pTarget->undercover_team == team_no )
			return FALSE;
	}

	if ( pTarget->pev->flags & FL_NOTARGET )
		return FALSE;
	if ( pTarget->items & IT_INVISIBILITY )
		return FALSE;

	return FVisible( pTarget );
}

void CTFSentrygun::FoundTarget( void )
{
	if ( ammo_shells > 0 || ( ammo_rockets > 0 && weapon == 3 ) )
		EMIT_SOUND( ENT( pev ), CHAN_ITEM, "weapons/turrspot.wav", 1, ATTN_NORM );

	SetThink( &CTFSentrygun::Attack );
	pev->nextthink = gpGlobals->time + 0.1;
	m_flNextAttack = gpGlobals->time + 0.1;

	// super_damage_finished is the rocket cooldown
	if ( super_damage_finished < gpGlobals->time )
		super_damage_finished = gpGlobals->time + 0.5;
}

void CTFSentrygun::Attack( void )
{
	if ( pev->renderfx )
		CheckShield();

	StudioFrameAdvance();
	DoDamageEffects( pev, pev->max_health * 0.66, pev->max_health * 0.33 );
	pev->nextthink = gpGlobals->time + 0.1;

	BOOL bHasAmmo;
	if ( weapon == 3 )
		bHasAmmo = ammo_shells > 0 || ammo_rockets > 0;
	else
		bHasAmmo = ammo_shells > 0;

	if ( !ValidTarget( m_hEnemy ) || !bHasAmmo )
	{
		// Lost it: back to sweeping
		SetThink( &CTFSentrygun::SentryRotate );
		pev->nextthink = gpGlobals->time + 0.1;
		m_hEnemy = NULL;
		return;
	}

	Vector vecMid = pev->origin + pev->view_ofs;
	Vector vecMidEnemy = m_hEnemy->BodyTarget( vecMid );
	Vector vecDirToEnemy = vecMidEnemy - vecMid;
	Vector angToTarget = UTIL_VecToAngles( vecDirToEnemy );

	angToTarget.y = UTIL_AngleMod( angToTarget.y );
	if ( angToTarget.x < -180 )
		angToTarget.x += 360;
	if ( angToTarget.x > 180 )
		angToTarget.x -= 360;

	// Pitch limits
	if ( angToTarget.x > 50 )
		angToTarget.x = 50;
	else if ( angToTarget.x < -50 )
		angToTarget.x = -50;

	m_vecGoalAngles.y = angToTarget.y;
	m_vecGoalAngles.x = angToTarget.x;

	MoveTurret();

	// Fire once it's nearly on target
	if ( m_flNextAttack <= gpGlobals->time && ( m_vecGoalAngles - m_vecCurAngles ).Length() <= 10 )
	{
		Fire();

		if ( weapon == 1 )
			m_flNextAttack = gpGlobals->time + 0.2;
		else
			m_flNextAttack = gpGlobals->time + 0.1;
		return;
	}

	SetSentryAnim( TFTURRET_ANIM_SPIN );
}

BOOL CTFSentrygun::Fire( void )
{
	Vector vecSrc, vecAng;

	UTIL_MakeAimVectors( m_vecCurAngles );
	Vector vecAimDir = ( m_hEnemy->pev->origin - pev->origin ).Normalize();

	// Level 3: rockets every 3 seconds, alternating launchers
	if ( weapon == 3 && ammo_rockets > 0 && gpGlobals->time > super_damage_finished )
	{
		if ( ammo_rockets & 1 )
			GetAttachment( 3, vecSrc, vecAng );
		else
			GetAttachment( 2, vecSrc, vecAng );

		vecAng = UTIL_VecToAngles( vecAimDir );
		vecAng.x = -vecAng.x;

		CTFRpgRocket *pRocket = CTFRpgRocket::CreateRpgRocket( vecSrc, vecAng, real_owner, NULL );
		pRocket->deathtype = MAKE_STRING( "sentrygun" );
		pRocket->pev->velocity = vecAimDir * 800;
		UTIL_ParametricRocket( pRocket->pev, vecSrc, vecAng, real_owner->edict() );

		EMIT_SOUND( ENT( pev ), CHAN_ITEM, "weapons/rocketfire1.wav", 1, ATTN_NORM );

		super_damage_finished = gpGlobals->time + 3;
		ammo_rockets--;

		if ( ammo_rockets == 10 )
			ClientPrint( real_owner->pev, HUD_PRINTNOTIFY, "#Sentry_rocketslow" );
		if ( ammo_rockets == 0 )
			ClientPrint( real_owner->pev, HUD_PRINTNOTIFY, "#Sentry_rocketsout" );

		if ( ammo_shells < 1 )
			return FALSE;
	}
	else if ( ammo_shells < 1 )
	{
		goto checkammo;
	}

	// Bullets
	SetSentryAnim( TFTURRET_ANIM_FIRE );
	pev->effects |= EF_MUZZLEFLASH;

	if ( weapon == 3 && ( ammo_shells & 1 ) )
		GetAttachment( 1, vecSrc, vecAng );
	else
		GetAttachment( 0, vecSrc, vecAng );

	FireBullets( 1, vecSrc, vecAimDir, g_vecZero, 2048, BULLET_MONSTER_9MM, 4, 16, real_owner->pev );
	EMIT_SOUND( ENT( pev ), CHAN_ITEM, "weapons/pl_gun3.wav", 1, ATTN_NORM );
	ammo_shells--;

checkammo:
	if ( ammo_shells == 0 && RANDOM_FLOAT( 0, 1 ) < 0.1 )
		ClientPrint( real_owner->pev, HUD_PRINTNOTIFY, "#Sentry_shellsout" );
	else if ( ammo_shells == 20 )
		ClientPrint( real_owner->pev, HUD_PRINTNOTIFY, "#Sentry_shellslow" );

	return TRUE;
}

// The gun must still be on its base and outside func_nobuild areas
BOOL CTFSentrygun::CheckSentry( void )
{
	BOOL bPositionOK;

	if ( m_pOtherSection )
		bPositionOK = ( pev->origin - m_pOtherSection->pev->origin ).Length() <= 24;
	else
		bPositionOK = FALSE;

	CBaseEntity *pNoBuild = UTIL_FindEntityByClassname( NULL, "func_nobuild" );
	while ( pNoBuild )
	{
		if ( pev->origin.x >= pNoBuild->pev->mins.x && pev->origin.y >= pNoBuild->pev->mins.y && pev->origin.z >= pNoBuild->pev->mins.z
			&& pev->origin.x <= pNoBuild->pev->maxs.x && pev->origin.y <= pNoBuild->pev->maxs.y && pev->origin.z <= pNoBuild->pev->maxs.z )
		{
			bPositionOK = FALSE;
		}
		pNoBuild = UTIL_FindEntityByClassname( pNoBuild, "func_nobuild" );
	}

	if ( !bPositionOK )
	{
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Sentry_malfunc", STRING( real_owner->pev->netname ) );
		UTIL_LogPrintf( "\"<-1><><>\" triggered \"Sentry_Malfunction\" against \"%s<%i><%s><%s>\"\n",
			STRING( real_owner->pev->netname ),
			GETPLAYERUSERID( real_owner->edict() ),
			GETPLAYERAUTHID( real_owner->edict() ),
			real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );

		Killed( NULL, NULL, 0 );
		return FALSE;
	}

	return bPositionOK;
}

void CTFSentrygun::TeamFortress_TakeEMPBlast( entvars_t *pevGren )
{
	CBaseEntity *pThrower = CBaseEntity::Instance( pevGren->owner );
	CBaseEntity *pGrenade = CBaseEntity::Instance( pevGren );

	// Allies' EMPs only hurt it with team damage on, but the owner's always do
	if ( !( (int)gpGlobals->teamplay & ( TEAMPLAY_HALFDIRECT | TEAMPLAY_NODIRECT | TEAMPLAY_HALFEXPLOSIVE | TEAMPLAY_NOEXPLOSIVE ) )
		|| !IsAlly( pThrower ) || (CBaseEntity *)real_owner == pThrower )
	{
		TakeDamage( pevGren, pThrower->pev, 200, DMG_BLAST );
	}
}

void CTFSentrygun::Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib )
{
	char weapon[30];

	if ( pev->solid == SOLID_NOT )
		return;

	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
		(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

	if ( !((CBasePlayer *)(CBaseEntity *)real_owner)->no_sentry_message )
		ClientPrint( real_owner->pev, HUD_PRINTCENTER, "#Sentry_destroyed" );

	real_owner->has_sentry = FALSE;
	((CBasePlayer *)(CBaseEntity *)real_owner)->no_sentry_message = 0;

	// Close anyone's sentry menu for it
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)UTIL_PlayerByIndex( i );
		if ( pPlayer && (CBaseEntity *)pPlayer->building == this )
		{
			pPlayer->ResetMenu();
			pPlayer->building = NULL;
		}
	}

	pev->solid = SOLID_NOT;
	m_pOtherSection->pev->solid = SOLID_NOT;

	SetThink( &CTFSentrygun::Sentry_Explode );
	pev->nextthink = gpGlobals->time + 0.1;

	if ( !pevAttacker )
		return;

	// A frag and a death notice for killing an enemy sentry
	CBaseEntity *pAttacker = CBaseEntity::Instance( pevAttacker );
	if ( pAttacker->IsPlayer() && !pAttacker->IsAlly( (CBaseEntity *)real_owner ) )
	{
		((CBasePlayer *)pAttacker)->TF_AddFrags( 1 );

		MESSAGE_BEGIN( MSG_ALL, gmsgDeathMsg );
			WRITE_BYTE( ENTINDEX( pAttacker->edict() ) );
			WRITE_BYTE( -1 );
			WRITE_STRING( "sentrygun" );
		MESSAGE_END();
	}

	if ( !(int)real_owner )
		return;

	CBasePlayer *pPlayer = (CBasePlayer *)CBaseEntity::Instance( pevAttacker );

	GetWeapon( pevInflictor, pevAttacker, weapon );

	if ( pevAttacker == pevInflictor )
	{
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\"\n",
			STRING( real_owner->pev->netname ),
			GETPLAYERUSERID( real_owner->edict() ),
			GETPLAYERAUTHID( real_owner->edict() ),
			real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );
	}
	else if ( pevAttacker != real_owner->pev )
	{
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Sentry_Destroyed\" against \"%s<%i><%s><%s>\" with \"%s\"\n",
			STRING( pevAttacker->netname ),
			GETPLAYERUSERID( ENT( pevAttacker ) ),
			GETPLAYERAUTHID( ENT( pevAttacker ) ),
			pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
			STRING( real_owner->pev->netname ),
			GETPLAYERUSERID( real_owner->edict() ),
			GETPLAYERAUTHID( real_owner->edict() ),
			real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR",
			weapon );
	}
}

void CTFSentrygun::Sentry_Explode( void )
{
	MESSAGE_BEGIN( MSG_PVS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLODEMODEL );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_COORD( 400 );	// velocity
		WRITE_SHORT( m_iShardIndex );
		WRITE_SHORT( 15 );	// count
		WRITE_BYTE( 25 );	// life
	MESSAGE_END();

	pev->takedamage = DAMAGE_NO;

	// No damage if the owner left the game
	if ( real_owner->has_disconnected != TRUE )
		RadiusDamage( pev, real_owner->pev, ammo_rockets * 8 + 75, CLASS_NONE, DMG_BLAST | DMG_RADIUS_QUAKE );

	MESSAGE_BEGIN( MSG_PAS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLOSION );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_SHORT( g_sModelIndexFireball );
		WRITE_BYTE( 30 );	// scale * 10
		WRITE_BYTE( 15 );	// framerate
		WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
	MESSAGE_END();

	dremove( m_pOtherSection );
	dremove( this );
}

// Spanner hit: upgrade, else repair, else put ammo in
BOOL CTFSentrygun::EngineerUse( CBasePlayer *pPlayer )
{
	if ( weapon < 3 && pPlayer->ammo_cells >= 130 )
	{
		pPlayer->ammo_cells -= 130;
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Sentry_upgrade", UTIL_dtos1( weapon + 1 ) );

		char *pszEvent = NULL;
		if ( weapon == 1 )
			pszEvent = "Sentry_Upgrade_Level_2";
		else if ( weapon == 2 )
			pszEvent = "Sentry_Upgrade_Level_3";

		if ( pszEvent )
		{
			if ( pPlayer->pev == real_owner->pev )
			{
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\"\n",
					STRING( pPlayer->pev->netname ),
					GETPLAYERUSERID( pPlayer->edict() ),
					GETPLAYERAUTHID( pPlayer->edict() ),
					pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
					pszEvent );
			}
			else
			{
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",
					STRING( pPlayer->pev->netname ),
					GETPLAYERUSERID( pPlayer->edict() ),
					GETPLAYERAUTHID( pPlayer->edict() ),
					pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
					pszEvent,
					STRING( real_owner->pev->netname ),
					GETPLAYERUSERID( real_owner->edict() ),
					GETPLAYERAUTHID( real_owner->edict() ),
					real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );
			}
		}

		Upgrade();
		return TRUE;
	}

	if ( pev->health < pev->max_health )
	{
		// 1 cell per 5 health
		int metalcost = ceil( ( pev->max_health - pev->health ) / 5 );
		if ( metalcost > pPlayer->ammo_cells )
			metalcost = pPlayer->ammo_cells;

		if ( metalcost > 0 )
		{
			pPlayer->ammo_cells -= metalcost;
			pev->health = min( pev->health + metalcost * 5, pev->max_health );
			ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Sentry_repair" );

			if ( pPlayer->pev != real_owner->pev )
			{
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\" against \"%s<%i><%s><%s>\"\n",
					STRING( pPlayer->pev->netname ),
					GETPLAYERUSERID( pPlayer->edict() ),
					GETPLAYERAUTHID( pPlayer->edict() ),
					pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
					STRING( real_owner->pev->netname ),
					GETPLAYERUSERID( real_owner->edict() ),
					GETPLAYERAUTHID( real_owner->edict() ),
					real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );
			}
			else
			{
				UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\"\n",
					STRING( pPlayer->pev->netname ),
					GETPLAYERUSERID( pPlayer->edict() ),
					GETPLAYERAUTHID( pPlayer->edict() ),
					pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR" );
			}
			return TRUE;
		}
	}

	if ( ammo_shells < maxammo_shells && pPlayer->ammo_shells > 0 )
	{
		int am = min( pPlayer->ammo_shells, 40 );
		if ( am > maxammo_shells - ammo_shells )
			am = maxammo_shells - ammo_shells;

		pPlayer->ammo_shells -= am;
		ammo_shells += am;
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Sentry_inshells" );
	}

	if ( ammo_rockets < maxammo_rockets && weapon == 3 && pPlayer->ammo_rockets > 0 )
	{
		int am = min( pPlayer->ammo_rockets, 20 );
		if ( am > maxammo_rockets - ammo_rockets )
			am = maxammo_rockets - ammo_rockets;

		pPlayer->ammo_rockets -= am;
		ammo_rockets += am;
		ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, "#Sentry_inrockets" );
	}

	return TRUE;
}

void CTFSentrygun::Upgrade( void )
{
	weapon++;
	pev->max_health = pev->max_health * 1.2;
	pev->health = pev->max_health;
	maxammo_shells = maxammo_shells * 1.2;

	if ( weapon == 2 )
	{
		EMIT_SOUND( ENT( pev ), CHAN_ITEM, "weapons/turrset.wav", 1, ATTN_NORM );
		SET_MODEL( ENT( pev ), "models/sentry2.mdl" );
		UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 48 ) );
		ResetSequenceInfo();
	}
	else
	{
		EMIT_SOUND( ENT( pev ), CHAN_ITEM, "weapons/turrset.wav", 1, ATTN_NORM );
		SET_MODEL( ENT( pev ), "models/sentry3.mdl" );
		UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 48 ) );
		SetBoneController( 2, -m_vecCurAngles.x );	// rocket pod
		ResetSequenceInfo();
	}
}

// Flash a team coloured shell when hit
int CTFSentrygun::TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType )
{
	int iDamageTaken = CBaseMonster::TakeDamage( pevInflictor, pevAttacker, flDamage, bitsDamageType );
	if ( !iDamageTaken )
		return iDamageTaken;

	pev->renderfx = kRenderFxGlowShell;

	if ( team_no == 2 )
		pev->rendercolor = Vector( 255, 0, 0 );
	else if ( team_no == 3 )
		pev->rendercolor = Vector( 245, 255, 0 );
	else if ( team_no == 1 )
		pev->rendercolor = Vector( 0, 0, 255 );
	else
		pev->rendercolor = Vector( 0, 215, 45 );

	pev->renderamt = 150;

	return iDamageTaken;
}

// Turn toward m_vecGoalAngles; returns whether it moved
int CTFSentrygun::MoveTurret( void )
{
	int state = 0;

	// any x movement?
	if ( m_vecCurAngles.x != m_vecGoalAngles.x )
	{
		float flDir = m_vecGoalAngles.x > m_vecCurAngles.x ? 1 : -1;

		m_vecCurAngles.x += 0.1 * ( m_iBaseTurnRate * 5 ) * flDir;

		// if we started below the goal, and now we're past, peg to goal
		if ( flDir == 1 )
		{
			if ( m_vecCurAngles.x > m_vecGoalAngles.x )
				m_vecCurAngles.x = m_vecGoalAngles.x;
		}
		else
		{
			if ( m_vecCurAngles.x < m_vecGoalAngles.x )
				m_vecCurAngles.x = m_vecGoalAngles.x;
		}

		SetBoneController( 1, -m_vecCurAngles.x );
		if ( weapon == 3 )
			SetBoneController( 2, -m_vecCurAngles.x );	// rocket pod

		state = 1;
	}

	if ( m_vecCurAngles.y != m_vecGoalAngles.y )
	{
		float flDir = m_vecGoalAngles.y > m_vecCurAngles.y ? 1 : -1;
		float flDist = fabs( m_vecGoalAngles.y - m_vecCurAngles.y );
		BOOL bReversed = FALSE;

		if ( flDist > 180 )
		{
			flDist = 360 - flDist;
			flDir = -flDir;
			bReversed = TRUE;
		}

		if ( m_hEnemy == NULL )
		{
			if ( flDist > 30 )
			{
				if ( m_fTurnRate < m_iBaseTurnRate * 10 )
					m_fTurnRate += m_iBaseTurnRate;
			}
			else if ( m_fTurnRate > m_iBaseTurnRate * 5 )
			{
				m_fTurnRate -= m_iBaseTurnRate;
			}
		}
		else
		{
			// When tracking enemies, move faster and don't slow
			if ( flDist > 30 && m_fTurnRate < m_iBaseTurnRate * 30 )
				m_fTurnRate += m_iBaseTurnRate * 3;
		}

		m_vecCurAngles.y += 0.1 * m_fTurnRate * flDir;

		// if we passed over the goal, peg right to it now
		if ( flDir == -1 )
		{
			if ( ( !bReversed && m_vecGoalAngles.y > m_vecCurAngles.y ) || ( bReversed && m_vecGoalAngles.y < m_vecCurAngles.y ) )
				m_vecCurAngles.y = m_vecGoalAngles.y;
		}
		else
		{
			if ( ( !bReversed && m_vecGoalAngles.y < m_vecCurAngles.y ) || ( bReversed && m_vecGoalAngles.y > m_vecCurAngles.y ) )
				m_vecCurAngles.y = m_vecGoalAngles.y;
		}

		if ( m_vecCurAngles.y < 0 )
			m_vecCurAngles.y += 360;
		else if ( m_vecCurAngles.y >= 360 )
			m_vecCurAngles.y -= 360;

		if ( flDist < ( 0.05 * m_iBaseTurnRate ) )
			m_vecCurAngles.y = m_vecGoalAngles.y;

		SetBoneController( 0, m_vecCurAngles.y - pev->angles.y );
		state = 1;
	}

	if ( !state )
		m_fTurnRate = m_iBaseTurnRate;

	return state;
}

// Uses the turret's aim rather than the entity's angles
BOOL CTFSentrygun::FInViewCone( CBaseEntity *pEntity )
{
	UTIL_MakeVectors( m_vecCurAngles );

	Vector2D vec2LOS = ( pEntity->pev->origin - pev->origin ).Make2D();
	vec2LOS = vec2LOS.Normalize();

	float flDot = DotProduct( vec2LOS, gpGlobals->v_forward.Make2D() );

	return flDot > m_flFieldOfView;
}
