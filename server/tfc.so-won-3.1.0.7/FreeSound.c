// FreeSound__9CSoundEntii  @ 000f0b00
void FreeSound__9CSoundEntii(int param_1,int param_2)

{
  if (pSoundEnt != 0) {
    if (param_2 == -1) {
      *(undefined4 *)(pSoundEnt + 0x44c) = *(undefined4 *)(param_1 * 0x20 + 0x470 + pSoundEnt);
    }
    else {
      *(undefined4 *)(param_2 * 0x20 + pSoundEnt + 0x470) =
           *(undefined4 *)(param_1 * 0x20 + pSoundEnt + 0x470);
    }
    *(undefined4 *)(param_1 * 0x20 + 0x470 + pSoundEnt) = *(undefined4 *)(pSoundEnt + 0x448);
    *(int *)(pSoundEnt + 0x448) = param_1;
  }
  return;
}


