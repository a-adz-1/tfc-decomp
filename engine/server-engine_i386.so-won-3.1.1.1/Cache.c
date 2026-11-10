// Cache_Alloc  @ 000c257c
undefined4 Cache_Alloc(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*param_1 != 0) {
    Sys_Error("Cache_Alloc: already allocated");
  }
  if (param_2 < 1) {
    Sys_Error("Cache_Alloc: size %i",param_2);
  }
  while( true ) {
    iVar1 = Cache_TryAlloc(param_2 + 0x67U & 0xfffffff0,0);
    if (iVar1 != 0) break;
    if ((undefined1 *)cache_head._80_4_ == cache_head) {
      Sys_Error("Cache_Alloc: out of memory");
    }
    Cache_Free(*(undefined4 *)(cache_head._80_4_ + 4));
  }
  Q_strncpy(iVar1 + 8,param_3,0x3f);
  *(undefined1 *)(iVar1 + 0x47) = 0;
  *param_1 = iVar1 + 0x58;
  *(int **)(iVar1 + 4) = param_1;
  uVar2 = Cache_Check(param_1);
  return uVar2;
}


// Cache_Check  @ 000c2520
int Cache_Check(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
    Cache_UnlinkLRU(iVar1 + -0x58);
    Cache_MakeLRU(iVar1 + -0x58);
    iVar1 = *param_1;
  }
  return iVar1;
}


// Cache_Compact  @ 000c23c0
void Cache_Compact(void)

{
  return;
}


// Cache_Flush  @ 000c1f5c
void Cache_Flush(void)

{
  if (((int)cl._1717472_4_ < 2) || (allow_cheats != 0)) {
    Cache_Force_Flush();
  }
  else {
    Con_Printf("Server must enable sv_cheats to activate the flush command in multiplayer games.\n")
    ;
  }
  return;
}


// Cache_Force_Flush  @ 000c1f0c
void Cache_Force_Flush(void)

{
  while ((undefined1 *)cache_head._76_4_ != cache_head) {
    Cache_Free(*(undefined4 *)(cache_head._76_4_ + 4));
  }
  return;
}


// Cache_Free  @ 000c2438
void Cache_Free(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    Sys_Error("Cache_Free: not allocated");
  }
  iVar1 = *param_1;
  *(undefined4 *)(*(int *)(iVar1 + -0x10) + 0x4c) = *(undefined4 *)(iVar1 + -0xc);
  *(undefined4 *)(*(int *)(iVar1 + -0xc) + 0x48) = *(undefined4 *)(iVar1 + -0x10);
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0xc) = 0;
  *param_1 = 0;
  Cache_UnlinkLRU(iVar1 + -0x58);
  return;
}


// Cache_FreeHigh  @ 000c1b20
void Cache_FreeHigh(int param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while ((iVar1 = cache_head._72_4_, (undefined1 *)cache_head._72_4_ != cache_head &&
         ((uint)((hunk_base + hunk_size) - param_1) <
          (uint)(*(int *)cache_head._72_4_ + cache_head._72_4_)))) {
    if (cache_head._72_4_ == local_c) {
      Cache_Free(*(undefined4 *)(cache_head._72_4_ + 4));
    }
    else {
      Cache_Move(cache_head._72_4_);
      local_c = iVar1;
    }
  }
  return;
}


// Cache_FreeLow  @ 000c1ab8
void Cache_FreeLow(int param_1)

{
  while (((undefined1 *)cache_head._76_4_ != cache_head &&
         ((uint)cache_head._76_4_ < (uint)(param_1 + hunk_base)))) {
    Cache_Move(cache_head._76_4_);
  }
  return;
}


// Cache_Init  @ 000c23c8
void Cache_Init(void)

{
  cache_head._72_4_ = cache_head;
  cache_head._76_4_ = cache_head;
  cache_head._80_4_ = cache_head;
  cache_head._84_4_ = cache_head;
  Cmd_AddCommand("flush",Cache_Flush);
  return;
}


// Cache_MakeLRU  @ 000c1c38
void Cache_MakeLRU(int param_1)

{
  if ((*(int *)(param_1 + 0x54) != 0) || (*(int *)(param_1 + 0x50) != 0)) {
    Sys_Error("Cache_MakeLRU: active link");
  }
  *(int *)(cache_head._84_4_ + 0x50) = param_1;
  *(undefined4 *)(param_1 + 0x54) = cache_head._84_4_;
  *(undefined1 **)(param_1 + 0x50) = cache_head;
  cache_head._84_4_ = param_1;
  return;
}


// Cache_Move  @ 000c1a00
void Cache_Move(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc1a0c;
  iVar1 = Cache_TryAlloc(*param_1,1);
  if (iVar1 == 0) {
    Cache_Free(param_1[1]);
  }
  else {
    Q_memcpy(iVar1 + 0x58,param_1 + 0x16,*param_1 + -0x58,uVar2);
    *(int *)(iVar1 + 4) = param_1[1];
    Q_memcpy(iVar1 + 8,param_1 + 2,0x40);
    Cache_Free(param_1[1]);
    **(int **)(iVar1 + 4) = iVar1 + 0x58;
  }
  return;
}


// Cache_Print  @ 000c1ffc
void Cache_Print(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined1 local_848 [52];
  int local_814;
  int local_810;
  char *local_80c;
  int local_808 [512];
  undefined1 *local_8;
  
  local_80c = (char *)0x0;
  local_810 = 0;
  local_814 = FS_Open(mem_dbgfile._4_4_,&DAT_000ecf1c);
  if (local_814 != 0) {
    Q_memset(local_808,0x800,0);
    FS_FPrintf(local_814,"\nCACHE:\n");
    for (local_8 = (undefined1 *)cache_head._76_4_; local_8 != cache_head;
        local_8 = *(undefined1 **)(local_8 + 0x4c)) {
      local_808[(int)local_80c] = (int)local_8;
      local_80c = local_80c + 1;
    }
    uVar2 = 4;
    pcVar1 = local_80c;
    qsort(local_808,(size_t)local_80c,4,CacheSystemCompare);
    for (local_810 = 0; local_810 < (int)local_80c; local_810 = local_810 + 1) {
      uVar2 = CommatizeNumber(*(undefined4 *)local_808[local_810],local_848,pcVar1,uVar2,
                              local_808[local_810] + 8);
      pcVar1 = "%16.16s : %-16s\n";
      FS_FPrintf(local_814);
    }
    FS_Close(local_814);
  }
  return;
}


// Cache_Print_Models_And_Totals  @ 000c27a0
void Cache_Print_Models_And_Totals(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  int local_854;
  int local_848;
  int local_844;
  size_t local_840;
  int local_83c [512];
  undefined1 *local_3c;
  undefined1 local_38 [52];
  
  local_840 = 0;
  local_848 = 0;
  iVar1 = FS_Open(mem_dbgfile._4_4_,&DAT_000ecf1c);
  if (iVar1 != 0) {
    Q_memset(local_83c,0x800,0);
    for (local_3c = (undefined1 *)cache_head._76_4_; local_3c != cache_head;
        local_3c = *(undefined1 **)(local_3c + 0x4c)) {
      iVar2 = Q_strstr(local_3c + 8,&DAT_000ed2dc);
      if (iVar2 != 0) {
        local_83c[local_840] = (int)local_3c;
        local_840 = local_840 + 1;
      }
    }
    pcVar3 = CacheSystemCompare;
    uVar5 = 4;
    qsort(local_83c,local_840,4,CacheSystemCompare);
    pcVar4 = "\nCACHED MODELS:\n";
    FS_FPrintf(iVar1,"\nCACHED MODELS:\n");
    for (local_844 = 0; local_844 < (int)local_840; local_844 = local_844 + 1) {
      for (local_854 = 0; local_854 < *(int *)(**(int **)(local_83c[local_844] + 4) + 0xb4);
          local_854 = local_854 + 1) {
      }
      pcVar3 = (code *)(local_83c[local_844] + 8);
      uVar5 = CommatizeNumber(*(undefined4 *)local_83c[local_844],local_38,pcVar4,uVar5,pcVar3);
      pcVar4 = "\t%16.16s : %s\n";
      FS_FPrintf(iVar1);
      local_848 = local_848 + *(int *)local_83c[local_844];
    }
    uVar5 = CommatizeNumber(local_848,local_38,pcVar4,uVar5,pcVar3);
    FS_FPrintf(iVar1,"Total bytes in cache used by models:  %s\n",uVar5);
    FS_Close(iVar1);
  }
  return;
}


// Cache_Print_Sounds_And_Totals  @ 000c2a9c
void Cache_Print_Sounds_And_Totals(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 local_a50 [512];
  int local_850;
  int local_84c;
  int local_848;
  int local_844;
  size_t local_840;
  int local_83c [512];
  undefined1 *local_3c;
  undefined1 local_38 [52];
  
  local_840 = 0;
  local_844 = 0;
  local_848 = 0;
  local_84c = FS_Open(mem_dbgfile._4_4_,&DAT_000ecf1c);
  local_850 = 0;
  if (local_84c != 0) {
    Q_memset(local_83c,0x800,0);
    for (local_3c = (undefined1 *)cache_head._76_4_; local_3c != cache_head;
        local_3c = *(undefined1 **)(local_3c + 0x4c)) {
      iVar2 = Q_strstr(local_3c + 8,&DAT_000ed34a);
      if (iVar2 != 0) {
        local_83c[local_840] = (int)local_3c;
        local_840 = local_840 + 1;
      }
    }
    pcVar1 = CacheSystemCompare;
    puVar5 = (undefined1 *)0x4;
    qsort(local_83c,local_840,4,CacheSystemCompare);
    if (local_84c != 0) {
      pcVar4 = "\nCACHED SOUNDS:\n";
      FS_FPrintf(local_84c,"\nCACHED SOUNDS:\n");
      for (local_844 = 0; local_844 < (int)local_840; local_844 = local_844 + 1) {
        pcVar1 = (code *)(local_83c[local_844] + 8);
        puVar5 = (undefined1 *)
                 CommatizeNumber(*(undefined4 *)local_83c[local_844],local_38,pcVar4,puVar5,pcVar1);
        FS_FPrintf(local_84c,"\t%16.16s : %s\n");
        local_848 = local_848 + *(int *)local_83c[local_844];
        if (local_844 + 1U == local_840) {
LAB_000c2ce4:
          Sys_SplitPath(local_83c[local_844] + 8,0,local_a50,0,0);
          pcVar1 = (code *)CommatizeNumber(local_848 - local_850,local_38);
          puVar5 = local_a50;
          pcVar4 = "\tTotal Bytes used in \"%s\": %s\n";
          FS_FPrintf(local_84c,"\tTotal Bytes used in \"%s\": %s\n",puVar5,pcVar1);
          local_850 = local_848;
        }
        else {
          pcVar4 = (char *)(local_83c[local_844 + 1] + 8);
          iVar2 = ComparePath1(local_83c[local_844] + 8);
          if (iVar2 == 0) goto LAB_000c2ce4;
        }
      }
      uVar3 = CommatizeNumber(local_848,local_38,pcVar4,puVar5);
      FS_FPrintf(local_84c,"Total bytes in cache used by sound:  %s\n",uVar3,pcVar1);
      FS_Close(local_84c);
    }
  }
  return;
}


// Cache_Report  @ 000c2364
void Cache_Report(void)

{
  Con_DPrintf("%4.1f megabyte data cache\n",
              (double)((float)((hunk_size - hunk_high_used) - hunk_low_used) / 1048576.0));
  return;
}


// Cache_TotalUsed  @ 000c24c4
int Cache_TotalUsed(void)

{
  int local_c;
  int *local_8;
  
  local_c = 0;
  for (local_8 = (int *)cache_head._76_4_; local_8 != (int *)cache_head;
      local_8 = (int *)local_8[0x13]) {
    local_c = local_c + *local_8;
  }
  return local_c;
}


// Cache_TryAlloc  @ 000c1cb4
int * Cache_TryAlloc(int param_1,int param_2)

{
  int *local_c;
  int *local_8;
  
  if ((param_2 == 0) && ((undefined1 *)cache_head._72_4_ == cache_head)) {
    if ((hunk_size - hunk_high_used) - hunk_low_used < param_1) {
      Sys_Error("Cache_TryAlloc: %i is greater then free hunk",param_1);
    }
    local_c = (int *)(hunk_low_used + hunk_base);
    Q_memset(local_c,0,0x58);
    *local_c = param_1;
    cache_head._72_4_ = local_c;
    cache_head._76_4_ = local_c;
    local_c[0x13] = (int)cache_head;
    local_c[0x12] = (int)cache_head;
    Cache_MakeLRU(local_c);
  }
  else {
    local_c = (int *)(hunk_low_used + hunk_base);
    local_8 = (int *)cache_head._76_4_;
    do {
      if (((param_2 == 0) || (local_8 != (int *)cache_head._76_4_)) &&
         (param_1 <= (int)local_8 - (int)local_c)) {
        Q_memset(local_c,0,0x58);
        *local_c = param_1;
        local_c[0x13] = (int)local_8;
        local_c[0x12] = local_8[0x12];
        *(int **)(local_8[0x12] + 0x4c) = local_c;
        local_8[0x12] = (int)local_c;
        Cache_MakeLRU(local_c);
        return local_c;
      }
      local_c = (int *)(*local_8 + (int)local_8);
      local_8 = (int *)local_8[0x13];
    } while (local_8 != (int *)cache_head);
    if (((hunk_base + hunk_size) - hunk_high_used) - (int)local_c < param_1) {
      local_c = (int *)0x0;
    }
    else {
      Q_memset(local_c,0,0x58);
      *local_c = param_1;
      local_c[0x13] = (int)cache_head;
      local_c[0x12] = cache_head._72_4_;
      *(int **)(cache_head._72_4_ + 0x4c) = local_c;
      cache_head._72_4_ = local_c;
      Cache_MakeLRU(local_c);
    }
  }
  return local_c;
}


// Cache_UnlinkLRU  @ 000c1bc0
void Cache_UnlinkLRU(int param_1)

{
  if ((*(int *)(param_1 + 0x54) == 0) || (*(int *)(param_1 + 0x50) == 0)) {
    Sys_Error("Cache_UnlinkLRU: NULL link");
  }
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  return;
}


