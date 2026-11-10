// FreeList__9CSoundEnt  @ 000f0e9c
undefined4 FreeList__9CSoundEnt(void)

{
  undefined4 uVar1;
  
  if (pSoundEnt == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(pSoundEnt + 0x448);
  }
  return uVar1;
}


