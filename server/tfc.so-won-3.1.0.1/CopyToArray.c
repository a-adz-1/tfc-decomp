// CopyToArray__6CStackPi  @ 000bd324
void CopyToArray__6CStackPi(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 400)) {
    iVar2 = 0;
    do {
      *(undefined4 *)(param_2 + iVar2) = *(undefined4 *)(param_1 + iVar2);
      iVar2 = iVar2 + 4;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 400));
  }
  return;
}


