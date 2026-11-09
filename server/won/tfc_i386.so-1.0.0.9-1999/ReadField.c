// ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1  @ 00119a10
int ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1
              (int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
              char *param_7,char *param_8)

{
  float *pfVar1;
  int iVar2;
  char *__s;
  size_t sVar3;
  float fVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  float *__s_00;
  int *piVar8;
  undefined4 uVar9;
  float local_28;
  int local_20;
  float local_10;
  float local_c;
  float local_8;
  
  local_28 = 0.0;
  local_10 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  if (*param_1 != 0) {
    iVar7 = *param_1;
    local_28 = *(float *)(iVar7 + 0x550);
    if (*(int *)(iVar7 + 0x52c) != 0) {
      local_10 = *(float *)(iVar7 + 0x544);
      local_c = *(float *)(iVar7 + 0x548);
      local_8 = *(float *)(iVar7 + 0x54c);
    }
  }
  iVar7 = 0;
  if (0 < param_4) {
    do {
      iVar6 = (param_5 + iVar7) % param_4;
      piVar8 = (int *)(param_3 + iVar6 * 0x10);
      iVar2 = strcasecmp((char *)piVar8[1],param_7);
      if (iVar2 == 0) {
        if ((param_1[1] != 0) && (((*(byte *)((int)piVar8 + 0xe) ^ 1) & 1) == 0)) {
          return iVar6;
        }
        local_20 = 0;
        if ((short)piVar8[3] < 1) {
          return iVar6;
        }
        goto LAB_00119ae4;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_4);
  }
  return -1;
LAB_00119ae4:
  pfVar1 = (float *)(local_20 * *(int *)(gSizes + *piVar8 * 4) + param_2 + piVar8[2]);
  __s_00 = (float *)(param_8 + local_20 * *(int *)(gSizes + *piVar8 * 4));
  switch(*piVar8) {
  case 0:
    *pfVar1 = *__s_00;
    break;
  case 1:
  case 0x10:
  case 0x11:
    iVar7 = 0;
    __s = param_8;
    if (0 < local_20) {
      do {
        for (; *__s != '\0'; __s = __s + 1) {
        }
        __s = __s + 1;
        iVar7 = iVar7 + 1;
      } while (iVar7 < local_20);
    }
    sVar3 = strlen(__s);
    if (sVar3 == 0) {
LAB_00119d4d:
      *pfVar1 = 0.0;
    }
    else {
      fVar4 = (float)(*DAT_001755cc)(__s);
      *pfVar1 = fVar4;
      if ((fVar4 != 0.0) && (param_1[2] != 0)) {
        if (*piVar8 == 0x10) {
          iVar7 = *(int *)(gpGlobals + 0x98);
          pcVar5 = g_engfuncs;
        }
        else {
          if (*piVar8 != 0x11) break;
          iVar7 = *(int *)(gpGlobals + 0x98);
          pcVar5 = DAT_001754c4;
        }
        (*pcVar5)((int)fVar4 + iVar7);
      }
    }
    break;
  case 2:
    iVar7 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s_00);
    if (iVar7 == 0) goto LAB_00119d4d;
    fVar4 = (float)(*DAT_001755d8)(iVar7);
    *pfVar1 = fVar4;
    break;
  case 3:
    iVar7 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s_00);
    if (iVar7 == 0) goto LAB_00119d4d;
    *pfVar1 = *(float *)(iVar7 + 0xd8);
    break;
  case 4:
    iVar7 = *(int *)(gSizes + *piVar8 * 4);
    iVar2 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s_00);
    if (iVar2 == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = *(undefined4 *)(iVar2 + 0xd8);
    }
    __as__7EHANDLEP11CBaseEntity((float *)((int)pfVar1 + (8 - iVar7) * local_20),uVar9);
    break;
  case 5:
    iVar7 = EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s_00);
    if (iVar7 == 0) goto LAB_00119d4d;
    *pfVar1 = (float)(iVar7 + 0xdc);
    break;
  case 6:
    fVar4 = (float)EntityFromIndex__18CSaveRestoreBufferi(param_1,*__s_00);
    *pfVar1 = fVar4;
    break;
  case 7:
    *pfVar1 = *__s_00;
    pfVar1[1] = __s_00[1];
    pfVar1[2] = __s_00[2];
    break;
  case 8:
    *pfVar1 = *__s_00 + local_10;
    pfVar1[1] = __s_00[1] + local_c;
    pfVar1[2] = __s_00[2] + local_8;
    break;
  case 9:
  case 10:
  case 0xc:
    *pfVar1 = *__s_00;
    break;
  case 0xb:
    sVar3 = strlen((char *)__s_00);
    if (sVar3 == 0) goto LAB_00119d4d;
    fVar4 = (float)(*DAT_001755f8)(__s_00);
    *pfVar1 = fVar4;
    break;
  case 0xd:
    *(undefined2 *)pfVar1 = *(undefined2 *)__s_00;
    break;
  case 0xe:
    *(undefined1 *)pfVar1 = *(undefined1 *)__s_00;
    break;
  case 0xf:
    *pfVar1 = local_28 + *__s_00;
    break;
  default:
    (*DAT_001755b4)(4,"Bad field type\n");
  }
  local_20 = local_20 + 1;
  if ((short)piVar8[3] <= local_20) {
    return iVar6;
  }
  goto LAB_00119ae4;
}


