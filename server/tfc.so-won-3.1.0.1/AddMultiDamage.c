// AddMultiDamage__FP9entvars_sP11CBaseEntityfi  @ 0010f2cc
void AddMultiDamage__FP9entvars_sP11CBaseEntityfi
               (undefined4 param_1,int param_2,float param_3,uint param_4)

{
  if (param_2 != 0) {
    DAT_001b5a28 = DAT_001b5a28 | param_4;
    if (param_2 != gMultiDamage) {
      ApplyMultiDamage__FP9entvars_sT0(param_1,param_1);
      gMultiDamage = param_2;
      DAT_001b5a24 = 0.0;
    }
    DAT_001b5a24 = param_3 + DAT_001b5a24;
  }
  return;
}


