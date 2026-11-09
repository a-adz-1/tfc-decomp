// CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::RotateRight  @ 00223090
/* DWARF original prototype: void
   RotateRight(CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> * this, ushort elem)
    */

void __thiscall
CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::RotateRight
          (CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> *this,ushort elem)

{
  ushort uVar1;
  ushort uVar2;
  Links_t *pLVar3;
  int iVar4;
  Node_t *pNVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  
                    /* Unresolved local var: ushort leftchild@[DW_OP_reg7(EDI)] */
  uVar8 = (uint)elem;
  if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
       == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                         Links(unsigned_short)::s_Sentinel);
  }
  if (uVar8 == 0xffff) {
    pcVar7 = " listed with startdemos\n";
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    pcVar7 = (char *)(uVar8 * 0x28);
    pLVar3 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
  }
  uVar1 = (((Node_t *)pLVar3)->super_Links_t).m_Left;
  uVar9 = (uint)uVar1;
  if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
       == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                         Links(unsigned_short)::s_Sentinel);
  }
  pNVar5 = (this->m_Elements).m_pMemory;
  if (uVar9 == 0xffff) {
    pcVar6 = " listed with startdemos\n";
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    pcVar6 = (char *)(uVar9 * 0x28);
    pLVar3 = &pNVar5[uVar9].super_Links_t;
  }
  *(ushort *)(pcVar7 + (int)(&pNVar5->m_Data + -1) + 0x18) =
       (((Node_t *)pLVar3)->super_Links_t).m_Right;
  if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
       == '\0') &&
     (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
    Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
    __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                         Links(unsigned_short)::s_Sentinel);
  }
  pLVar3 = &Links::lexical_block_0::s_Sentinel;
  if (uVar9 != 0xffff) {
    pLVar3 = (Links_t *)(pcVar6 + (int)(&((this->m_Elements).m_pMemory)->m_Data + -1) + 0x18);
  }
  if (pLVar3->m_Right != 0xffff) {
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
    if (uVar9 != 0xffff) {
      pLVar3 = (Links_t *)(pcVar6 + (int)(&pNVar5->m_Data + -1) + 0x18);
    }
    pNVar5[pLVar3->m_Right].super_Links_t.m_Parent = elem;
  }
  if (uVar9 != 0xffff) {
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_pMemory;
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
    if (uVar8 != 0xffff) {
      pLVar3 = (Links_t *)(pcVar7 + (int)(&pNVar5->m_Data + -1) + 0x18);
    }
    *(ushort *)((int)&(pNVar5->super_Links_t).m_Parent + (int)pcVar6) = pLVar3->m_Parent;
  }
  if (this->m_Root == uVar8) {
    this->m_Root = uVar1;
  }
  else {
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar3 = &Links::lexical_block_0::s_Sentinel;
    if (uVar8 != 0xffff) {
      pLVar3 = (Links_t *)(pcVar7 + (int)(&((this->m_Elements).m_pMemory)->m_Data + -1) + 0x18);
    }
    uVar2 = pLVar3->m_Parent;
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pNVar5 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (uVar2 != 0xffff) {
      pNVar5 = (this->m_Elements).m_pMemory + uVar2;
    }
    if ((pNVar5->super_Links_t).m_Right == uVar8) {
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar3 = &Links::lexical_block_0::s_Sentinel;
      if (uVar8 != 0xffff) {
        pLVar3 = (Links_t *)(pcVar7 + (int)(&pNVar5->m_Data + -1) + 0x18);
      }
      pNVar5[pLVar3->m_Parent].super_Links_t.m_Right = uVar1;
    }
    else {
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pNVar5 = (this->m_Elements).m_pMemory;
      pLVar3 = &Links::lexical_block_0::s_Sentinel;
      if (uVar8 != 0xffff) {
        pLVar3 = (Links_t *)(pcVar7 + (int)(&pNVar5->m_Data + -1) + 0x18);
      }
      pNVar5[pLVar3->m_Parent].super_Links_t.m_Left = uVar1;
    }
  }
  *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + (int)pcVar6) = elem;
  if (uVar8 != 0xffff) {
    *(ushort *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + (int)pcVar7) =
         uVar1;
  }
  return;
}


