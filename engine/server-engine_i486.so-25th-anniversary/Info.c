// Info_FindLargestKey  @ 0005ecf0
char * Info_FindLargestKey(char *s,int maxsize)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar7;
  int in_GS_OFFSET;
  int local_130;
  char local_120 [128];
  char local_a0 [128];
  int local_20;
  char *pcVar6;
  
                    /* Unresolved local var: char[128] key@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???]
                       Unresolved local var: int largest_size@[???] */
  Info_FindLargestKey::largest_key[0] = '\0';
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
                    /* Unresolved local var: int nCount@[???]
                       Unresolved local var: int size@[???] */
  local_130 = 0;
  while (cVar1 != '\0') {
    pcVar7 = local_120;
    pcVar5 = local_120;
    if (cVar1 != '\\') {
      do {
        pcVar7 = pcVar5 + 1;
        s = s + 1;
        *pcVar5 = cVar1;
        cVar1 = *s;
        if ((cVar1 == '\0') || (cVar1 == '\\')) break;
        pcVar5 = pcVar7;
      } while (pcVar7 != local_120 + 0x7f);
    }
    *pcVar7 = '\0';
    iVar2 = Q_strlen(local_120);
    if (*s == '\0') break;
    cVar1 = s[1];
    pcVar7 = s + 1;
    if ((cVar1 == '\0') || (cVar1 == '\\')) {
      pcVar5 = local_a0;
LAB_0005edbc:
      *pcVar5 = '\0';
      if (cVar1 != '\0') goto LAB_0005ee09;
    }
    else {
      pcVar6 = local_a0;
      do {
        pcVar5 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
        *pcVar6 = cVar1;
        cVar1 = *pcVar7;
        if ((cVar1 == '\0') || (cVar1 == '\\')) goto LAB_0005edbc;
        pcVar6 = pcVar5;
      } while (pcVar7 != s + 0x80);
      *pcVar5 = '\0';
LAB_0005ee09:
      pcVar7 = pcVar7 + 1;
    }
    iVar3 = Q_strlen(local_a0);
    if (((((local_130 < iVar2 + iVar3) && (local_120[0] != '*')) &&
         (iVar4 = Q_strcmp(local_120,"name"), iVar4 != 0)) &&
        ((((iVar4 = Q_strcmp(local_120,"model"), iVar4 != 0 &&
           (iVar4 = Q_strcmp(local_120,"rate"), iVar4 != 0)) &&
          ((iVar4 = Q_strcmp(local_120,"topcolor"), iVar4 != 0 &&
           ((iVar4 = Q_strcmp(local_120,"bottomcolor"), iVar4 != 0 &&
            (iVar4 = Q_strcmp(local_120,"cl_updaterate"), iVar4 != 0)))))) &&
         (iVar4 = Q_strcmp(local_120,"cl_lw"), iVar4 != 0)))) &&
       (((iVar4 = Q_strcmp(local_120,"cl_lc"), iVar4 != 0 &&
         (iVar4 = Q_strcmp(local_120,"*hltv"), iVar4 != 0)) &&
        (iVar4 = Q_strcmp(local_120,"*sid"), iVar4 != 0)))) {
      Q_strncpy(Info_FindLargestKey::largest_key,local_120,0x7f);
      Info_FindLargestKey::largest_key[0x7f] = '\0';
      local_130 = iVar2 + iVar3;
    }
    s = pcVar7;
    cVar1 = *pcVar7;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return Info_FindLargestKey::largest_key;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Info_IsKeyImportant  @ 0005ebf0
qboolean Info_IsKeyImportant(char *key)

{
  int iVar1;
  
  if ((((((*key != '*') && (iVar1 = Q_strcmp(key,"name"), iVar1 != 0)) &&
        (iVar1 = Q_strcmp(key,"model"), iVar1 != 0)) &&
       ((iVar1 = Q_strcmp(key,"rate"), iVar1 != 0 && (iVar1 = Q_strcmp(key,"topcolor"), iVar1 != 0))
       )) && ((iVar1 = Q_strcmp(key,"bottomcolor"), iVar1 != 0 &&
              ((iVar1 = Q_strcmp(key,"cl_updaterate"), iVar1 != 0 &&
               (iVar1 = Q_strcmp(key,"cl_lw"), iVar1 != 0)))))) &&
     ((iVar1 = Q_strcmp(key,"cl_lc"), iVar1 != 0 && (iVar1 = Q_strcmp(key,"*hltv"), iVar1 != 0)))) {
    iVar1 = Q_strcmp(key,"*sid");
    return (uint)(iVar1 == 0);
  }
  return true;
}


// Info_IsValid  @ 0005f3d0
int Info_IsValid(char *s)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar5;
  int in_GS_OFFSET;
  char local_110 [128];
  char local_90 [128];
  int local_10;
  char *pcVar4;
  
                    /* Unresolved local var: char[128] key@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
                    /* Unresolved local var: int nCount@[???] */
  do {
    if (cVar1 == '\0') {
      iVar2 = 1;
LAB_0005f492:
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return iVar2;
    }
    pcVar5 = local_110;
    if (cVar1 != '\\') {
      while( true ) {
        pcVar3 = pcVar5 + 1;
        s = s + 1;
        *pcVar5 = cVar1;
        cVar1 = *s;
        if ((cVar1 == '\0') || (cVar1 == '\\')) break;
        pcVar5 = pcVar3;
        if (pcVar3 == local_110 + 0x7f) goto LAB_0005f490;
      }
      *pcVar3 = '\0';
      if (cVar1 != '\0') goto LAB_0005f43b;
LAB_0005f490:
      iVar2 = 0;
      goto LAB_0005f492;
    }
    local_110[0] = '\0';
LAB_0005f43b:
    cVar1 = s[1];
    pcVar5 = s + 1;
    pcVar3 = local_90;
    if ((cVar1 != '\0') && (pcVar4 = local_90, cVar1 != '\\')) {
      while( true ) {
        pcVar3 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
        *pcVar4 = cVar1;
        cVar1 = *pcVar5;
        if ((cVar1 == '\0') || (cVar1 == '\\')) break;
        pcVar4 = pcVar3;
        if (pcVar5 == s + 0x80) goto LAB_0005f490;
      }
    }
    s = pcVar5;
    *pcVar3 = '\0';
    iVar2 = Q_strlen(local_90);
    if (iVar2 == 0) goto LAB_0005f490;
    cVar1 = '\0';
    if (*s != '\0') {
      cVar1 = s[1];
      s = s + 1;
    }
  } while( true );
}


// Info_Print  @ 0005f250
void Info_Print(char *s)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  char local_120 [128];
  char local_a0 [128];
  int local_20;
  char *pcVar5;
  
                    /* Unresolved local var: char[128] key@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???]
                       Unresolved local var: int l@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
  if (cVar1 != '\0') {
                    /* Unresolved local var: int nCount@[???] */
    do {
      pcVar3 = local_120;
      if (cVar1 == '\\') {
        iVar2 = 0;
        pcVar4 = local_120;
LAB_0005f370:
        Q_memset(pcVar4,0x20,0x14 - iVar2);
        local_120[0x14] = 0;
        pcVar3 = s;
      }
      else {
        do {
          pcVar4 = pcVar3 + 1;
          s = s + 1;
          *pcVar3 = cVar1;
          cVar1 = *s;
          if ((cVar1 == '\0') || (cVar1 == '\\')) break;
          pcVar3 = pcVar4;
        } while (pcVar4 != local_120 + 0x7f);
        iVar2 = (int)pcVar4 - (int)local_120;
        if (iVar2 < 0x14) goto LAB_0005f370;
        *pcVar4 = '\0';
        pcVar3 = s;
      }
      pcVar4 = local_120;
      Con_Printf("%s",local_120);
      if (*pcVar3 == '\0') {
        Con_Printf("MISSING VALUE\n",pcVar4);
        break;
      }
      cVar1 = pcVar3[1];
      s = pcVar3 + 1;
      if ((cVar1 == '\0') || (cVar1 == '\\')) {
        pcVar4 = local_a0;
LAB_0005f31c:
        *pcVar4 = '\0';
        if (cVar1 != '\0') goto LAB_0005f35c;
      }
      else {
        pcVar5 = local_a0;
        do {
          pcVar4 = pcVar5 + 1;
          s = s + 1;
          *pcVar5 = cVar1;
          cVar1 = *s;
          if ((cVar1 == '\0') || (cVar1 == '\\')) goto LAB_0005f31c;
          pcVar5 = pcVar4;
        } while (s != pcVar3 + 0x80);
        *pcVar4 = '\0';
LAB_0005f35c:
        s = s + 1;
      }
      Con_Printf("%s\n",local_a0);
      cVar1 = *s;
    } while (cVar1 != '\0');
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Info_RemoveKey  @ 0005e8f0
void Info_RemoveKey(char *s,char *key)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  size_t count;
  char *pcVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  char local_120 [128];
  char local_a0 [128];
  int local_20;
  
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char[128] pkey@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???]
                       Unresolved local var: int cmpsize@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
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
    if (cVar1 == '\\') goto LAB_0005ea2a;
LAB_0005e98c:
    if (cVar1 != '\0') {
      pcVar6 = local_120;
      do {
        pcVar5 = pcVar6 + 1;
        *pcVar6 = cVar1;
        cVar1 = s[1];
        if ((cVar1 == '\\') || (pcVar5 == local_120 + 0x7f)) {
          cVar1 = s[2];
          s = s + 2;
          *pcVar5 = '\0';
          if ((cVar1 == '\\') || (cVar1 == '\0')) {
            pcVar6 = local_a0;
            goto LAB_0005e9f4;
          }
LAB_0005e9ce:
          pcVar5 = local_a0;
          do {
            pcVar6 = pcVar5 + 1;
            s = s + 1;
            *pcVar5 = cVar1;
            cVar1 = *s;
            if ((cVar1 == '\\') || (cVar1 == '\0')) break;
            pcVar5 = pcVar6;
          } while (pcVar6 != local_a0 + 0x7f);
LAB_0005e9f4:
          do {
            *pcVar6 = '\0';
            iVar4 = Q_strncmp(key,local_120,count);
            if (iVar4 == 0) {
              iVar4 = Q_strlen(s);
              memmove(pcVar3,s,iVar4 + 1);
              goto LAB_0005e951;
            }
            cVar1 = *s;
            if (cVar1 == '\0') goto LAB_0005e951;
            pcVar3 = s;
            if (cVar1 != '\\') goto LAB_0005e98c;
LAB_0005ea2a:
            cVar1 = pcVar3[1];
            s = pcVar3 + 1;
            if (cVar1 != '\\') goto LAB_0005e98c;
            cVar1 = pcVar3[2];
            s = pcVar3 + 2;
            local_120[0] = '\0';
            if ((cVar1 != '\0') && (cVar1 != '\\')) goto LAB_0005e9ce;
            pcVar6 = local_a0;
          } while( true );
        }
        s = s + 1;
        pcVar6 = pcVar5;
      } while (cVar1 != '\0');
    }
  }
  else {
    Con_Printf("Can\'t use a key with a \\\n");
  }
LAB_0005e951:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Info_RemovePrefixedKeys  @ 0005eaa0
void Info_RemovePrefixedKeys(char *start,char prefix)

{
  char cVar1;
  char *pcVar2;
  char *pcVar4;
  int in_GS_OFFSET;
  char local_120 [128];
  char local_a0 [128];
  int local_20;
  char *pcVar3;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char[128] pkey@[???]
                       Unresolved local var: char[128] value@[???]
                       Unresolved local var: char * o@[???] */
                    /* Unresolved local var: int nCount@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = *start;
  pcVar4 = start;
  pcVar3 = start;
  if (cVar1 == '\\') goto LAB_0005eb6b;
LAB_0005eae1:
  if (cVar1 != '\0') {
    pcVar3 = local_120;
    do {
      pcVar2 = pcVar3 + 1;
      *pcVar3 = cVar1;
      cVar1 = pcVar4[1];
      if ((cVar1 == '\\') || (pcVar2 == local_120 + 0x7f)) {
        cVar1 = pcVar4[2];
        pcVar4 = pcVar4 + 2;
        *pcVar2 = '\0';
        if (cVar1 == '\\') goto LAB_0005ebdc;
        if (cVar1 == '\0') goto LAB_0005ebdc;
LAB_0005eb27:
        pcVar3 = local_a0;
        do {
          pcVar2 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
          *pcVar3 = cVar1;
          cVar1 = *pcVar4;
          if (cVar1 == '\\') goto LAB_0005eb54;
          if (cVar1 == '\0') goto LAB_0005eb54;
          pcVar3 = pcVar2;
        } while (pcVar2 != local_a0 + 0x7f);
        local_a0[0x7f] = 0;
        if (prefix != local_120[0]) goto LAB_0005eb61;
        do {
          Info_RemoveKey(start,local_120);
          cVar1 = *start;
          pcVar4 = start;
          do {
            if (cVar1 == '\0') goto LAB_0005eb80;
LAB_0005eb61:
            pcVar3 = pcVar4;
            if (cVar1 != '\\') goto LAB_0005eae1;
LAB_0005eb6b:
            cVar1 = pcVar3[1];
            pcVar4 = pcVar3 + 1;
            if (cVar1 != '\\') goto LAB_0005eae1;
            cVar1 = pcVar3[2];
            local_120[0] = '\0';
            pcVar4 = pcVar3 + 2;
            if ((cVar1 != '\0') && (cVar1 != '\\')) goto LAB_0005eb27;
LAB_0005ebdc:
            pcVar2 = local_a0;
LAB_0005eb54:
            *pcVar2 = '\0';
          } while (local_120[0] != prefix);
        } while( true );
      }
      pcVar3 = pcVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
LAB_0005eb80:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Info_Serverinfo  @ 00039c50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Info_Serverinfo(void)

{
  return serverinfo;
}


// Info_SetValueForKey  @ 0005f210
void Info_SetValueForKey(char *s,char *key,char *value,int maxsize)

{
  if (*key != '*') {
    Info_SetValueForStarKey(s,key,value,maxsize);
    return;
  }
  Con_Printf("Can\'t set * keys\n");
  return;
}


// Info_SetValueForStarKey  @ 0005ef50
void Info_SetValueForStarKey(char *s,char *key,char *value,int maxsize)

{
  char *pcVar1;
  int iVar2;
  qboolean qVar3;
  int iVar4;
  qboolean qVar5;
  __int32_t **pp_Var6;
  byte bVar7;
  byte *str;
  byte *pbVar8;
  int in_GS_OFFSET;
  byte local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: char[1024] newVal@[???]
                       Unresolved local var: char * v@[???]
                       Unresolved local var: int c@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
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
              str = local_420;
              __snprintf_chk(str,0x400,1,0x400,"\\%s\\%s",key,value);
              iVar2 = Q_strlen((char *)str);
              iVar4 = Q_strlen(s);
              if (iVar4 + iVar2 < maxsize) {
LAB_0005f1ab:
                iVar2 = Q_strlen(s);
                pbVar8 = (byte *)(s + iVar2);
                while (bVar7 = *str, bVar7 != 0) {
                  str = str + 1;
                  iVar2 = Q_stricmp(key,"team");
                  if (iVar2 == 0) {
                    /* Unresolved local var: int __res@[???] */
                    pp_Var6 = __ctype_tolower_loc();
                    bVar7 = (byte)(*pp_Var6)[bVar7];
                  }
                  *pbVar8 = bVar7;
                  pbVar8 = pbVar8 + 1;
                }
                *pbVar8 = 0;
              }
              else {
                qVar5 = Info_IsKeyImportant(key);
                if (qVar5 != false) {
                  do {
                    /* Unresolved local var: char * largekey@[???] */
                    pcVar1 = Info_FindLargestKey(s,maxsize);
                    Info_RemoveKey(s,pcVar1);
                    iVar2 = Q_strlen((char *)str);
                    iVar4 = Q_strlen(s);
                    if (iVar2 + iVar4 < maxsize) {
                      if (*pcVar1 != '\0') goto LAB_0005f1ab;
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
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Info_ValueForKey  @ 0005e7b0
char * Info_ValueForKey(char *s,char *key)

{
  char cVar1;
  int iVar2;
  char (*pacVar3) [128];
  char *pcVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  char local_a0 [128];
  int local_20;
  char *pcVar6;
  
                    /* Unresolved local var: char[128] pkey@[???]
                       Unresolved local var: char * o@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Info_ValueForKey::valueindex = (Info_ValueForKey::valueindex + 1) % 4;
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
                    /* Unresolved local var: int nCount@[???] */
  do {
    if (cVar1 == '\\') {
      pcVar4 = local_a0;
    }
    else {
      if (cVar1 == '\0') {
LAB_0005e8a0:
        pacVar3 = (char (*) [128])0xd7a8b;
LAB_0005e8a5:
        if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
          return *pacVar3;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      pcVar5 = local_a0;
      while( true ) {
        pcVar4 = pcVar5 + 1;
        s = s + 1;
        *pcVar5 = cVar1;
        cVar1 = *s;
        if ((cVar1 == '\\') || (pcVar4 == local_a0 + 0x7f)) break;
        pcVar5 = pcVar4;
        if (cVar1 == '\0') goto LAB_0005e8a0;
      }
    }
    *pcVar4 = '\0';
    pcVar4 = s + 1;
    cVar1 = s[1];
    pcVar5 = Info_ValueForKey::value[Info_ValueForKey::valueindex];
    if ((cVar1 != '\\') && (cVar1 != '\0')) {
      pcVar6 = pcVar5;
      do {
        pcVar5 = pcVar6 + 1;
        pcVar4 = pcVar4 + 1;
        *pcVar6 = cVar1;
        cVar1 = *pcVar4;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        pcVar6 = pcVar5;
      } while (pcVar4 != s + 0x80);
    }
    *pcVar5 = '\0';
    iVar2 = Q_strcmp(key,local_a0);
    if (iVar2 == 0) {
      pacVar3 = Info_ValueForKey::value + Info_ValueForKey::valueindex;
      goto LAB_0005e8a5;
    }
    if (*pcVar4 == '\0') goto LAB_0005e8a0;
    s = pcVar4 + 1;
    cVar1 = pcVar4[1];
  } while( true );
}


// Info_WriteVars  @ 00053700
void Info_WriteVars(FileHandle_t fp)

{
  bool *pbVar1;
  char cVar2;
  cvar_t *pcVar3;
  char *pcVar4;
  char *pcVar6;
  int in_GS_OFFSET;
  char local_210 [512];
  int local_10;
  char *pcVar5;
  
                    /* Unresolved local var: cvar_t * pcvar@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char * o@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Info_WriteVars::valueindex = (Info_WriteVars::valueindex + 1) % 4;
  pcVar6 = cls.userinfo;
  cVar2 = cls.userinfo[0];
  if (cls.userinfo[0] == '\\') {
    pcVar6 = cls.userinfo + 1;
    cVar2 = cls.userinfo[1];
  }
  do {
    if (cVar2 == '\\') {
      pcVar4 = local_210;
    }
    else {
      if (cVar2 == '\0') {
LAB_000537c8:
        if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      pcVar5 = local_210;
      while( true ) {
        pcVar4 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
        *pcVar5 = cVar2;
        cVar2 = *pcVar6;
        if (cVar2 == '\\') break;
        pcVar5 = pcVar4;
        if (cVar2 == '\0') goto LAB_000537c8;
      }
    }
    *pcVar4 = '\0';
    pcVar4 = pcVar6 + 1;
    cVar2 = pcVar6[1];
    pbVar1 = Info_WriteVars::value[Info_WriteVars::valueindex];
    while ((cVar2 != '\\' && ((bool)cVar2 != false))) {
      pcVar4 = pcVar4 + 1;
      *pbVar1 = (bool)cVar2;
      pbVar1 = pbVar1 + 1;
      cVar2 = *pcVar4;
    }
    *pbVar1 = false;
    pcVar3 = Cvar_FindVar(local_210);
    if ((pcVar3 == (cvar_t *)0x0) && (local_210[0] != '*')) {
      FS_FPrintf(fp,"setinfo \"%s\" \"%s\"\n",local_210,
                 Info_WriteVars::value + Info_WriteVars::valueindex);
    }
    if (*pcVar4 == '\0') goto LAB_000537c8;
    pcVar6 = pcVar4 + 1;
    cVar2 = pcVar4[1];
  } while( true );
}


