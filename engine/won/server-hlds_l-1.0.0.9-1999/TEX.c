// TEX_CleanupWadInfo  @ 080813c0
void TEX_CleanupWadInfo(void)

{
  int iVar1;
  
  if (lumpinfo != (void *)0x0) {
    free(lumpinfo);
    lumpinfo = (void *)0x0;
  }
  if (0 < nTexFiles) {
    iVar1 = 0;
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


// TEX_InitFromWad  @ 080810a0
undefined4 TEX_InitFromWad(char *param_1)

{
  void *pvVar1;
  char *pcVar2;
  char *pcVar3;
  FILE *pFVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char local_618 [260];
  char local_514 [260];
  char local_410 [1024];
  char local_10 [4];
  int local_c;
  long local_8;
  
  strcpy(local_410,param_1);
  pcVar2 = strchr(local_410,0x3b);
  if (pcVar2 == (char *)0x0) {
    strcat(local_410,";");
  }
  pcVar2 = strtok(local_410,";");
  if (pcVar2 != (char *)0x0) {
    do {
      ForwardSlashes(pcVar2);
      COM_FileBase(pcVar2,local_618);
      sprintf(local_514,"%s/%s",com_gamedir,local_618);
      COM_DefaultExtension(local_514,&DAT_080a5eda);
      pcVar3 = strstr(local_618,"pldecal");
      if (pcVar3 == (char *)0x0) {
        pFVar4 = fopen(local_514,"rb");
        (&texfiles)[nTexFiles] = pFVar4;
        if (pFVar4 == (FILE *)0x0) {
          COM_FileBase(pcVar2,local_618);
          sprintf(local_514,"valve/%s",local_618);
          COM_DefaultExtension(local_514,&DAT_080a5eda);
          pFVar4 = fopen(local_514,"rb");
          (&texfiles)[nTexFiles] = pFVar4;
        }
        iVar5 = nTexFiles;
        if ((&texfiles)[nTexFiles] == 0) {
          Sys_Error("WARNING: couldn\'t open %s\n",local_514);
          return 0;
        }
        nTexFiles = nTexFiles + 1;
        pFVar4 = (FILE *)(&texfiles)[iVar5];
        Con_DPrintf("Using WAD File: %s\n",local_514);
        SafeRead(pFVar4,local_10,0xc);
        iVar5 = strncmp(local_10,"WAD2",4);
        if ((iVar5 != 0) && (iVar5 = strncmp(local_10,"WAD3",4), iVar5 != 0)) {
          Sys_Error("TEX_InitFromWad: %s isn\'t a wadfile",local_514);
        }
        local_c = (*LittleLong)(local_c);
        local_8 = (*LittleLong)(local_8);
        fseek(pFVar4,local_8,0);
        lumpinfo = realloc(lumpinfo,(local_c + nTexLumps) * 0x24);
        iVar5 = 0;
        if (0 < local_c) {
          do {
            SafeRead(pFVar4,(void *)((int)lumpinfo + nTexLumps * 0x24),0x20);
            iVar7 = (int)lumpinfo + nTexLumps * 0x24 + 0x10;
            CleanupName(iVar7,iVar7);
            uVar6 = (*LittleLong)(*(undefined4 *)((int)lumpinfo + nTexLumps * 0x24));
            pvVar1 = lumpinfo;
            iVar7 = nTexLumps * 0x24;
            *(undefined4 *)((int)lumpinfo + iVar7) = uVar6;
            uVar6 = (*LittleLong)(*(undefined4 *)((int)pvVar1 + iVar7 + 4));
            pvVar1 = lumpinfo;
            iVar7 = nTexLumps * 0x24;
            *(undefined4 *)((int)lumpinfo + iVar7 + 4) = uVar6;
            *(int *)((int)pvVar1 + iVar7 + 0x20) = nTexFiles + -1;
            nTexLumps = nTexLumps + 1;
            iVar5 = iVar5 + 1;
          } while (iVar5 < local_c);
        }
      }
      pcVar2 = strtok((char *)0x0,";");
    } while (pcVar2 != (char *)0x0);
  }
  qsort(lumpinfo,nTexLumps,0x24,lump_sorter);
  return 1;
}


