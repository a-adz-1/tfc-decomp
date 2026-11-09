// CUtlMemory<CVideoMode_Common::bimage_t>::Grow  @ 00214150
/* DWARF original prototype: void Grow(CUtlMemory<CVideoMode_Common::bimage_t> * this, int num) */

void __thiscall
CUtlMemory<CVideoMode_Common::bimage_t>::Grow(CUtlMemory<CVideoMode_Common::bimage_t> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  bimage_t *pbVar4;
  
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
    pbVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x002141d0;
  }
  iVar3 = num + this->m_NumAllocated;
  pbVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x002141d0:
  if (pbVar4 != (bimage_t *)0x0) {
    pbVar4 = realloc(pbVar4,iVar3 * 0x18);
    this->m_pMemory = pbVar4;
    return;
  }
  pbVar4 = malloc(iVar3 * 0x18);
  this->m_pMemory = pbVar4;
  return;
}


