// ShootSatchelCharge__8CGrenadeP9entvars_tG6VectorT2  @ 000b9e90
int * ShootSatchelCharge__8CGrenadeP9entvars_tG6VectorT2
                (int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar2 = (int *)GetClassPtr__H1Z8CGrenade_PX01_PX01(0);
  *(undefined4 *)(*piVar2 + 0xe8) = 10;
  *(char **)*piVar2 = "?grenade" + (1 - *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*piVar2 + 0xec) = 2;
  (*DAT_001754c8)(*(undefined4 *)(*piVar2 + 0x1e8),"models/grenade.mdl");
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*piVar2,&local_1c,&local_10);
  *(undefined4 *)(*piVar2 + 0x1c0) = 0x43480000;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_2);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x20) = *param_3;
  *(undefined4 *)(iVar1 + 0x24) = param_3[1];
  *(undefined4 *)(iVar1 + 0x28) = param_3[2];
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x58) = DAT_00175488;
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(param_1 + 0x1e8);
  piVar2[3] = -0x10000;
  piVar2[4] = (int)SUB_DoNothing__11CBaseEntity;
  piVar2[7] = -0x10000;
  piVar2[8] = (int)DetonateUse__8CGrenadeP11CBaseEntityT18USE_TYPEf;
  piVar2[5] = -0x10000;
  piVar2[6] = (int)SlideTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x180) = 1;
  *(undefined4 *)(*piVar2 + 0x100) = 0x3f666666;
  return piVar2;
}


