// CaltropScatterThink__10CTFCaltrop  @ 001002c8
void CaltropScatterThink__10CTFCaltrop(int *param_1)

{
  int iVar1;
  int iVar2;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  if (*gpGlobals <= (float)param_1[0x116]) {
    if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
      param_1[5] = -0x10000;
      param_1[6] = (int)CanisterTouch__10CTFCaltropP11CBaseEntity;
    }
    else {
      *(undefined4 *)(*param_1 + 0x10c) = 1;
      param_1[5] = -0x10000;
      param_1[6] = (int)CaltropTouch__10CTFCaltropP11CBaseEntity;
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x50) = 0x42b40000;
      *(undefined4 *)(iVar1 + 0x54) = 0x42b40000;
      *(undefined4 *)(iVar1 + 0x58) = 0x42b40000;
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
      *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
      *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
      iVar2 = *param_1;
      *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar2 + 0x5c);
      *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar2 + 0x60);
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar2 + 100);
      UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    }
  }
  else {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  return;
}


