// FireTargets__FPCcP11CBaseEntityT18USE_TYPEf  @ 000e6dd8
void FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != 0) {
    (*DAT_001a7f34)(2,"Firing: (%s)\n",param_1);
LAB_000e6e14:
    iVar4 = (*DAT_001a7e78)(iVar4,"targetname",param_1);
    bVar1 = false;
    if (iVar4 == 0) {
LAB_000e6e49:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001a7f58)(iVar4);
      if (iVar2 == 0) goto LAB_000e6e49;
    }
    if (!bVar1) {
      iVar2 = iVar4;
      if (iVar4 == 0) {
        iVar2 = (*DAT_001a7f54)(0);
        if (iVar2 != 0) goto LAB_000e6e73;
        piVar3 = (int *)0x0;
      }
      else {
LAB_000e6e73:
        piVar3 = *(int **)(iVar2 + 0x7c);
      }
      if ((piVar3 != (int *)0x0) && ((*(byte *)(*piVar3 + 0x1a7) & 0x40) == 0)) {
        (*DAT_001a7f34)(2,"Found: %s, firing (%s)\n",*(int *)*piVar3 + *(int *)(gpGlobals + 0x98),
                        param_1);
        (**(code **)(piVar3[0xf5] + 0xb0))(piVar3,param_2,param_3,param_4,param_5);
      }
      goto LAB_000e6e14;
    }
  }
  return;
}


