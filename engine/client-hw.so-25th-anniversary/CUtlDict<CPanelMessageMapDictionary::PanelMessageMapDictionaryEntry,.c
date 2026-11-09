// CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictLessFunc  @ 00217240
bool CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictLessFunc
               (DictElement_t *src1,DictElement_t *src2)

{
  return (src1->m_Name).m_Id < (src2->m_Name).m_Id;
}


