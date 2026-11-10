// StartRefillingPlayer__23CDispenserRefillThinkerP11CBaseEntityP12CTFDispenserf  @ 0009c7f0
void StartRefillingPlayer__23CDispenserRefillThinkerP11CBaseEntityP12CTFDispenserf
               (int *param_1,int *param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + param_4;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x116,param_3);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x118,param_2);
  iVar1 = *param_2;
  param_1[0x11a] = *(int *)(iVar1 + 8);
  param_1[0x11b] = *(int *)(iVar1 + 0xc);
  param_1[0x11c] = *(int *)(iVar1 + 0x10);
  return;
}


