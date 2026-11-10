// WriteString__5CSavePCcPCii  @ 0011cf64
void WriteString__5CSavePCcPCii(undefined4 param_1,undefined4 param_2,int *param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  char *pcVar10;
  int local_4;
  
  uVar9 = 0;
  local_4 = 0;
  if (0 < (int)param_4) {
    uVar7 = param_4 & 3;
    piVar8 = param_3;
    if (uVar7 == 0) goto LAB_0011d020;
    if (1 < uVar7) {
      if (2 < uVar7) {
        uVar9 = 0xffffffff;
        pcVar10 = (char *)(*param_3 + *(int *)(gpGlobals + 0x98));
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        uVar9 = ~uVar9;
        piVar8 = param_3 + 1;
        local_4 = 1;
      }
      uVar7 = 0xffffffff;
      pcVar10 = (char *)(*piVar8 + *(int *)(gpGlobals + 0x98));
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar9 = uVar9 + ~uVar7;
      piVar8 = piVar8 + 1;
      local_4 = local_4 + 1;
    }
    uVar7 = 0xffffffff;
    pcVar10 = (char *)(*piVar8 + *(int *)(gpGlobals + 0x98));
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    uVar9 = uVar9 + ~uVar7;
    piVar8 = piVar8 + 1;
    for (local_4 = local_4 + 1; local_4 < (int)param_4; local_4 = local_4 + 4) {
LAB_0011d020:
      iVar2 = *(int *)(gpGlobals + 0x98);
      iVar4 = -1;
      pcVar10 = (char *)(iVar2 + *piVar8);
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar7 = 0xffffffff;
      pcVar10 = (char *)(iVar2 + piVar8[1]);
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar5 = 0xffffffff;
      pcVar10 = (char *)(iVar2 + piVar8[2]);
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar6 = 0xffffffff;
      pcVar10 = (char *)(iVar2 + piVar8[3]);
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar9 = ~uVar5 + ~uVar7 + (uVar9 - iVar4) + -1 + ~uVar6;
      piVar8 = piVar8 + 4;
    }
  }
  BufferHeader__5CSavePCci(param_1,param_2,uVar9);
  local_4 = 0;
  if (0 < (int)param_4) {
    uVar9 = param_4 & 3;
    if (uVar9 == 0) goto LAB_0011d184;
    if (1 < uVar9) {
      if (2 < uVar9) {
        pcVar3 = (char *)(*param_3 + *(int *)(gpGlobals + 0x98));
        uVar9 = 0xffffffff;
        pcVar10 = pcVar3;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        BufferData__5CSavePCci(param_1,pcVar3,~uVar9);
        param_3 = param_3 + 1;
        local_4 = 1;
      }
      pcVar3 = (char *)(*param_3 + *(int *)(gpGlobals + 0x98));
      uVar9 = 0xffffffff;
      pcVar10 = pcVar3;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      BufferData__5CSavePCci(param_1,pcVar3,~uVar9);
      param_3 = param_3 + 1;
      local_4 = local_4 + 1;
    }
    pcVar3 = (char *)(*param_3 + *(int *)(gpGlobals + 0x98));
    uVar9 = 0xffffffff;
    pcVar10 = pcVar3;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    BufferData__5CSavePCci(param_1,pcVar3,~uVar9);
    param_3 = param_3 + 1;
    for (local_4 = local_4 + 1; local_4 < (int)param_4; local_4 = local_4 + 4) {
LAB_0011d184:
      pcVar3 = (char *)(*param_3 + *(int *)(gpGlobals + 0x98));
      uVar9 = 0xffffffff;
      pcVar10 = pcVar3;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      BufferData__5CSavePCci(param_1,pcVar3,~uVar9);
      pcVar3 = (char *)(param_3[1] + *(int *)(gpGlobals + 0x98));
      uVar9 = 0xffffffff;
      pcVar10 = pcVar3;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      BufferData__5CSavePCci(param_1,pcVar3,~uVar9);
      pcVar3 = (char *)(param_3[2] + *(int *)(gpGlobals + 0x98));
      uVar9 = 0xffffffff;
      pcVar10 = pcVar3;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      BufferData__5CSavePCci(param_1,pcVar3,~uVar9);
      pcVar3 = (char *)(param_3[3] + *(int *)(gpGlobals + 0x98));
      uVar9 = 0xffffffff;
      pcVar10 = pcVar3;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      BufferData__5CSavePCci(param_1,pcVar3,~uVar9);
      param_3 = param_3 + 4;
    }
  }
  return;
}


// WriteString__5CSavePCcT1  @ 0011cf2c
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


