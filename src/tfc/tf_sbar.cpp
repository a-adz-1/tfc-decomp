/***
*
*	Team Fortress Classic: HUD status bar (player ID, building status,
*	spy disguise, prematch/respawn timers)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided. The original
*	function is heavily inlined; text buffers were mapped from the
*	machine code. VERIFY IN GAME: how the engineer's sentry and
*	teleporter texts are combined on line 0.
*
*	Status text lines sent to the client:
*	  0: own class status (engineer buildings, building, detpacking)
*	  1: spy disguise / clan battle id
*	  2: ID target, or the prematch / respawn timer
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"
#include "tf_defs.h"

extern int gmsgStatusText;
extern int gmsgStatusValue;
extern cvar_t tfc_playerid;	// 1 = hide enemy names, 2 = hide all names

#define MAX_TF_ID_RANGE		2048
#define TF_ID_ENEMY_RANGE	1024	// enemies are only identified this close

void CBasePlayer::TeamFortress_InitStatusBar( void )
{
	m_flStatusBarDisappearDelay = 0;
	m_SbarString2[0] = 0;
	m_SbarString1[0] = 0;
	m_SbarString0[0] = 0;
}

// This engineer's teleporter of the given type (BUILD_TELEPORTER_ENTRANCE/EXIT)
CBaseEntity *CBasePlayer::GetTeleporter( int type )
{
	CBaseEntity *pEnt = UTIL_FindEntityByClassname( NULL, "building_teleporter" );
	while ( pEnt )
	{
		if ( pEnt->real_owner->pev == pev && ((CTFTeleporter *)pEnt)->m_iType == type )
			break;
		pEnt = UTIL_FindEntityByClassname( pEnt, "building_teleporter" );
	}
	return pEnt;
}

static int HealthPercent( CBaseEntity *pEnt )
{
	int iPercent = (int)( ( pEnt->pev->health / pEnt->pev->max_health ) * 100 );
	if ( iPercent < 0 )
		return 0;
	if ( iPercent > 100 )
		return 100;
	return iPercent;
}

void CBasePlayer::TeamFortress_UpdateStatusBar( void )
{
	int newSBarState[ SBAR_END ];
	char sbuf0[ SBAR_STRING_SIZE ];
	char sbuf1[ SBAR_STRING_SIZE ];
	char sbuf2[ SBAR_STRING_SIZE ];
	char szTemp[ 32 ];

	memset( newSBarState, 0, sizeof( newSBarState ) );
	sbuf0[0] = 0;
	sbuf1[0] = 0;
	strcpy( sbuf2, m_SbarString2 );

	float flTimer = 0;
	BOOL bShowTimer = FALSE;

	if ( gpGlobals->time < cb_prematch_time )
	{
		strcpy( sbuf2, "#Sbar_prematch" );

		if ( tfc_clanbattle.value )
		{
			strcpy( sbuf1, "#Sbar_battleid" );
			newSBarState[ SBAR_TEAM1SCORE ] = tf_id;
		}

		newSBarState[ SBAR_TEAM2SCORE ] = cease_fire;
		flTimer = cb_prematch_time;
		bShowTimer = TRUE;
	}
	else if ( gpGlobals->time < respawn_time )
	{
		strcpy( sbuf2, "#Sbar_dead" );
		flTimer = respawn_time;
		bShowTimer = TRUE;
	}
	else
	{
		// Find an ID target
		TraceResult tr;
		UTIL_MakeVectors( pev->v_angle + pev->punchangle );
		Vector vecSrc = EyePosition();
		Vector vecEnd = vecSrc + gpGlobals->v_forward * MAX_TF_ID_RANGE;
		UTIL_TraceLine( vecSrc, vecEnd, dont_ignore_monsters, edict(), &tr );

		if ( tr.flFraction != 1.0 )
		{
			if ( !FNullEnt( tr.pHit ) )
			{
				CBaseEntity *pEntity = CBaseEntity::Instance( tr.pHit );
				BOOL bID = FALSE;

				if ( pEntity->Classify() == CLASS_PLAYER )
				{
					// Feigning enemy spies look dead
					if ( !( pEntity->is_feigning && !IsAlly( pEntity ) && !pev->iuser1 ) )
					{
						BOOL bInRange = IsAlly( pEntity ) || ( vecSrc - tr.vecEndPos ).Length() <= TF_ID_ENEMY_RANGE;

						if ( bInRange || pev->iuser1 )
						{
							bID = TRUE;

							// Disguised enemy spies show the player they're disguised as
							if ( bInRange && !pev->iuser1 && team_no && pEntity->undercover_target &&
								team_no != pEntity->team_no && pEntity->pev->playerclass == PC_SPY )
							{
								pEntity = pEntity->undercover_target;
							}

							if ( tfc_playerid.value == 2 || ( tfc_playerid.value == 1 && !IsAlly( pEntity ) && !pev->iuser1 ) )
								strcpy( sbuf2, " " );
							else
								strcpy( sbuf2, "1 %p1\n2    Health: %i2%%\n3  Armor: %i3%%" );

							newSBarState[ SBAR_ID_TARGETNAME ] = ENTINDEX( pEntity->edict() );
							m_hLastIDTarget = pEntity;
						}
					}
				}
				else
				{
					const char *pszText = NULL;

					if ( FClassnameIs( pEntity->pev, "building_sentrygun" ) )
						pszText = "1 Sentry gun built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
					else if ( FClassnameIs( pEntity->pev, "building_dispenser" ) )
						pszText = "1 Dispenser built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
					else if ( FClassnameIs( pEntity->pev, "building_teleporter" ) )
					{
						if ( ((CTFTeleporter *)pEntity)->m_iType == BUILD_TELEPORTER_ENTRANCE )
							pszText = "1 Teleporter entrance built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
						else
							pszText = "1 Teleporter exit built by: %p1\n2    Health: %i2%%\n3  Armor: %i3%%";
					}

					if ( pszText )
					{
						bID = TRUE;
						newSBarState[ SBAR_ID_TARGETNAME ] = ENTINDEX( pEntity->real_owner->edict() );

						if ( tfc_playerid.value == 2 || ( tfc_playerid.value == 1 && !pev->iuser1 && !IsAlly( pEntity ) ) )
							strcpy( sbuf2, " " );
						else
							strcpy( sbuf2, pszText );
					}
				}

				if ( bID )
				{
					// Allies, medics and spectators see health and armour
					if ( IsAlly( pEntity ) || pev->playerclass == PC_MEDIC || pev->iuser1 )
					{
						newSBarState[ SBAR_ID_TARGETHEALTH ] = (int)( ( pEntity->pev->health / pEntity->pev->max_health ) * 100 );
						newSBarState[ SBAR_ID_TARGETARMOR ] = (int)( ( pEntity->pev->armorvalue / pEntity->maxarmor ) * 100 );
					}

					m_flStatusBarDisappearDelay = gpGlobals->time + 1.0;

					if ( newSBarState[ SBAR_ID_TARGETNAME ] < 0 )
					{
						printf( "ERROR: SBAR_ID_TARGETNAME = %d\n", newSBarState[ SBAR_ID_TARGETNAME ] );
						newSBarState[ SBAR_ID_TARGETNAME ] = 0;
					}
				}
			}
			else if ( m_flStatusBarDisappearDelay > gpGlobals->time )
			{
				// hold the values for a short amount of time after viewing the object
				newSBarState[ SBAR_ID_TARGETNAME ] = m_izSBarState[ SBAR_ID_TARGETNAME ];
				newSBarState[ SBAR_ID_TARGETHEALTH ] = m_izSBarState[ SBAR_ID_TARGETHEALTH ];
				newSBarState[ SBAR_ID_TARGETARMOR ] = m_izSBarState[ SBAR_ID_TARGETARMOR ];
			}
		}

		// Spy: current disguise
		if ( pev->playerclass == PC_SPY )
		{
			if ( is_undercover && !undercover_team && !undercover_skin )
			{
				strcpy( sbuf1, "#Spy_disguising" );
			}
			else if ( undercover_team || undercover_skin )
			{
				strcpy( sbuf1, "#Spy_disguised" );
				if ( undercover_team )
				{
					strcat( sbuf1, " " );
					strcat( sbuf1, GetTeamName( undercover_team ) );
				}
				strcat( sbuf1, " #" );
				strcat( sbuf1, sClassNames[ undercover_skin ? undercover_skin : PC_SPY ] );
			}
		}

		// Engineer: own buildings
		if ( pev->playerclass == PC_ENGINEER )
		{
			if ( has_sentry )
			{
				for ( CBaseEntity *pSentry = UTIL_FindEntityByClassname( NULL, "building_sentrygun" ); pSentry; pSentry = UTIL_FindEntityByClassname( pSentry, "building_sentrygun" ) )
				{
					if ( (CBaseEntity *)pSentry->real_owner != this )
						continue;

					sprintf( sbuf1, "#Sentry_sbar %d", HealthPercent( pSentry ) );
					strcat( sbuf1, "%%\n4 ammo: %i4%%\n0" );

					if ( pSentry->ammo_shells == 0 )
					{
						strcat( sbuf1, " " );
						if ( pSentry->ammo_rockets == 0 && pSentry->weapon == 3 )
							strcat( sbuf1, "#No_Ammo" );
						else
							strcat( sbuf1, "#No_Shells" );
					}
					else
					{
						newSBarState[ SBAR_ENG_BUILDINGAMMO ] = (int)( ( (float)pSentry->ammo_shells / (float)pSentry->maxammo_shells ) * 100 );
						if ( pSentry->ammo_rockets == 0 && pSentry->weapon == 3 )
						{
							strcat( sbuf1, " " );
							strcat( sbuf1, "#No_Rockets" );
						}
					}
				}
			}

			if ( has_entry_teleporter || has_exit_teleporter )
			{
				CBaseEntity *pEntry = GetTeleporter( BUILD_TELEPORTER_ENTRANCE );
				CBaseEntity *pExit = GetTeleporter( BUILD_TELEPORTER_EXIT );
				char szTele[ SBAR_STRING_SIZE ];
				szTele[0] = 0;

				if ( pEntry )
				{
					strcat( szTele, "#Teleporter_entry_sbar " );
					sprintf( szTemp, "%d", HealthPercent( pEntry ) );
					strncat( szTele, szTemp, SBAR_STRING_SIZE - 1 );
					strcat( szTele, "%%\n0" );
				}

				if ( pExit )
				{
					if ( szTele[0] )
						strcat( szTele, "   " );
					strcat( szTele, "#Teleporter_exit_sbar " );
					sprintf( szTemp, "%d", HealthPercent( pExit ) );
					strncat( szTele, szTemp, SBAR_STRING_SIZE - 1 );
					strcat( szTele, "%%\n0" );
				}

				// line 1 holds the sentry; teleporters go above it if it's taken
				if ( szTele[0] )
				{
					if ( sbuf1[0] )
						strcpy( sbuf0, szTele );
					else
						strcpy( sbuf1, szTele );
				}
			}

			if ( is_building )
			{
				if ( sbuf1[0] )
					strcpy( sbuf0, "#Engineer_building" );
				else
					strcpy( sbuf1, "#Engineer_building" );
			}
		}

		if ( pev->playerclass == PC_DEMOMAN && is_detpacking )
			strcpy( sbuf1, "#Demoman_detpacking" );
	}

	if ( bShowTimer )
	{
		// %i1 seconds, %i2 minutes; slots 3/4 flag "1 second"/"1 minute"
		int iTime = (int)ceil( flTimer - gpGlobals->time );

		int iSecs = iTime % 60;
		if ( iSecs == 1 )
			newSBarState[ SBAR_ID_TARGETARMOR ] = 1;
		else
			newSBarState[ SBAR_ID_TARGETNAME ] = iSecs;

		int iMins = (int)( ceil( flTimer - gpGlobals->time ) / 60.0 );
		if ( iMins == 1 )
			newSBarState[ SBAR_ENG_BUILDINGAMMO ] = 1;
		else
			newSBarState[ SBAR_ID_TARGETHEALTH ] = iMins;
	}

	// Respawn time has passed: clear the dead message
	if ( respawn_time && respawn_time < gpGlobals->time && !strcmp( sbuf2, "#Sbar_dead" ) )
		sbuf2[0] = 0;

	BOOL bForceResend = FALSE;

	if ( strcmp( sbuf0, m_SbarString0 ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusText, NULL, pev );
			WRITE_BYTE( 0 );
			WRITE_STRING( sbuf0 );
		MESSAGE_END();

		strcpy( m_SbarString0, sbuf0 );
		bForceResend = TRUE;
	}

	if ( strcmp( sbuf1, m_SbarString1 ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusText, NULL, pev );
			WRITE_BYTE( 1 );
			WRITE_STRING( sbuf1 );
		MESSAGE_END();

		strcpy( m_SbarString1, sbuf1 );
		bForceResend = TRUE;
	}

	if ( strcmp( sbuf2, m_SbarString2 ) )
	{
		MESSAGE_BEGIN( MSG_ONE, gmsgStatusText, NULL, pev );
			WRITE_BYTE( 2 );
			WRITE_STRING( sbuf2 );
		MESSAGE_END();

		strcpy( m_SbarString2, sbuf2 );
		bForceResend = TRUE;
	}

	// Check values and send if they don't match
	for ( int i = 1; i < SBAR_END; i++ )
	{
		if ( newSBarState[i] != m_izSBarState[i] || bForceResend )
		{
			MESSAGE_BEGIN( MSG_ONE, gmsgStatusValue, NULL, pev );
				WRITE_BYTE( i );
				WRITE_SHORT( newSBarState[i] );
			MESSAGE_END();

			m_izSBarState[i] = newSBarState[i];
		}
	}
}
