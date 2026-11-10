// Draw_AllocateCacheSpace  @ 08053d40
void Draw_AllocateCacheSpace(int param_1,int param_2)

{
  void *__s;
  
  __s = malloc(param_2 * 0x44);
  *(void **)(param_1 + 4) = __s;
  memset(__s,0,param_2 * 0x44);
  return;
}


// Draw_CacheByIndex  @ 08054270
int Draw_CacheByIndex(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char *__s1;
  char local_24 [32];
  
  sprintf(local_24,"%03i%02i",param_3,param_2);
  __s1 = (char *)param_1[1];
  iVar2 = 0;
  if (0 < (int)param_1[2]) {
    do {
      iVar1 = strcmp(__s1,local_24);
      if (iVar1 == 0) break;
      __s1 = __s1 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[2]);
  }
  if (iVar2 == param_1[2]) {
    if (iVar2 == param_1[3]) {
      Sys_Error("Cache wad (%s) out of %d entries",*param_1,iVar2);
    }
    param_1[2] = param_1[2] + 1;
    sprintf(__s1,"%s",local_24);
  }
  return iVar2;
}


// Draw_CacheFindIndex  @ 08054c70
int Draw_CacheFindIndex(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *__s2;
  
  __s2 = *(char **)(param_1 + 4);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar1 = strcmp(param_2,__s2);
      if (iVar1 == 0) {
        return iVar2;
      }
      __s2 = __s2 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 8));
  }
  return -1;
}


// Draw_CacheGet  @ 08054850
int Draw_CacheGet(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_24 [16];
  undefined1 local_14 [16];
  
  if ((int)param_1[2] <= param_2) {
    Sys_Error("Cache wad indexed before load %s: %d",*param_1,param_2);
  }
  iVar1 = param_1[1] + param_2 * 0x44;
  iVar2 = Cache_Check(iVar1 + 0x40);
  if (iVar2 == 0) {
    COM_FileBase(iVar1,local_14);
    W_CleanupName(local_14,local_24);
    iVar2 = param_1[4];
    iVar4 = 0;
    if (0 < (int)param_1[5]) {
      do {
        iVar3 = strcmp(local_24,(char *)(iVar2 + 0x10));
        if (iVar3 == 0) break;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar4 < (int)param_1[5]);
    }
    iVar2 = Draw_CacheReload(param_1,iVar4,iVar2,iVar1,local_24,iVar1);
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


// Draw_CacheIndex  @ 08054c00
int Draw_CacheIndex(undefined4 *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *__s2;
  
  __s2 = (char *)param_1[1];
  iVar2 = 0;
  if (0 < (int)param_1[2]) {
    do {
      iVar1 = strcmp(param_2,__s2);
      if (iVar1 == 0) break;
      __s2 = __s2 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[2]);
  }
  if (iVar2 == param_1[2]) {
    if (iVar2 == param_1[3]) {
      Sys_Error("Cache wad (%s) out of %d entries",*param_1,iVar2);
    }
    param_1[2] = param_1[2] + 1;
    strcpy(__s2,param_2);
  }
  return iVar2;
}


// Draw_CacheLoadFromCustom  @ 08054af0
undefined4 Draw_CacheLoadFromCustom(char *param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (~uVar2 - 1 < 5) {
    iVar3 = 0;
  }
  else {
    iVar3 = __strtol_internal(param_1 + 3,0,10,0);
    if ((iVar3 < 0) || ((int)param_2[5] <= iVar3)) {
      return 0;
    }
  }
  piVar5 = (int *)(iVar3 * 0x20 + param_2[4]);
  iVar3 = Cache_Alloc(param_4 + 0x40,param_2[6] + piVar5[2] + 1,param_1);
  if (iVar3 == 0) {
    Sys_Error("Draw_CacheGet: not enough space for %s in %s",param_1,*param_2);
  }
  *(undefined1 *)(param_2[6] + piVar5[2] + iVar3) = 0;
  memcpy((void *)(iVar3 + param_2[6]),(void *)(param_3 + *piVar5),piVar5[2]);
  gfCustomBuild = 1;
  sprintf(szCustName,"T%s",param_1);
  szCustName[6] = 0;
  if (param_2[7] != 0) {
    (*(code *)param_2[7])(param_2,iVar3);
  }
  gfCustomBuild = 0;
  return 1;
}


// Draw_CacheReload  @ 080549f0
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
    if (param_1[7] != 0) {
      (*(code *)param_1[7])(param_1,iVar2);
    }
    uVar1 = 1;
  }
  return uVar1;
}


// Draw_CacheWadHandler  @ 08053f70
void Draw_CacheWadHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return;
}


// Draw_CacheWadInit  @ 08053e50
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


// Draw_CacheWadInitFromFile  @ 08053d70
void Draw_CacheWadInitFromFile
               (undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  Sys_FileRead(param_1[2],&local_10,0xc);
  if (local_10 != 0x33444157) {
    Sys_Error("Wad file %s doesn\'t have WAD3 id\n",param_3);
  }
  pvVar1 = malloc(param_2 - local_8);
  param_5[4] = pvVar1;
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
  *param_5 = param_3;
  Draw_AllocateCacheSpace(param_5,param_4,0);
  param_5[7] = 0;
  param_5[6] = 0;
  return;
}


// Draw_CustomCacheGet  @ 08054940
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


// Draw_CustomCacheWadInit  @ 08053eb0
void Draw_CustomCacheWadInit(undefined4 param_1,undefined4 *param_2,int *param_3,int param_4)

{
  uint uVar1;
  void *__dest;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_3[1];
  iVar3 = param_3[2];
  if (*param_3 != 0x33444157) {
    Sys_Error("Custom file doesn\'t have WAD3 id\n");
  }
  __dest = malloc(param_4 - iVar3);
  param_2[4] = __dest;
  memcpy(__dest,(void *)(iVar3 + (int)param_3),param_4 - iVar3);
  uVar2 = 0;
  iVar3 = param_2[4];
  if (uVar1 != 0) {
    do {
      W_CleanupName(iVar3 + 0x10,iVar3 + 0x10);
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (uVar2 < uVar1);
  }
  param_2[5] = uVar1;
  param_2[2] = 0;
  param_2[3] = param_1;
  *param_2 = "pldecal.wad";
  Draw_AllocateCacheSpace(param_2,param_1,0);
  param_2[7] = 0;
  param_2[6] = 0;
  return;
}


// Draw_DecalCount  @ 08054150
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


// Draw_DecalIndex  @ 080540c0
void Draw_DecalIndex(int param_1)

{
  int iVar1;
  char *__s1;
  char local_24 [32];
  
  if ((&decal_names)[param_1 * 0x10] == '\0') {
    Sys_Error("Used decal #%d without a name\n",param_1);
  }
  __s1 = &decal_names + param_1 * 0x10;
  if ((sv == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN((float)violence_hblood._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)violence_hblood._12_4_ == 0.0) << 0xe) >> 8)) == 0x40))
  {
    iVar1 = strncmp(__s1,"{blood",6);
    if (iVar1 == 0) {
      __s1 = local_24;
      sprintf(__s1,"{yblood%s",param_1 * 0x10 + 0x80ca246);
    }
  }
  Draw_CacheIndex(decal_wad,__s1);
  return;
}


// Draw_DecalIndexFromName  @ 08054300
int Draw_DecalIndexFromName(char *param_1)

{
  int iVar1;
  int iVar2;
  char local_14 [16];
  
  strcpy(local_14,param_1);
  if (local_14[0] == '}') {
    local_14[0] = '{';
  }
  iVar2 = 0;
  while (((&decal_names)[iVar2 * 0x10] == '\0' ||
         (iVar1 = strcmp(local_14,&decal_names + iVar2 * 0x10), iVar1 != 0))) {
    iVar2 = iVar2 + 1;
    if (0x1ff < iVar2) {
      return 0;
    }
  }
  return iVar2;
}


// Draw_DecalName  @ 080541b0
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


// Draw_DecalSetName  @ 08054080
void Draw_DecalSetName(int param_1,char *param_2)

{
  if (param_1 < 0x200) {
    strncpy(&decal_names + param_1 * 0x10,param_2,0xf);
    (&DAT_080ca24f)[param_1 * 0x10] = 0;
  }
  return;
}


// Draw_DecalShutdown  @ 08053d20
void Draw_DecalShutdown(void)

{
  Draw_FreeWad(decal_wad);
  decal_wad = 0;
  return;
}


// Draw_DecalSize  @ 08054170
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


// Draw_DecalTexture  @ 080541f0
undefined4 Draw_DecalTexture(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((int)param_1 < 0) {
    param_1 = ~param_1;
    piVar1 = *(int **)(cl + param_1 * 0x3e0 + 0x22264);
    if ((((piVar1 == (int *)0x0) || (*piVar1 == 0)) || (piVar1[0x1e] == 0)) || (piVar1[0x1f] == 0))
    {
      Sys_Error("Failed to load custom decal for player #%i:%s using default decal 0.\n",param_1,
                param_1 * 0x3e0 + 0x81ad788);
      uVar2 = 0;
    }
    else {
      uVar2 = Draw_CustomCacheGet(piVar1[0x1e],piVar1[0x1f],piVar1[0x1c]);
    }
  }
  else {
    uVar2 = Draw_CacheGet(decal_wad,param_1);
  }
  return uVar2;
}


// Draw_FreeWad  @ 08053f90
void Draw_FreeWad(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      free(*(void **)(param_1 + 0x10));
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x20)) {
        do {
          free(*(void **)(*(int *)(param_1 + 0x24) + iVar2 * 4));
          *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2 * 4) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0x20));
      }
      free(*(void **)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      free(*(void **)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 != 0) {
      if (0 < *(int *)(param_1 + 8)) {
        iVar3 = 0;
        do {
          iVar1 = Cache_Check(iVar2 + 0x40);
          if (iVar1 != 0) {
            Cache_Free(iVar2 + 0x40);
          }
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + 0x44;
        } while (iVar3 < *(int *)(param_1 + 8));
      }
      free(*(void **)(param_1 + 4));
    }
  }
  return;
}


// Draw_Init  @ 0808d270
void Draw_Init(void)

{
  return;
}


// Draw_Shutdown  @ 08053cf0
void Draw_Shutdown(void)

{
  if (m_bDrawInitialized != 0) {
    m_bDrawInitialized = 0;
    Draw_FreeWad(menu_wad);
    menu_wad = 0;
  }
  return;
}


