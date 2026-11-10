// W_CleanupName  @ 08081650
void W_CleanupName(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    cVar1 = *(char *)(iVar2 + param_1);
    if (cVar1 == 0) break;
    if ((int)cVar1 - 0x41U < 0x1a) {
      cVar1 = cVar1 + ' ';
    }
    *(char *)(iVar2 + param_2) = cVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  for (; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *(undefined1 *)(iVar2 + param_2) = 0;
  }
  return;
}


// W_GetLumpName  @ 080817f0
int W_GetLumpName(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)W_GetLumpinfo(param_1,1);
  return *piVar1 + wad_base;
}


// W_GetLumpNum  @ 08081810
int W_GetLumpNum(int param_1)

{
  if ((param_1 < 0) || (wad_numlumps < param_1)) {
    Sys_Error("W_GetLumpNum: bad number: %i",param_1);
  }
  return *(int *)(param_1 * 0x20 + wad_lumps) + wad_base;
}


// W_GetLumpinfo  @ 08081770
int W_GetLumpinfo(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_14 [16];
  
  W_CleanupName(param_1,local_14);
  iVar3 = 0;
  if (0 < wad_numlumps) {
    iVar2 = wad_lumps;
    do {
      iVar1 = strcmp(local_14,(char *)(iVar2 + 0x10));
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (iVar3 < wad_numlumps);
  }
  if (param_2 != 0) {
    Sys_Error("W_GetLumpinfo: %s not found",param_1);
  }
  return 0;
}


// W_LoadWadFile  @ 080816a0
void W_LoadWadFile(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  wad_base = (int *)COM_LoadHunkFile(param_1);
  if (wad_base == (int *)0x0) {
    Sys_Error("W_LoadWadFile: couldn\'t load %s",param_1);
  }
  piVar2 = wad_base;
  if (*wad_base != 0x33444157) {
    Sys_Error("Wad file %s doesn\'t have WAD3 id\n",param_1);
  }
  wad_numlumps = (*LittleLong)(piVar2[1]);
  iVar1 = (*LittleLong)(piVar2[2]);
  piVar2 = (int *)(iVar1 + (int)wad_base);
  wad_lumps = piVar2;
  if (0 < wad_numlumps) {
    iVar1 = 0;
    do {
      iVar3 = (*LittleLong)(*piVar2);
      *piVar2 = iVar3;
      iVar3 = (*LittleLong)(piVar2[2]);
      piVar2[2] = iVar3;
      W_CleanupName(piVar2 + 4,piVar2 + 4);
      if ((char)piVar2[3] == 'B') {
        SwapPic(*piVar2 + (int)wad_base);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 8;
    } while (iVar1 < wad_numlumps);
  }
  return;
}


