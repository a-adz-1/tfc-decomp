// ED_Alloc  @ 0008d938
int * ED_Alloc(void)

{
  float fVar1;
  int *piVar2;
  int local_8;
  
  local_8 = DAT_00524288;
  do {
    local_8 = local_8 + 1;
    if (DAT_003a78b0 <= local_8) {
      if (DAT_003a78b4 <= local_8) {
        if (DAT_003a78b4 == 0) {
          Sys_Error("ED_Alloc: No edicts yet");
        }
        Sys_Error("ED_Alloc: no free edicts");
      }
      DAT_003a78b0 = DAT_003a78b0 + 1;
      piVar2 = (int *)(DAT_003a78b8 + local_8 * 0x324);
      ED_ClearEdict(piVar2);
      return piVar2;
    }
    piVar2 = (int *)(DAT_003a78b8 + local_8 * 0x324);
  } while ((*piVar2 == 0) ||
          ((2.0 <= (float)piVar2[0x1e] &&
           (fVar1 = (float)DAT_0036bc6c - (float)piVar2[0x1e],
           (byte)(0.5 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.5) << 0xe) >> 8)) != 1))));
  ED_ClearEdict(piVar2);
  return piVar2;
}


// ED_ClearEdict  @ 0008d8dc
void ED_ClearEdict(undefined4 *param_1)

{
  Q_memset(param_1 + 0x20,0,0x2a4,0x8d8e8);
  *param_1 = 0;
  ReleaseEntityDLLFields(param_1);
  InitEntityDLLFields(param_1);
  return;
}


// ED_Count  @ 0008dc14
void ED_Count(void)

{
  int *piVar1;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  for (local_8 = 0; local_8 < DAT_003a78b0; local_8 = local_8 + 1) {
    piVar1 = (int *)(DAT_003a78b8 + local_8 * 0x324);
    if (*piVar1 == 0) {
      local_10 = local_10 + 1;
      if (piVar1[99] != 0) {
        local_18 = local_18 + 1;
      }
      if (piVar1[0x4e] != 0) {
        local_14 = local_14 + 1;
      }
      if (piVar1[0x62] == 4) {
        local_1c = local_1c + 1;
      }
    }
  }
  Con_Printf("num_edicts:%3i\n",DAT_003a78b0);
  Con_Printf("active    :%3i\n",local_10);
  Con_Printf("view      :%3i\n",local_14);
  Con_Printf("touch     :%3i\n",local_18);
  Con_Printf(FUN_000e6ba4,local_1c);
  return;
}


// ED_Free  @ 0008dab4
void ED_Free(int *param_1)

{
  if (*param_1 == 0) {
    SV_UnlinkEdict(param_1);
    FreeEntPrivateData(param_1);
    *param_1 = 1;
    param_1[1] = param_1[1] + 1;
    param_1[0x89] = 0;
    param_1[0x4e] = 0;
    param_1[0x7b] = 0;
    param_1[0x4d] = 0;
    param_1[0x8a] = 0;
    param_1[100] = 0;
    param_1[0x6c] = 0;
    param_1[0x71] = 0;
    param_1[0x67] = 0;
    param_1[0x22] = vec3_origin;
    param_1[0x23] = DAT_000f1be0;
    param_1[0x24] = DAT_000f1be4;
    param_1[0x34] = vec3_origin;
    param_1[0x35] = DAT_000f1be0;
    param_1[0x36] = DAT_000f1be4;
    param_1[0x61] = -0x40800000;
    param_1[99] = 0;
    param_1[0x1e] = (int)(float)DAT_0036bc6c;
  }
  return;
}


// ED_LoadFromFile  @ 0008e410
void ED_LoadFromFile(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_c = 0;
  gGlobalVariables = (float)DAT_0036bc6c;
  while (iVar2 = COM_Parse(param_1), iVar2 != 0) {
    if (com_token != '{') {
      Sys_Error("ED_LoadFromFile: found %s when expecting {",&com_token);
    }
    piVar1 = DAT_003a78b8;
    if (local_8 == (int *)0x0) {
      local_8 = DAT_003a78b8;
      ReleaseEntityDLLFields(DAT_003a78b8);
      InitEntityDLLFields(piVar1);
    }
    else {
      local_8 = (int *)ED_Alloc();
    }
    param_1 = ED_ParseEdict(iVar2,local_8);
    if (*local_8 == 0) {
      if (((byte)(0.0 < (float)deathmatch._12_4_ |
                  (byte)((ushort)((ushort)NAN((float)deathmatch._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)deathmatch._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)
         || ((local_8[0x88] & 0x800U) == 0)) {
        if (local_8[0x20] == 0) {
          Con_Printf("No classname for:\n");
          ED_Free(local_8);
        }
        else {
          iVar2 = (*DAT_0036af44)(local_8);
          if ((iVar2 < 0) || ((local_8[0x89] & 0x40000000U) != 0)) {
            ED_Free(local_8);
          }
        }
      }
      else {
        ED_Free(local_8);
        local_c = local_c + 1;
      }
    }
  }
  Con_DPrintf("%i entities inhibited\n",local_c);
  return;
}


// ED_NewString  @ 0008dd60
undefined1 * ED_NewString(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int local_10;
  undefined1 *local_c;
  
  iVar1 = Q_strlen(param_1);
  puVar2 = (undefined1 *)Hunk_Alloc(iVar1 + 1);
  local_c = puVar2;
  for (local_10 = 0; local_10 < iVar1 + 1; local_10 = local_10 + 1) {
    if ((*(char *)(param_1 + local_10) == '\\') && (local_10 < iVar1)) {
      local_10 = local_10 + 1;
      if (*(char *)(param_1 + local_10) == 'n') {
        *local_c = 10;
      }
      else {
        *local_c = 0x5c;
      }
    }
    else {
      *local_c = *(undefined1 *)(param_1 + local_10);
    }
    local_c = local_c + 1;
  }
  return puVar2;
}


// ED_ParseEdict  @ 0008de20
int ED_ParseEdict(undefined4 param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 local_32c [260];
  char local_228 [259];
  undefined1 local_125;
  char *local_124;
  char *local_120;
  undefined1 *local_11c;
  undefined4 local_118;
  char *local_114;
  code *local_110;
  undefined4 local_10c;
  char local_108 [255];
  undefined1 local_9;
  int local_8;
  
  if (param_2 != DAT_003a78b8) {
    Q_memset();
  }
  InitEntityDLLFields();
  SuckOutClassname();
  local_8 = 0;
  local_114 = (char *)(param_2[0x20] + pr_strings);
  local_110 = (code *)GetEntityInit();
  if (local_110 == (code *)0x0) {
    local_114 = "custom";
    local_110 = (code *)GetEntityInit();
    if (local_110 == (code *)0x0) {
      Con_DPrintf();
    }
    else {
      (*local_110)();
      local_124 = local_114;
      local_120 = "customclass";
      local_11c = (undefined1 *)(param_2[0x20] + pr_strings);
      local_118 = 0;
      (*DAT_0036af58)();
      local_8 = 1;
    }
  }
  else {
    (*local_110)();
    local_8 = 1;
  }
  while (iVar2 = COM_Parse(), com_token != '}') {
    if (iVar2 == 0) {
      Sys_Error();
    }
    Q_strncpy();
    local_9 = 0;
    for (local_10c = Q_strlen(); (local_10c != 0 && (local_108[local_10c + -1] == ' '));
        local_10c = local_10c + -1) {
      local_108[local_10c + -1] = '\0';
    }
    iVar2 = COM_Parse();
    if (iVar2 == 0) {
      Sys_Error();
    }
    if (com_token == '}') {
      Sys_Error();
    }
    iVar2 = COM_CheckParm();
    if ((((iVar2 != 0) && (DAT_00524288 < 2)) &&
        (iVar2 = strcmp(local_114,"trigger_changelevel"), iVar2 == 0)) &&
       ((iVar2 = strcmp(local_108,"map"), iVar2 == 0 &&
        (iVar2 = strcmp(&com_token,&DAT_0036bcc8), iVar2 != 0)))) {
      puVar4 = local_32c;
      COM_FileBase();
      snprintf(local_228,0x104,"reslists\\%s\\%s.lst",local_32c,&com_token,puVar4);
      local_125 = 0;
      FS_HintResourceNeed();
    }
    if ((pr_strings + param_2[0x20] == 0) || (iVar2 = Q_strcmp(), iVar2 != 0)) {
      pcVar5 = "angle";
      iVar2 = Q_strcmp();
      if (iVar2 == 0) {
        lVar3 = (longdouble)Q_atof();
        fVar1 = (float)lVar3;
        if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
          snprintf(&com_token,0x400,"%f %f %f",(double)(float)param_2[0x34],(double)fVar1,
                   (double)(float)param_2[0x36],pcVar5);
        }
        else if ((int)ROUND(fVar1) == -1) {
          snprintf(&com_token,0x400,"-90 0 0");
        }
        else {
          snprintf(&com_token,0x400,"90 0 0");
        }
        Q_strcpy();
      }
      local_124 = (char *)(param_2[0x20] + pr_strings);
      local_120 = local_108;
      local_11c = &com_token;
      local_118 = 0;
      (*DAT_0036af58)();
    }
  }
  if (local_8 == 0) {
    *param_2 = 1;
    param_2[1] = param_2[1] + 1;
  }
  return iVar2;
}


