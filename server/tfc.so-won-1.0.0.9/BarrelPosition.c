// BarrelPosition__9CFuncTank  @ 000b6580
float * BarrelPosition__9CFuncTank(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_28;
  float fStack_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  (*DAT_00175510)(*param_2 + 0x50,&local_10,&local_1c,&local_28);
  fVar1 = (float)param_2[0x106];
  iVar6 = *param_2;
  fVar2 = *(float *)(iVar6 + 0xc);
  fVar3 = *(float *)(iVar6 + 0x10);
  fVar4 = (float)param_2[0x107];
  fVar5 = (float)param_2[0x108];
  *param_1 = *(float *)(iVar6 + 8) + fVar1 * local_10 + fVar4 * local_1c + fVar5 * local_28;
  param_1[1] = fVar2 + fVar1 * local_c + fVar4 * local_18 + fVar5 * fStack_24;
  param_1[2] = fVar3 + fVar1 * local_8 + fVar4 * local_14 + fVar5 * fStack_20;
  return param_1;
}


