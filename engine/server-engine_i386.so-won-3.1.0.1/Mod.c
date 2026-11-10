// Mod_AdInit  @ 000627c8
void Mod_AdInit(void)

{
  char *pcVar1;
  int iVar2;
  
  tested = 1;
  iVar2 = COM_CheckParm(&DAT_000a866a);
  if (((iVar2 != 0) && (pcVar1 = *(char **)(com_argv + 4 + iVar2 * 4), pcVar1 != (char *)0x0)) &&
     (*pcVar1 != '\0')) {
    sprintf(filename_90,"%s",pcVar1);
    iVar2 = COM_FileSize(filename_90);
    if (iVar2 < 1) {
      Con_Printf("No -ad file specified, skipping\n");
    }
    else {
      Draw_CacheWadInit(filename_90,0x10,ad_wad);
      ad_enabled = 1;
    }
  }
  return;
}


// Mod_AdSwap  @ 00062864
void Mod_AdSwap(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  ushort *local_20;
  byte *local_1c;
  byte *local_18;
  ushort *local_14;
  byte *local_10;
  uint local_8;
  
  if (tested != 0) {
    uVar1 = Draw_CacheIndex(ad_wad,&DAT_000a86a1);
    iVar2 = Draw_CacheGet(ad_wad,uVar1);
    if (iVar2 != 0) {
      Q_memcpy(param_1 + 0x40,iVar2 + 0x40,param_2);
      param_1 = param_1 + param_2 + 0x40;
      local_20 = (ushort *)(param_1 + 2);
      iVar2 = iVar2 + param_2 + 0x40;
      local_1c = (byte *)(iVar2 + 2);
      local_8 = 0;
      if (0 < (int)param_3) {
        local_10 = (byte *)(iVar2 + 4);
        local_14 = (ushort *)(param_1 + 4);
        local_18 = (byte *)(iVar2 + 3);
        puVar5 = (ushort *)(param_1 + 6);
        puVar4 = (undefined2 *)(param_1 + 8);
        uVar3 = param_3 & 3;
        if (uVar3 != 0) {
          if (1 < uVar3) {
            if (2 < uVar3) {
              *(undefined2 *)(param_1 + 8) = 0;
              puVar5 = (ushort *)(param_1 + 0xe);
              puVar4 = (undefined2 *)(param_1 + 0x10);
              *(ushort *)(param_1 + 6) = (ushort)*(byte *)(iVar2 + 2);
              *(ushort *)(param_1 + 4) = (ushort)*(byte *)(iVar2 + 3);
              *(ushort *)(param_1 + 2) = (ushort)*(byte *)(iVar2 + 4);
              local_10 = (byte *)(iVar2 + 7);
              local_14 = (ushort *)(param_1 + 0xc);
              local_18 = (byte *)(iVar2 + 6);
              local_1c = (byte *)(iVar2 + 5);
              local_20 = (ushort *)(param_1 + 10);
            }
            local_8 = (uint)(2 < uVar3);
            *puVar4 = 0;
            *puVar5 = (ushort)*local_1c;
            puVar4 = puVar4 + 4;
            *local_14 = (ushort)*local_18;
            puVar5 = puVar5 + 4;
            *local_20 = (ushort)*local_10;
            local_10 = local_10 + 3;
            local_14 = local_14 + 4;
            local_18 = local_18 + 3;
            local_1c = local_1c + 3;
            local_20 = local_20 + 4;
            local_8 = local_8 + 1;
          }
          *puVar4 = 0;
          *puVar5 = (ushort)*local_1c;
          puVar4 = puVar4 + 4;
          *local_14 = (ushort)*local_18;
          puVar5 = puVar5 + 4;
          *local_20 = (ushort)*local_10;
          local_10 = local_10 + 3;
          local_14 = local_14 + 4;
          local_18 = local_18 + 3;
          local_1c = local_1c + 3;
          local_20 = local_20 + 4;
          local_8 = local_8 + 1;
          if ((int)param_3 <= (int)local_8) {
            return;
          }
        }
        do {
          *puVar4 = 0;
          *puVar5 = (ushort)*local_1c;
          *local_14 = (ushort)*local_18;
          *local_20 = (ushort)*local_10;
          puVar4[4] = 0;
          puVar5[4] = (ushort)local_1c[3];
          local_14[4] = (ushort)local_18[3];
          local_20[4] = (ushort)local_10[3];
          puVar4[8] = 0;
          puVar5[8] = (ushort)local_1c[6];
          local_14[8] = (ushort)local_18[6];
          local_20[8] = (ushort)local_10[6];
          puVar4[0xc] = 0;
          puVar4 = puVar4 + 0x10;
          puVar5[0xc] = (ushort)local_1c[9];
          puVar5 = puVar5 + 0x10;
          local_14[0xc] = (ushort)local_18[9];
          local_20[0xc] = (ushort)local_10[9];
          local_10 = local_10 + 0xc;
          local_14 = local_14 + 0x10;
          local_18 = local_18 + 0xc;
          local_1c = local_1c + 0xc;
          local_20 = local_20 + 0x10;
          local_8 = local_8 + 4;
        } while ((int)local_8 < (int)param_3);
      }
    }
  }
  return;
}


// Mod_ClearAll  @ 000624d0
void Mod_ClearAll(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < mod_numknown) {
    piVar1 = (int *)(mod_known + 0x40);
    do {
      if (*piVar1 != 3) {
        *piVar1 = 2;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x62;
    } while (iVar2 < mod_numknown);
  }
  return;
}


// Mod_DecompressVis  @ 000488c0
undefined1 * Mod_DecompressVis(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = mod_novis;
  }
  else {
    puVar1 = decompressed_4;
    CM_DecompressPVS(param_1,decompressed_4,*(int *)(param_2 + 0x88) + 7 >> 3);
  }
  return puVar1;
}


// Mod_Extradata  @ 000623cc
int Mod_Extradata(int param_1)

{
  int iVar1;
  
  iVar1 = Cache_Check(param_1 + 0x184);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      Sys_Error("Mod_ExtraData called with mod_brush!\n");
    }
    Mod_LoadModel(param_1,1);
    iVar1 = *(int *)(param_1 + 0x184);
    if (iVar1 == 0) {
      Sys_Error("Mod_Extradata: caching failed");
      iVar1 = *(int *)(param_1 + 0x184);
    }
  }
  return iVar1;
}


// Mod_FindName  @ 0006251c
undefined1 * Mod_FindName(char *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *local_8;
  
  local_8 = (undefined1 *)0x0;
  if (*param_1 == '\0') {
    Sys_Error("Mod_ForName: NULL name");
  }
  iVar3 = 0;
  puVar2 = mod_known;
  if (0 < mod_numknown) {
    do {
      iVar1 = Q_strcasecmp(puVar2,param_1);
      if (iVar1 == 0) break;
      if ((*(int *)(puVar2 + 0x40) == 2) &&
         ((local_8 == (undefined1 *)0x0 || (1 < *(int *)(puVar2 + 0x44) - 2U)))) {
        local_8 = puVar2;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 0x188;
    } while (iVar3 < mod_numknown);
  }
  if (iVar3 == mod_numknown) {
    if (iVar3 < 0x400) {
      mod_numknown = iVar3 + 1;
      local_8 = puVar2;
    }
    else if (local_8 == (undefined1 *)0x0) {
      Sys_Error("mod_numknown >= MAX_KNOWN_MODELS");
      local_8 = puVar2;
    }
    Q_strcpy(local_8,param_1);
    puVar2 = local_8;
    if (*(int *)(local_8 + 0x40) != 3) {
      *(undefined4 *)(local_8 + 0x40) = 1;
    }
  }
  return puVar2;
}


// Mod_ForName  @ 0006278c
undefined4 Mod_ForName(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = Mod_FindName(param_1);
  if (iVar1 != 0) {
    uVar2 = Mod_LoadModel(iVar1,param_2);
  }
  return uVar2;
}


// Mod_Init  @ 0004888c
void Mod_Init(void)

{
  SW_Mod_Init();
  Q_memset(mod_novis,0xff,0x400);
  return;
}


// Mod_LeafPVS  @ 0004890c
undefined1 * Mod_LeafPVS(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_1 == *(int *)(param_2 + 0x8c)) {
    puVar1 = mod_novis;
  }
  else if (gPVS == 0) {
    puVar1 = (undefined1 *)Mod_DecompressVis(*(undefined4 *)(param_1 + 0x18),param_2);
  }
  else {
    puVar1 = (undefined1 *)CM_LeafPVS((param_1 - *(int *)(param_2 + 0x8c)) * -0x55555555 >> 4);
  }
  return puVar1;
}


// Mod_LoadAliasFrame  @ 00065bb4
undefined1 *
Mod_LoadAliasFrame(undefined1 *param_1,int *param_2,uint param_3,undefined1 *param_4,
                  undefined1 *param_5,int param_6,undefined4 param_7)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *local_18;
  undefined1 *local_14;
  uint local_c;
  
  Q_strcpy(param_7,param_1 + 8);
  *param_4 = *param_1;
  *param_5 = param_1[4];
  param_4[1] = param_1[1];
  param_5[1] = param_1[5];
  param_4[2] = param_1[2];
  param_5[2] = param_1[6];
  puVar3 = param_1 + 0x18;
  puVar1 = (undefined1 *)Hunk_AllocName(param_3 * 4,loadname);
  *param_2 = (int)puVar1 - param_6;
  local_c = 0;
  if (0 < (int)param_3) {
    local_14 = puVar1 + 3;
    local_18 = param_1 + 0x1b;
    uVar2 = param_3 & 3;
    puVar5 = puVar3;
    if (uVar2 != 0) {
      if (1 < uVar2) {
        puVar4 = puVar1;
        if (2 < uVar2) {
          puVar1[3] = param_1[0x1b];
          *puVar1 = param_1[0x18];
          puVar1[1] = param_1[0x19];
          puVar1[2] = param_1[0x1a];
          puVar5 = param_1 + 0x1c;
          puVar4 = puVar1 + 4;
          local_14 = puVar1 + 7;
          local_18 = param_1 + 0x1f;
        }
        local_c = (uint)(2 < uVar2);
        *local_14 = *local_18;
        *puVar4 = *puVar5;
        puVar4[1] = puVar5[1];
        puVar4[2] = puVar5[2];
        puVar5 = puVar5 + 4;
        puVar1 = puVar4 + 4;
        local_14 = local_14 + 4;
        local_18 = local_18 + 4;
        local_c = local_c + 1;
      }
      *local_14 = *local_18;
      *puVar1 = *puVar5;
      puVar1[1] = puVar5[1];
      puVar1[2] = puVar5[2];
      puVar5 = puVar5 + 4;
      puVar1 = puVar1 + 4;
      local_14 = local_14 + 4;
      local_18 = local_18 + 4;
      local_c = local_c + 1;
      if ((int)param_3 <= (int)local_c) goto LAB_00065dd4;
    }
    do {
      *local_14 = *local_18;
      *puVar1 = *puVar5;
      puVar1[1] = puVar5[1];
      puVar1[2] = puVar5[2];
      local_14[4] = local_18[4];
      puVar1[4] = puVar5[4];
      puVar1[5] = puVar5[5];
      puVar1[6] = puVar5[6];
      local_14[8] = local_18[8];
      puVar1[8] = puVar5[8];
      puVar1[9] = puVar5[9];
      puVar1[10] = puVar5[10];
      local_14[0xc] = local_18[0xc];
      puVar1[0xc] = puVar5[0xc];
      puVar1[0xd] = puVar5[0xd];
      puVar1[0xe] = puVar5[0xe];
      puVar5 = puVar5 + 0x10;
      puVar1 = puVar1 + 0x10;
      local_14 = local_14 + 0x10;
      local_18 = local_18 + 0x10;
      local_c = local_c + 4;
    } while ((int)local_c < (int)param_3);
  }
LAB_00065dd4:
  return puVar3 + param_3 * 4;
}


// Mod_LoadAliasGroup  @ 00065de8
undefined4 *
Mod_LoadAliasGroup(undefined4 *param_1,int *param_2,undefined4 param_3,undefined1 *param_4,
                  undefined1 *param_5,int param_6,undefined4 param_7)

{
  uint uVar1;
  uint *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  longdouble lVar8;
  longdouble lVar9;
  uint *local_18;
  uint *local_14;
  uint local_c;
  
  uVar1 = (*LittleLong)(*param_1);
  puVar2 = (uint *)Hunk_AllocName((uVar1 * 3 + -3) * 4 + 0x14,loadname);
  *puVar2 = uVar1;
  *param_4 = *(undefined1 *)(param_1 + 1);
  *param_5 = *(undefined1 *)(param_1 + 2);
  param_4[1] = *(undefined1 *)((int)param_1 + 5);
  param_5[1] = *(undefined1 *)((int)param_1 + 9);
  param_4[2] = *(undefined1 *)((int)param_1 + 6);
  param_5[2] = *(undefined1 *)((int)param_1 + 10);
  *param_2 = (int)puVar2 - param_6;
  puVar4 = param_1 + 3;
  pfVar3 = (float *)Hunk_AllocName(uVar1 << 2,loadname);
  local_c = 0;
  puVar2[1] = (int)pfVar3 - param_6;
  if (0 < (int)uVar1) {
    uVar6 = uVar1 & 3;
    if (uVar6 != 0) {
      if (1 < uVar6) {
        if (2 < uVar6) {
          lVar8 = (longdouble)(*LittleFloat)(param_1[3]);
          *pfVar3 = (float)lVar8;
          lVar9 = (longdouble)0;
          if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
            Sys_Error("Mod_LoadAliasGroup: interval<=0");
          }
          pfVar3 = pfVar3 + 1;
          puVar4 = param_1 + 4;
          local_c = 1;
        }
        lVar8 = (longdouble)(*LittleFloat)(*puVar4);
        *pfVar3 = (float)lVar8;
        lVar9 = (longdouble)0;
        if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
          Sys_Error("Mod_LoadAliasGroup: interval<=0");
        }
        pfVar3 = pfVar3 + 1;
        puVar4 = puVar4 + 1;
        local_c = local_c + 1;
      }
      lVar8 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar3 = (float)lVar8;
      lVar9 = (longdouble)0;
      if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 1;
      puVar4 = puVar4 + 1;
      local_c = local_c + 1;
      if ((int)uVar1 <= (int)local_c) goto LAB_0006609c;
    }
    do {
      lVar9 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar3 = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[1]);
      pfVar3[1] = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[2]);
      pfVar3[2] = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[3]);
      pfVar3[3] = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 4;
      puVar4 = puVar4 + 4;
      local_c = local_c + 4;
    } while ((int)local_c < (int)uVar1);
  }
LAB_0006609c:
  local_c = 0;
  if (0 < (int)uVar1) {
    local_14 = puVar2 + 4;
    local_18 = puVar2 + 3;
    puVar7 = puVar2 + 2;
    uVar6 = uVar1 & 3;
    if (uVar6 != 0) {
      if (1 < uVar6) {
        if (2 < uVar6) {
          puVar4 = (undefined4 *)
                   Mod_LoadAliasFrame(puVar4,local_14,param_3,puVar7,local_18,param_6,param_7);
          local_14 = puVar2 + 7;
          local_18 = puVar2 + 6;
          puVar7 = puVar2 + 5;
        }
        local_c = (uint)(2 < uVar6);
        puVar4 = (undefined4 *)
                 Mod_LoadAliasFrame(puVar4,local_14,param_3,puVar7,local_18,param_6,param_7);
        local_14 = local_14 + 3;
        local_18 = local_18 + 3;
        puVar7 = puVar7 + 3;
        local_c = local_c + 1;
      }
      puVar4 = (undefined4 *)
               Mod_LoadAliasFrame(puVar4,local_14,param_3,puVar7,local_18,param_6,param_7);
      local_14 = local_14 + 3;
      local_18 = local_18 + 3;
      puVar7 = puVar7 + 3;
      local_c = local_c + 1;
      if ((int)uVar1 <= (int)local_c) {
        return puVar4;
      }
    }
    do {
      uVar5 = Mod_LoadAliasFrame(puVar4,local_14,param_3,puVar7,local_18,param_6,param_7);
      uVar5 = Mod_LoadAliasFrame(uVar5,local_14 + 3,param_3,puVar7 + 3,local_18 + 3,param_6,param_7)
      ;
      uVar5 = Mod_LoadAliasFrame(uVar5,local_14 + 6,param_3,puVar7 + 6,local_18 + 6,param_6,param_7)
      ;
      puVar4 = (undefined4 *)
               Mod_LoadAliasFrame(uVar5,local_14 + 9,param_3,puVar7 + 9,local_18 + 9,param_6,param_7
                                 );
      local_14 = local_14 + 0xc;
      local_18 = local_18 + 0xc;
      puVar7 = puVar7 + 0xc;
      local_c = local_c + 4;
    } while ((int)local_c < (int)uVar1);
  }
  return puVar4;
}


// Mod_LoadAliasModel  @ 0006665c
void Mod_LoadAliasModel(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uint uVar12;
  ushort *puVar13;
  byte *pbVar14;
  longdouble lVar15;
  byte *local_90;
  ushort *local_8c;
  int local_88;
  int *local_78;
  int *local_74;
  undefined4 *local_70;
  int *local_6c;
  undefined4 *local_68;
  int *local_64;
  int local_60;
  uint *local_5c;
  uint *local_58;
  uint *local_54;
  uint *local_50;
  ushort *local_48;
  ushort *local_44;
  ushort *local_40;
  byte *local_2c;
  int local_c;
  
  iVar4 = Hunk_LowMark();
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar5 != 6) {
    Sys_Error("%s has wrong version number (%i should be %i)",param_1,iVar5,6);
  }
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  iVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x3c));
  iVar7 = (*LittleLong)(*(undefined4 *)(param_2 + 0x40));
  puVar8 = (uint *)Hunk_AllocName(iVar5 * 0x20 + 0x68 + iVar6 * 0xc + iVar7 * 0x10,loadname);
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  uVar9 = iVar5 << 5 | 0x14;
  uVar10 = (*LittleLong)(*(undefined4 *)(param_2 + 0x4c));
  *(undefined4 *)(param_1 + 0x50) = uVar10;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x20));
  *(float *)((int)puVar8 + uVar9 + 0x20) = (float)lVar15;
  uVar10 = (*LittleLong)(*(undefined4 *)(param_2 + 0x30));
  *(undefined4 *)((int)puVar8 + uVar9 + 0x30) = uVar10;
  uVar10 = (*LittleLong)(*(undefined4 *)(param_2 + 0x34));
  *(undefined4 *)((int)puVar8 + uVar9 + 0x34) = uVar10;
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 0x38));
  *(int *)((int)puVar8 + uVar9 + 0x38) = iVar5;
  if (0x1e0 < iVar5) {
    Sys_Error("model %s has a skin taller than %d",param_1,0x1e0);
  }
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 0x3c));
  *(int *)((int)puVar8 + uVar9 + 0x3c) = iVar5;
  if (iVar5 < 1) {
    Sys_Error("model %s has no vertices",param_1);
  }
  if (2000 < *(int *)((int)puVar8 + uVar9 + 0x3c)) {
    Sys_Error("model %s has too many vertices",param_1);
  }
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 0x40));
  *(int *)((int)puVar8 + uVar9 + 0x40) = iVar5;
  if (iVar5 < 1) {
    Sys_Error("model %s has no triangles",param_1);
  }
  uVar10 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  *(undefined4 *)((int)puVar8 + uVar9 + 0x44) = uVar10;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x50));
  *(float *)((int)puVar8 + uVar9 + 0x50) = (float)((longdouble)0.09090909090909091 * lVar15);
  uVar10 = (*LittleLong)(*(undefined4 *)(param_2 + 0x48));
  *(undefined4 *)(param_1 + 0x4c) = uVar10;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)((int)puVar8 + uVar9 + 0x44);
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 8));
  *(float *)((int)puVar8 + uVar9 + 8) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x14));
  *(float *)((int)puVar8 + uVar9 + 0x14) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x24));
  *(float *)((int)puVar8 + uVar9 + 0x24) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0xc));
  *(float *)((int)puVar8 + uVar9 + 0xc) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x18));
  *(float *)((int)puVar8 + uVar9 + 0x18) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x28));
  *(float *)((int)puVar8 + uVar9 + 0x28) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x10));
  *(float *)((int)puVar8 + uVar9 + 0x10) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x1c));
  *(float *)((int)puVar8 + uVar9 + 0x1c) = (float)lVar15;
  lVar15 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x2c));
  *(float *)((int)puVar8 + uVar9 + 0x2c) = (float)lVar15;
  uVar12 = *(uint *)((int)puVar8 + uVar9 + 0x30);
  uVar3 = *(uint *)((int)puVar8 + uVar9 + 0x44);
  if ((*(byte *)((int)puVar8 + uVar9 + 0x34) & 3) != 0) {
    Sys_Error("Mod_LoadAliasModel: skinwidth not multiple of 4");
  }
  *puVar8 = uVar9;
  iVar5 = *(int *)((int)puVar8 + uVar9 + 0x38) * *(int *)((int)puVar8 + uVar9 + 0x34);
  if ((int)uVar12 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of skins: %d\n",uVar12);
  }
  local_90 = (byte *)(param_2 + 0x54);
  local_78 = (int *)Hunk_AllocName(uVar12 * 0xc,loadname);
  local_c = 0;
  puVar8[2] = (int)local_78 - (int)puVar8;
  if (0 < (int)uVar12) {
    local_74 = local_78 + 2;
    if ((uVar12 & 1) != 0) {
      iVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x54));
      *local_78 = iVar6;
      if (iVar6 == 0) {
        local_90 = (byte *)Mod_LoadAliasSkin(param_2 + 0x58,local_74,iVar5,puVar8);
      }
      else {
        local_90 = (byte *)Mod_LoadAliasSkinGroup(param_2 + 0x58,local_74,iVar5,puVar8);
      }
      local_74 = local_78 + 5;
      local_78 = local_78 + 3;
      local_c = 1;
      if ((int)uVar12 < 2) goto LAB_00066b39;
    }
    do {
      iVar6 = (*LittleLong)(*(undefined4 *)local_90);
      *local_78 = iVar6;
      if (iVar6 == 0) {
        puVar11 = (undefined4 *)
                  Mod_LoadAliasSkin((undefined4 *)((int)local_90 + 4),local_74,iVar5,puVar8);
      }
      else {
        puVar11 = (undefined4 *)
                  Mod_LoadAliasSkinGroup((undefined4 *)((int)local_90 + 4),local_74,iVar5,puVar8);
      }
      iVar6 = (*LittleLong)(*puVar11);
      local_78[3] = iVar6;
      if (iVar6 == 0) {
        local_90 = (byte *)Mod_LoadAliasSkin(puVar11 + 1,local_74 + 3,iVar5,puVar8);
      }
      else {
        local_90 = (byte *)Mod_LoadAliasSkinGroup(puVar11 + 1,local_74 + 3,iVar5,puVar8);
      }
      local_74 = local_74 + 6;
      local_78 = local_78 + 6;
      local_c = local_c + 2;
    } while (local_c < (int)uVar12);
  }
LAB_00066b39:
  local_2c = local_90;
  uVar12 = uVar9 + 0x54;
  puVar8[1] = uVar12;
  local_c = 0;
  iVar5 = *(int *)((int)puVar8 + uVar9 + 0x3c);
  if (0 < iVar5) {
    local_64 = (int *)((int)puVar8 + uVar9 + 0x5c);
    local_68 = (undefined4 *)((int)local_90 + 8);
    local_6c = (int *)((int)puVar8 + uVar9 + 0x58);
    local_70 = (undefined4 *)((int)local_90 + 4);
    iVar6 = 0;
    do {
      uVar10 = (*LittleLong)(*(undefined4 *)((int)local_90 + iVar6));
      *(undefined4 *)((int)puVar8 + iVar6 + uVar12) = uVar10;
      iVar5 = (*LittleLong)(*local_70);
      *local_6c = iVar5 << 0x10;
      iVar5 = (*LittleLong)(*local_68);
      iVar6 = iVar6 + 0xc;
      *local_64 = iVar5 << 0x10;
      local_64 = local_64 + 3;
      local_68 = local_68 + 3;
      local_6c = local_6c + 3;
      local_70 = local_70 + 3;
      local_c = local_c + 1;
      iVar5 = *(int *)((int)puVar8 + uVar9 + 0x3c);
    } while (local_c < iVar5);
  }
  uVar12 = iVar5 * 0xc + uVar12;
  puVar8[3] = uVar12;
  local_c = 0;
  iVar6 = *(int *)((int)puVar8 + uVar9 + 0x40);
  if (0 < iVar6) {
    puVar11 = (undefined4 *)((int)puVar8 + uVar12 + 4);
    local_90 = (byte *)((int)local_90 + (iVar5 * 3 + 1) * 4);
    local_88 = 0;
    do {
      uVar10 = (*LittleLong)(*(undefined4 *)((int)local_2c + local_88 + iVar5 * 0xc));
      *(undefined4 *)((int)puVar8 + local_88 + uVar12) = uVar10;
      uVar10 = (*LittleLong)(*(undefined4 *)local_90);
      *puVar11 = uVar10;
      uVar10 = (*LittleLong)(*(undefined4 *)((int)local_90 + 4));
      puVar11[1] = uVar10;
      uVar10 = (*LittleLong)(*(undefined4 *)((int)local_90 + 8));
      puVar11[2] = uVar10;
      puVar11 = puVar11 + 4;
      local_90 = (byte *)((int)local_90 + 0x10);
      local_88 = local_88 + 0x10;
      local_c = local_c + 1;
      iVar6 = *(int *)((int)puVar8 + uVar9 + 0x40);
    } while (local_c < iVar6);
  }
  if ((int)uVar3 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of frames: %d\n",uVar3);
    iVar6 = *(int *)((int)puVar8 + uVar9 + 0x40);
  }
  local_2c = (byte *)((int)local_2c + (iVar5 * 3 + iVar6 * 4) * 4);
  local_c = 0;
  if (0 < (int)uVar3) {
    local_50 = puVar8 + 8;
    local_54 = puVar8 + 6;
    local_58 = puVar8 + 7;
    local_5c = puVar8 + 9;
    local_60 = 0;
    if ((uVar3 & 1) == 0) goto LAB_00066ddc;
    uVar12 = (*LittleLong)(*(undefined4 *)local_2c);
    puVar8[5] = uVar12;
    if (uVar12 == 0) {
      local_2c = (byte *)Mod_LoadAliasFrame(local_2c + 4,local_50,
                                            *(undefined4 *)((int)puVar8 + uVar9 + 0x3c),local_54,
                                            local_58,puVar8,local_5c);
    }
    else {
      local_2c = (byte *)Mod_LoadAliasGroup(local_2c + 4,local_50,
                                            *(undefined4 *)((int)puVar8 + uVar9 + 0x3c),local_54,
                                            local_58,puVar8,local_5c);
    }
    local_54 = puVar8 + 0xe;
    local_58 = puVar8 + 0xf;
    local_5c = puVar8 + 0x11;
    local_60 = 0x20;
    local_50 = puVar8;
    for (local_c = 1; local_50 = local_50 + 0x10, local_c < (int)uVar3; local_c = local_c + 2) {
LAB_00066ddc:
      iVar5 = (*LittleLong)(*(undefined4 *)local_2c);
      *(int *)(local_60 + 0x14 + (int)puVar8) = iVar5;
      if (iVar5 == 0) {
        puVar11 = (undefined4 *)
                  Mod_LoadAliasFrame(local_2c + 4,local_50,
                                     *(undefined4 *)((int)puVar8 + uVar9 + 0x3c),local_54,local_58,
                                     puVar8,local_5c);
      }
      else {
        puVar11 = (undefined4 *)
                  Mod_LoadAliasGroup(local_2c + 4,local_50,
                                     *(undefined4 *)((int)puVar8 + uVar9 + 0x3c),local_54,local_58,
                                     puVar8,local_5c);
      }
      iVar5 = (*LittleLong)(*puVar11);
      *(int *)(local_60 + 0x34 + (int)puVar8) = iVar5;
      if (iVar5 == 0) {
        local_2c = (byte *)Mod_LoadAliasFrame(puVar11 + 1,local_50 + 8,
                                              *(undefined4 *)((int)puVar8 + uVar9 + 0x3c),
                                              local_54 + 8,local_58 + 8,puVar8,local_5c + 8);
      }
      else {
        local_2c = (byte *)Mod_LoadAliasGroup(puVar11 + 1,local_50 + 8,
                                              *(undefined4 *)((int)puVar8 + uVar9 + 0x3c),
                                              local_54 + 8,local_58 + 8,puVar8,local_5c + 8);
      }
      local_54 = local_54 + 0x10;
      local_58 = local_58 + 0x10;
      local_5c = local_5c + 0x10;
      local_60 = local_60 + 0x40;
    }
  }
  *(undefined4 *)(param_1 + 0x44) = 2;
  *(undefined4 *)(param_1 + 0x5c) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x58) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x54) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x68) = 0x41800000;
  *(undefined4 *)(param_1 + 100) = 0x41800000;
  *(undefined4 *)(param_1 + 0x60) = 0x41800000;
  puVar13 = (ushort *)Hunk_AllocName(0x800,loadname);
  local_40 = puVar13 + 3;
  local_44 = puVar13 + 2;
  local_48 = puVar13 + 1;
  pbVar14 = local_2c + 1;
  local_90 = local_2c + 2;
  pbVar1 = local_2c + 0x2fd;
  local_8c = puVar13;
  do {
    *local_8c = (ushort)*local_90;
    bVar2 = *pbVar14;
    pbVar14 = pbVar14 + 3;
    *local_48 = (ushort)bVar2;
    bVar2 = *local_2c;
    local_2c = local_2c + 3;
    *local_44 = (ushort)bVar2;
    local_44 = local_44 + 4;
    *local_40 = 0;
    local_40 = local_40 + 4;
    local_48 = local_48 + 4;
    local_90 = local_90 + 3;
    local_8c = local_8c + 4;
  } while ((int)local_2c <= (int)pbVar1);
  puVar8[4] = (int)puVar13 - (int)puVar8;
  iVar5 = Hunk_LowMark();
  Cache_Alloc(param_1 + 0x184,iVar5 - iVar4,loadname);
  if (*(int *)(param_1 + 0x184) != 0) {
    Q_memcpy(*(int *)(param_1 + 0x184),puVar8,iVar5 - iVar4);
    Hunk_FreeToLowMark(iVar4);
  }
  return;
}


// Mod_LoadAliasSkin  @ 00066270
int Mod_LoadAliasSkin(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = Hunk_AllocName(param_3 * r_pixbytes,loadname);
  *param_2 = iVar1 - param_4;
  if (r_pixbytes == 1) {
    Q_memcpy(iVar1,param_1,param_3);
  }
  else if (r_pixbytes != 2) {
    Sys_Error("Mod_LoadAliasSkin: driver set invalid r_pixbytes: %d\n",r_pixbytes);
  }
  return param_3 + param_1;
}


// Mod_LoadAliasSkinGroup  @ 000662f4
undefined4 * Mod_LoadAliasSkinGroup(undefined4 *param_1,int *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  longdouble lVar8;
  longdouble lVar9;
  uint local_c;
  
  uVar1 = (*LittleLong)(*param_1);
  puVar2 = (uint *)Hunk_AllocName((uVar1 * 3 + -3) * 4 + 0x14,loadname);
  *puVar2 = uVar1;
  *param_2 = (int)puVar2 - param_4;
  puVar4 = param_1 + 1;
  pfVar3 = (float *)Hunk_AllocName(uVar1 << 2,loadname);
  local_c = 0;
  puVar2[1] = (int)pfVar3 - param_4;
  if (0 < (int)uVar1) {
    uVar6 = uVar1 & 3;
    if (uVar6 == 0) goto LAB_00066460;
    if (1 < uVar6) {
      if (2 < uVar6) {
        lVar8 = (longdouble)(*LittleFloat)(param_1[1]);
        *pfVar3 = (float)lVar8;
        lVar9 = (longdouble)0;
        if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
          Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
        }
        pfVar3 = pfVar3 + 1;
        puVar4 = param_1 + 2;
        local_c = 1;
      }
      lVar8 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar3 = (float)lVar8;
      lVar9 = (longdouble)0;
      if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 1;
      puVar4 = puVar4 + 1;
      local_c = local_c + 1;
    }
    lVar8 = (longdouble)(*LittleFloat)(*puVar4);
    *pfVar3 = (float)lVar8;
    lVar9 = (longdouble)0;
    if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
      Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
    }
    pfVar3 = pfVar3 + 1;
    puVar4 = puVar4 + 1;
    for (local_c = local_c + 1; (int)local_c < (int)uVar1; local_c = local_c + 4) {
LAB_00066460:
      lVar9 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar3 = (float)lVar9;
      if (lVar9 <= (longdouble)0.0) {
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[1]);
      pfVar3[1] = (float)lVar9;
      if (lVar9 <= (longdouble)0.0) {
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[2]);
      pfVar3[2] = (float)lVar9;
      if (lVar9 <= (longdouble)0.0) {
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[3]);
      pfVar3[3] = (float)lVar9;
      if (lVar9 <= (longdouble)0.0) {
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 4;
      puVar4 = puVar4 + 4;
    }
  }
  local_c = 0;
  if (0 < (int)uVar1) {
    puVar7 = puVar2 + 4;
    uVar6 = uVar1 & 3;
    if (uVar6 != 0) {
      if (1 < uVar6) {
        if (2 < uVar6) {
          puVar4 = (undefined4 *)Mod_LoadAliasSkin(puVar4,puVar7,param_3,param_4);
          puVar7 = puVar2 + 7;
        }
        local_c = (uint)(2 < uVar6);
        puVar4 = (undefined4 *)Mod_LoadAliasSkin(puVar4,puVar7,param_3,param_4);
        puVar7 = puVar7 + 3;
        local_c = local_c + 1;
      }
      puVar4 = (undefined4 *)Mod_LoadAliasSkin(puVar4,puVar7,param_3,param_4);
      puVar7 = puVar7 + 3;
      local_c = local_c + 1;
      if ((int)uVar1 <= (int)local_c) {
        return puVar4;
      }
    }
    do {
      uVar5 = Mod_LoadAliasSkin(puVar4,puVar7,param_3,param_4);
      uVar5 = Mod_LoadAliasSkin(uVar5,puVar7 + 3,param_3,param_4);
      uVar5 = Mod_LoadAliasSkin(uVar5,puVar7 + 6,param_3,param_4);
      puVar4 = (undefined4 *)Mod_LoadAliasSkin(uVar5,puVar7 + 9,param_3,param_4);
      puVar7 = puVar7 + 0xc;
      local_c = local_c + 4;
    } while ((int)local_c < (int)uVar1);
  }
  return puVar4;
}


// Mod_LoadBrushModel  @ 00065868
void Mod_LoadBrushModel(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  longdouble lVar4;
  int local_1c;
  int local_14;
  char local_10 [12];
  
  loadmodel[0x11] = 0;
  iVar1 = (*LittleLong)(*param_2);
  if (1 < iVar1 - 0x1dU) {
    Sys_Error("Mod_LoadBrushModel: %s has wrong version number (%i should be %i)",param_1,iVar1,0x1e
             );
  }
  mod_base = param_2;
  puVar3 = param_2;
  if ((int)param_2 < (int)param_2 + 0x79) {
    uVar2 = (*LittleLong)(*param_2);
    *param_2 = uVar2;
    uVar2 = (*LittleLong)(param_2[1]);
    param_2[1] = uVar2;
    puVar3 = param_2 + 2;
  }
  uVar2 = (*LittleLong)(*puVar3);
  *puVar3 = uVar2;
  for (puVar3 = puVar3 + 1; puVar3 <= param_2 + 0x1e; puVar3 = puVar3 + 4) {
    uVar2 = (*LittleLong)(*puVar3);
    *puVar3 = uVar2;
    uVar2 = (*LittleLong)(puVar3[1]);
    puVar3[1] = uVar2;
    uVar2 = (*LittleLong)(puVar3[2]);
    puVar3[2] = uVar2;
    uVar2 = (*LittleLong)(puVar3[3]);
    puVar3[3] = uVar2;
  }
  Mod_LoadVertexes(param_2 + 7);
  Mod_LoadEdges(param_2 + 0x19);
  Mod_LoadSurfedges(param_2 + 0x1b);
  Mod_LoadEntities(param_2 + 1);
  Mod_LoadTextures(param_2 + 5);
  Mod_LoadLighting(param_2 + 0x11);
  Mod_LoadPlanes(param_2 + 3);
  Mod_LoadTexinfo(param_2 + 0xd);
  Mod_LoadFaces(param_2 + 0xf);
  Mod_LoadMarksurfaces(param_2 + 0x17);
  Mod_LoadVisibility(param_2 + 9);
  Mod_LoadLeafs(param_2 + 0x15);
  Mod_LoadNodes(param_2 + 0xb);
  Mod_LoadClipnodes(param_2 + 0x13);
  Mod_LoadSubmodels(param_2 + 0x1d);
  Mod_MakeHull0();
  local_14 = 0;
  param_1[0x12] = 2;
  param_1[0x14] = 0;
  if (0 < (int)param_1[0x1e]) {
    local_1c = 0;
    do {
      puVar3 = (undefined4 *)(local_1c + param_1[0x1f]);
      param_1[0x36] = puVar3[9];
      param_1[0x40] = puVar3[10];
      iVar1 = param_1[0x30] + -1;
      param_1[0x41] = iVar1;
      param_1[0x4a] = puVar3[0xb];
      param_1[0x4b] = iVar1;
      param_1[0x54] = puVar3[0xc];
      param_1[0x55] = iVar1;
      param_1[0x1c] = puVar3[0xe];
      param_1[0x1d] = puVar3[0xf];
      param_1[0x18] = puVar3[3];
      param_1[0x19] = puVar3[4];
      param_1[0x1a] = puVar3[5];
      param_1[0x15] = *puVar3;
      param_1[0x16] = puVar3[1];
      param_1[0x17] = puVar3[2];
      lVar4 = (longdouble)RadiusFromBounds(param_1 + 0x15,param_1 + 0x18);
      param_1[0x1b] = (float)lVar4;
      param_1[0x22] = puVar3[0xd];
      iVar1 = param_1[0x1e];
      if (local_14 < iVar1 + -1) {
        sprintf(local_10,"*%i",local_14 + 1);
        loadmodel = (undefined4 *)Mod_FindName(local_10);
        puVar3 = loadmodel;
        for (iVar1 = 0x62; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *param_1;
          param_1 = param_1 + 1;
          puVar3 = puVar3 + 1;
        }
        Q_strcpy(loadmodel,local_10);
        param_1 = loadmodel;
        iVar1 = loadmodel[0x1e];
      }
      local_1c = local_1c + 0x40;
      local_14 = local_14 + 1;
    } while (local_14 < iVar1);
  }
  return;
}


// Mod_LoadClipnodes  @ 00064de4
void Mod_LoadClipnodes(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 *local_1c;
  short *local_18;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*param_1 + mod_base);
  uVar3 = param_1[1];
  if ((uVar3 & 7) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar3 = param_1[1];
  }
  uVar3 = uVar3 >> 3;
  local_c = (undefined4 *)Hunk_AllocName(uVar3 * 8,loadname);
  *(undefined4 **)(loadmodel + 0xc4) = local_c;
  *(uint *)(loadmodel + 0xc0) = uVar3;
  iVar1 = loadmodel;
  *(undefined4 **)(loadmodel + 0xf8) = local_c;
  *(undefined4 *)(iVar1 + 0x100) = 0;
  iVar5 = uVar3 - 1;
  *(int *)(iVar1 + 0x104) = iVar5;
  *(undefined4 *)(iVar1 + 0xfc) = *(undefined4 *)(loadmodel + 0x84);
  *(undefined4 *)(iVar1 + 0x108) = 0xc1800000;
  *(undefined4 *)(iVar1 + 0x10c) = 0xc1800000;
  *(undefined4 *)(iVar1 + 0x110) = 0xc2100000;
  *(undefined4 *)(iVar1 + 0x114) = 0x41800000;
  *(undefined4 *)(iVar1 + 0x118) = 0x41800000;
  *(undefined4 *)(iVar1 + 0x11c) = 0x42100000;
  iVar1 = loadmodel;
  *(undefined4 **)(loadmodel + 0x120) = local_c;
  *(undefined4 *)(iVar1 + 0x128) = 0;
  *(int *)(iVar1 + 300) = iVar5;
  *(undefined4 *)(iVar1 + 0x124) = *(undefined4 *)(loadmodel + 0x84);
  *(undefined4 *)(iVar1 + 0x130) = 0xc2000000;
  *(undefined4 *)(iVar1 + 0x134) = 0xc2000000;
  *(undefined4 *)(iVar1 + 0x138) = 0xc2000000;
  *(undefined4 *)(iVar1 + 0x13c) = 0x42000000;
  *(undefined4 *)(iVar1 + 0x140) = 0x42000000;
  *(undefined4 *)(iVar1 + 0x144) = 0x42000000;
  iVar1 = loadmodel;
  *(undefined4 **)(loadmodel + 0x148) = local_c;
  *(undefined4 *)(iVar1 + 0x150) = 0;
  *(int *)(iVar1 + 0x154) = iVar5;
  local_10 = 0;
  *(undefined4 *)(iVar1 + 0x14c) = *(undefined4 *)(loadmodel + 0x84);
  *(undefined4 *)(iVar1 + 0x158) = 0xc1800000;
  *(undefined4 *)(iVar1 + 0x15c) = 0xc1800000;
  *(undefined4 *)(iVar1 + 0x160) = 0xc1900000;
  *(undefined4 *)(iVar1 + 0x164) = 0x41800000;
  *(undefined4 *)(iVar1 + 0x168) = 0x41800000;
  *(undefined4 *)(iVar1 + 0x16c) = 0x41900000;
  if (uVar3 != 0) {
    local_18 = (short *)((int)local_8 + 6);
    local_1c = (undefined2 *)((int)local_c + 6);
    if ((uVar3 & 1) == 0) goto LAB_0006506c;
    uVar4 = (*LittleLong)(*local_8);
    *local_c = uVar4;
    uVar2 = (*LittleShort)((int)*(short *)(local_8 + 1));
    *(undefined2 *)(local_c + 1) = uVar2;
    uVar2 = (*LittleShort)((int)*(short *)((int)local_8 + 6));
    local_10 = 1;
    *(undefined2 *)((int)local_c + 6) = uVar2;
    local_1c = (undefined2 *)((int)local_c + 0xe);
    local_c = local_c + 2;
    local_18 = (short *)((int)local_8 + 0xe);
    local_8 = local_8 + 2;
    for (; local_10 < (int)uVar3; local_10 = local_10 + 2) {
LAB_0006506c:
      uVar4 = (*LittleLong)(*local_8);
      *local_c = uVar4;
      uVar2 = (*LittleShort)((int)local_18[-1]);
      local_1c[-1] = uVar2;
      uVar2 = (*LittleShort)((int)*local_18);
      *local_1c = uVar2;
      uVar4 = (*LittleLong)(local_8[2]);
      local_c[2] = uVar4;
      uVar2 = (*LittleShort)((int)local_18[3]);
      local_1c[3] = uVar2;
      uVar2 = (*LittleShort)((int)local_18[4]);
      local_1c[4] = uVar2;
      local_1c = local_1c + 8;
      local_c = local_c + 4;
      local_18 = local_18 + 8;
      local_8 = local_8 + 4;
    }
  }
  return;
}


// Mod_LoadEdges  @ 00063d74
void Mod_LoadEdges(int *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint local_10;
  undefined2 *local_c;
  short *local_8;
  
  local_8 = (short *)(*param_1 + mod_base);
  uVar2 = param_1[1];
  if ((uVar2 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar2 = param_1[1];
  }
  uVar2 = uVar2 >> 2;
  local_c = (undefined2 *)Hunk_AllocName(uVar2 * 8 + 8,loadname);
  *(undefined2 **)(loadmodel + 0x9c) = local_c;
  local_10 = 0;
  *(uint *)(loadmodel + 0x98) = uVar2;
  if (uVar2 != 0) {
    uVar3 = uVar2 & 3;
    if (uVar3 == 0) goto LAB_00063ef4;
    if (1 < uVar3) {
      if (2 < uVar3) {
        uVar1 = (*LittleShort)((int)*local_8);
        *local_c = uVar1;
        uVar1 = (*LittleShort)((int)local_8[1]);
        local_c[1] = uVar1;
        local_8 = local_8 + 2;
        local_c = local_c + 4;
      }
      local_10 = (uint)(2 < uVar3);
      uVar1 = (*LittleShort)((int)*local_8);
      *local_c = uVar1;
      uVar1 = (*LittleShort)((int)local_8[1]);
      local_c[1] = uVar1;
      local_10 = local_10 + 1;
      local_8 = local_8 + 2;
      local_c = local_c + 4;
    }
    uVar1 = (*LittleShort)((int)*local_8);
    *local_c = uVar1;
    uVar1 = (*LittleShort)((int)local_8[1]);
    local_c[1] = uVar1;
    local_8 = local_8 + 2;
    local_c = local_c + 4;
    for (local_10 = local_10 + 1; (int)local_10 < (int)uVar2; local_10 = local_10 + 4) {
LAB_00063ef4:
      uVar1 = (*LittleShort)((int)*local_8);
      *local_c = uVar1;
      uVar1 = (*LittleShort)((int)local_8[1]);
      local_c[1] = uVar1;
      uVar1 = (*LittleShort)((int)local_8[2]);
      local_c[4] = uVar1;
      uVar1 = (*LittleShort)((int)local_8[3]);
      local_c[5] = uVar1;
      uVar1 = (*LittleShort)((int)local_8[4]);
      local_c[8] = uVar1;
      uVar1 = (*LittleShort)((int)local_8[5]);
      local_c[9] = uVar1;
      uVar1 = (*LittleShort)((int)local_8[6]);
      local_c[0xc] = uVar1;
      uVar1 = (*LittleShort)((int)local_8[7]);
      local_c[0xd] = uVar1;
      local_8 = local_8 + 8;
      local_c = local_c + 0x10;
    }
  }
  return;
}


// Mod_LoadEntities  @ 000637fc
void Mod_LoadEntities(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x180) = 0;
  }
  else {
    uVar1 = Hunk_AllocName(param_1[1],loadname);
    *(undefined4 *)(loadmodel + 0x180) = uVar1;
    Q_memcpy(*(undefined4 *)(loadmodel + 0x180),*param_1 + mod_base,param_1[1]);
    pcVar3 = *(char **)(loadmodel + 0x180);
    if (pcVar3 != (char *)0x0) {
      do {
        pcVar3 = (char *)COM_Parse(pcVar3);
        if (*pcVar3 == '\0') {
          return;
        }
        if (com_token == '}') {
          return;
        }
        iVar2 = Q_strcmp(&com_token,&DAT_000a8720);
      } while (iVar2 != 0);
      COM_Parse(pcVar3);
      if (wadpath != 0) {
        Mem_Free(wadpath);
      }
      wadpath = Mem_Strdup(&com_token);
    }
  }
  return;
}


// Mod_LoadFaces  @ 00064588
void Mod_LoadFaces(int *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  short *local_20;
  short *local_1c;
  undefined2 *local_18;
  int local_10;
  short *local_8;
  
  local_8 = (short *)(*param_1 + mod_base);
  uVar6 = param_1[1];
  if (uVar6 != (uVar6 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar6 = param_1[1];
  }
  uVar6 = uVar6 / 0x14;
  iVar3 = Hunk_AllocName(uVar6 * 0x44,loadname);
  *(int *)(loadmodel + 0xb4) = iVar3;
  local_10 = 0;
  *(uint *)(loadmodel + 0xb0) = uVar6;
  if (uVar6 != 0) {
    local_18 = (undefined2 *)(iVar3 + 0x32);
    local_1c = local_8 + 8;
    puVar7 = (undefined2 *)(iVar3 + 0x30);
    local_20 = local_8 + 5;
    do {
      uVar4 = (*LittleLong)(*(undefined4 *)(local_20 + -3));
      *(undefined4 *)(puVar7 + -0xe) = uVar4;
      sVar1 = (*LittleShort)((int)local_20[-1]);
      *(int *)(puVar7 + -0xc) = (int)sVar1;
      *(undefined4 *)(puVar7 + -0x10) = 0;
      *(undefined4 *)(puVar7 + 8) = 0;
      sVar1 = (*LittleShort)((int)*local_8);
      sVar2 = (*LittleShort)((int)local_20[-4]);
      if (sVar2 != 0) {
        *(byte *)(puVar7 + -0x10) = *(byte *)(puVar7 + -0x10) | 2;
      }
      *(int *)(puVar7 + -0x12) = sVar1 * 0x14 + *(int *)(loadmodel + 0x84);
      sVar1 = (*LittleShort)((int)*local_20);
      *(int *)(puVar7 + 2) = sVar1 * 0x2c + *(int *)(loadmodel + 0xac);
      CalcSurfaceExtents(iVar3);
      *(char *)(iVar3 + 0x38) = (char)local_8[6];
      *(undefined1 *)(iVar3 + 0x39) = *(undefined1 *)((int)local_8 + 0xd);
      *(char *)(iVar3 + 0x3a) = (char)local_8[7];
      *(undefined1 *)(iVar3 + 0x3b) = *(undefined1 *)((int)local_8 + 0xf);
      iVar5 = (*LittleLong)(*(undefined4 *)local_1c);
      if (iVar5 == -1) {
        *(undefined4 *)(puVar7 + 6) = 0;
      }
      else {
        *(int *)(puVar7 + 6) = iVar5 + *(int *)(loadmodel + 0x17c);
      }
      iVar5 = Q_strncmp(*(undefined4 *)(*(int *)(puVar7 + 2) + 0x24),&DAT_000a86c2,3);
      if (iVar5 == 0) {
        *(byte *)(puVar7 + -0x10) = *(byte *)(puVar7 + -0x10) | 0x24;
      }
      else {
        iVar5 = Q_strncmp(*(undefined4 *)(*(int *)(puVar7 + 2) + 0x24),"scroll",6);
        if (iVar5 == 0) {
          *(byte *)(puVar7 + -0x10) = *(byte *)(puVar7 + -0x10) | 0x20;
          *puVar7 = *(undefined2 *)(*(int *)(*(int *)(puVar7 + 2) + 0x24) + 0x10);
          *local_18 = *(undefined2 *)(*(int *)(*(int *)(puVar7 + 2) + 0x24) + 0x14);
        }
        else {
          if (**(char **)(*(int *)(puVar7 + 2) + 0x24) != '!') {
            iVar5 = Q_strnicmp(*(undefined4 *)(*(int *)(puVar7 + 2) + 0x24),"laser",5);
            if (iVar5 != 0) {
              iVar5 = Q_strnicmp(*(undefined4 *)(*(int *)(puVar7 + 2) + 0x24),"water",5);
              if (iVar5 != 0) {
                iVar5 = *(int *)(puVar7 + 2);
                if ((*(byte *)(iVar5 + 0x28) & 1) != 0) {
                  *(byte *)(puVar7 + -0x10) = *(byte *)(puVar7 + -0x10) | 0x20;
                  *puVar7 = *(undefined2 *)(*(int *)(iVar5 + 0x24) + 0x10);
                  *local_18 = *(undefined2 *)(*(int *)(iVar5 + 0x24) + 0x14);
                }
                goto LAB_00064878;
              }
            }
          }
          *(byte *)(puVar7 + -0x10) = *(byte *)(puVar7 + -0x10) | 0x30;
          *(undefined2 *)(iVar3 + 0x30) = 0x4000;
          *(undefined2 *)(iVar3 + 0x2c) = 0xe000;
          *(byte *)(*(int *)(puVar7 + 2) + 0x28) = *(byte *)(*(int *)(puVar7 + 2) + 0x28) | 1;
          *(undefined2 *)(iVar3 + 0x32) = 0x4000;
          *(undefined2 *)(iVar3 + 0x2e) = 0xe000;
          *(byte *)(*(int *)(puVar7 + 2) + 0x28) = *(byte *)(*(int *)(puVar7 + 2) + 0x28) | 1;
        }
      }
LAB_00064878:
      local_10 = local_10 + 1;
      local_20 = local_20 + 10;
      local_1c = local_1c + 10;
      local_8 = local_8 + 10;
      puVar7 = puVar7 + 0x22;
      local_18 = local_18 + 0x22;
      iVar3 = iVar3 + 0x44;
    } while (local_10 < (int)uVar6);
  }
  return;
}


// Mod_LoadLeafs  @ 00064b98
void Mod_LoadLeafs(int *param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  int local_8;
  
  puVar7 = (undefined4 *)(*param_1 + mod_base);
  uVar6 = param_1[1];
  if (uVar6 != (uVar6 / 0x1c) * 0x1c) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar6 = param_1[1];
  }
  uVar6 = uVar6 / 0x1c;
  puVar3 = (undefined4 *)Hunk_AllocName(uVar6 * 0x30,loadname);
  *(undefined4 **)(loadmodel + 0x8c) = puVar3;
  local_8 = 0;
  *(uint *)(loadmodel + 0x88) = uVar6;
  if (uVar6 != 0) {
    local_10 = puVar3 + 0xb;
    local_14 = puVar7 + 6;
    local_18 = puVar3 + 7;
    local_1c = puVar7 + 1;
    do {
      uVar1 = (*LittleShort)((int)*(short *)(puVar7 + 2));
      *(undefined2 *)(puVar3 + 2) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)puVar7 + 0xe));
      *(undefined2 *)((int)puVar3 + 0xe) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)puVar7 + 10));
      *(undefined2 *)((int)puVar3 + 10) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)(puVar7 + 4));
      *(undefined2 *)(puVar3 + 4) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)(puVar7 + 3));
      *(undefined2 *)(puVar3 + 3) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)puVar7 + 0x12));
      *(undefined2 *)((int)puVar3 + 0x12) = uVar1;
      uVar4 = (*LittleLong)(*puVar7);
      *puVar3 = uVar4;
      local_18[1] = (uint)*(ushort *)(local_1c + 4) * 4 + *(int *)(loadmodel + 0xcc);
      sVar2 = (*LittleShort)((int)*(short *)((int)local_1c + 0x12));
      local_18[2] = (int)sVar2;
      iVar5 = (*LittleLong)(*local_1c);
      if (iVar5 == -1) {
        local_18[-1] = 0;
      }
      else {
        local_18[-1] = iVar5 + *(int *)(loadmodel + 0x178);
      }
      *local_18 = 0;
      *(undefined1 *)local_10 = *(undefined1 *)local_14;
      *(undefined1 *)((int)local_10 + 1) = *(undefined1 *)((int)local_14 + 1);
      *(undefined1 *)((int)local_10 + 2) = *(undefined1 *)((int)local_14 + 2);
      *(undefined1 *)((int)local_10 + 3) = *(undefined1 *)((int)local_14 + 3);
      local_8 = local_8 + 1;
      local_1c = local_1c + 7;
      local_14 = local_14 + 7;
      puVar7 = puVar7 + 7;
      local_18 = local_18 + 0xc;
      local_10 = local_10 + 0xc;
      puVar3 = puVar3 + 0xc;
    } while (local_8 < (int)uVar6);
  }
  return;
}


// Mod_LoadLighting  @ 00063704
void Mod_LoadLighting(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x17c) = 0;
  }
  else {
    uVar1 = Hunk_AllocName(param_1[1],loadname);
    *(undefined4 *)(loadmodel + 0x17c) = uVar1;
    Q_memcpy(*(undefined4 *)(loadmodel + 0x17c),*param_1 + mod_base,param_1[1]);
  }
  return;
}


// Mod_LoadMarksurfaces  @ 000652ac
void Mod_LoadMarksurfaces(int *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *local_10;
  int *local_c;
  
  local_10 = (short *)(*param_1 + mod_base);
  uVar2 = param_1[1];
  if ((uVar2 & 1) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar2 = param_1[1];
  }
  uVar2 = uVar2 >> 1;
  local_c = (int *)Hunk_AllocName(uVar2 * 4,loadname);
  iVar3 = 0;
  *(int **)(loadmodel + 0xcc) = local_c;
  *(uint *)(loadmodel + 200) = uVar2;
  if (uVar2 != 0) {
    if ((uVar2 & 1) != 0) {
      sVar1 = (*LittleShort)((int)*local_10);
      if (*(int *)(loadmodel + 0xb0) <= (int)sVar1) {
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      iVar3 = 1;
      *local_c = sVar1 * 0x44 + *(int *)(loadmodel + 0xb4);
      local_c = local_c + 1;
      local_10 = local_10 + 1;
      if (uVar2 < 2) {
        return;
      }
    }
    do {
      sVar1 = (*LittleShort)((int)*local_10);
      if (*(int *)(loadmodel + 0xb0) <= (int)sVar1) {
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      *local_c = sVar1 * 0x44 + *(int *)(loadmodel + 0xb4);
      sVar1 = (*LittleShort)((int)local_10[1]);
      if (*(int *)(loadmodel + 0xb0) <= (int)sVar1) {
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      iVar3 = iVar3 + 2;
      local_c[1] = sVar1 * 0x44 + *(int *)(loadmodel + 0xb4);
      local_c = local_c + 2;
      local_10 = local_10 + 2;
    } while (iVar3 < (int)uVar2);
  }
  return;
}


// Mod_LoadModel  @ 00062640
int Mod_LoadModel(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 0x44) - 2U < 2) {
    iVar1 = Cache_Check(param_1 + 0x184);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x40) = 0;
      return param_1;
    }
  }
  else {
    if (*(int *)(param_1 + 0x40) == 0) {
      return param_1;
    }
    if (*(int *)(param_1 + 0x40) == 3) {
      return param_1;
    }
  }
  puVar2 = (undefined4 *)COM_LoadFileForMe(param_1,0);
  if (puVar2 == (undefined4 *)0x0) {
    if (param_2 != 0) {
      Sys_Error("Mod_NumForName: %s not found",param_1);
    }
    return 0;
  }
  if (1.0 < (float)developer._12_4_) {
    Con_DPrintf("loading %s\n",param_1);
  }
  COM_FileBase(param_1,loadname);
  loadmodel = param_1;
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar1 = (*LittleLong)(*puVar2);
  if (iVar1 == 0x50534449) {
    Mod_LoadSpriteModel(param_1,puVar2);
  }
  else {
    if (iVar1 < 0x5053444a) {
      if (iVar1 == 0x4f504449) {
        Mod_LoadAliasModel(param_1,puVar2);
        goto LAB_0006275f;
      }
    }
    else if (iVar1 == 0x54534449) {
      Mod_LoadStudioModel(param_1,puVar2);
      goto LAB_0006275f;
    }
    Mod_LoadBrushModel(param_1,puVar2);
  }
LAB_0006275f:
  if (puVar2 != (undefined4 *)0x0) {
    Mem_Free(puVar2);
  }
  return param_1;
}


// Mod_LoadNodes  @ 000648e4
void Mod_LoadNodes(int *param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined2 *local_20;
  short *local_1c;
  int *local_18;
  int local_8;
  
  puVar7 = (undefined4 *)(*param_1 + mod_base);
  uVar6 = param_1[1];
  if (uVar6 != (uVar6 / 0x18) * 0x18) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar6 = param_1[1];
  }
  uVar6 = uVar6 / 0x18;
  iVar3 = Hunk_AllocName(uVar6 * 0x28,loadname);
  *(int *)(loadmodel + 0xa4) = iVar3;
  local_8 = 0;
  *(uint *)(loadmodel + 0xa0) = uVar6;
  if (uVar6 != 0) {
    local_18 = (int *)(iVar3 + 0x1c);
    local_1c = (short *)(puVar7 + 1);
    local_20 = (undefined2 *)(iVar3 + 0x26);
    do {
      uVar1 = (*LittleShort)((int)*(short *)(puVar7 + 2));
      *(undefined2 *)(iVar3 + 8) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)puVar7 + 0xe));
      *(undefined2 *)(iVar3 + 0xe) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)puVar7 + 10));
      *(undefined2 *)(iVar3 + 10) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)(puVar7 + 4));
      *(undefined2 *)(iVar3 + 0x10) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)(puVar7 + 3));
      *(undefined2 *)(iVar3 + 0xc) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)puVar7 + 0x12));
      *(undefined2 *)(iVar3 + 0x12) = uVar1;
      iVar4 = (*LittleLong)(*puVar7);
      *(int *)(local_20 + -7) = iVar4 * 0x14 + *(int *)(loadmodel + 0x84);
      uVar1 = (*LittleShort)((int)local_1c[8]);
      local_20[-1] = uVar1;
      uVar1 = (*LittleShort)((int)local_1c[9]);
      *local_20 = uVar1;
      sVar2 = (*LittleShort)((int)*local_1c);
      uVar5 = (uint)sVar2;
      if ((int)uVar5 < 0) {
        iVar4 = ~uVar5 * 0x30 + *(int *)(loadmodel + 0x8c);
      }
      else {
        iVar4 = uVar5 * 0x28 + *(int *)(loadmodel + 0xa4);
      }
      *local_18 = iVar4;
      sVar2 = (*LittleShort)((int)local_1c[1]);
      uVar5 = (uint)sVar2;
      if ((int)uVar5 < 0) {
        iVar4 = ~uVar5 * 0x30 + *(int *)(loadmodel + 0x8c);
      }
      else {
        iVar4 = uVar5 * 0x28 + *(int *)(loadmodel + 0xa4);
      }
      local_18[1] = iVar4;
      local_8 = local_8 + 1;
      local_1c = local_1c + 0xc;
      puVar7 = puVar7 + 6;
      local_20 = local_20 + 0x14;
      local_18 = local_18 + 10;
      iVar3 = iVar3 + 0x28;
    } while (local_8 < (int)uVar6);
  }
  if (uVar6 != 0) {
    Mod_SetParent(*(undefined4 *)(loadmodel + 0xa4),0);
  }
  return;
}


// Mod_LoadPlanes  @ 000655e4
void Mod_LoadPlanes(int *param_1)

{
  undefined1 uVar1;
  float *pfVar2;
  uint uVar3;
  byte bVar4;
  longdouble lVar5;
  longdouble lVar6;
  float *local_1c;
  undefined4 *local_18;
  byte *local_14;
  undefined4 *local_c;
  int local_8;
  
  local_c = (undefined4 *)(*param_1 + mod_base);
  uVar3 = param_1[1];
  if (uVar3 != (uVar3 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar3 = param_1[1];
  }
  uVar3 = uVar3 / 0x14;
  pfVar2 = (float *)Hunk_AllocName(uVar3 * 0x28,loadname);
  *(float **)(loadmodel + 0x84) = pfVar2;
  local_8 = 0;
  *(uint *)(loadmodel + 0x80) = uVar3;
  if (uVar3 != 0) {
    local_14 = (byte *)((int)pfVar2 + 0x11);
    local_18 = local_c + 4;
    local_1c = pfVar2 + 4;
    do {
      lVar5 = (longdouble)(*LittleFloat)(*local_c);
      *pfVar2 = (float)lVar5;
      lVar6 = (longdouble)0;
      bVar4 = 0x3f < (byte)((lVar6 < lVar5 |
                             (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1);
      lVar5 = (longdouble)(*LittleFloat)(local_c[1]);
      pfVar2[1] = (float)lVar5;
      if (0x3f < (byte)((lVar6 < lVar5 |
                         (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)) {
        bVar4 = bVar4 | 2;
      }
      lVar5 = (longdouble)(*LittleFloat)(local_c[2]);
      pfVar2[2] = (float)lVar5;
      if (0x3f < (byte)((lVar6 < lVar5 |
                         (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)) {
        bVar4 = bVar4 | 4;
      }
      lVar6 = (longdouble)(*LittleFloat)(local_18[-1]);
      local_1c[-1] = (float)lVar6;
      uVar1 = (*LittleLong)(*local_18);
      *(undefined1 *)local_1c = uVar1;
      pfVar2 = pfVar2 + 5;
      *local_14 = bVar4;
      local_8 = local_8 + 1;
      local_18 = local_18 + 5;
      local_c = local_c + 5;
      local_1c = local_1c + 5;
      local_14 = local_14 + 0x14;
    } while (local_8 < (int)uVar3);
  }
  return;
}


// Mod_LoadSpriteFrame  @ 0006703c
int Mod_LoadSpriteFrame(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = (*LittleLong)(param_1[2]);
  iVar2 = (*LittleLong)(param_1[3]);
  iVar6 = iVar1 * iVar2;
  piVar3 = (int *)Hunk_AllocName(iVar6 * r_pixbytes + 0x20,loadname);
  Q_memset(piVar3,0,iVar6 + 0x20);
  *param_2 = piVar3;
  *piVar3 = iVar1;
  piVar3[1] = iVar2;
  iVar4 = (*LittleLong)(*param_1);
  iVar5 = (*LittleLong)(param_1[1]);
  piVar3[3] = (int)(float)iVar5;
  piVar3[4] = (int)(float)(iVar5 - iVar2);
  piVar3[5] = (int)(float)iVar4;
  piVar3[6] = (int)(float)(iVar1 + iVar4);
  if (r_pixbytes == 1) {
    Q_memcpy(piVar3 + 7,param_1 + 4,iVar6);
  }
  else if (r_pixbytes != 2) {
    Sys_Error("Mod_LoadSpriteFrame: driver set invalid r_pixbytes: %d\n",r_pixbytes);
  }
  return (int)param_1 + iVar6 + 0x10;
}


// Mod_LoadSpriteGroup  @ 00067158
undefined4 * Mod_LoadSpriteGroup(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  longdouble lVar8;
  longdouble lVar9;
  uint local_c;
  
  uVar1 = (*LittleLong)(*param_1);
  puVar2 = (uint *)Hunk_AllocName(uVar1 * 4 + 8,loadname);
  *puVar2 = uVar1;
  *param_2 = puVar2;
  puVar4 = param_1 + 1;
  pfVar3 = (float *)Hunk_AllocName(uVar1 << 2,loadname);
  local_c = 0;
  puVar2[1] = (uint)pfVar3;
  if (0 < (int)uVar1) {
    uVar6 = uVar1 & 3;
    if (uVar6 != 0) {
      if (1 < uVar6) {
        if (2 < uVar6) {
          lVar8 = (longdouble)(*LittleFloat)(param_1[1]);
          *pfVar3 = (float)lVar8;
          lVar9 = (longdouble)0;
          if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
            Sys_Error("Mod_LoadSpriteGroup: interval<=0");
          }
          pfVar3 = pfVar3 + 1;
          puVar4 = param_1 + 2;
          local_c = 1;
        }
        lVar8 = (longdouble)(*LittleFloat)(*puVar4);
        *pfVar3 = (float)lVar8;
        lVar9 = (longdouble)0;
        if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
          Sys_Error("Mod_LoadSpriteGroup: interval<=0");
        }
        pfVar3 = pfVar3 + 1;
        puVar4 = puVar4 + 1;
        local_c = local_c + 1;
      }
      lVar8 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar3 = (float)lVar8;
      lVar9 = (longdouble)0;
      if ((byte)(lVar9 < lVar8 | (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 1;
      puVar4 = puVar4 + 1;
      local_c = local_c + 1;
      if ((int)uVar1 <= (int)local_c) goto LAB_000673bc;
    }
    do {
      lVar9 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar3 = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[1]);
      pfVar3[1] = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[2]);
      pfVar3[2] = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
      }
      lVar9 = (longdouble)(*LittleFloat)(puVar4[3]);
      pfVar3[3] = (float)lVar9;
      lVar8 = (longdouble)0.0;
      if ((byte)(lVar8 < lVar9 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar9)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar8 == lVar9) << 0xe) >> 8)) != 1) {
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 4;
      puVar4 = puVar4 + 4;
      local_c = local_c + 4;
    } while ((int)local_c < (int)uVar1);
  }
LAB_000673bc:
  local_c = 0;
  if (0 < (int)uVar1) {
    puVar7 = puVar2 + 2;
    uVar6 = uVar1 & 3;
    if (uVar6 == 0) goto LAB_00067428;
    if (1 < uVar6) {
      if (2 < uVar6) {
        puVar4 = (undefined4 *)Mod_LoadSpriteFrame(puVar4,puVar7);
        puVar7 = puVar2 + 3;
      }
      local_c = (uint)(2 < uVar6);
      puVar4 = (undefined4 *)Mod_LoadSpriteFrame(puVar4,puVar7);
      puVar7 = puVar7 + 1;
      local_c = local_c + 1;
    }
    puVar4 = (undefined4 *)Mod_LoadSpriteFrame(puVar4,puVar7);
    puVar7 = puVar7 + 1;
    for (local_c = local_c + 1; (int)local_c < (int)uVar1; local_c = local_c + 4) {
LAB_00067428:
      uVar5 = Mod_LoadSpriteFrame(puVar4,puVar7);
      uVar5 = Mod_LoadSpriteFrame(uVar5,puVar7 + 1);
      uVar5 = Mod_LoadSpriteFrame(uVar5,puVar7 + 2);
      puVar4 = (undefined4 *)Mod_LoadSpriteFrame(uVar5,puVar7 + 3);
      puVar7 = puVar7 + 4;
    }
  }
  return puVar4;
}


// Mod_LoadSpriteModel  @ 0006747c
void Mod_LoadSpriteModel(int param_1,int param_2)

{
  ushort uVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  ushort *puVar12;
  undefined4 *puVar13;
  longdouble lVar14;
  byte *local_30;
  byte *local_2c;
  byte *local_24;
  ushort *local_20;
  ushort *local_1c;
  undefined2 *local_18;
  uint local_8;
  
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar4 != 2) {
    Sys_Error("%s has wrong version number (%i should be %i)",param_1,iVar4,2);
  }
  uVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 0x1c));
  puVar6 = (undefined2 *)Hunk_AllocName(uVar5 * 8 + 0x1e + *(short *)(param_2 + 0x28) * 8,loadname);
  *(undefined2 **)(param_1 + 0x184) = puVar6;
  uVar3 = (*LittleLong)(*(undefined4 *)(param_2 + 8));
  *puVar6 = uVar3;
  uVar3 = (*LittleLong)(*(undefined4 *)(param_2 + 0xc));
  puVar6[1] = uVar3;
  uVar7 = (*LittleLong)(*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(puVar6 + 2) = uVar7;
  uVar7 = (*LittleLong)(*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(puVar6 + 4) = uVar7;
  lVar14 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x20));
  *(float *)(puVar6 + 10) = (float)lVar14;
  uVar7 = (*LittleLong)(*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x4c) = uVar7;
  *(uint *)(puVar6 + 6) = uVar5;
  iVar4 = *(int *)(puVar6 + 2);
  *(float *)(param_1 + 0x58) = (float)(-iVar4 / 2);
  *(float *)(param_1 + 0x54) = (float)(-iVar4 / 2);
  fVar2 = (float)(*(int *)(puVar6 + 2) - (*(int *)(puVar6 + 2) >> 0x1f) >> 1);
  *(float *)(param_1 + 100) = fVar2;
  *(float *)(param_1 + 0x60) = fVar2;
  *(float *)(param_1 + 0x5c) = (float)(-*(int *)(puVar6 + 4) / 2);
  puVar8 = puVar6 + uVar5 * 4 + 0xe;
  *(float *)(param_1 + 0x68) = (float)(*(int *)(puVar6 + 4) - (*(int *)(puVar6 + 4) >> 0x1f) >> 1);
  *(uint *)(puVar6 + 8) = uVar5 * 8 + 0x1e;
  uVar1 = *(ushort *)(param_2 + 0x28);
  uVar10 = (uint)uVar1;
  *puVar8 = uVar1;
  puVar11 = puVar8 + 1;
  local_2c = (byte *)(param_2 + 0x2a);
  local_8 = 0;
  if (uVar10 != 0) {
    local_1c = puVar8 + 4;
    local_20 = puVar8 + 3;
    local_24 = (byte *)(param_2 + 0x2c);
    puVar12 = puVar8 + 2;
    local_30 = (byte *)(param_2 + 0x2b);
    uVar9 = uVar10 & 3;
    if ((uVar1 & 3) != 0) {
      if (1 < uVar9) {
        if (2 < uVar9) {
          *puVar11 = (ushort)*(byte *)(param_2 + 0x2a);
          puVar8[2] = (ushort)*(byte *)(param_2 + 0x2b);
          puVar8[3] = (ushort)*(byte *)(param_2 + 0x2c);
          puVar8[4] = 0;
          local_1c = puVar8 + 8;
          local_20 = puVar8 + 7;
          local_24 = (byte *)(param_2 + 0x2f);
          puVar12 = puVar8 + 6;
          local_30 = (byte *)(param_2 + 0x2e);
          local_2c = (byte *)(param_2 + 0x2d);
          puVar11 = puVar8 + 5;
        }
        local_8 = (uint)(2 < uVar9);
        *puVar11 = (ushort)*local_2c;
        puVar11 = puVar11 + 4;
        *puVar12 = (ushort)*local_30;
        puVar12 = puVar12 + 4;
        *local_20 = (ushort)*local_24;
        local_20 = local_20 + 4;
        *local_1c = 0;
        local_1c = local_1c + 4;
        local_24 = local_24 + 3;
        local_30 = local_30 + 3;
        local_2c = local_2c + 3;
        local_8 = local_8 + 1;
      }
      *puVar11 = (ushort)*local_2c;
      puVar11 = puVar11 + 4;
      *puVar12 = (ushort)*local_30;
      puVar12 = puVar12 + 4;
      *local_20 = (ushort)*local_24;
      local_20 = local_20 + 4;
      *local_1c = 0;
      local_1c = local_1c + 4;
      local_24 = local_24 + 3;
      local_30 = local_30 + 3;
      local_2c = local_2c + 3;
      local_8 = local_8 + 1;
      if (uVar10 <= local_8) goto LAB_00067863;
    }
    do {
      *puVar11 = (ushort)*local_2c;
      *puVar12 = (ushort)*local_30;
      *local_20 = (ushort)*local_24;
      *local_1c = 0;
      puVar11[4] = (ushort)local_2c[3];
      puVar12[4] = (ushort)local_30[3];
      local_20[4] = (ushort)local_24[3];
      local_1c[4] = 0;
      puVar11[8] = (ushort)local_2c[6];
      puVar12[8] = (ushort)local_30[6];
      local_20[8] = (ushort)local_24[6];
      local_1c[8] = 0;
      puVar11[0xc] = (ushort)local_2c[9];
      puVar11 = puVar11 + 0x10;
      puVar12[0xc] = (ushort)local_30[9];
      puVar12 = puVar12 + 0x10;
      local_20[0xc] = (ushort)local_24[9];
      local_20 = local_20 + 0x10;
      local_1c[0xc] = 0;
      local_1c = local_1c + 0x10;
      local_24 = local_24 + 0xc;
      local_30 = local_30 + 0xc;
      local_2c = local_2c + 0xc;
      local_8 = local_8 + 4;
    } while ((int)local_8 < (int)uVar10);
  }
LAB_00067863:
  if ((int)uVar5 < 1) {
    Sys_Error("Mod_LoadSpriteModel: Invalid # of frames: %d\n",uVar5);
  }
  local_8 = 0;
  *(uint *)(param_1 + 0x48) = uVar5;
  *(undefined4 *)(param_1 + 0x50) = 0;
  param_2 = uVar10 * 3 + 0x28 + param_2;
  puVar13 = (undefined4 *)(param_2 + 2);
  if (0 < (int)uVar5) {
    local_18 = puVar6 + 0x10;
    if ((uVar5 & 1) == 0) goto LAB_00067918;
    iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 2));
    *(int *)(puVar6 + 0xe) = iVar4;
    if (iVar4 == 0) {
      puVar13 = (undefined4 *)Mod_LoadSpriteFrame(param_2 + 6,local_18);
    }
    else {
      puVar13 = (undefined4 *)Mod_LoadSpriteGroup(param_2 + 6,local_18);
    }
    local_18 = puVar6 + 0x14;
    for (local_8 = 1; (int)local_8 < (int)uVar5; local_8 = local_8 + 2) {
LAB_00067918:
      iVar4 = (*LittleLong)(*puVar13);
      *(int *)(puVar6 + local_8 * 4 + 0xe) = iVar4;
      if (iVar4 == 0) {
        puVar13 = (undefined4 *)Mod_LoadSpriteFrame(puVar13 + 1,local_18);
      }
      else {
        puVar13 = (undefined4 *)Mod_LoadSpriteGroup(puVar13 + 1,local_18);
      }
      iVar4 = (*LittleLong)(*puVar13);
      *(int *)(puVar6 + (local_8 + 1) * 4 + 0xe) = iVar4;
      if (iVar4 == 0) {
        puVar13 = (undefined4 *)Mod_LoadSpriteFrame(puVar13 + 1,local_18 + 4);
      }
      else {
        puVar13 = (undefined4 *)Mod_LoadSpriteGroup(puVar13 + 1,local_18 + 4);
      }
      local_18 = local_18 + 8;
    }
  }
  *(undefined4 *)(param_1 + 0x44) = 1;
  return;
}


// Mod_LoadStudioModel  @ 0005dcc8
void Mod_LoadStudioModel(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  byte *local_34;
  ushort *local_30;
  ushort *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  ushort *local_1c;
  int local_18;
  byte *local_10;
  int local_8;
  
  iVar1 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar1 != 10) {
    Q_memset(param_2,0,0xf4);
    Q_strcpy(param_2 + 8,"bogus");
    *(undefined4 *)(param_2 + 0x48) = 0xf4;
    *(undefined4 *)(param_2 + 0xbc) = 0xf4;
  }
  *(undefined4 *)(param_1 + 0x44) = 3;
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 0x88);
  Cache_Alloc(param_1 + 0x184,*(int *)(param_2 + 0xb4) * 0x500 + *(int *)(param_2 + 0x48),param_1);
  iVar1 = *(int *)(param_1 + 0x184);
  if (iVar1 != 0) {
    iVar2 = iVar1 + *(int *)(param_2 + 0xb8);
    if (*(int *)(param_2 + 0xb8) == 0) {
      Q_memcpy(iVar1,param_2,*(undefined4 *)(param_2 + 0x48));
    }
    else {
      Q_memcpy(iVar1,param_2,*(undefined4 *)(param_2 + 0xbc));
      local_10 = (byte *)(param_2 + *(int *)(param_2 + 0xbc));
      local_30 = (ushort *)(*(int *)(param_2 + 0xbc) + iVar1);
      local_8 = 0;
      if (0 < *(int *)(param_2 + 0xb4)) {
        local_20 = (int *)(iVar2 + 0x48);
        local_24 = (int *)(iVar2 + 0x44);
        local_28 = (int *)(iVar2 + 0x4c);
        do {
          *local_28 = (int)local_30 - iVar1;
          iVar2 = *local_24 * *local_20;
          Q_memcpy(local_30,local_10,iVar2);
          local_30 = (ushort *)((int)local_30 + iVar2);
          local_10 = local_10 + iVar2;
          local_18 = 0;
          local_34 = local_10 + 2;
          local_1c = local_30 + 3;
          puVar3 = local_30 + 2;
          local_2c = puVar3;
          do {
            *local_30 = (ushort)(byte)texgammatable[*local_10];
            local_2c[-1] = (ushort)(byte)texgammatable[local_34[-1]];
            *puVar3 = (ushort)(byte)texgammatable[*local_34];
            *local_1c = 0;
            local_30[4] = (ushort)(byte)texgammatable[local_10[3]];
            local_2c[3] = (ushort)(byte)texgammatable[local_34[2]];
            puVar3[4] = (ushort)(byte)texgammatable[local_34[3]];
            local_1c[4] = 0;
            local_30[8] = (ushort)(byte)texgammatable[local_10[6]];
            local_2c[7] = (ushort)(byte)texgammatable[local_34[5]];
            puVar3[8] = (ushort)(byte)texgammatable[local_34[6]];
            local_1c[8] = 0;
            local_30[0xc] = (ushort)(byte)texgammatable[local_10[9]];
            local_2c[0xb] = (ushort)(byte)texgammatable[local_34[8]];
            puVar3[0xc] = (ushort)(byte)texgammatable[local_34[9]];
            puVar3 = puVar3 + 0x10;
            local_2c = local_2c + 0x10;
            local_1c[0xc] = 0;
            local_1c = local_1c + 0x10;
            local_30 = local_30 + 0x10;
            local_34 = local_34 + 0xc;
            local_10 = local_10 + 0xc;
            local_18 = local_18 + 4;
          } while (local_18 < 0x100);
          local_20 = local_20 + 0x14;
          local_24 = local_24 + 0x14;
          local_28 = local_28 + 0x14;
          local_8 = local_8 + 1;
        } while (local_8 < *(int *)(param_2 + 0xb4));
      }
    }
  }
  return;
}


// Mod_LoadSubmodels  @ 00063b28
void Mod_LoadSubmodels(int *param_1)

{
  uint uVar1;
  float *pfVar2;
  float fVar3;
  undefined4 *puVar4;
  longdouble lVar5;
  undefined4 *local_14;
  float *local_10;
  int local_8;
  
  puVar4 = (undefined4 *)(*param_1 + mod_base);
  uVar1 = param_1[1];
  if ((uVar1 & 0x3f) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar1 = param_1[1];
  }
  uVar1 = uVar1 >> 6;
  pfVar2 = (float *)Hunk_AllocName(uVar1 << 6,loadname);
  *(float **)(loadmodel + 0x7c) = pfVar2;
  local_8 = 0;
  *(uint *)(loadmodel + 0x78) = uVar1;
  if (uVar1 != 0) {
    local_10 = pfVar2 + 0xf;
    local_14 = puVar4 + 0xf;
    do {
      lVar5 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar2 = (float)(lVar5 - (longdouble)1.0);
      lVar5 = (longdouble)(*LittleFloat)(puVar4[3]);
      pfVar2[3] = (float)(lVar5 + (longdouble)1.0);
      lVar5 = (longdouble)(*LittleFloat)(puVar4[6]);
      pfVar2[6] = (float)lVar5;
      lVar5 = (longdouble)(*LittleFloat)(puVar4[1]);
      pfVar2[1] = (float)(lVar5 - (longdouble)1.0);
      lVar5 = (longdouble)(*LittleFloat)(puVar4[4]);
      pfVar2[4] = (float)(lVar5 + (longdouble)1.0);
      lVar5 = (longdouble)(*LittleFloat)(puVar4[7]);
      pfVar2[7] = (float)lVar5;
      lVar5 = (longdouble)(*LittleFloat)(puVar4[2]);
      pfVar2[2] = (float)(lVar5 - (longdouble)1.0);
      lVar5 = (longdouble)(*LittleFloat)(puVar4[5]);
      pfVar2[5] = (float)(lVar5 + (longdouble)1.0);
      lVar5 = (longdouble)(*LittleFloat)(puVar4[8]);
      pfVar2[8] = (float)lVar5;
      fVar3 = (float)(*LittleLong)(puVar4[9]);
      pfVar2[9] = fVar3;
      fVar3 = (float)(*LittleLong)(puVar4[10]);
      pfVar2[10] = fVar3;
      fVar3 = (float)(*LittleLong)(puVar4[0xb]);
      pfVar2[0xb] = fVar3;
      fVar3 = (float)(*LittleLong)(puVar4[0xc]);
      pfVar2[0xc] = fVar3;
      fVar3 = (float)(*LittleLong)(local_14[-2]);
      local_10[-2] = fVar3;
      fVar3 = (float)(*LittleLong)(local_14[-1]);
      local_10[-1] = fVar3;
      fVar3 = (float)(*LittleLong)(*local_14);
      puVar4 = puVar4 + 0x10;
      pfVar2 = pfVar2 + 0x10;
      *local_10 = fVar3;
      local_8 = local_8 + 1;
      local_14 = local_14 + 0x10;
      local_10 = local_10 + 0x10;
    } while (local_8 < (int)uVar1);
  }
  return;
}


// Mod_LoadSurfedges  @ 00065478
void Mod_LoadSurfedges(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint local_8;
  
  puVar5 = (undefined4 *)(*param_1 + mod_base);
  uVar1 = param_1[1];
  if ((uVar1 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar1 = param_1[1];
  }
  uVar1 = uVar1 >> 2;
  puVar2 = (undefined4 *)Hunk_AllocName(uVar1 * 4,loadname);
  *(undefined4 **)(loadmodel + 0xbc) = puVar2;
  local_8 = 0;
  *(uint *)(loadmodel + 0xb8) = uVar1;
  if (uVar1 != 0) {
    uVar3 = uVar1 & 3;
    if (uVar3 == 0) goto LAB_00065578;
    if (1 < uVar3) {
      if (2 < uVar3) {
        uVar4 = (*LittleLong)(*puVar5);
        *puVar2 = uVar4;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      local_8 = (uint)(2 < uVar3);
      uVar4 = (*LittleLong)(*puVar5);
      *puVar2 = uVar4;
      puVar2 = puVar2 + 1;
      puVar5 = puVar5 + 1;
      local_8 = local_8 + 1;
    }
    uVar4 = (*LittleLong)(*puVar5);
    *puVar2 = uVar4;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
    for (local_8 = local_8 + 1; (int)local_8 < (int)uVar1; local_8 = local_8 + 4) {
LAB_00065578:
      uVar4 = (*LittleLong)(*puVar5);
      *puVar2 = uVar4;
      uVar4 = (*LittleLong)(puVar5[1]);
      puVar2[1] = uVar4;
      uVar4 = (*LittleLong)(puVar5[2]);
      puVar2[2] = uVar4;
      uVar4 = (*LittleLong)(puVar5[3]);
      puVar2[3] = uVar4;
      puVar2 = puVar2 + 4;
      puVar5 = puVar5 + 4;
    }
  }
  return;
}


// Mod_LoadTexinfo  @ 00063ffc
void Mod_LoadTexinfo(int *param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  undefined4 *puVar5;
  longdouble lVar6;
  longdouble lVar7;
  float *local_1c;
  float *local_18;
  int local_8;
  
  puVar5 = (undefined4 *)(*param_1 + mod_base);
  uVar4 = param_1[1];
  if (uVar4 != (uVar4 / 0x28) * 0x28) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar4 = param_1[1];
  }
  uVar4 = uVar4 / 0x28;
  pfVar1 = (float *)Hunk_AllocName(uVar4 * 0x2c,loadname);
  *(float **)(loadmodel + 0xac) = pfVar1;
  local_8 = 0;
  *(uint *)(loadmodel + 0xa8) = uVar4;
  if (uVar4 != 0) {
    local_18 = pfVar1 + 10;
    local_1c = pfVar1 + 9;
    do {
      lVar6 = (longdouble)(*LittleFloat)(*puVar5);
      *pfVar1 = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(puVar5[1]);
      pfVar1[1] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(puVar5[2]);
      pfVar1[2] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(puVar5[3]);
      pfVar1[3] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(puVar5[4]);
      pfVar1[4] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(puVar5[5]);
      pfVar1[5] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(puVar5[6]);
      pfVar1[6] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(puVar5[7]);
      pfVar1[7] = (float)lVar6;
      lVar6 = (longdouble)Length(pfVar1);
      lVar7 = (longdouble)Length(pfVar1 + 4);
      lVar7 = (longdouble)0.5 * (lVar7 + (longdouble)(float)lVar6);
      lVar6 = (longdouble)0.32;
      if ((byte)((lVar6 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
        lVar6 = (longdouble)0.49;
        if ((byte)((lVar6 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
          lVar6 = (longdouble)0.99;
          if ((byte)((lVar6 < lVar7 |
                      (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar7)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(lVar6 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
            local_1c[-1] = 1.0;
          }
          else {
            local_1c[-1] = 2.0;
          }
        }
        else {
          local_1c[-1] = 3.0;
        }
      }
      else {
        local_1c[-1] = 4.0;
      }
      iVar2 = (*LittleLong)(puVar5[8]);
      fVar3 = (float)(*LittleLong)(puVar5[9]);
      *local_18 = fVar3;
      if (*(int *)(loadmodel + 0x174) == 0) {
        *local_1c = r_notexture_mip;
        *local_18 = 0.0;
      }
      else {
        if (*(int *)(loadmodel + 0x170) <= iVar2) {
          Sys_Error("miptex >= loadmodel->numtextures");
        }
        fVar3 = *(float *)(*(int *)(loadmodel + 0x174) + iVar2 * 4);
        *local_1c = fVar3;
        if (fVar3 == 0.0) {
          *local_1c = r_notexture_mip;
          *local_18 = 0.0;
        }
      }
      local_8 = local_8 + 1;
      puVar5 = puVar5 + 10;
      local_1c = local_1c + 0xb;
      local_18 = local_18 + 0xb;
      pfVar1 = pfVar1 + 0xb;
    } while (local_8 < (int)uVar4);
  }
  return;
}


// Mod_LoadTextures  @ 00062b08
void Mod_LoadTextures(int *param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  undefined1 *puVar11;
  ushort *puVar12;
  longdouble lVar13;
  longdouble lVar14;
  uint uStack_5540c;
  char *pcStack_55408;
  ushort *puStack_55400;
  ushort *puStack_553fc;
  int *piStack_553f8;
  byte *pbStack_553f4;
  byte *pbStack_553f0;
  ushort *puStack_553ec;
  byte *pbStack_553e8;
  int iStack_553ac;
  int iStack_553a8;
  int iStack_5539c;
  undefined1 auStack_55398 [348996];
  int local_54 [10];
  int local_2c [10];
  
  bVar2 = false;
  lVar13 = (longdouble)Sys_FloatTime();
  if (tested == 0) {
    Mod_AdInit();
  }
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x174) = 0;
  }
  else {
    piVar10 = (int *)(*param_1 + mod_base);
    iVar3 = (*LittleLong)();
    *piVar10 = iVar3;
    *(int *)(loadmodel + 0x170) = iVar3;
    uVar4 = Hunk_AllocName(*piVar10 << 2,loadname);
    iStack_5539c = 0;
    *(undefined4 *)(loadmodel + 0x174) = uVar4;
    iVar3 = *piVar10;
    piStack_553f8 = piVar10;
    if (0 < iVar3) {
      do {
        piStack_553f8 = piStack_553f8 + 1;
        iVar3 = (*LittleLong)();
        *piStack_553f8 = iVar3;
        if (iVar3 != -1) {
          if (((byte)((byte)((ushort)((ushort)NAN((float)r_wadtextures._12_4_) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)r_wadtextures._12_4_ == 0.0) << 0xe) >> 8)) !=
               0x40) ||
             (iVar5 = (*LittleLong)(), puVar11 = (undefined1 *)((int)piVar10 + iVar3), iVar5 == 0))
          {
            puVar11 = auStack_55398;
            if (!bVar2) {
              TEX_InitFromWad();
              TEX_AddAnimatingTextures();
              bVar2 = true;
            }
            iVar3 = TEX_LoadLump((undefined1 *)((int)piVar10 + iVar3),puVar11);
            if (iVar3 == 0) {
              *piStack_553f8 = -1;
              goto LAB_00063325;
            }
          }
          uVar4 = (*LittleLong)();
          *(undefined4 *)(puVar11 + 0x18) = uVar4;
          uVar4 = (*LittleLong)();
          *(undefined4 *)(puVar11 + 0x1c) = uVar4;
          uVar4 = (*LittleLong)();
          *(undefined4 *)(puVar11 + 0x20) = uVar4;
          uVar4 = (*LittleLong)();
          *(undefined4 *)(puVar11 + 0x24) = uVar4;
          uVar4 = (*LittleLong)();
          *(undefined4 *)(puVar11 + 0x10) = uVar4;
          uVar6 = (*LittleLong)(*(undefined4 *)(puVar11 + 0x14));
          *(uint *)(puVar11 + 0x14) = uVar6;
          uVar9 = *(uint *)(puVar11 + 0x10);
          if (((uVar9 & 0xf) != 0) || ((uVar6 & 0xf) != 0)) {
            Sys_Error("Texture %s is not 16 aligned");
            uVar9 = *(uint *)(puVar11 + 0x10);
          }
          iVar3 = (uVar9 * *(int *)(puVar11 + 0x14) >> 6) * 0x55;
          uVar1 = *(ushort *)(puVar11 + iVar3 + 0x28);
          uVar9 = (uint)uVar1;
          pcVar7 = (char *)Hunk_AllocName(iVar3 + 0x42 + uVar9 * 8);
          *(char **)(*(int *)(loadmodel + 0x174) + iStack_5539c * 4) = pcVar7;
          Q_memcpy(pcVar7,puVar11,0x10);
          pcVar8 = strchr(pcVar7,0x7e);
          if (pcVar8 != (char *)0x0) {
            pcVar7[2] = ' ';
          }
          *(undefined4 *)(pcVar7 + 0x10) = *(undefined4 *)(puVar11 + 0x10);
          *(undefined4 *)(pcVar7 + 0x14) = *(undefined4 *)(puVar11 + 0x14);
          *(int *)(pcVar7 + 0x2c) = *(int *)(puVar11 + 0x18) + 0x18;
          *(int *)(pcVar7 + 0x30) = *(int *)(puVar11 + 0x1c) + 0x18;
          *(int *)(pcVar7 + 0x34) = *(int *)(puVar11 + 0x20) + 0x18;
          *(int *)(pcVar7 + 0x38) = *(int *)(puVar11 + 0x24) + 0x18;
          *(int *)(pcVar7 + 0x3c) = iVar3 + 0x42;
          Q_memcpy(pcVar7 + 0x40,puVar11 + 0x28);
          pbStack_553f4 = puVar11 + iVar3 + 0x2a;
          puStack_553fc = (ushort *)(pcVar7 + iVar3 + 0x42);
          iVar5 = Q_strncmp(puVar11,&DAT_000a86c2,3);
          if (iVar5 == 0) {
            R_InitSky();
          }
          uStack_5540c = 0;
          if (uVar9 != 0) {
            pbStack_553e8 = puVar11 + iVar3 + 0x2c;
            puStack_553ec = (ushort *)(pcVar7 + iVar3 + 0x44);
            pbStack_553f0 = puVar11 + iVar3 + 0x2b;
            puVar12 = (ushort *)(pcVar7 + iVar3 + 0x46);
            pcStack_55408 = pcVar7 + iVar3 + 0x48;
            uVar6 = uVar9 & 3;
            if ((uVar1 & 3) != 0) {
              if (1 < uVar6) {
                if (2 < uVar6) {
                  (pcVar7 + iVar3 + 0x48)[0] = '\0';
                  (pcVar7 + iVar3 + 0x48)[1] = '\0';
                  *(ushort *)(pcVar7 + iVar3 + 0x46) =
                       (ushort)(byte)texgammatable[(byte)puVar11[iVar3 + 0x2a]];
                  *(ushort *)(pcVar7 + iVar3 + 0x44) =
                       (ushort)(byte)texgammatable[(byte)puVar11[iVar3 + 0x2b]];
                  *(ushort *)(pcVar7 + iVar3 + 0x42) =
                       (ushort)(byte)texgammatable[(byte)puVar11[iVar3 + 0x2c]];
                  pbStack_553e8 = puVar11 + iVar3 + 0x2f;
                  puStack_553ec = (ushort *)(pcVar7 + iVar3 + 0x4c);
                  pbStack_553f0 = puVar11 + iVar3 + 0x2e;
                  pbStack_553f4 = puVar11 + iVar3 + 0x2d;
                  puVar12 = (ushort *)(pcVar7 + iVar3 + 0x4e);
                  puStack_553fc = (ushort *)(pcVar7 + iVar3 + 0x4a);
                  pcStack_55408 = pcVar7 + iVar3 + 0x50;
                }
                uStack_5540c = (uint)(2 < uVar6);
                pcStack_55408[0] = '\0';
                pcStack_55408[1] = '\0';
                *puVar12 = (ushort)(byte)texgammatable[*pbStack_553f4];
                puVar12 = puVar12 + 4;
                *puStack_553ec = (ushort)(byte)texgammatable[*pbStack_553f0];
                *puStack_553fc = (ushort)(byte)texgammatable[*pbStack_553e8];
                pbStack_553e8 = pbStack_553e8 + 3;
                puStack_553ec = puStack_553ec + 4;
                pbStack_553f0 = pbStack_553f0 + 3;
                pbStack_553f4 = pbStack_553f4 + 3;
                puStack_553fc = puStack_553fc + 4;
                pcStack_55408 = pcStack_55408 + 8;
                uStack_5540c = uStack_5540c + 1;
              }
              pcStack_55408[0] = '\0';
              pcStack_55408[1] = '\0';
              *puVar12 = (ushort)(byte)texgammatable[*pbStack_553f4];
              puVar12 = puVar12 + 4;
              *puStack_553ec = (ushort)(byte)texgammatable[*pbStack_553f0];
              *puStack_553fc = (ushort)(byte)texgammatable[*pbStack_553e8];
              pbStack_553e8 = pbStack_553e8 + 3;
              puStack_553ec = puStack_553ec + 4;
              pbStack_553f0 = pbStack_553f0 + 3;
              pbStack_553f4 = pbStack_553f4 + 3;
              puStack_553fc = puStack_553fc + 4;
              pcStack_55408 = pcStack_55408 + 8;
              uStack_5540c = uStack_5540c + 1;
              if (uVar9 <= uStack_5540c) goto LAB_000632e9;
            }
            puStack_55400 = puStack_553fc;
            do {
              pcStack_55408[0] = '\0';
              pcStack_55408[1] = '\0';
              *puVar12 = (ushort)(byte)texgammatable[*pbStack_553f4];
              *puStack_553ec = (ushort)(byte)texgammatable[*pbStack_553f0];
              *puStack_55400 = (ushort)(byte)texgammatable[*pbStack_553e8];
              pcStack_55408[8] = '\0';
              pcStack_55408[9] = '\0';
              puVar12[4] = (ushort)(byte)texgammatable[pbStack_553f4[3]];
              puStack_553ec[4] = (ushort)(byte)texgammatable[pbStack_553f0[3]];
              puStack_55400[4] = (ushort)(byte)texgammatable[pbStack_553e8[3]];
              pcStack_55408[0x10] = '\0';
              pcStack_55408[0x11] = '\0';
              puVar12[8] = (ushort)(byte)texgammatable[pbStack_553f4[6]];
              puStack_553ec[8] = (ushort)(byte)texgammatable[pbStack_553f0[6]];
              puStack_55400[8] = (ushort)(byte)texgammatable[pbStack_553e8[6]];
              pcStack_55408[0x18] = '\0';
              pcStack_55408[0x19] = '\0';
              puVar12[0xc] = (ushort)(byte)texgammatable[pbStack_553f4[9]];
              puVar12 = puVar12 + 0x10;
              puStack_553ec[0xc] = (ushort)(byte)texgammatable[pbStack_553f0[9]];
              puStack_55400[0xc] = (ushort)(byte)texgammatable[pbStack_553e8[9]];
              pbStack_553e8 = pbStack_553e8 + 0xc;
              puStack_553ec = puStack_553ec + 0x10;
              pbStack_553f0 = pbStack_553f0 + 0xc;
              pbStack_553f4 = pbStack_553f4 + 0xc;
              puStack_55400 = puStack_55400 + 0x10;
              pcStack_55408 = pcStack_55408 + 0x20;
              uStack_5540c = uStack_5540c + 4;
            } while ((int)uStack_5540c < (int)uVar9);
          }
LAB_000632e9:
          if ((ad_enabled != 0) && (iVar5 = Q_stricmp(pcVar7), iVar5 == 0)) {
            Mod_AdSwap(pcVar7,iVar3);
          }
        }
LAB_00063325:
        iStack_5539c = iStack_5539c + 1;
        iVar3 = *piVar10;
      } while (iStack_5539c < iVar3);
    }
    if (bVar2) {
      TEX_CleanupWadInfo();
      iVar3 = *piVar10;
    }
    iStack_5539c = 0;
    if (0 < iVar3) {
      do {
        pcVar7 = *(char **)(*(int *)(loadmodel + 0x174) + iStack_5539c * 4);
        if ((pcVar7 != (char *)0x0) &&
           (((*pcVar7 == '+' || (*pcVar7 == '-')) && (*(int *)(pcVar7 + 0x24) == 0)))) {
          Q_memset(local_2c,0,0x28);
          Q_memset(local_54,0,0x28);
          iStack_553a8 = (int)pcVar7[1];
          iStack_553ac = 0;
          if (iStack_553a8 - 0x61U < 0x1a) {
            iStack_553a8 = iStack_553a8 + -0x20;
          }
          iVar3 = iStack_553a8;
          if (iStack_553a8 - 0x30U < 10) {
            local_2c[iStack_553a8 - 0x30U] = (int)pcVar7;
            iStack_553a8 = iStack_553a8 + -0x2f;
          }
          else {
            uVar9 = iStack_553a8 - 0x41;
            if (uVar9 < 10) {
              iStack_553a8 = 0;
              local_54[uVar9] = (int)pcVar7;
              iStack_553ac = iVar3 + -0x40;
            }
            else {
              Sys_Error();
            }
          }
          uStack_5540c = iStack_5539c + 1;
          if ((int)uStack_5540c < *piVar10) {
            do {
              pcVar7 = *(char **)(*(int *)(loadmodel + 0x174) + uStack_5540c * 4);
              if (((pcVar7 != (char *)0x0) && ((*pcVar7 == '+' || (*pcVar7 == '-')))) &&
                 (iVar3 = Q_strcmp(), iVar3 == 0)) {
                iVar3 = (int)pcVar7[1];
                if (iVar3 - 0x61U < 0x1a) {
                  iVar3 = iVar3 + -0x20;
                }
                if (iVar3 - 0x30U < 10) {
                  local_2c[iVar3 - 0x30U] = (int)pcVar7;
                  if (iStack_553a8 < iVar3 + -0x2f) {
                    iStack_553a8 = iVar3 + -0x2f;
                  }
                }
                else if (iVar3 - 0x41U < 10) {
                  local_54[iVar3 - 0x41U] = (int)pcVar7;
                  if (iStack_553ac < iVar3 + -0x40) {
                    iStack_553ac = iVar3 + -0x40;
                  }
                }
                else {
                  Sys_Error();
                }
              }
              uStack_5540c = uStack_5540c + 1;
            } while ((int)uStack_5540c < *piVar10);
          }
          uStack_5540c = 0;
          if (0 < iStack_553a8) {
            do {
              iVar3 = local_2c[uStack_5540c];
              if (iVar3 == 0) {
                Sys_Error("Missing frame %i of %s");
              }
              *(int *)(iVar3 + 0x18) = iStack_553a8;
              *(uint *)(iVar3 + 0x1c) = uStack_5540c;
              uStack_5540c = uStack_5540c + 1;
              *(uint *)(iVar3 + 0x20) = uStack_5540c;
              *(int *)(iVar3 + 0x24) = local_2c[(int)uStack_5540c % iStack_553a8];
              if (iStack_553ac != 0) {
                *(int *)(iVar3 + 0x28) = local_54[0];
              }
            } while ((int)uStack_5540c < iStack_553a8);
          }
          uStack_5540c = 0;
          if (0 < iStack_553ac) {
            do {
              iVar3 = local_54[uStack_5540c];
              if (iVar3 == 0) {
                Sys_Error("Missing frame %i of %s");
              }
              *(int *)(iVar3 + 0x18) = iStack_553ac;
              *(uint *)(iVar3 + 0x1c) = uStack_5540c;
              uStack_5540c = uStack_5540c + 1;
              *(uint *)(iVar3 + 0x20) = uStack_5540c;
              *(int *)(iVar3 + 0x24) = local_54[(int)uStack_5540c % iStack_553ac];
              if (iStack_553a8 != 0) {
                *(int *)(iVar3 + 0x28) = local_2c[0];
              }
            } while ((int)uStack_5540c < iStack_553ac);
          }
        }
        iStack_5539c = iStack_5539c + 1;
      } while (iStack_5539c < *piVar10);
    }
    lVar14 = (longdouble)Sys_FloatTime();
    Con_DPrintf("Texture load: %6.1fms\n",
                (double)((longdouble)1000.0 * (lVar14 - (longdouble)(double)lVar13)));
  }
  return;
}


// Mod_LoadVertexes  @ 000638fc
void Mod_LoadVertexes(int *param_1)

{
  uint uVar1;
  longdouble lVar2;
  undefined4 *local_1c;
  float *local_18;
  int local_10;
  float *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*param_1 + mod_base);
  uVar1 = param_1[1];
  if (uVar1 != (uVar1 / 0xc) * 0xc) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar1 = param_1[1];
  }
  uVar1 = uVar1 / 0xc;
  local_c = (float *)Hunk_AllocName(uVar1 * 0xc,loadname);
  *(float **)(loadmodel + 0x94) = local_c;
  local_10 = 0;
  *(uint *)(loadmodel + 0x90) = uVar1;
  if (uVar1 != 0) {
    local_18 = local_c + 2;
    local_1c = local_8 + 2;
    if ((uVar1 & 1) != 0) {
      lVar2 = (longdouble)(*LittleFloat)(*local_8);
      *local_c = (float)lVar2;
      lVar2 = (longdouble)(*LittleFloat)(local_8[1]);
      local_c[1] = (float)lVar2;
      lVar2 = (longdouble)(*LittleFloat)(local_8[2]);
      local_10 = 1;
      local_c[2] = (float)lVar2;
      local_1c = local_8 + 5;
      local_8 = local_8 + 3;
      local_18 = local_c + 5;
      local_c = local_c + 3;
      if (uVar1 < 2) {
        return;
      }
    }
    do {
      lVar2 = (longdouble)(*LittleFloat)(*local_8);
      *local_c = (float)lVar2;
      lVar2 = (longdouble)(*LittleFloat)(local_1c[-1]);
      local_18[-1] = (float)lVar2;
      lVar2 = (longdouble)(*LittleFloat)(*local_1c);
      *local_18 = (float)lVar2;
      lVar2 = (longdouble)(*LittleFloat)(local_8[3]);
      local_c[3] = (float)lVar2;
      lVar2 = (longdouble)(*LittleFloat)(local_1c[2]);
      local_18[2] = (float)lVar2;
      lVar2 = (longdouble)(*LittleFloat)(local_1c[3]);
      local_18[3] = (float)lVar2;
      local_10 = local_10 + 2;
      local_1c = local_1c + 6;
      local_8 = local_8 + 6;
      local_18 = local_18 + 6;
      local_c = local_c + 6;
    } while (local_10 < (int)uVar1);
  }
  return;
}


// Mod_LoadVisibility  @ 00063780
void Mod_LoadVisibility(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x178) = 0;
  }
  else {
    uVar1 = Hunk_AllocName(param_1[1],loadname);
    *(undefined4 *)(loadmodel + 0x178) = uVar1;
    Q_memcpy(*(undefined4 *)(loadmodel + 0x178),*param_1 + mod_base,param_1[1]);
  }
  return;
}


// Mod_MakeHull0  @ 00065134
void Mod_MakeHull0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 *puVar6;
  int *local_18;
  undefined4 *local_14;
  int local_c;
  
  iVar4 = loadmodel;
  iVar1 = *(int *)(loadmodel + 0xa4);
  iVar2 = *(int *)(loadmodel + 0xa0);
  local_18 = (int *)Hunk_AllocName(iVar2 * 8,loadname);
  *(int **)(iVar4 + 0xd0) = local_18;
  *(undefined4 *)(iVar4 + 0xd8) = 0;
  *(int *)(iVar4 + 0xdc) = iVar2 + -1;
  local_c = 0;
  *(undefined4 *)(iVar4 + 0xd4) = *(undefined4 *)(loadmodel + 0x84);
  if (0 < iVar2) {
    local_14 = (undefined4 *)(iVar1 + 0x1c);
    puVar6 = (undefined4 *)(iVar1 + 0x20);
    do {
      *local_18 = (puVar6[-2] - *(int *)(loadmodel + 0x84)) * -0x33333333 >> 2;
      piVar3 = (int *)*local_14;
      if (*piVar3 < 0) {
        uVar5 = (undefined2)*piVar3;
      }
      else {
        uVar5 = (undefined2)(((int)piVar3 - *(int *)(loadmodel + 0xa4)) * -0x33333333 >> 3);
      }
      *(undefined2 *)(local_18 + 1) = uVar5;
      piVar3 = (int *)*puVar6;
      if (*piVar3 < 0) {
        uVar5 = (undefined2)*piVar3;
      }
      else {
        uVar5 = (undefined2)(((int)piVar3 - *(int *)(loadmodel + 0xa4)) * -0x33333333 >> 3);
      }
      *(undefined2 *)((int)local_18 + 6) = uVar5;
      local_c = local_c + 1;
      local_18 = local_18 + 2;
      puVar6 = puVar6 + 10;
      local_14 = local_14 + 10;
    } while (local_c < iVar2);
  }
  return;
}


// Mod_MarkClient  @ 00062778
void Mod_MarkClient(int param_1)

{
  *(undefined4 *)(param_1 + 0x40) = 3;
  return;
}


// Mod_PointInLeaf  @ 00062438
int * Mod_PointInLeaf(float *param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  int *piVar3;
  
  if ((param_2 == 0) || (piVar3 = *(int **)(param_2 + 0xa4), piVar3 == (int *)0x0)) {
    Sys_Error("Mod_PointInLeaf: bad model");
    piVar3 = *(int **)(param_2 + 0xa4);
  }
  while (-1 < *piVar3) {
    pfVar2 = (float *)piVar3[6];
    if (*(byte *)(pfVar2 + 4) < 3) {
      fVar1 = param_1[*(byte *)(pfVar2 + 4)];
    }
    else {
      fVar1 = param_1[2] * pfVar2[2] + param_1[1] * pfVar2[1] + *param_1 * *pfVar2;
    }
    if (fVar1 - pfVar2[3] <= 0.0) {
      piVar3 = (int *)piVar3[8];
    }
    else {
      piVar3 = (int *)piVar3[7];
    }
  }
  return piVar3;
}


// Mod_Print  @ 000679f4
void Mod_Print(void)

{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  int local_8;
  
  Con_Printf("Cached models:\n");
  local_8 = 0;
  puVar3 = mod_known;
  if (0 < mod_numknown) {
    puVar2 = (uint *)(mod_known + 0x40);
    do {
      Con_Printf("%8p : %s",puVar2[0x51],puVar3);
      uVar1 = *puVar2;
      if ((uVar1 & 2) != 0) {
        Con_Printf(" (!R)");
        uVar1 = *puVar2;
      }
      if ((uVar1 & 1) != 0) {
        Con_Printf(" (!P)");
      }
      Con_Printf(&DAT_000a8bb3);
      local_8 = local_8 + 1;
      puVar2 = puVar2 + 0x62;
      puVar3 = puVar3 + 0x188;
    } while (local_8 < mod_numknown);
  }
  return;
}


// Mod_SetParent  @ 000648a8
void Mod_SetParent(int *param_1,int param_2)

{
  param_1[5] = param_2;
  if (-1 < *param_1) {
    Mod_SetParent(param_1[7],param_1);
    Mod_SetParent(param_1[8],param_1);
  }
  return;
}


// Mod_TouchModel  @ 000625fc
void Mod_TouchModel(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Mod_FindName(param_1);
  if ((*(int *)(iVar1 + 0x40) == 0) && (*(int *)(iVar1 + 0x44) - 2U < 2)) {
    Cache_Check(iVar1 + 0x184);
  }
  return;
}


// Mod_UnloadSpriteTextures  @ 000679d8
void Mod_UnloadSpriteTextures(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x44) == 1)) {
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  return;
}


