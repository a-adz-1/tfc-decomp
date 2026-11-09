// IsUseable__17CBasePlayerWeapon  @ 0011b8b0
undefined4 IsUseable__17CBasePlayerWeapon(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [12];
  int local_24;
  
  if (*(int *)(param_1 + 0x410) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,local_30);
    iVar2 = *(int *)(param_1 + 1000);
    iVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x13c))(param_1);
    iVar2 = *(int *)(iVar2 + 0x83c + iVar1 * 4);
    if (*(int *)(param_1 + 0xb0) != 0) {
      iVar2 = **(int **)(param_1 + 0xb0);
    }
    if ((iVar2 < 1) && (local_24 != -1)) {
      return 0;
    }
  }
  return 1;
}


// IsUseable__6CTFAxe  @ 000fa440
undefined4 IsUseable__6CTFAxe(void)

{
  return 1;
}


