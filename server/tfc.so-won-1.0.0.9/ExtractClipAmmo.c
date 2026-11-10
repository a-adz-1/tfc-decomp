// ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon  @ 0011bf70
void ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,local_30);
  uVar1 = 0;
  if (*(int *)(param_1 + 0x410) != -1) {
    uVar1 = *(undefined4 *)(param_1 + 0x410);
  }
  (**(code **)(*(int *)(*(int *)(param_2 + 1000) + 0x3c8) + 0x60))
            (*(int *)(param_2 + 1000),uVar1,local_28,local_24,param_1 + 0x408);
  return;
}


