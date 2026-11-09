// Instance__10CPathTrackP7edict_s  @ 000d0bc0
undefined4 Instance__10CPathTrackP7edict_s(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(param_1 + 0xdc);
  }
  iVar2 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"path_track");
  if ((iVar2 == 0) && (param_1 != 0)) {
    uVar3 = *(undefined4 *)(param_1 + 0xd8);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// Instance__11CBaseEntityP7edict_s  @ 0010e0f0
undefined4 Instance__11CBaseEntityP7edict_s(int param_1)

{
  if ((param_1 == 0) && (param_1 = (*DAT_001755d4)(0), param_1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0xd8);
}


// Instance__11CBaseEntityP9entvars_t  @ 0010e0b0
undefined4 Instance__11CBaseEntityP9entvars_t(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1e8);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 0xd8);
}


// Instance__11CBaseEntityi  @ 0010e070
undefined4 Instance__11CBaseEntityi(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_001755d4)(param_1);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 0xd8);
}


// Instance__15CFuncTrackTrainP7edict_s  @ 000d4140
undefined4 Instance__15CFuncTrackTrainP7edict_s(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(param_1 + 0xdc);
  }
  iVar2 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
  if ((iVar2 == 0) && (param_1 != 0)) {
    uVar3 = *(undefined4 *)(param_1 + 0xd8);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// Instance__19CMomentaryRotButtonP7edict_s  @ 000a0160
undefined4 Instance__19CMomentaryRotButtonP7edict_s(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0xd8);
  }
  return uVar1;
}


