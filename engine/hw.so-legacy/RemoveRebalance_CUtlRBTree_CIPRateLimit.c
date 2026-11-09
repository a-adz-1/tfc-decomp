// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveRebalance  @ 0017fee0
/* DWARF original prototype: void RemoveRebalance(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this,
   int elem) */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveRebalance
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  Node_t *pNVar6;
  int iVar7;
  bool bVar8;
  int local_20;
  
  iVar4 = this->m_Root;
  do {
    if (elem == iVar4) {
LAB_00180150:
      (this->m_Elements).m_pMemory[elem].super_Links_t.m_Tag = 1;
      return;
    }
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    if ((((Node_t *)pLVar1)->super_Links_t).m_Tag != 1) goto LAB_00180150;
                    /* Unresolved local var: int parent@[???] */
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar5 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
    }
    if (elem != (((Node_t *)pLVar1)->super_Links_t).m_Left) {
                    /* Unresolved local var: int sibling@[???] */
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 0) {
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        RotateRight(this,iVar5);
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar5 != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
      }
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar7 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar7 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar7 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar7 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar3 != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
          if (iVar4 != -1) {
            (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 0;
          }
          goto LAB_001805fd;
        }
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_0018005d;
LAB_001803d0:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar4 != -1) goto LAB_00180066;
LAB_001803f4:
        iVar7 = -0x1c;
        iVar3 = Links::lexical_block_0::s_Sentinel.m_Left;
      }
      else {
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_001803d0;
LAB_0018005d:
        if (iVar4 == -1) goto LAB_001803f4;
LAB_00180066:
        iVar7 = iVar4 * 0x1c;
        iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Left;
      }
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar5 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
        }
        pNVar6[pLVar1->m_Right].super_Links_t.m_Tag = 1;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + iVar7) = 0;
        RotateLeft(this,iVar4);
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar6 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pNVar6 = (this->m_Elements).m_pMemory + elem;
        }
        iVar5 = (pNVar6->super_Links_t).m_Parent;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar4 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          if (iVar5 != -1) goto LAB_00180ae5;
LAB_00181080:
          local_20 = -0x1c;
          pLVar1 = &Links::lexical_block_0::s_Sentinel;
        }
        else {
          if (iVar5 == -1) goto LAB_00181080;
LAB_00180ae5:
          local_20 = iVar5 * 0x1c;
          pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
        iVar7 = iVar4 * 0x1c;
      }
      else {
        local_20 = iVar5 * 0x1c;
      }
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          goto LAB_001800d0;
        }
        if (iVar5 != -1) goto LAB_001800d9;
LAB_00180a4c:
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
      }
      else {
LAB_001800d0:
        if (iVar5 == -1) goto LAB_00180a4c;
LAB_001800d9:
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + local_20);
      }
      bVar8 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar6->super_Links_t).m_Tag + iVar7) = pLVar1->m_Tag;
      *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
      if ((bVar8) &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        pNVar6 = (this->m_Elements).m_pMemory;
        if (iVar4 != -1) goto LAB_00180112;
LAB_00180940:
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
      }
      else {
        pNVar6 = (this->m_Elements).m_pMemory;
        if (iVar4 == -1) goto LAB_00180940;
LAB_00180112:
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
      }
      pNVar6[pLVar1->m_Left].super_Links_t.m_Tag = 1;
      RotateRight(this,iVar5);
      elem = this->m_Root;
      goto LAB_00180150;
    }
                    /* Unresolved local var: int sibling@[???] */
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar5 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
    }
    iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
    }
    if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 0) {
      (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
      (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
      RotateLeft(this,iVar5);
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      }
      iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    }
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
    }
    iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar7 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar7 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar3 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
    }
    if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar7 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar7 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag != 1) goto joined_r0x00180b21;
      if (iVar4 == -1) {
LAB_001805fd:
        iVar4 = this->m_Root;
        elem = iVar5;
      }
      else {
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 0;
        iVar4 = this->m_Root;
        elem = iVar5;
      }
    }
    else {
joined_r0x00180b21:
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar4 != -1) goto LAB_0018027e;
LAB_00180b54:
        iVar7 = -0x1c;
        iVar3 = Links::lexical_block_0::s_Sentinel.m_Right;
      }
      else {
        if (iVar4 == -1) goto LAB_00180b54;
LAB_0018027e:
        iVar7 = iVar4 * 0x1c;
        iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Right;
      }
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar5 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
        }
        pNVar6[pLVar1->m_Left].super_Links_t.m_Tag = 1;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + iVar7) = 0;
        RotateRight(this,iVar4);
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar5 == -1) {
          local_20 = -0x1c;
          pLVar1 = &Links::lexical_block_0::s_Sentinel;
        }
        else {
          local_20 = iVar5 * 0x1c;
          pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
        iVar7 = iVar4 * 0x1c;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_00180cf4;
LAB_001802e9:
        if (iVar5 != -1) goto LAB_001802f2;
LAB_00180d20:
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
      }
      else {
        local_20 = iVar5 * 0x1c;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_001802e9;
LAB_00180cf4:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          goto LAB_001802e9;
        }
        if (iVar5 == -1) goto LAB_00180d20;
LAB_001802f2:
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + local_20);
      }
      bVar8 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar6->super_Links_t).m_Tag + iVar7) = pLVar1->m_Tag;
      *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
      if ((bVar8) &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar6 = (this->m_Elements).m_pMemory;
      if (iVar4 == -1) {
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
      }
      else {
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
      }
      pNVar6[pLVar1->m_Right].super_Links_t.m_Tag = 1;
      RotateLeft(this,iVar5);
      iVar4 = this->m_Root;
      elem = iVar4;
    }
  } while( true );
}


