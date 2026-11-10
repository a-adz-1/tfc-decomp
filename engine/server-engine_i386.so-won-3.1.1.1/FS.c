// FS_AddSearchPath  @ 0006465c
void FS_AddSearchPath(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*g_pFileSystem + 0x18))(g_pFileSystem,param_1,param_2);
  return;
}


// FS_CancelWaitForResources  @ 0006559c
void FS_CancelWaitForResources(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 200))(g_pFileSystem,param_1);
  return;
}


// FS_Close  @ 000648e4
void FS_Close(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0x34))(g_pFileSystem,param_1);
  return;
}


// FS_CreateDirHierarchy  @ 00064748
void FS_CreateDirHierarchy(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*g_pFileSystem + 0x24))(g_pFileSystem,param_1,param_2);
  return;
}


// FS_EndOfFile  @ 00064b58
undefined1 FS_EndOfFile(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x54))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_FPrintf  @ 00064ca8
undefined4 FS_FPrintf(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  char local_2004 [8192];
  
  vsprintf(local_2004,param_2,&stack0x0000000c);
  uVar1 = (**(code **)(*g_pFileSystem + 100))(g_pFileSystem,param_1,local_2004);
  return uVar1;
}


// FS_FileExists  @ 00064794
undefined1 FS_FileExists(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x28))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_FileTimeToString  @ 00064a6c
void FS_FileTimeToString(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*g_pFileSystem + 0x48))(g_pFileSystem,param_1,param_2,param_3);
  return;
}


// FS_FindClose  @ 00064e20
void FS_FindClose(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0x7c))(g_pFileSystem,param_1);
  return;
}


// FS_FindFirst  @ 00064d28
undefined4 FS_FindFirst(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x70))(g_pFileSystem,param_1,param_2);
  return uVar1;
}


// FS_FindIsDirectory  @ 00064dcc
undefined1 FS_FindIsDirectory(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x78))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_FindNext  @ 00064d7c
undefined4 FS_FindNext(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x74))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_Flush  @ 00064b10
void FS_Flush(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0x50))(g_pFileSystem,param_1);
  return;
}


// FS_FullPathToRelativePath  @ 00064f7c
undefined1 FS_FullPathToRelativePath(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x8c))(g_pFileSystem,param_1,param_2);
  return uVar1;
}


// FS_GetCharacter  @ 000650ec
undefined1 FS_GetCharacter(undefined4 param_1)

{
  undefined1 local_5;
  
  FS_Read(&local_5,1,1,param_1);
  return local_5;
}


// FS_GetCurrentDirectory  @ 00064fd0
undefined1 FS_GetCurrentDirectory(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x90))(g_pFileSystem,param_1,param_2);
  return uVar1;
}


// FS_GetFileTime  @ 00064a1c
undefined4 FS_GetFileTime(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x44))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_GetInterfaceVersion  @ 000652e4
void FS_GetInterfaceVersion(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*g_pFileSystem + 0xb8))(g_pFileSystem,param_1,param_2);
  return;
}


// FS_GetLocalCopy  @ 00064e68
void FS_GetLocalCopy(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0x80))(g_pFileSystem,param_1);
  return;
}


// FS_GetLocalPath  @ 00064eb0
undefined4 FS_GetLocalPath(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x84))(g_pFileSystem,param_1,param_2,param_3);
  return uVar1;
}


// FS_GetReadBuffer  @ 0006532c
undefined4 FS_GetReadBuffer(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x68))(g_pFileSystem,param_1,param_2,0x60001);
  return uVar1;
}


// FS_GetWaitForResourcesProgress  @ 0006552c
undefined1 FS_GetWaitForResourcesProgress(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  undefined1 uVar1;
  byte local_5;
  
  local_5 = 0;
  uVar1 = (**(code **)(*g_pFileSystem + 0xc4))(g_pFileSystem,param_1,param_2,&local_5);
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)local_5;
  }
  return uVar1;
}


// FS_HintResourceNeed  @ 000651ac
undefined4 FS_HintResourceNeed(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0xa8))(g_pFileSystem,param_1,param_2);
  return uVar1;
}


// FS_IsDirectory  @ 000647e8
undefined1 FS_IsDirectory(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x2c))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_IsOk  @ 00064abc
undefined1 FS_IsOk(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x4c))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_LoadLibrary  @ 00065894
undefined4 FS_LoadLibrary(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    FS_GetLocalCopy(param_1);
    uVar1 = dlopen(param_1,2);
  }
  return uVar1;
}


// FS_LogLevelLoadFinished  @ 00065168
void FS_LogLevelLoadFinished(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0xa4))(g_pFileSystem,param_1);
  return;
}


// FS_LogLevelLoadStarted  @ 00065124
void FS_LogLevelLoadStarted(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0xa0))(g_pFileSystem,param_1);
  return;
}


// FS_Open  @ 0006483c
undefined4 FS_Open(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x30))(g_pFileSystem,param_1,param_2,0);
  return uVar1;
}


// FS_OpenPathID  @ 00064890
undefined4 FS_OpenPathID(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x30))(g_pFileSystem,param_1,param_2,param_3);
  return uVar1;
}


// FS_ParseFile  @ 00064f08
undefined4 FS_ParseFile(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  char local_5;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x88))(g_pFileSystem,param_1,param_2,&local_5);
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)(local_5 != '\0');
  }
  return uVar1;
}


// FS_PauseResourcePreloading  @ 00065244
undefined4 FS_PauseResourcePreloading(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0xac))(g_pFileSystem);
  return uVar1;
}


// FS_PrintOpenedFiles  @ 00065024
void FS_PrintOpenedFiles(void)

{
  (**(code **)(*g_pFileSystem + 0x94))(g_pFileSystem);
  return;
}


// FS_Read  @ 00064bac
undefined4 FS_Read(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x58))(g_pFileSystem,param_1,param_2,param_4);
  return uVar1;
}


// FS_ReadLine  @ 00064c54
undefined4 FS_ReadLine(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x60))(g_pFileSystem,param_1,param_2,param_3);
  return uVar1;
}


// FS_ReleaseReadBuffer  @ 00065380
void FS_ReleaseReadBuffer(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*g_pFileSystem + 0x6c))(g_pFileSystem,param_1,param_2);
  return;
}


// FS_RemoveAllSearchPaths  @ 00064618
void FS_RemoveAllSearchPaths(void)

{
  (**(code **)(*g_pFileSystem + 0x14))(g_pFileSystem);
  return;
}


// FS_RemoveFile  @ 000646fc
void FS_RemoveFile(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*g_pFileSystem + 0x20))(g_pFileSystem,param_1,param_2);
  return;
}


// FS_RemoveSearchPath  @ 000646a8
undefined1 FS_RemoveSearchPath(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x1c))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_Rename  @ 00065420
void FS_Rename(char *param_1,char *param_2)

{
  char *pcVar1;
  char local_404 [512];
  char local_204 [512];
  
  FS_GetLocalPath(param_1,local_204,0x200,0x6542f);
  strcpy(local_404,local_204);
  pcVar1 = strstr(local_404,param_1);
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
    strcat(local_404,param_2);
    rename(local_204,local_404);
  }
  return;
}


// FS_ResumeResourcePreloading  @ 000651fc
undefined4 FS_ResumeResourcePreloading(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0xb0))(g_pFileSystem);
  return uVar1;
}


// FS_Seek  @ 0006492c
void FS_Seek(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*g_pFileSystem + 0x38))(g_pFileSystem,param_1,param_2,param_3);
  return;
}


// FS_SetVBuf  @ 0006528c
undefined4 FS_SetVBuf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0xb4))(g_pFileSystem,param_1,param_2,param_3,param_4);
  return uVar1;
}


// FS_SetWarningFunc  @ 00065064
void FS_SetWarningFunc(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0x98))(g_pFileSystem,param_1);
  return;
}


// FS_SetWarningLevel  @ 000650a8
void FS_SetWarningLevel(undefined4 param_1)

{
  (**(code **)(*g_pFileSystem + 0x9c))(g_pFileSystem,param_1);
  return;
}


// FS_Size  @ 000649cc
undefined4 FS_Size(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x40))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_Tell  @ 0006497c
undefined4 FS_Tell(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x3c))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_Unlink  @ 000653c8
void FS_Unlink(undefined4 param_1)

{
  char local_204 [512];
  
  FS_GetLocalPath(param_1,local_204,0x200,0x653d7);
  unlink(local_204);
  return;
}


// FS_WaitForResources  @ 000654e0
undefined4 FS_WaitForResources(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0xc0))(g_pFileSystem,param_1);
  return uVar1;
}


// FS_Write  @ 00064c00
undefined4 FS_Write(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*g_pFileSystem + 0x5c))(g_pFileSystem,param_1,param_2,param_4);
  return uVar1;
}


