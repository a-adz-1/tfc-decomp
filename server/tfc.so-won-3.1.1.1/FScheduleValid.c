// FScheduleValid__12CBaseMonster  @ 000e9074
undefined4 FScheduleValid__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x580) == 0) ||
     ((*(uint *)(param_1 + 0x4f8) & (*(uint *)(*(int *)(param_1 + 0x580) + 8) | 0xc0000000)) != 0))
  {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


