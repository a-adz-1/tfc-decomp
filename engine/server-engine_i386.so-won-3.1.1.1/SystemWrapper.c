// SystemWrapper_ExecuteString  @ 00097750
void SystemWrapper_ExecuteString(undefined4 param_1)

{
  ExecuteString__13SystemWrapperPc(gSystemWrapper,param_1);
  return;
}


// SystemWrapper_Init  @ 00097650
void SystemWrapper_Init(void)

{
  Init__13SystemWrapperP11IBaseSystemiPc(gSystemWrapper,gSystemWrapper,0,"SystemWrapper");
  return;
}


// SystemWrapper_LoadModule  @ 00097704
bool SystemWrapper_LoadModule(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = GetModule__13SystemWrapperPcN21(gSystemWrapper,param_1,param_2,param_3);
  return iVar1 != 0;
}


// SystemWrapper_RunFrame  @ 00097694
void SystemWrapper_RunFrame(undefined8 param_1)

{
  RunFrame__13SystemWrapperd(gSystemWrapper,param_1);
  return;
}


// SystemWrapper_ShutDown  @ 000976d0
void SystemWrapper_ShutDown(void)

{
  ShutDown__13SystemWrapper(gSystemWrapper);
  return;
}


