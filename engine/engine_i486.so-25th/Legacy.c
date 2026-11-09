// Legacy_ErrorMessage  @ 0007bf70
void Legacy_ErrorMessage(int nLevel,char *pszErrorMessage)

{
  return;
}


// Legacy_MP3subsys_Resume_Audio  @ 0007bf90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Legacy_MP3subsys_Resume_Audio() */

void Legacy_MP3subsys_Resume_Audio(void)

{
  return;
}


// Legacy_MP3subsys_Suspend_Audio  @ 0007bf80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Legacy_MP3subsys_Suspend_Audio() */

void Legacy_MP3subsys_Suspend_Audio(void)

{
  return;
}


// Legacy_Sys_Printf  @ 0007b7f0
void Legacy_Sys_Printf(char *fmt,...)

{
  int in_GS_OFFSET;
  undefined1 local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] text@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000008);
  if (dedicated != (IDedicatedExports *)0x0) {
    (**(code **)(*(int *)dedicated + 8))(dedicated,local_410);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


