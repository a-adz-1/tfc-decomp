// ButtonTouch__11CBaseButtonP11CBaseEntity  @ 0009ea60
void ButtonTouch__11CBaseButtonP11CBaseEntity(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player");
  if ((iVar1 == 0) && ((*(byte *)(param_1 + 0x88) & 8) == 0)) {
    iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0);
    if (iVar1 != 0) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,param_2);
      iVar1 = ButtonResponseToTouch__11CBaseButton(param_1);
      if (iVar1 != 0) {
        iVar2 = UTIL_IsMasterTriggered__Fi(param_1[0x11a]);
        if (iVar2 == 0) {
          PlayLockSounds__FP9entvars_tP10locksoundsii(*param_1,param_1 + 0x11e,1,1);
        }
        else {
          param_1[5] = 0;
          param_1[6] = 0;
          if (iVar1 == 2) {
            EMIT_SOUND_DYN__FP7edict_siPCcffii
                      (*(undefined4 *)(*param_1 + 0x1e8),2,
                       *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd
                       ,0,100);
            uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,3,0);
            SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar3);
            ButtonReturn__11CBaseButton(param_1);
          }
          else {
            ButtonActivate__11CBaseButton(param_1);
          }
        }
      }
    }
  }
  return;
}


