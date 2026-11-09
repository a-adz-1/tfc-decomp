// CUtlVector<wchar_t*>::InsertBefore  @ 0022f440
/* DWARF original prototype: int InsertBefore(CUtlVector<wchar_t*> * this, int elem, wchar_t * *
   src) */

int __thiscall CUtlVector<wchar_t*>::InsertBefore(CUtlVector<wchar_t*> *this,int elem,wchar_t **src)

{
  int iVar1;
  int iVar2;
  wchar_t **ppwVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = (this->m_Memory).m_NumAllocated;
  iVar4 = this->m_Size + 1;
  if (iVar4 <= iVar1) {
LAB_0022f510:
    ppwVar3 = (this->m_Memory).m_pMemory;
    goto LAB_0022f4ab;
  }
  iVar2 = (this->m_Memory).m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar4 - iVar1 < iVar2) {
    if ((0 < iVar2) || (iVar2 != 0)) goto LAB_0022f483;
    iVar2 = 1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    iVar2 = iVar1 + iVar2;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar5 = iVar2 < 0;
    iVar2 = iVar4 - iVar1;
    if (bVar5) goto LAB_0022f510;
LAB_0022f483:
    iVar2 = iVar2 + iVar1;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
                    /* Unresolved local var: int growSize@[???] */
  ppwVar3 = (this->m_Memory).m_pMemory;
                    /* catch() { ... } // from try @ 0022f36a with catch @ 0022f48e */
  if (ppwVar3 == (wchar_t **)0x0) {
    ppwVar3 = malloc(iVar2 << 2);
    (this->m_Memory).m_pMemory = ppwVar3;
  }
  else {
    ppwVar3 = realloc(ppwVar3,iVar2 << 2);
    iVar4 = this->m_Size + 1;
    (this->m_Memory).m_pMemory = ppwVar3;
  }
LAB_0022f4ab:
  this->m_Size = iVar4;
                    /* Unresolved local var: int numToMove@[???] */
                    /* catch() { ... } // from try @ 0022f4ed with catch @ 0022f4b0
                       catch() { ... } // from try @ 0022fabc with catch @ 0022f4b0
                       catch() { ... } // from try @ 0022fc90 with catch @ 0022f4b0 */
  iVar4 = (iVar4 - elem) + -1;
  if (0 < iVar4) {
    memmove(ppwVar3 + elem + 1,ppwVar3 + elem,iVar4 * 4);
    ppwVar3 = (this->m_Memory).m_pMemory;
  }
  if (ppwVar3 + elem != (wchar_t **)0x0) {
    ppwVar3[elem] = *src;
  }
                    /* try { // try from 0022f4ed to 0023f9cb has its CatchHandler @ 0022f4b0 */
  return elem;
}


// CUtlVector<wchar_t*>::~CUtlVector  @ 0022f410
/* DWARF original prototype: void ~CUtlVector(CUtlVector<wchar_t*> * this, int __in_chrg) */

void __thiscall CUtlVector<wchar_t*>::~CUtlVector(CUtlVector<wchar_t*> *this,int __in_chrg)

{
  int iVar1;
  wchar_t **__ptr;
  
  iVar1 = (this->m_Memory).m_GrowSize;
  this->m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_Memory).m_pMemory, __ptr != (wchar_t **)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


// CUtlVector<wchar_t>::InsertBefore  @ 002202b0
/* DWARF original prototype: int InsertBefore(CUtlVector<wchar_t> * this, int elem, wchar_t * src)
    */

int __thiscall CUtlVector<wchar_t>::InsertBefore(CUtlVector<wchar_t> *this,int elem,wchar_t *src)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = (this->m_Memory).m_NumAllocated;
  iVar4 = this->m_Size + 1;
  if (iVar4 <= iVar1) {
LAB_00220380:
    pwVar3 = (this->m_Memory).m_pMemory;
    goto LAB_0022031b;
  }
  iVar2 = (this->m_Memory).m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar4 - iVar1 < iVar2) {
    if ((0 < iVar2) || (iVar2 != 0)) goto LAB_002202f3;
    iVar2 = 1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    iVar2 = iVar1 + iVar2;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar5 = iVar2 < 0;
    iVar2 = iVar4 - iVar1;
    if (bVar5) goto LAB_00220380;
LAB_002202f3:
    iVar2 = iVar2 + iVar1;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
                    /* Unresolved local var: int growSize@[???] */
  pwVar3 = (this->m_Memory).m_pMemory;
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = malloc(iVar2 << 2);
    (this->m_Memory).m_pMemory = pwVar3;
  }
  else {
    pwVar3 = realloc(pwVar3,iVar2 << 2);
    iVar4 = this->m_Size + 1;
    (this->m_Memory).m_pMemory = pwVar3;
  }
LAB_0022031b:
  this->m_Size = iVar4;
                    /* Unresolved local var: int numToMove@[???] */
  iVar4 = (iVar4 - elem) + -1;
  if (0 < iVar4) {
    memmove(pwVar3 + elem + 1,pwVar3 + elem,iVar4 * 4);
    pwVar3 = (this->m_Memory).m_pMemory;
  }
  if (pwVar3 + elem != (wchar_t *)0x0) {
    pwVar3[elem] = *src;
  }
  return elem;
}


// CUtlVector<wchar_t>::~CUtlVector  @ 00220160
/* DWARF original prototype: void ~CUtlVector(CUtlVector<wchar_t> * this, int __in_chrg) */

void __thiscall CUtlVector<wchar_t>::~CUtlVector(CUtlVector<wchar_t> *this,int __in_chrg)

{
  int iVar1;
  wchar_t *__ptr;
  
  iVar1 = (this->m_Memory).m_GrowSize;
  this->m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_Memory).m_pMemory, __ptr != (wchar_t *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


