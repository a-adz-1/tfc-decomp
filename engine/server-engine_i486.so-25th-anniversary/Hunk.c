// Hunk_Alloc  @ 000ad520
void * Hunk_Alloc(int size)

{
  void *pvVar1;
  
  pvVar1 = Hunk_AllocName(size,"unknown");
  return pvVar1;
}


// Hunk_AllocName  @ 000ad410
void * Hunk_AllocName(int size,char *name)

{
  byte *dest;
  int iVar1;
  int count;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  if (size < 0) {
    Sys_Error("Hunk_Alloc: bad size: %i",size);
  }
  count = (size + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < count) {
    Sys_Error("Hunk_Alloc: failed on %i bytes",count);
  }
                    /* Unresolved local var: cache_system_t * c@[???] */
  dest = hunk_base + hunk_low_used;
  iVar1 = hunk_low_used + count;
  hunk_low_used = iVar1;
  if ((cache_head.next != &cache_head) && (cache_head.next < (cache_system_s *)(hunk_base + iVar1)))
  {
    do {
      Cache_Move(cache_head.next);
      if (cache_head.next == &cache_head) break;
    } while (cache_head.next < (cache_system_s *)(hunk_base + iVar1));
  }
  Q_memset(dest,0,count);
  *(int *)(dest + 4) = count;
  dest[0] = 0xed;
  dest[1] = '\x01';
  dest[2] = 0xf0;
  dest[3] = '\x1d';
  Q_strncpy((char *)(dest + 8),name,0x40);
  dest[0x47] = '\0';
  return dest + 0x48;
}


// Hunk_Check  @ 000ac7e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Hunk_Check(void)

{
  int *piVar1;
  int *piVar2;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  piVar2 = (int *)hunk_base;
  if (hunk_low_used != 0) {
    do {
      while( true ) {
        if (*piVar2 != 0x1df001ed) {
          Sys_Error("Hunk_Check: trahsed sentinal");
        }
        if ((0xf < piVar2[1]) &&
           (piVar1 = (int *)((int)piVar2 + piVar2[1]), (int)piVar1 - (int)hunk_base <= hunk_size))
        break;
        Sys_Error("Hunk_Check: bad size");
        piVar2 = (int *)((int)piVar2 + piVar2[1]);
        if (piVar2 == (int *)(hunk_base + hunk_low_used)) {
          return;
        }
      }
      piVar2 = piVar1;
    } while (piVar1 != (int *)(hunk_base + hunk_low_used));
  }
  return;
}


// Hunk_FreeToHighMark  @ 000ad080
void Hunk_FreeToHighMark(int mark)

{
  int iVar1;
  
  iVar1 = hunk_high_used;
  if (hunk_tempactive != false) {
    iVar1 = hunk_tempmark;
    hunk_tempactive = false;
    if ((hunk_tempmark < 0) || (hunk_high_used < hunk_tempmark)) {
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
    }
  }
  hunk_high_used = iVar1;
  if ((mark < 0) || (hunk_high_used < mark)) {
    Sys_Error("Hunk_FreeToHighMark: bad mark %i",mark);
  }
  hunk_high_used = mark;
  return;
}


// Hunk_FreeToLowMark  @ 000ad050
void Hunk_FreeToLowMark(int mark)

{
  if ((mark < 0) || (hunk_low_used < mark)) {
    Sys_Error("Hunk_FreeToLowMark: bad mark %i",mark);
  }
  hunk_low_used = mark;
  return;
}


// Hunk_HighAllocName  @ 000ad540
void * Hunk_HighAllocName(int size,char *name)

{
  cache_user_t *pcVar1;
  cache_system_s *pcVar2;
  int iVar3;
  cache_system_s *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  byte *dest;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  if (size < 0) {
    Sys_Error("Hunk_HighAllocName: bad size: %i",size);
  }
  iVar7 = hunk_tempmark;
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    if (hunk_tempmark < 0) {
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
      hunk_high_used = iVar7;
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",iVar7);
      hunk_high_used = iVar7;
      hunk_tempactive = false;
    }
    else {
      if (hunk_high_used < hunk_tempmark) {
        Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
      }
      hunk_tempactive = false;
      hunk_high_used = iVar7;
    }
  }
  iVar7 = (size + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < iVar7) {
    Con_Printf("Hunk_HighAlloc: failed on %i bytes\n",iVar7);
    return (void *)0x0;
  }
                    /* Unresolved local var: cache_system_t * c@[???]
                       Unresolved local var: cache_system_t * prev@[???] */
  iVar6 = hunk_high_used + iVar7;
  pcVar4 = (cache_system_s *)0x0;
  hunk_high_used = iVar6;
  while ((pcVar2 = cache_head.prev, cache_head.prev != &cache_head &&
         (hunk_base + (hunk_size - iVar6) < (cache_head.prev)->name + (cache_head.prev)->size + -8))
        ) {
    if (cache_head.prev == pcVar4) {
      pcVar1 = pcVar4->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
      pvVar8 = pcVar1->data;
      if (pvVar8 == (void *)0x0) {
        Sys_Error("Cache_Free: not allocated");
        pvVar8 = pcVar1->data;
      }
      *(undefined4 *)(*(int *)((int)pvVar8 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar8 + -0xc);
      *(undefined4 *)(*(int *)((int)pvVar8 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar8 + -0x10);
      *(undefined4 *)((int)pvVar8 + -0x10) = 0;
      *(undefined4 *)((int)pvVar8 + -0xc) = 0;
      pcVar1->data = (void *)0x0;
      iVar3 = *(int *)((int)pvVar8 + -4);
      if ((iVar3 == 0) || (iVar5 = *(int *)((int)pvVar8 + -8), iVar5 == 0)) {
        Sys_Error("Cache_UnlinkLRU: NULL link");
        iVar3 = *(int *)((int)pvVar8 + -4);
        iVar5 = *(int *)((int)pvVar8 + -8);
      }
      *(int *)(iVar3 + 0x50) = iVar5;
      *(undefined4 *)(*(int *)((int)pvVar8 + -8) + 0x54) = *(undefined4 *)((int)pvVar8 + -4);
      *(undefined4 *)((int)pvVar8 + -4) = 0;
      *(undefined4 *)((int)pvVar8 + -8) = 0;
      pcVar4 = pcVar2;
    }
    else {
      Cache_Move(cache_head.prev);
      pcVar4 = pcVar2;
    }
  }
  dest = hunk_base + (hunk_size - hunk_high_used);
  Q_memset(dest,0,iVar7);
  *(int *)(dest + 4) = iVar7;
  dest[0] = 0xed;
  dest[1] = '\x01';
  dest[2] = 0xf0;
  dest[3] = '\x1d';
  Q_strncpy((char *)(dest + 8),name,0x40);
  dest[0x47] = '\0';
  return dest + 0x48;
}


// Hunk_HighMark  @ 000ad110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Hunk_HighMark(void)

{
  int iVar1;
  
  iVar1 = hunk_tempmark;
  if (hunk_tempactive == false) {
    return hunk_high_used;
  }
  hunk_tempactive = false;
  if ((hunk_tempmark < 0) || (hunk_high_used < hunk_tempmark)) {
    Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
  }
  hunk_high_used = iVar1;
  return iVar1;
}


// Hunk_LowMark  @ 000ad040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Hunk_LowMark(void)

{
  return hunk_low_used;
}


// Hunk_Print  @ 000ac860
void Hunk_Print(qboolean all)

{
  int *s1;
  int *piVar1;
  char cVar2;
  FileHandle_t file;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  int *piVar8;
  int *piVar9;
  int *local_120;
  int local_11c;
  int *local_10c;
  int local_108;
  int local_f7 [12];
  char local_c5 [50];
  char local_93 [49];
  undefined1 local_62;
  undefined1 local_61 [64];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: hunk_t * h@[???]
                       Unresolved local var: hunk_t * next@[???]
                       Unresolved local var: hunk_t * endlow@[???]
                       Unresolved local var: hunk_t * starthigh@[???]
                       Unresolved local var: hunk_t * endhigh@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int sum@[???]
                       Unresolved local var: int totalblocks@[???]
                       Unresolved local var: char[65] name@[???]
                       Unresolved local var: FILE * file@[???]
                       Unresolved local var: char[50] commabuf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_21 = 0;
  file = FS_Open(mem_dbgfile.string,"a");
  local_120 = (int *)hunk_base;
  iVar5 = hunk_size;
  if (file == (FileHandle_t)0x0) goto LAB_000aca2e;
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
  piVar3 = (int *)(hunk_base + hunk_low_used);
  piVar4 = (int *)(hunk_base + (hunk_size - hunk_high_used));
  piVar1 = (int *)(hunk_base + hunk_size);
  Q_memset(local_c5,0,0x32);
  for (; iVar5 != 0; iVar5 = iVar5 / 1000) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
    Q_strncpy(local_93,local_c5,0x31);
    local_62 = 0;
    __snprintf_chk(local_c5,0x32,1,0x32,",%03i%s",iVar5 % 1000,local_93);
  }
  iVar5 = Q_strlen(local_c5);
  if (iVar5 < 1) {
    if (iVar5 != 0) {
      iVar6 = 0;
      goto LAB_000aca60;
    }
LAB_000ac9d6:
    Q_strcpy((char *)local_f7,"0");
  }
  else {
    iVar6 = 0;
    cVar2 = local_c5[0];
    while ((cVar2 - 0x2cU & 0xfb) == 0) {
      iVar6 = iVar6 + 1;
      if (iVar5 == iVar6) goto LAB_000ac9d6;
      cVar2 = local_c5[iVar6];
    }
LAB_000aca60:
    Q_strcpy((char *)local_f7,local_c5 + iVar6);
  }
  local_10c = local_f7;
  piVar8 = local_10c;
  FS_FPrintf(file,"          :%16.16s total hunk size\n",local_10c);
  FS_FPrintf(file,"-------------------------\n");
  local_108 = 0;
  local_11c = 0;
LAB_000acaf8:
  piVar9 = local_120;
  if (local_120 == piVar3) {
    FS_FPrintf(file,"-------------------------\n",piVar8);
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
    iVar5 = (hunk_size - hunk_low_used) - hunk_high_used;
    Q_memset(local_c5,0,0x32);
    while (iVar5 != 0) {
      iVar6 = iVar5 >> 0x1f;
      iVar7 = iVar5 / 1000 + iVar6;
      Q_strncpy(local_93,local_c5,0x31);
      local_62 = 0;
      __snprintf_chk(local_c5,0x32,1,0x32,",%03i%s",iVar5 + (iVar7 - iVar6) * -1000,local_93);
      iVar5 = iVar7 - iVar6;
    }
    iVar5 = Q_strlen(local_c5);
    if (iVar5 < 1) {
      if (iVar5 != 0) {
        iVar6 = 0;
        goto LAB_000acfc0;
      }
LAB_000acfa2:
      Q_strcpy((char *)local_10c,"0");
    }
    else {
      iVar6 = 0;
      cVar2 = local_c5[0];
      while ((cVar2 - 0x2cU & 0xfb) == 0) {
        iVar6 = iVar6 + 1;
        if (iVar5 == iVar6) goto LAB_000acfa2;
        cVar2 = local_c5[iVar6];
      }
LAB_000acfc0:
      Q_strcpy((char *)local_10c,local_c5 + iVar6);
    }
    piVar8 = local_10c;
    FS_FPrintf(file,"          :%16.16s REMAINING\n",local_10c);
    FS_FPrintf(file,"-------------------------\n");
    piVar9 = piVar4;
  }
  if (piVar9 != piVar1) {
    if (*piVar9 != 0x1df001ed) {
      Sys_Error("Hunk_Check: trahsed sentinal");
    }
    iVar5 = piVar9[1];
    if ((iVar5 < 0x10) ||
       (local_120 = (int *)((int)piVar9 + iVar5), hunk_size < (int)local_120 - (int)hunk_base)) {
      Sys_Error("Hunk_Check: bad size");
      iVar5 = piVar9[1];
      local_120 = (int *)((int)piVar9 + iVar5);
    }
    local_11c = local_11c + iVar5;
    s1 = piVar9 + 2;
    local_108 = local_108 + 1;
    Q_memcpy(local_61,s1,0x40);
    if (all == false) {
      if ((piVar1 != local_120) && (piVar3 != local_120)) goto code_r0x000acad0;
      goto LAB_000accb0;
    }
    iVar5 = piVar9[1];
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
    Q_memset(local_c5,0,0x32);
    while (iVar5 != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
      iVar6 = iVar5 >> 0x1f;
      iVar7 = iVar5 / 1000 + iVar6;
      Q_strncpy(local_93,local_c5,0x31);
      local_62 = 0;
      __snprintf_chk(local_c5,0x32,1,0x32,",%03i%s",iVar5 + (iVar7 - iVar6) * -1000,local_93);
      iVar5 = iVar7 - iVar6;
    }
    iVar5 = Q_strlen(local_c5);
    if (iVar5 < 1) {
      if (iVar5 != 0) {
        iVar6 = 0;
        goto LAB_000acdd0;
      }
LAB_000acc8e:
      Q_strcpy((char *)local_10c,"0");
    }
    else {
      iVar6 = 0;
      cVar2 = local_c5[0];
      while ((cVar2 - 0x2cU & 0xfb) == 0) {
        iVar6 = iVar6 + 1;
        if (iVar5 == iVar6) goto LAB_000acc8e;
        cVar2 = local_c5[iVar6];
      }
LAB_000acdd0:
      Q_strcpy((char *)local_10c,local_c5 + iVar6);
    }
    FS_FPrintf(file,"%8p :%16.16s %16s\n",piVar9,local_10c,local_61);
    if ((piVar1 != local_120) && (piVar3 != local_120)) {
      piVar9 = (int *)&DAT_00000040;
      iVar5 = Q_strncmp((char *)s1,(char *)(local_120 + 2),0x40);
      piVar8 = piVar9;
      if (iVar5 == 0) goto LAB_000acaf8;
    }
    local_11c = 0;
    piVar8 = piVar9;
    goto LAB_000acaf8;
  }
  FS_FPrintf(file,"-------------------------\n",piVar8);
  FS_FPrintf(file,"%8i total blocks\n",local_108);
  FS_Close(file);
LAB_000aca2e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x000acad0:
  piVar8 = (int *)&DAT_00000040;
  iVar5 = Q_strncmp((char *)s1,(char *)(local_120 + 2),0x40);
  if (iVar5 == 0) goto LAB_000acaf8;
LAB_000accb0:
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
  Q_memset(local_c5,0,0x32);
  while (local_11c != 0) {
    iVar5 = local_11c >> 0x1f;
    iVar6 = local_11c / 1000 + iVar5;
    Q_strncpy(local_93,local_c5,0x31);
    local_62 = 0;
    __snprintf_chk(local_c5,0x32,1,0x32,",%03i%s",local_11c + (iVar6 - iVar5) * -1000,local_93);
    local_11c = iVar6 - iVar5;
  }
  iVar5 = Q_strlen(local_c5);
  if (iVar5 < 1) {
    if (iVar5 == 0) {
LAB_000acdae:
      Q_strcpy((char *)local_10c,"0");
      goto LAB_000ace52;
    }
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    cVar2 = local_c5[0];
    while ((cVar2 - 0x2cU & 0xfb) == 0) {
      iVar6 = iVar6 + 1;
      if (iVar5 == iVar6) goto LAB_000acdae;
      cVar2 = local_c5[iVar6];
    }
  }
  Q_strcpy((char *)local_10c,local_c5 + iVar6);
LAB_000ace52:
  piVar8 = local_10c;
  FS_FPrintf(file,"          :%16.16s %16s (TOTAL)\n",local_10c,local_61);
  local_11c = 0;
  goto LAB_000acaf8;
}


// Hunk_TempAlloc  @ 000ad770
void * Hunk_TempAlloc(int size)

{
  void *pvVar1;
  int iVar2;
  
                    /* Unresolved local var: void * buf@[???] */
  iVar2 = hunk_tempmark;
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    if (hunk_tempmark < 0) {
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
      hunk_high_used = iVar2;
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",iVar2);
      hunk_high_used = iVar2;
      hunk_tempactive = false;
    }
    else {
      if (hunk_high_used < hunk_tempmark) {
        Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
      }
      hunk_tempactive = false;
      hunk_high_used = iVar2;
    }
  }
  hunk_tempmark = hunk_high_used;
  pvVar1 = Hunk_HighAllocName(size + 0xfU & 0xfffffff0,"temp");
  hunk_tempactive = true;
  return pvVar1;
}


