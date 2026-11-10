// Host_Say__FP7edict_si  @ 0008f788
void Host_Say__FP7edict_si(int param_1,int param_2)

{
  float fVar1;
  uint *puVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  longdouble lVar12;
  int local_1a8;
  int *local_1a0;
  uint *local_194;
  uint local_184 [64];
  uint local_84 [32];
  
  pcVar4 = (char *)(*DAT_0019f7ec)(0);
  lVar12 = (longdouble)(*DAT_0019f784)("tfc_spectchat");
  fVar1 = (float)lVar12;
  iVar5 = (*DAT_0019f7f0)();
  if (iVar5 == 0) {
    return;
  }
  iVar5 = strcasecmp(pcVar4,"say");
  if ((iVar5 == 0) || (iVar5 = strcasecmp(pcVar4,"say_team"), iVar5 == 0)) {
    iVar5 = (*DAT_0019f7f0)();
    if (iVar5 < 2) {
      return;
    }
    local_194 = (uint *)(*DAT_0019f7e8)();
  }
  else {
    iVar5 = (*DAT_0019f7f0)();
    if (iVar5 < 2) {
      sprintf((char *)local_184,"%s",pcVar4);
    }
    else {
      uVar9 = (*DAT_0019f7e8)();
      sprintf((char *)local_184,"%s %s",pcVar4,uVar9);
    }
    local_194 = local_184;
  }
  iVar5 = FailedSpamCheck__FP7edict_si(param_1,param_2);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = param_1;
  if ((param_1 == 0) && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)) {
    local_1a0 = (int *)0x0;
  }
  else {
    local_1a0 = *(int **)(iVar5 + 0x7c);
  }
  if ((char)*local_194 != '\"') goto LAB_0008f94d;
  puVar10 = (uint *)((int)local_194 + 1);
  uVar11 = (uint)puVar10 & 3;
  puVar2 = puVar10;
  if (uVar11 == 0) {
LAB_0008f927:
    do {
      puVar6 = puVar2;
      uVar11 = *puVar6;
      if ((char)uVar11 == '\0') goto LAB_0008f949;
      if ((char)(uVar11 >> 8) == '\0') goto LAB_0008f948;
      if ((uVar11 & 0xff0000) == 0) goto LAB_0008f947;
      puVar2 = puVar6 + 1;
    } while ((uVar11 & 0xff000000) != 0);
    puVar6 = (uint *)((int)puVar6 + 1);
LAB_0008f947:
    puVar6 = (uint *)((int)puVar6 + 1);
LAB_0008f948:
    puVar6 = (uint *)((int)puVar6 + 1);
  }
  else {
    puVar6 = puVar10;
    if ((POPCOUNT(uVar11) & 1U) == 0) {
LAB_0008f922:
      if ((char)*puVar6 != '\0') {
        puVar2 = (uint *)((int)puVar6 + 1);
        goto LAB_0008f927;
      }
    }
    else if (uVar11 == 2) {
LAB_0008f91d:
      if ((char)*puVar6 != '\0') {
        puVar6 = (uint *)((int)puVar6 + 1);
        goto LAB_0008f922;
      }
    }
    else if (*(char *)puVar10 != '\0') {
      puVar6 = (uint *)((int)local_194 + 2);
      goto LAB_0008f91d;
    }
  }
LAB_0008f949:
  *(char *)((int)puVar6 + -1) = '\0';
  local_194 = puVar10;
LAB_0008f94d:
  puVar10 = local_194;
  puVar2 = local_194;
  if (local_194 != (uint *)0x0) {
    do {
      if ((char)*puVar10 == '\0') break;
      iVar5 = isprint((int)(char)*puVar10);
      if ((iVar5 != 0) && (iVar5 = isspace((int)(char)*puVar10), iVar5 == 0))
      goto joined_r0x0008f990;
      puVar10 = (uint *)((int)puVar10 + 1);
    } while (puVar10 != (uint *)0x0);
    if (puVar10 != (uint *)0x0) {
      return;
    }
  }
joined_r0x0008f990:
  do {
    if ((puVar2 == (uint *)0x0) || ((char)*puVar2 == '\0')) break;
    if ((char)*puVar2 == '%') {
      uVar11 = (uint)local_194 & 3;
      puVar10 = local_194;
      if (uVar11 == 0) {
LAB_0008f9ce:
        do {
          puVar6 = puVar10;
          uVar11 = *puVar6;
          if ((char)uVar11 == '\0') goto LAB_0008f9f0;
          if ((char)(uVar11 >> 8) == '\0') goto LAB_0008f9ef;
          if ((uVar11 & 0xff0000) == 0) goto LAB_0008f9ee;
          puVar10 = puVar6 + 1;
        } while ((uVar11 & 0xff000000) != 0);
        puVar6 = (uint *)((int)puVar6 + 1);
LAB_0008f9ee:
        puVar6 = (uint *)((int)puVar6 + 1);
LAB_0008f9ef:
        puVar6 = (uint *)((int)puVar6 + 1);
      }
      else {
        puVar6 = local_194;
        if ((POPCOUNT(uVar11) & 1U) == 0) {
LAB_0008f9c9:
          if ((char)*puVar6 != '\0') {
            puVar10 = (uint *)((int)puVar6 + 1);
            goto LAB_0008f9ce;
          }
        }
        else if (uVar11 == 2) {
LAB_0008f9c4:
          if ((char)*puVar6 != '\0') {
            puVar6 = (uint *)((int)puVar6 + 1);
            goto LAB_0008f9c9;
          }
        }
        else if ((char)*local_194 != '\0') {
          puVar6 = (uint *)((int)local_194 + 1);
          goto LAB_0008f9c4;
        }
      }
LAB_0008f9f0:
      if (0x7c < (uint)((int)puVar6 - (int)local_194)) break;
      cVar3 = *(char *)((int)puVar2 + 1);
      if (cVar3 == 'h') {
        *(char *)puVar2 = '\0';
        pcVar4 = (char *)UTIL_VarArgs__FPce(&DAT_0014817c,(int)ROUND(*(float *)(*local_1a0 + 0x160))
                                            ,(char *)((int)puVar2 + 2));
        strcat((char *)local_194,pcVar4);
        cVar3 = *(char *)((int)puVar2 + 1);
      }
      if (cVar3 == 'a') {
        *(char *)puVar2 = '\0';
        pcVar4 = (char *)UTIL_VarArgs__FPce(&DAT_0014817c,(int)ROUND(*(float *)(*local_1a0 + 0x1bc))
                                            ,(char *)((int)puVar2 + 2));
        strcat((char *)local_194,pcVar4);
        cVar3 = *(char *)((int)puVar2 + 1);
      }
      if (cVar3 == 'i') {
        *(char *)puVar2 = '\0';
        iVar5 = __opi__7EHANDLE(local_1a0 + 0x37a);
        if (iVar5 == 0) {
          pcVar4 = (char *)UTIL_VarArgs__FPce(&DAT_00148179,(char *)((int)puVar2 + 2));
          strcat((char *)local_194,pcVar4);
        }
        else {
          piVar7 = (int *)__rf__7EHANDLE(local_1a0 + 0x37a,(char *)((int)puVar2 + 2));
          pcVar4 = (char *)UTIL_VarArgs__FPce(&DAT_00148181,
                                              *(int *)(*piVar7 + 0x1d0) + gpGlobals[0x26]);
          strcat((char *)local_194,pcVar4);
        }
      }
    }
    puVar2 = (uint *)((int)puVar2 + 1);
  } while( true );
  local_1a0[0x36f] = *gpGlobals;
  if (*(int *)(*local_1a0 + 0x244) == 0) {
    if (param_2 == 0) goto LAB_0008fbec;
    iVar5 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
    pcVar4 = "%c(TEAM) %s: ";
  }
  else if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) || (param_2 != 0))
  {
    iVar5 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
    pcVar4 = "%c(SPEC) %s: ";
  }
  else {
LAB_0008fbec:
    iVar5 = *(int *)(param_1 + 0x250) + gpGlobals[0x26];
    pcVar4 = "%c%s: ";
  }
  sprintf((char *)local_84,pcVar4,2,iVar5);
  puVar2 = local_84;
  do {
    puVar10 = puVar2;
    uVar11 = *puVar10;
    if ((char)uVar11 == '\0') goto LAB_0008fc5c;
    if ((char)(uVar11 >> 8) == '\0') goto LAB_0008fc5b;
    if ((uVar11 & 0xff0000) == 0) goto LAB_0008fc5a;
    puVar2 = puVar10 + 1;
  } while ((uVar11 & 0xff000000) != 0);
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_0008fc5a:
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_0008fc5b:
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_0008fc5c:
  iVar5 = 0x7e - ((int)puVar10 - (int)local_84);
  uVar11 = (uint)local_194 & 3;
  puVar2 = local_194;
  if (uVar11 != 0) {
    puVar10 = local_194;
    if ((POPCOUNT(uVar11) & 1U) != 0) {
      if (uVar11 != 2) {
        if ((char)*local_194 == '\0') goto LAB_0008fcae;
        puVar10 = (uint *)((int)local_194 + 1);
      }
      if ((char)*puVar10 == '\0') goto LAB_0008fcae;
      puVar10 = (uint *)((int)puVar10 + 1);
    }
    if ((char)*puVar10 == '\0') goto LAB_0008fcae;
    puVar2 = (uint *)((int)puVar10 + 1);
  }
  do {
    puVar10 = puVar2;
    uVar11 = *puVar10;
    if ((uVar11 & 0xff) == 0) goto LAB_0008fcae;
    if ((uVar11 & 0xff00) == 0) goto LAB_0008fcad;
    if ((uVar11 & 0xff0000) == 0) goto LAB_0008fcac;
    puVar2 = puVar10 + 1;
  } while ((uVar11 & 0xff000000) != 0);
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_0008fcac:
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_0008fcad:
  puVar10 = (uint *)((int)puVar10 + 1);
LAB_0008fcae:
  if (iVar5 < (int)puVar10 - (int)local_194) {
    *(undefined1 *)(iVar5 + (int)local_194) = 0;
  }
  strcat((char *)local_84,(char *)local_194);
  strcat((char *)local_84,"\n");
  local_1a8 = 1;
  if (0 < gpGlobals[0x24]) {
    do {
      piVar7 = (int *)UTIL_PlayerByIndex__Fi(local_1a8);
      if ((((piVar7 != (int *)0x0) && (*(int *)(*piVar7 + 0x208) != param_1)) &&
          ((*(byte *)(*piVar7 + 0x1a4) & 8) != 0)) &&
         (cVar3 = PlayerHasBlockedPlayer__13CVoiceGameMgrP11CBasePlayerT1
                            (g_pGameRules + 6,piVar7,local_1a0), cVar3 == '\0')) {
        if (*(int *)(*local_1a0 + 0x244) == 0) {
          if (param_2 != 0) {
            iVar5 = *g_pGameRules;
            iVar8 = param_1;
            if ((param_1 == 0) && (iVar8 = (*DAT_0019f7b4)(0), iVar8 == 0)) {
              uVar9 = 0;
            }
            else {
              uVar9 = *(undefined4 *)(iVar8 + 0x7c);
            }
            iVar5 = (**(code **)(iVar5 + 0xd0))(g_pGameRules,piVar7,uVar9);
            if (iVar5 != 1) goto LAB_0008fe96;
          }
          if (*(int *)(*local_1a0 + 0x244) != 0) goto LAB_0008fe04;
        }
        else {
LAB_0008fe04:
          if ((((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
              (param_2 != 0)) && (*(int *)(*piVar7 + 0x244) == 0)) goto LAB_0008fe96;
        }
        (*DAT_0019f758)(1,gmsgSayText,0,*(undefined4 *)(*piVar7 + 0x208));
        uVar9 = (*DAT_0019f7bc)(param_1);
        (*DAT_0019f760)(uVar9);
        (*DAT_0019f778)(local_84);
        (*DAT_0019f75c)();
      }
LAB_0008fe96:
      local_1a8 = local_1a8 + 1;
    } while (local_1a8 <= gpGlobals[0x24]);
  }
  (*DAT_0019f758)(1,gmsgSayText,0,*(undefined4 *)(param_1 + 0x288));
  uVar9 = (*DAT_0019f7bc)(param_1);
  (*DAT_0019f760)(uVar9);
  (*DAT_0019f778)(local_84);
  (*DAT_0019f75c)();
  (*DAT_0019f7e4)(local_84);
  pcVar4 = "say";
  if (param_2 != 0) {
    pcVar4 = "say_team";
  }
  if (local_1a0[0x48] == 0) {
    pcVar4 = "SPECTATOR";
  }
  else {
    pcVar4 = (char *)GetTeamName__Fi(local_1a0[0x48],pcVar4,local_194);
  }
  uVar9 = (*DAT_0019f8dc)(param_1,pcVar4);
  uVar9 = (*DAT_0019f864)(param_1,uVar9);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%s><%s>\" %s \"%s\"\n",*(int *)(param_1 + 0x250) + gpGlobals[0x26],uVar9);
  return;
}


// Host_Tell__FP7edict_s  @ 0008ffdc
void Host_Tell__FP7edict_s(int param_1)

{
  uint *puVar1;
  int iVar2;
  char *pcVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  size_t __n;
  char *pcVar10;
  uint uVar11;
  int *local_18c;
  char local_184 [254];
  undefined1 local_86;
  undefined1 local_85;
  uint local_84 [31];
  undefined1 local_6;
  undefined1 local_5;
  
  iVar2 = (*DAT_0019f7f0)();
  if (iVar2 < 3) {
    return;
  }
  iVar2 = FailedSpamCheck__FP7edict_si(param_1,1);
  if (iVar2 != 0) {
    return;
  }
  pcVar3 = (char *)(*DAT_0019f7e8)();
  pcVar10 = pcVar3;
  if (pcVar3 != (char *)0x0) {
    do {
      if (*pcVar10 == '\0') break;
      iVar2 = isprint((int)*pcVar10);
      if ((iVar2 != 0) && (iVar2 = isspace((int)*pcVar10), iVar2 == 0)) goto LAB_00090068;
      pcVar10 = pcVar10 + 1;
    } while (pcVar10 != (char *)0x0);
    if (pcVar10 != (char *)0x0) {
      return;
    }
  }
LAB_00090068:
  iVar2 = param_1;
  if ((param_1 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    local_18c = (int *)0x0;
  }
  else {
    local_18c = *(int **)(iVar2 + 0x7c);
  }
  local_18c[0x36f] = *gpGlobals;
  sprintf((char *)local_84,"%c(TELL) %s: ",2,*(int *)(param_1 + 0x250) + gpGlobals[0x26]);
  pcVar10 = (char *)(*DAT_0019f7ec)(1);
  pcVar10 = strstr(pcVar3,pcVar10);
  puVar6 = local_84;
  puVar1 = local_84;
  if (pcVar10 == (char *)0x0) {
    do {
      puVar4 = puVar6;
      uVar11 = *puVar4;
      if ((char)uVar11 == '\0') goto LAB_000901ef;
      if ((char)(uVar11 >> 8) == '\0') goto LAB_000901ee;
      if ((uVar11 & 0xff0000) == 0) goto LAB_000901ed;
      puVar6 = puVar4 + 1;
    } while ((uVar11 & 0xff000000) != 0);
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000901ed:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000901ee:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000901ef:
    __n = 0x7f - ((int)puVar4 - (int)local_84);
    if ((int)__n < 1) goto LAB_00090218;
  }
  else {
    do {
      puVar4 = puVar6;
      uVar11 = *puVar4;
      if ((char)uVar11 == '\0') goto LAB_00090141;
      if ((char)(uVar11 >> 8) == '\0') goto LAB_00090140;
      if ((uVar11 & 0xff0000) == 0) goto LAB_0009013f;
      puVar6 = puVar4 + 1;
    } while ((uVar11 & 0xff000000) != 0);
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_0009013f:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_00090140:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_00090141:
    __n = 0x7f - ((int)puVar4 - (int)local_84);
    if ((int)__n < 1) goto LAB_00090218;
    puVar4 = (uint *)(*DAT_0019f7ec)(1);
    uVar11 = (uint)puVar4 & 3;
    puVar6 = puVar4;
    if (uVar11 == 0) {
LAB_00090187:
      do {
        puVar5 = puVar6;
        uVar11 = *puVar5;
        if ((uVar11 & 0xff) == 0) goto LAB_000901b1;
        if ((uVar11 & 0xff00) == 0) goto LAB_000901b0;
        if ((uVar11 & 0xff0000) == 0) goto LAB_000901af;
        puVar6 = puVar5 + 1;
      } while ((uVar11 & 0xff000000) != 0);
      puVar5 = (uint *)((int)puVar5 + 1);
LAB_000901af:
      puVar5 = (uint *)((int)puVar5 + 1);
LAB_000901b0:
      puVar5 = (uint *)((int)puVar5 + 1);
    }
    else {
      puVar5 = puVar4;
      if ((POPCOUNT(uVar11) & 1U) == 0) {
LAB_00090181:
        if ((char)*puVar5 != '\0') {
          puVar6 = (uint *)((int)puVar5 + 1);
          goto LAB_00090187;
        }
      }
      else if (uVar11 == 2) {
LAB_0009017b:
        if ((char)*puVar5 != '\0') {
          puVar5 = (uint *)((int)puVar5 + 1);
          goto LAB_00090181;
        }
      }
      else if ((char)*puVar4 != '\0') {
        puVar5 = (uint *)((int)puVar4 + 1);
        goto LAB_0009017b;
      }
    }
LAB_000901b1:
    pcVar3 = pcVar10 + ((int)puVar5 - (int)puVar4);
  }
  strncat((char *)local_84,pcVar3,__n);
LAB_00090218:
  do {
    puVar6 = puVar1;
    uVar11 = *puVar6;
    if ((char)uVar11 == '\0') goto LAB_0009023a;
    if ((char)(uVar11 >> 8) == '\0') goto LAB_00090239;
    if ((uVar11 & 0xff0000) == 0) goto LAB_00090238;
    puVar1 = puVar6 + 1;
  } while ((uVar11 & 0xff000000) != 0);
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_00090238:
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_00090239:
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_0009023a:
  if ((uint)((int)puVar6 - (int)local_84) < 0x7f) {
    strcat((char *)local_84,"\n");
  }
  else {
    local_6 = 10;
    local_5 = 0;
  }
  if (0 < gpGlobals[0x24]) {
    iVar2 = 1;
    do {
      piVar7 = (int *)UTIL_PlayerByIndex__Fi(iVar2);
      if ((((piVar7 != (int *)0x0) && (iVar8 = *piVar7, *(int *)(iVar8 + 0x208) != param_1)) &&
          ((*(byte *)(iVar8 + 0x1a4) & 8) != 0)) &&
         ((*(int *)(*local_18c + 0x244) == 0 || (*(int *)(iVar8 + 0x244) != 0)))) {
        pcVar3 = (char *)(*DAT_0019f7ec)(1);
        iVar8 = strcmp((char *)(*(int *)(*piVar7 + 0x1d0) + gpGlobals[0x26]),pcVar3);
        if (iVar8 == 0) {
          (*DAT_0019f758)(1,gmsgSayText,0,*(undefined4 *)(*piVar7 + 0x208));
          uVar9 = (*DAT_0019f7bc)(param_1);
          (*DAT_0019f760)(uVar9);
          (*DAT_0019f778)(local_84);
          (*DAT_0019f75c)();
          puVar6 = (uint *)(*DAT_0019f7ec)(1);
          uVar11 = (uint)puVar6 & 3;
          puVar1 = puVar6;
          if (uVar11 == 0) goto LAB_000903af;
          puVar4 = puVar6;
          if ((POPCOUNT(uVar11) & 1U) != 0) {
            if (uVar11 != 2) {
              if ((char)*puVar6 == '\0') goto LAB_000903d9;
              puVar4 = (uint *)((int)puVar6 + 1);
            }
            if ((char)*puVar4 == '\0') goto LAB_000903d9;
            puVar4 = (uint *)((int)puVar4 + 1);
          }
          if ((char)*puVar4 == '\0') goto LAB_000903d9;
          puVar1 = (uint *)((int)puVar4 + 1);
          goto LAB_000903af;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= gpGlobals[0x24]);
  }
  return;
  while( true ) {
    if ((uVar11 & 0xff00) == 0) goto LAB_000903d8;
    if ((uVar11 & 0xff0000) == 0) goto LAB_000903d7;
    puVar1 = puVar4 + 1;
    if ((uVar11 & 0xff000000) == 0) break;
LAB_000903af:
    puVar4 = puVar1;
    uVar11 = *puVar4;
    if ((uVar11 & 0xff) == 0) goto LAB_000903d9;
  }
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_000903d7:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_000903d8:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_000903d9:
  if (piVar7[0x48] == 0) {
    pcVar10 = "SPECTATOR";
  }
  else {
    pcVar10 = (char *)GetTeamName__Fi(piVar7[0x48],pcVar10 + (int)((int)puVar4 + (1 - (int)puVar6)))
    ;
  }
  uVar9 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar7 + 0x208),pcVar10);
  uVar9 = (*DAT_0019f864)(*(undefined4 *)(*piVar7 + 0x208),uVar9);
  if (local_18c[0x48] == 0) {
    pcVar10 = "SPECTATOR";
  }
  else {
    pcVar10 = (char *)GetTeamName__Fi(local_18c[0x48],*(int *)(*piVar7 + 0x1d0) + gpGlobals[0x26],
                                      uVar9);
  }
  uVar9 = (*DAT_0019f8dc)(param_1,pcVar10);
  uVar9 = (*DAT_0019f864)(param_1,uVar9);
  snprintf(local_184,0xff,"\"%s<%i><%s><%s>\" tell \"%s<%i><%s><%s>\" message \"%s\"\n",
           *(int *)(param_1 + 0x250) + gpGlobals[0x26],uVar9);
  local_86 = 10;
  local_85 = 0;
  (*DAT_0019f7e4)(local_184);
  UTIL_LogPrintf__FPce(local_184);
  return;
}


