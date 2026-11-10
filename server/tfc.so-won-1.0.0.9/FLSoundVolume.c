// FLSoundVolume__12CBaseMonsterP6CSound  @ 000c11e0
longdouble FLSoundVolume__12CBaseMonsterP6CSound(int *param_1,float *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = *param_1;
  fVar2 = *param_2 - *(float *)(iVar1 + 8);
  fVar4 = param_2[1] - *(float *)(iVar1 + 0xc);
  fVar3 = param_2[2] - *(float *)(iVar1 + 0x10);
  return (longdouble)(int)param_2[4] -
         (longdouble)SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2);
}


