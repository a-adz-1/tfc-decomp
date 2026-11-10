// FindThink__17CScriptedSentence  @ 000dd8fc
void FindThink__17CScriptedSentence(int *param_1)

{
  int iVar1;
  
  iVar1 = FindEntity__17CScriptedSentence(param_1);
  if (iVar1 == 0) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x122] + 0.5;
  }
  else {
    StartSentence__17CScriptedSentenceP12CBaseMonster(param_1,iVar1);
    if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)DelayThink__17CScriptedSentence;
    *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x121] + (float)param_1[0x122];
    param_1[0x125] = 0;
  }
  return;
}


