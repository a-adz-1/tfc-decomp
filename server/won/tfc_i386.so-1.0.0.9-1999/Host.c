// Host_Say__FP7edict_si  @ 000a20e0
void Host_Say__FP7edict_si(int param_1,int param_2)

{
  float fVar1;
  char cVar2;
  float *pfVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  char *local_1d0;
  char local_1c0 [60];
  char local_184 [256];
  char local_84 [128];
  
  pcVar4 = (char *)(*DAT_0017560c)(0);
  iVar5 = (*DAT_00175610)();
  if (iVar5 == 0) {
    return;
  }
  iVar5 = strcasecmp(pcVar4,"say");
  if ((iVar5 == 0) || (iVar5 = strcasecmp(pcVar4,"say_team"), iVar5 == 0)) {
    iVar5 = (*DAT_00175610)();
    if (iVar5 < 2) {
      return;
    }
    pcVar4 = (char *)(*DAT_00175608)();
  }
  else {
    iVar5 = (*DAT_00175610)();
    if (iVar5 < 2) {
      sprintf(local_184,"%s",pcVar4);
    }
    else {
      uVar6 = (*DAT_00175608)();
      sprintf(local_184,"%s %s",pcVar4,uVar6);
    }
    pcVar4 = local_184;
  }
  iVar5 = param_1;
  if ((param_1 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = *(int **)(iVar5 + 0xd8);
  }
  pfVar3 = gpGlobals;
  if (piVar7 != (int *)0x0) {
    if (*gpGlobals < (float)piVar7[0x33b]) {
      fVar1 = (float)piVar7[0x33b] + (float)tfc_spam_penalty2._12_4_;
      piVar7[0x33b] = (int)fVar1;
      sprintf(local_1c0,"You may not speak for %d seconds for spamming.\n",
              (int)ROUND(fVar1 - *pfVar3));
      (*DAT_00175578)(1,gmsgSayText,0,*(undefined4 *)(*piVar7 + 0x1e8));
      uVar6 = (*DAT_001755dc)(*(undefined4 *)(*piVar7 + 0x1e8));
      (*DAT_00175580)(uVar6);
      (*DAT_00175598)(local_1c0);
      (*DAT_0017557c)();
      piVar7[0x33c] = (int)*gpGlobals;
      return;
    }
    fVar1 = (float)piVar7[0x33b];
    if ((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) != 0x40) {
      piVar7[0x33d] = 0;
      piVar7[0x33b] = -0x40800000;
    }
    if (2.0 <= *gpGlobals - (float)piVar7[0x33c]) {
      iVar5 = (int)ROUND((float)piVar7[0x33d] - (*gpGlobals - (float)piVar7[0x33c]));
      piVar7[0x33d] = iVar5;
      if (iVar5 < 0) {
        piVar7[0x33d] = 0;
      }
    }
    else {
      piVar7[0x33d] = piVar7[0x33d] + 1;
      if (param_2 == 0) {
        piVar7[0x33d] = piVar7[0x33d] + 1;
      }
    }
    if ((float)tfc_spam_limit._12_4_ < (float)piVar7[0x33d]) {
      piVar7[0x33b] = (int)(*gpGlobals + (float)tfc_spam_penalty1._12_4_);
      return;
    }
  }
  local_1d0 = pcVar4;
  if (*pcVar4 == '\"') {
    local_1d0 = pcVar4 + 1;
    uVar10 = 0xffffffff;
    pcVar12 = local_1d0;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    pcVar4[~uVar10 - 1] = '\0';
  }
  pcVar4 = local_1d0;
  if (local_1d0 != (char *)0x0) {
    do {
      if (*pcVar4 == '\0') break;
      iVar5 = isprint((int)*pcVar4);
      if ((iVar5 != 0) && (iVar5 = isspace((int)*pcVar4), iVar5 == 0)) goto LAB_000a23f8;
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 != (char *)0x0);
    if (pcVar4 != (char *)0x0) {
      return;
    }
  }
LAB_000a23f8:
  pfVar3 = gpGlobals;
  piVar7[0x33c] = (int)*gpGlobals;
  if (param_2 == 0) {
    iVar5 = *(int *)(param_1 + 0x28c) + (int)gpGlobals[0x26];
    pcVar4 = "%c%s: ";
  }
  else {
    iVar5 = *(int *)(param_1 + 0x28c) + (int)pfVar3[0x26];
    pcVar4 = "%c(TEAM) %s: ";
  }
  sprintf(local_84,pcVar4,2,iVar5);
  uVar10 = 0xffffffff;
  pcVar4 = local_84;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  uVar11 = 0xffffffff;
  pcVar4 = local_1d0;
  do {
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  if ((int)(0x7f - ~uVar10) < (int)(~uVar11 - 1)) {
    local_1d0[0x7f - ~uVar10] = '\0';
  }
  strcat(local_84,local_1d0);
  strcat(local_84,"\n");
  iVar5 = 1;
  do {
    if ((int)gpGlobals[0x24] < iVar5) {
      (*DAT_00175578)(1,gmsgSayText,0,*(undefined4 *)(param_1 + 0x2c4));
      uVar6 = (*DAT_001755dc)(param_1);
      (*DAT_00175580)(uVar6);
      (*DAT_00175598)(local_84);
      (*DAT_0017557c)();
      (*DAT_00175604)(local_84);
      if (param_2 == 0) {
        uVar6 = (*DAT_00175684)(param_1,local_1d0);
        iVar5 = *(int *)(param_1 + 0x28c) + (int)gpGlobals[0x26];
        pcVar4 = "\"%s<%i>\" say \"%s\"\n";
      }
      else {
        uVar6 = (*DAT_00175684)(param_1,local_1d0);
        iVar5 = *(int *)(param_1 + 0x28c) + (int)gpGlobals[0x26];
        pcVar4 = "\"%s<%i>\" say_team \"%s\"\n";
      }
      UTIL_LogPrintf__FPce(pcVar4,iVar5,uVar6);
      return;
    }
    piVar7 = (int *)UTIL_PlayerByIndex__Fi(iVar5);
    if (((piVar7 != (int *)0x0) && (*(int *)(*piVar7 + 0x1e8) != param_1)) &&
       ((*(byte *)(*piVar7 + 0x184) & 8) != 0)) {
      if (param_2 != 0) {
        iVar9 = *g_pGameRules;
        iVar8 = param_1;
        if ((param_1 == 0) && (iVar8 = (*DAT_001755d4)(0), iVar8 == 0)) {
          uVar6 = 0;
        }
        else {
          uVar6 = *(undefined4 *)(iVar8 + 0xd8);
        }
        iVar9 = (**(code **)(iVar9 + 0xd0))(g_pGameRules,piVar7,uVar6);
        if (iVar9 != 1) goto LAB_000a2588;
      }
      (*DAT_00175578)(1,gmsgSayText,0,*(undefined4 *)(*piVar7 + 0x1e8));
      uVar6 = (*DAT_001755dc)(*(undefined4 *)(*piVar7 + 0x1e8));
      (*DAT_00175580)(uVar6);
      (*DAT_00175598)(local_84);
      (*DAT_0017557c)();
    }
LAB_000a2588:
    iVar5 = iVar5 + 1;
  } while( true );
}


