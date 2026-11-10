// Decal_CountLumps  @ 000602c4
int Decal_CountLumps(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = param_1; local_c != 0; local_c = *(int *)(local_c + 8)) {
    local_8 = local_8 + 1;
  }
  return local_8;
}


// Decal_Init  @ 0006074c
void Decal_Init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 local_2c [8];
  int local_c;
  int local_8;
  
  pcVar4 = "DEFAULTGAME";
  puVar5 = local_2c;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = *(undefined2 *)pcVar4;
  Draw_DecalShutdown();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    local_c = FS_OpenPathID("decals.wad",&DAT_000e0c42,(int)local_2c + local_8 * 0xf);
    if (local_c == 0) {
      if (local_8 == 0) {
        Sys_Error("Couldn\'t find \'%s\' in \"%s\" search path\n","decals.wad",local_2c);
      }
    }
    else {
      uVar1 = FS_Size(local_c);
      uVar2 = Mem_Malloc(0x2c);
      Q_memset(uVar2,0,0x2c);
      Draw_CacheWadInitFromFile(local_c,uVar1,"decals.wad",0x200,uVar2);
      Decal_MergeInDecals(uVar2,(int)local_2c + local_8 * 0xf);
      FS_Close(local_c);
    }
  }
  FUN_00060898();
  return;
}


// Decal_MergeInDecals  @ 00060334
void Decal_MergeInDecals(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_8;
  
  uStack_14 = 0;
  if (param_1 == 0) {
    Sys_Error("Decal_MergeInDecals called with NULL wad\n");
  }
  else {
    if (decal_wad != 0) {
      uVar1 = Mem_Malloc(0x2c);
      Q_memset(uVar1,0,0x2c);
      for (iStack_8 = 0; iStack_8 < *(int *)(decal_wad + 0x14); iStack_8 = iStack_8 + 1) {
        iStack_10 = *(int *)(decal_wad + 0x10) + iStack_8 * 0x20;
        Decal_ReplaceOrAppendLump(&uStack_14,iStack_10,0);
      }
      for (iStack_8 = 0; iStack_8 < *(int *)(param_1 + 0x14); iStack_8 = iStack_8 + 1) {
        iStack_10 = *(int *)(param_1 + 0x10) + iStack_8 * 0x20;
        Decal_ReplaceOrAppendLump(&uStack_14,iStack_10,1);
      }
      FUN_000604e8();
      return;
    }
    decal_wad = param_1;
    *(undefined4 *)(param_1 + 0x20) = 1;
    uVar1 = Mem_Malloc(*(int *)(decal_wad + 0x20) * 4);
    *(undefined4 *)(decal_wad + 0x24) = uVar1;
    uVar1 = Mem_Strdup(param_2);
    **(undefined4 **)(decal_wad + 0x24) = uVar1;
    uVar1 = Mem_Malloc(*(int *)(decal_wad + 0xc) * 4);
    *(undefined4 *)(decal_wad + 0x28) = uVar1;
    Q_memset(*(undefined4 *)(decal_wad + 0x28),0,*(int *)(decal_wad + 0xc) * 4);
  }
  return;
}


// Decal_ReplaceOrAppendLump  @ 000601b8
void Decal_ReplaceOrAppendLump(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piStack_8;
  
  uVar2 = 0x601c4;
  piStack_8 = (int *)*param_1;
  while( true ) {
    if (piStack_8 == (int *)0x0) {
      FUN_00060250();
      return;
    }
    iVar1 = Q_stricmp(param_2 + 0x10,*piStack_8 + 0x10);
    if (iVar1 == 0) break;
    piStack_8 = (int *)piStack_8[2];
  }
  Mem_Free(*piStack_8);
  iVar1 = Mem_Malloc(0x20);
  *piStack_8 = iVar1;
  Q_memcpy(*piStack_8,param_2,0x20,uVar2);
  piStack_8[1] = param_3;
  return;
}


// Decal_SizeLumps  @ 000602fc
int Decal_SizeLumps(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Decal_CountLumps(param_1);
  return iVar1 << 5;
}


