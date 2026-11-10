// ShootAtEnemy__12CBaseMonsterRC6Vector  @ 000b6554
float * ShootAtEnemy__12CBaseMonsterRC6Vector(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  float local_34;
  float local_30;
  float local_2c;
  
  piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(param_2 + 0x11f);
  iVar2 = gpGlobals;
  if (piVar6 == (int *)0x0) {
    *param_1 = *(float *)(gpGlobals + 0x28);
    param_1[1] = *(float *)(iVar2 + 0x2c);
    fVar1 = *(float *)(iVar2 + 0x30);
  }
  else {
    (**(code **)(piVar6[0xf5] + 0xd0))(&local_30,piVar6,param_3);
    iVar2 = *piVar6;
    fVar3 = ((local_34 - *(float *)(iVar2 + 8)) + param_2[0x171]) - *param_2;
    fVar5 = ((local_30 - *(float *)(iVar2 + 0xc)) + param_2[0x172]) - param_2[1];
    fVar1 = ((local_2c - *(float *)(iVar2 + 0x10)) + param_2[0x173]) - param_2[2];
    fVar4 = SQRT(fVar1 * fVar1 + fVar5 * fVar5 + fVar3 * fVar3);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) == 0x40) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 1.0;
      return param_1;
    }
    fVar4 = 1.0 / fVar4;
    fVar1 = fVar4 * fVar1;
    *param_1 = fVar4 * fVar3;
    param_1[1] = fVar4 * fVar5;
  }
  param_1[2] = fVar1;
  return param_1;
}


