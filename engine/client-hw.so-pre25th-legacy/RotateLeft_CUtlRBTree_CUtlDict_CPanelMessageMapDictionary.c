// CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>::RotateLeft  @ 0024c500
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void
   RotateLeft(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
   * this, int elem) */

void __thiscall
CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
::RotateLeft(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
             *this,int elem)

{
  Node_t *pNVar1;
  Links_t *pLVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
                    /* Unresolved local var: int rightchild@[DW_OP_reg7(EDI)] */
  if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                   ::Links(int)::s_Sentinel), iVar3 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                         ::Links(int)::s_Sentinel);
  }
  if (elem == -1) {
    iVar7 = -0x18;
    iVar3 = Links::lexical_block_0::s_Sentinel.m_Right;
  }
  else {
    iVar7 = elem * 0x18;
    iVar3 = (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right;
  }
  if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
       ::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                   ::Links(int)::s_Sentinel), iVar6 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                         ::Links(int)::s_Sentinel);
  }
  if (iVar3 == -1) {
    pNVar1 = (this->m_Elements).m_pMemory;
    iVar6 = -0x18;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
  }
  else {
    pNVar1 = (this->m_Elements).m_pMemory;
    iVar6 = iVar3 * 0x18;
    pLVar2 = &pNVar1[iVar3].super_Links_t;
  }
  bVar8 = CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
          ::Links(int)::s_Sentinel == '\0';
  *(int *)((int)&(pNVar1->super_Links_t).m_Right + iVar7) =
       (((Node_t *)pLVar2)->super_Links_t).m_Left;
  if ((bVar8) &&
     (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                   ::Links(int)::s_Sentinel), iVar5 != 0)) {
    Links::lexical_block_0::s_Sentinel.m_Left = -1;
    Links::lexical_block_0::s_Sentinel.m_Right = -1;
    Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                         ::Links(int)::s_Sentinel);
  }
  pLVar2 = &Links::lexical_block_0::s_Sentinel;
  if (iVar3 != -1) {
    pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6);
  }
  if (pLVar2->m_Left != -1) {
    if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (iVar3 != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar6);
    }
    pNVar1[pLVar2->m_Left].super_Links_t.m_Parent = elem;
  }
  if (iVar3 != -1) {
    if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
    }
    pNVar1 = (this->m_Elements).m_pMemory;
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
    }
    *(int *)((int)&(pNVar1->super_Links_t).m_Parent + iVar6) = pLVar2->m_Parent;
  }
  if (elem == this->m_Root) {
    this->m_Root = iVar3;
  }
  else {
    if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel), iVar5 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
    }
    pLVar2 = &Links::lexical_block_0::s_Sentinel;
    if (elem != -1) {
      pLVar2 = (Links_t *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar7);
    }
    iVar5 = pLVar2->m_Parent;
    if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
    }
    pNVar1 = (Node_t *)&Links::lexical_block_0::s_Sentinel;
    if (iVar5 != -1) {
      pNVar1 = (this->m_Elements).m_pMemory + iVar5;
    }
    if (elem == (pNVar1->super_Links_t).m_Left) {
      if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                       ::Links(int)::s_Sentinel), iVar5 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
      }
      pNVar1[pLVar2->m_Parent].super_Links_t.m_Left = iVar3;
    }
    else {
      if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar5 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                       ::Links(int)::s_Sentinel), iVar5 != 0)) {
        Links::lexical_block_0::s_Sentinel.m_Right = -1;
        Links::lexical_block_0::s_Sentinel.m_Left = -1;
        Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
      }
      pNVar1 = (this->m_Elements).m_pMemory;
      pLVar2 = &Links::lexical_block_0::s_Sentinel;
      if (elem != -1) {
        pLVar2 = (Links_t *)((int)&(pNVar1->super_Links_t).m_Left + iVar7);
      }
      pNVar1[pLVar2->m_Parent].super_Links_t.m_Right = iVar3;
    }
  }
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar6) = elem;
  if (elem != -1) {
    *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Parent + iVar7) = iVar3;
  }
  return;
}


