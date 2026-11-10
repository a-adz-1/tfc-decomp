// InitializePlane__6CPlaneRC6VectorT1  @ 000cd13c
void InitializePlane__6CPlaneRC6VectorT1(float *param_1,float *param_2,float *param_3)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_1[2] * param_3[2] + param_1[1] * param_3[1] + *param_1 * *param_3;
  param_1[4] = 1.4013e-45;
  return;
}


