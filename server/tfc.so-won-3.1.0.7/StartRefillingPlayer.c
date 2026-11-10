// StartRefillingPlayer__23CDispenserRefillThinkerP11CBaseEntityP12CTFDispenserf  @ 0009c880
void StartRefillingPlayer__23CDispenserRefillThinkerP11CBaseEntityP12CTFDispenserf
               (int *param_1,int *param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  
  *(float *)(*param_1 + 0x104) = param_4 + *gpGlobals;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x112,param_3);
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x114,param_2);
  iVar1 = *param_2;
  param_1[0x116] = *(int *)(iVar1 + 8);
  param_1[0x117] = *(int *)(iVar1 + 0xc);
  param_1[0x118] = *(int *)(iVar1 + 0x10);
  return;
}


