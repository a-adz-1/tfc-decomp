/***
*
*	Valve game database (datamining) - shared types.
*	Reconstructed from tfc.so DWARF (common/gamedb/gamedb_common.h).
*
****/
#ifndef GAMEDB_COMMON_H
#define GAMEDB_COMMON_H

#include "steam/steamtypes.h"

typedef uint32 HCOLUMN;

// Column types (values from InitDBFormat; names reconstructed)
typedef unsigned int ColumnType;
#define COLUMN_STRING	0
#define COLUMN_INT		1
#define COLUMN_PARENT	2	// row handle of the parent table's row

#endif // GAMEDB_COMMON_H
