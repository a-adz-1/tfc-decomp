// Info_FindLargestKey  @ 0007e780
char * Info_FindLargestKey(char *s,int maxsize)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int local_120;
  char local_11c [128];
  char local_9c [140];
  
                    /* Unresolved local var: char[128] key@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???]
                       Unresolved local var: int largest_size@[???] */
  Info_FindLargestKey::largest_key[0] = '\0';
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
                    /* Unresolved local var: int nCount@[???]
                       Unresolved local var: int size@[???] */
  local_120 = 0;
  while (cVar1 != '\0') {
    pcVar6 = s + 0x7f;
    pcVar3 = local_11c;
    if (cVar1 != '\\') {
      do {
        s = s + 1;
        *pcVar3 = cVar1;
        cVar1 = *s;
        pcVar3 = pcVar3 + 1;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
      } while (s != pcVar6);
    }
    *pcVar3 = '\0';
    iVar2 = Q_strlen(local_11c);
    if (*s == '\0') break;
    cVar1 = s[1];
    pcVar6 = s + 1;
    pcVar3 = local_9c;
    if ((cVar1 == '\\') || (cVar1 == '\0')) {
LAB_0007e834:
      *pcVar3 = '\0';
      if (cVar1 != '\0') goto LAB_0007e869;
      iVar4 = Q_strlen(local_9c);
    }
    else {
      do {
        pcVar6 = pcVar6 + 1;
        *pcVar3 = cVar1;
        cVar1 = *pcVar6;
        pcVar3 = pcVar3 + 1;
        if ((cVar1 == '\\') || (cVar1 == '\0')) goto LAB_0007e834;
      } while (pcVar6 != s + 0x80);
      *pcVar3 = '\0';
LAB_0007e869:
      pcVar6 = pcVar6 + 1;
      iVar4 = Q_strlen(local_9c);
    }
    if (((((local_120 < iVar2 + iVar4) && (local_11c[0] != '*')) &&
         (iVar5 = Q_strcmp(local_11c,"name"), iVar5 != 0)) &&
        ((((iVar5 = Q_strcmp(local_11c,"model"), iVar5 != 0 &&
           (iVar5 = Q_strcmp(local_11c,"rate"), iVar5 != 0)) &&
          ((iVar5 = Q_strcmp(local_11c,"topcolor"), iVar5 != 0 &&
           ((iVar5 = Q_strcmp(local_11c,"bottomcolor"), iVar5 != 0 &&
            (iVar5 = Q_strcmp(local_11c,"cl_updaterate"), iVar5 != 0)))))) &&
         (iVar5 = Q_strcmp(local_11c,"cl_lw"), iVar5 != 0)))) &&
       (((iVar5 = Q_strcmp(local_11c,"cl_lc"), iVar5 != 0 &&
         (iVar5 = Q_strcmp(local_11c,"*hltv"), iVar5 != 0)) &&
        (iVar5 = Q_strcmp(local_11c,"*sid"), iVar5 != 0)))) {
      Q_strncpy(Info_FindLargestKey::largest_key,local_11c,0x7f);
      Info_FindLargestKey::largest_key[0x7f] = '\0';
      local_120 = iVar2 + iVar4;
    }
    s = pcVar6;
    cVar1 = *pcVar6;
  }
  return Info_FindLargestKey::largest_key;
}


// Info_IsKeyImportant  @ 0007e670
qboolean Info_IsKeyImportant(char *key)

{
  int iVar1;
  qboolean qVar2;
  
  qVar2 = true;
  if (*key != '*') {
    iVar1 = Q_strcmp(key,"name");
    if (iVar1 != 0) {
      iVar1 = Q_strcmp(key,"model");
      if (iVar1 != 0) {
        iVar1 = Q_strcmp(key,"rate");
        if (iVar1 != 0) {
          iVar1 = Q_strcmp(key,"topcolor");
          if (iVar1 != 0) {
            iVar1 = Q_strcmp(key,"bottomcolor");
            if (iVar1 != 0) {
              iVar1 = Q_strcmp(key,"cl_updaterate");
              if (iVar1 != 0) {
                iVar1 = Q_strcmp(key,"cl_lw");
                if (iVar1 != 0) {
                  iVar1 = Q_strcmp(key,"cl_lc");
                  if (iVar1 != 0) {
                    iVar1 = Q_strcmp(key,"*hltv");
                    if (iVar1 != 0) {
                      iVar1 = Q_strcmp(key,"*sid");
                      qVar2 = (qboolean)(iVar1 == 0);
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
  return qVar2;
}


// Info_IsValid  @ 0007ee00
int Info_IsValid(char *s)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_10c [128];
  char local_8c [132];
  char *pcVar5;
  
                    /* Unresolved local var: char[128] key@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???] */
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
                    /* Unresolved local var: int nCount@[???] */
  while( true ) {
    if (cVar1 == '\0') {
      return 1;
    }
    if (cVar1 == '\\') {
      cVar1 = s[1];
      local_10c[0] = '\0';
      pcVar3 = s + 1;
      pcVar4 = s;
    }
    else {
      pcVar3 = local_10c;
      pcVar5 = s;
      while( true ) {
        pcVar4 = pcVar5 + 1;
        *pcVar3 = cVar1;
        cVar1 = *pcVar4;
        pcVar3 = pcVar3 + 1;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        pcVar5 = pcVar4;
        if (pcVar4 == s + 0x7f) {
          return 0;
        }
      }
      *pcVar3 = '\0';
      if (cVar1 == '\0') {
        return 0;
      }
      cVar1 = pcVar5[2];
      pcVar3 = pcVar5 + 2;
    }
    s = pcVar3;
    pcVar3 = local_8c;
    if ((cVar1 != '\\') && (cVar1 != '\0')) {
      while( true ) {
        s = s + 1;
        *pcVar3 = cVar1;
        cVar1 = *s;
        pcVar3 = pcVar3 + 1;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        if (s == pcVar4 + 0x80) {
          return 0;
        }
      }
    }
    *pcVar3 = '\0';
    iVar2 = Q_strlen(local_8c);
    if (iVar2 == 0) break;
    cVar1 = '\0';
    if (*s != '\0') {
      cVar1 = s[1];
      s = s + 1;
    }
  }
  return 0;
}


// Info_Print  @ 0007ec90
void Info_Print(char *s)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_11c [20];
  undefined1 local_108;
  char local_9c [140];
  
                    /* Unresolved local var: char[128] key@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???]
                       Unresolved local var: int l@[???] */
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
  if (cVar1 != '\0') {
                    /* Unresolved local var: int nCount@[???] */
    do {
      pcVar3 = local_11c;
      if ((cVar1 == '\\') || (cVar1 == '\0')) {
        iVar2 = 0;
LAB_0007edb0:
        Q_memset(pcVar3,0x20,0x14 - iVar2);
        local_108 = 0;
        pcVar3 = s;
      }
      else {
        pcVar4 = s + 0x7f;
        do {
          s = s + 1;
          *pcVar3 = cVar1;
          cVar1 = *s;
          pcVar3 = pcVar3 + 1;
          if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        } while (s != pcVar4);
        iVar2 = (int)pcVar3 - (int)local_11c;
        if (iVar2 < 0x14) goto LAB_0007edb0;
        *pcVar3 = '\0';
        pcVar3 = s;
      }
      pcVar4 = local_11c;
      Con_Printf("%s",local_11c);
      if (*pcVar3 == '\0') {
        Con_Printf("MISSING VALUE\n",pcVar4);
        return;
      }
      cVar1 = pcVar3[1];
      s = pcVar3 + 1;
      pcVar4 = local_9c;
      if ((cVar1 == '\\') || (cVar1 == '\0')) {
LAB_0007ed6b:
        *pcVar4 = '\0';
        if (cVar1 != '\0') goto LAB_0007ed9b;
      }
      else {
        do {
          s = s + 1;
          *pcVar4 = cVar1;
          cVar1 = *s;
          pcVar4 = pcVar4 + 1;
          if ((cVar1 == '\\') || (cVar1 == '\0')) goto LAB_0007ed6b;
        } while (s != pcVar3 + 0x80);
        *pcVar4 = '\0';
LAB_0007ed9b:
        s = s + 1;
      }
      Con_Printf("%s\n",local_9c);
      cVar1 = *s;
    } while (cVar1 != '\0');
  }
  return;
}


// Info_RemoveKey  @ 0007e460
void Info_RemoveKey(char *s,char *key)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  size_t count;
  char local_11c [128];
  char local_9c [140];
  
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char[128] pkey@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???]
                       Unresolved local var: int cmpsize@[???] */
  sVar2 = strlen(key);
  count = 0x7f;
  if (sVar2 < 0x7f) {
    count = sVar2;
  }
  pcVar3 = Q_strstr(key,"\\");
  if (pcVar3 == (char *)0x0) {
    cVar1 = *s;
                    /* Unresolved local var: int nCount@[???] */
    pcVar3 = s;
    if (cVar1 == '\\') goto LAB_0007e55d;
LAB_0007e4ce:
    if (cVar1 != '\0') {
      uVar7 = 0;
      pcVar5 = local_11c;
      while( true ) {
        uVar7 = uVar7 + 1;
        s = s + 1;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
        cVar1 = *s;
        if ((0x7e < uVar7) || (cVar1 == '\\')) break;
        if (cVar1 == '\0') {
          return;
        }
      }
      do {
        cVar1 = s[1];
        pcVar8 = s + 1;
        *pcVar5 = '\0';
        if ((cVar1 == '\0') || (cVar1 == '\\')) {
          pcVar5 = local_9c;
          s = pcVar8;
        }
        else {
          pcVar6 = s + 0x80;
          pcVar5 = local_9c;
          do {
            pcVar8 = pcVar8 + 1;
            *pcVar5 = cVar1;
            cVar1 = *pcVar8;
            pcVar5 = pcVar5 + 1;
            s = pcVar8;
            if ((cVar1 == '\0') || (cVar1 == '\\')) break;
          } while (pcVar8 != pcVar6);
        }
        *pcVar5 = '\0';
        iVar4 = Q_strncmp(key,local_11c,count);
        if (iVar4 == 0) {
          Q_strcpy(pcVar3,s);
          return;
        }
        cVar1 = *s;
        if (cVar1 == '\0') {
          return;
        }
        pcVar3 = s;
        if (cVar1 != '\\') goto LAB_0007e4ce;
LAB_0007e55d:
        cVar1 = pcVar3[1];
        s = pcVar3 + 1;
        if (cVar1 != '\\') goto LAB_0007e4ce;
        pcVar5 = local_11c;
      } while( true );
    }
  }
  else {
    Con_Printf("Can\'t use a key with a \\\n");
  }
  return;
}


// Info_RemovePrefixedKeys  @ 0007e590
void Info_RemovePrefixedKeys(char *start,char prefix)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  char local_10c [128];
  char local_8c [128];
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char[128] pkey@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???] */
                    /* Unresolved local var: int nCount@[???] */
  cVar1 = *start;
  pcVar4 = start;
  do {
    if (cVar1 == '\\') {
      cVar1 = pcVar4[1];
      pcVar4 = pcVar4 + 1;
      if (cVar1 != '\\') goto LAB_0007e5b1;
      pcVar2 = local_10c;
    }
    else {
LAB_0007e5b1:
      if (cVar1 == '\0') {
        return;
      }
      uVar5 = 0;
      pcVar2 = local_10c;
      while( true ) {
        uVar5 = uVar5 + 1;
        pcVar4 = pcVar4 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
        cVar1 = *pcVar4;
        if ((0x7e < uVar5) || (cVar1 == '\\')) break;
        if (cVar1 == '\0') {
          return;
        }
      }
    }
    cVar1 = pcVar4[1];
    *pcVar2 = '\0';
    pcVar2 = pcVar4 + 1;
    if ((cVar1 == '\\') || (cVar1 == '\0')) {
      pcVar3 = local_8c;
    }
    else {
      pcVar3 = local_8c;
      do {
        pcVar2 = pcVar2 + 1;
        *pcVar3 = cVar1;
        cVar1 = *pcVar2;
        pcVar3 = pcVar3 + 1;
        if ((cVar1 == '\0') || (cVar1 == '\\')) break;
      } while (pcVar2 != pcVar4 + 0x80);
    }
    *pcVar3 = '\0';
    pcVar4 = pcVar2;
    if (local_10c[0] == prefix) {
      Info_RemoveKey(start,local_10c);
      cVar1 = *start;
      pcVar4 = start;
    }
    if (cVar1 == '\0') {
      return;
    }
  } while( true );
}


// Info_Serverinfo  @ 0005f0f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Info_Serverinfo(void)

{
  return serverinfo;
}


// Info_SetValueForKey  @ 0007ec50
void Info_SetValueForKey(char *s,char *key,char *value,int maxsize)

{
  if (*key != '*') {
    Info_SetValueForStarKey(s,key,value,maxsize);
    return;
  }
  Con_Printf("Can\'t set * keys\n");
  return;
}


// Info_SetValueForStarKey  @ 0007e9c0
void Info_SetValueForStarKey(char *s,char *key,char *value,int maxsize)

{
  char *pcVar1;
  int iVar2;
  qboolean qVar3;
  int iVar4;
  qboolean qVar5;
  __int32_t **pp_Var6;
  byte *__s;
  byte *pbVar7;
  byte bVar8;
  byte local_41c [1036];
  
                    /* Unresolved local var: char[1024] newVal@[???]
                       Unresolved local var: char * v@[???]
                       Unresolved local var: int c@[???] */
  pcVar1 = Q_strstr(key,"\\");
  if ((pcVar1 == (char *)0x0) && (pcVar1 = Q_strstr(value,"\\"), pcVar1 == (char *)0x0)) {
    pcVar1 = Q_strstr(key,"..");
    if ((pcVar1 == (char *)0x0) && (pcVar1 = Q_strstr(value,".."), pcVar1 == (char *)0x0)) {
      pcVar1 = Q_strstr(key,"\"");
      if ((pcVar1 == (char *)0x0) && (pcVar1 = Q_strstr(value,"\""), pcVar1 == (char *)0x0)) {
        iVar2 = Q_strlen(key);
        if ((iVar2 < 1) ||
           ((iVar2 = Q_strlen(key), 0x7f < iVar2 || (iVar2 = Q_strlen(value), 0x7f < iVar2)))) {
          Con_Printf("Keys and values must be < %i characters and > 0.\n",0x80);
        }
        else {
          qVar3 = Q_UnicodeValidate(value);
          if (qVar3 == 0) {
            Con_Printf("Values must be valid utf8 text\n");
          }
          else {
            while (pcVar1 = Info_ValueForKey(s,key), *pcVar1 != '\0') {
              Info_RemoveKey(s,key);
            }
            if ((value != (char *)0x0) && (iVar2 = Q_strlen(value), iVar2 != 0)) {
              __s = local_41c;
              snprintf((char *)__s,0x400,"\\%s\\%s",key,value);
              iVar2 = Q_strlen((char *)__s);
              iVar4 = Q_strlen(s);
              if (iVar4 + iVar2 < maxsize) {
LAB_0007ebe6:
                iVar2 = Q_strlen(s);
                pbVar7 = (byte *)(s + iVar2);
                while (bVar8 = *__s, bVar8 != 0) {
                  __s = __s + 1;
                  iVar2 = Q_stricmp(key,"team");
                    /* Unresolved local var: int __res@[???] */
                  if ((iVar2 == 0) && (bVar8 + 0x80 < 0x180)) {
                    pp_Var6 = __ctype_tolower_loc();
                    bVar8 = (byte)(*pp_Var6)[bVar8];
                  }
                  *pbVar7 = bVar8;
                  pbVar7 = pbVar7 + 1;
                }
                *pbVar7 = 0;
              }
              else {
                qVar5 = Info_IsKeyImportant(key);
                if (qVar5 != false) {
                  do {
                    /* Unresolved local var: char * largekey@[???] */
                    pcVar1 = Info_FindLargestKey(s,maxsize);
                    Info_RemoveKey(s,pcVar1);
                    iVar2 = Q_strlen((char *)__s);
                    iVar4 = Q_strlen(s);
                    if (iVar4 + iVar2 < maxsize) {
                      if (*pcVar1 != '\0') goto LAB_0007ebe6;
                      break;
                    }
                  } while (*pcVar1 != '\0');
                }
                Con_Printf("Info string length exceeded\n");
              }
            }
          }
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


// Info_ValueForKey  @ 0007e370
char * Info_ValueForKey(char *s,char *key)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  char local_8c [128];
  
                    /* Unresolved local var: char[128] pkey@[???]
                       Unresolved local var: char * o@[???] */
  Info_ValueForKey::valueindex = (Info_ValueForKey::valueindex + 1) % 4;
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
  uVar3 = 0;
  pcVar4 = local_8c;
  do {
                    /* Unresolved local var: int nCount@[???] */
    if ((uVar3 < 0x7f) && (cVar1 != '\\')) {
      if (cVar1 == '\0') {
LAB_0007e435:
        return "";
      }
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
      uVar3 = uVar3 + 1;
    }
    else {
      cVar1 = s[1];
      *pcVar4 = '\0';
      pcVar5 = s + 1;
      pcVar4 = Info_ValueForKey::value[Info_ValueForKey::valueindex];
      if ((cVar1 != '\\') && (cVar1 != '\0')) {
        do {
          *pcVar4 = cVar1;
          pcVar5 = pcVar5 + 1;
          pcVar4 = pcVar4 + 1;
          cVar1 = *pcVar5;
          if ((cVar1 == '\0') || (cVar1 == '\\')) break;
        } while (pcVar5 != s + 0x80);
      }
      *pcVar4 = '\0';
      iVar2 = Q_strcmp(key,local_8c);
      if (iVar2 == 0) {
        return Info_ValueForKey::value[Info_ValueForKey::valueindex];
      }
      if (*pcVar5 == '\0') goto LAB_0007e435;
      uVar3 = 0;
      pcVar4 = local_8c;
      s = pcVar5;
    }
    s = s + 1;
    cVar1 = *s;
  } while( true );
}


// Info_WriteVars  @ 00073cc0
void Info_WriteVars(FileHandle_t fp)

{
  char cVar1;
  cvar_t *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool *pbVar5;
  char local_20c [516];
  
                    /* Unresolved local var: cvar_t * pcvar@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char * o@[???] */
  pcVar3 = cls.userinfo;
  Info_WriteVars::valueindex = (Info_WriteVars::valueindex + 1) % 4;
  cVar1 = cls.userinfo[0];
  if (cls.userinfo[0] == '\\') {
    pcVar3 = cls.userinfo + 1;
    cVar1 = cls.userinfo[1];
  }
  pcVar4 = local_20c;
  do {
    if (cVar1 == '\\') {
      *pcVar4 = '\0';
      pbVar5 = Info_WriteVars::value[Info_WriteVars::valueindex];
      cVar1 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
      while (((bool)cVar1 != false && (cVar1 != '\\'))) {
        pcVar3 = pcVar3 + 1;
        *pbVar5 = (bool)cVar1;
        pbVar5 = pbVar5 + 1;
        cVar1 = *pcVar3;
      }
      *pbVar5 = false;
      pcVar2 = Cvar_FindVar(local_20c);
      if ((pcVar2 == (cvar_t *)0x0) && (local_20c[0] != '*')) {
        FS_FPrintf(fp,"setinfo \"%s\" \"%s\"\n",local_20c,
                   Info_WriteVars::value + Info_WriteVars::valueindex);
      }
      if (*pcVar3 == '\0') {
        return;
      }
      pcVar4 = local_20c;
    }
    else {
      if (cVar1 == '\0') {
        return;
      }
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    }
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  } while( true );
}


