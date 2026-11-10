// EndSectionTouch__18CTriggerEndSectionP11CBaseEntity  @ 00112280
void EndSectionTouch__18CTriggerEndSectionP11CBaseEntity(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    param_1[5] = 0;
    param_1[6] = 0;
    if (*(int *)(*param_1 + 0x1b4) != 0) {
      (*DAT_00175644)(*(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98));
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


