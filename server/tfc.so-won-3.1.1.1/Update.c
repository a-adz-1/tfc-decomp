// Update__13CVoiceGameMgrd  @ 0013b208
void Update__13CVoiceGameMgrd(int param_1,double param_2)

{
  param_2 = *(double *)(param_1 + 0x10) + param_2;
  *(double *)(param_1 + 0x10) = param_2;
  if ((byte)(param_2 < 0.3 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 0.3) << 0xe) >> 8)) != 1) {
    UpdateMasks__13CVoiceGameMgr(param_1);
  }
  return;
}


