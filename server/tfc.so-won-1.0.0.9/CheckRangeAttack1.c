// CheckRangeAttack1__12CBaseMonsterff  @ 000c2280
undefined4 CheckRangeAttack1__12CBaseMonsterff(undefined4 param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  
  if ((((byte)(64.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_3 == 64.0) << 0xe) >> 8)) != 1) || (784.0 < param_3))
     || (0x3f < (byte)((0.5 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(param_2 == 0.5) << 0xe) >> 8)) - 1))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


