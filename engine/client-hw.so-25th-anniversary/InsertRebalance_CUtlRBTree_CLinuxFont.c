// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::InsertRebalance  @ 001de8f0
/* DWARF original prototype: void
   InsertRebalance(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> * this, ushort elem) */

void __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::InsertRebalance
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,ushort elem)

{
  ushort uVar1;
  uint uVar2;
  Node_t *pNVar3;
  int iVar4;
  uint uVar5;
  Links_t *pLVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)elem;
  do {
    uVar2 = (uint)this->m_Root;
    if (uVar8 == uVar2) {
LAB_001de958:
      (this->m_Elements).m_pMemory[uVar2].super_Links_t.m_Tag = 1;
      return;
    }
    if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
        '\0') {
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar6 = &Links::s_Sentinel;
      if (uVar8 != 0xffff) goto LAB_001de923;
LAB_001de92d:
      uVar2 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel !=
           '\0') ||
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 == 0))
      goto LAB_001de939;
      Links::s_Sentinel.m_Left = 0xffff;
      Links::s_Sentinel.m_Right = 0xffff;
      Links::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
      if (uVar2 == 0xffff) goto LAB_001dec90;
LAB_001de945:
      pLVar6 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
    }
    else {
      if (uVar8 != 0xffff) {
LAB_001de923:
        pLVar6 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
        goto LAB_001de92d;
      }
      uVar2 = (uint)Links::s_Sentinel.m_Parent;
LAB_001de939:
      if (uVar2 != 0xffff) goto LAB_001de945;
LAB_001dec90:
      pLVar6 = &Links::s_Sentinel;
    }
    if ((((Node_t *)pLVar6)->super_Links_t).m_Tag != 0) {
      uVar2 = (uint)this->m_Root;
      goto LAB_001de958;
    }
                    /* Unresolved local var: ushort parent@[???]
                       Unresolved local var: ushort grandparent@[???] */
    if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
        '\0') {
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
      pLVar6 = &Links::s_Sentinel;
      if (uVar8 != 0xffff) goto LAB_001de98b;
LAB_001de995:
      uVar2 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
           '\0') &&
         (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
      }
    }
    else {
      if (uVar8 != 0xffff) {
LAB_001de98b:
        pLVar6 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
        goto LAB_001de995;
      }
      uVar2 = (uint)Links::s_Sentinel.m_Parent;
    }
    if (uVar2 == 0xffff) {
      uVar5 = (uint)Links::s_Sentinel.m_Parent;
      uVar7 = uVar5;
      if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
          '\0') goto LAB_001deba0;
LAB_001de9d5:
      if (uVar7 != 0xffff) goto LAB_001de9e1;
LAB_001deb6f:
      pLVar6 = &Links::s_Sentinel;
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
      uVar5 = (uint)pNVar3[uVar2].super_Links_t.m_Parent;
      if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
          '\0') {
LAB_001deba0:
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar6 = &Links::s_Sentinel;
        if (uVar2 != 0xffff) {
          pNVar3 = (this->m_Elements).m_pMemory;
          goto LAB_001de9c2;
        }
      }
      else {
LAB_001de9c2:
        pLVar6 = &pNVar3[uVar2].super_Links_t;
      }
      uVar7 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
      if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel !=
          '\0') goto LAB_001de9d5;
      iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
      if (iVar4 != 0) {
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        goto LAB_001de9d5;
      }
      if (uVar7 == 0xffff) goto LAB_001deb6f;
LAB_001de9e1:
      pLVar6 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
    }
    if ((((Node_t *)pLVar6)->super_Links_t).m_Left == uVar2) {
                    /* Unresolved local var: ushort uncle@[???] */
      if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
          '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar6 = &Links::s_Sentinel;
        if (uVar5 != 0xffff) goto LAB_001dea05;
LAB_001dea0f:
        uVar7 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Right;
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             == '\0') &&
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
      }
      else {
        if (uVar5 != 0xffff) {
LAB_001dea05:
          pLVar6 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
          goto LAB_001dea0f;
        }
        uVar7 = (uint)Links::s_Sentinel.m_Right;
      }
      uVar1 = Links::s_Sentinel.m_Tag;
      if (uVar7 != 0xffff) {
        uVar1 = (this->m_Elements).m_pMemory[uVar7].super_Links_t.m_Tag;
      }
      if (uVar1 == 0) {
LAB_001dea3c:
                    /* Unresolved local var: ushort uncle@[???] */
        (this->m_Elements).m_pMemory[uVar2].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar7].super_Links_t.m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar5].super_Links_t.m_Tag = 0;
        uVar8 = uVar5;
      }
      else {
        if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
            '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (uVar8 != 0xffff) goto LAB_001ded6b;
LAB_001ded75:
          uVar7 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
               != '\0') ||
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                           Links(unsigned_short)::s_Sentinel), iVar4 == 0))
          goto LAB_001ded81;
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
          if (uVar7 == 0xffff) goto LAB_001df250;
LAB_001ded8d:
          pLVar6 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
        }
        else {
          if (uVar8 != 0xffff) {
LAB_001ded6b:
            pLVar6 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
            goto LAB_001ded75;
          }
          uVar7 = (uint)Links::s_Sentinel.m_Parent;
LAB_001ded81:
          if (uVar7 != 0xffff) goto LAB_001ded8d;
LAB_001df250:
          pLVar6 = &Links::s_Sentinel;
        }
        if ((((Node_t *)pLVar6)->super_Links_t).m_Right == uVar8) {
          RotateLeft(this,(ushort)uVar2);
          if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
              == '\0') {
            iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel);
            if (iVar4 != 0) {
              Links::s_Sentinel.m_Left = 0xffff;
              Links::s_Sentinel.m_Right = 0xffff;
              Links::s_Sentinel.m_Parent = 0xffff;
              __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
            }
            pLVar6 = &Links::s_Sentinel;
            if (uVar2 != 0xffff) goto LAB_001df08f;
LAB_001df099:
            uVar8 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
            if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::
                 s_Sentinel == '\0') &&
               (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                             Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
              Links::s_Sentinel.m_Right = 0xffff;
              Links::s_Sentinel.m_Left = 0xffff;
              Links::s_Sentinel.m_Parent = 0xffff;
              __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                   Links(unsigned_short)::s_Sentinel);
            }
          }
          else {
            if (uVar2 != 0xffff) {
LAB_001df08f:
              pLVar6 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
              goto LAB_001df099;
            }
            uVar8 = (uint)Links::s_Sentinel.m_Parent;
          }
          if (uVar8 == 0xffff) {
            pLVar6 = &Links::s_Sentinel;
            pNVar3 = (this->m_Elements).m_pMemory + 0xffff;
          }
          else {
            pNVar3 = (this->m_Elements).m_pMemory + uVar8;
            pLVar6 = &pNVar3->super_Links_t;
          }
          uVar5 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + uVar2;
          uVar2 = uVar8;
        }
        (pNVar3->super_Links_t).m_Tag = 1;
        (this->m_Elements).m_pMemory[uVar5].super_Links_t.m_Tag = 0;
        RotateRight(this,(ushort)uVar5);
        uVar8 = uVar2;
      }
    }
    else {
      if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
          '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar6 = &Links::s_Sentinel;
        if (uVar5 != 0xffff) goto LAB_001dea84;
LAB_001dea8e:
        uVar7 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Left;
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar4 == 0))
        goto LAB_001dea99;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        if (uVar7 == 0xffff) goto LAB_001dee70;
LAB_001deaa5:
        pLVar6 = &(this->m_Elements).m_pMemory[uVar7].super_Links_t;
      }
      else {
        if (uVar5 != 0xffff) {
LAB_001dea84:
          pLVar6 = &(this->m_Elements).m_pMemory[uVar5].super_Links_t;
          goto LAB_001dea8e;
        }
        uVar7 = (uint)Links::s_Sentinel.m_Left;
LAB_001dea99:
        if (uVar7 != 0xffff) goto LAB_001deaa5;
LAB_001dee70:
        pLVar6 = &Links::s_Sentinel;
      }
      if ((((Node_t *)pLVar6)->super_Links_t).m_Tag == 0) goto LAB_001dea3c;
      if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
          '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pLVar6 = &Links::s_Sentinel;
        if (uVar8 != 0xffff) goto LAB_001dead1;
LAB_001deadb:
        uVar7 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             != '\0') ||
           (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar4 == 0))
        goto LAB_001deae7;
        Links::s_Sentinel.m_Left = 0xffff;
        Links::s_Sentinel.m_Right = 0xffff;
        Links::s_Sentinel.m_Parent = 0xffff;
        __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                             Links(unsigned_short)::s_Sentinel);
        if (uVar7 == 0xffff) goto LAB_001df130;
LAB_001deaf3:
        if ((this->m_Elements).m_pMemory[uVar7].super_Links_t.m_Left != uVar8) goto LAB_001deb07;
LAB_001df150:
        RotateRight(this,(ushort)uVar2);
        if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
            '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar4 != 0) {
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
          pLVar6 = &Links::s_Sentinel;
          if (uVar2 != 0xffff) goto LAB_001df177;
LAB_001df181:
          uVar8 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
          if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
               == '\0') &&
             (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                           Links(unsigned_short)::s_Sentinel), iVar4 != 0)) {
            Links::s_Sentinel.m_Right = 0xffff;
            Links::s_Sentinel.m_Left = 0xffff;
            Links::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
        }
        else {
          if (uVar2 != 0xffff) {
LAB_001df177:
            pLVar6 = &(this->m_Elements).m_pMemory[uVar2].super_Links_t;
            goto LAB_001df181;
          }
          uVar8 = (uint)Links::s_Sentinel.m_Parent;
        }
        if (uVar8 == 0xffff) {
          pLVar6 = &Links::s_Sentinel;
          pNVar3 = (this->m_Elements).m_pMemory + 0xffff;
        }
        else {
          pNVar3 = (this->m_Elements).m_pMemory + uVar8;
          pLVar6 = &pNVar3->super_Links_t;
        }
        uVar5 = (uint)(((Node_t *)pLVar6)->super_Links_t).m_Parent;
      }
      else {
        if (uVar8 != 0xffff) {
LAB_001dead1:
          pLVar6 = &(this->m_Elements).m_pMemory[uVar8].super_Links_t;
          goto LAB_001deadb;
        }
        uVar7 = (uint)Links::s_Sentinel.m_Parent;
LAB_001deae7:
        if (uVar7 != 0xffff) goto LAB_001deaf3;
LAB_001df130:
        if (Links::s_Sentinel.m_Left == uVar8) goto LAB_001df150;
LAB_001deb07:
        pNVar3 = (this->m_Elements).m_pMemory + uVar2;
        uVar2 = uVar8;
      }
      (pNVar3->super_Links_t).m_Tag = 1;
      (this->m_Elements).m_pMemory[uVar5].super_Links_t.m_Tag = 0;
      RotateLeft(this,(ushort)uVar5);
      uVar8 = uVar2;
    }
  } while( true );
}


