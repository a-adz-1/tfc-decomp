// Sys_EngineAPI  @ 1009348d
undefined4 Sys_EngineAPI(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0x9348d  316  Sys_EngineAPI */
  if (param_1 != 1) {
    return 0;
  }
  if (param_2 != 0xf0) {
    return 0;
  }
  puVar2 = &DAT_100ee548;
  for (iVar1 = 0x3c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_3 = *puVar2;
    puVar2 = puVar2 + 1;
    param_3 = param_3 + 1;
  }
  return 1;
}


