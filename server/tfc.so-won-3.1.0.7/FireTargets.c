// FireTargets__FPCcP11CBaseEntityT18USE_TYPEf  @ 000f3a2c
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
    (*DAT_001c1114)(2,"Firing: (%s)\n",param_1);
LAB_000f3a68:
    iVar4 = (*DAT_001c1058)(iVar4,"targetname",param_1);
    bVar1 = false;
    if (iVar4 == 0) {
LAB_000f3a9d:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001c1138)(iVar4);
      if (iVar2 == 0) goto LAB_000f3a9d;
    }
    if (!bVar1) {
      iVar2 = iVar4;
      if (iVar4 == 0) {
        iVar2 = (*DAT_001c1134)(0);
        if (iVar2 != 0) goto LAB_000f3ac7;
        piVar3 = (int *)0x0;
      }
      else {
LAB_000f3ac7:
        piVar3 = *(int **)(iVar2 + 0x7c);
      }
      if ((piVar3 != (int *)0x0) && ((*(byte *)(*piVar3 + 0x1a7) & 0x40) == 0)) {
        (*DAT_001c1114)(2,"Found: %s, firing (%s)\n",*(int *)*piVar3 + *(int *)(gpGlobals + 0x98),
                        param_1);
        (**(code **)(piVar3[0x111] + 0xb8))(piVar3,param_2,param_3,param_4,param_5);
      }
      goto LAB_000f3a68;
    }
  }
  return;
}


