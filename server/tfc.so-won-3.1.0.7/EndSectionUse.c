// EndSectionUse__18CTriggerEndSectionP11CBaseEntityT18USE_TYPEf  @ 00114460
void EndSectionUse__18CTriggerEndSectionP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    param_1[7] = 0;
    param_1[8] = 0;
    if (*(int *)(*param_1 + 0x1d4) != 0) {
      (*DAT_001c11a4)(*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98));
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


