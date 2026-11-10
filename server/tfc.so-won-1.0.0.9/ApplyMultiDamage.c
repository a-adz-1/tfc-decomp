// ApplyMultiDamage__FP9entvars_tT0  @ 0011a2d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ApplyMultiDamage__FP9entvars_tT0(undefined4 param_1,undefined4 param_2)

{
  if (gMultiDamage != 0) {
    (**(code **)(*(int *)(gMultiDamage + 0x3c8) + 0x34))
              (gMultiDamage,param_1,param_2,_DAT_00183024,DAT_00183028);
  }
  return;
}


