// ExtractAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon  @ 00111278
undefined4 ExtractAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon(int param_1,undefined4 param_2)

{
  undefined4 unaff_EDI;
  undefined1 local_2c [8];
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_10;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x110))(param_1,local_2c);
  if (local_24 != 0) {
    unaff_EDI = AddPrimaryAmmo__17CBasePlayerWeaponiPcii
                          (param_2,*(undefined4 *)(param_1 + 0x44c),local_24,local_10,local_20);
    *(undefined4 *)(param_1 + 0x44c) = 0;
  }
  if (local_1c != 0) {
    unaff_EDI = AddSecondaryAmmo__17CBasePlayerWeaponiPci(param_2,0,local_1c,local_18);
  }
  return unaff_EDI;
}


