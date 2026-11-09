// Con_DPrintf  @ 08089d00
void Con_DPrintf(char *param_1)

{
  if ((byte)(0.0 < (float)developer._12_4_ |
             (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    vprintf(param_1,&stack0x00000008);
    fflush((FILE *)_IO_stdout_);
  }
  return;
}


// Con_Init  @ 0808d4d0
void Con_Init(void)

{
  return;
}


// Con_Print  @ 08089ce0
void Con_Print(char *param_1)

{
  fputs(param_1,(FILE *)_IO_stdout_);
  fflush((FILE *)_IO_stdout_);
  return;
}


// Con_Printf  @ 08089c30
void Con_Printf(char *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char local_2004 [8192];
  
  vsprintf(local_2004,param_1,&stack0x00000008);
  if (sv_redirected == 0) {
    Sys_Printf(local_2004);
  }
  else {
    uVar2 = 0xffffffff;
    pcVar4 = local_2004;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar3 = 0xffffffff;
    pcVar4 = &outputbuf;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (0x577 < (~uVar2 - 2) + ~uVar3) {
      Host_FlushRedirect();
    }
    strcat(&outputbuf,local_2004);
  }
  return;
}


// Con_SafePrintf  @ 08089cc0
void Con_SafePrintf(char *param_1)

{
  vprintf(param_1,&stack0x00000008);
  fflush((FILE *)_IO_stdout_);
  return;
}


// Con_Shutdown  @ 0808d520
void Con_Shutdown(void)

{
  return;
}


