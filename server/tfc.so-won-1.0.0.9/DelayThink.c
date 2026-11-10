// DelayThink__10CBaseDelay  @ 000f09f0
void DelayThink__10CBaseDelay(int *param_1)

{
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf
            (param_1,0,*(undefined4 *)(*param_1 + 0x160),0);
  (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  return;
}


// DelayThink__17CScriptedSentence  @ 000e8910
void DelayThink__17CScriptedSentence(int *param_1)

{
  param_1[0x122] = 1;
  if (*(int *)(*param_1 + 0x1ac) == 0) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)FindThink__17CScriptedSentence;
  return;
}


