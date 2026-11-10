// GetSequenceInfo__FPvP9entvars_sPfT2  @ 00087a1c
void GetSequenceInfo__FPvP9entvars_sPfT2(int param_1,int param_2,float *param_3,float *param_4)

{
  int iVar1;
  float fVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_2 + 0x128) < *(int *)(param_1 + 0xa4)) {
      iVar1 = *(int *)(param_2 + 0x128) * 0xb0 + param_1 + *(int *)(param_1 + 0xa8);
      if (1 < *(int *)(iVar1 + 0x38)) {
        *param_3 = (*(float *)(iVar1 + 0x20) * 256.0) / (float)(*(int *)(iVar1 + 0x38) + -1);
        fVar2 = SQRT(*(float *)(iVar1 + 0x54) * *(float *)(iVar1 + 0x54) +
                     *(float *)(iVar1 + 0x50) * *(float *)(iVar1 + 0x50) +
                     *(float *)(iVar1 + 0x4c) * *(float *)(iVar1 + 0x4c));
        *param_4 = fVar2;
        *param_4 = (fVar2 * *(float *)(iVar1 + 0x20)) / (float)(*(int *)(iVar1 + 0x38) + -1);
        return;
      }
      *param_3 = 256.0;
    }
    else {
      *param_3 = 0.0;
    }
    *param_4 = 0.0;
  }
  return;
}


