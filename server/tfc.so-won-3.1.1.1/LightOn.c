// LightOn__10CXenPLight  @ 00129a80
void LightOn__10CXenPLight(int param_1)

{
  byte *pbVar1;
  
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,1,0);
  if (*(int **)(param_1 + 0x478) != (int *)0x0) {
    pbVar1 = (byte *)(**(int **)(param_1 + 0x478) + 0x118);
    *pbVar1 = *pbVar1 & 0x7f;
  }
  return;
}


