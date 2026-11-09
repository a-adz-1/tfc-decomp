// Demo_ReadBuffer  @ 2701eb10
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Demo_ReadBuffer(undefined4 param_1,int *param_2)

{
                    /* 0x1eb10  476  Demo_ReadBuffer */
  if (*param_2 == 0) {
    DAT_270a86a0 = param_2[1];
    if (param_2[1] != 0) {
      DAT_270a86a4 = param_2[2];
      _DAT_270a8694 = param_2[3];
      _DAT_270a8698 = param_2[4];
      _DAT_270a869c = param_2[5];
      _DAT_270a8688 = param_2[6];
      _DAT_270a868c = param_2[7];
      _DAT_270a8690 = param_2[8];
    }
    return;
  }
  if (*param_2 != 1) {
    (*DAT_270a826c)(s_Unknown_demo_buffer_type__skippi_27076368);
    return;
  }
  _DAT_270a8684 = param_2[1];
  return;
}


