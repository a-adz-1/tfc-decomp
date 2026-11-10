// GetToken__9TokenLinei  @ 000cafa8
undefined4 GetToken__9TokenLinei(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x1200)) {
    uVar1 = *(undefined4 *)(param_2 * 4 + param_1 + 0x1000);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


