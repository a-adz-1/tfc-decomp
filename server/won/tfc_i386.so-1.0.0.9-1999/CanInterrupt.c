// CanInterrupt__12CCineMonster  @ 000e7c40
undefined4 CanInterrupt__12CCineMonster(int param_1)

{
  int *piVar1;
  
  if (((*(int *)(param_1 + 0x640) != 0) &&
      (piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x478), piVar1 != (int *)0x0)) &&
     (*(int *)(*piVar1 + 0x150) == 0)) {
    return 1;
  }
  return 0;
}


