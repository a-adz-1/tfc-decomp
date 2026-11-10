// ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon  @ 00120e54
void ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_2c [8];
  undefined4 local_24;
  undefined4 local_20;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x118))(param_1,local_2c);
  uVar1 = 0;
  if (*(int *)(param_1 + 0x4b0) != -1) {
    uVar1 = *(undefined4 *)(param_1 + 0x4b0);
  }
  (**(code **)(*(int *)(*(int *)(param_2 + 0x464) + 0x444) + 100))
            (*(int *)(param_2 + 0x464),uVar1,local_24,local_20,param_1 + 0x4a8);
  return;
}


