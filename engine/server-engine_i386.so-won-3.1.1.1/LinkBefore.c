// LinkBefore__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZiii  @ 000db914
void LinkBefore__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZiii
               (int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  Unlink__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1,param_3);
  iVar1 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                    (param_1,param_3);
  *(int *)(iVar1 + 0x1c) = param_2;
  iVar2 = InvalidIndex__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi();
  if (param_2 == iVar2) {
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x10) = param_3;
  }
  else {
    iVar2 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,param_2);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x18);
    *(undefined4 *)(iVar2 + 0x18) = param_3;
  }
  iVar2 = InvalidIndex__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi();
  if (*(int *)(iVar1 + 0x18) == iVar2) {
    *(undefined4 *)(param_1 + 0xc) = param_3;
  }
  else {
    iVar1 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,*(undefined4 *)(iVar1 + 0x18));
    *(undefined4 *)(iVar1 + 0x1c) = param_3;
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}


