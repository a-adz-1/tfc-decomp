// ExtractCommandString__FPcT0  @ 000aee88
void ExtractCommandString__FPcT0(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  char *pcVar5;
  uint auStack_404 [128];
  char local_204 [512];
  
  cVar1 = *param_1;
  if (cVar1 == '\\') {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  pcVar5 = local_204;
  do {
    while (cVar1 != '\\') {
      if (cVar1 == '\0') {
        return;
      }
      *pcVar5 = cVar1;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
      cVar1 = *param_1;
    }
    *pcVar5 = '\0';
    puVar4 = auStack_404;
    while( true ) {
      pcVar5 = param_1 + 1;
      cVar1 = *pcVar5;
      if ((cVar1 == '\\') || (cVar1 == '\0')) break;
      *(char *)puVar4 = cVar1;
      puVar4 = (uint *)((int)puVar4 + 1);
      param_1 = pcVar5;
    }
    *(char *)puVar4 = '\0';
    strcat(param_2,local_204);
    puVar4 = auStack_404;
    do {
      puVar3 = puVar4;
      uVar2 = *puVar3;
      if ((char)uVar2 == '\0') goto LAB_000aef32;
      if ((char)(uVar2 >> 8) == '\0') goto LAB_000aef31;
      if ((uVar2 & 0xff0000) == 0) goto LAB_000aef30;
      puVar4 = puVar3 + 1;
    } while ((uVar2 & 0xff000000) != 0);
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_000aef30:
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_000aef31:
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_000aef32:
    if (puVar3 != auStack_404) {
      strcat(param_2," ");
      strcat(param_2,(char *)auStack_404);
    }
    strcat(param_2,"\n");
    if (*pcVar5 == '\0') {
      return;
    }
    param_1 = param_1 + 2;
    cVar1 = *param_1;
    pcVar5 = local_204;
  } while( true );
}


