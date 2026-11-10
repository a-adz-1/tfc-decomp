// HasItemFromGroup__FP11CBaseEntityi  @ 00109908
undefined4 HasItemFromGroup__FP11CBaseEntityi(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  do {
    piVar1 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar1,"item_tfgoal");
    if (piVar1 == (int *)0x0) {
      return 0;
    }
  } while ((piVar1[0x85] != param_2) || (*(int *)(*piVar1 + 0x198) != *(int *)(*param_1 + 0x208)));
  return 1;
}


