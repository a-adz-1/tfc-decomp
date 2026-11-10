// W_CleanupName  @ 000bd330
void W_CleanupName(int param_1,int param_2)

{
  char local_c;
  int local_8;
  
  for (local_8 = 0; (local_8 < 0x10 && (local_c = *(char *)(param_1 + local_8), local_c != '\0'));
      local_8 = local_8 + 1) {
    if (('@' < local_c) && (local_c < '[')) {
      local_c = local_c + ' ';
    }
    *(char *)(param_2 + local_8) = local_c;
  }
  for (; local_8 < 0x10; local_8 = local_8 + 1) {
    *(undefined1 *)(param_2 + local_8) = 0;
  }
  return;
}


// W_GetLumpName  @ 000bd6c0
int W_GetLumpName(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)W_GetLumpinfo(param_1,param_2,1);
  return *piVar1 + *(int *)(wads + param_1 * 0x30 + 0x2c);
}


// W_GetLumpNum  @ 000bd718
int W_GetLumpNum(int param_1,int param_2)

{
  if ((param_2 < 0) || (*(int *)(wads + param_1 * 0x30 + 0x24) < param_2)) {
    Sys_Error("W_GetLumpNum: bad number: %i",param_2);
  }
  return *(int *)(*(int *)(wads + param_1 * 0x30 + 0x28) + param_2 * 0x20) +
         *(int *)(wads + param_1 * 0x30 + 0x2c);
}


// W_GetLumpinfo  @ 000bd5fc
int W_GetLumpinfo(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_1c [16];
  int local_c;
  int local_8;
  
  W_CleanupName(param_2,local_1c);
  local_c = *(int *)(wads + param_1 * 0x30 + 0x28);
  local_8 = 0;
  while( true ) {
    if (*(int *)(wads + param_1 * 0x30 + 0x24) <= local_8) {
      if (param_3 != 0) {
        Sys_Error("W_GetLumpinfo: %s not found",param_2);
      }
      return 0;
    }
    iVar1 = Q_strcmp(local_1c,local_c + 0x10);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
    local_c = local_c + 0x20;
  }
  return local_c;
}


// W_LoadWadFile  @ 000bd3a4
int W_LoadWadFile(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  int *local_1c;
  int local_18;
  int local_10;
  int *local_8;
  
  for (local_18 = 0; (local_18 < 2 && (local_1c = (int *)(wads + local_18 * 0x30), *local_1c != 0));
      local_18 = local_18 + 1) {
  }
  if (local_18 < 2) {
    iVar2 = COM_LoadHunkFile(param_1);
    local_1c[0xb] = iVar2;
    if (local_1c[0xb] == 0) {
      if (local_18 != 0) {
        Con_Printf("WARNING:  W_LoadWadFile, couldn\'t load %s\n",param_1);
        return -1;
      }
      Sys_Error("W_LoadWadFile: couldn\'t load %s",param_1);
    }
    Q_strncpy(local_1c + 1,param_1,0x1f);
    *(undefined1 *)((int)local_1c + 0x23) = 0;
    *local_1c = 1;
    pcVar1 = (char *)local_1c[0xb];
    if ((((*pcVar1 != 'W') || (pcVar1[1] != 'A')) || (pcVar1[2] != 'D')) || (pcVar1[3] != '3')) {
      Sys_Error("Wad file %s doesn\'t have WAD3 id\n",param_1);
    }
    iVar2 = (*LittleLong)(*(undefined4 *)(pcVar1 + 4));
    local_1c[9] = iVar2;
    iVar2 = (*LittleLong)(*(undefined4 *)(pcVar1 + 8));
    local_1c[10] = iVar2 + local_1c[0xb];
    local_10 = 0;
    local_8 = (int *)local_1c[10];
    for (; local_10 < local_1c[9]; local_10 = local_10 + 1) {
      iVar2 = (*LittleLong)(*local_8);
      *local_8 = iVar2;
      iVar2 = (*LittleLong)(local_8[2]);
      local_8[2] = iVar2;
      W_CleanupName(local_8 + 4,local_8 + 4);
      if ((char)local_8[3] == 'B') {
        SwapPic(local_1c[0xb] + *local_8);
      }
      local_8 = local_8 + 8;
    }
  }
  else {
    Con_Printf("No room for wad %s\n",param_1);
    local_18 = -1;
  }
  return local_18;
}


// W_Shutdown  @ 000bd7c0
void W_Shutdown(void)

{
  int local_8;
  
  for (local_8 = 0; (local_8 < 2 && (*(int *)(wads + local_8 * 0x30) != 0)); local_8 = local_8 + 1)
  {
    memset(wads + local_8 * 0x30,0,0x30);
  }
  return;
}


