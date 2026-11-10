// compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004e524
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
        if ((char)*param_2 == '\0') goto LAB_0004e576;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004e576;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004e576;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004e576;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004e575;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004e574;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e574:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e575:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e576:
  compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0004cd74
uint compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,byte *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  if (*(uint *)(*param_1 + -0x10) < param_3) {
    __out_of_range__FPCc("pos > length ()");
  }
  iVar1 = *(int *)(*param_1 + -0x10);
  uVar2 = iVar1 - param_3;
  if (param_4 < uVar2) {
    uVar2 = param_4;
  }
  bVar5 = false;
  uVar3 = 0;
  bVar6 = true;
  pbVar4 = (byte *)(param_3 + *param_1);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    bVar5 = *pbVar4 < *param_2;
    bVar6 = *pbVar4 == *param_2;
    pbVar4 = pbVar4 + 1;
    param_2 = param_2 + 1;
  } while (bVar6);
  if (!bVar6) {
    uVar3 = -(uint)bVar5 | 1;
  }
  if (uVar3 == 0) {
    uVar3 = (iVar1 - param_3) - param_4;
  }
  return uVar3;
}


// compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 0004ccec
uint compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
               (int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  uint local_c;
  
  if (*(uint *)(*param_1 + -0x10) < param_3) {
    __out_of_range__FPCc("pos > length ()");
  }
  iVar1 = *(int *)(*param_1 + -0x10);
  local_c = iVar1 - param_3;
  if (param_4 < local_c) {
    local_c = param_4;
  }
  uVar2 = *(uint *)((byte *)*param_2 + -0x10);
  if (uVar2 < local_c) {
    local_c = uVar2;
  }
  bVar7 = false;
  uVar3 = 0;
  bVar8 = true;
  uVar4 = local_c;
  pbVar5 = (byte *)(param_3 + *param_1);
  pbVar6 = (byte *)*param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar7 = *pbVar5 < *pbVar6;
    bVar8 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar8);
  if (!bVar8) {
    uVar3 = -(uint)bVar7 | 1;
  }
  if (uVar3 == 0) {
    if (local_c == param_4) {
      uVar3 = 0;
    }
    else {
      uVar3 = (iVar1 - param_3) - uVar2;
    }
  }
  return uVar3;
}


// compare__t18string_char_traits1ZcPCcT1Ui  @ 0004ce54
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


