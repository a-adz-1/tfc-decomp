// Setup__9CFuncPlat  @ 000d1350
void Setup__9CFuncPlat(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x100]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x100] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x100] = 0x42a00000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xff]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xff] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0xff] = 0x41200000;
  }
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x54) = DAT_00175484;
  *(undefined4 *)(iVar2 + 0x58) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0xec) = 4;
  *(undefined4 *)(*param_1 + 0xe8) = 7;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  iVar2 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar2,iVar2 + 0xbc,iVar2 + 200);
  (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  iVar2 = *param_1;
  param_1[0x101] = *(int *)(iVar2 + 8);
  param_1[0x102] = *(int *)(iVar2 + 0xc);
  param_1[0x103] = *(int *)(iVar2 + 0x10);
  param_1[0x104] = *(int *)(iVar2 + 8);
  param_1[0x105] = *(int *)(iVar2 + 0xc);
  param_1[0x106] = *(int *)(iVar2 + 0x10);
  fVar1 = (float)param_1[0x10e];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = (*(float *)(*param_1 + 0x10) - *(float *)(*param_1 + 0xdc)) + 8.0;
  }
  else {
    fVar1 = *(float *)(iVar2 + 0x10) - fVar1;
  }
  param_1[0x106] = (int)fVar1;
  fVar1 = *(float *)(*param_1 + 0x1d8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(undefined4 *)(*param_1 + 0x1d8) = 0x43160000;
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x11c]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x11c] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x11c] = 0x3f59999a;
  }
  return;
}


