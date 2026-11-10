// EntityUpdate__12CGlobalStateii  @ 00127ba0
void EntityUpdate__12CGlobalStateii(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  char *__s2;
  int iVar2;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(gpGlobals + 0x98);
    __s2 = (char *)*param_1;
    while ((__s2 != (char *)0x0 && (iVar2 = strcmp((char *)(param_2 + iVar1),__s2), iVar2 != 0))) {
      __s2 = *(char **)(__s2 + 100);
    }
    if (__s2 != (char *)0x0) {
      strcpy(__s2 + 0x40,(char *)(param_3 + *(int *)(gpGlobals + 0x98)));
    }
  }
  return;
}


