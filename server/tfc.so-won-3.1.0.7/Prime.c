// Prime__13CTFEMPGrenadeP11CBaseEntity  @ 000fee58
undefined4 * Prime__13CTFEMPGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"empgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return puVar2;
}


// Prime__13CTFGasGrenadeP11CBaseEntity  @ 000ff080
void Prime__13CTFGasGrenadeP11CBaseEntity(void)

{
  FUN_000ff088();
  return;
}


// Prime__14CTFMirvGrenadeP11CBaseEntity  @ 000fd248
undefined4 * Prime__14CTFMirvGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"mirvgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return puVar2;
}


// Prime__14CTFNailGrenadeP11CBaseEntity  @ 000fd774
undefined4 * Prime__14CTFNailGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"nailgrenade" - *(int *)(gpGlobals + 0x98);
    puVar2[0xfa] = (int)"nailgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return puVar2;
}


// Prime__16CTFNapalmGrenadeP11CBaseEntity  @ 000fe868
undefined4 * Prime__16CTFNapalmGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01(0);
    puVar2[0x1ac] = 7;
    *(char **)*puVar2 = "Bnapalmgrenade" + (1 - *(int *)(gpGlobals + 0x98));
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return puVar2;
}


// Prime__16CTFNormalGrenadeP11CBaseEntity  @ 000fceb8
undefined4 * Prime__16CTFNormalGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"normalgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return puVar2;
}


// Prime__17CTFCaltropGrenadeP11CBaseEntity  @ 000fe06c
undefined4 * Prime__17CTFCaltropGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01(0);
    *(char **)*puVar2 = "?caltrop" + (1 - *(int *)(gpGlobals + 0x98));
    InitPriming__17CTFCaltropGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return puVar2;
}


// Prime__20CTFConcussionGrenadeP11CBaseEntity  @ 000fcfbc
undefined4 * Prime__20CTFConcussionGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"concussiongrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return puVar2;
}


