// FreeList__9CSoundEnt  @ 000e4400
undefined4 FreeList__9CSoundEnt(void)

{
  undefined4 uVar1;
  
  if (pSoundEnt == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(pSoundEnt + 0x3d8);
  }
  return uVar1;
}


