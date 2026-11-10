// LaunchFromMirv__10CTFBombletP14CTFMirvGrenade  @ 000fd458
void LaunchFromMirv__10CTFBombletP14CTFMirvGrenade(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  float local_18;
  float local_14;
  float local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  local_10 = 32.0;
  local_18 = 0.0;
  local_14 = 0.0;
  iVar1 = *param_2;
  uStack_c = *(undefined4 *)(iVar1 + 8);
  uStack_8 = *(undefined4 *)(iVar1 + 0xc);
  fStack_4 = *(float *)(iVar1 + 0x10) + 32.0;
  lVar4 = (longdouble)(*DAT_001c118c)(0xc2960000,0x42960000);
  lVar5 = (longdouble)(*DAT_001c118c)(0xc2960000,0x42960000);
  lVar6 = (longdouble)(*DAT_001c118c)(0,0x42200000);
  local_10 = (float)((longdouble)5.0 * lVar6);
  local_18 = (float)(lVar4 + lVar4);
  local_14 = (float)(lVar5 + lVar5);
  (**(code **)(param_1[0x111] + 0xc))(param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,&uStack_c);
  iVar1 = *param_1;
  *(float *)(iVar1 + 0x20) = local_18;
  *(float *)(iVar1 + 0x24) = local_14;
  *(float *)(iVar1 + 0x28) = local_10;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 100) = DAT_001c0fe8;
  iVar2 = *param_1;
  UTIL_VecToAngles__FRC6Vector(&uStack_24,iVar2 + 0x20);
  *(undefined4 *)(iVar2 + 0x50) = uStack_28;
  *(undefined4 *)(iVar2 + 0x54) = uStack_24;
  *(undefined4 *)(iVar2 + 0x58) = uStack_20;
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x198);
  param_1[0x48] = param_2[0x48];
  param_1[5] = -0x10000;
  param_1[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  lVar4 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
  *(float *)(*param_1 + 0x1e4) = (float)((longdouble)2.0 + (longdouble)*gpGlobals + lVar4);
  param_1[3] = -0x10000;
  param_1[4] = (int)TumbleThink__8CGrenade;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  uVar3 = (*DAT_001c1188)(3,6);
  *(undefined4 *)(*param_1 + 0x128) = uVar3;
  *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f4ccccd;
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,iVar1);
  return;
}


