// PBestScent__12CBaseMonster  @ 000af0fc
undefined4 PBestScent__12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float local_14;
  
  fVar7 = -NAN;
  local_14 = 8192.0;
  fVar8 = (float)param_1[0x169];
  if (fVar8 == -NAN) {
    (*DAT_001a7f34)(2,FUN_00137da0);
    uVar4 = 0;
  }
  else {
    do {
      pfVar5 = (float *)SoundPointerForIndex__9CSoundEnti(fVar8);
      iVar6 = FIsScent__6CSound(pfVar5);
      if (iVar6 != 0) {
        iVar6 = *param_1;
        fVar1 = *pfVar5 - *(float *)(iVar6 + 8);
        fVar3 = pfVar5[1] - *(float *)(iVar6 + 0xc);
        fVar2 = pfVar5[2] - *(float *)(iVar6 + 0x10);
        fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
        if (fVar1 < local_14) {
          fVar7 = fVar8;
          local_14 = fVar1;
        }
      }
      fVar8 = pfVar5[7];
    } while (fVar8 != -NAN);
    if ((int)fVar7 < 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = SoundPointerForIndex__9CSoundEnti(fVar7);
    }
  }
  return uVar4;
}


