// ShootTimed__8CGrenadeP9entvars_sG6VectorT2f  @ 000b174c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * ShootTimed__8CGrenadeP9entvars_sG6VectorT2f
                (int param_1,undefined4 param_2,undefined4 *param_3,float param_4)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar3 = (int *)GetClassPtr__H1Z8CGrenade_PX01_PX01(0);
  (**(code **)(piVar3[0x115] + 0xc))(piVar3);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar3,param_2);
  iVar1 = *piVar3;
  *(undefined4 *)(iVar1 + 0x20) = *param_3;
  *(undefined4 *)(iVar1 + 0x24) = param_3[1];
  *(undefined4 *)(iVar1 + 0x28) = param_3[2];
  iVar1 = *piVar3;
  UTIL_VecToAngles__FRC6Vector(&local_10,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = local_10;
  *(undefined4 *)(iVar1 + 0x54) = local_c;
  *(undefined4 *)(iVar1 + 0x58) = local_8;
  *(undefined4 *)(*piVar3 + 0x198) = *(undefined4 *)(param_1 + 0x208);
  piVar3[5] = -0x10000;
  piVar3[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(float *)(*piVar3 + 0x1e4) = param_4 + *gpGlobals;
  piVar3[3] = -0x10000;
  piVar3[4] = (int)TumbleThink__8CGrenade;
  fVar2 = (float)_FUN_0014c250;
  *(float *)(*piVar3 + 0x104) = fVar2 + *gpGlobals;
  if (0x3f < (byte)((fVar2 < param_4 |
                     (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_4)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == param_4) << 0xe) >> 8)) - 1)) {
    *(float *)(*piVar3 + 0x104) = *gpGlobals;
    iVar1 = *piVar3;
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  uVar4 = (*DAT_0019f808)(3,6);
  *(undefined4 *)(*piVar3 + 0x128) = uVar4;
  *(undefined4 *)(*piVar3 + 0x138) = 0x3f800000;
  iVar1 = *piVar3;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 100) = 0;
  *(undefined4 *)(*piVar3 + 0x11c) = 0x3f000000;
  *(undefined4 *)(*piVar3 + 0x120) = 0x3f4ccccd;
  (*DAT_0019f6a8)(*(undefined4 *)(*piVar3 + 0x208),"models/w_grenade.mdl");
  *(undefined4 *)(*piVar3 + 0x1e0) = 0x42c80000;
  return piVar3;
}


