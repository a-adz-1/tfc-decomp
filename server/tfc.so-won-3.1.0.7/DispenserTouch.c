// DispenserTouch__12CTFDispenserP11CBaseEntity  @ 0009c90c
void DispenserTouch__12CTFDispenserP11CBaseEntity(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    if ((param_2[0x48] != 0) && (param_2[0x48] != *(int *)(param_1 + 0x120))) {
      puVar1 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x144,4,"#Dispenser_used",0,0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar1);
    }
    if (*(float *)(param_1 + 0x690) <= *gpGlobals) {
      iVar2 = FindTimer__11CBaseEntityi(param_1,0xe);
      if (iVar2 == 0) {
        uVar3 = GetClassPtr__H1Z23CDispenserRefillThinker_PX01_PX01(0);
        StartRefillingPlayer__23CDispenserRefillThinkerP11CBaseEntityP12CTFDispenserf
                  (uVar3,param_2,param_1,0x3e4ccccd);
      }
      *(float *)(param_1 + 0x690) = *gpGlobals + 1.0;
    }
  }
  return;
}


