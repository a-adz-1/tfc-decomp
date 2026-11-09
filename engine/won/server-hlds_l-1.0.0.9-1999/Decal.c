// Decal_CountLumps  @ 08054420
int Decal_CountLumps(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 8)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// Decal_Init  @ 080546e0
void Decal_Init(void)

{
  int iVar1;
  undefined4 *puVar2;
  char *__src;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  size_t __n;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  Draw_DecalShutdown();
  iVar1 = COM_MultipleOpenFile("decals.wad",&local_8);
  puVar5 = local_8;
  if (iVar1 < 1) {
    Sys_Error("Couldn\'t find \'%s\' in search path\n","decals.wad");
  }
  else {
    for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)puVar5[0x43]) {
      puVar2 = malloc(0x2c);
      puVar4 = puVar2;
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      Draw_CacheWadInitFromFile(puVar5[1],*puVar5,"decals.wad",0x200,puVar2);
      Decal_MergeInDecals("decals.wad",puVar5 + 2,puVar2);
    }
    COM_MultipleCloseFile(local_8);
    COM_DestroyMultipleFileList(&local_8);
  }
  sv_decalnamecount = Draw_DecalCount();
  if (0x200 < sv_decalnamecount) {
    Sys_Error("Too many decals: %d / %d\n",sv_decalnamecount,0x200);
  }
  iVar1 = 0;
  if (0 < sv_decalnamecount) {
    do {
      puVar5 = (undefined4 *)((int)&sv_decalnames + iVar1 * 0x11);
      for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      *(undefined1 *)puVar5 = 0;
      __n = 0xf;
      __src = (char *)Draw_DecalName(iVar1);
      strncpy((char *)((int)&sv_decalnames + iVar1 * 0x11),__src,__n);
      iVar1 = iVar1 + 1;
    } while (iVar1 < sv_decalnamecount);
  }
  return;
}


// Decal_MergeInDecals  @ 08054460
void Decal_MergeInDecals(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *__ptr;
  void *pvVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  size_t __size;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  if (param_3 == (undefined4 *)0x0) {
    Sys_Error("Decal_MergeInDecals called with NULL wad\n");
  }
  else if (decal_wad == (undefined4 *)0x0) {
    decal_wad = param_3;
    param_3[8] = 1;
    pvVar2 = malloc(4);
    decal_wad[9] = pvVar2;
    pcVar3 = strdup(param_2);
    *(char **)decal_wad[9] = pcVar3;
    pvVar2 = malloc(decal_wad[3] << 2);
    puVar6 = decal_wad;
    decal_wad[10] = pvVar2;
    memset((void *)puVar6[10],0,puVar6[3] * 4);
  }
  else {
    puVar4 = malloc(0x2c);
    puVar6 = puVar4;
    for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    iVar7 = 0;
    if (0 < (int)decal_wad[5]) {
      do {
        Decal_ReplaceOrAppendLump(&local_8,iVar7 * 0x20 + decal_wad[4],0);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)decal_wad[5]);
    }
    iVar7 = 0;
    if (0 < (int)param_3[5]) {
      do {
        Decal_ReplaceOrAppendLump(&local_8,iVar7 * 0x20 + param_3[4],1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)param_3[5]);
    }
    uVar5 = Decal_CountLumps(local_8);
    puVar4[5] = uVar5;
    puVar4[2] = 0;
    puVar6 = decal_wad;
    puVar4[3] = decal_wad[3];
    pcVar3 = strdup((char *)*puVar6);
    *puVar4 = pcVar3;
    Draw_AllocateCacheSpace(puVar4,puVar4[3],0);
    puVar6 = decal_wad;
    puVar4[7] = decal_wad[7];
    puVar4[6] = puVar6[6];
    pvVar2 = malloc(puVar4[3] * 4);
    puVar4[10] = pvVar2;
    memset(pvVar2,0,puVar4[3] * 4);
    puVar4[8] = 2;
    pvVar2 = malloc(8);
    puVar4[9] = pvVar2;
    pcVar3 = strdup(*(char **)decal_wad[9]);
    *(char **)puVar4[9] = pcVar3;
    pcVar3 = strdup(param_2);
    *(char **)(puVar4[9] + 4) = pcVar3;
    __size = Decal_SizeLumps(local_8);
    puVar6 = malloc(__size);
    puVar4[4] = puVar6;
    iVar7 = 0;
    __ptr = local_8;
    while (__ptr != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)__ptr[2];
      puVar9 = (undefined4 *)*__ptr;
      puVar10 = puVar6;
      for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      *__ptr = 0;
      *(uint *)(puVar4[10] + iVar7 * 4) = (uint)(__ptr[1] != 0);
      free(__ptr);
      puVar6 = puVar6 + 8;
      iVar7 = iVar7 + 1;
      __ptr = puVar1;
    }
    local_8 = (undefined4 *)0x0;
    Draw_FreeWad(decal_wad);
    decal_wad = puVar4;
  }
  return;
}


// Decal_ReplaceOrAppendLump  @ 08054370
void Decal_ReplaceOrAppendLump(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      puVar4 = malloc(0xc);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar3 = malloc(0x20);
      *puVar4 = puVar3;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar4[1] = param_3;
      puVar4[2] = *param_1;
      *param_1 = puVar4;
      return;
    }
    iVar2 = strcasecmp((char *)(param_2 + 4),(char *)(*piVar1 + 0x10));
    if (iVar2 == 0) break;
    piVar1 = (int *)piVar1[2];
  }
  free((void *)*piVar1);
  puVar3 = malloc(0x20);
  *piVar1 = (int)puVar3;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  piVar1[1] = param_3;
  return;
}


// Decal_SizeLumps  @ 08054440
int Decal_SizeLumps(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Decal_CountLumps(param_1);
  return iVar1 << 5;
}


