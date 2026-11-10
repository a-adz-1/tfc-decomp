// GetSequenceInfo__FPvP9entvars_sPfT2  @ 0007fa0c
void GetSequenceInfo__FPvP9entvars_sPfT2(int param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_2 + 0x128) < *(int *)(param_1 + 0xa4)) {
      iVar2 = *(int *)(param_2 + 0x128) * 0xb0 + param_1 + *(int *)(param_1 + 0xa8);
      if (1 < *(int *)(iVar2 + 0x38)) {
        *param_3 = (*(float *)(iVar2 + 0x20) * 256.0) / (float)(*(int *)(iVar2 + 0x38) + -1);
        fVar1 = SQRT(*(float *)(iVar2 + 0x54) * *(float *)(iVar2 + 0x54) +
                     *(float *)(iVar2 + 0x50) * *(float *)(iVar2 + 0x50) +
                     *(float *)(iVar2 + 0x4c) * *(float *)(iVar2 + 0x4c));
        *param_4 = fVar1;
        *param_4 = (fVar1 * *(float *)(iVar2 + 0x20)) / (float)(*(int *)(iVar2 + 0x38) + -1);
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


