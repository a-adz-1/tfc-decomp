// Mod_AdInit  @ 001b9cf0
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
      Draw_CacheWadHandler(&ad_wad,Draw_MiptexTexture,0x20);
      ad_enabled = 1;
      return;
    }
    Con_Printf("No -ad file specified, skipping\n");
  }
  return;
}


// Mod_AdSwap  @ 001b9dc0
void Mod_AdSwap(texture_t *src,int pixels,uchar **rawtex,uchar **pPal,int entries)

{
  int index;
  void *pvVar1;
  
                    /* Unresolved local var: texture_t * tex@[???] */
  if (tested != 0) {
    index = Draw_CacheIndex(&ad_wad,"img");
    pvVar1 = Draw_CacheGet(&ad_wad,index);
    if (pvVar1 != (void *)0x0) {
      *rawtex = (uchar *)((int)pvVar1 + 0x48);
      *pPal = (uchar *)((int)pvVar1 + pixels + 0x4a);
      return;
    }
  }
  return;
}


// Mod_ChangeGame  @ 001b9c60
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


// Mod_ClearAll  @ 001b99c0
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
      while (((pmVar2->type == mod_alias || (pmVar2->needload == 3)) ||
             (pmVar2->needload = 2, pmVar2->type != mod_sprite))) {
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


// Mod_DecompressVis  @ 00108100
byte * Mod_DecompressVis(byte *in,model_t *model)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  
                    /* Unresolved local var: int row@[???] */
  iVar1 = model->numleafs;
  pbVar2 = mod_novis;
  if (in != (byte *)0x0) {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: byte * out@[???] */
    pbVar2 = Mod_DecompressVis::decompressed;
LAB_0010814e:
    do {
      if (*in == '\0') {
        uVar8 = (uint)in[1];
        in = in + 2;
        if (uVar8 != 0) {
          uVar4 = -(int)pbVar2 & 0xfU;
          if (uVar8 < (-(int)pbVar2 & 0xfU)) {
            uVar4 = uVar8;
          }
          pbVar3 = pbVar2;
          uVar9 = uVar8;
          if (uVar4 == 0) {
LAB_0010818f:
            uVar6 = uVar8 - uVar4 >> 4;
            if (uVar6 != 0) {
              pauVar5 = (undefined1 (*) [16])(pbVar2 + uVar4);
              uVar7 = 0;
              do {
                uVar7 = uVar7 + 1;
                *pauVar5 = (undefined1  [16])0x0;
                pauVar5 = pauVar5 + 1;
              } while (uVar7 < uVar6);
              uVar9 = uVar9 + uVar6 * -0x10;
              pbVar3 = pbVar3 + uVar6 * 0x10;
              if (uVar8 - uVar4 == uVar6 * 0x10) goto LAB_001081e8;
            }
            pbVar10 = pbVar3 + uVar9;
            do {
              *pbVar3 = '\0';
              pbVar3 = pbVar3 + 1;
            } while (pbVar3 != pbVar10);
          }
          else {
            uVar6 = 0;
            do {
              uVar6 = uVar6 + 1;
              uVar9 = uVar9 - 1;
              *pbVar3 = '\0';
              pbVar3 = pbVar3 + 1;
            } while (uVar6 < uVar4);
            if (uVar8 != uVar4) goto LAB_0010818f;
          }
LAB_001081e8:
          pbVar2 = pbVar2 + uVar8;
          if (Mod_DecompressVis::decompressed + (iVar1 + 7 >> 3) <= pbVar2) break;
          goto LAB_0010814e;
        }
      }
      else {
        *pbVar2 = *in;
        in = in + 1;
        pbVar2 = pbVar2 + 1;
      }
    } while (pbVar2 < Mod_DecompressVis::decompressed + (iVar1 + 7 >> 3));
    pbVar2 = Mod_DecompressVis::decompressed;
  }
  return pbVar2;
}


// Mod_Extradata  @ 001bdb00
void * Mod_Extradata(model_t *mod)

{
  void *pvVar1;
  
                    /* Unresolved local var: void * r@[???] */
  if (mod == (model_t *)0x0) {
    return (void *)0x0;
  }
  pvVar1 = Cache_Check(&mod->cache);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[4096] tmpName@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  if (mod->type - mod_alias < 2) {
    pvVar1 = Cache_Check(&mod->cache);
    if (pvVar1 != (void *)0x0) {
      mod->needload = false;
      goto LAB_001bdb5d;
    }
  }
  else if ((mod->needload == 3) || (mod->needload == false)) goto LAB_001bdb5d;
  Mod_LoadModel(mod,true,false);
LAB_001bdb5d:
  pvVar1 = (mod->cache).data;
  if (pvVar1 == (void *)0x0) {
    Sys_Error("Mod_Extradata: caching failed");
    pvVar1 = (mod->cache).data;
  }
  return pvVar1;
}


// Mod_FillInCRCInfo  @ 001b9a20
void Mod_FillInCRCInfo(qboolean trackCRC,int model_number)

{
                    /* Unresolved local var: mod_known_info_t * p@[DW_OP_reg0(EAX)] */
  mod_known_info[model_number].firstCRCDone = false;
  mod_known_info[model_number].shouldCRC = trackCRC;
  mod_known_info[model_number].initialCRC = 0;
  return;
}


// Mod_FindName  @ 001b9a50
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
    Sys_Error("Mod_FindName: NULL name");
  }
  pmVar4 = (model_t *)0x0;
  iVar5 = 0;
  s1 = mod_known;
  if (0 < mod_numknown) {
    do {
      while( true ) {
        iVar3 = Q_strcmp(s1->name,name);
        if (iVar3 == 0) {
          if (iVar5 != mod_numknown) {
            return s1;
          }
          goto LAB_001b9ae9;
        }
        pmVar2 = pmVar4;
        if ((s1->needload == 2) && (pmVar2 = s1, pmVar4 != (model_t *)0x0)) break;
        pmVar4 = pmVar2;
        iVar5 = iVar5 + 1;
        s1 = s1 + 1;
        if (mod_numknown <= iVar5) goto LAB_001b9aca;
      }
      if (1 < s1->type - mod_alias) {
        pmVar4 = s1;
      }
      iVar5 = iVar5 + 1;
      s1 = s1 + 1;
    } while (iVar5 < mod_numknown);
  }
LAB_001b9aca:
  if (iVar5 == mod_numknown) {
LAB_001b9ae9:
    if (iVar5 < 0x400) {
                    /* Unresolved local var: mod_known_info_t * p@[DW_OP_reg0(EAX)] */
      mod_numknown = iVar5 + 1;
      mod_known_info[iVar5].firstCRCDone = false;
      mod_known_info[iVar5].initialCRC = 0;
      mod_known_info[iVar5].shouldCRC = trackCRC;
    }
    else if (pmVar4 == (model_t *)0x0) {
      Sys_Error("mod_numknown >= MAX_KNOWN_MODELS");
    }
    else {
                    /* Unresolved local var: mod_known_info_t * p@[DW_OP_reg0(EAX)] */
      iVar5 = ((int)&pmVar4[-0x9aa7].numedges >> 3) * 0x397829cc;
      *(qboolean *)((int)mod_known_info + iVar5) = trackCRC;
      *(undefined4 *)((int)mod_known_info + iVar5 + 4) = 0;
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


// Mod_FloodFillSkin  @ 001bc7f0
void Mod_FloodFillSkin(uchar *skin,int skinwidth,int skinheight)

{
  uchar uVar1;
  uchar uVar2;
  uint uVar3;
  uchar uVar4;
  uchar *puVar5;
  short sVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  uint local_402c;
  short local_401c [8198];
  
                    /* Unresolved local var: uchar fillcolor@[???]
                       Unresolved local var: floodfill_t[4096] fifo@[???]
                       Unresolved local var: int inpt@[???]
                       Unresolved local var: int outpt@[???]
                       Unresolved local var: int filledcolor@[???] */
  uVar1 = *skin;
  if ((uVar1 != '\0') && (uVar1 != 0xff)) {
    iVar9 = 0;
    iVar7 = 0;
    local_401c[0] = 0;
    local_401c[1] = 0;
    uVar3 = 0;
    local_402c = 1;
    while( true ) {
      uVar4 = '\0';
      uVar3 = uVar3 + 1 & 0xfff;
      puVar5 = skin + skinwidth * iVar9 + iVar7;
      sVar8 = (short)iVar9;
      sVar6 = (short)iVar7;
      if (0 < iVar7) {
        uVar2 = puVar5[-1];
        if (uVar2 == uVar1) {
          puVar5[-1] = 0xff;
          local_401c[local_402c * 2] = sVar6 + -1;
          local_401c[local_402c * 2 + 1] = sVar8;
          local_402c = local_402c + 1 & 0xfff;
        }
        else {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int fdc@[???]
                       Unresolved local var: uchar * pos@[???] */
          if (uVar2 != 0xff) {
            uVar4 = uVar2;
          }
        }
      }
      if (iVar7 < skinwidth + -1) {
        uVar2 = puVar5[1];
        if (uVar2 == uVar1) {
          puVar5[1] = 0xff;
          local_401c[local_402c * 2] = sVar6 + 1;
          local_401c[local_402c * 2 + 1] = sVar8;
          local_402c = local_402c + 1 & 0xfff;
        }
        else if (uVar2 != 0xff) {
          uVar4 = uVar2;
        }
      }
      if (0 < iVar9) {
        uVar2 = puVar5[-skinwidth];
        if (uVar2 == uVar1) {
          puVar5[-skinwidth] = 0xff;
          local_401c[local_402c * 2] = sVar6;
          local_401c[local_402c * 2 + 1] = sVar8 + -1;
          local_402c = local_402c + 1 & 0xfff;
        }
        else if (uVar2 != 0xff) {
          uVar4 = uVar2;
        }
      }
      if (iVar9 < skinheight + -1) {
        uVar2 = puVar5[skinwidth];
        if (uVar2 == uVar1) {
          puVar5[skinwidth] = 0xff;
          local_401c[local_402c * 2] = sVar6;
          local_401c[local_402c * 2 + 1] = sVar8 + 1;
          local_402c = local_402c + 1 & 0xfff;
        }
        else if (uVar2 != 0xff) {
          uVar4 = uVar2;
        }
      }
      *puVar5 = uVar4;
      if (local_402c == uVar3) break;
      iVar7 = (int)local_401c[uVar3 * 2];
      iVar9 = (int)local_401c[uVar3 * 2 + 1];
    }
  }
  return;
}


// Mod_ForName  @ 001bda60
model_t * Mod_ForName(char *name,qboolean crash,qboolean trackCRC)

{
  model_t *pmVar1;
  void *pvVar2;
  
                    /* Unresolved local var: model_t * mod@[???] */
  pmVar1 = Mod_FindName(trackCRC,name);
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[4096] tmpName@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  if (pmVar1->type - mod_alias < 2) {
    pvVar2 = Cache_Check(&pmVar1->cache);
    if (pvVar2 != (void *)0x0) {
      pmVar1->needload = false;
      return pmVar1;
    }
  }
  else if ((pmVar1->needload == 3) || (pmVar1->needload == false)) {
    return pmVar1;
  }
  pmVar1 = Mod_LoadModel(pmVar1,crash,trackCRC);
  return pmVar1;
}


// Mod_Init  @ 001080d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_Init(void)

{
  Q_memset(mod_novis,0xff,0x400);
  return;
}


// Mod_LeafPVS  @ 00108210
byte * Mod_LeafPVS(mleaf_t *leaf,model_t *model)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  pbVar2 = mod_novis;
  if (model->leafs != leaf) {
    if (gPVS == (byte *)0x0) {
      pbVar11 = leaf->compressed_vis;
                    /* Unresolved local var: int row@[???] */
      iVar1 = model->numleafs;
      if (pbVar11 != (byte *)0x0) {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: byte * out@[???] */
        pbVar2 = Mod_DecompressVis::decompressed;
        do {
          if (*pbVar11 == '\0') {
            uVar8 = (uint)pbVar11[1];
            pbVar11 = pbVar11 + 2;
            if (uVar8 != 0) {
              uVar4 = -(int)pbVar2 & 0xfU;
              if (uVar8 < (-(int)pbVar2 & 0xfU)) {
                uVar4 = uVar8;
              }
              pbVar3 = pbVar2;
              uVar9 = uVar8;
              if (uVar4 == 0) {
LAB_001082ef:
                uVar6 = uVar8 - uVar4 >> 4;
                if (uVar6 != 0) {
                  pauVar5 = (undefined1 (*) [16])(pbVar2 + uVar4);
                  uVar7 = 0;
                  do {
                    uVar7 = uVar7 + 1;
                    *pauVar5 = (undefined1  [16])0x0;
                    pauVar5 = pauVar5 + 1;
                  } while (uVar7 < uVar6);
                  uVar9 = uVar9 + uVar6 * -0x10;
                  pbVar3 = pbVar3 + uVar6 * 0x10;
                  if (uVar8 - uVar4 == uVar6 * 0x10) goto LAB_00108348;
                }
                pbVar10 = pbVar3 + uVar9;
                do {
                  *pbVar3 = '\0';
                  pbVar3 = pbVar3 + 1;
                } while (pbVar3 != pbVar10);
              }
              else {
                uVar6 = 0;
                do {
                  uVar6 = uVar6 + 1;
                  uVar9 = uVar9 - 1;
                  *pbVar3 = '\0';
                  pbVar3 = pbVar3 + 1;
                } while (uVar6 < uVar4);
                if (uVar4 != uVar8) goto LAB_001082ef;
              }
LAB_00108348:
              pbVar2 = pbVar2 + uVar8;
            }
          }
          else {
            *pbVar2 = *pbVar11;
            pbVar11 = pbVar11 + 1;
            pbVar2 = pbVar2 + 1;
          }
        } while (pbVar2 < Mod_DecompressVis::decompressed + (iVar1 + 7 >> 3));
        pbVar2 = Mod_DecompressVis::decompressed;
      }
    }
    else {
                    /* Unresolved local var: int leafnum@[???] */
      pbVar2 = gPVS + ((int)leaf - (int)model->leafs >> 2) * -0x11111111 * gPVSRowBytes;
    }
  }
  return pbVar2;
}


// Mod_LoadAliasFrame  @ 001bc6a0
void * Mod_LoadAliasFrame(void *pin,maliasframedesc_t *frame)

{
  int iVar1;
  
                    /* Unresolved local var: trivertx_t * pinframe@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: daliasframe_t * pdaliasframe@[???] */
  Q_strncpy(frame->name,(char *)((int)pin + 8),0xf);
  iVar1 = posenum;
  frame->name[0xf] = '\0';
  frame->numposes = 1;
  frame->firstpose = iVar1;
  (frame->bboxmin).v[0] = *(byte *)pin;
  (frame->bboxmin).v[0] = *(byte *)((int)pin + 4);
  (frame->bboxmin).v[1] = *(byte *)((int)pin + 1);
  (frame->bboxmin).v[1] = *(byte *)((int)pin + 5);
  (frame->bboxmin).v[2] = *(byte *)((int)pin + 2);
  (frame->bboxmin).v[2] = *(byte *)((int)pin + 6);
  poseverts[posenum] = (trivertx_t *)((int)pin + 0x18);
  posenum = posenum + 1;
  return (trivertx_t *)((int)pin + 0x18) + pheader->numverts;
}


// Mod_LoadAliasGroup  @ 001bc730
void * Mod_LoadAliasGroup(void *pin,maliasframedesc_t *frame)

{
  aliashdr_t *paVar1;
  int32 iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: daliasgroup_t * pingroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: daliasinterval_t * pin_intervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  iVar2 = (*LittleLong)(*(int32 *)pin);
  iVar5 = posenum;
  frame->numposes = iVar2;
  frame->firstpose = iVar5;
  (frame->bboxmin).v[0] = *(byte *)((int)pin + 4);
  (frame->bboxmin).v[0] = *(byte *)((int)pin + 8);
  (frame->bboxmin).v[1] = *(byte *)((int)pin + 5);
  (frame->bboxmin).v[1] = *(byte *)((int)pin + 9);
  (frame->bboxmin).v[2] = *(byte *)((int)pin + 6);
  (frame->bboxmin).v[2] = *(byte *)((int)pin + 10);
  lVar6 = (longdouble)(*LittleFloat)(*(float *)((int)pin + 0xc));
  pvVar4 = (void *)((int)pin + iVar2 * 4 + 0xc);
  frame->interval = (float)lVar6;
  paVar1 = pheader;
  if (0 < iVar2) {
    iVar3 = 0;
    iVar5 = posenum;
    do {
      iVar3 = iVar3 + 1;
      poseverts[iVar5] = (trivertx_t *)((int)pvVar4 + 0x18);
      iVar5 = iVar5 + 1;
      pvVar4 = (void *)((int)pvVar4 + paVar1->numverts * 4 + 0x18);
    } while (iVar3 != iVar2);
    posenum = posenum + iVar3;
  }
  return pvVar4;
}


// Mod_LoadAliasModel  @ 001bcb60
void Mod_LoadAliasModel(model_t *mod,void *buffer)

{
  int32 *piVar1;
  void *dest;
  aliashdr_t *paVar2;
  aliashdr_t *paVar3;
  int mark;
  int32 iVar4;
  synctype_t sVar5;
  int32 *piVar6;
  stvert_t *psVar7;
  mtriangle_t *pmVar8;
  int32 *piVar9;
  int iVar10;
  int iVar11;
  longdouble lVar12;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: mdl_t * pinmodel@[???]
                       Unresolved local var: stvert_t * pinstverts@[???]
                       Unresolved local var: dtriangle_t * pintriangles@[???]
                       Unresolved local var: int version@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: daliasframetype_t * pframetype@[???]
                       Unresolved local var: daliasskintype_t * pskintype@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???]
                       Unresolved local var: int total@[???] */
  mark = Hunk_LowMark();
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar4 != 6) {
    Sys_Error("Mod_LoadAliasModel: Model %s has wrong version number (%i should be %i)",mod,iVar4,6)
    ;
  }
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  pheader = Hunk_AllocName((iVar4 * 5 + -5) * 8 + 0x10c,loadname);
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x4c));
  paVar2 = pheader;
  mod->flags = iVar4;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  paVar2->boundingradius = (float)lVar12;
  paVar2 = pheader;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x30));
  paVar2->numskins = iVar4;
  paVar2 = pheader;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x34));
  paVar2->skinwidth = iVar4;
  paVar2 = pheader;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x38));
  paVar2->skinheight = iVar4;
  if (0x1e0 < pheader->skinheight) {
    Sys_Error("Mod_LoadAliasModel: Model %s has a skin taller than %d",mod,0x1e0);
  }
  paVar2 = pheader;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x3c));
  paVar2->numverts = iVar4;
  iVar11 = pheader->numverts;
  if (iVar11 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no vertices: %d",mod,iVar11);
    iVar11 = pheader->numverts;
  }
  if (0x400 < iVar11) {
    Sys_Error("Mod_LoadAliasModel: Model %s has too many vertices: %d",mod,iVar11);
  }
  paVar2 = pheader;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x40));
  paVar2->numtris = iVar4;
  iVar11 = pheader->numtris;
  if (iVar11 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no triangles: %d",mod,iVar11);
    iVar11 = pheader->numtris;
  }
  if (0x800 < iVar11) {
    Sys_Error("Mod_LoadAliasModel: Model %s has too many triangles: %d",mod,iVar11);
  }
  paVar2 = pheader;
  iVar4 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  paVar2->numframes = iVar4;
  iVar11 = pheader->numframes;
  if (iVar11 < 1) {
    Sys_Error("Mod_LoadAliasModel: Model %s has no frames: %d",mod,iVar11);
    iVar11 = pheader->numframes;
  }
  if (0x100 < iVar11) {
    Sys_Error("Mod_LoadAliasModel: Model %s has too many frames: %d",mod,iVar11);
  }
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x50));
  paVar2->size = (float)((longdouble)0.09090909090909091 * lVar12);
  sVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x48));
  paVar2 = pheader;
  mod->synctype = sVar5;
  mod->numframes = paVar2->numframes;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 8));
  paVar2->scale[0] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x14));
  paVar2->scale_origin[0] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x24));
  paVar2->eyeposition[0] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0xc));
  paVar2->scale[1] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x18));
  paVar2->scale_origin[1] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x28));
  paVar2->eyeposition[1] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x10));
  paVar2->scale[2] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x1c));
  paVar2->scale_origin[2] = (float)lVar12;
  paVar2 = pheader;
  lVar12 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x2c));
  paVar3 = pheader;
  paVar2->eyeposition[2] = (float)lVar12;
  piVar6 = Mod_LoadAllSkins(paVar3->numskins,(daliasskintype_t *)((int)buffer + 0x54));
  iVar11 = pheader->numverts;
  if (0 < iVar11) {
    psVar7 = stverts;
    iVar10 = 0;
    piVar9 = piVar6;
    do {
      iVar10 = iVar10 + 1;
      iVar4 = (*LittleLong)(*piVar9);
      psVar7->onseam = iVar4;
      iVar4 = (*LittleLong)(piVar9[1]);
      psVar7->s = iVar4;
      piVar1 = piVar9 + 2;
      piVar9 = piVar9 + 3;
      iVar4 = (*LittleLong)(*piVar1);
      psVar7->t = iVar4;
      psVar7 = psVar7 + 1;
      iVar11 = pheader->numverts;
    } while (iVar10 < iVar11);
  }
  piVar6 = piVar6 + iVar11 * 3;
  if (0 < pheader->numtris) {
    pmVar8 = triangles;
    iVar11 = 0;
    do {
      iVar11 = iVar11 + 1;
      iVar4 = (*LittleLong)(*piVar6);
      pmVar8->facesfront = iVar4;
      iVar4 = (*LittleLong)(piVar6[1]);
      pmVar8->vertindex[0] = iVar4;
      iVar4 = (*LittleLong)(piVar6[2]);
      pmVar8->vertindex[1] = iVar4;
      piVar9 = piVar6 + 3;
      piVar6 = piVar6 + 4;
      iVar4 = (*LittleLong)(*piVar9);
      pmVar8->vertindex[2] = iVar4;
      pmVar8 = pmVar8 + 1;
    } while (iVar11 < pheader->numtris);
  }
  paVar2 = pheader;
  pheader->numposes = 0;
  mod->type = mod_alias;
  mod->mins[2] = -16.0;
  mod->mins[1] = -16.0;
  mod->mins[0] = -16.0;
  mod->maxs[2] = 16.0;
  mod->maxs[1] = 16.0;
  mod->maxs[0] = 16.0;
  posenum = 0;
  GL_MakeAliasModelDisplayLists(mod,paVar2);
  iVar11 = Hunk_LowMark();
  Cache_Alloc(&mod->cache,iVar11 - mark,loadname);
  dest = (mod->cache).data;
  if (dest != (void *)0x0) {
    Q_memcpy(dest,pheader,iVar11 - mark);
    Hunk_FreeToLowMark(mark);
    return;
  }
  return;
}


// Mod_LoadAllSkins  @ 001bc9f0
void * Mod_LoadAllSkins(int numskins,daliasskintype_t *pskintype)

{
  daliasskintype_t *skin;
  aliashdr_t *paVar1;
  int iVar2;
  int iVar3;
  uint count;
  daliasskintype_t *local_44;
  char local_3c [44];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[32] name@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: uchar * skin@[???] */
  skin = pskintype + 1;
  if ((numskins - 1U < 0x20) ||
     (Sys_Error("Mod_LoadAliasModel: Invalid # of skins: %d\n",numskins), 0 < numskins)) {
    iVar3 = 0;
    local_44 = skin;
    while( true ) {
      Mod_FloodFillSkin((uchar *)skin,pheader->skinwidth,pheader->skinheight);
      count = pheader->skinwidth * pheader->skinheight;
      iVar2 = Q_strcmp(loadmodel->name,"progs/player.mdl");
      if (iVar2 == 0) {
        if (64000 < count) {
          Sys_Error("Player skin too large");
        }
        Q_memcpy(player_8bit_texels,local_44,count);
      }
      pskintype = (daliasskintype_t *)((int)&pskintype[1].type + count);
      snprintf(local_3c,0x20,"%s_%i",loadmodel,iVar3);
      paVar1 = pheader;
      iVar2 = GL_LoadTexture(local_3c,GLT_STUDIO,pheader->skinwidth,pheader->skinheight,
                             (uchar *)local_44,1,0,(uchar *)0x0);
      paVar1->gl_texturenum[iVar3] = iVar2;
      iVar3 = iVar3 + 1;
      if (iVar3 == numskins) break;
      local_44 = pskintype + 1;
    }
  }
  return &pskintype->type;
}


// Mod_LoadBrushModel  @ 001bbec0
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
  color24 *pcVar12;
  char *pcVar13;
  uint uVar14;
  dmodel_t *pdVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
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
  if (iVar7 - 0x1dU < 2) {
    mod_base = buffer;
    iVar17 = 0;
    do {
      piVar1 = (int32 *)((int)buffer + iVar17 * 4);
      iVar17 = iVar17 + 1;
      iVar7 = (*LittleLong)(*piVar1);
      *piVar1 = iVar7;
    } while (iVar17 != 0x1f);
    Mod_LoadVertexes((lump_t *)((int)buffer + 0x1c));
    Mod_LoadEdges((lump_t *)((int)buffer + 100));
    puVar6 = mod_base;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
    iVar17 = *(int *)((int)buffer + 0x6c);
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
      uVar18 = 0;
      do {
        iVar7 = (*LittleLong)(*(int32 *)(puVar6 + uVar18 * 4 + iVar17));
        piVar8[uVar18] = iVar7;
        uVar18 = uVar18 + 1;
        pmVar10 = loadmodel;
      } while (uVar14 != uVar18);
    }
    iVar17 = strcasecmp(com_gamedir,"bshift");
    if (iVar17 == 0) {
                    /* Unresolved local var: char * pszInputStream@[???] */
      if (*(int *)((int)buffer + 0x10) == 0) {
        pmVar10->entities = (char *)0x0;
      }
      else {
        pcVar13 = Hunk_AllocName(*(int *)((int)buffer + 0x10),loadname);
        pmVar10->entities = pcVar13;
        Q_memcpy(loadmodel->entities,mod_base + *(int *)((int)buffer + 0xc),
                 *(int *)((int)buffer + 0x10));
        pcVar13 = loadmodel->entities;
        if (pcVar13 != (char *)0x0) {
          do {
            pcVar13 = COM_Parse(pcVar13);
            if ((*pcVar13 == '\0') || (com_token[0] == '}')) goto LAB_001bc3db;
            iVar17 = Q_strcmp(com_token,"wad");
          } while (iVar17 != 0);
          COM_Parse(pcVar13);
          if (wadpath != (char *)0x0) {
            Mem_Free(wadpath);
          }
          wadpath = Mem_Strdup(com_token);
        }
      }
LAB_001bc3db:
      Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
      pmVar10 = loadmodel;
      if (*(int *)((int)buffer + 0x48) == 0) {
        loadmodel->lightdata = (color24 *)0x0;
      }
      else {
        pcVar12 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
        pmVar10->lightdata = pcVar12;
        Q_memcpy(loadmodel->lightdata,mod_base + *(int *)((int)buffer + 0x44),
                 *(int *)((int)buffer + 0x48));
      }
      Mod_LoadPlanes((lump_t *)((int)buffer + 4));
    }
    else {
                    /* Unresolved local var: char * pszInputStream@[???] */
      if (*(int *)((int)buffer + 8) == 0) {
        pmVar10->entities = (char *)0x0;
      }
      else {
        pcVar13 = Hunk_AllocName(*(int *)((int)buffer + 8),loadname);
        pmVar10->entities = pcVar13;
        Q_memcpy(loadmodel->entities,mod_base + *(int *)((int)buffer + 4),*(int *)((int)buffer + 8))
        ;
        pcVar13 = loadmodel->entities;
        if (pcVar13 != (char *)0x0) {
          do {
            pcVar13 = COM_Parse(pcVar13);
            if ((*pcVar13 == '\0') || (com_token[0] == '}')) goto LAB_001bc003;
            iVar17 = Q_strcmp(com_token,"wad");
          } while (iVar17 != 0);
          COM_Parse(pcVar13);
          if (wadpath != (char *)0x0) {
            Mem_Free(wadpath);
          }
          wadpath = Mem_Strdup(com_token);
        }
      }
LAB_001bc003:
      Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
      pmVar10 = loadmodel;
      if (*(int *)((int)buffer + 0x48) == 0) {
        loadmodel->lightdata = (color24 *)0x0;
      }
      else {
        pcVar12 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
        pmVar10->lightdata = pcVar12;
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
      Q_memcpy(loadmodel->visdata,mod_base + *(int *)((int)buffer + 0x24),
               *(int *)((int)buffer + 0x28));
    }
    Mod_LoadLeafs((lump_t *)((int)buffer + 0x54));
    Mod_LoadNodes((lump_t *)((int)buffer + 0x2c));
    Mod_LoadClipnodes((lump_t *)((int)buffer + 0x4c));
    Mod_LoadSubmodels((lump_t *)((int)buffer + 0x74));
    iVar17 = mod->numsurfaces;
    if (0 < iVar17) {
      iVar16 = 0;
      do {
        while (mod->surfaces[iVar16].firstedge + mod->surfaces[iVar16].numedges <= mod->numsurfedges
              ) {
          iVar16 = iVar16 + 1;
          if (iVar17 <= iVar16) goto LAB_001bc0e3;
        }
        iVar16 = iVar16 + 1;
        Sys_Error("MOD_LoadBrushModel: more surfedges referenced than loaded in %s",mod);
        iVar17 = mod->numsurfaces;
      } while (iVar16 < iVar17);
    }
LAB_001bc0e3:
    iVar17 = mod->numleafs;
    if (0 < iVar17) {
      iVar19 = 0;
      iVar16 = 0;
      do {
                    /* Unresolved local var: int firstmarksurface@[???] */
        while ((*(int *)(mod->leafs->ambient_sound_level + iVar19 + -0xc) - (int)mod->marksurfaces
               >> 2) + *(int *)(mod->leafs->ambient_sound_level + iVar19 + -8) <=
               mod->nummarksurfaces) {
          iVar16 = iVar16 + 1;
          iVar19 = iVar19 + 0x3c;
          if (iVar17 <= iVar16) goto LAB_001bc141;
        }
        iVar16 = iVar16 + 1;
        iVar19 = iVar19 + 0x3c;
        Sys_Error("MOD_LoadBrushModel: more marksurfaces referenced than loaded in %s",mod);
        iVar17 = mod->numleafs;
      } while (iVar16 < iVar17);
    }
LAB_001bc141:
    iVar17 = mod->numnodes;
    if (0 < iVar17) {
      iVar19 = 0;
      iVar16 = 0;
      do {
        while ((int)((uint)*(ushort *)((int)mod->nodes->children + iVar19 + 10) +
                    (uint)*(ushort *)((int)mod->nodes->children + iVar19 + 8)) <= mod->numsurfaces)
        {
          iVar16 = iVar16 + 1;
          iVar19 = iVar19 + 0x34;
          if (iVar17 <= iVar16) goto LAB_001bc198;
        }
        iVar16 = iVar16 + 1;
        iVar19 = iVar19 + 0x34;
        Sys_Error("MOD_LoadBrushModel: more surfaces referenced than loaded in %s",mod);
        iVar17 = mod->numnodes;
      } while (iVar16 < iVar17);
    }
LAB_001bc198:
    iVar17 = mod->numsubmodels;
    if (0 < iVar17) {
      iVar16 = 0;
      do {
        while (mod->submodels[iVar16].firstface + mod->submodels[iVar16].numfaces <=
               mod->numsurfaces) {
          iVar16 = iVar16 + 1;
          if (iVar17 <= iVar16) goto LAB_001bc1df;
        }
        iVar16 = iVar16 + 1;
        Sys_Error("MOD_LoadBrushModel: more faces referenced than loaded in %s",mod);
        iVar17 = mod->numsubmodels;
      } while (iVar16 < iVar17);
    }
LAB_001bc1df:
    Mod_MakeHull0();
    mod->numframes = 2;
    mod->flags = 0;
    if (0 < mod->numsubmodels) {
      iVar16 = 0;
      iVar17 = 1;
      do {
        pdVar15 = mod->submodels + iVar16;
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
        if (iVar16 < iVar19 + -1) {
          snprintf((char *)&local_2c,10,"*%i",iVar17);
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
        iVar16 = iVar16 + 1;
        bVar5 = iVar17 < iVar19;
        iVar17 = iVar17 + 1;
      } while (bVar5);
    }
  }
  else if (cls.state != ca_dedicated) {
    COM_ExplainDisconnection
              (true,"Mod_LoadBrushModel: %s has wrong version number (%i should be %i)\n",mod,iVar7,
               0x1e);
    CL_Disconnect();
    return;
  }
  return;
}


// Mod_LoadClipnodes  @ 001bb8d0
void Mod_LoadClipnodes(lump_t *l)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  mplane_t *pmVar4;
  model_t *pmVar5;
  uchar *puVar6;
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
  puVar6 = mod_base;
  uVar10 = l->filelen;
  iVar3 = l->fileofs;
  if ((uVar10 & 7) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar10 = l->filelen;
  }
  uVar10 = uVar10 >> 3;
  pdVar8 = Hunk_AllocName(uVar10 * 8,loadname);
  pmVar5 = loadmodel;
  iVar1 = uVar10 - 1;
  loadmodel->hulls[1].firstclipnode = 0;
  pmVar4 = pmVar5->planes;
  pmVar5->clipnodes = pdVar8;
  pmVar5->numclipnodes = uVar10;
  pmVar5->hulls[1].clipnodes = pdVar8;
  pmVar5->hulls[1].lastclipnode = iVar1;
  pmVar5->hulls[1].planes = pmVar4;
  pmVar5->hulls[1].clip_mins[0] = -16.0;
  pmVar5->hulls[1].clip_mins[1] = -16.0;
  pmVar5->hulls[1].clip_mins[2] = -36.0;
  pmVar5->hulls[1].clip_maxs[0] = 16.0;
  pmVar5->hulls[1].clip_maxs[1] = 16.0;
  pmVar5->hulls[1].clip_maxs[2] = 36.0;
  pmVar5->hulls[2].clipnodes = pdVar8;
  pmVar5->hulls[2].firstclipnode = 0;
  pmVar5->hulls[2].lastclipnode = iVar1;
  pmVar5->hulls[2].planes = pmVar4;
  pmVar5->hulls[2].clip_mins[0] = -32.0;
  pmVar5->hulls[2].clip_mins[1] = -32.0;
  pmVar5->hulls[2].clip_mins[2] = -32.0;
  pmVar5->hulls[2].clip_maxs[0] = 32.0;
  pmVar5->hulls[2].clip_maxs[1] = 32.0;
  pmVar5->hulls[2].clip_maxs[2] = 32.0;
  pmVar5->hulls[3].clipnodes = pdVar8;
  pmVar5->hulls[3].firstclipnode = 0;
  pmVar5->hulls[3].lastclipnode = iVar1;
  pmVar5->hulls[3].planes = pmVar4;
  pmVar5->hulls[3].clip_mins[0] = -16.0;
  pmVar5->hulls[3].clip_mins[1] = -16.0;
  pmVar5->hulls[3].clip_mins[2] = -18.0;
  pmVar5->hulls[3].clip_maxs[0] = 16.0;
  pmVar5->hulls[3].clip_maxs[1] = 16.0;
  pmVar5->hulls[3].clip_maxs[2] = 18.0;
  if (uVar10 != 0) {
    piVar11 = (int32 *)(puVar6 + iVar3);
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


// Mod_LoadEdges  @ 001baa60
void Mod_LoadEdges(lump_t *l)

{
  int iVar1;
  int iVar2;
  model_t *pmVar3;
  uchar *puVar4;
  ushort uVar5;
  medge_t *pmVar6;
  uint uVar7;
  uint uVar8;
  
                    /* Unresolved local var: dedge_t * in@[???]
                       Unresolved local var: medge_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  puVar4 = mod_base;
  uVar8 = l->filelen;
  iVar2 = l->fileofs;
  if ((uVar8 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 >> 2;
  pmVar6 = Hunk_AllocName(uVar8 * 8 + 8,loadname);
  pmVar3 = loadmodel;
  loadmodel->edges = pmVar6;
  pmVar3->numedges = uVar8;
  if (uVar8 != 0) {
    uVar7 = 0;
    do {
      uVar5 = (*LittleShort)(*(short *)(puVar4 + uVar7 * 4 + iVar2));
      pmVar6->v[0] = uVar5;
      iVar1 = uVar7 * 4;
      uVar7 = uVar7 + 1;
      uVar5 = (*LittleShort)(*(short *)(puVar4 + iVar1 + iVar2 + 2));
      pmVar6->v[1] = uVar5;
      pmVar6 = pmVar6 + 1;
    } while (uVar8 != uVar7);
  }
  return;
}


// Mod_LoadEntities  @ 001ba710
void Mod_LoadEntities(lump_t *l)

{
  model_t *pmVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: char * pszInputStream@[???] */
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


// Mod_LoadFaces  @ 001bb060
void Mod_LoadFaces(lump_t *l)

{
  mtexinfo_t *pmVar1;
  texture_t *__s1;
  model_t *pmVar2;
  uchar *puVar3;
  short sVar4;
  short sVar5;
  msurface_t *s;
  int32 iVar6;
  int iVar7;
  uint uVar8;
  short *psVar9;
  uint uVar10;
  
                    /* Unresolved local var: dface_t * in@[???]
                       Unresolved local var: msurface_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int surfnum@[???]
                       Unresolved local var: int planenum@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: qboolean IsCzeroAndIsSkyCullAndIsD3D@[???] */
  puVar3 = mod_base;
  uVar8 = l->filelen;
  iVar7 = l->fileofs;
  if (uVar8 != (uVar8 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 / 0x14;
  s = Hunk_AllocName(uVar8 * 0x5c,loadname);
  pmVar2 = loadmodel;
  loadmodel->surfaces = s;
  pmVar2->numsurfaces = uVar8;
  if (uVar8 != 0) {
    psVar9 = (short *)(puVar3 + iVar7);
    uVar10 = 0;
    do {
      while( true ) {
        iVar6 = (*LittleLong)(*(int32 *)(psVar9 + 2));
        s->firstedge = iVar6;
        sVar4 = (*LittleShort)(psVar9[4]);
        s->flags = 0;
        s->pdecals = (decal_t *)0x0;
        s->numedges = (int)sVar4;
        sVar4 = (*LittleShort)(*psVar9);
        sVar5 = (*LittleShort)(psVar9[1]);
        if (sVar5 != 0) {
          s->flags = s->flags | 2;
        }
        pmVar2 = loadmodel;
        s->plane = loadmodel->planes + sVar4;
        pmVar1 = pmVar2->texinfo;
        sVar4 = (*LittleShort)(psVar9[5]);
        s->texinfo = pmVar1 + sVar4;
        CalcSurfaceExtents(s);
        s->styles[0] = (uchar)psVar9[6];
        s->styles[1] = *(uchar *)((int)psVar9 + 0xd);
        s->styles[2] = (uchar)psVar9[7];
        s->styles[3] = *(uchar *)((int)psVar9 + 0xf);
        iVar6 = (*LittleLong)(*(int32 *)(psVar9 + 8));
        if (iVar6 == -1) {
          s->samples = (color24_conflict *)0x0;
        }
        else {
          s->samples = (color24_conflict *)(&loadmodel->lightdata->r + iVar6);
        }
        iVar7 = Q_strncmp(s->texinfo->texture->name,"sky",3);
        if (iVar7 != 0) break;
        s->flags = s->flags | 0x24;
LAB_001bb0dc:
        uVar10 = uVar10 + 1;
        psVar9 = psVar9 + 10;
        s = s + 1;
        if (uVar8 == uVar10) {
          return;
        }
      }
      iVar7 = Q_strncmp(s->texinfo->texture->name,"scroll",6);
      if (iVar7 == 0) {
LAB_001bb2c0:
        s->flags = s->flags | 0x20;
        goto LAB_001bb0dc;
      }
      pmVar1 = s->texinfo;
      __s1 = pmVar1->texture;
      if (((__s1->name[0] != '!') && (iVar7 = strncasecmp(__s1->name,"laser",5), iVar7 != 0)) &&
         (iVar7 = strncasecmp(__s1->name,"water",5), iVar7 != 0)) {
        if ((pmVar1->flags & 1) == 0) goto LAB_001bb0dc;
        goto LAB_001bb2c0;
      }
      s->flags = s->flags | 0x10;
      uVar10 = uVar10 + 1;
      psVar9 = psVar9 + 10;
      GL_SubdivideSurface(s);
      s = s + 1;
    } while (uVar8 != uVar10);
  }
  return;
}


// Mod_LoadLeafs  @ 001bb6e0
void Mod_LoadLeafs(lump_t *l)

{
  byte *pbVar1;
  int iVar2;
  model_t *pmVar3;
  uchar *puVar4;
  short sVar5;
  mleaf_t *pmVar6;
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
  puVar4 = mod_base;
  uVar8 = l->filelen;
  iVar2 = l->fileofs;
  if (uVar8 + (uVar8 / 0x1c) * 4 != uVar8 / 0x1c << 5) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 / 0x1c;
  pmVar6 = Hunk_AllocName(uVar8 * 0x3c,loadname);
  pmVar3 = loadmodel;
  loadmodel->leafs = pmVar6;
  pmVar3->numleafs = uVar8;
  if (uVar8 != 0) {
    piVar9 = (int32 *)(puVar4 + iVar2);
    uVar10 = 0;
    do {
      sVar5 = (*LittleShort)((short)piVar9[2]);
      pmVar6->minmaxs[0] = (float)sVar5;
      sVar5 = (*LittleShort)(*(short *)((int)piVar9 + 0xe));
      pmVar6->minmaxs[3] = (float)sVar5;
      sVar5 = (*LittleShort)(*(short *)((int)piVar9 + 10));
      pmVar6->minmaxs[1] = (float)sVar5;
      sVar5 = (*LittleShort)((short)piVar9[4]);
      pmVar6->minmaxs[4] = (float)sVar5;
      sVar5 = (*LittleShort)((short)piVar9[3]);
      pmVar6->minmaxs[2] = (float)sVar5;
      sVar5 = (*LittleShort)(*(short *)((int)piVar9 + 0x12));
      pmVar6->minmaxs[5] = (float)sVar5;
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


// Mod_LoadLighting  @ 001ba610
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


// Mod_LoadMarksurfaces  @ 001bbbb0
void Mod_LoadMarksurfaces(lump_t *l)

{
  int iVar1;
  model_t *pmVar2;
  uchar *puVar3;
  short sVar4;
  msurface_t **ppmVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: short * in@[???]
                       Unresolved local var: msurface_t * * out@[???] */
  puVar3 = mod_base;
  iVar1 = l->fileofs;
  uVar7 = l->filelen;
  if ((uVar7 & 1) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 >> 1;
  ppmVar5 = Hunk_AllocName(uVar7 * 4,loadname);
  pmVar2 = loadmodel;
  loadmodel->marksurfaces = ppmVar5;
  pmVar2->nummarksurfaces = uVar7;
  if (uVar7 != 0) {
    uVar6 = 0;
    do {
      sVar4 = (*LittleShort)(*(short *)(puVar3 + uVar6 * 2 + iVar1));
      if (loadmodel->numsurfaces <= (int)sVar4) {
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      ppmVar5[uVar6] = loadmodel->surfaces + sVar4;
      uVar6 = uVar6 + 1;
    } while (uVar7 != uVar6);
  }
  return;
}


// Mod_LoadModel  @ 001bd650
model_t * __regparm3 Mod_LoadModel(model_t *mod,qboolean crash,qboolean trackCRC)

{
  int iVar1;
  FileHandle_t file;
  int32 *buffer;
  int32 iVar2;
  model_t *__src;
  qboolean qVar3;
  qboolean qVar4;
  char local_1024 [4095];
  undefined1 local_25;
  uint local_24;
  CRC32_t local_20 [4];
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[4096] tmpName@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  iVar1 = COM_CheckParm("-steam");
  if ((iVar1 != 0) && (__src = mod, mod->name[0] == '/')) {
    do {
      __src = (model_t *)(__src->name + 1);
    } while (__src->name[0] == '/');
    strncpy(local_1024,(char *)__src,0xfff);
    local_25 = 0;
    strncpy(mod->name,local_1024,0x3f);
    mod->name[0x3f] = '\0';
  }
  file = FS_Open(mod->name,"rb");
  if (file != (FileHandle_t)0x0) {
    buffer = FS_GetReadBuffer(file,(int *)&local_24);
    if (buffer != (int32 *)0x0) {
      iVar2 = (*LittleLong)(*buffer);
      if (iVar2 != 0x54534449) goto LAB_001bd6c9;
      FS_ReleaseReadBuffer(file,buffer);
    }
    local_24 = FS_Size(file);
    buffer = Hunk_TempAlloc(local_24 + 1);
    FS_Read(buffer,local_24,1,file);
    FS_Close(file);
    if (buffer != (int32 *)0x0) {
      file = (FileHandle_t)0x0;
LAB_001bd6c9:
                    /* Unresolved local var: mod_known_info_t * p@[???] */
      if ((trackCRC != false) &&
         (iVar1 = ((int)&mod[-0x9aa7].numedges >> 3) * 0x397829cc,
         *(int *)((int)mod_known_info + iVar1) != 0)) {
                    /* Unresolved local var: CRC32_t currentCRC@[???] */
        CRC32_Init(local_20);
        CRC32_ProcessBuffer(local_20,buffer,local_24);
        local_20[0] = CRC32_Final(local_20[0]);
        if (*(int *)((int)mod_known_info + iVar1 + 4) == 0) {
                    /* Unresolved local var: qboolean badModel@[???] */
          *(CRC32_t *)((int)mod_known_info + iVar1 + 8) = local_20[0];
          *(undefined4 *)((int)mod_known_info + iVar1 + 4) = 1;
          SetCStrikeFlags();
          qVar3 = IsGameSubscribed("czero");
          if ((((qVar3 == false) && (g_bIsCStrike != 0)) &&
              (qVar4 = IsCZPlayerModel(local_20[0],mod->name), qVar4 != 0)) &&
             (cls.state != ca_dedicated)) {
            COM_ExplainDisconnection
                      (true,"Cannot continue with altered model %s, disconnecting.",mod);
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
      COM_FileBase(mod->name,loadname);
      mod->needload = false;
      loadmodel = mod;
      iVar2 = (*LittleLong)(*buffer);
      if (iVar2 == 0x50534449) {
        Mod_LoadSpriteModel(mod,buffer);
      }
      else if (iVar2 == 0x54534449) {
        Mod_LoadStudioModel(mod,buffer);
      }
      else if (iVar2 == 0x4f504449) {
        Mod_LoadAliasModel(mod,buffer);
      }
      else {
        DT_LoadDetailMapFile(loadname);
        Mod_LoadBrushModel(mod,buffer);
      }
      if (file != (FileHandle_t)0x0) {
        FS_ReleaseReadBuffer(file,buffer);
        FS_Close(file);
      }
      return mod;
    }
  }
  if ((crash != false) || (1.0 < developer.value)) {
    Sys_Error("Mod_NumForName: %s not found",mod);
  }
  Con_Printf("Error: could not load file %s\n",mod);
  return (model_t *)0x0;
}


// Mod_LoadModel  @ 001bd9e0
model_t * Mod_LoadModel(model_t *mod,qboolean crash,qboolean trackCRC)

{
  model_t *pmVar1;
  void *pvVar2;
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[4096] tmpName@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
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


// Mod_LoadNodes  @ 001bb480
void Mod_LoadNodes(lump_t *l)

{
  int iVar1;
  model_t *pmVar2;
  uchar *puVar3;
  short sVar4;
  ushort uVar5;
  mnode_t *node;
  int32 iVar6;
  uint uVar7;
  uint uVar8;
  int32 *piVar9;
  uint uVar10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: dnode_t * in@[???]
                       Unresolved local var: mnode_t * out@[???] */
  puVar3 = mod_base;
  uVar8 = l->filelen;
  iVar1 = l->fileofs;
  if (uVar8 != (uVar8 / 0x18) * 0x18) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 / 0x18;
  node = Hunk_AllocName(uVar8 * 0x34,loadname);
  pmVar2 = loadmodel;
  loadmodel->nodes = node;
  pmVar2->numnodes = uVar8;
  if (uVar8 != 0) {
    piVar9 = (int32 *)(puVar3 + iVar1);
    uVar10 = 0;
    do {
      while( true ) {
        sVar4 = (*LittleShort)((short)piVar9[2]);
        node->minmaxs[0] = (float)sVar4;
        sVar4 = (*LittleShort)(*(short *)((int)piVar9 + 0xe));
        node->minmaxs[3] = (float)sVar4;
        sVar4 = (*LittleShort)(*(short *)((int)piVar9 + 10));
        node->minmaxs[1] = (float)sVar4;
        sVar4 = (*LittleShort)((short)piVar9[4]);
        node->minmaxs[4] = (float)sVar4;
        sVar4 = (*LittleShort)((short)piVar9[3]);
        node->minmaxs[2] = (float)sVar4;
        sVar4 = (*LittleShort)(*(short *)((int)piVar9 + 0x12));
        node->minmaxs[5] = (float)sVar4;
        iVar6 = (*LittleLong)(*piVar9);
        node->plane = loadmodel->planes + iVar6;
        uVar5 = (*LittleShort)((short)piVar9[5]);
        node->firstsurface = uVar5;
        uVar5 = (*LittleShort)(*(short *)((int)piVar9 + 0x16));
        node->numsurfaces = uVar5;
        sVar4 = (*LittleShort)((short)piVar9[1]);
        uVar7 = (uint)sVar4;
        if ((int)uVar7 < 0) {
          node->children[0] = (mnode_s *)(loadmodel->leafs + ~uVar7);
        }
        else {
          node->children[0] = loadmodel->nodes + uVar7;
        }
        sVar4 = (*LittleShort)(*(short *)((int)piVar9 + 6));
        pmVar2 = loadmodel;
        uVar7 = (uint)sVar4;
        if ((int)uVar7 < 0) break;
        uVar10 = uVar10 + 1;
        piVar9 = piVar9 + 6;
        node->children[1] = loadmodel->nodes + uVar7;
        node = node + 1;
        if (uVar8 == uVar10) goto LAB_001bb698;
      }
      uVar10 = uVar10 + 1;
      piVar9 = piVar9 + 6;
      node->children[1] = (mnode_s *)(loadmodel->leafs + ~uVar7);
      node = node + 1;
    } while (uVar8 != uVar10);
LAB_001bb698:
    node = pmVar2->nodes;
  }
  Mod_SetParent(node,(mnode_t *)0x0);
  return;
}


// Mod_LoadPlanes  @ 001bbd30
void Mod_LoadPlanes(lump_t *l)

{
  float *pfVar1;
  int iVar2;
  model_t *pmVar3;
  uchar *puVar4;
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
  puVar4 = mod_base;
  uVar7 = l->filelen;
  iVar2 = l->fileofs;
  if (uVar7 != (uVar7 / 0x14) * 0x14) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 / 0x14;
  pmVar5 = Hunk_AllocName(uVar7 * 0x28,loadname);
  pmVar3 = loadmodel;
  loadmodel->planes = pmVar5;
  pmVar3->numplanes = uVar7;
  if (uVar7 != 0) {
    pfVar9 = (float *)(puVar4 + iVar2);
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


// Mod_LoadSpriteFrame  @ 001bd080
void * Mod_LoadSpriteFrame(void *pin,mspriteframe_t **ppframe,int framenum)

{
  int32 width;
  int32 height;
  mspriteframe_t *dest;
  int32 iVar1;
  int32 iVar2;
  int iVar3;
  uchar local_41c [768];
  char local_11c [268];
  
                    /* Unresolved local var: dspriteframe_t * pinframe@[???]
                       Unresolved local var: mspriteframe_t * pspriteframe@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int[2] origin@[???]
                       Unresolved local var: int textureType@[???]
                       Unresolved local var: uchar * pdata@[???]
                       Unresolved local var: uchar * ppal@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: uchar[768] bPal@[???] */
  Q_memcpy(local_41c,pspritepal,0x300);
  width = (*LittleLong)(*(int32 *)((int)pin + 8));
  height = (*LittleLong)(*(int32 *)((int)pin + 0xc));
  dest = Hunk_AllocName(0x1c,loadname);
  Q_memset(dest,0,0x1c);
  *ppframe = dest;
  dest->width = width;
  dest->height = height;
  iVar1 = (*LittleLong)(*(int32 *)pin);
  iVar2 = (*LittleLong)(*(int32 *)((int)pin + 4));
  dest->up = (float)iVar2;
  dest->down = (float)(iVar2 - height);
  dest->left = (float)iVar1;
  dest->right = (float)(iVar1 + width);
  snprintf(local_11c,0x100,"%s_%i",loadmodel,framenum);
  iVar3 = 3;
  if (gSpriteTextureFormat != 2) {
    if (gSpriteTextureFormat < 3) {
      if (-1 < gSpriteTextureFormat) {
        iVar3 = 0;
      }
    }
    else if (gSpriteTextureFormat == 3) {
      iVar3 = 1;
    }
  }
  if (gSpriteMipMap == false) {
    iVar3 = GL_LoadTexture(local_11c,GLT_HUDSPRITE,width,height,(uchar *)((int)pin + 0x10),0,iVar3,
                           local_41c);
    dest->gl_texturenum = iVar3;
  }
  else {
    iVar3 = GL_LoadTexture(local_11c,GLT_SPRITE,width,height,(uchar *)((int)pin + 0x10),
                           gSpriteMipMap,iVar3,local_41c);
    dest->gl_texturenum = iVar3;
  }
  return (void *)((int)pin + width * height + 0x10);
}


// Mod_LoadSpriteGroup  @ 001bd320
void * Mod_LoadSpriteGroup(void *pin,mspriteframe_t **ppframe,int framenum)

{
  float *ppframe_00;
  int framenum_00;
  int32 iVar1;
  mspriteframe_t *pmVar2;
  void *pvVar3;
  void *pin_00;
  int iVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: dspritegroup_t * pingroup@[???]
                       Unresolved local var: mspritegroup_t * pspritegroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: dspriteinterval_t * pin_intervals@[???]
                       Unresolved local var: float * poutintervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  iVar1 = (*LittleLong)(*(int32 *)pin);
  pmVar2 = Hunk_AllocName(iVar1 * 4 + 8,loadname);
  pin_00 = (void *)((int)pin + 4);
  pmVar2->width = iVar1;
  *ppframe = pmVar2;
  pvVar3 = Hunk_AllocName(iVar1 * 4,loadname);
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
        if (iVar4 == iVar1) goto LAB_001bd3ce;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar1);
LAB_001bd3ce:
    pin_00 = (void *)((int)pin_00 + iVar1 * 4);
    iVar4 = 0;
    do {
      framenum_00 = iVar4 + framenum * 100;
      ppframe_00 = &pmVar2->up + iVar4;
      iVar4 = iVar4 + 1;
      pin_00 = Mod_LoadSpriteFrame(pin_00,(mspriteframe_t **)ppframe_00,framenum_00);
    } while (iVar4 != iVar1);
  }
  return pin_00;
}


// Mod_LoadSpriteModel  @ 001bd420
void Mod_LoadSpriteModel(model_t *mod,void *buffer)

{
  int iVar1;
  float fVar2;
  int32 iVar3;
  undefined2 *puVar4;
  int32 iVar5;
  synctype_t sVar6;
  int32 *piVar7;
  int iVar8;
  longdouble lVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int version@[???]
                       Unresolved local var: dsprite_t * pin@[???]
                       Unresolved local var: msprite_t * psprite@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int palsize@[???]
                       Unresolved local var: dspriteframetype_t * pframetype@[???] */
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar3 != 2) {
    Sys_Error("%s has wrong version number (%i should be %i)",mod,iVar3,2);
  }
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 0x1c));
  iVar1 = *(short *)((int)buffer + 0x28) * 3;
  iVar8 = iVar1 + 2;
  puVar4 = Hunk_AllocName(iVar3 * 8 + 0x1c + iVar8,loadname);
  (mod->cache).data = puVar4;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 8));
  *puVar4 = (short)iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0xc));
  gSpriteTextureFormat = (int)(short)iVar5;
  puVar4[1] = (short)iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x14));
  *(int32 *)(puVar4 + 2) = iVar5;
  iVar5 = (*LittleLong)(*(int32 *)((int)buffer + 0x18));
  *(int32 *)(puVar4 + 4) = iVar5;
  lVar9 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  *(float *)(puVar4 + 10) = (float)lVar9;
  sVar6 = (*LittleLong)(*(int32 *)((int)buffer + 0x24));
  mod->synctype = sVar6;
  *(int32 *)(puVar4 + 6) = iVar3;
  fVar2 = (float)-(*(int *)(puVar4 + 2) - (*(int *)(puVar4 + 2) >> 0x1f) >> 1);
  mod->mins[1] = fVar2;
  mod->mins[0] = fVar2;
  fVar2 = (float)(*(int *)(puVar4 + 2) - (*(int *)(puVar4 + 2) >> 0x1f) >> 1);
  mod->maxs[1] = fVar2;
  mod->maxs[0] = fVar2;
  mod->mins[2] = (float)-(*(int *)(puVar4 + 4) - (*(int *)(puVar4 + 4) >> 0x1f) >> 1);
  mod->maxs[2] = (float)(*(int *)(puVar4 + 4) - (*(int *)(puVar4 + 4) >> 0x1f) >> 1);
  *(int32 *)(puVar4 + 8) = iVar3 * 8 + 0x1e;
  pspritepal = (uchar *)(puVar4 + iVar3 * 4 + 0xe);
  Q_memcpy(pspritepal,(void *)((int)buffer + 0x2a),iVar8);
  if (iVar3 < 1) {
    Sys_Error("Mod_LoadSpriteModel: Invalid # of frames: %d\n",iVar3);
    mod->numframes = iVar3;
    mod->flags = 0;
    mod->type = mod_sprite;
    return;
  }
  piVar7 = (int32 *)((int)buffer + iVar1 + 0x2a);
  iVar8 = 0;
  mod->numframes = iVar3;
  mod->flags = 0;
  do {
    while( true ) {
      iVar5 = (*LittleLong)(*piVar7);
      *(int32 *)(puVar4 + iVar8 * 4 + 0xe) = iVar5;
      if (iVar5 == 0) break;
      piVar7 = Mod_LoadSpriteGroup(piVar7 + 1,(mspriteframe_t **)(puVar4 + iVar8 * 4 + 0x10),iVar8);
      iVar8 = iVar8 + 1;
      if (iVar8 == iVar3) goto LAB_001bd60d;
    }
                    /* Unresolved local var: spriteframetype_t frametype@[???] */
    piVar7 = Mod_LoadSpriteFrame(piVar7 + 1,(mspriteframe_t **)(puVar4 + iVar8 * 4 + 0x10),iVar8);
    iVar8 = iVar8 + 1;
  } while (iVar8 != iVar3);
LAB_001bd60d:
  mod->type = mod_sprite;
  return;
}


// Mod_LoadStudioModel  @ 0012a520
void Mod_LoadStudioModel(model_t *mod,void *buffer)

{
  void *dest;
  int iVar1;
  int iVar2;
  int32 iVar3;
  int size;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_11c [268];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte * pin@[???]
                       Unresolved local var: byte * pout@[???]
                       Unresolved local var: studiohdr_t * phdr@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int version@[???] */
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar3 != 10) {
    Q_memset(buffer,0,0xf4);
    Q_strcpy((char *)((int)buffer + 8),"bogus");
    *(undefined4 *)((int)buffer + 0x48) = 0xf4;
    *(undefined4 *)((int)buffer + 0xbc) = 0xf4;
  }
  mod->type = mod_studio;
  mod->flags = *(int *)((int)buffer + 0x88);
  size = *(int *)((int)buffer + 0x48);
  if (*(int *)((int)buffer + 0xb8) != 0) {
    size = *(int *)((int)buffer + 0xbc);
  }
  Cache_Alloc(&mod->cache,size,mod->name);
  dest = (mod->cache).data;
  if (dest != (void *)0x0) {
    iVar5 = (int)buffer + *(int *)((int)buffer + 0xb8);
    if ((*(int *)((int)buffer + 0xb8) != 0) && (0 < *(int *)((int)buffer + 0xb4))) {
      iVar6 = 0;
      do {
        iVar4 = *(int *)(iVar5 + 0x48);
        iVar1 = *(int *)(iVar5 + 0x44);
        iVar2 = *(int *)(iVar5 + 0x4c);
        snprintf(local_11c,0x100,"%s%s",mod,iVar5);
        iVar6 = iVar6 + 1;
        iVar4 = GL_LoadTexture(local_11c,GLT_STUDIO,*(int *)(iVar5 + 0x44),*(int *)(iVar5 + 0x48),
                               (uchar *)(*(int *)(iVar5 + 0x4c) + (int)buffer),
                               (uint)((*(uint *)(iVar5 + 0x40) & 8) != 0),
                               (uint)((*(uint *)(iVar5 + 0x40) & 0x40) != 0),
                               (uchar *)(iVar1 * iVar4 + iVar2 + (int)buffer));
        *(int *)(iVar5 + 0x4c) = iVar4;
        iVar5 = iVar5 + 0x50;
      } while (iVar6 < *(int *)((int)buffer + 0xb4));
    }
    Q_memcpy(dest,buffer,size);
  }
  return;
}


// Mod_LoadSubmodels  @ 001ba8c0
void Mod_LoadSubmodels(lump_t *l)

{
  float *pfVar1;
  int iVar2;
  model_t *pmVar3;
  uchar *puVar4;
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
  puVar4 = mod_base;
  uVar7 = l->filelen;
  iVar2 = l->fileofs;
  if ((uVar7 & 0x3f) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 >> 6;
  pdVar5 = Hunk_AllocName(uVar7 << 6,loadname);
  pmVar3 = loadmodel;
  loadmodel->submodels = pdVar5;
  pmVar3->numsubmodels = uVar7;
  if (uVar7 != 0) {
    pfVar8 = (float *)(puVar4 + iVar2);
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


// Mod_LoadSurfedges  @ 001bbc90
void Mod_LoadSurfedges(lump_t *l)

{
  int iVar1;
  model_t *pmVar2;
  uchar *puVar3;
  int *piVar4;
  int32 iVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
  puVar3 = mod_base;
  iVar1 = l->fileofs;
  uVar7 = l->filelen;
  if ((uVar7 & 3) != 0) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar7 = l->filelen;
  }
  uVar7 = uVar7 >> 2;
  piVar4 = Hunk_AllocName(uVar7 * 4,loadname);
  pmVar2 = loadmodel;
  loadmodel->surfedges = piVar4;
  pmVar2->numsurfedges = uVar7;
  if (uVar7 != 0) {
    uVar6 = 0;
    do {
      iVar5 = (*LittleLong)(*(int32 *)(puVar3 + uVar6 * 4 + iVar1));
      piVar4[uVar6] = iVar5;
      uVar6 = uVar6 + 1;
    } while (uVar7 != uVar6);
  }
  return;
}


// Mod_LoadTexinfo  @ 001bab20
void Mod_LoadTexinfo(lump_t *l)

{
  int iVar1;
  texture_t *ptVar2;
  model_t *pmVar3;
  uchar *puVar4;
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
  puVar4 = mod_base;
  uVar8 = l->filelen;
  iVar1 = l->fileofs;
  if (uVar8 != (uVar8 / 0x28) * 0x28) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar8 = l->filelen;
  }
  uVar8 = uVar8 / 0x28;
  v = Hunk_AllocName(uVar8 * 0x2c,loadname);
  pmVar3 = loadmodel;
  loadmodel->texinfo = v;
  pmVar3->numtexinfo = uVar8;
  if (uVar8 != 0) {
    pfVar9 = (float *)(puVar4 + iVar1);
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


// Mod_LoadTextures  @ 001b9e20
void Mod_LoadTextures(lump_t *l)

{
  ushort uVar1;
  char *pcVar2;
  bool bVar3;
  model_t *pmVar4;
  int32 iVar5;
  texture_t **pptVar6;
  int iVar7;
  uint uVar8;
  texture_t *ptVar9;
  void *pvVar10;
  int iVar11;
  uint uVar12;
  uchar *name;
  int iVar13;
  int iVar14;
  int32 *piVar15;
  double dVar16;
  double dVar17;
  uchar *puStack_553e4;
  uchar *puStack_553e0;
  int iStack_553d4;
  uchar auStack_553c6 [349002];
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
                       Unresolved local var: uchar[349002] dtexdata@[???]
                       Unresolved local var: uchar * pPal@[???]
                       Unresolved local var: qboolean wads_parsed@[???]
                       Unresolved local var: double starttime@[???]
                       Unresolved local var: uchar * rawtex@[???]
                       Unresolved local var: qboolean IsCzeroAndIsSkyCullAndIsD3D@[???] */
  dVar16 = Sys_FloatTime();
  if (tested == 0) {
    Mod_AdInit();
  }
  if (l->filelen == 0) {
    loadmodel->textures = (texture_t **)0x0;
    return;
  }
  piVar15 = (int32 *)(mod_base + l->fileofs);
  iVar5 = (*LittleLong)(*piVar15);
  *piVar15 = iVar5;
  pmVar4 = loadmodel;
  loadmodel->numtextures = iVar5;
  pptVar6 = Hunk_AllocName(*piVar15 << 2,loadname);
  pmVar4->textures = pptVar6;
  if (0 < *piVar15) {
    iVar14 = 0;
    bVar3 = false;
    do {
      iVar5 = (*LittleLong)(piVar15[iVar14 + 1]);
      piVar15[iVar14 + 1] = iVar5;
      if (iVar5 != -1) {
        name = (uchar *)((int)piVar15 + iVar5);
        if ((r_wadtextures.value != 0.0) ||
           (iVar5 = (*LittleLong)(*(int32 *)(name + 0x18)), iVar5 == 0)) {
          if (!bVar3) {
            TEX_InitFromWad(wadpath);
            TEX_AddAnimatingTextures();
          }
          iVar7 = TEX_LoadLump((char *)name,auStack_553c6,0x5534a);
          if (iVar7 == 0) {
            piVar15[iVar14 + 1] = -1;
            bVar3 = true;
            goto LAB_001b9f2b;
          }
          bVar3 = true;
          name = auStack_553c6;
        }
        iVar5 = (*LittleLong)(*(int32 *)(name + 0x10));
        *(int32 *)(name + 0x10) = iVar5;
        iVar5 = (*LittleLong)(*(int32 *)(name + 0x14));
        *(int32 *)(name + 0x14) = iVar5;
        iVar5 = (*LittleLong)(*(int32 *)(name + 0x18));
        *(int32 *)(name + 0x18) = iVar5;
        iVar5 = (*LittleLong)(*(int32 *)(name + 0x1c));
        *(int32 *)(name + 0x1c) = iVar5;
        iVar5 = (*LittleLong)(*(int32 *)(name + 0x20));
        *(int32 *)(name + 0x20) = iVar5;
        iVar5 = (*LittleLong)(*(int32 *)(name + 0x24));
        *(int32 *)(name + 0x24) = iVar5;
        uVar8 = *(uint *)(name + 0x10);
        if (((uVar8 & 0xf) != 0) || (uVar12 = *(uint *)(name + 0x14), (uVar12 & 0xf) != 0)) {
          Sys_Error("Texture %s is not 16 aligned",name);
          uVar8 = *(uint *)(name + 0x10);
          uVar12 = *(uint *)(name + 0x14);
        }
        iVar7 = (uVar8 * uVar12 >> 6) * 0x55;
        uVar1 = *(ushort *)(name + iVar7 + 0x28);
        ptVar9 = Hunk_AllocName((uint)uVar1 * 3 + 0x48,loadname);
        loadmodel->textures[iVar14] = ptVar9;
        Q_memcpy(ptVar9,name,0x10);
        ptVar9->width = *(uint *)(name + 0x10);
        ptVar9->height = *(uint *)(name + 0x14);
        puStack_553e4 = name + iVar7 + 0x2a;
        ptVar9->pPal = (byte *)(ptVar9 + 1);
        Q_memcpy(ptVar9 + 1,puStack_553e4,(uint)uVar1 * 3);
        puStack_553e0 = name + 0x28;
                    /* Unresolved local var: texture_t * tex@[???] */
        if (((ad_enabled != 0) && (iVar13 = Q_stricmp(ptVar9->name,"DEFAULT"), iVar13 == 0)) &&
           (tested != 0)) {
          iVar13 = Draw_CacheIndex(&ad_wad,"img");
          pvVar10 = Draw_CacheGet(&ad_wad,iVar13);
          if (pvVar10 != (void *)0x0) {
            puStack_553e0 = (uchar *)((int)pvVar10 + 0x48);
            puStack_553e4 = (uchar *)((int)pvVar10 + iVar7 + 0x4a);
          }
        }
        iVar7 = Q_strncmp((char *)name,"sky",3);
        if (iVar7 == 0) {
          R_InitSky();
          iVar7 = ptVar9->gl_texturenum;
        }
        else {
          texture_mode = 0x2701;
          iVar7 = GL_LoadTexture((char *)name,GLT_WORLD,ptVar9->width,ptVar9->height,puStack_553e0,1
                                 ,(uint)(*name == '{'),puStack_553e4);
          texture_mode = 0x2601;
          ptVar9->gl_texturenum = iVar7;
        }
        DT_LoadDetailTexture((char *)name,iVar7);
      }
LAB_001b9f2b:
      iVar5 = *piVar15;
      iVar14 = iVar14 + 1;
    } while (iVar14 < iVar5);
    if (bVar3) {
      TEX_CleanupWadInfo();
      iVar5 = *piVar15;
    }
    if (0 < iVar5) {
      iVar14 = 1;
      do {
        iVar7 = iVar14 * 4;
        ptVar9 = loadmodel->textures[iVar14 + -1];
        if (((ptVar9 != (texture_t *)0x0) && ((ptVar9->name[0] == '-' || (ptVar9->name[0] == '+'))))
           && (ptVar9->anim_next == (texture_s *)0x0)) {
          Q_memset(local_7c,0,0x28);
          Q_memset(local_4c,0,0x28);
          iStack_553d4 = (int)ptVar9->name[1];
          if (iStack_553d4 - 0x61U < 0x1a) {
            iStack_553d4 = iStack_553d4 + -0x20;
          }
          if (iStack_553d4 - 0x30U < 10) {
            local_7c[iStack_553d4 - 0x30U] = (int)ptVar9;
            iStack_553d4 = iStack_553d4 + -0x2f;
            puStack_553e4 = (uchar *)0x0;
          }
          else {
            uVar8 = iStack_553d4 - 0x41;
            if (uVar8 < 10) {
              puStack_553e4 = (uchar *)(iStack_553d4 + -0x40);
              iStack_553d4 = 0;
              local_4c[uVar8] = (int)ptVar9;
            }
            else {
              Sys_Error("Bad animating texture %s",ptVar9);
              puStack_553e4 = (uchar *)0x0;
            }
          }
          iVar5 = *piVar15;
          if (iVar14 < iVar5) {
            iVar13 = iVar14;
            do {
              while ((pcVar2 = *(char **)((int)loadmodel->textures + iVar7), pcVar2 == (char *)0x0
                     || ((*pcVar2 != '-' && (*pcVar2 != '+'))))) {
LAB_001ba314:
                iVar13 = iVar13 + 1;
                iVar7 = iVar7 + 4;
                if (iVar5 <= iVar13) goto LAB_001ba3c8;
              }
              iVar11 = Q_strcmp(pcVar2 + 2,ptVar9->name + 2);
              if (iVar11 == 0) {
                iVar11 = (int)pcVar2[1];
                if (iVar11 - 0x61U < 0x1a) {
                  iVar11 = iVar11 + -0x20;
                }
                uVar8 = iVar11 - 0x30;
                if (uVar8 < 10) {
                  local_7c[uVar8] = (int)pcVar2;
                  if (iStack_553d4 <= (int)uVar8) {
                    iStack_553d4 = iVar11 + -0x2f;
                    iVar5 = *piVar15;
                    goto LAB_001ba314;
                  }
                }
                else {
                  uVar8 = iVar11 - 0x41;
                  if (uVar8 < 10) {
                    local_4c[uVar8] = (int)pcVar2;
                    if ((int)puStack_553e4 <= (int)uVar8) {
                      puStack_553e4 = (uchar *)(iVar11 + -0x40);
                      iVar5 = *piVar15;
                      goto LAB_001ba314;
                    }
                  }
                  else {
                    Sys_Error("Bad animating texture %s",ptVar9);
                  }
                }
              }
              iVar13 = iVar13 + 1;
              iVar7 = iVar7 + 4;
              iVar5 = *piVar15;
            } while (iVar13 < iVar5);
          }
LAB_001ba3c8:
          if (iStack_553d4 < 1) {
LAB_001ba4ae:
            if (0 < (int)puStack_553e4) {
              iVar7 = 0;
              if (iStack_553d4 == 0) {
                iVar7 = 0;
                do {
                  iVar13 = local_4c[iVar7];
                  if (iVar13 == 0) {
                    Sys_Error("Missing frame %i of %s",iVar7);
                  }
                  *(int *)(iVar13 + 0x24) = iVar7;
                  iVar7 = iVar7 + 1;
                  *(uchar **)(iVar13 + 0x20) = puStack_553e4;
                  *(int *)(iVar13 + 0x28) = iVar7;
                  *(int *)(iVar13 + 0x2c) = local_4c[iVar7 % (int)puStack_553e4];
                } while ((uchar *)iVar7 != puStack_553e4);
              }
              else {
                do {
                  iVar13 = local_4c[iVar7];
                  if (iVar13 == 0) {
                    Sys_Error("Missing frame %i of %s",iVar7);
                  }
                  *(int *)(iVar13 + 0x24) = iVar7;
                  iVar7 = iVar7 + 1;
                  *(uchar **)(iVar13 + 0x20) = puStack_553e4;
                  *(int *)(iVar13 + 0x28) = iVar7;
                  *(int *)(iVar13 + 0x2c) = local_4c[iVar7 % (int)puStack_553e4];
                  *(int *)(iVar13 + 0x30) = local_7c[0];
                } while ((uchar *)iVar7 != puStack_553e4);
              }
              iVar5 = *piVar15;
              goto LAB_001b9f84;
            }
          }
          else {
            iVar7 = 0;
            if (puStack_553e4 != (uchar *)0x0) {
              do {
                iVar13 = local_7c[iVar7];
                if (iVar13 == 0) {
                  Sys_Error("Missing frame %i of %s",iVar7);
                }
                *(int *)(iVar13 + 0x24) = iVar7;
                iVar7 = iVar7 + 1;
                *(int *)(iVar13 + 0x20) = iStack_553d4;
                *(int *)(iVar13 + 0x28) = iVar7;
                *(int *)(iVar13 + 0x2c) = local_7c[iVar7 % iStack_553d4];
                *(int *)(iVar13 + 0x30) = local_4c[0];
              } while (iVar7 != iStack_553d4);
              goto LAB_001ba4ae;
            }
            iVar7 = 0;
            do {
              iVar13 = local_7c[iVar7];
              if (iVar13 == 0) {
                Sys_Error("Missing frame %i of %s",iVar7);
              }
              *(int *)(iVar13 + 0x24) = iVar7;
              iVar7 = iVar7 + 1;
              *(int *)(iVar13 + 0x20) = iStack_553d4;
              *(int *)(iVar13 + 0x28) = iVar7;
              *(int *)(iVar13 + 0x2c) = local_7c[iVar7 % iStack_553d4];
            } while (iVar7 != iStack_553d4);
          }
          iVar5 = *piVar15;
        }
LAB_001b9f84:
        bVar3 = iVar14 < iVar5;
        iVar14 = iVar14 + 1;
      } while (bVar3);
    }
  }
  dVar17 = Sys_FloatTime();
  Con_DPrintf("Texture load: %6.1fms\n",(dVar17 - dVar16) * 1000.0);
  return;
}


// Mod_LoadVertexes  @ 001ba7f0
void Mod_LoadVertexes(lump_t *l)

{
  float *pfVar1;
  int iVar2;
  model_t *pmVar3;
  uchar *puVar4;
  mvertex_t *pmVar5;
  uint uVar6;
  float *pfVar7;
  uint uVar8;
  longdouble lVar9;
  
                    /* Unresolved local var: dvertex_t * in@[???]
                       Unresolved local var: mvertex_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  puVar4 = mod_base;
  uVar6 = l->filelen;
  iVar2 = l->fileofs;
  if (uVar6 != (uVar6 / 0xc) * 0xc) {
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    uVar6 = l->filelen;
  }
  uVar6 = uVar6 / 0xc;
  pmVar5 = Hunk_AllocName(uVar6 * 0xc,loadname);
  pmVar3 = loadmodel;
  loadmodel->vertexes = pmVar5;
  pmVar3->numvertexes = uVar6;
  if (uVar6 != 0) {
    pfVar7 = (float *)(puVar4 + iVar2);
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


// Mod_LoadVisibility  @ 001ba690
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


// Mod_MakeHull0  @ 001bbab0
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
      if (iVar8 < 0) goto LAB_001bbb9c;
LAB_001bbb44:
      pdVar3->children[1] = (short)((int)pmVar5 - (int)loadmodel->nodes >> 2) * 0x4ec5;
      pmVar7 = loadmodel;
    }
    else {
      pdVar3->children[0] = (short)((int)pmVar6->children[0] - (int)loadmodel->nodes >> 2) * 0x4ec5;
      pmVar5 = pmVar6->children[1];
      iVar8 = pmVar5->contents;
      if (-1 < iVar8) goto LAB_001bbb44;
LAB_001bbb9c:
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


// Mod_MarkClient  @ 001b9ce0
void Mod_MarkClient(model_t *pModel)

{
  pModel->needload = 3;
  return;
}


// Mod_NeedCRC  @ 001b9c20
void Mod_NeedCRC(char *name,qboolean needCRC)

{
  model_t *pmVar1;
  
                    /* Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  pmVar1 = Mod_FindName(false,name);
  *(qboolean *)((int)mod_known_info + ((int)&pmVar1[-0x9aa7].numedges >> 3) * 0x397829cc) = needCRC;
  return;
}


// Mod_PointInLeaf  @ 001b9940
mleaf_t * Mod_PointInLeaf(vec_t *p,model_t *model)

{
  float *pfVar1;
  mleaf_t *pmVar2;
  
                    /* Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: mplane_t * plane@[???] */
  if ((model == (model_t *)0x0) || (pmVar2 = (mleaf_t *)model->nodes, pmVar2 == (mleaf_t *)0x0)) {
    Sys_Error("Mod_PointInLeaf: bad model");
    pmVar2 = (mleaf_t *)model->nodes;
  }
  do {
    if (pmVar2->contents < 0) {
      return pmVar2;
    }
    while (pfVar1 = (float *)pmVar2->compressed_vis,
          0.0 < (p[2] * pfVar1[2] + p[1] * pfVar1[1] + *p * *pfVar1) - pfVar1[3]) {
      pmVar2 = (mleaf_t *)pmVar2->efrags;
      if ((int)pmVar2->contents < 0) {
        return pmVar2;
      }
    }
    pmVar2 = (mleaf_t *)pmVar2->firstmarksurface;
  } while( true );
}


// Mod_Print  @ 001bdba0
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


// Mod_SetParent  @ 001bb2f0
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


// Mod_SpriteTextureName  @ 001bd040
void Mod_SpriteTextureName(char *pszName,int nNameSize,char *pcszModelName,int framenum)

{
  snprintf(pszName,nNameSize,"%s_%i",pcszModelName,framenum);
  return;
}


// Mod_UnloadSpriteTextures  @ 001bd260
void Mod_UnloadSpriteTextures(model_t *pModel)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  char local_11c [268];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: msprite_t * pSprite@[???]
                       Unresolved local var: char[256] name@[???] */
  if (pModel->type == mod_sprite) {
    pvVar1 = (pModel->cache).data;
    pModel->needload = true;
    if ((pvVar1 != (void *)0x0) && (0 < *(int *)((int)pvVar1 + 0xc))) {
      iVar2 = 0;
      do {
        iVar3 = iVar2 + 1;
        snprintf(local_11c,0x100,"%s_%i",pModel,iVar2);
        GL_UnloadTexture(local_11c);
        iVar2 = iVar3;
      } while (iVar3 < *(int *)((int)pvVar1 + 0xc));
    }
  }
  return;
}


// Mod_ValidateCRC  @ 001b9bd0
qboolean Mod_ValidateCRC(char *name,CRC32_t crc)

{
  int iVar1;
  model_t *pmVar2;
  qboolean qVar3;
  
                    /* Unresolved local var: mod_known_info_t * p@[DW_OP_reg2(EDX)]
                       Unresolved local var: model_t * mod@[???] */
  pmVar2 = Mod_FindName(true,name);
  iVar1 = ((int)&pmVar2[-0x9aa7].numedges >> 3) * 0x397829cc;
  qVar3 = true;
  if (*(int *)((int)mod_known_info + iVar1 + 4) != 0) {
    qVar3 = (qboolean)(*(CRC32_t *)((int)mod_known_info + iVar1 + 8) == crc);
  }
  return qVar3;
}


