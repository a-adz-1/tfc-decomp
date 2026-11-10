// Instance__10CPathTrackP7edict_s  @ 000c1ce4
undefined4 Instance__10CPathTrackP7edict_s(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x80);
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  iVar1 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"path_track");
  if (iVar1 == 0) {
    uVar2 = 0;
    if (param_1 != 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x7c);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// Instance__11CBaseEntityP7edict_s  @ 00100384
undefined4 Instance__11CBaseEntityP7edict_s(int param_1)

{
  if ((param_1 == 0) && (param_1 = (*DAT_001a7f54)(0), param_1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x7c);
}


// Instance__11CBaseEntityP9entvars_s  @ 00100348
undefined4 Instance__11CBaseEntityP9entvars_s(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x208);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 0x7c);
}


// Instance__11CBaseEntityi  @ 00100300
undefined4 Instance__11CBaseEntityi(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_001a7f54)(param_1);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 0x7c);
}


// Instance__15CFuncTrackTrainP7edict_s  @ 000c5864
undefined4 Instance__15CFuncTrackTrainP7edict_s(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x80);
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  iVar1 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
  if (iVar1 == 0) {
    uVar2 = 0;
    if (param_1 != 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x7c);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// Instance__19CMomentaryRotButtonP7edict_s  @ 000858b0
undefined4 Instance__19CMomentaryRotButtonP7edict_s(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x7c);
  }
  return uVar1;
}


