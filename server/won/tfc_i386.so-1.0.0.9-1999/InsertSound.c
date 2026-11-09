// InsertSound__9CSoundEntiRC6Vectorif  @ 000ee240
void InsertSound__9CSoundEntiRC6Vectorif
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (pSoundEnt != 0) {
    iVar3 = IAllocSound__9CSoundEnt(pSoundEnt);
    iVar2 = pSoundEnt;
    if (iVar3 == -1) {
      (*DAT_001755b4)(1,"Could not AllocSound() for InsertSound() (DLL)\n");
    }
    else {
      iVar3 = iVar3 * 0x20;
      iVar1 = pSoundEnt + iVar3;
      *(undefined4 *)(iVar1 + 0x3dc) = *param_2;
      *(undefined4 *)(iVar1 + 0x3e0) = param_2[1];
      *(undefined4 *)(iVar1 + 0x3e4) = param_2[2];
      *(undefined4 *)(iVar3 + 1000 + iVar2) = param_1;
      *(undefined4 *)(iVar3 + 0x3ec + iVar2) = param_3;
      *(float *)(iVar3 + 0x3f0 + iVar2) = param_4 + *gpGlobals;
    }
  }
  return;
}


