// SpinUp__13CFuncRotating  @ 00088750
void SpinUp__13CFuncRotating(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
  iVar4 = *param_1;
  fVar1 = *(float *)(iVar4 + 0x1f8) * (float)param_1[0x116];
  *(float *)(iVar4 + 0x5c) = *(float *)(iVar4 + 0x44) * fVar1 + *(float *)(iVar4 + 0x5c);
  *(float *)(iVar4 + 0x60) = *(float *)(iVar4 + 0x48) * fVar1 + *(float *)(iVar4 + 0x60);
  *(float *)(iVar4 + 100) = fVar1 * *(float *)(iVar4 + 0x4c) + *(float *)(iVar4 + 100);
  iVar2 = *param_1;
  iVar4 = (int)ROUND(*(float *)(iVar2 + 0x5c));
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  iVar3 = (int)ROUND(*(float *)(iVar2 + 0x44) * *(float *)(iVar2 + 0x1f8));
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (iVar3 <= iVar4) {
    iVar4 = (int)ROUND(*(float *)(iVar2 + 0x60));
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    iVar3 = (int)ROUND(*(float *)(iVar2 + 0x48) * *(float *)(iVar2 + 0x1f8));
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 <= iVar4) {
      iVar4 = (int)ROUND(*(float *)(iVar2 + 100));
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      iVar3 = (int)ROUND(*(float *)(iVar2 + 0x4c) * *(float *)(iVar2 + 0x1f8));
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar3 <= iVar4) {
        fVar1 = *(float *)(iVar2 + 0x1f8);
        *(float *)(iVar2 + 0x5c) = *(float *)(iVar2 + 0x44) * fVar1;
        *(float *)(iVar2 + 0x60) = *(float *)(iVar2 + 0x48) * fVar1;
        *(float *)(iVar2 + 100) = fVar1 * *(float *)(iVar2 + 0x4c);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),6,
                   *(int *)(*param_1 + 500) + *(int *)(gpGlobals + 0x98),param_1[0x118],
                   param_1[0x117],0xc0,100);
        param_1[3] = -0x10000;
        param_1[4] = (int)Rotate__13CFuncRotating;
        Rotate__13CFuncRotating(param_1);
        return;
      }
    }
  }
  RampPitchVol__13CFuncRotatingi(param_1,1);
  return;
}


