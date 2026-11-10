// IsUseable__17CBasePlayerWeapon  @ 00120770
undefined4 IsUseable__17CBasePlayerWeapon(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_2c [12];
  int local_20;
  
  if (*(int *)(param_1 + 0x4b0) < 1) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x118))(param_1,local_2c);
    iVar2 = *(int *)(param_1 + 0x464);
    iVar1 = (**(code **)(*(int *)(param_1 + 0x444) + 0x144))(param_1);
    iVar2 = *(int *)(iVar2 + 0x8c4 + iVar1 * 4);
    if (*(int *)(param_1 + 0xb0) != 0) {
      iVar2 = **(int **)(param_1 + 0xb0);
    }
    if ((iVar2 < 1) && (local_20 != -1)) {
      return 0;
    }
  }
  return 1;
}


// IsUseable__6CTFAxe  @ 00129124
undefined4 IsUseable__6CTFAxe(void)

{
  return 1;
}


