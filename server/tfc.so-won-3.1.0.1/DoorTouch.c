// DoorTouch__9CBaseDoorP11CBaseEntity  @ 00093d44
void DoorTouch__9CBaseDoorP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
  if (iVar1 == 0) {
    if (param_1[0x11d] != 0) {
      iVar1 = UTIL_IsMasterTriggered__Fi(param_1[0x11d]);
      if (iVar1 == 0) {
        PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x11f,1,0);
      }
    }
    if (*(int *)(*param_1 + 0x1cc) == 0) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x112,param_2);
      iVar1 = DoorActivate__9CBaseDoor(param_1);
      if (iVar1 != 0) {
        param_1[5] = 0;
        param_1[6] = 0;
      }
    }
    else {
      PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x11f,1,0);
    }
  }
  return;
}


