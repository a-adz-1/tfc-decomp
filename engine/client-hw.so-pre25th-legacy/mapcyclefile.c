// mapcyclefile_hook_callback  @ 0014dc20
void __regparm3 mapcyclefile_hook_callback(cvar_t *cvar)

{
  char *s1;
  int iVar1;
  char local_100d [4101];
  
                    /* Unresolved local var: char[4097] buf@[???] */
  snprintf(local_100d,0x1001,"%s.txt",cvar->string);
  s1 = COM_LastFileExtension(local_100d);
  iVar1 = Q_strcmp(s1,"txt");
  if (iVar1 != 0) {
    Cvar_DirectSet(cvar,"mapcycle.txt");
    return;
  }
  Cvar_DirectSet(cvar,local_100d);
  return;
}


// mapcyclefile_hook_callback  @ 0014dcb0
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


