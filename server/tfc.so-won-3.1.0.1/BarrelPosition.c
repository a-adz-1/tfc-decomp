// BarrelPosition__9CFuncTank  @ 000a2b90
float * BarrelPosition__9CFuncTank(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  (*DAT_001a7e90)(*param_2 + 0x50,&local_c,&local_18,&local_24);
  fVar1 = (float)param_2[0x109];
  iVar6 = *param_2;
  fVar2 = *(float *)(iVar6 + 0xc);
  fVar3 = *(float *)(iVar6 + 0x10);
  fVar4 = (float)param_2[0x10a];
  fVar5 = (float)param_2[0x10b];
  *param_1 = *(float *)(iVar6 + 8) + fVar1 * local_c + fVar4 * local_18 + fVar5 * local_24;
  param_1[1] = fVar2 + fVar1 * local_8 + fVar4 * local_14 + fVar5 * local_20;
  param_1[2] = fVar3 + fVar1 * local_4 + fVar4 * local_10 + fVar5 * local_1c;
  return param_1;
}


