// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 00041680
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
        if ((char)*param_2 == '\0') goto LAB_000416cc;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_000416cc;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_000416cc;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_000416cc;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_000416cb;
    if ((uVar3 & 0xff0000) == 0) goto LAB_000416ca;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_000416ca:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_000416cb:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_000416cc:
  rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,param_2,param_3,(int)puVar2 - (int)param_2);
  return;
}


// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi  @ 0003feb0
uint rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
               (int *param_1,char *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  uVar2 = *(uint *)(*param_1 + -0x10);
  if (param_4 <= uVar2) {
    uVar2 = uVar2 - param_4;
    if (param_3 < uVar2) {
      uVar2 = param_3;
    }
    if (uVar2 != 0xffffffff) {
      do {
        pcVar3 = (char *)(*param_1 + uVar2);
        if (*pcVar3 == *param_2) {
          bVar5 = true;
          uVar1 = param_4;
          pcVar4 = param_2;
          do {
            if (uVar1 == 0) break;
            uVar1 = uVar1 - 1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            return uVar2;
          }
        }
        bVar5 = uVar2 != 0;
        uVar2 = uVar2 - 1;
      } while (bVar5);
    }
  }
  return 0xffffffff;
}


// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 000416f0
void rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,int *param_2,undefined4 param_3)

{
  rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
            (param_1,*param_2,param_3,*(undefined4 *)(*param_2 + -0x10));
  return;
}


// rfind__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0cUi  @ 0003ff30
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


