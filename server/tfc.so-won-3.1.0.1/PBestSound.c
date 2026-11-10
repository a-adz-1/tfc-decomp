// PBestSound__12CBaseMonster  @ 000aefa8
undefined4 PBestSound__12CBaseMonster(undefined4 *param_1)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float *pfVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  float fVar11;
  int local_2c [2];
  float local_24 [9];
  
  puVar8 = &stack0xffffffc0;
  fVar10 = -NAN;
  fVar11 = (float)param_1[0x169];
  if (fVar11 == -NAN) {
    (*DAT_001a7f34)(2,"ERROR! monster %s has no audible sounds!\n",
                    *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    uVar5 = 0;
  }
  else {
    do {
      *(float *)(puVar8 + -4) = fVar11;
      *(undefined4 *)(puVar8 + -8) = 0xaf032;
      pfVar6 = (float *)SoundPointerForIndex__9CSoundEnti();
      puVar9 = puVar8;
      if (pfVar6 != (float *)0x0) {
        *(float **)(puVar8 + -4) = pfVar6;
        *(undefined4 *)(puVar8 + -8) = 0xaf045;
        iVar7 = FIsSound__6CSound();
        if (iVar7 != 0) {
          *(undefined4 *)(puVar8 + 0x14) = *(undefined4 *)(*(int *)(puVar8 + 0x44) + 0x3d4);
          *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(puVar8 + 0x44);
          *(undefined4 *)(puVar8 + -8) = *(undefined4 *)(puVar8 + 0x1c);
          pcVar1 = *(code **)(*(int *)(puVar8 + 0x14) + 0xcc);
          *(code **)(puVar8 + 0x18) = pcVar1;
          *(undefined4 *)(puVar8 + -0xc) = 0xaf07a;
          (*pcVar1)();
          puVar9 = puVar8 + -4;
          fVar2 = *pfVar6 - *(float *)(puVar8 + 0x24);
          fVar4 = pfVar6[1] - *(float *)(puVar8 + 0x28);
          fVar3 = pfVar6[2] - *(float *)(puVar8 + 0x2c);
          *(float *)(puVar8 + 0x30) = fVar2;
          *(float *)(puVar8 + 0x34) = fVar4;
          *(float *)(puVar8 + 0x38) = fVar3;
          *(float *)(puVar8 + 0x20) = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2);
          if (*(float *)(puVar8 + 0x20) < *(float *)(puVar8 + 0x1c)) {
            *(float *)(puVar8 + 0x1c) = *(float *)(puVar8 + 0x20);
            puVar9 = puVar8 + -4;
            fVar10 = fVar11;
          }
        }
      }
      fVar11 = pfVar6[7];
      puVar8 = puVar9;
    } while (fVar11 != -NAN);
    if ((int)fVar10 < 0) {
      uVar5 = 0;
    }
    else {
      *(float *)(puVar9 + -4) = fVar10;
      *(undefined4 *)(puVar9 + -8) = 0xaf0e6;
      uVar5 = SoundPointerForIndex__9CSoundEnti();
    }
  }
  return uVar5;
}


