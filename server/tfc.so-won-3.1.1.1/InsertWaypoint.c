// InsertWaypoint__12CBaseMonsterG6Vectori  @ 000c242c
void InsertWaypoint__12CBaseMonsterG6Vectori(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 7;
  uVar1 = *(uint *)(*(int *)(param_1 + 0x60c) * 0x10 + param_1 + 0x594);
  do {
    iVar2 = iVar3 * 0x10 + param_1;
    iVar3 = iVar3 + -1;
    *(undefined4 *)(iVar2 + 0x588) = *(undefined4 *)(iVar2 + 0x578);
    *(undefined4 *)(iVar2 + 0x58c) = *(undefined4 *)(iVar2 + 0x57c);
    *(undefined4 *)(iVar2 + 0x590) = *(undefined4 *)(iVar2 + 0x580);
    *(undefined4 *)(iVar2 + 0x594) = *(undefined4 *)(iVar2 + 0x584);
  } while (0 < iVar3);
  iVar3 = *(int *)(param_1 + 0x60c) * 0x10 + param_1;
  *(undefined4 *)(iVar3 + 0x588) = *param_2;
  *(undefined4 *)(iVar3 + 0x58c) = param_2[1];
  *(undefined4 *)(iVar3 + 0x590) = param_2[2];
  *(uint *)(*(int *)(param_1 + 0x60c) * 0x10 + param_1 + 0x594) = uVar1 & 0xfffffe7f | param_3;
  return;
}


