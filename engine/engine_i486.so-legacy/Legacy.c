// Legacy_ErrorMessage  @ 00097ef0
void Legacy_ErrorMessage(int nLevel,char *pszErrorMessage)

{
  return;
}


// Legacy_MP3subsys_Resume_Audio  @ 00097f10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Legacy_MP3subsys_Resume_Audio(void)

{
  return;
}


// Legacy_MP3subsys_Suspend_Audio  @ 00097f00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Legacy_MP3subsys_Suspend_Audio(void)

{
  return;
}


// Legacy_Sys_Printf  @ 00097b50
void Legacy_Sys_Printf(char *fmt,...)

{
  char local_40c [1032];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] text@[???] */
  vsnprintf(local_40c,0x400,fmt,&stack0x00000008);
  if (dedicated != (IDedicatedExports *)0x0) {
    (**(code **)(*(int *)dedicated + 8))(dedicated,local_40c);
  }
  return;
}


