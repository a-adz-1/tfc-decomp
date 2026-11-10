// Activate__10CFuncTrain  @ 000cee00
void Activate__10CFuncTrain(int *param_1)

{
  int iVar1;
  int iVar2;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1[0x13e] == 0) {
    param_1[0x13e] = 1;
    iVar1 = (*DAT_001c1058)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    iVar2 = iVar1 + 0x80;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    *(undefined4 *)(*param_1 + 0x1c8) = *(undefined4 *)(iVar2 + 0x1c8);
    param_1[0x13c] = iVar2;
    iVar1 = *param_1;
    local_c = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xdc) + *(float *)(iVar1 + 0xe8)) * 0.5;
    local_8 = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xe0) + *(float *)(iVar1 + 0xec)) * 0.5;
    local_4 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xe4) + *(float *)(iVar1 + 0xf0)) * 0.5
    ;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,&local_c);
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1cc) == 0) {
      *(float *)(iVar2 + 0x104) = *(float *)(iVar2 + 0x100) + 0.1;
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__10CFuncTrain;
    }
    else {
      *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
    }
  }
  return;
}


// Activate__10CGunTarget  @ 000d23a0
void Activate__10CGunTarget(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float local_c;
  float local_8;
  float local_4;
  
  piVar3 = (int *)(**(code **)(param_1[0x111] + 0xac))(param_1);
  if (piVar3 != (int *)0x0) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x13d,piVar3);
    iVar1 = *param_1;
    iVar2 = *piVar3;
    local_c = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xdc) + *(float *)(iVar1 + 0xe8)) * 0.5;
    local_8 = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xe0) + *(float *)(iVar1 + 0xec)) * 0.5;
    local_4 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xe4) + *(float *)(iVar1 + 0xf0)) * 0.5
    ;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,&local_c);
  }
  return;
}


// Activate__10CLightning  @ 000a0ae8
void Activate__10CLightning(int *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x115]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x115] == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = (*(byte *)(*param_1 + 0x1a0) & 8) == 0;
  }
  if (bVar1) {
    BeamUpdateVars__10CLightning(param_1);
  }
  return;
}


// Activate__10CPathTrack  @ 000cc860
void Activate__10CPathTrack(int *param_1)

{
  if (*(int *)(*param_1 + 0x1cc) != 0) {
    Link__10CPathTrack(param_1);
  }
  return;
}


// Activate__11CBaseEntity  @ 0010fa30
void Activate__11CBaseEntity(void)

{
  return;
}


// Activate__12CCineMonster  @ 000e8fd4
void Activate__12CCineMonster(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  
  iVar2 = (*DAT_001c1058)(0,"targetname",*(int *)(param_1 + 0x694) + *(int *)(gpGlobals + 0x98));
  piVar4 = (int *)0x0;
  while( true ) {
    if (piVar4 != (int *)0x0) goto LAB_000e91b0;
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001c1138)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar3 = iVar2 + 0x80;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    if ((*(byte *)(iVar3 + 0x1a4) & 0x20) != 0) {
      iVar3 = iVar2;
      if ((iVar2 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x7c);
      }
      if (iVar3 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x444) + 0x50))(iVar3);
      }
    }
    iVar2 = (*DAT_001c1058)(iVar2,"targetname",
                            *(int *)(param_1 + 0x694) + *(int *)(gpGlobals + 0x98));
  }
  iVar2 = *(int *)(param_1 + 0x694) + *(int *)(gpGlobals + 0x98);
  pcVar5 = "classname";
  iVar3 = 0;
  while (iVar3 = (*DAT_001c1058)(iVar3,pcVar5,iVar2), piVar4 == (int *)0x0) {
    bVar1 = false;
    if ((iVar3 == 0) || (iVar2 = (*DAT_001c1138)(iVar3), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      return;
    }
    iVar2 = iVar3;
    if ((iVar3 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x7c);
    }
    if (iVar2 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(*(int *)(iVar2 + 0x444) + 0x50))(iVar2);
    }
    iVar2 = *(int *)(param_1 + 0x694) + *(int *)(gpGlobals + 0x98);
    pcVar5 = "targetname";
  }
LAB_000e91b0:
  iVar2 = (*DAT_001c1148)(*(undefined4 *)(*piVar4 + 0x208));
  if (iVar2 != 0) {
    SequencePrecache__FPvPCc(iVar2,*(int *)(param_1 + 0x68c) + *(int *)(gpGlobals + 0x98));
    SequencePrecache__FPvPCc(iVar2,*(int *)(param_1 + 0x690) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Activate__14CFuncTankLaser  @ 000ac7a8
void Activate__14CFuncTankLaser(int param_1)

{
  int iVar1;
  
  iVar1 = GetLaser__14CFuncTankLaser(param_1);
  if (iVar1 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
    (*DAT_001c1114)(4,"Laser tank with no env_laser!\n");
  }
  else {
    TurnOff__6CLaser(*(undefined4 *)(param_1 + 0x4c4));
  }
  return;
}


// Activate__8CTFSpawn  @ 0010875c
void Activate__8CTFSpawn(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x448,0);
  iVar1 = (*DAT_001c1058)(0,"targetname",*(int *)(param_1 + 0x220) + *(int *)(gpGlobals + 0x98));
  bVar6 = false;
  if ((iVar1 == 0) || (iVar2 = (*DAT_001c1138)(iVar1), iVar2 == 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    return;
  }
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(iVar1 + 0x7c);
  }
  iVar1 = 0x12;
  bVar6 = true;
  pcVar4 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar3);
  pcVar5 = "info_tf_teamcheck";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x448,puVar3);
  }
  return;
}


