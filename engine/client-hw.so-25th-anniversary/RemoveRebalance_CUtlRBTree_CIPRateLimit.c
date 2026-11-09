// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveRebalance  @ 001237f0
/* DWARF original prototype: void RemoveRebalance(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this,
   int elem) */

void __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveRebalance
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int elem)

{
  Node_t *pNVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  Links_t *pLVar6;
  bool bVar7;
  int local_24;
  int local_20;
  
  iVar5 = this->m_Root;
  while (elem != iVar5) {
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar5 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (elem != -1) goto LAB_0012382a;
LAB_00123f40:
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      if (elem == -1) goto LAB_00123f40;
LAB_0012382a:
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    iVar5 = elem;
    if ((((Node_t *)pLVar6)->super_Links_t).m_Tag != 1) break;
                    /* Unresolved local var: int parent@[???] */
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar5 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_00123880;
LAB_00123893:
      iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_0012389e;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      if (iVar5 != -1) goto LAB_001238a7;
LAB_00123a84:
      if (elem != Links::s_Sentinel.m_Left) goto LAB_001238c2;
LAB_00123aa0:
                    /* Unresolved local var: int sibling@[???] */
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar5 != -1) goto LAB_00123ab1;
        iVar4 = Links::s_Sentinel.m_Right;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_00123acf;
LAB_00124180:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 == 0) goto LAB_00123acf;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar4 != -1) goto LAB_00123ad8;
LAB_001241d0:
        if (Links::s_Sentinel.m_Tag != 0) goto LAB_00123af6;
LAB_001241e0:
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        RotateLeft(this,iVar5);
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar5 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_00124236;
LAB_00124249:
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
          goto LAB_00124254;
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          if (iVar5 != -1) goto LAB_0012425d;
LAB_00124554:
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          iVar5 = Links::s_Sentinel.m_Parent;
          if (elem != -1) {
LAB_00124236:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_00124249;
          }
LAB_00124254:
          if (iVar5 == -1) goto LAB_00124554;
LAB_0012425d:
          pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_00123b05;
LAB_0012427b:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar4 != -1) goto LAB_00123b0e;
        iVar3 = Links::s_Sentinel.m_Left;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_001242b0;
LAB_00123b2b:
        if (iVar3 != -1) goto LAB_00123b34;
LAB_001242dc:
        if (Links::s_Sentinel.m_Tag != 1) goto LAB_00123b4f;
LAB_001242eb:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (iVar4 != -1) goto LAB_001242fc;
LAB_0012430f:
          iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar2 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar3 = Links::s_Sentinel.m_Right;
          if (iVar4 != -1) {
LAB_001242fc:
            pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
            goto LAB_0012430f;
          }
        }
        if (iVar3 == -1) {
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar6)->super_Links_t).m_Tag != 1) {
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
          goto LAB_00123b57;
LAB_00124350:
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          if (iVar4 != -1) goto LAB_00123b60;
          local_24 = -0x1c;
          pLVar6 = &Links::s_Sentinel;
          goto LAB_00123b77;
        }
LAB_00123f80:
        elem = iVar5;
        if (iVar4 == -1) {
          iVar5 = this->m_Root;
        }
        else {
          (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 0;
          iVar5 = this->m_Root;
        }
      }
      else {
        iVar4 = Links::s_Sentinel.m_Right;
        if (iVar5 != -1) {
LAB_00123ab1:
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Right;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
          goto LAB_00124180;
        }
LAB_00123acf:
        if (iVar4 == -1) goto LAB_001241d0;
LAB_00123ad8:
        if ((this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag == 0) goto LAB_001241e0;
LAB_00123af6:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_0012427b;
LAB_00123b05:
        iVar3 = Links::s_Sentinel.m_Left;
        if (iVar4 == -1) goto LAB_00123b2b;
LAB_00123b0e:
        iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Left;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_00123b2b;
LAB_001242b0:
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar2 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          goto LAB_00123b2b;
        }
        if (iVar3 == -1) goto LAB_001242dc;
LAB_00123b34:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_001242eb;
LAB_00123b4f:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_00124350;
LAB_00123b57:
        if (iVar4 == -1) {
          local_24 = -0x1c;
          iVar3 = Links::s_Sentinel.m_Right;
LAB_00123b82:
          if (iVar3 == -1) goto LAB_0012458c;
LAB_00123b8b:
          if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_001245a0;
LAB_00123ba6:
          local_20 = iVar5 * 0x1c;
        }
        else {
LAB_00123b60:
          local_24 = iVar4 * 0x1c;
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
LAB_00123b77:
          iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
          goto LAB_00123b82;
          iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar2 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            goto LAB_00123b82;
          }
          if (iVar3 != -1) goto LAB_00123b8b;
LAB_0012458c:
          if (Links::s_Sentinel.m_Tag != 1) goto LAB_00123ba6;
LAB_001245a0:
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar5 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pNVar1 = (this->m_Elements).m_pMemory;
          pLVar6 = &Links::s_Sentinel;
          if (iVar4 != -1) {
            pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_24);
          }
          pNVar1[pLVar6->m_Left].super_Links_t.m_Tag = 1;
          *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_24) =
               0;
          RotateRight(this,iVar4);
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
            iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel);
            if (iVar5 != 0) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar6 = &Links::s_Sentinel;
            if (elem != -1) goto LAB_00124603;
LAB_00124614:
            iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar4 != 0)) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
          }
          else {
            iVar5 = Links::s_Sentinel.m_Parent;
            if (elem != -1) {
LAB_00124603:
              pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
              goto LAB_00124614;
            }
          }
          if (iVar5 == -1) {
            local_20 = -0x1c;
            pLVar6 = &Links::s_Sentinel;
          }
          else {
            local_20 = iVar5 * 0x1c;
            pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          }
          iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
          local_24 = iVar4 * 0x1c;
        }
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar3 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar1 = (this->m_Elements).m_pMemory;
        pLVar6 = &Links::s_Sentinel;
        if (iVar5 != -1) {
          pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_20);
        }
        bVar7 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0';
        *(int *)((int)&(pNVar1->super_Links_t).m_Tag + local_24) = pLVar6->m_Tag;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
        if ((bVar7) &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar3 != 0)) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar1 = (this->m_Elements).m_pMemory;
        pLVar6 = &Links::s_Sentinel;
        if (iVar4 != -1) {
          pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_24);
        }
        pNVar1[pLVar6->m_Right].super_Links_t.m_Tag = 1;
        RotateLeft(this,iVar5);
        iVar5 = this->m_Root;
        elem = iVar5;
      }
    }
    else {
      iVar5 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_00123880:
        pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_00123893;
      }
LAB_0012389e:
      if (iVar5 == -1) goto LAB_00123a84;
LAB_001238a7:
      if (elem == (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left) goto LAB_00123aa0;
LAB_001238c2:
                    /* Unresolved local var: int sibling@[???] */
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar5 != -1) goto LAB_001238d3;
        iVar4 = Links::s_Sentinel.m_Left;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_001238f0;
LAB_00123e90:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 == 0) goto LAB_001238f0;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar4 != -1) goto LAB_001238f9;
LAB_00123ee0:
        pLVar6 = &Links::s_Sentinel;
      }
      else {
        iVar4 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
LAB_001238d3:
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
          goto LAB_00123e90;
        }
LAB_001238f0:
        if (iVar4 == -1) goto LAB_00123ee0;
LAB_001238f9:
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 0) {
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        RotateRight(this,iVar5);
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar5 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_00123e06;
LAB_00123e19:
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar4 != 0)) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            Links::s_Sentinel.m_Left = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar5 = Links::s_Sentinel.m_Parent;
          if (elem != -1) {
LAB_00123e06:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_00123e19;
          }
        }
        iVar4 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left;
        }
      }
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::s_Sentinel;
        if (iVar4 != -1) goto LAB_0012392f;
LAB_00123942:
        iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_0012394d;
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar2 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          goto LAB_0012394d;
        }
        if (iVar3 != -1) goto LAB_00123956;
LAB_00123c9c:
        if (Links::s_Sentinel.m_Tag != 1) goto LAB_00123971;
LAB_00123cb0:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (iVar4 != -1) goto LAB_00123cc1;
LAB_00123cd4:
          iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar2 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            Links::s_Sentinel.m_Right = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar3 = Links::s_Sentinel.m_Left;
          if (iVar4 != -1) {
LAB_00123cc1:
            pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
            goto LAB_00123cd4;
          }
        }
        if (iVar3 == -1) {
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 1) goto LAB_00123f80;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_00123979;
LAB_00123d20:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar4 == -1) {
          local_24 = -0x1c;
          pLVar6 = &Links::s_Sentinel;
        }
        else {
LAB_00123982:
          local_24 = iVar4 * 0x1c;
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar3 != -1) goto LAB_001239ac;
LAB_00123fd8:
        if (Links::s_Sentinel.m_Tag != 1) goto LAB_001239c7;
LAB_00123ff0:
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar5 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar1 = (this->m_Elements).m_pMemory;
        pLVar6 = &Links::s_Sentinel;
        if (iVar4 != -1) {
          pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_24);
        }
        pNVar1[pLVar6->m_Right].super_Links_t.m_Tag = 1;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_24) = 0;
        RotateLeft(this,iVar4);
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar5 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_00124054;
LAB_00124065:
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar4 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar5 = Links::s_Sentinel.m_Parent;
          if (elem != -1) {
LAB_00124054:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_00124065;
          }
        }
        if (iVar5 == -1) {
          local_20 = -0x1c;
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          local_20 = iVar5 * 0x1c;
          pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
        local_24 = iVar4 * 0x1c;
      }
      else {
        iVar3 = Links::s_Sentinel.m_Right;
        if (iVar4 != -1) {
LAB_0012392f:
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
          goto LAB_00123942;
        }
LAB_0012394d:
        if (iVar3 == -1) goto LAB_00123c9c;
LAB_00123956:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_00123cb0;
LAB_00123971:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_00123d20;
LAB_00123979:
        if (iVar4 != -1) goto LAB_00123982;
        local_24 = -0x1c;
        iVar3 = Links::s_Sentinel.m_Left;
        if (Links::s_Sentinel.m_Left == -1) goto LAB_00123fd8;
LAB_001239ac:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_00123ff0;
LAB_001239c7:
        local_20 = iVar5 * 0x1c;
      }
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::s_Sentinel;
      if (iVar5 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_20);
      }
      bVar7 = CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar1->super_Links_t).m_Tag + local_24) = pLVar6->m_Tag;
      *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
      if ((bVar7) &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_24);
      }
      pNVar1[pLVar6->m_Left].super_Links_t.m_Tag = 1;
      RotateRight(this,iVar5);
      iVar5 = this->m_Root;
      elem = iVar5;
    }
  }
  (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 1;
  return;
}


