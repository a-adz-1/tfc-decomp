// IsUseable__17CBasePlayerWeapon  @ 001257f4
undefined4 IsUseable__17CBasePlayerWeapon(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [12];
  int local_24;
  
  if (*(int *)(param_1 + 0x4c0) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_30);
    iVar2 = *(int *)(param_1 + 0x474);
    iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x144))(param_1);
    iVar2 = *(int *)(iVar2 + 0x8ec + iVar1 * 4);
    if (*(int **)(param_1 + 0xb0) != (int *)0x0) {
      iVar2 = **(int **)(param_1 + 0xb0);
    }
    if ((iVar2 < 1) && (local_24 != -1)) {
      return 0;
    }
  }
  return 1;
}


// IsUseable__6CTFAxe  @ 0012d450
undefined4 IsUseable__6CTFAxe(void)

{
  return 1;
}


