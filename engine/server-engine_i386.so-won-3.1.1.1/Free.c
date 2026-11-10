// Free__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii  @ 000db550
void Free__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
               (int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = Element__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1,param_2);
  Destruct__H1ZQ219CServerRemoteAccess14DataResponse_t_PX01_v(uVar2);
  cVar1 = IsInList__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1,param_2);
  if (cVar1 != '\0') {
    Unlink__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1,param_2);
  }
  iVar3 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                    (param_1,param_2);
  *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


