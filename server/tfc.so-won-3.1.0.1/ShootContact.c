// ShootContact__8CGrenadeP9entvars_sG6VectorT2  @ 000a758c
int * ShootContact__8CGrenadeP9entvars_sG6VectorT2
                (undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_EBP;
  longdouble lVar3;
  int unaff_retaddr;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar2 = (int *)GetClassPtr__H1Z8CGrenade_PX01_PX01(0);
  (**(code **)(piVar2[0xf5] + 8))(piVar2);
  *(undefined4 *)(*piVar2 + 0x11c) = 0x3f000000;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,param_2);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x20) = *param_3;
  *(undefined4 *)(iVar1 + 0x24) = param_3[1];
  *(undefined4 *)(iVar1 + 0x28) = param_3[2];
  iVar1 = *piVar2;
  UTIL_VecToAngles__FRC6Vector(&local_c,iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x50) = unaff_EBP;
  *(undefined4 *)(iVar1 + 0x54) = local_c;
  *(undefined4 *)(iVar1 + 0x58) = local_8;
  *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(unaff_retaddr + 0x208);
  piVar2[3] = -0x10000;
  piVar2[4] = (int)DangerSoundThink__8CGrenade;
  *(undefined4 *)(*piVar2 + 0x104) = *gpGlobals;
  lVar3 = (longdouble)(*DAT_001a7fac)(0xc2c80000,0xc3fa0000);
  *(float *)(*piVar2 + 0x5c) = (float)lVar3;
  piVar2[5] = -0x10000;
  piVar2[6] = (int)ExplodeTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x1e0) = DAT_001aa458;
  return piVar2;
}


