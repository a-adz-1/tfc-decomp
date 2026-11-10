// Hunk_Alloc  @ 000c1690
undefined4 Hunk_Alloc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Hunk_AllocName(param_1,"unknown");
  return uVar1;
}


// Hunk_AllocName  @ 000c1578
undefined4 * Hunk_AllocName(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 < 0) {
    Sys_Error("Hunk_Alloc: bad size: %i",param_1);
  }
  iVar1 = (param_1 + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < iVar1) {
    Sys_Error("Hunk_Alloc: failed on %i bytes",iVar1);
  }
  puVar2 = (undefined4 *)(hunk_low_used + hunk_base);
  hunk_low_used = iVar1 + hunk_low_used;
  Cache_FreeLow(hunk_low_used);
  Q_memset(puVar2,0,iVar1);
  puVar2[1] = iVar1;
  *puVar2 = 0x1df001ed;
  Q_strncpy(puVar2 + 2,param_2,0x40);
  *(undefined1 *)((int)puVar2 + 0x47) = 0;
  return puVar2 + 0x12;
}


// Hunk_Check  @ 000c1180
void Hunk_Check(void)

{
  int *local_8;
  
  for (local_8 = hunk_base; local_8 != (int *)((int)hunk_base + hunk_low_used);
      local_8 = (int *)((int)local_8 + local_8[1])) {
    if (*local_8 != 0x1df001ed) {
      Sys_Error("Hunk_Check: trahsed sentinal");
    }
    if ((local_8[1] < 0x10) || (hunk_size < (int)local_8 + (local_8[1] - (int)hunk_base))) {
      Sys_Error("Hunk_Check: bad size");
    }
  }
  return;
}


// Hunk_FreeToHighMark  @ 000c1798
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


// Hunk_FreeToLowMark  @ 000c16f0
void Hunk_FreeToLowMark(int param_1)

{
  if ((param_1 < 0) || (hunk_low_used < param_1)) {
    Sys_Error("Hunk_FreeToLowMark: bad mark %i",param_1);
  }
  hunk_low_used = param_1;
  return;
}


// Hunk_HighAllocName  @ 000c1818
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
    puVar2 = (undefined4 *)((hunk_base + hunk_size) - hunk_high_used);
    Q_memset(puVar2,0,iVar1);
    puVar2[1] = iVar1;
    *puVar2 = 0x1df001ed;
    Q_strncpy(puVar2 + 2,param_2,0x40);
    *(undefined1 *)((int)puVar2 + 0x47) = 0;
    puVar2 = puVar2 + 0x12;
  }
  return puVar2;
}


// Hunk_HighMark  @ 000c1744
undefined4 Hunk_HighMark(void)

{
  if (hunk_tempactive != 0) {
    hunk_tempactive = 0;
    Hunk_FreeToHighMark(hunk_tempmark);
  }
  return hunk_high_used;
}


// Hunk_LowMark  @ 000c16cc
undefined4 Hunk_LowMark(void)

{
  return hunk_low_used;
}


// Hunk_Print  @ 000c1230
void Hunk_Print(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined1 local_a0 [52];
  int local_6c;
  undefined1 local_68 [64];
  undefined1 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_28 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_6c = FS_Open(mem_dbgfile._4_4_,&DAT_000ecf1c);
  if (local_6c != 0) {
    local_8 = hunk_base;
    local_10 = (int *)(hunk_low_used + (int)hunk_base);
    local_14 = (int *)((int)hunk_base + (hunk_size - hunk_high_used));
    local_18 = (int *)(hunk_size + (int)hunk_base);
    uVar1 = CommatizeNumber(hunk_size,local_a0);
    FS_FPrintf(local_6c,"          :%16.16s total hunk size\n",uVar1);
    FS_FPrintf(local_6c,"-------------------------\n");
    while( true ) {
      if (local_8 == local_10) {
        FS_FPrintf(local_6c,"-------------------------\n",uVar1);
        uVar1 = CommatizeNumber((hunk_size - hunk_low_used) - hunk_high_used,local_a0);
        FS_FPrintf(local_6c,"          :%16.16s REMAINING\n",uVar1);
        FS_FPrintf(local_6c,"-------------------------\n");
        local_8 = local_14;
      }
      if (local_8 == local_18) break;
      if (*local_8 != 0x1df001ed) {
        Sys_Error("Hunk_Check: trahsed sentinal");
      }
      if ((local_8[1] < 0x10) || (hunk_size < (int)local_8 + (local_8[1] - (int)hunk_base))) {
        Sys_Error("Hunk_Check: bad size");
      }
      local_c = (int *)(local_8[1] + (int)local_8);
      local_1c = local_1c + 1;
      local_24 = local_24 + 1;
      local_20 = local_20 + local_8[1];
      uVar1 = 0x40;
      piVar5 = local_8 + 2;
      Q_memcpy(local_68,piVar5);
      if (param_1 != 0) {
        puVar4 = local_68;
        uVar2 = CommatizeNumber(local_8[1],local_a0);
        FS_FPrintf(local_6c,"%8p :%16.16s %16s\n",local_8,uVar2,puVar4);
      }
      if ((local_c == local_10) || (local_c == local_18)) {
LAB_000c14d4:
        if (param_1 == 0) {
          uVar1 = CommatizeNumber(local_20,local_a0,piVar5,uVar1,local_68);
          FS_FPrintf(local_6c,"          :%16.16s %16s (TOTAL)\n",uVar1);
        }
        local_1c = 0;
        local_20 = 0;
      }
      else {
        uVar1 = 0x40;
        piVar5 = local_c + 2;
        iVar3 = Q_strncmp(local_8 + 2,piVar5);
        if (iVar3 != 0) goto LAB_000c14d4;
      }
      local_8 = local_c;
    }
    FS_FPrintf(local_6c,"-------------------------\n",uVar1);
    FS_FPrintf(local_6c,"%8i total blocks\n",local_24);
    FS_Close(local_6c);
  }
  return;
}


// Hunk_TempAlloc  @ 000c196c
undefined4 Hunk_TempAlloc(int param_1)

{
  undefined4 uVar1;
  
  if (hunk_tempactive != 0) {
    Hunk_FreeToHighMark(hunk_tempmark);
    hunk_tempactive = 0;
  }
  hunk_tempmark = Hunk_HighMark();
  uVar1 = Hunk_HighAllocName(param_1 + 0xfU & 0xfffffff0,&DAT_000ed104);
  hunk_tempactive = 1;
  return uVar1;
}


