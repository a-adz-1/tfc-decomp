// IScheduleFlags__12CBaseMonster  @ 000e578c
uint IScheduleFlags__12CBaseMonster(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x570) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x4e8) & *(uint *)(*(int *)(param_1 + 0x570) + 8);
  }
  return uVar1;
}


