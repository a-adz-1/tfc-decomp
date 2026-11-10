// PF_BuildSoundMsg_I  @ 00070d88
void PF_BuildSoundMsg_I(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                       undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  PF_MessageBegin_I(param_8,param_9,param_10,param_11);
  SV_BuildSoundMsg(param_1,param_2,param_3,(int)ROUND(param_4),param_5,param_6,param_7,param_10,
                   &gMsgBuffer);
  PF_MessageEnd_I();
  return;
}


// PF_CanSkipPlayer  @ 00070fa8
bool PF_CanSkipPlayer(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to PF_CanSkipPlayer a non-client\n");
    bVar2 = false;
  }
  else {
    bVar2 = *(int *)(DAT_001ab4e4 + -0x108 + iVar1 * 0x5054) != 0;
  }
  return bVar2;
}


// PF_CreateFakeClient_I  @ 0006fb90
int PF_CreateFakeClient_I(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  
  iVar2 = 0;
  if (0 < DAT_001ab4e8) {
    iVar3 = 0;
    do {
      unaff_EDI = (int *)(iVar3 + DAT_001ab4e4);
      if (((*unaff_EDI == 0) && (unaff_EDI[1] == 0)) && (unaff_EDI[3] == 0)) break;
      iVar3 = iVar3 + 0x5054;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_001ab4e8);
  }
  if (iVar2 == DAT_001ab4e8) {
    iVar2 = 0;
  }
  else {
    iVar2 = EDICT_NUM(iVar2 + 1);
    Q_memset(unaff_EDI,0,0x5054);
    unaff_EDI[0x1364] = (int)(unaff_EDI + 0x1343);
    unaff_EDI[0x1363] = (int)(unaff_EDI + 0x1343);
    unaff_EDI[0x1342] = (int)(unaff_EDI + 0x1321);
    unaff_EDI[0x1341] = (int)(unaff_EDI + 0x1321);
    Q_strncpy(unaff_EDI + 0x130f,param_1,0x20);
    *unaff_EDI = 1;
    unaff_EDI[1] = 1;
    unaff_EDI[2] = 1;
    unaff_EDI[3] = 1;
    unaff_EDI[4] = 0;
    unaff_EDI[0x12b9] = iVar2;
    unaff_EDI[0x918] = 1;
    unaff_EDI[0x12bb] = g_userid;
    g_userid = g_userid + 1;
    *(int *)(iVar2 + 0x250) = (int)unaff_EDI - (pr_strings + -0x4c3c);
    *(int *)(iVar2 + 0x288) = iVar2;
    *(undefined4 *)(iVar2 + 0x224) = 0x2008;
    piVar1 = unaff_EDI + 0x12bd;
    Info_SetValueForKey(piVar1,"name",param_1,0x100);
    Info_SetValueForKey(piVar1,"model","gordon",0x100);
    Info_SetValueForKey(piVar1,"topcolor",&DAT_000a99b8,0x100);
    Info_SetValueForKey(piVar1,"bottomcolor",&DAT_000a99b8,0x100);
    unaff_EDI[0x12fd] = 1;
    SV_ExtractFromUserinfo(unaff_EDI);
  }
  return iVar2;
}


// PF_CreateInstancedBaseline  @ 00071044
int PF_CreateInstancedBaseline(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (*DAT_00186f9c < 0x3f) {
    DAT_00186f9c[*DAT_00186f9c + 1] = param_1;
    piVar2 = DAT_00186f9c + *DAT_00186f9c * 0x55 + 0x41;
    for (iVar1 = 0x55; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = *param_2;
      param_2 = param_2 + 1;
      piVar2 = piVar2 + 1;
    }
    *DAT_00186f9c = *DAT_00186f9c + 1;
    iVar1 = *DAT_00186f9c;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// PF_Cvar_DirectSet  @ 000710d0
void PF_Cvar_DirectSet(undefined4 param_1,undefined4 param_2)

{
  Cvar_DirectSet(param_1,param_2);
  return;
}


// PF_DecalIndex  @ 0006f36c
int PF_DecalIndex(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < sv_decalnamecount) {
    iVar3 = 0;
    do {
      iVar1 = Q_stricmp(sv_decalnames + iVar3,param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar3 = iVar3 + 0x11;
      iVar2 = iVar2 + 1;
    } while (iVar2 < sv_decalnamecount);
  }
  return -1;
}


// PF_FadeVolume  @ 00070abc
void PF_FadeVolume(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                  undefined1 param_5)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to PF_FadeVolume a non-client\n");
  }
  else {
    iVar1 = DAT_001ab4e4 + -0x5054 + iVar1 * 0x5054;
    if (*(int *)(iVar1 + 0x2460) == 0) {
      iVar1 = iVar1 + 0x74;
      MSG_WriteChar(iVar1,0x30);
      MSG_WriteByte(iVar1,param_2);
      MSG_WriteByte(iVar1,param_4);
      MSG_WriteByte(iVar1,param_3);
      MSG_WriteByte(iVar1,param_5);
    }
  }
  return;
}


// PF_ForceUnmodified  @ 000710f4
void PF_ForceUnmodified(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_c;
  int local_8;
  
  if (DAT_00186fa0 != 1) {
    local_c = 0;
    iVar2 = 0;
    do {
      if ((*(int *)((int)&DAT_0017de84 + iVar2) != 0) &&
         (iVar1 = Q_stricmp(*(int *)((int)&DAT_0017de84 + iVar2),param_4), iVar1 == 0)) {
        return;
      }
      if ((*(int *)((int)&DAT_0017deb0 + iVar2) != 0) &&
         (iVar1 = Q_stricmp(*(int *)((int)&DAT_0017deb0 + iVar2),param_4), iVar1 == 0)) {
        return;
      }
      if ((*(int *)((int)&DAT_0017dedc + iVar2) != 0) &&
         (iVar1 = Q_stricmp(*(int *)((int)&DAT_0017dedc + iVar2),param_4), iVar1 == 0)) {
        return;
      }
      if ((*(int *)((int)&DAT_0017df08 + iVar2) != 0) &&
         (iVar1 = Q_stricmp(*(int *)((int)&DAT_0017df08 + iVar2),param_4), iVar1 == 0)) {
        return;
      }
      iVar2 = iVar2 + 0xb0;
      local_c = local_c + 4;
    } while (local_c < 0x200);
    Host_Error("ForceUnmodified: \'%s\' Precache can only be done in spawn functions",param_4);
  }
  PR_CheckEmptyString(param_4);
  local_8 = 0;
  piVar3 = &DAT_0017de84;
  iVar2 = 0;
  do {
    if (*piVar3 == 0) {
      *piVar3 = param_4;
      *(undefined4 *)((int)&DAT_0017de94 + iVar2) = param_1;
      if (param_2 != (undefined4 *)0x0) {
        *(undefined4 *)((int)&DAT_0017de98 + iVar2) = *param_2;
        *(undefined4 *)((int)&DAT_0017de9c + iVar2) = param_2[1];
        *(undefined4 *)((int)&DAT_0017dea0 + iVar2) = param_2[2];
      }
      if (param_3 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)((int)&DAT_0017dea4 + iVar2) = *param_3;
      *(undefined4 *)((int)&DAT_0017dea8 + iVar2) = param_3[1];
      *(undefined4 *)((int)&DAT_0017deac + iVar2) = param_3[2];
      return;
    }
    iVar1 = Q_stricmp(*piVar3,param_4);
    if (iVar1 == 0) {
      return;
    }
    piVar3 = piVar3 + 0xb;
    iVar2 = iVar2 + 0x2c;
    local_8 = local_8 + 1;
  } while (local_8 < 0x200);
  Host_Error("ForceUnmodified: \'%s\' overflow",param_4);
  return;
}


// PF_GetCurrentPlayer  @ 00070f68
int PF_GetCurrentPlayer(void)

{
  int iVar1;
  
  iVar1 = (host_client - DAT_001ab4e4) * -0x3356e4c3 >> 2;
  if ((iVar1 < 0) || (DAT_001ab4e8 <= iVar1)) {
    iVar1 = -1;
  }
  return iVar1;
}


// PF_GetInfoKeyBuffer_I  @ 0006f034
undefined1 * PF_GetInfoKeyBuffer_I(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 == 0) {
    puVar2 = localinfo;
  }
  else {
    iVar1 = NUM_FOR_EDICT(param_1);
    if (iVar1 == 0) {
      puVar2 = (undefined1 *)Info_Serverinfo();
    }
    else if (iVar1 < 0x21) {
      puVar2 = (undefined1 *)(DAT_001ab4e4 + -0x560 + iVar1 * 0x5054);
    }
    else {
      puVar2 = &DAT_000a9914;
    }
  }
  return puVar2;
}


// PF_GetPhysicsInfoString  @ 00070e24
undefined * PF_GetPhysicsInfoString(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to PF_GetPhysicsInfoString a non-client\n");
    puVar2 = &DAT_000a9914;
  }
  else {
    puVar2 = (undefined *)(DAT_001ab4e4 + -0x100 + iVar1 * 0x5054);
  }
  return puVar2;
}


// PF_GetPhysicsKeyValue  @ 00070e88
undefined * PF_GetPhysicsKeyValue(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to PF_GetPhysicsKeyValue a non-client\n");
    puVar2 = &DAT_000a9914;
  }
  else {
    puVar2 = (undefined *)Info_ValueForKey(DAT_001ab4e4 + -0x100 + iVar1 * 0x5054,param_2);
  }
  return puVar2;
}


// PF_GetPlayerStats  @ 00071290
void PF_GetPlayerStats(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  *param_2 = 0;
  *param_3 = 0;
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to PF_GetPlayerStats a non-client\n");
  }
  else {
    iVar1 = DAT_001ab4e4 + -0x5054 + iVar1 * 0x5054;
    *param_2 = (int)ROUND(*(float *)(iVar1 + 0x24b0) * 1000.0);
    *param_3 = (int)ROUND(*(float *)(iVar1 + 0x24b4));
  }
  return;
}


// PF_GetPlayerUserId  @ 00070bd0
undefined4 PF_GetPlayerUserId(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (((sv == 0) || (param_1 == 0)) || (iVar3 = 0, (int)DAT_001ab4e8 < 1)) {
LAB_00070c9b:
    uVar2 = 0xffffffff;
  }
  else {
    uVar1 = DAT_001ab4e8 & 3;
    iVar5 = DAT_001ab4e4;
    if (uVar1 == 0) goto LAB_00070c58;
    iVar4 = DAT_001ab4e4;
    if (uVar1 < 2) {
LAB_00070c4d:
      if (*(int *)(iVar4 + 0x4ae4) != param_1) {
        for (iVar3 = iVar3 + 1; iVar5 = iVar4 + 0x5054, iVar3 < (int)DAT_001ab4e8; iVar3 = iVar3 + 4
            ) {
LAB_00070c58:
          iVar4 = iVar5;
          if (((*(int *)(iVar5 + 0x4ae4) == param_1) ||
              (iVar4 = iVar5 + 0x5054, *(int *)(iVar5 + 0x9b38) == param_1)) ||
             ((iVar4 = iVar5 + 0xa0a8, *(int *)(iVar5 + 0xeb8c) == param_1 ||
              (iVar4 = iVar5 + 0xf0fc,
              *(int *)((int)DWORD_ARRAY_000120b0 + iVar5 + 0x1b30) == param_1)))) goto LAB_00070c00;
        }
        goto LAB_00070c9b;
      }
    }
    else if (uVar1 < 3) {
LAB_00070c3e:
      if (*(int *)(iVar4 + 0x4ae4) != param_1) {
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x5054;
        goto LAB_00070c4d;
      }
    }
    else if (*(int *)(DAT_001ab4e4 + 0x4ae4) != param_1) {
      iVar3 = 1;
      iVar4 = DAT_001ab4e4 + 0x5054;
      goto LAB_00070c3e;
    }
LAB_00070c00:
    uVar2 = *(undefined4 *)(iVar4 + 0x4aec);
  }
  return uVar2;
}


// PF_GetPlayerWONId  @ 00070cac
undefined4 PF_GetPlayerWONId(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (((sv == 0) || (param_1 == 0)) || (iVar3 = 0, (int)DAT_001ab4e8 < 1)) {
LAB_00070d77:
    uVar2 = 0xffffffff;
  }
  else {
    uVar1 = DAT_001ab4e8 & 3;
    iVar5 = DAT_001ab4e4;
    if (uVar1 == 0) goto LAB_00070d34;
    iVar4 = DAT_001ab4e4;
    if (uVar1 < 2) {
LAB_00070d29:
      if (*(int *)(iVar4 + 0x4ae4) != param_1) {
        for (iVar3 = iVar3 + 1; iVar5 = iVar4 + 0x5054, iVar3 < (int)DAT_001ab4e8; iVar3 = iVar3 + 4
            ) {
LAB_00070d34:
          iVar4 = iVar5;
          if (((*(int *)(iVar5 + 0x4ae4) == param_1) ||
              (iVar4 = iVar5 + 0x5054, *(int *)(iVar5 + 0x9b38) == param_1)) ||
             ((iVar4 = iVar5 + 0xa0a8, *(int *)(iVar5 + 0xeb8c) == param_1 ||
              (iVar4 = iVar5 + 0xf0fc,
              *(int *)((int)DWORD_ARRAY_000120b0 + iVar5 + 0x1b30) == param_1)))) goto LAB_00070cdc;
        }
        goto LAB_00070d77;
      }
    }
    else if (uVar1 < 3) {
LAB_00070d1a:
      if (*(int *)(iVar4 + 0x4ae4) != param_1) {
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x5054;
        goto LAB_00070d29;
      }
    }
    else if (*(int *)(DAT_001ab4e4 + 0x4ae4) != param_1) {
      iVar3 = 1;
      iVar4 = DAT_001ab4e4 + 0x5054;
      goto LAB_00070d1a;
    }
LAB_00070cdc:
    uVar2 = *(undefined4 *)(iVar4 + 0x4af0);
  }
  return uVar2;
}


// PF_InfoKeyValue_I  @ 0006f0a0
void PF_InfoKeyValue_I(undefined4 param_1,undefined4 param_2)

{
  Info_ValueForKey(param_1,param_2);
  return;
}


// PF_IsDedicatedServer  @ 00070e04
undefined4 PF_IsDedicatedServer(void)

{
  return isDedicated;
}


// PF_IsMapValid_I  @ 0006ef2c
uint PF_IsMapValid_I(undefined4 param_1)

{
  uint uVar1;
  char local_108 [260];
  
  sprintf(local_108,"maps/%.32s.bsp",param_1);
  uVar1 = COM_FileSize(local_108);
  return ~uVar1 >> 0x1f;
}


// PF_MessageBegin_I  @ 0006ffa8
void PF_MessageBegin_I(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  if ((param_1 == 1) || (param_1 == 8)) {
    if (param_4 == 0) {
      Sys_Error("MSG_ONE or MSG_ONE_UNRELIABLE with no target entity\n");
    }
    if (param_1 == 8) goto LAB_0006fffa;
  }
  if ((param_1 != 1) && (param_4 != 0)) {
    Sys_Error("Invalid message;  cannot use broadcast message with a target entity");
  }
LAB_0006fffa:
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
  if (param_1 - 4U < 2) {
    if (param_3 != (undefined4 *)0x0) {
      gMsgOrigin = *param_3;
      DAT_000d68c0 = param_3[1];
      DAT_000d68c4 = param_3[2];
    }
    Host_IsSinglePlayerGame();
  }
  DAT_000b2fbc = 0;
  gMsgBuffer = 0;
  return;
}


// PF_MessageEnd_I  @ 0007009c
void PF_MessageEnd_I(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  bVar1 = false;
  if (gMsgStarted == 0) {
    Sys_Error("MESSAGE_END called with no active message\n");
  }
  gMsgStarted = 0;
  if ((gMsgEntity != 0) && ((*(byte *)(gMsgEntity + 0x225) & 0x20) != 0)) {
    gMsgStarted = 0;
    return;
  }
  if (0x31 < gMsgType) {
    piVar2 = sv_gpUserMsgs;
    if (sv_gpUserMsgs == (int *)0x0) {
LAB_0007011b:
      Con_DPrintf("SV:  Illegal User Msg %d\n",gMsgType);
      return;
    }
    do {
      if (*piVar2 == gMsgType) break;
      piVar2 = (int *)piVar2[5];
    } while (piVar2 != (int *)0x0);
    if (piVar2 == (int *)0x0) goto LAB_0007011b;
    iVar3 = piVar2[1];
    if (iVar3 == -1) {
      bVar1 = true;
    }
    else if (iVar3 != DAT_000b2fbc) {
      Sys_Error("User Msg \'%s\': %d bytes written, expected %d\n",piVar2 + 2,DAT_000b2fbc,iVar3);
      return;
    }
  }
  iVar3 = WriteDest_Parm(gMsgDest);
  if ((gMsgDest == 0) && (*(int *)(iVar3 + 8) < DAT_000b2fbc + *(int *)(iVar3 + 0xc))) {
    return;
  }
  if (*(int *)(iVar3 + 4) == 0) {
    return;
  }
  if ((0x31 < gMsgType) && ((gMsgDest == 1 || (gMsgDest == 8)))) {
    iVar4 = NUM_FOR_EDICT(gMsgEntity);
    if ((iVar4 < 1) || (DAT_001ab4e8 < iVar4)) {
      Host_Error("WriteDest_Parm: not a client");
    }
    piVar2 = (int *)(DAT_001ab4e4 + -0x5054 + iVar4 * 0x5054);
    if (piVar2[5] == 0) {
      return;
    }
    if ((*piVar2 == 0) && (piVar2[1] == 0)) {
      return;
    }
    if (piVar2[0x918] != 0) {
      return;
    }
  }
  MSG_WriteByte(iVar3,gMsgType);
  if (bVar1) {
    MSG_WriteByte(iVar3,DAT_000b2fbc);
  }
  MSG_WriteBuf(iVar3,DAT_000b2fbc,PTR_gMsgData_000b2fb4);
  switch(gMsgDest) {
  case 4:
    uVar6 = 0;
    uVar5 = 2;
    goto LAB_000702a0;
  case 5:
    uVar6 = 0;
    break;
  case 6:
  case 7:
    uVar6 = 1;
    break;
  default:
    goto switchD_0007027b_default;
  }
  uVar5 = 4;
LAB_000702a0:
  SV_Multicast(&gMsgOrigin,uVar5,uVar6);
switchD_0007027b_default:
  return;
}


// PF_NumberOfEntities_I  @ 0006ef74
uint PF_NumberOfEntities_I(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar4 = 0;
  if (0 < (int)DAT_00186f8c) {
    iVar2 = 0;
    uVar3 = DAT_00186f8c & 3;
    if (uVar3 != 0) {
      if (1 < uVar3) {
        if (2 < uVar3) {
          uVar1 = (uint)(*DAT_00186f94 == 0);
          iVar2 = 0x324;
        }
        if (*(int *)((int)DAT_00186f94 + iVar2) == 0) {
          uVar1 = uVar1 + 1;
        }
        iVar2 = iVar2 + 0x324;
        iVar4 = (2 < uVar3) + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar2) == 0) {
        uVar1 = uVar1 + 1;
      }
      iVar2 = iVar2 + 0x324;
      iVar4 = iVar4 + 1;
      if ((int)DAT_00186f8c <= iVar4) {
        return uVar1;
      }
    }
    do {
      if (*(int *)((int)DAT_00186f94 + iVar2) == 0) {
        uVar1 = uVar1 + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar2 + 0x324) == 0) {
        uVar1 = uVar1 + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar2 + 0x648) == 0) {
        uVar1 = uVar1 + 1;
      }
      if (*(int *)((int)DAT_00186f94 + iVar2 + 0x96c) == 0) {
        uVar1 = uVar1 + 1;
      }
      iVar2 = iVar2 + 0xc90;
      iVar4 = iVar4 + 4;
    } while (iVar4 < (int)DAT_00186f8c);
  }
  return uVar1;
}


// PF_RemoveKey_I  @ 0006f120
void PF_RemoveKey_I(undefined4 param_1,undefined4 param_2)

{
  Info_RemoveKey(param_1,param_2);
  return;
}


// PF_Remove_I  @ 0006dc78
void PF_Remove_I(undefined4 param_1)

{
  ED_Free(param_1);
  return;
}


// PF_RunPlayerMove_I  @ 0006fd3c
void PF_RunPlayerMove_I(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4
                       ,undefined4 param_5,undefined2 param_6,undefined1 param_7,byte param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  
  uVar2 = sv_player;
  uVar1 = host_client;
  iVar3 = NUM_FOR_EDICT(param_1);
  sv_player = param_1;
  host_client = DAT_001ab4e4 + -0x5054 + iVar3 * 0x5054;
  *(double *)(host_client + 0x24c8) = (DAT_0015358c + host_frametime) - (double)param_8 * 0.001;
  Q_memset(&local_38,0,0x34);
  local_34 = *param_2;
  local_30 = param_2[1];
  local_2c = param_2[2];
  local_1a = param_6;
  local_18 = param_7;
  local_1c = 0;
  local_38._2_1_ = param_8;
  local_28 = param_3;
  local_24 = param_4;
  local_20 = param_5;
  pmove = g_svmove;
  SV_PreRunCmd();
  SV_RunCmd(&local_38,0);
  puVar4 = &local_38;
  puVar5 = (undefined4 *)(host_client + 0x246c);
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  sv_player = uVar2;
  host_client = uVar1;
  return;
}


// PF_SetClientKeyValue_I  @ 0006f144
void PF_SetClientKeyValue_I(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 != localinfo) {
    puVar1 = (undefined1 *)Info_Serverinfo();
    if (((param_2 != puVar1) && (0 < param_1)) && (param_1 <= DAT_001ab4e8)) {
      uVar2 = Info_ValueForKey(param_2,param_3,param_4);
      iVar3 = Q_strcmp(uVar2);
      if (iVar3 != 0) {
        Info_SetValueForKey(param_2,param_3,param_4,0x100);
        iVar3 = DAT_001ab4e4 + -0x5054 + param_1 * 0x5054;
        *(undefined4 *)(iVar3 + 0x4bf4) = 1;
        *(undefined4 *)(iVar3 + 0x4bf8) = 0;
      }
    }
  }
  return;
}


// PF_SetClientMaxspeed  @ 00070b60
void PF_SetClientMaxspeed(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to PF_SetClientMaxspeed a non-client\n");
  }
  else if (*(int *)(DAT_001ab4e4 + -0x2bf4 + iVar1 * 0x5054) == 0) {
    *(undefined4 *)(param_1 + 0x290) = param_2;
  }
  return;
}


// PF_SetGroupMask  @ 00071014
void PF_SetGroupMask(undefined4 param_1,undefined4 param_2)

{
  g_groupmask = param_1;
  g_groupop = param_2;
  return;
}


// PF_SetKeyValue_I  @ 0006f0c4
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


// PF_SetPhysicsKeyValue  @ 00070ef8
void PF_SetPhysicsKeyValue(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to PF_SetPhysicsKeyValue a non-client\n");
  }
  else {
    Info_SetValueForKey(DAT_001ab4e4 + -0x100 + iVar1 * 0x5054,param_2,param_3,0x100);
  }
  return;
}


// PF_Spawn_I  @ 0006dbd4
void PF_Spawn_I(void)

{
  ED_Alloc();
  return;
}


// PF_StaticDecal  @ 000706bc
void PF_StaticDecal(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  MSG_WriteByte(&DAT_0018a2c4,0x17);
  MSG_WriteByte(&DAT_0018a2c4,0xd);
  MSG_WriteCoord(&DAT_0018a2c4,*param_1);
  MSG_WriteCoord(&DAT_0018a2c4,param_1[1]);
  MSG_WriteCoord(&DAT_0018a2c4,param_1[2]);
  MSG_WriteShort(&DAT_0018a2c4,param_2);
  MSG_WriteShort(&DAT_0018a2c4,param_3);
  if (param_3 != 0) {
    MSG_WriteShort(&DAT_0018a2c4,param_4);
  }
  return;
}


// PF_Time  @ 0006befc
longdouble PF_Time(void)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)Sys_FloatTime();
  return (longdouble)(float)lVar1;
}


// PF_TraceToss_DLL  @ 0006d160
void PF_TraceToss_DLL(undefined4 param_1,int param_2,int *param_3)

{
  if (param_2 == 0) {
    param_2 = DAT_00186f94;
  }
  PF_TraceToss_Shared(param_1,param_2);
  *param_3 = (int)ROUND(DAT_00152b8c);
  param_3[1] = (int)ROUND(DAT_00152b90);
  param_3[2] = (int)ROUND(DAT_00152bb8);
  param_3[3] = (int)ROUND(DAT_00152bbc);
  param_3[4] = DAT_00152b94;
  param_3[8] = DAT_00152bb0;
  param_3[0xc] = DAT_00152bb4;
  param_3[5] = DAT_00152b98;
  param_3[6] = DAT_00152b9c;
  param_3[7] = DAT_00152ba0;
  param_3[9] = DAT_00152ba4;
  param_3[10] = DAT_00152ba8;
  param_3[0xb] = DAT_00152bac;
  param_3[0xd] = DAT_00152bc0;
  return;
}


// PF_TraceToss_Shared  @ 0006d068
void PF_TraceToss_Shared(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_3c [56];
  
  SV_Trace_Toss(local_3c,param_1,param_2);
  SV_SetGlobalTrace(local_3c);
  return;
}


// PF_WaterMove  @ 00082a1c
void PF_WaterMove(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  undefined4 uVar6;
  char *pcVar7;
  longdouble lVar8;
  
  if (*(int *)(param_1 + 0x188) == 8) goto LAB_00082c10;
  if (*(float *)(param_1 + 0x1e0) < 0.0) {
    return;
  }
  fVar1 = 1.0;
  if (*(int *)(param_1 + 0x1f0) == 0) {
    fVar1 = 3.0;
  }
  uVar2 = *(uint *)(param_1 + 0x224);
  iVar3 = *(int *)(param_1 + 0x240);
  iVar4 = *(int *)(param_1 + 0x244);
  if ((uVar2 & 0x20040) == 0) {
    if ((((uVar2 & 2) != 0) && ((float)iVar3 < fVar1)) || (fVar1 <= (float)iVar3)) {
      dVar5 = (double)*(float *)(param_1 + 0x27c);
      if ((0x3f < (byte)((DAT_0015358c < dVar5 |
                          (byte)((ushort)((ushort)(NAN(DAT_0015358c) || NAN(dVar5)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(DAT_0015358c == dVar5) << 0xe) >> 8)) - 1)) &&
         (dVar5 = (double)*(float *)(param_1 + 0x280),
         0x3f < (byte)((DAT_0015358c < dVar5 |
                        (byte)((ushort)((ushort)(NAN(DAT_0015358c) || NAN(dVar5)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(DAT_0015358c == dVar5) << 0xe) >> 8)) - 1))) {
        fVar1 = *(float *)(param_1 + 0x260) + 2.0;
        *(float *)(param_1 + 0x260) = fVar1;
        if (0x3f < (byte)((fVar1 < 15.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 15.0) << 0xe) >> 8)) - 1)) {
          *(undefined4 *)(param_1 + 0x260) = 0x41200000;
        }
        *(float *)(param_1 + 0x280) = (float)DAT_0015358c + 1.0;
      }
    }
    else {
      lVar8 = (longdouble)DAT_0015358c;
      *(undefined4 *)(param_1 + 0x260) = 0x40000000;
      *(float *)(param_1 + 0x27c) = (float)((longdouble)12.0 + lVar8);
    }
  }
  if (iVar3 != 0) {
    if (iVar4 == -5) {
      if (((uVar2 & 0x80040) == 0) &&
         (dVar5 = (double)*(float *)(param_1 + 0x264),
         0x3f < (byte)((DAT_0015358c < dVar5 |
                        (byte)((ushort)((ushort)(NAN(DAT_0015358c) || NAN(dVar5)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(DAT_0015358c == dVar5) << 0xe) >> 8)) - 1))) {
        dVar5 = (double)*(float *)(param_1 + 0x284);
        if ((byte)((DAT_0015358c < dVar5 |
                    (byte)((ushort)((ushort)(NAN(DAT_0015358c) || NAN(dVar5)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(DAT_0015358c == dVar5) << 0xe) >> 8)) - 1) < 0x40)
        goto LAB_00082cb2;
        lVar8 = (longdouble)0.2;
LAB_00082cb4:
        *(float *)(param_1 + 0x264) = (float)(lVar8 + (longdouble)DAT_0015358c);
      }
    }
    else if (((iVar4 == -4) && ((uVar2 & 0x40040) == 0)) &&
            ((dVar5 = (double)*(float *)(param_1 + 0x264),
             0x3f < (byte)((DAT_0015358c < dVar5 |
                            (byte)((ushort)((ushort)(NAN(DAT_0015358c) || NAN(dVar5)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(DAT_0015358c == dVar5) << 0xe) >> 8)) - 1) &&
             (dVar5 = (double)*(float *)(param_1 + 0x284),
             0x3f < (byte)((DAT_0015358c < dVar5 |
                            (byte)((ushort)((ushort)(NAN(DAT_0015358c) || NAN(dVar5)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(DAT_0015358c == dVar5) << 0xe) >> 8)) - 1))))) {
LAB_00082cb2:
      lVar8 = (longdouble)1;
      goto LAB_00082cb4;
    }
    if ((uVar2 & 0x10) != 0) goto LAB_00082d8e;
    if (iVar4 == -3) {
      uVar6 = RandomLong(0,3);
      switch(uVar6) {
      case 0:
        pcVar7 = "player/pl_wade1.wav";
        break;
      case 1:
        pcVar7 = "player/pl_wade2.wav";
        break;
      case 2:
        pcVar7 = "player/pl_wade3.wav";
        break;
      case 3:
        pcVar7 = "player/pl_wade4.wav";
        break;
      default:
        goto switchD_00082cfb_default;
      }
      SV_StartSound(0,param_1,4,pcVar7,0xff,0x3f4ccccd,0,100);
    }
switchD_00082cfb_default:
    *(uint *)(param_1 + 0x224) = uVar2 | 0x10;
    *(undefined4 *)(param_1 + 0x264) = 0;
LAB_00082d8e:
    if ((uVar2 & 0x800) != 0) {
      return;
    }
    iVar3 = param_1 + 0xa0;
    VectorMA(iVar3,(float)((longdouble)-0.8 * (longdouble)host_frametime *
                          (longdouble)*(int *)(param_1 + 0x240)),iVar3,iVar3);
    return;
  }
  if ((uVar2 & 0x10) == 0) goto LAB_00082c10;
  uVar6 = RandomLong(0,3);
  switch(uVar6) {
  case 0:
    pcVar7 = "player/pl_wade1.wav";
    break;
  case 1:
    pcVar7 = "player/pl_wade2.wav";
    break;
  case 2:
    pcVar7 = "player/pl_wade3.wav";
    break;
  case 3:
    pcVar7 = "player/pl_wade4.wav";
    break;
  default:
    goto switchD_00082b8d_default;
  }
  SV_StartSound(0,param_1,4,pcVar7,0xff,0x3f4ccccd,0,100);
switchD_00082b8d_default:
  *(uint *)(param_1 + 0x224) = uVar2 & 0xffffffef;
LAB_00082c10:
  *(float *)(param_1 + 0x27c) = (float)((longdouble)12.0 + (longdouble)DAT_0015358c);
  return;
}


// PF_WriteAngle_I  @ 000703b8
void PF_WriteAngle_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteAngle_I called with no active message\n");
  }
  MSG_WriteAngle(&gMsgBuffer,param_1);
  return;
}


// PF_WriteByte_I  @ 000702b8
void PF_WriteByte_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_BYTE called with no active message\n");
  }
  MSG_WriteByte(&gMsgBuffer,param_1);
  return;
}


// PF_WriteChar_I  @ 000702f8
void PF_WriteChar_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_CHAR called with no active message\n");
  }
  MSG_WriteChar(&gMsgBuffer,param_1);
  return;
}


// PF_WriteCoord_I  @ 000703fc
void PF_WriteCoord_I(float param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteCoord_I called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,(int)ROUND(param_1 * 8.0));
  return;
}


// PF_WriteEntity_I  @ 0007049c
void PF_WriteEntity_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteEntity_I called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,param_1);
  return;
}


// PF_WriteLong_I  @ 00070378
void PF_WriteLong_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteLong_I called with no active message\n");
  }
  MSG_WriteLong(&gMsgBuffer,param_1);
  return;
}


// PF_WriteShort_I  @ 00070338
void PF_WriteShort_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("WRITE_SHORT called with no active message\n");
  }
  MSG_WriteShort(&gMsgBuffer,param_1);
  return;
}


// PF_WriteString_I  @ 0007045c
void PF_WriteString_I(undefined4 param_1)

{
  if (gMsgStarted == 0) {
    Sys_Error("PF_WriteString_I called with no active message\n");
  }
  MSG_WriteString(&gMsgBuffer,param_1);
  return;
}


// PF_aim_I  @ 0006f4d4
void PF_aim_I(int param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float **ppfVar2;
  undefined1 *puVar3;
  int iVar4;
  float *pfStack_a8;
  int local_88;
  float local_78;
  int local_74;
  undefined1 local_6c [48];
  int local_3c;
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
  
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x225) & 0x20) == 0)) {
    local_10 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 500);
    local_c = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x1f8);
    local_8 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x1fc);
    local_1c = DAT_00152b68;
    local_18 = DAT_00152b6c;
    local_14 = DAT_00152b70;
    pfStack_a8 = &local_28;
    VectorMA(&local_10,0x45000000,&local_1c);
    SV_Move(local_6c,&local_10,&vec3_origin,&vec3_origin,&local_28,0,param_1,0);
    if (((local_3c == 0) ||
        ((byte)((byte)((ushort)((ushort)NAN(*(float *)(local_3c + 0x1ec)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(local_3c + 0x1ec) == 2.0) << 0xe) >> 8)) != 0x40)
        ) || ((0 < *(int *)(param_1 + 0x22c) &&
              (*(int *)(param_1 + 0x22c) == *(int *)(local_3c + 0x22c))))) {
      local_34 = local_1c;
      local_30 = local_18;
      local_2c = local_14;
      local_78 = (float)sv_aim._12_4_;
      local_74 = 1;
      if (1 < DAT_00186f8c) {
        local_88 = 0x324;
        ppfVar2 = &pfStack_a8;
        do {
          iVar4 = local_88 + DAT_00186f94;
          puVar3 = (undefined1 *)ppfVar2;
          if (((((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar4 + 0x1ec)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(*(float *)(iVar4 + 0x1ec) == 2.0) << 0xe) >> 8)) ==
                 0x40) && ((*(byte *)(iVar4 + 0x225) & 0x20) == 0)) && (iVar4 != param_1)) &&
             ((*(int *)(param_1 + 0x22c) < 1 ||
              (*(int *)(param_1 + 0x22c) != *(int *)(iVar4 + 0x22c))))) {
            local_28 = (*(float *)(iVar4 + 0x15c) + *(float *)(iVar4 + 0x168)) * 0.75 +
                       *(float *)(iVar4 + 0x88);
            local_24 = (*(float *)(iVar4 + 0x160) + *(float *)(iVar4 + 0x16c)) * 0.75 +
                       *(float *)(iVar4 + 0x8c);
            local_20 = (*(float *)(iVar4 + 0x164) + *(float *)(iVar4 + 0x170)) * 0.75 +
                       *(float *)(iVar4 + 0x90);
            local_1c = local_28 - local_10;
            local_18 = local_24 - local_c;
            local_14 = local_20 - local_8;
            *(float **)((int)ppfVar2 + -4) = &local_1c;
            *(undefined4 *)((int)ppfVar2 + -8) = 0x6f71f;
            VectorNormalize();
            fVar1 = local_14 * DAT_00152b70 + local_18 * DAT_00152b6c + local_1c * DAT_00152b68;
            if ((byte)(fVar1 < local_78 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_78)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == local_78) << 0xe) >> 8)) != 1) {
              *(undefined4 *)((int)ppfVar2 + -4) = 0;
              *(int *)((int)ppfVar2 + -8) = param_1;
              *(undefined4 *)((int)ppfVar2 + -0xc) = 0;
              *(float **)((int)ppfVar2 + -0x10) = &local_28;
              *(undefined4 **)((int)ppfVar2 + -0x14) = &vec3_origin;
              *(undefined4 **)((int)ppfVar2 + -0x18) = &vec3_origin;
              *(float **)((int)ppfVar2 + -0x1c) = &local_10;
              *(undefined1 **)((int)ppfVar2 + -0x20) = local_6c;
              *(undefined4 *)((int)ppfVar2 + -0x24) = 0x6f775;
              SV_Move();
              puVar3 = (undefined1 *)((int)ppfVar2 + -4);
              if (local_3c == iVar4) {
                local_34 = local_1c;
                local_30 = local_18;
                local_2c = local_14;
                puVar3 = (undefined1 *)((int)ppfVar2 + -4);
                local_78 = fVar1;
              }
            }
          }
          local_88 = local_88 + 0x324;
          local_74 = local_74 + 1;
          ppfVar2 = (float **)puVar3;
        } while (local_74 < DAT_00186f8c);
      }
      *param_3 = local_34;
      param_3[1] = local_30;
      goto LAB_0006f7cf;
    }
  }
  *param_3 = DAT_00152b68;
  param_3[1] = DAT_00152b6c;
  local_2c = DAT_00152b70;
LAB_0006f7cf:
  param_3[2] = local_2c;
  return;
}


// PF_ambientsound_I  @ 0006c4e8
void PF_ambientsound_I(undefined4 param_1,undefined4 *param_2,char *param_3,float param_4,
                      float param_5,uint param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int local_14;
  
  if (*param_3 == '!') {
    param_6 = param_6 | 0x10;
    param_3 = param_3 + 1;
    local_14 = Q_atoi(param_3);
    if (local_14 < 0x600) {
LAB_0006c578:
      uVar4 = NUM_FOR_EDICT(param_1);
      if ((param_6 & 0x100) == 0) {
        puVar6 = &DAT_00186fa4;
      }
      else {
        puVar6 = &DAT_0018a2c4;
      }
      MSG_WriteByte(puVar6,0x1d);
      puVar1 = param_2 + 2;
      if ((int)param_2 < (int)param_2 + 9) {
        MSG_WriteCoord(puVar6,*param_2);
        MSG_WriteCoord(puVar6,param_2[1]);
        param_2 = param_2 + 2;
      }
      MSG_WriteCoord(puVar6,*param_2);
      for (param_2 = param_2 + 1; (int)param_2 <= (int)puVar1; param_2 = param_2 + 4) {
        MSG_WriteCoord(puVar6,*param_2);
        MSG_WriteCoord(puVar6,param_2[1]);
        MSG_WriteCoord(puVar6,param_2[2]);
        MSG_WriteCoord(puVar6,param_2[3]);
      }
      MSG_WriteShort(puVar6,local_14);
      MSG_WriteByte(puVar6,(int)ROUND(param_4 * 255.0));
      MSG_WriteByte(puVar6,(int)ROUND(param_5 * 64.0));
      MSG_WriteShort(puVar6,uVar4);
      MSG_WriteByte(puVar6,param_7);
      MSG_WriteByte(puVar6,param_6 & 0xff);
      return;
    }
    pcVar3 = "invalid sentence number: %s";
  }
  else {
    local_14 = 0;
    piVar5 = &DAT_00185688;
    if (DAT_00185688 != 0) {
      do {
        iVar2 = Q_stricmp(*piVar5,param_3);
        if (iVar2 == 0) break;
        piVar5 = piVar5 + 1;
        local_14 = local_14 + 1;
      } while (*piVar5 != 0);
      if (*piVar5 != 0) goto LAB_0006c578;
    }
    pcVar3 = "no precache: %s\n";
  }
  Con_Printf(pcVar3,param_3);
  return;
}


// PF_bprint  @ 0006c284
void PF_bprint(undefined4 param_1)

{
  SV_BroadcastPrintf(&DAT_000a91f8,param_1);
  return;
}


// PF_changelevel_I  @ 00070790
void PF_changelevel_I(char *param_1,char *param_2)

{
  undefined4 uVar1;
  char **ppcVar2;
  char *pcStack_1c;
  char *pcStack_18;
  char *pcStack_14;
  
  if (DAT_001ab4f0 != last_spawncount_247) {
    pcStack_14 = (char *)0x707c4;
    last_spawncount_247 = DAT_001ab4f0;
    SV_SkipUpdates();
    if (param_2 == (char *)0x0) {
      pcStack_14 = param_1;
      pcStack_18 = "changelevel %s\n";
      ppcVar2 = &pcStack_18;
      pcStack_1c = (char *)0x707d5;
      uVar1 = va();
    }
    else {
      pcStack_14 = param_2;
      pcStack_18 = param_1;
      pcStack_1c = "changelevel2 %s %s\n";
      ppcVar2 = &pcStack_1c;
      uVar1 = va();
    }
    *(undefined4 *)((int)ppcVar2 + -4) = uVar1;
    *(undefined4 *)((int)ppcVar2 + -8) = 0x707ec;
    Cbuf_AddText();
  }
  return;
}


// PF_changepitch_I  @ 0006f8d4
void PF_changepitch_I(int param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar1 = (longdouble)anglemod(*(undefined4 *)(param_1 + 0xd0));
  lVar2 = (longdouble)*(float *)(param_1 + 0x124);
  lVar3 = (longdouble)*(float *)(param_1 + 0x128);
  if ((byte)(lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) != 0x40) {
    lVar4 = lVar2 - lVar1;
    if ((byte)((lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1) < 0x40) {
      lVar2 = (longdouble)-180.0;
      if ((byte)(lVar2 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) != 1) {
        lVar4 = (longdouble)360.0 + lVar4;
      }
    }
    else if ((longdouble)180.0 <= lVar4) {
      lVar4 = lVar4 - (longdouble)360.0;
    }
    if (lVar4 <= (longdouble)0) {
      lVar3 = -lVar3;
      if (0x3f < (byte)((lVar3 < lVar4 |
                         (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) - 1)) {
        lVar4 = lVar3;
      }
    }
    else if (0x3f < (byte)((lVar4 < lVar3 |
                            (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1)) {
      lVar4 = lVar3;
    }
    lVar1 = (longdouble)anglemod((float)(lVar1 + lVar4));
    *(float *)(param_1 + 0xd0) = (float)lVar1;
  }
  return;
}


// PF_changeyaw_I  @ 0006f7e0
void PF_changeyaw_I(int param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar1 = (longdouble)anglemod(*(undefined4 *)(param_1 + 0xd4));
  lVar2 = (longdouble)*(float *)(param_1 + 300);
  lVar3 = (longdouble)*(float *)(param_1 + 0x130);
  if ((byte)(lVar1 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) != 0x40) {
    lVar4 = lVar2 - lVar1;
    if ((byte)((lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1) < 0x40) {
      lVar2 = (longdouble)-180.0;
      if ((byte)(lVar2 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) != 1) {
        lVar4 = (longdouble)360.0 + lVar4;
      }
    }
    else if ((longdouble)180.0 <= lVar4) {
      lVar4 = lVar4 - (longdouble)360.0;
    }
    if (lVar4 <= (longdouble)0) {
      lVar3 = -lVar3;
      if (0x3f < (byte)((lVar3 < lVar4 |
                         (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar3 == lVar4) << 0xe) >> 8)) - 1)) {
        lVar4 = lVar3;
      }
    }
    else if (0x3f < (byte)((lVar4 < lVar3 |
                            (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1)) {
      lVar4 = lVar3;
    }
    lVar1 = (longdouble)anglemod((float)(lVar1 + lVar4));
    *(float *)(param_1 + 0xd4) = (float)lVar1;
  }
  return;
}


// PF_checkbottom_I  @ 0006f494
void PF_checkbottom_I(undefined4 param_1)

{
  SV_CheckBottom(param_1);
  return;
}


// PF_checkclient_I  @ 0006d464
int * PF_checkclient_I(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  float local_10;
  float local_c;
  float local_8;
  
  if (0.1 <= DAT_0015358c - DAT_001535a0) {
    DAT_0015359c = PF_newcheckclient(DAT_0015359c);
    DAT_001535a0 = DAT_0015358c;
  }
  piVar2 = DAT_00186f94 + DAT_0015359c * 0xc9;
  piVar4 = DAT_00186f94;
  if ((*piVar2 == 0) && (piVar2[0x1f] != 0)) {
    local_10 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 500);
    local_c = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x1f8);
    local_8 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x1fc);
    iVar3 = Mod_PointInLeaf(&local_10,DAT_00153668);
    uVar1 = ((iVar3 - *(int *)(DAT_00153668 + 0x8c)) * -0x55555555 >> 4) - 1;
    if (((int)uVar1 < 0) || (((byte)checkpvs[(int)uVar1 >> 3] >> (uVar1 & 7) & 1) == 0)) {
      c_notvis = c_notvis + 1;
      piVar4 = DAT_00186f94;
    }
    else {
      c_invis = c_invis + 1;
      piVar4 = piVar2;
    }
  }
  return piVar4;
}


// PF_crosshairangle_I  @ 0006fa58
void PF_crosshairangle_I(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if (((0 < iVar1) && (iVar1 <= DAT_001ab4e8)) &&
     (iVar1 = DAT_001ab4e4 + -0x5054 + iVar1 * 0x5054, *(int *)(iVar1 + 0x2460) == 0)) {
    if (180.0 < param_2) {
      param_2 = param_2 - 360.0;
    }
    if (0x3f < (byte)((-180.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(param_2 == -180.0) << 0xe) >> 8)) - 1)) {
      param_2 = param_2 + 360.0;
    }
    if (180.0 < param_3) {
      param_3 = param_3 - 360.0;
    }
    if (0x3f < (byte)((-180.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(param_3 == -180.0) << 0xe) >> 8)) - 1)) {
      param_3 = param_3 + 360.0;
    }
    iVar1 = iVar1 + 0x74;
    MSG_WriteByte(iVar1,0x2f);
    MSG_WriteChar(iVar1,(int)ROUND(param_2 * 5.0));
    MSG_WriteChar(iVar1,(int)ROUND(param_3 * 5.0));
  }
  return;
}


// PF_droptofloor_I  @ 0006f294
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
          (*(byte *)(param_1 + 0x226) & 0x80) != 0);
  if (local_48[0] == 0) {
    if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40) {
      uVar1 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x88) = local_34;
      *(undefined4 *)(param_1 + 0x8c) = local_30;
      *(undefined4 *)(param_1 + 0x90) = local_2c;
      SV_LinkEdict(param_1,0);
      *(byte *)(param_1 + 0x225) = *(byte *)(param_1 + 0x225) | 2;
      *(undefined4 *)(param_1 + 0x21c) = local_18;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// PF_find_Shared  @ 0006dc98
int * PF_find_Shared(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  param_1 = param_1 + 1;
  if (param_1 < DAT_00186f8c) {
    local_8 = param_1 * 0x324;
    do {
      piVar2 = (int *)(local_8 + (int)DAT_00186f94);
      if ((((*piVar2 == 0) &&
           (iVar1 = pr_strings + *(int *)((int)piVar2 + param_2 + 0x80), iVar1 != 0)) &&
          (iVar1 != pr_strings)) && (iVar1 = Q_strcmp(iVar1,param_3), iVar1 == 0)) {
        return piVar2;
      }
      local_8 = local_8 + 0x324;
      param_1 = param_1 + 1;
    } while (param_1 < DAT_00186f8c);
  }
  return DAT_00186f94;
}


// PF_lightstyle_I  @ 0006f3cc
void PF_lightstyle_I(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int local_c;
  int *local_8;
  
  (&DAT_00186e8c)[param_1] = param_2;
  if (DAT_00186fa0 == 2) {
    local_c = 0;
    local_8 = DAT_001ab4e4;
    if (0 < DAT_001ab4e8) {
      piVar1 = DAT_001ab4e4 + 0x1d;
      piVar2 = DAT_001ab4e4 + 0x918;
      do {
        if (((*local_8 != 0) || (piVar2[-0x917] != 0)) && (*piVar2 == 0)) {
          MSG_WriteChar(piVar1,0xc);
          MSG_WriteChar(piVar1,param_1);
          MSG_WriteString(piVar1,param_2);
        }
        local_c = local_c + 1;
        piVar2 = piVar2 + 0x1415;
        piVar1 = piVar1 + 0x1415;
        local_8 = local_8 + 0x1415;
      } while (local_c < DAT_001ab4e8);
    }
  }
  return;
}


// PF_localcmd_I  @ 0006d97c
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


// PF_localexec_I  @ 0006d9c0
void PF_localexec_I(void)

{
  Cbuf_Execute();
  return;
}


// PF_makestatic_I  @ 000704dc
void PF_makestatic_I(int param_1)

{
  undefined4 uVar1;
  
  MSG_WriteByte(&DAT_0018a2c4,0x14);
  uVar1 = SV_ModelIndex(*(int *)(param_1 + 0x138) + pr_strings);
  MSG_WriteShort(&DAT_0018a2c4,uVar1);
  MSG_WriteByte(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0x1a8));
  MSG_WriteByte(&DAT_0018a2c4,(int)ROUND(*(float *)(param_1 + 0x1b0)));
  MSG_WriteWord(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0x228));
  MSG_WriteByte(&DAT_0018a2c4,*(undefined4 *)(param_1 + 400));
  MSG_WriteCoord(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0x88));
  MSG_WriteAngle(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0xd0));
  MSG_WriteCoord(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0x8c));
  MSG_WriteAngle(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0xd4));
  MSG_WriteCoord(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0x90));
  MSG_WriteAngle(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0xd8));
  MSG_WriteByte(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0x1c8));
  if (*(int *)(param_1 + 0x1c8) != 0) {
    MSG_WriteByte(&DAT_0018a2c4,(int)ROUND(*(float *)(param_1 + 0x1cc)));
    MSG_WriteByte(&DAT_0018a2c4,(int)ROUND(*(float *)(param_1 + 0x1d0)));
    MSG_WriteByte(&DAT_0018a2c4,(int)ROUND(*(float *)(param_1 + 0x1d4)));
    MSG_WriteByte(&DAT_0018a2c4,(int)ROUND(*(float *)(param_1 + 0x1d8)));
    MSG_WriteByte(&DAT_0018a2c4,*(undefined4 *)(param_1 + 0x1dc));
  }
  ED_Free(param_1);
  return;
}


// PF_makevectors_I  @ 0006bec8
void PF_makevectors_I(undefined4 param_1)

{
  AngleVectors(param_1,&DAT_00152b68,&DAT_00152b80,&DAT_00152b74);
  return;
}


// PF_modelindex  @ 0006c218
void PF_modelindex(undefined4 param_1)

{
  SV_ModelIndex(param_1);
  return;
}


// PF_newcheckclient  @ 0006d34c
int PF_newcheckclient(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (DAT_001ab4e8 < param_1) {
    param_1 = DAT_001ab4e8;
  }
  iVar3 = param_1 + 1;
  if (param_1 == DAT_001ab4e8) {
    iVar3 = 1;
  }
  while( true ) {
    if (iVar3 == DAT_001ab4e8 + 1) {
      iVar3 = 1;
    }
    piVar1 = (int *)(DAT_00186f94 + iVar3 * 0x324);
    if ((iVar3 == param_1) || (((*piVar1 == 0 && (piVar1[0x1f] != 0)) && (-1 < (char)piVar1[0x89])))
       ) break;
    iVar3 = iVar3 + 1;
  }
  local_10 = (float)piVar1[0x22] + (float)piVar1[0x7d];
  local_c = (float)piVar1[0x23] + (float)piVar1[0x7e];
  local_8 = (float)piVar1[0x24] + (float)piVar1[0x7f];
  uVar2 = Mod_PointInLeaf(&local_10,DAT_00153668);
  uVar2 = Mod_LeafPVS(uVar2,DAT_00153668);
  Q_memcpy(checkpvs,uVar2,*(int *)(DAT_00153668 + 0x88) + 7 >> 3);
  return iVar3;
}


// PF_particle_I  @ 0006c488
void PF_particle_I(undefined4 param_1,undefined4 param_2,float param_3,float param_4)

{
  SV_StartParticle(param_1,param_2,(int)ROUND(param_3),(int)ROUND(param_4));
  return;
}


// PF_pointcontents_I  @ 0006f4b4
void PF_pointcontents_I(undefined4 param_1)

{
  SV_PointContents(param_1);
  return;
}


// PF_precache_generic_I  @ 0006ed34
int PF_precache_generic_I(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_00186fa0 != 1) {
    iVar2 = 0;
    do {
      if (((&DAT_0018668c)[iVar2] != 0) &&
         (iVar1 = Q_strcmp((&DAT_0018668c)[iVar2],param_1), iVar1 == 0)) {
        return iVar2;
      }
      if (((&DAT_0018668c)[iVar2 + 1] != 0) &&
         (iVar1 = Q_strcmp((&DAT_0018668c)[iVar2 + 1],param_1), iVar1 == 0)) {
        return iVar2 + 1;
      }
      if (((&DAT_0018668c)[iVar2 + 2] != 0) &&
         (iVar1 = Q_strcmp((&DAT_0018668c)[iVar2 + 2],param_1), iVar1 == 0)) {
        return iVar2 + 2;
      }
      if (((&DAT_0018668c)[iVar2 + 3] != 0) &&
         (iVar1 = Q_strcmp((&DAT_0018668c)[iVar2 + 3],param_1), iVar1 == 0)) {
        return iVar2 + 3;
      }
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x200);
    Host_Error("PF_precache_generic_I: \'%s\' Precache can only be done in spawn functions",param_1)
    ;
  }
  PR_CheckEmptyString(param_1);
  piVar3 = &DAT_0018668c;
  iVar2 = 0;
  while( true ) {
    if (*piVar3 == 0) {
      *piVar3 = param_1;
      return iVar2;
    }
    iVar1 = Q_strcasecmp(*piVar3,param_1);
    if (iVar1 == 0) {
      return iVar2;
    }
    if (piVar3[1] == 0) {
      piVar3[1] = param_1;
      return iVar2 + 1;
    }
    iVar1 = Q_strcasecmp(piVar3[1],param_1);
    if (iVar1 == 0) {
      return iVar2 + 1;
    }
    if (piVar3[2] == 0) {
      piVar3[2] = param_1;
      return iVar2 + 2;
    }
    iVar1 = Q_strcasecmp(piVar3[2],param_1);
    if (iVar1 == 0) {
      return iVar2 + 2;
    }
    if (piVar3[3] == 0) {
      piVar3[3] = param_1;
      return iVar2 + 3;
    }
    iVar1 = Q_strcasecmp(piVar3[3],param_1);
    if (iVar1 == 0) break;
    piVar3 = piVar3 + 4;
    iVar2 = iVar2 + 4;
    if (0x1ff < iVar2) {
      Host_Error("PF_precache_generic_I: \'%s\' overflow",param_1);
      return 0;
    }
  }
  return iVar2 + 3;
}


// PF_precache_model_I  @ 0006eb58
int PF_precache_model_I(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (DAT_00186fa0 != 1) {
    iVar4 = 0;
    do {
      if (((&DAT_00183688)[iVar4] != 0) &&
         (iVar1 = Q_stricmp((&DAT_00183688)[iVar4],param_1), iVar1 == 0)) {
        return iVar4;
      }
      if (((&DAT_00183688)[iVar4 + 1] != 0) &&
         (iVar1 = Q_stricmp((&DAT_00183688)[iVar4 + 1],param_1), iVar1 == 0)) {
        return iVar4 + 1;
      }
      if (((&DAT_00183688)[iVar4 + 2] != 0) &&
         (iVar1 = Q_stricmp((&DAT_00183688)[iVar4 + 2],param_1), iVar1 == 0)) {
        return iVar4 + 2;
      }
      if (((&DAT_00183688)[iVar4 + 3] != 0) &&
         (iVar1 = Q_stricmp((&DAT_00183688)[iVar4 + 3],param_1), iVar1 == 0)) {
        return iVar4 + 3;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 < 0x200);
    Host_Error("PF_precache_model_I: \'%s\' Precache can only be done in spawn functions",param_1);
  }
  PR_CheckEmptyString(param_1);
  piVar5 = &DAT_00183688;
  iVar4 = 0;
  while( true ) {
    if (*piVar5 == 0) {
      *piVar5 = param_1;
      uVar2 = Mod_ForName(param_1,1);
      *(undefined4 *)(&DAT_00183e88 + iVar4 * 4) = uVar2;
      return iVar4;
    }
    iVar1 = Q_stricmp(*piVar5,param_1);
    if (iVar1 == 0) {
      return iVar4;
    }
    iVar1 = iVar4 + 1;
    if (piVar5[1] == 0) {
      piVar5[1] = param_1;
      uVar2 = Mod_ForName(param_1,1);
      *(undefined4 *)(&DAT_00183e88 + iVar1 * 4) = uVar2;
      return iVar1;
    }
    iVar3 = Q_stricmp(piVar5[1],param_1);
    if (iVar3 == 0) break;
    piVar5 = piVar5 + 2;
    iVar4 = iVar4 + 2;
    if (0x1ff < iVar4) {
      Host_Error("PF_precache_model_I: \'%s\' overflow",param_1);
      return 0;
    }
  }
  return iVar1;
}


// PF_precache_sound_I  @ 0006dff8
int PF_precache_sound_I(char *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '!')) {
    if (DAT_00186fa0 != 1) {
      iVar3 = 0;
      do {
        if (((&DAT_00185688)[iVar3] != 0) &&
           (iVar1 = Q_stricmp((&DAT_00185688)[iVar3],param_1), iVar1 == 0)) {
          return iVar3;
        }
        if (((&DAT_00185688)[iVar3 + 1] != 0) &&
           (iVar1 = Q_stricmp((&DAT_00185688)[iVar3 + 1],param_1), iVar1 == 0)) {
          return iVar3 + 1;
        }
        if (((&DAT_00185688)[iVar3 + 2] != 0) &&
           (iVar1 = Q_stricmp((&DAT_00185688)[iVar3 + 2],param_1), iVar1 == 0)) {
          return iVar3 + 2;
        }
        if (((&DAT_00185688)[iVar3 + 3] != 0) &&
           (iVar1 = Q_stricmp((&DAT_00185688)[iVar3 + 3],param_1), iVar1 == 0)) {
          return iVar3 + 3;
        }
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0x200);
      Host_Error("PF_precache_sound_I: \'%s\' Precache can only be done in spawn functions",param_1)
      ;
    }
    PR_CheckEmptyString(param_1);
    DAT_00186688 = 0;
    iVar3 = 0;
    do {
      iVar1 = iVar3 * 4;
      iVar4 = iVar3;
      if ((&DAT_00185688)[iVar3] == 0) {
LAB_0006e024:
        *(char **)((int)&DAT_00185688 + iVar1) = param_1;
        return iVar4;
      }
      iVar1 = Q_stricmp((&DAT_00185688)[iVar3],param_1);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar4 = iVar3 + 1;
      iVar1 = iVar4 * 4;
      if ((&DAT_00185688)[iVar4] == 0) goto LAB_0006e024;
      iVar1 = Q_stricmp((&DAT_00185688)[iVar4],param_1);
      if (iVar1 == 0) {
        return iVar4;
      }
      iVar4 = iVar3 + 2;
      iVar1 = iVar4 * 4;
      if ((&DAT_00185688)[iVar4] == 0) goto LAB_0006e024;
      iVar1 = Q_stricmp((&DAT_00185688)[iVar4],param_1);
      if (iVar1 == 0) {
        return iVar4;
      }
      iVar4 = iVar3 + 3;
      iVar1 = iVar4 * 4;
      if ((&DAT_00185688)[iVar4] == 0) goto LAB_0006e024;
      iVar1 = Q_stricmp((&DAT_00185688)[iVar4],param_1);
      if (iVar1 == 0) {
        return iVar4;
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x200);
    pcVar2 = "PF_precache_sound_I: \'%s\' overflow";
  }
  else {
    pcVar2 = "PF_precache_sound_I: \'%s\' do not precache sentence names!";
  }
  Host_Error(pcVar2,param_1);
  return 0;
}


// PF_setmodel_I  @ 0006c160
void PF_setmodel_I(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = 0;
  piVar2 = &DAT_00183688;
  if (DAT_00183688 != 0) {
    do {
      iVar1 = Q_stricmp(*piVar2,param_2);
      if (iVar1 == 0) break;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + 1;
    } while (*piVar2 != 0);
    if (*piVar2 != 0) goto LAB_0006c1c0;
  }
  Host_Error("no precache: %s\n",param_2);
LAB_0006c1c0:
  *(int *)(param_1 + 0x138) = param_2 - pr_strings;
  *(int *)(param_1 + 0x134) = iVar3;
  iVar3 = *(int *)(&DAT_00183e88 + iVar3 * 4);
  if (iVar3 == 0) {
    puVar4 = &vec3_origin;
    puVar5 = puVar4;
  }
  else {
    puVar4 = (undefined4 *)(iVar3 + 0x54);
    puVar5 = (undefined4 *)(iVar3 + 0x60);
  }
  SetMinMaxSize(param_1,puVar4,puVar5,1);
  return;
}


// PF_setorigin_I  @ 0006bf24
void PF_setorigin_I(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x88) = *param_2;
  *(undefined4 *)(param_1 + 0x8c) = param_2[1];
  *(undefined4 *)(param_1 + 0x90) = param_2[2];
  SV_LinkEdict(param_1,0);
  return;
}


// PF_setsize_I  @ 0006c134
void PF_setsize_I(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  SetMinMaxSize(param_1,param_2,param_3,0);
  return;
}


// PF_setspawnparms_I  @ 00070750
void PF_setspawnparms_I(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Host_Error("Entity is not a client");
  }
  return;
}


// PF_setview_I  @ 0006f9c8
void PF_setview_I(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Host_Error("PF_setview_I: not a client");
  }
  iVar1 = DAT_001ab4e4 + -0x5054 + iVar1 * 0x5054;
  if (*(int *)(iVar1 + 0x2460) == 0) {
    *(undefined4 *)(iVar1 + 0x4ae8) = param_2;
    MSG_WriteByte(iVar1 + 0x74,5);
    uVar2 = NUM_FOR_EDICT(param_2);
    MSG_WriteShort(iVar1 + 0x74,uVar2);
  }
  return;
}


// PF_sound_I  @ 0006c6fc
void PF_sound_I(undefined4 param_1,uint param_2,undefined4 param_3,float param_4,float param_5,
               undefined4 param_6,uint param_7)

{
  if ((param_4 < 0.0) || (255.0 < param_4)) {
    Sys_Error("EMIT_SOUND: volume = %i",(double)param_4);
  }
  if ((param_5 < 0.0) || (4.0 < param_5)) {
    Sys_Error("EMIT_SOUND: attenuation = %f",(double)param_5);
  }
  if (7 < param_2) {
    Sys_Error("EMIT_SOUND: channel = %i",param_2);
  }
  if (0xff < param_7) {
    Sys_Error("EMIT_SOUND: pitch = %i",param_7);
  }
  SV_StartSound(0,param_1,param_2,param_3,(int)ROUND(param_4 * 255.0),param_5,param_6,param_7);
  return;
}


// PF_sprint  @ 0006c2ac
void PF_sprint(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 1) || (DAT_001ab4e8 < param_2)) {
    Con_Printf("tried to sprint to a non-client\n");
  }
  else {
    iVar1 = DAT_001ab4e4 + -0x4fe0 + param_2 * 0x5054;
    MSG_WriteChar(iVar1,8);
    MSG_WriteString(iVar1,param_1);
  }
  return;
}


// PF_stuffcmd_I  @ 0006d8ac
void PF_stuffcmd_I(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = NUM_FOR_EDICT(param_1);
  vsprintf(szOut_140,param_2,&stack0x0000000c);
  if ((iVar2 < 1) || (DAT_001ab4e8 < iVar2)) {
    Con_Printf("\n!!!\n\nStuffCmd:  Some entity tried to stuff \'%s\' to console buffer of entity %i when maxclients was set to %i, ignoring\n\n"
               ,szOut_140,iVar2,DAT_001ab4e8);
  }
  else {
    iVar3 = ValidCmd(szOut_140);
    uVar1 = host_client;
    if (iVar3 == 0) {
      Con_Printf("Tried to stuff bad command %s\n",szOut_140);
    }
    else {
      host_client = DAT_001ab4e4 + -0x5054 + iVar2 * 0x5054;
      Host_ClientCommands(&DAT_000a91f8,szOut_140);
      host_client = uVar1;
    }
  }
  return;
}


// PF_traceline_DLL  @ 0006c848
void PF_traceline_DLL(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     int *param_5)

{
  if (param_4 == 0) {
    param_4 = DAT_00186f94;
  }
  PF_traceline_Shared(param_1,param_2,param_3,param_4);
  *param_5 = (int)ROUND(DAT_00152b8c);
  param_5[1] = (int)ROUND(DAT_00152b90);
  param_5[2] = (int)ROUND(DAT_00152bb8);
  param_5[3] = (int)ROUND(DAT_00152bbc);
  param_5[4] = DAT_00152b94;
  param_5[8] = DAT_00152bb0;
  param_5[0xc] = DAT_00152bb4;
  param_5[5] = DAT_00152b98;
  param_5[6] = DAT_00152b9c;
  param_5[7] = DAT_00152ba0;
  param_5[9] = DAT_00152ba4;
  param_5[10] = DAT_00152ba8;
  param_5[0xb] = DAT_00152bac;
  param_5[0xd] = DAT_00152bc0;
  return;
}


// PF_traceline_Shared  @ 0006c7f0
void PF_traceline_Shared(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  undefined1 local_3c [56];
  
  SV_Move(local_3c,param_1,&vec3_origin,&vec3_origin,param_2,param_3,param_4,0);
  DAT_00152bc4 = 0;
  SV_SetGlobalTrace(local_3c);
  return;
}


// PF_vectoangles_I  @ 0006c464
void PF_vectoangles_I(undefined4 param_1,undefined4 param_2)

{
  VectorAngles(param_1,param_2);
  return;
}


// PF_vectoyaw_I  @ 0006c3e8
longdouble PF_vectoyaw_I(float *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)0;
  lVar1 = (longdouble)param_1[1];
  if (((byte)((byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) != 0x40) ||
     ((byte)((byte)((ushort)((ushort)(NAN((longdouble)*param_1) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)*param_1 == lVar2) << 0xe) >> 8)) != 0x40)) {
    lVar2 = (longdouble)fpatan(lVar1,(longdouble)*param_1);
    lVar2 = (longdouble)(int)ROUND(lVar2 * (longdouble)57.29577951308232);
    lVar1 = (longdouble)0;
    if (0x3f < (byte)((lVar1 < lVar2 |
                       (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar1 == lVar2) << 0xe) >> 8)) - 1)) {
      lVar2 = (longdouble)360.0 + lVar2;
    }
  }
  return lVar2;
}


// PF_walkmove_I  @ 0006f1ec
undefined4 PF_walkmove_I(int param_1,float param_2,float param_3,int param_4)

{
  undefined4 uVar1;
  longdouble lVar2;
  longdouble lVar3;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  if ((*(uint *)(param_1 + 0x224) & 0x203) == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = (longdouble)((param_2 * 3.1415927 + param_2 * 3.1415927) * 0.0027777778);
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


