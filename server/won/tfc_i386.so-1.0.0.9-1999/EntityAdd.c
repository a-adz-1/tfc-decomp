// EntityAdd__12CGlobalStateii12GLOBALESTATE  @ 0011d4e0
void EntityAdd__12CGlobalStateii12GLOBALESTATE
               (undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  char *__dest;
  
  __dest = calloc(0x68,1);
  *(undefined4 *)(__dest + 100) = *param_1;
  *param_1 = __dest;
  strcpy(__dest,(char *)(param_2 + *(int *)(gpGlobals + 0x98)));
  strcpy(__dest + 0x40,(char *)(param_3 + *(int *)(gpGlobals + 0x98)));
  *(undefined4 *)(__dest + 0x60) = param_4;
  param_1[1] = param_1[1] + 1;
  return;
}


