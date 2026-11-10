// Sys_FloatTime  @ 10085f90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 Sys_FloatTime(void)

{
  uint uVar1;
  ulonglong local_10;
  LARGE_INTEGER local_8;
  
                    /* 0x85f90  59  Sys_FloatTime */
  FUN_1009ebc6();
  QueryPerformanceCounter(&local_8);
  uVar1 = local_8.s.HighPart << (0x20 - DAT_104c13f8 & 0x1f) |
          local_8.s.LowPart >> (DAT_104c13f8 & 0x1f);
  if (DAT_100db310 == 0) {
    if ((DAT_104c13f4 < uVar1) || (0xfffffff < DAT_104c13f4 - uVar1)) {
      local_10 = (ulonglong)(uVar1 - DAT_104c13f4);
      _DAT_100db2f0 = (double)local_10 * _DAT_104c1400 + _DAT_100db2f0;
      if (_DAT_100db2f0 == (double)CONCAT44(_DAT_100db2fc,_DAT_100db2f8)) {
        DAT_104c0fe8 = DAT_104c0fe8 + 1;
        if (100000 < DAT_104c0fe8) {
          _DAT_100db2f0 = _DAT_100db2f0 + 1.0;
          DAT_104c0fe8 = 0;
        }
      }
      else {
        DAT_104c0fe8 = 0;
      }
      _DAT_100db2fc = DAT_100db2f4;
      _DAT_100db2f8 = DAT_100db2f0;
    }
  }
  else {
    DAT_100db310 = 0;
  }
  DAT_104c13f4 = uVar1;
  FUN_1009ebd3();
  return (float10)_DAT_100db2f0;
}


