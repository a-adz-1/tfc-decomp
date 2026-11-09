// FS_AddSearchPath  @ 000ae430
void FS_AddSearchPath(char *pPath,char *pathID)

{
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,pPath,pathID);
  return;
}


// FS_Close  @ 000ae580
void FS_Close(FileHandle_t file)

{
  (**(code **)(*(int *)g_pFileSystem + 0x30))(g_pFileSystem,file);
  return;
}


// FS_CreateDirHierarchy  @ 000ae4b0
void FS_CreateDirHierarchy(char *path,char *pathID)

{
  (**(code **)(*(int *)g_pFileSystem + 0x20))(g_pFileSystem,path,pathID);
  return;
}


// FS_EndOfFile  @ 000ae6c0
int FS_EndOfFile(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x54))(g_pFileSystem,file);
  return uVar1 & 0xff;
}


// FS_FPrintf  @ 000ae750
int FS_FPrintf(FileHandle_t file,char *pFormat,...)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined1 local_2010 [8192];
  int local_10;
  
                    /* Unresolved local var: char[8192] data@[???]
                       Unresolved local var: va_list argptr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsprintf_chk(local_2010,1,0x2000,pFormat,&stack0x0000000c);
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 100))(g_pFileSystem,file,0x264d1c,local_2010);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// FS_FileExists  @ 000ae4e0
int FS_FileExists(char *pFileName)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x24))(g_pFileSystem,pFileName);
  return uVar1 & 0xff;
}


// FS_FileSize  @ 000ae610
uint FS_FileSize(char *pFileName)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x40))(g_pFileSystem,pFileName);
  return uVar1;
}


// FS_FileTimeToString  @ 000ae650
void FS_FileTimeToString(char *pStrip,int maxCharsIncludingTerminator,int32 fileTime)

{
  (**(code **)(*(int *)g_pFileSystem + 0x48))
            (g_pFileSystem,pStrip,maxCharsIncludingTerminator,fileTime);
  return;
}


// FS_FindClose  @ 000ae850
void FS_FindClose(FileFindHandle_t handle)

{
  (**(code **)(*(int *)g_pFileSystem + 0x7c))(g_pFileSystem,handle);
  return;
}


// FS_FindFirst  @ 000ae7e0
char * FS_FindFirst(char *pWildCard,FileFindHandle_t *pHandle,char *pathID)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x70))
                             (g_pFileSystem,pWildCard,pHandle,pathID);
  return pcVar1;
}


// FS_FindIsDirectory  @ 000ae830
int FS_FindIsDirectory(FileFindHandle_t handle)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x78))(g_pFileSystem,handle);
  return uVar1 & 0xff;
}


// FS_FindNext  @ 000ae810
char * FS_FindNext(FileFindHandle_t handle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x74))(g_pFileSystem,handle);
  return pcVar1;
}


// FS_Flush  @ 000ae6a0
void FS_Flush(FileHandle_t file)

{
  (**(code **)(*(int *)g_pFileSystem + 0x50))(g_pFileSystem,file);
  return;
}


// FS_FullPathToRelativePath  @ 000ae900
int FS_FullPathToRelativePath(char *pFullpath,char *pRelative)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x8c))(g_pFileSystem,pFullpath,pRelative);
  return uVar1 & 0xff;
}


// FS_GetCharacter  @ 000ae9c0
uchar FS_GetCharacter(FileHandle_t f)

{
  uchar local_d [13];
  
                    /* Unresolved local var: uchar retval@[???] */
  (**(code **)(*(int *)g_pFileSystem + 0x58))(g_pFileSystem,local_d,1,f);
  return local_d[0];
}


// FS_GetCurrentDirectory  @ 000ae930
int FS_GetCurrentDirectory(char *pDirectory,int maxlen)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x90))(g_pFileSystem,pDirectory,maxlen);
  return uVar1 & 0xff;
}


// FS_GetFileTime  @ 000ae630
int32 FS_GetFileTime(char *pFileName)

{
  int32 iVar1;
  
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0x44))(g_pFileSystem,pFileName);
  return iVar1;
}


// FS_GetInterfaceVersion  @ 000aea80
void FS_GetInterfaceVersion(char *p,int maxlen)

{
  (**(code **)(*(int *)g_pFileSystem + 0xb8))(g_pFileSystem,p,maxlen);
  return;
}


// FS_GetLocalCopy  @ 000ae870
void FS_GetLocalCopy(char *pFileName)

{
  (**(code **)(*(int *)g_pFileSystem + 0x80))(g_pFileSystem,pFileName);
  return;
}


// FS_GetLocalPath  @ 000ae890
char * FS_GetLocalPath(char *pFileName,char *pLocalPath,int localPathBufferSize)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x84))
                             (g_pFileSystem,pFileName,pLocalPath,localPathBufferSize);
  return pcVar1;
}


// FS_GetReadBuffer  @ 000aeab0
void * FS_GetReadBuffer(FileHandle_t file,int *outBufSize)

{
  void *pvVar1;
  
  pvVar1 = (void *)(**(code **)(*(int *)g_pFileSystem + 0x68))(g_pFileSystem,file,outBufSize,1);
  return pvVar1;
}


// FS_IsDirectory  @ 000ae500
int FS_IsDirectory(char *pFileName)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x28))(g_pFileSystem,pFileName);
  return uVar1 & 0xff;
}


// FS_IsOk  @ 000ae680
int FS_IsOk(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x4c))(g_pFileSystem,file);
  return uVar1 & 0xff;
}


// FS_LoadLibrary  @ 000aec70
void * FS_LoadLibrary(char *dllName)

{
  void *pvVar1;
  
  if (dllName == (char *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    (**(code **)(*(int *)g_pFileSystem + 0x80))(g_pFileSystem,dllName);
    pvVar1 = (void *)dlopen(dllName,2);
  }
  return pvVar1;
}


// FS_LogLevelLoadFinished  @ 000aea20
void FS_LogLevelLoadFinished(char *name)

{
  (**(code **)(*(int *)g_pFileSystem + 0xa4))(g_pFileSystem,name);
  return;
}


// FS_LogLevelLoadStarted  @ 000aea00
void FS_LogLevelLoadStarted(char *name)

{
  (**(code **)(*(int *)g_pFileSystem + 0xa0))(g_pFileSystem,name);
  return;
}


// FS_Open  @ 000ae520
FileHandle_t FS_Open(char *pFileName,char *pOptions)

{
  FileHandle_t pvVar1;
  
  pvVar1 = (FileHandle_t)
           (**(code **)(*(int *)g_pFileSystem + 0x2c))(g_pFileSystem,pFileName,pOptions,0);
  return pvVar1;
}


// FS_OpenPathID  @ 000ae550
FileHandle_t FS_OpenPathID(char *pFileName,char *pOptions,char *pathID)

{
  FileHandle_t pvVar1;
  
  pvVar1 = (FileHandle_t)
           (**(code **)(*(int *)g_pFileSystem + 0x2c))(g_pFileSystem,pFileName,pOptions,pathID);
  return pvVar1;
}


// FS_ParseFile  @ 000ae8c0
char * FS_ParseFile(char *pFileBytes,char *pToken,int *pWasQuoted)

{
  char *pcVar1;
  byte local_d [9];
  
                    /* Unresolved local var: bool wasquoted@[???]
                       Unresolved local var: char * retval@[DW_OP_reg0(EAX)] */
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x88))
                             (g_pFileSystem,pFileBytes,pToken,local_d);
  if (pWasQuoted != (int *)0x0) {
    *pWasQuoted = (uint)local_d[0];
  }
  return pcVar1;
}


// FS_PrintOpenedFiles  @ 000ae960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FS_PrintOpenedFiles(void)

{
  (**(code **)(*(int *)g_pFileSystem + 0x94))(g_pFileSystem);
  return;
}


// FS_Read  @ 000ae6e0
int FS_Read(void *pOutput,int size,int count,FileHandle_t file)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000ae6fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0x58))();
  return iVar1;
}


// FS_ReadLine  @ 000ae720
char * FS_ReadLine(char *pOutput,int maxChars,FileHandle_t file)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x60))(g_pFileSystem,pOutput,maxChars,file);
  return pcVar1;
}


// FS_ReleaseReadBuffer  @ 000aeae0
void FS_ReleaseReadBuffer(FileHandle_t file,void *buffer)

{
  (**(code **)(*(int *)g_pFileSystem + 0x6c))(g_pFileSystem,file,buffer);
  return;
}


// FS_RemoveAllSearchPaths  @ 000ae410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FS_RemoveAllSearchPaths(void)

{
  (**(code **)(*(int *)g_pFileSystem + 0x10))(g_pFileSystem);
  return;
}


// FS_RemoveFile  @ 000ae480
void FS_RemoveFile(char *pRelativePath,char *pathID)

{
  (**(code **)(*(int *)g_pFileSystem + 0x1c))(g_pFileSystem,pRelativePath,pathID);
  return;
}


// FS_RemoveSearchPath  @ 000ae460
int FS_RemoveSearchPath(char *pPath)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x18))(g_pFileSystem,pPath);
  return uVar1 & 0xff;
}


// FS_Rename  @ 000aeb80
void FS_Rename(char *originalName,char *newName)

{
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char local_420 [512];
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char[512] localPath@[???]
                       Unresolved local var: char[512] newPath@[???]
                       Unresolved local var: char * cut@[???]
                       Unresolved local var: int res@[???]
                       Unresolved local var: char * path@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0x84))(g_pFileSystem,originalName,local_420,0x200);
  if (iVar1 != 0) {
    __strcpy_chk(local_220,local_420,0x200);
    pcVar2 = strstr(local_220,originalName);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
      __strcat_chk(local_220,newName,0x200);
      rename(local_420,local_220);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// FS_Seek  @ 000ae5a0
void FS_Seek(FileHandle_t file,int pos,FileSystemSeek_t seekType)

{
  (**(code **)(*(int *)g_pFileSystem + 0x34))(g_pFileSystem,file,pos,seekType);
  return;
}


// FS_SetVBuf  @ 000aea40
int FS_SetVBuf(FileHandle_t stream,char *buffer,int mode,size_t size)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0xb4))(g_pFileSystem,stream,buffer,mode,size);
  return iVar1;
}


// FS_SetWarningFunc  @ 000ae980
void FS_SetWarningFunc(_func_void_char_ptr_varargs *pfnWarning)

{
  (**(code **)(*(int *)g_pFileSystem + 0x98))(g_pFileSystem,pfnWarning);
  return;
}


// FS_SetWarningLevel  @ 000ae9a0
void FS_SetWarningLevel(FileWarningLevel_t level)

{
  (**(code **)(*(int *)g_pFileSystem + 0x9c))(g_pFileSystem,level);
  return;
}


// FS_Size  @ 000ae5f0
uint FS_Size(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x3c))(g_pFileSystem,file);
  return uVar1;
}


// FS_Tell  @ 000ae5d0
uint FS_Tell(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x38))(g_pFileSystem,file);
  return uVar1;
}


// FS_Unlink  @ 000aeb10
void FS_Unlink(char *filename)

{
  int in_GS_OFFSET;
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] localPath@[???]
                       Unresolved local var: int res@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  (**(code **)(*(int *)g_pFileSystem + 0x84))(g_pFileSystem,filename,local_210,0x200);
  unlink(local_210);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// FS_Write  @ 000ae700
int FS_Write(void *pInput,int size,int count,FileHandle_t file)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000ae71e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0x5c))();
  return iVar1;
}


