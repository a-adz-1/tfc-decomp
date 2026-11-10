// Cmd_AddCommand  @ 00054b38
void Cmd_AddCommand(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *local_24;
  undefined *local_20;
  undefined4 *local_14;
  undefined4 **local_10;
  undefined4 **local_c;
  int *local_8;
  
  if (host_initialized != 0) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar1 = (char *)Cvar_VariableString(param_1);
  if (*pcVar1 == '\0') {
    for (local_8 = cmd_functions; local_8 != (undefined4 *)0x0; local_8 = (int *)*local_8) {
      iVar2 = Q_strcmp(param_1,local_8[1]);
      if (iVar2 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n",param_1);
        return;
      }
    }
    local_8 = (int *)Hunk_Alloc(0x10);
    local_8[1] = param_1;
    local_8[2] = param_2;
    local_8[3] = 0;
    local_24 = cmd_functions;
    local_20 = &DAT_000df82d;
    local_10 = &local_24;
    local_c = local_10;
    for (; *local_10 != (undefined4 *)0x0; local_10 = (undefined4 **)*local_10) {
      iVar2 = strcasecmp((char *)(*local_10)[1],(char *)local_8[1]);
      if (0 < iVar2) {
        local_14 = *local_10;
        *local_10 = local_8;
        *local_8 = (int)local_14;
        cmd_functions = *local_c;
        return;
      }
    }
    *local_10 = local_8;
    *local_8 = 0;
    cmd_functions = *local_c;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n",param_1);
  }
  return;
}


// Cmd_AddGameCommand  @ 00054e24
void Cmd_AddGameCommand(undefined4 param_1,undefined4 param_2)

{
  Cmd_AddMallocCommand(param_1,param_2,2,0x54e30);
  return;
}


// Cmd_AddHUDCommand  @ 00054dc4
void Cmd_AddHUDCommand(undefined4 param_1,undefined4 param_2)

{
  Cmd_AddMallocCommand(param_1,param_2,1,0x54dd0);
  return;
}


// Cmd_AddMallocCommand  @ 00054cd8
void Cmd_AddMallocCommand(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *local_8;
  
  pcVar1 = (char *)Cvar_VariableString(param_1);
  if (*pcVar1 == '\0') {
    for (local_8 = cmd_functions; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
      iVar2 = Q_strcmp(param_1,local_8[1]);
      if (iVar2 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n",param_1);
        return;
      }
    }
    puVar3 = (undefined4 *)Mem_ZeroMalloc(0x10);
    puVar3[1] = param_1;
    puVar3[2] = param_2;
    puVar3[3] = param_3;
    *puVar3 = cmd_functions;
    cmd_functions = puVar3;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n",param_1);
  }
  return;
}


// Cmd_AddWrapperCommand  @ 00054df4
void Cmd_AddWrapperCommand(undefined4 param_1,undefined4 param_2)

{
  Cmd_AddMallocCommand(param_1,param_2,4,0x54e00);
  return;
}


// Cmd_Alias_f  @ 00054414
void Cmd_Alias_f(void)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  char *__src;
  int local_40c;
  char local_408 [1024];
  undefined4 *local_8;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Current alias commands:\n");
    for (local_8 = cmd_alias; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
      Con_Printf("%s : %s\n",local_8 + 1,local_8[9]);
    }
  }
  else {
    uVar2 = Cmd_Argv(1);
    iVar1 = Q_strlen(uVar2);
    if (iVar1 < 0x20) {
      local_408[0] = '\0';
      iVar1 = Cmd_Argc();
      for (local_40c = 2; local_40c < iVar1; local_40c = local_40c + 1) {
        sVar3 = strlen(local_408);
        sVar3 = 0x3fe - sVar3;
        __src = (char *)Cmd_Argv(local_40c);
        strncat(local_408,__src,sVar3);
        if (local_40c != iVar1) {
          sVar3 = strlen(local_408);
          strncat(local_408," ",0x3fe - sVar3);
        }
      }
      Q_strcat(local_408,&DAT_000df7e0);
      for (local_8 = cmd_alias; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
        iVar1 = Q_strcmp(uVar2,local_8 + 1);
        if (iVar1 == 0) {
          iVar1 = Q_strcmp(local_8[9],local_408);
          if (iVar1 == 0) {
            return;
          }
          Z_Free(local_8[9]);
          break;
        }
      }
      if (local_8 == (undefined4 *)0x0) {
        local_8 = (undefined4 *)Z_Malloc(0x28);
        *local_8 = cmd_alias;
        cmd_alias = local_8;
      }
      Q_strncpy(local_8 + 1,uVar2,0x1f);
      *(undefined1 *)((int)local_8 + 0x23) = 0;
      uVar2 = CopyString(local_408);
      local_8[9] = uVar2;
    }
    else {
      Con_Printf("Alias name is too long\n");
    }
  }
  return;
}


// Cmd_Argc  @ 00054818
undefined4 Cmd_Argc(void)

{
  (*(code *)g_engdstAddrs._152_4_)();
  return cmd_argc;
}


// Cmd_Args  @ 000548bc
undefined4 Cmd_Args(void)

{
  return cmd_args;
}


// Cmd_Argv  @ 00054850
undefined * Cmd_Argv(uint param_1)

{
  undefined *puVar1;
  
  (*(code *)g_engdstAddrs._156_4_)(&param_1);
  puVar1 = cmd_null_string;
  if (param_1 < cmd_argc) {
    puVar1 = (undefined *)(&cmd_argv)[param_1];
  }
  return puVar1;
}


// Cmd_CheckParm  @ 000555e8
int Cmd_CheckParm(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (param_1 == 0) {
    Sys_Error("Cmd_CheckParm: NULL");
  }
  local_8 = 1;
  while( true ) {
    iVar1 = Cmd_Argc();
    if (iVar1 <= local_8) {
      return 0;
    }
    uVar2 = Cmd_Argv(local_8);
    iVar1 = Q_strcasecmp(param_1,uVar2);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


// Cmd_CmdList_f  @ 00055674
void Cmd_CmdList_f(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  char local_120 [256];
  int local_20;
  int local_1c;
  undefined4 local_18;
  char *local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  local_c = 0;
  local_14 = (char *)0x0;
  local_20 = 0;
  local_10 = Cmd_Argc();
  if (1 < local_10) {
    puVar3 = &DAT_000dfadc;
    uVar1 = Cmd_Argv(1);
    iVar2 = Q_strcasecmp(uVar1,puVar3);
    if (iVar2 == 0) {
      Con_Printf(
                "CmdList           : List all commands\nCmdList [Partial] : List commands starting with \'Partial\'\nCmdList log [Partial] : Logs commands to file \"cmdlist.txt\" in the gamedir.\n"
                );
      return;
    }
    puVar3 = &DAT_000dfb8d;
    uVar1 = Cmd_Argv(1);
    iVar2 = Q_strcasecmp(uVar1,puVar3);
    if (iVar2 == 0) {
      snprintf(local_120,0x100,"cmdlist.txt");
      local_1c = FS_Open(local_120,&DAT_000dfb9d);
      if (local_1c == 0) {
        Con_Printf("Couldn\'t open [%s] for writing!\n",local_120);
        return;
      }
      local_20 = 1;
      if (local_10 == 3) {
        local_14 = (char *)Cmd_Argv(2);
        local_18 = Q_strlen(local_14);
      }
    }
    else {
      local_14 = (char *)Cmd_Argv(1);
      local_18 = Q_strlen(local_14);
    }
  }
  Con_Printf("Command List\n--------------\n");
  for (local_8 = cmd_functions; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
    if (local_14 == (char *)0x0) {
      Con_Printf("%-16.16s\n",local_8[1]);
      if (local_20 != 0) {
        FS_FPrintf(local_1c,"%-16.16s\n",local_8[1]);
      }
      local_c = local_c + 1;
    }
    else {
      iVar2 = Q_strncasecmp(local_8[1],local_14,local_18);
      if (iVar2 == 0) {
        Con_Printf("%-16.16s\n",local_8[1]);
        if (local_20 != 0) {
          FS_FPrintf(local_1c,"%-16.16s\n",local_8[1]);
        }
        local_c = local_c + 1;
      }
    }
  }
  if (((local_10 == 2) && (local_14 != (char *)0x0)) && (*local_14 != '\0')) {
    Con_Printf("--------------\n%3i Commands for [%s]\nCmdList ? for syntax\n",local_c,local_14);
  }
  else {
    Con_Printf("--------------\n%3i Total Commands\nCmdList ? for syntax\n",local_c);
  }
  if (local_20 != 0) {
    FS_Close(local_1c);
  }
  return;
}


// Cmd_CompleteCommand  @ 00054fb4
undefined4 Cmd_CompleteCommand(undefined4 param_1,int param_2)

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
    iVar1 = Q_stricmp(local_104,lastpartial_93);
    if ((iVar1 == 0) && (local_108 = (int *)Cmd_FindCmd(local_104), local_108 != (int *)0x0)) {
      if (param_2 == 1) {
        local_108 = (int *)*local_108;
      }
      else {
        local_108 = (int *)Cmd_FindCmdPrev(local_108[1]);
      }
      if (local_108 != (int *)0x0) {
        Q_strncpy(lastpartial_93,*(undefined4 *)((int)local_108 + 4),0xff);
        lastpartial_93[0xff] = 0;
        return *(undefined4 *)((int)local_108 + 4);
      }
    }
    for (local_108 = cmd_functions; local_108 != (undefined4 *)0x0; local_108 = (int *)*local_108) {
      iVar1 = Q_strncmp(local_104,local_108[1],local_10c);
      if (iVar1 == 0) {
        iVar1 = Q_strlen(local_108[1]);
        if (iVar1 == local_10c) {
          Q_strncpy(lastpartial_93,local_108[1],0xff);
          lastpartial_93[0xff] = 0;
          return local_108[1];
        }
        local_110 = local_108[1];
        break;
      }
    }
    if (local_108 != (undefined4 *)0x0) {
      Q_strncpy(lastpartial_93,local_108[1],0xff);
      lastpartial_93[0xff] = 0;
    }
  }
  return local_110;
}


// Cmd_CvarListPrintCvar  @ 0005c3a4
void Cmd_CvarListPrintCvar(undefined4 *param_1,int param_2)

{
  char local_104 [256];
  
  if ((byte)((byte)((ushort)((ushort)(NAN((float)param_1[3]) ||
                                     NAN((float)(int)ROUND((float)param_1[3]))) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[3] == (float)(int)ROUND((float)param_1[3])) <<
                           0xe) >> 8)) == 0x40) {
    snprintf(local_104,0xf5,"%-15s : %8i",*param_1,(int)ROUND((float)param_1[3]));
  }
  else {
    snprintf(local_104,0xf5,"%-15s : %8.3f",*param_1,(double)(float)param_1[3]);
  }
  if ((param_1[2] & 1) != 0) {
    Q_strcat(local_104,&DAT_000e04b8);
  }
  if ((param_1[2] & 4) != 0) {
    Q_strcat(local_104,&DAT_000e04bc);
  }
  if ((param_1[2] & 2) != 0) {
    Q_strcat(local_104,&DAT_000e04c1);
  }
  Q_strcat(local_104,&DAT_000e04c5);
  Con_Printf(&DAT_000e04c7,local_104);
  if (param_2 != 0) {
    FS_FPrintf(param_2,&DAT_000e04c7,local_104);
  }
  return;
}


// Cmd_CvarList_f  @ 0005c580
void Cmd_CvarList_f(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  int local_130;
  char local_120 [256];
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 *puStack_8;
  
  local_c = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_10 = Cmd_Argc();
  if (1 < local_10) {
    puVar3 = &DAT_000e04ca;
    uVar1 = Cmd_Argv(1);
    iVar2 = Q_strcasecmp(uVar1,puVar3);
    if (iVar2 == 0) {
      Con_Printf(
                "CvarList           : List all cvars\nCvarList [Partial] : List cvars starting with \'Partial\'\nCvarList log [Partial] : Logs cvars to file \"cvarlist.txt\" in the gamedir.\n"
                );
      return;
    }
    puVar3 = &DAT_000e0588;
    uVar1 = Cmd_Argv(1);
    iVar2 = Q_strcasecmp(uVar1,puVar3);
    if (iVar2 == 0) {
      local_130 = 0;
      while( true ) {
        if (99 < local_130) {
          FUN_0005c71c();
          return;
        }
        snprintf(local_120,0x100,"cvarlist%02d.txt",local_130);
        COM_FixSlashes(local_120);
        iVar2 = FS_Open(local_120,&DAT_000e059d);
        if (iVar2 == 0) break;
        FS_Close(iVar2);
        local_130 = local_130 + 1;
      }
      FUN_0005c71c();
      return;
    }
    puVar3 = &UNK_000e0621;
    uVar1 = Cmd_Argv(1);
    iVar2 = Q_stricmp(uVar1,puVar3);
    if (iVar2 == 0) {
      local_1c = 1;
    }
    else {
      puVar3 = &UNK_000e0624;
      uVar1 = Cmd_Argv(1);
      iVar2 = Q_stricmp(uVar1,puVar3);
      if (iVar2 == 0) {
        local_20 = 1;
      }
      else {
        local_14 = Cmd_Argv(1);
        local_18 = Q_strlen(local_14);
      }
    }
  }
  Con_Printf("CVar List\n--------------\n");
  for (puStack_8 = cvar_vars; puStack_8 != (undefined4 *)0x0; puStack_8 = (undefined4 *)puStack_8[4]
      ) {
    if (((local_1c == 0) || ((puStack_8[2] & 1) != 0)) &&
       ((local_20 == 0 || ((puStack_8[2] & 4) != 0)))) {
      if (local_14 == 0) {
        Cmd_CvarListPrintCvar(puStack_8,0);
        local_c = local_c + 1;
      }
      else {
        iVar2 = Q_strncasecmp(*puStack_8,local_14,local_18);
        if (iVar2 == 0) {
          Cmd_CvarListPrintCvar(puStack_8,0);
          local_c = local_c + 1;
        }
      }
    }
  }
  FUN_0005c920();
  return;
}


// Cmd_Echo_f  @ 00054348
void Cmd_Echo_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  local_8 = 1;
  while( true ) {
    iVar1 = Cmd_Argc();
    if (iVar1 <= local_8) break;
    uVar2 = Cmd_Argv(local_8);
    Con_Printf(&DAT_000df93f,uVar2);
    local_8 = local_8 + 1;
  }
  Con_Printf(&DAT_000df7e0);
  return;
}


// Cmd_Exec_f  @ 00054008
void Cmd_Exec_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int local_24;
  int local_10;
  int local_c;
  char *local_8;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    local_8 = (char *)Cmd_Argv(1);
    if (local_8 != (char *)0x0) {
      iVar1 = Q_strstr(local_8,&DAT_000df869);
      if (((iVar1 == 0) && (iVar1 = Q_strstr(local_8,&DAT_000df86b), iVar1 == 0)) &&
         (iVar1 = Q_strstr(local_8,&DAT_000df86d), iVar1 == 0)) {
        pcVar2 = strchr(local_8,0x2e);
        pcVar3 = strrchr(local_8,0x2e);
        if (pcVar2 == pcVar3) {
          puVar5 = &DAT_000df8a4;
          uVar4 = COM_FileExtension(local_8);
          iVar1 = Q_strcmp(uVar4,puVar5);
          if (iVar1 != 0) {
            puVar5 = &DAT_000df8a8;
            uVar4 = COM_FileExtension(local_8);
            iVar1 = Q_strcmp(uVar4,puVar5);
            if (iVar1 != 0) {
              Con_Printf("exec %s: not a .cfg or .rc file\n",local_8);
              return;
            }
          }
          local_c = COM_LoadFileForMe(local_8,&local_10);
          if (local_c == 0) {
            iVar1 = Q_strstr(local_8,"autoexec.cfg");
            if (((iVar1 == 0) && (iVar1 = Q_strstr(local_8,"userconfig.cfg"), iVar1 == 0)) &&
               ((iVar1 = Q_strstr(local_8,"hw/opengl.cfg"), iVar1 == 0 &&
                ((iVar1 = Q_strstr(local_8,"joystick.cfg"), iVar1 == 0 &&
                 (iVar1 = Q_strstr(local_8,"game.cfg"), iVar1 == 0)))))) {
              Con_Printf("couldn\'t exec %s\n",local_8);
            }
          }
          else {
            Con_DPrintf("execing %s\n",local_8);
            if (cmd_text._16_4_ + local_10 + 2 < (int)cmd_text._12_4_) {
              Cbuf_InsertTextLines(local_c);
            }
            else {
              local_24 = local_c;
              while( true ) {
                Cbuf_Execute();
                local_24 = COM_ParseLine(local_24);
                iVar1 = Q_strlen(&com_token);
                if (iVar1 < 1) break;
                Cbuf_InsertTextLines(&com_token);
              }
            }
            Mem_Free(local_c);
          }
        }
        else {
          Con_Printf("exec %s: invalid filename.\n",local_8);
        }
      }
      else {
        Con_Printf("exec %s: invalid path.\n",local_8);
      }
    }
  }
  else {
    Con_Printf("exec <filename> : execute a script file\n");
  }
  return;
}


// Cmd_ExecuteString  @ 0005522c
void Cmd_ExecuteString(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *local_c;
  undefined4 *local_8;
  
  cmd_source = param_2;
  Cmd_TokenizeString(param_1);
  iVar1 = Cmd_Argc();
  if (iVar1 != 0) {
    for (local_8 = cmd_functions; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
      iVar1 = Q_strcasecmp(cmd_argv,local_8[1]);
      if (iVar1 == 0) {
        (*(code *)local_8[2])();
        if (DAT_002fe000 == 0) {
          return;
        }
        if ((local_8[3] & 1) == 0) {
          return;
        }
        if (DAT_002fe330 != 0) {
          return;
        }
        CL_RecordHUDCommand(local_8[1]);
        return;
      }
    }
    for (local_c = cmd_alias; local_c != (undefined4 *)0x0; local_c = (undefined4 *)*local_c) {
      iVar1 = Q_strcasecmp(cmd_argv,local_c + 1);
      if (iVar1 == 0) {
        Cbuf_InsertText(local_c[9]);
        return;
      }
    }
    iVar1 = Cvar_Command();
    if ((iVar1 == 0) && (((cls == 5 || (cls == 3)) || (cls == 4)))) {
      Cmd_ForwardToServer();
    }
  }
  return;
}


// Cmd_Exists  @ 00054f50
undefined4 Cmd_Exists(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = cmd_functions;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return 0;
    }
    iVar1 = Q_strcmp(param_1,local_8[1]);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)*local_8;
  }
  return 1;
}


// Cmd_FindCmd  @ 00054a68
undefined4 * Cmd_FindCmd(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = cmd_functions;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = Q_strcmp(param_1,local_8[1]);
    if (iVar1 == 0) break;
    local_8 = (undefined4 *)*local_8;
  }
  return local_8;
}


// Cmd_FindCmdPrev  @ 00054acc
int * Cmd_FindCmdPrev(undefined4 param_1)

{
  int iVar1;
  int *local_8;
  
  local_8 = cmd_functions;
  while( true ) {
    if (*local_8 == 0) {
      return (int *)0x0;
    }
    iVar1 = Q_strcmp(param_1,*(undefined4 *)(*local_8 + 4));
    if (iVar1 == 0) break;
    local_8 = (int *)*local_8;
  }
  return local_8;
}


// Cmd_ForwardToServer  @ 00055574
undefined4 Cmd_ForwardToServer(void)

{
  undefined4 uVar1;
  
  uVar1 = Cmd_ForwardToServerInternal(&DAT_002f9ffc);
  return uVar1;
}


// Cmd_ForwardToServerInternal  @ 00055390
undefined4 Cmd_ForwardToServerInternal(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined1 local_1018 [4096];
  char *local_18;
  uint local_14;
  undefined1 *local_10;
  undefined4 local_c;
  int local_8;
  
  local_18 = "Cmd_ForwardToServerInternal::tempBuf";
  local_14 = CONCAT22(local_14._2_2_,1);
  local_10 = local_1018;
  local_c = 0x1000;
  local_8 = 0;
  if (((cls == 3) || (cls == 4)) || (cls == 5)) {
    if (DAT_002fe004 == 0) {
      if (isDedicated == 0) {
        MSG_WriteByte(&local_18,3);
        puVar4 = &DAT_000df998;
        uVar1 = Cmd_Argv(0);
        iVar2 = Q_strcasecmp(uVar1,puVar4);
        if (iVar2 != 0) {
          uVar1 = Cmd_Argv(0);
          SZ_Print(&local_18,uVar1);
          SZ_Print(&local_18,&DAT_000df82d);
        }
        iVar2 = Cmd_Argc();
        if (iVar2 < 2) {
          SZ_Print(&local_18,&DAT_000df7e0);
        }
        else {
          uVar1 = Cmd_Args();
          SZ_Print(&local_18,uVar1);
        }
        if ((local_14 & 2) == 0) {
          if (*(int *)(param_1 + 0xc) < local_8 + *(int *)(param_1 + 0x10)) {
            uVar1 = 0;
          }
          else {
            SZ_Write(param_1,local_10,local_8);
            uVar1 = 1;
          }
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    pcVar3 = "setinfo";
    uVar1 = Cmd_Argv(0);
    iVar2 = Q_stricmp(uVar1,pcVar3);
    if (iVar2 != 0) {
      uVar1 = Cmd_Argv(0);
      Con_Printf("Can\'t \"%s\", not connected\n",uVar1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


// Cmd_ForwardToServerUnreliable  @ 000555ac
undefined4 Cmd_ForwardToServerUnreliable(void)

{
  undefined4 uVar1;
  
  uVar1 = Cmd_ForwardToServerInternal(&DAT_002fc3b8);
  return uVar1;
}


// Cmd_GetFirstCmd  @ 000546b4
undefined4 Cmd_GetFirstCmd(void)

{
  return cmd_functions;
}


// Cmd_Init  @ 000546d8
void Cmd_Init(void)

{
  Cmd_AddCommand("stuffcmds",Cmd_StuffCmds_f);
  Cmd_AddCommand(FUN_000df988,Cmd_Exec_f);
  Cmd_AddCommand(&DAT_000df98d,Cmd_Echo_f);
  Cmd_AddCommand("alias",Cmd_Alias_f);
  Cmd_AddCommand(&DAT_000df998,Cmd_ForwardToServer);
  Cmd_AddCommand(&DAT_000df99c,Cmd_Wait_f);
  Cmd_AddCommand("cmdlist",Cmd_CmdList_f);
  return;
}


// Cmd_RemoveGameCmds  @ 00054f00
void Cmd_RemoveGameCmds(void)

{
  Cmd_RemoveMallocedCmds(2);
  return;
}


// Cmd_RemoveHudCmds  @ 00054ed8
void Cmd_RemoveHudCmds(void)

{
  Cmd_RemoveMallocedCmds(1);
  return;
}


// Cmd_RemoveMallocedCmds  @ 00054e54
void Cmd_RemoveMallocedCmds(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  local_c = cmd_functions;
  while (local_c != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_c;
    if ((local_c[3] & param_1) == 0) {
      *local_c = local_8;
      local_8 = local_c;
      local_c = puVar1;
    }
    else {
      Mem_Free(local_c);
      local_c = puVar1;
    }
  }
  cmd_functions = local_8;
  return;
}


// Cmd_RemoveWrapperCmds  @ 00054f28
void Cmd_RemoveWrapperCmds(void)

{
  Cmd_RemoveMallocedCmds(4);
  return;
}


// Cmd_Shutdown  @ 000547c0
void Cmd_Shutdown(void)

{
  cmd_functions = 0;
  cmd_argc = 0;
  memset(&cmd_argv,0,0x140);
  cmd_args = 0;
  return;
}


// Cmd_StuffCmds_f  @ 00053d54
void Cmd_StuffCmds_f(void)

{
  char cVar1;
  int iVar2;
  char *__s;
  char *__s_00;
  size_t sVar3;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 1) {
    local_10 = 0;
    for (local_8 = 1; local_8 < com_argc; local_8 = local_8 + 1) {
      if (*(int *)(com_argv + local_8 * 4) != 0) {
        iVar2 = Q_strlen(*(undefined4 *)(com_argv + local_8 * 4));
        local_10 = iVar2 + local_10 + 1;
      }
    }
    if (local_10 != 0) {
      __s = (char *)Z_Malloc(local_10 + 1);
      *__s = '\0';
      for (local_8 = 1; local_8 < com_argc; local_8 = local_8 + 1) {
        if (*(int *)(com_argv + local_8 * 4) != 0) {
          sVar3 = strlen(__s);
          strncat(__s,*(char **)(com_argv + local_8 * 4),(local_10 - sVar3) - 1);
          if (local_8 != com_argc + -1) {
            Q_strcat(__s,&DAT_000df82d);
          }
        }
      }
      __s_00 = (char *)Z_Malloc(local_10 + 1);
      *__s_00 = '\0';
      for (local_8 = 0; local_8 < local_10 + -1; local_8 = local_8 + 1) {
        if (__s[local_8] == '+') {
          for (local_c = local_8 + 1;
              ((__s[local_c] != '+' && (__s[local_c] != '-')) && (__s[local_c] != '\0'));
              local_c = local_c + 1) {
          }
          cVar1 = __s[local_c];
          __s[local_c] = '\0';
          sVar3 = strlen(__s_00);
          strncat(__s_00,__s + local_8 + 1,(local_10 - sVar3) - 2);
          Q_strcat(__s_00,&DAT_000df7e0);
          __s[local_c] = cVar1;
          local_8 = local_c + -1;
        }
      }
      if (*__s_00 != '\0') {
        Cbuf_InsertText(__s_00);
      }
      Z_Free(__s);
      Z_Free(__s_00);
    }
  }
  else {
    Con_Printf("stuffcmds : execute command line parameters\n");
  }
  return;
}


// Cmd_TokenizeString  @ 000548e0
void Cmd_TokenizeString(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  for (local_8 = 0; local_8 < cmd_argc; local_8 = local_8 + 1) {
    Z_Free((&cmd_argv)[local_8]);
  }
  cmd_argc = 0;
  cmd_args = (char *)0x0;
  while( true ) {
    for (; ((*param_1 != '\0' && (*param_1 < '!')) && (*param_1 != '\n')); param_1 = param_1 + 1) {
    }
    if ((*param_1 == '\n') || (*param_1 == '\0')) {
      return;
    }
    if (cmd_argc == 1) {
      cmd_args = param_1;
    }
    param_1 = (char *)COM_Parse(param_1);
    if (param_1 == (char *)0x0) break;
    iVar1 = Q_strlen(&com_token);
    if (0x203 < iVar1 + 1) {
      return;
    }
    if (cmd_argc < 0x50) {
      uVar2 = Z_Malloc(iVar1 + 1);
      (&cmd_argv)[cmd_argc] = uVar2;
      Q_strcpy((&cmd_argv)[cmd_argc],&com_token);
      cmd_argc = cmd_argc + 1;
    }
  }
  return;
}


// Cmd_Wait_f  @ 000538ac
void Cmd_Wait_f(void)

{
  cmd_wait = 1;
  return;
}


