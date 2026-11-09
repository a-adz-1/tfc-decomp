// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RotateLeft  @ 00122cb0
/* DWARF original prototype: void RotateLeft(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, int
   elem) */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::RotateLeft
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  bool bVar7;
  int local_24;
  char local_20;
  
                    /* Unresolved local var: int rightchild@[???] */
  local_20 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    local_20 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    if (elem != -1) goto LAB_00122cdb;
    pLVar1 = &Links::s_Sentinel;
    local_24 = -0x1c;
LAB_00122cf2:
    iVar2 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    if (local_20 != '\0') goto LAB_00122d00;
    CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel = local_20;
    iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar6 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    local_20 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    if (iVar2 == -1) goto LAB_00122df0;
    pNVar5 = (this->m_Elements).m_pMemory;
    iVar6 = iVar2 * 0x1c;
    bVar7 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0';
    *(int *)((int)&(pNVar5->super_Links_t).m_Right + local_24) = pNVar5[iVar2].super_Links_t.m_Left;
    if (bVar7) goto LAB_00122d25;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar3 != 0) goto LAB_00123154;
LAB_00122f73:
    if (*(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6) != -1) {
LAB_00122e25:
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
LAB_00122e73:
      if (iVar2 == -1) {
        pNVar5[Links::s_Sentinel.m_Left].super_Links_t.m_Parent = elem;
        goto LAB_00122d4a;
      }
      pNVar5[*(int *)((int)&(pNVar5->super_Links_t).m_Left + iVar6)].super_Links_t.m_Parent = elem;
    }
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
LAB_00122d32:
    pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_24);
    if (elem == -1) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + iVar6) = pLVar1->m_Parent;
  }
  else {
    if (elem != -1) {
LAB_00122cdb:
      local_24 = elem * 0x1c;
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      local_20 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      goto LAB_00122cf2;
    }
    local_24 = -0x1c;
    iVar2 = Links::s_Sentinel.m_Right;
LAB_00122d00:
    if (iVar2 != -1) {
      pNVar5 = (this->m_Elements).m_pMemory;
      iVar6 = iVar2 * 0x1c;
      CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel = local_20;
      *(int *)((int)&(pNVar5->super_Links_t).m_Right + local_24) =
           pNVar5[iVar2].super_Links_t.m_Left;
LAB_00122d25:
      pNVar5 = (this->m_Elements).m_pMemory;
      if (*(int *)((int)&(pNVar5->super_Links_t).m_Left + iVar6) != -1) goto LAB_00122e73;
      goto LAB_00122d32;
    }
LAB_00122df0:
    iVar6 = -0x1c;
    CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel = local_20;
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + local_24) =
         Links::s_Sentinel.m_Left;
    if ((local_20 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
LAB_00123154:
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar2 != -1) goto LAB_00122f73;
    }
    if (Links::s_Sentinel.m_Left != -1) goto LAB_00122e25;
  }
LAB_00122d4a:
  if (elem == this->m_Root) {
    this->m_Root = iVar2;
    goto LAB_00122dce;
  }
  if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) goto LAB_00122d6b;
LAB_00122d74:
    iVar3 = pLVar1->m_Parent;
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_00122d7f;
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar4 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      goto LAB_00122d7f;
    }
    if (iVar3 != -1) goto LAB_00122d88;
LAB_001230dc:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    iVar3 = Links::s_Sentinel.m_Parent;
    if (elem != -1) {
LAB_00122d6b:
      pLVar1 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_24);
      goto LAB_00122d74;
    }
LAB_00122d7f:
    if (iVar3 == -1) goto LAB_001230dc;
LAB_00122d88:
    pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
  }
  if (elem == (((Node_t *)pLVar1)->super_Links_t).m_Left) {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) {
      pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_24);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Left = iVar2;
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
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) {
      pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_24);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Right = iVar2;
  }
LAB_00122dce:
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + local_24) = iVar2;
  }
  return;
}


