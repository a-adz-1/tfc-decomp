// PlaceItem__11CTFGoalItem  @ 001091f4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PlaceItem__11CTFGoalItem(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x24) = DAT_001c0fe4;
  *(undefined4 *)(iVar2 + 0x28) = DAT_001c0fe8;
  if ((*(byte *)((int)param_1 + 0x229) & 8) != 0) {
    *(undefined4 *)(*param_1 + 0x108) = 6;
    *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 6.0;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    iVar2 = (*DAT_001c1088)();
    if (iVar2 == 0) {
      iVar2 = *param_1;
      (*DAT_001c1114)(4,"TF GoalItem %s fell out of level at %f,%f,%f",
                      *(int *)(iVar2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                      (double)*(float *)(iVar2 + 8),(double)*(float *)(iVar2 + 0xc),
                      (double)*(float *)(iVar2 + 0x10));
      UTIL_Remove__FP11CBaseEntity();
      return;
    }
  }
  *(undefined4 *)(*param_1 + 0x108) = 0;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 8);
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x10);
  if ((*(byte *)((int)param_1 + 0x229) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0x13;
    if (param_1[0x89] != 0) {
      iVar2 = GetTeamCheckTeam__FPCc();
      param_1[0x87] = iVar2;
    }
    iVar2 = param_1[0x87];
    if (iVar2 - 1U < 4) {
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x150) = (&rgbcolors)[iVar2 * 3];
      *(undefined4 *)(iVar1 + 0x154) = *(undefined4 *)(&DAT_001cdb84 + iVar2 * 0xc);
      *(undefined4 *)(iVar1 + 0x158) = *(undefined4 *)(&DAT_001cdb88 + iVar2 * 0xc);
    }
    else {
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x150) = rgbcolors;
      *(undefined4 *)(iVar2 + 0x154) = _DAT_001cdb84;
      *(undefined4 *)(iVar2 + 0x158) = _DAT_001cdb88;
    }
    *(undefined4 *)(*param_1 + 0x14c) = 0x42c80000;
  }
  param_1[0xfc] = item_list_bit_698;
  item_list_bit_698 = item_list_bit_698 << 1;
  return;
}


