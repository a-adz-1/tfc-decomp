// assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc  @ 0004d5ec
void assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
               (undefined4 param_1,uint *param_2)

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
        if ((char)*param_2 == '\0') goto LAB_0004d63a;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_0004d63a;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_0004d63a;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_0004d63a;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_0004d639;
    if ((uVar3 & 0xff0000) == 0) goto LAB_0004d638;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004d638:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004d639:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_0004d63a:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,param_2,(int)puVar2 - (int)param_2);
  return;
}


// assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0004d570
void assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,param_2,param_3);
  return;
}


// assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 0004d4e8
void assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,0,0xffffffff,param_2,param_3,param_4);
  return;
}


// assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic  @ 0004d714
void assign__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
               (undefined4 param_1,undefined4 param_2,char param_3)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,0,0xffffffff,param_2,(int)param_3);
  return;
}


// assign__t18string_char_traits1ZcRcRCc  @ 0004cddc
void assign__t18string_char_traits1ZcRcRCc(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  return;
}


