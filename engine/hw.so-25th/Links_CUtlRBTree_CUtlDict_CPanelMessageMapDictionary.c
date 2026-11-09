// CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>::Links  @ 002172b0
/* DWARF original prototype: Links_t *
   Links(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
   * this, int i) */

Links_t * __thiscall
CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
::Links(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
        *this,int i)

{
  int iVar1;
  
  if (CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
      ::Links(int)::s_Sentinel == '\0') {
    iVar1 = __cxa_guard_acquire(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                                 ::Links(int)::s_Sentinel);
                    /* catch() { ... } // from try @ 00217245 with catch @ 002172ef */
    if (iVar1 != 0) {
      Links::s_Sentinel.m_Left = -1;
                    /* catch() { ... } // from try @ 0021739b with catch @ 00217310 */
      Links::s_Sentinel.m_Right = -1;
      Links::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::DictElement_t,int>
                           ::Links(int)::s_Sentinel);
    }
  }
  if (i != -1) {
    return &(this->m_Elements).m_pMemory[i].super_Links_t;
  }
  return &Links::s_Sentinel;
}


