// HasWeapons__11CBasePlayer  @ 000db3a8
undefined4 HasWeapons__11CBasePlayer(int param_1)

{
  undefined4 uVar1;
  
  if ((((*(int *)(param_1 + 0x89c) == 0) && (*(int *)(param_1 + 0x8a0) == 0)) &&
      (*(int *)(param_1 + 0x8a4) == 0)) &&
     (((*(int *)(param_1 + 0x8a8) == 0 && (*(int *)(param_1 + 0x8ac) == 0)) &&
      (*(int *)(param_1 + 0x8b0) == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


