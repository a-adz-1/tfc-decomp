// Prime__13CTFEMPGrenadeP11CBaseEntity  @ 000f1a48
void Prime__13CTFEMPGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z13CTFEMPGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"empgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


// Prime__13CTFGasGrenadeP11CBaseEntity  @ 000f1c30
void Prime__13CTFGasGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z13CTFGasGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"gasgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


// Prime__14CTFMirvGrenadeP11CBaseEntity  @ 000eff58
void Prime__14CTFMirvGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z14CTFMirvGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"mirvgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


// Prime__14CTFNailGrenadeP11CBaseEntity  @ 000f0444
void Prime__14CTFNailGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z14CTFNailGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"nailgrenade" - *(int *)(gpGlobals + 0x98);
    puVar2[0xde] = (int)"nailgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


// Prime__16CTFNapalmGrenadeP11CBaseEntity  @ 000f1490
void Prime__16CTFNapalmGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z16CTFNapalmGrenade_PX01_PX01(0);
    puVar2[400] = 7;
    *(char **)*puVar2 = "Bnapalmgrenade" + (1 - *(int *)(gpGlobals + 0x98));
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


// Prime__16CTFNormalGrenadeP11CBaseEntity  @ 000efc44
void Prime__16CTFNormalGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z16CTFNormalGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"normalgrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


// Prime__17CTFCaltropGrenadeP11CBaseEntity  @ 000f0d04
void Prime__17CTFCaltropGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z17CTFCaltropGrenade_PX01_PX01(0);
    *(char **)*puVar2 = "?caltrop" + (1 - *(int *)(gpGlobals + 0x98));
    InitPriming__17CTFCaltropGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


// Prime__20CTFConcussionGrenadeP11CBaseEntity  @ 000efd0c
void Prime__20CTFConcussionGrenadeP11CBaseEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = canPrime__15CTFPrimeGrenadeP11CBaseEntity(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)GetClassPtr__H1Z20CTFConcussionGrenade_PX01_PX01(0);
    *(int *)*puVar2 = (int)"concussiongrenade" - *(int *)(gpGlobals + 0x98);
    InitPriming__15CTFPrimeGrenadeP11CBaseEntity(puVar2,param_1);
  }
  return;
}


