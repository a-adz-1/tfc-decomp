// BufferReadBytes__8CRestorePci  @ 00120bec
void BufferReadBytes__8CRestorePci(int *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] - *piVar1 < piVar1[3]) {
      if (piVar1[3] < (int)(param_3 + piVar1[2])) {
        (*DAT_0019f794)(4,"Restore overflow!");
        *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 0xc);
      }
      else {
        if (param_2 != (void *)0x0) {
          memcpy(param_2,(void *)piVar1[1],param_3);
          piVar1 = (int *)*param_1;
        }
        piVar1[1] = piVar1[1] + param_3;
        *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + param_3;
      }
    }
  }
  return;
}


