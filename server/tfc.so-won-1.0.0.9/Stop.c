// Stop__10CGunTarget  @ 000d5a90
void Stop__10CGunTarget(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0xe4) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  return;
}


// Stop__12CBaseMonster  @ 000c88c0
void Stop__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x148))(param_1);
  *(undefined4 *)(param_1 + 0x4e0) = uVar1;
  return;
}


// Stop__9CPendulum  @ 0009cee0
void Stop__9CPendulum(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x50) = param_1[0xfc];
  *(int *)(iVar1 + 0x54) = param_1[0xfd];
  *(int *)(iVar1 + 0x58) = param_1[0xfe];
  *(undefined4 *)(*param_1 + 0x1d8) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  return;
}


