// ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity  @ 0011529c
void ActivateMultiTrigger__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  fVar1 = *gpGlobals;
  fVar2 = *(float *)(*param_1 + 0x104);
  if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
     (iVar3 = UTIL_IsMasterTriggered__Fi(param_1[0x13d]), iVar3 != 0)) {
    iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"trigger_secret");
    if (iVar3 == 0) {
      if (*(int *)(*param_1 + 400) == 0) {
        return;
      }
      iVar3 = strcmp((char *)(*(int *)(*(int *)(*param_1 + 400) + 0x80) + (int)gpGlobals[0x26]),
                     "player");
      if (iVar3 != 0) {
        return;
      }
      gpGlobals[9] = gpGlobals[9] + 1.0;
    }
    iVar3 = *(int *)(*param_1 + 0x1e8);
    if (iVar3 != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,iVar3 + (int)gpGlobals[0x26],0x3f800000,
                 0x3f4ccccd,0,100);
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x132,param_2);
    uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x132,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar4);
    if ((*(int *)(*param_1 + 0x1d4) != 0) && ((*(byte *)(*param_2 + 0x1a4) & 8) != 0)) {
      UTIL_ShowMessage__FPCcP7edict_s
                (*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26],*(undefined4 *)(*param_2 + 0x208)
                );
    }
    if ((float)param_1[0x120] <= 0.0) {
      param_1[5] = 0;
      param_1[6] = 0;
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
    }
    else {
      param_1[3] = -0x10000;
      param_1[4] = (int)MultiWaitOver__12CBaseTrigger;
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x120];
    }
  }
  return;
}


