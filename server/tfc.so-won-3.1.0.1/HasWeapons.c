// HasWeapons__11CBasePlayer  @ 000cfce0
undefined4 HasWeapons__11CBasePlayer(int param_1)

{
  undefined4 uVar1;
  
  if ((((*(int *)(param_1 + 0x82c) == 0) && (*(int *)(param_1 + 0x830) == 0)) &&
      (*(int *)(param_1 + 0x834) == 0)) &&
     (((*(int *)(param_1 + 0x838) == 0 && (*(int *)(param_1 + 0x83c) == 0)) &&
      (*(int *)(param_1 + 0x840) == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


