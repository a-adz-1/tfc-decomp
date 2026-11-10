// recvTMessage__15EasyTitanSocketPcPUlN22i  @ 000d56e0
int recvTMessage__15EasyTitanSocketPcPUlN22i
              (int param_1,void *param_2,size_t *param_3,undefined4 *param_4,undefined4 *param_5,
              uint param_6)

{
  char cVar1;
  int iVar2;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_c = GetTickCount__10EasySocket(param_1);
  if (*(uint *)(param_1 + 0x28) < 4) {
    iVar2 = recvBuffer__10EasySocketPviPii
                      (param_1,*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28),
                       4 - *(int *)(param_1 + 0x28),&local_18,param_6);
    if (iVar2 != 0) {
      if (iVar2 != 0x3ed) {
        return iVar2;
      }
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_18;
      return 0x3f4;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_18;
    local_8 = 0;
  }
  iVar2 = GetTickCount__10EasySocket(param_1);
  local_10 = iVar2 - local_c;
  if (param_6 <= local_10) {
    param_6 = 0;
  }
  local_14 = **(uint **)(param_1 + 0x20);
  if (*(uint *)(param_1 + 0x24) < local_14) {
    local_8 = 0x3ef;
  }
  else if (local_14 < 0xc) {
    local_8 = 0x3f2;
  }
  else {
    local_8 = recvBuffer__10EasySocketPviPii
                        (param_1,*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28),
                         local_14 - *(int *)(param_1 + 0x28),&local_18,param_6 - local_10);
    if (local_8 == 0x3ed) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_18;
      local_8 = 0x3f4;
    }
    else {
      local_1c = 0;
      cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_8,&local_1c);
      if (cVar1 == '\0') {
        if (param_3 != (size_t *)0x0) {
          *param_3 = local_14;
        }
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 8);
        }
        memcpy(param_2,*(void **)(param_1 + 0x20),local_14);
        *(undefined4 *)(param_1 + 0x28) = 0;
        local_8 = 0;
      }
    }
  }
  return local_8;
}


