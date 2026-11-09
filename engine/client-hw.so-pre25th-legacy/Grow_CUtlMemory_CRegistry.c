// CUtlMemory<CRegistry::KV>::Grow  @ 0021be40
/* DWARF original prototype: void Grow(CUtlMemory<CRegistry::KV> * this, int num) */

void __thiscall CUtlMemory<CRegistry::KV>::Grow(CUtlMemory<CRegistry::KV> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  KV *pKVar4;
  
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
    pKVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x0021bebd;
  }
  pKVar4 = this->m_pMemory;
  iVar3 = num + this->m_NumAllocated;
  this->m_NumAllocated = iVar3;
joined_r0x0021bebd:
  if (pKVar4 != (KV *)0x0) {
    pKVar4 = realloc(pKVar4,iVar3 * 0x80);
    this->m_pMemory = pKVar4;
    return;
  }
  pKVar4 = malloc(iVar3 * 0x80);
  this->m_pMemory = pKVar4;
  return;
}


