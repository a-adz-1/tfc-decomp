// CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>::RotateRight  @ 00217470
/* DWARF original prototype: void
   RotateRight(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
   * this, int elem) */

void __thiscall
CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
::RotateRight(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
              *this,int elem)

{
  int i;
  Links_t *pLVar1;
  int iVar2;
  
                    /* Unresolved local var: int leftchild@[???] */
                    /* try { // try from 00217477 to 00227509 has its CatchHandler @ 00217460 */
  pLVar1 = Links(this,elem);
  i = pLVar1->m_Left;
  pLVar1 = Links(this,i);
  (this->m_Elements).m_pMemory[elem].super_Links_t.m_Left = pLVar1->m_Right;
  pLVar1 = Links(this,i);
  if (pLVar1->m_Right != -1) {
    pLVar1 = Links(this,i);
    (this->m_Elements).m_pMemory[pLVar1->m_Right].super_Links_t.m_Parent = elem;
  }
  iVar2 = -0x18;
  if (i != -1) {
    pLVar1 = Links(this,elem);
    iVar2 = i * 0x18;
    (this->m_Elements).m_pMemory[i].super_Links_t.m_Parent = pLVar1->m_Parent;
  }
  if (elem == this->m_Root) {
    this->m_Root = i;
  }
  else {
                    /* try { // try from 00217518 to 0022751c has its CatchHandler @ 002175fc */
    pLVar1 = Links(this,elem);
                    /* try { // try from 00217524 to 002275f4 has its CatchHandler @ 00217460 */
    pLVar1 = Links(this,pLVar1->m_Parent);
    if (elem == pLVar1->m_Right) {
      pLVar1 = Links(this,elem);
      (this->m_Elements).m_pMemory[pLVar1->m_Parent].super_Links_t.m_Right = i;
    }
    else {
      pLVar1 = Links(this,elem);
      (this->m_Elements).m_pMemory[pLVar1->m_Parent].super_Links_t.m_Left = i;
    }
  }
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Right + iVar2) = elem;
  if (elem != -1) {
    (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent = i;
  }
  return;
}


