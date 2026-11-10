// CanPlaySequence__12CBaseMonsterii  @ 000c13f0
undefined4 CanPlaySequence__12CBaseMonsterii(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((*(int *)(param_1 + 0x688) == 0) &&
       (iVar1 = (**(code **)(*(int *)(param_1 + 0x444) + 0x8c))(param_1), iVar1 != 0)) &&
      (*(int *)(param_1 + 0x564) != 5)) &&
     (((param_2 != 0 || (*(uint *)(param_1 + 0x564) < 2)) ||
      ((*(int *)(param_1 + 0x568) == 1 || ((*(int *)(param_1 + 0x564) == 3 && (0 < param_3)))))))) {
    return 1;
  }
  return 0;
}


