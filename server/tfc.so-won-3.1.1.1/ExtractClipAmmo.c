// ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon  @ 00125274
void ExtractClipAmmo__17CBasePlayerWeaponP17CBasePlayerWeapon(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_30);
  iVar1 = 0;
  if (*(int *)(param_1 + 0x4c0) != -1) {
    iVar1 = *(int *)(param_1 + 0x4c0);
  }
  (**(code **)(*(int *)(*(int *)(param_2 + 0x474) + 0x454) + 100))
            (*(int *)(param_2 + 0x474),iVar1,local_28,local_24,param_1 + 0x4b8);
  return;
}


