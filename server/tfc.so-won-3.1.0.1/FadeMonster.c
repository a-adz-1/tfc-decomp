// FadeMonster__12CBaseMonster  @ 0008cf0c
void FadeMonster__12CBaseMonster(int *param_1)

{
  int iVar1;
  
  *(undefined4 *)(*param_1 + 0x138) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
  *(undefined4 *)(*param_1 + 0x134) = *gpGlobals;
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
  SUB_StartFadeOut__11CBaseEntity(param_1);
  return;
}


