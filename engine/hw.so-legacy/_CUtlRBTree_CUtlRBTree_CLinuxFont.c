// CUtlRBTree<CLinuxFont::font_name_entry,_int>::~CUtlRBTree  @ 002272b0
/* DWARF original prototype: void ~CUtlRBTree(CUtlRBTree<CLinuxFont::font_name_entry,_int> * this,
   int __in_chrg) */

void __thiscall
CUtlRBTree<CLinuxFont::font_name_entry,_int>::~CUtlRBTree
          (CUtlRBTree<CLinuxFont::font_name_entry,_int> *this,int __in_chrg)

{
  Node_t *__ptr;
  
  if (-1 < (this->m_Elements).m_GrowSize) {
    __ptr = (this->m_Elements).m_pMemory;
    if (__ptr != (Node_t *)0x0) {
      free(__ptr);
      (this->m_Elements).m_pMemory = (Node_t *)0x0;
    }
    (this->m_Elements).m_NumAllocated = 0;
  }
  return;
}


