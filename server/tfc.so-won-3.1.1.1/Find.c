// Find__12CGlobalStatei  @ 00127eb0
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
    while ((__s2 != (char *)0x0 && (iVar2 = strcmp((char *)(iVar1 + param_2),__s2), iVar2 != 0))) {
      __s2 = *(char **)(__s2 + 100);
    }
  }
  return __s2;
}


// Find__15CFuncTrackTrain  @ 000cfa10
void Find__15CFuncTrackTrain(int *param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
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
  
  uVar2 = (*DAT_0019f6d8)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  piVar3 = (int *)Instance__10CPathTrackP7edict_s(uVar2);
  param_1[0x116] = (int)piVar3;
  if (piVar3 != (int *)0x0) {
    piVar3 = (int *)*piVar3;
    iVar4 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"path_track");
    if (iVar4 == 0) {
      local_1c = (float)piVar3[2];
      local_18 = (float)piVar3[3];
      local_8 = (float)piVar3[4] + (float)param_1[0x118];
      local_14 = local_8 - (float)param_1[0x118];
      local_10 = local_1c;
      local_c = local_18;
      LookAhead__10CPathTrackP6Vectorfi(param_1[0x116],&local_1c,param_1[0x117],0);
      local_14 = local_14 + (float)param_1[0x118];
      local_34 = local_1c - local_10;
      local_30 = local_18 - local_c;
      local_2c = local_14 - local_8;
      iVar4 = *param_1;
      UTIL_VecToAngles__FRC6Vector(&local_28,&local_34);
      *(undefined4 *)(iVar4 + 0x50) = local_28;
      *(undefined4 *)(iVar4 + 0x54) = local_24;
      *(undefined4 *)(iVar4 + 0x58) = local_20;
      *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 180.0;
      iVar4 = *param_1;
      if ((*(byte *)(iVar4 + 0x1a0) & 1) != 0) {
        *(undefined4 *)(iVar4 + 0x50) = 0;
        iVar4 = *param_1;
      }
      UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar4,&local_10);
      iVar4 = *param_1;
      pbVar1 = (byte *)(iVar4 + 0x1a6);
      *pbVar1 = *pbVar1 & 0xdf;
      *(float *)(*param_1 + 0x104) = *(float *)(iVar4 + 0x100) + 0.1;
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__15CFuncTrackTrain;
      *(int *)(*param_1 + 0x1f8) = param_1[0x11b];
      UpdateSound__15CFuncTrackTrain(param_1);
    }
    else {
      (*DAT_0019f794)(4,"func_track_train must be on a path of path_track\n");
      param_1[0x116] = 0;
    }
  }
  return;
}


// Find__16CFuncTrackChange  @ 000d05c8
void Find__16CFuncTrackChange(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piStack_30;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (*DAT_0019f6d8)(0,"targetname",param_1[0x149] + *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    iVar2 = param_1[0x149] + *(int *)(gpGlobals + 0x98);
    pcVar4 = "Can\'t find top track for track change! %s\n";
  }
  else {
    iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
    param_1[0x146] = iVar2;
    iVar2 = (*DAT_0019f6d8)(0,"targetname",param_1[0x14a] + *(int *)(gpGlobals + 0x98));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      iVar2 = param_1[0x14a] + *(int *)(gpGlobals + 0x98);
      pcVar4 = "Can\'t find bottom track for track change! %s\n";
    }
    else {
      iVar2 = Instance__10CPathTrackP7edict_s(iVar2);
      param_1[0x147] = iVar2;
      iVar2 = (*DAT_0019f6d8)(0,"targetname",param_1[0x14b] + *(int *)(gpGlobals + 0x98));
      bVar1 = false;
      if ((iVar2 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar2), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        (*DAT_0019f794)(4,"Can\'t find train for track change! %s\n",
                        param_1[0x14b] + *(int *)(gpGlobals + 0x98));
        (*DAT_0019f6d8)(0,"targetname",param_1[0x14b] + *(int *)(gpGlobals + 0x98));
        return;
      }
      iVar2 = (*DAT_0019f6d8)(0,"targetname",param_1[0x14b] + *(int *)(gpGlobals + 0x98));
      piStack_30 = (int *)(iVar2 + 0x80);
      if (iVar2 == 0) {
        piStack_30 = (int *)0x0;
      }
      iVar3 = strcmp((char *)(*piStack_30 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
      if (iVar3 == 0) {
        iVar3 = 0;
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar2 + 0x7c);
        }
      }
      else {
        iVar3 = 0;
      }
      param_1[0x148] = iVar3;
      if (iVar3 != 0) {
        iVar2 = *param_1;
        fStack_1c = (*(float *)(iVar2 + 0xc4) + *(float *)(iVar2 + 0xd0)) * 0.5;
        fStack_18 = (*(float *)(iVar2 + 200) + *(float *)(iVar2 + 0xd4)) * 0.5;
        fStack_14 = (*(float *)(iVar2 + 0xcc) + *(float *)(iVar2 + 0xd8)) * 0.5;
        fStack_10 = fStack_1c;
        fStack_c = fStack_18;
        fStack_8 = fStack_14;
        iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x147],&fStack_1c);
        param_1[0x147] = iVar2;
        fStack_1c = fStack_10;
        fStack_18 = fStack_c;
        fStack_14 = fStack_8;
        iVar2 = Nearest__10CPathTrackG6Vector(param_1[0x146],&fStack_1c);
        param_1[0x146] = iVar2;
        (**(code **)(param_1[0x115] + 0x120))(param_1,param_1[0x11d]);
        param_1[3] = 0;
        param_1[4] = 0;
        return;
      }
      iVar2 = param_1[0x14b] + *(int *)(gpGlobals + 0x98);
      pcVar4 = "Can\'t find train for track change! %s\n";
    }
  }
  (*DAT_0019f794)(4,pcVar4,iVar2);
  return;
}


// Find__18CFuncTrainControls  @ 000d01b8
void Find__18CFuncTrainControls(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *local_20;
  
  iVar9 = 0;
  do {
    iVar9 = (*DAT_0019f6d8)(iVar9,"targetname",
                            *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar6 = false;
    if ((iVar9 == 0) || (iVar7 = (*DAT_0019f7b8)(iVar9), iVar7 == 0)) {
      bVar6 = true;
    }
    if (bVar6) break;
    local_20 = (int *)(iVar9 + 0x80);
    if (iVar9 == 0) {
      local_20 = (int *)0x0;
    }
    iVar7 = strcmp((char *)(*local_20 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
  } while (iVar7 != 0);
  bVar6 = false;
  if ((iVar9 == 0) || (iVar7 = (*DAT_0019f7b8)(iVar9), iVar7 == 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    (*DAT_0019f794)(1,"No train %s\n",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
  }
  else {
    local_20 = (int *)(iVar9 + 0x80);
    if (iVar9 == 0) {
      local_20 = (int *)0x0;
    }
    iVar7 = strcmp((char *)(*local_20 + *(int *)(gpGlobals + 0x98)),"func_tracktrain");
    if (iVar7 == 0) {
      piVar8 = (int *)0x0;
      if (iVar9 != 0) {
        piVar8 = *(int **)(iVar9 + 0x7c);
      }
    }
    else {
      piVar8 = (int *)0x0;
    }
    iVar9 = *param_1;
    iVar7 = *piVar8;
    fVar3 = *(float *)(iVar9 + 8) - *(float *)(iVar7 + 0x14);
    fVar4 = *(float *)(iVar9 + 0xc) - *(float *)(iVar7 + 0x18);
    fVar5 = *(float *)(iVar9 + 0x10) - *(float *)(iVar7 + 0x1c);
    fVar1 = *(float *)(iVar9 + 0xe0);
    fVar2 = *(float *)(iVar9 + 0xe4);
    piVar8[0x11c] = (int)(fVar3 + *(float *)(iVar9 + 0xdc));
    piVar8[0x11d] = (int)(fVar4 + fVar1);
    piVar8[0x11e] = (int)(fVar5 + fVar2);
    fVar1 = *(float *)(iVar9 + 0xec);
    fVar2 = *(float *)(iVar9 + 0xf0);
    piVar8[0x11f] = (int)(*(float *)(iVar9 + 0xe8) + fVar3);
    piVar8[0x120] = (int)(fVar1 + fVar4);
    piVar8[0x121] = (int)(fVar2 + fVar5);
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


