// BufferRewind__18CSaveRestoreBufferi  @ 00121598
void BufferRewind__18CSaveRestoreBufferi(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) < param_2) {
      param_2 = *(int *)(iVar1 + 8);
    }
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) - param_2;
    *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) - param_2;
  }
  return;
}


