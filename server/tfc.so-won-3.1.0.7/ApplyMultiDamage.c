// ApplyMultiDamage__FP9entvars_sT0  @ 0011edcc
void ApplyMultiDamage__FP9entvars_sT0(undefined4 param_1,undefined4 param_2)

{
  if (gMultiDamage != 0) {
    (**(code **)(*(int *)(gMultiDamage + 0x444) + 0x38))
              (gMultiDamage,param_1,param_2,DAT_001cede4,DAT_001cede8);
  }
  return;
}


