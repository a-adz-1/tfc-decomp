// ButtonTouch__11CBaseButtonP11CBaseEntity  @ 0008b2f8
void ButtonTouch__11CBaseButtonP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
  if (((iVar1 == 0) && ((*(byte *)(param_1 + 0x8a) & 8) == 0)) &&
     (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar1 != 0))
  {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x132,param_2);
    if (1 < param_1[0x11d] - 2U) {
      if (param_1[0x11d] == 0) {
        if ((param_1[0x13e] == 0) && ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0)) {
          return;
        }
        if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
          return;
        }
        if (param_1[0x13e] != 0) {
          return;
        }
        local_c = 2;
      }
      else {
        local_c = 1;
      }
      iVar1 = UTIL_IsMasterTriggered__Fi(param_1[0x13d]);
      if (iVar1 == 0) {
        PlayLockSounds__FP9entvars_sP10locksoundsii(*param_1,param_1 + 0x141,1,1);
      }
      else {
        param_1[5] = 0;
        param_1[6] = 0;
        if (local_c == 2) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*param_1 + 0x208),2,
                     *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0
                     ,100);
          uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x132,3,0);
          SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar2);
          ButtonReturn__11CBaseButton(param_1);
        }
        else {
          ButtonActivate__11CBaseButton(param_1);
        }
      }
    }
  }
  return;
}


