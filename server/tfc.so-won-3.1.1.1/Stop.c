// Stop__10CGunTarget  @ 000d1750
void Stop__10CGunTarget(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x28) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x104) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  return;
}


// Stop__12CBaseMonster  @ 000c3208
void Stop__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x150))(param_1);
  *(undefined4 *)(param_1 + 0x56c) = uVar1;
  return;
}


// Stop__9CPendulum  @ 0008951c
void Stop__9CPendulum(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0x11f];
  *(int *)(iVar1 + 0x54) = param_1[0x120];
  *(int *)(iVar1 + 0x58) = param_1[0x121];
  *(undefined4 *)(*param_1 + 0x1f8) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
  return;
}


