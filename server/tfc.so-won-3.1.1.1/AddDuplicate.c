// AddDuplicate__15CBasePlayerItemP15CBasePlayerItem  @ 001266d0
undefined4 AddDuplicate__15CBasePlayerItemP15CBasePlayerItem(void)

{
  return 0;
}


// AddDuplicate__17CBasePlayerWeaponP15CBasePlayerItem  @ 00125b18
void AddDuplicate__17CBasePlayerWeaponP15CBasePlayerItem(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x4cc) == 0) {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x454) + 0x158);
  }
  else {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x454) + 0x154);
  }
  (*pcVar1)(param_1,param_2);
  return;
}


