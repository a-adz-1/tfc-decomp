// CUtlMemory<CFontAmalgam::TFontRange>::Grow  @ 00225420
/* WARNING: Enum "FT_Encoding_": Some values do not have unique names */
/* DWARF original prototype: void Grow(CUtlMemory<CFontAmalgam::TFontRange> * this, int num) */

void __thiscall
CUtlMemory<CFontAmalgam::TFontRange>::Grow(CUtlMemory<CFontAmalgam::TFontRange> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  TFontRange *pTVar4;
  
                    /* Unresolved local var: int growSize@[???] */
  iVar1 = this->m_GrowSize;
  if (iVar1 < 0) {
    bVar2 = 0 < num;
    num = iVar1;
    if (bVar2) {
      return;
    }
  }
  else if ((num < 1) && (num = iVar1, iVar1 == 0)) {
    iVar1 = this->m_NumAllocated;
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    iVar3 = iVar3 + iVar1;
    pTVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x002254a0;
  }
  iVar3 = num + this->m_NumAllocated;
  pTVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x002254a0:
  if (pTVar4 != (TFontRange *)0x0) {
    pTVar4 = realloc(pTVar4,iVar3 * 0xc);
    this->m_pMemory = pTVar4;
    return;
  }
                    /* Unresolved local var: int growSize@[???] */
  pTVar4 = malloc(iVar3 * 0xc);
  this->m_pMemory = pTVar4;
  return;
}


