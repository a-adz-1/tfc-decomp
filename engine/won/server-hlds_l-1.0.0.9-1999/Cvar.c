// Cvar_CmdInit  @ 08053cd0
void Cvar_CmdInit(void)

{
  Cmd_AddCommand("cvarlist",Cmd_CvarList_f);
  return;
}


// Cvar_Command  @ 080537f0
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
    else if ((((*(byte *)(puVar2 + 2) & 0x40) == 0) || (cls < 2)) || ((int)cl._138436_4_ < 2)) {
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


// Cvar_CompleteVariable  @ 08053480
undefined4 Cvar_CompleteVariable(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar2 = Q_strlen(param_1);
  puVar1 = cvar_vars;
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[4]) {
      iVar3 = Q_strncmp(param_1,*puVar1,iVar2);
      if (iVar3 == 0) {
        iVar3 = Q_strlen(*puVar1);
        if (iVar3 == iVar2) {
          return *puVar1;
        }
        uVar4 = *puVar1;
      }
    }
  }
  return uVar4;
}


// Cvar_CountServerVariables  @ 08053c60
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


// Cvar_FindVar  @ 080533a0
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


// Cvar_RegisterVariable  @ 08053700
void Cvar_RegisterVariable(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  
  iVar2 = Cvar_FindVar(*param_1);
  if (iVar2 == 0) {
    iVar2 = Cmd_Exists(*param_1);
    if (iVar2 == 0) {
      uVar1 = param_1[1];
      iVar2 = Q_strlen(uVar1);
      uVar3 = Z_Malloc(iVar2 + 1);
      param_1[1] = uVar3;
      Q_strcpy(uVar3,uVar1);
      lVar4 = (longdouble)Q_atof(param_1[1]);
      param_1[3] = (float)lVar4;
      param_1[4] = cvar_vars;
      cvar_vars = param_1;
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


// Cvar_RemoveHudCvars  @ 08053790
void Cvar_RemoveHudCvars(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (cvar_vars != 0) {
    iVar3 = 0;
    iVar2 = cvar_vars;
    do {
      iVar1 = *(int *)(iVar2 + 0x10);
      if ((*(byte *)(iVar2 + 8) & 0x10) == 0) {
        *(int *)(iVar2 + 0x10) = iVar3;
        iVar3 = iVar2;
      }
      else {
        Z_Free(*(undefined4 *)(iVar2 + 4));
        Z_Free(iVar2);
      }
      iVar2 = iVar1;
    } while (iVar1 != 0);
  }
  cvar_vars = iVar3;
  return;
}


// Cvar_Set  @ 08053500
void Cvar_Set(undefined4 param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  longdouble lVar7;
  uint local_404;
  undefined2 local_400;
  
  iVar3 = Cvar_FindVar(param_1);
  if (iVar3 == 0) {
    Con_DPrintf("Cvar_Set: variable %s not found\n",param_1);
    return;
  }
  if (*(char *)(iVar3 + 8) < '\0') {
    local_404 = local_404 & 0xffffff00;
    puVar5 = &local_404;
    cVar1 = (char)*param_2;
    while (cVar1 != '\0') {
      if ('\x1f' < (char)*param_2) {
        *(char *)puVar5 = (char)*param_2;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      param_2 = (uint *)((int)param_2 + 1);
      cVar1 = *(char *)param_2;
    }
    *(char *)puVar5 = '\0';
    iVar6 = -1;
    puVar5 = &local_404;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      uVar2 = *puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
    } while ((char)uVar2 != '\0');
    if (iVar6 == -2) {
      local_404._0_1_ = 'e';
      local_404._1_1_ = 'm';
      local_404._2_1_ = 'p';
      local_404._3_1_ = 't';
      local_400 = 0x79;
    }
    param_2 = &local_404;
  }
  iVar6 = Q_strcmp(*(undefined4 *)(iVar3 + 4),param_2);
  if ((*(byte *)(iVar3 + 8) & 2) != 0) {
    if (cls == 0) {
      uVar4 = Info_Serverinfo(param_1,param_2,0x200);
      Info_SetValueForKey(uVar4);
      uVar4 = Info_Serverinfo();
      SV_BroadcastCommand("fullserverinfo \"%s\"\n",uVar4);
      if (cls == 0) goto LAB_08053651;
    }
    Info_SetValueForKey(&DAT_081b9acc,param_1,param_2,0xc4);
    if ((iVar6 != 0) && (2 < cls)) {
      MSG_WriteByte(&DAT_081b5328,4);
      uVar4 = va("setinfo \"%s\" \"%s\"\n",param_1,param_2);
      SZ_Print(&DAT_081b5328,uVar4);
    }
  }
LAB_08053651:
  if (((*(byte *)(iVar3 + 8) & 4) != 0) && (iVar6 != 0)) {
    Log_Printf("\"%s\" = \"%s\"\n",param_1,param_2);
    SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",param_1,param_2);
  }
  Z_Free(*(undefined4 *)(iVar3 + 4));
  iVar6 = Q_strlen(param_2);
  uVar4 = Z_Malloc(iVar6 + 1);
  *(undefined4 *)(iVar3 + 4) = uVar4;
  Q_strcpy(*(undefined4 *)(iVar3 + 4),param_2);
  lVar7 = (longdouble)Q_atof(*(undefined4 *)(iVar3 + 4));
  *(float *)(iVar3 + 0xc) = (float)lVar7;
  return;
}


// Cvar_SetValue  @ 080536c0
void Cvar_SetValue(undefined4 param_1,float param_2)

{
  char local_24 [32];
  
  sprintf(local_24,"%f",(double)param_2);
  Cvar_Set(param_1,local_24);
  return;
}


// Cvar_UnlinkExternals  @ 08053c90
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


// Cvar_VariableInt  @ 08053420
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


// Cvar_VariableString  @ 08053450
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


// Cvar_VariableValue  @ 080533f0
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


// Cvar_WriteVariables  @ 08053880
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


