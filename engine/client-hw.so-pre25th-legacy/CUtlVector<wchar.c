// CUtlVector<wchar_t*>::InsertBefore  @ 0025da90
/* DWARF original prototype: int InsertBefore(CUtlVector<wchar_t*> * this, int elem, wchar_t * *
   src) */

int __thiscall CUtlVector<wchar_t*>::InsertBefore(CUtlVector<wchar_t*> *this,int elem,wchar_t **src)

{
  int iVar1;
  int iVar2;
  wchar_t **ppwVar3;
  
  iVar2 = this->m_Size;
  iVar1 = (this->m_Memory).m_NumAllocated;
  if (iVar1 <= iVar2) {
    CUtlMemory<wchar_t*>::Grow(&this->m_Memory,(iVar2 + 1) - iVar1);
    iVar2 = this->m_Size;
  }
  this->m_Size = iVar2 + 1;
                    /* Unresolved local var: int numToMove@[???] */
  iVar2 = ((iVar2 + 1) - elem) + -1;
  if (0 < iVar2) {
    ppwVar3 = (this->m_Memory).m_pMemory;
    memmove(ppwVar3 + elem + 1,ppwVar3 + elem,iVar2 * 4);
  }
  ppwVar3 = (this->m_Memory).m_pMemory + elem;
  if (ppwVar3 != (wchar_t **)0x0) {
    *ppwVar3 = *src;
  }
  return elem;
}


// CUtlVector<wchar_t>::CopyArray  @ 0025c940
/* DWARF original prototype: void CopyArray(CUtlVector<wchar_t> * this, wchar_t * pArray, int size)
    */

void __thiscall CUtlVector<wchar_t>::CopyArray(CUtlVector<wchar_t> *this,wchar_t *pArray,int size)

{
  wchar_t *__src;
  int iVar1;
  
  this->m_Size = 0;
  if (size != 0) {
    iVar1 = (this->m_Memory).m_NumAllocated;
    if (iVar1 < size) {
      CUtlMemory<wchar_t>::Grow(&this->m_Memory,size - iVar1);
      iVar1 = this->m_Size;
                    /* Unresolved local var: int numToMove@[???] */
      this->m_Size = size + iVar1;
      if ((0 < size) && (0 < iVar1)) {
        __src = (this->m_Memory).m_pMemory;
        memmove(__src + size,__src,iVar1 << 2);
      }
    }
    else {
      this->m_Size = size;
    }
                    /* Unresolved local var: int i@[???] */
    if (0 < size) {
      iVar1 = 0;
      do {
        (this->m_Memory).m_pMemory[iVar1] = pArray[iVar1];
        iVar1 = iVar1 + 1;
      } while (iVar1 != size);
      return;
    }
  }
  return;
}


// CUtlVector<wchar_t>::InsertBefore  @ 002540f0
/* DWARF original prototype: int InsertBefore(CUtlVector<wchar_t> * this, int elem, wchar_t * src)
    */

int __thiscall CUtlVector<wchar_t>::InsertBefore(CUtlVector<wchar_t> *this,int elem,wchar_t *src)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  
  iVar2 = this->m_Size;
  iVar1 = (this->m_Memory).m_NumAllocated;
  if (iVar1 <= iVar2) {
    CUtlMemory<wchar_t>::Grow(&this->m_Memory,(iVar2 + 1) - iVar1);
    iVar2 = this->m_Size;
  }
  this->m_Size = iVar2 + 1;
                    /* Unresolved local var: int numToMove@[???] */
  iVar2 = ((iVar2 + 1) - elem) + -1;
  if (0 < iVar2) {
    pwVar3 = (this->m_Memory).m_pMemory;
    memmove(pwVar3 + elem + 1,pwVar3 + elem,iVar2 * 4);
  }
  pwVar3 = (this->m_Memory).m_pMemory + elem;
  if (pwVar3 != (wchar_t *)0x0) {
    *pwVar3 = *src;
  }
  return elem;
}


