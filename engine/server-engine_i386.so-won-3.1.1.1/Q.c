// Q_FileNameCmp  @ 00056d20
undefined4 Q_FileNameCmp(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    if (((*param_1 != '/') || (*param_2 != '\\')) && ((*param_2 != '/' || (*param_1 != '\\')))) {
      if (*(int *)(__ctype_tolower + *param_1 * 4) != *(int *)(__ctype_tolower + *param_2 * 4)) {
        return 0xffffffff;
      }
      if (*param_1 == '\0') {
        return 0;
      }
    }
    if ((*param_1 == '\0') ||
       (cVar1 = *param_2, param_1 = param_1 + 1, param_2 = param_2 + 1, cVar1 == '\0')) {
      return 0;
    }
  } while( true );
}


// Q_atof  @ 00056ac4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble Q_atof(char *param_1)

{
  int iVar1;
  longdouble lVar2;
  int local_1c;
  int local_18;
  int local_10;
  double local_c;
  
  if (*param_1 == '-') {
    local_10 = -1;
    param_1 = param_1 + 1;
  }
  else {
    local_10 = 1;
  }
  local_c = 0.0;
  if ((*param_1 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    param_1 = param_1 + 2;
    while( true ) {
      while( true ) {
        while( true ) {
          iVar1 = (int)*param_1;
          param_1 = param_1 + 1;
          if ((iVar1 < 0x30) || (0x39 < iVar1)) break;
          local_c = ((double)iVar1 + local_c * 16.0) - 48.0;
        }
        if ((iVar1 < 0x61) || (0x66 < iVar1)) break;
        local_c = (((double)iVar1 + local_c * 16.0) - 97.0) + 10.0;
      }
      if ((iVar1 < 0x41) || (0x46 < iVar1)) break;
      local_c = (((double)iVar1 + local_c * 16.0) - _FUN_000dfd80) + 10.0;
    }
    lVar2 = (longdouble)((float)local_10 * (float)local_c);
  }
  else if (*param_1 == '\'') {
    lVar2 = (longdouble)(param_1[1] * local_10);
  }
  else {
    local_18 = -1;
    local_1c = 0;
    while( true ) {
      while( true ) {
        iVar1 = (int)*param_1;
        param_1 = param_1 + 1;
        if (iVar1 != 0x2e) break;
        local_18 = local_1c;
      }
      if ((iVar1 < 0x30) || (0x39 < iVar1)) break;
      local_c = ((double)iVar1 + local_c * 10.0) - 48.0;
      local_1c = local_1c + 1;
    }
    if (local_18 == -1) {
      lVar2 = (longdouble)((float)local_10 * (float)local_c);
    }
    else {
      for (; local_18 < local_1c; local_1c = local_1c + -1) {
        local_c = local_c / 10.0;
      }
      lVar2 = (longdouble)((float)local_10 * (float)local_c);
    }
  }
  return lVar2;
}


// Q_atoi  @ 00056980
int Q_atoi(char *param_1)

{
  int iVar1;
  int local_c;
  int local_8;
  
  if (*param_1 == '-') {
    local_c = -1;
    param_1 = param_1 + 1;
  }
  else {
    local_c = 1;
  }
  local_8 = 0;
  if ((*param_1 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    param_1 = param_1 + 2;
    while( true ) {
      while( true ) {
        while( true ) {
          iVar1 = (int)*param_1;
          param_1 = param_1 + 1;
          if ((iVar1 < 0x30) || (0x39 < iVar1)) break;
          local_8 = local_8 * 0x10 + iVar1 + -0x30;
        }
        if ((iVar1 < 0x61) || (0x66 < iVar1)) break;
        local_8 = local_8 * 0x10 + iVar1 + -0x57;
      }
      if ((iVar1 < 0x41) || (0x46 < iVar1)) break;
      local_8 = local_8 * 0x10 + iVar1 + -0x37;
    }
    local_c = local_8 * local_c;
  }
  else if (*param_1 == '\'') {
    local_c = param_1[1] * local_c;
  }
  else {
    while( true ) {
      iVar1 = (int)*param_1;
      param_1 = param_1 + 1;
      if ((iVar1 < 0x30) || (0x39 < iVar1)) break;
      local_8 = local_8 * 10 + iVar1 + -0x30;
    }
    local_c = local_8 * local_c;
  }
  return local_c;
}


// Q_log2  @ 00079cb4
int Q_log2(int param_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  while (param_1 = param_1 >> 1, param_1 != 0) {
    local_8 = local_8 + 1;
  }
  return local_8;
}


// Q_memcmp  @ 0005668c
undefined4 Q_memcmp(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// Q_memcpy  @ 00056658
void Q_memcpy(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


// Q_memset  @ 00056624
void Q_memset(void *param_1,int param_2,size_t param_3)

{
  memset(param_1,param_2,param_3);
  return;
}


// Q_ntohs  @ 000c2dd0
uint16_t Q_ntohs(uint16_t param_1)

{
  uint16_t uVar1;
  
  uVar1 = ntohs(param_1);
  return uVar1;
}


// Q_strcasecmp  @ 000568d8
undefined4 Q_strcasecmp(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = Q_strncasecmp(param_1,param_2,99999,0x568e4);
  return uVar1;
}


// Q_strcat  @ 000567d4
void Q_strcat(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Q_strlen(param_1);
  Q_strcpy(param_1 + iVar1,param_2);
  return;
}


// Q_strcmp  @ 00056818
undefined4 Q_strcmp(char *param_1,char *param_2)

{
  while( true ) {
    if (*param_1 != *param_2) {
      return 0xffffffff;
    }
    if (*param_1 == '\0') break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return 0;
}


// Q_strcpy  @ 000566d4
void Q_strcpy(char *param_1,char *param_2)

{
  for (; *param_2 != '\0'; param_2 = param_2 + 1) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
  }
  *param_1 = '\0';
  return;
}


// Q_stricmp  @ 00056914
undefined4 Q_stricmp(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = Q_strcasecmp(param_1,param_2);
  return uVar1;
}


// Q_strlen  @ 0005673c
int Q_strlen(int param_1)

{
  undefined4 local_8;
  
  for (local_8 = 0; *(char *)(param_1 + local_8) != '\0'; local_8 = local_8 + 1) {
  }
  return local_8;
}


// Q_strlwr  @ 00056cc0
char * Q_strlwr(char *param_1)

{
  char *local_8;
  
  for (local_8 = param_1; *local_8 != '\0'; local_8 = local_8 + 1) {
    *local_8 = *(char *)(__ctype_tolower + *local_8 * 4);
  }
  return local_8;
}


// Q_strncasecmp  @ 000568a0
int Q_strncasecmp(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = strncasecmp(param_1,param_2,param_3);
  return iVar1;
}


// Q_strncmp  @ 00056854
undefined4 Q_strncmp(char *param_1,char *param_2,int param_3)

{
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 == -1) {
      return 0;
    }
    if (*param_1 != *param_2) break;
    if (*param_1 == '\0') {
      return 0;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return 0xffffffff;
}


// Q_strncpy  @ 00056708
void Q_strncpy(char *param_1,char *param_2,size_t param_3)

{
  strncpy(param_1,param_2,param_3);
  return;
}


// Q_strnicmp  @ 00056948
undefined4 Q_strnicmp(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = Q_strncasecmp(param_1,param_2,param_3,0x56954);
  return uVar1;
}


// Q_strrchr  @ 00056770
char * Q_strrchr(char *param_1,char param_2)

{
  int local_c;
  
  local_c = Q_strlen(param_1);
  param_1 = (char *)((int)param_1 + local_c);
  do {
    local_c = local_c + -1;
    if (local_c == -1) {
      return (char *)0x0;
    }
    param_1 = param_1 + -1;
  } while (*param_1 != param_2);
  return param_1;
}


// Q_strstr  @ 00056dd8
char * Q_strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  
  pcVar1 = strstr(param_1,param_2);
  return pcVar1;
}


// Q_strtoull  @ 00056e0c
undefined8 Q_strtoull(char *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  bVar3 = false;
  for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
  }
  if (*param_1 == '+') {
    bVar3 = false;
    param_1 = param_1 + 1;
  }
  else if (*param_1 == '-') {
    bVar3 = true;
    param_1 = param_1 + 1;
  }
  for (; ('/' < *param_1 && (*param_1 < ':')); param_1 = param_1 + 1) {
    uVar4 = ((local_8 << 2 | local_c >> 0x1e) + local_8 + (uint)CARRY4(local_c * 4,local_c)) * 2 |
            local_c * 5 >> 0x1f;
    local_c = local_c * 10;
    if (bVar3) {
      uVar2 = (int)*param_1 - 0x30;
      uVar1 = -uVar2;
      local_8 = (uVar4 - ((int)uVar2 >> 0x1f)) - (uint)(local_c < uVar2);
    }
    else {
      uVar1 = (int)*param_1 - 0x30;
      local_8 = uVar4 + ((int)uVar1 >> 0x1f) + (uint)CARRY4(local_c,uVar1);
    }
    local_c = local_c + uVar1;
  }
  return CONCAT44(local_8,local_c);
}


