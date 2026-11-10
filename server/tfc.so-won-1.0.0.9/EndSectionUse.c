// EndSectionUse__18CTriggerEndSectionP11CBaseEntityT18USE_TYPEf  @ 001121a0
void EndSectionUse__18CTriggerEndSectionP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    param_1[7] = 0;
    param_1[8] = 0;
    if (*(int *)(*param_1 + 0x1b4) != 0) {
      (*DAT_00175644)(*(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98));
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


