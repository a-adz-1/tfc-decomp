// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RotateRight  @ 00123270
/* DWARF original prototype: void RotateRight(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, int
   elem) */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::RotateRight
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  int local_24;
  
                    /* Unresolved local var: int leftchild@[???] */
  if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    if (elem != -1) goto LAB_00123297;
    pLVar1 = &Links::s_Sentinel;
    local_24 = -0x1c;
LAB_001232ae:
    iVar2 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar6 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
  }
  else {
    if (elem != -1) {
LAB_00123297:
      local_24 = elem * 0x1c;
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      goto LAB_001232ae;
    }
    local_24 = -0x1c;
    iVar2 = Links::s_Sentinel.m_Left;
  }
  pNVar5 = (this->m_Elements).m_pMemory;
  if (iVar2 == -1) {
    *(int *)((int)&(pNVar5->super_Links_t).m_Left + local_24) = Links::s_Sentinel.m_Right;
    iVar6 = -0x1c;
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar3 != 0)) {
LAB_001235e0:
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar2 != -1) goto LAB_00123568;
    }
    if (Links::s_Sentinel.m_Right != -1) {
LAB_001233fb:
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
LAB_00123443:
      if (iVar2 != -1) {
        pNVar5[*(int *)((int)&(pNVar5->super_Links_t).m_Right + iVar6)].super_Links_t.m_Parent =
             elem;
        goto LAB_00123467;
      }
      pNVar5[Links::s_Sentinel.m_Right].super_Links_t.m_Parent = elem;
    }
  }
  else {
    iVar6 = iVar2 * 0x1c;
    *(int *)((int)&(pNVar5->super_Links_t).m_Left + local_24) = pNVar5[iVar2].super_Links_t.m_Right;
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar3 != 0) goto LAB_001235e0;
LAB_00123568:
      if (*(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar6) != -1)
      goto LAB_001233fb;
LAB_00123467:
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
      if (pNVar5[iVar2].super_Links_t.m_Right != -1) goto LAB_00123443;
    }
    pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_24);
    if (elem == -1) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + iVar6) = pLVar1->m_Parent;
  }
  if (elem == this->m_Root) {
    this->m_Root = iVar2;
    goto LAB_00123396;
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
    if (elem != -1) goto LAB_00123331;
LAB_0012333a:
    iVar3 = pLVar1->m_Parent;
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_00123345;
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar4 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      goto LAB_00123345;
    }
    if (iVar3 != -1) goto LAB_0012334e;
LAB_001236dc:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    iVar3 = Links::s_Sentinel.m_Parent;
    if (elem != -1) {
LAB_00123331:
      pLVar1 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_24);
      goto LAB_0012333a;
    }
LAB_00123345:
    if (iVar3 == -1) goto LAB_001236dc;
LAB_0012334e:
    pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
  }
  if (elem == (((Node_t *)pLVar1)->super_Links_t).m_Right) {
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
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Left = iVar2;
  }
LAB_00123396:
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar6) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + local_24) = iVar2;
  }
  return;
}


