// CM_CalcPAS  @ 00048ad0
void CM_CalcPAS(int param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint local_38;
  uint *local_34;
  int local_2c;
  int local_28;
  byte *local_24;
  uint *local_20;
  uint local_14;
  int local_10;
  
  Con_DPrintf("Building PAS...\n");
  CM_FreePAS();
  uVar1 = *(int *)(param_1 + 0x88) + 1;
  iVar4 = *(int *)(param_1 + 0x88) + 7 >> 3;
  uVar5 = iVar4 + 3;
  gPVSRowBytes = uVar5 & 0xfffffffc;
  uVar5 = (int)uVar5 >> 2;
  local_24 = (byte *)Mem_Calloc(gPVSRowBytes,uVar1);
  local_2c = 0;
  local_10 = 0;
  gPVS = local_24;
  if (0 < (int)uVar1) {
    local_38 = 0;
    do {
      CM_DecompressPVS(*(undefined4 *)(*(int *)(param_1 + 0x8c) + 0x18 + local_38),local_24,iVar4);
      if ((local_10 != 0) && (uVar8 = 0, 0 < (int)uVar1)) {
        uVar6 = uVar1 & 3;
        if (uVar6 != 0) {
          if (1 < uVar6) {
            if (2 < uVar6) {
              if ((*local_24 & 1) != 0) {
                local_2c = local_2c + 1;
              }
              uVar8 = 1;
            }
            if ((*local_24 >> uVar8 & 1) != 0) {
              local_2c = local_2c + 1;
            }
            uVar8 = uVar8 + 1;
          }
          if ((*local_24 >> uVar8 & 1) != 0) {
            local_2c = local_2c + 1;
          }
          uVar8 = uVar8 + 1;
          if ((int)uVar1 <= (int)uVar8) goto LAB_00048c6b;
        }
        do {
          if ((local_24[(int)uVar8 >> 3] >> (uVar8 & 7) & 1) != 0) {
            local_2c = local_2c + 1;
          }
          if ((local_24[(int)(uVar8 + 1) >> 3] >> (uVar8 + 1 & 7) & 1) != 0) {
            local_2c = local_2c + 1;
          }
          if ((local_24[(int)(uVar8 + 2) >> 3] >> (uVar8 + 2 & 7) & 1) != 0) {
            local_2c = local_2c + 1;
          }
          if ((local_24[(int)(uVar8 + 3) >> 3] >> (uVar8 + 3 & 7) & 1) != 0) {
            local_2c = local_2c + 1;
          }
          uVar8 = uVar8 + 4;
        } while ((int)uVar8 < (int)uVar1);
      }
LAB_00048c6b:
      local_38 = local_38 + 0x30;
      local_10 = local_10 + 1;
      local_24 = local_24 + gPVSRowBytes;
    } while (local_10 < (int)uVar1);
  }
  local_20 = (uint *)Mem_Calloc(gPVSRowBytes,uVar1);
  local_28 = 0;
  local_24 = gPVS;
  local_10 = 0;
  gPAS = local_20;
  if (0 < (int)uVar1) {
    do {
      Q_memcpy(local_20,local_24,gPVSRowBytes);
      for (iVar4 = 0; iVar4 < (int)gPVSRowBytes; iVar4 = iVar4 + 1) {
        bVar3 = local_24[iVar4];
        if (bVar3 != 0) {
          local_14 = 0;
          do {
            if ((((bVar3 >> (local_14 & 0x1f) & 1) != 0) &&
                (iVar2 = local_14 + 1 + iVar4 * 8, iVar2 < (int)uVar1)) && (0 < iVar2)) {
              local_34 = (uint *)(gPVS + iVar2 * gPVSRowBytes);
              local_38 = 0;
              if (0 < (int)uVar5) {
                uVar8 = uVar5 & 3;
                puVar7 = local_20;
                if (uVar8 != 0) {
                  if (1 < uVar8) {
                    if (2 < uVar8) {
                      *local_20 = *local_20 | *local_34;
                      puVar7 = local_20 + 1;
                      local_34 = local_34 + 1;
                    }
                    local_38 = (uint)(2 < uVar8);
                    *puVar7 = *puVar7 | *local_34;
                    puVar7 = puVar7 + 1;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + 1;
                  }
                  *puVar7 = *puVar7 | *local_34;
                  puVar7 = puVar7 + 1;
                  local_34 = local_34 + 1;
                  local_38 = local_38 + 1;
                  if ((int)uVar5 <= (int)local_38) goto LAB_00048dd5;
                }
                do {
                  *puVar7 = *puVar7 | *local_34;
                  puVar7[1] = puVar7[1] | local_34[1];
                  puVar7[2] = puVar7[2] | local_34[2];
                  puVar7[3] = puVar7[3] | local_34[3];
                  puVar7 = puVar7 + 4;
                  local_34 = local_34 + 4;
                  local_38 = local_38 + 4;
                } while ((int)local_38 < (int)uVar5);
              }
            }
LAB_00048dd5:
            local_14 = local_14 + 1;
          } while ((int)local_14 < 8);
        }
      }
      if ((local_10 != 0) && (uVar8 = 0, 0 < (int)uVar1)) {
        uVar6 = uVar1 & 3;
        if (uVar6 != 0) {
          if (1 < uVar6) {
            if (2 < uVar6) {
              if ((*local_20 & 1) != 0) {
                local_28 = local_28 + 1;
              }
              uVar8 = 1;
            }
            if (((byte)*local_20 >> uVar8 & 1) != 0) {
              local_28 = local_28 + 1;
            }
            uVar8 = uVar8 + 1;
          }
          if (((byte)*local_20 >> uVar8 & 1) != 0) {
            local_28 = local_28 + 1;
          }
          uVar8 = uVar8 + 1;
          if ((int)uVar1 <= (int)uVar8) goto LAB_00048eeb;
        }
        do {
          if ((*(byte *)(((int)uVar8 >> 3) + (int)local_20) >> (uVar8 & 7) & 1) != 0) {
            local_28 = local_28 + 1;
          }
          if ((*(byte *)(((int)(uVar8 + 1) >> 3) + (int)local_20) >> (uVar8 + 1 & 7) & 1) != 0) {
            local_28 = local_28 + 1;
          }
          if ((*(byte *)(((int)(uVar8 + 2) >> 3) + (int)local_20) >> (uVar8 + 2 & 7) & 1) != 0) {
            local_28 = local_28 + 1;
          }
          if ((*(byte *)(((int)(uVar8 + 3) >> 3) + (int)local_20) >> (uVar8 + 3 & 7) & 1) != 0) {
            local_28 = local_28 + 1;
          }
          uVar8 = uVar8 + 4;
        } while ((int)uVar8 < (int)uVar1);
      }
LAB_00048eeb:
      local_10 = local_10 + 1;
      local_20 = local_20 + uVar5;
      local_24 = local_24 + gPVSRowBytes;
    } while (local_10 < (int)uVar1);
  }
  Con_DPrintf("Average leaves visible / audible / total: %i / %i / %i\n",local_2c / (int)uVar1,
              local_28 / (int)uVar1,uVar1);
  return;
}


// CM_DecompressPVS  @ 00048978
void CM_DecompressPVS(char *param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    Q_memcpy(param_2,mod_novis,param_3);
  }
  else {
    pcVar3 = param_2 + param_3;
    do {
      if (*param_1 == '\0') {
        uVar2 = (uint)(byte)param_1[1];
        param_1 = param_1 + 2;
        if (uVar2 != 0) {
          uVar1 = -uVar2 & 3;
          if (uVar1 != 0) {
            if (uVar1 < 3) {
              if (uVar1 < 2) {
                *param_2 = '\0';
                param_2 = param_2 + 1;
                uVar2 = uVar2 - 1;
              }
              *param_2 = '\0';
              param_2 = param_2 + 1;
              uVar2 = uVar2 - 1;
            }
            *param_2 = '\0';
            param_2 = param_2 + 1;
            uVar2 = uVar2 - 1;
            if (uVar2 == 0) goto LAB_000489ff;
          }
          do {
            *param_2 = '\0';
            param_2[1] = '\0';
            param_2[2] = '\0';
            param_2[3] = '\0';
            param_2 = param_2 + 4;
            uVar2 = uVar2 - 4;
          } while (uVar2 != 0);
        }
      }
      else {
        *param_2 = *param_1;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
LAB_000489ff:
    } while (param_2 < pcVar3);
  }
  return;
}


// CM_FreePAS  @ 00048a80
void CM_FreePAS(void)

{
  if (gPAS != 0) {
    Mem_Free(gPAS);
  }
  if (gPVS != 0) {
    Mem_Free(gPVS);
  }
  gPAS = 0;
  gPVS = 0;
  return;
}


// CM_HeadnodeVisible  @ 00048f30
undefined4 CM_HeadnodeVisible(int *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  
  while( true ) {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    if (*param_1 == -2) {
      return 0;
    }
    if (*param_1 < 0) {
      uVar1 = (((int)param_1 - *(int *)(DAT_00153668 + 0x8c)) * -0x55555555 >> 4) - 1;
      if ((*(byte *)(((int)uVar1 >> 3) + param_2) >> (uVar1 & 7) & 1) == 0) {
        return 0;
      }
      if (param_3 != (uint *)0x0) {
        *param_3 = uVar1;
      }
      return 1;
    }
    iVar2 = CM_HeadnodeVisible(param_1[7],param_2,param_3);
    if (iVar2 != 0) break;
    param_1 = (int *)param_1[8];
  }
  return 1;
}


// CM_LeafPAS  @ 00048a48
undefined1 * CM_LeafPAS(int param_1)

{
  undefined1 *puVar1;
  
  if (gPAS == 0) {
    puVar1 = mod_novis;
  }
  else {
    puVar1 = (undefined1 *)(param_1 * gPVSRowBytes + gPAS);
  }
  return puVar1;
}


// CM_LeafPVS  @ 00048a10
undefined1 * CM_LeafPVS(int param_1)

{
  undefined1 *puVar1;
  
  if (gPVS == 0) {
    puVar1 = mod_novis;
  }
  else {
    puVar1 = (undefined1 *)(param_1 * gPVSRowBytes + gPVS);
  }
  return puVar1;
}


