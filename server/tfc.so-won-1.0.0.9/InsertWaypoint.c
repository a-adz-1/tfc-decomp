// InsertWaypoint__12CBaseMonsterG6Vectori  @ 000c3350
void InsertWaypoint__12CBaseMonsterG6Vectori(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x580) * 0x10 + 0x508 + param_1);
  iVar3 = 7;
  do {
    iVar2 = iVar3 * 0x10 + param_1;
    *(undefined4 *)(iVar2 + 0x4fc) = *(undefined4 *)(iVar2 + 0x4ec);
    *(undefined4 *)(iVar2 + 0x500) = *(undefined4 *)(iVar2 + 0x4f0);
    *(undefined4 *)(iVar2 + 0x504) = *(undefined4 *)(iVar2 + 0x4f4);
    *(undefined4 *)(iVar2 + 0x508) = *(undefined4 *)(iVar2 + 0x4f8);
    iVar3 = iVar3 + -1;
  } while (0 < iVar3);
  iVar3 = *(int *)(param_1 + 0x580) * 0x10 + param_1;
  *(undefined4 *)(iVar3 + 0x4fc) = *param_2;
  *(undefined4 *)(iVar3 + 0x500) = param_2[1];
  *(undefined4 *)(iVar3 + 0x504) = param_2[2];
  *(uint *)(*(int *)(param_1 + 0x580) * 0x10 + 0x508 + param_1) = param_3 | uVar1 & 0xfffffe7f;
  return;
}


