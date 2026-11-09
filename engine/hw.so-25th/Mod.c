// Mod_AdInit  @ 001621e0
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
      Draw_CacheWadHandler(&ad_wad,Draw_MiptexTexture,0x20);
      ad_enabled = 1;
      return;
    }
    Con_Printf("No -ad file specified, skipping\n");
  }
  return;
}


// Mod_AdSwap  @ 001622b0
void Mod_AdSwap(texture_t *src,int pixels,uchar **rawtex,uchar **pPal,int entries)

{
  int index;
  void *pvVar1;
  
                    /* Unresolved local var: texture_t * tex@[???] */
  if (tested == 0) {
    return;
  }
                    /* Unresolved local var: texture_t * tex@[???] */
  index = Draw_CacheIndex(&ad_wad,"img");
  pvVar1 = Draw_CacheGet(&ad_wad,index);
  if (pvVar1 != (void *)0x0) {
    *rawtex = (uchar *)((int)pvVar1 + 0x48);
    *pPal = (uchar *)((int)pvVar1 + pixels + 0x4a);
  }
  return;
}


// Mod_ChangeGame  @ 001620e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_ChangeGame(void)

{
  msurface_t *pmVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  qboolean *pqVar7;
  cache_user_t *c;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  if (0 < mod_numknown) {
    local_20 = 0;
    pqVar7 = &mod_known_info[0].firstCRCDone;
    c = &mod_known[0].cache;
    do {
      if ((*(modtype_t *)(c + -0x50) == mod_studio) &&
         (pvVar3 = Cache_Check(c), pvVar3 != (void *)0x0)) {
        Cache_Free(c);
      }
                    /* Unresolved local var: int surface@[???] */
      iVar4 = *(int *)(c + -0x35);
      *pqVar7 = false;
      pqVar7[1] = 0;
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          while( true ) {
                    /* Unresolved local var: mdisplaylist_t * displaylist@[???] */
            pmVar1 = c[-0x34].data;
            uVar2 = pmVar1[iVar5].displaylist.gl_displaylist;
            if (uVar2 == 0) break;
            iVar6 = iVar5 + 1;
            glDeleteLists(uVar2,1);
            pmVar1[iVar5].displaylist.gl_displaylist = 0;
            iVar4 = *(int *)(c + -0x35);
            iVar5 = iVar6;
            if (iVar4 <= iVar6) goto LAB_0016217e;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
LAB_0016217e:
      local_20 = local_20 + 1;
      pqVar7 = pqVar7 + 3;
      c = c + 0x62;
    } while (local_20 < mod_numknown);
  }
  return;
}


// Mod_ClearAll  @ 00161da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_ClearAll(void)

{
  msurface_t *pmVar1;
  uint uVar2;
  modtype_t mVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  model_t *pmVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???] */
  if (0 < mod_numknown) {
    iVar7 = 0;
    pmVar8 = mod_known;
    iVar5 = mod_numknown;
    do {
      while ((mVar3 = pmVar8->type, mVar3 != mod_alias && (pmVar8->needload != 3))) {
        if (pmVar8->needload != 2) {
                    /* Unresolved local var: int surface@[???] */
          iVar4 = pmVar8->numsurfaces;
          if (0 < iVar4) {
            iVar5 = 0;
            do {
              while( true ) {
                    /* Unresolved local var: mdisplaylist_t * displaylist@[???] */
                pmVar1 = pmVar8->surfaces;
                uVar2 = pmVar1[iVar5].displaylist.gl_displaylist;
                if (uVar2 == 0) break;
                iVar6 = iVar5 + 1;
                glDeleteLists(uVar2,1);
                pmVar1[iVar5].displaylist.gl_displaylist = 0;
                iVar4 = pmVar8->numsurfaces;
                iVar5 = iVar6;
                if (iVar4 <= iVar6) goto LAB_00161e26;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar4);
LAB_00161e26:
            mVar3 = pmVar8->type;
            iVar5 = mod_numknown;
          }
          pmVar8->needload = 2;
        }
        if (mVar3 != mod_sprite) break;
        iVar7 = iVar7 + 1;
        (pmVar8->cache).data = (void *)0x0;
        pmVar8 = pmVar8 + 1;
        if (iVar5 <= iVar7) {
          return;
        }
      }
      iVar7 = iVar7 + 1;
      pmVar8 = pmVar8 + 1;
    } while (iVar7 < iVar5);
  }
  return;
}


// Mod_DecompressVis  @ 0009c970
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


// Mod_Extradata  @ 00166ab0
void * Mod_Extradata(model_t *mod)

{
  void *pvVar1;
  
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
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[4096] tmpName@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  if (mod->type - mod_alias < 2) {
    pvVar1 = Cache_Check(&mod->cache);
    if (pvVar1 != (void *)0x0) {
      mod->needload = false;
      goto LAB_00166b35;
    }
  }
  else if ((mod->needload == false) || (mod->needload == 3)) goto LAB_00166b35;
  Mod_LoadModel(mod,true,false);
LAB_00166b35:
  pvVar1 = (mod->cache).data;
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Mod_Extradata: caching failed");
}


// Mod_FillInCRCInfo  @ 00161e70
void Mod_FillInCRCInfo(qboolean trackCRC,int model_number)

{
                    /* Unresolved local var: mod_known_info_t * p@[???] */
  mod_known_info[model_number].shouldCRC = trackCRC;
  mod_known_info[model_number].firstCRCDone = false;
  mod_known_info[model_number].initialCRC = 0;
  return;
}


// Mod_FindName  @ 00161ea0
model_t * Mod_FindName(qboolean trackCRC,char *name)

{
  qboolean qVar1;
  model_t *pmVar2;
  int iVar3;
  int iVar4;
  model_t *s1;
  model_t *dest;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: model_t * mod@[???]
                       Unresolved local var: model_t * avail@[???] */
  if (*name == '\0') {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_FindName: NULL name");
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
    dest = (model_t *)0x0;
    pmVar2 = mod_known;
    iVar3 = 0;
    do {
      while( true ) {
        iVar4 = iVar3;
        s1 = pmVar2;
        iVar3 = Q_strcmp(s1->name,name);
        if (iVar3 == 0) goto joined_r0x00161f37;
        pmVar2 = dest;
        if ((s1->needload == 2) && (pmVar2 = s1, dest != (model_t *)0x0)) break;
        dest = pmVar2;
        pmVar2 = s1 + 1;
        iVar3 = iVar4 + 1;
        if (mod_numknown <= iVar4 + 1) goto LAB_00161f1a;
      }
      if (1 < s1->type - mod_alias) {
        dest = s1;
      }
      pmVar2 = s1 + 1;
      iVar3 = iVar4 + 1;
    } while (iVar4 + 1 < mod_numknown);
LAB_00161f1a:
    iVar4 = iVar4 + 1;
    s1 = s1 + 1;
joined_r0x00161f37:
    if (iVar4 != mod_numknown) {
      return s1;
    }
    if (0x3ff < iVar4) {
      if (dest == (model_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("mod_numknown >= MAX_KNOWN_MODELS");
      }
                    /* Unresolved local var: mod_known_info_t * p@[???] */
      iVar4 = ((int)(dest[-0x9e46].name + 0x10) >> 3) * 0x397829cc;
      *(qboolean *)((int)mod_known_info + iVar4) = trackCRC;
      *(undefined4 *)((int)mod_known_info + iVar4 + 4) = 0;
      *(undefined4 *)((int)mod_known_info + iVar4 + 8) = 0;
      goto LAB_00161f7f;
    }
    mod_numknown = iVar4 + 1;
    dest = s1;
  }
                    /* Unresolved local var: mod_known_info_t * p@[???] */
  mod_known_info[iVar4].firstCRCDone = false;
  mod_known_info[iVar4].shouldCRC = trackCRC;
  mod_known_info[iVar4].initialCRC = 0;
LAB_00161f7f:
  Q_strncpy(dest->name,name,0x3f);
  qVar1 = dest->needload;
  dest->name[0x3f] = '\0';
  if (qVar1 == 3) {
    return dest;
  }
  dest->needload = true;
  return dest;
}


// Mod_FloodFillSkin  @ 001656e0
void Mod_FloodFillSkin(byte *skin,int skinwidth,int skinheight)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  int local_4020;
  short local_4010 [8192];
  
                    /* Unresolved local var: byte fillcolor@[???]
                       Unresolved local var: floodfill_t[4096] fifo@[???]
                       Unresolved local var: int inpt@[???]
                       Unresolved local var: int outpt@[???]
                       Unresolved local var: int filledcolor@[???] */
  bVar1 = *skin;
  if (0xfd < (byte)(bVar1 - 1)) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int fdc@[???]
                       Unresolved local var: byte * pos@[???] */
  uVar6 = 1;
  local_4020 = 0;
  uVar9 = 1;
  iVar8 = 0;
  local_4010[0] = 0;
  local_4010[1] = 0;
  pbVar4 = skin;
LAB_00165759:
  bVar5 = '\0';
  if (skinwidth + -1 <= iVar8) goto LAB_00165775;
  bVar7 = pbVar4[1];
  if (bVar1 == bVar7) goto LAB_00165835;
  do {
    if (bVar7 != 0xff) {
      bVar5 = bVar7;
    }
LAB_00165775:
    while( true ) {
      do {
        if (0 < local_4020) {
          bVar7 = pbVar4[-skinwidth];
          if (bVar1 == bVar7) {
            local_4010[uVar9 * 2] = (short)iVar8;
            pbVar4[-skinwidth] = 0xff;
            local_4010[uVar9 * 2 + 1] = (short)local_4020 + -1;
            uVar9 = uVar9 + 1 & 0xfff;
          }
          else if (bVar7 != 0xff) {
            bVar5 = bVar7;
          }
        }
        if (local_4020 < skinheight + -1) {
          bVar7 = pbVar4[skinwidth];
          if (bVar1 == bVar7) {
            local_4010[uVar9 * 2] = (short)iVar8;
            pbVar4[skinwidth] = 0xff;
            local_4010[uVar9 * 2 + 1] = (short)local_4020 + 1;
            uVar9 = uVar9 + 1 & 0xfff;
          }
          else if (bVar7 != 0xff) {
            bVar5 = bVar7;
          }
        }
        *pbVar4 = bVar5;
        if (uVar9 == uVar6) {
          return;
        }
        sVar2 = local_4010[uVar6 * 2 + 1];
        local_4020 = (int)sVar2;
        iVar3 = uVar6 * 2;
        iVar8 = (int)local_4010[iVar3];
        uVar6 = uVar6 + 1 & 0xfff;
        pbVar4 = skin + local_4020 * skinwidth + iVar8;
        if (iVar8 < 1) goto LAB_00165759;
        bVar5 = pbVar4[-1];
        if (bVar1 == bVar5) {
          local_4010[uVar9 * 2] = local_4010[iVar3] + -1;
          pbVar4[-1] = 0xff;
          local_4010[uVar9 * 2 + 1] = sVar2;
          uVar9 = uVar9 + 1 & 0xfff;
          goto LAB_00165759;
        }
        if (bVar5 == 0xff) {
          bVar5 = '\0';
        }
      } while (skinwidth + -1 <= iVar8);
      bVar7 = pbVar4[1];
      if (bVar1 != bVar7) break;
LAB_00165835:
      local_4010[uVar9 * 2] = (short)iVar8 + 1;
      pbVar4[1] = 0xff;
      local_4010[uVar9 * 2 + 1] = (short)local_4020;
      uVar9 = uVar9 + 1 & 0xfff;
    }
  } while( true );
}


// Mod_ForName  @ 00166a20
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
  else if ((pmVar1->needload == false) || (pmVar1->needload == 3)) {
    return pmVar1;
  }
  pmVar1 = Mod_LoadModel(pmVar1,crash,trackCRC);
  return pmVar1;
}


// Mod_Init  @ 0009c940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Mod_Init(void)

{
  Q_memset(mod_novis,0xff,0x400);
  return;
}


// Mod_LeafPVS  @ 0009ca70
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
      return gPVS + ((int)leaf - (int)model->leafs >> 2) * -0x11111111 * gPVSRowBytes;
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


// Mod_LoadAliasFrame  @ 00165590
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


// Mod_LoadAliasGroup  @ 00165620
void * Mod_LoadAliasGroup(void *pin,maliasframedesc_t *frame)

{
  int iVar1;
  aliashdr_t *paVar2;
  int32 iVar3;
  void *pvVar4;
  trivertx_t **pptVar5;
  trivertx_t **pptVar6;
  longdouble lVar7;
  
                    /* Unresolved local var: daliasgroup_t * pingroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: daliasinterval_t * pin_intervals@[???]
                       Unresolved local var: void * ptemp@[DW_OP_reg1(ECX)] */
  iVar3 = (*LittleLong)(*(int32 *)pin);
  iVar1 = posenum;
  frame->numposes = iVar3;
  frame->firstpose = iVar1;
  (frame->bboxmin).v[0] = *(byte *)((int)pin + 4);
  (frame->bboxmin).v[0] = *(byte *)((int)pin + 8);
  (frame->bboxmin).v[1] = *(byte *)((int)pin + 5);
  (frame->bboxmin).v[1] = *(byte *)((int)pin + 9);
  (frame->bboxmin).v[2] = *(byte *)((int)pin + 6);
  (frame->bboxmin).v[2] = *(byte *)((int)pin + 10);
  lVar7 = (longdouble)(*LittleFloat)(*(float *)((int)pin + 0xc));
  pvVar4 = (void *)((int)pin + iVar3 * 4 + 0xc);
  frame->interval = (float)lVar7;
  paVar2 = pheader;
  if (0 < iVar3) {
    iVar1 = iVar3 + posenum;
    pptVar5 = poseverts + posenum;
    do {
      pptVar6 = pptVar5 + 1;
      *pptVar5 = (trivertx_t *)((int)pvVar4 + 0x18);
      pvVar4 = (void *)((int)pvVar4 + paVar2->numverts * 4 + 0x18);
      pptVar5 = pptVar6;
      posenum = iVar1;
    } while (pptVar6 != poseverts + iVar1);
  }
  return pvVar4;
}


// Mod_LoadAliasModel  @ 00165a90
void Mod_LoadAliasModel(model_t *mod,void *buffer)

{
  void *dest;
  int mark;
  int32 iVar1;
  synctype_t sVar2;
  int32 *piVar3;
  int iVar4;
  stvert_t *psVar5;
  float *pfVar6;
  int iVar7;
  int32 *piVar8;
  aliashdr_t *paVar9;
  int iVar10;
  longdouble lVar11;
  
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
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 4));
  if (iVar1 != 6) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has wrong version number (%i should be %i)",mod,iVar1,6)
    ;
  }
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  pheader = Hunk_AllocName((iVar1 * 5 + -5) * 8 + 0x10c,loadname);
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x4c));
  paVar9 = pheader;
  mod->flags = iVar1;
  lVar11 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  paVar9->boundingradius = (float)lVar11;
  paVar9 = pheader;
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x30));
  paVar9->numskins = iVar1;
  paVar9 = pheader;
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x34));
  paVar9->skinwidth = iVar1;
  paVar9 = pheader;
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x38));
  paVar9->skinheight = iVar1;
  paVar9 = pheader;
  if (0x1e0 < pheader->skinheight) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has a skin taller than %d",mod,0x1e0);
  }
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x3c));
  paVar9->numverts = iVar1;
  paVar9 = pheader;
  iVar4 = pheader->numverts;
  if (iVar4 < 1) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has no vertices: %d",mod,iVar4);
  }
  if (0x400 < iVar4) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has too many vertices: %d",mod,iVar4);
  }
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x40));
  paVar9->numtris = iVar1;
  paVar9 = pheader;
  iVar4 = pheader->numtris;
  if (iVar4 < 1) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has no triangles: %d",mod,iVar4);
  }
  if (0x800 < iVar4) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has too many triangles: %d",mod,iVar4);
  }
  iVar1 = (*LittleLong)(*(int32 *)((int)buffer + 0x44));
  paVar9->numframes = iVar1;
  paVar9 = pheader;
  iVar4 = pheader->numframes;
  if (iVar4 < 1) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has no frames: %d",mod,iVar4);
  }
  if (0x100 < iVar4) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Model %s has too many frames: %d",mod,iVar4);
  }
  lVar11 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x50));
  paVar9->size = (float)((longdouble)0.09090909090909091 * lVar11);
  iVar4 = 0;
  sVar2 = (*LittleLong)(*(int32 *)((int)buffer + 0x48));
  mod->synctype = sVar2;
  paVar9 = pheader;
  mod->numframes = pheader->numframes;
  pfVar6 = (float *)((int)buffer + 8);
  do {
    lVar11 = (longdouble)(*LittleFloat)(*pfVar6);
    paVar9->scale[iVar4] = (float)lVar11;
    paVar9 = pheader;
    lVar11 = (longdouble)(*LittleFloat)(pfVar6[3]);
    paVar9->scale_origin[iVar4] = (float)lVar11;
    paVar9 = pheader;
    lVar11 = (longdouble)(*LittleFloat)(pfVar6[7]);
    paVar9->eyeposition[iVar4] = (float)lVar11;
    iVar4 = iVar4 + 1;
    pfVar6 = pfVar6 + 1;
    paVar9 = pheader;
  } while (iVar4 != 3);
  piVar3 = Mod_LoadAllSkins(pheader->numskins,(daliasskintype_t *)((int)buffer + 0x54));
  iVar4 = pheader->numverts;
  if (0 < iVar4) {
    iVar7 = 0;
    psVar5 = stverts;
    piVar8 = piVar3;
    do {
      iVar7 = iVar7 + 1;
      iVar1 = (*LittleLong)(*piVar8);
      psVar5->onseam = iVar1;
      iVar1 = (*LittleLong)(piVar8[1]);
      psVar5->s = iVar1;
      iVar1 = (*LittleLong)(piVar8[2]);
      psVar5->t = iVar1;
      iVar4 = pheader->numverts;
      psVar5 = psVar5 + 1;
      piVar8 = piVar8 + 3;
    } while (iVar7 < iVar4);
  }
  piVar3 = piVar3 + iVar4 * 3;
  if (0 < pheader->numtris) {
    iVar4 = 0;
    iVar7 = 0;
    do {
      iVar10 = 0;
      iVar1 = (*LittleLong)(*piVar3);
      *(int32 *)((int)triangles[0].vertindex + iVar4 + -4) = iVar1;
      do {
        iVar1 = (*LittleLong)(piVar3[iVar10 + 1]);
        *(int32 *)(iVar4 + 0xf1ab04 + iVar10 * 4) = iVar1;
        iVar10 = iVar10 + 1;
      } while (iVar10 != 3);
      iVar7 = iVar7 + 1;
      piVar3 = piVar3 + 4;
      iVar4 = iVar4 + 0x10;
    } while (iVar7 < pheader->numtris);
  }
  paVar9 = pheader;
  pheader->numposes = 0;
  posenum = 0;
  mod->type = mod_alias;
  mod->mins[2] = -16.0;
  mod->mins[1] = -16.0;
  mod->mins[0] = -16.0;
  mod->maxs[2] = 16.0;
  mod->maxs[1] = 16.0;
  mod->maxs[0] = 16.0;
  GL_MakeAliasModelDisplayLists(mod,paVar9);
  iVar4 = Hunk_LowMark();
  Cache_Alloc(&mod->cache,iVar4 - mark,loadname);
  dest = (mod->cache).data;
  if (dest == (void *)0x0) {
    return;
  }
  Q_memcpy(dest,pheader,iVar4 - mark);
  Hunk_FreeToLowMark(mark);
  return;
}


// Mod_LoadAllSkins  @ 001658e0
void * Mod_LoadAllSkins(int numskins,daliasskintype_t *pskintype)

{
  daliasskintype_t *skin;
  aliashdr_t *paVar1;
  int iVar2;
  int iVar3;
  daliasskintype_t *data;
  uint count;
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[32] name@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: byte * skin@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  skin = pskintype + 1;
  if (0x1f < numskins - 1U) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadAliasModel: Invalid # of skins: %d\n",numskins);
  }
  iVar3 = 0;
  data = skin;
  while( true ) {
    Mod_FloodFillSkin((byte *)skin,pheader->skinwidth,pheader->skinheight);
    count = pheader->skinwidth * pheader->skinheight;
    iVar2 = Q_strcmp(loadmodel->name,"progs/player.mdl");
    if (iVar2 == 0) {
      if (64000 < count) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Player skin too large");
      }
      Q_memcpy(player_8bit_texels,data,count);
    }
    pskintype = (daliasskintype_t *)((int)&pskintype[1].type + count);
    __snprintf_chk(local_40,0x20,1,0x20,"%s_%i",loadmodel,iVar3);
    paVar1 = pheader;
    iVar2 = GL_LoadTexture(local_40,GLT_STUDIO,pheader->skinwidth,pheader->skinheight,(byte *)data,1
                           ,0,(byte *)0x0);
    paVar1->gl_texturenum[iVar3] = iVar2;
    iVar3 = iVar3 + 1;
    if (numskins == iVar3) break;
    data = pskintype + 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (aliasskintype_t *)pskintype;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Mod_LoadBrushModel  @ 00164e00
void Mod_LoadBrushModel(model_t *mod,void *buffer)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  bool bVar4;
  byte *pbVar5;
  int32 iVar6;
  int *piVar7;
  int iVar8;
  dclipnode_t *pdVar9;
  int iVar10;
  int iVar11;
  model_t *pmVar12;
  byte *pbVar13;
  color24 *pcVar14;
  mnode_s *pmVar15;
  int iVar16;
  uint uVar17;
  model_t *pmVar18;
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
  iVar6 = (*LittleLong)(*(int32 *)buffer);
  if (iVar6 - 0x1dU < 2) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: dheader_t * header@[???]
                       Unresolved local var: dmodel_t * bm@[???] */
    mod_base = buffer;
    piVar19 = buffer;
    do {
      piVar20 = piVar19 + 1;
      iVar6 = (*LittleLong)(*piVar19);
      *piVar19 = iVar6;
      piVar19 = piVar20;
    } while ((int32 *)((int)buffer + 0x7c) != piVar20);
    Mod_LoadVertexes((lump_t *)((int)buffer + 0x1c));
    Mod_LoadEdges((lump_t *)((int)buffer + 100));
    pbVar5 = mod_base;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
    iVar8 = *(int *)((int)buffer + 0x6c);
    if ((*(uint *)((int)buffer + 0x70) & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
    }
    uVar21 = *(uint *)((int)buffer + 0x70) >> 2;
    piVar7 = Hunk_AllocName(uVar21 * 4,loadname);
    pmVar12 = loadmodel;
    loadmodel->surfedges = piVar7;
    pmVar12->numsurfedges = uVar21;
    if (uVar21 != 0) {
      uVar17 = 0;
      do {
        iVar6 = (*LittleLong)(*(int32 *)(pbVar5 + uVar17 * 4 + iVar8));
        piVar7[uVar17] = iVar6;
        uVar17 = uVar17 + 1;
      } while (uVar21 != uVar17);
    }
    iVar8 = strcasecmp(com_gamedir,"bshift");
    if (iVar8 == 0) {
      Mod_LoadEntities((lump_t *)((int)buffer + 0xc));
      Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
      pmVar12 = loadmodel;
      if (*(int *)((int)buffer + 0x48) == 0) {
        loadmodel->lightdata = (color24 *)0x0;
      }
      else {
        pcVar14 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
        pbVar5 = mod_base;
        pmVar12->lightdata = pcVar14;
        Q_memcpy(loadmodel->lightdata,pbVar5 + *(int *)((int)buffer + 0x44),
                 *(int *)((int)buffer + 0x48));
      }
      Mod_LoadPlanes((lump_t *)((int)buffer + 4));
    }
    else {
      Mod_LoadEntities((lump_t *)((int)buffer + 4));
      Mod_LoadTextures((lump_t *)((int)buffer + 0x14));
      pmVar12 = loadmodel;
      if (*(int *)((int)buffer + 0x48) == 0) {
        loadmodel->lightdata = (color24 *)0x0;
      }
      else {
        pcVar14 = Hunk_AllocName(*(int *)((int)buffer + 0x48),loadname);
        pbVar5 = mod_base;
        pmVar12->lightdata = pcVar14;
        Q_memcpy(loadmodel->lightdata,pbVar5 + *(int *)((int)buffer + 0x44),
                 *(int *)((int)buffer + 0x48));
      }
      Mod_LoadPlanes((lump_t *)((int)buffer + 0xc));
    }
    Mod_LoadTexinfo((lump_t *)((int)buffer + 0x34));
    Mod_LoadFaces((lump_t *)((int)buffer + 0x3c));
    Mod_LoadMarksurfaces((lump_t *)((int)buffer + 0x5c));
    pmVar12 = loadmodel;
    if (*(int *)((int)buffer + 0x28) == 0) {
      loadmodel->visdata = (byte *)0x0;
    }
    else {
      pbVar13 = Hunk_AllocName(*(int *)((int)buffer + 0x28),loadname);
      pbVar5 = mod_base;
      pmVar12->visdata = pbVar13;
      Q_memcpy(loadmodel->visdata,pbVar5 + *(int *)((int)buffer + 0x24),*(int *)((int)buffer + 0x28)
              );
    }
    Mod_LoadLeafs((lump_t *)((int)buffer + 0x54));
    Mod_LoadNodes((lump_t *)((int)buffer + 0x2c));
    Mod_LoadClipnodes((lump_t *)((int)buffer + 0x4c));
    iVar8 = 0;
    Mod_LoadSubmodels((lump_t *)((int)buffer + 0x74));
    pmVar12 = loadmodel;
    if (0 < mod->numsurfaces) {
      do {
        if (mod->numsurfedges < mod->surfaces[iVar8].firstedge + mod->surfaces[iVar8].numedges) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("MOD_LoadBrushModel: more surfedges referenced than loaded in %s",mod);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < mod->numsurfaces);
    }
    iVar8 = 0;
    if (0 < mod->numleafs) {
      do {
                    /* Unresolved local var: int firstmarksurface@[???] */
        if (mod->nummarksurfaces <
            ((int)mod->leafs[iVar8].firstmarksurface - (int)mod->marksurfaces >> 2) +
            mod->leafs[iVar8].nummarksurfaces) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("MOD_LoadBrushModel: more marksurfaces referenced than loaded in %s",mod);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < mod->numleafs);
    }
    iVar8 = 0;
    if (0 < mod->numnodes) {
      do {
        if (mod->numsurfaces <
            (int)((uint)mod->nodes[iVar8].numsurfaces + (uint)mod->nodes[iVar8].firstsurface)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("MOD_LoadBrushModel: more surfaces referenced than loaded in %s",mod);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < mod->numnodes);
    }
    iVar8 = 0;
    if (0 < mod->numsubmodels) {
      do {
        if (mod->numsurfaces < mod->submodels[iVar8].numfaces + mod->submodels[iVar8].firstface) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("MOD_LoadBrushModel: more faces referenced than loaded in %s",mod);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < mod->numsubmodels);
    }
                    /* Unresolved local var: mnode_t * in@[???]
                       Unresolved local var: mnode_t * child@[???]
                       Unresolved local var: dclipnode_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: hull_t * hull@[???] */
    iVar8 = loadmodel->numnodes;
    pmVar22 = loadmodel->nodes;
    pdVar9 = Hunk_AllocName(iVar8 * 8,loadname);
    pmVar18 = loadmodel;
    pmVar12->hulls[0].firstclipnode = 0;
    pmVar12->hulls[0].lastclipnode = iVar8 + -1;
    pmVar12->hulls[0].clipnodes = pdVar9;
    pmVar12->hulls[0].planes = pmVar18->planes;
    if (0 < iVar8) {
      iVar16 = 0;
      do {
        pdVar9->planenum = ((int)pmVar22->plane - (int)pmVar18->planes >> 2) * -0x33333333;
        iVar10 = pmVar22->children[0]->contents;
        if (iVar10 < 0) {
          pdVar9->children[0] = (short)iVar10;
          pmVar15 = pmVar22->children[1];
          iVar10 = pmVar15->contents;
          if (iVar10 < 0) goto LAB_0016523f;
LAB_001651e5:
          pdVar9->children[1] = (short)((int)pmVar15 - (int)loadmodel->nodes >> 2) * 0x4ec5;
          pmVar18 = loadmodel;
        }
        else {
          pdVar9->children[0] =
               (short)((int)pmVar22->children[0] - (int)loadmodel->nodes >> 2) * 0x4ec5;
          pmVar15 = pmVar22->children[1];
          iVar10 = pmVar15->contents;
          if (-1 < iVar10) goto LAB_001651e5;
LAB_0016523f:
          pdVar9->children[1] = (short)iVar10;
          pmVar18 = loadmodel;
        }
        loadmodel = pmVar18;
        if (iVar8 == iVar16 + 1) break;
        pmVar22 = pmVar22 + 1;
        iVar16 = iVar16 + 1;
        pdVar9 = pdVar9 + 1;
      } while( true );
    }
    iVar16 = 0;
    mod->numframes = 2;
    mod->flags = 0;
    iVar8 = 1;
    if (0 < mod->numsubmodels) {
      do {
        pdVar23 = mod->submodels + iVar16;
        mod->hulls[0].firstclipnode = pdVar23->headnode[0];
        mod->hulls[1].firstclipnode = pdVar23->headnode[1];
        iVar11 = mod->numclipnodes + -1;
        mod->hulls[1].lastclipnode = iVar11;
        iVar10 = pdVar23->headnode[2];
        mod->hulls[2].lastclipnode = iVar11;
        mod->hulls[2].firstclipnode = iVar10;
        iVar10 = pdVar23->headnode[3];
        mod->hulls[3].lastclipnode = iVar11;
        mod->hulls[3].firstclipnode = iVar10;
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
        iVar10 = mod->numsubmodels;
        if (iVar16 < iVar10 + -1) {
          __snprintf_chk(local_2a,10,1,10,0x25e199,iVar8);
          pmVar12 = Mod_FindName(false,local_2a);
          uVar21 = 0;
          loadmodel = pmVar12;
          do {
            uVar3 = *(undefined4 *)(mod->name + uVar21);
            *(undefined4 *)(pmVar12->name + uVar21 + 4) = *(undefined4 *)(mod->name + uVar21 + 4);
            *(undefined4 *)(pmVar12->name + uVar21) = uVar3;
            uVar21 = uVar21 + 8;
          } while (uVar21 < 0x188);
          Q_strncpy(loadmodel->name,local_2a,0x3f);
          mod = loadmodel;
          loadmodel->name[0x3f] = '\0';
          iVar10 = mod->numsubmodels;
        }
        iVar16 = iVar16 + 1;
        bVar4 = iVar8 < iVar10;
        iVar8 = iVar8 + 1;
      } while (bVar4);
    }
  }
  else if (cls.state != ca_dedicated) {
    COM_ExplainDisconnection
              (true,"Mod_LoadBrushModel: %s has wrong version number (%i should be %i)\n",mod,iVar6,
               0x1e);
    CL_Disconnect();
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Mod_LoadClipnodes  @ 00164810
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
  piVar8 = (int32 *)(mod_base + l->fileofs);
  if ((l->filelen & 7U) != 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar9 = (uint)l->filelen >> 3;
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


// Mod_LoadEdges  @ 001639f0
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
  psVar4 = (short *)(mod_base + l->fileofs);
  if ((l->filelen & 3U) == 0) {
    uVar5 = (uint)l->filelen >> 2;
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
                    /* WARNING: Subroutine does not return */
  Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
}


// Mod_LoadEntities  @ 001636f0
void Mod_LoadEntities(lump_t *l)

{
  model_t *pmVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: char * pszInputStream@[???] */
  pmVar1 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->entities = (char *)0x0;
  }
  else {
    pcVar3 = Hunk_AllocName(l->filelen,loadname);
    pbVar2 = mod_base;
    pmVar1->entities = pcVar3;
    Q_memcpy(loadmodel->entities,pbVar2 + l->fileofs,l->filelen);
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


// Mod_LoadFaces  @ 00164040
void Mod_LoadFaces(lump_t *l)

{
  mtexinfo_t *pmVar1;
  texture_t *__s1;
  model_t *pmVar2;
  short sVar3;
  short sVar4;
  msurface_t *s;
  int32 iVar5;
  int iVar6;
  color24_conflict *pcVar7;
  short *psVar8;
  uint uVar9;
  uint uVar10;
  
                    /* Unresolved local var: dface_t * in@[???]
                       Unresolved local var: msurface_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int surfnum@[???]
                       Unresolved local var: int planenum@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: qboolean IsCzeroAndIsSkyCullAndIsD3D@[???] */
  uVar9 = l->filelen;
  psVar8 = (short *)(mod_base + l->fileofs);
  if (uVar9 != (uVar9 / 0x14) * 0x14) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar9 = uVar9 / 0x14;
  s = Hunk_AllocName(uVar9 * 0x6c,loadname);
  pmVar2 = loadmodel;
  loadmodel->numsurfaces = uVar9;
  uVar10 = 0;
  pmVar2->surfaces = s;
  if (uVar9 != 0) {
    do {
      while( true ) {
        iVar5 = (*LittleLong)(*(int32 *)(psVar8 + 2));
        s->firstedge = iVar5;
        sVar3 = (*LittleShort)(psVar8[4]);
        s->flags = 0;
        s->pdecals = (decal_t *)0x0;
        (s->displaylist).gl_displaylist = 0;
        (s->displaylist).rendermode = 0;
        (s->displaylist).scrolloffset = 0.0;
        s->numedges = (int)sVar3;
        (s->displaylist).renderDetailTexture = 0;
        sVar3 = (*LittleShort)(*psVar8);
        sVar4 = (*LittleShort)(psVar8[1]);
        if (sVar4 != 0) {
          s->flags = s->flags | 2;
        }
        pmVar2 = loadmodel;
        s->plane = loadmodel->planes + sVar3;
        pmVar1 = pmVar2->texinfo;
        sVar3 = (*LittleShort)(psVar8[5]);
        s->texinfo = pmVar1 + sVar3;
        CalcSurfaceExtents(s);
        s->styles[0] = (byte)psVar8[6];
        s->styles[1] = *(byte *)((int)psVar8 + 0xd);
        s->styles[2] = (byte)psVar8[7];
        s->styles[3] = *(byte *)((int)psVar8 + 0xf);
        iVar5 = (*LittleLong)(*(int32 *)(psVar8 + 8));
        if (iVar5 == -1) {
          pcVar7 = (color24_conflict *)0x0;
        }
        else {
          pcVar7 = (color24_conflict *)(&loadmodel->lightdata->r + iVar5);
        }
        s->samples = pcVar7;
        iVar6 = Q_strncmp(s->texinfo->texture->name,"sky",3);
        if (iVar6 != 0) break;
        s->flags = s->flags | 0x24;
LAB_001640c4:
        uVar10 = uVar10 + 1;
        psVar8 = psVar8 + 10;
        s = s + 1;
        if (uVar9 == uVar10) {
          return;
        }
      }
      iVar6 = Q_strncmp(s->texinfo->texture->name,"scroll",6);
      if (iVar6 == 0) {
LAB_001642b0:
        s->flags = s->flags | 0x20;
        goto LAB_001640c4;
      }
      pmVar1 = s->texinfo;
      __s1 = pmVar1->texture;
      if (((__s1->name[0] != '!') && (iVar6 = strncasecmp(__s1->name,"laser",5), iVar6 != 0)) &&
         (iVar6 = strncasecmp(__s1->name,"water",5), iVar6 != 0)) {
        if ((pmVar1->flags & 1) == 0) goto LAB_001640c4;
        goto LAB_001642b0;
      }
      s->flags = s->flags | 0x10;
      uVar10 = uVar10 + 1;
      psVar8 = psVar8 + 10;
      GL_SubdivideSurface(s);
      s = s + 1;
    } while (uVar9 != uVar10);
  }
  return;
}


// Mod_LoadLeafs  @ 00164670
void Mod_LoadLeafs(lump_t *l)

{
  int iVar1;
  model_t *pmVar2;
  short sVar3;
  mleaf_t *pmVar4;
  float fVar5;
  int32 iVar6;
  byte *pbVar7;
  uint uVar8;
  short *psVar9;
  short *psVar10;
  float *pfVar11;
  float *pfVar12;
  short *psVar13;
  uint local_24;
  
                    /* Unresolved local var: dleaf_t * in@[???]
                       Unresolved local var: mleaf_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int p@[???] */
  pbVar7 = mod_base;
  uVar8 = l->filelen;
  iVar1 = l->fileofs;
  if (uVar8 + (uVar8 / 0x1c) * 4 == uVar8 / 0x1c << 5) {
    uVar8 = uVar8 / 0x1c;
    pmVar4 = Hunk_AllocName(uVar8 * 0x3c,loadname);
    pmVar2 = loadmodel;
    loadmodel->numleafs = uVar8;
    pmVar2->leafs = pmVar4;
    if (uVar8 != 0) {
      local_24 = 0;
      pfVar11 = pmVar4->minmaxs;
      psVar13 = (short *)(pbVar7 + iVar1 + 8);
      do {
        psVar9 = psVar13;
        pfVar12 = pfVar11;
        do {
          psVar10 = psVar9 + 1;
          sVar3 = (*LittleShort)(*psVar9);
          *pfVar12 = (float)sVar3;
          sVar3 = (*LittleShort)(psVar9[3]);
          pfVar12[3] = (float)sVar3;
          psVar9 = psVar10;
          pfVar12 = pfVar12 + 1;
        } while (psVar10 != psVar13 + 3);
        fVar5 = (float)(*LittleLong)(*(int32 *)(psVar13 + -4));
        ((mleaf_t *)(pfVar11 + -2))->contents = (int)fVar5;
        pfVar11[9] = (float)(loadmodel->marksurfaces + (ushort)psVar13[6]);
        sVar3 = (*LittleShort)(psVar13[7]);
        pfVar11[10] = (float)(int)sVar3;
        iVar6 = (*LittleLong)(*(int32 *)(psVar13 + -2));
        if (iVar6 == -1) {
          pbVar7 = (byte *)0x0;
        }
        else {
          pbVar7 = loadmodel->visdata + iVar6;
        }
        pfVar11[7] = (float)pbVar7;
        pfVar11[8] = 0.0;
        local_24 = local_24 + 1;
        *(byte *)(pfVar11 + 0xc) = (byte)psVar13[8];
        *(byte *)((int)pfVar11 + 0x31) = *(byte *)((int)psVar13 + 0x11);
        *(byte *)((int)pfVar11 + 0x32) = (byte)psVar13[9];
        *(byte *)((int)pfVar11 + 0x33) = *(byte *)((int)psVar13 + 0x13);
        pfVar11 = pfVar11 + 0xf;
        psVar13 = psVar13 + 0xe;
      } while (uVar8 != local_24);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
}


// Mod_LoadLighting  @ 001635d0
void Mod_LoadLighting(lump_t *l)

{
  model_t *pmVar1;
  byte *pbVar2;
  color24 *pcVar3;
  
  pmVar1 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->lightdata = (color24 *)0x0;
    return;
  }
  pcVar3 = Hunk_AllocName(l->filelen,loadname);
  pbVar2 = mod_base;
  pmVar1->lightdata = pcVar3;
  Q_memcpy(loadmodel->lightdata,pbVar2 + l->fileofs,l->filelen);
  return;
}


// Mod_LoadMarksurfaces  @ 00164b00
void Mod_LoadMarksurfaces(lump_t *l)

{
  int iVar1;
  model_t *pmVar2;
  byte *pbVar3;
  short sVar4;
  msurface_t **ppmVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: short * in@[???]
                       Unresolved local var: msurface_t * * out@[???] */
  pbVar3 = mod_base;
  iVar1 = l->fileofs;
  if ((l->filelen & 1U) != 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar6 = (uint)l->filelen >> 1;
  ppmVar5 = Hunk_AllocName(uVar6 * 4,loadname);
  pmVar2 = loadmodel;
  loadmodel->nummarksurfaces = uVar6;
  uVar7 = 0;
  pmVar2->marksurfaces = ppmVar5;
  if (uVar6 != 0) {
    do {
      sVar4 = (*LittleShort)(*(short *)(pbVar3 + uVar7 * 2 + iVar1));
      if (loadmodel->numsurfaces <= (int)sVar4) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Mod_ParseMarksurfaces: bad surface number");
      }
      ppmVar5[uVar7] = loadmodel->surfaces + sVar4;
      uVar7 = uVar7 + 1;
    } while (uVar6 != uVar7);
  }
  return;
}


// Mod_LoadModel  @ 001665f0
model_t * __regparm3 Mod_LoadModel(model_t *mod,qboolean crash,qboolean trackCRC)

{
  int iVar1;
  FileHandle_t file;
  int32 *buffer;
  int32 iVar2;
  model_t *__src;
  qboolean qVar3;
  qboolean qVar4;
  int in_GS_OFFSET;
  uint local_1028;
  CRC32_t local_1024;
  char local_1020 [4095];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: uint * buf@[???]
                       Unresolved local var: char[4096] tmpName@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = COM_CheckParm("-steam");
  if ((iVar1 != 0) && (__src = mod, mod->name[0] == '/')) {
    do {
      __src = (model_t *)(__src->name + 1);
    } while (__src->name[0] == '/');
    strncpy(local_1020,(char *)__src,0xfff);
    local_21 = 0;
    strncpy(mod->name,local_1020,0x3f);
    mod->name[0x3f] = '\0';
  }
  file = FS_Open(mod->name,"rb");
  if (file == (FileHandle_t)0x0) {
LAB_001667c0:
    if ((crash != false) || (2.0 < developer.value)) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Mod_NumForName: %s not found",mod);
    }
    Con_Printf("Error: could not load file %s\n",mod);
    mod = (model_t *)0x0;
  }
  else {
    buffer = FS_GetReadBuffer(file,(int *)&local_1028);
    if (buffer == (int32 *)0x0) {
LAB_00166774:
      local_1028 = FS_Size(file);
      buffer = Hunk_TempAlloc(local_1028 + 1);
      FS_Read(buffer,local_1028,1,file);
      FS_Close(file);
      if (buffer == (int32 *)0x0) goto LAB_001667c0;
      file = (FileHandle_t)0x0;
    }
    else {
      iVar2 = (*LittleLong)(*buffer);
      if (iVar2 == 0x54534449) {
        FS_ReleaseReadBuffer(file,buffer);
        goto LAB_00166774;
      }
    }
                    /* Unresolved local var: mod_known_info_t * p@[???] */
    if ((trackCRC != false) &&
       (iVar1 = ((int)(mod[-0x9e46].name + 0x10) >> 3) * 0x397829cc,
       *(int *)((int)mod_known_info + iVar1) != 0)) {
                    /* Unresolved local var: CRC32_t currentCRC@[???] */
      CRC32_Init(&local_1024);
      CRC32_ProcessBuffer(&local_1024,buffer,local_1028);
      local_1024 = CRC32_Final(local_1024);
      if (*(int *)((int)mod_known_info + iVar1 + 4) == 0) {
                    /* Unresolved local var: qboolean badModel@[???] */
        *(CRC32_t *)((int)mod_known_info + iVar1 + 8) = local_1024;
        *(undefined4 *)((int)mod_known_info + iVar1 + 4) = 1;
        SetCStrikeFlags();
        qVar3 = IsGameSubscribed("czero");
        if ((((qVar3 == false) && (g_bIsCStrike != 0)) &&
            (qVar4 = IsCZPlayerModel(local_1024,mod->name), qVar4 != 0)) &&
           (cls.state != ca_dedicated)) {
          COM_ExplainDisconnection(true,"Cannot continue with altered model %s, disconnecting.",mod)
          ;
          CL_Disconnect();
          mod = (model_t *)0x0;
          goto LAB_00166743;
        }
      }
      else if (local_1024 != *(CRC32_t *)((int)mod_known_info + iVar1 + 8)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("%s has been modified since starting the engine.  Consider running system diagnostics to check for faulty hardware.\n"
                  ,mod);
      }
    }
    if (1.0 < developer.value) {
      Con_DPrintf("loading %s\n",mod);
    }
    COM_FileBase(mod->name,loadname);
    loadmodel = mod;
    mod->needload = false;
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
  }
LAB_00166743:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return mod;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Mod_LoadModel  @ 001669b0
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
  else if ((mod->needload == false) || (mod->needload == 3)) {
    return mod;
  }
  pmVar1 = Mod_LoadModel(mod,crash,trackCRC);
  return pmVar1;
}


// Mod_LoadNodes  @ 00164480
void Mod_LoadNodes(lump_t *l)

{
  mnode_t *parent;
  mnode_s *pmVar1;
  model_t *pmVar2;
  short sVar3;
  ushort uVar4;
  mnode_s *pmVar5;
  int32 iVar6;
  uint uVar7;
  mleaf_t *pmVar8;
  uint uVar9;
  int32 *piVar10;
  int32 *piVar11;
  int iVar12;
  int32 *piVar13;
  float *pfVar14;
  uint local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: dnode_t * in@[???]
                       Unresolved local var: mnode_t * out@[???] */
  uVar9 = l->filelen;
  piVar13 = (int32 *)(mod_base + l->fileofs);
  if (uVar9 != (uVar9 / 0x18) * 0x18) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar9 = uVar9 / 0x18;
  pmVar5 = Hunk_AllocName(uVar9 * 0x34,loadname);
  pmVar2 = loadmodel;
  loadmodel->nodes = pmVar5;
  pmVar2->numnodes = uVar9;
  if (uVar9 != 0) {
    local_24 = 0;
    do {
      piVar10 = piVar13 + 2;
      pfVar14 = pmVar5->minmaxs;
      do {
        piVar11 = (int32 *)((int)piVar10 + 2);
        sVar3 = (*LittleShort)((short)*piVar10);
        *pfVar14 = (float)sVar3;
        sVar3 = (*LittleShort)(*(short *)((int)piVar10 + 6));
        pfVar14[3] = (float)sVar3;
        piVar10 = piVar11;
        pfVar14 = pfVar14 + 1;
      } while ((int32 *)((int)piVar13 + 0xe) != piVar11);
      iVar12 = 0;
      iVar6 = (*LittleLong)(*piVar13);
      pmVar5->plane = loadmodel->planes + iVar6;
      uVar4 = (*LittleShort)((short)piVar13[5]);
      pmVar5->firstsurface = uVar4;
      uVar4 = (*LittleShort)(*(short *)((int)piVar13 + 0x16));
      pmVar5->numsurfaces = uVar4;
      do {
        sVar3 = (*LittleShort)(*(short *)((int)piVar13 + iVar12 * 2 + 4));
        pmVar2 = loadmodel;
        uVar7 = (uint)sVar3;
        if ((int)uVar7 < 0) {
          pmVar8 = loadmodel->leafs + ~uVar7;
        }
        else {
          pmVar8 = (mleaf_t *)(loadmodel->nodes + uVar7);
        }
        pmVar5->children[iVar12] = (mnode_s *)pmVar8;
        iVar12 = iVar12 + 1;
      } while (iVar12 != 2);
      local_24 = local_24 + 1;
      piVar13 = piVar13 + 6;
      pmVar5 = pmVar5 + 1;
    } while (uVar9 != local_24);
    pmVar5 = pmVar2->nodes;
  }
  iVar12 = pmVar5->contents;
  pmVar5->parent = (mnode_s *)0x0;
  while (-1 < iVar12) {
    parent = pmVar5->children[0];
    iVar12 = parent->contents;
    parent->parent = pmVar5;
    while (-1 < iVar12) {
      Mod_SetParent(parent->children[0],parent);
      pmVar1 = parent->children[1];
      pmVar1->parent = parent;
      parent = pmVar1;
      iVar12 = pmVar1->contents;
    }
    pmVar1 = pmVar5->children[1];
    iVar12 = pmVar1->contents;
    pmVar1->parent = pmVar5;
    pmVar5 = pmVar1;
  }
  return;
}


// Mod_LoadPlanes  @ 00164c80
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
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
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


// Mod_LoadSpriteFrame  @ 00165f70
void * Mod_LoadSpriteFrame(void *pin,mspriteframe_t **ppframe,int framenum)

{
  int32 width;
  int32 height;
  mspriteframe_t *dest;
  int32 iVar1;
  int32 iVar2;
  uint iType;
  int iVar3;
  int in_GS_OFFSET;
  char local_420 [256];
  byte local_320 [768];
  int local_20;
  
                    /* Unresolved local var: dspriteframe_t * pinframe@[???]
                       Unresolved local var: mspriteframe_t * pspriteframe@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int[2] origin@[???]
                       Unresolved local var: int textureType@[???]
                       Unresolved local var: byte * pdata@[???]
                       Unresolved local var: byte * ppal@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: byte[768] bPal@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memcpy(local_320,pspritepal,0x300);
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
  __snprintf_chk(local_420,0x100,1,0x100,"%s_%i",loadmodel,framenum);
  if (gSpriteTextureFormat == 2) {
    iType = 3;
  }
  else if (gSpriteTextureFormat < 3) {
    iType = 0;
  }
  else {
    iType = (uint)(gSpriteTextureFormat == 3);
  }
  if (gSpriteMipMap == false) {
    iVar3 = GL_LoadTexture(local_420,GLT_HUDSPRITE,width,height,(byte *)((int)pin + 0x10),0,iType,
                           local_320);
    dest->gl_texturenum = iVar3;
  }
  else {
    iVar3 = GL_LoadTexture(local_420,GLT_SPRITE,width,height,(byte *)((int)pin + 0x10),gSpriteMipMap
                           ,iType,local_320);
    dest->gl_texturenum = iVar3;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (void *)((int)pin + width * height + 0x10);
}


// Mod_LoadSpriteGroup  @ 00166290
void * Mod_LoadSpriteGroup(void *pin,mspriteframe_t **ppframe,int framenum)

{
  int32 iVar1;
  mspriteframe_t *pmVar2;
  void *pvVar3;
  int iVar4;
  float *ppframe_00;
  int iVar5;
  void *pin_00;
  longdouble lVar6;
  
                    /* Unresolved local var: dspritegroup_t * pingroup@[???]
                       Unresolved local var: mspritegroup_t * pspritegroup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: dspriteinterval_t * pin_intervals@[???]
                       Unresolved local var: float * poutintervals@[???]
                       Unresolved local var: void * ptemp@[???] */
  pin_00 = (void *)((int)pin + 4);
  iVar1 = (*LittleLong)(*(int32 *)pin);
  iVar5 = iVar1 * 4;
  pmVar2 = Hunk_AllocName(iVar5 + 8,loadname);
  pmVar2->width = iVar1;
  *ppframe = pmVar2;
  pvVar3 = Hunk_AllocName(iVar5,loadname);
  pmVar2->height = (int)pvVar3;
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      lVar6 = (longdouble)(*LittleFloat)(*(float *)((int)pin + iVar4 * 4 + 4));
      *(float *)((int)pvVar3 + iVar4 * 4) = (float)lVar6;
      if (lVar6 <= (longdouble)0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Mod_LoadSpriteGroup: interval<=0");
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
    pin_00 = (void *)((int)pin_00 + iVar5);
    ppframe_00 = &pmVar2->up;
    iVar5 = framenum * 100;
    do {
      iVar4 = iVar5 + 1;
      pin_00 = Mod_LoadSpriteFrame(pin_00,(mspriteframe_t **)ppframe_00,iVar5);
      ppframe_00 = ppframe_00 + 1;
      iVar5 = iVar4;
    } while (iVar1 + framenum * 100 != iVar4);
  }
  return pin_00;
}


// Mod_LoadSpriteModel  @ 001663b0
void Mod_LoadSpriteModel(model_t *mod,void *buffer)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  undefined2 *puVar4;
  int32 iVar5;
  synctype_t sVar6;
  mspriteframe_t *pmVar7;
  int32 *piVar8;
  int iVar9;
  mspriteframe_t **ppframe;
  longdouble lVar10;
  
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
                    /* WARNING: Subroutine does not return */
    Sys_Error("%s has wrong version number (%i should be %i)",mod,iVar3,2);
  }
  iVar3 = (*LittleLong)(*(int32 *)((int)buffer + 0x1c));
  iVar2 = *(short *)((int)buffer + 0x28) * 3;
  iVar9 = iVar2 + 2;
  puVar4 = Hunk_AllocName(iVar3 * 8 + 0x1c + iVar9,loadname);
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
  lVar10 = (longdouble)(*LittleFloat)(*(float *)((int)buffer + 0x20));
  *(float *)(puVar4 + 10) = (float)lVar10;
  sVar6 = (*LittleLong)(*(int32 *)((int)buffer + 0x24));
  mod->synctype = sVar6;
  iVar1 = *(int *)(puVar4 + 2);
  *(int32 *)(puVar4 + 6) = iVar3;
  mod->mins[1] = (float)-(iVar1 / 2);
  mod->mins[0] = (float)-(iVar1 / 2);
  iVar1 = *(int *)(puVar4 + 2);
  mod->maxs[1] = (float)(iVar1 / 2);
  mod->maxs[0] = (float)(iVar1 / 2);
  mod->mins[2] = (float)-(*(int *)(puVar4 + 4) / 2);
  mod->maxs[2] = (float)(*(int *)(puVar4 + 4) / 2);
  *(int32 *)(puVar4 + 8) = iVar3 * 8 + 0x1e;
  pspritepal = (byte *)(puVar4 + iVar3 * 4 + 0xe);
  Q_memcpy(pspritepal,(void *)((int)buffer + 0x2a),iVar9);
  if (iVar3 < 1) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Mod_LoadSpriteModel: Invalid # of frames: %d\n",iVar3);
  }
  piVar8 = (int32 *)((int)buffer + iVar2 + 0x2a);
  ppframe = (mspriteframe_t **)(puVar4 + 0x10);
  iVar9 = 0;
  mod->numframes = iVar3;
  mod->flags = 0;
  do {
    while( true ) {
      pmVar7 = (mspriteframe_t *)(*LittleLong)(*piVar8);
      ppframe[-1] = pmVar7;
      if (pmVar7 == (mspriteframe_t *)0x0) break;
      piVar8 = Mod_LoadSpriteGroup(piVar8 + 1,ppframe,iVar9);
      iVar9 = iVar9 + 1;
      ppframe = ppframe + 2;
      if (iVar3 == iVar9) goto LAB_001665af;
    }
                    /* Unresolved local var: spriteframetype_t frametype@[???] */
    piVar8 = Mod_LoadSpriteFrame(piVar8 + 1,ppframe,iVar9);
    iVar9 = iVar9 + 1;
    ppframe = ppframe + 2;
  } while (iVar3 != iVar9);
LAB_001665af:
  mod->type = mod_sprite;
  return;
}


// Mod_LoadStudioModel  @ 000c46e0
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
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte * pin@[???]
                       Unresolved local var: byte * pout@[???]
                       Unresolved local var: studiohdr_t * phdr@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int version@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
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
    if ((*(int *)((int)buffer + 0xb8) != 0) && (0 < *(int *)((int)buffer + 0xb4))) {
      iVar5 = 0;
      iVar6 = *(int *)((int)buffer + 0xb8) + (int)buffer;
      do {
        iVar4 = *(int *)(iVar6 + 0x48);
        iVar1 = *(int *)(iVar6 + 0x44);
        iVar2 = *(int *)(iVar6 + 0x4c);
        __snprintf_chk(local_120,0x100,1,0x100,&LAB_0026291c,mod,iVar6);
        iVar5 = iVar5 + 1;
        iVar4 = GL_LoadTexture(local_120,GLT_STUDIO,*(int *)(iVar6 + 0x44),*(int *)(iVar6 + 0x48),
                               (byte *)(*(int *)(iVar6 + 0x4c) + (int)buffer),
                               (uint)(((byte)(*(uint *)(iVar6 + 0x40) >> 3) ^ 1) & 1),
                               (uint)((*(uint *)(iVar6 + 0x40) & 0x40) != 0),
                               (byte *)(iVar1 * iVar4 + iVar2 + (int)buffer));
        *(int *)(iVar6 + 0x4c) = iVar4;
        iVar6 = iVar6 + 0x50;
      } while (iVar5 < *(int *)((int)buffer + 0xb4));
    }
    Q_memcpy(dest,buffer,size);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Mod_LoadSubmodels  @ 001638b0
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
  pfVar5 = (float *)(mod_base + l->fileofs);
  if ((l->filelen & 0x3fU) != 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar2 = (uint)l->filelen >> 6;
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


// Mod_LoadSurfedges  @ 00164be0
void Mod_LoadSurfedges(lump_t *l)

{
  int iVar1;
  model_t *pmVar2;
  byte *pbVar3;
  int *piVar4;
  int32 iVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int * in@[???]
                       Unresolved local var: int * out@[???] */
  pbVar3 = mod_base;
  iVar1 = l->fileofs;
  if ((l->filelen & 3U) != 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar6 = (uint)l->filelen >> 2;
  uVar7 = 0;
  piVar4 = Hunk_AllocName(uVar6 * 4,loadname);
  pmVar2 = loadmodel;
  loadmodel->surfedges = piVar4;
  pmVar2->numsurfedges = uVar6;
  if (uVar6 != 0) {
    do {
      iVar5 = (*LittleLong)(*(int32 *)(pbVar3 + uVar7 * 4 + iVar1));
      piVar4[uVar7] = iVar5;
      uVar7 = uVar7 + 1;
    } while (uVar6 != uVar7);
  }
  return;
}


// Mod_LoadTexinfo  @ 00163ab0
void Mod_LoadTexinfo(lump_t *l)

{
  texture_t *ptVar1;
  model_t *pmVar2;
  mtexinfo_t *v;
  int32 iVar3;
  int32 iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  longdouble lVar9;
  float fVar10;
  float fVar11;
  
                    /* Unresolved local var: texinfo_t * in@[???]
                       Unresolved local var: mtexinfo_t * out@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int miptex@[???]
                       Unresolved local var: float len1@[???]
                       Unresolved local var: float len2@[???] */
  uVar6 = l->filelen;
  pbVar5 = mod_base + l->fileofs;
  if (uVar6 != (uVar6 / 0x28) * 0x28) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
  }
  uVar6 = uVar6 / 0x28;
  v = Hunk_AllocName(uVar6 * 0x2c,loadname);
  pmVar2 = loadmodel;
  loadmodel->numtexinfo = uVar6;
  uVar8 = 0;
  pmVar2->texinfo = v;
  if (uVar6 != 0) {
    do {
      iVar7 = 0;
      do {
        lVar9 = (longdouble)(*LittleFloat)(*(float *)(pbVar5 + iVar7 * 4));
        v->vecs[0][iVar7] = (float)lVar9;
        iVar7 = iVar7 + 1;
      } while (iVar7 != 8);
      fVar10 = Length((vec_t *)v);
      fVar11 = Length(v->vecs[1]);
      fVar10 = (fVar11 + fVar10) * 0.5;
      if (0.32 <= fVar10) {
        if (0.49 <= fVar10) {
          fVar11 = 2.0;
          if (0.99 <= fVar10) {
            fVar11 = 1.0;
          }
          v->mipadjust = fVar11;
        }
        else {
          v->mipadjust = 3.0;
        }
      }
      else {
        v->mipadjust = 4.0;
      }
      iVar3 = (*LittleLong)(*(int32 *)(pbVar5 + 0x20));
      iVar4 = (*LittleLong)(*(int32 *)(pbVar5 + 0x24));
      v->flags = iVar4;
      if (loadmodel->textures == (texture_t **)0x0) {
LAB_00163c08:
        ptVar1 = r_notexture_mip;
        v->flags = 0;
        v->texture = ptVar1;
      }
      else {
        if (loadmodel->numtextures <= iVar3) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("miptex >= loadmodel->numtextures");
        }
        ptVar1 = loadmodel->textures[iVar3];
        v->texture = ptVar1;
        if (ptVar1 == (texture_t *)0x0) goto LAB_00163c08;
      }
      uVar8 = uVar8 + 1;
      pbVar5 = pbVar5 + 0x28;
      v = v + 1;
    } while (uVar6 != uVar8);
  }
  return;
}


// Mod_LoadTextures  @ 00162310
void Mod_LoadTextures(lump_t *l)

{
  int iVar1;
  ushort uVar2;
  char *pcVar3;
  bool bVar4;
  model_t *pmVar5;
  int iVar6;
  int *piVar7;
  int32 iVar8;
  texture_t **pptVar9;
  int iVar10;
  texture_t *ptVar11;
  uint uVar12;
  int iVar13;
  void *pvVar14;
  byte *name;
  int32 *piVar15;
  int32 *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int in_GS_OFFSET;
  double dVar20;
  double dVar21;
  int iStack_553e0;
  byte *pbStack_553cc;
  int32 *piStack_553c8;
  int iStack_553c4;
  int aiStack_553bc [10];
  int aiStack_55394 [10];
  byte abStack_5536a [349018];
  
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
                       Unresolved local var: byte[349002] dtexdata@[???]
                       Unresolved local var: byte * pPal@[???]
                       Unresolved local var: qboolean wads_parsed@[???]
                       Unresolved local var: double starttime@[???]
                       Unresolved local var: uchar * rawtex@[???]
                       Unresolved local var: qboolean IsCzeroAndIsSkyCullAndIsD3D@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  dVar20 = Sys_FloatTime();
  if (tested == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * s@[???] */
    tested = 1;
    iVar17 = COM_CheckParm("-ad");
    if (((iVar17 != 0) && (pcVar3 = com_argv[iVar17 + 1], pcVar3 != (char *)0x0)) &&
       (*pcVar3 != '\0')) {
      snprintf(Mod_AdInit::filename,0x104,"%s",pcVar3);
      uVar12 = FS_FileSize(Mod_AdInit::filename);
      if ((int)uVar12 < 1) {
        Con_Printf("No -ad file specified, skipping\n");
      }
      else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * s@[???] */
        Draw_CacheWadInit(Mod_AdInit::filename,0x10,&ad_wad);
        Draw_CacheWadHandler(&ad_wad,Draw_MiptexTexture,0x20);
        ad_enabled = 1;
      }
    }
  }
  if (l->filelen == 0) {
    loadmodel->textures = (texture_t **)0x0;
  }
  else {
    piVar7 = (int *)(mod_base + l->fileofs);
    iVar8 = (*LittleLong)(*piVar7);
    *piVar7 = iVar8;
    pmVar5 = loadmodel;
    loadmodel->numtextures = iVar8;
    pptVar9 = Hunk_AllocName(*piVar7 << 2,loadname);
    pmVar5->textures = pptVar9;
    if (0 < *piVar7) {
      iVar17 = 0;
      bVar4 = false;
      do {
        iVar8 = (*LittleLong)(piVar7[iVar17 + 1]);
        piVar7[iVar17 + 1] = iVar8;
        if (iVar8 != -1) {
          name = (byte *)((int)piVar7 + iVar8);
          if ((r_wadtextures.value != 0.0) ||
             (iVar8 = (*LittleLong)(*(int32 *)(name + 0x18)), iVar8 == 0)) {
            if (!bVar4) {
              TEX_InitFromWad(wadpath);
              TEX_AddAnimatingTextures();
            }
            iVar10 = TEX_LoadLump((char *)name,abStack_5536a,0x5534a);
            if (iVar10 == 0) {
              piVar7[iVar17 + 1] = -1;
              bVar4 = true;
              goto LAB_00162444;
            }
            bVar4 = true;
            name = abStack_5536a;
          }
          iVar8 = (*LittleLong)(*(int32 *)(name + 0x10));
          *(int32 *)(name + 0x10) = iVar8;
          iVar8 = (*LittleLong)(*(int32 *)(name + 0x14));
          *(int32 *)(name + 0x14) = iVar8;
          piStack_553c8 = (int32 *)(name + 0x28);
          piVar15 = (int32 *)(name + 0x18);
          do {
            piVar16 = piVar15 + 1;
            iVar8 = (*LittleLong)(*piVar15);
            *piVar15 = iVar8;
            piVar15 = piVar16;
          } while (piStack_553c8 != piVar16);
          if (((*(uint *)(name + 0x10) & 0xf) != 0) || ((*(uint *)(name + 0x14) & 0xf) != 0)) {
                    /* WARNING: Subroutine does not return */
            Sys_Error("Texture %s is not 16 aligned",name);
          }
          iVar10 = (*(uint *)(name + 0x14) * *(uint *)(name + 0x10) >> 6) * 0x55;
          uVar2 = *(ushort *)(name + iVar10 + 0x28);
          ptVar11 = Hunk_AllocName((uint)uVar2 * 3 + 0x48,loadname);
          loadmodel->textures[iVar17] = ptVar11;
          Q_memcpy(ptVar11,name,0x10);
          ptVar11->width = *(uint *)(name + 0x10);
          ptVar11->height = *(uint *)(name + 0x14);
          pbStack_553cc = name + iVar10 + 0x2a;
          ptVar11->pPal = (byte *)(ptVar11 + 1);
          Q_memcpy(ptVar11 + 1,pbStack_553cc,(uint)uVar2 * 3);
                    /* Unresolved local var: texture_t * tex@[???] */
          if (((ad_enabled != 0) && (iVar18 = Q_stricmp(ptVar11->name,"DEFAULT"), iVar18 == 0)) &&
             (tested != 0)) {
                    /* Unresolved local var: texture_t * tex@[???] */
            iVar18 = Draw_CacheIndex(&ad_wad,"img");
            pvVar14 = Draw_CacheGet(&ad_wad,iVar18);
            if (pvVar14 != (void *)0x0) {
              piStack_553c8 = (int32 *)((int)pvVar14 + 0x48);
              pbStack_553cc = (byte *)((int)pvVar14 + iVar10 + 0x4a);
            }
          }
          iVar10 = Q_strncmp((char *)name,"sky",3);
          if (iVar10 == 0) {
            R_InitSky();
            iVar10 = ptVar11->gl_texturenum;
          }
          else {
            texture_mode = 0x2701;
            iVar10 = GL_LoadTexture((char *)name,GLT_WORLD,ptVar11->width,ptVar11->height,
                                    (byte *)piStack_553c8,1,(uint)(*name == '{'),pbStack_553cc);
            texture_mode = 0x2601;
            ptVar11->gl_texturenum = iVar10;
          }
          DT_LoadDetailTexture((char *)name,iVar10);
        }
LAB_00162444:
        iVar10 = *piVar7;
        iVar17 = iVar17 + 1;
      } while (iVar17 < iVar10);
      if (bVar4) {
        TEX_CleanupWadInfo();
        iVar10 = *piVar7;
      }
      if (0 < iVar10) {
        iVar17 = 0;
        do {
          ptVar11 = loadmodel->textures[iVar17];
          if (((ptVar11 != (texture_t *)0x0) && ((ptVar11->name[0] - 0x2bU & 0xfd) == 0)) &&
             (ptVar11->anim_next == (texture_s *)0x0)) {
            Q_memset(aiStack_553bc,0,0x28);
            Q_memset(aiStack_55394,0,0x28);
            iStack_553c4 = (int)ptVar11->name[1];
            if (iStack_553c4 - 0x61U < 0x1a) {
              iStack_553c4 = iStack_553c4 + -0x20;
            }
            if (iStack_553c4 - 0x30U < 10) {
              aiStack_553bc[iStack_553c4 - 0x30U] = (int)ptVar11;
              iStack_553c4 = iStack_553c4 + -0x2f;
              if (iVar17 + 1 < *piVar7) {
                iStack_553e0 = 0;
LAB_00162802:
                iVar19 = iVar17 + 1;
                iVar18 = iVar19 * 4;
                do {
                  pcVar3 = *(char **)((int)loadmodel->textures + iVar18);
                  iVar10 = iStack_553e0;
                  iVar6 = iStack_553c4;
                  if (((pcVar3 != (char *)0x0) && ((*pcVar3 - 0x2bU & 0xfd) == 0)) &&
                     (iVar13 = Q_strcmp(pcVar3 + 2,ptVar11->name + 2), iVar13 == 0)) {
                    iVar13 = (int)pcVar3[1];
                    if (iVar13 - 0x61U < 0x1a) {
                      iVar13 = iVar13 + -0x20;
                    }
                    uVar12 = iVar13 - 0x30;
                    if (uVar12 < 10) {
                      aiStack_553bc[uVar12] = (int)pcVar3;
                      iVar6 = iVar13 + -0x2f;
                      if ((int)uVar12 < iStack_553c4) {
                        iVar6 = iStack_553c4;
                      }
                    }
                    else {
                      uVar12 = iVar13 - 0x41;
                      if (9 < uVar12) {
                    /* WARNING: Subroutine does not return */
                        Sys_Error("Bad animating texture %s",ptVar11);
                      }
                      aiStack_55394[uVar12] = (int)pcVar3;
                      iVar10 = iVar13 + -0x40;
                      if ((int)uVar12 < iStack_553e0) {
                        iVar10 = iStack_553e0;
                      }
                    }
                  }
                  iStack_553c4 = iVar6;
                  iStack_553e0 = iVar10;
                  iVar10 = *piVar7;
                  iVar19 = iVar19 + 1;
                  iVar18 = iVar18 + 4;
                } while (iVar19 < iVar10);
                if (iStack_553c4 < 1) {
                  if (iStack_553e0 == 0) goto LAB_0016249e;
                  goto LAB_00162ee0;
                }
              }
              else {
                if (iStack_553c4 < 1) break;
                iStack_553e0 = 0;
              }
              if (aiStack_553bc[0] == 0) {
                    /* WARNING: Subroutine does not return */
                Sys_Error("Missing frame %i of %s",0,ptVar11);
              }
              *(int *)(aiStack_553bc[0] + 0x20) = iStack_553c4;
              *(undefined4 *)(aiStack_553bc[0] + 0x24) = 0;
              *(undefined4 *)(aiStack_553bc[0] + 0x28) = 1;
              *(int *)(aiStack_553bc[0] + 0x2c) = aiStack_553bc[(int)(1 % (longlong)iStack_553c4)];
              if (iStack_553e0 != 0) {
                *(int *)(aiStack_553bc[0] + 0x30) = aiStack_55394[0];
                if (iStack_553c4 != 1) {
                  if (aiStack_553bc[1] == 0) goto LAB_0016335d;
                  *(int *)(aiStack_553bc[1] + 0x20) = iStack_553c4;
                  *(undefined4 *)(aiStack_553bc[1] + 0x24) = 1;
                  *(undefined4 *)(aiStack_553bc[1] + 0x28) = 2;
                  *(int *)(aiStack_553bc[1] + 0x2c) =
                       aiStack_553bc[(int)(2 % (longlong)iStack_553c4)];
                  *(int *)(aiStack_553bc[1] + 0x30) = aiStack_55394[0];
                  if (iStack_553c4 != 2) {
                    if (aiStack_553bc[2] == 0) goto LAB_0016340b;
                    *(int *)(aiStack_553bc[2] + 0x20) = iStack_553c4;
                    *(undefined4 *)(aiStack_553bc[2] + 0x24) = 2;
                    *(undefined4 *)(aiStack_553bc[2] + 0x28) = 3;
                    *(int *)(aiStack_553bc[2] + 0x2c) =
                         aiStack_553bc[(int)(3 % (longlong)iStack_553c4)];
                    *(int *)(aiStack_553bc[2] + 0x30) = aiStack_55394[0];
                    if (iStack_553c4 != 3) {
                      if (aiStack_553bc[3] == 0) goto LAB_001633b4;
                      *(int *)(aiStack_553bc[3] + 0x20) = iStack_553c4;
                      *(undefined4 *)(aiStack_553bc[3] + 0x24) = 3;
                      *(undefined4 *)(aiStack_553bc[3] + 0x28) = 4;
                      *(int *)(aiStack_553bc[3] + 0x2c) =
                           aiStack_553bc[(int)(4 % (longlong)iStack_553c4)];
                      *(int *)(aiStack_553bc[3] + 0x30) = aiStack_55394[0];
                      if (iStack_553c4 != 4) {
                        if (aiStack_553bc[4] == 0) goto LAB_00163304;
                        *(int *)(aiStack_553bc[4] + 0x20) = iStack_553c4;
                        *(undefined4 *)(aiStack_553bc[4] + 0x24) = 4;
                        *(undefined4 *)(aiStack_553bc[4] + 0x28) = 5;
                        *(int *)(aiStack_553bc[4] + 0x2c) =
                             aiStack_553bc[(int)(5 % (longlong)iStack_553c4)];
                        *(int *)(aiStack_553bc[4] + 0x30) = aiStack_55394[0];
                        if (iStack_553c4 != 5) {
                          if (aiStack_553bc[5] == 0) goto LAB_001632ad;
                          *(int *)(aiStack_553bc[5] + 0x20) = iStack_553c4;
                          *(undefined4 *)(aiStack_553bc[5] + 0x24) = 5;
                          *(undefined4 *)(aiStack_553bc[5] + 0x28) = 6;
                          *(int *)(aiStack_553bc[5] + 0x2c) =
                               aiStack_553bc[(int)(6 % (longlong)iStack_553c4)];
                          *(int *)(aiStack_553bc[5] + 0x30) = aiStack_55394[0];
                          if (iStack_553c4 != 6) {
                            if (aiStack_553bc[6] == 0) goto LAB_00163256;
                            *(int *)(aiStack_553bc[6] + 0x20) = iStack_553c4;
                            *(undefined4 *)(aiStack_553bc[6] + 0x24) = 6;
                            *(undefined4 *)(aiStack_553bc[6] + 0x28) = 7;
                            *(int *)(aiStack_553bc[6] + 0x2c) =
                                 aiStack_553bc[(int)(7 % (longlong)iStack_553c4)];
                            *(int *)(aiStack_553bc[6] + 0x30) = aiStack_55394[0];
                            if (iStack_553c4 != 7) {
                              if (aiStack_553bc[7] == 0) goto LAB_001631fd;
                              *(int *)(aiStack_553bc[7] + 0x20) = iStack_553c4;
                              *(undefined4 *)(aiStack_553bc[7] + 0x24) = 7;
                              *(undefined4 *)(aiStack_553bc[7] + 0x28) = 8;
                              *(int *)(aiStack_553bc[7] + 0x2c) =
                                   aiStack_553bc[(int)(8 % (longlong)iStack_553c4)];
                              *(int *)(aiStack_553bc[7] + 0x30) = aiStack_55394[0];
                              if (iStack_553c4 != 8) {
                                if (aiStack_553bc[8] == 0) goto LAB_001631a6;
                                *(int *)(aiStack_553bc[8] + 0x20) = iStack_553c4;
                                *(undefined4 *)(aiStack_553bc[8] + 0x24) = 8;
                                *(undefined4 *)(aiStack_553bc[8] + 0x28) = 9;
                                *(int *)(aiStack_553bc[8] + 0x2c) =
                                     aiStack_553bc[(int)(9 % (longlong)iStack_553c4)];
                                *(int *)(aiStack_553bc[8] + 0x30) = aiStack_55394[0];
                                if (iStack_553c4 != 9) {
                                  if (aiStack_553bc[9] == 0) goto LAB_0016314d;
                                  *(int *)(aiStack_553bc[9] + 0x20) = iStack_553c4;
                                  *(undefined4 *)(aiStack_553bc[9] + 0x24) = 9;
                                  *(undefined4 *)(aiStack_553bc[9] + 0x28) = 10;
                                  *(int *)(aiStack_553bc[9] + 0x2c) =
                                       aiStack_553bc[(int)(10 % (longlong)iStack_553c4)];
                                  iStack_553c4 = 10;
                                  *(int *)(aiStack_553bc[9] + 0x30) = aiStack_55394[0];
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                if (aiStack_55394[0] == 0) goto LAB_00162ba0;
                *(undefined4 *)(aiStack_55394[0] + 0x24) = 0;
                *(undefined4 *)(aiStack_55394[0] + 0x28) = 1;
                *(int *)(aiStack_55394[0] + 0x20) = iStack_553e0;
                *(int *)(aiStack_55394[0] + 0x2c) = aiStack_55394[(int)(1 % (longlong)iStack_553e0)]
                ;
LAB_00162f1c:
                *(int *)(aiStack_55394[0] + 0x30) = aiStack_553bc[0];
                goto LAB_00162be8;
              }
              if (iStack_553c4 != 1) {
                if (aiStack_553bc[1] == 0) {
LAB_0016335d:
                    /* WARNING: Subroutine does not return */
                  Sys_Error("Missing frame %i of %s",1,ptVar11);
                }
                *(int *)(aiStack_553bc[1] + 0x20) = iStack_553c4;
                *(undefined4 *)(aiStack_553bc[1] + 0x24) = 1;
                *(undefined4 *)(aiStack_553bc[1] + 0x28) = 2;
                *(int *)(aiStack_553bc[1] + 0x2c) = aiStack_553bc[(int)(2 % (longlong)iStack_553c4)]
                ;
                if (iStack_553c4 != 2) {
                  if (aiStack_553bc[2] == 0) {
LAB_0016340b:
                    /* WARNING: Subroutine does not return */
                    Sys_Error("Missing frame %i of %s",2,ptVar11);
                  }
                  *(int *)(aiStack_553bc[2] + 0x20) = iStack_553c4;
                  *(undefined4 *)(aiStack_553bc[2] + 0x24) = 2;
                  *(undefined4 *)(aiStack_553bc[2] + 0x28) = 3;
                  *(int *)(aiStack_553bc[2] + 0x2c) =
                       aiStack_553bc[(int)(3 % (longlong)iStack_553c4)];
                  if (iStack_553c4 != 3) {
                    if (aiStack_553bc[3] == 0) {
LAB_001633b4:
                    /* WARNING: Subroutine does not return */
                      Sys_Error("Missing frame %i of %s",3,ptVar11);
                    }
                    *(int *)(aiStack_553bc[3] + 0x20) = iStack_553c4;
                    *(undefined4 *)(aiStack_553bc[3] + 0x24) = 3;
                    *(undefined4 *)(aiStack_553bc[3] + 0x28) = 4;
                    *(int *)(aiStack_553bc[3] + 0x2c) =
                         aiStack_553bc[(int)(4 % (longlong)iStack_553c4)];
                    if (iStack_553c4 != 4) {
                      if (aiStack_553bc[4] == 0) {
LAB_00163304:
                    /* WARNING: Subroutine does not return */
                        Sys_Error("Missing frame %i of %s",4,ptVar11);
                      }
                      *(int *)(aiStack_553bc[4] + 0x20) = iStack_553c4;
                      *(undefined4 *)(aiStack_553bc[4] + 0x24) = 4;
                      *(undefined4 *)(aiStack_553bc[4] + 0x28) = 5;
                      *(int *)(aiStack_553bc[4] + 0x2c) =
                           aiStack_553bc[(int)(5 % (longlong)iStack_553c4)];
                      if (iStack_553c4 != 5) {
                        if (aiStack_553bc[5] == 0) {
LAB_001632ad:
                    /* WARNING: Subroutine does not return */
                          Sys_Error("Missing frame %i of %s",5,ptVar11);
                        }
                        *(int *)(aiStack_553bc[5] + 0x20) = iStack_553c4;
                        *(undefined4 *)(aiStack_553bc[5] + 0x24) = 5;
                        *(undefined4 *)(aiStack_553bc[5] + 0x28) = 6;
                        *(int *)(aiStack_553bc[5] + 0x2c) =
                             aiStack_553bc[(int)(6 % (longlong)iStack_553c4)];
                        if (iStack_553c4 != 6) {
                          if (aiStack_553bc[6] == 0) {
LAB_00163256:
                    /* WARNING: Subroutine does not return */
                            Sys_Error("Missing frame %i of %s",6,ptVar11);
                          }
                          *(int *)(aiStack_553bc[6] + 0x20) = iStack_553c4;
                          *(undefined4 *)(aiStack_553bc[6] + 0x24) = 6;
                          *(undefined4 *)(aiStack_553bc[6] + 0x28) = 7;
                          *(int *)(aiStack_553bc[6] + 0x2c) =
                               aiStack_553bc[(int)(7 % (longlong)iStack_553c4)];
                          if (iStack_553c4 != 7) {
                            if (aiStack_553bc[7] == 0) {
LAB_001631fd:
                    /* WARNING: Subroutine does not return */
                              Sys_Error("Missing frame %i of %s",7,ptVar11);
                            }
                            *(int *)(aiStack_553bc[7] + 0x20) = iStack_553c4;
                            *(undefined4 *)(aiStack_553bc[7] + 0x24) = 7;
                            *(undefined4 *)(aiStack_553bc[7] + 0x28) = 8;
                            *(int *)(aiStack_553bc[7] + 0x2c) =
                                 aiStack_553bc[(int)(8 % (longlong)iStack_553c4)];
                            if (iStack_553c4 != 8) {
                              if (aiStack_553bc[8] == 0) {
LAB_001631a6:
                    /* WARNING: Subroutine does not return */
                                Sys_Error("Missing frame %i of %s",8,ptVar11);
                              }
                              *(int *)(aiStack_553bc[8] + 0x20) = iStack_553c4;
                              *(undefined4 *)(aiStack_553bc[8] + 0x24) = 8;
                              *(undefined4 *)(aiStack_553bc[8] + 0x28) = 9;
                              *(int *)(aiStack_553bc[8] + 0x2c) =
                                   aiStack_553bc[(int)(9 % (longlong)iStack_553c4)];
                              if (iStack_553c4 != 9) {
                                if (aiStack_553bc[9] == 0) {
LAB_0016314d:
                    /* WARNING: Subroutine does not return */
                                  Sys_Error("Missing frame %i of %s",9,ptVar11);
                                }
                                *(int *)(aiStack_553bc[9] + 0x20) = iStack_553c4;
                                *(undefined4 *)(aiStack_553bc[9] + 0x24) = 9;
                                *(undefined4 *)(aiStack_553bc[9] + 0x28) = 10;
                                *(int *)(aiStack_553bc[9] + 0x2c) =
                                     aiStack_553bc[(int)(10 % (longlong)iStack_553c4)];
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
            else {
              if (9 < iStack_553c4 - 0x41U) {
                    /* WARNING: Subroutine does not return */
                Sys_Error("Bad animating texture %s",ptVar11);
              }
              aiStack_55394[iStack_553c4 - 0x41U] = (int)ptVar11;
              iStack_553e0 = iStack_553c4 + -0x40;
              iStack_553c4 = 0;
              if (iVar17 + 1 < *piVar7) goto LAB_00162802;
              iStack_553c4 = 0;
LAB_00162ee0:
              if (aiStack_55394[0] == 0) {
LAB_00162ba0:
                    /* WARNING: Subroutine does not return */
                Sys_Error("Missing frame %i of %s",0,ptVar11);
              }
              *(undefined4 *)(aiStack_55394[0] + 0x24) = 0;
              *(undefined4 *)(aiStack_55394[0] + 0x28) = 1;
              *(int *)(aiStack_55394[0] + 0x20) = iStack_553e0;
              *(int *)(aiStack_55394[0] + 0x2c) = aiStack_55394[(int)(1 % (longlong)iStack_553e0)];
              if (iStack_553c4 != 0) goto LAB_00162f1c;
LAB_00162be8:
              if (iStack_553e0 != 1) {
                if (aiStack_55394[1] == 0) {
                    /* WARNING: Subroutine does not return */
                  Sys_Error("Missing frame %i of %s",1,ptVar11);
                }
                *(undefined4 *)(aiStack_55394[1] + 0x24) = 1;
                *(undefined4 *)(aiStack_55394[1] + 0x28) = 2;
                *(int *)(aiStack_55394[1] + 0x20) = iStack_553e0;
                *(int *)(aiStack_55394[1] + 0x2c) = aiStack_55394[(int)(2 % (longlong)iStack_553e0)]
                ;
                if (iStack_553c4 != 0) {
                  *(int *)(aiStack_55394[1] + 0x30) = aiStack_553bc[0];
                }
                if (iStack_553e0 != 2) {
                  if (aiStack_55394[2] == 0) {
                    /* WARNING: Subroutine does not return */
                    Sys_Error("Missing frame %i of %s",2,ptVar11);
                  }
                  *(undefined4 *)(aiStack_55394[2] + 0x24) = 2;
                  *(undefined4 *)(aiStack_55394[2] + 0x28) = 3;
                  *(int *)(aiStack_55394[2] + 0x20) = iStack_553e0;
                  *(int *)(aiStack_55394[2] + 0x2c) =
                       aiStack_55394[(int)(3 % (longlong)iStack_553e0)];
                  if (iStack_553c4 != 0) {
                    *(int *)(aiStack_55394[2] + 0x30) = aiStack_553bc[0];
                  }
                  if (iStack_553e0 != 3) {
                    if (aiStack_55394[3] == 0) {
                    /* WARNING: Subroutine does not return */
                      Sys_Error("Missing frame %i of %s",3,ptVar11);
                    }
                    *(undefined4 *)(aiStack_55394[3] + 0x24) = 3;
                    *(undefined4 *)(aiStack_55394[3] + 0x28) = 4;
                    *(int *)(aiStack_55394[3] + 0x20) = iStack_553e0;
                    *(int *)(aiStack_55394[3] + 0x2c) =
                         aiStack_55394[(int)(4 % (longlong)iStack_553e0)];
                    if (iStack_553c4 != 0) {
                      *(int *)(aiStack_55394[3] + 0x30) = aiStack_553bc[0];
                    }
                    if (iStack_553e0 != 4) {
                      if (aiStack_55394[4] == 0) {
                    /* WARNING: Subroutine does not return */
                        Sys_Error("Missing frame %i of %s",4,ptVar11);
                      }
                      *(undefined4 *)(aiStack_55394[4] + 0x24) = 4;
                      *(undefined4 *)(aiStack_55394[4] + 0x28) = 5;
                      *(int *)(aiStack_55394[4] + 0x20) = iStack_553e0;
                      *(int *)(aiStack_55394[4] + 0x2c) =
                           aiStack_55394[(int)(5 % (longlong)iStack_553e0)];
                      if (iStack_553c4 != 0) {
                        *(int *)(aiStack_55394[4] + 0x30) = aiStack_553bc[0];
                      }
                      if (iStack_553e0 != 5) {
                        if (aiStack_55394[5] == 0) {
                    /* WARNING: Subroutine does not return */
                          Sys_Error("Missing frame %i of %s",5,ptVar11);
                        }
                        *(undefined4 *)(aiStack_55394[5] + 0x24) = 5;
                        *(undefined4 *)(aiStack_55394[5] + 0x28) = 6;
                        *(int *)(aiStack_55394[5] + 0x20) = iStack_553e0;
                        *(int *)(aiStack_55394[5] + 0x2c) =
                             aiStack_55394[(int)(6 % (longlong)iStack_553e0)];
                        if (iStack_553c4 != 0) {
                          *(int *)(aiStack_55394[5] + 0x30) = aiStack_553bc[0];
                        }
                        if (iStack_553e0 != 6) {
                          if (aiStack_55394[6] == 0) {
                    /* WARNING: Subroutine does not return */
                            Sys_Error("Missing frame %i of %s",6,ptVar11);
                          }
                          *(undefined4 *)(aiStack_55394[6] + 0x24) = 6;
                          *(undefined4 *)(aiStack_55394[6] + 0x28) = 7;
                          *(int *)(aiStack_55394[6] + 0x20) = iStack_553e0;
                          *(int *)(aiStack_55394[6] + 0x2c) =
                               aiStack_55394[(int)(7 % (longlong)iStack_553e0)];
                          if (iStack_553c4 != 0) {
                            *(int *)(aiStack_55394[6] + 0x30) = aiStack_553bc[0];
                          }
                          if (iStack_553e0 != 7) {
                            if (aiStack_55394[7] == 0) {
                    /* WARNING: Subroutine does not return */
                              Sys_Error("Missing frame %i of %s",7,ptVar11);
                            }
                            *(undefined4 *)(aiStack_55394[7] + 0x24) = 7;
                            *(undefined4 *)(aiStack_55394[7] + 0x28) = 8;
                            *(int *)(aiStack_55394[7] + 0x20) = iStack_553e0;
                            *(int *)(aiStack_55394[7] + 0x2c) =
                                 aiStack_55394[(int)(8 % (longlong)iStack_553e0)];
                            if (iStack_553c4 != 0) {
                              *(int *)(aiStack_55394[7] + 0x30) = aiStack_553bc[0];
                            }
                            if (iStack_553e0 != 8) {
                              if (aiStack_55394[8] == 0) {
                    /* WARNING: Subroutine does not return */
                                Sys_Error("Missing frame %i of %s",8,ptVar11);
                              }
                              *(undefined4 *)(aiStack_55394[8] + 0x24) = 8;
                              *(undefined4 *)(aiStack_55394[8] + 0x28) = 9;
                              *(int *)(aiStack_55394[8] + 0x20) = iStack_553e0;
                              *(int *)(aiStack_55394[8] + 0x2c) =
                                   aiStack_55394[(int)(9 % (longlong)iStack_553e0)];
                              if (iStack_553c4 != 0) {
                                *(int *)(aiStack_55394[8] + 0x30) = aiStack_553bc[0];
                              }
                              if (iStack_553e0 != 9) {
                                if (aiStack_55394[9] == 0) {
                    /* WARNING: Subroutine does not return */
                                  Sys_Error("Missing frame %i of %s",9,ptVar11);
                                }
                                *(undefined4 *)(aiStack_55394[9] + 0x24) = 9;
                                *(undefined4 *)(aiStack_55394[9] + 0x28) = 10;
                                *(int *)(aiStack_55394[9] + 0x20) = iStack_553e0;
                                *(int *)(aiStack_55394[9] + 0x2c) =
                                     aiStack_55394[(int)(10 % (longlong)iStack_553e0)];
                                if (iStack_553c4 != 0) {
                                  *(int *)(aiStack_55394[9] + 0x30) = aiStack_553bc[0];
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
            iVar10 = *piVar7;
          }
LAB_0016249e:
          iVar17 = iVar17 + 1;
        } while (iVar17 < iVar10);
      }
    }
    dVar21 = Sys_FloatTime();
    Con_DPrintf("Texture load: %6.1fms\n",(dVar21 - dVar20) * 1000.0);
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Mod_LoadVertexes  @ 001637d0
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
  if (uVar3 == (uVar3 / 0xc) * 0xc) {
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
                    /* WARNING: Subroutine does not return */
  Sys_Error("MOD_LoadBmodel: funny lump size in %s",loadmodel);
}


// Mod_LoadVisibility  @ 00163660
void Mod_LoadVisibility(lump_t *l)

{
  model_t *pmVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pmVar1 = loadmodel;
  if (l->filelen == 0) {
    loadmodel->visdata = (byte *)0x0;
    return;
  }
  pbVar3 = Hunk_AllocName(l->filelen,loadname);
  pbVar2 = mod_base;
  pmVar1->visdata = pbVar3;
  Q_memcpy(loadmodel->visdata,pbVar2 + l->fileofs,l->filelen);
  return;
}


// Mod_MakeHull0  @ 001649f0
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
      if (iVar8 < 0) goto LAB_00164ae5;
LAB_00164a87:
      pdVar3->children[1] = (short)((int)pmVar5 - (int)loadmodel->nodes >> 2) * 0x4ec5;
      pmVar7 = loadmodel;
    }
    else {
      pdVar3->children[0] = (short)((int)pmVar6->children[0] - (int)loadmodel->nodes >> 2) * 0x4ec5;
      pmVar5 = pmVar6->children[1];
      iVar8 = pmVar5->contents;
      if (-1 < iVar8) goto LAB_00164a87;
LAB_00164ae5:
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


// Mod_MarkClient  @ 001621d0
void Mod_MarkClient(model_t *pModel)

{
  pModel->needload = 3;
  return;
}


// Mod_NeedCRC  @ 001620a0
void Mod_NeedCRC(char *name,qboolean needCRC)

{
  model_t *pmVar1;
  
                    /* Unresolved local var: model_t * mod@[???]
                       Unresolved local var: mod_known_info_t * p@[???] */
  pmVar1 = Mod_FindName(false,name);
  *(qboolean *)((int)mod_known_info + ((int)(pmVar1[-0x9e46].name + 0x10) >> 3) * 0x397829cc) =
       needCRC;
  return;
}


// Mod_PointInLeaf  @ 00161d20
mleaf_t * Mod_PointInLeaf(vec_t *p,model_t *model)

{
  float *pfVar1;
  mleaf_t *pmVar2;
  
                    /* Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: mplane_t * plane@[???] */
  if ((model != (model_t *)0x0) && (pmVar2 = (mleaf_t *)model->nodes, pmVar2 != (mleaf_t *)0x0)) {
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
                    /* WARNING: Subroutine does not return */
  Sys_Error("Mod_PointInLeaf: bad model");
}


// Mod_Print  @ 00166b80
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


// Mod_SetParent  @ 001642e0
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


// Mod_SpriteTextureName  @ 00165f20
void Mod_SpriteTextureName(char *pszName,int nNameSize,char *pcszModelName,int framenum)

{
  __snprintf_chk(pszName,nNameSize,1,0xffffffff,"%s_%i",pcszModelName,framenum);
  return;
}


// Mod_UnloadSpriteTextures  @ 001661a0
void Mod_UnloadSpriteTextures(model_t *pModel)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: msprite_t * pSprite@[???]
                       Unresolved local var: char[256] name@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (pModel->type == mod_sprite) {
    pvVar1 = (pModel->cache).data;
    pModel->needload = true;
    if (pvVar1 != (void *)0x0) {
      iVar2 = 0;
      if (0 < *(int *)((int)pvVar1 + 0xc)) {
        do {
          iVar3 = iVar2 + 1;
          __snprintf_chk(local_120,0x100,1,0x100,"%s_%i",pModel,iVar2);
          GL_UnloadTexture(local_120);
          iVar2 = iVar3;
        } while (iVar3 < *(int *)((int)pvVar1 + 0xc));
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Mod_ValidateCRC  @ 00162040
qboolean Mod_ValidateCRC(char *name,CRC32_t crc)

{
  int iVar1;
  model_t *pmVar2;
  
                    /* Unresolved local var: mod_known_info_t * p@[???]
                       Unresolved local var: model_t * mod@[???] */
  pmVar2 = Mod_FindName(true,name);
  iVar1 = ((int)(pmVar2[-0x9e46].name + 0x10) >> 3) * 0x397829cc;
  if (*(int *)((int)mod_known_info + iVar1 + 4) != 0) {
    return (uint)(*(CRC32_t *)((int)mod_known_info + iVar1 + 8) == crc);
  }
  return true;
}


