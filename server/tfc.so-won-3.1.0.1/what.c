// what__C9bad_alloc  @ 00128bd0
char * what__C9bad_alloc(void)

{
  return "bad_alloc";
}


// what__C9exception  @ 00127230
undefined4 what__C9exception(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 4))();
  return *puVar1;
}


