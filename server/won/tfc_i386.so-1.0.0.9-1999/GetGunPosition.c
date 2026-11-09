// GetGunPosition__12CBaseMonster  @ 000c5d00
float * GetGunPosition__12CBaseMonster(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  
  iVar4 = *param_2;
  if ((*(byte *)(iVar4 + 0x184) & 8) == 0) {
    UTIL_MakeVectors__FRC6Vector(*param_2 + 0x50);
    fVar1 = (float)param_2[0x180];
    iVar4 = *param_2;
    fVar2 = (float)param_2[0x17f];
    fVar3 = (float)param_2[0x181];
    fVar5 = *(float *)(iVar4 + 8) + fVar1 * *(float *)(gpGlobals + 0x28) +
            fVar2 * *(float *)(gpGlobals + 0x40) + fVar3 * *(float *)(gpGlobals + 0x34);
    fVar6 = *(float *)(iVar4 + 0xc) + fVar1 * *(float *)(gpGlobals + 0x2c) +
            fVar2 * *(float *)(gpGlobals + 0x44) + fVar3 * *(float *)(gpGlobals + 0x38);
    fVar1 = *(float *)(iVar4 + 0x10) + fVar1 * *(float *)(gpGlobals + 0x30) +
            fVar2 * *(float *)(gpGlobals + 0x48) + fVar3 * *(float *)(gpGlobals + 0x3c);
  }
  else {
    fVar5 = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x154);
    fVar6 = *(float *)(iVar4 + 0xc) + *(float *)(iVar4 + 0x158);
    fVar1 = *(float *)(iVar4 + 0x10) + *(float *)(iVar4 + 0x15c);
  }
  *param_1 = fVar5;
  param_1[1] = fVar6;
  param_1[2] = fVar1;
  return param_1;
}


