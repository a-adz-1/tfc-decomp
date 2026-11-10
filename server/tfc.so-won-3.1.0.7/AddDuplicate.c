// AddDuplicate__15CBasePlayerItemP15CBasePlayerItem  @ 00122018
undefined4 AddDuplicate__15CBasePlayerItemP15CBasePlayerItem(void)

{
  return 0;
}


// AddDuplicate__17CBasePlayerWeaponP15CBasePlayerItem  @ 0012032c
void AddDuplicate__17CBasePlayerWeaponP15CBasePlayerItem(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x4bc) == 0) {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x444) + 0x158);
  }
  else {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x444) + 0x154);
  }
  (*pcVar1)(param_1,param_2);
  return;
}


