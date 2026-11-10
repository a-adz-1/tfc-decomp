// DELTA_AddDefinition  @ 000639cc
void DELTA_AddDefinition(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *local_8;
  
  local_8 = g_defs;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)Mem_ZeroMalloc(0x10);
      *puVar2 = g_defs;
      g_defs = puVar2;
      uVar3 = Mem_Strdup(param_1);
      puVar2[1] = uVar3;
      puVar2[3] = param_2;
      puVar2[2] = param_3;
      return;
    }
    iVar1 = Q_stricmp(param_1,local_8[1]);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)*local_8;
  }
  local_8[3] = param_2;
  local_8[2] = param_3;
  return;
}


// DELTA_AddEncoder  @ 00062f50
void DELTA_AddEncoder(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)Mem_ZeroMalloc(0xc);
  uVar2 = Mem_Strdup(param_1);
  puVar1[1] = uVar2;
  puVar1[2] = param_2;
  *puVar1 = g_encoders;
  g_encoders = puVar1;
  return;
}


// DELTA_BuildFromLinks  @ 00063158
void DELTA_BuildFromLinks(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int local_1c;
  undefined4 *local_14;
  
  local_1c = 0;
  Mem_ZeroMalloc(0x30);
  DELTA_ReverseLinks(param_1);
  iVar2 = DELTA_CountLinks(*param_1);
  iVar2 = Mem_ZeroMalloc(iVar2 * 0x44);
  for (local_14 = (undefined4 *)*param_1; local_14 != (undefined4 *)0x0;
      local_14 = (undefined4 *)*local_14) {
    iVar1 = local_1c * 0x44;
    local_1c = local_1c + 1;
    Q_memcpy(iVar2 + iVar1,local_14[1],0x44);
    Mem_Free(local_14[1]);
    local_14[1] = 0;
  }
  FUN_00063244();
  return;
}


// DELTA_CheckDelta  @ 00062594
void DELTA_CheckDelta(void)

{
  FUN_000625a0();
  return;
}


// DELTA_ClearDefinitions  @ 00063a80
void DELTA_ClearDefinitions(void)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  local_8 = g_defs;
  while (local_8 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_8;
    Mem_Free(local_8[1]);
    Mem_Free(local_8);
    local_8 = puVar1;
  }
  g_defs = (undefined4 *)0x0;
  return;
}


// DELTA_ClearEncoders  @ 00062fb0
void DELTA_ClearEncoders(void)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  local_8 = g_encoders;
  while (local_8 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_8;
    Mem_Free(local_8[1]);
    Mem_Free(local_8);
    local_8 = puVar1;
  }
  g_encoders = (undefined4 *)0x0;
  return;
}


// DELTA_ClearFlags  @ 00061728
void DELTA_ClearFlags(int param_1)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < *(int *)(param_1 + 4); local_8 = local_8 + 1) {
    *(undefined2 *)(*(int *)(param_1 + 0x2c) + local_8 * 0x44 + 0x38) = 0;
  }
  return;
}


// DELTA_ClearLinks  @ 00063104
void DELTA_ClearLinks(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  local_8 = (undefined4 *)*param_1;
  while (local_8 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_8;
    Mem_Free(local_8);
    local_8 = puVar1;
  }
  *param_1 = 0;
  return;
}


// DELTA_ClearRegistrations  @ 000641ac
void DELTA_ClearRegistrations(void)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  local_8 = g_deltaregistry;
  while (local_8 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_8;
    Mem_Free(local_8[1]);
    if (local_8[2] != 0) {
      DELTA_FreeDescription(local_8 + 2);
    }
    Mem_Free(local_8);
    local_8 = puVar1;
  }
  g_deltaregistry = (undefined4 *)0x0;
  return;
}


// DELTA_ClearStats  @ 00064294
void DELTA_ClearStats(int param_1)

{
  undefined4 local_8;
  
  if (param_1 != 0) {
    for (local_8 = 0; local_8 < *(int *)(param_1 + 4); local_8 = local_8 + 1) {
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x3c + local_8 * 0x44) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x40 + local_8 * 0x44) = 0;
    }
  }
  return;
}


// DELTA_ClearStats_f  @ 0006430c
void DELTA_ClearStats_f(void)

{
  undefined4 *local_8;
  
  Con_Printf("Clearing delta stats\n");
  for (local_8 = g_deltaregistry; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
    DELTA_ClearStats(local_8[2]);
  }
  return;
}


// DELTA_CountLinks  @ 00063080
int DELTA_CountLinks(undefined4 *param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  for (local_8 = param_1; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
    local_c = local_c + 1;
  }
  return local_c;
}


// DELTA_CountSendFields  @ 00061b00
int DELTA_CountSendFields(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < *(int *)(param_1 + 4); local_8 = local_8 + 1) {
    iVar2 = *(int *)(param_1 + 0x2c) + local_8 * 0x44;
    if ((*(ushort *)(iVar2 + 0x38) & 1) != 0) {
      piVar1 = (int *)(iVar2 + 0x3c);
      *piVar1 = *piVar1 + 1;
      local_c = local_c + 1;
    }
  }
  return local_c;
}


// DELTA_DumpStats_f  @ 00064458
void DELTA_DumpStats_f(void)

{
  undefined4 *local_8;
  
  Con_Printf("Delta Stats\n");
  for (local_8 = g_deltaregistry; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
    DELTA_PrintStats(local_8[1],local_8[2]);
  }
  return;
}


// DELTA_FindDefinition  @ 00063aec
undefined4 DELTA_FindDefinition(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *local_8;
  
  *param_2 = 0;
  local_8 = g_defs;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return 0;
    }
    iVar1 = Q_stricmp(param_1,local_8[1]);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)*local_8;
  }
  *param_2 = local_8[2];
  return local_8[3];
}


// DELTA_FindField  @ 000614a4
int DELTA_FindField(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(param_1 + 4) <= local_8) {
      Con_Printf("DELTA_FindField:  Warning, couldn\'t find %s\n",param_2);
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x2c) + local_8 * 0x44;
    iVar1 = Q_strcasecmp(iVar2 + 4,param_2);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return iVar2;
}


// DELTA_FindFieldIndex  @ 00061544
int DELTA_FindFieldIndex(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)(param_1 + 4) <= local_8) {
      Con_Printf("DELTA_FindFieldIndex:  Warning, couldn\'t find %s\n",param_2);
      return -1;
    }
    iVar1 = Q_strcasecmp(*(int *)(param_1 + 0x2c) + local_8 * 0x44 + 4,param_2);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


// DELTA_FindOffset  @ 00063280
undefined4 DELTA_FindOffset(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (param_1 <= local_8) {
      Sys_Error("Couldn\'t find offset for %s!!!\n",param_3);
      return 0;
    }
    iVar1 = Q_stricmp(param_3,*(undefined4 *)(param_2 + local_8 * 8));
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(param_2 + 4 + local_8 * 8);
}


// DELTA_FreeDescription  @ 00063968
void DELTA_FreeDescription(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (*(int *)*param_1 != 0) {
      Mem_Free(*(undefined4 *)(*param_1 + 0x2c));
    }
    Mem_Free(*param_1);
    *param_1 = 0;
  }
  return;
}


// DELTA_Init  @ 000644bc
void DELTA_Init(void)

{
  Cmd_AddCommand("delta_stats",DELTA_DumpStats_f);
  Cmd_AddCommand("delta_clear",DELTA_ClearStats_f);
  DELTA_AddDefinition("clientdata_t",g_ClientDataDefinition,0x38);
  DELTA_AddDefinition("weapon_data_t",g_WeaponDataDefinition,0x16);
  DELTA_AddDefinition("usercmd_t",g_UsercmdDataDefinition,0x10);
  DELTA_AddDefinition("entity_state_t",g_EntityDataDefinition,0x57);
  DELTA_AddDefinition("entity_state_player_t",g_EntityDataDefinition,0x57);
  DELTA_AddDefinition("custom_entity_state_t",g_EntityDataDefinition,0x57);
  DELTA_AddDefinition("event_t",g_EventDataDefinition,0xe);
  return;
}


// DELTA_Load  @ 000640b0
undefined4 DELTA_Load(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = COM_LoadFile(param_3,5,0);
  if (iVar1 == 0) {
    Sys_Error("DELTA_Load:  Couldn\'t load file %s\n",param_3);
    uVar2 = 0;
  }
  else {
    uVar2 = DELTA_ParseDescription(param_1,param_2,iVar1);
    if (iVar1 != 0) {
      Mem_Free(iVar1);
    }
  }
  return uVar2;
}


// DELTA_LookupEncoder  @ 0006301c
undefined4 DELTA_LookupEncoder(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = g_encoders;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return 0;
    }
    iVar1 = Q_stricmp(local_8[1],param_1);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)*local_8;
  }
  return local_8[2];
}


// DELTA_LookupRegistration  @ 00064230
undefined4 * DELTA_LookupRegistration(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = g_deltaregistry;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = Q_stricmp(local_8[1],param_1);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)*local_8;
  }
  return local_8 + 2;
}


// DELTA_MarkSendFields  @ 00061b78
void DELTA_MarkSendFields(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *local_18;
  char *local_14;
  
  if (*(int *)(param_3 + 4) < 1) {
    FUN_00061f00();
    return;
  }
  puVar1 = *(uint **)(param_3 + 0x2c);
  uVar5 = *puVar1 & 0x7fffffff;
  if (uVar5 != 8) {
    if (uVar5 < 9) {
      if (uVar5 == 2) {
        iVar3 = Q_memcmp(puVar1[9] + param_1,puVar1[9] + param_2,2);
        if (iVar3 != 0) {
          *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
        }
        FUN_00061ef8();
        return;
      }
      if (uVar5 < 3) {
        if (uVar5 == 1) {
          if (*(char *)(puVar1[9] + param_1) != *(char *)(puVar1[9] + param_2)) {
            *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
          }
          FUN_00061ef8();
          return;
        }
        FUN_00061edc();
        return;
      }
      if (uVar5 != 4) {
        FUN_00061edc();
        return;
      }
    }
    else {
      if (uVar5 == 0x20) {
        if ((int)ROUND(*(float *)(puVar1[9] + param_1) * 100.0) !=
            (int)ROUND(*(float *)(puVar1[9] + param_2) * 100.0)) {
          *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
        }
        FUN_00061ef8();
        return;
      }
      if (0x20 < uVar5) {
        if (uVar5 == 0x40) {
          if ((int)ROUND(*(float *)(puVar1[9] + param_1) * 1000.0) !=
              (int)ROUND(*(float *)(puVar1[9] + param_2) * 1000.0)) {
            *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
          }
          FUN_00061ef8();
          return;
        }
        if (uVar5 != 0x80) {
          FUN_00061edc();
          return;
        }
        local_14 = (char *)(puVar1[9] + param_1);
        local_18 = (char *)(puVar1[9] + param_2);
        bVar2 = false;
        while( true ) {
          if ((*local_14 == '\0') || (*local_18 == '\0')) goto LAB_00061eb0;
          iVar3 = tolower((int)*local_14);
          iVar4 = tolower((int)*local_18);
          if (iVar3 != iVar4) break;
          local_14 = local_14 + 1;
          local_18 = local_18 + 1;
        }
        *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
        bVar2 = true;
LAB_00061eb0:
        if ((!bVar2) && ((*local_14 != '\0' || (*local_18 != '\0')))) {
          *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
        }
        FUN_00061ef8();
        return;
      }
      if (uVar5 != 0x10) {
        FUN_00061edc();
        return;
      }
    }
  }
  iVar3 = Q_memcmp(puVar1[9] + param_1,puVar1[9] + param_2,4);
  if (iVar3 != 0) {
    *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
  }
  FUN_00061ef8();
  return;
}


// DELTA_ParseDelta  @ 0006270c
void DELTA_ParseDelta(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *local_24;
  undefined1 local_14 [8];
  int local_c;
  
  MSG_CurrentBit();
  Q_memset(local_14,0,8);
  iVar2 = MSG_ReadBits(3);
  local_24 = local_14;
  for (local_c = 0; local_c < iVar2; local_c = local_c + 1) {
    uVar1 = MSG_ReadBits(8);
    *local_24 = uVar1;
    local_24 = local_24 + 1;
  }
  FUN_00062788();
  return;
}


// DELTA_ParseDescription  @ 00063d28
undefined4 DELTA_ParseDescription(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_54;
  undefined1 local_50 [31];
  undefined1 local_31;
  undefined1 local_30 [31];
  undefined1 local_11;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0;
  local_54 = 0;
  local_30[0] = 0;
  if (param_2 == (int *)0x0) {
    Sys_Error("DELTA_ParseDescription with no delta_description_t\n");
    uVar1 = 0;
  }
  else {
    *param_2 = 0;
    if (param_3 == 0) {
      Sys_Error("DELTA_ParseDescription with no data stream\n");
      uVar1 = 0;
    }
    else {
      local_8 = param_3;
      while( true ) {
        local_8 = COM_Parse(local_8);
        iVar2 = Q_strlen(&com_token);
        if (iVar2 < 1) break;
        iVar2 = Q_stricmp(&com_token,param_1);
        if (iVar2 == 0) {
          local_10 = DELTA_FindDefinition(&com_token,&local_54);
          if (local_10 == 0) {
            Sys_Error("DELTA_ParseDescription:  Unknown data type:  %s\n",&com_token);
            return 0;
          }
          local_8 = COM_Parse(local_8);
          iVar2 = Q_strlen(&com_token);
          if (iVar2 < 1) {
            Sys_Error("DELTA_ParseDescription:  Unknown encoder :  %s\nValid values:\nnone\ngamedll funcname\nclientdll funcname\n"
                      ,&com_token);
            return 0;
          }
          iVar2 = Q_stricmp(&com_token,&DAT_000e1ca7);
          if (iVar2 != 0) {
            Q_strncpy(local_50,&com_token,0x1f);
            local_31 = 0;
            local_8 = COM_Parse(local_8);
            iVar2 = Q_strlen(&com_token);
            if (iVar2 < 1) {
              Sys_Error("DELTA_ParseDescription:  Expecting encoder\n");
              return 0;
            }
            Q_strncpy(local_30,&com_token,0x1f);
            local_11 = 0;
          }
          while( true ) {
            local_8 = COM_Parse(local_8);
            iVar2 = Q_strlen(&com_token);
            if ((iVar2 < 1) || (iVar2 = Q_stricmp(&com_token,&DAT_000e1b66), iVar2 == 0)) break;
            iVar2 = Q_stricmp(&com_token,&DAT_000e1cec);
            if (iVar2 != 0) {
              Con_Printf("DELTA_ParseDescription:  Expecting {, got %s\n",&com_token);
              return 0;
            }
            iVar2 = DELTA_ParseOneField(&local_8,&local_c,local_54,local_10);
            if (iVar2 == 0) {
              return 0;
            }
          }
        }
        else {
          DELTA_SkipDescription(&local_8);
        }
      }
      iVar2 = DELTA_BuildFromLinks(&local_c);
      *param_2 = iVar2;
      iVar2 = Q_strlen(local_30);
      if (0 < iVar2) {
        Q_strncpy(*param_2 + 8,local_30,0x1f);
        *(undefined1 *)(*param_2 + 0x27) = 0;
        *(undefined4 *)(*param_2 + 0x28) = 0;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}


// DELTA_ParseField  @ 000635f8
void DELTA_ParseField(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  double dVar5;
  
  bVar1 = false;
  iVar2 = Q_stricmp(&com_token,"DEFINE_DELTA");
  if (iVar2 != 0) {
    iVar2 = Q_stricmp(&com_token,"DEFINE_DELTA_POST");
    if (iVar2 != 0) {
      Sys_Error("DELTA_ParseField:  Expecting DEFINE_*, got %s\n",&com_token);
      FUN_00063960();
      return;
    }
    bVar1 = true;
  }
  uVar3 = COM_Parse(*param_4);
  *param_4 = uVar3;
  iVar2 = Q_stricmp(&com_token,&UNK_000e1a8f);
  if (iVar2 != 0) {
    Sys_Error("DELTA_ParseField:  Expecting (, got %s\n",&com_token);
    FUN_00063960();
    return;
  }
  uVar3 = COM_Parse(*param_4);
  *param_4 = uVar3;
  iVar2 = Q_strlen(&com_token);
  if (iVar2 < 1) {
    Sys_Error("DELTA_ParseField:  Expecting fieldname\n");
    FUN_00063960();
    return;
  }
  Q_strncpy(*(int *)(param_3 + 4) + 4,&com_token,0x1f);
  *(undefined1 *)(*(int *)(param_3 + 4) + 0x23) = 0;
  uVar3 = DELTA_FindOffset(param_1,param_2,&com_token);
  *(undefined4 *)(*(int *)(param_3 + 4) + 0x24) = uVar3;
  uVar3 = COM_Parse(*param_4);
  *param_4 = uVar3;
  iVar2 = DELTA_ParseType(*(undefined4 *)(param_3 + 4),param_4);
  if (iVar2 != 0) {
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    *(undefined2 *)(*(int *)(param_3 + 4) + 0x28) = 1;
    uVar3 = Q_atoi(&com_token);
    *(undefined4 *)(*(int *)(param_3 + 4) + 0x2c) = uVar3;
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    lVar4 = (longdouble)Q_atof(&com_token);
    *(float *)(*(int *)(param_3 + 4) + 0x30) = (float)lVar4;
    if (bVar1) {
      uVar3 = COM_Parse(*param_4);
      *param_4 = uVar3;
      uVar3 = COM_Parse(*param_4);
      *param_4 = uVar3;
      dVar5 = atof(&com_token);
      *(float *)(*(int *)(param_3 + 4) + 0x34) = (float)dVar5;
    }
    else {
      *(undefined4 *)(*(int *)(param_3 + 4) + 0x34) = 0x3f800000;
    }
    uVar3 = COM_Parse(*param_4);
    *param_4 = uVar3;
    iVar2 = Q_stricmp(&com_token,&UNK_000e1b08);
    if (iVar2 == 0) {
      uVar3 = COM_Parse(*param_4);
      *param_4 = uVar3;
      iVar2 = Q_stricmp(&com_token,&UNK_000e198f);
      if (iVar2 != 0) {
        COM_UngetToken();
      }
      FUN_00063960();
      return;
    }
    Con_Printf("DELTA_ParseField:  Expecting ), got %s\n",&com_token);
    FUN_00063960();
    return;
  }
  FUN_00063960();
  return;
}


// DELTA_ParseOneField  @ 00063c14
undefined4
DELTA_ParseOneField(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  while( true ) {
    iVar1 = Q_stricmp(&com_token,&DAT_000e1b66);
    if (iVar1 == 0) {
      COM_UngetToken();
      return 1;
    }
    uVar2 = COM_Parse(*param_1);
    *param_1 = uVar2;
    iVar1 = Q_strlen(&com_token);
    if (iVar1 < 1) break;
    Q_memset(local_10,0,8);
    local_c = Mem_ZeroMalloc(0x44);
    iVar1 = DELTA_ParseField(param_3,param_4,local_10,param_1);
    if (iVar1 == 0) {
      return 0;
    }
    local_8 = (undefined4 *)Mem_ZeroMalloc(8);
    local_8[1] = local_c;
    *local_8 = *param_2;
    *param_2 = local_8;
  }
  return 1;
}


// DELTA_ParseType  @ 00063310
void DELTA_ParseType(uint *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  while( true ) {
    do {
      uVar1 = COM_Parse(*param_2);
      *param_2 = uVar1;
      iVar2 = Q_strlen(&com_token);
      if (iVar2 < 1) {
        Con_Printf("DELTA_ParseField:  Expecting fieldtype info\n");
        FUN_000635f0();
        return;
      }
      iVar2 = Q_stricmp(&com_token,&UNK_000e198d);
    } while (iVar2 == 0);
    iVar2 = Q_stricmp(&com_token,&UNK_000e198f);
    if (iVar2 == 0) {
      FUN_000635e8();
      return;
    }
    iVar2 = Q_stricmp(&com_token,"DT_SIGNED");
    if (iVar2 != 0) break;
    *param_1 = *param_1 | 0x80000000;
  }
  iVar2 = Q_stricmp(&com_token,"DT_BYTE");
  if (iVar2 == 0) {
    *param_1 = *param_1 | 1;
    FUN_000635e0();
    return;
  }
  iVar2 = Q_stricmp(&com_token,"DT_SHORT");
  if (iVar2 == 0) {
    *param_1 = *param_1 | 2;
    FUN_000635e0();
    return;
  }
  iVar2 = Q_stricmp(&com_token,"DT_FLOAT");
  if (iVar2 == 0) {
    *param_1 = *param_1 | 4;
    FUN_000635e0();
    return;
  }
  iVar2 = Q_stricmp(&com_token,"DT_INTEGER");
  if (iVar2 == 0) {
    *param_1 = *param_1 | 8;
    FUN_000635e0();
    return;
  }
  iVar2 = Q_stricmp(&com_token,"DT_ANGLE");
  if (iVar2 == 0) {
    *param_1 = *param_1 | 0x10;
    FUN_000635e0();
    return;
  }
  iVar2 = Q_stricmp(&com_token,"DT_TIMEWINDOW_8");
  if (iVar2 != 0) {
    iVar2 = Q_stricmp(&com_token,"DT_TIMEWINDOW_BIG");
    if (iVar2 == 0) {
      *param_1 = *param_1 | 0x40;
      FUN_000635e0();
      return;
    }
    iVar2 = Q_stricmp(&com_token,"DT_STRING");
    if (iVar2 != 0) {
      Sys_Error("DELTA_ParseField:  Unknown type or type flag %s\n",&com_token);
      FUN_000635f0();
      return;
    }
    *param_1 = *param_1 | 0x80;
    FUN_000635e0();
    return;
  }
  *param_1 = *param_1 | 0x20;
  FUN_000635e0();
  return;
}


// DELTA_PrintStats  @ 00064368
void DELTA_PrintStats(undefined4 param_1,int param_2)

{
  int local_8;
  
  if (param_2 != 0) {
    Con_Printf("Stats for \'%s\'\n",param_1);
    for (local_8 = 0; local_8 < *(int *)(param_2 + 4); local_8 = local_8 + 1) {
      Con_Printf("  %02i % 10s:  s % 5i r % 5i\n",local_8 + 1,
                 *(int *)(param_2 + 0x2c) + local_8 * 0x44 + 4,
                 *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x3c + local_8 * 0x44),
                 *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x40 + local_8 * 0x44));
    }
    Con_Printf(&DAT_000e1da8,param_1);
  }
  return;
}


// DELTA_RegisterDescription  @ 0006414c
void DELTA_RegisterDescription(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)Mem_ZeroMalloc(0xc);
  *puVar1 = g_deltaregistry;
  g_deltaregistry = puVar1;
  uVar2 = Mem_Strdup(param_1);
  puVar1[1] = uVar2;
  puVar1[2] = 0;
  return;
}


// DELTA_ReverseLinks  @ 000630b8
void DELTA_ReverseLinks(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_8;
  
  local_10 = (undefined4 *)0x0;
  local_8 = (undefined4 *)*param_1;
  while (local_8 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_8;
    *local_8 = local_10;
    local_10 = local_8;
    local_8 = puVar1;
  }
  *param_1 = local_10;
  return;
}


// DELTA_SetField  @ 000615e8
void DELTA_SetField(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DELTA_FindField(param_1,param_2);
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x38) = *(ushort *)(iVar1 + 0x38) | 1;
  }
  return;
}


// DELTA_SetFieldByIndex  @ 00061680
void DELTA_SetFieldByIndex(int param_1,int param_2)

{
  *(ushort *)(*(int *)(param_1 + 0x2c) + 0x38 + param_2 * 0x44) =
       *(ushort *)(*(int *)(param_1 + 0x2c) + 0x38 + param_2 * 0x44) | 1;
  return;
}


// DELTA_SetSendFlagBits  @ 00061f2c
void DELTA_SetSendFlagBits(int param_1,int param_2,int *param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  Q_memset(param_2,0,8,0x61f3a);
  local_c = *(int *)(param_1 + 4);
  local_10 = -1;
  while (local_c = local_c + -1, -1 < local_c) {
    if ((*(ushort *)(*(int *)(param_1 + 0x2c) + local_c * 0x44 + 0x38) & 1) != 0) {
      if (local_10 == -1) {
        local_10 = local_c;
      }
      *(uint *)(param_2 + (uint)(0x1f < local_c) * 4) =
           1 << ((byte)local_c & 0x1f) | *(uint *)(param_2 + (uint)(0x1f < local_c) * 4);
    }
  }
  *param_3 = (local_10 >> 3) + 1;
  return;
}


// DELTA_Shutdown  @ 000645ec
void DELTA_Shutdown(void)

{
  DELTA_ClearEncoders();
  DELTA_ClearDefinitions();
  DELTA_ClearRegistrations();
  return;
}


// DELTA_SkipDescription  @ 00063b68
void DELTA_SkipDescription(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = COM_Parse(*param_1);
  *param_1 = uVar1;
  do {
    uVar1 = COM_Parse(*param_1);
    *param_1 = uVar1;
    iVar2 = Q_strlen(&com_token);
    if (iVar2 < 1) {
      Sys_Error("Error during description skip");
      return;
    }
    iVar2 = Q_stricmp(&com_token,&DAT_000e1b66);
  } while (iVar2 != 0);
  return;
}


// DELTA_TestDelta  @ 0006177c
void DELTA_TestDelta(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *local_18;
  char *local_14;
  
  if (*(int *)(param_3 + 4) < 1) {
    FUN_00061ad4();
    return;
  }
  puVar1 = *(uint **)(param_3 + 0x2c);
  uVar5 = *puVar1 & 0x7fffffff;
  if (uVar5 != 8) {
    if (uVar5 < 9) {
      if (uVar5 == 2) {
        FUN_00061acc();
        return;
      }
      if (uVar5 < 3) {
        if (uVar5 != 1) {
          FUN_00061ab0();
          return;
        }
        FUN_00061acc();
        return;
      }
      if (uVar5 != 4) {
        FUN_00061ab0();
        return;
      }
    }
    else {
      if (uVar5 == 0x20) {
        FUN_00061acc();
        return;
      }
      if (0x20 < uVar5) {
        if (uVar5 == 0x40) {
          FUN_00061acc();
          return;
        }
        if (uVar5 != 0x80) {
          FUN_00061ab0();
          return;
        }
        local_14 = (char *)(puVar1[9] + param_1);
        bVar2 = false;
        for (local_18 = (char *)(puVar1[9] + param_2); *local_18 != '\0'; local_18 = local_18 + 1) {
          if (!bVar2) {
            iVar3 = tolower((int)*local_14);
            iVar4 = tolower((int)*local_18);
            if (iVar3 != iVar4) {
              *(ushort *)(puVar1 + 0xe) = (ushort)puVar1[0xe] | 1;
              bVar2 = true;
            }
          }
          local_14 = local_14 + 1;
        }
        FUN_00061a9c();
        return;
      }
      if (uVar5 != 0x10) {
        FUN_00061ab0();
        return;
      }
    }
  }
  FUN_00061acc();
  return;
}


// DELTA_UnsetField  @ 00061634
void DELTA_UnsetField(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DELTA_FindField(param_1,param_2);
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x38) = *(ushort *)(iVar1 + 0x38) & 0xfffe;
  }
  return;
}


// DELTA_UnsetFieldByIndex  @ 000616d4
void DELTA_UnsetFieldByIndex(int param_1,int param_2)

{
  *(ushort *)(*(int *)(param_1 + 0x2c) + 0x38 + param_2 * 0x44) =
       *(ushort *)(*(int *)(param_1 + 0x2c) + 0x38 + param_2 * 0x44) & 0xfffe;
  return;
}


// DELTA_WriteDelta  @ 00062600
void DELTA_WriteDelta(void)

{
  FUN_0006260d();
  return;
}


// DELTA_WriteMarkedFields  @ 0006202c
void DELTA_WriteMarkedFields(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  ulonglong local_3c;
  char *pcStack_24;
  
  if (*(int *)(param_3 + 4) < 1) {
    FUN_00062588();
    return;
  }
  puVar1 = *(uint **)(param_3 + 0x2c);
  if ((puVar1[0xe] & 1) == 0) {
    FUN_00062580();
    return;
  }
  uVar3 = *puVar1 & 0x7fffffff;
  uVar2 = *puVar1 & 0x80000000;
  if (uVar3 == 8) {
    if (uVar2 == 0) {
      local_3c = (ulonglong)*(uint *)(puVar1[9] + param_2);
      local_3c._0_4_ = (undefined4)(longlong)ROUND((float)local_3c * (float)puVar1[0xc]);
      MSG_WriteBits((undefined4)local_3c,puVar1[0xb]);
    }
    else {
      MSG_WriteSBits((int)ROUND((float)*(int *)(puVar1[9] + param_2) * (float)puVar1[0xc]),
                     puVar1[0xb]);
    }
    FUN_00062580();
    return;
  }
  if (uVar3 < 9) {
    if (uVar3 == 2) {
      if (uVar2 == 0) {
        MSG_WriteBits((int)ROUND((float)*(ushort *)(puVar1[9] + param_2) * (float)puVar1[0xc]) &
                      0xffff,puVar1[0xb]);
      }
      else {
        MSG_WriteSBits((int)(short)(int)ROUND((float)*(short *)(puVar1[9] + param_2) *
                                              (float)puVar1[0xc]),puVar1[0xb]);
      }
      FUN_00062580();
      return;
    }
    if (2 < uVar3) {
      if (uVar3 == 4) {
        local_3c._0_4_ =
             (undefined4)(longlong)ROUND(*(float *)(puVar1[9] + param_2) * (float)puVar1[0xc]);
        if (uVar2 == 0) {
          MSG_WriteBits((undefined4)local_3c,puVar1[0xb]);
        }
        else {
          MSG_WriteSBits((undefined4)local_3c,puVar1[0xb]);
        }
        FUN_00062580();
        return;
      }
      FUN_00062568();
      return;
    }
    if (uVar3 == 1) {
      if (uVar2 == 0) {
        MSG_WriteBits((int)ROUND((float)*(byte *)(puVar1[9] + param_2) * (float)puVar1[0xc]) & 0xff,
                      puVar1[0xb]);
      }
      else {
        MSG_WriteSBits((int)(char)(int)ROUND((float)(short)*(char *)(puVar1[9] + param_2) *
                                             (float)puVar1[0xc]),puVar1[0xb]);
      }
      FUN_00062580();
      return;
    }
    FUN_00062568();
    return;
  }
  if (uVar3 == 0x20) {
    MSG_WriteSBits((int)ROUND(DAT_0036bc6c * 100.0) -
                   (int)ROUND(*(float *)(puVar1[9] + param_2) * 100.0),8);
    FUN_00062580();
    return;
  }
  if (uVar3 < 0x21) {
    if (uVar3 == 0x10) {
      MSG_WriteBitAngle(*(undefined4 *)(puVar1[9] + param_2),puVar1[0xb]);
      FUN_00062580();
      return;
    }
    FUN_00062568();
    return;
  }
  if (uVar3 == 0x40) {
    MSG_WriteSBits((int)ROUND((float)puVar1[0xc] * (float)DAT_0036bc6c) -
                   (int)ROUND(*(float *)(puVar1[9] + param_2) * (float)puVar1[0xc]),puVar1[0xb]);
    FUN_00062580();
    return;
  }
  if (uVar3 == 0x80) {
    for (pcStack_24 = (char *)(puVar1[9] + param_2);
        (pcStack_24 != (char *)0x0 && (*pcStack_24 != '\0')); pcStack_24 = pcStack_24 + 1) {
      MSG_WriteBits((int)*pcStack_24,8);
    }
    MSG_WriteBits(0,8);
    FUN_00062580();
    return;
  }
  FUN_00062568();
  return;
}


