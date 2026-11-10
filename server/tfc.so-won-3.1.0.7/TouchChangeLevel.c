// TouchChangeLevel__12CChangeLevelP11CBaseEntity  @ 00113378
void TouchChangeLevel__12CChangeLevelP11CBaseEntity(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
  if (iVar1 == 0) {
    ChangeLevelNow__12CChangeLevelP11CBaseEntity(param_1,param_2);
  }
  return;
}


