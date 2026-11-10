// Center__11CBaseEntity  @ 00112920
float * Center__11CBaseEntity(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = *param_2;
  fVar1 = *(float *)(iVar5 + 0xd4);
  fVar2 = *(float *)(iVar5 + 200);
  fVar3 = *(float *)(iVar5 + 0xd8);
  fVar4 = *(float *)(iVar5 + 0xcc);
  *param_1 = (*(float *)(iVar5 + 0xd0) + *(float *)(iVar5 + 0xc4)) * 0.5;
  param_1[1] = (fVar1 + fVar2) * 0.5;
  param_1[2] = (fVar3 + fVar4) * 0.5;
  return param_1;
}


// Center__5CBeam  @ 000a5ca8
float * Center__5CBeam(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  
  pfVar5 = (float *)GetStartPos__5CBeam(param_2);
  pfVar6 = (float *)GetEndPos__5CBeam(param_2);
  fVar1 = pfVar5[1];
  fVar2 = pfVar6[1];
  fVar3 = pfVar5[2];
  fVar4 = pfVar6[2];
  *param_1 = (*pfVar5 + *pfVar6) * 0.5;
  param_1[1] = (fVar1 + fVar2) * 0.5;
  param_1[2] = (fVar3 + fVar4) * 0.5;
  return param_1;
}


