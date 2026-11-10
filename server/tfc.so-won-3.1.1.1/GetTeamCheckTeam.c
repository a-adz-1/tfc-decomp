// GetTeamCheckTeam__FPCc  @ 0010ab88
undefined4 GetTeamCheckTeam__FPCc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined4 *local_8;
  
  iVar1 = (*DAT_0019f6d8)(0,"targetname",param_1);
  bVar5 = false;
  if ((iVar1 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar1), iVar2 == 0)) {
    bVar5 = true;
  }
  if (!bVar5) {
    if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      local_8 = *(undefined4 **)(iVar1 + 0x7c);
    }
    iVar1 = 0x12;
    bVar5 = true;
    pcVar3 = (char *)(*(int *)*local_8 + *(int *)(gpGlobals + 0x98));
    pcVar4 = "info_tf_teamcheck";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      return local_8[0x48];
    }
  }
  return 0;
}


