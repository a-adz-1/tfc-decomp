// ExtractAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon  @ 0011bef0
undefined4 ExtractAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon(int param_1,undefined4 param_2)

{
  undefined4 unaff_ESI;
  undefined1 local_30 [8];
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_14;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,local_30);
  if (local_28 != 0) {
    unaff_ESI = AddPrimaryAmmo__17CBasePlayerWeaponiPcii
                          (param_2,*(undefined4 *)(param_1 + 0x420),local_28,local_14,local_24);
    *(undefined4 *)(param_1 + 0x420) = 0;
  }
  if (local_20 != 0) {
    unaff_ESI = AddSecondaryAmmo__17CBasePlayerWeaponiPci(param_2,0,local_20,local_1c);
  }
  return unaff_ESI;
}


