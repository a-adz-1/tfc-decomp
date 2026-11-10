// W_CleanupName  @ 00089dec
void W_CleanupName(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  do {
    cVar2 = *(char *)(iVar3 + param_1);
    iVar4 = iVar3;
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar3 + param_2) = cVar2;
    iVar4 = iVar3 + 1;
    cVar2 = *(char *)(iVar4 + param_1);
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar4 + param_2) = cVar2;
    iVar4 = iVar3 + 2;
    cVar2 = *(char *)(iVar4 + param_1);
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar4 + param_2) = cVar2;
    iVar4 = iVar3 + 3;
    cVar2 = *(char *)(iVar4 + param_1);
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar4 + param_2) = cVar2;
    iVar4 = iVar3 + 4;
    cVar2 = *(char *)(iVar4 + param_1);
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar4 + param_2) = cVar2;
    iVar4 = iVar3 + 5;
    cVar2 = *(char *)(iVar4 + param_1);
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar4 + param_2) = cVar2;
    iVar4 = iVar3 + 6;
    cVar2 = *(char *)(iVar4 + param_1);
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar4 + param_2) = cVar2;
    iVar4 = iVar3 + 7;
    cVar2 = *(char *)(iVar4 + param_1);
    if (cVar2 == 0) break;
    if ((int)cVar2 - 0x41U < 0x1a) {
      cVar2 = cVar2 + ' ';
    }
    *(char *)(iVar4 + param_2) = cVar2;
    iVar3 = iVar3 + 8;
    iVar4 = iVar3;
  } while (iVar3 < 0x10);
  if (0xf < iVar4) {
    return;
  }
  uVar1 = 0x10U - iVar4 & 3;
  if (iVar4 < 0x10) {
    if (uVar1 == 0) goto LAB_00089f00;
    if (1 < uVar1) {
      if (2 < uVar1) {
        *(undefined1 *)(iVar4 + param_2) = 0;
        iVar4 = iVar4 + 1;
      }
      *(undefined1 *)(iVar4 + param_2) = 0;
      iVar4 = iVar4 + 1;
    }
  }
  *(undefined1 *)(iVar4 + param_2) = 0;
  iVar4 = iVar4 + 1;
  if (0xf < iVar4) {
    return;
  }
LAB_00089f00:
  do {
    *(undefined1 *)(iVar4 + param_2) = 0;
    *(undefined1 *)(param_2 + 1 + iVar4) = 0;
    *(undefined1 *)(param_2 + 2 + iVar4) = 0;
    *(undefined1 *)(param_2 + 3 + iVar4) = 0;
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x10);
  return;
}


// W_GetLumpName  @ 0008a13c
int W_GetLumpName(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)W_GetLumpinfo(param_1,param_2,1);
  return *piVar1 + *(int *)(&DAT_000dc38c + param_1 * 0x30);
}


// W_GetLumpNum  @ 0008a174
int W_GetLumpNum(int param_1,int param_2)

{
  if ((param_2 < 0) || (*(int *)(&DAT_000dc384 + param_1 * 0x30) < param_2)) {
    Sys_Error("W_GetLumpNum: bad number: %i",param_2);
  }
  return *(int *)(param_2 * 0x20 + *(int *)(&DAT_000dc388 + param_1 * 0x30)) +
         *(int *)(&DAT_000dc38c + param_1 * 0x30);
}


// W_GetLumpinfo  @ 0008a0a8
int W_GetLumpinfo(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_14 [16];
  
  W_CleanupName(param_2,local_14);
  param_1 = param_1 * 0x30;
  iVar3 = 0;
  iVar2 = *(int *)(&DAT_000dc388 + param_1);
  if (0 < *(int *)(&DAT_000dc384 + param_1)) {
    do {
      iVar1 = Q_strcmp(local_14,iVar2 + 0x10);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (iVar3 < *(int *)(&DAT_000dc384 + param_1));
  }
  if (param_3 != 0) {
    Sys_Error("W_GetLumpinfo: %s not found",param_2);
  }
  return 0;
}


// W_LoadWadFile  @ 00089f24
uint W_LoadWadFile(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *local_14;
  int *local_10;
  uint local_c;
  int local_8;
  
  local_c = 0;
  puVar5 = &wads;
  if (wads != 0) {
    puVar5 = &DAT_000dc390;
    local_c = 1;
    if (DAT_000dc390 != 0) {
      local_c = 2;
    }
  }
  if (local_c < 2) {
    iVar1 = COM_LoadHunkFile(param_1);
    puVar5[0xb] = iVar1;
    if (iVar1 == 0) {
      if (local_c != 0) {
        pcVar2 = "WARNING:  W_LoadWadFile, couldn\'t load %s\n";
        goto LAB_00089f9f;
      }
      Sys_Error("W_LoadWadFile: couldn\'t load %s",param_1);
    }
    Q_strcpy(puVar5 + 1,param_1);
    *puVar5 = 1;
    piVar4 = (int *)puVar5[0xb];
    if (*piVar4 != 0x33444157) {
      Sys_Error("Wad file %s doesn\'t have WAD3 id\n",param_1);
    }
    uVar3 = (*LittleLong)(piVar4[1]);
    puVar5[9] = uVar3;
    iVar1 = (*LittleLong)(piVar4[2]);
    piVar4 = (int *)(iVar1 + puVar5[0xb]);
    puVar5[10] = piVar4;
    local_8 = 0;
    if (0 < (int)puVar5[9]) {
      local_10 = piVar4 + 3;
      local_14 = piVar4 + 2;
      do {
        iVar1 = (*LittleLong)(*piVar4);
        *piVar4 = iVar1;
        iVar1 = (*LittleLong)(*local_14);
        *local_14 = iVar1;
        W_CleanupName(piVar4 + 4,piVar4 + 4);
        if ((char)*local_10 == 'B') {
          SwapPic(*piVar4 + puVar5[0xb]);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 8;
        local_10 = local_10 + 8;
        piVar4 = piVar4 + 8;
      } while (local_8 < (int)puVar5[9]);
    }
  }
  else {
    pcVar2 = "No room for wad %s\n";
LAB_00089f9f:
    Con_Printf(pcVar2,param_1);
    local_c = 0xffffffff;
  }
  return local_c;
}


