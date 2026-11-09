// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RotateLeft  @ 000b5e80
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
    if (elem != -1) goto LAB_000b5eab;
    pLVar1 = &Links::s_Sentinel;
    local_24 = -0x1c;
LAB_000b5ec2:
    iVar2 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    if (local_20 != '\0') goto LAB_000b5ed0;
    CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel = local_20;
    iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar6 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    local_20 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    if (iVar2 == -1) goto LAB_000b5fc0;
    pNVar5 = (this->m_Elements).m_pMemory;
    iVar6 = iVar2 * 0x1c;
    bVar7 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0';
    *(int *)((int)&(pNVar5->super_Links_t).m_Right + local_24) = pNVar5[iVar2].super_Links_t.m_Left;
    if (bVar7) goto LAB_000b5ef5;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar3 != 0) goto LAB_000b6324;
LAB_000b6143:
    if (*(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6) != -1) {
LAB_000b5ff5:
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
LAB_000b6043:
      if (iVar2 == -1) {
        pNVar5[Links::s_Sentinel.m_Left].super_Links_t.m_Parent = elem;
        goto LAB_000b5f1a;
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
LAB_000b5f02:
    pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_24);
    if (elem == -1) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + iVar6) = pLVar1->m_Parent;
  }
  else {
    if (elem != -1) {
LAB_000b5eab:
      local_24 = elem * 0x1c;
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      local_20 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      goto LAB_000b5ec2;
    }
    local_24 = -0x1c;
    iVar2 = Links::s_Sentinel.m_Right;
LAB_000b5ed0:
    if (iVar2 != -1) {
      pNVar5 = (this->m_Elements).m_pMemory;
      iVar6 = iVar2 * 0x1c;
      CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel = local_20;
      *(int *)((int)&(pNVar5->super_Links_t).m_Right + local_24) =
           pNVar5[iVar2].super_Links_t.m_Left;
LAB_000b5ef5:
      pNVar5 = (this->m_Elements).m_pMemory;
      if (*(int *)((int)&(pNVar5->super_Links_t).m_Left + iVar6) != -1) goto LAB_000b6043;
      goto LAB_000b5f02;
    }
LAB_000b5fc0:
    iVar6 = -0x1c;
    CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel = local_20;
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + local_24) =
         Links::s_Sentinel.m_Left;
    if ((local_20 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
LAB_000b6324:
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar2 != -1) goto LAB_000b6143;
    }
    if (Links::s_Sentinel.m_Left != -1) goto LAB_000b5ff5;
  }
LAB_000b5f1a:
  if (elem == this->m_Root) {
    this->m_Root = iVar2;
    goto LAB_000b5f9e;
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
    if (elem != -1) goto LAB_000b5f3b;
LAB_000b5f44:
    iVar3 = pLVar1->m_Parent;
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_000b5f4f;
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar4 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      goto LAB_000b5f4f;
    }
    if (iVar3 != -1) goto LAB_000b5f58;
LAB_000b62ac:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    iVar3 = Links::s_Sentinel.m_Parent;
    if (elem != -1) {
LAB_000b5f3b:
      pLVar1 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_24);
      goto LAB_000b5f44;
    }
LAB_000b5f4f:
    if (iVar3 == -1) goto LAB_000b62ac;
LAB_000b5f58:
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
LAB_000b5f9e:
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + local_24) = iVar2;
  }
  return;
}


