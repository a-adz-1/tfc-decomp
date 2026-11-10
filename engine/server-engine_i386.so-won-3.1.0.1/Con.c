// Con_DPrintf  @ 00094338
void Con_DPrintf(char *param_1)

{
  if ((byte)((float)developer._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    vprintf(param_1,&stack0x00000008);
    fflush((FILE *)_IO_stdout_);
  }
  return;
}


// Con_Init  @ 00092144
void Con_Init(void)

{
  return;
}


// Con_NPrintf  @ 000921c0
void Con_NPrintf(void)

{
  return;
}


// Con_Print  @ 00094380
void Con_Print(char *param_1)

{
  fputs(param_1,(FILE *)_IO_stdout_);
  fflush((FILE *)_IO_stdout_);
  return;
}


// Con_Printf  @ 0009427c
void Con_Printf(char *param_1)

{
  int iVar1;
  int iVar2;
  char local_2004 [8192];
  
  vsprintf(local_2004,param_1,&stack0x00000008);
  if (sv_redirected == 0) {
    Sys_Printf(&DAT_000aea8e,local_2004);
  }
  else {
    iVar1 = Q_strlen(local_2004);
    iVar2 = Q_strlen(&outputbuf);
    if (0x577 < (uint)(iVar2 + iVar1)) {
      SV_FlushRedirect();
    }
    Q_strcat(&outputbuf,local_2004);
  }
  return;
}


// Con_SafePrintf  @ 00094308
void Con_SafePrintf(char *param_1)

{
  vprintf(param_1,&stack0x00000008);
  fflush((FILE *)_IO_stdout_);
  return;
}


// Con_Shutdown  @ 0009215c
void Con_Shutdown(void)

{
  return;
}


