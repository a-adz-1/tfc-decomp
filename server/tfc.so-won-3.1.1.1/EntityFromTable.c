// EntityFromTable__12CGlobalStatei  @ 00127d04
char * EntityFromTable__12CGlobalStatei(undefined4 *param_1,int param_2)

{
  int iVar1;
  char *__s2;
  int iVar2;
  
  if (param_2 == 0) {
    __s2 = (char *)0x0;
  }
  else {
    iVar1 = *(int *)(gpGlobals + 0x98);
    __s2 = (char *)*param_1;
    while ((__s2 != (char *)0x0 && (iVar2 = strcmp((char *)(iVar1 + param_2),__s2), iVar2 != 0))) {
      __s2 = *(char **)(__s2 + 100);
    }
  }
  return __s2;
}


