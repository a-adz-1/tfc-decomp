// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>::Insert  @ 00129cd0
/* DWARF original prototype: int
   Insert(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
   * this, ulonglong * insert, bool bInsertDuplicates) */

int __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
::Insert(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
         *this,ulonglong *insert,bool bInsertDuplicates)

{
  undefined4 uVar1;
  bool bVar2;
  Node_t *pNVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  int local_24;
  
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: bool leftchild@[???]
                       Unresolved local var: bool isDuplicate@[???] */
                    /* Unresolved local var: int current@[???] */
  iVar6 = this->m_Root;
  if (iVar6 == -1) {
    bVar2 = false;
  }
  else {
    pNVar3 = (this->m_Elements).m_pMemory;
    iVar4 = iVar6;
    do {
      iVar6 = iVar4;
      bVar2 = (*this->m_LessFunc)(insert,&pNVar3[iVar6].m_Data);
      if (bVar2) {
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar3 = (this->m_Elements).m_pMemory;
        bVar2 = true;
        iVar4 = pNVar3[iVar6].super_Links_t.m_Left;
      }
      else {
        if ((!bInsertDuplicates) &&
           (bVar2 = (*this->m_LessFunc)(&(this->m_Elements).m_pMemory[iVar6].m_Data,insert), !bVar2)
           ) {
          pNVar3 = (this->m_Elements).m_pMemory;
          uVar1 = *(undefined4 *)((int)insert + 4);
          *(int *)&pNVar3[iVar6].m_Data = (int)*insert;
          *(undefined4 *)((int)&pNVar3[iVar6].m_Data + 4) = uVar1;
          return iVar6;
        }
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar3 = (this->m_Elements).m_pMemory;
        bVar2 = false;
        iVar4 = pNVar3[iVar6].super_Links_t.m_Right;
      }
    } while (iVar4 != -1);
  }
                    /* Unresolved local var: int newNode@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int newElem@[???] */
  local_24 = this->m_FirstFree;
  if (local_24 == -1) {
    local_24 = (this->m_Elements).m_NumAllocated;
    if (local_24 == this->m_TotalElements) {
      iVar4 = (this->m_Elements).m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((iVar4 == 0) && (iVar4 = 1, local_24 != 0)) {
        iVar4 = local_24;
      }
                    /* Unresolved local var: int growSize@[???] */
      pNVar3 = (this->m_Elements).m_pMemory;
      iVar4 = iVar4 + local_24;
      (this->m_Elements).m_NumAllocated = iVar4;
      if (pNVar3 == (Node_t *)0x0) {
        pNVar5 = malloc(iVar4 * 0x18);
        (this->m_Elements).m_pMemory = pNVar5;
      }
      else {
        pNVar5 = realloc(pNVar3,iVar4 * 0x18);
        (this->m_Elements).m_pMemory = pNVar5;
        local_24 = this->m_TotalElements;
      }
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
      local_24 = this->m_TotalElements;
    }
    this->m_TotalElements = local_24 + 1;
    pNVar3 = pNVar5 + local_24;
  }
  else {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pNVar3 = pNVar5 + local_24;
    this->m_FirstFree = (pNVar3->super_Links_t).m_Right;
  }
                    /* Unresolved local var: Links_t * elem@[???] */
  this->m_pElements = pNVar5;
  (pNVar3->super_Links_t).m_Parent = iVar6;
  (pNVar3->super_Links_t).m_Right = -1;
  (pNVar3->super_Links_t).m_Left = -1;
  (pNVar3->super_Links_t).m_Tag = 0;
  if (iVar6 == -1) {
    this->m_Root = local_24;
  }
  else {
    pNVar3 = (this->m_Elements).m_pMemory + iVar6;
    if (bVar2) {
      (pNVar3->super_Links_t).m_Left = local_24;
    }
    else {
      (pNVar3->super_Links_t).m_Right = local_24;
    }
  }
  InsertRebalance(this,local_24);
  pNVar3 = (this->m_Elements).m_pMemory;
  this->m_NumElements = this->m_NumElements + 1;
  pNVar3 = pNVar3 + local_24;
  if (pNVar3 == (Node_t *)0xfffffff0) {
    return local_24;
  }
  uVar1 = *(undefined4 *)((int)insert + 4);
  *(int *)&pNVar3->m_Data = (int)*insert;
  *(undefined4 *)((int)&pNVar3->m_Data + 4) = uVar1;
  return local_24;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>::InsertRebalance  @ 001291a0
/* DWARF original prototype: void
   InsertRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
::InsertRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
                  *this,int elem)

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
LAB_001291ff:
      (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel == '\0') {
      iVar1 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar1 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar7 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_001291cf;
LAB_001291d8:
      iVar1 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel != '\0') ||
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar6 == 0)) goto LAB_001291e3;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      if (iVar1 == -1) goto LAB_00129500;
LAB_001291ec:
      pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    else {
      iVar1 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_001291cf:
        pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_001291d8;
      }
LAB_001291e3:
      if (iVar1 != -1) goto LAB_001291ec;
LAB_00129500:
      pLVar7 = &Links::s_Sentinel;
    }
    if ((((Node_t *)pLVar7)->super_Links_t).m_Tag != 0) {
      iVar1 = this->m_Root;
      goto LAB_001291ff;
    }
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int grandparent@[???] */
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel == '\0') {
      iVar1 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar1 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar7 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_00129238;
LAB_00129241:
      iVar1 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar6 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
    }
    else {
      iVar1 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_00129238:
        pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_00129241;
      }
    }
    if (iVar1 == -1) {
      iVar6 = Links::s_Sentinel.m_Parent;
      iVar5 = Links::s_Sentinel.m_Parent;
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') goto LAB_00129420;
LAB_00129278:
      if (iVar6 != -1) goto LAB_00129281;
LAB_001293fc:
      pLVar7 = &Links::s_Sentinel;
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      iVar5 = pNVar3[iVar1].super_Links_t.m_Parent;
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
LAB_00129420:
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (iVar1 != -1) {
          pNVar3 = (this->m_Elements).m_pMemory;
          goto LAB_00129267;
        }
      }
      else {
LAB_00129267:
        pLVar7 = &pNVar3[iVar1].super_Links_t;
      }
      iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel != '\0') goto LAB_00129278;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        goto LAB_00129278;
      }
      if (iVar6 == -1) goto LAB_001293fc;
LAB_00129281:
      pLVar7 = &(this->m_Elements).m_pMemory[iVar6].super_Links_t;
    }
    if (iVar1 == (((Node_t *)pLVar7)->super_Links_t).m_Left) {
                    /* Unresolved local var: int uncle@[???] */
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (iVar5 != -1) goto LAB_001292a3;
LAB_001292ad:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Right;
        iVar4 = Links::s_Sentinel.m_Parent;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel),
           iVar4 = Links::s_Sentinel.m_Parent, iVar2 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          Links::s_Sentinel.m_Right = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          iVar4 = Links::s_Sentinel.m_Parent;
        }
      }
      else {
        iVar6 = Links::s_Sentinel.m_Right;
        iVar4 = Links::s_Sentinel.m_Parent;
        if (iVar5 != -1) {
LAB_001292a3:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          goto LAB_001292ad;
        }
      }
      iVar2 = Links::s_Sentinel.m_Tag;
      if (iVar6 != -1) {
        iVar2 = (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Tag;
      }
      Links::s_Sentinel.m_Parent = iVar4;
      if (iVar2 == 0) {
LAB_001292d5:
                    /* Unresolved local var: int uncle@[???] */
        (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        elem = iVar5;
      }
      else {
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar6 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar7 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_001295c8;
LAB_001295d1:
          iVar4 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel != '\0') ||
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar6 == 0))
          goto LAB_001295dc;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          if (iVar4 == -1) goto LAB_00129a40;
LAB_001295e5:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        else {
          if (elem != -1) {
LAB_001295c8:
            pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_001295d1;
          }
LAB_001295dc:
          if (iVar4 != -1) goto LAB_001295e5;
LAB_00129a40:
          pLVar7 = &Links::s_Sentinel;
        }
        if (elem == (((Node_t *)pLVar7)->super_Links_t).m_Right) {
          RotateLeft(this,iVar1);
          if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0') {
            iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel);
            if (iVar6 != 0) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
            }
            pLVar7 = &Links::s_Sentinel;
            if (iVar1 != -1) goto LAB_001298a4;
LAB_001298ad:
            iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
            if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                 ::Links(int)::s_Sentinel == '\0') &&
               (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                             ::Links(int)::s_Sentinel), iVar5 != 0)) {
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
            }
          }
          else {
            iVar6 = Links::s_Sentinel.m_Parent;
            if (iVar1 != -1) {
LAB_001298a4:
              pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
              goto LAB_001298ad;
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
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (iVar5 != -1) goto LAB_00129321;
LAB_0012932b:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Left;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 == 0)) goto LAB_00129335;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        if (iVar6 == -1) goto LAB_001296c0;
LAB_0012933e:
        pLVar7 = &(this->m_Elements).m_pMemory[iVar6].super_Links_t;
      }
      else {
        iVar6 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
LAB_00129321:
          pLVar7 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          goto LAB_0012932b;
        }
LAB_00129335:
        if (iVar6 != -1) goto LAB_0012933e;
LAB_001296c0:
        pLVar7 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar7)->super_Links_t).m_Tag == 0) goto LAB_001292d5;
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar6 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar7 = &Links::s_Sentinel;
        if (elem != -1) goto LAB_00129366;
LAB_0012936f:
        iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 == 0)) goto LAB_0012937a;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        if (iVar6 == -1) goto LAB_00129940;
LAB_00129383:
        if (elem != (this->m_Elements).m_pMemory[iVar6].super_Links_t.m_Left) goto LAB_00129394;
LAB_00129950:
        RotateRight(this,iVar1);
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar6 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar7 = &Links::s_Sentinel;
          if (iVar1 != -1) goto LAB_00129974;
LAB_0012997d:
          iVar6 = (((Node_t *)pLVar7)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar5 != 0)) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar6 = Links::s_Sentinel.m_Parent;
          if (iVar1 != -1) {
LAB_00129974:
            pLVar7 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
            goto LAB_0012997d;
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
LAB_00129366:
          pLVar7 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
          goto LAB_0012936f;
        }
LAB_0012937a:
        if (iVar6 != -1) goto LAB_00129383;
LAB_00129940:
        if (elem == Links::s_Sentinel.m_Left) goto LAB_00129950;
LAB_00129394:
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


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>::RemoveRebalance  @ 00129fd0
/* DWARF original prototype: void
   RemoveRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
::RemoveRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
                  *this,int elem)

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
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      if (elem == -1) goto LAB_0012a620;
LAB_0012a00a:
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    else {
      if (elem != -1) goto LAB_0012a00a;
LAB_0012a620:
      pLVar6 = &Links::s_Sentinel;
    }
    iVar5 = elem;
    if ((((Node_t *)pLVar6)->super_Links_t).m_Tag != 1) break;
                    /* Unresolved local var: int parent@[???] */
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel == '\0') {
      iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar5 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::s_Sentinel;
      if (elem != -1) goto LAB_0012a050;
LAB_0012a059:
      iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel != '\0') goto LAB_0012a064;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      if (iVar5 == -1) goto LAB_0012a1fc;
LAB_0012a06d:
      if (elem != (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left) goto LAB_0012a07e;
LAB_0012a210:
                    /* Unresolved local var: int sibling@[???] */
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar5 != -1) goto LAB_0012a221;
        iVar4 = Links::s_Sentinel.m_Right;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0') goto LAB_0012a235;
LAB_0012a820:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar3 == 0) goto LAB_0012a235;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        if (iVar4 == -1) goto LAB_0012a870;
LAB_0012a23e:
        if ((this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag != 0) goto LAB_0012a253;
LAB_0012a880:
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        RotateLeft(this,iVar5);
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar5 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_0012a8c5;
LAB_0012a8ce:
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel != '\0') goto LAB_0012a8d9;
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          if (iVar5 == -1) goto LAB_0012abc4;
LAB_0012a8e2:
          pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        else {
          iVar5 = Links::s_Sentinel.m_Parent;
          if (elem != -1) {
LAB_0012a8c5:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_0012a8ce;
          }
LAB_0012a8d9:
          if (iVar5 != -1) goto LAB_0012a8e2;
LAB_0012abc4:
          pLVar6 = &Links::s_Sentinel;
        }
        iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') goto LAB_0012a8f6;
LAB_0012a262:
        iVar3 = Links::s_Sentinel.m_Left;
        if (iVar4 != -1) {
LAB_0012a26b:
          iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Left;
          if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0') goto LAB_0012a930;
        }
LAB_0012a27f:
        if (iVar3 != -1) goto LAB_0012a288;
LAB_0012a95c:
        iVar2 = Links::s_Sentinel.m_Right;
        if (Links::s_Sentinel.m_Tag == 1) goto LAB_0012a96b;
joined_r0x0012a9b6:
        Links::s_Sentinel.m_Right = iVar2;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          if (iVar4 != -1) goto LAB_0012a2ac;
          local_24 = -0x18;
          pLVar6 = &Links::s_Sentinel;
LAB_0012a2c0:
          iVar2 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
          if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel != '\0') goto LAB_0012a2cb;
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
            goto LAB_0012a2cb;
          }
          if (iVar2 == -1) goto LAB_0012abfc;
LAB_0012a2d4:
          if ((this->m_Elements).m_pMemory[iVar2].super_Links_t.m_Tag != 1) goto LAB_0012a2e7;
LAB_0012ac10:
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar5 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
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
          if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0') {
            iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel);
            if (iVar5 != 0) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
            }
            pLVar6 = &Links::s_Sentinel;
            if (elem != -1) goto LAB_0012ac6a;
LAB_0012ac73:
            iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
            if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                 ::Links(int)::s_Sentinel == '\0') &&
               (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                             ::Links(int)::s_Sentinel), iVar4 != 0)) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
            }
          }
          else {
            iVar5 = Links::s_Sentinel.m_Parent;
            if (elem != -1) {
LAB_0012ac6a:
              pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
              goto LAB_0012ac73;
            }
          }
          if (iVar5 == -1) {
            local_20 = -0x18;
            pLVar6 = &Links::s_Sentinel;
          }
          else {
            local_20 = iVar5 * 0x18;
            pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
          }
          iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
          local_24 = iVar4 * 0x18;
        }
        else {
          if (iVar4 != -1) {
LAB_0012a2ac:
            local_24 = iVar4 * 0x18;
            pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
            goto LAB_0012a2c0;
          }
          local_24 = -0x18;
LAB_0012a2cb:
          if (iVar2 != -1) goto LAB_0012a2d4;
LAB_0012abfc:
          if (Links::s_Sentinel.m_Tag == 1) goto LAB_0012ac10;
LAB_0012a2e7:
          local_20 = iVar5 * 0x18;
        }
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar3 != 0)) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar1 = (this->m_Elements).m_pMemory;
        pLVar6 = &Links::s_Sentinel;
        if (iVar5 != -1) {
          pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_20);
        }
        bVar7 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                ::Links(int)::s_Sentinel == '\0';
        *(int *)((int)&(pNVar1->super_Links_t).m_Tag + local_24) = pLVar6->m_Tag;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
        if ((bVar7) &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar3 != 0)) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
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
      else {
        iVar4 = Links::s_Sentinel.m_Right;
        if (iVar5 != -1) {
LAB_0012a221:
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Right;
          if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0') goto LAB_0012a820;
        }
LAB_0012a235:
        if (iVar4 != -1) goto LAB_0012a23e;
LAB_0012a870:
        if (Links::s_Sentinel.m_Tag == 0) goto LAB_0012a880;
LAB_0012a253:
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0') goto LAB_0012a262;
LAB_0012a8f6:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar4 != -1) goto LAB_0012a26b;
        iVar3 = Links::s_Sentinel.m_Left;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0') goto LAB_0012a27f;
LAB_0012a930:
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar2 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          goto LAB_0012a27f;
        }
        if (iVar3 == -1) goto LAB_0012a95c;
LAB_0012a288:
        iVar2 = Links::s_Sentinel.m_Right;
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag != 1) goto joined_r0x0012a9b6;
LAB_0012a96b:
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (iVar4 != -1) goto LAB_0012a97c;
LAB_0012a986:
          iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar2 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar3 = Links::s_Sentinel.m_Right;
          if (iVar4 != -1) {
LAB_0012a97c:
            pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
            goto LAB_0012a986;
          }
        }
        if (iVar3 == -1) {
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        iVar2 = Links::s_Sentinel.m_Right;
        if ((((Node_t *)pLVar6)->super_Links_t).m_Tag != 1) goto joined_r0x0012a9b6;
LAB_0012a660:
        elem = iVar5;
        if (iVar4 == -1) {
          iVar5 = this->m_Root;
        }
        else {
          (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 0;
          iVar5 = this->m_Root;
        }
      }
    }
    else {
      iVar5 = Links::s_Sentinel.m_Parent;
      if (elem != -1) {
LAB_0012a050:
        pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        goto LAB_0012a059;
      }
LAB_0012a064:
      if (iVar5 != -1) goto LAB_0012a06d;
LAB_0012a1fc:
      if (elem == Links::s_Sentinel.m_Left) goto LAB_0012a210;
LAB_0012a07e:
                    /* Unresolved local var: int sibling@[???] */
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar5 != -1) goto LAB_0012a08f;
        iVar4 = Links::s_Sentinel.m_Left;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0') goto LAB_0012a0a2;
LAB_0012a570:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar3 == 0) goto LAB_0012a0a2;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        if (iVar4 == -1) goto LAB_0012a5c0;
LAB_0012a0ab:
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      else {
        iVar4 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
LAB_0012a08f:
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left;
          if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0') goto LAB_0012a570;
        }
LAB_0012a0a2:
        if (iVar4 != -1) goto LAB_0012a0ab;
LAB_0012a5c0:
        pLVar6 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 0) {
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        RotateRight(this,iVar5);
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar5 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_0012a506;
LAB_0012a50f:
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar4 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar5 = Links::s_Sentinel.m_Parent;
          if (elem != -1) {
LAB_0012a506:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_0012a50f;
          }
        }
        iVar4 = Links::s_Sentinel.m_Left;
        if (iVar5 != -1) {
          iVar4 = (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Left;
        }
      }
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::s_Sentinel;
        if (iVar4 != -1) goto LAB_0012a0d8;
LAB_0012a0e2:
        iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0') goto LAB_0012a0ed;
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar2 != 0) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          goto LAB_0012a0ed;
        }
        if (iVar3 == -1) goto LAB_0012a3cc;
LAB_0012a0f6:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag != 1) goto LAB_0012a109;
LAB_0012a3e0:
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (iVar4 != -1) goto LAB_0012a3f1;
LAB_0012a3fb:
          iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar2 != 0)) {
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar3 = Links::s_Sentinel.m_Left;
          if (iVar4 != -1) {
LAB_0012a3f1:
            pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
            goto LAB_0012a3fb;
          }
        }
        if (iVar3 == -1) {
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 1) goto LAB_0012a660;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') goto LAB_0012a430;
LAB_0012a111:
        if (iVar4 != -1) {
LAB_0012a11a:
          local_24 = iVar4 * 0x18;
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
          goto LAB_0012a12e;
        }
        local_24 = -0x18;
        iVar3 = Links::s_Sentinel.m_Left;
        if (Links::s_Sentinel.m_Left == -1) goto LAB_0012a6a8;
LAB_0012a141:
        if ((this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Tag != 1) goto LAB_0012a154;
LAB_0012a6c0:
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar5 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar1 = (this->m_Elements).m_pMemory;
        pLVar6 = &Links::s_Sentinel;
        if (iVar4 != -1) {
          pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_24);
        }
        pNVar1[pLVar6->m_Right].super_Links_t.m_Tag = 1;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_24) = 0;
        RotateLeft(this,iVar4);
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar5 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (elem != -1) goto LAB_0012a71b;
LAB_0012a724:
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar4 != 0)) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
        }
        else {
          iVar5 = Links::s_Sentinel.m_Parent;
          if (elem != -1) {
LAB_0012a71b:
            pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
            goto LAB_0012a724;
          }
        }
        if (iVar5 == -1) {
          local_20 = -0x18;
          pLVar6 = &Links::s_Sentinel;
        }
        else {
          local_20 = iVar5 * 0x18;
          pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
        local_24 = iVar4 * 0x18;
      }
      else {
        iVar3 = Links::s_Sentinel.m_Right;
        if (iVar4 != -1) {
LAB_0012a0d8:
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
          goto LAB_0012a0e2;
        }
LAB_0012a0ed:
        if (iVar3 != -1) goto LAB_0012a0f6;
LAB_0012a3cc:
        if (Links::s_Sentinel.m_Tag == 1) goto LAB_0012a3e0;
LAB_0012a109:
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0') goto LAB_0012a111;
LAB_0012a430:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar4 != -1) goto LAB_0012a11a;
        local_24 = -0x18;
        pLVar6 = &Links::s_Sentinel;
LAB_0012a12e:
        iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = -1;
          Links::s_Sentinel.m_Right = -1;
          Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar3 != -1) goto LAB_0012a141;
LAB_0012a6a8:
        if (Links::s_Sentinel.m_Tag == 1) goto LAB_0012a6c0;
LAB_0012a154:
        local_20 = iVar5 * 0x18;
      }
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        Links::s_Sentinel.m_Left = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::s_Sentinel;
      if (iVar5 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_20);
      }
      bVar7 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar1->super_Links_t).m_Tag + local_24) = pLVar6->m_Tag;
      *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
      if ((bVar7) &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
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


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>::RotateLeft  @ 001285d0
/* DWARF original prototype: void
   RotateLeft(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
::RotateLeft(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
             *this,int elem)

{
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  bool bVar7;
  int local_28;
  
                    /* Unresolved local var: int rightchild@[???] */
  if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
      ::Links(int)::s_Sentinel == '\0') {
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar4 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    if (elem != -1) goto LAB_001285f7;
    iVar4 = -0x18;
    pLVar1 = &Links::s_Sentinel;
LAB_00128606:
    iVar6 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel != '\0') goto LAB_00128611;
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    if (iVar6 == -1) goto LAB_001286e0;
    pNVar5 = (this->m_Elements).m_pMemory;
    local_28 = iVar6 * 0x18;
    bVar7 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0';
    *(int *)((int)&(pNVar5->super_Links_t).m_Right + iVar4) = pNVar5[iVar6].super_Links_t.m_Left;
    if (bVar7) goto LAB_00128631;
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar2 != 0) goto LAB_001289fc;
LAB_0012882d:
    if (*(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28) != -1) {
LAB_00128712:
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        pNVar5 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar5 = (this->m_Elements).m_pMemory;
      }
LAB_00128735:
      if (iVar6 == -1) {
        pNVar5[Links::s_Sentinel.m_Left].super_Links_t.m_Parent = elem;
        goto LAB_00128657;
      }
      pNVar5[*(int *)((int)&(pNVar5->super_Links_t).m_Left + local_28)].super_Links_t.m_Parent =
           elem;
    }
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      pNVar5 = (this->m_Elements).m_pMemory;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
    }
LAB_0012863e:
    pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar4);
    if (elem == -1) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + local_28) = pLVar1->m_Parent;
  }
  else {
    if (elem != -1) {
LAB_001285f7:
      iVar4 = elem * 0x18;
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      goto LAB_00128606;
    }
    iVar4 = -0x18;
    iVar6 = Links::s_Sentinel.m_Right;
LAB_00128611:
    if (iVar6 != -1) {
      pNVar5 = (this->m_Elements).m_pMemory;
      local_28 = iVar6 * 0x18;
      *(int *)((int)&(pNVar5->super_Links_t).m_Right + iVar4) = pNVar5[iVar6].super_Links_t.m_Left;
LAB_00128631:
      pNVar5 = (this->m_Elements).m_pMemory;
      if (*(int *)((int)&(pNVar5->super_Links_t).m_Left + local_28) != -1) goto LAB_00128735;
      goto LAB_0012863e;
    }
LAB_001286e0:
    bVar7 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0';
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar4) =
         Links::s_Sentinel.m_Left;
    local_28 = -0x18;
    if ((bVar7) &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
LAB_001289fc:
      Links::s_Sentinel.m_Parent = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      if (iVar6 != -1) goto LAB_0012882d;
    }
    if (Links::s_Sentinel.m_Left != -1) goto LAB_00128712;
  }
LAB_00128657:
  if (elem == this->m_Root) {
    this->m_Root = iVar6;
    goto LAB_001286c3;
  }
  if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
      ::Links(int)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Parent = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) goto LAB_00128678;
LAB_0012867d:
    iVar2 = pLVar1->m_Parent;
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel != '\0') goto LAB_00128688;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      goto LAB_00128688;
    }
    if (iVar2 != -1) goto LAB_00128691;
LAB_001289bc:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    iVar2 = Links::s_Sentinel.m_Parent;
    if (elem != -1) {
LAB_00128678:
      pLVar1 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar4);
      goto LAB_0012867d;
    }
LAB_00128688:
    if (iVar2 == -1) goto LAB_001289bc;
LAB_00128691:
    pLVar1 = &(this->m_Elements).m_pMemory[iVar2].super_Links_t;
  }
  if (elem == (((Node_t *)pLVar1)->super_Links_t).m_Left) {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) {
      pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar4);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Left = iVar6;
  }
  else {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Parent = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) {
      pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar4);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Right = iVar6;
  }
LAB_001286c3:
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar4) = iVar6;
  }
  return;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>::RotateRight  @ 00128bd0
/* DWARF original prototype: void
   RotateRight(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
::RotateRight(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
              *this,int elem)

{
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  Node_t *pNVar4;
  int iVar5;
  int iVar6;
  int local_28;
  
                    /* Unresolved local var: int leftchild@[???] */
  if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
      ::Links(int)::s_Sentinel == '\0') {
    iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar6 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    if (elem != -1) goto LAB_00128bf7;
    iVar6 = -0x18;
    pLVar1 = &Links::s_Sentinel;
LAB_00128c02:
    iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
  }
  else {
    if (elem != -1) {
LAB_00128bf7:
      iVar6 = elem * 0x18;
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      goto LAB_00128c02;
    }
    iVar6 = -0x18;
    iVar5 = Links::s_Sentinel.m_Left;
  }
  pNVar4 = (this->m_Elements).m_pMemory;
  if (iVar5 == -1) {
    local_28 = -0x18;
    *(int *)((int)&(pNVar4->super_Links_t).m_Left + iVar6) = Links::s_Sentinel.m_Right;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
LAB_00128f08:
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      if (iVar5 != -1) goto LAB_00128e8c;
    }
    if (Links::s_Sentinel.m_Right != -1) {
LAB_00128d43:
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        pNVar4 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar4 = (this->m_Elements).m_pMemory;
      }
LAB_00128d66:
      if (iVar5 != -1) {
        pNVar4[*(int *)((int)&(pNVar4->super_Links_t).m_Right + local_28)].super_Links_t.m_Parent =
             elem;
        goto LAB_00128d85;
      }
      pNVar4[Links::s_Sentinel.m_Right].super_Links_t.m_Parent = elem;
    }
  }
  else {
    local_28 = iVar5 * 0x18;
    *(int *)((int)&(pNVar4->super_Links_t).m_Left + iVar6) = pNVar4[iVar5].super_Links_t.m_Right;
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel == '\0') {
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar2 != 0) goto LAB_00128f08;
LAB_00128e8c:
      if (*(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + local_28) != -1)
      goto LAB_00128d43;
LAB_00128d85:
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        pNVar4 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar4 = (this->m_Elements).m_pMemory;
      }
    }
    else {
      pNVar4 = (this->m_Elements).m_pMemory;
      if (pNVar4[iVar5].super_Links_t.m_Right != -1) goto LAB_00128d66;
    }
    pLVar1 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar6);
    if (elem == -1) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(int *)((int)&(pNVar4->super_Links_t).m_Parent + local_28) = pLVar1->m_Parent;
  }
  if (elem == this->m_Root) {
    this->m_Root = iVar5;
    goto LAB_00128cd4;
  }
  if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
      ::Links(int)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) goto LAB_00128c86;
LAB_00128c8b:
    iVar2 = pLVar1->m_Parent;
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel != '\0') goto LAB_00128c96;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      goto LAB_00128c96;
    }
    if (iVar2 != -1) goto LAB_00128c9f;
LAB_00129034:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    iVar2 = Links::s_Sentinel.m_Parent;
    if (elem != -1) {
LAB_00128c86:
      pLVar1 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6);
      goto LAB_00128c8b;
    }
LAB_00128c96:
    if (iVar2 == -1) goto LAB_00129034;
LAB_00128c9f:
    pLVar1 = &(this->m_Elements).m_pMemory[iVar2].super_Links_t;
  }
  if (elem == (((Node_t *)pLVar1)->super_Links_t).m_Right) {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar4 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) {
      pLVar1 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar6);
    }
    pNVar4[pLVar1->m_Parent].super_Links_t.m_Right = iVar5;
  }
  else {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar4 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (elem != -1) {
      pLVar1 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar6);
    }
    pNVar4[pLVar1->m_Parent].super_Links_t.m_Left = iVar5;
  }
LAB_00128cd4:
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + local_28) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar6) = iVar5;
  }
  return;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>::Unlink  @ 0012b3d0
/* DWARF original prototype: void
   Unlink(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
::Unlink(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(long_long_unsigned_int_const&,_long_long_unsigned_int_const&)>
         *this,int elem)

{
  Node_t *pNVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
  iVar4 = elem;
  if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
      ::Links(int)::s_Sentinel == '\0') {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    local_28 = elem * 0x18;
    pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    if ((((Node_t *)pLVar6)->super_Links_t).m_Left != -1) {
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel != '\0') goto LAB_0012b6b8;
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar3 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
      if (iVar3 != -1) {
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Left = -1;
            Links::s_Sentinel.m_Right = -1;
            Links::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right;
        }
        goto LAB_0012b6c4;
      }
    }
    cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel != '\0') goto LAB_0012b41d;
LAB_0012b8ca:
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
joined_r0x0012b8e8:
    if (iVar4 == -1) {
      pLVar6 = &Links::s_Sentinel;
      goto LAB_0012b41d;
    }
    if (*(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28) != -1)
    goto LAB_0012b426;
LAB_0012b75d:
    if ((cVar2 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    if (iVar4 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28);
    }
    local_2c = pLVar6->m_Right;
  }
  else {
    local_28 = elem * 0x18;
    pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
    if ((((Node_t *)pLVar6)->super_Links_t).m_Left != -1) {
LAB_0012b6b8:
      local_28 = elem * 0x18;
      iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
      if (iVar3 != -1) {
LAB_0012b6c4:
        cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                ::Links(int)::s_Sentinel;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') goto LAB_0012b703;
LAB_0012b6d0:
        if (iVar3 == -1) goto LAB_0012b723;
        while (iVar4 = iVar3, (this->m_Elements).m_pMemory[iVar3].super_Links_t.m_Left != -1) {
          while( true ) {
            if ((cVar2 == '\0') &&
               (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                             ::Links(int)::s_Sentinel),
               cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                       ::Links(int)::s_Sentinel, iVar3 != 0)) {
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
              cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                      ::Links(int)::s_Sentinel;
            }
            iVar3 = Links::s_Sentinel.m_Left;
            if (iVar4 != -1) {
              iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Left;
            }
            if (cVar2 != '\0') goto LAB_0012b6d0;
LAB_0012b703:
            iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel);
            if (iVar4 != 0) {
              Links::s_Sentinel.m_Right = -1;
              Links::s_Sentinel.m_Left = -1;
              Links::s_Sentinel.m_Parent = -1;
              __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
            }
            cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                    ::Links(int)::s_Sentinel;
            if (iVar3 != -1) break;
LAB_0012b723:
            iVar4 = iVar3;
            if (Links::s_Sentinel.m_Left == -1) goto LAB_0012b730;
          }
        }
LAB_0012b730:
        iVar4 = iVar3;
        if (cVar2 == '\0') {
          local_28 = iVar3 * 0x18;
          goto LAB_0012b8ca;
        }
        local_28 = iVar3 * 0x18;
        goto joined_r0x0012b8e8;
      }
    }
LAB_0012b41d:
    if ((((Node_t *)pLVar6)->super_Links_t).m_Left == -1) goto LAB_0012b75d;
LAB_0012b426:
    if ((cVar2 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    if (iVar4 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28);
    }
    local_2c = pLVar6->m_Left;
  }
  if (local_2c != -1) {
    if ((cVar2 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar6 = &Links::s_Sentinel;
    if (iVar4 != -1) {
      pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_28);
    }
    pNVar1[local_2c].super_Links_t.m_Parent = pLVar6->m_Parent;
  }
  if (iVar4 == this->m_Root) {
    this->m_Root = local_2c;
  }
  else {
    if (cVar2 == '\0') {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar3 != 0) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::s_Sentinel;
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
      if (iVar4 != -1) goto LAB_0012b48b;
LAB_0012b490:
      iVar3 = pLVar6->m_Parent;
      if ((cVar2 == '\0') &&
         (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel),
         cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                 ::Links(int)::s_Sentinel, iVar5 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                ::Links(int)::s_Sentinel;
      }
    }
    else {
      iVar3 = Links::s_Sentinel.m_Parent;
      if (iVar4 != -1) {
LAB_0012b48b:
        pLVar6 = (Links_t *)
                 ((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28);
        goto LAB_0012b490;
      }
    }
    if (iVar3 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
    }
    if (iVar4 == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
      if ((cVar2 == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_28);
      }
      pNVar1[pLVar6->m_Parent].super_Links_t.m_Left = local_2c;
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    else {
      if ((cVar2 == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel),
         cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                 ::Links(int)::s_Sentinel, iVar3 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                ::Links(int)::s_Sentinel;
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_28);
      }
      pNVar1[pLVar6->m_Parent].super_Links_t.m_Right = local_2c;
    }
  }
  if ((cVar2 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar3 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  if (iVar4 == -1) {
    local_24 = Links::s_Sentinel.m_Tag;
  }
  else {
    local_24 = *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_28);
    if (elem == iVar4) goto LAB_0012b549;
  }
  if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
      ::Links(int)::s_Sentinel == '\0') {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    bVar7 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0';
    *(int *)((int)&(pNVar1->super_Links_t).m_Parent + local_28) =
         pNVar1[elem].super_Links_t.m_Parent;
    if (bVar7) {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar3 != 0) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      bVar7 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar1->super_Links_t).m_Right + local_28) =
           pNVar1[elem].super_Links_t.m_Right;
      if ((bVar7) &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
    }
    else {
      pNVar1 = (this->m_Elements).m_pMemory;
      *(int *)((int)&(pNVar1->super_Links_t).m_Right + local_28) =
           pNVar1[elem].super_Links_t.m_Right;
    }
  }
  else {
    pNVar1 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar1->super_Links_t).m_Parent + local_28) =
         pNVar1[elem].super_Links_t.m_Parent;
    pNVar1 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar1->super_Links_t).m_Right + local_28) = pNVar1[elem].super_Links_t.m_Right;
  }
  pNVar1 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar1->super_Links_t).m_Left + local_28) = pNVar1[elem].super_Links_t.m_Left;
  if (elem == this->m_Root) {
    this->m_Root = iVar4;
    cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
  }
  else {
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel == '\0') {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar3 != 0) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar5 != 0)) {
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        Links::s_Sentinel.m_Left = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
    }
    else {
      iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
    }
    if (iVar3 == -1) {
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
    }
    if (elem == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pNVar1[pNVar1[elem].super_Links_t.m_Parent].super_Links_t.m_Left = iVar4;
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    else {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = -1;
        Links::s_Sentinel.m_Right = -1;
        Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
      pNVar1 = (this->m_Elements).m_pMemory;
      pNVar1[pNVar1[elem].super_Links_t.m_Parent].super_Links_t.m_Right = iVar4;
    }
  }
  if ((cVar2 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel),
     cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel, iVar3 != 0)) {
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
    cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
  }
  if (iVar4 == -1) {
    pLVar6 = &Links::s_Sentinel;
  }
  else {
    pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28);
  }
  if (pLVar6->m_Left != -1) {
    if ((cVar2 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar6 = &Links::s_Sentinel;
    if (iVar4 != -1) {
      pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_28);
    }
    pNVar1[pLVar6->m_Left].super_Links_t.m_Parent = iVar4;
  }
  if ((cVar2 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel),
     cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel, iVar3 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
    cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
  }
  if (iVar4 == -1) {
    pLVar6 = &Links::s_Sentinel;
  }
  else {
    pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28);
  }
  if (pLVar6->m_Right != -1) {
    if ((cVar2 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Left = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar2 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar6 = &Links::s_Sentinel;
    if (iVar4 != -1) {
      pLVar6 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + local_28);
    }
    pNVar1[pLVar6->m_Right].super_Links_t.m_Parent = iVar4;
  }
  if ((cVar2 == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar4 != 0)) {
    Links::s_Sentinel.m_Left = -1;
    Links::s_Sentinel.m_Right = -1;
    Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  pNVar1 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar1->super_Links_t).m_Tag + local_28) = pNVar1[elem].super_Links_t.m_Tag;
LAB_0012b549:
  if ((local_24 == 1) && (local_2c != -1)) {
    RemoveRebalance(this,local_2c);
    return;
  }
  return;
}


