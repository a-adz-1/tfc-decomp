// Cmd_AddCommand  @ 0804d070
void Cmd_AddCommand(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (host_initialized != 0) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar1 = (char *)Cvar_VariableString(param_1);
  puVar3 = cmd_functions;
  if (*pcVar1 == '\0') {
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      iVar2 = Q_strcmp(param_1,puVar3[1]);
      if (iVar2 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n",param_1);
        return;
      }
    }
    puVar3 = (undefined4 *)Hunk_Alloc(0x10);
    puVar3[1] = param_1;
    puVar3[2] = param_2;
    puVar3[3] = 0;
    *puVar3 = cmd_functions;
    cmd_functions = puVar3;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n",param_1);
  }
  return;
}


// Cmd_AddHUDCommand  @ 0804d120
void Cmd_AddHUDCommand(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  
  pcVar1 = (char *)Cvar_VariableString(param_1);
  puVar3 = cmd_functions;
  if (*pcVar1 == '\0') {
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      iVar2 = Q_strcmp(param_1,puVar3[1]);
      if (iVar2 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n",param_1);
        return;
      }
    }
    puVar3 = malloc(0x10);
    puVar3[1] = param_1;
    puVar3[2] = param_2;
    puVar3[3] = 1;
    *puVar3 = cmd_functions;
    cmd_functions = puVar3;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n",param_1);
  }
  return;
}


// Cmd_Alias_f  @ 0804cd10
void Cmd_Alias_f(void)

{
  char cVar1;
  int iVar2;
  char *__s1;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char local_404 [1024];
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 1) {
    Con_Printf("Current alias commands:\n");
    for (puVar4 = cmd_alias; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
      Con_Printf("%s : %s\n",puVar4 + 1,puVar4[9]);
    }
    return;
  }
  __s1 = (char *)Cmd_Argv(1);
  uVar6 = 0xffffffff;
  pcVar3 = __s1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (0x1f < ~uVar6 - 1) {
    Con_Printf("Alias name is too long\n");
    return;
  }
  local_404[0] = '\0';
  iVar2 = Cmd_Argc();
  iVar7 = 2;
  if (2 < iVar2) {
    do {
      pcVar3 = (char *)Cmd_Argv(iVar7);
      strcat(local_404,pcVar3);
      if (iVar7 != iVar2) {
        strcat(local_404," ");
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  strcat(local_404,"\n");
  puVar4 = cmd_alias;
  if (cmd_alias != (undefined4 *)0x0) {
    do {
      iVar2 = strcmp(__s1,(char *)(puVar4 + 1));
      if (iVar2 == 0) {
        iVar2 = strcmp((char *)puVar4[9],local_404);
        if (iVar2 == 0) {
          return;
        }
        Z_Free(puVar4[9]);
        break;
      }
      puVar4 = (undefined4 *)*puVar4;
    } while (puVar4 != (undefined4 *)0x0);
    if (puVar4 != (undefined4 *)0x0) goto LAB_0804ce83;
  }
  puVar4 = (undefined4 *)Z_Malloc(0x28);
  *puVar4 = cmd_alias;
  cmd_alias = puVar4;
LAB_0804ce83:
  strcpy((char *)(puVar4 + 1),__s1);
  uVar5 = CopyString(local_404);
  puVar4[9] = uVar5;
  return;
}


// Cmd_Argc  @ 0804cf40
undefined4 Cmd_Argc(void)

{
  return cmd_argc;
}


// Cmd_Args  @ 0804cf80
undefined4 Cmd_Args(void)

{
  return cmd_args;
}


// Cmd_Argv  @ 0804cf50
undefined * Cmd_Argv(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = cmd_null_string;
  if (param_1 < cmd_argc) {
    puVar1 = (undefined *)(&cmd_argv)[param_1];
  }
  return puVar1;
}


// Cmd_CheckParm  @ 0804d4b0
int Cmd_CheckParm(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    Sys_Error("Cmd_CheckParm: NULL");
  }
  iVar3 = 1;
  while( true ) {
    iVar2 = Cmd_Argc();
    if (iVar2 <= iVar3) {
      return 0;
    }
    uVar1 = Cmd_Argv(iVar3);
    iVar2 = Q_strcasecmp(param_1,uVar1);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}


// Cmd_CmdList_f  @ 0804d510
void Cmd_CmdList_f(void)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int unaff_EDI;
  char *pcVar9;
  FILE *local_110;
  int local_108;
  char local_104 [256];
  
  local_108 = 0;
  pcVar8 = (char *)0x0;
  bVar3 = false;
  iVar4 = Cmd_Argc();
  if (1 < iVar4) {
    uVar5 = Cmd_Argv(1,&DAT_0809e93b);
    iVar6 = Q_strcasecmp(uVar5);
    if (iVar6 == 0) {
      Con_Printf(
                "CmdList           : List all commands\nCmdList [Partial] : List commands starting with \'Partial\'\nCmdList log logfile [Partial] : Logs commands to file c:\\logfile.\nNOTE:  No relative paths allowed!"
                );
      return;
    }
    uVar5 = Cmd_Argv(1,&DAT_0809ea04);
    iVar6 = Q_strcasecmp(uVar5);
    if (iVar6 == 0) {
      uVar5 = Cmd_Argv(2);
      sprintf(local_104,"c:\\%s",uVar5);
      local_110 = fopen(local_104,"wt");
      if (local_110 == (FILE *)0x0) {
        uVar5 = Cmd_Argv(2);
        Con_Printf("Couldn\'t open [%s] for writing!\n",uVar5);
      }
      bVar3 = local_110 != (FILE *)0x0;
      if (iVar4 != 4) goto LAB_0804d62d;
      uVar5 = 3;
    }
    else {
      uVar5 = 1;
    }
    pcVar8 = (char *)Cmd_Argv(uVar5);
    uVar7 = 0xffffffff;
    pcVar9 = pcVar8;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    unaff_EDI = ~uVar7 - 1;
  }
LAB_0804d62d:
  Con_Printf("Command List\n--------------\n");
  for (puVar2 = cmd_functions; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if ((pcVar8 == (char *)0x0) || (iVar6 = Q_strncasecmp(puVar2[1],pcVar8,unaff_EDI), iVar6 == 0))
    {
      Con_Printf("%-16.16s\n",puVar2[1]);
      if (bVar3) {
        fprintf(local_110,"%-16.16s\n",puVar2[1]);
      }
      local_108 = local_108 + 1;
    }
  }
  if (((iVar4 == 2) && (pcVar8 != (char *)0x0)) && (*pcVar8 != '\0')) {
    Con_Printf("--------------\n%3i Commands for [%s]\nCmdList ? for syntax\n",local_108,pcVar8);
  }
  else {
    Con_Printf("--------------\n%3i Total Commands\nCmdList ? for syntax\n",local_108);
  }
  if (bVar3) {
    fclose(local_110);
  }
  return;
}


// Cmd_CompleteCommand  @ 0804d260
undefined4 Cmd_CompleteCommand(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar2 = Q_strlen(param_1);
  puVar1 = cmd_functions;
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      iVar3 = Q_strncmp(param_1,puVar1[1],iVar2);
      if (iVar3 == 0) {
        iVar3 = Q_strlen(puVar1[1]);
        if (iVar3 == iVar2) {
          return puVar1[1];
        }
        uVar4 = puVar1[1];
      }
    }
  }
  return uVar4;
}


// Cmd_CvarListPrintCvar  @ 080538c0
void Cmd_CvarListPrintCvar(undefined4 *param_1,FILE *param_2)

{
  float fVar1;
  char local_104 [256];
  
  fVar1 = (float)param_1[3];
  if ((byte)((byte)((ushort)((ushort)(NAN((float)(int)ROUND(fVar1)) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)(int)ROUND(fVar1) == fVar1) << 0xe) >> 8)) == 0x40) {
    sprintf(local_104,"%-15s : %8i",*param_1);
  }
  else {
    sprintf(local_104,"%-15s : %8.3f",*param_1,(double)(float)param_1[3]);
  }
  if ((*(byte *)(param_1 + 2) & 1) != 0) {
    strcat(local_104,", a");
  }
  if ((*(byte *)(param_1 + 2) & 4) != 0) {
    strcat(local_104,", sv");
  }
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    strcat(local_104,", i");
  }
  strcat(local_104,"\n");
  Con_Printf(&DAT_0809f385,local_104);
  if (param_2 != (FILE *)0x0) {
    fprintf(param_2,"%s");
  }
  return;
}


// Cmd_CvarList_f  @ 080539e0
void Cmd_CvarList_f(void)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  FILE *local_118;
  int local_108;
  char local_104 [256];
  
  local_108 = 0;
  pcVar11 = (char *)0x0;
  iVar12 = 0;
  bVar4 = false;
  bVar5 = false;
  local_118 = (FILE *)0x0;
  bVar3 = false;
  iVar6 = Cmd_Argc();
  if (iVar6 < 2) goto LAB_08053b8d;
  uVar7 = Cmd_Argv(1,&DAT_0809f388);
  iVar8 = Q_strcasecmp(uVar7);
  if (iVar8 == 0) {
    Con_Printf(
              "CvarList           : List all cvars\nCvarList [Partial] : List cvars starting with \'Partial\'\nCvarList log logfile [Partial] : Logs cvars to file c:\\logfile.\nNOTE:  No relative paths allowed!"
              );
    return;
  }
  uVar7 = Cmd_Argv(1,&DAT_0809f45e);
  iVar8 = Q_strcasecmp(uVar7);
  if (iVar8 == 0) {
    uVar7 = Cmd_Argv(2);
    sprintf(local_104,"c:\\%s",uVar7);
    local_118 = fopen(local_104,"wt");
    if (local_118 == (FILE *)0x0) {
      uVar7 = Cmd_Argv(2);
      Con_Printf("Couldn\'t open [%s] for writing!\n",uVar7);
      fclose((FILE *)0x0);
    }
    bVar3 = local_118 != (FILE *)0x0;
    if (iVar6 != 4) goto LAB_08053b8d;
    uVar7 = 3;
  }
  else {
    pcVar13 = "-a";
    pcVar9 = (char *)Cmd_Argv(1);
    iVar8 = strcasecmp(pcVar9,pcVar13);
    if (iVar8 == 0) {
      bVar4 = true;
      goto LAB_08053b8d;
    }
    pcVar13 = "-s";
    pcVar9 = (char *)Cmd_Argv(1);
    iVar8 = strcasecmp(pcVar9,pcVar13);
    if (iVar8 == 0) {
      bVar5 = true;
      goto LAB_08053b8d;
    }
    uVar7 = 1;
  }
  pcVar11 = (char *)Cmd_Argv(uVar7);
  uVar10 = 0xffffffff;
  pcVar9 = pcVar11;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  iVar12 = ~uVar10 - 1;
LAB_08053b8d:
  Con_Printf("CVar List\n--------------\n");
  for (puVar2 = cvar_vars; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[4]) {
    if ((((!bVar4) || ((*(byte *)(puVar2 + 2) & 1) != 0)) &&
        ((!bVar5 || ((*(byte *)(puVar2 + 2) & 4) != 0)))) &&
       ((pcVar11 == (char *)0x0 || (iVar8 = Q_strncasecmp(*puVar2,pcVar11,iVar12), iVar8 == 0)))) {
      Cmd_CvarListPrintCvar(puVar2,local_118);
      local_108 = local_108 + 1;
    }
  }
  if (((iVar6 == 2) && (pcVar11 != (char *)0x0)) && (*pcVar11 != '\0')) {
    Con_Printf("--------------\n%3i CVars for [%s]\nCvarList ? for syntax\n",local_108,pcVar11);
  }
  else {
    Con_Printf("--------------\n%3i Total CVars\nCvarList ? for syntax\n",local_108);
  }
  if (bVar3) {
    fclose(local_118);
  }
  return;
}


// Cmd_Echo_f  @ 0804cc90
void Cmd_Echo_f(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  while( true ) {
    iVar2 = Cmd_Argc();
    if (iVar2 <= iVar3) break;
    uVar1 = Cmd_Argv(iVar3);
    Con_Printf(&DAT_0809e7d8,uVar1);
    iVar3 = iVar3 + 1;
  }
  Con_Printf(&DAT_0809e718);
  return;
}


// Cmd_Exec_f  @ 0804cbc0
void Cmd_Exec_f(void)

{
  int iVar1;
  char *__haystack;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    __haystack = (char *)Cmd_Argv(1);
    if (__haystack != (char *)0x0) {
      uVar2 = Hunk_LowMark();
      iVar1 = COM_LoadHunkFile(__haystack);
      if (iVar1 == 0) {
        pcVar3 = strstr(__haystack,"autoexec.cfg");
        if (pcVar3 == (char *)0x0) {
          pcVar3 = strstr(__haystack,"hw/opengl.cfg");
          if (pcVar3 == (char *)0x0) {
            pcVar3 = strstr(__haystack,"joystick.cfg");
            if (pcVar3 == (char *)0x0) {
              pcVar3 = strstr(__haystack,"game.cfg");
              if (pcVar3 == (char *)0x0) {
                Con_Printf("couldn\'t exec %s\n",__haystack);
              }
            }
          }
        }
      }
      else {
        Con_DPrintf("execing %s\n",__haystack);
        Cbuf_InsertTextLines(iVar1);
        Hunk_FreeToLowMark(uVar2);
      }
    }
  }
  else {
    Con_Printf("exec <filename> : execute a script file\n");
  }
  return;
}


// Cmd_ExecuteString  @ 0804d2e0
void Cmd_ExecuteString(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  cmd_source = param_2;
  Cmd_TokenizeString(param_1);
  iVar3 = Cmd_Argc();
  puVar1 = cmd_functions;
  if (iVar3 != 0) {
    for (; puVar2 = cmd_alias, puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      iVar3 = Q_strcasecmp(cmd_argv,puVar1[1]);
      if (iVar3 == 0) {
        (*(code *)puVar1[2])();
        if (DAT_081b9d94 == 0) {
          return;
        }
        if (puVar1[3] == 0) {
          return;
        }
        CL_RecordHUDCommand(puVar1[1]);
        return;
      }
    }
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      iVar3 = Q_strcasecmp(cmd_argv,puVar2 + 1);
      if (iVar3 == 0) {
        Cbuf_InsertText(puVar2[9]);
        return;
      }
    }
    iVar3 = Cvar_Command();
    if ((iVar3 == 0) && (((cls == 5 || (cls == 3)) || (cls == 4)))) {
      Cmd_ForwardToServer();
    }
  }
  return;
}


// Cmd_Exists  @ 0804d210
undefined4 Cmd_Exists(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = cmd_functions;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = Q_strcmp(param_1,puVar1[1]);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}


// Cmd_ForwardToServer  @ 0804d3d0
void Cmd_ForwardToServer(void)

{
  char *__s1;
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  char *__s2;
  
  if (cls - 3U < 3) {
    if ((DAT_081b9d98 == 0) && (isDedicated == 0)) {
      MSG_WriteByte(&DAT_081b5328,4);
      uVar2 = Cmd_Argv(0,&DAT_0809e831);
      iVar1 = Q_strcasecmp(uVar2);
      if (iVar1 != 0) {
        uVar2 = Cmd_Argv(0);
        SZ_Print(&DAT_081b5328,uVar2);
        SZ_Print(&DAT_081b5328,&DAT_0809e74d);
      }
      iVar1 = Cmd_Argc();
      if (iVar1 < 2) {
        puVar3 = &DAT_0809e718;
      }
      else {
        puVar3 = (undefined *)Cmd_Args();
      }
      SZ_Print(&DAT_081b5328,puVar3);
    }
  }
  else {
    __s2 = "setinfo";
    __s1 = (char *)Cmd_Argv(0);
    iVar1 = strcasecmp(__s1,__s2);
    if (iVar1 != 0) {
      uVar2 = Cmd_Argv(0);
      Con_Printf("Can\'t \"%s\", not connected\n",uVar2);
    }
  }
  return;
}


// Cmd_Init  @ 0804cec0
void Cmd_Init(void)

{
  Cmd_AddCommand("stuffcmds",Cmd_StuffCmds_f);
  Cmd_AddCommand(&DAT_0809e821,Cmd_Exec_f);
  Cmd_AddCommand(&DAT_0809e826,Cmd_Echo_f);
  Cmd_AddCommand("alias",Cmd_Alias_f);
  Cmd_AddCommand(&DAT_0809e831,Cmd_ForwardToServer);
  Cmd_AddCommand(&DAT_0809e835,Cmd_Wait_f);
  Cmd_AddCommand("cmdlist",Cmd_CmdList_f);
  return;
}


// Cmd_RemoveHudCmds  @ 0804d1c0
void Cmd_RemoveHudCmds(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *__ptr;
  
  puVar2 = (undefined4 *)0x0;
  __ptr = cmd_functions;
  while (__ptr != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*__ptr;
    if (__ptr[3] == 0) {
      *__ptr = puVar2;
      puVar2 = __ptr;
      __ptr = puVar1;
    }
    else {
      free(__ptr);
      __ptr = puVar1;
    }
  }
  cmd_functions = puVar2;
  return;
}


// Cmd_StuffCmds_f  @ 0804ca40
void Cmd_StuffCmds_f(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  int local_8;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 1) {
    local_8 = 0;
    iVar2 = 1;
    if (1 < com_argc) {
      do {
        if (*(int *)(com_argv + iVar2 * 4) != 0) {
          iVar3 = Q_strlen(*(undefined4 *)(com_argv + iVar2 * 4));
          local_8 = iVar3 + 1 + local_8;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < com_argc);
    }
    if (local_8 != 0) {
      puVar4 = (undefined1 *)Z_Malloc(local_8 + 1);
      *puVar4 = 0;
      iVar2 = 1;
      if (1 < com_argc) {
        do {
          if ((*(int *)(com_argv + iVar2 * 4) != 0) &&
             (Q_strcat(puVar4,*(undefined4 *)(com_argv + iVar2 * 4)), iVar2 != com_argc + -1)) {
            Q_strcat(puVar4,&DAT_0809e74d);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < com_argc);
      }
      pcVar5 = (char *)Z_Malloc(local_8 + 1);
      *pcVar5 = '\0';
      for (iVar2 = 0; iVar2 < local_8 + -1; iVar2 = iVar2 + 1) {
        if (puVar4[iVar2] == '+') {
          iVar2 = iVar2 + 1;
          iVar3 = iVar2;
          if ((puVar4[iVar2] != '+') && (puVar4[iVar2] != '-')) {
            while (puVar4[iVar3] != '\0') {
              iVar3 = iVar3 + 1;
              if ((puVar4[iVar3] == '+') || (puVar4[iVar3] == '-')) break;
            }
          }
          uVar1 = puVar4[iVar3];
          puVar4[iVar3] = 0;
          Q_strcat(pcVar5,puVar4 + iVar2);
          Q_strcat(pcVar5,&DAT_0809e718);
          puVar4[iVar3] = uVar1;
          iVar2 = iVar3 + -1;
        }
      }
      if (*pcVar5 != '\0') {
        Cbuf_InsertText(pcVar5);
      }
      Z_Free(puVar4);
      Z_Free(pcVar5);
    }
  }
  else {
    Con_Printf("stuffcmds : execute command line parameters\n");
  }
  return;
}


// Cmd_TokenizeString  @ 0804cf90
void Cmd_TokenizeString(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (0 < cmd_argc) {
    iVar2 = 0;
    do {
      Z_Free((&cmd_argv)[iVar2]);
      iVar2 = iVar2 + 1;
    } while (iVar2 < cmd_argc);
  }
  cmd_argc = 0;
  cmd_args = (char *)0x0;
  while( true ) {
    for (; (*param_1 != '\0' && (*param_1 < '!')); param_1 = param_1 + 1) {
      if (*param_1 == '\n') {
        return;
      }
    }
    if ((*param_1 == '\n') || (*param_1 == '\0')) break;
    if (cmd_argc == 1) {
      cmd_args = param_1;
    }
    param_1 = (char *)COM_Parse(param_1);
    if (param_1 == (char *)0x0) {
      return;
    }
    if (cmd_argc < 0x50) {
      iVar2 = Q_strlen(&com_token);
      uVar1 = Z_Malloc(iVar2 + 1);
      (&cmd_argv)[cmd_argc] = uVar1;
      Q_strcpy(uVar1,&com_token);
      cmd_argc = cmd_argc + 1;
    }
  }
  return;
}


// Cmd_Wait_f  @ 0804c7d0
void Cmd_Wait_f(void)

{
  cmd_wait = 1;
  return;
}


