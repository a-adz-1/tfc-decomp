// NextNodeInRoute__6CGraphiiii  @ 000c4090
int NextNodeInRoute__6CGraphiiii(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_3 + 1;
  pcVar2 = (char *)(*(int *)(param_1 + 0x14) +
                   *(int *)(param_5 * 4 + param_4 * 8 +
                           *(int *)(param_1 + 0xc) + 0x28 + param_2 * 0x58));
  iVar3 = param_2;
  while( true ) {
    while( true ) {
      if (iVar4 < 1) {
        return iVar3;
      }
      cVar1 = *pcVar2;
      if (cVar1 < '\0') break;
      if (cVar1 + 1 < iVar4) {
        iVar4 = (iVar4 - cVar1) + -1;
      }
      else {
        iVar3 = param_2 + pcVar2[1];
        if (iVar3 < *(int *)(param_1 + 0x18)) {
          if (iVar3 < 0) {
            iVar3 = iVar3 + *(int *)(param_1 + 0x18);
          }
        }
        else {
          iVar3 = iVar3 - *(int *)(param_1 + 0x18);
        }
        iVar4 = 0;
      }
      pcVar2 = pcVar2 + 2;
    }
    if (iVar4 <= -cVar1) break;
    iVar4 = iVar4 - -cVar1;
    pcVar2 = pcVar2 + 1;
  }
  return param_3;
}


