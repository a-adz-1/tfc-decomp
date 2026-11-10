// Find__12CGlobalStatei  @ 00112d48
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


// Find__15CFuncTrackTrain  @ 000c5330
void Find__15CFuncTrackTrain(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  uVar1 = (*DAT_001a7e78)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  piVar2 = (int *)Instance__10CPathTrackP7edict_s(uVar1);
  param_1[0xf6] = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    piVar2 = (int *)*piVar2;
    iVar3 = strcmp((char *)(*piVar2 + *(int *)(gpGlobals + 0x98)),"path_track");
    if (iVar3 == 0) {
      fStack_18 = (float)piVar2[2];
      fStack_14 = (float)piVar2[3];
      fStack_4 = (float)piVar2[4] + (float)param_1[0xf8];
      fStack_10 = fStack_4 - (float)param_1[0xf8];
      fStack_c = fStack_18;
      fStack_8 = fStack_14;
      LookAhead__10CPathTrackP6Vectorfi(param_1[0xf6],&fStack_18,param_1[0xf7],0);
      fStack_10 = fStack_10 + (float)param_1[0xf8];
      iVar3 = *param_1;
      fStack_30 = fStack_18 - fStack_c;
      fStack_2c = fStack_14 - fStack_8;
      fStack_28 = fStack_10 - fStack_4;
      UTIL_VecToAngles__FRC6Vector(&uStack_24,&fStack_30);
      *(float *)(iVar3 + 0x50) = fStack_28;
      *(undefined4 *)(iVar3 + 0x54) = uStack_24;
      *(undefined4 *)(iVar3 + 0x58) = uStack_20;
      *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 180.0;
      if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
        *(undefined4 *)(*param_1 + 0x50) = 0;
      }
      UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,&fStack_10);
      NextThink__15CFuncTrackTrainfi(param_1,*(float *)(*param_1 + 0x100) + 0.1,0);
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__15CFuncTrackTrain;
      *(int *)(*param_1 + 0x1f8) = param_1[0xfb];
      UpdateSound__15CFuncTrackTrain(param_1);
    }
    else {
      (*DAT_001a7f34)(4,"func_track_train must be on a path of path_track\n");
      param_1[0xf6] = 0;
    }
  }
  return;
}


// Find__16CFuncTrackChange  @ 000c6100
void Find__16CFuncTrackChange(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar2 = (*DAT_001a7e78)(0,"targetname",param_1[0x129] + *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    iVar2 = param_1[0x129] + *(int *)(gpGlobals + 0x98);
    pcVar5 = "Can\'t find top track for track change! %s\n";
  }
  else {
    iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
    param_1[0x126] = iVar2;
    iVar2 = (*DAT_001a7e78)(0,"targetname",param_1[0x12a] + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      iVar2 = param_1[0x12a] + *(int *)(gpGlobals + 0x98);
      pcVar5 = "Can\'t find bottom track for track change! %s\n";
    }
    else {
      iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
      param_1[0x127] = iVar2;
      iVar2 = (*DAT_001a7e78)(0,"targetname",param_1[299] + *(int *)(gpGlobals + 0x98));
      bVar1 = false;
      if ((iVar2 == 0) || (iVar2 = (*DAT_001a7f58)(iVar2), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        (*DAT_001a7f34)(4,"Can\'t find train for track change! %s\n",
                        param_1[299] + *(int *)(gpGlobals + 0x98));
        (*DAT_001a7e78)(0,"targetname",param_1[299] + *(int *)(gpGlobals + 0x98));
        return;
      }
      uVar4 = (*DAT_001a7e78)(0,"targetname",param_1[299] + *(int *)(gpGlobals + 0x98));
      iVar2 = Instance__15CFuncTrackTrainP7edict_s(uVar4);
      param_1[0x128] = iVar2;
      if (iVar2 != 0) {
        iVar2 = *param_1;
        fStack_18 = (*(float *)(iVar2 + 0xc4) + *(float *)(iVar2 + 0xd0)) * 0.5;
        fStack_14 = (*(float *)(iVar2 + 200) + *(float *)(iVar2 + 0xd4)) * 0.5;
        fStack_10 = (*(float *)(iVar2 + 0xcc) + *(float *)(iVar2 + 0xd8)) * 0.5;
        fStack_c = fStack_18;
        fStack_8 = fStack_14;
        fStack_4 = fStack_10;
        iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x127],&fStack_18);
        param_1[0x127] = iVar2;
        fStack_18 = fStack_c;
        fStack_14 = fStack_8;
        fStack_10 = fStack_4;
        iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x126],&fStack_18);
        param_1[0x126] = iVar2;
        (**(code **)(param_1[0xf5] + 0x118))(param_1,param_1[0xfd]);
        param_1[3] = 0;
        param_1[4] = 0;
        return;
      }
      iVar2 = param_1[299] + *(int *)(gpGlobals + 0x98);
      pcVar5 = "Can\'t find train for track change! %s\n";
    }
  }
  (*DAT_001a7f34)(4,pcVar5,iVar2);
  return;
}


// Find__18CFuncTrainControls  @ 000c5c30
void Find__18CFuncTrainControls(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    iVar5 = (*DAT_001a7e78)(iVar5,"targetname",
                            *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if (iVar5 == 0) {
LAB_000c5c94:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001a7f58)(iVar5);
      if (iVar2 == 0) goto LAB_000c5c94;
    }
    if (bVar1) break;
    piVar4 = (int *)(iVar5 + 0x80);
    if (iVar5 == 0) {
      piVar4 = (int *)0x0;
    }
    iVar2 = strcmp((char *)(*piVar4 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
  } while (iVar2 != 0);
  bVar1 = false;
  if (iVar5 != 0) {
    iVar2 = (*DAT_001a7f58)(iVar5);
    if (iVar2 != 0) goto LAB_000c5cf2;
  }
  bVar1 = true;
LAB_000c5cf2:
  if (bVar1) {
    (*DAT_001a7f34)(1,"No train %s\n",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  }
  else {
    uVar3 = Instance__15CFuncTrackTrainP7edict_s(iVar5);
    SetControls__15CFuncTrackTrainP9entvars_s(uVar3,*param_1);
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


