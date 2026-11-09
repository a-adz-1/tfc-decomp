// Mod_AdInit  @ 00081260
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
      Draw_CacheWadInit(Mod_AdInit::filename,0x10,&ad_wad);
      ad_enabled = 1;
      return;
    }
    Con_Printf("No -ad file specified, skipping\n");
  }
  return;
}


// Mod_AdSwap  @ 00081310
void Mod_AdSwap(texture_t *src,int pixels,int entries)

{
  byte *pbVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  byte *pbVar5;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: uchar[3] * mippal@[???]
                       Unresolved local var: ushort[4] * texpal@[???]
                       Unresolved local var: texture_t * tex@[???] */
  if (tested != 0) {
    iVar2 = Draw_CacheIndex(&ad_wad,"img");
    pvVar3 = Draw_CacheGet(&ad_wad,iVar2);
    if (pvVar3 != (void *)0x0) {
      pcVar4 = src[1].name + pixels + 2;
      pbVar5 = (byte *)(pixels + 0x42 + (int)pvVar3);
      Q_memcpy(src + 1,(void *)((int)pvVar3 + 0x40),pixels);
      if (0 < entries) {
        iVar2 = 0;
        do {
          pcVar4[6] = '\0';
          pcVar4[7] = '\0';
          iVar2 = iVar2 + 1;
          *(ushort *)(pcVar4 + 4) = (ushort)*pbVar5;
          *(ushort *)(pcVar4 + 2) = (ushort)pbVar5[1];
          pbVar1 = pbVar5 + 2;
          pbVar5 = pbVar5 + 3;
          *(ushort *)pcVar4 = (ushort)*pbVar1;
          pcVar4 = pcVar4 + 8;
        } while (iVar2 != entries);
      }
    }
  }
  return;
}


// Mod_ChangeGame  @ 00085260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_ChangeGame(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  model_t *pmVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  if (0 < mod_numknown) {
    pmVar5 = mod_known;
    iVar2 = mod_numknown;
    iVar4 = 0;
    do {
      if (pmVar5->type == mod_studio) {
        pvVar1 = Cache_Check(&pmVar5->cache);
        iVar2 = mod_numknown;
        if (pvVar1 != (void *)0x0) {
          Cache_Free(&pmVar5->cache);
          iVar2 = mod_numknown;
        }
      }
      iVar3 = iVar4 + 1;
      pmVar5 = pmVar5 + 1;
      mod_known_info[iVar4].firstCRCDone = false;
      mod_known_info[iVar4].initialCRC = 0;
      iVar4 = iVar3;
    } while (iVar3 < iVar2);
  }
  return;
}


// Mod_ClearAll  @ 00080fb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_ClearAll(void)

{
  int iVar1;
  model_t *pmVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???] */
  iVar1 = mod_numknown;
  if (0 < mod_numknown) {
    pmVar2 = mod_known;
    iVar3 = 0;
    do {
      while ((pmVar2->needload == 3 || (pmVar2->needload = 2, pmVar2->type != mod_sprite))) {
        iVar3 = iVar3 + 1;
        pmVar2 = pmVar2 + 1;
        if (iVar1 <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      (pmVar2->cache).data = (void *)0x0;
      pmVar2 = pmVar2 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


// Mod_DecompressVis  @ 0005de40
uchar * Mod_DecompressVis(uchar *in,model_t *model)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  uint uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uchar *puVar10;
  
                    /* Unresolved local var: int row@[???] */
  iVar1 = model->numleafs;
  puVar2 = mod_novis;
  if (in != (uchar *)0x0) {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: uchar * out@[???] */
    puVar2 = Mod_DecompressVis::decompressed;
LAB_0005de8e:
    do {
      if (*in == '\0') {
        uVar8 = (uint)in[1];
        in = in + 2;
        if (uVar8 != 0) {
          uVar4 = -(int)puVar2 & 0xfU;
          if (uVar8 < (-(int)puVar2 & 0xfU)) {
            uVar4 = uVar8;
          }
          puVar3 = puVar2;
          uVar9 = uVar8;
          if (uVar4 == 0) {
LAB_0005decf:
            uVar6 = uVar8 - uVar4 >> 4;
            if (uVar6 != 0) {
              pauVar5 = (undefined1 (*) [16])(puVar2 + uVar4);
              uVar7 = 0;
              do {
                uVar7 = uVar7 + 1;
                *pauVar5 = (undefined1  [16])0x0;
                pauVar5 = pauVar5 + 1;
              } while (uVar7 < uVar6);
              uVar9 = uVar9 + uVar6 * -0x10;
              puVar3 = puVar3 + uVar6 * 0x10;
              if (uVar8 - uVar4 == uVar6 * 0x10) goto LAB_0005df28;
            }
            puVar10 = puVar3 + uVar9;
            do {
              *puVar3 = '\0';
              puVar3 = puVar3 + 1;
            } while (puVar3 != puVar10);
          }
          else {
            uVar6 = 0;
            do {
              uVar6 = uVar6 + 1;
              uVar9 = uVar9 - 1;
              *puVar3 = '\0';
              puVar3 = puVar3 + 1;
            } while (uVar6 < uVar4);
            if (uVar8 != uVar4) goto LAB_0005decf;
          }
LAB_0005df28:
          puVar2 = puVar2 + uVar8;
          if (Mod_DecompressVis::decompressed + (iVar1 + 7 >> 3) <= puVar2) break;
          goto LAB_0005de8e;
        }
      }
      else {
        *puVar2 = *in;
        in = in + 1;
        puVar2 = puVar2 + 1;
      }
    } while (puVar2 < Mod_DecompressVis::decompressed + (iVar1 + 7 >> 3));
    puVar2 = Mod_DecompressVis::decompressed;
  }
  return puVar2;
}


// Mod_Extradata  @ 000850f0
void * Mod_Extradata(model_t *mod)

{
  void *pvVar1;
  modtype_t mVar2;
  
                    /* Unresolved local var: void * r@[???] */
  if (mod == (model_t *)0x0) {
    return (void *)0x0;
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
      goto LAB_00085151;
    }
  }
  else if ((mod->needload == 3) || (mod->needload == false)) goto LAB_00085151;
  Mod_LoadModel(mod,true,false);
LAB_00085151:
  pvVar1 = (mod->cache).data;
  if (pvVar1 == (void *)0x0) {
    Sys_Error("Mod_Extradata: caching failed");
    pvVar1 = (mod->cache).data;
  }
  return pvVar1;
}


// Mod_FillInCRCInfo  @ 00081010
void Mod_FillInCRCInfo(qboolean trackCRC,int model_number)

{
                    /* Unresolved local var: mod_known_info_t * p@[DW_OP_reg0(EAX)] */
  mod_known_info[model_number].shouldCRC = trackCRC;
  mod_known_info[model_number].firstCRCDone = false;
  mod_known_info[model_number].initialCRC = 0;
  return;
}


// Mod_FindName  @ 00081040
model_t * Mod_FindName(qboolean trackCRC,char *name)

{
  qboolean qVar1;
  model_t *pmVar2;
  int iVar3;
  model_t *s1;
  model_t *pmVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???]
                       Unresolved local var: model_t * avail@[???] */
  if (*name == '\0') {
    Sys_Error("Mod_ForName: NULL name");
  }
  pmVar4 = (model_t *)0x0;
  iVar5 = 0;
  s1 = mod_known;
  if (0 < mod_numknown) {
    do {
      while( true ) {
        iVar3 = Q_strcasecmp(s1->name,name);
        if (iVar3 == 0) {
          if (iVar5 != mod_numknown) {
            return s1;
          }
          goto LAB_000810d9;
        }
        pmVar2 = pmVar4;
        if ((s1->needload == 2) && (pmVar2 = s1, pmVar4 != (model_t *)0x0)) break;
        pmVar4 = pmVar2;
        iVar5 = iVar5 + 1;
        s1 = s1 + 1;
        if (mod_numknown <= iVar5) goto LAB_000810ba;
      }
      if (1 < s1->type - mod_alias) {
        pmVar4 = s1;
      }
      iVar5 = iVar5 + 1;
      s1 = s1 + 1;
    } while (iVar5 < mod_numknown);
  }
LAB_000810ba:
  if (iVar5 == mod_numknown) {
LAB_000810d9:
    if (iVar5 < 0x400) {
                    /* Unresolved local var: mod_known_info_t * p@[DW_OP_reg0(EAX)] */
      mod_numknown = iVar5 + 1;
      mod_known_info[iVar5].firstCRCDone = false;
      mod_known_info[iVar5].shouldCRC = trackCRC;
      mod_known_info[iVar5].initialCRC = 0;
    }
    else if (pmVar4 == (model_t *)0x0) {
      Sys_Error("mod_numknown >= MAX_KNOWN_MODELS");
    }
    else {
                    /* Unresolved local var: mod_known_info_t * p@[DW_OP_reg0(EAX)] */
      iVar5 = ((int)(pmVar4[-0x1f1b].hulls[1].clip_maxs + 1) >> 3) * 0x397829cc;
      *(undefined4 *)((int)mod_known_info + iVar5 + 4) = 0;
      *(qboolean *)((int)mod_known_info + iVar5) = trackCRC;
      *(undefined4 *)((int)mod_known_info + iVar5 + 8) = 0;
      s1 = pmVar4;
    }
    Q_strncpy(s1->name,name,0x3f);
    qVar1 = s1->needload;
    s1->name[0x3f] = '\0';
    if (qVar1 != 3) {
      s1->needload = true;
      return s1;
    }
  }
  return s1;
}


// Mod_ForName  @ 00085050
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
    if (pmVar1->needload == 3) {
      return pmVar1;
    }
    if (pmVar1->needload == false) {
      return pmVar1;
    }
  }
  pmVar1 = Mod_LoadModel(pmVar1,crash,trackCRC);
  return pmVar1;
}


// Mod_Init  @ 0005de10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_Init(void)

{
  SW_Mod_Init();
  Q_memset(mod_novis,0xff,0x400);
  return;
}


// Mod_LeafPVS  @ 0005df50
uchar * Mod_LeafPVS(mleaf_t *leaf,model_t *model)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  uint uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uchar *puVar10;
  uchar *puVar11;
  
  puVar2 = mod_novis;
  if (model->leafs != leaf) {
    if (gPVS == (uchar *)0x0) {
      puVar11 = leaf->compressed_vis;
                    /* Unresolved local var: int row@[???] */
      iVar1 = model->numleafs;
      if (puVar11 != (uchar *)0x0) {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: uchar * out@[???] */
        puVar2 = Mod_DecompressVis::decompressed;
        do {
          if (*puVar11 == '\0') {
            uVar8 = (uint)puVar11[1];
            puVar11 = puVar11 + 2;
            if (uVar8 != 0) {
              uVar4 = -(int)puVar2 & 0xfU;
              if (uVar8 < (-(int)puVar2 & 0xfU)) {
                uVar4 = uVar8;
              }
              puVar3 = puVar2;
              uVar9 = uVar8;
              if (uVar4 == 0) {
LAB_0005e02f:
                uVar6 = uVar8 - uVar4 >> 4;
                if (uVar6 != 0) {
                  pauVar5 = (undefined1 (*) [16])(puVar2 + uVar4);
                  uVar7 = 0;
                  do {
                    uVar7 = uVar7 + 1;
                    *pauVar5 = (undefined1  [16])0x0;
                    pauVar5 = pauVar5 + 1;
                  } while (uVar7 < uVar6);
                  uVar9 = uVar9 + uVar6 * -0x10;
                  puVar3 = puVar3 + uVar6 * 0x10;
                  if (uVar8 - uVar4 == uVar6 * 0x10) goto LAB_0005e088;
                }
                puVar10 = puVar3 + uVar9;
                do {
                  *puVar3 = '\0';
                  puVar3 = puVar3 + 1;
                } while (puVar3 != puVar10);
              }
              else {
                uVar6 = 0;
                do {
                  uVar6 = uVar6 + 1;
                  uVar9 = uVar9 - 1;
                  *puVar3 = '\0';
                  puVar3 = puVar3 + 1;
                } while (uVar6 < uVar4);
                if (uVar4 != uVar8) goto LAB_0005e02f;
              }
LAB_0005e088:
              puVar2 = puVar2 + uVar8;
            }
          }
          else {
            *puVar2 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar2 = puVar2 + 1;
          }
        } while (puVar2 < Mod_DecompressVis::decompressed + (iVar1 + 7 >> 3));
        puVar2 = Mod_DecompressVis::decompressed;
      }
    }
    else {
                    /* Unresolved local var: int leafnum@[???] */
      puVar2 = gPVS + ((int)leaf - (int)model->leafs >> 4) * -0x55555555 * gPVSRowBytes;
    }
  }
  return puVar2;
}


// Mod_LoadAliasFrame  @ 00083c80
void * Mod_LoadAliasFrame(void *pin,int *pframeindex,int numv,trivertx_t *pbboxmin,
                         trivertx_t *pbboxmax,aliashdr_t *pheader,char *name)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  uint uVar13;
  
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
  pvVar7 = Hunk_AllocName(numv * 4,loadname);
  *pframeindex = (int)pvVar7 - (int)pheader;
  if (numv < 1) goto LAB_00083da5;
  uVar8 = (uint)numv >> 2;
  iVar10 = uVar8 << 2;
  if (uVar8 == 0) {
LAB_00083db3:
    iVar10 = 0;
  }
  else {
    if ((uint)numv < 4 ||
        pvVar7 <= (void *)((int)pin + 0x28U) && (int)pin + 0x18U <= (int)pvVar7 + 0x10U)
    goto LAB_00083db3;
    iVar11 = 0;
    uVar13 = 0;
    do {
      uVar13 = uVar13 + 1;
      puVar3 = (undefined4 *)((int)pin + iVar11 + 0x18);
      uVar4 = puVar3[1];
      uVar5 = puVar3[2];
      uVar6 = puVar3[3];
      puVar2 = (undefined4 *)((int)pvVar7 + iVar11);
      *puVar2 = *puVar3;
      puVar2[1] = uVar4;
      puVar2[2] = uVar5;
      puVar2[3] = uVar6;
      iVar11 = iVar11 + 0x10;
    } while (uVar13 < uVar8);
    if (numv == iVar10) goto LAB_00083da5;
  }
  puVar9 = (undefined1 *)((int)pin + iVar10 * 4 + 0x1b);
  puVar12 = (undefined1 *)((int)pvVar7 + iVar10 * 4 + 3);
  do {
                    /* Unresolved local var: int k@[???] */
    iVar10 = iVar10 + 1;
    *puVar12 = *puVar9;
    puVar12[-3] = puVar9[-3];
    puVar12[-2] = puVar9[-2];
    puVar1 = puVar9 + -1;
    puVar9 = puVar9 + 4;
    puVar12[-1] = *puVar1;
    puVar12 = puVar12 + 4;
  } while (iVar10 < numv);
LAB_00083da5:
  return (void *)((int)pin + 0x18U + numv * 4);
}


// Mod_LoadAliasGroup  @ 00083dc0
void * Mod_LoadAliasGroup(void *pin,int *pframeindex,int numv,trivertx_t *pbboxmin,
                         trivertx_t *pbboxmax,aliashdr_t *pheader,char *name)

{
  int32 iVar1;
  int32 *piVar2;
  void *pvVar3;
  void *pin_00;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  
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
  pin_00 = (void *)((int)pin + 0xc);
  pvVar3 = Hunk_AllocName(iVar1 * 4,loadname);
  piVar2[1] = (int)pvVar3 - (int)pheader;
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      while( true ) {
        lVar6 = (longdouble)(*LittleFloat)(*(float *)((int)pin + iVar4 * 4 + 0xc));
        *(float *)((int)pvVar3 + iVar4 * 4) = (float)lVar6;
        if ((longdouble)0 < lVar6) break;
        iVar4 = iVar4 + 1;
        Sys_Error("Mod_LoadAliasGroup: interval<=0");
        if (iVar4 == iVar1) goto LAB_00083ebe;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar1);
LAB_00083ebe:
    pin_00 = (void *)((int)pin_00 + iVar1 * 4);
    iVar4 = 0;
    do {
      iVar5 = iVar4 + 1;
      pin_00 = Mod_LoadAliasFrame(pin_00,piVar2 + iVar4 * 3 + 4,numv,
                                  (trivertx_t *)(piVar2 + iVar4 * 3 + 2),
                                  (trivertx_t *)(piVar2 + iVar4 * 3 + 3),pheader,name);
      iVar4 = iVar5;
    } while (iVar5 != iVar1);
  }
  return pin_00;
}


// Mod_LoadAliasModel  @ 00084140
void Mod_LoadAliasModel(model_t *mod,void *buffer)

{
  int32 *piVar1;
  maliasframedesc_t *pmVar2;
  byte bVar3;
  int iVar4;
  int mark;
  int32 iVar5;
  int32 iVar6;
  int32 iVar7;
  aliashdr_t *pheader;
  int iVar8;
  synctype_t sVar9;
  int32 *piVar10;
  void *pvVar11;
  aliasframetype_t aVar12;
  int iVar13;
  int32 *piVar14;
  int iVar15;
  int32 *piVar16;
  byte *pbVar17;
  maliasframedesc_t *pmVar18;
  longdouble lVar19;
  aliashdr_t *local_3c;
  
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
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar5 != 6) {
    Sys_Error("Mod_LoadAliasModel: Model %s has wrong version number (%i should be %i)",mod,iVar5,6)
    ;
  }
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  iVar6 = (*LittleLong)(*(int32 *)((int)buffer + 0x3c));
  iVar7 = (*LittleLong)(*(int32 *)((int)buffer + 0x40));
  pheader = Hunk_AllocName((iVar5 + -1) * 0x20 + iVar7 * 0x10 + 0x88 + iVar6 * 0xc,loadname);
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  pmVar2 = pheader->frames + iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x4c));
  mod->flags = iVar5;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  *(float *)(pmVar2 + 1) = (float)lVar19;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x30));
  *(int32 *)((int)(pmVar2 + 1) + 0x10) = iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x34));
  *(int32 *)((int)(pmVar2 + 1) + 0x14) = iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x38));
  *(int32 *)((int)(pmVar2 + 1) + 0x18) = iVar5;
  if (0x1e0 < iVar5) {
    Sys_Error("Mod_LoadAliasModel: Model %s has a skin taller than %d",mod,0x1e0);
  }
  iVar8 = (*LittleLong)(*(int32 *)((int)buffer + 0x3c));
  *(int *)((int)(pmVar2 + 1) + 0x1c) = iVar8;
  if (iVar8 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no vertices: %d",mod,iVar8);
    iVar8 = *(int *)((int)(pmVar2 + 1) + 0x1c);
  }
  if (2000 < iVar8) {
    Sys_Error("Mod_LoadAliasModel: Model %s has too many vertices: %d",mod,iVar8);
  }
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x40));
  *(int32 *)(pmVar2 + 2) = iVar5;
  if (iVar5 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no triangles: %d",mod,iVar5);
  }
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  *(int32 *)((int)(pmVar2 + 2) + 4) = iVar5;
  if (iVar5 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no frames: %d",mod,iVar5);
  }
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x50));
  *(float *)((int)(pmVar2 + 2) + 0x10) = (float)((longdouble)0.09090909090909091 * lVar19);
  sVar9 = (*LittleLong)(*(int32 *)((int)buffer + 0x48));
  mod->synctype = sVar9;
  mod->numframes = *(int *)((int)(pmVar2 + 2) + 4);
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 8));
  pmVar2->bboxmax = (trivertx_t)(float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x14));
  *(float *)(pmVar2->name + 4) = (float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x24));
  *(float *)((int)(pmVar2 + 1) + 4) = (float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0xc));
  pmVar2->frame = (int)(float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x18));
  *(float *)(pmVar2->name + 8) = (float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x28));
  *(float *)((int)(pmVar2 + 1) + 8) = (float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x10));
  *(float *)pmVar2->name = (float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x1c));
  *(float *)(pmVar2->name + 0xc) = (float)lVar19;
  lVar19 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x2c));
  iVar8 = *(int *)((int)(pmVar2 + 1) + 0x10);
  iVar4 = *(int *)((int)(pmVar2 + 2) + 4);
  *(float *)((int)(pmVar2 + 1) + 0xc) = (float)lVar19;
  if ((*(byte *)((int)(pmVar2 + 1) + 0x14) & 3) != 0) {
    Sys_Error("Mod_LoadAliasModel: skinwidth not multiple of 4");
  }
  pheader->model = (int)pmVar2 - (int)pheader;
  iVar13 = *(int *)((int)(pmVar2 + 1) + 0x18) * *(int *)((int)(pmVar2 + 1) + 0x14);
  if (iVar8 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of skins: %d\n",iVar8);
    piVar14 = (int32 *)((int)buffer + 0x54);
    pvVar11 = Hunk_AllocName(iVar8 * 0xc,loadname);
    pheader->skindesc = (int)pvVar11 - (int)pheader;
  }
  else {
    piVar14 = (int32 *)((int)buffer + 0x54);
    iVar15 = 0;
    piVar10 = Hunk_AllocName(iVar8 * 0xc,loadname);
    pheader->skindesc = (int)piVar10 - (int)pheader;
    do {
                    /* Unresolved local var: aliasskintype_t skintype@[???] */
      piVar16 = piVar14 + 1;
      iVar5 = (*LittleLong)(*piVar14);
      *piVar10 = iVar5;
      if (iVar5 == 0) {
                    /* Unresolved local var: uchar * pskin@[???]
                       Unresolved local var: uchar * pinskin@[???]
                       Unresolved local var: ushort * pusskin@[???] */
        pvVar11 = Hunk_AllocName(r_pixbytes * iVar13,loadname);
        piVar10[2] = (int)pvVar11 - (int)pheader;
        if (r_pixbytes == 1) {
          Q_memcpy(pvVar11,piVar16,iVar13);
        }
        else if (r_pixbytes != 2) {
          Sys_Error("Mod_LoadAliasSkin: driver set invalid r_pixbytes: %d\n",r_pixbytes);
        }
        piVar14 = (int32 *)((int)piVar16 + iVar13);
      }
      else {
        piVar14 = Mod_LoadAliasSkinGroup(piVar16,piVar10 + 2,iVar13,pheader);
      }
      iVar15 = iVar15 + 1;
      piVar10 = piVar10 + 3;
    } while (iVar15 != iVar8);
  }
  pheader->stverts = (int)pmVar2 + (0x54 - (int)pheader);
  iVar8 = *(int *)((int)(pmVar2 + 1) + 0x1c);
  if (0 < iVar8) {
    iVar13 = 0;
    piVar10 = piVar14;
    pmVar18 = pmVar2;
    do {
      iVar13 = iVar13 + 1;
      iVar5 = (*LittleLong)(*piVar10);
      *(int32 *)((int)(pmVar18 + 2) + 0x14) = iVar5;
      iVar5 = (*LittleLong)(piVar10[1]);
      *(int32 *)((int)(pmVar18 + 2) + 0x18) = iVar5 << 0x10;
      piVar16 = piVar10 + 2;
      piVar10 = piVar10 + 3;
      iVar5 = (*LittleLong)(*piVar16);
      *(int32 *)((int)(pmVar18 + 2) + 0x1c) = iVar5 << 0x10;
      pmVar18 = (maliasframedesc_t *)&pmVar18->frame;
      iVar8 = *(int *)((int)(pmVar2 + 1) + 0x1c);
    } while (iVar13 < iVar8);
  }
  piVar10 = (int32 *)((int)(pmVar2 + 2) + 0x14 + iVar8 * 0xc);
  piVar14 = piVar14 + iVar8 * 3;
  pheader->triangles = (int)piVar10 - (int)pheader;
  iVar8 = *(int *)(pmVar2 + 2);
  if (0 < iVar8) {
    iVar13 = 0;
    piVar16 = piVar14;
    do {
                    /* Unresolved local var: int j@[???] */
      iVar13 = iVar13 + 1;
      iVar5 = (*LittleLong)(*piVar16);
      *piVar10 = iVar5;
      iVar5 = (*LittleLong)(piVar16[1]);
      piVar10[1] = iVar5;
      iVar5 = (*LittleLong)(piVar16[2]);
      piVar10[2] = iVar5;
      piVar1 = piVar16 + 3;
      piVar16 = piVar16 + 4;
      iVar5 = (*LittleLong)(*piVar1);
      piVar10[3] = iVar5;
      piVar10 = piVar10 + 4;
      iVar8 = *(int *)(pmVar2 + 2);
    } while (iVar13 < iVar8);
  }
  if (iVar4 < 1) {
    Sys_Error("Mod_LoadAliasModel: Invalid # of frames: %d\n",iVar4);
    piVar14 = piVar14 + *(int *)(pmVar2 + 2) * 4;
  }
  else {
    piVar14 = piVar14 + iVar8 * 4;
    iVar8 = 0;
    local_3c = pheader;
    do {
      while( true ) {
        iVar13 = iVar8 + 1;
        aVar12 = (*LittleLong)(*piVar14);
        local_3c->frames[0].type = aVar12;
        if (aVar12 == ALIAS_SINGLE) break;
        piVar14 = Mod_LoadAliasGroup(piVar14 + 1,&pheader->frames[iVar8].frame,
                                     *(int *)((int)(pmVar2 + 1) + 0x1c),
                                     &pheader->frames[iVar8].bboxmin,&pheader->frames[iVar8].bboxmax
                                     ,pheader,pheader->frames[iVar8].name);
        local_3c = (aliashdr_t *)&local_3c->frames[0].frame;
        iVar8 = iVar13;
        if (iVar13 == iVar4) goto LAB_00084619;
      }
                    /* Unresolved local var: aliasframetype_t frametype@[???] */
      piVar14 = Mod_LoadAliasFrame(piVar14 + 1,&pheader->frames[iVar8].frame,
                                   *(int *)((int)(pmVar2 + 1) + 0x1c),
                                   &pheader->frames[iVar8].bboxmin,&pheader->frames[iVar8].bboxmax,
                                   pheader,pheader->frames[iVar8].name);
      local_3c = (aliashdr_t *)&local_3c->frames[0].frame;
      iVar8 = iVar13;
    } while (iVar13 != iVar4);
  }
LAB_00084619:
                    /* Unresolved local var: ushort * pPal@[???]
                       Unresolved local var: uchar * pPalSrc@[???] */
  pbVar17 = (byte *)((int)piVar14 + 2);
  mod->type = mod_alias;
  mod->mins[2] = -16.0;
  mod->mins[1] = -16.0;
  mod->mins[0] = -16.0;
  mod->maxs[2] = 16.0;
  mod->maxs[1] = 16.0;
  mod->maxs[0] = 16.0;
  pvVar11 = Hunk_AllocName(0x800,loadname);
  iVar8 = 0;
  do {
    *(ushort *)((int)pvVar11 + iVar8 * 8) = (ushort)*pbVar17;
    *(ushort *)((int)pvVar11 + iVar8 * 8 + 2) = (ushort)pbVar17[-1];
    bVar3 = pbVar17[-2];
    pbVar17 = pbVar17 + 3;
    *(undefined2 *)((int)pvVar11 + iVar8 * 8 + 6) = 0;
    *(ushort *)((int)pvVar11 + iVar8 * 8 + 4) = (ushort)bVar3;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0x100);
  pheader->palette = (int)pvVar11 - (int)pheader;
  iVar8 = Hunk_LowMark();
  Cache_Alloc(&mod->cache,iVar8 - mark,loadname);
  pvVar11 = (mod->cache).data;
  if (pvVar11 == (void *)0x0) {
    return;
  }
  Q_memcpy(pvVar11,pheader,iVar8 - mark);
  Hunk_FreeToLowMark(mark);
  return;
}


// Mod_LoadAliasSkin  @ 00083f30
void * Mod_LoadAliasSkin(void *pin,int *pskinindex,int skinsize,aliashdr_t *pheader)

{
  void *dest;
  
                    /* Unresolved local var: uchar * pskin@[???]
                       Unresolved local var: uchar * pinskin@[???]
                       Unresolved local var: ushort * pusskin@[???] */
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


// Mod_LoadAliasSkinGroup  @ 00083fc0
void * Mod_LoadAliasSkinGroup(void *pin,int *pskinindex,int skinsize,aliashdr_t *pheader)

{
  int32 iVar1;
  int32 *piVar2;
  void *pvVar3;
  void *dest;
  void *pvVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  
                    /* Unresolved local var: daliasskingroup_t * pinskingroup@[???]
                       Unresolved local var: maliasskingroup_t * paliasskingroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numskins@[???]
                       Unresolved local var: daliasskininterval_t * pinskinintervals@[???]
                       Unresolved local var: float * poutskinintervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  iVar1 = (*LittleLong)(*(int32 *)pin);
  piVar2 = Hunk_AllocName((iVar1 * 3 + -3) * 4 + 0x14,loadname);
  pvVar4 = (void *)((int)pin + 4);
  *piVar2 = iVar1;
  *pskinindex = (int)piVar2 - (int)pheader;
  pvVar3 = Hunk_AllocName(iVar1 * 4,loadname);
  piVar2[1] = (int)pvVar3 - (int)pheader;
  if (0 < iVar1) {
    iVar5 = 0;
    do {
      while( true ) {
        lVar7 = (longdouble)(*LittleFloat)(*(float *)((int)pin + iVar5 * 4 + 4));
        *(float *)((int)pvVar3 + iVar5 * 4) = (float)lVar7;
        if ((longdouble)0 < lVar7) break;
        iVar5 = iVar5 + 1;
        Sys_Error("Mod_LoadAliasSkinGroup: interval<=0");
        if (iVar5 == iVar1) goto LAB_0008408e;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != iVar1);
LAB_0008408e:
    pvVar4 = (void *)((int)pvVar4 + iVar1 * 4);
    iVar5 = 0;
    pvVar3 = pvVar4;
    do {
      while( true ) {
        iVar6 = iVar5;
        dest = Hunk_AllocName(r_pixbytes * skinsize,loadname);
        piVar2[4] = (int)dest - (int)pheader;
        if (r_pixbytes != 1) break;
        piVar2 = piVar2 + 3;
        Q_memcpy(dest,pvVar3,skinsize);
        iVar5 = iVar6 + 1;
        pvVar3 = (void *)((int)pvVar3 + skinsize);
        if (iVar6 + 1 == iVar1) goto LAB_00084120;
      }
                    /* Unresolved local var: uchar * pskin@[???]
                       Unresolved local var: uchar * pinskin@[???]
                       Unresolved local var: ushort * pusskin@[???] */
      if (r_pixbytes != 2) {
        Sys_Error("Mod_LoadAliasSkin: driver set invalid r_pixbytes: %d\n",r_pixbytes);
      }
      pvVar3 = (void *)((int)pvVar3 + skinsize);
      piVar2 = piVar2 + 3;
      iVar5 = iVar6 + 1;
    } while (iVar6 + 1 != iVar1);
LAB_00084120:
    pvVar4 = (void *)((int)pvVar4 + (iVar6 + 1) * skinsize);
  }
  return pvVar4;
}


// Mod_LoadBrushModel  @ 000834e0
void Mod_LoadBrushModel(model_t *mod,void *buffer)

{
  int32 *piVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  bool bVar5;
  uchar *puVar6;
  int32 iVar7;
  int *piVar8;
  int iVar9;
  model_t *pmVar10;
  byte *pbVar11;
  char *pcVar12;
  color24 *pcVar13;
  uint uVar14;
  dmodel_t *pdVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  float fVar20;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: dheader_t * header@[???]
                       Unresolved local var: dmodel_t * bm@[???] */
  loadmodel->type = mod_brush;
  iVar7 = (*LittleLong)(*(int32 *)buffer);
  if (1 < iVar7 - 0x1dU) {
    Sys_Error("Mod_LoadBrushModel: %s has wrong version number (%i should be %i)",mod,iVar7,0x1e);
  }
  mod_base = buffer;
  iVar16 = 0;
  do {
    piVar1 = (int32 *)((int)buffer + iVar16 * 4);
    iVar16 = iVar16 + 1;
    iVar7 = (*LittleLong)(*piVar1);
    *piVar1 = iVar7;
  } while (iVar16 != 0x1f);
  Mod_LoadVertexes((lump_t *)((int)buffer + 0x1c));
  Mod_LoadEdges((lump_t *)((int)buffer + 100));
  puVar6 = mod_base;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
  iVar16 = *(int *)((int)buffer + 0x6c);
  uVar14 = *(uint *)((int)buffer + 0x70);
  if ((uVar14 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar14 = *(uint *)((int)buffer + 0x70);
  }
  uVar14 = uVar14 >> 2;
  piVar8 = Hunk_AllocName(uVar14 * 4,loadname);
  pmVar10 = loadmodel;
  loadmodel->surfedges = piVar8;
  pmVar10->numsurfedges = uVar14;
  if (uVar14 != 0) {
    uVar17 = 0;
    do {
      iVar7 = (*LittleLong)(*(int32 *)(puVar6 + uVar17 * 4 + iVar16));
      piVar8[uVar17] = iVar7;
      uVar17 = uVar17 + 1;
      pmVar10 = loadmodel;
    } while (uVar14 != uVar17);
  }
  iVar16 = strcasecmp(com_gamedir,"bshift");
  if (iVar16 == 0) {
    if (*(int *)((int)buffer + 0x10) == 0) {
      pmVar10->entities = (char *)0x0;
    }
    else {
      pcVar12 = Hunk_AllocName(*(int *)((int)buffer + 0x10),loadname);
      pmVar10->entities = pcVar12;
      Q_memcpy(loadmodel->entities,mod_base + *(int *)((int)buffer + 0xc),
               *(int *)((int)buffer + 0x10));
      pcVar12 = loadmodel->entities;
      if (pcVar12 != (char *)0x0) {
        do {
          pcVar12 = COM_Parse(pcVar12);
          if ((*pcVar12 == '\0') || (com_token[0] == '}')) goto LAB_0008361f;
          iVar16 = Q_strcmp(com_token,"wad");
        } while (iVar16 != 0);
        COM_Parse(pcVar12);
        if (wadpath != (char *)0x0) {
          Mem_Free(wadpath);
        }
        wadpath = Mem_Strdup(com_token);
      }
    }
LAB_0008361f:
    Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
    pmVar10 = loadmodel;
    if (*(int *)((int)buffer + 0x48) == 0) {
      loadmodel->lightdata = (color24 *)0x0;
    }
    else {
      pcVar13 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
      pmVar10->lightdata = pcVar13;
      Q_memcpy(loadmodel->lightdata,mod_base + *(int *)((int)buffer + 0x44),
               *(int *)((int)buffer + 0x48));
    }
    Mod_LoadPlanes((lump_t *)((int)buffer + 4));
  }
  else {
    if (*(int *)((int)buffer + 8) == 0) {
      pmVar10->entities = (char *)0x0;
    }
    else {
      pcVar12 = Hunk_AllocName(*(int *)((int)buffer + 8),loadname);
      pmVar10->entities = pcVar12;
      Q_memcpy(loadmodel->entities,mod_base + *(int *)((int)buffer + 4),*(int *)((int)buffer + 8));
      pcVar12 = loadmodel->entities;
      if (pcVar12 != (char *)0x0) {
        do {
          pcVar12 = COM_Parse(pcVar12);
          if ((*pcVar12 == '\0') || (com_token[0] == '}')) goto LAB_00083663;
          iVar16 = Q_strcmp(com_token,"wad");
        } while (iVar16 != 0);
        COM_Parse(pcVar12);
        if (wadpath != (char *)0x0) {
          Mem_Free(wadpath);
        }
        wadpath = Mem_Strdup(com_token);
      }
    }
LAB_00083663:
    Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
    pmVar10 = loadmodel;
    if (*(int *)((int)buffer + 0x48) == 0) {
      loadmodel->lightdata = (color24 *)0x0;
    }
    else {
      pcVar13 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
      pmVar10->lightdata = pcVar13;
      Q_memcpy(loadmodel->lightdata,mod_base + *(int *)((int)buffer + 0x44),
               *(int *)((int)buffer + 0x48));
    }
    Mod_LoadPlanes((lump_t *)((int)buffer + 0xc));
  }
  Mod_LoadTexinfo((lump_t *)((int)buffer + 0x34));
  Mod_LoadFaces((lump_t *)((int)buffer + 0x3c));
  Mod_LoadMarksurfaces((lump_t *)((int)buffer + 0x5c));
  pmVar10 = loadmodel;
  if (*(int *)((int)buffer + 0x28) == 0) {
    loadmodel->visdata = (byte *)0x0;
  }
  else {
    pbVar11 = Hunk_AllocName(*(int *)((int)buffer + 0x28),loadname);
    pmVar10->visdata = pbVar11;
    Q_memcpy(loadmodel->visdata,mod_base + *(int *)((int)buffer + 0x24),*(int *)((int)buffer + 0x28)
            );
  }
  Mod_LoadLeafs((lump_t *)((int)buffer + 0x54));
  Mod_LoadNodes((lump_t *)((int)buffer + 0x2c));
  Mod_LoadClipnodes((lump_t *)((int)buffer + 0x4c));
  Mod_LoadSubmodels((lump_t *)((int)buffer + 0x74));
  iVar16 = mod->numsurfaces;
  if (0 < iVar16) {
    iVar19 = 0;
    iVar18 = 0;
    do {
      while (*(int *)((int)mod->surfaces->cachespots + iVar19 + -8) +
             *(int *)((int)mod->surfaces->cachespots + iVar19 + -4) <= mod->numsurfedges) {
        iVar18 = iVar18 + 1;
        iVar19 = iVar19 + 0x44;
        if (iVar16 <= iVar18) goto LAB_0008374e;
      }
      iVar18 = iVar18 + 1;
      iVar19 = iVar19 + 0x44;
      Sys_Error("MOD_LoadBrushModel: more surfedges referenced than loaded in %s",mod);
      iVar16 = mod->numsurfaces;
    } while (iVar18 < iVar16);
  }
LAB_0008374e:
  iVar16 = mod->numleafs;
  if (0 < iVar16) {
    iVar19 = 0;
    iVar18 = 0;
    do {
                    /* Unresolved local var: int firstmarksurface@[???] */
      while ((*(int *)(mod->leafs->ambient_sound_level + iVar19 + -0xc) - (int)mod->marksurfaces >>
             2) + *(int *)(mod->leafs->ambient_sound_level + iVar19 + -8) <= mod->nummarksurfaces) {
        iVar18 = iVar18 + 1;
        iVar19 = iVar19 + 0x30;
        if (iVar16 <= iVar18) goto LAB_000837a9;
      }
      iVar18 = iVar18 + 1;
      iVar19 = iVar19 + 0x30;
      Sys_Error("MOD_LoadBrushModel: more marksurfaces referenced than loaded in %s",mod);
      iVar16 = mod->numleafs;
    } while (iVar18 < iVar16);
  }
LAB_000837a9:
  iVar16 = mod->numnodes;
  if (0 < iVar16) {
    iVar19 = 0;
    iVar18 = 0;
    do {
      while ((int)((uint)*(ushort *)((int)mod->nodes->children + iVar19 + 10) +
                  (uint)*(ushort *)((int)mod->nodes->children + iVar19 + 8)) <= mod->numsurfaces) {
        iVar18 = iVar18 + 1;
        iVar19 = iVar19 + 0x28;
        if (iVar16 <= iVar18) goto LAB_00083800;
      }
      iVar18 = iVar18 + 1;
      iVar19 = iVar19 + 0x28;
      Sys_Error("MOD_LoadBrushModel: more surfaces referenced than loaded in %s",mod);
      iVar16 = mod->numnodes;
    } while (iVar18 < iVar16);
  }
LAB_00083800:
  iVar16 = mod->numsubmodels;
  if (0 < iVar16) {
    iVar18 = 0;
    do {
      while (mod->submodels[iVar18].firstface + mod->submodels[iVar18].numfaces <= mod->numsurfaces)
      {
        iVar18 = iVar18 + 1;
        if (iVar16 <= iVar18) goto LAB_00083847;
      }
      iVar18 = iVar18 + 1;
      Sys_Error("MOD_LoadBrushModel: more faces referenced than loaded in %s",mod);
      iVar16 = mod->numsubmodels;
    } while (iVar18 < iVar16);
  }
LAB_00083847:
  Mod_MakeHull0();
  mod->numframes = 2;
  mod->flags = 0;
  if (0 < mod->numsubmodels) {
    iVar18 = 0;
    iVar16 = 1;
    do {
      pdVar15 = mod->submodels + iVar18;
      mod->hulls[0].firstclipnode = pdVar15->headnode[0];
      mod->hulls[1].firstclipnode = pdVar15->headnode[1];
      iVar9 = mod->numclipnodes + -1;
      mod->hulls[1].lastclipnode = iVar9;
      iVar19 = pdVar15->headnode[2];
      mod->hulls[2].lastclipnode = iVar9;
      mod->hulls[2].firstclipnode = iVar19;
      iVar19 = pdVar15->headnode[3];
      mod->hulls[3].lastclipnode = iVar9;
      mod->hulls[3].firstclipnode = iVar19;
      mod->firstmodelsurface = pdVar15->firstface;
      mod->nummodelsurfaces = pdVar15->numfaces;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t corner@[???] */
      fVar20 = pdVar15->maxs[0];
      mod->maxs[0] = fVar20;
      fVar2 = pdVar15->maxs[1];
      mod->maxs[1] = fVar2;
      fVar3 = pdVar15->maxs[2];
      mod->maxs[2] = fVar3;
      local_2c = pdVar15->mins[0];
      mod->mins[0] = local_2c;
      local_28 = pdVar15->mins[1];
      mod->mins[1] = local_28;
      local_24 = pdVar15->mins[2];
      mod->mins[2] = local_24;
      local_2c = ABS(local_2c);
      fVar20 = ABS(fVar20);
      if (local_2c <= fVar20) {
        local_2c = fVar20;
      }
      local_28 = ABS(local_28);
      fVar2 = ABS(fVar2);
      if (local_28 <= fVar2) {
        local_28 = fVar2;
      }
      local_24 = ABS(local_24);
      fVar3 = ABS(fVar3);
      if (local_24 <= fVar3) {
        local_24 = fVar3;
      }
      fVar20 = Length(&local_2c);
      mod->radius = fVar20;
      mod->numleafs = pdVar15->visleafs;
      iVar19 = mod->numsubmodels;
      if (iVar18 < iVar19 + -1) {
        snprintf((char *)&local_2c,10,"*%i",iVar16);
        pmVar10 = Mod_FindName(false,(char *)&local_2c);
        uVar14 = 0;
        loadmodel = pmVar10;
        do {
          uVar4 = *(undefined4 *)(mod->name + uVar14);
          *(undefined4 *)(pmVar10->name + uVar14 + 4) = *(undefined4 *)(mod->name + uVar14 + 4);
          *(undefined4 *)(pmVar10->name + uVar14) = uVar4;
          uVar14 = uVar14 + 8;
        } while (uVar14 < 0x188);
        Q_strncpy(loadmodel->name,(char *)&local_2c,0x3f);
        mod = loadmodel;
        loadmodel->name[0x3f] = '\0';
        iVar19 = mod->numsubmodels;
      }
                    /* Unresolved local var: char[10] name@[???] */
      iVar18 = iVar18 + 1;
      bVar5 = iVar16 < iVar19;
      iVar16 = iVar16 + 1;
    } while (bVar5);
  }
  return;
}


// Mod_LoadClipnodes  @ 00082ef0
void Mod_LoadClipnodes(lump_t *l)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  mplane_t *pmVar4;
  uchar *puVar5;
  model_t *pmVar6;
  short sVar7;
  dclipnode_t *pdVar8;
  int32 iVar9;
  uint uVar10;
  int32 *piVar11;
  uint uVar12;
  
                    /* Unresolved local var: dclipnode_t * in@[???]
                       Unresolved local var: dclipnode_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: hull_t * hull@[???] */
  puVar5 = mod_base;
  uVar10 = l->filelen;
  iVar3 = l->fileofs;
  if ((uVar10 & 7) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar10 = l->filelen;
  }
  uVar10 = uVar10 >> 3;
  pdVar8 = Hunk_AllocName(uVar10 * 8,loadname);
  pmVar6 = loadmodel;
  iVar1 = uVar10 - 1;
  loadmodel->hulls[1].firstclipnode = 0;
  pmVar4 = pmVar6->planes;
  pmVar6->clipnodes = pdVar8;
  pmVar6->numclipnodes = uVar10;
  pmVar6->hulls[1].clipnodes = pdVar8;
  pmVar6->hulls[1].lastclipnode = iVar1;
  pmVar6->hulls[1].planes = pmVar4;
  pmVar6->hulls[1].clip_mins[0] = -16.0;
  pmVar6->hulls[1].clip_mins[1] = -16.0;
  pmVar6->hulls[1].clip_mins[2] = -36.0;
  pmVar6->hulls[1].clip_maxs[0] = 16.0;
  pmVar6->hulls[1].clip_maxs[1] = 16.0;
  pmVar6->hulls[1].clip_maxs[2] = 36.0;
  pmVar6->hulls[2].clipnodes = pdVar8;
  pmVar6->hulls[2].firstclipnode = 0;
  pmVar6->hulls[2].lastclipnode = iVar1;
  pmVar6->hulls[2].planes = pmVar4;
  pmVar6->hulls[2].clip_mins[0] = -32.0;
  pmVar6->hulls[2].clip_mins[1] = -32.0;
  pmVar6->hulls[2].clip_mins[2] = -32.0;
  pmVar6->hulls[2].clip_maxs[0] = 32.0;
  pmVar6->hulls[2].clip_maxs[1] = 32.0;
  pmVar6->hulls[2].clip_maxs[2] = 32.0;
  pmVar6->hulls[3].clipnodes = pdVar8;
  pmVar6->hulls[3].firstclipnode = 0;
  pmVar6->hulls[3].lastclipnode = iVar1;
  pmVar6->hulls[3].planes = pmVar4;
  pmVar6->hulls[3].clip_mins[0] = -16.0;
  pmVar6->hulls[3].clip_mins[1] = -16.0;
  pmVar6->hulls[3].clip_mins[2] = -18.0;
  pmVar6->hulls[3].clip_maxs[0] = 16.0;
  pmVar6->hulls[3].clip_maxs[1] = 16.0;
  pmVar6->hulls[3].clip_maxs[2] = 18.0;
  if (uVar10 != 0) {
    piVar11 = (int32 *)(puVar5 + iVar3);
    uVar12 = 0;
    do {
      uVar12 = uVar12 + 1;
      iVar9 = (*LittleLong)(*piVar11);
      pdVar8->planenum = iVar9;
      sVar7 = (*LittleShort)((short)piVar11[1]);
      pdVar8->children[0] = sVar7;
      psVar2 = (short *)((int)piVar11 + 6);
      piVar11 = piVar11 + 2;
      sVar7 = (*LittleShort)(*psVar2);
      pdVar8->children[1] = sVar7;
      pdVar8 = pdVar8 + 1;
    } while (uVar10 != uVar12);
  }
  return;
}


// Mod_LoadEdges  @ 000820d0
void Mod_LoadEdges(lump_t *l)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  model_t *pmVar4;
  ushort uVar5;
  medge_t *pmVar6;
  uint uVar7;
  uint uVar8;
  
                    /* Unresolved local var: dedge_t * in@[???]
                       Unresolved local var: medge_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  puVar3 = mod_base;
  uVar8 = l->filelen;
  iVar2 = l->fileofs;
  if ((uVar8 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 >> 2;
  pmVar6 = Hunk_AllocName(uVar8 * 8 + 8,loadname);
  pmVar4 = loadmodel;
  loadmodel->edges = pmVar6;
  pmVar4->numedges = uVar8;
  if (uVar8 != 0) {
    uVar7 = 0;
    do {
      uVar5 = (*LittleShort)(*(short *)(puVar3 + uVar7 * 4 + iVar2));
      pmVar6->v[0] = uVar5;
      iVar1 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      uVar5 = (*LittleShort)(*(short *)(puVar3 + iVar1 + iVar2 + 2));
      pmVar6->v[1] = uVar5;
      pmVar6 = pmVar6 + 1;
    } while (uVar8 != uVar7);
  }
  return;
}


// Mod_LoadEntities  @ 00081d80
void Mod_LoadEntities(lump_t *l)

{
  model_t *pmVar1;
  char *pcVar2;
  int iVar3;
  
  pmVar1 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->entities = (char *)0x0;
  }
  else {
    pcVar2 = Hunk_AllocName(l->filelen,loadname);
    pmVar1->entities = pcVar2;
    Q_memcpy(loadmodel->entities,mod_base + l->fileofs,l->filelen);
    pcVar2 = loadmodel->entities;
    if (pcVar2 != (char *)0x0) {
      do {
        pcVar2 = COM_Parse(pcVar2);
        if (*pcVar2 == '\0') {
          return;
        }
        if (com_token[0] == '}') {
          return;
        }
        iVar3 = Q_strcmp(com_token,"wad");
      } while (iVar3 != 0);
      COM_Parse(pcVar2);
      if (wadpath != (char *)0x0) {
        Mem_Free(wadpath);
      }
      wadpath = Mem_Strdup(com_token);
    }
  }
  return;
}


// Mod_LoadFaces  @ 000826d0
void Mod_LoadFaces(lump_t *l)

{
  int *piVar1;
  uchar *puVar2;
  model_t *pmVar3;
  short sVar4;
  short sVar5;
  msurface_t *s;
  int32 iVar6;
  int iVar7;
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
  puVar2 = mod_base;
  uVar9 = l->filelen;
  iVar7 = l->fileofs;
  if (uVar9 != (uVar9 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar9 = l->filelen;
  }
  uVar9 = uVar9 / 0x14;
  s = Hunk_AllocName(uVar9 * 0x44,loadname);
  pmVar3 = loadmodel;
  loadmodel->surfaces = s;
  pmVar3->numsurfaces = uVar9;
  if (uVar9 != 0) {
    psVar10 = (short *)(puVar2 + iVar7);
    uVar11 = 0;
    do {
      while( true ) {
        iVar6 = (*LittleLong)(*(int32 *)(psVar10 + 2));
        s->firstedge = iVar6;
        sVar4 = (*LittleShort)(psVar10[4]);
        s->flags = 0;
        s->pdecals = (decal_t *)0x0;
        s->numedges = (int)sVar4;
        sVar4 = (*LittleShort)(*psVar10);
        sVar5 = (*LittleShort)(psVar10[1]);
        if (sVar5 != 0) {
          s->flags = s->flags | 2;
        }
        pmVar3 = loadmodel;
        s->plane = loadmodel->planes + sVar4;
        pmVar8 = pmVar3->texinfo;
        sVar4 = (*LittleShort)(psVar10[5]);
        s->texinfo = pmVar8 + sVar4;
        CalcSurfaceExtents(s);
        s->styles[0] = (byte)psVar10[6];
        s->styles[1] = *(byte *)((int)psVar10 + 0xd);
        s->styles[2] = (byte)psVar10[7];
        s->styles[3] = *(byte *)((int)psVar10 + 0xf);
        iVar6 = (*LittleLong)(*(int32 *)(psVar10 + 8));
        if (iVar6 == -1) {
          s->samples = (color24 *)0x0;
        }
        else {
          s->samples = (color24 *)(&loadmodel->lightdata->r + iVar6);
        }
        iVar7 = Q_strncmp(s->texinfo->texture->name,"sky",3);
        if (iVar7 != 0) break;
        s->flags = s->flags | 0x24;
LAB_00082754:
        uVar11 = uVar11 + 1;
        psVar10 = psVar10 + 10;
        s = s + 1;
        if (uVar9 == uVar11) {
          return;
        }
      }
      iVar7 = Q_strncmp(s->texinfo->texture->name,"scroll",6);
      if (iVar7 != 0) {
        pmVar8 = s->texinfo;
        if (pmVar8->texture->name[0] != '!') {
          iVar7 = Q_strnicmp(pmVar8->texture->name,"laser",5);
          if (iVar7 == 0) {
            pmVar8 = s->texinfo;
          }
          else {
            iVar7 = Q_strnicmp(s->texinfo->texture->name,"water",5);
            pmVar8 = s->texinfo;
            if (iVar7 != 0) {
              if ((pmVar8->flags & 1) == 0) goto LAB_00082754;
              s->flags = s->flags | 0x20;
              goto LAB_00082898;
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
        goto LAB_00082754;
      }
      s->flags = s->flags | 0x20;
      pmVar8 = s->texinfo;
LAB_00082898:
      uVar11 = uVar11 + 1;
      psVar10 = psVar10 + 10;
      s->extents[0] = (short)pmVar8->texture->width;
      s->extents[1] = (short)pmVar8->texture->height;
      s = s + 1;
    } while (uVar9 != uVar11);
  }
  return;
}


// Mod_LoadLeafs  @ 00082d40
void Mod_LoadLeafs(lump_t *l)

{
  byte *pbVar1;
  int iVar2;
  uchar *puVar3;
  model_t *pmVar4;
  short sVar5;
  mleaf_s *pmVar6;
  int32 iVar7;
  uint uVar8;
  int32 *piVar9;
  uint uVar10;
  
                    /* Unresolved local var: dleaf_t * in@[???]
                       Unresolved local var: mleaf_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int p@[???] */
  puVar3 = mod_base;
  uVar8 = l->filelen;
  iVar2 = l->fileofs;
  if (uVar8 + (uVar8 / 0x1c) * 4 != uVar8 / 0x1c << 5) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 / 0x1c;
  pmVar6 = Hunk_AllocName(uVar8 * 0x30,loadname);
  pmVar4 = loadmodel;
  loadmodel->leafs = pmVar6;
  pmVar4->numleafs = uVar8;
  if (uVar8 != 0) {
    piVar9 = (int32 *)(puVar3 + iVar2);
    uVar10 = 0;
    do {
      sVar5 = (*LittleShort)((short)piVar9[2]);
      pmVar6->minmaxs[0] = sVar5;
      sVar5 = (*LittleShort)(*(short *)((int)piVar9 + 0xe));
      pmVar6->minmaxs[3] = sVar5;
      sVar5 = (*LittleShort)(*(short *)((int)piVar9 + 10));
      pmVar6->minmaxs[1] = sVar5;
      sVar5 = (*LittleShort)((short)piVar9[4]);
      pmVar6->minmaxs[4] = sVar5;
      sVar5 = (*LittleShort)((short)piVar9[3]);
      pmVar6->minmaxs[2] = sVar5;
      sVar5 = (*LittleShort)(*(short *)((int)piVar9 + 0x12));
      pmVar6->minmaxs[5] = sVar5;
      iVar7 = (*LittleLong)(*piVar9);
      pmVar6->contents = iVar7;
      pmVar6->firstmarksurface = loadmodel->marksurfaces + *(ushort *)(piVar9 + 5);
      sVar5 = (*LittleShort)(*(short *)((int)piVar9 + 0x16));
      pmVar6->nummarksurfaces = (int)sVar5;
      iVar7 = (*LittleLong)(piVar9[1]);
      if (iVar7 == -1) {
        pmVar6->compressed_vis = (byte *)0x0;
      }
      else {
        pmVar6->compressed_vis = loadmodel->visdata + iVar7;
      }
      pmVar6->efrags = (efrag_s *)0x0;
      uVar10 = uVar10 + 1;
      pmVar6->ambient_sound_level[0] = (byte)piVar9[6];
      pmVar6->ambient_sound_level[1] = *(byte *)((int)piVar9 + 0x19);
      pmVar6->ambient_sound_level[2] = *(byte *)((int)piVar9 + 0x1a);
      pbVar1 = (byte *)((int)piVar9 + 0x1b);
      piVar9 = piVar9 + 7;
      pmVar6->ambient_sound_level[3] = *pbVar1;
      pmVar6 = pmVar6 + 1;
    } while (uVar8 != uVar10);
  }
  return;
}


// Mod_LoadLighting  @ 00081c80
void Mod_LoadLighting(lump_t *l)

{
  model_t *pmVar1;
  color24 *pcVar2;
  
  pmVar1 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->lightdata = (color24 *)0x0;
    return;
  }
  pcVar2 = Hunk_AllocName(l->filelen,loadname);
  pmVar1->lightdata = pcVar2;
  Q_memcpy(loadmodel->lightdata,mod_base + l->fileofs,l->filelen);
  return;
}


// Mod_LoadMarksurfaces  @ 000831d0
void Mod_LoadMarksurfaces(lump_t *l)

{
  int iVar1;
  uchar *puVar2;
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
  puVar2 = mod_base;
  iVar1 = l->fileofs;
  uVar7 = l->filelen;
  if ((uVar7 & 1) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 >> 1;
  ppmVar5 = Hunk_AllocName(uVar7 * 4,loadname);
  pmVar3 = loadmodel;
  loadmodel->marksurfaces = ppmVar5;
  pmVar3->nummarksurfaces = uVar7;
  if (uVar7 != 0) {
    uVar6 = 0;
    do {
      sVar4 = (*LittleShort)(*(short *)(puVar2 + uVar6 * 2 + iVar1));
      if (loadmodel->numsurfaces <= (int)sVar4) {
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      ppmVar5[uVar6] = loadmodel->surfaces + sVar4;
      uVar6 = uVar6 + 1;
    } while (uVar7 != uVar6);
  }
  return;
}


// Mod_LoadModel  @ 00084cd0
model_t * __regparm3 Mod_LoadModel(model_t *mod,qboolean crash,qboolean trackCRC)

{
  int iVar1;
  int32 *pBuffer;
  char *pcVar2;
  int32 iVar3;
  qboolean qVar4;
  qboolean qVar5;
  model_t *pmVar6;
  char local_128 [259];
  undefined1 local_25;
  int local_24;
  CRC32_t local_20 [4];
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[260] tmpName@[???] */
  iVar1 = COM_CheckParm("-steam");
  if ((iVar1 != 0) && (pmVar6 = mod, mod->name[0] == '/')) {
    do {
      pmVar6 = (model_t *)(pmVar6->name + 1);
    } while (pmVar6->name[0] == '/');
    strncpy(local_128,(char *)pmVar6,0x103);
    local_25 = 0;
    strncpy(mod->name,local_128,0x3f);
    mod->name[0x3f] = '\0';
  }
  pBuffer = (int32 *)COM_LoadFileForMe(mod->name,&local_24);
  if (pBuffer != (int32 *)0x0) {
                    /* Unresolved local var: mod_known_info_t * p@[???] */
    if ((trackCRC != false) &&
       (iVar1 = ((int)(mod[-0x1f1b].hulls[1].clip_maxs + 1) >> 3) * 0x397829cc,
       *(int *)((int)mod_known_info + iVar1) != 0)) {
                    /* Unresolved local var: CRC32_t currentCRC@[???] */
      CRC32_Init(local_20);
      CRC32_ProcessBuffer(local_20,pBuffer,local_24);
      local_20[0] = CRC32_Final(local_20[0]);
      if (*(int *)((int)mod_known_info + iVar1 + 4) == 0) {
                    /* Unresolved local var: qboolean badModel@[???] */
        *(CRC32_t *)((int)mod_known_info + iVar1 + 8) = local_20[0];
        *(undefined4 *)((int)mod_known_info + iVar1 + 4) = 1;
        SetCStrikeFlags();
        qVar4 = IsGameSubscribed("czero");
        if ((((qVar4 == false) && (g_bIsCStrike != 0)) &&
            (qVar5 = IsCZPlayerModel(local_20[0],mod->name), qVar5 != 0)) &&
           (cls.state != ca_dedicated)) {
          COM_ExplainDisconnection(true,"Cannot continue with altered model %s, disconnecting.",mod)
          ;
          CL_Disconnect();
          return (model_t *)0x0;
        }
      }
      else if (local_20[0] != *(CRC32_t *)((int)mod_known_info + iVar1 + 8)) {
        Sys_Error("%s has been modified since starting the engine.  Consider running system diagnostics to check for faulty hardware.\n"
                  ,mod);
        return (model_t *)0x0;
      }
    }
    if (1.0 < developer.value) {
      Con_DPrintf("loading %s\n",mod);
    }
    pcVar2 = COM_FileBase_s(mod->name,loadname,0x20);
    if (pcVar2 == (char *)0x0) {
      pmVar6 = (model_t *)0x0;
      Sys_Error("Mod_LoadModel: Bad model name length: %s\n",mod);
    }
    else {
      mod->needload = false;
      loadmodel = mod;
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
      pmVar6 = mod;
    }
    return pmVar6;
  }
  if (crash != false) {
    Sys_Error("Mod_NumForName: %s not found",mod);
    return (model_t *)0x0;
  }
  return (model_t *)0x0;
}


// Mod_LoadModel  @ 00084fd0
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
  else if ((mod->needload == 3) || (mod->needload == false)) {
    return mod;
  }
  pmVar1 = Mod_LoadModel(mod,crash,trackCRC);
  return pmVar1;
}


// Mod_LoadNodes  @ 00082b30
void Mod_LoadNodes(lump_t *l)

{
  int iVar1;
  uchar *puVar2;
  model_t *pmVar3;
  short sVar4;
  ushort uVar5;
  mnode_t *pmVar6;
  int32 iVar7;
  uint uVar8;
  uint uVar9;
  int32 *piVar10;
  uint uVar11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: dnode_t * in@[???]
                       Unresolved local var: mnode_t * out@[???] */
  puVar2 = mod_base;
  uVar9 = l->filelen;
  iVar1 = l->fileofs;
  if (uVar9 != (uVar9 / 0x18) * 0x18) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar9 = l->filelen;
  }
  uVar9 = uVar9 / 0x18;
  pmVar6 = Hunk_AllocName(uVar9 * 0x28,loadname);
  pmVar3 = loadmodel;
  loadmodel->nodes = pmVar6;
  pmVar3->numnodes = uVar9;
  if (uVar9 != 0) {
    piVar10 = (int32 *)(puVar2 + iVar1);
    uVar11 = 0;
    do {
      while( true ) {
        sVar4 = (*LittleShort)((short)piVar10[2]);
        pmVar6->minmaxs[0] = sVar4;
        sVar4 = (*LittleShort)(*(short *)((int)piVar10 + 0xe));
        pmVar6->minmaxs[3] = sVar4;
        sVar4 = (*LittleShort)(*(short *)((int)piVar10 + 10));
        pmVar6->minmaxs[1] = sVar4;
        sVar4 = (*LittleShort)((short)piVar10[4]);
        pmVar6->minmaxs[4] = sVar4;
        sVar4 = (*LittleShort)((short)piVar10[3]);
        pmVar6->minmaxs[2] = sVar4;
        sVar4 = (*LittleShort)(*(short *)((int)piVar10 + 0x12));
        pmVar6->minmaxs[5] = sVar4;
        iVar7 = (*LittleLong)(*piVar10);
        pmVar6->plane = loadmodel->planes + iVar7;
        uVar5 = (*LittleShort)((short)piVar10[5]);
        pmVar6->firstsurface = uVar5;
        uVar5 = (*LittleShort)(*(short *)((int)piVar10 + 0x16));
        pmVar6->numsurfaces = uVar5;
        sVar4 = (*LittleShort)((short)piVar10[1]);
        uVar8 = (uint)sVar4;
        if ((int)uVar8 < 0) {
          pmVar6->children[0] = (mnode_s *)(loadmodel->leafs + ~uVar8);
        }
        else {
          pmVar6->children[0] = loadmodel->nodes + uVar8;
        }
        sVar4 = (*LittleShort)(*(short *)((int)piVar10 + 6));
        pmVar3 = loadmodel;
        uVar8 = (uint)sVar4;
        if ((int)uVar8 < 0) break;
        uVar11 = uVar11 + 1;
        piVar10 = piVar10 + 6;
        pmVar6->children[1] = loadmodel->nodes + uVar8;
        pmVar6 = pmVar6 + 1;
        if (uVar9 == uVar11) goto LAB_00082d02;
      }
      uVar11 = uVar11 + 1;
      piVar10 = piVar10 + 6;
      pmVar6->children[1] = (mnode_s *)(loadmodel->leafs + ~uVar8);
      pmVar6 = pmVar6 + 1;
    } while (uVar9 != uVar11);
LAB_00082d02:
    Mod_SetParent(pmVar3->nodes,(mnode_t *)0x0);
  }
  return;
}


// Mod_LoadPlanes  @ 00083350
void Mod_LoadPlanes(lump_t *l)

{
  float *pfVar1;
  int iVar2;
  uchar *puVar3;
  model_t *pmVar4;
  mplane_t *pmVar5;
  int32 iVar6;
  uint uVar7;
  byte bVar8;
  float *pfVar9;
  uint uVar10;
  longdouble lVar11;
  longdouble lVar12;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: mplane_t * out@[???]
                       Unresolved local var: dplane_t * in@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int bits@[???] */
  puVar3 = mod_base;
  uVar7 = l->filelen;
  iVar2 = l->fileofs;
  if (uVar7 != (uVar7 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 / 0x14;
  pmVar5 = Hunk_AllocName(uVar7 * 0x28,loadname);
  pmVar4 = loadmodel;
  loadmodel->planes = pmVar5;
  pmVar4->numplanes = uVar7;
  if (uVar7 != 0) {
    pfVar9 = (float *)(puVar3 + iVar2);
    uVar10 = 0;
    do {
      lVar11 = (longdouble)(*LittleFloat)(*pfVar9);
      pmVar5->normal[0] = (float)lVar11;
      lVar12 = (longdouble)(*LittleFloat)(pfVar9[1]);
      pmVar5->normal[1] = (float)lVar12;
      bVar8 = lVar11 < (longdouble)0;
      if (lVar12 < (longdouble)0) {
        bVar8 = lVar11 < (longdouble)0 | 2;
      }
      lVar11 = (longdouble)(*LittleFloat)(pfVar9[2]);
      pmVar5->normal[2] = (float)lVar11;
      if (lVar11 < (longdouble)0) {
        bVar8 = bVar8 | 4;
      }
      uVar10 = uVar10 + 1;
      lVar11 = (longdouble)(*LittleFloat)(pfVar9[3]);
      pmVar5->dist = (float)lVar11;
      pfVar1 = pfVar9 + 4;
      pfVar9 = pfVar9 + 5;
      iVar6 = (*LittleLong)((int32)*pfVar1);
      pmVar5->signbits = bVar8;
      pmVar5->type = (byte)iVar6;
      pmVar5 = pmVar5 + 1;
    } while (uVar7 != uVar10);
  }
  return;
}


// Mod_LoadSpriteFrame  @ 00084860
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
                       Unresolved local var: uchar * ppixin@[???] */
  iVar2 = (*LittleLong)(*(int32 *)((int)pin + 8));
  iVar3 = (*LittleLong)(*(int32 *)((int)pin + 0xc));
  count = iVar2 * iVar3;
  dest = Hunk_AllocName(r_pixbytes * count + 0x20,loadname);
  Q_memset(dest,0,r_pixbytes * count + 0x20);
  *ppframe = dest;
  dest->width = iVar2;
  dest->height = iVar3;
  iVar4 = (*LittleLong)(*(int32 *)pin);
  iVar5 = (*LittleLong)(*(int32 *)((int)pin + 4));
  dest->up = (float)iVar5;
  iVar1 = r_pixbytes;
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


// Mod_LoadSpriteGroup  @ 000849a0
void * Mod_LoadSpriteGroup(void *pin,mspriteframe_t **ppframe)

{
  int iVar1;
  int32 iVar2;
  mspriteframe_t *pmVar3;
  void *pvVar4;
  void *pin_00;
  int iVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: dspritegroup_t * pingroup@[???]
                       Unresolved local var: mspritegroup_t * pspritegroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: dspriteinterval_t * pin_intervals@[???]
                       Unresolved local var: float * poutintervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  iVar2 = (*LittleLong)(*(int32 *)pin);
  pmVar3 = Hunk_AllocName(iVar2 * 4 + 8,loadname);
  pmVar3->width = iVar2;
  *ppframe = pmVar3;
  pin_00 = (void *)((int)pin + 4);
  pvVar4 = Hunk_AllocName(iVar2 * 4,loadname);
  pmVar3->height = (int)pvVar4;
  if (0 < iVar2) {
    iVar5 = 0;
    do {
      while( true ) {
        lVar6 = (longdouble)(*LittleFloat)(*(float *)((int)pin + iVar5 * 4 + 4));
        *(float *)((int)pvVar4 + iVar5 * 4) = (float)lVar6;
        if ((longdouble)0 < lVar6) break;
        iVar5 = iVar5 + 1;
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
        if (iVar5 == iVar2) goto LAB_00084a4e;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != iVar2);
LAB_00084a4e:
    iVar5 = 0;
    pin_00 = (void *)((int)pin_00 + iVar2 * 4);
    do {
      iVar1 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      pin_00 = Mod_LoadSpriteFrame(pin_00,(mspriteframe_t **)(pmVar3->pixels + iVar1 + -0x14));
    } while (iVar5 != iVar2);
  }
  return pin_00;
}


// Mod_LoadSpriteModel  @ 00084a80
void Mod_LoadSpriteModel(model_t *mod,void *buffer)

{
  byte bVar1;
  int32 iVar2;
  undefined2 *puVar3;
  int32 iVar4;
  synctype_t sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  int32 *piVar9;
  longdouble lVar10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int version@[???]
                       Unresolved local var: dsprite_t * pin@[???]
                       Unresolved local var: msprite_t * psprite@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int palsize@[???]
                       Unresolved local var: dspriteframetype_t * pframetype@[???]
                       Unresolved local var: int entries@[???] */
  iVar2 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar2 != 2) {
    Sys_Error("%s has wrong version number (%i should be %i)",mod,iVar2,2);
  }
  iVar2 = (*LittleLong)(*(int32 *)((int)buffer + 0x1c));
  puVar3 = Hunk_AllocName(iVar2 * 8 + 0x1e + *(short *)((int)buffer + 0x28) * 8,loadname);
  (mod->cache).data = puVar3;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 8));
  *puVar3 = (short)iVar4;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0xc));
  puVar3[1] = (short)iVar4;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x14));
  *(int32 *)(puVar3 + 2) = iVar4;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x18));
  *(int32 *)(puVar3 + 4) = iVar4;
  lVar10 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  *(float *)(puVar3 + 10) = (float)lVar10;
  sVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x24));
  mod->synctype = sVar5;
  iVar7 = *(int *)(puVar3 + 2);
  *(int32 *)(puVar3 + 6) = iVar2;
  mod->mins[1] = (float)-(iVar7 / 2);
  mod->mins[0] = (float)-(iVar7 / 2);
  iVar7 = *(int *)(puVar3 + 2);
  mod->maxs[1] = (float)(iVar7 / 2);
  mod->maxs[0] = (float)(iVar7 / 2);
  mod->mins[2] = (float)-(*(int *)(puVar3 + 4) / 2);
  mod->maxs[2] = (float)(*(int *)(puVar3 + 4) / 2);
  *(int32 *)(puVar3 + 8) = iVar2 * 8 + 0x1e;
                    /* Unresolved local var: uchar * palsrc@[???]
                       Unresolved local var: ushort * paldest@[???] */
  uVar6 = (uint)*(ushort *)((int)buffer + 0x28);
  puVar8 = puVar3 + iVar2 * 4 + 0xe;
  *puVar8 = *(ushort *)((int)buffer + 0x28);
  if (uVar6 != 0) {
    iVar7 = 0;
    do {
      puVar8[1] = (ushort)*(byte *)((int)buffer + iVar7 + 0x2a);
      puVar8[2] = (ushort)*(byte *)((int)buffer + iVar7 + 0x2b);
      bVar1 = *(byte *)((int)buffer + iVar7 + 0x2c);
      iVar7 = iVar7 + 3;
      puVar8[4] = 0;
      puVar8[3] = (ushort)bVar1;
      puVar8 = puVar8 + 4;
    } while (iVar7 != uVar6 * 3);
  }
  if (iVar2 < 1) {
    Sys_Error("Mod_LoadSpriteModel: Invalid # of frames: %d\n",iVar2);
    mod->numframes = iVar2;
    mod->flags = 0;
  }
  else {
    iVar7 = 0;
    mod->numframes = iVar2;
    piVar9 = (int32 *)((int)buffer + uVar6 * 3 + 0x2a);
    mod->flags = 0;
    do {
      while( true ) {
        iVar4 = (*LittleLong)(*piVar9);
        *(int32 *)(puVar3 + iVar7 * 4 + 0xe) = iVar4;
        if (iVar4 == 0) break;
        piVar9 = Mod_LoadSpriteGroup(piVar9 + 1,(mspriteframe_t **)(puVar3 + iVar7 * 4 + 0x10));
        iVar7 = iVar7 + 1;
        if (iVar7 == iVar2) goto LAB_00084c99;
      }
                    /* Unresolved local var: spriteframetype_t frametype@[???] */
      piVar9 = Mod_LoadSpriteFrame(piVar9 + 1,(mspriteframe_t **)(puVar3 + iVar7 * 4 + 0x10));
      iVar7 = iVar7 + 1;
    } while (iVar7 != iVar2);
  }
LAB_00084c99:
  mod->type = mod_sprite;
  return;
}


// Mod_LoadStudioModel  @ 0007eee0
void Mod_LoadStudioModel(model_t *mod,void *buffer)

{
  byte *pbVar1;
  ushort *puVar2;
  byte bVar3;
  void *dest;
  int32 iVar4;
  ushort *dest_00;
  byte *pbVar5;
  int count;
  int iVar6;
  byte *src;
  int iVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar * pin@[???]
                       Unresolved local var: uchar * pout@[???]
                       Unresolved local var: uchar * pindata@[???]
                       Unresolved local var: uchar * poutdata@[???]
                       Unresolved local var: studiohdr_t * phdr@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int version@[???] */
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar4 != 10) {
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
    iVar7 = (int)dest + *(int *)((int)buffer + 0xb8);
    if (*(int *)((int)buffer + 0xb8) == 0) {
      Q_memcpy(dest,buffer,*(int *)((int)buffer + 0x48));
      return;
    }
    Q_memcpy(dest,buffer,*(int *)((int)buffer + 0xbc));
    if (0 < *(int *)((int)buffer + 0xb4)) {
      src = (byte *)((int)buffer + *(int *)((int)buffer + 0xbc));
      iVar6 = 0;
      dest_00 = (ushort *)(*(int *)((int)buffer + 0xbc) + (int)dest);
      do {
                    /* Unresolved local var: int j@[???] */
        *(int *)(iVar7 + 0x4c) = (int)dest_00 - (int)dest;
        count = *(int *)(iVar7 + 0x44) * *(int *)(iVar7 + 0x48);
        Q_memcpy(dest_00,src,count);
        dest_00 = (ushort *)((int)dest_00 + count);
        puVar2 = dest_00 + 0x400;
        pbVar5 = src + count;
        do {
          *dest_00 = (ushort)texgammatable[*pbVar5];
          dest_00[1] = (ushort)texgammatable[pbVar5[1]];
          pbVar1 = pbVar5 + 2;
          pbVar5 = pbVar5 + 3;
          bVar3 = texgammatable[*pbVar1];
          dest_00[3] = 0;
          dest_00[2] = (ushort)bVar3;
          dest_00 = dest_00 + 4;
        } while (dest_00 != puVar2);
        iVar6 = iVar6 + 1;
        src = src + count + 0x300;
        iVar7 = iVar7 + 0x50;
      } while (iVar6 < *(int *)((int)buffer + 0xb4));
    }
  }
  return;
}


// Mod_LoadSubmodels  @ 00081f30
void Mod_LoadSubmodels(lump_t *l)

{
  float *pfVar1;
  int iVar2;
  uchar *puVar3;
  model_t *pmVar4;
  dmodel_t *pdVar5;
  int32 iVar6;
  uint uVar7;
  float *pfVar8;
  uint uVar9;
  longdouble lVar10;
  
                    /* Unresolved local var: dmodel_t * in@[???]
                       Unresolved local var: dmodel_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???] */
  puVar3 = mod_base;
  uVar7 = l->filelen;
  iVar2 = l->fileofs;
  if ((uVar7 & 0x3f) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 >> 6;
  pdVar5 = Hunk_AllocName(uVar7 << 6,loadname);
  pmVar4 = loadmodel;
  loadmodel->submodels = pdVar5;
  pmVar4->numsubmodels = uVar7;
  if (uVar7 != 0) {
    pfVar8 = (float *)(puVar3 + iVar2);
    uVar9 = 0;
    do {
      uVar9 = uVar9 + 1;
      lVar10 = (longdouble)(*LittleFloat)(*pfVar8);
      pdVar5->mins[0] = (float)(lVar10 - (longdouble)1);
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[3]);
      pdVar5->maxs[0] = (float)((longdouble)1 + lVar10);
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[6]);
      pdVar5->origin[0] = (float)lVar10;
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[1]);
      pdVar5->mins[1] = (float)(lVar10 - (longdouble)1);
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[4]);
      pdVar5->maxs[1] = (float)((longdouble)1 + lVar10);
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[7]);
      pdVar5->origin[1] = (float)lVar10;
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[2]);
      pdVar5->mins[2] = (float)(lVar10 - (longdouble)1);
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[5]);
      pdVar5->maxs[2] = (float)((longdouble)1 + lVar10);
      lVar10 = (longdouble)(*LittleFloat)(pfVar8[8]);
      pdVar5->origin[2] = (float)lVar10;
      iVar6 = (*LittleLong)((int32)pfVar8[9]);
      pdVar5->headnode[0] = iVar6;
      iVar6 = (*LittleLong)((int32)pfVar8[10]);
      pdVar5->headnode[1] = iVar6;
      iVar6 = (*LittleLong)((int32)pfVar8[0xb]);
      pdVar5->headnode[2] = iVar6;
      iVar6 = (*LittleLong)((int32)pfVar8[0xc]);
      pdVar5->headnode[3] = iVar6;
      iVar6 = (*LittleLong)((int32)pfVar8[0xd]);
      pdVar5->visleafs = iVar6;
      iVar6 = (*LittleLong)((int32)pfVar8[0xe]);
      pdVar5->firstface = iVar6;
      pfVar1 = pfVar8 + 0xf;
      pfVar8 = pfVar8 + 0x10;
      iVar6 = (*LittleLong)((int32)*pfVar1);
      pdVar5->numfaces = iVar6;
      pdVar5 = pdVar5 + 1;
    } while (uVar7 != uVar9);
  }
  return;
}


// Mod_LoadSurfedges  @ 000832b0
void Mod_LoadSurfedges(lump_t *l)

{
  int iVar1;
  uchar *puVar2;
  model_t *pmVar3;
  int *piVar4;
  int32 iVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
  puVar2 = mod_base;
  iVar1 = l->fileofs;
  uVar7 = l->filelen;
  if ((uVar7 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 >> 2;
  piVar4 = Hunk_AllocName(uVar7 * 4,loadname);
  pmVar3 = loadmodel;
  loadmodel->surfedges = piVar4;
  pmVar3->numsurfedges = uVar7;
  if (uVar7 != 0) {
    uVar6 = 0;
    do {
      iVar5 = (*LittleLong)(*(int32 *)(puVar2 + uVar6 * 4 + iVar1));
      piVar4[uVar6] = iVar5;
      uVar6 = uVar6 + 1;
    } while (uVar7 != uVar6);
  }
  return;
}


// Mod_LoadTexinfo  @ 00082190
void Mod_LoadTexinfo(lump_t *l)

{
  int iVar1;
  texture_t *ptVar2;
  uchar *puVar3;
  model_t *pmVar4;
  mtexinfo_t *v;
  int32 iVar5;
  int32 iVar6;
  texture_t **pptVar7;
  uint uVar8;
  float *pfVar9;
  uint uVar10;
  longdouble lVar11;
  float fVar12;
  float fVar13;
  
                    /* Unresolved local var: texinfo_t * in@[???]
                       Unresolved local var: mtexinfo_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int miptex@[???]
                       Unresolved local var: float len1@[???]
                       Unresolved local var: float len2@[???] */
  puVar3 = mod_base;
  uVar8 = l->filelen;
  iVar1 = l->fileofs;
  if (uVar8 != (uVar8 / 0x28) * 0x28) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 / 0x28;
  v = Hunk_AllocName(uVar8 * 0x2c,loadname);
  pmVar4 = loadmodel;
  loadmodel->texinfo = v;
  pmVar4->numtexinfo = uVar8;
  if (uVar8 != 0) {
    pfVar9 = (float *)(puVar3 + iVar1);
    uVar10 = 0;
    do {
      while( true ) {
        lVar11 = (longdouble)(*LittleFloat)(*pfVar9);
        v->vecs[0][0] = (float)lVar11;
        lVar11 = (longdouble)(*LittleFloat)(pfVar9[1]);
        v->vecs[0][1] = (float)lVar11;
        lVar11 = (longdouble)(*LittleFloat)(pfVar9[2]);
        v->vecs[0][2] = (float)lVar11;
        lVar11 = (longdouble)(*LittleFloat)(pfVar9[3]);
        v->vecs[0][3] = (float)lVar11;
        lVar11 = (longdouble)(*LittleFloat)(pfVar9[4]);
        v->vecs[1][0] = (float)lVar11;
        lVar11 = (longdouble)(*LittleFloat)(pfVar9[5]);
        v->vecs[1][1] = (float)lVar11;
        lVar11 = (longdouble)(*LittleFloat)(pfVar9[6]);
        v->vecs[1][2] = (float)lVar11;
        lVar11 = (longdouble)(*LittleFloat)(pfVar9[7]);
        v->vecs[1][3] = (float)lVar11;
        fVar12 = Length((vec_t *)v);
        fVar13 = Length(v->vecs[1]);
        fVar12 = (fVar13 + fVar12) * 0.5;
        if (fVar12 < 0.32) {
          v->mipadjust = 4.0;
        }
        else if (0.49 <= fVar12) {
          fVar13 = 1.0;
          if (fVar12 < 0.99) {
            fVar13 = 2.0;
          }
          v->mipadjust = fVar13;
        }
        else {
          v->mipadjust = 3.0;
        }
        iVar5 = (*LittleLong)((int32)pfVar9[8]);
        iVar6 = (*LittleLong)((int32)pfVar9[9]);
        v->flags = iVar6;
        pptVar7 = loadmodel->textures;
        if (pptVar7 == (texture_t **)0x0) break;
        if (loadmodel->numtextures <= iVar5) {
          Sys_Error("miptex >= loadmodel->numtextures");
          pptVar7 = loadmodel->textures;
        }
        ptVar2 = pptVar7[iVar5];
        v->texture = ptVar2;
        if (ptVar2 == (texture_t *)0x0) break;
        uVar10 = uVar10 + 1;
        pfVar9 = pfVar9 + 10;
        v = v + 1;
        if (uVar8 == uVar10) {
          return;
        }
      }
      ptVar2 = r_notexture_mip;
      uVar10 = uVar10 + 1;
      pfVar9 = pfVar9 + 10;
      v->flags = 0;
      v->texture = ptVar2;
      v = v + 1;
    } while (uVar8 != uVar10);
  }
  return;
}


// Mod_LoadTextures  @ 000813d0
void Mod_LoadTextures(lump_t *l)

{
  byte *pbVar1;
  bool bVar2;
  model_t *pmVar3;
  int32 iVar4;
  texture_t **pptVar5;
  int iVar6;
  uint uVar7;
  texture_t *ptVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  ushort *puVar12;
  byte *pbVar13;
  int iVar14;
  uchar *name;
  int iVar15;
  int32 *piVar16;
  double dVar17;
  double dVar18;
  int iStack_553ec;
  int iStack_553e4;
  uchar auStack_553be [348994];
  int local_7c [12];
  int local_4c [15];
  
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
                       Unresolved local var: uchar[348994] dtexdata@[???]
                       Unresolved local var: qboolean wads_parsed@[???]
                       Unresolved local var: double starttime@[???] */
  dVar17 = Sys_FloatTime();
  if (tested == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * s@[???] */
    tested = 1;
    iVar14 = COM_CheckParm("-ad");
    if (((iVar14 != 0) && (pcVar9 = com_argv[iVar14 + 1], pcVar9 != (char *)0x0)) &&
       (*pcVar9 != '\0')) {
      snprintf(Mod_AdInit::filename,0x104,"%s",pcVar9);
      uVar10 = FS_FileSize(Mod_AdInit::filename);
      if ((int)uVar10 < 1) {
        Con_Printf("No -ad file specified, skipping\n");
      }
      else {
        Draw_CacheWadInit(Mod_AdInit::filename,0x10,&ad_wad);
        ad_enabled = 1;
      }
    }
  }
  if (l->filelen == 0) {
    loadmodel->textures = (texture_t **)0x0;
    return;
  }
  piVar16 = (int32 *)(mod_base + l->fileofs);
  iVar4 = (*LittleLong)(*piVar16);
  *piVar16 = iVar4;
  pmVar3 = loadmodel;
  loadmodel->numtextures = iVar4;
  pptVar5 = Hunk_AllocName(*piVar16 << 2,loadname);
  pmVar3->textures = pptVar5;
  if (0 < *piVar16) {
    iVar14 = 0;
    bVar2 = false;
    do {
      iVar4 = (*LittleLong)(piVar16[iVar14 + 1]);
      piVar16[iVar14 + 1] = iVar4;
      if (iVar4 != -1) {
        name = (uchar *)((int)piVar16 + iVar4);
        if ((r_wadtextures.value != 0.0) ||
           (iVar4 = (*LittleLong)(*(int32 *)(name + 0x18)), iVar4 == 0)) {
          if (!bVar2) {
            TEX_InitFromWad(wadpath);
            TEX_AddAnimatingTextures();
          }
          iVar6 = TEX_LoadLump((char *)name,auStack_553be,0x55342);
          if (iVar6 == 0) {
            piVar16[iVar14 + 1] = -1;
            bVar2 = true;
            goto LAB_000814db;
          }
          bVar2 = true;
          name = auStack_553be;
        }
        iVar4 = (*LittleLong)(*(int32 *)(name + 0x18));
        *(int32 *)(name + 0x18) = iVar4;
        iVar4 = (*LittleLong)(*(int32 *)(name + 0x1c));
        *(int32 *)(name + 0x1c) = iVar4;
        iVar4 = (*LittleLong)(*(int32 *)(name + 0x20));
        *(int32 *)(name + 0x20) = iVar4;
        iVar4 = (*LittleLong)(*(int32 *)(name + 0x24));
        *(int32 *)(name + 0x24) = iVar4;
        iVar4 = (*LittleLong)(*(int32 *)(name + 0x10));
        *(int32 *)(name + 0x10) = iVar4;
        uVar7 = (*LittleLong)(*(int32 *)(name + 0x14));
        uVar10 = *(uint *)(name + 0x10);
        *(uint *)(name + 0x14) = uVar7;
        if (((uVar7 | uVar10) & 0xf) != 0) {
          Sys_Error("Texture %s is not 16 aligned",name);
          uVar10 = *(uint *)(name + 0x10);
          uVar7 = *(uint *)(name + 0x14);
        }
        iVar6 = (uVar7 * uVar10 >> 6) * 0x55;
        uVar10 = (uint)*(ushort *)(name + iVar6 + 0x28);
        uVar7 = iVar6 + 0x42;
        ptVar8 = Hunk_AllocName(uVar10 * 8 + uVar7,loadname);
        loadmodel->textures[iVar14] = ptVar8;
        Q_memcpy(ptVar8,name,0x10);
        pcVar9 = strchr(ptVar8->name,0x7e);
        if (pcVar9 != (char *)0x0) {
          ptVar8->name[2] = ' ';
        }
        ptVar8->width = *(uint *)(name + 0x10);
        ptVar8->height = *(uint *)(name + 0x14);
        ptVar8->offsets[0] = *(int *)(name + 0x18) + 0x18;
        ptVar8->offsets[1] = *(int *)(name + 0x1c) + 0x18;
        ptVar8->offsets[2] = *(int *)(name + 0x20) + 0x18;
        iVar15 = *(int *)(name + 0x24);
        ptVar8->paloffset = uVar7;
        ptVar8->offsets[3] = iVar15 + 0x18;
        Q_memcpy(ptVar8 + 1,name + 0x28,iVar6 + 2);
        pbVar13 = name + iVar6 + 0x2a;
        puVar12 = (ushort *)(uVar7 + (int)ptVar8);
        iVar15 = Q_strncmp((char *)name,"sky",3);
        if (iVar15 == 0) {
          R_InitSky();
        }
        if (uVar10 != 0) {
          uVar7 = 0;
          do {
            puVar12[3] = 0;
            uVar7 = uVar7 + 1;
            puVar12[2] = (ushort)texgammatable[*pbVar13];
            puVar12[1] = (ushort)texgammatable[pbVar13[1]];
            pbVar1 = pbVar13 + 2;
            pbVar13 = pbVar13 + 3;
            *puVar12 = (ushort)texgammatable[*pbVar1];
            puVar12 = puVar12 + 4;
          } while (uVar7 != uVar10);
        }
        if ((ad_enabled != 0) && (iVar15 = Q_stricmp(ptVar8->name,"DEFAULT"), iVar15 == 0)) {
          Mod_AdSwap(ptVar8,iVar6,uVar10);
        }
      }
LAB_000814db:
      iVar4 = *piVar16;
      iVar14 = iVar14 + 1;
    } while (iVar14 < iVar4);
    if (bVar2) {
      TEX_CleanupWadInfo();
      iVar4 = *piVar16;
    }
    if (0 < iVar4) {
      iVar14 = 1;
      do {
        iVar6 = iVar14 * 4;
        ptVar8 = loadmodel->textures[iVar14 + -1];
        if ((ptVar8 != (texture_t *)0x0) &&
           (((ptVar8->name[0] == '-' || (ptVar8->name[0] == '+')) &&
            (ptVar8->anim_next == (texture_s *)0x0)))) {
          Q_memset(local_7c,0,0x28);
          Q_memset(local_4c,0,0x28);
          iVar15 = (int)ptVar8->name[1];
          iStack_553ec = iVar15 + -0x20;
          if (0x19 < iVar15 - 0x61U) {
            iStack_553ec = iVar15;
          }
          uVar10 = iStack_553ec - 0x30;
          if (uVar10 < 10) {
            iStack_553ec = iStack_553ec + -0x2f;
            local_7c[uVar10] = (int)ptVar8;
            iStack_553e4 = 0;
          }
          else if (iStack_553ec - 0x41U < 10) {
            local_4c[iStack_553ec - 0x41U] = (int)ptVar8;
            iStack_553e4 = iStack_553ec + -0x40;
            iStack_553ec = 0;
          }
          else {
            Sys_Error("Bad animating texture %s",ptVar8);
            iStack_553e4 = 0;
          }
          iVar4 = *piVar16;
          if (iVar14 < iVar4) {
            iVar15 = iVar14;
            do {
              while ((pcVar9 = *(char **)((int)loadmodel->textures + iVar6), pcVar9 != (char *)0x0
                     && ((*pcVar9 == '-' || (*pcVar9 == '+'))))) {
                iVar11 = Q_strcmp(pcVar9 + 2,ptVar8->name + 2);
                if (iVar11 == 0) {
                  iVar11 = (int)pcVar9[1];
                  if (iVar11 - 0x61U < 0x1a) {
                    iVar11 = iVar11 + -0x20;
                  }
                  uVar10 = iVar11 - 0x30;
                  if (uVar10 < 10) {
                    local_7c[uVar10] = (int)pcVar9;
                    if (iStack_553ec <= (int)uVar10) {
                      iStack_553ec = iVar11 + -0x2f;
                      iVar4 = *piVar16;
                      break;
                    }
                  }
                  else {
                    uVar10 = iVar11 - 0x41;
                    if (uVar10 < 10) {
                      local_4c[uVar10] = (int)pcVar9;
                      if (iStack_553e4 <= (int)uVar10) {
                        iStack_553e4 = iVar11 + -0x40;
                        iVar4 = *piVar16;
                        break;
                      }
                    }
                    else {
                      Sys_Error("Bad animating texture %s",ptVar8);
                    }
                  }
                }
                iVar15 = iVar15 + 1;
                iVar6 = iVar6 + 4;
                iVar4 = *piVar16;
                if (iVar4 <= iVar15) goto LAB_000819f8;
              }
              iVar15 = iVar15 + 1;
              iVar6 = iVar6 + 4;
            } while (iVar15 < iVar4);
          }
LAB_000819f8:
          if (iStack_553ec < 1) {
LAB_00081aec:
            if (0 < iStack_553e4) {
              iVar6 = 0;
              if (iStack_553ec == 0) {
                iVar6 = 0;
                do {
                  iVar15 = local_4c[iVar6];
                  if (iVar15 == 0) {
                    Sys_Error("Missing frame %i of %s",iVar6);
                  }
                  *(int *)(iVar15 + 0x1c) = iVar6;
                  iVar6 = iVar6 + 1;
                  *(int *)(iVar15 + 0x18) = iStack_553e4;
                  *(int *)(iVar15 + 0x20) = iVar6;
                  *(int *)(iVar15 + 0x24) = local_4c[iVar6 % iStack_553e4];
                } while (iVar6 != iStack_553e4);
              }
              else {
                do {
                  iVar15 = local_4c[iVar6];
                  if (iVar15 == 0) {
                    Sys_Error("Missing frame %i of %s",iVar6);
                  }
                  *(int *)(iVar15 + 0x1c) = iVar6;
                  iVar6 = iVar6 + 1;
                  *(int *)(iVar15 + 0x18) = iStack_553e4;
                  *(int *)(iVar15 + 0x20) = iVar6;
                  *(int *)(iVar15 + 0x24) = local_4c[iVar6 % iStack_553e4];
                  *(int *)(iVar15 + 0x28) = local_7c[0];
                } while (iVar6 != iStack_553e4);
              }
            }
          }
          else {
            iVar6 = 0;
            if (iStack_553e4 != 0) {
              do {
                iVar15 = local_7c[iVar6];
                if (iVar15 == 0) {
                  Sys_Error("Missing frame %i of %s",iVar6);
                }
                *(int *)(iVar15 + 0x1c) = iVar6;
                iVar6 = iVar6 + 1;
                *(int *)(iVar15 + 0x18) = iStack_553ec;
                *(int *)(iVar15 + 0x20) = iVar6;
                *(int *)(iVar15 + 0x24) = local_7c[iVar6 % iStack_553ec];
                *(int *)(iVar15 + 0x28) = local_4c[0];
              } while (iVar6 != iStack_553ec);
              goto LAB_00081aec;
            }
            iVar6 = 0;
            do {
              iVar15 = local_7c[iVar6];
              if (iVar15 == 0) {
                Sys_Error("Missing frame %i of %s",iVar6);
              }
              *(int *)(iVar15 + 0x1c) = iVar6;
              iVar6 = iVar6 + 1;
              *(int *)(iVar15 + 0x18) = iStack_553ec;
              *(int *)(iVar15 + 0x20) = iVar6;
              *(int *)(iVar15 + 0x24) = local_7c[iVar6 % iStack_553ec];
            } while (iVar6 != iStack_553ec);
          }
          iVar4 = *piVar16;
        }
        bVar2 = iVar14 < iVar4;
        iVar14 = iVar14 + 1;
      } while (bVar2);
    }
  }
  dVar18 = Sys_FloatTime();
  Con_DPrintf("Texture load: %6.1fms\n",(dVar18 - dVar17) * 1000.0);
  return;
}


// Mod_LoadVertexes  @ 00081e60
void Mod_LoadVertexes(lump_t *l)

{
  float *pfVar1;
  int iVar2;
  uchar *puVar3;
  model_t *pmVar4;
  mvertex_t *pmVar5;
  uint uVar6;
  float *pfVar7;
  uint uVar8;
  longdouble lVar9;
  
                    /* Unresolved local var: dvertex_t * in@[???]
                       Unresolved local var: mvertex_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  puVar3 = mod_base;
  uVar6 = l->filelen;
  iVar2 = l->fileofs;
  if (uVar6 != (uVar6 / 0xc) * 0xc) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar6 = l->filelen;
  }
  uVar6 = uVar6 / 0xc;
  pmVar5 = Hunk_AllocName(uVar6 * 0xc,loadname);
  pmVar4 = loadmodel;
  loadmodel->vertexes = pmVar5;
  pmVar4->numvertexes = uVar6;
  if (uVar6 != 0) {
    pfVar7 = (float *)(puVar3 + iVar2);
    uVar8 = 0;
    do {
      uVar8 = uVar8 + 1;
      lVar9 = (longdouble)(*LittleFloat)(*pfVar7);
      pmVar5->position[0] = (float)lVar9;
      lVar9 = (longdouble)(*LittleFloat)(pfVar7[1]);
      pmVar5->position[1] = (float)lVar9;
      pfVar1 = pfVar7 + 2;
      pfVar7 = pfVar7 + 3;
      lVar9 = (longdouble)(*LittleFloat)(*pfVar1);
      pmVar5->position[2] = (float)lVar9;
      pmVar5 = pmVar5 + 1;
    } while (uVar6 != uVar8);
  }
  return;
}


// Mod_LoadVisibility  @ 00081d00
void Mod_LoadVisibility(lump_t *l)

{
  model_t *pmVar1;
  byte *pbVar2;
  
  pmVar1 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->visdata = (byte *)0x0;
    return;
  }
  pbVar2 = Hunk_AllocName(l->filelen,loadname);
  pmVar1->visdata = pbVar2;
  Q_memcpy(loadmodel->visdata,mod_base + l->fileofs,l->filelen);
  return;
}


// Mod_MakeHull0  @ 000830d0
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
      if (iVar8 < 0) goto LAB_000831bc;
LAB_00083164:
      pdVar3->children[1] = (short)((int)pmVar5 - (int)loadmodel->nodes >> 3) * -0x3333;
      pmVar7 = loadmodel;
    }
    else {
      pdVar3->children[0] = (short)((int)pmVar6->children[0] - (int)loadmodel->nodes >> 3) * -0x3333
      ;
      pmVar5 = pmVar6->children[1];
      iVar8 = pmVar5->contents;
      if (-1 < iVar8) goto LAB_00083164;
LAB_000831bc:
      pdVar3->children[1] = (short)iVar8;
      pmVar7 = loadmodel;
    }
    if (iVar4 + 1 == iVar1) {
      loadmodel = pmVar7;
      return;
    }
    iVar4 = iVar4 + 1;
    pdVar3 = pdVar3 + 1;
    pmVar6 = pmVar6 + 1;
    loadmodel = pmVar7;
  } while( true );
}


// Mod_MarkClient  @ 00081250
void Mod_MarkClient(model_t *pModel)

{
  pModel->needload = 3;
  return;
}


// Mod_NeedCRC  @ 00081210
void Mod_NeedCRC(char *name,qboolean needCRC)

{
  model_t *pmVar1;
  
                    /* Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  pmVar1 = Mod_FindName(false,name);
  *(qboolean *)
   ((int)mod_known_info + ((int)(pmVar1[-0x1f1b].hulls[1].clip_maxs + 1) >> 3) * 0x397829cc) =
       needCRC;
  return;
}


// Mod_PointInLeaf  @ 00080f10
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


// Mod_Print  @ 000851c0
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


// Mod_SetParent  @ 000829a0
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
  
  iVar1 = node->contents;
  node->parent = parent;
  while (-1 < iVar1) {
    pmVar2 = node->children[0];
    iVar1 = pmVar2->contents;
    pmVar2->parent = node;
    while (-1 < iVar1) {
      pmVar3 = pmVar2->children[0];
      pmVar3->parent = pmVar2;
      iVar1 = pmVar3->contents;
      while (-1 < iVar1) {
        pmVar4 = pmVar3->children[0];
        pmVar4->parent = pmVar3;
        iVar1 = pmVar4->contents;
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
                    iVar1 = pmVar9->contents;
                    pmVar9->parent = parent_00;
                    parent_00 = pmVar9;
                  }
                  pmVar9 = pmVar8->children[1];
                  pmVar9->parent = pmVar8;
                  pmVar8 = pmVar9;
                  iVar1 = pmVar9->contents;
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
            pmVar6->parent = pmVar5;
            pmVar5 = pmVar6;
            iVar1 = pmVar6->contents;
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


// Mod_UnloadSpriteTextures  @ 000851a0
void Mod_UnloadSpriteTextures(model_t *pModel)

{
  if ((pModel != (model_t *)0x0) && (pModel->type == mod_sprite)) {
    pModel->needload = true;
    return;
  }
  return;
}


// Mod_ValidateCRC  @ 000811c0
qboolean Mod_ValidateCRC(char *name,CRC32_t crc)

{
  int iVar1;
  model_t *pmVar2;
  qboolean qVar3;
  
                    /* Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[DW_OP_reg2(EDX)] */
  pmVar2 = Mod_FindName(true,name);
  iVar1 = ((int)(pmVar2[-0x1f1b].hulls[1].clip_maxs + 1) >> 3) * 0x397829cc;
  qVar3 = true;
  if (*(int *)((int)mod_known_info + iVar1 + 4) != 0) {
    qVar3 = (qboolean)(*(CRC32_t *)((int)mod_known_info + iVar1 + 8) == crc);
  }
  return qVar3;
}


