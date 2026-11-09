// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::Insert  @ 002289c0
/* DWARF original prototype: ushort Insert(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *
   this, abc_cache_t * insert) */

ushort __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::Insert
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,abc_cache_t *insert)

{
  abc_t aVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  Node_t *pNVar6;
  uint uVar7;
  
                    /* Unresolved local var: ushort newnode@[???]
                       Unresolved local var: ushort current@[???]
                       Unresolved local var: ushort parent@[???]
                       Unresolved local var: bool leftchild@[???] */
  if (this->m_Root == 0xffff) {
    uVar7 = 0xffff;
    bVar2 = false;
  }
  else {
    pNVar6 = (this->m_Elements).m_pMemory;
    uVar4 = (uint)this->m_Root;
    do {
      while( true ) {
        uVar7 = uVar4;
        bVar2 = (*this->m_LessFunc)(insert,&pNVar6[uVar7].m_Data);
        if (bVar2) break;
        if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
            '\0') {
          iVar5 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar5 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
        }
        pNVar6 = (this->m_Elements).m_pMemory;
        bVar2 = false;
        uVar4 = (uint)pNVar6[uVar7].super_Links_t.m_Right;
        if (uVar4 == 0xffff) goto LAB_00228a3a;
      }
      if (CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
          '\0') {
        iVar5 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar5 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
      }
      pNVar6 = (this->m_Elements).m_pMemory;
      bVar2 = true;
      uVar4 = (uint)pNVar6[uVar7].super_Links_t.m_Left;
    } while (uVar4 != 0xffff);
  }
LAB_00228a3a:
  uVar3 = InsertAt(this,(ushort)uVar7,bVar2);
  pNVar6 = (this->m_Elements).m_pMemory + uVar3;
  if (pNVar6 != (Node_t *)0xfffffff8) {
    aVar1 = insert->abc;
    (pNVar6->m_Data).wch = insert->wch;
    (pNVar6->m_Data).abc = aVar1;
  }
  return uVar3;
}


