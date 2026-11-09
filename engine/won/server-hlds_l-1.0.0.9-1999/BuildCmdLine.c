// BuildCmdLine__FiPPc  @ 08089ec0
void BuildCmdLine__FiPPc(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar3 = 0;
  iVar4 = 1;
  if (1 < param_1) {
    do {
      uVar2 = 0xffffffff;
      pcVar5 = *(char **)(param_2 + iVar4 * 4);
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar3 = iVar3 + ~uVar2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1);
  }
  cmdline = (char *)__builtin_vec_new(iVar3 + 1);
  *cmdline = '\0';
  iVar3 = 1;
  if (1 < param_1) {
    do {
      if (1 < iVar3) {
        strcat(cmdline," ");
      }
      strcat(cmdline,*(char **)(param_2 + iVar3 * 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1);
  }
  return;
}


