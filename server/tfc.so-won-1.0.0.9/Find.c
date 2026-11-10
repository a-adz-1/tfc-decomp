// Find__12CGlobalStatei  @ 0011d430
char * Find__12CGlobalStatei(undefined4 *param_1,int param_2)

{
  int iVar1;
  char *__s2;
  int iVar2;
  
  if (param_2 == 0) {
    __s2 = (char *)0x0;
  }
  else {
    iVar1 = *(int *)(gpGlobals + 0x98);
    __s2 = (char *)*param_1;
    while ((__s2 != (char *)0x0 && (iVar2 = strcmp((char *)(param_2 + iVar1),__s2), iVar2 != 0))) {
      __s2 = *(char **)(__s2 + 100);
    }
  }
  return __s2;
}


// Find__15CFuncTrackTrain  @ 000d3ce0
void Find__15CFuncTrackTrain(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  uVar1 = (*DAT_001754f8)(0,"targetname",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
  piVar2 = (int *)Instance__10CPathTrackP7edict_s(uVar1);
  param_1[0xf3] = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    piVar2 = (int *)*piVar2;
    iVar3 = strcmp((char *)(*piVar2 + *(int *)(gpGlobals + 0x98)),"path_track");
    if (iVar3 == 0) {
      local_1c = (float)piVar2[2];
      local_18 = (float)piVar2[3];
      local_8 = (float)piVar2[4] + (float)param_1[0xf5];
      local_14 = local_8 - (float)param_1[0xf5];
      local_10 = local_1c;
      local_c = local_18;
      LookAhead__10CPathTrackP6Vectorfi(param_1[0xf3],&local_1c,param_1[0xf4],0);
      local_14 = local_14 + (float)param_1[0xf5];
      iVar3 = *param_1;
      local_34 = local_1c - local_10;
      local_30 = local_18 - local_c;
      local_2c = local_14 - local_8;
      UTIL_VecToAngles__FRC6Vector(&local_28,&local_34);
      *(undefined4 *)(iVar3 + 0x50) = local_28;
      *(undefined4 *)(iVar3 + 0x54) = local_24;
      *(undefined4 *)(iVar3 + 0x58) = local_20;
      *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 180.0;
      if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
        *(undefined4 *)(*param_1 + 0x50) = 0;
      }
      UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,&local_10);
      NextThink__15CFuncTrackTrainfi(param_1,*(float *)(*param_1 + 0xe0) + 0.1,0);
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__15CFuncTrackTrain;
      *(int *)(*param_1 + 0x1d8) = param_1[0xf8];
      UpdateSound__15CFuncTrackTrain(param_1);
    }
    else {
      (*DAT_001755b4)(4,"func_track_train must be on a path of path_track\n");
      param_1[0xf3] = 0;
    }
  }
  return;
}


// Find__16CFuncTrackChange  @ 000d4940
void Find__16CFuncTrackChange(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (*DAT_001754f8)(0,"targetname",param_1[0x126] + *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    iVar2 = param_1[0x126] + *(int *)(gpGlobals + 0x98);
    pcVar5 = (code *)"Can\'t find top track for track change! %s\n";
  }
  else {
    iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
    param_1[0x123] = iVar2;
    iVar2 = (*DAT_001754f8)(0,"targetname",param_1[0x127] + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      iVar2 = param_1[0x127] + *(int *)(gpGlobals + 0x98);
      pcVar5 = FUN_00138520;
    }
    else {
      iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
      param_1[0x124] = iVar2;
      iVar2 = (*DAT_001754f8)(0,"targetname",param_1[0x128] + *(int *)(gpGlobals + 0x98));
      bVar1 = false;
      if ((iVar2 == 0) || (iVar2 = (*DAT_001755d8)(iVar2), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        (*DAT_001755b4)(4,FUN_001384e0,param_1[0x128] + *(int *)(gpGlobals + 0x98));
        (*DAT_001754f8)(0,"targetname",param_1[0x128] + *(int *)(gpGlobals + 0x98));
        return;
      }
      uVar4 = (*DAT_001754f8)(0,"targetname",param_1[0x128] + *(int *)(gpGlobals + 0x98));
      iVar2 = Instance__15CFuncTrackTrainP7edict_s(uVar4);
      param_1[0x125] = iVar2;
      if (iVar2 != 0) {
        iVar2 = *param_1;
        fStack_1c = (*(float *)(iVar2 + 0xa4) + *(float *)(iVar2 + 0xb0)) * 0.5;
        fStack_18 = (*(float *)(iVar2 + 0xa8) + *(float *)(iVar2 + 0xb4)) * 0.5;
        fStack_14 = (*(float *)(iVar2 + 0xac) + *(float *)(iVar2 + 0xb8)) * 0.5;
        fStack_10 = fStack_1c;
        fStack_c = fStack_18;
        fStack_8 = fStack_14;
        iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x124],&fStack_1c);
        param_1[0x124] = iVar2;
        fStack_1c = fStack_10;
        fStack_18 = fStack_c;
        fStack_14 = fStack_8;
        iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x123],&fStack_1c);
        param_1[0x123] = iVar2;
        (**(code **)(param_1[0xf2] + 0x118))(param_1,param_1[0xfa]);
        param_1[3] = 0;
        param_1[4] = 0;
        return;
      }
      iVar2 = param_1[0x128] + *(int *)(gpGlobals + 0x98);
      pcVar5 = FUN_001384e0;
    }
  }
  (*DAT_001755b4)(4,pcVar5,iVar2);
  return;
}


// Find__18CFuncTrainControls  @ 000d44f0
void Find__18CFuncTrainControls(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    iVar5 = (*DAT_001754f8)(iVar5,"targetname",
                            *(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if (iVar5 == 0) {
LAB_000d4538:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001755d8)(iVar5);
      if (iVar2 == 0) goto LAB_000d4538;
    }
    if (bVar1) break;
    if (iVar5 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(iVar5 + 0xdc);
    }
    iVar2 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
  } while (iVar2 != 0);
  bVar1 = false;
  if (iVar5 != 0) {
    iVar2 = (*DAT_001755d8)(iVar5);
    if (iVar2 != 0) goto LAB_000d4590;
  }
  bVar1 = true;
LAB_000d4590:
  if (bVar1) {
    (*DAT_001755b4)(1,"No train %s\n",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
  }
  else {
    uVar4 = Instance__15CFuncTrackTrainP7edict_s(iVar5);
    SetControls__15CFuncTrackTrainP9entvars_t(uVar4,*param_1);
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


