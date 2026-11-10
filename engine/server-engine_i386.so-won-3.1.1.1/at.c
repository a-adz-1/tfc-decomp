// at__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e070
int at__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
              (int *param_1,uint param_2)

{
  if (*(uint *)(*param_1 + -0x10) <= param_2) {
    __out_of_range__FPCc("pos >= length ()");
  }
  return param_2 + *param_1;
}


// at__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e01c
int at__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
              (int *param_1,uint param_2)

{
  if (*(uint *)(*param_1 + -0x10) <= param_2) {
    __out_of_range__FPCc("pos >= length ()");
  }
  if (1 < *(uint *)(*param_1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(*param_1 + -0x10),1);
  }
  *(undefined1 *)(*param_1 + -4) = 1;
  return param_2 + *param_1;
}


