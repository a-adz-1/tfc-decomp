// StartSentence__17CScriptedSentenceP12CBaseMonster  @ 000e8b60
undefined4 StartSentence__17CScriptedSentenceP12CBaseMonster(int *param_1,int *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if (param_2 == (int *)0x0) {
    (*DAT_001755b4)(2,"Not Playing sentence %s\n",param_1[0x11b] + *(int *)(gpGlobals + 0x98));
    uVar2 = 0;
  }
  else {
    bVar1 = *(byte *)(*param_1 + 0x180);
    uVar2 = 0;
    if (param_1[0x123] != 0) {
      local_8 = param_1[0x11d];
      iVar3 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + param_1[0x123]),"player");
      if (iVar3 == 0) {
        local_8 = 0x45800000;
      }
      uVar2 = UTIL_FindEntityGeneric__FPCcR6Vectorf
                        (param_1[0x123] + *(int *)(gpGlobals + 0x98),*param_2 + 8,local_8);
    }
    (**(code **)(param_2[0xf2] + 0x184))
              (param_2,param_1[0x11b] + *(int *)(gpGlobals + 0x98),param_1[0x11e],param_1[0x121],
               param_1[0x120],(bVar1 & 8) == 0,uVar2);
    (*DAT_001755b4)(2,"Playing sentence %s (%.1f)\n",param_1[0x11b] + *(int *)(gpGlobals + 0x98),
                    (double)(float)param_1[0x11e]);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,0,3,0);
    uVar2 = 1;
  }
  return uVar2;
}


