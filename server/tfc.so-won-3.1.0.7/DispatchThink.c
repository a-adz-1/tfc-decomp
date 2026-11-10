// DispatchThink__FP7edict_s  @ 0008defc
void DispatchThink__FP7edict_s(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x7c);
  }
  if (piVar1 != (int *)0x0) {
    if (((int *)*piVar1)[0x69] < 0) {
      (*DAT_001c1114)(4,"Dormant entity %s is thinking!!\n",
                      *(int *)*piVar1 + *(int *)(gpGlobals + 0x98));
    }
    (**(code **)(piVar1[0x111] + 0xb0))(piVar1);
  }
  return;
}


