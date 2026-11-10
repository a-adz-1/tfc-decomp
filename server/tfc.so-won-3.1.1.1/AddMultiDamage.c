// AddMultiDamage__FP9entvars_sP11CBaseEntityfi  @ 00126380
void AddMultiDamage__FP9entvars_sP11CBaseEntityfi
               (undefined4 param_1,int param_2,float param_3,uint param_4)

{
  if (param_2 != 0) {
    DAT_001ad488 = DAT_001ad488 | param_4;
    if (param_2 != gMultiDamage) {
      if (gMultiDamage != 0) {
        (**(code **)(*(int *)(gMultiDamage + 0x454) + 0x38))
                  (gMultiDamage,param_1,param_1,DAT_001ad484,DAT_001ad488);
      }
      gMultiDamage = param_2;
      DAT_001ad484 = 0.0;
    }
    DAT_001ad484 = DAT_001ad484 + param_3;
  }
  return;
}


