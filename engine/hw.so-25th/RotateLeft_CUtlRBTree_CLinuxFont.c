// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::RotateLeft  @ 001ddc50
/* DWARF original prototype: void RotateLeft(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>
   * this, ushort elem) */

void __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::RotateLeft
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,ushort elem)

{
  Node_t *pNVar1;
  Links_t *pLVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  bool bVar10;
  Node_t *local_24;
  
                    /* Unresolved local var: ushort rightchild@[???] */
  uVar6 = (uint)elem;
  local_24._0_1_ =
       CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel;
  if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
  {
    iVar7 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar7 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    local_24._0_1_ =
         CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_001ddc7f;
    iVar7 = 0xffff0;
    pLVar2 = &Links::s_Sentinel;
LAB_001ddc89:
    uVar9 = (uint)(((Node_t *)pLVar2)->super_Links_t).m_Right;
    if ((char)local_24 != '\0') goto LAB_001ddc98;
    CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel =
         (char)local_24;
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar4 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    local_24._0_1_ =
         CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel;
    if (uVar9 == 0xffff) goto LAB_001ddd90;
    iVar4 = uVar9 * 0x10;
    bVar10 = CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             != '\0';
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar7) =
         (this->m_Elements).m_pMemory[uVar9].super_Links_t.m_Left;
    if (bVar10) goto LAB_001ddcb5;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar3 != 0) goto LAB_001de104;
LAB_001ddef6:
    uVar8 = (ushort)uVar9;
    if (*(short *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar4) != -1) {
LAB_001dddc8:
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        Links::s_Sentinel.m_Left = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        local_24 = (this->m_Elements).m_pMemory;
      }
      else {
        local_24 = (this->m_Elements).m_pMemory;
      }
LAB_001dddef:
      uVar8 = (ushort)uVar9;
      if (uVar9 == 0xffff) {
        local_24[Links::s_Sentinel.m_Left].super_Links_t.m_Parent = elem;
        pNVar5 = (Node_t *)iVar4;
        goto LAB_001ddcec;
      }
      local_24[*(ushort *)((int)&(local_24->super_Links_t).m_Left + iVar4)].super_Links_t.m_Parent =
           elem;
    }
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
      local_24 = (this->m_Elements).m_pMemory;
    }
    else {
      local_24 = (this->m_Elements).m_pMemory;
    }
LAB_001ddccb:
    pLVar2 = (Links_t *)((int)&(local_24->super_Links_t).m_Left + iVar7);
    if (uVar6 == 0xffff) {
      pLVar2 = &Links::s_Sentinel;
    }
    *(ushort *)((int)&(local_24->super_Links_t).m_Parent + iVar4) = pLVar2->m_Parent;
    pNVar5 = (Node_t *)iVar4;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_001ddc7f:
      iVar7 = uVar6 * 0x10;
      pLVar2 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      local_24._0_1_ =
           CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel;
      goto LAB_001ddc89;
    }
    uVar9 = (uint)Links::s_Sentinel.m_Right;
    iVar7 = 0xffff0;
LAB_001ddc98:
    if (uVar9 != 0xffff) {
      pNVar5 = (this->m_Elements).m_pMemory;
      iVar4 = uVar9 * 0x10;
      CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel =
           (char)local_24;
      *(ushort *)((int)&(pNVar5->super_Links_t).m_Right + iVar7) =
           pNVar5[uVar9].super_Links_t.m_Left;
LAB_001ddcb5:
      uVar8 = (ushort)uVar9;
      local_24 = (this->m_Elements).m_pMemory;
      if (*(short *)((int)&(local_24->super_Links_t).m_Left + iVar4) != -1) goto LAB_001dddef;
      goto LAB_001ddccb;
    }
LAB_001ddd90:
    CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel =
         (char)local_24;
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar7) =
         Links::s_Sentinel.m_Left;
    pNVar5 = (Node_t *)0xffff0;
    if ((char)local_24 == '\0') {
      local_24 = (Node_t *)0xffff0;
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      iVar4 = 0xffff0;
      pNVar5 = local_24;
      if (iVar3 != 0) {
LAB_001de104:
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        pNVar5 = (Node_t *)iVar4;
        if (uVar9 != 0xffff) goto LAB_001ddef6;
      }
    }
    uVar8 = (ushort)uVar9;
    iVar4 = (int)pNVar5;
    if (Links::s_Sentinel.m_Left != 0xffff) goto LAB_001dddc8;
  }
LAB_001ddcec:
  if (this->m_Root == uVar6) {
    this->m_Root = uVar8;
    goto LAB_001ddd67;
  }
  if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
  {
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar4 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar2 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_001ddd13;
LAB_001ddd18:
    uVar9 = (uint)pLVar2->m_Parent;
    if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel !=
        '\0') goto LAB_001ddd24;
    iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar4 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
      goto LAB_001ddd24;
    }
    if (uVar9 != 0xffff) goto LAB_001ddd30;
LAB_001de087:
    pLVar2 = &Links::s_Sentinel;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_001ddd13:
      pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
      goto LAB_001ddd18;
    }
    uVar9 = (uint)Links::s_Sentinel.m_Parent;
LAB_001ddd24:
    if (uVar9 == 0xffff) goto LAB_001de087;
LAB_001ddd30:
    pLVar2 = &(this->m_Elements).m_pMemory[uVar9].super_Links_t;
  }
  if ((((Node_t *)pLVar2)->super_Links_t).m_Left == uVar6) {
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
    }
    pNVar1[pLVar2->m_Parent].super_Links_t.m_Left = uVar8;
  }
  else {
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
      Links::s_Sentinel.m_Parent = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
    }
    pNVar1[pLVar2->m_Parent].super_Links_t.m_Right = uVar8;
  }
LAB_001ddd67:
  *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + (int)pNVar5) = elem;
  if (uVar6 != 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar7) = uVar8;
  }
  return;
}


