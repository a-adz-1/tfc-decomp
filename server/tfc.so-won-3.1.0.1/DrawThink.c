// DrawThink__11CNodeViewer  @ 000c080c
void DrawThink__11CNodeViewer(int *param_1)

{
  int local_10;
  
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  local_10 = 0;
  do {
    if (param_1[0xf7] == param_1[0xf8]) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
    (*DAT_001a7ef8)(0,0x17,0,0);
    (*DAT_001a7f00)(0);
    (*DAT_001a7f14)(*(undefined4 *)(DAT_001a82ac + param_1[param_1[0xf7] + 0xf9] * 0x58));
    (*DAT_001a7f14)(*(undefined4 *)(DAT_001a82ac + 4 + param_1[param_1[0xf7] + 0xf9] * 0x58));
    (*DAT_001a7f14)(*(float *)(DAT_001a82ac + 8 + param_1[param_1[0xf7] + 0xf9] * 0x58) + 8.0);
    (*DAT_001a7f14)(*(undefined4 *)(DAT_001a82ac + param_1[param_1[0xf7] + 0x179] * 0x58));
    (*DAT_001a7f14)(*(undefined4 *)(DAT_001a82ac + 4 + param_1[param_1[0xf7] + 0x179] * 0x58));
    (*DAT_001a7f14)(*(float *)(DAT_001a82ac + 8 + param_1[param_1[0xf7] + 0x179] * 0x58) + 8.0);
    (*DAT_001a7f08)((int)g_sModelIndexLaser);
    (*DAT_001a7f00)(0);
    (*DAT_001a7f00)(0);
    (*DAT_001a7f00)(0xfa);
    (*DAT_001a7f00)(0x28);
    (*DAT_001a7f00)(0);
    (*DAT_001a7f00)((int)ROUND((float)param_1[0x1fb]));
    (*DAT_001a7f00)((int)ROUND((float)param_1[0x1fc]));
    (*DAT_001a7f00)((int)ROUND((float)param_1[0x1fd]));
    (*DAT_001a7f00)(0x80);
    (*DAT_001a7f00)(0);
    (*DAT_001a7efc)();
    param_1[0xf7] = param_1[0xf7] + 1;
    local_10 = local_10 + 1;
  } while (local_10 < 10);
  return;
}


