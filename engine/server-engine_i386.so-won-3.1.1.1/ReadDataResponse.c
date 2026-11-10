// ReadDataResponse__19CServerRemoteAccessPvi  @ 000c6c78
size_t ReadDataResponse__19CServerRemoteAccessPvi(int param_1,void *param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *__src;
  size_t __n;
  undefined4 local_10;
  
  uVar2 = Head__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi(param_1 + 4);
  cVar1 = IsValidIndex__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                    (param_1 + 4,uVar2);
  if (cVar1 == '\0') {
    local_10 = 0;
  }
  else {
    uVar3 = __vc__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1 + 4,uVar2);
    local_10 = TellPut__C10CUtlBuffer(uVar3);
    if (param_3 < (int)local_10) {
      local_10 = 0;
    }
    else {
      __n = local_10;
      __src = (void *)Base__10CUtlBuffer(uVar3);
      memcpy(param_2,__src,__n);
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_10;
    Remove__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1 + 4,uVar2);
  }
  return local_10;
}


