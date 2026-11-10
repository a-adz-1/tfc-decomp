// MoveExecute__12CBaseMonsterP11CBaseEntityRC6Vectorf  @ 000b2488
void MoveExecute__12CBaseMonsterP11CBaseEntityRC6Vectorf
               (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  float local_8;
  
  if (param_1[0x13b] != param_1[0x168]) {
    param_1[0x13b] = param_1[0x168];
  }
  for (param_4 = (float)param_1[0xf9] * *(float *)(*param_1 + 0x138) * param_4;
      (byte)(0.001 < param_4 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_4 == 0.001) << 0xe) >> 8)) == 1;
      param_4 = param_4 - local_8) {
    local_8 = param_4;
    if (16.0 < param_4) {
      local_8 = 16.0;
    }
    UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi
              (*(undefined4 *)(*param_1 + 0x208),param_1 + param_1[0x163] * 4 + 0x142,local_8,0);
  }
  return;
}


