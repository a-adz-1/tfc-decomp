// AddMultiDamage__FP9entvars_sP11CBaseEntityfi  @ 0011ee18
void AddMultiDamage__FP9entvars_sP11CBaseEntityfi
               (undefined4 param_1,int param_2,float param_3,uint param_4)

{
  if (param_2 != 0) {
    DAT_001cede8 = DAT_001cede8 | param_4;
    if (param_2 != gMultiDamage) {
      ApplyMultiDamage__FP9entvars_sT0(param_1,param_1);
      gMultiDamage = param_2;
      DAT_001cede4 = 0.0;
    }
    DAT_001cede4 = param_3 + DAT_001cede4;
  }
  return;
}


