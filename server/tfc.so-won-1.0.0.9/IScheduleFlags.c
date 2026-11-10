// IScheduleFlags__12CBaseMonster  @ 000e4ca0
uint IScheduleFlags__12CBaseMonster(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x4f4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x46c) & *(uint *)(*(int *)(param_1 + 0x4f4) + 8);
  }
  return uVar1;
}


