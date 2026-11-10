// Hunk_Alloc  @ 0008dcc4
void Hunk_Alloc(undefined4 param_1)

{
  Hunk_AllocName(param_1,"unknown");
  return;
}


// Hunk_AllocName  @ 0008dc18
undefined4 * Hunk_AllocName(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 < 0) {
    Sys_Error("Hunk_Alloc: bad size: %i",param_1);
  }
  iVar1 = (param_1 + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < iVar1) {
    Sys_Error("Hunk_Alloc: failed on %i bytes",iVar1);
  }
  iVar2 = hunk_low_used + iVar1;
  puVar3 = (undefined4 *)(hunk_low_used + hunk_base);
  hunk_low_used = iVar2;
  Cache_FreeLow(iVar2);
  Q_memset(puVar3,0,iVar1);
  puVar3[1] = iVar1;
  *puVar3 = 0x1df001ed;
  Q_strncpy(puVar3 + 2,param_2,0x40);
  return puVar3 + 0x12;
}


// Hunk_Check  @ 0008d8d4
void Hunk_Check(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = hunk_base;
  if (hunk_base != (int *)((int)hunk_base + hunk_low_used)) {
    do {
      if (*piVar2 != 0x1df001ed) {
        Sys_Error("Hunk_Check: trahsed sentinal");
      }
      iVar1 = piVar2[1];
      if ((iVar1 < 0x10) || (hunk_size < (int)piVar2 + (iVar1 - (int)hunk_base))) {
        Sys_Error("Hunk_Check: bad size");
        iVar1 = piVar2[1];
      }
      piVar2 = (int *)((int)piVar2 + iVar1);
    } while (piVar2 != (int *)(hunk_low_used + (int)hunk_base));
  }
  return;
}


// Hunk_FreeToHighMark  @ 0008dd8c
void Hunk_FreeToHighMark(int param_1)

{
  if (hunk_tempactive != 0) {
    hunk_tempactive = 0;
    Hunk_FreeToHighMark(hunk_tempmark);
  }
  if ((param_1 < 0) || (hunk_high_used < param_1)) {
    Sys_Error("Hunk_FreeToHighMark: bad mark %i",param_1);
  }
  hunk_high_used = param_1;
  return;
}


// Hunk_FreeToLowMark  @ 0008dd0c
void Hunk_FreeToLowMark(int param_1)

{
  if ((param_1 < 0) || (hunk_low_used < param_1)) {
    Sys_Error("Hunk_FreeToLowMark: bad mark %i",param_1);
  }
  hunk_low_used = param_1;
  return;
}


// Hunk_HighAllocName  @ 0008ddf0
undefined4 * Hunk_HighAllocName(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 < 0) {
    Sys_Error("Hunk_HighAllocName: bad size: %i",param_1);
  }
  if (hunk_tempactive != 0) {
    Hunk_FreeToHighMark(hunk_tempmark);
    hunk_tempactive = 0;
  }
  iVar1 = (param_1 + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < iVar1) {
    Con_Printf("Hunk_HighAlloc: failed on %i bytes\n",iVar1);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    hunk_high_used = iVar1 + hunk_high_used;
    Cache_FreeHigh(hunk_high_used);
    puVar2 = (undefined4 *)((hunk_size + hunk_base) - hunk_high_used);
    Q_memset(puVar2,0,iVar1);
    puVar2[1] = iVar1;
    *puVar2 = 0x1df001ed;
    Q_strncpy(puVar2 + 2,param_2,0x40);
    puVar2 = puVar2 + 0x12;
  }
  return puVar2;
}


// Hunk_HighMark  @ 0008dd4c
undefined4 Hunk_HighMark(void)

{
  if (hunk_tempactive != 0) {
    hunk_tempactive = 0;
    Hunk_FreeToHighMark(hunk_tempmark);
  }
  return hunk_high_used;
}


// Hunk_LowMark  @ 0008dcec
undefined4 Hunk_LowMark(void)

{
  return hunk_low_used;
}


// Hunk_Print  @ 0008d964
void Hunk_Print(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  FILE *__stream;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_8c;
  int local_88;
  undefined1 local_7c [52];
  undefined1 local_48 [64];
  undefined1 local_8;
  
  local_8 = 0;
  local_88 = 0;
  local_8c = 0;
  __stream = fopen((char *)mem_dbgfile._4_4_,"a");
  piVar6 = hunk_base;
  if (__stream != (FILE *)0x0) {
    piVar1 = (int *)((int)hunk_base + hunk_low_used);
    piVar2 = (int *)((int)hunk_base + hunk_size);
    piVar3 = (int *)((int)piVar2 - hunk_high_used);
    uVar4 = CommatizeNumber(hunk_size,local_7c);
    fprintf(__stream,"          :%16.16s total hunk size\n",uVar4);
    fprintf(__stream,"-------------------------\n");
    while( true ) {
      piVar7 = piVar6;
      if (piVar6 == piVar1) {
        fprintf(__stream,"-------------------------\n");
        uVar4 = CommatizeNumber((hunk_size - hunk_low_used) - hunk_high_used,local_7c);
        fprintf(__stream,"          :%16.16s REMAINING\n",uVar4);
        fprintf(__stream,"-------------------------\n");
        piVar7 = piVar3;
      }
      if (piVar7 == piVar2) break;
      if (*piVar7 != 0x1df001ed) {
        Sys_Error("Hunk_Check: trahsed sentinal");
      }
      iVar5 = piVar7[1];
      if ((iVar5 < 0x10) || (hunk_size < (int)piVar7 + (iVar5 - (int)hunk_base))) {
        Sys_Error("Hunk_Check: bad size");
        iVar5 = piVar7[1];
      }
      piVar6 = (int *)(iVar5 + (int)piVar7);
      local_8c = local_8c + 1;
      local_88 = local_88 + iVar5;
      Q_memcpy(local_48,piVar7 + 2,0x40);
      if (param_1 != 0) {
        uVar4 = CommatizeNumber(piVar7[1],local_7c,local_48);
        fprintf(__stream,"%8p :%16.16s %16s\n",piVar7,uVar4);
      }
      if (((piVar6 == piVar1) || (piVar6 == piVar2)) ||
         (iVar5 = Q_strncmp(piVar7 + 2,piVar6 + 2,0x40), iVar5 != 0)) {
        if (param_1 == 0) {
          uVar4 = CommatizeNumber(local_88,local_7c,local_48);
          fprintf(__stream,"          :%16.16s %16s (TOTAL)\n",uVar4);
        }
        local_88 = 0;
      }
    }
    fprintf(__stream,"-------------------------\n");
    fprintf(__stream,"%8i total blocks\n",local_8c);
    fclose(__stream);
  }
  return;
}


// Hunk_TempAlloc  @ 0008ded0
undefined4 Hunk_TempAlloc(int param_1)

{
  undefined4 uVar1;
  
  if (hunk_tempactive != 0) {
    Hunk_FreeToHighMark(hunk_tempmark);
    hunk_tempactive = 0;
  }
  hunk_tempmark = Hunk_HighMark();
  uVar1 = Hunk_HighAllocName(param_1 + 0xfU & 0xfffffff0,&DAT_000adca4);
  hunk_tempactive = 1;
  return uVar1;
}


