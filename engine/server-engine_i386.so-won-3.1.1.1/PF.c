// PF_BuildSoundMsg_I  @ 0008cfa8
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


// PF_CanSkipPlayer  @ 0008d2ec
bool PF_CanSkipPlayer(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to PF_CanSkipPlayer a non-client\n");
    bVar2 = false;
  }
  else {
    bVar2 = *(int *)(DAT_00524284 + iVar1 * 0x4eec + -0x114) != 0;
  }
  return bVar2;
}


// PF_CreateFakeClient_I  @ 0008b390
int PF_CreateFakeClient_I(undefined4 param_1)

{
  int iVar1;
  int local_10;
  int *local_8;
  
  local_10 = 0;
  while ((local_10 < DAT_00524288 &&
         (((local_8 = (int *)(DAT_00524284 + local_10 * 0x4eec), *local_8 != 0 || (local_8[1] != 0))
          || (local_8[3] != 0))))) {
    local_10 = local_10 + 1;
  }
  if (local_10 == DAT_00524288) {
    iVar1 = 0;
  }
  else {
    iVar1 = EDICT_NUM(local_10 + 1);
    if (local_8[0xd20] != 0) {
      SV_ClearFrames(local_8 + 0xd20);
    }
    Q_memset(local_8,0,0x4eec);
    local_8[0x1349] = (int)(local_8 + 0x1328);
    local_8[0x1348] = (int)(local_8 + 0x1328);
    local_8[0x1327] = (int)(local_8 + 0x1306);
    local_8[0x1326] = (int)(local_8 + 0x1306);
    Q_strncpy(local_8 + 0x12fb,param_1,0x20);
    *(undefined1 *)((int)local_8 + 0x4c0b) = 0;
    *local_8 = 1;
    local_8[1] = 1;
    local_8[2] = 1;
    local_8[3] = 1;
    local_8[4] = 0;
    local_8[0x12a1] = iVar1;
    local_8[0x90e] = 1;
    local_8[0x12a3] = g_userid;
    g_userid = g_userid + 1;
    *(int *)(iVar1 + 0x250) = (int)local_8 - (pr_strings + -0x4bec);
    *(int *)(iVar1 + 0x288) = iVar1;
    *(undefined4 *)(iVar1 + 0x224) = 0x2008;
    Info_SetValueForKey(local_8 + 0x12a9,"name",param_1,0x100);
    Info_SetValueForKey(local_8 + 0x12a9,"model","gordon",0x100);
    Info_SetValueForKey(local_8 + 0x12a9,"topcolor",&DAT_000e62a0,0x100);
    Info_SetValueForKey(local_8 + 0x12a9,"bottomcolor",&DAT_000e62a0,0x100);
    local_8[0x12e9] = 1;
    SV_ExtractFromUserinfo(local_8);
  }
  return iVar1;
}


// PF_CreateInstancedBaseline  @ 0008d3d0
int PF_CreateInstancedBaseline(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*DAT_003a78c0 < 0x3f) {
    DAT_003a78c0[*DAT_003a78c0 + 1] = param_1;
    piVar2 = DAT_003a78c0 + *DAT_003a78c0 * 0x55 + 0x41;
    for (iVar1 = 0x55; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *param_2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    }
    *DAT_003a78c0 = *DAT_003a78c0 + 1;
    iVar1 = *DAT_003a78c0;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// PF_Cvar_DirectSet  @ 0008d49c
void PF_Cvar_DirectSet(undefined4 param_1,undefined4 param_2)

{
  Cvar_DirectSet(param_1,param_2);
  return;
}


// PF_DecalIndex  @ 0008a888
int PF_DecalIndex(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (sv_decalnamecount <= local_8) {
      return -1;
    }
    iVar1 = Q_stricmp(sv_decalnames + local_8 * 0x11,param_1);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


// PF_FadeVolume  @ 0008ca60
void PF_FadeVolume(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                  undefined1 param_5)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to PF_FadeVolume a non-client\n");
  }
  else {
    iVar1 = DAT_00524284 + iVar1 * 0x4eec + -0x4eec;
    if (*(int *)(iVar1 + 0x2438) == 0) {
      MSG_WriteChar(iVar1 + 0x74,0x30);
      MSG_WriteByte(iVar1 + 0x74,param_2);
      MSG_WriteByte(iVar1 + 0x74,param_4);
      MSG_WriteByte(iVar1 + 0x74,param_3);
      MSG_WriteByte(iVar1 + 0x74,param_5);
    }
  }
  return;
}


// PF_ForceUnmodified  @ 0008d4cc
void PF_ForceUnmodified(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int local_8;
  
  if (param_4 == 0) {
    Host_Error("PF_ForceUnmodified: NULL pointer");
  }
  else {
    iVar1 = PR_IsEmptyString(param_4);
    if (iVar1 == 0) {
      if (DAT_003a78c4 != 1) {
        for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
          if ((*(int *)(&DAT_003965a4 + local_8 * 0x2c) != 0) &&
             (iVar1 = Q_stricmp(*(undefined4 *)(&DAT_003965a4 + local_8 * 0x2c),param_4), iVar1 == 0
             )) {
            return;
          }
        }
        Host_Error("ForceUnmodified: \'%s\' Precache can only be done in spawn functions",param_4);
      }
      for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
        if (*(int *)(&DAT_003965a4 + local_8 * 0x2c) == 0) {
          *(int *)(&DAT_003965a4 + local_8 * 0x2c) = param_4;
          *(undefined4 *)(&DAT_003965b4 + local_8 * 0x2c) = param_1;
          if (param_2 != (undefined4 *)0x0) {
            *(undefined4 *)(&DAT_003965b8 + local_8 * 0x2c) = *param_2;
            *(undefined4 *)(&DAT_003965bc + local_8 * 0x2c) = param_2[1];
            *(undefined4 *)(&DAT_003965c0 + local_8 * 0x2c) = param_2[2];
          }
          if (param_3 == (undefined4 *)0x0) {
            return;
          }
          *(undefined4 *)(&DAT_003965c4 + local_8 * 0x2c) = *param_3;
          *(undefined4 *)(&DAT_003965c8 + local_8 * 0x2c) = param_3[1];
          *(undefined4 *)(&DAT_003965cc + local_8 * 0x2c) = param_3[2];
          return;
        }
        iVar1 = Q_stricmp(*(undefined4 *)(&DAT_003965a4 + local_8 * 0x2c),param_4);
        if (iVar1 == 0) {
          return;
        }
      }
      Host_Error("ForceUnmodified: \'%s\' overflow",param_4);
    }
    else {
      Host_Error("PF_ForceUnmodified: Bad string \'%s\'",param_4);
    }
  }
  return;
}


// PF_GetCurrentPlayer  @ 0008d288
int PF_GetCurrentPlayer(void)

{
  int iVar1;
  
  iVar1 = (host_client - DAT_00524284) * 0x614fb973 >> 2;
  if ((iVar1 < 0) || (DAT_00524288 <= iVar1)) {
    iVar1 = -1;
  }
  return iVar1;
}


// PF_GetInfoKeyBuffer_I  @ 0008a3c4
undefined1 * PF_GetInfoKeyBuffer_I(int param_1)

{
  int iVar1;
  undefined *local_c;
  
  if (param_1 == 0) {
    local_c = localinfo;
  }
  else {
    iVar1 = NUM_FOR_EDICT(param_1);
    if (iVar1 == 0) {
      local_c = (undefined *)Info_Serverinfo();
    }
    else if (iVar1 < 0x21) {
      local_c = (undefined *)(DAT_00524284 + iVar1 * 0x4eec + -0x448);
    }
    else {
      local_c = &DAT_000e61ec;
    }
  }
  return local_c;
}


// PF_GetPhysicsInfoString  @ 0008d058
undefined * PF_GetPhysicsInfoString(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to PF_GetPhysicsInfoString a non-client\n");
    puVar2 = &DAT_000e61ec;
  }
  else {
    puVar2 = (undefined *)(DAT_00524284 + iVar1 * 0x4eec + -0x10c);
  }
  return puVar2;
}


// PF_GetPhysicsKeyValue  @ 0008d10c
undefined * PF_GetPhysicsKeyValue(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to PF_GetPhysicsKeyValue a non-client\n");
    puVar2 = &DAT_000e61ec;
  }
  else {
    puVar2 = (undefined *)Info_ValueForKey(DAT_00524284 + iVar1 * 0x4eec + -0x10c,param_2);
  }
  return puVar2;
}


// PF_GetPlayerAuthId  @ 0008cd80
undefined1 * PF_GetPlayerAuthId(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int local_c;
  int local_8;
  
  count_299 = (count_299 + 1) % 5;
  szAuthID_298[count_299 * 0x40] = 0;
  if (sv == 0) {
    puVar3 = szAuthID_298 + count_299 * 0x40;
  }
  else if (param_1 == 0) {
    puVar3 = szAuthID_298 + count_299 * 0x40;
  }
  else {
    local_8 = DAT_00524284;
    for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
      if (*(int *)(local_8 + 0x4a84) == param_1) {
        if (*(int *)(local_8 + 0x2438) == 0) {
          iVar1 = *(int *)(local_8 + 0x4a90);
          if (iVar1 == 0) {
            snprintf(szAuthID_298 + count_299 * 0x40,0x3f,"%u",*(undefined4 *)(local_8 + 0x4a94));
          }
          else if ((-1 < iVar1) && (iVar1 < 3)) {
            uVar2 = SV_GetClientIDString(local_8);
            snprintf(szAuthID_298 + count_299 * 0x40,0x3f,"%s",uVar2);
          }
        }
        else {
          snprintf(szAuthID_298 + count_299 * 0x40,0x3f,"%s",&DAT_000e68cc);
        }
      }
      local_8 = local_8 + 0x4eec;
    }
    szAuthID_298[count_299 * 0x40 + 0x3f] = 0;
    puVar3 = szAuthID_298 + count_299 * 0x40;
  }
  return puVar3;
}


// PF_GetPlayerStats  @ 0008d7dc
void PF_GetPlayerStats(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  *param_2 = 0;
  *param_3 = 0;
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to PF_GetPlayerStats a non-client\n");
  }
  else {
    iVar1 = DAT_00524284 + iVar1 * 0x4eec + -0x4eec;
    *param_2 = (int)ROUND(*(float *)(iVar1 + 0x248c) * 1000.0);
    *param_3 = (int)ROUND(*(float *)(iVar1 + 0x2490));
  }
  return;
}


// PF_GetPlayerUserId  @ 0008cc44
undefined4 PF_GetPlayerUserId(int param_1)

{
  int local_c;
  int local_8;
  
  if ((sv != 0) && (param_1 != 0)) {
    local_8 = DAT_00524284;
    for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
      if (*(int *)(local_8 + 0x4a84) == param_1) {
        return *(undefined4 *)(local_8 + 0x4a8c);
      }
      local_8 = local_8 + 0x4eec;
    }
  }
  return 0xffffffff;
}


// PF_GetPlayerWONId  @ 0008ccd8
undefined4 PF_GetPlayerWONId(int param_1)

{
  int local_c;
  int local_8;
  
  if ((sv != 0) && (param_1 != 0)) {
    local_8 = DAT_00524284;
    for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
      if ((*(int *)(local_8 + 0x4a84) == param_1) && (*(int *)(local_8 + 0x4a90) == 0)) {
        return *(undefined4 *)(local_8 + 0x4a94);
      }
      local_8 = local_8 + 0x4eec;
    }
  }
  return 0xffffffff;
}


// PF_InfoKeyValue_I  @ 0008a484
undefined4 PF_InfoKeyValue_I(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = Info_ValueForKey(param_1,param_2);
  return uVar1;
}


// PF_IsDedicatedServer  @ 0008d034
undefined4 PF_IsDedicatedServer(void)

{
  return isDedicated;
}


// PF_IsMapValid_I  @ 0008a2d8
uint PF_IsMapValid_I(undefined4 param_1)

{
  uint uVar1;
  char local_108 [260];
  
  snprintf(local_108,0x104,"maps/%.32s.bsp",param_1);
  uVar1 = COM_FileSize(local_108);
  return ~uVar1 >> 0x1f;
}


// PF_MessageBegin_I  @ 0008b964
void PF_MessageBegin_I(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  if (((param_1 == 1) || (param_1 == 8)) && (param_4 == 0)) {
    Sys_Error("MSG_ONE or MSG_ONE_UNRELIABLE with no target entity\n");
  }
  if (((param_1 != 8) && (param_1 != 1)) && (param_4 != 0)) {
    Sys_Error("Invalid message;  cannot use broadcast message with a target entity");
  }
  if (gMsgStarted != 0) {
    Sys_Error("New message started when msg \'%d\' has not been sent yet",gMsgType);
  }
  if (param_2 == 0) {
    Sys_Error("Tried to create a message with a bogus message type ( 0 )");
  }
  gMsgStarted = 1;
  gMsgType = param_2;
  gMsgEntity = param_4;
  gMsgDest = param_1;
  if ((param_1 == 4) || (param_1 == 5)) {
    if (param_3 != (undefined4 *)0x0) {
      gMsgOrigin = *param_3;
      DAT_0011c1c4 = param_3[1];
      DAT_0011c1c8 = param_3[2];
    }
    Host_IsSinglePlayerGame();
  }
  gMsgBuffer._16_4_ = 0;
  gMsgBuffer._4_2_ = 1;
  return;
}


// PF_MessageEnd_I  @ 0008ba98
void PF_MessageEnd_I(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *local_14;
  
  bVar1 = false;
  if (gMsgStarted == 0) {
    Sys_Error("MESSAGE_END called with no active message\n");
  }
  gMsgStarted = 0;
  if ((gMsgEntity == 0) || ((*(uint *)(gMsgEntity + 0x224) & 0x2000) == 0)) {
    if ((gMsgBuffer._4_2_ & 2) == 0) {
      if (0x37 < gMsgType) {
        for (local_14 = sv_gpUserMsgs; (local_14 != (int *)0x0 && (*local_14 != gMsgType));
            local_14 = (int *)local_14[6]) {
        }
        if (local_14 == (int *)0x0) {
          Con_DPrintf("PF_MessageEnd_I:  Unknown User Msg %d\n",gMsgType);
          return;
        }
        if (local_14[1] == -1) {
          bVar1 = true;
          if (0xc0 < (int)gMsgBuffer._16_4_) {
            Host_Error("PF_MessageEnd_I:  Refusing to send user message %s of %i bytes to client, user message size limit is %i bytes\n"
                       ,local_14 + 2,gMsgBuffer._16_4_,0xc0);
            return;
          }
        }
        else if (local_14[1] != gMsgBuffer._16_4_) {
          Sys_Error("User Msg \'%s\': %d bytes written, expected %d\n",local_14 + 2,
                    gMsgBuffer._16_4_,local_14[1]);
          return;
        }
      }
      iVar2 = WriteDest_Parm(gMsgDest);
      if (((gMsgDest != 0) || (gMsgBuffer._16_4_ + *(int *)(iVar2 + 0x10) <= *(int *)(iVar2 + 0xc)))
         && (*(int *)(iVar2 + 8) != 0)) {
        if ((0x37 < gMsgType) && ((gMsgDest == 1 || (gMsgDest == 8)))) {
          iVar3 = NUM_FOR_EDICT(gMsgEntity);
          if ((iVar3 < 1) || (DAT_00524288 < iVar3)) {
            Host_Error("WriteDest_Parm: not a client");
          }
          piVar4 = (int *)(DAT_00524284 + iVar3 * 0x4eec + -0x4eec);
          if (piVar4[5] == 0) {
            return;
          }
          if ((*piVar4 == 0) && (piVar4[1] == 0)) {
            return;
          }
          if (piVar4[0x90e] != 0) {
            return;
          }
        }
        MSG_WriteByte(iVar2,gMsgType);
        if (bVar1) {
          MSG_WriteByte(iVar2,gMsgBuffer._16_4_);
        }
        MSG_WriteBuf(iVar2,gMsgBuffer._16_4_,gMsgBuffer._8_4_);
        switch(gMsgDest) {
        case 4:
          SV_Multicast(gMsgEntity,&gMsgOrigin,2,0);
          break;
        case 5:
          SV_Multicast(gMsgEntity,&gMsgOrigin,4,0);
          break;
        case 6:
          SV_Multicast(gMsgEntity,&gMsgOrigin,4,1);
          break;
        case 7:
          SV_Multicast(gMsgEntity,&gMsgOrigin,4,1);
        }
      }
    }
    else {
      Sys_Error("MESSAGE_END called, but message buffer from .dll had overflowed\n");
    }
  }
  return;
}


// PF_NumberOfEntities_I  @ 0008a33c
int PF_NumberOfEntities_I(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < DAT_003a78b0; local_c = local_c + 1) {
    if (*(int *)(DAT_003a78b8 + local_c * 0x324) == 0) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


// PF_RemoveKey_I  @ 0008a538
void PF_RemoveKey_I(undefined4 param_1,undefined4 param_2)

{
  Info_RemoveKey(param_1,param_2);
  return;
}


// PF_Remove_I  @ 00088bf0
void PF_Remove_I(undefined4 param_1)

{
  ED_Free(param_1);
  return;
}


// PF_RunPlayerMove_I  @ 0008b634
void PF_RunPlayerMove_I(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4
                       ,undefined4 param_5,undefined2 param_6,undefined1 param_7,byte param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  byte local_8;
  undefined1 local_7;
  undefined2 local_6;
  
  uVar2 = sv_player;
  uVar1 = host_client;
  local_6 = param_6;
  local_7 = param_7;
  local_8 = param_8;
  iVar3 = NUM_FOR_EDICT(param_1);
  sv_player = param_1;
  host_client = DAT_00524284 + iVar3 * 0x4eec + -0x4eec;
  *(double *)(host_client + 0x24a4) = (DAT_0036bc6c + host_frametime) - (double)local_8 / 1000.0;
  Q_memset(&local_3c,0,0x34);
  local_38 = *param_2;
  local_34 = param_2[1];
  local_30 = param_2[2];
  local_2c = param_3;
  local_28 = param_4;
  local_24 = param_5;
  local_1e = local_6;
  local_1c = local_7;
  local_20 = 0;
  local_3c._2_1_ = local_8;
  pmove = g_svmove;
  SV_PreRunCmd();
  SV_RunCmd(&local_3c,0);
  puVar4 = &local_3c;
  puVar5 = (undefined4 *)(host_client + 0x2440);
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  sv_player = uVar2;
  host_client = uVar1;
  return;
}


// PF_SetClientKeyValue_I  @ 0008a568
void PF_SetClientKeyValue_I(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((((param_2 != localinfo) && (puVar1 = (undefined1 *)Info_Serverinfo(), param_2 != puVar1)) &&
      (0 < param_1)) && (param_1 <= DAT_00524288)) {
    uVar4 = param_4;
    uVar2 = Info_ValueForKey(param_2,param_3);
    iVar3 = Q_strcmp(uVar2,uVar4);
    if (iVar3 != 0) {
      Info_SetValueForKey(param_2,param_3,param_4,0x100);
      iVar3 = DAT_00524284 + param_1 * 0x4eec;
      *(undefined4 *)(iVar3 + -0x348) = 1;
      *(undefined4 *)(iVar3 + -0x344) = 0;
    }
  }
  return;
}


// PF_SetClientMaxspeed  @ 0008cb84
void PF_SetClientMaxspeed(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to PF_SetClientMaxspeed a non-client\n");
  }
  else if (*(int *)(DAT_00524284 + iVar1 * 0x4eec + -0x2ab4) == 0) {
    *(undefined4 *)(param_1 + 0x290) = param_2;
  }
  return;
}


// PF_SetGroupMask  @ 0008d3a0
void PF_SetGroupMask(undefined4 param_1,undefined4 param_2)

{
  g_groupmask = param_1;
  g_groupop = param_2;
  return;
}


// PF_SetKeyValue_I  @ 0008a4b8
void PF_SetKeyValue_I(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  
  if (param_1 == localinfo) {
    Info_SetValueForKey(localinfo,param_2,param_3,0x8000);
  }
  else {
    puVar1 = (undefined1 *)Info_Serverinfo();
    if (param_1 == puVar1) {
      Info_SetValueForKey(param_1,param_2,param_3,0x200);
    }
    else {
      Sys_Error("Can\'t set client keys with SetKeyValue");
    }
  }
  return;
}


// PF_SetPhysicsKeyValue  @ 0008d1d0
void PF_SetPhysicsKeyValue(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Con_Printf("tried to PF_SetPhysicsKeyValue a non-client\n");
  }
  else {
    Info_SetValueForKey(DAT_00524284 + iVar1 * 0x4eec + -0x10c,param_2,param_3,0x100);
  }
  return;
}


// PF_Spawn_I  @ 00088af8
undefined4 PF_Spawn_I(void)

{
  undefined4 uVar1;
  
  uVar1 = ED_Alloc();
  return uVar1;
}


// PF_StaticDecal  @ 0008c3e0
void PF_StaticDecal(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  MSG_WriteByte(&DAT_003aa058,0x17);
  MSG_WriteByte(&DAT_003aa058,0xd);
  MSG_WriteCoord(&DAT_003aa058,*param_1);
  MSG_WriteCoord(&DAT_003aa058,param_1[1]);
  MSG_WriteCoord(&DAT_003aa058,param_1[2]);
  MSG_WriteShort(&DAT_003aa058,param_2);
  MSG_WriteShort(&DAT_003aa058,param_3);
  if (param_3 != 0) {
    MSG_WriteShort(&DAT_003aa058,param_4);
  }
  return;
}


// PF_Time  @ 00086290
longdouble PF_Time(void)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)Sys_FloatTime();
  return (longdouble)(float)lVar1;
}


// PF_TraceToss_DLL  @ 00087c38
void PF_TraceToss_DLL(undefined4 param_1,int param_2,int *param_3)

{
  if (param_2 == 0) {
    param_2 = DAT_003a78b8;
  }
  PF_TraceToss_Shared(param_1,param_2);
  *param_3 = (int)ROUND(DAT_0036b26c);
  param_3[1] = (int)ROUND(DAT_0036b270);
  param_3[2] = (int)ROUND(DAT_0036b298);
  param_3[3] = (int)ROUND(DAT_0036b29c);
  param_3[4] = DAT_0036b274;
  param_3[8] = DAT_0036b290;
  param_3[0xc] = DAT_0036b294;
  param_3[5] = DAT_0036b278;
  param_3[6] = DAT_0036b27c;
  param_3[7] = DAT_0036b280;
  param_3[9] = DAT_0036b284;
  param_3[10] = DAT_0036b288;
  param_3[0xb] = DAT_0036b28c;
  param_3[0xd] = DAT_0036b2a0;
  return;
}


// PF_TraceToss_Shared  @ 00087ab4
void PF_TraceToss_Shared(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_3c [56];
  
  SV_Trace_Toss(local_3c,param_1,param_2,0x87ac0);
  SV_SetGlobalTrace(local_3c);
  return;
}


// PF_WaterMove  @ 000b4100
void PF_WaterMove(int param_1)

{
  float fVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  float local_14;
  
  if (*(int *)(param_1 + 0x188) == 8) {
    *(float *)(param_1 + 0x27c) = (float)(DAT_0036bc6c + 12.0);
  }
  else {
    fVar1 = *(float *)(param_1 + 0x1e0);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      if (*(int *)(param_1 + 0x1f0) == 0) {
        local_14 = 3.0;
      }
      else {
        local_14 = 1.0;
      }
      uVar3 = *(uint *)(param_1 + 0x224);
      iVar4 = *(int *)(param_1 + 0x240);
      iVar5 = *(int *)(param_1 + 0x244);
      if ((uVar3 & 0x20040) == 0) {
        if ((((uVar3 & 2) != 0) &&
            (fVar1 = (float)iVar4,
            (byte)(fVar1 < local_14 |
                   (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_14)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == local_14) << 0xe) >> 8)) == 1)) ||
           (local_14 <= (float)iVar4)) {
          dVar2 = (double)*(float *)(param_1 + 0x27c);
          if (((byte)(dVar2 < DAT_0036bc6c |
                      (byte)((ushort)((ushort)(NAN(dVar2) || NAN(DAT_0036bc6c)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(dVar2 == DAT_0036bc6c) << 0xe) >> 8)) == 1) &&
             (dVar2 = (double)*(float *)(param_1 + 0x280),
             (byte)(dVar2 < DAT_0036bc6c |
                    (byte)((ushort)((ushort)(NAN(dVar2) || NAN(DAT_0036bc6c)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(dVar2 == DAT_0036bc6c) << 0xe) >> 8)) == 1)) {
            *(float *)(param_1 + 0x260) = *(float *)(param_1 + 0x260) + 2.0;
            if (15.0 < *(float *)(param_1 + 0x260)) {
              *(undefined4 *)(param_1 + 0x260) = 0x41200000;
            }
            *(float *)(param_1 + 0x280) = (float)(DAT_0036bc6c + 1.0);
          }
        }
        else {
          *(float *)(param_1 + 0x27c) = (float)(DAT_0036bc6c + 12.0);
          *(undefined4 *)(param_1 + 0x260) = 0x40000000;
        }
      }
      if (iVar4 == 0) {
        if ((uVar3 & 0x10) != 0) {
          uVar6 = RandomLong(0,3);
          switch(uVar6) {
          case 0:
            SV_StartSound(0,param_1,4,"player/pl_wade1.wav",0xff,0x3f4ccccd,0,100);
            break;
          case 1:
            SV_StartSound(0,param_1,4,"player/pl_wade2.wav",0xff,0x3f4ccccd,0,100);
            break;
          case 2:
            SV_StartSound(0,param_1,4,"player/pl_wade3.wav",0xff,0x3f4ccccd,0,100);
            break;
          case 3:
            SV_StartSound(0,param_1,4,"player/pl_wade4.wav",0xff,0x3f4ccccd,0,100);
          }
          *(uint *)(param_1 + 0x224) = uVar3 & 0xffffffef;
        }
        *(float *)(param_1 + 0x27c) = (float)(DAT_0036bc6c + 12.0);
      }
      else {
        if (iVar5 == -5) {
          if (((uVar3 & 0x80040) == 0) &&
             (dVar2 = (double)*(float *)(param_1 + 0x264),
             (byte)(dVar2 < DAT_0036bc6c |
                    (byte)((ushort)((ushort)(NAN(dVar2) || NAN(DAT_0036bc6c)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(dVar2 == DAT_0036bc6c) << 0xe) >> 8)) == 1)) {
            dVar2 = (double)*(float *)(param_1 + 0x284);
            if ((byte)(dVar2 < DAT_0036bc6c |
                       (byte)((ushort)((ushort)(NAN(dVar2) || NAN(DAT_0036bc6c)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(dVar2 == DAT_0036bc6c) << 0xe) >> 8)) == 1) {
              *(float *)(param_1 + 0x264) = (float)(DAT_0036bc6c + 0.2);
            }
            else {
              *(float *)(param_1 + 0x264) = (float)(DAT_0036bc6c + 1.0);
            }
          }
        }
        else if (((iVar5 == -4) && ((uVar3 & 0x40040) == 0)) &&
                ((dVar2 = (double)*(float *)(param_1 + 0x264),
                 (byte)(dVar2 < DAT_0036bc6c |
                        (byte)((ushort)((ushort)(NAN(dVar2) || NAN(DAT_0036bc6c)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(dVar2 == DAT_0036bc6c) << 0xe) >> 8)) == 1 &&
                 (dVar2 = (double)*(float *)(param_1 + 0x284),
                 (byte)(dVar2 < DAT_0036bc6c |
                        (byte)((ushort)((ushort)(NAN(dVar2) || NAN(DAT_0036bc6c)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(dVar2 == DAT_0036bc6c) << 0xe) >> 8)) == 1)))) {
          *(float *)(param_1 + 0x264) = (float)(DAT_0036bc6c + 1.0);
        }
        if ((uVar3 & 0x10) == 0) {
          if (iVar5 == -3) {
            uVar6 = RandomLong(0,3);
            switch(uVar6) {
            case 0:
              SV_StartSound(0,param_1,4,"player/pl_wade1.wav",0xff,0x3f4ccccd,0,100);
              break;
            case 1:
              SV_StartSound(0,param_1,4,"player/pl_wade2.wav",0xff,0x3f4ccccd,0,100);
              break;
            case 2:
              SV_StartSound(0,param_1,4,"player/pl_wade3.wav",0xff,0x3f4ccccd,0,100);
              break;
            case 3:
              SV_StartSound(0,param_1,4,"player/pl_wade4.wav",0xff,0x3f4ccccd,0,100);
            }
          }
          *(uint *)(param_1 + 0x224) = uVar3 | 0x10;
          *(undefined4 *)(param_1 + 0x264) = 0;
        }
        if ((uVar3 & 0x800) == 0) {
          VectorMA(param_1 + 0xa0,(float)((double)*(int *)(param_1 + 0x240) * -0.8 * host_frametime)
                   ,param_1 + 0xa0,param_1 + 0xa0);
        }
      }
    }
  }
  return;
}


// PF_WriteAngle_I  @ 0008bf88
void PF_WriteAngle_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteAngle_I called with no active message\n");
  }
  MSG_WriteAngle(gMsgBuffer,param_1);
  return;
}


// PF_WriteByte_I  @ 0008be48
void PF_WriteByte_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_BYTE called with no active message\n");
  }
  MSG_WriteByte(gMsgBuffer,param_1);
  return;
}


// PF_WriteChar_I  @ 0008be98
void PF_WriteChar_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_CHAR called with no active message\n");
  }
  MSG_WriteChar(gMsgBuffer,param_1);
  return;
}


// PF_WriteCoord_I  @ 0008bfdc
void PF_WriteCoord_I(float param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteCoord_I called with no active message\n");
  }
  MSG_WriteShort(gMsgBuffer,(int)ROUND(param_1 * 8.0));
  return;
}


// PF_WriteEntity_I  @ 0008c0a0
void PF_WriteEntity_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteEntity_I called with no active message\n");
  }
  MSG_WriteShort(gMsgBuffer,param_1);
  return;
}


// PF_WriteLong_I  @ 0008bf38
void PF_WriteLong_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteLong_I called with no active message\n");
  }
  MSG_WriteLong(gMsgBuffer,param_1);
  return;
}


// PF_WriteShort_I  @ 0008bee8
void PF_WriteShort_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_SHORT called with no active message\n");
  }
  MSG_WriteShort(gMsgBuffer,param_1);
  return;
}


// PF_WriteString_I  @ 0008c050
void PF_WriteString_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteString_I called with no active message\n");
  }
  MSG_WriteString(gMsgBuffer,param_1);
  return;
}


// PF_aim_I  @ 0008aa3c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PF_aim_I(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  undefined1 *puVar2;
  float **ppfVar3;
  int aiStackY_e4 [2];
  float *pfStack_c0;
  float local_84;
  undefined1 local_7c [48];
  int local_4c;
  int local_44;
  int local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30 [4];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  
  if ((param_1 == 0) || ((*(uint *)(param_1 + 0x224) & 0x2000) != 0)) {
    *param_3 = _DAT_0036b248;
    param_3[1] = _DAT_0036b24c;
    param_3[2] = _DAT_0036b250;
  }
  else {
    local_18 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 500);
    local_14 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x1f8);
    local_10 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x1fc);
    local_30[3] = _DAT_0036b248;
    local_20 = _DAT_0036b24c;
    local_1c = _DAT_0036b250;
    pfStack_c0 = local_30;
    VectorMA(&local_18,0x45000000,local_30 + 3);
    pfStack_c0 = (float *)0x0;
    SV_Move(local_7c,&local_18,&vec3_origin,&vec3_origin,local_30,0,param_1);
    ppfVar3 = &pfStack_c0;
    if (((local_4c == 0) ||
        ((byte)((byte)((ushort)((ushort)NAN(*(float *)(local_4c + 0x1ec)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(local_4c + 0x1ec) == 2.0) << 0xe) >> 8)) != 0x40)
        ) || ((0 < *(int *)(param_1 + 0x22c) &&
              (*(int *)(param_1 + 0x22c) == *(int *)(local_4c + 0x22c))))) {
      local_3c = local_30[3];
      local_38 = local_20;
      local_34 = local_1c;
      local_84 = (float)sv_aim._12_4_;
      local_c = 0;
      for (local_40 = 1; local_40 < DAT_003a78b0; local_40 = local_40 + 1) {
        local_8 = DAT_003a78b8 + local_40 * 0x324;
        fVar1 = *(float *)(local_8 + 0x1ec);
        if (((((byte)(2.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) == 0x40) &&
             ((*(uint *)(local_8 + 0x224) & 0x2000) == 0)) && (local_8 != param_1)) &&
           ((*(int *)(param_1 + 0x22c) < 1 ||
            (*(int *)(param_1 + 0x22c) != *(int *)(local_8 + 0x22c))))) {
          for (local_44 = 0; local_44 < 3; local_44 = local_44 + 1) {
            local_30[local_44] =
                 *(float *)(local_44 * 4 + param_1 + 500) * 0.0 +
                 (*(float *)(local_44 * 4 + local_8 + 0x15c) +
                 *(float *)(local_44 * 4 + local_8 + 0x168)) * 0.75 +
                 *(float *)(local_44 * 4 + local_8 + 0x88);
          }
          local_30[3] = local_30[0] - local_18;
          local_20 = local_30[1] - local_14;
          local_1c = local_30[2] - local_10;
          *(float **)((int)ppfVar3 + -0x10) = local_30 + 3;
          *(undefined4 *)((int)ppfVar3 + -0x14) = 0x8add3;
          VectorNormalize();
          fVar1 = local_1c * _DAT_0036b250 + local_20 * _DAT_0036b24c + local_30[3] * _DAT_0036b248;
          if ((byte)(fVar1 < local_84 |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_84)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == local_84) << 0xe) >> 8)) != 1) {
            *(undefined4 *)((int)ppfVar3 + -4) = 0;
            *(int *)((int)ppfVar3 + -8) = param_1;
            *(undefined4 *)((int)ppfVar3 + -0xc) = 0;
            *(float **)((int)ppfVar3 + -0x10) = local_30;
            *(undefined4 **)((int)ppfVar3 + -0x14) = &vec3_origin;
            *(undefined4 **)((int)ppfVar3 + -0x18) = &vec3_origin;
            *(float **)((int)ppfVar3 + -0x1c) = &local_18;
            *(undefined1 **)((int)ppfVar3 + -0x20) = local_7c;
            *(undefined4 *)((int)ppfVar3 + -0x24) = 0x8ae43;
            SV_Move();
            puVar2 = (undefined1 *)((int)ppfVar3 + -4);
            ppfVar3 = (float **)((int)ppfVar3 + -4);
            if (local_4c == local_8) {
              local_c = local_8;
              local_3c = local_30[3];
              local_38 = local_20;
              local_34 = local_1c;
              ppfVar3 = (float **)puVar2;
              local_84 = fVar1;
            }
          }
        }
      }
      *param_3 = local_3c;
      param_3[1] = local_38;
      param_3[2] = local_34;
    }
    else {
      *param_3 = _DAT_0036b248;
      param_3[1] = _DAT_0036b24c;
      param_3[2] = _DAT_0036b250;
    }
  }
  return;
}


// PF_ambientsound_I  @ 00086c94
void PF_ambientsound_I(undefined4 param_1,int param_2,char *param_3,float param_4,float param_5,
                      uint param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined *local_18;
  int local_10;
  int local_c;
  int *local_8;
  
  if (*param_3 == '!') {
    param_6 = param_6 | 0x10;
    local_10 = Q_atoi(param_3 + 1);
    if (0x5ff < local_10) {
      Con_Printf(FUN_000e588c,param_3 + 1);
      return;
    }
  }
  else {
    local_10 = 0;
    local_8 = &DAT_0039dfa8;
    while ((*local_8 != 0 && (iVar1 = Q_stricmp(*local_8,param_3), iVar1 != 0))) {
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
    }
    if (*local_8 == 0) {
      Con_Printf("no precache: %s\n",param_3);
      return;
    }
  }
  uVar2 = NUM_FOR_EDICT(param_1);
  if ((param_6 & 0x100) == 0) {
    local_18 = &DAT_003a78c8;
  }
  else {
    local_18 = &DAT_003aa058;
  }
  MSG_WriteByte(local_18,0x1d);
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    MSG_WriteCoord(local_18,*(undefined4 *)(param_2 + local_c * 4));
  }
  MSG_WriteShort(local_18,local_10);
  MSG_WriteByte(local_18,(int)ROUND(param_4 * 255.0));
  MSG_WriteByte(local_18,(int)ROUND(param_5 * 64.0));
  MSG_WriteShort(local_18,uVar2);
  MSG_WriteByte(local_18,param_7);
  MSG_WriteByte(local_18,param_6 & 0xff);
  return;
}


// PF_bprint  @ 000868d0
void PF_bprint(undefined4 param_1)

{
  SV_BroadcastPrintf(&DAT_000e582c,param_1);
  return;
}


// PF_changelevel_I  @ 0008c590
void PF_changelevel_I(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (DAT_00524290 != last_spawncount_265) {
    last_spawncount_265 = DAT_00524290;
    SV_SkipUpdates();
    if (param_2 == 0) {
      uVar1 = va("changelevel %s\n",param_1);
      Cbuf_AddText(uVar1);
    }
    else {
      uVar1 = va("changelevel2 %s %s\n",param_1,param_2);
      Cbuf_AddText(uVar1);
    }
  }
  return;
}


// PF_changepitch_I  @ 0008afcc
void PF_changepitch_I(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  undefined4 local_10;
  
  lVar4 = (longdouble)anglemod(*(undefined4 *)(param_1 + 0xd0));
  fVar1 = (float)lVar4;
  fVar2 = *(float *)(param_1 + 0x124);
  fVar3 = *(float *)(param_1 + 0x128);
  if ((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    local_10 = fVar2 - fVar1;
    if (fVar2 <= fVar1) {
      if (local_10 <= -180.0) {
        local_10 = local_10 + 360.0;
      }
    }
    else if ((byte)((180.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_10 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      local_10 = local_10 - 360.0;
    }
    if ((byte)(0.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) == 1) {
      if (fVar3 < local_10) {
        local_10 = fVar3;
      }
    }
    else {
      fVar2 = -fVar3;
      if ((byte)(local_10 < fVar2 |
                 (byte)((ushort)((ushort)(NAN(local_10) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_10 == fVar2) << 0xe) >> 8)) == 1) {
        local_10 = -fVar3;
      }
    }
    lVar4 = (longdouble)anglemod(fVar1 + local_10);
    *(float *)(param_1 + 0xd0) = (float)lVar4;
  }
  return;
}


// PF_changeyaw_I  @ 0008aea0
void PF_changeyaw_I(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  undefined4 local_10;
  
  lVar4 = (longdouble)anglemod(*(undefined4 *)(param_1 + 0xd4));
  fVar1 = (float)lVar4;
  fVar2 = *(float *)(param_1 + 300);
  fVar3 = *(float *)(param_1 + 0x130);
  if ((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    local_10 = fVar2 - fVar1;
    if (fVar2 <= fVar1) {
      if (local_10 <= -180.0) {
        local_10 = local_10 + 360.0;
      }
    }
    else if ((byte)((180.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_10 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      local_10 = local_10 - 360.0;
    }
    if ((byte)(0.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) == 1) {
      if (fVar3 < local_10) {
        local_10 = fVar3;
      }
    }
    else {
      fVar2 = -fVar3;
      if ((byte)(local_10 < fVar2 |
                 (byte)((ushort)((ushort)(NAN(local_10) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_10 == fVar2) << 0xe) >> 8)) == 1) {
        local_10 = -fVar3;
      }
    }
    lVar4 = (longdouble)anglemod(fVar1 + local_10);
    *(float *)(param_1 + 0xd4) = (float)lVar4;
  }
  return;
}


// PF_checkbottom_I  @ 0008a9dc
undefined4 PF_checkbottom_I(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = SV_CheckBottom(param_1);
  return uVar1;
}


// PF_checkclient_I  @ 0008806c
int * PF_checkclient_I(int param_1)

{
  double dVar1;
  int iVar2;
  int *piVar3;
  float local_1c;
  float local_18;
  float local_14;
  int *local_8;
  
  dVar1 = DAT_0036bc6c - DAT_0036bc80;
  if ((byte)((0.1 < dVar1 | (byte)((ushort)((ushort)NAN(dVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(dVar1 == 0.1) << 0xe) >> 8)) - 1) < 0x40) {
    DAT_0036bc7c = PF_newcheckclient(DAT_0036bc7c);
    DAT_0036bc80 = DAT_0036bc6c;
  }
  local_8 = DAT_003a78b8 + DAT_0036bc7c * 0xc9;
  piVar3 = DAT_003a78b8;
  if ((*local_8 == 0) && (local_8[0x1f] != 0)) {
    local_1c = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 500);
    local_18 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x1f8);
    local_14 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x1fc);
    iVar2 = Mod_PointInLeaf(&local_1c,DAT_0036bd88);
    iVar2 = ((iVar2 - *(int *)(DAT_0036bd88 + 0x8c)) * -0x55555555 >> 4) + -1;
    if ((iVar2 < 0) || (((int)(uint)(byte)checkpvs[iVar2 >> 3] >> ((byte)iVar2 & 7) & 1U) == 0)) {
      c_notvis = c_notvis + 1;
      piVar3 = DAT_003a78b8;
    }
    else {
      c_invis = c_invis + 1;
      piVar3 = local_8;
    }
  }
  return piVar3;
}


// PF_crosshairangle_I  @ 0008b1e4
void PF_crosshairangle_I(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if (((0 < iVar1) && (iVar1 <= DAT_00524288)) &&
     (iVar1 = DAT_00524284 + iVar1 * 0x4eec + -0x4eec, *(int *)(iVar1 + 0x2438) == 0)) {
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
    MSG_WriteByte(iVar1 + 0x74,0x2f);
    MSG_WriteChar(iVar1 + 0x74,(int)ROUND(param_2 * 5.0));
    MSG_WriteChar(iVar1 + 0x74,(int)ROUND(param_3 * 5.0));
  }
  return;
}


// PF_droptofloor_I  @ 0008a758
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
  
  local_10 = *(undefined4 *)(param_1 + 0x88);
  local_c = *(undefined4 *)(param_1 + 0x8c);
  local_8 = *(float *)(param_1 + 0x90) - 256.0;
  SV_Move(local_48,param_1 + 0x88,param_1 + 0x15c,param_1 + 0x168,&local_10,0,param_1,
          (*(uint *)(param_1 + 0x224) & 0x800000) != 0);
  if (local_48[0] == 0) {
    if ((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40) {
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x88) = local_34;
      *(undefined4 *)(param_1 + 0x8c) = local_30;
      *(undefined4 *)(param_1 + 0x90) = local_2c;
      SV_LinkEdict(param_1,0);
      *(uint *)(param_1 + 0x224) = *(uint *)(param_1 + 0x224) | 0x200;
      *(undefined4 *)(param_1 + 0x21c) = local_18;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// PF_find_Shared  @ 00088c1c
int * PF_find_Shared(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  do {
    local_8 = param_1 + 1;
    if (DAT_003a78b0 <= local_8) {
      return DAT_003a78b8;
    }
    piVar2 = DAT_003a78b8 + local_8 * 0xc9;
    param_1 = local_8;
  } while ((((*piVar2 != 0) ||
            (iVar1 = *(int *)((int)piVar2 + param_2 + 0x80) + pr_strings, iVar1 == 0)) ||
           (iVar1 == pr_strings)) || (iVar1 = Q_strcmp(iVar1,param_3), iVar1 != 0));
  return piVar2;
}


// PF_lightstyle_I  @ 0008a900
void PF_lightstyle_I(int param_1,undefined4 param_2)

{
  int local_c;
  int *local_8;
  
  *(undefined4 *)(&DAT_003a77b0 + param_1 * 4) = param_2;
  if (DAT_003a78c4 == 2) {
    local_8 = DAT_00524284;
    for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
      if (((*local_8 != 0) || (local_8[1] != 0)) && (local_8[0x90e] == 0)) {
        MSG_WriteChar(local_8 + 0x1d,0xc);
        MSG_WriteChar(local_8 + 0x1d,param_1);
        MSG_WriteString(local_8 + 0x1d,param_2);
      }
      local_8 = local_8 + 0x13bb;
    }
  }
  return;
}


// PF_localcmd_I  @ 000887dc
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


// PF_localexec_I  @ 00088838
void PF_localexec_I(void)

{
  Cbuf_Execute();
  return;
}


// PF_makestatic_I  @ 0008c0f0
void PF_makestatic_I(int param_1)

{
  undefined4 uVar1;
  int local_8;
  
  MSG_WriteByte(&DAT_003aa058,0x14);
  uVar1 = SV_ModelIndex(pr_strings + *(int *)(param_1 + 0x138));
  MSG_WriteShort(&DAT_003aa058,uVar1);
  MSG_WriteByte(&DAT_003aa058,*(undefined4 *)(param_1 + 0x1a8));
  MSG_WriteByte(&DAT_003aa058,(int)ROUND(*(float *)(param_1 + 0x1b0)));
  MSG_WriteWord(&DAT_003aa058,*(undefined4 *)(param_1 + 0x228));
  MSG_WriteByte(&DAT_003aa058,*(undefined4 *)(param_1 + 400));
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    MSG_WriteCoord(&DAT_003aa058,*(undefined4 *)(local_8 * 4 + param_1 + 0x88));
    MSG_WriteAngle(&DAT_003aa058,*(undefined4 *)(local_8 * 4 + param_1 + 0xd0));
  }
  MSG_WriteByte(&DAT_003aa058,*(undefined4 *)(param_1 + 0x1c8));
  if (*(int *)(param_1 + 0x1c8) != 0) {
    MSG_WriteByte(&DAT_003aa058,(int)ROUND(*(float *)(param_1 + 0x1cc)));
    MSG_WriteByte(&DAT_003aa058,(int)ROUND(*(float *)(param_1 + 0x1d0)));
    MSG_WriteByte(&DAT_003aa058,(int)ROUND(*(float *)(param_1 + 0x1d4)));
    MSG_WriteByte(&DAT_003aa058,(int)ROUND(*(float *)(param_1 + 0x1d8)));
    MSG_WriteByte(&DAT_003aa058,*(undefined4 *)(param_1 + 0x1dc));
  }
  ED_Free(param_1);
  return;
}


// PF_makevectors_I  @ 0008624c
void PF_makevectors_I(undefined4 param_1)

{
  AngleVectors(param_1,&DAT_0036b248,&DAT_0036b260,&DAT_0036b254);
  return;
}


// PF_modelindex  @ 00086828
undefined4 PF_modelindex(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = SV_ModelIndex(param_1);
  return uVar1;
}


// PF_newcheckclient  @ 00087ec0
int PF_newcheckclient(int param_1)

{
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  int *local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (DAT_00524288 < param_1) {
    param_1 = DAT_00524288;
  }
  if (param_1 == DAT_00524288) {
    local_8 = 1;
  }
  else {
    local_8 = param_1 + 1;
  }
  while( true ) {
    if (local_8 == DAT_00524288 + 1) {
      local_8 = 1;
    }
    local_10 = (int *)(DAT_003a78b8 + local_8 * 0x324);
    if ((local_8 == param_1) ||
       (((*local_10 == 0 && (local_10[0x1f] != 0)) && ((*(byte *)(local_10 + 0x89) & 0x80) == 0))))
    break;
    local_8 = local_8 + 1;
  }
  local_20 = (float)local_10[0x22] + (float)local_10[0x7d];
  local_1c = (float)local_10[0x23] + (float)local_10[0x7e];
  local_18 = (float)local_10[0x24] + (float)local_10[0x7f];
  local_14 = Mod_PointInLeaf(&local_20,DAT_0036bd88);
  local_c = Mod_LeafPVS(local_14,DAT_0036bd88);
  Q_memcpy(checkpvs,local_c,*(int *)(DAT_0036bd88 + 0x88) + 7 >> 3);
  return local_8;
}


// PF_particle_I  @ 00086c28
void PF_particle_I(undefined4 param_1,undefined4 param_2,float param_3,float param_4)

{
  SV_StartParticle(param_1,param_2,(int)ROUND(param_3),(int)ROUND(param_4));
  return;
}


// PF_pointcontents_I  @ 0008aa0c
undefined4 PF_pointcontents_I(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = SV_PointContents(param_1);
  return uVar1;
}


// PF_precache_generic_I  @ 0008a108
int PF_precache_generic_I(int param_1)

{
  int iVar1;
  int local_8;
  
  if (param_1 == 0) {
    Host_Error("PF_precache_generic_I: NULL pointer");
  }
  else {
    iVar1 = PR_IsEmptyString(param_1);
    if (iVar1 == 0) {
      if (DAT_003a78c4 != 1) {
        for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
          if ((*(int *)(&DAT_0039efac + local_8 * 4) != 0) &&
             (iVar1 = Q_strcmp(*(undefined4 *)(&DAT_0039efac + local_8 * 4),param_1), iVar1 == 0)) {
            return local_8;
          }
        }
        Host_Error("PF_precache_generic_I: \'%s\' Precache can only be done in spawn functions",
                   param_1);
      }
      for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
        if (*(int *)(&DAT_0039efac + local_8 * 4) == 0) {
          *(int *)(&DAT_0039efac + local_8 * 4) = param_1;
          return local_8;
        }
        iVar1 = Q_strcasecmp(*(undefined4 *)(&DAT_0039efac + local_8 * 4),param_1);
        if (iVar1 == 0) {
          return local_8;
        }
      }
      Host_Error("PF_precache_generic_I: Generic item \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
                 ,param_1,0x200);
    }
    else {
      Host_Error("PF_precache_generic_I: Bad string \'%s\'",param_1);
    }
  }
  return 0;
}


// PF_precache_model_I  @ 00089eb4
int PF_precache_model_I(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  if (param_1 == (char *)0x0) {
    Host_Error("PF_precache_model_I: NULL pointer");
  }
  else {
    iVar2 = PR_IsEmptyString(param_1);
    if (iVar2 == 0) {
      cVar1 = *param_1;
      if (cVar1 == '!') {
        param_1 = param_1 + 1;
      }
      if (DAT_003a78c4 != 1) {
        for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
          if (((&DAT_0039bda8)[local_8] != 0) &&
             (iVar2 = Q_stricmp((&DAT_0039bda8)[local_8],param_1), iVar2 == 0)) {
            return local_8;
          }
        }
        Host_Error("PF_precache_model_I: \'%s\' Precache can only be done in spawn functions",
                   param_1);
      }
      for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
        if ((&DAT_0039bda8)[local_8] == 0) {
          (&DAT_0039bda8)[local_8] = param_1;
          uVar3 = Mod_ForName(param_1,1,1);
          *(undefined4 *)(&DAT_0039c5a8 + local_8 * 4) = uVar3;
          if (cVar1 == '!') {
            return local_8;
          }
          (&DAT_0039cda8)[local_8] = (&DAT_0039cda8)[local_8] | 1;
          return local_8;
        }
        iVar2 = Q_stricmp((&DAT_0039bda8)[local_8],param_1);
        if (iVar2 == 0) {
          return local_8;
        }
      }
      Host_Error("PF_precache_model_I: Model \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
                 ,param_1,0x200);
    }
    else {
      Host_Error("PF_precache_model_I: Bad string \'%s\'",param_1);
    }
  }
  return 0;
}


// PF_precache_sound_I  @ 0008915c
int PF_precache_sound_I(char *param_1)

{
  int iVar1;
  int local_8;
  
  if (param_1 == (char *)0x0) {
    Host_Error("PF_precache_sound_I: NULL pointer");
  }
  else {
    iVar1 = PR_IsEmptyString(param_1);
    if (iVar1 == 0) {
      if (*param_1 == '!') {
        Host_Error("PF_precache_sound_I: \'%s\' do not precache sentence names!",param_1);
      }
      else {
        if (DAT_003a78c4 != 1) {
          for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
            if (((&DAT_0039dfa8)[local_8] != 0) &&
               (iVar1 = Q_stricmp((&DAT_0039dfa8)[local_8],param_1), iVar1 == 0)) {
              return local_8;
            }
          }
          Host_Error("PF_precache_sound_I: \'%s\' Precache can only be done in spawn functions",
                     param_1);
        }
        DAT_0039efa8 = 0;
        for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
          if ((&DAT_0039dfa8)[local_8] == 0) {
            (&DAT_0039dfa8)[local_8] = param_1;
            return local_8;
          }
          iVar1 = Q_stricmp((&DAT_0039dfa8)[local_8],param_1);
          if (iVar1 == 0) {
            return local_8;
          }
        }
        Host_Error("PF_precache_sound_I: Sound \'%s\' failed to precache because the item count is over the %d limit.\nReduce the number of brush models and/or regular models in the map to correct this."
                   ,param_1,0x200);
      }
    }
    else {
      Host_Error("PF_precache_sound_I: Bad string \'%s\'",param_1);
    }
  }
  return 0;
}


// PF_setmodel_I  @ 0008670c
void PF_setmodel_I(int param_1,int param_2)

{
  int iVar1;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_c = &DAT_0039bda8;
  while ((*local_c != 0 && (iVar1 = Q_stricmp(*local_c,param_2), iVar1 != 0))) {
    local_8 = local_8 + 1;
    local_c = local_c + 1;
  }
  if (*local_c == 0) {
    Host_Error("no precache: %s\n",param_2);
  }
  *(int *)(param_1 + 0x138) = param_2 - pr_strings;
  *(int *)(param_1 + 0x134) = local_8;
  iVar1 = *(int *)(&DAT_0039c5a8 + *(int *)(param_1 + 0x134) * 4);
  if (iVar1 == 0) {
    SetMinMaxSize(param_1,&vec3_origin,&vec3_origin,1);
  }
  else {
    SetMinMaxSize(param_1,iVar1 + 0x54,iVar1 + 0x60,1);
  }
  return;
}


// PF_setorigin_I  @ 000862b8
void PF_setorigin_I(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x88) = *param_2;
  *(undefined4 *)(param_1 + 0x8c) = param_2[1];
  *(undefined4 *)(param_1 + 0x90) = param_2[2];
  SV_LinkEdict(param_1,0);
  return;
}


// PF_setsize_I  @ 000866dc
void PF_setsize_I(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  SetMinMaxSize(param_1,param_2,param_3,0);
  return;
}


// PF_setspawnparms_I  @ 0008c4f8
void PF_setspawnparms_I(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Host_Error("Entity is not a client");
  }
  return;
}


// PF_setview_I  @ 0008b0f8
void PF_setview_I(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_00524288 < iVar1)) {
    Host_Error("PF_setview_I: not a client");
  }
  iVar1 = DAT_00524284 + iVar1 * 0x4eec + -0x4eec;
  if (*(int *)(iVar1 + 0x2438) == 0) {
    *(undefined4 *)(iVar1 + 0x4a88) = param_2;
    MSG_WriteByte(iVar1 + 0x74,5);
    uVar2 = NUM_FOR_EDICT(param_2);
    MSG_WriteShort(iVar1 + 0x74,uVar2);
  }
  return;
}


// PF_sound_I  @ 00086ec4
void PF_sound_I(undefined4 param_1,int param_2,undefined4 param_3,float param_4,float param_5,
               undefined4 param_6,int param_7)

{
  if ((param_4 < 0.0) ||
     ((byte)(255.0 < param_4 | (byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_4 == 255.0) << 0xe) >> 8)) == 1)) {
    Sys_Error("EMIT_SOUND: volume = %i",(double)param_4);
  }
  if ((param_5 < 0.0) ||
     ((byte)(4.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 4.0) << 0xe) >> 8)) == 1)) {
    Sys_Error("EMIT_SOUND: attenuation = %f",(double)param_5);
  }
  if ((param_2 < 0) || (7 < param_2)) {
    Sys_Error("EMIT_SOUND: channel = %i",param_2);
  }
  if ((param_7 < 0) || (0xff < param_7)) {
    Sys_Error("EMIT_SOUND: pitch = %i",param_7);
  }
  SV_StartSound(0,param_1,param_2,param_3,(int)ROUND(param_4 * 255.0),param_5,param_6,param_7);
  return;
}


// PF_sprint  @ 00086904
void PF_sprint(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 1) || (DAT_00524288 < param_2)) {
    Con_Printf("tried to sprint to a non-client\n");
  }
  else {
    iVar1 = DAT_00524284 + param_2 * 0x4eec + -0x4eec;
    if (*(int *)(iVar1 + 0x2438) == 0) {
      MSG_WriteChar(iVar1 + 0x74,8);
      MSG_WriteString(iVar1 + 0x74,param_1);
    }
  }
  return;
}


// PF_stuffcmd_I  @ 00088690
void PF_stuffcmd_I(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = NUM_FOR_EDICT(param_1);
  vsnprintf(szOut_105,0x400,param_2,&stack0x0000000c);
  if ((iVar2 < 1) || (DAT_00524288 < iVar2)) {
    Con_Printf("\n!!!\n\nStuffCmd:  Some entity tried to stuff \'%s\' to console buffer of entity %i when maxclients was set to %i, ignoring\n\n"
               ,szOut_105,iVar2,DAT_00524288);
  }
  else {
    iVar3 = ValidCmd(szOut_105);
    uVar1 = host_client;
    if (iVar3 == 0) {
      Con_Printf("Tried to stuff bad command %s\n",szOut_105);
    }
    else {
      host_client = DAT_00524284 + iVar2 * 0x4eec + -0x4eec;
      Host_ClientCommands(&DAT_000e582c,szOut_105);
      host_client = uVar1;
    }
  }
  return;
}


// PF_traceline_DLL  @ 00087074
void PF_traceline_DLL(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     int *param_5)

{
  if (param_4 == 0) {
    param_4 = DAT_003a78b8;
  }
  PF_traceline_Shared(param_1,param_2,param_3,param_4);
  *param_5 = (int)ROUND(DAT_0036b26c);
  param_5[1] = (int)ROUND(DAT_0036b270);
  param_5[2] = (int)ROUND(DAT_0036b298);
  param_5[3] = (int)ROUND(DAT_0036b29c);
  param_5[4] = DAT_0036b274;
  param_5[8] = DAT_0036b290;
  param_5[0xc] = DAT_0036b294;
  param_5[5] = DAT_0036b278;
  param_5[6] = DAT_0036b27c;
  param_5[7] = DAT_0036b280;
  param_5[9] = DAT_0036b284;
  param_5[10] = DAT_0036b288;
  param_5[0xb] = DAT_0036b28c;
  param_5[0xd] = DAT_0036b2a0;
  return;
}


// PF_traceline_Shared  @ 00087008
void PF_traceline_Shared(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  undefined1 local_3c [56];
  
  SV_Move(local_3c,param_1,&vec3_origin,&vec3_origin,param_2,param_3,param_4,0);
  DAT_0036b2a4 = 0;
  SV_SetGlobalTrace(local_3c);
  return;
}


// PF_vectoangles_I  @ 00086bf8
void PF_vectoangles_I(undefined4 param_1,undefined4 param_2)

{
  VectorAngles(param_1,param_2);
  return;
}


// PF_vectoyaw_I  @ 00086b30
longdouble PF_vectoyaw_I(float *param_1)

{
  double dVar1;
  float local_8;
  
  if (((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    local_8 = 0.0;
  }
  else {
    dVar1 = atan2((double)param_1[1],(double)*param_1);
    local_8 = (float)(int)ROUND((dVar1 * 180.0) / 3.141592653589793);
    if (local_8 < 0.0) {
      local_8 = local_8 + 360.0;
    }
  }
  return (longdouble)local_8;
}


// PF_walkmove_I  @ 0008a65c
undefined4 PF_walkmove_I(int param_1,float param_2,float param_3,int param_4)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  if ((*(uint *)(param_1 + 0x224) & 0x203) == 0) {
    uVar2 = 0;
  }
  else {
    fVar1 = (param_2 * 3.1415927 + param_2 * 3.1415927) / 360.0;
    dVar3 = cos((double)fVar1);
    local_10 = param_3 * (float)dVar3;
    dVar3 = sin((double)fVar1);
    local_c = param_3 * (float)dVar3;
    local_8 = 0;
    if (param_4 == 1) {
      uVar2 = SV_movetest(param_1,&local_10,1);
    }
    else if (param_4 == 2) {
      uVar2 = SV_movestep(param_1,&local_10,0);
    }
    else {
      uVar2 = SV_movestep(param_1,&local_10,1);
    }
  }
  return uVar2;
}


