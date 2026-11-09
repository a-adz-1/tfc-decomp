// Decal_CountLumps  @ 001132b0
int Decal_CountLumps(lumplist_t *plist)

{
  int iVar1;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
  iVar1 = 0;
  for (; plist != (lumplist_t *)0x0; plist = plist->next) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// Decal_Init  @ 001137c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Decal_Init(void)

{
  decalname_t *dest;
  char *pcVar1;
  FileHandle_t pvVar2;
  cachewad_t *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  bool bVar8;
  char local_3a [42];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t hfile@[???]
                       Unresolved local var: char[2][15] pszPathID@[???] */
  uVar4 = 0x1e;
  bVar8 = ((uint)local_3a & 2) != 0;
  pcVar1 = local_3a;
  if (bVar8) {
    pcVar1 = local_3a + 2;
    uVar4 = 0x1c;
  }
  uVar5 = 0;
  do {
    pcVar6 = pcVar1 + uVar5 + 4;
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar1 + uVar5;
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar1 + uVar5 + 8;
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar1 + uVar5 + 0xc;
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    uVar5 = uVar5 + 0x10;
  } while (uVar5 < (uVar4 & 0xfffffff0));
  pcVar1 = pcVar1 + uVar5;
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  pcVar1[4] = '\0';
  pcVar1[5] = '\0';
  pcVar1[6] = '\0';
  pcVar1[7] = '\0';
  pcVar1[8] = '\0';
  pcVar1[9] = '\0';
  pcVar1[10] = '\0';
  pcVar1[0xb] = '\0';
  if (!bVar8) {
    pcVar1[0xc] = '\0';
    pcVar1[0xd] = '\0';
  }
  builtin_strncpy(local_3a,"DEFAULTGAME",0xc);
  local_3a[0xf] = 'G';
  local_3a[0x10] = 'A';
  local_3a[0x11] = 'M';
  local_3a[0x12] = 'E';
  local_3a[0x13] = '\0';
  local_3a[0x14] = '\0';
  local_3a[0x15] = '\0';
  local_3a[0x16] = '\0';
  local_3a[0x17] = '\0';
  local_3a[0x18] = '\0';
  local_3a[0x19] = '\0';
  local_3a[0x1a] = '\0';
  local_3a[0xc] = '\0';
  local_3a[0xd] = '\0';
  local_3a[0xe] = 0;
  local_3a[0x1b] = '\0';
  local_3a[0x1c] = '\0';
  local_3a[0x1d] = 0;
  Draw_FreeWad(decal_wad);
  if (decal_wad != (cachewad_t *)0x0) {
    Mem_Free(decal_wad);
  }
  decal_wad = (cachewad_t *)0x0;
  pvVar2 = FS_OpenPathID("decals.wad","rb",local_3a);
  if (pvVar2 == (FileHandle_t)0x0) {
    Sys_Error("Couldn\'t find \'%s\' in \"%s\" search path\n","decals.wad",local_3a);
  }
  else {
                    /* Unresolved local var: int filesize@[???]
                       Unresolved local var: cachewad_t * decal_wad_temp@[???] */
    uVar4 = FS_Size(pvVar2);
    pcVar3 = Mem_Malloc(0x30);
    Q_memset(pcVar3,0,0x30);
    Draw_CacheWadInitFromFile(pvVar2,uVar4,"decals.wad",0x200,pcVar3);
    pcVar3->pfnCacheBuild = Draw_MiptexTexture;
    pcVar3->cacheExtra = 0x20;
    Decal_MergeInDecals(pcVar3,local_3a);
    FS_Close(pvVar2);
  }
  pvVar2 = FS_OpenPathID("decals.wad","rb",local_3a + 0xf);
  if (pvVar2 != (FileHandle_t)0x0) {
    uVar4 = FS_Size(pvVar2);
    pcVar3 = Mem_Malloc(0x30);
    Q_memset(pcVar3,0,0x30);
    Draw_CacheWadInitFromFile(pvVar2,uVar4,"decals.wad",0x200,pcVar3);
    pcVar3->pfnCacheBuild = Draw_MiptexTexture;
    pcVar3->cacheExtra = 0x20;
    Decal_MergeInDecals(pcVar3,local_3a + 0xf);
    FS_Close(pvVar2);
  }
  if (decal_wad == (cachewad_t *)0x0) {
    sv_decalnamecount = 0;
    return;
  }
  sv_decalnamecount = decal_wad->lumpCount;
  if (0x200 < sv_decalnamecount) {
    Sys_Error("Too many decals: %d / %d\n",sv_decalnamecount,0x200);
  }
  if (0 < sv_decalnamecount) {
    pcVar1 = sv_decalnames[0].name + 0xf;
    iVar7 = 0;
    do {
      Q_memset(sv_decalnames + iVar7,0,0x11);
      pcVar6 = (char *)0x0;
      if ((decal_wad != (cachewad_t *)0x0) && (iVar7 < decal_wad->lumpCount)) {
        pcVar6 = decal_wad->lumps[iVar7].name;
      }
      dest = sv_decalnames + iVar7;
      iVar7 = iVar7 + 1;
      Q_strncpy(dest->name,pcVar6,0xf);
      *pcVar1 = '\0';
      pcVar1 = pcVar1 + 0x11;
    } while (iVar7 < sv_decalnamecount);
  }
  return;
}


// Decal_MergeInDecals  @ 001132f0
void Decal_MergeInDecals(cachewad_t *pwad,char *pathID)

{
  size_t size;
  cachewad_t *pcVar1;
  cachewad_t *pcVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  cacheentry_t *dest;
  char **ppcVar7;
  lumpinfo_s *plVar8;
  int *piVar9;
  int *piVar10;
  int *local_2c;
  
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
    ppcVar7 = Mem_Malloc(4);
    pwad->basedirs = ppcVar7;
    ppcVar7 = decal_wad->basedirs;
    pcVar6 = Mem_Strdup(pathID);
    *ppcVar7 = pcVar6;
    pcVar2 = decal_wad;
    piVar10 = Mem_Malloc(decal_wad->cacheMax << 2);
    pcVar2->lumppathindices = piVar10;
    Q_memset(decal_wad->lumppathindices,0,decal_wad->cacheMax << 2);
    return;
  }
  pcVar2 = Mem_Malloc(0x30);
  piVar10 = (int *)0x0;
  Q_memset(pcVar2,0,0x30);
  local_2c = piVar10;
  if (0 < decal_wad->lumpCount) {
    local_2c = (int *)0x0;
    do {
                    /* Unresolved local var: lumplist_t * p@[???] */
      plVar8 = decal_wad->lumps + (int)piVar10;
      if (local_2c != (int *)0x0) {
        piVar9 = local_2c;
        do {
          iVar3 = Q_stricmp(plVar8->name,(char *)(*piVar9 + 0x10));
          if (iVar3 == 0) {
            Mem_Free((void *)*piVar9);
            pvVar4 = Mem_Malloc(0x20);
            *piVar9 = (int)pvVar4;
            Q_memcpy(pvVar4,plVar8,0x20);
            piVar9[1] = 0;
            goto LAB_001133d4;
          }
          piVar9 = (int *)piVar9[2];
        } while (piVar9 != (int *)0x0);
      }
                    /* Unresolved local var: lumplist_t * p@[???] */
      piVar9 = Mem_Malloc(0xc);
      Q_memset(piVar9,0,0xc);
      pvVar4 = Mem_Malloc(0x20);
      *piVar9 = (int)pvVar4;
      Q_memcpy(pvVar4,plVar8,0x20);
      piVar9[1] = 0;
      piVar9[2] = (int)local_2c;
      local_2c = piVar9;
LAB_001133d4:
      piVar10 = (int *)((int)piVar10 + 1);
    } while ((int)piVar10 < decal_wad->lumpCount);
  }
  if (0 < pwad->lumpCount) {
    iVar3 = 0;
    do {
                    /* Unresolved local var: lumplist_t * p@[???] */
      plVar8 = pwad->lumps + iVar3;
      if (local_2c != (int *)0x0) {
        piVar10 = local_2c;
        do {
          iVar5 = Q_stricmp(plVar8->name,(char *)(*piVar10 + 0x10));
          if (iVar5 == 0) {
            Mem_Free((void *)*piVar10);
            pvVar4 = Mem_Malloc(0x20);
            *piVar10 = (int)pvVar4;
            Q_memcpy(pvVar4,plVar8,0x20);
            piVar10[1] = 1;
            goto LAB_00113474;
          }
          piVar10 = (int *)piVar10[2];
        } while (piVar10 != (int *)0x0);
      }
                    /* Unresolved local var: lumplist_t * p@[???] */
      piVar10 = Mem_Malloc(0xc);
      Q_memset(piVar10,0,0xc);
      pvVar4 = Mem_Malloc(0x20);
      *piVar10 = (int)pvVar4;
      Q_memcpy(pvVar4,plVar8,0x20);
      piVar10[1] = 1;
      piVar10[2] = (int)local_2c;
      local_2c = piVar10;
LAB_00113474:
      iVar3 = iVar3 + 1;
    } while (iVar3 < pwad->lumpCount);
  }
  pcVar1 = decal_wad;
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
  iVar3 = 0;
  for (piVar10 = local_2c; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[2]) {
    iVar3 = iVar3 + 1;
  }
  pcVar2->lumpCount = iVar3;
  pcVar2->cacheCount = 0;
  pcVar2->cacheMax = pcVar1->cacheMax;
  pcVar6 = Mem_Strdup(pcVar1->name);
  pcVar2->name = pcVar6;
                    /* Unresolved local var: int len@[???] */
  size = pcVar2->cacheMax * 0x44;
  dest = Mem_Malloc(size);
  pcVar2->cache = dest;
  Q_memset(dest,0,size);
  pcVar2->tempWad = 0;
  pcVar1 = decal_wad;
  pcVar2->pfnCacheBuild = decal_wad->pfnCacheBuild;
  pcVar2->cacheExtra = pcVar1->cacheExtra;
  piVar10 = Mem_Malloc(pcVar2->cacheMax << 2);
  pcVar2->lumppathindices = piVar10;
  Q_memset(piVar10,0,pcVar2->cacheMax << 2);
  pcVar2->numpaths = 2;
  ppcVar7 = Mem_Malloc(8);
  pcVar2->basedirs = ppcVar7;
  pcVar6 = Mem_Strdup(*decal_wad->basedirs);
  *ppcVar7 = pcVar6;
  ppcVar7 = pcVar2->basedirs;
  pcVar6 = Mem_Strdup(pathID);
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
  ppcVar7[1] = pcVar6;
  if (local_2c == (int *)0x0) {
    plVar8 = Mem_Malloc(0);
    pcVar2->lumps = plVar8;
  }
  else {
    iVar3 = 0;
    piVar10 = local_2c;
    do {
      piVar10 = (int *)piVar10[2];
      iVar3 = iVar3 + 1;
    } while (piVar10 != (int *)0x0);
    iVar5 = 0;
    plVar8 = Mem_Malloc(iVar3 * 0x20);
    pcVar2->lumps = plVar8;
    do {
      piVar10 = (int *)local_2c[2];
      Q_memcpy(plVar8,(void *)*local_2c,0x20);
      Mem_Free((void *)*local_2c);
      *local_2c = 0;
      plVar8 = plVar8 + 1;
      *(uint *)((int)pcVar2->lumppathindices + iVar5) = (uint)(local_2c[1] != 0);
      iVar5 = iVar5 + 4;
      Mem_Free(local_2c);
      local_2c = piVar10;
    } while (piVar10 != (int *)0x0);
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


// Decal_ReplaceOrAppendLump  @ 001131d0
void Decal_ReplaceOrAppendLump(lumplist_t **ppList,lumpinfo_t *lump,qboolean bsecondlump)

{
  int iVar1;
  lumpinfo_t *plVar2;
  lumplist_t *plVar3;
  
                    /* Unresolved local var: lumplist_t * p@[???] */
  plVar3 = *ppList;
  if (plVar3 != (lumplist_t *)0x0) {
    do {
      iVar1 = Q_stricmp(lump->name,plVar3->lump->name);
      if (iVar1 == 0) {
        Mem_Free(plVar3->lump);
        plVar2 = Mem_Malloc(0x20);
        plVar3->lump = plVar2;
        Q_memcpy(plVar2,lump,0x20);
        plVar3->breplaced = bsecondlump;
        return;
      }
      plVar3 = plVar3->next;
    } while (plVar3 != (lumplist_s *)0x0);
  }
                    /* Unresolved local var: lumplist_t * p@[???] */
  plVar3 = Mem_Malloc(0xc);
  Q_memset(plVar3,0,0xc);
  plVar2 = Mem_Malloc(0x20);
  plVar3->lump = plVar2;
  Q_memcpy(plVar2,lump,0x20);
  plVar3->breplaced = bsecondlump;
  plVar3->next = *ppList;
  *ppList = plVar3;
  return;
}


// Decal_SizeLumps  @ 001132d0
int Decal_SizeLumps(lumplist_t *plist)

{
  int iVar1;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: lumplist_t * p@[???] */
  iVar1 = 0;
  if (plist != (lumplist_t *)0x0) {
    do {
      plist = plist->next;
      iVar1 = iVar1 + 1;
    } while (plist != (lumplist_s *)0x0);
    iVar1 = iVar1 * 0x20;
  }
  return iVar1;
}


