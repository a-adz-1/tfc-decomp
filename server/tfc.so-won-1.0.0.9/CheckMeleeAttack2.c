// CheckMeleeAttack2__12CBaseMonsterff  @ 000c23b0
undefined4 CheckMeleeAttack2__12CBaseMonsterff(undefined4 param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  
  if ((64.0 < param_3) ||
     (0x3f < (byte)((0.7 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == 0.7) << 0xe) >> 8)) - 1))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


