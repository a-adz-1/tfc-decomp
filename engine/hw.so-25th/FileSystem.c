// FileSystem_AddFallbackGameDir  @ 000aef40
int FileSystem_AddFallbackGameDir(char *pGameDir)

{
  int *piVar1;
  undefined4 *puVar2;
  char *__src;
  int iVar3;
  int in_GS_OFFSET;
  char local_1090 [128];
  undefined1 local_1010 [4095];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[128] language@[???]
                       Unresolved local var: char * pchLang@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1090[0] = '\0';
  piVar1 = (int *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
  if (*piVar1 != 0) {
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
    __src = (char *)(**(code **)(*(int *)*puVar2 + 0x10))((int *)*puVar2);
    if (__src != (char *)0x0) {
      strncpy(local_1090,__src,0x80);
      goto LAB_000aefb0;
    }
  }
  strncpy(local_1090,"english",0x80);
LAB_000aefb0:
  if (local_1090[0] != '\0') {
    iVar3 = strcasecmp(local_1090,"english");
    if (iVar3 != 0) {
                    /* Unresolved local var: char[4096] temp@[???] */
      __snprintf_chk(local_1010,0x1000,1,0x1000,&LAB_002577cb_4,s_pBaseDir,pGameDir,local_1090);
      local_11 = 0;
      (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1010,&LAB_002578aa);
    }
  }
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,pGameDir,&LAB_002578aa);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// FileSystem_Init  @ 000af0b0
int FileSystem_Init(char *basedir,void *voidfilesystemFactory)

{
  qboolean qVar1;
  
                    /* Unresolved local var: CreateInterfaceFn filesystemFactory@[???] */
  __strcpy_chk(s_pBaseDir,basedir,0x200);
                    /* Unresolved local var: char * fsmodule@[???] */
  host_parms.basedir = s_pBaseDir;
  if (((voidfilesystemFactory != (void *)0x0) ||
      ((g_pFileSystemModule = Sys_LoadModule("filesystem_stdio.so"),
       g_pFileSystemModule != (CSysModule *)0x0 &&
       (voidfilesystemFactory = Sys_GetFactory(g_pFileSystemModule),
       g_FileSystemFactory = voidfilesystemFactory, voidfilesystemFactory != (CreateInterfaceFn)0x0)
       ))) && (g_FileSystemFactory = voidfilesystemFactory,
              g_pFileSystem = (*voidfilesystemFactory)("VFileSystem009",(int *)0x0),
              g_pFileSystem != (IFileSystem *)0x0)) {
    qVar1 = COM_SetupDirectories();
    return (uint)(qVar1 != false);
  }
  return 0;
}


// FileSystem_SetGameDirectory  @ 000af880
int FileSystem_SetGameDirectory(char *pDefaultDir,char *pGameDir)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  qboolean qVar7;
  int in_GS_OFFSET;
  int local_12b4;
  char local_12a0 [128];
  char local_1220 [511];
  undefined1 local_1021;
  char local_1020 [4095];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[512] temp@[???]
                       Unresolved local var: bool writeset@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: char[128] language@[???]
                       Unresolved local var: char * pchLang@[???]
                       Unresolved local var: bool bEnableHDPack@[???]
                       Unresolved local var: bool bLanguage@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (**(code **)(*(int *)g_pFileSystem + 0x10))(g_pFileSystem);
  local_12a0[0] = '\0';
  if (((bLowViolenceBuild == false) &&
      (piVar3 = (int *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext),
      *piVar3 != 0)) && (iVar6 = GetGameAppID(), iVar6 == 0x46)) {
    puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
    bLowViolenceBuild = (bool)(**(code **)(*(int *)*puVar4 + 4))((int *)*puVar4);
  }
  piVar3 = (int *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
  if (*piVar3 == 0) {
LAB_000afd60:
    strncpy(local_12a0,"english",0x80);
  }
  else {
    puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
    pcVar5 = (char *)(**(code **)(*(int *)*puVar4 + 0x10))((int *)*puVar4);
    if (pcVar5 == (char *)0x0) goto LAB_000afd60;
    strncpy(local_12a0,pcVar5,0x80);
  }
  if (g_bIsDedicatedServer == false) {
    qVar7 = IsGameSubscribed(pGameDir);
    iVar6 = 0;
    if (qVar7 == false) goto LAB_000afd41;
  }
  iVar6 = GetGameAppID();
  SteamAPI_SetBreakpadAppID(iVar6);
  iVar6 = COM_CheckParm("-nohdmodels");
  bVar1 = false;
  if (iVar6 == 0) {
    iVar6 = (*registry->_vptr_IRegistry[2])(registry,0x2577b6,0);
    bVar1 = 0 < iVar6;
  }
  if (local_12a0[0] == '\0') {
    local_12b4 = 0;
    bVar2 = false;
  }
  else {
    local_12b4 = strcasecmp(local_12a0,"english");
    bVar2 = false;
    if (local_12b4 != 0) {
      local_12b4 = 1;
      bVar2 = true;
    }
  }
  if ((pGameDir != (char *)0x0) || (pGameDir = pDefaultDir, pDefaultDir != (char *)0x0)) {
    if (bLowViolenceBuild != false) {
      __snprintf_chk(local_1220,0x1ff,1,0x200,&LAB_0025781a,s_pBaseDir,pGameDir);
      local_1021 = 0;
      COM_FixSlashes(local_1220);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,&LAB_002578aa);
    }
    iVar6 = COM_CheckParm("-addons");
    if ((iVar6 != 0) || (iVar6 = (*registry->_vptr_IRegistry[2])(registry,0x258ec0,0), 0 < iVar6)) {
      __snprintf_chk(local_1220,0x1ff,1,0x200,0x257831,s_pBaseDir,pGameDir);
      local_1021 = 0;
      COM_FixSlashes(local_1220);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,&LAB_002578aa);
    }
    if (bVar2) {
      __snprintf_chk(local_1220,0x1ff,1,0x200,&LAB_002577cb_4,s_pBaseDir,pGameDir,local_12a0);
      local_1021 = 0;
      COM_FixSlashes(local_1220);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,&LAB_002578aa);
      iVar6 = COM_CheckParm("-steam");
      if (iVar6 == 0) {
                    /* Unresolved local var: char[4096] baseDir@[???]
                       Unresolved local var: char * tempPtr@[???] */
        Q_strncpy(local_1020,s_pBaseDir,0xfff);
        local_21 = 0;
        pcVar5 = Q_strstr(local_1020,"\\game");
        if (pcVar5 != (char *)0x0) {
          *pcVar5 = '\0';
          __snprintf_chk(local_1220,0x1ff,1,0x200,0x25784a,local_1020,pGameDir,local_12a0);
          local_1021 = 0;
          COM_FixSlashes(local_1220);
          (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,&LAB_002578aa);
        }
      }
    }
    if (bVar1) {
      __snprintf_chk(local_1220,0x1ff,1,0x200,0x257860,s_pBaseDir,pGameDir);
      local_1021 = 0;
      COM_FixSlashes(local_1220);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,&LAB_002578aa);
    }
    __snprintf_chk(local_1220,0x1ff,1,0x200,&LAB_0025bece_4,s_pBaseDir,pGameDir);
    local_1021 = 0;
    COM_FixSlashes(local_1220);
    (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1220,&LAB_002578aa);
    (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1220,0x25569c);
    __snprintf_chk(local_1220,0x1ff,1,0x200,&LAB_00257886,s_pBaseDir,pGameDir);
    local_1021 = 0;
    COM_FixSlashes(local_1220);
    (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1220,&LAB_00257896);
    CheckLiblistForFallbackDir(pGameDir,SUB41(local_12b4,0),local_12a0,bLowViolenceBuild);
  }
  if (bVar2) {
    if (bLowViolenceBuild != false) {
      __snprintf_chk(local_1220,0x1ff,1,0x200,&LAB_0025781a,s_pBaseDir,pDefaultDir);
      local_1021 = 0;
      COM_FixSlashes(local_1220);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,0x2578a3);
    }
    iVar6 = COM_CheckParm("-addons");
    if ((iVar6 != 0) || (iVar6 = (*registry->_vptr_IRegistry[2])(registry,0x258ec0,0), 0 < iVar6)) {
      __snprintf_chk(local_1220,0x1ff,1,0x200,0x257831,s_pBaseDir,pDefaultDir);
      local_1021 = 0;
      COM_FixSlashes(local_1220);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,0x2578a3);
    }
    __snprintf_chk(local_1220,0x1ff,1,0x200,&LAB_002577cb_4,s_pBaseDir,pDefaultDir,local_12a0);
    local_1021 = 0;
    COM_FixSlashes(local_1220);
    (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,0x2578a3);
    iVar6 = COM_CheckParm("-steam");
    if (iVar6 == 0) {
                    /* Unresolved local var: char[4096] baseDir@[???]
                       Unresolved local var: char * tempPtr@[???] */
      Q_strncpy(local_1020,s_pBaseDir,0xfff);
      local_21 = 0;
      pcVar5 = Q_strstr(local_1020,"\\game");
      if (pcVar5 != (char *)0x0) {
        *pcVar5 = '\0';
        __snprintf_chk(local_1220,0x1ff,1,0x200,0x25784a,local_1020,pDefaultDir,local_12a0);
        local_1021 = 0;
        COM_FixSlashes(local_1220);
        (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,0x2578a3);
      }
    }
  }
  if (bVar1) {
    __snprintf_chk(local_1220,0x1ff,1,0x200,0x257860,s_pBaseDir,pDefaultDir);
    local_1021 = 0;
    COM_FixSlashes(local_1220);
    (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,0x2578a3);
  }
  snprintf(local_1220,0x1ff,"%s",s_pBaseDir);
  local_1021 = 0;
  COM_FixSlashes(local_1220);
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1220,0x2578af);
  __snprintf_chk(local_1220,0x1ff,1,0x200,&LAB_0025bece_4,s_pBaseDir,pDefaultDir);
  local_1021 = 0;
  COM_FixSlashes(local_1220);
  (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1220,0x2578a3);
  __snprintf_chk(local_1220,0x1ff,1,0x200,0x2578b4,s_pBaseDir);
  local_1021 = 0;
  COM_FixSlashes(local_1220);
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1220,&LAB_00255b05);
  iVar6 = 1;
LAB_000afd41:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// FileSystem_Shutdown  @ 000af150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FileSystem_Shutdown(void)

{
  (**(code **)(*(int *)g_pFileSystem + 0x10))(g_pFileSystem);
  if (g_pFileSystemModule != (CSysModule *)0x0) {
    Sys_UnloadModule(g_pFileSystemModule);
    g_pFileSystemModule = (CSysModule *)0x0;
  }
  return;
}


