// Info_Print  @ 08052fa0
void Info_Print(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char local_404 [512];
  char local_204 [20];
  undefined1 local_1f0;
  
  if (*param_1 == '\\') {
    param_1 = param_1 + 1;
  }
  if (*param_1 != '\0') {
    do {
      pcVar3 = local_204;
      cVar1 = *param_1;
      while ((cVar1 != '\0' && (*param_1 != '\\'))) {
        *pcVar3 = *param_1;
        param_1 = param_1 + 1;
        pcVar3 = pcVar3 + 1;
        cVar1 = *param_1;
      }
      iVar2 = (int)pcVar3 - (int)local_204;
      if (iVar2 < 0x14) {
        memset(pcVar3,0x20,0x14 - iVar2);
        local_1f0 = 0;
      }
      else {
        *pcVar3 = '\0';
      }
      Con_Printf(&DAT_0809ebf5,local_204);
      if (*param_1 == '\0') {
        Con_Printf("MISSING VALUE\n");
        return;
      }
      pcVar3 = local_404;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
      while ((cVar1 != '\0' && (*param_1 != '\\'))) {
        *pcVar3 = *param_1;
        param_1 = param_1 + 1;
        pcVar3 = pcVar3 + 1;
        cVar1 = *param_1;
      }
      *pcVar3 = '\0';
      if (*param_1 != '\0') {
        param_1 = param_1 + 1;
      }
      Con_Printf(&DAT_0809ee48,local_404);
    } while (*param_1 != '\0');
  }
  return;
}


// Info_RemoveKey  @ 08052c30
void Info_RemoveKey(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char local_404 [512];
  char local_204 [512];
  
  pcVar2 = strstr(param_2,"\\");
  if (pcVar2 == (char *)0x0) {
    do {
      pcVar2 = param_1;
      if (*param_1 == '\\') {
        pcVar2 = param_1 + 1;
      }
      pcVar4 = local_204;
      cVar1 = *pcVar2;
      while (cVar1 != '\\') {
        if (*pcVar2 == '\0') {
          return;
        }
        *pcVar4 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar2;
      }
      *pcVar4 = '\0';
      pcVar2 = pcVar2 + 1;
      pcVar4 = local_404;
      cVar1 = *pcVar2;
      while ((cVar1 != '\\' && (*pcVar2 != '\0'))) {
        *pcVar4 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar2;
      }
      *pcVar4 = '\0';
      iVar3 = strcmp(param_2,local_204);
      if (iVar3 == 0) {
        strcpy(param_1,pcVar2);
        return;
      }
      param_1 = pcVar2;
    } while (*pcVar2 != '\0');
  }
  else {
    Con_Printf("Can\'t use a key with a \\\n");
  }
  return;
}


// Info_RemovePrefixedKeys  @ 08052ce0
void Info_RemovePrefixedKeys(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char local_404 [512];
  char local_204 [512];
  
  pcVar3 = param_1;
  do {
    if (*pcVar3 == '\\') {
      pcVar3 = pcVar3 + 1;
    }
    pcVar2 = local_204;
    cVar1 = *pcVar3;
    while (cVar1 != '\\') {
      if (*pcVar3 == '\0') {
        return;
      }
      *pcVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar3;
    }
    *pcVar2 = '\0';
    pcVar3 = pcVar3 + 1;
    pcVar2 = local_404;
    cVar1 = *pcVar3;
    while ((cVar1 != '\\' && (*pcVar3 != '\0'))) {
      *pcVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar3;
    }
    *pcVar2 = '\0';
    if (local_204[0] == param_2) {
      Info_RemoveKey(param_1,local_204);
      pcVar3 = param_1;
    }
  } while (*pcVar3 != '\0');
  return;
}


// Info_Serverinfo  @ 0804db90
undefined1 * Info_Serverinfo(void)

{
  return serverinfo;
}


// Info_SetValueForKey  @ 08052f60
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


// Info_SetValueForStarKey  @ 08052d80
void Info_SetValueForStarKey(char *param_1,char *param_2,char *param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte local_404 [1024];
  
  pcVar3 = strstr(param_2,"\\");
  if ((pcVar3 == (char *)0x0) && (pcVar3 = strstr(param_3,"\\"), pcVar3 == (char *)0x0)) {
    pcVar3 = strstr(param_2,"\"");
    if ((pcVar3 == (char *)0x0) && (pcVar3 = strstr(param_3,"\""), pcVar3 == (char *)0x0)) {
      uVar4 = 0xffffffff;
      pcVar3 = param_2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (~uVar4 - 1 < 0x40) {
        uVar4 = 0xffffffff;
        pcVar3 = param_3;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (~uVar4 - 1 < 0x40) {
          Info_RemoveKey(param_1,param_2);
          if (param_3 == (char *)0x0) {
            return;
          }
          iVar5 = -1;
          pcVar3 = param_3;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          if (iVar5 == -2) {
            return;
          }
          sprintf((char *)local_404,"\\%s\\%s",param_2,param_3);
          uVar4 = 0xffffffff;
          pbVar7 = local_404;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            bVar2 = *pbVar7;
            pbVar7 = pbVar7 + 1;
          } while (bVar2 != 0);
          uVar6 = 0xffffffff;
          pcVar3 = param_1;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          if (param_4 < (int)((~uVar4 - 2) + ~uVar6)) {
            Con_Printf("Info string length exceeded\n");
            return;
          }
          uVar4 = 0xffffffff;
          pcVar3 = param_1;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          param_1 = param_1 + (~uVar4 - 1);
          pbVar7 = local_404;
          do {
            if (local_404[0] == 0) {
              *param_1 = '\0';
              return;
            }
            bVar2 = *pbVar7;
            uVar4 = (uint)bVar2;
            pbVar7 = pbVar7 + 1;
            iVar5 = strcasecmp(param_2,"name");
            if (iVar5 == 0) {
LAB_08052f3d:
              if (0xd < (int)uVar4) {
                *param_1 = (char)uVar4;
                param_1 = param_1 + 1;
              }
            }
            else {
              uVar4 = bVar2 & 0x7f;
              if (uVar4 - 0x20 < 0x60) {
                iVar5 = strcasecmp(param_2,"team");
                if (iVar5 == 0) {
                  uVar4 = tolower(uVar4);
                }
                goto LAB_08052f3d;
              }
            }
            local_404[0] = *pbVar7;
          } while( true );
        }
      }
      Con_Printf("Keys and values must be < 64 characters.\n");
    }
    else {
      Con_Printf("Can\'t use keys or values with a \"\n");
    }
  }
  else {
    Con_Printf("Can\'t use keys or values with a \\\n");
  }
  return;
}


// Info_ValueForKey  @ 08052b60
undefined * Info_ValueForKey(char *param_1,char *param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char local_204 [512];
  
  uVar1 = valueindex_394 + 1;
  uVar3 = uVar1;
  if ((int)uVar1 < 0) {
    uVar3 = valueindex_394 + 4;
  }
  valueindex_394 = uVar1 - (uVar3 & 0xfffffffc);
  if (*param_1 != '\\') goto LAB_08052b94;
  do {
    param_1 = param_1 + 1;
LAB_08052b94:
    pcVar5 = local_204;
    cVar2 = *param_1;
    while (cVar2 != '\\') {
      if (*param_1 == '\0') goto LAB_08052c19;
      *pcVar5 = *param_1;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
      cVar2 = *param_1;
    }
    *pcVar5 = '\0';
    param_1 = param_1 + 1;
    pcVar5 = value_393 + valueindex_394 * 0x200;
    cVar2 = *param_1;
    while ((cVar2 != '\\' && (*param_1 != '\0'))) {
      *pcVar5 = *param_1;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
      cVar2 = *param_1;
    }
    *pcVar5 = '\0';
    iVar4 = strcmp(param_2,local_204);
    if (iVar4 == 0) {
      return value_393 + valueindex_394 * 0x200;
    }
  } while (*param_1 != '\0');
LAB_08052c19:
  return &DAT_0809ebf8;
}


// Info_WriteVars  @ 08057680
void Info_WriteVars(FILE *param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char local_204 [512];
  
  pcVar6 = &DAT_081b9acc;
  uVar1 = valueindex_104 + 1;
  uVar3 = uVar1;
  if ((int)uVar1 < 0) {
    uVar3 = valueindex_104 + 4;
  }
  valueindex_104 = uVar1 - (uVar3 & 0xfffffffc);
  if (DAT_081b9acc != '\\') goto LAB_080576b8;
  do {
    pcVar6 = pcVar6 + 1;
LAB_080576b8:
    pcVar5 = local_204;
    cVar2 = *pcVar6;
    while (cVar2 != '\\') {
      if (*pcVar6 == '\0') {
        return;
      }
      *pcVar5 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar6;
    }
    *pcVar5 = '\0';
    pcVar6 = pcVar6 + 1;
    pcVar5 = value_103 + valueindex_104 * 0x200;
    cVar2 = *pcVar6;
    while ((cVar2 != '\\' && (*pcVar6 != '\0'))) {
      *pcVar5 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar6;
    }
    *pcVar5 = '\0';
    iVar4 = Cvar_FindVar(local_204);
    if ((iVar4 == 0) && (local_204[0] != '*')) {
      fprintf(param_1,"setinfo \"%s\" \"%s\"\n",local_204,value_103 + valueindex_104 * 0x200);
    }
  } while (*pcVar6 != '\0');
  return;
}


