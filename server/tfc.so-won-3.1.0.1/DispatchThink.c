// DispatchThink__FP7edict_s  @ 00085dd0
void DispatchThink__FP7edict_s(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x7c);
  }
  if (piVar1 != (int *)0x0) {
    if (((int *)*piVar1)[0x69] < 0) {
      (*DAT_001a7f34)(4,"Dormant entity %s is thinking!!\n",
                      *(int *)*piVar1 + *(int *)(gpGlobals + 0x98));
    }
    (**(code **)(piVar1[0xf5] + 0xa8))(piVar1);
  }
  return;
}


