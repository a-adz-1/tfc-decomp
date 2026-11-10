// Host_Say__FP7edict_si  @ 00087d48
void Host_Say__FP7edict_si(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  char *pcVar11;
  char *local_198;
  char *local_190;
  char local_180 [256];
  char local_80 [128];
  
  pcVar2 = (char *)(*DAT_001a7f8c)(0);
  iVar3 = (*DAT_001a7f90)();
  if (iVar3 == 0) {
    return;
  }
  iVar3 = strcasecmp(pcVar2,"say");
  if ((iVar3 == 0) || (iVar3 = strcasecmp(pcVar2,"say_team"), iVar3 == 0)) {
    iVar3 = (*DAT_001a7f90)();
    if (iVar3 < 2) {
      return;
    }
    pcVar2 = (char *)(*DAT_001a7f88)();
  }
  else {
    iVar3 = (*DAT_001a7f90)();
    if (iVar3 < 2) {
      sprintf(local_180,"%s",pcVar2);
    }
    else {
      uVar7 = (*DAT_001a7f88)();
      sprintf(local_180,"%s %s",pcVar2,uVar7);
    }
    pcVar2 = local_180;
  }
  iVar3 = FailedSpamCheck__FP7edict_si(param_1,param_2);
  if (iVar3 != 0) {
    return;
  }
  iVar3 = param_1;
  if ((param_1 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = *(int **)(iVar3 + 0x7c);
  }
  local_190 = pcVar2;
  if (*pcVar2 == '\"') {
    local_190 = pcVar2 + 1;
    uVar8 = 0xffffffff;
    pcVar11 = local_190;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    pcVar2[~uVar8 - 1] = '\0';
  }
  if (local_190 == (char *)0x0) goto LAB_0008802e;
  uVar8 = -(int)local_190 & 3;
  pcVar2 = local_190;
  if (uVar8 == 0) {
LAB_00087f80:
    do {
      pcVar11 = pcVar2;
      if (*pcVar2 == '\0') break;
      iVar3 = isprint((int)*pcVar2);
      if ((iVar3 != 0) && (iVar3 = isspace((int)*pcVar2), iVar3 == 0)) goto LAB_0008802e;
      pcVar11 = pcVar2 + 1;
      if (*pcVar11 == '\0') break;
      iVar3 = isprint((int)*pcVar11);
      if ((iVar3 != 0) && (iVar3 = isspace((int)*pcVar11), iVar3 == 0)) goto LAB_0008802e;
      pcVar11 = pcVar2 + 2;
      if (*pcVar11 == '\0') break;
      iVar3 = isprint((int)*pcVar11);
      if ((iVar3 != 0) && (iVar3 = isspace((int)*pcVar11), iVar3 == 0)) goto LAB_0008802e;
      pcVar11 = pcVar2 + 3;
      if (*pcVar11 == '\0') break;
      iVar3 = isprint((int)*pcVar11);
      if ((iVar3 != 0) && (iVar3 = isspace((int)*pcVar11), iVar3 == 0)) goto LAB_0008802e;
      pcVar2 = pcVar2 + 4;
      pcVar11 = pcVar2;
    } while (pcVar2 != (char *)0x0);
  }
  else {
    pcVar11 = local_190;
    if (uVar8 < 2) {
LAB_00087f4c:
      if (*pcVar11 != '\0') {
        iVar3 = isprint((int)*pcVar11);
        if (((iVar3 != 0) && (iVar3 = isspace((int)*pcVar11), iVar3 == 0)) ||
           (pcVar2 = pcVar11 + 1, pcVar2 == (char *)0x0)) goto LAB_0008802e;
        goto LAB_00087f80;
      }
    }
    else if (uVar8 < 3) {
LAB_00087f1e:
      if (*pcVar11 != '\0') {
        iVar3 = isprint((int)*pcVar11);
        if ((iVar3 != 0) && (iVar3 = isspace((int)*pcVar11), iVar3 == 0)) goto LAB_0008802e;
        pcVar11 = pcVar11 + 1;
        goto LAB_00087f4c;
      }
    }
    else if (*local_190 != '\0') {
      iVar3 = isprint((int)*local_190);
      if ((iVar3 != 0) && (iVar3 = isspace((int)*local_190), iVar3 == 0)) goto LAB_0008802e;
      pcVar11 = local_190 + 1;
      goto LAB_00087f1e;
    }
  }
  if (pcVar11 != (char *)0x0) {
    return;
  }
LAB_0008802e:
  local_198 = local_190;
  if (local_190 != (char *)0x0) {
    pcVar2 = local_190 + 2;
    do {
      if (*local_198 == '\0') break;
      if (*local_198 == '%') {
        uVar8 = 0xffffffff;
        pcVar11 = local_190;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          cVar1 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar1 != '\0');
        if (0x7c < ~uVar8 - 1) break;
        if (pcVar2[-1] == 'h') {
          *local_198 = '\0';
          pcVar11 = (char *)UTIL_VarArgs__FPce(&DAT_0013296e,
                                               (int)ROUND(*(float *)(*piVar10 + 0x160)),pcVar2);
          strcat(local_190,pcVar11);
        }
        if (pcVar2[-1] == 'a') {
          *local_198 = '\0';
          pcVar11 = (char *)UTIL_VarArgs__FPce(&DAT_0013296e,
                                               (int)ROUND(*(float *)(*piVar10 + 0x1bc)),pcVar2);
          strcat(local_190,pcVar11);
        }
        if (pcVar2[-1] == 'i') {
          *local_198 = '\0';
          iVar3 = __opi__7EHANDLE(piVar10 + 0x353);
          if (iVar3 == 0) {
            pcVar11 = (char *)UTIL_VarArgs__FPce(&DAT_0013296b,pcVar2);
            strcat(local_190,pcVar11);
          }
          else {
            piVar4 = (int *)__rf__7EHANDLE(piVar10 + 0x353,pcVar2);
            pcVar11 = (char *)UTIL_VarArgs__FPce(&DAT_00132973,
                                                 *(int *)(*piVar4 + 0x1d0) + gpGlobals[0x26]);
            strcat(local_190,pcVar11);
          }
        }
      }
      pcVar2 = pcVar2 + 1;
      local_198 = local_198 + 1;
    } while (local_198 != (char *)0x0);
  }
  piVar10[0x348] = *gpGlobals;
  if (*(int *)(*piVar10 + 0x244) == 0) {
    if (param_2 == 0) {
      iVar3 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
      pcVar2 = "%c%s: ";
    }
    else {
      iVar3 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
      pcVar2 = "%c(TEAM) %s: ";
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
    pcVar2 = "%c(SPEC) %s: ";
  }
  sprintf(local_80,pcVar2,2,iVar3);
  uVar8 = 0xffffffff;
  pcVar2 = local_80;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar9 = 0xffffffff;
  pcVar2 = local_190;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if ((int)(0x7f - ~uVar8) < (int)(~uVar9 - 1)) {
    local_190[0x7f - ~uVar8] = '\0';
  }
  strcat(local_80,local_190);
  strcat(local_80,"\n");
  iVar3 = 1;
  if (0 < gpGlobals[0x24]) {
    do {
      piVar4 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
      if (((piVar4 != (int *)0x0) && (*(int *)(*piVar4 + 0x208) != param_1)) &&
         ((*(byte *)(*piVar4 + 0x1a4) & 8) != 0)) {
        if (param_2 != 0) {
          iVar6 = *g_pGameRules;
          iVar5 = param_1;
          if ((param_1 == 0) && (iVar5 = (*DAT_001a7f54)(0), iVar5 == 0)) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined4 *)(iVar5 + 0x7c);
          }
          iVar6 = (**(code **)(iVar6 + 0xd0))(g_pGameRules,piVar4,uVar7);
          if (iVar6 != 1) goto LAB_00088481;
        }
        if ((*(int *)(*piVar10 + 0x244) == 0) || (*(int *)(*piVar4 + 0x244) != 0)) {
          (*DAT_001a7ef8)(1,gmsgSayText,0,*(undefined4 *)(*piVar4 + 0x208));
          uVar7 = (*DAT_001a7f5c)(param_1);
          (*DAT_001a7f00)(uVar7);
          (*DAT_001a7f18)(local_80);
          (*DAT_001a7efc)();
        }
      }
LAB_00088481:
      iVar3 = iVar3 + 1;
    } while (iVar3 <= gpGlobals[0x24]);
  }
  (*DAT_001a7ef8)(1,gmsgSayText,0,*(undefined4 *)(param_1 + 0x288));
  uVar7 = (*DAT_001a7f5c)(param_1);
  (*DAT_001a7f00)(uVar7);
  (*DAT_001a7f18)(local_80);
  (*DAT_001a7efc)();
  (*DAT_001a7f84)(local_80);
  if (param_2 == 0) {
    uVar7 = (*DAT_001a8004)(param_1,local_190);
    iVar3 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
    pcVar2 = "\"%s<%i>\" say \"%s\"\n";
  }
  else {
    uVar7 = (*DAT_001a8004)(param_1,local_190);
    iVar3 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
    pcVar2 = "\"%s<%i>\" say_team \"%s\"\n";
  }
  UTIL_LogPrintf__FPce(pcVar2,iVar3,uVar7);
  return;
}


// Host_Tell__FP7edict_s  @ 00088618
void Host_Tell__FP7edict_s(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  size_t __n;
  char local_80 [126];
  undefined1 local_2;
  undefined1 local_1;
  
  iVar2 = (*DAT_001a7f90)();
  if (iVar2 < 3) {
    return;
  }
  iVar2 = FailedSpamCheck__FP7edict_si(param_1,1);
  if (iVar2 != 0) {
    return;
  }
  pcVar3 = (char *)(*DAT_001a7f88)();
  if (pcVar3 == (char *)0x0) goto LAB_000887d6;
  uVar7 = -(int)pcVar3 & 3;
  pcVar10 = pcVar3;
  if (uVar7 == 0) {
LAB_00088728:
    do {
      pcVar9 = pcVar10;
      if (*pcVar10 == '\0') break;
      iVar2 = isprint((int)*pcVar10);
      if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar10), iVar2 == 0)) goto LAB_000887d6;
      pcVar9 = pcVar10 + 1;
      if (*pcVar9 == '\0') break;
      iVar2 = isprint((int)*pcVar9);
      if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_000887d6;
      pcVar9 = pcVar10 + 2;
      if (*pcVar9 == '\0') break;
      iVar2 = isprint((int)*pcVar9);
      if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_000887d6;
      pcVar9 = pcVar10 + 3;
      if (*pcVar9 == '\0') break;
      iVar2 = isprint((int)*pcVar9);
      if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_000887d6;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar10;
    } while (pcVar10 != (char *)0x0);
  }
  else {
    pcVar9 = pcVar3;
    if (uVar7 < 2) {
LAB_000886f3:
      if (*pcVar9 != '\0') {
        iVar2 = isprint((int)*pcVar9);
        if (((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) ||
           (pcVar10 = pcVar9 + 1, pcVar10 == (char *)0x0)) goto LAB_000887d6;
        goto LAB_00088728;
      }
    }
    else if (uVar7 < 3) {
LAB_000886c5:
      if (*pcVar9 != '\0') {
        iVar2 = isprint((int)*pcVar9);
        if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_000887d6;
        pcVar9 = pcVar9 + 1;
        goto LAB_000886f3;
      }
    }
    else if (*pcVar3 != '\0') {
      iVar2 = isprint((int)*pcVar3);
      if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar3), iVar2 == 0)) goto LAB_000887d6;
      pcVar9 = pcVar3 + 1;
      goto LAB_000886c5;
    }
  }
  if (pcVar9 != (char *)0x0) {
    return;
  }
LAB_000887d6:
  iVar2 = param_1;
  if ((param_1 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = *(int **)(iVar2 + 0x7c);
  }
  piVar8[0x348] = *gpGlobals;
  sprintf(local_80,"%c(TELL) %s: ",2,*(int *)(param_1 + 0x250) + gpGlobals[0x26]);
  pcVar10 = (char *)(*DAT_001a7f8c)(1);
  pcVar10 = strstr(pcVar3,pcVar10);
  if (pcVar10 == (char *)0x0) {
    uVar7 = 0xffffffff;
    pcVar10 = local_80;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    __n = 0x81 - ~uVar7;
  }
  else {
    uVar7 = 0xffffffff;
    pcVar3 = local_80;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    __n = 0x81 - ~uVar7;
    pcVar3 = (char *)(*DAT_001a7f8c)(1);
    uVar7 = 0xffffffff;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = pcVar10 + (~uVar7 - 1);
  }
  strncat(local_80,pcVar3,__n);
  local_2 = 10;
  local_1 = 0;
  iVar2 = 1;
  do {
    if (gpGlobals[0x24] < iVar2) {
      return;
    }
    piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar2);
    if ((((piVar5 != (int *)0x0) && (iVar6 = *piVar5, *(int *)(iVar6 + 0x208) != param_1)) &&
        ((*(byte *)(iVar6 + 0x1a4) & 8) != 0)) &&
       ((*(int *)(*piVar8 + 0x244) == 0 || (*(int *)(iVar6 + 0x244) != 0)))) {
      pcVar3 = (char *)(*DAT_001a7f8c)(1);
      iVar6 = strcmp((char *)(*(int *)(*piVar5 + 0x1d0) + gpGlobals[0x26]),pcVar3);
      if (iVar6 == 0) {
        (*DAT_001a7ef8)(1,gmsgSayText,0,*(undefined4 *)(*piVar5 + 0x208));
        uVar4 = (*DAT_001a7f5c)(param_1);
        (*DAT_001a7f00)(uVar4);
        (*DAT_001a7f18)(local_80);
        (*DAT_001a7efc)();
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


