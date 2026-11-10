// Pop__6CStack  @ 000cb4cc
undefined4 Pop__6CStack(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 400);
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 400) = iVar1 + -1;
    uVar2 = *(undefined4 *)(param_1 + -4 + iVar1 * 4);
  }
  return uVar2;
}


