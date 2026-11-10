// CancelScript__12CCineMonster  @ 000e9be4
void CancelScript__12CCineMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  (*DAT_0019f794)(2,"Cancelling script: %s\n",param_1[0x1a8] + *(int *)(gpGlobals + 0x98));
  iVar3 = *(int *)(*param_1 + 0x1cc);
  if (iVar3 != 0) {
    iVar3 = iVar3 + *(int *)(gpGlobals + 0x98);
    iVar2 = 0;
    while( true ) {
      iVar2 = (*DAT_0019f6d8)(iVar2,"targetname",iVar3);
      bVar1 = false;
      if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      piVar6 = (int *)(iVar2 + 0x80);
      piVar5 = piVar6;
      if (iVar2 == 0) {
        piVar5 = (int *)0x0;
      }
      iVar3 = strcmp((char *)(*piVar5 + *(int *)(gpGlobals + 0x98)),"scripted_sequence");
      if (iVar3 == 0) {
        if (iVar2 == 0) {
          piVar6 = (int *)0x0;
        }
        iVar3 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(piVar6);
        iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x504);
        iVar4 = 0;
        if (iVar3 != 0) {
          iVar4 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x50))(iVar3);
        }
        if ((iVar4 != 0) && (*(int *)(iVar4 + 0x574) == 6)) {
          *(undefined4 *)(iVar4 + 0x694) = 2;
          CineCleanup__12CBaseMonster(iVar4);
        }
      }
      iVar3 = *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98);
    }
    return;
  }
  iVar3 = *(int *)(*param_1 + 0x208);
  piVar5 = (int *)(iVar3 + 0x80);
  if (iVar3 == 0) {
    piVar5 = (int *)0x0;
  }
  iVar2 = strcmp((char *)(*piVar5 + *(int *)(gpGlobals + 0x98)),"scripted_sequence");
  if (iVar2 == 0) {
    iVar2 = iVar3 + 0x80;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    iVar3 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(iVar2);
    iVar3 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x504);
    iVar2 = 0;
    if (iVar3 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x50))(iVar3);
    }
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x574) == 6)) {
      *(undefined4 *)(iVar2 + 0x694) = 2;
      CineCleanup__12CBaseMonster(iVar2);
    }
  }
  return;
}


