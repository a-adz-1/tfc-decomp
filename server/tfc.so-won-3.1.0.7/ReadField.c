// ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1  @ 0011e01c
int ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1
              (int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
              char *param_7,char *param_8)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  size_t sVar6;
  float fVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float *__s;
  uint uVar12;
  float *pfVar13;
  undefined4 uVar14;
  int local_2c;
  float local_24;
  float local_c;
  float local_8;
  float local_4;
  
  local_24 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  local_4 = 0.0;
  if (*param_1 != 0) {
    iVar11 = *param_1;
    local_24 = *(float *)(iVar11 + 0x550);
    if (*(int *)(iVar11 + 0x52c) != 0) {
      local_c = *(float *)(iVar11 + 0x544);
      local_8 = *(float *)(iVar11 + 0x548);
      local_4 = *(float *)(iVar11 + 0x54c);
    }
  }
  if (0 < param_4) {
    iVar11 = 0;
    do {
      iVar9 = (param_5 + iVar11) % param_4;
      piVar2 = (int *)(iVar9 * 0x10 + param_3);
      iVar3 = strcasecmp((char *)piVar2[1],param_7);
      if (iVar3 == 0) {
        if ((param_1[1] != 0) && (((*(byte *)((int)piVar2 + 0xe) ^ 1) & 1) == 0)) {
          return iVar9;
        }
        uVar10 = 0;
        if ((short)piVar2[3] < 1) {
          return iVar9;
        }
        goto LAB_0011e114;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_4);
  }
  return -1;
LAB_0011e114:
  pfVar13 = (float *)(param_2 + piVar2[2] + uVar10 * *(int *)(gSizes + *piVar2 * 4));
  __s = (float *)(param_8 + uVar10 * *(int *)(gSizes + *piVar2 * 4));
  switch(*piVar2) {
  case 0:
    *pfVar13 = *__s;
    break;
  case 1:
  case 0x10:
  case 0x11:
    local_2c = 0;
    pcVar4 = param_8;
    if (0 < (int)uVar10) {
      uVar12 = uVar10 & 3;
      if (uVar12 != 0) {
        if (1 < uVar12) {
          if (2 < uVar12) {
            cVar1 = *param_8;
            while (cVar1 != '\0') {
              pcVar4 = pcVar4 + 1;
              cVar1 = *pcVar4;
            }
            pcVar4 = pcVar4 + 1;
            local_2c = 1;
          }
          for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
          }
          pcVar4 = pcVar4 + 1;
          local_2c = local_2c + 1;
        }
        for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
        }
        pcVar4 = pcVar4 + 1;
        local_2c = local_2c + 1;
        if ((int)uVar10 <= local_2c) goto LAB_0011e23a;
      }
      do {
        for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
        }
        do {
          pcVar4 = pcVar4 + 1;
        } while (*pcVar4 != '\0');
        do {
          pcVar4 = pcVar4 + 1;
        } while (*pcVar4 != '\0');
        do {
          pcVar5 = pcVar4;
          pcVar4 = pcVar5 + 1;
        } while (*pcVar4 != '\0');
        pcVar4 = pcVar5 + 2;
        local_2c = local_2c + 4;
      } while (local_2c < (int)uVar10);
    }
LAB_0011e23a:
    sVar6 = strlen(pcVar4);
    if (sVar6 == 0) {
LAB_0011e401:
      *pfVar13 = 0.0;
    }
    else {
      fVar7 = (float)(*DAT_001c112c)(pcVar4);
      *pfVar13 = fVar7;
      if ((fVar7 != 0.0) && (param_1[2] != 0)) {
        if (*piVar2 == 0x10) {
          iVar11 = *(int *)(gpGlobals + 0x98);
          pcVar8 = g_engfuncs;
        }
        else {
          if (*piVar2 != 0x11) break;
          iVar11 = *(int *)(gpGlobals + 0x98);
          pcVar8 = DAT_001c1024;
        }
        (*pcVar8)((int)fVar7 + iVar11);
      }
    }
    break;
  case 2:
    iVar11 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s);
    if (iVar11 == 0) goto LAB_0011e401;
    fVar7 = (float)(*DAT_001c1138)(iVar11);
    *pfVar13 = fVar7;
    break;
  case 3:
    iVar11 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s);
    if (iVar11 == 0) goto LAB_0011e401;
    *pfVar13 = *(float *)(iVar11 + 0x7c);
    break;
  case 4:
    iVar11 = *(int *)(gSizes + *piVar2 * 4);
    iVar3 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s);
    if (iVar3 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = *(undefined4 *)(iVar3 + 0x7c);
    }
    __as__7EHANDLEP11CBaseEntity((float *)((int)pfVar13 + (8 - iVar11) * uVar10),uVar14);
    break;
  case 5:
    iVar11 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s);
    if (iVar11 == 0) goto LAB_0011e401;
    *pfVar13 = (float)(iVar11 + 0x80);
    break;
  case 6:
    fVar7 = (float)EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s);
    *pfVar13 = fVar7;
    break;
  case 7:
    *pfVar13 = *__s;
    pfVar13[1] = __s[1];
    pfVar13[2] = __s[2];
    break;
  case 8:
    *pfVar13 = *__s + local_c;
    pfVar13[1] = __s[1] + local_8;
    pfVar13[2] = __s[2] + local_4;
    break;
  case 9:
  case 10:
  case 0xc:
    *pfVar13 = *__s;
    break;
  case 0xb:
    sVar6 = strlen((char *)__s);
    if (sVar6 == 0) goto LAB_0011e401;
    fVar7 = (float)(*DAT_001c1158)(__s);
    *pfVar13 = fVar7;
    break;
  case 0xd:
    *(undefined2 *)pfVar13 = *(undefined2 *)__s;
    break;
  case 0xe:
    *(undefined1 *)pfVar13 = *(undefined1 *)__s;
    break;
  case 0xf:
    *pfVar13 = local_24 + *__s;
    break;
  default:
    (*DAT_001c1114)(4,"Bad field type\n");
  }
  uVar10 = uVar10 + 1;
  if ((int)(short)piVar2[3] <= (int)uVar10) {
    return iVar9;
  }
  goto LAB_0011e114;
}


