// Hunk_Alloc  @ 000c2da0
void * Hunk_Alloc(int size)

{
  void *pvVar1;
  
  pvVar1 = Hunk_AllocName(size,"unknown");
  return pvVar1;
}


// Hunk_AllocName  @ 000c2ce0
void * Hunk_AllocName(int size,char *name)

{
  byte *dest;
  int count;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  if (size < 0) {
    Sys_Error("Hunk_Alloc: bad size: %i",size);
  }
  count = (size + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < count) {
    Sys_Error("Hunk_Alloc: failed on %i bytes",count);
  }
  dest = hunk_base + hunk_low_used;
  hunk_low_used = hunk_low_used + count;
  Cache_FreeLow(hunk_low_used);
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


// Hunk_Check  @ 000c1f60
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


// Hunk_FreeToHighMark  @ 000c2030
void Hunk_FreeToHighMark(int mark)

{
  int iVar1;
  
  iVar1 = hunk_high_used;
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    iVar1 = hunk_tempmark;
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


// Hunk_FreeToLowMark  @ 000c2000
void Hunk_FreeToLowMark(int mark)

{
  if ((mark < 0) || (hunk_low_used < mark)) {
    Sys_Error("Hunk_FreeToLowMark: bad mark %i",mark);
  }
  hunk_low_used = mark;
  return;
}


// Hunk_HighAllocName  @ 000c2840
void * Hunk_HighAllocName(int size,char *name)

{
  byte *dest;
  int iVar1;
  
                    /* Unresolved local var: hunk_t * h@[???] */
  if (size < 0) {
    Sys_Error("Hunk_HighAllocName: bad size: %i",size);
  }
  iVar1 = hunk_tempmark;
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    Hunk_FreeToHighMark(hunk_tempmark);
    if ((iVar1 < 0) || (hunk_high_used < iVar1)) {
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",iVar1);
    }
    hunk_tempactive = false;
    hunk_high_used = iVar1;
  }
  iVar1 = (size + 0xfU & 0xfffffff0) + 0x48;
  if (iVar1 <= (hunk_size - hunk_low_used) - hunk_high_used) {
    hunk_high_used = hunk_high_used + iVar1;
    Cache_FreeHigh(hunk_high_used);
    dest = hunk_base + (hunk_size - hunk_high_used);
    Q_memset(dest,0,iVar1);
    *(int *)(dest + 4) = iVar1;
    dest[0] = 0xed;
    dest[1] = '\x01';
    dest[2] = 0xf0;
    dest[3] = '\x1d';
    Q_strncpy((char *)(dest + 8),name,0x40);
    dest[0x47] = '\0';
    return dest + 0x48;
  }
  Con_Printf("Hunk_HighAlloc: failed on %i bytes\n",iVar1);
  return (void *)0x0;
}


// Hunk_HighMark  @ 000c20c0
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


// Hunk_LowMark  @ 000c1ff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Hunk_LowMark(void)

{
  return hunk_low_used;
}


// Hunk_Print  @ 000c3130
void Hunk_Print(qboolean all)

{
  int *s1;
  int *piVar1;
  FileHandle_t file;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int num;
  int local_b0;
  undefined1 local_8f [64];
  undefined1 local_4f;
  char local_4e [62];
  
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
  local_4f = 0;
  file = FS_Open(mem_dbgfile.string,"a");
  piVar7 = (int *)hunk_base;
  if (file != (FileHandle_t)0x0) {
    piVar5 = (int *)(hunk_base + hunk_low_used);
    piVar6 = (int *)(hunk_base + (hunk_size - hunk_high_used));
    piVar1 = (int *)(hunk_base + hunk_size);
    piVar2 = (int *)CommatizeNumber(hunk_size,local_4e);
    FS_FPrintf(file,"          :%16.16s total hunk size\n",piVar2);
    num = 0;
    FS_FPrintf(file,"-------------------------\n");
    local_b0 = 0;
    if (piVar7 == piVar5) goto LAB_000c3295;
    num = 0;
LAB_000c31f0:
    piVar8 = piVar7;
    if (piVar7 != piVar1) {
      do {
        if (*piVar8 != 0x1df001ed) {
          Sys_Error("Hunk_Check: trahsed sentinal");
        }
        iVar3 = piVar8[1];
        if ((iVar3 < 0x10) ||
           (piVar7 = (int *)((int)piVar8 + iVar3), hunk_size < (int)piVar7 - (int)hunk_base)) {
          Sys_Error("Hunk_Check: bad size");
          iVar3 = piVar8[1];
          piVar7 = (int *)((int)piVar8 + iVar3);
        }
        num = num + iVar3;
        s1 = piVar8 + 2;
        local_b0 = local_b0 + 1;
        piVar2 = (int *)0x40;
        Q_memcpy(local_8f,s1,0x40);
        if (all != false) {
          pcVar4 = CommatizeNumber(piVar8[1],local_4e);
          FS_FPrintf(file,"%8p :%16.16s %16s\n",piVar8,pcVar4,local_8f);
          piVar2 = piVar8;
        }
        if ((piVar1 == piVar7) || (piVar5 == piVar7)) {
          if (all != false) goto LAB_000c3287;
LAB_000c33a0:
          piVar2 = (int *)CommatizeNumber(num,local_4e);
          FS_FPrintf(file,"          :%16.16s %16s (TOTAL)\n",piVar2,local_8f);
          num = 0;
        }
        else {
          piVar2 = (int *)0x40;
          iVar3 = Q_strncmp((char *)s1,(char *)(piVar7 + 2),0x40);
          if (iVar3 != 0) {
            if (all == false) goto LAB_000c33a0;
LAB_000c3287:
            num = 0;
          }
        }
        if (piVar7 != piVar5) goto LAB_000c31f0;
LAB_000c3295:
        FS_FPrintf(file,"-------------------------\n",piVar2);
        piVar2 = (int *)CommatizeNumber((hunk_size - hunk_low_used) - hunk_high_used,local_4e);
        FS_FPrintf(file,"          :%16.16s REMAINING\n",piVar2);
        FS_FPrintf(file,"-------------------------\n");
        piVar8 = piVar6;
        if (piVar6 == piVar1) break;
      } while( true );
    }
    FS_FPrintf(file,"-------------------------\n",piVar2);
    FS_FPrintf(file,"%8i total blocks\n",local_b0);
    FS_Close(file);
  }
  return;
}


// Hunk_TempAlloc  @ 000c2970
void * Hunk_TempAlloc(int size)

{
  byte *pbVar1;
  byte *dest;
  uint uVar2;
  int iVar3;
  
                    /* Unresolved local var: void * buf@[DW_OP_reg0(EAX)] */
  iVar3 = hunk_tempmark;
  uVar2 = size + 0xfU & 0xfffffff0;
  if (hunk_tempactive != false) {
    hunk_tempactive = false;
    Hunk_FreeToHighMark(hunk_tempmark);
    if ((iVar3 < 0) || (hunk_high_used < iVar3)) {
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",iVar3);
    }
    hunk_tempactive = false;
    hunk_high_used = iVar3;
  }
                    /* Unresolved local var: hunk_t * h@[???] */
  hunk_tempmark = hunk_high_used;
  if (((int)uVar2 < 0) &&
     (Sys_Error("Hunk_HighAllocName: bad size: %i",uVar2), iVar3 = hunk_tempmark,
     hunk_tempactive != false)) {
    hunk_tempactive = false;
    Hunk_FreeToHighMark(hunk_tempmark);
    if ((iVar3 < 0) || (hunk_high_used < iVar3)) {
      Sys_Error("Hunk_FreeToHighMark: bad mark %i",iVar3);
    }
    hunk_tempactive = false;
    hunk_high_used = iVar3;
  }
  iVar3 = uVar2 + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < iVar3) {
    Con_Printf("Hunk_HighAlloc: failed on %i bytes\n",iVar3);
    pbVar1 = (byte *)0x0;
  }
  else {
    hunk_high_used = hunk_high_used + iVar3;
    Cache_FreeHigh(hunk_high_used);
    dest = hunk_base + (hunk_size - hunk_high_used);
    Q_memset(dest,0,iVar3);
    *(int *)(dest + 4) = iVar3;
    dest[0] = 0xed;
    dest[1] = '\x01';
    dest[2] = 0xf0;
    dest[3] = '\x1d';
    Q_strncpy((char *)(dest + 8),"temp",0x40);
    pbVar1 = dest + 0x48;
    dest[0x47] = '\0';
  }
  hunk_tempactive = true;
  return pbVar1;
}


