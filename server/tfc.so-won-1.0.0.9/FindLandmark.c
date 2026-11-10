// FindLandmark__12CChangeLevelPCc  @ 00111190
int FindLandmark__12CChangeLevelPCc(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  while( true ) {
    iVar4 = (*DAT_001754f8)(iVar4,"targetname",param_1);
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
    iVar2 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"info_landmark");
    if (iVar2 == 0) {
      return iVar4;
    }
  }
  (*DAT_001755b4)(4,"Can\'t find landmark %s\n",param_1);
  return 0;
}


