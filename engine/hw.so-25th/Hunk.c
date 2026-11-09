// Hunk_Alloc  @ 001188e0
void * Hunk_Alloc(int size)

{
  void *pvVar1;
  
  pvVar1 = Hunk_AllocName(size,"unknown");
  return pvVar1;
}


// Hunk_AllocName  @ 001187d0
void * Hunk_AllocName(int size,char *name)

{
  byte *dest;
  int iVar1;
  int count;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  if (size < 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Hunk_Alloc: bad size: %i",size);
  }
  count = (size + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < count) {
                    /* WARNING: Subroutine does not return */
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


// Hunk_Check  @ 00117ba0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Hunk_Check(void)

{
  int *piVar1;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  piVar1 = (int *)hunk_base;
  if (hunk_low_used != 0) {
    do {
      if (*piVar1 != 0x1df001ed) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Hunk_Check: trahsed sentinal");
      }
      if ((piVar1[1] < 0x10) ||
         (piVar1 = (int *)((int)piVar1 + piVar1[1]), hunk_size < (int)piVar1 - (int)hunk_base)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Hunk_Check: bad size");
      }
    } while (piVar1 != (int *)(hunk_base + hunk_low_used));
  }
  return;
}


// Hunk_FreeToHighMark  @ 00118440
void Hunk_FreeToHighMark(int mark)

{
  int iVar1;
  
  iVar1 = hunk_high_used;
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    if ((hunk_tempmark < 0) || (iVar1 = hunk_tempmark, hunk_high_used < hunk_tempmark)) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
    }
  }
  hunk_high_used = iVar1;
  if ((-1 < mark) && (mark <= hunk_high_used)) {
    hunk_high_used = mark;
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Hunk_FreeToHighMark: bad mark %i",mark);
}


// Hunk_FreeToLowMark  @ 00118410
void Hunk_FreeToLowMark(int mark)

{
  if ((-1 < mark) && (mark <= hunk_low_used)) {
    hunk_low_used = mark;
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Hunk_FreeToLowMark: bad mark %i",mark);
}


// Hunk_HighAllocName  @ 00118900
void * Hunk_HighAllocName(int size,char *name)

{
  int count;
  cache_user_t *pcVar1;
  void *pvVar2;
  cache_system_s *pcVar3;
  cache_system_s *pcVar4;
  int iVar5;
  byte *dest;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  if (size < 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Hunk_HighAllocName: bad size: %i",size);
  }
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    if (hunk_tempmark < 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
    }
    if (hunk_high_used < hunk_tempmark) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
    }
    hunk_tempactive = false;
    hunk_high_used = hunk_tempmark;
  }
  count = (size + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < count) {
    Con_Printf("Hunk_HighAlloc: failed on %i bytes\n",count);
    return (void *)0x0;
  }
                    /* Unresolved local var: cache_system_t * c@[???]
                       Unresolved local var: cache_system_t * prev@[???] */
  iVar5 = hunk_high_used + count;
  pcVar4 = (cache_system_s *)0x0;
  hunk_high_used = iVar5;
  while( true ) {
    while( true ) {
      pcVar3 = cache_head.prev;
      if ((cache_head.prev == &cache_head) ||
         ((cache_head.prev)->name + (cache_head.prev)->size + -8 <= hunk_base + (hunk_size - iVar5))
         ) {
        dest = hunk_base + (hunk_size - hunk_high_used);
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
      if (cache_head.prev == pcVar4) break;
      Cache_Move(cache_head.prev);
      pcVar4 = pcVar3;
    }
    pcVar1 = pcVar4->user;
                    /* Unresolved local var: cache_system_t * cs@[???] */
    pvVar2 = pcVar1->data;
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Cache_Free: not allocated");
    }
    *(undefined4 *)(*(int *)((int)pvVar2 + -0x10) + 0x4c) = *(undefined4 *)((int)pvVar2 + -0xc);
    *(undefined4 *)(*(int *)((int)pvVar2 + -0xc) + 0x48) = *(undefined4 *)((int)pvVar2 + -0x10);
    *(undefined4 *)((int)pvVar2 + -0x10) = 0;
    *(undefined4 *)((int)pvVar2 + -0xc) = 0;
    pcVar1->data = (void *)0x0;
    if ((*(int *)((int)pvVar2 + -4) == 0) || (*(int *)((int)pvVar2 + -8) == 0)) break;
    *(int *)(*(int *)((int)pvVar2 + -4) + 0x50) = *(int *)((int)pvVar2 + -8);
    *(undefined4 *)(*(int *)((int)pvVar2 + -8) + 0x54) = *(undefined4 *)((int)pvVar2 + -4);
    *(undefined4 *)((int)pvVar2 + -4) = 0;
    *(undefined4 *)((int)pvVar2 + -8) = 0;
    pcVar4 = pcVar3;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Cache_UnlinkLRU: NULL link");
}


// Hunk_HighMark  @ 001184d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Hunk_HighMark(void)

{
  if (hunk_tempactive == false) {
    return hunk_high_used;
  }
  hunk_tempactive = false;
  if ((-1 < hunk_tempmark) && (hunk_tempmark <= hunk_high_used)) {
    hunk_high_used = hunk_tempmark;
    return hunk_tempmark;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
}


// Hunk_LowMark  @ 00118400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Hunk_LowMark(void)

{
  return hunk_low_used;
}


// Hunk_Print  @ 00117c20
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
  int *piVar8;
  int in_GS_OFFSET;
  int *piVar9;
  int *piVar10;
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
  iVar5 = hunk_size;
  piVar8 = (int *)hunk_base;
  if (file == (FileHandle_t)0x0) {
LAB_00117dee:
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
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
    __snprintf_chk(local_c5,0x32,1,0x32,0x260a97,iVar5 % 1000,local_93);
  }
  iVar5 = Q_strlen(local_c5);
  if (iVar5 < 1) {
    if (iVar5 == 0) {
LAB_00117d96:
      Q_strcpy((char *)local_f7,"0");
      goto LAB_00117e36;
    }
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    cVar2 = local_c5[0];
    while ((cVar2 - 0x2cU & 0xfb) == 0) {
      iVar6 = iVar6 + 1;
      if (iVar5 == iVar6) goto LAB_00117d96;
      cVar2 = local_c5[iVar6];
    }
  }
  Q_strcpy((char *)local_f7,local_c5 + iVar6);
LAB_00117e36:
  local_10c = local_f7;
  piVar9 = local_10c;
  FS_FPrintf(file,"          :%16.16s total hunk size\n",local_10c);
  FS_FPrintf(file,"-------------------------\n");
  local_108 = 0;
  local_11c = 0;
LAB_00117eb8:
  piVar10 = piVar8;
  if (piVar8 == piVar3) {
    FS_FPrintf(file,"-------------------------\n",piVar9);
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
      __snprintf_chk(local_c5,0x32,1,0x32,0x260a97,iVar5 + (iVar7 - iVar6) * -1000,local_93);
      iVar5 = iVar7 - iVar6;
    }
    iVar5 = Q_strlen(local_c5);
    if (iVar5 < 1) {
      if (iVar5 != 0) {
        iVar6 = 0;
        goto LAB_00118380;
      }
LAB_00118362:
      Q_strcpy((char *)local_10c,"0");
    }
    else {
      iVar6 = 0;
      cVar2 = local_c5[0];
      while ((cVar2 - 0x2cU & 0xfb) == 0) {
        iVar6 = iVar6 + 1;
        if (iVar5 == iVar6) goto LAB_00118362;
        cVar2 = local_c5[iVar6];
      }
LAB_00118380:
      Q_strcpy((char *)local_10c,local_c5 + iVar6);
    }
    piVar9 = local_10c;
    FS_FPrintf(file,"          :%16.16s REMAINING\n",local_10c);
    FS_FPrintf(file,"-------------------------\n");
    piVar10 = piVar4;
  }
  if (piVar10 == piVar1) {
    FS_FPrintf(file,"-------------------------\n",piVar9);
    FS_FPrintf(file,"%8i total blocks\n",local_108);
    FS_Close(file);
    goto LAB_00117dee;
  }
  if (*piVar10 != 0x1df001ed) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Hunk_Check: trahsed sentinal");
  }
  iVar5 = piVar10[1];
  if ((iVar5 < 0x10) ||
     (piVar8 = (int *)((int)piVar10 + iVar5), hunk_size < (int)piVar8 - (int)hunk_base)) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Hunk_Check: bad size");
  }
  local_11c = local_11c + iVar5;
  s1 = piVar10 + 2;
  local_108 = local_108 + 1;
  Q_memcpy(local_61,s1,0x40);
  if (all == false) {
    if ((piVar1 != piVar8) && (piVar3 != piVar8)) goto code_r0x00117e90;
    goto LAB_00118070;
  }
  iVar5 = piVar10[1];
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
    __snprintf_chk(local_c5,0x32,1,0x32,0x260a97,iVar5 + (iVar7 - iVar6) * -1000,local_93);
    iVar5 = iVar7 - iVar6;
  }
  iVar5 = Q_strlen(local_c5);
  if (iVar5 < 1) {
    if (iVar5 != 0) {
      iVar6 = 0;
      goto LAB_00118190;
    }
LAB_0011804e:
    Q_strcpy((char *)local_10c,"0");
  }
  else {
    iVar6 = 0;
    cVar2 = local_c5[0];
    while ((cVar2 - 0x2cU & 0xfb) == 0) {
      iVar6 = iVar6 + 1;
      if (iVar5 == iVar6) goto LAB_0011804e;
      cVar2 = local_c5[iVar6];
    }
LAB_00118190:
    Q_strcpy((char *)local_10c,local_c5 + iVar6);
  }
  FS_FPrintf(file,"%8p :%16.16s %16s\n",piVar10,local_10c,local_61);
  if ((piVar1 != piVar8) && (piVar3 != piVar8)) {
    piVar10 = (int *)&DAT_00000040;
    iVar5 = Q_strncmp((char *)s1,(char *)(piVar8 + 2),0x40);
    piVar9 = piVar10;
    if (iVar5 == 0) goto LAB_00117eb8;
  }
  local_11c = 0;
  piVar9 = piVar10;
  goto LAB_00117eb8;
code_r0x00117e90:
  piVar9 = (int *)&DAT_00000040;
  iVar5 = Q_strncmp((char *)s1,(char *)(piVar8 + 2),0x40);
  if (iVar5 == 0) goto LAB_00117eb8;
LAB_00118070:
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
    __snprintf_chk(local_c5,0x32,1,0x32,0x260a97,local_11c + (iVar6 - iVar5) * -1000,local_93);
    local_11c = iVar6 - iVar5;
  }
  iVar5 = Q_strlen(local_c5);
  if (iVar5 < 1) {
    if (iVar5 == 0) {
LAB_0011816e:
      Q_strcpy((char *)local_10c,"0");
      goto LAB_00118212;
    }
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    cVar2 = local_c5[0];
    while ((cVar2 - 0x2cU & 0xfb) == 0) {
      iVar6 = iVar6 + 1;
      if (iVar5 == iVar6) goto LAB_0011816e;
      cVar2 = local_c5[iVar6];
    }
  }
  Q_strcpy((char *)local_10c,local_c5 + iVar6);
LAB_00118212:
  piVar9 = local_10c;
  FS_FPrintf(file,"          :%16.16s %16s (TOTAL)\n",local_10c,local_61);
  local_11c = 0;
  goto LAB_00117eb8;
}


// Hunk_TempAlloc  @ 00118b30
void * Hunk_TempAlloc(int size)

{
  void *pvVar1;
  
                    /* Unresolved local var: void * buf@[???] */
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    if (hunk_tempmark < 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
    }
    if (hunk_high_used < hunk_tempmark) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",hunk_tempmark);
    }
    hunk_tempactive = false;
    hunk_high_used = hunk_tempmark;
  }
  hunk_tempmark = hunk_high_used;
  pvVar1 = Hunk_HighAllocName(size + 0xfU & 0xfffffff0,"temp");
  hunk_tempactive = true;
  return pvVar1;
}


