// Legacy_ErrorMessage  @ 00149900
void Legacy_ErrorMessage(int nLevel,char *pszErrorMessage)

{
  return;
}


// Legacy_MP3subsys_Resume_Audio  @ 00149920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Legacy_MP3subsys_Resume_Audio(void)

{
  return;
}


// Legacy_MP3subsys_Suspend_Audio  @ 00149910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Legacy_MP3subsys_Suspend_Audio(void)

{
  return;
}


// Legacy_Sys_Printf  @ 00149540
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


