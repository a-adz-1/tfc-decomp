// CUtlRBTree<unsigned_int,_short_unsigned_int>::InsertAt  @ 00264220
/* DWARF original prototype: ushort InsertAt(CUtlRBTree<unsigned_int,_short_unsigned_int> * this,
   ushort parent, bool leftchild) */

ushort __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::InsertAt
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,ushort parent,bool leftchild)

{
  int iVar1;
  uint uVar2;
  size_t __size;
  Node_t *pNVar3;
  ushort elem;
  uint uVar4;
  
                    /* Unresolved local var: ushort i@[DW_OP_reg7(EDI)]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: ushort newElem@[???] */
  uVar4 = (uint)this->m_FirstFree;
  if (uVar4 == 0xffff) {
    uVar4 = (uint)this->m_TotalElements;
    if ((this->m_Elements).m_NumAllocated == uVar4) {
                    /* Unresolved local var: int growSize@[???] */
      uVar2 = (this->m_Elements).m_GrowSize;
      if ((uVar2 == 0) && (uVar2 = 1, uVar4 != 0)) {
        uVar2 = uVar4;
      }
      pNVar3 = (this->m_Elements).m_pMemory;
      (this->m_Elements).m_NumAllocated = uVar2 + uVar4;
      __size = (uVar2 + uVar4) * 0xc;
      if (pNVar3 == (Node_t *)0x0) {
        pNVar3 = malloc(__size);
        (this->m_Elements).m_pMemory = pNVar3;
      }
      else {
        pNVar3 = realloc(pNVar3,__size);
        uVar4 = (uint)this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar3;
      }
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
    }
    this->m_TotalElements = (short)uVar4 + 1;
    pNVar3 = pNVar3 + uVar4;
  }
  else {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar3 = (this->m_Elements).m_pMemory + uVar4;
    this->m_FirstFree = (pNVar3->super_Links_t).m_Right;
  }
  (pNVar3->super_Links_t).m_Parent = parent;
  (pNVar3->super_Links_t).m_Right = 0xffff;
  (pNVar3->super_Links_t).m_Left = 0xffff;
  (pNVar3->super_Links_t).m_Tag = 0;
  elem = (ushort)uVar4;
  if (parent == 0xffff) {
    this->m_Root = elem;
  }
  else {
    pNVar3 = (this->m_Elements).m_pMemory + parent;
    if (leftchild) {
      (pNVar3->super_Links_t).m_Left = elem;
    }
    else {
      (pNVar3->super_Links_t).m_Right = elem;
    }
  }
  InsertRebalance(this,elem);
  this->m_NumElements = this->m_NumElements + 1;
  return elem;
}


// CUtlRBTree<unsigned_int,_short_unsigned_int>::InsertRebalance  @ 00263810
/* DWARF original prototype: void InsertRebalance(CUtlRBTree<unsigned_int,_short_unsigned_int> *
   this, ushort elem) */

void __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::InsertRebalance
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,ushort elem)

{
  ushort elem_00;
  uint uVar1;
  Node_t *pNVar2;
  int iVar3;
  Links_t *pLVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = (uint)elem;
  do {
                    /* Unresolved local var: ushort parent@[???]
                       Unresolved local var: ushort grandparent@[???]
                       Unresolved local var: ushort uncle@[DW_OP_reg2(EDX)] */
    uVar1 = (uint)this->m_Root;
    if (uVar7 == uVar1) {
LAB_0026387a:
      (this->m_Elements).m_pMemory[uVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar7 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
    }
    uVar1 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    if ((((Node_t *)pLVar4)->super_Links_t).m_Tag != 0) {
      uVar1 = (uint)this->m_Root;
      goto LAB_0026387a;
    }
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar7 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
    }
    elem_00 = (((Node_t *)pLVar4)->super_Links_t).m_Parent;
    uVar1 = (uint)elem_00;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar5 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
    }
                    /* Unresolved local var: ushort uncle@[DW_OP_reg2(EDX)] */
    if ((((Node_t *)pLVar4)->super_Links_t).m_Left == uVar1) {
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar6 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Right;
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Tag == 0) {
LAB_0026397e:
        (this->m_Elements).m_pMemory[uVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar5].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 0;
        uVar7 = uVar6;
      }
      else {
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar7 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
        }
        uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar5 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
        }
        if ((((Node_t *)pLVar4)->super_Links_t).m_Right == uVar7) {
          RotateLeft(this,elem_00);
          if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
             && (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                              Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
          }
          pLVar4 = &Links::lexical_block_0::s_Sentinel;
          if (uVar1 != 0xffff) {
            pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
          }
          uVar7 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
             && (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                              Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
          }
          if (uVar7 == 0xffff) {
            pLVar4 = &Links::lexical_block_0::s_Sentinel;
            pNVar2 = (this->m_Elements).m_pMemory + 0xffff;
          }
          else {
            pNVar2 = (this->m_Elements).m_pMemory + uVar7;
            pLVar4 = &pNVar2->super_Links_t;
          }
          uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        }
        else {
          pNVar2 = (this->m_Elements).m_pMemory + uVar1;
          uVar1 = uVar7;
        }
        (pNVar2->super_Links_t).m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 0;
        RotateRight(this,(ushort)uVar6);
        uVar7 = uVar1;
      }
    }
    else {
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar6 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Left;
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Tag == 0) goto LAB_0026397e;
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar7 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Left == uVar7) {
        RotateRight(this,elem_00);
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar1 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
        }
        uVar7 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        if (uVar7 == 0xffff) {
          pLVar4 = &Links::lexical_block_0::s_Sentinel;
          pNVar2 = (this->m_Elements).m_pMemory + 0xffff;
        }
        else {
          pNVar2 = (this->m_Elements).m_pMemory + uVar7;
          pLVar4 = &pNVar2->super_Links_t;
        }
        uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
      }
      else {
        pNVar2 = (this->m_Elements).m_pMemory + uVar1;
        uVar1 = uVar7;
      }
      (pNVar2->super_Links_t).m_Tag = 1;
      (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 0;
      RotateLeft(this,(ushort)uVar6);
      uVar7 = uVar1;
    }
  } while( true );
}


// CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateLeft  @ 00262ce0
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RotateLeft(CUtlRBTree<unsigned_int,_short_unsigned_int> * this,
   ushort elem) */

void __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateLeft
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,ushort elem)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  Node_t *pNVar4;
  Links_t *pLVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
                    /* Unresolved local var: ushort rightchild@[DW_OP_reg7(EDI)] */
  uVar9 = (uint)elem;
  if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
     (iVar8 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel), iVar8 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel)
    ;
  }
  if (uVar9 == 0xffff) {
    iVar8 = 0xbfff4;
    uVar1 = Links::lexical_block_0::s_Sentinel.m_Right;
  }
  else {
    iVar8 = uVar9 * 0xc;
    uVar1 = (this->m_Elements).m_pMemory[uVar9].super_Links_t.m_Right;
  }
  uVar3 = (uint)uVar1;
  if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
     (iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel), iVar7 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel)
    ;
  }
  if (uVar3 == 0xffff) {
    pNVar4 = (this->m_Elements).m_pMemory;
    iVar7 = 0xbfff4;
    pLVar5 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory;
    iVar7 = uVar3 * 0xc;
    pLVar5 = &pNVar4[uVar3].super_Links_t;
  }
  bVar10 = CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0';
  *(ushort *)((int)&(pNVar4->super_Links_t).m_Right + iVar8) =
       (((Node_t *)pLVar5)->super_Links_t).m_Left;
  if ((bVar10) &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel)
    ;
  }
  pLVar5 = &Links::lexical_block_0::s_Sentinel;
  if (uVar3 != 0xffff) {
    pLVar5 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
  }
  if (pLVar5->m_Left != 0xffff) {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar4 = (this->m_Elements).m_pMemory;
    pLVar5 = &Links::lexical_block_0::s_Sentinel;
    if (uVar3 != 0xffff) {
      pLVar5 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar7);
    }
    pNVar4[pLVar5->m_Left].super_Links_t.m_Parent = elem;
  }
  if (uVar3 != 0xffff) {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar4 = (this->m_Elements).m_pMemory;
    pLVar5 = &Links::lexical_block_0::s_Sentinel;
    if (uVar9 != 0xffff) {
      pLVar5 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar8);
    }
    *(ushort *)((int)&(pNVar4->super_Links_t).m_Parent + iVar7) = pLVar5->m_Parent;
  }
  if (this->m_Root == uVar9) {
    this->m_Root = uVar1;
  }
  else {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar5 = &Links::lexical_block_0::s_Sentinel;
    if (uVar9 != 0xffff) {
      pLVar5 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar8);
    }
    uVar2 = pLVar5->m_Parent;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar4 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (uVar2 != 0xffff) {
      pNVar4 = (this->m_Elements).m_pMemory + uVar2;
    }
    if ((pNVar4->super_Links_t).m_Left == uVar9) {
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pNVar4 = (this->m_Elements).m_pMemory;
      pLVar5 = &Links::lexical_block_0::s_Sentinel;
      if (uVar9 != 0xffff) {
        pLVar5 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar8);
      }
      pNVar4[pLVar5->m_Parent].super_Links_t.m_Left = uVar1;
    }
    else {
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pNVar4 = (this->m_Elements).m_pMemory;
      pLVar5 = &Links::lexical_block_0::s_Sentinel;
      if (uVar9 != 0xffff) {
        pLVar5 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar8);
      }
      pNVar4[pLVar5->m_Parent].super_Links_t.m_Right = uVar1;
    }
  }
  *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7) = elem;
  if (uVar9 != 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar8) = uVar1;
  }
  return;
}


// CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateRight  @ 002632a0
/* DWARF original prototype: void RotateRight(CUtlRBTree<unsigned_int,_short_unsigned_int> * this,
   ushort elem) */

void __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateRight
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,ushort elem)

{
  ushort uVar1;
  ushort uVar2;
  Links_t *pLVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
                    /* Unresolved local var: ushort leftchild@[DW_OP_reg7(EDI)] */
  uVar8 = (uint)elem;
  if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
     (iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel), iVar7 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel)
    ;
  }
  if (uVar8 == 0xffff) {
    iVar7 = 0xbfff4;
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar7 = uVar8 * 0xc;
    pLVar3 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
  }
  uVar1 = (((Node_t *)pLVar3)->super_Links_t).m_Left;
  uVar9 = (uint)uVar1;
  if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel)
    ;
  }
  pNVar5 = (this->m_Elements).m_pMemory;
  if (uVar9 == 0xffff) {
    iVar6 = 0xbfff4;
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    iVar6 = uVar9 * 0xc;
    pLVar3 = &pNVar5[uVar9].super_Links_t;
  }
  *(ushort *)((int)&(pNVar5->super_Links_t).m_Left + iVar7) =
       (((Node_t *)pLVar3)->super_Links_t).m_Right;
  if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel), iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel)
    ;
  }
  pLVar3 = &Links::lexical_block_0::s_Sentinel;
  if (uVar9 != 0xffff) {
    pLVar3 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6);
  }
  if (pLVar3->m_Right != 0xffff) {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
    if (uVar9 != 0xffff) {
      pLVar3 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar6);
    }
    pNVar5[pLVar3->m_Right].super_Links_t.m_Parent = elem;
  }
  if (uVar9 != 0xffff) {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
    if (uVar8 != 0xffff) {
      pLVar3 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
    }
    *(ushort *)((int)&(pNVar5->super_Links_t).m_Parent + iVar6) = pLVar3->m_Parent;
  }
  if (this->m_Root == uVar8) {
    this->m_Root = uVar1;
  }
  else {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
    if (uVar8 != 0xffff) {
      pLVar3 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    uVar2 = pLVar3->m_Parent;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar5 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (uVar2 != 0xffff) {
      pNVar5 = (this->m_Elements).m_pMemory + uVar2;
    }
    if ((pNVar5->super_Links_t).m_Right == uVar8) {
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar3 = &Links::lexical_block_0::s_Sentinel;
      if (uVar8 != 0xffff) {
        pLVar3 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar3->m_Parent].super_Links_t.m_Right = uVar1;
    }
    else {
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar3 = &Links::lexical_block_0::s_Sentinel;
      if (uVar8 != 0xffff) {
        pLVar3 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + iVar7);
      }
      pNVar5[pLVar3->m_Parent].super_Links_t.m_Left = uVar1;
    }
  }
  *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar6) = elem;
  if (uVar8 != 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar7) = uVar1;
  }
  return;
}


