// SparkThink__9CEnvSpark  @ 0009fe70
void SparkThink__9CEnvSpark(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_0017562c)(0,param_1[0xf3]);
  *(float *)(*param_1 + 0xe4) = (float)((longdouble)0.1 + (longdouble)*gpGlobals + lVar1);
  DoSpark__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


