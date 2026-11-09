// Cmd_AddCommand  @ 0009b600
void Cmd_AddCommand(char *cmd_name,xcommand_t function)

{
  Cmd_AddCommandWithFlags(cmd_name,function,0);
  return;
}


// Cmd_AddCommandWithFlags  @ 0009b3b0
void Cmd_AddCommandWithFlags(char *cmd_name,xcommand_t function,int flags)

{
  char *pcVar1;
  cmd_function_s *pcVar2;
  int iVar3;
  cmd_function_t *pcVar4;
  cmd_function_t *pcVar5;
  cmd_function_t local_2c;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???] */
  if (host_initialized != false) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar1 = Cvar_VariableString(cmd_name);
  pcVar4 = cmd_functions;
  if (*pcVar1 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n");
    return;
  }
  for (; pcVar4 != (cmd_function_t *)0x0; pcVar4 = pcVar4->next) {
    iVar3 = Q_strcmp(cmd_name,pcVar4->name);
    if (iVar3 == 0) {
      Con_Printf("Cmd_AddCommand: %s already defined\n");
      return;
    }
  }
  pcVar2 = Hunk_Alloc(0x10);
  local_2c.name = " ";
  pcVar2->name = cmd_name;
  if (function == (xcommand_t)0x0) {
    function = Cmd_ForwardToServer;
  }
  pcVar2->function = function;
  local_2c.next = cmd_functions;
  pcVar2->flags = flags;
  pcVar4 = &local_2c;
  pcVar5 = local_2c.next;
  while( true ) {
    if (pcVar5 == (cmd_function_t *)0x0) {
      pcVar4->next = pcVar2;
      pcVar2->next = (cmd_function_s *)0x0;
      cmd_functions = local_2c.next;
      return;
    }
    iVar3 = strcasecmp(pcVar5->name,cmd_name);
    if (0 < iVar3) break;
    pcVar4 = pcVar5;
    pcVar5 = pcVar5->next;
  }
  pcVar4->next = pcVar2;
  pcVar2->next = pcVar5;
  cmd_functions = local_2c.next;
  return;
}


// Cmd_AddGameCommand  @ 0009b870
void Cmd_AddGameCommand(char *cmd_name,xcommand_t function)

{
  char *pcVar1;
  int iVar2;
  cmd_function_t *pcVar3;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
  pcVar1 = Cvar_VariableString(cmd_name);
  pcVar3 = cmd_functions;
  if (*pcVar1 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n");
    return;
  }
  while( true ) {
    if (pcVar3 == (cmd_function_t *)0x0) {
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
      pcVar3 = Mem_ZeroMalloc(0x10);
      if (function == (xcommand_t)0x0) {
        function = Cmd_ForwardToServer;
      }
      pcVar3->name = cmd_name;
      pcVar3->next = cmd_functions;
      pcVar3->function = function;
      pcVar3->flags = 2;
      cmd_functions = pcVar3;
      return;
    }
    iVar2 = Q_strcmp(cmd_name,pcVar3->name);
    if (iVar2 == 0) break;
    pcVar3 = pcVar3->next;
  }
  Con_Printf("Cmd_AddCommand: %s already defined\n");
  return;
}


// Cmd_AddHUDCommand  @ 0009b6f0
void Cmd_AddHUDCommand(char *cmd_name,xcommand_t function)

{
  char *pcVar1;
  int iVar2;
  cmd_function_t *pcVar3;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
  pcVar1 = Cvar_VariableString(cmd_name);
  pcVar3 = cmd_functions;
  if (*pcVar1 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n");
    return;
  }
  while( true ) {
    if (pcVar3 == (cmd_function_t *)0x0) {
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
      pcVar3 = Mem_ZeroMalloc(0x10);
      if (function == (xcommand_t)0x0) {
        function = Cmd_ForwardToServer;
      }
      pcVar3->name = cmd_name;
      pcVar3->next = cmd_functions;
      pcVar3->function = function;
      pcVar3->flags = 1;
      cmd_functions = pcVar3;
      return;
    }
    iVar2 = Q_strcmp(cmd_name,pcVar3->name);
    if (iVar2 == 0) break;
    pcVar3 = pcVar3->next;
  }
  Con_Printf("Cmd_AddCommand: %s already defined\n");
  return;
}


// Cmd_AddMallocCommand  @ 0009b630
void Cmd_AddMallocCommand(char *cmd_name,xcommand_t function,int flag)

{
  char *pcVar1;
  int iVar2;
  cmd_function_t *pcVar3;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
  pcVar1 = Cvar_VariableString(cmd_name);
  pcVar3 = cmd_functions;
  if (*pcVar1 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n");
    return;
  }
  while( true ) {
    if (pcVar3 == (cmd_function_t *)0x0) {
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
      pcVar3 = Mem_ZeroMalloc(0x10);
      if (function == (xcommand_t)0x0) {
        function = Cmd_ForwardToServer;
      }
      pcVar3->name = cmd_name;
      pcVar3->next = cmd_functions;
      pcVar3->function = function;
      pcVar3->flags = flag;
      cmd_functions = pcVar3;
      return;
    }
    iVar2 = Q_strcmp(cmd_name,pcVar3->name);
    if (iVar2 == 0) break;
    pcVar3 = pcVar3->next;
  }
  Con_Printf("Cmd_AddCommand: %s already defined\n");
  return;
}


// Cmd_AddWrapperCommand  @ 0009b7b0
void Cmd_AddWrapperCommand(char *cmd_name,xcommand_t function)

{
  char *pcVar1;
  int iVar2;
  cmd_function_t *pcVar3;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
  pcVar1 = Cvar_VariableString(cmd_name);
  pcVar3 = cmd_functions;
  if (*pcVar1 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n");
    return;
  }
  while( true ) {
    if (pcVar3 == (cmd_function_t *)0x0) {
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
      pcVar3 = Mem_ZeroMalloc(0x10);
      if (function == (xcommand_t)0x0) {
        function = Cmd_ForwardToServer;
      }
      pcVar3->name = cmd_name;
      pcVar3->next = cmd_functions;
      pcVar3->function = function;
      pcVar3->flags = 4;
      cmd_functions = pcVar3;
      return;
    }
    iVar2 = Q_strcmp(cmd_name,pcVar3->name);
    if (iVar2 == 0) break;
    pcVar3 = pcVar3->next;
  }
  Con_Printf("Cmd_AddCommand: %s already defined\n");
  return;
}


// Cmd_Alias_f  @ 0009a920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Alias_f(void)

{
  int iVar1;
  cvar_t *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  cmdalias_s *pcVar6;
  uint *puVar7;
  uint *puVar8;
  char *pcVar9;
  uint uVar10;
  int in_GS_OFFSET;
  uint local_428;
  uint local_424;
  uint local_420 [256];
  int local_20;
  
                    /* Unresolved local var: cmdalias_t * a@[???]
                       Unresolved local var: char[1024] cmd@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: cvar_t * cv@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engdstAddrs.Cmd_Argc)();
  if (cmd_argc == 1) {
    Con_Printf("Current alias commands:\n");
    for (pcVar6 = cmd_alias; pcVar6 != (cmdalias_t *)0x0; pcVar6 = pcVar6->next) {
      Con_Printf("%s : %s\n",pcVar6->name,pcVar6->value);
    }
  }
  else {
    pcVar9 = "";
    local_428 = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)&local_428);
    if (local_428 < (uint)cmd_argc) {
      pcVar9 = cmd_argv[local_428];
      iVar1 = Q_strlen(pcVar9);
    }
    else {
      iVar1 = Q_strlen("");
    }
    if (iVar1 < 0x20) {
      pcVar2 = Cvar_FindVar(pcVar9);
      if ((pcVar2 == (cvar_t *)0x0) &&
         ((((SetCStrikeFlags(), g_bIsCStrike == 0 && (g_bIsCZero == 0)) ||
           (((iVar1 = strcasecmp(pcVar9,"cl_autobuy"), iVar1 != 0 &&
             (((iVar1 = strcasecmp(pcVar9,"cl_rebuy"), iVar1 != 0 &&
               (iVar1 = strcasecmp(pcVar9,"gl_ztrick"), iVar1 != 0)) &&
              (iVar1 = strcasecmp(pcVar9,"gl_ztrick_old"), iVar1 != 0)))) &&
            (iVar1 = strcasecmp(pcVar9,"gl_d3dflip"), iVar1 != 0)))) &&
          ((iVar1 = strcasecmp(pcVar9,"_special"), iVar1 != 0 &&
           (iVar1 = strcasecmp(pcVar9,"special"), iVar1 != 0)))))) {
        local_420[0]._0_1_ = 0;
        (*g_engdstAddrs.Cmd_Argc)();
        iVar1 = cmd_argc;
        if (2 < cmd_argc) {
          uVar10 = 2;
          puVar8 = local_420;
          do {
            do {
              puVar7 = puVar8;
              uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
              uVar4 = uVar3 & 0x80808080;
              puVar8 = puVar7 + 1;
            } while (uVar4 == 0);
            if ((uVar3 & 0x8080) == 0) {
              puVar8 = (uint *)((int)puVar7 + 6);
              uVar4 = uVar4 >> 0x10;
            }
            local_424 = uVar10;
            (*g_engdstAddrs.Cmd_Argv)((int *)&local_424);
            pcVar5 = "";
            if (local_424 < (uint)cmd_argc) {
              pcVar5 = cmd_argv[local_424];
            }
            __strncat_chk(local_420,pcVar5,
                          0x3fe - ((int)puVar8 +
                                  ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_420)),
                          0x400);
            puVar8 = local_420;
            do {
              puVar7 = puVar8;
              uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
              uVar4 = uVar3 & 0x80808080;
              puVar8 = puVar7 + 1;
            } while (uVar4 == 0);
            if ((uVar3 & 0x8080) == 0) {
              puVar8 = (uint *)((int)puVar7 + 6);
              uVar4 = uVar4 >> 0x10;
            }
            uVar10 = uVar10 + 1;
            __strncat_chk(local_420,&DAT_0027beaa,
                          0x3fe - ((int)puVar8 +
                                  ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_420)),
                          0x400);
            puVar8 = local_420;
          } while (uVar10 != iVar1);
        }
        Q_strcat((char *)local_420,"\n");
        for (pcVar6 = cmd_alias; pcVar6 != (cmdalias_t *)0x0; pcVar6 = pcVar6->next) {
          pcVar5 = pcVar6->name;
          iVar1 = Q_strcmp(pcVar9,pcVar5);
          if (iVar1 == 0) {
            iVar1 = Q_strcmp(pcVar6->value,(char *)local_420);
            if (iVar1 == 0) goto LAB_0009a9b4;
            Z_Free(pcVar6->value);
            goto LAB_0009ac9f;
          }
        }
        pcVar6 = Z_Malloc(0x28);
        pcVar5 = pcVar6->name;
        pcVar6->next = cmd_alias;
        cmd_alias = pcVar6;
LAB_0009ac9f:
        Q_strncpy(pcVar5,pcVar9,0x1f);
        pcVar6->name[0x1f] = '\0';
                    /* Unresolved local var: char * out@[???] */
        iVar1 = Q_strlen((char *)local_420);
        pcVar9 = Z_Malloc(iVar1 + 1);
        Q_strcpy(pcVar9,(char *)local_420);
        pcVar6->value = pcVar9;
      }
      else {
        Con_Printf("Alias name is invalid\n");
      }
    }
    else {
      Con_Printf("Alias name is too long\n");
    }
  }
LAB_0009a9b4:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Cmd_Argc  @ 0009b1a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cmd_Argc(void)

{
  (*g_engdstAddrs.Cmd_Argc)();
  return cmd_argc;
}


// Cmd_Args  @ 0009b1f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Cmd_Args(void)

{
  return cmd_args;
}


// Cmd_Argv  @ 0009b1c0
char * Cmd_Argv(int arg)

{
  char *pcVar1;
  
  (*g_engdstAddrs.Cmd_Argv)(&arg);
  pcVar1 = "";
  if ((uint)arg < (uint)cmd_argc) {
    pcVar1 = cmd_argv[arg];
  }
  return pcVar1;
}


// Cmd_CheckParm  @ 0009c8a0
int Cmd_CheckParm(char *parm)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint local_10;
  
                    /* Unresolved local var: int i@[???] */
  if (parm == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Cmd_CheckParm: NULL");
  }
  uVar3 = 1;
  while( true ) {
    (*g_engdstAddrs.Cmd_Argc)();
    if (cmd_argc <= (int)uVar3) {
      return 0;
    }
    local_10 = uVar3;
    (*g_engdstAddrs.Cmd_Argv)((int *)&local_10);
    pcVar1 = "";
    if (local_10 < (uint)cmd_argc) {
      pcVar1 = cmd_argv[local_10];
    }
    iVar2 = Q_strcasecmp(parm,pcVar1);
    if (iVar2 == 0) break;
    uVar3 = uVar3 + 1;
  }
  return uVar3;
}


// Cmd_CmdList_f  @ 0009a130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_CmdList_f(void)

{
  bool bVar1;
  cmd_function_s **ppcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  cmd_function_s *pcVar6;
  int unaff_EDI;
  int in_GS_OFFSET;
  bool bVar7;
  FileHandle_t local_140;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: int iCmds@[???]
                       Unresolved local var: int iArgs@[???]
                       Unresolved local var: char * partial@[???]
                       Unresolved local var: int ipLen@[???]
                       Unresolved local var: FileHandle_t f@[???]
                       Unresolved local var: qboolean bLogging@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engdstAddrs.Cmd_Argc)();
  iVar5 = cmd_argc;
  if (cmd_argc < 2) {
    Con_Printf("Command List\n--------------\n");
    bVar7 = false;
    if (cmd_functions != (cmd_function_t *)0x0) {
LAB_0009a30f:
      iVar5 = 0;
      pcVar6 = cmd_functions;
      do {
        iVar5 = iVar5 + 1;
        Con_Printf("%-16.16s\n",pcVar6->name);
        pcVar6 = pcVar6->next;
      } while (pcVar6 != (cmd_function_s *)0x0);
      bVar1 = false;
      pcVar3 = (char *)0x0;
      goto LAB_0009a350;
    }
    iVar5 = 0;
    bVar1 = false;
LAB_0009a360:
    Con_Printf("--------------\n%3i Total Commands\nCmdList ? for syntax\n",iVar5);
  }
  else {
    local_130 = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)&local_130);
    pcVar3 = "";
    if (local_130 < (uint)cmd_argc) {
      pcVar3 = cmd_argv[local_130];
    }
    iVar4 = Q_strcasecmp(pcVar3,&LAB_00255a7a);
    if (iVar4 == 0) {
      Con_Printf(
                "CmdList           : List all commands\nCmdList [Partial] : List commands starting with \'Partial\'\nCmdList log [Partial] : Logs commands to file \"cmdlist.txt\" in the gamedir.\n"
                );
      goto LAB_0009a2cc;
    }
    local_12c = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)&local_12c);
    pcVar3 = "";
    if (local_12c < (uint)cmd_argc) {
      pcVar3 = cmd_argv[local_12c];
    }
    iVar4 = Q_strcasecmp(pcVar3,"log");
    if (iVar4 == 0) {
                    /* Unresolved local var: char[256] szTemp@[???] */
      builtin_strncpy(local_120,"cmdlist.txt",0xc);
      local_140 = FS_Open(local_120,"wt");
      if (local_140 == (FileHandle_t)0x0) {
        Con_Printf("Couldn\'t open [%s] for writing!\n",local_120);
        goto LAB_0009a2cc;
      }
      if (iVar5 == 3) {
        pcVar3 = "";
        local_128 = 2;
        (*g_engdstAddrs.Cmd_Argv)((int *)&local_128);
        if (local_128 < (uint)cmd_argc) {
          pcVar3 = cmd_argv[local_128];
        }
        unaff_EDI = Q_strlen(pcVar3);
      }
      else {
        pcVar3 = (char *)0x0;
      }
      iVar5 = 0;
      Con_Printf("Command List\n--------------\n");
      bVar7 = false;
      bVar1 = true;
      if (cmd_functions == (cmd_function_t *)0x0) goto LAB_0009a360;
LAB_0009a25a:
      iVar5 = 0;
      if (pcVar3 == (char *)0x0) {
        pcVar6 = cmd_functions;
        if (!bVar1) goto LAB_0009a30f;
        do {
          iVar5 = iVar5 + 1;
          Con_Printf("%-16.16s\n",pcVar6->name);
          FS_FPrintf(local_140,"%-16.16s\n",pcVar6->name);
          ppcVar2 = &pcVar6->next;
          pcVar6 = *ppcVar2;
        } while (*ppcVar2 != (cmd_function_s *)0x0);
      }
      else {
        pcVar6 = cmd_functions;
        if (!bVar1) {
          do {
            iVar4 = Q_strncasecmp(pcVar6->name,pcVar3,unaff_EDI);
            if (iVar4 == 0) {
              iVar5 = iVar5 + 1;
              Con_Printf("%-16.16s\n",pcVar6->name);
            }
            pcVar6 = pcVar6->next;
          } while (pcVar6 != (cmd_function_s *)0x0);
          goto LAB_0009a350;
        }
        do {
          while (iVar4 = Q_strncasecmp(pcVar6->name,pcVar3,unaff_EDI), iVar4 != 0) {
            ppcVar2 = &pcVar6->next;
            pcVar6 = *ppcVar2;
            if (*ppcVar2 == (cmd_function_s *)0x0) goto LAB_0009a455;
          }
          iVar5 = iVar5 + 1;
          Con_Printf("%-16.16s\n",pcVar6->name);
          FS_FPrintf(local_140,"%-16.16s\n",pcVar6->name);
          ppcVar2 = &pcVar6->next;
          pcVar6 = *ppcVar2;
        } while (*ppcVar2 != (cmd_function_s *)0x0);
      }
LAB_0009a455:
      bVar1 = true;
    }
    else {
      local_124 = 1;
      (*g_engdstAddrs.Cmd_Argv)((int *)&local_124);
      if (local_124 < (uint)cmd_argc) {
        pcVar3 = cmd_argv[local_124];
        bVar7 = pcVar3 != (char *)0x0;
      }
      else {
        bVar7 = true;
        pcVar3 = "";
      }
      unaff_EDI = Q_strlen(pcVar3);
      bVar7 = (bool)(iVar5 == 2 & bVar7);
      Con_Printf("Command List\n--------------\n");
      bVar1 = false;
      if (cmd_functions != (cmd_function_t *)0x0) goto LAB_0009a25a;
      iVar5 = 0;
    }
LAB_0009a350:
    if ((!bVar7) || (*pcVar3 == '\0')) goto LAB_0009a360;
    Con_Printf("--------------\n%3i Commands for [%s]\nCmdList ? for syntax\n",iVar5,pcVar3);
  }
  if (bVar1) {
    FS_Close(local_140);
  }
LAB_0009a2cc:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Cmd_CompleteCommand  @ 0009bac0
char * Cmd_CompleteCommand(char *search,int forward)

{
  char cVar1;
  char *s1;
  int iVar2;
  cmd_function_s *pcVar3;
  int count;
  int iVar4;
  char *pcVar5;
  cmd_function_s *pcVar6;
  cmd_function_s *pcVar7;
  int in_GS_OFFSET;
  char acStack_121 [256];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[256] partial@[???]
                       Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char * pPartial@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar5 = acStack_121 + 1;
  Q_strncpy(pcVar5,search,0xff);
  local_21 = 0;
  count = Q_strlen(pcVar5);
  if (count != 0) {
    cVar1 = acStack_121[count];
    iVar4 = count + -1;
    while (iVar2 = iVar4, cVar1 == ' ') {
      pcVar5[iVar2] = '\0';
      iVar4 = iVar2 + -1;
      count = iVar2;
      cVar1 = pcVar5[iVar2 + -1];
    }
    iVar4 = Q_stricmp(pcVar5,Cmd_CompleteCommand::lastpartial);
    pcVar3 = cmd_functions;
    if (iVar4 != 0) goto joined_r0x0009bb58;
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
    pcVar7 = cmd_functions;
    if (cmd_functions != (cmd_function_t *)0x0) {
      do {
        iVar4 = Q_strcmp(pcVar5,pcVar7->name);
        pcVar3 = cmd_functions;
        if (iVar4 == 0) {
          if (forward == 1) {
            pcVar7 = pcVar7->next;
            goto LAB_0009bc4a;
          }
          s1 = pcVar7->name;
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
          pcVar6 = cmd_functions->next;
          pcVar7 = cmd_functions;
          if (pcVar6 != (cmd_function_s *)0x0) goto LAB_0009bc28;
          break;
        }
        pcVar7 = pcVar7->next;
      } while (pcVar7 != (cmd_function_s *)0x0);
      goto joined_r0x0009bb58;
    }
  }
LAB_0009bbb7:
  pcVar5 = (char *)0x0;
  goto LAB_0009bbb9;
  while( true ) {
    pcVar7 = pcVar7->next;
    pcVar6 = pcVar7->next;
    pcVar3 = cmd_functions;
    if (pcVar6 == (cmd_function_s *)0x0) break;
LAB_0009bc28:
    iVar4 = Q_strcmp(s1,pcVar6->name);
    if (iVar4 == 0) goto LAB_0009bc4a;
  }
joined_r0x0009bb58:
  do {
    pcVar7 = pcVar3;
    if (pcVar7 == (cmd_function_s *)0x0) goto LAB_0009bbb7;
    iVar4 = Q_strncmp(pcVar5,pcVar7->name,count);
    if (iVar4 == 0) {
      iVar4 = Q_strlen(pcVar7->name);
      if (iVar4 == count) goto LAB_0009bc4e;
      pcVar5 = pcVar7->name;
      Q_strncpy(Cmd_CompleteCommand::lastpartial,pcVar5,0xff);
      Cmd_CompleteCommand::lastpartial[0xff] = '\0';
      goto LAB_0009bbb9;
    }
    pcVar3 = pcVar7->next;
  } while( true );
LAB_0009bc4a:
  pcVar3 = cmd_functions;
  if (pcVar7 == (cmd_function_s *)0x0) goto joined_r0x0009bb58;
LAB_0009bc4e:
  Q_strncpy(Cmd_CompleteCommand::lastpartial,pcVar7->name,0xff);
  Cmd_CompleteCommand::lastpartial[0xff] = '\0';
  pcVar5 = pcVar7->name;
LAB_0009bbb9:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pcVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Cmd_CurrentCommandIsPrivileged  @ 0009c930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Cmd_CurrentCommandIsPrivileged(void)

{
  return s_bCurrentCommandIsPrivileged;
}


// Cmd_CvarListPrintCvar  @ 000a7800
void Cmd_CvarListPrintCvar(cvar_t *var,FileHandle_t f)

{
  float fVar1;
  uint uVar2;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] szOutstr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  fVar1 = var->value;
  if (fVar1 == (float)(int)fVar1) {
    __snprintf_chk(local_110,0xf5,1,0x100,"%-15s : %8i",var->name,(int)fVar1);
    uVar2 = var->flags;
  }
  else {
    __snprintf_chk(local_110,0xf5,1,0x100,"%-15s : %8.3f",var->name,(double)fVar1);
    uVar2 = var->flags;
  }
  if ((uVar2 & 1) != 0) {
    Q_strcat(local_110,", a");
    uVar2 = var->flags;
  }
  if ((uVar2 & 4) != 0) {
    Q_strcat(local_110,", sv");
    uVar2 = var->flags;
  }
  if ((uVar2 & 2) != 0) {
    Q_strcat(local_110,", i");
  }
  Q_strcat(local_110,"\n");
  Con_Printf("%s",local_110);
  if (f != (FileHandle_t)0x0) {
    FS_FPrintf(f,"%s",local_110);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Cmd_CvarList_f  @ 000a79a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_CvarList_f(void)

{
  cvar_s **ppcVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  FileHandle_t file;
  int iVar6;
  bool bVar7;
  cvar_s *pcVar8;
  int in_GS_OFFSET;
  FileHandle_t local_134;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: cvar_t * var@[???]
                       Unresolved local var: int iCvars@[???]
                       Unresolved local var: int iArgs@[???]
                       Unresolved local var: char * partial@[???]
                       Unresolved local var: int ipLen@[???]
                       Unresolved local var: qboolean bAOnly@[???]
                       Unresolved local var: qboolean bSOnly@[???]
                       Unresolved local var: char[256] szTemp@[???]
                       Unresolved local var: FileHandle_t f@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: qboolean bLogging@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = Cmd_Argc();
  if (iVar3 < 2) {
    bVar2 = false;
    local_134 = (FileHandle_t)0x0;
LAB_000a7aec:
    Con_Printf("CVar List\n--------------\n");
    if (cvar_vars == (cvar_t *)0x0) goto LAB_000a7b06;
    bVar7 = false;
LAB_000a7bb5:
    iVar3 = 0;
    pcVar8 = cvar_vars;
    do {
      iVar3 = iVar3 + 1;
      Cmd_CvarListPrintCvar(pcVar8,local_134);
      pcVar8 = pcVar8->next;
    } while (pcVar8 != (cvar_s *)0x0);
    pcVar4 = (char *)0x0;
LAB_000a7be0:
    if ((!bVar7) || (*pcVar4 == '\0')) goto LAB_000a7b08;
    Con_Printf("--------------\n%3i CVars for [%s]\nCvarList ? for syntax\n",iVar3,pcVar4);
  }
  else {
    pcVar4 = Cmd_Argv(1);
    iVar5 = Q_strcasecmp(pcVar4,&LAB_00255a7a);
    if (iVar5 == 0) {
      Con_Printf(
                "CvarList           : List all cvars\nCvarList [Partial] : List cvars starting with \'Partial\'\nCvarList log [Partial] : Logs cvars to file \"cvarlist.txt\" in the gamedir.\n"
                );
      goto LAB_000a7abc;
    }
    pcVar4 = Cmd_Argv(1);
    iVar5 = Q_strcasecmp(pcVar4,"log");
    if (iVar5 == 0) {
      iVar5 = 0;
      do {
        __snprintf_chk(local_120,0x100,1,0x100,"cvarlist%02d.txt",iVar5);
        COM_FixSlashes(local_120);
        file = FS_Open(local_120,"r");
        if (file == (FileHandle_t)0x0) {
          local_134 = FS_Open(local_120,"wt");
          if (local_134 == (FileHandle_t)0x0) {
            Con_Printf("Couldn\'t open [%s] for writing!\n",local_120);
            goto LAB_000a7abc;
          }
          if (iVar3 == 3) {
            pcVar4 = Cmd_Argv(2);
            iVar5 = Q_strlen(pcVar4);
            bVar7 = false;
            bVar2 = true;
            goto LAB_000a7cce;
          }
          bVar2 = true;
          goto LAB_000a7aec;
        }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int found@[???] */
        iVar5 = iVar5 + 1;
        FS_Close(file);
      } while (iVar5 != 100);
      Con_Printf("Can\'t cvarlist! Too many existing cvarlist output files in the gamedir!\n");
      goto LAB_000a7abc;
    }
    pcVar4 = Cmd_Argv(1);
    iVar5 = Q_stricmp(pcVar4,"-a");
    if (iVar5 == 0) {
      Con_Printf("CVar List\n--------------\n");
      if (cvar_vars != (cvar_t *)0x0) {
        iVar3 = 0;
        pcVar8 = cvar_vars;
        do {
          if ((pcVar8->flags & 1) != 0) {
            iVar3 = iVar3 + 1;
            Cmd_CvarListPrintCvar(pcVar8,(FileHandle_t)0x0);
          }
          pcVar8 = pcVar8->next;
        } while (pcVar8 != (cvar_s *)0x0);
LAB_000a7c97:
        bVar2 = false;
        local_134 = (FileHandle_t)0x0;
        goto LAB_000a7b08;
      }
    }
    else {
      pcVar4 = Cmd_Argv(1);
      iVar5 = Q_stricmp(pcVar4,"-s");
      if (iVar5 != 0) {
        pcVar4 = Cmd_Argv(1);
        iVar5 = Q_strlen(pcVar4);
        bVar7 = pcVar4 != (char *)0x0 && iVar3 == 2;
        bVar2 = false;
        local_134 = (FileHandle_t)0x0;
LAB_000a7cce:
        Con_Printf("CVar List\n--------------\n");
        if (cvar_vars == (cvar_t *)0x0) {
          iVar3 = 0;
        }
        else {
          if (pcVar4 == (char *)0x0) goto LAB_000a7bb5;
          iVar3 = 0;
          pcVar8 = cvar_vars;
          do {
            iVar6 = Q_strncasecmp(pcVar8->name,pcVar4,iVar5);
            if (iVar6 == 0) {
              iVar3 = iVar3 + 1;
              Cmd_CvarListPrintCvar(pcVar8,local_134);
            }
            pcVar8 = pcVar8->next;
          } while (pcVar8 != (cvar_s *)0x0);
        }
        goto LAB_000a7be0;
      }
      iVar3 = 0;
      Con_Printf("CVar List\n--------------\n");
      pcVar8 = cvar_vars;
      if (cvar_vars != (cvar_t *)0x0) {
        do {
          if ((pcVar8->flags & 4) != 0) {
            iVar3 = iVar3 + 1;
            Cmd_CvarListPrintCvar(pcVar8,(FileHandle_t)0x0);
          }
          ppcVar1 = &pcVar8->next;
          pcVar8 = *ppcVar1;
        } while (*ppcVar1 != (cvar_s *)0x0);
        goto LAB_000a7c97;
      }
    }
    bVar2 = false;
    local_134 = (FileHandle_t)0x0;
LAB_000a7b06:
    iVar3 = 0;
LAB_000a7b08:
    Con_Printf("--------------\n%3i Total CVars\nCvarList ? for syntax\n",iVar3);
  }
  if (bVar2) {
    FS_Close(local_134);
    Con_Printf("cvarlist logged to %s\n",local_120);
  }
LAB_000a7abc:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Cmd_Echo_f  @ 0009a0c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Echo_f(void)

{
  char *pcVar1;
  uint uVar2;
  uint local_10 [2];
  
                    /* Unresolved local var: int i@[???] */
  uVar2 = 1;
  while( true ) {
    (*g_engdstAddrs.Cmd_Argc)();
    if (cmd_argc <= (int)uVar2) break;
    local_10[0] = uVar2;
    (*g_engdstAddrs.Cmd_Argv)((int *)local_10);
    pcVar1 = "";
    if (local_10[0] < (uint)cmd_argc) {
      pcVar1 = cmd_argv[local_10[0]];
    }
    uVar2 = uVar2 + 1;
    Con_Printf("%s ",pcVar1);
  }
  Con_Printf("\n");
  return;
}


// Cmd_Exec_f  @ 0009c3c0
/* WARNING: Removing unreachable block (ram,0x0009c565) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Exec_f(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  FileHandle_t file;
  uint size;
  char *pcVar5;
  undefined4 *puVar6;
  int in_GS_OFFSET;
  byte bVar7;
  uint local_2054;
  undefined4 *local_2050 [12];
  char local_2020 [4096];
  undefined4 local_1020 [1024];
  int local_20;
  
                    /* Unresolved local var: char * pszFileName@[???]
                       Unresolved local var: char * pszFileData@[???]
                       Unresolved local var: int nFileLength@[???]
                       Unresolved local var: char * pszFirstDot@[???]
                       Unresolved local var: char * pszLastDot@[???]
                       Unresolved local var: int nCurrentLen@[???]
                       Unresolved local var: int nAddLen@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2054 = 1;
  (*g_engdstAddrs.Cmd_Argv)((int *)&local_2054);
  if (local_2054 < (uint)cmd_argc) {
    pcVar5 = cmd_argv[local_2054];
    if (pcVar5 == (char *)0x0) goto LAB_0009c443;
  }
  else {
    pcVar5 = "";
  }
  pcVar1 = Q_strstr(pcVar5,"\\");
  if ((((pcVar1 == (char *)0x0) && (pcVar1 = Q_strstr(pcVar5,":"), pcVar1 == (char *)0x0)) &&
      (pcVar1 = Q_strstr(pcVar5,"~"), pcVar1 == (char *)0x0)) &&
     ((pcVar1 = Q_strstr(pcVar5,".."), pcVar1 == (char *)0x0 && (*pcVar5 != '/')))) {
    pcVar1 = strchr(pcVar5,0x2e);
    pcVar2 = strrchr(pcVar5,0x2e);
    if (pcVar1 == pcVar2) {
      pcVar1 = COM_LastFileExtension(pcVar5);
      iVar3 = Q_strcmp(pcVar1,"cfg");
      if (iVar3 != 0) {
        pcVar1 = COM_LastFileExtension(pcVar5);
        iVar3 = Q_strcmp(pcVar1,"rc");
        if (iVar3 != 0) {
          Con_Printf("exec %s: not a .cfg or .rc file\n",pcVar5);
          goto LAB_0009c443;
        }
      }
      if (s_bCurrentCommandIsPrivileged == false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[4096] pchBuf@[???]
                       Unresolved local var: char[4096] pchCurMapCfg@[???]
                       Unresolved local var: char *[12] rgpszUnprivilegedWhitelist@[???] */
        puVar6 = local_1020;
        for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
        }
        local_2050[0] = (undefined4 *)&LAB_0025561a;
        local_2050[1] = (undefined4 *)0x255629;
        local_2050[2] = (undefined4 *)0x255633;
        local_2050[3] = (undefined4 *)0x25563e;
        local_2050[4] = (undefined4 *)0x25564a;
        local_2050[5] = (undefined4 *)0x255656;
        local_2050[6] = (undefined4 *)&LAB_00255660;
        local_2050[7] = (undefined4 *)0x25566a;
        local_2050[8] = (undefined4 *)0x255673;
        local_2050[9] = (undefined4 *)0x25567b;
        local_2050[10] = (undefined4 *)0x255688;
        local_2050[0xb] = local_1020;
        pcVar1 = COM_FileBase_s(cl.levelname,local_2020,0x1000);
        if (pcVar1 != (char *)0x0) {
          __snprintf_chk(local_1020,0x1000,1,0x1000,0x255695,local_2020);
        }
        iVar3 = 0;
        do {
          iVar4 = Q_strcmp(pcVar5,(char *)local_2050[iVar3]);
          if (iVar4 == 0) goto LAB_0009c63a;
          iVar3 = iVar3 + 1;
        } while (iVar3 != 0xc);
        Con_Printf("exec %s: not privileged or in whitelist\n",pcVar5);
      }
      else {
LAB_0009c63a:
        file = FS_OpenPathID(pcVar5,"rb","GAMECONFIG");
        if (((file == (FileHandle_t)0x0) &&
            (file = FS_OpenPathID(pcVar5,"rb","GAME"), file == (FileHandle_t)0x0)) &&
           (file = FS_Open(pcVar5,"rb"), file == (FileHandle_t)0x0)) {
          pcVar1 = Q_strstr(pcVar5,"autoexec.cfg");
          if ((((pcVar1 == (char *)0x0) &&
               (pcVar1 = Q_strstr(pcVar5,"userconfig.cfg"), pcVar1 == (char *)0x0)) &&
              (pcVar1 = Q_strstr(pcVar5,"hw/opengl.cfg"), pcVar1 == (char *)0x0)) &&
             ((pcVar1 = Q_strstr(pcVar5,"joystick.cfg"), pcVar1 == (char *)0x0 &&
              (pcVar1 = Q_strstr(pcVar5,"game.cfg"), pcVar1 == (char *)0x0)))) {
            Con_Printf("couldn\'t exec %s\n",pcVar5);
          }
        }
        else {
          size = FS_Size(file);
          pcVar1 = Mem_Malloc(size + 1);
          if (pcVar1 == (char *)0x0) {
            Con_Printf("exec: not enough space for %s",pcVar5);
            FS_Close(file);
          }
          else {
            FS_Read(pcVar1,size,1,file);
            pcVar1[size] = '\0';
            FS_Close(file);
            Con_DPrintf("execing %s\n",pcVar5);
            pcVar5 = pcVar1;
            if ((int)(size + 2 + cmd_text.cursize) < cmd_text.maxsize) {
              Cbuf_InsertTextToBuffer(pcVar1,&cmd_text,true);
            }
            else {
              while( true ) {
                Cbuf_Execute();
                pcVar5 = COM_ParseLine(pcVar5);
                iVar3 = Q_strlen(com_token);
                if (iVar3 < 1) break;
                    /* Unresolved local var: char * pszDataPtr@[???] */
                Cbuf_InsertTextToBuffer(com_token,&cmd_text,true);
              }
            }
            Mem_Free(pcVar1);
          }
        }
      }
    }
    else {
      Con_Printf("exec %s: invalid filename.\n",pcVar5);
    }
  }
  else {
    Con_Printf("exec %s: invalid path.\n",pcVar5);
  }
LAB_0009c443:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Cmd_Exec_f  @ 0009c850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Exec_f(void)

{
                    /* Unresolved local var: char * pszFileName@[???]
                       Unresolved local var: char * pszFileData@[???]
                       Unresolved local var: int nFileLength@[???]
                       Unresolved local var: char * pszFirstDot@[???]
                       Unresolved local var: char * pszLastDot@[???]
                       Unresolved local var: int nCurrentLen@[???]
                       Unresolved local var: int nAddLen@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  (*g_engdstAddrs.Cmd_Argc)();
  if (cmd_argc != 2) {
    Con_Printf("exec <filename> : execute a script file\n");
    return;
  }
  Cmd_Exec_f();
  return;
}


// Cmd_ExecuteString  @ 0009c1c0
void Cmd_ExecuteString(char *text,cmd_source_t src)

{
  qboolean bIsPrivileged;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmdalias_t * a@[???] */
  cmd_source = src;
  Cmd_TokenizeString(text);
  (*g_engdstAddrs.Cmd_Argc)();
  if (cmd_argc != 0) {
    Cmd_ExecuteStringWithPrivilegeCheck(text,src_command,bIsPrivileged);
    return;
  }
  return;
}


// Cmd_ExecuteStringWithPrivilegeCheck  @ 0009bf80
void __regparm3
Cmd_ExecuteStringWithPrivilegeCheck(char *text,cmd_source_t src,qboolean bIsPrivileged)

{
  cmd_function_s *pcVar1;
  cmdalias_t *pcVar2;
  char *pcVar3;
  qboolean qVar4;
  char *pcVar5;
  int iVar6;
  sizebuf_t *buf;
  float fVar7;
  uint local_34;
  uint local_30 [3];
  undefined *local_24;
  undefined4 local_20;
  
  pcVar1 = cmd_functions;
  while( true ) {
    pcVar2 = cmd_alias;
    if (pcVar1 == (cmd_function_t *)0x0) {
      for (; pcVar2 != (cmdalias_t *)0x0; pcVar2 = pcVar2->next) {
        iVar6 = Q_strcasecmp(cmd_argv[0],pcVar2->name);
        if (iVar6 == 0) {
          buf = &cmd_text;
          if (src == src_client) {
            buf = &filteredcmd_text;
          }
          Cbuf_InsertTextToBuffer(pcVar2->value,buf,false);
          return;
        }
      }
      qVar4 = Cvar_CommandWithPrivilegeCheck(src);
      if (qVar4 != false) {
        return;
      }
      if (2 < cls.state - ca_connected) {
        return;
      }
      local_30[0] = 0;
      (*g_engdstAddrs.Cmd_Argv)((int *)local_30);
      pcVar5 = "";
      if (local_30[0] < (uint)cmd_argc) {
        pcVar5 = cmd_argv[local_30[0]];
      }
      iVar6 = Q_strcasecmp(pcVar5,0x2555d0);
      if (iVar6 == 0) {
        local_34 = 1;
        (*g_engdstAddrs.Cmd_Argv)((int *)&local_34);
        pcVar5 = "";
        if (local_34 < (uint)cmd_argc) {
          pcVar5 = cmd_argv[local_34];
        }
        iVar6 = Q_strcasecmp(pcVar5,&LAB_0025e3bc);
        if (iVar6 == 0) {
          return;
        }
      }
      Cmd_ForwardToServerInternal(&cls.netchan.message);
      return;
    }
    iVar6 = Q_strcasecmp(cmd_argv[0],pcVar1->name);
    if (iVar6 == 0) break;
    pcVar1 = pcVar1->next;
  }
  if (src == src_client) {
    if ((pcVar1->flags & 8) != 0) {
LAB_0009c198:
      Con_Printf("Could not execute privileged command %s\n",text);
      return;
    }
    fVar7 = Cvar_VariableValue("cl_filterstuffcmd");
    if (0.0 < fVar7) {
      if ((pcVar1->flags & 0x10) != 0) goto LAB_0009c198;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char *[5] rgpchFilterPrefixes@[???] */
      iVar6 = 0;
      local_30[0] = 0x2555d4;
      local_30[1] = 0x2555d8;
      local_30[2] = 0x2555dc;
      local_24 = &DAT_00276f90;
      local_20 = 0x2555df;
      pcVar5 = pcVar1->name;
      do {
        pcVar3 = Q_stristr(pcVar5,(char *)local_30[iVar6]);
        pcVar5 = pcVar1->name;
        if (pcVar3 == pcVar5) goto LAB_0009c198;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 5);
    }
  }
  s_bCurrentCommandIsPrivileged = src;
  (*pcVar1->function)();
  s_bCurrentCommandIsPrivileged = true;
  if (((cls.demorecording != false) && ((pcVar1->flags & 1) != 0)) && (cls.spectator == false)) {
    CL_RecordHUDCommand(pcVar1->name);
  }
  return;
}


// Cmd_Exists  @ 0009ba70
qboolean Cmd_Exists(char *cmd_name)

{
  cmd_function_s *pcVar1;
  int iVar2;
  
  pcVar1 = cmd_functions;
  while( true ) {
    if (pcVar1 == (cmd_function_t *)0x0) {
      return false;
    }
    iVar2 = Q_strcmp(cmd_name,pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return true;
}


// Cmd_FindCmd  @ 0009b310
cmd_function_t * Cmd_FindCmd(char *cmd_name)

{
  cmd_function_s *pcVar1;
  int iVar2;
  
  pcVar1 = cmd_functions;
  while( true ) {
    if (pcVar1 == (cmd_function_t *)0x0) {
      return (cmd_function_t *)0x0;
    }
    iVar2 = Q_strcmp(cmd_name,pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// Cmd_FindCmdPrev  @ 0009b360
cmd_function_t * Cmd_FindCmdPrev(char *cmd_name)

{
  cmd_function_s *pcVar1;
  cmd_function_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
  pcVar1 = cmd_functions->next;
  pcVar2 = cmd_functions;
  while( true ) {
    if (pcVar1 == (cmd_function_s *)0x0) {
      return (cmd_function_t *)0x0;
    }
    iVar3 = Q_strcmp(cmd_name,pcVar1->name);
    if (iVar3 == 0) break;
    pcVar2 = pcVar2->next;
    pcVar1 = pcVar2->next;
  }
  return pcVar2;
}


// Cmd_ForwardToServer  @ 0009bee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_ForwardToServer(void)

{
  char *pcVar1;
  int iVar2;
  uint local_14;
  uint local_10 [4];
  
  local_14 = 0;
  (*g_engdstAddrs.Cmd_Argv)((int *)&local_14);
  pcVar1 = "";
  if (local_14 < (uint)cmd_argc) {
    pcVar1 = cmd_argv[local_14];
  }
  iVar2 = Q_strcasecmp(pcVar1,0x2555d0);
  if (iVar2 == 0) {
    local_10[0] = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)local_10);
    pcVar1 = "";
    if (local_10[0] < (uint)cmd_argc) {
      pcVar1 = cmd_argv[local_10[0]];
    }
    iVar2 = Q_strcasecmp(pcVar1,&LAB_0025e3bc);
    if (iVar2 == 0) {
      return;
    }
  }
  Cmd_ForwardToServerInternal(&cls.netchan.message);
  return;
}


// Cmd_ForwardToServerInternal  @ 0009bc90
int Cmd_ForwardToServerInternal(sizebuf_t *pBuf)

{
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  uint local_1034;
  uint local_1030;
  uint local_102c;
  uint local_1028;
  sizebuf_t local_1024;
  byte local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: sizebuf_t tempBuf@[???]
                       Unresolved local var: char[4096] tempData@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1024.data = local_1010;
  local_1024.maxsize = 0x1000;
  local_1024.cursize = 0;
  local_1024.buffername = "Cmd_ForwardToServerInternal::tempBuf";
  local_1024.flags = 1;
  if (cls.state - ca_connected < 3) {
    if ((cls.demoplayback == false) && (g_bIsDedicatedServer == false)) {
      MSG_WriteByte(&local_1024,3);
      local_102c = 0;
      (*g_engdstAddrs.Cmd_Argv)((int *)&local_102c);
      pcVar2 = "";
      if (local_102c < (uint)cmd_argc) {
        pcVar2 = cmd_argv[local_102c];
      }
      iVar1 = Q_strcasecmp(pcVar2,0x2555d0);
      if (iVar1 != 0) {
        local_1028 = 0;
        (*g_engdstAddrs.Cmd_Argv)((int *)&local_1028);
        pcVar2 = "";
        if (local_1028 < (uint)cmd_argc) {
          pcVar2 = cmd_argv[local_1028];
        }
        SZ_Print(&local_1024,pcVar2);
        SZ_Print(&local_1024," ");
      }
      (*g_engdstAddrs.Cmd_Argc)();
      if (cmd_argc < 2) {
        SZ_Print(&local_1024,"\n");
      }
      else {
        SZ_Print(&local_1024,cmd_args);
      }
      if (((local_1024.flags & 2) == 0) && (pBuf->cursize + local_1024.cursize <= pBuf->maxsize)) {
        SZ_Write(pBuf,local_1024.data,local_1024.cursize);
        iVar1 = 1;
        goto LAB_0009bcfa;
      }
    }
  }
  else {
    local_1034 = 0;
    (*g_engdstAddrs.Cmd_Argv)((int *)&local_1034);
    pcVar2 = "";
    if (local_1034 < (uint)cmd_argc) {
      pcVar2 = cmd_argv[local_1034];
    }
    iVar1 = Q_stricmp(pcVar2,"setinfo");
    if (iVar1 != 0) {
      local_1030 = 0;
      (*g_engdstAddrs.Cmd_Argv)((int *)&local_1030);
      pcVar2 = "";
      if (local_1030 < (uint)cmd_argc) {
        pcVar2 = cmd_argv[local_1030];
      }
      Con_Printf("Can\'t \"%s\", not connected\n",pcVar2);
    }
  }
  iVar1 = 0;
LAB_0009bcfa:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Cmd_ForwardToServerUnreliable  @ 0009c880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cmd_ForwardToServerUnreliable(void)

{
  int iVar1;
  
  iVar1 = Cmd_ForwardToServerInternal(&cls.datagram);
  return iVar1;
}


// Cmd_GetFirstCmd  @ 0009b150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cmd_function_s * Cmd_GetFirstCmd(void)

{
  return cmd_functions;
}


// Cmd_Init  @ 0009b4f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Init(void)

{
  SetCStrikeFlags();
  Cmd_AddCommandWithFlags("stuffcmds",Cmd_StuffCmds_f,0);
  if (g_bIsTFC == 0) {
    Cmd_AddCommandWithFlags("exec",Cmd_Exec_f,8);
  }
  else {
    Cmd_AddCommandWithFlags("exec",Cmd_Exec_f,0);
  }
  Cmd_AddCommandWithFlags("echo",Cmd_Echo_f,0);
  Cmd_AddCommandWithFlags("alias",Cmd_Alias_f,8);
  Cmd_AddCommandWithFlags("cmd",Cmd_ForwardToServer,0);
  Cmd_AddCommandWithFlags("wait",Cmd_Wait_f,0);
  Cmd_AddCommandWithFlags("cmdlist",Cmd_CmdList_f,0);
  return;
}


// Cmd_RemoveGameCmds  @ 0009b9d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_RemoveGameCmds(void)

{
  cmd_function_s *pcVar1;
  cmd_function_t *p;
  cmd_function_t *pcVar2;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_t *)0x0;
  pcVar1 = cmd_functions;
  do {
    if (pcVar1 == (cmd_function_t *)0x0) {
      cmd_functions = pcVar2;
      return;
    }
    while (p = pcVar1, pcVar1 = p->next, (p->flags & 2) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      if (pcVar1 == (cmd_function_s *)0x0) {
        cmd_functions = p;
        return;
      }
    }
    Mem_Free(p);
  } while( true );
}


// Cmd_RemoveHudCmds  @ 0009b980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_RemoveHudCmds(void)

{
  cmd_function_s *pcVar1;
  cmd_function_t *p;
  cmd_function_t *pcVar2;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_t *)0x0;
  pcVar1 = cmd_functions;
  do {
    if (pcVar1 == (cmd_function_t *)0x0) {
      cmd_functions = pcVar2;
      return;
    }
    while (p = pcVar1, pcVar1 = p->next, (p->flags & 1) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      if (pcVar1 == (cmd_function_s *)0x0) {
        cmd_functions = p;
        return;
      }
    }
    Mem_Free(p);
  } while( true );
}


// Cmd_RemoveMallocedCmds  @ 0009b930
void Cmd_RemoveMallocedCmds(int flag)

{
  cmd_function_s *pcVar1;
  cmd_function_t *p;
  cmd_function_t *pcVar2;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_t *)0x0;
  pcVar1 = cmd_functions;
  do {
    if (pcVar1 == (cmd_function_t *)0x0) {
      cmd_functions = pcVar2;
      return;
    }
    while (p = pcVar1, pcVar1 = p->next, (p->flags & flag) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      if (pcVar1 == (cmd_function_s *)0x0) {
        cmd_functions = p;
        return;
      }
    }
    Mem_Free(p);
  } while( true );
}


// Cmd_RemoveWrapperCmds  @ 0009ba20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_RemoveWrapperCmds(void)

{
  cmd_function_s *pcVar1;
  cmd_function_t *p;
  cmd_function_t *pcVar2;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_t *)0x0;
  pcVar1 = cmd_functions;
  do {
    if (pcVar1 == (cmd_function_t *)0x0) {
      cmd_functions = pcVar2;
      return;
    }
    while (p = pcVar1, pcVar1 = p->next, (p->flags & 4) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      if (pcVar1 == (cmd_function_s *)0x0) {
        cmd_functions = p;
        return;
      }
    }
    Mem_Free(p);
  } while( true );
}


// Cmd_Shutdown  @ 0009b160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Shutdown(void)

{
  uint uVar1;
  uint uVar2;
  
  cmd_functions = (cmd_function_t *)0x0;
  cmd_argc = 0;
  uVar1 = 0;
  do {
    *(undefined4 *)((int)cmd_argv + uVar1) = 0;
    uVar2 = uVar1 + 8;
    *(undefined4 *)((int)cmd_argv + uVar1 + 4) = 0;
    uVar1 = uVar2;
  } while (uVar2 < 0x140);
  cmd_args = (char *)0x0;
  return;
}


// Cmd_StuffCmds_f  @ 0009a710
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_StuffCmds_f(void)

{
  char *__src;
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *__s;
  size_t sVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: char * text@[???]
                       Unresolved local var: char * build@[???]
                       Unresolved local var: char c@[???] */
  (*g_engdstAddrs.Cmd_Argc)();
  if (cmd_argc != 1) {
    Con_Printf("stuffcmds : execute command line parameters\n");
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: char * text@[???]
                       Unresolved local var: char * build@[???]
                       Unresolved local var: char c@[???] */
  iVar9 = 0;
  iVar7 = 1;
  iVar3 = com_argc;
  if (1 < com_argc) {
    do {
      if (com_argv[iVar7] != (char *)0x0) {
        iVar3 = Q_strlen(com_argv[iVar7]);
        iVar9 = iVar3 + 1 + iVar9;
        iVar3 = com_argc;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar3);
    if (iVar9 != 0) {
      iVar8 = 1;
      iVar3 = iVar9 + -1;
      __s = Z_Malloc(iVar9 + 1);
      *__s = '\0';
      iVar7 = com_argc;
      if (1 < com_argc) {
        do {
          pcVar5 = com_argv[iVar8];
          if (pcVar5 != (char *)0x0) {
            sVar4 = strlen(__s);
            strncat(__s,pcVar5,iVar3 - sVar4);
            iVar7 = com_argc;
            if (com_argc + -1 != iVar8) {
              Q_strcat(__s," ");
              iVar7 = com_argc;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar7);
      }
      iVar7 = 0;
      pcVar5 = Z_Malloc(iVar9 + 1);
      *pcVar5 = '\0';
      if (0 < iVar3) {
        do {
          while (__s[iVar7] == '+') {
            iVar7 = iVar7 + 1;
            __src = __s + iVar7;
            cVar6 = *__src;
            pcVar1 = __src;
            while (((cVar6 - 0x2bU & 0xfd) != 0 && (bVar2 = cVar6 != '\0', cVar6 = '\0', bVar2))) {
              iVar7 = iVar7 + 1;
              pcVar1 = __s + iVar7;
              cVar6 = __s[iVar7];
            }
            *pcVar1 = '\0';
            sVar4 = strlen(pcVar5);
            strncat(pcVar5,__src,(iVar9 + -2) - sVar4);
            Q_strcat(pcVar5,"\n");
            *pcVar1 = cVar6;
            if (iVar3 <= iVar7) goto LAB_0009a8c1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar3);
LAB_0009a8c1:
        if (*pcVar5 != '\0') {
          Cbuf_InsertTextToBuffer(pcVar5,&cmd_text,false);
        }
      }
      Z_Free(__s);
      Z_Free(pcVar5);
      return;
    }
  }
  return;
}


// Cmd_TokenizeString  @ 0009b200
void Cmd_TokenizeString(char *text)

{
  char **ppcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int arglen@[???] */
  if (0 < cmd_argc) {
    iVar5 = 0;
    do {
      ppcVar1 = cmd_argv + iVar5;
      iVar5 = iVar5 + 1;
      Z_Free(*ppcVar1);
    } while (iVar5 < cmd_argc);
  }
  cmd_argc = 0;
  cmd_args = (char *)0x0;
  while( true ) {
    cVar2 = *text;
    while (((byte)(cVar2 - 1U) < 0x20 && (cVar2 != '\n'))) {
      text = text + 1;
      cVar2 = *text;
    }
    if ((cVar2 == '\n') || (cVar2 == '\0')) break;
    if (cmd_argc == 1) {
      cmd_args = text;
      text = COM_Parse(text);
    }
    else {
      text = COM_Parse(text);
    }
    if (text == (char *)0x0) {
      return;
    }
    iVar3 = Q_strlen(com_token);
    iVar5 = cmd_argc;
    if (0x203 < iVar3 + 1) {
      return;
    }
    if (cmd_argc < 0x50) {
      pcVar4 = Z_Malloc(iVar3 + 1);
      cmd_argv[iVar5] = pcVar4;
      Q_strcpy(cmd_argv[cmd_argc],com_token);
      cmd_argc = cmd_argc + 1;
    }
  }
  return;
}


// Cmd_Wait_f  @ 0009a0b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Wait_f(void)

{
  cmd_wait = true;
  return;
}


