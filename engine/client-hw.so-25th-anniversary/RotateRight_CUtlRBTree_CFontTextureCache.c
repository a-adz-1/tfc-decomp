// CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::RotateRight  @ 001d90d0
/* DWARF original prototype: void
   RotateRight(CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> * this, ushort elem)
    */

void __thiscall
CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::RotateRight
          (CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> *this,ushort elem)

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
  if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
      == '\0') {
    iVar7 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar7 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    if (uVar6 != 0xffff) goto LAB_001d90fb;
    iVar7 = 0x27ffd8;
    pLVar1 = &Links::s_Sentinel;
LAB_001d9106:
    uVar5 = (uint)(((Node_t *)pLVar1)->super_Links_t).m_Left;
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
  }
  else {
    if (uVar6 != 0xffff) {
LAB_001d90fb:
      iVar7 = uVar6 * 0x28;
      pLVar1 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      goto LAB_001d9106;
    }
    uVar5 = (uint)Links::s_Sentinel.m_Left;
    iVar7 = 0x27ffd8;
  }
  if (uVar5 == 0xffff) {
    local_24 = 0x27ffd8;
    *(ushort *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + iVar7 + -0x14) =
         Links::s_Sentinel.m_Right;
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
LAB_001d9458:
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
      if (uVar5 != 0xffff) goto LAB_001d93dc;
    }
    if (Links::s_Sentinel.m_Right != 0xffff) {
LAB_001d927d:
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        pNVar3 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar3 = (this->m_Elements).m_pMemory;
      }
LAB_001d92a0:
      if (uVar5 != 0xffff) {
        pNVar3[*(ushort *)((int)(pNVar3->m_Data).texCoords + local_24 + -0x12)].super_Links_t.
        m_Parent = elem;
        goto LAB_001d92c4;
      }
      pNVar3[Links::s_Sentinel.m_Right].super_Links_t.m_Parent = elem;
    }
  }
  else {
    pNVar3 = (this->m_Elements).m_pMemory;
    local_24 = uVar5 * 0x28;
    *(ushort *)((int)(pNVar3->m_Data).texCoords + iVar7 + -0x14) =
         pNVar3[uVar5].super_Links_t.m_Right;
    if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
        s_Sentinel == '\0') {
      iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar2 != 0) goto LAB_001d9458;
LAB_001d93dc:
      if (*(short *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + local_24 + -0x12) !=
          -1) goto LAB_001d927d;
LAB_001d92c4:
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
                    /* try { // try from 001d967e to 001e9682 has its CatchHandler @ 001d9885 */
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        pNVar3 = (this->m_Elements).m_pMemory;
      }
      else {
        pNVar3 = (this->m_Elements).m_pMemory;
      }
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      if (pNVar3[uVar5].super_Links_t.m_Right != 0xffff) goto LAB_001d92a0;
    }
    pLVar1 = (Links_t *)((int)(pNVar3->m_Data).texCoords + iVar7 + -0x14);
    if (uVar6 == 0xffff) {
      pLVar1 = &Links::s_Sentinel;
    }
    *(ushort *)((int)(pNVar3->m_Data).texCoords + local_24 + -0x10) = pLVar1->m_Parent;
  }
  uVar4 = (ushort)uVar5;
  if (this->m_Root == uVar6) {
    this->m_Root = uVar4;
    goto LAB_001d91fd;
  }
  if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
      == '\0') {
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar2 != 0) {
                    /* try { // try from 001d96d5 to 001e9896 has its CatchHandler @ 001d95e0 */
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) goto LAB_001d91a0;
LAB_001d91a5:
    uVar5 = (uint)pLVar1->m_Parent;
    if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
        s_Sentinel != '\0') goto LAB_001d91b3;
    iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
    if (iVar2 != 0) {
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
      goto LAB_001d91b3;
    }
    if (uVar5 != 0xffff) goto LAB_001d91bf;
LAB_001d957f:
    pLVar1 = &Links::s_Sentinel;
  }
  else {
    if (uVar6 != 0xffff) {
LAB_001d91a0:
      pLVar1 = (Links_t *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + iVar7 + -0x14);
      goto LAB_001d91a5;
    }
                    /* catch() { ... } // from try @ 001d966a with catch @ 001d95e0
                       catch() { ... } // from try @ 001d96d5 with catch @ 001d95e0 */
    uVar5 = (uint)Links::s_Sentinel.m_Parent;
LAB_001d91b3:
    if (uVar5 == 0xffff) goto LAB_001d957f;
LAB_001d91bf:
    pLVar1 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
  }
  if ((((Node_t *)pLVar1)->super_Links_t).m_Right == uVar6) {
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pNVar3 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)(pNVar3->m_Data).texCoords + iVar7 + -0x14);
    }
    pNVar3[pLVar1->m_Parent].super_Links_t.m_Right = uVar4;
  }
  else {
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pNVar3 = (this->m_Elements).m_pMemory;
    pLVar1 = &Links::s_Sentinel;
    if (uVar6 != 0xffff) {
      pLVar1 = (Links_t *)((int)(pNVar3->m_Data).texCoords + iVar7 + -0x14);
    }
    pNVar3[pLVar1->m_Parent].super_Links_t.m_Left = uVar4;
  }
LAB_001d91fd:
  *(ushort *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + local_24 + -0x12) = elem;
  if (uVar6 != 0xffff) {
    *(ushort *)((int)(((this->m_Elements).m_pMemory)->m_Data).texCoords + iVar7 + -0x10) = uVar4;
  }
  return;
}


