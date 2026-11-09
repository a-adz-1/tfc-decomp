// UpdateTarget__19CMomentaryRotButtonf  @ 0009f8f0
void UpdateTarget__19CMomentaryRotButtonf(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(*param_1 + 0x1a8) != 0) {
    iVar3 = 0;
LAB_0009f90c:
    iVar3 = (*DAT_001754f8)(iVar3,"targetname",
                            *(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if (iVar3 == 0) {
LAB_0009f948:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001755d8)(iVar3);
      if (iVar2 == 0) goto LAB_0009f948;
    }
    if (!bVar1) {
      iVar2 = iVar3;
      if (iVar3 == 0) {
        iVar2 = (*DAT_001755d4)(0);
        if (iVar2 != 0) goto LAB_0009f967;
        iVar2 = 0;
      }
      else {
LAB_0009f967:
        iVar2 = *(int *)(iVar2 + 0xd8);
      }
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 0x3c8) + 0xb0))(iVar2,param_1,param_1,2,param_2);
      }
      goto LAB_0009f90c;
    }
  }
  return;
}


