// CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::Insert  @ 002241b0
/* DWARF original prototype: ushort
   Insert(CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> * this, cacheentry_t *
   insert) */

ushort __thiscall
CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int>::Insert
          (CUtlRBTree<CFontTextureCache::cacheentry_t,_short_unsigned_int> *this,
          cacheentry_t *insert)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  cacheentry_t *pcVar5;
  Node_t *pNVar6;
  uint uVar7;
  
                    /* Unresolved local var: ushort newnode@[DW_OP_reg2(EDX)]
                       Unresolved local var: ushort current@[???]
                       Unresolved local var: ushort parent@[???]
                       Unresolved local var: bool leftchild@[???] */
  if (this->m_Root == 0xffff) {
    uVar7 = 0xffff;
    bVar1 = false;
  }
  else {
    pNVar6 = (this->m_Elements).m_pMemory;
    uVar3 = (uint)this->m_Root;
    do {
      while( true ) {
        uVar7 = uVar3;
        bVar1 = (*this->m_LessFunc)(insert,&pNVar6[uVar7].m_Data);
        if (bVar1) break;
        if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
            s_Sentinel == '\0') {
          iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                       Links(unsigned_short)::s_Sentinel);
          if (iVar4 != 0) {
            Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
            Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
            __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                 Links(unsigned_short)::s_Sentinel);
          }
        }
        pNVar6 = (this->m_Elements).m_pMemory;
        bVar1 = false;
        uVar3 = (uint)pNVar6[uVar7].super_Links_t.m_Right;
        if (uVar3 == 0xffff) goto LAB_0022422f;
      }
      if (CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::Links(unsigned_short)::
          s_Sentinel == '\0') {
        iVar4 = __cxa_guard_acquire(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                                     Links(unsigned_short)::s_Sentinel);
        if (iVar4 != 0) {
          Links::lexical_block_0::s_Sentinel.m_Left = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Right = 0xffff;
          Links::lexical_block_0::s_Sentinel.m_Parent = 0xffff;
          __cxa_guard_release(&CUtlRBTree<CFontTextureCache::cacheentry_t,unsigned_short>::
                               Links(unsigned_short)::s_Sentinel);
        }
      }
      pNVar6 = (this->m_Elements).m_pMemory;
      bVar1 = true;
      uVar3 = (uint)pNVar6[uVar7].super_Links_t.m_Left;
    } while (uVar3 != 0xffff);
  }
LAB_0022422f:
  uVar2 = InsertAt(this,(ushort)uVar7,bVar1);
  pcVar5 = &(this->m_Elements).m_pMemory[uVar2].m_Data;
  if (pcVar5 != (cacheentry_t *)0x0) {
    uVar7 = 0;
    do {
      *(undefined4 *)((int)pcVar5->texCoords + (uVar7 - 0xc)) =
           *(undefined4 *)((int)insert->texCoords + (uVar7 - 0xc));
      uVar7 = uVar7 + 4;
    } while (uVar7 < 0x20);
  }
  return uVar2;
}


