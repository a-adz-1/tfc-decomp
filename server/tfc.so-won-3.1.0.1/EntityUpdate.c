// EntityUpdate__12CGlobalStateii  @ 0011315c
void EntityUpdate__12CGlobalStateii(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = Find__12CGlobalStatei(param_1,param_2);
  if (iVar1 != 0) {
    strcpy((char *)(iVar1 + 0x40),(char *)(param_3 + *(int *)(gpGlobals + 0x98)));
  }
  return;
}


