// CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::Find  @ 0024c3d0
/* DWARF original prototype: int
   Find(CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int> * this, char *
   pName) */

int __thiscall
CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::Find
          (CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int> *this,
          char *pName)

{
  bool bVar1;
  Node_t *pNVar2;
  int iVar3;
  int iVar4;
  DictElement_t local_28;
  UtlSymId_t local_1e;
  
                    /* Unresolved local var: DictElement_t elem@[???] */
  local_28.m_Name.m_Id = 0xffff;
  CUtlSymbolTable::AddString((CUtlSymbolTable *)&local_1e,(char *)&this->m_SymbolTable);
                    /* Unresolved local var: int current@[???] */
  iVar4 = (this->m_Elements).m_Root;
  local_28.m_Name.m_Id = local_1e;
  if (iVar4 != -1) {
    pNVar2 = (this->m_Elements).m_Elements.m_pMemory;
    do {
      while( true ) {
        bVar1 = (*(this->m_Elements).m_LessFunc)(&local_28,&pNVar2[iVar4].m_Data);
        if (bVar1) break;
        bVar1 = (*(this->m_Elements).m_LessFunc)
                          (&(this->m_Elements).m_Elements.m_pMemory[iVar4].m_Data,&local_28);
        if (!bVar1) {
          return iVar4;
        }
        if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                         ::Links(int)::s_Sentinel), iVar3 != 0)) {
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::lexical_block_0::s_Sentinel.m_Left = -1;
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::lexical_block_0::s_Sentinel.m_Right = -1;
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                               ::Links(int)::s_Sentinel);
        }
        pNVar2 = (this->m_Elements).m_Elements.m_pMemory;
        iVar4 = pNVar2[iVar4].super_Links_t.m_Right;
        if (iVar4 == -1) {
          return -1;
        }
      }
      if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
           ::Links(int)::s_Sentinel == '\0') &&
         (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                       ::Links(int)::s_Sentinel), iVar3 != 0)) {
        CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
        ::Links::lexical_block_0::s_Sentinel.m_Left = -1;
        CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
        ::Links::lexical_block_0::s_Sentinel.m_Right = -1;
        CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
        ::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                             ::Links(int)::s_Sentinel);
      }
      pNVar2 = (this->m_Elements).m_Elements.m_pMemory;
      iVar4 = pNVar2[iVar4].super_Links_t.m_Left;
    } while (iVar4 != -1);
  }
  return iVar4;
}


