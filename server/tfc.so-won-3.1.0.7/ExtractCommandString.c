// ExtractCommandString__FPcT0  @ 000b0330
void ExtractCommandString__FPcT0(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char acStack_400 [512];
  char local_200 [512];
  
  if (*param_1 != '\\') goto LAB_000b0354;
  do {
    param_1 = param_1 + 1;
LAB_000b0354:
    pcVar3 = local_200;
    cVar1 = *param_1;
    while (cVar1 != '\\') {
      if (*param_1 == '\0') {
        return;
      }
      *pcVar3 = *param_1;
      param_1 = param_1 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *param_1;
    }
    *pcVar3 = '\0';
    param_1 = param_1 + 1;
    pcVar3 = acStack_400;
    cVar1 = *param_1;
    while ((cVar1 != '\\' && (*param_1 != '\0'))) {
      *pcVar3 = *param_1;
      param_1 = param_1 + 1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *param_1;
    }
    *pcVar3 = '\0';
    strcat(param_2,local_200);
    iVar2 = -1;
    pcVar3 = acStack_400;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      strcat(param_2," ");
      strcat(param_2,acStack_400);
    }
    strcat(param_2,"\n");
    if (*param_1 == '\0') {
      return;
    }
  } while( true );
}


