// Q_FileNameCmp  @ 00049750
undefined4 Q_FileNameCmp(char *param_1,char *param_2)

{
  char cVar1;
  char local_6;
  
  do {
    cVar1 = *param_1;
    if (((cVar1 != '/') || (local_6 = *param_2, local_6 != '\\')) &&
       ((local_6 = *param_2, local_6 != '/' || (cVar1 != '\\')))) {
      if (*(int *)(__ctype_tolower + *param_1 * 4) != *(int *)(__ctype_tolower + *param_2 * 4)) {
        return 0xffffffff;
      }
      if (cVar1 == '\0') {
        return 0;
      }
    }
    param_1 = param_1 + 1;
    if (cVar1 == '\0') {
      return 0;
    }
    param_2 = param_2 + 1;
  } while (local_6 != '\0');
  return 0;
}


// Q_atof  @ 000495a0
longdouble Q_atof(char *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_c;
  
  cVar5 = *param_1;
  if (cVar5 == '-') {
    param_1 = param_1 + 1;
    local_c = -1;
    cVar5 = *param_1;
  }
  else {
    local_c = 1;
  }
  fVar1 = 0.0;
  if ((cVar5 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    param_1 = param_1 + 2;
    do {
      while( true ) {
        iVar6 = (int)*param_1;
        param_1 = param_1 + 1;
        if (9 < iVar6 - 0x30U) break;
        fVar1 = (fVar1 * 16.0 + (float)iVar6) - 48.0;
      }
      if (iVar6 - 0x61U < 6) {
        fVar1 = fVar1 * 16.0 + (float)iVar6;
        fVar2 = 97.0;
      }
      else {
        if (5 < iVar6 - 0x41U) goto LAB_00049705;
        fVar1 = fVar1 * 16.0 + (float)iVar6;
        fVar2 = 65.0;
      }
      fVar1 = (fVar1 - fVar2) + 10.0;
    } while( true );
  }
  if (cVar5 == '\'') {
    return (longdouble)(param_1[1] * local_c);
  }
  iVar4 = 0;
  iVar6 = -1;
  while( true ) {
    do {
      iVar8 = iVar6;
      iVar7 = (int)*param_1;
      param_1 = param_1 + 1;
      iVar6 = iVar4;
    } while (iVar7 == 0x2e);
    if (9 < iVar7 - 0x30U) break;
    iVar4 = iVar4 + 1;
    fVar1 = (fVar1 * 10.0 + (float)iVar7) - 48.0;
    iVar6 = iVar8;
  }
  if ((iVar8 != -1) && (iVar8 < iVar4)) {
    uVar3 = iVar8 - iVar4 & 3;
    if (uVar3 != 0) {
      if (uVar3 < 3) {
        if (uVar3 < 2) {
          fVar1 = fVar1 * 0.1;
          iVar4 = iVar4 + -1;
        }
        fVar1 = fVar1 * 0.1;
        iVar4 = iVar4 + -1;
      }
      fVar1 = fVar1 * 0.1;
      iVar4 = iVar4 + -1;
      if (iVar4 <= iVar8) goto LAB_00049705;
    }
    do {
      fVar1 = fVar1 * 0.1 * 0.1 * 0.1 * 0.1;
      iVar4 = iVar4 + -4;
    } while (iVar8 < iVar4);
  }
LAB_00049705:
  return (longdouble)(fVar1 * (float)local_c);
}


// Q_atoi  @ 000494f0
int Q_atoi(char *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  cVar2 = *param_1;
  if (cVar2 == '-') {
    param_1 = param_1 + 1;
    iVar4 = -1;
    cVar2 = *param_1;
  }
  else {
    iVar4 = 1;
  }
  iVar1 = 0;
  if ((cVar2 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    param_1 = param_1 + 2;
    while( true ) {
      while( true ) {
        while( true ) {
          iVar3 = (int)*param_1;
          param_1 = param_1 + 1;
          if (9 < iVar3 - 0x30U) break;
          iVar1 = iVar3 + -0x30 + iVar1 * 0x10;
        }
        if (5 < iVar3 - 0x61U) break;
        iVar1 = iVar3 + -0x57 + iVar1 * 0x10;
      }
      if (5 < iVar3 - 0x41U) break;
      iVar1 = iVar3 + -0x37 + iVar1 * 0x10;
    }
  }
  else if (cVar2 == '\'') {
    iVar1 = (int)param_1[1];
  }
  else {
    while( true ) {
      cVar2 = *param_1;
      param_1 = param_1 + 1;
      if (9 < (int)cVar2 - 0x30U) break;
      iVar1 = cVar2 + -0x30 + iVar1 * 10;
    }
  }
  return iVar1 * iVar4;
}


// Q_log2  @ 00061d1c
void Q_log2(int param_1)

{
  do {
    param_1 = param_1 >> 1;
  } while (param_1 != 0);
  return;
}


// Q_memcmp  @ 000491e8
undefined4 Q_memcmp(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_3 == 0) {
LAB_00049260:
    uVar2 = 0;
  }
  else {
    uVar1 = -param_3 & 3;
    if (uVar1 == 0) goto LAB_0004922c;
    if (((2 < uVar1) ||
        (((1 < uVar1 ||
          (param_3 = param_3 + -1, *(char *)(param_3 + param_1) == *(char *)(param_3 + param_2))) &&
         (param_3 = param_3 + -1, *(char *)(param_3 + param_1) == *(char *)(param_3 + param_2)))))
       && (param_3 = param_3 + -1, *(char *)(param_3 + param_1) == *(char *)(param_3 + param_2))) {
      do {
        if (param_3 == 0) goto LAB_00049260;
LAB_0004922c:
      } while (((*(char *)(param_1 + -1 + param_3) == *(char *)(param_2 + -1 + param_3)) &&
               (*(char *)(param_1 + -2 + param_3) == *(char *)(param_2 + -2 + param_3))) &&
              ((*(char *)(param_1 + -3 + param_3) == *(char *)(param_2 + -3 + param_3) &&
               (param_3 = param_3 + -4, *(char *)(param_3 + param_1) == *(char *)(param_3 + param_2)
               ))));
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// Q_memcpy  @ 000490c8
void Q_memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((((uint)param_1 | (uint)param_2 | param_3) & 3) == 0) {
    param_3 = (int)param_3 >> 2;
    iVar3 = 0;
    if (0 < (int)param_3) {
      uVar2 = param_3 & 3;
      if (uVar2 != 0) {
        if (1 < uVar2) {
          if (2 < uVar2) {
            *param_1 = *param_2;
            param_1 = param_1 + 1;
            param_2 = param_2 + 1;
          }
          *param_1 = *param_2;
          param_1 = param_1 + 1;
          param_2 = param_2 + 1;
          iVar3 = (2 < uVar2) + 1;
        }
        *param_1 = *param_2;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + 1;
        if ((int)param_3 <= iVar3) {
          return;
        }
      }
      do {
        *param_1 = *param_2;
        param_1[1] = param_2[1];
        param_1[2] = param_2[2];
        param_1[3] = param_2[3];
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        iVar3 = iVar3 + 4;
      } while (iVar3 < (int)param_3);
    }
  }
  else {
    iVar3 = 0;
    if (0 < (int)param_3) {
      uVar2 = param_3 & 3;
      if (uVar2 != 0) {
        if (1 < uVar2) {
          if (2 < uVar2) {
            *(undefined1 *)param_1 = *(undefined1 *)param_2;
          }
          uVar2 = (uint)(2 < uVar2);
          *(undefined1 *)(uVar2 + (int)param_1) = *(undefined1 *)(uVar2 + (int)param_2);
          iVar3 = uVar2 + 1;
        }
        *(undefined1 *)(iVar3 + (int)param_1) = *(undefined1 *)(iVar3 + (int)param_2);
        iVar3 = iVar3 + 1;
        if ((int)param_3 <= iVar3) {
          return;
        }
      }
      do {
        *(undefined1 *)(iVar3 + (int)param_1) = *(undefined1 *)(iVar3 + (int)param_2);
        *(undefined1 *)(iVar3 + 1 + (int)param_1) = *(undefined1 *)(iVar3 + 1 + (int)param_2);
        *(undefined1 *)(iVar3 + 2 + (int)param_1) = *(undefined1 *)(iVar3 + 2 + (int)param_2);
        iVar1 = iVar3 + 3;
        iVar3 = iVar3 + 4;
        *(undefined1 *)(iVar1 + (int)param_1) = *(undefined1 *)(iVar1 + (int)param_2);
      } while (iVar3 < (int)param_3);
    }
  }
  return;
}


// Q_memset  @ 00048ff8
void Q_memset(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  
  if ((((uint)param_1 | param_3) & 3) == 0) {
    param_3 = (int)param_3 >> 2;
    uVar4 = param_2 << 0x18 | param_2 << 8 | param_2 | param_2 << 0x10;
    iVar2 = 0;
    if (0 < (int)param_3) {
      uVar1 = param_3 & 3;
      if (uVar1 != 0) {
        if (1 < uVar1) {
          if (2 < uVar1) {
            *param_1 = uVar4;
            param_1 = param_1 + 1;
          }
          *param_1 = uVar4;
          param_1 = param_1 + 1;
          iVar2 = (2 < uVar1) + 1;
        }
        *param_1 = uVar4;
        param_1 = param_1 + 1;
        iVar2 = iVar2 + 1;
        if ((int)param_3 <= iVar2) {
          return;
        }
      }
      do {
        *param_1 = uVar4;
        param_1[1] = uVar4;
        param_1[2] = uVar4;
        param_1[3] = uVar4;
        param_1 = param_1 + 4;
        iVar2 = iVar2 + 4;
      } while (iVar2 < (int)param_3);
    }
  }
  else {
    iVar2 = 0;
    if (0 < (int)param_3) {
      uVar4 = param_3 & 3;
      uVar3 = (undefined1)param_2;
      if (uVar4 != 0) {
        if (1 < uVar4) {
          if (2 < uVar4) {
            *(undefined1 *)param_1 = uVar3;
          }
          *(undefined1 *)((uint)(2 < uVar4) + (int)param_1) = uVar3;
          iVar2 = (2 < uVar4) + 1;
        }
        *(undefined1 *)(iVar2 + (int)param_1) = uVar3;
        iVar2 = iVar2 + 1;
        if ((int)param_3 <= iVar2) {
          return;
        }
      }
      do {
        *(undefined1 *)(iVar2 + (int)param_1) = uVar3;
        *(undefined1 *)((int)param_1 + iVar2 + 1) = uVar3;
        *(undefined1 *)((int)param_1 + iVar2 + 2) = uVar3;
        *(undefined1 *)((int)param_1 + iVar2 + 3) = uVar3;
        iVar2 = iVar2 + 4;
      } while (iVar2 < (int)param_3);
    }
  }
  return;
}


// Q_strcasecmp  @ 00049478
void Q_strcasecmp(undefined4 param_1,undefined4 param_2)

{
  Q_strncasecmp(param_1,param_2,99999);
  return;
}


// Q_strcat  @ 0004938c
void Q_strcat(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Q_strlen(param_1);
  Q_strcpy(param_1 + iVar1,param_2);
  return;
}


// Q_strcmp  @ 000493c0
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


// Q_strcpy  @ 0004926c
void Q_strcpy(char *param_1,char *param_2)

{
  for (; *param_2 != '\0'; param_2 = param_2 + 1) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
  }
  *param_1 = '\0';
  return;
}


// Q_stricmp  @ 000494a4
void Q_stricmp(undefined4 param_1,undefined4 param_2)

{
  Q_strcasecmp(param_1,param_2);
  return;
}


// Q_strlen  @ 000492bc
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


// Q_strlwr  @ 00049718
char * Q_strlwr(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    *param_1 = *(char *)(__ctype_tolower + *param_1 * 4);
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return param_1;
}


// Q_strncasecmp  @ 00049424
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


// Q_strncmp  @ 000493ec
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


// Q_strncpy  @ 0004928c
void Q_strncpy(char *param_1,char *param_2,int param_3)

{
  bool bVar1;
  
  while ((*param_2 != '\0' && (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1))) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  if (param_3 != 0) {
    *param_1 = '\0';
  }
  return;
}


// Q_strnicmp  @ 000494c8
void Q_strnicmp(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Q_strncasecmp(param_1,param_2,param_3);
  return;
}


// Q_strrchr  @ 000492d8
char * Q_strrchr(int param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  bool bVar5;
  
  iVar1 = Q_strlen(param_1);
  pcVar4 = (char *)(param_1 + iVar1);
  uVar3 = iVar1 - 1;
  if (iVar1 != 0) {
    uVar2 = ~uVar3 & 3;
    if (uVar2 != 0) {
      if (uVar2 < 3) {
        if (uVar2 < 2) {
          pcVar4 = pcVar4 + -1;
          if (*pcVar4 == param_2) {
            return pcVar4;
          }
          uVar3 = iVar1 - 2;
        }
        pcVar4 = pcVar4 + -1;
        if (*pcVar4 == param_2) {
          return pcVar4;
        }
        uVar3 = uVar3 - 1;
      }
      pcVar4 = pcVar4 + -1;
      if (*pcVar4 == param_2) {
        return pcVar4;
      }
      bVar5 = uVar3 == 0;
      uVar3 = uVar3 - 1;
      if (bVar5) {
        return (char *)0x0;
      }
    }
    do {
      if (pcVar4[-1] == param_2) {
        return pcVar4 + -1;
      }
      if (pcVar4[-2] == param_2) {
        return pcVar4 + -2;
      }
      if (pcVar4[-3] == param_2) {
        return pcVar4 + -3;
      }
      pcVar4 = pcVar4 + -4;
      if (*pcVar4 == param_2) {
        return pcVar4;
      }
      uVar3 = uVar3 - 4;
    } while (uVar3 != 0xffffffff);
  }
  return (char *)0x0;
}


// Q_strstr  @ 000497d4
void Q_strstr(char *param_1,char *param_2)

{
  strstr(param_1,param_2);
  return;
}


