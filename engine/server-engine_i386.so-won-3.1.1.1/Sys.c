// Sys_CheckOSVersion__Fv  @ 00096190
void Sys_CheckOSVersion__Fv(void)

{
  return;
}


// Sys_DebugOutStraight  @ 000943ec
void Sys_DebugOutStraight(void)

{
  return;
}


// Sys_Error  @ 000943f4
void Sys_Error(char *param_1)

{
  char local_408 [1024];
  undefined1 *local_8;
  
  local_8 = &stack0x00000008;
  vsnprintf(local_408,0x400,param_1,local_8);
  if (bReentry_69 != 0) {
    fprintf((FILE *)_IO_stderr_,"%s\n",local_408);
                    /* WARNING: Subroutine does not return */
    longjmp((__jmp_buf_tag *)host_abortserver,2);
  }
  bReentry_69 = 1;
  if ((svs != 0) && (DAT_0036afc4 != (code *)0x0)) {
    (*DAT_0036afc4)(local_408);
  }
  Log_Printf("FATAL ERROR (shutting down): %s\n",local_408);
  if (isDedicated != 0) {
    if (Launcher_ConsolePrintf != (code *)0x0) {
      (*Launcher_ConsolePrintf)("FATAL ERROR (shutting down): %s\n",local_408);
    }
    Sys_Sleep(10000);
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  Sys_Printf(local_408);
  giActive = 2;
  giStateInfo = 4;
  return;
}


// Sys_FindClose  @ 0009409c
void Sys_FindClose(void)

{
  if (g_hfind != -1) {
    FS_FindClose(g_hfind);
    g_hfind = -1;
  }
  return;
}


// Sys_FindFirst  @ 00093fb4
int Sys_FindFirst(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (g_hfind != -1) {
    Sys_Error("Sys_FindFirst without close");
    FS_FindClose(g_hfind);
  }
  iVar1 = FS_FindFirst(param_1,&g_hfind);
  if ((param_2 != 0) && (iVar1 != 0)) {
    COM_FileBase(iVar1,param_2);
  }
  return iVar1;
}


// Sys_FindNext  @ 00094044
int Sys_FindNext(int param_1)

{
  int iVar1;
  
  iVar1 = FS_FindNext(g_hfind);
  if ((param_1 != 0) && (iVar1 != 0)) {
    COM_FileBase(iVar1,param_1);
  }
  return iVar1;
}


// Sys_FloatTime  @ 000946a0
longdouble Sys_FloatTime(void)

{
  longdouble lVar1;
  timeval local_c;
  
  gettimeofday(&local_c,(__timezone_ptr_t)0x0);
  if (secbase_82 == 0) {
    secbase_82 = local_c.tv_sec;
    lVar1 = (longdouble)local_c.tv_usec / (longdouble)1000000.0;
  }
  else {
    lVar1 = (longdouble)local_c.tv_usec / (longdouble)1000000.0 +
            (longdouble)(local_c.tv_sec - secbase_82);
  }
  return lVar1;
}


// Sys_GetFactoryThis__Fv  @ 000d7c68
code * Sys_GetFactoryThis__Fv(void)

{
  return CreateInterface;
}


// Sys_GetFactory__FP10CSysModule  @ 000d7c1c
undefined4 Sys_GetFactory__FP10CSysModule(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = dlsym(param_1,"CreateInterface");
  }
  return uVar1;
}


// Sys_GetFactory__FPCc  @ 000d7c8c
undefined4 Sys_GetFactory__FPCc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Sys_GetProcAddress__FPCcT0(param_1,"CreateInterface");
  return uVar1;
}


// Sys_GetProcAddress__FPCcT0  @ 000d7a38
undefined4 Sys_GetProcAddress__FPCcT0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = GetModuleHandle__FPCc(param_1);
  uVar1 = dlsym(uVar1,param_2);
  return uVar1;
}


// Sys_GetProcAddress__FPvPCc  @ 000d7a7c
undefined4 Sys_GetProcAddress__FPvPCc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = dlsym(param_1,param_2);
  return uVar1;
}


// Sys_Init  @ 000943a4
void Sys_Init(void)

{
  return;
}


// Sys_InitArgv__FPc  @ 000961b4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_InitArgv__FPc(char *param_1)

{
  _DAT_00300864 = 1;
  argv = empty_string;
  while ((*param_1 != '\0' && (_DAT_00300864 < 0x32))) {
    for (; (*param_1 != '\0' && ((*param_1 < '!' || (*param_1 == '\x7f')))); param_1 = param_1 + 1)
    {
    }
    if (*param_1 != '\0') {
      (&argv)[_DAT_00300864] = param_1;
      _DAT_00300864 = _DAT_00300864 + 1;
      for (; ((*param_1 != '\0' && (' ' < *param_1)) && (*param_1 < '\x7f')); param_1 = param_1 + 1)
      {
      }
      if (*param_1 != '\0') {
        *param_1 = '\0';
        param_1 = param_1 + 1;
      }
    }
  }
  _DAT_00300868 = &argv;
  COM_InitArgv(_DAT_00300864,&argv);
  _DAT_00300864 = com_argc;
  _DAT_00300868 = (undefined4 *)com_argv;
  return;
}


// Sys_InitAuthentication__Fv  @ 000964ac
void Sys_InitAuthentication__Fv(void)

{
  int iVar1;
  undefined4 local_130;
  undefined1 *local_12c;
  char *local_128;
  char *local_124;
  undefined *local_120;
  code *local_11c;
  undefined4 local_118;
  undefined4 local_114;
  int local_110;
  char local_10c [260];
  int local_8;
  
  iVar1 = COM_CheckParm("-steam");
  if (iVar1 == 0) {
    local_110 = 1;
    Q_memset(&local_130,0,0x20);
    iVar1 = Crypt_ReturnAPI(1,crypt);
    if (iVar1 == 0) {
      Sys_Printf("Host_Init:  Auth API Failure\n");
    }
    sprintf(local_10c,"%s","valvecomm.lst");
    local_8 = COM_CheckParm("-comm");
    if ((local_8 != 0) && (local_8 < com_argc + -1)) {
      Q_strcpy(local_10c,*(undefined4 *)(local_8 * 4 + com_argv + 4));
    }
    local_130 = 1;
    local_12c = &com_gamedir;
    local_128 = "2123437429222";
    local_124 = local_10c;
    local_120 = &DAT_000e7560;
    local_11c = Con_Printf;
    local_118 = 0;
    local_114 = 0;
    (*(code *)crypt._8_4_)(&local_130);
    local_8 = COM_CheckParm("+sv_lan");
    if (((local_8 != 0) && (local_8 < com_argc + -1)) &&
       (iVar1 = Q_atoi(*(undefined4 *)(local_8 * 4 + com_argv + 4)), iVar1 != 0)) {
      local_110 = 0;
    }
    if (isDedicated != 0) {
      if (((local_110 != 0) && (crypt._60_4_ != 0)) &&
         (iVar1 = (*(code *)crypt._60_4_)(), iVar1 != 0)) {
        Sys_Printf("WON Auth Server\r\n");
        return;
      }
      Sys_Printf("Auth Server\r\n");
    }
  }
  return;
}


// Sys_InitGame__FPcT0Pvi  @ 000968ec
undefined4 Sys_InitGame__FPcT0Pvi(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_stack_00000010;
  char local_1210 [4096];
  undefined1 local_210 [260];
  char local_10c [260];
  int local_8;
  
  host_initialized = 0;
  isDedicated = in_stack_00000010;
  memset(&gmodinfo,0,0x238);
  TraceInit__FPCcT0i("Sys_Init()","Sys_Shutdown()",0);
  Sys_Init__Fv();
  FS_LogLevelLoadStarted("Launcher");
  SeedRandomNumberGenerator();
  TraceInit__FPCcT0i("Sys_InitMemory()","Sys_ShutdownMemory()",0);
  Sys_InitMemory__Fv();
  TraceInit__FPCcT0i("Sys_InitLauncherInterface()","Sys_ShutdownLauncherInterface()",0);
  Sys_InitLauncherInterface__Fv();
  TraceInit__FPCcT0i("Host_Init( &host_parms )","Host_Shutdown()",0);
  Host_Init(&host_parms);
  if (host_initialized == 0) {
    uVar1 = 0;
  }
  else {
    COM_FileBase(&com_gamedir,local_210);
    iVar2 = COM_CheckParm("-steam");
    if (iVar2 != 0) {
      sprintf(local_10c,"reslists\\%s\\internal_preloads.lst",local_210);
      FS_HintResourceNeed(local_10c,1);
    }
    TraceInit__FPCcT0i("Sys_InitAuthentication()","Sys_ShutdownAuthentication()",0);
    Sys_InitAuthentication__Fv();
    local_8 = COM_CheckParm("+fs_preload");
    if (((local_8 != 0) && (local_8 != 0)) && (local_8 < com_argc + -1)) {
      Cvar_DirectSet(fs_preloader,*(undefined4 *)(local_8 * 4 + com_argv + 4));
    }
    if ((byte)(0.0 < (float)fs_preloader._12_4_ |
               (byte)((ushort)((ushort)NAN((float)fs_preloader._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)fs_preloader._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      sprintf(local_1210,"reslists\\%s\\memcache_preloads.lst",&com_gamedir);
      FSMC_HintResourcesNeeded(local_1210);
    }
    if (isDedicated != 0) {
      Host_InitializeGameDLL();
      NET_Config(1);
    }
    uVar1 = 1;
  }
  return uVar1;
}


// Sys_InitLauncherInterface__Fv  @ 0009647c
void Sys_InitLauncherInterface__Fv(void)

{
  Sys_SetupLegacyAPIs__Fv();
  return;
}


// Sys_InitMemory__Fv  @ 0009631c
void Sys_InitMemory__Fv(void)

{
  int iVar1;
  
  DAT_00300870 = 0x2000000;
  iVar1 = COM_CheckParm("-heapsize");
  if ((iVar1 != 0) && (iVar1 < com_argc + -1)) {
    iVar1 = atoi(*(char **)(iVar1 * 4 + com_argv + 4));
    DAT_00300870 = iVar1 << 10;
  }
  iVar1 = COM_CheckParm("-minmemory");
  if (iVar1 != 0) {
    DAT_00300870 = 0xe00000;
  }
  DAT_0030086c = malloc(DAT_00300870);
  if (DAT_0030086c == (void *)0x0) {
    Sys_Error("Unable to allocate %.2f MB\n",(double)(int)DAT_00300870 / 1048576.0);
  }
  return;
}


// Sys_Init__Fv  @ 0009619c
void Sys_Init__Fv(void)

{
  return;
}


// Sys_LoadModule__FPCc  @ 000d7ab0
int Sys_LoadModule__FPCc(undefined4 param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  char acStack_a08 [512];
  int iStack_808;
  char acStack_804 [1023];
  char acStack_405 [1025];
  
  getcwd(acStack_405 + 1,0x400);
  sVar1 = strlen(acStack_405 + 1);
  if (acStack_405[sVar1] == '/') {
    sVar1 = strlen(acStack_405 + 1);
    acStack_405[sVar1] = '\0';
  }
  snprintf(acStack_804,0x400,"%s/%s",acStack_405 + 1,param_1);
  iStack_808 = dlopen(acStack_804,2);
  if (iStack_808 == 0) {
    uVar2 = dlerror();
    printf("Error:%s\n",uVar2);
    snprintf(acStack_a08,0x200,"%s.so",acStack_804);
    iStack_808 = dlopen(acStack_a08,2);
  }
  return iStack_808;
}


// Sys_MakeCodeWriteable  @ 0009437c
void Sys_MakeCodeWriteable(void)

{
  return;
}


// Sys_PageIn  @ 00093fac
void Sys_PageIn(void)

{
  return;
}


// Sys_PopFPCW  @ 00094394
void Sys_PopFPCW(void)

{
  return;
}


// Sys_Printf  @ 000945ac
void Sys_Printf(char *param_1)

{
  int iVar1;
  char local_408 [1024];
  undefined1 *local_8;
  
  local_8 = &stack0x00000008;
  vsnprintf(local_408,0x400,param_1,local_8);
  if ((isDedicated != 0) && (Launcher_ConsolePrintf != (code *)0x0)) {
    iVar1 = COM_CheckParm("-steam");
    if ((iVar1 != 0) && ((g_bPrintingKeepAliveDots != 0 && (local_408[0] != '.')))) {
      (*Launcher_ConsolePrintf)(&DAT_000e7088);
      g_bPrintingKeepAliveDots = 0;
    }
    (*Launcher_ConsolePrintf)(&DAT_000e708a,local_408);
  }
  return;
}


// Sys_PushFPCW_SetHigh  @ 0009438c
void Sys_PushFPCW_SetHigh(void)

{
  return;
}


// Sys_Quit  @ 0009467c
void Sys_Quit(void)

{
  giActive = 3;
  return;
}


// Sys_SetFPCW  @ 00094384
void Sys_SetFPCW(void)

{
  return;
}


// Sys_SetupLegacyAPIs__Fv  @ 00096164
void Sys_SetupLegacyAPIs__Fv(void)

{
  Launcher_ConsolePrintf = Legacy_Sys_Printf__FPce;
  return;
}


// Sys_ShowProgressTicks__FPc  @ 00096758
void Sys_ShowProgressTicks__FPc(void)

{
  int iVar1;
  longdouble lVar2;
  int local_94;
  char local_8c [128];
  double local_c;
  
  if (recursionGuard_88 == '\0') {
    recursionGuard_88 = 1;
    iVar1 = COM_CheckParm("-steam");
    if (iVar1 == 0) {
      recursionGuard_88 = '\0';
    }
    else {
      lVar2 = (longdouble)Sys_FloatTime();
      local_c = (double)lVar2;
      if (g_flLastSteamProgressUpdateTime + 2.0 <= local_c) {
        numTics_87 = numTics_87 + 1;
        g_flLastSteamProgressUpdateTime = local_c;
        if (isDedicated == 0) {
          strcpy(local_8c,"Updating game resources");
          iVar1 = numTics_87 % 5;
          for (local_94 = 0; local_94 < iVar1 + 1; local_94 = local_94 + 1) {
            strcat(local_8c,".");
          }
          SetLoadingProgressBarStatusText(local_8c);
        }
        else if (g_bMajorMapChange != 0) {
          g_bPrintingKeepAliveDots = 1;
          Sys_Printf(&DAT_000e7612);
        }
        recursionGuard_88 = '\0';
      }
      else {
        recursionGuard_88 = '\0';
      }
    }
  }
  return;
}


// Sys_ShutdownArgv__Fv  @ 00096310
void Sys_ShutdownArgv__Fv(void)

{
  return;
}


// Sys_ShutdownAuthentication__Fv  @ 000966f8
void Sys_ShutdownAuthentication__Fv(void)

{
  int iVar1;
  
  iVar1 = COM_CheckParm("-steam");
  if (((iVar1 == 0) && (isDedicated != 0)) && (crypt._12_4_ != 0)) {
    (*(code *)crypt._12_4_)();
  }
  return;
}


// Sys_ShutdownGame__Fv  @ 00096b74
void Sys_ShutdownGame__Fv(void)

{
  TraceShutdown__FPCci("Sys_ShutdownAuthentication()",0);
  Sys_ShutdownAuthentication__Fv();
  TraceShutdown__FPCci("Host_Shutdown()",0);
  Host_Shutdown();
  if (isDedicated != 0) {
    NET_Config(0);
  }
  TraceShutdown__FPCci("Sys_ShutdownLauncherInterface()",0);
  Sys_ShutdownLauncherInterface__Fv();
  TraceShutdown__FPCci("Sys_ShutdownMemory()",0);
  Sys_ShutdownMemory__Fv();
  TraceShutdown__FPCci("Sys_Shutdown()",0);
  Sys_Shutdown__Fv();
  return;
}


// Sys_ShutdownLauncherInterface__Fv  @ 000964a0
void Sys_ShutdownLauncherInterface__Fv(void)

{
  return;
}


// Sys_ShutdownMemory__Fv  @ 0009642c
void Sys_ShutdownMemory__Fv(void)

{
  free(DAT_0030086c);
  DAT_0030086c = (void *)0x0;
  DAT_00300870 = 0;
  return;
}


// Sys_Shutdown__Fv  @ 000961a8
void Sys_Shutdown__Fv(void)

{
  return;
}


// Sys_Sleep  @ 000943ac
void Sys_Sleep(int param_1)

{
  usleep(param_1 * 1000);
  return;
}


// Sys_SplitPath  @ 00095b58
void Sys_SplitPath(char *param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  size_t sVar1;
  char *pcVar2;
  char *local_c;
  char *local_8;
  
  local_c = (char *)0x0;
  sVar1 = strlen(param_1);
  if ((sVar1 == 0) || (param_1[1] != ':')) {
    if (param_2 != (char *)0x0) {
      *param_2 = '\0';
    }
  }
  else {
    if (param_2 != (char *)0x0) {
      strncpy(param_2,param_1,2);
      param_2[2] = '\0';
    }
    param_1 = param_1 + 2;
  }
  local_8 = (char *)0x0;
  for (pcVar2 = param_1; *pcVar2 != '\0'; pcVar2 = pcVar2 + 1) {
    if ((*pcVar2 == '/') || (*pcVar2 == '\\')) {
      local_8 = pcVar2 + 1;
    }
    else if (*pcVar2 == '.') {
      local_c = pcVar2;
    }
  }
  if (local_8 == (char *)0x0) {
    local_8 = param_1;
    if (param_3 != (char *)0x0) {
      *param_3 = '\0';
    }
  }
  else if (param_3 != (char *)0x0) {
    sVar1 = (int)local_8 - (int)param_1;
    if (0xff < sVar1) {
      sVar1 = 0xff;
    }
    strncpy(param_3,param_1,sVar1);
    param_3[sVar1] = '\0';
  }
  if ((local_c == (char *)0x0) || (local_c < local_8)) {
    if (param_4 != (char *)0x0) {
      sVar1 = (int)pcVar2 - (int)local_8;
      if (0xff < sVar1) {
        sVar1 = 0xff;
      }
      strncpy(param_4,local_8,sVar1);
      param_4[sVar1] = '\0';
    }
    if (param_5 != (char *)0x0) {
      *param_5 = '\0';
    }
  }
  else {
    if (param_4 != (char *)0x0) {
      sVar1 = (int)local_c - (int)local_8;
      if (0xff < sVar1) {
        sVar1 = 0xff;
      }
      strncpy(param_4,local_8,sVar1);
      param_4[sVar1] = '\0';
    }
    if (param_5 != (char *)0x0) {
      sVar1 = (int)pcVar2 - (int)local_c;
      if (0xff < sVar1) {
        sVar1 = 0xff;
      }
      strncpy(param_5,local_c,sVar1);
      param_5[sVar1] = '\0';
    }
  }
  return;
}


// Sys_UnloadModule__FP10CSysModule  @ 000d7be4
void Sys_UnloadModule__FP10CSysModule(int param_1)

{
  if (param_1 != 0) {
    dlclose(param_1);
  }
  return;
}


// Sys_Warning  @ 00094558
void Sys_Warning(char *param_1)

{
  char local_408 [1024];
  undefined1 *local_8;
  
  local_8 = &stack0x00000008;
  vsnprintf(local_408,0x400,param_1,local_8);
  Sys_Printf(local_408);
  return;
}


