// Center__11CBaseEntity  @ 0010dec0
float * Center__11CBaseEntity(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = *param_2;
  fVar1 = *(float *)(iVar5 + 0xb4);
  fVar2 = *(float *)(iVar5 + 0xa8);
  fVar3 = *(float *)(iVar5 + 0xb8);
  fVar4 = *(float *)(iVar5 + 0xac);
  *param_1 = (*(float *)(iVar5 + 0xb0) + *(float *)(iVar5 + 0xa4)) * 0.5;
  param_1[1] = (fVar1 + fVar2) * 0.5;
  param_1[2] = (fVar3 + fVar4) * 0.5;
  return param_1;
}


// Center__5CBeam  @ 000b0780
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * Center__5CBeam(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  
  pfVar3 = (float *)GetStartPos__5CBeam(param_2);
  pfVar4 = (float *)GetEndPos__5CBeam(param_2);
  fVar1 = (pfVar3[1] + pfVar4[1]) * _FUN_0013001c;
  fVar2 = _FUN_0013001c * (pfVar3[2] + pfVar4[2]);
  *param_1 = (*pfVar3 + *pfVar4) * _FUN_0013001c;
  param_1[1] = fVar1;
  param_1[2] = fVar2;
  return param_1;
}


