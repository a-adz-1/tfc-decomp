// Legacy_ErrorMessage__FiPCc  @ 000960c8
void Legacy_ErrorMessage__FiPCc(void)

{
  return;
}


// Legacy_MP3subsys_Resume_Audio__Fv  @ 00096158
void Legacy_MP3subsys_Resume_Audio__Fv(void)

{
  return;
}


// Legacy_MP3subsys_Suspend_Audio__Fv  @ 0009614c
void Legacy_MP3subsys_Suspend_Audio__Fv(void)

{
  return;
}


// Legacy_Sys_Printf__FPce  @ 000960d4
void Legacy_Sys_Printf__FPce(char *param_1)

{
  char local_408 [1024];
  undefined1 *local_8;
  
  local_8 = &stack0x00000008;
  vsnprintf(local_408,0x400,param_1,local_8);
  if (dedicated != (int *)0x0) {
    (**(code **)(*dedicated + 0xc))(dedicated,local_408);
  }
  return;
}


