// Cvar_CmdInit  @ 0004ed78
void Cvar_CmdInit(void)

{
  Cmd_AddCommand("cvarlist",Cmd_CvarList_f);
  return;
}


// Cvar_Command  @ 0004e87c
undefined4 Cvar_Command(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = Cmd_Argv(0);
  puVar2 = (undefined4 *)Cvar_FindVar(uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar3 = Cmd_Argc();
    if (iVar3 == 1) {
      Con_Printf("\"%s\" is \"%s\"\n",*puVar2,puVar2[1]);
    }
    else if ((((*(byte *)(puVar2 + 2) & 0x40) == 0) || (cls < 2)) || ((int)cl._1356812_4_ < 2)) {
      uVar1 = Cmd_Argv(1);
      Cvar_Set(*puVar2,uVar1);
    }
    else {
      Con_Printf("Can\'t set %s in multiplayer\n",*puVar2);
    }
    uVar1 = 1;
  }
  return uVar1;
}


// Cvar_CompleteVariable  @ 0004e34c
undefined4 Cvar_CompleteVariable(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_108;
  undefined1 local_104 [256];
  
  local_108 = 0;
  Q_strcpy(local_104,param_1);
  iVar3 = Q_strlen(local_104);
  if (iVar3 == 0) {
    local_108 = 0;
  }
  else {
    cVar1 = local_104[iVar3 + -1];
    iVar4 = iVar3 + -1;
    while (iVar2 = iVar4, cVar1 == ' ') {
      local_104[iVar2] = 0;
      iVar4 = iVar2 + -1;
      iVar3 = iVar2;
      cVar1 = local_104[iVar2 + -1];
    }
    iVar4 = Q_stricmp(local_104,lastpartial_12);
    if ((iVar4 == 0) &&
       (puVar5 = (undefined4 *)Cvar_FindVar(local_104), puVar5 != (undefined4 *)0x0)) {
      if (param_2 == 1) {
        puVar5 = (undefined4 *)puVar5[4];
      }
      else {
        puVar5 = (undefined4 *)Cvar_FindPrevVar(*puVar5);
      }
      if (puVar5 != (undefined4 *)0x0) {
LAB_0004e40d:
        Q_strcpy(lastpartial_12,*puVar5);
        return *puVar5;
      }
    }
    puVar5 = cvar_vars;
    if (cvar_vars != (undefined4 *)0x0) {
      do {
        iVar4 = Q_strncmp(local_104,*puVar5,iVar3);
        if (iVar4 == 0) {
          iVar4 = Q_strlen(*puVar5);
          if (iVar4 == iVar3) goto LAB_0004e40d;
          local_108 = *puVar5;
          break;
        }
        puVar5 = (undefined4 *)puVar5[4];
      } while (puVar5 != (undefined4 *)0x0);
      if (puVar5 != (undefined4 *)0x0) {
        Q_strcpy(lastpartial_12,*puVar5);
      }
    }
  }
  return local_108;
}


// Cvar_CountServerVariables  @ 0004ed00
int Cvar_CountServerVariables(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = cvar_vars; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    if ((*(byte *)(iVar1 + 8) & 4) != 0) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}


// Cvar_DirectSet  @ 0004e48c
void Cvar_DirectSet(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  longdouble lVar5;
  char local_404 [1024];
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (param_2 == (char *)0x0) {
    return;
  }
  pcVar4 = param_2;
  if (*(char *)(param_1 + 2) < '\0') {
    local_404[0] = '\0';
    pcVar4 = local_404;
    pcVar3 = pcVar4;
    while (*param_2 != '\0') {
      if (*param_2 < ' ') {
        param_2 = param_2 + 1;
      }
      else {
        *pcVar3 = *param_2;
        param_2 = param_2 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
    *pcVar3 = '\0';
    iVar1 = Q_strlen(pcVar4);
    if (iVar1 == 0) {
      Q_strcpy(pcVar4,"empty");
    }
  }
  iVar1 = Q_strcmp(param_1[1],pcVar4);
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    if (cls == 0) {
      uVar2 = Info_Serverinfo(*param_1,pcVar4,0x200);
      Info_SetValueForKey(uVar2);
      uVar2 = Info_Serverinfo();
      SV_BroadcastCommand("fullserverinfo \"%s\"\n",uVar2);
      if (cls == 0) goto LAB_0004e5c7;
    }
    Info_SetValueForKey(&DAT_00385294,*param_1,pcVar4,0x100);
    if ((iVar1 != 0) && (2 < cls)) {
      MSG_WriteByte(&DAT_00382558,3);
      uVar2 = va("setinfo \"%s\" \"%s\"\n",*param_1,pcVar4);
      SZ_Print(&DAT_00382558,uVar2);
    }
  }
LAB_0004e5c7:
  if ((((param_1[2] & 4) != 0) && (iVar1 != 0)) && ((param_1[2] & 0x100) == 0)) {
    Log_Printf("\"%s\" = \"%s\"\n",*param_1,pcVar4);
    SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",*param_1,pcVar4);
  }
  Z_Free(param_1[1]);
  iVar1 = Q_strlen(pcVar4);
  uVar2 = Z_Malloc(iVar1 + 1);
  param_1[1] = uVar2;
  Q_strcpy(uVar2,pcVar4);
  lVar5 = (longdouble)Q_atof(param_1[1]);
  param_1[3] = (float)lVar5;
  return;
}


// Cvar_FindPrevVar  @ 0004e25c
int Cvar_FindPrevVar(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = cvar_vars;
  while( true ) {
    if (*(undefined4 **)(iVar2 + 0x10) == (undefined4 *)0x0) {
      return 0;
    }
    iVar1 = Q_strcmp(param_1,**(undefined4 **)(iVar2 + 0x10));
    if (iVar1 == 0) break;
    iVar2 = *(int *)(iVar2 + 0x10);
  }
  return iVar2;
}


// Cvar_FindVar  @ 0004e210
undefined4 * Cvar_FindVar(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = cvar_vars;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar2 = Q_strcmp(param_1,*puVar1);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)puVar1[4];
  }
  return puVar1;
}


// Cvar_RegisterVariable  @ 0004e6d8
void Cvar_RegisterVariable(undefined4 *param_1)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  longdouble lVar6;
  undefined4 uVar7;
  undefined *local_18 [4];
  undefined *local_8;
  
  iVar3 = Cvar_FindVar(*param_1);
  if (iVar3 == 0) {
    iVar3 = Cmd_Exists(*param_1);
    if (iVar3 == 0) {
      uVar7 = param_1[1];
      iVar3 = Q_strlen(uVar7);
      uVar5 = Z_Malloc(iVar3 + 1);
      param_1[1] = uVar5;
      Q_strcpy(uVar5,uVar7);
      lVar6 = (longdouble)Q_atof(param_1[1]);
      ppuVar1 = local_18;
      param_1[3] = (float)lVar6;
      local_8 = cvar_vars;
      local_18[0] = &DAT_000a4ca8;
      puVar2 = cvar_vars;
      while( true ) {
        if (puVar2 == (undefined *)0x0) {
          ppuVar1[4] = (undefined *)param_1;
          param_1[4] = 0;
          cvar_vars = local_8;
          return;
        }
        iVar3 = Q_stricmp(*(undefined4 *)ppuVar1[4],*param_1);
        if (0 < iVar3) break;
        ppuVar1 = (undefined **)ppuVar1[4];
        puVar2 = ppuVar1[4];
      }
      puVar2 = ppuVar1[4];
      ppuVar1[4] = (undefined *)param_1;
      param_1[4] = puVar2;
      cvar_vars = local_8;
      return;
    }
    uVar7 = *param_1;
    pcVar4 = (char *)FUN_000a4c80;
  }
  else {
    uVar7 = *param_1;
    pcVar4 = "Can\'t register variable %s, already defined\n";
  }
  Con_Printf(pcVar4,uVar7);
  return;
}


// Cvar_RemoveHudCvars  @ 0004e7e8
void Cvar_RemoveHudCvars(void)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = cvar_vars;
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x10);
    if ((*(byte *)(iVar2 + 8) & 0x10) == 0) {
      *(int *)(iVar2 + 0x10) = local_8;
      local_8 = iVar2;
    }
    else {
      Z_Free(*(undefined4 *)(iVar2 + 4));
      Z_Free(iVar2);
    }
  }
  cvar_vars = 0;
  while (iVar1 = local_8, iVar1 != 0) {
    local_8 = *(int *)(iVar1 + 0x10);
    *(int *)(iVar1 + 0x10) = cvar_vars;
    cvar_vars = iVar1;
  }
  return;
}


// Cvar_Set  @ 0004e64c
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


// Cvar_SetValue  @ 0004e694
void Cvar_SetValue(undefined4 param_1,float param_2)

{
  char local_24 [32];
  
  sprintf(local_24,"%f",(double)param_2);
  Cvar_Set(param_1,local_24);
  return;
}


// Cvar_UnlinkExternals  @ 0004ed38
void Cvar_UnlinkExternals(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &cvar_vars;
  iVar1 = cvar_vars;
  iVar2 = cvar_vars;
  while (iVar2 != 0) {
    if ((*(byte *)(iVar1 + 8) & 8) == 0) {
      piVar3 = (int *)(iVar1 + 0x10);
    }
    else {
      *piVar3 = *(int *)(iVar1 + 0x10);
    }
    iVar1 = *(int *)(iVar1 + 0x10);
    iVar2 = *piVar3;
  }
  return;
}


// Cvar_VariableInt  @ 0004e2e0
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


// Cvar_VariableString  @ 0004e318
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


// Cvar_VariableValue  @ 0004e2a8
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


// Cvar_WriteVariables  @ 0004e91c
void Cvar_WriteVariables(FILE *param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = cvar_vars; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[4]) {
    if ((*(byte *)(puVar1 + 2) & 1) != 0) {
      fprintf(param_1,"%s \"%s\"\n",*puVar1,puVar1[1]);
    }
  }
  return;
}


