// ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity  @ 00110a40
void ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if ((*(float *)(*param_1 + 0xe4) <= *gpGlobals) &&
     (iVar2 = UTIL_IsMasterTriggered__Fi(param_1[0x11a]), iVar2 != 0)) {
    iVar2 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"trigger_secret");
    if (iVar2 == 0) {
      if (*(int *)(*param_1 + 0x170) == 0) {
        return;
      }
      iVar2 = *(int *)(*param_1 + 0x170);
      if (iVar2 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)(iVar2 + 0xdc);
      }
      iVar2 = strcmp((char *)(*piVar4 + (int)gpGlobals[0x26]),"player");
      if (iVar2 != 0) {
        return;
      }
      gpGlobals[9] = gpGlobals[9] + 1.0;
    }
    iVar2 = *(int *)(*param_1 + 0x1c8);
    if (iVar2 != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),2,(int)gpGlobals[0x26] + iVar2,0x3f800000,
                 0x3f4ccccd,0,100);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x10f,param_2);
    uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar3);
    if ((*(int *)(*param_1 + 0x1b4) != 0) && ((*(byte *)(*param_2 + 0x184) & 8) != 0)) {
      UTIL_ShowMessage__FPCcP7edict_s
                (*(int *)(*param_1 + 0x1b4) + (int)gpGlobals[0x26],*(undefined4 *)(*param_2 + 0x1e8)
                );
    }
    fVar1 = (float)param_1[0xfd];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      param_1[3] = -0x10000;
      param_1[4] = (int)MultiWaitOver__12CBaseTrigger;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xfd];
    }
    else {
      param_1[5] = 0;
      param_1[6] = 0;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
    }
  }
  return;
}


