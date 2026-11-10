// Setup__9CFuncPlat  @ 000cd59c
void Setup__9CFuncPlat(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x123]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x123] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x123] = 0x42a00000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x122]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x122] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x122] = 0x41200000;
  }
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar2 + 0x58) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x10c) = 4;
  *(undefined4 *)(*param_1 + 0x108) = 7;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  iVar2 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,iVar2 + 0xdc,iVar2 + 0xe8);
  (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                  *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  iVar2 = *param_1;
  fVar1 = (float)param_1[0x131];
  param_1[0x124] = *(int *)(iVar2 + 8);
  param_1[0x125] = *(int *)(iVar2 + 0xc);
  param_1[0x126] = *(int *)(iVar2 + 0x10);
  param_1[0x127] = *(int *)(iVar2 + 8);
  param_1[0x128] = *(int *)(iVar2 + 0xc);
  param_1[0x129] = *(int *)(iVar2 + 0x10);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = (*(float *)(iVar2 + 0x10) - *(float *)(iVar2 + 0xfc)) + 8.0;
  }
  else {
    fVar1 = *(float *)(iVar2 + 0x10) - fVar1;
  }
  param_1[0x129] = (int)fVar1;
  fVar1 = *(float *)(*param_1 + 0x1f8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1f8) = 0x43160000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x13f]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x13f] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x13f] = 0x3f59999a;
  }
  return;
}


