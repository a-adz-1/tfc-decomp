// SparkThink__9CEnvSpark  @ 0008d550
void SparkThink__9CEnvSpark(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_001c118c)(0,param_1[0x112]);
  *(float *)(*param_1 + 0x104) = (float)((longdouble)0.1 + (longdouble)*gpGlobals + lVar1);
  DoSpark__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


