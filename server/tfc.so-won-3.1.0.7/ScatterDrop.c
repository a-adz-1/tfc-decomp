// ScatterDrop__10CTFCaltropP11CBaseEntity  @ 000fe28c
void ScatterDrop__10CTFCaltropP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_2 == (int *)0x0) {
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
  }
  else {
    iVar1 = *param_2;
    local_c = *(undefined4 *)(iVar1 + 8);
    local_8 = *(undefined4 *)(iVar1 + 0xc);
    local_4 = *(undefined4 *)(iVar1 + 0x10);
  }
  (**(code **)(param_1[0x111] + 0xc))(param_1);
  if (param_2 != (int *)0x0) {
    param_1[0x48] = param_2[0x48];
  }
  *(int *)*param_1 = (int)"tf_weapon_caltrop" - (int)gpGlobals[0x26];
  if (param_2 != (int *)0x0) {
    *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
  }
  setModel__10CTFCaltrop(param_1);
  local_18 = 0x40800000;
  local_24 = -4.0;
  local_1c = -8.0;
  local_20 = local_24;
  local_14 = local_18;
  local_10 = local_18;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_24,&local_18);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 0x58) = DAT_001c0fe8;
  lVar2 = (longdouble)(*DAT_001c118c)(0,0x43b40000);
  *(float *)(*param_1 + 0x50) = (float)lVar2;
  iVar1 = *param_1;
  lVar2 = (longdouble)(*DAT_001c118c)(0xc3160000,0x43160000);
  lVar3 = (longdouble)(*DAT_001c118c)(0xc3160000,0x43160000);
  lVar4 = (longdouble)(*DAT_001c118c)(0x43160000,0x43480000);
  local_1c = (float)lVar4;
  *(float *)(iVar1 + 0x20) = (float)lVar2;
  *(float *)(iVar1 + 0x24) = (float)lVar3;
  *(float *)(iVar1 + 0x28) = local_1c;
  iVar1 = *param_1;
  local_24 = (float)lVar2;
  local_20 = (float)lVar3;
  lVar2 = (longdouble)(*DAT_001c118c)(0xc3c80000,0x43c80000);
  lVar3 = (longdouble)(*DAT_001c118c)(0xc3c80000,0x43c80000);
  lVar4 = (longdouble)(*DAT_001c118c)(0xc3c80000,0x43c80000);
  local_1c = (float)lVar4;
  *(float *)(iVar1 + 0x5c) = (float)lVar2;
  *(float *)(iVar1 + 0x60) = (float)lVar3;
  *(float *)(iVar1 + 100) = local_1c;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f4ccccd;
  *(undefined4 *)(*param_1 + 0x108) = 6;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_24 = (float)lVar2;
  local_20 = (float)lVar3;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,&local_c);
  lVar2 = (longdouble)(*DAT_001c118c)(0x41200000,0x41700000);
  param_1[0x112] = (int)(float)(lVar2 + (longdouble)*gpGlobals);
  param_1[3] = -0x10000;
  param_1[4] = (int)CaltropScatterThink__10CTFCaltrop;
  *(float *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


