// GetGunPosition__12CBaseMonster  @ 000befac
float * GetGunPosition__12CBaseMonster(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  
  iVar8 = *param_2;
  if ((*(byte *)(iVar8 + 0x1a4) & 8) == 0) {
    UTIL_MakeVectors__FRC6Vector(iVar8 + 0x50);
    fVar1 = (float)param_2[0x1a3];
    fVar2 = *(float *)(gpGlobals + 0x2c);
    iVar8 = *param_2;
    fVar3 = *(float *)(iVar8 + 0xc);
    fVar4 = (float)param_2[0x1a2];
    fVar5 = *(float *)(gpGlobals + 0x44);
    fVar6 = (float)param_2[0x1a4];
    fVar7 = *(float *)(gpGlobals + 0x38);
    fVar9 = fVar1 * *(float *)(gpGlobals + 0x30) + *(float *)(iVar8 + 0x10) +
            fVar4 * *(float *)(gpGlobals + 0x48) + fVar6 * *(float *)(gpGlobals + 0x3c);
    *param_1 = *(float *)(gpGlobals + 0x28) * fVar1 + *(float *)(iVar8 + 8) +
               *(float *)(gpGlobals + 0x40) * fVar4 + *(float *)(gpGlobals + 0x34) * fVar6;
    param_1[1] = fVar2 * fVar1 + fVar3 + fVar5 * fVar4 + fVar7 * fVar6;
  }
  else {
    fVar1 = *(float *)(iVar8 + 0xc);
    fVar2 = *(float *)(iVar8 + 0x178);
    fVar9 = *(float *)(iVar8 + 0x10) + *(float *)(iVar8 + 0x17c);
    *param_1 = *(float *)(iVar8 + 8) + *(float *)(iVar8 + 0x174);
    param_1[1] = fVar1 + fVar2;
  }
  param_1[2] = fVar9;
  return param_1;
}


