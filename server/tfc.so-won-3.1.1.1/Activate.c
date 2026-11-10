// Activate__10CFuncTrain  @ 000ce47c
void Activate__10CFuncTrain(int *param_1)

{
  int iVar1;
  int iVar2;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (param_1[0x142] == 0) {
    param_1[0x142] = 1;
    iVar1 = (*DAT_0019f6d8)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    iVar2 = iVar1 + 0x80;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    *(undefined4 *)(*param_1 + 0x1c8) = *(undefined4 *)(iVar2 + 0x1c8);
    iVar1 = *param_1;
    param_1[0x140] = iVar2;
    fStack_10 = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xdc) + *(float *)(iVar1 + 0xe8)) * 0.5;
    fStack_c = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xe0) + *(float *)(iVar1 + 0xec)) * 0.5
    ;
    fStack_8 = *(float *)(iVar2 + 0x10) -
               (*(float *)(iVar1 + 0xe4) + *(float *)(iVar1 + 0xf0)) * 0.5;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,&fStack_10);
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1cc) == 0) {
      *(float *)(iVar2 + 0x104) = *(float *)(iVar2 + 0x100) + 0.1;
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__10CFuncTrain;
    }
    else {
      *(byte *)(iVar2 + 0x1a0) = *(byte *)(iVar2 + 0x1a0) | 1;
    }
  }
  return;
}


// Activate__10CGunTarget  @ 000d1338
void Activate__10CGunTarget(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float local_10;
  float local_c;
  float local_8;
  
  piVar3 = (int *)(**(code **)(param_1[0x115] + 0xac))(param_1);
  if (piVar3 != (int *)0x0) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x141,piVar3);
    iVar1 = *param_1;
    iVar2 = *piVar3;
    local_10 = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xdc) + *(float *)(iVar1 + 0xe8)) * 0.5;
    local_c = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xe0) + *(float *)(iVar1 + 0xec)) * 0.5;
    local_8 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xe4) + *(float *)(iVar1 + 0xf0)) * 0.5
    ;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,&local_10);
  }
  return;
}


// Activate__10CLightning  @ 000a4f58
void Activate__10CLightning(int *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x119]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x119] == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = (*(byte *)(*param_1 + 0x1a0) & 8) == 0;
  }
  if (bVar1) {
    BeamUpdateVars__10CLightning(param_1);
  }
  return;
}


// Activate__10CPathTrack  @ 000ccbbc
void Activate__10CPathTrack(int *param_1)

{
  if (*(int *)(*param_1 + 0x1cc) != 0) {
    Link__10CPathTrack(param_1);
  }
  return;
}


// Activate__11CBaseEntity  @ 00112f58
void Activate__11CBaseEntity(void)

{
  return;
}


// Activate__12CCineMonster  @ 000e9f40
void Activate__12CCineMonster(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *local_8;
  
  iVar2 = (*DAT_0019f6d8)(0,"targetname",*(int *)(param_1 + 0x6a4) + *(int *)(gpGlobals + 0x98));
  local_8 = (int *)0x0;
  do {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      if (local_8 == (int *)0x0) {
        iVar2 = *(int *)(param_1 + 0x6a4) + *(int *)(gpGlobals + 0x98);
        pcVar4 = "classname";
        iVar3 = 0;
        while (iVar3 = (*DAT_0019f6d8)(iVar3,pcVar4,iVar2), local_8 == (int *)0x0) {
          bVar1 = false;
          if ((iVar3 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar3), iVar2 == 0)) {
            bVar1 = true;
          }
          if (bVar1) {
            return;
          }
          iVar2 = iVar3;
          if ((iVar3 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
            iVar2 = 0;
          }
          else {
            iVar2 = *(int *)(iVar2 + 0x7c);
          }
          if (iVar2 == 0) {
            local_8 = (int *)0x0;
          }
          else {
            local_8 = (int *)(**(code **)(*(int *)(iVar2 + 0x454) + 0x50))(iVar2);
          }
          iVar2 = *(int *)(param_1 + 0x6a4) + *(int *)(gpGlobals + 0x98);
          pcVar4 = "targetname";
        }
      }
      break;
    }
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    if ((*(byte *)(iVar3 + 0x1a4) & 0x20) != 0) {
      iVar3 = iVar2;
      if ((iVar2 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x7c);
      }
      if (iVar3 == 0) {
        local_8 = (int *)0x0;
      }
      else {
        local_8 = (int *)(**(code **)(*(int *)(iVar3 + 0x454) + 0x50))(iVar3);
      }
    }
    iVar2 = (*DAT_0019f6d8)(iVar2,"targetname",
                            *(int *)(param_1 + 0x6a4) + *(int *)(gpGlobals + 0x98));
  } while (local_8 == (int *)0x0);
  iVar2 = (*DAT_0019f7c8)(*(undefined4 *)(*local_8 + 0x208));
  if (iVar2 != 0) {
    SequencePrecache__FPvPCc(iVar2,*(int *)(param_1 + 0x69c) + *(int *)(gpGlobals + 0x98));
    SequencePrecache__FPvPCc(iVar2,*(int *)(param_1 + 0x6a0) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Activate__14CFuncTankLaser  @ 000ac420
void Activate__14CFuncTankLaser(int param_1)

{
  int iVar1;
  
  iVar1 = GetLaser__14CFuncTankLaser(param_1);
  if (iVar1 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
    (*DAT_0019f794)(4,"Laser tank with no env_laser!\n");
  }
  else {
    TurnOff__6CLaser(*(undefined4 *)(param_1 + 0x4d4));
  }
  return;
}


// Activate__8CTFSpawn  @ 0010ad50
void Activate__8CTFSpawn(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined4 *local_c;
  
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x458,0);
  iVar1 = (*DAT_0019f6d8)(0,"targetname",*(int *)(param_1 + 0x220) + *(int *)(gpGlobals + 0x98));
  bVar5 = false;
  if ((iVar1 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar1), iVar2 == 0)) {
    bVar5 = true;
  }
  if (bVar5) {
    return;
  }
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    local_c = (undefined4 *)0x0;
  }
  else {
    local_c = *(undefined4 **)(iVar1 + 0x7c);
  }
  iVar1 = 0x12;
  bVar5 = true;
  pcVar3 = (char *)(*(int *)*local_c + *(int *)(gpGlobals + 0x98));
  pcVar4 = "info_tf_teamcheck";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x458,local_c);
  }
  return;
}


