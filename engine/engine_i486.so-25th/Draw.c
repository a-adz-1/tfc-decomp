// Draw_AllocateCacheSpace  @ 000457f0
void Draw_AllocateCacheSpace(cachewad_t *wad,int cacheMax,int tempWad)

{
  cachepic_t *dest;
  
                    /* Unresolved local var: int len@[???] */
  dest = Mem_Malloc(cacheMax * 0x44);
  wad->cache = dest;
  Q_memset(dest,0,cacheMax * 0x44);
  return;
}


// Draw_CacheByIndex  @ 00046010
int Draw_CacheByIndex(cachewad_t *wad,int nIndex,int playernum)

{
  int iVar1;
  int iVar2;
  cachepic_t *s1;
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[32] szTestName@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = 0;
  __snprintf_chk(local_40,0x20,1,0x20,"%03i%02i",playernum,nIndex);
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
      Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar1);
      iVar1 = wad->cacheCount;
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


// Draw_CacheFindIndex  @ 00047950
int Draw_CacheFindIndex(cachewad_t *wad,char *path)

{
  int iVar1;
  int iVar2;
  cachepic_t *s2;
  
                    /* Unresolved local var: cachepic_t * pic@[???]
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


// Draw_CacheGet  @ 00046c90
void * Draw_CacheGet(cachewad_t *wad,int index)

{
  void *pvVar1;
  char *pcVar2;
  int iVar3;
  qboolean qVar4;
  cachepic_t *pic;
  int i;
  lumpinfo_t *pLump;
  int in_GS_OFFSET;
  char local_40 [16];
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (wad->cacheCount <= index) {
    Sys_Error("Cache wad indexed before load %s: %d",wad->name,index);
  }
  pic = wad->cache + index;
  pvVar1 = Cache_Check(&pic->cache);
  if (pvVar1 == (void *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???]
                       Unresolved local var: lumpinfo_t * pLump@[???] */
    pcVar2 = COM_FileBase_s(pic->name,local_40,0x10);
    if (pcVar2 == (char *)0x0) {
      Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pic);
      pvVar1 = (void *)0x0;
    }
    else {
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
                if (pvVar1 != (void *)0x0) goto LAB_00046cd8;
                Sys_Error("Draw_CacheGet: failed to load %s",pic);
              }
            }
            break;
          }
          i = i + 1;
          pLump = pLump + 1;
        } while (i < wad->lumpCount);
      }
      pvVar1 = (void *)0x0;
    }
  }
LAB_00046cd8:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pvVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_CacheIndex  @ 000478b0
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


// Draw_CacheLoadFromCustom  @ 000470a0
qboolean Draw_CacheLoadFromCustom(char *clean,cachewad_t *wad,void *raw,int rawsize,cachepic_t *pic)

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


// Draw_CacheReload  @ 00046b40
qboolean Draw_CacheReload(cachewad_t *wad,int i,lumpinfo_t *pLump,cachepic_t *pic,char *clean,
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
    pbVar1 = Cache_Alloc(&pic->cache,wad->cacheExtra + pLump->size + 1,clean);
    if (pbVar1 == (byte *)0x0) {
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


// Draw_CacheWadHandler  @ 00045c40
void Draw_CacheWadHandler(cachewad_t *wad,PFNCACHE fn,int extraDataSize)

{
  wad->pfnCacheBuild = fn;
  wad->cacheExtra = extraDataSize;
  return;
}


// Draw_CacheWadInit  @ 00045990
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


// Draw_CacheWadInitFromFile  @ 00045840
void Draw_CacheWadInitFromFile(FileHandle_t hFile,int len,char *name,int cacheMax,cachewad_t *wad)

{
  lumpinfo_s *plVar1;
  char *pcVar2;
  cachepic_t *dest;
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
  wad->pfnCacheBuild = (PFNCACHE)0x0;
  wad->cacheExtra = 0;
  if (local_20 == iVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_CustomCacheGet  @ 00047200
void * Draw_CustomCacheGet(cachewad_t *wad,void *raw,int rawsize,int index)

{
  void *pvVar1;
  char *pcVar2;
  qboolean qVar3;
  cachepic_t *pic;
  void *pvVar4;
  int in_GS_OFFSET;
  char local_40 [16];
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (wad->cacheCount <= index) {
    Sys_Error("Cache wad indexed before load %s: %d",wad->name,index);
  }
  pic = wad->cache + index;
  pvVar1 = Cache_Check(&pic->cache);
  pvVar4 = pvVar1;
  if (pvVar1 == (void *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???] */
    pcVar2 = COM_FileBase_s(pic->name,local_40,0x10);
    if (pcVar2 == (char *)0x0) {
      Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pic);
    }
    else {
      W_CleanupName(local_40,local_30);
      qVar3 = Draw_CacheLoadFromCustom(local_30,wad,raw,rawsize,pic);
      if (qVar3 != false) {
        pvVar4 = (pic->cache).data;
        if (pvVar4 == (void *)0x0) {
          Sys_Error("Draw_CacheGet: failed to load %s",pic);
          pvVar4 = pvVar1;
        }
        goto LAB_00047257;
      }
    }
    pvVar4 = (void *)0x0;
  }
LAB_00047257:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar4;
}


// Draw_CustomCacheWadInit  @ 00045a20
qboolean Draw_CustomCacheWadInit(int cacheMax,cachewad_t *wad,void *raw,int nFileSize)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  qboolean qVar5;
  lumpinfo_s *plVar6;
  char *pcVar7;
  cachepic_t *dest;
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


// Draw_DecalCount  @ 00045f90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Draw_DecalCount(void)

{
  if (decal_wad != (cachewad_t *)0x0) {
    return decal_wad->lumpCount;
  }
  return 0;
}


// Draw_DecalIndex  @ 00045e20
int Draw_DecalIndex(int id)

{
  cachewad_t *pcVar1;
  qboolean qVar2;
  int iVar3;
  int iVar4;
  cachepic_t *s2;
  char (*s1) [16];
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: char[32] tmp@[???]
                       Unresolved local var: char * pName@[???]
                       Unresolved local var: cvar_t violence_hblood@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (decal_names[id][0] == '\0') {
    Sys_Error("Used decal #%d without a name\n",id);
  }
  qVar2 = Host_IsServerActive();
  s1 = decal_names + id;
  if (((qVar2 == false) && (violence_hblood.value == 0.0)) &&
     (iVar3 = Q_strncmp(*s1,"{blood",6), iVar3 == 0)) {
    s1 = (char (*) [16])local_40;
    __snprintf_chk(s1,0x20,1,0x20,"{yblood%s",id * 0x10 + 0x2f06c6);
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
  if (iVar4 == iVar3) {
    iVar3 = iVar4;
    if (pcVar1->cacheMax == iVar4) {
      Sys_Error("Cache wad (%s) out of %d entries",pcVar1->name,iVar4);
      iVar3 = pcVar1->cacheCount;
    }
    pcVar1->cacheCount = iVar3 + 1;
    Q_strncpy(s2->name,*s1,0x3f);
    s2->name[0x3f] = '\0';
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_DecalIndexFromName  @ 00046110
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
    if (((*s2)[0] != '\0') && (iVar1 = Q_strcmp(local_20,*s2), iVar1 == 0)) goto LAB_0004617b;
    iVar2 = iVar2 + 1;
    s2 = s2 + 1;
  } while (iVar2 != 0x200);
  iVar2 = 0;
LAB_0004617b:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}


// Draw_DecalName  @ 00045fe0
char * Draw_DecalName(int number)

{
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    return decal_wad->lumps[number].name;
  }
  return (char *)0x0;
}


// Draw_DecalSetName  @ 00045de0
void Draw_DecalSetName(int decal,char *name)

{
  if (decal < 0x200) {
    Q_strncpy(decal_names[decal],name,0xf);
    decal_names[decal][0xf] = '\0';
  }
  return;
}


// Draw_DecalShutdown  @ 00045db0
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


// Draw_DecalSize  @ 00045fb0
int Draw_DecalSize(int number)

{
  if ((decal_wad != (cachewad_t *)0x0) && (number < decal_wad->lumpCount)) {
    return decal_wad->lumps[number].size;
  }
  return 0;
}


// Draw_DecalTexture  @ 00047350
texture_t * Draw_DecalTexture(int index)

{
  customization_s *pcVar1;
  cachewad_t *pcVar2;
  void *raw;
  texture_t *ptVar3;
  char *pcVar4;
  int iVar5;
  qboolean qVar6;
  cachepic_t *pcVar7;
  uint uVar8;
  int iVar9;
  lumpinfo_s *pLump;
  int in_GS_OFFSET;
  char local_40 [16];
  char local_30 [16];
  int local_20;
  
                    /* Unresolved local var: int playernum@[???]
                       Unresolved local var: customization_t * pCust@[???] */
  pcVar2 = decal_wad;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (index < 0) {
    uVar8 = ~index;
    pcVar1 = cl.players[uVar8].customdata.pNext;
    if ((((pcVar1 == (customization_s *)0x0) || (pcVar1->bInUse == false)) ||
        (pcVar2 = pcVar1->pInfo, pcVar2 == (cachewad_t *)0x0)) ||
       (raw = pcVar1->pBuffer, raw == (void *)0x0)) {
      Sys_Error("Failed to load custom decal for player #%i:%s using default decal 0.\n",uVar8,
                uVar8 * 0x250 + 0x2e5224);
      ptVar3 = (texture_t *)0x0;
    }
    else {
                    /* Unresolved local var: texture_t * retval@[???] */
      iVar9 = pcVar1->nUserData1;
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
      iVar5 = (pcVar1->resource).nDownloadSize;
      if (pcVar2->cacheCount <= iVar9) {
        Sys_Error("Cache wad indexed before load %s: %d",pcVar2->name,iVar9);
      }
      pcVar7 = pcVar2->cache + iVar9;
      ptVar3 = Cache_Check(&pcVar7->cache);
      if (ptVar3 == (texture_t *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???] */
        pcVar4 = COM_FileBase_s(pcVar7->name,local_40,0x10);
        if (pcVar4 == (char *)0x0) {
          Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pcVar7);
        }
        else {
          W_CleanupName(local_40,local_30);
          qVar6 = Draw_CacheLoadFromCustom(local_30,pcVar2,raw,iVar5,pcVar7);
          if (qVar6 != false) {
            ptVar3 = (pcVar7->cache).data;
            if (ptVar3 != (texture_t *)0x0) goto LAB_000473a9;
            Sys_Error("Draw_CacheGet: failed to load %s",pcVar7);
          }
        }
        ptVar3 = Draw_CacheGet(decal_wad,0);
      }
    }
  }
  else {
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
    if (decal_wad->cacheCount <= index) {
      Sys_Error("Cache wad indexed before load %s: %d",decal_wad->name,index);
    }
    pcVar7 = pcVar2->cache + index;
    ptVar3 = Cache_Check(&pcVar7->cache);
    if (ptVar3 == (texture_t *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???]
                       Unresolved local var: lumpinfo_t * pLump@[???] */
      pcVar4 = COM_FileBase_s(pcVar7->name,local_40,0x10);
      if (pcVar4 == (char *)0x0) {
        Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pcVar7);
        ptVar3 = (texture_t *)0x0;
      }
      else {
        W_CleanupName(local_40,local_30);
        pLump = pcVar2->lumps;
        if (0 < pcVar2->lumpCount) {
          iVar9 = 0;
          do {
            iVar5 = Q_strcmp(local_30,pLump->name);
            if (iVar5 == 0) {
              if (iVar9 < pcVar2->lumpCount) {
                qVar6 = Draw_CacheReload(pcVar2,iVar9,pLump,pcVar7,local_30,pcVar7->name);
                if (qVar6 != false) {
                  ptVar3 = (pcVar7->cache).data;
                  if (ptVar3 != (texture_t *)0x0) goto LAB_000473a9;
                  Sys_Error("Draw_CacheGet: failed to load %s",pcVar7);
                }
              }
              break;
            }
            iVar9 = iVar9 + 1;
            pLump = pLump + 1;
          } while (iVar9 < pcVar2->lumpCount);
        }
        ptVar3 = (texture_t *)0x0;
      }
    }
  }
LAB_000473a9:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return ptVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_FreeWad  @ 00045c60
void Draw_FreeWad(cachewad_t *pWad)

{
  void *pvVar1;
  cache_user_t *c;
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
      iVar3 = 0;
      if (0 < pWad->numpaths) {
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


// Draw_Init  @ 000b3120
void Draw_Init(void)

{
  return;
}


// Draw_MiptexTexture  @ 00045630
void Draw_MiptexTexture(cachewad_t *wad,byte *data)

{
  byte *pbVar1;
  int iVar2;
  ushort uVar3;
  qboolean qVar4;
  uint uVar5;
  int32 iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  int in_GS_OFFSET;
  int32 local_48 [10];
  int local_20;
  
                    /* Unresolved local var: texture_t * tex@[???]
                       Unresolved local var: miptex_t * mip@[???]
                       Unresolved local var: miptex_t tmp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int pix@[???]
                       Unresolved local var: int palette@[???]
                       Unresolved local var: byte * pal@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar11 = wad->cacheExtra;
  if (iVar11 != 0x18) {
    Sys_Error("Draw_MiptexTexture: Bad cached wad %s\n",wad->name);
    iVar11 = wad->cacheExtra;
  }
  uVar5 = 0;
  do {
    *(undefined4 *)((int)local_48 + uVar5) = *(undefined4 *)(data + uVar5 + iVar11);
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x28);
  iVar10 = 0;
  Q_memcpy(data,local_48,0x10);
  iVar6 = (*LittleLong)(local_48[4]);
  *(int32 *)(data + 0x10) = iVar6;
  iVar6 = (*LittleLong)(local_48[5]);
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
  *(int32 *)(data + 0x14) = iVar6;
  do {
    iVar6 = (*LittleLong)(local_48[iVar10 + 6]);
    *(int32 *)(data + iVar10 * 4 + 0x2c) = iVar6 + wad->cacheExtra;
    qVar4 = gfCustomBuild;
    iVar10 = iVar10 + 1;
  } while (iVar10 != 4);
  iVar10 = *(int *)(data + 0x14) * *(int *)(data + 0x10);
  iVar10 = iVar10 + (iVar10 >> 6) + (iVar10 >> 2) + (iVar10 >> 4);
  iVar2 = iVar10 + 2 + *(int *)(data + 0x2c);
  *(int *)(data + 0x3c) = iVar2;
  uVar3 = *(ushort *)(data + iVar10 + iVar11 + 0x28);
  pbVar1 = data + iVar2;
  if (qVar4 != false) {
    Q_strncpy((char *)data,szCustName,0xf);
    data[0xf] = '\0';
  }
  bVar9 = '}';
  if ((pbVar1[0x2fd] == 0) && (pbVar1[0x2fe] == 0)) {
    bVar9 = ((pbVar1[0x2ff] != 0xff) - 1U & 0xfe) + 0x7d;
  }
  *data = bVar9;
  if (uVar3 != 0) {
    pbVar7 = pbVar1;
    do {
      pbVar8 = pbVar7 + 3;
      *pbVar7 = texgammatable[*pbVar7];
      pbVar7[1] = texgammatable[pbVar7[1]];
      pbVar7[2] = texgammatable[pbVar7[2]];
      pbVar7 = pbVar8;
    } while (pbVar1 + (uint)uVar3 * 3 != pbVar8);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Draw_Shutdown  @ 00045d60
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


// Draw_ValidateCustomLogo  @ 00046e00
qboolean Draw_ValidateCustomLogo(cachewad_t *wad,byte *data,lumpinfo_t *lump)

{
  qboolean qVar1;
  uint uVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  int local_88 [4];
  int32 local_78;
  int32 local_74;
  int local_70 [4];
  uint local_60 [16];
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
  if (wad->cacheExtra == 0x18) {
    uVar2 = 0;
    do {
      *(undefined4 *)((int)local_88 + uVar2) = *(undefined4 *)(data + uVar2 + 0x18);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x28);
    uVar2 = 0;
    do {
      *(undefined4 *)((int)local_60 + uVar2) = *(undefined4 *)(data + uVar2);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x40);
    iVar4 = 0;
    Q_memcpy(local_60,local_88,0x10);
    local_60[4] = (*LittleLong)(local_78);
    local_60[5] = (*LittleLong)(local_74);
    local_60[8] = 0;
    local_60[7] = 0;
    local_60[6] = 0;
    local_60[10] = 0;
    local_60[9] = 0;
    do {
      iVar3 = (*LittleLong)(local_88[iVar4 + 6]);
      iVar5 = wad->cacheExtra;
      local_60[iVar4 + 0xb] = iVar3 + iVar5;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 4);
    if (((local_60[4] == 0) || (0xff < local_60[5] - 1)) || (0x100 < local_60[4])) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad tex size %ux%u on %s\n",local_60[4],
                 local_60[5],wad->name);
      qVar1 = false;
      goto LAB_00046e69;
    }
    iVar4 = local_60[4] * local_60[5];
    uVar2 = iVar5 + lump->size;
    iVar5 = (iVar4 >> 2) + (iVar4 >> 4) + (iVar4 >> 6) + iVar4;
    if (uVar2 <= iVar5 + 0x28U) {
      Con_Printf("Draw_ValidateCustomLogo: Bad cached wad size %i/%i on %s\n",iVar5 + 0x28U,uVar2,
                 wad->name);
      iVar4 = local_60[4] * local_60[5];
    }
    uVar2 = (uint)*(ushort *)(data + iVar5 + 0x40);
    if (((local_70[1] == iVar4 + local_70[0]) && (local_70[2] == local_70[1] + (iVar4 >> 2))) &&
       ((iVar4 >> 4) + local_70[2] == local_70[3])) {
      if (0x100 < uVar2) {
        Con_Printf("Draw_ValidateCustomLogo: Bad cached wad palette size %i on %s\n",uVar2,wad->name
                  );
        qVar1 = false;
        goto LAB_00046e69;
      }
      iVar3 = (*LittleLong)(local_70[0]);
      qVar1 = true;
      if (iVar5 + iVar3 + uVar2 * 3 + 2 <= (uint)lump->disksize) goto LAB_00046e69;
    }
  }
  Con_Printf("Draw_ValidateCustomLogo: Bad cached wad %s\n",wad->name);
  qVar1 = false;
LAB_00046e69:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar1;
}


