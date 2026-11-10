// BarrelPosition__9CFuncTank  @ 000acb6c
float * BarrelPosition__9CFuncTank(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  (*DAT_0019f6f0)(*param_2 + 0x50,&local_10,&local_1c,&local_28);
  fVar1 = (float)param_2[0x129];
  iVar6 = *param_2;
  fVar2 = *(float *)(iVar6 + 0xc);
  fVar3 = *(float *)(iVar6 + 0x10);
  fVar4 = (float)param_2[0x12a];
  fVar5 = (float)param_2[299];
  *param_1 = local_10 * fVar1 + *(float *)(iVar6 + 8) + local_1c * fVar4 + local_28 * fVar5;
  param_1[1] = local_c * fVar1 + fVar2 + local_18 * fVar4 + local_24 * fVar5;
  param_1[2] = fVar1 * local_8 + fVar3 + fVar4 * local_14 + fVar5 * local_20;
  return param_1;
}


