// Demo_ReadBuffer  @ 27015bf0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Demo_ReadBuffer(undefined4 param_1,int *param_2)

{
                    /* 0x15bf0  422  Demo_ReadBuffer */
  if (*param_2 == 0) {
    DAT_27073f38 = param_2[1];
    if (param_2[1] != 0) {
      DAT_27073f3c = param_2[2];
      _DAT_27073f2c = param_2[3];
      _DAT_27073f30 = param_2[4];
      _DAT_27073f34 = param_2[5];
      _DAT_27073f20 = param_2[6];
      _DAT_27073f24 = param_2[7];
      _DAT_27073f28 = param_2[8];
    }
    return;
  }
  if (*param_2 != 1) {
    (*DAT_27073b44)(s_Unknown_demo_buffer_type__skippi_2705f504);
    return;
  }
  _DAT_27073f1c = param_2[1];
  return;
}


