// Init__10ObjectList  @ 000cac84
void Init__10ObjectList(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// Init__12CInitTrackerPCcT1i  @ 000c6664
void Init__12CInitTrackerPCcT1i(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)__builtin_new(0x24);
  *local_8 = param_2;
  local_8[1] = param_3;
  local_8[3] = *(undefined4 *)(param_4 * 4 + param_1);
  local_8[2] = 1;
  *(undefined1 *)(local_8 + 4) = 0;
  local_8[5] = 0;
  local_8[6] = 0;
  local_8[7] = 0;
  local_8[8] = 0;
  AddToHead__t10CUtlVector1ZPQ212CInitTracker8InitFuncRCPQ212CInitTracker8InitFunc
            (param_4 * 0x14 + 0x10 + param_1,&local_8);
  piVar1 = (int *)(param_4 * 4 + param_1);
  *piVar1 = *piVar1 + 1;
  return;
}


// Init__13EngineWrapperP11IBaseSystemiPc  @ 000994c0
undefined4
Init__13EngineWrapperP11IBaseSystemiPc
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = Init__16BaseSystemModuleP11IBaseSystemiPc(param_1 + 4,param_2,param_3,param_4);
  return uVar1;
}


// Init__13SystemWrapperP11IBaseSystemiPc  @ 00097e8c
/* WARNING: Removing unreachable block (ram,0x00097f42) */

undefined4
Init__13SystemWrapperP11IBaseSystemiPc
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  Init__16BaseSystemModuleP11IBaseSystemiPc(param_1 + 1,param_2,param_3,param_4);
  Init__10ObjectList(param_1 + 0x56);
  Init__10ObjectList(param_1 + 0x4c);
  Init__10ObjectList(param_1 + 0x51);
  Init__10ObjectList(param_1 + 3);
  uVar1 = __builtin_new(0x130);
  iVar2 = __13EngineWrapper(uVar1);
  param_1[0x5f] = iVar2;
  (**(code **)(*param_1 + 0x8c))(param_1,param_1[0x5f],"enginewrapper001");
  param_1[0x48] = 3;
  return 1;
}


// Init__16BaseSystemModuleP11IBaseSystemiPc  @ 000cb3c4
undefined4
Init__16BaseSystemModuleP11IBaseSystemiPc(int param_1,int param_2,undefined4 param_3,char *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    *(int *)(param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 0x11c) = 1;
    *(undefined4 *)(param_1 + 0x120) = param_3;
    *(undefined4 *)(param_1 + 0x124) = 0;
    *(undefined4 *)(param_1 + 0x128) = 0;
    if (param_4 != (char *)0x0) {
      strncpy((char *)(param_1 + 0x1c),param_4,0xfe);
      *(undefined1 *)(param_1 + 0x11a) = 0;
    }
    Init__10ObjectList(param_1 + 8);
    uVar1 = 1;
  }
  return uVar1;
}


// Init__19CDedicatedServerAPIPcT1PFPCcPi_P14IBaseInterfaceT3  @ 00097074
undefined4
Init__19CDedicatedServerAPIPcT1PFPCcPi_P14IBaseInterfaceT3
          (int param_1,undefined4 param_2,char *param_3,code *param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  char local_108 [255];
  undefined1 local_9;
  void *local_8;
  
  dedicated = (*param_4)("VENGINE_DEDICATEDEXPORTS_API_VERSION001",0);
  if (dedicated != 0) {
    strcpy((char *)(param_1 + 4),param_3);
    TraceInit__FPCcT0i("Sys_InitArgv( m_OrigCmd )","Sys_ShutdownArgv()",0);
    Sys_InitArgv__FPc(param_1 + 4);
    (**(code **)(*(int *)eng + 0x48))(eng,0);
    (**(code **)(*(int *)registry + 8))(registry);
    TraceInit__FPCcT0i("FileSystem_Init(basedir, (void *)filesystemFactory)","FileSystem_Shutdown()"
                       ,0);
    iVar2 = FileSystem_Init__FPcPv(param_2,param_5);
    if (iVar2 != 0) {
      uVar3 = 0;
      cVar1 = (**(code **)(*(int *)game + 0xc))(game,0);
      if ((cVar1 != '\0') &&
         (cVar1 = (**(code **)(*(int *)eng + 0xc))(eng,CONCAT22(uVar3,1),param_2,param_3),
         cVar1 != '\0')) {
        iVar2 = COM_CheckParm("-steam");
        if (iVar2 != 0) {
          local_8 = (void *)0x0;
          iVar2 = BuildMapCycleListHints__FPPc(&local_8);
          if (iVar2 != 0) {
            FS_HintResourceNeed(local_8,1);
          }
          if (local_8 != (void *)0x0) {
            free(local_8);
          }
        }
        snprintf(local_108,0xff,"exec %s\n",servercfgfile._4_4_);
        local_9 = 0;
        Cbuf_InsertText(local_108);
        return 1;
      }
    }
  }
  return 0;
}


// Init__5CGamePv  @ 0009a0f0
undefined1 Init__5CGamePv(void)

{
  return 1;
}


// Init__9CRegistry  @ 000d87d4
undefined4 Init__9CRegistry(undefined4 param_1)

{
  return param_1;
}


