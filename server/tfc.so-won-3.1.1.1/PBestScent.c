// PBestScent__12CBaseMonster  @ 000bb538
undefined4 PBestScent__12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  undefined4 uVar6;
  float fVar7;
  float local_1c;
  float local_18;
  
  local_18 = -NAN;
  local_1c = 8192.0;
  fVar7 = (float)param_1[0x189];
  if (fVar7 == -NAN) {
    (*DAT_0019f794)(2,"ERROR! PBestScent() has empty soundlist!\n");
  }
  else {
    do {
      pfVar4 = (float *)SoundPointerForIndex__9CSoundEnti(fVar7);
      iVar5 = FIsScent__6CSound(pfVar4);
      if (iVar5 != 0) {
        iVar5 = *param_1;
        fVar1 = *pfVar4 - *(float *)(iVar5 + 8);
        fVar3 = pfVar4[1] - *(float *)(iVar5 + 0xc);
        fVar2 = pfVar4[2] - *(float *)(iVar5 + 0x10);
        fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
        if (fVar1 < local_1c) {
          local_1c = fVar1;
          local_18 = fVar7;
        }
      }
      fVar7 = pfVar4[7];
    } while (fVar7 != -NAN);
    if (-1 < (int)local_18) {
      uVar6 = SoundPointerForIndex__9CSoundEnti(local_18);
      return uVar6;
    }
  }
  return 0;
}


