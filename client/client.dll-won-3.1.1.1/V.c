// V_CalcRefdef  @ 27045330
void __cdecl V_CalcRefdef(float *param_1)

{
                    /* 0x45330  511  V_CalcRefdef */
  if (param_1[0x11] != 0.0) {
    FUN_27043610(param_1);
    return;
  }
  if ((param_1[0x13] == 0.0) && (DAT_270c28a8 == 0)) {
    if (param_1[0x12] == 0.0) {
      FUN_27043740(param_1);
      return;
    }
    return;
  }
  FUN_27044d50(param_1);
  return;
}


