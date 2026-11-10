// DrawThink__11CNodeViewer  @ 000ca9cc
void DrawThink__11CNodeViewer(int *param_1)

{
  int local_14;
  
  local_14 = 0;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  do {
    if (param_1[0x117] == param_1[0x118]) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
    (*DAT_0019f758)(0,0x17,0,0);
    (*DAT_0019f760)(0);
    (*DAT_0019f774)(*(undefined4 *)(DAT_0019fb2c + param_1[param_1[0x117] + 0x119] * 0x58));
    (*DAT_0019f774)(*(undefined4 *)(DAT_0019fb2c + 4 + param_1[param_1[0x117] + 0x119] * 0x58));
    (*DAT_0019f774)(*(float *)(DAT_0019fb2c + 8 + param_1[param_1[0x117] + 0x119] * 0x58) + 8.0);
    (*DAT_0019f774)(*(undefined4 *)(DAT_0019fb2c + param_1[param_1[0x117] + 0x199] * 0x58));
    (*DAT_0019f774)(*(undefined4 *)(DAT_0019fb2c + 4 + param_1[param_1[0x117] + 0x199] * 0x58));
    (*DAT_0019f774)(*(float *)(DAT_0019fb2c + 8 + param_1[param_1[0x117] + 0x199] * 0x58) + 8.0);
    (*DAT_0019f768)((int)g_sModelIndexLaser);
    (*DAT_0019f760)(0);
    (*DAT_0019f760)(0);
    (*DAT_0019f760)(0xfa);
    (*DAT_0019f760)(0x28);
    (*DAT_0019f760)(0);
    (*DAT_0019f760)((int)ROUND((float)param_1[0x21b]));
    (*DAT_0019f760)((int)ROUND((float)param_1[0x21c]));
    (*DAT_0019f760)((int)ROUND((float)param_1[0x21d]));
    (*DAT_0019f760)(0x80);
    (*DAT_0019f760)(0);
    (*DAT_0019f75c)();
    param_1[0x117] = param_1[0x117] + 1;
    local_14 = local_14 + 1;
  } while (local_14 < 10);
  return;
}


