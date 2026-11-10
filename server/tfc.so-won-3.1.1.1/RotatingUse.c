// RotatingUse__13CFuncRotatingP11CBaseEntityT18USE_TYPEf  @ 00088b88
void RotatingUse__13CFuncRotatingP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 0x10) == 0) {
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x5c))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x5c)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x60))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x60)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 100);
      bVar3 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (bVar3) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),6,*(int *)(iVar2 + 500) + *(int *)(gpGlobals + 0x98)
                 ,param_1[0x118],param_1[0x117],0,100);
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar2 + 0x1f8);
      *(float *)(iVar2 + 0x5c) = *(float *)(iVar2 + 0x44) * fVar1;
      *(float *)(iVar2 + 0x60) = *(float *)(iVar2 + 0x48) * fVar1;
      *(float *)(iVar2 + 100) = fVar1 * *(float *)(iVar2 + 0x4c);
      param_1[3] = -0x10000;
      param_1[4] = (int)Rotate__13CFuncRotating;
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar2 + 0x100) + 10.0;
      goto LAB_00088d7a;
    }
LAB_00088cb3:
    param_1[3] = -0x10000;
    param_1[4] = (int)SpinDown__13CFuncRotating;
  }
  else {
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x5c))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x5c)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar2 + 0x60))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar2 + 0x60)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 100);
      bVar3 = (byte)(DAT_0019f668 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (!bVar3) goto LAB_00088cb3;
    param_1[3] = -0x10000;
    param_1[4] = (int)SpinUp__13CFuncRotating;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,
               *(int *)(*param_1 + 500) + *(int *)(gpGlobals + 0x98),0x3c23d70a,param_1[0x117],0,
               0x1e);
  }
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x100) + 0.1;
LAB_00088d7a:
  *(float *)(iVar2 + 0x104) = fVar1;
  return;
}


