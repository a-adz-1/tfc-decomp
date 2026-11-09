// Con_DPrintf  @ 00096f60
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Con_DPrintf(char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  (*g_engdstAddrs.Con_DPrintf)(&fmt);
  if (developer.value != 0.0) {
    vfprintf(_stdout,fmt,&stack0x00000008);
    fflush(_stdout);
    return;
  }
  return;
}


// Con_DebugLog  @ 000969e0
void Con_DebugLog(char *file,char *fmt,...)

{
  FileHandle_t file_00;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: FILE * fd@[???] */
  vsnprintf(Con_DebugLog::data,0x2000,fmt,&stack0x0000000c);
  Con_DebugLog::data[0x1fff] = false;
  file_00 = FS_Open(file,"at");
  FS_FPrintf(file_00,"%s",Con_DebugLog::data);
  FS_Close(file_00);
  return;
}


// Con_Debug_f  @ 00096b50
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


// Con_Init  @ 00096fc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Init(void)

{
  con_debuglog = COM_CheckParm("-condebug");
  Con_DPrintf("Console initialized.\n");
  Cmd_AddCommand("condebug",Con_Debug_f);
  return;
}


// Con_NPrintf  @ 00068610
void Con_NPrintf(int idx,char *fmt,...)

{
  return;
}


// Con_Printf  @ 00096a50
void Con_Printf(char *fmt,...)

{
  int iVar1;
  int iVar2;
  char local_200c [8191];
  undefined1 local_d;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[8192] msg@[???] */
  (*g_engdstAddrs.Con_DPrintf)(&fmt);
  vsnprintf(local_200c,0x2000,fmt,&stack0x00000008);
  local_d = 0;
  Sys_Printf("%s",local_200c);
  if (sv_redirected != RD_NONE) {
    iVar1 = Q_strlen(local_200c);
    iVar2 = Q_strlen(outputbuf);
    if (0x577 < (uint)(iVar1 + iVar2)) {
      SV_FlushRedirect();
    }
    strncat(outputbuf,local_200c,0x577);
    return;
  }
  if (con_debuglog == false) {
    return;
  }
  Con_DebugLog("qconsole.log","%s",local_200c);
  return;
}


// Con_SafePrintf  @ 00096f20
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Con_SafePrintf(char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vfprintf(_stdout,fmt,&stack0x00000008);
  fflush(_stdout);
  return;
}


// Con_Shutdown  @ 00068550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Con_Shutdown(void)

{
  return;
}


