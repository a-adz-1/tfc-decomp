// recvTMessage__15EasyTitanSocketPcPUlN22i  @ 0009c8c4
int recvTMessage__15EasyTitanSocketPcPUlN22i
              (int param_1,void *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
              uint param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar2 = GetTickCount__10EasySocket(param_1);
  uVar1 = *(uint *)(param_1 + 0x28);
  if (uVar1 < 4) {
    iVar3 = recvBuffer__10EasySocketPviPii
                      (param_1,uVar1 + *(int *)(param_1 + 0x20),4 - uVar1,&local_8,param_6);
    if (iVar3 != 0) {
      if (iVar3 != 0x3ed) {
        return iVar3;
      }
      goto LAB_0009c973;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_8;
  }
  iVar3 = GetTickCount__10EasySocket(param_1);
  if (param_6 <= (uint)(iVar3 - iVar2)) {
    param_6 = 0;
  }
  uVar1 = **(uint **)(param_1 + 0x20);
  if (*(uint *)(param_1 + 0x24) < uVar1) {
    return 0x3ef;
  }
  if (uVar1 < 0xc) {
    return 0x3f2;
  }
  iVar2 = recvBuffer__10EasySocketPviPii
                    (param_1,*(int *)(param_1 + 0x28) + (int)*(uint **)(param_1 + 0x20),
                     uVar1 - *(int *)(param_1 + 0x28),&local_8,param_6 - (iVar3 - iVar2));
  if (iVar2 != 0x3ed) {
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = uVar1;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 8);
    }
    memcpy(param_2,*(void **)(param_1 + 0x20),uVar1);
    *(undefined4 *)(param_1 + 0x28) = 0;
    return 0;
  }
LAB_0009c973:
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + local_8;
  return 0x3f4;
}


