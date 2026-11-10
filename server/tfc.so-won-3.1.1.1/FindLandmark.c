// FindLandmark__12CChangeLevelPCc  @ 0011593c
int FindLandmark__12CChangeLevelPCc(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  iVar3 = 0;
  while( true ) {
    iVar3 = (*DAT_0019f6d8)(iVar3,"targetname",param_1);
    bVar1 = false;
    if ((iVar3 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar3), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    local_8 = (int *)(iVar3 + 0x80);
    if (iVar3 == 0) {
      local_8 = (int *)0x0;
    }
    iVar2 = strcmp((char *)(*local_8 + *(int *)(gpGlobals + 0x98)),"info_landmark");
    if (iVar2 == 0) {
      return iVar3;
    }
  }
  (*DAT_0019f794)(4,"Can\'t find landmark %s\n",param_1);
  return 0;
}


