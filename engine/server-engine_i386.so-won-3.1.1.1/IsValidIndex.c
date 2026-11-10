// IsValidIndex__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii  @ 000ddc64
bool IsValidIndex__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = LeftChild__Ct10CUtlRBTree2ZQ212CIPRateLimit8iprate_sZii(param_1,param_2);
  return iVar1 != param_2;
}


// IsValidIndex__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii  @ 000dbe98
undefined1
IsValidIndex__Ct14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
          (int param_1,int param_2)

{
  int iVar1;
  undefined1 local_5;
  
  local_5 = 0;
  if (((param_2 < *(int *)(param_1 + 0x1c)) && (-1 < param_2)) &&
     ((iVar1 = __vc__Ct10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_ti
                         (param_1,param_2), *(int *)(iVar1 + 0x18) != param_2 ||
      (iVar1 = __vc__Ct10CUtlMemory1ZQ2t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi10ListElem_ti
                         (param_1,param_2), *(int *)(iVar1 + 0x1c) == param_2)))) {
    local_5 = 1;
  }
  return local_5;
}


