// Con_DPrintf  @ 00096004
void Con_DPrintf(char *param_1)

{
  (*(code *)g_engdstAddrs._164_4_)(&param_1);
  if ((byte)(0.0 < (float)developer._12_4_ |
             (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    vprintf(param_1,&stack0x00000008);
    fflush((FILE *)_IO_stdout_);
  }
  return;
}


// Con_DebugLog  @ 00095e20
void Con_DebugLog(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  
  vsnprintf(data_156,0x400,param_2,&stack0x0000000c);
  uVar1 = FS_Open(param_1,&DAT_000e7512);
  FS_FPrintf(uVar1,&DAT_000e708a,data_156);
  FS_Close(uVar1);
  return;
}


// Con_Debug_f  @ 00095d40
void Con_Debug_f(void)

{
  if (con_debuglog == 0) {
    con_debuglog = 1;
    Con_Printf("condebug enabled\n");
  }
  else {
    Con_Printf("condebug disabled\n");
    con_debuglog = 0;
  }
  return;
}


// Con_Init  @ 00095da8
void Con_Init(void)

{
  con_debuglog = COM_CheckParm("-condebug");
  Con_DPrintf("Console initialized.\n");
  Cmd_AddCommand("condebug",Con_Debug_f);
  return;
}


// Con_NPrintf  @ 0005f268
void Con_NPrintf(void)

{
  return;
}


// Con_Printf  @ 00095eac
void Con_Printf(char *param_1)

{
  int iVar1;
  int iVar2;
  char local_2008 [8192];
  undefined1 *local_8;
  
  (*(code *)g_engdstAddrs._164_4_)(&param_1);
  local_8 = &stack0x00000008;
  vsnprintf(local_2008,0x2000,param_1,local_8);
  Sys_Printf(&DAT_000e708a,local_2008);
  if (sv_redirected == 0) {
    if (con_debuglog != 0) {
      Con_DebugLog("qconsole.log",&DAT_000e708a,local_2008);
    }
  }
  else {
    iVar1 = Q_strlen(local_2008);
    iVar2 = Q_strlen(&outputbuf);
    if (0x577 < (uint)(iVar2 + iVar1)) {
      SV_FlushRedirect();
    }
    strncat(&outputbuf,local_2008,0x577);
  }
  return;
}


// Con_SafePrintf  @ 00095fbc
void Con_SafePrintf(char *param_1)

{
  vprintf(param_1,&stack0x00000008);
  fflush((FILE *)_IO_stdout_);
  return;
}


// Con_Shutdown  @ 0005f204
void Con_Shutdown(void)

{
  return;
}


