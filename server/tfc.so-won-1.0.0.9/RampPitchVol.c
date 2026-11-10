// RampPitchVol__13CFuncRotatingi  @ 0009c2d0
void RampPitchVol__13CFuncRotatingi(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  fVar1 = *(float *)(*param_1 + 0x5c);
  fVar2 = *(float *)(*param_1 + 0x60);
  if (((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar1 = fVar2,
     (byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 100);
  }
  iVar3 = (int)ROUND(fVar1);
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  fVar1 = *(float *)(*param_1 + 0x44);
  if (((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar1 = *(float *)(*param_1 + 0x48),
     (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = *(float *)(*param_1 + 0x4c);
  }
  iVar4 = (int)ROUND(fVar1 * *(float *)(*param_1 + 0x1d8));
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  iVar5 = (int)ROUND(((float)iVar3 / (float)iVar4) * 70.0 + 30.0);
  if (iVar5 == 100) {
    iVar5 = 99;
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),6,
             *(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98),
             ((float)iVar3 / (float)iVar4) * (float)param_1[0xf5],param_1[0xf4],0xc0,iVar5);
  return;
}


