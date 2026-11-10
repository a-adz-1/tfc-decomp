// DropDelay__9CTestHull  @ 000cb620
void DropDelay__9CTestHull(int *param_1)

{
  UTIL_ClientPrintAll__FiPCcN41(4,"Node Graph out of Date. Rebuilding...",0,0,0,0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,DAT_0019fb2c);
  param_1[3] = -0x10000;
  param_1[4] = (int)CallBuildNodeGraph__9CTestHull;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  return;
}


