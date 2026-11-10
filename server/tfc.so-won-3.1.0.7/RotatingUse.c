// RotatingUse__13CFuncRotatingP11CBaseEntityT18USE_TYPEf  @ 00089878
void RotatingUse__13CFuncRotatingP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x1a0) & 0x10) == 0) {
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(*param_1 + 0x5c))) << 10)
                      >> 8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(*param_1 + 0x5c)) << 0xe) >> 8)) ==
         0x40) &&
       (fVar1 = *(float *)(*param_1 + 0x60),
       (byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(DAT_001c0fe4 == fVar1) << 0xe) >> 8)) == 0x40)) {
      fVar1 = *(float *)(*param_1 + 100);
      bVar3 = (byte)(DAT_001c0fe8 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (bVar3) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,
                 *(int *)(*param_1 + 500) + *(int *)(gpGlobals + 0x98),param_1[0x114],param_1[0x113]
                 ,0,100);
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar2 + 0x1f8);
      *(float *)(iVar2 + 0x5c) = fVar1 * *(float *)(iVar2 + 0x44);
      *(float *)(iVar2 + 0x60) = fVar1 * *(float *)(iVar2 + 0x48);
      *(float *)(iVar2 + 100) = fVar1 * *(float *)(iVar2 + 0x4c);
      param_1[3] = -0x10000;
      param_1[4] = (int)Rotate__13CFuncRotating;
      Rotate__13CFuncRotating(param_1);
      return;
    }
  }
  else {
    bVar3 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x5c))) << 10) >>
                      8) |
               (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x5c)) << 0xe) >> 8)) ==
         0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(*(float *)(iVar2 + 0x60))) << 10)
                     >> 8) |
              (byte)((ushort)((ushort)(DAT_001c0fe4 == *(float *)(iVar2 + 0x60)) << 0xe) >> 8)) ==
        0x40)) {
      fVar1 = *(float *)(iVar2 + 100);
      bVar3 = (byte)(DAT_001c0fe8 < fVar1 |
                     (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
    }
    if (bVar3) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SpinUp__13CFuncRotating;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,
                 *(int *)(*param_1 + 500) + *(int *)(gpGlobals + 0x98),0x3c23d70a,param_1[0x113],0,
                 0x1e);
      *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
      return;
    }
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)SpinDown__13CFuncRotating;
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  return;
}


