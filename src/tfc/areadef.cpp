/***
*
*	Team Fortress Classic: map areas for stats logging (info_areadef).
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "saverestore.h"
#include "tf_defs.h"
#include "areadef.h"

extern int g_nActiveAreas;	// dbhelpers.cpp

LINK_ENTITY_TO_CLASS( info_areadef, CAreaDef );

TYPEDESCRIPTION CAreaDef::m_SaveData[] =
{
	DEFINE_FIELD( CAreaDef, m_AreaName, FIELD_STRING ),
};

IMPLEMENT_SAVERESTORE( CAreaDef, CBaseEntity );

CAreaDef g_DefaultArea( true );
CAreaDef *g_pActiveAreas;

DBAreaClassData::DBAreaClassData()
{
	Clear();
}

void DBAreaClassData::Clear( void )
{
	m_DB_PingTotal = 0;
	m_DB_nPingTests = 0;
	m_DB_TimeInArea = 0;
}

void DBAreaClassData::MergeData( DBAreaClassData *pSource )
{
	m_DB_PingTotal += pSource->m_DB_PingTotal;
	m_DB_nPingTests += pSource->m_DB_nPingTests;
	m_DB_TimeInArea += pSource->m_DB_TimeInArea;
	pSource->Clear();
}

CAreaDef::CAreaDef( bool bDefaultArea )
{
	g_nActiveAreas++;

	if ( bDefaultArea )
	{
		strcpy( m_AreaName, "DefaultArea" );
		m_pNext = NULL;
	}
	else
	{
		m_AreaName[0] = 0;
		m_pNext = g_pActiveAreas;
	}

	g_pActiveAreas = this;
}

CAreaDef::~CAreaDef()
{
	g_nActiveAreas--;

	// unlink from the area list
	for ( CAreaDef **ppArea = &g_pActiveAreas; *ppArea; ppArea = &( *ppArea )->m_pNext )
	{
		if ( *ppArea == this )
		{
			*ppArea = m_pNext;
			break;
		}
	}
}

void CAreaDef::KeyValue( KeyValueData *pkvd )
{
	if ( FStrEq( pkvd->szKeyName, "areaname" ) )
	{
		strncpy( m_AreaName, pkvd->szValue, sizeof( m_AreaName ) - 1 );
		m_AreaName[ sizeof( m_AreaName ) - 1 ] = 0;
		pkvd->fHandled = TRUE;
	}
	else
	{
		CBaseEntity::KeyValue( pkvd );
	}
}

DBAreaClassData *CAreaDef::GetClassData( const char *pClassName )
{
	for ( int i = 0; i < PC_LASTCLASS; i++ )
	{
		if ( !stricmp( pClassName, sClassNames[i] ) )
			return &m_ClassData[i];
	}

	return NULL;
}

void CAreaDef::MergeData( CAreaDef *pSource )
{
	for ( int i = 0; i < PC_LASTCLASS; i++ )
		m_ClassData[i].MergeData( &pSource->m_ClassData[i] );
}

void CAreaDef::ClearClassData( void )
{
	for ( int i = 0; i < PC_LASTCLASS; i++ )
		m_ClassData[i].Clear();
}
