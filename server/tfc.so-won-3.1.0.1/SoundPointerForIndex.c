// SoundPointerForIndex__9CSoundEnti  @ 000e442c
int SoundPointerForIndex__9CSoundEnti(int param_1)

{
  char *pcVar1;
  
  if (pSoundEnt != 0) {
    if (param_1 < 0x40) {
      if (-1 < param_1) {
        return pSoundEnt + 1000 + param_1 * 0x20;
      }
      pcVar1 = "SoundPointerForIndex() - Index < 0!\n";
    }
    else {
      pcVar1 = "SoundPointerForIndex() - Index too large!\n";
    }
    (*DAT_001a7f34)(1,pcVar1);
  }
  return 0;
}


