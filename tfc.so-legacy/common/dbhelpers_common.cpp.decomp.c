// Ghidra decompilation of functions from common/dbhelpers_common.cpp
// 1 functions, ordered by original source line

// GetUniqueFilename  @ 00177690  (line 11)

bool GetUniqueFilename(char *pTitle,char *pExt,char *pFilename)

{
  FILE *__stream;
  int iVar1;
  
  iVar1 = 0;
  do {
    sprintf(pFilename,"%s%d.%s",pTitle,iVar1,pExt);
    __stream = fopen(pFilename,"rb");
    if (__stream == (FILE *)0x0) {
      return true;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: FILE * fp@[???] */
    iVar1 = iVar1 + 1;
    fclose(__stream);
  } while (iVar1 != 32000);
  return false;
}


