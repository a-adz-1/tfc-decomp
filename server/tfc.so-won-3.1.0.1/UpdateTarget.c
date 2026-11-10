// UpdateTarget__19CMomentaryRotButtonf  @ 00084f10
void UpdateTarget__19CMomentaryRotButtonf(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar3 = 0;
LAB_00084f38:
    iVar3 = (*DAT_001a7e78)(iVar3,"targetname",
                            *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if (iVar3 == 0) {
LAB_00084f84:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001a7f58)(iVar3);
      if (iVar2 == 0) goto LAB_00084f84;
    }
    if (!bVar1) {
      iVar2 = iVar3;
      if (iVar3 == 0) {
        iVar2 = (*DAT_001a7f54)(0);
        if (iVar2 != 0) goto LAB_00084faa;
        iVar2 = 0;
      }
      else {
LAB_00084faa:
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 0x3d4) + 0xb0))(iVar2,param_1,param_1,2,param_2);
      }
      goto LAB_00084f38;
    }
  }
  return;
}


