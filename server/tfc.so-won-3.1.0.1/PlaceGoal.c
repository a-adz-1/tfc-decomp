// PlaceGoal__7CTFGoal  @ 000faff4
void PlaceGoal__7CTFGoal(int *param_1)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),(char *)FUN_00140fb4);
  if (iVar1 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)tfgoal_timer_tick__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x93];
  }
  else if ((*(byte *)(param_1 + 0x88) & 1) != 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)tfgoal_touch__11CBaseEntityP11CBaseEntity;
  }
  *(int *)*param_1 = (int)"info_tfgoal" - (int)gpGlobals[0x26];
  if ((*(byte *)((int)param_1 + 0x221) & 8) != 0) {
    *(undefined4 *)(*param_1 + 0x108) = 6;
    *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 6.0;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    iVar1 = (*DAT_001a7ea8)();
    if (iVar1 == 0) {
      iVar1 = *param_1;
      (*DAT_001a7f34)(4,"TF Goal %s fell out of level at %f,%f,%f",
                      *(int *)(iVar1 + 0x1d0) + (int)gpGlobals[0x26],(double)*(float *)(iVar1 + 8),
                      (double)*(float *)(iVar1 + 0xc),(double)*(float *)(iVar1 + 0x10));
      UTIL_Remove__FP11CBaseEntity();
      return;
    }
  }
  *(undefined4 *)(*param_1 + 0x108) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar1 + 0x10);
  return;
}


