// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::RotateRight  @ 001de2b0
/* DWARF original prototype: void
   RotateRight(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> * this, ushort elem) */

void __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::RotateRight
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,ushort elem)

{
  Node_t *pNVar1;
  Links_t *pLVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  Node_t *local_24;
  
                    /* Unresolved local var: ushort leftchild@[???] */
  uVar5 = (uint)elem;
  if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
  {
    iVar6 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar6 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    if (uVar5 != 0xffff) goto LAB_001de2db;
    iVar6 = 0xffff0;
    pLVar2 = &Links::s_Sentinel;
LAB_001de2e5:
    uVar8 = (uint)(((Node_t *)pLVar2)->super_Links_t).m_Left;
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
  }
  else {
    if (uVar5 != 0xffff) {
LAB_001de2db:
      iVar6 = uVar5 * 0x10;
      pLVar2 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      goto LAB_001de2e5;
    }
    uVar8 = (uint)Links::s_Sentinel.m_Left;
    iVar6 = 0xffff0;
  }
  if (uVar8 == 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6) =
         Links::s_Sentinel.m_Right;
    iVar4 = 0xffff0;
    if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
        '\0') {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      iVar4 = 0xffff0;
      if (iVar3 != 0) goto LAB_001de630;
    }
LAB_001de428:
    if (Links::s_Sentinel.m_Right != 0xffff) {
LAB_001de441:
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        local_24 = (this->m_Elements).m_pMemory;
      }
      else {
        local_24 = (this->m_Elements).m_pMemory;
      }
LAB_001de468:
      if (uVar8 != 0xffff) {
        local_24[*(ushort *)((int)&(local_24->super_Links_t).m_Right + iVar4)].super_Links_t.
        m_Parent = elem;
        goto LAB_001de48c;
      }
      local_24[Links::s_Sentinel.m_Right].super_Links_t.m_Parent = elem;
    }
  }
  else {
    pNVar1 = (this->m_Elements).m_pMemory;
    iVar4 = uVar8 * 0x10;
    *(ushort *)((int)&(pNVar1->super_Links_t).m_Left + iVar6) = pNVar1[uVar8].super_Links_t.m_Right;
    if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
        '\0') {
      iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar3 != 0) {
LAB_001de630:
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        if (uVar8 == 0xffff) goto LAB_001de428;
      }
      if (*(short *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar4) != -1)
      goto LAB_001de441;
LAB_001de48c:
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        local_24 = (this->m_Elements).m_pMemory;
      }
      else {
        local_24 = (this->m_Elements).m_pMemory;
      }
    }
    else {
      local_24 = (this->m_Elements).m_pMemory;
      if (local_24[uVar8].super_Links_t.m_Right != 0xffff) goto LAB_001de468;
    }
    pLVar2 = (Links_t *)((int)&(local_24->super_Links_t).m_Left + iVar6);
    if (uVar5 == 0xffff) {
      pLVar2 = &Links::s_Sentinel;
    }
    *(ushort *)((int)&(local_24->super_Links_t).m_Parent + iVar4) = pLVar2->m_Parent;
  }
  uVar7 = (ushort)uVar8;
  if (this->m_Root == uVar5) {
    this->m_Root = uVar7;
    goto LAB_001de3cf;
  }
  if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel == '\0')
  {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pLVar2 = &Links::s_Sentinel;
    if (uVar5 != 0xffff) goto LAB_001de379;
LAB_001de37e:
    uVar8 = (uint)pLVar2->m_Parent;
    if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel !=
        '\0') goto LAB_001de38a;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
      goto LAB_001de38a;
    }
    if (uVar8 != 0xffff) goto LAB_001de396;
LAB_001de767:
    pLVar2 = &Links::s_Sentinel;
  }
  else {
    if (uVar5 != 0xffff) {
LAB_001de379:
      pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6);
      goto LAB_001de37e;
    }
    uVar8 = (uint)Links::s_Sentinel.m_Parent;
LAB_001de38a:
    if (uVar8 == 0xffff) goto LAB_001de767;
LAB_001de396:
    pLVar2 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
  }
  if ((((Node_t *)pLVar2)->super_Links_t).m_Right == uVar5) {
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::s_Sentinel;
    if (uVar5 != 0xffff) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar6);
    }
    pNVar1[pLVar2->m_Parent].super_Links_t.m_Right = uVar7;
  }
  else {
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::s_Sentinel;
    if (uVar5 != 0xffff) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar6);
    }
    pNVar1[pLVar2->m_Parent].super_Links_t.m_Left = uVar7;
  }
LAB_001de3cf:
  *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar4) = elem;
  if (uVar5 != 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar6) = uVar7;
  }
  return;
}


