/***
*
*	Datamining helpers shared between game dlls.
*
*	Reconstructed from tfc.so (legacy), DWARF-guided.
*
****/

#include <stdio.h>

// Finds an unused filename of the form <title><n>.<ext>
bool GetUniqueFilename( const char *pTitle, const char *pExt, char *pFilename )
{
	for ( int i = 0; i < 32000; i++ )
	{
		sprintf( pFilename, "%s%d.%s", pTitle, i, pExt );

		FILE *fp = fopen( pFilename, "rb" );
		if ( !fp )
			return true;

		fclose( fp );
	}

	return false;
}
