// CaltropScatterThink__10CTFCaltrop  @ 000fde20
void CaltropScatterThink__10CTFCaltrop(int *param_1)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.2;
  if ((*(byte *)(*param_1 + 0x185) & 2) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)CanisterTouch__10CTFCaltropP11CBaseEntity;
  }
  else {
    lVar3 = (longdouble)(*DAT_0017562c)(0,0x40a00000);
    *(float *)(*param_1 + 0xe4) = (float)((longdouble)10.0 + (longdouble)*gpGlobals + lVar3);
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(undefined4 *)(*param_1 + 0xec) = 1;
    param_1[5] = -0x10000;
    param_1[6] = (int)CaltropTouch__10CTFCaltropP11CBaseEntity;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x50) = 0x42b40000;
    *(undefined4 *)(iVar1 + 0x54) = 0x42b40000;
    *(undefined4 *)(iVar1 + 0x58) = 0x42b40000;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
    *(undefined4 *)(iVar1 + 100) = DAT_00175488;
    iVar2 = *param_1;
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar2 + 0x5c);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar2 + 0x60);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar2 + 100);
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  }
  return;
}


