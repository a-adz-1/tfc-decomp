// LightOff__10CXenPLight  @ 001148a0
void LightOff__10CXenPLight(int param_1)

{
  byte *pbVar1;
  
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,0,0);
  if (*(int *)(param_1 + 0x3f8) != 0) {
    pbVar1 = (byte *)(**(int **)(param_1 + 0x3f8) + 0x118);
    *pbVar1 = *pbVar1 | 0x80;
  }
  return;
}


