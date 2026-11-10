// SparkStart__9CEnvSparkP11CBaseEntityT18USE_TYPEf  @ 0008c3f0
void SparkStart__9CEnvSparkP11CBaseEntityT18USE_TYPEf(int *param_1)

{
  longdouble lVar1;
  
  param_1[7] = -0x10000;
  param_1[8] = (int)SparkStop__9CEnvSparkP11CBaseEntityT18USE_TYPEf;
  param_1[3] = -0x10000;
  param_1[4] = (int)SparkThink__9CEnvSpark;
  lVar1 = (longdouble)(*DAT_0019f80c)(0,param_1[0x116]);
  *(float *)(*param_1 + 0x104) = (float)((longdouble)0.1 + lVar1 + (longdouble)*gpGlobals);
  return;
}


