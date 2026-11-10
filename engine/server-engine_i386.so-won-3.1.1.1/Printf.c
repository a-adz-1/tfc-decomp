// Printf__10CUtlBufferPCce  @ 000d85c0
void Printf__10CUtlBufferPCce(undefined4 param_1,undefined4 param_2)

{
  VaPrintf__10CUtlBufferPCcPv(param_1,param_2,&stack0x0000000c,0xd85cd);
  return;
}


// Printf__13SystemWrapperPce  @ 000988d4
void Printf__13SystemWrapperPce(undefined4 param_1,char *param_2)

{
  vsnprintf(string_229,0x2000,param_2,&stack0x0000000c);
  Con_Printf(string_229);
  return;
}


