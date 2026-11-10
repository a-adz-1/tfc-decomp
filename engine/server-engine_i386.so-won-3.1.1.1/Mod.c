// Mod_AdInit  @ 0007b0e8
void Mod_AdInit(void)

{
  char *pcVar1;
  int iVar2;
  
  tested = 1;
  iVar2 = COM_CheckParm(&DAT_000e4b80);
  if (((iVar2 != 0) && (pcVar1 = *(char **)(iVar2 * 4 + com_argv + 4), pcVar1 != (char *)0x0)) &&
     (*pcVar1 != '\0')) {
    snprintf(filename_36,0x104,"%s",pcVar1);
    iVar2 = COM_FileSize(filename_36);
    if (iVar2 < 1) {
      Con_Printf("No -ad file specified, skipping\n");
    }
    else {
      Draw_CacheWadInit(filename_36,0x10,ad_wad);
      ad_enabled = 1;
    }
  }
  return;
}


// Mod_AdSwap  @ 0007b1e8
void Mod_AdSwap(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if (tested != 0) {
    uVar2 = Draw_CacheIndex(ad_wad,&DAT_000e4bc1);
    iVar3 = Draw_CacheGet(ad_wad,uVar2);
    if (iVar3 != 0) {
      Q_memcpy(param_1 + 0x40,iVar3 + 0x40,param_2);
      iVar1 = param_2 + param_1 + 0x42;
      iVar3 = param_2 + iVar3 + 0x42;
      for (local_8 = 0; local_8 < param_3; local_8 = local_8 + 1) {
        *(undefined2 *)(local_8 * 8 + iVar1 + 6) = 0;
        *(ushort *)(local_8 * 8 + iVar1 + 4) = (ushort)*(byte *)(iVar3 + local_8 * 3);
        *(ushort *)(local_8 * 8 + iVar1 + 2) = (ushort)*(byte *)(local_8 * 3 + iVar3 + 1);
        *(ushort *)(iVar1 + local_8 * 8) = (ushort)*(byte *)(local_8 * 3 + iVar3 + 2);
      }
    }
  }
  return;
}


// Mod_ChangeGame  @ 0007fb28
void Mod_ChangeGame(void)

{
  int iVar1;
  undefined1 *local_c;
  int local_8;
  
  local_c = mod_known;
  for (local_8 = 0; local_8 < mod_numknown; local_8 = local_8 + 1) {
    if (*(int *)(local_c + 0x44) == 3) {
      iVar1 = Cache_Check(local_c + 0x184);
      if (iVar1 != 0) {
        Cache_Free(local_c + 0x184);
      }
    }
    *(undefined4 *)(mod_known_info + local_8 * 0xc + 4) = 0;
    *(undefined4 *)(mod_known_info + local_8 * 0xc + 8) = 0;
    local_c = local_c + 0x188;
  }
  return;
}


// Mod_ClearAll  @ 0007a9ac
void Mod_ClearAll(void)

{
  undefined1 *local_c;
  int local_8;
  
  local_c = mod_known;
  for (local_8 = 0; local_8 < mod_numknown; local_8 = local_8 + 1) {
    if (*(int *)(local_c + 0x40) != 3) {
      *(undefined4 *)(local_c + 0x40) = 2;
    }
    local_c = local_c + 0x188;
  }
  return;
}


// Mod_DecompressVis  @ 00055984
undefined1 * Mod_DecompressVis(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = mod_novis;
  }
  else {
    CM_DecompressPVS(param_1,decompressed_6,*(int *)(param_2 + 0x88) + 7 >> 3);
    puVar1 = decompressed_6;
  }
  return puVar1;
}


// Mod_Extradata  @ 0007a7ec
int Mod_Extradata(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = Cache_Check(param_1 + 0x184);
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x44) == 0) {
        Sys_Error("Mod_ExtraData called with mod_brush!\n");
      }
      Mod_LoadModel(param_1,1,0);
      if (*(int *)(param_1 + 0x184) == 0) {
        Sys_Error("Mod_Extradata: caching failed");
      }
      iVar1 = *(int *)(param_1 + 0x184);
    }
  }
  return iVar1;
}


// Mod_FillInCRCInfo  @ 0007aa0c
void Mod_FillInCRCInfo(undefined4 param_1,int param_2)

{
  param_2 = param_2 * 0xc;
  *(undefined4 *)(mod_known_info + param_2) = param_1;
  *(undefined4 *)(mod_known_info + param_2 + 4) = 0;
  *(undefined4 *)(mod_known_info + param_2 + 8) = 0;
  return;
}


// Mod_FindName  @ 0007aa60
undefined1 * Mod_FindName(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_10 = (undefined1 *)0x0;
  if (*param_2 == '\0') {
    Sys_Error("Mod_ForName: NULL name");
  }
  local_8 = 0;
  local_c = mod_known;
  while ((local_8 < mod_numknown && (iVar1 = Q_strcasecmp(local_c,param_2), iVar1 != 0))) {
    if ((*(int *)(local_c + 0x40) == 2) &&
       ((local_10 == (undefined1 *)0x0 ||
        ((*(int *)(local_c + 0x44) != 2 && (*(int *)(local_c + 0x44) != 3)))))) {
      local_10 = local_c;
    }
    local_8 = local_8 + 1;
    local_c = local_c + 0x188;
  }
  if (local_8 == mod_numknown) {
    if (mod_numknown < 0x400) {
      Mod_FillInCRCInfo(param_1,mod_numknown);
      mod_numknown = mod_numknown + 1;
    }
    else if (local_10 == (undefined1 *)0x0) {
      Sys_Error("mod_numknown >= MAX_KNOWN_MODELS");
    }
    else {
      local_c = local_10;
      Mod_FillInCRCInfo(param_1,(int)(local_10 + -0x300980) * 0x1a1f58d1 >> 3);
    }
    Q_strncpy(local_c,param_2,0x3f);
    local_c[0x3f] = 0;
    if (*(int *)(local_c + 0x40) != 3) {
      *(undefined4 *)(local_c + 0x40) = 1;
    }
  }
  return local_c;
}


// Mod_ForName  @ 0007b084
undefined4 Mod_ForName(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  uVar2 = 0x7b090;
  local_c = 0;
  iVar1 = Mod_FindName(param_3,param_1);
  if (iVar1 != 0) {
    local_c = Mod_LoadModel(iVar1,param_2,param_3,uVar2);
  }
  return local_c;
}


// Mod_Init  @ 00055944
void Mod_Init(void)

{
  SW_Mod_Init();
  Q_memset(mod_novis,0xff,0x400);
  return;
}


// Mod_LeafPVS  @ 000559ec
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


// Mod_LoadAliasFrame  @ 0007e274
int Mod_LoadAliasFrame(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,
                      undefined4 param_7)

{
  int iVar1;
  int local_1c;
  int local_14;
  int local_10;
  
  Q_strcpy(param_7,param_1 + 8);
  for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
    *(undefined1 *)(local_10 + param_4) = *(undefined1 *)(local_10 + param_1);
    *(undefined1 *)(local_10 + param_5) = *(undefined1 *)(local_10 + param_1 + 4);
  }
  iVar1 = Hunk_AllocName(param_3 * 4,loadname);
  *param_2 = iVar1 - param_6;
  for (local_14 = 0; local_14 < param_3; local_14 = local_14 + 1) {
    *(undefined1 *)(iVar1 + 3 + local_14 * 4) = *(undefined1 *)(param_1 + 0x1b + local_14 * 4);
    for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
      *(undefined1 *)(local_1c + iVar1 + local_14 * 4) =
           *(undefined1 *)(local_1c + local_14 * 4 + param_1 + 0x18);
    }
  }
  return param_1 + 0x18 + param_3 * 4;
}


// Mod_LoadAliasGroup  @ 0007e3e8
undefined4 *
Mod_LoadAliasGroup(undefined4 *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,
                  int param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  longdouble lVar3;
  undefined4 *local_20;
  float *local_1c;
  undefined4 *local_18;
  int local_10;
  
  iVar1 = (*LittleLong)(*param_1);
  piVar2 = (int *)Hunk_AllocName((iVar1 + -1) * 0xc + 0x14,loadname);
  *piVar2 = iVar1;
  for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
    *(undefined1 *)(local_10 + param_4) = *(undefined1 *)((int)param_1 + local_10 + 4);
    *(undefined1 *)(local_10 + param_5) = *(undefined1 *)((int)param_1 + local_10 + 8);
  }
  *param_2 = (int)piVar2 - param_6;
  local_18 = param_1 + 3;
  local_1c = (float *)Hunk_AllocName(iVar1 * 4,loadname);
  piVar2[1] = (int)local_1c - param_6;
  for (local_10 = 0; local_10 < iVar1; local_10 = local_10 + 1) {
    lVar3 = (longdouble)(*LittleFloat)(*local_18);
    *local_1c = (float)lVar3;
    if (*local_1c <= 0.0) {
      Sys_Error("Mod_LoadAliasGroup: interval<=0");
    }
    local_1c = local_1c + 1;
    local_18 = local_18 + 1;
  }
  local_20 = local_18;
  for (local_10 = 0; local_10 < iVar1; local_10 = local_10 + 1) {
    local_20 = (undefined4 *)
               Mod_LoadAliasFrame(local_20,piVar2 + local_10 * 3 + 4,param_3,
                                  piVar2 + local_10 * 3 + 2,piVar2 + local_10 * 3 + 3,param_6,
                                  param_7);
  }
  return local_20;
}


// Mod_LoadAliasModel  @ 0007e850
void Mod_LoadAliasModel(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longdouble lVar11;
  int local_60;
  undefined4 *local_3c;
  undefined4 *local_38;
  int local_8;
  
  iVar2 = Hunk_LowMark();
  iVar3 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar3 != 6) {
    Sys_Error("%s has wrong version number (%i should be %i)",param_1,iVar3,6);
  }
  iVar3 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x3c));
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 0x40));
  piVar6 = (int *)Hunk_AllocName(iVar5 * 0x10 + (iVar3 + -1) * 0x20 + iVar4 * 0xc + 0x88,loadname);
  iVar3 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  iVar3 = iVar3 + -1;
  uVar7 = (*LittleLong)(*(undefined4 *)(param_2 + 0x4c));
  *(undefined4 *)(param_1 + 0x50) = uVar7;
  lVar11 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x20));
  piVar6[iVar3 * 8 + 0x15] = (int)(float)lVar11;
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x30));
  piVar6[iVar3 * 8 + 0x19] = iVar4;
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x34));
  piVar6[iVar3 * 8 + 0x1a] = iVar4;
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x38));
  piVar6[iVar3 * 8 + 0x1b] = iVar4;
  if (0x1e0 < piVar6[iVar3 * 8 + 0x1b]) {
    Sys_Error("model %s has a skin taller than %d",param_1,0x1e0);
  }
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x3c));
  piVar6[iVar3 * 8 + 0x1c] = iVar4;
  if (piVar6[iVar3 * 8 + 0x1c] < 1) {
    Sys_Error("model %s has no vertices",param_1);
  }
  if (2000 < piVar6[iVar3 * 8 + 0x1c]) {
    Sys_Error("model %s has too many vertices",param_1);
  }
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x40));
  piVar6[iVar3 * 8 + 0x1d] = iVar4;
  if (piVar6[iVar3 * 8 + 0x1d] < 1) {
    Sys_Error("model %s has no triangles",param_1);
  }
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  piVar6[iVar3 * 8 + 0x1e] = iVar4;
  lVar11 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x50));
  piVar6[iVar3 * 8 + 0x21] = (int)(float)((longdouble)0.09090909090909091 * lVar11);
  uVar7 = (*LittleLong)(*(undefined4 *)(param_2 + 0x48));
  *(undefined4 *)(param_1 + 0x4c) = uVar7;
  *(int *)(param_1 + 0x48) = piVar6[iVar3 * 8 + 0x1e];
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    lVar11 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_8 * 4 + param_2 + 8));
    piVar6[iVar3 * 8 + local_8 + 0xf] = (int)(float)lVar11;
    lVar11 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_8 * 4 + param_2 + 0x14));
    piVar6[iVar3 * 8 + local_8 + 0x12] = (int)(float)lVar11;
    lVar11 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_8 * 4 + param_2 + 0x24));
    piVar6[iVar3 * 8 + local_8 + 0x16] = (int)(float)lVar11;
  }
  iVar4 = piVar6[iVar3 * 8 + 0x19];
  iVar5 = piVar6[iVar3 * 8 + 0x1e];
  if ((piVar6[iVar3 * 8 + 0x1a] & 3U) != 0) {
    Sys_Error("Mod_LoadAliasModel: skinwidth not multiple of 4");
  }
  *piVar6 = iVar3 * 0x20 + 0x34;
  iVar10 = piVar6[iVar3 * 8 + 0x1b];
  iVar1 = piVar6[iVar3 * 8 + 0x1a];
  if (iVar4 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of skins: %d\n",iVar4);
  }
  local_3c = (undefined4 *)(param_2 + 0x54);
  iVar8 = Hunk_AllocName(iVar4 * 0xc,loadname);
  piVar6[2] = iVar8 - (int)piVar6;
  for (local_8 = 0; local_8 < iVar4; local_8 = local_8 + 1) {
    iVar9 = (*LittleLong)(*local_3c);
    *(int *)(iVar8 + local_8 * 0xc) = iVar9;
    if (iVar9 == 0) {
      local_3c = (undefined4 *)
                 Mod_LoadAliasSkin(local_3c + 1,local_8 * 0xc + iVar8 + 8,iVar10 * iVar1,piVar6);
    }
    else {
      local_3c = (undefined4 *)
                 Mod_LoadAliasSkinGroup
                           (local_3c + 1,local_8 * 0xc + iVar8 + 8,iVar10 * iVar1,piVar6);
    }
  }
  iVar4 = iVar3 * 0x20 + 0x88;
  piVar6[1] = iVar4;
  for (local_8 = 0; local_8 < piVar6[iVar3 * 8 + 0x1c]; local_8 = local_8 + 1) {
    iVar10 = (*LittleLong)(local_3c[local_8 * 3]);
    piVar6[iVar3 * 8 + local_8 * 3 + 0x22] = iVar10;
    iVar10 = (*LittleLong)(local_3c[local_8 * 3 + 1]);
    piVar6[iVar3 * 8 + local_8 * 3 + 0x23] = iVar10 << 0x10;
    iVar10 = (*LittleLong)(local_3c[local_8 * 3 + 2]);
    piVar6[iVar3 * 8 + local_8 * 3 + 0x24] = iVar10 << 0x10;
  }
  iVar10 = piVar6[iVar3 * 8 + 0x1c];
  iVar1 = piVar6[iVar3 * 8 + 0x1c];
  piVar6[3] = iVar10 * 0xc + iVar4;
  for (local_8 = 0; local_8 < piVar6[iVar3 * 8 + 0x1d]; local_8 = local_8 + 1) {
    iVar4 = (*LittleLong)(local_3c[iVar1 * 3 + local_8 * 4]);
    piVar6[iVar3 * 8 + iVar10 * 3 + local_8 * 4 + 0x22] = iVar4;
    for (local_60 = 0; local_60 < 3; local_60 = local_60 + 1) {
      iVar4 = (*LittleLong)(local_3c[iVar1 * 3 + local_8 * 4 + local_60 + 1]);
      piVar6[iVar3 * 8 + iVar10 * 3 + local_8 * 4 + local_60 + 0x23] = iVar4;
    }
  }
  if (iVar5 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of frames: %d\n",iVar5);
  }
  local_38 = local_3c + iVar1 * 3 + piVar6[iVar3 * 8 + 0x1d] * 4;
  for (local_8 = 0; local_8 < iVar5; local_8 = local_8 + 1) {
    iVar4 = (*LittleLong)(*local_38);
    piVar6[local_8 * 8 + 5] = iVar4;
    if (iVar4 == 0) {
      local_38 = (undefined4 *)
                 Mod_LoadAliasFrame(local_38 + 1,piVar6 + local_8 * 8 + 8,piVar6[iVar3 * 8 + 0x1c],
                                    piVar6 + local_8 * 8 + 6,piVar6 + local_8 * 8 + 7,piVar6,
                                    piVar6 + local_8 * 8 + 9);
    }
    else {
      local_38 = (undefined4 *)
                 Mod_LoadAliasGroup(local_38 + 1,piVar6 + local_8 * 8 + 8,piVar6[iVar3 * 8 + 0x1c],
                                    piVar6 + local_8 * 8 + 6,piVar6 + local_8 * 8 + 7,piVar6,
                                    piVar6 + local_8 * 8 + 9);
    }
  }
  *(undefined4 *)(param_1 + 0x44) = 2;
  *(undefined4 *)(param_1 + 0x5c) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x58) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x54) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x68) = 0x41800000;
  *(undefined4 *)(param_1 + 100) = 0x41800000;
  *(undefined4 *)(param_1 + 0x60) = 0x41800000;
  iVar3 = Hunk_AllocName(0x800,loadname);
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    *(ushort *)(iVar3 + local_8 * 8) = (ushort)*(byte *)((int)local_38 + local_8 * 3 + 2);
    *(ushort *)(local_8 * 8 + iVar3 + 2) = (ushort)*(byte *)((int)local_38 + local_8 * 3 + 1);
    *(ushort *)(local_8 * 8 + iVar3 + 4) = (ushort)*(byte *)((int)local_38 + local_8 * 3);
    *(undefined2 *)(local_8 * 8 + iVar3 + 6) = 0;
  }
  piVar6[4] = iVar3 - (int)piVar6;
  iVar3 = Hunk_LowMark();
  Cache_Alloc(param_1 + 0x184,iVar3 - iVar2,loadname);
  if (*(int *)(param_1 + 0x184) != 0) {
    Q_memcpy(*(undefined4 *)(param_1 + 0x184),piVar6,iVar3 - iVar2);
    Hunk_FreeToLowMark(iVar2);
  }
  return;
}


// Mod_LoadAliasSkin  @ 0007e608
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
  return param_1 + param_3;
}


// Mod_LoadAliasSkinGroup  @ 0007e6c8
undefined4 * Mod_LoadAliasSkinGroup(undefined4 *param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  longdouble lVar3;
  undefined4 *local_20;
  float *local_1c;
  undefined4 *local_18;
  int local_10;
  
  iVar1 = (*LittleLong)(*param_1);
  piVar2 = (int *)Hunk_AllocName((iVar1 + -1) * 0xc + 0x14,loadname);
  *piVar2 = iVar1;
  *param_2 = (int)piVar2 - param_4;
  local_1c = (float *)Hunk_AllocName(iVar1 * 4,loadname);
  piVar2[1] = (int)local_1c - param_4;
  for (local_10 = 0; local_18 = param_1 + 1, local_10 < iVar1; local_10 = local_10 + 1) {
    lVar3 = (longdouble)(*LittleFloat)(*local_18);
    *local_1c = (float)lVar3;
    if (*local_1c <= 0.0) {
      Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
    }
    local_1c = local_1c + 1;
    param_1 = local_18;
  }
  local_20 = local_18;
  for (local_10 = 0; local_10 < iVar1; local_10 = local_10 + 1) {
    local_20 = (undefined4 *)Mod_LoadAliasSkin(local_20,piVar2 + local_10 * 3 + 4,param_3,param_4);
  }
  return local_20;
}


// Mod_LoadBrushModel  @ 0007deb4
void Mod_LoadBrushModel(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  longdouble lVar4;
  char local_20 [12];
  undefined4 *local_14;
  undefined4 *local_10;
  int local_c;
  uint local_8;
  
  loadmodel[0x11] = 0;
  local_10 = param_2;
  local_8 = (*LittleLong)(*param_2);
  if ((local_8 != 0x1d) && (local_8 != 0x1e)) {
    Sys_Error("Mod_LoadBrushModel: %s has wrong version number (%i should be %i)",param_1,local_8,
              0x1e);
  }
  mod_base = local_10;
  for (local_8 = 0; local_8 < 0x1f; local_8 = local_8 + 1) {
    uVar1 = (*LittleLong)(local_10[local_8]);
    local_10[local_8] = uVar1;
  }
  Mod_LoadVertexes(local_10 + 7);
  Mod_LoadEdges(local_10 + 0x19);
  Mod_LoadSurfedges(local_10 + 0x1b);
  Mod_LoadEntities(local_10 + 1);
  Mod_LoadTextures(local_10 + 5);
  Mod_LoadLighting(local_10 + 0x11);
  Mod_LoadPlanes(local_10 + 3);
  Mod_LoadTexinfo(local_10 + 0xd);
  Mod_LoadFaces(local_10 + 0xf);
  Mod_LoadMarksurfaces(local_10 + 0x17);
  Mod_LoadVisibility(local_10 + 9);
  Mod_LoadLeafs(local_10 + 0x15);
  Mod_LoadNodes(local_10 + 0xb);
  Mod_LoadClipnodes(local_10 + 0x13);
  Mod_LoadSubmodels(local_10 + 0x1d);
  Mod_MakeHull0();
  param_1[0x12] = 2;
  param_1[0x14] = 0;
  for (local_8 = 0; (int)local_8 < (int)param_1[0x1e]; local_8 = local_8 + 1) {
    local_14 = (undefined4 *)(param_1[0x1f] + local_8 * 0x40);
    param_1[0x36] = local_14[9];
    for (local_c = 1; local_c < 4; local_c = local_c + 1) {
      param_1[local_c * 10 + 0x36] = local_14[local_c + 9];
      param_1[local_c * 10 + 0x37] = param_1[0x30] + -1;
    }
    param_1[0x1c] = local_14[0xe];
    param_1[0x1d] = local_14[0xf];
    param_1[0x18] = local_14[3];
    param_1[0x19] = local_14[4];
    param_1[0x1a] = local_14[5];
    param_1[0x15] = *local_14;
    param_1[0x16] = local_14[1];
    param_1[0x17] = local_14[2];
    lVar4 = (longdouble)RadiusFromBounds(param_1 + 0x15,param_1 + 0x18);
    param_1[0x1b] = (float)lVar4;
    param_1[0x22] = local_14[0xd];
    if ((int)local_8 < param_1[0x1e] + -1) {
      snprintf(local_20,10,"*%i",local_8 + 1);
      loadmodel = (undefined4 *)Mod_FindName(0,local_20);
      puVar3 = loadmodel;
      for (iVar2 = 0x62; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *param_1;
        param_1 = param_1 + 1;
        puVar3 = puVar3 + 1;
      }
      Q_strncpy(loadmodel,local_20,0x3f);
      *(undefined1 *)((int)loadmodel + 0x3f) = 0;
      param_1 = loadmodel;
    }
  }
  return;
}


// Mod_LoadClipnodes  @ 0007d540
void Mod_LoadClipnodes(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*param_1 + mod_base);
  if ((param_1[1] & 7U) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar3 = (uint)param_1[1] >> 3;
  local_c = (undefined4 *)Hunk_AllocName(uVar3 * 8,loadname);
  *(undefined4 **)(loadmodel + 0xc4) = local_c;
  *(uint *)(loadmodel + 0xc0) = uVar3;
  iVar1 = loadmodel;
  *(undefined4 **)(loadmodel + 0xf8) = local_c;
  *(undefined4 *)(iVar1 + 0x100) = 0;
  *(uint *)(iVar1 + 0x104) = uVar3 - 1;
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
  *(uint *)(iVar1 + 300) = uVar3 - 1;
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
  *(uint *)(iVar1 + 0x154) = uVar3 - 1;
  *(undefined4 *)(iVar1 + 0x14c) = *(undefined4 *)(loadmodel + 0x84);
  *(undefined4 *)(iVar1 + 0x158) = 0xc1800000;
  *(undefined4 *)(iVar1 + 0x15c) = 0xc1800000;
  *(undefined4 *)(iVar1 + 0x160) = 0xc1900000;
  *(undefined4 *)(iVar1 + 0x164) = 0x41800000;
  *(undefined4 *)(iVar1 + 0x168) = 0x41800000;
  *(undefined4 *)(iVar1 + 0x16c) = 0x41900000;
  for (local_10 = 0; local_10 < (int)uVar3; local_10 = local_10 + 1) {
    uVar4 = (*LittleLong)(*local_8);
    *local_c = uVar4;
    uVar2 = (*LittleShort)((int)*(short *)(local_8 + 1));
    *(undefined2 *)(local_c + 1) = uVar2;
    uVar2 = (*LittleShort)((int)*(short *)((int)local_8 + 6));
    *(undefined2 *)((int)local_c + 6) = uVar2;
    local_c = local_c + 2;
    local_8 = local_8 + 2;
  }
  return;
}


// Mod_LoadEdges  @ 0007c36c
void Mod_LoadEdges(int *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int local_10;
  undefined2 *local_c;
  short *local_8;
  
  local_8 = (short *)(*param_1 + mod_base);
  if ((param_1[1] & 3U) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar2 = (uint)param_1[1] >> 2;
  local_c = (undefined2 *)Hunk_AllocName((uVar2 + 1) * 8,loadname);
  *(undefined2 **)(loadmodel + 0x9c) = local_c;
  *(uint *)(loadmodel + 0x98) = uVar2;
  for (local_10 = 0; local_10 < (int)uVar2; local_10 = local_10 + 1) {
    uVar1 = (*LittleShort)((int)*local_8);
    *local_c = uVar1;
    uVar1 = (*LittleShort)((int)local_8[1]);
    local_c[1] = uVar1;
    local_8 = local_8 + 2;
    local_c = local_c + 4;
  }
  return;
}


// Mod_LoadEntities  @ 0007be18
void Mod_LoadEntities(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *local_8;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x180) = 0;
  }
  else {
    uVar1 = Hunk_AllocName(param_1[1],loadname);
    *(undefined4 *)(loadmodel + 0x180) = uVar1;
    Q_memcpy(*(undefined4 *)(loadmodel + 0x180),mod_base + *param_1,param_1[1]);
    if (*(int *)(loadmodel + 0x180) != 0) {
      local_8 = (char *)COM_Parse(*(undefined4 *)(loadmodel + 0x180));
      while( true ) {
        if (*local_8 == '\0') {
          return;
        }
        if (com_token == '}') {
          return;
        }
        iVar2 = Q_strcmp(&com_token,&DAT_000e4c40);
        if (iVar2 == 0) break;
        local_8 = (char *)COM_Parse(local_8);
      }
      COM_Parse(local_8);
      if (wadpath != 0) {
        Mem_Free(wadpath);
      }
      wadpath = Mem_Strdup(&com_token);
    }
  }
  return;
}


// Mod_LoadFaces  @ 0007caec
void Mod_LoadFaces(int *param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_18;
  int local_10;
  int local_c;
  short *local_8;
  
  local_8 = (short *)(*param_1 + mod_base);
  if ((uint)param_1[1] % 0x14 != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar3 = (uint)param_1[1] / 0x14;
  local_c = Hunk_AllocName(uVar3 * 0x44,loadname);
  *(int *)(loadmodel + 0xb4) = local_c;
  *(uint *)(loadmodel + 0xb0) = uVar3;
  for (local_18 = 0; local_18 < (int)uVar3; local_18 = local_18 + 1) {
    uVar4 = (*LittleLong)(*(undefined4 *)(local_8 + 2));
    *(undefined4 *)(local_c + 0x14) = uVar4;
    sVar1 = (*LittleShort)((int)local_8[4]);
    *(int *)(local_c + 0x18) = (int)sVar1;
    *(undefined4 *)(local_c + 0x10) = 0;
    *(undefined4 *)(local_c + 0x40) = 0;
    sVar1 = (*LittleShort)((int)*local_8);
    sVar2 = (*LittleShort)((int)local_8[1]);
    if (sVar2 != 0) {
      *(uint *)(local_c + 0x10) = *(uint *)(local_c + 0x10) | 2;
    }
    *(int *)(local_c + 0xc) = *(int *)(loadmodel + 0x84) + sVar1 * 0x14;
    sVar1 = (*LittleShort)((int)local_8[5]);
    *(int *)(local_c + 0x34) = *(int *)(loadmodel + 0xac) + sVar1 * 0x2c;
    CalcSurfaceExtents(local_c);
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      *(undefined1 *)(local_10 + local_c + 0x38) = *(undefined1 *)((int)local_8 + local_10 + 0xc);
    }
    iVar5 = (*LittleLong)(*(undefined4 *)(local_8 + 8));
    if (iVar5 == -1) {
      *(undefined4 *)(local_c + 0x3c) = 0;
    }
    else {
      *(int *)(local_c + 0x3c) = iVar5 + *(int *)(loadmodel + 0x17c);
    }
    iVar5 = Q_strncmp(*(undefined4 *)(*(int *)(local_c + 0x34) + 0x24),&DAT_000e4be2,3);
    if (iVar5 == 0) {
      *(uint *)(local_c + 0x10) = *(uint *)(local_c + 0x10) | 0x24;
    }
    else {
      iVar5 = Q_strncmp(*(undefined4 *)(*(int *)(local_c + 0x34) + 0x24),"scroll",6);
      if (iVar5 == 0) {
        *(uint *)(local_c + 0x10) = *(uint *)(local_c + 0x10) | 0x20;
        *(undefined2 *)(local_c + 0x30) =
             *(undefined2 *)(*(int *)(*(int *)(local_c + 0x34) + 0x24) + 0x10);
        *(undefined2 *)(local_c + 0x32) =
             *(undefined2 *)(*(int *)(*(int *)(local_c + 0x34) + 0x24) + 0x14);
      }
      else if (((**(char **)(*(int *)(local_c + 0x34) + 0x24) == '!') ||
               (iVar5 = Q_strnicmp(*(undefined4 *)(*(int *)(local_c + 0x34) + 0x24),"laser",5),
               iVar5 == 0)) ||
              (iVar5 = Q_strnicmp(*(undefined4 *)(*(int *)(local_c + 0x34) + 0x24),"water",5),
              iVar5 == 0)) {
        *(uint *)(local_c + 0x10) = *(uint *)(local_c + 0x10) | 0x30;
        for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
          *(undefined2 *)(local_10 * 2 + local_c + 0x30) = 0x4000;
          *(undefined2 *)(local_10 * 2 + local_c + 0x2c) = 0xe000;
          *(uint *)(*(int *)(local_c + 0x34) + 0x28) =
               *(uint *)(*(int *)(local_c + 0x34) + 0x28) | 1;
        }
      }
      else if ((*(uint *)(*(int *)(local_c + 0x34) + 0x28) & 1) != 0) {
        *(uint *)(local_c + 0x10) = *(uint *)(local_c + 0x10) | 0x20;
        *(undefined2 *)(local_c + 0x30) =
             *(undefined2 *)(*(int *)(*(int *)(local_c + 0x34) + 0x24) + 0x10);
        *(undefined2 *)(local_c + 0x32) =
             *(undefined2 *)(*(int *)(*(int *)(local_c + 0x34) + 0x24) + 0x14);
      }
    }
    local_8 = local_8 + 10;
    local_c = local_c + 0x44;
  }
  return;
}


// Mod_LoadLeafs  @ 0007d2b0
void Mod_LoadLeafs(int *param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int local_14;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*param_1 + mod_base);
  if ((uint)param_1[1] % 0x1c != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar5 = (uint)param_1[1] / 0x1c;
  local_c = (undefined4 *)Hunk_AllocName(uVar5 * 0x30,loadname);
  *(undefined4 **)(loadmodel + 0x8c) = local_c;
  *(uint *)(loadmodel + 0x88) = uVar5;
  for (local_10 = 0; local_10 < (int)uVar5; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
      uVar1 = (*LittleShort)((int)*(short *)((int)local_8 + local_14 * 2 + 8));
      *(undefined2 *)((int)local_c + local_14 * 2 + 8) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)local_8 + local_14 * 2 + 0xe));
      *(undefined2 *)((int)local_c + (local_14 + 3) * 2 + 8) = uVar1;
    }
    uVar3 = (*LittleLong)(*local_8);
    *local_c = uVar3;
    local_c[8] = *(int *)(loadmodel + 0xcc) + (uint)*(ushort *)(local_8 + 5) * 4;
    sVar2 = (*LittleShort)((int)*(short *)((int)local_8 + 0x16));
    local_c[9] = (int)sVar2;
    iVar4 = (*LittleLong)(local_8[1]);
    if (iVar4 == -1) {
      local_c[6] = 0;
    }
    else {
      local_c[6] = iVar4 + *(int *)(loadmodel + 0x178);
    }
    local_c[7] = 0;
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      *(undefined1 *)((int)local_c + local_14 + 0x2c) =
           *(undefined1 *)((int)local_8 + local_14 + 0x18);
    }
    local_8 = local_8 + 7;
    local_c = local_c + 0xc;
  }
  return;
}


// Mod_LoadLighting  @ 0007bcf0
void Mod_LoadLighting(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x17c) = 0;
  }
  else {
    uVar1 = Hunk_AllocName(param_1[1],loadname);
    *(undefined4 *)(loadmodel + 0x17c) = uVar1;
    Q_memcpy(*(undefined4 *)(loadmodel + 0x17c),mod_base + *param_1,param_1[1]);
  }
  return;
}


// Mod_LoadMarksurfaces  @ 0007d9c0
void Mod_LoadMarksurfaces(int *param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int local_8;
  
  iVar1 = *param_1 + mod_base;
  if ((param_1[1] & 1U) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar3 = (uint)param_1[1] >> 1;
  iVar4 = Hunk_AllocName(uVar3 * 4,loadname);
  *(int *)(loadmodel + 0xcc) = iVar4;
  *(uint *)(loadmodel + 200) = uVar3;
  for (local_8 = 0; local_8 < (int)uVar3; local_8 = local_8 + 1) {
    sVar2 = (*LittleShort)((int)*(short *)(iVar1 + local_8 * 2));
    if (*(int *)(loadmodel + 0xb0) <= (int)sVar2) {
      Sys_Error("Mod_ParseMarksurfaces: bad surface number");
    }
    *(int *)(iVar4 + local_8 * 4) = *(int *)(loadmodel + 0xb4) + sVar2 * 0x44;
  }
  return;
}


// Mod_LoadModel  @ 0007ace8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * Mod_LoadModel(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int local_11c;
  int *local_118;
  char *local_114;
  char local_110 [259];
  undefined1 local_d;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_c = (undefined4 *)0x0;
  if ((*(int *)(param_1 + 0x44) == 2) || (*(int *)(param_1 + 0x44) == 3)) {
    iVar1 = Cache_Check(param_1 + 0x184);
    if (iVar1 != 0) {
      param_1[0x40] = '\0';
      param_1[0x41] = '\0';
      param_1[0x42] = '\0';
      param_1[0x43] = '\0';
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
  iVar1 = COM_CheckParm("-steam");
  if ((iVar1 != 0) && (*param_1 == '/')) {
    for (local_114 = param_1; *local_114 == '/'; local_114 = local_114 + 1) {
    }
    strncpy(local_110,local_114,0x103);
    local_d = 0;
    strncpy(param_1,local_110,0x3f);
    param_1[0x3f] = '\0';
  }
  local_c = (undefined4 *)COM_LoadFileForMe(param_1,&local_8);
  if (local_c == (undefined4 *)0x0) {
    if (param_2 != 0) {
      Sys_Error("Mod_NumForName: %s not found",param_1);
    }
    return (char *)0x0;
  }
  if ((param_3 != 0) &&
     (local_118 = (int *)(mod_known_info + ((int)(param_1 + -0x300980) * 0x1a1f58d1 >> 3) * 0xc),
     *local_118 != 0)) {
    CRC32_Init(&local_11c);
    CRC32_ProcessBuffer(&local_11c,local_c,local_8);
    local_11c = CRC32_Final(local_11c);
    if (local_118[1] == 0) {
      local_118[1] = 1;
      local_118[2] = local_11c;
    }
    else if (local_11c != local_118[2]) {
      Sys_Error("%s has been modified since starting the engine.  Consider running system diagnostics to check for faulty hardware.\n"
                ,param_1);
      return (char *)0x0;
    }
  }
  if ((byte)(1.0 < (float)developer._12_4_ |
             (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)developer._12_4_ == 1.0) << 0xe) >> 8)) == 1) {
    Con_DPrintf("loading %s\n",param_1);
  }
  COM_FileBase(param_1,loadname);
  loadmodel = param_1;
  param_1[0x40] = '\0';
  param_1[0x41] = '\0';
  param_1[0x42] = '\0';
  param_1[0x43] = '\0';
  iVar1 = (*LittleLong)(*local_c);
  if (iVar1 == 0x50534449) {
    Mod_LoadSpriteModel(param_1,local_c);
  }
  else {
    if (iVar1 < 0x5053444a) {
      if (iVar1 == 0x4f504449) {
        Mod_LoadAliasModel(param_1,local_c);
        goto LAB_0007b020;
      }
    }
    else if (iVar1 == 0x54534449) {
      Mod_LoadStudioModel(param_1,local_c);
      goto LAB_0007b020;
    }
    Mod_LoadBrushModel(param_1,local_c);
  }
LAB_0007b020:
  if (_DAT_001198a4 != (code *)0x0) {
    (*_DAT_001198a4)(param_1,local_c);
  }
  if (local_c != (undefined4 *)0x0) {
    Mem_Free(local_c);
  }
  return param_1;
}


// Mod_LoadNodes  @ 0007cfb0
void Mod_LoadNodes(int *param_1)

{
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int local_1c;
  undefined4 *local_18;
  int local_c;
  int local_8;
  
  local_18 = (undefined4 *)(*param_1 + mod_base);
  if ((uint)param_1[1] % 0x18 != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar3 = (uint)param_1[1] / 0x18;
  local_1c = Hunk_AllocName(uVar3 * 0x28,loadname);
  *(int *)(loadmodel + 0xa4) = local_1c;
  *(uint *)(loadmodel + 0xa0) = uVar3;
  for (local_8 = 0; local_8 < (int)uVar3; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      uVar1 = (*LittleShort)((int)*(short *)((int)local_18 + local_c * 2 + 8));
      *(undefined2 *)(local_c * 2 + local_1c + 8) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)local_18 + local_c * 2 + 0xe));
      *(undefined2 *)((local_c + 3) * 2 + local_1c + 8) = uVar1;
    }
    iVar4 = (*LittleLong)(*local_18);
    *(int *)(local_1c + 0x18) = *(int *)(loadmodel + 0x84) + iVar4 * 0x14;
    uVar1 = (*LittleShort)((int)*(short *)(local_18 + 5));
    *(undefined2 *)(local_1c + 0x24) = uVar1;
    uVar1 = (*LittleShort)((int)*(short *)((int)local_18 + 0x16));
    *(undefined2 *)(local_1c + 0x26) = uVar1;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      sVar2 = (*LittleShort)((int)*(short *)((int)local_18 + local_c * 2 + 4));
      iVar4 = (int)sVar2;
      if (iVar4 < 0) {
        *(int *)(local_c * 4 + local_1c + 0x1c) = *(int *)(loadmodel + 0x8c) + (-1 - iVar4) * 0x30;
      }
      else {
        *(int *)(local_c * 4 + local_1c + 0x1c) = *(int *)(loadmodel + 0xa4) + iVar4 * 0x28;
      }
    }
    local_18 = local_18 + 6;
    local_1c = local_1c + 0x28;
  }
  if (uVar3 != 0) {
    Mod_SetParent(*(undefined4 *)(loadmodel + 0xa4),0);
  }
  return;
}


// Mod_LoadPlanes  @ 0007dc18
void Mod_LoadPlanes(int *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  longdouble lVar3;
  uint local_1c;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = *param_1 + mod_base;
  if ((uint)param_1[1] % 0x14 != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar2 = (uint)param_1[1] / 0x14;
  local_10 = Hunk_AllocName(uVar2 * 0x28,loadname);
  *(int *)(loadmodel + 0x84) = local_10;
  *(uint *)(loadmodel + 0x80) = uVar2;
  for (local_8 = 0; local_8 < (int)uVar2; local_8 = local_8 + 1) {
    local_1c = 0;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      lVar3 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_c * 4 + local_14));
      *(float *)(local_c * 4 + local_10) = (float)lVar3;
      if (*(float *)(local_c * 4 + local_10) < 0.0) {
        local_1c = local_1c | 1 << ((byte)local_c & 0x1f);
      }
    }
    lVar3 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_14 + 0xc));
    *(float *)(local_10 + 0xc) = (float)lVar3;
    uVar1 = (*LittleLong)(*(undefined4 *)(local_14 + 0x10));
    *(undefined1 *)(local_10 + 0x10) = uVar1;
    *(undefined1 *)(local_10 + 0x11) = (undefined1)local_1c;
    local_14 = local_14 + 0x14;
    local_10 = local_10 + 0x14;
  }
  return;
}


// Mod_LoadSpriteFrame  @ 0007f2d8
int Mod_LoadSpriteFrame(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = (*LittleLong)(param_1[2]);
  iVar2 = (*LittleLong)(param_1[3]);
  iVar3 = iVar1 * iVar2;
  piVar4 = (int *)Hunk_AllocName(iVar3 * r_pixbytes + 0x20,loadname);
  Q_memset(piVar4,0,iVar3 * r_pixbytes + 0x20);
  *param_2 = piVar4;
  *piVar4 = iVar1;
  piVar4[1] = iVar2;
  iVar5 = (*LittleLong)(*param_1);
  iVar6 = (*LittleLong)(param_1[1]);
  piVar4[3] = (int)(float)iVar6;
  piVar4[4] = (int)(float)(iVar6 - iVar2);
  piVar4[5] = (int)(float)iVar5;
  piVar4[6] = (int)(float)(iVar1 + iVar5);
  if (r_pixbytes == 1) {
    Q_memcpy(piVar4 + 7,param_1 + 4,iVar3);
  }
  else if (r_pixbytes != 2) {
    Sys_Error("Mod_LoadSpriteFrame: driver set invalid r_pixbytes: %d\n",r_pixbytes);
  }
  return iVar3 + 0x10 + (int)param_1;
}


// Mod_LoadSpriteGroup  @ 0007f488
undefined4 * Mod_LoadSpriteGroup(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  longdouble lVar3;
  undefined4 *local_20;
  float *local_1c;
  undefined4 *local_18;
  int local_10;
  
  iVar1 = (*LittleLong)(*param_1);
  piVar2 = (int *)Hunk_AllocName((iVar1 + -1) * 4 + 0xc,loadname);
  *piVar2 = iVar1;
  *param_2 = piVar2;
  local_1c = (float *)Hunk_AllocName(iVar1 * 4,loadname);
  piVar2[1] = (int)local_1c;
  for (local_10 = 0; local_18 = param_1 + 1, local_10 < iVar1; local_10 = local_10 + 1) {
    lVar3 = (longdouble)(*LittleFloat)(*local_18);
    *local_1c = (float)lVar3;
    if (*local_1c <= 0.0) {
      Sys_Error("Mod_LoadSpriteGroup: interval<=0");
    }
    local_1c = local_1c + 1;
    param_1 = local_18;
  }
  local_20 = local_18;
  for (local_10 = 0; local_10 < iVar1; local_10 = local_10 + 1) {
    local_20 = (undefined4 *)Mod_LoadSpriteFrame(local_20,piVar2 + local_10 + 2);
  }
  return local_20;
}


// Mod_LoadSpriteModel  @ 0007f5f0
void Mod_LoadSpriteModel(int param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined4 uVar8;
  longdouble lVar9;
  undefined4 *local_24;
  int local_8;
  
  iVar5 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar5 != 2) {
    Sys_Error("%s has wrong version number (%i should be %i)",param_1,iVar5,2);
  }
  iVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x1c));
  iVar5 = (iVar6 + -1) * 8;
  puVar7 = (undefined2 *)Hunk_AllocName(iVar5 + *(short *)(param_2 + 0x28) * 8 + 0x26,loadname);
  *(undefined2 **)(param_1 + 0x184) = puVar7;
  uVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 8));
  *puVar7 = uVar4;
  uVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0xc));
  puVar7[1] = uVar4;
  uVar8 = (*LittleLong)(*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(puVar7 + 2) = uVar8;
  uVar8 = (*LittleLong)(*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(puVar7 + 4) = uVar8;
  lVar9 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x20));
  *(float *)(puVar7 + 10) = (float)lVar9;
  uVar8 = (*LittleLong)(*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x4c) = uVar8;
  *(int *)(puVar7 + 6) = iVar6;
  iVar3 = *(int *)(puVar7 + 2);
  *(float *)(param_1 + 0x58) = (float)(-iVar3 / 2);
  *(float *)(param_1 + 0x54) = (float)(-iVar3 / 2);
  iVar3 = *(int *)(puVar7 + 2);
  *(float *)(param_1 + 100) = (float)(iVar3 / 2);
  *(float *)(param_1 + 0x60) = (float)(iVar3 / 2);
  *(float *)(param_1 + 0x5c) = (float)(-*(int *)(puVar7 + 4) / 2);
  *(float *)(param_1 + 0x68) = (float)(*(int *)(puVar7 + 4) / 2);
  *(int *)(puVar7 + 8) = iVar5 + 0x26;
  puVar1 = puVar7 + (iVar6 + -1) * 4 + 0x12;
  uVar2 = *(ushort *)(param_2 + 0x28);
  *puVar1 = uVar2;
  iVar5 = param_2 + 0x2a;
  for (local_8 = 0; local_8 < (int)(uint)uVar2; local_8 = local_8 + 1) {
    puVar1[local_8 * 4 + 1] = (ushort)*(byte *)(iVar5 + local_8 * 3);
    puVar1[local_8 * 4 + 2] = (ushort)*(byte *)(local_8 * 3 + iVar5 + 1);
    puVar1[local_8 * 4 + 3] = (ushort)*(byte *)(local_8 * 3 + iVar5 + 2);
    puVar1[local_8 * 4 + 4] = 0;
  }
  if (iVar6 < 1) {
    Sys_Error("Mod_LoadSpriteModel: Invalid # of frames: %d\n",iVar6);
  }
  *(int *)(param_1 + 0x48) = iVar6;
  *(undefined4 *)(param_1 + 0x50) = 0;
  local_24 = (undefined4 *)((uint)uVar2 * 3 + param_2 + 0x2a);
  for (local_8 = 0; local_8 < iVar6; local_8 = local_8 + 1) {
    iVar5 = (*LittleLong)(*local_24);
    *(int *)(puVar7 + local_8 * 4 + 0xe) = iVar5;
    if (iVar5 == 0) {
      local_24 = (undefined4 *)Mod_LoadSpriteFrame(local_24 + 1,puVar7 + local_8 * 4 + 0x10);
    }
    else {
      local_24 = (undefined4 *)Mod_LoadSpriteGroup(local_24 + 1,puVar7 + local_8 * 4 + 0x10);
    }
  }
  *(undefined4 *)(param_1 + 0x44) = 1;
  return;
}


// Mod_LoadStudioModel  @ 000770c0
void Mod_LoadStudioModel(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  ushort *local_18;
  byte *local_14;
  int local_8;
  
  iVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar2 != 10) {
    Q_memset(param_2,0,0xf4);
    Q_strcpy(param_2 + 8,"bogus");
    *(undefined4 *)(param_2 + 0x48) = 0xf4;
    *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(param_2 + 0x48);
  }
  *(undefined4 *)(param_1 + 0x44) = 3;
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 0x88);
  _LogFunctionTrace("Mod_LoadStudioModel  ",param_1);
  Cache_Alloc(param_1 + 0x184,*(int *)(param_2 + 0x48) + *(int *)(param_2 + 0xb4) * 0x500,param_1);
  if (*(int *)(param_1 + 0x184) != 0) {
    iVar1 = *(int *)(param_1 + 0x184);
    iVar2 = *(int *)(param_2 + 0xb8) + iVar1;
    if (*(int *)(param_2 + 0xb8) == 0) {
      Q_memcpy(iVar1,param_2,*(undefined4 *)(param_2 + 0x48));
    }
    else {
      Q_memcpy(iVar1,param_2,*(undefined4 *)(param_2 + 0xbc));
      local_14 = (byte *)(*(int *)(param_2 + 0xbc) + param_2);
      local_18 = (ushort *)(*(int *)(param_2 + 0xbc) + iVar1);
      for (local_8 = 0; local_8 < *(int *)(param_2 + 0xb4); local_8 = local_8 + 1) {
        *(int *)(iVar2 + 0x4c + local_8 * 0x50) = (int)local_18 - iVar1;
        iVar3 = *(int *)(iVar2 + 0x44 + local_8 * 0x50) * *(int *)(iVar2 + 0x48 + local_8 * 0x50);
        Q_memcpy(local_18,local_14,iVar3);
        local_18 = (ushort *)((int)local_18 + iVar3);
        local_14 = local_14 + iVar3;
        for (local_2c = 0; local_2c < 0x100; local_2c = local_2c + 1) {
          *local_18 = (ushort)(byte)texgammatable[*local_14];
          local_18[1] = (ushort)(byte)texgammatable[local_14[1]];
          local_18[2] = (ushort)(byte)texgammatable[local_14[2]];
          local_18[3] = 0;
          local_18 = local_18 + 4;
          local_14 = local_14 + 3;
        }
      }
    }
  }
  return;
}


// Mod_LoadSubmodels  @ 0007c104
void Mod_LoadSubmodels(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  longdouble lVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = *param_1 + mod_base;
  if ((param_1[1] & 0x3fU) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar1 = (uint)param_1[1] >> 6;
  local_c = Hunk_AllocName(uVar1 << 6,loadname);
  *(int *)(loadmodel + 0x7c) = local_c;
  *(uint *)(loadmodel + 0x78) = uVar1;
  for (local_10 = 0; local_10 < (int)uVar1; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
      lVar3 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_14 * 4 + local_8));
      *(float *)(local_14 * 4 + local_c) = (float)(lVar3 - (longdouble)1);
      lVar3 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_14 * 4 + local_8 + 0xc));
      *(float *)(local_14 * 4 + local_c + 0xc) = (float)((longdouble)1 + lVar3);
      lVar3 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_14 * 4 + local_8 + 0x18));
      *(float *)(local_14 * 4 + local_c + 0x18) = (float)lVar3;
    }
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      uVar2 = (*LittleLong)(*(undefined4 *)(local_14 * 4 + local_8 + 0x24));
      *(undefined4 *)(local_14 * 4 + local_c + 0x24) = uVar2;
    }
    uVar2 = (*LittleLong)(*(undefined4 *)(local_8 + 0x34));
    *(undefined4 *)(local_c + 0x34) = uVar2;
    uVar2 = (*LittleLong)(*(undefined4 *)(local_8 + 0x38));
    *(undefined4 *)(local_c + 0x38) = uVar2;
    uVar2 = (*LittleLong)(*(undefined4 *)(local_8 + 0x3c));
    *(undefined4 *)(local_c + 0x3c) = uVar2;
    local_8 = local_8 + 0x40;
    local_c = local_c + 0x40;
  }
  return;
}


// Mod_LoadSurfedges  @ 0007db18
void Mod_LoadSurfedges(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_8;
  
  iVar1 = *param_1 + mod_base;
  if ((param_1[1] & 3U) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar2 = (uint)param_1[1] >> 2;
  iVar3 = Hunk_AllocName(uVar2 * 4,loadname);
  *(int *)(loadmodel + 0xbc) = iVar3;
  *(uint *)(loadmodel + 0xb8) = uVar2;
  for (local_8 = 0; local_8 < (int)uVar2; local_8 = local_8 + 1) {
    uVar4 = (*LittleLong)(*(undefined4 *)(iVar1 + local_8 * 4));
    *(undefined4 *)(iVar3 + local_8 * 4) = uVar4;
  }
  return;
}


// Mod_LoadTexinfo  @ 0007c484
void Mod_LoadTexinfo(int *param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  longdouble lVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = *param_1 + mod_base;
  if ((uint)param_1[1] % 0x28 != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar2 = (uint)param_1[1] / 0x28;
  local_c = Hunk_AllocName(uVar2 * 0x2c,loadname);
  *(int *)(loadmodel + 0xac) = local_c;
  *(uint *)(loadmodel + 0xa8) = uVar2;
  for (local_10 = 0; local_10 < (int)uVar2; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
      lVar5 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_14 * 4 + local_8));
      *(float *)(local_14 * 4 + local_c) = (float)lVar5;
    }
    lVar5 = (longdouble)Length(local_c);
    lVar6 = (longdouble)Length(local_c + 0x10);
    fVar1 = ((float)lVar5 + (float)lVar6) / 2.0;
    if (0.32 <= fVar1) {
      if (0.49 <= fVar1) {
        if (0.99 <= fVar1) {
          *(undefined4 *)(local_c + 0x20) = 0x3f800000;
        }
        else {
          *(undefined4 *)(local_c + 0x20) = 0x40000000;
        }
      }
      else {
        *(undefined4 *)(local_c + 0x20) = 0x40400000;
      }
    }
    else {
      *(undefined4 *)(local_c + 0x20) = 0x40800000;
    }
    iVar3 = (*LittleLong)(*(undefined4 *)(local_8 + 0x20));
    uVar4 = (*LittleLong)(*(undefined4 *)(local_8 + 0x24));
    *(undefined4 *)(local_c + 0x28) = uVar4;
    if (*(int *)(loadmodel + 0x174) == 0) {
      *(undefined4 *)(local_c + 0x24) = r_notexture_mip;
      *(undefined4 *)(local_c + 0x28) = 0;
    }
    else {
      if (*(int *)(loadmodel + 0x170) <= iVar3) {
        Sys_Error("miptex >= loadmodel->numtextures");
      }
      *(undefined4 *)(local_c + 0x24) = *(undefined4 *)(*(int *)(loadmodel + 0x174) + iVar3 * 4);
      if (*(int *)(local_c + 0x24) == 0) {
        *(undefined4 *)(local_c + 0x24) = r_notexture_mip;
        *(undefined4 *)(local_c + 0x28) = 0;
      }
    }
    local_8 = local_8 + 0x28;
    local_c = local_c + 0x2c;
  }
  return;
}


// Mod_LoadTextures  @ 0007b34c
void Mod_LoadTextures(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  longdouble lVar9;
  longdouble lVar10;
  undefined1 auStack_553cc [348236];
  undefined4 auStack_380 [203];
  undefined4 local_54 [10];
  char *local_2c;
  char *local_28;
  undefined1 *local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  bVar2 = false;
  lVar9 = (longdouble)Sys_FloatTime();
  if (tested == 0) {
    Mod_AdInit();
  }
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x174) = 0;
  }
  else {
    piVar1 = (int *)(*param_1 + mod_base);
    iVar5 = (*LittleLong)(*piVar1);
    *piVar1 = iVar5;
    *(int *)(loadmodel + 0x170) = *piVar1;
    uVar6 = Hunk_AllocName(*piVar1 * 4,loadname);
    *(undefined4 *)(loadmodel + 0x174) = uVar6;
    for (local_8 = 0; local_8 < *piVar1; local_8 = local_8 + 1) {
      iVar5 = (*LittleLong)(piVar1[local_8 + 1]);
      piVar1[local_8 + 1] = iVar5;
      if (piVar1[local_8 + 1] != -1) {
        local_24 = (undefined1 *)(piVar1[local_8 + 1] + (int)piVar1);
        if (((byte)((byte)((ushort)((ushort)NAN((float)r_wadtextures._12_4_) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)r_wadtextures._12_4_ == 0.0) << 0xe) >> 8)) !=
             0x40) || (iVar5 = (*LittleLong)(*(undefined4 *)(local_24 + 0x18)), iVar5 == 0)) {
          if (!bVar2) {
            TEX_InitFromWad(wadpath);
            TEX_AddAnimatingTextures();
            bVar2 = true;
          }
          iVar5 = TEX_LoadLump(local_24,auStack_553cc);
          if (iVar5 == 0) {
            piVar1[local_8 + 1] = -1;
            goto LAB_0007b8db;
          }
          local_24 = auStack_553cc;
        }
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          uVar6 = (*LittleLong)(*(undefined4 *)(local_24 + local_c * 4 + 0x18));
          *(undefined4 *)(local_24 + local_c * 4 + 0x18) = uVar6;
        }
        uVar6 = (*LittleLong)(*(undefined4 *)(local_24 + 0x10));
        *(undefined4 *)(local_24 + 0x10) = uVar6;
        uVar6 = (*LittleLong)(*(undefined4 *)(local_24 + 0x14));
        *(undefined4 *)(local_24 + 0x14) = uVar6;
        if (((*(uint *)(local_24 + 0x10) & 0xf) != 0) || ((*(uint *)(local_24 + 0x14) & 0xf) != 0))
        {
          Sys_Error("Texture %s is not 16 aligned",local_24);
        }
        local_10 = ((uint)(*(int *)(local_24 + 0x10) * *(int *)(local_24 + 0x14)) >> 6) * 0x55;
        local_14 = (uint)*(ushort *)(local_24 + local_10 + 0x28) * 8;
        local_28 = (char *)Hunk_AllocName(local_14 + local_10 + 0x42,loadname);
        *(char **)(*(int *)(loadmodel + 0x174) + local_8 * 4) = local_28;
        Q_memcpy(local_28,local_24);
        pcVar7 = strchr(local_28,0x7e);
        if (pcVar7 != (char *)0x0) {
          local_28[2] = ' ';
        }
        *(undefined4 *)(local_28 + 0x10) = *(undefined4 *)(local_24 + 0x10);
        *(undefined4 *)(local_28 + 0x14) = *(undefined4 *)(local_24 + 0x14);
        for (local_c = 0; local_c < 4; local_c = local_c + 1) {
          *(int *)(local_28 + local_c * 4 + 0x2c) = *(int *)(local_24 + local_c * 4 + 0x18) + 0x18;
        }
        *(int *)(local_28 + 0x3c) = local_10 + 0x42;
        Q_memcpy(local_28 + 0x40,local_24 + 0x28);
        puVar4 = local_24;
        pcVar7 = local_28;
        iVar5 = local_10 + 0x2a;
        iVar3 = local_10 + 0x42;
        iVar8 = Q_strncmp(local_24,&DAT_000e4be2);
        if (iVar8 == 0) {
          R_InitSky();
        }
        for (local_c = 0; local_c < (int)(local_14 >> 3); local_c = local_c + 1) {
          (pcVar7 + local_c * 8 + iVar3 + 6)[0] = '\0';
          (pcVar7 + local_c * 8 + iVar3 + 6)[1] = '\0';
          *(ushort *)(pcVar7 + local_c * 8 + iVar3 + 4) =
               (ushort)(byte)texgammatable[(byte)puVar4[local_c * 3 + iVar5]];
          *(ushort *)(pcVar7 + local_c * 8 + iVar3 + 2) =
               (ushort)(byte)texgammatable[(byte)puVar4[local_c * 3 + iVar5 + 1]];
          *(ushort *)(pcVar7 + local_c * 8 + iVar3) =
               (ushort)(byte)texgammatable[(byte)puVar4[local_c * 3 + iVar5 + 2]];
        }
        if ((ad_enabled != 0) && (iVar5 = Q_stricmp(local_28,"DEFAULT"), iVar5 == 0)) {
          Mod_AdSwap(local_28,local_10);
        }
      }
LAB_0007b8db:
    }
    if (bVar2) {
      TEX_CleanupWadInfo();
    }
    for (local_8 = 0; local_8 < *piVar1; local_8 = local_8 + 1) {
      local_28 = *(char **)(*(int *)(loadmodel + 0x174) + local_8 * 4);
      if ((local_28 != (char *)0x0) &&
         (((*local_28 == '+' || (*local_28 == '-')) && (*(int *)(local_28 + 0x24) == 0)))) {
        Q_memset(local_54,0,0x28);
        Q_memset(auStack_380 + 0xc1);
        local_1c = (int)local_28[1];
        local_20 = 0;
        if ((0x60 < local_1c) && (local_1c < 0x7b)) {
          local_1c = local_1c + -0x20;
        }
        iVar5 = local_1c;
        if ((local_1c < 0x30) || (0x39 < local_1c)) {
          if ((local_1c < 0x41) || (0x4a < local_1c)) {
            Sys_Error("Bad animating texture %s");
            local_c = local_8;
          }
          else {
            local_1c = 0;
            auStack_380[iVar5 + 0x80] = local_28;
            local_20 = iVar5 + -0x40;
            local_c = local_8;
          }
        }
        else {
          local_1c = local_1c + -0x30;
          local_20 = 0;
          local_54[local_1c] = local_28;
          local_1c = local_1c + 1;
          local_c = local_8;
        }
        while (local_c = local_c + 1, local_c < *piVar1) {
          local_2c = *(char **)(*(int *)(loadmodel + 0x174) + local_c * 4);
          if ((local_2c != (char *)0x0) &&
             (((*local_2c == '+' || (*local_2c == '-')) &&
              (iVar5 = Q_strcmp(local_2c + 2), iVar5 == 0)))) {
            local_18 = (int)local_2c[1];
            if ((0x60 < local_18) && (local_18 < 0x7b)) {
              local_18 = local_18 + -0x20;
            }
            iVar5 = local_18;
            if ((local_18 < 0x30) || (0x39 < local_18)) {
              if ((local_18 < 0x41) || (0x4a < local_18)) {
                Sys_Error("Bad animating texture %s");
              }
              else {
                local_18 = local_18 + -0x41;
                auStack_380[iVar5 + 0x80] = local_2c;
                if (local_20 < iVar5 + -0x40) {
                  local_20 = iVar5 + -0x40;
                }
              }
            }
            else {
              local_18 = local_18 + -0x30;
              local_54[local_18] = local_2c;
              if (local_1c < local_18 + 1) {
                local_1c = local_18 + 1;
              }
            }
          }
        }
        for (local_c = 0; local_c < local_1c; local_c = local_c + 1) {
          local_2c = (char *)local_54[local_c];
          if ((char *)local_54[local_c] == (char *)0x0) {
            Sys_Error("Missing frame %i of %s");
          }
          *(int *)(local_2c + 0x18) = local_1c;
          *(int *)(local_2c + 0x1c) = local_c;
          *(int *)(local_2c + 0x20) = local_c + 1;
          *(undefined4 *)(local_2c + 0x24) = local_54[(local_c + 1) % local_1c];
          if (local_20 != 0) {
            *(undefined4 *)(local_2c + 0x28) = auStack_380[0xc1];
          }
        }
        for (local_c = 0; local_c < local_20; local_c = local_c + 1) {
          local_2c = (char *)auStack_380[local_c + 0xc1];
          if ((char *)auStack_380[local_c + 0xc1] == (char *)0x0) {
            Sys_Error("Missing frame %i of %s");
          }
          *(int *)(local_2c + 0x18) = local_20;
          *(int *)(local_2c + 0x1c) = local_c;
          *(int *)(local_2c + 0x20) = local_c + 1;
          *(undefined4 *)(local_2c + 0x24) = auStack_380[(local_c + 1) % local_20 + 0xc1];
          if (local_1c != 0) {
            *(undefined4 *)(local_2c + 0x28) = local_54[0];
          }
        }
      }
    }
    lVar10 = (longdouble)Sys_FloatTime();
    Con_DPrintf("Texture load: %6.1fms\n",
                (double)((longdouble)1000.0 * (lVar10 - (longdouble)(double)lVar9)));
  }
  return;
}


// Mod_LoadVertexes  @ 0007bf98
void Mod_LoadVertexes(int *param_1)

{
  uint uVar1;
  longdouble lVar2;
  int local_10;
  float *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*param_1 + mod_base);
  if ((uint)param_1[1] % 0xc != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar1 = (uint)param_1[1] / 0xc;
  local_c = (float *)Hunk_AllocName(uVar1 * 0xc,loadname);
  *(float **)(loadmodel + 0x94) = local_c;
  *(uint *)(loadmodel + 0x90) = uVar1;
  for (local_10 = 0; local_10 < (int)uVar1; local_10 = local_10 + 1) {
    lVar2 = (longdouble)(*LittleFloat)(*local_8);
    *local_c = (float)lVar2;
    lVar2 = (longdouble)(*LittleFloat)(local_8[1]);
    local_c[1] = (float)lVar2;
    lVar2 = (longdouble)(*LittleFloat)(local_8[2]);
    local_c[2] = (float)lVar2;
    local_8 = local_8 + 3;
    local_c = local_c + 3;
  }
  return;
}


// Mod_LoadVisibility  @ 0007bd84
void Mod_LoadVisibility(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x178) = 0;
  }
  else {
    uVar1 = Hunk_AllocName(param_1[1],loadname);
    *(undefined4 *)(loadmodel + 0x178) = uVar1;
    Q_memcpy(*(undefined4 *)(loadmodel + 0x178),mod_base + *param_1,param_1[1]);
  }
  return;
}


// Mod_MakeHull0  @ 0007d810
void Mod_MakeHull0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_18;
  int local_14;
  int *local_10;
  int local_8;
  
  iVar3 = loadmodel;
  puVar4 = (undefined4 *)(loadmodel + 0xd0);
  local_8 = *(int *)(loadmodel + 0xa4);
  iVar1 = *(int *)(loadmodel + 0xa0);
  local_10 = (int *)Hunk_AllocName(iVar1 * 8,loadname);
  *puVar4 = local_10;
  *(undefined4 *)(iVar3 + 0xd8) = 0;
  *(int *)(iVar3 + 0xdc) = iVar1 + -1;
  *(undefined4 *)(iVar3 + 0xd4) = *(undefined4 *)(loadmodel + 0x84);
  for (local_14 = 0; local_14 < iVar1; local_14 = local_14 + 1) {
    *local_10 = (*(int *)(local_8 + 0x18) - *(int *)(loadmodel + 0x84)) * -0x33333333 >> 2;
    for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
      piVar2 = *(int **)(local_18 * 4 + local_8 + 0x1c);
      if (*piVar2 < 0) {
        *(short *)(local_18 * 2 + 4 + (int)local_10) = (short)*piVar2;
      }
      else {
        *(short *)(local_18 * 2 + 4 + (int)local_10) =
             (short)(((int)piVar2 - *(int *)(loadmodel + 0xa4)) * -0x33333333 >> 3);
      }
    }
    local_10 = local_10 + 2;
    local_8 = local_8 + 0x28;
  }
  return;
}


// Mod_MarkClient  @ 0007b070
void Mod_MarkClient(int param_1)

{
  *(undefined4 *)(param_1 + 0x40) = 3;
  return;
}


// Mod_NeedCRC  @ 0007ac7c
void Mod_NeedCRC(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Mod_FindName(0,param_1);
  *(undefined4 *)(mod_known_info + ((iVar1 + -0x300980) * 0x1a1f58d1 >> 3) * 0xc) = param_2;
  return;
}


// Mod_PointInLeaf  @ 0007a8a8
int * Mod_PointInLeaf(float *param_1,int param_2)

{
  float *pfVar1;
  float local_c;
  int *local_8;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 0xa4) == 0)) {
    Sys_Error("Mod_PointInLeaf: bad model");
  }
  local_8 = *(int **)(param_2 + 0xa4);
  while (-1 < *local_8) {
    pfVar1 = (float *)local_8[6];
    if (*(byte *)(pfVar1 + 4) < 3) {
      local_c = param_1[*(byte *)(pfVar1 + 4)] - pfVar1[3];
    }
    else {
      local_c = (param_1[2] * pfVar1[2] + param_1[1] * pfVar1[1] + *param_1 * *pfVar1) - pfVar1[3];
    }
    if ((byte)(0.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_c == 0.0) << 0xe) >> 8)) == 1) {
      local_8 = (int *)local_8[7];
    }
    else {
      local_8 = (int *)local_8[8];
    }
  }
  return local_8;
}


// Mod_Print  @ 0007fa48
void Mod_Print(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 *local_c;
  int local_8;
  
  Con_Printf("Cached models:\n");
  local_c = mod_known;
  for (local_8 = 0; local_8 < mod_numknown; local_8 = local_8 + 1) {
    uVar1 = *(undefined4 *)(local_c + 0x184);
    puVar2 = local_c;
    Con_Printf("%8p : %s",uVar1,local_c);
    if ((*(uint *)(local_c + 0x40) & 2) != 0) {
      Con_Printf(" (!R)",uVar1,puVar2);
    }
    if ((*(uint *)(local_c + 0x40) & 1) != 0) {
      Con_Printf(" (!P)",uVar1,puVar2);
    }
    Con_Printf(&DAT_000e50f3,uVar1,puVar2);
    local_c = local_c + 0x188;
  }
  return;
}


// Mod_SetParent  @ 0007cf54
void Mod_SetParent(int *param_1,int param_2)

{
  param_1[5] = param_2;
  if (-1 < *param_1) {
    Mod_SetParent(param_1[7],param_1);
    Mod_SetParent(param_1[8],param_1);
  }
  return;
}


// Mod_UnloadSpriteTextures  @ 0007fa28
void Mod_UnloadSpriteTextures(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x44) == 1)) {
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  return;
}


// Mod_ValidateCRC  @ 0007abe0
undefined4 Mod_ValidateCRC(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mod_FindName(1,param_1);
  iVar1 = ((iVar1 + -0x300980) * 0x1a1f58d1 >> 3) * 0xc;
  if (*(int *)(mod_known_info + iVar1 + 4) == 0) {
    uVar2 = 1;
  }
  else if (param_2 == *(int *)(mod_known_info + iVar1 + 8)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


