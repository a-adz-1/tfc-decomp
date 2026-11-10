// ActiveList__9CSoundEnt  @ 000f2ee0
undefined4 ActiveList__9CSoundEnt(void)

{
  undefined4 uVar1;
  
  if (pSoundEnt == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(pSoundEnt + 0x45c);
  }
  return uVar1;
}


