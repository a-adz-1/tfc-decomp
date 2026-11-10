// MoveExecute__12CBaseMonsterP11CBaseEntityRC6Vectorf  @ 000c2344
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MoveExecute__12CBaseMonsterP11CBaseEntityRC6Vectorf
               (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  
  if (param_1[0x15b] != param_1[0x188]) {
    param_1[0x15b] = param_1[0x188];
  }
  for (param_4 = (float)param_1[0x119] * *(float *)(*param_1 + 0x138) * param_4;
      (byte)(0.001 < param_4 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_4 == 0.001) << 0xe) >> 8)) == 1;
      param_4 = param_4 - fVar1) {
    fVar1 = param_4;
    if (0x3f < (byte)((param_4 < 16.0 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
                      (byte)((ushort)((ushort)(param_4 == 16.0) << 0xe) >> 8)) - 1)) {
      fVar1 = _FUN_0014e1f0;
    }
    UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi
              (*(undefined4 *)(*param_1 + 0x208),param_1 + param_1[0x183] * 4 + 0x162,fVar1,0);
  }
  return;
}


