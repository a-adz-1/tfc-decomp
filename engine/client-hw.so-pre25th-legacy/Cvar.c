// Cvar_CmdInit  @ 00110c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_CmdInit(void)

{
  Cmd_AddCommand("cvarlist",Cmd_CvarList_f);
  return;
}


// Cvar_Command  @ 001102c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Cvar_Command(void)

{
  char *pcVar1;
  int iVar2;
  char *value;
  qboolean qVar3;
  cvarhook_s *pcVar4;
  int iVar5;
  cvar_s *pcVar6;
  char *local_20 [4];
  
                    /* Unresolved local var: char * firstToken@[???]
                       Unresolved local var: cvar_t * v@[???]
                       Unresolved local var: qboolean bret@[???]
                       Unresolved local var: int tokens@[???]
                       Unresolved local var: char * name@[???] */
  iVar5 = 0;
  pcVar1 = Cmd_Argv(0);
  Cvar_IsMultipleTokens::firstToken[0] = '\0';
  while( true ) {
    pcVar1 = COM_Parse(pcVar1);
    iVar2 = Q_strlen(com_token);
    if (iVar2 < 1) break;
    if (iVar5 == 0) {
      iVar5 = 1;
      Q_strncpy(Cvar_IsMultipleTokens::firstToken,com_token,0x203);
      Cvar_IsMultipleTokens::firstToken[0x203] = '\0';
    }
    else {
      iVar5 = iVar5 + 1;
    }
  }
  if (iVar5 == 1) {
    local_20[0] = Cmd_Argv(0);
    (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
    for (pcVar6 = cvar_vars; pcVar6 != (cvar_t *)0x0; pcVar6 = pcVar6->next) {
      iVar5 = Q_stricmp(local_20[0],pcVar6->name);
      if (iVar5 == 0) {
        iVar5 = Cmd_Argc();
        if (iVar5 != 1) {
          if (((((pcVar6->flags & 0x40U) != 0) && (ca_disconnected < cls.state)) &&
              (((pcVar6->flags & 4U) == 0 || (qVar3 = Host_IsServerActive(), qVar3 == false)))) &&
             (1 < cl.maxclients)) {
            Con_Printf("Can\'t set %s in multiplayer\n",pcVar6->name);
            return true;
          }
          value = Cmd_Argv(1);
          pcVar1 = pcVar6->name;
          local_20[0] = pcVar1;
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg3(EBX)]
                       Unresolved local var: cvarhook_t * pHook@[???]
                       Unresolved local var: cvar_t * var@[???] */
          (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
          pcVar6 = cvar_vars;
          while( true ) {
            if (pcVar6 == (cvar_s *)0x0) {
              Con_DPrintf("Cvar_Set: variable %s not found\n",pcVar1);
              return true;
            }
            iVar5 = Q_stricmp(local_20[0],pcVar6->name);
            if (iVar5 == 0) break;
            pcVar6 = pcVar6->next;
          }
          Cvar_DirectSet(pcVar6,value);
          pcVar4 = cvar_hooks;
          if (cvar_hooks != (cvarhook_t *)0x0) {
            do {
              if (pcVar4->cvar == pcVar6) {
                (*pcVar4->hook)(pcVar6);
                return true;
              }
              pcVar4 = pcVar4->next;
            } while (pcVar4 != (cvarhook_s *)0x0);
            return true;
          }
          return true;
        }
        goto LAB_0011037d;
      }
    }
  }
  else {
                    /* Unresolved local var: cvar_t * var@[???] */
    local_20[0] = Cvar_IsMultipleTokens::firstToken;
    (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
    pcVar6 = cvar_vars;
    if (cvar_vars == (cvar_t *)0x0) {
      return false;
    }
    do {
      iVar5 = Q_stricmp(local_20[0],pcVar6->name);
      if (iVar5 == 0) {
LAB_0011037d:
        Con_Printf("\"%s\" is \"%s\"\n",pcVar6->name,pcVar6->string);
        return true;
      }
      pcVar6 = pcVar6->next;
    } while (pcVar6 != (cvar_s *)0x0);
  }
                    /* Unresolved local var: cvar_t * var@[???] */
  return false;
}


// Cvar_CommandWithPrivilegeCheck  @ 0010ff00
qboolean Cvar_CommandWithPrivilegeCheck(qboolean bIsPrivileged)

{
  cvar_s *pcVar1;
  cvarhook_s *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  qboolean qVar6;
  int iVar7;
  cvar_s *pcVar8;
  float fVar9;
  char *local_20 [4];
  
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
    local_20[0] = Cmd_Argv(0);
    (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
    for (pcVar8 = cvar_vars; pcVar8 != (cvar_t *)0x0; pcVar8 = pcVar8->next) {
      iVar7 = Q_stricmp(local_20[0],pcVar8->name);
      if (iVar7 == 0) {
        if (bIsPrivileged != false) goto LAB_0011016e;
        if ((pcVar8->flags & 0x400) != 0) goto LAB_0011022e;
        local_20[0] = "cl_filterstuffcmd";
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg6(ESI)]
                       Unresolved local var: cvar_t * var@[???] */
        (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
        pcVar1 = cvar_vars;
        goto joined_r0x0011006d;
      }
    }
  }
  else {
    local_20[0] = Cvar_IsMultipleTokens::firstToken;
                    /* Unresolved local var: cvar_t * var@[???] */
    (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
    pcVar8 = cvar_vars;
    if (cvar_vars == (cvar_t *)0x0) {
      return false;
    }
    do {
      iVar7 = Q_stricmp(local_20[0],pcVar8->name);
      if (iVar7 == 0) goto LAB_0010ffbd;
      pcVar8 = pcVar8->next;
    } while (pcVar8 != (cvar_s *)0x0);
  }
                    /* Unresolved local var: cvar_t * var@[???] */
  return false;
joined_r0x0011006d:
  if (pcVar1 == (cvar_t *)0x0) goto LAB_0011016e;
  iVar7 = Q_stricmp(local_20[0],pcVar1->name);
  if (iVar7 == 0) {
    fVar9 = Q_atof(pcVar1->string);
    if (fVar9 <= 0.0) goto LAB_0011016e;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char *[5] rgpchFilterPrefixes@[???] */
    if ((pcVar8->flags & 0x800) != 0) {
LAB_0011022e:
      Con_Printf("%s is a privileged variable\n",pcVar8->name);
      return true;
    }
    pcVar5 = Q_stristr(pcVar8->name,"cl_");
    pcVar3 = pcVar8->name;
    if (pcVar5 != pcVar3) {
      pcVar5 = Q_stristr(pcVar3,"gl_");
      pcVar3 = pcVar8->name;
      if (pcVar5 != pcVar3) {
        pcVar5 = Q_stristr(pcVar3,"m_");
        pcVar3 = pcVar8->name;
        if (pcVar5 != pcVar3) {
          pcVar5 = Q_stristr(pcVar3,"r_");
          pcVar3 = pcVar8->name;
          if (pcVar5 != pcVar3) {
            pcVar5 = Q_stristr(pcVar3,"hud_");
            pcVar3 = pcVar8->name;
            if (pcVar5 != pcVar3) goto LAB_0011016e;
          }
        }
      }
    }
    Con_Printf("%s is a privileged variable\n",pcVar3);
    return true;
  }
  pcVar1 = pcVar1->next;
  goto joined_r0x0011006d;
LAB_0011016e:
  iVar7 = Cmd_Argc();
  if (iVar7 == 1) {
LAB_0010ffbd:
    Con_Printf("\"%s\" is \"%s\"\n",pcVar8->name,pcVar8->string);
  }
  else if (((((pcVar8->flags & 0x40U) == 0) || (cls.state < ca_connecting)) ||
           (((pcVar8->flags & 4U) != 0 && (qVar6 = Host_IsServerActive(), qVar6 != false)))) ||
          (cl.maxclients < 2)) {
    pcVar5 = Cmd_Argv(1);
    pcVar3 = pcVar8->name;
    local_20[0] = pcVar3;
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg3(EBX)]
                       Unresolved local var: cvarhook_t * pHook@[???]
                       Unresolved local var: cvar_t * var@[???] */
    (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
    for (pcVar8 = cvar_vars; pcVar8 != (cvar_s *)0x0; pcVar8 = pcVar8->next) {
      iVar7 = Q_stricmp(local_20[0],pcVar8->name);
      if (iVar7 == 0) {
        Cvar_DirectSet(pcVar8,pcVar5);
        if (cvar_hooks == (cvarhook_t *)0x0) {
          return true;
        }
        pcVar1 = cvar_hooks->cvar;
        pcVar2 = cvar_hooks;
        while( true ) {
          if (pcVar1 == pcVar8) {
            (*pcVar2->hook)(pcVar8);
            return true;
          }
          pcVar2 = pcVar2->next;
          if (pcVar2 == (cvarhook_s *)0x0) break;
          pcVar1 = pcVar2->cvar;
        }
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


// Cvar_CompleteVariable  @ 0010f500
char * Cvar_CompleteVariable(char *search,int forward)

{
  char cVar1;
  char *pcVar2;
  char *s1;
  cvar_t *pcVar3;
  int count;
  int iVar4;
  cvar_s *pcVar5;
  cvar_t *pcVar6;
  char acStack_122 [257];
  undefined1 local_21;
  char *local_20 [4];
  
                    /* Unresolved local var: char[256] partial@[???]
                       Unresolved local var: cvar_t * cvar@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char * pPartial@[???] */
  pcVar2 = acStack_122 + 2;
  Q_strncpy(pcVar2,search,0xff);
  local_21 = 0;
  count = Q_strlen(pcVar2);
  if (count == 0) {
    return (char *)0x0;
  }
  cVar1 = acStack_122[count + 1];
  while (cVar1 == ' ') {
    acStack_122[count + 1] = '\0';
    cVar1 = acStack_122[count];
    count = count + -1;
  }
  iVar4 = Q_stricmp(pcVar2,Cvar_CompleteVariable::lastpartial);
  pcVar3 = cvar_vars;
  if (iVar4 == 0) {
                    /* Unresolved local var: cvar_t * var@[???] */
    local_20[0] = pcVar2;
    (*g_engdstAddrs.pfnGetCvarPointer)(local_20);
    pcVar5 = cvar_vars;
    if (cvar_vars == (cvar_t *)0x0) {
      return (char *)0x0;
    }
    do {
      iVar4 = Q_stricmp(local_20[0],pcVar5->name);
      pcVar3 = cvar_vars;
      if (iVar4 == 0) {
        if (forward == 1) {
          pcVar6 = pcVar5->next;
          goto LAB_0010f649;
        }
                    /* Unresolved local var: cvar_t * var@[???] */
        s1 = pcVar5->name;
        pcVar5 = cvar_vars->next;
        pcVar6 = cvar_vars;
        if (pcVar5 != (cvar_s *)0x0) goto LAB_0010f690;
        break;
      }
      pcVar5 = pcVar5->next;
    } while (pcVar5 != (cvar_s *)0x0);
  }
  goto LAB_0010f599;
LAB_0010f649:
  pcVar3 = cvar_vars;
  if (pcVar6 != (cvar_t *)0x0) goto LAB_0010f64d;
  goto LAB_0010f599;
  while( true ) {
    pcVar5 = pcVar6->next->next;
    pcVar6 = pcVar6->next;
    pcVar3 = cvar_vars;
    if (pcVar5 == (cvar_s *)0x0) break;
LAB_0010f690:
    iVar4 = Q_stricmp(s1,pcVar5->name);
    if (iVar4 == 0) goto LAB_0010f649;
  }
LAB_0010f599:
  while( true ) {
    pcVar6 = pcVar3;
    if (pcVar6 == (cvar_t *)0x0) {
      return (char *)0x0;
    }
    iVar4 = Q_strncmp(pcVar2,pcVar6->name,count);
    if (iVar4 == 0) break;
    pcVar3 = pcVar6->next;
  }
  iVar4 = Q_strlen(pcVar6->name);
  if (iVar4 != count) {
    pcVar2 = pcVar6->name;
    Q_strncpy(Cvar_CompleteVariable::lastpartial,pcVar2,0xff);
    Cvar_CompleteVariable::lastpartial[0xff] = '\0';
    return pcVar2;
  }
LAB_0010f64d:
  Q_strncpy(Cvar_CompleteVariable::lastpartial,pcVar6->name,0xff);
  Cvar_CompleteVariable::lastpartial[0xff] = '\0';
  return pcVar6->name;
}


// Cvar_CountServerVariables  @ 00110c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Cvar_CountServerVariables(void)

{
  int *piVar1;
  cvar_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: cvar_t * var@[???] */
  iVar3 = 0;
  pcVar2 = cvar_vars;
  while (pcVar2 != (cvar_t *)0x0) {
    piVar1 = &pcVar2->flags;
    pcVar2 = pcVar2->next;
    if ((*piVar1 & 4) != 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}


// Cvar_DirectSet  @ 0010f6d0
void Cvar_DirectSet(cvar_s *var,char *value)

{
  char cVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  qboolean qVar6;
  char *s;
  char *pcVar7;
  float fVar8;
  char local_41c [1036];
  
                    /* Unresolved local var: qboolean changed@[???]
                       Unresolved local var: char * pszValue@[???]
                       Unresolved local var: char[1024] szNew@[???] */
  if (value == (char *)0x0) {
    return;
  }
  if (var == (cvar_s *)0x0) {
    return;
  }
  uVar5 = var->flags;
  if ((uVar5 & 0x2000) != 0) {
    if ((((*value == '/') || (pcVar2 = Q_strstr(value,":"), pcVar2 != (char *)0x0)) ||
        (pcVar2 = Q_strstr(value,".."), pcVar2 != (char *)0x0)) ||
       (pcVar2 = Q_strstr(value,"\\"), pcVar2 != (char *)0x0)) {
      Con_Printf("Refusing to set %s to %s (invalid path)\n",var->name,value);
      return;
    }
    uVar5 = var->flags;
  }
  if ((uVar5 & 0x80) != 0) {
                    /* Unresolved local var: char * pS@[???]
                       Unresolved local var: char * pD@[???] */
    local_41c[0] = '\0';
    qVar6 = Q_UnicodeValidate(value);
    if (qVar6 == 0) {
      pcVar2 = local_41c;
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
      pcVar2 = local_41c;
      Q_strncpy_s(pcVar2,value,0x400);
    }
    value = local_41c;
    qVar6 = Q_UnicodeValidate(pcVar2);
    if (qVar6 == 0) {
      Q_UnicodeRepair(pcVar2);
    }
    iVar4 = Q_strlen(value);
    if (iVar4 == 0) {
      Q_strcpy(value,"empty");
    }
    uVar5 = var->flags;
  }
  pcVar2 = value;
  if ((uVar5 & 0x200) != 0) {
    pcVar2 = local_41c;
    if (value != pcVar2) {
      Q_strncpy_s(pcVar2,value,0x400);
    }
    Q_StripUnprintableAndSpace(pcVar2);
    uVar5 = var->flags;
  }
  pcVar7 = pcVar2;
  if ((uVar5 & 0x1000) != 0) {
                    /* Unresolved local var: char * k_pchFilterChars@[???] */
    pcVar7 = local_41c;
    if (pcVar2 != pcVar7) {
      Q_strncpy_s(pcVar7,pcVar2,0x400);
    }
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???] */
    sVar3 = strcspn(pcVar7,";\n");
    local_41c[sVar3] = '\0';
  }
  iVar4 = Q_strcmp(var->string,pcVar7);
  uVar5 = var->flags;
  if ((uVar5 & 2) != 0) {
    if (cls.state == ca_dedicated) {
      pcVar2 = var->name;
      s = Info_Serverinfo();
      Info_SetValueForKey(s,pcVar2,pcVar7,0x200);
      pcVar2 = Info_Serverinfo();
      SV_BroadcastCommand("fullserverinfo \"%s\"\n",pcVar2);
      if (cls.state != ca_dedicated) goto LAB_0010f839;
    }
    else {
LAB_0010f839:
      Info_SetValueForKey(cls.userinfo,var->name,pcVar7,0x100);
      if (iVar4 == 0) goto LAB_0010f8c8;
      if (ca_connecting < cls.state) {
        MSG_WriteByte(&cls.netchan.message,3);
        pcVar2 = va("setinfo \"%s\" \"%s\"\n",var->name,pcVar7);
        SZ_Print(&cls.netchan.message,pcVar2);
      }
    }
    uVar5 = var->flags;
  }
  if (((uVar5 & 4) != 0) && (iVar4 != 0)) {
                    /* Unresolved local var: char * szVal@[???] */
    if ((uVar5 & 0x100) == 0) {
      if ((uVar5 & 0x20) == 0) {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,pcVar7);
        pcVar2 = pcVar7;
      }
      else {
        Log_Printf("Server cvar \"%s\" = \"%s\"\n",var->name,"***PROTECTED***");
        pcVar2 = "***PROTECTED***";
      }
      SV_BroadcastPrintf("\"%s\" changed to \"%s\"\n",var->name,pcVar2);
      uVar5 = var->flags;
    }
    pcVar2 = pcVar7;
    if ((uVar5 & 0x20) != 0) {
      pcVar2 = "0";
      iVar4 = Q_strlen(pcVar7);
      if ((0 < iVar4) && (iVar4 = Q_stricmp(pcVar7,"none"), iVar4 != 0)) {
        pcVar2 = "1";
      }
    }
    Steam_SetCVar(var->name,pcVar2);
  }
LAB_0010f8c8:
  Z_Free(var->string);
  iVar4 = Q_strlen(pcVar7);
  pcVar2 = Z_Malloc(iVar4 + 1);
  var->string = pcVar2;
  Q_strcpy(pcVar2,pcVar7);
  fVar8 = Q_atof(var->string);
  var->value = fVar8;
  return;
}


// Cvar_FindPrevVar  @ 0010f340
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


// Cvar_FindVar  @ 0010f2f0
cvar_t * Cvar_FindVar(char *var_name)

{
  cvar_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: cvar_t * var@[???] */
  (*g_engdstAddrs.pfnGetCvarPointer)(&var_name);
  pcVar1 = cvar_vars;
  while ((pcVar1 != (cvar_t *)0x0 && (iVar2 = Q_stricmp(var_name,pcVar1->name), iVar2 != 0))) {
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// Cvar_HookVariable  @ 00110c80
qboolean Cvar_HookVariable(char *var_name,cvarhook_t *pHook)

{
  cvar_s *pcVar1;
  cvarhook_s *pcVar2;
  int iVar3;
  cvarhook_t *pcVar4;
  char *local_10 [2];
  
                    /* Unresolved local var: cvar_t * cvar@[DW_OP_reg6(ESI)] */
  if ((((pHook != (cvarhook_t *)0x0) && (pHook->hook != (pfnCvar_HookVariable_t)0x0)) &&
      (pHook->cvar == (cvar_t *)0x0)) && (pHook->next == (cvarhook_s *)0x0)) {
                    /* Unresolved local var: cvar_t * var@[???] */
    local_10[0] = var_name;
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


// Cvar_Init  @ 0010f2d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_Init(void)

{
  return;
}


// Cvar_IsMultipleTokens  @ 0010fe70
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
  pcVar2 = (char *)0x0;
  if (iVar3 != 1) {
    pcVar2 = Cvar_IsMultipleTokens::firstToken;
  }
  return pcVar2;
}


// Cvar_RegisterVariable  @ 0010fcb0
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
  cvar_t local_24;
  char *local_10;
  
                    /* Unresolved local var: char * oldstr@[???]
                       Unresolved local var: cvar_t * dummy@[???]
                       Unresolved local var: cvar_t * v@[???]
                       Unresolved local var: cvar_t * n@[DW_OP_reg3(EBX)]
                       Unresolved local var: cvar_t dummyvar@[???] */
  local_10 = variable->name;
                    /* Unresolved local var: cvar_t * var@[???] */
  (*g_engdstAddrs.pfnGetCvarPointer)(&local_10);
  for (pcVar1 = cvar_vars; pcVar1 != (cvar_t *)0x0; pcVar1 = pcVar1->next) {
    iVar4 = Q_stricmp(local_10,pcVar1->name);
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
    local_24.name = " ";
    local_24.next = cvar_vars;
    variable->value = fVar7;
    pcVar6 = &local_24;
    while (pcVar5 = pcVar2, pcVar5 != (cvar_t *)0x0) {
      iVar4 = strcasecmp(pcVar5->name,variable->name);
      if (0 < iVar4) {
        pcVar6->next = variable;
        variable->next = pcVar5;
        cvar_vars = local_24.next;
        return;
      }
      pcVar6 = pcVar5;
      pcVar2 = pcVar5->next;
    }
    pcVar6->next = variable;
    cvar_vars = local_24.next;
    variable->next = (cvar_s *)0x0;
  }
  else {
    Con_Printf("Cvar_RegisterVariable: %s is a command\n",variable->name);
  }
  return;
}


// Cvar_RemoveHudCvars  @ 0010fdf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_RemoveHudCvars(void)

{
  cvar_s *pcVar1;
  cvar_t *pcVar2;
  cvar_s *pcVar3;
  
                    /* Unresolved local var: cvar_t * pNewList@[???]
                       Unresolved local var: cvar_t * pCvar@[???]
                       Unresolved local var: cvar_t * pNext@[???] */
  pcVar3 = (cvar_t *)0x0;
  pcVar2 = cvar_vars;
  if (cvar_vars != (cvar_t *)0x0) {
    do {
      pcVar1 = pcVar2->next;
      if ((pcVar2->flags & 0x10) == 0) {
        pcVar2->next = pcVar3;
        pcVar3 = pcVar2;
      }
      else {
        Z_Free(pcVar2->string);
        Z_Free(pcVar2);
      }
      pcVar2 = pcVar1;
    } while (pcVar1 != (cvar_s *)0x0);
    cvar_vars = (cvar_t *)0x0;
    if (pcVar3 != (cvar_t *)0x0) {
      pcVar2 = (cvar_t *)0x0;
      do {
        cvar_vars = pcVar3;
        pcVar3 = cvar_vars->next;
        cvar_vars->next = pcVar2;
        pcVar2 = cvar_vars;
      } while (pcVar3 != (cvar_s *)0x0);
    }
  }
  return;
}


// Cvar_Set  @ 0010fad0
void Cvar_Set(char *var_name,char *value)

{
  cvar_s *pcVar1;
  cvar_s *var;
  cvarhook_s *pcVar2;
  int iVar3;
  char *local_10 [2];
  
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg3(EBX)]
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
    iVar3 = Q_stricmp(local_10[0],var->name);
    if (iVar3 == 0) break;
    var = var->next;
  }
  Cvar_DirectSet(var,value);
  if (cvar_hooks == (cvarhook_t *)0x0) {
    return;
  }
  pcVar1 = cvar_hooks->cvar;
  pcVar2 = cvar_hooks;
  while( true ) {
    if (var == pcVar1) {
      (*pcVar2->hook)(var);
      return;
    }
    pcVar2 = pcVar2->next;
    if (pcVar2 == (cvarhook_s *)0x0) break;
    pcVar1 = pcVar2->cvar;
  }
  return;
}


// Cvar_SetValue  @ 0010fb80
void Cvar_SetValue(char *var_name,float value)

{
  cvar_s *var;
  cvarhook_s *pcVar1;
  char *pcVar2;
  int iVar3;
  char local_30 [32];
  char *local_10;
  
                    /* Unresolved local var: char[32] val@[???] */
  (*g_engdstAddrs.Cvar_SetValue)(&var_name,&value);
  if (ABS(value - (float)(int)value) < 1e-06) {
    snprintf(local_30,0x20,"%d",(int)value);
  }
  else {
    snprintf(local_30,0x20,"%f",(double)value);
  }
  pcVar2 = var_name;
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg3(EBX)]
                       Unresolved local var: cvarhook_t * pHook@[???]
                       Unresolved local var: cvar_t * var@[???] */
  local_10 = var_name;
  (*g_engdstAddrs.pfnGetCvarPointer)(&local_10);
  var = cvar_vars;
  while( true ) {
    if (var == (cvar_s *)0x0) {
      Con_DPrintf("Cvar_Set: variable %s not found\n",pcVar2);
      return;
    }
    iVar3 = Q_stricmp(local_10,var->name);
    if (iVar3 == 0) break;
    var = var->next;
  }
  Cvar_DirectSet(var,local_30);
  pcVar1 = cvar_hooks;
  while( true ) {
    if (pcVar1 == (cvarhook_t *)0x0) {
      return;
    }
    if (var == pcVar1->cvar) break;
    pcVar1 = pcVar1->next;
  }
  (*pcVar1->hook)(var);
  return;
}


// Cvar_Shutdown  @ 0010f2e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_Shutdown(void)

{
  cvar_vars = (cvar_t *)0x0;
  return;
}


// Cvar_UnlinkExternals  @ 00110c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cvar_UnlinkExternals(void)

{
  cvar_s *pcVar1;
  cvar_s *pcVar2;
  cvar_t **ppcVar3;
  
                    /* Unresolved local var: cvar_t * pVar@[???]
                       Unresolved local var: cvar_t * * pList@[???] */
  if (cvar_vars != (cvar_t *)0x0) {
    ppcVar3 = &cvar_vars;
    pcVar2 = cvar_vars;
    do {
      while ((pcVar2->flags & 8) == 0) {
        ppcVar3 = &pcVar2->next;
        pcVar2 = pcVar2->next;
        if (pcVar2 == (cvar_s *)0x0) {
          return;
        }
      }
      pcVar1 = pcVar2->next;
      *ppcVar3 = pcVar1;
      pcVar2 = pcVar2->next;
    } while (pcVar1 != (cvar_s *)0x0);
  }
  return;
}


// Cvar_VariableInt  @ 0010f430
int Cvar_VariableInt(char *var_name)

{
  int iVar1;
  cvar_s *pcVar2;
  char *local_10 [3];
  
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: cvar_t * var@[???] */
  local_10[0] = var_name;
  (*g_engdstAddrs.pfnGetCvarPointer)(local_10);
  iVar1 = 0;
  pcVar2 = cvar_vars;
  if (cvar_vars != (cvar_t *)0x0) {
    while (iVar1 = Q_stricmp(local_10[0],pcVar2->name), iVar1 != 0) {
      pcVar2 = pcVar2->next;
      if (pcVar2 == (cvar_s *)0x0) {
        return 0;
      }
    }
    iVar1 = Q_atoi(pcVar2->string);
  }
  return iVar1;
}


// Cvar_VariableString  @ 0010f4a0
char * Cvar_VariableString(char *var_name)

{
  cvar_s *pcVar1;
  int iVar2;
  char *local_10 [3];
  
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg3(EBX)] */
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


// Cvar_VariableValue  @ 0010f3a0
float Cvar_VariableValue(char *var_name)

{
  cvar_s **ppcVar1;
  int iVar2;
  cvar_s *pcVar3;
  float fVar4;
  char *local_10 [3];
  
                    /* Unresolved local var: cvar_t * var@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: cvar_t * var@[???] */
  local_10[0] = var_name;
  (*g_engdstAddrs.pfnGetCvarPointer)(local_10);
  fVar4 = 0.0;
  pcVar3 = cvar_vars;
  if (cvar_vars != (cvar_t *)0x0) {
    while (iVar2 = Q_stricmp(local_10[0],pcVar3->name), iVar2 != 0) {
      ppcVar1 = &pcVar3->next;
      pcVar3 = *ppcVar1;
      if (*ppcVar1 == (cvar_s *)0x0) {
        return 0.0;
      }
    }
    fVar4 = Q_atof(pcVar3->string);
  }
  return fVar4;
}


// Cvar_WriteVariables  @ 00110510
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


