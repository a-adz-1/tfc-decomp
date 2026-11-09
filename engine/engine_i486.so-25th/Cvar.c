// Cvar_CmdInit  @ 00043c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_CmdInit(void)

{
  Cmd_AddCommand("cvarlist",Cmd_CvarList_f);
  return;
}


// Cvar_Command  @ 000435e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Cvar_Command(void)

{
  qboolean qVar1;
  
  qVar1 = Cvar_CommandWithPrivilegeCheck(true);
  return qVar1;
}


// Cvar_CommandWithPrivilegeCheck  @ 00043290
qboolean Cvar_CommandWithPrivilegeCheck(qboolean bIsPrivileged)

{
  cvar_s *pcVar1;
  cvarhook_s *pcVar2;
  char *pcVar3;
  int iVar4;
  qboolean qVar5;
  char *pcVar6;
  int iVar7;
  cvar_s *pcVar8;
  float fVar9;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *local_20 [5];
  
                    /* Unresolved local var: char * firstToken@[???]
                       Unresolved local var: cvar_t * v@[???] */
                    /* Unresolved local var: qboolean bret@[???]
                       Unresolved local var: int tokens@[???]
                       Unresolved local var: char * name@[???] */
  iVar7 = 0;
  pcVar3 = Cmd_Argv(0);
  Cvar_IsMultipleTokens::firstToken[0] = '\0';
  while( true ) {
    pcVar3 = COM_Parse(pcVar3);
    iVar4 = Q_strlen(com_token);
    if (iVar4 < 1) break;
    if (iVar7 == 0) {
      iVar7 = 1;
      Q_strncpy(Cvar_IsMultipleTokens::firstToken,com_token,0x203);
      Cvar_IsMultipleTokens::firstToken[0x203] = '\0';
    }
    else {
      iVar7 = iVar7 + 1;
    }
  }
  if (iVar7 == 1) {
                    /* Unresolved local var: char * firstToken@[???]
                       Unresolved local var: cvar_t * v@[???] */
    local_28 = Cmd_Argv(0);
                    /* Unresolved local var: cvar_t * var@[???] */
    (*g_engdstAddrs.pfnGetCvarPointer)(&local_28);
    for (pcVar8 = cvar_vars; pcVar8 != (cvar_t *)0x0; pcVar8 = pcVar8->next) {
      iVar7 = Q_stricmp(local_28,pcVar8->name);
      if (iVar7 == 0) {
        if (bIsPrivileged != false) goto LAB_00043491;
        if ((pcVar8->flags & 0x400) != 0) {
          Con_Printf("%s is a privileged variable\n",pcVar8->name);
          return true;
        }
        local_24 = "cl_filterstuffcmd";
                    /* Unresolved local var: cvar_t * var@[???] */
        (*g_engdstAddrs.pfnGetCvarPointer)(&local_24);
        pcVar1 = cvar_vars;
        goto joined_r0x000433f9;
      }
    }
  }
  else {
                    /* Unresolved local var: cvar_t * var@[???] */
    local_2c = Cvar_IsMultipleTokens::firstToken;
    (*g_engdstAddrs.pfnGetCvarPointer)(&local_2c);
    for (pcVar8 = cvar_vars; pcVar8 != (cvar_t *)0x0; pcVar8 = pcVar8->next) {
      iVar7 = Q_stricmp(local_2c,pcVar8->name);
      if (iVar7 == 0) goto LAB_00043345;
    }
  }
  return false;
joined_r0x000433f9:
  if (pcVar1 == (cvar_t *)0x0) goto LAB_00043491;
  iVar7 = Q_stricmp(local_24,pcVar1->name);
  if (iVar7 == 0) {
    fVar9 = Q_atof(pcVar1->string);
    if (0.0 < fVar9) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char *[5] rgpchFilterPrefixes@[???] */
      local_20[3] = "r_";
      local_20[0] = "cl_";
      local_20[1] = "gl_";
      local_20[2] = "m_";
      local_20[4] = "hud_";
      if ((pcVar8->flags & 0x800) != 0) {
        Con_Printf("%s is a privileged variable\n",pcVar8->name);
        return true;
      }
      pcVar3 = pcVar8->name;
      iVar7 = 0;
      do {
        pcVar6 = Q_stristr(pcVar3,local_20[iVar7]);
        pcVar3 = pcVar8->name;
        if (pcVar6 == pcVar3) {
          Con_Printf("%s is a privileged variable\n",pcVar3);
          return true;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 5);
    }
    goto LAB_00043491;
  }
  pcVar1 = pcVar1->next;
  goto joined_r0x000433f9;
LAB_00043491:
  iVar7 = Cmd_Argc();
  if (iVar7 == 1) {
LAB_00043345:
    Con_Printf("\"%s\" is \"%s\"\n",pcVar8->name,pcVar8->string);
  }
  else if (((((pcVar8->flags & 0x40U) == 0) || (cls.state < ca_connecting)) ||
           (((pcVar8->flags & 4U) != 0 && (qVar5 = Host_IsServerActive(), qVar5 != false)))) ||
          (cl.maxclients < 2)) {
    pcVar6 = Cmd_Argv(1);
    pcVar3 = pcVar8->name;
                    /* Unresolved local var: cvar_t * var@[???]
                       Unresolved local var: cvarhook_t * pHook@[???] */
    local_20[0] = pcVar3;
    (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
    for (pcVar8 = cvar_vars; pcVar8 != (cvar_s *)0x0; pcVar8 = pcVar8->next) {
      iVar7 = Q_stricmp(local_20[0],pcVar8->name);
      if (iVar7 == 0) {
        Cvar_DirectSet(pcVar8,pcVar6);
        pcVar2 = cvar_hooks;
        while( true ) {
          if (pcVar2 == (cvarhook_t *)0x0) {
            return true;
          }
          if (pcVar2->cvar == pcVar8) break;
          pcVar2 = pcVar2->next;
        }
        (*pcVar2->hook)(pcVar8);
        return true;
      }
    }
    Con_DPrintf("Cvar_Set: variable %s not found\n",pcVar3);
  }
  else {
    Con_Printf("Can\'t set %s in multiplayer\n",pcVar8->name);
  }
  return true;
}


// Cvar_CompleteVariable  @ 00042870
char * Cvar_CompleteVariable(char *search,int forward)

{
  char cVar1;
  int iVar2;
  cvar_s *pcVar3;
  int count;
  int iVar4;
  char *pcVar5;
  cvar_s *pcVar6;
  cvar_t *pcVar7;
  int in_GS_OFFSET;
  undefined4 local_124;
  char local_120 [255];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[256] partial@[???]
                       Unresolved local var: cvar_t * cvar@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char * pPartial@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_strncpy(local_120,search,0xff);
  local_21 = 0;
  count = Q_strlen(local_120);
  if (count != 0) {
    cVar1 = local_120[count + -1];
    iVar4 = count + -1;
    while (iVar2 = iVar4, cVar1 == ' ') {
      local_120[iVar2] = '\0';
      iVar4 = iVar2 + -1;
      count = iVar2;
      cVar1 = local_120[iVar2 + -1];
    }
    iVar4 = Q_stricmp(local_120,Cvar_CompleteVariable::lastpartial);
    pcVar3 = cvar_vars;
    if (iVar4 != 0) goto joined_r0x00042908;
                    /* Unresolved local var: cvar_t * var@[???] */
    local_124 = local_120;
    (*g_engdstAddrs.pfnGetCvarPointer)((char **)&local_124);
    pcVar6 = cvar_vars;
    if (cvar_vars != (cvar_t *)0x0) {
      do {
        iVar4 = Q_stricmp(local_124,pcVar6->name);
        pcVar3 = cvar_vars;
        if (iVar4 == 0) {
          if (forward == 1) {
            pcVar7 = pcVar6->next;
            goto LAB_00042a14;
          }
          pcVar5 = pcVar6->name;
                    /* Unresolved local var: cvar_t * var@[???] */
          pcVar6 = cvar_vars->next;
          pcVar7 = cvar_vars;
          if (pcVar6 != (cvar_s *)0x0) goto LAB_000429f2;
          break;
        }
        pcVar6 = pcVar6->next;
      } while (pcVar6 != (cvar_s *)0x0);
      goto joined_r0x00042908;
    }
  }
LAB_00042965:
  pcVar5 = (char *)0x0;
  goto LAB_00042967;
  while( true ) {
    pcVar7 = pcVar7->next;
    pcVar6 = pcVar7->next;
    pcVar3 = cvar_vars;
    if (pcVar6 == (cvar_s *)0x0) break;
LAB_000429f2:
    iVar4 = Q_stricmp(pcVar5,pcVar6->name);
    if (iVar4 == 0) goto LAB_00042a14;
  }
joined_r0x00042908:
  do {
    pcVar7 = pcVar3;
    if (pcVar7 == (cvar_t *)0x0) goto LAB_00042965;
    iVar4 = Q_strncmp(local_120,pcVar7->name,count);
    if (iVar4 == 0) {
      iVar4 = Q_strlen(pcVar7->name);
      if (iVar4 == count) goto LAB_00042a18;
      pcVar5 = pcVar7->name;
      Q_strncpy(Cvar_CompleteVariable::lastpartial,pcVar5,0xff);
      Cvar_CompleteVariable::lastpartial[0xff] = '\0';
      goto LAB_00042967;
    }
    pcVar3 = pcVar7->next;
  } while( true );
LAB_00042a14:
  pcVar3 = cvar_vars;
  if (pcVar7 == (cvar_t *)0x0) goto joined_r0x00042908;
LAB_00042a18:
  Q_strncpy(Cvar_CompleteVariable::lastpartial,pcVar7->name,0xff);
  Cvar_CompleteVariable::lastpartial[0xff] = '\0';
  pcVar5 = pcVar7->name;
LAB_00042967:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pcVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Cvar_CountServerVariables  @ 00043c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cvar_CountServerVariables(void)

{
  cvar_s **ppcVar1;
  int iVar2;
  cvar_s *pcVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: cvar_t * var@[???] */
  iVar2 = 0;
  pcVar3 = cvar_vars;
  if (cvar_vars == (cvar_t *)0x0) {
    return iVar2;
  }
  do {
    ppcVar1 = &pcVar3->next;
    iVar2 = iVar2 + ((uint)pcVar3->flags >> 2 & 1);
    pcVar3 = *ppcVar1;
  } while (*ppcVar1 != (cvar_s *)0x0);
  return iVar2;
}


// Cvar_DirectSet  @ 00042a50
void Cvar_DirectSet(cvar_s *var,char *value)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  qboolean qVar5;
  size_t sVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  float fVar8;
  char local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: qboolean changed@[???]
                       Unresolved local var: char * pszValue@[???]
                       Unresolved local var: char[1024] szNew@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((var == (cvar_s *)0x0) || (value == (char *)0x0)) goto LAB_00042ad3;
  uVar4 = var->flags;
  if ((uVar4 & 0x2000) != 0) {
    if ((((*value == '/') || (pcVar2 = Q_strstr(value,":"), pcVar2 != (char *)0x0)) ||
        (pcVar2 = Q_strstr(value,".."), pcVar2 != (char *)0x0)) ||
       (pcVar2 = Q_strstr(value,"\\"), pcVar2 != (char *)0x0)) {
      Con_Printf("Refusing to set %s to %s (invalid path)\n",var->name,value);
      goto LAB_00042ad3;
    }
    uVar4 = var->flags;
  }
  if ((uVar4 & 0x80) == 0) {
    if ((uVar4 & 0x200) == 0) {
      if ((uVar4 & 0x1000) == 0) goto LAB_00042b7c;
                    /* Unresolved local var: char * k_pchFilterChars@[???] */
      Q_strncpy_s(local_420,value,0x400);
    }
    else {
      Q_strncpy_s(local_420,value,0x400);
LAB_00042b6a:
      value = local_420;
      Q_StripUnprintableAndSpace(value);
      if ((var->flags & 0x1000) == 0) goto LAB_00042b7c;
    }
LAB_00042cb2:
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???] */
    value = local_420;
    sVar6 = strcspn(value,";\n");
    local_420[sVar6] = '\0';
  }
  else {
                    /* Unresolved local var: char * pS@[???]
                       Unresolved local var: char * pD@[???] */
    local_420[0] = '\0';
    qVar5 = Q_UnicodeValidate(value);
    if (qVar5 == 0) {
      pcVar2 = local_420;
      while( true ) {
        pcVar7 = value + 1;
        cVar1 = *value;
        if (cVar1 == '\0') break;
        value = pcVar7;
        if ((byte)(cVar1 - 0x20U) < 0x5f) {
          *pcVar2 = cVar1;
          pcVar2 = pcVar2 + 1;
        }
      }
      *pcVar2 = '\0';
    }
    else {
      pcVar2 = local_420;
      Q_strncpy_s(pcVar2,value,0x400);
    }
    value = local_420;
    qVar5 = Q_UnicodeValidate(pcVar2);
    if (qVar5 == 0) {
      Q_UnicodeRepair(pcVar2);
    }
    iVar3 = Q_strlen(value);
    if (iVar3 == 0) {
      Q_strcpy(value,"empty");
    }
    if ((var->flags & 0x200U) != 0) goto LAB_00042b6a;
    if ((var->flags & 0x1000U) != 0) goto LAB_00042cb2;
  }
LAB_00042b7c:
  iVar3 = Q_strcmp(var->string,value);
  uVar4 = var->flags;
  if (((uVar4 & 2) != 0) && (cls.state == ca_dedicated)) {
    pcVar2 = var->name;
    pcVar7 = Info_Serverinfo();
    Info_SetValueForKey(pcVar7,pcVar2,value,0x200);
    pcVar2 = Info_Serverinfo();
    SV_BroadcastCommand("fullserverinfo \"%s\"\n",pcVar2);
    uVar4 = var->flags;
  }
  if (((uVar4 & 4) != 0) && (iVar3 != 0)) {
                    /* Unresolved local var: char * szVal@[???] */
    if ((uVar4 & 0x100) == 0) {
      if ((uVar4 & 0x20) == 0) {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,value);
        pcVar2 = value;
      }
      else {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,"***PROTECTED***");
        pcVar2 = "***PROTECTED***";
      }
      SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",var->name,pcVar2);
      uVar4 = var->flags;
    }
    pcVar2 = value;
    if ((uVar4 & 0x20) != 0) {
      iVar3 = Q_strlen(value);
      if (0 < iVar3) {
        iVar3 = Q_stricmp(value,"none");
        pcVar2 = "1";
        if (iVar3 != 0) goto LAB_00042bfd;
      }
      pcVar2 = "0";
    }
LAB_00042bfd:
    Steam_SetCVar(var->name,pcVar2);
  }
  Z_Free(var->string);
  iVar3 = Q_strlen(value);
  pcVar2 = Z_Malloc(iVar3 + 1);
  var->string = pcVar2;
  Q_strcpy(pcVar2,value);
  fVar8 = Q_atof(var->string);
  var->value = fVar8;
LAB_00042ad3:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Cvar_FindPrevVar  @ 00042700
cvar_t * Cvar_FindPrevVar(char *var_name)

{
  cvar_s *pcVar1;
  cvar_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: cvar_t * var@[???] */
  pcVar1 = cvar_vars->next;
  pcVar2 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_s *)0x0) {
      return (cvar_t *)0x0;
    }
    iVar3 = Q_stricmp(var_name,pcVar1->name);
    if (iVar3 == 0) break;
    pcVar2 = pcVar2->next;
    pcVar1 = pcVar2->next;
  }
  return pcVar2;
}


// Cvar_FindVar  @ 000426b0
cvar_t * Cvar_FindVar(char *var_name)

{
  cvar_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: cvar_t * var@[???] */
  (*g_engdstAddrs.pfnGetCvarPointer)(&var_name);
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return (cvar_t *)0x0;
    }
    iVar2 = Q_stricmp(var_name,pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// Cvar_HookVariable  @ 00043c80
qboolean Cvar_HookVariable(char *var_name,cvarhook_t *pHook)

{
  cvar_s *pcVar1;
  cvarhook_s *pcVar2;
  int iVar3;
  cvarhook_t *pcVar4;
  char *local_10 [2];
  
                    /* Unresolved local var: cvar_t * cvar@[???] */
  if ((((pHook != (cvarhook_t *)0x0) && (pHook->hook != (pfnCvar_HookVariable_t)0x0)) &&
      (pHook->cvar == (cvar_t *)0x0)) && (pHook->next == (cvarhook_s *)0x0)) {
    local_10[0] = var_name;
                    /* Unresolved local var: cvar_t * var@[???] */
    (*g_engdstAddrs.pfnGetCvarPointer)(local_10);
    for (pcVar1 = cvar_vars; pcVar1 != (cvar_t *)0x0; pcVar1 = pcVar1->next) {
      iVar3 = Q_stricmp(local_10[0],pcVar1->name);
      pcVar2 = cvar_hooks;
      if (iVar3 == 0) {
        pHook->cvar = pcVar1;
        if (pcVar2 == (cvarhook_t *)0x0) {
          cvar_hooks = pHook;
          return true;
        }
        do {
          pcVar4 = pcVar2;
          pcVar2 = pcVar4->next;
        } while (pcVar2 != (cvarhook_s *)0x0);
        pcVar4->next = pHook;
        return true;
      }
    }
  }
  return false;
}


// Cvar_Init  @ 00042690
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_Init(void)

{
  return;
}


// Cvar_IsMultipleTokens  @ 00043200
char * Cvar_IsMultipleTokens(char *varname)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: qboolean bret@[???]
                       Unresolved local var: int tokens@[???]
                       Unresolved local var: char * name@[???] */
  iVar3 = 0;
  Cvar_IsMultipleTokens::firstToken[0] = '\0';
  while( true ) {
    varname = COM_Parse(varname);
    iVar1 = Q_strlen(com_token);
    if (iVar1 < 1) break;
    if (iVar3 == 0) {
      iVar3 = 1;
      Q_strncpy(Cvar_IsMultipleTokens::firstToken,com_token,0x203);
      Cvar_IsMultipleTokens::firstToken[0x203] = '\0';
    }
    else {
      iVar3 = iVar3 + 1;
    }
  }
  pcVar2 = Cvar_IsMultipleTokens::firstToken;
  if (iVar3 == 1) {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


// Cvar_RegisterVariable  @ 00043040
void Cvar_RegisterVariable(cvar_t *variable)

{
  cvar_s *pcVar1;
  char *str;
  cvar_t *pcVar2;
  qboolean qVar3;
  int iVar4;
  char *dest;
  cvar_t *pcVar5;
  cvar_t *pcVar6;
  float fVar7;
  char *local_24;
  cvar_t local_20;
  
                    /* Unresolved local var: char * oldstr@[???]
                       Unresolved local var: cvar_t * dummy@[???]
                       Unresolved local var: cvar_t * v@[???]
                       Unresolved local var: cvar_t * n@[???]
                       Unresolved local var: cvar_t dummyvar@[???] */
  local_24 = variable->name;
                    /* Unresolved local var: cvar_t * var@[???] */
  (*g_engdstAddrs.pfnGetCvarPointer)(&local_24);
  for (pcVar1 = cvar_vars; pcVar1 != (cvar_t *)0x0; pcVar1 = pcVar1->next) {
    iVar4 = Q_stricmp(local_24,pcVar1->name);
    if (iVar4 == 0) {
      Con_Printf("Can\'t register variable %s, already defined\n",variable->name);
      return;
    }
  }
  qVar3 = Cmd_Exists(variable->name);
  if (qVar3 == false) {
    str = variable->string;
    iVar4 = Q_strlen(str);
    dest = Z_Malloc(iVar4 + 1);
    variable->string = dest;
    Q_strcpy(dest,str);
    fVar7 = Q_atof(variable->string);
    pcVar2 = cvar_vars;
    local_20.name = " ";
    local_20.next = cvar_vars;
    variable->value = fVar7;
    pcVar6 = &local_20;
    while (pcVar5 = pcVar2, pcVar5 != (cvar_t *)0x0) {
      iVar4 = strcasecmp(pcVar5->name,variable->name);
      if (0 < iVar4) {
        pcVar6->next = variable;
        variable->next = pcVar5;
        cvar_vars = local_20.next;
        return;
      }
      pcVar6 = pcVar5;
      pcVar2 = pcVar5->next;
    }
    pcVar6->next = variable;
    cvar_vars = local_20.next;
    variable->next = (cvar_s *)0x0;
  }
  else {
    Con_Printf("Cvar_RegisterVariable: %s is a command\n",variable->name);
  }
  return;
}


// Cvar_RemoveHudCvars  @ 00043180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_RemoveHudCvars(void)

{
  cvar_s *pcVar1;
  cvar_t *pcVar2;
  cvar_s *ptr;
  
                    /* Unresolved local var: cvar_t * pNewList@[???]
                       Unresolved local var: cvar_t * pCvar@[???]
                       Unresolved local var: cvar_t * pNext@[???] */
  if (cvar_vars != (cvar_t *)0x0) {
    pcVar1 = cvar_vars;
    pcVar2 = (cvar_t *)0x0;
    do {
      while (ptr = pcVar1, pcVar1 = ptr->next, (ptr->flags & 0x10) == 0) {
        ptr->next = pcVar2;
        pcVar2 = ptr;
        if (pcVar1 == (cvar_s *)0x0) goto LAB_000431c5;
      }
      Z_Free(ptr->string);
      Z_Free(ptr);
      ptr = pcVar2;
    } while (pcVar1 != (cvar_s *)0x0);
LAB_000431c5:
    cvar_vars = (cvar_t *)0x0;
    if (ptr != (cvar_t *)0x0) {
      pcVar2 = (cvar_t *)0x0;
      do {
        cvar_vars = ptr;
        ptr = cvar_vars->next;
        cvar_vars->next = pcVar2;
        pcVar2 = cvar_vars;
      } while (ptr != (cvar_s *)0x0);
    }
  }
  return;
}


// Cvar_Set  @ 00042e10
void Cvar_Set(char *var_name,char *value)

{
  cvar_s *var;
  cvarhook_s *pcVar1;
  int iVar2;
  char *local_10 [2];
  
                    /* Unresolved local var: cvar_t * var@[???]
                       Unresolved local var: cvarhook_t * pHook@[???] */
                    /* Unresolved local var: cvar_t * var@[???] */
  local_10[0] = var_name;
  (*g_engdstAddrs.pfnGetCvarPointer)(local_10);
  var = cvar_vars;
  while( true ) {
    if (var == (cvar_s *)0x0) {
      Con_DPrintf("Cvar_Set: variable %s not found\n",var_name);
      return;
    }
    iVar2 = Q_stricmp(local_10[0],var->name);
    if (iVar2 == 0) break;
    var = var->next;
  }
  Cvar_DirectSet(var,value);
  pcVar1 = cvar_hooks;
  while( true ) {
    if (pcVar1 == (cvarhook_t *)0x0) {
      return;
    }
    if (pcVar1->cvar == var) break;
    pcVar1 = pcVar1->next;
  }
  (*pcVar1->hook)(var);
  return;
}


// Cvar_SetValue  @ 00042ec0
void Cvar_SetValue(char *var_name,float value)

{
  cvar_s *pcVar1;
  cvar_s *var;
  cvarhook_s *pcVar2;
  char *pcVar3;
  int iVar4;
  int in_GS_OFFSET;
  char *local_40 [3];
  char *local_34;
  char local_30 [32];
  int local_10;
  
                    /* Unresolved local var: char[32] val@[???] */
  local_40[0] = var_name;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engdstAddrs.Cvar_SetValue)(local_40,&value);
  if (ABS(value - (float)(int)value) < 1e-06) {
    __snprintf_chk(local_30,0x20,1,0x20,&DAT_000d153e,(int)value);
  }
  else {
    __snprintf_chk(local_30,0x20,1,0x20,"%f",(double)value);
  }
  pcVar3 = local_40[0];
                    /* Unresolved local var: cvar_t * var@[???]
                       Unresolved local var: cvarhook_t * pHook@[???] */
  local_34 = local_40[0];
  (*g_engdstAddrs.pfnGetCvarPointer)(&local_34);
  for (var = cvar_vars; var != (cvar_s *)0x0; var = var->next) {
    iVar4 = Q_stricmp(local_34,var->name);
    if (iVar4 == 0) {
      Cvar_DirectSet(var,local_30);
      if (cvar_hooks == (cvarhook_t *)0x0) goto LAB_00042fbc;
      pcVar1 = cvar_hooks->cvar;
      pcVar2 = cvar_hooks;
      goto joined_r0x00042fa5;
    }
  }
  Con_DPrintf("Cvar_Set: variable %s not found\n",pcVar3);
LAB_00042fbc:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
joined_r0x00042fa5:
  if (var == pcVar1) goto LAB_00042fe8;
  pcVar2 = pcVar2->next;
  if (pcVar2 == (cvarhook_s *)0x0) goto LAB_00042fbc;
  pcVar1 = pcVar2->cvar;
  goto joined_r0x00042fa5;
LAB_00042fe8:
  (*pcVar2->hook)(var);
  goto LAB_00042fbc;
}


// Cvar_Shutdown  @ 000426a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_Shutdown(void)

{
  cvar_vars = (cvar_t *)0x0;
  return;
}


// Cvar_UnlinkExternals  @ 00043c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_UnlinkExternals(void)

{
  cvar_s *pcVar1;
  cvar_s *pcVar2;
  cvar_t **ppcVar3;
  
                    /* Unresolved local var: cvar_t * pVar@[???]
                       Unresolved local var: cvar_t * * pList@[???] */
  ppcVar3 = &cvar_vars;
  pcVar2 = cvar_vars;
  do {
    if (pcVar2 == (cvar_t *)0x0) {
      return;
    }
    while ((pcVar2->flags & 8) != 0) {
      pcVar1 = pcVar2->next;
      *ppcVar3 = pcVar1;
      pcVar2 = pcVar2->next;
      if (pcVar1 == (cvar_s *)0x0) {
        return;
      }
    }
    ppcVar3 = &pcVar2->next;
    pcVar2 = pcVar2->next;
  } while( true );
}


// Cvar_VariableInt  @ 000427b0
int Cvar_VariableInt(char *var_name)

{
  cvar_s *pcVar1;
  int iVar2;
  char *local_10 [3];
  
                    /* Unresolved local var: cvar_t * var@[???] */
  local_10[0] = var_name;
                    /* Unresolved local var: cvar_t * var@[???] */
  (*g_engdstAddrs.pfnGetCvarPointer)(local_10);
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return 0;
    }
    iVar2 = Q_stricmp(local_10[0],pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  iVar2 = Q_atoi(pcVar1->string);
  return iVar2;
}


// Cvar_VariableString  @ 00042810
char * Cvar_VariableString(char *var_name)

{
  cvar_s *pcVar1;
  int iVar2;
  char *local_10 [3];
  
                    /* Unresolved local var: cvar_t * var@[???] */
  local_10[0] = var_name;
                    /* Unresolved local var: cvar_t * var@[???] */
  (*g_engdstAddrs.pfnGetCvarPointer)(local_10);
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return cvar_null_string;
    }
    iVar2 = Q_stricmp(local_10[0],pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1->string;
}


// Cvar_VariableValue  @ 00042750
float Cvar_VariableValue(char *var_name)

{
  cvar_s *pcVar1;
  int iVar2;
  float fVar3;
  char *local_10 [3];
  
                    /* Unresolved local var: cvar_t * var@[???] */
  local_10[0] = var_name;
                    /* Unresolved local var: cvar_t * var@[???] */
  (*g_engdstAddrs.pfnGetCvarPointer)(local_10);
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return 0.0;
    }
    iVar2 = Q_stricmp(local_10[0],pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  fVar3 = Q_atof(pcVar1->string);
  return fVar3;
}


// Cvar_WriteVariables  @ 00043600
void Cvar_WriteVariables(FileHandle_t f)

{
  cvar_s *pcVar1;
  
  pcVar1 = cvar_vars;
  do {
    if (pcVar1 == (cvar_t *)0x0) {
      return;
    }
    while ((pcVar1->flags & 1) == 0) {
      pcVar1 = pcVar1->next;
      if (pcVar1 == (cvar_s *)0x0) {
        return;
      }
    }
    FS_FPrintf(f,"%s \"%s\"\n",pcVar1->name,pcVar1->string);
    pcVar1 = pcVar1->next;
  } while( true );
}


