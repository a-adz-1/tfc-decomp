// DrawThink__11CNodeViewer  @ 000cfd90
void DrawThink__11CNodeViewer(int *param_1)

{
  int local_14;
  
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  local_14 = 0;
  do {
    if (param_1[0xf4] == param_1[0xf5]) {
      UTIL_Remove__FP11CBaseEntity(param_1);
      return;
    }
    (*DAT_00175578)(0,0x17,0,0);
    (*DAT_00175580)(0);
    (*DAT_00175594)(*(undefined4 *)(DAT_001758cc + param_1[param_1[0xf4] + 0xf6] * 0x58));
    (*DAT_00175594)(*(undefined4 *)(DAT_001758cc + 4 + param_1[param_1[0xf4] + 0xf6] * 0x58));
    (*DAT_00175594)(*(float *)(DAT_001758cc + 8 + param_1[param_1[0xf4] + 0xf6] * 0x58) + 8.0);
    (*DAT_00175594)(*(undefined4 *)(DAT_001758cc + param_1[param_1[0xf4] + 0x176] * 0x58));
    (*DAT_00175594)(*(undefined4 *)(DAT_001758cc + 4 + param_1[param_1[0xf4] + 0x176] * 0x58));
    (*DAT_00175594)(*(float *)(DAT_001758cc + 8 + param_1[param_1[0xf4] + 0x176] * 0x58) + 8.0);
    (*DAT_00175588)((int)g_sModelIndexLaser);
    (*DAT_00175580)(0);
    (*DAT_00175580)(0);
    (*DAT_00175580)(0xfa);
    (*DAT_00175580)(0x28);
    (*DAT_00175580)(0);
    (*DAT_00175580)((int)ROUND((float)param_1[0x1f8]));
    (*DAT_00175580)((int)ROUND((float)param_1[0x1f9]));
    (*DAT_00175580)((int)ROUND((float)param_1[0x1fa]));
    (*DAT_00175580)(0x80);
    (*DAT_00175580)(0);
    (*DAT_0017557c)();
    param_1[0xf4] = param_1[0xf4] + 1;
    local_14 = local_14 + 1;
  } while (local_14 < 10);
  return;
}


