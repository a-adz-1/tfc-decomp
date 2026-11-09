/***
*
*	Team Fortress Classic: timers (infection, hallucination, tranq,
*	building, disguise, cease fire...), pipebomb/ammobox limits, discard,
*	"save me", alliances
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
#include "decals.h"
#include "tf_defs.h"

extern DLL_DECALLIST gDecals[];

// Global TF variables (the map and server settings set most of these)
float number_of_teams;
int   illegalclasses[5];
int   civilianteams;

Vector rgbcolors[5];

team_color_t teamcolors[5][PC_LASTCLASS];

int   g_iOrderedTeams[5];
int   teamscores[5];
int   teamfrags[5];
int   teamlives[5];
int   teammaxplayers[5];
float teamadvantage[5];

int   teamallies[5];
string_t team_names[5];

BOOL  CTF_Map;
BOOL  birthday;
BOOL  christmas;

float num_world_flames;

// Clan battles
float clan_scores_dumped;
float cb_prematch_time;
float fOldPrematch;
float fOldCeaseFire;
float cb_ceasefire_time;
float last_id;
float spy_off;
float old_grens;
float flagem_checked;
float flNextEqualisationCalc;
BOOL  cease_fire;
BOOL  no_cease_fire_text;
BOOL  initial_cease_fire;
BOOL  last_cease_fire;

float autokick_kills;

float deathmsg;

char *sTeamSpawnNames[] =
{
	"",
	"ts1",
	"ts2",
	"ts3",
	"ts4",
};

char *sClassNames[] =
{
	"Observer",
	"Scout",
	"Sniper",
	"Soldier",
	"Demoman",
	"Medic",
	"HWGuy",
	"Pyro",
	"Spy",
	"Engineer",
	"RandomPC",
	"Civilian",
};

char *sNewClassModelFiles[] =
{
	NULL,
	"models/player/scout/scout.mdl",
	"models/player/sniper/sniper.mdl",
	"models/player/soldier/soldier.mdl",
	"models/player/demo/demo.mdl",
	"models/player/medic/medic.mdl",
	"models/player/hvyweapon/hvyweapon.mdl",
	"models/player/pyro/pyro.mdl",
	"models/player/spy/spy.mdl",
	"models/player/engineer/engineer.mdl",
	"models/player.mdl",
	"models/player/civilian/civilian.mdl",
};

char *sOldClassModelFiles[] =
{
	NULL,
	"models/player/scout/scout2.mdl",
	"models/player/sniper/sniper2.mdl",
	"models/player/soldier/soldier2.mdl",
	"models/player/demo/demo2.mdl",
	"models/player/medic/medic2.mdl",
	"models/player/hvyweapon/hvyweapon2.mdl",
	"models/player/pyro/pyro2.mdl",
	"models/player/spy/spy2.mdl",
	"models/player/engineer/engineer2.mdl",
	"models/player.mdl",
	"models/player/civilian/civilian.mdl",
};

char *sClassModels[] =
{
	"",
	"scout",
	"sniper",
	"soldier",
	"demo",
	"medic",
	"hvyweapon",
	"pyro",
	"spy",
	"engineer",
	"",
	"civilian",
};

char *sClassCfgs[] =
{
	"",
	"exec scout.cfg\n",
	"exec sniper.cfg\n",
	"exec soldier.cfg\n",
	"exec demoman.cfg\n",
	"exec medic.cfg\n",
	"exec hwguy.cfg\n",
	"exec pyro.cfg\n",
	"exec spy.cfg\n",
	"exec engineer.cfg\n",
	"",
	"exec civilian.cfg\n",
};

char *sGrenadeNames[] =
{
	"",
	"Normal",
	"Concussion",
	"Nail",
	"Mirv",
	"Napalm",
	"",
	"Gas",
	"EMP",
	"Caltrop",
	"",
};

string_t team_menu_string;

int toggleflags;

CBaseEntity *g_pLastSpawns[5];


//=========================================================
// Pipebombs: 8 per demoman, ammoboxes: 3 per player
//=========================================================

// bAll: detonate all of this player's pipebombs (only ones at least 0.6s
// old unless bForceDetonation), else just the oldest one
void CBasePlayer::ExplodeOldPipebomb( BOOL bAll, BOOL bForceDetonation )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "tf_gl_pipebomb" );
	if ( !pEnt )
		return;

	if ( !bAll )
	{
		CTFGrenade *pOldestPB = NULL;

		while ( pEnt )
		{
			CBaseEntity *pOwner = CBaseEntity::Instance( pEnt->pev->owner );
			if ( pOwner == this )
			{
				if ( !pOldestPB || ((CTFGrenade *)pEnt)->m_flCreationTime < pOldestPB->m_flCreationTime )
					pOldestPB = (CTFGrenade *)pEnt;
			}
			pEnt = UTIL_FindEntityByClassname( pEnt, "tf_gl_pipebomb" );
		}

		if ( pOldestPB )
			pOldestPB->pev->nextthink = gpGlobals->time;
	}
	else
	{
		while ( pEnt )
		{
			CBaseEntity *pOwner = CBaseEntity::Instance( pEnt->pev->owner );
			CTFGrenade *pPB = (CTFGrenade *)pEnt;

			if ( pOwner == this && ( bForceDetonation || pPB->m_flCreationTime + 0.6 <= gpGlobals->time ) )
				pPB->pev->nextthink = gpGlobals->time;

			pEnt = UTIL_FindEntityByClassname( pEnt, "tf_gl_pipebomb" );
		}
	}
}

void CBasePlayer::RemovePipebombs( void )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "tf_gl_pipebomb" );
	while ( pEnt )
	{
		CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pEnt->pev->owner );
		if ( pOwner == this )
		{
			m_iPipebombCount--;
			pEnt->pev->flags |= FL_KILLME;
		}
		pEnt = UTIL_FindEntityByClassname( pEnt, "tf_gl_pipebomb" );
	}
}

void CBasePlayer::RemoveOldAmmobox( void )
{
	CWeaponBox *pOldestBox = NULL;

	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "tf_ammobox" );
	if ( !pEnt )
		return;

	while ( pEnt )
	{
		CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pEnt->pev->enemy );
		if ( pOwner == this )
		{
			if ( !pOldestBox || ((CWeaponBox *)pEnt)->m_flCreationTime < pOldestBox->m_flCreationTime )
				pOldestBox = (CWeaponBox *)pEnt;
		}
		pEnt = UTIL_FindEntityByClassname( pEnt, "tf_ammobox" );
	}

	if ( pOldestBox )
		pOldestBox->pev->nextthink = gpGlobals->time;
}

//=========================================================
// Timers: "timer" entities owned by the player they affect
//=========================================================
class CTimer : public CBaseEntity
{
};

LINK_ENTITY_TO_CLASS( timer, CTimer );

// TF_TIMER_ANY finds any of the owner's timers
CBaseEntity *CBaseEntity::FindTimer( int iTimerType )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "timer" );
	while ( pEnt )
	{
		if ( pEnt->pev->owner == edict() && ( iTimerType == TF_TIMER_ANY || pEnt->timer_type == iTimerType ) )
			return pEnt;
		pEnt = UTIL_FindEntityByClassname( pEnt, "timer" );
	}
	return NULL;
}

CBaseEntity *CBaseEntity::CreateTimer( int iTimerType )
{
	CBaseEntity *pTimer = CBaseEntity::Create( "timer", g_vecZero, g_vecZero, edict() );
	pTimer->timer_type = iTimerType;
	return pTimer;
}

// Medic infection: 8 damage every 3 seconds, spreads to nearby enemies
void CBaseEntity::Timer_Infection( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );	// infected player
	CBaseEntity *pEnemy = CBaseEntity::Instance( pev->enemy );	// the medic
	BOOL bRemoveMe = FALSE;

	// Changed to the medic's team
	if ( ( (int)gpGlobals->teamplay & ( TEAMPLAY_HALFDIRECT | TEAMPLAY_NODIRECT | TEAMPLAY_HALFEXPLOSIVE | TEAMPLAY_NOEXPLOSIVE ) )
		&& pOwner->team_no == pEnemy->team_no )
	{
		bRemoveMe = pOwner->team_no != 0;
	}

	// Respawned (spawn protection)
	if ( gpGlobals->time < pOwner->invincible_finished )
		bRemoveMe = TRUE;

	if ( !( pOwner->tfstate & TFSTATE_INFECTED ) || pOwner->pev->playerclass == PC_MEDIC || bRemoveMe )
	{
		pOwner->tfstate &= ~TFSTATE_INFECTED;
		SetThink( &CBaseEntity::SUB_Remove );
		pev->nextthink = gpGlobals->time;
		return;
	}

	// Pass it on to anyone close enough
	Vector vecSrc = pOwner->pev->origin;
	CBaseEntity *pEntity = NULL;
	while ( ( pEntity = UTIL_FindEntityInSphere( pEntity, vecSrc, 128 ) ) != NULL )
	{
		if ( pEntity->Classify() != CLASS_PLAYER )
			continue;
		if ( !pEntity->IsAlive() || !pEntity->pev->playerclass || ( pEntity->tfstate & TFSTATE_INFECTED ) || pEntity->pev->playerclass == PC_MEDIC )
			continue;

		// Not the medic's team mates or allies
		if ( (int)gpGlobals->teamplay & ( TEAMPLAY_HALFDIRECT | TEAMPLAY_NODIRECT | TEAMPLAY_HALFEXPLOSIVE | TEAMPLAY_NOEXPLOSIVE ) )
		{
			if ( pEnemy->team_no && pEntity->team_no
				&& ( ( teamallies[pEntity->team_no] & ( 1 << ( pEnemy->team_no - 1 ) ) ) || pEnemy->team_no == pEntity->team_no ) )
				continue;
		}

		TraceResult tr;
		Vector vecTarget = pEntity->BodyTarget( vecSrc );
		UTIL_TraceLine( vecSrc, vecTarget, dont_ignore_monsters, edict(), &tr );

		if ( tr.flFraction == 1.0 || tr.pHit == pEntity->edict() )
		{
			EMIT_SOUND( pEntity->edict(), CHAN_VOICE, "player/death2.wav", 1, ATTN_NORM );

			pEntity->tfstate |= TFSTATE_INFECTED;

			CBaseEntity *pTimer = pEntity->CreateTimer( TF_TIMER_INFECTION );
			pTimer->pev->nextthink = gpGlobals->time + 2;
			pTimer->SetThink( &CBaseEntity::Timer_Infection );
			pTimer->pev->enemy = pev->enemy;
			pEntity->infection_team_no = pOwner->team_no;

			ClientPrint( pEntity->pev, HUD_PRINTNOTIFY, "#Medic_infected", STRING( pOwner->pev->netname ) );
			ClientPrint( pOwner->pev, HUD_PRINTNOTIFY, "#Medic_infect", STRING( pEntity->pev->netname ) );

			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Passed_On_Infection\" against \"%s<%i><%s><%s>\"\n",
				STRING( pOwner->pev->netname ),
				GETPLAYERUSERID( pOwner->edict() ),
				GETPLAYERAUTHID( pOwner->edict() ),
				pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR",
				STRING( pEntity->pev->netname ),
				GETPLAYERUSERID( pEntity->edict() ),
				GETPLAYERAUTHID( pEntity->edict() ),
				pEntity->team_no ? GetTeamName( pEntity->team_no ) : "SPECTATOR" );
		}
	}

	pev->nextthink = gpGlobals->time + 3;

	SpawnBlood( pOwner->pev->origin, pOwner->BloodColor(), 8 );

	if ( pOwner->IsAlive() )
	{
		pOwner->TakeDamage( pev, pEnemy->pev, 8, DMG_IGNOREARMOR | DMG_NERVEGAS );

		if ( !pOwner->IsAlive() )
		{
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
				STRING( pEnemy->pev->netname ),
				GETPLAYERUSERID( pEnemy->edict() ),
				GETPLAYERAUTHID( pEnemy->edict() ),
				pEnemy->team_no ? GetTeamName( pEnemy->team_no ) : "SPECTATOR",
				STRING( pOwner->pev->netname ),
				GETPLAYERUSERID( pOwner->edict() ),
				GETPLAYERAUTHID( pOwner->edict() ),
				pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR",
				"infection" );
		}
	}
}

// Overheal (and megahealth) rots back down to max health
void CBaseEntity::Timer_HealthRot( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	if ( pOwner->pev->health > pOwner->pev->max_health )
	{
		pOwner->pev->health -= 1;
		pev->nextthink = gpGlobals->time + 1;
		return;
	}

	pOwner->items &= ~IT_SUPERHEALTH;

	// The megahealth item that gave it can respawn now
	if ( !FNullEnt( pev->enemy ) )
	{
		CBaseEntity *pEnemy = CBaseEntity::Instance( pev->enemy );
		pEnemy->Respawn();
		return;
	}

	SetThink( &CBaseEntity::SUB_Remove );
	pev->nextthink = gpGlobals->time;
}

// Concussion hallucinations: fake sounds and effects only the victim sees
void CBaseEntity::Timer_Hallucination( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	pev->health -= 2.5;
	if ( pOwner->pev->playerclass == PC_MEDIC )	// medics get over it twice as fast
		pev->health -= 2.5;

	if ( pev->health <= 0 || pOwner->pev->deadflag || pOwner->has_disconnected )
		pOwner->tfstate &= ~TFSTATE_HALLUCINATING;

	if ( !( pOwner->tfstate & TFSTATE_HALLUCINATING ) )
	{
		UTIL_Remove( this );
		return;
	}

	pev->nextthink = gpGlobals->time + 0.3;

	switch ( RANDOM_LONG( 0, 20 ) )
	{
	case 0:
		CLIENT_COMMAND( pOwner->edict(), "play weapons/cbar_hit1.wav\n" );
		break;

	case 1:
		CLIENT_COMMAND( pOwner->edict(), "play weapons/cbar_hitbod1.wav\n" );
		UTIL_ScreenShakeOne( pOwner->edict(), 12, 10, 0.9 );
		break;

	case 2:
	{
		// Explosion nearby
		UTIL_MakeVectors( pOwner->pev->angles );
		Vector vecPos = pOwner->pev->origin + gpGlobals->v_forward * RANDOM_FLOAT( 100, 300 );
		vecPos = vecPos + gpGlobals->v_right * RANDOM_FLOAT( -100, 100 );

		MESSAGE_BEGIN( MSG_ONE, SVC_TEMPENTITY, NULL, pOwner->pev );
			WRITE_BYTE( TE_EXPLOSION );
			WRITE_COORD( vecPos.x );
			WRITE_COORD( vecPos.y );
			WRITE_COORD( vecPos.z );
			WRITE_SHORT( g_sModelIndexFireball );
			WRITE_BYTE( 20 );	// scale * 10
			WRITE_BYTE( 12 );	// framerate
			WRITE_BYTE( TE_EXPLFLAG_NOADDITIVE | TE_EXPLFLAG_NODLIGHTS );
		MESSAGE_END();
		break;
	}

	case 3:
	{
		// A grenade lands nearby
		UTIL_MakeVectors( pOwner->pev->angles );
		Vector vecPos = pOwner->pev->origin;
		vecPos.z += RANDOM_FLOAT( 0, 128 );
		vecPos = vecPos + gpGlobals->v_right * RANDOM_FLOAT( -128, 128 );

		float flSpeed = pOwner->pev->velocity.Length();

		short sModelIndex;
		switch ( RANDOM_LONG( 0, 3 ) )
		{
		case 0:		sModelIndex = g_sModelIndexMirvGrenade; break;
		case 1:		sModelIndex = g_sModelIndexGrenade; break;
		case 2:		sModelIndex = g_sModelIndexNapalmGrenade; break;
		case 3:		sModelIndex = g_sModelIndexNailGrenade; break;
		default:	sModelIndex = 0; break;
		}

		if ( UTIL_PointContents( vecPos ) != CONTENTS_SOLID )
		{
			Vector vecVelocity = pOwner->pev->v_angle;
			vecVelocity.y = UTIL_AngleMod( vecVelocity.y + RANDOM_FLOAT( -50, 50 ) );
			UTIL_MakeVectors( vecVelocity );
			Vector vecTossVel = gpGlobals->v_forward * ( flSpeed + RANDOM_FLOAT( 200, 400 ) );

			MESSAGE_BEGIN( MSG_ONE, SVC_TEMPENTITY, NULL, pOwner->pev );
				WRITE_BYTE( TE_MODEL );
				WRITE_COORD( vecPos.x );
				WRITE_COORD( vecPos.y );
				WRITE_COORD( vecPos.z );
				WRITE_COORD( vecTossVel.x );
				WRITE_COORD( vecTossVel.y );
				WRITE_COORD( vecTossVel.z );
				WRITE_ANGLE( 0 );	// yaw
				WRITE_SHORT( sModelIndex );
				WRITE_BYTE( 0 );	// bounce sound
				WRITE_BYTE( 25 );	// life
			MESSAGE_END();
		}
		break;
	}

	case 4:
		// "On fire"
		MESSAGE_BEGIN( MSG_ONE, SVC_TEMPENTITY, NULL, pOwner->pev );
			WRITE_BYTE( TE_PLAYERSPRITES );
			WRITE_SHORT( ENTINDEX( pOwner->edict() ) );
			WRITE_SHORT( g_sModelIndexPlayerFlame );
			WRITE_BYTE( 5 );	// count
			WRITE_BYTE( 25 );	// variance
		MESSAGE_END();
		break;

	case 5:
	{
		// Nails flying past from behind
		UTIL_MakeVectors( pOwner->pev->v_angle );
		gpGlobals->v_forward.z = 0;

		Vector vecSrc = pOwner->pev->origin - gpGlobals->v_forward * 200;
		vecSrc = vecSrc + gpGlobals->v_right * RANDOM_FLOAT( -100, 100 );
		vecSrc.z += 0.8 * pOwner->pev->view_ofs.z;

		Vector vecFireAngle = UTIL_VecToAngles( gpGlobals->v_forward );
		vecFireAngle.y += RANDOM_FLOAT( -6, 6 );

		if ( UTIL_PointContents( vecSrc ) != CONTENTS_SOLID )
		{
			for ( int i = 0; i < 3; i++ )
			{
				UTIL_MakeVectors( vecFireAngle );
				Vector vecVelocity = gpGlobals->v_forward * ( 600 - i * 20 );

				MESSAGE_BEGIN( MSG_ONE, SVC_TEMPENTITY, NULL, pOwner->pev );
					WRITE_BYTE( TE_PROJECTILE );
					WRITE_COORD( vecSrc.x );
					WRITE_COORD( vecSrc.y );
					WRITE_COORD( vecSrc.z );
					WRITE_COORD( vecVelocity.x );
					WRITE_COORD( vecVelocity.y );
					WRITE_COORD( vecVelocity.z );
					WRITE_SHORT( g_sModelIndexNail );
					WRITE_BYTE( 6 );	// life
					WRITE_BYTE( ENTINDEX( pOwner->edict() ) );
				MESSAGE_END();

				vecFireAngle.y += RANDOM_FLOAT( 4, 8 );
				vecSrc.z += RANDOM_FLOAT( -10, 10 );
			}
		}
		break;
	}

	case 6:
	{
		// Shotgun blast
		Vector vecDir = pOwner->pev->v_angle;
		vecDir.x += RANDOM_FLOAT( -15, 15 );
		vecDir.y += RANDOM_FLOAT( -50, 50 );
		vecDir.z += RANDOM_FLOAT( -25, 25 );
		Vector vecAngles = UTIL_VecToAngles( vecDir );

		int decalIndex = gDecals[DECAL_GUNSHOT1].index;
		if ( decalIndex >= 0 )
		{
			CLIENT_COMMAND( pOwner->edict(), "play weapons/sbarrel1.wav\n" );

			MESSAGE_BEGIN( MSG_ONE, SVC_TEMPENTITY, NULL, pOwner->pev );
				WRITE_BYTE( TE_MULTIGUNSHOT );
				WRITE_COORD( pOwner->pev->origin.x );
				WRITE_COORD( pOwner->pev->origin.y );
				WRITE_COORD( pOwner->pev->origin.z );
				WRITE_COORD( vecDir.x * 10 );
				WRITE_COORD( vecDir.y * 10 );
				WRITE_COORD( vecDir.z * 10 );
				WRITE_COORD( 80 );	// x noise
				WRITE_COORD( 80 );	// y noise
				WRITE_BYTE( 6 );	// count
				WRITE_BYTE( decalIndex );
			MESSAGE_END();
		}
		break;
	}
	}
}

void CBaseEntity::Timer_Tranquilisation( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pev->owner );

	ClientPrint( pOwner->pev, HUD_PRINTNOTIFY, "#Tranq_finished" );
	pOwner->tfstate &= ~TFSTATE_TRANQUILISED;
	pOwner->TeamFortress_SetSpeed();

	SetThink( &CBaseEntity::SUB_Remove );
	pev->nextthink = gpGlobals->time;
}

// Medics heal 2 every 3 seconds
void CBaseEntity::Timer_Regeneration( void )
{
	CBaseEntity *pOwner = CBaseEntity::Instance( pev->owner );

	pev->nextthink = gpGlobals->time + 3;

	if ( pOwner->pev->health < pOwner->pev->max_health )
	{
		pOwner->pev->health += 2;
		if ( pOwner->pev->health > pOwner->pev->max_health )
			pOwner->pev->health = pOwner->pev->max_health;
	}
}

// Birthday/Christmas mode: a party every 3-4 minutes, with a message
// (weapon counts the steps, team_str_moved holds the message)
void CBaseEntity::Timer_Birthday( void )
{
	if ( weapon < 6 )
	{
		pev->nextthink = gpGlobals->time + 1.5;
		weapon++;

		UTIL_ClientPrintAll( HUD_PRINTCENTER, STRING( team_str_moved ) );

		CBaseEntity *client = NULL;
		while ( ( client = UTIL_FindEntityByClassname( client, "player" ) ) != NULL && !FNullEnt( client->edict() ) )
		{
			if ( !client->pev || client->has_disconnected )
				continue;

			if ( weapon == 1 )
			{
				if ( christmas )
					EMIT_SOUND( client->edict(), CHAN_VOICE, "misc/b2.wav", 1, ATTN_NORM );
				else
					EMIT_SOUND( client->edict(), CHAN_VOICE, "misc/b1.wav", 1, ATTN_NORM );
			}
			else if ( weapon < 5 )
			{
				if ( RANDOM_LONG( 0, 1 ) )
					EMIT_SOUND( client->edict(), CHAN_ITEM, "misc/party2.wav", 1, ATTN_NORM );
				else
					EMIT_SOUND( client->edict(), CHAN_ITEM, "misc/party1.wav", 1, ATTN_NORM );
			}
		}
		return;
	}

	weapon = 0;
	pev->nextthink = gpGlobals->time + RANDOM_FLOAT( 180, 240 );

	float rnum = RANDOM_FLOAT( 0, 1 );
	if ( rnum < 0.02 )
	{
		if ( christmas )
			team_str_moved = MAKE_STRING( "\n\n\n\nMERRY CHRISTMAS!!\n" );
		else
			team_str_moved = MAKE_STRING( "\n\n\n\nHAPPY BIRTHDAY TEAMFORTRESS!\n" );
	}
	else if ( rnum < 0.04 )
		team_str_moved = MAKE_STRING( UTIL_VarArgs( "\n\n\n\nCurrent number of Snipers on\nthe Battlements Worldwide: %d\n", RANDOM_FLOAT( 1000, 5000 ) ) );	// sic: float for %d
	else if ( rnum < 0.06 )
		team_str_moved = MAKE_STRING( "\n\n\n\nYeeha!\nThe 505,672nd detpack was\njust laid on the bridge!\n" );
	else if ( rnum < 0.08 )
		team_str_moved = MAKE_STRING( "\n\n\n\nIs that an assault cannon in your\n pocket, or are you just playing TF?\n(Blame Ian)\n" );
	else if ( rnum < 0.1 )
		team_str_moved = MAKE_STRING( "\n\n\n\n25,000 downloads\n50 donations\nDamn, but we rock!\n" );
	else if ( rnum < 0.12 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTeamFortress is one year old today!\n" );
	else if ( rnum < 0.14 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF II available soon!\n" );
	else if ( rnum < 0.16 )
		team_str_moved = MAKE_STRING( "\n\n\n\nhmm.... I wonder what the next\nmessage will be...\n" );
	else if ( rnum < 0.18 )
		team_str_moved = MAKE_STRING( "\n\n\n\nKill your friends! Kill your family!\nSnipe your pets! Detpack your house!\nGet TF Now!\n" );
	else if ( rnum < 0.2 )
		team_str_moved = MAKE_STRING( "\n\n\n\nDeath to Potatoes!\n" );
	else if ( rnum < 0.22 )
		team_str_moved = MAKE_STRING( "\n\n\n\n\"You guys have really screwed up\n urinals, you know that?\"\n   - TyR in Australia\n" );
	else if ( rnum < 0.24 )
		team_str_moved = MAKE_STRING( "\n\n\n\nMany potatoes were harmed in the\nmaking of this product.\n" );
	else if ( rnum < 0.25 )
		team_str_moved = MAKE_STRING( "\n\n\n\nBAH! I shoulda put the Demoman\nblast armor back while I was at it!\n   - Gudlyf\n" );
	else if ( rnum < 0.26 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTwin Peaks will be out... uhh...\nerr... soon.\n" );
	else if ( rnum < 0.28 )
		team_str_moved = MAKE_STRING( "\n\n\n\n\"Twin Peaks will be finished tomorrow.\"\n   - TyR, 16th July, 25th July, 2nd August..." );
	else if ( rnum < 0.3 )
		team_str_moved = MAKE_STRING( "\n\n\n\n\"After all, TF is an INSULT to the\npurity of CTF!\"\n   - Mjollnir, who was joking... really!" );
	else if ( rnum < 0.32 )
		team_str_moved = MAKE_STRING( "\n\n\n\n\"I force them to work.\nElse I cut back their supplies\"\n   - Vomitgod, on TFS\n" );
	else if ( rnum < 0.34 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen you had to use imin1 & imin2\nto join a team.\n" );
	else if ( rnum < 0.36 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen there were 2 TF servers...\nand they were always down." );
	else if ( rnum < 0.38 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen no-one knew how to use\nhand grenades...\n" );
	else if ( rnum < 0.4 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen 2fort was the only TF map.\nWe sure have come a long\nway since then... sigh" );
	else if ( rnum < 0.42 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen the sniper rifle just\nkilled in one hit... everytime\n" );
	else if ( rnum < 0.44 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen I could download TF in\n1 minute 20 seconds\n" );
	else if ( rnum < 0.46 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen I didn't have to download\nANYTHING to play TF\n" );
	else if ( rnum < 0.48 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen players used to say\n\"What's that bubble?\"\n" );
	else if ( rnum < 0.5 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen The Well actually had a well...\n" );
	else if ( rnum < 0.52 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen the motion detector was officially\nthe Scout's best friend, at least\naccording to the readme.txt\n" );
	else if ( rnum < 0.54 )
		team_str_moved = MAKE_STRING( "\n\n\n\nI remember the good ol' days...\nwhen  Ian went to jail for punching\nRobin out\n" );
	else if ( rnum < 0.56 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #1:\nUmm... How do I set a detpack?\n" );
	else if ( rnum < 0.58 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #2:\nUmm... How do I throw a grenade?\n" );
	else if ( rnum < 0.6 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #3:\nHey, he is cheating, that soldier just jumped up to the roof!!\n" );
	else if ( rnum < 0.62 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #4:\nHow do I throw the pins?\n" );
	else if ( rnum < 0.64 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #5:\nWhere do I take the flag!?!?!\n" );
	else if ( rnum < 0.66 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #6:\nWhere's the control room?\n" );
	else if ( rnum < 0.68 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #7:\nWhy the hell are these backpacks\nexploding?\n" );
	else if ( rnum < 0.7 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #8:\nWho's the maniac with the axe?\n" );
	else if ( rnum < 0.72 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #9:\nStop shooting me!\nI'm on your team!\nYou tried to attack my with the axe!\n" );
	else if ( rnum < 0.74 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Newbie Quote #10:\nWhat's this key? I thought this\nwas a CTF style map, guys?\n" );
	else if ( rnum < 0.76 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #1:\nUm, Red Medics, please don't\nheal the Hunted.\n" );
	else if ( rnum < 0.78 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #2:\nGuys could you NOT set up\nsentries in Hunted?\n" );
	else if ( rnum < 0.8 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #3:\nWho the hell is on\nthe lift?\n" );
	else if ( rnum < 0.82 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #4:\nDISCARD!!\n" );
	else if ( rnum < 0.84 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #5:\nDamn Snipers!\n" );
	else if ( rnum < 0.86 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #6:\nDamn Snipers!\n" );
	else if ( rnum < 0.88 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #7:\nGet a mask or\nget in the WATER!!\n" );
	else if ( rnum < 0.9 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #8:\nSpy's, please change colors\noutside our base.\n" );
	else if ( rnum < 0.92 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #9:\nI was typing!!\n" );
	else if ( rnum < 0.94 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF Veteran Quote #10:\nWhy is that guy running\nout of our yard with\nthe flag???\n" );
	else if ( rnum < 0.96 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF's original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_1.gif" );
	else if ( rnum < 0.98 )
		team_str_moved = MAKE_STRING( "\n\n\n\nTF's original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_2.gif" );
	else
		team_str_moved = MAKE_STRING( "\n\n\n\n\"MJ: Did you hear John Cash wrote TF?\"\n   - VomitGod" );
}

// The demoman's detpack has been set
void CBaseEntity::Timer_DetpackSet( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pev->owner );

	pOwner->tfstate &= ~TFSTATE_CANT_MOVE;
	pOwner->is_detpacking = FALSE;
	pOwner->TeamFortress_SetSpeed();
	pOwner->m_pActiveItem->Deploy();

	// The timer's health holds the fuse length
	CBaseEntity *Detpack = CBaseEntity::Create( "detpack", pOwner->pev->origin, Vector( 0, 0, 0 ), pOwner->edict() );
	Detpack->pev->health = gpGlobals->time + pev->health;

	ClientPrint( pOwner->pev, HUD_PRINTNOTIFY, "#Detpack_finishset" );

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Detpack_Set\"\n",
		STRING( pOwner->pev->netname ),
		GETPLAYERUSERID( pOwner->edict() ),
		GETPLAYERAUTHID( pOwner->edict() ),
		pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

	dremove( this );
}

// A scout finished disarming a detpack
void CBaseEntity::Timer_DetpackDisarm( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pev->owner );
	CBaseEntity *pEnemy = CBaseEntity::Instance( pev->enemy );
	CBasePlayer *pEnemyOwner = (CBasePlayer *)CBaseEntity::Instance( pEnemy->pev->owner );

	if ( pOwner->IsAlive() && pEnemy->weaponmode )
	{
		if ( birthday == 1 )
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Detpack_disarm_bday", STRING( pOwner->pev->netname ), STRING( pEnemyOwner->pev->netname ) );
		else
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Detpack_disarm", STRING( pEnemyOwner->pev->netname ), STRING( pOwner->pev->netname ) );

		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%s><%s>\"\n",
			STRING( pEnemyOwner->pev->netname ),
			GETPLAYERUSERID( pEnemyOwner->edict() ),
			GETPLAYERAUTHID( pEnemyOwner->edict() ),
			pEnemyOwner->team_no ? GetTeamName( pEnemyOwner->team_no ) : "SPECTATOR",
			STRING( pOwner->pev->netname ),
			GETPLAYERUSERID( pOwner->edict() ),
			GETPLAYERAUTHID( pOwner->edict() ),
			pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

		pOwner->tfstate &= ~TFSTATE_CANT_MOVE;
		pOwner->TeamFortress_SetSpeed();
		pOwner->TF_AddFrags( 1 );
		dremove( pEnemy );
	}

	dremove( this );
}

// Close the building menu if the engineer walks away from it
void CBaseEntity::Timer_CheckBuildDistance( void )
{
	if ( FNullEnt( pev->owner ) || FNullEnt( pev->enemy ) )
	{
		UTIL_Remove( this );
		return;
	}

	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pev->owner );
	CBaseEntity *pEnemy = CBaseEntity::Instance( pev->enemy );

	if ( pOwner->building && (CBaseEntity *)pOwner->building == pEnemy )
	{
		if ( ( pEnemy->pev->origin - pOwner->pev->origin ).Length() <= 64 )
		{
			pev->nextthink = gpGlobals->time + 0.3;
			return;
		}

		pOwner->ResetMenu();
		pOwner->building = NULL;
	}

	UTIL_Remove( this );
}

void CBaseEntity::Timer_FinishedBuilding( void )
{
	if ( FNullEnt( pev->owner ) )
	{
		UTIL_Remove( this );
		return;
	}

	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pev->owner );

	STOP_SOUND( pOwner->edict(), CHAN_STATIC, "weapons/building.wav" );

	if ( pOwner->is_building == TRUE )
	{
		pOwner->tfstate &= ~TFSTATE_CANT_MOVE;
		pOwner->is_building = FALSE;
		pOwner->TeamFortress_SetSpeed();

		if ( pOwner->m_pActiveItem )
			pOwner->m_pActiveItem->Deploy();

		if ( pOwner->building )
		{
			pOwner->building->Finished();
			pOwner->building = NULL;
		}
	}

	dremove( this );
}

// Disguise finished; the timer's skin/team_no are the disguise
void CBaseEntity::Timer_SpyUndercoverThink( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pev->owner );

	if ( pOwner->is_undercover == 2 )
	{
		pOwner->immune_to_check = gpGlobals->time + 10;

		if ( pev->skin )
		{
			ClientPrint( pOwner->pev, HUD_PRINTNOTIFY, "#Disguise_asclass", UTIL_VarArgs( "#%s", sClassNames[pev->skin] ) );
			pOwner->undercover_skin = pev->skin;
		}

		if ( team_no )
		{
			ClientPrint( pOwner->pev, HUD_PRINTNOTIFY, "#Disguise_asteam", UTIL_dtos1( team_no ) );
			pOwner->undercover_team = team_no;
		}

		ClientPrint( pOwner->pev, HUD_PRINTCENTER, "#Disguise_now" );
		pOwner->is_undercover = 1;
		pOwner->TeamFortress_SpyCalcName();
		pOwner->Spy_DisguiseExternalWeaponModel();
		pOwner->TeamFortress_SetSkin();
	}

	dremove( this );
}

// Clan battle cease fire: nag every 5 seconds until it's lifted
void CBaseEntity::Timer_CeaseFireThink( void )
{
	if ( gpGlobals->time > cb_ceasefire_time && weapon == 1 && cease_fire == 1 )
	{
		cease_fire = 0;
		UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_resumefire" );
		UTIL_LogPrintf( "World triggered \"Resume_Fire\"\n" );

		CBasePlayer *client = NULL;
		while ( ( client = (CBasePlayer *)UTIL_FindEntityByClassname( client, "player" ) ) != NULL && !FNullEnt( client->edict() ) )
		{
			if ( client->pev )
			{
				client->pev->iuser4 = 0;
				client->tfstate &= ~TFSTATE_CANT_MOVE;
				client->immune_to_check = gpGlobals->time + 10;
				client->TeamFortress_SetSpeed();
			}
		}
	}

	if ( !cease_fire )
	{
		dremove( this );
		return;
	}

	UTIL_ClientPrintAll( HUD_PRINTNOTIFY, "#Game_ceasefire" );
	UTIL_LogPrintf( "World triggered \"Cease_Fire\"\n" );
	pev->nextthink = gpGlobals->time + 5;
}

// Teamkill count expires
void CBaseEntity::Timer_AutokickThink( void )
{
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( pev->owner );
	pOwner->teamkills = 0;
	dremove( this );
}

CBaseEntity *CBaseEntity::FindTeamSpawnPoint( void )
{
	CBaseEntity *pSpot = g_pLastSpawns[team_no];
	int iAttemptsRemoved = 0;
	int iAttemptsTelefrag = 0;

	while ( 1 )
	{
		pSpot = UTIL_FindEntityByString( pSpot, "classname", "info_player_teamspawn" );
		if ( !pSpot )
		{
			pSpot = UTIL_FindEntityByString( NULL, "classname", "info_player_teamspawn" );
			if ( !pSpot )
				return NULL;
		}

		if ( !((CTFSpawn *)pSpot)->CheckTeam( team_no ) )
			continue;

		// Every spawn point for this team is removed
		if ( iAttemptsTelefrag == 0 && iAttemptsRemoved >= 128 )
			return NULL;

		if ( pSpot->goal_state == TFGS_REMOVED )
		{
			iAttemptsRemoved++;
			continue;
		}

		// Occupied; after 32 tries just telefrag
		if ( !IsSpawnPointValid( pSpot->pev->origin ) && iAttemptsTelefrag < 32 )
		{
			iAttemptsTelefrag++;
			continue;
		}

		if ( gpGlobals->time < cb_prematch_time )
			return pSpot;

		if ( ActivationSucceeded( pSpot, (CBasePlayer *)this, NULL ) )
		{
			g_pLastSpawns[team_no] = pSpot;
			return pSpot;
		}
	}

	return NULL;
}

// Drop the ammo this class can't use in a backpack; engineers turn
// metal into ammo for team mates
void CBasePlayer::TeamFortress_Discard( void )
{
	int iShellsDropped = 0;
	int iNailsDropped, iRocketsDropped, iCellsDropped;
	int iNails, iRockets, iCells;

	switch ( pev->playerclass )
	{
	case PC_SCOUT:
	case PC_SNIPER:
	case PC_MEDIC:
	case PC_SPY:
		iNails = ammo_nails;		iNailsDropped = 0;
		iRockets = 0;				iRocketsDropped = ammo_rockets;
		iCells = 0;					iCellsDropped = ammo_cells;
		break;
	case PC_SOLDIER:
	case PC_DEMOMAN:
		iNails = 0;					iNailsDropped = ammo_nails;
		iRockets = ammo_rockets;	iRocketsDropped = 0;
		iCells = 0;					iCellsDropped = ammo_cells;
		break;
	case PC_HVYWEAP:
		iNails = 0;					iNailsDropped = ammo_nails;
		iRockets = 0;				iRocketsDropped = ammo_rockets;
		iCells = 0;					iCellsDropped = ammo_cells;
		break;
	case PC_PYRO:
		iNails = 0;					iNailsDropped = ammo_nails;
		iRockets = ammo_rockets;	iRocketsDropped = 0;
		iCells = ammo_cells;		iCellsDropped = 0;
		break;
	case PC_ENGINEER:	// the railgun uses nails
		iNails = ammo_nails;		iNailsDropped = 0;
		iRockets = 0;				iRocketsDropped = ammo_rockets;
		iCells = ammo_cells;		iCellsDropped = 0;
		break;
	default:
		iNails = ammo_nails;		iNailsDropped = 0;
		iRockets = ammo_rockets;	iRocketsDropped = 0;
		iCells = ammo_cells;		iCellsDropped = 0;
		break;
	}

	ammo_nails = iNails;
	ammo_cells = iCells;
	ammo_rockets = iRockets;

	if ( pev->playerclass == PC_ENGINEER )
	{
		// Split the metal between shells, cells, and nails/rockets if
		// there aren't many of those already
		float iTypesToMake;
		if ( iNailsDropped < 20 )
			iTypesToMake = ( iRocketsDropped < 10 ) ? 4 : 3;
		else
			iTypesToMake = ( iRocketsDropped < 10 ) ? 3 : 2;

		float iCellsForEach = (int)floor( iCells / iTypesToMake );
		float flHalf = iCellsForEach * 0.5;

		// shells: 2 cells each, 20 max
		if ( floor( flHalf ) > 20 )
			iShellsDropped = 20;
		else
			iShellsDropped = floor( flHalf );
		if ( iShellsDropped )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Drop_shells" );
			ammo_cells -= iShellsDropped * 2;
		}

		// cells: 2 cells each (sic), 10 max
		if ( floor( flHalf ) > 10 )
			iCellsDropped = 10;
		else
			iCellsDropped = floor( flHalf );
		if ( iCellsDropped )
		{
			ClientPrint( pev, HUD_PRINTNOTIFY, "#Drop_cells" );
			ammo_cells -= iCellsDropped * 2;
		}

		// nails: 1 cell each, up to 20 in the pack
		if ( iNailsDropped < 20 )
		{
			int iNailsCreated = min( (float)( 20 - iNailsDropped ), (float)( floor( iCellsForEach ) + iNailsDropped ) );
			if ( iNailsCreated )
			{
				ClientPrint( pev, HUD_PRINTNOTIFY, "#Drop_nails" );
				ammo_cells -= iNailsCreated;
			}
			iNailsDropped += iNailsCreated;
		}

		// rockets: 2 cells each, up to 10 in the pack
		if ( iRocketsDropped < 10 )
		{
			int iRocketsCreated = min( (float)( 10 - iRocketsDropped ), (float)( floor( flHalf ) + iRocketsDropped ) );
			if ( iRocketsCreated )
			{
				ClientPrint( pev, HUD_PRINTNOTIFY, "#Drop_rockets" );
				iRocketsDropped += iRocketsCreated;
				ammo_cells -= iRocketsCreated * 2;
			}
		}
	}

	if ( !iRocketsDropped && !iNailsDropped && !iCellsDropped )
		return;

	if ( ++m_iAmmoboxCount > 3 )
		RemoveOldAmmobox();

	EMIT_SOUND( ENT( pev ), CHAN_ITEM, "items/ammopickup1.wav", 1, ATTN_NORM );

	CWeaponBox *pWeaponBox = GetClassPtr( (CWeaponBox *)NULL );
	pWeaponBox->Spawn();
	pWeaponBox->pev->netname = MAKE_STRING( "tf_ammobox" );
	pWeaponBox->pev->classname = MAKE_STRING( "tf_ammobox" );
	pWeaponBox->pev->enemy = edict();	// the dropper
	pWeaponBox->m_flTouchableAt = gpGlobals->time + 2;
	pWeaponBox->team_no = team_no;
	pWeaponBox->ammo_nails = iNailsDropped;
	pWeaponBox->ammo_rockets = iRocketsDropped;
	pWeaponBox->ammo_cells = iCellsDropped;
	pWeaponBox->m_flCreationTime = gpGlobals->time;
	pWeaponBox->ammo_shells = iShellsDropped;

	UTIL_SetOrigin( pWeaponBox->pev, pev->origin );
	UTIL_MakeVectors( pev->v_angle );
	pWeaponBox->pev->angles = g_vecZero;
	pWeaponBox->pev->velocity = gpGlobals->v_forward * 400 + gpGlobals->v_up * 200;

	pWeaponBox->SetThink( &CWeaponBox::Kill );
	pWeaponBox->pev->nextthink = gpGlobals->time + 30;
}

// "Save me": medics, engineers and spies see an icon over the player
void CBasePlayer::TeamFortress_SaveMe( void )
{
	if ( last_saveme_sound < gpGlobals->time )
	{
		if ( RANDOM_FLOAT( 0, 1 ) < 0.8 )
			EMIT_SOUND( ENT( pev ), CHAN_WEAPON, "speech/saveme1.wav", 1, ATTN_NORM );
		else
			EMIT_SOUND( ENT( pev ), CHAN_WEAPON, "speech/saveme2.wav", 1, ATTN_NORM );

		last_saveme_sound = gpGlobals->time + 4;
	}

	CBaseEntity *client = NULL;
	while ( ( client = UTIL_FindEntityByClassname( client, "player" ) ) != NULL && !FNullEnt( client->edict() ) )
	{
		if ( !client->pev )
			continue;

		if ( client->pev->playerclass == PC_SPY || client->pev->playerclass == PC_MEDIC || client->pev->playerclass == PC_ENGINEER )
		{
			MESSAGE_BEGIN( MSG_ONE, SVC_TEMPENTITY, NULL, client->pev );
				WRITE_BYTE( TE_PLAYERATTACHMENT );
				WRITE_BYTE( ENTINDEX( edict() ) );
				WRITE_COORD( 50 );	// vertical offset
				WRITE_SHORT( g_sModelIndexSaveMe );
				WRITE_SHORT( 40 );	// life
			MESSAGE_END();
		}
	}
}

BOOL CBaseEntity::IsAlly( CBaseEntity *pOther )
{
	if ( !pOther->team_no || !team_no )
		return FALSE;

	if ( teamallies[team_no] & ( 1 << ( pOther->team_no - 1 ) ) )
		return TRUE;

	return pOther->team_no == team_no;
}

BOOL CBaseEntity::IsAlly( int iTeamNo )
{
	if ( !iTeamNo || !team_no )
		return FALSE;

	if ( teamallies[team_no] & ( 1 << ( iTeamNo - 1 ) ) )
		return TRUE;

	return iTeamNo == team_no;
}

BOOL CBaseEntity::IsTeammate( CBaseEntity *pOther )
{
	if ( pOther->team_no == team_no )
		return TRUE;

	return team_no == 0;
}

void CBasePlayer::TeamFortress_DisplayDetectionItems( void )
{
	CBaseEntity *pDetect = UTIL_FindEntityByClassname( NULL, "info_tfdetect" );
	if ( !pDetect )
		return;

	for ( int i = 0; i < 4; i++ )
	{
		if ( !pDetect->display_item_status[i] )
			continue;

		CBaseEntity *pItem = Finditem( pDetect->display_item_status[i] );
		if ( pItem )
			DisplayItemStatus( pDetect, this, pItem );
		else
			ClientPrint( pev, HUD_PRINTTALK, "#Item_missing" );
	}
}

void CBasePlayer::DisplayLocalItemStatus( CBaseEntity *pGoal )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( !pGoal->display_item_status[i] )
			continue;

		CBaseEntity *pItem = Finditem( pGoal->display_item_status[i] );
		if ( pItem )
			DisplayItemStatus( pGoal, this, pItem );
		else
			ClientPrint( pev, HUD_PRINTTALK, "#Item_missing" );
	}
}
