// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::InsertRebalance  @ 00227e10
/* DWARF original prototype: void
   InsertRebalance(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> * this, ushort elem) */

void __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::InsertRebalance
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,ushort elem)

{
  ushort elem_00;
  uint uVar1;
  Node_t *pNVar2;
  int iVar3;
  Links_t *pLVar4;
  uint uVar5;
  uint uVar6;
  uint local_20;
  
  uVar6 = (uint)elem;
  do {
                    /* Unresolved local var: ushort parent@[???]
                       Unresolved local var: ushort grandparent@[???]
                       Unresolved local var: ushort uncle@[DW_OP_reg2(EDX)] */
    uVar1 = (uint)this->m_Root;
    if (uVar6 == uVar1) {
LAB_00227e7c:
      (this->m_Elements).m_pMemory[uVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
    }
    uVar1 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    if ((((Node_t *)pLVar4)->super_Links_t).m_Tag != 0) {
      uVar1 = (uint)this->m_Root;
      goto LAB_00227e7c;
    }
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
    }
    elem_00 = (((Node_t *)pLVar4)->super_Links_t).m_Parent;
    uVar1 = (uint)elem_00;
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    local_20 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar5 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
    }
                    /* Unresolved local var: ushort uncle@[DW_OP_reg2(EDX)] */
    if ((((Node_t *)pLVar4)->super_Links_t).m_Left == uVar1) {
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (local_20 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[local_20].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Right;
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Tag == 0) {
LAB_00227f83:
        (this->m_Elements).m_pMemory[uVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar5].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[local_20].super_Links_t.m_Tag = 0;
        uVar6 = local_20;
      }
      else {
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar6 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
        }
        uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar5 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
        }
        if ((((Node_t *)pLVar4)->super_Links_t).m_Right == uVar6) {
          RotateLeft(this,elem_00);
          if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
               == '\0') &&
             (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                           Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          pLVar4 = &Links::lexical_block_0::s_Sentinel;
          if (uVar1 != 0xffff) {
            pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
          }
          uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
               == '\0') &&
             (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                           Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          if (uVar6 == 0xffff) {
            pNVar2 = (this->m_Elements).m_pMemory + 0xffff;
            pLVar4 = &Links::lexical_block_0::s_Sentinel;
          }
          else {
            pNVar2 = (this->m_Elements).m_pMemory + uVar6;
            pLVar4 = &pNVar2->super_Links_t;
          }
          local_20 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        }
        else {
          pNVar2 = (this->m_Elements).m_pMemory + uVar1;
          uVar1 = uVar6;
        }
        (pNVar2->super_Links_t).m_Tag = 1;
        (this->m_Elements).m_pMemory[local_20].super_Links_t.m_Tag = 0;
        RotateRight(this,(ushort)local_20);
        uVar6 = uVar1;
      }
    }
    else {
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (local_20 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[local_20].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Left;
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Tag == 0) goto LAB_00227f83;
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar6 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Left == uVar6) {
        RotateRight(this,elem_00);
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar1 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
        }
        uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        if (uVar6 == 0xffff) {
          pNVar2 = (this->m_Elements).m_pMemory + 0xffff;
          pLVar4 = &Links::lexical_block_0::s_Sentinel;
        }
        else {
          pNVar2 = (this->m_Elements).m_pMemory + uVar6;
          pLVar4 = &pNVar2->super_Links_t;
        }
        local_20 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
      }
      else {
        pNVar2 = (this->m_Elements).m_pMemory + uVar1;
        uVar1 = uVar6;
      }
      (pNVar2->super_Links_t).m_Tag = 1;
      (this->m_Elements).m_pMemory[local_20].super_Links_t.m_Tag = 0;
      RotateLeft(this,(ushort)local_20);
      uVar6 = uVar1;
    }
  } while( true );
}


