// AddMultiDamage__FP9entvars_tP11CBaseEntityfi  @ 0011a310
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AddMultiDamage__FP9entvars_tP11CBaseEntityfi
               (undefined4 param_1,int param_2,float param_3,uint param_4)

{
  if (param_2 != 0) {
    DAT_00183028 = DAT_00183028 | param_4;
    if (param_2 != gMultiDamage) {
      ApplyMultiDamage__FP9entvars_tT0(param_1,param_1);
      gMultiDamage = param_2;
      _DAT_00183024 = 0.0;
    }
    _DAT_00183024 = param_3 + _DAT_00183024;
  }
  return;
}


