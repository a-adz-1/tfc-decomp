// FileSystem_AddFallbackGameDir  @ 001190f0
int FileSystem_AddFallbackGameDir(char *pGameDir)

{
  int iVar1;
  int *piVar2;
  char *__src;
  char local_108c [4095];
  undefined1 local_8d;
  char local_8c [132];
  
                    /* Unresolved local var: char[128] language@[???]
                       Unresolved local var: char * pchLang@[???] */
  local_8c[0] = '\0';
  iVar1 = SteamApps();
  if (iVar1 != 0) {
    piVar2 = (int *)SteamApps();
    __src = (char *)(**(code **)(*piVar2 + 0x10))(piVar2);
    if (__src != (char *)0x0) {
      strncpy(local_8c,__src,0x80);
      goto LAB_00119146;
    }
  }
  strncpy(local_8c,"english",0x80);
LAB_00119146:
  if (local_8c[0] != '\0') {
    iVar1 = strcasecmp(local_8c,"english");
    if (iVar1 != 0) {
                    /* Unresolved local var: char[4096] temp@[???] */
      snprintf(local_108c,0x1000,"%s/%s_%s",s_pBaseDir,pGameDir,local_8c);
      local_8d = 0;
      (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_108c,"GAME");
    }
  }
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,pGameDir,"GAME");
  return 1;
}


// FileSystem_Init  @ 00119210
int FileSystem_Init(char *basedir,void *voidfilesystemFactory)

{
  qboolean qVar1;
  uint uVar2;
  
                    /* Unresolved local var: CreateInterfaceFn filesystemFactory@[???] */
  strcpy(s_pBaseDir,basedir);
                    /* Unresolved local var: char * fsmodule@[???] */
  host_parms.basedir = s_pBaseDir;
  if (voidfilesystemFactory == (void *)0x0) {
    g_pFileSystemModule = Sys_LoadModule("filesystem_stdio.so");
    if (g_pFileSystemModule == (CSysModule *)0x0) {
      return 0;
    }
    voidfilesystemFactory = Sys_GetFactory(g_pFileSystemModule);
    if (voidfilesystemFactory == (CreateInterfaceFn)0x0) {
      g_FileSystemFactory = voidfilesystemFactory;
      return 0;
    }
  }
  g_FileSystemFactory = voidfilesystemFactory;
  g_pFileSystem = (IFileSystem *)(*voidfilesystemFactory)("VFileSystem009",(int *)0x0);
  uVar2 = 0;
  if (g_pFileSystem != (IFileSystem *)0x0) {
    qVar1 = COM_SetupDirectories();
    uVar2 = (uint)(qVar1 != false);
  }
  return uVar2;
}


// FileSystem_SetGameDirectory  @ 001187e0
int FileSystem_SetGameDirectory(char *pDefaultDir,char *pGameDir)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  qboolean qVar5;
  char local_12bc;
  bool local_12a0;
  char local_129c [4095];
  undefined1 local_29d;
  char local_29c [511];
  undefined1 local_9d;
  char local_9c [140];
  
                    /* Unresolved local var: char[512] temp@[???]
                       Unresolved local var: bool writeset@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: char[128] language@[???]
                       Unresolved local var: char * pchLang@[???]
                       Unresolved local var: bool bEnableHDPack@[DW_OP_reg3(EBX)]
                       Unresolved local var: bool bLanguage@[???] */
  (**(code **)(*(int *)g_pFileSystem + 0x10))(g_pFileSystem);
  local_9c[0] = '\0';
  if (((bLowViolenceBuild == false) && (iVar2 = SteamApps(), iVar2 != 0)) &&
     (iVar2 = GetGameAppID(), iVar2 == 0x46)) {
    piVar3 = (int *)SteamApps();
    bLowViolenceBuild = (bool)(**(code **)(*piVar3 + 4))(piVar3);
  }
  iVar2 = SteamApps();
  if (iVar2 != 0) {
    piVar3 = (int *)SteamApps();
    pcVar4 = (char *)(**(code **)(*piVar3 + 0x10))(piVar3);
    if (pcVar4 != (char *)0x0) {
      strncpy(local_9c,pcVar4,0x80);
      goto LAB_00118852;
    }
  }
  strncpy(local_9c,"english",0x80);
LAB_00118852:
  if (g_bIsDedicatedServer == false) {
    qVar5 = IsGameSubscribed(pGameDir);
    if (qVar5 == false) {
      return 0;
    }
  }
  iVar2 = GetGameAppID();
  bVar1 = false;
  SteamAPI_SetBreakpadAppID(iVar2);
  iVar2 = COM_CheckParm("-nohdmodels");
  if (iVar2 == 0) {
    iVar2 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",1);
    bVar1 = 0 < iVar2;
  }
  if (local_9c[0] == '\0') {
    local_12a0 = false;
    local_12bc = '\0';
  }
  else {
    iVar2 = strcasecmp(local_9c,"english");
    local_12a0 = iVar2 != 0;
    local_12bc = '\x01' - (iVar2 == 0);
  }
  if ((pGameDir != (char *)0x0) || (pGameDir = pDefaultDir, pDefaultDir != (char *)0x0)) {
    if (bLowViolenceBuild != false) {
      snprintf(local_29c,0x1ff,"%s/%s_lv",s_pBaseDir,pGameDir);
      local_9d = 0;
      COM_FixSlashes(local_29c);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"GAME");
    }
    iVar2 = COM_CheckParm("-addons");
    if ((iVar2 != 0) ||
       (iVar2 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0), 0 < iVar2)) {
      snprintf(local_29c,0x1ff,"%s/%s_addon",s_pBaseDir,pGameDir);
      local_9d = 0;
      COM_FixSlashes(local_29c);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"GAME");
    }
    if (local_12bc != '\0') {
      snprintf(local_29c,0x1ff,"%s/%s_%s",s_pBaseDir,pGameDir,local_9c);
      local_9d = 0;
      COM_FixSlashes(local_29c);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"GAME");
      iVar2 = COM_CheckParm("-steam");
      if (iVar2 == 0) {
                    /* Unresolved local var: char[4096] baseDir@[???]
                       Unresolved local var: char * tempPtr@[???] */
        Q_strncpy(local_129c,s_pBaseDir,0xfff);
        local_29d = 0;
        pcVar4 = Q_strstr(local_129c,"\\game");
        if (pcVar4 != (char *)0x0) {
          *pcVar4 = '\0';
          snprintf(local_29c,0x1ff,"%s\\localization\\%s_%s",local_129c,pGameDir,local_9c);
          local_9d = 0;
          COM_FixSlashes(local_29c);
          (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"GAME");
        }
      }
    }
    if (bVar1) {
      snprintf(local_29c,0x1ff,"%s/%s_hd",s_pBaseDir,pGameDir);
      local_9d = 0;
      COM_FixSlashes(local_29c);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"GAME");
    }
    snprintf(local_29c,0x1ff,"%s/%s",s_pBaseDir,pGameDir);
    local_9d = 0;
    COM_FixSlashes(local_29c);
    (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_29c,"GAME");
    (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_29c,"GAMECONFIG");
    snprintf(local_29c,0x1ff,"%s/%s_downloads",s_pBaseDir,pGameDir);
    local_9d = 0;
    COM_FixSlashes(local_29c);
    (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_29c,"GAMEDOWNLOAD");
    CheckLiblistForFallbackDir(pGameDir,local_12a0,local_9c,bLowViolenceBuild);
  }
  if (local_12bc != '\0') {
    if (bLowViolenceBuild != false) {
      snprintf(local_29c,0x1ff,"%s/%s_lv",s_pBaseDir,pDefaultDir);
      local_9d = 0;
      COM_FixSlashes(local_29c);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"DEFAULTGAME");
    }
    iVar2 = COM_CheckParm("-addons");
    if ((iVar2 != 0) ||
       (iVar2 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0), 0 < iVar2)) {
      snprintf(local_29c,0x1ff,"%s/%s_addon",s_pBaseDir,pDefaultDir);
      local_9d = 0;
      COM_FixSlashes(local_29c);
      (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"DEFAULTGAME");
    }
    snprintf(local_29c,0x1ff,"%s/%s_%s",s_pBaseDir,pDefaultDir,local_9c);
    local_9d = 0;
    COM_FixSlashes(local_29c);
    (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"DEFAULTGAME");
    iVar2 = COM_CheckParm("-steam");
    if (iVar2 == 0) {
                    /* Unresolved local var: char[4096] baseDir@[???]
                       Unresolved local var: char * tempPtr@[???] */
      Q_strncpy(local_129c,s_pBaseDir,0xfff);
      local_29d = 0;
      pcVar4 = Q_strstr(local_129c,"\\game");
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
        snprintf(local_29c,0x1ff,"%s\\localization\\%s_%s",local_129c,pDefaultDir,local_9c);
        local_9d = 0;
        COM_FixSlashes(local_29c);
        (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"DEFAULTGAME");
      }
    }
  }
  if (bVar1) {
    snprintf(local_29c,0x1ff,"%s/%s_hd",s_pBaseDir,pDefaultDir);
    local_9d = 0;
    COM_FixSlashes(local_29c);
    (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"DEFAULTGAME");
  }
  snprintf(local_29c,0x1ff,"%s",s_pBaseDir);
  local_9d = 0;
  COM_FixSlashes(local_29c);
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_29c,&DAT_0027dc1a);
  snprintf(local_29c,0x1ff,"%s/%s",s_pBaseDir,pDefaultDir);
  local_9d = 0;
  COM_FixSlashes(local_29c);
  (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_29c,"DEFAULTGAME");
  snprintf(local_29c,0x1ff,"%s/platform",s_pBaseDir);
  local_9d = 0;
  COM_FixSlashes(local_29c);
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_29c,"PLATFORM");
  return 1;
}


// FileSystem_Shutdown  @ 001192a0
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


