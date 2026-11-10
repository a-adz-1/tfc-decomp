// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004e1e0
void rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
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
        if ((char)*param_2 == '\0') goto LAB_0004e232;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004e232;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004e232;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004e232;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004e231;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004e230;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e230:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e231:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004e232:
  rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0004c9fc
uint rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,char *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  uVar1 = *(uint *)(*param_1 + -0x10);
  if (param_4 <= uVar1) {
    uVar1 = uVar1 - param_4;
    if (param_3 < uVar1) {
      uVar1 = param_3;
    }
    if (uVar1 != 0xffffffff) {
      pcVar3 = (char *)(*param_1 + uVar1);
      do {
        if (*pcVar3 == *param_2) {
          bVar6 = true;
          uVar2 = param_4;
          pcVar4 = pcVar3;
          pcVar5 = param_2;
          do {
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            return uVar1;
          }
        }
        pcVar3 = pcVar3 + -1;
        bVar6 = uVar1 != 0;
        uVar1 = uVar1 - 1;
      } while (bVar6);
    }
  }
  return 0xffffffff;
}


// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e1b8
void rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0004ca6c
uint rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi
               (int *param_1,char param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 != 0) {
    uVar2 = iVar1 - 1;
    if (param_3 < uVar2) {
      uVar2 = param_3;
    }
    if (uVar2 != 0xffffffff) {
      do {
        if (*(char *)(uVar2 + *param_1) == param_2) {
          return uVar2;
        }
        bVar3 = uVar2 != 0;
        uVar2 = uVar2 - 1;
      } while (bVar3);
    }
  }
  return 0xffffffff;
}


