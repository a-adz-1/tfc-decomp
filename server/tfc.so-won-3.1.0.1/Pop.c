// Pop__6CStack  @ 000bd2e4
undefined4 Pop__6CStack(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 400) < 1) {
    uVar1 = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + -1;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 400) * 4 + param_1);
  }
  return uVar1;
}


