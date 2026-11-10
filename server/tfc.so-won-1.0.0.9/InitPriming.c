// InitPriming__15CTFPrimeGrenadeP11CBaseEntity  @ 000fc510
void InitPriming__15CTFPrimeGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(*param_2 + 0x1e8);
  param_1[0x48] = param_2[0x48];
  param_1[3] = -0x10000;
  param_1[4] = (int)GrenadePrimed__15CTFPrimeGrenade;
  lVar3 = (longdouble)(**(code **)(param_1[0xf2] + 0x22c))(param_1);
  *(float *)(*param_1 + 0xe4) = (float)(lVar3 + (longdouble)*gpGlobals);
  lVar3 = (longdouble)(**(code **)(param_1[0xf2] + 0x228))(param_1);
  lVar4 = (longdouble)(**(code **)(param_1[0xf2] + 0x22c))(param_1);
  param_1[0x189] = (int)(float)((longdouble)(float)lVar3 + (longdouble)*gpGlobals + lVar4);
  param_1[0x48] = param_2[0x48];
  uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_2 + 0x1e8));
  iVar2 = UTIL_PlayerByIndex__Fi(uVar1);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)*param_1;
  }
  return;
}


// InitPriming__17CTFCaltropGrenadeP11CBaseEntity  @ 000fd710
void InitPriming__17CTFCaltropGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  *(undefined4 *)(*param_1 + 0x178) = *(undefined4 *)(*param_2 + 0x1e8);
  param_1[3] = -0x10000;
  param_1[4] = (int)CaltropGrenadePrimed__17CTFCaltropGrenade;
  lVar3 = (longdouble)(**(code **)(param_1[0xf2] + 0x22c))(param_1);
  *(float *)(*param_1 + 0xe4) = (float)(lVar3 + (longdouble)*gpGlobals);
  lVar3 = (longdouble)(**(code **)(param_1[0xf2] + 0x228))(param_1);
  lVar4 = (longdouble)(**(code **)(param_1[0xf2] + 0x22c))(param_1);
  param_1[0x189] = (int)(float)((longdouble)(float)lVar3 + (longdouble)*gpGlobals + lVar4);
  param_1[0x48] = param_2[0x48];
  uVar1 = (*DAT_001755dc)(*(undefined4 *)(*param_2 + 0x1e8));
  iVar2 = UTIL_PlayerByIndex__Fi(uVar1);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)*param_1;
  }
  return;
}


