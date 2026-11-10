// PointOnPlane__6CPlaneRC6Vector  @ 000c1e1c
bool PointOnPlane__6CPlaneRC6Vector(float *param_1,float *param_2)

{
  return (param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2) - param_1[3] <
         0.001;
}


