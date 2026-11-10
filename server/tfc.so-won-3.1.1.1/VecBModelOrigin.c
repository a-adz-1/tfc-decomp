// VecBModelOrigin__FP9entvars_s  @ 0008a194
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
  *param_1 = *(float *)(param_2 + 0xf4) * 0.5 + *(float *)(param_2 + 0xc4);
  param_1[1] = fVar1 * 0.5 + fVar3;
  param_1[2] = fVar2 * 0.5 + fVar4;
  return param_1;
}


