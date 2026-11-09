// CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::InsertRebalance  @ 00223600
/* DWARF original prototype: void
   InsertRebalance(CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> * this, ushort
   elem) */

void __thiscall
CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::InsertRebalance
          (CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> *this,ushort elem)

{
  ushort elem_00;
  uint uVar1;
  int iVar2;
  Node_t *pNVar3;
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
LAB_0022366a:
      (this->m_Elements).m_pMemory[uVar1].super_Links_t.m_Tag = 1;
      return;
    }
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar7 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
    }
    uVar1 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    if ((((Node_t *)pLVar4)->super_Links_t).m_Tag != 0) {
      uVar1 = (uint)this->m_Root;
      goto LAB_0022366a;
    }
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar7 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
    }
    elem_00 = (((Node_t *)pLVar4)->super_Links_t).m_Parent;
    uVar1 = (uint)elem_00;
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar1 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
    }
    uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
    if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
         s_Sentinel == '\0') &&
       (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
    }
    pLVar4 = &Links::lexical_block_0::s_Sentinel;
    if (uVar5 != 0xffff) {
      pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
    }
                    /* Unresolved local var: ushort uncle@[DW_OP_reg2(EDX)] */
    if ((((Node_t *)pLVar4)->super_Links_t).m_Left == uVar1) {
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar6 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Right;
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Tag == 0) {
LAB_0022376e:
        (this->m_Elements).m_pMemory[uVar1].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar5].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 0;
        uVar7 = uVar6;
      }
      else {
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar7 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
        }
        uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar5 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
        }
        if ((((Node_t *)pLVar4)->super_Links_t).m_Right == uVar7) {
          RotateLeft(this,elem_00);
          if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
               s_Sentinel == '\0') &&
             (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                           ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          pLVar4 = &Links::lexical_block_0::s_Sentinel;
          if (uVar1 != 0xffff) {
            pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
          }
          uVar7 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
               s_Sentinel == '\0') &&
             (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                           ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          if (uVar7 == 0xffff) {
            pLVar4 = &Links::lexical_block_0::s_Sentinel;
            pNVar3 = (Node_t *)
                     ("No demos listed with startdemos\n" +
                     (int)&((this->m_Elements).m_pMemory)->m_Data);
          }
          else {
            pNVar3 = (this->m_Elements).m_pMemory + uVar7;
            pLVar4 = &pNVar3->super_Links_t;
          }
          uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + uVar1;
          uVar1 = uVar7;
        }
        (pNVar3->super_Links_t).m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 0;
        RotateRight(this,(ushort)uVar6);
        uVar7 = uVar1;
      }
    }
    else {
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar6 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Left;
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Tag == 0) goto LAB_0022376e;
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar7 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
      }
      uVar5 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
        Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar4 = &Links::lexical_block_0::s_Sentinel;
      if (uVar5 != 0xffff) {
        pLVar4 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
      }
      if ((((Node_t *)pLVar4)->super_Links_t).m_Left == uVar7) {
        RotateRight(this,elem_00);
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar4 = &Links::lexical_block_0::s_Sentinel;
        if (uVar1 != 0xffff) {
          pLVar4 = &(this->m_Elements).m_pMemory[uVar1].super_Links_t;
        }
        uVar7 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        if (uVar7 == 0xffff) {
          pLVar4 = &Links::lexical_block_0::s_Sentinel;
          pNVar3 = (Node_t *)
                   ("No demos listed with startdemos\n" +
                   (int)&((this->m_Elements).m_pMemory)->m_Data);
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + uVar7;
          pLVar4 = &pNVar3->super_Links_t;
        }
        uVar6 = (uint)(((Node_t *)pLVar4)->super_Links_t).m_Parent;
      }
      else {
        pNVar3 = (this->m_Elements).m_pMemory + uVar1;
        uVar1 = uVar7;
      }
      (pNVar3->super_Links_t).m_Tag = 1;
      (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 0;
      RotateLeft(this,(ushort)uVar6);
      uVar7 = uVar1;
    }
  } while( true );
}


