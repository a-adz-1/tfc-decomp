// FadeMonster__12CBaseMonster  @ 000a4680
void FadeMonster__12CBaseMonster(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x118) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0x114) = *gpGlobals;
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x20;
  SUB_StartFadeOut__11CBaseEntity(param_1);
  return;
}


