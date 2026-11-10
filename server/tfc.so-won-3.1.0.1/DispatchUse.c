// DispatchUse__FP7edict_sT0  @ 00085d7c
void DispatchUse__FP7edict_sT0(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (param_1 != 0) {
    piVar2 = *(int **)(param_1 + 0x7c);
  }
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x7c);
  }
  if ((piVar2 != (int *)0x0) && ((*(byte *)(*piVar2 + 0x1a7) & 0x40) == 0)) {
    (**(code **)(piVar2[0xf5] + 0xb0))(piVar2,uVar1,uVar1,3,0);
  }
  return;
}


