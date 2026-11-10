// Prime__13CTFEMPGrenadeP11CBaseEntity  @ 0010100c
undefined4 * Prime__13CTFEMPGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01(0);
    *(int *)*puVar1 = (int)"empgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


// Prime__13CTFGasGrenadeP11CBaseEntity  @ 00100ee4
undefined4 * Prime__13CTFGasGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01(0);
    *(int *)*puVar1 = (int)"gasgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


// Prime__14CTFMirvGrenadeP11CBaseEntity  @ 00101664
undefined4 * Prime__14CTFMirvGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01(0);
    *(int *)*puVar1 = (int)"mirvgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


// Prime__14CTFNailGrenadeP11CBaseEntity  @ 001013e8
undefined4 * Prime__14CTFNailGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01(0);
    *(int *)*puVar1 = (int)"nailgrenade" - *(int *)(gpGlobals + 0x98);
    puVar1[0xfe] = (int)"nailgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


// Prime__16CTFNapalmGrenadeP11CBaseEntity  @ 00101100
undefined4 * Prime__16CTFNapalmGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01(0);
    puVar1[0x1b0] = 7;
    *(char **)*puVar1 = "Bnapalmgrenade" + (1 - *(int *)(gpGlobals + 0x98));
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


// Prime__16CTFNormalGrenadeP11CBaseEntity  @ 00101a78
undefined4 * Prime__16CTFNormalGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01(0);
    *(int *)*puVar1 = (int)"normalgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


// Prime__17CTFCaltropGrenadeP11CBaseEntity  @ 001012fc
undefined4 * Prime__17CTFCaltropGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01(0);
    *(int *)*puVar1 = (int)FUN_00154758 - *(int *)(gpGlobals + 0x98);
    InitPriming__17CTFCaltropGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


// Prime__20CTFConcussionGrenadeP11CBaseEntity  @ 00101904
undefined4 * Prime__20CTFConcussionGrenadeP11CBaseEntity(int param_1)

{
  undefined4 *puVar1;
  
  if (((*(byte *)(param_1 + 0x84) ^ 1) & 1) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01(0);
    *(int *)*puVar1 = (int)"concussiongrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar1,param_1);
  }
  return puVar1;
}


