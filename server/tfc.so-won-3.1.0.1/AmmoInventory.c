// AmmoInventory__11CBasePlayeri  @ 000d1080
undefined4 AmmoInventory__11CBasePlayeri(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == -1) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x850 + param_2 * 4);
  }
  return uVar1;
}


