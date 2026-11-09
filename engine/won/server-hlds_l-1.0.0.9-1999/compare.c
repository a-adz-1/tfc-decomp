// compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 080989e4
void compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08098a30;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098a30;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098a30;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08098a30;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08098a2f;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08098a2e;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098a2e:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098a2f:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098a30:
  compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 08097b50
uint compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,byte *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  iVar3 = *param_1;
  if (*(uint *)(iVar3 + -0x10) < param_3) {
    __out_of_range__FPCc("pos > length ()");
    iVar3 = *param_1;
  }
  uVar1 = *(int *)(iVar3 + -0x10) - param_3;
  uVar2 = uVar1;
  if (param_4 < uVar1) {
    uVar2 = param_4;
  }
  bVar6 = false;
  uVar4 = 0;
  bVar7 = true;
  pbVar5 = (byte *)(param_3 + iVar3);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    bVar6 = *pbVar5 < *param_2;
    bVar7 = *pbVar5 == *param_2;
    pbVar5 = pbVar5 + 1;
    param_2 = param_2 + 1;
  } while (bVar7);
  if (!bVar7) {
    uVar4 = -(uint)bVar6 | 1;
  }
  if (uVar4 == 0) {
    uVar4 = uVar1 - param_4;
  }
  return uVar4;
}


// compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 08097ad8
uint compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
               (int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = *param_1;
  if (*(uint *)(iVar5 + -0x10) < param_3) {
    __out_of_range__FPCc("pos > length ()");
    iVar5 = *param_1;
  }
  uVar3 = *(int *)(iVar5 + -0x10) - param_3;
  uVar6 = uVar3;
  if (param_4 < uVar3) {
    uVar6 = param_4;
  }
  uVar1 = *(uint *)((byte *)*param_2 + -0x10);
  if (uVar1 < uVar6) {
    uVar6 = uVar1;
  }
  bVar9 = false;
  uVar2 = 0;
  bVar10 = true;
  uVar4 = uVar6;
  pbVar7 = (byte *)(param_3 + iVar5);
  pbVar8 = (byte *)*param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar9 = *pbVar7 < *pbVar8;
    bVar10 = *pbVar7 == *pbVar8;
    pbVar7 = pbVar7 + 1;
    pbVar8 = pbVar8 + 1;
  } while (bVar10);
  if (!bVar10) {
    uVar2 = -(uint)bVar9 | 1;
  }
  if (uVar2 == 0) {
    if (uVar6 == param_4) {
      uVar2 = 0;
    }
    else {
      uVar2 = uVar3 - uVar1;
    }
  }
  return uVar2;
}


// compare__t18string_char_traits1ZcPCcT1Ui  @ 08099ef4
uint compare__t18string_char_traits1ZcPCcT1Ui(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  uVar1 = 0;
  bVar3 = true;
  do {
    if (param_3 == 0) break;
    param_3 = param_3 + -1;
    bVar2 = *param_1 < *param_2;
    bVar3 = *param_1 == *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (bVar3);
  if (!bVar3) {
    uVar1 = -(uint)bVar2 | 1;
  }
  return uVar1;
}


