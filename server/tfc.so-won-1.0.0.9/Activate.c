// Activate__10CFuncTrain  @ 000d2790
void Activate__10CFuncTrain(int *param_1)

{
  int iVar1;
  int iVar2;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_1[0x11f] == 0) {
    param_1[0x11f] = 1;
    iVar2 = (*DAT_001754f8)(0,"targetname",*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98));
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + 0xdc;
    }
    *(undefined4 *)(*param_1 + 0x1a8) = *(undefined4 *)(iVar2 + 0x1a8);
    param_1[0x11d] = iVar2;
    iVar1 = *param_1;
    local_10 = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xbc) + *(float *)(iVar1 + 200)) * 0.5;
    local_c = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xc0) + *(float *)(iVar1 + 0xcc)) * 0.5;
    local_8 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xc4) + *(float *)(iVar1 + 0xd0)) * 0.5
    ;
    UTIL_SetOrigin__FP9entvars_tRC6Vector(iVar1,&local_10);
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1ac) == 0) {
      *(float *)(iVar2 + 0xe4) = *(float *)(iVar2 + 0xe0) + 0.1;
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__10CFuncTrain;
    }
    else {
      *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) | 1;
    }
  }
  return;
}


// Activate__10CGunTarget  @ 000d5790
void Activate__10CGunTarget(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float local_10;
  float local_c;
  float local_8;
  
  piVar3 = (int *)(**(code **)(param_1[0xf2] + 0xa4))(param_1);
  if (piVar3 != (int *)0x0) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x11e,piVar3);
    iVar1 = *param_1;
    iVar2 = *piVar3;
    local_10 = *(float *)(iVar2 + 8) - (*(float *)(iVar1 + 0xbc) + *(float *)(iVar1 + 200)) * 0.5;
    local_c = *(float *)(iVar2 + 0xc) - (*(float *)(iVar1 + 0xc0) + *(float *)(iVar1 + 0xcc)) * 0.5;
    local_8 = *(float *)(iVar2 + 0x10) - (*(float *)(iVar1 + 0xc4) + *(float *)(iVar1 + 0xd0)) * 0.5
    ;
    UTIL_SetOrigin__FP9entvars_tRC6Vector(iVar1,&local_10);
  }
  return;
}


// Activate__10CLightning  @ 000abfe0
void Activate__10CLightning(int *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf6]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0xf6] == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar1 = (*(byte *)(*param_1 + 0x180) & 8) == 0;
  }
  if (bVar1) {
    BeamUpdateVars__10CLightning(param_1);
  }
  return;
}


// Activate__10CPathTrack  @ 000d04c0
void Activate__10CPathTrack(int *param_1)

{
  if (*(int *)(*param_1 + 0x1ac) != 0) {
    Link__10CPathTrack(param_1);
  }
  return;
}


// Activate__11CBaseEntity  @ 0010e540
void Activate__11CBaseEntity(void)

{
  return;
}


// Activate__12CCineMonster  @ 000e7f40
void Activate__12CCineMonster(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  
  iVar2 = (*DAT_001754f8)(0,"targetname",*(int *)(param_1 + 0x618) + *(int *)(gpGlobals + 0x98));
  piVar4 = (int *)0x0;
  while( true ) {
    if (piVar4 != (int *)0x0) goto LAB_000e8104;
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = iVar2 + 0xdc;
    }
    if ((*(byte *)(iVar3 + 0x184) & 0x20) != 0) {
      iVar3 = iVar2;
      if ((iVar2 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xd8);
      }
      if (iVar3 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x3c8) + 0x4c))(iVar3);
      }
    }
    iVar2 = (*DAT_001754f8)(iVar2,"targetname",
                            *(int *)(param_1 + 0x618) + *(int *)(gpGlobals + 0x98));
  }
  iVar3 = *(int *)(param_1 + 0x618) + *(int *)(gpGlobals + 0x98);
  pcVar5 = "classname";
  iVar2 = 0;
  while (iVar2 = (*DAT_001754f8)(iVar2,pcVar5,iVar3), piVar4 == (int *)0x0) {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      return;
    }
    iVar3 = iVar2;
    if ((iVar2 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if (iVar3 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x3c8) + 0x4c))(iVar3);
    }
    iVar3 = *(int *)(param_1 + 0x618) + *(int *)(gpGlobals + 0x98);
    pcVar5 = "targetname";
  }
LAB_000e8104:
  iVar2 = (*DAT_001755e8)(*(undefined4 *)(*piVar4 + 0x1e8));
  if (iVar2 != 0) {
    SequencePrecache__FPvPCc(iVar2,*(int *)(param_1 + 0x610) + *(int *)(gpGlobals + 0x98));
    SequencePrecache__FPvPCc(iVar2,*(int *)(param_1 + 0x614) + *(int *)(gpGlobals + 0x98));
  }
  return;
}


// Activate__14CFuncTankLaser  @ 000b5c30
void Activate__14CFuncTankLaser(int param_1)

{
  int iVar1;
  
  iVar1 = GetLaser__14CFuncTankLaser(param_1);
  if (iVar1 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
    (*DAT_001755b4)(4,"Laser tank with no env_laser!\n");
  }
  else {
    TurnOff__6CLaser(*(undefined4 *)(param_1 + 0x448));
  }
  return;
}


