/***
*
*	Team Fortress Classic: gameplay datamining (mp_datamine) via gamedb.so
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/
#ifndef DBHELPERS_H
#define DBHELPERS_H

#include "../common/gamedb/igamedb.h"

class CAreaDef;

extern IGameDB *g_pDB;
extern cvar_t mp_datamine;

void DB_GameDBLoad( void );
void DB_GameDBShutdown( void );
void DB_OnStartLevel( void );
void DB_OnStartFrame( void );
bool DB_Transmit( bool bClear );
void DB_Clear( void );

HROW DB_GetRow_Level( const char *pLevelName );
HROW DB_GetRow_LevelClass( const char *pLevelName, const char *pClassName );
HROW DB_GetRow_LevelArea( const char *pLevelName, const char *pAreaName );
HROW DB_GetRow_LevelAreaClass( const char *pLevelName, const char *pAreaName, const char *pClassName );
HROW DB_GetRow_LevelAreaClassWeapon( const char *pLevelName, const char *pAreaName, const char *pClassName, const char *pWeaponName );
HROW DB_GetRow_LevelAreaClassWeaponDamage( const char *pLevelName, const char *pAreaName, const char *pClassName, const char *pWeaponName, const char *pDamagedClassName );

HFIELD DB_GetField( HROW hRow, HCOLUMN hColumn );
bool DB_SetFieldValueInt( HFIELD hField, int32 value );
bool DB_AddToField( HFIELD hField, int32 amount );

const char *DB_GetLevelName( void );
CAreaDef *DB_GetArea( const Vector &pos );
const char *DB_GetAreaName( const Vector &pos );

// Columns used by the rest of the game code
extern HCOLUMN g_hLevelAreaClass_DeathCount;
extern HCOLUMN g_hLevelAreaClassWeapon_NumShotsFired;
extern HCOLUMN g_hLevelAreaClassWeaponDamage_DamageInflicted;
extern HCOLUMN g_hLevelAreaClassWeaponDamage_Kills;

extern int g_nActiveAreas;

bool GetUniqueFilename( const char *pTitle, const char *pExt, char *pFilename );

#endif // DBHELPERS_H
