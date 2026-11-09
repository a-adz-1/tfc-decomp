// DoDrop__11CBaseEntityG6Vector  @ 0010d180
void DoDrop__11CBaseEntityG6Vector(int *param_1,undefined4 *param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 8) = *param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_2[1];
  *(undefined4 *)(iVar1 + 0x10) = param_2[2];
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0x174) = 0;
  *(undefined4 *)(*param_1 + 0x28) = 0x43c80000;
  if (1 < param_1[0xc5]) {
    lVar2 = (longdouble)(*DAT_0017562c)(0xc2480000,0x42480000);
    *(float *)(*param_1 + 0x20) = (float)lVar2;
    lVar2 = (longdouble)(*DAT_0017562c)(0xc2480000,0x42480000);
    *(float *)(*param_1 + 0x24) = (float)lVar2;
  }
  param_1[0x86] = 2;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x58) = DAT_00175488;
  if ((*(byte *)((int)param_1 + 0x221) & 0x20) == 0) {
    *(undefined4 *)(*param_1 + 0xec) = 1;
  }
  else {
    *(undefined4 *)(*param_1 + 0xec) = 2;
  }
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,param_1 + 0x9e,param_1 + 0xa1);
  param_1[0xc5] = param_1[0xc5] + 1;
  param_1[3] = -0x10000;
  param_1[4] = (int)tfgoalitem_dropthink__11CBaseEntity;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 5.0;
  return;
}


