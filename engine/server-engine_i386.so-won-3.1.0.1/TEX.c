// TEX_AddAnimatingTextures  @ 00089c70
void TEX_AddAnimatingTextures(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_3c;
  int local_30;
  int local_2c;
  undefined1 local_24;
  char local_23;
  
  iVar1 = nummiptex;
  local_2c = 0;
  if (0 < nummiptex) {
    local_3c = 0;
    do {
      if ((miptex[local_3c] == '+') || (miptex[local_3c] == '-')) {
        Q_strcpy(&local_24,miptex + local_3c);
        local_30 = 0;
        do {
          if (local_30 < 10) {
            local_23 = (char)local_30 + '0';
          }
          else {
            local_23 = (char)local_30 + '7';
          }
          iVar3 = 0;
          if (0 < nTexLumps) {
            iVar4 = 0;
            do {
              iVar2 = Q_strcmp(&local_24,iVar4 + lumpinfo + 0x10);
              if (iVar2 == 0) {
                FindMiptex(&local_24);
                break;
              }
              iVar4 = iVar4 + 0x24;
              iVar3 = iVar3 + 1;
            } while (iVar3 < nTexLumps);
          }
          local_23 = (char)(local_30 + 1);
          if (local_30 + 1 < 10) {
            local_23 = local_23 + '0';
          }
          else {
            local_23 = local_23 + '7';
          }
          iVar3 = 0;
          if (0 < nTexLumps) {
            iVar4 = 0;
            do {
              iVar2 = Q_strcmp(&local_24,iVar4 + lumpinfo + 0x10);
              if (iVar2 == 0) {
                FindMiptex(&local_24);
                break;
              }
              iVar4 = iVar4 + 0x24;
              iVar3 = iVar3 + 1;
            } while (iVar3 < nTexLumps);
          }
          local_30 = local_30 + 2;
        } while (local_30 < 0x14);
      }
      local_3c = local_3c + 0x40;
      local_2c = local_2c + 1;
    } while (local_2c < iVar1);
  }
  if (nummiptex != iVar1) {
    Con_DPrintf("added %i texture frames\n",nummiptex - iVar1);
  }
  return;
}


// TEX_CleanupWadInfo  @ 00089aa8
void TEX_CleanupWadInfo(void)

{
  int iVar1;
  
  if (lumpinfo != 0) {
    Mem_Free(lumpinfo);
    lumpinfo = 0;
  }
  iVar1 = 0;
  if (0 < nTexFiles) {
    do {
      fclose((FILE *)(&texfiles)[iVar1]);
      (&texfiles)[iVar1] = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < nTexFiles);
  }
  nTexLumps = 0;
  nTexFiles = 0;
  return;
}


// TEX_InitFromWad  @ 000896b8
undefined4 TEX_InitFromWad(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  int local_62c;
  undefined1 local_618 [260];
  char local_514 [260];
  char local_410 [1024];
  undefined1 local_10 [4];
  int local_c;
  long local_8;
  
  Q_strcpy(local_410,param_1);
  pcVar1 = strchr(local_410,0x3b);
  if (pcVar1 == (char *)0x0) {
    Q_strcat(local_410,&DAT_000ad012);
  }
  pcVar1 = strtok(local_410,";");
  if (pcVar1 != (char *)0x0) {
    do {
      ForwardSlashes(pcVar1);
      COM_FileBase(pcVar1,local_618);
      sprintf(local_514,"%s/%s",com_gamedir,local_618);
      COM_DefaultExtension(local_514,&DAT_000ad01a);
      iVar2 = Q_strstr(local_618,"pldecal");
      if (iVar2 == 0) {
        pFVar3 = fopen(local_514,"rb");
        (&texfiles)[nTexFiles] = pFVar3;
        if ((&texfiles)[nTexFiles] == 0) {
          COM_FileBase(pcVar1,local_618);
          sprintf(local_514,"valve/%s",local_618);
          COM_DefaultExtension(local_514,&DAT_000ad01a);
          pFVar3 = fopen(local_514,"rb");
          (&texfiles)[nTexFiles] = pFVar3;
        }
        if ((&texfiles)[nTexFiles] == 0) {
          Sys_Error("WARNING: couldn\'t open %s\n",local_514);
          return 0;
        }
        pFVar3 = (FILE *)(&texfiles)[nTexFiles];
        nTexFiles = nTexFiles + 1;
        Con_DPrintf("Using WAD File: %s\n",local_514);
        SafeRead(pFVar3,local_10,0xc);
        iVar2 = Q_strncmp(local_10,&DAT_000ad062,4);
        if ((iVar2 != 0) && (iVar2 = Q_strncmp(local_10,&DAT_000ad067,4), iVar2 != 0)) {
          Sys_Error("TEX_InitFromWad: %s isn\'t a wadfile",local_514);
        }
        local_c = (*LittleLong)(local_c);
        local_8 = (*LittleLong)(local_8);
        fseek(pFVar3,local_8,0);
        lumpinfo = (void *)Mem_Realloc(lumpinfo,(local_c + nTexLumps) * 0x24);
        for (local_62c = 0; local_62c < local_c; local_62c = local_62c + 1) {
          SafeRead(pFVar3,(void *)((int)lumpinfo + nTexLumps * 0x24),0x20);
          CleanupName((int)lumpinfo + nTexLumps * 0x24 + 0x10,
                      (int)lumpinfo + nTexLumps * 0x24 + 0x10);
          uVar4 = (*LittleLong)(*(undefined4 *)((int)lumpinfo + nTexLumps * 0x24));
          *(undefined4 *)((int)lumpinfo + nTexLumps * 0x24) = uVar4;
          uVar4 = (*LittleLong)(*(undefined4 *)((int)lumpinfo + nTexLumps * 0x24 + 4));
          *(undefined4 *)((int)lumpinfo + nTexLumps * 0x24 + 4) = uVar4;
          *(int *)((int)lumpinfo + nTexLumps * 0x24 + 0x20) = nTexFiles + -1;
          nTexLumps = nTexLumps + 1;
        }
      }
      pcVar1 = strtok((char *)0x0,";");
    } while (pcVar1 != (char *)0x0);
  }
  qsort(lumpinfo,nTexLumps,0x24,lump_sorter);
  return 1;
}


// TEX_LoadLump  @ 00089b3c
long TEX_LoadLump(undefined4 param_1,undefined4 param_2)

{
  long *plVar1;
  long lVar2;
  undefined1 local_28 [16];
  undefined1 local_18 [20];
  
  CleanupName(param_1,local_18);
  plVar1 = bsearch(local_28,lumpinfo,nTexLumps,0x24,lump_sorter);
  if (plVar1 == (long *)0x0) {
    Con_SafePrintf("WARNING: texture lump \"%s\" not found\n",param_1);
    lVar2 = 0;
  }
  else {
    fseek((FILE *)(&texfiles)[plVar1[8]],*plVar1,0);
    SafeRead((&texfiles)[plVar1[8]],param_2,plVar1[1]);
    lVar2 = plVar1[1];
  }
  return lVar2;
}


