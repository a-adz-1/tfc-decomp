// CUtlRBTree<(anonymous_namespace)::Texture,_int>::~CUtlRBTree  @ 001746f0
/* DWARF original prototype: void ~CUtlRBTree(CUtlRBTree<(anonymous_namespace)::Texture,_int> *
   this, int __in_chrg) */

void __thiscall
CUtlRBTree<(anonymous_namespace)::Texture,_int>::~CUtlRBTree
          (CUtlRBTree<(anonymous_namespace)::Texture,_int> *this,int __in_chrg)

{
  Node_t *__ptr;
  
  if ((-1 < (this->m_Elements).m_GrowSize) &&
     (__ptr = (this->m_Elements).m_pMemory, __ptr != (Node_t *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


