// Info_FindLargestKey  @ 000c3f00
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
LAB_000c3fcc:
      *pcVar5 = '\0';
      if (cVar1 != '\0') goto LAB_000c4019;
    }
    else {
      pcVar6 = local_a0;
      do {
        pcVar5 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
        *pcVar6 = cVar1;
        cVar1 = *pcVar7;
        if ((cVar1 == '\0') || (cVar1 == '\\')) goto LAB_000c3fcc;
        pcVar6 = pcVar5;
      } while (pcVar7 != s + 0x80);
      *pcVar5 = '\0';
LAB_000c4019:
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


// Info_FindLargestKey  @ 001ce220
char * Info_FindLargestKey(char *s,int maxsize)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  uint *puVar11;
  int in_GS_OFFSET;
  int local_230;
  undefined4 local_220;
  uint local_120 [64];
  int local_20;
  char *pcVar10;
  uint *puVar12;
  
                    /* Unresolved local var: char[256] key@[???]
                       Unresolved local var: char[256] value@[???]
                       Unresolved local var: char * o@[???]
                       Unresolved local var: int largest_size@[???] */
  Info_FindLargestKey::largest_key[0] = '\0';
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cVar4 = *s;
  if (cVar4 == '\\') {
    cVar4 = s[1];
    s = s + 1;
  }
                    /* Unresolved local var: int nCount@[???]
                       Unresolved local var: int size@[???] */
  local_230 = 0;
  while (cVar4 != '\0') {
    if (cVar4 == '\\') {
      local_220._0_1_ = '\0';
      puVar11 = &local_220;
      do {
        puVar12 = puVar11;
        uVar2 = *puVar12 + 0xfefefeff & ~*puVar12;
        uVar3 = uVar2 & 0x80808080;
        puVar11 = puVar12 + 1;
      } while (uVar3 == 0);
      bVar1 = (byte)uVar3;
      if ((uVar2 & 0x8080) == 0) {
        bVar1 = (byte)(uVar3 >> 0x10);
        puVar11 = (uint *)((int)puVar12 + 6);
      }
      iVar5 = (int)puVar11 + ((-3 - (uint)CARRY1(bVar1,bVar1)) - (int)&local_220);
      cVar4 = s[1];
      pcVar8 = s + 1;
      if (cVar4 != '\0') goto LAB_001ce2f8;
LAB_001ce440:
      puVar11 = local_120;
    }
    else {
      pcVar6 = s;
      pcVar10 = (char *)&local_220;
      do {
        pcVar8 = pcVar6;
        pcVar9 = pcVar10 + 1;
        pcVar6 = pcVar8 + 1;
        *pcVar10 = cVar4;
        cVar4 = *pcVar6;
        if (cVar4 == '\0' || cVar4 == '\\') break;
        pcVar10 = pcVar9;
      } while ((int)pcVar6 - (int)s < 0xff);
      *pcVar9 = '\0';
      puVar11 = &local_220;
      do {
        puVar12 = puVar11;
        uVar2 = *puVar12 + 0xfefefeff & ~*puVar12;
        uVar3 = uVar2 & 0x80808080;
        puVar11 = puVar12 + 1;
      } while (uVar3 == 0);
      bVar1 = (byte)uVar3;
      if ((uVar2 & 0x8080) == 0) {
        bVar1 = (byte)(uVar3 >> 0x10);
        puVar11 = (uint *)((int)puVar12 + 6);
      }
      iVar5 = (int)puVar11 + ((-3 - (uint)CARRY1(bVar1,bVar1)) - (int)&local_220);
      if (cVar4 == '\0') break;
      cVar4 = pcVar8[2];
      pcVar8 = pcVar8 + 2;
      if (cVar4 == '\0') goto LAB_001ce440;
LAB_001ce2f8:
      if (cVar4 == '\\') goto LAB_001ce440;
      iVar7 = 0;
      puVar12 = local_120;
      do {
        puVar11 = (uint *)((int)puVar12 + 1);
        pcVar8 = pcVar8 + 1;
        *(char *)puVar12 = cVar4;
        cVar4 = *pcVar8;
        iVar7 = iVar7 + 1;
        if (cVar4 == '\0' || cVar4 == '\\') break;
        puVar12 = puVar11;
      } while (iVar7 < 0xff);
    }
    *(char *)puVar11 = '\0';
    s = pcVar8 + (cVar4 != '\0');
    puVar11 = local_120;
    do {
      puVar12 = puVar11;
      uVar3 = *puVar12 + 0xfefefeff & ~*puVar12;
      uVar2 = uVar3 & 0x80808080;
      puVar11 = puVar12 + 1;
    } while (uVar2 == 0);
    if ((uVar3 & 0x8080) == 0) {
      puVar11 = (uint *)((int)puVar12 + 6);
      uVar2 = uVar2 >> 0x10;
    }
    iVar5 = (int)puVar11 + iVar5 + ((-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2)) - (int)local_120);
    if (((local_230 < iVar5) && ((char)local_220 != '*')) &&
       (iVar7 = strcasecmp((char *)&local_220,"tracker"), iVar7 != 0)) {
      __strcpy_chk(Info_FindLargestKey::largest_key,&local_220,0x100);
      local_230 = iVar5;
    }
    cVar4 = *s;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return Info_FindLargestKey::largest_key;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Info_IsKeyImportant  @ 000c3e00
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


// Info_IsKeyImportant  @ 001ce1e0
bool Info_IsKeyImportant(char *key)

{
  int iVar1;
  
  if (*key != '*') {
    iVar1 = strcasecmp(key,"tracker");
    return iVar1 == 0;
  }
  return true;
}


// Info_IsValid  @ 000c45e0
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
LAB_000c46a2:
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
        if (pcVar3 == local_110 + 0x7f) goto LAB_000c46a0;
      }
      *pcVar3 = '\0';
      if (cVar1 != '\0') goto LAB_000c464b;
LAB_000c46a0:
      iVar2 = 0;
      goto LAB_000c46a2;
    }
    local_110[0] = '\0';
LAB_000c464b:
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
        if (pcVar5 == s + 0x80) goto LAB_000c46a0;
      }
    }
    s = pcVar5;
    *pcVar3 = '\0';
    iVar2 = Q_strlen(local_90);
    if (iVar2 == 0) goto LAB_000c46a0;
    cVar1 = '\0';
    if (*s != '\0') {
      cVar1 = s[1];
      s = s + 1;
    }
  } while( true );
}


// Info_Print  @ 000c4460
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
LAB_000c4580:
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
        if (iVar2 < 0x14) goto LAB_000c4580;
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
LAB_000c452c:
        *pcVar4 = '\0';
        if (cVar1 != '\0') goto LAB_000c456c;
      }
      else {
        pcVar5 = local_a0;
        do {
          pcVar4 = pcVar5 + 1;
          s = s + 1;
          *pcVar5 = cVar1;
          cVar1 = *s;
          if ((cVar1 == '\0') || (cVar1 == '\\')) goto LAB_000c452c;
          pcVar5 = pcVar4;
        } while (s != pcVar3 + 0x80);
        *pcVar4 = '\0';
LAB_000c456c:
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


// Info_RemoveKey  @ 000c3b00
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
    if (cVar1 == '\\') goto LAB_000c3c3a;
LAB_000c3b9c:
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
            goto LAB_000c3c04;
          }
LAB_000c3bde:
          pcVar5 = local_a0;
          do {
            pcVar6 = pcVar5 + 1;
            s = s + 1;
            *pcVar5 = cVar1;
            cVar1 = *s;
            if ((cVar1 == '\\') || (cVar1 == '\0')) break;
            pcVar5 = pcVar6;
          } while (pcVar6 != local_a0 + 0x7f);
LAB_000c3c04:
          do {
            *pcVar6 = '\0';
            iVar4 = Q_strncmp(key,local_120,count);
            if (iVar4 == 0) {
              iVar4 = Q_strlen(s);
              memmove(pcVar3,s,iVar4 + 1);
              goto LAB_000c3b61;
            }
            cVar1 = *s;
            if (cVar1 == '\0') goto LAB_000c3b61;
            pcVar3 = s;
            if (cVar1 != '\\') goto LAB_000c3b9c;
LAB_000c3c3a:
            cVar1 = pcVar3[1];
            s = pcVar3 + 1;
            if (cVar1 != '\\') goto LAB_000c3b9c;
            cVar1 = pcVar3[2];
            s = pcVar3 + 2;
            local_120[0] = '\0';
            if ((cVar1 != '\0') && (cVar1 != '\\')) goto LAB_000c3bde;
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
LAB_000c3b61:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Info_RemoveKey  @ 001cdda0
void __regparm3 Info_RemoveKey(char *s,char *key)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int in_GS_OFFSET;
  char *local_430;
  char local_420 [512];
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * o@[???] */
  cVar3 = *s;
                    /* Unresolved local var: int nCount@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_430 = s;
  if (cVar3 == '\\') goto LAB_001cde6e;
LAB_001cddd7:
  if (cVar3 == '\0') {
LAB_001cdea0:
    if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  pcVar2 = local_420;
  while( true ) {
    pcVar1 = pcVar2 + 1;
    s = s + 1;
    *pcVar2 = cVar3;
    cVar3 = *s;
    if ((cVar3 == '\\') || (pcVar1 == local_420 + 0x1ff)) break;
    pcVar2 = pcVar1;
    if (cVar3 == '\0') goto LAB_001cdea0;
  }
  do {
    cVar3 = s[1];
    s = s + 1;
    *pcVar1 = '\0';
    pcVar2 = local_220;
    if ((cVar3 != '\0') && (iVar4 = 0, pcVar1 = pcVar2, cVar3 != '\\')) {
      do {
        pcVar2 = pcVar1 + 1;
        s = s + 1;
        *pcVar1 = cVar3;
        cVar3 = *s;
        iVar4 = iVar4 + 1;
        if (cVar3 == '\\' || cVar3 == '\0') break;
        pcVar1 = pcVar2;
      } while (iVar4 < 0x1ff);
    }
    *pcVar2 = '\0';
    iVar4 = strcasecmp(key,local_420);
    if (iVar4 == 0) {
      strcpy(local_430,s);
      goto LAB_001cdea0;
    }
    if (cVar3 == '\0') goto LAB_001cdea0;
    local_430 = s;
    if (cVar3 != '\\') goto LAB_001cddd7;
LAB_001cde6e:
    cVar3 = local_430[1];
    s = local_430 + 1;
    if (cVar3 != '\\') goto LAB_001cddd7;
    pcVar1 = local_420;
  } while( true );
}


// Info_RemoveKey  @ 001ce000
void Info_RemoveKey(char *s,char *key)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * o@[???] */
  pcVar1 = strchr(key,0x5c);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  Info_RemoveKey(s,key);
  return;
}


// Info_RemovePrefixedKeys  @ 000c3cb0
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
  if (cVar1 == '\\') goto LAB_000c3d7b;
LAB_000c3cf1:
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
        if (cVar1 == '\\') goto LAB_000c3dec;
        if (cVar1 == '\0') goto LAB_000c3dec;
LAB_000c3d37:
        pcVar3 = local_a0;
        do {
          pcVar2 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
          *pcVar3 = cVar1;
          cVar1 = *pcVar4;
          if (cVar1 == '\\') goto LAB_000c3d64;
          if (cVar1 == '\0') goto LAB_000c3d64;
          pcVar3 = pcVar2;
        } while (pcVar2 != local_a0 + 0x7f);
        local_a0[0x7f] = 0;
        if (prefix != local_120[0]) goto LAB_000c3d71;
        do {
          Info_RemoveKey(start,local_120);
          cVar1 = *start;
          pcVar4 = start;
          do {
            if (cVar1 == '\0') goto LAB_000c3d90;
LAB_000c3d71:
            pcVar3 = pcVar4;
            if (cVar1 != '\\') goto LAB_000c3cf1;
LAB_000c3d7b:
            cVar1 = pcVar3[1];
            pcVar4 = pcVar3 + 1;
            if (cVar1 != '\\') goto LAB_000c3cf1;
            cVar1 = pcVar3[2];
            local_120[0] = '\0';
            pcVar4 = pcVar3 + 2;
            if ((cVar1 != '\0') && (cVar1 != '\\')) goto LAB_000c3d37;
LAB_000c3dec:
            pcVar2 = local_a0;
LAB_000c3d64:
            *pcVar2 = '\0';
          } while (local_120[0] != prefix);
        } while( true );
      }
      pcVar3 = pcVar2;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
LAB_000c3d90:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Info_RemovePrefixedKeys  @ 001ce050
void Info_RemovePrefixedKeys(char *start,char prefix)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  char *local_438;
  char local_42d;
  char local_420 [512];
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * o@[???] */
                    /* Unresolved local var: int nCount@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = *start;
  pcVar2 = start;
  local_42d = cVar1;
  do {
    if (cVar1 == '\\') {
      cVar1 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
      if (cVar1 != '\\') goto LAB_001ce098;
      pcVar3 = local_420;
    }
    else {
LAB_001ce098:
      if (cVar1 == '\0') break;
      pcVar5 = local_420;
      while( true ) {
        pcVar3 = pcVar5 + 1;
        pcVar2 = pcVar2 + 1;
        *pcVar5 = cVar1;
        cVar1 = *pcVar2;
        if ((cVar1 == '\\') || (pcVar3 == local_420 + 0x1ff)) break;
        pcVar5 = pcVar3;
        if (cVar1 == '\0') goto LAB_001ce130;
      }
    }
    local_438 = local_420;
    cVar1 = pcVar2[1];
    *pcVar3 = '\0';
    pcVar2 = pcVar2 + 1;
    if ((cVar1 == '\0') || (cVar1 == '\\')) {
      local_220[0] = '\0';
    }
    else {
      iVar4 = 0;
      pcVar3 = local_220;
      do {
        pcVar5 = pcVar3 + 1;
        pcVar2 = pcVar2 + 1;
        *pcVar3 = cVar1;
        cVar1 = *pcVar2;
        iVar4 = iVar4 + 1;
        if (cVar1 == '\\' || cVar1 == '\0') break;
        pcVar3 = pcVar5;
      } while (iVar4 < 0x1ff);
      *pcVar5 = '\0';
    }
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * o@[???] */
    if ((local_420[0] == prefix) &&
       (pcVar3 = strchr(local_438,0x5c), pcVar2 = start, cVar1 = local_42d, pcVar3 == (char *)0x0))
    {
      Info_RemoveKey(start,local_438);
      local_42d = *start;
      cVar1 = local_42d;
    }
  } while (cVar1 != '\0');
LAB_001ce130:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Info_Serverinfo  @ 0009dd90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Info_Serverinfo(void)

{
  return serverinfo;
}


// Info_SetValueForKey  @ 000c4420
void Info_SetValueForKey(char *s,char *key,char *value,int maxsize)

{
  if (*key != '*') {
    Info_SetValueForStarKey(s,key,value,maxsize);
    return;
  }
  Con_Printf("Can\'t set * keys\n");
  return;
}


// Info_SetValueForKey  @ 001ce6c0
void Info_SetValueForKey(char *s,char *key,char *value,int maxsize)

{
  if (*key != '*') {
    Info_SetValueForStarKey(s,key,value,maxsize);
    return;
  }
  return;
}


// Info_SetValueForStarKey  @ 000c4160
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
              __snprintf_chk(str,0x400,1,0x400,0x259e7c,key,value);
              iVar2 = Q_strlen((char *)str);
              iVar4 = Q_strlen(s);
              if (iVar4 + iVar2 < maxsize) {
LAB_000c43bb:
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
                      if (*pcVar1 != '\0') goto LAB_000c43bb;
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


// Info_SetValueForStarKey  @ 001ce460
void Info_SetValueForStarKey(char *s,char *key,char *value,int maxsize)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *pcVar10;
  int in_GS_OFFSET;
  byte local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: char[1024] news@[???]
                       Unresolved local var: char * v@[???]
                       Unresolved local var: int c@[???] */
  bVar3 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar4 = strchr(key,0x5c);
  if (((((pcVar4 == (char *)0x0) && (pcVar4 = strchr(value,0x5c), pcVar4 == (char *)0x0)) &&
       (pcVar4 = strstr(key,".."), pcVar4 == (char *)0x0)) &&
      ((pcVar4 = strstr(value,".."), pcVar4 == (char *)0x0 &&
       (pcVar4 = strchr(key,0x22), pcVar4 == (char *)0x0)))) &&
     (pcVar4 = strchr(value,0x22), pcVar4 == (char *)0x0)) {
    uVar6 = 0xffffffff;
    pcVar4 = key;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (uint)bVar3 * -2 + 1;
    } while (cVar1 != '\0');
    if (~uVar6 - 1 < 0x80) {
      uVar6 = 0xffffffff;
      pcVar4 = value;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + (uint)bVar3 * -2 + 1;
      } while (cVar1 != '\0');
      if (((~uVar6 - 1 < 0x80) && (Info_RemoveKey(s,key), value != (char *)0x0)) && (*value != '\0')
         ) {
        pbVar9 = local_420;
        __sprintf_chk(pbVar9,1,0x400,0x259e7c,key,value);
        uVar6 = 0xffffffff;
        pbVar8 = pbVar9;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar2 = *pbVar8;
          pbVar8 = pbVar8 + (uint)bVar3 * -2 + 1;
        } while (bVar2 != 0);
        uVar7 = 0xffffffff;
        pcVar4 = s;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + (uint)bVar3 * -2 + 1;
        } while (cVar1 != '\0');
        if ((int)((~uVar6 - 2) + ~uVar7) < maxsize) {
LAB_001ce606:
          uVar6 = 0xffffffff;
          pcVar4 = s;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + (uint)bVar3 * -2 + 1;
          } while (cVar1 != '\0');
          pbVar8 = (byte *)(s + (~uVar6 - 1));
          while (*pbVar9 != 0) {
            bVar3 = *pbVar9 & 0x7f;
            pbVar9 = pbVar9 + 1;
            if (0xd < bVar3) {
              *pbVar8 = bVar3;
              pbVar8 = pbVar8 + 1;
            }
          }
          *pbVar8 = 0;
        }
        else if ((*key == '*') || (iVar5 = strcasecmp(key,"tracker"), iVar5 == 0)) {
          do {
                    /* Unresolved local var: char * largekey@[???] */
            pcVar4 = Info_FindLargestKey(s,maxsize);
            Info_RemoveKey(s,pcVar4);
            uVar6 = 0xffffffff;
            pbVar8 = pbVar9;
            do {
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              bVar2 = *pbVar8;
              pbVar8 = pbVar8 + (uint)bVar3 * -2 + 1;
            } while (bVar2 != 0);
            uVar7 = 0xffffffff;
            pcVar10 = s;
            do {
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              cVar1 = *pcVar10;
              pcVar10 = pcVar10 + (uint)bVar3 * -2 + 1;
            } while (cVar1 != '\0');
            if ((int)((~uVar6 - 2) + ~uVar7) < maxsize) {
              if (*pcVar4 != '\0') goto LAB_001ce606;
              break;
            }
          } while (*pcVar4 != '\0');
        }
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Info_ValueForKey  @ 000c39c0
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
LAB_000c3ab0:
        pacVar3 = (char (*) [128])&DAT_0027abd7;
LAB_000c3ab5:
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
        if (cVar1 == '\0') goto LAB_000c3ab0;
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
      goto LAB_000c3ab5;
    }
    if (*pcVar4 == '\0') goto LAB_000c3ab0;
    s = pcVar4 + 1;
    cVar1 = pcVar4[1];
  } while( true );
}


// Info_ValueForKey  @ 001cdec0
char * Info_ValueForKey(char *s,char *key)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char * o@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = *s;
  Info_ValueForKey::valueindex = (Info_ValueForKey::valueindex + 1) % 4;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
                    /* Unresolved local var: int nCount@[???] */
  pcVar3 = Info_ValueForKey::value[Info_ValueForKey::valueindex];
  do {
    if (cVar1 == '\\') {
      pcVar4 = local_220;
    }
    else {
      if (cVar1 == '\0') {
LAB_001cdfb0:
        pcVar3 = "";
LAB_001cdfb5:
        if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return pcVar3;
      }
      pcVar6 = local_220;
      while( true ) {
        pcVar4 = pcVar6 + 1;
        s = s + 1;
        *pcVar6 = cVar1;
        cVar1 = *s;
        if ((cVar1 == '\\') || (pcVar4 == local_220 + 0x1ff)) break;
        pcVar6 = pcVar4;
        if (cVar1 == '\0') goto LAB_001cdfb0;
      }
    }
    cVar1 = s[1];
    pcVar6 = s + 1;
    *pcVar4 = '\0';
    pcVar4 = pcVar3;
    if ((cVar1 != '\\') && (cVar1 != '\0')) {
      pcVar5 = pcVar3;
      do {
        pcVar4 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
        *pcVar5 = cVar1;
        cVar1 = *pcVar6;
        if ((cVar1 == '\\') || (cVar1 == '\0')) break;
        pcVar5 = pcVar4;
      } while (pcVar6 != s + 0x200);
    }
    *pcVar4 = '\0';
    iVar2 = strcasecmp(key,local_220);
    if (iVar2 == 0) goto LAB_001cdfb5;
    if (*pcVar6 == '\0') goto LAB_001cdfb0;
    s = pcVar6 + 1;
    cVar1 = pcVar6[1];
  } while( true );
}


// Info_WriteVars  @ 000b7290
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
LAB_000b7358:
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
        if (cVar2 == '\0') goto LAB_000b7358;
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
    if (*pcVar4 == '\0') goto LAB_000b7358;
    pcVar6 = pcVar4 + 1;
    cVar2 = pcVar4[1];
  } while( true );
}


