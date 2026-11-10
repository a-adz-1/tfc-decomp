// Host_Say__FP7edict_si  @ 0008ff48
void Host_Say__FP7edict_si(int param_1,int param_2)

{
  float fVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  char *pcVar12;
  longdouble lVar13;
  char *local_19c;
  char *local_190;
  char local_180 [256];
  char local_80 [128];
  
  pcVar3 = (char *)(*DAT_001c116c)(0);
  lVar13 = (longdouble)(*DAT_001c1104)("tfc_spectchat");
  fVar1 = (float)lVar13;
  iVar4 = (*DAT_001c1170)();
  if (iVar4 == 0) {
    return;
  }
  iVar4 = strcasecmp(pcVar3,"say");
  if ((iVar4 == 0) || (iVar4 = strcasecmp(pcVar3,"say_team"), iVar4 == 0)) {
    iVar4 = (*DAT_001c1170)();
    if (iVar4 < 2) {
      return;
    }
    local_190 = (char *)(*DAT_001c1168)();
  }
  else {
    iVar4 = (*DAT_001c1170)();
    if (iVar4 < 2) {
      sprintf(local_180,"%s",pcVar3);
    }
    else {
      uVar8 = (*DAT_001c1168)();
      sprintf(local_180,"%s %s",pcVar3,uVar8);
    }
    local_190 = local_180;
  }
  iVar4 = FailedSpamCheck__FP7edict_si(param_1,param_2);
  if (iVar4 != 0) {
    return;
  }
  iVar4 = param_1;
  if ((param_1 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = *(int **)(iVar4 + 0x7c);
  }
  if (*local_190 == '\"') {
    uVar9 = 0xffffffff;
    pcVar3 = local_190 + 1;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    local_190[~uVar9 - 1] = '\0';
    local_190 = local_190 + 1;
  }
  if (local_190 != (char *)0x0) {
    uVar9 = -(int)local_190 & 3;
    pcVar3 = local_190;
    if (uVar9 == 0) {
LAB_000901b0:
      do {
        pcVar12 = pcVar3;
        if (*pcVar3 == '\0') break;
        iVar4 = isprint((int)*pcVar3);
        if ((iVar4 != 0) && (iVar4 = isspace((int)*pcVar3), iVar4 == 0)) goto LAB_0009025e;
        pcVar12 = pcVar3 + 1;
        if (*pcVar12 == '\0') break;
        iVar4 = isprint((int)*pcVar12);
        if ((iVar4 != 0) && (iVar4 = isspace((int)*pcVar12), iVar4 == 0)) goto LAB_0009025e;
        pcVar12 = pcVar3 + 2;
        if (*pcVar12 == '\0') break;
        iVar4 = isprint((int)*pcVar12);
        if ((iVar4 != 0) && (iVar4 = isspace((int)*pcVar12), iVar4 == 0)) goto LAB_0009025e;
        pcVar12 = pcVar3 + 3;
        if (*pcVar12 == '\0') break;
        iVar4 = isprint((int)*pcVar12);
        if ((iVar4 != 0) && (iVar4 = isspace((int)*pcVar12), iVar4 == 0)) goto LAB_0009025e;
        pcVar3 = pcVar3 + 4;
        pcVar12 = pcVar3;
      } while (pcVar3 != (char *)0x0);
    }
    else {
      pcVar12 = local_190;
      if (uVar9 < 2) {
LAB_0009017a:
        if (*pcVar12 != '\0') {
          iVar4 = isprint((int)*pcVar12);
          if (((iVar4 != 0) && (iVar4 = isspace((int)*pcVar12), iVar4 == 0)) ||
             (pcVar3 = pcVar12 + 1, pcVar3 == (char *)0x0)) goto LAB_0009025e;
          goto LAB_000901b0;
        }
      }
      else if (uVar9 < 3) {
LAB_0009014c:
        if (*pcVar12 != '\0') {
          iVar4 = isprint((int)*pcVar12);
          if ((iVar4 != 0) && (iVar4 = isspace((int)*pcVar12), iVar4 == 0)) goto LAB_0009025e;
          pcVar12 = pcVar12 + 1;
          goto LAB_0009017a;
        }
      }
      else if (*local_190 != '\0') {
        iVar4 = isprint((int)*local_190);
        if ((iVar4 != 0) && (iVar4 = isspace((int)*local_190), iVar4 == 0)) goto LAB_0009025e;
        pcVar12 = local_190 + 1;
        goto LAB_0009014c;
      }
    }
    if (pcVar12 != (char *)0x0) {
      return;
    }
  }
LAB_0009025e:
  local_19c = local_190;
  if (local_190 != (char *)0x0) {
    pcVar3 = local_190 + 2;
    do {
      if (*local_19c == '\0') break;
      if (*local_19c == '%') {
        uVar9 = 0xffffffff;
        pcVar12 = local_190;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar2 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar2 != '\0');
        if (0x7c < ~uVar9 - 1) break;
        if (pcVar3[-1] == 'h') {
          *local_19c = '\0';
          pcVar12 = (char *)UTIL_VarArgs__FPce(&DAT_00142abc,
                                               (int)ROUND(*(float *)(*piVar11 + 0x160)),pcVar3);
          strcat(local_190,pcVar12);
        }
        if (pcVar3[-1] == 'a') {
          *local_19c = '\0';
          pcVar12 = (char *)UTIL_VarArgs__FPce(&DAT_00142abc,
                                               (int)ROUND(*(float *)(*piVar11 + 0x1bc)),pcVar3);
          strcat(local_190,pcVar12);
        }
        if (pcVar3[-1] == 'i') {
          *local_19c = '\0';
          iVar4 = __opi__7EHANDLE(piVar11 + 0x373);
          if (iVar4 == 0) {
            pcVar12 = (char *)UTIL_VarArgs__FPce(&DAT_00142ab9,pcVar3);
            strcat(local_190,pcVar12);
          }
          else {
            piVar5 = (int *)__rf__7EHANDLE(piVar11 + 0x373,pcVar3);
            pcVar12 = (char *)UTIL_VarArgs__FPce(&DAT_00142ac1,
                                                 *(int *)(*piVar5 + 0x1d0) + gpGlobals[0x26]);
            strcat(local_190,pcVar12);
          }
        }
      }
      pcVar3 = pcVar3 + 1;
      local_19c = local_19c + 1;
    } while (local_19c != (char *)0x0);
  }
  piVar11[0x368] = *gpGlobals;
  if (*(int *)(*piVar11 + 0x244) == 0) {
    if (param_2 != 0) {
      iVar4 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
      pcVar3 = "%c(TEAM) %s: ";
      goto LAB_000904de;
    }
  }
  else if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) || (param_2 != 0))
  {
    iVar4 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
    pcVar3 = "%c(SPEC) %s: ";
    goto LAB_000904de;
  }
  iVar4 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
  pcVar3 = "%c%s: ";
LAB_000904de:
  sprintf(local_80,pcVar3,2,iVar4);
  uVar9 = 0xffffffff;
  pcVar3 = local_80;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  uVar10 = 0xffffffff;
  pcVar3 = local_190;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  if ((int)(0x7f - ~uVar9) < (int)(~uVar10 - 1)) {
    local_190[0x7f - ~uVar9] = '\0';
  }
  strcat(local_80,local_190);
  strcat(local_80,"\n");
  iVar4 = 1;
  if (0 < gpGlobals[0x24]) {
    do {
      piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar4);
      if (((piVar5 != (int *)0x0) && (*(int *)(*piVar5 + 0x208) != param_1)) &&
         ((*(byte *)(*piVar5 + 0x1a4) & 8) != 0)) {
        if (*(int *)(*piVar11 + 0x244) == 0) {
          if (param_2 != 0) {
            iVar7 = *g_pGameRules;
            iVar6 = param_1;
            if ((param_1 == 0) && (iVar6 = (*DAT_001c1134)(0), iVar6 == 0)) {
              uVar8 = 0;
            }
            else {
              uVar8 = *(undefined4 *)(iVar6 + 0x7c);
            }
            iVar7 = (**(code **)(iVar7 + 0xd0))(g_pGameRules,piVar5,uVar8);
            if (iVar7 != 1) goto LAB_00090705;
          }
          if (*(int *)(*piVar11 + 0x244) != 0) goto LAB_00090642;
        }
        else {
LAB_00090642:
          if ((((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
              (param_2 != 0)) && (*(int *)(*piVar5 + 0x244) == 0)) goto LAB_00090705;
        }
        (*DAT_001c10d8)(1,gmsgSayText,0,*(undefined4 *)(*piVar5 + 0x208));
        uVar8 = (*DAT_001c113c)(param_1);
        (*DAT_001c10e0)(uVar8);
        (*DAT_001c10f8)(local_80);
        (*DAT_001c10dc)();
      }
LAB_00090705:
      iVar4 = iVar4 + 1;
    } while (iVar4 <= gpGlobals[0x24]);
  }
  (*DAT_001c10d8)(1,gmsgSayText,0,*(undefined4 *)(param_1 + 0x288));
  uVar8 = (*DAT_001c113c)(param_1);
  (*DAT_001c10e0)(uVar8);
  (*DAT_001c10f8)(local_80);
  (*DAT_001c10dc)();
  (*DAT_001c1164)(local_80);
  pcVar3 = "say";
  if (param_2 != 0) {
    pcVar3 = "say_team";
  }
  if (piVar11[0x48] == 0) {
    pcVar3 = "SPECTATOR";
  }
  else {
    pcVar3 = (char *)GetTeamName__Fi(piVar11[0x48],pcVar3,local_190);
  }
  uVar8 = (*DAT_001c11f4)(param_1,pcVar3);
  uVar8 = (*DAT_001c11e4)(param_1,uVar8);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%u><%s>\" %s \"%s\"\n",*(int *)(param_1 + 0x250) + gpGlobals[0x26],uVar8);
  return;
}


// Host_Tell__FP7edict_s  @ 00090898
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
  
  iVar2 = (*DAT_001c1170)();
  if (iVar2 < 3) {
    return;
  }
  iVar2 = FailedSpamCheck__FP7edict_si(param_1,1);
  if (iVar2 != 0) {
    return;
  }
  pcVar3 = (char *)(*DAT_001c1168)();
  if (pcVar3 != (char *)0x0) {
    uVar7 = -(int)pcVar3 & 3;
    pcVar10 = pcVar3;
    if (uVar7 == 0) {
LAB_000909a8:
      do {
        pcVar9 = pcVar10;
        if (*pcVar10 == '\0') break;
        iVar2 = isprint((int)*pcVar10);
        if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar10), iVar2 == 0)) goto LAB_00090a56;
        pcVar9 = pcVar10 + 1;
        if (*pcVar9 == '\0') break;
        iVar2 = isprint((int)*pcVar9);
        if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_00090a56;
        pcVar9 = pcVar10 + 2;
        if (*pcVar9 == '\0') break;
        iVar2 = isprint((int)*pcVar9);
        if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_00090a56;
        pcVar9 = pcVar10 + 3;
        if (*pcVar9 == '\0') break;
        iVar2 = isprint((int)*pcVar9);
        if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_00090a56;
        pcVar10 = pcVar10 + 4;
        pcVar9 = pcVar10;
      } while (pcVar10 != (char *)0x0);
    }
    else {
      pcVar9 = pcVar3;
      if (uVar7 < 2) {
LAB_00090973:
        if (*pcVar9 != '\0') {
          iVar2 = isprint((int)*pcVar9);
          if (((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) ||
             (pcVar10 = pcVar9 + 1, pcVar10 == (char *)0x0)) goto LAB_00090a56;
          goto LAB_000909a8;
        }
      }
      else if (uVar7 < 3) {
LAB_00090945:
        if (*pcVar9 != '\0') {
          iVar2 = isprint((int)*pcVar9);
          if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar9), iVar2 == 0)) goto LAB_00090a56;
          pcVar9 = pcVar9 + 1;
          goto LAB_00090973;
        }
      }
      else if (*pcVar3 != '\0') {
        iVar2 = isprint((int)*pcVar3);
        if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar3), iVar2 == 0)) goto LAB_00090a56;
        pcVar9 = pcVar3 + 1;
        goto LAB_00090945;
      }
    }
    if (pcVar9 != (char *)0x0) {
      return;
    }
  }
LAB_00090a56:
  iVar2 = param_1;
  if ((param_1 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = *(int **)(iVar2 + 0x7c);
  }
  piVar8[0x368] = *gpGlobals;
  sprintf(local_80,"%c(TELL) %s: ",2,*(int *)(param_1 + 0x250) + gpGlobals[0x26]);
  pcVar10 = (char *)(*DAT_001c116c)(1);
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
    __n = 0x80 - ~uVar7;
    if ((int)__n < 1) goto LAB_00090c26;
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
    __n = 0x80 - ~uVar7;
    if ((int)__n < 1) goto LAB_00090c26;
    pcVar3 = (char *)(*DAT_001c116c)(1);
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
LAB_00090c26:
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
      pcVar3 = (char *)(*DAT_001c116c)(1);
      iVar6 = strcmp((char *)(*(int *)(*piVar5 + 0x1d0) + gpGlobals[0x26]),pcVar3);
      if (iVar6 == 0) {
        (*DAT_001c10d8)(1,gmsgSayText,0,*(undefined4 *)(*piVar5 + 0x208));
        uVar4 = (*DAT_001c113c)(param_1);
        (*DAT_001c10e0)(uVar4);
        (*DAT_001c10f8)(local_80);
        (*DAT_001c10dc)();
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


