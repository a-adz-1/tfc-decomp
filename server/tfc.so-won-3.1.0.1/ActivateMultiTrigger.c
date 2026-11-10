// ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity  @ 001030a0
void ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((*(float *)(*param_1 + 0x104) <= *gpGlobals) &&
     (iVar1 = UTIL_IsMasterTriggered__Fi(param_1[0x11d]), iVar1 != 0)) {
    iVar1 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"trigger_secret");
    if (iVar1 == 0) {
      if (*(int *)(*param_1 + 400) == 0) {
        return;
      }
      iVar1 = *(int *)(*param_1 + 400);
      piVar3 = (int *)(iVar1 + 0x80);
      if (iVar1 == 0) {
        piVar3 = (int *)0x0;
      }
      iVar1 = strcmp((char *)(*piVar3 + (int)gpGlobals[0x26]),"player");
      if (iVar1 != 0) {
        return;
      }
      gpGlobals[9] = gpGlobals[9] + 1.0;
    }
    iVar1 = *(int *)(*param_1 + 0x1e8);
    if (iVar1 != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,iVar1 + (int)gpGlobals[0x26],0x3f800000,
                 0x3f4ccccd,0,100);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x112,param_2);
    uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x112,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar2);
    if ((*(int *)(*param_1 + 0x1d4) != 0) && ((*(byte *)(*param_2 + 0x1a4) & 8) != 0)) {
      UTIL_ShowMessage__FPCcP7edict_s
                (*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26],*(undefined4 *)(*param_2 + 0x208)
                );
    }
    if ((float)param_1[0x100] <= 0.0) {
      param_1[5] = 0;
      param_1[6] = 0;
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
    }
    else {
      param_1[3] = -0x10000;
      param_1[4] = (int)MultiWaitOver__12CBaseTrigger;
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x100];
    }
  }
  return;
}


