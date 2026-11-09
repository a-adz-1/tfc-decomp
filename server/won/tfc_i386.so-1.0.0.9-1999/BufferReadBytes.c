// BufferReadBytes__8CRestorePci  @ 0011a020
void BufferReadBytes__8CRestorePci(int *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  bool bVar2;
  
  if (*param_1 != 0) {
    bVar2 = false;
    if ((*param_1 == 0) || (piVar1 = (int *)*param_1, piVar1[3] <= piVar1[1] - *piVar1)) {
      bVar2 = true;
    }
    if (!bVar2) {
      if (*(int *)(*param_1 + 0xc) < (int)(param_3 + *(int *)(*param_1 + 8))) {
        (*DAT_001755b4)(4,"Restore overflow!");
        *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 0xc);
      }
      else {
        if (param_2 != (void *)0x0) {
          memcpy(param_2,*(void **)(*param_1 + 4),param_3);
        }
        *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + param_3;
        *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + param_3;
      }
    }
  }
  return;
}


