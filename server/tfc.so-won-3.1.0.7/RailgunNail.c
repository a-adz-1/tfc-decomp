// RailgunNail_Think__14CTFNailgunNail  @ 00100904
void RailgunNail_Think__14CTFNailgunNail(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar1 + 0x1c);
  param_1[5] = -0x10000;
  param_1[6] = (int)RailgunNailTouch__14CTFNailgunNailP11CBaseEntity;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  return;
}


