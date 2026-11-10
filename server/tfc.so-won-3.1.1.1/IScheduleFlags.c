// IScheduleFlags__12CBaseMonster  @ 000e90a4
uint IScheduleFlags__12CBaseMonster(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x580) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x4f8) & *(uint *)(*(int *)(param_1 + 0x580) + 8);
  }
  return uVar1;
}


