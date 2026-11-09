// CUtlRBTree<unsigned_int,_short_unsigned_int>::CreateInsertedNode  @ 00236640
/* DWARF original prototype: ushort CreateInsertedNode(CUtlRBTree<unsigned_int,_short_unsigned_int>
   * this, uint * insert) */

ushort __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::CreateInsertedNode
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,uint *insert)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  Node_t *pNVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  
                    /* Unresolved local var: ushort current@[???]
                       Unresolved local var: ushort parent@[???]
                       Unresolved local var: bool leftchild@[???] */
  uVar7 = (uint)this->m_Root;
  if (uVar7 == 0xffff) {
    bVar1 = false;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory;
    uVar9 = uVar7;
    do {
      uVar7 = uVar9;
      bVar1 = (*this->m_LessFunc)(insert,&pNVar4[uVar7].m_Data);
      if (bVar1) {
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        uVar5 = pNVar4[uVar7].super_Links_t.m_Left;
        bVar1 = true;
      }
      else {
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        uVar5 = pNVar4[uVar7].super_Links_t.m_Right;
        bVar1 = false;
      }
      uVar9 = (uint)uVar5;
    } while (uVar5 != 0xffff);
  }
                    /* Unresolved local var: ushort i@[DW_OP_reg7(EDI)]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: ushort newElem@[???] */
  uVar5 = this->m_FirstFree;
  uVar9 = (uint)uVar5;
  if (uVar9 == 0xffff) {
                    /* Unresolved local var: ushort newElem@[???] */
    uVar9 = (uint)this->m_TotalElements;
    uVar6 = (this->m_Elements).m_NumAllocated;
    if (uVar6 == uVar9) {
      uVar3 = (this->m_Elements).m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((uVar3 == 0) && (uVar3 = 1, uVar6 != 0)) {
        uVar3 = uVar6;
      }
                    /* Unresolved local var: int growSize@[???] */
      pNVar4 = (this->m_Elements).m_pMemory;
      iVar2 = uVar3 + uVar6;
      (this->m_Elements).m_NumAllocated = iVar2;
      if (pNVar4 == (Node_t *)0x0) {
        pNVar4 = malloc(iVar2 * 0xc);
        (this->m_Elements).m_pMemory = pNVar4;
      }
      else {
        pNVar4 = realloc(pNVar4,iVar2 * 0xc);
        uVar6 = (uint)this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar4;
        uVar9 = uVar6;
      }
    }
    else {
      pNVar4 = (this->m_Elements).m_pMemory;
      uVar6 = uVar9;
    }
    uVar5 = (ushort)uVar6;
    this->m_TotalElements = (short)uVar9 + 1;
    pNVar4 = pNVar4 + uVar9;
  }
  else {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar4 = (this->m_Elements).m_pMemory + uVar9;
    this->m_FirstFree = (pNVar4->super_Links_t).m_Right;
  }
  (pNVar4->super_Links_t).m_Parent = (ushort)uVar7;
  (pNVar4->super_Links_t).m_Right = 0xffff;
  (pNVar4->super_Links_t).m_Left = 0xffff;
  (pNVar4->super_Links_t).m_Tag = 0;
  uVar8 = (ushort)uVar9;
  if (uVar7 == 0xffff) {
    this->m_Root = uVar8;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory + uVar7;
    if (bVar1) {
      (pNVar4->super_Links_t).m_Left = uVar8;
    }
    else {
      (pNVar4->super_Links_t).m_Right = uVar8;
    }
  }
  InsertRebalance(this,uVar5);
  this->m_NumElements = this->m_NumElements + 1;
  return uVar8;
}


// CUtlRBTree<unsigned_int,_short_unsigned_int>::Find  @ 00234c90
/* DWARF original prototype: ushort Find(CUtlRBTree<unsigned_int,_short_unsigned_int> * this, uint *
   search) */

ushort __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::Find
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,uint *search)

{
  bool bVar1;
  Node_t *pNVar2;
  int iVar3;
  uint uVar4;
  
                    /* Unresolved local var: ushort current@[???] */
  uVar4 = (uint)this->m_Root;
  if (uVar4 != 0xffff) {
    pNVar2 = (this->m_Elements).m_pMemory;
    do {
      while( true ) {
        bVar1 = (*this->m_LessFunc)(search,&pNVar2[uVar4].m_Data);
        if (bVar1) break;
        bVar1 = (*this->m_LessFunc)(&(this->m_Elements).m_pMemory[uVar4].m_Data,search);
        if (!bVar1) goto LAB_00234d12;
        if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
          iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar3 != 0) {
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
          }
        }
        pNVar2 = (this->m_Elements).m_pMemory;
        uVar4 = (uint)pNVar2[uVar4].super_Links_t.m_Right;
        if (uVar4 == 0xffff) goto LAB_00234d0d;
      }
      if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
        iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel);
        if (iVar3 != 0) {
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
      }
      pNVar2 = (this->m_Elements).m_pMemory;
      uVar4 = (uint)pNVar2[uVar4].super_Links_t.m_Left;
    } while (uVar4 != 0xffff);
  }
LAB_00234d0d:
  uVar4 = 0xffff;
LAB_00234d12:
  return (ushort)uVar4;
}


// CUtlRBTree<unsigned_int,_short_unsigned_int>::InsertRebalance  @ 00235a50
/* DWARF original prototype: void InsertRebalance(CUtlRBTree<unsigned_int,_short_unsigned_int> *
   this, ushort elem) */

void __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::InsertRebalance
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,ushort elem)

{
  ushort uVar1;
  uint uVar2;
  Node_t *pNVar3;
  int iVar4;
  Links_t *pLVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)elem;
  do {
    uVar2 = (uint)this->m_Root;
    if (uVar8 == uVar2) {
LAB_00235ab8:
      (this->m_Elements).m_pMemory[uVar2].super_Links_t.m_Tag = 1;
      return;
    }
    if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar5 = &Links::s_Sentinel;
      if (uVar8 != 0xffff) goto LAB_00235a83;
LAB_00235a8c:
      uVar2 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0') ||
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 == 0))
      goto LAB_00235a98;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
      if (uVar2 == 0xffff) goto LAB_00235de0;
LAB_00235aa4:
      pLVar5 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
    }
    else {
      if (uVar8 != 0xffff) {
LAB_00235a83:
        pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
        goto LAB_00235a8c;
      }
      uVar2 = (uint)Links::s_Sentinel.m_Parent;
LAB_00235a98:
      if (uVar2 != 0xffff) goto LAB_00235aa4;
LAB_00235de0:
      pLVar5 = &Links::s_Sentinel;
    }
    if ((((Node_t *)pLVar5)->super_Links_t).m_Tag != 0) {
      uVar2 = (uint)this->m_Root;
      goto LAB_00235ab8;
    }
                    /* Unresolved local var: ushort parent@[???]
                       Unresolved local var: ushort grandparent@[???] */
    if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
      pLVar5 = &Links::s_Sentinel;
      if (uVar8 != 0xffff) goto LAB_00235aeb;
LAB_00235af4:
      uVar2 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
      }
    }
    else {
      if (uVar8 != 0xffff) {
LAB_00235aeb:
        pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
        goto LAB_00235af4;
      }
      uVar2 = (uint)Links::s_Sentinel.m_Parent;
    }
    if (uVar2 == 0xffff) {
      uVar6 = (uint)Links::s_Sentinel.m_Parent;
      uVar7 = uVar6;
      if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
      goto LAB_00235cf0;
LAB_00235b31:
      if (uVar6 != 0xffff) goto LAB_00235b3d;
LAB_00235cc7:
      pLVar5 = &Links::s_Sentinel;
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      uVar6 = (uint)pNVar3[uVar2].super_Links_t.m_Parent;
      if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
LAB_00235cf0:
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        uVar7 = uVar6;
        if (uVar2 != 0xffff) {
          pNVar3 = (this->m_Elements).m_pMemory;
          goto LAB_00235b1f;
        }
      }
      else {
LAB_00235b1f:
        pLVar5 = &pNVar3[uVar2].super_Links_t;
        uVar7 = uVar6;
      }
      uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
      if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0')
      goto LAB_00235b31;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
        goto LAB_00235b31;
      }
      if (uVar6 == 0xffff) goto LAB_00235cc7;
LAB_00235b3d:
      pLVar5 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
    }
    if ((((Node_t *)pLVar5)->super_Links_t).m_Left == uVar2) {
                    /* Unresolved local var: ushort uncle@[???] */
      if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        if (uVar7 != 0xffff) goto LAB_00235b65;
LAB_00235b6f:
        uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Right;
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
      }
      else {
        if (uVar7 != 0xffff) {
LAB_00235b65:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
          goto LAB_00235b6f;
        }
        uVar6 = (uint)Links::s_Sentinel.m_Right;
      }
      uVar1 = Links::s_Sentinel.m_Tag;
      if (uVar6 != 0xffff) {
        uVar1 = (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag;
      }
      if (uVar1 == 0) {
LAB_00235b9b:
                    /* Unresolved local var: ushort uncle@[???] */
        (this->m_Elements).m_pMemory[uVar2].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar7].super_Links_t.m_Tag = 0;
        uVar8 = uVar7;
      }
      else {
        if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
          }
          pLVar5 = &Links::s_Sentinel;
          if (uVar8 != 0xffff) goto LAB_00235ebb;
LAB_00235ec4:
          uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0')
             || (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                              Links(unsigned_short)::s_Sentinel), iVar4 == 0))
          goto LAB_00235ed0;
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
          if (uVar6 == 0xffff) goto LAB_00236380;
LAB_00235edc:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
        }
        else {
          if (uVar8 != 0xffff) {
LAB_00235ebb:
            pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
            goto LAB_00235ec4;
          }
          uVar6 = (uint)Links::s_Sentinel.m_Parent;
LAB_00235ed0:
          if (uVar6 != 0xffff) goto LAB_00235edc;
LAB_00236380:
          pLVar5 = &Links::s_Sentinel;
        }
        if ((((Node_t *)pLVar5)->super_Links_t).m_Right == uVar8) {
          RotateLeft(this,(ushort)uVar2);
          if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
            iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel);
            if (iVar4 != 0) {
              Links::s_Sentinel.m_Left = 0xffff;
              Links::s_Sentinel.m_Right = 0xffff;
              Links::s_Sentinel.m_Parent = 0xffff;
              __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel);
            }
            pLVar5 = &Links::s_Sentinel;
            if (uVar2 != 0xffff) goto LAB_002361cf;
LAB_002361d8:
            uVar8 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
            if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
               && (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                                Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
              Links::s_Sentinel.m_Left = 0xffff;
              Links::s_Sentinel.m_Right = 0xffff;
              Links::s_Sentinel.m_Parent = 0xffff;
              __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel);
            }
          }
          else {
            if (uVar2 != 0xffff) {
LAB_002361cf:
              pLVar5 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
              goto LAB_002361d8;
            }
            uVar8 = (uint)Links::s_Sentinel.m_Parent;
          }
          if (uVar8 == 0xffff) {
            pLVar5 = &Links::s_Sentinel;
            pNVar3 = (this->m_Elements).m_pMemory + 0xffff;
          }
          else {
            pNVar3 = (this->m_Elements).m_pMemory + uVar8;
            pLVar5 = &pNVar3->super_Links_t;
          }
          uVar7 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + uVar2;
          uVar2 = uVar8;
        }
        (pNVar3->super_Links_t).m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar7].super_Links_t.m_Tag = 0;
        RotateRight(this,(ushort)uVar7);
        uVar8 = uVar2;
      }
    }
    else {
      if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        if (uVar7 != 0xffff) goto LAB_00235be4;
LAB_00235bee:
        uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Left;
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar4 == 0))
        goto LAB_00235bf9;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
        if (uVar6 == 0xffff) goto LAB_00235fc0;
LAB_00235c05:
        pLVar5 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      }
      else {
        if (uVar7 != 0xffff) {
LAB_00235be4:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
          goto LAB_00235bee;
        }
        uVar6 = (uint)Links::s_Sentinel.m_Left;
LAB_00235bf9:
        if (uVar6 != 0xffff) goto LAB_00235c05;
LAB_00235fc0:
        pLVar5 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar5)->super_Links_t).m_Tag == 0) goto LAB_00235b9b;
      if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                               s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        if (uVar8 != 0xffff) goto LAB_00235c30;
LAB_00235c39:
        uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
        if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar4 == 0))
        goto LAB_00235c45;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
        if (uVar6 == 0xffff) goto LAB_00236270;
LAB_00235c51:
        if ((this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Left != uVar8) goto LAB_00235c65;
LAB_00236280:
        RotateRight(this,(ushort)uVar2);
        if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
          }
          pLVar5 = &Links::s_Sentinel;
          if (uVar2 != 0xffff) goto LAB_002362a7;
LAB_002362b0:
          uVar8 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
          if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
             && (iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                              Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
          }
        }
        else {
          if (uVar2 != 0xffff) {
LAB_002362a7:
            pLVar5 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
            goto LAB_002362b0;
          }
          uVar8 = (uint)Links::s_Sentinel.m_Parent;
        }
        if (uVar8 == 0xffff) {
          pLVar5 = &Links::s_Sentinel;
          pNVar3 = (this->m_Elements).m_pMemory + 0xffff;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + uVar8;
          pLVar5 = &pNVar3->super_Links_t;
        }
        uVar7 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
      }
      else {
        if (uVar8 != 0xffff) {
LAB_00235c30:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
          goto LAB_00235c39;
        }
        uVar6 = (uint)Links::s_Sentinel.m_Parent;
LAB_00235c45:
        if (uVar6 != 0xffff) goto LAB_00235c51;
LAB_00236270:
        if (Links::s_Sentinel.m_Left == uVar8) goto LAB_00236280;
LAB_00235c65:
        pNVar3 = (this->m_Elements).m_pMemory + uVar2;
        uVar2 = uVar8;
      }
      (pNVar3->super_Links_t).m_Tag = 1;
      (this->m_Elements).m_pMemory[uVar7].super_Links_t.m_Tag = 0;
      RotateLeft(this,(ushort)uVar7);
      uVar8 = uVar2;
    }
  } while( true );
}


// CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateLeft  @ 00234db0
/* DWARF original prototype: void RotateLeft(CUtlRBTree<unsigned_int,_short_unsigned_int> * this,
   ushort elem) */

void __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateLeft
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,ushort elem)

{
  Links_t *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  bool bVar9;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: ushort rightchild@[???] */
  uVar6 = (uint)elem;
  local_24._0_1_ = CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel;
  if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    local_24._0_1_ = CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_00234ddf;
    local_28 = 0xbfff4;
    pLVar1 = &Links::s_Sentinel;
LAB_00234dee:
    uVar8 = (uint)(((Node_t *)pLVar1)->super_Links_t).m_Right;
    if ((char)local_24 != '\0') goto LAB_00234dfd;
    CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel = (char)local_24;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    local_24._0_1_ = CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel;
    if (uVar8 == 0xffff) goto LAB_00234f00;
    pNVar5 = (this->m_Elements).m_pMemory;
    iVar3 = uVar8 * 0xc;
    bVar9 = CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0';
    *(ushort *)((int)&(pNVar5->super_Links_t).m_Right + local_28) =
         pNVar5[uVar8].super_Links_t.m_Left;
    if (bVar9) goto LAB_00234e24;
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar2 != 0) goto LAB_0023527c;
LAB_0023506d:
    uVar7 = (ushort)uVar8;
    if (*(short *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar3) != -1) {
LAB_00234f3c:
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
        pNVar5 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar5 = (this->m_Elements).m_pMemory;
      }
LAB_00234f5f:
      uVar7 = (ushort)uVar8;
      if (uVar8 == 0xffff) {
        pNVar5[Links::s_Sentinel.m_Left].super_Links_t.m_Parent = elem;
        iVar2 = iVar3;
        goto LAB_00234e53;
      }
      pNVar5[*(ushort *)((int)&(pNVar5->super_Links_t).m_Left + iVar3)].super_Links_t.m_Parent =
           elem;
    }
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
      pNVar5 = (this->m_Elements).m_pMemory;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
    }
LAB_00234e36:
    pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_28);
    if (uVar6 == 0xffff) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(ushort *)((int)&(pNVar5->super_Links_t).m_Parent + iVar3) = pLVar1->m_Parent;
    iVar2 = iVar3;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_00234ddf:
      local_28 = uVar6 * 0xc;
      pLVar1 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      local_24._0_1_ = CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel;
      goto LAB_00234dee;
    }
    uVar8 = (uint)Links::s_Sentinel.m_Right;
    local_28 = 0xbfff4;
LAB_00234dfd:
    if (uVar8 != 0xffff) {
      pNVar5 = (this->m_Elements).m_pMemory;
      iVar3 = uVar8 * 0xc;
      CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel = (char)local_24;
      *(ushort *)((int)&(pNVar5->super_Links_t).m_Right + local_28) =
           pNVar5[uVar8].super_Links_t.m_Left;
LAB_00234e24:
      uVar7 = (ushort)uVar8;
      pNVar5 = (this->m_Elements).m_pMemory;
      if (*(short *)((int)&(pNVar5->super_Links_t).m_Left + iVar3) != -1) goto LAB_00234f5f;
      goto LAB_00234e36;
    }
LAB_00234f00:
    CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel = (char)local_24;
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + local_28) =
         Links::s_Sentinel.m_Left;
    iVar2 = 0xbfff4;
    if ((char)local_24 == '\0') {
      local_24 = 0xbfff4;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel);
      iVar3 = 0xbfff4;
      iVar2 = local_24;
      if (iVar4 != 0) {
LAB_0023527c:
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
        iVar2 = iVar3;
        if (uVar8 != 0xffff) goto LAB_0023506d;
      }
    }
    uVar7 = (ushort)uVar8;
    iVar3 = iVar2;
    if (Links::s_Sentinel.m_Left != 0xffff) goto LAB_00234f3c;
  }
LAB_00234e53:
  if (this->m_Root == uVar6) {
    this->m_Root = uVar7;
    goto LAB_00234ed8;
  }
  if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_00234e7a;
LAB_00234e83:
    uVar8 = (uint)pLVar1->m_Parent;
    if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0')
    goto LAB_00234e8f;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
      goto LAB_00234e8f;
    }
    if (uVar8 != 0xffff) goto LAB_00234e9b;
LAB_002351ff:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_00234e7a:
      pLVar1 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + local_28);
      goto LAB_00234e83;
    }
    uVar8 = (uint)Links::s_Sentinel.m_Parent;
LAB_00234e8f:
    if (uVar8 == 0xffff) goto LAB_002351ff;
LAB_00234e9b:
    pLVar1 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
  }
  if ((((Node_t *)pLVar1)->super_Links_t).m_Left == uVar6) {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_28);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Left = uVar7;
  }
  else {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar3 != 0)) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)&(pNVar5->super_Links_t).m_Left + local_28);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Right = uVar7;
  }
LAB_00234ed8:
  *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2) = elem;
  if (uVar6 != 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + local_28) = uVar7;
  }
  return;
}


// CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateRight  @ 00235420
/* DWARF original prototype: void RotateRight(CUtlRBTree<unsigned_int,_short_unsigned_int> * this,
   ushort elem) */

void __thiscall
CUtlRBTree<unsigned_int,_short_unsigned_int>::RotateRight
          (CUtlRBTree<unsigned_int,_short_unsigned_int> *this,ushort elem)

{
  Links_t *pLVar1;
  int iVar2;
  Node_t *pNVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_24;
  
                    /* Unresolved local var: ushort leftchild@[???] */
  uVar6 = (uint)elem;
  if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
    iVar7 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar7 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    if (uVar6 != 0xffff) goto LAB_0023544b;
    iVar7 = 0xbfff4;
    pLVar1 = &Links::s_Sentinel;
LAB_00235456:
    uVar5 = (uint)(((Node_t *)pLVar1)->super_Links_t).m_Left;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
  }
  else {
    if (uVar6 != 0xffff) {
LAB_0023544b:
      iVar7 = uVar6 * 0xc;
      pLVar1 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      goto LAB_00235456;
    }
    uVar5 = (uint)Links::s_Sentinel.m_Left;
    iVar7 = 0xbfff4;
  }
  if (uVar5 == 0xffff) {
    local_24 = 0xbfff4;
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7) =
         Links::s_Sentinel.m_Right;
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar2 != 0)) {
LAB_002357a8:
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
      if (uVar5 != 0xffff) goto LAB_0023572c;
    }
    if (Links::s_Sentinel.m_Right != 0xffff) {
LAB_002355cd:
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
        pNVar3 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar3 = (this->m_Elements).m_pMemory;
      }
LAB_002355f0:
      if (uVar5 != 0xffff) {
        pNVar3[*(ushort *)((int)&(pNVar3->super_Links_t).m_Right + local_24)].super_Links_t.m_Parent
             = elem;
        goto LAB_00235614;
      }
      pNVar3[Links::s_Sentinel.m_Right].super_Links_t.m_Parent = elem;
    }
  }
  else {
    pNVar3 = (this->m_Elements).m_pMemory;
    local_24 = uVar5 * 0xc;
    *(ushort *)((int)&(pNVar3->super_Links_t).m_Left + iVar7) = pNVar3[uVar5].super_Links_t.m_Right;
    if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                   s_Sentinel);
      if (iVar2 != 0) goto LAB_002357a8;
LAB_0023572c:
      if (*(short *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + local_24) != -1
         ) goto LAB_002355cd;
LAB_00235614:
      if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                             s_Sentinel);
        pNVar3 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar3 = (this->m_Elements).m_pMemory;
      }
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      if (pNVar3[uVar5].super_Links_t.m_Right != 0xffff) goto LAB_002355f0;
    }
    pLVar1 = (Links_t *)((int)&(pNVar3->super_Links_t).m_Left + iVar7);
    if (uVar6 == 0xffff) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(ushort *)((int)&(pNVar3->super_Links_t).m_Parent + local_24) = pLVar1->m_Parent;
  }
  uVar4 = (ushort)uVar5;
  if (this->m_Root == uVar6) {
    this->m_Root = uVar4;
    goto LAB_0023554d;
  }
  if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_002354f0;
LAB_002354f5:
    uVar5 = (uint)pLVar1->m_Parent;
    if (CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel != '\0')
    goto LAB_00235503;
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                                 s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
      goto LAB_00235503;
    }
    if (uVar5 != 0xffff) goto LAB_0023550f;
LAB_002358cf:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_002354f0:
      pLVar1 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
      goto LAB_002354f5;
    }
    uVar5 = (uint)Links::s_Sentinel.m_Parent;
LAB_00235503:
    if (uVar5 == 0xffff) goto LAB_002358cf;
LAB_0023550f:
    pLVar1 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
  }
  if ((((Node_t *)pLVar1)->super_Links_t).m_Right == uVar6) {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar3 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)&(pNVar3->super_Links_t).m_Left + iVar7);
    }
    pNVar3[pLVar1->m_Parent].super_Links_t.m_Right = uVar4;
  }
  else {
    if ((CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)
                                     ::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<unsigned_int,unsigned_short>::Links(unsigned_short)::
                           s_Sentinel);
    }
    pNVar3 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)&(pNVar3->super_Links_t).m_Left + iVar7);
    }
    pNVar3[pLVar1->m_Parent].super_Links_t.m_Left = uVar4;
  }
LAB_0023554d:
  *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + local_24) = elem;
  if (uVar6 != 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar7) = uVar4;
  }
  return;
}


