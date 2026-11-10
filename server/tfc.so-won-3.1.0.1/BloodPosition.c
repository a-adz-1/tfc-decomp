// BloodPosition__6CBloodP11CBaseEntity  @ 0009a2e4
float * BloodPosition__6CBloodP11CBaseEntity(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  
  if ((*(byte *)(*param_2 + 0x1a0) & 4) != 0) {
    iVar7 = (*DAT_001a7f60)(1);
    if (iVar7 != 0) {
      fVar1 = *(float *)(iVar7 + 0x88);
      fVar2 = *(float *)(iVar7 + 500);
      fVar3 = *(float *)(iVar7 + 0x8c);
      fVar4 = *(float *)(iVar7 + 0x1f8);
      fVar5 = *(float *)(iVar7 + 0x90);
      fVar6 = *(float *)(iVar7 + 0x1fc);
      lVar8 = (longdouble)(*DAT_001a7fac)(0xc1200000,0x41200000);
      lVar9 = (longdouble)(*DAT_001a7fac)(0xc1200000,0x41200000);
      lVar10 = (longdouble)(*DAT_001a7fac)(0xc1200000,0x41200000);
      fVar5 = fVar5 + fVar6 + (float)lVar10;
      *param_1 = fVar1 + fVar2 + (float)lVar8;
      param_1[1] = fVar3 + fVar4 + (float)lVar9;
      goto LAB_0009a3fb;
    }
  }
  iVar7 = *param_2;
  *param_1 = *(float *)(iVar7 + 8);
  param_1[1] = *(float *)(iVar7 + 0xc);
  fVar5 = *(float *)(iVar7 + 0x10);
LAB_0009a3fb:
  param_1[2] = fVar5;
  return param_1;
}


