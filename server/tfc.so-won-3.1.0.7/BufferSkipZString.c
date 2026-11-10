// BufferSkipZString__8CRestore  @ 0011e7e8
int BufferSkipZString__8CRestore(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  if (*param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar2 = *param_1;
    pcVar4 = *(char **)(iVar2 + 4);
    for (iVar3 = 0;
        (cVar1 = *pcVar4, pcVar4 = pcVar4 + 1, cVar1 != '\0' &&
        (iVar3 < *(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8))); iVar3 = iVar3 + 1) {
    }
    iVar3 = iVar3 + 1;
    BufferSkipBytes__8CRestorei(param_1,iVar3);
  }
  return iVar3;
}


