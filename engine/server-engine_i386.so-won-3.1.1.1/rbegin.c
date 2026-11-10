// rbegin__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0004e688
int * rbegin__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                (int *param_1,int *param_2)

{
  *param_1 = *param_2 + *(int *)(*param_2 + -0x10);
  return param_1;
}


// rbegin__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0004e61c
int * rbegin__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                (int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (1 < *(uint *)(*param_2 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_2,*(undefined4 *)(*param_2 + -0x10),1);
  }
  *(undefined1 *)(*param_2 + -4) = 1;
  iVar1 = *param_2;
  iVar2 = *(int *)(iVar1 + -0x10);
  if (1 < *(uint *)(iVar1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_2,*(undefined4 *)(iVar1 + -0x10),1);
  }
  *(undefined1 *)(*param_2 + -4) = 1;
  *param_1 = iVar2 + *param_2;
  return param_1;
}


