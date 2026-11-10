// InsertSound__9CSoundEntiRC6Vectorif  @ 000e415c
void InsertSound__9CSoundEntiRC6Vectorif
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  int iVar2;
  
  if (pSoundEnt != 0) {
    iVar1 = IAllocSound__9CSoundEnt(pSoundEnt);
    if (iVar1 == -1) {
      (*DAT_001a7f34)(1,"Could not AllocSound() for InsertSound() (DLL)\n");
    }
    else {
      iVar1 = iVar1 * 0x20;
      iVar2 = iVar1 + pSoundEnt;
      *(undefined4 *)(iVar2 + 1000) = *param_2;
      *(undefined4 *)(iVar2 + 0x3ec) = param_2[1];
      *(undefined4 *)(iVar2 + 0x3f0) = param_2[2];
      *(undefined4 *)(iVar1 + pSoundEnt + 0x3f4) = param_1;
      *(undefined4 *)(iVar1 + pSoundEnt + 0x3f8) = param_3;
      *(float *)(iVar1 + pSoundEnt + 0x3fc) = param_4 + *gpGlobals;
    }
  }
  return;
}


