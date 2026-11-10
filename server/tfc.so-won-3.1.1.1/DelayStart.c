// DelayStart__12CCineMonsteri  @ 000e9dfc
void DelayStart__12CCineMonsteri(int *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *local_10;
  
  iVar3 = *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26];
  iVar5 = 0;
  do {
    iVar5 = (*DAT_0019f6d8)(iVar5,"targetname",iVar3);
    bVar2 = false;
    if (iVar5 == 0) {
LAB_000e9f28:
      bVar2 = true;
    }
    else {
      iVar3 = (*DAT_0019f7b8)(iVar5);
      if (iVar3 == 0) goto LAB_000e9f28;
    }
    if (bVar2) {
      return;
    }
    piVar4 = (int *)(iVar5 + 0x80);
    local_10 = piVar4;
    if (iVar5 == 0) {
      local_10 = (int *)0x0;
    }
    iVar3 = strcmp((char *)(*local_10 + (int)gpGlobals[0x26]),"scripted_sequence");
    if (iVar3 == 0) {
      if (iVar5 == 0) {
        piVar4 = (int *)0x0;
      }
      iVar3 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(piVar4);
      if (param_2 == 0) {
        iVar1 = *(int *)(iVar3 + 0x6b8) + -1;
        *(int *)(iVar3 + 0x6b8) = iVar1;
        if (iVar1 < 1) {
          *(float *)(iVar3 + 0x6bc) = *gpGlobals + 0.05;
        }
      }
      else {
        *(int *)(iVar3 + 0x6b8) = *(int *)(iVar3 + 0x6b8) + 1;
      }
    }
    iVar3 = *(int *)(*param_1 + 0x1cc) + (int)gpGlobals[0x26];
  } while( true );
}


