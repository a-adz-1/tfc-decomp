// Draw_AllocateCacheSpace  @ 001128d0
void Draw_AllocateCacheSpace(cachewad_t *wad,int cacheMax,int tempWad)

{
  cacheentry_t *dest;
  
                    /* Unresolved local var: int len@[???] */
  dest = Mem_Malloc(cacheMax * 0x44);
  wad->cache = dest;
  Q_memset(dest,0,cacheMax * 0x44);
  wad->tempWad = tempWad;
  return;
}


// Draw_AlphaAddPic  @ 001b1bc0
void Draw_AlphaAddPic(int x,int y,qpic_t *pic,colorVec *pc,int iAlpha)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: glpic_t * gl@[???] */
  if (pic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    (*qglEnable)(0xde1);
    (*qglBlendFunc)(0x302,1);
    (*qglEnable)(0xbe2);
    (*qglEnable)(0xbc0);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    if (pc == (colorVec *)0x0) {
      (*qglColor4f)(1.0,1.0,1.0,(float)iAlpha / 255.0);
    }
    else {
      (*qglColor4f)((float)pc->r / 255.0,(float)pc->g / 255.0,(float)pc->b / 255.0,
                    (float)iAlpha / 255.0);
    }
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar2 = *(uint *)pic->data & 0xffff;
    if (uVar2 != currenttexture) {
      iVar1 = ((int)*(uint *)pic->data >> 0x10) + -1;
      currenttexture = uVar2;
      (*qglBindTexture)(0xde1,uVar2);
      if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar1;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar1].colors);
      }
    }
    (*qglBegin)(7);
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)x,(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)(pic->width + x),(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)(x + pic->width),(float)(pic->height + y));
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)x,(float)(y + pic->height));
    (*qglEnd)();
                    /* WARNING: Could not recover jumptable at 0x001b1e42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
    return;
  }
  return;
}


// Draw_AlphaPic  @ 001b1920
void Draw_AlphaPic(int x,int y,qpic_t *pic,colorVec *pc,int iAlpha)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: glpic_t * gl@[???]
                       Unresolved local var: float alpha@[???] */
  if (pic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    (*qglBlendFunc)(1,1);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglEnable)(0xbe2);
    (*qglEnable)(0xbc0);
    fVar2 = (float)iAlpha / 255.0;
    if (pc == (colorVec *)0x0) {
      (*qglColor3f)(fVar2,fVar2,fVar2);
    }
    else {
      (*qglColor3f)((float)pc->r * fVar2 * 0.00390625,(float)pc->g * fVar2 * 0.00390625,
                    (float)pc->b * fVar2 * 0.00390625);
    }
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar3 = *(uint *)pic->data & 0xffff;
    if (uVar3 != currenttexture) {
      iVar1 = ((int)*(uint *)pic->data >> 0x10) + -1;
      currenttexture = uVar3;
      (*qglBindTexture)(0xde1,uVar3);
      if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar1;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar1].colors);
      }
    }
    (*qglBegin)(7);
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)x,(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)(pic->width + x),(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)(x + pic->width),(float)(pic->height + y));
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)x,(float)(y + pic->height));
    (*qglEnd)();
                    /* WARNING: Could not recover jumptable at 0x001b1b88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglDisable)(0xbe2);
    return;
  }
  return;
}


// Draw_AlphaSubPic  @ 001b1610
void Draw_AlphaSubPic(int xDest,int yDest,int xSrc,int ySrc,int iWidth,int iHeight,qpic_t *pPic,
                     colorVec *pc,int iAlpha)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  
                    /* Unresolved local var: glpic_t * gl@[???]
                       Unresolved local var: float flX@[???]
                       Unresolved local var: float flY@[???]
                       Unresolved local var: float flHeight@[???]
                       Unresolved local var: float flWidth@[???]
                       Unresolved local var: float alpha@[???] */
  if (pPic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    (*qglBlendFunc)(1,1);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglEnable)(0xbe2);
    (*qglEnable)(0xbc0);
    iVar2 = pPic->height;
    iVar3 = pPic->width;
    fVar5 = (float)xSrc / (float)iVar3;
    fVar4 = (float)ySrc / (float)iVar2;
    fVar6 = (float)iAlpha / 255.0;
    (*qglColor4f)((float)pc->r * fVar6 * 0.00390625,(float)pc->g * fVar6 * 0.00390625,
                  (float)pc->b * fVar6 * 0.00390625,1.0);
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar7 = *(uint *)pPic->data & 0xffff;
    if (uVar7 != currenttexture) {
      iVar1 = ((int)*(uint *)pPic->data >> 0x10) + -1;
      currenttexture = uVar7;
      (*qglBindTexture)(0xde1,uVar7);
      if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar1;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar1].colors);
      }
    }
    (*qglBegin)(7);
    (*qglTexCoord2f)(fVar5,fVar4);
    (*qglVertex2f)((float)xDest,(float)yDest);
    fVar6 = fVar5 + (float)iWidth / (float)iVar3;
    (*qglTexCoord2f)(fVar6,fVar4);
    (*qglVertex2f)((float)(xDest + iWidth),(float)yDest);
    fVar4 = fVar4 + (float)iHeight / (float)iVar2;
    (*qglTexCoord2f)(fVar6,fVar4);
    (*qglVertex2f)((float)(xDest + iWidth),(float)(iHeight + yDest));
    (*qglTexCoord2f)(fVar5,fVar4);
    (*qglVertex2f)((float)xDest,(float)(iHeight + yDest));
    (*qglEnd)();
                    /* WARNING: Could not recover jumptable at 0x001b1908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglDisable)(0xbe2);
    return;
  }
  return;
}


// Draw_BeginDisc  @ 001b3230
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_BeginDisc(void)

{
  if (draw_disc != (qpic_t *)0x0) {
    Draw_CenterPic(draw_disc);
  }
  return;
}


// Draw_CacheByIndex  @ 00113070
int Draw_CacheByIndex(cachewad_t *wad,int nIndex,int playernum)

{
  int iVar1;
  int iVar2;
  cacheentry_t *s1;
  char local_3c [44];
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[32] szTestName@[???] */
  iVar2 = 0;
  snprintf(local_3c,0x20,"%03i%02i",playernum,nIndex);
  iVar1 = wad->cacheCount;
  s1 = wad->cache;
  if (0 < iVar1) {
    do {
      iVar1 = Q_strcmp(s1->name,local_3c);
      if (iVar1 == 0) {
        iVar1 = wad->cacheCount;
        break;
      }
      iVar1 = wad->cacheCount;
      iVar2 = iVar2 + 1;
      s1 = s1 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar1 == iVar2) {
    if (iVar1 == wad->cacheMax) {
      Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar1);
      iVar1 = wad->cacheCount;
    }
    wad->cacheCount = iVar1 + 1;
    snprintf(s1->name,0x40,"%s",local_3c,nIndex);
    return iVar2;
  }
  return iVar2;
}


// Draw_CacheFindIndex  @ 00114610
int Draw_CacheFindIndex(cachewad_t *wad,char *path)

{
  int iVar1;
  int iVar2;
  cacheentry_t *s2;
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = -1;
  s2 = wad->cache;
  if (0 < wad->cacheCount) {
    iVar2 = 0;
    while( true ) {
      iVar1 = Q_strcmp(path,s2->name);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
      s2 = s2 + 1;
      if (wad->cacheCount <= iVar2) {
        return -1;
      }
    }
  }
  return iVar2;
}


// Draw_CacheGet  @ 00113cd0
void * Draw_CacheGet(cachewad_t *wad,int index)

{
  cacheentry_t *pic;
  void *pvVar1;
  char *pcVar2;
  int iVar3;
  qboolean qVar4;
  lumpinfo_t *pLump;
  int i;
  char local_3c [16];
  char local_2c [28];
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
  if (wad->cacheCount <= index) {
    Sys_Error("Cache wad indexed before load %s: %d",wad->name,index);
  }
  pic = wad->cache + index;
  if ((wad->tempWad == 0) && (pvVar1 = Cache_Check(&pic->cache), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???]
                       Unresolved local var: lumpinfo_t * pLump@[???] */
  pcVar2 = COM_FileBase_s(pic->name,local_3c,0x10);
  if (pcVar2 == (char *)0x0) {
    Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pic);
  }
  else {
    W_CleanupName(local_3c,local_2c);
    pLump = wad->lumps;
    if (0 < wad->lumpCount) {
      i = 0;
      while (iVar3 = Q_strcmp(local_2c,pLump->name), iVar3 != 0) {
        i = i + 1;
        pLump = pLump + 1;
        if (wad->lumpCount <= i) {
          return (void *)0x0;
        }
      }
      if (wad->lumpCount <= i) {
        return (void *)0x0;
      }
      qVar4 = Draw_CacheReload(wad,i,pLump,pic,local_2c,pic->name);
      if (qVar4 == false) {
        return (void *)0x0;
      }
      pvVar1 = (pic->cache).data;
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      Sys_Error("Draw_CacheGet: failed to load %s",pic);
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}


// Draw_CacheIndex  @ 00114570
int Draw_CacheIndex(cachewad_t *wad,char *path)

{
  int iVar1;
  int iVar2;
  cacheentry_t *s2;
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = 0;
  iVar1 = wad->cacheCount;
  s2 = wad->cache;
  if (0 < iVar1) {
    do {
      iVar1 = Q_strcmp(path,s2->name);
      if (iVar1 == 0) {
        iVar1 = wad->cacheCount;
        break;
      }
      iVar1 = wad->cacheCount;
      iVar2 = iVar2 + 1;
      s2 = s2 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar1 == iVar2) {
    if (iVar1 == wad->cacheMax) {
      Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar1);
      iVar1 = wad->cacheCount;
    }
    wad->cacheCount = iVar1 + 1;
    Q_strncpy(s2->name,path,0x3f);
    s2->name[0x3f] = '\0';
    return iVar2;
  }
  return iVar2;
}


// Draw_CacheLoadFromCustom  @ 001140f0
qboolean Draw_CacheLoadFromCustom
                   (char *clean,cachewad_t *wad,void *raw,int rawsize,cacheentry_t *pic)

{
  int iVar1;
  uchar *data;
  qboolean qVar2;
  qboolean qVar3;
  int iVar4;
  lumpinfo_t *lump;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: uchar * buf@[???]
                       Unresolved local var: lumpinfo_t * pLump@[???]
                       Unresolved local var: uchar * pStart@[???]
                       Unresolved local var: uchar * pDest@[???] */
  iVar4 = 0;
  iVar1 = Q_strlen(clean);
  if (4 < iVar1) {
    iVar4 = Q_atoi(clean + 3);
    if (iVar4 < 0) {
      return false;
    }
    if (wad->lumpCount <= iVar4) {
      return false;
    }
    iVar4 = iVar4 << 5;
  }
  lump = (lumpinfo_t *)(wad->lumps->name + iVar4 + -0x10);
  data = Cache_Alloc(&pic->cache,lump->size + wad->cacheExtra + 1,clean);
  if (data == (uchar *)0x0) {
    Sys_Error("Draw_CacheGet: not enough space for %s in %s",clean,wad->name);
  }
  data[wad->cacheExtra + lump->size] = '\0';
  Q_memcpy(data + wad->cacheExtra,(void *)((int)raw + lump->filepos),lump->size);
  qVar2 = Draw_ValidateCustomLogo(wad,data,lump);
  qVar3 = false;
  if (qVar2 != false) {
    gfCustomBuild = true;
    Q_strcpy(szCustName,"T");
    Q_memcpy(szCustName + 1,clean,5);
    szCustName[6] = '\0';
    if (wad->pfnCacheBuild != (PFNCACHE)0x0) {
      (*wad->pfnCacheBuild)(wad,data);
    }
    qVar3 = true;
    gfCustomBuild = false;
  }
  return qVar3;
}


// Draw_CachePic  @ 001b1190
qpic_t * Draw_CachePic(char *path)

{
  int index;
  qpic_t *pqVar1;
  
                    /* Unresolved local var: qpic_t * ret@[DW_OP_reg0(EAX)]
                       Unresolved local var: int idx@[???] */
  index = Draw_CacheIndex(menu_wad,path);
  pqVar1 = Draw_CacheGet(menu_wad,index);
  return pqVar1;
}


// Draw_CacheReload  @ 00113b50
qboolean Draw_CacheReload(cachewad_t *wad,int i,lumpinfo_t *pLump,cacheentry_t *pic,char *clean,
                         char *path)

{
  FileHandle_t file;
  qboolean qVar1;
  byte *pbVar2;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: uchar * buf@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  if (wad->numpaths < 1) {
    file = FS_Open(wad->name,"rb");
  }
  else {
                    /* Unresolved local var: char * pathID@[???] */
    file = FS_OpenPathID(wad->name,"rb",wad->basedirs[wad->lumppathindices[i]]);
  }
  qVar1 = false;
  if (file != (FileHandle_t)0x0) {
    FS_Size(file);
    if (wad->tempWad == 0) {
      pbVar2 = Cache_Alloc(&pic->cache,pLump->size + wad->cacheExtra + 1,clean);
    }
    else {
      pbVar2 = Hunk_TempAlloc(pLump->size + wad->cacheExtra + 1);
      (pic->cache).data = pbVar2;
    }
    if (pbVar2 == (byte *)0x0) {
      Sys_Error("Draw_CacheGet: not enough space for %s in %s",path,wad->name);
    }
    pbVar2[wad->cacheExtra + pLump->size] = '\0';
    FS_Seek(file,pLump->filepos,FILESYSTEM_SEEK_HEAD);
    FS_Read(pbVar2 + wad->cacheExtra,pLump->size,1,file);
    FS_Close(file);
    qVar1 = true;
    if (wad->pfnCacheBuild != (PFNCACHE)0x0) {
      (*wad->pfnCacheBuild)(wad,pbVar2);
      qVar1 = true;
    }
  }
  return qVar1;
}


// Draw_CacheWadHandler  @ 00112cf0
void Draw_CacheWadHandler(cachewad_t *wad,PFNCACHE fn,int extraDataSize)

{
  wad->pfnCacheBuild = fn;
  wad->cacheExtra = extraDataSize;
  return;
}


// Draw_CacheWadInit  @ 00112a50
void Draw_CacheWadInit(char *name,int cacheMax,cachewad_t *wad)

{
  FileHandle_t file;
  uint len;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  file = FS_Open(name,"rb");
  if (file == (FileHandle_t)0x0) {
    Sys_Error("Draw_LoadWad: Couldn\'t open %s\n",name);
  }
  len = FS_Size(file);
  Draw_CacheWadInitFromFile(file,len,name,cacheMax,wad);
  FS_Close(file);
  return;
}


// Draw_CacheWadInitFromFile  @ 00112920
void Draw_CacheWadInitFromFile(FileHandle_t hFile,int len,char *name,int cacheMax,cachewad_t *wad)

{
  lumpinfo_s *plVar1;
  char *pcVar2;
  cacheentry_t *dest;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  
                    /* Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: wadinfo_t header@[???]
                       Unresolved local var: int i@[???] */
  FS_Read(&local_28,0xc,1,hFile);
  if (local_28 != 0x33444157) {
    Sys_Error("Wad file %s doesn\'t have WAD3 id\n",name);
  }
  plVar1 = Mem_Malloc(len - local_20);
  wad->lumps = plVar1;
  FS_Seek(hFile,local_20,FILESYSTEM_SEEK_HEAD);
  FS_Read(wad->lumps,len - local_20,1,hFile);
  plVar1 = wad->lumps;
  if (0 < local_24) {
    iVar3 = 0;
    do {
      pcVar2 = plVar1->name;
      iVar3 = iVar3 + 1;
      plVar1 = plVar1 + 1;
      W_CleanupName(pcVar2,pcVar2);
    } while (iVar3 < local_24);
  }
  wad->lumpCount = local_24;
  wad->cacheMax = cacheMax;
  wad->cacheCount = 0;
  pcVar2 = Mem_Strdup(name);
  wad->name = pcVar2;
                    /* Unresolved local var: int len@[???] */
  dest = Mem_Malloc(cacheMax * 0x44);
  wad->cache = dest;
  Q_memset(dest,0,cacheMax * 0x44);
  wad->tempWad = 0;
  wad->pfnCacheBuild = (PFNCACHE)0x0;
  wad->cacheExtra = 0;
  return;
}


// Draw_CenterPic  @ 001d1130
void Draw_CenterPic(qpic_t *pPic)

{
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  Draw_Pic(glwidth / 2 - pPic->width / 2,SCR_CalcRefdef::h / 2 - pPic->height / 2,pPic);
  return;
}


// Draw_CharToConback  @ 001b11f0
void Draw_CharToConback(int num,uchar *dest)

{
  return;
}


// Draw_Character  @ 001b1330
int Draw_Character(int x,int y,int num,uint font)

{
  ISurface *pIVar1;
  int iVar2;
  int iStack_18;
  int iStack_14;
  int aiStack_10 [2];
  
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x18])
            (g_BaseUISurface._engineSurface);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xe])(pIVar1,font);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x11])(pIVar1,x,y);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x10])(pIVar1,_col._color);
  iVar2 = iswprint(num);
  if (iVar2 != 0) {
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x14])(pIVar1,num);
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x16])(pIVar1);
  }
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
            (pIVar1,font,num,&iStack_18,&iStack_14,aiStack_10);
  return iStack_18 + iStack_14 + aiStack_10[0];
}


// Draw_ConsoleBackground  @ 001b2b40
void Draw_ConsoleBackground(int lines)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char local_7c [100];
  int local_18;
  int local_14;
  int local_10;
  
                    /* Unresolved local var: char[100] ver@[???]
                       Unresolved local var: int x@[???] */
  iVar2 = glwidth;
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???] */
  iVar4 = lines - SCR_CalcRefdef::h;
  (*qglDisable)(0xde1);
  (*qglDisable)(0xbe2);
  (*qglDisable)(0xbc0);
  (*qglColor4f)(0.0,0.0,0.0,1.0);
  (*qglBegin)(7);
  (*qglVertex2f)(0.0,(float)iVar4);
  (*qglVertex2f)((float)iVar2,(float)iVar4);
  (*qglVertex2f)((float)iVar2,(float)lines);
  (*qglVertex2f)(0.0,(float)lines);
  (*qglEnd)();
  (*qglEnable)(0xde1);
  (*qglEnable)(0xbc0);
  iVar2 = build_number();
  snprintf(local_7c,100,"Half-Life %i/%s (hw build %d)",0x30,gpszVersionString,iVar2);
  uVar1 = vid.conwidth;
  uVar3 = VGUI2_GetConsoleFont();
  iVar2 = VGUI2_Draw_StringLen(local_7c,uVar3);
  if (console.value != 0.0) {
    if (((byte)giSubState & 4) == 0) {
                    /* Unresolved local var: int wide@[???] */
      uVar3 = VGUI2_GetConsoleFont();
      VGUI2_DrawString(uVar1 - iVar2,0,local_7c,uVar3);
                    /* Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: int num@[???] */
      iVar2 = __isoc99_sscanf(con_color.string,"%i %i %i",&local_18,&local_14,&local_10);
      if (iVar2 == 3) {
        VGUI2_Draw_SetTextColor(local_18,local_14,local_10);
      }
    }
    return;
  }
  return;
}


// Draw_CustomCacheGet  @ 00114240
void * Draw_CustomCacheGet(cachewad_t *wad,void *raw,int rawsize,int index)

{
  void *pvVar1;
  char *pcVar2;
  qboolean qVar3;
  cacheentry_t *pic;
  char local_3c [16];
  char local_2c [28];
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[DW_OP_reg3(EBX)] */
  if (wad->cacheCount <= index) {
    Sys_Error("Cache wad indexed before load %s: %d",wad->name,index);
  }
  pic = wad->cache + index;
  pvVar1 = Cache_Check(&pic->cache);
  if (pvVar1 == (void *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???] */
    pcVar2 = COM_FileBase_s(pic->name,local_3c,0x10);
    if (pcVar2 == (char *)0x0) {
      Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pic);
    }
    else {
      W_CleanupName(local_3c,local_2c);
      qVar3 = Draw_CacheLoadFromCustom(local_2c,wad,raw,rawsize,pic);
      if ((qVar3 != false) && (pvVar1 = (pic->cache).data, pvVar1 == (void *)0x0)) {
        Sys_Error("Draw_CacheGet: failed to load %s",pic);
      }
    }
  }
  return pvVar1;
}


// Draw_CustomCacheWadInit  @ 001126d0
qboolean __regparm3 Draw_CustomCacheWadInit(int cacheMax,cachewad_t *wad,void *raw,int nFileSize)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  char *pcVar6;
  
                    /* Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: wadinfo_t header@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: uchar * pStart@[DW_OP_reg2(EDX)]
                       Unresolved local var: int len@[???] */
  iVar1 = wad->cacheCount;
  if (wad->name != (char *)0x33444157) {
    Con_Printf("Custom file doesn\'t have WAD3 id\n");
    return false;
  }
  if (wad->cache == (cacheentry_t *)0x1) {
    if (iVar1 < 1) {
      Con_Printf("Custom file has bogus infotableofs %i\n",iVar1);
    }
    else if ((void *)(iVar1 + 0x20) == raw) {
      pvVar5 = Mem_Malloc(0x20);
      *(void **)(cacheMax + 0x10) = pvVar5;
      Q_memcpy(pvVar5,(void *)((int)&wad->name + iVar1),0x20);
      puVar2 = *(uint **)(cacheMax + 0x10);
      W_CleanupName((char *)(puVar2 + 4),(char *)(puVar2 + 4));
      uVar3 = puVar2[2];
      if (uVar3 == puVar2[1]) {
        if ((int)uVar3 < 1) {
          Con_Printf("Custom file has bogus lump size %i\n",uVar3);
        }
        else {
          uVar4 = *puVar2;
          if (uVar4 < 0xc) {
            Con_Printf("Custom file has bogus lump offset %i\n",uVar4);
          }
          else {
            if ((int)(uVar4 + uVar3) <= iVar1) {
              *(undefined4 *)(cacheMax + 0x14) = 1;
              *(undefined4 *)(cacheMax + 8) = 0;
              *(undefined4 *)(cacheMax + 0xc) = 0x10;
              pcVar6 = Mem_Strdup("tempdecal.wad");
              *(char **)cacheMax = pcVar6;
                    /* Unresolved local var: int len@[???] */
              pvVar5 = Mem_Malloc(0x440);
              *(void **)(cacheMax + 4) = pvVar5;
              Q_memset(pvVar5,0,0x440);
              *(undefined4 *)(cacheMax + 0x2c) = 0;
              *(undefined4 *)(cacheMax + 0x1c) = 0;
              *(undefined4 *)(cacheMax + 0x18) = 0;
              return true;
            }
            Con_Printf("Custom file has bogus lump %i\n",0);
          }
        }
      }
      else {
        Con_Printf("Custom file has mismatched lump size ( %i vs. %i )\n",uVar3,puVar2[1]);
      }
    }
    else {
      Con_Printf("Custom file has bogus infotableofs ( %i > %i )\n",(void *)(iVar1 + 0x20),raw);
    }
    return false;
  }
  Con_Printf("Custom file has wrong number of lumps %i\n",wad->cache);
  return false;
}


// Draw_CustomCacheWadInit  @ 00112ae0
qboolean Draw_CustomCacheWadInit(int cacheMax,cachewad_t *wad,void *raw,int nFileSize)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  qboolean qVar4;
  lumpinfo_s *plVar5;
  char *pcVar6;
  cacheentry_t *dest;
  
                    /* Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: wadinfo_t header@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: uchar * pStart@[???] */
  iVar1 = *(int *)((int)raw + 8);
  if (*(int *)raw == 0x33444157) {
    if (*(int *)((int)raw + 4) == 1) {
      if (iVar1 < 1) {
        Con_Printf("Custom file has bogus infotableofs %i\n",iVar1);
        qVar4 = false;
      }
      else if (iVar1 + 0x20 == nFileSize) {
        plVar5 = Mem_Malloc(0x20);
        wad->lumps = plVar5;
        Q_memcpy(plVar5,(void *)((int)raw + iVar1),0x20);
        plVar5 = wad->lumps;
        W_CleanupName(plVar5->name,plVar5->name);
        iVar2 = plVar5->size;
        if (iVar2 == plVar5->disksize) {
          if (iVar2 < 1) {
            Con_Printf("Custom file has bogus lump size %i\n",iVar2);
            qVar4 = false;
          }
          else {
            uVar3 = plVar5->filepos;
            if (uVar3 < 0xc) {
              Con_Printf("Custom file has bogus lump offset %i\n",uVar3);
              qVar4 = false;
            }
            else if (iVar1 < (int)(uVar3 + iVar2)) {
              Con_Printf("Custom file has bogus lump %i\n",0);
              qVar4 = false;
            }
            else {
              wad->cacheMax = cacheMax;
              wad->lumpCount = 1;
              wad->cacheCount = 0;
              pcVar6 = Mem_Strdup("tempdecal.wad");
              wad->name = pcVar6;
                    /* Unresolved local var: int len@[???] */
              dest = Mem_Malloc(cacheMax * 0x44);
              wad->cache = dest;
              Q_memset(dest,0,cacheMax * 0x44);
              qVar4 = true;
              wad->tempWad = 0;
              wad->pfnCacheBuild = (PFNCACHE)0x0;
              wad->cacheExtra = 0;
            }
          }
        }
        else {
          Con_Printf("Custom file has mismatched lump size ( %i vs. %i )\n",iVar2,plVar5->disksize);
          qVar4 = false;
        }
      }
      else {
        Con_Printf("Custom file has bogus infotableofs ( %i > %i )\n",iVar1 + 0x20,nFileSize);
        qVar4 = false;
      }
    }
    else {
      Con_Printf("Custom file has wrong number of lumps %i\n",*(int *)((int)raw + 4));
      qVar4 = false;
    }
  }
  else {
    Con_Printf("Custom file doesn\'t have WAD3 id\n");
    qVar4 = false;
  }
  return qVar4;
}


// Draw_DebugChar  @ 001b13e0
void Draw_DebugChar(char num)

{
  return;
}


// Draw_DecalCount  @ 00113000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Draw_DecalCount(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (decal_wad != (cachewad_t *)0x0) {
    iVar1 = decal_wad->lumpCount;
  }
  return iVar1;
}


// Draw_DecalIndex  @ 00112ec0
int Draw_DecalIndex(int id)

{
  cachewad_t *pcVar1;
  qboolean qVar2;
  int iVar3;
  int iVar4;
  char (*s1) [16];
  cacheentry_t *s2;
  char local_3c [44];
  
                    /* Unresolved local var: char[32] tmp@[???]
                       Unresolved local var: char * pName@[???]
                       Unresolved local var: cvar_t violence_hblood@[???] */
  if (decal_names[id][0] == '\0') {
    Sys_Error("Used decal #%d without a name\n",id);
  }
  qVar2 = Host_IsServerActive();
  s1 = decal_names + id;
  if (((qVar2 == false) && (violence_hblood.value == 0.0)) &&
     (iVar3 = Q_strncmp(*s1,"{blood",6), iVar3 == 0)) {
    s1 = (char (*) [16])local_3c;
    snprintf((char *)s1,0x20,"{yblood%s",id * 0x10 + 0x971926);
  }
  pcVar1 = decal_wad;
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = 0;
  iVar3 = decal_wad->cacheCount;
  s2 = decal_wad->cache;
  if (0 < iVar3) {
    do {
      iVar3 = Q_strcmp(*s1,s2->name);
      if (iVar3 == 0) {
        iVar3 = pcVar1->cacheCount;
        break;
      }
      iVar3 = pcVar1->cacheCount;
      iVar4 = iVar4 + 1;
      s2 = s2 + 1;
    } while (iVar4 < iVar3);
  }
  if (iVar4 != iVar3) {
    return iVar4;
  }
  iVar3 = iVar4;
  if (pcVar1->cacheMax == iVar4) {
    Sys_Error("Cache wad (%s) out of %d entries",pcVar1->name,iVar4);
    iVar3 = pcVar1->cacheCount;
  }
  pcVar1->cacheCount = iVar3 + 1;
  Q_strncpy(s2->name,*s1,0x3f);
  s2->name[0x3f] = '\0';
  return iVar4;
}


// Draw_DecalIndexFromName  @ 00113140
int Draw_DecalIndexFromName(char *name)

{
  int iVar1;
  char (*s2) [16];
  int iVar2;
  char local_1c [15];
  undefined1 local_d;
  
                    /* Unresolved local var: char[16] tmpName@[???]
                       Unresolved local var: int i@[???] */
  Q_strncpy(local_1c,name,0xf);
  local_d = 0;
  if (local_1c[0] == '}') {
    local_1c[0] = '{';
  }
  s2 = decal_names;
  iVar2 = 0;
  do {
    if ((*s2)[0] != '\0') {
      iVar1 = Q_strcmp(local_1c,*s2);
      if (iVar1 == 0) {
        return iVar2;
      }
    }
    iVar2 = iVar2 + 1;
    s2 = s2 + 1;
  } while (iVar2 != 0x200);
  return 0;
}


// Draw_DecalName  @ 00113040
char * Draw_DecalName(int number)

{
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    return decal_wad->lumps[number].name;
  }
  return (char *)0x0;
}


// Draw_DecalSetName  @ 00112e80
void Draw_DecalSetName(int decal,char *name)

{
  if (decal < 0x200) {
    Q_strncpy(decal_names[decal],name,0xf);
    decal_names[decal][0xf] = '\0';
  }
  return;
}


// Draw_DecalShutdown  @ 00112e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_DecalShutdown(void)

{
  Draw_FreeWad(decal_wad);
  if (decal_wad != (cachewad_t *)0x0) {
    Mem_Free(decal_wad);
  }
  decal_wad = (cachewad_t *)0x0;
  return;
}


// Draw_DecalSize  @ 00113010
int Draw_DecalSize(int number)

{
  int iVar1;
  
  iVar1 = 0;
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    iVar1 = decal_wad->lumps[number].size;
  }
  return iVar1;
}


// Draw_DecalTexture  @ 001144b0
texture_t * Draw_DecalTexture(int index)

{
  customization_s_conflict *pcVar1;
  texture_t *ptVar2;
  uint uVar3;
  
                    /* Unresolved local var: int playernum@[???]
                       Unresolved local var: customization_t * pCust@[???] */
  if (index < 0) {
    uVar3 = ~index;
    pcVar1 = cl.players[uVar3].customdata.pNext;
    if ((((pcVar1 == (customization_s_conflict *)0x0) || (pcVar1->bInUse == 0)) ||
        (pcVar1->pInfo == (cachewad_t *)0x0)) || (pcVar1->pBuffer == (void *)0x0)) {
      Sys_Error("Failed to load custom decal for player #%i:%s using default decal 0.\n",uVar3,
                uVar3 * 0x250 + 0xdf8924);
      ptVar2 = (texture_t *)0x0;
    }
    else {
                    /* Unresolved local var: texture_t * retval@[???] */
      ptVar2 = Draw_CustomCacheGet(pcVar1->pInfo,pcVar1->pBuffer,(pcVar1->resource).nDownloadSize,
                                   pcVar1->nUserData1);
      if (ptVar2 == (texture_t *)0x0) {
        ptVar2 = Draw_CacheGet(decal_wad,0);
      }
    }
  }
  else {
    ptVar2 = Draw_CacheGet(decal_wad,index);
  }
  return ptVar2;
}


// Draw_EndDisc  @ 001b3250
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_EndDisc(void)

{
  return;
}


// Draw_FadeScreen  @ 001b3150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_FadeScreen(void)

{
  (*qglEnable)(0xbe2);
  (*qglDisable)(0xde1);
  (*qglColor4f)(0.0,0.0,0.0,0.8);
  (*qglBegin)(7);
  (*qglVertex2f)(0.0,0.0);
  (*qglVertex2f)((float)glwidth,0.0);
  (*qglVertex2f)((float)glwidth,(float)SCR_CalcRefdef::h);
  (*qglVertex2f)(0.0,(float)SCR_CalcRefdef::h);
  (*qglEnd)();
  (*qglColor4f)(1.0,1.0,1.0,1.0);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  return;
}


// Draw_Fill  @ 001b30e0
void Draw_Fill(int x,int y,int w,int h,int c)

{
  Draw_FillRGBA(x,y,w,h,(uint)host_basepal[c * 4],(uint)host_basepal[c * 4 + 1],
                (uint)host_basepal[c * 4 + 2],c);
  return;
}


// Draw_FillRGBA  @ 001b0800
void __regparm3 Draw_FillRGBA(int x,int y,int w,int h,int r,int g,int b,int a)

{
  int local_28;
  int local_24;
  int local_20 [4];
  int local_10 [4];
  
  local_10[0] = 0xff;
  local_28 = w;
  local_24 = y;
  local_20[0] = x;
  (*g_engdstAddrs.pfnFillRGBA)(local_20,&local_24,&local_28,&h,&r,&g,&b,local_10);
  (*qglDisable)(0xde1);
  (*qglEnable)(0xbe2);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBlendFunc)(0x302,1);
  (*qglColor4f)((float)r / 255.0,(float)g / 255.0,(float)b / 255.0,(float)local_10[0] / 255.0);
  (*qglBegin)(7);
  (*qglVertex2f)((float)local_20[0],(float)local_24);
  (*qglVertex2f)((float)(local_20[0] + local_28),(float)local_24);
  (*qglVertex2f)((float)(local_20[0] + local_28),(float)(local_24 + h));
  (*qglVertex2f)((float)local_20[0],(float)(local_24 + h));
  (*qglEnd)();
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  return;
}


// Draw_FillRGBA  @ 001b2d60
void Draw_FillRGBA(int x,int y,int w,int h,int r,int g,int b,int a)

{
  (*g_engdstAddrs.pfnFillRGBA)(&x,&y,&w,&h,&r,&g,&b,&a);
  (*qglDisable)(0xde1);
  (*qglEnable)(0xbe2);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBlendFunc)(0x302,1);
  (*qglColor4f)((float)r / 255.0,(float)g / 255.0,(float)b / 255.0,(float)a / 255.0);
  (*qglBegin)(7);
  (*qglVertex2f)((float)x,(float)y);
  (*qglVertex2f)((float)(x + w),(float)y);
  (*qglVertex2f)((float)(x + w),(float)(y + h));
  (*qglVertex2f)((float)x,(float)(y + h));
  (*qglEnd)();
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  return;
}


// Draw_FillRGBABlend  @ 001b2f00
void Draw_FillRGBABlend(int x,int y,int w,int h,int r,int g,int b,int a)

{
  (*g_engdstAddrs.pfnFillRGBA)(&x,&y,&w,&h,&r,&g,&b,&a);
  (*qglDisable)(0xde1);
  (*qglEnable)(0xbe2);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBlendFunc)(0x302,0x303);
  (*qglColor4f)((float)r / 255.0,(float)g / 255.0,(float)b / 255.0,(float)a / 255.0);
  (*qglBegin)(7);
  (*qglVertex2f)((float)x,(float)y);
  (*qglVertex2f)((float)(x + w),(float)y);
  (*qglVertex2f)((float)(x + w),(float)(y + h));
  (*qglVertex2f)((float)x,(float)(y + h));
  (*qglEnd)();
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  return;
}


// Draw_Frame  @ 001b26d0
void Draw_Frame(mspriteframe_t *pFrame,int ix,int iy,wrect_t *prcSubRect)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float fLeft@[???]
                       Unresolved local var: float fRight@[???]
                       Unresolved local var: float fTop@[???]
                       Unresolved local var: float fBottom@[???]
                       Unresolved local var: int iWidth@[???]
                       Unresolved local var: int iHeight@[???] */
  local_24 = 0.0;
  local_20 = 1.0;
  local_14 = pFrame->width;
  local_1c = 0.0;
  local_10[0] = pFrame->height;
  local_18 = 1.0;
  fVar2 = (float)ix + 0.5;
  fVar3 = (float)iy + 0.5;
  VGUI2_ResetCurrentTexture();
  if (giScissorTest != false) {
    (*qglScissor)(scissor_x,scissor_y,scissor_width,scissor_height);
    (*qglEnable)(0xc11);
  }
  if (prcSubRect != (wrect_t *)0x0) {
    AdjustSubRect(pFrame,&local_24,&local_20,&local_1c,&local_18,&local_14,local_10,prcSubRect);
  }
  (*qglDepthMask)('\0');
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar4 = pFrame->gl_texturenum & 0xffff;
  if (uVar4 != currenttexture) {
    iVar1 = (pFrame->gl_texturenum >> 0x10) + -1;
    currenttexture = uVar4;
    (*qglBindTexture)(0xde1,uVar4);
    if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar1;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar1].colors);
    }
  }
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBegin)(7);
  (*qglTexCoord2f)(local_24,local_1c);
  (*qglVertex2f)(fVar2,fVar3);
  (*qglTexCoord2f)(local_20,local_1c);
  (*qglVertex2f)((float)local_14 + fVar2,fVar3);
  (*qglTexCoord2f)(local_20,local_18);
  (*qglVertex2f)((float)local_14 + fVar2,(float)local_10[0] + fVar3);
  (*qglTexCoord2f)(local_24,local_18);
  (*qglVertex2f)(fVar2,(float)local_10[0] + fVar3);
  (*qglEnd)();
  (*qglDepthMask)('\x01');
  (*qglDisable)(0xc11);
  return;
}


// Draw_FreeWad  @ 00112d10
void Draw_FreeWad(cachewad_t *pWad)

{
  void *pvVar1;
  cacheentry_t *p;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???] */
  if (pWad != (cachewad_t *)0x0) {
    if (pWad->lumps != (lumpinfo_s *)0x0) {
      Mem_Free(pWad->lumps);
    }
    pWad->lumps = (lumpinfo_s *)0x0;
    Mem_Free(pWad->name);
    if (pWad->numpaths != 0) {
      if (0 < pWad->numpaths) {
        iVar3 = 0;
        do {
          iVar2 = iVar3 + 1;
          Mem_Free(pWad->basedirs[iVar3]);
          pWad->basedirs[iVar3] = (char *)0x0;
          iVar3 = iVar2;
        } while (iVar2 < pWad->numpaths);
      }
      Mem_Free(pWad->basedirs);
      pWad->basedirs = (char **)0x0;
    }
    if (pWad->lumppathindices != (int *)0x0) {
      Mem_Free(pWad->lumppathindices);
      pWad->lumppathindices = (int *)0x0;
    }
    p = pWad->cache;
    if (p != (cacheentry_t *)0x0) {
                    /* Unresolved local var: int i@[???] */
      if ((pWad->tempWad == 0) && (0 < pWad->cacheCount)) {
        iVar3 = 0;
        do {
          pvVar1 = Cache_Check(&p->cache);
          if (pvVar1 != (void *)0x0) {
            Cache_Free(&p->cache);
          }
          iVar3 = iVar3 + 1;
          p = p + 1;
        } while (iVar3 < pWad->cacheCount);
        p = pWad->cache;
      }
      Mem_Free(p);
      return;
    }
  }
  return;
}


// Draw_GetDefaultColor  @ 001b12d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_GetDefaultColor(void)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10 [4];
  
                    /* Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: int num@[???] */
  iVar1 = __isoc99_sscanf(con_color.string,"%i %i %i",&local_18,&local_14,local_10);
  if (iVar1 != 3) {
    return;
  }
  VGUI2_Draw_SetTextColor(local_18,local_14,local_10[0]);
  return;
}


// Draw_Init  @ 001b7790
/* WARNING: Removing unreachable block (ram,0x001b7909) */
/* WARNING: Removing unreachable block (ram,0x001b7910) */
/* WARNING: Removing unreachable block (ram,0x001b7a2c) */
/* WARNING: Removing unreachable block (ram,0x001b7a30) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_Init(void)

{
  byte bVar1;
  char cVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  int iVar21;
  GL_PALETTE *pGVar22;
  qpic_t *pqVar23;
  qpic_t *pqVar24;
  uint *data;
  uint uVar25;
  uchar *puVar26;
  gltexture_t *pgVar27;
  int iVar28;
  bool bVar29;
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar35 [16];
  undefined1 auVar39 [16];
  undefined1 auVar43 [16];
  undefined1 auVar51 [16];
  undefined1 auVar59 [16];
  undefined1 auVar67 [16];
  undefined1 uVar75;
  undefined1 uVar76;
  undefined1 uVar77;
  undefined1 uVar78;
  undefined1 uVar79;
  undefined1 uVar80;
  undefined1 uVar81;
  int iVar82;
  undefined2 uVar83;
  int iVar84;
  int iVar85;
  int iVar87;
  uint local_28;
  int local_24;
  int local_20 [4];
  undefined1 auVar32 [16];
  undefined1 auVar36 [16];
  undefined1 auVar40 [16];
  undefined1 auVar44 [16];
  undefined1 auVar52 [16];
  undefined1 auVar60 [16];
  undefined1 auVar68 [16];
  undefined1 auVar45 [16];
  undefined1 auVar53 [16];
  undefined1 auVar61 [16];
  undefined1 auVar69 [16];
  undefined1 auVar33 [16];
  undefined1 auVar37 [16];
  undefined1 auVar41 [16];
  undefined1 auVar46 [16];
  undefined1 auVar54 [16];
  undefined1 auVar62 [16];
  undefined1 auVar70 [16];
  undefined1 auVar47 [16];
  undefined1 auVar55 [16];
  undefined1 auVar63 [16];
  undefined1 auVar71 [16];
  undefined1 auVar34 [16];
  undefined1 auVar38 [16];
  undefined1 auVar42 [16];
  undefined1 auVar48 [16];
  undefined1 auVar56 [16];
  undefined1 auVar64 [16];
  undefined1 auVar72 [16];
  undefined1 auVar49 [16];
  undefined1 auVar57 [16];
  undefined1 auVar65 [16];
  undefined1 auVar73 [16];
  undefined1 auVar50 [16];
  undefined1 auVar58 [16];
  undefined1 auVar66 [16];
  undefined1 auVar74 [16];
  int iVar86;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int vid_level@[???] */
  m_bDrawInitialized = true;
  VGUI2_Draw_Init();
  Cmd_AddCommand("gl_texels",GL_Texels_f);
  Cvar_RegisterVariable(&gl_max_size);
  Cvar_RegisterVariable(&gl_round_down);
  Cvar_RegisterVariable(&gl_picmip);
  Cvar_RegisterVariable(&gl_palette_tex);
  Cvar_RegisterVariable(&gl_texturemode);
  Cvar_RegisterVariable(&gl_ansio);
  Cvar_HookVariable(gl_texturemode.name,&gl_texturemode_hook);
  iVar21 = Host_GetVideoLevel();
  if (0 < iVar21) {
    (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  }
  pGVar22 = gGLPalette;
  do {
                    /* Unresolved local var: int i@[???] */
    pGVar22->tag = -1;
    pGVar22->referenceCount = 0;
    pGVar22 = pGVar22 + 1;
  } while (pGVar22 != (GL_PALETTE *)&DAT_00e4e690);
  menu_wad = Mem_ZeroMalloc(0x30);
  Draw_CacheWadInit("cached.wad",0x10,menu_wad);
  menu_wad->tempWad = 1;
  Draw_CacheWadHandler(&custom_wad,Draw_MiptexTexture,0x20);
  if ((qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0) &&
     (gl_palette_tex.value != 0.0)) {
    (*qglEnable)(0x81fb);
  }
  Q_memset(decal_names,0,0x2000);
  puVar26 = texgammatable;
  uVar25 = 0;
  auVar30._8_8_ = 0x300000002;
  auVar30._0_8_ = 0x100000000;
  do {
    iVar21 = auVar30._0_4_;
    iVar82 = iVar21 + 4;
    iVar28 = auVar30._4_4_;
    iVar84 = iVar28 + 4;
    iVar86 = auVar30._8_4_;
    iVar87 = auVar30._12_4_;
    iVar85 = iVar86 + 4;
    uVar25 = uVar25 + 1;
    auVar34._0_12_ = auVar30._0_12_;
    auVar34._12_2_ = auVar30._6_2_;
    auVar34._14_2_ = (short)((uint)iVar84 >> 0x10);
    auVar33._12_4_ = auVar34._12_4_;
    auVar33._0_10_ = auVar30._0_10_;
    auVar33._10_2_ = (short)iVar84;
    auVar32._10_6_ = auVar33._10_6_;
    auVar32._0_8_ = auVar30._0_8_;
    auVar32._8_2_ = auVar30._4_2_;
    uVar83 = (undefined2)((uint)iVar82 >> 0x10);
    auVar3._2_8_ = auVar32._8_8_;
    auVar3._0_2_ = uVar83;
    auVar3._10_6_ = 0;
    auVar31._12_4_ = 0;
    auVar31._0_12_ = SUB1612(auVar3 << 0x30,4);
    auVar31 = auVar31 << 0x20;
    auVar38._0_12_ = auVar31._0_12_;
    auVar38._12_2_ = uVar83;
    auVar38._14_2_ = (short)((uint)iVar85 >> 0x10);
    auVar37._12_4_ = auVar38._12_4_;
    auVar37._0_10_ = auVar31._0_10_;
    auVar37._10_2_ = auVar30._10_2_;
    auVar36._10_6_ = auVar37._10_6_;
    auVar36._0_8_ = auVar31._0_8_;
    auVar36._8_2_ = auVar30._2_2_;
    auVar4._2_8_ = auVar36._8_8_;
    auVar4._0_2_ = (short)iVar85;
    auVar4._10_6_ = 0;
    auVar35._12_4_ = 0;
    auVar35._0_12_ = SUB1612(auVar4 << 0x30,4);
    auVar35 = auVar35 << 0x20;
    cVar2 = (char)(iVar87 + 8);
    auVar42._0_12_ = auVar35._0_12_;
    auVar42._12_2_ = (short)iVar85;
    auVar42._14_2_ = (short)(iVar87 + 4);
    auVar41._12_4_ = auVar42._12_4_;
    auVar41._0_10_ = auVar35._0_10_;
    auVar41._10_2_ = (short)iVar84;
    auVar40._10_6_ = auVar41._10_6_;
    auVar40._0_8_ = auVar35._0_8_;
    auVar40._8_2_ = (short)iVar82;
    auVar5._2_8_ = auVar40._8_8_;
    auVar5._0_2_ = auVar30._12_2_;
    auVar5._10_6_ = 0;
    auVar39._12_4_ = 0;
    auVar39._0_12_ = SUB1612(auVar5 << 0x30,4);
    auVar39 = auVar39 << 0x20;
    uVar79 = (undefined1)((uint)(iVar21 + 0xc) >> 8);
    uVar80 = (undefined1)(iVar28 + 0xc);
    uVar81 = (undefined1)(iVar86 + 0xc);
    auVar50._0_14_ = auVar39._0_14_;
    auVar50[0xe] = auVar30[0xd];
    auVar50[0xf] = (char)((uint)(iVar87 + 8) >> 8);
    auVar49._14_2_ = auVar50._14_2_;
    auVar49._0_13_ = auVar39._0_13_;
    auVar49[0xd] = cVar2;
    auVar48._13_3_ = auVar49._13_3_;
    auVar48._0_12_ = auVar39._0_12_;
    auVar48[0xc] = auVar30[0xc];
    auVar47._12_4_ = auVar48._12_4_;
    auVar47._0_11_ = auVar39._0_11_;
    uVar78 = (undefined1)((uint)(iVar86 + 8) >> 8);
    auVar47[0xb] = uVar78;
    auVar46._11_5_ = auVar47._11_5_;
    auVar46._0_10_ = auVar39._0_10_;
    auVar46[10] = auVar30[9];
    auVar45._10_6_ = auVar46._10_6_;
    auVar45._0_9_ = auVar39._0_9_;
    uVar77 = (undefined1)(iVar86 + 8);
    auVar45[9] = uVar77;
    auVar44._9_7_ = auVar45._9_7_;
    auVar44._0_8_ = auVar39._0_8_;
    auVar44[8] = auVar30[8];
    uVar76 = (undefined1)((uint)(iVar28 + 8) >> 8);
    auVar10._1_8_ = auVar44._8_8_;
    auVar10[0] = uVar76;
    auVar10._9_7_ = 0;
    uVar75 = (undefined1)(iVar28 + 8);
    auVar9._10_6_ = 0;
    auVar9._0_10_ = SUB1610(auVar10 << 0x38,6);
    auVar8._11_5_ = 0;
    auVar8._0_11_ = SUB1611(auVar9 << 0x30,5);
    auVar7._12_4_ = 0;
    auVar7._0_12_ = SUB1612(auVar8 << 0x28,4);
    auVar6._13_3_ = 0;
    auVar6._0_13_ = SUB1613(auVar7 << 0x20,3);
    auVar67[0] = auVar30[0];
    auVar43._14_2_ = 0;
    auVar43._0_14_ = SUB1614(auVar6 << 0x18,2);
    auVar43 = auVar43 << 0x10;
    auVar58._0_14_ = auVar43._0_14_;
    auVar58[0xe] = uVar76;
    auVar58[0xf] = (char)((uint)(iVar28 + 0xc) >> 8);
    auVar57._14_2_ = auVar58._14_2_;
    auVar57._0_13_ = auVar43._0_13_;
    auVar57[0xd] = (char)((uint)iVar84 >> 8);
    auVar56._13_3_ = auVar57._13_3_;
    auVar56._0_12_ = auVar43._0_12_;
    auVar56[0xc] = auVar30[5];
    auVar55._12_4_ = auVar56._12_4_;
    auVar55._0_11_ = auVar43._0_11_;
    auVar55[0xb] = uVar80;
    auVar54._11_5_ = auVar55._11_5_;
    auVar54._0_10_ = auVar43._0_10_;
    auVar54[10] = uVar75;
    auVar53._10_6_ = auVar54._10_6_;
    auVar53._0_9_ = auVar43._0_9_;
    auVar53[9] = (char)iVar84;
    auVar52._9_7_ = auVar53._9_7_;
    auVar52._0_8_ = auVar43._0_8_;
    auVar52[8] = auVar30[4];
    auVar15._1_8_ = auVar52._8_8_;
    auVar15[0] = uVar79;
    auVar15._9_7_ = 0;
    auVar14._10_6_ = 0;
    auVar14._0_10_ = SUB1610(auVar15 << 0x38,6);
    auVar13._11_5_ = 0;
    auVar13._0_11_ = SUB1611(auVar14 << 0x30,5);
    auVar12._12_4_ = 0;
    auVar12._0_12_ = SUB1612(auVar13 << 0x28,4);
    auVar11._13_3_ = 0;
    auVar11._0_13_ = SUB1613(auVar12 << 0x20,3);
    auVar51._14_2_ = 0;
    auVar51._0_14_ = SUB1614(auVar11 << 0x18,2);
    auVar51 = auVar51 << 0x10;
    auVar66._0_14_ = auVar51._0_14_;
    auVar66[0xe] = uVar79;
    auVar66[0xf] = (char)((uint)(iVar86 + 0xc) >> 8);
    auVar65._14_2_ = auVar66._14_2_;
    auVar65._0_13_ = auVar51._0_13_;
    auVar65[0xd] = uVar78;
    auVar64._13_3_ = auVar65._13_3_;
    auVar64._0_12_ = auVar51._0_12_;
    auVar64[0xc] = (char)((uint)(iVar21 + 8) >> 8);
    auVar63._12_4_ = auVar64._12_4_;
    auVar63._0_11_ = auVar51._0_11_;
    auVar63[0xb] = (char)((uint)iVar85 >> 8);
    auVar62._11_5_ = auVar63._11_5_;
    auVar62._0_10_ = auVar51._0_10_;
    auVar62[10] = (char)((uint)iVar82 >> 8);
    auVar61._10_6_ = auVar62._10_6_;
    auVar61._0_9_ = auVar51._0_9_;
    auVar61[9] = auVar30[9];
    auVar60._9_7_ = auVar61._9_7_;
    auVar60._0_8_ = auVar51._0_8_;
    auVar60[8] = auVar30[1];
    auVar20._1_8_ = auVar60._8_8_;
    auVar20[0] = uVar81;
    auVar20._9_7_ = 0;
    auVar19._10_6_ = 0;
    auVar19._0_10_ = SUB1610(auVar20 << 0x38,6);
    auVar18._11_5_ = 0;
    auVar18._0_11_ = SUB1611(auVar19 << 0x30,5);
    auVar17._12_4_ = 0;
    auVar17._0_12_ = SUB1612(auVar18 << 0x28,4);
    auVar16._13_3_ = 0;
    auVar16._0_13_ = SUB1613(auVar17 << 0x20,3);
    auVar59._14_2_ = 0;
    auVar59._0_14_ = SUB1614(auVar16 << 0x18,2);
    auVar59 = auVar59 << 0x10;
    auVar74._0_14_ = auVar59._0_14_;
    auVar74[0xe] = uVar81;
    auVar74[0xf] = cVar2 + '\x04';
    auVar73._14_2_ = auVar74._14_2_;
    auVar73._0_13_ = auVar59._0_13_;
    auVar73[0xd] = uVar80;
    auVar72._13_3_ = auVar73._13_3_;
    auVar72._0_12_ = auVar59._0_12_;
    auVar72[0xc] = (char)(iVar21 + 0xc);
    auVar71._12_4_ = auVar72._12_4_;
    auVar71._0_11_ = auVar59._0_11_;
    auVar71[0xb] = cVar2;
    auVar70._11_5_ = auVar71._11_5_;
    auVar70._0_10_ = auVar59._0_10_;
    auVar70[10] = uVar77;
    auVar69._10_6_ = auVar70._10_6_;
    auVar69._0_9_ = auVar59._0_9_;
    auVar69[9] = uVar75;
    auVar68._9_7_ = auVar69._9_7_;
    auVar68._0_8_ = auVar59._0_8_;
    auVar68[8] = (char)(iVar21 + 8);
    auVar67._8_8_ = auVar68._8_8_;
    auVar67[7] = (char)(iVar87 + 4);
    auVar67[6] = (char)iVar85;
    auVar67[5] = (char)iVar84;
    auVar67[4] = (char)iVar82;
    auVar67[3] = auVar30[0xc];
    auVar67[2] = auVar30[8];
    auVar67[1] = auVar30[4];
    *(undefined1 (*) [16])puVar26 = auVar67;
    puVar26 = (uchar *)((int)puVar26 + 0x10);
    auVar30._0_4_ = iVar21 + 0x10;
    auVar30._4_4_ = iVar28 + 0x10;
    auVar30._8_4_ = iVar86 + 0x10;
    auVar30._12_4_ = iVar87 + 0x10;
  } while (uVar25 < 0x10);
  pqVar23 = W_GetLumpName(0,"lambda");
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: gltexture_t * glt@[???]
                       Unresolved local var: int * pbuf@[???]
                       Unresolved local var: uchar * pPal@[???]
                       Unresolved local var: glpic_t * gl@[???]
                       Unresolved local var: qpic_t * ppicNew@[???] */
  if (pqVar23 == (qpic_t *)0x0) {
    pqVar23 = (qpic_t *)0x0;
  }
  else {
    pgVar27 = gltextures;
    iVar28 = 0;
    pqVar24 = Mem_Malloc(0x20);
    iVar21 = pqVar23->height;
    iVar82 = pqVar23->width;
    pqVar24->width = iVar82;
    pqVar24->height = iVar21;
    while (iVar28 < numgltextures) {
      iVar84 = Q_strcmp("lambda",pgVar27->identifier);
      if (iVar84 == 0) {
        if ((iVar82 == pgVar27->width) && (iVar21 == pgVar27->height)) goto LAB_001b7c73;
        DAT_0028ab3f = 99;
        pgVar27 = gltextures;
        iVar28 = 0;
      }
      else {
        iVar28 = iVar28 + 1;
        pgVar27 = pgVar27 + 1;
      }
    }
    numgltextures = numgltextures + 1;
    Q_strncpy(pgVar27->identifier,"lambda",0x3f);
                    /* Unresolved local var: GLuint tex@[???] */
    pgVar27->identifier[0x3f] = '\0';
    (*qglGenTextures)(1,&local_28);
    iVar28 = gHostSpawnCount;
    pgVar27->width = iVar82;
    pgVar27->texnum = local_28;
    pgVar27->servercount = (short)iVar28;
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar25 = local_28 & 0xffff;
    bVar29 = uVar25 != currenttexture;
    pgVar27->height = iVar21;
    pgVar27->mipmap = false;
    if (bVar29) {
      iVar21 = ((int)local_28 >> 0x10) + -1;
      currenttexture = uVar25;
      (*qglBindTexture)(0xde1,uVar25);
      if (((-1 < iVar21) && (iVar21 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar21;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar21 * 0x308 + 0xe0c1a8));
      }
    }
    data = Mem_Malloc(pqVar23->width * pqVar23->height * 4);
    iVar21 = pqVar23->width * pqVar23->height + 10;
    iVar82 = 0;
    do {
      pqVar23->data[iVar82 + iVar21 + -8] = texgammatable[pqVar23->data[iVar82 + iVar21 + -8]];
      iVar82 = iVar82 + 1;
    } while (iVar82 != 0x300);
    iVar82 = pqVar23->width;
    iVar28 = pqVar23->height;
    if (0 < iVar82 * iVar28) {
      iVar84 = 0;
      do {
                    /* Unresolved local var: uchar b@[???] */
        bVar1 = pqVar23->data[iVar84];
        uVar25 = *(uint *)(pqVar23->data + (uint)bVar1 * 3 + iVar21 + -8) & 0xffffff;
        data[iVar84] = uVar25;
        if (bVar1 != 0xff) {
          data[iVar84] = uVar25 | 0xff000000;
        }
        iVar82 = pqVar23->width;
        iVar84 = iVar84 + 1;
        iVar28 = pqVar23->height;
      } while (iVar84 < iVar82 * iVar28);
    }
    GL_Upload32(data,iVar82,iVar28,false,1,gl_filter_max);
    *(int *)pqVar24->data = pgVar27->texnum;
    pqVar24[1].width = 0;
    pqVar24[1].data[0] = '\0';
    pqVar24[1].data[1] = '\0';
    pqVar24[1].data[2] = 0x80;
    pqVar24[1].data[3] = '?';
    pqVar24[1].height = 0;
    pqVar24[2].width = 0x3f800000;
    Mem_Free(data);
    pqVar23 = pqVar24;
  }
LAB_001b7c73:
                    /* Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: int num@[???] */
  draw_disc = pqVar23;
  iVar21 = __isoc99_sscanf(con_color.string,"%i %i %i",&local_28,&local_24,local_20);
  if (iVar21 != 3) {
    return;
  }
  VGUI2_Draw_SetTextColor(local_28,local_24,local_20[0]);
  return;
}


// Draw_MessageCharacterAdd  @ 001b11e0
int Draw_MessageCharacterAdd(int x,int y,int num,int rr,int gg,int bb,uint font)

{
  ISurface *pIVar1;
  int iVar2;
  int iStack_18;
  int iStack_14;
  int aiStack_10 [2];
  
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x18])
            (g_BaseUISurface._engineSurface);
  _col._color[1] = (uchar)gg;
  _col._color[0] = (uchar)rr;
  _col._color[2] = (uchar)bb;
  _col._color[3] = 0xff;
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xe])(pIVar1,font);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x11])(pIVar1,x,y);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x10])(pIVar1,_col._color);
  iVar2 = iswprint(num);
  if (iVar2 != 0) {
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x15])(pIVar1,num);
  }
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x3f])(pIVar1,font);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
            (pIVar1,font,num,&iStack_18,&iStack_14,aiStack_10);
  return iStack_18 + iStack_14 + aiStack_10[0];
}


// Draw_MessageFontInfo  @ 001b11d0
int Draw_MessageFontInfo(short *pWidth,uint font)

{
  int iVar1;
  
  iVar1 = VGUI2_GetFontTall(font);
  return iVar1;
}


// Draw_MiptexTexture  @ 001b8eb0
void Draw_MiptexTexture(cachewad_t *wad,uchar *data)

{
  int iVar1;
  uint uVar2;
  int32 iVar3;
  int iVar4;
  uchar *pPal;
  int32 local_34 [10];
  
                    /* Unresolved local var: texture_t * tex@[???]
                       Unresolved local var: miptex_t * mip@[???]
                       Unresolved local var: miptex_t tmp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int paloffset@[???]
                       Unresolved local var: int palettesize@[???]
                       Unresolved local var: uchar * pal@[???]
                       Unresolved local var: uchar * bitmap@[???] */
  iVar1 = 0x20;
  if (wad->cacheExtra != 0x20) {
    Sys_Error("Draw_MiptexTexture: Bad cached wad %s\n",wad->name);
    iVar1 = wad->cacheExtra;
  }
  uVar2 = 0;
  do {
    *(undefined4 *)((int)local_34 + uVar2) = *(undefined4 *)(data + uVar2 + iVar1);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x28);
  Q_memcpy(data,local_34,0x10);
  iVar3 = (*LittleLong)(local_34[4]);
  *(int32 *)(data + 0x10) = iVar3;
  iVar3 = (*LittleLong)(local_34[5]);
  data[0x28] = '\0';
  data[0x29] = '\0';
  data[0x2a] = '\0';
  data[0x2b] = '\0';
  data[0x24] = '\0';
  data[0x25] = '\0';
  data[0x26] = '\0';
  data[0x27] = '\0';
  data[0x20] = '\0';
  data[0x21] = '\0';
  data[0x22] = '\0';
  data[0x23] = '\0';
  data[0x30] = '\0';
  data[0x31] = '\0';
  data[0x32] = '\0';
  data[0x33] = '\0';
  data[0x2c] = '\0';
  data[0x2d] = '\0';
  data[0x2e] = '\0';
  data[0x2f] = '\0';
  *(int32 *)(data + 0x14) = iVar3;
  iVar3 = (*LittleLong)(local_34[6]);
  *(int32 *)(data + 0x34) = iVar3 + wad->cacheExtra;
  iVar3 = (*LittleLong)(local_34[7]);
  *(int32 *)(data + 0x38) = iVar3 + wad->cacheExtra;
  iVar3 = (*LittleLong)(local_34[8]);
  *(int32 *)(data + 0x3c) = iVar3 + wad->cacheExtra;
  iVar3 = (*LittleLong)(local_34[9]);
  iVar1 = *(int *)(data + 0x34);
  *(int32 *)(data + 0x40) = iVar3 + wad->cacheExtra;
  iVar4 = *(int *)(data + 0x14) * *(int *)(data + 0x10);
  pPal = data + iVar1 + 2 + iVar4 + (iVar4 >> 6) + (iVar4 >> 2) + (iVar4 >> 4);
  if (gfCustomBuild != false) {
    Q_strncpy((char *)data,szCustName,0xf);
    data[0xf] = '\0';
  }
  if (((pPal[0x2fd] == '\0') && (pPal[0x2fe] == '\0')) && (pPal[0x2ff] == 0xff)) {
    *data = '{';
    iVar4 = 1;
  }
  else {
    *data = '}';
    if (gfCustomBuild != false) {
      GL_UnloadTexture((char *)data);
    }
    iVar4 = 3;
  }
  iVar1 = GL_LoadTexture2((char *)data,GLT_DECAL,*(int *)(data + 0x10),*(int *)(data + 0x14),
                          data + iVar1,true,iVar4,pPal,gl_filter_max);
  *(int *)(data + 0x18) = iVar1;
  return;
}


// Draw_Pic  @ 001b13f0
void Draw_Pic(int x,int y,qpic_t *pic)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: glpic_t * gl@[???] */
  if (pic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    (*qglEnable)(0xde1);
    (*qglDisable)(0xbe2);
    (*qglDisable)(0xb71);
    (*qglEnable)(0xbc0);
    (*qglTexEnvf)(0x2300,0x2200,7681.0);
    (*qglColor4f)(1.0,1.0,1.0,1.0);
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar2 = *(uint *)pic->data & 0xffff;
    if (uVar2 != currenttexture) {
      iVar1 = ((int)*(uint *)pic->data >> 0x10) + -1;
      currenttexture = uVar2;
      (*qglBindTexture)(0xde1,uVar2);
      if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar1;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar1].colors);
      }
    }
    (*qglBegin)(7);
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)x,(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)(pic->width + x),(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)(x + pic->width),(float)(pic->height + y));
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)x,(float)(y + pic->height));
                    /* WARNING: Could not recover jumptable at 0x001b15f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglEnd)();
    return;
  }
  return;
}


// Draw_Pic2  @ 001b1e80
void Draw_Pic2(int x,int y,int w,int h,qpic_t *pic)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  
                    /* Unresolved local var: glpic_t * gl@[???] */
  if (pic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    (*qglEnable)(0xde1);
    (*qglDisable)(0xbe2);
    (*qglEnable)(0xbc0);
    (*qglTexEnvf)(0x2300,0x2200,7681.0);
    (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar2 = *(uint *)pic->data & 0xffff;
    if (uVar2 != currenttexture) {
      iVar3 = ((int)*(uint *)pic->data >> 0x10) + -1;
      currenttexture = uVar2;
      (*qglBindTexture)(0xde1,uVar2);
      if (((-1 < iVar3) && (iVar3 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar3;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar3].colors);
      }
    }
    (*qglBegin)(7);
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)x,(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[1].height);
    (*qglVertex2f)((float)(x + w),(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[2].width);
    fVar1 = (float)(y + h + -1);
    (*qglVertex2f)((float)(x + w),fVar1);
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)x,fVar1);
                    /* WARNING: Could not recover jumptable at 0x001b208a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglEnd)();
    return;
  }
  return;
}


// Draw_PicFromWad  @ 001b8e20
qpic_t * Draw_PicFromWad(char *name)

{
  qpic_t *pqVar1;
  int iVar2;
  
                    /* Unresolved local var: qpic_t * p@[???]
                       Unresolved local var: glpic_t * gl@[???] */
  pqVar1 = W_GetLumpName(0,name);
                    /* Unresolved local var: uchar * pPal@[???] */
  iVar2 = GL_LoadTexture2(name,GLT_SYSTEM,pqVar1->width,pqVar1->height,pqVar1->data,false,1,
                          pqVar1->data + pqVar1->width * pqVar1->height + 2,gl_filter_max);
  pqVar1[1].width = 0;
  pqVar1[1].height = 0;
  *(int *)pqVar1->data = iVar2;
  pqVar1[1].data[0] = '\0';
  pqVar1[1].data[1] = '\0';
  pqVar1[1].data[2] = 0x80;
  pqVar1[1].data[3] = '?';
  pqVar1[2].width = 0x3f800000;
  return pqVar1;
}


// Draw_ResetTextColor  @ 001b1200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_ResetTextColor(void)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10 [4];
  
                    /* Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: int num@[???] */
  iVar1 = __isoc99_sscanf(con_color.string,"%i %i %i",&local_18,&local_14,local_10);
  if (iVar1 != 3) {
    return;
  }
  VGUI2_Draw_SetTextColor(local_18,local_14,local_10[0]);
  return;
}


// Draw_SetTextColor  @ 001b1260
void Draw_SetTextColor(float r,float g,float b)

{
  (*g_engdstAddrs.pfnDrawSetTextColor)(&r,&g,&b);
  VGUI2_Draw_SetTextColor((int)(r * 255.0),(int)(g * 255.0),(int)(b * 255.0));
  return;
}


// Draw_Shutdown  @ 00112e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_Shutdown(void)

{
  if (m_bDrawInitialized == false) {
    return;
  }
  m_bDrawInitialized = false;
  Draw_FreeWad(menu_wad);
  if (menu_wad != (cachewad_t *)0x0) {
    Mem_Free(menu_wad);
  }
  menu_wad = (cachewad_t *)0x0;
  return;
}


// Draw_SpriteFrame  @ 001b2960
void Draw_SpriteFrame(mspriteframe_t *pFrame,ushort *pPalette,int x,int y,wrect_t *prcSubRect)

{
  Draw_Frame(pFrame,x,y,prcSubRect);
  return;
}


// Draw_SpriteFrameAdditive  @ 001b2a30
void Draw_SpriteFrameAdditive
               (mspriteframe_t *pFrame,ushort *pPalette,int x,int y,wrect_t *prcSubRect)

{
  (*qglEnable)(0xbe2);
  (*qglBlendFunc)(1,1);
  Draw_Frame(pFrame,x,y,prcSubRect);
                    /* WARNING: Could not recover jumptable at 0x001b2aab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglDisable)(0xbe2);
  return;
}


// Draw_SpriteFrameGeneric  @ 001b2ab0
void Draw_SpriteFrameGeneric
               (mspriteframe_t *pFrame,ushort *pPalette,int x,int y,wrect_t *prcSubRect,int src,
               int dest,int width,int height)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int oldWidth@[???]
                       Unresolved local var: int oldHeight@[???] */
  iVar1 = pFrame->width;
  pFrame->width = width;
  iVar2 = pFrame->height;
  pFrame->height = height;
  (*qglEnable)(0xbe2);
  (*qglBlendFunc)(src,dest);
  Draw_Frame(pFrame,x,y,prcSubRect);
  (*qglDisable)(0xbe2);
  pFrame->width = iVar1;
  pFrame->height = iVar2;
  return;
}


// Draw_SpriteFrameHoles  @ 001b2980
void Draw_SpriteFrameHoles(mspriteframe_t *pFrame,ushort *pPalette,int x,int y,wrect_t *prcSubRect)

{
  (*qglEnable)(0xbc0);
  if (gl_spriteblend.value != 0.0) {
    (*qglBlendFunc)(0x302,0x303);
    (*qglEnable)(0xbe2);
  }
  Draw_Frame(pFrame,x,y,prcSubRect);
  (*qglDisable)(0xbc0);
                    /* WARNING: Could not recover jumptable at 0x001b2a02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglDisable)(0xbe2);
  return;
}


// Draw_String  @ 001b1340
int Draw_String(int x,int y,char *str)

{
  uint font;
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int wide@[???] */
  font = VGUI2_GetConsoleFont();
  iVar1 = VGUI2_DrawString(x,y,str,font);
                    /* Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: int num@[???] */
  iVar2 = __isoc99_sscanf(con_color.string,"%i %i %i",&local_18,&local_14,local_10);
  if (iVar2 != 3) {
    return iVar1 + x;
  }
  VGUI2_Draw_SetTextColor(local_18,local_14,local_10[0]);
  return iVar1 + x;
}


// Draw_StringLen  @ 001b11c0
int Draw_StringLen(char *psz,uint font)

{
  ILocalize *pIVar1;
  ISurface *pIVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  wchar_t *__s;
  int iStack_28;
  int iStack_24;
  int aiStack_20 [4];
  
  if ((psz != (char *)0x0) && (*psz == '#')) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,psz);
    if (__s != (wchar_t *)0x0) goto LAB_0021c5e0;
  }
  pIVar1 = vgui2::localize();
  __s = VGUI2_Find_String::lexical_block_0::tmpString;
  (**(code **)(*(int *)pIVar1 + 0x14))
            (pIVar1,psz,VGUI2_Find_String::lexical_block_0::tmpString,0x1000);
LAB_0021c5e0:
  iVar5 = 0;
  for (uVar4 = 0; sVar3 = wcslen(__s), uVar4 < sVar3; uVar4 = uVar4 + 1) {
    pIVar2 = vgui2::surface();
    (*(pIVar2->super_IBaseInterface)._vptr_IBaseInterface[0x40])
              (pIVar2,font,__s[uVar4],&iStack_28,&iStack_24,aiStack_20);
    iVar5 = iVar5 + iStack_28 + iStack_24 + aiStack_20[0];
  }
  return iVar5;
}


// Draw_TileClear  @ 001b30a0
void Draw_TileClear(int x,int y,int w,int h)

{
  int in_stack_00000014;
  
  Draw_FillRGBA(x,y,w,h,0,0,0,in_stack_00000014);
  return;
}


// Draw_TransPic  @ 001b20a0
void Draw_TransPic(int x,int y,qpic_t *pic)

{
  if (pic != (qpic_t *)0x0) {
    if ((((x < 0) || (vid.width < (uint)(pic->width + x))) || (y < 0)) ||
       (vid.height < (uint)(pic->height + y))) {
      Sys_Error("Draw_TransPic: bad coordinates");
    }
    Draw_Pic(x,y,pic);
    return;
  }
  return;
}


// Draw_TransPicTranslate  @ 001b2130
void Draw_TransPicTranslate(int x,int y,qpic_t *pic,uchar *translation)

{
  int iVar1;
  int iVar2;
  int iVar3;
  GLuint GVar4;
  uint uVar5;
  int iVar6;
  GLuint *pGVar7;
  int local_4038;
  GLuint local_4020 [4096];
  GLuint local_20 [4];
  
                    /* Unresolved local var: int v@[???]
                       Unresolved local var: int u@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: uint[4096] trans@[???]
                       Unresolved local var: uint * dest@[???]
                       Unresolved local var: uchar * src@[???]
                       Unresolved local var: int p@[???] */
  if (pic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    if (translate_texture == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
      (*qglGenTextures)(1,local_20);
      translate_texture = local_20[0];
    }
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar5 = translate_texture & 0xffff;
    if (uVar5 != currenttexture) {
      iVar1 = (translate_texture >> 0x10) + -1;
      currenttexture = uVar5;
      (*qglBindTexture)(0xde1,uVar5);
      if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar1;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar1].colors);
      }
    }
    local_4038 = 0;
    pGVar7 = local_4020;
    iVar1 = pic->height;
    iVar2 = pic->width;
    do {
      iVar6 = 0;
      iVar3 = 0;
      do {
        GVar4 = 0xff;
        if (menuplyr_pixels[(iVar6 >> 6) + (local_4038 >> 6) * iVar2] != 0xff) {
          GVar4 = 0xff0000ff;
        }
        iVar6 = iVar6 + iVar2;
        pGVar7[iVar3] = GVar4;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0x40);
      pGVar7 = pGVar7 + 0x40;
      local_4038 = local_4038 + iVar1;
    } while (pGVar7 != local_20);
    (*qglTexImage2D)(0xde1,0,0x8058,0x40,0x40,0,0x1908,0x1401,local_4020);
    (*qglTexParameterf)(0xde1,0x2801,9729.0);
    (*qglTexParameterf)(0xde1,0x2800,9729.0);
    (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
    (*qglColor3f)(1.0,1.0,1.0);
    (*qglBegin)(7);
    (*qglTexCoord2f)(0.0,0.0);
    (*qglVertex2f)((float)x,(float)y);
    (*qglTexCoord2f)(1.0,0.0);
    (*qglVertex2f)((float)(x + pic->width),(float)y);
    (*qglTexCoord2f)(1.0,1.0);
    (*qglVertex2f)((float)(x + pic->width),(float)(y + pic->height));
    (*qglTexCoord2f)(0.0,1.0);
    (*qglVertex2f)((float)x,(float)(y + pic->height));
    (*qglEnd)();
  }
  return;
}


// Draw_ValidateCustomLogo  @ 00113e30
qboolean Draw_ValidateCustomLogo(cachewad_t *wad,uchar *data,lumpinfo_t *lump)

{
  uint uVar1;
  int32 iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_9c [20];
  int local_4c [4];
  int32 local_3c;
  int32 local_38;
  int32 local_34;
  int32 local_30;
  int32 local_2c;
  int32 local_28;
  
                    /* Unresolved local var: texture_t tex@[???]
                       Unresolved local var: miptex_t * mip@[???]
                       Unresolved local var: miptex_t tmp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int paloffset@[???]
                       Unresolved local var: int palettesize@[???]
                       Unresolved local var: int size@[???] */
  if (wad->cacheExtra == 0x20) {
    uVar1 = 0;
    do {
      *(undefined4 *)((int)local_4c + uVar1) = *(undefined4 *)(data + uVar1 + 0x20);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x28);
    uVar1 = 0;
    do {
      *(undefined4 *)((int)local_9c + uVar1) = *(undefined4 *)(data + uVar1);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x48);
    Q_memcpy(local_9c,local_4c,0x10);
    local_9c[4] = (*LittleLong)(local_3c);
    local_9c[5] = (*LittleLong)(local_38);
    local_9c[10] = 0;
    local_9c[9] = 0;
    local_9c[8] = 0;
    local_9c[0xc] = 0;
    local_9c[0xb] = 0;
    iVar2 = (*LittleLong)(local_34);
    local_9c[0xd] = iVar2 + wad->cacheExtra;
    iVar2 = (*LittleLong)(local_30);
    local_9c[0xe] = iVar2 + wad->cacheExtra;
    iVar2 = (*LittleLong)(local_2c);
    local_9c[0xf] = iVar2 + wad->cacheExtra;
    iVar2 = (*LittleLong)(local_28);
    local_9c[0x10] = iVar2 + wad->cacheExtra;
    if ((((local_9c[4] == 0) || (local_9c[5] == 0)) || (0x100 < local_9c[4])) ||
       (0x100 < local_9c[5])) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad tex size %ux%u on %s\n",local_9c[4],
                 local_9c[5],wad->name);
      return false;
    }
    iVar3 = local_9c[5] * local_9c[4];
    iVar5 = (iVar3 >> 2) + (iVar3 >> 4) + (iVar3 >> 6) + iVar3;
    uVar1 = wad->cacheExtra + lump->size;
    if (uVar1 <= iVar5 + 0x28U) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad size %i/%i on %s\n",iVar5 + 0x28U,uVar1,
                 wad->name);
      iVar3 = local_9c[5] * local_9c[4];
    }
    uVar1 = (uint)*(ushort *)(data + iVar5 + 0x48);
    if (((local_34 + iVar3 == local_30) &&
        (iVar4 = local_34 + iVar3 + (iVar3 >> 2), iVar4 == local_2c)) &&
       (iVar4 + (iVar3 >> 4) == local_28)) {
      if (0x100 < uVar1) {
        Con_Printf("Draw_ValidateCustomLogo: Bad cached wad palette size %i on %s\n",uVar1,wad->name
                  );
        return false;
      }
      iVar2 = (*LittleLong)(local_34);
      if (iVar5 + iVar2 + uVar1 * 3 + 2 <= (uint)lump->disksize) {
        return true;
      }
    }
  }
  Con_Printf("Draw_ValidateCustomLogo: Bad cached wad %s\n",wad->name);
  return false;
}


