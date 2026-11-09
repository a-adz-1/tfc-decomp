// CM_CalcPAS  @ 0804d8f0
void CM_CalcPAS(int param_1)

{
  size_t __size;
  uint *puVar1;
  byte bVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  void *__dest;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_2c;
  int local_1c;
  int local_18;
  void *local_14;
  int local_c;
  
  Con_DPrintf("Building PAS...\n");
  CM_FreePAS();
  __size = *(int *)(param_1 + 0x88) + 1;
  iVar4 = *(int *)(param_1 + 0x88) + 7 >> 3;
  uVar5 = iVar4 + 3;
  gPVSRowBytes = uVar5 & 0xfffffffc;
  iVar8 = (int)uVar5 >> 2;
  gPVS = calloc(gPVSRowBytes,__size);
  local_1c = 0;
  local_c = 0;
  local_14 = gPVS;
  if (0 < (int)__size) {
    do {
      CM_DecompressPVS(*(undefined4 *)(*(int *)(param_1 + 0x8c) + 0x18 + local_c * 0x30),local_14,
                       iVar4);
      if ((local_c != 0) && (uVar5 = 0, 0 < (int)__size)) {
        do {
          if ((*(byte *)(((int)uVar5 >> 3) + (int)local_14) >> (uVar5 & 7) & 1) != 0) {
            local_1c = local_1c + 1;
          }
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < (int)__size);
      }
      local_c = local_c + 1;
      local_14 = (void *)((int)local_14 + gPVSRowBytes);
    } while (local_c < (int)__size);
  }
  __dest = calloc(gPVSRowBytes,__size);
  local_18 = 0;
  local_14 = gPVS;
  local_c = 0;
  gPAS = __dest;
  if (0 < (int)__size) {
    do {
      memcpy(__dest,local_14,gPVSRowBytes);
      iVar4 = 0;
      if (0 < (int)gPVSRowBytes) {
        do {
          pvVar3 = gPVS;
          bVar2 = *(byte *)(iVar4 + (int)local_14);
          if (bVar2 != 0) {
            local_2c = 0;
            do {
              if ((((bVar2 >> (local_2c & 0x1f) & 1) != 0) &&
                  (iVar6 = local_2c + 1 + iVar4 * 8, iVar6 < (int)__size)) && (0 < iVar6)) {
                iVar6 = iVar6 * gPVSRowBytes;
                iVar7 = 0;
                if (0 < iVar8) {
                  do {
                    puVar1 = (uint *)((int)__dest + iVar7 * 4);
                    *puVar1 = *puVar1 | *(uint *)((int)pvVar3 + iVar7 * 4 + iVar6);
                    iVar7 = iVar7 + 1;
                  } while (iVar7 < iVar8);
                }
              }
              local_2c = local_2c + 1;
            } while ((int)local_2c < 8);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)gPVSRowBytes);
      }
      if ((local_c != 0) && (uVar5 = 0, 0 < (int)__size)) {
        do {
          if ((*(byte *)(((int)uVar5 >> 3) + (int)__dest) >> (uVar5 & 7) & 1) != 0) {
            local_18 = local_18 + 1;
          }
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < (int)__size);
      }
      local_c = local_c + 1;
      __dest = (void *)((int)__dest + iVar8 * 4);
      local_14 = (void *)((int)local_14 + gPVSRowBytes);
    } while (local_c < (int)__size);
  }
  Con_DPrintf("Average leaves visible / audible / total: %i / %i / %i\n",local_1c / (int)__size,
              local_18 / (int)__size,__size);
  return;
}


// CM_DecompressPVS  @ 0804d7e0
void CM_DecompressPVS(char *param_1,char *param_2,size_t param_3)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    memcpy(param_2,mod_novis,param_3);
  }
  else {
    pcVar3 = param_2 + param_3;
    do {
      if (*param_1 == '\0') {
        pbVar1 = (byte *)(param_1 + 1);
        param_1 = param_1 + 2;
        for (uVar2 = (uint)*pbVar1; uVar2 != 0; uVar2 = uVar2 - 1) {
          *param_2 = '\0';
          param_2 = param_2 + 1;
        }
      }
      else {
        *param_2 = *param_1;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
    } while (param_2 < pcVar3);
  }
  return;
}


// CM_FreePAS  @ 0804d8a0
void CM_FreePAS(void)

{
  if (gPAS != (void *)0x0) {
    free(gPAS);
  }
  if (gPVS != (void *)0x0) {
    free(gPVS);
  }
  gPAS = (void *)0x0;
  gPVS = (void *)0x0;
  return;
}


// CM_HeadnodeVisible  @ 0804db00
undefined4 CM_HeadnodeVisible(int *param_1,int param_2)

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
      uVar1 = (((int)param_1 - *(int *)(DAT_0811d320 + 0x8c)) * -0x55555555 >> 4) - 1;
      if ((*(byte *)(((int)uVar1 >> 3) + param_2) >> (uVar1 & 7) & 1) == 0) {
        return 0;
      }
      return 1;
    }
    iVar2 = CM_HeadnodeVisible(param_1[7],param_2);
    if (iVar2 != 0) break;
    param_1 = (int *)param_1[8];
  }
  return 1;
}


// CM_LeafPAS  @ 0804d870
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


// CM_LeafPVS  @ 0804d840
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


