/***
*
*	Team Fortress Classic: map areas for stats logging (info_areadef).
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/
#ifndef AREADEF_H
#define AREADEF_H

// Per-class stats gathered while players are inside an area
class DBAreaClassData
{
public:
	DBAreaClassData();
	void Clear( void );
	void MergeData( DBAreaClassData *pSource );	// add pSource's data to ours and clear it

	int m_DB_PingTotal;
	int m_DB_nPingTests;
	int m_DB_TimeInArea;
};

class CAreaDef : public CBaseEntity
{
public:
	CAreaDef( bool bDefaultArea = false );
	~CAreaDef();

	virtual int Save( CSave &save );
	virtual int Restore( CRestore &restore );
	static TYPEDESCRIPTION m_SaveData[];

	virtual void KeyValue( KeyValueData *pkvd );

	DBAreaClassData *GetClassData( const char *pClassName );
	void ClearClassData( void );
	void MergeData( CAreaDef *pSource );

	DBAreaClassData m_ClassData[ PC_LASTCLASS ];
	char m_AreaName[ 32 ];
	CAreaDef *m_pNext;	// all areas are linked through g_pActiveAreas
};

// The area used for anywhere not inside an info_areadef
extern CAreaDef g_DefaultArea;
extern CAreaDef *g_pActiveAreas;

#endif // AREADEF_H
