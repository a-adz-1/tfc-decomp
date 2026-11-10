// InsertWaypoint__12CBaseMonsterG6Vectori  @ 000bc5b4
void InsertWaypoint__12CBaseMonsterG6Vectori(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x5fc) * 0x10;
  uVar1 = *(uint *)(iVar2 + param_1 + 0x584);
  *(undefined4 *)(param_1 + 0x5e8) = *(undefined4 *)(param_1 + 0x5d8);
  *(undefined4 *)(param_1 + 0x5ec) = *(undefined4 *)(param_1 + 0x5dc);
  *(undefined4 *)(param_1 + 0x5f0) = *(undefined4 *)(param_1 + 0x5e0);
  *(undefined4 *)(param_1 + 0x5f4) = *(undefined4 *)(param_1 + 0x5e4);
  *(undefined4 *)(param_1 + 0x5d8) = *(undefined4 *)(param_1 + 0x5c8);
  *(undefined4 *)(param_1 + 0x5dc) = *(undefined4 *)(param_1 + 0x5cc);
  *(undefined4 *)(param_1 + 0x5e0) = *(undefined4 *)(param_1 + 0x5d0);
  *(undefined4 *)(param_1 + 0x5e4) = *(undefined4 *)(param_1 + 0x5d4);
  *(undefined4 *)(param_1 + 0x5c8) = *(undefined4 *)(param_1 + 0x5b8);
  *(undefined4 *)(param_1 + 0x5cc) = *(undefined4 *)(param_1 + 0x5bc);
  *(undefined4 *)(param_1 + 0x5d0) = *(undefined4 *)(param_1 + 0x5c0);
  *(undefined4 *)(param_1 + 0x5d4) = *(undefined4 *)(param_1 + 0x5c4);
  *(undefined4 *)(param_1 + 0x5b8) = *(undefined4 *)(param_1 + 0x5a8);
  *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(param_1 + 0x5ac);
  *(undefined4 *)(param_1 + 0x5c0) = *(undefined4 *)(param_1 + 0x5b0);
  *(undefined4 *)(param_1 + 0x5c4) = *(undefined4 *)(param_1 + 0x5b4);
  *(undefined4 *)(param_1 + 0x5a8) = *(undefined4 *)(param_1 + 0x598);
  *(undefined4 *)(param_1 + 0x5ac) = *(undefined4 *)(param_1 + 0x59c);
  *(undefined4 *)(param_1 + 0x5b0) = *(undefined4 *)(param_1 + 0x5a0);
  *(undefined4 *)(param_1 + 0x5b4) = *(undefined4 *)(param_1 + 0x5a4);
  *(undefined4 *)(param_1 + 0x598) = *(undefined4 *)(param_1 + 0x588);
  *(undefined4 *)(param_1 + 0x59c) = *(undefined4 *)(param_1 + 0x58c);
  *(undefined4 *)(param_1 + 0x5a0) = *(undefined4 *)(param_1 + 0x590);
  *(undefined4 *)(param_1 + 0x5a4) = *(undefined4 *)(param_1 + 0x594);
  *(undefined4 *)(param_1 + 0x588) = *(undefined4 *)(param_1 + 0x578);
  *(undefined4 *)(param_1 + 0x58c) = *(undefined4 *)(param_1 + 0x57c);
  *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)(param_1 + 0x580);
  *(undefined4 *)(param_1 + 0x594) = *(undefined4 *)(param_1 + 0x584);
  iVar2 = iVar2 + param_1;
  *(undefined4 *)(iVar2 + 0x578) = *param_2;
  *(undefined4 *)(iVar2 + 0x57c) = param_2[1];
  *(undefined4 *)(iVar2 + 0x580) = param_2[2];
  *(uint *)(*(int *)(param_1 + 0x5fc) * 0x10 + param_1 + 0x584) = param_3 | uVar1 & 0xfffffe7f;
  return;
}


