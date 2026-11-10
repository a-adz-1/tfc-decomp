// SoundPointerForIndex__9CSoundEnti  @ 000f2e38
int SoundPointerForIndex__9CSoundEnti(int param_1)

{
  int iVar1;
  
  if (pSoundEnt == 0) {
    iVar1 = 0;
  }
  else if (param_1 < 0x40) {
    if (param_1 < 0) {
      (*DAT_0019f794)(1,"SoundPointerForIndex() - Index < 0!\n");
      iVar1 = 0;
    }
    else {
      iVar1 = pSoundEnt + 0x468 + param_1 * 0x20;
    }
  }
  else {
    (*DAT_0019f794)(1,"SoundPointerForIndex() - Index too large!\n");
    iVar1 = 0;
  }
  return iVar1;
}


