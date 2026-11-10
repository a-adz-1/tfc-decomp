// UpdateAllButtons__19CMomentaryRotButtonfi  @ 0009f640
void UpdateAllButtons__19CMomentaryRotButtonfi(int *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    iVar4 = (*DAT_001754f8)(iVar4,"target",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if (iVar4 == 0) {
LAB_0009f68b:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001755d8)(iVar4);
      if (iVar2 == 0) goto LAB_0009f68b;
    }
    if (bVar1) {
      return;
    }
    if (iVar4 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(iVar4 + 0xdc);
    }
    iVar2 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"momentary_rot_button");
    if (iVar2 == 0) {
      if (iVar4 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar4 + 0xd8);
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
  } while( true );
}


