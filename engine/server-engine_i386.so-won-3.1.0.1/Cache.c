// Cache_Alloc  @ 0008e890
void Cache_Alloc(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
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
  *param_1 = iVar1 + 0x58;
  *(int **)(iVar1 + 4) = param_1;
  Cache_Check(param_1);
  return;
}


// Cache_Check  @ 0008e854
int Cache_Check(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1 + -0x58;
    Cache_UnlinkLRU(iVar1);
    Cache_MakeLRU(iVar1);
    iVar1 = *param_1;
  }
  return iVar1;
}


// Cache_Compact  @ 0008e778
void Cache_Compact(void)

{
  return;
}


// Cache_Flush  @ 0008e29c
void Cache_Flush(void)

{
  while ((undefined1 *)cache_head._76_4_ != cache_head) {
    Cache_Free(*(undefined4 *)(cache_head._76_4_ + 4));
  }
  return;
}


// Cache_Free  @ 0008e7bc
void Cache_Free(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    Sys_Error("Cache_Free: not allocated");
    iVar1 = *param_1;
  }
  *(undefined4 *)(*(int *)(iVar1 + -0x10) + 0x4c) = *(undefined4 *)(iVar1 + -0xc);
  *(undefined4 *)(*(int *)(iVar1 + -0xc) + 0x48) = *(undefined4 *)(iVar1 + -0x10);
  *(undefined4 *)(iVar1 + -0x10) = 0;
  *(undefined4 *)(iVar1 + -0xc) = 0;
  *param_1 = 0;
  Cache_UnlinkLRU(iVar1 + -0x58);
  return;
}


// Cache_FreeHigh  @ 0008e018
void Cache_FreeHigh(int param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while ((iVar1 = cache_head._72_4_, (undefined1 *)cache_head._72_4_ != cache_head &&
         ((uint)((hunk_size + hunk_base) - param_1) <
          (uint)(cache_head._72_4_ + *(int *)cache_head._72_4_)))) {
    if (cache_head._72_4_ == local_8) {
      Cache_Free(*(undefined4 *)(cache_head._72_4_ + 4));
    }
    else {
      Cache_Move(cache_head._72_4_);
      local_8 = iVar1;
    }
  }
  return;
}


// Cache_FreeLow  @ 0008dfd0
void Cache_FreeLow(int param_1)

{
  while (((undefined1 *)cache_head._76_4_ != cache_head &&
         ((uint)cache_head._76_4_ < (uint)(param_1 + hunk_base)))) {
    Cache_Move(cache_head._76_4_);
  }
  return;
}


// Cache_Init  @ 0008e780
void Cache_Init(void)

{
  cache_head._72_4_ = cache_head;
  cache_head._76_4_ = cache_head;
  cache_head._80_4_ = cache_head;
  cache_head._84_4_ = cache_head;
  Cmd_AddCommand("flush",Cache_Flush);
  return;
}


// Cache_MakeLRU  @ 0008e0e4
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


// Cache_Move  @ 0008df48
void Cache_Move(int *param_1)

{
  int iVar1;
  
  iVar1 = Cache_TryAlloc(*param_1,1);
  if (iVar1 == 0) {
    Cache_Free(param_1[1]);
  }
  else {
    Q_memcpy(iVar1 + 0x58,param_1 + 0x16,*param_1 + -0x58);
    *(int *)(iVar1 + 4) = param_1[1];
    Q_memcpy(iVar1 + 8,param_1 + 2,0x40);
    Cache_Free(param_1[1]);
    **(int **)(iVar1 + 4) = iVar1 + 0x58;
  }
  return;
}


// Cache_Print  @ 0008e30c
void Cache_Print(void)

{
  int *piVar1;
  FILE *__stream;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint local_83c;
  undefined1 local_838 [52];
  undefined4 *local_804;
  int local_800 [511];
  
  local_83c = 0;
  __stream = fopen((char *)mem_dbgfile._4_4_,"a");
  if (__stream == (FILE *)0x0) {
    return;
  }
  Q_memset(&local_804,0x800,0);
  fprintf(__stream,"\nCACHE:\n");
  puVar4 = (undefined4 *)cache_head._76_4_;
  if ((undefined1 *)cache_head._76_4_ != cache_head) {
    do {
      (&local_804)[local_83c] = puVar4;
      local_83c = local_83c + 1;
      piVar1 = puVar4 + 0x13;
      puVar4 = (undefined4 *)*piVar1;
    } while ((undefined4 *)*piVar1 != (undefined4 *)cache_head);
  }
  qsort(&local_804,local_83c,4,CacheSystemCompare);
  iVar5 = 0;
  if (0 < (int)local_83c) {
    uVar2 = local_83c & 3;
    if (uVar2 != 0) {
      if (1 < uVar2) {
        if (2 < uVar2) {
          uVar3 = CommatizeNumber(*local_804,local_838,local_804 + 2);
          fprintf(__stream,"%16.16s : %-16s\n",uVar3);
        }
        puVar4 = (&local_804)[2 < uVar2];
        uVar3 = CommatizeNumber(*puVar4,local_838,puVar4 + 2);
        fprintf(__stream,"%16.16s : %-16s\n",uVar3);
        iVar5 = (2 < uVar2) + 1;
      }
      puVar4 = (&local_804)[iVar5];
      uVar3 = CommatizeNumber(*puVar4,local_838,puVar4 + 2);
      fprintf(__stream,"%16.16s : %-16s\n",uVar3);
      iVar5 = iVar5 + 1;
      if ((int)local_83c <= iVar5) goto LAB_0008e58e;
    }
    do {
      puVar4 = (&local_804)[iVar5];
      uVar3 = CommatizeNumber(*puVar4,local_838,puVar4 + 2);
      fprintf(__stream,"%16.16s : %-16s\n",uVar3);
      uVar3 = CommatizeNumber(*(undefined4 *)local_800[iVar5],local_838,
                              (undefined4 *)local_800[iVar5] + 2);
      fprintf(__stream,"%16.16s : %-16s\n",uVar3);
      uVar3 = CommatizeNumber(*(undefined4 *)local_800[iVar5 + 1],local_838,
                              (undefined4 *)local_800[iVar5 + 1] + 2);
      fprintf(__stream,"%16.16s : %-16s\n",uVar3);
      uVar3 = CommatizeNumber(*(undefined4 *)local_800[iVar5 + 2],local_838,
                              (undefined4 *)local_800[iVar5 + 2] + 2);
      fprintf(__stream,"%16.16s : %-16s\n",uVar3);
      iVar5 = iVar5 + 4;
    } while (iVar5 < (int)local_83c);
  }
LAB_0008e58e:
  fclose(__stream);
  return;
}


// Cache_Print_Models_And_Totals  @ 0008ea18
void Cache_Print_Models_And_Totals(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int *piVar3;
  FILE *__stream;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int *local_850;
  int local_840;
  size_t local_83c;
  int local_838 [512];
  undefined1 local_38 [52];
  
  local_83c = 0;
  local_840 = 0;
  __stream = fopen((char *)mem_dbgfile._4_4_,"a");
  if (__stream != (FILE *)0x0) {
    Q_memset(local_838,0x800,0);
    for (puVar1 = (undefined1 *)cache_head._76_4_; puVar1 != cache_head;
        puVar1 = *(undefined1 **)(puVar1 + 0x4c)) {
      iVar4 = Q_strstr(puVar1 + 8,&DAT_000ade1c);
      if (iVar4 != 0) {
        local_838[local_83c] = (int)puVar1;
        local_83c = local_83c + 1;
      }
    }
    qsort(local_838,local_83c,4,CacheSystemCompare);
    fprintf(__stream,"\nCACHED MODELS:\n");
    if (0 < (int)local_83c) {
      iVar4 = 0;
      local_850 = local_838;
      do {
        iVar7 = 0;
        uVar2 = *(uint *)(**(int **)(local_838[iVar4] + 4) + 0xb4);
        if (0 < (int)uVar2) {
          uVar5 = uVar2 & 3;
          if (uVar5 != 0) {
            if (1 < uVar5) {
              iVar7 = (2 < uVar5) + 1;
            }
            iVar7 = iVar7 + 1;
            if ((int)uVar2 <= iVar7) goto LAB_0008eb6b;
          }
          do {
            iVar7 = iVar7 + 4;
          } while (iVar7 < (int)uVar2);
        }
LAB_0008eb6b:
        uVar6 = CommatizeNumber(*(undefined4 *)*local_850,local_38,(undefined4 *)*local_850 + 2);
        fprintf(__stream,"\t%16.16s : %s\n",uVar6);
        iVar4 = iVar4 + 1;
        piVar3 = (int *)*local_850;
        local_850 = local_850 + 1;
        local_840 = local_840 + *piVar3;
      } while (iVar4 < (int)local_83c);
    }
    uVar6 = CommatizeNumber(local_840,local_38);
    fprintf(__stream,"Total bytes in cache used by models:  %s\n",uVar6);
    fclose(__stream);
  }
  return;
}


// Cache_Print_Sounds_And_Totals  @ 0008ec00
void Cache_Print_Sounds_And_Totals(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  FILE *__stream;
  int iVar4;
  undefined4 uVar5;
  size_t sVar6;
  size_t sVar7;
  int local_a48;
  int local_a40;
  size_t local_a3c;
  undefined1 local_a38 [512];
  int local_838 [512];
  undefined1 local_38 [52];
  
  local_a3c = 0;
  local_a40 = 0;
  __stream = fopen((char *)mem_dbgfile._4_4_,"a");
  local_a48 = 0;
  if (__stream != (FILE *)0x0) {
    Q_memset(local_838,0x800,0);
    for (puVar1 = (undefined1 *)cache_head._76_4_; puVar1 != cache_head;
        puVar1 = *(undefined1 **)(puVar1 + 0x4c)) {
      iVar4 = Q_strstr(puVar1 + 8,&DAT_000ade8a);
      if (iVar4 != 0) {
        local_838[local_a3c] = (int)puVar1;
        local_a3c = local_a3c + 1;
      }
    }
    qsort(local_838,local_a3c,4,CacheSystemCompare);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"\nCACHED SOUNDS:\n");
      if (0 < (int)local_a3c) {
        sVar6 = 0;
        do {
          puVar2 = (undefined4 *)local_838[sVar6];
          uVar5 = CommatizeNumber(*puVar2,local_38,puVar2 + 2);
          fprintf(__stream,"\t%16.16s : %s\n",uVar5);
          sVar7 = sVar6 + 1;
          piVar3 = (int *)local_838[sVar6];
          local_a40 = local_a40 + *piVar3;
          if ((sVar7 == local_a3c) ||
             (iVar4 = ComparePath1(piVar3 + 2,local_838[sVar7] + 8), iVar4 == 0)) {
            Sys_SplitPath(local_838[sVar6] + 8,0,local_a38,0,0);
            uVar5 = CommatizeNumber(local_a40 - local_a48,local_38);
            fprintf(__stream,"\tTotal Bytes used in \"%s\": %s\n",local_a38,uVar5);
            local_a48 = local_a40;
          }
          sVar6 = sVar7;
        } while ((int)sVar7 < (int)local_a3c);
      }
      uVar5 = CommatizeNumber(local_a40,local_38);
      fprintf(__stream,"Total bytes in cache used by sound:  %s\n",uVar5);
      fclose(__stream);
    }
  }
  return;
}


// Cache_Report  @ 0008e724
void Cache_Report(void)

{
  Con_DPrintf("%4.1f megabyte data cache\n",
              (double)((float)((hunk_size - hunk_high_used) - hunk_low_used) * 9.536743e-07));
  return;
}


// Cache_TotalUsed  @ 0008e824
int Cache_TotalUsed(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  for (piVar1 = (int *)cache_head._76_4_; piVar1 != (int *)cache_head; piVar1 = (int *)piVar1[0x13])
  {
    iVar2 = iVar2 + *piVar1;
  }
  return iVar2;
}


// Cache_TryAlloc  @ 0008e140
int * Cache_TryAlloc(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  if ((param_2 == 0) && ((undefined1 *)cache_head._72_4_ == cache_head)) {
    if ((hunk_size - hunk_high_used) - hunk_low_used < param_1) {
      Sys_Error("Cache_TryAlloc: %i is greater then free hunk",param_1);
    }
    piVar2 = (int *)(hunk_low_used + hunk_base);
    Q_memset(piVar2,0,0x58);
    *piVar2 = param_1;
    cache_head._72_4_ = piVar2;
    cache_head._76_4_ = piVar2;
    piVar2[0x13] = (int)cache_head;
    piVar2[0x12] = (int)cache_head;
  }
  else {
    piVar2 = (int *)(hunk_low_used + hunk_base);
    piVar3 = (int *)cache_head._76_4_;
    do {
      if (((param_2 == 0) || (piVar3 != (int *)cache_head._76_4_)) &&
         (param_1 <= (int)piVar3 - (int)piVar2)) {
        Q_memset(piVar2,0,0x58);
        *piVar2 = param_1;
        piVar2[0x13] = (int)piVar3;
        piVar2[0x12] = piVar3[0x12];
        *(int **)(piVar3[0x12] + 0x4c) = piVar2;
        piVar3[0x12] = (int)piVar2;
        goto LAB_0008e287;
      }
      piVar1 = piVar3 + 0x13;
      piVar2 = (int *)((int)piVar3 + *piVar3);
      piVar3 = (int *)*piVar1;
    } while ((int *)*piVar1 != (int *)cache_head);
    if (((hunk_size + hunk_base) - hunk_high_used) - (int)piVar2 < param_1) {
      return (int *)0x0;
    }
    Q_memset(piVar2,0,0x58);
    *piVar2 = param_1;
    piVar2[0x13] = (int)cache_head;
    piVar2[0x12] = cache_head._72_4_;
    *(int **)(cache_head._72_4_ + 0x4c) = piVar2;
    cache_head._72_4_ = piVar2;
  }
LAB_0008e287:
  Cache_MakeLRU(piVar2);
  return piVar2;
}


// Cache_UnlinkLRU  @ 0008e08c
void Cache_UnlinkLRU(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x54);
  if ((iVar2 == 0) || (iVar1 = *(int *)(param_1 + 0x50), iVar1 == 0)) {
    Sys_Error("Cache_UnlinkLRU: NULL link");
    iVar2 = *(int *)(param_1 + 0x54);
    iVar1 = *(int *)(param_1 + 0x50);
  }
  *(int *)(iVar2 + 0x50) = iVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  return;
}


