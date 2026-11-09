// VecBModelOrigin__FP9entvars_t  @ 0009b5e0
float * VecBModelOrigin__FP9entvars_t(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_2 + 0xd8);
  fVar2 = *(float *)(param_2 + 0xdc);
  fVar3 = *(float *)(param_2 + 0xa8);
  fVar4 = *(float *)(param_2 + 0xac);
  *param_1 = *(float *)(param_2 + 0xa4) + *(float *)(param_2 + 0xd4) * 0.5;
  param_1[1] = fVar3 + fVar1 * 0.5;
  param_1[2] = fVar4 + fVar2 * 0.5;
  return param_1;
}


