// IsInList__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii  @ 000db410
undefined1
IsInList__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_5;
  
  local_5 = 0;
  if ((param_2 < *(int *)(param_1 + 0x1c)) && (-1 < param_2)) {
    iVar1 = Previous__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
                      (param_1,param_2);
    if (iVar1 != param_2) {
      local_5 = 1;
    }
  }
  return local_5;
}


