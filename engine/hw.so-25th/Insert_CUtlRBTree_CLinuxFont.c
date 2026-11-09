// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::Insert  @ 001df520
/* WARNING: Variable defined which should be unmapped: newnode */
/* DWARF original prototype: ushort Insert(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *
   this, abc_cache_t * insert) */

ushort __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::Insert
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,abc_cache_t *insert)

{
  abc_t aVar1;
  bool bVar2;
  int iVar3;
  Node_t *pNVar4;
  ushort uVar5;
  uint uVar6;
  size_t __size;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  ushort newnode;
  
                    /* Unresolved local var: ushort current@[???]
                       Unresolved local var: ushort parent@[???]
                       Unresolved local var: bool leftchild@[???] */
  uVar10 = (uint)this->m_Root;
  if (uVar10 == 0xffff) {
    bVar2 = false;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory;
    uVar9 = uVar10;
    do {
      uVar10 = uVar9;
      bVar2 = (*this->m_LessFunc)(insert,&pNVar4[uVar10].m_Data);
      if (bVar2) {
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        bVar2 = true;
        uVar5 = pNVar4[uVar10].super_Links_t.m_Left;
      }
      else {
        if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel
             == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                         Links(unsigned_short)::s_Sentinel), iVar3 != 0)) {
          Links::s_Sentinel.m_Left = 0xffff;
          Links::s_Sentinel.m_Right = 0xffff;
          Links::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
        pNVar4 = (this->m_Elements).m_pMemory;
        bVar2 = false;
        uVar5 = pNVar4[uVar10].super_Links_t.m_Right;
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
    uVar7 = (this->m_Elements).m_NumAllocated;
    if (uVar7 == uVar9) {
      uVar6 = (this->m_Elements).m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((uVar6 == 0) && (uVar6 = 1, uVar7 != 0)) {
        uVar6 = uVar7;
      }
                    /* Unresolved local var: int growSize@[???] */
      pNVar4 = (this->m_Elements).m_pMemory;
      (this->m_Elements).m_NumAllocated = uVar6 + uVar7;
      __size = (uVar6 + uVar7) * 0x10;
      if (pNVar4 == (Node_t *)0x0) {
        pNVar4 = malloc(__size);
        (this->m_Elements).m_pMemory = pNVar4;
      }
      else {
        pNVar4 = realloc(pNVar4,__size);
        uVar7 = (uint)this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar4;
        uVar9 = uVar7;
      }
    }
    else {
      pNVar4 = (this->m_Elements).m_pMemory;
      uVar7 = uVar9;
    }
    uVar5 = (ushort)uVar7;
    this->m_TotalElements = (short)uVar9 + 1;
    pNVar4 = pNVar4 + uVar9;
  }
  else {
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
    pNVar4 = (this->m_Elements).m_pMemory + uVar9;
    this->m_FirstFree = (pNVar4->super_Links_t).m_Right;
  }
  (pNVar4->super_Links_t).m_Parent = (ushort)uVar10;
  (pNVar4->super_Links_t).m_Right = 0xffff;
  (pNVar4->super_Links_t).m_Left = 0xffff;
  (pNVar4->super_Links_t).m_Tag = 0;
  uVar8 = (ushort)uVar9;
  if (uVar10 == 0xffff) {
    this->m_Root = uVar8;
  }
  else {
    pNVar4 = (this->m_Elements).m_pMemory + uVar10;
    if (bVar2) {
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
    aVar1 = insert->abc;
    (pNVar4->m_Data).wch = insert->wch;
    (pNVar4->m_Data).abc = aVar1;
  }
  return uVar8;
}


