// IScheduleFlags__12CBaseMonster  @ 000d96f0
uint IScheduleFlags__12CBaseMonster(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x500) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x478) & *(uint *)(*(int *)(param_1 + 0x500) + 8);
  }
  return uVar1;
}


