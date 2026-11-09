// GetSequenceFlags__14CBaseAnimating  @ 000c5650
void GetSequenceFlags__14CBaseAnimating(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  GetSequenceFlags__FPvP9entvars_t(uVar1,*param_1);
  return;
}


// GetSequenceFlags__FPvP9entvars_t  @ 0009aea0
undefined4 GetSequenceFlags__FPvP9entvars_t(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xa4) <= *(int *)(param_2 + 0x108))) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)
             (*(int *)(param_2 + 0x108) * 0xb0 + 0x24 + param_1 + *(int *)(param_1 + 0xa8));
  }
  return uVar1;
}


