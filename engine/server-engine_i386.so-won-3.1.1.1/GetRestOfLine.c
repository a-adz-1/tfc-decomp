// GetRestOfLine__9TokenLinei  @ 000cb104
int GetRestOfLine__9TokenLinei(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < *(int *)(param_1 + 0x1200)) {
    iVar1 = *(int *)(param_2 * 4 + param_1 + 0x1000) + 0x800;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


