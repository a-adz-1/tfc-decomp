/***
*
*	Valve game database (datamining) interface, provided by gamedb.so.
*	Reconstructed from tfc.so DWARF (common/gamedb/igamedb.h).
*
****/
#ifndef IGAMEDB_H
#define IGAMEDB_H

#include "../../public/interface.h"
#include "gamedb_common.h"

namespace gamedb
{
	struct Table;
	struct TableRow;
	struct Field;
}

typedef gamedb::Table *HTABLE;
typedef gamedb::TableRow *HROW;
typedef gamedb::Field *HFIELD;

class AddTableColumnDesc
{
public:
	const char *m_pName;
	ColumnType m_Type;
	HCOLUMN *m_pColumnHandle;
};

class IGameDB : public IBaseInterface
{
public:
	virtual void Release() = 0;
	virtual void Term() = 0;	// clear all tables

	virtual bool LoadDB( const char *pFilename ) = 0;
	virtual bool SaveDB( const char *pFilename ) = 0;

	virtual HTABLE AddTable( const char *pName, int nColumns, AddTableColumnDesc *pColumns ) = 0;
	// nColumns triples of (const char *name, ColumnType type, HCOLUMN *pHandle)
	virtual HTABLE AddTable_VA( const char *pName, int nColumns, ... ) = 0;
	virtual HTABLE GetTable_VA( const char *pName, int nColumns, ... ) = 0;

	// nKeys pairs of (HCOLUMN, value); bCreate adds the row if it doesn't exist
	virtual HROW FindRow( HTABLE hTable, int nKeys, bool bCreate, ... ) = 0;
	virtual HFIELD GetField( HROW hRow, HCOLUMN hColumn ) = 0;

	virtual bool GetFieldValueInt( HFIELD hField, int32 &value ) = 0;
	virtual bool SetFieldValueInt( HFIELD hField, int32 value ) = 0;
	virtual bool GetFieldValueString( HFIELD hField, char *pValue, uint32 maxLen ) = 0;
	virtual bool SetFieldValueString( HFIELD hField, const char *pValue ) = 0;
};

#endif // IGAMEDB_H
