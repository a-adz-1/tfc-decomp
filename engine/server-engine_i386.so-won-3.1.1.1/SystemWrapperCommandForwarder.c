// SystemWrapperCommandForwarder__Fv  @ 00097788
void SystemWrapperCommandForwarder__Fv(void)

{
  char *pcVar1;
  int iVar2;
  char local_404 [1023];
  undefined1 local_5;
  
  pcVar1 = (char *)Cmd_Argv(0);
  strcpy(local_404,pcVar1);
  iVar2 = Cmd_Argc();
  if (1 < iVar2) {
    strcat(local_404," ");
    pcVar1 = (char *)Cmd_Args();
    strcat(local_404,pcVar1);
  }
  local_5 = 0;
  ExecuteString__13SystemWrapperPc(gSystemWrapper,local_404);
  return;
}


