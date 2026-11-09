// CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::Unlink  @ 0017e4b0
/* DWARF original prototype: void Unlink(CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *
   this, int elem) */

void __thiscall
CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::Unlink
          (CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *this,int elem)

{
  ListElem_t *pLVar1;
  int iVar2;
  
  if (elem < 0) {
    return;
  }
  if (elem < this->m_TotalElements) {
    pLVar1 = (this->m_Memory).m_pMemory;
    iVar2 = pLVar1[elem].m_Previous;
    if (elem != iVar2) {
                    /* Unresolved local var: ListElem_t * oldElem@[???] */
      if (iVar2 == -1) {
        this->m_Head = pLVar1[elem].m_Next;
        iVar2 = pLVar1[elem].m_Next;
      }
      else {
        pLVar1[iVar2].m_Next = pLVar1[elem].m_Next;
        iVar2 = pLVar1[elem].m_Next;
      }
      if (iVar2 == -1) {
        this->m_Tail = pLVar1[elem].m_Previous;
      }
      else {
        (this->m_Memory).m_pMemory[iVar2].m_Previous = pLVar1[elem].m_Previous;
      }
      pLVar1[elem].m_Next = elem;
      pLVar1[elem].m_Previous = elem;
      this->m_ElementCount = this->m_ElementCount + -1;
      return;
    }
    return;
  }
  return;
}


