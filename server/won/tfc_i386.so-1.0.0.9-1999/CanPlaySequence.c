// CanPlaySequence__12CBaseMonsterii  @ 000c7550
undefined4 CanPlaySequence__12CBaseMonsterii(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((*(int *)(param_1 + 0x60c) == 0) &&
       (iVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x88))(param_1), iVar1 != 0)) &&
      (*(int *)(param_1 + 0x4e8) != 5)) &&
     (((param_2 != 0 || (*(uint *)(param_1 + 0x4e8) < 2)) ||
      ((*(int *)(param_1 + 0x4ec) == 1 || ((*(int *)(param_1 + 0x4e8) == 3 && (0 < param_3)))))))) {
    return 1;
  }
  return 0;
}


