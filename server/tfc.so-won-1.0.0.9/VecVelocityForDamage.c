// VecVelocityForDamage__Ff  @ 000d6710
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * VecVelocityForDamage__Ff(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  float local_1c;
  
  lVar4 = (longdouble)(*DAT_0017562c)(0xc2c80000,0x42c80000);
  local_1c = (float)lVar4;
  lVar4 = (longdouble)(*DAT_0017562c)(0xc2c80000,0x42c80000);
  fVar1 = (float)lVar4;
  lVar4 = (longdouble)(*DAT_0017562c)(0x43480000,0x43960000);
  fVar2 = (float)lVar4;
  fVar3 = _FUN_00139700;
  if ((byte)(-50.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == -50.0) << 0xe) >> 8)) != 1) {
    if ((byte)(-200.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2 == -200.0) << 0xe) >> 8)) == 1) {
      local_1c = local_1c + local_1c;
      fVar1 = fVar1 + fVar1;
      fVar3 = fVar2 + fVar2;
      goto LAB_000d67cf;
    }
    fVar3 = 10.0;
  }
  local_1c = local_1c * fVar3;
  fVar1 = fVar1 * fVar3;
  fVar3 = fVar3 * fVar2;
LAB_000d67cf:
  *param_1 = local_1c;
  param_1[1] = fVar1;
  param_1[2] = fVar3;
  return param_1;
}


