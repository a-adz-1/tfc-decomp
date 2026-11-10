// GetTeamCheckTeam__FPCc  @ 00108604
undefined4 GetTeamCheckTeam__FPCc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar1 = (*DAT_001c1058)(0,"targetname",param_1);
  bVar6 = false;
  if ((iVar1 == 0) || (iVar2 = (*DAT_001c1138)(iVar1), iVar2 == 0)) {
    bVar6 = true;
  }
  if (!bVar6) {
    if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = *(undefined4 **)(iVar1 + 0x7c);
    }
    iVar1 = 0x12;
    bVar6 = true;
    pcVar4 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar3);
    pcVar5 = "info_tf_teamcheck";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      return puVar3[0x48];
    }
  }
  return 0;
}


