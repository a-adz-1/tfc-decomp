// DelayStart__12CCineMonsteri  @ 000e7e20
void DelayStart__12CCineMonsteri(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = *(int *)(*param_1 + 0x1ac) + (int)gpGlobals[0x26];
  iVar4 = 0;
  while( true ) {
    iVar4 = (*DAT_001754f8)(iVar4,"targetname",iVar2);
    bVar1 = false;
    if ((iVar4 == 0) || (iVar2 = (*DAT_001755d8)(iVar4), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    if (iVar4 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(iVar4 + 0xdc);
    }
    iVar2 = strcmp((char *)(*piVar3 + (int)gpGlobals[0x26]),"scripted_sequence");
    if (iVar2 == 0) {
      if (iVar4 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = iVar4 + 0xdc;
      }
      iVar2 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(iVar2);
      if (param_2 == 0) {
        *(int *)(iVar2 + 0x62c) = *(int *)(iVar2 + 0x62c) + -1;
        if (*(int *)(iVar2 + 0x62c) < 1) {
          *(float *)(iVar2 + 0x630) = *gpGlobals + 0.05;
        }
      }
      else {
        *(int *)(iVar2 + 0x62c) = *(int *)(iVar2 + 0x62c) + 1;
      }
    }
    iVar2 = *(int *)(*param_1 + 0x1ac) + (int)gpGlobals[0x26];
  }
  return;
}


