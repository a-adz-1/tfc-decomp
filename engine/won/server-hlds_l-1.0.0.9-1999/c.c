// c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 08098e4c
undefined *
c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(int *param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(*param_1 + -0x10);
  if (iVar1 == 0) {
    puVar2 = &DAT_080a9447;
  }
  else {
    *(undefined1 *)(iVar1 + *param_1) = 0;
    puVar2 = (undefined *)*param_1;
  }
  return puVar2;
}


