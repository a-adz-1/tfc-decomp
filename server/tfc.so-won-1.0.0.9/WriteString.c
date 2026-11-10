// WriteString__5CSavePCcPCii  @ 00119130
void WriteString__5CSavePCcPCii(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
  iVar3 = 0;
  iVar5 = 0;
  if (0 < param_4) {
    do {
      uVar2 = 0xffffffff;
      pcVar6 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(param_3 + iVar5 * 4));
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      iVar3 = iVar3 + ~uVar2;
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_4);
  }
  BufferHeader__5CSavePCci(param_1,param_2,iVar3);
  iVar3 = 0;
  if (0 < param_4) {
    do {
      pcVar4 = (char *)(*(int *)(param_3 + iVar3 * 4) + *(int *)(gpGlobals + 0x98));
      uVar2 = 0xffffffff;
      pcVar6 = pcVar4;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      BufferData__5CSavePCci(param_1,pcVar4,~uVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  return;
}


// WriteString__5CSavePCcT1  @ 00119100
void WriteString__5CSavePCcT1(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = param_3;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  BufferField__5CSavePCciT1(param_1,param_2,~uVar2,param_3);
  return;
}


