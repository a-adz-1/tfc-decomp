// Remove__10ObjectListPv  @ 000cabb4
bool Remove__10ObjectListPv(int param_1,int param_2)

{
  int *local_8;
  
  for (local_8 = *(int **)(param_1 + 4); (local_8 != (int *)0x0 && (local_8[2] != param_2));
      local_8 = (int *)local_8[1]) {
  }
  if (local_8 != (int *)0x0) {
    if (*local_8 != 0) {
      *(int *)(*local_8 + 4) = local_8[1];
    }
    if (local_8[1] != 0) {
      *(int *)local_8[1] = *local_8;
    }
    if (*(int **)(param_1 + 4) == local_8) {
      *(int *)(param_1 + 4) = local_8[1];
    }
    if (*(int **)(param_1 + 8) == local_8) {
      *(int *)(param_1 + 8) = *local_8;
    }
    if (*(int **)(param_1 + 0xc) == local_8) {
      *(int *)(param_1 + 0xc) = local_8[1];
    }
    Mem_Free(local_8);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  }
  return local_8 != (int *)0x0;
}


// Remove__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii  @ 000db5d8
void Remove__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
               (undefined4 param_1,undefined4 param_2)

{
  Free__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1,param_2);
  return;
}


