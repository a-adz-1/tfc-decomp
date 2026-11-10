// ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1  @ 0010e4d0
int ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1
              (int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
              char *param_7,char *param_8)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  float fVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  uint uVar12;
  float *pfVar13;
  undefined4 uVar14;
  int iStack_2c;
  float local_24;
  float local_c;
  float local_8;
  float local_4;
  
  local_24 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  local_4 = 0.0;
  if (*param_1 != 0) {
    iVar10 = *param_1;
    local_24 = *(float *)(iVar10 + 0x550);
    if (*(int *)(iVar10 + 0x52c) != 0) {
      local_c = *(float *)(iVar10 + 0x544);
      local_8 = *(float *)(iVar10 + 0x548);
      local_4 = *(float *)(iVar10 + 0x54c);
    }
  }
  if (0 < param_4) {
    iVar10 = 0;
    do {
      iVar8 = (param_5 + iVar10) % param_4;
      piVar2 = (int *)(iVar8 * 0x10 + param_3);
      iVar3 = strcasecmp((char *)piVar2[1],param_7);
      if (iVar3 == 0) {
        if ((param_1[1] != 0) && (((*(byte *)((int)piVar2 + 0xe) ^ 1) & 1) == 0)) {
          return iVar8;
        }
        uVar9 = 0;
        if ((short)piVar2[3] < 1) {
          return iVar8;
        }
        goto LAB_0010e5c8;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_4);
  }
  return -1;
LAB_0010e5c8:
  pfVar13 = (float *)(param_2 + piVar2[2] + uVar9 * *(int *)(gSizes + *piVar2 * 4));
  pfVar11 = (float *)(param_8 + uVar9 * *(int *)(gSizes + *piVar2 * 4));
  switch(*piVar2) {
  case 0:
    *pfVar13 = *pfVar11;
    break;
  case 1:
  case 0x10:
  case 0x11:
    iStack_2c = 0;
    pcVar4 = param_8;
    if (0 < (int)uVar9) {
      uVar12 = uVar9 & 3;
      if (uVar12 != 0) {
        if (1 < uVar12) {
          if (2 < uVar12) {
            cVar1 = *param_8;
            while (cVar1 != '\0') {
              pcVar4 = pcVar4 + 1;
              cVar1 = *pcVar4;
            }
            pcVar4 = pcVar4 + 1;
            iStack_2c = 1;
          }
          for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
          }
          pcVar4 = pcVar4 + 1;
          iStack_2c = iStack_2c + 1;
        }
        for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
        }
        pcVar4 = pcVar4 + 1;
        iStack_2c = iStack_2c + 1;
        if ((int)uVar9 <= iStack_2c) goto code_r0x0010e6ee;
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
        iStack_2c = iStack_2c + 4;
      } while (iStack_2c < (int)uVar9);
    }
code_r0x0010e6ee:
    iVar10 = func_0x0007e7e4(pcVar4);
    if (iVar10 == 0) {
LAB_0010e8b5:
      *pfVar13 = 0.0;
    }
    else {
      fVar6 = (float)(*DAT_001a7f4c)(pcVar4);
      *pfVar13 = fVar6;
      if ((fVar6 != 0.0) && (param_1[2] != 0)) {
        if (*piVar2 == 0x10) {
          iVar10 = *(int *)(gpGlobals + 0x98);
          pcVar7 = g_engfuncs;
        }
        else {
          if (*piVar2 != 0x11) break;
          iVar10 = *(int *)(gpGlobals + 0x98);
          pcVar7 = DAT_001a7e44;
        }
        (*pcVar7)((int)fVar6 + iVar10);
      }
    }
    break;
  case 2:
    iVar10 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*pfVar11);
    if (iVar10 == 0) goto LAB_0010e8b5;
    fVar6 = (float)(*DAT_001a7f58)(iVar10);
    *pfVar13 = fVar6;
    break;
  case 3:
    iVar10 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*pfVar11);
    if (iVar10 == 0) goto LAB_0010e8b5;
    *pfVar13 = *(float *)(iVar10 + 0x7c);
    break;
  case 4:
    iVar10 = *(int *)(gSizes + *piVar2 * 4);
    iVar3 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*pfVar11);
    if (iVar3 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = *(undefined4 *)(iVar3 + 0x7c);
    }
    __as__7EHANDLEP11CBaseEntity((float *)((int)pfVar13 + (8 - iVar10) * uVar9),uVar14);
    break;
  case 5:
    iVar10 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*pfVar11);
    if (iVar10 == 0) goto LAB_0010e8b5;
    *pfVar13 = (float)(iVar10 + 0x80);
    break;
  case 6:
    fVar6 = (float)EntityFromIndex__18CSaveRestoreBufferi(param_1,*pfVar11);
    *pfVar13 = fVar6;
    break;
  case 7:
    *pfVar13 = *pfVar11;
    pfVar13[1] = pfVar11[1];
    pfVar13[2] = pfVar11[2];
    break;
  case 8:
    *pfVar13 = *pfVar11 + local_c;
    pfVar13[1] = pfVar11[1] + local_8;
    pfVar13[2] = pfVar11[2] + local_4;
    break;
  case 9:
  case 10:
  case 0xc:
    *pfVar13 = *pfVar11;
    break;
  case 0xb:
    iVar10 = func_0x0007e7e4(pfVar11);
    if (iVar10 == 0) goto LAB_0010e8b5;
    fVar6 = (float)(*pcRam001a7f78)(pfVar11);
    *pfVar13 = fVar6;
    break;
  case 0xd:
    *(undefined2 *)pfVar13 = *(undefined2 *)pfVar11;
    break;
  case 0xe:
    *(undefined1 *)pfVar13 = *(undefined1 *)pfVar11;
    break;
  case 0xf:
    *pfVar13 = local_24 + *pfVar11;
    break;
  default:
    (*DAT_001a7f34)(4,"Bad field type\n");
  }
  uVar9 = uVar9 + 1;
  if ((int)(short)piVar2[3] <= (int)uVar9) {
    return iVar8;
  }
  goto LAB_0010e5c8;
}


