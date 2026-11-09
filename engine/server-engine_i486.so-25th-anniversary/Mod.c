// Mod_AdInit  @ 000617c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_AdInit(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * s@[???] */
  tested = 1;
  iVar2 = COM_CheckParm("-ad");
  if (((iVar2 != 0) && (pcVar1 = com_argv[iVar2 + 1], pcVar1 != (char *)0x0)) && (*pcVar1 != '\0'))
  {
    snprintf(Mod_AdInit::filename,0x104,"%s",pcVar1);
    uVar3 = FS_FileSize(Mod_AdInit::filename);
    if (0 < (int)uVar3) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * s@[???] */
      Draw_CacheWadInit(Mod_AdInit::filename,0x10,&ad_wad);
      ad_enabled = 1;
      return;
    }
    Con_Printf("No -ad file specified, skipping\n");
  }
  return;
}


// Mod_AdSwap  @ 00061870
void Mod_AdSwap(texture_t *src,int pixels,int entries)

{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  char *pcVar4;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: uchar[3] * mippal@[???]
                       Unresolved local var: ushort[4] * texpal@[???]
                       Unresolved local var: texture_t * tex@[???] */
  if (tested != 0) {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: uchar[3] * mippal@[???]
                       Unresolved local var: ushort[4] * texpal@[???]
                       Unresolved local var: texture_t * tex@[???] */
    iVar1 = Draw_CacheIndex(&ad_wad,"img");
    pvVar2 = Draw_CacheGet(&ad_wad,iVar1);
    if (pvVar2 != (void *)0x0) {
      Q_memcpy(src + 1,(void *)((int)pvVar2 + 0x40),pixels);
      if (0 < entries) {
        iVar1 = (int)pvVar2 + pixels;
        pcVar3 = src->name + pixels;
        do {
          *(undefined2 *)(pcVar3 + 0x48) = 0;
          pcVar4 = pcVar3 + 8;
          *(ushort *)(pcVar3 + 0x46) = (ushort)*(byte *)(iVar1 + 0x42);
          *(ushort *)(pcVar3 + 0x44) = (ushort)*(byte *)(iVar1 + 0x43);
          *(ushort *)(pcVar3 + 0x42) = (ushort)*(byte *)(iVar1 + 0x44);
          iVar1 = iVar1 + 3;
          pcVar3 = pcVar4;
        } while (pcVar4 != src->name + pixels + entries * 8);
        return;
      }
    }
  }
  return;
}


// Mod_ChangeGame  @ 00066200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_ChangeGame(void)

{
  int iVar1;
  void *pvVar2;
  qboolean *pqVar3;
  cache_user_t *c;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  if (0 < mod_numknown) {
    iVar4 = 0;
    c = &mod_known[0].cache;
    iVar1 = mod_numknown;
    pqVar3 = &mod_known_info[0].firstCRCDone;
    do {
      if ((*(modtype_t *)(c + -0x50) == mod_studio) &&
         (pvVar2 = Cache_Check(c), iVar1 = mod_numknown, pvVar2 != (void *)0x0)) {
        Cache_Free(c);
        iVar1 = mod_numknown;
      }
      iVar4 = iVar4 + 1;
      *pqVar3 = false;
      c = c + 0x62;
      pqVar3[1] = 0;
      pqVar3 = pqVar3 + 3;
    } while (iVar4 < iVar1);
  }
  return;
}


// Mod_ClearAll  @ 000614f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_ClearAll(void)

{
  int iVar1;
  model_t *pmVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???] */
  iVar1 = mod_numknown;
  iVar3 = 0;
  pmVar2 = mod_known;
  if (0 < mod_numknown) {
    do {
      while ((pmVar2->needload == 3 || (pmVar2->needload = 2, pmVar2->type != mod_sprite))) {
        iVar3 = iVar3 + 1;
        pmVar2 = pmVar2 + 1;
        if (iVar3 == iVar1) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      (pmVar2->cache).data = (void *)0x0;
      pmVar2 = pmVar2 + 1;
    } while (iVar3 != iVar1);
  }
  return;
}


// Mod_DecompressVis  @ 00038830
byte * Mod_DecompressVis(byte *in,model_t *model)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
                    /* Unresolved local var: int row@[???] */
  iVar3 = model->numleafs;
  if (in != (byte *)0x0) {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: byte * out@[???] */
    pbVar4 = Mod_DecompressVis::decompressed;
    do {
      if (*in == '\0') {
        pbVar1 = in + 1;
        uVar5 = (uint)*pbVar1;
        in = in + 2;
        if (*pbVar1 != 0) {
          pbVar6 = pbVar4;
          uVar7 = uVar5;
          if (7 < uVar5) {
            if (((uint)pbVar4 & 1) != 0) {
              *pbVar4 = '\0';
              pbVar6 = pbVar4 + 1;
              uVar7 = uVar5 - 1;
            }
            if (((uint)pbVar6 & 2) != 0) {
              pbVar6[0] = '\0';
              pbVar6[1] = '\0';
              uVar7 = uVar7 - 2;
              pbVar6 = pbVar6 + 2;
            }
            if (7 < uVar7) {
              uVar8 = 0;
              do {
                pbVar2 = pbVar6 + uVar8;
                pbVar2[0] = '\0';
                pbVar2[1] = '\0';
                pbVar2[2] = '\0';
                pbVar2[3] = '\0';
                pbVar2 = pbVar6 + uVar8 + 4;
                pbVar2[0] = '\0';
                pbVar2[1] = '\0';
                pbVar2[2] = '\0';
                pbVar2[3] = '\0';
                uVar8 = uVar8 + 8;
              } while (uVar8 < (uVar7 & 0xfffffff8));
              pbVar6 = pbVar6 + uVar8;
            }
          }
          if ((uVar7 & 4) != 0) {
            pbVar6[0] = '\0';
            pbVar6[1] = '\0';
            pbVar6[2] = '\0';
            pbVar6[3] = '\0';
            pbVar6 = pbVar6 + 4;
          }
          if ((uVar7 & 2) != 0) {
            pbVar6[0] = '\0';
            pbVar6[1] = '\0';
            pbVar6 = pbVar6 + 2;
          }
          if ((uVar7 & 1) != 0) {
            *pbVar6 = '\0';
          }
          pbVar4 = pbVar4 + uVar5;
        }
      }
      else {
        *pbVar4 = *in;
        in = in + 1;
        pbVar4 = pbVar4 + 1;
      }
    } while (pbVar4 < Mod_DecompressVis::decompressed + (iVar3 + 7 >> 3));
    return Mod_DecompressVis::decompressed;
  }
  return mod_novis;
}


// Mod_Extradata  @ 00066050
void * Mod_Extradata(model_t *mod)

{
  void *pvVar1;
  modtype_t mVar2;
  
                    /* Unresolved local var: void * r@[???] */
  if (mod == (model_t *)0x0) {
    return (void *)0x0;
  }
  if ((mod->type == mod_sprite) && (pvVar1 = (mod->cache).data, pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  pvVar1 = Cache_Check(&mod->cache);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
  mVar2 = mod->type;
  if (mVar2 == mod_brush) {
    Sys_Error("Mod_ExtraData called with mod_brush!\n");
    mVar2 = mod->type;
  }
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[260] tmpName@[???] */
  if (mVar2 - mod_alias < 2) {
    pvVar1 = Cache_Check(&mod->cache);
    if (pvVar1 != (void *)0x0) {
      mod->needload = false;
      goto LAB_000660d9;
    }
  }
  else if ((mod->needload == false) || (mod->needload == 3)) goto LAB_000660d9;
  Mod_LoadModel(mod,true,false);
LAB_000660d9:
  pvVar1 = (mod->cache).data;
  if (pvVar1 == (void *)0x0) {
    Sys_Error("Mod_Extradata: caching failed");
    pvVar1 = (mod->cache).data;
  }
  return pvVar1;
}


// Mod_FillInCRCInfo  @ 00061540
void Mod_FillInCRCInfo(qboolean trackCRC,int model_number)

{
                    /* Unresolved local var: mod_known_info_t * p@[???] */
  mod_known_info[model_number].shouldCRC = trackCRC;
  mod_known_info[model_number].firstCRCDone = false;
  mod_known_info[model_number].initialCRC = 0;
  return;
}


// Mod_FindName  @ 00061570
model_t * Mod_FindName(qboolean trackCRC,char *name)

{
  qboolean qVar1;
  model_t *pmVar2;
  int iVar3;
  int iVar4;
  model_t *dest;
  model_t *pmVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???]
                       Unresolved local var: model_t * avail@[???] */
  if (*name == '\0') {
    Sys_Error("Mod_ForName: NULL name");
  }
  if (mod_numknown < 1) {
    if (mod_numknown != 0) {
      return mod_known;
    }
    mod_numknown = 1;
    dest = mod_known;
    iVar4 = 0;
  }
  else {
    pmVar5 = (model_t *)0x0;
    pmVar2 = mod_known;
    iVar3 = 0;
    do {
      while( true ) {
        iVar4 = iVar3;
        dest = pmVar2;
        iVar3 = Q_strcasecmp(dest,name);
        if (iVar3 == 0) goto joined_r0x00061607;
        pmVar2 = pmVar5;
        if ((dest->needload == 2) && (pmVar2 = dest, pmVar5 != (model_t *)0x0)) break;
        pmVar5 = pmVar2;
        pmVar2 = dest + 1;
        iVar3 = iVar4 + 1;
        if (mod_numknown <= iVar4 + 1) goto LAB_000615ea;
      }
      if (1 < dest->type - mod_alias) {
        pmVar5 = dest;
      }
      pmVar2 = dest + 1;
      iVar3 = iVar4 + 1;
    } while (iVar4 + 1 < mod_numknown);
LAB_000615ea:
    iVar4 = iVar4 + 1;
    dest = dest + 1;
joined_r0x00061607:
    if (iVar4 != mod_numknown) {
      return dest;
    }
    if (0x3ff < iVar4) {
      if (pmVar5 == (model_t *)0x0) {
        Sys_Error("mod_numknown >= MAX_KNOWN_MODELS");
      }
      else {
                    /* Unresolved local var: mod_known_info_t * p@[???] */
        iVar4 = ((int)(pmVar5[-0x1ecd].hulls[0].clip_mins + 2) >> 3) * 0x397829cc;
        *(qboolean *)((int)mod_known_info + iVar4) = trackCRC;
        *(undefined4 *)((int)mod_known_info + iVar4 + 4) = 0;
        *(undefined4 *)((int)mod_known_info + iVar4 + 8) = 0;
        dest = pmVar5;
      }
      goto LAB_0006164f;
    }
    mod_numknown = iVar4 + 1;
  }
                    /* Unresolved local var: mod_known_info_t * p@[???] */
  mod_known_info[iVar4].firstCRCDone = false;
  mod_known_info[iVar4].shouldCRC = trackCRC;
  mod_known_info[iVar4].initialCRC = 0;
LAB_0006164f:
  Q_strncpy(dest->name,name,0x3f);
  qVar1 = dest->needload;
  dest->name[0x3f] = '\0';
  if (qVar1 == 3) {
    return dest;
  }
  dest->needload = true;
  return dest;
}


// Mod_ForName  @ 00065fc0
model_t * Mod_ForName(char *name,qboolean crash,qboolean trackCRC)

{
  model_t *pmVar1;
  void *pvVar2;
  
                    /* Unresolved local var: model_t * mod@[???]
                       Unresolved local var: model_t * mreturn@[???] */
  pmVar1 = Mod_FindName(trackCRC,name);
  if (pmVar1 == (model_t *)0x0) {
    return (model_t *)0x0;
  }
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[260] tmpName@[???] */
  if (pmVar1->type - mod_alias < 2) {
    pvVar2 = Cache_Check(&pmVar1->cache);
    if (pvVar2 != (void *)0x0) {
      pmVar1->needload = false;
      return pmVar1;
    }
  }
  else {
    if (pmVar1->needload == false) {
      return pmVar1;
    }
    if (pmVar1->needload == 3) {
      return pmVar1;
    }
  }
  pmVar1 = Mod_LoadModel(pmVar1,crash,trackCRC);
  return pmVar1;
}


// Mod_Init  @ 00038800
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_Init(void)

{
  SW_Mod_Init();
  Q_memset(mod_novis,0xff,0x400);
  return;
}


// Mod_LeafPVS  @ 00038930
byte * Mod_LeafPVS(mleaf_t *leaf,model_t *model)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  
  if (model->leafs != leaf) {
    if (gPVS != (byte *)0x0) {
                    /* Unresolved local var: int leafnum@[???] */
      return gPVS + ((int)leaf - (int)model->leafs >> 4) * -0x55555555 * gPVSRowBytes;
    }
    pbVar6 = leaf->compressed_vis;
                    /* Unresolved local var: int row@[???] */
    if (pbVar6 != (byte *)0x0) {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: byte * out@[???] */
      iVar3 = model->numleafs;
      pbVar4 = Mod_DecompressVis::decompressed;
      do {
        if (*pbVar6 == '\0') {
          pbVar1 = pbVar6 + 1;
          uVar5 = (uint)*pbVar1;
          pbVar6 = pbVar6 + 2;
          if (*pbVar1 != 0) {
            pbVar7 = pbVar4;
            uVar8 = uVar5;
            if (7 < uVar5) {
              if (((uint)pbVar4 & 1) != 0) {
                *pbVar4 = '\0';
                pbVar7 = pbVar4 + 1;
                uVar8 = uVar5 - 1;
              }
              if (((uint)pbVar7 & 2) != 0) {
                pbVar7[0] = '\0';
                pbVar7[1] = '\0';
                uVar8 = uVar8 - 2;
                pbVar7 = pbVar7 + 2;
              }
              if (7 < uVar8) {
                uVar9 = 0;
                do {
                  pbVar2 = pbVar7 + uVar9;
                  pbVar2[0] = '\0';
                  pbVar2[1] = '\0';
                  pbVar2[2] = '\0';
                  pbVar2[3] = '\0';
                  pbVar2 = pbVar7 + uVar9 + 4;
                  pbVar2[0] = '\0';
                  pbVar2[1] = '\0';
                  pbVar2[2] = '\0';
                  pbVar2[3] = '\0';
                  uVar9 = uVar9 + 8;
                } while (uVar9 < (uVar8 & 0xfffffff8));
                pbVar7 = pbVar7 + uVar9;
              }
            }
            if ((uVar8 & 4) != 0) {
              pbVar7[0] = '\0';
              pbVar7[1] = '\0';
              pbVar7[2] = '\0';
              pbVar7[3] = '\0';
              pbVar7 = pbVar7 + 4;
            }
            if ((uVar8 & 2) != 0) {
              pbVar7[0] = '\0';
              pbVar7[1] = '\0';
              pbVar7 = pbVar7 + 2;
            }
            if ((uVar8 & 1) != 0) {
              *pbVar7 = '\0';
            }
            pbVar4 = pbVar4 + uVar5;
          }
        }
        else {
          *pbVar4 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          pbVar4 = pbVar4 + 1;
        }
      } while (pbVar4 < Mod_DecompressVis::decompressed + (iVar3 + 7 >> 3));
      return Mod_DecompressVis::decompressed;
    }
  }
  return mod_novis;
}


// Mod_LoadAliasFrame  @ 00064be0
void * Mod_LoadAliasFrame(void *pin,int *pframeindex,int numv,trivertx_t *pbboxmin,
                         trivertx_t *pbboxmax,aliashdr_t *pheader,char *name)

{
  int size;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
                    /* Unresolved local var: trivertx_t * pframe@[???]
                       Unresolved local var: trivertx_t * pinframe@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: daliasframe_t * pdaliasframe@[???] */
  Q_strcpy(name,(char *)((int)pin + 8));
  pbboxmin->v[0] = *(byte *)pin;
  pbboxmax->v[0] = *(byte *)((int)pin + 4);
  pbboxmin->v[1] = *(byte *)((int)pin + 1);
  pbboxmax->v[1] = *(byte *)((int)pin + 5);
  pbboxmin->v[2] = *(byte *)((int)pin + 2);
  pbboxmax->v[2] = *(byte *)((int)pin + 6);
  size = numv * 4;
  puVar1 = Hunk_AllocName(size,loadname);
  *pframeindex = (int)puVar1 - (int)pheader;
  if (0 < numv) {
    puVar2 = puVar1;
    puVar4 = (undefined1 *)((int)pin + 0x1b);
    do {
                    /* Unresolved local var: int k@[???] */
      puVar3 = puVar2 + 4;
      puVar2[3] = *puVar4;
      *puVar2 = puVar4[-3];
      puVar2[1] = puVar4[-2];
      puVar2[2] = puVar4[-1];
      puVar2 = puVar3;
      puVar4 = puVar4 + 4;
    } while (puVar1 + size != puVar3);
  }
  return (void *)((int)pin + size + 0x18);
}


// Mod_LoadAliasGroup  @ 00064ca0
void * Mod_LoadAliasGroup(void *pin,int *pframeindex,int numv,trivertx_t *pbboxmin,
                         trivertx_t *pbboxmax,aliashdr_t *pheader,char *name)

{
  int size;
  int32 iVar1;
  int32 *piVar2;
  void *pvVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *src;
  longdouble lVar10;
  void *local_2c;
  
                    /* Unresolved local var: daliasgroup_t * pingroup@[???]
                       Unresolved local var: maliasgroup_t * paliasgroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: daliasinterval_t * pin_intervals@[???]
                       Unresolved local var: float * poutintervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  iVar1 = (*LittleLong)(*(int32 *)pin);
  piVar2 = Hunk_AllocName((iVar1 * 3 + -3) * 4 + 0x14,loadname);
  *piVar2 = iVar1;
  pbboxmin->v[0] = *(byte *)((int)pin + 4);
  pbboxmax->v[0] = *(byte *)((int)pin + 8);
  pbboxmin->v[1] = *(byte *)((int)pin + 5);
  pbboxmax->v[1] = *(byte *)((int)pin + 9);
  pbboxmin->v[2] = *(byte *)((int)pin + 6);
  pbboxmax->v[2] = *(byte *)((int)pin + 10);
  *pframeindex = (int)piVar2 - (int)pheader;
  local_2c = (void *)((int)pin + 0xc);
  size = iVar1 * 4;
  pvVar3 = Hunk_AllocName(size,loadname);
  piVar2[1] = (int)pvVar3 - (int)pheader;
  if (0 < iVar1) {
    iVar9 = 0;
    do {
      while( true ) {
        lVar10 = (longdouble)(*LittleFloat)(*(float *)((int)pin + iVar9 * 4 + 0xc));
        *(float *)((int)pvVar3 + iVar9 * 4) = (float)lVar10;
        if ((longdouble)0 < lVar10) break;
        iVar9 = iVar9 + 1;
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
        if (iVar1 == iVar9) goto LAB_00064d90;
      }
      iVar9 = iVar9 + 1;
    } while (iVar1 != iVar9);
LAB_00064d90:
    src = (char *)((int)local_2c + size + 8);
    piVar2 = piVar2 + 2;
    iVar8 = 0;
    iVar9 = numv * 4;
    do {
                    /* Unresolved local var: trivertx_t * pframe@[???]
                       Unresolved local var: trivertx_t * pinframe@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: daliasframe_t * pdaliasframe@[???] */
      Q_strcpy(name,src);
      *(char *)piVar2 = src[-8];
      *(char *)(piVar2 + 1) = src[-4];
      *(char *)((int)piVar2 + 1) = src[-7];
      *(char *)((int)piVar2 + 5) = src[-3];
      *(char *)((int)piVar2 + 2) = src[-6];
      *(char *)((int)piVar2 + 6) = src[-2];
      pcVar4 = Hunk_AllocName(iVar9,loadname);
      piVar2[2] = (int)pcVar4 - (int)pheader;
      if (0 < numv) {
        pcVar5 = pcVar4;
        pcVar7 = src + 0x13;
        do {
                    /* Unresolved local var: int k@[???] */
          pcVar6 = pcVar5 + 4;
          pcVar5[3] = *pcVar7;
          *pcVar5 = pcVar7[-3];
          pcVar5[1] = pcVar7[-2];
          pcVar5[2] = pcVar7[-1];
          pcVar5 = pcVar6;
          pcVar7 = pcVar7 + 4;
        } while (pcVar4 + iVar9 != pcVar6);
      }
      iVar8 = iVar8 + 1;
      piVar2 = piVar2 + 3;
      src = src + iVar9 + 0x18;
    } while (iVar1 != iVar8);
    local_2c = (void *)((int)local_2c + iVar1 * (iVar9 + 0x18) + size);
  }
  return local_2c;
}


// Mod_LoadAliasModel  @ 000650b0
void Mod_LoadAliasModel(model_t *mod,void *buffer)

{
  byte bVar1;
  int iVar2;
  int mark;
  int32 iVar3;
  int32 iVar4;
  int32 iVar5;
  aliashdr_t *pheader;
  aliasframetype_t aVar6;
  trivertx_t tVar7;
  synctype_t sVar8;
  int iVar9;
  void *pvVar10;
  ushort *puVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  ushort *puVar15;
  float *pfVar16;
  float *pfVar17;
  int32 *piVar18;
  int iVar19;
  int *piVar20;
  int iVar21;
  int32 *piVar22;
  char *name;
  trivertx_t *ptVar23;
  int *piVar24;
  int32 *piVar25;
  longdouble lVar26;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mdl_t * pmodel@[???]
                       Unresolved local var: mdl_t * pinmodel@[???]
                       Unresolved local var: stvert_t * pstverts@[???]
                       Unresolved local var: stvert_t * pinstverts@[???]
                       Unresolved local var: aliashdr_t * pheader@[???]
                       Unresolved local var: mtriangle_t * ptri@[???]
                       Unresolved local var: dtriangle_t * pintriangles@[???]
                       Unresolved local var: int version@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: int numskins@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: daliasframetype_t * pframetype@[???]
                       Unresolved local var: daliasskintype_t * pskintype@[???]
                       Unresolved local var: maliasskindesc_t * pskindesc@[???]
                       Unresolved local var: int skinsize@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???]
                       Unresolved local var: int total@[???] */
  mark = Hunk_LowMark();
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar3 != 6) {
    Sys_Error("Mod_LoadAliasModel: Model %s has wrong version number (%i should be %i)",mod,iVar3,6)
    ;
  }
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x3c));
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x40));
  pheader = Hunk_AllocName(iVar5 * 0x10 + 0x88 + iVar4 * 0xc + (iVar3 + -1) * 0x20,loadname);
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x4c));
  mod->flags = iVar4;
  lVar26 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  pheader[1].frames[iVar3 + -1].frame = (int)(float)lVar26;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x30));
  *(int32 *)(pheader[1].frames[iVar3 + -1].name + 0xc) = iVar4;
  aVar6 = (*LittleLong)(*(int32 *)((int)buffer + 0x34));
  pheader[1].frames[iVar3].type = aVar6;
  tVar7 = (trivertx_t)(*LittleLong)(*(int32 *)((int)buffer + 0x38));
  pheader[1].frames[iVar3].bboxmin = tVar7;
  if (0x1e0 < (int)tVar7) {
    Sys_Error("Mod_LoadAliasModel: Model %s has a skin taller than %d",mod,0x1e0);
  }
  tVar7 = (trivertx_t)(*LittleLong)(*(int32 *)((int)buffer + 0x3c));
  pheader[1].frames[iVar3].bboxmax = tVar7;
  if ((int)tVar7 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no vertices: %d",mod,tVar7);
    tVar7 = pheader[1].frames[iVar3].bboxmax;
  }
  if (2000 < (int)tVar7) {
    Sys_Error("Mod_LoadAliasModel: Model %s has too many vertices: %d",mod,tVar7);
  }
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x40));
  pheader[1].frames[iVar3].frame = iVar4;
  if (iVar4 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no triangles: %d",mod,iVar4);
  }
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  *(int32 *)pheader[1].frames[iVar3].name = iVar4;
  if (iVar4 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no frames: %d",mod,iVar4);
  }
  lVar26 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x50));
  *(float *)(pheader[1].frames[iVar3].name + 0xc) =
       (float)((longdouble)0.09090909090909091 * lVar26);
  sVar8 = (*LittleLong)(*(int32 *)((int)buffer + 0x48));
  mod->synctype = sVar8;
  mod->numframes = *(int *)pheader[1].frames[iVar3].name;
  pfVar16 = (float *)((int)buffer + 8);
  ptVar23 = &pheader->frames[iVar3].bboxmax;
  do {
    pfVar17 = pfVar16 + 1;
    lVar26 = (longdouble)(*LittleFloat)(*pfVar16);
    *ptVar23 = (trivertx_t)(float)lVar26;
    lVar26 = (longdouble)(*LittleFloat)(pfVar16[3]);
    ptVar23[3] = (trivertx_t)(float)lVar26;
    lVar26 = (longdouble)(*LittleFloat)(pfVar16[7]);
    ptVar23[7] = (trivertx_t)(float)lVar26;
    pfVar16 = pfVar17;
    ptVar23 = ptVar23 + 1;
  } while (pfVar17 != (float *)((int)buffer + 0x14));
  iVar19 = *(int *)(pheader[1].frames[iVar3 + -1].name + 0xc);
  iVar2 = *(int *)pheader[1].frames[iVar3].name;
  if ((pheader[1].frames[iVar3].type & 3) != ALIAS_SINGLE) {
    Sys_Error("Mod_LoadAliasModel: skinwidth not multiple of 4");
  }
  pheader->model = iVar3 * 0x20 + 0x14;
  iVar9 = (int)pheader[1].frames[iVar3].bboxmin * pheader[1].frames[iVar3].type;
  if (iVar19 < 1) {
    piVar18 = (int32 *)((int)buffer + 0x54);
    Sys_Error("Mod_LoadAliasModel: Invalid # of skins: %d\n",iVar19);
    pvVar10 = Hunk_AllocName(iVar19 * 0xc,loadname);
    pheader->skindesc = (int)pvVar10 - (int)pheader;
  }
  else {
    piVar18 = (int32 *)((int)buffer + 0x54);
    iVar21 = 0;
    pvVar10 = Hunk_AllocName(iVar19 * 0xc,loadname);
    pheader->skindesc = (int)pvVar10 - (int)pheader;
    piVar20 = (int *)((int)pvVar10 + 8);
    do {
                    /* Unresolved local var: aliasskintype_t skintype@[???] */
      piVar22 = piVar18 + 1;
      iVar4 = (*LittleLong)(*piVar18);
      piVar20[-2] = iVar4;
      if (iVar4 == 0) {
                    /* Unresolved local var: byte * pskin@[???]
                       Unresolved local var: byte * pinskin@[???]
                       Unresolved local var: ushort * pusskin@[DW_OP_reg0(EAX)] */
        pvVar10 = Hunk_AllocName(r_pixbytes * iVar9,loadname);
        *piVar20 = (int)pvVar10 - (int)pheader;
        if (r_pixbytes == 1) {
          Q_memcpy(pvVar10,piVar22,iVar9);
        }
        else if (r_pixbytes != 2) {
          Sys_Error("Mod_LoadAliasSkin: driver set invalid r_pixbytes: %d\n",r_pixbytes);
        }
        piVar18 = (int32 *)((int)piVar22 + iVar9);
      }
      else {
        piVar18 = Mod_LoadAliasSkinGroup(piVar22,piVar20,iVar9,pheader);
      }
      iVar21 = iVar21 + 1;
      piVar20 = piVar20 + 3;
    } while (iVar19 != iVar21);
  }
  piVar20 = &pheader[2].frames[iVar3 + -1].frame;
  pheader->stverts = (int)piVar20 - (int)pheader;
  tVar7 = pheader[1].frames[iVar3].bboxmax;
  if (0 < (int)tVar7) {
    iVar19 = 0;
    piVar22 = piVar18;
    piVar24 = piVar20;
    do {
      iVar19 = iVar19 + 1;
      iVar4 = (*LittleLong)(*piVar22);
      *piVar24 = iVar4;
      iVar4 = (*LittleLong)(piVar22[1]);
      piVar24[1] = iVar4 << 0x10;
      iVar4 = (*LittleLong)(piVar22[2]);
      piVar24[2] = iVar4 << 0x10;
      tVar7 = pheader[1].frames[iVar3].bboxmax;
      piVar22 = piVar22 + 3;
      piVar24 = piVar24 + 3;
    } while (iVar19 < (int)tVar7);
  }
  piVar18 = piVar18 + (int)tVar7 * 3;
  piVar20 = piVar20 + (int)tVar7 * 3;
  pheader->triangles = (int)piVar20 - (int)pheader;
  iVar19 = pheader[1].frames[iVar3].frame;
  if (0 < iVar19) {
    iVar9 = 0;
    piVar22 = piVar18;
    do {
                    /* Unresolved local var: int j@[???] */
      iVar19 = 0;
      iVar4 = (*LittleLong)(*piVar22);
      *piVar20 = iVar4;
      do {
        iVar4 = (*LittleLong)(piVar22[iVar19 + 1]);
        piVar20[iVar19 + 1] = iVar4;
        iVar19 = iVar19 + 1;
      } while (iVar19 != 3);
      iVar9 = iVar9 + 1;
      piVar22 = piVar22 + 4;
      piVar20 = piVar20 + 4;
      iVar19 = pheader[1].frames[iVar3].frame;
    } while (iVar9 < iVar19);
  }
  if (iVar2 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of frames: %d\n",iVar2);
    piVar18 = piVar18 + pheader[1].frames[iVar3].frame * 4;
  }
  else {
    piVar18 = piVar18 + iVar19 * 4;
    iVar19 = 0;
    name = pheader->frames[0].name;
    do {
      while( true ) {
                    /* Unresolved local var: aliasframetype_t frametype@[???] */
        aVar6 = (*LittleLong)(*piVar18);
        ((maliasframedesc_t *)(name + -0x10))->type = aVar6;
        if (aVar6 != ALIAS_SINGLE) break;
        tVar7 = pheader[1].frames[iVar3].bboxmax;
                    /* Unresolved local var: trivertx_t * pframe@[???]
                       Unresolved local var: trivertx_t * pinframe@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: daliasframe_t * pdaliasframe@[???] */
        Q_strcpy(name,(char *)(piVar18 + 3));
        ((trivertx_t *)(name + -0xc))->v[0] = (byte)piVar18[1];
        ((trivertx_t *)(name + -8))->v[0] = (byte)piVar18[2];
        name[-0xb] = *(byte *)((int)piVar18 + 5);
        name[-7] = *(byte *)((int)piVar18 + 9);
        name[-10] = *(byte *)((int)piVar18 + 6);
        name[-6] = *(byte *)((int)piVar18 + 10);
        piVar18 = piVar18 + 7;
        pvVar10 = Hunk_AllocName((int)tVar7 * 4,loadname);
        *(int *)(name + -4) = (int)pvVar10 - (int)pheader;
        if (0 < (int)tVar7) {
          puVar12 = (undefined1 *)((int)pvVar10 + 3);
          piVar22 = piVar18;
          do {
                    /* Unresolved local var: int k@[???] */
            piVar25 = piVar22 + 1;
            *puVar12 = *(undefined1 *)((int)piVar22 + 3);
            puVar12[-3] = (char)*piVar22;
            puVar12[-2] = *(undefined1 *)((int)piVar22 + 1);
            puVar12[-1] = *(undefined1 *)((int)piVar22 + 2);
            puVar12 = puVar12 + 4;
            piVar22 = piVar25;
          } while (piVar25 != piVar18 + (int)tVar7);
        }
        piVar18 = piVar18 + (int)tVar7;
        iVar19 = iVar19 + 1;
        name = name + 0x20;
        if (iVar2 == iVar19) goto LAB_00065558;
      }
      iVar19 = iVar19 + 1;
      piVar18 = Mod_LoadAliasGroup(piVar18 + 1,(int *)(name + -4),
                                   (int)pheader[1].frames[iVar3].bboxmax,(trivertx_t *)(name + -0xc)
                                   ,(trivertx_t *)(name + -8),pheader,name);
      name = name + 0x20;
    } while (iVar2 != iVar19);
  }
LAB_00065558:
                    /* Unresolved local var: ushort * pPal@[???]
                       Unresolved local var: uchar * pPalSrc@[???] */
  mod->type = mod_alias;
  mod->mins[2] = -16.0;
  mod->mins[1] = -16.0;
  mod->mins[0] = -16.0;
  mod->maxs[2] = 16.0;
  mod->maxs[1] = 16.0;
  mod->maxs[0] = 16.0;
  puVar11 = Hunk_AllocName(0x800,loadname);
  pbVar13 = (byte *)((int)piVar18 + 2);
  puVar15 = puVar11;
  do {
    pbVar14 = pbVar13 + 3;
    *puVar15 = (ushort)*pbVar13;
    puVar15[1] = (ushort)pbVar13[-1];
    bVar1 = pbVar13[-2];
    puVar15[3] = 0;
    puVar15[2] = (ushort)bVar1;
    pbVar13 = pbVar14;
    puVar15 = puVar15 + 4;
  } while (pbVar14 != (byte *)((int)piVar18 + 0x302));
  pheader->palette = (int)puVar11 - (int)pheader;
  iVar19 = Hunk_LowMark();
  Cache_Alloc(&mod->cache,iVar19 - mark,loadname);
  pvVar10 = (mod->cache).data;
  if (pvVar10 == (void *)0x0) {
    return;
  }
  Q_memcpy(pvVar10,pheader,iVar19 - mark);
  Hunk_FreeToLowMark(mark);
  return;
}


// Mod_LoadAliasSkin  @ 00064ea0
void * Mod_LoadAliasSkin(void *pin,int *pskinindex,int skinsize,aliashdr_t *pheader)

{
  void *dest;
  
                    /* Unresolved local var: byte * pskin@[???]
                       Unresolved local var: byte * pinskin@[???]
                       Unresolved local var: ushort * pusskin@[DW_OP_reg0(EAX)] */
  dest = Hunk_AllocName(r_pixbytes * skinsize,loadname);
  *pskinindex = (int)dest - (int)pheader;
  if (r_pixbytes == 1) {
    Q_memcpy(dest,pin,skinsize);
  }
  else if (r_pixbytes != 2) {
    Sys_Error("Mod_LoadAliasSkin: driver set invalid r_pixbytes: %d\n",r_pixbytes);
  }
  return (void *)((int)pin + skinsize);
}


// Mod_LoadAliasSkinGroup  @ 00064f20
void * Mod_LoadAliasSkinGroup(void *pin,int *pskinindex,int skinsize,aliashdr_t *pheader)

{
  int32 iVar1;
  int32 *piVar2;
  void *pvVar3;
  void *dest;
  int iVar4;
  longdouble lVar5;
  void *local_28;
  
                    /* Unresolved local var: daliasskingroup_t * pinskingroup@[???]
                       Unresolved local var: maliasskingroup_t * paliasskingroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numskins@[???]
                       Unresolved local var: daliasskininterval_t * pinskinintervals@[???]
                       Unresolved local var: float * poutskinintervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  iVar1 = (*LittleLong)(*(int32 *)pin);
  piVar2 = Hunk_AllocName((iVar1 * 3 + -3) * 4 + 0x14,loadname);
  *piVar2 = iVar1;
  *pskinindex = (int)piVar2 - (int)pheader;
  local_28 = (void *)((int)pin + 4);
  pvVar3 = Hunk_AllocName(iVar1 * 4,loadname);
  piVar2[1] = (int)pvVar3 - (int)pheader;
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      while( true ) {
        lVar5 = (longdouble)(*LittleFloat)(*(float *)((int)pin + iVar4 * 4 + 4));
        *(float *)((int)pvVar3 + iVar4 * 4) = (float)lVar5;
        if ((longdouble)0 < lVar5) break;
        iVar4 = iVar4 + 1;
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
        if (iVar1 == iVar4) goto LAB_00064ff0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
LAB_00064ff0:
    iVar4 = 0;
    local_28 = (void *)((int)local_28 + iVar1 * 4);
    piVar2 = piVar2 + 4;
    pvVar3 = local_28;
    do {
      while( true ) {
        dest = Hunk_AllocName(r_pixbytes * skinsize,loadname);
        *piVar2 = (int)dest - (int)pheader;
        if (r_pixbytes != 1) break;
        iVar4 = iVar4 + 1;
        piVar2 = piVar2 + 3;
        Q_memcpy(dest,pvVar3,skinsize);
        pvVar3 = (void *)((int)pvVar3 + skinsize);
        if (iVar1 == iVar4) goto LAB_00065090;
      }
                    /* Unresolved local var: byte * pskin@[???]
                       Unresolved local var: byte * pinskin@[???]
                       Unresolved local var: ushort * pusskin@[DW_OP_reg0(EAX)] */
      if (r_pixbytes != 2) {
        Sys_Error("Mod_LoadAliasSkin: driver set invalid r_pixbytes: %d\n",r_pixbytes);
      }
      iVar4 = iVar4 + 1;
      pvVar3 = (void *)((int)pvVar3 + skinsize);
      piVar2 = piVar2 + 3;
    } while (iVar1 != iVar4);
LAB_00065090:
    local_28 = (void *)(iVar1 * skinsize + (int)local_28);
  }
  return local_28;
}


// Mod_LoadBrushModel  @ 00064480
void Mod_LoadBrushModel(model_t *mod,void *buffer)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  bool bVar4;
  byte *pbVar5;
  model_t *pmVar6;
  int32 iVar7;
  int *piVar8;
  int iVar9;
  dclipnode_t *pdVar10;
  int iVar11;
  int iVar12;
  model_t *pmVar13;
  byte *pbVar14;
  color24 *pcVar15;
  mnode_s *pmVar16;
  uint uVar17;
  int iVar18;
  int32 *piVar19;
  int32 *piVar20;
  uint uVar21;
  mnode_t *pmVar22;
  dmodel_t *pdVar23;
  int in_GS_OFFSET;
  float fVar24;
  float local_38;
  float local_34;
  float local_30;
  char local_2a [10];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: dheader_t * header@[???]
                       Unresolved local var: dmodel_t * bm@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  loadmodel->type = mod_brush;
  iVar7 = (*LittleLong)(*(int32 *)buffer);
  if (1 < iVar7 - 0x1dU) {
    Sys_Error("Mod_LoadBrushModel: %s has wrong version number (%i should be %i)",mod,iVar7,0x1e);
  }
  mod_base = buffer;
  piVar19 = buffer;
  do {
    piVar20 = piVar19 + 1;
    iVar7 = (*LittleLong)(*piVar19);
    *piVar19 = iVar7;
    piVar19 = piVar20;
  } while (piVar20 != (int32 *)((int)buffer + 0x7c));
  Mod_LoadVertexes((lump_t *)((int)buffer + 0x1c));
  Mod_LoadEdges((lump_t *)((int)buffer + 100));
  pbVar5 = mod_base;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
  uVar21 = *(uint *)((int)buffer + 0x70);
  iVar9 = *(int *)((int)buffer + 0x6c);
  if ((uVar21 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar21 = *(uint *)((int)buffer + 0x70);
  }
  uVar21 = uVar21 >> 2;
  piVar8 = Hunk_AllocName(uVar21 * 4,loadname);
  pmVar13 = loadmodel;
  loadmodel->surfedges = piVar8;
  pmVar13->numsurfedges = uVar21;
  if (uVar21 != 0) {
    uVar17 = 0;
    do {
      iVar7 = (*LittleLong)(*(int32 *)(pbVar5 + uVar17 * 4 + iVar9));
      piVar8[uVar17] = iVar7;
      uVar17 = uVar17 + 1;
    } while (uVar21 != uVar17);
  }
  iVar9 = strcasecmp(com_gamedir,"bshift");
  if (iVar9 == 0) {
    Mod_LoadEntities((lump_t *)((int)buffer + 0xc));
    Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
    pmVar13 = loadmodel;
    if (*(int *)((int)buffer + 0x48) == 0) {
      loadmodel->lightdata = (color24 *)0x0;
    }
    else {
      pcVar15 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
      pbVar5 = mod_base;
      pmVar13->lightdata = pcVar15;
      Q_memcpy(loadmodel->lightdata,pbVar5 + *(int *)((int)buffer + 0x44),
               *(int *)((int)buffer + 0x48));
    }
    Mod_LoadPlanes((lump_t *)((int)buffer + 4));
  }
  else {
    Mod_LoadEntities((lump_t *)((int)buffer + 4));
    Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
    pmVar13 = loadmodel;
    if (*(int *)((int)buffer + 0x48) == 0) {
      loadmodel->lightdata = (color24 *)0x0;
    }
    else {
      pcVar15 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
      pbVar5 = mod_base;
      pmVar13->lightdata = pcVar15;
      Q_memcpy(loadmodel->lightdata,pbVar5 + *(int *)((int)buffer + 0x44),
               *(int *)((int)buffer + 0x48));
    }
    Mod_LoadPlanes((lump_t *)((int)buffer + 0xc));
  }
  Mod_LoadTexinfo((lump_t *)((int)buffer + 0x34));
  Mod_LoadFaces((lump_t *)((int)buffer + 0x3c));
  Mod_LoadMarksurfaces((lump_t *)((int)buffer + 0x5c));
  pmVar13 = loadmodel;
  if (*(int *)((int)buffer + 0x28) == 0) {
    loadmodel->visdata = (byte *)0x0;
  }
  else {
    pbVar14 = Hunk_AllocName(*(int *)((int)buffer + 0x28),loadname);
    pbVar5 = mod_base;
    pmVar13->visdata = pbVar14;
    Q_memcpy(loadmodel->visdata,pbVar5 + *(int *)((int)buffer + 0x24),*(int *)((int)buffer + 0x28));
  }
  Mod_LoadLeafs((lump_t *)((int)buffer + 0x54));
  Mod_LoadNodes((lump_t *)((int)buffer + 0x2c));
  Mod_LoadClipnodes((lump_t *)((int)buffer + 0x4c));
  iVar18 = 0;
  Mod_LoadSubmodels((lump_t *)((int)buffer + 0x74));
  iVar9 = mod->numsurfaces;
  if (0 < iVar9) {
    do {
      while (mod->numsurfedges < mod->surfaces[iVar18].numedges + mod->surfaces[iVar18].firstedge) {
        iVar18 = iVar18 + 1;
        Sys_Error("MOD_LoadBrushModel: more surfedges referenced than loaded in %s",mod);
        iVar9 = mod->numsurfaces;
        if (iVar9 <= iVar18) goto LAB_00064708;
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < iVar9);
  }
LAB_00064708:
  iVar9 = mod->numleafs;
  iVar18 = 0;
  if (0 < iVar9) {
    do {
                    /* Unresolved local var: int firstmarksurface@[???] */
      while (mod->nummarksurfaces <
             ((int)mod->leafs[iVar18].firstmarksurface - (int)mod->marksurfaces >> 2) +
             mod->leafs[iVar18].nummarksurfaces) {
        iVar18 = iVar18 + 1;
        Sys_Error("MOD_LoadBrushModel: more marksurfaces referenced than loaded in %s",mod);
        iVar9 = mod->numleafs;
        if (iVar9 <= iVar18) goto LAB_00064769;
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < iVar9);
  }
LAB_00064769:
  iVar9 = mod->numnodes;
  iVar18 = 0;
  if (0 < iVar9) {
    do {
      while (mod->numsurfaces <
             (int)((uint)mod->nodes[iVar18].numsurfaces + (uint)mod->nodes[iVar18].firstsurface)) {
        iVar18 = iVar18 + 1;
        Sys_Error("MOD_LoadBrushModel: more surfaces referenced than loaded in %s",mod);
        iVar9 = mod->numnodes;
        if (iVar9 <= iVar18) goto LAB_000647be;
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < iVar9);
  }
LAB_000647be:
  iVar9 = mod->numsubmodels;
  iVar18 = 0;
  if (0 < iVar9) {
    do {
      while (mod->numsurfaces < mod->submodels[iVar18].numfaces + mod->submodels[iVar18].firstface)
      {
        iVar18 = iVar18 + 1;
        Sys_Error("MOD_LoadBrushModel: more faces referenced than loaded in %s",mod);
        iVar9 = mod->numsubmodels;
        if (iVar9 <= iVar18) goto LAB_00064807;
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < iVar9);
  }
LAB_00064807:
                    /* Unresolved local var: mnode_t * in@[???]
                       Unresolved local var: mnode_t * child@[???]
                       Unresolved local var: dclipnode_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: hull_t * hull@[???] */
  pmVar6 = loadmodel;
  iVar9 = loadmodel->numnodes;
  pmVar22 = loadmodel->nodes;
  pdVar10 = Hunk_AllocName(iVar9 * 8,loadname);
  pmVar13 = loadmodel;
  pmVar6->hulls[0].firstclipnode = 0;
  pmVar6->hulls[0].lastclipnode = iVar9 + -1;
  pmVar6->hulls[0].clipnodes = pdVar10;
  pmVar6->hulls[0].planes = pmVar13->planes;
  if (0 < iVar9) {
    iVar18 = 0;
    do {
      pdVar10->planenum = ((int)pmVar22->plane - (int)pmVar13->planes >> 2) * -0x33333333;
      iVar11 = pmVar22->children[0]->contents;
      if (iVar11 < 0) {
        pdVar10->children[0] = (short)iVar11;
        pmVar16 = pmVar22->children[1];
        iVar11 = pmVar16->contents;
        if (iVar11 < 0) goto LAB_000648ef;
LAB_00064895:
        pdVar10->children[1] = (short)((int)pmVar16 - (int)loadmodel->nodes >> 3) * -0x3333;
        pmVar13 = loadmodel;
      }
      else {
        pdVar10->children[0] =
             (short)((int)pmVar22->children[0] - (int)loadmodel->nodes >> 3) * -0x3333;
        pmVar16 = pmVar22->children[1];
        iVar11 = pmVar16->contents;
        if (-1 < iVar11) goto LAB_00064895;
LAB_000648ef:
        pdVar10->children[1] = (short)iVar11;
        pmVar13 = loadmodel;
      }
      loadmodel = pmVar13;
      if (iVar9 == iVar18 + 1) break;
      pmVar22 = pmVar22 + 1;
      iVar18 = iVar18 + 1;
      pdVar10 = pdVar10 + 1;
    } while( true );
  }
  iVar18 = 0;
  mod->numframes = 2;
  mod->flags = 0;
  iVar9 = 1;
  if (0 < mod->numsubmodels) {
    do {
      pdVar23 = mod->submodels + iVar18;
      mod->hulls[0].firstclipnode = pdVar23->headnode[0];
      mod->hulls[1].firstclipnode = pdVar23->headnode[1];
      iVar12 = mod->numclipnodes + -1;
      mod->hulls[1].lastclipnode = iVar12;
      iVar11 = pdVar23->headnode[2];
      mod->hulls[2].lastclipnode = iVar12;
      mod->hulls[2].firstclipnode = iVar11;
      iVar11 = pdVar23->headnode[3];
      mod->hulls[3].lastclipnode = iVar12;
      mod->hulls[3].firstclipnode = iVar11;
      mod->firstmodelsurface = pdVar23->firstface;
      mod->nummodelsurfaces = pdVar23->numfaces;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t corner@[???] */
      fVar24 = pdVar23->maxs[0];
      mod->maxs[0] = fVar24;
      fVar1 = pdVar23->maxs[1];
      mod->maxs[1] = fVar1;
      fVar2 = pdVar23->maxs[2];
      mod->maxs[2] = fVar2;
      local_38 = pdVar23->mins[0];
      mod->mins[0] = local_38;
      local_34 = pdVar23->mins[1];
      mod->mins[1] = local_34;
      local_30 = pdVar23->mins[2];
      mod->mins[2] = local_30;
      local_38 = ABS(local_38);
      fVar24 = ABS(fVar24);
      if (local_38 <= fVar24) {
        local_38 = fVar24;
      }
      local_34 = ABS(local_34);
      fVar1 = ABS(fVar1);
      if (local_34 <= fVar1) {
        local_34 = fVar1;
      }
      local_30 = ABS(local_30);
      fVar2 = ABS(fVar2);
      if (local_30 <= fVar2) {
        local_30 = fVar2;
      }
      fVar24 = Length(&local_38);
      mod->radius = fVar24;
                    /* Unresolved local var: char[10] name@[???] */
      mod->numleafs = pdVar23->visleafs;
      iVar11 = mod->numsubmodels;
      if (iVar18 < iVar11 + -1) {
        __snprintf_chk(local_2a,10,1,10,&DAT_000d51fd,iVar9);
        pmVar13 = Mod_FindName(false,local_2a);
        uVar21 = 0;
        loadmodel = pmVar13;
        do {
          uVar3 = *(undefined4 *)(mod->name + uVar21);
          *(undefined4 *)(pmVar13->name + uVar21 + 4) = *(undefined4 *)(mod->name + uVar21 + 4);
          *(undefined4 *)(pmVar13->name + uVar21) = uVar3;
          uVar21 = uVar21 + 8;
        } while (uVar21 < 0x188);
        Q_strncpy(loadmodel->name,local_2a,0x3f);
        mod = loadmodel;
        loadmodel->name[0x3f] = '\0';
        iVar11 = mod->numsubmodels;
      }
      iVar18 = iVar18 + 1;
      bVar4 = iVar9 < iVar11;
      iVar9 = iVar9 + 1;
    } while (bVar4);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Mod_LoadClipnodes  @ 00063e90
void Mod_LoadClipnodes(lump_t *l)

{
  int iVar1;
  mplane_t *pmVar2;
  model_t *pmVar3;
  short sVar4;
  dclipnode_t *pdVar5;
  int32 iVar6;
  uint uVar7;
  int32 *piVar8;
  uint uVar9;
  
                    /* Unresolved local var: dclipnode_t * in@[???]
                       Unresolved local var: dclipnode_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: hull_t * hull@[???] */
  uVar9 = l->filelen;
  piVar8 = (int32 *)(mod_base + l->fileofs);
  if ((uVar9 & 7) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar9 = l->filelen;
  }
  uVar9 = uVar9 >> 3;
  pdVar5 = Hunk_AllocName(uVar9 * 8,loadname);
  pmVar3 = loadmodel;
  iVar1 = uVar9 - 1;
  loadmodel->hulls[1].firstclipnode = 0;
  pmVar2 = pmVar3->planes;
  pmVar3->hulls[2].firstclipnode = 0;
  pmVar3->hulls[3].firstclipnode = 0;
  uVar7 = 0;
  pmVar3->clipnodes = pdVar5;
  pmVar3->numclipnodes = uVar9;
  pmVar3->hulls[1].clipnodes = pdVar5;
  pmVar3->hulls[1].lastclipnode = iVar1;
  pmVar3->hulls[1].planes = pmVar2;
  pmVar3->hulls[1].clip_mins[0] = -16.0;
  pmVar3->hulls[1].clip_mins[1] = -16.0;
  pmVar3->hulls[1].clip_mins[2] = -36.0;
  pmVar3->hulls[1].clip_maxs[0] = 16.0;
  pmVar3->hulls[1].clip_maxs[1] = 16.0;
  pmVar3->hulls[1].clip_maxs[2] = 36.0;
  pmVar3->hulls[2].clipnodes = pdVar5;
  pmVar3->hulls[2].lastclipnode = iVar1;
  pmVar3->hulls[2].planes = pmVar2;
  pmVar3->hulls[2].clip_mins[0] = -32.0;
  pmVar3->hulls[2].clip_mins[1] = -32.0;
  pmVar3->hulls[2].clip_mins[2] = -32.0;
  pmVar3->hulls[2].clip_maxs[0] = 32.0;
  pmVar3->hulls[2].clip_maxs[1] = 32.0;
  pmVar3->hulls[2].clip_maxs[2] = 32.0;
  pmVar3->hulls[3].clipnodes = pdVar5;
  pmVar3->hulls[3].lastclipnode = iVar1;
  pmVar3->hulls[3].planes = pmVar2;
  pmVar3->hulls[3].clip_mins[0] = -16.0;
  pmVar3->hulls[3].clip_mins[1] = -16.0;
  pmVar3->hulls[3].clip_mins[2] = -18.0;
  pmVar3->hulls[3].clip_maxs[0] = 16.0;
  pmVar3->hulls[3].clip_maxs[1] = 16.0;
  pmVar3->hulls[3].clip_maxs[2] = 18.0;
  if (uVar9 != 0) {
    do {
      uVar7 = uVar7 + 1;
      iVar6 = (*LittleLong)(*piVar8);
      pdVar5->planenum = iVar6;
      sVar4 = (*LittleShort)((short)piVar8[1]);
      pdVar5->children[0] = sVar4;
      sVar4 = (*LittleShort)(*(short *)((int)piVar8 + 6));
      pdVar5->children[1] = sVar4;
      pdVar5 = pdVar5 + 1;
      piVar8 = piVar8 + 2;
    } while (uVar9 != uVar7);
  }
  return;
}


// Mod_LoadEdges  @ 00063070
void Mod_LoadEdges(lump_t *l)

{
  model_t *pmVar1;
  ushort uVar2;
  medge_t *pmVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  
                    /* Unresolved local var: dedge_t * in@[???]
                       Unresolved local var: medge_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  uVar5 = l->filelen;
  psVar4 = (short *)(mod_base + l->fileofs);
  if ((uVar5 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar5 = l->filelen;
  }
  uVar5 = uVar5 >> 2;
  pmVar3 = Hunk_AllocName(uVar5 * 8 + 8,loadname);
  pmVar1 = loadmodel;
  loadmodel->edges = pmVar3;
  pmVar1->numedges = uVar5;
  if (uVar5 != 0) {
    uVar6 = 0;
    do {
      uVar6 = uVar6 + 1;
      uVar2 = (*LittleShort)(*psVar4);
      pmVar3->v[0] = uVar2;
      uVar2 = (*LittleShort)(psVar4[1]);
      pmVar3->v[1] = uVar2;
      psVar4 = psVar4 + 2;
      pmVar3 = pmVar3 + 1;
    } while (uVar5 != uVar6);
  }
  return;
}


// Mod_LoadEntities  @ 00062d70
void Mod_LoadEntities(lump_t *l)

{
  byte *pbVar1;
  model_t *pmVar2;
  char *pcVar3;
  int iVar4;
  
  pmVar2 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->entities = (char *)0x0;
  }
  else {
    pcVar3 = Hunk_AllocName(l->filelen,loadname);
    pbVar1 = mod_base;
    pmVar2->entities = pcVar3;
    Q_memcpy(loadmodel->entities,pbVar1 + l->fileofs,l->filelen);
    pcVar3 = loadmodel->entities;
    if (pcVar3 != (char *)0x0) {
      do {
        pcVar3 = COM_Parse(pcVar3);
        if (*pcVar3 == '\0') {
          return;
        }
        if (com_token[0] == '}') {
          return;
        }
        iVar4 = Q_strcmp(com_token,"wad");
      } while (iVar4 != 0);
      COM_Parse(pcVar3);
      if (wadpath != (char *)0x0) {
        Mem_Free(wadpath);
      }
      wadpath = Mem_Strdup(com_token);
    }
  }
  return;
}


// Mod_LoadFaces  @ 000636c0
void Mod_LoadFaces(lump_t *l)

{
  int *piVar1;
  model_t *pmVar2;
  short sVar3;
  short sVar4;
  msurface_t *s;
  int32 iVar5;
  int iVar6;
  color24 *pcVar7;
  mtexinfo_t *pmVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  
                    /* Unresolved local var: dface_t * in@[???]
                       Unresolved local var: msurface_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int surfnum@[???]
                       Unresolved local var: int planenum@[???]
                       Unresolved local var: int side@[???] */
  uVar9 = l->filelen;
  psVar10 = (short *)(mod_base + l->fileofs);
  if (uVar9 != (uVar9 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar9 = l->filelen;
  }
  uVar9 = uVar9 / 0x14;
  s = Hunk_AllocName(uVar9 * 0x44,loadname);
  pmVar2 = loadmodel;
  loadmodel->numsurfaces = uVar9;
  uVar11 = 0;
  pmVar2->surfaces = s;
  if (uVar9 != 0) {
    do {
      while( true ) {
        iVar5 = (*LittleLong)(*(int32 *)(psVar10 + 2));
        s->firstedge = iVar5;
        sVar3 = (*LittleShort)(psVar10[4]);
        s->flags = 0;
        s->pdecals = (decal_t *)0x0;
        s->numedges = (int)sVar3;
        sVar3 = (*LittleShort)(*psVar10);
        sVar4 = (*LittleShort)(psVar10[1]);
        if (sVar4 != 0) {
          s->flags = s->flags | 2;
        }
        pmVar2 = loadmodel;
        s->plane = loadmodel->planes + sVar3;
        pmVar8 = pmVar2->texinfo;
        sVar3 = (*LittleShort)(psVar10[5]);
        s->texinfo = pmVar8 + sVar3;
        CalcSurfaceExtents(s);
        s->styles[0] = (byte)psVar10[6];
        s->styles[1] = *(byte *)((int)psVar10 + 0xd);
        s->styles[2] = (byte)psVar10[7];
        s->styles[3] = *(byte *)((int)psVar10 + 0xf);
        iVar5 = (*LittleLong)(*(int32 *)(psVar10 + 8));
        if (iVar5 == -1) {
          pcVar7 = (color24 *)0x0;
        }
        else {
          pcVar7 = (color24 *)(&loadmodel->lightdata->r + iVar5);
        }
        s->samples = pcVar7;
        iVar6 = Q_strncmp(s->texinfo->texture->name,"sky",3);
        if (iVar6 != 0) break;
        s->flags = s->flags | 0x24;
LAB_00063744:
        uVar11 = uVar11 + 1;
        psVar10 = psVar10 + 10;
        s = s + 1;
        if (uVar9 == uVar11) {
          return;
        }
      }
      iVar6 = Q_strncmp(s->texinfo->texture->name,"scroll",6);
      if (iVar6 != 0) {
        pmVar8 = s->texinfo;
        if (pmVar8->texture->name[0] != '!') {
          iVar6 = Q_strnicmp(pmVar8->texture->name,"laser",5);
          if (iVar6 == 0) {
            pmVar8 = s->texinfo;
          }
          else {
            iVar6 = Q_strnicmp(s->texinfo->texture->name,"water",5);
            pmVar8 = s->texinfo;
            if (iVar6 != 0) {
              if ((pmVar8->flags & 1) == 0) goto LAB_00063744;
              s->flags = s->flags | 0x20;
              goto LAB_0006387b;
            }
          }
        }
        s->flags = s->flags | 0x30;
        s->extents[0] = 0x4000;
        s->texturemins[0] = -0x2000;
        pmVar8->flags = pmVar8->flags | 1;
        s->extents[1] = 0x4000;
        pmVar8 = s->texinfo;
        s->texturemins[1] = -0x2000;
        piVar1 = &pmVar8->flags;
        *piVar1 = *piVar1 | 1;
        goto LAB_00063744;
      }
      s->flags = s->flags | 0x20;
      pmVar8 = s->texinfo;
LAB_0006387b:
      uVar11 = uVar11 + 1;
      psVar10 = psVar10 + 10;
      s->extents[0] = (short)pmVar8->texture->width;
      s->extents[1] = (short)pmVar8->texture->height;
      s = s + 1;
    } while (uVar9 != uVar11);
  }
  return;
}


// Mod_LoadLeafs  @ 00063d00
void Mod_LoadLeafs(lump_t *l)

{
  int iVar1;
  model_t *pmVar2;
  short sVar3;
  mleaf_s *pmVar4;
  int32 iVar5;
  byte *pbVar6;
  uint uVar7;
  short *psVar8;
  short *psVar9;
  short *psVar10;
  short *psVar11;
  short *psVar12;
  uint local_24;
  
                    /* Unresolved local var: dleaf_t * in@[???]
                       Unresolved local var: mleaf_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int p@[???] */
  pbVar6 = mod_base;
  uVar7 = l->filelen;
  iVar1 = l->fileofs;
  if (uVar7 + (uVar7 / 0x1c) * 4 != uVar7 / 0x1c << 5) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 / 0x1c;
  pmVar4 = Hunk_AllocName(uVar7 * 0x30,loadname);
  pmVar2 = loadmodel;
  loadmodel->numleafs = uVar7;
  pmVar2->leafs = pmVar4;
  if (uVar7 != 0) {
    local_24 = 0;
    psVar10 = pmVar4->minmaxs;
    psVar12 = (short *)(pbVar6 + iVar1 + 8);
    do {
      psVar8 = psVar12;
      psVar11 = psVar10;
      do {
        psVar9 = psVar8 + 1;
        sVar3 = (*LittleShort)(*psVar8);
        *psVar11 = sVar3;
        sVar3 = (*LittleShort)(psVar8[3]);
        psVar11[3] = sVar3;
        psVar8 = psVar9;
        psVar11 = psVar11 + 1;
      } while (psVar9 != psVar12 + 3);
      iVar5 = (*LittleLong)(*(int32 *)(psVar12 + -4));
      ((mleaf_s *)(psVar10 + -4))->contents = iVar5;
      *(msurface_t ***)(psVar10 + 0xc) = loadmodel->marksurfaces + (ushort)psVar12[6];
      sVar3 = (*LittleShort)(psVar12[7]);
      *(int *)(psVar10 + 0xe) = (int)sVar3;
      iVar5 = (*LittleLong)(*(int32 *)(psVar12 + -2));
      if (iVar5 == -1) {
        pbVar6 = (byte *)0x0;
      }
      else {
        pbVar6 = loadmodel->visdata + iVar5;
      }
      *(byte **)(psVar10 + 8) = pbVar6;
      *(efrag_s **)(psVar10 + 10) = (efrag_s *)0x0;
      local_24 = local_24 + 1;
      *(byte *)(psVar10 + 0x12) = (byte)psVar12[8];
      *(byte *)((int)psVar10 + 0x25) = *(byte *)((int)psVar12 + 0x11);
      *(byte *)(psVar10 + 0x13) = (byte)psVar12[9];
      *(byte *)((int)psVar10 + 0x27) = *(byte *)((int)psVar12 + 0x13);
      psVar10 = psVar10 + 0x18;
      psVar12 = psVar12 + 0xe;
    } while (uVar7 != local_24);
  }
  return;
}


// Mod_LoadLighting  @ 00062c50
void Mod_LoadLighting(lump_t *l)

{
  byte *pbVar1;
  model_t *pmVar2;
  color24 *pcVar3;
  
  pmVar2 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->lightdata = (color24 *)0x0;
    return;
  }
  pcVar3 = Hunk_AllocName(l->filelen,loadname);
  pbVar1 = mod_base;
  pmVar2->lightdata = pcVar3;
  Q_memcpy(loadmodel->lightdata,pbVar1 + l->fileofs,l->filelen);
  return;
}


// Mod_LoadMarksurfaces  @ 00064180
void Mod_LoadMarksurfaces(lump_t *l)

{
  int iVar1;
  byte *pbVar2;
  model_t *pmVar3;
  short sVar4;
  msurface_t **ppmVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: short * in@[???]
                       Unresolved local var: msurface_t * * out@[???] */
  pbVar2 = mod_base;
  uVar6 = l->filelen;
  iVar1 = l->fileofs;
  if ((uVar6 & 1) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar6 = l->filelen;
  }
  uVar6 = uVar6 >> 1;
  ppmVar5 = Hunk_AllocName(uVar6 * 4,loadname);
  pmVar3 = loadmodel;
  loadmodel->nummarksurfaces = uVar6;
  uVar7 = 0;
  pmVar3->marksurfaces = ppmVar5;
  if (uVar6 != 0) {
    do {
      sVar4 = (*LittleShort)(*(short *)(pbVar2 + uVar7 * 2 + iVar1));
      if (loadmodel->numsurfaces <= (int)sVar4) {
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      ppmVar5[uVar7] = loadmodel->surfaces + sVar4;
      uVar7 = uVar7 + 1;
    } while (uVar6 != uVar7);
  }
  return;
}


// Mod_LoadModel  @ 00065c50
model_t * __regparm3 Mod_LoadModel(model_t *mod,qboolean crash,qboolean trackCRC)

{
  int iVar1;
  int32 *pBuffer;
  char *pcVar2;
  int32 iVar3;
  model_t *__src;
  qboolean qVar4;
  qboolean qVar5;
  int in_GS_OFFSET;
  model_t *local_130;
  int local_12c;
  CRC32_t local_128;
  char local_124 [259];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[260] tmpName@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = COM_CheckParm("-steam");
  if ((iVar1 != 0) && (__src = mod, mod->name[0] == '/')) {
    do {
      __src = (model_t *)(__src->name + 1);
    } while (__src->name[0] == '/');
    strncpy(local_124,(char *)__src,0x103);
    local_21 = 0;
    strncpy(mod->name,local_124,0x3f);
    mod->name[0x3f] = '\0';
  }
  pBuffer = (int32 *)COM_LoadFileForMe(mod->name,&local_12c);
  if (pBuffer == (int32 *)0x0) {
    local_130 = (model_t *)0x0;
    if (crash != false) {
      local_130 = (model_t *)0x0;
      Sys_Error("Mod_NumForName: %s not found",mod);
    }
    goto LAB_00065d67;
  }
                    /* Unresolved local var: mod_known_info_t * p@[???] */
  if ((trackCRC != false) &&
     (iVar1 = ((int)(mod[-0x1ecd].hulls[0].clip_mins + 2) >> 3) * 0x397829cc,
     *(int *)((int)mod_known_info + iVar1) != 0)) {
                    /* Unresolved local var: CRC32_t currentCRC@[???] */
    CRC32_Init(&local_128);
    CRC32_ProcessBuffer(&local_128,pBuffer,local_12c);
    local_128 = CRC32_Final(local_128);
    if (*(int *)((int)mod_known_info + iVar1 + 4) == 0) {
                    /* Unresolved local var: qboolean badModel@[???] */
      *(CRC32_t *)((int)mod_known_info + iVar1 + 8) = local_128;
      *(undefined4 *)((int)mod_known_info + iVar1 + 4) = 1;
      SetCStrikeFlags();
      qVar4 = IsGameSubscribed("czero");
      if ((((qVar4 == false) && (g_bIsCStrike != 0)) &&
          (qVar5 = IsCZPlayerModel(local_128,mod->name), qVar5 != 0)) && (cls.state != ca_dedicated)
         ) {
        COM_ExplainDisconnection(true,"Cannot continue with altered model %s, disconnecting.",mod);
        CL_Disconnect();
        local_130 = (model_t *)0x0;
        goto LAB_00065d67;
      }
    }
    else if (local_128 != *(CRC32_t *)((int)mod_known_info + iVar1 + 8)) {
      Sys_Error("%s has been modified since starting the engine.  Consider running system diagnostics to check for faulty hardware.\n"
                ,mod);
      local_130 = (model_t *)0x0;
      goto LAB_00065d67;
    }
  }
  if (1.0 < developer.value) {
    Con_DPrintf("loading %s\n",mod);
  }
  pcVar2 = COM_FileBase_s(mod->name,loadname,0x20);
  if (pcVar2 == (char *)0x0) {
    Sys_Error("Mod_LoadModel: Bad model name length: %s\n",mod);
    local_130 = (model_t *)0x0;
  }
  else {
    loadmodel = mod;
    mod->needload = false;
    iVar3 = (*LittleLong)(*pBuffer);
    if (iVar3 == 0x50534449) {
      Mod_LoadSpriteModel(mod,pBuffer);
    }
    else if (iVar3 == 0x54534449) {
      Mod_LoadStudioModel(mod,pBuffer);
    }
    else if (iVar3 == 0x4f504449) {
      Mod_LoadAliasModel(mod,pBuffer);
    }
    else {
      Mod_LoadBrushModel(mod,pBuffer);
    }
    if (g_modfuncs.m_pfnModelLoad != (PFN_MODELLOAD)0x0) {
      (*g_modfuncs.m_pfnModelLoad)(mod,pBuffer);
    }
    Mem_Free(pBuffer);
    local_130 = mod;
  }
LAB_00065d67:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_130;
}


// Mod_LoadModel  @ 00065f50
model_t * Mod_LoadModel(model_t *mod,qboolean crash,qboolean trackCRC)

{
  model_t *pmVar1;
  void *pvVar2;
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[260] tmpName@[???] */
  if (mod->type - mod_alias < 2) {
    pvVar2 = Cache_Check(&mod->cache);
    if (pvVar2 != (void *)0x0) {
      mod->needload = false;
      return mod;
    }
  }
  else if ((mod->needload == false) || (mod->needload == 3)) {
    return mod;
  }
  pmVar1 = Mod_LoadModel(mod,crash,trackCRC);
  return pmVar1;
}


// Mod_LoadNodes  @ 00063b20
void Mod_LoadNodes(lump_t *l)

{
  mnode_s *pmVar1;
  mnode_s *pmVar2;
  model_t *pmVar3;
  short sVar4;
  ushort uVar5;
  mnode_t *pmVar6;
  int32 iVar7;
  uint uVar8;
  mleaf_s *pmVar9;
  uint uVar10;
  int32 *piVar11;
  int32 *piVar12;
  int iVar13;
  short *psVar14;
  int32 *piVar15;
  uint local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: dnode_t * in@[???]
                       Unresolved local var: mnode_t * out@[???] */
  uVar10 = l->filelen;
  piVar15 = (int32 *)(mod_base + l->fileofs);
  if (uVar10 != (uVar10 / 0x18) * 0x18) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar10 = l->filelen;
  }
  uVar10 = uVar10 / 0x18;
  pmVar6 = Hunk_AllocName(uVar10 * 0x28,loadname);
  pmVar3 = loadmodel;
  local_24 = 0;
  loadmodel->nodes = pmVar6;
  pmVar3->numnodes = uVar10;
  if (uVar10 != 0) {
    do {
      piVar11 = piVar15 + 2;
      psVar14 = pmVar6->minmaxs;
      do {
        piVar12 = (int32 *)((int)piVar11 + 2);
        sVar4 = (*LittleShort)((short)*piVar11);
        *psVar14 = sVar4;
        sVar4 = (*LittleShort)(*(short *)((int)piVar11 + 6));
        psVar14[3] = sVar4;
        piVar11 = piVar12;
        psVar14 = psVar14 + 1;
      } while (piVar12 != (int32 *)((int)piVar15 + 0xe));
      iVar13 = 0;
      iVar7 = (*LittleLong)(*piVar15);
      pmVar6->plane = loadmodel->planes + iVar7;
      uVar5 = (*LittleShort)((short)piVar15[5]);
      pmVar6->firstsurface = uVar5;
      uVar5 = (*LittleShort)(*(short *)((int)piVar15 + 0x16));
      pmVar6->numsurfaces = uVar5;
      do {
        sVar4 = (*LittleShort)(*(short *)((int)piVar15 + iVar13 * 2 + 4));
        pmVar3 = loadmodel;
        uVar8 = (uint)sVar4;
        if ((int)uVar8 < 0) {
          pmVar9 = loadmodel->leafs + ~uVar8;
        }
        else {
          pmVar9 = (mleaf_s *)(loadmodel->nodes + uVar8);
        }
        pmVar6->children[iVar13] = (mnode_s *)pmVar9;
        iVar13 = iVar13 + 1;
      } while (iVar13 != 2);
      local_24 = local_24 + 1;
      piVar15 = piVar15 + 6;
      pmVar6 = pmVar6 + 1;
    } while (local_24 != uVar10);
    pmVar1 = pmVar3->nodes;
    iVar13 = pmVar1->contents;
    pmVar1->parent = (mnode_s *)0x0;
    while (-1 < iVar13) {
      pmVar6 = pmVar1->children[0];
      iVar13 = pmVar6->contents;
      pmVar6->parent = pmVar1;
      while (-1 < iVar13) {
        Mod_SetParent(pmVar6->children[0],pmVar6);
        pmVar2 = pmVar6->children[1];
        iVar13 = pmVar2->contents;
        pmVar2->parent = pmVar6;
        pmVar6 = pmVar2;
      }
      pmVar2 = pmVar1->children[1];
      iVar13 = pmVar2->contents;
      pmVar2->parent = pmVar1;
      pmVar1 = pmVar2;
    }
  }
  return;
}


// Mod_LoadPlanes  @ 00064300
void Mod_LoadPlanes(lump_t *l)

{
  model_t *pmVar1;
  mplane_t *pmVar2;
  int32 iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  longdouble lVar8;
  uint local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: mplane_t * out@[???]
                       Unresolved local var: dplane_t * in@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int bits@[???] */
  uVar4 = l->filelen;
  pbVar7 = mod_base + l->fileofs;
  if (uVar4 != (uVar4 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar4 = l->filelen;
  }
  uVar6 = 0;
  uVar4 = uVar4 / 0x14;
  pmVar2 = Hunk_AllocName(uVar4 * 0x28,loadname);
  pmVar1 = loadmodel;
  loadmodel->planes = pmVar2;
  pmVar1->numplanes = uVar4;
  if (uVar4 != 0) {
    do {
      iVar5 = 0;
      local_24 = 0;
      do {
        lVar8 = (longdouble)(*LittleFloat)(*(float *)(pbVar7 + iVar5 * 4));
        pmVar2->normal[iVar5] = (float)lVar8;
        if (lVar8 < (longdouble)0) {
          local_24 = local_24 | 1 << ((byte)iVar5 & 0x1f);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != 3);
      uVar6 = uVar6 + 1;
      lVar8 = (longdouble)(*LittleFloat)(*(float *)(pbVar7 + 0xc));
      pmVar2->dist = (float)lVar8;
      iVar3 = (*LittleLong)(*(int32 *)(pbVar7 + 0x10));
      pmVar2->type = (byte)iVar3;
      pmVar2->signbits = (byte)local_24;
      pmVar2 = pmVar2 + 1;
      pbVar7 = pbVar7 + 0x14;
    } while (uVar4 != uVar6);
  }
  return;
}


// Mod_LoadSpriteFrame  @ 00065800
void * Mod_LoadSpriteFrame(void *pin,mspriteframe_t **ppframe)

{
  int iVar1;
  int32 iVar2;
  int32 iVar3;
  mspriteframe_t *dest;
  int32 iVar4;
  int32 iVar5;
  int count;
  
                    /* Unresolved local var: dspriteframe_t * pinframe@[???]
                       Unresolved local var: mspriteframe_t * pspriteframe@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int[2] origin@[???]
                       Unresolved local var: ushort * ppixout@[???]
                       Unresolved local var: byte * ppixin@[???] */
  iVar2 = (*LittleLong)(*(int32 *)((int)pin + 8));
  iVar3 = (*LittleLong)(*(int32 *)((int)pin + 0xc));
  count = iVar2 * iVar3;
  dest = Hunk_AllocName(r_pixbytes * count + 0x20,loadname);
  Q_memset(dest,0,r_pixbytes * count + 0x20);
  *ppframe = dest;
  dest->height = iVar3;
  dest->width = iVar2;
  iVar4 = (*LittleLong)(*(int32 *)pin);
  iVar5 = (*LittleLong)(*(int32 *)((int)pin + 4));
  iVar1 = r_pixbytes;
  dest->up = (float)iVar5;
  dest->down = (float)(iVar5 - iVar3);
  dest->left = (float)iVar4;
  dest->right = (float)(iVar2 + iVar4);
  if (iVar1 == 1) {
    Q_memcpy(dest->pixels,(void *)((int)pin + 0x10),count);
  }
  else if (iVar1 != 2) {
    Sys_Error("Mod_LoadSpriteFrame: driver set invalid r_pixbytes: %d\n",iVar1);
  }
  return (void *)((int)pin + count + 0x10);
}


// Mod_LoadSpriteGroup  @ 00065930
void * Mod_LoadSpriteGroup(void *pin,mspriteframe_t **ppframe)

{
  int size;
  int32 iVar1;
  mspriteframe_t *pmVar2;
  void *pvVar3;
  int iVar4;
  void **ppframe_00;
  void *pin_00;
  longdouble lVar5;
  
                    /* Unresolved local var: dspritegroup_t * pingroup@[???]
                       Unresolved local var: mspritegroup_t * pspritegroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: dspriteinterval_t * pin_intervals@[???]
                       Unresolved local var: float * poutintervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  pin_00 = (void *)((int)pin + 4);
  iVar1 = (*LittleLong)(*(int32 *)pin);
  size = iVar1 * 4;
  pmVar2 = Hunk_AllocName(size + 8,loadname);
  pmVar2->width = iVar1;
  *ppframe = pmVar2;
  pvVar3 = Hunk_AllocName(size,loadname);
  pmVar2->height = (int)pvVar3;
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      while( true ) {
        lVar5 = (longdouble)(*LittleFloat)(*(float *)((int)pin + iVar4 * 4 + 4));
        *(float *)((int)pvVar3 + iVar4 * 4) = (float)lVar5;
        if ((longdouble)0 < lVar5) break;
        iVar4 = iVar4 + 1;
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
        if (iVar1 == iVar4) goto LAB_000659e0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
LAB_000659e0:
    iVar4 = 0;
    pin_00 = (void *)((int)pin_00 + size);
    ppframe_00 = &pmVar2->pcachespot;
    do {
      iVar4 = iVar4 + 1;
      pin_00 = Mod_LoadSpriteFrame(pin_00,ppframe_00);
      ppframe_00 = ppframe_00 + 1;
    } while (iVar1 != iVar4);
  }
  return pin_00;
}


// Mod_LoadSpriteModel  @ 00065a10
void Mod_LoadSpriteModel(model_t *mod,void *buffer)

{
  ushort *puVar1;
  byte bVar2;
  int32 iVar3;
  undefined2 *puVar4;
  int32 iVar5;
  synctype_t sVar6;
  uint uVar7;
  mspriteframe_t *pmVar8;
  byte *pbVar9;
  ushort *puVar10;
  ushort *puVar11;
  int iVar12;
  int32 *piVar13;
  mspriteframe_t **ppframe;
  longdouble lVar14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int version@[???]
                       Unresolved local var: dsprite_t * pin@[???]
                       Unresolved local var: msprite_t * psprite@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int palsize@[???]
                       Unresolved local var: dspriteframetype_t * pframetype@[???]
                       Unresolved local var: int entries@[???] */
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar3 != 2) {
    Sys_Error("%s has wrong version number (%i should be %i)",mod,iVar3,2);
  }
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 0x1c));
  puVar4 = Hunk_AllocName(iVar3 * 8 + 0x1e + *(short *)((int)buffer + 0x28) * 8,loadname);
  (mod->cache).data = puVar4;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 8));
  *puVar4 = (short)iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0xc));
  puVar4[1] = (short)iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x14));
  *(int32 *)(puVar4 + 2) = iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x18));
  *(int32 *)(puVar4 + 4) = iVar5;
  lVar14 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  *(float *)(puVar4 + 10) = (float)lVar14;
  sVar6 = (*LittleLong)(*(int32 *)((int)buffer + 0x24));
  mod->synctype = sVar6;
  iVar12 = *(int *)(puVar4 + 2);
  *(int32 *)(puVar4 + 6) = iVar3;
  mod->mins[1] = (float)-(iVar12 / 2);
  mod->mins[0] = (float)-(iVar12 / 2);
  iVar12 = *(int *)(puVar4 + 2);
  mod->maxs[1] = (float)(iVar12 / 2);
  mod->maxs[0] = (float)(iVar12 / 2);
  mod->mins[2] = (float)-(*(int *)(puVar4 + 4) / 2);
  pbVar9 = (byte *)((int)buffer + 0x2b);
  mod->maxs[2] = (float)(*(int *)(puVar4 + 4) / 2);
  *(int32 *)(puVar4 + 8) = iVar3 * 8 + 0x1e;
                    /* Unresolved local var: byte * palsrc@[???]
                       Unresolved local var: ushort * paldest@[???] */
  puVar10 = puVar4 + iVar3 * 4 + 0xf;
  uVar7 = (uint)*(ushort *)((int)buffer + 0x28);
  puVar4[iVar3 * 4 + 0xe] = *(ushort *)((int)buffer + 0x28);
  puVar1 = puVar10 + uVar7 * 4;
  if (uVar7 != 0) {
    do {
      puVar11 = puVar10 + 4;
      *puVar10 = (ushort)pbVar9[-1];
      puVar10[1] = (ushort)*pbVar9;
      bVar2 = pbVar9[1];
      puVar10[3] = 0;
      puVar10[2] = (ushort)bVar2;
      pbVar9 = pbVar9 + 3;
      puVar10 = puVar11;
    } while (puVar11 != puVar1);
  }
  if (iVar3 < 1) {
    Sys_Error("Mod_LoadSpriteModel: Invalid # of frames: %d\n",iVar3);
    mod->numframes = iVar3;
    mod->flags = 0;
  }
  else {
    ppframe = (mspriteframe_t **)(puVar4 + 0x10);
    iVar12 = 0;
    mod->numframes = iVar3;
    mod->flags = 0;
    piVar13 = (int32 *)((int)buffer + uVar7 * 3 + 0x2a);
    do {
      while( true ) {
        pmVar8 = (mspriteframe_t *)(*LittleLong)(*piVar13);
        ppframe[-1] = pmVar8;
        if (pmVar8 == (mspriteframe_t *)0x0) break;
        piVar13 = Mod_LoadSpriteGroup(piVar13 + 1,ppframe);
        iVar12 = iVar12 + 1;
        ppframe = ppframe + 2;
        if (iVar3 == iVar12) goto LAB_00065c1b;
      }
                    /* Unresolved local var: spriteframetype_t frametype@[???] */
      piVar13 = Mod_LoadSpriteFrame(piVar13 + 1,ppframe);
      iVar12 = iVar12 + 1;
      ppframe = ppframe + 2;
    } while (iVar3 != iVar12);
  }
LAB_00065c1b:
  mod->type = mod_sprite;
  return;
}


// Mod_LoadStudioModel  @ 0005f4d0
void Mod_LoadStudioModel(model_t *mod,void *buffer)

{
  byte bVar1;
  void *dest;
  int32 iVar2;
  int count;
  byte *pbVar3;
  byte *pbVar4;
  ushort *puVar5;
  byte *src;
  int iVar6;
  ushort *dest_00;
  int iVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte * pin@[???]
                       Unresolved local var: byte * pout@[???]
                       Unresolved local var: byte * pindata@[???]
                       Unresolved local var: byte * poutdata@[???]
                       Unresolved local var: studiohdr_t * phdr@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int version@[???] */
  iVar2 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar2 != 10) {
    Q_memset(buffer,0,0xf4);
    Q_strcpy((char *)((int)buffer + 8),"bogus");
    *(undefined4 *)((int)buffer + 0x48) = 0xf4;
    *(undefined4 *)((int)buffer + 0xbc) = 0xf4;
  }
  mod->type = mod_studio;
  mod->flags = *(int *)((int)buffer + 0x88);
  Cache_Alloc(&mod->cache,*(int *)((int)buffer + 0xb4) * 0x500 + *(int *)((int)buffer + 0x48),
              mod->name);
  dest = (mod->cache).data;
  if (dest != (void *)0x0) {
    iVar6 = *(int *)((int)buffer + 0xb8);
    if (iVar6 == 0) {
      Q_memcpy(dest,buffer,*(int *)((int)buffer + 0x48));
      return;
    }
    Q_memcpy(dest,buffer,*(int *)((int)buffer + 0xbc));
    src = (byte *)((int)buffer + *(int *)((int)buffer + 0xbc));
    dest_00 = (ushort *)(*(int *)((int)buffer + 0xbc) + (int)dest);
    if (0 < *(int *)((int)buffer + 0xb4)) {
      iVar6 = iVar6 + (int)dest;
      iVar7 = 0;
      do {
                    /* Unresolved local var: int j@[???] */
        *(int *)(iVar6 + 0x4c) = (int)dest_00 - (int)dest;
        count = *(int *)(iVar6 + 0x44) * *(int *)(iVar6 + 0x48);
        Q_memcpy(dest_00,src,count);
        pbVar3 = src + count;
        src = pbVar3 + 0x300;
        puVar5 = (ushort *)((int)dest_00 + count);
        do {
          pbVar4 = pbVar3 + 3;
          *puVar5 = (ushort)texgammatable[*pbVar3];
          puVar5[1] = (ushort)texgammatable[pbVar3[1]];
          bVar1 = texgammatable[pbVar3[2]];
          puVar5[3] = 0;
          puVar5[2] = (ushort)bVar1;
          pbVar3 = pbVar4;
          puVar5 = puVar5 + 4;
        } while (pbVar4 != src);
        iVar7 = iVar7 + 1;
        dest_00 = (ushort *)((int)dest_00 + count) + 0x400;
        iVar6 = iVar6 + 0x50;
      } while (iVar7 < *(int *)((int)buffer + 0xb4));
    }
  }
  return;
}


// Mod_LoadSubmodels  @ 00062f30
void Mod_LoadSubmodels(lump_t *l)

{
  model_t *pmVar1;
  uint uVar2;
  dmodel_t *pdVar3;
  int32 iVar4;
  float *pfVar5;
  dmodel_t *pdVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  longdouble lVar10;
  uint local_24;
  
                    /* Unresolved local var: dmodel_t * in@[???]
                       Unresolved local var: dmodel_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???] */
  uVar2 = l->filelen;
  pfVar5 = (float *)(mod_base + l->fileofs);
  if ((uVar2 & 0x3f) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar2 = l->filelen;
  }
  uVar2 = uVar2 >> 6;
  pdVar3 = Hunk_AllocName(uVar2 << 6,loadname);
  pmVar1 = loadmodel;
  local_24 = 0;
  loadmodel->submodels = pdVar3;
  pmVar1->numsubmodels = uVar2;
  if (uVar2 != 0) {
    do {
      pdVar6 = pdVar3;
      pfVar8 = pfVar5;
      do {
        pfVar9 = pfVar8 + 1;
        lVar10 = (longdouble)(*LittleFloat)(*pfVar8);
        pdVar6->mins[0] = (float)(lVar10 - (longdouble)1);
        lVar10 = (longdouble)(*LittleFloat)(pfVar8[3]);
        pdVar6->maxs[0] = (float)((longdouble)1 + lVar10);
        lVar10 = (longdouble)(*LittleFloat)(pfVar8[6]);
        pdVar6->origin[0] = (float)lVar10;
        pdVar6 = (dmodel_t *)(pdVar6->mins + 1);
        pfVar8 = pfVar9;
      } while (pfVar5 + 3 != pfVar9);
      iVar7 = 0;
      do {
        iVar4 = (*LittleLong)((int32)pfVar5[iVar7 + 9]);
        pdVar3->headnode[iVar7] = iVar4;
        iVar7 = iVar7 + 1;
      } while (iVar7 != 4);
      iVar4 = (*LittleLong)((int32)pfVar5[0xd]);
      pdVar3->visleafs = iVar4;
      iVar4 = (*LittleLong)((int32)pfVar5[0xe]);
      pdVar3->firstface = iVar4;
      iVar4 = (*LittleLong)((int32)pfVar5[0xf]);
      local_24 = local_24 + 1;
      pdVar3->numfaces = iVar4;
      pfVar5 = pfVar5 + 0x10;
      pdVar3 = pdVar3 + 1;
    } while (uVar2 != local_24);
  }
  return;
}


// Mod_LoadSurfedges  @ 00064260
void Mod_LoadSurfedges(lump_t *l)

{
  int iVar1;
  byte *pbVar2;
  model_t *pmVar3;
  int *piVar4;
  int32 iVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
  pbVar2 = mod_base;
  uVar6 = l->filelen;
  iVar1 = l->fileofs;
  if ((uVar6 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar6 = l->filelen;
  }
  uVar6 = uVar6 >> 2;
  uVar7 = 0;
  piVar4 = Hunk_AllocName(uVar6 * 4,loadname);
  pmVar3 = loadmodel;
  loadmodel->surfedges = piVar4;
  pmVar3->numsurfedges = uVar6;
  if (uVar6 != 0) {
    do {
      iVar5 = (*LittleLong)(*(int32 *)(pbVar2 + uVar7 * 4 + iVar1));
      piVar4[uVar7] = iVar5;
      uVar7 = uVar7 + 1;
    } while (uVar6 != uVar7);
  }
  return;
}


// Mod_LoadTexinfo  @ 00063130
void Mod_LoadTexinfo(lump_t *l)

{
  texture_t *ptVar1;
  model_t *pmVar2;
  mtexinfo_t *v;
  int32 iVar3;
  int32 iVar4;
  texture_t **pptVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  longdouble lVar10;
  float fVar11;
  float fVar12;
  
                    /* Unresolved local var: texinfo_t * in@[???]
                       Unresolved local var: mtexinfo_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int miptex@[???]
                       Unresolved local var: float len1@[???]
                       Unresolved local var: float len2@[???] */
  uVar7 = l->filelen;
  pbVar6 = mod_base + l->fileofs;
  if (uVar7 != (uVar7 / 0x28) * 0x28) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 / 0x28;
  v = Hunk_AllocName(uVar7 * 0x2c,loadname);
  pmVar2 = loadmodel;
  loadmodel->numtexinfo = uVar7;
  uVar9 = 0;
  pmVar2->texinfo = v;
  if (uVar7 != 0) {
    do {
      iVar8 = 0;
      do {
        lVar10 = (longdouble)(*LittleFloat)(*(float *)(pbVar6 + iVar8 * 4));
        v->vecs[0][iVar8] = (float)lVar10;
        iVar8 = iVar8 + 1;
      } while (iVar8 != 8);
      fVar11 = Length((vec_t *)v);
      fVar12 = Length(v->vecs[1]);
      fVar11 = (fVar12 + fVar11) * 0.5;
      if (0.32 <= fVar11) {
        if (0.49 <= fVar11) {
          fVar12 = 2.0;
          if (0.99 <= fVar11) {
            fVar12 = 1.0;
          }
          v->mipadjust = fVar12;
        }
        else {
          v->mipadjust = 3.0;
        }
      }
      else {
        v->mipadjust = 4.0;
      }
      iVar3 = (*LittleLong)(*(int32 *)(pbVar6 + 0x20));
      iVar4 = (*LittleLong)(*(int32 *)(pbVar6 + 0x24));
      v->flags = iVar4;
      pptVar5 = loadmodel->textures;
      if (pptVar5 == (texture_t **)0x0) {
LAB_00063288:
        ptVar1 = r_notexture_mip;
        v->flags = 0;
        v->texture = ptVar1;
      }
      else {
        if (loadmodel->numtextures <= iVar3) {
          Sys_Error("miptex >= loadmodel->numtextures");
          pptVar5 = loadmodel->textures;
        }
        ptVar1 = pptVar5[iVar3];
        v->texture = ptVar1;
        if (ptVar1 == (texture_t *)0x0) goto LAB_00063288;
      }
      uVar9 = uVar9 + 1;
      pbVar6 = pbVar6 + 0x28;
      v = v + 1;
    } while (uVar7 != uVar9);
  }
  return;
}


// Mod_LoadTextures  @ 00061930
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Mod_LoadTextures(lump_t *l)

{
  int iVar1;
  bool bVar2;
  model_t *pmVar3;
  int iVar4;
  int32 *piVar5;
  int32 iVar6;
  texture_t **pptVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  texture_t *ptVar11;
  char *pcVar12;
  byte *pbVar13;
  void *pvVar14;
  int iVar15;
  int iVar16;
  int32 *piVar17;
  int32 *piVar18;
  int iVar19;
  int iVar20;
  int in_GS_OFFSET;
  double dVar21;
  double dVar22;
  int iStack_553e0;
  int iStack_553d4;
  int iStack_553c8;
  int aiStack_553b4 [10];
  int aiStack_5538c [10];
  byte abStack_55362 [349010];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int pixels@[???]
                       Unresolved local var: int palette@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int max@[???]
                       Unresolved local var: int altmax@[???]
                       Unresolved local var: miptex_t * mt@[???]
                       Unresolved local var: texture_t * tx@[???]
                       Unresolved local var: texture_t * tx2@[???]
                       Unresolved local var: texture_t *[10] anims@[???]
                       Unresolved local var: texture_t *[10] altanims@[???]
                       Unresolved local var: dmiptexlump_t * m@[???]
                       Unresolved local var: uchar[3] * mippal@[???]
                       Unresolved local var: ushort[4] * texpal@[???]
                       Unresolved local var: byte[348994] dtexdata@[???]
                       Unresolved local var: qboolean wads_parsed@[???]
                       Unresolved local var: double starttime@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  dVar21 = Sys_FloatTime();
  if (tested == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * s@[???] */
    tested = 1;
    iVar19 = COM_CheckParm("-ad");
    if (((iVar19 != 0) && (pcVar12 = com_argv[iVar19 + 1], pcVar12 != (char *)0x0)) &&
       (*pcVar12 != '\0')) {
      snprintf(Mod_AdInit::filename,0x104,"%s",pcVar12);
      uVar10 = FS_FileSize(Mod_AdInit::filename);
      if ((int)uVar10 < 1) {
        Con_Printf("No -ad file specified, skipping\n");
      }
      else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * s@[???] */
        Draw_CacheWadInit(Mod_AdInit::filename,0x10,&ad_wad);
        ad_enabled = 1;
      }
    }
  }
  if (l->filelen == 0) {
    loadmodel->textures = (texture_t **)0x0;
  }
  else {
    piVar5 = (int32 *)(mod_base + l->fileofs);
    iVar6 = (*LittleLong)(*piVar5);
    *piVar5 = iVar6;
    pmVar3 = loadmodel;
    loadmodel->numtextures = iVar6;
    pptVar7 = Hunk_AllocName(*piVar5 << 2,loadname);
    pmVar3->textures = pptVar7;
    if (0 < *piVar5) {
      bVar2 = false;
      iVar19 = 0;
      do {
        iVar6 = (*LittleLong)(piVar5[iVar19 + 1]);
        piVar5[iVar19 + 1] = iVar6;
        if (iVar6 != -1) {
          pbVar13 = (byte *)((int)piVar5 + iVar6);
          if ((r_wadtextures.value != 0.0) ||
             (iVar6 = (*LittleLong)(*(int32 *)(pbVar13 + 0x18)), iVar6 == 0)) {
            if (!bVar2) {
              TEX_InitFromWad(wadpath);
              TEX_AddAnimatingTextures();
            }
            iVar8 = TEX_LoadLump((char *)pbVar13,abStack_55362,0x55342);
            if (iVar8 == 0) {
              piVar5[iVar19 + 1] = -1;
              bVar2 = true;
              goto LAB_00061a6e;
            }
            bVar2 = true;
            pbVar13 = abStack_55362;
          }
          piVar17 = (int32 *)(pbVar13 + 0x18);
          do {
            piVar18 = piVar17 + 1;
            iVar6 = (*LittleLong)(*piVar17);
            *piVar17 = iVar6;
            piVar17 = piVar18;
          } while (piVar18 != (int32 *)(pbVar13 + 0x28));
          iVar6 = (*LittleLong)(*(int32 *)(pbVar13 + 0x10));
          *(int32 *)(pbVar13 + 0x10) = iVar6;
          uVar9 = (*LittleLong)(*(int32 *)(pbVar13 + 0x14));
          uVar10 = *(uint *)(pbVar13 + 0x10);
          *(uint *)(pbVar13 + 0x14) = uVar9;
          if (((uVar9 | uVar10) & 0xf) != 0) {
            Sys_Error("Texture %s is not 16 aligned",pbVar13);
            uVar10 = *(uint *)(pbVar13 + 0x10);
            uVar9 = *(uint *)(pbVar13 + 0x14);
          }
          iVar8 = (uVar9 * uVar10 >> 6) * 0x55;
          uVar10 = (uint)*(ushort *)(pbVar13 + iVar8 + 0x28);
          ptVar11 = Hunk_AllocName(uVar10 * 8 + iVar8 + 0x42U,loadname);
          loadmodel->textures[iVar19] = ptVar11;
          Q_memcpy(ptVar11,pbVar13,0x10);
          pcVar12 = strchr(ptVar11->name,0x7e);
          if (pcVar12 != (char *)0x0) {
            ptVar11->name[2] = ' ';
          }
          ptVar11->width = *(uint *)(pbVar13 + 0x10);
          ptVar11->height = *(uint *)(pbVar13 + 0x14);
          ptVar11->offsets[0] = *(int *)(pbVar13 + 0x18) + 0x18;
          ptVar11->offsets[1] = *(int *)(pbVar13 + 0x1c) + 0x18;
          ptVar11->offsets[2] = *(int *)(pbVar13 + 0x20) + 0x18;
          iVar20 = *(int *)(pbVar13 + 0x24);
          ptVar11->paloffset = iVar8 + 0x42U;
          ptVar11->offsets[3] = iVar20 + 0x18;
          Q_memcpy(ptVar11 + 1,pbVar13 + 0x28,iVar8 + 2);
          iVar20 = Q_strncmp((char *)pbVar13,"sky",3);
          if (iVar20 == 0) {
            R_InitSky();
          }
          if (uVar10 != 0) {
            pbVar13 = pbVar13 + iVar8;
            iVar20 = (int)ptVar11 + iVar8;
            do {
              *(undefined2 *)(iVar20 + 0x48) = 0;
              iVar16 = iVar20 + 8;
              *(ushort *)(iVar20 + 0x46) = (ushort)texgammatable[pbVar13[0x2a]];
              *(ushort *)(iVar20 + 0x44) = (ushort)texgammatable[pbVar13[0x2b]];
              *(ushort *)(iVar20 + 0x42) = (ushort)texgammatable[pbVar13[0x2c]];
              pbVar13 = pbVar13 + 3;
              iVar20 = iVar16;
            } while (iVar16 != iVar8 + uVar10 * 8 + (int)ptVar11);
          }
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: uchar[3] * mippal@[???]
                       Unresolved local var: ushort[4] * texpal@[???]
                       Unresolved local var: texture_t * tex@[???] */
          if (((ad_enabled != 0) && (iVar20 = Q_stricmp(ptVar11->name,"DEFAULT"), iVar20 == 0)) &&
             (tested != 0)) {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: uchar[3] * mippal@[???]
                       Unresolved local var: ushort[4] * texpal@[???]
                       Unresolved local var: texture_t * tex@[???] */
            iVar20 = Draw_CacheIndex(&ad_wad,"img");
            pvVar14 = Draw_CacheGet(&ad_wad,iVar20);
            if ((pvVar14 != (void *)0x0) &&
               (Q_memcpy(ptVar11 + 1,(void *)((int)pvVar14 + 0x40),iVar8), uVar10 != 0)) {
              iVar20 = iVar8 + (int)ptVar11;
              pvVar14 = (void *)((int)pvVar14 + iVar8);
              do {
                *(undefined2 *)(iVar20 + 0x48) = 0;
                iVar16 = iVar20 + 8;
                *(ushort *)(iVar20 + 0x46) = (ushort)*(byte *)((int)pvVar14 + 0x42);
                *(ushort *)(iVar20 + 0x44) = (ushort)*(byte *)((int)pvVar14 + 0x43);
                *(ushort *)(iVar20 + 0x42) = (ushort)*(byte *)((int)pvVar14 + 0x44);
                iVar20 = iVar16;
                pvVar14 = (void *)((int)pvVar14 + 3);
              } while (iVar16 != (int)ptVar11 + iVar8 + uVar10 * 8);
            }
          }
        }
LAB_00061a6e:
        iVar6 = *piVar5;
        iVar19 = iVar19 + 1;
      } while (iVar19 < iVar6);
      if (bVar2) {
        TEX_CleanupWadInfo();
        iVar6 = *piVar5;
      }
      if (0 < iVar6) {
        iVar19 = 0;
        do {
          ptVar11 = loadmodel->textures[iVar19];
          if (((ptVar11 != (texture_t *)0x0) && ((ptVar11->name[0] - 0x2bU & 0xfd) == 0)) &&
             (ptVar11->anim_next == (texture_s *)0x0)) {
            Q_memset(aiStack_553b4,0,0x28);
            Q_memset(aiStack_5538c,0,0x28);
            iStack_553c8 = (int)ptVar11->name[1];
            if (iStack_553c8 - 0x61U < 0x1a) {
              iStack_553c8 = iStack_553c8 + -0x20;
            }
            if (iStack_553c8 - 0x30U < 10) {
              aiStack_553b4[iStack_553c8 - 0x30U] = (int)ptVar11;
              iStack_553c8 = iStack_553c8 + -0x2f;
LAB_00061ee9:
              iStack_553e0 = 0;
              if (iVar19 + 1 < *piVar5) {
LAB_00061f05:
                iVar20 = iVar19 + 1;
                iVar8 = iVar20 * 4;
                do {
                  pcVar12 = *(char **)((int)loadmodel->textures + iVar8);
                  iVar16 = iStack_553e0;
                  iVar4 = iStack_553c8;
                  if (((pcVar12 != (char *)0x0) && ((*pcVar12 - 0x2bU & 0xfd) == 0)) &&
                     (iVar15 = Q_strcmp(pcVar12 + 2,ptVar11->name + 2), iVar15 == 0)) {
                    iVar15 = (int)pcVar12[1];
                    if (iVar15 - 0x61U < 0x1a) {
                      iVar15 = iVar15 + -0x20;
                    }
                    uVar10 = iVar15 - 0x30;
                    if (uVar10 < 10) {
                      aiStack_553b4[uVar10] = (int)pcVar12;
                      iVar4 = iVar15 + -0x2f;
                      if ((int)uVar10 < iStack_553c8) {
                        iVar4 = iStack_553c8;
                      }
                    }
                    else {
                      uVar10 = iVar15 - 0x41;
                      if (uVar10 < 10) {
                        aiStack_5538c[uVar10] = (int)pcVar12;
                        iVar16 = iVar15 + -0x40;
                        if ((int)uVar10 < iStack_553e0) {
                          iVar16 = iStack_553e0;
                        }
                      }
                      else {
                        Sys_Error("Bad animating texture %s",ptVar11);
                      }
                    }
                  }
                  iStack_553c8 = iVar4;
                  iStack_553e0 = iVar16;
                  iVar20 = iVar20 + 1;
                  iVar8 = iVar8 + 4;
                } while (iVar20 < *piVar5);
                if (iStack_553c8 < 1) {
                  if (iStack_553e0 != 0) goto LAB_00062565;
                }
                else {
LAB_00061fd8:
                  iVar8 = aiStack_553b4[0];
                  if (aiStack_553b4[0] == 0) {
                    Sys_Error("Missing frame %i of %s",0);
                  }
                  *(int *)(iVar8 + 0x18) = iStack_553c8;
                  *(undefined4 *)(iVar8 + 0x1c) = 0;
                  *(undefined4 *)(iVar8 + 0x20) = 1;
                  *(int *)(iVar8 + 0x24) = aiStack_553b4[(int)(1 % (longlong)iStack_553c8)];
                  if (iStack_553e0 != 0) {
                    *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                    if (iStack_553c8 != 1) {
                      if (aiStack_553b4[1] == 0) goto LAB_00062828;
                      *(int *)(aiStack_553b4[1] + 0x18) = iStack_553c8;
                      *(undefined4 *)(aiStack_553b4[1] + 0x1c) = 1;
                      *(undefined4 *)(aiStack_553b4[1] + 0x20) = 2;
                      *(int *)(aiStack_553b4[1] + 0x24) =
                           aiStack_553b4[(int)(2 % (longlong)iStack_553c8)];
                      iVar8 = aiStack_553b4[1];
LAB_0006204c:
                      *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                      if (iStack_553c8 != 2) {
                        if (aiStack_553b4[2] == 0) goto LAB_00062a36;
                        *(int *)(aiStack_553b4[2] + 0x18) = iStack_553c8;
                        *(undefined4 *)(aiStack_553b4[2] + 0x1c) = 2;
                        *(undefined4 *)(aiStack_553b4[2] + 0x20) = 3;
                        *(int *)(aiStack_553b4[2] + 0x24) =
                             aiStack_553b4[(int)(3 % (longlong)iStack_553c8)];
                        iVar8 = aiStack_553b4[2];
LAB_00062088:
                        *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                        if (iStack_553c8 != 3) {
                          if (aiStack_553b4[3] == 0) goto LAB_000627d1;
                          *(int *)(aiStack_553b4[3] + 0x18) = iStack_553c8;
                          *(undefined4 *)(aiStack_553b4[3] + 0x1c) = 3;
                          *(undefined4 *)(aiStack_553b4[3] + 0x20) = 4;
                          *(int *)(aiStack_553b4[3] + 0x24) =
                               aiStack_553b4[(int)(4 % (longlong)iStack_553c8)];
                          iVar8 = aiStack_553b4[3];
LAB_000620c4:
                          *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                          if (iStack_553c8 != 4) {
                            if (aiStack_553b4[4] == 0) goto LAB_0006292d;
                            *(int *)(aiStack_553b4[4] + 0x18) = iStack_553c8;
                            *(undefined4 *)(aiStack_553b4[4] + 0x1c) = 4;
                            *(undefined4 *)(aiStack_553b4[4] + 0x20) = 5;
                            *(int *)(aiStack_553b4[4] + 0x24) =
                                 aiStack_553b4[(int)(5 % (longlong)iStack_553c8)];
                            iVar8 = aiStack_553b4[4];
LAB_00062100:
                            *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                            if (iStack_553c8 != 5) {
                              if (aiStack_553b4[5] == 0) goto LAB_000628d6;
                              *(int *)(aiStack_553b4[5] + 0x18) = iStack_553c8;
                              *(undefined4 *)(aiStack_553b4[5] + 0x1c) = 5;
                              *(undefined4 *)(aiStack_553b4[5] + 0x20) = 6;
                              *(int *)(aiStack_553b4[5] + 0x24) =
                                   aiStack_553b4[(int)(6 % (longlong)iStack_553c8)];
                              iVar8 = aiStack_553b4[5];
LAB_0006213c:
                              *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                              if (iStack_553c8 != 6) {
                                if (aiStack_553b4[6] == 0) goto LAB_000629df;
                                *(int *)(aiStack_553b4[6] + 0x18) = iStack_553c8;
                                *(undefined4 *)(aiStack_553b4[6] + 0x1c) = 6;
                                *(undefined4 *)(aiStack_553b4[6] + 0x20) = 7;
                                *(int *)(aiStack_553b4[6] + 0x24) =
                                     aiStack_553b4[(int)(7 % (longlong)iStack_553c8)];
                                iVar8 = aiStack_553b4[6];
LAB_00062178:
                                *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                                if (iStack_553c8 != 7) {
                                  if (aiStack_553b4[7] == 0) goto LAB_00062986;
                                  *(int *)(aiStack_553b4[7] + 0x18) = iStack_553c8;
                                  *(undefined4 *)(aiStack_553b4[7] + 0x1c) = 7;
                                  *(undefined4 *)(aiStack_553b4[7] + 0x20) = 8;
                                  *(int *)(aiStack_553b4[7] + 0x24) =
                                       aiStack_553b4[(int)(8 % (longlong)iStack_553c8)];
                                  iVar8 = aiStack_553b4[7];
LAB_000621b4:
                                  *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                                  if (iStack_553c8 != 8) {
                                    if (aiStack_553b4[8] == 0) goto LAB_0006287f;
                                    *(int *)(aiStack_553b4[8] + 0x18) = iStack_553c8;
                                    *(undefined4 *)(aiStack_553b4[8] + 0x1c) = 8;
                                    *(undefined4 *)(aiStack_553b4[8] + 0x20) = 9;
                                    *(int *)(aiStack_553b4[8] + 0x24) =
                                         aiStack_553b4[(int)(9 % (longlong)iStack_553c8)];
                                    iVar8 = aiStack_553b4[8];
LAB_000621ec:
                                    *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                                    if (iStack_553c8 != 9) {
                                      if (aiStack_553b4[9] == 0) goto LAB_00062a8f;
                                      *(int *)(aiStack_553b4[9] + 0x18) = iStack_553c8;
                                      *(undefined4 *)(aiStack_553b4[9] + 0x1c) = 9;
                                      *(undefined4 *)(aiStack_553b4[9] + 0x20) = 10;
                                      *(int *)(aiStack_553b4[9] + 0x24) =
                                           aiStack_553b4[(int)(10 % (longlong)iStack_553c8)];
                                      iVar8 = aiStack_553b4[9];
LAB_00062224:
                                      iStack_553c8 = 10;
                                      *(int *)(iVar8 + 0x28) = aiStack_5538c[0];
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    if (aiStack_5538c[0] == 0) goto LAB_00062238;
                    *(undefined4 *)(aiStack_5538c[0] + 0x1c) = 0;
                    *(undefined4 *)(aiStack_5538c[0] + 0x20) = 1;
                    *(int *)(aiStack_5538c[0] + 0x18) = iStack_553e0;
                    *(int *)(aiStack_5538c[0] + 0x24) =
                         aiStack_5538c[(int)(1 % (longlong)iStack_553e0)];
                    iStack_553d4 = aiStack_5538c[0];
                    goto LAB_00062786;
                  }
                  if (iStack_553c8 != 1) {
                    if (aiStack_553b4[1] == 0) {
LAB_00062828:
                      Sys_Error("Missing frame %i of %s",1);
                      _DAT_0000001c = 1;
                      _DAT_00000020 = 2;
                      _DAT_00000024 = aiStack_553b4[(int)(2 % (longlong)iStack_553c8)];
                      _DAT_00000018 = iStack_553c8;
                      if (iStack_553e0 != 0) {
                        iVar8 = 0;
                        goto LAB_0006204c;
                      }
                    }
                    else {
                      *(int *)(aiStack_553b4[1] + 0x18) = iStack_553c8;
                      *(undefined4 *)(aiStack_553b4[1] + 0x1c) = 1;
                      *(undefined4 *)(aiStack_553b4[1] + 0x20) = 2;
                      *(int *)(aiStack_553b4[1] + 0x24) =
                           aiStack_553b4[(int)(2 % (longlong)iStack_553c8)];
                    }
                    if (iStack_553c8 != 2) {
                      if (aiStack_553b4[2] == 0) {
LAB_00062a36:
                        Sys_Error("Missing frame %i of %s",2);
                        _DAT_0000001c = 2;
                        _DAT_00000020 = 3;
                        _DAT_00000024 = aiStack_553b4[(int)(3 % (longlong)iStack_553c8)];
                        _DAT_00000018 = iStack_553c8;
                        if (iStack_553e0 != 0) {
                          iVar8 = 0;
                          goto LAB_00062088;
                        }
                      }
                      else {
                        *(int *)(aiStack_553b4[2] + 0x18) = iStack_553c8;
                        *(undefined4 *)(aiStack_553b4[2] + 0x1c) = 2;
                        *(undefined4 *)(aiStack_553b4[2] + 0x20) = 3;
                        *(int *)(aiStack_553b4[2] + 0x24) =
                             aiStack_553b4[(int)(3 % (longlong)iStack_553c8)];
                      }
                      if (iStack_553c8 != 3) {
                        if (aiStack_553b4[3] == 0) {
LAB_000627d1:
                          Sys_Error("Missing frame %i of %s",3);
                          _DAT_0000001c = 3;
                          _DAT_00000020 = 4;
                          _DAT_00000024 = aiStack_553b4[(int)(4 % (longlong)iStack_553c8)];
                          _DAT_00000018 = iStack_553c8;
                          if (iStack_553e0 != 0) {
                            iVar8 = 0;
                            goto LAB_000620c4;
                          }
                        }
                        else {
                          *(int *)(aiStack_553b4[3] + 0x18) = iStack_553c8;
                          *(undefined4 *)(aiStack_553b4[3] + 0x1c) = 3;
                          *(undefined4 *)(aiStack_553b4[3] + 0x20) = 4;
                          *(int *)(aiStack_553b4[3] + 0x24) =
                               aiStack_553b4[(int)(4 % (longlong)iStack_553c8)];
                        }
                        if (iStack_553c8 != 4) {
                          if (aiStack_553b4[4] == 0) {
LAB_0006292d:
                            Sys_Error("Missing frame %i of %s",4);
                            _DAT_0000001c = 4;
                            _DAT_00000020 = 5;
                            _DAT_00000024 = aiStack_553b4[(int)(5 % (longlong)iStack_553c8)];
                            _DAT_00000018 = iStack_553c8;
                            if (iStack_553e0 != 0) {
                              iVar8 = 0;
                              goto LAB_00062100;
                            }
                          }
                          else {
                            *(int *)(aiStack_553b4[4] + 0x18) = iStack_553c8;
                            *(undefined4 *)(aiStack_553b4[4] + 0x1c) = 4;
                            *(undefined4 *)(aiStack_553b4[4] + 0x20) = 5;
                            *(int *)(aiStack_553b4[4] + 0x24) =
                                 aiStack_553b4[(int)(5 % (longlong)iStack_553c8)];
                          }
                          if (iStack_553c8 != 5) {
                            if (aiStack_553b4[5] == 0) {
LAB_000628d6:
                              Sys_Error("Missing frame %i of %s",5);
                              _DAT_0000001c = 5;
                              _DAT_00000020 = 6;
                              _DAT_00000024 = aiStack_553b4[(int)(6 % (longlong)iStack_553c8)];
                              _DAT_00000018 = iStack_553c8;
                              if (iStack_553e0 != 0) {
                                iVar8 = 0;
                                goto LAB_0006213c;
                              }
                            }
                            else {
                              *(int *)(aiStack_553b4[5] + 0x18) = iStack_553c8;
                              *(undefined4 *)(aiStack_553b4[5] + 0x1c) = 5;
                              *(undefined4 *)(aiStack_553b4[5] + 0x20) = 6;
                              *(int *)(aiStack_553b4[5] + 0x24) =
                                   aiStack_553b4[(int)(6 % (longlong)iStack_553c8)];
                            }
                            if (iStack_553c8 != 6) {
                              if (aiStack_553b4[6] == 0) {
LAB_000629df:
                                Sys_Error("Missing frame %i of %s",6);
                                _DAT_0000001c = 6;
                                _DAT_00000020 = 7;
                                _DAT_00000024 = aiStack_553b4[(int)(7 % (longlong)iStack_553c8)];
                                _DAT_00000018 = iStack_553c8;
                                if (iStack_553e0 != 0) {
                                  iVar8 = 0;
                                  goto LAB_00062178;
                                }
                              }
                              else {
                                *(int *)(aiStack_553b4[6] + 0x18) = iStack_553c8;
                                *(undefined4 *)(aiStack_553b4[6] + 0x1c) = 6;
                                *(undefined4 *)(aiStack_553b4[6] + 0x20) = 7;
                                *(int *)(aiStack_553b4[6] + 0x24) =
                                     aiStack_553b4[(int)(7 % (longlong)iStack_553c8)];
                              }
                              if (iStack_553c8 != 7) {
                                if (aiStack_553b4[7] == 0) {
LAB_00062986:
                                  Sys_Error("Missing frame %i of %s",7);
                                  _DAT_0000001c = 7;
                                  _DAT_00000020 = 8;
                                  _DAT_00000024 = aiStack_553b4[(int)(8 % (longlong)iStack_553c8)];
                                  _DAT_00000018 = iStack_553c8;
                                  if (iStack_553e0 != 0) {
                                    iVar8 = 0;
                                    goto LAB_000621b4;
                                  }
                                }
                                else {
                                  *(int *)(aiStack_553b4[7] + 0x18) = iStack_553c8;
                                  *(undefined4 *)(aiStack_553b4[7] + 0x1c) = 7;
                                  *(undefined4 *)(aiStack_553b4[7] + 0x20) = 8;
                                  *(int *)(aiStack_553b4[7] + 0x24) =
                                       aiStack_553b4[(int)(8 % (longlong)iStack_553c8)];
                                }
                                if (iStack_553c8 != 8) {
                                  if (aiStack_553b4[8] == 0) {
LAB_0006287f:
                                    Sys_Error("Missing frame %i of %s",8);
                                    _DAT_0000001c = 8;
                                    _DAT_00000020 = 9;
                                    _DAT_00000024 = aiStack_553b4[(int)(9 % (longlong)iStack_553c8)]
                                    ;
                                    _DAT_00000018 = iStack_553c8;
                                    if (iStack_553e0 != 0) {
                                      iVar8 = 0;
                                      goto LAB_000621ec;
                                    }
                                  }
                                  else {
                                    *(int *)(aiStack_553b4[8] + 0x18) = iStack_553c8;
                                    *(undefined4 *)(aiStack_553b4[8] + 0x1c) = 8;
                                    *(undefined4 *)(aiStack_553b4[8] + 0x20) = 9;
                                    *(int *)(aiStack_553b4[8] + 0x24) =
                                         aiStack_553b4[(int)(9 % (longlong)iStack_553c8)];
                                  }
                                  if (iStack_553c8 != 9) {
                                    if (aiStack_553b4[9] == 0) {
LAB_00062a8f:
                                      Sys_Error("Missing frame %i of %s",9);
                                      _DAT_0000001c = 9;
                                      _DAT_00000020 = 10;
                                      _DAT_00000024 =
                                           aiStack_553b4[(int)(10 % (longlong)iStack_553c8)];
                                      _DAT_00000018 = iStack_553c8;
                                      if (iStack_553e0 != 0) {
                                        iVar8 = 0;
                                        goto LAB_00062224;
                                      }
                                    }
                                    else {
                                      *(int *)(aiStack_553b4[9] + 0x18) = iStack_553c8;
                                      *(undefined4 *)(aiStack_553b4[9] + 0x1c) = 9;
                                      *(undefined4 *)(aiStack_553b4[9] + 0x20) = 10;
                                      *(int *)(aiStack_553b4[9] + 0x24) =
                                           aiStack_553b4[(int)(10 % (longlong)iStack_553c8)];
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (0 < iStack_553c8) goto LAB_00061fd8;
            }
            else {
              if (9 < iStack_553c8 - 0x41U) {
                Sys_Error("Bad animating texture %s",ptVar11);
                goto LAB_00061ee9;
              }
              aiStack_5538c[iStack_553c8 - 0x41U] = (int)ptVar11;
              iStack_553e0 = iStack_553c8 + -0x40;
              iStack_553c8 = 0;
              if (iVar19 + 1 < *piVar5) goto LAB_00061f05;
              iStack_553c8 = 0;
LAB_00062565:
              iStack_553d4 = aiStack_5538c[0];
              if (aiStack_5538c[0] == 0) {
LAB_00062238:
                Sys_Error("Missing frame %i of %s",0);
                iStack_553d4 = 0;
              }
              *(undefined4 *)(iStack_553d4 + 0x1c) = 0;
              *(undefined4 *)(iStack_553d4 + 0x20) = 1;
              *(int *)(iStack_553d4 + 0x18) = iStack_553e0;
              *(int *)(iStack_553d4 + 0x24) = aiStack_5538c[(int)(1 % (longlong)iStack_553e0)];
              if (iStack_553c8 != 0) {
LAB_00062786:
                *(int *)(iStack_553d4 + 0x28) = aiStack_553b4[0];
              }
              iVar8 = aiStack_5538c[1];
              if (iStack_553e0 != 1) {
                if (aiStack_5538c[1] == 0) {
                  Sys_Error("Missing frame %i of %s",1);
                }
                iVar20 = aiStack_5538c[2];
                *(undefined4 *)(iVar8 + 0x1c) = 1;
                *(undefined4 *)(iVar8 + 0x20) = 2;
                *(int *)(iVar8 + 0x18) = iStack_553e0;
                *(int *)(iVar8 + 0x24) = aiStack_5538c[(int)(2 % (longlong)iStack_553e0)];
                if (iStack_553c8 != 0) {
                  *(int *)(iVar8 + 0x28) = aiStack_553b4[0];
                }
                if (iStack_553e0 != 2) {
                  if (aiStack_5538c[2] == 0) {
                    Sys_Error("Missing frame %i of %s",2);
                  }
                  iVar8 = aiStack_5538c[3];
                  *(undefined4 *)(iVar20 + 0x1c) = 2;
                  *(undefined4 *)(iVar20 + 0x20) = 3;
                  *(int *)(iVar20 + 0x18) = iStack_553e0;
                  *(int *)(iVar20 + 0x24) = aiStack_5538c[(int)(3 % (longlong)iStack_553e0)];
                  if (iStack_553c8 != 0) {
                    *(int *)(iVar20 + 0x28) = aiStack_553b4[0];
                  }
                  if (iStack_553e0 != 3) {
                    if (aiStack_5538c[3] == 0) {
                      Sys_Error("Missing frame %i of %s",3);
                    }
                    iVar20 = aiStack_5538c[4];
                    *(undefined4 *)(iVar8 + 0x1c) = 3;
                    *(undefined4 *)(iVar8 + 0x20) = 4;
                    *(int *)(iVar8 + 0x18) = iStack_553e0;
                    *(int *)(iVar8 + 0x24) = aiStack_5538c[(int)(4 % (longlong)iStack_553e0)];
                    if (iStack_553c8 != 0) {
                      *(int *)(iVar8 + 0x28) = aiStack_553b4[0];
                    }
                    if (iStack_553e0 != 4) {
                      if (aiStack_5538c[4] == 0) {
                        Sys_Error("Missing frame %i of %s",4);
                      }
                      iVar8 = aiStack_5538c[5];
                      *(undefined4 *)(iVar20 + 0x1c) = 4;
                      *(undefined4 *)(iVar20 + 0x20) = 5;
                      *(int *)(iVar20 + 0x18) = iStack_553e0;
                      *(int *)(iVar20 + 0x24) = aiStack_5538c[(int)(5 % (longlong)iStack_553e0)];
                      if (iStack_553c8 != 0) {
                        *(int *)(iVar20 + 0x28) = aiStack_553b4[0];
                      }
                      if (iStack_553e0 != 5) {
                        if (aiStack_5538c[5] == 0) {
                          Sys_Error("Missing frame %i of %s",5);
                        }
                        iVar20 = aiStack_5538c[6];
                        *(undefined4 *)(iVar8 + 0x1c) = 5;
                        *(undefined4 *)(iVar8 + 0x20) = 6;
                        *(int *)(iVar8 + 0x18) = iStack_553e0;
                        *(int *)(iVar8 + 0x24) = aiStack_5538c[(int)(6 % (longlong)iStack_553e0)];
                        if (iStack_553c8 != 0) {
                          *(int *)(iVar8 + 0x28) = aiStack_553b4[0];
                        }
                        if (iStack_553e0 != 6) {
                          if (aiStack_5538c[6] == 0) {
                            Sys_Error("Missing frame %i of %s",6);
                          }
                          iVar8 = aiStack_5538c[7];
                          *(undefined4 *)(iVar20 + 0x1c) = 6;
                          *(undefined4 *)(iVar20 + 0x20) = 7;
                          *(int *)(iVar20 + 0x18) = iStack_553e0;
                          *(int *)(iVar20 + 0x24) = aiStack_5538c[(int)(7 % (longlong)iStack_553e0)]
                          ;
                          if (iStack_553c8 != 0) {
                            *(int *)(iVar20 + 0x28) = aiStack_553b4[0];
                          }
                          if (iStack_553e0 != 7) {
                            if (aiStack_5538c[7] == 0) {
                              Sys_Error("Missing frame %i of %s",7);
                            }
                            iVar20 = aiStack_5538c[8];
                            *(undefined4 *)(iVar8 + 0x1c) = 7;
                            *(undefined4 *)(iVar8 + 0x20) = 8;
                            *(int *)(iVar8 + 0x18) = iStack_553e0;
                            *(int *)(iVar8 + 0x24) =
                                 aiStack_5538c[(int)(8 % (longlong)iStack_553e0)];
                            if (iStack_553c8 != 0) {
                              *(int *)(iVar8 + 0x28) = aiStack_553b4[0];
                            }
                            if (iStack_553e0 != 8) {
                              if (aiStack_5538c[8] == 0) {
                                Sys_Error("Missing frame %i of %s",8);
                              }
                              iVar8 = aiStack_5538c[9];
                              *(undefined4 *)(iVar20 + 0x1c) = 8;
                              *(undefined4 *)(iVar20 + 0x20) = 9;
                              *(int *)(iVar20 + 0x18) = iStack_553e0;
                              *(int *)(iVar20 + 0x24) =
                                   aiStack_5538c[(int)(9 % (longlong)iStack_553e0)];
                              if (iStack_553c8 != 0) {
                                *(int *)(iVar20 + 0x28) = aiStack_553b4[0];
                              }
                              if (iStack_553e0 == 10) {
                                if (aiStack_5538c[9] == 0) {
                                  Sys_Error("Missing frame %i of %s",9);
                                }
                                *(undefined4 *)(iVar8 + 0x18) = 10;
                                *(undefined4 *)(iVar8 + 0x1c) = 9;
                                *(undefined4 *)(iVar8 + 0x20) = 10;
                                *(int *)(iVar8 + 0x24) = aiStack_5538c[0];
                                if (iStack_553c8 != 0) {
                                  *(int *)(iVar8 + 0x28) = aiStack_553b4[0];
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            iVar6 = *piVar5;
          }
          iVar19 = iVar19 + 1;
        } while (iVar19 < iVar6);
      }
    }
    dVar22 = Sys_FloatTime();
    Con_DPrintf("Texture load: %6.1fms\n",(dVar22 - dVar21) * 1000.0);
  }
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Mod_LoadVertexes  @ 00062e50
void Mod_LoadVertexes(lump_t *l)

{
  model_t *pmVar1;
  mvertex_t *pmVar2;
  uint uVar3;
  float *pfVar4;
  uint uVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: dvertex_t * in@[???]
                       Unresolved local var: mvertex_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  uVar3 = l->filelen;
  pfVar4 = (float *)(mod_base + l->fileofs);
  if (uVar3 != (uVar3 / 0xc) * 0xc) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar3 = l->filelen;
  }
  uVar5 = 0;
  uVar3 = uVar3 / 0xc;
  pmVar2 = Hunk_AllocName(uVar3 * 0xc,loadname);
  pmVar1 = loadmodel;
  loadmodel->vertexes = pmVar2;
  pmVar1->numvertexes = uVar3;
  if (uVar3 != 0) {
    do {
      uVar5 = uVar5 + 1;
      lVar6 = (longdouble)(*LittleFloat)(*pfVar4);
      pmVar2->position[0] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(pfVar4[1]);
      pmVar2->position[1] = (float)lVar6;
      lVar6 = (longdouble)(*LittleFloat)(pfVar4[2]);
      pmVar2->position[2] = (float)lVar6;
      pfVar4 = pfVar4 + 3;
      pmVar2 = pmVar2 + 1;
    } while (uVar3 != uVar5);
  }
  return;
}


// Mod_LoadVisibility  @ 00062ce0
void Mod_LoadVisibility(lump_t *l)

{
  byte *pbVar1;
  model_t *pmVar2;
  byte *pbVar3;
  
  pmVar2 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->visdata = (byte *)0x0;
    return;
  }
  pbVar3 = Hunk_AllocName(l->filelen,loadname);
  pbVar1 = mod_base;
  pmVar2->visdata = pbVar3;
  Q_memcpy(loadmodel->visdata,pbVar1 + l->fileofs,l->filelen);
  return;
}


// Mod_MakeHull0  @ 00064070
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_MakeHull0(void)

{
  int iVar1;
  model_t *pmVar2;
  dclipnode_t *pdVar3;
  int iVar4;
  mnode_s *pmVar5;
  mnode_t *pmVar6;
  model_t *pmVar7;
  int iVar8;
  
                    /* Unresolved local var: mnode_t * in@[???]
                       Unresolved local var: mnode_t * child@[???]
                       Unresolved local var: dclipnode_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: hull_t * hull@[???] */
  pmVar2 = loadmodel;
  iVar1 = loadmodel->numnodes;
  pmVar6 = loadmodel->nodes;
  pdVar3 = Hunk_AllocName(iVar1 * 8,loadname);
  pmVar7 = loadmodel;
  pmVar2->hulls[0].firstclipnode = 0;
  pmVar2->hulls[0].lastclipnode = iVar1 + -1;
  pmVar2->hulls[0].clipnodes = pdVar3;
  pmVar2->hulls[0].planes = pmVar7->planes;
  if (iVar1 < 1) {
    return;
  }
  iVar4 = 0;
  do {
    pdVar3->planenum = ((int)pmVar6->plane - (int)pmVar7->planes >> 2) * -0x33333333;
    iVar8 = pmVar6->children[0]->contents;
    if (iVar8 < 0) {
      pdVar3->children[0] = (short)iVar8;
      pmVar5 = pmVar6->children[1];
      iVar8 = pmVar5->contents;
      if (iVar8 < 0) goto LAB_00064165;
LAB_00064107:
      pdVar3->children[1] = (short)((int)pmVar5 - (int)loadmodel->nodes >> 3) * -0x3333;
      pmVar7 = loadmodel;
    }
    else {
      pdVar3->children[0] = (short)((int)pmVar6->children[0] - (int)loadmodel->nodes >> 3) * -0x3333
      ;
      pmVar5 = pmVar6->children[1];
      iVar8 = pmVar5->contents;
      if (-1 < iVar8) goto LAB_00064107;
LAB_00064165:
      pdVar3->children[1] = (short)iVar8;
      pmVar7 = loadmodel;
    }
    if (iVar1 == iVar4 + 1) {
      loadmodel = pmVar7;
      return;
    }
    pmVar6 = pmVar6 + 1;
    iVar4 = iVar4 + 1;
    pdVar3 = pdVar3 + 1;
    loadmodel = pmVar7;
  } while( true );
}


// Mod_MarkClient  @ 000617b0
void Mod_MarkClient(model_t *pModel)

{
  pModel->needload = 3;
  return;
}


// Mod_NeedCRC  @ 00061770
void Mod_NeedCRC(char *name,qboolean needCRC)

{
  model_t *pmVar1;
  
                    /* Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  pmVar1 = Mod_FindName(false,name);
  *(qboolean *)
   ((int)mod_known_info + ((int)(pmVar1[-0x1ecd].hulls[0].clip_mins + 2) >> 3) * 0x397829cc) =
       needCRC;
  return;
}


// Mod_PointInLeaf  @ 00061450
mleaf_t * Mod_PointInLeaf(vec_t *p,model_t *model)

{
  float *pfVar1;
  float fVar2;
  mleaf_t *pmVar3;
  
                    /* Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: mplane_t * plane@[???] */
  if ((model == (model_t *)0x0) || (pmVar3 = (mleaf_t *)model->nodes, pmVar3 == (mleaf_t *)0x0)) {
    Sys_Error("Mod_PointInLeaf: bad model");
    pmVar3 = (mleaf_t *)model->nodes;
  }
  do {
    if (pmVar3->contents < 0) {
      return pmVar3;
    }
    while( true ) {
      pfVar1 = (float *)pmVar3->compressed_vis;
      if (*(byte *)(pfVar1 + 4) < 3) {
        fVar2 = p[*(byte *)(pfVar1 + 4)] - pfVar1[3];
      }
      else {
        fVar2 = (p[2] * pfVar1[2] + p[1] * pfVar1[1] + *p * *pfVar1) - pfVar1[3];
      }
      if (fVar2 <= 0.0) break;
      pmVar3 = (mleaf_t *)pmVar3->efrags;
      if ((int)pmVar3->contents < 0) {
        return pmVar3;
      }
    }
    pmVar3 = (mleaf_t *)pmVar3->firstmarksurface;
  } while( true );
}


// Mod_Print  @ 00066160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_Print(void)

{
  qboolean qVar1;
  model_t *pmVar2;
  int iVar3;
  void *pvVar4;
  model_t *pmVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???] */
  Con_Printf("Cached models:\n");
  if (0 < mod_numknown) {
    pmVar2 = mod_known;
    iVar3 = 0;
    do {
      pvVar4 = (pmVar2->cache).data;
      pmVar5 = pmVar2;
      Con_Printf("%8p : %s",pvVar4,pmVar2);
      qVar1 = pmVar2->needload;
      if ((qVar1 & 2) != false) {
        Con_Printf(" (!R)",pvVar4,pmVar5);
        qVar1 = pmVar2->needload;
      }
      if ((qVar1 & true) != false) {
        Con_Printf(" (!P)",pvVar4,pmVar5);
      }
      iVar3 = iVar3 + 1;
      pmVar2 = pmVar2 + 1;
      Con_Printf("\n",pvVar4,pmVar5);
    } while (iVar3 < mod_numknown);
  }
  return;
}


// Mod_SetParent  @ 00063980
void Mod_SetParent(mnode_t *node,mnode_t *parent)

{
  int iVar1;
  mnode_s *pmVar2;
  mnode_s *pmVar3;
  mnode_s *pmVar4;
  mnode_s *pmVar5;
  mnode_s *pmVar6;
  mnode_s *pmVar7;
  mnode_s *pmVar8;
  mnode_t *parent_00;
  mnode_s *pmVar9;
  
  node->parent = parent;
  iVar1 = node->contents;
  while (-1 < iVar1) {
    pmVar2 = node->children[0];
    iVar1 = pmVar2->contents;
    pmVar2->parent = node;
    while (-1 < iVar1) {
      pmVar3 = pmVar2->children[0];
      iVar1 = pmVar3->contents;
      pmVar3->parent = pmVar2;
      while (-1 < iVar1) {
        pmVar4 = pmVar3->children[0];
        iVar1 = pmVar4->contents;
        pmVar4->parent = pmVar3;
        while (-1 < iVar1) {
          pmVar5 = pmVar4->children[0];
          iVar1 = pmVar5->contents;
          pmVar5->parent = pmVar4;
          while (-1 < iVar1) {
            pmVar6 = pmVar5->children[0];
            iVar1 = pmVar6->contents;
            pmVar6->parent = pmVar5;
            while (-1 < iVar1) {
              pmVar7 = pmVar6->children[0];
              iVar1 = pmVar7->contents;
              pmVar7->parent = pmVar6;
              while (-1 < iVar1) {
                pmVar8 = pmVar7->children[0];
                iVar1 = pmVar8->contents;
                pmVar8->parent = pmVar7;
                while (-1 < iVar1) {
                  parent_00 = pmVar8->children[0];
                  iVar1 = parent_00->contents;
                  parent_00->parent = pmVar8;
                  while (-1 < iVar1) {
                    Mod_SetParent(parent_00->children[0],parent_00);
                    pmVar9 = parent_00->children[1];
                    pmVar9->parent = parent_00;
                    parent_00 = pmVar9;
                    iVar1 = pmVar9->contents;
                  }
                  pmVar9 = pmVar8->children[1];
                  iVar1 = pmVar9->contents;
                  pmVar9->parent = pmVar8;
                  pmVar8 = pmVar9;
                }
                pmVar8 = pmVar7->children[1];
                iVar1 = pmVar8->contents;
                pmVar8->parent = pmVar7;
                pmVar7 = pmVar8;
              }
              pmVar7 = pmVar6->children[1];
              iVar1 = pmVar7->contents;
              pmVar7->parent = pmVar6;
              pmVar6 = pmVar7;
            }
            pmVar6 = pmVar5->children[1];
            iVar1 = pmVar6->contents;
            pmVar6->parent = pmVar5;
            pmVar5 = pmVar6;
          }
          pmVar5 = pmVar4->children[1];
          iVar1 = pmVar5->contents;
          pmVar5->parent = pmVar4;
          pmVar4 = pmVar5;
        }
        pmVar4 = pmVar3->children[1];
        iVar1 = pmVar4->contents;
        pmVar4->parent = pmVar3;
        pmVar3 = pmVar4;
      }
      pmVar3 = pmVar2->children[1];
      iVar1 = pmVar3->contents;
      pmVar3->parent = pmVar2;
      pmVar2 = pmVar3;
    }
    pmVar2 = node->children[1];
    iVar1 = pmVar2->contents;
    pmVar2->parent = node;
    node = pmVar2;
  }
  return;
}


// Mod_UnloadSpriteTextures  @ 00066140
void Mod_UnloadSpriteTextures(model_t *pModel)

{
  if ((pModel != (model_t *)0x0) && (pModel->type == mod_sprite)) {
    pModel->needload = true;
    return;
  }
  return;
}


// Mod_ValidateCRC  @ 00061710
qboolean Mod_ValidateCRC(char *name,CRC32_t crc)

{
  int iVar1;
  model_t *pmVar2;
  
                    /* Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  pmVar2 = Mod_FindName(true,name);
  iVar1 = ((int)(pmVar2[-0x1ecd].hulls[0].clip_mins + 2) >> 3) * 0x397829cc;
  if (*(int *)((int)mod_known_info + iVar1 + 4) != 0) {
    return (uint)(*(CRC32_t *)((int)mod_known_info + iVar1 + 8) == crc);
  }
  return true;
}


