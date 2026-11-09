// TurretUse__11CBaseTurretP11CBaseEntityT18USE_TYPEf  @ 00114160
void TurretUse__11CBaseTurretP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x18e]);
  if (iVar1 != 0) {
    if (param_1[0x18e] == 0) {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
      if ((*(byte *)(*param_1 + 0x180) & 0x20) != 0) {
        param_1[400] = 1;
      }
      pcVar2 = Deploy__11CBaseTurret;
    }
    else {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x11c,0);
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
      param_1[400] = 0;
      pcVar2 = Retire__11CBaseTurret;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)pcVar2;
  }
  return;
}


