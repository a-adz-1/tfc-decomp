// FreeSound__9CSoundEntii  @ 000ee160
void FreeSound__9CSoundEntii(int param_1,int param_2)

{
  int iVar1;
  
  if (pSoundEnt != 0) {
    if (param_2 == -1) {
      *(undefined4 *)(pSoundEnt + 0x3d0) = *(undefined4 *)(param_1 * 0x20 + 0x3f4 + pSoundEnt);
    }
    else {
      *(undefined4 *)(param_2 * 0x20 + pSoundEnt + 0x3f4) =
           *(undefined4 *)(param_1 * 0x20 + pSoundEnt + 0x3f4);
    }
    iVar1 = pSoundEnt;
    *(undefined4 *)(param_1 * 0x20 + 0x3f4 + pSoundEnt) = *(undefined4 *)(pSoundEnt + 0x3cc);
    *(int *)(iVar1 + 0x3cc) = param_1;
  }
  return;
}


