/***
*
*	Team Fortress Classic: gameplay datamining (mp_datamine) via gamedb.so
*
*	Collects per-level, per-class and per-area statistics into Valve's game
*	database module and, on dedicated servers, sends them with sendgameinfo.
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "tf_defs.h"
#include "areadef.h"
#include "dbhelpers.h"

#include <errno.h>
#include <unistd.h>

#ifndef SERVER_PRINT
#define SERVER_PRINT	(*g_engfuncs.pfnServerPrint)
#endif

int g_nActiveAreas;
bool g_bDBSent;
bool g_bFirstSend = true;

// Class popularity, sampled every few seconds
int g_ClassPlayerCounts[ PC_LASTCLASS ];
int g_nClassPlayerSamples;
float g_fLastPlayerCountSampleTime;

int g_nTotalClients;
int g_nClientSamples;

float g_fLevelStartTime;

IGameDB *g_pDB;
CSysModule *g_hGameDBDLL;

HTABLE g_hLevel;
HCOLUMN g_hLevel_LevelName;
HCOLUMN g_hLevel_GameLength;
HCOLUMN g_hLevel_WinningTeam;
HCOLUMN g_hLevel_NumClients;

HTABLE g_hLevelClass;
HCOLUMN g_hLevelClass_Parent;
HCOLUMN g_hLevelClass_ClassName;
HCOLUMN g_hLevelClass_ClassPercent;

HTABLE g_hLevelArea;
HCOLUMN g_hLevelArea_AreaName;
HCOLUMN g_hLevelArea_Parent;

HTABLE g_hLevelAreaClass;
HCOLUMN g_hLevelAreaClass_Parent;
HCOLUMN g_hLevelAreaClass_ClassName;
HCOLUMN g_hLevelAreaClass_DeathCount;
HCOLUMN g_hLevelAreaClass_PingTime;
HCOLUMN g_hLevelAreaClass_TimeInArea;

HTABLE g_hLevelAreaClassWeapon;
HCOLUMN g_hLevelAreaClassWeapon_Parent;
HCOLUMN g_hLevelAreaClassWeapon_WeaponName;
HCOLUMN g_hLevelAreaClassWeapon_NumShotsFired;

HTABLE g_hLevelAreaClassWeaponDamage;
HCOLUMN g_hLevelAreaClassWeaponDamage_Parent;
HCOLUMN g_hLevelAreaClassWeaponDamage_DamagedClassName;
HCOLUMN g_hLevelAreaClassWeaponDamage_DamageInflicted;
HCOLUMN g_hLevelAreaClassWeaponDamage_Kills;

cvar_t mp_datamine = { "mp_datamine", "1.0", FCVAR_ARCHIVE };

#define MAX_UNIQUE_AREAS	256

static inline CAreaDef *DB_FindAreaDef( CAreaDef **pAreas, int nAreas, const char *pName )
{
	for ( int i = 0; i < nAreas; i++ )
	{
		if ( !stricmp( pAreas[i]->m_AreaName, pName ) )
			return pAreas[i];
	}
	return NULL;
}

// Several info_areadefs may share a name: fold them into one entry each
static inline void DB_MergeAreas( CAreaDef *pList, CAreaDef **pUniqueAreas, int nMaxAreas, int &nUniqueAreas )
{
	for ( CAreaDef *pArea = pList; pArea; pArea = pArea->m_pNext )
	{
		CAreaDef *pExisting = DB_FindAreaDef( pUniqueAreas, nUniqueAreas, pArea->m_AreaName );
		if ( pExisting )
			pExisting->MergeData( pArea );
		else if ( nUniqueAreas < nMaxAreas )
			pUniqueAreas[ nUniqueAreas++ ] = pArea;
	}
}

static void InitDBFormat( void )
{
	if ( !g_pDB )
		return;

	g_hLevel = g_pDB->AddTable_VA( "Level", 4,
		"LevelName", COLUMN_STRING, &g_hLevel_LevelName,
		"GameLength", COLUMN_INT, &g_hLevel_GameLength,
		"WinningTeam", COLUMN_INT, &g_hLevel_WinningTeam,
		"NumClients", COLUMN_INT, &g_hLevel_NumClients );

	g_hLevelClass = g_pDB->AddTable_VA( "LevelClass", 3,
		"ClassName", COLUMN_STRING, &g_hLevelClass_ClassName,
		"ClassPercent", COLUMN_INT, &g_hLevelClass_ClassPercent,
		"Parent", COLUMN_PARENT, &g_hLevelClass_Parent );

	g_hLevelArea = g_pDB->AddTable_VA( "LevelArea", 2,
		"AreaName", COLUMN_STRING, &g_hLevelArea_AreaName,
		"Parent", COLUMN_PARENT, &g_hLevelArea_Parent );

	g_hLevelAreaClass = g_pDB->AddTable_VA( "LevelAreaClass", 5,
		"ClassName", COLUMN_STRING, &g_hLevelAreaClass_ClassName,
		"Parent", COLUMN_PARENT, &g_hLevelAreaClass_Parent,
		"DeathCount", COLUMN_INT, &g_hLevelAreaClass_DeathCount,
		"PingTime", COLUMN_INT, &g_hLevelAreaClass_PingTime,
		"TimeInArea", COLUMN_INT, &g_hLevelAreaClass_TimeInArea );

	g_hLevelAreaClassWeapon = g_pDB->AddTable_VA( "LevelAreaClassWeapon", 3,
		"WeaponName", COLUMN_STRING, &g_hLevelAreaClassWeapon_WeaponName,
		"Parent", COLUMN_PARENT, &g_hLevelAreaClassWeapon_Parent,
		"NumShotsFired", COLUMN_INT, &g_hLevelAreaClassWeapon_NumShotsFired );

	g_hLevelAreaClassWeaponDamage = g_pDB->AddTable_VA( "LevelAreaClassWeaponDamage", 4,
		"DamagedClassName", COLUMN_STRING, &g_hLevelAreaClassWeaponDamage_DamagedClassName,
		"Parent", COLUMN_PARENT, &g_hLevelAreaClassWeaponDamage_Parent,
		"DamageInflicted", COLUMN_INT, &g_hLevelAreaClassWeaponDamage_DamageInflicted,
		"Kills", COLUMN_INT, &g_hLevelAreaClassWeaponDamage_Kills );
}

void DB_GameDBShutdown( void )
{
	if ( !g_hGameDBDLL )
		return;

	if ( g_pDB )
	{
		g_pDB->Release();
		g_pDB = NULL;
	}

	Sys_UnloadModule( g_hGameDBDLL );
	g_hGameDBDLL = NULL;
}

void DB_GameDBLoad( void )
{
	DB_GameDBShutdown();

	g_hGameDBDLL = Sys_LoadModule( "gamedb.so" );
	if ( g_hGameDBDLL )
	{
		CreateInterfaceFn factory = Sys_GetFactory( g_hGameDBDLL );
		if ( factory && ( g_pDB = (IGameDB *)factory( "GameDB", NULL ) ) )
		{
			DB_Clear();
		}
		else
		{
			Sys_UnloadModule( g_hGameDBDLL );
			g_hGameDBDLL = NULL;
		}
	}

	CVAR_REGISTER( &mp_datamine );
}

void DB_OnStartLevel( void )
{
	g_bDBSent = false;
	DB_Clear();

	g_fLevelStartTime = g_fLastPlayerCountSampleTime = g_engfuncs.pfnTime();

	for ( int i = 0; i < PC_LASTCLASS; i++ )
		g_ClassPlayerCounts[i] = 0;

	g_nClassPlayerSamples = 0;
	g_nTotalClients = 0;
	g_nClientSamples = 0;
}

void DB_OnStartFrame( void )
{
	float flTime = g_engfuncs.pfnTime();

	if ( flTime - g_fLastPlayerCountSampleTime < 3.0 )
		return;

	g_fLastPlayerCountSampleTime = flTime;

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		if ( UTIL_PlayerByIndex( i ) )
			g_nTotalClients++;
	}
	g_nClientSamples++;

	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CBaseEntity *pPlayer = UTIL_PlayerByIndex( i );
		if ( pPlayer && pPlayer->pev && pPlayer->pev->playerclass >= 0 && pPlayer->pev->playerclass < PC_LASTCLASS )
		{
			g_ClassPlayerCounts[ pPlayer->pev->playerclass ]++;
			g_nClassPlayerSamples++;
		}
	}
}

bool DB_AddFinalData( void )
{
	if ( !g_nClassPlayerSamples )
		return false;

	int nTeams = (int)number_of_teams;
	if ( nTeams < 1 || !g_nClientSamples )
		return false;
	if ( nTeams > 5 )
		return false;

	const char *pLevelName = DB_GetLevelName();

	for ( int i = 0; i < PC_LASTCLASS; i++ )
	{
		DB_SetFieldValueInt( DB_GetField( DB_GetRow_LevelClass( pLevelName, sClassNames[i] ), g_hLevelClass_ClassPercent ),
			( g_ClassPlayerCounts[i] * 100 ) / g_nClassPlayerSamples );
	}

	DB_SetFieldValueInt( DB_GetField( DB_GetRow_Level( pLevelName ), g_hLevel_NumClients ),
		(int)( (float)g_nTotalClients / g_nClientSamples + 0.5 ) );

	DB_SetFieldValueInt( DB_GetField( DB_GetRow_Level( DB_GetLevelName() ), g_hLevel_GameLength ),
		(int)( (int)g_engfuncs.pfnTime() - g_fLevelStartTime ) );

	if ( !TeamFortress_SortTeams() )
	{
		DB_SetFieldValueInt( DB_GetField( DB_GetRow_Level( DB_GetLevelName() ), g_hLevel_WinningTeam ),
			g_iOrderedTeams[ nTeams - 1 ] );
	}

	// Per area, per class ping and time
	CAreaDef *pUniqueAreas[ MAX_UNIQUE_AREAS ];
	int nUniqueAreas = 0;
	DB_MergeAreas( g_pActiveAreas, pUniqueAreas, MAX_UNIQUE_AREAS, nUniqueAreas );

	for ( int iArea = 0; iArea < nUniqueAreas; iArea++ )
	{
		CAreaDef *pArea = pUniqueAreas[ iArea ];

		for ( int i = 0; i < PC_LASTCLASS; i++ )
		{
			DBAreaClassData *pData = &pArea->m_ClassData[i];

			if ( pData->m_DB_nPingTests > 0 )
			{
				int iPing = pData->m_DB_PingTotal / pData->m_DB_nPingTests;
				DB_SetFieldValueInt( DB_GetField( DB_GetRow_LevelAreaClass( DB_GetLevelName(), pArea->m_AreaName, sClassNames[i] ), g_hLevelAreaClass_PingTime ), iPing );
			}

			if ( pData->m_DB_TimeInArea > 0 )
			{
				DB_SetFieldValueInt( DB_GetField( DB_GetRow_LevelAreaClass( DB_GetLevelName(), pArea->m_AreaName, sClassNames[i] ), g_hLevelAreaClass_TimeInArea ), pData->m_DB_TimeInArea );
			}
		}
	}

	return true;
}

bool DB_Transmit( bool bClear )
{
	char szFilename[ 256 ];
	char szIP[ 256 ];
	char szMsg[ 256 ];
	bool bRet = false;

	g_bDBSent = true;
	g_bFirstSend = false;

	if ( !g_pDB )
		return false;

	if ( !DB_AddFinalData() )
	{
		SERVER_PRINT( "DB_AddFinalData returned false. Not sending GameDB.\n" );
		return false;
	}

	bRet = true;

	if ( mp_datamine.value )
	{
		// Listen servers only send with mp_datamine 2
		if ( IS_DEDICATED_SERVER() || mp_datamine.value == 2 )
		{
			FILE *fp = fopen( "vmine.ip", "rt" );
			if ( !fp )
			{
				strcpy( szMsg, "DB_StartSending: can't open vmine.ip.\n" );
				bRet = false;
				SERVER_PRINT( szMsg );
			}
			else
			{
				szIP[0] = 0;
				fscanf( fp, "%s", szIP );
				bRet = false;
				fclose( fp );

				if ( szIP[0] && GetUniqueFilename( "gameplay_", "db", szFilename ) )
				{
					if ( !g_pDB->SaveDB( szFilename ) )
					{
						sprintf( szMsg, "DB_StartSending (%s): IGameDB::SaveDB failed.\n", szFilename );
						SERVER_PRINT( szMsg );
					}
					else
					{
						pid_t pid = fork();
						if ( pid == 0 )
						{
							execl( "./sendgameinfo", "sendgameinfo", "-file", szFilename, "-ip", szIP, "-bps", "4096", "-autodelete", NULL );
						}
						else if ( pid < 1 )
						{
							// Note: the original builds this message but never prints it
							sprintf( szMsg, "DB_StartSending (%s): CreateProcess failed.\n(%s)\n", szFilename, strerror( errno ) );
						}
						else
						{
							sprintf( szMsg, "DB_StartSending (%s): succeeded.\n", szFilename );
							bRet = true;
							SERVER_PRINT( szMsg );
						}
					}
				}
			}
		}
	}

	if ( bClear )
		DB_Clear();

	return bRet;
}

void DB_Clear( void )
{
	if ( !g_pDB )
		return;

	for ( CAreaDef *pArea = g_pActiveAreas; pArea; pArea = pArea->m_pNext )
		pArea->ClearClassData();

	g_pDB->Term();
	InitDBFormat();
}

HROW DB_GetRow_Level( const char *pLevelName )
{
	if ( !g_pDB )
		return NULL;

	return g_pDB->FindRow( g_hLevel, 1, true, g_hLevel_LevelName, pLevelName );
}

HROW DB_GetRow_LevelClass( const char *pLevelName, const char *pClassName )
{
	if ( !g_pDB )
		return NULL;

	HROW hLevel = g_pDB->FindRow( g_hLevel, 1, true, g_hLevel_LevelName, pLevelName );
	return g_pDB->FindRow( g_hLevelClass, 2, true, g_hLevelClass_ClassName, pClassName, g_hLevelClass_Parent, hLevel );
}

HROW DB_GetRow_LevelArea( const char *pLevelName, const char *pAreaName )
{
	if ( !g_pDB )
		return NULL;

	HROW hLevel = g_pDB->FindRow( g_hLevel, 1, true, g_hLevel_LevelName, pLevelName );
	return g_pDB->FindRow( g_hLevelArea, 2, true, g_hLevelArea_AreaName, pAreaName, g_hLevelArea_Parent, hLevel );
}

HROW DB_GetRow_LevelAreaClass( const char *pLevelName, const char *pAreaName, const char *pClassName )
{
	if ( !g_pDB )
		return NULL;

	HROW hLevel = g_pDB->FindRow( g_hLevel, 1, true, g_hLevel_LevelName, pLevelName );
	HROW hArea = g_pDB->FindRow( g_hLevelArea, 2, true, g_hLevelArea_AreaName, pAreaName, g_hLevelArea_Parent, hLevel );
	return g_pDB->FindRow( g_hLevelAreaClass, 2, true, g_hLevelAreaClass_ClassName, pClassName, g_hLevelAreaClass_Parent, hArea );
}

HROW DB_GetRow_LevelAreaClassWeapon( const char *pLevelName, const char *pAreaName, const char *pClassName, const char *pWeaponName )
{
	if ( !g_pDB )
		return NULL;

	HROW hClass = DB_GetRow_LevelAreaClass( pLevelName, pAreaName, pClassName );
	return g_pDB->FindRow( g_hLevelAreaClassWeapon, 2, true, g_hLevelAreaClassWeapon_WeaponName, pWeaponName, g_hLevelAreaClassWeapon_Parent, hClass );
}

HROW DB_GetRow_LevelAreaClassWeaponDamage( const char *pLevelName, const char *pAreaName, const char *pClassName, const char *pWeaponName, const char *pDamagedClassName )
{
	if ( !g_pDB )
		return NULL;

	HROW hClass = DB_GetRow_LevelAreaClass( pLevelName, pAreaName, pClassName );
	HROW hWeapon = g_pDB->FindRow( g_hLevelAreaClassWeapon, 2, true, g_hLevelAreaClassWeapon_WeaponName, pWeaponName, g_hLevelAreaClassWeapon_Parent, hClass );
	return g_pDB->FindRow( g_hLevelAreaClassWeaponDamage, 2, true, g_hLevelAreaClassWeaponDamage_DamagedClassName, pDamagedClassName, g_hLevelAreaClassWeaponDamage_Parent, hWeapon );
}

HFIELD DB_GetField( HROW hRow, HCOLUMN hColumn )
{
	if ( !g_pDB )
		return NULL;

	return g_pDB->GetField( hRow, hColumn );
}

bool DB_SetFieldValueInt( HFIELD hField, int32 value )
{
	if ( !g_pDB )
		return false;

	return g_pDB->SetFieldValueInt( hField, value );
}

bool DB_AddToField( HFIELD hField, int32 amount )
{
	int32 value;

	if ( !g_pDB || !g_pDB->GetFieldValueInt( hField, value ) )
		return false;

	return g_pDB->SetFieldValueInt( hField, value + amount );
}

const char *DB_GetLevelName( void )
{
	return STRING( gpGlobals->mapname );
}

// The info_areadef containing pos, or the default area
CAreaDef *DB_GetArea( const Vector &pos )
{
	for ( CAreaDef *pArea = g_pActiveAreas; pArea; pArea = pArea->m_pNext )
	{
		entvars_t *pevArea = pArea->pev;
		if ( !pevArea )
			continue;

		Vector vecLocal = pos - pevArea->origin;
		if ( vecLocal.x > pevArea->mins.x && vecLocal.y > pevArea->mins.y && vecLocal.z > pevArea->mins.z &&
			vecLocal.x < pevArea->maxs.x && vecLocal.y < pevArea->maxs.y && vecLocal.z < pevArea->maxs.z )
		{
			return pArea;
		}
	}

	return &g_DefaultArea;
}

const char *DB_GetAreaName( const Vector &pos )
{
	return DB_GetArea( pos )->m_AreaName;
}
