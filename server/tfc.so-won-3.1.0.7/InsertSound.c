// InsertSound__9CSoundEntiRC6Vectorif  @ 000f0bf8
void InsertSound__9CSoundEntiRC6Vectorif
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  int iVar2;
  
  if (pSoundEnt != 0) {
    iVar1 = IAllocSound__9CSoundEnt(pSoundEnt);
    if (iVar1 == -1) {
      (*DAT_001c1114)(1,"Could not AllocSound() for InsertSound() (DLL)\n");
    }
    else {
      iVar1 = iVar1 * 0x20;
      iVar2 = iVar1 + pSoundEnt;
      *(undefined4 *)(iVar2 + 0x458) = *param_2;
      *(undefined4 *)(iVar2 + 0x45c) = param_2[1];
      *(undefined4 *)(iVar2 + 0x460) = param_2[2];
      *(undefined4 *)(iVar1 + pSoundEnt + 0x464) = param_1;
      *(undefined4 *)(iVar1 + pSoundEnt + 0x468) = param_3;
      *(float *)(iVar1 + pSoundEnt + 0x46c) = param_4 + *gpGlobals;
    }
  }
  return;
}


