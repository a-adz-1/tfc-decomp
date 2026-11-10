// UpdatePlayerSound__11CBasePlayer  @ 000dbb50
void UpdatePlayerSound__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar2 = ClientSoundIndex__9CSoundEntP7edict_s(*(undefined4 *)(*param_1 + 0x1e8));
  puVar3 = (undefined4 *)SoundPointerForIndex__9CSoundEnti(uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    (*DAT_001755b4)(1,"Client lost reserved sound!\n");
  }
  else {
    puVar3[3] = 0;
    iVar4 = *param_1;
    if ((*(byte *)(iVar4 + 0x185) & 2) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (int)ROUND(SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                              *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                              *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20)));
      if (0x200 < iVar4) {
        iVar4 = 0x200;
      }
    }
    if ((*(byte *)(*param_1 + 0x160) & 2) != 0) {
      iVar4 = iVar4 + 100;
    }
    if (iVar4 < param_1[0x186]) {
      param_1[0x185] = param_1[0x186];
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 1;
    }
    else {
      param_1[0x185] = iVar4;
    }
    param_1[0x186] = (int)ROUND((float)param_1[0x186] - gpGlobals[1] * 250.0);
    iVar4 = puVar3[4];
    if (iVar4 < param_1[0x185]) {
      iVar4 = param_1[0x185];
    }
    else if (param_1[0x185] < iVar4) {
      iVar4 = (int)ROUND((float)iVar4 - gpGlobals[1] * 250.0);
      if (iVar4 < param_1[0x185]) {
        iVar4 = 0;
      }
    }
    if (param_1[0x1fb] != 0) {
      iVar4 = 0;
    }
    if ((float)param_1[0x189] < *gpGlobals) {
      param_1[0x187] = 0;
    }
    if (puVar3 != (undefined4 *)0x0) {
      iVar1 = *param_1;
      *puVar3 = *(undefined4 *)(iVar1 + 8);
      puVar3[1] = *(undefined4 *)(iVar1 + 0xc);
      puVar3[2] = *(undefined4 *)(iVar1 + 0x10);
      puVar3[3] = puVar3[3] | 4 | param_1[0x187];
      puVar3[4] = iVar4;
    }
    iVar4 = (int)ROUND((float)param_1[0x188] - gpGlobals[1] * 256.0);
    param_1[0x188] = iVar4;
    if (iVar4 < 0) {
      param_1[0x188] = 0;
    }
  }
  return;
}


