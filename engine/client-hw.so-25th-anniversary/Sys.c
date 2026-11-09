// Sys_CheckOSVersion  @ 000e6880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_CheckOSVersion() */

void Sys_CheckOSVersion(void)

{
  return;
}


// Sys_DebugOutStraight  @ 000e4670
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_DebugOutStraight(char *pStr)

{
  __fprintf_chk(_stderr,1,0x25dcd4,pStr);
  return;
}


// Sys_Error  @ 000e4770
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Sys_Error(char *error,...)

{
  HWND pvVar1;
  int in_GS_OFFSET;
  char local_410 [1024];
  undefined4 local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] text@[???] */
  local_10 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,error,&stack0x00000008);
  if (Sys_Error::bReentry == false) {
    Sys_Error::bReentry = true;
    if ((svs.dll_initialized != false) &&
       (gEntityInterface.pfnSys_Error != (_func_void_char_ptr *)0x0)) {
      (*gEntityInterface.pfnSys_Error)(local_410);
    }
    Log_Printf("FATAL ERROR (shutting down): %s\n",local_410);
    if (g_bIsDedicatedServer == false) {
                    /* Unresolved local var: SDL_Window * window@[???] */
      if (pmainwindow == (HWND *)0x0) {
        pvVar1 = (HWND)0x0;
      }
      else {
        pvVar1 = *pmainwindow;
      }
      Sys_Printf(local_410);
      SDL_ShowSimpleMessageBox(0x10,0x25bd70,local_410,pvVar1);
      VideoMode_IsWindowed();
    }
    else if (Launcher_ConsolePrintf == (_func_void_char_ptr_varargs *)0x0) {
      __printf_chk(1,"FATAL ERROR (shutting down): %s\n",local_410);
    }
    else {
      (*Launcher_ConsolePrintf)("FATAL ERROR (shutting down): %s\n",local_410);
    }
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  __fprintf_chk(_stderr,1,0x25dcd4,local_410);
                    /* WARNING: Subroutine does not return */
  __longjmp_chk(host_abortserver,2);
}


// Sys_FindClose  @ 000e42d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_FindClose(void)

{
  if (g_hfind != -1) {
    FS_FindClose(g_hfind);
    g_hfind = -1;
  }
  return;
}


// Sys_FindFirst  @ 000e48c0
char * Sys_FindFirst(char *path,char *basename)

{
  char *in;
  
                    /* Unresolved local var: char * psz@[???] */
  if (g_hfind == -1) {
    in = FS_FindFirst(path,&g_hfind,(char *)0x0);
    if ((basename != (char *)0x0) && (in != (char *)0x0)) {
      COM_FileBase(in,basename);
    }
    return in;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Sys_FindFirst without close");
}


// Sys_FindFirstPathID  @ 000e4920
char * Sys_FindFirstPathID(char *path,char *pathid)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * psz@[???] */
  if (g_hfind == -1) {
    pcVar1 = FS_FindFirst(path,&g_hfind,pathid);
    return pcVar1;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Sys_FindFirst without close");
}


// Sys_FindNext  @ 000e4290
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


// Sys_FloatTime  @ 000e49f0
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


// Sys_GetCDKey  @ 000e6620
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
      __snprintf_chk(local_1061,0x41,1,0x41,&DAT_0025c2aa,*pcVar1,pcVar1[1],pcVar1[2],pcVar1[3]);
      goto LAB_000e6731;
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
  __snprintf_chk(local_1061,0x41,1,0x41,&DAT_0025c2b3,local_1068);
LAB_000e6731:
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


// Sys_GetFactory  @ 001cf820
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


// Sys_GetFactory  @ 001cf860
CreateInterfaceFn Sys_GetFactory(char *pModuleName)

{
  int iVar1;
  CreateInterfaceFn p_Var2;
  
                    /* Unresolved local var: void * handle@[???] */
  if (pModuleName != (char *)0x0) {
    iVar1 = dlopen(pModuleName,2);
    if (iVar1 != 0) {
      dlclose(iVar1);
      goto LAB_001cf88b;
    }
  }
  iVar1 = 0;
LAB_001cf88b:
  p_Var2 = (CreateInterfaceFn)dlsym(iVar1,"CreateInterface");
  return p_Var2;
}


// Sys_GetFactoryThis  @ 001cf850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CreateInterfaceFn Sys_GetFactoryThis(void)

{
  return CreateInterface;
}


// Sys_GetProcAddress  @ 001cf640
void * Sys_GetProcAddress(void *pModuleHandle,char *pName)

{
  void *pvVar1;
  
  pvVar1 = (void *)dlsym();
  return pvVar1;
}


// Sys_GetSurfaceCacheSize  @ 000e6010
int Sys_GetSurfaceCacheSize(int width,int height)

{
  int iVar1;
  long lVar2;
  
                    /* Unresolved local var: int size@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = COM_CheckParm("-surfcachesize");
  if (iVar1 == 0) {
    iVar1 = width * height * 6 + 0x2d1200;
    if (width * height * 2 < 0xfa01) {
      iVar1 = 0x300000;
    }
    return iVar1;
  }
  lVar2 = strtol(com_argv[iVar1 + 1],(char **)0x0,10);
  return lVar2 << 10;
}


// Sys_Init  @ 000e45d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Init(void)

{
  int iVar1;
  float fVar2;
  timespec local_14 [2];
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: timespec now@[???] */
  if (!Sys_FloatTime::bInitialized) {
    Sys_FloatTime::bInitialized = true;
    clock_gettime(1,(timespec *)&Sys_FloatTime::start_time);
  }
  clock_gettime(1,local_14);
  iVar1 = COM_CheckParm("-starttime");
  if (iVar1 == 0) {
    curtime = 0.0;
    return;
  }
  fVar2 = Q_atof(com_argv[iVar1 + 1]);
  curtime = (double)fVar2;
  return;
}


// Sys_Init  @ 000e6890
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
    return;
  }
  fVar2 = Q_atof(com_argv[iVar1 + 1]);
  curtime = (double)fVar2;
  return;
}


// Sys_InitArgv  @ 000e68e0
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
    *(char **)(argc * 4 + 0x9bc93c) = lpCmdLine;
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


// Sys_InitAuthentication  @ 000e6c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitAuthentication(void)

{
  Sys_Printf("STEAM Auth Server\r\n");
  return;
}


// Sys_InitFloatTime  @ 000e4a50
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
    return;
  }
  fVar2 = Q_atof(com_argv[iVar1 + 1]);
  curtime = (double)fVar2;
  return;
}


// Sys_InitGame  @ 000e6db0
int Sys_InitGame(char *lpOrgCmdLine,char *pBaseDir,void *pwnd,int bIsDedicated)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int in_GS_OFFSET;
  char local_21c [524];
  int local_10;
  
                    /* Unresolved local var: bool gD3DMode@[???]
                       Unresolved local var: char[12] en_US@[???]
                       Unresolved local var: char * CurrentLocale@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  host_initialized = false;
  if (bIsDedicated == 0) {
    pmainwindow = pwnd;
    (*videomode->_vptr_IVideoMode[0xb])(videomode);
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
    uVar1 = uVar3 + 8;
  } while (uVar3 + 8 < 0x240);
  pcVar4 = gmodinfo.szInfo + uVar3 + 4;
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
      iVar2 = 1;
      builtin_strncpy(local_21c,"en_US.UTF-8",0xc);
      pcVar4 = setlocale(6,(char *)0x0);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "c";
      }
      iVar5 = strcasecmp(pcVar4,local_21c);
      if (iVar5 != 0) {
                    /* Unresolved local var: char[512] MessageText@[???] */
        __snprintf_chk(local_21c + 0xc,0x200,1,0x200,
                       "SetLocale(\'%s\') failed. Using \'%s\'.\nYou may have limited glyph support.\nPlease install \'%s\' locale."
                       ,local_21c,pcVar4,local_21c);
        SDL_ShowSimpleMessageBox(0,"Warning",local_21c + 0xc,*pmainwindow);
      }
      goto LAB_000e6f22;
    }
  }
  iVar2 = 0;
LAB_000e6f22:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


// Sys_InitLauncherInterface  @ 000e6bc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_InitLauncherInterface(void)

{
  gHasMMXTechnology = 1;
  VID_FlipScreen = Sys_VID_FlipScreen;
  D_SurfaceCacheForRes = Sys_GetSurfaceCacheSize;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_InitMemory  @ 000e69c0
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
                    /* WARNING: Subroutine does not return */
        Sys_Error("Available memory less than 15MB!!! %i\n",host_parms.memsize);
      }
      if (uVar6 < 0x7fffffff) {
        uVar2 = (ulonglong)((longlong)lVar5 * (longlong)lVar4) >> 1;
        host_parms.memsize = (int)uVar2;
        if (((int)(uVar2 >> 0x20) == 0) && ((uint)host_parms.memsize < 0xe00000)) {
          host_parms.memsize = 0xe00000;
          goto LAB_000e6a11;
        }
        goto LAB_000e69fe;
      }
    }
    host_parms.memsize = 0x8000000;
  }
LAB_000e69fe:
  if (0x8000000 < host_parms.memsize) {
    host_parms.memsize = 0x8000000;
  }
LAB_000e6a11:
  iVar3 = COM_CheckParm("-minmemory");
  if (iVar3 != 0) {
    host_parms.memsize = 0xe00000;
  }
  iVar3 = host_parms.memsize;
  host_parms.membase = malloc(host_parms.memsize);
  if (host_parms.membase != (void *)0x0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Unable to allocate %.2f MB\n",(double)((float)iVar3 * 9.536743e-07));
}


// Sys_IsWin95  @ 000e6860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin95(void)

{
  return g_bIsWin95;
}


// Sys_IsWin98  @ 000e6870
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Sys_IsWin98(void)

{
  return g_bIsWin98;
}


// Sys_LoadModule  @ 001cf650
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
    __snprintf_chk(local_410,0x400,1,0x400,&LAB_0025bece_4,local_810,pModuleName);
    pCVar4 = (CSysModule *)dlopen(local_410,2);
  }
  if (pCVar4 == (CSysModule *)0x0) {
                    /* Unresolved local var: char[512] str@[???] */
    uVar5 = dlerror();
    __printf_chk(1,"Error:%s\n",uVar5);
    __snprintf_chk(local_410,0x200,1,0x200,"%s.so",local_c10);
    pCVar4 = (CSysModule *)dlopen(local_410,2);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pCVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Sys_MakeCodeWriteable  @ 000e4580
void Sys_MakeCodeWriteable(uint32 startaddr,uint32 length)

{
  return;
}


// Sys_PageIn  @ 000e4280
void Sys_PageIn(void *ptr,int size)

{
  return;
}


// Sys_PopFPCW  @ 000e45b0
void Sys_PopFPCW(void)

{
  return;
}


// Sys_Printf  @ 000e46a0
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
    __fprintf_chk(_stderr,1,0x25dcd4,local_410);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Sys_PushFPCW_SetHigh  @ 000e45a0
void Sys_PushFPCW_SetHigh(void)

{
  return;
}


// Sys_Quit  @ 000e49e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Quit(void)

{
  giActive = 3;
  return;
}


// Sys_SetFPCW  @ 000e4590
void Sys_SetFPCW(void)

{
  return;
}


// Sys_SetupLegacyAPIs  @ 000e6830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_SetupLegacyAPIs(void)

{
  VID_FlipScreen = Sys_VID_FlipScreen;
  D_SurfaceCacheForRes = Sys_GetSurfaceCacheSize;
  Launcher_ConsolePrintf = Legacy_Sys_Printf;
  return;
}


// Sys_ShowProgressTicks  @ 000e6c30
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
            __strcat_chk(local_90,&DAT_0027b606,0x80);
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


// Sys_Shutdown  @ 000e68a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_Shutdown(void)

{
  Sys_ShutdownFloatTime();
  Steam_ShutdownClient();
  GL_Shutdown(*pmainwindow,maindc,baseRC);
  return;
}


// Sys_ShutdownArgv  @ 000e69b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_ShutdownArgv() */

void Sys_ShutdownArgv(void)

{
  return;
}


// Sys_ShutdownAuthentication  @ 000e6c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownAuthentication(void)

{
  return;
}


// Sys_ShutdownFloatTime  @ 000e4ad0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownFloatTime(void)

{
  curtime = 0.0;
  return;
}


// Sys_ShutdownGame  @ 000e70c0
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


// Sys_ShutdownLauncherInterface  @ 000e6bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Sys_ShutdownLauncherInterface() */

void Sys_ShutdownLauncherInterface(void)

{
  return;
}


// Sys_ShutdownMemory  @ 000e6b90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_ShutdownMemory(void)

{
  free(host_parms.membase);
  host_parms.membase = (void *)0x0;
  host_parms.memsize = 0;
  return;
}


// Sys_Sleep  @ 000e4650
void Sys_Sleep(int msec)

{
  usleep(msec * 1000);
  return;
}


// Sys_SplitPath  @ 000e5db0
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
LAB_000e5dd9:
      *drive = '\0';
      cVar2 = *path;
      goto LAB_000e5de0;
    }
LAB_000e5ef8:
    __src = path;
    if (dir == (char *)0x0) goto LAB_000e5f20;
    bVar3 = false;
    __src_00 = (char *)0x0;
LAB_000e5f08:
    *dir = '\0';
    if (bVar3) goto LAB_000e5e78;
  }
  else {
    if (path[1] == ':') {
      if (drive != (char *)0x0) {
        strncpy(drive,path,2);
        drive[2] = '\0';
      }
      cVar2 = path[2];
      path = path + 2;
LAB_000e5de0:
      __src = path;
      if (cVar2 == '\0') goto LAB_000e5ef8;
    }
    else {
      __src = path;
      if (drive != (char *)0x0) goto LAB_000e5dd9;
    }
    __src_00 = (char *)0x0;
    pcVar1 = __src + 1;
    pcVar5 = (char *)0x0;
    do {
      while ((path = pcVar1, cVar2 == '/' || (cVar2 == '\\'))) {
        cVar2 = *path;
        pcVar1 = path + 1;
        pcVar5 = path;
        if (cVar2 == '\0') goto LAB_000e5e1e;
      }
      bVar3 = cVar2 == '.';
      cVar2 = *path;
      if (bVar3) {
        __src_00 = path + -1;
      }
      pcVar1 = path + 1;
    } while (cVar2 != '\0');
LAB_000e5e1e:
    if (pcVar5 == (char *)0x0) {
      bVar3 = __src_00 != (char *)0x0 && __src <= __src_00;
      if (dir != (char *)0x0) goto LAB_000e5f08;
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
LAB_000e5e78:
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
LAB_000e5f20:
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


// Sys_UnloadModule  @ 001cf800
void Sys_UnloadModule(CSysModule *pModule)

{
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule != (CSysModule *)0x0) {
    dlclose();
    return;
  }
  return;
}


// Sys_VID_FlipScreen  @ 000e5ff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Sys_VID_FlipScreen(void)

{
  if (pmainwindow != (HWND *)0x0) {
    SDL_GL_SwapWindow(*pmainwindow);
  }
  return;
}


// Sys_Warning  @ 000e4960
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


