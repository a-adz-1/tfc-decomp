// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::FindInsertionPosition  @ 00185080
/* DWARF original prototype: void
   FindInsertionPosition(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, ulonglong * insert, bool bCheckForDuplicates, int * parent, bool * leftchild, bool *
   isDuplicate) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::FindInsertionPosition
          (CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
           *this,ulonglong *insert,bool bCheckForDuplicates,int *parent,bool *leftchild,
          bool *isDuplicate)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int current@[???] */
  iVar2 = this->m_Root;
  *parent = -1;
  *leftchild = false;
  *isDuplicate = false;
  do {
    if (iVar2 == -1) {
      return;
    }
    while( true ) {
      *parent = iVar2;
      bVar1 = (*this->m_LessFunc)(insert,&(this->m_Elements).m_pMemory[iVar2].m_Data);
      if (bVar1) break;
      if ((bCheckForDuplicates) &&
         (bVar1 = (*this->m_LessFunc)(&(this->m_Elements).m_pMemory[iVar2].m_Data,insert), !bVar1))
      {
        *leftchild = false;
        *isDuplicate = true;
        return;
      }
      *leftchild = false;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      iVar2 = (this->m_Elements).m_pMemory[iVar2].super_Links_t.m_Right;
      if (iVar2 == -1) {
        return;
      }
    }
    *leftchild = true;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    iVar2 = (this->m_Elements).m_pMemory[iVar2].super_Links_t.m_Left;
  } while( true );
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::Insert  @ 00186970
/* DWARF original prototype: int
   Insert(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, ulonglong * insert, bool bInsertDuplicates) */

int __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::Insert(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
         *this,ulonglong *insert,bool bInsertDuplicates)

{
  undefined4 uVar1;
  Node_t *pNVar2;
  int iVar3;
  int local_1c [3];
  bool local_e;
  bool local_d;
  
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: bool leftchild@[???]
                       Unresolved local var: bool isDuplicate@[???] */
  FindInsertionPosition(this,insert,!bInsertDuplicates,local_1c,&local_e,&local_d);
  if ((local_d != false) && (!bInsertDuplicates)) {
    uVar1 = *(undefined4 *)((int)insert + 4);
    pNVar2 = (this->m_Elements).m_pMemory;
    *(int *)&pNVar2[local_1c[0]].m_Data = (int)*insert;
    *(undefined4 *)((int)&pNVar2[local_1c[0]].m_Data + 4) = uVar1;
    return local_1c[0];
  }
                    /* Unresolved local var: int newNode@[???] */
  iVar3 = InsertAt(this,local_1c[0],local_e);
  pNVar2 = (this->m_Elements).m_pMemory + iVar3;
  if (pNVar2 != (Node_t *)0xfffffff0) {
    uVar1 = *(undefined4 *)((int)insert + 4);
    *(int *)&pNVar2->m_Data = (int)*insert;
    *(undefined4 *)((int)&pNVar2->m_Data + 4) = uVar1;
  }
  return iVar3;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::InsertAt  @ 00186800
/* DWARF original prototype: int
   InsertAt(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, int parent, bool leftchild) */

int __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::InsertAt(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
           *this,int parent,bool leftchild)

{
  int iVar1;
  size_t __size;
  Node_t *pNVar2;
  Node_t *pNVar3;
  int elem;
  
                    /* Unresolved local var: int i@[DW_OP_reg7(EDI)]
                       Unresolved local var: int newElem@[???] */
  elem = this->m_FirstFree;
  if (elem == -1) {
    elem = this->m_TotalElements;
    if ((this->m_Elements).m_NumAllocated == elem) {
                    /* Unresolved local var: int growSize@[???] */
      iVar1 = (this->m_Elements).m_GrowSize;
      if ((iVar1 == 0) && (iVar1 = 1, elem != 0)) {
        iVar1 = elem;
      }
      pNVar2 = (this->m_Elements).m_pMemory;
      (this->m_Elements).m_NumAllocated = iVar1 + elem;
      __size = (iVar1 + elem) * 0x18;
      if (pNVar2 == (Node_t *)0x0) {
        pNVar2 = malloc(__size);
        (this->m_Elements).m_pMemory = pNVar2;
      }
      else {
        pNVar2 = realloc(pNVar2,__size);
        elem = this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar2;
      }
    }
    else {
      pNVar2 = (this->m_Elements).m_pMemory;
    }
    this->m_TotalElements = elem + 1;
    pNVar3 = pNVar2 + elem;
  }
  else {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar2 = (this->m_Elements).m_pMemory;
    pNVar3 = pNVar2 + elem;
    this->m_FirstFree = (pNVar3->super_Links_t).m_Right;
  }
                    /* Unresolved local var: Links_t * elem@[???] */
  this->m_pElements = pNVar2;
  (pNVar3->super_Links_t).m_Parent = parent;
  (pNVar3->super_Links_t).m_Right = -1;
  (pNVar3->super_Links_t).m_Left = -1;
  (pNVar3->super_Links_t).m_Tag = 0;
  if (parent == -1) {
    this->m_Root = elem;
  }
  else {
    pNVar2 = (this->m_Elements).m_pMemory + parent;
    if (leftchild) {
      (pNVar2->super_Links_t).m_Left = elem;
    }
    else {
      (pNVar2->super_Links_t).m_Right = elem;
    }
  }
  InsertRebalance(this,elem);
  this->m_NumElements = this->m_NumElements + 1;
  return elem;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::InsertRebalance  @ 00185ea0
/* DWARF original prototype: void
   InsertRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::InsertRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
                  *this,int elem)

{
  int iVar1;
  int iVar2;
  Node_t *pNVar3;
  int iVar4;
  int iVar5;
  Links_t *pLVar6;
  
  do {
                    /* Unresolved local var: int parent@[???]
                       Unresolved local var: int grandparent@[???]
                       Unresolved local var: int uncle@[DW_OP_reg2(EDX)] */
    iVar1 = this->m_Root;
    if (elem == iVar1) {
LAB_00185f01:
      (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    iVar1 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    if ((((Node_t *)pLVar6)->super_Links_t).m_Tag != 0) {
      iVar1 = this->m_Root;
      goto LAB_00185f01;
    }
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    iVar1 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
    }
    iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
    }
    if (iVar1 == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
                    /* Unresolved local var: int uncle@[DW_OP_reg2(EDX)] */
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Right;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 0) {
LAB_00185fe9:
        (this->m_Elements).m_pMemory[iVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        elem = iVar5;
      }
      else {
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        if (elem == (((Node_t *)pLVar6)->super_Links_t).m_Right) {
          RotateLeft(this,iVar1);
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar5 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          pLVar6 = &Links::lexical_block_0::s_Sentinel;
          if (iVar1 != -1) {
            pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
          }
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                           ::Links(int)::s_Sentinel), iVar4 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          if (iVar5 == -1) {
            pLVar6 = &Links::lexical_block_0::s_Sentinel;
            pNVar3 = (this->m_Elements).m_pMemory + -1;
          }
          else {
            pNVar3 = (this->m_Elements).m_pMemory + iVar5;
            pLVar6 = &pNVar3->super_Links_t;
          }
          iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
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
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 0) goto LAB_00185fe9;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar6 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if (elem == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
        RotateRight(this,iVar1);
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar5 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (iVar1 != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar1].super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar5 == -1) {
          pLVar6 = &Links::lexical_block_0::s_Sentinel;
          pNVar3 = (this->m_Elements).m_pMemory + -1;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + iVar5;
          pLVar6 = &pNVar3->super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar6)->super_Links_t).m_Parent;
      }
      else {
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


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::Remove  @ 00188a10
/* DWARF original prototype: bool
   Remove(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, ulonglong * search) */

bool __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::Remove(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
         *this,ulonglong *search)

{
  bool bVar1;
  Node_t *pNVar2;
  int iVar3;
  int elem;
  
                    /* Unresolved local var: int node@[DW_OP_reg3(EBX)]
                       Unresolved local var: int current@[???] */
  elem = this->m_Root;
  if (elem != -1) {
    pNVar2 = (this->m_Elements).m_pMemory;
    do {
      while (bVar1 = (*this->m_LessFunc)(search,&pNVar2[elem].m_Data), !bVar1) {
        bVar1 = (*this->m_LessFunc)(&(this->m_Elements).m_pMemory[elem].m_Data,search);
        if (!bVar1) {
          Unlink(this,elem);
          (this->m_Elements).m_pMemory[elem].super_Links_t.m_Left = elem;
          (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right = this->m_FirstFree;
          this->m_NumElements = this->m_NumElements + -1;
          this->m_FirstFree = elem;
          return true;
        }
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar2 = (this->m_Elements).m_pMemory;
        elem = pNVar2[elem].super_Links_t.m_Right;
        if (elem == -1) {
          return false;
        }
      }
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar2 = (this->m_Elements).m_pMemory;
      elem = pNVar2[elem].super_Links_t.m_Left;
    } while (elem != -1);
  }
  return false;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::RemoveRebalance  @ 00186a40
/* DWARF original prototype: void
   RemoveRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::RemoveRebalance(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
                  *this,int elem)

{
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  Node_t *pNVar6;
  int iVar7;
  bool bVar8;
  int local_20;
  
  iVar4 = this->m_Root;
  do {
    if (elem == iVar4) {
LAB_00186c40:
      (this->m_Elements).m_pMemory[elem].super_Links_t.m_Tag = 1;
      return;
    }
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    if ((((Node_t *)pLVar1)->super_Links_t).m_Tag != 1) goto LAB_00186c40;
                    /* Unresolved local var: int parent@[???] */
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
    }
    iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar5 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
    }
    if (elem != (((Node_t *)pLVar1)->super_Links_t).m_Left) {
                    /* Unresolved local var: int sibling@[???] */
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 0) {
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
        RotateRight(this,iVar5);
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar5 != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
      }
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar7 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
        }
        iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar7 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar3 != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
          if (iVar4 != -1) {
            (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 0;
          }
          goto LAB_00187066;
        }
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') goto LAB_00186e60;
LAB_00186b71:
        if (iVar4 != -1) goto LAB_00186b7a;
LAB_00186e84:
        iVar7 = -0x18;
        iVar3 = Links::lexical_block_0::s_Sentinel.m_Left;
      }
      else {
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0') goto LAB_00186b71;
LAB_00186e60:
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar3 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar4 == -1) goto LAB_00186e84;
LAB_00186b7a:
        iVar7 = iVar4 * 0x18;
        iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Left;
      }
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar5 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
        }
        pNVar6[pLVar1->m_Right].super_Links_t.m_Tag = 1;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + iVar7) = 0;
        RotateLeft(this,iVar4);
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar6 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pNVar6 = (this->m_Elements).m_pMemory + elem;
        }
        iVar5 = (pNVar6->super_Links_t).m_Parent;
        if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel);
          if (iVar4 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Left = -1;
            Links::lexical_block_0::s_Sentinel.m_Right = -1;
            Links::lexical_block_0::s_Sentinel.m_Parent = -1;
            __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
          }
          if (iVar5 == -1) goto LAB_00187a10;
LAB_00187352:
          local_20 = iVar5 * 0x18;
          pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        else {
          if (iVar5 != -1) goto LAB_00187352;
LAB_00187a10:
          pLVar1 = &Links::lexical_block_0::s_Sentinel;
          local_20 = -0x18;
        }
        iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
        iVar7 = iVar4 * 0x18;
      }
      else {
        local_20 = iVar5 * 0x18;
      }
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar6 = (this->m_Elements).m_pMemory;
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + local_20);
      }
      bVar8 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar6->super_Links_t).m_Tag + iVar7) = pLVar1->m_Tag;
      *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
      if ((bVar8) &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        pNVar6 = (this->m_Elements).m_pMemory;
        if (iVar4 == -1) goto LAB_00187480;
LAB_00186c08:
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
      }
      else {
        pNVar6 = (this->m_Elements).m_pMemory;
        if (iVar4 != -1) goto LAB_00186c08;
LAB_00187480:
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
      }
      pNVar6[pLVar1->m_Left].super_Links_t.m_Tag = 1;
      RotateRight(this,iVar5);
      elem = this->m_Root;
      goto LAB_00186c40;
    }
                    /* Unresolved local var: int sibling@[???] */
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar5 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
    }
    iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
    }
    if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 0) {
      (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 1;
      (this->m_Elements).m_pMemory[iVar5].super_Links_t.m_Tag = 0;
      RotateLeft(this,iVar5);
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
      }
      iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
      }
      iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
    }
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
    }
    iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Left;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar7 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar1 = &Links::lexical_block_0::s_Sentinel;
    if (iVar3 != -1) {
      pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
    }
    if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar4 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar4].super_Links_t;
      }
      iVar3 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar7 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag != 1) goto joined_r0x001874f9;
      if (iVar4 == -1) {
LAB_00187066:
        iVar4 = this->m_Root;
        elem = iVar5;
      }
      else {
        (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Tag = 0;
        iVar4 = this->m_Root;
        elem = iVar5;
      }
    }
    else {
joined_r0x001874f9:
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar3 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar4 == -1) goto LAB_00187524;
LAB_00186d40:
        iVar7 = iVar4 * 0x18;
        iVar3 = (this->m_Elements).m_pMemory[iVar4].super_Links_t.m_Right;
      }
      else {
        if (iVar4 != -1) goto LAB_00186d40;
LAB_00187524:
        iVar7 = -0x18;
        iVar3 = Links::lexical_block_0::s_Sentinel.m_Right;
      }
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar3 != -1) {
        pLVar1 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
      }
      if ((((Node_t *)pLVar1)->super_Links_t).m_Tag == 1) {
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar5 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pNVar6 = (this->m_Elements).m_pMemory;
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (iVar4 != -1) {
          pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
        }
        pNVar6[pLVar1->m_Left].super_Links_t.m_Tag = 1;
        *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + iVar7) = 0;
        RotateRight(this,iVar4);
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
        if (elem != -1) {
          pLVar1 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
        }
        iVar5 = (((Node_t *)pLVar1)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel), iVar4 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
        }
        if (iVar5 == -1) {
          pLVar1 = &Links::lexical_block_0::s_Sentinel;
          local_20 = -0x18;
        }
        else {
          local_20 = iVar5 * 0x18;
          pLVar1 = &(this->m_Elements).m_pMemory[iVar5].super_Links_t;
        }
        iVar4 = (((Node_t *)pLVar1)->super_Links_t).m_Right;
        iVar7 = iVar4 * 0x18;
      }
      else {
        local_20 = iVar5 * 0x18;
      }
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar6 = (this->m_Elements).m_pMemory;
      pLVar1 = &Links::lexical_block_0::s_Sentinel;
      if (iVar5 != -1) {
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + local_20);
      }
      bVar8 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel == '\0';
      *(int *)((int)&(pNVar6->super_Links_t).m_Tag + iVar7) = pLVar1->m_Tag;
      *(undefined4 *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + local_20) = 1;
      if ((bVar8) &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar6 = (this->m_Elements).m_pMemory;
      if (iVar4 == -1) {
        pLVar1 = &Links::lexical_block_0::s_Sentinel;
      }
      else {
        pLVar1 = (Links_t *)((int)&(pNVar6->super_Links_t).m_Left + iVar7);
      }
      pNVar6[pLVar1->m_Right].super_Links_t.m_Tag = 1;
      RotateLeft(this,iVar5);
      iVar4 = this->m_Root;
      elem = iVar4;
    }
  } while( true );
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::RotateLeft  @ 00185450
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void
   RotateLeft(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::RotateLeft(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
             *this,int elem)

{
  Node_t *pNVar1;
  Links_t *pLVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
                    /* Unresolved local var: int rightchild@[DW_OP_reg7(EDI)] */
  if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar3 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  if (elem == -1) {
    iVar7 = -0x18;
    iVar3 = Links::lexical_block_0::s_Sentinel.m_Right;
  }
  else {
    iVar7 = elem * 0x18;
    iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right;
  }
  if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  if (iVar3 == -1) {
    pNVar1 = (this->m_Elements).m_pMemory;
    iVar6 = -0x18;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    pNVar1 = (this->m_Elements).m_pMemory;
    iVar6 = iVar3 * 0x18;
    pLVar2 = &pNVar1[iVar3].super_Links_t;
  }
  bVar8 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0';
  *(int *)((int)&(pNVar1->super_Links_t).m_Right + iVar7) =
       (((Node_t *)pLVar2)->super_Links_t).m_Left;
  if ((bVar8) &&
     (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar5 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  pLVar2 = &Links::lexical_block_0::s_Sentinel;
  if (iVar3 != -1) {
    pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6);
  }
  if (pLVar2->m_Left != -1) {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (iVar3 != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar6);
    }
    pNVar1[pLVar2->m_Left].super_Links_t.m_Parent = elem;
  }
  if (iVar3 != -1) {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
    }
    *(int *)((int)&(pNVar1->super_Links_t).m_Parent + iVar6) = pLVar2->m_Parent;
  }
  if (elem == this->m_Root) {
    this->m_Root = iVar3;
  }
  else {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    iVar5 = pLVar2->m_Parent;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar1 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (iVar5 != -1) {
      pNVar1 = (this->m_Elements).m_pMemory + iVar5;
    }
    if (elem == (pNVar1->super_Links_t).m_Left) {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar5 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
      }
      pNVar1[pLVar2->m_Parent].super_Links_t.m_Left = iVar3;
    }
    else {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar5 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar5 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
      }
      pNVar1[pLVar2->m_Parent].super_Links_t.m_Right = iVar3;
    }
  }
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar7) = iVar3;
  }
  return;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::RotateRight  @ 001859a0
/* DWARF original prototype: void
   RotateRight(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::RotateRight(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
              *this,int elem)

{
  int iVar1;
  Links_t *pLVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int leftchild@[DW_OP_reg7(EDI)] */
  if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar7 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  if (elem == -1) {
    iVar7 = -0x18;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar7 = elem * 0x18;
    pLVar2 = &(this->m_Elements).m_pMemory[elem].super_Links_t;
  }
  iVar1 = (((Node_t *)pLVar2)->super_Links_t).m_Left;
  if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  pNVar5 = (this->m_Elements).m_pMemory;
  if (iVar1 == -1) {
    iVar6 = -0x18;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar6 = iVar1 * 0x18;
    pLVar2 = &pNVar5[iVar1].super_Links_t;
  }
  *(int *)((int)&(pNVar5->super_Links_t).m_Left + iVar7) =
       (((Node_t *)pLVar2)->super_Links_t).m_Right;
  if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  pLVar2 = &Links::lexical_block_0::s_Sentinel;
  if (iVar1 != -1) {
    pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6);
  }
  if (pLVar2->m_Right != -1) {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (iVar1 != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar6);
    }
    pNVar5[pLVar2->m_Right].super_Links_t.m_Parent = elem;
  }
  if (iVar1 != -1) {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
    }
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + iVar6) = pLVar2->m_Parent;
  }
  if (elem == this->m_Root) {
    this->m_Root = iVar1;
  }
  else {
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    iVar4 = pLVar2->m_Parent;
    if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (iVar4 != -1) {
      pNVar5 = (this->m_Elements).m_pMemory + iVar4;
    }
    if (elem == (pNVar5->super_Links_t).m_Right) {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar2->m_Parent].super_Links_t.m_Right = iVar1;
    }
    else {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar2->m_Parent].super_Links_t.m_Left = iVar1;
    }
  }
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar6) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar7) = iVar1;
  }
  return;
}


// CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>::Unlink  @ 00187ce0
/* WARNING: Variable defined which should be unmapped: ycolor */
/* DWARF original prototype: void
   Unlink(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
   * this, int elem) */

void __thiscall
CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
::Unlink(CUtlRBTree<long_long_unsigned_int,_int,_bool_(*)(const_long_long_unsigned_int&,_const_long_long_unsigned_int&)>
         *this,int elem)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  Links_t *pLVar6;
  int iVar7;
  bool bVar8;
  int local_30;
  int local_20;
  NodeColor_t ycolor;
  
  if (elem == -1) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar2 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  iVar7 = elem * 0x18;
  pNVar5 = (this->m_Elements).m_pMemory + elem;
  iVar2 = elem;
  cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel;
  if ((pNVar5->super_Links_t).m_Left != -1) {
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel == '\0') {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar3 == 0) {
        pNVar5 = (this->m_Elements).m_pMemory + elem;
      }
      else {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        pNVar5 = (this->m_Elements).m_pMemory + elem;
      }
    }
    iVar3 = (pNVar5->super_Links_t).m_Right;
    cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
    if (iVar3 != -1) {
      if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
          ::Links(int)::s_Sentinel == '\0') {
        iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel);
        if (iVar2 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right;
          cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                  ::Links(int)::s_Sentinel;
          goto LAB_00187d85;
        }
        iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right;
        cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                ::Links(int)::s_Sentinel;
        goto LAB_00187d85;
      }
      while( true ) {
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (iVar3 != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        if ((((Node_t *)pLVar6)->super_Links_t).m_Left == -1) break;
        if ((cVar1 == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel),
           cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                   ::Links(int)::s_Sentinel, iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                  ::Links(int)::s_Sentinel;
        }
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
        if (iVar3 != -1) {
          pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
        }
        iVar3 = (((Node_t *)pLVar6)->super_Links_t).m_Left;
LAB_00187d85:
        if ((cVar1 == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                         ::Links(int)::s_Sentinel),
           cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                   ::Links(int)::s_Sentinel, iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = -1;
          Links::lexical_block_0::s_Sentinel.m_Right = -1;
          Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                               ::Links(int)::s_Sentinel);
          cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                  ::Links(int)::s_Sentinel;
        }
      }
      iVar7 = iVar3 * 0x18;
      iVar2 = iVar3;
    }
  }
  if ((cVar1 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel),
     cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel, iVar3 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
    cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
  }
  pLVar6 = &Links::lexical_block_0::s_Sentinel;
  if (iVar2 != -1) {
    pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
  }
  if (pLVar6->m_Left == -1) {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar2 != -1) {
      pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    local_30 = pLVar6->m_Right;
  }
  else {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar2 != -1) {
      pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    local_30 = pLVar6->m_Left;
  }
  if (local_30 != -1) {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    if (iVar2 == -1) {
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar6 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
    }
    pNVar5[local_30].super_Links_t.m_Parent = pLVar6->m_Parent;
  }
  if (iVar2 == this->m_Root) {
    this->m_Root = local_30;
  }
  else {
    if ((cVar1 == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar2 != -1) {
      pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    iVar3 = pLVar6->m_Parent;
    if ((cVar1 == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (iVar3 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[iVar3].super_Links_t;
    }
    if (iVar2 == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
      if ((cVar1 == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
      if (iVar2 != -1) {
        pLVar6 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar6->m_Parent].super_Links_t.m_Left = local_30;
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    else {
      if ((cVar1 == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel),
         cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                 ::Links(int)::s_Sentinel, iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
        cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                ::Links(int)::s_Sentinel;
      }
      if (iVar2 == -1) {
        pNVar5 = (this->m_Elements).m_pMemory;
        pLVar6 = &Links::lexical_block_0::s_Sentinel;
      }
      else {
        pNVar5 = (this->m_Elements).m_pMemory;
        pLVar6 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar6->m_Parent].super_Links_t.m_Right = local_30;
    }
  }
  if ((cVar1 == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar3 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  iVar3 = Links::lexical_block_0::s_Sentinel.m_Tag;
  if ((iVar2 != -1) &&
     (iVar3 = *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Tag + iVar7),
     iVar2 == elem)) goto LAB_00187ef5;
  if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
      ::Links(int)::s_Sentinel == '\0') {
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar4 != 0) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    bVar8 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel != '\0';
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + iVar7) = pNVar5[elem].super_Links_t.m_Parent;
    if (bVar8) goto LAB_00187f92;
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                 ::Links(int)::s_Sentinel);
    if (iVar4 != 0) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    bVar8 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel == '\0';
    *(int *)((int)&(pNVar5->super_Links_t).m_Right + iVar7) = pNVar5[elem].super_Links_t.m_Right;
    if ((bVar8) &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
    }
  }
  else {
    pNVar5 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar5->super_Links_t).m_Parent + iVar7) = pNVar5[elem].super_Links_t.m_Parent;
LAB_00187f92:
    pNVar5 = (this->m_Elements).m_pMemory;
    *(int *)((int)&(pNVar5->super_Links_t).m_Right + iVar7) = pNVar5[elem].super_Links_t.m_Right;
  }
  pNVar5 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar5->super_Links_t).m_Left + iVar7) = pNVar5[elem].super_Links_t.m_Left;
  if (elem == this->m_Root) {
    this->m_Root = iVar2;
    cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
  }
  else {
    if (CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
        ::Links(int)::s_Sentinel == '\0') {
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel);
      if (iVar4 != 0) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      local_20 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
    }
    else {
      local_20 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent;
    }
    pLVar6 = &Links::lexical_block_0::s_Sentinel;
    if (local_20 != -1) {
      pLVar6 = &(this->m_Elements).m_pMemory[local_20].super_Links_t;
    }
    if (elem == (((Node_t *)pLVar6)->super_Links_t).m_Left) {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pNVar5[pNVar5[elem].super_Links_t.m_Parent].super_Links_t.m_Left = iVar2;
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    else {
      if ((CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                       ::Links(int)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                             ::Links(int)::s_Sentinel);
      }
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
      pNVar5 = (this->m_Elements).m_pMemory;
      pNVar5[pNVar5[elem].super_Links_t.m_Parent].super_Links_t.m_Right = iVar2;
    }
  }
  if ((cVar1 == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel),
     cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel, iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
    cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
  }
  pLVar6 = &Links::lexical_block_0::s_Sentinel;
  if (iVar2 != -1) {
    pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
  }
  if (pLVar6->m_Left != -1) {
    if ((cVar1 == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    if (iVar2 == -1) {
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar6 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
    }
    pNVar5[pLVar6->m_Left].super_Links_t.m_Parent = iVar2;
  }
  if ((cVar1 == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel),
     cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
             ::Links(int)::s_Sentinel, iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
    cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
            ::Links(int)::s_Sentinel;
  }
  pLVar6 = &Links::lexical_block_0::s_Sentinel;
  if (iVar2 != -1) {
    pLVar6 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
  }
  if (pLVar6->m_Right != -1) {
    if ((cVar1 == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                     ::Links(int)::s_Sentinel),
       cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
               ::Links(int)::s_Sentinel, iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                           ::Links(int)::s_Sentinel);
      cVar1 = CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
              ::Links(int)::s_Sentinel;
    }
    if (iVar2 == -1) {
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar6 = &Links::lexical_block_0::s_Sentinel;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar6 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
    }
    pNVar5[pLVar6->m_Right].super_Links_t.m_Parent = iVar2;
  }
  if ((cVar1 == '\0') &&
     (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                                   ::Links(int)::s_Sentinel), iVar2 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<unsigned_long_long,int,bool(*)(unsigned_long_long_const&,unsigned_long_long_const&)>
                         ::Links(int)::s_Sentinel);
  }
  pNVar5 = (this->m_Elements).m_pMemory;
  *(int *)((int)&(pNVar5->super_Links_t).m_Tag + iVar7) = pNVar5[elem].super_Links_t.m_Tag;
LAB_00187ef5:
  if ((local_30 != -1) && (iVar3 == 1)) {
    RemoveRebalance(this,local_30);
    return;
  }
  return;
}


