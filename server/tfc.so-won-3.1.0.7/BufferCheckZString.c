// BufferCheckZString__8CRestorePCc  @ 0011e838
undefined4 BufferCheckZString__8CRestorePCc(int *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  if (*param_1 != 0) {
    iVar2 = *param_1;
    uVar3 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (((int)(~uVar3 - 1) <= *(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8)) &&
       (iVar2 = strncmp(param_2,*(char **)(iVar2 + 4),~uVar3 - 1), iVar2 == 0)) {
      return 1;
    }
  }
  return 0;
}


