// ScatterDrop__10CTFCaltropP11CBaseEntity  @ 000ffe18
void ScatterDrop__10CTFCaltropP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_2 == (int *)0x0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
  }
  else {
    iVar1 = *param_2;
    local_10 = *(undefined4 *)(iVar1 + 8);
    local_c = *(undefined4 *)(iVar1 + 0xc);
    local_8 = *(undefined4 *)(iVar1 + 0x10);
  }
  (**(code **)(param_1[0x115] + 0xc))(param_1);
  if (param_2 != (int *)0x0) {
    param_1[0x48] = param_2[0x48];
  }
  *(int *)*param_1 = (int)"tf_weapon_caltrop" - (int)gpGlobals[0x26];
  if (param_2 != (int *)0x0) {
    *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
  }
  setModel__10CTFCaltrop(param_1);
  uStack_1c = 0x40800000;
  fStack_28 = -4.0;
  fStack_20 = -8.0;
  fStack_24 = fStack_28;
  uStack_18 = uStack_1c;
  uStack_14 = uStack_1c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&fStack_28,&uStack_1c);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  lVar2 = (longdouble)(*DAT_0019f80c)(0,0x43b40000);
  *(float *)(*param_1 + 0x50) = (float)lVar2;
  iVar1 = *param_1;
  lVar2 = (longdouble)(*DAT_0019f80c)(0xc3160000,0x43160000);
  lVar3 = (longdouble)(*DAT_0019f80c)(0xc3160000,0x43160000);
  lVar4 = (longdouble)(*DAT_0019f80c)(0x43160000,0x43480000);
  fStack_20 = (float)lVar4;
  *(float *)(iVar1 + 0x20) = (float)lVar2;
  *(float *)(iVar1 + 0x24) = (float)lVar3;
  *(float *)(iVar1 + 0x28) = fStack_20;
  iVar1 = *param_1;
  fStack_28 = (float)lVar2;
  fStack_24 = (float)lVar3;
  lVar2 = (longdouble)(*DAT_0019f80c)(0xc3c80000,0x43c80000);
  lVar3 = (longdouble)(*DAT_0019f80c)(0xc3c80000,0x43c80000);
  lVar4 = (longdouble)(*DAT_0019f80c)(0xc3c80000,0x43c80000);
  fStack_20 = (float)lVar4;
  *(float *)(iVar1 + 0x5c) = (float)lVar2;
  *(float *)(iVar1 + 0x60) = (float)lVar3;
  *(float *)(iVar1 + 100) = fStack_20;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f4ccccd;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  fStack_28 = (float)lVar2;
  fStack_24 = (float)lVar3;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,&local_10);
  lVar2 = (longdouble)(*DAT_0019f80c)(0x41200000,0x41700000);
  param_1[0x116] = (int)(float)(lVar2 + (longdouble)*gpGlobals);
  param_1[3] = -0x10000;
  param_1[4] = (int)CaltropScatterThink__10CTFCaltrop;
  *(float *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


