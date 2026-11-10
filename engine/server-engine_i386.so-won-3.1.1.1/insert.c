// insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcUic  @ 0004dc3c
int insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcUic
              (int *param_1,int param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2 - iVar1,0,param_3,(int)param_4);
  if (1 < *(uint *)(*param_1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(*param_1 + -0x10),1);
  }
  *(undefined1 *)(*param_1 + -4) = 1;
  return (param_2 - iVar1) + *param_1;
}


// insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Pcc  @ 0004dbe4
int insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Pcc
              (int *param_1,int param_2,char param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2 - iVar1,0,1,(int)param_3);
  if (1 < *(uint *)(*param_1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(*param_1 + -0x10),1);
  }
  *(undefined1 *)(*param_1 + -4) = 1;
  return (param_2 - iVar1) + *param_1;
}


// insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiPCc  @ 0004dad0
void insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiPCc
               (undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_3 & 3;
  puVar1 = param_3;
  if (uVar3 != 0) {
    puVar2 = param_3;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_3 == '\0') goto LAB_0004db22;
        puVar2 = (uint *)((int)param_3 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004db22;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004db22;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004db22;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004db21;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004db20;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004db20:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004db21:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004db22:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2,0,param_3,(int)puVar2 - (int)param_3);
  return;
}


// insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiPCcUi  @ 0004daa8
void insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiPCcUi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,param_2,0,param_3,param_4);
  return;
}


// insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 0004da78
void insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,param_2,0,param_3,param_4,param_5);
  return;
}


// insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUic  @ 0004db3c
void insert__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUic
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2,0,param_3,(int)param_4);
  return;
}


