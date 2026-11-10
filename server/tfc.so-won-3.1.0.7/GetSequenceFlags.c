// GetSequenceFlags__14CBaseAnimating  @ 000bef68
void GetSequenceFlags__14CBaseAnimating(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  GetSequenceFlags__FPvP9entvars_s(uVar1,*param_1);
  return;
}


// GetSequenceFlags__FPvP9entvars_s  @ 000879e8
undefined4 GetSequenceFlags__FPvP9entvars_s(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xa4) <= *(int *)(param_2 + 0x128))) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)
             (*(int *)(param_2 + 0x128) * 0xb0 + 0x24 + param_1 + *(int *)(param_1 + 0xa8));
  }
  return uVar1;
}


