// WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi  @ 0011f81c
undefined4
WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
          (int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  uint *puVar2;
  float *pfVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  float *pfVar9;
  float *pfVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  char *pcVar14;
  int iVar15;
  float *local_188;
  int local_158;
  float local_154;
  int local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  int local_104 [64];
  
  iVar15 = 0;
  for (local_158 = 0; local_158 < param_5; local_158 = local_158 + 1) {
    iVar12 = local_158 * 0x10;
    iVar12 = DataEmpty__5CSavePCci
                       (param_1,param_3 + *(int *)(param_4 + 8 + iVar12),
                        (int)*(short *)(param_4 + 0xc + iVar12) *
                        *(int *)(gSizes + *(int *)(param_4 + iVar12) * 4));
    if (iVar12 != 0) {
      iVar15 = iVar15 + 1;
    }
  }
  local_150 = param_5 - iVar15;
  BufferField__5CSavePCciT1(param_1,param_2,4,&local_150);
  local_158 = 0;
  if (0 < param_5) {
    do {
      piVar4 = (int *)(local_158 * 0x10 + param_4);
      pfVar9 = (float *)(param_3 + piVar4[2]);
      iVar15 = DataEmpty__5CSavePCci
                         (param_1,pfVar9,(int)(short)piVar4[3] * *(int *)(gSizes + *piVar4 * 4));
      if (iVar15 != 0) goto LAB_0011ffe6;
      switch(*piVar4) {
      case 0:
        iVar15 = piVar4[1];
        iVar12 = (int)(short)piVar4[3] << 2;
        break;
      case 1:
      case 0x10:
      case 0x11:
        iVar12 = 0;
        iVar15 = (int)(short)piVar4[3];
        local_188 = (float *)0x0;
        if (0 < iVar15) {
          do {
            pfVar3 = pfVar9 + iVar12;
            iVar12 = iVar12 + 1;
            puVar13 = (uint *)((int)*pfVar3 + *(int *)(gpGlobals + 0x98));
            uVar11 = (uint)puVar13 & 3;
            puVar2 = puVar13;
            if (uVar11 == 0) {
LAB_0011fadb:
              do {
                puVar5 = puVar2;
                uVar11 = *puVar5;
                if ((char)uVar11 == '\0') goto LAB_0011fafd;
                if ((char)(uVar11 >> 8) == '\0') goto LAB_0011fafc;
                if ((uVar11 & 0xff0000) == 0) goto LAB_0011fafb;
                puVar2 = puVar5 + 1;
              } while ((uVar11 & 0xff000000) != 0);
              puVar5 = (uint *)((int)puVar5 + 1);
LAB_0011fafb:
              puVar5 = (uint *)((int)puVar5 + 1);
LAB_0011fafc:
              puVar5 = (uint *)((int)puVar5 + 1);
            }
            else {
              puVar5 = puVar13;
              if ((POPCOUNT(uVar11) & 1U) == 0) {
LAB_0011fad6:
                if ((char)*puVar5 != '\0') {
                  puVar2 = (uint *)((int)puVar5 + 1);
                  goto LAB_0011fadb;
                }
              }
              else if (uVar11 == 2) {
LAB_0011fad1:
                if ((char)*puVar5 != '\0') {
                  puVar5 = (uint *)((int)puVar5 + 1);
                  goto LAB_0011fad6;
                }
              }
              else if ((char)*puVar13 != '\0') {
                puVar5 = (uint *)((int)puVar13 + 1);
                goto LAB_0011fad1;
              }
            }
LAB_0011fafd:
            local_188 = (float *)((int)puVar5 + (int)((int)local_188 + (1 - (int)puVar13)));
          } while (iVar12 < iVar15);
        }
        BufferHeader__5CSavePCci(param_1,piVar4[1],local_188);
        if (0 < iVar15) {
          iVar12 = 0;
          do {
            puVar13 = (uint *)((int)pfVar9[iVar12] + *(int *)(gpGlobals + 0x98));
            uVar11 = (uint)puVar13 & 3;
            puVar2 = puVar13;
            if (uVar11 == 0) {
LAB_0011fb7a:
              do {
                puVar5 = puVar2;
                uVar11 = *puVar5;
                if ((char)uVar11 == '\0') goto LAB_0011fb9c;
                if ((char)(uVar11 >> 8) == '\0') goto LAB_0011fb9b;
                if ((uVar11 & 0xff0000) == 0) goto LAB_0011fb9a;
                puVar2 = puVar5 + 1;
              } while ((uVar11 & 0xff000000) != 0);
              puVar5 = (uint *)((int)puVar5 + 1);
LAB_0011fb9a:
              puVar5 = (uint *)((int)puVar5 + 1);
LAB_0011fb9b:
              puVar5 = (uint *)((int)puVar5 + 1);
            }
            else {
              puVar5 = puVar13;
              if ((POPCOUNT(uVar11) & 1U) == 0) {
LAB_0011fb75:
                if ((char)*puVar5 != '\0') {
                  puVar2 = (uint *)((int)puVar5 + 1);
                  goto LAB_0011fb7a;
                }
              }
              else if (uVar11 == 2) {
LAB_0011fb70:
                if ((char)*puVar5 != '\0') {
                  puVar5 = (uint *)((int)puVar5 + 1);
                  goto LAB_0011fb75;
                }
              }
              else if ((char)*puVar13 != '\0') {
                puVar5 = (uint *)((int)puVar13 + 1);
                goto LAB_0011fb70;
              }
            }
LAB_0011fb9c:
            BufferData__5CSavePCci(param_1,puVar13,(char *)((int)puVar5 + (1 - (int)puVar13)));
            iVar12 = iVar12 + 1;
          } while (iVar12 < iVar15);
        }
        goto LAB_0011ffe6;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        if (0x40 < (short)piVar4[3]) {
          (*DAT_0019f794)(4,"Can\'t save more than %d entities in an array!!!\n",0x40);
        }
        iVar15 = (int)(short)piVar4[3];
        if (iVar15 < 1) goto LAB_0011fd65;
        iVar12 = 0;
        goto LAB_0011fc08;
      case 7:
        iVar15 = (short)piVar4[3] * 0xc;
        BufferHeader__5CSavePCci(param_1,piVar4[1],iVar15);
        BufferData__5CSavePCci(param_1,pfVar9,iVar15);
        goto LAB_0011ffe6;
      case 8:
        iVar15 = (int)(short)piVar4[3];
        BufferHeader__5CSavePCci(param_1,piVar4[1],iVar15 * 0xc);
        local_188 = (float *)0x0;
        if (0 < iVar15) {
          do {
            local_140 = *pfVar9;
            local_13c = pfVar9[1];
            local_138 = pfVar9[2];
            iVar12 = *param_1;
            if ((iVar12 != 0) && (*(int *)(iVar12 + 0x52c) != 0)) {
              local_14c = local_140 - *(float *)(iVar12 + 0x544);
              local_148 = local_13c - *(float *)(iVar12 + 0x548);
              local_144 = local_138 - *(float *)(iVar12 + 0x54c);
              local_140 = local_14c;
              local_13c = local_148;
              local_138 = local_144;
            }
            BufferData__5CSavePCci(param_1,&local_140,0xc);
            pfVar9 = pfVar9 + 3;
            local_188 = (float *)((int)local_188 + 1);
          } while ((int)local_188 < iVar15);
        }
        goto LAB_0011ffe6;
      case 9:
        iVar15 = piVar4[1];
        iVar12 = (int)(short)piVar4[3] << 2;
        break;
      case 10:
      case 0xc:
        iVar15 = piVar4[1];
        iVar12 = (int)(short)piVar4[3] << 2;
        break;
      case 0xb:
        iVar15 = piVar4[1];
        pfVar9 = (float *)(*DAT_0019f7dc)(*pfVar9);
        if (pfVar9 == (float *)0x0) {
          pcVar14 = "Invalid function pointer in entity!";
          goto LAB_0011ffd8;
        }
        uVar11 = (uint)pfVar9 & 3;
        pfVar3 = pfVar9;
        if (uVar11 == 0) {
LAB_0011ff85:
          do {
            pfVar10 = pfVar3;
            fVar1 = *pfVar10;
            if (SUB41(fVar1,0) == '\0') goto LAB_0011ffa7;
            if ((char)((uint)fVar1 >> 8) == '\0') goto LAB_0011ffa6;
            if (((uint)fVar1 & 0xff0000) == 0) goto LAB_0011ffa5;
            pfVar3 = pfVar10 + 1;
          } while (((uint)fVar1 & 0xff000000) != 0);
          pfVar10 = (float *)((int)pfVar10 + 1);
LAB_0011ffa5:
          pfVar10 = (float *)((int)pfVar10 + 1);
LAB_0011ffa6:
          pfVar10 = (float *)((int)pfVar10 + 1);
        }
        else {
          pfVar10 = pfVar9;
          if ((POPCOUNT(uVar11) & 1U) == 0) {
LAB_0011ff80:
            if (*(char *)pfVar10 != '\0') {
              pfVar3 = (float *)((int)pfVar10 + 1);
              goto LAB_0011ff85;
            }
          }
          else if (uVar11 == 2) {
LAB_0011ff7b:
            if (*(char *)pfVar10 != '\0') {
              pfVar10 = (float *)((int)pfVar10 + 1);
              goto LAB_0011ff80;
            }
          }
          else if (*(char *)pfVar9 != '\0') {
            pfVar10 = (float *)((int)pfVar9 + 1);
            goto LAB_0011ff7b;
          }
        }
LAB_0011ffa7:
        iVar12 = (int)pfVar10 + (1 - (int)pfVar9);
        break;
      case 0xd:
        iVar15 = piVar4[1];
        iVar12 = (short)piVar4[3] * 2;
        break;
      case 0xe:
        iVar12 = (int)(short)piVar4[3];
        iVar15 = piVar4[1];
        break;
      case 0xf:
        iVar15 = (int)(short)piVar4[3];
        BufferHeader__5CSavePCci(param_1,piVar4[1],iVar15 * 4);
        if (0 < iVar15) {
          iVar12 = 0;
          local_188 = pfVar9;
          do {
            local_154 = *local_188;
            if (*param_1 != 0) {
              local_154 = local_154 - *(float *)(*param_1 + 0x550);
            }
            BufferData__5CSavePCci(param_1,&local_154,4);
            local_188 = local_188 + 1;
            iVar12 = iVar12 + 1;
          } while (iVar12 < iVar15);
        }
        goto LAB_0011ffe6;
      default:
        pcVar14 = "Bad field type\n";
LAB_0011ffd8:
        (*DAT_0019f794)(4,pcVar14);
        goto LAB_0011ffe6;
      }
      BufferField__5CSavePCciT1(param_1,iVar15,iVar12,pfVar9);
LAB_0011ffe6:
      local_158 = local_158 + 1;
    } while (local_158 < param_5);
  }
  return 1;
LAB_0011fc08:
  switch(*piVar4) {
  case 2:
    uVar8 = (*DAT_0019f7b4)(pfVar9[iVar12]);
    iVar15 = EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,uVar8);
    local_104[iVar12] = iVar15;
    goto LAB_0011fd58;
  case 3:
    puVar7 = (undefined4 *)pfVar9[iVar12];
    break;
  case 4:
    puVar7 = (undefined4 *)__opP11CBaseEntity__7EHANDLE(pfVar9 + iVar12 * 2);
    break;
  case 5:
    if (pfVar9[iVar12] == 0.0) goto LAB_0011fcde;
    iVar6 = EntityIndex__18CSaveRestoreBufferP7edict_s
                      (param_1,*(undefined4 *)((int)pfVar9[iVar12] + 0x208));
    goto LAB_0011fd49;
  case 6:
    iVar15 = *param_1;
    if ((iVar15 != 0) && (pfVar9[iVar12] != 0.0)) {
      iVar6 = 0;
      if (0 < *(int *)(iVar15 + 0x20)) {
        do {
          if (*(float *)(*(int *)(iVar15 + 0x28) + 4 + iVar6 * 0x18) == pfVar9[iVar12])
          goto LAB_0011fd49;
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(iVar15 + 0x20));
      }
    }
    goto LAB_0011fcde;
  default:
    goto switchD_0011fc25_default;
  }
  if (puVar7 == (undefined4 *)0x0) {
LAB_0011fcde:
    iVar6 = -1;
  }
  else {
    iVar6 = EntityIndex__18CSaveRestoreBufferP9entvars_s(param_1,*puVar7);
  }
LAB_0011fd49:
  local_104[iVar12] = iVar6;
LAB_0011fd58:
  iVar15 = (int)(short)piVar4[3];
switchD_0011fc25_default:
  iVar12 = iVar12 + 1;
  if (iVar15 <= iVar12) {
LAB_0011fd65:
    uVar8 = FUN_0011ff28();
    return uVar8;
  }
  goto LAB_0011fc08;
}


