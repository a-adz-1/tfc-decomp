// FreeSound__9CSoundEntii  @ 000e4064
void FreeSound__9CSoundEntii(int param_1,int param_2)

{
  if (pSoundEnt != 0) {
    if (param_2 == -1) {
      *(undefined4 *)(pSoundEnt + 0x3dc) = *(undefined4 *)(param_1 * 0x20 + 0x400 + pSoundEnt);
    }
    else {
      *(undefined4 *)(param_2 * 0x20 + pSoundEnt + 0x400) =
           *(undefined4 *)(param_1 * 0x20 + pSoundEnt + 0x400);
    }
    *(undefined4 *)(param_1 * 0x20 + 0x400 + pSoundEnt) = *(undefined4 *)(pSoundEnt + 0x3d8);
    *(int *)(pSoundEnt + 0x3d8) = param_1;
  }
  return;
}


