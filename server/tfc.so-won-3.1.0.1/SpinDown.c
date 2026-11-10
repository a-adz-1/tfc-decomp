// SpinDown__13CFuncRotating  @ 000816e0
void SpinDown__13CFuncRotating(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x1f8) * (float)param_1[0xf6];
  *(float *)(iVar2 + 0x5c) = *(float *)(iVar2 + 0x5c) - fVar1 * *(float *)(iVar2 + 0x44);
  *(float *)(iVar2 + 0x60) = *(float *)(iVar2 + 0x60) - fVar1 * *(float *)(iVar2 + 0x48);
  *(float *)(iVar2 + 100) = *(float *)(iVar2 + 100) - fVar1 * *(float *)(iVar2 + 0x4c);
  fVar3 = *(float *)(*param_1 + 0x5c);
  fVar4 = *(float *)(*param_1 + 0x60);
  fVar1 = *(float *)(*param_1 + 0x44);
  if (((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x48),
     (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x4c);
  }
  if (((((0.0 < fVar1) &&
        ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1)) &&
       ((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) != 1)) &&
      (*(float *)(*param_1 + 100) <= 0.0)) ||
     (((0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) && (0.0 <= fVar3))
      && ((0.0 <= fVar4 && (0.0 <= *(float *)(*param_1 + 100))))))) {
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar2 + 0x60) = DAT_001a7e04;
    *(undefined4 *)(iVar2 + 100) = DAT_001a7e08;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,
               *(int *)(*param_1 + 500) + *(int *)(gpGlobals + 0x98),0,0,0x20,
               (int)ROUND((float)param_1[0xf9]));
    param_1[3] = -0x10000;
    param_1[4] = (int)Rotate__13CFuncRotating;
    Rotate__13CFuncRotating(param_1);
  }
  else {
    RampPitchVol__13CFuncRotatingi(param_1,0);
  }
  return;
}


