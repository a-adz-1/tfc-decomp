// resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 0004e0dc
void resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
               (undefined4 param_1,undefined4 param_2)

{
  resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
            (param_1,param_2,0);
  return;
}


// resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic  @ 0004c89c
void resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
               (int *param_1,uint param_2,char param_3)

{
  uint uVar1;
  
  if (param_2 == 0xffffffff) {
    __length_error__FPCc(FUN_000df5a8);
  }
  uVar1 = *(uint *)(*param_1 + -0x10);
  if (uVar1 < param_2) {
    replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
              (param_1,*(undefined4 *)(*param_1 + -0x10),0,param_2 - uVar1,(int)param_3);
  }
  else {
    replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
              (param_1,param_2,0xffffffff,0,0);
  }
  return;
}


