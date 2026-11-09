// CUtlMemory<wchar_t*>::Grow  @ 0025da00
/* DWARF original prototype: void Grow(CUtlMemory<wchar_t*> * this, int num) */

void __thiscall CUtlMemory<wchar_t*>::Grow(CUtlMemory<wchar_t*> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  wchar_t **ppwVar4;
  
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
    ppwVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x0025da7d;
  }
  iVar3 = num + this->m_NumAllocated;
  ppwVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x0025da7d:
  if (ppwVar4 != (wchar_t **)0x0) {
    ppwVar4 = realloc(ppwVar4,iVar3 * 4);
    this->m_pMemory = ppwVar4;
    return;
  }
  ppwVar4 = malloc(iVar3 * 4);
  this->m_pMemory = ppwVar4;
  return;
}


// CUtlMemory<wchar_t>::Grow  @ 00254060
/* DWARF original prototype: void Grow(CUtlMemory<wchar_t> * this, int num) */

void __thiscall CUtlMemory<wchar_t>::Grow(CUtlMemory<wchar_t> *this,int num)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  wchar_t *pwVar4;
  
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
    pwVar4 = this->m_pMemory;
    this->m_NumAllocated = iVar3;
    goto joined_r0x002540dd;
  }
  iVar3 = num + this->m_NumAllocated;
  pwVar4 = this->m_pMemory;
  this->m_NumAllocated = iVar3;
joined_r0x002540dd:
  if (pwVar4 != (wchar_t *)0x0) {
    pwVar4 = realloc(pwVar4,iVar3 * 4);
    this->m_pMemory = pwVar4;
    return;
  }
                    /* Unresolved local var: int growSize@[???] */
  pwVar4 = malloc(iVar3 * 4);
  this->m_pMemory = pwVar4;
  return;
}


