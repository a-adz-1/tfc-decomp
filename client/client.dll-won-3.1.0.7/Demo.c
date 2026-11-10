// Demo_ReadBuffer  @ 27015950
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Demo_ReadBuffer(undefined4 param_1,int *param_2)

{
                    /* 0x15950  422  Demo_ReadBuffer */
  if (*param_2 == 0) {
    DAT_2707cd60 = param_2[1];
    if (param_2[1] != 0) {
      DAT_2707cd64 = param_2[2];
      _DAT_2707cd54 = param_2[3];
      _DAT_2707cd58 = param_2[4];
      _DAT_2707cd5c = param_2[5];
      _DAT_2707cd48 = param_2[6];
      _DAT_2707cd4c = param_2[7];
      _DAT_2707cd50 = param_2[8];
    }
    return;
  }
  if (*param_2 != 1) {
    (*DAT_2707c96c)(s_Unknown_demo_buffer_type__skippi_2706558c);
    return;
  }
  _DAT_2707cd44 = param_2[1];
  return;
}


