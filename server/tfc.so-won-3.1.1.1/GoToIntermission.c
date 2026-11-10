// GoToIntermission__13CTeamFortress  @ 000fb9a4
void GoToIntermission__13CTeamFortress(int param_1)

{
  char *pcVar1;
  float fVar2;
  char **ppcVar3;
  longdouble lVar4;
  char *local_28;
  char *pcStack_24;
  char *pcStack_20;
  
  ppcVar3 = (char **)&stack0xffffffe4;
  if (g_fGameOver != 0) {
    return;
  }
  pcStack_20 = (char *)0x0;
  pcStack_24 = (char *)0x0;
  local_28 = (char *)0x1e;
  (*DAT_0019f758)(2);
  pcStack_20 = (char *)0xfb9ef;
  (*DAT_0019f75c)();
  pcStack_20 = (char *)0xfb9f4;
  DumpClanScores__Fv();
  pcVar1 = "mp_chattime";
  clan_scores_dumped = 0x3f800000;
  pcStack_24 = (char *)0xfba15;
  pcStack_20 = pcVar1;
  lVar4 = (longdouble)(*DAT_0019f784)();
  if ((int)ROUND(lVar4) < 1) {
    pcStack_20 = &DAT_00153cb6;
    ppcVar3 = &pcStack_24;
    pcStack_24 = pcVar1;
  }
  else {
    if ((int)ROUND(lVar4) < 0x79) goto LAB_000fba68;
    pcStack_20 = (undefined *)0x78;
    pcStack_24 = (char *)0xfba5e;
    pcStack_24 = (char *)UTIL_dtos1__Fi();
    ppcVar3 = &local_28;
    local_28 = pcVar1;
  }
  *(undefined4 *)((int)ppcVar3 + -4) = 0xfba68;
  (*DAT_0019f790)();
LAB_000fba68:
  fVar2 = *gpGlobals;
  *(int *)((int)ppcVar3 + -4) = (int)ROUND((float)mp_chattime._12_4_);
  *(float *)(param_1 + 4) = fVar2 + (float)*(int *)((int)ppcVar3 + -4);
  *(float *)(param_1 + 8) = *gpGlobals;
  g_fGameOver = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


// GoToIntermission__18CHalfLifeMultiplay  @ 000af680
void GoToIntermission__18CHalfLifeMultiplay(int param_1)

{
  if (g_fGameOver == 0) {
    (*DAT_0019f758)(2,0x1e,0,0);
    (*DAT_0019f75c)();
    *(float *)(param_1 + 4) = *gpGlobals + 6.0;
    g_fGameOver = 1;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


