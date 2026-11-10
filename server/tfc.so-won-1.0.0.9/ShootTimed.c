// ShootTimed__8CGrenadeP9entvars_tG6VectorT2f  @ 000b9ce0
int * ShootTimed__8CGrenadeP9entvars_tG6VectorT2f
                (int param_1,undefined4 param_2,undefined4 *param_3,float param_4)

{
  int iVar1;
  float *pfVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar3 = (int *)GetClassPtr__H1Z8CGrenade_PX01_PX01(0);
  (**(code **)(piVar3[0xf2] + 8))(piVar3);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar3,param_2);
  iVar1 = *piVar3;
  *(undefined4 *)(iVar1 + 0x20) = *param_3;
  *(undefined4 *)(iVar1 + 0x24) = param_3[1];
  *(undefined4 *)(iVar1 + 0x28) = param_3[2];
  iVar1 = *piVar3;
  UTIL_VecToAngles__FRC6Vector(&uStack_10,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = uStack_10;
  *(undefined4 *)(iVar1 + 0x54) = uStack_c;
  *(undefined4 *)(iVar1 + 0x58) = uStack_8;
  *(undefined4 *)(*piVar3 + 0x178) = *(undefined4 *)(param_1 + 0x1e8);
  piVar3[5] = -0x10000;
  piVar3[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  pfVar2 = gpGlobals;
  *(float *)(*piVar3 + 0x1c4) = param_4 + *gpGlobals;
  piVar3[3] = -0x10000;
  piVar3[4] = (int)TumbleThink__8CGrenade;
  *(float *)(*piVar3 + 0xe4) = *pfVar2 + 0.1;
  if (param_4 < 0.1) {
    *(float *)(*piVar3 + 0xe4) = *pfVar2;
    iVar1 = *piVar3;
    uStack_10 = 0;
    uStack_c = 0;
    uStack_8 = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  uVar4 = (*DAT_00175628)(3,6);
  *(undefined4 *)(*piVar3 + 0x108) = uVar4;
  *(undefined4 *)(*piVar3 + 0x118) = 0x3f800000;
  iVar1 = *piVar3;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 100) = 0;
  *(undefined4 *)(*piVar3 + 0xfc) = 0x3f000000;
  *(undefined4 *)(*piVar3 + 0x100) = 0x3f4ccccd;
  (*DAT_001754c8)(*(undefined4 *)(*piVar3 + 0x1e8),"models/w_grenade.mdl");
  *(undefined4 *)(*piVar3 + 0x1c0) = 0x42c80000;
  return piVar3;
}


