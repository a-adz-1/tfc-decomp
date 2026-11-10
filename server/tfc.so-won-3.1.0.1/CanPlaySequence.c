// CanPlaySequence__12CBaseMonsterii  @ 000b6190
undefined4 CanPlaySequence__12CBaseMonsterii(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((*(int *)(param_1 + 0x618) == 0) &&
       (iVar1 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x88))(param_1), iVar1 != 0)) &&
      (*(int *)(param_1 + 0x4f4) != 5)) &&
     (((param_2 != 0 || (*(uint *)(param_1 + 0x4f4) < 2)) ||
      ((*(int *)(param_1 + 0x4f8) == 1 || ((*(int *)(param_1 + 0x4f4) == 3 && (0 < param_3)))))))) {
    return 1;
  }
  return 0;
}


