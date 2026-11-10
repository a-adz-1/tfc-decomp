// CheckRangeAttack2__12CBaseMonsterff  @ 000bb1cc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CheckRangeAttack2__12CBaseMonsterff(undefined4 param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  
  if (((param_3 <= _FUN_00148760) ||
      ((byte)(512.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_3 == 512.0) << 0xe) >> 8)) == 1)) || (param_2 < 0.5)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


