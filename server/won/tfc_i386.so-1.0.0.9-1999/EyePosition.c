// EyePosition__11CBaseEntity  @ 0010de80
float * EyePosition__11CBaseEntity(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = *param_2;
  fVar1 = *(float *)(iVar5 + 0xc);
  fVar2 = *(float *)(iVar5 + 0x158);
  fVar3 = *(float *)(iVar5 + 0x10);
  fVar4 = *(float *)(iVar5 + 0x15c);
  *param_1 = *(float *)(iVar5 + 8) + *(float *)(iVar5 + 0x154);
  param_1[1] = fVar1 + fVar2;
  param_1[2] = fVar3 + fVar4;
  return param_1;
}


