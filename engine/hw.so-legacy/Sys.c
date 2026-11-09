// Sys_CheckOSVersion  @ 00149980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_CheckOSVersion(void)

{
  return;
}


// Sys_DebugOutStraight  @ 001478e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_DebugOutStraight(char *pStr)

{
  fprintf(_stderr,"%s\n",pStr);
  return;
}


// Sys_Error  @ 001479f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_Error(char *error,...)

{
  HWND pvVar1;
  char local_40c [1028];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
                    /* Unresolved local var: SDL_Window * window@[???] */
  vsnprintf(local_40c,0x400,error,&stack0x00000008);
  if (Sys_Error::bReentry == false) {
    Sys_Error::bReentry = true;
    if ((svs.dll_initialized != false) &&
       (gEntityInterface.pfnSys_Error != (_func_void_char_ptr *)0x0)) {
      (*gEntityInterface.pfnSys_Error)(local_40c);
    }
    Log_Printf("FATAL ERROR (shutting down): %s\n",local_40c);
    if (g_bIsDedicatedServer == false) {
      pvVar1 = (HWND)0x0;
      if (pmainwindow != (HWND *)0x0) {
        pvVar1 = *pmainwindow;
      }
      Sys_Printf(local_40c);
      SDL_ShowSimpleMessageBox(0x10,"Fatal Error",local_40c,pvVar1);
      VideoMode_IsWindowed();
    }
    else if (Launcher_ConsolePrintf == (_func_void_char_ptr_varargs *)0x0) {
      printf("FATAL ERROR (shutting down): %s\n",local_40c);
    }
    else {
      (*Launcher_ConsolePrintf)("FATAL ERROR (shutting down): %s\n");
    }
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  fprintf(_stderr,"%s\n",local_40c);
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,2);
}


// Sys_FindClose  @ 001475c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_FindClose(void)

{
  if (g_hfind != -1) {
    FS_FindClose(g_hfind);
    g_hfind = -1;
  }
  return;
}


// Sys_FindFirst  @ 00147b40
char * Sys_FindFirst(char *path,char *basename)

{
  char *in;
  char *extraout_EAX;
  
                    /* Unresolved local var: char * psz@[???] */
  if (g_hfind != -1) {
    Sys_Error("Sys_FindFirst without close");
    Sys_Quit();
    return extraout_EAX;
  }
  in = FS_FindFirst(path,&g_hfind,(char *)0x0);
  if ((in != (char *)0x0) && (basename != (char *)0x0)) {
    COM_FileBase(in,basename);
    return in;
  }
  return in;
}


// Sys_FindFirstPathID  @ 00147b00
char * Sys_FindFirstPathID(char *path,char *pathid)

{
  char *pcVar1;
  char *extraout_EAX;
  char *in_stack_ffffffe8;
  char *in_stack_ffffffec;
  
                    /* Unresolved local var: char * psz@[???] */
  if (g_hfind == -1) {
    pcVar1 = FS_FindFirst(path,&g_hfind,pathid);
    return pcVar1;
  }
  Sys_Error("Sys_FindFirst without close");
  if (g_hfind == -1) {
    pcVar1 = FS_FindFirst(in_stack_ffffffe8,&g_hfind,(char *)0x0);
    if ((pcVar1 != (char *)0x0) && (in_stack_ffffffec != (char *)0x0)) {
      COM_FileBase(pcVar1,in_stack_ffffffec);
      return pcVar1;
    }
    return pcVar1;
  }
  Sys_Error("Sys_FindFirst without close");
  Sys_Quit();
  return extraout_EAX;
}


// Sys_FindNext  @ 00147580
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


// Sys_FloatTime  @ 00147bc0
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


// Sys_GetCDKey  @ 00149790
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
      goto LAB_0014984a;
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
LAB_0014984a:
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


// Sys_GetFactory  @ 0021aa10
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


// Sys_GetFactory  @ 0021aa50
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


// Sys_GetFactoryThis  @ 0021aa40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CreateInterfaceFn Sys_GetFactoryThis(void)

{
  return CreateInterfaceLocal;
}


// Sys_GetProcAddress  @ 0021a880
void * Sys_GetProcAddress(void *pModuleHandle,char *pName)

{
  void *pvVar1;
  
  pvVar1 = (void *)dlsym();
  return pvVar1;
}


// Sys_GetSurfaceCacheSize  @ 001494d0
int Sys_GetSurfaceCacheSize(int width,int height)

{
  int iVar1;
  long lVar2;
  
                    /* Unresolved local var: int size@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = COM_CheckParm("-surfcachesize");
  if (iVar1 == 0) {
    iVar1 = 0x300000;
    if (64000 < width * height * 2) {
      iVar1 = width * height * 6 + 0x2d1200;
    }
    return iVar1;
  }
  lVar2 = strtol(com_argv[iVar1 + 1],(char **)0x0,10);
  return lVar2 << 10;
}


// Sys_Init  @ 00147cc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Init(void)

{
  int iVar1;
  float fVar2;
  timespec atStack_14 [2];
  
  if (!Sys_FloatTime::bInitialized) {
    Sys_FloatTime::bInitialized = true;
    clock_gettime(1,(timespec *)&Sys_FloatTime::start_time);
  }
  clock_gettime(1,atStack_14);
  iVar1 = COM_CheckParm("-starttime");
  if (iVar1 == 0) {
    curtime = 0.0;
    lastcurtime = 0.0;
    return;
  }
  fVar2 = Q_atof(com_argv[iVar1 + 1]);
  curtime = (double)fVar2;
  lastcurtime = (double)fVar2;
  return;
}


// Sys_Init  @ 00149990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Init(void)

{
  int iVar1;
  float fVar2;
  timespec atStack_14 [2];
  
  if (!Sys_FloatTime::bInitialized) {
    Sys_FloatTime::bInitialized = true;
    clock_gettime(1,(timespec *)&Sys_FloatTime::start_time);
  }
  clock_gettime(1,atStack_14);
  iVar1 = COM_CheckParm("-starttime");
  if (iVar1 == 0) {
    curtime = 0.0;
    lastcurtime = 0.0;
    return;
  }
  fVar2 = Q_atof(com_argv[iVar1 + 1]);
  curtime = (double)fVar2;
  lastcurtime = (double)fVar2;
  return;
}


// Sys_InitArgv  @ 001499e0
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
LAB_00149a0e:
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
        if (cVar2 == '\0') goto LAB_00149a0e;
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


// Sys_InitAuthentication  @ 00149e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitAuthentication(void)

{
  Sys_Printf("STEAM Auth Server\r\n");
  return;
}


// Sys_InitFloatTime  @ 00147c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitFloatTime(void)

{
  int iVar1;
  float fVar2;
  timespec local_14 [2];
  
                    /* Unresolved local var: int j@[???] */
                    /* Unresolved local var: timespec now@[???] */
  if (!Sys_FloatTime::bInitialized) {
    Sys_FloatTime::bInitialized = true;
    clock_gettime(1,(timespec *)&Sys_FloatTime::start_time);
  }
  clock_gettime(1,local_14);
  iVar1 = COM_CheckParm("-starttime");
  if (iVar1 == 0) {
    curtime = 0.0;
    lastcurtime = 0.0;
    return;
  }
  fVar2 = Q_atof(com_argv[iVar1 + 1]);
  curtime = (double)fVar2;
  lastcurtime = (double)fVar2;
  return;
}


// Sys_InitGame  @ 00149fb0
int Sys_InitGame(char *lpOrgCmdLine,char *pBaseDir,void *pwnd,int bIsDedicated)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  char local_218 [512];
  char local_18 [12];
  
                    /* Unresolved local var: bool gD3DMode@[???]
                       Unresolved local var: char[12] en_US@[???]
                       Unresolved local var: char * CurrentLocale@[???] */
  host_initialized = false;
  if (bIsDedicated == 0) {
    pmainwindow = pwnd;
    (*videomode->_vptr_IVideoMode[10])(videomode);
  }
  g_bIsDedicatedServer = bIsDedicated;
  iVar2 = COM_CheckParm("-dev");
  if (iVar2 != 0) {
    developer.value = 1.0;
  }
  uVar1 = 0;
  do {
    uVar3 = uVar1;
    pcVar4 = gmodinfo.szInfo + (uVar3 - 4);
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = gmodinfo.szInfo + uVar3;
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = gmodinfo.szInfo + uVar3 + 4;
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = gmodinfo.szInfo + uVar3 + 8;
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    uVar1 = uVar3 + 0x10;
  } while (uVar3 + 0x10 < 0x240);
  pcVar4 = gmodinfo.szInfo + uVar3 + 0xc;
  pcVar4[0] = '\0';
  pcVar4[1] = '\0';
  pcVar4[2] = '\0';
  pcVar4[3] = '\0';
  SV_ResetModInfo();
  TraceInit("Sys_Init()","Sys_Shutdown()",0);
  Sys_InitFloatTime();
  FS_LogLevelLoadStarted("Launcher");
  SeedRandomNumberGenerator();
  TraceInit("Sys_InitMemory()","Sys_ShutdownMemory()",0);
  Sys_InitMemory();
  TraceInit("Sys_InitLauncherInterface()","Sys_ShutdownLauncherInterface()",0);
  gHasMMXTechnology = 1;
  VID_FlipScreen = Sys_VID_FlipScreen;
  D_SurfaceCacheForRes = Sys_GetSurfaceCacheSize;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  iVar5 = 0;
  iVar2 = GL_SetMode(*pmainwindow,&maindc,&baseRC,0,"opengl32.dll",lpOrgCmdLine);
  if (iVar2 != 0) {
    TraceInit("Host_Init( &host_parms )","Host_Shutdown()",0);
    Host_Init(&host_parms);
    if (host_initialized != false) {
      TraceInit("Sys_InitAuthentication()","Sys_ShutdownAuthentication()",0);
      Sys_Printf("STEAM Auth Server\r\n");
      if (g_bIsDedicatedServer == false) {
        ClientDLL_ActivateMouse();
      }
      else {
        Host_InitializeGameDLL();
        NET_Config(true);
      }
      iVar5 = 1;
      builtin_strncpy(local_18,"en_US.UTF-8",0xc);
      pcVar4 = setlocale(6,(char *)0x0);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "c";
      }
      iVar2 = strcasecmp(pcVar4,local_18);
      if (iVar2 != 0) {
                    /* Unresolved local var: char[512] MessageText@[???] */
        snprintf(local_218,0x200,
                 "SetLocale(\'%s\') failed. Using \'%s\'.\nYou may have limited glyph support.\nPlease install \'%s\' locale."
                 ,local_18,pcVar4,local_18);
        SDL_ShowSimpleMessageBox(0,"Warning",local_218,*pmainwindow);
      }
    }
  }
  return iVar5;
}


// Sys_InitLauncherInterface  @ 00149dd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitLauncherInterface(void)

{
  gHasMMXTechnology = 1;
  VID_FlipScreen = Sys_VID_FlipScreen;
  D_SurfaceCacheForRes = Sys_GetSurfaceCacheSize;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_InitMemory  @ 00149c90
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
    goto joined_r0x00149d1f;
  }
  iVar1 = COM_CheckParm("-minmemory");
joined_r0x00149d1f:
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


// Sys_IsWin95  @ 00149960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin95(void)

{
  return g_bIsWin95;
}


// Sys_IsWin98  @ 00149970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin98(void)

{
  return g_bIsWin98;
}


// Sys_LoadModule  @ 0021a890
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


// Sys_MakeCodeWriteable  @ 00147870
void Sys_MakeCodeWriteable(uint32 startaddr,uint32 length)

{
  return;
}


// Sys_PageIn  @ 00147570
void Sys_PageIn(void *ptr,int size)

{
  return;
}


// Sys_PopFPCW  @ 001478a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_PopFPCW(void)

{
  return;
}


// Sys_Printf  @ 00147910
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


// Sys_PushFPCW_SetHigh  @ 00147890
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_PushFPCW_SetHigh(void)

{
  return;
}


// Sys_Quit  @ 00147bb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Quit(void)

{
  giActive = 3;
  return;
}


// Sys_SetFPCW  @ 00147880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_SetFPCW(void)

{
  return;
}


// Sys_SetupLegacyAPIs  @ 00149930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_SetupLegacyAPIs(void)

{
  VID_FlipScreen = Sys_VID_FlipScreen;
  D_SurfaceCacheForRes = Sys_GetSurfaceCacheSize;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_ShowProgressTicks  @ 00149e40
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


// Sys_Shutdown  @ 001499a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Shutdown(void)

{
  Sys_ShutdownFloatTime();
  Steam_ShutdownClient();
  GL_Shutdown(*pmainwindow,maindc,baseRC);
  return;
}


// Sys_ShutdownArgv  @ 00149c80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownArgv(void)

{
  return;
}


// Sys_ShutdownAuthentication  @ 00149e30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownAuthentication(void)

{
  return;
}


// Sys_ShutdownFloatTime  @ 00147cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownFloatTime(void)

{
  lastcurtime = 0.0;
  curtime = 0.0;
  return;
}


// Sys_ShutdownGame  @ 0014a290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownGame(void)

{
  if (g_bIsDedicatedServer == false) {
    ClientDLL_DeactivateMouse();
  }
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
  Sys_ShutdownFloatTime();
  Steam_ShutdownClient();
  GL_Shutdown(*pmainwindow,maindc,baseRC);
  return;
}


// Sys_ShutdownLauncherInterface  @ 00149e00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownLauncherInterface(void)

{
  return;
}


// Sys_ShutdownMemory  @ 00149da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownMemory(void)

{
  free(host_parms.membase);
  host_parms.membase = (void *)0x0;
  host_parms.memsize = 0;
  return;
}


// Sys_Sleep  @ 001478c0
void Sys_Sleep(int msec)

{
  usleep(msec * 1000);
  return;
}


// Sys_SplitPath  @ 00149210
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
LAB_00149255:
        cVar1 = pcVar3[1];
      }
      else {
        if (cVar1 != '.') goto LAB_00149255;
        cVar1 = pcVar3[1];
        __src = pcVar3;
      }
      if (cVar1 == '\0') goto LAB_00149280;
      pcVar3 = pcVar3 + 1;
    } while( true );
  }
  bVar2 = false;
  __src = (char *)0x0;
  pcVar3 = path;
LAB_001493d7:
  if (dir != (char *)0x0) {
    *dir = '\0';
  }
LAB_001492d0:
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
LAB_00149280:
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
    goto LAB_001492d0;
  }
  bVar2 = path <= __src && __src != (char *)0x0;
  goto LAB_001493d7;
}


// Sys_UnloadModule  @ 0021a9f0
void Sys_UnloadModule(CSysModule *pModule)

{
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule != (CSysModule *)0x0) {
    dlclose();
    return;
  }
  return;
}


// Sys_VID_FlipScreen  @ 00149590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_VID_FlipScreen(void)

{
  if (pmainwindow != (HWND *)0x0) {
    SDL_GL_SwapWindow(*pmainwindow);
  }
  return;
}


// Sys_Warning  @ 001479a0
void Sys_Warning(char *pszWarning,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  vsnprintf(local_40c,0x400,pszWarning,&stack0x00000008);
  Sys_Printf(local_40c);
  return;
}


