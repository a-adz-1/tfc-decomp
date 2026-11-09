// CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::InsertAt  @ 00228830
/* DWARF original prototype: ushort InsertAt(CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>
   * this, ushort parent, bool leftchild) */

ushort __thiscall
CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int>::InsertAt
          (CUtlRBTree<CLinuxFont::abc_cache_t,_short_unsigned_int> *this,ushort parent,
          bool leftchild)

{
  int iVar1;
  uint uVar2;
  size_t __size;
  Node_t *pNVar3;
  ushort elem;
  uint uVar4;
  
                    /* Unresolved local var: ushort i@[DW_OP_reg7(EDI)]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: ushort newElem@[???] */
  uVar4 = (uint)this->m_FirstFree;
  if (uVar4 == 0xffff) {
    uVar4 = (uint)this->m_TotalElements;
    if ((this->m_Elements).m_NumAllocated == uVar4) {
                    /* Unresolved local var: int growSize@[???] */
      uVar2 = (this->m_Elements).m_GrowSize;
      if ((uVar2 == 0) && (uVar2 = 1, uVar4 != 0)) {
        uVar2 = uVar4;
      }
      pNVar3 = (this->m_Elements).m_pMemory;
      (this->m_Elements).m_NumAllocated = uVar2 + uVar4;
      __size = (uVar2 + uVar4) * 0x10;
      if (pNVar3 == (Node_t *)0x0) {
        pNVar3 = malloc(__size);
        (this->m_Elements).m_pMemory = pNVar3;
      }
      else {
        pNVar3 = realloc(pNVar3,__size);
        uVar4 = (uint)this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar3;
      }
    }
    else {
      pNVar3 = (this->m_Elements).m_pMemory;
    }
    this->m_TotalElements = (short)uVar4 + 1;
    pNVar3 = pNVar3 + uVar4;
  }
  else {
    if ((CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)::s_Sentinel ==
         '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel), iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
      Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
      __cxa_guard_release(&CUtlRBTree<CLinuxFont::abc_cache_t,unsigned_short>::Links(unsigned_short)
                           ::s_Sentinel);
    }
    pNVar3 = (this->m_Elements).m_pMemory + uVar4;
    this->m_FirstFree = (pNVar3->super_Links_t).m_Right;
  }
  (pNVar3->super_Links_t).m_Parent = parent;
  (pNVar3->super_Links_t).m_Right = 0xffff;
  (pNVar3->super_Links_t).m_Left = 0xffff;
  (pNVar3->super_Links_t).m_Tag = 0;
  elem = (ushort)uVar4;
  if (parent == 0xffff) {
    this->m_Root = elem;
  }
  else {
    pNVar3 = (this->m_Elements).m_pMemory + parent;
    if (leftchild) {
      (pNVar3->super_Links_t).m_Left = elem;
    }
    else {
      (pNVar3->super_Links_t).m_Right = elem;
    }
  }
  InsertRebalance(this,elem);
  this->m_NumElements = this->m_NumElements + 1;
  return elem;
}


