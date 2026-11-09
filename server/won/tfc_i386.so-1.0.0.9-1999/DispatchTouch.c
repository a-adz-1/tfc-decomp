// DispatchTouch__FP7edict_sT0  @ 000a0530
void DispatchTouch__FP7edict_sT0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (gTouchDisabled == 0) {
    if (param_1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(param_1 + 0xd8);
    }
    if (param_2 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = *(int **)(param_2 + 0xd8);
    }
    if (((piVar2 != (int *)0x0) && (piVar1 != (int *)0x0)) &&
       (((*(uint *)(*piVar2 + 0x184) | *(uint *)(*piVar1 + 0x184)) & 0x40000000) == 0)) {
      (**(code **)(piVar2[0xf2] + 0xac))(piVar2,piVar1);
    }
  }
  return;
}


