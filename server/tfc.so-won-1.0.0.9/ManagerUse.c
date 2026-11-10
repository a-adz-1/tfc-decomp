// ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf  @ 0010fb60
void ManagerUse__13CMultiManagerP11CBaseEntityT18USE_TYPEf(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,param_2);
  param_1[0x11c] = 0;
  piVar1 = gpGlobals;
  param_1[0x11d] = *gpGlobals;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)ManagerThink__13CMultiManager;
  *(int *)(*param_1 + 0xe4) = *piVar1;
  return;
}


