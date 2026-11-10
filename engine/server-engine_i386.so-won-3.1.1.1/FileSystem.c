// FileSystem_Init__FPcPv  @ 00065d00
bool FileSystem_Init__FPcPv(char *param_1,undefined4 param_2)

{
  char cVar1;
  
  strcpy(s_pBaseDir,param_1);
  host_parms = s_pBaseDir;
  cVar1 = FileSystem_LoadDLL__FPFPCcPi_P14IBaseInterface(param_2);
  if (cVar1 != '\0') {
    COM_SetupDirectories();
  }
  return cVar1 != '\0';
}


// FileSystem_LoadDLL__FPFPCcPi_P14IBaseInterface  @ 00065934
undefined * FileSystem_LoadDLL__FPFPCcPi_P14IBaseInterface(code *param_1)

{
  int iVar1;
  undefined *puVar2;
  char *local_8;
  undefined4 *puVar3;
  
  local_8 = "filesystem_stdio_i386.so";
  iVar1 = COM_CheckParm("-steam");
  if (iVar1 != 0) {
    local_8 = "filesystem_steam_i386.so";
  }
  if (param_1 == (code *)0x0) {
    g_pFileSystemModule = Sys_LoadModule__FPCc(local_8);
    if (g_pFileSystemModule == 0) {
      return (undefined *)0x0;
    }
    g_FileSystemFactory = (code *)Sys_GetFactory__FP10CSysModule(g_pFileSystemModule);
    if (g_FileSystemFactory == (code *)0x0) {
      return g_EntityDataDefinition + 0x270;
    }
  }
  else {
    g_FileSystemFactory = param_1;
  }
  g_pFileSystem = (*g_FileSystemFactory)("VFileSystem007",0);
  g_pFileSystemMemoryCache = (*g_FileSystemFactory)("FileSystemMemoryCache001",0);
  puVar3 = &g_pFileSystem;
  if ((g_pFileSystem == 0) || (puVar3 = &g_pFileSystemMemoryCache, g_pFileSystemMemoryCache == 0)) {
    puVar2 = (undefined *)((uint)puVar3 & 0xffffff00);
  }
  else {
    puVar2 = &DAT_00115001;
  }
  return puVar2;
}


// FileSystem_SetGameDirectory  @ 00065ac0
undefined4 FileSystem_SetGameDirectory(char *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  char local_288 [131];
  undefined1 local_205;
  char local_204 [512];
  
  local_205 = 0;
  (**(code **)(*g_pFileSystem + 0x14))(g_pFileSystem);
  local_288[0] = '\0';
  sVar1 = strlen(local_288);
  if (sVar1 != 0) {
    iVar2 = strcasecmp(local_288,"english");
    if (iVar2 != 0) {
      if (param_2 != (char *)0x0) {
        iVar2 = strcasecmp(param_2,param_1);
        if (iVar2 != 0) {
          uVar3 = GetBaseDirectory__Fv(param_2,local_288);
          sprintf(local_204,"%s/%s_%s",uVar3);
          (**(code **)(*g_pFileSystem + 0x18))(g_pFileSystem,local_204,&DAT_000e1ee1);
        }
      }
      uVar3 = GetBaseDirectory__Fv(param_1,local_288);
      sprintf(local_204,"%s/%s_%s",uVar3);
      (**(code **)(*g_pFileSystem + 0x18))(g_pFileSystem,local_204,"DEFAULTGAME");
    }
  }
  if (param_2 != (char *)0x0) {
    iVar2 = strcasecmp(param_2,param_1);
    if (iVar2 != 0) {
      uVar3 = GetBaseDirectory__Fv(param_2);
      sprintf(local_204,"%s/%s",uVar3);
      (**(code **)(*g_pFileSystem + 0x18))(g_pFileSystem,local_204,&DAT_000e1ee1);
    }
  }
  uVar3 = GetBaseDirectory__Fv(param_1);
  sprintf(local_204,"%s/%s",uVar3);
  (**(code **)(*g_pFileSystem + 0x18))(g_pFileSystem,local_204,"DEFAULTGAME");
  return 1;
}


// FileSystem_Shutdown__Fv  @ 00065d74
void FileSystem_Shutdown__Fv(void)

{
  (**(code **)(*g_pFileSystem + 0x14))(g_pFileSystem);
  FileSystem_UnloadDLL__Fv();
  return;
}


// FileSystem_UnloadDLL__Fv  @ 00065a78
void FileSystem_UnloadDLL__Fv(void)

{
  if (g_pFileSystemModule != 0) {
    Sys_UnloadModule__FP10CSysModule(g_pFileSystemModule);
    g_pFileSystemModule = 0;
  }
  return;
}


