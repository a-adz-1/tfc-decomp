// FindThink__17CScriptedSentence  @ 000eaddc
void FindThink__17CScriptedSentence(int *param_1)

{
  int iVar1;
  
  iVar1 = FindEntity__17CScriptedSentence(param_1);
  if (iVar1 == 0) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x142] + 0.5;
  }
  else {
    StartSentence__17CScriptedSentenceP12CBaseMonster(param_1,iVar1);
    if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)DelayThink__17CScriptedSentence;
    *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x141] + (float)param_1[0x142];
    param_1[0x145] = 0;
  }
  return;
}


