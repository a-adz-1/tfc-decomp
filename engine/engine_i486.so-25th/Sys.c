// Sys_CheckOSVersion  @ 0007bfd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_CheckOSVersion() */

void Sys_CheckOSVersion(void)

{
  return;
}


// Sys_DebugOutStraight  @ 00079b50
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_DebugOutStraight(char *pStr)

{
  __fprintf_chk(_stderr,1,"%s\n",pStr);
  return;
}


// Sys_Error  @ 00079b80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_Error(char *error,...)

{
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,error,&stack0x00000008);
  if (Sys_Error::bReentry != false) {
    __fprintf_chk(_stderr,1,"%s\n",local_410);
                    /* WARNING: Subroutine does not return */
    __longjmp_chk(host_abortserver,2);
  }
  Sys_Error::bReentry = true;
  if ((svs.dll_initialized != false) &&
     (gEntityInterface.pfnSys_Error != (_func_void_char_ptr *)0x0)) {
    (*gEntityInterface.pfnSys_Error)(local_410);
  }
  Log_Printf("FATAL ERROR (shutting down): %s\n",local_410);
  if (g_bIsDedicatedServer == false) {
    giActive = 2;
    giStateInfo = 4;
    if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  if (Launcher_ConsolePrintf == (_func_void_char_ptr_varargs *)0x0) {
    __printf_chk(1,"FATAL ERROR (shutting down): %s\n",local_410);
  }
  else {
    (*Launcher_ConsolePrintf)("FATAL ERROR (shutting down): %s\n",local_410);
  }
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}


// Sys_FindClose  @ 00079820
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_FindClose(void)

{
  if (g_hfind != -1) {
    FS_FindClose(g_hfind);
    g_hfind = -1;
  }
  return;
}


// Sys_FindFirst  @ 00079cd0
char * Sys_FindFirst(char *path,char *basename)

{
  char *in;
  
                    /* Unresolved local var: char * psz@[???] */
  if (g_hfind != -1) {
    Sys_Error("Sys_FindFirst without close");
    FS_FindClose(g_hfind);
  }
  in = FS_FindFirst(path,&g_hfind,(char *)0x0);
  if ((basename != (char *)0x0) && (in != (char *)0x0)) {
    COM_FileBase(in,basename);
  }
  return in;
}


// Sys_FindFirstPathID  @ 00079d40
char * Sys_FindFirstPathID(char *path,char *pathid)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * psz@[DW_OP_reg0(EAX)] */
  if (g_hfind != -1) {
    Sys_Error("Sys_FindFirst without close");
    FS_FindClose(g_hfind);
  }
  pcVar1 = FS_FindFirst(path,&g_hfind,pathid);
  return pcVar1;
}


// Sys_FindNext  @ 000797e0
char * Sys_FindNext(char *basename)

{
  char *in;
  
                    /* Unresolved local var: char * psz@[???] */
  in = FS_FindNext(g_hfind);
  if ((basename != (char *)0x0) && (in != (char *)0x0)) {
    COM_FileBase(in,basename);
  }
  return in;
}


// Sys_FloatTime  @ 00079ef0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double Sys_FloatTime(void)

{
  timespec local_14 [2];
  
                    /* Unresolved local var: timespec now@[???] */
  if (!Sys_FloatTime::bInitialized) {
    Sys_FloatTime::bInitialized = true;
    clock_gettime(1,(timespec *)&Sys_FloatTime::start_time);
  }
  clock_gettime(1,local_14);
  return (double)local_14[0].tv_nsec * 1e-09 +
         (double)(local_14[0].tv_sec - Sys_FloatTime::start_time.tv_sec);
}


// Sys_GetCDKey  @ 0007bd90
void Sys_GetCDKey(char *pszCDKey,int *nLength,int *bDedicated)

{
  char *pcVar1;
  int iVar2;
  hostent *phVar3;
  uint uVar4;
  uint uVar5;
  size_t sVar6;
  uint *puVar7;
  uint *puVar8;
  int in_GS_OFFSET;
  CRC32_t local_1068;
  char local_1061 [64];
  undefined1 local_1021;
  uint local_1020 [1024];
  int local_20;
  
                    /* Unresolved local var: char[65] key@[???]
                       Unresolved local var: char[4096] hostname@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = gethostname((char *)local_1020,0x1000);
  if (iVar2 == 0) {
                    /* Unresolved local var: hostent * hostinfo@[???] */
    phVar3 = gethostbyname((char *)local_1020);
    puVar8 = local_1020;
    if (((phVar3 != (hostent *)0x0) && (phVar3->h_length == 4)) &&
       (pcVar1 = *phVar3->h_addr_list, pcVar1 != (char *)0x0)) {
      __snprintf_chk(local_1061,0x41,1,0x41,&DAT_000d7a3b,*pcVar1,pcVar1[1],pcVar1[2],pcVar1[3]);
      goto LAB_0007bea1;
    }
    do {
      puVar7 = puVar8;
      uVar4 = *puVar7 + 0xfefefeff & ~*puVar7;
      uVar5 = uVar4 & 0x80808080;
      puVar8 = puVar7 + 1;
    } while (uVar5 == 0);
    if ((uVar4 & 0x8080) == 0) {
      puVar8 = (uint *)((int)puVar7 + 6);
      uVar5 = uVar5 >> 0x10;
    }
    CRC32_ProcessBuffer(&local_1068,local_1020,
                        (int)((int)puVar8 +
                             ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)local_1020)));
  }
  else {
                    /* Unresolved local var: int val@[???] */
    local_1068 = RandomLong(0,0x7fffffff);
  }
  __snprintf_chk(local_1061,0x41,1,0x41,&DAT_000d7a44,local_1068);
LAB_0007bea1:
  local_1021 = 0;
  strcpy(pszCDKey,local_1061);
  if (nLength != (int *)0x0) {
    sVar6 = strlen(local_1061);
    *nLength = sVar6;
  }
  if (bDedicated != (int *)0x0) {
    *bDedicated = 0;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Sys_GetFactory  @ 000c4bf0
CreateInterfaceFn Sys_GetFactory(CSysModule *pModule)

{
  CreateInterfaceFn p_Var1;
  
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule == (CSysModule *)0x0) {
    p_Var1 = (CreateInterfaceFn)0x0;
  }
  else {
    p_Var1 = (CreateInterfaceFn)dlsym(pModule,"CreateInterface");
  }
  return p_Var1;
}


// Sys_GetFactory  @ 000c4c30
CreateInterfaceFn Sys_GetFactory(char *pModuleName)

{
  int iVar1;
  CreateInterfaceFn p_Var2;
  
                    /* Unresolved local var: void * handle@[???] */
  if (pModuleName != (char *)0x0) {
    iVar1 = dlopen(pModuleName,2);
    if (iVar1 != 0) {
      dlclose(iVar1);
      goto LAB_000c4c5b;
    }
  }
  iVar1 = 0;
LAB_000c4c5b:
  p_Var2 = (CreateInterfaceFn)dlsym(iVar1,"CreateInterface");
  return p_Var2;
}


// Sys_GetFactoryThis  @ 000c4c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CreateInterfaceFn Sys_GetFactoryThis(void)

{
  return CreateInterface;
}


// Sys_GetProcAddress  @ 000c4a10
void * Sys_GetProcAddress(void *pModuleHandle,char *pName)

{
  void *pvVar1;
  
  pvVar1 = (void *)dlsym();
  return pvVar1;
}


// Sys_Init  @ 00079b20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Init(void)

{
  return;
}


// Sys_Init  @ 0007bfe0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_Init() */

void Sys_Init(void)

{
  return;
}


// Sys_InitArgv  @ 0007c000
void Sys_InitArgv(char *lpCmdLine)

{
  char cVar1;
  int argc;
  
  argv[0] = "";
  host_parms.argc = 1;
  while ((argc = host_parms.argc, *lpCmdLine != '\0' && (host_parms.argc < 0x32))) {
    if (0x5d < (byte)(*lpCmdLine - 0x21U)) {
      do {
        lpCmdLine = lpCmdLine + 1;
        cVar1 = *lpCmdLine;
        if ((byte)(cVar1 - 0x21U) < 0x5e) break;
      } while (cVar1 != '\0');
      if (cVar1 == '\0') break;
    }
    argc = host_parms.argc + 1;
    host_parms.argc = argc;
    *(char **)(argc * 4 + 0x35c75c) = lpCmdLine;
    for (; (byte)(*lpCmdLine - 0x21U) < 0x5e; lpCmdLine = lpCmdLine + 1) {
    }
    if (*lpCmdLine == '\0') break;
    *lpCmdLine = '\0';
    lpCmdLine = lpCmdLine + 1;
  }
  host_parms.argv = argv;
  COM_InitArgv(argc,argv);
  host_parms.argc = com_argc;
  host_parms.argv = com_argv;
  return;
}


// Sys_InitAuthentication  @ 0007c310
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitAuthentication(void)

{
  Sys_Printf("STEAM Auth Server\r\n");
  return;
}


// Sys_InitGame  @ 0007c4c0
int Sys_InitGame(char *lpOrgCmdLine,char *pBaseDir,void *pwnd,int bIsDedicated)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  host_initialized = false;
  g_bIsDedicatedServer = bIsDedicated;
  iVar3 = COM_CheckParm("-dev");
  if (iVar3 != 0) {
    developer.value = 1.0;
  }
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    pcVar1 = gmodinfo.szInfo + (uVar4 - 4);
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1 = gmodinfo.szInfo + uVar4;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    uVar2 = uVar4 + 8;
  } while (uVar4 + 8 < 0x240);
  pcVar1 = gmodinfo.szInfo + uVar4 + 4;
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  SV_ResetModInfo();
  TraceInit("Sys_Init()","Sys_Shutdown()",0);
  FS_LogLevelLoadStarted("Launcher");
  SeedRandomNumberGenerator();
  TraceInit("Sys_InitMemory()","Sys_ShutdownMemory()",0);
  Sys_InitMemory();
  TraceInit("Sys_InitLauncherInterface()","Sys_ShutdownLauncherInterface()",0);
  gHasMMXTechnology = 1;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  TraceInit("Host_Init( &host_parms )","Host_Shutdown()",0);
  Host_Init(&host_parms);
  iVar3 = 0;
  if (host_initialized != false) {
    TraceInit("Sys_InitAuthentication()","Sys_ShutdownAuthentication()",0);
    Sys_Printf("STEAM Auth Server\r\n");
    iVar3 = 1;
    if (g_bIsDedicatedServer != false) {
      Host_InitializeGameDLL();
      NET_Config(true);
      return 1;
    }
  }
  return iVar3;
}


// Sys_InitLauncherInterface  @ 0007c2e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitLauncherInterface(void)

{
  gHasMMXTechnology = 1;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_InitMemory  @ 0007c0e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitMemory(void)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: bool bDidDefault@[???] */
  iVar3 = COM_CheckParm("-heapsize");
  if ((iVar3 != 0) && (iVar3 < com_argc + -1)) {
    lVar4 = strtol(com_argv[iVar3 + 1],(char **)0x0,10);
    host_parms.memsize = lVar4 << 10;
  }
  if (host_parms.memsize < 0xe00000) {
                    /* Unresolved local var: uint64_t nPhysMemBytes@[???] */
    lVar4 = sysconf(0x55);
    lVar5 = sysconf(0x1e);
    lVar1 = (longlong)lVar5 * (longlong)lVar4 - 1;
    uVar6 = (uint)lVar1;
    if ((int)((ulonglong)lVar1 >> 0x20) == 0) {
      if (uVar6 < 0xefffff) {
        Sys_Error("Available memory less than 15MB!!! %i\n",host_parms.memsize);
      }
      else if (0x7ffffffe < uVar6) goto LAB_0007c1f8;
      uVar2 = (ulonglong)((longlong)lVar5 * (longlong)lVar4) >> 1;
      host_parms.memsize = (int)uVar2;
      if (((int)(uVar2 >> 0x20) == 0) && ((uint)host_parms.memsize < 0xe00000)) {
        host_parms.memsize = 0xe00000;
        goto LAB_0007c131;
      }
    }
    else {
LAB_0007c1f8:
      host_parms.memsize = 0x8000000;
    }
  }
  if (0x8000000 < host_parms.memsize) {
    host_parms.memsize = 0x8000000;
  }
LAB_0007c131:
  iVar3 = COM_CheckParm("-minmemory");
  if (iVar3 != 0) {
    host_parms.memsize = 0xe00000;
  }
  iVar3 = host_parms.memsize;
  host_parms.membase = malloc(host_parms.memsize);
  if (host_parms.membase != (void *)0x0) {
    return;
  }
  Sys_Error("Unable to allocate %.2f MB\n",(double)((float)iVar3 * 9.536743e-07));
  return;
}


// Sys_IsWin95  @ 0007bfb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin95(void)

{
  return g_bIsWin95;
}


// Sys_IsWin98  @ 0007bfc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin98(void)

{
  return g_bIsWin98;
}


// Sys_LoadModule  @ 000c4a20
CSysModule * Sys_LoadModule(char *pModuleName)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  CSysModule *pCVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  int in_GS_OFFSET;
  char local_c10 [1020];
  char acStack_814 [4];
  uint local_810 [256];
  undefined1 local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: void * hDLL@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_c10[0] = '\0';
  if (*pModuleName == '/') {
    snprintf(local_c10,0x400,"%s",pModuleName);
    pCVar4 = (CSysModule *)dlopen(pModuleName,2);
  }
  else {
                    /* Unresolved local var: char[1024] szCwd@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
    getcwd((char *)local_810,0x400);
    puVar7 = local_810;
    do {
      puVar6 = puVar7;
      uVar2 = *puVar6 + 0xfefefeff & ~*puVar6;
      uVar3 = uVar2 & 0x80808080;
      puVar7 = puVar6 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar7 = (uint *)((int)puVar6 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    iVar1 = -(int)local_810 - (uint)CARRY1((byte)uVar3,(byte)uVar3);
    if (*(char *)((int)puVar7 + (int)(acStack_814 + iVar1)) == '/') {
      *(char *)((int)puVar7 + (int)(acStack_814 + iVar1)) = '\0';
    }
    __snprintf_chk(local_410,0x400,1,0x400,"%s/%s",local_810,pModuleName);
    pCVar4 = (CSysModule *)dlopen(local_410,2);
  }
  if (pCVar4 == (CSysModule *)0x0) {
                    /* Unresolved local var: char[512] str@[???] */
    uVar5 = dlerror();
    __printf_chk(1,"Error:%s\n",uVar5);
                    /* try { // try from 000c4b8f to 000d4b93 has its CatchHandler @ 000c4b30 */
                    /* try { // try from 000c4bab to 000d4d6b has its CatchHandler @ 000c4d76 */
    __snprintf_chk(local_410,0x200,1,0x200,"%s.so",local_c10);
    pCVar4 = (CSysModule *)dlopen(local_410,2);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pCVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Sys_MakeCodeWriteable  @ 00079ad0
void Sys_MakeCodeWriteable(uint32 startaddr,uint32 length)

{
  return;
}


// Sys_PageIn  @ 000797d0
void Sys_PageIn(void *ptr,int size)

{
  return;
}


// Sys_PopFPCW  @ 00079b00
void Sys_PopFPCW(void)

{
  return;
}


// Sys_Printf  @ 00079d90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_Printf(char *fmt,...)

{
  int in_GS_OFFSET;
  undefined1 local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000008);
  if ((g_bIsDedicatedServer == false) ||
     ((Launcher_ConsolePrintf != (_func_void_char_ptr_varargs *)0x0 &&
      ((*Launcher_ConsolePrintf)("%s",local_410), g_bIsDedicatedServer == false)))) {
    __fprintf_chk(_stderr,1,"%s\n",local_410);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Sys_PushFPCW_SetHigh  @ 00079af0
void Sys_PushFPCW_SetHigh(void)

{
  return;
}


// Sys_Quit  @ 00079ee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Quit(void)

{
  giActive = 3;
  return;
}


// Sys_SetFPCW  @ 00079ae0
void Sys_SetFPCW(void)

{
  return;
}


// Sys_SetupLegacyAPIs  @ 0007bfa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_SetupLegacyAPIs(void)

{
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_ShowProgressTicks  @ 0007c340
void Sys_ShowProgressTicks(char *specialProgressMsg)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_GS_OFFSET;
  double dVar4;
  char local_90 [128];
  int local_10;
  
                    /* Unresolved local var: double currentTime@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (!Sys_ShowProgressTicks::recursionGuard) {
    Sys_ShowProgressTicks::recursionGuard = true;
    iVar1 = COM_CheckParm("-steam");
    if ((iVar1 != 0) && (dVar4 = Sys_FloatTime(), g_flLastSteamProgressUpdateTime + 2.0 <= dVar4)) {
      Sys_ShowProgressTicks::numTics = Sys_ShowProgressTicks::numTics + 1;
      g_flLastSteamProgressUpdateTime = dVar4;
      if (g_bIsDedicatedServer == false) {
                    /* Unresolved local var: char[128] msg@[???]
                       Unresolved local var: int numTicsToPrint@[???] */
        uVar2 = 0;
        do {
          *(undefined4 *)(local_90 + uVar2) = *(undefined4 *)("Updating game resources" + uVar2);
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x18);
                    /* Unresolved local var: int i@[???] */
        iVar3 = 0;
        iVar1 = Sys_ShowProgressTicks::numTics % 5;
        if (-1 < iVar1) {
          do {
            iVar3 = iVar3 + 1;
            __strcat_chk(local_90,&DAT_000d0aa7,0x80);
          } while (iVar3 <= iVar1);
        }
        SetLoadingProgressBarStatusText(local_90);
      }
      else if (g_bMajorMapChange != false) {
        g_bPrintingKeepAliveDots = true;
        Sys_Printf(".");
      }
    }
    Sys_ShowProgressTicks::recursionGuard = false;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Sys_Shutdown  @ 0007bff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_Shutdown() */

void Sys_Shutdown(void)

{
  return;
}


// Sys_ShutdownArgv  @ 0007c0d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_ShutdownArgv() */

void Sys_ShutdownArgv(void)

{
  return;
}


// Sys_ShutdownAuthentication  @ 0007c330
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_ShutdownAuthentication() */

void Sys_ShutdownAuthentication(void)

{
  return;
}


// Sys_ShutdownGame  @ 0007c620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownGame(void)

{
  TraceShutdown("Host_Shutdown()",0);
  Host_Shutdown();
  if (g_bIsDedicatedServer != false) {
    NET_Config(false);
  }
  TraceShutdown("Sys_ShutdownLauncherInterface()",0);
  TraceShutdown("Sys_ShutdownAuthentication()",0);
  TraceShutdown("Sys_ShutdownMemory()",0);
  free(host_parms.membase);
  host_parms.membase = (void *)0x0;
  host_parms.memsize = 0;
  TraceShutdown("Sys_Shutdown()",0);
  return;
}


// Sys_ShutdownLauncherInterface  @ 0007c300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_ShutdownLauncherInterface() */

void Sys_ShutdownLauncherInterface(void)

{
  return;
}


// Sys_ShutdownMemory  @ 0007c2b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownMemory(void)

{
  free(host_parms.membase);
  host_parms.membase = (void *)0x0;
  host_parms.memsize = 0;
  return;
}


// Sys_Sleep  @ 00079b30
void Sys_Sleep(int msec)

{
  usleep(msec * 1000);
  return;
}


// Sys_SplitPath  @ 0007a7e0
void Sys_SplitPath(char *path,char *drive,char *dir,char *fname,char *ext)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  size_t sVar4;
  char *__src;
  char *__src_00;
  char *pcVar5;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: char * last_slash@[???]
                       Unresolved local var: char * dot@[???]
                       Unresolved local var: uint len@[???] */
  cVar2 = *path;
  if (cVar2 == '\0') {
    if (drive != (char *)0x0) {
LAB_0007a809:
      *drive = '\0';
      cVar2 = *path;
      goto LAB_0007a810;
    }
LAB_0007a928:
    __src = path;
    if (dir == (char *)0x0) goto LAB_0007a950;
    bVar3 = false;
    __src_00 = (char *)0x0;
LAB_0007a938:
    *dir = '\0';
    if (bVar3) goto LAB_0007a8a8;
  }
  else {
    if (path[1] == ':') {
      if (drive != (char *)0x0) {
        strncpy(drive,path,2);
        drive[2] = '\0';
      }
      cVar2 = path[2];
      path = path + 2;
LAB_0007a810:
      __src = path;
      if (cVar2 == '\0') goto LAB_0007a928;
    }
    else {
      __src = path;
      if (drive != (char *)0x0) goto LAB_0007a809;
    }
    __src_00 = (char *)0x0;
    pcVar1 = __src + 1;
    pcVar5 = (char *)0x0;
    do {
      while ((path = pcVar1, cVar2 == '/' || (cVar2 == '\\'))) {
        cVar2 = *path;
        pcVar1 = path + 1;
        pcVar5 = path;
        if (cVar2 == '\0') goto LAB_0007a84e;
      }
      bVar3 = cVar2 == '.';
      cVar2 = *path;
      if (bVar3) {
        __src_00 = path + -1;
      }
      pcVar1 = path + 1;
    } while (cVar2 != '\0');
LAB_0007a84e:
    if (pcVar5 == (char *)0x0) {
      bVar3 = __src_00 != (char *)0x0 && __src <= __src_00;
      if (dir != (char *)0x0) goto LAB_0007a938;
    }
    else {
      if (dir != (char *)0x0) {
        sVar4 = (int)pcVar5 - (int)__src;
        if (0xff < sVar4) {
          sVar4 = 0xff;
        }
        strncpy(dir,__src,sVar4);
        dir[sVar4] = '\0';
      }
      bVar3 = pcVar5 <= __src_00 && __src_00 != (char *)0x0;
      __src = pcVar5;
    }
    if (bVar3) {
LAB_0007a8a8:
      if (fname != (char *)0x0) {
        sVar4 = (int)__src_00 - (int)__src;
        if (0xff < sVar4) {
          sVar4 = 0xff;
        }
        strncpy(fname,__src,sVar4);
        fname[sVar4] = '\0';
      }
      if (ext == (char *)0x0) {
        return;
      }
      sVar4 = (int)path - (int)__src_00;
      if (0xff < sVar4) {
        sVar4 = 0xff;
      }
      strncpy(ext,__src_00,sVar4);
      ext[sVar4] = '\0';
      return;
    }
  }
LAB_0007a950:
  if (fname != (char *)0x0) {
    sVar4 = (int)path - (int)__src;
    if (0xff < sVar4) {
      sVar4 = 0xff;
    }
    strncpy(fname,__src,sVar4);
    fname[sVar4] = '\0';
  }
  if (ext == (char *)0x0) {
    return;
  }
  *ext = '\0';
  return;
}


// Sys_UnloadModule  @ 000c4bd0
void Sys_UnloadModule(CSysModule *pModule)

{
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule != (CSysModule *)0x0) {
    dlclose();
    return;
  }
  return;
}


// Sys_Warning  @ 00079e60
void Sys_Warning(char *pszWarning,...)

{
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,pszWarning,&stack0x00000008);
  Sys_Printf(local_410);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


