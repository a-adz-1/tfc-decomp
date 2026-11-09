// CustomDecal_Init  @ 000469d0
qboolean CustomDecal_Init(cachewad_s *wad,void *raw,int nFileSize,int playernum)

{
  qboolean qVar1;
  int iVar2;
  cachepic_t *s1;
  int iVar3;
  int in_GS_OFFSET;
  int local_54;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bret@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  qVar1 = Draw_CustomCacheWadInit(0x10,wad,raw,nFileSize);
  if (qVar1 != false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bret@[???] */
    wad->pfnCacheBuild = Draw_MiptexTexture;
    wad->cacheExtra = 0x18;
    if (0 < wad->lumpCount) {
      local_54 = 0;
      do {
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[32] szTestName@[???] */
        iVar3 = 0;
        __snprintf_chk(local_40,0x20,1,0x20,"%03i%02i",playernum,local_54);
        iVar2 = wad->cacheCount;
        s1 = wad->cache;
        if (0 < iVar2) {
          do {
            iVar2 = Q_strcmp(s1->name,local_40);
            if (iVar2 == 0) {
              iVar2 = wad->cacheCount;
              break;
            }
            iVar2 = wad->cacheCount;
            iVar3 = iVar3 + 1;
            s1 = s1 + 1;
          } while (iVar3 < iVar2);
        }
        if (iVar2 == iVar3) {
          if (iVar2 == wad->cacheMax) {
            Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar2);
            iVar2 = wad->cacheCount;
          }
          wad->cacheCount = iVar2 + 1;
          snprintf(s1->name,0x40,"%s",local_40);
        }
        local_54 = local_54 + 1;
      } while (local_54 < wad->lumpCount);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar1;
}


// CustomDecal_Validate  @ 00047640
qboolean CustomDecal_Validate(void *raw,int nFileSize)

{
  cachewad_t *wad;
  qboolean qVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  cachepic_t *pcVar5;
  qboolean qVar6;
  int iVar7;
  int in_GS_OFFSET;
  int local_64;
  char local_50 [16];
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: qboolean bret@[???]
                       Unresolved local var: cachewad_t * fakewad@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  wad = Mem_ZeroMalloc(0x2c);
  if (wad == (cachewad_t *)0x0) {
    qVar6 = false;
    goto LAB_00047787;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bret@[???] */
  qVar1 = Draw_CustomCacheWadInit(0x10,wad,raw,nFileSize);
  qVar6 = false;
  if (qVar1 != false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bret@[???] */
    wad->pfnCacheBuild = Draw_MiptexTexture;
    wad->cacheExtra = 0x18;
    if (0 < wad->lumpCount) {
      local_64 = 0;
      do {
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[32] szTestName@[???] */
        iVar7 = 0;
        __snprintf_chk(local_40,0x20,1,0x20,"%03i%02i",0xfffffffe,local_64);
        iVar2 = wad->cacheCount;
        pcVar5 = wad->cache;
        if (0 < iVar2) {
          do {
            iVar2 = Q_strcmp(pcVar5->name,local_40);
            if (iVar2 == 0) {
              iVar2 = wad->cacheCount;
              break;
            }
            iVar2 = wad->cacheCount;
            iVar7 = iVar7 + 1;
            pcVar5 = pcVar5 + 1;
          } while (iVar7 < iVar2);
        }
        if (iVar7 == iVar2) {
          if (wad->cacheMax == iVar7) {
            Sys_Error("Cache wad (%s) out of %d entries",wad->name,iVar2);
            iVar7 = wad->cacheCount;
          }
          wad->cacheCount = iVar7 + 1;
          snprintf(pcVar5->name,0x40,"%s",local_40);
        }
        local_64 = local_64 + 1;
      } while (local_64 < wad->lumpCount);
    }
                    /* Unresolved local var: cachepic_t * pic@[???]
                       Unresolved local var: void * dat@[???]
                       Unresolved local var: char * path@[???] */
    if (wad->cacheCount < 1) {
      Sys_Error("Cache wad indexed before load %s: %d",wad->name,0);
    }
    pcVar5 = wad->cache;
    qVar6 = true;
    pvVar3 = Cache_Check(&pcVar5->cache);
    if (pvVar3 == (void *)0x0) {
                    /* Unresolved local var: char[16] name@[???]
                       Unresolved local var: char[16] clean@[???] */
      pcVar4 = COM_FileBase_s(pcVar5->name,local_50,0x10);
      if (pcVar4 == (char *)0x0) {
        Sys_Error("Draw_CacheGet: Invalid path length: %s\n",pcVar5);
      }
      else {
        W_CleanupName(local_50,local_40);
        qVar1 = Draw_CacheLoadFromCustom(local_40,wad,raw,nFileSize,pcVar5);
        if (qVar1 != false) {
          if ((pcVar5->cache).data != (void *)0x0) goto LAB_00047775;
          Sys_Error("Draw_CacheGet: failed to load %s",pcVar5);
        }
      }
      qVar6 = false;
    }
  }
LAB_00047775:
  Draw_FreeWad(wad);
  Mem_Free(wad);
LAB_00047787:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar6;
}


