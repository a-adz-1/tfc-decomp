// Sys_CompareFileTime  @ 000925ec
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


// Sys_EngineAPI  @ 00094234
undefined4 Sys_EngineAPI(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_1 == 1) && (param_2 == 0xf0)) {
    uVar1 = 1;
    puVar3 = &engineapi;
    for (iVar2 = 0x3c; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_3 = *puVar3;
      puVar3 = puVar3 + 1;
      param_3 = param_3 + 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Sys_Error  @ 00092af0
void Sys_Error(char *param_1)

{
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  if (bReentry_74 != 0) {
    fprintf((FILE *)_IO_stderr_,"%s\n",local_404);
                    /* WARNING: Subroutine does not return */
    longjmp((__jmp_buf_tag *)host_abortserver,2);
  }
  bReentry_74 = 1;
  if ((svs != 0) && (DAT_003862a4 != (code *)0x0)) {
    (*DAT_003862a4)(local_404);
  }
  if (isDedicated != 0) {
    if (Launcher_ConsolePrintf != (code *)0x0) {
      (*Launcher_ConsolePrintf)("Error %s\n",local_404);
    }
    Sys_Sleep(5000);
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  if (Launcher_ErrorMessage != (code *)0x0) {
    (*Launcher_ErrorMessage)(0,local_404);
  }
  return;
}


// Sys_FileClose  @ 000924c0
void Sys_FileClose(int param_1)

{
  fclose(*(FILE **)(sys_handles + param_1 * 4));
  *(undefined4 *)(sys_handles + param_1 * 4) = 0;
  return;
}


// Sys_FileOpenAppend  @ 0009244c
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
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1;
  }
  return iVar1;
}


// Sys_FileOpenRead  @ 00092380
void Sys_FileOpenRead(char *param_1,int *param_2)

{
  int iVar1;
  FILE *pFVar2;
  
  iVar1 = findhandle();
  pFVar2 = fopen(param_1,"rb");
  if (pFVar2 == (FILE *)0x0) {
    iVar1 = -1;
  }
  else {
    *(FILE **)(sys_handles + iVar1 * 4) = pFVar2;
    filelength(pFVar2);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1;
  }
  return;
}


// Sys_FileOpenWrite  @ 000923e0
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


// Sys_FileRead  @ 00092538
void Sys_FileRead(int param_1,void *param_2,size_t param_3)

{
  fread(param_2,1,param_3,*(FILE **)(sys_handles + param_1 * 4));
  return;
}


// Sys_FileSeek  @ 00092500
void Sys_FileSeek(int param_1,long param_2)

{
  fseek(*(FILE **)(sys_handles + param_1 * 4),param_2,0);
  return;
}


// Sys_FileTell  @ 0009263c
void Sys_FileTell(int param_1)

{
  ftell(*(FILE **)(sys_handles + param_1 * 4));
  return;
}


// Sys_FileTime  @ 000925b8
int Sys_FileTime(char *param_1)

{
  int iVar1;
  stat local_5c;
  
  iVar1 = __xstat(3,param_1,&local_5c);
  if (iVar1 != -1) {
    iVar1 = local_5c.st_mtim.tv_sec;
  }
  return iVar1;
}


// Sys_FileWrite  @ 00092578
void Sys_FileWrite(int param_1,void *param_2,size_t param_3)

{
  fwrite(param_2,1,param_3,*(FILE **)(sys_handles + param_1 * 4));
  return;
}


// Sys_FindClose  @ 00092a5c
void Sys_FindClose(void)

{
  if (fdir != (DIR *)0x0) {
    closedir(fdir);
  }
  fdir = (DIR *)0x0;
  return;
}


// Sys_FindFirst  @ 00092880
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
LAB_000929ad:
    puVar3 = (undefined1 *)0x0;
  }
  else {
    do {
      pdVar2 = readdir(fdir);
      if (pdVar2 == (dirent *)0x0) goto LAB_000929ad;
    } while ((findpattern != '\0') && (iVar4 = glob_match(&findpattern,pdVar2->d_name), iVar4 == 0))
    ;
    strcpy(findname,pdVar2->d_name);
    if (param_2 != (char *)0x0) {
      strcpy(param_2,findname);
    }
    puVar3 = findpath;
    sprintf(findpath,"%s/%s",findbase,pdVar2->d_name);
  }
  return puVar3;
}


// Sys_FindNext  @ 000929bc
undefined1 * Sys_FindNext(char *param_1)

{
  int iVar1;
  dirent *pdVar2;
  undefined1 *puVar3;
  
  if (fdir == (DIR *)0x0) {
LAB_00092a4d:
    puVar3 = (undefined1 *)0x0;
  }
  else {
    do {
      pdVar2 = readdir(fdir);
      if (pdVar2 == (dirent *)0x0) goto LAB_00092a4d;
    } while ((findpattern != '\0') && (iVar1 = glob_match(&findpattern,pdVar2->d_name), iVar1 == 0))
    ;
    if (param_1 != (char *)0x0) {
      strcpy(param_1,findname);
    }
    puVar3 = findpath;
    sprintf(findpath,"%s/%s",findbase,pdVar2->d_name);
  }
  return puVar3;
}


// Sys_FloatTime  @ 00092cd4
longdouble Sys_FloatTime(void)

{
  longdouble lVar1;
  timeval local_14;
  timezone local_c;
  
  gettimeofday(&local_14,&local_c);
  if (secbase_83 == 0) {
    secbase_83 = local_14.tv_sec;
    lVar1 = (longdouble)1e-06 * (longdouble)local_14.tv_usec;
  }
  else {
    lVar1 = (longdouble)1e-06 * (longdouble)local_14.tv_usec +
            (longdouble)(local_14.tv_sec - secbase_83);
  }
  return lVar1;
}


// Sys_GetHandle  @ 00092300
undefined4 Sys_GetHandle(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x80) {
    uVar1 = *(undefined4 *)(sys_handles + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Sys_Init  @ 00092ab8
void Sys_Init(void)

{
  return;
}


// Sys_MakeCodeWriteable  @ 00092a90
void Sys_MakeCodeWriteable(void)

{
  return;
}


// Sys_PageIn  @ 00092264
void Sys_PageIn(void)

{
  return;
}


// Sys_PopFPCW  @ 00092aa8
void Sys_PopFPCW(void)

{
  return;
}


// Sys_Printf  @ 00092c48
void Sys_Printf(char *param_1)

{
  char local_404 [1024];
  
  if (isDedicated != 0) {
    vsprintf(local_404,param_1,&stack0x00000008);
    if (Launcher_ConsolePrintf != (code *)0x0) {
      (*Launcher_ConsolePrintf)(&DAT_000aea8e,local_404);
    }
  }
  return;
}


// Sys_PushFPCW_SetHigh  @ 00092aa0
void Sys_PushFPCW_SetHigh(void)

{
  return;
}


// Sys_Quit  @ 00092ca4
void Sys_Quit(void)

{
  Host_Shutdown();
  giActive = 3;
                    /* WARNING: Subroutine does not return */
  longjmp((__jmp_buf_tag *)host_abortserver,1);
}


// Sys_SendKeyEvents  @ 00092d34
void Sys_SendKeyEvents(void)

{
  return;
}


// Sys_SetFPCW  @ 00092a98
void Sys_SetFPCW(void)

{
  return;
}


// Sys_Sleep  @ 00092ac0
void Sys_Sleep(int param_1)

{
  usleep(param_1 * 1000);
  return;
}


// Sys_SplitPath  @ 00094038
void Sys_SplitPath(uint *param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  uint *puVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  size_t sVar5;
  uint *local_10;
  uint *local_c;
  
  local_10 = (uint *)0x0;
  uVar4 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar4 != 0) {
    puVar3 = param_1;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_1 == '\0') goto LAB_0009409b;
        puVar3 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar3 == '\0') goto LAB_0009409b;
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    if ((char)*puVar3 == '\0') goto LAB_0009409b;
    puVar1 = (uint *)((int)puVar3 + 1);
  }
  do {
    puVar3 = puVar1;
    uVar4 = *puVar3;
    if ((char)uVar4 == '\0') goto LAB_0009409b;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_0009409a;
    if ((uVar4 & 0xff0000) == 0) goto LAB_00094099;
    puVar1 = puVar3 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_00094099:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_0009409a:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_0009409b:
  if ((puVar3 == param_1) || (*(char *)((int)param_1 + 1) != ':')) {
    if (param_2 != (char *)0x0) {
      *param_2 = '\0';
    }
  }
  else {
    if (param_2 != (char *)0x0) {
      strncpy(param_2,(char *)param_1,2);
      param_2[2] = '\0';
    }
    param_1 = (uint *)((int)param_1 + 2);
  }
  local_c = (uint *)0x0;
  cVar2 = (char)*param_1;
  puVar1 = param_1;
  while (cVar2 != '\0') {
    cVar2 = (char)*puVar1;
    if ((cVar2 == '/') || (cVar2 == '\\')) {
      local_c = (uint *)((int)puVar1 + 1);
    }
    else if (cVar2 == '.') {
      local_10 = puVar1;
    }
    puVar1 = (uint *)((int)puVar1 + 1);
    cVar2 = *(char *)puVar1;
  }
  if (local_c == (uint *)0x0) {
    local_c = param_1;
    if (param_3 != (char *)0x0) {
      *param_3 = '\0';
    }
  }
  else if (param_3 != (char *)0x0) {
    sVar5 = (int)local_c - (int)param_1;
    if (0xff < sVar5) {
      sVar5 = 0xff;
    }
    strncpy(param_3,(char *)param_1,sVar5);
    param_3[sVar5] = '\0';
  }
  if ((local_10 == (uint *)0x0) || (local_10 < local_c)) {
    if (param_4 != (char *)0x0) {
      sVar5 = (int)puVar1 - (int)local_c;
      if (0xff < sVar5) {
        sVar5 = 0xff;
      }
      strncpy(param_4,(char *)local_c,sVar5);
      param_4[sVar5] = '\0';
    }
    if (param_5 != (char *)0x0) {
      *param_5 = '\0';
    }
  }
  else {
    if (param_4 != (char *)0x0) {
      sVar5 = (int)local_10 - (int)local_c;
      if (0xff < sVar5) {
        sVar5 = 0xff;
      }
      strncpy(param_4,(char *)local_c,sVar5);
      param_4[sVar5] = '\0';
    }
    if (param_5 != (char *)0x0) {
      sVar5 = (int)puVar1 - (int)local_10;
      if (0xff < sVar5) {
        sVar5 = 0xff;
      }
      strncpy(param_5,(char *)local_10,sVar5);
      param_5[sVar5] = '\0';
    }
  }
  return;
}


// Sys_Unlink  @ 0009266c
void Sys_Unlink(char *param_1)

{
  unlink(param_1);
  return;
}


// Sys_Warning  @ 00092bc8
void Sys_Warning(char *param_1)

{
  char local_404 [1024];
  
  vsprintf(local_404,param_1,&stack0x00000008);
  if (isDedicated == 0) {
    if (Launcher_ErrorMessage != (code *)0x0) {
      (*Launcher_ErrorMessage)(1,local_404);
    }
  }
  else if (Launcher_ConsolePrintf != (code *)0x0) {
    (*Launcher_ConsolePrintf)("WARNING:  %s\n",local_404);
  }
  giActive = 2;
  return;
}


// Sys_mkdir  @ 00092614
void Sys_mkdir(char *param_1)

{
  mkdir(param_1,0x1f8);
  return;
}


