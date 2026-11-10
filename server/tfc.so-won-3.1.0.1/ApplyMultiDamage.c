// ApplyMultiDamage__FP9entvars_sT0  @ 0010f280
void ApplyMultiDamage__FP9entvars_sT0(undefined4 param_1,undefined4 param_2)

{
  if (gMultiDamage != 0) {
    (**(code **)(*(int *)(gMultiDamage + 0x3d4) + 0x34))
              (gMultiDamage,param_1,param_2,DAT_001b5a24,DAT_001b5a28);
  }
  return;
}


