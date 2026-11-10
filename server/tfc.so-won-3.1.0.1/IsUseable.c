// IsUseable__17CBasePlayerWeapon  @ 00110c20
undefined4 IsUseable__17CBasePlayerWeapon(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_2c [12];
  int local_20;
  
  if (*(int *)(param_1 + 0x440) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x110))(param_1,local_2c);
    iVar2 = *(int *)(param_1 + 0x3f4);
    iVar1 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x13c))(param_1);
    iVar2 = *(int *)(iVar2 + 0x850 + iVar1 * 4);
    if (*(int *)(param_1 + 0xb0) != 0) {
      iVar2 = **(int **)(param_1 + 0xb0);
    }
    if ((iVar2 < 1) && (local_20 != -1)) {
      return 0;
    }
  }
  return 1;
}


// IsUseable__6CTFAxe  @ 00118dfc
undefined4 IsUseable__6CTFAxe(void)

{
  return 1;
}


