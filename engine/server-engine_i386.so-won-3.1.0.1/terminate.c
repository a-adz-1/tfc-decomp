// terminate__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 00041850
void terminate__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (int *param_1)

{
  *(undefined1 *)(*param_1 + *(int *)(*param_1 + -0x10)) = 0;
  return;
}


// terminate__Fv  @ 000a0e30
undefined * terminate__Fv(void)

{
  undefined *puVar1;
  
  (*(code *)__terminate_func)();
  terminate__Fv(&__DT_PLTGOT);
  puVar1 = __terminate_func;
  __terminate_func = &stack0xfffffffc;
  return puVar1;
}


