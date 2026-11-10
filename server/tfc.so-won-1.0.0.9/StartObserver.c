// StartObserver__11CBasePlayerG6VectorT1  @ 000d9230
void StartObserver__11CBasePlayerG6VectorT1(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) | 0x20;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x154) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x158) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x15c) = DAT_00175488;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x74) = *param_3;
  *(undefined4 *)(iVar1 + 0x78) = param_3[1];
  *(undefined4 *)(iVar1 + 0x7c) = param_3[2];
  iVar2 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar2 + 0x74);
  *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar2 + 0x78);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar2 + 0x7c);
  *(undefined4 *)(*param_1 + 0x80) = 1;
  *(undefined4 *)(*param_1 + 0xec) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  *(undefined4 *)(*param_1 + 0xe8) = 0;
  *(undefined4 *)(*param_1 + 0x94) = 0;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,param_2);
  return;
}


