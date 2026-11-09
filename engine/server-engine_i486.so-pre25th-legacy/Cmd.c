// Cmd_AddCommand  @ 0005ca30
void Cmd_AddCommand(char *cmd_name,xcommand_t function)

{
  char cVar1;
  cmd_function_t *pcVar2;
  char *pcVar3;
  cmd_function_s *pcVar4;
  int iVar5;
  cmd_function_t *pcVar6;
  cmd_function_t *pcVar7;
  cmd_function_t local_2c;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???] */
  if (host_initialized == false) {
    pcVar3 = Cvar_VariableString(cmd_name);
    cVar1 = *pcVar3;
  }
  else {
    Sys_Error("Cmd_AddCommand after host_initialized");
    pcVar3 = Cvar_VariableString(cmd_name);
    cVar1 = *pcVar3;
  }
  pcVar2 = cmd_functions;
  if (cVar1 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n");
    return;
  }
  for (; pcVar2 != (cmd_function_t *)0x0; pcVar2 = pcVar2->next) {
    iVar5 = Q_strcmp(cmd_name,pcVar2->name);
    if (iVar5 == 0) {
      Con_Printf("Cmd_AddCommand: %s already defined\n");
      return;
    }
  }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
  pcVar4 = Hunk_Alloc(0x10);
  pcVar2 = cmd_functions;
  local_2c.next = cmd_functions;
  pcVar4->name = cmd_name;
  if (function == (xcommand_t)0x0) {
    function = Cmd_ForwardToServer;
  }
  pcVar4->function = function;
  pcVar4->flags = 0;
  local_2c.name = " ";
  pcVar7 = &local_2c;
  while( true ) {
    pcVar6 = pcVar2;
    if (pcVar6 == (cmd_function_t *)0x0) {
      pcVar7->next = pcVar4;
      pcVar4->next = (cmd_function_s *)0x0;
      cmd_functions = local_2c.next;
      return;
    }
    iVar5 = strcasecmp(pcVar6->name,cmd_name);
    if (0 < iVar5) break;
    pcVar2 = pcVar6->next;
    pcVar7 = pcVar6;
  }
  pcVar7->next = pcVar4;
  pcVar4->next = pcVar6;
  cmd_functions = local_2c.next;
  return;
}


// Cmd_AddCommandWithFlags  @ 0005c8e0
void Cmd_AddCommandWithFlags(char *cmd_name,xcommand_t function,int flags)

{
  char cVar1;
  cmd_function_t *pcVar2;
  char *pcVar3;
  cmd_function_s *pcVar4;
  int iVar5;
  cmd_function_t *pcVar6;
  cmd_function_t *pcVar7;
  cmd_function_t local_2c;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???] */
  if (host_initialized == false) {
    pcVar3 = Cvar_VariableString(cmd_name);
    cVar1 = *pcVar3;
  }
  else {
    Sys_Error("Cmd_AddCommand after host_initialized");
    pcVar3 = Cvar_VariableString(cmd_name);
    cVar1 = *pcVar3;
  }
  pcVar2 = cmd_functions;
  if (cVar1 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n");
    return;
  }
  for (; pcVar2 != (cmd_function_t *)0x0; pcVar2 = pcVar2->next) {
    iVar5 = Q_strcmp(cmd_name,pcVar2->name);
    if (iVar5 == 0) {
      Con_Printf("Cmd_AddCommand: %s already defined\n");
      return;
    }
  }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
  pcVar4 = Hunk_Alloc(0x10);
  pcVar2 = cmd_functions;
  local_2c.name = " ";
  local_2c.next = cmd_functions;
  pcVar4->name = cmd_name;
  if (function == (xcommand_t)0x0) {
    function = Cmd_ForwardToServer;
  }
  pcVar4->function = function;
  pcVar4->flags = flags;
  pcVar7 = &local_2c;
  while( true ) {
    pcVar6 = pcVar2;
    if (pcVar6 == (cmd_function_t *)0x0) {
      pcVar7->next = pcVar4;
      pcVar4->next = (cmd_function_s *)0x0;
      cmd_functions = local_2c.next;
      return;
    }
    iVar5 = strcasecmp(pcVar6->name,cmd_name);
    if (0 < iVar5) break;
    pcVar2 = pcVar6->next;
    pcVar7 = pcVar6;
  }
  pcVar7->next = pcVar4;
  pcVar4->next = pcVar6;
  cmd_functions = local_2c.next;
  return;
}


// Cmd_AddGameCommand  @ 0005cdc0
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


// Cmd_AddHUDCommand  @ 0005cc40
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


// Cmd_AddMallocCommand  @ 0005cb80
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


// Cmd_AddWrapperCommand  @ 0005cd00
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


// Cmd_Alias_f  @ 0005b730
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
  uint local_420 [256];
  uint local_20 [4];
  
                    /* Unresolved local var: cmdalias_t * a@[???]
                       Unresolved local var: char[1024] cmd@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int c@[DW_OP_reg0(EAX)]
                       Unresolved local var: char * s@[DW_OP_reg3(EBX)]
                       Unresolved local var: cvar_t * cv@[???] */
  (*g_engdstAddrs.Cmd_Argc)();
  if (cmd_argc == 1) {
    Con_Printf("Current alias commands:\n");
    for (pcVar6 = cmd_alias; pcVar6 != (cmdalias_t *)0x0; pcVar6 = pcVar6->next) {
      Con_Printf("%s : %s\n",pcVar6->name,pcVar6->value);
    }
  }
  else {
    pcVar9 = "";
    local_20[0] = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)local_20);
    if (local_20[0] < (uint)cmd_argc) {
      pcVar9 = cmd_argv[local_20[0]];
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
            local_20[0] = uVar10;
            (*g_engdstAddrs.Cmd_Argv)((int *)local_20);
            pcVar5 = "";
            if (local_20[0] < (uint)cmd_argc) {
              pcVar5 = cmd_argv[local_20[0]];
            }
            strncat((char *)local_420,pcVar5,
                    0x3fe - (int)((int)puVar8 +
                                 ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_420)));
            puVar8 = local_420;
            if (uVar10 != iVar1) {
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
              strncat((char *)local_420," ",
                      0x3fe - (int)((int)puVar8 +
                                   ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_420)))
              ;
            }
            uVar10 = uVar10 + 1;
            puVar8 = local_420;
          } while (uVar10 != iVar1);
        }
        Q_strcat((char *)local_420,"\n");
        for (pcVar6 = cmd_alias; pcVar6 != (cmdalias_t *)0x0; pcVar6 = pcVar6->next) {
          pcVar5 = pcVar6->name;
          iVar1 = Q_strcmp(pcVar9,pcVar5);
          if (iVar1 == 0) {
            iVar1 = Q_strcmp(pcVar6->value,(char *)local_420);
            if (iVar1 == 0) {
              return;
            }
            Z_Free(pcVar6->value);
            goto LAB_0005ba1f;
          }
        }
        pcVar6 = Z_Malloc(0x28);
        pcVar5 = pcVar6->name;
        pcVar6->next = cmd_alias;
        cmd_alias = pcVar6;
LAB_0005ba1f:
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
  return;
}


// Cmd_Argc  @ 0005c6b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cmd_Argc(void)

{
  (*g_engdstAddrs.Cmd_Argc)();
  return cmd_argc;
}


// Cmd_Args  @ 0005c700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Cmd_Args(void)

{
  return cmd_args;
}


// Cmd_Argv  @ 0005c6d0
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


// Cmd_CheckParm  @ 0005dd80
int Cmd_CheckParm(char *parm)

{
  char *s2;
  int iVar1;
  uint uVar2;
  uint local_10;
  
                    /* Unresolved local var: int i@[???] */
  if (parm == (char *)0x0) {
    Sys_Error("Cmd_CheckParm: NULL");
  }
  uVar2 = 1;
  while( true ) {
    (*g_engdstAddrs.Cmd_Argc)();
    if (cmd_argc <= (int)uVar2) {
      return 0;
    }
    local_10 = uVar2;
    (*g_engdstAddrs.Cmd_Argv)((int *)&local_10);
    s2 = "";
    if (local_10 < (uint)cmd_argc) {
      s2 = cmd_argv[local_10];
    }
    iVar1 = Q_strcasecmp(parm,s2);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}


// Cmd_CmdList_f  @ 0005afa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_CmdList_f(void)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  cmd_function_s *pcVar4;
  int unaff_EBP;
  int iVar5;
  bool bVar6;
  FileHandle_t local_130;
  char local_120 [256];
  uint local_20 [4];
  
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: int iCmds@[???]
                       Unresolved local var: int iArgs@[DW_OP_reg7(EDI)]
                       Unresolved local var: char * partial@[???]
                       Unresolved local var: int ipLen@[???]
                       Unresolved local var: FileHandle_t f@[???]
                       Unresolved local var: qboolean bLogging@[???] */
  (*g_engdstAddrs.Cmd_Argc)();
  iVar5 = cmd_argc;
  if (cmd_argc < 2) {
    pcVar2 = (char *)0x0;
    bVar6 = false;
    bVar1 = false;
  }
  else {
    local_20[0] = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)local_20);
    pcVar2 = "";
    if (local_20[0] < (uint)cmd_argc) {
      pcVar2 = cmd_argv[local_20[0]];
    }
    iVar3 = Q_strcasecmp(pcVar2,"?");
    if (iVar3 == 0) {
      Con_Printf(
                "CmdList           : List all commands\nCmdList [Partial] : List commands starting with \'Partial\'\nCmdList log [Partial] : Logs commands to file \"cmdlist.txt\" in the gamedir.\n"
                );
      return;
    }
    local_20[0] = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)local_20);
    pcVar2 = "";
    if (local_20[0] < (uint)cmd_argc) {
      pcVar2 = cmd_argv[local_20[0]];
    }
    iVar3 = Q_strcasecmp(pcVar2,"log");
    if (iVar3 == 0) {
                    /* Unresolved local var: char[256] szTemp@[???] */
      snprintf(local_120,0x100,"cmdlist.txt");
      local_130 = FS_Open(local_120,"wt");
      if (local_130 == (FileHandle_t)0x0) {
        Con_Printf("Couldn\'t open [%s] for writing!\n",local_120);
        return;
      }
      if (iVar5 == 3) {
        pcVar2 = "";
        local_20[0] = 2;
        (*g_engdstAddrs.Cmd_Argv)((int *)local_20);
        if (local_20[0] < (uint)cmd_argc) {
          pcVar2 = cmd_argv[local_20[0]];
        }
        unaff_EBP = Q_strlen(pcVar2);
        bVar6 = false;
        bVar1 = true;
      }
      else {
        pcVar2 = (char *)0x0;
        bVar6 = false;
        bVar1 = true;
      }
    }
    else {
      local_20[0] = 1;
      (*g_engdstAddrs.Cmd_Argv)((int *)local_20);
      if (local_20[0] < (uint)cmd_argc) {
        pcVar2 = cmd_argv[local_20[0]];
        bVar6 = pcVar2 != (char *)0x0;
      }
      else {
        bVar6 = true;
        pcVar2 = "";
      }
      unaff_EBP = Q_strlen(pcVar2);
      bVar6 = (bool)(iVar5 == 2 & bVar6);
      bVar1 = false;
    }
  }
  iVar5 = 0;
  Con_Printf("Command List\n--------------\n");
  if (cmd_functions != (cmd_function_t *)0x0) {
    if (pcVar2 == (char *)0x0) {
      if (bVar1) {
        iVar5 = 0;
        pcVar4 = cmd_functions;
        do {
          iVar5 = iVar5 + 1;
          Con_Printf("%-16.16s\n",pcVar4->name);
          FS_FPrintf(local_130,"%-16.16s\n",pcVar4->name);
          pcVar4 = pcVar4->next;
        } while (pcVar4 != (cmd_function_s *)0x0);
      }
      else {
        iVar5 = 0;
        pcVar4 = cmd_functions;
        do {
          iVar5 = iVar5 + 1;
          Con_Printf("%-16.16s\n",pcVar4->name);
          pcVar4 = pcVar4->next;
        } while (pcVar4 != (cmd_function_s *)0x0);
      }
    }
    else {
      pcVar4 = cmd_functions;
      if (bVar1) {
        do {
          iVar3 = Q_strncasecmp(pcVar4->name,pcVar2,unaff_EBP);
          if (iVar3 == 0) {
            iVar5 = iVar5 + 1;
            Con_Printf("%-16.16s\n",pcVar4->name);
            FS_FPrintf(local_130,"%-16.16s\n",pcVar4->name);
          }
          pcVar4 = pcVar4->next;
        } while (pcVar4 != (cmd_function_s *)0x0);
      }
      else {
        iVar5 = 0;
        do {
          while (iVar3 = Q_strncasecmp(pcVar4->name,pcVar2,unaff_EBP), iVar3 != 0) {
            pcVar4 = pcVar4->next;
            if (pcVar4 == (cmd_function_s *)0x0) goto LAB_0005b160;
          }
          iVar5 = iVar5 + 1;
          Con_Printf("%-16.16s\n",pcVar4->name);
          pcVar4 = pcVar4->next;
        } while (pcVar4 != (cmd_function_s *)0x0);
      }
    }
  }
LAB_0005b160:
  if ((bVar6) && (*pcVar2 != '\0')) {
    Con_Printf("--------------\n%3i Commands for [%s]\nCmdList ? for syntax\n",iVar5,pcVar2);
  }
  else {
    Con_Printf("--------------\n%3i Total Commands\nCmdList ? for syntax\n",iVar5);
  }
  if (!bVar1) {
    return;
  }
  FS_Close(local_130);
  return;
}


// Cmd_CompleteCommand  @ 0005d010
char * Cmd_CompleteCommand(char *search,int forward)

{
  char cVar1;
  char *s1;
  cmd_function_t *pcVar2;
  int count;
  int iVar3;
  cmd_function_s *pcVar4;
  cmd_function_t *pcVar5;
  undefined4 local_120;
  char local_11c [255];
  undefined1 local_1d;
  
                    /* Unresolved local var: char[256] partial@[???]
                       Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char * pPartial@[???] */
  Q_strncpy(local_11c,search,0xff);
  local_1d = 0;
  count = Q_strlen(local_11c);
  if (count == 0) {
    return (char *)0x0;
  }
  cVar1 = local_11c[count + -1];
  while (cVar1 == ' ') {
    local_11c[count + -1] = '\0';
    cVar1 = local_11c[count + -2];
    count = count + -1;
  }
  iVar3 = Q_stricmp(local_11c,Cmd_CompleteCommand::lastpartial);
  pcVar2 = cmd_functions;
  if (iVar3 == 0) {
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
    pcVar4 = cmd_functions;
    if (cmd_functions == (cmd_function_t *)0x0) {
      return (char *)0x0;
    }
    do {
      iVar3 = Q_strcmp(local_11c,pcVar4->name);
      pcVar2 = cmd_functions;
      if (iVar3 == 0) {
        if (forward == 1) {
          pcVar5 = pcVar4->next;
          goto LAB_0005d131;
        }
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
        s1 = pcVar4->name;
        pcVar4 = cmd_functions->next;
        pcVar5 = cmd_functions;
        if (pcVar4 != (cmd_function_s *)0x0) goto LAB_0005d180;
        break;
      }
      pcVar4 = pcVar4->next;
    } while (pcVar4 != (cmd_function_s *)0x0);
  }
  goto LAB_0005d0a9;
LAB_0005d131:
  pcVar2 = cmd_functions;
  if (pcVar5 != (cmd_function_t *)0x0) goto LAB_0005d135;
  goto LAB_0005d0a9;
  while( true ) {
    pcVar4 = pcVar5->next->next;
    pcVar5 = pcVar5->next;
    pcVar2 = cmd_functions;
    if (pcVar4 == (cmd_function_s *)0x0) break;
LAB_0005d180:
    iVar3 = Q_strcmp(s1,pcVar4->name);
    if (iVar3 == 0) goto LAB_0005d131;
  }
LAB_0005d0a9:
  while( true ) {
    pcVar5 = pcVar2;
    if (pcVar5 == (cmd_function_t *)0x0) {
      return (char *)0x0;
    }
    iVar3 = Q_strncmp(local_11c,pcVar5->name,count);
    if (iVar3 == 0) break;
    pcVar2 = pcVar5->next;
  }
  iVar3 = Q_strlen(pcVar5->name);
  if (iVar3 != count) {
    local_120 = pcVar5->name;
    Q_strncpy(Cmd_CompleteCommand::lastpartial,local_120,0xff);
    Cmd_CompleteCommand::lastpartial[0xff] = '\0';
    return local_120;
  }
LAB_0005d135:
  Q_strncpy(Cmd_CompleteCommand::lastpartial,pcVar5->name,0xff);
  Cmd_CompleteCommand::lastpartial[0xff] = '\0';
  return pcVar5->name;
}


// Cmd_CurrentCommandIsPrivileged  @ 0005de00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Cmd_CurrentCommandIsPrivileged(void)

{
  return s_bCurrentCommandIsPrivileged;
}


// Cmd_CvarListPrintCvar  @ 00066220
void Cmd_CvarListPrintCvar(cvar_t *var,FileHandle_t f)

{
  float fVar1;
  uint uVar2;
  char local_10c [256];
  
                    /* Unresolved local var: char[256] szOutstr@[???] */
  fVar1 = var->value;
  if (fVar1 == (float)(int)fVar1) {
    snprintf(local_10c,0xf5,"%-15s : %8i",var->name,(int)fVar1);
    uVar2 = var->flags;
  }
  else {
    snprintf(local_10c,0xf5,"%-15s : %8.3f",var->name,(double)fVar1);
    uVar2 = var->flags;
  }
  if ((uVar2 & 1) != 0) {
    Q_strcat(local_10c,", a");
    uVar2 = var->flags;
  }
  if ((uVar2 & 4) != 0) {
    Q_strcat(local_10c,", sv");
    uVar2 = var->flags;
  }
  if ((uVar2 & 2) != 0) {
    Q_strcat(local_10c,", i");
  }
  Q_strcat(local_10c,"\n");
  Con_Printf("%s",local_10c);
  if (f != (FileHandle_t)0x0) {
    FS_FPrintf(f,"%s",local_10c);
  }
  return;
}


// Cmd_CvarList_f  @ 00066390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_CvarList_f(void)

{
  cvar_s **ppcVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  FileHandle_t file;
  cvar_s *pcVar10;
  char *pcVar11;
  char *pcVar12;
  FileHandle_t local_12c;
  char local_11c [268];
  
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
  iVar7 = Cmd_Argc();
  if (iVar7 < 2) {
    iVar9 = 0;
    bVar5 = false;
    pcVar8 = (char *)0x0;
    local_12c = (FileHandle_t)0x0;
    bVar4 = false;
    bVar6 = false;
    bVar2 = false;
  }
  else {
    pcVar8 = Cmd_Argv(1);
    iVar9 = Q_strcasecmp(pcVar8,"?");
    if (iVar9 == 0) {
      Con_Printf(
                "CvarList           : List all cvars\nCvarList [Partial] : List cvars starting with \'Partial\'\nCvarList log [Partial] : Logs cvars to file \"cvarlist.txt\" in the gamedir.\n"
                );
      return;
    }
    pcVar8 = Cmd_Argv(1);
    iVar9 = Q_strcasecmp(pcVar8,"log");
    if (iVar9 == 0) {
      iVar9 = 0;
      while( true ) {
        snprintf(local_11c,0x100,"cvarlist%02d.txt",iVar9);
        COM_FixSlashes(local_11c);
        file = FS_Open(local_11c,"r");
        if (file == (FileHandle_t)0x0) break;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int found@[???] */
        iVar9 = iVar9 + 1;
        FS_Close(file);
        if (iVar9 == 100) {
          Con_Printf("Can\'t cvarlist! Too many existing cvarlist output files in the gamedir!\n");
          return;
        }
      }
      local_12c = FS_Open(local_11c,"wt");
      if (local_12c == (FileHandle_t)0x0) {
        Con_Printf("Couldn\'t open [%s] for writing!\n",local_11c);
        return;
      }
      if (iVar7 == 3) {
        pcVar8 = Cmd_Argv(2);
        iVar9 = Q_strlen(pcVar8);
        bVar2 = false;
        bVar5 = true;
        bVar4 = false;
        bVar6 = false;
      }
      else {
        iVar9 = 0;
        bVar5 = true;
        pcVar8 = (char *)0x0;
        bVar4 = false;
        bVar6 = false;
        bVar2 = false;
      }
    }
    else {
      pcVar8 = Cmd_Argv(1);
      iVar9 = Q_stricmp(pcVar8,"-a");
      if (iVar9 == 0) {
        pcVar8 = (char *)0x0;
        bVar5 = false;
        iVar9 = 0;
        bVar4 = false;
        bVar6 = true;
        bVar2 = false;
        local_12c = (FileHandle_t)0x0;
      }
      else {
        pcVar8 = Cmd_Argv(1);
        iVar9 = Q_stricmp(pcVar8,"-s");
        if (iVar9 == 0) {
          bVar6 = false;
          bVar4 = true;
          iVar9 = 0;
          pcVar8 = (char *)0x0;
          bVar2 = false;
          bVar5 = false;
          local_12c = (FileHandle_t)0x0;
        }
        else {
          pcVar8 = Cmd_Argv(1);
          iVar9 = Q_strlen(pcVar8);
          bVar2 = pcVar8 != (char *)0x0 && iVar7 == 2;
          bVar5 = false;
          local_12c = (FileHandle_t)0x0;
          bVar6 = false;
          bVar4 = false;
        }
      }
    }
  }
  pcVar11 = (char *)0x0;
  Con_Printf("CVar List\n--------------\n");
  pcVar12 = pcVar11;
  if (cvar_vars != (cvar_t *)0x0) {
    if (bVar6) {
      if (pcVar8 == (char *)0x0) {
        pcVar10 = cvar_vars;
        pcVar12 = pcVar8;
        if (bVar4) {
          do {
            if (((pcVar10->flags & 1U) != 0) && ((pcVar10->flags & 4U) != 0)) {
              pcVar12 = pcVar12 + 1;
              Cmd_CvarListPrintCvar(pcVar10,local_12c);
            }
            pcVar10 = pcVar10->next;
          } while (pcVar10 != (cvar_s *)0x0);
        }
        else {
          do {
            if ((pcVar10->flags & 1) != 0) {
              pcVar12 = pcVar12 + 1;
              Cmd_CvarListPrintCvar(pcVar10,local_12c);
            }
            ppcVar1 = &pcVar10->next;
            pcVar10 = *ppcVar1;
          } while (*ppcVar1 != (cvar_s *)0x0);
        }
      }
      else {
        pcVar10 = cvar_vars;
        if (bVar4) {
          do {
            if ((((pcVar10->flags & 1U) != 0) && ((pcVar10->flags & 4U) != 0)) &&
               (iVar7 = Q_strncasecmp(pcVar10->name,pcVar8,iVar9), iVar7 == 0)) {
              pcVar12 = pcVar12 + 1;
              Cmd_CvarListPrintCvar(pcVar10,local_12c);
            }
            pcVar10 = pcVar10->next;
          } while (pcVar10 != (cvar_s *)0x0);
        }
        else {
          bVar3 = (byte)cvar_vars->flags;
          while( true ) {
            if (((bVar3 & 1) != 0) &&
               (iVar7 = Q_strncasecmp(pcVar10->name,pcVar8,iVar9), iVar7 == 0)) {
              pcVar12 = pcVar12 + 1;
              Cmd_CvarListPrintCvar(pcVar10,local_12c);
            }
            pcVar10 = pcVar10->next;
            if (pcVar10 == (cvar_s *)0x0) break;
            bVar3 = (byte)pcVar10->flags;
          }
        }
      }
    }
    else if (bVar4) {
      pcVar10 = cvar_vars;
      pcVar12 = pcVar8;
      if (pcVar8 == (char *)0x0) {
        do {
          if ((pcVar10->flags & 4) != 0) {
            pcVar12 = pcVar12 + 1;
            Cmd_CvarListPrintCvar(pcVar10,local_12c);
          }
          ppcVar1 = &pcVar10->next;
          pcVar10 = *ppcVar1;
        } while (*ppcVar1 != (cvar_s *)0x0);
      }
      else {
        do {
          while ((pcVar12 = pcVar11, (pcVar10->flags & 4) == 0 ||
                 (iVar7 = Q_strncasecmp(pcVar10->name,pcVar8,iVar9), iVar7 != 0))) {
            pcVar10 = pcVar10->next;
            pcVar11 = pcVar12;
            if (pcVar10 == (cvar_s *)0x0) goto LAB_00066550;
          }
          pcVar12 = pcVar12 + 1;
          Cmd_CvarListPrintCvar(pcVar10,local_12c);
          pcVar10 = pcVar10->next;
          pcVar11 = pcVar12;
        } while (pcVar10 != (cvar_s *)0x0);
      }
    }
    else {
      pcVar12 = (char *)0x0;
      pcVar10 = cvar_vars;
      if (pcVar8 == (char *)0x0) {
        pcVar12 = (char *)0x0;
        do {
          pcVar12 = pcVar12 + 1;
          Cmd_CvarListPrintCvar(pcVar10,local_12c);
          pcVar10 = pcVar10->next;
        } while (pcVar10 != (cvar_s *)0x0);
      }
      else {
        do {
          iVar7 = Q_strncasecmp(pcVar10->name,pcVar8,iVar9);
          if (iVar7 == 0) {
            pcVar12 = pcVar12 + 1;
            Cmd_CvarListPrintCvar(pcVar10,local_12c);
          }
          pcVar10 = pcVar10->next;
        } while (pcVar10 != (cvar_s *)0x0);
      }
    }
  }
LAB_00066550:
  if ((bVar2) && (*pcVar8 != '\0')) {
    Con_Printf("--------------\n%3i CVars for [%s]\nCvarList ? for syntax\n",pcVar12,pcVar8);
  }
  else {
    Con_Printf("--------------\n%3i Total CVars\nCvarList ? for syntax\n",pcVar12);
  }
  if (!bVar5) {
    return;
  }
  FS_Close(local_12c);
  Con_Printf("cvarlist logged to %s\n",local_11c);
  return;
}


// Cmd_Echo_f  @ 0005af30
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


// Cmd_Exec_f  @ 0005d8d0
/* WARNING: Removing unreachable block (ram,0x0005da3c) */
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
  byte bVar6;
  char local_2050 [4096];
  char local_1050 [4096];
  char *local_50 [12];
  uint local_20 [4];
  
                    /* Unresolved local var: char * pszFileName@[DW_OP_reg3(EBX)]
                       Unresolved local var: char * pszFileData@[???]
                       Unresolved local var: int nFileLength@[???]
                       Unresolved local var: char * pszFirstDot@[???]
                       Unresolved local var: char * pszLastDot@[???]
                       Unresolved local var: int nCurrentLen@[???]
                       Unresolved local var: int nAddLen@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  bVar6 = 0;
  pcVar5 = "";
  local_20[0] = 1;
  (*g_engdstAddrs.Cmd_Argv)((int *)local_20);
  if (((uint)cmd_argc <= local_20[0]) || (pcVar5 = cmd_argv[local_20[0]], pcVar5 != (char *)0x0)) {
    pcVar1 = Q_strstr(pcVar5,"\\");
    if ((pcVar1 == (char *)0x0) &&
       ((((pcVar1 = Q_strstr(pcVar5,":"), pcVar1 == (char *)0x0 &&
          (pcVar1 = Q_strstr(pcVar5,"~"), pcVar1 == (char *)0x0)) &&
         (pcVar1 = Q_strstr(pcVar5,".."), pcVar1 == (char *)0x0)) && (*pcVar5 != '/')))) {
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
            return;
          }
        }
        if (s_bCurrentCommandIsPrivileged == false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[4096] pchBuf@[???]
                       Unresolved local var: char[4096] pchCurMapCfg@[???]
                       Unresolved local var: char *[12] rgpszUnprivilegedWhitelist@[???] */
          pcVar1 = local_1050;
          for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
            pcVar1[0] = '\0';
            pcVar1[1] = '\0';
            pcVar1[2] = '\0';
            pcVar1[3] = '\0';
            pcVar1 = pcVar1 + (uint)bVar6 * -8 + 4;
          }
          local_50[0] = "mapdefault.cfg";
          local_50[1] = "scout.cfg";
          local_50[2] = "sniper.cfg";
          local_50[3] = "soldier.cfg";
          local_50[4] = "demoman.cfg";
          local_50[5] = "medic.cfg";
          local_50[6] = "hwguy.cfg";
          local_50[7] = "pyro.cfg";
          local_50[8] = "spy.cfg";
          local_50[9] = "engineer.cfg";
          local_50[10] = "civilian.cfg";
          local_50[0xb] = local_1050;
          pcVar1 = COM_FileBase_s(cl.levelname,local_2050,0x1000);
          if (pcVar1 != (char *)0x0) {
            snprintf(local_1050,0x1000,"%s.cfg",local_2050);
          }
          iVar3 = 0;
          do {
            iVar4 = Q_strcmp(pcVar5,local_50[iVar3]);
            if (iVar4 == 0) goto LAB_0005db28;
            iVar3 = iVar3 + 1;
          } while (iVar3 != 0xc);
          Con_Printf("exec %s: not privileged or in whitelist\n",pcVar5);
        }
        else {
LAB_0005db28:
          file = FS_OpenPathID(pcVar5,"rb","GAMECONFIG");
          if (((file == (FileHandle_t)0x0) &&
              (file = FS_OpenPathID(pcVar5,"rb","GAME"), file == (FileHandle_t)0x0)) &&
             (file = FS_Open(pcVar5,"rb"), file == (FileHandle_t)0x0)) {
            pcVar1 = Q_strstr(pcVar5,"autoexec.cfg");
            if (((pcVar1 == (char *)0x0) &&
                (pcVar1 = Q_strstr(pcVar5,"userconfig.cfg"), pcVar1 == (char *)0x0)) &&
               ((pcVar1 = Q_strstr(pcVar5,"hw/opengl.cfg"), pcVar1 == (char *)0x0 &&
                ((pcVar1 = Q_strstr(pcVar5,"joystick.cfg"), pcVar1 == (char *)0x0 &&
                 (pcVar1 = Q_strstr(pcVar5,"game.cfg"), pcVar1 == (char *)0x0)))))) {
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
                Cbuf_InsertTextLines(pcVar1);
              }
              else {
                while( true ) {
                  Cbuf_Execute();
                  pcVar5 = COM_ParseLine(pcVar5);
                  iVar3 = Q_strlen(com_token);
                  if (iVar3 < 1) break;
                    /* Unresolved local var: char * pszDataPtr@[???] */
                  Cbuf_InsertTextLines(com_token);
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
  }
  return;
}


// Cmd_Exec_f  @ 0005dd30
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


// Cmd_ExecuteString  @ 0005d710
void Cmd_ExecuteString(char *text,cmd_source_t src)

{
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmdalias_t * a@[???] */
  cmd_source = src;
  Cmd_TokenizeString(text);
  (*g_engdstAddrs.Cmd_Argc)();
  if (cmd_argc == 0) {
    return;
  }
  Cmd_ExecuteStringWithPrivilegeCheck(text,src_command,cmd_argc);
  return;
}


// Cmd_ExecuteStringWithPrivilegeCheck  @ 0005d4e0
void __regparm3
Cmd_ExecuteStringWithPrivilegeCheck(char *text,cmd_source_t src,qboolean bIsPrivileged)

{
  cmd_function_s *pcVar1;
  cmdalias_t *pcVar2;
  char *pcVar3;
  qboolean qVar4;
  int iVar5;
  sizebuf_t *buf;
  float fVar6;
  
  pcVar1 = cmd_functions;
  while( true ) {
    pcVar2 = cmd_alias;
    if (pcVar1 == (cmd_function_t *)0x0) {
      for (; pcVar2 != (cmdalias_t *)0x0; pcVar2 = pcVar2->next) {
        iVar5 = Q_strcasecmp(cmd_argv[0],pcVar2->name);
        if (iVar5 == 0) {
          buf = &cmd_text;
          if (src == src_client) {
            buf = &filteredcmd_text;
          }
          Cbuf_InsertTextToBuffer(pcVar2->value,buf,false);
          return;
        }
      }
      qVar4 = Cvar_CommandWithPrivilegeCheck(src);
      if ((qVar4 == false) &&
         (((cls.state == ca_connected || (cls.state == ca_active)) ||
          (cls.state == ca_uninitialized)))) {
        Cmd_ForwardToServer();
        return;
      }
      return;
    }
    iVar5 = Q_strcasecmp(cmd_argv[0],pcVar1->name);
    if (iVar5 == 0) break;
    pcVar1 = pcVar1->next;
  }
  if (src != src_client) {
LAB_0005d610:
    s_bCurrentCommandIsPrivileged = src;
    (*pcVar1->function)();
    s_bCurrentCommandIsPrivileged = true;
    if (cls.demorecording == false) {
      s_bCurrentCommandIsPrivileged = true;
      return;
    }
    if ((pcVar1->flags & 1) == 0) {
      s_bCurrentCommandIsPrivileged = true;
      return;
    }
    if (cls.spectator != false) {
      s_bCurrentCommandIsPrivileged = true;
      return;
    }
    CL_RecordHUDCommand(pcVar1->name);
    return;
  }
  if ((pcVar1->flags & 8) == 0) {
    fVar6 = Cvar_VariableValue("cl_filterstuffcmd");
    if (fVar6 <= 0.0) goto LAB_0005d610;
    if ((pcVar1->flags & 0x10) == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char *[5] rgpchFilterPrefixes@[???] */
      pcVar3 = Q_stristr(pcVar1->name,"cl_");
      if (pcVar3 != pcVar1->name) {
        pcVar3 = Q_stristr(pcVar1->name,"gl_");
        if (pcVar3 != pcVar1->name) {
          pcVar3 = Q_stristr(pcVar1->name,"m_");
          if (pcVar3 != pcVar1->name) {
            pcVar3 = Q_stristr(pcVar1->name,"r_");
            if ((pcVar3 != pcVar1->name) &&
               (pcVar3 = Q_stristr(pcVar1->name,"hud_"), pcVar3 != pcVar1->name)) goto LAB_0005d610;
          }
        }
      }
    }
  }
  Con_Printf("Could not execute privileged command %s\n",text);
  return;
}


// Cmd_Exists  @ 0005cfc0
qboolean Cmd_Exists(char *cmd_name)

{
  qboolean qVar1;
  int iVar2;
  cmd_function_s *pcVar3;
  
                    /* Unresolved local var: cmd_function_t * cmd@[???] */
  qVar1 = false;
  pcVar3 = cmd_functions;
  if (cmd_functions != (cmd_function_t *)0x0) {
    while (iVar2 = Q_strcmp(cmd_name,pcVar3->name), iVar2 != 0) {
      pcVar3 = pcVar3->next;
      if (pcVar3 == (cmd_function_s *)0x0) {
        return false;
      }
    }
    qVar1 = true;
  }
  return qVar1;
}


// Cmd_FindCmd  @ 0005c840
cmd_function_t * Cmd_FindCmd(char *cmd_name)

{
  cmd_function_s *pcVar1;
  int iVar2;
  
  pcVar1 = cmd_functions;
  while ((pcVar1 != (cmd_function_t *)0x0 && (iVar2 = Q_strcmp(cmd_name,pcVar1->name), iVar2 != 0)))
  {
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// Cmd_FindCmdPrev  @ 0005c880
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


// Cmd_ForwardToServer  @ 0005d440
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_ForwardToServer(void)

{
  char *pcVar1;
  int iVar2;
  uint local_10 [3];
  
  local_10[0] = 0;
  (*g_engdstAddrs.Cmd_Argv)((int *)local_10);
  pcVar1 = "";
  if (local_10[0] < (uint)cmd_argc) {
    pcVar1 = cmd_argv[local_10[0]];
  }
  iVar2 = Q_strcasecmp(pcVar1,"cmd");
  if (iVar2 == 0) {
    local_10[0] = 1;
    (*g_engdstAddrs.Cmd_Argv)((int *)local_10);
    pcVar1 = "";
    if (local_10[0] < (uint)cmd_argc) {
      pcVar1 = cmd_argv[local_10[0]];
    }
    iVar2 = Q_strcasecmp(pcVar1,"dlfile");
    if (iVar2 == 0) {
      return;
    }
  }
  Cmd_ForwardToServerInternal(&cls.netchan.message);
  return;
}


// Cmd_ForwardToServerInternal  @ 0005d1c0
int Cmd_ForwardToServerInternal(sizebuf_t *pBuf)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  byte local_102c [4096];
  sizebuf_t local_2c;
  uint local_10;
  
                    /* Unresolved local var: sizebuf_t tempBuf@[???]
                       Unresolved local var: char[4096] tempData@[???] */
  local_2c.flags = 1;
  local_2c.data = local_102c;
  local_2c.maxsize = 0x1000;
  local_2c.cursize = 0;
  local_2c.buffername = "Cmd_ForwardToServerInternal::tempBuf";
  if (cls.state - ca_connected < 3) {
    iVar1 = 0;
    if ((cls.demoplayback == false) && (g_bIsDedicatedServer == false)) {
      MSG_WriteByte(&local_2c,3);
      local_10 = 0;
      (*g_engdstAddrs.Cmd_Argv)((int *)&local_10);
      pcVar3 = "";
      if (local_10 < (uint)cmd_argc) {
        pcVar3 = cmd_argv[local_10];
      }
      iVar1 = Q_strcasecmp(pcVar3,"cmd");
      if (iVar1 != 0) {
        local_10 = 0;
        (*g_engdstAddrs.Cmd_Argv)((int *)&local_10);
        pcVar3 = "";
        if (local_10 < (uint)cmd_argc) {
          pcVar3 = cmd_argv[local_10];
        }
        SZ_Print(&local_2c,pcVar3);
        SZ_Print(&local_2c," ");
      }
      (*g_engdstAddrs.Cmd_Argc)();
      if (cmd_argc < 2) {
        SZ_Print(&local_2c,"\n");
      }
      else {
        SZ_Print(&local_2c,cmd_args);
      }
      iVar1 = 0;
      if (((local_2c.flags & 2) == 0) && (pBuf->cursize + local_2c.cursize <= pBuf->maxsize)) {
        SZ_Write(pBuf,local_2c.data,local_2c.cursize);
        iVar1 = 1;
      }
    }
  }
  else {
    local_10 = 0;
    (*g_engdstAddrs.Cmd_Argv)((int *)&local_10);
    pcVar3 = "";
    if (local_10 < (uint)cmd_argc) {
      pcVar3 = cmd_argv[local_10];
    }
    iVar2 = Q_stricmp(pcVar3,"setinfo");
    iVar1 = 0;
    if (iVar2 != 0) {
      local_10 = 0;
      (*g_engdstAddrs.Cmd_Argv)((int *)&local_10);
      pcVar3 = "";
      if (local_10 < (uint)cmd_argc) {
        pcVar3 = cmd_argv[local_10];
      }
      Con_Printf("Can\'t \"%s\", not connected\n",pcVar3);
      iVar1 = 0;
    }
  }
  return iVar1;
}


// Cmd_ForwardToServerUnreliable  @ 0005dd60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cmd_ForwardToServerUnreliable(void)

{
  int iVar1;
  
  iVar1 = Cmd_ForwardToServerInternal(&cls.datagram);
  return iVar1;
}


// Cmd_GetFirstCmd  @ 0005bc90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cmd_function_s * Cmd_GetFirstCmd(void)

{
  return cmd_functions;
}


// Cmd_Init  @ 0005bca0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Init(void)

{
  cmd_function_t *pcVar1;
  char *pcVar2;
  int iVar3;
  cmd_function_s *pcVar4;
  cmd_function_t *pcVar5;
  cmd_function_t *pcVar6;
  cmd_function_t local_1c;
  
  SetCStrikeFlags();
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???] */
  if (host_initialized != false) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar2 = Cvar_VariableString("stuffcmds");
  pcVar1 = cmd_functions;
  if (*pcVar2 == '\0') {
    for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_strcmp("stuffcmds",pcVar1->name);
      if (iVar3 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n","stuffcmds");
        goto LAB_0005bd16;
      }
    }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
    pcVar4 = Hunk_Alloc(0x10);
    pcVar1 = cmd_functions;
    local_1c.next = cmd_functions;
    pcVar4->name = "stuffcmds";
    pcVar4->function = Cmd_StuffCmds_f;
    pcVar4->flags = 0;
    local_1c.name = " ";
    pcVar6 = &local_1c;
    while (pcVar5 = pcVar1, pcVar5 != (cmd_function_t *)0x0) {
      iVar3 = strcasecmp(pcVar5->name,"stuffcmds");
      if (0 < iVar3) {
        pcVar6->next = pcVar4;
        cmd_functions = local_1c.next;
        pcVar4->next = pcVar5;
        goto LAB_0005bd16;
      }
      pcVar6 = pcVar5;
      pcVar1 = pcVar5->next;
    }
    pcVar6->next = pcVar4;
    cmd_functions = local_1c.next;
    pcVar4->next = (cmd_function_s *)0x0;
    if (g_bIsTFC == 0) goto LAB_0005c31a;
LAB_0005bd23:
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???] */
    if (host_initialized != false) {
      Sys_Error("Cmd_AddCommand after host_initialized");
    }
    pcVar2 = Cvar_VariableString("exec");
    pcVar1 = cmd_functions;
    if (*pcVar2 != '\0') goto LAB_0005c430;
    for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_strcmp("exec",pcVar1->name);
      if (iVar3 == 0) goto LAB_0005bd79;
    }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
    pcVar4 = Hunk_Alloc(0x10);
    pcVar1 = cmd_functions;
    local_1c.next = cmd_functions;
    pcVar4->name = "exec";
    pcVar4->function = Cmd_Exec_f;
    pcVar4->flags = 0;
    local_1c.name = " ";
    pcVar6 = &local_1c;
    while (pcVar5 = pcVar1, pcVar5 != (cmd_function_t *)0x0) {
      iVar3 = strcasecmp(pcVar5->name,"exec");
      if (0 < iVar3) goto LAB_0005c528;
      pcVar6 = pcVar5;
      pcVar1 = pcVar5->next;
    }
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n","stuffcmds");
LAB_0005bd16:
    if (g_bIsTFC != 0) goto LAB_0005bd23;
LAB_0005c31a:
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???] */
    if (host_initialized != false) {
      Sys_Error("Cmd_AddCommand after host_initialized");
    }
    pcVar2 = Cvar_VariableString("exec");
    pcVar1 = cmd_functions;
    if (*pcVar2 != '\0') {
LAB_0005c430:
      Con_Printf("Cmd_AddCommand: %s already defined as a var\n",&DAT_000e0b98);
      goto LAB_0005bd8e;
    }
    for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_strcmp("exec",pcVar1->name);
      if (iVar3 == 0) goto LAB_0005bd79;
    }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
    pcVar4 = Hunk_Alloc(0x10);
    pcVar1 = cmd_functions;
    local_1c.name = " ";
    local_1c.next = cmd_functions;
    pcVar4->name = "exec";
    pcVar4->function = Cmd_Exec_f;
    pcVar4->flags = 8;
    pcVar6 = &local_1c;
    while (pcVar5 = pcVar1, pcVar5 != (cmd_function_t *)0x0) {
      iVar3 = strcasecmp(pcVar5->name,"exec");
      if (0 < iVar3) goto LAB_0005c528;
      pcVar6 = pcVar5;
      pcVar1 = pcVar5->next;
    }
  }
  pcVar6->next = pcVar4;
  pcVar4->next = (cmd_function_s *)0x0;
  cmd_functions = local_1c.next;
LAB_0005bd8e:
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???] */
  if (host_initialized != false) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar2 = Cvar_VariableString("echo");
  pcVar1 = cmd_functions;
  if (*pcVar2 == '\0') {
    for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_strcmp("echo",pcVar1->name);
      if (iVar3 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n","echo");
        goto joined_r0x0005bdfe;
      }
    }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
    pcVar4 = Hunk_Alloc(0x10);
    pcVar1 = cmd_functions;
    local_1c.name = " ";
    local_1c.next = cmd_functions;
    pcVar4->name = "echo";
    pcVar4->function = Cmd_Echo_f;
    pcVar4->flags = 0;
    pcVar6 = &local_1c;
    while (pcVar5 = pcVar1, pcVar5 != (cmd_function_t *)0x0) {
      iVar3 = strcasecmp(pcVar5->name,"echo");
      if (0 < iVar3) {
        pcVar6->next = pcVar4;
        pcVar4->next = pcVar5;
        cmd_functions = local_1c.next;
        goto joined_r0x0005bdfe;
      }
      pcVar6 = pcVar5;
      pcVar1 = pcVar5->next;
    }
    pcVar6->next = pcVar4;
    pcVar4->next = (cmd_function_s *)0x0;
    cmd_functions = local_1c.next;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n","echo");
  }
joined_r0x0005bdfe:
  if (host_initialized != false) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar2 = Cvar_VariableString("alias");
  pcVar1 = cmd_functions;
  if (*pcVar2 == '\0') {
    for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_strcmp("alias",pcVar1->name);
      if (iVar3 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n","alias");
        goto joined_r0x0005be6d;
      }
    }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
    pcVar4 = Hunk_Alloc(0x10);
    pcVar1 = cmd_functions;
    local_1c.next = cmd_functions;
    pcVar4->name = "alias";
    pcVar4->function = Cmd_Alias_f;
    pcVar4->flags = 8;
    local_1c.name = " ";
    pcVar6 = &local_1c;
    while (pcVar5 = pcVar1, pcVar5 != (cmd_function_t *)0x0) {
      iVar3 = strcasecmp(pcVar5->name,"alias");
      if (0 < iVar3) {
        pcVar6->next = pcVar4;
        pcVar4->next = pcVar5;
        cmd_functions = local_1c.next;
        goto joined_r0x0005be6d;
      }
      pcVar6 = pcVar5;
      pcVar1 = pcVar5->next;
    }
    pcVar6->next = pcVar4;
    pcVar4->next = (cmd_function_s *)0x0;
    cmd_functions = local_1c.next;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n","alias");
  }
joined_r0x0005be6d:
  if (host_initialized != false) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar2 = Cvar_VariableString("cmd");
  pcVar1 = cmd_functions;
  if (*pcVar2 == '\0') {
    for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_strcmp("cmd",pcVar1->name);
      if (iVar3 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n","cmd");
        goto joined_r0x0005bede;
      }
    }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
    pcVar4 = Hunk_Alloc(0x10);
    pcVar1 = cmd_functions;
    local_1c.name = " ";
    local_1c.next = cmd_functions;
    pcVar4->name = "cmd";
    pcVar4->function = Cmd_ForwardToServer;
    pcVar4->flags = 0;
    pcVar6 = &local_1c;
    while (pcVar5 = pcVar1, pcVar5 != (cmd_function_t *)0x0) {
      iVar3 = strcasecmp(pcVar5->name,"cmd");
      if (0 < iVar3) {
        pcVar6->next = pcVar4;
        pcVar4->next = pcVar5;
        cmd_functions = local_1c.next;
        goto joined_r0x0005bede;
      }
      pcVar6 = pcVar5;
      pcVar1 = pcVar5->next;
    }
    pcVar6->next = pcVar4;
    pcVar4->next = (cmd_function_s *)0x0;
    cmd_functions = local_1c.next;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n","cmd");
  }
joined_r0x0005bede:
  if (host_initialized != false) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar2 = Cvar_VariableString("wait");
  pcVar1 = cmd_functions;
  if (*pcVar2 == '\0') {
    for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_strcmp("wait",pcVar1->name);
      if (iVar3 == 0) {
        Con_Printf("Cmd_AddCommand: %s already defined\n",&DAT_000e0ba3);
        goto joined_r0x0005bf4d;
      }
    }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
    pcVar4 = Hunk_Alloc(0x10);
    pcVar1 = cmd_functions;
    local_1c.next = cmd_functions;
    pcVar4->name = "wait";
    pcVar4->function = Cmd_Wait_f;
    pcVar4->flags = 0;
    local_1c.name = " ";
    pcVar6 = &local_1c;
    while (pcVar5 = pcVar1, pcVar5 != (cmd_function_t *)0x0) {
      iVar3 = strcasecmp(pcVar5->name,"wait");
      if (0 < iVar3) {
        pcVar6->next = pcVar4;
        pcVar4->next = pcVar5;
        cmd_functions = local_1c.next;
        goto joined_r0x0005bf4d;
      }
      pcVar6 = pcVar5;
      pcVar1 = pcVar5->next;
    }
    pcVar6->next = pcVar4;
    pcVar4->next = (cmd_function_s *)0x0;
    cmd_functions = local_1c.next;
  }
  else {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n",&DAT_000e0ba3);
  }
joined_r0x0005bf4d:
  if (host_initialized != false) {
    Sys_Error("Cmd_AddCommand after host_initialized");
  }
  pcVar2 = Cvar_VariableString("cmdlist");
  pcVar1 = cmd_functions;
  if (*pcVar2 != '\0') {
    Con_Printf("Cmd_AddCommand: %s already defined as a var\n","cmdlist");
    return;
  }
  for (; pcVar1 != (cmd_function_t *)0x0; pcVar1 = pcVar1->next) {
    iVar3 = Q_strcmp("cmdlist",pcVar1->name);
    if (iVar3 == 0) {
      Con_Printf("Cmd_AddCommand: %s already defined\n","cmdlist");
      return;
    }
  }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmd_function_t * c@[???]
                       Unresolved local var: cmd_function_t * n@[???]
                       Unresolved local var: cmd_function_t dummycmd@[???]
                       Unresolved local var: cmd_function_t * dummy@[???] */
  pcVar4 = Hunk_Alloc(0x10);
  pcVar1 = cmd_functions;
  local_1c.name = " ";
  local_1c.next = cmd_functions;
  pcVar4->name = "cmdlist";
  pcVar4->function = Cmd_CmdList_f;
  pcVar4->flags = 0;
  pcVar6 = &local_1c;
  while( true ) {
    pcVar5 = pcVar1;
    if (pcVar5 == (cmd_function_t *)0x0) {
      pcVar6->next = pcVar4;
      pcVar4->next = (cmd_function_s *)0x0;
      cmd_functions = local_1c.next;
      return;
    }
    iVar3 = strcasecmp(pcVar5->name,"cmdlist");
    if (0 < iVar3) break;
    pcVar1 = pcVar5->next;
    pcVar6 = pcVar5;
  }
  pcVar6->next = pcVar4;
  pcVar4->next = pcVar5;
  cmd_functions = local_1c.next;
  return;
LAB_0005bd79:
  Con_Printf("Cmd_AddCommand: %s already defined\n",&DAT_000e0b98);
  goto LAB_0005bd8e;
LAB_0005c528:
  pcVar6->next = pcVar4;
  pcVar4->next = pcVar5;
  cmd_functions = local_1c.next;
  goto LAB_0005bd8e;
}


// Cmd_RemoveGameCmds  @ 0005cf20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_RemoveGameCmds(void)

{
  cmd_function_s *pcVar1;
  cmd_function_s *pcVar2;
  cmd_function_t *p;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_s *)0x0;
  p = cmd_functions;
  while (p != (cmd_function_t *)0x0) {
    pcVar1 = p->next;
    if ((p->flags & 2) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      p = pcVar1;
    }
    else {
      Mem_Free(p);
      p = pcVar1;
    }
  }
  cmd_functions = pcVar2;
  return;
}


// Cmd_RemoveHudCmds  @ 0005ced0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_RemoveHudCmds(void)

{
  cmd_function_s *pcVar1;
  cmd_function_s *pcVar2;
  cmd_function_t *p;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_s *)0x0;
  p = cmd_functions;
  while (p != (cmd_function_t *)0x0) {
    pcVar1 = p->next;
    if ((p->flags & 1) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      p = pcVar1;
    }
    else {
      Mem_Free(p);
      p = pcVar1;
    }
  }
  cmd_functions = pcVar2;
  return;
}


// Cmd_RemoveMallocedCmds  @ 0005ce80
void Cmd_RemoveMallocedCmds(int flag)

{
  cmd_function_s *pcVar1;
  cmd_function_s *pcVar2;
  cmd_function_t *p;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_s *)0x0;
  p = cmd_functions;
  while (p != (cmd_function_t *)0x0) {
    pcVar1 = p->next;
    if ((p->flags & flag) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      p = pcVar1;
    }
    else {
      Mem_Free(p);
      p = pcVar1;
    }
  }
  cmd_functions = pcVar2;
  return;
}


// Cmd_RemoveWrapperCmds  @ 0005cf70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_RemoveWrapperCmds(void)

{
  cmd_function_s *pcVar1;
  cmd_function_s *pcVar2;
  cmd_function_t *p;
  
                    /* Unresolved local var: cmd_function_t * pNewList@[???]
                       Unresolved local var: cmd_function_t * pCmd@[???]
                       Unresolved local var: cmd_function_t * pNext@[???] */
  pcVar2 = (cmd_function_s *)0x0;
  p = cmd_functions;
  while (p != (cmd_function_t *)0x0) {
    pcVar1 = p->next;
    if ((p->flags & 4) == 0) {
      p->next = pcVar2;
      pcVar2 = p;
      p = pcVar1;
    }
    else {
      Mem_Free(p);
      p = pcVar1;
    }
  }
  cmd_functions = pcVar2;
  return;
}


// Cmd_Shutdown  @ 0005c660
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Shutdown(void)

{
  uint uVar1;
  
  cmd_functions = (cmd_function_t *)0x0;
  cmd_argc = 0;
  uVar1 = 0;
  do {
    *(undefined4 *)((int)cmd_argv + uVar1) = 0;
    *(undefined4 *)((int)cmd_argv + uVar1 + 4) = 0;
    *(undefined4 *)((int)cmd_argv + uVar1 + 8) = 0;
    *(undefined4 *)((int)cmd_argv + uVar1 + 0xc) = 0;
    uVar1 = uVar1 + 0x10;
  } while (uVar1 < 0x140);
  cmd_args = (char *)0x0;
  return;
}


// Cmd_StuffCmds_f  @ 0005b530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_StuffCmds_f(void)

{
  char *__src;
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *__s;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
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
  if (1 < com_argc) {
    iVar8 = 0;
    iVar6 = 1;
    iVar3 = com_argc;
    do {
      if (com_argv[iVar6] != (char *)0x0) {
        iVar3 = Q_strlen(com_argv[iVar6]);
        iVar8 = iVar3 + 1 + iVar8;
        iVar3 = com_argc;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
    if (iVar8 != 0) {
      iVar3 = iVar8 + -1;
      __s = Z_Malloc(iVar8 + 1);
      *__s = '\0';
      if (1 < com_argc) {
        iVar7 = 1;
        iVar6 = com_argc;
        do {
          pcVar5 = com_argv[iVar7];
          if (pcVar5 != (char *)0x0) {
            sVar4 = strlen(__s);
            strncat(__s,pcVar5,iVar3 - sVar4);
            iVar6 = com_argc;
            if (iVar7 != com_argc + -1) {
              Q_strcat(__s," ");
              iVar6 = com_argc;
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar6);
      }
      pcVar5 = Z_Malloc(iVar8 + 1);
      *pcVar5 = '\0';
      if (0 < iVar3) {
        iVar6 = 0;
        do {
          while (__s[iVar6] == '+') {
            iVar6 = iVar6 + 1;
            __src = __s + iVar6;
            cVar2 = *__src;
            pcVar1 = __src;
            while (((cVar2 != '-' && (cVar2 != '+')) && (cVar2 != '\0'))) {
              iVar6 = iVar6 + 1;
              pcVar1 = __s + iVar6;
              cVar2 = __s[iVar6];
            }
            *pcVar1 = '\0';
            sVar4 = strlen(pcVar5);
            strncat(pcVar5,__src,(iVar8 + -2) - sVar4);
            Q_strcat(pcVar5,"\n");
            *pcVar1 = cVar2;
            if (iVar3 <= iVar6) goto LAB_0005b6da;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar3);
LAB_0005b6da:
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


// Cmd_TokenizeString  @ 0005c710
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
    for (; (cVar2 = *text, (byte)(cVar2 - 1U) < 0x20 && (cVar2 != '\n')); text = text + 1) {
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


// Cmd_Wait_f  @ 0005af20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cmd_Wait_f(void)

{
  cmd_wait = true;
  return;
}


