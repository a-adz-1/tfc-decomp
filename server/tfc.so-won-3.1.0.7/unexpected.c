// unexpected__Fv  @ 001375b0
int unexpected__Fv(void)

{
  int *piVar1;
  
  (*(code *)__unexpected_func)();
  piVar1 = (int *)__get_eh_info(&__DT_PLTGOT,&stack0xfffffffc);
  return *piVar1 + 8;
}


