// Decal_CountLumps  @ 00046280
int Decal_CountLumps(lumplist_t *plist)

{
  int iVar1;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
  iVar1 = 0;
  if (plist == (lumplist_t *)0x0) {
    return iVar1;
  }
  do {
    plist = plist->next;
    iVar1 = iVar1 + 1;
  } while (plist != (lumplist_s *)0x0);
  return iVar1;
}


// Decal_Init  @ 000467b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Decal_Init(void)

{
  uint uVar1;
  FileHandle_t file;
  cachewad_t *wad;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  decalname_t *dest;
  uint uVar5;
  int iVar6;
  bool bVar7;
  char local_3a [42];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t hfile@[???]
                       Unresolved local var: char[2][15] pszPathID@[???] */
  pcVar2 = local_3a;
  bVar7 = ((uint)pcVar2 & 2) != 0;
  if (bVar7) {
    pcVar4 = local_3a + 2;
    pcVar3 = "FAULTGAME";
    uVar5 = 0x1c;
    local_3a[0] = 'D';
    local_3a[1] = 'E';
  }
  else {
    pcVar3 = "DEFAULTGAME";
    uVar5 = 0x1e;
    pcVar4 = pcVar2;
  }
  uVar1 = 0;
  do {
    *(undefined4 *)(pcVar4 + uVar1) = *(undefined4 *)(pcVar3 + uVar1);
    uVar1 = uVar1 + 4;
  } while (uVar1 < (uVar5 & 0xfffffffc));
  if (!bVar7) {
    *(undefined2 *)(pcVar4 + uVar1) = *(undefined2 *)(pcVar3 + uVar1);
  }
  Draw_FreeWad(decal_wad);
  if (decal_wad != (cachewad_t *)0x0) {
    Mem_Free(decal_wad);
  }
  iVar6 = 1;
  decal_wad = (cachewad_t *)0x0;
  do {
    file = FS_OpenPathID("decals.wad","rb",pcVar2);
    if (file == (FileHandle_t)0x0) {
      if (iVar6 != 1) goto LAB_000468ab;
      Sys_Error("Couldn\'t find \'%s\' in \"%s\" search path\n","decals.wad",pcVar2);
    }
    else {
                    /* Unresolved local var: int filesize@[???]
                       Unresolved local var: cachewad_t * decal_wad_temp@[???] */
      uVar5 = FS_Size(file);
      wad = Mem_Malloc(0x2c);
      Q_memset(wad,0,0x2c);
      Draw_CacheWadInitFromFile(file,uVar5,"decals.wad",0x200,wad);
      Decal_MergeInDecals(wad,pcVar2);
      FS_Close(file);
LAB_000468ab:
      if (iVar6 == 2) {
        if (decal_wad != (cachewad_t *)0x0) {
          sv_decalnamecount = decal_wad->lumpCount;
          if (0x200 < sv_decalnamecount) {
            Sys_Error("Too many decals: %d / %d\n",sv_decalnamecount,0x200);
          }
          if (0 < sv_decalnamecount) {
            iVar6 = 0;
            dest = sv_decalnames;
            do {
              Q_memset(dest,0,0x11);
              pcVar2 = (char *)0x0;
              if ((decal_wad != (cachewad_t *)0x0) && (iVar6 < decal_wad->lumpCount)) {
                pcVar2 = decal_wad->lumps[iVar6].name;
              }
              iVar6 = iVar6 + 1;
              Q_strncpy(dest->name,pcVar2,0xf);
              dest->name[0xf] = '\0';
              dest = dest + 1;
            } while (iVar6 < sv_decalnamecount);
          }
          return;
        }
        sv_decalnamecount = 0;
        return;
      }
    }
    pcVar2 = pcVar2 + 0xf;
    iVar6 = iVar6 + 1;
  } while( true );
}


// Decal_MergeInDecals  @ 000462c0
void Decal_MergeInDecals(cachewad_t *pwad,char *pathID)

{
  size_t size;
  cachewad_t *pcVar1;
  cachewad_t *pcVar2;
  int iVar3;
  char *pcVar4;
  cachepic_t *dest;
  char **ppcVar5;
  lumpinfo_s *plVar6;
  int *piVar7;
  void *pvVar8;
  int *piVar9;
  int iVar10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int lumpcount@[DW_OP_reg1(ECX)]
                       Unresolved local var: lumpinfo_t * lump@[???]
                       Unresolved local var: lumplist_t * lumplist@[???]
                       Unresolved local var: lumplist_t * plump@[???]
                       Unresolved local var: lumplist_t * pnext@[???]
                       Unresolved local var: cachewad_t * final@[???] */
  if (pwad == (cachewad_t *)0x0) {
    Sys_Error("Decal_MergeInDecals called with NULL wad\n");
    return;
  }
  if (decal_wad == (cachewad_t *)0x0) {
    pwad->numpaths = 1;
    decal_wad = pwad;
    ppcVar5 = Mem_Malloc(4);
    pwad->basedirs = ppcVar5;
    ppcVar5 = decal_wad->basedirs;
    pcVar4 = Mem_Strdup(pathID);
    *ppcVar5 = pcVar4;
    pcVar2 = decal_wad;
    piVar9 = Mem_Malloc(decal_wad->cacheMax << 2);
    pcVar1 = decal_wad;
    pcVar2->lumppathindices = piVar9;
    Q_memset(pcVar1->lumppathindices,0,pcVar1->cacheMax << 2);
    return;
  }
  pcVar2 = Mem_Malloc(0x2c);
  piVar9 = (int *)0x0;
  Q_memset(pcVar2,0,0x2c);
  if (decal_wad->lumpCount < 1) {
    if (0 < pwad->lumpCount) goto LAB_000463c6;
  }
  else {
    iVar10 = 0;
    do {
      plVar6 = decal_wad->lumps + iVar10;
                    /* Unresolved local var: lumplist_t * p@[???] */
      for (piVar7 = piVar9; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[2]) {
        iVar3 = Q_stricmp(plVar6->name,(char *)(*piVar7 + 0x10));
        if (iVar3 == 0) {
          Mem_Free((void *)*piVar7);
          pvVar8 = Mem_Malloc(0x20);
          *piVar7 = (int)pvVar8;
          Q_memcpy(pvVar8,plVar6,0x20);
          piVar7[1] = 0;
          goto LAB_000463a8;
        }
      }
                    /* Unresolved local var: lumplist_t * p@[???] */
      piVar7 = Mem_Malloc(0xc);
      Q_memset(piVar7,0,0xc);
      pvVar8 = Mem_Malloc(0x20);
      *piVar7 = (int)pvVar8;
      Q_memcpy(pvVar8,plVar6,0x20);
      piVar7[2] = (int)piVar9;
      piVar7[1] = 0;
      piVar9 = piVar7;
LAB_000463a8:
      iVar10 = iVar10 + 1;
    } while (iVar10 < decal_wad->lumpCount);
    if (0 < pwad->lumpCount) {
LAB_000463c6:
      iVar10 = 0;
      do {
        plVar6 = pwad->lumps + iVar10;
                    /* Unresolved local var: lumplist_t * p@[???] */
        for (piVar7 = piVar9; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[2]) {
          iVar3 = Q_stricmp(plVar6->name,(char *)(*piVar7 + 0x10));
          if (iVar3 == 0) {
            Mem_Free((void *)*piVar7);
            pvVar8 = Mem_Malloc(0x20);
            *piVar7 = (int)pvVar8;
            Q_memcpy(pvVar8,plVar6,0x20);
            piVar7[1] = 1;
            goto LAB_00046448;
          }
        }
                    /* Unresolved local var: lumplist_t * p@[???] */
        piVar7 = Mem_Malloc(0xc);
        Q_memset(piVar7,0,0xc);
        pvVar8 = Mem_Malloc(0x20);
        *piVar7 = (int)pvVar8;
        Q_memcpy(pvVar8,plVar6,0x20);
        piVar7[2] = (int)piVar9;
        piVar7[1] = 1;
        piVar9 = piVar7;
LAB_00046448:
        iVar10 = iVar10 + 1;
      } while (iVar10 < pwad->lumpCount);
    }
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
    if (piVar9 != (int *)0x0) {
      iVar10 = 0;
      piVar7 = piVar9;
      do {
        piVar7 = (int *)piVar7[2];
        iVar10 = iVar10 + 1;
      } while (piVar7 != (int *)0x0);
      goto LAB_00046478;
    }
  }
  iVar10 = 0;
LAB_00046478:
  pcVar1 = decal_wad;
  pcVar2->lumpCount = iVar10;
  pcVar2->cacheCount = 0;
  pcVar2->cacheMax = pcVar1->cacheMax;
  pcVar4 = Mem_Strdup(pcVar1->name);
  pcVar2->name = pcVar4;
                    /* Unresolved local var: int len@[???] */
  size = pcVar2->cacheMax * 0x44;
  dest = Mem_Malloc(size);
  pcVar2->cache = dest;
  Q_memset(dest,0,size);
  pcVar1 = decal_wad;
  pcVar2->pfnCacheBuild = decal_wad->pfnCacheBuild;
  pcVar2->cacheExtra = pcVar1->cacheExtra;
  piVar7 = Mem_Malloc(pcVar2->cacheMax << 2);
  pcVar2->lumppathindices = piVar7;
  Q_memset(piVar7,0,pcVar2->cacheMax * 4);
  pcVar2->numpaths = 2;
  ppcVar5 = Mem_Malloc(8);
  pcVar2->basedirs = ppcVar5;
  pcVar4 = Mem_Strdup(*decal_wad->basedirs);
  *ppcVar5 = pcVar4;
  ppcVar5 = pcVar2->basedirs;
  pcVar4 = Mem_Strdup(pathID);
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
  ppcVar5[1] = pcVar4;
  if (piVar9 == (int *)0x0) {
    plVar6 = Mem_Malloc(0);
    pcVar2->lumps = plVar6;
  }
  else {
    iVar10 = 0;
    piVar7 = piVar9;
    do {
      piVar7 = (int *)piVar7[2];
      iVar10 = iVar10 + 1;
    } while (piVar7 != (int *)0x0);
    plVar6 = Mem_Malloc(iVar10 * 0x20);
    pcVar2->lumps = plVar6;
    iVar10 = 0;
    do {
      piVar7 = (int *)piVar9[2];
      Q_memcpy(plVar6,(void *)*piVar9,0x20);
      Mem_Free((void *)*piVar9);
      *piVar9 = 0;
      plVar6 = plVar6 + 1;
      *(uint *)((int)pcVar2->lumppathindices + iVar10) = (uint)(piVar9[1] != 0);
      iVar10 = iVar10 + 4;
      Mem_Free(piVar9);
      piVar9 = piVar7;
    } while (piVar7 != (int *)0x0);
  }
  Draw_FreeWad(decal_wad);
  if (decal_wad != (cachewad_t *)0x0) {
    Mem_Free(decal_wad);
  }
  decal_wad = pcVar2;
  Draw_FreeWad(pwad);
  Mem_Free(pwad);
  return;
}


// Decal_ReplaceOrAppendLump  @ 000461a0
void Decal_ReplaceOrAppendLump(lumplist_t **ppList,lumpinfo_t *lump,qboolean bsecondlump)

{
  int iVar1;
  lumplist_t *plVar2;
  lumpinfo_t *plVar3;
  
                    /* Unresolved local var: lumplist_t * p@[???] */
  plVar2 = *ppList;
  while( true ) {
    if (plVar2 == (lumplist_t *)0x0) {
                    /* Unresolved local var: lumplist_t * p@[???] */
      plVar2 = Mem_Malloc(0xc);
      Q_memset(plVar2,0,0xc);
      plVar3 = Mem_Malloc(0x20);
      plVar2->lump = plVar3;
      Q_memcpy(plVar3,lump,0x20);
      plVar2->breplaced = bsecondlump;
      plVar2->next = *ppList;
      *ppList = plVar2;
      return;
    }
    iVar1 = Q_stricmp(lump->name,plVar2->lump->name);
    if (iVar1 == 0) break;
    plVar2 = plVar2->next;
  }
  Mem_Free(plVar2->lump);
  plVar3 = Mem_Malloc(0x20);
  plVar2->lump = plVar3;
  Q_memcpy(plVar3,lump,0x20);
  plVar2->breplaced = bsecondlump;
  return;
}


// Decal_SizeLumps  @ 000462a0
int Decal_SizeLumps(lumplist_t *plist)

{
  int iVar1;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
  iVar1 = 0;
  if (plist == (lumplist_t *)0x0) {
    return iVar1;
  }
  do {
    plist = plist->next;
    iVar1 = iVar1 + 1;
  } while (plist != (lumplist_s *)0x0);
  return iVar1 * 0x20;
}


