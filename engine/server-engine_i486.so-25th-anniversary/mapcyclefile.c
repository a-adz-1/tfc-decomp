// mapcyclefile_hook_callback  @ 00080820
void __regparm3 mapcyclefile_hook_callback(cvar_t *cvar)

{
  char *s1;
  int iVar1;
  int in_GS_OFFSET;
  char local_1011 [4097];
  int local_10;
  
                    /* Unresolved local var: char[4097] buf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __snprintf_chk(local_1011,0x1001,1,0x1001,"%s.txt",cvar->string);
  s1 = COM_LastFileExtension(local_1011);
  iVar1 = Q_strcmp(s1,"txt");
  if (iVar1 == 0) {
    Cvar_DirectSet(cvar,local_1011);
  }
  else {
    Cvar_DirectSet(cvar,"mapcycle.txt");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// mapcyclefile_hook_callback  @ 000808d0
void mapcyclefile_hook_callback(cvar_t *cvar)

{
  char *s1;
  int iVar1;
  
  s1 = COM_LastFileExtension(cvar->string);
  iVar1 = Q_strcmp(s1,"txt");
  if (iVar1 == 0) {
    return;
  }
  mapcyclefile_hook_callback(cvar);
  return;
}


