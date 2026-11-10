// Sys_CompareFileTime  @ 08087bd0
undefined4 Sys_CompareFileTime(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_1 < param_2) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 < param_1) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Sys_ConsoleInput  @ 08089dd0
undefined1 * Sys_ConsoleInput(void)

{
  ssize_t sVar1;
  int iVar2;
  undefined1 *puVar3;
  __fd_mask *p_Var4;
  char local_8d;
  timeval local_8c;
  byte local_84 [128];
  
  p_Var4 = (__fd_mask *)local_84;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *p_Var4 = 0;
    p_Var4 = p_Var4 + 1;
  }
  local_84[0] = local_84[0] | 1;
  local_8c.tv_sec = 0;
  local_8c.tv_usec = 0;
  iVar2 = select(1,(fd_set *)local_84,(fd_set *)0x0,(fd_set *)0x0,&local_8c);
  if ((iVar2 != -1) && ((local_84[0] & 1) != 0)) {
    while (sVar1 = read(0,&local_8d,1), sVar1 != 0) {
      if (local_8d == '\n') {
        puVar3 = (undefined1 *)0x0;
        szInput[iInput] = 0;
        if ('\0' < iInput) {
          puVar3 = szInput;
        }
        iInput = 0;
        return puVar3;
      }
      szInput[iInput] = local_8d;
      iInput = iInput + '\x01';
    }
  }
  return (undefined1 *)0x0;
}


// Sys_Error  @ 080880d0
void Sys_Error(char *param_1)

{
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  if (bReentry_164 != 0) {
    fprintf((FILE *)_IO_stderr_,"%s\n",local_404);
                    /* WARNING: Subroutine does not return */
    longjmp((__jmp_buf_tag *)host_abortserver,2);
  }
  bReentry_164 = 1;
  (*Console_Printf)("Error %s\n",local_404);
  Sys_Quit();
  return;
}


// Sys_FileClose  @ 08087ad0
void Sys_FileClose(int param_1)

{
  if (*(int *)(sys_handles + param_1 * 4) != 0) {
    fclose(*(FILE **)(sys_handles + param_1 * 4));
  }
  *(undefined4 *)(sys_handles + param_1 * 4) = 0;
  return;
}


// Sys_FileOpenAppend  @ 080879f0
int Sys_FileOpenAppend(char *param_1,int *param_2)

{
  int iVar1;
  FILE *pFVar2;
  int *piVar3;
  char *pcVar4;
  
  iVar1 = findhandle();
  pFVar2 = fopen(param_1,"wb");
  if (pFVar2 == (FILE *)0x0) {
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    Sys_Error("Error opening %s: %s",param_1,pcVar4);
    iVar1 = -1;
  }
  else {
    *(FILE **)(sys_handles + iVar1 * 4) = pFVar2;
    *param_2 = iVar1;
  }
  return iVar1;
}


// Sys_FileOpenRead  @ 08087990
undefined4 Sys_FileOpenRead(char *param_1,int *param_2)

{
  int iVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  
  iVar1 = findhandle();
  pFVar2 = fopen(param_1,"rb");
  if (pFVar2 == (FILE *)0x0) {
    *param_2 = -1;
    uVar3 = 0xffffffff;
  }
  else {
    *(FILE **)(sys_handles + iVar1 * 4) = pFVar2;
    *param_2 = iVar1;
    uVar3 = filelength(pFVar2);
  }
  return uVar3;
}


// Sys_FileOpenWrite  @ 08087a60
int Sys_FileOpenWrite(char *param_1)

{
  int iVar1;
  FILE *pFVar2;
  int *piVar3;
  char *pcVar4;
  
  iVar1 = findhandle();
  pFVar2 = fopen(param_1,"wb");
  if (pFVar2 == (FILE *)0x0) {
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    Sys_Error("Error opening %s: %s",param_1,pcVar4);
    iVar1 = -1;
  }
  else {
    *(FILE **)(sys_handles + iVar1 * 4) = pFVar2;
  }
  return iVar1;
}


// Sys_FileRead  @ 08087b40
void Sys_FileRead(int param_1,void *param_2,size_t param_3)

{
  fread(param_2,1,param_3,*(FILE **)(sys_handles + param_1 * 4));
  return;
}


// Sys_FileSeek  @ 08087b10
void Sys_FileSeek(int param_1,long param_2)

{
  fseek(*(FILE **)(sys_handles + param_1 * 4),param_2,0);
  return;
}


// Sys_FileTell  @ 08087c30
void Sys_FileTell(int param_1)

{
  ftell(*(FILE **)(sys_handles + param_1 * 4));
  return;
}


// Sys_FileTime  @ 08087ba0
__time_t Sys_FileTime(char *param_1)

{
  int iVar1;
  stat local_5c;
  
  iVar1 = __xstat(3,param_1,&local_5c);
  if (iVar1 == -1) {
    local_5c.st_mtim.tv_sec = -1;
  }
  return local_5c.st_mtim.tv_sec;
}


// Sys_FileWrite  @ 08087b70
void Sys_FileWrite(int param_1,void *param_2,size_t param_3)

{
  fwrite(param_2,1,param_3,*(FILE **)(sys_handles + param_1 * 4));
  return;
}


// Sys_FindClose  @ 08088040
void Sys_FindClose(void)

{
  if (fdir != (DIR *)0x0) {
    closedir(fdir);
  }
  fdir = (DIR *)0x0;
  return;
}


// Sys_FindFirst  @ 08087e60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * Sys_FindFirst(char *param_1,char *param_2)

{
  char *pcVar1;
  dirent *pdVar2;
  undefined1 *puVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  
  if (fdir != (DIR *)0x0) {
    Sys_Error("Sys_FindFirst without close");
  }
  strcpy(findbase,param_1);
  pcVar1 = strrchr(findbase,0x2f);
  if (pcVar1 == (char *)0x0) {
    _findpattern = 0x2a;
  }
  else {
    *pcVar1 = '\0';
    strcpy(&findpattern,pcVar1 + 1);
  }
  iVar4 = 4;
  bVar6 = true;
  pcVar1 = &findpattern;
  pcVar5 = "*.*";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar6 = *pcVar1 == *pcVar5;
    pcVar1 = pcVar1 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    _findpattern = 0x2a;
  }
  fdir = opendir(findbase);
  if (fdir == (DIR *)0x0) {
LAB_08087f98:
    puVar3 = (undefined1 *)0x0;
  }
  else {
    do {
      pdVar2 = readdir(fdir);
      if (pdVar2 == (dirent *)0x0) goto LAB_08087f98;
    } while ((findpattern != '\0') && (iVar4 = glob_match(&findpattern,pdVar2->d_name), iVar4 == 0))
    ;
    strcpy(findname,pdVar2->d_name);
    if (param_2 != (char *)0x0) {
      strcpy(param_2,findname);
    }
    sprintf(findpath,"%s/%s",findbase,pdVar2->d_name);
    puVar3 = findpath;
  }
  return puVar3;
}


// Sys_FindNext  @ 08087fb0
undefined1 * Sys_FindNext(char *param_1)

{
  int iVar1;
  dirent *pdVar2;
  undefined1 *puVar3;
  
  if (fdir == (DIR *)0x0) {
LAB_08088034:
    puVar3 = (undefined1 *)0x0;
  }
  else {
    do {
      pdVar2 = readdir(fdir);
      if (pdVar2 == (dirent *)0x0) goto LAB_08088034;
    } while ((findpattern != '\0') && (iVar1 = glob_match(&findpattern,pdVar2->d_name), iVar1 == 0))
    ;
    if (param_1 != (char *)0x0) {
      strcpy(param_1,findname);
    }
    sprintf(findpath,"%s/%s",findbase,pdVar2->d_name);
    puVar3 = findpath;
  }
  return puVar3;
}


// Sys_FloatTime  @ 080881b0
longdouble Sys_FloatTime(void)

{
  longdouble lVar1;
  timeval local_14;
  timezone local_c;
  
  gettimeofday(&local_14,&local_c);
  if (secbase_171 == 0) {
    secbase_171 = local_14.tv_sec;
    lVar1 = (longdouble)local_14.tv_usec / (longdouble)1000000.0;
  }
  else {
    lVar1 = (longdouble)local_14.tv_usec / (longdouble)1000000.0 +
            (longdouble)(local_14.tv_sec - secbase_171);
  }
  return lVar1;
}


// Sys_GetHandle  @ 08087920
undefined4 Sys_GetHandle(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 10) {
    uVar1 = *(undefined4 *)(sys_handles + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Sys_Init  @ 080880c0
void Sys_Init(void)

{
  return;
}


// Sys_MakeCodeWriteable  @ 08088070
void Sys_MakeCodeWriteable(void)

{
  return;
}


// Sys_PageIn  @ 080878e0
void Sys_PageIn(void)

{
  return;
}


// Sys_PopFPCW  @ 080880a0
void Sys_PopFPCW(void)

{
  return;
}


// Sys_Printf  @ 08089c10
void Sys_Printf(char *param_1)

{
  vprintf(param_1,&stack0x00000008);
  fflush((FILE *)_IO_stdout_);
  return;
}


// Sys_PushFPCW_SetHigh  @ 08088090
void Sys_PushFPCW_SetHigh(void)

{
  return;
}


// Sys_Quit  @ 08088190
void Sys_Quit(void)

{
  Host_Shutdown();
  giActive = 3;
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Sys_SendKeyEvents  @ 08088220
void Sys_SendKeyEvents(void)

{
  return;
}


// Sys_SetFPCW  @ 08088080
void Sys_SetFPCW(void)

{
  return;
}


// Sys_Sleep  @ 08088210
void Sys_Sleep(void)

{
  usleep(1);
  return;
}


// Sys_Unlink  @ 08087c50
void Sys_Unlink(char *param_1)

{
  unlink(param_1);
  return;
}


// Sys_Warning  @ 08088150
void Sys_Warning(char *param_1)

{
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  (*Console_Printf)("WARNING:  %s\n",local_404);
  giActive = 2;
  return;
}


// Sys_mkdir  @ 08087c10
void Sys_mkdir(char *param_1)

{
  mkdir(param_1,0x1f8);
  return;
}


