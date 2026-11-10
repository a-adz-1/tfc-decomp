// FScheduleValid__12CBaseMonster  @ 000d9714
undefined4 FScheduleValid__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x500) == 0) ||
     (((*(uint *)(*(int *)(param_1 + 0x500) + 8) | 0xc0000000) & *(uint *)(param_1 + 0x478)) != 0))
  {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


