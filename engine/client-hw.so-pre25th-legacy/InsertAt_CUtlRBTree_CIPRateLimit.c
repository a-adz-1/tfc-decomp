// CUtlRBTree<CIPRateLimit::iprate_s,_int>::InsertAt  @ 00182ba0
/* DWARF original prototype: int InsertAt(CUtlRBTree<CIPRateLimit::iprate_s,_int> * this, int
   parent, bool leftchild) */

int __thiscall
CUtlRBTree<CIPRateLimit::iprate_s,_int>::InsertAt
          (CUtlRBTree<CIPRateLimit::iprate_s,_int> *this,int parent,bool leftchild)

{
  int iVar1;
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
      iVar1 = iVar1 + elem;
      (this->m_Elements).m_NumAllocated = iVar1;
      if (pNVar2 == (Node_t *)0x0) {
        pNVar2 = malloc(iVar1 * 0x1c);
        (this->m_Elements).m_pMemory = pNVar2;
      }
      else {
        pNVar2 = realloc(pNVar2,iVar1 * 0x1c);
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
    if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
       (iVar1 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
       , iVar1 != 0)) {
      Links::lexical_block_0::s_Sentinel.m_Right = -1;
      Links::lexical_block_0::s_Sentinel.m_Left = -1;
      Links::lexical_block_0::s_Sentinel.m_Parent = -1;
      __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    }
    pNVar2 = (this->m_Elements).m_pMemory + elem;
    this->m_FirstFree = (pNVar2->super_Links_t).m_Right;
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


