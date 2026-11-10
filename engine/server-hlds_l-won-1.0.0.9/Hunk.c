// Hunk_Alloc  @ 08086b20
void Hunk_Alloc(undefined4 param_1)

{
  Hunk_AllocName(param_1,"unknown");
  return;
}


// Hunk_AllocName  @ 08086a80
undefined4 * Hunk_AllocName(int param_1,undefined4 param_2)

{
  undefined4 *__s;
  size_t __n;
  
  if (param_1 < 0) {
    Sys_Error("Hunk_Alloc: bad size: %i",param_1);
  }
  __n = (param_1 + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < (int)__n) {
    Sys_Error("Hunk_Alloc: failed on %i bytes",__n);
  }
  __s = (undefined4 *)(hunk_base + hunk_low_used);
  hunk_low_used = hunk_low_used + __n;
  Cache_FreeLow(hunk_low_used);
  memset(__s,0,__n);
  __s[1] = __n;
  *__s = 0x1df001ed;
  Q_strncpy(__s + 2,param_2,0x40);
  return __s + 0x12;
}


// Hunk_Check  @ 08086790
void Hunk_Check(void)

{
  int *piVar1;
  
  piVar1 = hunk_base;
  if (hunk_base != (int *)((int)hunk_base + hunk_low_used)) {
    do {
      if (*piVar1 != 0x1df001ed) {
        Sys_Error("Hunk_Check: trahsed sentinal");
      }
      if ((piVar1[1] < 0x10) || (hunk_size < (int)piVar1 + (piVar1[1] - (int)hunk_base))) {
        Sys_Error("Hunk_Check: bad size");
      }
      piVar1 = (int *)((int)piVar1 + piVar1[1]);
    } while (piVar1 != (int *)(hunk_low_used + (int)hunk_base));
  }
  return;
}


// Hunk_FreeToHighMark  @ 08086bb0
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


// Hunk_FreeToLowMark  @ 08086b50
void Hunk_FreeToLowMark(int param_1)

{
  if ((param_1 < 0) || (hunk_low_used < param_1)) {
    Sys_Error("Hunk_FreeToLowMark: bad mark %i",param_1);
  }
  hunk_low_used = param_1;
  return;
}


// Hunk_HighAllocName  @ 08086c00
undefined4 * Hunk_HighAllocName(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  size_t __n;
  
  if (param_1 < 0) {
    Sys_Error("Hunk_HighAllocName: bad size: %i",param_1);
  }
  if (hunk_tempactive != 0) {
    Hunk_FreeToHighMark(hunk_tempmark);
    hunk_tempactive = 0;
  }
  __n = (param_1 + 0xfU & 0xfffffff0) + 0x48;
  if ((hunk_size - hunk_low_used) - hunk_high_used < (int)__n) {
    Con_Printf("Hunk_HighAlloc: failed on %i bytes\n",__n);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    hunk_high_used = hunk_high_used + __n;
    Cache_FreeHigh(hunk_high_used);
    puVar1 = (undefined4 *)((hunk_size + hunk_base) - hunk_high_used);
    memset(puVar1,0,__n);
    puVar1[1] = __n;
    *puVar1 = 0x1df001ed;
    Q_strncpy(puVar1 + 2,param_2,0x40);
    puVar1 = puVar1 + 0x12;
  }
  return puVar1;
}


// Hunk_HighMark  @ 08086b80
undefined4 Hunk_HighMark(void)

{
  if (hunk_tempactive != 0) {
    hunk_tempactive = 0;
    Hunk_FreeToHighMark(hunk_tempmark);
  }
  return hunk_high_used;
}


// Hunk_LowMark  @ 08086b40
undefined4 Hunk_LowMark(void)

{
  return hunk_low_used;
}


// Hunk_Print  @ 08086800
void Hunk_Print(int param_1)

{
  int *piVar1;
  int *piVar2;
  FILE *__stream;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int local_94;
  int local_90;
  undefined1 local_7c [52];
  int local_48 [16];
  undefined1 local_8;
  
  local_8 = 0;
  local_90 = 0;
  local_94 = 0;
  __stream = fopen((char *)mem_dbgfile._4_4_,"a");
  piVar6 = hunk_base;
  if (__stream != (FILE *)0x0) {
    piVar4 = (int *)(hunk_low_used + (int)hunk_base);
    piVar2 = (int *)((int)hunk_base + (hunk_size - hunk_high_used));
    piVar1 = (int *)(hunk_size + (int)hunk_base);
    uVar3 = CommatizeNumber(hunk_size,local_7c);
    fprintf(__stream,"          :%16.16s total hunk size\n",uVar3);
    fprintf(__stream,"-------------------------\n");
    while( true ) {
      piVar7 = piVar6;
      if (piVar6 == piVar4) {
        fprintf(__stream,"-------------------------\n");
        uVar3 = CommatizeNumber((hunk_size - hunk_low_used) - hunk_high_used,local_7c);
        fprintf(__stream,"          :%16.16s REMAINING\n",uVar3);
        fprintf(__stream,"-------------------------\n");
        piVar7 = piVar2;
      }
      if (piVar7 == piVar1) break;
      if (*piVar7 != 0x1df001ed) {
        Sys_Error("Hunk_Check: trahsed sentinal");
      }
      if ((piVar7[1] < 0x10) || (hunk_size < (int)piVar7 + (piVar7[1] - (int)hunk_base))) {
        Sys_Error("Hunk_Check: bad size");
      }
      piVar6 = (int *)(piVar7[1] + (int)piVar7);
      local_94 = local_94 + 1;
      local_90 = local_90 + piVar7[1];
      piVar8 = piVar7 + 2;
      piVar9 = local_48;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar9 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar9 = piVar9 + 1;
      }
      if (param_1 != 0) {
        uVar3 = CommatizeNumber(piVar7[1],local_7c,local_48);
        fprintf(__stream,"%8p :%16.16s %16s\n",piVar7,uVar3);
      }
      if (((piVar6 == piVar4) || (piVar6 == piVar1)) ||
         (iVar5 = strncmp((char *)(piVar7 + 2),(char *)(piVar6 + 2),0x40), iVar5 != 0)) {
        if (param_1 == 0) {
          uVar3 = CommatizeNumber(local_90,local_7c,local_48);
          fprintf(__stream,"          :%16.16s %16s (TOTAL)\n",uVar3);
        }
        local_90 = 0;
      }
    }
    fprintf(__stream,"-------------------------\n");
    fprintf(__stream,"%8i total blocks\n",local_94);
    fclose(__stream);
  }
  return;
}


// Hunk_TempAlloc  @ 08086cd0
void Hunk_TempAlloc(int param_1)

{
  if (hunk_tempactive != 0) {
    Hunk_FreeToHighMark(hunk_tempmark);
    hunk_tempactive = 0;
  }
  hunk_tempmark = Hunk_HighMark();
  Hunk_HighAllocName(param_1 + 0xfU & 0xfffffff0,&DAT_080a6b04);
  hunk_tempactive = 1;
  return;
}


