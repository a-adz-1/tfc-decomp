// InsertSound__9CSoundEntiRC6Vectorif  @ 000f2f8c
void InsertSound__9CSoundEntiRC6Vectorif
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = pSoundEnt;
  if (pSoundEnt != 0) {
    iVar2 = *(int *)(pSoundEnt + 0x458);
    if (iVar2 == -1) {
      (*DAT_0019f794)(1,"Free Sound List is full!\n");
      (*DAT_0019f794)(1,"Could not AllocSound() for InsertSound() (DLL)\n");
    }
    else {
      iVar1 = pSoundEnt + 0x480;
      *(undefined4 *)(pSoundEnt + 0x458) = *(undefined4 *)(iVar2 * 0x20 + iVar1);
      *(undefined4 *)(iVar2 * 0x20 + iVar1) = *(undefined4 *)(iVar3 + 0x45c);
      *(int *)(iVar3 + 0x45c) = iVar2;
      iVar2 = iVar2 * 0x20;
      iVar3 = iVar2 + pSoundEnt;
      *(undefined4 *)(iVar3 + 0x468) = *param_2;
      *(undefined4 *)(iVar3 + 0x46c) = param_2[1];
      *(undefined4 *)(iVar3 + 0x470) = param_2[2];
      *(undefined4 *)(iVar2 + pSoundEnt + 0x474) = param_1;
      *(undefined4 *)(iVar2 + pSoundEnt + 0x478) = param_3;
      *(float *)(iVar2 + pSoundEnt + 0x47c) = *gpGlobals + param_4;
    }
  }
  return;
}


