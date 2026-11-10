// ApplyMultiDamage__FP9entvars_sT0  @ 00126400
void ApplyMultiDamage__FP9entvars_sT0(undefined4 param_1,undefined4 param_2)

{
  if (gMultiDamage != 0) {
    (**(code **)(*(int *)(gMultiDamage + 0x454) + 0x38))
              (gMultiDamage,param_1,param_2,DAT_001ad484,DAT_001ad488);
  }
  return;
}


