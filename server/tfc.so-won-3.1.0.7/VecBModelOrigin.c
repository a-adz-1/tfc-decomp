// VecBModelOrigin__FP9entvars_s  @ 000883a0
float * VecBModelOrigin__FP9entvars_s(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_2 + 0xf8);
  fVar2 = *(float *)(param_2 + 0xfc);
  fVar3 = *(float *)(param_2 + 200);
  fVar4 = *(float *)(param_2 + 0xcc);
  *param_1 = *(float *)(param_2 + 0xc4) + *(float *)(param_2 + 0xf4) * 0.5;
  param_1[1] = fVar3 + fVar1 * 0.5;
  param_1[2] = fVar4 + fVar2 * 0.5;
  return param_1;
}


