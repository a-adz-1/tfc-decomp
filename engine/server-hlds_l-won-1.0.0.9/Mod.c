// Mod_ClearAll  @ 08062770
void Mod_ClearAll(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = mod_known;
  if (0 < mod_numknown) {
    do {
      if (*(int *)(puVar1 + 0x40) != 3) {
        *(undefined4 *)(puVar1 + 0x40) = 2;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x188;
    } while (iVar2 < mod_numknown);
  }
  return;
}


// Mod_DecompressVis  @ 0804d730
undefined1 * Mod_DecompressVis(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = mod_novis;
  }
  else {
    CM_DecompressPVS(param_1,decompressed_96,*(int *)(param_2 + 0x88) + 7 >> 3);
    puVar1 = decompressed_96;
  }
  return puVar1;
}


// Mod_Extradata  @ 08062660
int Mod_Extradata(int param_1)

{
  int iVar1;
  
  iVar1 = Cache_Check(param_1 + 0x184);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      Sys_Error("Mod_ExtraData called with mod_brush!\n");
    }
    Mod_LoadModel(param_1,1);
    if (*(int *)(param_1 + 0x184) == 0) {
      Sys_Error("Mod_Extradata: caching failed");
    }
    iVar1 = *(int *)(param_1 + 0x184);
  }
  return iVar1;
}


// Mod_FindName  @ 080627b0
undefined1 * Mod_FindName(char *param_1)

{
  int iVar1;
  undefined1 *__dest;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = (char *)0x0;
  if (*param_1 == '\0') {
    Sys_Error("Mod_ForName: NULL name");
  }
  iVar2 = 0;
  __dest = mod_known;
  if (0 < mod_numknown) {
    do {
      iVar1 = Q_strcasecmp(__dest,param_1);
      if (iVar1 == 0) break;
      if ((*(int *)(__dest + 0x40) == 2) &&
         ((pcVar3 == (char *)0x0 || (1 < *(int *)(__dest + 0x44) - 2U)))) {
        pcVar3 = __dest;
      }
      iVar2 = iVar2 + 1;
      __dest = __dest + 0x188;
    } while (iVar2 < mod_numknown);
  }
  if (iVar2 == mod_numknown) {
    if (mod_numknown == 0x200) {
      if (pcVar3 == (char *)0x0) {
        return (char *)0x0;
      }
      Sys_Error("mod_numknown == MAX_MODELS");
      __dest = pcVar3;
    }
    else {
      mod_numknown = mod_numknown + 1;
    }
    strcpy(__dest,param_1);
    if (*(int *)(__dest + 0x40) != 3) {
      __dest[0x40] = '\x01';
      __dest[0x41] = '\0';
      __dest[0x42] = '\0';
      __dest[0x43] = '\0';
    }
  }
  return __dest;
}


// Mod_ForName  @ 08062a20
undefined4 Mod_ForName(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mod_FindName(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Mod_LoadModel(iVar1,param_2);
  }
  return uVar2;
}


// Mod_Init  @ 0804d710
void Mod_Init(void)

{
  SW_Mod_Init();
  memset(mod_novis,0xff,0x400);
  return;
}


// Mod_LeafPVS  @ 0804d770
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


// Mod_LoadAliasFrame  @ 08064920
int Mod_LoadAliasFrame(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,
                      char *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  strcpy(param_7,(char *)(param_1 + 8));
  iVar2 = 0;
  do {
    *(undefined1 *)(iVar2 + param_4) = *(undefined1 *)(iVar2 + param_1);
    *(undefined1 *)(iVar2 + param_5) = *(undefined1 *)(iVar2 + param_1 + 4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  iVar2 = Hunk_AllocName(param_3 * 4,loadname);
  *param_2 = iVar2 - param_6;
  iVar1 = 0;
  if (0 < param_3) {
    do {
      *(undefined1 *)(iVar2 + 3 + iVar1 * 4) = *(undefined1 *)(param_1 + 0x1b + iVar1 * 4);
      iVar3 = 0;
      do {
        *(undefined1 *)(iVar3 + iVar2 + iVar1 * 4) =
             *(undefined1 *)(iVar3 + param_1 + 0x18 + iVar1 * 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_3);
  }
  return param_1 + 0x18 + param_3 * 4;
}


// Mod_LoadAliasGroup  @ 080649d0
undefined4 *
Mod_LoadAliasGroup(undefined4 *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,
                  int param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  longdouble lVar6;
  
  iVar2 = (*LittleLong)(*param_1);
  piVar3 = (int *)Hunk_AllocName((iVar2 * 3 + -3) * 4 + 0x14,loadname);
  *piVar3 = iVar2;
  iVar5 = 0;
  do {
    *(undefined1 *)(iVar5 + param_4) = *(undefined1 *)((int)param_1 + iVar5 + 4);
    *(undefined1 *)(iVar5 + param_5) = *(undefined1 *)((int)param_1 + iVar5 + 8);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  *param_2 = (int)piVar3 - param_6;
  param_1 = param_1 + 3;
  pfVar4 = (float *)Hunk_AllocName(iVar2 << 2,loadname);
  piVar3[1] = (int)pfVar4 - param_6;
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      lVar6 = (longdouble)(*LittleFloat)(*param_1);
      *pfVar4 = (float)lVar6;
      if (*pfVar4 <= 0.0) {
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
      }
      pfVar4 = pfVar4 + 1;
      param_1 = param_1 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2);
  }
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      piVar1 = piVar3 + iVar5 * 3 + 2;
      param_1 = (undefined4 *)
                Mod_LoadAliasFrame(param_1,piVar1 + 2,param_3,piVar1,piVar1 + 1,param_6,param_7);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2);
  }
  return param_1;
}


// Mod_LoadAliasModel  @ 08064c50
void Mod_LoadAliasModel(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *__src;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  int iVar12;
  longdouble lVar13;
  int local_3c;
  
  iVar1 = Hunk_LowMark();
  iVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar2 != 6) {
    Sys_Error("%s has wrong version number (%i should be %i)",param_1,iVar2,6);
  }
  iVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  iVar3 = (*LittleLong)(*(undefined4 *)(param_2 + 0x3c));
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x40));
  __src = (uint *)Hunk_AllocName(iVar2 * 0x20 + 0x68 + iVar3 * 0xc + iVar4 * 0x10,loadname);
  iVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  uVar5 = iVar2 << 5 | 0x14;
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x4c));
  *(undefined4 *)(param_1 + 0x50) = uVar6;
  lVar13 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x20));
  *(float *)((int)__src + uVar5 + 0x20) = (float)lVar13;
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x30));
  *(undefined4 *)((int)__src + uVar5 + 0x30) = uVar6;
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x34));
  *(undefined4 *)((int)__src + uVar5 + 0x34) = uVar6;
  iVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 0x38));
  *(int *)((int)__src + uVar5 + 0x38) = iVar2;
  if (0x1e0 < iVar2) {
    Sys_Error("model %s has a skin taller than %d",param_1,0x1e0);
  }
  iVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 0x3c));
  *(int *)((int)__src + uVar5 + 0x3c) = iVar2;
  if (iVar2 < 1) {
    Sys_Error("model %s has no vertices",param_1);
  }
  if (2000 < *(int *)((int)__src + uVar5 + 0x3c)) {
    Sys_Error("model %s has too many vertices",param_1);
  }
  iVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 0x40));
  *(int *)((int)__src + uVar5 + 0x40) = iVar2;
  if (iVar2 < 1) {
    Sys_Error("model %s has no triangles",param_1);
  }
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x44));
  *(undefined4 *)((int)__src + uVar5 + 0x44) = uVar6;
  lVar13 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x50));
  *(float *)((int)__src + uVar5 + 0x50) = (float)((longdouble)0.09090909090909091 * lVar13);
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x48));
  *(undefined4 *)(param_1 + 0x4c) = uVar6;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)((int)__src + uVar5 + 0x44);
  iVar2 = 0;
  do {
    iVar3 = iVar2 * 4;
    lVar13 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar3 + 8 + param_2));
    *(float *)((int)__src + iVar3 + 8 + uVar5) = (float)lVar13;
    lVar13 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar3 + 0x14 + param_2));
    *(float *)((int)__src + iVar3 + 0x14 + uVar5) = (float)lVar13;
    lVar13 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar3 + 0x24 + param_2));
    *(float *)((int)__src + iVar3 + 0x24 + uVar5) = (float)lVar13;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  iVar2 = *(int *)((int)__src + uVar5 + 0x30);
  iVar3 = *(int *)((int)__src + uVar5 + 0x44);
  if ((*(byte *)((int)__src + uVar5 + 0x34) & 3) != 0) {
    Sys_Error("Mod_LoadAliasModel: skinwidth not multiple of 4");
  }
  *__src = uVar5;
  iVar4 = *(int *)((int)__src + uVar5 + 0x38) * *(int *)((int)__src + uVar5 + 0x34);
  if (iVar2 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of skins: %d\n",iVar2);
  }
  puVar11 = (undefined4 *)(param_2 + 0x54);
  iVar7 = Hunk_AllocName(iVar2 * 0xc,loadname);
  __src[2] = iVar7 - (int)__src;
  iVar12 = 0;
  if (0 < iVar2) {
    do {
      iVar8 = (*LittleLong)(*puVar11);
      *(int *)(iVar7 + iVar12 * 0xc) = iVar8;
      if (iVar8 == 0) {
        puVar11 = (undefined4 *)Mod_LoadAliasSkin(puVar11 + 1,iVar12 * 0xc + 8 + iVar7,iVar4,__src);
      }
      else {
        puVar11 = (undefined4 *)
                  Mod_LoadAliasSkinGroup(puVar11 + 1,iVar7 + 8 + iVar12 * 0xc,iVar4,__src);
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar2);
  }
  uVar9 = uVar5 + 0x54;
  __src[1] = uVar9;
  for (iVar2 = 0; iVar2 < *(int *)((int)__src + uVar5 + 0x3c); iVar2 = iVar2 + 1) {
    iVar7 = iVar2 * 0xc;
    uVar6 = (*LittleLong)(puVar11[iVar2 * 3]);
    *(undefined4 *)((int)__src + iVar7 + uVar9) = uVar6;
    iVar4 = (*LittleLong)(puVar11[iVar2 * 3 + 1]);
    *(int *)((int)__src + iVar7 + uVar5 + 0x58) = iVar4 << 0x10;
    iVar4 = (*LittleLong)(puVar11[iVar2 * 3 + 2]);
    *(int *)((int)__src + iVar7 + uVar5 + 0x5c) = iVar4 << 0x10;
  }
  iVar2 = *(int *)((int)__src + uVar5 + 0x3c);
  uVar9 = iVar2 * 0xc + uVar9;
  __src[3] = uVar9;
  iVar4 = 0;
  if (0 < *(int *)((int)__src + uVar5 + 0x40)) {
    do {
      uVar6 = (*LittleLong)(puVar11[iVar2 * 3 + iVar4 * 4]);
      *(undefined4 *)((int)__src + iVar4 * 0x10 + uVar9) = uVar6;
      local_3c = 0;
      do {
        uVar6 = (*LittleLong)(puVar11[iVar2 * 3 + iVar4 * 4 + local_3c + 1]);
        *(undefined4 *)((int)__src + local_3c * 4 + iVar4 * 0x10 + uVar9 + 4) = uVar6;
        local_3c = local_3c + 1;
      } while (local_3c < 3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)__src + uVar5 + 0x40));
  }
  if (iVar3 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of frames: %d\n",iVar3);
  }
  puVar11 = puVar11 + iVar2 * 3 + *(int *)((int)__src + uVar5 + 0x40) * 4;
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      uVar9 = (*LittleLong)(*puVar11);
      __src[iVar2 * 8 + 5] = uVar9;
      if (uVar9 == 0) {
        puVar11 = (undefined4 *)
                  Mod_LoadAliasFrame(puVar11 + 1,__src + iVar2 * 8 + 8,
                                     *(undefined4 *)((int)__src + uVar5 + 0x3c),
                                     __src + iVar2 * 8 + 6,__src + iVar2 * 8 + 7,__src,
                                     __src + iVar2 * 8 + 9);
      }
      else {
        puVar11 = (undefined4 *)
                  Mod_LoadAliasGroup(puVar11 + 1,__src + iVar2 * 8 + 8,
                                     *(undefined4 *)((int)__src + uVar5 + 0x3c),
                                     __src + iVar2 * 8 + 6,__src + iVar2 * 8 + 7,__src,
                                     __src + iVar2 * 8 + 9);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  *(undefined4 *)(param_1 + 0x44) = 2;
  *(undefined4 *)(param_1 + 0x5c) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x58) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x54) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x68) = 0x41800000;
  *(undefined4 *)(param_1 + 100) = 0x41800000;
  *(undefined4 *)(param_1 + 0x60) = 0x41800000;
  iVar2 = Hunk_AllocName(0x800,loadname);
  iVar3 = 0;
  do {
    pbVar10 = (byte *)(iVar3 * 3 + (int)puVar11);
    *(ushort *)(iVar2 + iVar3 * 8) = (ushort)pbVar10[2];
    *(ushort *)(iVar2 + 2 + iVar3 * 8) = (ushort)pbVar10[1];
    *(ushort *)(iVar2 + 4 + iVar3 * 8) = (ushort)*pbVar10;
    *(undefined2 *)(iVar2 + 6 + iVar3 * 8) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  __src[4] = iVar2 - (int)__src;
  iVar2 = Hunk_LowMark();
  Cache_Alloc(param_1 + 0x184,iVar2 - iVar1,loadname);
  if (*(int *)(param_1 + 0x184) != 0) {
    memcpy(*(void **)(param_1 + 0x184),__src,iVar2 - iVar1);
    Hunk_FreeToLowMark(iVar1);
  }
  return;
}


// Mod_LoadAliasSkin  @ 08064af0
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


// Mod_LoadAliasSkinGroup  @ 08064b70
undefined4 * Mod_LoadAliasSkinGroup(undefined4 *param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  longdouble lVar5;
  
  iVar1 = (*LittleLong)(*param_1);
  piVar2 = (int *)Hunk_AllocName((iVar1 * 3 + -3) * 4 + 0x14,loadname);
  *piVar2 = iVar1;
  *param_2 = (int)piVar2 - param_4;
  param_1 = param_1 + 1;
  pfVar3 = (float *)Hunk_AllocName(iVar1 << 2,loadname);
  piVar2[1] = (int)pfVar3 - param_4;
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      lVar5 = (longdouble)(*LittleFloat)(*param_1);
      *pfVar3 = (float)lVar5;
      if (lVar5 <= (longdouble)0) {
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 1;
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      param_1 = (undefined4 *)Mod_LoadAliasSkin(param_1,piVar2 + iVar4 * 3 + 4,param_3,param_4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return param_1;
}


// Mod_LoadBrushModel  @ 080646d0
void Mod_LoadBrushModel(char *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  longdouble lVar5;
  int local_24;
  uint local_14;
  char local_10 [12];
  
  pcVar4 = loadmodel;
  pcVar4[0x44] = '\0';
  pcVar4[0x45] = '\0';
  pcVar4[0x46] = '\0';
  pcVar4[0x47] = '\0';
  iVar1 = (*LittleLong)(*param_2);
  if (1 < iVar1 - 0x1dU) {
    Sys_Error("Mod_LoadBrushModel: %s has wrong version number (%i should be %i)",param_1,iVar1,0x1e
             );
  }
  mod_base = param_2;
  local_14 = 0;
  do {
    uVar2 = (*LittleLong)(param_2[local_14]);
    param_2[local_14] = uVar2;
    local_14 = local_14 + 1;
  } while (local_14 < 0x1f);
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
  param_1[0x48] = '\x02';
  param_1[0x49] = '\0';
  param_1[0x4a] = '\0';
  param_1[0x4b] = '\0';
  param_1[0x50] = '\0';
  param_1[0x51] = '\0';
  param_1[0x52] = '\0';
  param_1[0x53] = '\0';
  local_14 = 0;
  if (0 < *(int *)(param_1 + 0x78)) {
    do {
      puVar3 = (undefined4 *)(local_14 * 0x40 + *(int *)(param_1 + 0x7c));
      *(undefined4 *)(param_1 + 0xd8) = puVar3[9];
      local_24 = 1;
      do {
        *(undefined4 *)(param_1 + local_24 * 0x28 + 0xd8) = puVar3[local_24 + 9];
        *(int *)(param_1 + local_24 * 0x28 + 0xdc) = *(int *)(param_1 + 0xc0) + -1;
        local_24 = local_24 + 1;
      } while (local_24 < 4);
      *(undefined4 *)(param_1 + 0x70) = puVar3[0xe];
      *(undefined4 *)(param_1 + 0x74) = puVar3[0xf];
      *(undefined4 *)(param_1 + 0x60) = puVar3[3];
      *(undefined4 *)(param_1 + 100) = puVar3[4];
      *(undefined4 *)(param_1 + 0x68) = puVar3[5];
      *(undefined4 *)(param_1 + 0x54) = *puVar3;
      *(undefined4 *)(param_1 + 0x58) = puVar3[1];
      *(undefined4 *)(param_1 + 0x5c) = puVar3[2];
      lVar5 = (longdouble)RadiusFromBounds(param_1 + 0x54,param_1 + 0x60);
      *(float *)(param_1 + 0x6c) = (float)lVar5;
      *(undefined4 *)(param_1 + 0x88) = puVar3[0xd];
      if ((int)local_14 < *(int *)(param_1 + 0x78) + -1) {
        sprintf(local_10,"*%i",local_14 + 1);
        loadmodel = (char *)Mod_FindName(local_10);
        pcVar4 = loadmodel;
        for (iVar1 = 0x62; iVar1 != 0; iVar1 = iVar1 + -1) {
          *(undefined4 *)pcVar4 = *(undefined4 *)param_1;
          param_1 = param_1 + 4;
          pcVar4 = pcVar4 + 4;
        }
        strcpy(loadmodel,local_10);
        param_1 = loadmodel;
      }
      local_14 = local_14 + 1;
    } while ((int)local_14 < *(int *)(param_1 + 0x78));
  }
  return;
}


// Mod_LoadClipnodes  @ 080640f0
void Mod_LoadClipnodes(int *param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)(mod_base + *param_1);
  if ((*(byte *)(param_1 + 1) & 7) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar5 = (uint)param_1[1] >> 3;
  puVar2 = (undefined4 *)Hunk_AllocName(uVar5 * 8,loadname);
  iVar6 = loadmodel;
  *(undefined4 **)(loadmodel + 0xc4) = puVar2;
  *(uint *)(iVar6 + 0xc0) = uVar5;
  *(undefined4 **)(iVar6 + 0xf8) = puVar2;
  *(undefined4 *)(iVar6 + 0x100) = 0;
  iVar4 = uVar5 - 1;
  *(int *)(iVar6 + 0x154) = iVar4;
  *(int *)(iVar6 + 0x104) = iVar4;
  uVar3 = *(undefined4 *)(iVar6 + 0x84);
  *(undefined4 *)(iVar6 + 0xfc) = uVar3;
  *(undefined4 *)(iVar6 + 0x108) = 0xc1800000;
  *(undefined4 *)(iVar6 + 0x10c) = 0xc1800000;
  *(undefined4 *)(iVar6 + 0x110) = 0xc2100000;
  *(undefined4 *)(iVar6 + 0x114) = 0x41800000;
  *(undefined4 *)(iVar6 + 0x118) = 0x41800000;
  *(undefined4 *)(iVar6 + 0x11c) = 0x42100000;
  *(undefined4 **)(iVar6 + 0x120) = puVar2;
  *(undefined4 *)(iVar6 + 0x128) = 0;
  *(int *)(iVar6 + 300) = iVar4;
  *(undefined4 *)(iVar6 + 0x124) = uVar3;
  *(undefined4 *)(iVar6 + 0x130) = 0xc2000000;
  *(undefined4 *)(iVar6 + 0x134) = 0xc2000000;
  *(undefined4 *)(iVar6 + 0x138) = 0xc2000000;
  *(undefined4 *)(iVar6 + 0x13c) = 0x42000000;
  *(undefined4 *)(iVar6 + 0x140) = 0x42000000;
  *(undefined4 *)(iVar6 + 0x144) = 0x42000000;
  *(undefined4 **)(iVar6 + 0x148) = puVar2;
  *(undefined4 *)(iVar6 + 0x150) = 0;
  *(undefined4 *)(iVar6 + 0x14c) = uVar3;
  *(undefined4 *)(iVar6 + 0x158) = 0xc1800000;
  *(undefined4 *)(iVar6 + 0x15c) = 0xc1800000;
  *(undefined4 *)(iVar6 + 0x160) = 0xc1900000;
  *(undefined4 *)(iVar6 + 0x164) = 0x41800000;
  *(undefined4 *)(iVar6 + 0x168) = 0x41800000;
  *(undefined4 *)(iVar6 + 0x16c) = 0x41900000;
  iVar6 = 0;
  if (uVar5 != 0) {
    do {
      uVar3 = (*LittleLong)(*puVar7);
      *puVar2 = uVar3;
      uVar1 = (*LittleShort)((int)*(short *)(puVar7 + 1));
      *(undefined2 *)(puVar2 + 1) = uVar1;
      uVar1 = (*LittleShort)((int)*(short *)((int)puVar7 + 6));
      *(undefined2 *)((int)puVar2 + 6) = uVar1;
      iVar6 = iVar6 + 1;
      puVar2 = puVar2 + 2;
      puVar7 = puVar7 + 2;
    } while (iVar6 < (int)uVar5);
  }
  return;
}


// Mod_LoadEdges  @ 08063590
void Mod_LoadEdges(int *param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  
  psVar5 = (short *)(mod_base + *param_1);
  if ((*(byte *)(param_1 + 1) & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar3 = (uint)param_1[1] >> 2;
  puVar2 = (undefined2 *)Hunk_AllocName(uVar3 * 8 + 8,loadname);
  iVar4 = loadmodel;
  *(undefined2 **)(loadmodel + 0x9c) = puVar2;
  *(uint *)(iVar4 + 0x98) = uVar3;
  if (uVar3 != 0) {
    iVar4 = 0;
    do {
      uVar1 = (*LittleShort)((int)*psVar5);
      *puVar2 = uVar1;
      uVar1 = (*LittleShort)((int)psVar5[1]);
      puVar2[1] = uVar1;
      iVar4 = iVar4 + 1;
      psVar5 = psVar5 + 2;
      puVar2 = puVar2 + 4;
    } while (iVar4 < (int)uVar3);
  }
  return;
}


// Mod_LoadEntities  @ 08063260
void Mod_LoadEntities(int *param_1)

{
  void *__dest;
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x180) = 0;
  }
  else {
    __dest = (void *)Hunk_AllocName(param_1[1],loadname);
    *(void **)(loadmodel + 0x180) = __dest;
    memcpy(__dest,(void *)(*param_1 + mod_base),param_1[1]);
    if (*(int *)(loadmodel + 0x180) != 0) {
      pcVar1 = *(char **)(loadmodel + 0x180);
      do {
        pcVar1 = (char *)COM_Parse(pcVar1);
        if (*pcVar1 == '\0') {
          return;
        }
        if (com_token == '}') {
          return;
        }
        iVar2 = 4;
        bVar5 = true;
        pcVar3 = &com_token;
        pcVar4 = "wad";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
      } while (!bVar5);
      COM_Parse(pcVar1);
      if (wadpath != (char *)0x0) {
        free(wadpath);
      }
      wadpath = strdup(&com_token);
    }
  }
  return;
}


// Mod_LoadFaces  @ 08063a70
void Mod_LoadFaces(int *param_1)

{
  byte *pbVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  short *psVar8;
  int local_14;
  int local_c;
  
  psVar8 = (short *)(*param_1 + mod_base);
  if (param_1[1] != ((uint)param_1[1] / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar7 = (uint)param_1[1] / 0x14;
  iVar4 = Hunk_AllocName(uVar7 * 0x44,loadname);
  iVar6 = loadmodel;
  *(int *)(loadmodel + 0xb4) = iVar4;
  *(uint *)(iVar6 + 0xb0) = uVar7;
  local_c = 0;
  if (uVar7 != 0) {
    do {
      uVar5 = (*LittleLong)(*(undefined4 *)(psVar8 + 2));
      *(undefined4 *)(iVar4 + 0x14) = uVar5;
      sVar2 = (*LittleShort)((int)psVar8[4]);
      *(int *)(iVar4 + 0x18) = (int)sVar2;
      *(undefined4 *)(iVar4 + 0x10) = 0;
      *(undefined4 *)(iVar4 + 0x40) = 0;
      sVar2 = (*LittleShort)((int)*psVar8);
      sVar3 = (*LittleShort)((int)psVar8[1]);
      if (sVar3 != 0) {
        *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) | 2;
      }
      *(int *)(iVar4 + 0xc) = sVar2 * 0x14 + *(int *)(loadmodel + 0x84);
      sVar2 = (*LittleShort)((int)psVar8[5]);
      *(int *)(iVar4 + 0x34) = sVar2 * 0x2c + *(int *)(loadmodel + 0xac);
      CalcSurfaceExtents(iVar4);
      local_14 = 0;
      do {
        *(undefined1 *)(local_14 + iVar4 + 0x38) = *(undefined1 *)((int)psVar8 + local_14 + 0xc);
        local_14 = local_14 + 1;
      } while (local_14 < 4);
      iVar6 = (*LittleLong)(*(undefined4 *)(psVar8 + 8));
      if (iVar6 == -1) {
        *(undefined4 *)(iVar4 + 0x3c) = 0;
      }
      else {
        *(int *)(iVar4 + 0x3c) = iVar6 + *(int *)(loadmodel + 0x17c);
      }
      iVar6 = Q_strncmp(*(undefined4 *)(*(int *)(iVar4 + 0x34) + 0x24),&DAT_080a2157,3);
      if (iVar6 == 0) {
        *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) | 0x24;
      }
      else {
        iVar6 = Q_strncmp(*(undefined4 *)(*(int *)(iVar4 + 0x34) + 0x24),"scroll",6);
        if (iVar6 == 0) {
          *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) | 0x20;
          *(undefined2 *)(iVar4 + 0x30) =
               *(undefined2 *)(*(int *)(*(int *)(iVar4 + 0x34) + 0x24) + 0x10);
          iVar6 = *(int *)(*(int *)(iVar4 + 0x34) + 0x24);
LAB_08063d0b:
          *(undefined2 *)(iVar4 + 0x32) = *(undefined2 *)(iVar6 + 0x14);
        }
        else if (((**(char **)(*(int *)(iVar4 + 0x34) + 0x24) == '!') ||
                 (iVar6 = strncasecmp(*(char **)(*(int *)(iVar4 + 0x34) + 0x24),"laser",5),
                 iVar6 == 0)) ||
                (iVar6 = strncasecmp(*(char **)(*(int *)(iVar4 + 0x34) + 0x24),"water",5),
                iVar6 == 0)) {
          *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) | 0x30;
          local_14 = 0;
          do {
            *(undefined2 *)(local_14 * 2 + iVar4 + 0x30) = 0x4000;
            *(undefined2 *)(local_14 * 2 + iVar4 + 0x2c) = 0xe000;
            pbVar1 = (byte *)(*(int *)(iVar4 + 0x34) + 0x28);
            *pbVar1 = *pbVar1 | 1;
            local_14 = local_14 + 1;
          } while (local_14 < 2);
        }
        else {
          iVar6 = *(int *)(iVar4 + 0x34);
          if ((*(byte *)(iVar6 + 0x28) & 1) != 0) {
            *(byte *)(iVar4 + 0x10) = *(byte *)(iVar4 + 0x10) | 0x20;
            *(undefined2 *)(iVar4 + 0x30) = *(undefined2 *)(*(int *)(iVar6 + 0x24) + 0x10);
            iVar6 = *(int *)(iVar6 + 0x24);
            goto LAB_08063d0b;
          }
        }
      }
      local_c = local_c + 1;
      psVar8 = psVar8 + 10;
      iVar4 = iVar4 + 0x44;
    } while (local_c < (int)uVar7);
  }
  return;
}


// Mod_LoadLeafs  @ 08063f50
void Mod_LoadLeafs(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  short sVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*param_1 + mod_base);
  if (param_1[1] != ((uint)param_1[1] / 0x1c) * 0x1c) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar6 = (uint)param_1[1] / 0x1c;
  puVar4 = (undefined4 *)Hunk_AllocName(uVar6 * 0x30,loadname);
  iVar7 = loadmodel;
  *(undefined4 **)(loadmodel + 0x8c) = puVar4;
  *(uint *)(iVar7 + 0x88) = uVar6;
  local_c = 0;
  if (uVar6 != 0) {
    do {
      iVar7 = 0;
      do {
        iVar1 = iVar7 * 2;
        uVar2 = (*LittleShort)((int)*(short *)(iVar1 + 8 + (int)local_8));
        *(undefined2 *)((int)puVar4 + iVar1 + 8) = uVar2;
        uVar2 = (*LittleShort)((int)*(short *)(iVar1 + 0xe + (int)local_8));
        *(undefined2 *)((int)puVar4 + iVar7 * 2 + 0xe) = uVar2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 3);
      uVar5 = (*LittleLong)(*local_8);
      *puVar4 = uVar5;
      puVar4[8] = (uint)*(ushort *)(local_8 + 5) * 4 + *(int *)(loadmodel + 0xcc);
      sVar3 = (*LittleShort)((int)*(short *)((int)local_8 + 0x16));
      puVar4[9] = (int)sVar3;
      iVar7 = (*LittleLong)(local_8[1]);
      if (iVar7 == -1) {
        puVar4[6] = 0;
      }
      else {
        puVar4[6] = iVar7 + *(int *)(loadmodel + 0x178);
      }
      puVar4[7] = 0;
      iVar7 = 0;
      do {
        *(undefined1 *)((int)puVar4 + iVar7 + 0x2c) = *(undefined1 *)((int)local_8 + iVar7 + 0x18);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 4);
      local_c = local_c + 1;
      local_8 = local_8 + 7;
      puVar4 = puVar4 + 0xc;
    } while (local_c < (int)uVar6);
  }
  return;
}


// Mod_LoadLighting  @ 080631a0
void Mod_LoadLighting(int *param_1)

{
  void *__dest;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x17c) = 0;
  }
  else {
    __dest = (void *)Hunk_AllocName(param_1[1],loadname);
    *(void **)(loadmodel + 0x17c) = __dest;
    memcpy(__dest,(void *)(*param_1 + mod_base),param_1[1]);
  }
  return;
}


// Mod_LoadMarksurfaces  @ 080643e0
void Mod_LoadMarksurfaces(int *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = *param_1 + mod_base;
  if ((*(byte *)(param_1 + 1) & 1) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar5 = (uint)param_1[1] >> 1;
  iVar3 = Hunk_AllocName(uVar5 * 4,loadname);
  iVar4 = loadmodel;
  *(int *)(loadmodel + 0xcc) = iVar3;
  *(uint *)(iVar4 + 200) = uVar5;
  iVar4 = 0;
  if (uVar5 != 0) {
    do {
      sVar1 = (*LittleShort)((int)*(short *)(iVar2 + iVar4 * 2));
      if (*(int *)(loadmodel + 0xb0) <= (int)sVar1) {
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      *(int *)(iVar3 + iVar4 * 4) = sVar1 * 0x44 + *(int *)(loadmodel + 0xb4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar5);
  }
  return;
}


// Mod_LoadModel  @ 080628c0
int Mod_LoadModel(int param_1,int param_2)

{
  int iVar1;
  undefined4 *__ptr;
  
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
  __ptr = (undefined4 *)COM_LoadFileForMe(param_1,0);
  if (__ptr == (undefined4 *)0x0) {
    if (param_2 != 0) {
      Sys_Error("Mod_NumForName: %s not found",param_1);
    }
    return 0;
  }
  if ((byte)(1.0 < (float)developer._12_4_ |
             (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)developer._12_4_ == 1.0) << 0xe) >> 8)) == 1) {
    Con_DPrintf("loading %s\n",param_1);
  }
  COM_FileBase(param_1,loadname);
  loadmodel = param_1;
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar1 = (*LittleLong)(*__ptr);
  if (iVar1 == 0x50534449) {
    Mod_LoadSpriteModel(param_1,__ptr);
  }
  else {
    if (iVar1 < 0x5053444a) {
      if (iVar1 == 0x4f504449) {
        Mod_LoadAliasModel(param_1,__ptr);
        goto LAB_080629e7;
      }
    }
    else if (iVar1 == 0x54534449) {
      Mod_LoadStudioModel(param_1,__ptr);
      goto LAB_080629e7;
    }
    Mod_LoadBrushModel(param_1,__ptr);
  }
LAB_080629e7:
  if (__ptr != (undefined4 *)0x0) {
    free(__ptr);
  }
  return param_1;
}


// Mod_LoadNodes  @ 08063d70
void Mod_LoadNodes(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int local_14;
  undefined4 *local_10;
  int local_8;
  
  local_10 = (undefined4 *)(*param_1 + mod_base);
  if (param_1[1] != ((uint)param_1[1] / 0x18) * 0x18) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar4 = (uint)param_1[1] / 0x18;
  local_14 = Hunk_AllocName(uVar4 * 0x28,loadname);
  iVar5 = loadmodel;
  *(int *)(loadmodel + 0xa4) = local_14;
  *(uint *)(iVar5 + 0xa0) = uVar4;
  local_8 = 0;
  if (uVar4 != 0) {
    do {
      iVar5 = 0;
      do {
        iVar1 = iVar5 * 2;
        uVar2 = (*LittleShort)((int)*(short *)(iVar1 + 8 + (int)local_10));
        *(undefined2 *)(iVar1 + local_14 + 8) = uVar2;
        uVar2 = (*LittleShort)((int)*(short *)(iVar1 + 0xe + (int)local_10));
        *(undefined2 *)(local_14 + 0xe + iVar5 * 2) = uVar2;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 3);
      iVar5 = (*LittleLong)(*local_10);
      *(int *)(local_14 + 0x18) = iVar5 * 0x14 + *(int *)(loadmodel + 0x84);
      uVar2 = (*LittleShort)((int)*(short *)(local_10 + 5));
      *(undefined2 *)(local_14 + 0x24) = uVar2;
      uVar2 = (*LittleShort)((int)*(short *)((int)local_10 + 0x16));
      *(undefined2 *)(local_14 + 0x26) = uVar2;
      iVar5 = 0;
      do {
        sVar3 = (*LittleShort)((int)*(short *)((int)local_10 + iVar5 * 2 + 4));
        uVar6 = (uint)sVar3;
        if ((int)uVar6 < 0) {
          *(uint *)(local_14 + 0x1c + iVar5 * 4) = ~uVar6 * 0x30 + *(int *)(loadmodel + 0x8c);
        }
        else {
          *(uint *)(local_14 + 0x1c + iVar5 * 4) = uVar6 * 0x28 + *(int *)(loadmodel + 0xa4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      local_8 = local_8 + 1;
      local_10 = local_10 + 6;
      local_14 = local_14 + 0x28;
    } while (local_8 < (int)uVar4);
  }
  if (uVar4 != 0) {
    Mod_SetParent(*(undefined4 *)(loadmodel + 0xa4),0);
  }
  return;
}


// Mod_LoadPlanes  @ 08064540
void Mod_LoadPlanes(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longdouble lVar5;
  uint local_14;
  int local_c;
  int local_8;
  
  local_c = *param_1 + mod_base;
  if (param_1[1] != ((uint)param_1[1] / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar3 = (uint)param_1[1] / 0x14;
  iVar2 = Hunk_AllocName(uVar3 * 0x28,loadname);
  iVar4 = loadmodel;
  *(int *)(loadmodel + 0x84) = iVar2;
  *(uint *)(iVar4 + 0x80) = uVar3;
  local_8 = 0;
  if (uVar3 != 0) {
    do {
      local_14 = 0;
      iVar4 = 0;
      do {
        lVar5 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar4 * 4 + local_c));
        *(float *)(iVar4 * 4 + iVar2) = (float)lVar5;
        if (lVar5 < (longdouble)0) {
          local_14 = local_14 | 1 << ((byte)iVar4 & 0x1f);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 3);
      lVar5 = (longdouble)(*LittleFloat)(*(undefined4 *)(local_c + 0xc));
      *(float *)(iVar2 + 0xc) = (float)lVar5;
      uVar1 = (*LittleLong)(*(undefined4 *)(local_c + 0x10));
      *(undefined1 *)(iVar2 + 0x10) = uVar1;
      *(undefined1 *)(iVar2 + 0x11) = (undefined1)local_14;
      local_8 = local_8 + 1;
      local_c = local_c + 0x14;
      iVar2 = iVar2 + 0x14;
    } while (local_8 < (int)uVar3);
  }
  return;
}


// Mod_LoadSpriteFrame  @ 08065220
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


// Mod_LoadSpriteGroup  @ 08065340
undefined4 * Mod_LoadSpriteGroup(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  longdouble lVar5;
  
  iVar1 = (*LittleLong)(*param_1);
  piVar2 = (int *)Hunk_AllocName(iVar1 * 4 + 8,loadname);
  *piVar2 = iVar1;
  *param_2 = piVar2;
  param_1 = param_1 + 1;
  pfVar3 = (float *)Hunk_AllocName(iVar1 << 2,loadname);
  piVar2[1] = (int)pfVar3;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      lVar5 = (longdouble)(*LittleFloat)(*param_1);
      *pfVar3 = (float)lVar5;
      if (*pfVar3 <= 0.0) {
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
      }
      pfVar3 = pfVar3 + 1;
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      param_1 = (undefined4 *)Mod_LoadSpriteFrame(param_1,piVar2 + iVar4 + 2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return param_1;
}


// Mod_LoadSpriteModel  @ 08065410
void Mod_LoadSpriteModel(int param_1,int param_2)

{
  float fVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  longdouble lVar11;
  
  iVar3 = (*LittleLong)(*(undefined4 *)(param_2 + 4));
  if (iVar3 != 2) {
    Sys_Error("%s has wrong version number (%i should be %i)",param_1,iVar3,2);
  }
  iVar4 = (*LittleLong)(*(undefined4 *)(param_2 + 0x1c));
  puVar5 = (undefined2 *)Hunk_AllocName(iVar4 * 8 + 0x1e + *(short *)(param_2 + 0x28) * 8,loadname);
  *(undefined2 **)(param_1 + 0x184) = puVar5;
  uVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 8));
  *puVar5 = uVar2;
  uVar2 = (*LittleLong)(*(undefined4 *)(param_2 + 0xc));
  puVar5[1] = uVar2;
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(puVar5 + 2) = uVar6;
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(puVar5 + 4) = uVar6;
  lVar11 = (longdouble)(*LittleFloat)(*(undefined4 *)(param_2 + 0x20));
  *(float *)(puVar5 + 10) = (float)lVar11;
  uVar6 = (*LittleLong)(*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x4c) = uVar6;
  *(int *)(puVar5 + 6) = iVar4;
  iVar3 = *(int *)(puVar5 + 2);
  *(float *)(param_1 + 0x58) = (float)(-iVar3 / 2);
  *(float *)(param_1 + 0x54) = (float)(-iVar3 / 2);
  fVar1 = (float)(*(int *)(puVar5 + 2) - (*(int *)(puVar5 + 2) >> 0x1f) >> 1);
  *(float *)(param_1 + 100) = fVar1;
  *(float *)(param_1 + 0x60) = fVar1;
  *(float *)(param_1 + 0x5c) = (float)(-*(int *)(puVar5 + 4) / 2);
  *(float *)(param_1 + 0x68) = (float)(*(int *)(puVar5 + 4) - (*(int *)(puVar5 + 4) >> 0x1f) >> 1);
  *(int *)(puVar5 + 8) = iVar4 * 8 + 0x1e;
  puVar10 = puVar5 + iVar4 * 4 + 0xe;
  uVar8 = (uint)*(ushort *)(param_2 + 0x28);
  *puVar10 = *(ushort *)(param_2 + 0x28);
  iVar3 = 0;
  if (uVar8 != 0) {
    do {
      puVar10[iVar3 * 4 + 1] = (ushort)*(byte *)(param_2 + 0x2a + iVar3 * 3);
      iVar9 = iVar3 * 3 + param_2 + 0x2a;
      puVar10[iVar3 * 4 + 2] = (ushort)*(byte *)(iVar9 + 1);
      puVar10[iVar3 * 4 + 3] = (ushort)*(byte *)(iVar9 + 2);
      puVar10[iVar3 * 4 + 4] = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar8);
  }
  if (iVar4 < 1) {
    Sys_Error("Mod_LoadSpriteModel: Invalid # of frames: %d\n",iVar4);
  }
  *(int *)(param_1 + 0x48) = iVar4;
  *(undefined4 *)(param_1 + 0x50) = 0;
  puVar7 = (undefined4 *)(param_2 + 0x2a + uVar8 * 3);
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      iVar9 = (*LittleLong)(*puVar7);
      *(int *)(puVar5 + iVar3 * 4 + 0xe) = iVar9;
      if (iVar9 == 0) {
        puVar7 = (undefined4 *)Mod_LoadSpriteFrame(puVar7 + 1,puVar5 + iVar3 * 4 + 0x10);
      }
      else {
        puVar7 = (undefined4 *)Mod_LoadSpriteGroup(puVar7 + 1,puVar5 + iVar3 * 4 + 0x10);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  *(undefined4 *)(param_1 + 0x44) = 1;
  return;
}


// Mod_LoadStudioModel  @ 0805f7a0
void Mod_LoadStudioModel(int param_1,undefined4 *param_2)

{
  void *__dest;
  int iVar1;
  int iVar2;
  size_t __n;
  ushort *__dest_00;
  undefined4 *puVar3;
  byte *__src;
  int local_8;
  
  iVar1 = (*LittleLong)(param_2[1]);
  if (iVar1 != 10) {
    puVar3 = param_2;
    for (iVar1 = 0x3d; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    builtin_strncpy((char *)(param_2 + 2),"bogu",4);
    *(undefined2 *)(param_2 + 3) = 0x73;
    param_2[0x12] = 0xf4;
    param_2[0x2f] = 0xf4;
  }
  *(undefined4 *)(param_1 + 0x44) = 3;
  *(undefined4 *)(param_1 + 0x50) = param_2[0x22];
  Cache_Alloc(param_1 + 0x184,param_2[0x2d] * 0x500 + param_2[0x12],param_1);
  if (*(int *)(param_1 + 0x184) != 0) {
    __dest = *(void **)(param_1 + 0x184);
    iVar1 = param_2[0x2e];
    if (iVar1 == 0) {
      memcpy(__dest,param_2,param_2[0x12]);
    }
    else {
      memcpy(__dest,param_2,param_2[0x2f]);
      __src = (byte *)(param_2[0x2f] + (int)param_2);
      __dest_00 = (ushort *)((int)__dest + param_2[0x2f]);
      local_8 = 0;
      if (0 < (int)param_2[0x2d]) {
        do {
          iVar2 = local_8 * 0x50;
          *(int *)((int)__dest + iVar2 + iVar1 + 0x4c) = (int)__dest_00 - (int)__dest;
          __n = *(int *)((int)__dest + iVar2 + iVar1 + 0x44) *
                *(int *)((int)__dest + iVar2 + iVar1 + 0x48);
          memcpy(__dest_00,__src,__n);
          __dest_00 = (ushort *)((int)__dest_00 + __n);
          __src = __src + __n;
          iVar2 = 0;
          do {
            *__dest_00 = (ushort)(byte)texgammatable[*__src];
            __dest_00[1] = (ushort)(byte)texgammatable[__src[1]];
            __dest_00[2] = (ushort)(byte)texgammatable[__src[2]];
            __dest_00[3] = 0;
            __dest_00 = __dest_00 + 4;
            __src = __src + 3;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x100);
          local_8 = local_8 + 1;
        } while (local_8 < (int)param_2[0x2d]);
      }
    }
  }
  return;
}


// Mod_LoadSubmodels  @ 08063420
void Mod_LoadSubmodels(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  longdouble lVar6;
  int local_c;
  int local_8;
  
  local_8 = *param_1 + mod_base;
  if ((*(byte *)(param_1 + 1) & 0x3f) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar4 = (uint)param_1[1] >> 6;
  iVar2 = Hunk_AllocName(uVar4 << 6,loadname);
  iVar5 = loadmodel;
  *(int *)(loadmodel + 0x7c) = iVar2;
  *(uint *)(iVar5 + 0x78) = uVar4;
  for (local_c = 0; local_c < (int)uVar4; local_c = local_c + 1) {
    iVar5 = 0;
    do {
      iVar1 = iVar5 * 4;
      lVar6 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar1 + local_8));
      *(float *)(iVar1 + iVar2) = (float)(lVar6 - (longdouble)1.0);
      lVar6 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar1 + 0xc + local_8));
      *(float *)(iVar1 + 0xc + iVar2) = (float)(lVar6 + (longdouble)1.0);
      lVar6 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar1 + 0x18 + local_8));
      *(float *)(iVar1 + 0x18 + iVar2) = (float)lVar6;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    iVar5 = 0;
    do {
      uVar3 = (*LittleLong)(*(undefined4 *)(iVar5 * 4 + local_8 + 0x24));
      *(undefined4 *)(iVar5 * 4 + iVar2 + 0x24) = uVar3;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    uVar3 = (*LittleLong)(*(undefined4 *)(local_8 + 0x34));
    *(undefined4 *)(iVar2 + 0x34) = uVar3;
    uVar3 = (*LittleLong)(*(undefined4 *)(local_8 + 0x38));
    *(undefined4 *)(iVar2 + 0x38) = uVar3;
    uVar3 = (*LittleLong)(*(undefined4 *)(local_8 + 0x3c));
    *(undefined4 *)(iVar2 + 0x3c) = uVar3;
    local_8 = local_8 + 0x40;
    iVar2 = iVar2 + 0x40;
  }
  return;
}


// Mod_LoadSurfedges  @ 080644b0
void Mod_LoadSurfedges(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = *param_1 + mod_base;
  if ((*(byte *)(param_1 + 1) & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar5 = (uint)param_1[1] >> 2;
  iVar2 = Hunk_AllocName(uVar5 * 4,loadname);
  iVar4 = loadmodel;
  *(int *)(loadmodel + 0xbc) = iVar2;
  *(uint *)(iVar4 + 0xb8) = uVar5;
  iVar4 = 0;
  if (uVar5 != 0) {
    do {
      uVar3 = (*LittleLong)(*(undefined4 *)(iVar1 + iVar4 * 4));
      *(undefined4 *)(iVar2 + iVar4 * 4) = uVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar5);
  }
  return;
}


// Mod_LoadTexinfo  @ 08063640
void Mod_LoadTexinfo(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  int local_c;
  int local_8;
  
  local_8 = *param_1 + mod_base;
  if (param_1[1] != ((uint)param_1[1] / 0x28) * 0x28) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar4 = (uint)param_1[1] / 0x28;
  iVar2 = Hunk_AllocName(uVar4 * 0x2c,loadname);
  iVar5 = loadmodel;
  *(int *)(loadmodel + 0xac) = iVar2;
  *(uint *)(iVar5 + 0xa8) = uVar4;
  local_c = 0;
  if (uVar4 != 0) {
    do {
      iVar5 = 0;
      do {
        lVar6 = (longdouble)(*LittleFloat)(*(undefined4 *)(iVar5 * 4 + local_8));
        *(float *)(iVar5 * 4 + iVar2) = (float)lVar6;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      lVar6 = (longdouble)Length(iVar2);
      lVar7 = (longdouble)Length(iVar2 + 0x10);
      fVar1 = (float)(lVar7 + (longdouble)(float)lVar6) * 0.5;
      if (0.32 <= fVar1) {
        if (0.49 <= fVar1) {
          if (0.99 <= fVar1) {
            *(undefined4 *)(iVar2 + 0x20) = 0x3f800000;
          }
          else {
            *(undefined4 *)(iVar2 + 0x20) = 0x40000000;
          }
        }
        else {
          *(undefined4 *)(iVar2 + 0x20) = 0x40400000;
        }
      }
      else {
        *(undefined4 *)(iVar2 + 0x20) = 0x40800000;
      }
      iVar5 = (*LittleLong)(*(undefined4 *)(local_8 + 0x20));
      uVar3 = (*LittleLong)(*(undefined4 *)(local_8 + 0x24));
      *(undefined4 *)(iVar2 + 0x28) = uVar3;
      if (*(int *)(loadmodel + 0x174) == 0) {
LAB_080637eb:
        *(undefined4 *)(iVar2 + 0x24) = r_notexture_mip;
        *(undefined4 *)(iVar2 + 0x28) = 0;
      }
      else {
        if (*(int *)(loadmodel + 0x170) <= iVar5) {
          Sys_Error("miptex >= loadmodel->numtextures");
        }
        iVar5 = *(int *)(*(int *)(loadmodel + 0x174) + iVar5 * 4);
        *(int *)(iVar2 + 0x24) = iVar5;
        if (iVar5 == 0) goto LAB_080637eb;
      }
      local_c = local_c + 1;
      local_8 = local_8 + 0x28;
      iVar2 = iVar2 + 0x2c;
    } while (local_c < (int)uVar4);
  }
  return;
}


// Mod_LoadTextures  @ 08062a60
void Mod_LoadTextures(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  longdouble lVar11;
  longdouble lVar12;
  int iStack_55404;
  undefined4 *puStack_553a8;
  int iStack_553a4;
  int iStack_5539c;
  undefined4 auStack_55398 [87249];
  int local_54 [10];
  int local_2c [10];
  
  bVar1 = false;
  lVar11 = (longdouble)Sys_FloatTime();
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x174) = 0;
  }
  else {
    piVar8 = (int *)(*param_1 + mod_base);
    iVar3 = (*LittleLong)();
    *piVar8 = iVar3;
    *(int *)(loadmodel + 0x170) = iVar3;
    uVar4 = Hunk_AllocName(*piVar8 << 2,loadname);
    *(undefined4 *)(loadmodel + 0x174) = uVar4;
    iStack_5539c = 0;
    if (0 < *piVar8) {
      do {
        iVar3 = (*LittleLong)();
        piVar8[iStack_5539c + 1] = iVar3;
        if (iVar3 != -1) {
          puStack_553a8 = (undefined4 *)(iVar3 + (int)piVar8);
          if (((byte)((byte)((ushort)((ushort)NAN((float)r_wadtextures._12_4_) << 10) >> 8) |
                     (byte)((ushort)((ushort)((float)r_wadtextures._12_4_ == 0.0) << 0xe) >> 8)) !=
               0x40) || (iVar3 = (*LittleLong)(), iVar3 == 0)) {
            if (!bVar1) {
              TEX_InitFromWad();
              AddAnimatingTextures();
              bVar1 = true;
            }
            iVar3 = LoadLump(puStack_553a8);
            if (iVar3 == 0) {
              piVar8[iStack_5539c + 1] = -1;
              goto LAB_08062e40;
            }
            puStack_553a8 = auStack_55398;
          }
          iVar3 = 0;
          do {
            uVar4 = (*LittleLong)();
            puStack_553a8[iVar3 + 6] = uVar4;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 4);
          uVar4 = (*LittleLong)();
          puStack_553a8[4] = uVar4;
          uVar4 = (*LittleLong)(puStack_553a8[5]);
          puStack_553a8[5] = uVar4;
          if (((*(byte *)(puStack_553a8 + 4) & 0xf) != 0) ||
             ((*(byte *)(puStack_553a8 + 5) & 0xf) != 0)) {
            Sys_Error("Texture %s is not 16 aligned");
          }
          iVar3 = ((uint)(puStack_553a8[4] * puStack_553a8[5]) >> 6) * 0x55;
          uVar7 = (uint)*(ushort *)((int)puStack_553a8 + iVar3 + 0x28);
          pcVar5 = (char *)Hunk_AllocName(iVar3 + 0x42 + uVar7 * 8);
          *(char **)(*(int *)(loadmodel + 0x174) + iStack_5539c * 4) = pcVar5;
          *(undefined4 *)pcVar5 = *puStack_553a8;
          *(undefined4 *)(pcVar5 + 4) = puStack_553a8[1];
          *(undefined4 *)(pcVar5 + 8) = puStack_553a8[2];
          *(undefined4 *)(pcVar5 + 0xc) = puStack_553a8[3];
          pcVar6 = strchr(pcVar5,0x7e);
          if (pcVar6 != (char *)0x0) {
            pcVar5[2] = ' ';
          }
          *(undefined4 *)(pcVar5 + 0x10) = puStack_553a8[4];
          *(undefined4 *)(pcVar5 + 0x14) = puStack_553a8[5];
          iVar9 = 0;
          do {
            *(int *)(pcVar5 + iVar9 * 4 + 0x2c) = puStack_553a8[iVar9 + 6] + 0x18;
            iVar9 = iVar9 + 1;
          } while (iVar9 < 4);
          *(int *)(pcVar5 + 0x3c) = iVar3 + 0x42;
          memcpy(pcVar5 + 0x40,puStack_553a8 + 10,iVar3 + 2);
          iVar9 = Q_strncmp(puStack_553a8,&DAT_080a2157);
          if (iVar9 == 0) {
            R_InitSky();
          }
          iVar9 = 0;
          if (uVar7 != 0) {
            do {
              (pcVar5 + iVar9 * 8 + iVar3 + 0x48)[0] = '\0';
              (pcVar5 + iVar9 * 8 + iVar3 + 0x48)[1] = '\0';
              *(ushort *)(pcVar5 + iVar9 * 8 + iVar3 + 0x46) =
                   (ushort)(byte)texgammatable
                                 [*(byte *)((int)puStack_553a8 + iVar9 * 3 + iVar3 + 0x2a)];
              iVar2 = iVar9 * 3 + iVar3 + 0x2a;
              *(ushort *)(pcVar5 + iVar9 * 8 + iVar3 + 0x44) =
                   (ushort)(byte)texgammatable[*(byte *)((int)puStack_553a8 + iVar2 + 1)];
              *(ushort *)(pcVar5 + iVar9 * 8 + iVar3 + 0x42) =
                   (ushort)(byte)texgammatable[*(byte *)((int)puStack_553a8 + iVar2 + 2)];
              iVar9 = iVar9 + 1;
            } while (iVar9 < (int)uVar7);
          }
        }
LAB_08062e40:
        iStack_5539c = iStack_5539c + 1;
      } while (iStack_5539c < *piVar8);
    }
    if (bVar1) {
      TEX_CleanupWadInfo();
    }
    iStack_5539c = 0;
    if (0 < *piVar8) {
      do {
        pcVar5 = *(char **)(*(int *)(loadmodel + 0x174) + iStack_5539c * 4);
        if ((pcVar5 != (char *)0x0) &&
           (((*pcVar5 == '+' || (*pcVar5 == '-')) && (*(int *)(pcVar5 + 0x24) == 0)))) {
          piVar10 = local_2c;
          for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *piVar10 = 0;
            piVar10 = piVar10 + 1;
          }
          piVar10 = local_54;
          for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *piVar10 = 0;
            piVar10 = piVar10 + 1;
          }
          iStack_55404 = (int)pcVar5[1];
          iStack_553a4 = 0;
          if (iStack_55404 - 0x61U < 0x1a) {
            iStack_55404 = iStack_55404 + -0x20;
          }
          iVar3 = iStack_55404;
          iVar9 = iStack_5539c;
          if (iStack_55404 - 0x30U < 10) {
            iStack_553a4 = 0;
            local_2c[iStack_55404 - 0x30U] = (int)pcVar5;
            iStack_55404 = iStack_55404 + -0x2f;
          }
          else {
            uVar7 = iStack_55404 - 0x41;
            if (uVar7 < 10) {
              iStack_55404 = 0;
              local_54[uVar7] = (int)pcVar5;
              iStack_553a4 = iVar3 + -0x40;
            }
            else {
              Sys_Error("Bad animating texture %s");
            }
          }
          while (iVar9 = iVar9 + 1, iVar9 < *piVar8) {
            pcVar6 = *(char **)(*(int *)(loadmodel + 0x174) + iVar9 * 4);
            if (((pcVar6 != (char *)0x0) && ((*pcVar6 == '+' || (*pcVar6 == '-')))) &&
               (iVar3 = strcmp(pcVar6 + 2,pcVar5 + 2), iVar3 == 0)) {
              iVar3 = (int)pcVar6[1];
              if (iVar3 - 0x61U < 0x1a) {
                iVar3 = iVar3 + -0x20;
              }
              if (iVar3 - 0x30U < 10) {
                local_2c[iVar3 - 0x30U] = (int)pcVar6;
                if (iStack_55404 < iVar3 + -0x2f) {
                  iStack_55404 = iVar3 + -0x2f;
                }
              }
              else if (iVar3 - 0x41U < 10) {
                local_54[iVar3 - 0x41U] = (int)pcVar6;
                if (iStack_553a4 < iVar3 + -0x40) {
                  iStack_553a4 = iVar3 + -0x40;
                }
              }
              else {
                Sys_Error("Bad animating texture %s");
              }
            }
          }
          if (0 < iStack_55404) {
            iVar3 = 0;
            do {
              iVar9 = local_2c[iVar3];
              if (iVar9 == 0) {
                Sys_Error("Missing frame %i of %s",iVar3);
              }
              *(int *)(iVar9 + 0x18) = iStack_55404;
              *(int *)(iVar9 + 0x1c) = iVar3;
              *(int *)(iVar9 + 0x20) = iVar3 + 1;
              *(int *)(iVar9 + 0x24) = local_2c[(iVar3 + 1) % iStack_55404];
              if (iStack_553a4 != 0) {
                *(int *)(iVar9 + 0x28) = local_54[0];
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < iStack_55404);
          }
          iVar3 = 0;
          if (0 < iStack_553a4) {
            do {
              iVar9 = local_54[iVar3];
              if (iVar9 == 0) {
                Sys_Error("Missing frame %i of %s",iVar3);
              }
              *(int *)(iVar9 + 0x18) = iStack_553a4;
              *(int *)(iVar9 + 0x1c) = iVar3;
              *(int *)(iVar9 + 0x20) = iVar3 + 1;
              *(int *)(iVar9 + 0x24) = local_54[(iVar3 + 1) % iStack_553a4];
              if (iStack_55404 != 0) {
                *(int *)(iVar9 + 0x28) = local_2c[0];
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < iStack_553a4);
          }
        }
        iStack_5539c = iStack_5539c + 1;
      } while (iStack_5539c < *piVar8);
    }
    lVar12 = (longdouble)Sys_FloatTime();
    Con_DPrintf("Texture load: %6.1fms\n",
                (double)((longdouble)1000.0 * (lVar12 - (longdouble)(double)lVar11)));
  }
  return;
}


// Mod_LoadVertexes  @ 08063350
void Mod_LoadVertexes(int *param_1)

{
  float *pfVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  longdouble lVar5;
  
  puVar4 = (undefined4 *)(*param_1 + mod_base);
  if (param_1[1] != ((uint)param_1[1] / 0xc) * 0xc) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar2 = (uint)param_1[1] / 0xc;
  pfVar1 = (float *)Hunk_AllocName(uVar2 * 0xc,loadname);
  iVar3 = loadmodel;
  *(float **)(loadmodel + 0x94) = pfVar1;
  *(uint *)(iVar3 + 0x90) = uVar2;
  iVar3 = 0;
  if (uVar2 != 0) {
    do {
      lVar5 = (longdouble)(*LittleFloat)(*puVar4);
      *pfVar1 = (float)lVar5;
      lVar5 = (longdouble)(*LittleFloat)(puVar4[1]);
      pfVar1[1] = (float)lVar5;
      lVar5 = (longdouble)(*LittleFloat)(puVar4[2]);
      pfVar1[2] = (float)lVar5;
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 3;
      pfVar1 = pfVar1 + 3;
    } while (iVar3 < (int)uVar2);
  }
  return;
}


// Mod_LoadVisibility  @ 08063200
void Mod_LoadVisibility(int *param_1)

{
  void *__dest;
  
  if (param_1[1] == 0) {
    *(undefined4 *)(loadmodel + 0x178) = 0;
  }
  else {
    __dest = (void *)Hunk_AllocName(param_1[1],loadname);
    *(void **)(loadmodel + 0x178) = __dest;
    memcpy(__dest,(void *)(*param_1 + mod_base),param_1[1]);
  }
  return;
}


// Mod_MakeHull0  @ 080642c0
void Mod_MakeHull0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int *local_18;
  int local_8;
  
  iVar3 = loadmodel;
  local_8 = *(int *)(loadmodel + 0xa4);
  iVar1 = *(int *)(loadmodel + 0xa0);
  local_18 = (int *)Hunk_AllocName(iVar1 * 8,loadname);
  *(int **)(iVar3 + 0xd0) = local_18;
  *(undefined4 *)(iVar3 + 0xd8) = 0;
  *(int *)(iVar3 + 0xdc) = iVar1 + -1;
  *(undefined4 *)(iVar3 + 0xd4) = *(undefined4 *)(loadmodel + 0x84);
  iVar3 = loadmodel;
  iVar6 = 0;
  if (0 < iVar1) {
    do {
      *local_18 = (*(int *)(local_8 + 0x18) - *(int *)(iVar3 + 0x84)) * -0x33333333 >> 2;
      iVar5 = 0;
      do {
        piVar2 = *(int **)(local_8 + 0x1c + iVar5 * 4);
        if (*piVar2 < 0) {
          uVar4 = (undefined2)*piVar2;
        }
        else {
          uVar4 = (undefined2)(((int)piVar2 - *(int *)(iVar3 + 0xa4)) * -0x33333333 >> 3);
        }
        *(undefined2 *)((int)local_18 + iVar5 * 2 + 4) = uVar4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      iVar6 = iVar6 + 1;
      local_18 = local_18 + 2;
      local_8 = local_8 + 0x28;
    } while (iVar6 < iVar1);
  }
  return;
}


// Mod_MarkClient  @ 08062a00
void Mod_MarkClient(int param_1)

{
  *(undefined4 *)(param_1 + 0x40) = 3;
  return;
}


// Mod_PointInLeaf  @ 080626c0
int * Mod_PointInLeaf(float *param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  int *piVar3;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 0xa4) == 0)) {
    Sys_Error("Mod_PointInLeaf: bad model");
  }
  piVar3 = *(int **)(param_2 + 0xa4);
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


// Mod_Print  @ 08065680
void Mod_Print(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  Con_Printf("Cached models:\n");
  puVar1 = mod_known;
  if (0 < mod_numknown) {
    iVar2 = 0;
    do {
      Con_Printf("%8p : %s",*(undefined4 *)(puVar1 + 0x184),puVar1);
      if ((puVar1[0x40] & 2) != 0) {
        Con_Printf(" (!R)");
      }
      if ((puVar1[0x40] & 1) != 0) {
        Con_Printf(" (!P)");
      }
      Con_Printf(&DAT_080a2613);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x188;
    } while (iVar2 < mod_numknown);
  }
  return;
}


// Mod_SetParent  @ 08063d40
void Mod_SetParent(int *param_1,int param_2)

{
  param_1[5] = param_2;
  if (-1 < *param_1) {
    Mod_SetParent(param_1[7],param_1);
    Mod_SetParent(param_1[8],param_1);
  }
  return;
}


// Mod_TouchModel  @ 08062880
void Mod_TouchModel(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Mod_FindName(param_1);
  if ((*(int *)(iVar1 + 0x40) == 0) && (*(int *)(iVar1 + 0x44) - 2U < 2)) {
    Cache_Check(iVar1 + 0x184);
  }
  return;
}


// Mod_UnloadSpriteTextures  @ 08065660
void Mod_UnloadSpriteTextures(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x44) == 1)) {
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  return;
}


