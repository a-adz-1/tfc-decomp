// append__11WriteBufferPCvUl  @ 08090b40
void append__11WriteBufferPCvUl(int *param_1,void *param_2,size_t param_3)

{
  if ((uint)param_1[1] <= param_3 + param_1[2]) {
    reallocAndCopy__11WriteBufferUl(param_1,(param_3 + param_1[1]) * 2);
  }
  memcpy((void *)(param_1[2] + *param_1),param_2,param_3);
  param_1[2] = param_1[2] + param_3;
  return;
}


// append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc  @ 08099560
void append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
               (int *param_1,uint *param_2)

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
        if ((char)*param_2 == '\0') goto LAB_080995a8;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_080995a8;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_080995a8;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_080995a8;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_080995a7;
    if ((uVar3 & 0xff0000) == 0) goto LAB_080995a6;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_080995a6:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_080995a7:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_080995a8:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,*(undefined4 *)(*param_1 + -0x10),0,param_2,(int)puVar2 - (int)param_2);
  return;
}


// append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 080995c4
void append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,*(undefined4 *)(*param_1 + -0x10),0,param_2,param_3);
  return;
}


// append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 080995e4
void append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,*(undefined4 *)(*param_1 + -0x10),0,param_2,param_3,param_4);
  return;
}


// append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic  @ 0809953c
void append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
               (int *param_1,undefined4 param_2,char param_3)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,*(undefined4 *)(*param_1 + -0x10),0,param_2,(int)param_3);
  return;
}


