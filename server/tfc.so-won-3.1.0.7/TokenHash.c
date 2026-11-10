// TokenHash__18CSaveRestoreBufferPCc  @ 0011cbcc
uint TokenHash__18CSaveRestoreBufferPCc(int *param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_c;
  
  uVar2 = HashString__18CSaveRestoreBufferPCc(param_1,param_2);
  local_c = *param_1;
  uVar1 = *(uint *)(local_c + 0x14);
  iVar5 = 0;
  if (0 < *(int *)(local_c + 0x14)) {
    do {
      uVar4 = (uVar2 % uVar1 & 0xffff) + iVar5;
      if (*(int *)(local_c + 0x14) <= (int)uVar4) {
        uVar4 = uVar4 - *(int *)(local_c + 0x14);
      }
      if ((*(int *)(*(int *)(*param_1 + 0x18) + uVar4 * 4) == 0) ||
         (iVar3 = strcmp(param_2,*(char **)(*(int *)(*param_1 + 0x18) + uVar4 * 4)), iVar3 == 0)) {
        *(char **)(*(int *)(*param_1 + 0x18) + uVar4 * 4) = param_2;
        return uVar4 & 0xffff;
      }
      iVar5 = iVar5 + 1;
      local_c = *param_1;
    } while (iVar5 < *(int *)(local_c + 0x14));
  }
  (*DAT_001c1114)(4,"CSaveRestoreBuffer :: TokenHash() is COMPLETELY FULL!");
  return 0;
}


