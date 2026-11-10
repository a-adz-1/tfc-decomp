// StartSentence__17CScriptedSentenceP12CBaseMonster  @ 000ea98c
undefined4 StartSentence__17CScriptedSentenceP12CBaseMonster(int *param_1,int *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  
  if (param_2 == (int *)0x0) {
    (*DAT_0019f794)(2,"Not Playing sentence %s\n",param_1[0x13e] + *(int *)(gpGlobals + 0x98));
    uVar2 = 0;
  }
  else {
    bVar1 = *(byte *)(*param_1 + 0x1a0);
    uVar2 = 0;
    if (param_1[0x146] != 0) {
      local_c = param_1[0x140];
      iVar3 = strcmp((char *)(param_1[0x146] + *(int *)(gpGlobals + 0x98)),(char *)FUN_00151d78);
      if (iVar3 == 0) {
        local_c = 0x45800000;
      }
      uVar2 = UTIL_FindEntityGeneric__FPCcR6Vectorf
                        (param_1[0x146] + *(int *)(gpGlobals + 0x98),*param_2 + 8,local_c);
    }
    (**(code **)(param_2[0x115] + 0x18c))
              (param_2,param_1[0x13e] + *(int *)(gpGlobals + 0x98),param_1[0x141],param_1[0x144],
               param_1[0x143],(bVar1 & 8) == 0,uVar2);
    (*DAT_0019f794)(2,"Playing sentence %s (%.1f)\n",param_1[0x13e] + *(int *)(gpGlobals + 0x98),
                    (double)(float)param_1[0x141]);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,0,3,0);
    uVar2 = 1;
  }
  return uVar2;
}


