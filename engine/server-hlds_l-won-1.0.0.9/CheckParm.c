// CheckParm__FPCcPPc  @ 08089610
char * CheckParm__FPCcPPc(char *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  if (gpszCmdLine == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = strstr(gpszCmdLine,param_1);
    if ((pcVar2 != (char *)0x0) && (param_2 != (undefined4 *)0x0)) {
      *param_2 = 0;
      cVar1 = *pcVar2;
      pcVar3 = pcVar2;
      while ((cVar1 != '\0' && (*pcVar3 != ' '))) {
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
      if (pcVar3 != (char *)0x0) {
        iVar4 = 0;
        do {
          pcVar3 = pcVar3 + 1;
          if ((*pcVar3 == '\0') || (*pcVar3 == ' ')) break;
          (&sz_452)[iVar4] = *pcVar3;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x80);
        (&sz_452)[iVar4] = 0;
        *param_2 = &sz_452;
      }
    }
  }
  return pcVar2;
}


