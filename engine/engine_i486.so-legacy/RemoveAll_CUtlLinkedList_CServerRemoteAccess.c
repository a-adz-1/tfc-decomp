// CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::RemoveAll  @ 000c9bf0
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RemoveAll(CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>
   * this) */

void __thiscall
CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::RemoveAll
          (CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
                    /* Unresolved local var: int prev@[???] */
  iVar2 = this->m_TotalElements;
  if (iVar2 != 0) {
                    /* Unresolved local var: int i@[???] */
    iVar3 = iVar2 + -1;
    if (-1 < iVar3) {
      iVar4 = iVar3 * 0x20;
      iVar1 = -1;
      while( true ) {
        puVar5 = (undefined4 *)
                 ((int)&(((this->m_Memory).m_pMemory)->m_Element).packet.m_Memory.m_pMemory + iVar4)
        ;
        if ((iVar3 < iVar2) &&
           (((iVar3 != puVar5[6] || (iVar3 == puVar5[7])) && (-1 < (int)puVar5[2])))) {
          if ((void *)*puVar5 != (void *)0x0) {
            free((void *)*puVar5);
            *puVar5 = 0;
          }
          puVar5[1] = 0;
          puVar5 = (undefined4 *)
                   ((int)&(((this->m_Memory).m_pMemory)->m_Element).packet.m_Memory.m_pMemory +
                   iVar4);
        }
        puVar5[7] = iVar1;
        *(int *)((int)&((this->m_Memory).m_pMemory)->m_Previous + iVar4) = iVar3;
        iVar4 = iVar4 + -0x20;
        if (iVar3 + -1 == -1) break;
        iVar2 = this->m_TotalElements;
        iVar1 = iVar3;
        iVar3 = iVar3 + -1;
      }
    }
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_FirstFree = 0;
    this->m_ElementCount = 0;
  }
  return;
}


