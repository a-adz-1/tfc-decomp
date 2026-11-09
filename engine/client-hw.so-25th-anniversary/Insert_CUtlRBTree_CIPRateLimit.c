// CUtlRBTree<CIPRateLimit::iprate_s,_int>::Insert  @ 001267b0
/* WARNING: Variable defined which should be unmapped: newnode */
/* DWARF original prototype: int Insert(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, iprate_s *
   insert) */

int __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::Insert
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,iprate_s *insert)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  Node_t *pNVar4;
  int iVar5;
  int newnode;
  
                    /* Unresolved local var: int current@[???]
                       Unresolved local var: int parent@[???]
                       Unresolved local var: bool leftchild@[???] */
  iVar5 = this->m_Root;
  if (iVar5 == -1) {
    bVar1 = false;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory;
    iVar2 = iVar5;
    do {
      iVar5 = iVar2;
      bVar1 = (*this->m_LessFunc)(insert,&pNVar4[iVar5].m_Data);
      if (bVar1) {
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        bVar1 = true;
        iVar2 = pNVar4[iVar5].super_Links_t.m_Left;
      }
      else {
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        bVar1 = false;
        iVar2 = pNVar4[iVar5].super_Links_t.m_Right;
      }
    } while (iVar2 != -1);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: int newElem@[???] */
  iVar2 = this->m_FirstFree;
  if (iVar2 == -1) {
    iVar2 = (this->m_Elements).m_NumAllocated;
                    /* Unresolved local var: int newElem@[???] */
    if (iVar2 == this->m_TotalElements) {
      iVar3 = (this->m_Elements).m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((iVar3 == 0) && (iVar3 = 1, iVar2 != 0)) {
        iVar3 = iVar2;
      }
                    /* Unresolved local var: int growSize@[???] */
      pNVar4 = (this->m_Elements).m_pMemory;
      iVar3 = iVar3 + iVar2;
      (this->m_Elements).m_NumAllocated = iVar3;
      if (pNVar4 == (Node_t *)0x0) {
        pNVar4 = malloc(iVar3 * 0x1c);
        (this->m_Elements).m_pMemory = pNVar4;
      }
      else {
        pNVar4 = realloc(pNVar4,iVar3 * 0x1c);
        iVar2 = this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar4;
      }
    }
    else {
      pNVar4 = (this->m_Elements).m_pMemory;
      iVar2 = this->m_TotalElements;
    }
    this->m_TotalElements = iVar2 + 1;
    pNVar4 = pNVar4 + iVar2;
  }
  else {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar4 = (this->m_Elements).m_pMemory + iVar2;
    this->m_FirstFree = (pNVar4->super_Links_t).m_Right;
  }
  (pNVar4->super_Links_t).m_Parent = iVar5;
  (pNVar4->super_Links_t).m_Right = -1;
  (pNVar4->super_Links_t).m_Left = -1;
  (pNVar4->super_Links_t).m_Tag = 0;
  if (iVar5 == -1) {
    this->m_Root = iVar2;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory + iVar5;
    if (bVar1) {
      (pNVar4->super_Links_t).m_Left = iVar2;
    }
    else {
      (pNVar4->super_Links_t).m_Right = iVar2;
    }
  }
  InsertRebalance(this,iVar2);
  pNVar4 = (this->m_Elements).m_pMemory;
  this->m_NumElements = this->m_NumElements + 1;
  pNVar4 = pNVar4 + iVar2;
  if (pNVar4 != (Node_t *)0xfffffff0) {
    (pNVar4->m_Data).ip = insert->ip;
    (pNVar4->m_Data).lastTime = insert->lastTime;
    (pNVar4->m_Data).count = insert->count;
  }
  return iVar2;
}


