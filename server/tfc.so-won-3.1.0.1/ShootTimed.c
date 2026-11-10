// ShootTimed__8CGrenadeP9entvars_sG6VectorT2f  @ 000a76a0
int * ShootTimed__8CGrenadeP9entvars_sG6VectorT2f
                (undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int unaff_retaddr;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar2 = (int *)GetClassPtr__H1Z8CGrenade_PX01_PX01(0);
  (**(code **)(piVar2[0xf5] + 8))(piVar2);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,param_2);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x20) = *param_3;
  *(undefined4 *)(iVar1 + 0x24) = param_3[1];
  *(undefined4 *)(iVar1 + 0x28) = param_3[2];
  iVar1 = *piVar2;
  UTIL_VecToAngles__FRC6Vector(&local_c,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = local_10;
  *(undefined4 *)(iVar1 + 0x54) = local_c;
  *(undefined4 *)(iVar1 + 0x58) = local_8;
  *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(unaff_retaddr + 0x208);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(float *)(*piVar2 + 0x1e4) = (float)param_3 + *gpGlobals;
  piVar2[3] = -0x10000;
  piVar2[4] = (int)TumbleThink__8CGrenade;
  *(float *)(*piVar2 + 0x104) = *gpGlobals + 0.1;
  if (0x3f < (byte)((0.1 < (float)param_3 | (byte)((ushort)((ushort)NAN((float)param_3) << 10) >> 8)
                    | (byte)((ushort)((ushort)((float)param_3 == 0.1) << 0xe) >> 8)) - 1)) {
    *(float *)(*piVar2 + 0x104) = *gpGlobals;
    iVar1 = *piVar2;
    local_c = 0;
    local_8 = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  uVar3 = (*DAT_001a7fa8)(3,6);
  *(undefined4 *)(*piVar2 + 0x128) = uVar3;
  *(undefined4 *)(*piVar2 + 0x138) = 0x3f800000;
  iVar1 = *piVar2;
  local_c = 0;
  local_8 = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 100) = 0;
  *(undefined4 *)(*piVar2 + 0x11c) = 0x3f000000;
  *(undefined4 *)(*piVar2 + 0x120) = 0x3f4ccccd;
  (*DAT_001a7e48)(*(undefined4 *)(*piVar2 + 0x208),"models/w_grenade.mdl");
  *(undefined4 *)(*piVar2 + 0x1e0) = 0x42c80000;
  return piVar2;
}


