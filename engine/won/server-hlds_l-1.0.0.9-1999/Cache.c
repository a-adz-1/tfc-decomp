// Cache_Alloc  @ 08087400
void Cache_Alloc(int *param_1,int param_2,char *param_3)

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
  strncpy((char *)(iVar1 + 8),param_3,0x3f);
  *param_1 = iVar1 + 0x58;
  *(int **)(iVar1 + 4) = param_1;
  Cache_Check(param_1);
  return;
}


// Cache_Check  @ 080873c0
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


// Cache_Compact  @ 080872f0
void Cache_Compact(void)

{
  return;
}


// Cache_Flush  @ 08087050
void Cache_Flush(void)

{
  while ((undefined1 *)cache_head._76_4_ != cache_head) {
    Cache_Free(*(undefined4 *)(cache_head._76_4_ + 4));
  }
  return;
}


// Cache_Free  @ 08087330
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


// Cache_FreeHigh  @ 08086df0
void Cache_FreeHigh(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  while ((uVar1 = cache_head._72_4_, (undefined1 *)cache_head._72_4_ != cache_head &&
         ((uint)((hunk_size + hunk_base) - param_1) <
          (uint)(cache_head._72_4_ + *(int *)cache_head._72_4_)))) {
    if (cache_head._72_4_ == iVar2) {
      Cache_Free(*(undefined4 *)(cache_head._72_4_ + 4));
    }
    else {
      Cache_Move(cache_head._72_4_);
      iVar2 = uVar1;
    }
  }
  return;
}


// Cache_FreeLow  @ 08086db0
void Cache_FreeLow(int param_1)

{
  while (((undefined1 *)cache_head._76_4_ != cache_head &&
         ((uint)cache_head._76_4_ < (uint)(param_1 + hunk_base)))) {
    Cache_Move(cache_head._76_4_);
  }
  return;
}


// Cache_Init  @ 08087300
void Cache_Init(void)

{
  cache_head._72_4_ = cache_head;
  cache_head._76_4_ = cache_head;
  cache_head._80_4_ = cache_head;
  cache_head._84_4_ = cache_head;
  Cmd_AddCommand("flush",Cache_Flush);
  return;
}


// Cache_MakeLRU  @ 08086eb0
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


// Cache_Move  @ 08086d30
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


// Cache_Print  @ 080870b0
void Cache_Print(void)

{
  FILE *__stream;
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  size_t __nmemb;
  undefined1 local_838 [52];
  int local_804 [512];
  
  __nmemb = 0;
  __stream = fopen((char *)mem_dbgfile._4_4_,"a");
  if (__stream != (FILE *)0x0) {
    memset(local_804,0x800,0);
    fprintf(__stream,"\nCACHE:\n");
    if ((undefined1 *)cache_head._76_4_ != cache_head) {
      __nmemb = 0;
      puVar1 = (undefined1 *)cache_head._76_4_;
      do {
        local_804[__nmemb] = (int)puVar1;
        __nmemb = __nmemb + 1;
        puVar1 = *(undefined1 **)(puVar1 + 0x4c);
      } while (puVar1 != cache_head);
    }
    qsort(local_804,__nmemb,4,CacheSystemCompare);
    iVar3 = 0;
    if (0 < (int)__nmemb) {
      do {
        uVar2 = CommatizeNumber(*(undefined4 *)local_804[iVar3],local_838,
                                (undefined4 *)local_804[iVar3] + 2);
        fprintf(__stream,"%16.16s : %-16s\n",uVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)__nmemb);
    }
    fclose(__stream);
  }
  return;
}


// Cache_Print_Models_And_Totals  @ 08087550
void Cache_Print_Models_And_Totals(void)

{
  int *piVar1;
  FILE *__stream;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int local_840;
  size_t local_83c;
  int local_838 [512];
  undefined1 local_38 [52];
  
  local_83c = 0;
  local_840 = 0;
  __stream = fopen((char *)mem_dbgfile._4_4_,"a");
  if (__stream != (FILE *)0x0) {
    memset(local_838,0x800,0);
    puVar5 = (undefined1 *)cache_head._76_4_;
    if ((undefined1 *)cache_head._76_4_ != cache_head) {
      do {
        pcVar2 = strstr(puVar5 + 8,".mdl");
        if (pcVar2 != (char *)0x0) {
          local_838[local_83c] = (int)puVar5;
          local_83c = local_83c + 1;
        }
        piVar1 = (int *)(puVar5 + 0x4c);
        puVar5 = (undefined1 *)*piVar1;
      } while ((undefined1 *)*piVar1 != cache_head);
    }
    qsort(local_838,local_83c,4,CacheSystemCompare);
    fprintf(__stream,"\nCACHED MODELS:\n");
    if (0 < (int)local_83c) {
      iVar6 = 0;
      do {
        iVar4 = 0;
        if (0 < *(int *)(**(int **)(local_838[iVar6] + 4) + 0xb4)) {
          do {
            iVar4 = iVar4 + 1;
          } while (iVar4 < *(int *)(**(int **)(local_838[iVar6] + 4) + 0xb4));
        }
        uVar3 = CommatizeNumber(*(undefined4 *)local_838[iVar6],local_38,
                                (undefined4 *)local_838[iVar6] + 2);
        fprintf(__stream,"\t%16.16s : %s\n",uVar3);
        local_840 = local_840 + *(int *)local_838[iVar6];
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)local_83c);
    }
    uVar3 = CommatizeNumber(local_840,local_38);
    fprintf(__stream,"Total bytes in cache used by models:  %s\n",uVar3);
    fclose(__stream);
  }
  return;
}


// Cache_Print_Sounds_And_Totals  @ 080876d0
void Cache_Print_Sounds_And_Totals(void)

{
  int *piVar1;
  FILE *__stream;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
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
    memset(local_838,0x800,0);
    puVar5 = (undefined1 *)cache_head._76_4_;
    if ((undefined1 *)cache_head._76_4_ != cache_head) {
      do {
        pcVar2 = strstr(puVar5 + 8,".wav");
        if (pcVar2 != (char *)0x0) {
          local_838[local_a3c] = (int)puVar5;
          local_a3c = local_a3c + 1;
        }
        piVar1 = (int *)(puVar5 + 0x4c);
        puVar5 = (undefined1 *)*piVar1;
      } while ((undefined1 *)*piVar1 != cache_head);
    }
    qsort(local_838,local_a3c,4,CacheSystemCompare);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"\nCACHED SOUNDS:\n");
      if (0 < (int)local_a3c) {
        iVar6 = 0;
        do {
          uVar3 = CommatizeNumber(*(undefined4 *)local_838[iVar6],local_38,
                                  (undefined4 *)local_838[iVar6] + 2);
          fprintf(__stream,"\t%16.16s : %s\n",uVar3);
          local_a40 = local_a40 + *(int *)local_838[iVar6];
          if ((iVar6 + 1U == local_a3c) ||
             (iVar4 = ComparePath1((int *)local_838[iVar6] + 2,local_838[iVar6 + 1U] + 8),
             iVar4 == 0)) {
            gcc2_compiled_(local_838[iVar6] + 8,0,local_a38,0,0);
            uVar3 = CommatizeNumber(local_a40 - local_a48,local_38);
            fprintf(__stream,"\tTotal Bytes used in \"%s\": %s\n",local_a38,uVar3);
            local_a48 = local_a40;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)local_a3c);
      }
      uVar3 = CommatizeNumber(local_a40,local_38);
      fprintf(__stream,"Total bytes in cache used by sound:  %s\n",uVar3);
      fclose(__stream);
    }
  }
  return;
}


// Cache_Report  @ 080872b0
void Cache_Report(void)

{
  Con_DPrintf("%4.1f megabyte data cache\n",
              (double)((float)((hunk_size - hunk_high_used) - hunk_low_used) * 9.536743e-07));
  return;
}


// Cache_TotalUsed  @ 08087390
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


// Cache_TryAlloc  @ 08086f00
int * Cache_TryAlloc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if ((param_2 == 0) && ((undefined1 *)cache_head._72_4_ == cache_head)) {
    if ((hunk_size - hunk_high_used) - hunk_low_used < param_1) {
      Sys_Error("Cache_TryAlloc: %i is greater then free hunk",param_1);
    }
    piVar3 = (int *)(hunk_base + hunk_low_used);
    piVar2 = piVar3;
    for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
    *piVar3 = param_1;
    cache_head._72_4_ = piVar3;
    cache_head._76_4_ = piVar3;
    piVar3[0x13] = (int)cache_head;
    piVar3[0x12] = (int)cache_head;
  }
  else {
    piVar3 = (int *)(hunk_base + hunk_low_used);
    piVar2 = (int *)cache_head._76_4_;
    do {
      if (((param_2 == 0) || (piVar2 != (int *)cache_head._76_4_)) &&
         (param_1 <= (int)piVar2 - (int)piVar3)) {
        piVar4 = piVar3;
        for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
          *piVar4 = 0;
          piVar4 = piVar4 + 1;
        }
        *piVar3 = param_1;
        piVar3[0x13] = (int)piVar2;
        piVar3[0x12] = piVar2[0x12];
        *(int **)(piVar2[0x12] + 0x4c) = piVar3;
        piVar2[0x12] = (int)piVar3;
        goto LAB_0808703b;
      }
      piVar3 = (int *)((int)piVar2 + *piVar2);
      piVar2 = (int *)piVar2[0x13];
    } while (piVar2 != (int *)cache_head);
    if (((hunk_size + hunk_base) - hunk_high_used) - (int)piVar3 < param_1) {
      return (int *)0x0;
    }
    piVar2 = piVar3;
    for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
    *piVar3 = param_1;
    piVar3[0x13] = (int)cache_head;
    piVar3[0x12] = cache_head._72_4_;
    *(int **)(cache_head._72_4_ + 0x4c) = piVar3;
    cache_head._72_4_ = piVar3;
  }
LAB_0808703b:
  Cache_MakeLRU(piVar3);
  return piVar3;
}


// Cache_UnlinkLRU  @ 08086e60
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


