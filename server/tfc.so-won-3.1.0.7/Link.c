// Link__10CPathTrack  @ 000cc6a8
void Link__10CPathTrack(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar2 = (*DAT_001c1058)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001c1138)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      (*DAT_001c1114)(1,"Dead end link %s\n",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
                     );
    }
    else {
      iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
      param_1[0x114] = iVar2;
      if (iVar2 != 0) {
        SetPrevious__10CPathTrackP10CPathTrack(iVar2,param_1);
      }
    }
  }
  if (param_1[0x113] != 0) {
    iVar2 = (*DAT_001c1058)(0,"targetname",param_1[0x113] + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001c1138)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
      param_1[0x116] = iVar2;
      if (iVar2 != 0) {
        SetPrevious__10CPathTrackP10CPathTrack(iVar2,param_1);
      }
    }
    return;
  }
  return;
}


