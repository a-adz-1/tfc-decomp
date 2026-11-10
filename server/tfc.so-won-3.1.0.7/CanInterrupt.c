// CanInterrupt__12CCineMonster  @ 000e8c94
undefined4 CanInterrupt__12CCineMonster(int param_1)

{
  int *piVar1;
  
  if (((*(int *)(param_1 + 0x6bc) != 0) &&
      (piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x4f4), piVar1 != (int *)0x0)) &&
     (*(int *)(*piVar1 + 0x170) == 0)) {
    return 1;
  }
  return 0;
}


