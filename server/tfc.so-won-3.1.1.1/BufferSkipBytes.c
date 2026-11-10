// BufferSkipBytes__8CRestorei  @ 00120b74
void BufferSkipBytes__8CRestorei(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] - *piVar1 < piVar1[3]) {
      if (piVar1[3] < param_2 + piVar1[2]) {
        (*DAT_0019f794)(4,"Restore overflow!");
        *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 0xc);
      }
      else {
        piVar1[1] = piVar1[1] + param_2;
        *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + param_2;
      }
    }
  }
  return;
}


