// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveAt  @ 00181350
/* WARNING: Variable defined which should be unmapped: ycolor */
/* DWARF original prototype: void RemoveAt(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, int elem)
    */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveAt
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  Node_t *pNVar7;
  Links_t *pLVar8;
  bool bVar9;
  Node_t *local_34;
  Node_t *local_30;
  int local_28;
  NodeColor_t ycolor;
  
  if (elem == -1) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar2 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  iVar2 = elem * 0x1c;
  pNVar7 = (this->m_Elements).m_pMemory + elem;
  iVar4 = elem;
  cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  if ((pNVar7->super_Links_t).m_Left != -1) {
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar3 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar7 = (this->m_Elements).m_pMemory + elem;
    }
    iVar3 = (pNVar7->super_Links_t).m_Right;
    cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    if (iVar3 != -1) {
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar2 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right;
        cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
        goto LAB_001813fd;
      }
      while( true ) {
        pLVar8 = &Links::lexical_block_0::s_Sentinel;
        if (iVar3 != -1) {
          pLVar8 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar8)->super_Links_t).m_Left == -1) break;
        if ((cVar1 == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel),
           cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
        }
        pLVar8 = &Links::lexical_block_0::s_Sentinel;
        if (iVar3 != -1) {
          pLVar8 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        iVar3 = (((Node_t *)pLVar8)->super_Links_t).m_Left;
LAB_001813fd:
        if ((cVar1 == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel),
           cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
        }
      }
      iVar2 = iVar3 * 0x1c;
      iVar4 = iVar3;
    }
  }
  if ((cVar1 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar3 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  }
  pLVar8 = &Links::lexical_block_0::s_Sentinel;
  if (iVar4 != -1) {
    pLVar8 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2);
  }
  if (pLVar8->m_Left == -1) {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pLVar8 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar8 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2);
    }
    local_28 = pLVar8->m_Right;
  }
  else {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pLVar8 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar8 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2);
    }
    local_28 = pLVar8->m_Left;
  }
  if (local_28 != -1) {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    if (iVar4 == -1) {
      local_34 = (this->m_Elements).m_pMemory;
      pLVar8 = &Links::lexical_block_0::s_Sentinel;
    }
    else {
      local_34 = (this->m_Elements).m_pMemory;
      pLVar8 = (Links_t *)((int)&(local_34->super_Links_t).m_Left + iVar2);
    }
    local_34[local_28].super_Links_t.m_Parent = pLVar8->m_Parent;
  }
  if (iVar4 == this->m_Root) {
    this->m_Root = local_28;
  }
  else {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pLVar8 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar8 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2);
    }
    iVar3 = pLVar8->m_Parent;
    if ((cVar1 == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pLVar8 = &Links::lexical_block_0::s_Sentinel;
    if (iVar3 != -1) {
      pLVar8 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
    }
    if (iVar4 == (((Node_t *)pLVar8)->super_Links_t).m_Left) {
      if ((cVar1 == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar7 = (this->m_Elements).m_pMemory;
      pLVar8 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar8 = (Links_t *)((int)&(pNVar7->super_Links_t).m_Left + iVar2);
      }
      pNVar7[pLVar8->m_Parent].super_Links_t.m_Left = local_28;
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    else {
      if ((cVar1 == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel),
         cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      }
      if (iVar4 == -1) {
        local_30 = (this->m_Elements).m_pMemory;
        pLVar8 = &Links::lexical_block_0::s_Sentinel;
      }
      else {
        local_30 = (this->m_Elements).m_pMemory;
        pLVar8 = (Links_t *)((int)&(local_30->super_Links_t).m_Left + iVar2);
      }
      local_30[pLVar8->m_Parent].super_Links_t.m_Right = local_28;
    }
  }
  if ((cVar1 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar3 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  iVar3 = Links::lexical_block_0::s_Sentinel.m_Tag;
  if ((iVar4 != -1) &&
     (iVar3 = *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + iVar2),
     iVar4 == elem)) goto LAB_0018155f;
  if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
    iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar6 != 0) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar7 = (this->m_Elements).m_pMemory;
    bVar9 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0';
    *(int *)((int)&(pNVar7->super_Links_t).m_Parent + iVar2) = pNVar7[elem].super_Links_t.m_Parent;
    if (bVar9) goto LAB_00181632;
    iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar6 != 0) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar7 = (this->m_Elements).m_pMemory;
    bVar9 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0';
    *(int *)((int)&(pNVar7->super_Links_t).m_Right + iVar2) = pNVar7[elem].super_Links_t.m_Right;
    if ((bVar9) &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
  }
  else {
    pNVar7 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar7->super_Links_t).m_Parent + iVar2) = pNVar7[elem].super_Links_t.m_Parent;
LAB_00181632:
    pNVar7 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar7->super_Links_t).m_Right + iVar2) = pNVar7[elem].super_Links_t.m_Right;
  }
  pNVar7 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar7->super_Links_t).m_Left + iVar2) = pNVar7[elem].super_Links_t.m_Left;
  if (elem == this->m_Root) {
    this->m_Root = iVar4;
    cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  }
  else {
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar6 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      iVar6 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar5 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
    }
    else {
      iVar6 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
    }
    pLVar8 = &Links::lexical_block_0::s_Sentinel;
    if (iVar6 != -1) {
      pLVar8 = &(this->m_Elements).m_pMemory[iVar6].super_Links_t;
    }
    if (elem == (((Node_t *)pLVar8)->super_Links_t).m_Left) {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar7 = (this->m_Elements).m_pMemory;
      pNVar7[pNVar7[elem].super_Links_t.m_Parent].super_Links_t.m_Left = iVar4;
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    else {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      pNVar7 = (this->m_Elements).m_pMemory;
      *(int *)((int)pNVar7 +
              pNVar7[elem].super_Links_t.m_Parent * 0x20 + pNVar7[elem].super_Links_t.m_Parent * -4
              + 4) = iVar4;
    }
  }
  if ((cVar1 == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  }
  pLVar8 = &Links::lexical_block_0::s_Sentinel;
  if (iVar4 != -1) {
    pLVar8 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2);
  }
  if (pLVar8->m_Left != -1) {
    if ((cVar1 == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pNVar7 = (this->m_Elements).m_pMemory;
    pLVar8 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar8 = (Links_t *)((int)&(pNVar7->super_Links_t).m_Left + iVar2);
    }
    pNVar7[pLVar8->m_Left].super_Links_t.m_Parent = iVar4;
  }
  if ((cVar1 == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  }
  pLVar8 = &Links::lexical_block_0::s_Sentinel;
  if (iVar4 != -1) {
    pLVar8 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2);
  }
  if (pLVar8->m_Right != -1) {
    if ((cVar1 == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pNVar7 = (this->m_Elements).m_pMemory;
    pLVar8 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar8 = (Links_t *)((int)&(pNVar7->super_Links_t).m_Left + iVar2);
    }
    pNVar7[pLVar8->m_Right].super_Links_t.m_Parent = iVar4;
  }
  if ((cVar1 == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  pNVar7 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar7->super_Links_t).m_Tag + iVar2) = pNVar7[elem].super_Links_t.m_Tag;
LAB_0018155f:
  if ((local_28 != -1) && (iVar3 == 1)) {
    RemoveRebalance(this,local_28);
  }
  (this->m_Elements).m_pMemory[elem].super_Links_t.m_Left = elem;
  (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right = this->m_FirstFree;
  this->m_NumElements = this->m_NumElements + -1;
  this->m_FirstFree = elem;
  return;
}


