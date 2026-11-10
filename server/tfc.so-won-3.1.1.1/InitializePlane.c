// InitializePlane__6CPlaneRC6VectorT1  @ 000cd0bc
void InitializePlane__6CPlaneRC6VectorT1(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  fVar1 = *param_3;
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  param_1[4] = 1.4013e-45;
  param_1[3] = param_1[2] * fVar3 + param_1[1] * fVar2 + *param_1 * fVar1;
  return;
}


