/***
*
*	Team Fortress Classic: Pyro - burning flames attached to targets
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*	The flamethrower burst and incendiary rocket projectiles are in
*	tf_wpn_nails.cpp, as in the original.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "weapons.h"
#include "player.h"
#include "tf_defs.h"

LINK_ENTITY_TO_CLASS( tf_flame, CTFFlame );

// Attach a flame to pTarget, lit by pOwner
CTFFlame *CTFFlame::FlameSpawn( CBaseEntity *pOwner, CBaseEntity *pTarget )
{
	CTFFlame *pFlame = GetClassPtr( (CTFFlame *)NULL );

	UTIL_SetOrigin( pFlame->pev, pTarget->pev->origin );
	pFlame->Spawn();
	pFlame->pev->enemy = pTarget->edict();
	pFlame->pev->owner = pOwner->edict();

	EMIT_SOUND_DYN( pFlame->edict(), CHAN_WEAPON, "ambience/fire1.wav", 1.0, 0.5, 0, PITCH_NORM );

	MESSAGE_BEGIN( MSG_PVS, SVC_TEMPENTITY, pTarget->pev->origin );
		WRITE_BYTE( TE_PLAYERSPRITES );
		WRITE_SHORT( ENTINDEX( pTarget->edict() ) );
		WRITE_SHORT( g_sModelIndexPlayerFlame );
		WRITE_BYTE( 5 );
		WRITE_BYTE( 25 );
	MESSAGE_END();

	pFlame->pev->movetype = MOVETYPE_FOLLOW;
	pFlame->pev->aiment = pTarget->edict();

	return pFlame;
}

void CTFFlame::Spawn( void )
{
	Precache();

	pev->solid = SOLID_NOT;
	UTIL_SetSize( pev, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
	UTIL_SetOrigin( pev, pev->origin );

	pev->classname = MAKE_STRING( "tf_fire" );
	deathtype = MAKE_STRING( "flames" );

	pev->health = gpGlobals->time + 5.0;	// burn-out time
	pev->effects |= EF_NODRAW | EF_DIMLIGHT;

	pev->nextthink = gpGlobals->time + 1.0;
	SetThink( &CTFFlame::FlameThink );
	m_flNextDamageTime = pev->nextthink;
}

void CTFFlame::Precache( void )
{
	PRECACHE_SOUND( "ambience/fire1.wav" );
}

void CTFFlame::FlameThink( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( VARS( pev->owner ) );
	CBaseEntity *pEnemy = CBaseEntity::Instance( VARS( pev->enemy ) );

	MESSAGE_BEGIN( MSG_PVS, SVC_TEMPENTITY, pEnemy->pev->origin );
		WRITE_BYTE( TE_PLAYERSPRITES );
		WRITE_SHORT( ENTINDEX( pEnemy->edict() ) );
		WRITE_SHORT( g_sModelIndexPlayerFlame );
		WRITE_BYTE( 5 );
		WRITE_BYTE( 50 );
	MESSAGE_END();

	if ( pEnemy->numflames )
	{
		if ( pEnemy->pev->health < 1 )
		{
			// Target died: the fire spreads briefly before going out
			::RadiusDamage( pev->origin, pev, pOwner ? pOwner->pev : pev, 10, 10, CLASS_NONE, DMG_BURN | DMG_RADIUS_QUAKE );
		}
		else
		{
			// Fire-resistant armour puts the flame out
			if ( ( pEnemy->armorclass & AT_SAVEFIRE ) && pEnemy->pev->armorvalue > 0 )
			{
				pEnemy->numflames--;
				FlameDestroy();
				return;
			}

			// Re-ignited: restart the burn-out time
			if ( pEnemy->tfstate & TFSTATE_RESET_FLAMETIME )
			{
				pev->health = gpGlobals->time + 5.0;
				pEnemy->tfstate &= ~TFSTATE_RESET_FLAMETIME;
			}

			if ( gpGlobals->time < m_flNextDamageTime )
			{
				pev->nextthink = gpGlobals->time + 0.2;
				return;
			}

			if ( gpGlobals->time <= pev->health )
			{
				if ( pEnemy->IsAlive() )
				{
					pEnemy->TakeDamage( pev, VARS( pev->owner ), pEnemy->numflames * 2, DMG_BURN );

					if ( !pEnemy->IsAlive() )
					{
						UTIL_LogPrintf( "\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
							STRING( pOwner->pev->netname ),
							GETPLAYERUSERID( pOwner->edict() ),
							GETPLAYERAUTHID( pOwner->edict() ),
							pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR",
							STRING( pEnemy->pev->netname ),
							GETPLAYERUSERID( pEnemy->edict() ),
							GETPLAYERAUTHID( pEnemy->edict() ),
							pEnemy->team_no ? GetTeamName( pEnemy->team_no ) : "SPECTATOR",
							"flames" );
					}
				}

				m_flNextDamageTime = gpGlobals->time + 1.0;
				pev->nextthink = gpGlobals->time + 0.2;
				return;
			}
		}

		pEnemy->numflames = 0;
	}

	FlameDestroy();
}

void CTFFlame::FlameDestroy( void )
{
	EMIT_SOUND_DYN( edict(), CHAN_WEAPON, "ambience/fire1.wav", 0, 0, SND_STOP, PITCH_NORM );
	num_world_flames--;
	SUB_Remove();
}
