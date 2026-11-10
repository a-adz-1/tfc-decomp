// Info_FindLargestKey  @ 0005d888
undefined1 * Info_FindLargestKey(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int local_208;
  char local_204 [256];
  char local_104 [256];
  
  local_208 = 0;
  largest_key_34 = 0;
  cVar1 = *param_1;
  if (cVar1 != '\\') goto LAB_0005d971;
  param_1 = param_1 + 1;
  while( true ) {
    cVar1 = *param_1;
LAB_0005d971:
    if (cVar1 == '\0') break;
    pcVar5 = local_104;
    while ((cVar1 != '\0' && (cVar1 != '\\'))) {
      *pcVar5 = cVar1;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
      cVar1 = *param_1;
    }
    *pcVar5 = '\0';
    iVar2 = Q_strlen(local_104);
    if (*param_1 == '\0') break;
    pcVar5 = local_204;
    pcVar6 = param_1;
    while( true ) {
      param_1 = pcVar6 + 1;
      cVar1 = *param_1;
      if ((cVar1 == '\0') || (cVar1 == '\\')) break;
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
      pcVar6 = param_1;
    }
    *pcVar5 = '\0';
    if (*param_1 != '\0') {
      param_1 = pcVar6 + 2;
    }
    iVar3 = Q_strlen(local_204);
    if ((local_208 < iVar2 + iVar3) && (iVar4 = Info_IsKeyImportant(local_104), iVar4 == 0)) {
      Q_strcpy(&largest_key_34,local_104);
      local_208 = iVar2 + iVar3;
    }
  }
  return &largest_key_34;
}


// Info_IsKeyImportant  @ 0005d79c
undefined4 Info_IsKeyImportant(char *param_1)

{
  int iVar1;
  
  if ((((((*param_1 != '*') && (iVar1 = Q_strcmp(param_1,&DAT_000a825d), iVar1 != 0)) &&
        (iVar1 = Q_strcmp(param_1,"model"), iVar1 != 0)) &&
       ((iVar1 = Q_strcmp(param_1,&DAT_000a8268), iVar1 != 0 &&
        (iVar1 = Q_strcmp(param_1,"topcolor"), iVar1 != 0)))) &&
      ((iVar1 = Q_strcmp(param_1,"bottomcolor"), iVar1 != 0 &&
       ((iVar1 = Q_strcmp(param_1,"cl_updaterate"), iVar1 != 0 &&
        (iVar1 = Q_strcmp(param_1,"cl_lw"), iVar1 != 0)))))) &&
     ((iVar1 = Q_strcmp(param_1,"cl_lc"), iVar1 != 0 &&
      (iVar1 = Q_strcmp(param_1,"tracker"), iVar1 != 0)))) {
    return 0;
  }
  return 1;
}


// Info_Print  @ 0005dbe8
void Info_Print(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char local_404 [512];
  char local_204 [20];
  undefined1 local_1f0;
  
  cVar1 = *param_1;
  if (cVar1 != '\\') goto LAB_0005dcb1;
  param_1 = param_1 + 1;
  while( true ) {
    cVar1 = *param_1;
LAB_0005dcb1:
    if (cVar1 == '\0') {
      return;
    }
    pcVar2 = local_204;
    while ((cVar1 != '\0' && (cVar1 != '\\'))) {
      *pcVar2 = cVar1;
      param_1 = param_1 + 1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *param_1;
    }
    iVar3 = (int)pcVar2 - (int)local_204;
    if (iVar3 < 0x14) {
      Q_memset(pcVar2,0x20,0x14 - iVar3);
      local_1f0 = 0;
    }
    else {
      *pcVar2 = '\0';
    }
    Con_Printf(&DAT_000a83a5,local_204);
    if (*param_1 == '\0') break;
    pcVar2 = local_404;
    pcVar4 = param_1;
    while( true ) {
      param_1 = pcVar4 + 1;
      cVar1 = *param_1;
      if ((cVar1 == '\0') || (cVar1 == '\\')) break;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
      pcVar4 = param_1;
    }
    *pcVar2 = '\0';
    if (*param_1 != '\0') {
      param_1 = pcVar4 + 2;
    }
    Con_Printf(&DAT_000a83b7,local_404);
  }
  Con_Printf("MISSING VALUE\n");
  return;
}


// Info_RemoveKey  @ 0005d618
void Info_RemoveKey(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_404 [512];
  char local_204 [512];
  
  iVar2 = Q_strstr(param_2,&DAT_000a8241);
  if (iVar2 == 0) {
    cVar1 = *param_1;
    do {
      pcVar3 = local_204;
      pcVar4 = param_1;
      if (cVar1 == '\\') {
        pcVar4 = param_1 + 1;
        cVar1 = *pcVar4;
      }
      while (cVar1 != '\\') {
        if (cVar1 == '\0') {
          return;
        }
        *pcVar3 = cVar1;
        cVar1 = pcVar4[1];
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      }
      *pcVar3 = '\0';
      pcVar3 = local_404;
      while( true ) {
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
      }
      *pcVar3 = '\0';
      iVar2 = Q_strcmp(param_2,local_204);
      if (iVar2 == 0) {
        Q_strcpy(param_1,pcVar4);
        return;
      }
      cVar1 = *pcVar4;
      param_1 = pcVar4;
    } while (cVar1 != '\0');
  }
  else {
    Con_Printf("Can\'t use a key with a \\\n");
  }
  return;
}


// Info_RemovePrefixedKeys  @ 0005d6d8
void Info_RemovePrefixedKeys(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char local_404 [512];
  char local_204 [512];
  
  cVar1 = *param_1;
  pcVar3 = param_1;
  do {
    pcVar2 = local_204;
    if (cVar1 == '\\') {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
    while (cVar1 != '\\') {
      if (cVar1 == '\0') {
        return;
      }
      *pcVar2 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar3;
    }
    *pcVar2 = '\0';
    pcVar2 = local_404;
    while( true ) {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
      if ((cVar1 == '\\') || (cVar1 == '\0')) break;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    }
    *pcVar2 = '\0';
    if (local_204[0] == param_2) {
      Info_RemoveKey(param_1,local_204);
      pcVar3 = param_1;
    }
    cVar1 = *pcVar3;
  } while (cVar1 != '\0');
  return;
}


// Info_Serverinfo  @ 00048fd8
undefined1 * Info_Serverinfo(void)

{
  return serverinfo;
}


// Info_SetValueForKey  @ 0005dba4
void Info_SetValueForKey(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  if (*param_2 == '*') {
    Con_Printf("Can\'t set * keys\n");
  }
  else {
    Info_SetValueForStarKey(param_1,param_2,param_3,param_4);
  }
  return;
}


// Info_SetValueForStarKey  @ 0005d98c
void Info_SetValueForStarKey(undefined1 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint __c;
  byte *__s;
  byte local_404 [1024];
  
  iVar1 = Q_strstr(param_2,&DAT_000a8241);
  if ((iVar1 == 0) && (iVar1 = Q_strstr(param_3,&DAT_000a8241), iVar1 == 0)) {
    iVar1 = Q_strstr(param_2,&DAT_000a82e3);
    if ((iVar1 == 0) && (iVar1 = Q_strstr(param_3,&DAT_000a82e3), iVar1 == 0)) {
      iVar1 = Q_strlen(param_2);
      if ((0x7f < iVar1) || (iVar1 = Q_strlen(param_3), 0x7f < iVar1)) {
        Con_Printf("Keys and values must be < %i characters.\n",0x80);
        return;
      }
      Info_RemoveKey(param_1,param_2);
      if (param_3 == 0) {
        return;
      }
      iVar1 = Q_strlen(param_3);
      if (iVar1 == 0) {
        return;
      }
      __s = local_404;
      sprintf((char *)__s,"\\%s\\%s",param_2,param_3);
      iVar1 = Q_strlen(__s);
      iVar2 = Q_strlen(param_1);
      if (iVar2 + iVar1 < param_4) {
LAB_0005db14:
        iVar1 = Q_strlen(param_1);
        param_1 = (undefined1 *)((int)param_1 + iVar1);
        do {
          if (local_404[0] == 0) {
            *param_1 = 0;
            return;
          }
          __c = (uint)*__s;
          __s = __s + 1;
          iVar1 = Q_stricmp(param_2,&DAT_000a825d);
          if (iVar1 == 0) {
LAB_0005db7c:
            if (0xd < (int)__c) {
              *param_1 = (char)__c;
              param_1 = param_1 + 1;
            }
          }
          else {
            __c = __c & 0x7f;
            if (__c - 0x20 < 0x60) {
              iVar1 = Q_stricmp(param_2,&DAT_000a838e);
              if (iVar1 == 0) {
                __c = tolower(__c);
              }
              goto LAB_0005db7c;
            }
          }
          local_404[0] = *__s;
        } while( true );
      }
      iVar1 = Info_IsKeyImportant(param_2);
      if (iVar1 != 0) {
        do {
          pcVar3 = (char *)Info_FindLargestKey(param_1,param_4);
          Info_RemoveKey(param_1,pcVar3);
          iVar1 = Q_strlen(__s);
          iVar2 = Q_strlen(param_1);
          if (iVar2 + iVar1 < param_4) {
            if (*pcVar3 != '\0') goto LAB_0005db14;
            break;
          }
        } while (*pcVar3 != '\0');
      }
      pcVar3 = "Info string length exceeded\n";
    }
    else {
      pcVar3 = "Can\'t use keys or values with a \"\n";
    }
  }
  else {
    pcVar3 = "Can\'t use keys or values with a \\\n";
  }
  Con_Printf(pcVar3);
  return;
}


// Info_ValueForKey  @ 0005d550
undefined * Info_ValueForKey(char *param_1,undefined4 param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char local_204 [512];
  
  uVar1 = valueindex_25 + 1;
  uVar3 = uVar1;
  if ((int)uVar1 < 0) {
    uVar3 = valueindex_25 + 4;
  }
  valueindex_25 = uVar1 - (uVar3 & 0xfffffffc);
  cVar2 = *param_1;
  if (cVar2 == '\\') {
    param_1 = param_1 + 1;
    cVar2 = *param_1;
  }
  pcVar5 = local_204;
  while( true ) {
    while (cVar2 != '\\') {
      if (cVar2 == '\0') goto LAB_0005d604;
      *pcVar5 = cVar2;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
      cVar2 = *param_1;
    }
    *pcVar5 = '\0';
    pcVar5 = value_24 + valueindex_25 * 0x200;
    while( true ) {
      pcVar6 = param_1 + 1;
      cVar2 = *pcVar6;
      if ((cVar2 == '\\') || (cVar2 == '\0')) break;
      *pcVar5 = cVar2;
      pcVar5 = pcVar5 + 1;
      param_1 = pcVar6;
    }
    *pcVar5 = '\0';
    iVar4 = Q_strcmp(param_2,local_204);
    if (iVar4 == 0) {
      return value_24 + valueindex_25 * 0x200;
    }
    if (*pcVar6 == '\0') break;
    param_1 = param_1 + 2;
    cVar2 = *param_1;
    pcVar5 = local_204;
  }
LAB_0005d604:
  return &DAT_000a8240;
}


// Info_WriteVars  @ 00055240
void Info_WriteVars(FILE *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char local_204 [512];
  
  pcVar6 = &DAT_00385294;
  uVar4 = valueindex_10 + 1;
  uVar2 = uVar4;
  if ((int)uVar4 < 0) {
    uVar2 = valueindex_10 + 4;
  }
  valueindex_10 = uVar4 - (uVar2 & 0xfffffffc);
  if (DAT_00385294 == '\\') {
    pcVar6 = &DAT_00385295;
  }
  pcVar5 = local_204;
  while( true ) {
    for (; cVar1 = *pcVar6, cVar1 != '\\'; pcVar6 = pcVar6 + 1) {
      if (cVar1 == '\0') {
        return;
      }
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
    }
    *pcVar5 = '\0';
    pcVar5 = value_9 + valueindex_10 * 0x200;
    while( true ) {
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar7;
      if ((cVar1 == '\\') || (cVar1 == '\0')) break;
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar7;
    }
    *pcVar5 = '\0';
    iVar3 = Cvar_FindVar(local_204);
    if ((iVar3 == 0) && (local_204[0] != '*')) {
      fprintf(param_1,"setinfo \"%s\" \"%s\"\n",local_204,value_9 + valueindex_10 * 0x200);
    }
    if (*pcVar7 == '\0') break;
    pcVar6 = pcVar6 + 2;
    pcVar5 = local_204;
  }
  return;
}


