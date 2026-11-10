// Draw_AllocateCacheSpace  @ 0004ee3c
void Draw_AllocateCacheSpace(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = Mem_Malloc(param_2 * 0x44);
  *(undefined4 *)(param_1 + 4) = uVar1;
  Q_memset(uVar1,0,param_2 * 0x44);
  return;
}


// Draw_CacheByIndex  @ 0004f41c
int Draw_CacheByIndex(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char *__s;
  char local_24 [32];
  
  sprintf(local_24,"%03i%02i",param_3,param_2);
  iVar2 = 0;
  __s = (char *)param_1[1];
  if (0 < (int)param_1[2]) {
    do {
      iVar1 = Q_strcmp(__s,local_24);
      if (iVar1 == 0) break;
      __s = __s + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[2]);
  }
  iVar1 = param_1[2];
  if (iVar2 == iVar1) {
    if (iVar2 == param_1[3]) {
      Sys_Error("Cache wad (%s) out of %d entries",*param_1,iVar2);
      iVar1 = param_1[2];
    }
    param_1[2] = iVar1 + 1;
    sprintf(__s,"%s",local_24);
  }
  return iVar2;
}


// Draw_CacheFindIndex  @ 0004ff90
int Draw_CacheFindIndex(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 4);
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar1 = Q_strcmp(param_2,iVar3);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar3 = iVar3 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 8));
  }
  return -1;
}


// Draw_CacheGet  @ 0004fb48
int Draw_CacheGet(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_24 [16];
  undefined1 auStack_14 [16];
  
  if ((int)param_1[2] <= param_2) {
    Sys_Error("Cache wad indexed before load %s: %d",*param_1,param_2);
  }
  iVar1 = param_1[1] + param_2 * 0x44;
  iVar2 = Cache_Check(iVar1 + 0x40);
  if (iVar2 == 0) {
    COM_FileBase(iVar1,auStack_14);
    W_CleanupName(auStack_14,auStack_24);
    iVar2 = param_1[4];
    if (0 < (int)param_1[5]) {
      iVar4 = 0;
      do {
        iVar3 = Q_strcmp(auStack_24,iVar2 + 0x10);
        if (iVar3 == 0) break;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar4 < (int)param_1[5]);
      if ((iVar4 < (int)param_1[5]) &&
         (iVar2 = Draw_CacheReload(param_1,iVar4,iVar2,iVar1,auStack_24,iVar1), iVar2 != 0)) {
        if (*(int *)(iVar1 + 0x40) != 0) {
          return *(int *)(iVar1 + 0x40);
        }
        Sys_Error("Draw_CacheGet: failed to load %s",iVar1);
        return 0;
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}


// Draw_CacheIndex  @ 0004ff0c
int Draw_CacheIndex(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = param_1[1];
  if (0 < (int)param_1[2]) {
    do {
      iVar1 = Q_strcmp(param_2,iVar3);
      if (iVar1 == 0) break;
      iVar3 = iVar3 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[2]);
  }
  iVar1 = param_1[2];
  if (iVar2 == iVar1) {
    if (iVar2 == param_1[3]) {
      Sys_Error("Cache wad (%s) out of %d entries",*param_1,iVar2);
      iVar1 = param_1[2];
    }
    param_1[2] = iVar1 + 1;
    Q_strcpy(iVar3,param_2);
  }
  return iVar2;
}


// Draw_CacheLoadFromCustom  @ 0004fdf8
undefined4 Draw_CacheLoadFromCustom(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = Q_strlen(param_1);
  if (iVar1 < 5) {
    iVar1 = 0;
  }
  else {
    iVar1 = Q_atoi(param_1 + 3);
    if ((iVar1 < 0) || ((int)param_2[5] <= iVar1)) {
      return 0;
    }
  }
  piVar2 = (int *)(iVar1 * 0x20 + param_2[4]);
  iVar1 = Cache_Alloc(param_4 + 0x40,param_2[6] + piVar2[2] + 1,param_1);
  if (iVar1 == 0) {
    Sys_Error("Draw_CacheGet: not enough space for %s in %s",param_1,*param_2);
  }
  *(undefined1 *)(param_2[6] + piVar2[2] + iVar1) = 0;
  Q_memcpy(iVar1 + param_2[6],param_3 + *piVar2,piVar2[2]);
  gfCustomBuild = 1;
  sprintf(szCustName,"T%s",param_1);
  szCustName[6] = 0;
  if ((code *)param_2[7] != (code *)0x0) {
    (*(code *)param_2[7])(param_2,iVar1);
  }
  gfCustomBuild = 0;
  return 1;
}


// Draw_CacheReload  @ 0004fcfc
undefined4
Draw_CacheReload(undefined4 *param_1,int param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_1[8] == 2) {
    COM_OpenFileInDir(*(undefined4 *)(param_1[9] + *(int *)(param_1[10] + param_2 * 4) * 4),*param_1
                      ,&local_10);
  }
  else {
    COM_OpenFile(*param_1,&local_10);
  }
  if (local_8 == -1) {
    uVar1 = 0;
  }
  else {
    iVar2 = Cache_Alloc(param_4 + 0x40,param_1[6] + param_3[2] + 1,param_5);
    if (iVar2 == 0) {
      Sys_Error("Draw_CacheGet: not enough space for %s in %s",param_6,*param_1);
    }
    *(undefined1 *)(param_1[6] + param_3[2] + iVar2) = 0;
    COM_FileSeek(local_10,local_c,local_8,*param_3);
    Sys_FileRead(local_8,iVar2 + param_1[6],param_3[2]);
    COM_CloseFile(local_10,local_c,local_8);
    if ((code *)param_1[7] != (code *)0x0) {
      (*(code *)param_1[7])(param_1,iVar2);
    }
    uVar1 = 1;
  }
  return uVar1;
}


// Draw_CacheWadHandler  @ 0004f0bc
void Draw_CacheWadHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return;
}


// Draw_CacheWadInit  @ 0004ef70
void Draw_CacheWadInit(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  uVar1 = COM_OpenFile(param_1,&local_10);
  if (local_8 == -1) {
    Sys_Error("Draw_LoadWad: Couldn\'t open %s\n",param_1);
  }
  Draw_CacheWadInitFromFile(&local_10,uVar1,param_1,param_2,param_3);
  COM_CloseFile(local_10,local_c,local_8);
  return;
}


// Draw_CacheWadInitFromFile  @ 0004ee7c
void Draw_CacheWadInitFromFile
               (undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  Sys_FileRead(param_1[2],&local_10,0xc);
  if (local_10 != 0x33444157) {
    Sys_Error("Wad file %s doesn\'t have WAD3 id\n",param_3);
  }
  uVar1 = Mem_Malloc(param_2 - local_8);
  param_5[4] = uVar1;
  COM_FileSeek(*param_1,param_1[1],param_1[2],local_8);
  Sys_FileRead(param_1[2],param_5[4],param_2 - local_8);
  iVar2 = 0;
  iVar3 = param_5[4];
  if (0 < local_c) {
    do {
      W_CleanupName(iVar3 + 0x10,iVar3 + 0x10);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar2 < local_c);
  }
  param_5[5] = local_c;
  param_5[2] = 0;
  param_5[3] = param_4;
  uVar1 = Mem_Strdup(param_3);
  *param_5 = uVar1;
  Draw_AllocateCacheSpace(param_5,param_4,0);
  param_5[7] = 0;
  param_5[6] = 0;
  return;
}


// Draw_CustomCacheGet  @ 0004fc4c
int Draw_CustomCacheGet(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  if ((int)param_1[2] <= param_3) {
    Sys_Error("Cache wad indexed before load %s: %d",*param_1,param_3);
  }
  iVar1 = param_1[1] + param_3 * 0x44;
  iVar2 = Cache_Check(iVar1 + 0x40);
  if (iVar2 == 0) {
    COM_FileBase(iVar1,local_14);
    W_CleanupName(local_14,local_24);
    iVar2 = Draw_CacheLoadFromCustom(local_24,param_1,param_2,iVar1);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x40);
      if (iVar2 == 0) {
        Sys_Error("Draw_CacheGet: failed to load %s",iVar1);
      }
    }
  }
  return iVar2;
}


// Draw_CustomCacheWadInit  @ 0004efdc
void Draw_CustomCacheWadInit(undefined4 param_1,undefined4 *param_2,int *param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_3[1];
  iVar4 = param_3[2];
  if (*param_3 != 0x33444157) {
    Sys_Error("Custom file doesn\'t have WAD3 id\n");
  }
  uVar2 = Mem_Malloc(param_4 - iVar4);
  param_2[4] = uVar2;
  Q_memcpy(uVar2,iVar4 + (int)param_3,param_4 - iVar4);
  iVar4 = param_2[4];
  if (uVar1 != 0) {
    uVar3 = 0;
    do {
      W_CleanupName(iVar4 + 0x10,iVar4 + 0x10);
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x20;
    } while (uVar3 < uVar1);
  }
  param_2[5] = uVar1;
  param_2[2] = 0;
  param_2[3] = param_1;
  uVar2 = Mem_Strdup("pldecal.wad");
  *param_2 = uVar2;
  Draw_AllocateCacheSpace(param_2,param_1,0);
  param_2[7] = 0;
  param_2[6] = 0;
  return;
}


// Draw_DecalCount  @ 0004f2d0
undefined4 Draw_DecalCount(void)

{
  undefined4 uVar1;
  
  if (decal_wad == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(decal_wad + 0x14);
  }
  return uVar1;
}


// Draw_DecalIndex  @ 0004f22c
void Draw_DecalIndex(int param_1)

{
  int iVar1;
  int iVar2;
  char *__s;
  char local_24 [32];
  
  iVar2 = param_1 * 0x10;
  if ((&decal_names)[iVar2] == '\0') {
    Sys_Error("Used decal #%d without a name\n",param_1);
  }
  __s = &decal_names + iVar2;
  iVar1 = Host_IsServerActive();
  if ((iVar1 == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN((float)violence_hblood._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)violence_hblood._12_4_ == 0.0) << 0xe) >> 8)) == 0x40))
  {
    iVar1 = Q_strncmp(__s,"{blood",6);
    if (iVar1 == 0) {
      __s = local_24;
      sprintf(__s,"{yblood%s",iVar2 + 0xe6ae6);
    }
  }
  Draw_CacheIndex(decal_wad,__s);
  return;
}


// Draw_DecalIndexFromName  @ 0004f4c8
int Draw_DecalIndexFromName(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_14 [16];
  
  Q_strcpy(local_14,param_1);
  if (local_14[0] == '}') {
    local_14[0] = '{';
  }
  iVar3 = 0;
  iVar2 = 0;
  while( true ) {
    if (((&decal_names)[iVar2] != '\0') &&
       (iVar1 = Q_strcmp(local_14,&decal_names + iVar2), iVar1 == 0)) {
      return iVar3;
    }
    if (((&DAT_000e6af0)[iVar2] != '\0') &&
       (iVar1 = Q_strcmp(local_14,&DAT_000e6af0 + iVar2), iVar1 == 0)) {
      return iVar3 + 1;
    }
    if (((&DAT_000e6b00)[iVar2] != '\0') &&
       (iVar1 = Q_strcmp(local_14,&DAT_000e6b00 + iVar2), iVar1 == 0)) {
      return iVar3 + 2;
    }
    if (((&DAT_000e6b10)[iVar2] != '\0') &&
       (iVar1 = Q_strcmp(local_14,&DAT_000e6b10 + iVar2), iVar1 == 0)) break;
    iVar2 = iVar2 + 0x40;
    iVar3 = iVar3 + 4;
    if (0x1ff < iVar3) {
      return 0;
    }
  }
  return iVar3 + 3;
}


// Draw_DecalName  @ 0004f338
int Draw_DecalName(int param_1)

{
  int iVar1;
  
  if ((decal_wad == 0) || (*(int *)(decal_wad + 0x14) <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 * 0x20 + *(int *)(decal_wad + 0x10) + 0x10;
  }
  return iVar1;
}


// Draw_DecalSetName  @ 0004f1e0
void Draw_DecalSetName(int param_1,undefined4 param_2)

{
  if (param_1 < 0x200) {
    Q_strncpy(&decal_names + param_1 * 0x10,param_2,0xf);
    (&DAT_000e6aef)[param_1 * 0x10] = 0;
  }
  return;
}


// Draw_DecalShutdown  @ 0004edfc
void Draw_DecalShutdown(void)

{
  Draw_FreeWad(decal_wad);
  if (decal_wad != 0) {
    Mem_Free(decal_wad);
  }
  decal_wad = 0;
  return;
}


// Draw_DecalSize  @ 0004f2fc
undefined4 Draw_DecalSize(int param_1)

{
  undefined4 uVar1;
  
  if ((decal_wad == 0) || (*(int *)(decal_wad + 0x14) <= param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(decal_wad + 0x10) + 8 + param_1 * 0x20);
  }
  return uVar1;
}


// Draw_DecalTexture  @ 0004f374
undefined4 Draw_DecalTexture(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((int)param_1 < 0) {
    param_1 = ~param_1;
    piVar1 = *(int **)(cl + param_1 * 0x440 + 0x14c42c);
    if ((((piVar1 != (int *)0x0) && (*piVar1 != 0)) && (piVar1[0x26] != 0)) && (piVar1[0x27] != 0))
    {
      uVar2 = Draw_CustomCacheGet(piVar1[0x26],piVar1[0x27],piVar1[0x24]);
      return uVar2;
    }
    Sys_Error("Failed to load custom decal for player #%i:%s using default decal 0.\n",param_1,
              param_1 * 0x440 + 0x3732f0);
    uVar2 = 0;
  }
  else {
    uVar2 = Draw_CacheGet(decal_wad,param_1);
  }
  return uVar2;
}


// Draw_FreeWad  @ 0004f0d4
void Draw_FreeWad(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[4] != 0) {
      Mem_Free(param_1[4]);
    }
    param_1[4] = 0;
    Mem_Free(*param_1);
    if (param_1[8] != 0) {
      iVar2 = 0;
      if (0 < (int)param_1[8]) {
        do {
          Mem_Free(*(undefined4 *)(param_1[9] + iVar2 * 4));
          *(undefined4 *)(param_1[9] + iVar2 * 4) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)param_1[8]);
      }
      Mem_Free(param_1[9]);
      param_1[9] = 0;
    }
    if (param_1[10] != 0) {
      Mem_Free(param_1[10]);
      param_1[10] = 0;
    }
    local_8 = param_1[1];
    if (local_8 != 0) {
      iVar2 = 0;
      if (0 < (int)param_1[2]) {
        do {
          iVar1 = Cache_Check(local_8 + 0x40);
          if (iVar1 != 0) {
            Cache_Free(local_8 + 0x40);
          }
          iVar2 = iVar2 + 1;
          local_8 = local_8 + 0x44;
        } while (iVar2 < (int)param_1[2]);
      }
      Mem_Free(param_1[1]);
    }
  }
  return;
}


// Draw_Init  @ 00092030
void Draw_Init(void)

{
  return;
}


// Draw_Shutdown  @ 0004eda4
void Draw_Shutdown(void)

{
  if (m_bDrawInitialized != 0) {
    m_bDrawInitialized = 0;
    Draw_FreeWad(menu_wad);
    if (menu_wad != 0) {
      Mem_Free(menu_wad);
    }
    menu_wad = 0;
  }
  return;
}


