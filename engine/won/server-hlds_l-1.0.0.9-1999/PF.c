// PF_BuildSoundMsg_I  @ 0806f5c0
void PF_BuildSoundMsg_I(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                       undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  PF_MessageBegin_I(param_8,param_9,param_10,param_11);
  SV_BuildSoundMsg(param_1,param_2,param_3,(int)ROUND(param_4),param_5,param_6,param_7,param_10,
                   gMsgBuffer);
  PF_MessageEnd_I();
  return;
}


// PF_CreateFakeClient_I  @ 0806e750
int PF_CreateFakeClient_I(char *param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  int *piVar3;
  int local_c;
  
  local_c = 0;
  if (0 < svs) {
    do {
      unaff_ESI = (int *)(DAT_0816dd10 + local_c * 0x52b8);
      if (((*unaff_ESI == 0) && (unaff_ESI[1] == 0)) && (unaff_ESI[2] == 0)) break;
      local_c = local_c + 1;
    } while (local_c < svs);
  }
  if (local_c == svs) {
    iVar1 = 0;
  }
  else {
    iVar1 = EDICT_NUM(local_c + 1);
    piVar3 = unaff_ESI;
    for (iVar2 = 0x14ae; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    unaff_ESI[0x1447] = (int)(unaff_ESI + 0x142e);
    unaff_ESI[0x1446] = (int)(unaff_ESI + 0x142e);
    unaff_ESI[0x142d] = (int)(unaff_ESI + 0x1414);
    unaff_ESI[0x142c] = (int)(unaff_ESI + 0x1414);
    strncpy((char *)((int)unaff_ESI + 0x5005),param_1,0x20);
    *unaff_ESI = 1;
    unaff_ESI[1] = 1;
    unaff_ESI[2] = 1;
    unaff_ESI[3] = 0;
    unaff_ESI[0x13c2] = iVar1;
    unaff_ESI[0xfb0] = 1;
    unaff_ESI[0x13c4] = g_userid;
    g_userid = g_userid + 1;
    *(int *)(iVar1 + 0x28c) = (int)unaff_ESI - (pr_strings + -0x5005);
    *(int *)(iVar1 + 0x2c4) = iVar1;
    *(undefined4 *)(iVar1 + 0x260) = 0x2008;
    piVar3 = unaff_ESI + 0x13c6;
    Info_SetValueForKey(piVar3,"name",param_1,0xc4);
    Info_SetValueForKey(piVar3,"model","gordon",0xc4);
    Info_SetValueForKey(piVar3,"topcolor",&DAT_080a33f8,0xc4);
    Info_SetValueForKey(piVar3,"bottomcolor",&DAT_080a33f8,0xc4);
    unaff_ESI[0x13f7] = 1;
    SV_ExtractFromUserinfo(unaff_ESI);
  }
  return iVar1;
}


// PF_DecalIndex  @ 0806e020
int PF_DecalIndex(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < sv_decalnamecount) {
    do {
      iVar1 = strcasecmp((char *)((int)&sv_decalnames + iVar2 * 0x11),param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < sv_decalnamecount);
  }
  return -1;
}


// PF_FadeVolume  @ 0806f440
void PF_FadeVolume(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                  undefined1 param_5)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (svs < iVar1)) {
    Con_Printf("tried to PF_FadeVolume a non-client\n");
  }
  else {
    iVar1 = DAT_0816dd10 + -0x5240 + iVar1 * 0x52b8;
    MSG_WriteChar(iVar1,0x33);
    MSG_WriteByte(iVar1,param_2);
    MSG_WriteByte(iVar1,param_4);
    MSG_WriteByte(iVar1,param_3);
    MSG_WriteByte(iVar1,param_5);
  }
  return;
}


// PF_GetInfoKeyBuffer_I  @ 0806dcf0
undefined1 * PF_GetInfoKeyBuffer_I(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_1 == 0) {
    puVar1 = localinfo;
  }
  else {
    iVar2 = NUM_FOR_EDICT(param_1);
    if (iVar2 == 0) {
      puVar1 = (undefined1 *)Info_Serverinfo();
    }
    else if (iVar2 < 0x21) {
      puVar1 = (undefined1 *)(DAT_0816dd10 + -0x3a0 + iVar2 * 0x52b8);
    }
    else {
      puVar1 = &DAT_080a3354;
    }
  }
  return puVar1;
}


// PF_GetPlayerUserId  @ 0806f560
undefined4 PF_GetPlayerUserId(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((sv != 0) && (param_1 != 0)) && (iVar2 = 0, iVar1 = DAT_0816dd10, 0 < svs)) {
    do {
      if (*(int *)(iVar1 + 0x4f08) == param_1) {
        return *(undefined4 *)(iVar1 + 0x4f10);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x52b8;
    } while (iVar2 < svs);
  }
  return 0xffffffff;
}


// PF_InfoKeyValue_I  @ 0806dd70
void PF_InfoKeyValue_I(undefined4 param_1,undefined4 param_2)

{
  Info_ValueForKey(param_1,param_2);
  return;
}


// PF_IsDedicatedServer  @ 0806f630
undefined4 PF_IsDedicatedServer(void)

{
  return isDedicated;
}


// PF_IsMapValid_I  @ 0806dc70
uint PF_IsMapValid_I(undefined4 param_1)

{
  uint uVar1;
  char local_108 [260];
  
  sprintf(local_108,"maps/%.32s.bsp",param_1);
  uVar1 = COM_FileSize(local_108);
  return ~uVar1 >> 0x1f;
}


// PF_MessageBegin_I  @ 0806ea50
void PF_MessageBegin_I(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  if (param_1 == 1) {
    if (param_4 == 0) {
      Sys_Error("MSG_ONE with no target entity\n");
    }
  }
  else if (param_4 != 0) {
    Sys_Error("Invalid message;  cannot use broadcast message with a target entity");
  }
  if (gMsgStarted != 0) {
    Sys_Error("new message started when msg \'%d\' has not been sent yet",gMsgType);
  }
  gMsgStarted = 1;
  gMsgType = param_2;
  gMsgEntity = param_4;
  gMsgDest = param_1;
  if (param_1 - 4U < 2) {
    if (param_3 != (undefined4 *)0x0) {
      gMsgOrigin._0_4_ = *param_3;
      gMsgOrigin._4_4_ = param_3[1];
      gMsgOrigin._8_4_ = param_3[2];
    }
    IsSinglePlayerGame();
  }
  gMsgBuffer._16_4_ = 0;
  gMsgBuffer._4_4_ = 0;
  gMsgBuffer._0_4_ = 0;
  return;
}


// PF_MessageEnd_I  @ 0806eb20
void PF_MessageEnd_I(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  
  bVar1 = false;
  if (gMsgStarted == 0) {
    Sys_Error("MESSAGE_END called with no active message\n");
  }
  gMsgStarted = 0;
  if ((gMsgEntity != 0) && ((*(byte *)(gMsgEntity + 0x261) & 0x20) != 0)) {
    gMsgStarted = 0;
    return;
  }
  if (0x35 < gMsgType) {
    piVar4 = sv_gpUserMsgs;
    if (sv_gpUserMsgs == (int *)0x0) {
LAB_0806eb89:
      Con_DPrintf("Illegal User Msg %d\n",gMsgType);
      return;
    }
    do {
      if (*piVar4 == gMsgType) break;
      piVar4 = (int *)piVar4[5];
    } while (piVar4 != (int *)0x0);
    if (piVar4 == (int *)0x0) goto LAB_0806eb89;
    if (piVar4[1] == -1) {
      bVar1 = true;
    }
    else if (piVar4[1] != gMsgBuffer._16_4_) {
      Sys_Error("User Msg \'%s\': %d bytes written, expected %d\n",piVar4 + 2,gMsgBuffer._16_4_,
                piVar4[1]);
      return;
    }
  }
  iVar2 = WriteDest_Parm(gMsgDest);
  if ((gMsgDest == 0) && (*(int *)(iVar2 + 0xc) < gMsgBuffer._16_4_ + *(int *)(iVar2 + 0x10))) {
    return;
  }
  if (*(int *)(iVar2 + 8) == 0) {
    Con_DPrintf("Message sent to uninitialized buffer\n");
    return;
  }
  uVar3 = WriteDest_Parm(gMsgDest,gMsgType);
  MSG_WriteByte(uVar3);
  if (bVar1) {
    uVar3 = WriteDest_Parm(gMsgDest,gMsgBuffer._16_4_);
    MSG_WriteByte(uVar3);
  }
  uVar3 = WriteDest_Parm(gMsgDest,gMsgBuffer._16_4_,gMsgBuffer._8_4_);
  MSG_WriteBuf(uVar3);
  if (gMsgDest == 5) {
    uVar3 = 0;
  }
  else {
    if (gMsgDest < 6) {
      if (gMsgDest != 4) {
        return;
      }
      uVar3 = 0;
      uVar5 = 1;
      goto LAB_0806ecd4;
    }
    if ((gMsgDest != 6) && (gMsgDest != 7)) {
      return;
    }
    uVar3 = 1;
  }
  uVar5 = 2;
LAB_0806ecd4:
  SV_Multicast(gMsgOrigin,uVar5,uVar3);
  return;
}


// PF_NumberOfEntities_I  @ 0806dcb0
int PF_NumberOfEntities_I(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (0 < DAT_08140434) {
    do {
      if (*(int *)(DAT_0814043c + iVar2 * 0x2c8) == 0) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_08140434);
  }
  return iVar1;
}


// PF_Remove_I  @ 0806d610
void PF_Remove_I(undefined4 param_1)

{
  ED_Free(param_1);
  return;
}


// PF_RunPlayerMove_I  @ 0806e8f0
void PF_RunPlayerMove_I(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined2 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 uVar1;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  undefined2 local_a;
  undefined1 local_8;
  
  uVar1 = sv_player;
  sv_player = param_1;
  local_24 = *param_2;
  local_20 = param_2[1];
  local_1c = param_2[2];
  local_18 = param_3;
  local_14 = param_4;
  local_10 = param_5;
  local_a = param_6;
  local_8 = param_7;
  local_c = 0;
  local_28[0] = param_8;
  *(undefined4 *)(param_1 + 0x150) = local_24;
  *(undefined4 *)(param_1 + 0x154) = local_20;
  *(undefined4 *)(param_1 + 0x158) = local_1c;
  SV_PreRunCmd();
  SV_RunCmd(local_28);
  sv_player = uVar1;
  return;
}


// PF_SetClientKeyValue_I  @ 0806ddf0
void PF_SetClientKeyValue_I(int param_1,undefined1 *param_2,undefined4 param_3,char *param_4)

{
  undefined1 *puVar1;
  char *__s1;
  int iVar2;
  char *__s2;
  
  if (param_2 != localinfo) {
    puVar1 = (undefined1 *)Info_Serverinfo();
    if (((param_2 != puVar1) && (0 < param_1)) && (param_1 <= svs)) {
      __s2 = param_4;
      __s1 = (char *)Info_ValueForKey(param_2,param_3);
      iVar2 = strcmp(__s1,__s2);
      if (iVar2 != 0) {
        Info_SetValueForKey(param_2,param_3,param_4,0xc4);
        iVar2 = DAT_0816dd10 + -0x52b8 + param_1 * 0x52b8;
        *(undefined4 *)(iVar2 + 0x4fdc) = 1;
        *(undefined4 *)(iVar2 + 0x4fe0) = 0;
      }
    }
  }
  return;
}


// PF_SetClientMaxspeed  @ 0806f4d0
void PF_SetClientMaxspeed(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (svs < iVar1)) {
    Con_Printf("tried to PF_SetClientMaxspeed a non-client\n");
  }
  else {
    *(undefined4 *)(DAT_0816dd10 + -0x1384 + iVar1 * 0x52b8) = param_2;
    MSG_WriteChar(&DAT_081413f8,0x34);
    MSG_WriteByte(&DAT_081413f8,(char)iVar1 + -1);
    MSG_WriteFloat(&DAT_081413f8,param_2);
  }
  return;
}


// PF_SetKeyValue_I  @ 0806dd90
void PF_SetKeyValue_I(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == localinfo) {
    uVar2 = 0x8000;
  }
  else {
    puVar1 = (undefined1 *)Info_Serverinfo();
    if (param_1 != puVar1) {
      Sys_Error("Can\'t set client keys with SetKeyValue");
      return;
    }
    uVar2 = 0x200;
  }
  Info_SetValueForKey(param_1,param_2,param_3,uVar2);
  return;
}


// PF_Spawn_I  @ 0806d580
void PF_Spawn_I(void)

{
  ED_Alloc();
  return;
}


// PF_StaticDecal  @ 0806f040
void PF_StaticDecal(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  MSG_WriteByte(&DAT_08143774,0x17);
  MSG_WriteByte(&DAT_08143774,0xd);
  MSG_WriteCoord(&DAT_08143774,*param_1);
  MSG_WriteCoord(&DAT_08143774,param_1[1]);
  MSG_WriteCoord(&DAT_08143774,param_1[2]);
  MSG_WriteShort(&DAT_08143774,param_2);
  MSG_WriteShort(&DAT_08143774,param_3);
  if (param_3 != 0) {
    MSG_WriteShort(&DAT_08143774,param_4);
  }
  SV_FlushSignon();
  return;
}


// PF_Time  @ 0806bcf0
longdouble PF_Time(void)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)Sys_FloatTime();
  return (longdouble)(float)lVar1;
}


// PF_TraceToss_DLL  @ 0806cc60
void PF_TraceToss_DLL(undefined4 param_1,int param_2,int *param_3)

{
  if (param_2 == 0) {
    param_2 = DAT_0814043c;
  }
  PF_TraceToss_Shared(param_1,param_2);
  *param_3 = (int)ROUND((float)gGlobalVariables._76_4_);
  param_3[1] = (int)ROUND((float)gGlobalVariables._80_4_);
  param_3[2] = (int)ROUND((float)gGlobalVariables._120_4_);
  param_3[3] = (int)ROUND((float)gGlobalVariables._124_4_);
  param_3[4] = gGlobalVariables._84_4_;
  param_3[8] = gGlobalVariables._112_4_;
  param_3[0xc] = gGlobalVariables._116_4_;
  param_3[5] = gGlobalVariables._88_4_;
  param_3[6] = gGlobalVariables._92_4_;
  param_3[7] = gGlobalVariables._96_4_;
  param_3[9] = gGlobalVariables._100_4_;
  param_3[10] = gGlobalVariables._104_4_;
  param_3[0xb] = gGlobalVariables._108_4_;
  param_3[0xd] = gGlobalVariables._128_4_;
  return;
}


// PF_TraceToss_Shared  @ 0806cb60
void PF_TraceToss_Shared(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_3c [56];
  
  SV_Trace_Toss(local_3c,param_1,param_2);
  SV_SetGlobalTrace(local_3c);
  return;
}


// PF_WaterMove  @ 0807c680
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PF_WaterMove(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  longdouble lVar6;
  char *pcVar7;
  
  if (*(int *)(param_1 + 0x1c4) == 8) goto LAB_0807c884;
  if (*(float *)(param_1 + 0x21c) < 0.0) {
    return;
  }
  if (*(int *)(param_1 + 0x22c) == 0) {
    fVar1 = 3.0;
  }
  else {
    fVar1 = 1.0;
  }
  uVar2 = *(uint *)(param_1 + 0x260);
  iVar5 = *(int *)(param_1 + 0x27c);
  iVar3 = *(int *)(param_1 + 0x280);
  if ((uVar2 & 0x20040) == 0) {
    if ((((uVar2 & 2) != 0) && ((float)iVar5 < fVar1)) ||
       (fVar4 = (float)iVar5,
       (byte)((fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) - 1) < 0x40)) {
      fVar1 = *(float *)(param_1 + 0x2b8);
      fVar4 = (float)_DAT_0811d24c;
      if ((byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) == 1) {
        fVar1 = *(float *)(param_1 + 700);
        fVar4 = (float)_DAT_0811d24c;
        if ((byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) == 1) {
          fVar1 = *(float *)(param_1 + 0x29c) + 2.0;
          *(float *)(param_1 + 0x29c) = fVar1;
          if ((byte)(15.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 15.0) << 0xe) >> 8)) == 1) {
            *(undefined4 *)(param_1 + 0x29c) = 0x41200000;
          }
          *(float *)(param_1 + 700) = (float)_DAT_0811d24c + 1.0;
        }
      }
    }
    else {
      *(float *)(param_1 + 0x2b8) = (float)((longdouble)12.0 + (longdouble)_DAT_0811d24c);
      *(undefined4 *)(param_1 + 0x29c) = 0x40000000;
    }
  }
  if (iVar5 != 0) {
    if (iVar3 == -5) {
      if ((uVar2 & 0x80040) == 0) {
        fVar1 = *(float *)(param_1 + 0x2a0);
        fVar4 = (float)_DAT_0811d24c;
        if ((byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) == 1) {
          fVar1 = *(float *)(param_1 + 0x2c0);
          fVar4 = (float)_DAT_0811d24c;
          if ((byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) == 1) {
            lVar6 = (longdouble)0.2;
          }
          else {
LAB_0807c939:
            lVar6 = (longdouble)1;
          }
          *(float *)(param_1 + 0x2a0) = (float)(lVar6 + (longdouble)_DAT_0811d24c);
        }
      }
    }
    else if ((iVar3 == -4) && ((uVar2 & 0x40040) == 0)) {
      fVar1 = *(float *)(param_1 + 0x2a0);
      fVar4 = (float)_DAT_0811d24c;
      if ((byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) == 1) {
        fVar1 = *(float *)(param_1 + 0x2c0);
        fVar4 = (float)_DAT_0811d24c;
        if ((byte)(fVar1 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) == 1) goto LAB_0807c939;
      }
    }
    if ((uVar2 & 0x10) != 0) goto LAB_0807ca22;
    if (iVar3 == -3) {
      iVar5 = RandomLong(0,3);
      if (iVar5 == 1) {
        pcVar7 = "player/pl_wade2.wav";
      }
      else if (iVar5 < 2) {
        if (iVar5 != 0) goto LAB_0807ca0e;
        pcVar7 = "player/pl_wade1.wav";
      }
      else if (iVar5 == 2) {
        pcVar7 = "player/pl_wade3.wav";
      }
      else {
        if (iVar5 != 3) goto LAB_0807ca0e;
        pcVar7 = "player/pl_wade4.wav";
      }
      SV_StartSound(param_1,4,pcVar7,0xff,0x3f4ccccd,0,100);
    }
LAB_0807ca0e:
    *(uint *)(param_1 + 0x260) = uVar2 | 0x10;
    *(undefined4 *)(param_1 + 0x2a0) = 0;
LAB_0807ca22:
    if ((uVar2 & 0x800) != 0) {
      return;
    }
    iVar5 = param_1 + 0xfc;
    VectorMA(iVar5,(float)*(int *)(param_1 + 0x27c) * -0.8 * (float)host_frametime,iVar5,iVar5);
    return;
  }
  if ((uVar2 & 0x10) == 0) goto LAB_0807c884;
  iVar5 = RandomLong(0,3);
  if (iVar5 == 1) {
    pcVar7 = "player/pl_wade2.wav";
LAB_0807c873:
    SV_StartSound(param_1,4,pcVar7,0xff,0x3f4ccccd,0,100);
  }
  else {
    if (1 < iVar5) {
      if (iVar5 == 2) {
        pcVar7 = "player/pl_wade3.wav";
      }
      else {
        if (iVar5 != 3) goto LAB_0807c87b;
        pcVar7 = "player/pl_wade4.wav";
      }
      goto LAB_0807c873;
    }
    if (iVar5 == 0) {
      pcVar7 = "player/pl_wade1.wav";
      goto LAB_0807c873;
    }
  }
LAB_0807c87b:
  *(uint *)(param_1 + 0x260) = uVar2 & 0xffffffef;
LAB_0807c884:
  *(float *)(param_1 + 0x2b8) = (float)((longdouble)12.0 + (longdouble)_DAT_0811d24c);
  return;
}


// PF_WriteAngle_I  @ 0806edb0
void PF_WriteAngle_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteAngle_I called with no active message\n");
  }
  MSG_WriteAngle(gMsgBuffer,param_1);
  return;
}


// PF_WriteByte_I  @ 0806ecf0
void PF_WriteByte_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_BYTE called with no active message\n");
  }
  MSG_WriteByte(gMsgBuffer,param_1);
  return;
}


// PF_WriteChar_I  @ 0806ed20
void PF_WriteChar_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_CHAR called with no active message\n");
  }
  MSG_WriteChar(gMsgBuffer,param_1);
  return;
}


// PF_WriteCoord_I  @ 0806ede0
void PF_WriteCoord_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteCoord_I called with no active message\n");
  }
  MSG_WriteCoord(gMsgBuffer,param_1);
  return;
}


// PF_WriteEntity_I  @ 0806ee40
void PF_WriteEntity_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteEntity_I called with no active message\n");
  }
  MSG_WriteShort(gMsgBuffer,param_1);
  return;
}


// PF_WriteLong_I  @ 0806ed80
void PF_WriteLong_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteLong_I called with no active message\n");
  }
  MSG_WriteLong(gMsgBuffer,param_1);
  return;
}


// PF_WriteShort_I  @ 0806ed50
void PF_WriteShort_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_SHORT called with no active message\n");
  }
  MSG_WriteShort(gMsgBuffer,param_1);
  return;
}


// PF_WriteString_I  @ 0806ee10
void PF_WriteString_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteString_I called with no active message\n");
  }
  MSG_WriteString(gMsgBuffer,param_1);
  return;
}


// PF_aim_I  @ 0806e120
void PF_aim_I(int param_1,undefined4 param_2,float *param_3)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  undefined1 *puVar5;
  float **ppfVar6;
  int iVar7;
  float *pfStack_a4;
  float local_78;
  undefined1 local_6c [48];
  int local_3c;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [4];
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(param_1 + 0xe4);
  local_c = *(float *)(param_1 + 0xe8);
  local_8 = *(float *)(param_1 + 0xec) + *(float *)(param_1 + 0x238);
  local_28[3] = (float)gGlobalVariables._40_4_;
  local_18 = (float)gGlobalVariables._44_4_;
  local_14 = (float)gGlobalVariables._48_4_;
  pfStack_a4 = local_28;
  VectorMA(&local_10,0x45000000,local_28 + 3);
  SV_Move(local_6c,&local_10,vec3_origin,vec3_origin,local_28,0,param_1,0);
  ppfVar6 = &pfStack_a4;
  if (((local_3c == 0) ||
      ((byte)((byte)((ushort)((ushort)NAN(*(float *)(local_3c + 0x228)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(local_3c + 0x228) == 2.0) << 0xe) >> 8)) != 0x40))
     || ((0 < *(int *)(param_1 + 0x268) && (*(int *)(param_1 + 0x268) == *(int *)(local_3c + 0x268))
         ))) {
    local_34 = local_28[3];
    local_30 = local_18;
    local_2c = local_14;
    local_78 = (float)sv_aim._12_4_;
    if (1 < DAT_08140434) {
      iVar7 = 1;
      do {
        iVar1 = DAT_0814043c + iVar7 * 0x2c8;
        if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar1 + 0x228)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x228) == 2.0) << 0xe) >> 8)) ==
              0x40) && (iVar1 != param_1)) &&
           ((*(int *)(param_1 + 0x268) < 1 || (*(int *)(param_1 + 0x268) != *(int *)(iVar1 + 0x268))
            ))) {
          iVar4 = 0;
          do {
            iVar2 = iVar4 * 4;
            local_28[iVar4] =
                 *(float *)(iVar2 + 0x230 + param_1) * 0.0 +
                 (*(float *)(iVar2 + iVar1 + 0x198) + *(float *)(iVar2 + iVar1 + 0x1a4)) * 0.75 +
                 *(float *)(iVar2 + iVar1 + 0xe4);
            iVar4 = iVar4 + 1;
          } while (iVar4 < 3);
          local_28[3] = local_28[0] - local_10;
          local_18 = local_28[1] - local_c;
          local_14 = local_28[2] - local_8;
          *(float **)((int)ppfVar6 + -4) = local_28 + 3;
          *(undefined4 *)((int)ppfVar6 + -8) = 0x806e321;
          VectorNormalize();
          fVar3 = local_14 * (float)gGlobalVariables._48_4_ +
                  local_18 * (float)gGlobalVariables._44_4_ +
                  local_28[3] * (float)gGlobalVariables._40_4_;
          if ((byte)(fVar3 < local_78 |
                     (byte)((ushort)((ushort)(NAN(fVar3) || NAN(local_78)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar3 == local_78) << 0xe) >> 8)) != 1) {
            *(undefined4 *)((int)ppfVar6 + -4) = 0;
            *(int *)((int)ppfVar6 + -8) = param_1;
            *(undefined4 *)((int)ppfVar6 + -0xc) = 0;
            *(float **)((int)ppfVar6 + -0x10) = local_28;
            *(undefined1 **)((int)ppfVar6 + -0x14) = vec3_origin;
            *(undefined1 **)((int)ppfVar6 + -0x18) = vec3_origin;
            *(float **)((int)ppfVar6 + -0x1c) = &local_10;
            *(undefined1 **)((int)ppfVar6 + -0x20) = local_6c;
            *(undefined4 *)((int)ppfVar6 + -0x24) = 0x806e37c;
            SV_Move();
            puVar5 = (undefined1 *)((int)ppfVar6 + -4);
            ppfVar6 = (float **)((int)ppfVar6 + -4);
            if (local_3c == iVar1) {
              local_34 = local_28[3];
              local_30 = local_18;
              local_2c = local_14;
              ppfVar6 = (float **)puVar5;
              local_78 = fVar3;
            }
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_08140434);
    }
    *param_3 = local_34;
    param_3[1] = local_30;
    param_3[2] = local_2c;
  }
  else {
    *param_3 = (float)gGlobalVariables._40_4_;
    param_3[1] = (float)gGlobalVariables._44_4_;
    param_3[2] = (float)gGlobalVariables._48_4_;
  }
  return;
}


// PF_ambientsound_I  @ 0806c180
void PF_ambientsound_I(undefined4 param_1,int param_2,char *param_3,float param_4,float param_5,
                      uint param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined *puVar5;
  
  if (*param_3 == '!') {
    param_6 = param_6 | 0x10;
    iVar1 = __strtol_internal(param_3 + 1,0,10,0);
    if (0x5ff < iVar1) {
      Con_Printf("invalid sentence number: %s",param_3 + 1);
      return;
    }
LAB_0806c210:
    uVar2 = NUM_FOR_EDICT(param_1);
    puVar5 = &DAT_08140444;
    if ((param_6 & 0x100) != 0) {
      puVar5 = &DAT_08143774;
    }
    MSG_WriteByte(puVar5,0x1d);
    iVar4 = 0;
    do {
      MSG_WriteCoord(puVar5,*(undefined4 *)(param_2 + iVar4 * 4));
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    MSG_WriteShort(puVar5,iVar1);
    MSG_WriteByte(puVar5,(int)ROUND(param_4 * 255.0));
    MSG_WriteByte(puVar5,(int)ROUND(param_5 * 64.0));
    MSG_WriteShort(puVar5,uVar2);
    MSG_WriteByte(puVar5,param_7);
    MSG_WriteByte(puVar5,param_6 & 0xff);
  }
  else {
    iVar1 = 0;
    piVar3 = &DAT_0813eb30;
    if (DAT_0813eb30 != 0) {
      do {
        iVar4 = strcasecmp((char *)*piVar3,param_3);
        if (iVar4 == 0) break;
        piVar3 = piVar3 + 1;
        iVar1 = iVar1 + 1;
      } while (*piVar3 != 0);
      if (*piVar3 != 0) goto LAB_0806c210;
    }
    Con_Printf("no precache: %s\n",param_3);
  }
  return;
}


// PF_bprint  @ 0806bf30
void PF_bprint(undefined4 param_1)

{
  SV_BroadcastPrintf(&DAT_080a2e6c,param_1);
  return;
}


// PF_changelevel_I  @ 0806f110
void PF_changelevel_I(char *param_1,char *param_2)

{
  undefined4 uVar1;
  char **ppcVar2;
  char *pcStack_20;
  char *pcStack_1c;
  char *pcStack_18;
  
  if (DAT_08166d08 != last_spawncount_259) {
    last_spawncount_259 = DAT_08166d08;
    if (param_2 == (char *)0x0) {
      pcStack_18 = param_1;
      ppcVar2 = &pcStack_1c;
      pcStack_1c = "changelevel %s\n";
      pcStack_20 = (char *)0x806f13e;
      uVar1 = va();
    }
    else {
      if (((int)ROUND((float)gGlobalVariables._32_4_) & 0x30U) == 0) {
        pcStack_20 = "changelevel2 %s %s\n";
      }
      else {
        pcStack_20 = "changelevel %s %s\n";
      }
      pcStack_18 = param_2;
      pcStack_1c = param_1;
      ppcVar2 = &pcStack_20;
      uVar1 = va();
    }
    *(undefined4 *)((int)ppcVar2 + -4) = uVar1;
    *(undefined4 *)((int)ppcVar2 + -8) = 0x806f182;
    Cbuf_AddText();
  }
  return;
}


// PF_changepitch_I  @ 0806e4c0
void PF_changepitch_I(int param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar1 = (longdouble)anglemod(*(undefined4 *)(param_1 + 300));
  lVar2 = (longdouble)*(float *)(param_1 + 0x160);
  lVar3 = (longdouble)*(float *)(param_1 + 0x164);
  if ((byte)(lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) != 0x40) {
    lVar4 = lVar2 - lVar1;
    if (lVar2 <= lVar1) {
      if (lVar4 <= (longdouble)-180.0) {
        lVar4 = (longdouble)360.0 + lVar4;
      }
    }
    else {
      lVar2 = (longdouble)180.0;
      if ((byte)((lVar2 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
        lVar4 = lVar4 - (longdouble)360.0;
      }
    }
    lVar2 = (longdouble)0;
    if ((byte)(lVar2 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) == 1) {
      if (lVar3 < lVar4) {
        lVar4 = lVar3;
      }
    }
    else if (lVar4 < -lVar3) {
      lVar4 = -lVar3;
    }
    lVar1 = (longdouble)anglemod((float)(lVar1 + lVar4));
    *(float *)(param_1 + 300) = (float)lVar1;
  }
  return;
}


// PF_changeyaw_I  @ 0806e3d0
void PF_changeyaw_I(int param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar1 = (longdouble)anglemod(*(undefined4 *)(param_1 + 0x130));
  lVar2 = (longdouble)*(float *)(param_1 + 0x168);
  lVar3 = (longdouble)*(float *)(param_1 + 0x16c);
  if ((byte)(lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) != 0x40) {
    lVar4 = lVar2 - lVar1;
    if (lVar2 <= lVar1) {
      if (lVar4 <= (longdouble)-180.0) {
        lVar4 = (longdouble)360.0 + lVar4;
      }
    }
    else {
      lVar2 = (longdouble)180.0;
      if ((byte)((lVar2 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
        lVar4 = lVar4 - (longdouble)360.0;
      }
    }
    lVar2 = (longdouble)0;
    if ((byte)(lVar2 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) == 1) {
      if (lVar3 < lVar4) {
        lVar4 = lVar3;
      }
    }
    else if (lVar4 < -lVar3) {
      lVar4 = -lVar3;
    }
    lVar1 = (longdouble)anglemod((float)(lVar1 + lVar4));
    *(float *)(param_1 + 0x130) = (float)lVar1;
  }
  return;
}


// PF_checkbottom_I  @ 0806e100
void PF_checkbottom_I(undefined4 param_1)

{
  SV_CheckBottom(param_1);
  return;
}


// PF_checkclient_I  @ 0806cf30
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * PF_checkclient_I(int param_1)

{
  uint uVar1;
  int *piVar2;
  double dVar3;
  int iVar4;
  int *piVar5;
  float local_10;
  float local_c;
  float local_8;
  
  dVar3 = _DAT_0811d24c - _DAT_0811d258;
  if ((byte)((0.1 < dVar3 | (byte)((ushort)((ushort)NAN(dVar3) << 10) >> 8) |
             (byte)((ushort)((ushort)(dVar3 == 0.1) << 0xe) >> 8)) - 1) < 0x40) {
    DAT_0811d254 = PF_newcheckclient(DAT_0811d254);
    _DAT_0811d258 = _DAT_0811d24c;
  }
  piVar2 = DAT_0814043c + DAT_0811d254 * 0xb2;
  piVar5 = DAT_0814043c;
  if ((*piVar2 == 0) && (piVar2[0x36] != 0)) {
    local_10 = *(float *)(param_1 + 0xe4) + *(float *)(param_1 + 0x230);
    local_c = *(float *)(param_1 + 0xe8) + *(float *)(param_1 + 0x234);
    local_8 = *(float *)(param_1 + 0xec) + *(float *)(param_1 + 0x238);
    iVar4 = Mod_PointInLeaf(&local_10,DAT_0811d320);
    uVar1 = ((iVar4 - *(int *)(DAT_0811d320 + 0x8c)) * -0x55555555 >> 4) - 1;
    if (((int)uVar1 < 0) || (((byte)checkpvs[(int)uVar1 >> 3] >> (uVar1 & 7) & 1) == 0)) {
      c_notvis = c_notvis + 1;
      piVar5 = DAT_0814043c;
    }
    else {
      c_invis = c_invis + 1;
      piVar5 = piVar2;
    }
  }
  return piVar5;
}


// PF_crosshairangle_I  @ 0806e630
void PF_crosshairangle_I(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (svs < iVar1)) {
    Host_Error("PF_setview_I: not a client");
  }
  if ((byte)(180.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 180.0) << 0xe) >> 8)) == 1) {
    param_2 = param_2 - 360.0;
  }
  if (param_2 < -180.0) {
    param_2 = param_2 + 360.0;
  }
  if ((byte)(180.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_3 == 180.0) << 0xe) >> 8)) == 1) {
    param_3 = param_3 - 360.0;
  }
  if (param_3 < -180.0) {
    param_3 = param_3 + 360.0;
  }
  iVar1 = DAT_0816dd10 + iVar1 * 0x52b8 + -0x5240;
  MSG_WriteByte(iVar1,0x32);
  MSG_WriteChar(iVar1,(int)ROUND(param_2 * 5.0));
  MSG_WriteChar(iVar1,(int)ROUND(param_3 * 5.0));
  return;
}


// PF_droptofloor_I  @ 0806df40
undefined4 PF_droptofloor_I(int param_1)

{
  undefined4 uVar1;
  int local_48 [4];
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  local_10 = *(undefined4 *)(param_1 + 0xe4);
  local_c = *(undefined4 *)(param_1 + 0xe8);
  local_8 = *(float *)(param_1 + 0xec) - 256.0;
  SV_Move(local_48,param_1 + 0xe4,param_1 + 0x198,param_1 + 0x1a4,&local_10,0,param_1,
          (*(byte *)(param_1 + 0x262) & 0x80) != 0);
  if (local_48[0] == 0) {
    if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40) {
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0xe4) = local_34;
      *(undefined4 *)(param_1 + 0xe8) = local_30;
      *(undefined4 *)(param_1 + 0xec) = local_2c;
      SV_LinkEdict(param_1,0);
      *(byte *)(param_1 + 0x261) = *(byte *)(param_1 + 0x261) | 2;
      *(undefined4 *)(param_1 + 600) = local_18;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// PF_find_Shared  @ 0806d620
int * PF_find_Shared(int param_1,int param_2,char *param_3)

{
  int *piVar1;
  char *__s1;
  int iVar2;
  
  do {
    param_1 = param_1 + 1;
    if (DAT_08140434 <= param_1) {
      return DAT_0814043c;
    }
    piVar1 = DAT_0814043c + param_1 * 0xb2;
  } while ((((*piVar1 != 0) ||
            (__s1 = pr_strings + *(int *)((int)piVar1 + param_2 + 0xdc), __s1 == (char *)0x0)) ||
           (__s1 == pr_strings)) || (iVar2 = strcmp(__s1,param_3), iVar2 != 0));
  return piVar1;
}


// PF_lightstyle_I  @ 0806e080
void PF_lightstyle_I(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  (&DAT_08140334)[param_1] = param_2;
  if (DAT_08140440 == 2) {
    iVar3 = 0;
    piVar2 = DAT_0816dd10;
    if (0 < svs) {
      do {
        if ((*piVar2 != 0) || (piVar2[1] != 0)) {
          piVar1 = piVar2 + 0x1e;
          MSG_WriteChar(piVar1,0xc);
          MSG_WriteChar(piVar1,param_1);
          MSG_WriteString(piVar1,param_2);
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 0x14ae;
      } while (iVar3 < svs);
    }
  }
  return;
}


// PF_localcmd_I  @ 0806d3e0
void PF_localcmd_I(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ValidCmd(param_1);
  if (iVar1 == 0) {
    Con_Printf("Error, bad server command %s\n",param_1);
  }
  else {
    Cbuf_AddText(param_1);
  }
  return;
}


// PF_localexec_I  @ 0806d420
void PF_localexec_I(void)

{
  Cbuf_Execute();
  return;
}


// PF_makestatic_I  @ 0806ee70
void PF_makestatic_I(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  MSG_WriteByte(&DAT_08143774,0x14);
  uVar1 = SV_ModelIndex(*(int *)(param_1 + 0x174) + pr_strings);
  MSG_WriteShort(&DAT_08143774,uVar1);
  MSG_WriteByte(&DAT_08143774,*(undefined4 *)(param_1 + 0x1e4));
  MSG_WriteByte(&DAT_08143774,(int)ROUND(*(float *)(param_1 + 0x1ec)));
  MSG_WriteWord(&DAT_08143774,*(undefined4 *)(param_1 + 0x264));
  MSG_WriteByte(&DAT_08143774,*(undefined4 *)(param_1 + 0x1cc));
  iVar2 = 0;
  do {
    MSG_WriteCoord(&DAT_08143774,*(undefined4 *)(iVar2 * 4 + param_1 + 0xe4));
    MSG_WriteAngle(&DAT_08143774,*(undefined4 *)(iVar2 * 4 + 300 + param_1));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  MSG_WriteByte(&DAT_08143774,*(undefined4 *)(param_1 + 0x204));
  if (*(int *)(param_1 + 0x204) != 0) {
    MSG_WriteByte(&DAT_08143774,(int)ROUND(*(float *)(param_1 + 0x208)));
    MSG_WriteByte(&DAT_08143774,(int)ROUND(*(float *)(param_1 + 0x20c)));
    MSG_WriteByte(&DAT_08143774,(int)ROUND(*(float *)(param_1 + 0x210)));
    MSG_WriteByte(&DAT_08143774,(int)ROUND(*(float *)(param_1 + 0x214)));
    MSG_WriteByte(&DAT_08143774,*(undefined4 *)(param_1 + 0x218));
  }
  ED_Free(param_1);
  return;
}


// PF_makevectors_I  @ 0806bcd0
void PF_makevectors_I(undefined4 param_1)

{
  AngleVectors(param_1,0x811cda8,0x811cdc0,0x811cdb4);
  return;
}


// PF_modelindex  @ 0806bed0
void PF_modelindex(undefined4 param_1)

{
  SV_ModelIndex(param_1);
  return;
}


// PF_newcheckclient  @ 0806ce30
int PF_newcheckclient(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  void *__src;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (svs < param_1) {
    param_1 = svs;
  }
  iVar3 = param_1 + 1;
  if (param_1 == svs) {
    iVar3 = 1;
  }
  while( true ) {
    if (iVar3 == svs + 1) {
      iVar3 = 1;
    }
    piVar1 = (int *)(DAT_0814043c + iVar3 * 0x2c8);
    if ((iVar3 == param_1) || (((*piVar1 == 0 && (piVar1[0x36] != 0)) && (-1 < (char)piVar1[0x98])))
       ) break;
    iVar3 = iVar3 + 1;
  }
  local_10 = (float)piVar1[0x39] + (float)piVar1[0x8c];
  local_c = (float)piVar1[0x3a] + (float)piVar1[0x8d];
  local_8 = (float)piVar1[0x3b] + (float)piVar1[0x8e];
  uVar2 = Mod_PointInLeaf(&local_10,DAT_0811d320);
  __src = (void *)Mod_LeafPVS(uVar2,DAT_0811d320);
  memcpy(checkpvs,__src,*(int *)(DAT_0811d320 + 0x88) + 7 >> 3);
  return iVar3;
}


// PF_particle_I  @ 0806c120
void PF_particle_I(undefined4 param_1,undefined4 param_2,float param_3,float param_4)

{
  SV_StartParticle(param_1,param_2,(int)ROUND(param_3),(int)ROUND(param_4));
  return;
}


// PF_pointcontents_I  @ 0806e110
void PF_pointcontents_I(undefined4 param_1)

{
  SV_PointContents(param_1);
  return;
}


// PF_precache_generic_I  @ 0806dbb0
int PF_precache_generic_I(char *param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_08140440 != 1) {
    iVar2 = 0;
    do {
      if (((&DAT_0813fb34)[iVar2] != 0) &&
         (iVar1 = strcmp((char *)(&DAT_0813fb34)[iVar2],param_1), iVar1 == 0)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x200);
    Host_Error("PF_precache_generic_I: \'%s\' Precache can only be done in spawn functions",param_1)
    ;
  }
  PR_CheckEmptyString(param_1);
  iVar2 = 0;
  while( true ) {
    if ((&DAT_0813fb34)[iVar2] == 0) {
      (&DAT_0813fb34)[iVar2] = param_1;
      return iVar2;
    }
    iVar1 = Q_strcasecmp((&DAT_0813fb34)[iVar2],param_1);
    if (iVar1 == 0) break;
    iVar2 = iVar2 + 1;
    if (0x1ff < iVar2) {
      Host_Error("PF_precache_generic_I: \'%s\' overflow",param_1);
      return 0;
    }
  }
  return iVar2;
}


// PF_precache_model_I  @ 0806dae0
int PF_precache_model_I(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_08140440 != 1) {
    iVar3 = 0;
    do {
      if (((&DAT_0813db30)[iVar3] != 0) &&
         (iVar1 = strcasecmp((char *)(&DAT_0813db30)[iVar3],param_1), iVar1 == 0)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x200);
    Host_Error("PF_precache_model_I: \'%s\' Precache can only be done in spawn functions",param_1);
  }
  PR_CheckEmptyString(param_1);
  iVar3 = 0;
  while( true ) {
    if ((&DAT_0813db30)[iVar3] == 0) {
      (&DAT_0813db30)[iVar3] = param_1;
      uVar2 = Mod_ForName(param_1,1);
      (&DAT_0813e330)[iVar3] = uVar2;
      return iVar3;
    }
    iVar1 = strcasecmp((char *)(&DAT_0813db30)[iVar3],param_1);
    if (iVar1 == 0) break;
    iVar3 = iVar3 + 1;
    if (0x1ff < iVar3) {
      Host_Error("PF_precache_model_I: \'%s\' overflow",param_1);
      return 0;
    }
  }
  return iVar3;
}


// PF_precache_sound_I  @ 0806da00
int PF_precache_sound_I(char *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '!')) {
    if (DAT_08140440 != 1) {
      iVar2 = 0;
      do {
        if (((&DAT_0813eb30)[iVar2] != 0) &&
           (iVar1 = strcasecmp((char *)(&DAT_0813eb30)[iVar2],param_1), iVar1 == 0)) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x200);
      Host_Error("PF_precache_sound_I: \'%s\' Precache can only be done in spawn functions",param_1)
      ;
    }
    PR_CheckEmptyString(param_1);
    DAT_0813fb30 = 0;
    iVar2 = 0;
    do {
      if ((&DAT_0813eb30)[iVar2] == 0) {
        (&DAT_0813eb30)[iVar2] = param_1;
        return iVar2;
      }
      iVar1 = strcasecmp((char *)(&DAT_0813eb30)[iVar2],param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x200);
    pcVar3 = "PF_precache_sound_I: \'%s\' overflow";
  }
  else {
    pcVar3 = "PF_precache_sound_I: \'%s\' do not precache sentence names!";
  }
  Host_Error(pcVar3,param_1);
  return 0;
}


// PF_setmodel_I  @ 0806be30
void PF_setmodel_I(int param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  iVar3 = 0;
  piVar2 = &DAT_0813db30;
  if (DAT_0813db30 != 0) {
    iVar3 = 0;
    do {
      iVar1 = strcasecmp((char *)*piVar2,param_2);
      if (iVar1 == 0) break;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (*piVar2 != 0);
    if (*piVar2 != 0) goto LAB_0806be78;
  }
  Host_Error("no precache: %s\n",param_2);
LAB_0806be78:
  *(int *)(param_1 + 0x174) = (int)param_2 - pr_strings;
  *(int *)(param_1 + 0x170) = iVar3;
  iVar3 = (&DAT_0813e330)[iVar3];
  if (iVar3 == 0) {
    puVar5 = vec3_origin;
    puVar4 = vec3_origin;
  }
  else {
    puVar5 = (undefined1 *)(iVar3 + 0x60);
    puVar4 = (undefined1 *)(iVar3 + 0x54);
  }
  SetMinMaxSize(param_1,puVar4,puVar5,1);
  return;
}


// PF_setorigin_I  @ 0806bd10
void PF_setorigin_I(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0xe4) = *param_2;
  *(undefined4 *)(param_1 + 0xe8) = param_2[1];
  *(undefined4 *)(param_1 + 0xec) = param_2[2];
  SV_LinkEdict(param_1,0);
  return;
}


// PF_setsize_I  @ 0806be10
void PF_setsize_I(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  SetMinMaxSize(param_1,param_2,param_3,0);
  return;
}


// PF_setspawnparms_I  @ 0806f0e0
void PF_setspawnparms_I(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (svs < iVar1)) {
    Host_Error("Entity is not a client");
  }
  return;
}


// PF_setview_I  @ 0806e5b0
void PF_setview_I(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (svs < iVar1)) {
    Host_Error("PF_setview_I: not a client");
  }
  iVar1 = DAT_0816dd10 + -0x52b8 + iVar1 * 0x52b8;
  *(undefined4 *)(iVar1 + 0x4f0c) = param_2;
  iVar1 = iVar1 + 0x78;
  MSG_WriteByte(iVar1,5);
  uVar2 = NUM_FOR_EDICT(param_2);
  MSG_WriteShort(iVar1,uVar2);
  return;
}


// PF_sound_I  @ 0806c2e0
void PF_sound_I(undefined4 param_1,uint param_2,undefined4 param_3,float param_4,float param_5,
               undefined4 param_6,uint param_7)

{
  if ((param_4 < 0.0) ||
     ((byte)(255.0 < param_4 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_4 == 255.0) << 0xe) >> 8)) == 1)) {
    Sys_Error("SV_StartSound: volume = %i",(double)param_4);
  }
  if ((param_5 < 0.0) ||
     ((byte)(4.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 4.0) << 0xe) >> 8)) == 1)) {
    Sys_Error("SV_StartSound: attenuation = %f",(double)param_5);
  }
  if (7 < param_2) {
    Sys_Error("SV_StartSound: channel = %i",param_2);
  }
  if (0xff < param_7) {
    Sys_Error("SV_StartSound: pitch = %i",param_7);
  }
  SV_StartSound(param_1,param_2,param_3,(int)ROUND(param_4 * 255.0),param_5,param_6,param_7);
  return;
}


// PF_sprint  @ 0806bf50
void PF_sprint(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 1) || (svs < param_2)) {
    Con_Printf("tried to sprint to a non-client\n");
  }
  else {
    iVar1 = DAT_0816dd10 + -0x5240 + param_2 * 0x52b8;
    MSG_WriteChar(iVar1,8);
    MSG_WriteString(iVar1,param_1);
  }
  return;
}


// PF_stuffcmd_I  @ 0806d320
void PF_stuffcmd_I(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = NUM_FOR_EDICT(param_1);
  vsprintf(szOut_162,param_2,&stack0x0000000c);
  if ((iVar2 < 1) || (svs < iVar2)) {
    Con_Printf("\n!!!\n\nStuffCmd:  Some entity tried to stuff \'%s\' to console buffer of entity %i when maxclients was set to %i, ignoring\n\n"
               ,szOut_162,iVar2,svs);
  }
  else {
    iVar3 = ValidCmd(szOut_162);
    uVar1 = host_client;
    if (iVar3 == 0) {
      Con_Printf("Tried to stuff bad command %s\n",szOut_162);
    }
    else {
      host_client = DAT_0816dd10 + -0x52b8 + iVar2 * 0x52b8;
      Host_ClientCommands(&DAT_080a2e6c,szOut_162);
      host_client = uVar1;
    }
  }
  return;
}


// PF_traceline_DLL  @ 0806c420
void PF_traceline_DLL(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     int *param_5)

{
  if (param_4 == 0) {
    param_4 = DAT_0814043c;
  }
  PF_traceline_Shared(param_1,param_2,param_3,param_4);
  *param_5 = (int)ROUND((float)gGlobalVariables._76_4_);
  param_5[1] = (int)ROUND((float)gGlobalVariables._80_4_);
  param_5[2] = (int)ROUND((float)gGlobalVariables._120_4_);
  param_5[3] = (int)ROUND((float)gGlobalVariables._124_4_);
  param_5[4] = gGlobalVariables._84_4_;
  param_5[8] = gGlobalVariables._112_4_;
  param_5[0xc] = gGlobalVariables._116_4_;
  param_5[5] = gGlobalVariables._88_4_;
  param_5[6] = gGlobalVariables._92_4_;
  param_5[7] = gGlobalVariables._96_4_;
  param_5[9] = gGlobalVariables._100_4_;
  param_5[10] = gGlobalVariables._104_4_;
  param_5[0xb] = gGlobalVariables._108_4_;
  param_5[0xd] = gGlobalVariables._128_4_;
  return;
}


// PF_traceline_Shared  @ 0806c3d0
void PF_traceline_Shared(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  undefined1 local_3c [56];
  
  SV_Move(local_3c,param_1,vec3_origin,vec3_origin,param_2,param_3,param_4,0);
  gGlobalVariables._132_4_ = 0;
  SV_SetGlobalTrace(local_3c);
  return;
}


// PF_vectoangles_I  @ 0806c100
void PF_vectoangles_I(undefined4 param_1,undefined4 param_2)

{
  VectorAngles(param_1,param_2);
  return;
}


// PF_vectoyaw_I  @ 0806c090
longdouble PF_vectoyaw_I(float *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)0;
  if (((byte)((byte)((ushort)((ushort)(NAN(lVar2) || NAN((longdouble)param_1[1])) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar2 == (longdouble)param_1[1]) << 0xe) >> 8)) != 0x40) ||
     (lVar1 = (longdouble)*param_1,
     (byte)(lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
           (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) != 0x40)) {
    lVar2 = (longdouble)fpatan((longdouble)param_1[1],(longdouble)*param_1);
    lVar2 = (longdouble)(int)ROUND((lVar2 * (longdouble)180.0) / (longdouble)3.141592653589793);
    if (lVar2 < (longdouble)0) {
      lVar2 = (longdouble)360.0 + lVar2;
    }
  }
  return lVar2;
}


// PF_walkmove_I  @ 0806de90
undefined4 PF_walkmove_I(int param_1,float param_2,float param_3,int param_4)

{
  undefined4 uVar1;
  longdouble lVar2;
  longdouble lVar3;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  if ((*(uint *)(param_1 + 0x260) & 0x203) == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = (longdouble)((param_2 * 3.1415927 + param_2 * 3.1415927) / 360.0);
    lVar3 = (longdouble)fcos(lVar2);
    local_10 = (float)(lVar3 * (longdouble)param_3);
    lVar2 = (longdouble)fsin(lVar2);
    local_c = (float)(lVar2 * (longdouble)param_3);
    local_8 = 0;
    if (param_4 == 1) {
      uVar1 = SV_movetest(param_1,&local_10,1);
    }
    else {
      uVar1 = SV_movestep(param_1,&local_10,param_4 != 2);
    }
  }
  return uVar1;
}


