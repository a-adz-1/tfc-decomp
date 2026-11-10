// TEX_AddAnimatingTextures  @ 000bd1b8
void TEX_AddAnimatingTextures(void)

{
  int iVar1;
  undefined1 local_34;
  char local_33;
  undefined1 local_15;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = nummiptex;
  local_c = 0;
  do {
    if (local_8 <= local_c) {
      if (nummiptex != local_8) {
        Con_DPrintf("added %i texture frames\n",nummiptex - local_8);
      }
      return;
    }
    if ((miptex[local_c * 0x40] == '+') || (miptex[local_c * 0x40] == '-')) {
      Q_strncpy(&local_34,miptex + local_c * 0x40,0x1f);
      local_15 = 0;
      for (local_10 = 0; local_10 < 0x14; local_10 = local_10 + 1) {
        if (local_10 < 10) {
          local_33 = (char)local_10 + '0';
        }
        else {
          local_33 = (char)local_10 + '7';
        }
        for (local_14 = 0; local_14 < nTexLumps; local_14 = local_14 + 1) {
          iVar1 = Q_strcmp(&local_34,lumpinfo + local_14 * 0x24 + 0x10);
          if (iVar1 == 0) {
            FindMiptex(&local_34);
            break;
          }
        }
      }
    }
    local_c = local_c + 1;
  } while( true );
}


// TEX_CleanupWadInfo  @ 000bcf38
void TEX_CleanupWadInfo(void)

{
  int local_8;
  
  if (lumpinfo != 0) {
    Mem_Free(lumpinfo);
    lumpinfo = 0;
  }
  for (local_8 = 0; local_8 < nTexFiles; local_8 = local_8 + 1) {
    FS_Close(*(undefined4 *)(texfiles + local_8 * 4));
    *(undefined4 *)(texfiles + local_8 * 4) = 0;
  }
  nTexLumps = 0;
  nTexFiles = 0;
  return;
}


// TEX_InitFromWad  @ 000bca50
undefined4 TEX_InitFromWad(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_624 [260];
  char local_520 [260];
  undefined4 local_41c;
  char *local_418;
  char local_414 [1022];
  undefined1 local_16;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  int local_8;
  
  Q_strncpy(local_414,param_1,0x3fe);
  local_16 = 0;
  pcVar1 = strchr(local_414,0x3b);
  if (pcVar1 == (char *)0x0) {
    Q_strcat(local_414,&DAT_000ec872);
  }
  local_418 = strtok(local_414,";");
  while( true ) {
    while( true ) {
      if (local_418 == (char *)0x0) {
        qsort(lumpinfo,nTexLumps,0x24,lump_sorter);
        return 1;
      }
      ForwardSlashes(local_418);
      COM_FileBase(local_418,local_624);
      snprintf(local_520,0x100,"%s",local_624);
      COM_DefaultExtension(local_520,&DAT_000ec877);
      iVar2 = Q_strstr(local_624,"pldecal");
      if (iVar2 == 0) break;
      local_418 = strtok((char *)0x0,";");
    }
    uVar3 = FS_Open(local_520,&DAT_000ec884);
    *(undefined4 *)(texfiles + nTexFiles * 4) = uVar3;
    if (*(int *)(texfiles + nTexFiles * 4) == 0) break;
    local_41c = *(undefined4 *)(texfiles + nTexFiles * 4);
    nTexFiles = nTexFiles + 1;
    Con_DPrintf("Using WAD File: %s\n",local_520);
    SafeRead(local_41c,local_14,0xc);
    iVar2 = Q_strncmp(local_14,&DAT_000ec8b6,4);
    if ((iVar2 != 0) && (iVar2 = Q_strncmp(local_14,&DAT_000ec8bb,4), iVar2 != 0)) {
      Sys_Error("TEX_InitFromWad: %s isn\'t a wadfile",local_520);
    }
    local_10 = (*LittleLong)(local_10);
    local_c = (*LittleLong)(local_c);
    FS_Seek(local_41c,local_c,0);
    lumpinfo = (void *)Mem_Realloc(lumpinfo,(nTexLumps + local_10) * 0x24);
    for (local_8 = 0; local_8 < local_10; local_8 = local_8 + 1) {
      SafeRead(local_41c,(void *)((int)lumpinfo + nTexLumps * 0x24),0x20);
      CleanupName((int)lumpinfo + nTexLumps * 0x24 + 0x10,(int)lumpinfo + nTexLumps * 0x24 + 0x10);
      uVar3 = (*LittleLong)(*(undefined4 *)((int)lumpinfo + nTexLumps * 0x24));
      *(undefined4 *)((int)lumpinfo + nTexLumps * 0x24) = uVar3;
      uVar3 = (*LittleLong)(*(undefined4 *)((int)lumpinfo + nTexLumps * 0x24 + 4));
      *(undefined4 *)((int)lumpinfo + nTexLumps * 0x24 + 4) = uVar3;
      *(int *)((int)lumpinfo + nTexLumps * 0x24 + 0x20) = nTexFiles + -1;
      nTexLumps = nTexLumps + 1;
    }
    local_418 = strtok((char *)0x0,";");
  }
  Sys_Error("WARNING: couldn\'t open %s\n",local_520);
  return 0;
}


// TEX_LoadLump  @ 000bcff0
undefined4 TEX_LoadLump(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_28 [16];
  undefined1 local_18 [20];
  
  CleanupName(param_1,local_18);
  puVar1 = bsearch(local_28,lumpinfo,nTexLumps,0x24,lump_sorter);
  if (puVar1 == (undefined4 *)0x0) {
    Con_SafePrintf("WARNING: texture lump \"%s\" not found\n",param_1);
    uVar2 = 0;
  }
  else {
    FS_Seek(*(undefined4 *)(texfiles + puVar1[8] * 4),*puVar1,0);
    SafeRead(*(undefined4 *)(texfiles + puVar1[8] * 4),param_2,puVar1[1]);
    uVar2 = puVar1[1];
  }
  return uVar2;
}


