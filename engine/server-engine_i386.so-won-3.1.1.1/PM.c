// PM_AddToTouched  @ 000830f4
undefined4 PM_AddToTouched(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_stack_00000034;
  undefined4 uStack00000038;
  undefined4 uStack0000003c;
  undefined4 uStack00000040;
  undefined4 *in_stack_00000048;
  int local_8;
  
  for (local_8 = 0;
      (local_8 < *(int *)((int)&__DT_JMPREL[0x3e6].r_info + pmove) &&
      (*(int *)(local_8 * 0x44 + pmove + 0x454c0) != in_stack_00000034)); local_8 = local_8 + 1) {
  }
  if (local_8 == *(int *)((int)&__DT_JMPREL[0x3e6].r_info + pmove)) {
    uStack00000038 = *in_stack_00000048;
    uStack0000003c = in_stack_00000048[1];
    uStack00000040 = in_stack_00000048[2];
    if (599 < *(int *)((int)&__DT_JMPREL[0x3e6].r_info + pmove)) {
      (**(code **)(pmove + 0x4f564))("Too many entities were touched!\n");
    }
    iVar2 = pmove;
    puVar5 = (undefined4 *)
             ((int)__DT_JMPREL +
             *(int *)((int)&__DT_JMPREL[0x3e6].r_info + pmove) * 0x44 + pmove + 0x1f38);
    for (iVar4 = 0x11; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4),
        iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *(undefined4 *)register0x00000010;
      puVar5 = puVar5 + 1;
    }
    piVar1 = (int *)((int)&__DT_JMPREL[0x3e6].r_info + iVar2);
    *piVar1 = *piVar1 + 1;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// PM_GetModelBounds  @ 00083704
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


// PM_GetModelType  @ 0008375c
undefined4 PM_GetModelType(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}


// PM_HullForBox  @ 000838d4
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


// PM_HullForBsp  @ 00083f2c
int PM_HullForBsp(int param_1,float *param_2)

{
  int local_8;
  
  switch(*(undefined4 *)(pmove + 0xbc)) {
  default:
    local_8 = *(int *)(param_1 + 0x30) + 0xf8;
    break;
  case 1:
    local_8 = *(int *)(param_1 + 0x30) + 0x148;
    break;
  case 2:
    local_8 = *(int *)(param_1 + 0x30) + 0xd0;
    break;
  case 3:
    local_8 = *(int *)(param_1 + 0x30) + 0x120;
  }
  *param_2 = *(float *)(local_8 + 0x10) - *(float *)(player_mins + *(int *)(pmove + 0xbc) * 0xc);
  param_2[1] = *(float *)(local_8 + 0x14) -
               *(float *)(player_mins + *(int *)(pmove + 0xbc) * 0xc + 4);
  param_2[2] = *(float *)(local_8 + 0x18) -
               *(float *)(player_mins + *(int *)(pmove + 0xbc) * 0xc + 8);
  *param_2 = *param_2 + *(float *)(param_1 + 0x24);
  param_2[1] = param_2[1] + *(float *)(param_1 + 0x28);
  param_2[2] = param_2[2] + *(float *)(param_1 + 0x2c);
  return local_8;
}


// PM_HullForStudioModel  @ 00083da0
undefined4
PM_HullForStudioModel
          (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9)

{
  undefined4 uVar1;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(player_maxs + *(int *)(pmove + 0xbc) * 0xc) -
             *(float *)(player_mins + *(int *)(pmove + 0xbc) * 0xc);
  local_c = *(float *)(player_maxs + *(int *)(pmove + 0xbc) * 0xc + 4) -
            *(float *)(player_mins + *(int *)(pmove + 0xbc) * 0xc + 4);
  local_8 = *(float *)(player_maxs + *(int *)(pmove + 0xbc) * 0xc + 8) -
            *(float *)(player_mins + *(int *)(pmove + 0xbc) * 0xc + 8);
  VectorScale(&local_10,0x3f000000,&local_10);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  uVar1 = R_StudioHull(param_1,param_3,param_4,param_5,param_6,&local_10,param_7,param_8,param_9,0,0
                      );
  return uVar1;
}


// PM_HullPointContents  @ 00083958
int PM_HullPointContents(int *param_1,int param_2,float *param_3)

{
  short sVar1;
  int *piVar2;
  float *pfVar3;
  float local_8;
  
  if (param_1[2] < param_1[3]) {
    while (-1 < param_2) {
      if ((param_2 < param_1[2]) || (param_1[3] < param_2)) {
        Sys_Error("PM_HullPointContents: bad node number");
      }
      piVar2 = (int *)(*param_1 + param_2 * 8);
      pfVar3 = (float *)(param_1[1] + *piVar2 * 0x14);
      if (*(byte *)(pfVar3 + 4) < 3) {
        local_8 = param_3[*(byte *)(pfVar3 + 4)] - pfVar3[3];
      }
      else {
        local_8 = (pfVar3[2] * param_3[2] + pfVar3[1] * param_3[1] + *pfVar3 * *param_3) - pfVar3[3]
        ;
      }
      if (0.0 <= local_8) {
        sVar1 = (short)piVar2[1];
      }
      else {
        sVar1 = *(short *)((int)piVar2 + 6);
      }
      param_2 = (int)sVar1;
    }
  }
  else {
    param_2 = -1;
  }
  return param_2;
}


// PM_Init  @ 000832b8
void PM_Init(int param_1)

{
  int local_8;
  
  PM_InitBoxHull();
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(local_8 * 0xc + param_1 + 0x4f4f4) =
         *(undefined4 *)(player_mins + local_8 * 0xc);
    *(undefined4 *)(local_8 * 0xc + param_1 + 0x4f4f8) =
         *(undefined4 *)(player_mins + local_8 * 0xc + 4);
    *(undefined4 *)(local_8 * 0xc + param_1 + 0x4f4fc) =
         *(undefined4 *)(player_mins + local_8 * 0xc + 8);
    *(undefined4 *)(local_8 * 0xc + param_1 + 0x4f524) =
         *(undefined4 *)(player_maxs + local_8 * 0xc);
    *(undefined4 *)(local_8 * 0xc + param_1 + 0x4f528) =
         *(undefined4 *)(player_maxs + local_8 * 0xc + 4);
    *(undefined4 *)(local_8 * 0xc + param_1 + 0x4f52c) =
         *(undefined4 *)(player_maxs + local_8 * 0xc + 8);
  }
  *(undefined4 **)(__out_of_range__FPCc + param_1) = &movevars;
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
  *(code **)(&DAT_0004f5c0 + param_1) = PM_PlayerTraceEx;
  *(code **)(&DAT_0004f5c4 + param_1) = PM_TestPlayerPositionEx;
  *(code **)(&DAT_0004f5c8 + param_1) = PM_TraceLineEx;
  return;
}


// PM_InitBoxHull  @ 00083770
void PM_InitBoxHull(void)

{
  uint local_8;
  
  box_hull = box_clipnodes;
  DAT_00362bc4 = box_planes;
  DAT_00362bc8 = 0;
  DAT_00362bcc = 5;
  for (local_8 = 0; (int)local_8 < 6; local_8 = local_8 + 1) {
    *(uint *)(box_clipnodes + local_8 * 8) = local_8;
    *(undefined2 *)(box_clipnodes + (local_8 & 1) * 2 + local_8 * 8 + 4) = 0xffff;
    if (local_8 == 5) {
      box_clipnodes._44_2_ = 0xfffe;
    }
    else {
      *(short *)(box_clipnodes + (local_8 & 1 ^ 1) * 2 + local_8 * 8 + 4) = (short)local_8 + 1;
    }
    box_planes[local_8 * 0x14 + 0x10] = (char)((int)local_8 >> 1);
    *(undefined4 *)(box_planes + ((int)local_8 >> 1) * 4 + local_8 * 0x14) = 0x3f800000;
  }
  return;
}


// PM_LinkContents  @ 00083a90
undefined4 PM_LinkContents(float *param_1,undefined4 *param_2)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  
  local_8 = 1;
  do {
    if (*(int *)(pmove + 0x24c) <= local_8) {
      return 0xffffffff;
    }
    local_c = pmove + local_8 * 0xe0 + 0x250;
    if ((*(int *)(local_c + 0x60) == 0) && (*(int *)(local_c + 0x30) != 0)) {
      local_18 = *param_1 - *(float *)(local_c + 0x24);
      local_14 = param_1[1] - *(float *)(local_c + 0x28);
      local_10 = param_1[2] - *(float *)(local_c + 0x2c);
      iVar1 = PM_HullPointContents
                        (*(int *)(local_c + 0x30) + 0xd0,
                         *(undefined4 *)(*(int *)(local_c + 0x30) + 0xd8),&local_18);
      if (iVar1 != -1) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = *(undefined4 *)(local_c + 0x50);
        }
        return *(undefined4 *)(local_c + 100);
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}


// PM_PlayerTrace  @ 00085980
undefined4 *
PM_PlayerTrace(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  _PM_PlayerTrace(local_48,param_2,param_3,param_4,*(undefined4 *)(pmove + 0x24c),pmove + 0x250,
                  param_5,0);
  puVar2 = local_48;
  puVar3 = param_1;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// PM_PlayerTraceEx  @ 000859f4
undefined4 *
PM_PlayerTraceEx(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  _PM_PlayerTrace(local_48,param_2,param_3,param_4,*(undefined4 *)(pmove + 0x24c),pmove + 0x250,
                  0xffffffff,param_5);
  puVar2 = local_48;
  puVar3 = param_1;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


// PM_PointContents  @ 00083bac
int PM_PointContents(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_10;
  
  (*(code *)g_engdstAddrs._228_4_)(&param_1,&param_2);
  iVar1 = *(int *)(pmove + 0x280) + 0xd0;
  if (iVar1 == 0) {
    if (param_2 != (int *)0x0) {
      *param_2 = -1;
    }
    local_10 = -2;
  }
  else {
    local_10 = PM_HullPointContents(iVar1,*(undefined4 *)(*(int *)(pmove + 0x280) + 0xd8),param_1);
    if (param_2 != (int *)0x0) {
      *param_2 = local_10;
    }
    if ((local_10 < -8) && (-0xf < local_10)) {
      local_10 = -3;
    }
    if ((local_10 != -2) && (iVar1 = PM_LinkContents(param_1,0), iVar1 != -1)) {
      local_10 = iVar1;
    }
  }
  return local_10;
}


// PM_RecursiveHullCheck  @ 00085c38
undefined4
PM_RecursiveHullCheck
          (int *param_1,int param_2,float param_3,float param_4,float *param_5,float *param_6,
          int *param_7)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  float local_34;
  float local_28;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float *local_c;
  int *local_8;
  
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
    uVar1 = 1;
  }
  else if (param_1[2] < param_1[3]) {
    local_8 = (int *)(*param_1 + param_2 * 8);
    local_c = (float *)(param_1[1] + *local_8 * 0x14);
    if (*(byte *)(local_c + 4) < 3) {
      local_10 = param_5[*(byte *)(local_c + 4)] - local_c[3];
      local_14 = param_6[*(byte *)(local_c + 4)] - local_c[3];
    }
    else {
      local_10 = (local_c[2] * param_5[2] + local_c[1] * param_5[1] + *local_c * *param_5) -
                 local_c[3];
      local_14 = (local_c[2] * param_6[2] + local_c[1] * param_6[1] + *local_c * *param_6) -
                 local_c[3];
    }
    if (((byte)((0.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) - 1) < 0x40) &&
       ((byte)((0.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) - 1) < 0x40)) {
      uVar1 = PM_RecursiveHullCheck
                        (param_1,(int)(short)local_8[1],param_3,param_4,param_5,param_6,param_7);
    }
    else if ((0.0 <= local_10) || (0.0 <= local_14)) {
      if (0.0 <= local_10) {
        local_18 = (local_10 - 0.03125) / (local_10 - local_14);
      }
      else {
        local_18 = (local_10 + 0.03125) / (local_10 - local_14);
      }
      if (local_18 < 0.0) {
        local_18 = 0.0;
      }
      if ((byte)(1.0 < local_18 | (byte)((ushort)((ushort)NAN(local_18) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_18 == 1.0) << 0xe) >> 8)) == 1) {
        local_18 = 1.0;
      }
      local_34 = param_3 + (param_4 - param_3) * local_18;
      for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
        (&local_28)[local_1c] =
             param_5[local_1c] + (param_6[local_1c] - param_5[local_1c]) * local_18;
      }
      uVar3 = (uint)(local_10 < 0.0);
      iVar2 = PM_RecursiveHullCheck
                        (param_1,(int)*(short *)(uVar3 * 2 + 4 + (int)local_8),param_3,local_34,
                         param_5,&local_28,param_7);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        iVar2 = PM_HullPointContents
                          (param_1,(int)*(short *)((uVar3 ^ 1) * 2 + 4 + (int)local_8),&local_28);
        if (iVar2 == -2) {
          if (*param_7 == 0) {
            if (uVar3 == 0) {
              param_7[8] = (int)*local_c;
              param_7[9] = (int)local_c[1];
              param_7[10] = (int)local_c[2];
              param_7[0xb] = (int)local_c[3];
            }
            else {
              param_7[8] = (int)(vec3_origin - *local_c);
              param_7[9] = (int)(DAT_000f1be0 - local_c[1]);
              param_7[10] = (int)(DAT_000f1be4 - local_c[2]);
              param_7[0xb] = (int)-local_c[3];
            }
            while (iVar2 = PM_HullPointContents(param_1,param_1[2],&local_28), iVar2 == -2) {
              local_18 = local_18 - 0.05;
              if (local_18 < 0.0) {
                param_7[4] = (int)local_34;
                param_7[5] = (int)local_28;
                param_7[6] = local_24;
                param_7[7] = local_20;
                Con_DPrintf("Trace backed up past 0.0.\n");
                return 0;
              }
              local_34 = param_3 + (param_4 - param_3) * local_18;
              for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
                (&local_28)[local_1c] =
                     param_5[local_1c] + (param_6[local_1c] - param_5[local_1c]) * local_18;
              }
            }
            param_7[4] = (int)local_34;
            param_7[5] = (int)local_28;
            param_7[6] = local_24;
            param_7[7] = local_20;
            uVar1 = 0;
          }
          else {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = PM_RecursiveHullCheck
                            (param_1,(int)*(short *)((uVar3 ^ 1) * 2 + 4 + (int)local_8),local_34,
                             param_4,&local_28,param_6,param_7);
        }
      }
    }
    else {
      uVar1 = PM_RecursiveHullCheck
                        (param_1,(int)*(short *)((int)local_8 + 6),param_3,param_4,param_5,param_6,
                         param_7);
    }
  }
  else {
    *param_7 = 0;
    param_7[2] = 1;
    uVar1 = 1;
  }
  return uVar1;
}


// PM_SV_PlaySound  @ 000b0b20
void PM_SV_PlaySound(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)

{
  SV_StartSound(1,*(undefined4 *)(host_client + 0x4a84),param_1,param_2,(int)ROUND(param_3 * 255.0),
                param_4,param_5,param_6);
  return;
}


// PM_SV_PlaybackEventFull  @ 000b0ab0
void PM_SV_PlaybackEventFull
               (uint param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  EV_SV_Playback(param_1 | 1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                 param_10,param_11,param_12);
  return;
}


// PM_SV_TraceTexture  @ 000b0b94
undefined4 PM_SV_TraceTexture(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 < 0) || (*(int *)(pmove + 0x24c) <= param_1)) {
    uVar1 = 0;
  }
  else {
    iVar2 = pmove + param_1 * 0xe0 + 0x250;
    if (*(int *)(iVar2 + 0x30) == 0) {
      uVar1 = 0;
    }
    else if ((*(int *)(iVar2 + 0x50) < 0) || (DAT_003a78b4 <= *(int *)(iVar2 + 0x50))) {
      uVar1 = 0;
    }
    else {
      iVar2 = DAT_003a78b8 + *(int *)(iVar2 + 0x50) * 0x324;
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = TraceTexture(iVar2,param_2,param_3);
      }
    }
  }
  return uVar1;
}


// PM_StuckTouch  @ 00083220
void PM_StuckTouch(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 auStack_7c [15];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_30;
  
  uStack_30 = 0x8322e;
  if (*(int *)(pmove + 4) != 0) {
    uStack_3c = *(undefined4 *)(param_1 * 0xe0 + pmove + 0x2a0);
    uStack_40 = 0x8327a;
    EDICT_NUM();
    iStack_38 = pmove + 0x5c;
    puVar2 = auStack_7c;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    PM_AddToTouched();
  }
  return;
}


// PM_TestPlayerPosition  @ 000845e8
undefined4 PM_TestPlayerPosition(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _PM_TestPlayerPosition(param_1,param_2,0,0x845f4);
  return uVar1;
}


// PM_TestPlayerPositionEx  @ 00084620
undefined4 PM_TestPlayerPositionEx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = _PM_TestPlayerPosition(param_1,param_2,param_3,0x8462c);
  return uVar1;
}


// PM_TraceLine  @ 00085a68
undefined1 *
PM_TraceLine(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  (*(code *)g_engdstAddrs._236_4_)(&param_1,&param_2,&param_3,&param_4,&param_5);
  uVar1 = *(undefined4 *)(pmove + 0xbc);
  *(undefined4 *)(pmove + 0xbc) = param_4;
  if (param_3 == 0) {
    _PM_PlayerTrace(tr_57,param_1,param_2,0,*(undefined4 *)(pmove + 0x24c),pmove + 0x250,param_5,0);
  }
  else if (param_3 == 1) {
    _PM_PlayerTrace(tr_57,param_1,param_2,0,
                    *(undefined4 *)
                     (
                     "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                     + pmove + 0x7f),
                    "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                    + pmove + 0x83,param_5,0);
  }
  *(undefined4 *)(pmove + 0xbc) = uVar1;
  return tr_57;
}


// PM_TraceLineEx  @ 00085b78
undefined1 *
PM_TraceLineEx(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
              undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(pmove + 0xbc);
  *(undefined4 *)(pmove + 0xbc) = param_4;
  if (param_3 == 0) {
    PM_PlayerTraceEx(tr_61,param_1,param_2,0,param_5);
  }
  else {
    _PM_PlayerTrace(tr_61,param_1,param_2,0,
                    *(undefined4 *)
                     (
                     "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                     + pmove + 0x7f),
                    "__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21"
                    + pmove + 0x83,0xffffffff,param_5);
  }
  *(undefined4 *)(pmove + 0xbc) = uVar1;
  return tr_61;
}


// PM_TraceModel  @ 00083614
longdouble PM_TraceModel(undefined4 param_1,float *param_2,float *param_3,int param_4)

{
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = *(undefined4 *)(pmove + 0xbc);
  *(undefined4 *)(pmove + 0xbc) = 2;
  local_8 = PM_HullForBsp(param_1,&local_30);
  *(undefined4 *)(pmove + 0xbc) = local_c;
  local_18 = *param_2 - local_30;
  local_14 = param_2[1] - local_2c;
  local_10 = param_2[2] - local_28;
  local_24 = *param_3 - local_30;
  local_20 = param_3[1] - local_2c;
  local_1c = param_3[2] - local_28;
  SV_RecursiveHullCheck
            (local_8,*(undefined4 *)(local_8 + 8),0,0x3f800000,&local_18,&local_24,param_4);
  *(undefined4 *)(param_4 + 0x30) = 0;
  return (longdouble)*(float *)(param_4 + 0x10);
}


// PM_TruePointContents  @ 00083d3c
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


// PM_WaterEntity  @ 00083c94
undefined4 PM_WaterEntity(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  (*(code *)g_engdstAddrs._232_4_)(&param_1);
  local_10 = 0xffffffff;
  local_8 = *(int *)(pmove + 0x280) + 0xd0;
  local_c = *(undefined4 *)(*(int *)(pmove + 0x280) + 0xd8);
  iVar1 = PM_HullPointContents(local_8,local_c,param_1);
  if (iVar1 < -2) {
    local_10 = 0;
  }
  if (iVar1 != -2) {
    PM_LinkContents(param_1,&local_10);
  }
  return local_10;
}


