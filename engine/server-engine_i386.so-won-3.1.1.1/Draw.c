// Draw_AllocateCacheSpace  @ 0005f61c
void Draw_AllocateCacheSpace(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x5f628;
  uVar1 = Mem_Malloc(param_2 * 0x44);
  *(undefined4 *)(param_1 + 4) = uVar1;
  Q_memset(*(undefined4 *)(param_1 + 4),0,param_2 * 0x44,uVar2);
  return;
}


// Draw_CacheByIndex  @ 00060024
int Draw_CacheByIndex(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char local_2c [32];
  int local_c;
  char *local_8;
  
  snprintf(local_2c,0x20,"%03i%02i",param_3,param_2);
  local_8 = (char *)param_1[1];
  local_c = 0;
  while ((local_c < (int)param_1[2] && (iVar1 = Q_strcmp(local_8,local_2c), iVar1 != 0))) {
    local_8 = local_8 + 0x44;
    local_c = local_c + 1;
  }
  if (local_c == param_1[2]) {
    if (param_1[2] == param_1[3]) {
      Sys_Error("Cache wad (%s) out of %d entries",*param_1,param_1[3]);
    }
    param_1[2] = param_1[2] + 1;
    snprintf(local_8,0x40,"%s",local_2c);
  }
  return local_c;
}


// Draw_CacheFindIndex  @ 00061434
int Draw_CacheFindIndex(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = *(int *)(param_1 + 4);
  local_c = 0;
  while( true ) {
    if (*(int *)(param_1 + 8) <= local_c) {
      return -1;
    }
    iVar1 = Q_strcmp(param_2,local_8);
    if (iVar1 == 0) break;
    local_8 = local_8 + 0x44;
    local_c = local_c + 1;
  }
  return local_c;
}


// Draw_CacheGet  @ 00060ac4
int Draw_CacheGet(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iStack_38;
  undefined1 auStack_34 [16];
  undefined1 auStack_24 [16];
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if ((int)param_1[2] <= param_2) {
    Sys_Error("Cache wad indexed before load %s: %d",*param_1,param_2);
  }
  iStack_8 = param_1[1] + param_2 * 0x44;
  iStack_10 = Cache_Check(iStack_8 + 0x40);
  if (iStack_10 == 0) {
    iStack_14 = iStack_8;
    COM_FileBase(iStack_8,auStack_24);
    W_CleanupName(auStack_24,auStack_34);
    iStack_38 = param_1[4];
    iStack_c = 0;
    while ((iStack_c < (int)param_1[5] &&
           (iVar1 = Q_strcmp(auStack_34,iStack_38 + 0x10), iVar1 != 0))) {
      iStack_c = iStack_c + 1;
      iStack_38 = iStack_38 + 0x20;
    }
    if (iStack_c < (int)param_1[5]) {
      iVar1 = Draw_CacheReload(param_1,iStack_c,iStack_38,iStack_8,auStack_34,iStack_14);
      if (iVar1 == 0) {
        iStack_10 = 0;
      }
      else {
        iStack_10 = *(int *)(iStack_8 + 0x40);
        if (iStack_10 == 0) {
          Sys_Error(FUN_000e1060,iStack_14);
        }
      }
    }
    else {
      iStack_10 = 0;
    }
  }
  return iStack_10;
}


// Draw_CacheIndex  @ 0006136c
int Draw_CacheIndex(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = param_1[1];
  local_c = 0;
  while ((local_c < (int)param_1[2] && (iVar1 = Q_strcmp(param_2,local_8), iVar1 != 0))) {
    local_8 = local_8 + 0x44;
    local_c = local_c + 1;
  }
  if (local_c == param_1[2]) {
    if (param_1[2] == param_1[3]) {
      Sys_Error("Cache wad (%s) out of %d entries",*param_1,param_1[3]);
    }
    param_1[2] = param_1[2] + 1;
    Q_strncpy(local_8,param_2,0x3f);
    *(undefined1 *)(local_8 + 0x3f) = 0;
  }
  return local_c;
}


// Draw_CacheLoadFromCustom  @ 000611a0
void Draw_CacheLoadFromCustom
               (int param_1,undefined4 *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iStack_8;
  
  iVar1 = Q_strlen(param_1);
  if (iVar1 < 5) {
    iStack_8 = 0;
  }
  else {
    iStack_8 = Q_atoi(param_1 + 3);
    if ((iStack_8 < 0) || ((int)param_2[5] <= iStack_8)) {
      FUN_00061360();
      return;
    }
  }
  piVar3 = (int *)(param_2[4] + iStack_8 * 0x20);
  iVar1 = Cache_Alloc(param_5 + 0x40,piVar3[2] + param_2[6] + 1,param_1);
  if (iVar1 == 0) {
    Sys_Error("Draw_CacheGet: not enough space for %s in %s",param_1,*param_2);
  }
  *(undefined1 *)(piVar3[2] + param_2[6] + iVar1) = 0;
  Q_memcpy(param_2[6] + iVar1,*piVar3 + param_3,piVar3[2]);
  iVar2 = Draw_ValidateCustomLogo(param_2,iVar1,piVar3);
  if (iVar2 != 0) {
    gfCustomBuild = 1;
    Q_strcpy(szCustName,&UNK_000e115f);
    Q_memcpy(0x300761,param_1,5);
    szCustName[6] = 0;
    if (param_2[7] != 0) {
      (*(code *)param_2[7])(param_2,iVar1);
    }
    gfCustomBuild = 0;
    FUN_00061360();
    return;
  }
  FUN_00061360();
  return;
}


// Draw_CacheReload  @ 00060d4c
void Draw_CacheReload(undefined4 *param_1,int param_2,undefined4 *param_3,int param_4,
                     undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int local_10;
  
  if ((int)param_1[8] < 1) {
    local_10 = FS_Open(*param_1,&DAT_000e0c42);
  }
  else {
    local_10 = FS_OpenPathID(*param_1,&DAT_000e0c42,
                             *(undefined4 *)(param_1[9] + *(int *)(param_1[10] + param_2 * 4) * 4));
  }
  if (local_10 == 0) {
    FUN_00060ec8();
    return;
  }
  FS_Size(local_10);
  iVar1 = Cache_Alloc(param_4 + 0x40,param_3[2] + param_1[6] + 1,param_5);
  if (iVar1 == 0) {
    Sys_Error("Draw_CacheGet: not enough space for %s in %s",param_6,*param_1);
  }
  *(undefined1 *)(param_3[2] + param_1[6] + iVar1) = 0;
  FS_Seek(local_10,*param_3,0);
  FS_Read(param_1[6] + iVar1,param_3[2],1,local_10);
  FS_Close(local_10);
  if (param_1[7] != 0) {
    (*(code *)param_1[7])(param_1,iVar1);
  }
  FUN_00060ec8();
  return;
}


// Draw_CacheWadHandler  @ 0005fb18
void Draw_CacheWadHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return;
}


// Draw_CacheWadInit  @ 0005f7cc
void Draw_CacheWadInit(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FS_Open(param_1,&DAT_000e0c42);
  if (iVar1 == 0) {
    Sys_Error("Draw_LoadWad: Couldn\'t open %s\n",param_1);
  }
  uVar2 = FS_Size(iVar1);
  Draw_CacheWadInitFromFile(iVar1,uVar2,param_1,param_2,param_3);
  FS_Close(iVar1);
  return;
}


// Draw_CacheWadInitFromFile  @ 0005f67c
void Draw_CacheWadInitFromFile
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  int local_18;
  char local_14;
  char local_13;
  char local_12;
  char local_11;
  int local_10;
  int local_c;
  int local_8;
  
  FS_Read(&local_14,0xc,1,param_1);
  if ((((local_14 != 'W') || (local_13 != 'A')) || (local_12 != 'D')) || (local_11 != '3')) {
    Sys_Error("Wad file %s doesn\'t have WAD3 id\n",param_3);
  }
  uVar1 = Mem_Malloc(param_2 - local_c);
  *(undefined4 *)(param_5 + 0x10) = uVar1;
  FS_Seek(param_1,local_c,0);
  FS_Read(*(undefined4 *)(param_5 + 0x10),param_2 - local_c,1,param_1);
  local_18 = 0;
  local_8 = *(int *)(param_5 + 0x10);
  for (; local_18 < local_10; local_18 = local_18 + 1) {
    W_CleanupName(local_8 + 0x10,local_8 + 0x10);
    local_8 = local_8 + 0x20;
  }
  FUN_0005f768();
  return;
}


// Draw_CustomCacheGet  @ 00060c38
int Draw_CustomCacheGet(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  int local_10;
  int local_c;
  int local_8;
  
  if ((int)param_1[2] <= param_4) {
    Sys_Error("Cache wad indexed before load %s: %d",*param_1,param_4);
  }
  local_8 = param_1[1] + param_4 * 0x44;
  local_c = Cache_Check(local_8 + 0x40);
  if (local_c == 0) {
    local_10 = local_8;
    COM_FileBase(local_8,local_20);
    W_CleanupName(local_20,local_30);
    iVar1 = Draw_CacheLoadFromCustom(local_30,param_1,param_2,param_3,local_8);
    if (iVar1 == 0) {
      local_c = 0;
    }
    else {
      local_c = *(int *)(local_8 + 0x40);
      if (local_c == 0) {
        Sys_Error(FUN_000e1060,local_10);
      }
    }
  }
  return local_c;
}


// Draw_CustomCacheWadInit  @ 0005f864
void Draw_CustomCacheWadInit(undefined4 param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  char local_14;
  char cStack_13;
  char cStack_12;
  char cStack_11;
  uint *local_8;
  
  uVar3 = *param_3;
  iVar1 = param_3[2];
  local_14 = (char)uVar3;
  if ((((local_14 != 'W') || (cStack_13 = (char)((uint)uVar3 >> 8), cStack_13 != 'A')) ||
      (cStack_12 = (char)((uint)uVar3 >> 0x10), cStack_12 != 'D')) ||
     (cStack_11 = (char)((uint)uVar3 >> 0x18), cStack_11 != '3')) {
    Con_Printf("Custom file doesn\'t have WAD3 id\n");
    FUN_0005fb10();
    return;
  }
  if (param_3[1] != 1) {
    Con_Printf("Custom file has wrong number of lumps %i\n",param_3[1]);
    FUN_0005fb10();
    return;
  }
  if (iVar1 < 1) {
    Con_Printf("Custom file has bogus infotableofs %i\n",iVar1);
    FUN_0005fb10();
    return;
  }
  if (iVar1 + 0x20 != param_4) {
    Con_Printf("Custom file has bogus infotableofs ( %i > %i )\n",iVar1 + 0x20,param_4);
    FUN_0005fb10();
    return;
  }
  uVar3 = Mem_Malloc(param_4 - iVar1);
  *(undefined4 *)(param_2 + 0x10) = uVar3;
  Q_memcpy(*(undefined4 *)(param_2 + 0x10),(int)param_3 + iVar1,param_4 - iVar1);
  bVar2 = false;
  local_8 = *(uint **)(param_2 + 0x10);
  while( true ) {
    if (bVar2) {
      FUN_0005faa8();
      return;
    }
    W_CleanupName(local_8 + 4,local_8 + 4);
    if (local_8[2] != local_8[1]) {
      Con_Printf("Custom file has mismatched lump size ( %i vs. %i )\n",local_8[2],local_8[1]);
      FUN_0005fb10();
      return;
    }
    if ((int)local_8[1] < 1) {
      Con_Printf("Custom file has bogus lump size %i\n",local_8[1]);
      FUN_0005fb10();
      return;
    }
    if (*local_8 < 0xc) break;
    if (iVar1 < (int)(*local_8 + local_8[1])) {
      Con_Printf("Custom file has bogus lump %i\n",0);
      FUN_0005fb10();
      return;
    }
    bVar2 = true;
    local_8 = local_8 + 8;
  }
  Con_Printf("Custom file has bogus lump offset %i\n",*local_8);
  FUN_0005fb10();
  return;
}


// Draw_DecalCount  @ 0005fde4
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


// Draw_DecalIndex  @ 0005fd00
undefined4 Draw_DecalIndex(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *local_28;
  char local_24 [32];
  
  if (decal_names[param_1 * 0x10] == '\0') {
    Sys_Error("Used decal #%d without a name\n",param_1);
  }
  local_28 = decal_names + param_1 * 0x10;
  iVar1 = Host_IsServerActive();
  if ((iVar1 == 0) &&
     ((byte)((byte)((ushort)((ushort)NAN((float)violence_hblood._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)violence_hblood._12_4_ == 0.0) << 0xe) >> 8)) == 0x40))
  {
    iVar1 = Q_strncmp(local_28,"{blood",6);
    if (iVar1 == 0) {
      snprintf(local_24,0x20,"{yblood%s",param_1 * 0x10 + 0x2fe766);
      local_28 = local_24;
    }
  }
  uVar2 = Draw_CacheIndex(decal_wad,local_28);
  return uVar2;
}


// Draw_DecalIndexFromName  @ 00060110
void Draw_DecalIndexFromName(undefined4 param_1)

{
  int iVar1;
  int local_18;
  char local_14 [15];
  undefined1 local_5;
  
  Q_strncpy(local_14,param_1,0xf);
  local_5 = 0;
  if (local_14[0] == '}') {
    local_14[0] = '{';
  }
  local_18 = 0;
  do {
    if (0x1ff < local_18) {
      FUN_000601ac();
      return;
    }
    if (decal_names[local_18 * 0x10] != '\0') {
      iVar1 = Q_strcmp(local_14,decal_names + local_18 * 0x10);
      if (iVar1 == 0) {
        FUN_000601b0();
        return;
      }
    }
    local_18 = local_18 + 1;
  } while( true );
}


// Draw_DecalName  @ 0005fe70
int Draw_DecalName(int param_1)

{
  int iVar1;
  
  if (decal_wad == 0) {
    iVar1 = 0;
  }
  else if (param_1 < *(int *)(decal_wad + 0x14)) {
    iVar1 = param_1 * 0x20 + *(int *)(decal_wad + 0x10) + 0x10;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// Draw_DecalSetName  @ 0005fca0
void Draw_DecalSetName(int param_1,undefined4 param_2)

{
  if (param_1 < 0x200) {
    Q_strncpy(decal_names + param_1 * 0x10,param_2,0xf);
    decal_names[param_1 * 0x10 + 0xf] = 0;
  }
  return;
}


// Draw_DecalShutdown  @ 0005f5c8
void Draw_DecalShutdown(void)

{
  Draw_FreeWad(decal_wad);
  if (decal_wad != 0) {
    Mem_Free(decal_wad);
  }
  decal_wad = 0;
  return;
}


// Draw_DecalSize  @ 0005fe18
void Draw_DecalSize(void)

{
  FUN_0005fe21();
  return;
}


// Draw_DecalTexture  @ 0005fecc
void Draw_DecalTexture(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (-1 < param_1) {
    Draw_CacheGet(decal_wad,param_1);
    FUN_0006001c();
    return;
  }
  param_1 = -1 - param_1;
  piVar1 = *(int **)(cl + param_1 * 0x24c + 0x1a4314);
  if ((((piVar1 != (int *)0x0) && (*piVar1 != 0)) && (piVar1[0x26] != 0)) && (piVar1[0x27] != 0)) {
    iVar2 = Draw_CustomCacheGet(piVar1[0x26],piVar1[0x27],piVar1[0x13],piVar1[0x24]);
    if (iVar2 != 0) {
      FUN_0006001c();
      return;
    }
    Draw_CacheGet(decal_wad,0);
    FUN_0006001c();
    return;
  }
  Sys_Error("Failed to load custom decal for player #%i:%s using default decal 0.\n",param_1,
            param_1 * 0x24c + 0x2eec04);
  FUN_0006001c();
  return;
}


// Draw_FreeWad  @ 0005fb34
void Draw_FreeWad(undefined4 *param_1)

{
  int iVar1;
  int iStack_10;
  int local_c;
  int iStack_8;
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[4] != 0) {
      Mem_Free(param_1[4]);
    }
    param_1[4] = 0;
    Mem_Free(*param_1);
    if (param_1[8] != 0) {
      for (local_c = 0; local_c < (int)param_1[8]; local_c = local_c + 1) {
        Mem_Free(*(undefined4 *)(param_1[9] + local_c * 4));
        *(undefined4 *)(param_1[9] + local_c * 4) = 0;
      }
      FUN_0005fbe8();
      return;
    }
    if (param_1[10] != 0) {
      Mem_Free(param_1[10]);
      param_1[10] = 0;
    }
    iStack_8 = param_1[1];
    if (iStack_8 != 0) {
      for (iStack_10 = 0; iStack_10 < (int)param_1[2]; iStack_10 = iStack_10 + 1) {
        iVar1 = Cache_Check(iStack_8 + 0x40);
        if (iVar1 != 0) {
          Cache_Free(iStack_8 + 0x40);
        }
        iStack_8 = iStack_8 + 0x44;
      }
      Mem_Free(param_1[1]);
    }
  }
  return;
}


// Draw_Init  @ 000c619c
void Draw_Init(void)

{
  return;
}


// Draw_MiptexTexture  @ 0005f2a8
void Draw_MiptexTexture(undefined4 *param_1,undefined1 *param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iStack_38;
  undefined4 local_34 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 auStack_1c [4];
  undefined4 *local_c;
  undefined1 *local_8;
  
  if (param_1[6] != 0x18) {
    Sys_Error("Draw_MiptexTexture: Bad cached wad %s\n",*param_1);
  }
  local_c = (undefined4 *)(param_2 + param_1[6]);
  puVar5 = local_c;
  puVar6 = local_34;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  local_8 = param_2;
  Q_memcpy(param_2,local_34,0x10);
  uVar3 = (*LittleLong)(uStack_24);
  *(undefined4 *)(local_8 + 0x10) = uVar3;
  uVar3 = (*LittleLong)(uStack_20);
  *(undefined4 *)(local_8 + 0x14) = uVar3;
  *(undefined4 *)(local_8 + 0x20) = 0;
  *(undefined4 *)(local_8 + 0x1c) = 0;
  *(undefined4 *)(local_8 + 0x18) = 0;
  *(undefined4 *)(local_8 + 0x28) = 0;
  *(undefined4 *)(local_8 + 0x24) = 0;
  for (iStack_38 = 0; puVar2 = local_8, iStack_38 < 4; iStack_38 = iStack_38 + 1) {
    iVar4 = (*LittleLong)(auStack_1c[iStack_38]);
    *(int *)(local_8 + iStack_38 * 4 + 0x2c) = param_1[6] + iVar4;
  }
  iVar4 = *(int *)(local_8 + 0x10) * *(int *)(local_8 + 0x14);
  iVar4 = iVar4 + (iVar4 >> 2) + (iVar4 >> 4) + (iVar4 >> 6);
  *(int *)(local_8 + 0x3c) = iVar4 + *(int *)(local_8 + 0x2c) + 2;
  uVar1 = *(ushort *)((int)local_c + iVar4 + 0x28);
  iVar4 = *(int *)(local_8 + 0x3c);
  if (gfCustomBuild != 0) {
    Q_strncpy(local_8,szCustName,0xf);
    local_8[0xf] = 0;
  }
  if (((puVar2[iVar4 + 0x2fd] == '\0') && (puVar2[iVar4 + 0x2fe] == '\0')) &&
     (puVar2[iVar4 + 0x2ff] == -1)) {
    *local_8 = 0x7b;
  }
  else {
    *local_8 = 0x7d;
  }
  for (iStack_38 = 0; iStack_38 < (int)(uint)uVar1; iStack_38 = iStack_38 + 1) {
    puVar2[iStack_38 * 3 + iVar4] = texgammatable[(byte)puVar2[iStack_38 * 3 + iVar4]];
    puVar2[iStack_38 * 3 + iVar4 + 1] = texgammatable[(byte)puVar2[iStack_38 * 3 + iVar4 + 1]];
    puVar2[iStack_38 * 3 + iVar4 + 2] = texgammatable[(byte)puVar2[iStack_38 * 3 + iVar4 + 2]];
  }
  FUN_0005f548();
  return;
}


// Draw_Shutdown  @ 0005f554
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


// Draw_ValidateCustomLogo  @ 00060ed4
void Draw_ValidateCustomLogo(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iStack_74;
  undefined4 local_70 [4];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_58 [4];
  undefined4 *local_48;
  undefined4 local_44 [4];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int aiStack_18 [5];
  
  if (param_1[6] != 0x18) {
    Con_Printf("Draw_ValidateCustomLogo: Bad cached wad %s\n",*param_1);
    FUN_00061190();
    return;
  }
  local_48 = (undefined4 *)(param_1[6] + (int)param_2);
  puVar2 = local_48;
  puVar3 = local_70;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  Q_memcpy(local_44,local_70,0x10);
  uStack_34 = (*LittleLong)(uStack_60);
  uStack_30 = (*LittleLong)(uStack_5c);
  uStack_24 = 0;
  uStack_28 = 0;
  uStack_2c = 0;
  uStack_1c = 0;
  uStack_20 = 0;
  for (iStack_74 = 0; iStack_74 < 4; iStack_74 = iStack_74 + 1) {
    iVar1 = (*LittleLong)(auStack_58[iStack_74]);
    aiStack_18[iStack_74] = param_1[6] + iVar1;
  }
  FUN_00061004();
  return;
}


