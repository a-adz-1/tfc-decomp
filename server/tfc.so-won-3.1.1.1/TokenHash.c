// TokenHash__18CSaveRestoreBufferPCc  @ 0011f564
uint TokenHash__18CSaveRestoreBufferPCc(int *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  bool bVar8;
  int local_10;
  
  uVar4 = 0;
  cVar1 = *param_2;
  pcVar6 = param_2;
  while (cVar1 != '\0') {
    iVar5 = 3;
    do {
      uVar2 = uVar4 & 1;
      uVar4 = uVar4 >> 1;
      if (uVar2 != 0) {
        uVar4 = uVar4 | 0x80000000;
      }
      bVar8 = iVar5 != 0;
      iVar5 = iVar5 + -1;
    } while (bVar8);
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    uVar4 = (int)cVar1 ^ uVar4;
    cVar1 = *pcVar6;
  }
  iVar5 = 0;
  local_10 = *param_1;
  uVar2 = *(uint *)(local_10 + 0x14);
  if (0 < (int)uVar2) {
    do {
      uVar7 = (uVar4 % uVar2 & 0xffff) + iVar5;
      if (*(int *)(local_10 + 0x14) <= (int)uVar7) {
        uVar7 = uVar7 - *(int *)(local_10 + 0x14);
      }
      pcVar6 = *(char **)(*(int *)(local_10 + 0x18) + uVar7 * 4);
      if ((pcVar6 == (char *)0x0) || (iVar3 = strcmp(param_2,pcVar6), iVar3 == 0)) {
        *(char **)(*(int *)(*param_1 + 0x18) + uVar7 * 4) = param_2;
        return uVar7 & 0xffff;
      }
      iVar5 = iVar5 + 1;
      local_10 = *param_1;
    } while (iVar5 < *(int *)(local_10 + 0x14));
  }
  (*DAT_0019f794)(4,"CSaveRestoreBuffer :: TokenHash() is COMPLETELY FULL!");
  return 0;
}


