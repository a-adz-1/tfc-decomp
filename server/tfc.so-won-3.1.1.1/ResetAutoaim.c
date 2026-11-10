// ResetAutoaim__11CBasePlayer  @ 000e50dc
void ResetAutoaim__11CBasePlayer(int *param_1)

{
  float fVar1;
  
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x27b]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x27b] == 0.0) << 0xe) >> 8)) != 0x40) ||
     (fVar1 = (float)param_1[0x27c],
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    param_1[0x27b] = 0;
    param_1[0x27c] = 0;
    param_1[0x27d] = 0;
    (*DAT_0019f818)(*(undefined4 *)(*param_1 + 0x208),0,0);
  }
  param_1[0x27e] = 0;
  return;
}


