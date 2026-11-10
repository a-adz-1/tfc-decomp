// VecVelocityForDamage__Ff  @ 000c81dc
float * VecVelocityForDamage__Ff(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  float local_18;
  
  lVar4 = (longdouble)(*DAT_001a7fac)(0xc2c80000,0x42c80000);
  local_18 = (float)lVar4;
  lVar4 = (longdouble)(*DAT_001a7fac)(0xc2c80000,0x42c80000);
  fVar1 = (float)lVar4;
  lVar4 = (longdouble)(*DAT_001a7fac)(0x43480000,0x43960000);
  fVar2 = (float)lVar4;
  if (param_2 <= -50.0) {
    if (-200.0 < param_2) {
      local_18 = local_18 + local_18;
      fVar1 = fVar1 + fVar1;
      fVar3 = fVar2 + fVar2;
      goto LAB_000c82e6;
    }
    fVar3 = 10.0;
  }
  else {
    fVar3 = 0.7;
  }
  local_18 = local_18 * fVar3;
  fVar1 = fVar1 * fVar3;
  fVar3 = fVar3 * fVar2;
LAB_000c82e6:
  *param_1 = local_18;
  param_1[1] = fVar1;
  param_1[2] = fVar3;
  return param_1;
}


