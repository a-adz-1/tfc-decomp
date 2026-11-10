// FireTargets__FPCcP11CBaseEntityT18USE_TYPEf  @ 000f599c
void FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  local_8 = 0;
  if (param_1 != 0) {
    (*DAT_0019f794)(2,"Firing: (%s)\n",param_1);
LAB_000f5a6a:
    local_8 = (*DAT_0019f6d8)(local_8,"targetname",param_1);
    bVar1 = false;
    if (local_8 == 0) {
LAB_000f5aa9:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_0019f7b8)(local_8);
      if (iVar2 == 0) goto LAB_000f5aa9;
    }
    if (!bVar1) {
      iVar2 = local_8;
      if (local_8 == 0) {
        iVar2 = (*DAT_0019f7b4)(0);
        if (iVar2 != 0) goto LAB_000f5a06;
        piVar3 = (int *)0x0;
      }
      else {
LAB_000f5a06:
        piVar3 = *(int **)(iVar2 + 0x7c);
      }
      if ((piVar3 != (int *)0x0) && ((*(byte *)(*piVar3 + 0x1a7) & 0x40) == 0)) {
        (*DAT_0019f794)(2,"Found: %s, firing (%s)\n",*(int *)*piVar3 + *(int *)(gpGlobals + 0x98),
                        param_1);
        (**(code **)(piVar3[0x115] + 0xb8))(piVar3,param_2,param_3,param_4,param_5);
      }
      goto LAB_000f5a6a;
    }
  }
  return;
}


