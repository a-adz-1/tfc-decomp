// ValidateCDKey__FPc  @ 08089d40
undefined4 ValidateCDKey__FPc(char *param_1)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    iVar2 = -1;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    if (iVar2 == -0xf) {
      return 1;
    }
  }
  return 0;
}


