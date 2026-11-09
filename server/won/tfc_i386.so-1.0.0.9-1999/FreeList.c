// FreeList__9CSoundEnt  @ 000ee490
undefined4 FreeList__9CSoundEnt(void)

{
  undefined4 uVar1;
  
  if (pSoundEnt == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(pSoundEnt + 0x3cc);
  }
  return uVar1;
}


