// Spy_DisguiseExternalWeaponModel__11CBasePlayer  @ 000eee90
void Spy_DisguiseExternalWeaponModel__11CBasePlayer(int *param_1)

{
  if ((((param_1[0xb] == 8) && (param_1[0x1a] != 0)) && (param_1[0x76] != 0)) &&
     ((param_1[0x76] != 8 && (param_1[0x76] < 10)))) {
    *(int *)(*param_1 + 0xa0) =
         *(int *)(SpyFakeWeaponArray + param_1[0x76] * 8) - *(int *)(gpGlobals + 0x98);
    strcpy((char *)(param_1 + 0x325),*(char **)(SpyFakeWeaponArray + param_1[0x76] * 8 + 4));
    param_1[0x32d] = 0;
  }
  return;
}


// Spy_RemoveDisguise__11CBasePlayer  @ 000eee30
void Spy_RemoveDisguise__11CBasePlayer(int param_1)

{
  if (*(int *)(param_1 + 0x2c) == 8) {
    *(undefined4 *)(param_1 + 0x1d4) = 0;
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    *(float *)(param_1 + 0x18c) = *gpGlobals + 10.0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    TeamFortress_SetSkin__11CBasePlayer(param_1);
    TeamFortress_SpyCalcName__11CBasePlayer(param_1);
    Spy_ResetExternalWeaponModel__11CBasePlayer(param_1);
  }
  return;
}


// Spy_ResetExternalWeaponModel__11CBasePlayer  @ 000eef20
void Spy_ResetExternalWeaponModel__11CBasePlayer(int *param_1)

{
  *(int *)(*param_1 + 0xa0) = param_1[0x337] - *(int *)(gpGlobals + 0x98);
  strcpy((char *)(param_1 + 0x325),(char *)(param_1 + 0x32f));
  param_1[0x32d] = 0;
  return;
}


