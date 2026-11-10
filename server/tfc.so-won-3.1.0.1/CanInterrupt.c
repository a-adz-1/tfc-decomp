// CanInterrupt__12CCineMonster  @ 000dcbf8
undefined4 CanInterrupt__12CCineMonster(int param_1)

{
  int *piVar1;
  
  if (((*(int *)(param_1 + 0x64c) != 0) &&
      (piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x484), piVar1 != (int *)0x0)) &&
     (*(int *)(*piVar1 + 0x170) == 0)) {
    return 1;
  }
  return 0;
}


