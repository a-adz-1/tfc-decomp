// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveAt  @ 00124d80
/* DWARF original prototype: void RemoveAt(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, int elem)
    */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveAt
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  Node_t *pNVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  Links_t *pLVar6;
  bool bVar7;
  int local_2c;
  int local_28;
  int local_24;
  
  if (elem == -1) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: NodeColor_t ycolor@[???] */
  iVar3 = elem;
  if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    local_2c = elem * 0x1c;
    pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    if ((((Node_t *)pLVar6)->super_Links_t).m_Left != -1) {
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_001250c8;
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar2 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      iVar2 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
      if (iVar2 != -1) {
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          iVar2 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right;
        }
        goto LAB_001250d4;
      }
    }
    cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_00124dd1;
LAB_00125310:
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
joined_r0x0012532e:
    if (iVar3 == -1) {
      pLVar6 = &Links::s_Sentinel;
      goto LAB_00124dd1;
    }
    if (*(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_2c) != -1)
    goto LAB_00124dda;
LAB_00125183:
    if ((cVar5 == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    if (iVar3 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_2c);
    }
    local_28 = pLVar6->m_Right;
  }
  else {
    local_2c = elem * 0x1c;
    pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    if ((((Node_t *)pLVar6)->super_Links_t).m_Left != -1) {
LAB_001250c8:
      local_2c = elem * 0x1c;
      iVar2 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      if (iVar2 != -1) {
LAB_001250d4:
        cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_00125125;
LAB_001250e0:
        if (iVar2 == -1) goto LAB_00125145;
        while (iVar3 = iVar2, (this->m_Elements).m_pMemory[iVar2].super_Links_t.m_Left != -1) {
          while( true ) {
            if ((cVar5 == '\0') &&
               (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel),
               cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0))
            {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
              cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
            }
            iVar2 = Links::s_Sentinel.m_Left;
            if (iVar3 != -1) {
              iVar2 = (this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Left;
            }
            if (cVar5 != '\0') goto LAB_001250e0;
LAB_00125125:
            iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel);
            if (iVar3 != 0) {
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
            if (iVar2 != -1) break;
LAB_00125145:
            iVar3 = iVar2;
            if (Links::s_Sentinel.m_Left == -1) goto LAB_00125150;
          }
        }
LAB_00125150:
        iVar3 = iVar2;
        if (cVar5 == '\0') {
          local_2c = iVar2 * 0x1c;
          goto LAB_00125310;
        }
        local_2c = iVar2 * 0x1c;
        goto joined_r0x0012532e;
      }
    }
LAB_00124dd1:
    if ((((Node_t *)pLVar6)->super_Links_t).m_Left == -1) goto LAB_00125183;
LAB_00124dda:
    if ((cVar5 == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    if (iVar3 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_2c);
    }
    local_28 = pLVar6->m_Left;
  }
  if (local_28 != -1) {
    if ((cVar5 == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar6 = &Links::s_Sentinel;
    if (iVar3 != -1) {
      pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_2c);
    }
    pNVar1[local_28].super_Links_t.m_Parent = pLVar6->m_Parent;
  }
  if (iVar3 == this->m_Root) {
    this->m_Root = local_28;
  }
  else {
    if (cVar5 == '\0') {
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar2 != 0) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::s_Sentinel;
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      if (iVar3 != -1) goto LAB_00124e4e;
LAB_00124e53:
      iVar2 = pLVar6->m_Parent;
      if ((cVar5 == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel),
         cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar4 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        Links::s_Sentinel.m_Right = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      }
    }
    else {
      iVar2 = Links::s_Sentinel.m_Parent;
      if (iVar3 != -1) {
LAB_00124e4e:
        pLVar6 = (Links_t *)
                 ((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_2c);
        goto LAB_00124e53;
      }
    }
    if (iVar2 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar2].super_Links_t;
    }
    if (iVar3 == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
      if ((cVar5 == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::s_Sentinel;
      if (iVar3 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_2c);
      }
      pNVar1[pLVar6->m_Parent].super_Links_t.m_Left = local_28;
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    else {
      if ((cVar5 == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel),
         cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::s_Sentinel;
      if (iVar3 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_2c);
      }
      pNVar1[pLVar6->m_Parent].super_Links_t.m_Right = local_28;
    }
  }
  if ((cVar5 == '\0') &&
     (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar2 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  if (iVar3 == -1) {
    local_24 = Links::s_Sentinel.m_Tag;
  }
  else {
    local_24 = *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_2c);
    if (elem == iVar3) goto LAB_00124f21;
  }
  if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    bVar7 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0';
    *(int *)((int)&(pNVar1->super_Links_t).m_Parent + local_2c) =
         pNVar1[elem].super_Links_t.m_Parent;
    if (bVar7) {
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar2 != 0) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      bVar7 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar1->super_Links_t).m_Right + local_2c) =
           pNVar1[elem].super_Links_t.m_Right;
      if ((bVar7) &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
    }
    else {
      pNVar1 = (this->m_Elements).m_pMemory;
      *(int *)((int)&(pNVar1->super_Links_t).m_Right + local_2c) =
           pNVar1[elem].super_Links_t.m_Right;
    }
  }
  else {
    pNVar1 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar1->super_Links_t).m_Parent + local_2c) =
         pNVar1[elem].super_Links_t.m_Parent;
    pNVar1 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar1->super_Links_t).m_Right + local_2c) = pNVar1[elem].super_Links_t.m_Right;
  }
  pNVar1 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar1->super_Links_t).m_Left + local_2c) = pNVar1[elem].super_Links_t.m_Left;
  if (elem == this->m_Root) {
    this->m_Root = iVar3;
    cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  }
  else {
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar2 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      iVar2 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar4 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
    }
    else {
      iVar2 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
    }
    if (iVar2 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar2].super_Links_t;
    }
    if (elem == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pNVar1[pNVar1[elem].super_Links_t.m_Parent].super_Links_t.m_Left = iVar3;
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
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
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
      pNVar1 = (this->m_Elements).m_pMemory;
      pNVar1[pNVar1[elem].super_Links_t.m_Parent].super_Links_t.m_Right = iVar3;
    }
  }
  if ((cVar5 == '\0') &&
     (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  }
  if (iVar3 == -1) {
    pLVar6 = &Links::s_Sentinel;
  }
  else {
    pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_2c);
  }
  if (pLVar6->m_Left != -1) {
    if ((cVar5 == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar6 = &Links::s_Sentinel;
    if (iVar3 != -1) {
      pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_2c);
    }
    pNVar1[pLVar6->m_Left].super_Links_t.m_Parent = iVar3;
  }
  if ((cVar5 == '\0') &&
     (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
  }
  if (iVar3 == -1) {
    pLVar6 = &Links::s_Sentinel;
  }
  else {
    pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_2c);
  }
  if (pLVar6->m_Right != -1) {
    if ((cVar5 == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel, iVar2 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      cVar5 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel;
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar6 = &Links::s_Sentinel;
    if (iVar3 != -1) {
      pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_2c);
    }
    pNVar1[pLVar6->m_Right].super_Links_t.m_Parent = iVar3;
  }
  if ((cVar5 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar3 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  pNVar1 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar1->super_Links_t).m_Tag + local_2c) = pNVar1[elem].super_Links_t.m_Tag;
LAB_00124f21:
  if ((local_24 == 1) && (local_28 != -1)) {
    RemoveRebalance(this,local_28);
  }
  (this->m_Elements).m_pMemory[elem].super_Links_t.m_Left = elem;
  (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right = this->m_FirstFree;
  this->m_NumElements = this->m_NumElements + -1;
  this->m_FirstFree = elem;
  return;
}


