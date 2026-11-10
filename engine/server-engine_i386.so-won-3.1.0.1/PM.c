// PM_AddToTouched  @ 00069ec4
undefined4 PM_AddToTouched(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_stack_00000034;
  undefined4 uStack00000038;
  undefined4 uStack0000003c;
  undefined4 uStack00000040;
  undefined4 *in_stack_00000048;
  int local_18;
  
  local_18 = 0;
  uVar1 = *(uint *)(pmove + 0x4548c);
  iVar2 = local_18;
  if (0 < (int)uVar1) {
    iVar3 = 0;
    iVar6 = pmove + 0x454c0;
    uVar5 = uVar1 & 3;
    if (uVar5 == 0) goto LAB_00069f44;
    if (1 < uVar5) {
      if (2 < uVar5) {
        if (*(int *)(pmove + 0x454c0) == in_stack_00000034) goto LAB_00069f7a;
        iVar3 = 0x44;
        local_18 = 1;
      }
      iVar2 = local_18;
      if (*(int *)(iVar3 + iVar6) == in_stack_00000034) goto LAB_00069f7a;
      iVar3 = iVar3 + 0x44;
      local_18 = local_18 + 1;
    }
    iVar2 = local_18;
    if (*(int *)(iVar3 + iVar6) != in_stack_00000034) {
      iVar3 = iVar3 + 0x44;
      while (local_18 = local_18 + 1, iVar2 = local_18, local_18 < (int)uVar1) {
LAB_00069f44:
        iVar2 = local_18;
        if ((((*(int *)(iVar3 + iVar6) == in_stack_00000034) ||
             (iVar2 = local_18 + 1, *(int *)(pmove + 0x45504 + iVar3) == in_stack_00000034)) ||
            (iVar2 = local_18 + 2, *(int *)(pmove + 0x45548 + iVar3) == in_stack_00000034)) ||
           (local_18 = local_18 + 3, iVar2 = local_18,
           *(int *)(pmove + 0x4558c + iVar3) == in_stack_00000034)) break;
        iVar3 = iVar3 + 0x110;
      }
    }
  }
LAB_00069f7a:
  local_18 = iVar2;
  if (local_18 == *(int *)(pmove + 0x4548c)) {
    uStack00000038 = *in_stack_00000048;
    uStack0000003c = in_stack_00000048[1];
    uStack00000040 = in_stack_00000048[2];
    if (599 < *(int *)(pmove + 0x4548c)) {
      (**(code **)(pmove + 0x4f564))("Too many entities were touched!\n");
    }
    iVar2 = pmove;
    uVar4 = 1;
    puVar7 = (undefined4 *)
             (pmove + 0x45490 + (*(int *)(pmove + 0x4548c) * 0x10 + *(int *)(pmove + 0x4548c)) * 4);
    for (iVar3 = 0x11; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4),
        iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *(undefined4 *)register0x00000010;
      puVar7 = puVar7 + 1;
    }
    *(int *)(iVar2 + 0x4548c) = *(int *)(iVar2 + 0x4548c) + 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


// PM_GetModelBounds  @ 0006a3a0
void PM_GetModelBounds(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = *(undefined4 *)(param_1 + 0x54);
  param_2[1] = *(undefined4 *)(param_1 + 0x58);
  param_2[2] = *(undefined4 *)(param_1 + 0x5c);
  *param_3 = *(undefined4 *)(param_1 + 0x60);
  param_3[1] = *(undefined4 *)(param_1 + 100);
  param_3[2] = *(undefined4 *)(param_1 + 0x68);
  return;
}


// PM_GetModelType  @ 0006a3d4
undefined4 PM_GetModelType(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}


// PM_HullForBox  @ 0006a5d4
undefined4 * PM_HullForBox(undefined4 *param_1,undefined4 *param_2)

{
  box_planes._12_4_ = *param_2;
  box_planes._32_4_ = *param_1;
  box_planes._52_4_ = param_2[1];
  box_planes._72_4_ = param_1[1];
  box_planes._92_4_ = param_2[2];
  box_planes._112_4_ = param_1[2];
  return &box_hull;
}


// PM_HullForBsp  @ 0006a984
int PM_HullForBsp(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  switch(*(undefined4 *)(pmove + 0xbc)) {
  default:
    iVar4 = *(int *)(param_1 + 0x30) + 0xf8;
    break;
  case 1:
    iVar4 = *(int *)(param_1 + 0x30) + 0x148;
    break;
  case 2:
    iVar4 = *(int *)(param_1 + 0x30) + 0xd0;
    break;
  case 3:
    iVar4 = *(int *)(param_1 + 0x30) + 0x120;
  }
  fVar1 = *(float *)(iVar4 + 0x10) - (float)(&player_mins)[*(int *)(pmove + 0xbc) * 3];
  *param_2 = fVar1;
  fVar2 = *(float *)(iVar4 + 0x14) - (float)(&DAT_000b2ec4)[*(int *)(pmove + 0xbc) * 3];
  param_2[1] = fVar2;
  fVar3 = *(float *)(iVar4 + 0x18) - (float)(&DAT_000b2ec8)[*(int *)(pmove + 0xbc) * 3];
  param_2[2] = fVar3;
  *param_2 = fVar1 + *(float *)(param_1 + 0x24);
  param_2[1] = fVar2 + *(float *)(param_1 + 0x28);
  param_2[2] = fVar3 + *(float *)(param_1 + 0x2c);
  return iVar4;
}


// PM_HullForStudioModel  @ 0006a8c8
void PM_HullForStudioModel
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = (float)(&player_maxs)[*(int *)(pmove + 0xbc) * 3] -
             (float)(&player_mins)[*(int *)(pmove + 0xbc) * 3];
  local_c = (float)(&DAT_000b2f04)[*(int *)(pmove + 0xbc) * 3] -
            (float)(&DAT_000b2ec4)[*(int *)(pmove + 0xbc) * 3];
  local_8 = (float)(&DAT_000b2f08)[*(int *)(pmove + 0xbc) * 3] -
            (float)(&DAT_000b2ec8)[*(int *)(pmove + 0xbc) * 3];
  VectorScale(&local_10,0x3f000000,&local_10);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  R_StudioHull(param_1,param_3,param_4,param_5,param_6,&local_10,param_7,param_8,param_9);
  return;
}


// PM_HullPointContents  @ 0006a620
int PM_HullPointContents(int *param_1,int param_2,float *param_3)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  
  if (param_1[2] < param_1[3]) {
    while (-1 < param_2) {
      if ((param_2 < param_1[2]) || (param_1[3] < param_2)) {
        Sys_Error("PM_HullPointContents: bad node number");
      }
      piVar1 = (int *)(*param_1 + param_2 * 8);
      pfVar2 = (float *)(param_1[1] + *piVar1 * 0x14);
      if (*(byte *)(pfVar2 + 4) < 3) {
        fVar3 = param_3[*(byte *)(pfVar2 + 4)];
      }
      else {
        fVar3 = pfVar2[2] * param_3[2] + pfVar2[1] * param_3[1] + *pfVar2 * *param_3;
      }
      fVar3 = fVar3 - pfVar2[3];
      if ((byte)((0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
        param_2 = (int)(short)piVar1[1];
      }
      else {
        param_2 = (int)*(short *)((int)piVar1 + 6);
      }
    }
  }
  else {
    param_2 = -1;
  }
  return param_2;
}


// PM_Init  @ 0006a080
void PM_Init(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_8;
  
  PM_InitBoxHull();
  local_8 = 0;
  iVar3 = 0;
  do {
    *(undefined4 *)(param_1 + 0x4f4f4 + iVar3) = *(undefined4 *)((int)&player_mins + iVar3);
    *(undefined4 *)(param_1 + 0x4f4f8 + iVar3) = *(undefined4 *)((int)&DAT_000b2ec4 + iVar3);
    *(undefined4 *)(param_1 + 0x4f4fc + iVar3) = *(undefined4 *)((int)&DAT_000b2ec8 + iVar3);
    *(undefined4 *)(param_1 + 0x4f524 + iVar3) = *(undefined4 *)((int)&player_maxs + iVar3);
    *(undefined4 *)(param_1 + 0x4f528 + iVar3) = *(undefined4 *)((int)&DAT_000b2f04 + iVar3);
    iVar1 = iVar3 + 0xc;
    *(undefined4 *)(param_1 + 0x4f52c + iVar3) = *(undefined4 *)((int)&DAT_000b2f08 + iVar3);
    *(undefined4 *)(param_1 + 0x4f4f4 + iVar1) = *(undefined4 *)((int)&DAT_000b2ecc + iVar3);
    *(undefined4 *)(param_1 + 0x4f4f8 + iVar1) = *(undefined4 *)((int)&DAT_000b2ed0 + iVar3);
    *(undefined4 *)(param_1 + 0x4f4fc + iVar1) = *(undefined4 *)((int)&DAT_000b2ed4 + iVar3);
    *(undefined4 *)(param_1 + 0x4f524 + iVar1) = *(undefined4 *)((int)&DAT_000b2f0c + iVar3);
    *(undefined4 *)(param_1 + 0x4f528 + iVar1) = *(undefined4 *)((int)&DAT_000b2f10 + iVar3);
    puVar2 = (undefined4 *)((int)&DAT_000b2f14 + iVar3);
    iVar3 = iVar3 + 0x18;
    *(undefined4 *)(param_1 + 0x4f52c + iVar1) = *puVar2;
    local_8 = local_8 + 2;
  } while (local_8 < 4);
  *(undefined4 **)(param_1 + 0x4f4f0) = &movevars;
  *(code **)(param_1 + 0x4f554) = Info_ValueForKey;
  *(code **)(param_1 + 0x4f558) = CL_Particle;
  *(code **)(param_1 + 0x4f55c) = PM_TestPlayerPosition;
  *(code **)(param_1 + 0x4f560) = Con_NPrintf;
  *(code **)(param_1 + 0x4f564) = Con_DPrintf;
  *(code **)(param_1 + 0x4f568) = Con_Printf;
  *(code **)(param_1 + 0x4f56c) = Sys_FloatTime;
  *(code **)(param_1 + 0x4f570) = PM_StuckTouch;
  *(code **)(param_1 + 0x4f574) = PM_PointContents;
  *(code **)(param_1 + 0x4f578) = PM_TruePointContents;
  *(code **)(param_1 + 0x4f57c) = PM_HullPointContents;
  *(code **)(param_1 + 0x4f580) = PM_PlayerTrace;
  *(code **)(param_1 + 0x4f584) = PM_TraceLine;
  *(code **)(param_1 + 0x4f59c) = PM_TraceModel;
  *(code **)(param_1 + 0x4f588) = RandomLong;
  *(code **)(param_1 + 0x4f58c) = RandomFloat;
  *(code **)(param_1 + 0x4f590) = PM_GetModelType;
  *(code **)(param_1 + 0x4f598) = PM_HullForBsp;
  *(code **)(param_1 + 0x4f594) = PM_GetModelBounds;
  *(code **)(param_1 + 0x4f5a0) = COM_FileSize;
  *(code **)(param_1 + 0x4f5a4) = COM_LoadFile;
  *(code **)(param_1 + 0x4f5a8) = COM_FreeFile;
  *(code **)(param_1 + 0x4f5ac) = memfgets;
  return;
}


// PM_InitBoxHull  @ 0006a3e4
void PM_InitBoxHull(void)

{
  int iVar1;
  uint uVar2;
  uint local_18;
  int local_c;
  
  box_hull = box_clipnodes;
  DAT_00152624 = box_planes;
  local_18 = 0;
  DAT_00152628 = 0;
  DAT_0015262c = 5;
  local_c = 0;
  do {
    iVar1 = local_18 * 8;
    *(uint *)(box_clipnodes + iVar1) = local_18;
    *(undefined2 *)(box_clipnodes + (local_18 & 1) * 2 + iVar1 + 4) = 0xffff;
    if (local_18 == 5) {
      box_clipnodes._44_2_ = 0xfffe;
    }
    else {
      *(short *)(box_clipnodes + (local_18 & 1 ^ 1) * 2 + iVar1 + 4) = (short)local_18 + 1;
    }
    box_planes[local_c + 0x10] = (char)((int)local_18 >> 1);
    *(undefined4 *)(box_planes + local_c + ((int)local_18 >> 1) * 4) = 0x3f800000;
    uVar2 = local_18 + 1;
    iVar1 = uVar2 * 8;
    *(uint *)(box_clipnodes + iVar1) = uVar2;
    *(undefined2 *)(box_clipnodes + (uVar2 & 1) * 2 + iVar1 + 4) = 0xffff;
    if (uVar2 == 5) {
      box_clipnodes._44_2_ = 0xfffe;
    }
    else {
      *(short *)(box_clipnodes + (uVar2 & 1 ^ 1) * 2 + iVar1 + 4) = (short)uVar2 + 1;
    }
    box_planes[local_c + 0x24] = (char)((int)uVar2 >> 1);
    *(undefined4 *)(box_planes + local_c + ((int)uVar2 >> 1) * 4 + 0x14) = 0x3f800000;
    uVar2 = local_18 + 2;
    iVar1 = uVar2 * 8;
    *(uint *)(box_clipnodes + iVar1) = uVar2;
    *(undefined2 *)(box_clipnodes + (uVar2 & 1) * 2 + iVar1 + 4) = 0xffff;
    if (uVar2 == 5) {
      box_clipnodes._44_2_ = 0xfffe;
    }
    else {
      *(short *)(box_clipnodes + (uVar2 & 1 ^ 1) * 2 + iVar1 + 4) = (short)uVar2 + 1;
    }
    box_planes[local_c + 0x38] = (char)((int)uVar2 >> 1);
    *(undefined4 *)(box_planes + local_c + ((int)uVar2 >> 1) * 4 + 0x28) = 0x3f800000;
    local_c = local_c + 0x3c;
    local_18 = local_18 + 3;
  } while ((int)local_18 < 6);
  return;
}


// PM_LinkContents  @ 0006a6d0
undefined4 PM_LinkContents(float *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = 1;
  if (1 < *(int *)(pmove + 0x24c)) {
    local_14 = 0x330;
    do {
      iVar2 = local_14 + pmove;
      if ((*(int *)(iVar2 + 0x60) == 0) && (iVar1 = *(int *)(iVar2 + 0x30), iVar1 != 0)) {
        local_10 = *param_1 - *(float *)(iVar2 + 0x24);
        local_c = param_1[1] - *(float *)(iVar2 + 0x28);
        local_8 = param_1[2] - *(float *)(iVar2 + 0x2c);
        iVar1 = PM_HullPointContents(iVar1 + 0xd0,*(undefined4 *)(iVar1 + 0xd8),&local_10);
        if (iVar1 != -1) {
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = *(undefined4 *)(iVar2 + 0x50);
          }
          return *(undefined4 *)(iVar2 + 100);
        }
      }
      local_14 = local_14 + 0xe0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(pmove + 0x24c));
  }
  return 0xffffffff;
}


// PM_PlayerTrace  @ 0006b994
undefined4 *
PM_PlayerTrace(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  _PM_PlayerTrace(local_48,param_2,param_3,param_4,*(undefined4 *)(pmove + 0x24c),pmove + 0x250,
                  param_5);
  puVar2 = local_48;
  puVar3 = param_1;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// PM_PointContents  @ 0006a794
int PM_PointContents(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(pmove + 0x280) + 0xd0;
  if (iVar2 == 0) {
    if (param_2 != (int *)0x0) {
      *param_2 = -1;
    }
    iVar2 = -2;
  }
  else {
    iVar2 = PM_HullPointContents(iVar2,*(undefined4 *)(*(int *)(pmove + 0x280) + 0xd8),param_1);
    if (param_2 != (int *)0x0) {
      *param_2 = iVar2;
    }
    if (iVar2 + 0xeU < 6) {
      iVar2 = -3;
    }
    if ((iVar2 != -2) && (iVar1 = PM_LinkContents(param_1,0), iVar1 != -1)) {
      return iVar1;
    }
  }
  return iVar2;
}


// PM_RecursiveHullCheck  @ 0006baa0
undefined4
PM_RecursiveHullCheck
          (int *param_1,int param_2,float param_3,float param_4,float *param_5,float *param_6,
          int *param_7)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  float fVar10;
  float *pfVar11;
  uint local_40;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_2 < 0) {
    if (param_2 == -2) {
      param_7[1] = 1;
    }
    else {
      *param_7 = 0;
      if (param_2 == -1) {
        param_7[2] = 1;
      }
      else {
        param_7[3] = 1;
      }
    }
    return 1;
  }
  if (param_1[3] <= param_1[2]) {
    *param_7 = 0;
    param_7[2] = 1;
    return 1;
  }
  piVar1 = (int *)(*param_1 + param_2 * 8);
  pfVar2 = (float *)(param_1[1] + *piVar1 * 0x14);
  if (*(byte *)(pfVar2 + 4) < 3) {
    fVar10 = pfVar2[3];
    fVar5 = param_5[*(byte *)(pfVar2 + 4)] - fVar10;
    fVar3 = param_6[*(byte *)(pfVar2 + 4)];
  }
  else {
    fVar3 = pfVar2[2] * param_6[2] + pfVar2[1] * param_6[1] + *pfVar2 * *param_6;
    fVar10 = pfVar2[3];
    fVar5 = (pfVar2[2] * param_5[2] + pfVar2[1] * param_5[1] + *pfVar2 * *param_5) - fVar10;
  }
  fVar3 = fVar3 - fVar10;
  fVar10 = param_3;
  pfVar11 = param_5;
  if (fVar5 < 0.0) {
LAB_0006bbde:
    if (0x3f < (byte)((0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) - 1)) {
      iVar6 = (int)*(short *)((int)piVar1 + 6);
      goto LAB_0006bd70;
    }
    if ((byte)((0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) - 1) < 0x40) goto LAB_0006bc2c;
    fVar4 = fVar5 + 0.03125;
  }
  else {
    if (0.0 <= fVar3) {
      iVar6 = (int)(short)piVar1[1];
      goto LAB_0006bd70;
    }
    if (0x3f < (byte)((0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) - 1)) goto LAB_0006bbde;
LAB_0006bc2c:
    fVar4 = fVar5 - 0.03125;
  }
  fVar4 = fVar4 / (fVar5 - fVar3);
  if (0x3f < (byte)((0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) - 1)) {
    fVar4 = 0.0;
  }
  if (1.0 < fVar4) {
    fVar4 = 1.0;
  }
  fVar10 = (param_4 - param_3) * fVar4 + param_3;
  pfVar11 = &local_10;
  local_10 = fVar4 * (*param_6 - *param_5) + *param_5;
  local_c = fVar4 * (param_6[1] - param_5[1]) + param_5[1];
  local_8 = fVar4 * (param_6[2] - param_5[2]) + param_5[2];
  bVar9 = (byte)(fVar5 < 0.0 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 1;
  uVar7 = (uint)bVar9;
  iVar6 = PM_RecursiveHullCheck
                    (param_1,(int)*(short *)(uVar7 * 2 + 4 + (int)piVar1),param_3,fVar10,param_5,
                     pfVar11,param_7);
  if (iVar6 != 0) {
    local_40 = (uint)!bVar9;
    iVar6 = PM_HullPointContents(param_1,(int)*(short *)(local_40 * 2 + 4 + (int)piVar1),pfVar11);
    if (iVar6 != -2) {
      iVar6 = (int)*(short *)(local_40 * 2 + 4 + (int)piVar1);
LAB_0006bd70:
      uVar8 = PM_RecursiveHullCheck(param_1,iVar6,fVar10,param_4,pfVar11,param_6,param_7);
      return uVar8;
    }
    if (*param_7 == 0) {
      if (uVar7 == 0) {
        param_7[8] = (int)*pfVar2;
        param_7[9] = (int)pfVar2[1];
        param_7[10] = (int)pfVar2[2];
        param_7[0xb] = (int)pfVar2[3];
      }
      else {
        param_7[8] = (int)(vec3_origin - *pfVar2);
        param_7[9] = (int)(DAT_000b2e2c - pfVar2[1]);
        param_7[10] = (int)(DAT_000b2e30 - pfVar2[2]);
        param_7[0xb] = (int)-pfVar2[3];
      }
      while( true ) {
        iVar6 = PM_HullPointContents(param_1,param_1[2],pfVar11);
        if (iVar6 != -2) {
          param_7[4] = (int)fVar10;
          param_7[5] = (int)local_10;
          param_7[6] = (int)local_c;
          param_7[7] = (int)local_8;
          return 0;
        }
        fVar4 = fVar4 - 0.05;
        if (fVar4 < 0.0) break;
        fVar10 = param_3 + (param_4 - param_3) * fVar4;
        local_10 = fVar4 * (*param_6 - *param_5) + *param_5;
        local_c = fVar4 * (param_6[1] - param_5[1]) + param_5[1];
        local_8 = fVar4 * (param_6[2] - param_5[2]) + param_5[2];
      }
      param_7[4] = (int)fVar10;
      param_7[5] = (int)local_10;
      param_7[6] = (int)local_c;
      param_7[7] = (int)local_8;
      Con_DPrintf("Trace backed up past 0.0.\n");
    }
  }
  return 0;
}


// PM_SV_PlaySound  @ 0007fca8
void PM_SV_PlaySound(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)

{
  SV_StartSound(1,*(undefined4 *)(host_client + 0x4ae4),param_1,param_2,(int)ROUND(param_3 * 255.0),
                param_4,param_5,param_6);
  return;
}


// PM_SV_PlaybackEventFull  @ 0007fc40
void PM_SV_PlaybackEventFull
               (uint param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  EV_SV_Playback(param_1 | 1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                 param_10,param_11,param_12);
  return;
}


// PM_SV_TraceTexture  @ 0007fd18
undefined4 PM_SV_TraceTexture(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 < 0) || (*(int *)(pmove + 0x24c) <= param_1)) ||
      (iVar1 = pmove + 0x250 + param_1 * 0xe0, *(int *)(iVar1 + 0x30) == 0)) ||
     (((iVar1 = *(int *)(iVar1 + 0x50), iVar1 < 0 || (DAT_00186f90 <= iVar1)) ||
      (iVar1 = DAT_00186f94 + iVar1 * 0x324, iVar1 == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = TraceTexture(iVar1,param_2,param_3);
  }
  return uVar2;
}


// PM_StuckTouch  @ 0006a004
void PM_StuckTouch(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 auStack_58 [16];
  undefined4 uStack_18;
  int iStack_14;
  
  if ((*(int *)(pmove + 4) != 0) && (*(int *)(pmove + 0xd8) == 0)) {
    iStack_14 = *(undefined4 *)(param_1 * 0xe0 + 0x2a0 + pmove);
    uStack_18 = 0x6a04c;
    iVar1 = EDICT_NUM();
    if ((*(byte *)(iVar1 + 0x227) & 4) == 0) {
      iStack_14 = pmove + 0x5c;
      puVar2 = auStack_58;
      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
      PM_AddToTouched();
    }
  }
  return;
}


// PM_TestPlayerPosition  @ 0006aa84
int PM_TestPlayerPosition(float *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  undefined4 local_78 [17];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  PM_PlayerTrace(local_78,pmove + 0x38,pmove + 0x38,0,0xffffffff);
  if (param_2 != (undefined4 *)0x0) {
    puVar6 = local_78;
    for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
      *param_2 = *puVar6;
      puVar6 = puVar6 + 1;
      param_2 = param_2 + 1;
    }
  }
  local_b0 = 0;
  if (0 < *(int *)(pmove + 0x24c)) {
    local_b8 = 0x250;
    do {
      iVar5 = local_b8 + pmove;
      if (((*(int *)(iVar5 + 0x30) == 0) || (*(int *)(iVar5 + 0x60) != 0)) ||
         (*(int *)(iVar5 + 100) == 0)) {
        local_ac = 1;
        local_34 = *(float *)(iVar5 + 0x24);
        local_30 = *(float *)(iVar5 + 0x28);
        local_2c = *(float *)(iVar5 + 0x2c);
        if (*(int *)(iVar5 + 0x30) == 0) {
          iVar4 = *(int *)(iVar5 + 0x34);
          if (((iVar4 == 0) || (*(int *)(iVar4 + 0x44) != 3)) ||
             (((*(byte *)(iVar4 + 0x51) & 2) == 0 && (*(int *)(pmove + 0xbc) != 2)))) {
            local_10 = *(float *)(iVar5 + 0x38) - (float)(&player_maxs)[*(int *)(pmove + 0xbc) * 3];
            local_c = *(float *)(iVar5 + 0x3c) - (float)(&DAT_000b2f04)[*(int *)(pmove + 0xbc) * 3];
            local_8 = *(float *)(iVar5 + 0x40) - (float)(&DAT_000b2f08)[*(int *)(pmove + 0xbc) * 3];
            local_1c = *(float *)(iVar5 + 0x44) - (float)(&player_mins)[*(int *)(pmove + 0xbc) * 3];
            local_18 = *(float *)(iVar5 + 0x48) - (float)(&DAT_000b2ec4)[*(int *)(pmove + 0xbc) * 3]
            ;
            local_14 = *(float *)(iVar5 + 0x4c) - (float)(&DAT_000b2ec8)[*(int *)(pmove + 0xbc) * 3]
            ;
            iVar4 = PM_HullForBox(&local_10,&local_1c);
          }
          else {
            iVar4 = PM_HullForStudioModel
                              (iVar4,&local_34,*(undefined4 *)(iVar5 + 0x6c),
                               *(undefined4 *)(iVar5 + 0x70),iVar5 + 0x54,iVar5 + 0x24,iVar5 + 0x74,
                               iVar5 + 0x78,&local_ac);
          }
        }
        else {
          iVar4 = PM_HullForBsp(iVar5,&local_34);
        }
        local_28 = *param_1 - local_34;
        local_24 = param_1[1] - local_30;
        local_20 = param_1[2] - local_2c;
        if ((*(int *)(iVar5 + 0x60) == 4) &&
           ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar5 + 0x54)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(iVar5 + 0x54) == 0.0) << 0xe) >> 8)) != 0x40
             || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar5 + 0x58)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(*(float *)(iVar5 + 0x58) == 0.0) << 0xe) >> 8)) !=
                 0x40)) ||
            (fVar1 = *(float *)(iVar5 + 0x5c),
            (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)))) {
          AngleVectors(iVar5 + 0x54,&local_84,&local_90,&local_9c);
          fVar2 = local_24 * local_80;
          fVar3 = local_20 * local_7c;
          local_a8 = local_28;
          local_a4 = local_24;
          fVar1 = local_20 * local_88;
          local_a0 = local_20;
          local_20 = local_20 * local_94 + local_28 * local_9c + local_24 * local_98;
          local_24 = -(fVar1 + local_28 * local_90 + local_24 * local_8c);
          local_28 = fVar3 + fVar2 + local_28 * local_84;
        }
        if (local_ac == 1) {
          g_contentsresult = PM_HullPointContents(iVar4,*(undefined4 *)(iVar4 + 8),&local_28);
          if (g_contentsresult == -2) {
            return local_b0;
          }
        }
        else {
          local_b4 = 0;
          if (0 < local_ac) {
            puVar6 = (undefined4 *)(iVar4 + 8);
            do {
              g_contentsresult = PM_HullPointContents(iVar4,*puVar6,&local_28);
              if (g_contentsresult == -2) {
                return local_b0;
              }
              iVar4 = iVar4 + 0x28;
              puVar6 = puVar6 + 10;
              local_b4 = local_b4 + 1;
            } while (local_b4 < local_ac);
          }
        }
      }
      local_b8 = local_b8 + 0xe0;
      local_b0 = local_b0 + 1;
    } while (local_b0 < *(int *)(pmove + 0x24c));
  }
  return -1;
}


// PM_TraceLine  @ 0006b9fc
undefined1 *
PM_TraceLine(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(pmove + 0xbc);
  *(undefined4 *)(pmove + 0xbc) = param_4;
  if (param_3 == 0) {
    PM_PlayerTrace(tr_32,param_1,param_2,0,param_5);
  }
  else {
    _PM_PlayerTrace(tr_32,param_1,param_2,0,*(undefined4 *)("Draw_CacheWadHandler" + pmove + 8),
                    "Draw_CacheWadHandler" + pmove + 0xc,param_5);
  }
  *(undefined4 *)(pmove + 0xbc) = uVar1;
  return tr_32;
}


// PM_TraceModel  @ 0006a2e4
longdouble PM_TraceModel(undefined4 param_1,float *param_2,float *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  uVar1 = *(undefined4 *)(pmove + 0xbc);
  *(undefined4 *)(pmove + 0xbc) = 2;
  iVar2 = PM_HullForBsp(param_1,&local_28);
  *(undefined4 *)(pmove + 0xbc) = uVar1;
  local_10 = *param_2 - local_28;
  local_c = param_2[1] - local_24;
  local_8 = param_2[2] - local_20;
  local_1c = *param_3 - local_28;
  local_18 = param_3[1] - local_24;
  local_14 = param_3[2] - local_20;
  SV_RecursiveHullCheck(iVar2,*(undefined4 *)(iVar2 + 8),0,0x3f800000,&local_10,&local_1c,param_4);
  *(undefined4 *)(param_4 + 0x30) = 0;
  return (longdouble)*(float *)(param_4 + 0x10);
}


// PM_TruePointContents  @ 0006a880
undefined4 PM_TruePointContents(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(pmove + 0x280) + 0xd0;
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = PM_HullPointContents(iVar2,*(undefined4 *)(*(int *)(pmove + 0x280) + 0xd8),param_1);
  }
  return uVar1;
}


// PM_WaterEntity  @ 0006a818
undefined4 PM_WaterEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  iVar1 = PM_HullPointContents
                    (*(int *)(pmove + 0x280) + 0xd0,*(undefined4 *)(*(int *)(pmove + 0x280) + 0xd8),
                     param_1);
  if (iVar1 < -2) {
    local_8 = 0;
  }
  if (iVar1 != -2) {
    PM_LinkContents(param_1,&local_8);
  }
  return local_8;
}


