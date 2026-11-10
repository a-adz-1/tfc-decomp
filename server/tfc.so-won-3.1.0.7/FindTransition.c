// FindTransition__14CBaseAnimatingiiPi  @ 000bf554
undefined4
FindTransition__14CBaseAnimatingiiPi(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int local_4;
  
  uVar1 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  if (param_4 == 0) {
    uVar1 = FindTransition__FPviiPi(uVar1,param_2,param_3,&local_4);
    if (local_4 != 1) {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = FindTransition__FPviiPi(uVar1,param_2,param_3,param_4);
  }
  return uVar1;
}


// FindTransition__FPviiPi  @ 00087f30
int FindTransition__FPviiPi(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint *local_14;
  int *local_c;
  
  if (param_1 == 0) {
    return param_3;
  }
  iVar6 = param_1 + *(int *)(param_1 + 0xa8);
  if (*(int *)(iVar6 + 0xa0 + param_2 * 0xb0) == 0) {
    return param_3;
  }
  if (*(int *)(iVar6 + 0xa0 + param_3 * 0xb0) == 0) {
    return param_3;
  }
  if (*param_4 < 1) {
    uVar5 = *(uint *)(iVar6 + 0xa0 + param_2 * 0xb0);
  }
  else {
    uVar5 = *(uint *)(iVar6 + 0xa4 + param_2 * 0xb0);
  }
  if (uVar5 == *(uint *)(iVar6 + 0xa0 + param_3 * 0xb0)) {
    *param_4 = 1;
    return param_3;
  }
  uVar3 = (uint)*(byte *)(param_1 + *(int *)(param_1 + 0xf0) + -1 +
                         (uVar5 - 1) * *(int *)(param_1 + 0xec) +
                         *(int *)(iVar6 + 0xa0 + param_3 * 0xb0));
  if (uVar3 == 0) {
    return param_3;
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0xa4) < 1) goto LAB_000882a8;
  puVar7 = (uint *)(iVar6 + 0xa0);
  puVar8 = (uint *)(iVar6 + 0xa4);
  local_c = (int *)(iVar6 + 0xa8);
  uVar4 = *(uint *)(param_1 + 0xa4) & 3;
  local_14 = puVar7;
  if (*(int *)(param_1 + 0xa4) < 1) {
LAB_0008813d:
    iVar2 = iVar1;
    if ((*local_14 == uVar5) && (*puVar8 == uVar3)) {
LAB_000882d4:
      *param_4 = 1;
      return iVar2;
    }
    if ((*local_c != 0) && ((*puVar8 == uVar5 && (*local_14 == uVar3)))) {
LAB_000882c8:
      *param_4 = -1;
      return iVar2;
    }
    puVar7 = local_14 + 0x2c;
    puVar8 = puVar8 + 0x2c;
    local_c = local_c + 0x2c;
    iVar1 = iVar1 + 1;
    local_14 = puVar7;
    if (*(int *)(param_1 + 0xa4) <= iVar1) goto LAB_000882a8;
  }
  else if (uVar4 != 0) {
    if (1 < uVar4) {
      if (2 < uVar4) {
        iVar2 = iVar1;
        if ((*(uint *)(iVar6 + 0xa0) == uVar5) && (*(uint *)(iVar6 + 0xa4) == uVar3))
        goto LAB_000882d4;
        if ((*local_c != 0) && ((*puVar8 == uVar5 && (*puVar7 == uVar3)))) goto LAB_000882c8;
        local_14 = (uint *)(iVar6 + 0x150);
        puVar8 = (uint *)(iVar6 + 0x154);
        local_c = (int *)(iVar6 + 0x158);
        iVar1 = 1;
      }
      iVar2 = iVar1;
      if ((*local_14 == uVar5) && (*puVar8 == uVar3)) goto LAB_000882d4;
      if ((*local_c != 0) && ((*puVar8 == uVar5 && (*local_14 == uVar3)))) goto LAB_000882c8;
      local_14 = local_14 + 0x2c;
      puVar8 = puVar8 + 0x2c;
      local_c = local_c + 0x2c;
      iVar1 = iVar1 + 1;
    }
    goto LAB_0008813d;
  }
  do {
    iVar2 = iVar1;
    if ((*local_14 == uVar5) && (*puVar8 == uVar3)) goto LAB_000882d4;
    if ((*local_c != 0) && ((*puVar8 == uVar5 && (puVar7 = local_14, *local_14 == uVar3))))
    goto LAB_000882c8;
    iVar2 = iVar1 + 1;
    if ((local_14[0x2c] == uVar5) && (puVar8[0x2c] == uVar3)) goto LAB_000882d4;
    if (((local_c[0x2c] != 0) && (puVar8[0x2c] == uVar5)) &&
       (puVar7 = local_14, local_14[0x2c] == uVar3)) goto LAB_000882c8;
    iVar2 = iVar1 + 2;
    if ((local_14[0x58] == uVar5) && (puVar8[0x58] == uVar3)) goto LAB_000882d4;
    if ((local_c[0x58] != 0) &&
       ((puVar8[0x58] == uVar5 && (puVar7 = local_14, local_14[0x58] == uVar3)))) goto LAB_000882c8;
    iVar2 = iVar1 + 3;
    if ((local_14[0x84] == uVar5) && (puVar8[0x84] == uVar3)) goto LAB_000882d4;
    if (((local_c[0x84] != 0) && (puVar8[0x84] == uVar5)) &&
       (puVar7 = local_14, local_14[0x84] == uVar3)) goto LAB_000882c8;
    puVar8 = puVar8 + 0xb0;
    local_c = local_c + 0xb0;
    iVar1 = iVar1 + 4;
    local_14 = local_14 + 0xb0;
  } while (iVar1 < (int)puVar7[0x29]);
LAB_000882a8:
  (*DAT_001c1114)(1,"error in transition graph");
  return param_3;
}


