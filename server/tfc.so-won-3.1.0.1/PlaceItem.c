// PlaceItem__11CTFGoalItem  @ 000fadfc
void PlaceItem__11CTFGoalItem(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar2 + 0x24) = DAT_001a7e04;
  *(undefined4 *)(iVar2 + 0x28) = DAT_001a7e08;
  if ((*(byte *)((int)param_1 + 0x221) & 8) != 0) {
    *(undefined4 *)(*param_1 + 0x108) = 6;
    *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 6.0;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    iVar2 = (*DAT_001a7ea8)();
    if (iVar2 == 0) {
      iVar2 = *param_1;
      (*DAT_001a7f34)(4,"TF GoalItem %s fell out of level at %f,%f,%f",
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
  if ((*(byte *)((int)param_1 + 0x221) & 2) != 0) {
    *(undefined4 *)(*param_1 + 0x15c) = 0x13;
    iVar2 = param_1[0x87];
    if (iVar2 - 1U < 4) {
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x150) = (&rgbcolors)[iVar2 * 3];
      *(undefined4 *)(iVar1 + 0x154) = (&DAT_001b49a4)[iVar2 * 3];
      *(undefined4 *)(iVar1 + 0x158) = (&DAT_001b49a8)[iVar2 * 3];
    }
    else {
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x150) = rgbcolors;
      *(undefined4 *)(iVar2 + 0x154) = DAT_001b49a4;
      *(undefined4 *)(iVar2 + 0x158) = DAT_001b49a8;
    }
    *(undefined4 *)(*param_1 + 0x14c) = 0x42c80000;
  }
  param_1[0xe0] = item_list_bit_684;
  item_list_bit_684 = item_list_bit_684 << 1;
  return;
}


