// extract_cie_info  @ 00120ce0
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

byte * extract_cie_info(int param_1,int *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint *puVar8;
  char *pcVar9;
  uint *puVar10;
  bool bVar11;
  int local_8;
  
  param_1 = param_1 - (*(int *)(param_1 + 4) + -4);
  pcVar7 = (char *)(param_1 + 9);
  *param_2 = (int)pcVar7;
  iVar5 = 1;
  bVar11 = true;
  pcVar6 = pcVar7;
  pcVar9 = "";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar11 = *pcVar6 == *pcVar9;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar11);
  if (!bVar11) {
    iVar5 = 3;
    bVar11 = true;
    pcVar6 = "eh";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar11);
    if ((!bVar11) && (*(char *)(param_1 + 9) != 'z')) {
      return (byte *)0x0;
    }
  }
  puVar8 = (uint *)*param_2;
  uVar2 = (uint)puVar8 & 3;
  puVar1 = puVar8;
  if (uVar2 != 0) {
    puVar10 = puVar8;
    if ((POPCOUNT(uVar2) & 1U) != 0) {
      if (uVar2 != 2) {
        if ((char)*puVar8 == '\0') goto LAB_00120d92;
        puVar10 = (uint *)((int)puVar8 + 1);
      }
      if ((char)*puVar10 == '\0') goto LAB_00120d92;
      puVar10 = (uint *)((int)puVar10 + 1);
    }
    if ((char)*puVar10 == '\0') goto LAB_00120d92;
    puVar1 = (uint *)((int)puVar10 + 1);
  }
  do {
    puVar10 = puVar1;
    uVar2 = *puVar10;
    if ((char)uVar2 == '\0') goto LAB_00120d92;
    if ((char)(uVar2 >> 8) == '\0') goto LAB_00120d91;
    if ((uVar2 & 0xff0000) == 0) goto LAB_00120d90;
    puVar1 = puVar10 + 1;
  } while ((uVar2 & 0xff000000) != 0);
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_00120d90:
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_00120d91:
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_00120d92:
  pcVar6 = (char *)((int)puVar10 + 1);
  iVar5 = 3;
  bVar11 = true;
  pcVar7 = "eh";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar11 = (char)*puVar8 == *pcVar7;
    puVar8 = (uint *)((int)puVar8 + 1);
    pcVar7 = pcVar7 + 1;
  } while (bVar11);
  if (bVar11) {
    param_2[1] = *(int *)((int)puVar10 + 1);
    pcVar6 = (char *)((int)puVar10 + 5);
  }
  else {
    param_2[1] = 0;
  }
  uVar3 = decode_uleb128(pcVar6,param_2 + 2);
  pbVar4 = (byte *)decode_sleb128(uVar3,param_2 + 3);
  param_2[4] = (uint)*pbVar4;
  pbVar4 = pbVar4 + 1;
  if (*(char *)*param_2 == 'z') {
    iVar5 = decode_uleb128(pbVar4,&local_8);
    pbVar4 = (byte *)(iVar5 + local_8);
  }
  return pbVar4;
}


