// at__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 00041870
int at__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
              (int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(uint *)(iVar1 + -0x10) <= param_2) {
    __out_of_range__FPCc("pos >= length ()");
    iVar1 = *param_1;
  }
  return iVar1 + param_2;
}


// at__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 000418a0
int at__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
              (int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(uint *)(iVar1 + -0x10) <= param_2) {
    __out_of_range__FPCc("pos >= length ()");
    iVar1 = *param_1;
  }
  if (1 < *(uint *)(iVar1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(iVar1 + -0x10),1);
    iVar1 = *param_1;
  }
  *(undefined1 *)(iVar1 + -4) = 1;
  return param_2 + *param_1;
}


