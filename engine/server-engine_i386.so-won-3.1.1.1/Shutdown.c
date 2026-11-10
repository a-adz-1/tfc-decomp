// Shutdown__12CInitTrackerPCci  @ 000c6728
void Shutdown__12CInitTrackerPCci(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (*(int *)(param_3 * 4 + param_1) == 0) {
    Sys_Printf("Mismatched shutdown function %s\n",param_2);
  }
  else {
    local_c = 0;
    for (local_8 = 0; local_8 < *(int *)(param_3 * 4 + param_1); local_8 = local_8 + 1) {
      piVar2 = (int *)__vc__t10CUtlVector1ZPQ212CInitTracker8InitFunci
                                (param_3 * 0x14 + 0x10 + param_1,local_8);
      local_c = *piVar2;
      if (*(int *)(local_c + 8) != 0) break;
    }
    if ((((local_c != 0) && (*(int *)(local_c + 8) != 0)) &&
        (iVar1 = strcasecmp(*(char **)(local_c + 4),param_2), iVar1 != 0)) &&
       (*(char *)(local_c + 0x10) == '\0')) {
      *(undefined1 *)(local_c + 0x10) = 1;
    }
    for (local_8 = 0; local_8 < *(int *)(param_3 * 4 + param_1); local_8 = local_8 + 1) {
      piVar2 = (int *)__vc__t10CUtlVector1ZPQ212CInitTracker8InitFunci
                                (param_3 * 0x14 + 0x10 + param_1,local_8);
      iVar1 = *piVar2;
      iVar3 = strcasecmp(*(char **)(iVar1 + 4),param_2);
      if (iVar3 == 0) {
        piVar2 = (int *)(iVar1 + 8);
        *piVar2 = *piVar2 + -1;
        return;
      }
    }
    Sys_Printf("Shutdown function %s not in list!!!\n",param_2);
  }
  return;
}


// Shutdown__19CDedicatedServerAPI  @ 000972d8
undefined4 Shutdown__19CDedicatedServerAPI(void)

{
  (**(code **)(*(int *)eng + 0x10))(eng);
  (**(code **)(*(int *)game + 0x10))(game);
  TraceShutdown__FPCci("FileSystem_Shutdown()",0);
  FileSystem_Shutdown__Fv();
  (**(code **)(*(int *)registry + 0xc))(registry);
  TraceShutdown__FPCci("Sys_ShutdownArgv()",0);
  Sys_ShutdownArgv__Fv();
  dedicated = 0;
  return giActive;
}


// Shutdown__5CGame  @ 0009a100
undefined1 Shutdown__5CGame(void)

{
  return 1;
}


// Shutdown__9CRegistry  @ 000d87e0
undefined4 Shutdown__9CRegistry(undefined4 param_1)

{
  return param_1;
}


