// AllGoalsInState__Fii  @ 001098b0
undefined4 AllGoalsInState__Fii(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar1,"info_tfgoal");
    if (iVar1 == 0) {
      return 1;
    }
  } while ((*(int *)(iVar1 + 0x214) != param_1) || (*(int *)(iVar1 + 0x218) == param_2));
  return 0;
}


