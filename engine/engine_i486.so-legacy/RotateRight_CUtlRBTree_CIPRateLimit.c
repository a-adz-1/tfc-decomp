// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RotateRight  @ 000cb210
/* DWARF original prototype: void RotateRight(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, int
   elem) */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::RotateRight
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  int iVar1;
  Links_t *pLVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int leftchild@[DW_OP_reg7(EDI)] */
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar7 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar7 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  if (elem == -1) {
    iVar7 = -0x1c;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar7 = elem * 0x1c;
    pLVar2 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
  }
  iVar1 = (((Node_t *)pLVar2)->super_Links_t).m_Left;
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  pNVar5 = (this->m_Elements).m_pMemory;
  if (iVar1 == -1) {
    iVar6 = -0x1c;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar6 = iVar1 * 0x1c;
    pLVar2 = &pNVar5[iVar1].super_Links_t;
  }
  *(int *)((int)&(pNVar5->super_Links_t).m_Left + iVar7) =
       (((Node_t *)pLVar2)->super_Links_t).m_Right;
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  pLVar2 = &Links::lexical_block_0::s_Sentinel;
  if (iVar1 != -1) {
    pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6);
  }
  if (pLVar2->m_Right != -1) {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar6);
    }
    pNVar5[pLVar2->m_Right].super_Links_t.m_Parent = elem;
  }
  if (iVar1 != -1) {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
    }
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + iVar6) = pLVar2->m_Parent;
  }
  if (elem == this->m_Root) {
    this->m_Root = iVar1;
  }
  else {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    iVar4 = pLVar2->m_Parent;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar5 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pNVar5 = (this->m_Elements).m_pMemory + iVar4;
    }
    if (elem == (pNVar5->super_Links_t).m_Right) {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar2->m_Parent].super_Links_t.m_Right = iVar1;
    }
    else {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar2->m_Parent].super_Links_t.m_Left = iVar1;
    }
  }
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar6) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar7) = iVar1;
  }
  return;
}


