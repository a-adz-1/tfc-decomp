// CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::RotateLeft  @ 001d8a60
/* DWARF original prototype: void
   RotateLeft(CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> * this, ushort elem)
    */

void __thiscall
CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::RotateLeft
          (CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> *this,ushort elem)

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
  local_24._0_1_ =
       CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
  ;
  if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
      == '\0') {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    local_24._0_1_ =
         CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_001d8a8f;
    local_28 = 0x27ffd8;
    pLVar1 = &Links::s_Sentinel;
LAB_001d8a9e:
    uVar8 = (uint)(((Node_t *)pLVar1)->super_Links_t).m_Right;
    if ((char)local_24 != '\0') goto LAB_001d8aad;
    CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel =
         (char)local_24;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    local_24._0_1_ =
         CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel;
    if (uVar8 == 0xffff) goto LAB_001d8bb0;
    pNVar5 = (this->m_Elements).m_pMemory;
    iVar3 = uVar8 * 0x28;
    bVar9 = CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
            s_Sentinel != '\0';
    *(ushort *)((int)(pNVar5->m_Data).texCoords + local_28 + -0x12) =
         pNVar5[uVar8].super_Links_t.m_Left;
    if (bVar9) goto LAB_001d8ad4;
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar2 != 0) goto LAB_001d8f2c;
LAB_001d8d1d:
    uVar7 = (ushort)uVar8;
    if (*(short *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + iVar3 + -0x14) != -1) {
LAB_001d8bec:
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        pNVar5 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar5 = (this->m_Elements).m_pMemory;
      }
LAB_001d8c0f:
      uVar7 = (ushort)uVar8;
      if (uVar8 == 0xffff) {
        pNVar5[Links::s_Sentinel.m_Left].super_Links_t.m_Parent = elem;
        iVar2 = iVar3;
        goto LAB_001d8b03;
      }
      pNVar5[*(ushort *)((int)(pNVar5->m_Data).texCoords + iVar3 + -0x14)].super_Links_t.m_Parent =
           elem;
    }
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
      pNVar5 = (this->m_Elements).m_pMemory;
    }
    else {
      pNVar5 = (this->m_Elements).m_pMemory;
    }
LAB_001d8ae6:
    pLVar1 = (Links_t *)((int)(pNVar5->m_Data).texCoords + local_28 + -0x14);
    if (uVar6 == 0xffff) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(ushort *)((int)(pNVar5->m_Data).texCoords + iVar3 + -0x10) = pLVar1->m_Parent;
    iVar2 = iVar3;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_001d8a8f:
      local_28 = uVar6 * 0x28;
      pLVar1 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      local_24._0_1_ =
           CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel;
      goto LAB_001d8a9e;
    }
    uVar8 = (uint)Links::s_Sentinel.m_Right;
    local_28 = 0x27ffd8;
LAB_001d8aad:
    if (uVar8 != 0xffff) {
      pNVar5 = (this->m_Elements).m_pMemory;
      iVar3 = uVar8 * 0x28;
      CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
           = (char)local_24;
      *(ushort *)((int)(pNVar5->m_Data).texCoords + local_28 + -0x12) =
           pNVar5[uVar8].super_Links_t.m_Left;
LAB_001d8ad4:
      uVar7 = (ushort)uVar8;
      pNVar5 = (this->m_Elements).m_pMemory;
      if (*(short *)((int)(pNVar5->m_Data).texCoords + iVar3 + -0x14) != -1) goto LAB_001d8c0f;
      goto LAB_001d8ae6;
    }
LAB_001d8bb0:
    CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel =
         (char)local_24;
    *(ushort *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + local_28 + -0x12) =
         Links::s_Sentinel.m_Left;
    iVar2 = 0x27ffd8;
    if ((char)local_24 == '\0') {
      local_24 = 0x27ffd8;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      iVar3 = 0x27ffd8;
      iVar2 = local_24;
      if (iVar4 != 0) {
LAB_001d8f2c:
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        iVar2 = iVar3;
        if (uVar8 != 0xffff) goto LAB_001d8d1d;
      }
    }
    uVar7 = (ushort)uVar8;
    iVar3 = iVar2;
    if (Links::s_Sentinel.m_Left != 0xffff) goto LAB_001d8bec;
  }
LAB_001d8b03:
  if (this->m_Root == uVar6) {
    this->m_Root = uVar7;
    goto LAB_001d8b88;
  }
  if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
      == '\0') {
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_001d8b2a;
LAB_001d8b33:
    uVar8 = (uint)pLVar1->m_Parent;
    if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
        s_Sentinel != '\0') goto LAB_001d8b3f;
    iVar3 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar3 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
      goto LAB_001d8b3f;
    }
    if (uVar8 != 0xffff) goto LAB_001d8b4b;
LAB_001d8eaf:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_001d8b2a:
      pLVar1 = (Links_t *)
               ((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + local_28 + -0x14);
      goto LAB_001d8b33;
    }
    uVar8 = (uint)Links::s_Sentinel.m_Parent;
LAB_001d8b3f:
    if (uVar8 == 0xffff) goto LAB_001d8eaf;
LAB_001d8b4b:
    pLVar1 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
  }
  if ((((Node_t *)pLVar1)->super_Links_t).m_Left == uVar6) {
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)(pNVar5->m_Data).texCoords + local_28 + -0x14);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Left = uVar7;
  }
  else {
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)(pNVar5->m_Data).texCoords + local_28 + -0x14);
    }
    pNVar5[pLVar1->m_Parent].super_Links_t.m_Right = uVar7;
  }
LAB_001d8b88:
  *(ushort *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + iVar2 + -0x14) = elem;
  if (uVar6 != 0xffff) {
    *(ushort *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + local_28 + -0x10) = uVar7;
  }
  return;
}


