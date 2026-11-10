// DeadThrow__15CTFPrimeGrenade  @ 000fc9f4
void DeadThrow__15CTFPrimeGrenade(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      piVar3 = (int *)0x0;
      goto LAB_000fca36;
    }
  }
  piVar3 = *(int **)(iVar1 + 0x7c);
LAB_000fca36:
  (**(code **)(param_1[0x111] + 0xc))(param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*piVar3 + 8);
  iVar1 = *param_1;
  local_4 = 0x41f00000;
  local_c = 0;
  local_8 = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0x41f00000;
  iVar1 = *param_1;
  UTIL_VecToAngles__FRC6Vector(&local_c,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = local_10;
  *(undefined4 *)(iVar1 + 0x54) = local_c;
  *(undefined4 *)(iVar1 + 0x58) = local_8;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 100) = DAT_001c0fe8;
  param_1[5] = -0x10000;
  param_1[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(int *)(*param_1 + 0x1e4) = param_1[0x1aa];
  param_1[3] = -0x10000;
  param_1[4] = (int)TumbleThink__8CGrenade;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  uVar2 = (*DAT_001c1188)(3,6);
  *(undefined4 *)(*param_1 + 0x128) = uVar2;
  *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0x11c) = 0x3f4f5c29;
  *(undefined4 *)(*param_1 + 0x120) = 0x3f19999a;
  return;
}


