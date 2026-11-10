// Cmd_AddCommand  @ 000480d8
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void Cmd_AddCommand(int param_1,int param_2)

{
  int **ppiVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int *local_14;
  undefined *local_10;
  
  if (host_initialized != 0) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar3 = (char *)Cvar_VariableString(param_1);
  piVar2 = cmd_functions;
  if (*pcVar3 == '\0') {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar4 = Q_strcmp(param_1,piVar2[1]);
      if (iVar4 == 0) {
        pcVar3 = "Cmd_AddCommand: %s already defined\n";
        goto LAB_0004812b;
      }
    }
    piVar5 = (int *)Hunk_Alloc(0x10);
    ppiVar1 = &local_14;
    piVar5[1] = param_1;
    piVar5[2] = param_2;
    piVar5[3] = 0;
    local_14 = cmd_functions;
    local_10 = &DAT_000a404d;
    piVar2 = cmd_functions;
    while (piVar2 != (int *)0x0) {
      iVar4 = Q_stricmp((*ppiVar1)[1],piVar5[1]);
      if (0 < iVar4) {
        piVar2 = *ppiVar1;
        *ppiVar1 = piVar5;
        *piVar5 = (int)piVar2;
        goto LAB_000481cd;
      }
      ppiVar1 = (int **)*ppiVar1;
      piVar2 = *ppiVar1;
    }
    *ppiVar1 = piVar5;
    *piVar5 = 0;
LAB_000481cd:
    cmd_functions = local_14;
  }
  else {
    pcVar3 = "Cmd_AddCommand: %s already defined as a var\n";
LAB_0004812b:
    Con_Printf(pcVar3,param_1);
  }
  return;
}


// Cmd_AddHUDCommand  @ 000481e4
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
        pcVar1 = "Cmd_AddCommand: %s already defined\n";
        goto LAB_00048217;
      }
    }
    puVar3 = (undefined4 *)Mem_ZeroMalloc(0x10);
    puVar3[1] = param_1;
    puVar3[2] = param_2;
    puVar3[3] = 1;
    *puVar3 = cmd_functions;
    cmd_functions = puVar3;
  }
  else {
    pcVar1 = "Cmd_AddCommand: %s already defined as a var\n";
LAB_00048217:
    Con_Printf(pcVar1,param_1);
  }
  return;
}


// Cmd_Alias_f  @ 00047b30
void Cmd_Alias_f(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 local_404 [1024];
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Current alias commands:\n");
    for (puVar5 = cmd_alias; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
      Con_Printf("%s : %s\n",puVar5 + 1,puVar5[9]);
    }
    return;
  }
  uVar2 = Cmd_Argv(1);
  iVar1 = Q_strlen(uVar2);
  if (0x1f < iVar1) {
    Con_Printf("Alias name is too long\n");
    return;
  }
  local_404[0] = 0;
  iVar1 = Cmd_Argc();
  iVar6 = 2;
  if (2 < iVar1) {
    uVar3 = iVar1 - 2U & 3;
    if (uVar3 != 0) {
      if (1 < uVar3) {
        if (2 < uVar3) {
          uVar4 = Cmd_Argv(2);
          Q_strcat(local_404,uVar4);
          Q_strcat(local_404,&DAT_000a404d);
          iVar6 = 3;
        }
        uVar4 = Cmd_Argv(iVar6);
        Q_strcat(local_404,uVar4);
        if (iVar6 != iVar1) {
          Q_strcat(local_404,&DAT_000a404d);
        }
        iVar6 = iVar6 + 1;
      }
      uVar4 = Cmd_Argv(iVar6);
      Q_strcat(local_404,uVar4);
      if (iVar6 != iVar1) {
        Q_strcat(local_404,&DAT_000a404d);
      }
      iVar6 = iVar6 + 1;
      if (iVar1 <= iVar6) goto LAB_00047d98;
    }
    do {
      uVar4 = Cmd_Argv(iVar6);
      Q_strcat(local_404,uVar4);
      if (iVar6 != iVar1) {
        Q_strcat(local_404,&DAT_000a404d);
      }
      uVar4 = Cmd_Argv(iVar6 + 1);
      Q_strcat(local_404,uVar4);
      if (iVar6 + 1 != iVar1) {
        Q_strcat(local_404,&DAT_000a404d);
      }
      uVar4 = Cmd_Argv(iVar6 + 2);
      Q_strcat(local_404,uVar4);
      if (iVar6 + 2 != iVar1) {
        Q_strcat(local_404,&DAT_000a404d);
      }
      uVar4 = Cmd_Argv(iVar6 + 3);
      Q_strcat(local_404,uVar4);
      if (iVar6 + 3 != iVar1) {
        Q_strcat(local_404,&DAT_000a404d);
      }
      iVar6 = iVar6 + 4;
    } while (iVar6 < iVar1);
  }
LAB_00047d98:
  Q_strcat(local_404,&DAT_000a4018);
  puVar5 = cmd_alias;
  if (cmd_alias != (undefined4 *)0x0) {
    do {
      iVar1 = Q_strcmp(uVar2,puVar5 + 1);
      if (iVar1 == 0) {
        iVar1 = Q_strcmp(puVar5[9],local_404);
        if (iVar1 == 0) {
          return;
        }
        Z_Free(puVar5[9]);
        break;
      }
      puVar5 = (undefined4 *)*puVar5;
    } while (puVar5 != (undefined4 *)0x0);
    if (puVar5 != (undefined4 *)0x0) goto LAB_00047e20;
  }
  puVar5 = (undefined4 *)Z_Malloc(0x28);
  *puVar5 = cmd_alias;
  cmd_alias = puVar5;
LAB_00047e20:
  Q_strcpy(puVar5 + 1,uVar2);
  uVar2 = CopyString(local_404);
  puVar5[9] = uVar2;
  return;
}


// Cmd_Argc  @ 00047eec
undefined4 Cmd_Argc(void)

{
  return cmd_argc;
}


// Cmd_Args  @ 00047f40
undefined4 Cmd_Args(void)

{
  return cmd_args;
}


// Cmd_Argv  @ 00047f0c
undefined * Cmd_Argv(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = cmd_null_string;
  if (param_1 < cmd_argc) {
    puVar1 = (undefined *)(&cmd_argv)[param_1];
  }
  return puVar1;
}


// Cmd_CheckParm  @ 00048620
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


// Cmd_CmdList_f  @ 00048680
void Cmd_CmdList_f(void)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  FILE *local_118;
  undefined4 local_114;
  char *local_110;
  int local_108;
  char local_104 [256];
  
  local_108 = 0;
  local_110 = (char *)0x0;
  bVar2 = false;
  iVar3 = Cmd_Argc();
  if (1 < iVar3) {
    uVar4 = Cmd_Argv(1,&DAT_000a423b);
    iVar5 = Q_strcasecmp(uVar4);
    if (iVar5 == 0) {
      Con_Printf(
                "CmdList           : List all commands\nCmdList [Partial] : List commands starting with \'Partial\'\nCmdList log logfile [Partial] : Logs commands to file c:\\logfile.\nNOTE:  No relative paths allowed!"
                );
      return;
    }
    uVar4 = Cmd_Argv(1,&DAT_000a4304);
    iVar5 = Q_strcasecmp(uVar4);
    if (iVar5 == 0) {
      uVar4 = Cmd_Argv(2);
      sprintf(local_104,"c:\\%s",uVar4);
      local_118 = fopen(local_104,"wt");
      if (local_118 == (FILE *)0x0) {
        uVar4 = Cmd_Argv(2);
        Con_Printf("Couldn\'t open [%s] for writing!\n",uVar4);
      }
      bVar2 = local_118 != (FILE *)0x0;
      if (iVar3 != 4) goto LAB_0004879c;
      uVar4 = 3;
    }
    else {
      uVar4 = 1;
    }
    local_110 = (char *)Cmd_Argv(uVar4);
    local_114 = Q_strlen(local_110);
  }
LAB_0004879c:
  Con_Printf("Command List\n--------------\n");
  for (puVar1 = cmd_functions; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if ((local_110 == (char *)0x0) ||
       (iVar5 = Q_strncasecmp(puVar1[1],local_110,local_114), iVar5 == 0)) {
      Con_Printf("%-16.16s\n",puVar1[1]);
      if (bVar2) {
        fprintf(local_118,"%-16.16s\n",puVar1[1]);
      }
      local_108 = local_108 + 1;
    }
  }
  if (((iVar3 == 2) && (local_110 != (char *)0x0)) && (*local_110 != '\0')) {
    Con_Printf("--------------\n%3i Commands for [%s]\nCmdList ? for syntax\n",local_108,local_110);
  }
  else {
    Con_Printf("--------------\n%3i Total Commands\nCmdList ? for syntax\n",local_108);
  }
  if (bVar2) {
    fclose(local_118);
  }
  return;
}


// Cmd_CompleteCommand  @ 00048310
int Cmd_CompleteCommand(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
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
    iVar4 = Q_stricmp(local_104,lastpartial_46);
    if ((iVar4 == 0) && (puVar5 = (undefined4 *)Cmd_FindCmd(local_104), puVar5 != (undefined4 *)0x0)
       ) {
      if (param_2 == 1) {
        piVar6 = (int *)*puVar5;
      }
      else {
        piVar6 = (int *)Cmd_FindCmdPrev(puVar5[1]);
      }
      if (piVar6 != (int *)0x0) {
LAB_000483d2:
        Q_strcpy(lastpartial_46,piVar6[1]);
        return piVar6[1];
      }
    }
    piVar6 = cmd_functions;
    if (cmd_functions != (int *)0x0) {
      do {
        iVar4 = Q_strncmp(local_104,piVar6[1],iVar3);
        if (iVar4 == 0) {
          iVar4 = Q_strlen(piVar6[1]);
          if (iVar4 == iVar3) goto LAB_000483d2;
          local_108 = piVar6[1];
          break;
        }
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)0x0);
      if (piVar6 != (int *)0x0) {
        Q_strcpy(lastpartial_46,piVar6[1]);
      }
    }
  }
  return local_108;
}


// Cmd_CvarListPrintCvar  @ 0004e970
void Cmd_CvarListPrintCvar(undefined4 *param_1,FILE *param_2)

{
  float fVar1;
  uint uVar2;
  char local_104 [256];
  
  fVar1 = (float)param_1[3];
  if ((byte)((byte)((ushort)((ushort)(NAN((float)(int)ROUND(fVar1)) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)(int)ROUND(fVar1) == fVar1) << 0xe) >> 8)) == 0x40) {
    sprintf(local_104,"%-15s : %8i",*param_1);
  }
  else {
    sprintf(local_104,"%-15s : %8.3f",*param_1,(double)fVar1);
  }
  uVar2 = param_1[2];
  if ((uVar2 & 1) != 0) {
    Q_strcat(local_104);
    uVar2 = param_1[2];
  }
  if ((uVar2 & 4) != 0) {
    Q_strcat(local_104);
    uVar2 = param_1[2];
  }
  if ((uVar2 & 2) != 0) {
    Q_strcat(local_104);
  }
  Q_strcat(local_104);
  Con_Printf(&DAT_000a4d07,local_104);
  if (param_2 != (FILE *)0x0) {
    fprintf(param_2,"%s");
  }
  return;
}


// Cmd_CvarList_f  @ 0004ea90
void Cmd_CvarList_f(void)

{
  undefined4 *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  FILE *local_11c;
  undefined4 local_110;
  int local_108;
  char local_104 [256];
  
  local_108 = 0;
  pcVar8 = (char *)0x0;
  local_110 = 0;
  bVar3 = false;
  bVar4 = false;
  local_11c = (FILE *)0x0;
  bVar2 = false;
  iVar5 = Cmd_Argc();
  if (iVar5 < 2) goto LAB_0004ec28;
  uVar6 = Cmd_Argv(1,&DAT_000a4d0a);
  iVar7 = Q_strcasecmp(uVar6);
  if (iVar7 == 0) {
    Con_Printf(
              "CvarList           : List all cvars\nCvarList [Partial] : List cvars starting with \'Partial\'\nCvarList log logfile [Partial] : Logs cvars to file c:\\logfile.\nNOTE:  No relative paths allowed!"
              );
    return;
  }
  uVar6 = Cmd_Argv(1,&DAT_000a4dde);
  iVar7 = Q_strcasecmp(uVar6);
  if (iVar7 == 0) {
    uVar6 = Cmd_Argv(2);
    sprintf(local_104,"c:\\%s",uVar6);
    local_11c = fopen(local_104,"wt");
    if (local_11c == (FILE *)0x0) {
      uVar6 = Cmd_Argv(2);
      Con_Printf("Couldn\'t open [%s] for writing!\n",uVar6);
      fclose((FILE *)0x0);
    }
    bVar2 = local_11c != (FILE *)0x0;
    if (iVar5 != 4) goto LAB_0004ec28;
    uVar6 = 3;
  }
  else {
    uVar6 = Cmd_Argv(1,&DAT_000a4e21);
    iVar7 = Q_stricmp(uVar6);
    if (iVar7 == 0) {
      bVar3 = true;
      goto LAB_0004ec28;
    }
    uVar6 = Cmd_Argv(1,&DAT_000a4e24);
    iVar7 = Q_stricmp(uVar6);
    if (iVar7 == 0) {
      bVar4 = true;
      goto LAB_0004ec28;
    }
    uVar6 = 1;
  }
  pcVar8 = (char *)Cmd_Argv(uVar6);
  local_110 = Q_strlen(pcVar8);
LAB_0004ec28:
  Con_Printf("CVar List\n--------------\n");
  for (puVar1 = cvar_vars; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[4]) {
    if ((((!bVar3) || ((*(byte *)(puVar1 + 2) & 1) != 0)) &&
        ((!bVar4 || ((*(byte *)(puVar1 + 2) & 4) != 0)))) &&
       ((pcVar8 == (char *)0x0 || (iVar7 = Q_strncasecmp(*puVar1,pcVar8,local_110), iVar7 == 0)))) {
      Cmd_CvarListPrintCvar(puVar1,local_11c);
      local_108 = local_108 + 1;
    }
  }
  if (((iVar5 == 2) && (pcVar8 != (char *)0x0)) && (*pcVar8 != '\0')) {
    Con_Printf("--------------\n%3i CVars for [%s]\nCvarList ? for syntax\n",local_108,pcVar8);
  }
  else {
    Con_Printf("--------------\n%3i Total CVars\nCvarList ? for syntax\n",local_108);
  }
  if (bVar2) {
    fclose(local_11c);
  }
  return;
}


// Cmd_Echo_f  @ 00047aa8
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
    Con_Printf(&DAT_000a40d8,uVar1);
    iVar3 = iVar3 + 1;
  }
  Con_Printf(&DAT_000a4018);
  return;
}


// Cmd_Exec_f  @ 000479c4
void Cmd_Exec_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    iVar1 = Cmd_Argv(1);
    if (iVar1 != 0) {
      uVar2 = Hunk_LowMark();
      iVar3 = COM_LoadHunkFile(iVar1);
      if (iVar3 == 0) {
        iVar3 = Q_strstr(iVar1,"autoexec.cfg");
        if (iVar3 == 0) {
          iVar3 = Q_strstr(iVar1,"hw/opengl.cfg");
          if (iVar3 == 0) {
            iVar3 = Q_strstr(iVar1,"joystick.cfg");
            if (iVar3 == 0) {
              iVar3 = Q_strstr(iVar1,"game.cfg");
              if (iVar3 == 0) {
                Con_Printf("couldn\'t exec %s\n",iVar1);
              }
            }
          }
        }
      }
      else {
        Con_DPrintf("execing %s\n",iVar1);
        Cbuf_InsertTextLines(iVar3);
        Hunk_FreeToLowMark(uVar2);
      }
    }
  }
  else {
    Con_Printf("exec <filename> : execute a script file\n");
  }
  return;
}


// Cmd_ExecuteString  @ 00048458
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
        if (DAT_003855a0 == 0) {
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


// Cmd_Exists  @ 000482c4
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


// Cmd_FindCmd  @ 00048040
undefined4 * Cmd_FindCmd(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = cmd_functions;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar2 = Q_strcmp(param_1,puVar1[1]);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}


// Cmd_FindCmdPrev  @ 0004808c
int * Cmd_FindCmdPrev(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = cmd_functions;
  while( true ) {
    if (*piVar2 == 0) {
      return (int *)0x0;
    }
    iVar1 = Q_strcmp(param_1,*(undefined4 *)(*piVar2 + 4));
    if (iVar1 == 0) break;
    piVar2 = (int *)*piVar2;
  }
  return piVar2;
}


// Cmd_ForwardToServer  @ 00048540
void Cmd_ForwardToServer(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  if (cls - 3U < 3) {
    if ((DAT_003855a4 == 0) && (isDedicated == 0)) {
      MSG_WriteByte(&DAT_00382558,3);
      uVar1 = Cmd_Argv(0,&DAT_000a4131);
      iVar2 = Q_strcasecmp(uVar1);
      if (iVar2 != 0) {
        uVar1 = Cmd_Argv(0);
        SZ_Print(&DAT_00382558,uVar1);
        SZ_Print(&DAT_00382558,&DAT_000a404d);
      }
      iVar2 = Cmd_Argc();
      if (iVar2 < 2) {
        puVar3 = &DAT_000a4018;
      }
      else {
        puVar3 = (undefined *)Cmd_Args();
      }
      SZ_Print(&DAT_00382558,puVar3);
    }
  }
  else {
    uVar1 = Cmd_Argv(0,"setinfo");
    iVar2 = Q_stricmp(uVar1);
    if (iVar2 != 0) {
      uVar1 = Cmd_Argv(0);
      Con_Printf("Can\'t \"%s\", not connected\n",uVar1);
    }
  }
  return;
}


// Cmd_Init  @ 00047e4c
void Cmd_Init(void)

{
  Cmd_AddCommand("stuffcmds",Cmd_StuffCmds_f);
  Cmd_AddCommand(&DAT_000a4121,Cmd_Exec_f);
  Cmd_AddCommand(&DAT_000a4126,Cmd_Echo_f);
  Cmd_AddCommand("alias",Cmd_Alias_f);
  Cmd_AddCommand(&DAT_000a4131,Cmd_ForwardToServer);
  Cmd_AddCommand(&DAT_000a4135,Cmd_Wait_f);
  Cmd_AddCommand("cmdlist",Cmd_CmdList_f);
  return;
}


// Cmd_RemoveHudCmds  @ 00048274
void Cmd_RemoveHudCmds(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)0x0;
  puVar3 = cmd_functions;
  while (puVar3 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar3;
    if (puVar3[3] == 0) {
      *puVar3 = puVar2;
      puVar2 = puVar3;
      puVar3 = puVar1;
    }
    else {
      Mem_Free(puVar3);
      puVar3 = puVar1;
    }
  }
  cmd_functions = puVar2;
  return;
}


// Cmd_StuffCmds_f  @ 000477e8
void Cmd_StuffCmds_f(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char *local_20;
  int local_1c;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 1) {
    local_1c = 0;
    if (1 < com_argc) {
      iVar2 = 1;
      do {
        iVar3 = *(int *)(com_argv + iVar2 * 4);
        if (iVar3 != 0) {
          iVar3 = Q_strlen(iVar3);
          local_1c = iVar3 + 1 + local_1c;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < com_argc);
    }
    if (local_1c != 0) {
      puVar4 = (undefined1 *)Z_Malloc(local_1c + 1);
      *puVar4 = 0;
      if (1 < com_argc) {
        iVar2 = 1;
        do {
          iVar3 = *(int *)(com_argv + iVar2 * 4);
          if (iVar3 != 0) {
            Q_strcat(puVar4,iVar3);
            if (iVar2 != com_argc + -1) {
              Q_strcat(puVar4,&DAT_000a404d);
            }
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < com_argc);
      }
      pcVar5 = (char *)Z_Malloc(local_1c + 1);
      *pcVar5 = '\0';
      iVar3 = 0;
      iVar2 = local_1c + -1;
      if (0 < iVar2) {
        do {
          if (puVar4[iVar3] == '+') {
            iVar3 = iVar3 + 1;
            local_1c = iVar3;
            if ((puVar4[iVar3] != '+') && (puVar4[iVar3] != '-')) {
              local_20 = puVar4 + iVar3;
              while (*local_20 != '\0') {
                local_20 = local_20 + 1;
                local_1c = local_1c + 1;
                if ((*local_20 == '+') || (*local_20 == '-')) break;
              }
            }
            uVar1 = puVar4[local_1c];
            puVar4[local_1c] = 0;
            Q_strcat(pcVar5,puVar4 + iVar3);
            Q_strcat(pcVar5,&DAT_000a4018);
            puVar4[local_1c] = uVar1;
            iVar3 = local_1c + -1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
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


// Cmd_TokenizeString  @ 00047f60
void Cmd_TokenizeString(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < cmd_argc) {
    do {
      Z_Free((&cmd_argv)[iVar3]);
      iVar3 = iVar3 + 1;
    } while (iVar3 < cmd_argc);
  }
  cmd_argc = 0;
  cmd_args = (char *)0x0;
  while( true ) {
    for (; (cVar1 = *param_1, cVar1 != '\0' && (cVar1 < '!')); param_1 = param_1 + 1) {
      if (cVar1 == '\n') {
        return;
      }
    }
    if ((cVar1 == '\n') || (cVar1 == '\0')) break;
    if (cmd_argc == 1) {
      cmd_args = param_1;
    }
    param_1 = (char *)COM_Parse(param_1);
    if (param_1 == (char *)0x0) {
      return;
    }
    if (cmd_argc < 0x50) {
      iVar3 = Q_strlen(&com_token);
      uVar2 = Z_Malloc(iVar3 + 1);
      (&cmd_argv)[cmd_argc] = uVar2;
      Q_strcpy(uVar2,&com_token);
      cmd_argc = cmd_argc + 1;
    }
  }
  return;
}


// Cmd_Wait_f  @ 00047430
void Cmd_Wait_f(void)

{
  cmd_wait = 1;
  return;
}


