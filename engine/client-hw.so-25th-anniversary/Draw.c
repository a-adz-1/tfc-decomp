// Draw_AllocateCacheSpace  @ 000a9450
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


// Draw_AlphaAddPic  @ 00159dd0
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
                    /* WARNING: Could not recover jumptable at 0x0015a062. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
    return;
  }
  return;
}


// Draw_AlphaPic  @ 00159b20
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
                    /* WARNING: Could not recover jumptable at 0x00159d9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglDisable)(0xbe2);
    return;
  }
  return;
}


// Draw_AlphaSubPic  @ 00159830
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
    fVar6 = (float)iWidth / (float)iVar3 + fVar5;
    (*qglTexCoord2f)(fVar6,fVar4);
    (*qglVertex2f)((float)(iWidth + xDest),(float)yDest);
    fVar4 = (float)iHeight / (float)iVar2 + fVar4;
    (*qglTexCoord2f)(fVar6,fVar4);
    (*qglVertex2f)((float)(iWidth + xDest),(float)(iHeight + yDest));
    (*qglTexCoord2f)(fVar5,fVar4);
    (*qglVertex2f)((float)xDest,(float)(iHeight + yDest));
    (*qglEnd)();
                    /* WARNING: Could not recover jumptable at 0x00159b09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglDisable)(0xbe2);
    return;
  }
  return;
}


// Draw_BeginDisc  @ 0015b5c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_BeginDisc(void)

{
  if (draw_disc != (qpic_t *)0x0) {
    Draw_CenterPic(draw_disc);
  }
  return;
}


// Draw_CacheByIndex  @ 000a9c70
int Draw_CacheByIndex(cachewad_t *wad,int nIndex,int playernum)

{
  int iVar1;
  int iVar2;
  cacheentry_t *s1;
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[32] szTestName@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = 0;
  __snprintf_chk(local_40,0x20,1,0x20,0x256c8d,playernum,nIndex);
  iVar1 = wad->cacheCount;
  s1 = wad->cache;
  if (0 < iVar1) {
    do {
      iVar1 = Q_strcmp(s1->name,local_40);
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
                    /* WARNING: Subroutine does not return */
      Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar1);
    }
    wad->cacheCount = iVar1 + 1;
    snprintf(s1->name,0x40,"%s",local_40);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


// Draw_CacheFindIndex  @ 000ab4e0
int Draw_CacheFindIndex(cachewad_t *wad,char *path)

{
  int iVar1;
  int iVar2;
  cacheentry_t *s2;
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = 0;
  s2 = wad->cache;
  if (0 < wad->cacheCount) {
    do {
      iVar1 = Q_strcmp(path,s2->name);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      s2 = s2 + 1;
    } while (iVar2 < wad->cacheCount);
  }
  return -1;
}


// Draw_CacheGet  @ 000aa930
void * Draw_CacheGet(cachewad_t *wad,int index)

{
  void *pvVar1;
  char *pcVar2;
  int iVar3;
  qboolean qVar4;
  lumpinfo_t *pLump;
  cacheentry_t *pic;
  int i;
  int in_GS_OFFSET;
  char local_40 [16];
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (wad->cacheCount <= index) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Cache wad indexed before load %s: %d",wad->name,index);
  }
  pic = wad->cache + index;
  if (wad->tempWad == 0) {
    pvVar1 = Cache_Check(&pic->cache);
    if (pvVar1 != (void *)0x0) goto LAB_000aa983;
  }
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???]
                       Unresolved local var: lumpinfo_t * pLump@[???] */
  pcVar2 = COM_FileBase_s(pic->name,local_40,0x10);
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pic);
  }
  W_CleanupName(local_40,local_30);
  pLump = wad->lumps;
  if (0 < wad->lumpCount) {
    i = 0;
    do {
      iVar3 = Q_strcmp(local_30,pLump->name);
      if (iVar3 == 0) {
        if (i < wad->lumpCount) {
          qVar4 = Draw_CacheReload(wad,i,pLump,pic,local_30,pic->name);
          if (qVar4 != false) {
            pvVar1 = (pic->cache).data;
            if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
              Sys_Error("Draw_CacheGet: failed to load %s",pic);
            }
            goto LAB_000aa983;
          }
        }
        break;
      }
      i = i + 1;
      pLump = pLump + 1;
    } while (i < wad->lumpCount);
  }
  pvVar1 = (void *)0x0;
LAB_000aa983:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pvVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_CacheIndex  @ 000ab440
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
  if (iVar1 != iVar2) {
    return iVar2;
  }
  if (iVar1 == wad->cacheMax) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar1);
  }
  wad->cacheCount = iVar1 + 1;
  Q_strncpy(s2->name,path,0x3f);
  s2->name[0x3f] = '\0';
  return iVar2;
}


// Draw_CacheLoadFromCustom  @ 000aad40
qboolean Draw_CacheLoadFromCustom
                   (char *clean,cachewad_t *wad,void *raw,int rawsize,cacheentry_t *pic)

{
  int iVar1;
  lumpinfo_t *lump;
  byte *data;
  qboolean qVar2;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: byte * buf@[???]
                       Unresolved local var: lumpinfo_t * pLump@[???]
                       Unresolved local var: byte * pStart@[???]
                       Unresolved local var: byte * pDest@[???] */
  iVar1 = Q_strlen(clean);
  if (iVar1 < 5) {
    iVar1 = 0;
  }
  else {
    iVar1 = Q_atoi(clean + 3);
    if (iVar1 < 0) {
      return false;
    }
    if (wad->lumpCount <= iVar1) {
      return false;
    }
    iVar1 = iVar1 << 5;
  }
  lump = (lumpinfo_t *)(wad->lumps->name + iVar1 + -0x10);
  data = Cache_Alloc(&pic->cache,wad->cacheExtra + lump->size + 1,clean);
  if (data == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Draw_CacheGet: not enough space for %s in %s",clean,wad->name);
  }
  data[wad->cacheExtra + lump->size] = '\0';
  Q_memcpy(data + wad->cacheExtra,(void *)((int)raw + lump->filepos),lump->size);
  qVar2 = Draw_ValidateCustomLogo(wad,data,lump);
  if (qVar2 == false) {
    return false;
  }
  gfCustomBuild = true;
  Q_strcpy(szCustName,"T");
  Q_memcpy(szCustName + 1,clean,5);
  szCustName[6] = '\0';
  if (wad->pfnCacheBuild != (PFNCACHE)0x0) {
    (*wad->pfnCacheBuild)(wad,data);
  }
  gfCustomBuild = false;
  return true;
}


// Draw_CachePic  @ 00159390
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


// Draw_CacheReload  @ 000aa7b0
qboolean Draw_CacheReload(cachewad_t *wad,int i,lumpinfo_t *pLump,cacheentry_t *pic,char *clean,
                         char *path)

{
  FileHandle_t file;
  byte *pbVar1;
  qboolean qVar2;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: byte * buf@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  if (wad->numpaths < 1) {
    file = FS_Open(wad->name,"rb");
  }
  else {
                    /* Unresolved local var: char * pathID@[???] */
    file = FS_OpenPathID(wad->name,"rb",wad->basedirs[wad->lumppathindices[i]]);
  }
  if (file == (FileHandle_t)0x0) {
    qVar2 = false;
  }
  else {
    FS_Size(file);
    if (wad->tempWad == 0) {
      pbVar1 = Cache_Alloc(&pic->cache,wad->cacheExtra + pLump->size + 1,clean);
    }
    else {
      pbVar1 = Hunk_TempAlloc(wad->cacheExtra + pLump->size + 1);
      (pic->cache).data = pbVar1;
    }
    if (pbVar1 == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Draw_CacheGet: not enough space for %s in %s",path,wad->name);
    }
    pbVar1[wad->cacheExtra + pLump->size] = '\0';
    FS_Seek(file,pLump->filepos,FILESYSTEM_SEEK_HEAD);
    FS_Read(pbVar1 + wad->cacheExtra,pLump->size,1,file);
    FS_Close(file);
    if (wad->pfnCacheBuild == (PFNCACHE)0x0) {
      qVar2 = true;
    }
    else {
      (*wad->pfnCacheBuild)(wad,pbVar1);
      qVar2 = true;
    }
  }
  return qVar2;
}


// Draw_CacheWadHandler  @ 000a98a0
void Draw_CacheWadHandler(cachewad_t *wad,PFNCACHE fn,int extraDataSize)

{
  wad->pfnCacheBuild = fn;
  wad->cacheExtra = extraDataSize;
  return;
}


// Draw_CacheWadInit  @ 000a95f0
void Draw_CacheWadInit(char *name,int cacheMax,cachewad_t *wad)

{
  FileHandle_t file;
  uint len;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  file = FS_Open(name,"rb");
  if (file != (FileHandle_t)0x0) {
    len = FS_Size(file);
    Draw_CacheWadInitFromFile(file,len,name,cacheMax,wad);
    FS_Close(file);
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Draw_LoadWad: Couldn\'t open %s\n",name);
}


// Draw_CacheWadInitFromFile  @ 000a94a0
void Draw_CacheWadInitFromFile(FileHandle_t hFile,int len,char *name,int cacheMax,cachewad_t *wad)

{
  lumpinfo_s *plVar1;
  char *pcVar2;
  cacheentry_t *dest;
  int iVar3;
  int in_GS_OFFSET;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
                    /* Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: wadinfo_t header@[???]
                       Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  FS_Read(&local_2c,0xc,1,hFile);
  if (local_2c != 0x33444157) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Wad file %s doesn\'t have WAD3 id\n",name);
  }
  plVar1 = Mem_Malloc(len - local_24);
  wad->lumps = plVar1;
  FS_Seek(hFile,local_24,FILESYSTEM_SEEK_HEAD);
  FS_Read(wad->lumps,len - local_24,1,hFile);
  if (0 < local_28) {
    iVar3 = 0;
    pcVar2 = wad->lumps->name;
    do {
      iVar3 = iVar3 + 1;
      W_CleanupName(pcVar2,pcVar2);
      pcVar2 = pcVar2 + 0x20;
    } while (iVar3 < local_28);
  }
  wad->lumpCount = local_28;
  wad->cacheCount = 0;
  wad->cacheMax = cacheMax;
  pcVar2 = Mem_Strdup(name);
                    /* Unresolved local var: int len@[???] */
  wad->name = pcVar2;
  dest = Mem_Malloc(cacheMax * 0x44);
  wad->cache = dest;
  Q_memset(dest,0,cacheMax * 0x44);
  iVar3 = *(int *)(in_GS_OFFSET + 0x14);
  wad->tempWad = 0;
  wad->pfnCacheBuild = (PFNCACHE)0x0;
  wad->cacheExtra = 0;
  if (local_20 == iVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_CenterPic  @ 0017af70
void Draw_CenterPic(qpic_t *pPic)

{
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  Draw_Pic(glwidth / 2 - pPic->width / 2,glheight / 2 - pPic->height / 2,pPic);
  return;
}


// Draw_CharToConback  @ 001593f0
void Draw_CharToConback(int num,byte *dest)

{
  return;
}


// Draw_Character  @ 00159530
int Draw_Character(int x,int y,int num,uint font)

{
  ISurface *pIVar1;
  int iVar2;
  int iStack_18;
  int iStack_14;
  int aiStack_10 [2];
  
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x19])
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
  return iStack_14 + iStack_18 + aiStack_10[0];
}


// Draw_ConsoleBackground  @ 0015aeb0
void Draw_ConsoleBackground(int lines)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_GS_OFFSET;
  int local_80;
  int local_7c;
  int local_78;
  char local_74 [100];
  int local_10;
  
                    /* Unresolved local var: char[100] ver@[???]
                       Unresolved local var: int x@[???] */
  iVar3 = glwidth;
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = lines - glheight;
  (*qglDisable)(0xde1);
  (*qglDisable)(0xbe2);
  (*qglDisable)(0xbc0);
  (*qglColor4f)(0.0,0.0,0.0,1.0);
  (*qglBegin)(7);
  (*qglVertex2f)(0.0,(float)iVar2);
  (*qglVertex2f)((float)iVar3,(float)iVar2);
  (*qglVertex2f)((float)iVar3,(float)lines);
  (*qglVertex2f)(0.0,(float)lines);
  (*qglEnd)();
  (*qglEnable)(0xde1);
  (*qglEnable)(0xbc0);
  iVar3 = build_number();
  __snprintf_chk(local_74,100,1,100,"Half-Life %i/%s (hw build %d)",0x30,gpszVersionString,iVar3);
  uVar1 = vid.conwidth;
  uVar4 = VGUI2_GetConsoleFont();
  iVar3 = VGUI2_Draw_StringLen(local_74,uVar4);
  if ((console.value != 0.0) && (((byte)giSubState & 4) == 0)) {
                    /* Unresolved local var: int wide@[???] */
    uVar4 = VGUI2_GetConsoleFont();
    VGUI2_DrawString(uVar1 - iVar3,0,local_74,uVar4);
                    /* Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: int num@[???] */
    iVar3 = __isoc99_sscanf(con_color.string,"%i %i %i",&local_80,&local_7c,&local_78);
    if (iVar3 == 3) {
      VGUI2_Draw_SetTextColor(local_80,local_7c,local_78);
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Draw_CustomCacheGet  @ 000aaea0
void * Draw_CustomCacheGet(cachewad_t *wad,void *raw,int rawsize,int index)

{
  void *pvVar1;
  char *pcVar2;
  qboolean qVar3;
  cacheentry_t *pic;
  int in_GS_OFFSET;
  char local_40 [16];
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (wad->cacheCount <= index) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Cache wad indexed before load %s: %d",wad->name,index);
  }
  pic = wad->cache + index;
  pvVar1 = Cache_Check(&pic->cache);
  if (pvVar1 == (void *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???] */
    pcVar2 = COM_FileBase_s(pic->name,local_40,0x10);
    if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pic);
    }
    W_CleanupName(local_40,local_30);
    qVar3 = Draw_CacheLoadFromCustom(local_30,wad,raw,rawsize,pic);
    if (qVar3 == false) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = (pic->cache).data;
      if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Draw_CacheGet: failed to load %s",pic);
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar1;
}


// Draw_CustomCacheWadInit  @ 000a9680
qboolean Draw_CustomCacheWadInit(int cacheMax,cachewad_t *wad,void *raw,int nFileSize)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  qboolean qVar5;
  lumpinfo_s *plVar6;
  char *pcVar7;
  cacheentry_t *dest;
  int in_GS_OFFSET;
  
                    /* Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: wadinfo_t header@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: uchar * pStart@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = *(int *)((int)raw + 8);
  if (*(int *)raw == 0x33444157) {
    if (*(int *)((int)raw + 4) == 1) {
      if (iVar2 < 1) {
        Con_Printf("Custom file has bogus infotableofs %i\n",iVar2);
        qVar5 = false;
      }
      else if (iVar2 + 0x20 == nFileSize) {
        plVar6 = Mem_Malloc(0x20);
        wad->lumps = plVar6;
        Q_memcpy(plVar6,(void *)((int)raw + iVar2),0x20);
        plVar6 = wad->lumps;
        W_CleanupName(plVar6->name,plVar6->name);
        iVar3 = plVar6->size;
        if (iVar3 == plVar6->disksize) {
          if (iVar3 < 1) {
            Con_Printf("Custom file has bogus lump size %i\n",iVar3);
            qVar5 = false;
          }
          else {
            uVar4 = plVar6->filepos;
            if (uVar4 < 0xc) {
              Con_Printf("Custom file has bogus lump offset %i\n",uVar4);
              qVar5 = false;
            }
            else if (iVar2 < (int)(uVar4 + iVar3)) {
              Con_Printf("Custom file has bogus lump %i\n",0);
              qVar5 = false;
            }
            else {
              wad->lumpCount = 1;
              wad->cacheCount = 0;
              wad->cacheMax = cacheMax;
              pcVar7 = Mem_Strdup("tempdecal.wad");
              wad->name = pcVar7;
                    /* Unresolved local var: int len@[???] */
              dest = Mem_Malloc(cacheMax * 0x44);
              wad->cache = dest;
              Q_memset(dest,0,cacheMax * 0x44);
              qVar5 = true;
              wad->tempWad = 0;
              wad->pfnCacheBuild = (PFNCACHE)0x0;
              wad->cacheExtra = 0;
            }
          }
        }
        else {
          Con_Printf("Custom file has mismatched lump size ( %i vs. %i )\n",iVar3,plVar6->disksize);
          qVar5 = false;
        }
      }
      else {
        Con_Printf("Custom file has bogus infotableofs ( %i > %i )\n",iVar2 + 0x20,nFileSize);
        qVar5 = false;
      }
    }
    else {
      Con_Printf("Custom file has wrong number of lumps %i\n",*(int *)((int)raw + 4));
      qVar5 = false;
    }
  }
  else {
    Con_Printf("Custom file doesn\'t have WAD3 id\n");
    qVar5 = false;
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_DebugChar  @ 001595e0
void Draw_DebugChar(char num)

{
  return;
}


// Draw_DecalCount  @ 000a9bf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Draw_DecalCount(void)

{
  if (decal_wad != (cachewad_t *)0x0) {
    return decal_wad->lumpCount;
  }
  return 0;
}


// Draw_DecalIndex  @ 000a9a80
int Draw_DecalIndex(int id)

{
  cachewad_t *pcVar1;
  qboolean qVar2;
  int iVar3;
  int iVar4;
  cacheentry_t *s2;
  char (*s1) [16];
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: char[32] tmp@[???]
                       Unresolved local var: char * pName@[???]
                       Unresolved local var: cvar_t violence_hblood@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (decal_names[id][0] == '\0') {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Used decal #%d without a name\n",id);
  }
  qVar2 = Host_IsServerActive();
  s1 = decal_names + id;
  if (((qVar2 == false) && (violence_hblood.value == 0.0)) &&
     (iVar3 = Q_strncmp(*s1,"{blood",6), iVar3 == 0)) {
    s1 = (char (*) [16])local_40;
    __snprintf_chk(s1,0x20,1,0x20,0x256c83,id * 0x10 + 0x95b646);
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
  if (iVar4 == iVar3) {
    if (pcVar1->cacheMax == iVar4) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Cache wad (%s) out of %d entries",pcVar1->name,iVar4);
    }
    pcVar1->cacheCount = iVar4 + 1;
    Q_strncpy(s2->name,*s1,0x3f);
    s2->name[0x3f] = '\0';
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_DecalIndexFromName  @ 000a9d70
int Draw_DecalIndexFromName(char *name)

{
  int iVar1;
  char (*s2) [16];
  int iVar2;
  int in_GS_OFFSET;
  char local_20 [15];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[16] tmpName@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_strncpy(local_20,name,0xf);
  local_11 = 0;
  if (local_20[0] == '}') {
    local_20[0] = '{';
  }
  s2 = decal_names;
  iVar2 = 0;
  do {
    if (((*s2)[0] != '\0') && (iVar1 = Q_strcmp(local_20,*s2), iVar1 == 0)) goto LAB_000a9ddb;
    iVar2 = iVar2 + 1;
    s2 = s2 + 1;
  } while (iVar2 != 0x200);
  iVar2 = 0;
LAB_000a9ddb:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


// Draw_DecalName  @ 000a9c40
char * Draw_DecalName(int number)

{
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    return decal_wad->lumps[number].name;
  }
  return (char *)0x0;
}


// Draw_DecalSetName  @ 000a9a40
void Draw_DecalSetName(int decal,char *name)

{
  if (decal < 0x200) {
    Q_strncpy(decal_names[decal],name,0xf);
    decal_names[decal][0xf] = '\0';
  }
  return;
}


// Draw_DecalShutdown  @ 000a9a10
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


// Draw_DecalSize  @ 000a9c10
int Draw_DecalSize(int number)

{
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    return decal_wad->lumps[number].size;
  }
  return 0;
}


// Draw_DecalTexture  @ 000aaff0
texture_t * Draw_DecalTexture(int index)

{
  customization_s *pcVar1;
  cachewad_t *wad;
  void *raw;
  int iVar2;
  int rawsize;
  texture_t *ptVar3;
  uint uVar4;
  char *pcVar5;
  qboolean qVar6;
  cacheentry_t *pic;
  int in_GS_OFFSET;
  char local_40 [16];
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: int playernum@[???]
                       Unresolved local var: customization_t * pCust@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (index < 0) {
    uVar4 = ~index;
    pcVar1 = cl.players[uVar4].customdata.pNext;
    if ((((pcVar1 == (customization_s *)0x0) || (pcVar1->bInUse == false)) ||
        (wad = pcVar1->pInfo, wad == (cachewad_t *)0x0)) ||
       (raw = pcVar1->pBuffer, raw == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Failed to load custom decal for player #%i:%s using default decal 0.\n",uVar4,
                uVar4 * 0x250 + 0xde5464);
    }
                    /* Unresolved local var: texture_t * retval@[???] */
    iVar2 = pcVar1->nUserData1;
                    /* Unresolved local var: cacheentry_t * pic@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
    rawsize = (pcVar1->resource).nDownloadSize;
    if (wad->cacheCount <= iVar2) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Cache wad indexed before load %s: %d",wad->name,iVar2);
    }
    pic = wad->cache + iVar2;
    ptVar3 = Cache_Check(&pic->cache);
    if (ptVar3 == (texture_t *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???] */
      pcVar5 = COM_FileBase_s(pic->name,local_40,0x10);
      if (pcVar5 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pic);
      }
      W_CleanupName(local_40,local_30);
      qVar6 = Draw_CacheLoadFromCustom(local_30,wad,raw,rawsize,pic);
      if (qVar6 == false) {
        ptVar3 = Draw_CacheGet(decal_wad,0);
      }
      else {
        ptVar3 = (pic->cache).data;
        if (ptVar3 == (texture_t *)0x0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Draw_CacheGet: failed to load %s",pic);
        }
      }
    }
  }
  else {
    ptVar3 = Draw_CacheGet(decal_wad,index);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return ptVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_EndDisc  @ 0015b5e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_EndDisc(void)

{
  return;
}


// Draw_FadeScreen  @ 0015b4d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_FadeScreen(void)

{
  (*qglEnable)(0xbe2);
  (*qglDisable)(0xde1);
  (*qglColor4f)(0.0,0.0,0.0,0.8);
  (*qglBegin)(7);
  (*qglVertex2f)(0.0,0.0);
  (*qglVertex2f)((float)glwidth,0.0);
  (*qglVertex2f)((float)glwidth,(float)glheight);
  (*qglVertex2f)(0.0,(float)glheight);
  (*qglEnd)();
  (*qglColor4f)(1.0,1.0,1.0,1.0);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  return;
}


// Draw_Fill  @ 0015b470
void Draw_Fill(int x,int y,int w,int h,int c)

{
  Draw_FillRGBA(x,y,w,h,(uint)host_basepal[c * 4],(uint)host_basepal[c * 4 + 1],
                (uint)host_basepal[c * 4 + 2],0xff);
  return;
}


// Draw_FillRGBA  @ 0015b0e0
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
  (*qglVertex2f)((float)(w + x),(float)y);
  (*qglVertex2f)((float)(w + x),(float)(h + y));
  (*qglVertex2f)((float)x,(float)(h + y));
  (*qglEnd)();
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  return;
}


// Draw_FillRGBABlend  @ 0015b280
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
  (*qglVertex2f)((float)(w + x),(float)y);
  (*qglVertex2f)((float)(w + x),(float)(h + y));
  (*qglVertex2f)((float)x,(float)(h + y));
  (*qglEnd)();
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  return;
}


// Draw_Frame  @ 0015a900
void Draw_Frame(mspriteframe_t *pFrame,int ix,int iy,wrect_t *prcSubRect)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  GLfloat local_40;
  GLfloat local_3c;
  GLfloat local_30;
  GLfloat local_2c;
  int local_28;
  
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float fLeft@[???]
                       Unresolved local var: float fRight@[???]
                       Unresolved local var: float fTop@[???]
                       Unresolved local var: float fBottom@[???]
                       Unresolved local var: int iWidth@[???]
                       Unresolved local var: int iHeight@[???] */
  fVar2 = (float)ix + 0.5;
  local_28 = pFrame->height;
  iVar8 = pFrame->width;
  fVar3 = (float)iy + 0.5;
  VGUI2_ResetCurrentTexture();
  if (giScissorTest != false) {
    (*qglScissor)(scissor_x,scissor_y,scissor_width,scissor_height);
    (*qglEnable)(0xc11);
  }
  if (prcSubRect == (wrect_t *)0x0) {
    local_3c = 1.0;
    local_40 = 0.0;
    local_30 = 1.0;
    local_2c = 0.0;
    goto LAB_0015a981;
  }
                    /* Unresolved local var: wrect_t rc@[???]
                       Unresolved local var: float f@[???] */
  iVar4 = prcSubRect->left;
  iVar7 = prcSubRect->right;
  if (iVar4 < iVar7) {
    iVar1 = prcSubRect->top;
    iVar9 = prcSubRect->bottom;
    if (iVar9 <= iVar1) {
      local_3c = 1.0;
      local_40 = 0.0;
      local_30 = 1.0;
      local_2c = 0.0;
      goto LAB_0015a981;
    }
                    /* Unresolved local var: wrect_t rc@[???]
                       Unresolved local var: float f@[???] */
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (iVar8 <= iVar7) {
      iVar7 = iVar8;
    }
    if (iVar4 < iVar7) {
      iVar5 = 0;
      if (-1 < iVar1) {
        iVar5 = iVar1;
      }
      if (local_28 <= iVar9) {
        iVar9 = local_28;
      }
      if (iVar5 < iVar9) {
        local_28 = iVar9 - iVar5;
        iVar8 = iVar7 - iVar4;
        local_30 = 1.0 / (float)pFrame->width;
        local_2c = ((float)iVar4 + 0.5) * local_30;
        local_30 = ((float)iVar7 - 0.5) * local_30;
        local_3c = 1.0 / (float)pFrame->height;
        local_40 = ((float)iVar5 + 0.5) * local_3c;
        local_3c = local_3c * ((float)iVar9 - 0.5);
      }
      else {
        local_3c = 1.0;
        local_40 = 0.0;
        local_30 = 1.0;
        local_2c = 0.0;
      }
      goto LAB_0015a981;
    }
  }
  local_3c = 1.0;
  local_40 = 0.0;
  local_30 = 1.0;
  local_2c = 0.0;
LAB_0015a981:
  (*qglDepthMask)('\0');
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar6 = pFrame->gl_texturenum & 0xffff;
  if (uVar6 != currenttexture) {
    iVar4 = (pFrame->gl_texturenum >> 0x10) + -1;
    currenttexture = uVar6;
    (*qglBindTexture)(0xde1,uVar6);
    if (((-1 < iVar4) && (iVar4 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar4;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar4].colors);
    }
  }
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBegin)(7);
  (*qglTexCoord2f)(local_2c,local_40);
  (*qglVertex2f)(fVar2,fVar3);
  (*qglTexCoord2f)(local_30,local_40);
  (*qglVertex2f)((float)iVar8 + fVar2,fVar3);
  (*qglTexCoord2f)(local_30,local_3c);
  (*qglVertex2f)((float)iVar8 + fVar2,(float)local_28 + fVar3);
  (*qglTexCoord2f)(local_2c,local_3c);
  (*qglVertex2f)(fVar2,(float)local_28 + fVar3);
  (*qglEnd)();
  (*qglDepthMask)('\x01');
                    /* WARNING: Could not recover jumptable at 0x0015ab4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglDisable)(0xc11);
  return;
}


// Draw_FreeWad  @ 000a98c0
void Draw_FreeWad(cachewad_t *pWad)

{
  void *pvVar1;
  cacheentry_t *p;
  cache_user_t *c;
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
        c = &p->cache;
        iVar3 = 0;
        do {
          pvVar1 = Cache_Check(c);
          if (pvVar1 != (void *)0x0) {
            Cache_Free(c);
          }
          iVar3 = iVar3 + 1;
          c = c + 0x11;
        } while (iVar3 < pWad->cacheCount);
        p = pWad->cache;
      }
      Mem_Free(p);
      return;
    }
  }
  return;
}


// Draw_GetDefaultColor  @ 001594d0
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


// Draw_Init  @ 00160b60
/* WARNING: Removing unreachable block (ram,0x00161813) */
/* WARNING: Removing unreachable block (ram,0x001617f5) */
/* WARNING: Removing unreachable block (ram,0x001617d7) */
/* WARNING: Removing unreachable block (ram,0x001617b9) */
/* WARNING: Removing unreachable block (ram,0x0016179b) */
/* WARNING: Removing unreachable block (ram,0x0016177d) */
/* WARNING: Removing unreachable block (ram,0x00160dbe) */
/* WARNING: Removing unreachable block (ram,0x00160cde) */
/* WARNING: Removing unreachable block (ram,0x00160cee) */
/* WARNING: Removing unreachable block (ram,0x00160cfe) */
/* WARNING: Removing unreachable block (ram,0x00160d0e) */
/* WARNING: Removing unreachable block (ram,0x00160d1e) */
/* WARNING: Removing unreachable block (ram,0x00160d2e) */
/* WARNING: Removing unreachable block (ram,0x00160d3e) */
/* WARNING: Removing unreachable block (ram,0x00160d4e) */
/* WARNING: Removing unreachable block (ram,0x00160d5e) */
/* WARNING: Removing unreachable block (ram,0x00160d6e) */
/* WARNING: Removing unreachable block (ram,0x00160d7e) */
/* WARNING: Removing unreachable block (ram,0x00160d8e) */
/* WARNING: Removing unreachable block (ram,0x00160d9e) */
/* WARNING: Removing unreachable block (ram,0x00160dae) */
/* WARNING: Removing unreachable block (ram,0x0016175f) */
/* WARNING: Removing unreachable block (ram,0x0016176e) */
/* WARNING: Removing unreachable block (ram,0x0016178c) */
/* WARNING: Removing unreachable block (ram,0x001617aa) */
/* WARNING: Removing unreachable block (ram,0x001617c8) */
/* WARNING: Removing unreachable block (ram,0x001617e6) */
/* WARNING: Removing unreachable block (ram,0x00161804) */
/* WARNING: Removing unreachable block (ram,0x00161822) */
/* WARNING: Removing unreachable block (ram,0x00160dcf) */
/* WARNING: Removing unreachable block (ram,0x001615cb) */
/* WARNING: Removing unreachable block (ram,0x001615dd) */
/* WARNING: Removing unreachable block (ram,0x001615ef) */
/* WARNING: Removing unreachable block (ram,0x00161601) */
/* WARNING: Removing unreachable block (ram,0x00161613) */
/* WARNING: Removing unreachable block (ram,0x00161625) */
/* WARNING: Removing unreachable block (ram,0x00161633) */
/* WARNING: Removing unreachable block (ram,0x00161641) */
/* WARNING: Removing unreachable block (ram,0x0016164f) */
/* WARNING: Removing unreachable block (ram,0x0016165d) */
/* WARNING: Removing unreachable block (ram,0x0016166b) */
/* WARNING: Removing unreachable block (ram,0x00161679) */
/* WARNING: Removing unreachable block (ram,0x00161687) */
/* WARNING: Removing unreachable block (ram,0x00161695) */
/* WARNING: Removing unreachable block (ram,0x001616a3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_Init(void)

{
  ushort uVar1;
  short sVar2;
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
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  GL_PALETTE *pGVar67;
  GL_PALETTE *pGVar68;
  qpic_t *ppic;
  int iVar69;
  undefined1 auVar70 [16];
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  undefined1 auVar81 [16];
  undefined1 auVar82 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar93 [16];
  undefined1 auVar94 [16];
  undefined1 auVar97 [16];
  undefined1 auVar98 [16];
  undefined1 auVar101 [16];
  undefined1 auVar102 [16];
  undefined1 auVar105 [16];
  undefined1 auVar106 [16];
  undefined1 auVar109 [16];
  undefined1 auVar110 [16];
  undefined1 auVar113 [16];
  undefined1 auVar114 [16];
  undefined1 auVar117 [16];
  undefined1 auVar118 [16];
  undefined1 auVar121 [16];
  undefined1 auVar122 [16];
  undefined1 auVar125 [16];
  undefined1 auVar126 [16];
  undefined1 auVar129 [16];
  undefined1 auVar130 [16];
  undefined1 auVar133 [16];
  undefined1 auVar134 [16];
  undefined1 auVar137 [16];
  undefined1 auVar138 [16];
  undefined1 auVar141 [16];
  undefined1 auVar142 [16];
  undefined1 auVar145 [16];
  undefined1 auVar146 [16];
  undefined1 auVar149 [16];
  undefined1 auVar150 [16];
  undefined1 auVar153 [16];
  undefined1 auVar154 [16];
  undefined1 auVar157 [16];
  undefined1 auVar158 [16];
  undefined1 auVar161 [16];
  undefined1 auVar162 [16];
  undefined1 auVar165 [16];
  undefined1 auVar166 [16];
  undefined1 auVar169 [16];
  undefined1 auVar170 [16];
  undefined1 auVar173 [16];
  undefined1 auVar174 [16];
  undefined1 auVar177 [16];
  undefined1 auVar178 [16];
  undefined1 auVar181 [16];
  undefined1 auVar182 [16];
  undefined1 auVar185 [16];
  undefined1 auVar186 [16];
  undefined1 auVar189 [16];
  undefined1 auVar190 [16];
  undefined1 auVar193 [16];
  undefined1 auVar194 [16];
  undefined1 auVar197 [16];
  int local_28;
  int local_24;
  int local_20 [4];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar75 [16];
  undefined1 auVar79 [16];
  undefined1 auVar83 [16];
  undefined1 auVar87 [16];
  undefined1 auVar91 [16];
  undefined1 auVar95 [16];
  undefined1 auVar99 [16];
  undefined1 auVar103 [16];
  undefined1 auVar107 [16];
  undefined1 auVar111 [16];
  undefined1 auVar115 [16];
  undefined1 auVar119 [16];
  undefined1 auVar123 [16];
  undefined1 auVar127 [16];
  undefined1 auVar131 [16];
  undefined1 auVar76 [16];
  undefined1 auVar80 [16];
  undefined1 auVar84 [16];
  undefined1 auVar88 [16];
  undefined1 auVar92 [16];
  undefined1 auVar96 [16];
  undefined1 auVar100 [16];
  undefined1 auVar104 [16];
  undefined1 auVar108 [16];
  undefined1 auVar112 [16];
  undefined1 auVar116 [16];
  undefined1 auVar120 [16];
  undefined1 auVar124 [16];
  undefined1 auVar128 [16];
  undefined1 auVar132 [16];
  undefined1 auVar135 [16];
  undefined1 auVar139 [16];
  undefined1 auVar143 [16];
  undefined1 auVar147 [16];
  undefined1 auVar151 [16];
  undefined1 auVar155 [16];
  undefined1 auVar159 [16];
  undefined1 auVar163 [16];
  undefined1 auVar167 [16];
  undefined1 auVar171 [16];
  undefined1 auVar175 [16];
  undefined1 auVar179 [16];
  undefined1 auVar183 [16];
  undefined1 auVar187 [16];
  undefined1 auVar191 [16];
  undefined1 auVar136 [16];
  undefined1 auVar140 [16];
  undefined1 auVar144 [16];
  undefined1 auVar148 [16];
  undefined1 auVar152 [16];
  undefined1 auVar156 [16];
  undefined1 auVar160 [16];
  undefined1 auVar164 [16];
  undefined1 auVar168 [16];
  undefined1 auVar172 [16];
  undefined1 auVar176 [16];
  undefined1 auVar180 [16];
  undefined1 auVar184 [16];
  undefined1 auVar188 [16];
  undefined1 auVar192 [16];
  undefined1 auVar195 [16];
  undefined1 auVar196 [16];
  
                    /* Unresolved local var: int i@[???] */
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
  (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  pGVar67 = gGLPalette;
  do {
                    /* Unresolved local var: int i@[???] */
    pGVar67->tag = -1;
    pGVar68 = pGVar67 + 1;
    pGVar67->referenceCount = 0;
    pGVar67 = pGVar68;
  } while (pGVar68 != (GL_PALETTE *)&DAT_00e3c850);
  menu_wad = Mem_ZeroMalloc(0x30);
  Draw_CacheWadInit("cached.wad",0x10,menu_wad);
  menu_wad->tempWad = 1;
  Draw_CacheWadHandler(&custom_wad,Draw_MiptexTexture,0x20);
  if ((qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0) &&
     (gl_palette_tex.value != 0.0)) {
    (*qglEnable)(0x81fb);
  }
  Q_memset(decal_names,0,0x2000);
  auVar3._10_6_ = 0;
  auVar3._0_10_ = (unkuint10)6;
  auVar77._12_4_ = 0;
  auVar77._0_12_ = SUB1612(auVar3 << 0x30,4);
  auVar76._0_12_ = SUB1612(auVar77 << 0x20,0);
  auVar76._12_2_ = 6;
  auVar76._14_2_ = 7;
  auVar75._12_4_ = auVar76._12_4_;
  auVar75._0_10_ = SUB1610(auVar77 << 0x20,0);
  auVar75._10_2_ = 5;
  auVar74._10_6_ = auVar75._10_6_;
  auVar74._0_10_ = (unkuint10)4 << 0x40;
  auVar66._6_8_ = auVar74._8_8_;
  auVar66._4_2_ = 3;
  auVar66._2_2_ = 2;
  auVar66._0_2_ = 1;
  auVar66._14_2_ = 0;
  auVar5._10_6_ = 0;
  auVar5._0_10_ = (unkuint10)0xe;
  auVar4._12_4_ = 0;
  auVar4._0_12_ = SUB1612(auVar5 << 0x30,4);
  auVar136._0_12_ = SUB1612(auVar4 << 0x20,0);
  auVar136._12_2_ = 0xe;
  auVar136._14_2_ = 0xf;
  auVar135._12_4_ = auVar136._12_4_;
  auVar135._0_10_ = SUB1610(auVar4 << 0x20,0);
  auVar135._10_2_ = 0xd;
  auVar134._10_6_ = auVar135._10_6_;
  auVar134._0_10_ = (unkuint10)0xc << 0x40;
  auVar137._8_8_ = auVar134._8_8_;
  auVar137._6_2_ = 0xb;
  auVar137._4_2_ = 10;
  auVar137._0_4_ = 0x90008;
  auVar77 = auVar66 << 0x10 & _DAT_00267f50;
  auVar137 = auVar137 & _DAT_00267f50;
  texgammatable[0] = '\0';
  uVar1 = auVar77._2_2_;
  texgammatable[1] = (uVar1 != 0) * (uVar1 < 0x100) * auVar77[2] - (0xff < uVar1);
  uVar1 = auVar77._4_2_;
  texgammatable[2] = (uVar1 != 0) * (uVar1 < 0x100) * auVar77[4] - (0xff < uVar1);
  uVar1 = auVar77._6_2_;
  texgammatable[3] = (uVar1 != 0) * (uVar1 < 0x100) * auVar77[6] - (0xff < uVar1);
  sVar2 = auVar77._8_2_;
  texgammatable[4] = (0 < sVar2) * (sVar2 < 0x100) * auVar77[8] - (0xff < sVar2);
  sVar2 = auVar77._10_2_;
  texgammatable[5] = (0 < sVar2) * (sVar2 < 0x100) * auVar77[10] - (0xff < sVar2);
  sVar2 = auVar77._12_2_;
  texgammatable[6] = (0 < sVar2) * (sVar2 < 0x100) * auVar77[0xc] - (0xff < sVar2);
  sVar2 = auVar77._14_2_;
  texgammatable[7] = (0 < sVar2) * (sVar2 < 0x100) * auVar77[0xe] - (0xff < sVar2);
  uVar1 = auVar137._0_2_;
  texgammatable[8] = (uVar1 != 0) * (uVar1 < 0x100) * auVar137[0] - (0xff < uVar1);
  uVar1 = auVar137._2_2_;
  texgammatable[9] = (uVar1 != 0) * (uVar1 < 0x100) * auVar137[2] - (0xff < uVar1);
  uVar1 = auVar137._4_2_;
  texgammatable[10] = (uVar1 != 0) * (uVar1 < 0x100) * auVar137[4] - (0xff < uVar1);
  uVar1 = auVar137._6_2_;
  texgammatable[0xb] = (uVar1 != 0) * (uVar1 < 0x100) * auVar137[6] - (0xff < uVar1);
  sVar2 = auVar137._8_2_;
  texgammatable[0xc] = (0 < sVar2) * (sVar2 < 0x100) * auVar137[8] - (0xff < sVar2);
  sVar2 = auVar137._10_2_;
  texgammatable[0xd] = (0 < sVar2) * (sVar2 < 0x100) * auVar137[10] - (0xff < sVar2);
  sVar2 = auVar137._12_2_;
  texgammatable[0xe] = (0 < sVar2) * (sVar2 < 0x100) * auVar137[0xc] - (0xff < sVar2);
  sVar2 = auVar137._14_2_;
  texgammatable[0xf] = (0 < sVar2) * (sVar2 < 0x100) * auVar137[0xe] - (0xff < sVar2);
  auVar7._10_6_ = 0;
  auVar7._0_10_ = (unkuint10)0x16;
  auVar6._12_4_ = 0;
  auVar6._0_12_ = SUB1612(auVar7 << 0x30,4);
  auVar80._0_12_ = SUB1612(auVar6 << 0x20,0);
  auVar80._12_2_ = 0x16;
  auVar80._14_2_ = 0x17;
  auVar79._12_4_ = auVar80._12_4_;
  auVar79._0_10_ = SUB1610(auVar6 << 0x20,0);
  auVar79._10_2_ = 0x15;
  auVar78._10_6_ = auVar79._10_6_;
  auVar78._0_10_ = (unkuint10)0x14 << 0x40;
  auVar81._8_8_ = auVar78._8_8_;
  auVar81._6_2_ = 0x13;
  auVar81._4_2_ = 0x12;
  auVar81._0_4_ = 0x110010;
  auVar81 = auVar81 & _DAT_00267f50;
  auVar9._10_6_ = 0;
  auVar9._0_10_ = (unkuint10)0x1e;
  auVar8._12_4_ = 0;
  auVar8._0_12_ = SUB1612(auVar9 << 0x30,4);
  auVar140._0_12_ = SUB1612(auVar8 << 0x20,0);
  auVar140._12_2_ = 0x1e;
  auVar140._14_2_ = 0x1f;
  auVar139._12_4_ = auVar140._12_4_;
  auVar139._0_10_ = SUB1610(auVar8 << 0x20,0);
  auVar139._10_2_ = 0x1d;
  auVar138._10_6_ = auVar139._10_6_;
  auVar138._0_10_ = (unkuint10)0x1c << 0x40;
  auVar141._8_8_ = auVar138._8_8_;
  auVar141._6_2_ = 0x1b;
  auVar141._4_2_ = 0x1a;
  auVar141._0_4_ = 0x190018;
  auVar141 = auVar141 & _DAT_00267f50;
  uVar1 = auVar81._0_2_;
  texgammatable[0x10] = (uVar1 != 0) * (uVar1 < 0x100) * auVar81[0] - (0xff < uVar1);
  uVar1 = auVar81._2_2_;
  texgammatable[0x11] = (uVar1 != 0) * (uVar1 < 0x100) * auVar81[2] - (0xff < uVar1);
  uVar1 = auVar81._4_2_;
  texgammatable[0x12] = (uVar1 != 0) * (uVar1 < 0x100) * auVar81[4] - (0xff < uVar1);
  uVar1 = auVar81._6_2_;
  texgammatable[0x13] = (uVar1 != 0) * (uVar1 < 0x100) * auVar81[6] - (0xff < uVar1);
  sVar2 = auVar81._8_2_;
  texgammatable[0x14] = (0 < sVar2) * (sVar2 < 0x100) * auVar81[8] - (0xff < sVar2);
  sVar2 = auVar81._10_2_;
  texgammatable[0x15] = (0 < sVar2) * (sVar2 < 0x100) * auVar81[10] - (0xff < sVar2);
  sVar2 = auVar81._12_2_;
  texgammatable[0x16] = (0 < sVar2) * (sVar2 < 0x100) * auVar81[0xc] - (0xff < sVar2);
  sVar2 = auVar81._14_2_;
  texgammatable[0x17] = (0 < sVar2) * (sVar2 < 0x100) * auVar81[0xe] - (0xff < sVar2);
  uVar1 = auVar141._0_2_;
  texgammatable[0x18] = (uVar1 != 0) * (uVar1 < 0x100) * auVar141[0] - (0xff < uVar1);
  uVar1 = auVar141._2_2_;
  texgammatable[0x19] = (uVar1 != 0) * (uVar1 < 0x100) * auVar141[2] - (0xff < uVar1);
  uVar1 = auVar141._4_2_;
  texgammatable[0x1a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar141[4] - (0xff < uVar1);
  uVar1 = auVar141._6_2_;
  texgammatable[0x1b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar141[6] - (0xff < uVar1);
  sVar2 = auVar141._8_2_;
  texgammatable[0x1c] = (0 < sVar2) * (sVar2 < 0x100) * auVar141[8] - (0xff < sVar2);
  sVar2 = auVar141._10_2_;
  texgammatable[0x1d] = (0 < sVar2) * (sVar2 < 0x100) * auVar141[10] - (0xff < sVar2);
  sVar2 = auVar141._12_2_;
  texgammatable[0x1e] = (0 < sVar2) * (sVar2 < 0x100) * auVar141[0xc] - (0xff < sVar2);
  sVar2 = auVar141._14_2_;
  texgammatable[0x1f] = (0 < sVar2) * (sVar2 < 0x100) * auVar141[0xe] - (0xff < sVar2);
  auVar11._10_6_ = 0;
  auVar11._0_10_ = (unkuint10)0x26;
  auVar10._12_4_ = 0;
  auVar10._0_12_ = SUB1612(auVar11 << 0x30,4);
  auVar84._0_12_ = SUB1612(auVar10 << 0x20,0);
  auVar84._12_2_ = 0x26;
  auVar84._14_2_ = 0x27;
  auVar83._12_4_ = auVar84._12_4_;
  auVar83._0_10_ = SUB1610(auVar10 << 0x20,0);
  auVar83._10_2_ = 0x25;
  auVar82._10_6_ = auVar83._10_6_;
  auVar82._0_10_ = (unkuint10)0x24 << 0x40;
  auVar85._8_8_ = auVar82._8_8_;
  auVar85._6_2_ = 0x23;
  auVar85._4_2_ = 0x22;
  auVar85._0_4_ = 0x210020;
  auVar85 = auVar85 & _DAT_00267f50;
  auVar13._10_6_ = 0;
  auVar13._0_10_ = (unkuint10)0x2e;
  auVar12._12_4_ = 0;
  auVar12._0_12_ = SUB1612(auVar13 << 0x30,4);
  auVar144._0_12_ = SUB1612(auVar12 << 0x20,0);
  auVar144._12_2_ = 0x2e;
  auVar144._14_2_ = 0x2f;
  auVar143._12_4_ = auVar144._12_4_;
  auVar143._0_10_ = SUB1610(auVar12 << 0x20,0);
  auVar143._10_2_ = 0x2d;
  auVar142._10_6_ = auVar143._10_6_;
  auVar142._0_10_ = (unkuint10)0x2c << 0x40;
  auVar145._8_8_ = auVar142._8_8_;
  auVar145._6_2_ = 0x2b;
  auVar145._4_2_ = 0x2a;
  auVar145._0_4_ = 0x290028;
  auVar145 = auVar145 & _DAT_00267f50;
  uVar1 = auVar85._0_2_;
  texgammatable[0x20] = (uVar1 != 0) * (uVar1 < 0x100) * auVar85[0] - (0xff < uVar1);
  uVar1 = auVar85._2_2_;
  texgammatable[0x21] = (uVar1 != 0) * (uVar1 < 0x100) * auVar85[2] - (0xff < uVar1);
  uVar1 = auVar85._4_2_;
  texgammatable[0x22] = (uVar1 != 0) * (uVar1 < 0x100) * auVar85[4] - (0xff < uVar1);
  uVar1 = auVar85._6_2_;
  texgammatable[0x23] = (uVar1 != 0) * (uVar1 < 0x100) * auVar85[6] - (0xff < uVar1);
  sVar2 = auVar85._8_2_;
  texgammatable[0x24] = (0 < sVar2) * (sVar2 < 0x100) * auVar85[8] - (0xff < sVar2);
  sVar2 = auVar85._10_2_;
  texgammatable[0x25] = (0 < sVar2) * (sVar2 < 0x100) * auVar85[10] - (0xff < sVar2);
  sVar2 = auVar85._12_2_;
  texgammatable[0x26] = (0 < sVar2) * (sVar2 < 0x100) * auVar85[0xc] - (0xff < sVar2);
  sVar2 = auVar85._14_2_;
  texgammatable[0x27] = (0 < sVar2) * (sVar2 < 0x100) * auVar85[0xe] - (0xff < sVar2);
  uVar1 = auVar145._0_2_;
  texgammatable[0x28] = (uVar1 != 0) * (uVar1 < 0x100) * auVar145[0] - (0xff < uVar1);
  uVar1 = auVar145._2_2_;
  texgammatable[0x29] = (uVar1 != 0) * (uVar1 < 0x100) * auVar145[2] - (0xff < uVar1);
  uVar1 = auVar145._4_2_;
  texgammatable[0x2a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar145[4] - (0xff < uVar1);
  uVar1 = auVar145._6_2_;
  texgammatable[0x2b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar145[6] - (0xff < uVar1);
  sVar2 = auVar145._8_2_;
  texgammatable[0x2c] = (0 < sVar2) * (sVar2 < 0x100) * auVar145[8] - (0xff < sVar2);
  sVar2 = auVar145._10_2_;
  texgammatable[0x2d] = (0 < sVar2) * (sVar2 < 0x100) * auVar145[10] - (0xff < sVar2);
  sVar2 = auVar145._12_2_;
  texgammatable[0x2e] = (0 < sVar2) * (sVar2 < 0x100) * auVar145[0xc] - (0xff < sVar2);
  sVar2 = auVar145._14_2_;
  texgammatable[0x2f] = (0 < sVar2) * (sVar2 < 0x100) * auVar145[0xe] - (0xff < sVar2);
  auVar15._10_6_ = 0;
  auVar15._0_10_ = (unkuint10)0x36;
  auVar14._12_4_ = 0;
  auVar14._0_12_ = SUB1612(auVar15 << 0x30,4);
  auVar88._0_12_ = SUB1612(auVar14 << 0x20,0);
  auVar88._12_2_ = 0x36;
  auVar88._14_2_ = 0x37;
  auVar87._12_4_ = auVar88._12_4_;
  auVar87._0_10_ = SUB1610(auVar14 << 0x20,0);
  auVar87._10_2_ = 0x35;
  auVar86._10_6_ = auVar87._10_6_;
  auVar86._0_10_ = (unkuint10)0x34 << 0x40;
  auVar89._8_8_ = auVar86._8_8_;
  auVar89._6_2_ = 0x33;
  auVar89._4_2_ = 0x32;
  auVar89._0_4_ = 0x310030;
  auVar89 = auVar89 & _DAT_00267f50;
  auVar17._10_6_ = 0;
  auVar17._0_10_ = (unkuint10)0x3e;
  auVar16._12_4_ = 0;
  auVar16._0_12_ = SUB1612(auVar17 << 0x30,4);
  auVar148._0_12_ = SUB1612(auVar16 << 0x20,0);
  auVar148._12_2_ = 0x3e;
  auVar148._14_2_ = 0x3f;
  auVar147._12_4_ = auVar148._12_4_;
  auVar147._0_10_ = SUB1610(auVar16 << 0x20,0);
  auVar147._10_2_ = 0x3d;
  auVar146._10_6_ = auVar147._10_6_;
  auVar146._0_10_ = (unkuint10)0x3c << 0x40;
  auVar149._8_8_ = auVar146._8_8_;
  auVar149._6_2_ = 0x3b;
  auVar149._4_2_ = 0x3a;
  auVar149._0_4_ = 0x390038;
  auVar149 = auVar149 & _DAT_00267f50;
  uVar1 = auVar89._0_2_;
  texgammatable[0x30] = (uVar1 != 0) * (uVar1 < 0x100) * auVar89[0] - (0xff < uVar1);
  uVar1 = auVar89._2_2_;
  texgammatable[0x31] = (uVar1 != 0) * (uVar1 < 0x100) * auVar89[2] - (0xff < uVar1);
  uVar1 = auVar89._4_2_;
  texgammatable[0x32] = (uVar1 != 0) * (uVar1 < 0x100) * auVar89[4] - (0xff < uVar1);
  uVar1 = auVar89._6_2_;
  texgammatable[0x33] = (uVar1 != 0) * (uVar1 < 0x100) * auVar89[6] - (0xff < uVar1);
  sVar2 = auVar89._8_2_;
  texgammatable[0x34] = (0 < sVar2) * (sVar2 < 0x100) * auVar89[8] - (0xff < sVar2);
  sVar2 = auVar89._10_2_;
  texgammatable[0x35] = (0 < sVar2) * (sVar2 < 0x100) * auVar89[10] - (0xff < sVar2);
  sVar2 = auVar89._12_2_;
  texgammatable[0x36] = (0 < sVar2) * (sVar2 < 0x100) * auVar89[0xc] - (0xff < sVar2);
  sVar2 = auVar89._14_2_;
  texgammatable[0x37] = (0 < sVar2) * (sVar2 < 0x100) * auVar89[0xe] - (0xff < sVar2);
  uVar1 = auVar149._0_2_;
  texgammatable[0x38] = (uVar1 != 0) * (uVar1 < 0x100) * auVar149[0] - (0xff < uVar1);
  uVar1 = auVar149._2_2_;
  texgammatable[0x39] = (uVar1 != 0) * (uVar1 < 0x100) * auVar149[2] - (0xff < uVar1);
  uVar1 = auVar149._4_2_;
  texgammatable[0x3a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar149[4] - (0xff < uVar1);
  uVar1 = auVar149._6_2_;
  texgammatable[0x3b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar149[6] - (0xff < uVar1);
  sVar2 = auVar149._8_2_;
  texgammatable[0x3c] = (0 < sVar2) * (sVar2 < 0x100) * auVar149[8] - (0xff < sVar2);
  sVar2 = auVar149._10_2_;
  texgammatable[0x3d] = (0 < sVar2) * (sVar2 < 0x100) * auVar149[10] - (0xff < sVar2);
  sVar2 = auVar149._12_2_;
  texgammatable[0x3e] = (0 < sVar2) * (sVar2 < 0x100) * auVar149[0xc] - (0xff < sVar2);
  sVar2 = auVar149._14_2_;
  texgammatable[0x3f] = (0 < sVar2) * (sVar2 < 0x100) * auVar149[0xe] - (0xff < sVar2);
  auVar19._10_6_ = 0;
  auVar19._0_10_ = (unkuint10)0x46;
  auVar18._12_4_ = 0;
  auVar18._0_12_ = SUB1612(auVar19 << 0x30,4);
  auVar92._0_12_ = SUB1612(auVar18 << 0x20,0);
  auVar92._12_2_ = 0x46;
  auVar92._14_2_ = 0x47;
  auVar91._12_4_ = auVar92._12_4_;
  auVar91._0_10_ = SUB1610(auVar18 << 0x20,0);
  auVar91._10_2_ = 0x45;
  auVar90._10_6_ = auVar91._10_6_;
  auVar90._0_10_ = (unkuint10)0x44 << 0x40;
  auVar93._8_8_ = auVar90._8_8_;
  auVar93._6_2_ = 0x43;
  auVar93._4_2_ = 0x42;
  auVar93._0_4_ = 0x410040;
  auVar93 = auVar93 & _DAT_00267f50;
  auVar21._10_6_ = 0;
  auVar21._0_10_ = (unkuint10)0x4e;
  auVar20._12_4_ = 0;
  auVar20._0_12_ = SUB1612(auVar21 << 0x30,4);
  auVar152._0_12_ = SUB1612(auVar20 << 0x20,0);
  auVar152._12_2_ = 0x4e;
  auVar152._14_2_ = 0x4f;
  auVar151._12_4_ = auVar152._12_4_;
  auVar151._0_10_ = SUB1610(auVar20 << 0x20,0);
  auVar151._10_2_ = 0x4d;
  auVar150._10_6_ = auVar151._10_6_;
  auVar150._0_10_ = (unkuint10)0x4c << 0x40;
  auVar153._8_8_ = auVar150._8_8_;
  auVar153._6_2_ = 0x4b;
  auVar153._4_2_ = 0x4a;
  auVar153._0_4_ = 0x490048;
  auVar153 = auVar153 & _DAT_00267f50;
  uVar1 = auVar93._0_2_;
  texgammatable[0x40] = (uVar1 != 0) * (uVar1 < 0x100) * auVar93[0] - (0xff < uVar1);
  uVar1 = auVar93._2_2_;
  texgammatable[0x41] = (uVar1 != 0) * (uVar1 < 0x100) * auVar93[2] - (0xff < uVar1);
  uVar1 = auVar93._4_2_;
  texgammatable[0x42] = (uVar1 != 0) * (uVar1 < 0x100) * auVar93[4] - (0xff < uVar1);
  uVar1 = auVar93._6_2_;
  texgammatable[0x43] = (uVar1 != 0) * (uVar1 < 0x100) * auVar93[6] - (0xff < uVar1);
  sVar2 = auVar93._8_2_;
  texgammatable[0x44] = (0 < sVar2) * (sVar2 < 0x100) * auVar93[8] - (0xff < sVar2);
  sVar2 = auVar93._10_2_;
  texgammatable[0x45] = (0 < sVar2) * (sVar2 < 0x100) * auVar93[10] - (0xff < sVar2);
  sVar2 = auVar93._12_2_;
  texgammatable[0x46] = (0 < sVar2) * (sVar2 < 0x100) * auVar93[0xc] - (0xff < sVar2);
  sVar2 = auVar93._14_2_;
  texgammatable[0x47] = (0 < sVar2) * (sVar2 < 0x100) * auVar93[0xe] - (0xff < sVar2);
  uVar1 = auVar153._0_2_;
  texgammatable[0x48] = (uVar1 != 0) * (uVar1 < 0x100) * auVar153[0] - (0xff < uVar1);
  uVar1 = auVar153._2_2_;
  texgammatable[0x49] = (uVar1 != 0) * (uVar1 < 0x100) * auVar153[2] - (0xff < uVar1);
  uVar1 = auVar153._4_2_;
  texgammatable[0x4a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar153[4] - (0xff < uVar1);
  uVar1 = auVar153._6_2_;
  texgammatable[0x4b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar153[6] - (0xff < uVar1);
  sVar2 = auVar153._8_2_;
  texgammatable[0x4c] = (0 < sVar2) * (sVar2 < 0x100) * auVar153[8] - (0xff < sVar2);
  sVar2 = auVar153._10_2_;
  texgammatable[0x4d] = (0 < sVar2) * (sVar2 < 0x100) * auVar153[10] - (0xff < sVar2);
  sVar2 = auVar153._12_2_;
  texgammatable[0x4e] = (0 < sVar2) * (sVar2 < 0x100) * auVar153[0xc] - (0xff < sVar2);
  sVar2 = auVar153._14_2_;
  texgammatable[0x4f] = (0 < sVar2) * (sVar2 < 0x100) * auVar153[0xe] - (0xff < sVar2);
  auVar23._10_6_ = 0;
  auVar23._0_10_ = (unkuint10)0x56;
  auVar22._12_4_ = 0;
  auVar22._0_12_ = SUB1612(auVar23 << 0x30,4);
  auVar96._0_12_ = SUB1612(auVar22 << 0x20,0);
  auVar96._12_2_ = 0x56;
  auVar96._14_2_ = 0x57;
  auVar95._12_4_ = auVar96._12_4_;
  auVar95._0_10_ = SUB1610(auVar22 << 0x20,0);
  auVar95._10_2_ = 0x55;
  auVar94._10_6_ = auVar95._10_6_;
  auVar94._0_10_ = (unkuint10)0x54 << 0x40;
  auVar97._8_8_ = auVar94._8_8_;
  auVar97._6_2_ = 0x53;
  auVar97._4_2_ = 0x52;
  auVar97._0_4_ = 0x510050;
  auVar97 = auVar97 & _DAT_00267f50;
  auVar25._10_6_ = 0;
  auVar25._0_10_ = (unkuint10)0x5e;
  auVar24._12_4_ = 0;
  auVar24._0_12_ = SUB1612(auVar25 << 0x30,4);
  auVar156._0_12_ = SUB1612(auVar24 << 0x20,0);
  auVar156._12_2_ = 0x5e;
  auVar156._14_2_ = 0x5f;
  auVar155._12_4_ = auVar156._12_4_;
  auVar155._0_10_ = SUB1610(auVar24 << 0x20,0);
  auVar155._10_2_ = 0x5d;
  auVar154._10_6_ = auVar155._10_6_;
  auVar154._0_10_ = (unkuint10)0x5c << 0x40;
  auVar157._8_8_ = auVar154._8_8_;
  auVar157._6_2_ = 0x5b;
  auVar157._4_2_ = 0x5a;
  auVar157._0_4_ = 0x590058;
  auVar157 = auVar157 & _DAT_00267f50;
  uVar1 = auVar97._0_2_;
  texgammatable[0x50] = (uVar1 != 0) * (uVar1 < 0x100) * auVar97[0] - (0xff < uVar1);
  uVar1 = auVar97._2_2_;
  texgammatable[0x51] = (uVar1 != 0) * (uVar1 < 0x100) * auVar97[2] - (0xff < uVar1);
  uVar1 = auVar97._4_2_;
  texgammatable[0x52] = (uVar1 != 0) * (uVar1 < 0x100) * auVar97[4] - (0xff < uVar1);
  uVar1 = auVar97._6_2_;
  texgammatable[0x53] = (uVar1 != 0) * (uVar1 < 0x100) * auVar97[6] - (0xff < uVar1);
  sVar2 = auVar97._8_2_;
  texgammatable[0x54] = (0 < sVar2) * (sVar2 < 0x100) * auVar97[8] - (0xff < sVar2);
  sVar2 = auVar97._10_2_;
  texgammatable[0x55] = (0 < sVar2) * (sVar2 < 0x100) * auVar97[10] - (0xff < sVar2);
  sVar2 = auVar97._12_2_;
  texgammatable[0x56] = (0 < sVar2) * (sVar2 < 0x100) * auVar97[0xc] - (0xff < sVar2);
  sVar2 = auVar97._14_2_;
  texgammatable[0x57] = (0 < sVar2) * (sVar2 < 0x100) * auVar97[0xe] - (0xff < sVar2);
  uVar1 = auVar157._0_2_;
  texgammatable[0x58] = (uVar1 != 0) * (uVar1 < 0x100) * auVar157[0] - (0xff < uVar1);
  uVar1 = auVar157._2_2_;
  texgammatable[0x59] = (uVar1 != 0) * (uVar1 < 0x100) * auVar157[2] - (0xff < uVar1);
  uVar1 = auVar157._4_2_;
  texgammatable[0x5a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar157[4] - (0xff < uVar1);
  uVar1 = auVar157._6_2_;
  texgammatable[0x5b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar157[6] - (0xff < uVar1);
  sVar2 = auVar157._8_2_;
  texgammatable[0x5c] = (0 < sVar2) * (sVar2 < 0x100) * auVar157[8] - (0xff < sVar2);
  sVar2 = auVar157._10_2_;
  texgammatable[0x5d] = (0 < sVar2) * (sVar2 < 0x100) * auVar157[10] - (0xff < sVar2);
  sVar2 = auVar157._12_2_;
  texgammatable[0x5e] = (0 < sVar2) * (sVar2 < 0x100) * auVar157[0xc] - (0xff < sVar2);
  sVar2 = auVar157._14_2_;
  texgammatable[0x5f] = (0 < sVar2) * (sVar2 < 0x100) * auVar157[0xe] - (0xff < sVar2);
  auVar27._10_6_ = 0;
  auVar27._0_10_ = (unkuint10)0x66;
  auVar26._12_4_ = 0;
  auVar26._0_12_ = SUB1612(auVar27 << 0x30,4);
  auVar100._0_12_ = SUB1612(auVar26 << 0x20,0);
  auVar100._12_2_ = 0x66;
  auVar100._14_2_ = 0x67;
  auVar99._12_4_ = auVar100._12_4_;
  auVar99._0_10_ = SUB1610(auVar26 << 0x20,0);
  auVar99._10_2_ = 0x65;
  auVar98._10_6_ = auVar99._10_6_;
  auVar98._0_10_ = (unkuint10)100 << 0x40;
  auVar101._8_8_ = auVar98._8_8_;
  auVar101._6_2_ = 99;
  auVar101._4_2_ = 0x62;
  auVar101._0_4_ = 0x610060;
  auVar101 = auVar101 & _DAT_00267f50;
  auVar29._10_6_ = 0;
  auVar29._0_10_ = (unkuint10)0x6e;
  auVar28._12_4_ = 0;
  auVar28._0_12_ = SUB1612(auVar29 << 0x30,4);
  auVar160._0_12_ = SUB1612(auVar28 << 0x20,0);
  auVar160._12_2_ = 0x6e;
  auVar160._14_2_ = 0x6f;
  auVar159._12_4_ = auVar160._12_4_;
  auVar159._0_10_ = SUB1610(auVar28 << 0x20,0);
  auVar159._10_2_ = 0x6d;
  auVar158._10_6_ = auVar159._10_6_;
  auVar158._0_10_ = (unkuint10)0x6c << 0x40;
  auVar161._8_8_ = auVar158._8_8_;
  auVar161._6_2_ = 0x6b;
  auVar161._4_2_ = 0x6a;
  auVar161._0_4_ = 0x690068;
  auVar161 = auVar161 & _DAT_00267f50;
  uVar1 = auVar101._0_2_;
  texgammatable[0x60] = (uVar1 != 0) * (uVar1 < 0x100) * auVar101[0] - (0xff < uVar1);
  uVar1 = auVar101._2_2_;
  texgammatable[0x61] = (uVar1 != 0) * (uVar1 < 0x100) * auVar101[2] - (0xff < uVar1);
  uVar1 = auVar101._4_2_;
  texgammatable[0x62] = (uVar1 != 0) * (uVar1 < 0x100) * auVar101[4] - (0xff < uVar1);
  uVar1 = auVar101._6_2_;
  texgammatable[99] = (uVar1 != 0) * (uVar1 < 0x100) * auVar101[6] - (0xff < uVar1);
  sVar2 = auVar101._8_2_;
  texgammatable[100] = (0 < sVar2) * (sVar2 < 0x100) * auVar101[8] - (0xff < sVar2);
  sVar2 = auVar101._10_2_;
  texgammatable[0x65] = (0 < sVar2) * (sVar2 < 0x100) * auVar101[10] - (0xff < sVar2);
  sVar2 = auVar101._12_2_;
  texgammatable[0x66] = (0 < sVar2) * (sVar2 < 0x100) * auVar101[0xc] - (0xff < sVar2);
  sVar2 = auVar101._14_2_;
  texgammatable[0x67] = (0 < sVar2) * (sVar2 < 0x100) * auVar101[0xe] - (0xff < sVar2);
  uVar1 = auVar161._0_2_;
  texgammatable[0x68] = (uVar1 != 0) * (uVar1 < 0x100) * auVar161[0] - (0xff < uVar1);
  uVar1 = auVar161._2_2_;
  texgammatable[0x69] = (uVar1 != 0) * (uVar1 < 0x100) * auVar161[2] - (0xff < uVar1);
  uVar1 = auVar161._4_2_;
  texgammatable[0x6a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar161[4] - (0xff < uVar1);
  uVar1 = auVar161._6_2_;
  texgammatable[0x6b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar161[6] - (0xff < uVar1);
  sVar2 = auVar161._8_2_;
  texgammatable[0x6c] = (0 < sVar2) * (sVar2 < 0x100) * auVar161[8] - (0xff < sVar2);
  sVar2 = auVar161._10_2_;
  texgammatable[0x6d] = (0 < sVar2) * (sVar2 < 0x100) * auVar161[10] - (0xff < sVar2);
  sVar2 = auVar161._12_2_;
  texgammatable[0x6e] = (0 < sVar2) * (sVar2 < 0x100) * auVar161[0xc] - (0xff < sVar2);
  sVar2 = auVar161._14_2_;
  texgammatable[0x6f] = (0 < sVar2) * (sVar2 < 0x100) * auVar161[0xe] - (0xff < sVar2);
  auVar31._10_6_ = 0;
  auVar31._0_10_ = (unkuint10)0x76;
  auVar30._12_4_ = 0;
  auVar30._0_12_ = SUB1612(auVar31 << 0x30,4);
  auVar104._0_12_ = SUB1612(auVar30 << 0x20,0);
  auVar104._12_2_ = 0x76;
  auVar104._14_2_ = 0x77;
  auVar103._12_4_ = auVar104._12_4_;
  auVar103._0_10_ = SUB1610(auVar30 << 0x20,0);
  auVar103._10_2_ = 0x75;
  auVar102._10_6_ = auVar103._10_6_;
  auVar102._0_10_ = (unkuint10)0x74 << 0x40;
  auVar105._8_8_ = auVar102._8_8_;
  auVar105._6_2_ = 0x73;
  auVar105._4_2_ = 0x72;
  auVar105._0_4_ = 0x710070;
  auVar105 = auVar105 & _DAT_00267f50;
  auVar33._10_6_ = 0;
  auVar33._0_10_ = (unkuint10)0x7e;
  auVar32._12_4_ = 0;
  auVar32._0_12_ = SUB1612(auVar33 << 0x30,4);
  auVar164._0_12_ = SUB1612(auVar32 << 0x20,0);
  auVar164._12_2_ = 0x7e;
  auVar164._14_2_ = 0x7f;
  auVar163._12_4_ = auVar164._12_4_;
  auVar163._0_10_ = SUB1610(auVar32 << 0x20,0);
  auVar163._10_2_ = 0x7d;
  auVar162._10_6_ = auVar163._10_6_;
  auVar162._0_10_ = (unkuint10)0x7c << 0x40;
  auVar165._8_8_ = auVar162._8_8_;
  auVar165._6_2_ = 0x7b;
  auVar165._4_2_ = 0x7a;
  auVar165._0_4_ = 0x790078;
  auVar165 = auVar165 & _DAT_00267f50;
  uVar1 = auVar105._0_2_;
  texgammatable[0x70] = (uVar1 != 0) * (uVar1 < 0x100) * auVar105[0] - (0xff < uVar1);
  uVar1 = auVar105._2_2_;
  texgammatable[0x71] = (uVar1 != 0) * (uVar1 < 0x100) * auVar105[2] - (0xff < uVar1);
  uVar1 = auVar105._4_2_;
  texgammatable[0x72] = (uVar1 != 0) * (uVar1 < 0x100) * auVar105[4] - (0xff < uVar1);
  uVar1 = auVar105._6_2_;
  texgammatable[0x73] = (uVar1 != 0) * (uVar1 < 0x100) * auVar105[6] - (0xff < uVar1);
  sVar2 = auVar105._8_2_;
  texgammatable[0x74] = (0 < sVar2) * (sVar2 < 0x100) * auVar105[8] - (0xff < sVar2);
  sVar2 = auVar105._10_2_;
  texgammatable[0x75] = (0 < sVar2) * (sVar2 < 0x100) * auVar105[10] - (0xff < sVar2);
  sVar2 = auVar105._12_2_;
  texgammatable[0x76] = (0 < sVar2) * (sVar2 < 0x100) * auVar105[0xc] - (0xff < sVar2);
  sVar2 = auVar105._14_2_;
  texgammatable[0x77] = (0 < sVar2) * (sVar2 < 0x100) * auVar105[0xe] - (0xff < sVar2);
  uVar1 = auVar165._0_2_;
  texgammatable[0x78] = (uVar1 != 0) * (uVar1 < 0x100) * auVar165[0] - (0xff < uVar1);
  uVar1 = auVar165._2_2_;
  texgammatable[0x79] = (uVar1 != 0) * (uVar1 < 0x100) * auVar165[2] - (0xff < uVar1);
  uVar1 = auVar165._4_2_;
  texgammatable[0x7a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar165[4] - (0xff < uVar1);
  uVar1 = auVar165._6_2_;
  texgammatable[0x7b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar165[6] - (0xff < uVar1);
  sVar2 = auVar165._8_2_;
  texgammatable[0x7c] = (0 < sVar2) * (sVar2 < 0x100) * auVar165[8] - (0xff < sVar2);
  sVar2 = auVar165._10_2_;
  texgammatable[0x7d] = (0 < sVar2) * (sVar2 < 0x100) * auVar165[10] - (0xff < sVar2);
  sVar2 = auVar165._12_2_;
  texgammatable[0x7e] = (0 < sVar2) * (sVar2 < 0x100) * auVar165[0xc] - (0xff < sVar2);
  sVar2 = auVar165._14_2_;
  texgammatable[0x7f] = (0 < sVar2) * (sVar2 < 0x100) * auVar165[0xe] - (0xff < sVar2);
  auVar35._10_6_ = 0;
  auVar35._0_10_ = (unkuint10)0x86;
  auVar34._12_4_ = 0;
  auVar34._0_12_ = SUB1612(auVar35 << 0x30,4);
  auVar108._0_12_ = SUB1612(auVar34 << 0x20,0);
  auVar108._12_2_ = 0x86;
  auVar108._14_2_ = 0x87;
  auVar107._12_4_ = auVar108._12_4_;
  auVar107._0_10_ = SUB1610(auVar34 << 0x20,0);
  auVar107._10_2_ = 0x85;
  auVar106._10_6_ = auVar107._10_6_;
  auVar106._0_10_ = (unkuint10)0x84 << 0x40;
  auVar109._8_8_ = auVar106._8_8_;
  auVar109._6_2_ = 0x83;
  auVar109._4_2_ = 0x82;
  auVar109._0_4_ = 0x810080;
  auVar109 = auVar109 & _DAT_00267f50;
  auVar37._10_6_ = 0;
  auVar37._0_10_ = (unkuint10)0x8e;
  auVar36._12_4_ = 0;
  auVar36._0_12_ = SUB1612(auVar37 << 0x30,4);
  auVar168._0_12_ = SUB1612(auVar36 << 0x20,0);
  auVar168._12_2_ = 0x8e;
  auVar168._14_2_ = 0x8f;
  auVar167._12_4_ = auVar168._12_4_;
  auVar167._0_10_ = SUB1610(auVar36 << 0x20,0);
  auVar167._10_2_ = 0x8d;
  auVar166._10_6_ = auVar167._10_6_;
  auVar166._0_10_ = (unkuint10)0x8c << 0x40;
  auVar169._8_8_ = auVar166._8_8_;
  auVar169._6_2_ = 0x8b;
  auVar169._4_2_ = 0x8a;
  auVar169._0_4_ = staticRGBA + 0x3d4a8;
  auVar169 = auVar169 & _DAT_00267f50;
  uVar1 = auVar109._0_2_;
  texgammatable[0x80] = (uVar1 != 0) * (uVar1 < 0x100) * auVar109[0] - (0xff < uVar1);
  uVar1 = auVar109._2_2_;
  texgammatable[0x81] = (uVar1 != 0) * (uVar1 < 0x100) * auVar109[2] - (0xff < uVar1);
  uVar1 = auVar109._4_2_;
  texgammatable[0x82] = (uVar1 != 0) * (uVar1 < 0x100) * auVar109[4] - (0xff < uVar1);
  uVar1 = auVar109._6_2_;
  texgammatable[0x83] = (uVar1 != 0) * (uVar1 < 0x100) * auVar109[6] - (0xff < uVar1);
  sVar2 = auVar109._8_2_;
  texgammatable[0x84] = (0 < sVar2) * (sVar2 < 0x100) * auVar109[8] - (0xff < sVar2);
  sVar2 = auVar109._10_2_;
  texgammatable[0x85] = (0 < sVar2) * (sVar2 < 0x100) * auVar109[10] - (0xff < sVar2);
  sVar2 = auVar109._12_2_;
  texgammatable[0x86] = (0 < sVar2) * (sVar2 < 0x100) * auVar109[0xc] - (0xff < sVar2);
  sVar2 = auVar109._14_2_;
  texgammatable[0x87] = (0 < sVar2) * (sVar2 < 0x100) * auVar109[0xe] - (0xff < sVar2);
  uVar1 = auVar169._0_2_;
  texgammatable[0x88] = (uVar1 != 0) * (uVar1 < 0x100) * auVar169[0] - (0xff < uVar1);
  uVar1 = auVar169._2_2_;
  texgammatable[0x89] = (uVar1 != 0) * (uVar1 < 0x100) * auVar169[2] - (0xff < uVar1);
  uVar1 = auVar169._4_2_;
  texgammatable[0x8a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar169[4] - (0xff < uVar1);
  uVar1 = auVar169._6_2_;
  texgammatable[0x8b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar169[6] - (0xff < uVar1);
  sVar2 = auVar169._8_2_;
  texgammatable[0x8c] = (0 < sVar2) * (sVar2 < 0x100) * auVar169[8] - (0xff < sVar2);
  sVar2 = auVar169._10_2_;
  texgammatable[0x8d] = (0 < sVar2) * (sVar2 < 0x100) * auVar169[10] - (0xff < sVar2);
  sVar2 = auVar169._12_2_;
  texgammatable[0x8e] = (0 < sVar2) * (sVar2 < 0x100) * auVar169[0xc] - (0xff < sVar2);
  sVar2 = auVar169._14_2_;
  texgammatable[0x8f] = (0 < sVar2) * (sVar2 < 0x100) * auVar169[0xe] - (0xff < sVar2);
  auVar39._10_6_ = 0;
  auVar39._0_10_ = (unkuint10)0x96;
  auVar38._12_4_ = 0;
  auVar38._0_12_ = SUB1612(auVar39 << 0x30,4);
  auVar112._0_12_ = SUB1612(auVar38 << 0x20,0);
  auVar112._12_2_ = 0x96;
  auVar112._14_2_ = 0x97;
  auVar111._12_4_ = auVar112._12_4_;
  auVar111._0_10_ = SUB1610(auVar38 << 0x20,0);
  auVar111._10_2_ = 0x95;
  auVar110._10_6_ = auVar111._10_6_;
  auVar110._0_10_ = (unkuint10)0x94 << 0x40;
  auVar113._8_8_ = auVar110._8_8_;
  auVar113._6_2_ = 0x93;
  auVar113._4_2_ = 0x92;
  auVar113._0_4_ = staticRGBA + 0xbd4b0;
  auVar113 = auVar113 & _DAT_00267f50;
  auVar41._10_6_ = 0;
  auVar41._0_10_ = (unkuint10)0x9e;
  auVar40._12_4_ = 0;
  auVar40._0_12_ = SUB1612(auVar41 << 0x30,4);
  auVar172._0_12_ = SUB1612(auVar40 << 0x20,0);
  auVar172._12_2_ = 0x9e;
  auVar172._14_2_ = 0x9f;
  auVar171._12_4_ = auVar172._12_4_;
  auVar171._0_10_ = SUB1610(auVar40 << 0x20,0);
  auVar171._10_2_ = 0x9d;
  auVar170._10_6_ = auVar171._10_6_;
  auVar170._0_10_ = (unkuint10)0x9c << 0x40;
  auVar173._8_8_ = auVar170._8_8_;
  auVar173._6_2_ = 0x9b;
  auVar173._4_2_ = 0x9a;
  auVar173._0_4_ = 0x990098;
  auVar173 = auVar173 & _DAT_00267f50;
  uVar1 = auVar113._0_2_;
  texgammatable[0x90] = (uVar1 != 0) * (uVar1 < 0x100) * auVar113[0] - (0xff < uVar1);
  uVar1 = auVar113._2_2_;
  texgammatable[0x91] = (uVar1 != 0) * (uVar1 < 0x100) * auVar113[2] - (0xff < uVar1);
  uVar1 = auVar113._4_2_;
  texgammatable[0x92] = (uVar1 != 0) * (uVar1 < 0x100) * auVar113[4] - (0xff < uVar1);
  uVar1 = auVar113._6_2_;
  texgammatable[0x93] = (uVar1 != 0) * (uVar1 < 0x100) * auVar113[6] - (0xff < uVar1);
  sVar2 = auVar113._8_2_;
  texgammatable[0x94] = (0 < sVar2) * (sVar2 < 0x100) * auVar113[8] - (0xff < sVar2);
  sVar2 = auVar113._10_2_;
  texgammatable[0x95] = (0 < sVar2) * (sVar2 < 0x100) * auVar113[10] - (0xff < sVar2);
  sVar2 = auVar113._12_2_;
  texgammatable[0x96] = (0 < sVar2) * (sVar2 < 0x100) * auVar113[0xc] - (0xff < sVar2);
  sVar2 = auVar113._14_2_;
  texgammatable[0x97] = (0 < sVar2) * (sVar2 < 0x100) * auVar113[0xe] - (0xff < sVar2);
  uVar1 = auVar173._0_2_;
  texgammatable[0x98] = (uVar1 != 0) * (uVar1 < 0x100) * auVar173[0] - (0xff < uVar1);
  uVar1 = auVar173._2_2_;
  texgammatable[0x99] = (uVar1 != 0) * (uVar1 < 0x100) * auVar173[2] - (0xff < uVar1);
  uVar1 = auVar173._4_2_;
  texgammatable[0x9a] = (uVar1 != 0) * (uVar1 < 0x100) * auVar173[4] - (0xff < uVar1);
  uVar1 = auVar173._6_2_;
  texgammatable[0x9b] = (uVar1 != 0) * (uVar1 < 0x100) * auVar173[6] - (0xff < uVar1);
  sVar2 = auVar173._8_2_;
  texgammatable[0x9c] = (0 < sVar2) * (sVar2 < 0x100) * auVar173[8] - (0xff < sVar2);
  sVar2 = auVar173._10_2_;
  texgammatable[0x9d] = (0 < sVar2) * (sVar2 < 0x100) * auVar173[10] - (0xff < sVar2);
  sVar2 = auVar173._12_2_;
  texgammatable[0x9e] = (0 < sVar2) * (sVar2 < 0x100) * auVar173[0xc] - (0xff < sVar2);
  sVar2 = auVar173._14_2_;
  texgammatable[0x9f] = (0 < sVar2) * (sVar2 < 0x100) * auVar173[0xe] - (0xff < sVar2);
  auVar43._10_6_ = 0;
  auVar43._0_10_ = (unkuint10)0xa6;
  auVar42._12_4_ = 0;
  auVar42._0_12_ = SUB1612(auVar43 << 0x30,4);
  auVar116._0_12_ = SUB1612(auVar42 << 0x20,0);
  auVar116._12_2_ = 0xa6;
  auVar116._14_2_ = 0xa7;
  auVar115._12_4_ = auVar116._12_4_;
  auVar115._0_10_ = SUB1610(auVar42 << 0x20,0);
  auVar115._10_2_ = 0xa5;
  auVar114._10_6_ = auVar115._10_6_;
  auVar114._0_10_ = (unkuint10)0xa4 << 0x40;
  auVar117._8_8_ = auVar114._8_8_;
  auVar117._6_2_ = 0xa3;
  auVar117._4_2_ = 0xa2;
  auVar117._0_4_ = 0xa100a0;
  auVar117 = auVar117 & _DAT_00267f50;
  auVar45._10_6_ = 0;
  auVar45._0_10_ = (unkuint10)0xae;
  auVar44._12_4_ = 0;
  auVar44._0_12_ = SUB1612(auVar45 << 0x30,4);
  auVar176._0_12_ = SUB1612(auVar44 << 0x20,0);
  auVar176._12_2_ = 0xae;
  auVar176._14_2_ = 0xaf;
  auVar175._12_4_ = auVar176._12_4_;
  auVar175._0_10_ = SUB1610(auVar44 << 0x20,0);
  auVar175._10_2_ = 0xad;
  auVar174._10_6_ = auVar175._10_6_;
  auVar174._0_10_ = (unkuint10)0xac << 0x40;
  auVar177._8_8_ = auVar174._8_8_;
  auVar177._6_2_ = 0xab;
  auVar177._4_2_ = 0xaa;
  auVar177._0_4_ = 0xa900a8;
  auVar177 = auVar177 & _DAT_00267f50;
  uVar1 = auVar117._0_2_;
  texgammatable[0xa0] = (uVar1 != 0) * (uVar1 < 0x100) * auVar117[0] - (0xff < uVar1);
  uVar1 = auVar117._2_2_;
  texgammatable[0xa1] = (uVar1 != 0) * (uVar1 < 0x100) * auVar117[2] - (0xff < uVar1);
  uVar1 = auVar117._4_2_;
  texgammatable[0xa2] = (uVar1 != 0) * (uVar1 < 0x100) * auVar117[4] - (0xff < uVar1);
  uVar1 = auVar117._6_2_;
  texgammatable[0xa3] = (uVar1 != 0) * (uVar1 < 0x100) * auVar117[6] - (0xff < uVar1);
  sVar2 = auVar117._8_2_;
  texgammatable[0xa4] = (0 < sVar2) * (sVar2 < 0x100) * auVar117[8] - (0xff < sVar2);
  sVar2 = auVar117._10_2_;
  texgammatable[0xa5] = (0 < sVar2) * (sVar2 < 0x100) * auVar117[10] - (0xff < sVar2);
  sVar2 = auVar117._12_2_;
  texgammatable[0xa6] = (0 < sVar2) * (sVar2 < 0x100) * auVar117[0xc] - (0xff < sVar2);
  sVar2 = auVar117._14_2_;
  texgammatable[0xa7] = (0 < sVar2) * (sVar2 < 0x100) * auVar117[0xe] - (0xff < sVar2);
  uVar1 = auVar177._0_2_;
  texgammatable[0xa8] = (uVar1 != 0) * (uVar1 < 0x100) * auVar177[0] - (0xff < uVar1);
  uVar1 = auVar177._2_2_;
  texgammatable[0xa9] = (uVar1 != 0) * (uVar1 < 0x100) * auVar177[2] - (0xff < uVar1);
  uVar1 = auVar177._4_2_;
  texgammatable[0xaa] = (uVar1 != 0) * (uVar1 < 0x100) * auVar177[4] - (0xff < uVar1);
  uVar1 = auVar177._6_2_;
  texgammatable[0xab] = (uVar1 != 0) * (uVar1 < 0x100) * auVar177[6] - (0xff < uVar1);
  sVar2 = auVar177._8_2_;
  texgammatable[0xac] = (0 < sVar2) * (sVar2 < 0x100) * auVar177[8] - (0xff < sVar2);
  sVar2 = auVar177._10_2_;
  texgammatable[0xad] = (0 < sVar2) * (sVar2 < 0x100) * auVar177[10] - (0xff < sVar2);
  sVar2 = auVar177._12_2_;
  texgammatable[0xae] = (0 < sVar2) * (sVar2 < 0x100) * auVar177[0xc] - (0xff < sVar2);
  sVar2 = auVar177._14_2_;
  texgammatable[0xaf] = (0 < sVar2) * (sVar2 < 0x100) * auVar177[0xe] - (0xff < sVar2);
  auVar47._10_6_ = 0;
  auVar47._0_10_ = (unkuint10)0xb6;
  auVar46._12_4_ = 0;
  auVar46._0_12_ = SUB1612(auVar47 << 0x30,4);
  auVar120._0_12_ = SUB1612(auVar46 << 0x20,0);
  auVar120._12_2_ = 0xb6;
  auVar120._14_2_ = 0xb7;
  auVar119._12_4_ = auVar120._12_4_;
  auVar119._0_10_ = SUB1610(auVar46 << 0x20,0);
  auVar119._10_2_ = 0xb5;
  auVar118._10_6_ = auVar119._10_6_;
  auVar118._0_10_ = (unkuint10)0xb4 << 0x40;
  auVar121._8_8_ = auVar118._8_8_;
  auVar121._6_2_ = 0xb3;
  auVar121._4_2_ = 0xb2;
  auVar121._0_4_ = 0xb100b0;
  auVar121 = auVar121 & _DAT_00267f50;
  auVar49._10_6_ = 0;
  auVar49._0_10_ = (unkuint10)0xbe;
  auVar48._12_4_ = 0;
  auVar48._0_12_ = SUB1612(auVar49 << 0x30,4);
  auVar180._0_12_ = SUB1612(auVar48 << 0x20,0);
  auVar180._12_2_ = 0xbe;
  auVar180._14_2_ = 0xbf;
  auVar179._12_4_ = auVar180._12_4_;
  auVar179._0_10_ = SUB1610(auVar48 << 0x20,0);
  auVar179._10_2_ = 0xbd;
  auVar178._10_6_ = auVar179._10_6_;
  auVar178._0_10_ = (unkuint10)0xbc << 0x40;
  auVar181._8_8_ = auVar178._8_8_;
  auVar181._6_2_ = 0xbb;
  auVar181._4_2_ = 0xba;
  auVar181._0_4_ = 0xb900b8;
  auVar181 = auVar181 & _DAT_00267f50;
  uVar1 = auVar121._0_2_;
  texgammatable[0xb0] = (uVar1 != 0) * (uVar1 < 0x100) * auVar121[0] - (0xff < uVar1);
  uVar1 = auVar121._2_2_;
  texgammatable[0xb1] = (uVar1 != 0) * (uVar1 < 0x100) * auVar121[2] - (0xff < uVar1);
  uVar1 = auVar121._4_2_;
  texgammatable[0xb2] = (uVar1 != 0) * (uVar1 < 0x100) * auVar121[4] - (0xff < uVar1);
  uVar1 = auVar121._6_2_;
  texgammatable[0xb3] = (uVar1 != 0) * (uVar1 < 0x100) * auVar121[6] - (0xff < uVar1);
  sVar2 = auVar121._8_2_;
  texgammatable[0xb4] = (0 < sVar2) * (sVar2 < 0x100) * auVar121[8] - (0xff < sVar2);
  sVar2 = auVar121._10_2_;
  texgammatable[0xb5] = (0 < sVar2) * (sVar2 < 0x100) * auVar121[10] - (0xff < sVar2);
  sVar2 = auVar121._12_2_;
  texgammatable[0xb6] = (0 < sVar2) * (sVar2 < 0x100) * auVar121[0xc] - (0xff < sVar2);
  sVar2 = auVar121._14_2_;
  texgammatable[0xb7] = (0 < sVar2) * (sVar2 < 0x100) * auVar121[0xe] - (0xff < sVar2);
  uVar1 = auVar181._0_2_;
  texgammatable[0xb8] = (uVar1 != 0) * (uVar1 < 0x100) * auVar181[0] - (0xff < uVar1);
  uVar1 = auVar181._2_2_;
  texgammatable[0xb9] = (uVar1 != 0) * (uVar1 < 0x100) * auVar181[2] - (0xff < uVar1);
  uVar1 = auVar181._4_2_;
  texgammatable[0xba] = (uVar1 != 0) * (uVar1 < 0x100) * auVar181[4] - (0xff < uVar1);
  uVar1 = auVar181._6_2_;
  texgammatable[0xbb] = (uVar1 != 0) * (uVar1 < 0x100) * auVar181[6] - (0xff < uVar1);
  sVar2 = auVar181._8_2_;
  texgammatable[0xbc] = (0 < sVar2) * (sVar2 < 0x100) * auVar181[8] - (0xff < sVar2);
  sVar2 = auVar181._10_2_;
  texgammatable[0xbd] = (0 < sVar2) * (sVar2 < 0x100) * auVar181[10] - (0xff < sVar2);
  sVar2 = auVar181._12_2_;
  texgammatable[0xbe] = (0 < sVar2) * (sVar2 < 0x100) * auVar181[0xc] - (0xff < sVar2);
  sVar2 = auVar181._14_2_;
  texgammatable[0xbf] = (0 < sVar2) * (sVar2 < 0x100) * auVar181[0xe] - (0xff < sVar2);
  auVar51._10_6_ = 0;
  auVar51._0_10_ = (unkuint10)0xc6;
  auVar50._12_4_ = 0;
  auVar50._0_12_ = SUB1612(auVar51 << 0x30,4);
  auVar124._0_12_ = SUB1612(auVar50 << 0x20,0);
  auVar124._12_2_ = 0xc6;
  auVar124._14_2_ = 199;
  auVar123._12_4_ = auVar124._12_4_;
  auVar123._0_10_ = SUB1610(auVar50 << 0x20,0);
  auVar123._10_2_ = 0xc5;
  auVar122._10_6_ = auVar123._10_6_;
  auVar122._0_10_ = (unkuint10)0xc4 << 0x40;
  auVar125._8_8_ = auVar122._8_8_;
  auVar125._6_2_ = 0xc3;
  auVar125._4_2_ = 0xc2;
  auVar125._0_4_ = 0xc100c0;
  auVar125 = auVar125 & _DAT_00267f50;
  auVar53._10_6_ = 0;
  auVar53._0_10_ = (unkuint10)0xce;
  auVar52._12_4_ = 0;
  auVar52._0_12_ = SUB1612(auVar53 << 0x30,4);
  auVar184._0_12_ = SUB1612(auVar52 << 0x20,0);
  auVar184._12_2_ = 0xce;
  auVar184._14_2_ = 0xcf;
  auVar183._12_4_ = auVar184._12_4_;
  auVar183._0_10_ = SUB1610(auVar52 << 0x20,0);
  auVar183._10_2_ = 0xcd;
  auVar182._10_6_ = auVar183._10_6_;
  auVar182._0_10_ = (unkuint10)0xcc << 0x40;
  auVar185._8_8_ = auVar182._8_8_;
  auVar185._6_2_ = 0xcb;
  auVar185._4_2_ = 0xca;
  auVar185._0_4_ = 0xc900c8;
  auVar185 = auVar185 & _DAT_00267f50;
  uVar1 = auVar125._0_2_;
  texgammatable[0xc0] = (uVar1 != 0) * (uVar1 < 0x100) * auVar125[0] - (0xff < uVar1);
  uVar1 = auVar125._2_2_;
  texgammatable[0xc1] = (uVar1 != 0) * (uVar1 < 0x100) * auVar125[2] - (0xff < uVar1);
  uVar1 = auVar125._4_2_;
  texgammatable[0xc2] = (uVar1 != 0) * (uVar1 < 0x100) * auVar125[4] - (0xff < uVar1);
  uVar1 = auVar125._6_2_;
  texgammatable[0xc3] = (uVar1 != 0) * (uVar1 < 0x100) * auVar125[6] - (0xff < uVar1);
  sVar2 = auVar125._8_2_;
  texgammatable[0xc4] = (0 < sVar2) * (sVar2 < 0x100) * auVar125[8] - (0xff < sVar2);
  sVar2 = auVar125._10_2_;
  texgammatable[0xc5] = (0 < sVar2) * (sVar2 < 0x100) * auVar125[10] - (0xff < sVar2);
  sVar2 = auVar125._12_2_;
  texgammatable[0xc6] = (0 < sVar2) * (sVar2 < 0x100) * auVar125[0xc] - (0xff < sVar2);
  sVar2 = auVar125._14_2_;
  texgammatable[199] = (0 < sVar2) * (sVar2 < 0x100) * auVar125[0xe] - (0xff < sVar2);
  uVar1 = auVar185._0_2_;
  texgammatable[200] = (uVar1 != 0) * (uVar1 < 0x100) * auVar185[0] - (0xff < uVar1);
  uVar1 = auVar185._2_2_;
  texgammatable[0xc9] = (uVar1 != 0) * (uVar1 < 0x100) * auVar185[2] - (0xff < uVar1);
  uVar1 = auVar185._4_2_;
  texgammatable[0xca] = (uVar1 != 0) * (uVar1 < 0x100) * auVar185[4] - (0xff < uVar1);
  uVar1 = auVar185._6_2_;
  texgammatable[0xcb] = (uVar1 != 0) * (uVar1 < 0x100) * auVar185[6] - (0xff < uVar1);
  sVar2 = auVar185._8_2_;
  texgammatable[0xcc] = (0 < sVar2) * (sVar2 < 0x100) * auVar185[8] - (0xff < sVar2);
  sVar2 = auVar185._10_2_;
  texgammatable[0xcd] = (0 < sVar2) * (sVar2 < 0x100) * auVar185[10] - (0xff < sVar2);
  sVar2 = auVar185._12_2_;
  texgammatable[0xce] = (0 < sVar2) * (sVar2 < 0x100) * auVar185[0xc] - (0xff < sVar2);
  sVar2 = auVar185._14_2_;
  texgammatable[0xcf] = (0 < sVar2) * (sVar2 < 0x100) * auVar185[0xe] - (0xff < sVar2);
  auVar55._10_6_ = 0;
  auVar55._0_10_ = (unkuint10)0xd6;
  auVar54._12_4_ = 0;
  auVar54._0_12_ = SUB1612(auVar55 << 0x30,4);
  auVar128._0_12_ = SUB1612(auVar54 << 0x20,0);
  auVar128._12_2_ = 0xd6;
  auVar128._14_2_ = 0xd7;
  auVar127._12_4_ = auVar128._12_4_;
  auVar127._0_10_ = SUB1610(auVar54 << 0x20,0);
  auVar127._10_2_ = 0xd5;
  auVar126._10_6_ = auVar127._10_6_;
  auVar126._0_10_ = (unkuint10)0xd4 << 0x40;
  auVar129._8_8_ = auVar126._8_8_;
  auVar129._6_2_ = 0xd3;
  auVar129._4_2_ = 0xd2;
  auVar129._0_4_ = 0xd100d0;
  auVar129 = auVar129 & _DAT_00267f50;
  auVar57._10_6_ = 0;
  auVar57._0_10_ = (unkuint10)0xde;
  auVar56._12_4_ = 0;
  auVar56._0_12_ = SUB1612(auVar57 << 0x30,4);
  auVar188._0_12_ = SUB1612(auVar56 << 0x20,0);
  auVar188._12_2_ = 0xde;
  auVar188._14_2_ = 0xdf;
  auVar187._12_4_ = auVar188._12_4_;
  auVar187._0_10_ = SUB1610(auVar56 << 0x20,0);
  auVar187._10_2_ = 0xdd;
  auVar186._10_6_ = auVar187._10_6_;
  auVar186._0_10_ = (unkuint10)0xdc << 0x40;
  auVar189._8_8_ = auVar186._8_8_;
  auVar189._6_2_ = 0xdb;
  auVar189._4_2_ = 0xda;
  auVar189._0_4_ = 0xd900d8;
  auVar189 = auVar189 & _DAT_00267f50;
  uVar1 = auVar129._0_2_;
  texgammatable[0xd0] = (uVar1 != 0) * (uVar1 < 0x100) * auVar129[0] - (0xff < uVar1);
  uVar1 = auVar129._2_2_;
  texgammatable[0xd1] = (uVar1 != 0) * (uVar1 < 0x100) * auVar129[2] - (0xff < uVar1);
  uVar1 = auVar129._4_2_;
  texgammatable[0xd2] = (uVar1 != 0) * (uVar1 < 0x100) * auVar129[4] - (0xff < uVar1);
  uVar1 = auVar129._6_2_;
  texgammatable[0xd3] = (uVar1 != 0) * (uVar1 < 0x100) * auVar129[6] - (0xff < uVar1);
  sVar2 = auVar129._8_2_;
  texgammatable[0xd4] = (0 < sVar2) * (sVar2 < 0x100) * auVar129[8] - (0xff < sVar2);
  sVar2 = auVar129._10_2_;
  texgammatable[0xd5] = (0 < sVar2) * (sVar2 < 0x100) * auVar129[10] - (0xff < sVar2);
  sVar2 = auVar129._12_2_;
  texgammatable[0xd6] = (0 < sVar2) * (sVar2 < 0x100) * auVar129[0xc] - (0xff < sVar2);
  sVar2 = auVar129._14_2_;
  texgammatable[0xd7] = (0 < sVar2) * (sVar2 < 0x100) * auVar129[0xe] - (0xff < sVar2);
  uVar1 = auVar189._0_2_;
  texgammatable[0xd8] = (uVar1 != 0) * (uVar1 < 0x100) * auVar189[0] - (0xff < uVar1);
  uVar1 = auVar189._2_2_;
  texgammatable[0xd9] = (uVar1 != 0) * (uVar1 < 0x100) * auVar189[2] - (0xff < uVar1);
  uVar1 = auVar189._4_2_;
  texgammatable[0xda] = (uVar1 != 0) * (uVar1 < 0x100) * auVar189[4] - (0xff < uVar1);
  uVar1 = auVar189._6_2_;
  texgammatable[0xdb] = (uVar1 != 0) * (uVar1 < 0x100) * auVar189[6] - (0xff < uVar1);
  sVar2 = auVar189._8_2_;
  texgammatable[0xdc] = (0 < sVar2) * (sVar2 < 0x100) * auVar189[8] - (0xff < sVar2);
  sVar2 = auVar189._10_2_;
  texgammatable[0xdd] = (0 < sVar2) * (sVar2 < 0x100) * auVar189[10] - (0xff < sVar2);
  sVar2 = auVar189._12_2_;
  texgammatable[0xde] = (0 < sVar2) * (sVar2 < 0x100) * auVar189[0xc] - (0xff < sVar2);
  sVar2 = auVar189._14_2_;
  texgammatable[0xdf] = (0 < sVar2) * (sVar2 < 0x100) * auVar189[0xe] - (0xff < sVar2);
  auVar59._10_6_ = 0;
  auVar59._0_10_ = (unkuint10)0xe6;
  auVar58._12_4_ = 0;
  auVar58._0_12_ = SUB1612(auVar59 << 0x30,4);
  auVar192._0_12_ = SUB1612(auVar58 << 0x20,0);
  auVar192._12_2_ = 0xe6;
  auVar192._14_2_ = 0xe7;
  auVar191._12_4_ = auVar192._12_4_;
  auVar191._0_10_ = SUB1610(auVar58 << 0x20,0);
  auVar191._10_2_ = 0xe5;
  auVar190._10_6_ = auVar191._10_6_;
  auVar190._0_10_ = (unkuint10)0xe4 << 0x40;
  auVar193._8_8_ = auVar190._8_8_;
  auVar193._6_2_ = 0xe3;
  auVar193._4_2_ = 0xe2;
  auVar193._0_4_ = 0xe100e0;
  auVar193 = auVar193 & _DAT_00267f50;
  auVar61._10_6_ = 0;
  auVar61._0_10_ = (unkuint10)0xee;
  auVar60._12_4_ = 0;
  auVar60._0_12_ = SUB1612(auVar61 << 0x30,4);
  auVar132._0_12_ = SUB1612(auVar60 << 0x20,0);
  auVar132._12_2_ = 0xee;
  auVar132._14_2_ = 0xef;
  auVar131._12_4_ = auVar132._12_4_;
  auVar131._0_10_ = SUB1610(auVar60 << 0x20,0);
  auVar131._10_2_ = 0xed;
  auVar130._10_6_ = auVar131._10_6_;
  auVar130._0_10_ = (unkuint10)0xec << 0x40;
  auVar133._8_8_ = auVar130._8_8_;
  auVar133._6_2_ = 0xeb;
  auVar133._4_2_ = 0xea;
  auVar133._0_4_ = 0xe900e8;
  auVar133 = auVar133 & _DAT_00267f50;
  uVar1 = auVar193._0_2_;
  texgammatable[0xe0] = (uVar1 != 0) * (uVar1 < 0x100) * auVar193[0] - (0xff < uVar1);
  uVar1 = auVar193._2_2_;
  texgammatable[0xe1] = (uVar1 != 0) * (uVar1 < 0x100) * auVar193[2] - (0xff < uVar1);
  uVar1 = auVar193._4_2_;
  texgammatable[0xe2] = (uVar1 != 0) * (uVar1 < 0x100) * auVar193[4] - (0xff < uVar1);
  uVar1 = auVar193._6_2_;
  texgammatable[0xe3] = (uVar1 != 0) * (uVar1 < 0x100) * auVar193[6] - (0xff < uVar1);
  sVar2 = auVar193._8_2_;
  texgammatable[0xe4] = (0 < sVar2) * (sVar2 < 0x100) * auVar193[8] - (0xff < sVar2);
  sVar2 = auVar193._10_2_;
  texgammatable[0xe5] = (0 < sVar2) * (sVar2 < 0x100) * auVar193[10] - (0xff < sVar2);
  sVar2 = auVar193._12_2_;
  texgammatable[0xe6] = (0 < sVar2) * (sVar2 < 0x100) * auVar193[0xc] - (0xff < sVar2);
  sVar2 = auVar193._14_2_;
  texgammatable[0xe7] = (0 < sVar2) * (sVar2 < 0x100) * auVar193[0xe] - (0xff < sVar2);
  uVar1 = auVar133._0_2_;
  texgammatable[0xe8] = (uVar1 != 0) * (uVar1 < 0x100) * auVar133[0] - (0xff < uVar1);
  uVar1 = auVar133._2_2_;
  texgammatable[0xe9] = (uVar1 != 0) * (uVar1 < 0x100) * auVar133[2] - (0xff < uVar1);
  uVar1 = auVar133._4_2_;
  texgammatable[0xea] = (uVar1 != 0) * (uVar1 < 0x100) * auVar133[4] - (0xff < uVar1);
  uVar1 = auVar133._6_2_;
  texgammatable[0xeb] = (uVar1 != 0) * (uVar1 < 0x100) * auVar133[6] - (0xff < uVar1);
  sVar2 = auVar133._8_2_;
  texgammatable[0xec] = (0 < sVar2) * (sVar2 < 0x100) * auVar133[8] - (0xff < sVar2);
  sVar2 = auVar133._10_2_;
  texgammatable[0xed] = (0 < sVar2) * (sVar2 < 0x100) * auVar133[10] - (0xff < sVar2);
  sVar2 = auVar133._12_2_;
  texgammatable[0xee] = (0 < sVar2) * (sVar2 < 0x100) * auVar133[0xc] - (0xff < sVar2);
  sVar2 = auVar133._14_2_;
  texgammatable[0xef] = (0 < sVar2) * (sVar2 < 0x100) * auVar133[0xe] - (0xff < sVar2);
  auVar63._10_6_ = 0;
  auVar63._0_10_ = (unkuint10)0xf6;
  auVar62._12_4_ = 0;
  auVar62._0_12_ = SUB1612(auVar63 << 0x30,4);
  auVar196._0_12_ = SUB1612(auVar62 << 0x20,0);
  auVar196._12_2_ = 0xf6;
  auVar196._14_2_ = 0xf7;
  auVar195._12_4_ = auVar196._12_4_;
  auVar195._0_10_ = SUB1610(auVar62 << 0x20,0);
  auVar195._10_2_ = 0xf5;
  auVar194._10_6_ = auVar195._10_6_;
  auVar194._0_10_ = (unkuint10)0xf4 << 0x40;
  auVar197._8_8_ = auVar194._8_8_;
  auVar197._6_2_ = 0xf3;
  auVar197._4_2_ = 0xf2;
  auVar197._0_4_ = player_8bit_texels + 0x4ff0;
  auVar197 = auVar197 & _DAT_00267f50;
  auVar65._10_6_ = 0;
  auVar65._0_10_ = (unkuint10)0xfe;
  auVar64._12_4_ = 0;
  auVar64._0_12_ = SUB1612(auVar65 << 0x30,4);
  auVar72._0_12_ = SUB1612(auVar64 << 0x20,0);
  auVar72._12_2_ = 0xfe;
  auVar72._14_2_ = 0xff;
  auVar71._12_4_ = auVar72._12_4_;
  auVar71._0_10_ = SUB1610(auVar64 << 0x20,0);
  auVar71._10_2_ = 0xfd;
  auVar70._10_6_ = auVar71._10_6_;
  auVar70._0_10_ = (unkuint10)0xfc << 0x40;
  auVar73._8_8_ = auVar70._8_8_;
  auVar73._6_2_ = 0xfb;
  auVar73._4_2_ = 0xfa;
  auVar73._0_4_ = 0xf900f8;
  auVar73 = _DAT_00267f50 & auVar73;
  uVar1 = auVar197._0_2_;
  texgammatable[0xf0] = (uVar1 != 0) * (uVar1 < 0x100) * auVar197[0] - (0xff < uVar1);
  uVar1 = auVar197._2_2_;
  texgammatable[0xf1] = (uVar1 != 0) * (uVar1 < 0x100) * auVar197[2] - (0xff < uVar1);
  uVar1 = auVar197._4_2_;
  texgammatable[0xf2] = (uVar1 != 0) * (uVar1 < 0x100) * auVar197[4] - (0xff < uVar1);
  uVar1 = auVar197._6_2_;
  texgammatable[0xf3] = (uVar1 != 0) * (uVar1 < 0x100) * auVar197[6] - (0xff < uVar1);
  sVar2 = auVar197._8_2_;
  texgammatable[0xf4] = (0 < sVar2) * (sVar2 < 0x100) * auVar197[8] - (0xff < sVar2);
  sVar2 = auVar197._10_2_;
  texgammatable[0xf5] = (0 < sVar2) * (sVar2 < 0x100) * auVar197[10] - (0xff < sVar2);
  sVar2 = auVar197._12_2_;
  texgammatable[0xf6] = (0 < sVar2) * (sVar2 < 0x100) * auVar197[0xc] - (0xff < sVar2);
  sVar2 = auVar197._14_2_;
  texgammatable[0xf7] = (0 < sVar2) * (sVar2 < 0x100) * auVar197[0xe] - (0xff < sVar2);
  uVar1 = auVar73._0_2_;
  texgammatable[0xf8] = (uVar1 != 0) * (uVar1 < 0x100) * auVar73[0] - (0xff < uVar1);
  uVar1 = auVar73._2_2_;
  texgammatable[0xf9] = (uVar1 != 0) * (uVar1 < 0x100) * auVar73[2] - (0xff < uVar1);
  uVar1 = auVar73._4_2_;
  texgammatable[0xfa] = (uVar1 != 0) * (uVar1 < 0x100) * auVar73[4] - (0xff < uVar1);
  uVar1 = auVar73._6_2_;
  texgammatable[0xfb] = (uVar1 != 0) * (uVar1 < 0x100) * auVar73[6] - (0xff < uVar1);
  sVar2 = auVar73._8_2_;
  texgammatable[0xfc] = (0 < sVar2) * (sVar2 < 0x100) * auVar73[8] - (0xff < sVar2);
  sVar2 = auVar73._10_2_;
  texgammatable[0xfd] = (0 < sVar2) * (sVar2 < 0x100) * auVar73[10] - (0xff < sVar2);
  sVar2 = auVar73._12_2_;
  texgammatable[0xfe] = (0 < sVar2) * (sVar2 < 0x100) * auVar73[0xc] - (0xff < sVar2);
  sVar2 = auVar73._14_2_;
  texgammatable[0xff] = (0 < sVar2) * (sVar2 < 0x100) * auVar73[0xe] - (0xff < sVar2);
                    /* WARNING: Read-only address (ram,0x00267f50) is written */
  ppic = W_GetLumpName(0,"lambda");
  draw_disc = LoadTransPic("lambda",ppic);
                    /* Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: int num@[???] */
  iVar69 = __isoc99_sscanf(con_color.string,"%i %i %i",&local_28,&local_24,local_20);
  if (iVar69 != 3) {
    return;
  }
  VGUI2_Draw_SetTextColor(local_28,local_24,local_20[0]);
  return;
}


// Draw_MessageCharacterAdd  @ 001593e0
int Draw_MessageCharacterAdd(int x,int y,int num,int rr,int gg,int bb,uint font)

{
  ISurface *pIVar1;
  int iVar2;
  int iStack_18;
  int iStack_14;
  int aiStack_10 [2];
  
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x19])
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
  return iStack_14 + iStack_18 + aiStack_10[0];
}


// Draw_MessageFontInfo  @ 001593d0
int Draw_MessageFontInfo(short *pWidth,uint font)

{
  int iVar1;
  
  iVar1 = VGUI2_GetFontTall(font);
  return iVar1;
}


// Draw_MiptexTexture  @ 00160570
void Draw_MiptexTexture(cachewad_t *wad,byte *data)

{
  uint uVar1;
  int32 iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  gltexture_t *dest;
  byte *pPal;
  int in_GS_OFFSET;
  int in_stack_ffffff80;
  byte *in_stack_ffffff84;
  int in_stack_ffffff88;
  int32 local_48 [10];
  int local_20;
  
                    /* Unresolved local var: texture_t * tex@[???]
                       Unresolved local var: miptex_t * mip@[???]
                       Unresolved local var: miptex_t tmp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int paloffset@[???]
                       Unresolved local var: int palettesize@[???]
                       Unresolved local var: byte * pal@[???]
                       Unresolved local var: byte * bitmap@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (wad->cacheExtra != 0x20) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Draw_MiptexTexture: Bad cached wad %s\n",wad->name);
  }
  uVar1 = 0;
  do {
    *(undefined4 *)((int)local_48 + uVar1) = *(undefined4 *)(data + uVar1 + 0x20);
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x28);
  iVar5 = 0;
  Q_memcpy(data,local_48,0x10);
  iVar2 = (*LittleLong)(local_48[4]);
  *(int32 *)(data + 0x10) = iVar2;
  iVar2 = (*LittleLong)(local_48[5]);
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
  *(int32 *)(data + 0x14) = iVar2;
  do {
    iVar2 = (*LittleLong)(local_48[iVar5 + 6]);
    *(int32 *)(data + iVar5 * 4 + 0x34) = iVar2 + wad->cacheExtra;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 4);
  iVar5 = *(int *)(data + 0x34);
  iVar3 = *(int *)(data + 0x10) * *(int *)(data + 0x14);
  pPal = data + iVar5 + 2 + iVar3 + (iVar3 >> 6) + (iVar3 >> 2) + (iVar3 >> 4);
  if (gfCustomBuild != false) {
    Q_strncpy((char *)data,szCustName,0xf);
    data[0xf] = '\0';
  }
  if (((pPal[0x2fd] == '\0') && (pPal[0x2fe] == '\0')) && (pPal[0x2ff] == 0xff)) {
    *data = '{';
    iVar5 = GL_LoadTexture2((char *)data,GLT_DECAL,*(int *)(data + 0x10),*(int *)(data + 0x14),
                            data + iVar5,true,1,pPal,gl_filter_max);
    *(int *)(data + 0x18) = iVar5;
  }
  else {
    *data = '}';
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???] */
    if ((gfCustomBuild != false) && (0 < numgltextures)) {
      iVar3 = 0;
      dest = gltextures;
      do {
        iVar4 = Q_strcmp((char *)data,dest->identifier);
        if (iVar4 == 0) {
          if ((short)(dest->servercount & -0x8000) == 0) {
                    /* Unresolved local var: int texnum@[???] */
            (*qglDeleteTextures)(1,(GLuint *)dest);
            iVar3 = (int)dest->paletteIndex;
            if (-1 < iVar3) {
              if (gGLPalette[iVar3].referenceCount < 2) {
                if (iVar3 < 0x15e) {
                  gGLPalette[iVar3].tag = -1;
                  gGLPalette[iVar3].referenceCount = 0;
                }
              }
              else {
                gGLPalette[iVar3].referenceCount = gGLPalette[iVar3].referenceCount + -1;
              }
            }
            Q_memset(dest,0,0x54);
            dest->servercount = -1;
          }
          break;
        }
        iVar3 = iVar3 + 1;
        dest = dest + 1;
      } while (iVar3 < numgltextures);
    }
    iVar5 = GL_LoadTexture2((char *)data,*(GL_TEXTURETYPE *)(data + 0x10),*(int *)(data + 0x14),
                            (int)(data + iVar5),pPal,gl_filter_max,in_stack_ffffff80,
                            in_stack_ffffff84,in_stack_ffffff88);
    *(int *)(data + 0x18) = iVar5;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_Pic  @ 001595f0
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
                    /* WARNING: Could not recover jumptable at 0x00159812. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglEnd)();
    return;
  }
  return;
}


// Draw_Pic2  @ 0015a0b0
void Draw_Pic2(int x,int y,int w,int h,qpic_t *pic)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: glpic_t * gl@[???] */
  if (pic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    (*qglEnable)(0xde1);
    (*qglDisable)(0xbe2);
    (*qglEnable)(0xbc0);
    (*qglTexEnvf)(0x2300,0x2200,7681.0);
    (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
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
    (*qglVertex2f)((float)(w + x),(float)y);
    (*qglTexCoord2f)(*(GLfloat *)pic[1].data,(GLfloat)pic[2].width);
    fVar2 = (float)(h + -1 + y);
    (*qglVertex2f)((float)(w + x),fVar2);
    (*qglTexCoord2f)((GLfloat)pic[1].width,(GLfloat)pic[2].width);
    (*qglVertex2f)((float)x,fVar2);
                    /* WARNING: Could not recover jumptable at 0x0015a2c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglEnd)();
    return;
  }
  return;
}


// Draw_PicFromWad  @ 0015cf20
qpic_t * Draw_PicFromWad(char *name)

{
  qpic_t *pqVar1;
  int iVar2;
  byte *unaff_EBX;
  int unaff_ESI;
  int in_stack_fffffff0;
  
                    /* Unresolved local var: qpic_t * p@[???]
                       Unresolved local var: glpic_t * gl@[???] */
  pqVar1 = W_GetLumpName(0,name);
                    /* Unresolved local var: byte * pPal@[???] */
  iVar2 = GL_LoadTexture2(name,pqVar1->width,pqVar1->height,(int)pqVar1->data,
                          pqVar1->data + pqVar1->width * pqVar1->height + 2,gl_filter_max,
                          in_stack_fffffff0,unaff_EBX,unaff_ESI);
  *(int *)pqVar1->data = iVar2;
  pqVar1[1].width = 0;
  pqVar1[1].data[0] = '\0';
  pqVar1[1].data[1] = '\0';
  pqVar1[1].data[2] = 0x80;
  pqVar1[1].data[3] = '?';
  pqVar1[1].height = 0;
  pqVar1[2].width = 0x3f800000;
  return pqVar1;
}


// Draw_ResetTextColor  @ 00159400
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


// Draw_SetTextColor  @ 00159460
void Draw_SetTextColor(float r,float g,float b)

{
  (*g_engdstAddrs.pfnDrawSetTextColor)(&r,&g,&b);
  VGUI2_Draw_SetTextColor((int)(r * 255.0),(int)(g * 255.0),(int)(b * 255.0));
  return;
}


// Draw_Shutdown  @ 000a99c0
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


// Draw_SpriteFrame  @ 0015acd0
void Draw_SpriteFrame(mspriteframe_t *pFrame,word *pPalette,int x,int y,wrect_t *prcSubRect)

{
  Draw_Frame(pFrame,x,y,prcSubRect);
  return;
}


// Draw_SpriteFrameAdditive  @ 0015ada0
void Draw_SpriteFrameAdditive(mspriteframe_t *pFrame,word *pPalette,int x,int y,wrect_t *prcSubRect)

{
  (*qglEnable)(0xbe2);
  (*qglBlendFunc)(1,1);
  Draw_Frame(pFrame,x,y,prcSubRect);
                    /* WARNING: Could not recover jumptable at 0x0015ae16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglDisable)(0xbe2);
  return;
}


// Draw_SpriteFrameGeneric  @ 0015ae20
void Draw_SpriteFrameGeneric
               (mspriteframe_t *pFrame,word *pPalette,int x,int y,wrect_t *prcSubRect,int src,
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


// Draw_SpriteFrameHoles  @ 0015acf0
void Draw_SpriteFrameHoles(mspriteframe_t *pFrame,word *pPalette,int x,int y,wrect_t *prcSubRect)

{
  (*qglEnable)(0xbc0);
  if (gl_spriteblend.value != 0.0) {
    (*qglBlendFunc)(0x302,0x303);
    (*qglEnable)(0xbe2);
  }
  Draw_Frame(pFrame,x,y,prcSubRect);
  (*qglDisable)(0xbc0);
                    /* WARNING: Could not recover jumptable at 0x0015ad6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglDisable)(0xbe2);
  return;
}


// Draw_String  @ 00159540
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
    return x + iVar1;
  }
  VGUI2_Draw_SetTextColor(local_18,local_14,local_10[0]);
  return x + iVar1;
}


// Draw_StringLen  @ 001593c0
int Draw_StringLen(char *psz,uint font)

{
  ILocalize *pIVar1;
  ISurface *pIVar2;
  size_t sVar3;
  uint uVar4;
  wchar_t *__s;
  int iVar5;
  int iStack_28;
  int iStack_24;
  int aiStack_20 [4];
  
  if ((psz != (char *)0x0) && (*psz == '#')) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,psz);
    if (__s != (wchar_t *)0x0) goto LAB_001d1510;
  }
  pIVar1 = vgui2::localize();
  __s = VGUI2_Find_String::tmpString;
  (**(code **)(*(int *)pIVar1 + 0x14))(pIVar1,psz,VGUI2_Find_String::tmpString,0x1000);
LAB_001d1510:
  iVar5 = 0;
  for (uVar4 = 0; sVar3 = wcslen(__s), uVar4 < sVar3; uVar4 = uVar4 + 1) {
    pIVar2 = vgui2::surface();
    (*(pIVar2->super_IBaseInterface)._vptr_IBaseInterface[0x40])
              (pIVar2,font,__s[uVar4],&iStack_28,&iStack_24,aiStack_20);
    iVar5 = iVar5 + iStack_24 + iStack_28 + aiStack_20[0];
  }
  return iVar5;
}


// Draw_TileClear  @ 0015b420
void Draw_TileClear(int x,int y,int w,int h)

{
  Draw_FillRGBA(x,y,w,h,0,0,0,0xff);
  return;
}


// Draw_TransPic  @ 0015a2e0
void Draw_TransPic(int x,int y,qpic_t *pic)

{
  if (pic == (qpic_t *)0x0) {
    return;
  }
  if ((((-1 < x) && ((uint)(pic->width + x) <= vid.width)) && (-1 < y)) &&
     ((uint)(pic->height + y) <= vid.height)) {
    Draw_Pic(x,y,pic);
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Draw_TransPic: bad coordinates");
}


// Draw_TransPicTranslate  @ 0015a370
void Draw_TransPicTranslate(int x,int y,qpic_t *pic,byte *translation)

{
  int iVar1;
  int iVar2;
  GLuint *pGVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  GLuint *pGVar7;
  GLuint *pGVar8;
  GLuint local_401c [4096];
  GLuint local_1c [3];
  
                    /* Unresolved local var: int v@[???]
                       Unresolved local var: int u@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: uint[4096] trans@[???]
                       Unresolved local var: uint * dest@[???]
                       Unresolved local var: byte * src@[???]
                       Unresolved local var: int p@[???] */
  if (pic != (qpic_t *)0x0) {
    VGUI2_ResetCurrentTexture();
    if (translate_texture == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
      (*qglGenTextures)(1,local_401c);
      translate_texture = local_401c[0];
    }
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar4 = translate_texture & 0xffff;
    if (uVar4 != currenttexture) {
      iVar1 = (translate_texture >> 0x10) + -1;
      currenttexture = uVar4;
      (*qglBindTexture)(0xde1,uVar4);
      if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar1;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,gGLPalette[iVar1].colors);
      }
    }
    iVar6 = 0;
    iVar1 = pic->width;
    iVar2 = pic->height;
    pGVar7 = local_401c;
    do {
      pGVar8 = pGVar7 + 0x40;
      iVar5 = 0;
      do {
        while (pGVar3 = pGVar7, menuplyr_pixels[(iVar5 >> 6) + (iVar6 >> 6) * iVar1] == 0xff) {
          *pGVar3 = 0xff;
          iVar5 = iVar5 + iVar1;
          pGVar7 = pGVar3 + 1;
          if (pGVar3 + 1 == pGVar8) goto LAB_0015a499;
        }
        *pGVar3 = 0xff0000ff;
        iVar5 = iVar5 + iVar1;
        pGVar7 = pGVar3 + 1;
      } while (pGVar3 + 1 != pGVar8);
LAB_0015a499:
      iVar6 = iVar6 + iVar2;
      pGVar7 = pGVar8;
    } while (pGVar3 + 1 != local_1c);
    (*qglTexImage2D)(0xde1,0,0x8058,0x40,0x40,0,0x1908,0x1401,local_401c);
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


// Draw_ValidateCustomLogo  @ 000aaaa0
qboolean Draw_ValidateCustomLogo(cachewad_t *wad,byte *data,lumpinfo_t *lump)

{
  qboolean qVar1;
  uint uVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  int local_90 [4];
  int32 local_80;
  int32 local_7c;
  int local_78 [4];
  uint local_68 [18];
  int local_20;
  
                    /* Unresolved local var: texture_t tex@[???]
                       Unresolved local var: miptex_t * mip@[???]
                       Unresolved local var: miptex_t tmp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int paloffset@[???]
                       Unresolved local var: int palettesize@[???]
                       Unresolved local var: int size@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (wad->cacheExtra == 0x20) {
    uVar2 = 0;
    do {
      *(undefined4 *)((int)local_90 + uVar2) = *(undefined4 *)(data + uVar2 + 0x20);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x28);
    uVar2 = 0;
    do {
      *(undefined4 *)((int)local_68 + uVar2) = *(undefined4 *)(data + uVar2);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x48);
    iVar4 = 0;
    Q_memcpy(local_68,local_90,0x10);
    local_68[4] = (*LittleLong)(local_80);
    local_68[5] = (*LittleLong)(local_7c);
    local_68[10] = 0;
    local_68[9] = 0;
    local_68[8] = 0;
    local_68[0xc] = 0;
    local_68[0xb] = 0;
    do {
      iVar3 = (*LittleLong)(local_90[iVar4 + 6]);
      iVar5 = wad->cacheExtra;
      local_68[iVar4 + 0xd] = iVar3 + iVar5;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 4);
    if (((local_68[4] == 0) || (0xff < local_68[5] - 1)) || (0x100 < local_68[4])) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad tex size %ux%u on %s\n",local_68[4],
                 local_68[5],wad->name);
      qVar1 = false;
      goto LAB_000aab09;
    }
    iVar4 = local_68[4] * local_68[5];
    uVar2 = iVar5 + lump->size;
    iVar5 = (iVar4 >> 2) + (iVar4 >> 4) + (iVar4 >> 6) + iVar4;
    if (uVar2 <= iVar5 + 0x28U) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad size %i/%i on %s\n",iVar5 + 0x28U,uVar2,
                 wad->name);
      iVar4 = local_68[4] * local_68[5];
    }
    uVar2 = (uint)*(ushort *)(data + iVar5 + 0x48);
    if (((local_78[1] == iVar4 + local_78[0]) && (local_78[2] == local_78[1] + (iVar4 >> 2))) &&
       ((iVar4 >> 4) + local_78[2] == local_78[3])) {
      if (0x100 < uVar2) {
        Con_Printf("Draw_ValidateCustomLogo: Bad cached wad palette size %i on %s\n",uVar2,wad->name
                  );
        qVar1 = false;
        goto LAB_000aab09;
      }
      iVar3 = (*LittleLong)(local_78[0]);
      qVar1 = true;
      if (iVar5 + iVar3 + uVar2 * 3 + 2 <= (uint)lump->disksize) goto LAB_000aab09;
    }
  }
  Con_Printf("Draw_ValidateCustomLogo: Bad cached wad %s\n",wad->name);
  qVar1 = false;
LAB_000aab09:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar1;
}


