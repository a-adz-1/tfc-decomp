// InitPriming__15CTFPrimeGrenadeP11CBaseEntity  @ 000fec68
void InitPriming__15CTFPrimeGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  char *pcVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
  param_1[0x48] = param_2[0x48];
  param_1[3] = -0x10000;
  param_1[4] = (int)GrenadePrimed__15CTFPrimeGrenade;
  lVar2 = (longdouble)(**(code **)(param_1[0x115] + 0x234))(param_1);
  *(float *)(*param_1 + 0x104) = (float)(lVar2 + (longdouble)*gpGlobals);
  lVar2 = (longdouble)(**(code **)(param_1[0x115] + 0x230))(param_1);
  lVar3 = (longdouble)(**(code **)(param_1[0x115] + 0x234))(param_1);
  param_1[0x1ae] = (int)(float)((longdouble)(float)lVar2 + (longdouble)*gpGlobals + lVar3);
  param_1[0x48] = param_2[0x48];
  if (param_2[0x15] != 0) {
    (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(0);
    (*DAT_0019f764)(100);
    (*DAT_0019f764)(0x5f);
    if (param_2[0x15] == 0) {
      pcVar1 = "normalgrenade";
    }
    else {
      pcVar1 = (char *)((int)gpGlobals[0x26] + param_2[0x15]);
    }
    (*DAT_0019f778)(pcVar1);
    (*DAT_0019f760)(0xff);
    (*DAT_0019f760)(0xa0);
    (*DAT_0019f760)(0);
    (*DAT_0019f75c)();
  }
  param_2[0x15] = *(int *)*param_1;
  return;
}


// InitPriming__17CTFCaltropGrenadeP11CBaseEntity  @ 000ffa0c
void InitPriming__17CTFCaltropGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  char *pcVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  *(undefined4 *)(*param_1 + 0x198) = *(undefined4 *)(*param_2 + 0x208);
  param_1[3] = -0x10000;
  param_1[4] = (int)CaltropGrenadePrimed__17CTFCaltropGrenade;
  lVar2 = (longdouble)(**(code **)(param_1[0x115] + 0x234))(param_1);
  *(float *)(*param_1 + 0x104) = (float)(lVar2 + (longdouble)*gpGlobals);
  lVar2 = (longdouble)(**(code **)(param_1[0x115] + 0x230))(param_1);
  lVar3 = (longdouble)(**(code **)(param_1[0x115] + 0x234))(param_1);
  param_1[0x1ae] = (int)(float)((longdouble)(float)lVar2 + (longdouble)*gpGlobals + lVar3);
  param_1[0x48] = param_2[0x48];
  if (param_2[0x15] != 0) {
    (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_2 + 0x208));
    (*DAT_0019f760)(0);
    (*DAT_0019f764)(100);
    (*DAT_0019f764)(0x5f);
    if (param_2[0x15] == 0) {
      pcVar1 = "normalgrenade";
    }
    else {
      pcVar1 = (char *)((int)gpGlobals[0x26] + param_2[0x15]);
    }
    (*DAT_0019f778)(pcVar1);
    (*DAT_0019f760)(0xff);
    (*DAT_0019f760)(0xa0);
    (*DAT_0019f760)(0);
    (*DAT_0019f75c)();
  }
  param_2[0x15] = *(int *)*param_1;
  return;
}


