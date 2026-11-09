// CUtlRBTree<CIPRateLimit::iprate_s,_int>::InsertRebalance  @ 000b8d60
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
LAB_000b8dd1:
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
      if (elem != -1) goto LAB_000b8d8f;
LAB_000b8da2:
      iVar1 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 == 0)) goto LAB_000b8dad;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar1 == -1) goto LAB_000b9160;
LAB_000b8db6:
      pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    else {
      iVar1 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_000b8d8f:
        pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_000b8da2;
      }
LAB_000b8dad:
      if (iVar1 != -1) goto LAB_000b8db6;
LAB_000b9160:
      pLVar7 = &Links::s_Sentinel;
    }
    if ((((Node_t *)pLVar7)->super_Links_t).m_Tag != 0) {
      iVar1 = this->m_Root;
      goto LAB_000b8dd1;
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
      if (elem != -1) goto LAB_000b8e10;
LAB_000b8e23:
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
LAB_000b8e10:
        pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_000b8e23;
      }
    }
    if (iVar1 == -1) {
      iVar6 = Links::s_Sentinel.m_Parent;
      iVar5 = Links::s_Sentinel.m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') goto LAB_000b9080;
LAB_000b8e75:
      if (iVar6 != -1) goto LAB_000b8e7e;
LAB_000b905c:
      pLVar7 = &Links::s_Sentinel;
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      iVar5 = pNVar3[iVar1].super_Links_t.m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
LAB_000b9080:
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
          goto LAB_000b8e54;
        }
      }
      else {
LAB_000b8e54:
        pLVar7 = &pNVar3[iVar1].super_Links_t;
      }
      iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') goto LAB_000b8e75;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        goto LAB_000b8e75;
      }
      if (iVar6 == -1) goto LAB_000b905c;
LAB_000b8e7e:
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
        if (iVar5 != -1) goto LAB_000b8ea8;
LAB_000b8ebb:
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
LAB_000b8ea8:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          goto LAB_000b8ebb;
        }
      }
      iVar2 = Links::s_Sentinel.m_Tag;
      if (iVar6 != -1) {
        iVar2 = (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Tag;
      }
      Links::s_Sentinel.m_Parent = iVar4;
      if (iVar2 == 0) {
LAB_000b8eed:
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
          if (elem != -1) goto LAB_000b9228;
LAB_000b923b:
          iVar4 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 == 0)) goto LAB_000b9246;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          if (iVar4 == -1) goto LAB_000b96f0;
LAB_000b924f:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        else {
          if (elem != -1) {
LAB_000b9228:
            pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_000b923b;
          }
LAB_000b9246:
          if (iVar4 != -1) goto LAB_000b924f;
LAB_000b96f0:
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
            if (iVar1 != -1) goto LAB_000b9534;
LAB_000b9547:
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
LAB_000b9534:
              pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
              goto LAB_000b9547;
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
        if (iVar5 != -1) goto LAB_000b8f51;
LAB_000b8f64:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Left;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 == 0)) goto LAB_000b8f6e;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar6 == -1) goto LAB_000b9340;
LAB_000b8f77:
        pLVar7 = &(this->m_Elements).m_pMemory[iVar6].super_Links_t;
      }
      else {
        iVar6 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
LAB_000b8f51:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          goto LAB_000b8f64;
        }
LAB_000b8f6e:
        if (iVar6 != -1) goto LAB_000b8f77;
LAB_000b9340:
        pLVar7 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar7)->super_Links_t).m_Tag == 0) goto LAB_000b8eed;
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
        if (elem != -1) goto LAB_000b8fad;
LAB_000b8fc0:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar4 == 0)) goto LAB_000b8fcb;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        if (iVar6 == -1) goto LAB_000b95e0;
LAB_000b8fd4:
        if (elem != (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Left) goto LAB_000b8fed;
LAB_000b95f0:
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
          if (iVar1 != -1) goto LAB_000b9614;
LAB_000b9627:
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
LAB_000b9614:
            pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
            goto LAB_000b9627;
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
LAB_000b8fad:
          pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
          goto LAB_000b8fc0;
        }
LAB_000b8fcb:
        if (iVar6 != -1) goto LAB_000b8fd4;
LAB_000b95e0:
        if (elem == Links::s_Sentinel.m_Left) goto LAB_000b95f0;
LAB_000b8fed:
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


