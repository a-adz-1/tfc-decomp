// CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::Insert  @ 001da2f0
/* WARNING: Variable defined which should be unmapped: newnode */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: ushort
   Insert(CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> * this, cacheentry_t *
   insert) */

ushort __thiscall
CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::Insert
          (CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> *this,
          cacheentry_t *insert)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  size_t __size;
  Node_t *pNVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  ushort newnode;
  
                    /* Unresolved local var: ushort current@[???]
                       Unresolved local var: ushort parent@[???]
                       Unresolved local var: bool leftchild@[???] */
  uVar7 = (uint)this->m_Root;
  if (uVar7 == 0xffff) {
    bVar1 = false;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory;
    uVar9 = uVar7;
    do {
      uVar7 = uVar9;
      bVar1 = (*this->m_LessFunc)(insert,&pNVar4[uVar7].m_Data);
      if (bVar1) {
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        bVar1 = true;
        uVar5 = pNVar4[uVar7].super_Links_t.m_Left;
      }
      else {
        if ((CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
             s_Sentinel == '\0') &&
           (iVar2 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>
                                         ::Links(unsigned_short)::s_Sentinel), iVar2 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        bVar1 = false;
        uVar5 = pNVar4[uVar7].super_Links_t.m_Right;
      }
      uVar9 = (uint)uVar5;
    } while (uVar5 != 0xffff);
  }
                    /* Unresolved local var: ushort i@[???]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: ushort newElem@[???] */
  uVar5 = this->m_FirstFree;
  uVar9 = (uint)uVar5;
  if (uVar9 == 0xffff) {
                    /* Unresolved local var: ushort newElem@[???] */
    uVar9 = (uint)this->m_TotalElements;
    uVar6 = (this->m_Elements).m_NumAllocated;
    if (uVar6 == uVar9) {
      uVar3 = (this->m_Elements).m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((uVar3 == 0) && (uVar3 = 1, uVar6 != 0)) {
        uVar3 = uVar6;
      }
                    /* Unresolved local var: int growSize@[???] */
      pNVar4 = (this->m_Elements).m_pMemory;
      (this->m_Elements).m_NumAllocated = uVar3 + uVar6;
      __size = (uVar3 + uVar6) * 0x28;
      if (pNVar4 == (Node_t *)0x0) {
        pNVar4 = malloc(__size);
        (this->m_Elements).m_pMemory = pNVar4;
      }
      else {
        pNVar4 = realloc(pNVar4,__size);
        uVar6 = (uint)this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar4;
        uVar9 = uVar6;
      }
    }
    else {
      pNVar4 = (this->m_Elements).m_pMemory;
      uVar6 = uVar9;
    }
    uVar5 = (ushort)uVar6;
    this->m_TotalElements = (short)uVar9 + 1;
    pNVar4 = pNVar4 + uVar9;
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
    pNVar4 = (this->m_Elements).m_pMemory + uVar9;
    this->m_FirstFree = (pNVar4->super_Links_t).m_Right;
  }
  (pNVar4->super_Links_t).m_Parent = (ushort)uVar7;
  (pNVar4->super_Links_t).m_Right = 0xffff;
  (pNVar4->super_Links_t).m_Left = 0xffff;
  (pNVar4->super_Links_t).m_Tag = 0;
  uVar8 = (ushort)uVar9;
  if (uVar7 == 0xffff) {
    this->m_Root = uVar8;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory + uVar7;
    if (bVar1) {
      (pNVar4->super_Links_t).m_Left = uVar8;
    }
    else {
      (pNVar4->super_Links_t).m_Right = uVar8;
    }
  }
  InsertRebalance(this,uVar5);
  pNVar4 = (this->m_Elements).m_pMemory;
  this->m_NumElements = this->m_NumElements + 1;
  pNVar4 = pNVar4 + uVar9;
  if (pNVar4 != (Node_t *)0xfffffff8) {
    uVar7 = 0;
    do {
      *(undefined4 *)((int)(pNVar4->m_Data).texCoords + (uVar7 - 0xc)) =
           *(undefined4 *)((int)insert->texCoords + (uVar7 - 0xc));
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x20);
  }
  return uVar8;
}


