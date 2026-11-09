// CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::~CUtlLinkedList  @ 00122100
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void
   ~CUtlLinkedList(CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> * this, int __in_chrg)
    */

void __thiscall
CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::~CUtlLinkedList
          (CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *this,int __in_chrg)

{
  undefined4 *puVar1;
  int iVar2;
  ListElem_t *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int prev@[???] */
  iVar2 = this->m_TotalElements;
  if (iVar2 != 0) {
                    /* Unresolved local var: int i@[???] */
    iVar4 = iVar2 + -1;
    if (-1 < iVar4) {
      iVar7 = iVar4 * 0x20;
      iVar6 = -1;
      while( true ) {
        iVar5 = iVar4;
        if (iVar5 < iVar2) {
          pLVar3 = (this->m_Memory).m_pMemory;
          puVar1 = (undefined4 *)((int)&(pLVar3->m_Element).packet.m_Memory.m_pMemory + iVar7);
          if ((puVar1[6] != iVar5) || (puVar1[7] == iVar5)) {
            if ((-1 < (int)puVar1[2]) && ((void *)*puVar1 != (void *)0x0)) {
              free((void *)*puVar1);
              pLVar3 = (this->m_Memory).m_pMemory;
            }
            puVar1 = (undefined4 *)((int)&(pLVar3->m_Element).packet.m_Memory.m_pMemory + iVar7);
          }
        }
        else {
          puVar1 = (undefined4 *)
                   ((int)&(((this->m_Memory).m_pMemory)->m_Element).packet.m_Memory.m_pMemory +
                   iVar7);
        }
        puVar1[7] = iVar6;
        *(int *)((int)&((this->m_Memory).m_pMemory)->m_Previous + iVar7) = iVar5;
        iVar7 = iVar7 + -0x20;
        if (iVar5 + -1 == -1) break;
        iVar2 = this->m_TotalElements;
        iVar4 = iVar5 + -1;
        iVar6 = iVar5;
      }
    }
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_FirstFree = 0;
    this->m_ElementCount = 0;
  }
  if ((-1 < (this->m_Memory).m_GrowSize) &&
     (pLVar3 = (this->m_Memory).m_pMemory, pLVar3 != (ListElem_t *)0x0)) {
    free(pLVar3);
    return;
  }
  return;
}


