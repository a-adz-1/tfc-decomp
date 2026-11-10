// CreatePath__11AuthRequestPc  @ 0009bbbc
void CreatePath__11AuthRequestPc(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_2 + 1;
  cVar1 = param_2[1];
  while (cVar1 != '\0') {
    cVar1 = *pcVar2;
    if ((cVar1 == '/') || (cVar1 == '\\')) {
      *pcVar2 = '\0';
      mkdir(param_2,0x1ff);
      *pcVar2 = cVar1;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  return;
}


