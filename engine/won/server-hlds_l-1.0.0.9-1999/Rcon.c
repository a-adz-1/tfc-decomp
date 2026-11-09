// Rcon_Validate  @ 08059d10
undefined4 Rcon_Validate(void)

{
  char cVar1;
  char *__s1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = -1;
  pcVar3 = (char *)rcon_password._4_4_;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 != -2) {
    pcVar3 = (char *)rcon_password._4_4_;
    __s1 = (char *)Cmd_Argv(1);
    iVar2 = strcmp(__s1,pcVar3);
    if (iVar2 == 0) {
      return 1;
    }
  }
  return 0;
}


