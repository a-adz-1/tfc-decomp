// V_CalcRefdef  @ 27036000
void __cdecl V_CalcRefdef(float *param_1)

{
                    /* 0x36000  454  V_CalcRefdef */
  if (param_1[0x11] != 0.0) {
    FUN_270352f0(param_1);
    return;
  }
  if (param_1[0x12] == 0.0) {
    FUN_270353f0(param_1);
  }
  return;
}


