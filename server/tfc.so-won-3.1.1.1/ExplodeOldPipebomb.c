// ExplodeOldPipebomb__11CBasePlayerii  @ 00104f44
void ExplodeOldPipebomb__11CBasePlayerii(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  piVar2 = (int *)0x0;
  while (piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"tf_gl_pipebomb"),
        piVar3 != (int *)0x0) {
    iVar1 = *(int *)(*piVar3 + 0x198);
    if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x7c);
    }
    if (iVar1 == param_1) {
      if (param_2 == 0) {
        if ((piVar2 == (int *)0x0) || ((float)piVar3[0x1af] < (float)piVar2[0x1af])) {
          piVar2 = piVar3;
        }
      }
      else if ((param_3 != 0) || ((float)piVar3[0x1af] + 0.6 <= *gpGlobals)) {
        *(float *)(*piVar3 + 0x104) = *gpGlobals;
      }
    }
  }
  if (piVar2 != (int *)0x0) {
    *(float *)(*piVar2 + 0x104) = *gpGlobals;
  }
  return;
}


