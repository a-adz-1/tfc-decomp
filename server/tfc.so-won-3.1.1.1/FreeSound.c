// FreeSound__9CSoundEntii  @ 000f3110
void FreeSound__9CSoundEntii(int param_1,int param_2)

{
  if (pSoundEnt != 0) {
    if (param_2 == -1) {
      *(undefined4 *)(pSoundEnt + 0x45c) = *(undefined4 *)(param_1 * 0x20 + 0x480 + pSoundEnt);
    }
    else {
      *(undefined4 *)(param_2 * 0x20 + pSoundEnt + 0x480) =
           *(undefined4 *)(param_1 * 0x20 + pSoundEnt + 0x480);
    }
    *(undefined4 *)(param_1 * 0x20 + 0x480 + pSoundEnt) = *(undefined4 *)(pSoundEnt + 0x458);
    *(int *)(pSoundEnt + 0x458) = param_1;
  }
  return;
}


