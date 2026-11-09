// MoveExecute__12CBaseMonsterP11CBaseEntityRC6Vectorf  @ 000c4190
void MoveExecute__12CBaseMonsterP11CBaseEntityRC6Vectorf
               (int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  byte bVar1;
  float local_c;
  
  if (param_1[0x138] != param_1[0x165]) {
    param_1[0x138] = param_1[0x165];
  }
  param_4 = (float)param_1[0xf6] * *(float *)(*param_1 + 0x118) * param_4;
  bVar1 = 0.001 < param_4 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
          (byte)((ushort)((ushort)(param_4 == 0.001) << 0xe) >> 8);
  while (bVar1 == 1) {
    local_c = param_4;
    if ((byte)(16.0 < param_4 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_4 == 16.0) << 0xe) >> 8)) == 1) {
      local_c = 16.0;
    }
    UTIL_MoveToOrigin__FP7edict_sRC6Vectorfi
              (*(undefined4 *)(*param_1 + 0x1e8),param_1 + param_1[0x160] * 4 + 0x13f,local_c,0);
    param_4 = param_4 - local_c;
    bVar1 = 0.001 < param_4 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_4 == 0.001) << 0xe) >> 8);
  }
  return;
}


