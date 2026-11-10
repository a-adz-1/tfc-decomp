// ShootSatchelCharge__8CGrenadeP9entvars_sG6VectorT2  @ 000b2834
int * ShootSatchelCharge__8CGrenadeP9entvars_sG6VectorT2
                (int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar2 = (int *)GetClassPtr__H1Z8CGrenade_PX01_PX01(0);
  *(undefined4 *)(*piVar2 + 0x108) = 10;
  *(char **)*piVar2 = "?grenade" + (1 - *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*piVar2 + 0x10c) = 2;
  (*DAT_001c1028)(*(undefined4 *)(*piVar2 + 0x208),"models/grenade.mdl");
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar2,&local_18,&local_c);
  *(undefined4 *)(*piVar2 + 0x1e0) = 0x43480000;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,param_2);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x20) = *param_3;
  *(undefined4 *)(iVar1 + 0x24) = param_3[1];
  *(undefined4 *)(iVar1 + 0x28) = param_3[2];
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 0x58) = DAT_001c0fe8;
  *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(param_1 + 0x208);
  piVar2[3] = -0x10000;
  piVar2[4] = (int)SUB_DoNothing__11CBaseEntity;
  piVar2[7] = -0x10000;
  piVar2[8] = (int)DetonateUse__8CGrenadeP11CBaseEntityT18USE_TYPEf;
  piVar2[5] = -0x10000;
  piVar2[6] = (int)SlideTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x1a0) = 1;
  *(undefined4 *)(*piVar2 + 0x120) = 0x3f666666;
  return piVar2;
}


