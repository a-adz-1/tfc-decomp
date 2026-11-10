// Q_FileNameCmp  @ 0804e1b0
undefined4 Q_FileNameCmp(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  do {
    if ((*param_1 != '/') || (*param_2 != '\\')) {
      iVar2 = tolower((int)*param_1);
      iVar3 = tolower((int)*param_2);
      if (iVar2 != iVar3) {
        return 0xffffffff;
      }
      if (*param_1 == '\0') {
        return 0;
      }
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 == '\0') {
      return 0;
    }
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return 0;
}


// Q_atof  @ 0804e010
longdouble Q_atof(char *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*param_1 == '-') {
    iVar6 = -1;
    param_1 = param_1 + 1;
  }
  else {
    iVar6 = 1;
  }
  fVar1 = 0.0;
  if ((*param_1 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    param_1 = param_1 + 2;
    while( true ) {
      while( true ) {
        while( true ) {
          iVar3 = (int)*param_1;
          param_1 = param_1 + 1;
          if (9 < iVar3 - 0x30U) break;
          fVar1 = (fVar1 * 16.0 + (float)iVar3) - 48.0;
        }
        if (5 < iVar3 - 0x61U) break;
        fVar1 = ((fVar1 * 16.0 + (float)iVar3) - 97.0) + 10.0;
      }
      if (5 < iVar3 - 0x41U) break;
      fVar1 = ((fVar1 * 16.0 + (float)iVar3) - 65.0) + 10.0;
    }
  }
  else {
    if (*param_1 == '\'') {
      return (longdouble)(param_1[1] * iVar6);
    }
    iVar3 = 0;
    iVar2 = -1;
    while( true ) {
      do {
        iVar5 = iVar2;
        iVar4 = (int)*param_1;
        param_1 = param_1 + 1;
        iVar2 = iVar3;
      } while (iVar4 == 0x2e);
      if (9 < iVar4 - 0x30U) break;
      fVar1 = (fVar1 * 10.0 + (float)iVar4) - 48.0;
      iVar3 = iVar3 + 1;
      iVar2 = iVar5;
    }
    if (iVar5 != -1) {
      for (; iVar5 < iVar3; iVar3 = iVar3 + -1) {
        fVar1 = fVar1 / 10.0;
      }
    }
  }
  return (longdouble)(fVar1 * (float)iVar6);
}


// Q_atoi  @ 0804df30
int Q_atoi(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 == '-') {
    iVar4 = -1;
    param_1 = param_1 + 1;
  }
  else {
    iVar4 = 1;
  }
  iVar2 = 0;
  if ((*param_1 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    param_1 = param_1 + 2;
    while( true ) {
      while( true ) {
        while( true ) {
          iVar3 = (int)*param_1;
          param_1 = param_1 + 1;
          if (9 < iVar3 - 0x30U) break;
          iVar2 = iVar3 + -0x30 + iVar2 * 0x10;
        }
        if (5 < iVar3 - 0x61U) break;
        iVar2 = iVar3 + -0x57 + iVar2 * 0x10;
      }
      if (5 < iVar3 - 0x41U) break;
      iVar2 = iVar3 + -0x37 + iVar2 * 0x10;
    }
  }
  else if (*param_1 == '\'') {
    iVar2 = (int)param_1[1];
  }
  else {
    while( true ) {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      if (9 < (int)cVar1 - 0x30U) break;
      iVar2 = cVar1 + -0x30 + iVar2 * 10;
    }
  }
  return iVar2 * iVar4;
}


// Q_log2  @ 08062080
void Q_log2(int param_1)

{
  do {
    param_1 = param_1 >> 1;
  } while (param_1 != 0);
  return;
}


// Q_memcmp  @ 0804dce0
undefined4 Q_memcmp(int param_1,int param_2,int param_3)

{
  do {
    if (param_3 == 0) {
      return 0;
    }
    param_3 = param_3 + -1;
  } while (*(char *)(param_3 + param_1) == *(char *)(param_3 + param_2));
  return 0xffffffff;
}


// Q_memcpy  @ 0804dc80
void Q_memcpy(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (((param_1 | param_2 | param_3) & 3) == 0) {
    iVar1 = 0;
    if (0 < (int)param_3 >> 2) {
      do {
        *(undefined4 *)(param_1 + iVar1 * 4) = *(undefined4 *)(param_2 + iVar1 * 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)param_3 >> 2);
    }
  }
  else {
    iVar1 = 0;
    if (0 < (int)param_3) {
      do {
        *(undefined1 *)(iVar1 + param_1) = *(undefined1 *)(iVar1 + param_2);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)param_3);
    }
  }
  return;
}


// Q_memset  @ 0804dc10
void Q_memset(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (((param_1 | param_3) & 3) == 0) {
    iVar1 = 0;
    if (0 < (int)param_3 >> 2) {
      do {
        *(uint *)(param_1 + iVar1 * 4) = param_2 << 8 | param_2 | param_2 << 0x10 | param_2 << 0x18;
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)param_3 >> 2);
    }
  }
  else {
    iVar1 = 0;
    if (0 < (int)param_3) {
      do {
        *(char *)(iVar1 + param_1) = (char)param_2;
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)param_3);
    }
  }
  return;
}


// Q_strcasecmp  @ 0804df10
void Q_strcasecmp(undefined4 param_1,undefined4 param_2)

{
  Q_strncasecmp(param_1,param_2,99999);
  return;
}


// Q_strcat  @ 0804ddf0
void Q_strcat(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Q_strlen(param_1);
  Q_strcpy(param_1 + iVar1,param_2);
  return;
}


// Q_strcmp  @ 0804de20
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


// Q_strcpy  @ 0804dd20
void Q_strcpy(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_2;
  while (cVar1 != '\0') {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    cVar1 = *param_2;
  }
  *param_1 = '\0';
  return;
}


// Q_strlen  @ 0804dd90
void Q_strlen(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = iVar2 + 1;
    cVar1 = param_1[iVar2];
  }
  return;
}


// Q_strlwr  @ 0804e180
char * Q_strlwr(char *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = tolower((int)*param_1);
    *param_1 = (char)iVar2;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return param_1;
}


// Q_strncasecmp  @ 0804deb0
undefined4 Q_strncasecmp(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  do {
    iVar1 = (int)*param_1;
    param_1 = param_1 + 1;
    iVar2 = (int)*param_2;
    param_2 = param_2 + 1;
    bVar3 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar3) {
      return 0;
    }
    if (iVar1 != iVar2) {
      if (iVar1 - 0x61U < 0x1a) {
        iVar1 = iVar1 + -0x20;
      }
      if (iVar2 - 0x61U < 0x1a) {
        iVar2 = iVar2 + -0x20;
      }
      if (iVar1 != iVar2) {
        return 0xffffffff;
      }
    }
    if (iVar1 == 0) {
      return 0;
    }
  } while( true );
}


// Q_strncmp  @ 0804de60
undefined4 Q_strncmp(char *param_1,char *param_2,int param_3)

{
  bool bVar1;
  
  while( true ) {
    bVar1 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar1) {
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


// Q_strncpy  @ 0804dd50
void Q_strncpy(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = *param_2;
  while ((cVar1 != '\0' && (bVar2 = param_3 != 0, param_3 = param_3 + -1, bVar2))) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    cVar1 = *param_2;
  }
  if (param_3 != 0) {
    *param_1 = '\0';
  }
  return;
}


// Q_strrchr  @ 0804ddb0
char * Q_strrchr(int param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = Q_strlen(param_1);
  pcVar2 = (char *)(param_1 + iVar1);
  do {
    if (iVar1 == 0) {
      return (char *)0x0;
    }
    iVar1 = iVar1 + -1;
    pcVar2 = pcVar2 + -1;
  } while (*pcVar2 != param_2);
  return pcVar2;
}


