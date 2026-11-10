// Cvar_CmdInit  @ 0005ca74
void Cvar_CmdInit(void)

{
  Cmd_AddCommand("cvarlist",Cmd_CvarList_f);
  return;
}


// Cvar_Command  @ 0005c1c0
void Cvar_Command(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = Cmd_Argv(0);
  iVar2 = Cvar_IsMultipleTokens(uVar1);
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)Cvar_FindVar(iVar2);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_0005c330();
      return;
    }
    Con_Printf("\"%s\" is \"%s\"\n",*puVar3,puVar3[1]);
    FUN_0005c330();
    return;
  }
  uVar1 = Cmd_Argv(0);
  puVar3 = (undefined4 *)Cvar_FindVar(uVar1);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_0005c330();
    return;
  }
  iVar2 = Cmd_Argc();
  if (iVar2 == 1) {
    Con_Printf("\"%s\" is \"%s\"\n",*puVar3,puVar3[1]);
    FUN_0005c330();
    return;
  }
  if (((((puVar3[2] & 0x40) != 0) && (cls != 0)) && (cls != 1)) && (1 < (int)cl._1717472_4_)) {
    Con_Printf("Can\'t set %s in multiplayer\n",*puVar3);
    FUN_0005c330();
    return;
  }
  uVar1 = Cmd_Argv(1);
  Cvar_Set(*puVar3,uVar1);
  FUN_0005c330();
  return;
}


// Cvar_CompleteVariable  @ 0005b7a4
undefined4 Cvar_CompleteVariable(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 local_110;
  int local_10c;
  undefined4 local_108;
  undefined1 local_104 [255];
  undefined1 local_5;
  
  local_110 = 0;
  Q_strncpy(local_104,param_1,0xff);
  local_5 = 0;
  local_10c = Q_strlen(local_104);
  if (local_10c == 0) {
    local_110 = 0;
  }
  else {
    for (; local_104[local_10c + -1] == ' '; local_10c = local_10c + -1) {
      local_104[local_10c + -1] = 0;
    }
    iVar1 = Q_stricmp(local_104,lastpartial_24);
    if ((iVar1 == 0) &&
       (local_108 = (undefined4 *)Cvar_FindVar(local_104), local_108 != (undefined4 *)0x0)) {
      if (param_2 == 1) {
        local_108 = (undefined4 *)local_108[4];
      }
      else {
        local_108 = (undefined4 *)Cvar_FindPrevVar(*local_108);
      }
      if (local_108 != (undefined4 *)0x0) {
        Q_strncpy(lastpartial_24,*local_108,0xff);
        lastpartial_24[0xff] = 0;
        return *local_108;
      }
    }
    for (local_108 = cvar_vars; local_108 != (undefined4 *)0x0;
        local_108 = (undefined4 *)local_108[4]) {
      iVar1 = Q_strncmp(local_104,*local_108,local_10c);
      if (iVar1 == 0) {
        iVar1 = Q_strlen(*local_108);
        if (iVar1 == local_10c) {
          Q_strncpy(lastpartial_24,*local_108,0xff);
          lastpartial_24[0xff] = 0;
          return *local_108;
        }
        local_110 = *local_108;
        break;
      }
    }
    if (local_108 != (undefined4 *)0x0) {
      Q_strncpy(lastpartial_24,*local_108,0xff);
      lastpartial_24[0xff] = 0;
    }
  }
  return local_110;
}


// Cvar_CountServerVariables  @ 0005c9ac
int Cvar_CountServerVariables(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = cvar_vars; local_c != 0; local_c = *(int *)(local_c + 0x10)) {
    if ((*(uint *)(local_c + 8) & 4) != 0) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


// Cvar_DirectSet  @ 0005ba10
void Cvar_DirectSet(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  char *local_414;
  char *local_410;
  char local_40c [1024];
  char *local_c;
  int local_8;
  
  local_c = param_2;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (char *)0x0)) {
    if ((*(byte *)(param_1 + 2) & 0x80) != 0) {
      local_40c[0] = '\0';
      local_410 = param_2;
      local_414 = local_40c;
      while (*local_410 != '\0') {
        if ((*local_410 < ' ') || (*local_410 == '\x7f')) {
          local_410 = local_410 + 1;
        }
        else {
          *local_414 = *local_410;
          local_410 = local_410 + 1;
          local_414 = local_414 + 1;
        }
      }
      *local_414 = '\0';
      iVar1 = Q_strlen(local_40c);
      if (iVar1 == 0) {
        Q_strcpy(local_40c,"empty");
      }
      local_c = local_40c;
    }
    local_8 = Q_strcmp(param_1[1],local_c);
    if ((param_1[2] & 2) != 0) {
      if (cls == 0) {
        uVar2 = Info_Serverinfo(*param_1,local_c,0x200);
        Info_SetValueForKey(uVar2);
        uVar2 = Info_Serverinfo();
        SV_BroadcastCommand("fullserverinfo \"%s\"\n",uVar2);
      }
      if (((cls != 0) && (Info_SetValueForKey(&DAT_002fdcf4,*param_1,local_c,0x100), local_8 != 0))
         && (2 < cls)) {
        MSG_WriteByte(&DAT_002f9ffc,3);
        uVar2 = va("setinfo \"%s\" \"%s\"\n",*param_1,local_c);
        SZ_Print(&DAT_002f9ffc,uVar2);
      }
    }
    if ((((param_1[2] & 4) != 0) && (local_8 != 0)) && ((param_1[2] & 0x100) == 0)) {
      if ((param_1[2] & 0x20) == 0) {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",*param_1,local_c);
        SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",*param_1,local_c);
      }
      else {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",*param_1,"***PROTECTED***");
        SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",*param_1,"***PROTECTED***");
      }
    }
    Z_Free(param_1[1]);
    iVar1 = Q_strlen(local_c);
    uVar2 = Z_Malloc(iVar1 + 1);
    param_1[1] = uVar2;
    Q_strcpy(param_1[1],local_c);
    lVar3 = (longdouble)Q_atof(param_1[1]);
    param_1[3] = (float)lVar3;
  }
  return;
}


// Cvar_FindPrevVar  @ 0005b644
int Cvar_FindPrevVar(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = cvar_vars;
  while( true ) {
    if (*(int *)(local_8 + 0x10) == 0) {
      return 0;
    }
    iVar1 = Q_stricmp(param_1,**(undefined4 **)(local_8 + 0x10));
    if (iVar1 == 0) break;
    local_8 = *(int *)(local_8 + 0x10);
  }
  return local_8;
}


// Cvar_FindVar  @ 0005b5c4
undefined4 * Cvar_FindVar(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_8;
  
  (*(code *)g_engdstAddrs._288_4_)(&param_1);
  local_8 = cvar_vars;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = Q_stricmp(param_1,*local_8);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)local_8[4];
  }
  return local_8;
}


// Cvar_Init  @ 0005b598
void Cvar_Init(void)

{
  return;
}


// Cvar_IsMultipleTokens  @ 0005c0f8
undefined1 * Cvar_IsMultipleTokens(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 local_10;
  int local_c;
  
  local_c = 0;
  local_10 = param_1;
  firstToken_43 = 0;
  while( true ) {
    local_10 = COM_Parse(local_10);
    iVar1 = Q_strlen(&com_token);
    if (iVar1 < 1) break;
    if (local_c == 0) {
      Q_strncpy(&firstToken_43,&com_token,0x203);
      DAT_00115063 = 0;
    }
    local_c = local_c + 1;
  }
  if (local_c == 1) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    puVar2 = &firstToken_43;
  }
  return puVar2;
}


// Cvar_RegisterVariable  @ 0005be88
void Cvar_RegisterVariable(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  undefined *local_28 [4];
  undefined *local_18;
  undefined *local_14;
  undefined **local_10;
  undefined **local_c;
  undefined4 local_8;
  
  iVar1 = Cvar_FindVar(*param_1);
  if (iVar1 == 0) {
    iVar1 = Cmd_Exists(*param_1);
    if (iVar1 == 0) {
      local_8 = param_1[1];
      iVar1 = Q_strlen(param_1[1]);
      uVar2 = Z_Malloc(iVar1 + 1);
      param_1[1] = uVar2;
      Q_strcpy(param_1[1],local_8);
      lVar3 = (longdouble)Q_atof(param_1[1]);
      param_1[3] = (float)lVar3;
      local_10 = local_28;
      local_18 = cvar_vars;
      local_28[0] = &DAT_000e0468;
      local_c = local_10;
      while( true ) {
        if (local_10[4] == (undefined *)0x0) {
          FUN_0005bffc();
          return;
        }
        iVar1 = strcasecmp(*(char **)local_10[4],(char *)*param_1);
        if (0 < iVar1) break;
        local_10 = (undefined **)local_10[4];
      }
      local_14 = local_10[4];
      local_10[4] = (undefined *)param_1;
      param_1[4] = local_14;
      cvar_vars = local_c[4];
    }
    else {
      Con_Printf("Cvar_RegisterVariable: %s is a command\n",*param_1);
    }
  }
  else {
    Con_Printf("Can\'t register variable %s, already defined\n",*param_1);
  }
  return;
}


// Cvar_RemoveHudCvars  @ 0005c024
void Cvar_RemoveHudCvars(void)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = cvar_vars;
  while (local_c != 0) {
    iVar1 = *(int *)(local_c + 0x10);
    if ((*(uint *)(local_c + 8) & 0x10) == 0) {
      *(int *)(local_c + 0x10) = local_8;
      local_8 = local_c;
      local_c = iVar1;
    }
    else {
      Z_Free(*(undefined4 *)(local_c + 4));
      Z_Free(local_c);
      local_c = iVar1;
    }
  }
  local_c = local_8;
  cvar_vars = 0;
  while (local_c != 0) {
    iVar1 = *(int *)(local_c + 0x10);
    *(int *)(local_c + 0x10) = cvar_vars;
    cvar_vars = local_c;
    local_c = iVar1;
  }
  return;
}


// Cvar_Set  @ 0005bd40
void Cvar_Set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Cvar_FindVar(param_1);
  if (iVar1 == 0) {
    Con_DPrintf("Cvar_Set: variable %s not found\n",param_1);
  }
  else {
    Cvar_DirectSet(iVar1,param_2);
  }
  return;
}


// Cvar_SetValue  @ 0005bda4
void Cvar_SetValue(undefined4 param_1,float param_2)

{
  undefined4 *puVar1;
  char local_24 [32];
  
  puVar1 = &param_2;
  (*(code *)g_engdstAddrs._148_4_)();
  if (1e-06 <= ABS(param_2 - (float)(int)ROUND(param_2))) {
    snprintf(local_24,0x20,"%f",(double)param_2,puVar1);
  }
  else {
    snprintf(local_24,0x20,"%d",(int)ROUND(param_2));
  }
  Cvar_Set();
  return;
}


// Cvar_Shutdown  @ 0005b5a0
void Cvar_Shutdown(void)

{
  cvar_vars = 0;
  return;
}


// Cvar_UnlinkExternals  @ 0005ca08
void Cvar_UnlinkExternals(void)

{
  int *local_c;
  int local_8;
  
  local_c = &cvar_vars;
  local_8 = cvar_vars;
  while (*local_c != 0) {
    if ((*(uint *)(local_8 + 8) & 8) == 0) {
      local_c = (int *)(local_8 + 0x10);
    }
    else {
      *local_c = *(int *)(local_8 + 0x10);
    }
    local_8 = *(int *)(local_8 + 0x10);
  }
  FUN_0005ca6c();
  return;
}


// Cvar_VariableInt  @ 0005b700
undefined4 Cvar_VariableInt(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Cvar_FindVar(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Q_atoi(*(undefined4 *)(iVar1 + 4));
  }
  return uVar2;
}


// Cvar_VariableString  @ 0005b754
undefined * Cvar_VariableString(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = Cvar_FindVar(param_1);
  puVar2 = cvar_null_string;
  if (iVar1 != 0) {
    puVar2 = *(undefined **)(iVar1 + 4);
  }
  return puVar2;
}


// Cvar_VariableValue  @ 0005b6b0
longdouble Cvar_VariableValue(undefined4 param_1)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = Cvar_FindVar(param_1);
  if (iVar1 == 0) {
    lVar2 = (longdouble)0;
  }
  else {
    lVar2 = (longdouble)Q_atof(*(undefined4 *)(iVar1 + 4));
  }
  return lVar2;
}


// Cvar_WriteVariables  @ 0005c338
void Cvar_WriteVariables(undefined4 param_1)

{
  undefined4 *local_8;
  
  for (local_8 = cvar_vars; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)local_8[4]) {
    if ((local_8[2] & 1) != 0) {
      FS_FPrintf(param_1,"%s \"%s\"\n",*local_8,local_8[1]);
    }
  }
  return;
}


