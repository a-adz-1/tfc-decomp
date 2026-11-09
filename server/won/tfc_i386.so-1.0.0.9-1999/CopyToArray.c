// CopyToArray__6CStackPi  @ 000cd5a0
void CopyToArray__6CStackPi(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 400)) {
    do {
      *(undefined4 *)(param_2 + iVar1 * 4) = *(undefined4 *)(param_1 + iVar1 * 4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 400));
  }
  return;
}


