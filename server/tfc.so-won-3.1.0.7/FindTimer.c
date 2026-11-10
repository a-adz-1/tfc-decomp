// FindTimer__11CBaseEntityi  @ 00102770
int * FindTimer__11CBaseEntityi(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  while( true ) {
    piVar1 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar1,"timer");
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    if ((*(int *)(*piVar1 + 0x198) == *(int *)(*param_1 + 0x208)) && (param_2 == 0)) break;
    if ((*(int *)(*piVar1 + 0x198) == *(int *)(*param_1 + 0x208)) && (piVar1[0x106] == param_2)) {
      return piVar1;
    }
  }
  return piVar1;
}


