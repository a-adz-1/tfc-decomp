// CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::InsertRebalance  @ 001d9700
/* DWARF original prototype: void
   InsertRebalance(CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> * this, ushort
   elem) */

void __thiscall
CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::InsertRebalance
          (CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> *this,ushort elem)

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
LAB_001d9768:
      (this->m_Elements).m_pMemory[uVar2].super_Links_t.m_Tag = 1;
      return;
    }
    if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
        s_Sentinel == '\0') {
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar5 = &Links::s_Sentinel;
      if (uVar8 != 0xffff) goto LAB_001d9733;
LAB_001d973c:
      uVar2 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel != '\0') ||
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 == 0))
      goto LAB_001d9748;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                           Links(unsigned_short)::s_Sentinel);
      if (uVar2 == 0xffff) goto LAB_001d9a90;
LAB_001d9754:
      pLVar5 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
    }
    else {
      if (uVar8 != 0xffff) {
LAB_001d9733:
        pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
        goto LAB_001d973c;
      }
      uVar2 = (uint)Links::s_Sentinel.m_Parent;
LAB_001d9748:
      if (uVar2 != 0xffff) goto LAB_001d9754;
LAB_001d9a90:
      pLVar5 = &Links::s_Sentinel;
    }
    if ((((Node_t *)pLVar5)->super_Links_t).m_Tag != 0) {
      uVar2 = (uint)this->m_Root;
      goto LAB_001d9768;
    }
                    /* Unresolved local var: ushort parent@[???]
                       Unresolved local var: ushort grandparent@[???] */
    if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
        s_Sentinel == '\0') {
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar5 = &Links::s_Sentinel;
      if (uVar8 != 0xffff) goto LAB_001d979b;
LAB_001d97a4:
      uVar2 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
           s_Sentinel == '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
    }
    else {
      if (uVar8 != 0xffff) {
LAB_001d979b:
        pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
        goto LAB_001d97a4;
      }
      uVar2 = (uint)Links::s_Sentinel.m_Parent;
    }
    if (uVar2 == 0xffff) {
      uVar6 = (uint)Links::s_Sentinel.m_Parent;
      uVar7 = uVar6;
      if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
          s_Sentinel == '\0') goto LAB_001d99a0;
LAB_001d97e1:
      if (uVar6 != 0xffff) goto LAB_001d97ed;
LAB_001d9977:
      pLVar5 = &Links::s_Sentinel;
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      uVar6 = (uint)pNVar3[uVar2].super_Links_t.m_Parent;
      if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
          s_Sentinel == '\0') {
LAB_001d99a0:
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        uVar7 = uVar6;
        if (uVar2 != 0xffff) {
          pNVar3 = (this->m_Elements).m_pMemory;
          goto LAB_001d97cf;
        }
      }
      else {
LAB_001d97cf:
        pLVar5 = &pNVar3[uVar2].super_Links_t;
        uVar7 = uVar6;
      }
      uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
      if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
          s_Sentinel != '\0') goto LAB_001d97e1;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        goto LAB_001d97e1;
      }
      if (uVar6 == 0xffff) goto LAB_001d9977;
LAB_001d97ed:
      pLVar5 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
    }
    if ((((Node_t *)pLVar5)->super_Links_t).m_Left == uVar2) {
                    /* Unresolved local var: ushort uncle@[???] */
      if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
          s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        if (uVar7 != 0xffff) goto LAB_001d9815;
LAB_001d981f:
        uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Right;
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
      }
      else {
        if (uVar7 != 0xffff) {
LAB_001d9815:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
          goto LAB_001d981f;
        }
        uVar6 = (uint)Links::s_Sentinel.m_Right;
      }
      uVar1 = Links::s_Sentinel.m_Tag;
      if (uVar6 != 0xffff) {
        uVar1 = (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag;
      }
      if (uVar1 == 0) {
LAB_001d984b:
                    /* Unresolved local var: ushort uncle@[???] */
        (this->m_Elements).m_pMemory[uVar2].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar7].super_Links_t.m_Tag = 0;
        uVar8 = uVar7;
      }
      else {
        if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
            s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          pLVar5 = &Links::s_Sentinel;
          if (uVar8 != 0xffff) goto LAB_001d9b6b;
LAB_001d9b74:
          uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
               s_Sentinel != '\0') ||
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                           ::Links(unsigned_short)::s_Sentinel), iVar4 == 0))
          goto LAB_001d9b80;
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
          if (uVar6 == 0xffff) goto LAB_001da030;
LAB_001d9b8c:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
        }
        else {
          if (uVar8 != 0xffff) {
LAB_001d9b6b:
            pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
            goto LAB_001d9b74;
          }
          uVar6 = (uint)Links::s_Sentinel.m_Parent;
LAB_001d9b80:
          if (uVar6 != 0xffff) goto LAB_001d9b8c;
LAB_001da030:
          pLVar5 = &Links::s_Sentinel;
        }
        if ((((Node_t *)pLVar5)->super_Links_t).m_Right == uVar8) {
          RotateLeft(this,(ushort)uVar2);
          if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
              s_Sentinel == '\0') {
            iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel);
            if (iVar4 != 0) {
              Links::s_Sentinel.m_Left = 0xffff;
              Links::s_Sentinel.m_Right = 0xffff;
              Links::s_Sentinel.m_Parent = 0xffff;
              __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
            }
            pLVar5 = &Links::s_Sentinel;
            if (uVar2 != 0xffff) goto LAB_001d9e7f;
LAB_001d9e88:
            uVar8 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
            if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
                 s_Sentinel == '\0') &&
               (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                             ::Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
              Links::s_Sentinel.m_Left = 0xffff;
              Links::s_Sentinel.m_Right = 0xffff;
              Links::s_Sentinel.m_Parent = 0xffff;
              __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
            }
          }
          else {
            if (uVar2 != 0xffff) {
LAB_001d9e7f:
              pLVar5 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
              goto LAB_001d9e88;
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
      if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
          s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        if (uVar7 != 0xffff) goto code_r0x001d9894;
code_r0x001d989e:
        uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Left;
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar4 == 0))
        goto LAB_001d98a9;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        if (uVar6 == 0xffff) goto LAB_001d9c70;
LAB_001d98b5:
        pLVar5 = &(this->m_Elements).m_pMemory[uVar6].super_Links_t;
      }
      else {
        if (uVar7 != 0xffff) {
code_r0x001d9894:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
          goto code_r0x001d989e;
        }
        uVar6 = (uint)Links::s_Sentinel.m_Left;
LAB_001d98a9:
        if (uVar6 != 0xffff) goto LAB_001d98b5;
LAB_001d9c70:
        pLVar5 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar5)->super_Links_t).m_Tag == 0) goto LAB_001d984b;
      if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
          s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar5 = &Links::s_Sentinel;
        if (uVar8 != 0xffff) goto LAB_001d98e0;
LAB_001d98e9:
        uVar6 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar4 == 0))
        goto LAB_001d98f5;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        if (uVar6 == 0xffff) goto LAB_001d9f20;
LAB_001d9901:
        if ((this->m_Elements).m_pMemory[uVar6].super_Links_t.m_Left != uVar8) goto LAB_001d9915;
LAB_001d9f30:
        RotateRight(this,(ushort)uVar2);
        if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
            s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          pLVar5 = &Links::s_Sentinel;
          if (uVar2 != 0xffff) goto LAB_001d9f57;
LAB_001d9f60:
          uVar8 = (uint)(((Node_t *)pLVar5)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
               s_Sentinel == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                           ::Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
        }
        else {
          if (uVar2 != 0xffff) {
LAB_001d9f57:
            pLVar5 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
            goto LAB_001d9f60;
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
LAB_001d98e0:
          pLVar5 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
          goto LAB_001d98e9;
        }
        uVar6 = (uint)Links::s_Sentinel.m_Parent;
LAB_001d98f5:
        if (uVar6 != 0xffff) goto LAB_001d9901;
LAB_001d9f20:
        if (Links::s_Sentinel.m_Left == uVar8) goto LAB_001d9f30;
LAB_001d9915:
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


