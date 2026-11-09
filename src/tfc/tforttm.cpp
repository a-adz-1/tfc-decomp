/***
*
*	Team Fortress Classic: team management
*	(names, colours, scores, class restrictions, team equalisation)
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "tf_defs.h"

char *g_szTeamColors[5] = { "", "Blue", "Red", "Yellow", "Green" };
extern int gmsgTeamScore;

void TeamFortress_TeamShowScores( BOOL bLong, CBasePlayer *pPlayer )
{
	for ( int i = 1; i <= number_of_teams; i++ )
	{
		if ( !bLong )
		{
			UTIL_ClientPrintAll( HUD_PRINTNOTIFY, UTIL_VarArgs( "%s: %d\n", g_szTeamColors[i], teamscores[i] ) );
		}
		else
		{
			char *pszMsg = UTIL_VarArgs( "Team %d (%s): %d\n", i, g_szTeamColors[i], teamscores[i] );
			if ( pPlayer )
				ClientPrint( pPlayer->pev, HUD_PRINTNOTIFY, pszMsg );
			else
				UTIL_ClientPrintAll( HUD_PRINTNOTIFY, pszMsg );
		}
	}
}

// Player model colours for each team and class (tno is unused: sets all teams)
void TeamFortress_TeamSetColor( int tno )
{
	static const int iColors[5][ PC_LASTCLASS ][2] =
	{
		{ { 0 } },
		// Blue
		{ { 0, 0 }, { 153, 139 }, { 153, 145 }, { 153, 130 }, { 153, 145 }, { 153, 140 }, { 148, 138 },
		  { 140, 145 }, { 150, 145 }, { 140, 148 }, { 150, 0 }, { 150, 140 } },
		// Red
		{ { 0, 0 }, { 255, 10 }, { 255, 10 }, { 250, 28 }, { 255, 20 }, { 255, 250 }, { 255, 25 },
		  { 250, 25 }, { 250, 240 }, { 5, 250 }, { 250, 0 }, { 250, 240 } },
		// Yellow
		{ { 0, 0 }, { 45, 35 }, { 45, 35 }, { 45, 35 }, { 45, 35 }, { 45, 35 }, { 45, 40 },
		  { 45, 35 }, { 45, 35 }, { 45, 45 }, { 45, 0 }, { 45, 35 } },
		// Green
		{ { 0, 0 }, { 100, 90 }, { 80, 90 }, { 100, 40 }, { 100, 90 }, { 100, 90 }, { 100, 90 },
		  { 100, 50 }, { 100, 90 }, { 100, 90 }, { 100, 0 }, { 100, 90 } },
	};

	for ( int t = 1; t <= 4; t++ )
	{
		for ( int pc = PC_SCOUT; pc < PC_LASTCLASS; pc++ )
		{
			teamcolors[t][pc].topColor = iColors[t][pc][0];
			teamcolors[t][pc].bottomColor = iColors[t][pc][1];
		}
	}

	rgbcolors[0] = Vector( 255, 255, 255 );
	rgbcolors[1] = Vector( 0, 0, 255 );
	rgbcolors[2] = Vector( 255, 0, 0 );
	rgbcolors[3] = Vector( 255, 255, 30 );
	rgbcolors[4] = Vector( 0, 255, 0 );
}

// Map cvars for team names, short forms, then the default names
char *sTNameCvars[12] =
{
	"team1", "team2", "team3", "team4",
	"t1", "t2", "t3", "t4",
	"Blue", "Red", "Yellow", "Green",
};

char *GetTeamName( int tno )
{
	if ( tno <= 0 )
		return "";

	if ( team_names[tno] )
		return (char *)STRING( team_names[tno] );

	return sTNameCvars[ tno + 7 ];
}

void TeamFortress_TeamIncreaseScore( int tno, int scoretoadd )
{
	if ( tno == 0 )
		return;

	teamscores[tno] += scoretoadd;

	MESSAGE_BEGIN( MSG_ALL, gmsgTeamScore );
		WRITE_STRING( GetTeamName( tno ) );
		WRITE_SHORT( teamscores[tno] );
		WRITE_SHORT( 0 );
	MESSAGE_END();
}

int TeamFortress_TeamGetScoreFrags( int tno )
{
	return teamscores[tno];
}

int TeamFortress_TeamGetNoPlayers( int tno )
{
	int iCount = 0;

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
		if ( pPlayer && pPlayer->team_no == tno )
			iCount++;
	}

	return iCount;
}

int TeamFortress_GetNoPlayers( void )
{
	int iCount = 0;

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		if ( UTIL_PlayerByIndex( i ) )
			iCount++;
	}

	return iCount;
}

// Class limits per team: 0 = unlimited, -1 = not allowed, n = at most n
extern cvar_t cr_scout;
extern cvar_t cr_sniper;
extern cvar_t cr_soldier;
extern cvar_t cr_demoman;
extern cvar_t cr_medic;
extern cvar_t cr_hwguy;
extern cvar_t cr_pyro;
extern cvar_t cr_spy;
extern cvar_t cr_engineer;
extern cvar_t cr_random;

BOOL ClassIsRestricted( float tno, int pc )
{
	if ( tno == 0 )
		return FALSE;

	int iMax;
	switch ( pc )
	{
	case PC_SCOUT:		iMax = (int)cr_scout.value; break;
	case PC_SNIPER:		iMax = (int)cr_sniper.value; break;
	case PC_SOLDIER:	iMax = (int)cr_soldier.value; break;
	case PC_DEMOMAN:	iMax = (int)cr_demoman.value; break;
	case PC_MEDIC:		iMax = (int)cr_medic.value; break;
	case PC_HVYWEAP:	iMax = (int)cr_hwguy.value; break;
	case PC_PYRO:		iMax = (int)cr_pyro.value; break;
	case PC_SPY:		iMax = (int)cr_spy.value; break;
	case PC_ENGINEER:	iMax = (int)cr_engineer.value; break;
	case PC_RANDOM:		iMax = (int)cr_random.value; break;
	default:
		return FALSE;
	}

	if ( iMax < 1 )
		return iMax == -1;

	int iCount = 0;
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
		if ( !pPlayer || pPlayer->team_no != tno )
			continue;

		if ( pc == PC_RANDOM )
		{
			if ( pPlayer->tfstate & TFSTATE_RANDOMPC )
				iCount++;
		}
		else if ( ( pPlayer->pev->playerclass == pc || pPlayer->nextpc == pc ) && !( pPlayer->tfstate & TFSTATE_RANDOMPC ) )
		{
			iCount++;
		}
	}

	return iCount >= iMax;
}

BOOL TeamFortress_TeamIsCivilian( float tno )
{
	if ( tno == 1 )
		return ( civilianteams & TEAM1_CIVILIANS ) != 0;
	if ( tno == 2 )
		return ( civilianteams & TEAM2_CIVILIANS ) != 0;
	if ( tno == 3 )
		return ( civilianteams & TEAM3_CIVILIANS ) != 0;
	if ( tno == 4 )
		return ( civilianteams & TEAM4_CIVILIANS ) != 0;
	if ( tno == 0 )
		return illegalclasses[0] == -1;

	return FALSE;
}

// How far a team's advantage moves towards balance (1/3 of the difference)
static inline float Equalise( float flRatio )
{
	float flDiff = flRatio - 1;
	if ( flDiff )
		flDiff = flDiff / 3;
	return flDiff + 1;
}

// Only used on two team maps
void CalculateTeamEqualiser( void )
{
	for ( int i = 1; i <= 4; i++ )
		teamadvantage[i] = 1;

	if ( number_of_teams != 2 )
	{
		for ( int i = 1; i <= 4; i++ )
			teamadvantage[i] = 1;
		return;
	}

	// Fewer players: more damage
	if ( tfc_balance_teams.value )
	{
		float flPlayers[5];
		for ( int i = 1; i <= 4; i++ )
			flPlayers[i] = TeamFortress_TeamGetNoPlayers( i );

		float flTotal = flPlayers[1] + flPlayers[2] + flPlayers[3] + flPlayers[4];
		if ( flTotal < 1 )
			return;

		float flAverage = flTotal / number_of_teams;

		if ( flPlayers[1] > 0 )
			teamadvantage[1] = Equalise( flAverage / flPlayers[1] );
		if ( flPlayers[2] > 0 && number_of_teams >= 2 )
			teamadvantage[2] = Equalise( flAverage / flPlayers[2] );
		if ( flPlayers[3] > 0 && number_of_teams >= 3 )
			teamadvantage[3] = Equalise( flAverage / flPlayers[3] );
		if ( flPlayers[4] > 0 && number_of_teams >= 4 )
			teamadvantage[4] = Equalise( flAverage / flPlayers[4] );
	}

	// Lower score: more damage
	if ( tfc_balance_scores.value )
	{
		float flScore1 = teamscores[1] + 60;
		float flScore2 = number_of_teams >= 2 ? teamscores[2] + 60 : 0;
		float flScore3 = number_of_teams >= 3 ? teamscores[3] + 60 : 0;
		float flScore4 = number_of_teams >= 4 ? teamscores[4] + 60 : 0;
		float flOthers = number_of_teams - 1;

		float flAdv1 = Equalise( ( ( flScore2 + flScore3 + flScore4 ) / flOthers ) / flScore1 );

		if ( number_of_teams >= 2 )
			teamadvantage[2] *= Equalise( ( ( flScore1 + flScore3 + flScore4 ) / flOthers ) / flScore2 );

		teamadvantage[1] *= flAdv1;

		if ( number_of_teams >= 3 )
			teamadvantage[3] *= Equalise( ( ( flScore2 + flScore1 + flScore4 ) / flOthers ) / flScore3 );
		if ( number_of_teams >= 4 )
			teamadvantage[4] *= Equalise( ( ( flScore1 + flScore2 + flScore3 ) / flOthers ) / flScore4 );
	}
}

// Running totals of damage added/removed by equalisation (debugging)
extern float gfPrototypeExtraDamage;
extern float gfPrototypeLessDamage;

float TeamEqualiseDamage( CBaseEntity *targ, CBaseEntity *attacker, float damage )
{
	if ( !FClassnameIs( targ->pev, "player" ) || !FClassnameIs( attacker->pev, "player" ) )
		return damage;

	if ( !targ->team_no || !attacker->team_no || attacker->IsAlly( targ ) )
		return damage;

	float flAttackerAdv = teamadvantage[ attacker->team_no ];
	if ( flAttackerAdv == 0 )
	{
		ALERT( at_console, "There is a team with an advantage of 0\n" );
		flAttackerAdv = 0.1;
	}

	float flTargetAdv;
	if ( teamadvantage[ targ->team_no ] == 0 )
	{
		ALERT( at_console, "There is a team with an advantage of 0\n" );
		flTargetAdv = 10;
	}
	else
	{
		flTargetAdv = 1 / teamadvantage[ targ->team_no ];
	}

	float flNewDamage = flTargetAdv * flAttackerAdv * damage;

	if ( flNewDamage < damage )
		gfPrototypeLessDamage += damage - flNewDamage;
	else
		gfPrototypeExtraDamage += flNewDamage - damage;

	return flNewDamage;
}

void TeamFortress_StatusQuery( void )
{
	ALERT( at_console, "players per team: %d %d %d %d\n",
		TeamFortress_TeamGetNoPlayers( 1 ), TeamFortress_TeamGetNoPlayers( 2 ),
		TeamFortress_TeamGetNoPlayers( 3 ), TeamFortress_TeamGetNoPlayers( 4 ) );
	ALERT( at_console, "    equalisation: %0.1f %0.1f %0.1f %0.1f\n",
		teamadvantage[1], teamadvantage[2], teamadvantage[3], teamadvantage[4] );
	ALERT( at_console, "Teamplay is %d\n", gpGlobals->teamplay );	// sic: float printed with %d
}

// Orders teams by score into g_iOrderedTeams[1..number_of_teams].
// Returns TRUE if the result is a draw.
BOOL TeamFortress_SortTeams( void )
{
	int iUsed[5] = { 0 };
	BOOL bDraw = TRUE;

	for ( int i = 0; i <= 4; i++ )
		g_iOrderedTeams[i] = 0;

	int iPrevTeam = 0;
	int iPrevScore = 0;

	for ( int i = 1; i <= number_of_teams; i++ )
	{
		int iHighest = 0;
		int iTeam = iPrevTeam;

		for ( int t = 1; t <= number_of_teams; t++ )
		{
			if ( teamscores[t] >= iHighest && !iUsed[t] )
			{
				iHighest = teamscores[t];
				iTeam = t;
			}
		}

		// Still a draw only if this team scored the same as the one above it
		// (or is allied to it). Note: the original indexes teamallies by
		// position i, not by team.
		if ( bDraw && i > 1 )
		{
			bDraw = TRUE;
			if ( !( teamallies[i] & ( 1 << ( iPrevTeam - 1 ) ) ) )
				bDraw = ( iHighest == iPrevScore );
		}

		g_iOrderedTeams[i] = iTeam;
		iUsed[iTeam] = TRUE;
		iPrevTeam = iTeam;
		iPrevScore = iHighest;
	}

	return bDraw;
}
