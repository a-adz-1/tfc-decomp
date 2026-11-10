// PBestSound__12CBaseMonster  @ 000bb424
undefined4 PBestSound__12CBaseMonster(undefined4 *param_1)

{
  code *pcVar1;
  float fVar2;
  undefined4 uVar3;
  float *pfVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  float fVar8;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  puVar7 = &stack0xffffffc8;
  local_24 = -NAN;
  local_28 = 8192.0;
  fVar8 = (float)param_1[0x189];
  if (fVar8 != -NAN) {
    do {
      *(float *)(puVar7 + -4) = fVar8;
      *(undefined4 *)(puVar7 + -8) = 0xbb492;
      pfVar4 = (float *)SoundPointerForIndex__9CSoundEnti();
      if (pfVar4 != (float *)0x0) {
        *(float **)(puVar7 + -4) = pfVar4;
        *(undefined4 *)(puVar7 + -8) = 0xbb4a1;
        iVar5 = FIsSound__6CSound();
        if (iVar5 != 0) {
          iVar5 = param_1[0x115];
          *(undefined4 **)(puVar7 + -4) = param_1;
          *(float **)(puVar7 + -8) = &local_1c;
          pcVar1 = *(code **)(iVar5 + 0xd4);
          *(undefined4 *)(puVar7 + -0xc) = 0xbb4c4;
          (*pcVar1)();
          local_10 = *pfVar4 - local_1c;
          fStack_c = pfVar4[1] - local_18;
          fStack_8 = pfVar4[2] - local_14;
          puVar6 = puVar7 + -4;
          puVar7 = puVar7 + -4;
          fVar2 = SQRT(fStack_8 * fStack_8 + fStack_c * fStack_c + local_10 * local_10);
          if (fVar2 < local_28) {
            puVar7 = puVar6;
            local_28 = fVar2;
            local_24 = fVar8;
          }
        }
      }
      fVar8 = pfVar4[7];
    } while (fVar8 != -NAN);
    if ((int)local_24 < 0) {
      uVar3 = 0;
    }
    else {
      *(float *)(puVar7 + -4) = local_24;
      *(undefined4 *)(puVar7 + -8) = 0xbb528;
      uVar3 = SoundPointerForIndex__9CSoundEnti();
    }
    return uVar3;
  }
  (*DAT_0019f794)(2,"ERROR! monster %s has no audible sounds!\n",
                  *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
  uVar3 = FUN_000bb52c();
  return uVar3;
}


