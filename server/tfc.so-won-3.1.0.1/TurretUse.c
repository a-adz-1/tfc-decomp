// TurretUse__11CBaseTurretP11CBaseEntityT18USE_TYPEf  @ 00107260
void TurretUse__11CBaseTurretP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x191]);
  if (iVar1 != 0) {
    if (param_1[0x191] == 0) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      if ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0) {
        param_1[0x193] = 1;
      }
      param_1[3] = -0x10000;
      param_1[4] = (int)Deploy__11CBaseTurret;
    }
    else {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x11f,0);
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      param_1[0x193] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)Retire__11CBaseTurret;
    }
  }
  return;
}


