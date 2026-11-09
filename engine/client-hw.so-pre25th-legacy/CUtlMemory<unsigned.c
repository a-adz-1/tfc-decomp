// CUtlMemory<unsigned_int>::Grow  @ 002141e0
/* DWARF original prototype: void Grow(CUtlMemory<unsigned_int> * this, int num) */

void __thiscall CUtlMemory<unsigned_int>::Grow(CUtlMemory<unsigned_int> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  
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
    puVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x0021425d;
  }
  puVar4 = this->m_pMemory;
  iVar3 = num + this->m_NumAllocated;
  this->m_NumAllocated = iVar3;
joined_r0x0021425d:
  if (puVar4 != (uint *)0x0) {
    puVar4 = realloc(puVar4,iVar3 * 4);
    this->m_pMemory = puVar4;
    return;
  }
  puVar4 = malloc(iVar3 * 4);
  this->m_pMemory = puVar4;
  return;
}


