// VecVelocityForDamage__Ff  @ 000d3b00
float * VecVelocityForDamage__Ff(float *param_1,float param_2)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar2 = (longdouble)(*DAT_0019f80c)(0xc2c80000,0x42c80000);
  lVar3 = (longdouble)(*DAT_0019f80c)(0xc2c80000,0x42c80000);
  lVar4 = (longdouble)(*DAT_0019f80c)(0x43480000,0x43960000);
  if (param_2 <= -50.0) {
    if (-200.0 < param_2) {
      lVar2 = lVar2 + lVar2;
      lVar3 = lVar3 + lVar3;
      lVar5 = lVar4 + lVar4;
      goto LAB_000d3bc6;
    }
    fVar1 = 10.0;
  }
  else {
    fVar1 = 0.7;
  }
  lVar5 = (longdouble)fVar1;
  lVar2 = lVar2 * lVar5;
  lVar3 = lVar3 * lVar5;
  lVar5 = lVar5 * lVar4;
LAB_000d3bc6:
  *param_1 = (float)lVar2;
  param_1[1] = (float)lVar3;
  param_1[2] = (float)lVar5;
  return param_1;
}


