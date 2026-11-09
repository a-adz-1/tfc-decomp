// PBestScent__12CBaseMonster  @ 000c1630
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
  float local_18;
  
  fVar8 = -NAN;
  local_18 = 8192.0;
  fVar7 = (float)param_1[0x166];
  if (fVar7 == -NAN) {
    (*DAT_001755b4)(2,FUN_00135a40);
    uVar4 = 0;
  }
  else {
    do {
      pfVar5 = (float *)SoundPointerForIndex__9CSoundEnti(fVar7);
      iVar6 = FIsScent__6CSound(pfVar5);
      if (iVar6 != 0) {
        iVar6 = *param_1;
        fVar1 = *pfVar5 - *(float *)(iVar6 + 8);
        fVar3 = pfVar5[1] - *(float *)(iVar6 + 0xc);
        fVar2 = pfVar5[2] - *(float *)(iVar6 + 0x10);
        fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
        if ((byte)(fVar1 < local_18 |
                   (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_18)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == local_18) << 0xe) >> 8)) == 1) {
          fVar8 = fVar7;
          local_18 = fVar1;
        }
      }
      fVar7 = pfVar5[7];
    } while (fVar7 != -NAN);
    if ((int)fVar8 < 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = SoundPointerForIndex__9CSoundEnti(fVar8);
    }
  }
  return uVar4;
}


