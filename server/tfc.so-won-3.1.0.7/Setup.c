// Setup__9CFuncPlat  @ 000cd780
void Setup__9CFuncPlat(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x11f]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x11f] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x11f] = 0x42a00000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x11e]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x11e] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x11e] = 0x41200000;
  }
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x54) = DAT_001c0fe4;
  *(undefined4 *)(iVar2 + 0x58) = DAT_001c0fe8;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar2 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,iVar2 + 0xdc,iVar2 + 0xe8);
  (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar2 = *param_1;
  param_1[0x120] = *(int *)(iVar2 + 8);
  param_1[0x121] = *(int *)(iVar2 + 0xc);
  param_1[0x122] = *(int *)(iVar2 + 0x10);
  param_1[0x123] = *(int *)(iVar2 + 8);
  param_1[0x124] = *(int *)(iVar2 + 0xc);
  param_1[0x125] = *(int *)(iVar2 + 0x10);
  fVar1 = (float)param_1[0x12d];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = (*(float *)(*param_1 + 0x10) - *(float *)(*param_1 + 0xfc)) + 8.0;
  }
  else {
    fVar1 = *(float *)(iVar2 + 0x10) - fVar1;
  }
  param_1[0x125] = (int)fVar1;
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x43160000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x13b]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x13b] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x13b] = 0x3f59999a;
  }
  return;
}


