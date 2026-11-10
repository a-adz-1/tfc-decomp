// Alloc__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZib  @ 000db7b0
undefined4
Alloc__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZib(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  iVar1 = InvalidIndex__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi();
  if (*(int *)(param_1 + 0x14) == iVar1) {
    iVar1 = NumAllocated__Ct10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_t
                      (param_1);
    if (*(int *)(param_1 + 0x1c) == iVar1) {
      Grow__t10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_ti
                (param_1,0);
    }
    local_8 = *(undefined4 *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x14);
    iVar1 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,*(undefined4 *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x1c);
  }
  if (param_2 == '\0') {
    iVar1 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,local_8);
    iVar2 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,local_8);
    *(undefined4 *)(iVar2 + 0x18) = local_8;
    *(undefined4 *)(iVar1 + 0x1c) = local_8;
  }
  else {
    iVar1 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,local_8);
    iVar2 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,local_8);
    uVar3 = InvalidIndex__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi();
    *(undefined4 *)(iVar2 + 0x18) = uVar3;
    *(undefined4 *)(iVar1 + 0x1c) = uVar3;
  }
  uVar3 = Element__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1,local_8);
  Construct__H1ZQ219CServerRemoteAccess14DataResponse_t_PX01_v(uVar3);
  ResetDbgInfo__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi(param_1);
  return local_8;
}


