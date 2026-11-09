// Draw_AllocateCacheSpace  @ 00068ad0
void Draw_AllocateCacheSpace(cachewad_t *wad,int cacheMax,int tempWad)

{
  cachepic_t *dest;
  
                    /* Unresolved local var: int len@[???] */
  dest = Mem_Malloc(cacheMax * 0x44);
  wad->cache = dest;
  Q_memset(dest,0,cacheMax * 0x44);
  return;
}


// Draw_CacheByIndex  @ 00069260
int Draw_CacheByIndex(cachewad_t *wad,int nIndex,int playernum)

{
  int iVar1;
  int iVar2;
  cachepic_t *s1;
  char local_3c [44];
  
                    /* Unresolved local var: cachepic_t * pic@[???]
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


// Draw_CacheFindIndex  @ 0006a7c0
int Draw_CacheFindIndex(cachewad_t *wad,char *path)

{
  int iVar1;
  int iVar2;
  cachepic_t *s2;
  
                    /* Unresolved local var: cachepic_t * pic@[???]
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


// Draw_CacheGet  @ 00069e80
void * Draw_CacheGet(cachewad_t *wad,int index)

{
  void *pvVar1;
  char *pcVar2;
  int iVar3;
  qboolean qVar4;
  int i;
  cachepic_t *pic;
  lumpinfo_t *pLump;
  char local_3c [16];
  char local_2c [28];
  
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[DW_OP_reg6(ESI)] */
  if (wad->cacheCount <= index) {
    Sys_Error("Cache wad indexed before load %s: %d",wad->name,index);
  }
  pic = wad->cache + index;
  pvVar1 = Cache_Check(&pic->cache);
  if (pvVar1 == (void *)0x0) {
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
        do {
          iVar3 = Q_strcmp(local_2c,pLump->name);
          if (iVar3 == 0) {
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
          i = i + 1;
          pLump = pLump + 1;
        } while (i < wad->lumpCount);
      }
    }
  }
  return pvVar1;
}


// Draw_CacheIndex  @ 0006a720
int Draw_CacheIndex(cachewad_t *wad,char *path)

{
  int iVar1;
  int iVar2;
  cachepic_t *s2;
  
                    /* Unresolved local var: cachepic_t * pic@[???]
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


// Draw_CacheLoadFromCustom  @ 0006a2a0
qboolean Draw_CacheLoadFromCustom(char *clean,cachewad_t *wad,void *raw,int rawsize,cachepic_t *pic)

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


// Draw_CacheReload  @ 00069d30
qboolean Draw_CacheReload(cachewad_t *wad,int i,lumpinfo_t *pLump,cachepic_t *pic,char *clean,
                         char *path)

{
  FileHandle_t file;
  qboolean qVar1;
  uchar *puVar2;
  
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
    puVar2 = Cache_Alloc(&pic->cache,pLump->size + wad->cacheExtra + 1,clean);
    if (puVar2 == (uchar *)0x0) {
      Sys_Error("Draw_CacheGet: not enough space for %s in %s",path,wad->name);
    }
    puVar2[wad->cacheExtra + pLump->size] = '\0';
    FS_Seek(file,pLump->filepos,FILESYSTEM_SEEK_HEAD);
    FS_Read(puVar2 + wad->cacheExtra,pLump->size,1,file);
    FS_Close(file);
    qVar1 = true;
    if (wad->pfnCacheBuild != (PFNCACHE)0x0) {
      (*wad->pfnCacheBuild)(wad,puVar2);
      qVar1 = true;
    }
  }
  return qVar1;
}


// Draw_CacheWadHandler  @ 00068ee0
void Draw_CacheWadHandler(cachewad_t *wad,PFNCACHE fn,int extraDataSize)

{
  wad->pfnCacheBuild = fn;
  wad->cacheExtra = extraDataSize;
  return;
}


// Draw_CacheWadInit  @ 00068c50
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


// Draw_CacheWadInitFromFile  @ 00068b20
void Draw_CacheWadInitFromFile(FileHandle_t hFile,int len,char *name,int cacheMax,cachewad_t *wad)

{
  lumpinfo_s *plVar1;
  char *pcVar2;
  cachepic_t *dest;
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
  wad->pfnCacheBuild = (PFNCACHE)0x0;
  wad->cacheExtra = 0;
  return;
}


// Draw_CustomCacheGet  @ 0006a3f0
void * Draw_CustomCacheGet(cachewad_t *wad,void *raw,int rawsize,int index)

{
  void *pvVar1;
  char *pcVar2;
  qboolean qVar3;
  cachepic_t *pic;
  char local_3c [16];
  char local_2c [28];
  
                    /* Unresolved local var: cachepic_t * pic@[???]
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


// Draw_CustomCacheWadInit  @ 000688e0
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
  if (wad->cache == (cachepic_t *)0x1) {
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


// Draw_CustomCacheWadInit  @ 00068ce0
qboolean Draw_CustomCacheWadInit(int cacheMax,cachewad_t *wad,void *raw,int nFileSize)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  qboolean qVar4;
  lumpinfo_s *plVar5;
  char *pcVar6;
  cachepic_t *dest;
  
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


// Draw_DecalCount  @ 000691f0
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


// Draw_DecalIndex  @ 000690b0
int Draw_DecalIndex(int id)

{
  cachewad_t *pcVar1;
  qboolean qVar2;
  int iVar3;
  int iVar4;
  char (*s1) [16];
  cachepic_t *s2;
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
    snprintf((char *)s1,0x20,"{yblood%s",id * 0x10 + 0x2f7dc6);
  }
  pcVar1 = decal_wad;
                    /* Unresolved local var: cachepic_t * pic@[???]
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


// Draw_DecalIndexFromName  @ 00069330
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


// Draw_DecalName  @ 00069230
char * Draw_DecalName(int number)

{
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    return decal_wad->lumps[number].name;
  }
  return (char *)0x0;
}


// Draw_DecalSetName  @ 00069070
void Draw_DecalSetName(int decal,char *name)

{
  if (decal < 0x200) {
    Q_strncpy(decal_names[decal],name,0xf);
    decal_names[decal][0xf] = '\0';
  }
  return;
}


// Draw_DecalShutdown  @ 00069000
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


// Draw_DecalSize  @ 00069200
int Draw_DecalSize(int number)

{
  int iVar1;
  
  iVar1 = 0;
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    iVar1 = decal_wad->lumps[number].size;
  }
  return iVar1;
}


// Draw_DecalTexture  @ 0006a660
texture_t * Draw_DecalTexture(int index)

{
  customization_s *pcVar1;
  texture_t *ptVar2;
  uint uVar3;
  
                    /* Unresolved local var: int playernum@[???]
                       Unresolved local var: customization_t * pCust@[???] */
  if (index < 0) {
    uVar3 = ~index;
    pcVar1 = cl.players[uVar3].customdata.pNext;
    if ((((pcVar1 == (customization_s *)0x0) || (pcVar1->bInUse == false)) ||
        (pcVar1->pInfo == (cachewad_t *)0x0)) || (pcVar1->pBuffer == (void *)0x0)) {
      Sys_Error("Failed to load custom decal for player #%i:%s using default decal 0.\n",uVar3,
                uVar3 * 0x250 + 0x2ec924);
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


// Draw_FreeWad  @ 00068f00
void Draw_FreeWad(cachewad_t *pWad)

{
  void *pvVar1;
  cachepic_t *p;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: cachepic_t * pic@[???]
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
    if (p != (cachepic_t *)0x0) {
                    /* Unresolved local var: int i@[???] */
      if (0 < pWad->cacheCount) {
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


// Draw_Init  @ 000c7950
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Draw_Init(void)

{
  return;
}


// Draw_MiptexTexture  @ 00068720
void Draw_MiptexTexture(cachewad_t *wad,uchar *data)

{
  int iVar1;
  ushort uVar2;
  uchar uVar3;
  uint uVar4;
  int32 iVar5;
  int iVar6;
  int iVar7;
  int32 local_34 [10];
  
                    /* Unresolved local var: texture_t * tex@[???]
                       Unresolved local var: miptex_t * mip@[???]
                       Unresolved local var: miptex_t tmp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int palette@[???]
                       Unresolved local var: uchar * pal@[???] */
  iVar7 = 0x18;
  if (wad->cacheExtra != 0x18) {
    Sys_Error("Draw_MiptexTexture: Bad cached wad %s\n",wad->name);
    iVar7 = wad->cacheExtra;
  }
  uVar4 = 0;
  do {
    *(undefined4 *)((int)local_34 + uVar4) = *(undefined4 *)(data + uVar4 + iVar7);
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x28);
  Q_memcpy(data,local_34,0x10);
  iVar5 = (*LittleLong)(local_34[4]);
  *(int32 *)(data + 0x10) = iVar5;
  iVar5 = (*LittleLong)(local_34[5]);
  data[0x20] = '\0';
  data[0x21] = '\0';
  data[0x22] = '\0';
  data[0x23] = '\0';
  data[0x1c] = '\0';
  data[0x1d] = '\0';
  data[0x1e] = '\0';
  data[0x1f] = '\0';
  data[0x18] = '\0';
  data[0x19] = '\0';
  data[0x1a] = '\0';
  data[0x1b] = '\0';
  data[0x28] = '\0';
  data[0x29] = '\0';
  data[0x2a] = '\0';
  data[0x2b] = '\0';
  data[0x24] = '\0';
  data[0x25] = '\0';
  data[0x26] = '\0';
  data[0x27] = '\0';
  *(int32 *)(data + 0x14) = iVar5;
  iVar5 = (*LittleLong)(local_34[6]);
  *(int32 *)(data + 0x2c) = iVar5 + wad->cacheExtra;
  iVar5 = (*LittleLong)(local_34[7]);
  *(int32 *)(data + 0x30) = iVar5 + wad->cacheExtra;
  iVar5 = (*LittleLong)(local_34[8]);
  *(int32 *)(data + 0x34) = iVar5 + wad->cacheExtra;
  iVar5 = (*LittleLong)(local_34[9]);
  *(int32 *)(data + 0x38) = iVar5 + wad->cacheExtra;
  iVar6 = *(int *)(data + 0x14) * *(int *)(data + 0x10);
  iVar6 = iVar6 + (iVar6 >> 6) + (iVar6 >> 2) + (iVar6 >> 4);
  iVar1 = iVar6 + 2 + *(int *)(data + 0x2c);
  *(int *)(data + 0x3c) = iVar1;
  uVar2 = *(ushort *)(data + iVar6 + iVar7 + 0x28);
  if (gfCustomBuild != false) {
    Q_strncpy((char *)data,szCustName,0xf);
    data[0xf] = '\0';
  }
  uVar3 = '}';
  if ((data[iVar1 + 0x2fd] == '\0') && (data[iVar1 + 0x2fe] == '\0')) {
    uVar3 = ((data[iVar1 + 0x2ff] != 0xff) - 1U & 0xfe) + 0x7d;
  }
  *data = uVar3;
  if (uVar2 != 0) {
    iVar7 = 0;
    do {
      data[iVar7 + iVar1] = texgammatable[data[iVar7 + iVar1]];
      data[iVar7 + iVar1 + 1] = texgammatable[data[iVar7 + iVar1 + 1]];
      data[iVar7 + iVar1 + 2] = texgammatable[data[iVar7 + iVar1 + 2]];
      iVar7 = iVar7 + 3;
    } while (iVar7 != (uint)uVar2 * 3);
  }
  return;
}


// Draw_Shutdown  @ 00069030
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


// Draw_ValidateCustomLogo  @ 00069ff0
qboolean Draw_ValidateCustomLogo(cachewad_t *wad,uchar *data,lumpinfo_t *lump)

{
  uint uVar1;
  int32 iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_8c [16];
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
  if (wad->cacheExtra == 0x18) {
    uVar1 = 0;
    do {
      *(undefined4 *)((int)local_4c + uVar1) = *(undefined4 *)(data + uVar1 + 0x18);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x28);
    uVar1 = 0;
    do {
      *(undefined4 *)((int)local_8c + uVar1) = *(undefined4 *)(data + uVar1);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x40);
    Q_memcpy(local_8c,local_4c,0x10);
    local_8c[4] = (*LittleLong)(local_3c);
    local_8c[5] = (*LittleLong)(local_38);
    local_8c[8] = 0;
    local_8c[7] = 0;
    local_8c[6] = 0;
    local_8c[10] = 0;
    local_8c[9] = 0;
    iVar2 = (*LittleLong)(local_34);
    local_8c[0xb] = iVar2 + wad->cacheExtra;
    iVar2 = (*LittleLong)(local_30);
    local_8c[0xc] = iVar2 + wad->cacheExtra;
    iVar2 = (*LittleLong)(local_2c);
    local_8c[0xd] = iVar2 + wad->cacheExtra;
    iVar2 = (*LittleLong)(local_28);
    local_8c[0xe] = iVar2 + wad->cacheExtra;
    if ((((local_8c[4] == 0) || (local_8c[5] == 0)) || (0x100 < local_8c[4])) ||
       (0x100 < local_8c[5])) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad tex size %ux%u on %s\n",local_8c[4],
                 local_8c[5],wad->name);
      return false;
    }
    iVar3 = local_8c[5] * local_8c[4];
    iVar5 = (iVar3 >> 2) + (iVar3 >> 4) + (iVar3 >> 6) + iVar3;
    uVar1 = wad->cacheExtra + lump->size;
    if (uVar1 <= iVar5 + 0x28U) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad size %i/%i on %s\n",iVar5 + 0x28U,uVar1,
                 wad->name);
      iVar3 = local_8c[5] * local_8c[4];
    }
    uVar1 = (uint)*(ushort *)(data + iVar5 + 0x40);
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


