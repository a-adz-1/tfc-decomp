// VecToYaw__12CBaseMonsterG6Vector  @ 000b3a5c
longdouble VecToYaw__12CBaseMonsterG6Vector(int *param_1,float *param_2)

{
  longdouble lVar1;
  
  if ((((byte)((byte)((ushort)((ushort)NAN(*param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(*param_2 == 0.0) << 0xe) >> 8)) == 0x40) &&
      ((byte)((byte)((ushort)((ushort)NAN(param_2[1]) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2[1] == 0.0) << 0xe) >> 8)) == 0x40)) &&
     ((byte)((byte)((ushort)((ushort)NAN(param_2[2]) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2[2] == 0.0) << 0xe) >> 8)) == 0x40)) {
    lVar1 = (longdouble)*(float *)(*param_1 + 0x54);
  }
  else {
    lVar1 = (longdouble)UTIL_VecToYaw__FRC6Vector(param_2);
  }
  return lVar1;
}


