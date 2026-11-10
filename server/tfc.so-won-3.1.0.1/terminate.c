// terminate__Fv  @ 00126b50
undefined * terminate__Fv(void)

{
  undefined *puVar1;
  
  (*(code *)__terminate_func)();
  terminate__Fv(&__DT_PLTGOT);
  puVar1 = __terminate_func;
  __terminate_func = &stack0xfffffffc;
  return puVar1;
}


