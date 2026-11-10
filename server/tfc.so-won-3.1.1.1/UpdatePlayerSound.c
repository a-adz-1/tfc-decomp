// UpdatePlayerSound__11CBasePlayer  @ 000d9088
void UpdatePlayerSound__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar3 = ClientSoundIndex__9CSoundEntP7edict_s(*(undefined4 *)(*param_1 + 0x208));
  puVar4 = (undefined4 *)SoundPointerForIndex__9CSoundEnti(uVar3);
  if (puVar4 == (undefined4 *)0x0) {
    (*DAT_0019f794)(1,"Client lost reserved sound!\n");
  }
  else {
    puVar4[3] = 0;
    iVar5 = *param_1;
    if ((*(byte *)(iVar5 + 0x1a5) & 2) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (int)ROUND(SQRT(*(float *)(iVar5 + 0x28) * *(float *)(iVar5 + 0x28) +
                              *(float *)(iVar5 + 0x24) * *(float *)(iVar5 + 0x24) +
                              *(float *)(iVar5 + 0x20) * *(float *)(iVar5 + 0x20)));
      if (0x200 < iVar5) {
        iVar5 = 0x200;
      }
    }
    if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
      iVar5 = iVar5 + 100;
    }
    if (iVar5 < param_1[0x1af]) {
      param_1[0x1ae] = param_1[0x1af];
      *(byte *)(puVar4 + 3) = *(byte *)(puVar4 + 3) | 1;
    }
    else {
      param_1[0x1ae] = iVar5;
    }
    param_1[0x1af] = (int)ROUND((float)param_1[0x1af] - gpGlobals[1] * 250.0);
    iVar1 = puVar4[4];
    iVar2 = param_1[0x1ae];
    iVar5 = iVar2;
    if (((iVar2 <= iVar1) && (iVar5 = iVar1, iVar2 < iVar1)) &&
       (iVar5 = (int)ROUND((float)iVar1 - gpGlobals[1] * 250.0), iVar5 < iVar2)) {
      iVar5 = 0;
    }
    if (param_1[0x226] != 0) {
      iVar5 = 0;
    }
    if ((float)param_1[0x1b2] < *gpGlobals) {
      param_1[0x1b0] = 0;
    }
    if (puVar4 != (undefined4 *)0x0) {
      iVar1 = *param_1;
      *puVar4 = *(undefined4 *)(iVar1 + 8);
      puVar4[1] = *(undefined4 *)(iVar1 + 0xc);
      puVar4[2] = *(undefined4 *)(iVar1 + 0x10);
      puVar4[3] = puVar4[3] | 4 | param_1[0x1b0];
      puVar4[4] = iVar5;
    }
    iVar5 = (int)ROUND((float)param_1[0x1b1] - gpGlobals[1] * 256.0);
    param_1[0x1b1] = iVar5;
    if (iVar5 < 0) {
      param_1[0x1b1] = 0;
    }
  }
  return;
}


