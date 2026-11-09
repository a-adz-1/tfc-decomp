// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::RotateLeft  @ 002272f0
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RotateLeft(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>
   * this, ushort elem) */

void __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::RotateLeft
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,ushort elem)

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
  if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0'
      ) && (iVar8 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar8 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::
                         s_Sentinel);
  }
  if (uVar9 == 0xffff) {
    iVar8 = 0xffff0;
    uVar1 = Links::lexical_block_0::s_Sentinel.m_Right;
  }
  else {
    iVar8 = uVar9 * 0x10;
    uVar1 = (this->m_Elements).m_pMemory[uVar9].super_Links_t.m_Right;
  }
  uVar3 = (uint)uVar1;
  if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0'
      ) && (iVar7 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar7 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::
                         s_Sentinel);
  }
  if (uVar3 == 0xffff) {
    pNVar4 = (this->m_Elements).m_pMemory;
    iVar7 = 0xffff0;
    pLVar5 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory;
    iVar7 = uVar3 * 0x10;
    pLVar5 = &pNVar4[uVar3].super_Links_t;
  }
  bVar10 = CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0';
  *(ushort *)((int)&(pNVar4->super_Links_t).m_Right + iVar8) =
       (((Node_t *)pLVar5)->super_Links_t).m_Left;
  if ((bVar10) &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::
                         s_Sentinel);
  }
  pLVar5 = &Links::lexical_block_0::s_Sentinel;
  if (uVar3 != 0xffff) {
    pLVar5 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
  }
  if (pLVar5->m_Left != 0xffff) {
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pNVar4 = (this->m_Elements).m_pMemory;
    pLVar5 = &Links::lexical_block_0::s_Sentinel;
    if (uVar3 != 0xffff) {
      pLVar5 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar7);
    }
    pNVar4[pLVar5->m_Left].super_Links_t.m_Parent = elem;
  }
  if (uVar3 != 0xffff) {
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
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
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar5 = &Links::lexical_block_0::s_Sentinel;
    if (uVar9 != 0xffff) {
      pLVar5 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar8);
    }
    uVar2 = pLVar5->m_Parent;
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pNVar4 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (uVar2 != 0xffff) {
      pNVar4 = (this->m_Elements).m_pMemory + uVar2;
    }
    if ((pNVar4->super_Links_t).m_Left == uVar9) {
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pNVar4 = (this->m_Elements).m_pMemory;
      pLVar5 = &Links::lexical_block_0::s_Sentinel;
      if (uVar9 != 0xffff) {
        pLVar5 = (Links_t *)((int)&(pNVar4->super_Links_t).m_Left + iVar8);
      }
      pNVar4[pLVar5->m_Parent].super_Links_t.m_Left = uVar1;
    }
    else {
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar6 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
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


