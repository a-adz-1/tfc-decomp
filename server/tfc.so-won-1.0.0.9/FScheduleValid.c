// FScheduleValid__12CBaseMonster  @ 000e4ce0
undefined4 FScheduleValid__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x4f4) == 0) ||
     (((*(uint *)(*(int *)(param_1 + 0x4f4) + 8) | 0xc0000000) & *(uint *)(param_1 + 0x46c)) != 0))
  {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


