// CheckRangeAttack1__12CBaseMonsterff  @ 000aff1c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CheckRangeAttack1__12CBaseMonsterff(undefined4 param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  
  if (((param_3 <= 64.0) ||
      ((byte)(_FUN_00137e10 < param_3 |
              (byte)((ushort)((ushort)(NAN(_FUN_00137e10) || NAN(param_3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(_FUN_00137e10 == param_3) << 0xe) >> 8)) == 1)) ||
     (param_2 < 0.5)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


