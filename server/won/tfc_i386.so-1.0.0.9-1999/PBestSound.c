// PBestSound__12CBaseMonster  @ 000c1510
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
  float fVar9;
  float local_24;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  puVar7 = &stack0xffffffc4;
  fVar9 = -NAN;
  local_24 = 8192.0;
  fVar8 = (float)param_1[0x166];
  if (fVar8 == -NAN) {
    (*DAT_001755b4)(2,"ERROR! monster %s has no audible sounds!\n",
                    *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    uVar3 = 0;
  }
  else {
    do {
      *(float *)(puVar7 + -4) = fVar8;
      *(undefined4 *)(puVar7 + -8) = 0xc156e;
      pfVar4 = (float *)SoundPointerForIndex__9CSoundEnti();
      if (pfVar4 != (float *)0x0) {
        *(float **)(puVar7 + -4) = pfVar4;
        *(undefined4 *)(puVar7 + -8) = 0xc157d;
        iVar5 = FIsSound__6CSound();
        if (iVar5 != 0) {
          iVar5 = param_1[0xf2];
          *(undefined4 **)(puVar7 + -4) = param_1;
          *(float **)(puVar7 + -8) = &fStack_1c;
          pcVar1 = *(code **)(iVar5 + 0xcc);
          *(undefined4 *)(puVar7 + -0xc) = 0xc15a3;
          (*pcVar1)();
          puVar6 = puVar7 + -4;
          puVar7 = puVar7 + -4;
          fStack_10 = *pfVar4 - fStack_1c;
          fStack_c = pfVar4[1] - fStack_18;
          fStack_8 = pfVar4[2] - fStack_14;
          fVar2 = SQRT(fStack_8 * fStack_8 + fStack_c * fStack_c + fStack_10 * fStack_10);
          if ((byte)(fVar2 < local_24 |
                     (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_24)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == local_24) << 0xe) >> 8)) == 1) {
            puVar7 = puVar6;
            fVar9 = fVar8;
            local_24 = fVar2;
          }
        }
      }
      fVar8 = pfVar4[7];
    } while (fVar8 != -NAN);
    if ((int)fVar9 < 0) {
      uVar3 = 0;
    }
    else {
      *(float *)(puVar7 + -4) = fVar9;
      *(undefined4 *)(puVar7 + -8) = 0xc1616;
      uVar3 = SoundPointerForIndex__9CSoundEnti();
    }
  }
  return uVar3;
}


