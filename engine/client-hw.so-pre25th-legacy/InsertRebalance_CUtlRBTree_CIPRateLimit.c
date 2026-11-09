// CUtlRBTree<CIPRateLimit::iprate_s,_int>::InsertRebalance  @ 00182130
/* DWARF original prototype: void InsertRebalance(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this,
   int elem) */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::InsertRebalance
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  int iVar1;
  int iVar2;
  Node_t *pNVar3;
  int iVar4;
  int iVar5;
  Links_t *pLVar6;
  
  do {
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int grandparent@[???]
                       Unresolved local var: int uncle@[DW_OP_reg2(EDX)] */
    iVar1 = this->m_Root;
    if (elem == iVar1) {
LAB_001821a5:
      (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    iVar1 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    if ((((Node_t *)pLVar6)->super_Links_t).m_Tag != 0) {
      iVar1 = this->m_Root;
      goto LAB_001821a5;
    }
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    iVar1 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
    }
    if (iVar1 == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
                    /* Unresolved local var: int uncle@[DW_OP_reg2(EDX)] */
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 0) {
LAB_001822d4:
        (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        elem = iVar5;
      }
      else {
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        if (elem == (((Node_t *)pLVar6)->super_Links_t).m_Right) {
          RotateLeft(this,iVar1);
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar5 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::lexical_block_0::s_Sentinel;
          if (iVar1 != -1) {
            pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
          }
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar4 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          if (iVar5 == -1) {
            pLVar6 = &Links::lexical_block_0::s_Sentinel;
            pNVar3 = (this->m_Elements).m_pMemory + -1;
          }
          else {
            pNVar3 = (this->m_Elements).m_pMemory + iVar5;
            pLVar6 = &pNVar3->super_Links_t;
          }
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + iVar1;
          iVar1 = elem;
        }
        (pNVar3->super_Links_t).m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        RotateRight(this,iVar5);
        elem = iVar1;
      }
    }
    else {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 0) goto LAB_001822d4;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if (elem == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
        RotateRight(this,iVar1);
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar5 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (iVar1 != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar5 == -1) {
          pLVar6 = &Links::lexical_block_0::s_Sentinel;
          pNVar3 = (this->m_Elements).m_pMemory + -1;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + iVar5;
          pLVar6 = &pNVar3->super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
      }
      else {
        pNVar3 = (this->m_Elements).m_pMemory + iVar1;
        iVar1 = elem;
      }
      (pNVar3->super_Links_t).m_Tag = 1;
      (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
      RotateLeft(this,iVar5);
      elem = iVar1;
    }
  } while( true );
}


