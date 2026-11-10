// ActiveList__9CSoundEnt  @ 000f0e70
undefined4 ActiveList__9CSoundEnt(void)

{
  undefined4 uVar1;
  
  if (pSoundEnt == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(pSoundEnt + 0x44c);
  }
  return uVar1;
}


