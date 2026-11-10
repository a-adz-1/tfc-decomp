// CM_CalcPAS  @ 00055c1c
void CM_CalcPAS(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  Con_DPrintf("Building PAS...\n");
  CM_FreePAS();
  iVar4 = *(int *)(param_1 + 0x88) + 1;
  iVar3 = *(int *)(param_1 + 0x88) + 7 >> 3;
  uVar2 = iVar3 + 3;
  gPVSRowBytes = uVar2 & 0xfffffffc;
  iVar5 = (int)uVar2 >> 2;
  local_34 = Mem_Calloc(gPVSRowBytes,iVar4);
  local_3c = 0;
  gPVS = local_34;
  for (local_10 = 0; local_10 < iVar4; local_10 = local_10 + 1) {
    CM_DecompressPVS(*(undefined4 *)(*(int *)(param_1 + 0x8c) + 0x18 + local_10 * 0x30),local_34,
                     iVar3);
    if (local_10 != 0) {
      for (local_14 = 0; local_14 < iVar4; local_14 = local_14 + 1) {
        if (((int)(uint)*(byte *)((local_14 >> 3) + local_34) >> ((byte)local_14 & 7) & 1U) != 0) {
          local_3c = local_3c + 1;
        }
      }
    }
    local_34 = local_34 + gPVSRowBytes;
  }
  local_2c = Mem_Calloc(gPVSRowBytes,iVar4);
  local_38 = 0;
  local_34 = gPVS;
  gPAS = local_2c;
  for (local_10 = 0; local_10 < iVar4; local_10 = local_10 + 1) {
    Q_memcpy(local_2c,local_34,gPVSRowBytes);
    for (local_14 = 0; local_14 < (int)gPVSRowBytes; local_14 = local_14 + 1) {
      bVar1 = *(byte *)(local_34 + local_14);
      if (bVar1 != 0) {
        for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
          if (((((int)(uint)bVar1 >> ((byte)local_18 & 0x1f) & 1U) != 0) &&
              (iVar3 = local_14 * 8 + local_18 + 1, iVar3 < iVar4)) && (0 < iVar3)) {
            iVar3 = gPVS + iVar3 * gPVSRowBytes;
            for (local_1c = 0; local_1c < iVar5; local_1c = local_1c + 1) {
              *(uint *)(local_2c + local_1c * 4) =
                   *(uint *)(local_2c + local_1c * 4) | *(uint *)(iVar3 + local_1c * 4);
            }
          }
        }
      }
    }
    if (local_10 != 0) {
      for (local_14 = 0; local_14 < iVar4; local_14 = local_14 + 1) {
        if (((int)(uint)*(byte *)((local_14 >> 3) + local_2c) >> ((byte)local_14 & 7) & 1U) != 0) {
          local_38 = local_38 + 1;
        }
      }
    }
    local_2c = local_2c + iVar5 * 4;
    local_34 = local_34 + gPVSRowBytes;
  }
  Con_DPrintf("Average leaves visible / audible / total: %i / %i / %i\n",local_3c / iVar4,
              local_38 / iVar4,iVar4);
  return;
}


// CM_DecompressPVS  @ 00055a90
void CM_DecompressPVS(char *param_1,char *param_2,int param_3)

{
  byte *pbVar1;
  char *local_c;
  uint local_8;
  
  if (param_1 == (char *)0x0) {
    Q_memcpy(param_2,mod_novis,param_3);
  }
  else {
    local_c = param_2;
    do {
      if (*param_1 == '\0') {
        pbVar1 = (byte *)(param_1 + 1);
        param_1 = param_1 + 2;
        for (local_8 = (uint)*pbVar1; local_8 != 0; local_8 = local_8 - 1) {
          *local_c = '\0';
          local_c = local_c + 1;
        }
      }
      else {
        *local_c = *param_1;
        param_1 = param_1 + 1;
        local_c = local_c + 1;
      }
    } while (local_c < param_2 + param_3);
  }
  return;
}


// CM_FreePAS  @ 00055bb8
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


// CM_HeadnodeVisible  @ 00055f70
undefined4 CM_HeadnodeVisible(int *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else if (*param_1 == -2) {
    uVar1 = 0;
  }
  else if (*param_1 < 0) {
    iVar2 = (((int)param_1 - *(int *)(DAT_0036bd88 + 0x8c)) * -0x55555555 >> 4) + -1;
    if (((int)(uint)*(byte *)((iVar2 >> 3) + param_2) >> ((byte)iVar2 & 7) & 1U) == 0) {
      uVar1 = 0;
    }
    else {
      if (param_3 != (int *)0x0) {
        *param_3 = iVar2;
      }
      uVar1 = 1;
    }
  }
  else {
    iVar2 = CM_HeadnodeVisible(param_1[7],param_2,param_3);
    if (iVar2 == 0) {
      uVar1 = CM_HeadnodeVisible(param_1[8],param_2,param_3);
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// CM_LeafPAS  @ 00055b74
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


// CM_LeafPVS  @ 00055b30
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


