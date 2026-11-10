// FixupAngles__FR6Vector  @ 000d3190
void FixupAngles__FR6Vector(float *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)Fix__Ff(*param_1);
  *param_1 = (float)lVar1;
  lVar1 = (longdouble)Fix__Ff(param_1[1]);
  param_1[1] = (float)lVar1;
  lVar1 = (longdouble)Fix__Ff(param_1[2]);
  param_1[2] = (float)lVar1;
  return;
}


