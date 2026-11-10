// recvTMessage__15EasyTitanSocketPcPUlN22i  @ 0808d930
int recvTMessage__15EasyTitanSocketPcPUlN22i
              (int param_1,void *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
              uint param_6)

{
  uint __n;
  int iVar1;
  int iVar2;
  int local_8;
  
  iVar1 = GetTickCount();
  if (*(uint *)(param_1 + 0x28) < 4) {
    iVar2 = recvBuffer__10EasySocketPviPii
                      (param_1,*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x20),
                       4 - *(int *)(param_1 + 0x28),&local_8,param_6);
    if (iVar2 != 0) {
      if (iVar2 != 0x3ed) {
        return iVar2;
      }
      goto LAB_0808d9e5;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_8;
  }
  iVar2 = GetTickCount();
  if (param_6 <= (uint)(iVar2 - iVar1)) {
    param_6 = 0;
  }
  __n = **(uint **)(param_1 + 0x20);
  if (*(uint *)(param_1 + 0x24) < __n) {
    return 0x3ef;
  }
  if (__n < 0xc) {
    return 0x3f2;
  }
  iVar1 = recvBuffer__10EasySocketPviPii
                    (param_1,*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x20),
                     __n - *(int *)(param_1 + 0x28),&local_8,param_6 - (iVar2 - iVar1));
  if (iVar1 != 0x3ed) {
    if (iVar1 != 0) {
      return iVar1;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = __n;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 8);
    }
    memcpy(param_2,*(void **)(param_1 + 0x20),__n);
    *(undefined4 *)(param_1 + 0x28) = 0;
    return 0;
  }
LAB_0808d9e5:
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_8;
  return 0x3f4;
}


