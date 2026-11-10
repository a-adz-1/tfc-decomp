// erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Pc  @ 0004dd58
int erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Pc
              (int *param_1,int param_2)

{
  int iVar1;
  
  if (1 < *(uint *)(*param_1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(*param_1 + -0x10),1);
  }
  *(undefined1 *)(*param_1 + -4) = 1;
  if (1 < *(uint *)(*param_1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(*param_1 + -0x10),1);
  }
  *(undefined1 *)(*param_1 + -4) = 1;
  iVar1 = *param_1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2 - iVar1,1,0,0);
  if (1 < *(uint *)(*param_1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(*param_1 + -0x10),1);
  }
  *(undefined1 *)(*param_1 + -4) = 1;
  return (param_2 - iVar1) + *param_1;
}


// erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1  @ 0004ddf8
int erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PcT1
              (int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2 - iVar1,param_3 - param_2,0,0);
  if (1 < *(uint *)(*param_1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(*param_1 + -0x10),1);
  }
  *(undefined1 *)(*param_1 + -4) = 1;
  return (param_2 - iVar1) + *param_1;
}


// erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 0004dc98
void erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,param_2,param_3,0,0);
  return;
}


