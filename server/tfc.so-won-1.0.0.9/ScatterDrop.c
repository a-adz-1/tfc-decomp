// ScatterDrop__10CTFCaltropP11CBaseEntity  @ 000fda50
void ScatterDrop__10CTFCaltropP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_2;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  (**(code **)(param_1[0xf2] + 8))(param_1);
  param_1[0x48] = param_2[0x48];
  *(int *)*param_1 = (int)"tf_weapon_caltrop" - gpGlobals[0x26];
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(*param_2 + 0x1e8);
  setModel__10CTFCaltrop(param_1);
  local_1c = 0x40800000;
  local_18 = 0x40800000;
  local_14 = 0x40800000;
  local_28 = -4.0;
  local_24 = -4.0;
  local_20 = -8.0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_28,&local_1c);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x58) = DAT_00175488;
  lVar2 = (longdouble)(*DAT_0017562c)(0,0x43b40000);
  *(float *)(*param_1 + 0x50) = (float)lVar2;
  iVar1 = *param_1;
  lVar2 = (longdouble)(*DAT_0017562c)(0xc3160000,0x43160000);
  lVar3 = (longdouble)(*DAT_0017562c)(0xc3160000,0x43160000);
  lVar4 = (longdouble)(*DAT_0017562c)(0x43160000,0x43480000);
  local_20 = (float)lVar4;
  *(float *)(iVar1 + 0x20) = (float)lVar2;
  *(float *)(iVar1 + 0x24) = (float)lVar3;
  *(float *)(iVar1 + 0x28) = local_20;
  iVar1 = *param_1;
  local_28 = (float)lVar2;
  local_24 = (float)lVar3;
  lVar2 = (longdouble)(*DAT_0017562c)(0xc3c80000,0x43c80000);
  lVar3 = (longdouble)(*DAT_0017562c)(0xc3c80000,0x43c80000);
  lVar4 = (longdouble)(*DAT_0017562c)(0xc3c80000,0x43c80000);
  local_20 = (float)lVar4;
  *(float *)(iVar1 + 0x5c) = (float)lVar2;
  *(float *)(iVar1 + 0x60) = (float)lVar3;
  *(float *)(iVar1 + 100) = local_20;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
  *(undefined4 *)(*param_1 + 0x100) = 0x3f4ccccd;
  *(undefined4 *)(*param_1 + 0xe8) = 6;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  local_28 = (float)lVar2;
  local_24 = (float)lVar3;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,&local_10);
  param_1[3] = -0x10000;
  param_1[4] = (int)CaltropScatterThink__10CTFCaltrop;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


