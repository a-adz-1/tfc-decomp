// UpdatePlayerSound__11CBasePlayer  @ 000d9750
void UpdatePlayerSound__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar4 = ClientSoundIndex__9CSoundEntP7edict_s(*(undefined4 *)(*param_1 + 0x208));
  puVar5 = (undefined4 *)SoundPointerForIndex__9CSoundEnti(uVar4);
  if (puVar5 == (undefined4 *)0x0) {
    (*DAT_001c1114)(1,"Client lost reserved sound!\n");
  }
  else {
    puVar5[3] = 0;
    iVar6 = *param_1;
    if ((*(byte *)(iVar6 + 0x1a5) & 2) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (int)ROUND(SQRT(*(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
                              *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
                              *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20)));
      if (0x200 < iVar6) {
        iVar6 = 0x200;
      }
    }
    if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
      iVar6 = iVar6 + 100;
    }
    if (iVar6 < param_1[0x1a6]) {
      param_1[0x1a5] = param_1[0x1a6];
      *(byte *)(puVar5 + 3) = *(byte *)(puVar5 + 3) | 1;
    }
    else {
      param_1[0x1a5] = iVar6;
    }
    param_1[0x1a6] = (int)ROUND((float)param_1[0x1a6] - gpGlobals[1] * 250.0);
    iVar6 = puVar5[4];
    if (iVar6 < param_1[0x1a5]) {
      iVar6 = param_1[0x1a5];
    }
    else if (param_1[0x1a5] < iVar6) {
      iVar6 = (int)ROUND((float)iVar6 - gpGlobals[1] * 250.0);
      if (iVar6 < param_1[0x1a5]) {
        iVar6 = 0;
      }
    }
    if (param_1[0x21c] != 0) {
      iVar6 = 0;
    }
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x1a9];
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      param_1[0x1a7] = 0;
    }
    if (puVar5 != (undefined4 *)0x0) {
      iVar3 = *param_1;
      *puVar5 = *(undefined4 *)(iVar3 + 8);
      puVar5[1] = *(undefined4 *)(iVar3 + 0xc);
      puVar5[2] = *(undefined4 *)(iVar3 + 0x10);
      puVar5[3] = puVar5[3] | 4 | param_1[0x1a7];
      puVar5[4] = iVar6;
    }
    iVar6 = (int)ROUND((float)param_1[0x1a8] - gpGlobals[1] * 256.0);
    param_1[0x1a8] = iVar6;
    if (iVar6 < 0) {
      param_1[0x1a8] = 0;
    }
  }
  return;
}


