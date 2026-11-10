// teamsprint__FiP11CBaseEntityiPCcN33  @ 000ac66c
void teamsprint__FiP11CBaseEntityiPCcN33
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    for (iVar3 = 1; iVar3 <= *(int *)(gpGlobals + 0x90); iVar3 = iVar3 + 1) {
      puVar1 = (undefined4 *)UTIL_PlayerByIndex__Fi(iVar3);
      if (puVar1 != (undefined4 *)0x0) {
        iVar2 = IsAlly__11CBaseEntityi(puVar1,param_1);
        if (iVar2 != 0) {
          ClientPrint__FP9entvars_siPCcN42(*puVar1,param_3,param_4,param_5,param_6,param_7,0);
        }
      }
    }
  }
  return;
}


