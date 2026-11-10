// DestroyMapCycle__FP10mapcycle_s  @ 000afe54
void DestroyMapCycle__FP10mapcycle_s(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar1;
    while (puVar3 != puVar1) {
      puVar2 = (undefined4 *)*puVar3;
      __builtin_delete(puVar3);
      puVar3 = puVar2;
    }
    __builtin_delete(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


