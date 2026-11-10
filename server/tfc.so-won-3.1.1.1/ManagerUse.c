// ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf  @ 00119974
void ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x132,param_2);
  param_1[0x13f] = 0;
  iVar1 = *gpGlobals;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0x140] = iVar1;
  param_1[3] = -0x10000;
  param_1[4] = (int)ManagerThink__13CMultiManager;
  *(int *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


