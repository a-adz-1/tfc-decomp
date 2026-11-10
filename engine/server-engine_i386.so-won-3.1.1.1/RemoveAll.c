// RemoveAll__t10CUtlVector1ZPQ212CInitTracker8InitFunc  @ 000da9e0
void RemoveAll__t10CUtlVector1ZPQ212CInitTracker8InitFunc(int param_1)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  local_8 = *(int *)(param_1 + 0xc);
  while (local_8 = local_8 + -1, -1 < local_8) {
    uVar1 = Element__t10CUtlVector1ZPQ212CInitTracker8InitFunci(param_1,local_8);
    Destruct__H1ZPQ212CInitTracker8InitFunc_PX01_v(uVar1);
  }
  FUN_000daa2c();
  return;
}


// RemoveAll__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi  @ 000db1b4
void RemoveAll__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    local_8 = InvalidIndex__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi();
    local_c = *(int *)(param_1 + 0x1c);
    while (local_c = local_c + -1, -1 < local_c) {
      cVar1 = IsValidIndex__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                        (param_1,local_c);
      if (cVar1 != '\0') {
        uVar3 = Element__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                          (param_1,local_c);
        Destruct__H1ZQ219CServerRemoteAccess14DataResponse_t_PX01_v(uVar3);
      }
      iVar2 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                        (param_1,local_c);
      *(int *)(iVar2 + 0x1c) = local_8;
      iVar2 = InternalElement__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                        (param_1,local_c);
      *(int *)(iVar2 + 0x18) = local_c;
      local_8 = local_c;
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    uVar3 = InvalidIndex__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi();
    *(undefined4 *)(param_1 + 0xc) = uVar3;
    uVar3 = InvalidIndex__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi();
    *(undefined4 *)(param_1 + 0x10) = uVar3;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}


