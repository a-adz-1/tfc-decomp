// rbegin__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 000411f0
int * rbegin__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                (int *param_1,int *param_2)

{
  *param_1 = *param_2 + *(int *)(*param_2 + -0x10);
  return param_1;
}


// rbegin__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 00041210
int * rbegin__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                (int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (1 < *(uint *)(iVar2 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_2,*(undefined4 *)(iVar2 + -0x10),1);
    iVar2 = *param_2;
  }
  *(undefined1 *)(iVar2 + -4) = 1;
  iVar2 = *param_2;
  iVar1 = *(int *)(iVar2 + -0x10);
  if (1 < *(uint *)(iVar2 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_2,iVar1,1);
    iVar2 = *param_2;
  }
  *(undefined1 *)(iVar2 + -4) = 1;
  *param_1 = iVar1 + *param_2;
  return param_1;
}


