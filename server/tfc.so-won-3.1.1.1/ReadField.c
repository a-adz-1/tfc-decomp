// ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1  @ 00120010
int ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1
              (int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
              char *param_7,char *param_8)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  char *__s;
  size_t sVar4;
  float fVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  float *__s_00;
  float *pfVar9;
  int local_34;
  float local_28;
  int local_20;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = 0.0;
  local_c = 0.0;
  local_8 = 0.0;
  local_28 = 0.0;
  iVar8 = *param_1;
  if ((iVar8 != 0) && (local_28 = *(float *)(iVar8 + 0x550), *(int *)(iVar8 + 0x52c) != 0)) {
    local_10 = *(float *)(iVar8 + 0x544);
    local_c = *(float *)(iVar8 + 0x548);
    local_8 = *(float *)(iVar8 + 0x54c);
  }
  iVar8 = 0;
  if (0 < param_4) {
    do {
      iVar7 = (param_5 + iVar8) % param_4;
      piVar2 = (int *)(iVar7 * 0x10 + param_3);
      iVar3 = strcasecmp((char *)piVar2[1],param_7);
      if (iVar3 == 0) {
        if ((param_1[1] != 0) && (((*(byte *)((int)piVar2 + 0xe) ^ 1) & 1) == 0)) {
          return iVar7;
        }
        local_20 = 0;
        if ((short)piVar2[3] < 1) {
          return iVar7;
        }
        goto LAB_001200f4;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_4);
  }
  return -1;
LAB_001200f4:
  iVar8 = *piVar2;
  pfVar9 = (float *)(param_2 + piVar2[2] + local_20 * *(int *)(gSizes + iVar8 * 4));
  __s_00 = (float *)(param_8 + local_20 * *(int *)(gSizes + iVar8 * 4));
  switch(iVar8) {
  case 0:
    *pfVar9 = *__s_00;
    break;
  case 1:
  case 0x10:
  case 0x11:
    iVar8 = 0;
    __s = param_8;
    if (0 < local_20) {
      do {
        for (; *__s != '\0'; __s = __s + 1) {
        }
        __s = __s + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < local_20);
    }
    sVar4 = strlen(__s);
    if (sVar4 == 0) goto LAB_00120468;
    fVar5 = (float)(*DAT_0019f7ac)(__s);
    *pfVar9 = fVar5;
    if ((fVar5 != 0.0) && (param_1[2] != 0)) {
      if (*piVar2 == 0x10) {
        iVar8 = *(int *)(gpGlobals + 0x98);
        pcVar6 = g_engfuncs;
      }
      else {
        if (*piVar2 != 0x11) break;
        iVar8 = *(int *)(gpGlobals + 0x98);
        pcVar6 = DAT_0019f6a4;
      }
      (*pcVar6)((int)fVar5 + iVar8);
    }
    break;
  case 2:
    iVar8 = *param_1;
    if ((iVar8 != 0) && (-1 < (int)*__s_00)) {
      local_34 = 0;
      if (0 < *(int *)(iVar8 + 0x20)) {
        do {
          pfVar1 = (float *)(*(int *)(iVar8 + 0x28) + local_34 * 0x18);
          if (*pfVar1 == *__s_00) {
            fVar5 = pfVar1[1];
            goto LAB_00120446;
          }
          local_34 = local_34 + 1;
        } while (local_34 < *(int *)(iVar8 + 0x20));
      }
      fVar5 = 0.0;
LAB_00120446:
      if (fVar5 != 0.0) {
        fVar5 = (float)(*DAT_0019f7b8)(fVar5);
        *pfVar9 = fVar5;
        break;
      }
    }
    goto LAB_00120468;
  case 3:
    iVar8 = *param_1;
    if ((iVar8 != 0) && (-1 < (int)*__s_00)) {
      local_34 = 0;
      if (0 < *(int *)(iVar8 + 0x20)) {
        do {
          pfVar1 = (float *)(*(int *)(iVar8 + 0x28) + local_34 * 0x18);
          if (*pfVar1 == *__s_00) {
            fVar5 = pfVar1[1];
            goto LAB_00120306;
          }
          local_34 = local_34 + 1;
        } while (local_34 < *(int *)(iVar8 + 0x20));
      }
      fVar5 = 0.0;
LAB_00120306:
      if (fVar5 != 0.0) {
        *pfVar9 = *(float *)((int)fVar5 + 0x7c);
        break;
      }
    }
LAB_001204f1:
    *pfVar9 = 0.0;
    break;
  case 4:
    pfVar9 = (float *)((int)pfVar9 + (8 - *(int *)(gSizes + iVar8 * 4)) * local_20);
    iVar8 = *param_1;
    if ((iVar8 != 0) && (-1 < (int)*__s_00)) {
      local_34 = 0;
      if (0 < *(int *)(iVar8 + 0x20)) {
        do {
          pfVar1 = (float *)(*(int *)(iVar8 + 0x28) + local_34 * 0x18);
          if (*pfVar1 == *__s_00) {
            fVar5 = pfVar1[1];
            goto LAB_001203d2;
          }
          local_34 = local_34 + 1;
        } while (local_34 < *(int *)(iVar8 + 0x20));
      }
      fVar5 = 0.0;
LAB_001203d2:
      if (fVar5 != 0.0) {
        __as__7EHANDLEP11CBaseEntity(pfVar9,*(undefined4 *)((int)fVar5 + 0x7c));
        break;
      }
    }
    __as__7EHANDLEP11CBaseEntity(pfVar9,0);
    break;
  case 5:
    iVar8 = *param_1;
    if ((iVar8 != 0) && (-1 < (int)*__s_00)) {
      local_34 = 0;
      if (0 < *(int *)(iVar8 + 0x20)) {
        do {
          pfVar1 = (float *)(*(int *)(iVar8 + 0x28) + local_34 * 0x18);
          if (*pfVar1 == *__s_00) {
            fVar5 = pfVar1[1];
            goto LAB_0012029e;
          }
          local_34 = local_34 + 1;
        } while (local_34 < *(int *)(iVar8 + 0x20));
      }
      fVar5 = 0.0;
LAB_0012029e:
      if (fVar5 != 0.0) {
        *pfVar9 = (float)((int)fVar5 + 0x80);
        break;
      }
    }
LAB_00120468:
    *pfVar9 = 0.0;
    break;
  case 6:
    iVar8 = *param_1;
    if ((iVar8 != 0) && (-1 < (int)*__s_00)) {
      local_34 = 0;
      if (0 < *(int *)(iVar8 + 0x20)) {
        do {
          pfVar1 = (float *)(*(int *)(iVar8 + 0x28) + local_34 * 0x18);
          if (*pfVar1 == *__s_00) {
            fVar5 = pfVar1[1];
            goto LAB_0012036a;
          }
          local_34 = local_34 + 1;
        } while (local_34 < *(int *)(iVar8 + 0x20));
      }
    }
    fVar5 = 0.0;
LAB_0012036a:
    *pfVar9 = fVar5;
    break;
  case 7:
    *pfVar9 = *__s_00;
    pfVar9[1] = __s_00[1];
    pfVar9[2] = __s_00[2];
    break;
  case 8:
    *pfVar9 = *__s_00 + local_10;
    pfVar9[1] = __s_00[1] + local_c;
    pfVar9[2] = __s_00[2] + local_8;
    break;
  case 9:
    *pfVar9 = *__s_00;
    break;
  case 10:
  case 0xc:
    *pfVar9 = *__s_00;
    break;
  case 0xb:
    sVar4 = strlen((char *)__s_00);
    if (sVar4 == 0) goto LAB_001204f1;
    fVar5 = (float)(*DAT_0019f7d8)(__s_00);
    *pfVar9 = fVar5;
    break;
  case 0xd:
    *(undefined2 *)pfVar9 = *(undefined2 *)__s_00;
    break;
  case 0xe:
    *(undefined1 *)pfVar9 = *(undefined1 *)__s_00;
    break;
  case 0xf:
    *pfVar9 = local_28 + *__s_00;
    break;
  default:
    (*DAT_0019f794)(4,"Bad field type\n");
  }
  local_20 = local_20 + 1;
  if ((short)piVar2[3] <= local_20) {
    return iVar7;
  }
  goto LAB_001200f4;
}


