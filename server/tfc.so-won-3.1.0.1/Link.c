// Link__10CPathTrack  @ 000c1388
void Link__10CPathTrack(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar2 = (*DAT_001a7e78)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      (*DAT_001a7f34)(1,"Dead end link %s\n",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
                     );
    }
    else {
      iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
      param_1[0xf8] = iVar2;
      if (iVar2 != 0) {
        SetPrevious__10CPathTrackP10CPathTrack(iVar2,param_1);
      }
    }
  }
  if (param_1[0xf7] != 0) {
    iVar2 = (*DAT_001a7e78)(0,"targetname",param_1[0xf7] + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
      param_1[0xfa] = iVar2;
      if (iVar2 != 0) {
        SetPrevious__10CPathTrackP10CPathTrack(iVar2,param_1);
      }
    }
    return;
  }
  return;
}


