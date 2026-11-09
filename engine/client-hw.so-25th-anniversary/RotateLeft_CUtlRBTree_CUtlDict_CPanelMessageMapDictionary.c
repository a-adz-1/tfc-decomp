// CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>::RotateLeft  @ 00217330
/* DWARF original prototype: void
   RotateLeft(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
   * this, int elem) */

void __thiscall
CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
::RotateLeft(CUtlRBTree<CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,_int>::DictElement_t,_int>
             *this,int elem)

{
  int i;
  Links_t *pLVar1;
  int iVar2;
  
                    /* Unresolved local var: int rightchild@[???] */
  pLVar1 = Links(this,elem);
  i = pLVar1->m_Right;
                    /* try { // try from 0021736b to 0022736f has its CatchHandler @ 00217310 */
  pLVar1 = Links(this,i);
  (this->m_Elements).m_pMemory[elem].super_Links_t.m_Right = pLVar1->m_Left;
  pLVar1 = Links(this,i);
  if (pLVar1->m_Left != -1) {
                    /* try { // try from 0021738f to 00227393 has its CatchHandler @ 00217443 */
    pLVar1 = Links(this,i);
                    /* try { // try from 0021739b to 00227454 has its CatchHandler @ 00217310 */
    (this->m_Elements).m_pMemory[pLVar1->m_Left].super_Links_t.m_Parent = elem;
  }
  iVar2 = -0x18;
  if (i != -1) {
    pLVar1 = Links(this,elem);
    iVar2 = i * 0x18;
    (this->m_Elements).m_pMemory[i].super_Links_t.m_Parent = pLVar1->m_Parent;
  }
  if (elem == this->m_Root) {
                    /* catch() { ... } // from try @ 00217477 with catch @ 00217460
                       catch() { ... } // from try @ 00217524 with catch @ 00217460
                       catch() { ... } // from try @ 00217609 with catch @ 00217460 */
    this->m_Root = i;
  }
  else {
    pLVar1 = Links(this,elem);
    pLVar1 = Links(this,pLVar1->m_Parent);
    if (elem == pLVar1->m_Left) {
                    /* catch() { ... } // from try @ 0021738f with catch @ 00217443 */
      pLVar1 = Links(this,elem);
      (this->m_Elements).m_pMemory[pLVar1->m_Parent].super_Links_t.m_Left = i;
    }
    else {
      pLVar1 = Links(this,elem);
      (this->m_Elements).m_pMemory[pLVar1->m_Parent].super_Links_t.m_Right = i;
    }
  }
  *(int *)((int)&(((this->m_Elements).m_pMemory)->super_Links_t).m_Left + iVar2) = elem;
  if (elem != -1) {
    (this->m_Elements).m_pMemory[elem].super_Links_t.m_Parent = i;
  }
  return;
}


