// CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>::InsertAt  @ 0024d8a0
/* DWARF original prototype: int
   InsertAt(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
   * this, int parent, bool leftchild) */

int __thiscall
CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
::InsertAt(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
           *this,int parent,bool leftchild)

{
  int iVar1;
  size_t __size;
  Node_t *pNVar2;
  int elem;
  
                    /* Unresolved local var: int i@[DW_OP_reg7(EDI)]
                       Unresolved local var: Links_t * elem@[???]
                       Unresolved local var: int newElem@[???] */
  elem = this->m_FirstFree;
  if (elem == -1) {
    elem = this->m_TotalElements;
    if ((this->m_Elements).m_NumAllocated == elem) {
                    /* Unresolved local var: int growSize@[???] */
      iVar1 = (this->m_Elements).m_GrowSize;
      if ((iVar1 == 0) && (iVar1 = 1, elem != 0)) {
        iVar1 = elem;
      }
      pNVar2 = (this->m_Elements).m_pMemory;
      (this->m_Elements).m_NumAllocated = iVar1 + elem;
      __size = (iVar1 + elem) * 0x18;
      if (pNVar2 == (Node_t *)0x0) {
        pNVar2 = malloc(__size);
        (this->m_Elements).m_pMemory = pNVar2;
      }
      else {
        pNVar2 = realloc(pNVar2,__size);
        elem = this->m_TotalElements;
        (this->m_Elements).m_pMemory = pNVar2;
      }
    }
    else {
      pNVar2 = (this->m_Elements).m_pMemory;
    }
    this->m_TotalElements = elem + 1;
    pNVar2 = pNVar2 + elem;
  }
  else {
    if ((CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
         ::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                     ::Links(int)::s_Sentinel), iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
    }
    pNVar2 = (this->m_Elements).m_pMemory + elem;
    this->m_FirstFree = (pNVar2->super_Links_t).m_Right;
  }
  if (pNVar2 != (Node_t *)0xfffffff0) {
    (pNVar2->m_Data).m_Name.m_Id = 0xffff;
    pNVar2 = (this->m_Elements).m_pMemory + elem;
  }
  (pNVar2->super_Links_t).m_Parent = parent;
  (pNVar2->super_Links_t).m_Right = -1;
  (pNVar2->super_Links_t).m_Left = -1;
  (pNVar2->super_Links_t).m_Tag = 0;
  if (parent == -1) {
    this->m_Root = elem;
  }
  else {
    pNVar2 = (this->m_Elements).m_pMemory + parent;
    if (leftchild) {
      (pNVar2->super_Links_t).m_Left = elem;
    }
    else {
      (pNVar2->super_Links_t).m_Right = elem;
    }
  }
  InsertRebalance(this,elem);
  this->m_NumElements = this->m_NumElements + 1;
  return elem;
}


