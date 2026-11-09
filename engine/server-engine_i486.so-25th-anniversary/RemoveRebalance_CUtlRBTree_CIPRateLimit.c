// CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveRebalance  @ 000b69c0
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
      if (elem != -1) goto LAB_000b69fa;
LAB_000b7110:
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      if (elem == -1) goto LAB_000b7110;
LAB_000b69fa:
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
      if (elem != -1) goto LAB_000b6a50;
LAB_000b6a63:
      iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_000b6a6e;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      if (iVar5 != -1) goto LAB_000b6a77;
LAB_000b6c54:
      if (elem != Links::s_Sentinel.m_Left) goto LAB_000b6a92;
LAB_000b6c70:
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
        if (iVar5 != -1) goto LAB_000b6c81;
        iVar4 = Links::s_Sentinel.m_Right;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_000b6c9f;
LAB_000b7350:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 == 0) goto LAB_000b6c9f;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar4 != -1) goto LAB_000b6ca8;
LAB_000b73a0:
        if (Links::s_Sentinel.m_Tag != 0) goto LAB_000b6cc6;
LAB_000b73b0:
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
          if (elem != -1) goto LAB_000b7406;
LAB_000b7419:
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
          goto LAB_000b7424;
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          if (iVar5 != -1) goto LAB_000b742d;
LAB_000b7724:
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          iVar5 = Links::s_Sentinel.m_Parent;
          if (elem != -1) {
LAB_000b7406:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_000b7419;
          }
LAB_000b7424:
          if (iVar5 == -1) goto LAB_000b7724;
LAB_000b742d:
          pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_000b6cd5;
LAB_000b744b:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar4 != -1) goto LAB_000b6cde;
        iVar3 = Links::s_Sentinel.m_Left;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_000b7480;
LAB_000b6cfb:
        if (iVar3 != -1) goto LAB_000b6d04;
LAB_000b74ac:
        if (Links::s_Sentinel.m_Tag != 1) goto LAB_000b6d1f;
LAB_000b74bb:
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
          if (iVar4 != -1) goto LAB_000b74cc;
LAB_000b74df:
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
LAB_000b74cc:
            pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
            goto LAB_000b74df;
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
          goto LAB_000b6d27;
LAB_000b7520:
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          if (iVar4 != -1) goto LAB_000b6d30;
          local_24 = -0x1c;
          pLVar6 = &Links::s_Sentinel;
          goto LAB_000b6d47;
        }
LAB_000b7150:
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
LAB_000b6c81:
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Right;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
          goto LAB_000b7350;
        }
LAB_000b6c9f:
        if (iVar4 == -1) goto LAB_000b73a0;
LAB_000b6ca8:
        if ((this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag == 0) goto LAB_000b73b0;
LAB_000b6cc6:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_000b744b;
LAB_000b6cd5:
        iVar3 = Links::s_Sentinel.m_Left;
        if (iVar4 == -1) goto LAB_000b6cfb;
LAB_000b6cde:
        iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Left;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_000b6cfb;
LAB_000b7480:
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar2 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          goto LAB_000b6cfb;
        }
        if (iVar3 == -1) goto LAB_000b74ac;
LAB_000b6d04:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_000b74bb;
LAB_000b6d1f:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_000b7520;
LAB_000b6d27:
        if (iVar4 == -1) {
          local_24 = -0x1c;
          iVar3 = Links::s_Sentinel.m_Right;
LAB_000b6d52:
          if (iVar3 == -1) goto LAB_000b775c;
LAB_000b6d5b:
          if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_000b7770;
LAB_000b6d76:
          local_20 = iVar5 * 0x1c;
        }
        else {
LAB_000b6d30:
          local_24 = iVar4 * 0x1c;
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
LAB_000b6d47:
          iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
          goto LAB_000b6d52;
          iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar2 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            goto LAB_000b6d52;
          }
          if (iVar3 != -1) goto LAB_000b6d5b;
LAB_000b775c:
          if (Links::s_Sentinel.m_Tag != 1) goto LAB_000b6d76;
LAB_000b7770:
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
            if (elem != -1) goto LAB_000b77d3;
LAB_000b77e4:
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
LAB_000b77d3:
              pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
              goto LAB_000b77e4;
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
LAB_000b6a50:
        pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_000b6a63;
      }
LAB_000b6a6e:
      if (iVar5 == -1) goto LAB_000b6c54;
LAB_000b6a77:
      if (elem == (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left) goto LAB_000b6c70;
LAB_000b6a92:
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
        if (iVar5 != -1) goto LAB_000b6aa3;
        iVar4 = Links::s_Sentinel.m_Left;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_000b6ac0;
LAB_000b7060:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar3 == 0) goto LAB_000b6ac0;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar4 != -1) goto LAB_000b6ac9;
LAB_000b70b0:
        pLVar6 = &Links::s_Sentinel;
      }
      else {
        iVar4 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
LAB_000b6aa3:
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left;
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
          goto LAB_000b7060;
        }
LAB_000b6ac0:
        if (iVar4 == -1) goto LAB_000b70b0;
LAB_000b6ac9:
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
          if (elem != -1) goto LAB_000b6fd6;
LAB_000b6fe9:
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
LAB_000b6fd6:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_000b6fe9;
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
        if (iVar4 != -1) goto LAB_000b6aff;
LAB_000b6b12:
        iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_000b6b1d;
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar2 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          goto LAB_000b6b1d;
        }
        if (iVar3 != -1) goto LAB_000b6b26;
LAB_000b6e6c:
        if (Links::s_Sentinel.m_Tag != 1) goto LAB_000b6b41;
LAB_000b6e80:
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
          if (iVar4 != -1) goto LAB_000b6e91;
LAB_000b6ea4:
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
LAB_000b6e91:
            pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
            goto LAB_000b6ea4;
          }
        }
        if (iVar3 == -1) {
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 1) goto LAB_000b7150;
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0')
        goto LAB_000b6b49;
LAB_000b6ef0:
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
LAB_000b6b52:
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
        if (iVar3 != -1) goto LAB_000b6b7c;
LAB_000b71a8:
        if (Links::s_Sentinel.m_Tag != 1) goto LAB_000b6b97;
LAB_000b71c0:
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
          if (elem != -1) goto LAB_000b7224;
LAB_000b7235:
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
LAB_000b7224:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_000b7235;
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
LAB_000b6aff:
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
          goto LAB_000b6b12;
        }
LAB_000b6b1d:
        if (iVar3 == -1) goto LAB_000b6e6c;
LAB_000b6b26:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_000b6e80;
LAB_000b6b41:
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0')
        goto LAB_000b6ef0;
LAB_000b6b49:
        if (iVar4 != -1) goto LAB_000b6b52;
        local_24 = -0x1c;
        iVar3 = Links::s_Sentinel.m_Left;
        if (Links::s_Sentinel.m_Left == -1) goto LAB_000b71a8;
LAB_000b6b7c:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag == 1) goto LAB_000b71c0;
LAB_000b6b97:
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


