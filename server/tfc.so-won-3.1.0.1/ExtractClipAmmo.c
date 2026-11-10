// ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon  @ 00111304
void ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_2c [8];
  undefined4 local_24;
  undefined4 local_20;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x110))(param_1,local_2c);
  uVar1 = 0;
  if (*(int *)(param_1 + 0x440) != -1) {
    uVar1 = *(undefined4 *)(param_1 + 0x440);
  }
  (**(code **)(*(int *)(*(int *)(param_2 + 0x3f4) + 0x3d4) + 0x60))
            (*(int *)(param_2 + 0x3f4),uVar1,local_24,local_20,param_1 + 0x438);
  return;
}


