// FindThink__17CScriptedSentence  @ 000e8870
void FindThink__17CScriptedSentence(int *param_1)

{
  int iVar1;
  
  iVar1 = FindEntity__17CScriptedSentence(param_1);
  if (iVar1 == 0) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0x11f] + 0.5;
  }
  else {
    StartSentence__17CScriptedSentenceP12CBaseMonster(param_1,iVar1);
    if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)DelayThink__17CScriptedSentence;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0x11e] + (float)param_1[0x11f];
    param_1[0x122] = 0;
  }
  return;
}


