// ShootContact__8CGrenadeP9entvars_tG6VectorT2  @ 000b9bf0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * ShootContact__8CGrenadeP9entvars_tG6VectorT2
                (int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  longdouble lVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar2 = (int *)GetClassPtr__H1Z8CGrenade_PX01_PX01(0);
  (**(code **)(piVar2[0xf2] + 8))(piVar2);
  *(undefined4 *)(*piVar2 + 0xfc) = 0x3f000000;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_2);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x20) = *param_3;
  *(undefined4 *)(iVar1 + 0x24) = param_3[1];
  *(undefined4 *)(iVar1 + 0x28) = param_3[2];
  iVar1 = *piVar2;
  UTIL_VecToAngles__FRC6Vector(&local_10,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = local_10;
  *(undefined4 *)(iVar1 + 0x54) = local_c;
  *(undefined4 *)(iVar1 + 0x58) = local_8;
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(param_1 + 0x1e8);
  piVar2[3] = -0x10000;
  piVar2[4] = (int)DangerSoundThink__8CGrenade;
  *(undefined4 *)(*piVar2 + 0xe4) = *gpGlobals;
  lVar3 = (longdouble)(*DAT_0017562c)(0xc2c80000,0xc3fa0000);
  *(float *)(*piVar2 + 0x5c) = (float)lVar3;
  piVar2[5] = -0x10000;
  piVar2[6] = (int)ExplodeTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x1c0) = _DAT_00177a78;
  return piVar2;
}


