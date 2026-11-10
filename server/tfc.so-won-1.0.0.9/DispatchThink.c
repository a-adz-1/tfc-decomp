// DispatchThink__FP7edict_s  @ 000a0600
void DispatchThink__FP7edict_s(int param_1)

{
  int *piVar1;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0xd8);
  }
  if (piVar1 != (int *)0x0) {
    if (((int *)*piVar1)[0x61] < 0) {
      (*DAT_001755b4)(4,"Dormant entity %s is thinking!!\n",
                      *(int *)*piVar1 + *(int *)(gpGlobals + 0x98));
    }
    (**(code **)(piVar1[0xf2] + 0xa8))(piVar1);
  }
  return;
}


