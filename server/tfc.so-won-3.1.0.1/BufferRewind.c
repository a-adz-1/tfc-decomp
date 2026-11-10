// BufferRewind__18CSaveRestoreBufferi  @ 0010cf6c
void BufferRewind__18CSaveRestoreBufferi(int *param_1,int param_2)

{
  if (*param_1 != 0) {
    if (*(int *)(*param_1 + 8) < param_2) {
      param_2 = *(int *)(*param_1 + 8);
    }
    *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) - param_2;
    *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) - param_2;
  }
  return;
}


