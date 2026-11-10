// DispatchUse__FP7edict_sT0  @ 000a05a0
void DispatchUse__FP7edict_sT0(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xd8);
  }
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0xd8);
  }
  if ((piVar2 != (int *)0x0) && ((*(byte *)(*piVar2 + 0x187) & 0x40) == 0)) {
    (**(code **)(piVar2[0xf2] + 0xb0))(piVar2,uVar1,uVar1,3,0);
  }
  return;
}


