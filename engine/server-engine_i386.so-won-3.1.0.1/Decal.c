// Decal_CountLumps  @ 0004f67c
int Decal_CountLumps(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 8)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// Decal_Init  @ 0004f9b4
void Decal_Init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  Draw_DecalShutdown();
  iVar1 = COM_MultipleOpenFile("decals.wad",&local_8);
  puVar3 = local_8;
  if (iVar1 < 1) {
    Sys_Error("Couldn\'t find \'%s\' in search path\n","decals.wad");
  }
  else {
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[0x43]) {
      uVar2 = Mem_Malloc(0x2c);
      Q_memset(uVar2,0,0x2c);
      Draw_CacheWadInitFromFile(puVar3[1],*puVar3,"decals.wad",0x200,uVar2);
      Decal_MergeInDecals("decals.wad",puVar3 + 2,uVar2);
    }
    COM_MultipleCloseFile(local_8);
    COM_DestroyMultipleFileList(&local_8);
  }
  sv_decalnamecount = Draw_DecalCount();
  if (0x200 < sv_decalnamecount) {
    Sys_Error("Too many decals: %d / %d\n",sv_decalnamecount,0x200);
  }
  if (0 < sv_decalnamecount) {
    iVar4 = 0;
    iVar1 = 0;
    do {
      Q_memset(sv_decalnames + iVar4,0,0x11);
      uVar2 = Draw_DecalName(iVar1,0xf);
      Q_strncpy(sv_decalnames + iVar4,uVar2);
      iVar4 = iVar4 + 0x11;
      iVar1 = iVar1 + 1;
    } while (iVar1 < sv_decalnamecount);
  }
  return;
}


// Decal_MergeInDecals  @ 0004f6b8
void Decal_MergeInDecals(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  if (param_3 == (undefined4 *)0x0) {
    Sys_Error("Decal_MergeInDecals called with NULL wad\n");
  }
  else if (decal_wad == (undefined4 *)0x0) {
    decal_wad = param_3;
    param_3[8] = 1;
    uVar3 = Mem_Malloc(param_3[8] << 2);
    decal_wad[9] = uVar3;
    uVar3 = Mem_Strdup(param_2);
    *(undefined4 *)decal_wad[9] = uVar3;
    uVar3 = Mem_Malloc(decal_wad[3] << 2);
    puVar4 = decal_wad;
    decal_wad[10] = uVar3;
    Q_memset(puVar4[10],0,puVar4[3] * 4);
  }
  else {
    puVar4 = (undefined4 *)Mem_Malloc(0x2c);
    Q_memset(puVar4,0,0x2c);
    local_c = 0;
    if (0 < (int)decal_wad[5]) {
      iVar5 = 0;
      do {
        Decal_ReplaceOrAppendLump(&local_8,iVar5 + decal_wad[4],0);
        iVar5 = iVar5 + 0x20;
        local_c = local_c + 1;
      } while (local_c < (int)decal_wad[5]);
    }
    local_c = 0;
    if (0 < (int)param_3[5]) {
      iVar5 = 0;
      do {
        Decal_ReplaceOrAppendLump(&local_8,iVar5 + param_3[4],1);
        iVar5 = iVar5 + 0x20;
        local_c = local_c + 1;
      } while (local_c < (int)param_3[5]);
    }
    uVar3 = Decal_CountLumps(local_8);
    puVar4[5] = uVar3;
    puVar4[2] = 0;
    puVar4[3] = decal_wad[3];
    uVar3 = Mem_Strdup(*decal_wad);
    *puVar4 = uVar3;
    Draw_AllocateCacheSpace(puVar4,puVar4[3],0);
    puVar4[7] = decal_wad[7];
    puVar4[6] = decal_wad[6];
    uVar3 = Mem_Malloc(puVar4[3] * 4);
    puVar4[10] = uVar3;
    Q_memset(puVar4[10],0,puVar4[3] * 4);
    puVar4[8] = 2;
    uVar3 = Mem_Malloc(8);
    puVar4[9] = uVar3;
    uVar3 = Mem_Strdup(*(undefined4 *)decal_wad[9]);
    *(undefined4 *)puVar4[9] = uVar3;
    uVar3 = Mem_Strdup(param_2);
    *(undefined4 *)(puVar4[9] + 4) = uVar3;
    uVar3 = Decal_SizeLumps(local_8);
    iVar5 = Mem_Malloc(uVar3);
    local_c = 0;
    puVar4[4] = iVar5;
    puVar2 = local_8;
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[2];
      Q_memcpy(iVar5,*puVar2,0x20);
      Mem_Free(*puVar2);
      *puVar2 = 0;
      *(uint *)(puVar4[10] + local_c * 4) = (uint)(puVar2[1] != 0);
      Mem_Free(puVar2);
      iVar5 = iVar5 + 0x20;
      local_c = local_c + 1;
      puVar2 = puVar1;
    }
    local_8 = (undefined4 *)0x0;
    Draw_FreeWad(decal_wad);
    if (decal_wad != (undefined4 *)0x0) {
      Mem_Free(decal_wad);
    }
    decal_wad = puVar4;
    Draw_FreeWad(param_3);
    Mem_Free(param_3);
  }
  return;
}


// Decal_ReplaceOrAppendLump  @ 0004f5d8
void Decal_ReplaceOrAppendLump(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      puVar3 = (undefined4 *)Mem_Malloc(0xc);
      Q_memset(puVar3,0,0xc);
      uVar4 = Mem_Malloc(0x20);
      *puVar3 = uVar4;
      Q_memcpy(*puVar3,param_2,0x20);
      puVar3[1] = param_3;
      puVar3[2] = *param_1;
      *param_1 = puVar3;
      return;
    }
    iVar2 = Q_stricmp(param_2 + 0x10,*piVar1 + 0x10);
    if (iVar2 == 0) break;
    piVar1 = (int *)piVar1[2];
  }
  Mem_Free(*piVar1);
  iVar2 = Mem_Malloc(0x20);
  *piVar1 = iVar2;
  Q_memcpy(*piVar1,param_2,0x20);
  piVar1[1] = param_3;
  return;
}


// Decal_SizeLumps  @ 0004f694
int Decal_SizeLumps(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Decal_CountLumps(param_1);
  return iVar1 << 5;
}


