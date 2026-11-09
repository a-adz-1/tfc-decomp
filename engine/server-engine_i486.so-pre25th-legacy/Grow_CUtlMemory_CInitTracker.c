// CUtlMemory<CInitTracker::InitFunc*>::Grow  @ 000c7fc0
/* DWARF original prototype: void Grow(CUtlMemory<CInitTracker::InitFunc*> * this, int num) */

void __thiscall
CUtlMemory<CInitTracker::InitFunc*>::Grow(CUtlMemory<CInitTracker::InitFunc*> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  InitFunc **ppIVar4;
  
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
    ppIVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x000c803d;
  }
  iVar3 = num + this->m_NumAllocated;
  ppIVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x000c803d:
  if (ppIVar4 != (InitFunc **)0x0) {
    ppIVar4 = realloc(ppIVar4,iVar3 * 4);
    this->m_pMemory = ppIVar4;
    return;
  }
  ppIVar4 = malloc(iVar3 * 4);
  this->m_pMemory = ppIVar4;
  return;
}


