// CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::Insert  @ 00217d10
/* DWARF original prototype: int
   Insert(CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int> * this, char *
   pName, PanelMessageMapDictionaryEntry * element) */

int __thiscall
CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::Insert
          (CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int> *this,
          char *pName,PanelMessageMapDictionaryEntry *element)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  Node_t *pNVar5;
  int iVar6;
  CUtlSymbol CStack_26;
  DictElement_t local_24 [2];
  
                    /* Unresolved local var: DictElement_t elem@[???]
                       Unresolved local var: int idx@[DW_OP_reg7(EDI)] */
  local_24[0].m_Name.m_Id = 0xffff;
  CUtlSymbolTable::AddString((CUtlSymbolTable *)&CStack_26,(char *)&this->m_SymbolTable);
                    /* Unresolved local var: int newnode@[???]
                       Unresolved local var: int current@[???]
                       Unresolved local var: int parent@[???]
                       Unresolved local var: bool leftchild@[???] */
  iVar6 = (this->m_Elements).m_Root;
  local_24[0].m_Name.m_Id = CStack_26.m_Id;
  if (iVar6 == -1) {
    bVar2 = false;
  }
  else {
    pNVar5 = (this->m_Elements).m_Elements.m_pMemory;
    iVar3 = iVar6;
    do {
      iVar6 = iVar3;
      bVar2 = (*(this->m_Elements).m_LessFunc)(local_24,&pNVar5[iVar6].m_Data);
      if (bVar2) {
        if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                         ::Links(int)::s_Sentinel), iVar3 != 0)) {
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::s_Sentinel.m_Left = -1;
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::s_Sentinel.m_Right = -1;
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                               ::Links(int)::s_Sentinel);
        }
        pNVar5 = (this->m_Elements).m_Elements.m_pMemory;
        iVar3 = pNVar5[iVar6].super_Links_t.m_Left;
        bVar2 = true;
      }
      else {
        if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
             ::Links(int)::s_Sentinel == '\0') &&
           (iVar3 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                         ::Links(int)::s_Sentinel), iVar3 != 0)) {
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::s_Sentinel.m_Left = -1;
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::s_Sentinel.m_Right = -1;
          CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
          ::Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                               ::Links(int)::s_Sentinel);
        }
        pNVar5 = (this->m_Elements).m_Elements.m_pMemory;
        iVar3 = pNVar5[iVar6].super_Links_t.m_Right;
        bVar2 = false;
      }
    } while (iVar3 != -1);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: int newElem@[???] */
  iVar3 = (this->m_Elements).m_FirstFree;
  if (iVar3 == -1) {
    iVar3 = (this->m_Elements).m_Elements.m_NumAllocated;
    iVar4 = (this->m_Elements).m_TotalElements;
    if (iVar3 == iVar4) {
      iVar4 = (this->m_Elements).m_Elements.m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((iVar4 == 0) && (iVar4 = 1, iVar3 != 0)) {
        iVar4 = iVar3;
      }
                    /* Unresolved local var: int growSize@[???] */
      pNVar5 = (this->m_Elements).m_Elements.m_pMemory;
      iVar4 = iVar4 + iVar3;
      (this->m_Elements).m_Elements.m_NumAllocated = iVar4;
      if (pNVar5 == (Node_t *)0x0) {
        pNVar5 = malloc(iVar4 * 0x18);
        (this->m_Elements).m_Elements.m_pMemory = pNVar5;
      }
      else {
        pNVar5 = realloc(pNVar5,iVar4 * 0x18);
        iVar3 = (this->m_Elements).m_TotalElements;
        (this->m_Elements).m_Elements.m_pMemory = pNVar5;
      }
    }
    else {
      pNVar5 = (this->m_Elements).m_Elements.m_pMemory;
      iVar3 = iVar4;
    }
    (this->m_Elements).m_TotalElements = iVar3 + 1;
    pNVar5 = pNVar5 + iVar3;
  }
  else {
    if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar4 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel), iVar4 != 0)) {
      CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
      ::Links::s_Sentinel.m_Left = -1;
      CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
      ::Links::s_Sentinel.m_Right = -1;
      CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
      ::Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
    }
    pNVar5 = (this->m_Elements).m_Elements.m_pMemory + iVar3;
    (this->m_Elements).m_FirstFree = (pNVar5->super_Links_t).m_Right;
  }
  if (pNVar5 != (Node_t *)0xfffffff0) {
    (pNVar5->m_Data).m_Name.m_Id = 0xffff;
    pNVar5 = (this->m_Elements).m_Elements.m_pMemory + iVar3;
  }
  (pNVar5->super_Links_t).m_Parent = iVar6;
  (pNVar5->super_Links_t).m_Right = -1;
  (pNVar5->super_Links_t).m_Left = -1;
  (pNVar5->super_Links_t).m_Tag = 0;
  if (iVar6 == -1) {
    (this->m_Elements).m_Root = iVar3;
  }
  else {
    pNVar5 = (this->m_Elements).m_Elements.m_pMemory + iVar6;
    if (bVar2) {
      (pNVar5->super_Links_t).m_Left = iVar3;
    }
    else {
      (pNVar5->super_Links_t).m_Right = iVar3;
    }
  }
  CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
  ::InsertRebalance(&this->m_Elements,iVar3);
  pNVar5 = (this->m_Elements).m_Elements.m_pMemory;
  piVar1 = &(this->m_Elements).m_NumElements;
  *piVar1 = *piVar1 + 1;
  pNVar5 = pNVar5 + iVar3;
  if (pNVar5 == (Node_t *)0xfffffff0) {
    pNVar5 = (Node_t *)0xfffffff0;
  }
  else {
    (pNVar5->m_Data).m_Name.m_Id = (UtlSymId_t)local_24[0]._0_4_;
    (pNVar5->m_Data).m_Data.map = local_24[0].m_Data.map;
    pNVar5 = (this->m_Elements).m_Elements.m_pMemory + iVar3;
  }
  (pNVar5->m_Data).m_Data.map = element->map;
  return iVar3;
}


