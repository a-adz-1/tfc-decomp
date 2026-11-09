// CUtlRBTree<CIPRateLimit::iprate_s,_int>::InsertRebalance  @ 00125b90
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
  int iVar6;
  Links_t *pLVar7;
  
  do {
    iVar1 = this->m_Root;
    if (elem == iVar1) {
LAB_00125c01:
      (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar1 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar1 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar7 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_00125bbf;
LAB_00125bd2:
      iVar1 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 == 0)) goto LAB_00125bdd;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar1 == -1) goto LAB_00125f90;
LAB_00125be6:
      pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    else {
      iVar1 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_00125bbf:
        pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_00125bd2;
      }
LAB_00125bdd:
      if (iVar1 != -1) goto LAB_00125be6;
LAB_00125f90:
      pLVar7 = &Links::s_Sentinel;
    }
    if ((((Node_t *)pLVar7)->super_Links_t).m_Tag != 0) {
      iVar1 = this->m_Root;
      goto LAB_00125c01;
    }
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int grandparent@[???] */
    if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
      iVar1 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar1 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar7 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_00125c40;
LAB_00125c53:
      iVar1 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
    }
    else {
      iVar1 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_00125c40:
        pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_00125c53;
      }
    }
    if (iVar1 == -1) {
      iVar6 = Links::s_Sentinel.m_Parent;
      iVar5 = Links::s_Sentinel.m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') goto LAB_00125eb0;
LAB_00125ca5:
      if (iVar6 != -1) goto LAB_00125cae;
LAB_00125e8c:
      pLVar7 = &Links::s_Sentinel;
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      iVar5 = pNVar3[iVar1].super_Links_t.m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
LAB_00125eb0:
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (iVar1 != -1) {
          pNVar3 = (this->m_Elements).m_pMemory;
          goto LAB_00125c84;
        }
      }
      else {
LAB_00125c84:
        pLVar7 = &pNVar3[iVar1].super_Links_t;
      }
      iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_00125ca5;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        goto LAB_00125ca5;
      }
      if (iVar6 == -1) goto LAB_00125e8c;
LAB_00125cae:
      pLVar7 = &(this->m_Elements).m_pMemory[iVar6].super_Links_t;
    }
    if (iVar1 == (((Node_t *)pLVar7)->super_Links_t).m_Left) {
                    /* Unresolved local var: int uncle@[???] */
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (iVar5 != -1) goto LAB_00125cd8;
LAB_00125ceb:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Right;
        iVar4 = Links::s_Sentinel.m_Parent;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 = Links::s_Sentinel.m_Parent, iVar2 != 0
           )) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          iVar4 = Links::s_Sentinel.m_Parent;
        }
      }
      else {
        iVar6 = Links::s_Sentinel.m_Right;
        iVar4 = Links::s_Sentinel.m_Parent;
        if (iVar5 != -1) {
LAB_00125cd8:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          goto LAB_00125ceb;
        }
      }
      iVar2 = Links::s_Sentinel.m_Tag;
      if (iVar6 != -1) {
        iVar2 = (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Tag;
      }
      Links::s_Sentinel.m_Parent = iVar4;
      if (iVar2 == 0) {
LAB_00125d1d:
                    /* Unresolved local var: int uncle@[???] */
        (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        elem = iVar5;
      }
      else {
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar6 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar7 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_00126058;
LAB_0012606b:
          iVar4 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 == 0)) goto LAB_00126076;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          if (iVar4 == -1) goto LAB_00126520;
LAB_0012607f:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        else {
          if (elem != -1) {
LAB_00126058:
            pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_0012606b;
          }
LAB_00126076:
          if (iVar4 != -1) goto LAB_0012607f;
LAB_00126520:
          pLVar7 = &Links::s_Sentinel;
        }
        if (elem == (((Node_t *)pLVar7)->super_Links_t).m_Right) {
          RotateLeft(this,iVar1);
          if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
            iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel);
            if (iVar6 != 0) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar7 = &Links::s_Sentinel;
            if (iVar1 != -1) goto LAB_00126364;
LAB_00126377:
            iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar5 != 0)) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
          }
          else {
            iVar6 = Links::s_Sentinel.m_Parent;
            if (iVar1 != -1) {
LAB_00126364:
              pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
              goto LAB_00126377;
            }
          }
          if (iVar6 == -1) {
            pLVar7 = &Links::s_Sentinel;
            pNVar3 = (this->m_Elements).m_pMemory + -1;
          }
          else {
            pNVar3 = (this->m_Elements).m_pMemory + iVar6;
            pLVar7 = &pNVar3->super_Links_t;
          }
          iVar5 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
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
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (iVar5 != -1) goto LAB_00125d81;
LAB_00125d94:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Left;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 == 0)) goto LAB_00125d9e;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar6 == -1) goto LAB_00126170;
LAB_00125da7:
        pLVar7 = &(this->m_Elements).m_pMemory[iVar6].super_Links_t;
      }
      else {
        iVar6 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
LAB_00125d81:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          goto LAB_00125d94;
        }
LAB_00125d9e:
        if (iVar6 != -1) goto LAB_00125da7;
LAB_00126170:
        pLVar7 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar7)->super_Links_t).m_Tag == 0) goto LAB_00125d1d;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (elem != -1) goto LAB_00125ddd;
LAB_00125df0:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 == 0)) goto LAB_00125dfb;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar6 == -1) goto LAB_00126410;
LAB_00125e04:
        if (elem != (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Left) goto LAB_00125e1d;
LAB_00126420:
        RotateRight(this,iVar1);
        if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
          iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel);
          if (iVar6 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar7 = &Links::s_Sentinel;
          if (iVar1 != -1) goto LAB_00126444;
LAB_00126457:
          iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar5 != 0)) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar6 = Links::s_Sentinel.m_Parent;
          if (iVar1 != -1) {
LAB_00126444:
            pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
            goto LAB_00126457;
          }
        }
        if (iVar6 == -1) {
          pLVar7 = &Links::s_Sentinel;
          pNVar3 = (this->m_Elements).m_pMemory + -1;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + iVar6;
          pLVar7 = &pNVar3->super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      }
      else {
        iVar6 = Links::s_Sentinel.m_Parent;
        if (elem != -1) {
LAB_00125ddd:
          pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
          goto LAB_00125df0;
        }
LAB_00125dfb:
        if (iVar6 != -1) goto LAB_00125e04;
LAB_00126410:
        if (elem == Links::s_Sentinel.m_Left) goto LAB_00126420;
LAB_00125e1d:
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


