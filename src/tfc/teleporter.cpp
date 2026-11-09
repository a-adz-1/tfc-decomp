/***
*
*	Team Fortress Classic: Engineer teleporters, plus the building event
*	helpers shared by all buildings
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"
#include "effects.h"
#include "shake.h"
#include "tf_defs.h"

// Building event flags (iparam1 of events/misc/tf_buildingevent.sc), also
// kept in m_iBuildingEventState so late joiners can be told the state
#define BUILDING_EVENT_DAMAGE1			(1 << 0)	// light damage smoke
#define BUILDING_EVENT_DAMAGE2			(1 << 1)	// heavy damage sparks
#define BUILDING_EVENT_ENTRANCE_RINGS	(1 << 2)
#define BUILDING_EVENT_EXIT_RINGS		(1 << 3)
#define BUILDING_EVENT_READY			(1 << 5)
#define BUILDING_EVENT_TELEPORT_IN		(1 << 6)
#define BUILDING_EVENT_TELEPORT_OUT		(1 << 7)
#define BUILDING_EVENT_MOVED			(1 << 8)
#define BUILDING_EVENT_PARTICLES		(1 << 9)
#define BUILDING_EVENT_DESTROYED		(1 << 10)
#define BUILDING_EVENT_INFO				(1 << 11)	// state resend to one player

#define TELEPORTER_STATE_IDLE			1
#define TELEPORTER_STATE_READY			2
#define TELEPORTER_STATE_SENDING		3
#define TELEPORTER_STATE_RECEIVING		4
#define TELEPORTER_STATE_RECEIVING_RELEASE	5
#define TELEPORTER_STATE_RECHARGING		6

extern int gmsgResetFade;
extern int gmsgSpecFade;

Vector g_vRed = Vector( 255, 0, 0 );
Vector g_vBlue = Vector( 0, 0, 255 );
Vector g_vYellow = Vector( 255, 255, 0 );
Vector g_vGreen = Vector( 0, 255, 0 );
Vector g_vBlack = Vector( 0, 0, 0 );

LINK_ENTITY_TO_CLASS( building_teleporter, CTFTeleporter );

void CTFTeleporter::Spawn( void )
{
	Precache();

	pev->classname = MAKE_STRING( "building_teleporter" );
	pev->solid = SOLID_BBOX;
	pev->movetype = MOVETYPE_TOSS;
	pev->flags &= ~FL_ONGROUND;
	pev->velocity = Vector( 0, 0, 8 );
	pev->max_health = 125;
	pev->health = pev->max_health;
	pev->takedamage = DAMAGE_NO;

	// Team colours
	int topColor = teamcolors[team_no][10].topColor;
	pev->colormap = topColor | ( ( ( topColor + 10 ) & 0xFF ) << 8 );

	pev->flags |= FL_MONSTER;

	SET_MODEL( ENT( pev ), "models/teleporter.mdl" );
	UTIL_SetSize( pev, Vector( -16, -16, 0 ), Vector( 16, 16, 12 ) );
}

// Removed by the owner (dismantled, changed class, left the game)
void CTFTeleporter::Remove( void )
{
	char *type;
	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( real_owner->edict() );

	if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
	{
		pOwner->has_entry_teleporter = FALSE;
		type = "#Teleporter_Entrance_Destroyed";
	}
	else
	{
		pOwner->has_exit_teleporter = FALSE;
		type = "#Teleporter_Exit_Destroyed";
	}

	ClientPrint( pOwner->pev, HUD_PRINTCENTER, type );

	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
		(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

	if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
		pOwner->no_entry_teleporter_message = 0;
	else
		pOwner->no_exit_teleporter_message = 0;

	UTIL_LogPrintf( "\"<-1><><>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",
		type + 1,
		STRING( pOwner->pev->netname ),
		GETPLAYERUSERID( pOwner->edict() ),
		GETPLAYERAUTHID( pOwner->edict() ),
		pOwner->team_no ? GetTeamName( pOwner->team_no ) : "SPECTATOR" );

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

void CTFTeleporter::Precache( void )
{
	PRECACHE_MODEL( "models/teleporter.mdl" );
	PRECACHE_SOUND( "misc/teleport_out.wav" );
	PRECACHE_SOUND( "misc/teleport_in.wav" );
	PRECACHE_SOUND( "misc/teleport_ready.wav" );
	PRECACHE_SOUND( "misc/teleport_ready.wav" );	// sic: twice
	PRECACHE_MODEL( "sprites/shellchrome.spr" );
	PRECACHE_MODEL( "sprites/particle.spr" );
	m_iShardIndex = PRECACHE_MODEL( "models/computergibs.mdl" );
	m_usBuildingEvent = PRECACHE_EVENT( 1, "events/misc/tf_buildingevent.sc" );
}

CTFTeleporter *CTFTeleporter::CreateTeleporter( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, int type )
{
	CTFTeleporter *pBase = GetClassPtr( (CTFTeleporter *)NULL );

	UTIL_SetOrigin( pBase->pev, vecOrigin );
	pBase->pev->angles = g_vecZero;
	pBase->pev->angles.y = UTIL_AngleMod( pOwner->pev->angles.y + 180 );	// face the engineer
	pBase->real_owner = pOwner;
	pBase->team_no = pOwner->team_no;
	pBase->m_iType = type;
	pBase->Spawn();
	pBase->m_iDestroyed = FALSE;

	return pBase;
}

// Called when the build timer runs out
void CTFTeleporter::Finished( void )
{
	char *pszMessageToPlayer;
	char *pszMessageToTeam;

	if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
	{
		pszMessageToPlayer = "#Teleporter_Entrance_Finished";
		pszMessageToTeam = "#Teleporter_Entrance_Built";
		real_owner->has_entry_teleporter = TRUE;
	}
	else
	{
		pszMessageToPlayer = "#Teleporter_Exit_Finished";
		pszMessageToTeam = "#Teleporter_Exit_Built";
		real_owner->has_exit_teleporter = TRUE;
	}

	ClientPrint( real_owner->pev, HUD_PRINTNOTIFY, pszMessageToPlayer );
	teamsprint( team_no, real_owner, HUD_PRINTCENTER, pszMessageToTeam, STRING( real_owner->pev->netname ) );

	UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\"\n",
		STRING( real_owner->pev->netname ),
		GETPLAYERUSERID( real_owner->edict() ),
		GETPLAYERAUTHID( real_owner->edict() ),
		real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR",
		pszMessageToPlayer + 1 );

	real_owner->ammo_cells -= BUILD_COST_TELEPORTER;

	pev->takedamage = DAMAGE_AIM;
	m_iState = TELEPORTER_STATE_IDLE;
	SetTouch( &CTFTeleporter::TeleporterTouch );
	SetThink( &CTFTeleporter::TeleporterThink );
	pev->nextthink = gpGlobals->time + 0.1;

	pev->movetype = MOVETYPE_TOSS;
	pev->velocity = Vector( 0, 0, 8 );
	pev->flags &= ~FL_ONGROUND;

	m_vOldOrigin = pev->origin;

	EMIT_SOUND( ENT( pev ), CHAN_ITEM, "weapons/turrset.wav", 1, ATTN_NORM );
}

void CTFTeleporter::Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib )
{
	char weapon[30];
	char *type;
	int iPrintMessage;

	if ( m_iDestroyed )
		return;

	CBasePlayer *pOwner = (CBasePlayer *)CBaseEntity::Instance( real_owner->edict() );

	if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
	{
		iPrintMessage = pOwner->no_entry_teleporter_message;
		pOwner->has_entry_teleporter = FALSE;
		pOwner->no_entry_teleporter_message = 0;
		type = "#Teleporter_Entrance_Destroyed";
	}
	else
	{
		iPrintMessage = pOwner->no_exit_teleporter_message;
		pOwner->has_exit_teleporter = FALSE;
		pOwner->no_exit_teleporter_message = 0;
		type = "#Teleporter_Exit_Destroyed";
	}

	if ( !iPrintMessage )
		ClientPrint( pOwner->pev, HUD_PRINTCENTER, type );

	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
		(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DESTROYED, 0, 0, 0 );

	TeleporterKilled();

	SetThink( &CTFTeleporter::Teleporter_Explode );
	pev->nextthink = gpGlobals->time + 0.1;

	if ( pevAttacker && pevInflictor )
	{
		CBasePlayer *pPlayer = (CBasePlayer *)CBaseEntity::Instance( pevAttacker );

		GetWeapon( pevInflictor, pevAttacker, weapon );

		if ( pevAttacker == pevInflictor )
		{
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\"\n",
				STRING( real_owner->pev->netname ),
				GETPLAYERUSERID( real_owner->edict() ),
				GETPLAYERAUTHID( real_owner->edict() ),
				real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR",
				type + 1 );
		}
		else if ( pevAttacker != real_owner->pev )
		{
			UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\" with \"%s\"\n",
				STRING( pevAttacker->netname ),
				GETPLAYERUSERID( ENT( pevAttacker ) ),
				GETPLAYERAUTHID( ENT( pevAttacker ) ),
				pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
				type + 1,
				STRING( real_owner->pev->netname ),
				GETPLAYERUSERID( real_owner->edict() ),
				GETPLAYERAUTHID( real_owner->edict() ),
				real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR",
				weapon );
		}
	}

	m_iDestroyed = TRUE;
}

void CTFTeleporter::Teleporter_Explode( void )
{
	MESSAGE_BEGIN( MSG_PVS, SVC_TEMPENTITY, pev->origin );
		WRITE_BYTE( TE_EXPLODEMODEL );
		WRITE_COORD( pev->origin.x );
		WRITE_COORD( pev->origin.y );
		WRITE_COORD( pev->origin.z );
		WRITE_COORD( 400 );	// velocity
		WRITE_SHORT( m_iShardIndex );
		WRITE_SHORT( 10 );	// count
		WRITE_BYTE( 25 );	// life
	MESSAGE_END();

	// No damage if the owner left the game
	if ( real_owner->has_disconnected != TRUE )
		RadiusDamage( pev, real_owner->pev, 25, CLASS_NONE, DMG_BLAST | DMG_RADIUS_QUAKE );

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

bool CTFTeleporter::PlayerIsStandingOnTeleporter( CBaseEntity *pOther )
{
	return true;
}

void CTFTeleporter::TeleporterTouch( CBaseEntity *pOther )
{
	if ( !( pOther->pev->flags & FL_CLIENT ) )
		return;

	// Let the engineer know an enemy is on it
	if ( pOther->team_no && pOther->team_no != team_no )
	{
		if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
			ClientPrint( real_owner->pev, HUD_PRINTCENTER, "#Teleporter_entrance_enemy_use" );
		else
			ClientPrint( real_owner->pev, HUD_PRINTCENTER, "#Teleporter_exit_enemy_use" );
		return;
	}

	if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
	{
		if ( m_iState == TELEPORTER_STATE_READY )
		{
			if ( pOther->is_unableto_spy_or_teleport )
			{
				// Say which goal item is stopping them
				CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "item_tfgoal" );
				while ( pEnt )
				{
					if ( pEnt->pev->owner == pOther->edict() && ( pEnt->goal_result & TFGR_REMOVE_DISGUISE ) )
					{
						ClientPrint( pOther->pev, HUD_PRINTCENTER, "#Teleporter_carrying_goal", STRING( pEnt->pev->netname ) );
						return;
					}
					pEnt = UTIL_FindEntityByClassname( pEnt, "item_tfgoal" );
				}
			}
			else if ( pOther->pev->velocity.Length() == 0 )
			{
				// Standing still: send them if the exit is ready
				CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" );
				while ( pEnt )
				{
					CTFTeleporter *pExit = (CTFTeleporter *)pEnt;
					if ( pEnt->real_owner->pev == real_owner->pev && pExit->m_iType == BUILD_TELEPORTER_EXIT && pExit->m_iState == TELEPORTER_STATE_READY )
					{
						TeleporterSend( (CBasePlayer *)pOther );
						return;
					}
					pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" );
				}
			}
		}
		else if ( m_iState == TELEPORTER_STATE_IDLE )
		{
			ClientPrint( pOther->pev, HUD_PRINTCENTER, "#Teleporter_entrance_idle" );
		}
	}
	else if ( m_iState == TELEPORTER_STATE_IDLE )
	{
		ClientPrint( pOther->pev, HUD_PRINTCENTER, "#Teleporter_exit_idle" );
	}
}

void CTFTeleporter::TeleporterSend( CBasePlayer *pPlayer )
{
	if ( !pPlayer )
		return;

	m_pPlayer = pPlayer;
	m_iState = TELEPORTER_STATE_SENDING;
	m_flMyNextThink = gpGlobals->time + 0.1;
}

void CTFTeleporter::TeleporterReceive( CBasePlayer *pPlayer, float flDelay )
{
	if ( !pPlayer )
		return;

	m_flDamageDelay = flDelay;
	m_pPlayer = pPlayer;
	m_iState = TELEPORTER_STATE_RECEIVING;
	m_flMyNextThink = gpGlobals->time + flDelay * 0.25;
}

// This end died: whoever is mid-teleport through either end dies too
void CTFTeleporter::TeleporterKilled( void )
{
	CTFTeleporter *pMatch = FindMatch();
	char *pszMessage;

	if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
		pszMessage = "#Teleporter_Entrance_Gone_Player_Killed";
	else
		pszMessage = "#Teleporter_Exit_Gone_Player_Killed";

	if ( m_pPlayer )
	{
		m_pPlayer->tfstate &= ~TFSTATE_CANT_MOVE;
		m_pPlayer->TeamFortress_SetSpeed();
		m_pPlayer->m_iBeingTeleported = FALSE;

		MESSAGE_BEGIN( MSG_ONE, gmsgResetFade, NULL, m_pPlayer->pev );
		MESSAGE_END();

		MESSAGE_BEGIN( MSG_ALL, gmsgSpecFade );
			WRITE_BYTE( ENTINDEX( m_pPlayer->edict() ) );
			WRITE_BYTE( 1 );
			WRITE_BYTE( 0 );
			WRITE_SHORT( 1 );
			WRITE_BYTE( 0 );
		MESSAGE_END();

		TeleporterResetFade( m_pPlayer );
		ClientPrint( m_pPlayer->pev, HUD_PRINTCENTER, pszMessage );
		m_pPlayer->TakeDamage( pev, real_owner->pev, 500, DMG_ALWAYSGIB );

		if ( !pMatch )
			return;
	}
	else
	{
		if ( !pMatch )
			return;

		if ( pMatch->m_pPlayer )
		{
			pMatch->m_pPlayer->tfstate &= ~TFSTATE_CANT_MOVE;
			pMatch->m_pPlayer->TeamFortress_SetSpeed();
			pMatch->m_pPlayer->m_iBeingTeleported = FALSE;

			MESSAGE_BEGIN( MSG_ONE, gmsgResetFade, NULL, pMatch->m_pPlayer->pev );
			MESSAGE_END();

			MESSAGE_BEGIN( MSG_ALL, gmsgSpecFade );
				WRITE_BYTE( ENTINDEX( pMatch->m_pPlayer->edict() ) );
				WRITE_BYTE( 1 );
				WRITE_BYTE( 0 );
				WRITE_SHORT( 1 );
				WRITE_BYTE( 0 );
			MESSAGE_END();

			TeleporterResetFade( pMatch->m_pPlayer );
			ClientPrint( pMatch->m_pPlayer->pev, HUD_PRINTCENTER, pszMessage );
			pMatch->m_pPlayer->TakeDamage( pMatch->pev, pMatch->real_owner->pev, 500, DMG_ALWAYSGIB );
		}
	}

	pMatch->m_pPlayer = NULL;
	pMatch->m_iState = TELEPORTER_STATE_IDLE;
	pMatch->m_flMyNextThink = gpGlobals->time + 0.1;
	pMatch->SetTeleporterRings( TELEPORTER_STATE_IDLE );
	pMatch->SetTeleporterParticles( pMatch->m_iState );
}

// Rings spin while the teleporter is doing anything but idling
void CTFTeleporter::SetTeleporterRings( int state )
{
	int iFlag = ( m_iType == BUILD_TELEPORTER_ENTRANCE ) ? BUILDING_EVENT_ENTRANCE_RINGS : BUILDING_EVENT_EXIT_RINGS;

	if ( state >= TELEPORTER_STATE_READY && state <= TELEPORTER_STATE_RECHARGING )
	{
		if ( !( m_iBuildingEventState & iFlag ) )
		{
			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
				(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, iFlag, team_no, 1, 0 );
			m_iBuildingEventState |= iFlag;
		}
	}
	else if ( m_iBuildingEventState & iFlag )
	{
		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
			(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, iFlag, team_no, 0, 0 );
		m_iBuildingEventState &= ~iFlag;
	}
}

// Particles over a ready entrance
void CTFTeleporter::SetTeleporterParticles( int state )
{
	if ( state == TELEPORTER_STATE_READY )
	{
		if ( m_iType == BUILD_TELEPORTER_ENTRANCE && !( m_iBuildingEventState & BUILDING_EVENT_PARTICLES ) )
		{
			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
				(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_PARTICLES, team_no, 1, 0 );
			m_iBuildingEventState |= BUILDING_EVENT_PARTICLES;

			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
				(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_READY, team_no, 1, 0 );
		}
	}
	else if ( m_iBuildingEventState & BUILDING_EVENT_PARTICLES )
	{
		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
			(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_PARTICLES, team_no, 0, 0 );
		m_iBuildingEventState &= ~BUILDING_EVENT_PARTICLES;
	}
}

BOOL CTFTeleporter::TeleportersReady( void )
{
	CTFTeleporter *pMatch = FindMatch();
	if ( !pMatch )
		return FALSE;

	return pMatch->m_iState != 0;
}

// direction 0: fade the player out, 1: fade them in
void CTFTeleporter::TeleporterFadePlayer( int direction )
{
	if ( !m_pPlayer )
		return;

	m_pPlayer->pev->rendermode = kRenderTransAlpha;

	if ( direction == 0 )
	{
		m_pPlayer->pev->renderamt = 255;
		m_pPlayer->m_iFadeDirection = 0;
		m_pPlayer->m_flFadeAmount = 255 / ( ( m_flDamageDelay * 0.25 ) / 0.05 );
	}
	else
	{
		m_pPlayer->pev->renderamt = 0;
		m_pPlayer->m_iFadeDirection = 1;
		m_pPlayer->m_flFadeAmount = 255 / ( ( m_flDamageDelay * 0.25 ) / 0.05 );
	}
}

void CTFTeleporter::TeleporterProcessFade( void )
{
	if ( !m_pPlayer || m_pPlayer->pev->rendermode == kRenderNormal )
		return;

	if ( m_pPlayer->m_iFadeDirection == 1 )
	{
		if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
		{
			m_pPlayer->pev->renderamt += m_pPlayer->m_flFadeAmount;
			if ( m_pPlayer->pev->renderamt > 255 )
				m_pPlayer->pev->renderamt = 255;
		}
	}
	else if ( m_pPlayer->m_iFadeDirection == 0 && m_iType == BUILD_TELEPORTER_EXIT )
	{
		m_pPlayer->pev->renderamt -= m_pPlayer->m_flFadeAmount;
		if ( m_pPlayer->pev->renderamt < 0 )
			m_pPlayer->pev->renderamt = 0;
	}
}

void CTFTeleporter::TeleporterThink( void )
{
	CheckBelowBuilding( 8 );
	UpdateEntityEvents( this );
	DoDamageEffects( pev, pev->max_health * 0.66, pev->max_health * 0.33 );
	TeleporterProcessFade();

	pev->nextthink = gpGlobals->time + 0.05;

	if ( m_flMyNextThink && gpGlobals->time < m_flMyNextThink )
		return;

	switch ( m_iState )
	{
	case TELEPORTER_STATE_READY:
		if ( !TeleportersReady() )
			m_iState = TELEPORTER_STATE_IDLE;
		m_flMyNextThink = gpGlobals->time + 0.1;
		break;

	case TELEPORTER_STATE_SENDING:
	{
		m_pPlayer->tfstate |= TFSTATE_CANT_MOVE;
		m_pPlayer->TeamFortress_SetSpeed();
		m_pPlayer->m_iBeingTeleported = TRUE;

		CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" );
		while ( pEnt )
		{
			CTFTeleporter *pExit = (CTFTeleporter *)pEnt;
			if ( pEnt->real_owner->pev == real_owner->pev && pExit->m_iType == BUILD_TELEPORTER_EXIT && pExit->m_iState == TELEPORTER_STATE_READY )
			{
				m_flDamageDelay = 1.0;

				// Fade out in our team's colour
				TeleporterResetEffects( m_pPlayer );
				UTIL_ScreenFade( m_pPlayer->edict(), GetTeamColor(), m_flDamageDelay * 0.25, m_flDamageDelay * 0.25, 255, FFADE_OUT );
				TeleporterFadePlayer( 0 );

				MESSAGE_BEGIN( MSG_ALL, gmsgSpecFade );
					WRITE_BYTE( ENTINDEX( m_pPlayer->edict() ) );
					WRITE_BYTE( 0 );
					WRITE_BYTE( team_no );
					WRITE_SHORT( (int)( m_flDamageDelay * 0.25 * 100 ) );
					WRITE_BYTE( 255 );
				MESSAGE_END();

				PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
					(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_TELEPORT_OUT, team_no, 1, 0 );

				pExit->TeleporterReceive( m_pPlayer, m_flDamageDelay );

				m_iState = TELEPORTER_STATE_RECHARGING;
				m_flMyNextThink = gpGlobals->time + m_flDamageDelay * 10.5;
				break;
			}
			pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" );
		}

		if ( !pEnt )
		{
			// Exit went away: let them go
			m_flDamageDelay = 1.0;
			m_pPlayer->tfstate &= ~TFSTATE_CANT_MOVE;
			m_pPlayer->TeamFortress_SetSpeed();
			m_pPlayer->m_iBeingTeleported = FALSE;
			TeleporterResetFade( m_pPlayer );

			m_iState = TELEPORTER_STATE_RECHARGING;
			m_flMyNextThink = gpGlobals->time + m_flDamageDelay * 10;
			SetTeleporterRings( TELEPORTER_STATE_RECHARGING );
			SetTeleporterParticles( m_iState );
		}
		break;
	}

	case TELEPORTER_STATE_RECEIVING:
	{
		// Telefrag anyone standing on the exit, then move the player here
		Vector newPosition = pev->origin + Vector( 0, 0, 49 );

		CTelefragDeath *pDeath = GetClassPtr( (CTelefragDeath *)NULL );
		UTIL_SetOrigin( pDeath->pev, newPosition );
		pDeath->pev->owner = m_pPlayer->edict();
		pDeath->Spawn( this );

		UTIL_SetOrigin( m_pPlayer->pev, newPosition );

		UTIL_ScreenFade( m_pPlayer->edict(), GetTeamColor(), m_flDamageDelay * 0.25, 0, 255, FFADE_IN );
		TeleporterFadePlayer( 1 );

		MESSAGE_BEGIN( MSG_ALL, gmsgSpecFade );
			WRITE_BYTE( ENTINDEX( m_pPlayer->edict() ) );
			WRITE_BYTE( 1 );
			WRITE_BYTE( team_no );
			WRITE_SHORT( (int)( m_flDamageDelay * 0.25 * 100 ) );
			WRITE_BYTE( 255 );
		MESSAGE_END();

		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, edict(), m_usBuildingEvent, 0.0,
			(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_TELEPORT_IN, team_no, 1, 0 );

		m_iState = TELEPORTER_STATE_RECEIVING_RELEASE;
		m_flMyNextThink = gpGlobals->time + m_flDamageDelay * 0.25;
		break;
	}

	case TELEPORTER_STATE_RECEIVING_RELEASE:
	{
		m_pPlayer->tfstate &= ~TFSTATE_CANT_MOVE;
		m_pPlayer->TeamFortress_SetSpeed();
		m_pPlayer->m_iBeingTeleported = FALSE;
		TeleporterResetFade( m_pPlayer );

		m_iState = TELEPORTER_STATE_RECHARGING;
		m_flMyNextThink = gpGlobals->time + m_flDamageDelay * 10;

		// Team coloured glow for a while after arriving
		m_pPlayer->pev->renderfx = kRenderFxGlowShell;
		m_pPlayer->pev->rendercolor = GetTeamColor();
		m_pPlayer->pev->renderamt = 15;
		m_pPlayer->m_flTeleporterEffectEndTime = gpGlobals->time + 12;

		m_pPlayer = NULL;

		CTFTeleporter *pMatch = FindMatch();
		if ( pMatch )
			pMatch->m_pPlayer = NULL;
		break;
	}

	case TELEPORTER_STATE_RECHARGING:
		m_iState = TELEPORTER_STATE_READY;
		m_flMyNextThink = gpGlobals->time + 0.1;
		break;

	default:
		if ( TeleportersReady() )
			m_iState = TELEPORTER_STATE_READY;
		m_flMyNextThink = gpGlobals->time + 0.1;
		break;
	}

	SetTeleporterRings( m_iState );
	SetTeleporterParticles( m_iState );
}

// The engineer hit it with the spanner
BOOL CTFTeleporter::EngineerUse( CBasePlayer *pPlayer )
{
	char *type;
	int metalcost = ceil( ( pev->max_health - pev->health ) / 5 );

	if ( metalcost > pPlayer->ammo_cells )
		metalcost = pPlayer->ammo_cells;

	if ( metalcost <= 0 )
		return FALSE;

	if ( m_iType == BUILD_TELEPORTER_ENTRANCE )
		type = "#Teleporter_Entrance_Repaired";
	else
		type = "#Teleporter_Exit_Repaired";

	ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, type );

	pPlayer->ammo_cells -= metalcost;
	pev->health = min( pev->health + metalcost * 5, pev->max_health );

	if ( pPlayer->pev == real_owner->pev )
	{
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\"\n",
			STRING( pPlayer->pev->netname ),
			GETPLAYERUSERID( pPlayer->edict() ),
			GETPLAYERAUTHID( pPlayer->edict() ),
			pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
			type + 1 );
	}
	else
	{
		UTIL_LogPrintf( "\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",
			STRING( pPlayer->pev->netname ),
			GETPLAYERUSERID( pPlayer->edict() ),
			GETPLAYERAUTHID( pPlayer->edict() ),
			pPlayer->team_no ? GetTeamName( pPlayer->team_no ) : "SPECTATOR",
			type + 1,
			STRING( real_owner->pev->netname ),
			GETPLAYERUSERID( real_owner->edict() ),
			GETPLAYERAUTHID( real_owner->edict() ),
			real_owner->team_no ? GetTeamName( real_owner->team_no ) : "SPECTATOR" );
	}

	// Both ends fully repaired: cut the recharge short
	CTFTeleporter *pMatch = FindMatch();
	if ( pMatch && m_iState == TELEPORTER_STATE_RECHARGING && pMatch->m_iState == TELEPORTER_STATE_RECHARGING
		&& pev->health == pev->max_health && pMatch->pev->health == pMatch->pev->max_health
		&& m_flMyNextThink - gpGlobals->time > 10 )
	{
		m_flMyNextThink = gpGlobals->time + 10;
		pMatch->m_flMyNextThink = gpGlobals->time + 10;
	}

	return TRUE;
}

void CTFTeleporter::TeamFortress_TakeEMPBlast( entvars_t *pevGren )
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

float CTFTeleporter::GetDamageMultiplier( void )
{
	return 1.0;
}

const Vector &CTFTeleporter::GetTeamColor( void )
{
	switch ( team_no )
	{
	case 1:		return g_vBlue;
	case 2:		return g_vRed;
	case 3:		return g_vYellow;
	case 4:		return g_vGreen;
	default:	return g_vBlack;
	}
}

// The other end of this teleporter pair
CTFTeleporter *CTFTeleporter::FindMatch( void )
{
	int iMatch = ( m_iType == BUILD_TELEPORTER_ENTRANCE ) ? BUILD_TELEPORTER_EXIT : BUILD_TELEPORTER_ENTRANCE;

	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" );
	while ( pEnt )
	{
		if ( pEnt->real_owner->pev == real_owner->pev && ((CTFTeleporter *)pEnt)->m_iType == iMatch )
			return (CTFTeleporter *)pEnt;
		pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" );
	}

	return NULL;
}

// Player died or left mid-teleport
void PlayerStoppedTeleporting( CBasePlayer *pPlayer )
{
	if ( !pPlayer )
		return;

	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" );
	while ( pEnt )
	{
		CTFTeleporter *pTeleporter = (CTFTeleporter *)pEnt;
		if ( pTeleporter->m_pPlayer == pPlayer )
		{
			pTeleporter->m_iState = TELEPORTER_STATE_RECHARGING;
			pTeleporter->m_flMyNextThink = gpGlobals->time + pTeleporter->m_flDamageDelay * 10;
			pTeleporter->SetTeleporterRings( TELEPORTER_STATE_RECHARGING );
			pTeleporter->SetTeleporterParticles( pTeleporter->m_iState );
		}
		pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" );
	}

	pPlayer->m_iBeingTeleported = FALSE;
	pPlayer->tfstate &= ~TFSTATE_CANT_MOVE;

	MESSAGE_BEGIN( MSG_ONE, gmsgResetFade, NULL, pPlayer->pev );
	MESSAGE_END();

	MESSAGE_BEGIN( MSG_ALL, gmsgSpecFade );
		WRITE_BYTE( ENTINDEX( pPlayer->edict() ) );
		WRITE_BYTE( 1 );
		WRITE_BYTE( 0 );
		WRITE_SHORT( 1 );
		WRITE_BYTE( 0 );
	MESSAGE_END();

	TeleporterResetFade( pPlayer );
}

// Smoke below damageLevelOne health, sparks below damageLevelTwo
void DoDamageEffects( entvars_t *pev, float damageLevelOne, float damageLevelTwo )
{
	CBaseEntity *pEntity = CBaseEntity::Instance( pev );

	if ( pev->health < damageLevelOne )
	{
		if ( !( pEntity->m_iBuildingEventState & BUILDING_EVENT_DAMAGE1 ) )
		{
			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEntity->edict(), pEntity->m_usBuildingEvent, 0.0,
				(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DAMAGE1, pEntity->team_no, 1, 0 );
			pEntity->m_iBuildingEventState |= BUILDING_EVENT_DAMAGE1;
		}

		if ( pev->health < damageLevelTwo )
		{
			if ( !( pEntity->m_iBuildingEventState & BUILDING_EVENT_DAMAGE2 ) )
			{
				PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEntity->edict(), pEntity->m_usBuildingEvent, 0.0,
					(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DAMAGE2, pEntity->team_no, 1, 0 );
				pEntity->m_iBuildingEventState |= BUILDING_EVENT_DAMAGE2;
			}
			return;
		}
	}
	else if ( pEntity->m_iBuildingEventState & BUILDING_EVENT_DAMAGE1 )
	{
		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEntity->edict(), pEntity->m_usBuildingEvent, 0.0,
			(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DAMAGE1, 0, 0, 0 );
		pEntity->m_iBuildingEventState &= ~BUILDING_EVENT_DAMAGE1;
	}

	if ( pEntity->m_iBuildingEventState & BUILDING_EVENT_DAMAGE2 )
	{
		PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEntity->edict(), pEntity->m_usBuildingEvent, 0.0,
			(float *)&pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_DAMAGE2, 0, 0, 0 );
		pEntity->m_iBuildingEventState &= ~BUILDING_EVENT_DAMAGE2;
	}
}

// Tell clients when a building has moved (fallen, pushed)
void UpdateEntityEvents( CBaseEntity *pEntity )
{
	if ( !pEntity || pEntity->pev->origin == pEntity->m_vOldOrigin )
		return;

	PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_GLOBAL, pEntity->edict(), pEntity->m_usBuildingEvent, 0.0,
		(float *)&pEntity->pev->origin, (float *)&g_vecZero, 0.0, 0.0, BUILDING_EVENT_MOVED, 0, 0, 0 );
	pEntity->m_vOldOrigin = pEntity->pev->origin;
}

// Bring a newly connected player up to date on every building's effects
void SendBuildingEventInfo( CBasePlayer *pPlayer )
{
	CBaseEntity *pEntity;

	pEntity = UTIL_FindEntityByClassname( NULL, "building_dispenser" );
	while ( pEntity )
	{
		if ( pEntity->m_iBuildingEventState )
		{
			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_HOSTONLY, pPlayer->edict(), pEntity->m_usBuildingEvent, 0.0,
				(float *)&pEntity->pev->origin, (float *)&g_vecZero, ENTINDEX( pEntity->edict() ), 0.0,
				pEntity->m_iBuildingEventState | BUILDING_EVENT_INFO, pEntity->team_no, 1, 0 );
		}
		pEntity = UTIL_FindEntityByClassname( pEntity, "building_dispenser" );
	}

	pEntity = UTIL_FindEntityByClassname( NULL, "building_sentrygun" );
	while ( pEntity )
	{
		if ( pEntity->m_iBuildingEventState )
		{
			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_HOSTONLY, pPlayer->edict(), pEntity->m_usBuildingEvent, 0.0,
				(float *)&pEntity->pev->origin, (float *)&g_vecZero, ENTINDEX( pEntity->edict() ), 0.0,
				pEntity->m_iBuildingEventState | BUILDING_EVENT_INFO, pEntity->team_no, 1, 0 );
		}
		pEntity = UTIL_FindEntityByClassname( pEntity, "building_sentrygun" );
	}

	pEntity = UTIL_FindEntityByClassname( NULL, "building_teleporter" );
	while ( pEntity )
	{
		if ( pEntity->m_iBuildingEventState )
		{
			PLAYBACK_EVENT_FULL( FEV_RELIABLE | FEV_HOSTONLY, pPlayer->edict(), pEntity->m_usBuildingEvent, 0.0,
				(float *)&pEntity->pev->origin, (float *)&g_vecZero, ENTINDEX( pEntity->edict() ), 0.0,
				pEntity->m_iBuildingEventState | BUILDING_EVENT_INFO, pEntity->team_no, 1, 0 );
		}
		pEntity = UTIL_FindEntityByClassname( pEntity, "building_teleporter" );
	}
}

void TeleporterResetEffects( CBasePlayer *pPlayer )
{
	if ( !pPlayer )
		return;

	pPlayer->pev->rendermode = kRenderNormal;
	pPlayer->pev->renderamt = 0;
	pPlayer->m_iFadeDirection = 0;
	pPlayer->m_flFadeAmount = 0;
	pPlayer->pev->renderfx = kRenderFxNone;
	pPlayer->pev->rendercolor = g_vecZero;
	pPlayer->pev->renderamt = 0;
	pPlayer->m_flTeleporterEffectEndTime = 0;
}

void TeleporterResetFade( CBasePlayer *pPlayer )
{
	if ( !pPlayer )
		return;

	pPlayer->pev->rendermode = kRenderNormal;
	pPlayer->pev->renderamt = 0;
	pPlayer->m_flFadeAmount = 0;
	pPlayer->m_iFadeDirection = 0;
}

void TeleporterResetGlowshell( CBasePlayer *pPlayer )
{
	if ( !pPlayer )
		return;

	pPlayer->pev->renderfx = kRenderFxNone;
	pPlayer->pev->rendercolor = g_vecZero;
	pPlayer->pev->renderamt = 0;
	pPlayer->m_flTeleporterEffectEndTime = 0;
}
