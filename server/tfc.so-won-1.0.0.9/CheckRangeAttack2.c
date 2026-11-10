// CheckRangeAttack2__12CBaseMonsterff  @ 000c22e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CheckRangeAttack2__12CBaseMonsterff(undefined4 param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  
  if ((((byte)(_FUN_00135ab0 < param_3 |
               (byte)((ushort)((ushort)(NAN(_FUN_00135ab0) || NAN(param_3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_FUN_00135ab0 == param_3) << 0xe) >> 8)) != 1) ||
      (512.0 < param_3)) ||
     (0x3f < (byte)((0.5 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == 0.5) << 0xe) >> 8)) - 1))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


