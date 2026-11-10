// Info_FindLargestKey  @ 000769a8
undefined1 * Info_FindLargestKey(char *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_210;
  char *local_208;
  char local_204 [256];
  char local_104 [256];
  
  local_210 = 0;
  largest_key_17 = 0;
  if (*param_1 == '\\') {
    param_1 = param_1 + 1;
  }
  while (*param_1 != '\0') {
    local_208 = local_104;
    for (; (*param_1 != '\0' && (*param_1 != '\\')); param_1 = param_1 + 1) {
      *local_208 = *param_1;
      local_208 = local_208 + 1;
    }
    *local_208 = '\0';
    iVar2 = Q_strlen(local_104);
    if (*param_1 == '\0') break;
    local_208 = local_204;
    pcVar1 = param_1;
    while ((param_1 = pcVar1 + 1, *param_1 != '\0' && (*param_1 != '\\'))) {
      *local_208 = *param_1;
      local_208 = local_208 + 1;
      pcVar1 = param_1;
    }
    *local_208 = '\0';
    if (*param_1 != '\0') {
      param_1 = pcVar1 + 2;
    }
    iVar3 = Q_strlen(local_204);
    if ((local_210 < iVar2 + iVar3) && (iVar4 = Info_IsKeyImportant(local_104), iVar4 == 0)) {
      Q_strncpy(&largest_key_17,local_104,0xff);
      DAT_0011675f = 0;
      local_210 = iVar2 + iVar3;
    }
  }
  return &largest_key_17;
}


// Info_IsKeyImportant  @ 000767e4
undefined4 Info_IsKeyImportant(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_1 == '*') {
    uVar1 = 1;
  }
  else {
    iVar2 = Q_strcmp(param_1,&DAT_000e47bd);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      iVar2 = Q_strcmp(param_1,"model");
      if (iVar2 == 0) {
        uVar1 = 1;
      }
      else {
        iVar2 = Q_strcmp(param_1,&DAT_000e47c8);
        if (iVar2 == 0) {
          uVar1 = 1;
        }
        else {
          iVar2 = Q_strcmp(param_1,"topcolor");
          if (iVar2 == 0) {
            uVar1 = 1;
          }
          else {
            iVar2 = Q_strcmp(param_1,"bottomcolor");
            if (iVar2 == 0) {
              uVar1 = 1;
            }
            else {
              iVar2 = Q_strcmp(param_1,"cl_updaterate");
              if (iVar2 == 0) {
                uVar1 = 1;
              }
              else {
                iVar2 = Q_strcmp(param_1,"cl_lw");
                if (iVar2 == 0) {
                  uVar1 = 1;
                }
                else {
                  iVar2 = Q_strcmp(param_1,"cl_lc");
                  if (iVar2 == 0) {
                    uVar1 = 1;
                  }
                  else {
                    iVar2 = Q_strcmp(param_1,"*tracker");
                    if (iVar2 == 0) {
                      uVar1 = 1;
                    }
                    else {
                      iVar2 = Q_strcmp(param_1,"*hltv");
                      if (iVar2 == 0) {
                        uVar1 = 1;
                      }
                      else {
                        uVar1 = 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar1;
}


// Info_Print  @ 00076f44
void Info_Print(char *param_1)

{
  char *pcVar1;
  char *local_408;
  char local_404 [512];
  char local_204 [20];
  undefined1 local_1f0;
  
  if (*param_1 == '\\') {
    param_1 = param_1 + 1;
  }
  while( true ) {
    if (*param_1 == '\0') {
      return;
    }
    local_408 = local_204;
    for (; (*param_1 != '\0' && (*param_1 != '\\')); param_1 = param_1 + 1) {
      *local_408 = *param_1;
      local_408 = local_408 + 1;
    }
    if ((int)local_408 - (int)local_204 < 0x14) {
      Q_memset(local_408,0x20,0x14 - ((int)local_408 - (int)local_204));
      local_1f0 = 0;
    }
    else {
      *local_408 = '\0';
    }
    pcVar1 = local_204;
    Con_Printf(&DAT_000e4905,pcVar1);
    if (*param_1 == '\0') break;
    local_408 = local_404;
    pcVar1 = param_1;
    while ((param_1 = pcVar1 + 1, *param_1 != '\0' && (*param_1 != '\\'))) {
      *local_408 = *param_1;
      local_408 = local_408 + 1;
      pcVar1 = param_1;
    }
    *local_408 = '\0';
    if (*param_1 != '\0') {
      param_1 = pcVar1 + 2;
    }
    Con_Printf(&DAT_000e4917,local_404);
  }
  Con_Printf("MISSING VALUE\n",pcVar1);
  return;
}


// Info_RemoveKey  @ 00076568
void Info_RemoveKey(char *param_1,undefined4 param_2)

{
  int iVar1;
  char *local_40c;
  char local_408 [512];
  char local_208 [512];
  char *local_8;
  
  iVar1 = Q_strstr(param_2,&DAT_000e47a1);
  if (iVar1 == 0) {
    do {
      local_8 = param_1;
      if (*param_1 == '\\') {
        param_1 = param_1 + 1;
      }
      local_40c = local_208;
      for (; *param_1 != '\\'; param_1 = param_1 + 1) {
        if (*param_1 == '\0') {
          return;
        }
        *local_40c = *param_1;
        local_40c = local_40c + 1;
      }
      *local_40c = '\0';
      local_40c = local_408;
      while ((param_1 = param_1 + 1, *param_1 != '\\' && (*param_1 != '\0'))) {
        if (*param_1 == '\0') {
          return;
        }
        *local_40c = *param_1;
        local_40c = local_40c + 1;
      }
      *local_40c = '\0';
      iVar1 = Q_strcmp(param_2,local_208);
      if (iVar1 == 0) {
        Q_strcpy(local_8,param_1);
        return;
      }
    } while (*param_1 != '\0');
  }
  else {
    Con_Printf("Can\'t use a key with a \\\n");
  }
  return;
}


// Info_RemovePrefixedKeys  @ 000766c8
void Info_RemovePrefixedKeys(char *param_1,char param_2)

{
  char *local_410;
  char local_40c [512];
  char local_20c [512];
  char *local_c;
  char local_5;
  
  local_5 = param_2;
  local_c = param_1;
  do {
    if (*local_c == '\\') {
      local_c = local_c + 1;
    }
    local_410 = local_20c;
    for (; *local_c != '\\'; local_c = local_c + 1) {
      if (*local_c == '\0') {
        return;
      }
      *local_410 = *local_c;
      local_410 = local_410 + 1;
    }
    *local_410 = '\0';
    local_410 = local_40c;
    while ((local_c = local_c + 1, *local_c != '\\' && (*local_c != '\0'))) {
      if (*local_c == '\0') {
        return;
      }
      *local_410 = *local_c;
      local_410 = local_410 + 1;
    }
    *local_410 = '\0';
    if (local_20c[0] == local_5) {
      Info_RemoveKey(param_1,local_20c);
      local_c = param_1;
    }
  } while (*local_c != '\0');
  return;
}


// Info_Serverinfo  @ 00056600
undefined1 * Info_Serverinfo(void)

{
  return serverinfo;
}


// Info_SetValueForKey  @ 00076ef0
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


// Info_SetValueForStarKey  @ 00076b64
void Info_SetValueForStarKey(byte *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint __c;
  byte local_40c;
  byte *local_408;
  byte local_404 [1024];
  
  iVar1 = Q_strstr(param_2,&DAT_000e47a1);
  if ((iVar1 == 0) && (iVar1 = Q_strstr(param_3,&DAT_000e47a1), iVar1 == 0)) {
    iVar1 = Q_strstr(param_2,&DAT_000e4843);
    if ((iVar1 == 0) && (iVar1 = Q_strstr(param_3,&DAT_000e4843), iVar1 == 0)) {
      iVar1 = Q_strstr(param_2,&DAT_000e4846);
      if ((iVar1 == 0) && (iVar1 = Q_strstr(param_3,&DAT_000e4846), iVar1 == 0)) {
        iVar1 = Q_strlen(param_2);
        if ((iVar1 < 0x80) && (iVar1 = Q_strlen(param_3), iVar1 < 0x80)) {
          Info_RemoveKey(param_1,param_2);
          if ((param_3 != 0) && (iVar1 = Q_strlen(param_3), iVar1 != 0)) {
            snprintf((char *)local_404,0x400,"\\%s\\%s",param_2,param_3);
            iVar1 = Q_strlen(local_404);
            iVar2 = Q_strlen(param_1);
            if (param_4 <= iVar2 + iVar1) {
              iVar1 = Info_IsKeyImportant(param_2);
              if (iVar1 == 0) {
                Con_Printf("Info string length exceeded\n");
                return;
              }
              do {
                pcVar3 = (char *)Info_FindLargestKey(param_1,param_4);
                Info_RemoveKey(param_1,pcVar3);
                iVar1 = Q_strlen(local_404);
                iVar2 = Q_strlen(param_1);
                if (iVar2 + iVar1 < param_4) break;
              } while (*pcVar3 != '\0');
              if (*pcVar3 == '\0') {
                Con_Printf("Info string length exceeded\n");
                return;
              }
            }
            iVar1 = Q_strlen(param_1);
            param_1 = (byte *)((int)param_1 + iVar1);
            local_408 = local_404;
            while (*local_408 != 0) {
              local_40c = *local_408;
              __c = (uint)local_40c;
              local_408 = local_408 + 1;
              if ((0x1f < __c) && (__c < 0x7f)) {
                iVar1 = Q_stricmp(param_2,&DAT_000e48ee);
                if (iVar1 == 0) {
                  iVar1 = tolower(__c);
                  local_40c = (byte)iVar1;
                }
                *param_1 = local_40c;
                param_1 = param_1 + 1;
              }
            }
            *param_1 = 0;
          }
        }
        else {
          Con_Printf("Keys and values must be < %i characters.\n",0x80);
        }
      }
      else {
        Con_Printf("Can\'t use keys or values with a \"\n");
      }
    }
  }
  else {
    Con_Printf("Can\'t use keys or values with a \\\n");
  }
  return;
}


// Info_ValueForKey  @ 000763e4
undefined * Info_ValueForKey(char *param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *local_208;
  char local_204 [512];
  
  iVar2 = valueindex_4 + 1;
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = valueindex_4 + 4;
  }
  valueindex_4 = iVar2 + (iVar3 >> 2) * -4;
  if (*param_1 == '\\') {
    param_1 = param_1 + 1;
  }
  while( true ) {
    local_208 = local_204;
    for (; *param_1 != '\\'; param_1 = param_1 + 1) {
      if (*param_1 == '\0') {
        return &DAT_000e47a0;
      }
      *local_208 = *param_1;
      local_208 = local_208 + 1;
    }
    *local_208 = '\0';
    local_208 = value_3 + valueindex_4 * 0x200;
    pcVar1 = param_1;
    while ((param_1 = pcVar1 + 1, *param_1 != '\\' && (*param_1 != '\0'))) {
      if (*param_1 == '\0') {
        return &DAT_000e47a0;
      }
      *local_208 = *param_1;
      local_208 = local_208 + 1;
      pcVar1 = param_1;
    }
    *local_208 = '\0';
    iVar3 = Q_strcmp(param_2,local_204);
    if (iVar3 == 0) break;
    if (*param_1 == '\0') {
      return &DAT_000e47a0;
    }
    param_1 = pcVar1 + 2;
  }
  return value_3 + valueindex_4 * 0x200;
}


// Info_WriteVars  @ 0006a39c
void Info_WriteVars(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *local_210;
  char local_20c [512];
  char *local_c;
  int local_8;
  
  local_c = &DAT_002fdcf4;
  iVar1 = valueindex_41 + 1;
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = valueindex_41 + 4;
  }
  valueindex_41 = iVar1 + (iVar2 >> 2) * -4;
  if (DAT_002fdcf4 == '\\') {
    local_c = &DAT_002fdcf5;
  }
  while( true ) {
    local_210 = local_20c;
    for (; *local_c != '\\'; local_c = local_c + 1) {
      if (*local_c == '\0') {
        return;
      }
      *local_210 = *local_c;
      local_210 = local_210 + 1;
    }
    *local_210 = '\0';
    local_210 = value_40 + valueindex_41 * 0x200;
    while ((local_c = local_c + 1, *local_c != '\\' && (*local_c != '\0'))) {
      if (*local_c == '\0') {
        return;
      }
      *local_210 = *local_c;
      local_210 = local_210 + 1;
    }
    *local_210 = '\0';
    local_8 = Cvar_FindVar(local_20c);
    if ((local_8 == 0) && (local_20c[0] != '*')) {
      FS_FPrintf(param_1,"setinfo \"%s\" \"%s\"\n",local_20c,value_40 + valueindex_41 * 0x200);
    }
    if (*local_c == '\0') break;
    local_c = local_c + 1;
  }
  return;
}


