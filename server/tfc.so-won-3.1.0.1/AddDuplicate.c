// AddDuplicate__15CBasePlayerItemP15CBasePlayerItem  @ 00112468
undefined4 AddDuplicate__15CBasePlayerItemP15CBasePlayerItem(void)

{
  return 0;
}


// AddDuplicate__17CBasePlayerWeaponP15CBasePlayerItem  @ 001107dc
void AddDuplicate__17CBasePlayerWeaponP15CBasePlayerItem(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x44c) == 0) {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x150);
  }
  else {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x14c);
  }
  (*pcVar1)(param_1,param_2);
  return;
}


