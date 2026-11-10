// RampPitchVol__13CFuncRotatingi  @ 000885f4
void RampPitchVol__13CFuncRotatingi(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = *(float *)(*param_1 + 0x5c);
  fVar2 = *(float *)(*param_1 + 0x60);
  if (((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) ||
     (fVar1 = *(float *)(*param_1 + 100),
     (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar2 = fVar1;
  }
  iVar4 = (int)ROUND(fVar2);
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  iVar3 = *param_1;
  fVar1 = *(float *)(iVar3 + 0x44);
  if (((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar1 = *(float *)(iVar3 + 0x48),
     (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(iVar3 + 0x4c);
  }
  iVar5 = (int)ROUND(fVar1 * *(float *)(iVar3 + 0x1f8));
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  iVar6 = (int)ROUND(((float)iVar4 / (float)iVar5) * 70.0 + 30.0);
  if (iVar6 == 100) {
    iVar6 = 99;
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(iVar3 + 0x208),6,*(int *)(iVar3 + 500) + *(int *)(gpGlobals + 0x98),
             (float)param_1[0x118] * ((float)iVar4 / (float)iVar5),param_1[0x117],0xc0,iVar6);
  return;
}


