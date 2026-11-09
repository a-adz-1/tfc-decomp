// CUtlMemory<CFontTextureCache::page_t>::Grow  @ 00222a40
/* DWARF original prototype: void Grow(CUtlMemory<CFontTextureCache::page_t> * this, int num) */

void __thiscall
CUtlMemory<CFontTextureCache::page_t>::Grow(CUtlMemory<CFontTextureCache::page_t> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  page_t *ppVar4;
  
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
    ppVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x00222ac0;
  }
  ppVar4 = this->m_pMemory;
  iVar3 = num + this->m_NumAllocated;
  this->m_NumAllocated = iVar3;
joined_r0x00222ac0:
  if (ppVar4 != (page_t *)0x0) {
    ppVar4 = realloc(ppVar4,iVar3 * 0xc);
    this->m_pMemory = ppVar4;
    return;
  }
  ppVar4 = malloc(iVar3 * 0xc);
  this->m_pMemory = ppVar4;
  return;
}


