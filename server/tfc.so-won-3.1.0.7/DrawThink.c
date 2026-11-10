// DrawThink__11CNodeViewer  @ 000cbaec
void DrawThink__11CNodeViewer(int *param_1)

{
  int local_10;
  
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  local_10 = 0;
  do {
    if (param_1[0x113] == param_1[0x114]) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      FUN_000cbe7c();
      return;
    }
    (*DAT_001c10d8)(0,0x17,0,0);
    (*DAT_001c10e0)(0);
    (*DAT_001c10f4)(*(undefined4 *)(DAT_001c148c + param_1[param_1[0x113] + 0x115] * 0x58));
    (*DAT_001c10f4)(*(undefined4 *)(DAT_001c148c + 4 + param_1[param_1[0x113] + 0x115] * 0x58));
    (*DAT_001c10f4)(*(float *)(DAT_001c148c + 8 + param_1[param_1[0x113] + 0x115] * 0x58) + 8.0);
    (*DAT_001c10f4)(*(undefined4 *)(DAT_001c148c + param_1[param_1[0x113] + 0x195] * 0x58));
    (*DAT_001c10f4)(*(undefined4 *)(DAT_001c148c + 4 + param_1[param_1[0x113] + 0x195] * 0x58));
    (*DAT_001c10f4)(*(float *)(DAT_001c148c + 8 + param_1[param_1[0x113] + 0x195] * 0x58) + 8.0);
    (*DAT_001c10e8)((int)g_sModelIndexLaser);
    (*DAT_001c10e0)(0);
    (*DAT_001c10e0)(0);
    (*DAT_001c10e0)(0xfa);
    (*DAT_001c10e0)(0x28);
    (*DAT_001c10e0)(0);
    (*DAT_001c10e0)((int)ROUND((float)param_1[0x217]));
    (*DAT_001c10e0)((int)ROUND((float)param_1[0x218]));
    (*DAT_001c10e0)((int)ROUND((float)param_1[0x219]));
    (*DAT_001c10e0)(0x80);
    (*DAT_001c10e0)(0);
    (*DAT_001c10dc)();
    param_1[0x113] = param_1[0x113] + 1;
    local_10 = local_10 + 1;
  } while (local_10 < 10);
  return;
}


