// UpdateAllButtons__19CMomentaryRotButtonfi  @ 0008bc00
void UpdateAllButtons__19CMomentaryRotButtonfi(int *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  while( true ) {
    iVar4 = (*DAT_0019f6d8)(iVar4,"target",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar4 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar4), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    piVar3 = (int *)(iVar4 + 0x80);
    if (iVar4 == 0) {
      piVar3 = (int *)0x0;
    }
    iVar2 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"momentary_rot_button");
    if (iVar2 == 0) {
      iVar2 = 0;
      if (iVar4 != 0) {
        iVar2 = *(int *)(iVar4 + 0x7c);
      }
      if (iVar2 != 0) {
        if (param_3 == 0) {
          UpdateSelfReturn__19CMomentaryRotButtonf(iVar2,param_2);
        }
        else {
          UpdateSelf__19CMomentaryRotButtonf(iVar2,param_2);
        }
      }
    }
  }
  return;
}


