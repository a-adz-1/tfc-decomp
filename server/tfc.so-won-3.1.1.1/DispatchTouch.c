// DispatchTouch__FP7edict_sT0  @ 0008f05c
void DispatchTouch__FP7edict_sT0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (gTouchDisabled == 0) {
    piVar2 = (int *)0x0;
    if (param_1 != 0) {
      piVar2 = *(int **)(param_1 + 0x7c);
    }
    piVar1 = (int *)0x0;
    if (param_2 != 0) {
      piVar1 = *(int **)(param_2 + 0x7c);
    }
    if (((piVar2 != (int *)0x0) && (piVar1 != (int *)0x0)) &&
       (((*(uint *)(*piVar2 + 0x1a4) | *(uint *)(*piVar1 + 0x1a4)) & 0x40000000) == 0)) {
      (**(code **)(piVar2[0x115] + 0xb4))(piVar2,piVar1);
    }
  }
  return;
}


