// Sys_CheckOSVersion  @ 00097f50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_CheckOSVersion(void)

{
  return;
}


// Sys_DebugOutStraight  @ 00095ca0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_DebugOutStraight(char *pStr)

{
  fprintf(_stderr,"%s\n",pStr);
  return;
}


// Sys_Error  @ 00095cd0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_Error(char *error,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  vsnprintf(local_40c,0x400,error,&stack0x00000008);
  if (Sys_Error::bReentry != false) {
    fprintf(_stderr,"%s\n",local_40c);
                    /* WARNING: Subroutine does not return */
    longjmp((__jmp_buf_tag *)host_abortserver,2);
  }
  Sys_Error::bReentry = true;
  if ((svs.dll_initialized != false) &&
     (gEntityInterface.pfnSys_Error != (_func_void_char_ptr *)0x0)) {
    (*gEntityInterface.pfnSys_Error)(local_40c);
  }
  Log_Printf("FATAL ERROR (shutting down): %s\n",local_40c);
  if (g_bIsDedicatedServer == false) {
    giActive = 2;
    giStateInfo = 4;
    return;
  }
  if (Launcher_ConsolePrintf == (_func_void_char_ptr_varargs *)0x0) {
    printf("FATAL ERROR (shutting down): %s\n",local_40c);
  }
  else {
    (*Launcher_ConsolePrintf)("FATAL ERROR (shutting down): %s\n");
  }
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}


// Sys_FindClose  @ 00095970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_FindClose(void)

{
  if (g_hfind != -1) {
    FS_FindClose(g_hfind);
    g_hfind = -1;
  }
  return;
}


// Sys_FindFirst  @ 00095e10
char * Sys_FindFirst(char *path,char *basename)

{
  char *in;
  
                    /* Unresolved local var: char * psz@[???] */
  if (g_hfind != -1) {
    Sys_Error("Sys_FindFirst without close");
    FS_FindClose(g_hfind);
  }
  in = FS_FindFirst(path,&g_hfind,(char *)0x0);
  if ((in != (char *)0x0) && (basename != (char *)0x0)) {
    COM_FileBase(in,basename);
    return in;
  }
  return in;
}


// Sys_FindFirstPathID  @ 00095dc0
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


// Sys_FindNext  @ 00095930
char * Sys_FindNext(char *basename)

{
  char *in;
  
                    /* Unresolved local var: char * psz@[???] */
  in = FS_FindNext(g_hfind);
  if ((in != (char *)0x0) && (basename != (char *)0x0)) {
    COM_FileBase(in,basename);
    return in;
  }
  return in;
}


// Sys_FloatTime  @ 00095f70
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


// Sys_GetCDKey  @ 00097d80
void Sys_GetCDKey(char *pszCDKey,int *nLength,int *bDedicated)

{
  byte *pbVar1;
  int iVar2;
  hostent *phVar3;
  size_t sVar4;
  char local_1051 [4096];
  char local_51 [64];
  undefined1 local_11;
  CRC32_t local_10;
  
                    /* Unresolved local var: char[65] key@[???]
                       Unresolved local var: char[4096] hostname@[???] */
  iVar2 = gethostname(local_1051,0x1000);
  if (iVar2 == 0) {
                    /* Unresolved local var: hostent * hostinfo@[???] */
    phVar3 = gethostbyname(local_1051);
    if (((phVar3 != (hostent *)0x0) && (phVar3->h_length == 4)) &&
       (pbVar1 = (byte *)*phVar3->h_addr_list, pbVar1 != (byte *)0x0)) {
      snprintf(local_51,0x41,"%u.%u.%u.%u",(uint)*pbVar1,(uint)pbVar1[1],(uint)pbVar1[2],
               (uint)pbVar1[3]);
      goto LAB_00097e3a;
    }
                    /* Unresolved local var: CRC32_t crc@[???] */
    sVar4 = strlen(local_1051);
    CRC32_ProcessBuffer(&local_10,local_1051,sVar4);
  }
  else {
                    /* Unresolved local var: int val@[???] */
    local_10 = RandomLong(0,0x7fffffff);
  }
  snprintf(local_51,0x41,"%u",local_10);
LAB_00097e3a:
  local_11 = 0;
  strcpy(pszCDKey,local_51);
  if (nLength != (int *)0x0) {
    sVar4 = strlen(local_51);
    *nLength = sVar4;
  }
  if (bDedicated != (int *)0x0) {
    *bDedicated = 0;
  }
  return;
}


// Sys_GetFactory  @ 000d4c50
CreateInterfaceFn Sys_GetFactory(CSysModule *pModule)

{
  CreateInterfaceFn p_Var1;
  
                    /* Unresolved local var: void * hDLL@[???] */
  p_Var1 = (CreateInterfaceFn)0x0;
  if (pModule != (CSysModule *)0x0) {
    p_Var1 = (CreateInterfaceFn)dlsym(pModule,"CreateInterface");
  }
  return p_Var1;
}


// Sys_GetFactory  @ 000d4c90
CreateInterfaceFn Sys_GetFactory(char *pModuleName)

{
  CreateInterfaceFn p_Var1;
  int iVar2;
  
                    /* Unresolved local var: void * handle@[???] */
  iVar2 = 0;
  if (pModuleName != (char *)0x0) {
    iVar2 = dlopen(pModuleName,2);
    if (iVar2 != 0) {
      dlclose(iVar2);
    }
  }
  p_Var1 = (CreateInterfaceFn)dlsym(iVar2,"CreateInterface");
  return p_Var1;
}


// Sys_GetFactoryThis  @ 000d4c80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CreateInterfaceFn Sys_GetFactoryThis(void)

{
  return CreateInterfaceLocal;
}


// Sys_GetProcAddress  @ 000d4ac0
void * Sys_GetProcAddress(void *pModuleHandle,char *pName)

{
  void *pvVar1;
  
  pvVar1 = (void *)dlsym();
  return pvVar1;
}


// Sys_Init  @ 00095c70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Init(void)

{
  return;
}


// Sys_Init  @ 00097f60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Init(void)

{
  return;
}


// Sys_InitArgv  @ 00097f80
void Sys_InitArgv(char *lpCmdLine)

{
  char cVar1;
  char cVar2;
  
  host_parms.argc = 1;
  argv[0] = "";
  do {
    cVar2 = *lpCmdLine;
    do {
      if ((cVar2 == '\0') || (0x31 < host_parms.argc)) {
LAB_00097faf:
        host_parms.argv = argv;
        COM_InitArgv(host_parms.argc,argv);
        host_parms.argc = com_argc;
        host_parms.argv = com_argv;
        return;
      }
      if (0x5d < (byte)(cVar2 - 0x21U)) {
        do {
          lpCmdLine = lpCmdLine + 1;
          cVar2 = *lpCmdLine;
          if ((byte)(cVar2 - 0x21U) < 0x5e) break;
        } while (cVar2 != '\0');
        if (cVar2 == '\0') goto LAB_00097faf;
      }
      argv[host_parms.argc] = lpCmdLine;
      host_parms.argc = host_parms.argc + 1;
      cVar1 = *lpCmdLine;
      while ((byte)(cVar1 - 0x21U) < 0x5e) {
        lpCmdLine = lpCmdLine + 1;
        cVar1 = *lpCmdLine;
      }
      cVar2 = '\0';
    } while (cVar1 == '\0');
    *lpCmdLine = '\0';
    lpCmdLine = lpCmdLine + 1;
  } while( true );
}


// Sys_InitAuthentication  @ 000983a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitAuthentication(void)

{
  Sys_Printf("STEAM Auth Server\r\n");
  return;
}


// Sys_InitGame  @ 00098540
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
    pcVar1 = gmodinfo.szInfo + uVar4 + 4;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1 = gmodinfo.szInfo + uVar4 + 8;
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    uVar2 = uVar4 + 0x10;
  } while (uVar4 + 0x10 < 0x240);
  pcVar1 = gmodinfo.szInfo + uVar4 + 0xc;
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


// Sys_InitLauncherInterface  @ 00098370
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitLauncherInterface(void)

{
  gHasMMXTechnology = 1;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_InitMemory  @ 00098230
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitMemory(void)

{
  int iVar1;
  long lVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: bool bDidDefault@[???] */
  iVar1 = COM_CheckParm("-heapsize");
  if ((iVar1 != 0) && (iVar1 < com_argc + -1)) {
    lVar2 = strtol(com_argv[iVar1 + 1],(char **)0x0,10);
    host_parms.memsize = lVar2 << 10;
  }
  if (host_parms.memsize < 0xe00000) {
    host_parms.memsize = 0x2800000;
  }
  else if (0x8000000 < host_parms.memsize) {
    host_parms.memsize = 0x8000000;
    iVar1 = COM_CheckParm("-minmemory");
    goto joined_r0x000982bf;
  }
  iVar1 = COM_CheckParm("-minmemory");
joined_r0x000982bf:
  if (iVar1 != 0) {
    host_parms.memsize = 0xe00000;
  }
  iVar1 = host_parms.memsize;
  host_parms.membase = malloc(host_parms.memsize);
  if (host_parms.membase != (void *)0x0) {
    return;
  }
  Sys_Error("Unable to allocate %.2f MB\n",(double)((float)iVar1 * 9.536743e-07));
  return;
}


// Sys_IsWin95  @ 00097f30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin95(void)

{
  return g_bIsWin95;
}


// Sys_IsWin98  @ 00097f40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin98(void)

{
  return g_bIsWin98;
}


// Sys_LoadModule  @ 000d4ad0
CSysModule * Sys_LoadModule(char *pModuleName)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  CSysModule *pCVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  char local_c0c [1020];
  char acStack_810 [4];
  uint local_80c [256];
  char local_40c [1028];
  
                    /* Unresolved local var: void * hDLL@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
  local_c0c[0] = '\0';
  if (*pModuleName == '/') {
    snprintf(local_c0c,0x400,"%s",pModuleName);
    pCVar4 = (CSysModule *)dlopen(pModuleName,2);
  }
  else {
                    /* Unresolved local var: char[1024] szCwd@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
    getcwd((char *)local_80c,0x400);
    puVar7 = local_80c;
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
    iVar1 = -(int)local_80c - (uint)CARRY1((byte)uVar3,(byte)uVar3);
    if (*(char *)((int)puVar7 + (int)(acStack_810 + iVar1)) == '/') {
      *(char *)((int)puVar7 + (int)(acStack_810 + iVar1)) = '\0';
    }
    snprintf(local_40c,0x400,"%s/%s",local_80c,pModuleName);
    pCVar4 = (CSysModule *)dlopen(local_40c,2);
  }
  if (pCVar4 != (CSysModule *)0x0) {
    return pCVar4;
  }
                    /* Unresolved local var: char[512] str@[???] */
  uVar5 = dlerror();
  printf("Error:%s\n",uVar5);
  snprintf(local_40c,0x200,"%s.so",local_c0c);
  pCVar4 = (CSysModule *)dlopen(local_40c,2);
  return pCVar4;
}


// Sys_MakeCodeWriteable  @ 00095c20
void Sys_MakeCodeWriteable(uint32 startaddr,uint32 length)

{
  return;
}


// Sys_PageIn  @ 00095920
void Sys_PageIn(void *ptr,int size)

{
  return;
}


// Sys_PopFPCW  @ 00095c50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_PopFPCW(void)

{
  return;
}


// Sys_Printf  @ 00095e80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_Printf(char *fmt,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  vsnprintf(local_40c,0x400,fmt,&stack0x00000008);
  if (g_bIsDedicatedServer != false) {
    if (Launcher_ConsolePrintf == (_func_void_char_ptr_varargs *)0x0) {
      return;
    }
    (*Launcher_ConsolePrintf)("%s",local_40c);
    if (g_bIsDedicatedServer != false) {
      return;
    }
  }
  fprintf(_stderr,"%s\n",local_40c);
  return;
}


// Sys_PushFPCW_SetHigh  @ 00095c40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_PushFPCW_SetHigh(void)

{
  return;
}


// Sys_Quit  @ 00095f60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Quit(void)

{
  giActive = 3;
  return;
}


// Sys_SetFPCW  @ 00095c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_SetFPCW(void)

{
  return;
}


// Sys_SetupLegacyAPIs  @ 00097f20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_SetupLegacyAPIs(void)

{
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_ShowProgressTicks  @ 000983d0
void Sys_ShowProgressTicks(char *specialProgressMsg)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  double dVar7;
  uint local_8c [32];
  
                    /* Unresolved local var: double currentTime@[???] */
  if (!Sys_ShowProgressTicks::lexical_block_0::recursionGuard) {
    Sys_ShowProgressTicks::lexical_block_0::recursionGuard = true;
    iVar1 = COM_CheckParm("-steam");
    if ((iVar1 != 0) && (dVar7 = Sys_FloatTime(), g_flLastSteamProgressUpdateTime + 2.0 <= dVar7)) {
      Sys_ShowProgressTicks::lexical_block_0::numTics =
           Sys_ShowProgressTicks::lexical_block_0::numTics + 1;
      g_flLastSteamProgressUpdateTime = dVar7;
      if (g_bIsDedicatedServer == false) {
                    /* Unresolved local var: char[128] msg@[???]
                       Unresolved local var: int numTicsToPrint@[???] */
        uVar2 = 0;
        do {
          *(undefined4 *)((int)local_8c + uVar2) =
               *(undefined4 *)("Updating game resources" + uVar2);
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x18);
                    /* Unresolved local var: int i@[???] */
        if (-1 < Sys_ShowProgressTicks::lexical_block_0::numTics % 5) {
          iVar1 = 1;
          puVar5 = local_8c;
          do {
            do {
              puVar4 = puVar5;
              uVar3 = *puVar4 + 0xfefefeff & ~*puVar4;
              uVar2 = uVar3 & 0x80808080;
              puVar5 = puVar4 + 1;
            } while (uVar2 == 0);
            if ((uVar3 & 0x8080) == 0) {
              puVar5 = (uint *)((int)puVar4 + 6);
              uVar2 = uVar2 >> 0x10;
            }
            pcVar6 = (char *)((int)puVar5 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2)));
            iVar1 = iVar1 + 1;
            pcVar6[0] = '.';
            pcVar6[1] = '\0';
            puVar5 = local_8c;
          } while (iVar1 != Sys_ShowProgressTicks::lexical_block_0::numTics % 5 + 2);
        }
        SetLoadingProgressBarStatusText((char *)local_8c);
      }
      else if (g_bMajorMapChange != false) {
        g_bPrintingKeepAliveDots = true;
        Sys_Printf(".");
      }
    }
    Sys_ShowProgressTicks::lexical_block_0::recursionGuard = false;
  }
  return;
}


// Sys_Shutdown  @ 00097f70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Shutdown(void)

{
  return;
}


// Sys_ShutdownArgv  @ 00098220
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownArgv(void)

{
  return;
}


// Sys_ShutdownAuthentication  @ 000983c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownAuthentication(void)

{
  return;
}


// Sys_ShutdownGame  @ 000986c0
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


// Sys_ShutdownLauncherInterface  @ 00098390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownLauncherInterface(void)

{
  return;
}


// Sys_ShutdownMemory  @ 00098340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownMemory(void)

{
  free(host_parms.membase);
  host_parms.membase = (void *)0x0;
  host_parms.memsize = 0;
  return;
}


// Sys_Sleep  @ 00095c80
void Sys_Sleep(int msec)

{
  usleep(msec * 1000);
  return;
}


// Sys_SplitPath  @ 000967f0
void Sys_SplitPath(char *path,char *drive,char *dir,char *fname,char *ext)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  size_t sVar4;
  char *__src;
  char *pcVar5;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: char * last_slash@[???]
                       Unresolved local var: char * dot@[???]
                       Unresolved local var: uint len@[???] */
  cVar1 = *path;
  if ((cVar1 == '\0') || (path[1] != ':')) {
    if (drive != (char *)0x0) {
      *drive = '\0';
      cVar1 = *path;
    }
  }
  else {
    if (drive != (char *)0x0) {
      strncpy(drive,path,2);
      drive[2] = '\0';
    }
    cVar1 = path[2];
    path = path + 2;
  }
  if (cVar1 != '\0') {
    __src = (char *)0x0;
    pcVar5 = (char *)0x0;
    pcVar3 = path;
    do {
      if ((cVar1 == '\\') || (cVar1 == '/')) {
        pcVar5 = pcVar3 + 1;
LAB_00096835:
        cVar1 = pcVar3[1];
      }
      else {
        if (cVar1 != '.') goto LAB_00096835;
        cVar1 = pcVar3[1];
        __src = pcVar3;
      }
      if (cVar1 == '\0') goto LAB_00096860;
      pcVar3 = pcVar3 + 1;
    } while( true );
  }
  bVar2 = false;
  __src = (char *)0x0;
  pcVar3 = path;
LAB_000969b7:
  if (dir != (char *)0x0) {
    *dir = '\0';
  }
LAB_000968b0:
  if (bVar2) {
    if (fname != (char *)0x0) {
      sVar4 = (int)__src - (int)path;
      if (0xff < sVar4) {
        sVar4 = 0xff;
      }
      strncpy(fname,path,sVar4);
      fname[sVar4] = '\0';
    }
    if (ext != (char *)0x0) {
      sVar4 = (int)pcVar3 - (int)__src;
      if (0xff < sVar4) {
        sVar4 = 0xff;
      }
      strncpy(ext,__src,sVar4);
      ext[sVar4] = '\0';
    }
  }
  else {
    if (fname != (char *)0x0) {
      sVar4 = (int)pcVar3 - (int)path;
      if (0xff < sVar4) {
        sVar4 = 0xff;
      }
      strncpy(fname,path,sVar4);
      fname[sVar4] = '\0';
    }
    if (ext != (char *)0x0) {
      *ext = '\0';
      return;
    }
  }
  return;
LAB_00096860:
  pcVar3 = pcVar3 + 1;
  if (pcVar5 != (char *)0x0) {
    if (dir != (char *)0x0) {
      sVar4 = (int)pcVar5 - (int)path;
      if (0xff < sVar4) {
        sVar4 = 0xff;
      }
      strncpy(dir,path,sVar4);
      dir[sVar4] = '\0';
    }
    bVar2 = pcVar5 <= __src && __src != (char *)0x0;
    path = pcVar5;
    goto LAB_000968b0;
  }
  bVar2 = path <= __src && __src != (char *)0x0;
  goto LAB_000969b7;
}


// Sys_UnloadModule  @ 000d4c30
void Sys_UnloadModule(CSysModule *pModule)

{
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule != (CSysModule *)0x0) {
    dlclose();
    return;
  }
  return;
}


// Sys_Warning  @ 00095f10
void Sys_Warning(char *pszWarning,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  vsnprintf(local_40c,0x400,pszWarning,&stack0x00000008);
  Sys_Printf(local_40c);
  return;
}


