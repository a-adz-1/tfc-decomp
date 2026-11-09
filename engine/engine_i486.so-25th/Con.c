// Con_DPrintf  @ 0007aff0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Con_DPrintf(char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  (*g_engdstAddrs.Con_DPrintf)(&fmt);
  if (developer.value != 0.0) {
    __vfprintf_chk(_stdout,1,fmt,&stack0x00000008);
    fflush(_stdout);
    return;
  }
  return;
}


// Con_DebugLog  @ 0007a9f0
void Con_DebugLog(char *file,char *fmt,...)

{
  FileHandle_t file_00;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: FILE * fd@[???] */
  __vsnprintf_chk(Con_DebugLog::data,0x2000,1,0x2000,fmt,&stack0x0000000c);
  Con_DebugLog::data[0x1fff] = false;
  file_00 = FS_Open(file,"at");
  FS_FPrintf(file_00,"%s",Con_DebugLog::data);
  FS_Close(file_00);
  return;
}


// Con_Debug_f  @ 0007af60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Debug_f(void)

{
  if (con_debuglog == false) {
    con_debuglog = true;
    Con_Printf("condebug enabled\n");
    return;
  }
  Con_Printf("condebug disabled\n");
  con_debuglog = false;
  return;
}


// Con_Init  @ 0007b780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Init(void)

{
  con_debuglog = COM_CheckParm("-condebug");
  Con_DPrintf("Console initialized.\n");
  Cmd_AddCommand("condebug",Con_Debug_f);
  return;
}


// Con_NPrintf  @ 00045520
void Con_NPrintf(int idx,char *fmt,...)

{
  return;
}


// Con_Printf  @ 0007aa70
void Con_Printf(char *fmt,...)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  char *local_2020 [4];
  char local_2010 [8191];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[8192] msg@[???] */
  local_2020[0] = fmt;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engdstAddrs.Con_DPrintf)(local_2020);
  __vsnprintf_chk(local_2010,0x2000,1,0x2000,local_2020[0],&stack0x00000008);
  local_11 = 0;
  Sys_Printf("%s",local_2010);
  if (sv_redirected == RD_NONE) {
    if (con_debuglog != false) {
      Con_DebugLog("qconsole.log","%s",local_2010);
    }
  }
  else {
    iVar1 = Q_strlen(local_2010);
    iVar2 = Q_strlen(outputbuf);
    if (0x577 < (uint)(iVar2 + iVar1)) {
      SV_FlushRedirect();
    }
    __strncat_chk(outputbuf,local_2010,0x577,0x578);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Con_SafePrintf  @ 0007afb0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Con_SafePrintf(char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vfprintf_chk(_stdout,1,fmt,&stack0x00000008);
  fflush(_stdout);
  return;
}


// Con_Shutdown  @ 00045460
void Con_Shutdown(void)

{
  return;
}


