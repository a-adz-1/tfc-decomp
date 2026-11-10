// CanPlaySequence__12CBaseMonsterii  @ 000c19f4
undefined4 CanPlaySequence__12CBaseMonsterii(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((((*(int *)(param_1 + 0x698) == 0) &&
       (iVar2 = (**(code **)(*(int *)(param_1 + 0x454) + 0x8c))(param_1), iVar2 != 0)) &&
      (uVar1 = *(uint *)(param_1 + 0x574), uVar1 != 5)) &&
     (((param_2 != 0 || (uVar1 < 2)) ||
      ((*(int *)(param_1 + 0x578) == 1 || ((uVar1 == 3 && (0 < param_3)))))))) {
    return 1;
  }
  return 0;
}


