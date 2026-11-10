// DropDelay__9CTestHull  @ 000cbbb0
void DropDelay__9CTestHull(int *param_1)

{
  UTIL_ClientPrintAll__FiPCcN41(4,"Node Graph out of Date. Rebuilding...",0,0,0,0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,DAT_001758cc);
  param_1[3] = -0x10000;
  param_1[4] = (int)CallBuildNodeGraph__9CTestHull;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  return;
}


