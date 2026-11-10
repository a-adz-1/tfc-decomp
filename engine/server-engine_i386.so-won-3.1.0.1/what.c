// what__C11logic_error  @ 000438b0
undefined * what__C11logic_error(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + -0x10);
  if (iVar1 == 0) {
    puVar2 = &DAT_000a3d88;
  }
  else {
    *(undefined1 *)(iVar1 + *(int *)(param_1 + 4)) = 0;
    puVar2 = *(undefined **)(param_1 + 4);
  }
  return puVar2;
}


// what__C13runtime_error  @ 000433f0
undefined * what__C13runtime_error(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + -0x10);
  if (iVar1 == 0) {
    puVar2 = &DAT_000a3d88;
  }
  else {
    *(undefined1 *)(iVar1 + *(int *)(param_1 + 4)) = 0;
    puVar2 = *(undefined **)(param_1 + 4);
  }
  return puVar2;
}


// what__C9bad_alloc  @ 000a1710
char * what__C9bad_alloc(void)

{
  return "bad_alloc";
}


// what__C9exception  @ 000a1510
undefined4 what__C9exception(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 4))();
  return *puVar1;
}


