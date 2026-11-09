// FS_AddSearchPath  @ 0004a8a0
void FS_AddSearchPath(char *pPath,char *pathID)

{
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,pPath,pathID);
  return;
}


// FS_Close  @ 0004a9f0
void FS_Close(FileHandle_t file)

{
  (**(code **)(*(int *)g_pFileSystem + 0x30))(g_pFileSystem,file);
  return;
}


// FS_CreateDirHierarchy  @ 0004a920
void FS_CreateDirHierarchy(char *path,char *pathID)

{
  (**(code **)(*(int *)g_pFileSystem + 0x20))(g_pFileSystem,path,pathID);
  return;
}


// FS_EndOfFile  @ 0004ab30
int FS_EndOfFile(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x54))(g_pFileSystem,file);
  return uVar1 & 0xff;
}


// FS_FPrintf  @ 0004abc0
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
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 100))(g_pFileSystem,file,&DAT_000d525e,local_2010);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// FS_FileExists  @ 0004a950
int FS_FileExists(char *pFileName)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x24))(g_pFileSystem,pFileName);
  return uVar1 & 0xff;
}


// FS_FileSize  @ 0004aa80
uint FS_FileSize(char *pFileName)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x40))(g_pFileSystem,pFileName);
  return uVar1;
}


// FS_FileTimeToString  @ 0004aac0
void FS_FileTimeToString(char *pStrip,int maxCharsIncludingTerminator,int32 fileTime)

{
  (**(code **)(*(int *)g_pFileSystem + 0x48))
            (g_pFileSystem,pStrip,maxCharsIncludingTerminator,fileTime);
  return;
}


// FS_FindClose  @ 0004acc0
void FS_FindClose(FileFindHandle_t handle)

{
  (**(code **)(*(int *)g_pFileSystem + 0x7c))(g_pFileSystem,handle);
  return;
}


// FS_FindFirst  @ 0004ac50
char * FS_FindFirst(char *pWildCard,FileFindHandle_t *pHandle,char *pathID)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x70))
                             (g_pFileSystem,pWildCard,pHandle,pathID);
  return pcVar1;
}


// FS_FindIsDirectory  @ 0004aca0
int FS_FindIsDirectory(FileFindHandle_t handle)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x78))(g_pFileSystem,handle);
  return uVar1 & 0xff;
}


// FS_FindNext  @ 0004ac80
char * FS_FindNext(FileFindHandle_t handle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x74))(g_pFileSystem,handle);
  return pcVar1;
}


// FS_Flush  @ 0004ab10
void FS_Flush(FileHandle_t file)

{
  (**(code **)(*(int *)g_pFileSystem + 0x50))(g_pFileSystem,file);
  return;
}


// FS_FullPathToRelativePath  @ 0004ad70
int FS_FullPathToRelativePath(char *pFullpath,char *pRelative)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x8c))(g_pFileSystem,pFullpath,pRelative);
  return uVar1 & 0xff;
}


// FS_GetCharacter  @ 0004ae30
uchar FS_GetCharacter(FileHandle_t f)

{
  uchar local_d [13];
  
                    /* Unresolved local var: uchar retval@[???] */
  (**(code **)(*(int *)g_pFileSystem + 0x58))(g_pFileSystem,local_d,1,f);
  return local_d[0];
}


// FS_GetCurrentDirectory  @ 0004ada0
int FS_GetCurrentDirectory(char *pDirectory,int maxlen)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x90))(g_pFileSystem,pDirectory,maxlen);
  return uVar1 & 0xff;
}


// FS_GetFileTime  @ 0004aaa0
int32 FS_GetFileTime(char *pFileName)

{
  int32 iVar1;
  
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0x44))(g_pFileSystem,pFileName);
  return iVar1;
}


// FS_GetInterfaceVersion  @ 0004aef0
void FS_GetInterfaceVersion(char *p,int maxlen)

{
  (**(code **)(*(int *)g_pFileSystem + 0xb8))(g_pFileSystem,p,maxlen);
  return;
}


// FS_GetLocalCopy  @ 0004ace0
void FS_GetLocalCopy(char *pFileName)

{
  (**(code **)(*(int *)g_pFileSystem + 0x80))(g_pFileSystem,pFileName);
  return;
}


// FS_GetLocalPath  @ 0004ad00
char * FS_GetLocalPath(char *pFileName,char *pLocalPath,int localPathBufferSize)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x84))
                             (g_pFileSystem,pFileName,pLocalPath,localPathBufferSize);
  return pcVar1;
}


// FS_GetReadBuffer  @ 0004af20
void * FS_GetReadBuffer(FileHandle_t file,int *outBufSize)

{
  void *pvVar1;
  
  pvVar1 = (void *)(**(code **)(*(int *)g_pFileSystem + 0x68))(g_pFileSystem,file,outBufSize,1);
  return pvVar1;
}


// FS_IsDirectory  @ 0004a970
int FS_IsDirectory(char *pFileName)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x28))(g_pFileSystem,pFileName);
  return uVar1 & 0xff;
}


// FS_IsOk  @ 0004aaf0
int FS_IsOk(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x4c))(g_pFileSystem,file);
  return uVar1 & 0xff;
}


// FS_LoadLibrary  @ 0004b0e0
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


// FS_LogLevelLoadFinished  @ 0004ae90
void FS_LogLevelLoadFinished(char *name)

{
  (**(code **)(*(int *)g_pFileSystem + 0xa4))(g_pFileSystem,name);
  return;
}


// FS_LogLevelLoadStarted  @ 0004ae70
void FS_LogLevelLoadStarted(char *name)

{
  (**(code **)(*(int *)g_pFileSystem + 0xa0))(g_pFileSystem,name);
  return;
}


// FS_Open  @ 0004a990
FileHandle_t FS_Open(char *pFileName,char *pOptions)

{
  FileHandle_t pvVar1;
  
  pvVar1 = (FileHandle_t)
           (**(code **)(*(int *)g_pFileSystem + 0x2c))(g_pFileSystem,pFileName,pOptions,0);
  return pvVar1;
}


// FS_OpenPathID  @ 0004a9c0
FileHandle_t FS_OpenPathID(char *pFileName,char *pOptions,char *pathID)

{
  FileHandle_t pvVar1;
  
  pvVar1 = (FileHandle_t)
           (**(code **)(*(int *)g_pFileSystem + 0x2c))(g_pFileSystem,pFileName,pOptions,pathID);
  return pvVar1;
}


// FS_ParseFile  @ 0004ad30
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


// FS_PrintOpenedFiles  @ 0004add0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FS_PrintOpenedFiles(void)

{
  (**(code **)(*(int *)g_pFileSystem + 0x94))(g_pFileSystem);
  return;
}


// FS_Read  @ 0004ab50
int FS_Read(void *pOutput,int size,int count,FileHandle_t file)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0004ab6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0x58))();
  return iVar1;
}


// FS_ReadLine  @ 0004ab90
char * FS_ReadLine(char *pOutput,int maxChars,FileHandle_t file)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(*(int *)g_pFileSystem + 0x60))(g_pFileSystem,pOutput,maxChars,file);
  return pcVar1;
}


// FS_ReleaseReadBuffer  @ 0004af50
void FS_ReleaseReadBuffer(FileHandle_t file,void *buffer)

{
  (**(code **)(*(int *)g_pFileSystem + 0x6c))(g_pFileSystem,file,buffer);
  return;
}


// FS_RemoveAllSearchPaths  @ 0004a880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FS_RemoveAllSearchPaths(void)

{
  (**(code **)(*(int *)g_pFileSystem + 0x10))(g_pFileSystem);
  return;
}


// FS_RemoveFile  @ 0004a8f0
void FS_RemoveFile(char *pRelativePath,char *pathID)

{
  (**(code **)(*(int *)g_pFileSystem + 0x1c))(g_pFileSystem,pRelativePath,pathID);
  return;
}


// FS_RemoveSearchPath  @ 0004a8d0
int FS_RemoveSearchPath(char *pPath)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x18))(g_pFileSystem,pPath);
  return uVar1 & 0xff;
}


// FS_Rename  @ 0004aff0
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


// FS_Seek  @ 0004aa10
void FS_Seek(FileHandle_t file,int pos,FileSystemSeek_t seekType)

{
  (**(code **)(*(int *)g_pFileSystem + 0x34))(g_pFileSystem,file,pos,seekType);
  return;
}


// FS_SetVBuf  @ 0004aeb0
int FS_SetVBuf(FileHandle_t stream,char *buffer,int mode,size_t size)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0xb4))(g_pFileSystem,stream,buffer,mode,size);
  return iVar1;
}


// FS_SetWarningFunc  @ 0004adf0
void FS_SetWarningFunc(_func_void_char_ptr_varargs *pfnWarning)

{
  (**(code **)(*(int *)g_pFileSystem + 0x98))(g_pFileSystem,pfnWarning);
  return;
}


// FS_SetWarningLevel  @ 0004ae10
void FS_SetWarningLevel(FileWarningLevel_t level)

{
  (**(code **)(*(int *)g_pFileSystem + 0x9c))(g_pFileSystem,level);
  return;
}


// FS_Size  @ 0004aa60
uint FS_Size(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x3c))(g_pFileSystem,file);
  return uVar1;
}


// FS_Tell  @ 0004aa40
uint FS_Tell(FileHandle_t file)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)g_pFileSystem + 0x38))(g_pFileSystem,file);
  return uVar1;
}


// FS_Unlink  @ 0004af80
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


// FS_Write  @ 0004ab70
int FS_Write(void *pInput,int size,int count,FileHandle_t file)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0004ab8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*(int *)g_pFileSystem + 0x5c))();
  return iVar1;
}


