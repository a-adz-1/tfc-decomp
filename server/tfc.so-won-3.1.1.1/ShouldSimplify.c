// ShouldSimplify__Fi  @ 000c29b0
undefined4 ShouldSimplify__Fi(uint param_1)

{
  undefined4 uVar1;
  
  if (((param_1 & 0xffffff7f) == 0x10) || ((param_1 & 0x100) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


