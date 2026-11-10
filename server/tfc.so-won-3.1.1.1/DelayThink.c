// DelayThink__10CBaseDelay  @ 000f661c
void DelayThink__10CBaseDelay(int *param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf
            (param_1,0,*(undefined4 *)(*param_1 + 0x180),0);
  (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// DelayThink__17CScriptedSentence  @ 000ead78
void DelayThink__17CScriptedSentence(int *param_1)

{
  param_1[0x145] = 1;
  if (*(int *)(*param_1 + 0x1cc) == 0) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)FindThink__17CScriptedSentence;
  return;
}


