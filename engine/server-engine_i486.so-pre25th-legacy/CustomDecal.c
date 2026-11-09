// CustomDecal_Init  @ 00069cb0
qboolean CustomDecal_Init(cachewad_s *wad,void *raw,int nFileSize,int playernum)

{
  qboolean qVar1;
  int nIndex;
  int iVar2;
  int in_stack_ffffffd4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bret@[???] */
  qVar1 = Draw_CustomCacheWadInit((int)wad,raw,(void *)nFileSize,in_stack_ffffffd4);
  if (qVar1 != false) {
    wad->pfnCacheBuild = Draw_MiptexTexture;
    wad->cacheExtra = 0x18;
    if (0 < wad->lumpCount) {
      nIndex = 0;
      do {
        iVar2 = nIndex + 1;
        Draw_CacheByIndex(wad,nIndex,playernum);
        nIndex = iVar2;
      } while (iVar2 < wad->lumpCount);
    }
  }
  return qVar1;
}


// CustomDecal_Validate  @ 0006a500
qboolean CustomDecal_Validate(void *raw,int nFileSize)

{
  cachewad_t *wad;
  qboolean qVar1;
  qboolean qVar2;
  void *pvVar3;
  int iVar4;
  cachepic_t *s1;
  int iVar5;
  int iVar6;
  int local_40;
  char local_3c [44];
  
                    /* Unresolved local var: qboolean bret@[???]
                       Unresolved local var: cachewad_t * fakewad@[???] */
  iVar5 = 0x2c;
  wad = Mem_ZeroMalloc(0x2c);
  qVar1 = false;
  if (wad != (cachewad_t *)0x0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bret@[???] */
    qVar2 = Draw_CustomCacheWadInit((int)wad,raw,(void *)nFileSize,iVar5);
    qVar1 = false;
    if (qVar2 != false) {
      wad->pfnCacheBuild = Draw_MiptexTexture;
      wad->cacheExtra = 0x18;
      if (0 < wad->lumpCount) {
        local_40 = 0;
        do {
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[32] szTestName@[???] */
          iVar4 = 0;
          iVar6 = local_40;
          snprintf(local_3c,0x20,"%03i%02i",0xfffffffe,local_40);
          iVar5 = wad->cacheCount;
          s1 = wad->cache;
          if (0 < iVar5) {
            do {
              iVar5 = Q_strcmp(s1->name,local_3c);
              if (iVar5 == 0) {
                iVar5 = wad->cacheCount;
                break;
              }
              iVar5 = wad->cacheCount;
              iVar4 = iVar4 + 1;
              s1 = s1 + 1;
            } while (iVar4 < iVar5);
          }
          if (iVar5 == iVar4) {
            if (iVar5 == wad->cacheMax) {
              Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar5);
              iVar5 = wad->cacheCount;
            }
            wad->cacheCount = iVar5 + 1;
            snprintf(s1->name,0x40,"%s",local_3c,iVar6);
          }
          local_40 = local_40 + 1;
        } while (local_40 < wad->lumpCount);
      }
      pvVar3 = Draw_CustomCacheGet(wad,raw,nFileSize,0);
      qVar1 = (qboolean)(pvVar3 != (void *)0x0);
    }
    Draw_FreeWad(wad);
    Mem_Free(wad);
  }
  return qVar1;
}


