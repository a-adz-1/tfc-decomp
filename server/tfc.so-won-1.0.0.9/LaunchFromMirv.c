// LaunchFromMirv__10CTFBombletP14CTFMirvGrenade  @ 000fd020
void LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(int *param_1,int *param_2)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_1c = 0.0;
  local_18 = 0.0;
  local_14 = 32.0;
  iVar1 = *param_2;
  local_10 = *(float *)(iVar1 + 8) + 0.0;
  local_c = *(float *)(iVar1 + 0xc) + 0.0;
  local_8 = *(float *)(iVar1 + 0x10) + 32.0;
  lVar4 = (longdouble)(*DAT_0017562c)(0xc2960000,0x42960000);
  lVar5 = (longdouble)(*DAT_0017562c)(0xc2960000,0x42960000);
  lVar6 = (longdouble)(*DAT_0017562c)(0,0x42200000);
  local_14 = (float)((longdouble)5.0 * lVar6);
  local_1c = (float)(lVar4 + lVar4);
  local_18 = (float)(lVar5 + lVar5);
  (**(code **)(param_1[0xf2] + 8))(param_1);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,&local_10);
  iVar1 = *param_1;
  *(float *)(iVar1 + 0x20) = local_1c;
  *(float *)(iVar1 + 0x24) = local_18;
  *(float *)(iVar1 + 0x28) = local_14;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  iVar1 = *param_1;
  UTIL_VecToAngles__FRC6Vector(&local_28,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = local_28;
  *(undefined4 *)(iVar1 + 0x54) = local_24;
  *(undefined4 *)(iVar1 + 0x58) = local_20;
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(*param_2 + 0x178);
  param_1[0x48] = param_2[0x48];
  param_1[5] = -0x10000;
  param_1[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  lVar4 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
  pfVar2 = gpGlobals;
  *(float *)(*param_1 + 0x1c4) = (float)((longdouble)2.0 + (longdouble)*gpGlobals + lVar4);
  param_1[3] = -0x10000;
  param_1[4] = (int)TumbleThink__8CGrenade;
  *(float *)(*param_1 + 0xe4) = *pfVar2 + 0.1;
  uVar3 = (*DAT_00175628)(3,6);
  *(undefined4 *)(*param_1 + 0x108) = uVar3;
  *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f000000;
  *(undefined4 *)(*param_1 + 0x100) = 0x3f4ccccd;
  *(undefined4 *)(*param_1 + 0xec) = 1;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,&local_10);
  return;
}


