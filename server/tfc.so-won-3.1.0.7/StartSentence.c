// StartSentence__17CScriptedSentenceP12CBaseMonster  @ 000e9cb4
undefined4 StartSentence__17CScriptedSentenceP12CBaseMonster(int *param_1,int *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_4;
  
  if (param_2 == (int *)0x0) {
    (*DAT_001c1114)(2,"Not Playing sentence %s\n",param_1[0x13a] + *(int *)(gpGlobals + 0x98));
    uVar2 = 0;
  }
  else {
    bVar1 = *(byte *)(*param_1 + 0x1a0);
    uVar2 = 0;
    if (param_1[0x142] != 0) {
      local_4 = param_1[0x13c];
      iVar3 = strcmp((char *)(param_1[0x142] + *(int *)(gpGlobals + 0x98)),"player");
      if (iVar3 == 0) {
        local_4 = 0x45800000;
      }
      uVar2 = UTIL_FindEntityGeneric__FPCcR6Vectorf
                        (param_1[0x142] + *(int *)(gpGlobals + 0x98),*param_2 + 8,local_4);
    }
    (**(code **)(param_2[0x111] + 0x18c))
              (param_2,param_1[0x13a] + *(int *)(gpGlobals + 0x98),param_1[0x13d],param_1[0x140],
               param_1[0x13f],(bVar1 & 8) == 0,uVar2);
    (*DAT_001c1114)(2,"Playing sentence %s (%.1f)\n",param_1[0x13a] + *(int *)(gpGlobals + 0x98),
                    (double)(float)param_1[0x13d]);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,0,3,0);
    uVar2 = 1;
  }
  return uVar2;
}


