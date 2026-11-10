// ExplodeOldPipebomb__11CBasePlayeri  @ 00104400
void ExplodeOldPipebomb__11CBasePlayeri(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  piVar2 = (int *)0x0;
  while (piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"tf_gl_pipebomb"),
        piVar3 != (int *)0x0) {
    iVar1 = *(int *)(*piVar3 + 0x178);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xd8);
    }
    if (iVar1 == param_1) {
      if (param_2 == 0) {
        if ((piVar2 == (int *)0x0) || ((float)piVar3[0x18a] < (float)piVar2[0x18a])) {
          piVar2 = piVar3;
        }
      }
      else {
        *(undefined4 *)(*piVar3 + 0xe4) = *gpGlobals;
      }
    }
  }
  if (piVar2 != (int *)0x0) {
    *(undefined4 *)(*piVar2 + 0xe4) = *gpGlobals;
  }
  return;
}


