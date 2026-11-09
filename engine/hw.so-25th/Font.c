// Font_Reset  @ 001d8040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Font_Reset(void)

{
  BaseFontPlat *pBVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
                    /* Unresolved local var: int i@[???] */
  iVar2 = staticFontPlatDar._count;
  if (0 < staticFontPlatDar._count) {
    do {
      if ((-1 < iVar3) && (pBVar1 = staticFontPlatDar._data[iVar3], pBVar1 != (BaseFontPlat *)0x0))
      {
        (*pBVar1->_vptr_BaseFontPlat[1])(pBVar1);
        iVar2 = staticFontPlatDar._count;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if (-1 < staticFontPlatDar._capacity) {
    staticFontPlatDar._count = 0;
  }
  return;
}


