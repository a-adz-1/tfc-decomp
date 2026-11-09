// HPAK_AddLump  @ 0004da20
void HPAK_AddLump(qboolean bUseQueue,char *pakname,resource_s *pResource,void *pData,
                 FileHandle_t fpSource)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  FileHandle_t file;
  FileHandle_t dst;
  char *pcVar5;
  uchar *puVar6;
  uint uVar7;
  int iVar8;
  void *pInput;
  int iVar9;
  int in_GS_OFFSET;
  void *local_354;
  int local_350;
  uint local_33c;
  void *local_338;
  int local_334;
  void *local_330;
  char local_32c [260];
  uchar local_228 [260];
  MD5Context_t local_124 [2];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t iRead@[???]
                       Unresolved local var: FileHandle_t iWrite@[???]
                       Unresolved local var: int cmp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t olddirectory@[???]
                       Unresolved local var: hash_pack_directory_t newdirectory@[???]
                       Unresolved local var: qboolean bExact@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: hash_pack_entry_t * pNewEntry@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((pakname == (char *)0x0) || (pResource == (resource_s *)0x0)) {
    if (pakname == (char *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
      goto LAB_0004dab2;
    }
    if (pResource == (resource_s *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no lump to add\n");
      goto LAB_0004dab2;
    }
    if ((pData != (void *)0x0) || (fpSource != (FileHandle_t)0x0)) goto LAB_0004dab2;
  }
  else if ((pData != (void *)0x0) || (fpSource != (FileHandle_t)0x0)) {
    if (pResource->nDownloadSize - 0x400U < 0x1fc01) {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
      Q_memset(local_124,0,0x58);
      MD5Init(local_124);
      if (pData == (void *)0x0) {
                    /* Unresolved local var: int nOrig@[???]
                       Unresolved local var: uchar * pDiskData@[???] */
        uVar7 = FS_Tell(fpSource);
        puVar6 = Mem_Malloc(pResource->nDownloadSize + 1);
        Q_memset(puVar6,0,pResource->nDownloadSize);
        FS_Read(puVar6,pResource->nDownloadSize,1,fpSource);
        FS_Seek(fpSource,uVar7,FILESYSTEM_SEEK_HEAD);
        MD5Update(local_124,puVar6,pResource->nDownloadSize);
        Mem_Free(puVar6);
      }
      else {
        MD5Update(local_124,pData,pResource->nDownloadSize);
      }
      MD5Final(local_228,local_124);
      puVar6 = pResource->rgucMD5_hash;
      iVar4 = Q_memcmp(puVar6,local_228,0x10);
      if (iVar4 == 0) {
        if (bUseQueue == false) {
          snprintf(local_32c,0x100,"%s",pakname);
          COM_DefaultExtension(local_32c,".hpk");
          COM_FixSlashes(local_32c);
          Q_strncpy((char *)local_124,local_32c,0xff);
          local_25 = 0;
          file = FS_Open(local_32c,"rb");
          if (file == (FileHandle_t)0x0) {
            HPAK_CreatePak(pakname,pResource,pData,fpSource);
          }
          else {
            COM_StripExtension(local_32c,(char *)local_228);
            COM_DefaultExtension((char *)local_228,".hp2");
            dst = FS_Open((char *)local_228,"w+b");
            if (dst == (FileHandle_t)0x0) {
              FS_Close(file);
              Con_Printf("ERROR: couldn\'t open %s.\n",local_32c);
            }
            else {
              FS_Read(&hash_pack_header,0xc,1,file);
              if (hash_pack_header.version == 1) {
                FS_Seek(file,0,FILESYSTEM_SEEK_HEAD);
                uVar7 = FS_Size(file);
                COM_CopyFileChunk(dst,file,uVar7);
                FS_Seek(file,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                FS_Read(&local_33c,4,1,file);
                if (local_33c < 0x8001) {
                  local_338 = Mem_Malloc((local_33c * 9 + 9) * 0x10);
                  FS_Read(local_338,local_33c * 0x90,1,file);
                  FS_Close(file);
                    /* Unresolved local var: int i@[???] */
                  if (0 < (int)local_33c) {
                    iVar9 = 0;
                    iVar4 = 0;
                    do {
                      iVar8 = Q_memcmp(puVar6,(void *)((int)local_338 + iVar9 + 0x4d),0x10);
                      if (iVar8 == 0) {
                        FS_Close(dst);
                        FS_Unlink((char *)local_228);
                        Mem_Free(local_338);
                        goto LAB_0004dab2;
                      }
                      iVar4 = iVar4 + 1;
                      iVar9 = iVar9 + 0x90;
                    } while (iVar4 < (int)local_33c);
                  }
                  local_334 = local_33c + 1;
                  local_330 = Mem_Malloc(local_334 * 0x90);
                  Q_memset(local_330,0,local_334 * 0x90);
                  Q_memcpy(local_330,local_338,local_33c * 0x90);
                  if (0 < (int)local_33c) {
                    local_350 = 0;
                    iVar4 = 0;
LAB_0004e081:
                    iVar9 = Q_memcmp(puVar6,(void *)((int)local_338 + iVar4 + 0x4d),0x10);
                    if (-1 < iVar9) goto LAB_0004e070;
                    local_354 = (void *)(iVar4 + (int)local_330);
                    if (local_350 < (int)local_33c) {
                      iVar4 = local_350 * 0x90;
                      do {
                        uVar7 = 0;
                        do {
                          puVar1 = (undefined4 *)((int)local_338 + uVar7 + iVar4);
                          puVar2 = (undefined4 *)((int)local_330 + uVar7 + iVar4 + 0x90);
                          uVar7 = uVar7 + 8;
                          uVar3 = puVar1[1];
                          *puVar2 = *puVar1;
                          puVar2[1] = uVar3;
                        } while (uVar7 < 0x90);
                        local_350 = local_350 + 1;
                        iVar4 = iVar4 + 0x90;
                      } while (local_350 < (int)local_33c);
                    }
                    if (local_354 == (void *)0x0) goto LAB_0004e319;
                    goto LAB_0004e175;
                  }
LAB_0004e319:
                  local_354 = (void *)((int)local_330 + local_334 * 0x90 + -0x90);
LAB_0004e175:
                  Q_memset(local_354,0,0x90);
                  FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                  uVar7 = 0;
                  do {
                    uVar3 = *(undefined4 *)(pResource->szFileName + uVar7);
                    *(undefined4 *)((int)local_354 + uVar7 + 4) =
                         *(undefined4 *)(pResource->szFileName + uVar7 + 4);
                    *(undefined4 *)((int)local_354 + uVar7) = uVar3;
                    uVar7 = uVar7 + 8;
                  } while (uVar7 < 0x88);
                  uVar7 = FS_Tell(dst);
                  *(uint *)((int)local_354 + 0x88) = uVar7;
                  iVar4 = pResource->nDownloadSize;
                  *(int *)((int)local_354 + 0x8c) = iVar4;
                  if (pData == (void *)0x0) {
                    COM_CopyFileChunk(dst,fpSource,iVar4);
                  }
                  else {
                    FS_Write(pData,iVar4,1,dst);
                  }
                  hash_pack_header.nDirectoryOffset = FS_Tell(dst);
                  iVar4 = 0;
                  FS_Write(&local_334,4,1,dst);
                  if (0 < local_334) {
                    iVar9 = 0;
                    do {
                      iVar4 = iVar4 + 1;
                      pInput = (void *)((int)local_330 + iVar9);
                      iVar9 = iVar9 + 0x90;
                      FS_Write(pInput,0x90,1,dst);
                    } while (iVar4 < local_334);
                  }
                  if (local_330 != (void *)0x0) {
                    Mem_Free(local_330);
                  }
                  if (local_338 != (void *)0x0) {
                    Mem_Free(local_338);
                  }
                  FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
                  FS_Write(&hash_pack_header,0xc,1,dst);
                  FS_Close(dst);
                  FS_Unlink((char *)local_124);
                  FS_Rename((char *)local_228,(char *)local_124);
                }
                else {
                  Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_33c);
                  FS_Close(file);
                  FS_Close(dst);
                  FS_Unlink((char *)local_228);
                }
              }
              else {
                FS_Close(file);
                FS_Close(dst);
                FS_Unlink((char *)local_228);
                Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
              }
            }
          }
        }
        else {
          HPAK_AddToQueue(pakname,pResource,pData,fpSource);
        }
      }
      else {
        Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
        pcVar5 = MD5_Print(puVar6);
        Con_Printf("Purported:  %s\n",pcVar5);
        pcVar5 = MD5_Print(local_228);
        Con_Printf("Actual   :  %s\n",pcVar5);
        Con_Printf("Ignoring lump addition\n");
      }
    }
    else {
      Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",pResource->nDownloadSize);
    }
    goto LAB_0004dab2;
  }
  Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
LAB_0004dab2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0004e070:
  local_350 = local_350 + 1;
  iVar4 = iVar4 + 0x90;
  if ((int)local_33c <= local_350) goto LAB_0004e319;
  goto LAB_0004e081;
}


// HPAK_AddToQueue  @ 0004d110
void HPAK_AddToQueue(char *pakname,resource_s *pResource,void *pData,FileHandle_t fpSource)

{
  undefined4 uVar1;
  size_t size;
  hash_pack_queue_t *dest;
  char *pcVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  
                    /* Unresolved local var: hash_pack_queue_t * n@[???] */
  dest = Mem_Malloc(0x98);
  if (dest == (hash_pack_queue_t *)0x0) {
    Sys_Error("Unable to allocate %i bytes for hpak queue!",0x98);
  }
  iVar5 = 0;
  Q_memset(dest,0,0x98);
  pcVar2 = Mem_Strdup(pakname);
  dest->pakname = pcVar2;
  uVar3 = 0;
  do {
    uVar1 = *(undefined4 *)(pResource->szFileName + uVar3 + 4);
    *(undefined4 *)((dest->resource).szFileName + uVar3) =
         *(undefined4 *)(pResource->szFileName + uVar3);
    *(undefined4 *)((dest->resource).szFileName + uVar3 + 4) = uVar1;
    uVar3 = uVar3 + 8;
  } while (uVar3 < 0x88);
  size = pResource->nDownloadSize;
  dest->datasize = size;
  pvVar4 = Mem_Malloc(size);
  dest->data = pvVar4;
  if (pvVar4 == (void *)0x0) {
    iVar5 = dest->datasize;
    Sys_Error("Unable to allocate %i bytes for hpak queue!",iVar5);
  }
  if (pData == (void *)0x0) {
    if (fpSource == (FileHandle_t)0x0) {
      Sys_Error("Add to Queue called without data or file pointer!",iVar5);
    }
    else {
      FS_Read(dest->data,dest->datasize,1,fpSource);
    }
  }
  else {
    Q_memcpy(dest->data,pData,dest->datasize);
  }
  dest->next = gp_hpak_queue;
  gp_hpak_queue = dest;
  return;
}


// HPAK_CheckIntegrity  @ 00053570
void HPAK_CheckIntegrity(char *pakname)

{
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] name@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  snprintf(local_114,0x100,"%s",pakname);
  COM_DefaultExtension(local_114,".hpk");
  COM_FixSlashes(local_114);
  HPAK_ValidatePak(local_114);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// HPAK_CheckSize  @ 000528c0
void HPAK_CheckSize(char *pakname)

{
  float fVar1;
  float fVar2;
  FileHandle_t file;
  uint uVar3;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] fullname@[???]
                       Unresolved local var: float maxSize@[???]
                       Unresolved local var: float actualSize@[???]
                       Unresolved local var: FileHandle_t hfile@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((hpk_maxsize.value != 0.0) && (pakname != (char *)0x0)) {
    if (hpk_maxsize.value < 0.0) {
      Con_Printf("hpk_maxsize < 0, setting to 0\n");
      Cvar_DirectSet(&hpk_maxsize,"0");
    }
    else {
      snprintf(local_114,0x100,"%s");
      COM_DefaultExtension(local_114,".hpk");
      COM_FixSlashes(local_114);
      fVar2 = hpk_maxsize.value * 1e+06;
      file = FS_Open(local_114,"rb");
      if (file == (FileHandle_t)0x0) {
        fVar1 = 0.0;
      }
      else {
        uVar3 = FS_Size(file);
        fVar1 = (float)uVar3;
        FS_Close(file);
      }
      if (fVar2 <= fVar1) {
        Con_Printf("Server: Size of %s > %f MB, deleting.\n",local_114,(double)hpk_maxsize.value);
        Log_Printf("Server: Size of %s > %f MB, deleting.\n",local_114,(double)hpk_maxsize.value);
        FS_RemoveFile(local_114,(char *)0x0);
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// HPAK_CreatePak  @ 0004d580
void HPAK_CreatePak(char *pakname,resource_s *pResource,void *pData,FileHandle_t fpSource)

{
  undefined4 uVar1;
  hash_pack_entry_t *phVar2;
  FileHandle_t file;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uchar *buf;
  int iVar6;
  int in_GS_OFFSET;
  uchar local_18c [16];
  MD5Context_t local_17c;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int32 curpos@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((pData != (void *)0x0) == (fpSource == (FileHandle_t)0x0)) {
    snprintf(local_124,0x100,"%s",pakname);
    COM_DefaultExtension(local_124,".hpk");
    Con_Printf("Creating HPAK %s.\n",local_124);
    file = FS_Open(local_124,"wb");
    if (file == (FileHandle_t)0x0) {
      Con_Printf("ERROR: couldn\'t open new .hpk, check access rights to %s.\n",local_124);
    }
    else {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
      Q_memset(&local_17c,0,0x58);
      MD5Init(&local_17c);
      if (pData == (void *)0x0) {
                    /* Unresolved local var: int nOrig@[???]
                       Unresolved local var: uchar * pDiskData@[???] */
        uVar4 = FS_Tell(fpSource);
        buf = Mem_Malloc(pResource->nDownloadSize + 1);
        Q_memset(buf,0,pResource->nDownloadSize);
        FS_Read(buf,pResource->nDownloadSize,1,fpSource);
        FS_Seek(fpSource,uVar4,FILESYSTEM_SEEK_HEAD);
        MD5Update(&local_17c,buf,pResource->nDownloadSize);
        Mem_Free(buf);
      }
      else {
        MD5Update(&local_17c,pData,pResource->nDownloadSize);
      }
      MD5Final(local_18c,&local_17c);
      iVar3 = Q_memcmp(pResource->rgucMD5_hash,local_18c,0x10);
      if (iVar3 == 0) {
        Q_memset(&hash_pack_header,0,0xc);
        Q_strncpy(hash_pack_header.szFileStamp,"HPAK",4);
        hash_pack_header.version = 1;
        hash_pack_header.nDirectoryOffset = 0;
        FS_Write(&hash_pack_header,0xc,1,file);
        Q_memset(&hash_pack_dir,0,8);
        hash_pack_dir.nEntries = 1;
        hash_pack_dir.p_rgEntries = Mem_Malloc(0x90);
        Q_memset(hash_pack_dir.p_rgEntries,0,hash_pack_dir.nEntries * 0x90);
        phVar2 = hash_pack_dir.p_rgEntries;
        uVar4 = 0;
        do {
          uVar1 = *(undefined4 *)(pResource->szFileName + uVar4 + 4);
          *(undefined4 *)((phVar2->resource).szFileName + uVar4) =
               *(undefined4 *)(pResource->szFileName + uVar4);
          *(undefined4 *)((phVar2->resource).szFileName + uVar4 + 4) = uVar1;
          uVar4 = uVar4 + 8;
        } while (uVar4 < 0x88);
        uVar4 = FS_Tell(file);
        phVar2->nOffset = uVar4;
        iVar3 = pResource->nDownloadSize;
        phVar2->nFileLength = iVar3;
        if (pData == (void *)0x0) {
          COM_CopyFileChunk(file,fpSource,iVar3);
        }
        else {
          FS_Write(pData,iVar3,1,file);
        }
        iVar3 = 0;
        uVar4 = FS_Tell(file);
        FS_Write(&hash_pack_dir,4,1,file);
        if (0 < hash_pack_dir.nEntries) {
          iVar6 = 0;
          do {
            iVar6 = iVar6 + 1;
            pcVar5 = ((hash_pack_dir.p_rgEntries)->resource).szFileName + iVar3;
            iVar3 = iVar3 + 0x90;
            FS_Write(pcVar5,0x90,1,file);
          } while (iVar6 < hash_pack_dir.nEntries);
        }
        if (hash_pack_dir.p_rgEntries != (hash_pack_entry_t *)0x0) {
          Mem_Free(hash_pack_dir.p_rgEntries);
        }
        hash_pack_dir.nEntries = 0;
        hash_pack_dir.p_rgEntries = (hash_pack_entry_t *)0x0;
        hash_pack_header.nDirectoryOffset = uVar4;
        FS_Seek(file,0,FILESYSTEM_SEEK_HEAD);
        FS_Write(&hash_pack_header,0xc,1,file);
        FS_Close(file);
      }
      else {
        Con_Printf("HPAK_CreatePak called with bogus lump, md5 mismatch\n");
        pcVar5 = MD5_Print(pResource->rgucMD5_hash);
        Con_Printf("Purported:  %s\n",pcVar5);
        pcVar5 = MD5_Print(local_18c);
        Con_Printf("Actual   :  %s\n",pcVar5);
        Con_Printf("Ignoring lump addition\n");
      }
    }
  }
  else {
    Con_Printf("HPAK_CreatePak, must specify one of pData or fpSource\n");
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// HPAK_Extract_f  @ 00051110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Extract_f(void)

{
  uchar *hash;
  undefined4 uVar1;
  hash_pack_queue_t *p;
  int iVar2;
  char *pcVar3;
  FileHandle_t pvVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  void *pvVar8;
  FileHandle_t pvVar9;
  undefined4 *puVar10;
  int iVar11;
  int in_GS_OFFSET;
  char *pcVar12;
  undefined4 *puVar13;
  double dVar14;
  uchar *puVar15;
  int local_384;
  void *local_37c;
  uint local_368;
  void *local_364;
  int local_360;
  void *local_35c;
  char local_358 [4];
  int local_354;
  int local_350;
  undefined4 local_34c;
  uint local_348;
  char local_32c [260];
  uchar local_228 [260];
  MD5Context_t local_124 [2];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int nIndex@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source != src_command) goto LAB_00051132;
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
                    /* Unresolved local var: hash_pack_queue_t * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t iRead@[???]
                       Unresolved local var: FileHandle_t iWrite@[???]
                       Unresolved local var: int cmp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t olddirectory@[???]
                       Unresolved local var: hash_pack_directory_t newdirectory@[???]
                       Unresolved local var: qboolean bExact@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: hash_pack_entry_t * pNewEntry@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
  p = gp_hpak_queue;
  while (p != (hash_pack_queue_t *)0x0) {
    gp_hpak_queue = p->next;
    pcVar3 = p->pakname;
    if (pcVar3 == (char *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
    }
    else {
      puVar15 = p->data;
      if (puVar15 == (uchar *)0x0) {
        Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
      }
      else {
        iVar2 = (p->resource).nDownloadSize;
        if (iVar2 - 0x400U < 0x1fc01) {
          Q_memset(local_124,0,0x58);
          MD5Init(local_124);
          MD5Update(local_124,puVar15,(p->resource).nDownloadSize);
          MD5Final(local_228,local_124);
          hash = (p->resource).rgucMD5_hash;
          iVar2 = Q_memcmp(hash,local_228,0x10);
          if (iVar2 == 0) {
            snprintf(local_32c,0x100,"%s",pcVar3);
            COM_DefaultExtension(local_32c,".hpk");
            COM_FixSlashes(local_32c);
            Q_strncpy((char *)local_124,local_32c,0xff);
            local_25 = 0;
            pvVar4 = FS_Open(local_32c,"rb");
            if (pvVar4 == (FileHandle_t)0x0) {
              HPAK_CreatePak(pcVar3,&p->resource,puVar15,(FileHandle_t)0x0);
            }
            else {
              COM_StripExtension(local_32c,(char *)local_228);
              COM_DefaultExtension((char *)local_228,".hp2");
              pvVar9 = FS_Open((char *)local_228,"w+b");
              if (pvVar9 == (FileHandle_t)0x0) {
                FS_Close(pvVar4);
                Con_Printf("ERROR: couldn\'t open %s.\n",local_32c);
              }
              else {
                FS_Read(&hash_pack_header,0xc,1,pvVar4);
                if (hash_pack_header.version == 1) {
                  FS_Seek(pvVar4,0,FILESYSTEM_SEEK_HEAD);
                  uVar6 = FS_Size(pvVar4);
                  COM_CopyFileChunk(pvVar9,pvVar4,uVar6);
                  FS_Seek(pvVar4,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                  FS_Read(&local_368,4,1,pvVar4);
                  if (local_368 < 0x8001) {
                    local_364 = Mem_Malloc((local_368 * 9 + 9) * 0x10);
                    FS_Read(local_364,local_368 * 0x90,1,pvVar4);
                    FS_Close(pvVar4);
                    /* Unresolved local var: int i@[???] */
                    if (0 < (int)local_368) {
                      iVar2 = 0;
                      local_384 = 0;
                      do {
                        iVar5 = Q_memcmp(hash,(void *)((int)local_364 + iVar2 + 0x4d),0x10);
                        if (iVar5 == 0) {
                          FS_Close(pvVar9);
                          FS_Unlink((char *)local_228);
                          Mem_Free(local_364);
                          goto LAB_000511a0;
                        }
                        local_384 = local_384 + 1;
                        iVar2 = iVar2 + 0x90;
                      } while (local_384 < (int)local_368);
                    }
                    local_360 = local_368 + 1;
                    local_35c = Mem_Malloc(local_360 * 0x90);
                    Q_memset(local_35c,0,local_360 * 0x90);
                    Q_memcpy(local_35c,local_364,local_368 * 0x90);
                    if (0 < (int)local_368) {
                      iVar2 = 0;
LAB_000517fb:
                      iVar5 = iVar2 * 0x90;
                      iVar11 = Q_memcmp(hash,(void *)((int)local_364 + iVar5 + 0x4d),0x10);
                      if (-1 < iVar11) goto LAB_000517f0;
                      local_37c = (void *)((int)local_35c + iVar5);
                      for (; iVar2 < (int)local_368; iVar2 = iVar2 + 1) {
                        uVar6 = 0;
                        do {
                          puVar13 = (undefined4 *)((int)local_364 + uVar6 + iVar5);
                          uVar1 = puVar13[1];
                          puVar10 = (undefined4 *)((int)local_35c + uVar6 + iVar5 + 0x90);
                          uVar6 = uVar6 + 8;
                          *puVar10 = *puVar13;
                          puVar10[1] = uVar1;
                        } while (uVar6 < 0x90);
                        iVar5 = iVar5 + 0x90;
                      }
                      if (local_37c == (void *)0x0) goto LAB_00051c4d;
                      goto LAB_00051c66;
                    }
LAB_00051c4d:
                    local_37c = (void *)((int)local_35c + local_360 * 0x90 + -0x90);
LAB_00051c66:
                    Q_memset(local_37c,0,0x90);
                    FS_Seek(pvVar9,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                    uVar6 = 0;
                    do {
                      uVar1 = *(undefined4 *)((p->resource).szFileName + uVar6 + 4);
                      *(undefined4 *)((int)local_37c + uVar6) =
                           *(undefined4 *)((p->resource).szFileName + uVar6);
                      *(undefined4 *)((int)local_37c + uVar6 + 4) = uVar1;
                      uVar6 = uVar6 + 8;
                    } while (uVar6 < 0x88);
                    uVar6 = FS_Tell(pvVar9);
                    *(uint *)((int)local_37c + 0x88) = uVar6;
                    iVar2 = (p->resource).nDownloadSize;
                    *(int *)((int)local_37c + 0x8c) = iVar2;
                    FS_Write(puVar15,iVar2,1,pvVar9);
                    hash_pack_header.nDirectoryOffset = FS_Tell(pvVar9);
                    FS_Write(&local_360,4,1,pvVar9);
                    if (0 < local_360) {
                      iVar2 = 0;
                      iVar5 = 0;
                      do {
                        iVar5 = iVar5 + 1;
                        pvVar8 = (void *)((int)local_35c + iVar2);
                        iVar2 = iVar2 + 0x90;
                        FS_Write(pvVar8,0x90,1,pvVar9);
                      } while (iVar5 < local_360);
                    }
                    if (local_35c != (void *)0x0) {
                      Mem_Free(local_35c);
                    }
                    if (local_364 != (void *)0x0) {
                      Mem_Free(local_364);
                    }
                    FS_Seek(pvVar9,0,FILESYSTEM_SEEK_HEAD);
                    FS_Write(&hash_pack_header,0xc,1,pvVar9);
                    FS_Close(pvVar9);
                    FS_Unlink((char *)local_124);
                    FS_Rename((char *)local_228,(char *)local_124);
                  }
                  else {
                    Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_368);
                    FS_Close(pvVar4);
                    FS_Close(pvVar9);
                    FS_Unlink((char *)local_228);
                  }
                }
                else {
                  FS_Close(pvVar4);
                  FS_Close(pvVar9);
                  FS_Unlink((char *)local_228);
                  Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
                }
              }
            }
          }
          else {
            Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
            pcVar3 = MD5_Print(hash);
            Con_Printf("Purported:  %s\n",pcVar3);
            pcVar3 = MD5_Print(local_228);
            Con_Printf("Actual   :  %s\n",pcVar3);
            Con_Printf("Ignoring lump addition\n");
          }
        }
        else {
          Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",iVar2);
        }
      }
    }
LAB_000511a0:
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    p = gp_hpak_queue;
  }
  gp_hpak_queue = p;
  iVar2 = Cmd_Argc();
  if (iVar2 != 3) {
    Con_Printf("Usage:  hpkextract hpkname [all | single index]\n");
    goto LAB_00051132;
  }
  pcVar3 = Cmd_Argv(2);
  iVar2 = Q_stricmp(pcVar3,"all");
  if (iVar2 == 0) {
    pcVar3 = Cmd_Argv(1);
    pcVar12 = "%s";
    snprintf(local_32c,0x100,"%s",pcVar3);
    COM_DefaultExtension(local_32c,".hpk");
LAB_000514a7:
    pcVar3 = pcVar12;
    iVar2 = -1;
    Con_Printf("Extracting all lumps from %s.\n",local_32c);
  }
  else {
    pcVar3 = local_32c;
    pcVar12 = Cmd_Argv(2);
    iVar2 = Q_atoi(pcVar12);
    pcVar7 = Cmd_Argv(1);
    pcVar12 = "%s";
    snprintf(pcVar3,0x100,"%s",pcVar7);
    COM_DefaultExtension(pcVar3,".hpk");
    if (iVar2 == -1) goto LAB_000514a7;
    Con_Printf("Extracting lump %i from %s\n",iVar2,pcVar3);
  }
  pvVar4 = FS_Open(local_32c,"rb");
  if (pvVar4 == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_32c,pcVar3);
  }
  else {
    FS_Read(local_358,0xc,1,pvVar4);
    iVar5 = Q_strncmp(local_358,"HPAK",4);
    if (iVar5 == 0) {
      if (local_354 == 1) {
        FS_Seek(pvVar4,local_350,FILESYSTEM_SEEK_HEAD);
        FS_Read(&local_360,4,1,pvVar4);
        if (local_360 - 1U < 0x8000) {
          Con_Printf("# of Entries:  %i\n",local_360);
          Con_Printf("# Type Size FileName : MD5 Hash\n");
          local_35c = Mem_Malloc(local_360 * 0x90);
          FS_Read(local_35c,local_360 * 0x90,1,pvVar4);
          if (0 < local_360) {
            iVar11 = 0;
            iVar5 = local_360;
                    /* Unresolved local var: uchar * pData@[???]
                       Unresolved local var: int nDataSize@[???]
                       Unresolved local var: FileHandle_t fpOutput@[???]
                       Unresolved local var: char[260] szFileOut@[???] */
            do {
              if ((iVar11 == iVar2) || (iVar2 == -1)) {
                pcVar3 = (char *)(iVar11 * 0x90 + (int)local_35c);
                COM_FileBase(pcVar3,(char *)local_228);
                switch(*(undefined4 *)(pcVar3 + 0x40)) {
                case 0:
                  local_34c = 0x6e756f73;
                  local_348 = CONCAT22(local_348._2_2_,100);
                  break;
                case 1:
                  local_34c = 0x6e696b73;
                  local_348 = local_348 & 0xffffff00;
                  break;
                case 2:
                  local_34c = 0x65646f6d;
                  local_348 = CONCAT22(local_348._2_2_,0x6c);
                  break;
                case 3:
                  local_34c = 0x61636564;
                  local_348 = CONCAT22(local_348._2_2_,0x6c);
                  break;
                case 4:
                  local_34c = 0x656e6567;
                  local_348 = 0x636972;
                  break;
                case 5:
                  local_34c = 0x6e657665;
                  local_348 = CONCAT22(local_348._2_2_,0x74);
                  break;
                default:
                  local_34c = CONCAT22(local_34c._2_2_,0x3f);
                }
                puVar13 = &local_34c;
                puVar15 = local_228;
                dVar14 = (double)((float)*(int *)(pcVar3 + 0x48) * 0.0009765625);
                Con_Printf("Extracting %i: %10s %.2fK %s\n",iVar11 + 1,puVar13,dVar14,puVar15);
                iVar5 = *(int *)(pcVar3 + 0x8c);
                if (iVar5 - 1U < 0x1ffff) {
                  pvVar8 = Mem_Malloc(iVar5 + 1);
                  Q_memset(pvVar8,0,iVar5);
                  FS_Seek(pvVar4,*(int *)(pcVar3 + 0x88),FILESYSTEM_SEEK_HEAD);
                  FS_Read(pvVar8,iVar5,1,pvVar4);
                  __snprintf_chk(local_124,0x104,1,0x104,"hpklmps\\lmp%04i.wad",iVar11);
                  COM_FixSlashes((char *)local_124);
                  COM_CreatePath((char *)local_124);
                  pvVar9 = FS_Open((char *)local_124,"wb");
                  if (pvVar9 == (FileHandle_t)0x0) {
                    Con_Printf("Error creating lump file %s\n",local_124);
                  }
                  else {
                    FS_Write(pvVar8,iVar5,1,pvVar9);
                    FS_Close(pvVar9);
                  }
                  iVar5 = local_360;
                  if (pvVar8 != (void *)0x0) {
                    Mem_Free(pvVar8);
                    iVar5 = local_360;
                  }
                }
                else {
                  Con_Printf("Unable to extract data, size invalid:  %s\n",iVar5,puVar13,dVar14,
                             puVar15);
                  iVar5 = local_360;
                }
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 < iVar5);
          }
          FS_Close(pvVar4);
          Mem_Free(local_35c);
        }
        else {
          Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_360);
          FS_Close(pvVar4);
        }
      }
      else {
        Con_Printf("hpkextract:  version mismatch\n");
        FS_Close(pvVar4);
      }
    }
    else {
      Con_Printf("%s is not an HPAK file\n",local_32c);
      FS_Close(pvVar4);
    }
  }
LAB_00051132:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_000517f0:
  iVar2 = iVar2 + 1;
  if ((int)local_368 <= iVar2) goto LAB_00051c4d;
  goto LAB_000517fb;
}


// HPAK_FindResource  @ 0004d070
qboolean HPAK_FindResource(hash_pack_directory_t *pDir,uchar *hash,resource_s *pResourceEntry)

{
  char *pcVar1;
  hash_pack_entry_t *phVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < pDir->nEntries) {
    iVar7 = 0;
    iVar6 = 0;
    do {
      iVar4 = Q_memcmp(hash,(pDir->p_rgEntries->resource).rgucMD5_hash + iVar7,0x10);
      if (iVar4 == 0) {
        if (pResourceEntry != (resource_s *)0x0) {
          phVar2 = pDir->p_rgEntries;
          uVar5 = 0;
          do {
            pcVar1 = (phVar2->resource).szFileName + uVar5 + iVar7;
            uVar3 = *(undefined4 *)(pcVar1 + 4);
            *(undefined4 *)(pResourceEntry->szFileName + uVar5) = *(undefined4 *)pcVar1;
            *(undefined4 *)(pResourceEntry->szFileName + uVar5 + 4) = uVar3;
            uVar5 = uVar5 + 8;
          } while (uVar5 < 0x88);
        }
        return true;
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0x90;
    } while (iVar6 < pDir->nEntries);
  }
  return false;
}


// HPAK_FlushHostQueue  @ 0004e360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_FlushHostQueue(void)

{
  hash_pack_queue_t *p;
  
  p = gp_hpak_queue;
  while (p != (hash_pack_queue_t *)0x0) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
    gp_hpak_queue = p->next;
    HPAK_AddLump(false,p->pakname,&p->resource,p->data,(FileHandle_t)0x0);
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    p = gp_hpak_queue;
  }
  gp_hpak_queue = p;
  return;
}


// HPAK_GetDataPointer  @ 0004cc40
qboolean HPAK_GetDataPointer(char *pakname,resource_s *pResource,uchar **pbuffer,int *bufsize)

{
  hash_pack_queue_s *phVar1;
  size_t size;
  FileHandle_t file;
  int iVar2;
  qboolean qVar3;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  int local_138;
  void *local_134;
  char local_130 [4];
  int local_12c;
  int local_128;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: qboolean retval@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bfound@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (pbuffer != (uchar **)0x0) {
    *pbuffer = (uchar *)0x0;
  }
  if (bufsize != (int *)0x0) {
    *bufsize = 0;
  }
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
  for (phVar1 = gp_hpak_queue; phVar1 != (hash_pack_queue_t *)0x0; phVar1 = phVar1->next) {
    iVar2 = Q_stricmp(phVar1->pakname,pakname);
    if ((iVar2 == 0) &&
       (iVar2 = Q_memcmp((phVar1->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10), iVar2 == 0))
    {
      if (pbuffer != (uchar **)0x0) {
                    /* Unresolved local var: uchar * pbuf@[???] */
        puVar5 = Mem_Malloc(phVar1->datasize);
        if (puVar5 == (uchar *)0x0) {
          Sys_Error("Error allocating %i bytes for hpak!",phVar1->datasize);
        }
        Q_memcpy(puVar5,phVar1->data,phVar1->datasize);
        *pbuffer = puVar5;
      }
      if (bufsize == (int *)0x0) {
        qVar3 = true;
      }
      else {
        *bufsize = phVar1->datasize;
        qVar3 = true;
      }
      goto LAB_0004cdfb;
    }
  }
  snprintf(local_124,0x100,"%s",pakname);
  COM_DefaultExtension(local_124,".hpk");
  file = FS_Open(local_124,"rb");
  if (file == (FileHandle_t)0x0) {
    qVar3 = false;
  }
  else {
    FS_Read(local_130,0xc,1,file);
    iVar2 = Q_strncmp(local_130,"HPAK",4);
    if (iVar2 == 0) {
      if (local_12c == 1) {
        FS_Seek(file,local_128,FILESYSTEM_SEEK_HEAD);
        FS_Read(&local_138,4,1,file);
        if (local_138 - 1U < 0x8000) {
          local_134 = Mem_ZeroMalloc(local_138 * 0x90);
          FS_Read(local_134,local_138 * 0x90,1,file);
          if (0 < local_138) {
            iVar6 = 0;
            iVar2 = 0;
            do {
              iVar7 = (int)local_134 + iVar6;
              iVar4 = Q_memcmp((void *)(iVar7 + 0x4d),pResource->rgucMD5_hash,0x10);
              if (iVar4 == 0) {
                FS_Seek(file,*(int *)(iVar7 + 0x88),FILESYSTEM_SEEK_HEAD);
                if (((pbuffer == (uchar **)0x0) || (iVar7 == 0)) ||
                   (size = *(size_t *)(iVar7 + 0x8c), (int)size < 1)) {
                  qVar3 = true;
                  goto LAB_0004cfae;
                }
                if (bufsize == (int *)0x0) {
                  puVar5 = Mem_Malloc(size);
                  if (puVar5 == (uchar *)0x0) {
                    qVar3 = false;
                    Con_Printf("Couln\'t allocate %i bytes for HPAK entry\n",
                               *(undefined4 *)(iVar7 + 0x8c));
                    goto LAB_0004cfae;
                  }
                }
                else {
                  *bufsize = size;
                  puVar5 = Mem_Malloc(*(size_t *)(iVar7 + 0x8c));
                  if (puVar5 == (uchar *)0x0) {
                    qVar3 = false;
                    Con_Printf("Couln\'t allocate %i bytes for HPAK entry\n",
                               *(undefined4 *)(iVar7 + 0x8c));
                    *bufsize = 0;
                    goto LAB_0004cfae;
                  }
                }
                qVar3 = true;
                FS_Read(puVar5,*(int *)(iVar7 + 0x8c),1,file);
                *pbuffer = puVar5;
                goto LAB_0004cfae;
              }
              iVar2 = iVar2 + 1;
              iVar6 = iVar6 + 0x90;
            } while (iVar2 < local_138);
          }
                    /* Unresolved local var: uchar * p@[???] */
          qVar3 = false;
LAB_0004cfae:
          Mem_Free(local_134);
          FS_Close(file);
        }
        else {
          Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_138);
          FS_Close(file);
          qVar3 = false;
        }
      }
      else {
        Con_Printf("HPAK_List:  version mismatch\n");
        FS_Close(file);
        qVar3 = false;
      }
    }
    else {
      Con_Printf("%s is not an HPAK file\n",local_124);
      FS_Close(file);
      qVar3 = false;
    }
  }
LAB_0004cdfb:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// HPAK_GetItem  @ 00051ec0
char * HPAK_GetItem(int item)

{
  uchar *hash;
  undefined4 *puVar1;
  uchar *buf;
  undefined4 uVar2;
  hash_pack_queue_t *p;
  FileHandle_t pvVar3;
  int iVar4;
  char *pcVar5;
  FileHandle_t dst;
  uint uVar6;
  int iVar7;
  int iVar8;
  void *pInput;
  undefined4 *puVar9;
  int in_GS_OFFSET;
  int local_354;
  void *local_34c;
  uint local_33c;
  void *local_338;
  int local_334;
  void *local_330;
  char local_32c [260];
  uchar local_228 [4];
  int local_224;
  int local_220;
  MD5Context_t local_124 [2];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
                    /* Unresolved local var: hash_pack_queue_t * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t iRead@[???]
                       Unresolved local var: FileHandle_t iWrite@[???]
                       Unresolved local var: int cmp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t olddirectory@[???]
                       Unresolved local var: hash_pack_directory_t newdirectory@[???]
                       Unresolved local var: qboolean bExact@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: hash_pack_entry_t * pNewEntry@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  p = gp_hpak_queue;
  do {
    if (p == (hash_pack_queue_t *)0x0) {
      builtin_strncpy(HPAK_GetItem::name,"custom",7);
      gp_hpak_queue = p;
      COM_DefaultExtension(HPAK_GetItem::name,".hpk");
      pvVar3 = FS_Open(HPAK_GetItem::name,"rb");
      if (pvVar3 == (FileHandle_t)0x0) {
        pcVar5 = "";
      }
      else {
        FS_Read(local_228,0xc,1,pvVar3);
        iVar4 = Q_strncmp((char *)local_228,"HPAK",4);
        if (iVar4 == 0) {
          if (local_224 == 1) {
            FS_Seek(pvVar3,local_220,FILESYSTEM_SEEK_HEAD);
            FS_Read(&local_334,4,1,pvVar3);
            if (local_334 - 1U < 0x8000) {
              local_330 = Mem_Malloc(local_334 * 0x90);
              FS_Read(local_330,local_334 * 0x90,1,pvVar3);
              iVar4 = local_334 + -1;
              if (item < local_334 + -1) {
                iVar4 = item;
              }
              pcVar5 = (char *)(iVar4 * 0x90 + (int)local_330);
              COM_FileBase(pcVar5,(char *)local_124);
              pcVar5 = MD5_Print((uchar *)(pcVar5 + 0x4d));
              __snprintf_chk(HPAK_GetItem::name,0x104,1,0x104,"!MD5%s",pcVar5);
              FS_Close(pvVar3);
              Mem_Free(local_330);
              pcVar5 = HPAK_GetItem::name;
            }
            else {
              Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_334);
              FS_Close(pvVar3);
              pcVar5 = "";
            }
          }
          else {
            Con_Printf("HPAK_List:  version mismatch\n");
            FS_Close(pvVar3);
            pcVar5 = "";
          }
        }
        else {
          Con_Printf("%s is not an HPAK file\n",HPAK_GetItem::name);
          FS_Close(pvVar3);
          pcVar5 = "";
        }
      }
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return pcVar5;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    gp_hpak_queue = p->next;
    pcVar5 = p->pakname;
    if (pcVar5 == (char *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
    }
    else {
      buf = p->data;
      if (buf == (uchar *)0x0) {
        Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
      }
      else {
        iVar4 = (p->resource).nDownloadSize;
        if (iVar4 - 0x400U < 0x1fc01) {
          Q_memset(local_124,0,0x58);
          MD5Init(local_124);
          MD5Update(local_124,buf,(p->resource).nDownloadSize);
          MD5Final(local_228,local_124);
          hash = (p->resource).rgucMD5_hash;
          iVar4 = Q_memcmp(hash,local_228,0x10);
          if (iVar4 == 0) {
            snprintf(local_32c,0x100,"%s",pcVar5);
            COM_DefaultExtension(local_32c,".hpk");
            COM_FixSlashes(local_32c);
            Q_strncpy((char *)local_124,local_32c,0xff);
            local_25 = 0;
            pvVar3 = FS_Open(local_32c,"rb");
            if (pvVar3 == (FileHandle_t)0x0) {
              HPAK_CreatePak(pcVar5,&p->resource,buf,(FileHandle_t)0x0);
            }
            else {
              COM_StripExtension(local_32c,(char *)local_228);
              COM_DefaultExtension((char *)local_228,".hp2");
              dst = FS_Open((char *)local_228,"w+b");
              if (dst == (FileHandle_t)0x0) {
                FS_Close(pvVar3);
                Con_Printf("ERROR: couldn\'t open %s.\n",local_32c);
              }
              else {
                FS_Read(&hash_pack_header,0xc,1,pvVar3);
                if (hash_pack_header.version == 1) {
                  FS_Seek(pvVar3,0,FILESYSTEM_SEEK_HEAD);
                  uVar6 = FS_Size(pvVar3);
                  COM_CopyFileChunk(dst,pvVar3,uVar6);
                  FS_Seek(pvVar3,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                  FS_Read(&local_33c,4,1,pvVar3);
                  if (local_33c < 0x8001) {
                    local_338 = Mem_Malloc((local_33c * 9 + 9) * 0x10);
                    FS_Read(local_338,local_33c * 0x90,1,pvVar3);
                    FS_Close(pvVar3);
                    /* Unresolved local var: int i@[???] */
                    if (0 < (int)local_33c) {
                      iVar4 = 0;
                      local_354 = 0;
                      do {
                        iVar7 = Q_memcmp(hash,(void *)((int)local_338 + iVar4 + 0x4d),0x10);
                        if (iVar7 == 0) {
                          FS_Close(dst);
                          FS_Unlink((char *)local_228);
                          Mem_Free(local_338);
                          goto LAB_00051f00;
                        }
                        local_354 = local_354 + 1;
                        iVar4 = iVar4 + 0x90;
                      } while (local_354 < (int)local_33c);
                    }
                    local_334 = local_33c + 1;
                    local_330 = Mem_Malloc(local_334 * 0x90);
                    Q_memset(local_330,0,local_334 * 0x90);
                    Q_memcpy(local_330,local_338,local_33c * 0x90);
                    if (0 < (int)local_33c) {
                      iVar4 = 0;
LAB_0005260b:
                      iVar7 = iVar4 * 0x90;
                      iVar8 = Q_memcmp(hash,(void *)((int)local_338 + iVar7 + 0x4d),0x10);
                      if (-1 < iVar8) break;
                      local_34c = (void *)((int)local_330 + iVar7);
                      for (; iVar4 < (int)local_33c; iVar4 = iVar4 + 1) {
                        uVar6 = 0;
                        do {
                          puVar1 = (undefined4 *)((int)local_338 + uVar6 + iVar7);
                          uVar2 = puVar1[1];
                          puVar9 = (undefined4 *)((int)local_330 + uVar6 + iVar7 + 0x90);
                          uVar6 = uVar6 + 8;
                          *puVar9 = *puVar1;
                          puVar9[1] = uVar2;
                        } while (uVar6 < 0x90);
                        iVar7 = iVar7 + 0x90;
                      }
                      if (local_34c == (void *)0x0) goto LAB_000526ef;
                      goto LAB_00052708;
                    }
LAB_000526ef:
                    local_34c = (void *)((int)local_330 + local_334 * 0x90 + -0x90);
LAB_00052708:
                    Q_memset(local_34c,0,0x90);
                    FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                    uVar6 = 0;
                    do {
                      uVar2 = *(undefined4 *)((p->resource).szFileName + uVar6 + 4);
                      *(undefined4 *)((int)local_34c + uVar6) =
                           *(undefined4 *)((p->resource).szFileName + uVar6);
                      *(undefined4 *)((int)local_34c + uVar6 + 4) = uVar2;
                      uVar6 = uVar6 + 8;
                    } while (uVar6 < 0x88);
                    uVar6 = FS_Tell(dst);
                    *(uint *)((int)local_34c + 0x88) = uVar6;
                    iVar4 = (p->resource).nDownloadSize;
                    *(int *)((int)local_34c + 0x8c) = iVar4;
                    FS_Write(buf,iVar4,1,dst);
                    hash_pack_header.nDirectoryOffset = FS_Tell(dst);
                    FS_Write(&local_334,4,1,dst);
                    if (0 < local_334) {
                      iVar7 = 0;
                      iVar4 = 0;
                      do {
                        iVar7 = iVar7 + 1;
                        pInput = (void *)((int)local_330 + iVar4);
                        iVar4 = iVar4 + 0x90;
                        FS_Write(pInput,0x90,1,dst);
                      } while (iVar7 < local_334);
                    }
                    if (local_330 != (void *)0x0) {
                      Mem_Free(local_330);
                    }
                    if (local_338 != (void *)0x0) {
                      Mem_Free(local_338);
                    }
                    FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
                    FS_Write(&hash_pack_header,0xc,1,dst);
                    FS_Close(dst);
                    FS_Unlink((char *)local_124);
                    FS_Rename((char *)local_228,(char *)local_124);
                  }
                  else {
                    Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_33c);
                    FS_Close(pvVar3);
                    FS_Close(dst);
                    FS_Unlink((char *)local_228);
                  }
                }
                else {
                  FS_Close(pvVar3);
                  FS_Close(dst);
                  FS_Unlink((char *)local_228);
                  Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
                }
              }
            }
          }
          else {
            Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
            pcVar5 = MD5_Print(hash);
            Con_Printf("Purported:  %s\n",pcVar5);
            pcVar5 = MD5_Print(local_228);
            Con_Printf("Actual   :  %s\n",pcVar5);
            Con_Printf("Ignoring lump addition\n");
          }
        }
        else {
          Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",iVar4);
        }
      }
    }
LAB_00051f00:
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    p = gp_hpak_queue;
  } while( true );
  iVar4 = iVar4 + 1;
  if ((int)local_33c <= iVar4) goto LAB_000526ef;
  goto LAB_0005260b;
}


// HPAK_Init  @ 00051e50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Init(void)

{
  Cmd_AddCommand("hpklist",HPAK_List_f);
  Cmd_AddCommand("hpkremove",HPAK_Remove_f);
  Cmd_AddCommand("hpkval",HPAK_Validate_f);
  Cmd_AddCommand("hpkextract",HPAK_Extract_f);
  gp_hpak_queue = (hash_pack_queue_t *)0x0;
  return;
}


// HPAK_List_f  @ 0004f9f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_List_f(void)

{
  uchar *hash;
  undefined4 *puVar1;
  uchar *buf;
  undefined4 uVar2;
  char *pcVar3;
  FileHandle_t pvVar4;
  int iVar5;
  FileHandle_t dst;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  void *pInput;
  undefined4 *puVar10;
  hash_pack_queue_t *p;
  int in_GS_OFFSET;
  int local_364;
  void *local_35c;
  uint local_348;
  void *local_344;
  int local_340;
  void *local_33c;
  char local_338 [4];
  int local_334;
  int local_330;
  undefined4 local_32c;
  uint local_328;
  uchar local_228 [260];
  MD5Context_t local_124 [2];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
    if (gp_hpak_queue != (hash_pack_queue_t *)0x0) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t iRead@[???]
                       Unresolved local var: FileHandle_t iWrite@[???]
                       Unresolved local var: int cmp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t olddirectory@[???]
                       Unresolved local var: hash_pack_directory_t newdirectory@[???]
                       Unresolved local var: qboolean bExact@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: hash_pack_entry_t * pNewEntry@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
      p = gp_hpak_queue;
      do {
        gp_hpak_queue = p->next;
        pcVar3 = p->pakname;
        if (pcVar3 == (char *)0x0) {
          Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
        }
        else {
          buf = p->data;
          if (buf == (uchar *)0x0) {
            Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
          }
          else {
            iVar5 = (p->resource).nDownloadSize;
            if (iVar5 - 0x400U < 0x1fc01) {
              Q_memset(local_124,0,0x58);
              MD5Init(local_124);
              MD5Update(local_124,buf,(p->resource).nDownloadSize);
              MD5Final(local_228,local_124);
              hash = (p->resource).rgucMD5_hash;
              iVar5 = Q_memcmp(hash,local_228,0x10);
              if (iVar5 == 0) {
                snprintf((char *)&local_32c,0x100,"%s",pcVar3);
                COM_DefaultExtension((char *)&local_32c,".hpk");
                COM_FixSlashes((char *)&local_32c);
                Q_strncpy((char *)local_124,(char *)&local_32c,0xff);
                local_25 = 0;
                pvVar4 = FS_Open((char *)&local_32c,"rb");
                if (pvVar4 == (FileHandle_t)0x0) {
                  HPAK_CreatePak(pcVar3,&p->resource,buf,(FileHandle_t)0x0);
                }
                else {
                  COM_StripExtension((char *)&local_32c,(char *)local_228);
                  COM_DefaultExtension((char *)local_228,".hp2");
                  dst = FS_Open((char *)local_228,"w+b");
                  if (dst == (FileHandle_t)0x0) {
                    FS_Close(pvVar4);
                    Con_Printf("ERROR: couldn\'t open %s.\n",&local_32c);
                  }
                  else {
                    FS_Read(&hash_pack_header,0xc,1,pvVar4);
                    if (hash_pack_header.version == 1) {
                      FS_Seek(pvVar4,0,FILESYSTEM_SEEK_HEAD);
                      uVar6 = FS_Size(pvVar4);
                      COM_CopyFileChunk(dst,pvVar4,uVar6);
                      FS_Seek(pvVar4,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                      FS_Read(&local_348,4,1,pvVar4);
                      if (local_348 < 0x8001) {
                        local_344 = Mem_Malloc((local_348 * 9 + 9) * 0x10);
                        FS_Read(local_344,local_348 * 0x90,1,pvVar4);
                        FS_Close(pvVar4);
                    /* Unresolved local var: int i@[???] */
                        if (0 < (int)local_348) {
                          iVar5 = 0;
                          local_364 = 0;
                          do {
                            iVar8 = Q_memcmp(hash,(void *)((int)local_344 + iVar5 + 0x4d),0x10);
                            if (iVar8 == 0) {
                              FS_Close(dst);
                              FS_Unlink((char *)local_228);
                              Mem_Free(local_344);
                              goto LAB_0004fa70;
                            }
                            local_364 = local_364 + 1;
                            iVar5 = iVar5 + 0x90;
                          } while (local_364 < (int)local_348);
                        }
                        local_340 = local_348 + 1;
                        local_33c = Mem_Malloc(local_340 * 0x90);
                        Q_memset(local_33c,0,local_340 * 0x90);
                        Q_memcpy(local_33c,local_344,local_348 * 0x90);
                        if (0 < (int)local_348) {
                          iVar5 = 0;
LAB_0005021b:
                          iVar8 = iVar5 * 0x90;
                          iVar9 = Q_memcmp(hash,(void *)((int)local_344 + iVar8 + 0x4d),0x10);
                          if (-1 < iVar9) goto LAB_00050210;
                          local_35c = (void *)((int)local_33c + iVar8);
                          for (; iVar5 < (int)local_348; iVar5 = iVar5 + 1) {
                            uVar6 = 0;
                            do {
                              puVar1 = (undefined4 *)((int)local_33c + uVar6 + iVar8 + 0x90);
                              puVar10 = (undefined4 *)((int)local_344 + uVar6 + iVar8);
                              uVar6 = uVar6 + 8;
                              uVar2 = puVar10[1];
                              *puVar1 = *puVar10;
                              puVar1[1] = uVar2;
                            } while (uVar6 < 0x90);
                            iVar8 = iVar8 + 0x90;
                          }
                          if (local_35c == (void *)0x0) goto LAB_00050300;
                          goto LAB_00050319;
                        }
LAB_00050300:
                        local_35c = (void *)((int)local_33c + local_340 * 0x90 + -0x90);
LAB_00050319:
                        Q_memset(local_35c,0,0x90);
                        FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                        uVar6 = 0;
                        do {
                          uVar2 = *(undefined4 *)((p->resource).szFileName + uVar6);
                          *(undefined4 *)((int)local_35c + uVar6 + 4) =
                               *(undefined4 *)((p->resource).szFileName + uVar6 + 4);
                          *(undefined4 *)((int)local_35c + uVar6) = uVar2;
                          uVar6 = uVar6 + 8;
                        } while (uVar6 < 0x88);
                        uVar6 = FS_Tell(dst);
                        *(uint *)((int)local_35c + 0x88) = uVar6;
                        iVar5 = (p->resource).nDownloadSize;
                        *(int *)((int)local_35c + 0x8c) = iVar5;
                        FS_Write(buf,iVar5,1,dst);
                        hash_pack_header.nDirectoryOffset = FS_Tell(dst);
                        FS_Write(&local_340,4,1,dst);
                        if (0 < local_340) {
                          iVar5 = 0;
                          iVar8 = 0;
                          do {
                            iVar8 = iVar8 + 1;
                            pInput = (void *)((int)local_33c + iVar5);
                            iVar5 = iVar5 + 0x90;
                            FS_Write(pInput,0x90,1,dst);
                          } while (iVar8 < local_340);
                        }
                        if (local_33c != (void *)0x0) {
                          Mem_Free(local_33c);
                        }
                        if (local_344 != (void *)0x0) {
                          Mem_Free(local_344);
                        }
                        FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
                        FS_Write(&hash_pack_header,0xc,1,dst);
                        FS_Close(dst);
                        FS_Unlink((char *)local_124);
                        FS_Rename((char *)local_228,(char *)local_124);
                      }
                      else {
                        Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_348);
                        FS_Close(pvVar4);
                        FS_Close(dst);
                        FS_Unlink((char *)local_228);
                      }
                    }
                    else {
                      FS_Close(pvVar4);
                      FS_Close(dst);
                      FS_Unlink((char *)local_228);
                      Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
                    }
                  }
                }
              }
              else {
                Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
                pcVar3 = MD5_Print(hash);
                Con_Printf("Purported:  %s\n",pcVar3);
                pcVar3 = MD5_Print(local_228);
                Con_Printf("Actual   :  %s\n",pcVar3);
                Con_Printf("Ignoring lump addition\n");
              }
            }
            else {
              Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",iVar5);
            }
          }
        }
LAB_0004fa70:
        Mem_Free(p->pakname);
        Mem_Free(p->data);
        Mem_Free(p);
        p = gp_hpak_queue;
      } while (gp_hpak_queue != (hash_pack_queue_t *)0x0);
    }
    pcVar3 = Cmd_Argv(1);
    snprintf((char *)local_228,0x100,"%s",pcVar3);
    COM_DefaultExtension((char *)local_228,".hpk");
    Con_Printf("Contents for %s.\n",local_228);
    pvVar4 = FS_Open((char *)local_228,"rb");
    if (pvVar4 == (FileHandle_t)0x0) {
      Con_Printf("ERROR: couldn\'t open %s.\n",local_228);
    }
    else {
      FS_Read(local_338,0xc,1,pvVar4);
      iVar5 = Q_strncmp(local_338,"HPAK",4);
      if (iVar5 == 0) {
        if (local_334 == 1) {
          FS_Seek(pvVar4,local_330,FILESYSTEM_SEEK_HEAD);
          FS_Read(&local_340,4,1,pvVar4);
          if (local_340 - 1U < 0x8000) {
            Con_Printf("# of Entries:  %i\n",local_340);
            Con_Printf("# Type Size FileName : MD5 Hash\n");
            local_33c = Mem_Malloc(local_340 * 0x90);
            FS_Read(local_33c,local_340 * 0x90,1,pvVar4);
            if (0 < local_340) {
              iVar5 = 0;
              do {
                pcVar3 = (char *)(iVar5 * 0x90 + (int)local_33c);
                COM_FileBase(pcVar3,(char *)local_124);
                switch(*(undefined4 *)(pcVar3 + 0x40)) {
                case 0:
                  local_32c = 0x6e756f73;
                  local_328 = CONCAT22(local_328._2_2_,100);
                  break;
                case 1:
                  local_32c = 0x6e696b73;
                  local_328 = local_328 & 0xffffff00;
                  break;
                case 2:
                  local_32c = 0x65646f6d;
                  local_328 = CONCAT22(local_328._2_2_,0x6c);
                  break;
                case 3:
                  local_32c = 0x61636564;
                  local_328 = CONCAT22(local_328._2_2_,0x6c);
                  break;
                case 4:
                  local_32c = 0x656e6567;
                  local_328 = 0x636972;
                  break;
                case 5:
                  local_32c = 0x6e657665;
                  local_328 = CONCAT22(local_328._2_2_,0x74);
                  break;
                default:
                  local_32c = CONCAT22(local_32c._2_2_,0x3f);
                }
                iVar5 = iVar5 + 1;
                pcVar7 = MD5_Print((uchar *)(pcVar3 + 0x4d));
                Con_Printf("%i: %10s %.2fK %s\n  :  %s\n",iVar5,&local_32c,
                           (double)((float)*(int *)(pcVar3 + 0x48) * 0.0009765625),local_124,pcVar7)
                ;
              } while (iVar5 < local_340);
            }
            FS_Close(pvVar4);
            Mem_Free(local_33c);
          }
          else {
            Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_340);
            FS_Close(pvVar4);
          }
        }
        else {
          Con_Printf("HPAK_List:  version mismatch\n");
          FS_Close(pvVar4);
        }
      }
      else {
        Con_Printf("%s is not an HPAK file\n",local_228);
        FS_Close(pvVar4);
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00050210:
  iVar5 = iVar5 + 1;
  if ((int)local_348 <= iVar5) goto LAB_00050300;
  goto LAB_0005021b;
}


// HPAK_RemoveLump  @ 0004e3e0
void HPAK_RemoveLump(char *pakname,resource_s *pResource)

{
  uchar *hash;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  char *pcVar5;
  FileHandle_t pvVar6;
  FileHandle_t pvVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  void *pvVar11;
  int iVar12;
  int iVar13;
  hash_pack_queue_t *p;
  int in_GS_OFFSET;
  resource_s *__s;
  uchar *puVar14;
  resource_t *prVar15;
  FileHandle_t file;
  int local_34c;
  resource_s *local_33c;
  void *local_338;
  char *local_334;
  void *local_330;
  resource_s local_32c;
  uchar local_228 [260];
  MD5Context_t local_124 [2];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: FileHandle_t tmp@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t hash_pack_dir@[???]
                       Unresolved local var: hash_pack_directory_t newdir@[???]
                       Unresolved local var: hash_pack_entry_t * oldentry@[???]
                       Unresolved local var: hash_pack_entry_t * newentry@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bFound@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((pakname == (char *)0x0) || (*pakname == '\0')) || (pResource == (resource_s *)0x0)) {
    Con_Printf("HPAK_RemoveLump:  Invalid arguments\n");
    goto LAB_0004e4cc;
  }
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
  __s = &local_32c;
  p = gp_hpak_queue;
  while (p != (hash_pack_queue_t *)0x0) {
    gp_hpak_queue = p->next;
    pcVar5 = p->pakname;
    if (pcVar5 == (char *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
    }
    else {
      puVar14 = p->data;
      if (puVar14 == (uchar *)0x0) {
        Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
      }
      else {
        iVar8 = (p->resource).nDownloadSize;
        if (iVar8 - 0x400U < 0x1fc01) {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
          Q_memset(local_124,0,0x58);
          MD5Init(local_124);
          MD5Update(local_124,puVar14,(p->resource).nDownloadSize);
          MD5Final(local_228,local_124);
          prVar15 = &p->resource;
          hash = (p->resource).rgucMD5_hash;
          iVar8 = Q_memcmp(hash,local_228,0x10);
          if (iVar8 == 0) {
            snprintf(__s->szFileName,0x100,"%s",pcVar5,__s,pResource,prVar15);
            COM_DefaultExtension(__s->szFileName,".hpk");
            COM_FixSlashes(__s->szFileName);
            Q_strncpy((char *)local_124,__s->szFileName,0xff);
            local_25 = 0;
            pvVar6 = FS_Open(__s->szFileName,"rb");
            if (pvVar6 == (FileHandle_t)0x0) {
              HPAK_CreatePak(pcVar5,&p->resource,puVar14,(FileHandle_t)0x0);
            }
            else {
              COM_StripExtension(__s->szFileName,(char *)local_228);
              COM_DefaultExtension((char *)local_228,".hp2");
              pvVar7 = FS_Open((char *)local_228,"w+b");
              if (pvVar7 == (FileHandle_t)0x0) {
                FS_Close(pvVar6);
                Con_Printf("ERROR: couldn\'t open %s.\n",__s);
              }
              else {
                FS_Read(&hash_pack_header,0xc,1,pvVar6);
                if (hash_pack_header.version == 1) {
                  FS_Seek(pvVar6,0,FILESYSTEM_SEEK_HEAD);
                  uVar10 = FS_Size(pvVar6);
                  COM_CopyFileChunk(pvVar7,pvVar6,uVar10);
                  FS_Seek(pvVar6,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                  FS_Read(&local_33c,4,1,pvVar6);
                  if (local_33c < (resource_s *)0x8001) {
                    local_338 = Mem_Malloc(((int)local_33c * 9 + 9) * 0x10);
                    FS_Read(local_338,(int)local_33c * 0x90,1,pvVar6);
                    FS_Close(pvVar6);
                    /* Unresolved local var: int i@[???] */
                    if (0 < (int)local_33c) {
                      iVar13 = 0;
                      iVar8 = 0;
                      do {
                        iVar9 = Q_memcmp(hash,(void *)((int)local_338 + iVar13 + 0x4d),0x10);
                        if (iVar9 == 0) {
                          FS_Close(pvVar7);
                          FS_Unlink((char *)local_228);
                          Mem_Free(local_338);
                          goto LAB_0004e460;
                        }
                        iVar8 = iVar8 + 1;
                        iVar13 = iVar13 + 0x90;
                      } while (iVar8 < (int)local_33c);
                    }
                    local_334 = local_33c->szFileName + 1;
                    local_330 = Mem_Malloc((int)local_334 * 0x90);
                    Q_memset(local_330,0,(int)local_334 * 0x90);
                    Q_memcpy(local_330,local_338,(int)local_33c * 0x90);
                    if (0 < (int)local_33c) {
                      iVar8 = 0;
                      local_34c = 0;
LAB_0004ebf1:
                      iVar13 = Q_memcmp(hash,(void *)((int)local_338 + iVar8 + 0x4d),0x10);
                      if (-1 < iVar13) goto LAB_0004ebe0;
                      pvVar11 = (void *)(iVar8 + (int)local_330);
                      if (local_34c < (int)local_33c) {
                        iVar8 = local_34c * 0x90;
                        do {
                          uVar10 = 0;
                          do {
                            puVar1 = (undefined4 *)((int)local_338 + uVar10 + iVar8);
                            puVar2 = (undefined4 *)((int)local_330 + uVar10 + iVar8 + 0x90);
                            uVar10 = uVar10 + 8;
                            uVar3 = puVar1[1];
                            *puVar2 = *puVar1;
                            puVar2[1] = uVar3;
                          } while (uVar10 < 0x90);
                          local_34c = local_34c + 1;
                          iVar8 = iVar8 + 0x90;
                        } while (local_34c < (int)local_33c);
                      }
                      if (pvVar11 == (void *)0x0) goto LAB_0004efab;
                      goto LAB_0004efc4;
                    }
LAB_0004efab:
                    pvVar11 = (void *)((int)local_330 + (int)local_334 * 0x90 + -0x90);
LAB_0004efc4:
                    Q_memset(pvVar11,0,0x90);
                    FS_Seek(pvVar7,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                    uVar10 = 0;
                    do {
                      uVar3 = *(undefined4 *)((p->resource).szFileName + uVar10);
                      *(undefined4 *)((int)pvVar11 + uVar10 + 4) =
                           *(undefined4 *)((p->resource).szFileName + uVar10 + 4);
                      *(undefined4 *)((int)pvVar11 + uVar10) = uVar3;
                      uVar10 = uVar10 + 8;
                    } while (uVar10 < 0x88);
                    uVar10 = FS_Tell(pvVar7);
                    *(uint *)((int)pvVar11 + 0x88) = uVar10;
                    iVar8 = (p->resource).nDownloadSize;
                    *(int *)((int)pvVar11 + 0x8c) = iVar8;
                    iVar13 = 0;
                    FS_Write(puVar14,iVar8,1,pvVar7);
                    hash_pack_header.nDirectoryOffset = FS_Tell(pvVar7);
                    FS_Write(&local_334,4,1,pvVar7);
                    if (0 < (int)local_334) {
                      iVar8 = 0;
                      do {
                        iVar13 = iVar13 + 1;
                        pvVar11 = (void *)((int)local_330 + iVar8);
                        iVar8 = iVar8 + 0x90;
                        FS_Write(pvVar11,0x90,1,pvVar7);
                      } while (iVar13 < (int)local_334);
                    }
                    if (local_330 != (void *)0x0) {
                      Mem_Free(local_330);
                    }
                    if (local_338 != (void *)0x0) {
                      Mem_Free(local_338);
                    }
                    FS_Seek(pvVar7,0,FILESYSTEM_SEEK_HEAD);
                    FS_Write(&hash_pack_header,0xc,1,pvVar7);
                    FS_Close(pvVar7);
                    FS_Unlink((char *)local_124);
                    FS_Rename((char *)local_228,(char *)local_124);
                  }
                  else {
                    Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_33c);
                    FS_Close(pvVar6);
                    FS_Close(pvVar7);
                    FS_Unlink((char *)local_228);
                  }
                }
                else {
                  FS_Close(pvVar6);
                  FS_Close(pvVar7);
                  FS_Unlink((char *)local_228);
                  Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
                }
              }
            }
          }
          else {
            Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
            pcVar5 = MD5_Print(hash);
            Con_Printf("Purported:  %s\n",pcVar5);
            pcVar5 = MD5_Print(local_228);
            Con_Printf("Actual   :  %s\n",pcVar5);
            Con_Printf("Ignoring lump addition\n");
          }
        }
        else {
          Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",iVar8);
        }
      }
    }
LAB_0004e460:
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    p = gp_hpak_queue;
  }
  gp_hpak_queue = p;
  pcVar5 = Cmd_Argv(1);
  snprintf(__s->szFileName,0x100,"%s",pcVar5);
  COM_DefaultExtension(__s->szFileName,".hpk");
  Q_strncpy((char *)local_124,__s->szFileName,0xff);
  local_25 = 0;
  pvVar6 = FS_Open((char *)local_124,"rb");
  if (pvVar6 == (FileHandle_t)0x0) {
    Con_Printf("Error:  couldn\'t open HPAK file %s for removal.\n",__s);
    goto LAB_0004e4cc;
  }
  COM_StripExtension(__s->szFileName,(char *)local_228);
  COM_DefaultExtension((char *)local_228,".hp2");
  pvVar7 = FS_Open((char *)local_228,"w+b");
  if (pvVar7 == (FileHandle_t)0x0) {
    FS_Close(pvVar6);
    Con_Printf("ERROR: couldn\'t create %s.\n",local_228);
    goto LAB_0004e4cc;
  }
  FS_Seek(pvVar6,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(pvVar7,0,FILESYSTEM_SEEK_HEAD);
  FS_Read(&hash_pack_header,0xc,1,pvVar6);
  FS_Write(&hash_pack_header,0xc,1,pvVar7);
  iVar8 = Q_strncmp(hash_pack_header.szFileStamp,"HPAK",4);
  if (iVar8 == 0) {
    if (hash_pack_header.version == 1) {
      FS_Seek(pvVar6,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
      FS_Read(&local_33c,4,1,pvVar6);
      if ((undefined1 *)((int)&local_33c[-1].pPrev + 3U) < (undefined1 *)0x8000) {
        if (local_33c == (resource_s *)0x1) {
          Con_Printf("Removing final lump from HPAK, deleting HPAK:\n  %s\n",local_124);
          FS_Close(pvVar7);
          FS_Close(pvVar6);
          FS_Unlink((char *)local_228);
          FS_Unlink((char *)local_124);
          goto LAB_0004e4cc;
        }
        local_338 = Mem_Malloc((int)local_33c * 0x90);
        FS_Read(local_338,(int)local_33c * 0x90,1,pvVar6);
        local_334 = (char *)((int)&local_33c[-1].pPrev + 3);
        local_330 = Mem_Malloc((int)local_334 * 0x90);
                    /* Unresolved local var: int i@[???] */
        puVar14 = pResource->rgucMD5_hash;
        if (0 < (int)local_33c) {
          iVar13 = 0;
          iVar8 = 0;
          do {
            iVar9 = Q_memcmp(puVar14,(void *)((int)local_338 + iVar13 + 0x4d),0x10);
            if (iVar9 == 0) {
              Con_Printf("Removing %s from HPAK %s.\n",pResource,__s);
              if (0 < (int)local_33c) {
                iVar13 = 0;
                iVar8 = 0;
                file = pvVar6;
                do {
                  pvVar11 = local_338;
                  iVar9 = Q_memcmp((void *)((int)local_338 + iVar13 * 0x90 + 0x4d),puVar14,0x10);
                  pvVar4 = local_330;
                  pvVar6 = file;
                  if (iVar9 != 0) {
                    iVar9 = iVar8 + 1;
                    uVar10 = 0;
                    do {
                      uVar3 = *(undefined4 *)((int)pvVar11 + uVar10 + iVar13 * 0x90);
                      *(undefined4 *)((int)local_330 + uVar10 + iVar8 * 0x90 + 4) =
                           *(undefined4 *)((int)pvVar11 + uVar10 + iVar13 * 0x90 + 4);
                      *(undefined4 *)((int)local_330 + uVar10 + iVar8 * 0x90) = uVar3;
                      uVar10 = uVar10 + 8;
                    } while (uVar10 < 0x90);
                    uVar10 = FS_Tell(pvVar7);
                    *(uint *)((int)pvVar4 + iVar8 * 0x90 + 0x88) = uVar10;
                    pvVar6 = file;
                    FS_Seek(file,*(int *)((int)pvVar11 + iVar13 * 0x90 + 0x88),FILESYSTEM_SEEK_HEAD)
                    ;
                    iVar12 = iVar8 * 0x90;
                    iVar8 = iVar9;
                    COM_CopyFileChunk(pvVar7,file,*(int *)((int)pvVar4 + iVar12 + 0x8c));
                  }
                  iVar13 = iVar13 + 1;
                  file = pvVar6;
                } while (iVar13 < (int)local_33c);
              }
              hash_pack_header.nDirectoryOffset = FS_Tell(pvVar7);
              iVar8 = 0;
              FS_Write(&local_334,4,1,pvVar7);
              if (0 < (int)local_334) {
                iVar13 = 0;
                do {
                  iVar8 = iVar8 + 1;
                  pvVar11 = (void *)((int)local_330 + iVar13);
                  iVar13 = iVar13 + 0x90;
                  FS_Write(pvVar11,0x90,1,pvVar7);
                } while (iVar8 < (int)local_334);
              }
              FS_Seek(pvVar7,0,FILESYSTEM_SEEK_HEAD);
              FS_Write(&hash_pack_header,0xc,1,pvVar7);
              FS_Close(pvVar7);
              FS_Close(pvVar6);
              FS_Unlink((char *)local_124);
              FS_Rename((char *)local_228,(char *)local_124);
              Mem_Free(local_330);
              Mem_Free(local_338);
              goto LAB_0004e4cc;
            }
            iVar8 = iVar8 + 1;
            iVar13 = iVar13 + 0x90;
          } while (iVar8 < (int)local_33c);
        }
        pcVar5 = "ERROR: HPAK doesn\'t contain specified lump:  %s\n";
        __s = pResource;
      }
      else {
        pcVar5 = "ERROR: HPAK had bogus # of directory entries:  %i\n";
        __s = local_33c;
      }
      goto LAB_0004e9eb;
    }
    Con_Printf("ERROR: HPAK version outdated\n");
  }
  else {
    pcVar5 = "%s is not an HPAK file\n";
LAB_0004e9eb:
    Con_Printf(pcVar5,__s);
  }
  FS_Close(pvVar7);
  FS_Close(pvVar6);
  FS_Unlink((char *)local_228);
LAB_0004e4cc:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0004ebe0:
  local_34c = local_34c + 1;
  iVar8 = iVar8 + 0x90;
  if ((int)local_33c <= local_34c) goto LAB_0004efab;
  goto LAB_0004ebf1;
}


// HPAK_Remove_f  @ 0004f170
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Remove_f(void)

{
  uchar *hash;
  undefined4 *puVar1;
  uchar *buf;
  undefined4 uVar2;
  hash_pack_queue_t *p;
  int iVar3;
  FileHandle_t file;
  FileHandle_t dst;
  char *pcVar4;
  char *str;
  uint uVar5;
  int iVar6;
  int iVar7;
  qboolean qVar8;
  void *pInput;
  undefined4 *puVar9;
  int in_GS_OFFSET;
  int local_354;
  void *local_34c;
  uint local_33c;
  void *local_338;
  int local_334;
  void *local_330;
  char local_32c [260];
  uchar local_228 [260];
  resource_s local_124;
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: resource_t resource@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
                    /* Unresolved local var: hash_pack_queue_t * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t iRead@[???]
                       Unresolved local var: FileHandle_t iWrite@[???]
                       Unresolved local var: int cmp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t olddirectory@[???]
                       Unresolved local var: hash_pack_directory_t newdirectory@[???]
                       Unresolved local var: qboolean bExact@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: hash_pack_entry_t * pNewEntry@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
    p = gp_hpak_queue;
    while (p != (hash_pack_queue_t *)0x0) {
      gp_hpak_queue = p->next;
      pcVar4 = p->pakname;
      if (pcVar4 == (char *)0x0) {
        Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
      }
      else {
        buf = p->data;
        if (buf == (uchar *)0x0) {
          Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
        }
        else {
          iVar3 = (p->resource).nDownloadSize;
          if (iVar3 - 0x400U < 0x1fc01) {
            Q_memset(&local_124,0,0x58);
            MD5Init((MD5Context_t *)&local_124);
            MD5Update((MD5Context_t *)&local_124,buf,(p->resource).nDownloadSize);
            MD5Final(local_228,(MD5Context_t *)&local_124);
            hash = (p->resource).rgucMD5_hash;
            iVar3 = Q_memcmp(hash,local_228,0x10);
            if (iVar3 == 0) {
              snprintf(local_32c,0x100,"%s",pcVar4);
              COM_DefaultExtension(local_32c,".hpk");
              COM_FixSlashes(local_32c);
              Q_strncpy(local_124.szFileName,local_32c,0xff);
              local_25 = 0;
              file = FS_Open(local_32c,"rb");
              if (file == (FileHandle_t)0x0) {
                HPAK_CreatePak(pcVar4,&p->resource,buf,(FileHandle_t)0x0);
              }
              else {
                COM_StripExtension(local_32c,(char *)local_228);
                COM_DefaultExtension((char *)local_228,".hp2");
                dst = FS_Open((char *)local_228,"w+b");
                if (dst == (FileHandle_t)0x0) {
                  FS_Close(file);
                  Con_Printf("ERROR: couldn\'t open %s.\n",local_32c);
                }
                else {
                  FS_Read(&hash_pack_header,0xc,1,file);
                  if (hash_pack_header.version == 1) {
                    FS_Seek(file,0,FILESYSTEM_SEEK_HEAD);
                    uVar5 = FS_Size(file);
                    COM_CopyFileChunk(dst,file,uVar5);
                    FS_Seek(file,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                    FS_Read(&local_33c,4,1,file);
                    if (local_33c < 0x8001) {
                      local_338 = Mem_Malloc((local_33c * 9 + 9) * 0x10);
                      FS_Read(local_338,local_33c * 0x90,1,file);
                      FS_Close(file);
                    /* Unresolved local var: int i@[???] */
                      if (0 < (int)local_33c) {
                        iVar3 = 0;
                        local_354 = 0;
                        do {
                          iVar6 = Q_memcmp(hash,(void *)((int)local_338 + iVar3 + 0x4d),0x10);
                          if (iVar6 == 0) {
                            FS_Close(dst);
                            FS_Unlink((char *)local_228);
                            Mem_Free(local_338);
                            goto LAB_0004f200;
                          }
                          local_354 = local_354 + 1;
                          iVar3 = iVar3 + 0x90;
                        } while (local_354 < (int)local_33c);
                      }
                      local_334 = local_33c + 1;
                      local_330 = Mem_Malloc(local_334 * 0x90);
                      Q_memset(local_330,0,local_334 * 0x90);
                      Q_memcpy(local_330,local_338,local_33c * 0x90);
                      if (0 < (int)local_33c) {
                        iVar3 = 0;
LAB_0004f70b:
                        iVar6 = iVar3 * 0x90;
                        iVar7 = Q_memcmp(hash,(void *)((int)local_338 + iVar6 + 0x4d),0x10);
                        if (-1 < iVar7) goto LAB_0004f700;
                        local_34c = (void *)((int)local_330 + iVar6);
                        for (; iVar3 < (int)local_33c; iVar3 = iVar3 + 1) {
                          uVar5 = 0;
                          do {
                            puVar1 = (undefined4 *)((int)local_338 + uVar5 + iVar6);
                            uVar2 = puVar1[1];
                            puVar9 = (undefined4 *)((int)local_330 + uVar5 + iVar6 + 0x90);
                            uVar5 = uVar5 + 8;
                            *puVar9 = *puVar1;
                            puVar9[1] = uVar2;
                          } while (uVar5 < 0x90);
                          iVar6 = iVar6 + 0x90;
                        }
                        if (local_34c == (void *)0x0) goto LAB_0004f824;
                        goto LAB_0004f83d;
                      }
LAB_0004f824:
                      local_34c = (void *)((int)local_330 + local_334 * 0x90 + -0x90);
LAB_0004f83d:
                      Q_memset(local_34c,0,0x90);
                      FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                      uVar5 = 0;
                      do {
                        uVar2 = *(undefined4 *)((p->resource).szFileName + uVar5 + 4);
                        *(undefined4 *)((int)local_34c + uVar5) =
                             *(undefined4 *)((p->resource).szFileName + uVar5);
                        *(undefined4 *)((int)local_34c + uVar5 + 4) = uVar2;
                        uVar5 = uVar5 + 8;
                      } while (uVar5 < 0x88);
                      uVar5 = FS_Tell(dst);
                      *(uint *)((int)local_34c + 0x88) = uVar5;
                      iVar3 = (p->resource).nDownloadSize;
                      *(int *)((int)local_34c + 0x8c) = iVar3;
                      FS_Write(buf,iVar3,1,dst);
                      hash_pack_header.nDirectoryOffset = FS_Tell(dst);
                      FS_Write(&local_334,4,1,dst);
                      if (0 < local_334) {
                        iVar6 = 0;
                        iVar3 = 0;
                        do {
                          iVar6 = iVar6 + 1;
                          pInput = (void *)((int)local_330 + iVar3);
                          iVar3 = iVar3 + 0x90;
                          FS_Write(pInput,0x90,1,dst);
                        } while (iVar6 < local_334);
                      }
                      if (local_330 != (void *)0x0) {
                        Mem_Free(local_330);
                      }
                      if (local_338 != (void *)0x0) {
                        Mem_Free(local_338);
                      }
                      FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
                      FS_Write(&hash_pack_header,0xc,1,dst);
                      FS_Close(dst);
                      FS_Unlink(local_124.szFileName);
                      FS_Rename((char *)local_228,local_124.szFileName);
                    }
                    else {
                      Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_33c);
                      FS_Close(file);
                      FS_Close(dst);
                      FS_Unlink((char *)local_228);
                    }
                  }
                  else {
                    FS_Close(file);
                    FS_Close(dst);
                    FS_Unlink((char *)local_228);
                    Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
                  }
                }
              }
            }
            else {
              Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
              pcVar4 = MD5_Print(hash);
              Con_Printf("Purported:  %s\n",pcVar4);
              pcVar4 = MD5_Print(local_228);
              Con_Printf("Actual   :  %s\n",pcVar4);
              Con_Printf("Ignoring lump addition\n");
            }
          }
          else {
            Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",iVar3);
          }
        }
      }
LAB_0004f200:
      Mem_Free(p->pakname);
      Mem_Free(p->data);
      Mem_Free(p);
      p = gp_hpak_queue;
    }
    gp_hpak_queue = p;
    iVar3 = Cmd_Argc();
    if (iVar3 == 3) {
      pcVar4 = Cmd_Argv(2);
      iVar3 = Q_atoi(pcVar4);
      pcVar4 = Cmd_Argv(1);
                    /* Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
      if (cmd_source == src_command) {
        qVar8 = HPAK_ResourceForIndex(pcVar4,iVar3,&local_124);
        if (qVar8 != false) {
          pcVar4 = Cmd_Argv(1);
          HPAK_RemoveLump(pcVar4,&local_124);
          goto LAB_0004f192;
        }
      }
      pcVar4 = Cmd_Argv(1);
      str = Cmd_Argv(2);
      iVar3 = Q_atoi(str);
      Con_Printf("Could not locate resource %i in %s\n",iVar3,pcVar4);
    }
    else {
      Con_Printf("Usage:  hpkremove <hpk> <index>\n");
    }
  }
LAB_0004f192:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0004f700:
  iVar3 = iVar3 + 1;
  if ((int)local_33c <= iVar3) goto LAB_0004f824;
  goto LAB_0004f70b;
}


// HPAK_ResourceForHash  @ 0004d290
qboolean HPAK_ResourceForHash(char *pakname,uchar *hash,resource_s *pResourceEntry)

{
  undefined4 *puVar1;
  hash_pack_queue_s *phVar2;
  undefined4 uVar3;
  FileHandle_t file;
  int iVar4;
  qboolean qVar5;
  int iVar6;
  uint uVar7;
  int in_GS_OFFSET;
  int local_140;
  int local_138;
  void *local_134;
  char local_130 [4];
  int local_12c;
  int local_128;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: qboolean bFound@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  for (phVar2 = gp_hpak_queue; phVar2 != (hash_pack_queue_t *)0x0; phVar2 = phVar2->next) {
    iVar4 = Q_stricmp(phVar2->pakname,pakname);
    if ((iVar4 == 0) && (iVar4 = Q_memcmp((phVar2->resource).rgucMD5_hash,hash,0x10), iVar4 == 0)) {
      uVar7 = 0;
      if (pResourceEntry != (resource_s *)0x0) {
        do {
          uVar3 = *(undefined4 *)((phVar2->resource).szFileName + uVar7 + 4);
          *(undefined4 *)(pResourceEntry->szFileName + uVar7) =
               *(undefined4 *)((phVar2->resource).szFileName + uVar7);
          *(undefined4 *)(pResourceEntry->szFileName + uVar7 + 4) = uVar3;
          uVar7 = uVar7 + 8;
        } while (uVar7 < 0x88);
      }
      qVar5 = true;
      goto LAB_0004d3e7;
    }
  }
  snprintf(local_124,0x100,"%s",pakname);
  COM_DefaultExtension(local_124,".hpk");
  file = FS_Open(local_124,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_124);
    qVar5 = false;
  }
  else {
    FS_Read(local_130,0xc,1,file);
    iVar4 = Q_strncmp(local_130,"HPAK",4);
    if (iVar4 == 0) {
      if (local_12c == 1) {
        FS_Seek(file,local_128,FILESYSTEM_SEEK_HEAD);
        FS_Read(&local_138,4,1,file);
        if (local_138 - 1U < 0x8000) {
                    /* Unresolved local var: int i@[???] */
          iVar4 = 0;
          local_134 = Mem_Malloc(local_138 * 0x90);
          FS_Read(local_134,local_138 * 0x90,1,file);
          local_140 = 0;
          if (0 < local_138) {
LAB_0004d49c:
            iVar6 = Q_memcmp(hash,(void *)((int)local_134 + iVar4 + 0x4d),0x10);
            if (iVar6 != 0) goto code_r0x0004d4be;
            if (pResourceEntry != (resource_s *)0x0) {
              uVar7 = 0;
              do {
                puVar1 = (undefined4 *)((int)local_134 + uVar7 + iVar4);
                uVar3 = puVar1[1];
                *(undefined4 *)(pResourceEntry->szFileName + uVar7) = *puVar1;
                *(undefined4 *)(pResourceEntry->szFileName + uVar7 + 4) = uVar3;
                uVar7 = uVar7 + 8;
              } while (uVar7 < 0x88);
            }
            qVar5 = true;
            goto LAB_0004d53f;
          }
LAB_0004d4d2:
          qVar5 = false;
LAB_0004d53f:
          FS_Close(file);
          Mem_Free(local_134);
        }
        else {
          Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_138);
          FS_Close(file);
          qVar5 = false;
        }
      }
      else {
        Con_Printf("HPAK_List:  version mismatch\n");
        FS_Close(file);
        qVar5 = false;
      }
    }
    else {
      Con_Printf("%s is not an HPAK file\n",local_124);
      FS_Close(file);
      qVar5 = false;
    }
  }
LAB_0004d3e7:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x0004d4be:
  local_140 = local_140 + 1;
  iVar4 = iVar4 + 0x90;
  if (local_138 <= local_140) goto LAB_0004d4d2;
  goto LAB_0004d49c;
}


// HPAK_ResourceForIndex  @ 0004c9b0
qboolean __regparm3 HPAK_ResourceForIndex(char *pakname,int nIndex,resource_s *pResource)

{
  undefined4 uVar1;
  FileHandle_t file;
  int iVar2;
  qboolean qVar3;
  uint uVar4;
  int in_GS_OFFSET;
  int local_138;
  void *local_134;
  char local_130 [4];
  int local_12c;
  int local_128;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  snprintf(local_124,0x100,"%s",pakname);
  COM_DefaultExtension(local_124,".hpk");
  file = FS_Open(local_124,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_124);
    qVar3 = false;
  }
  else {
    FS_Read(local_130,0xc,1,file);
    iVar2 = Q_strncmp(local_130,"HPAK",4);
    if (iVar2 == 0) {
      if (local_12c == 1) {
        FS_Seek(file,local_128,FILESYSTEM_SEEK_HEAD);
        FS_Read(&local_138,4,1,file);
        if (local_138 - 1U < 0x8000) {
          local_134 = Mem_Malloc(local_138 * 0x90);
          if ((nIndex < 1) || (local_138 < nIndex)) {
            Con_Printf("ERROR: HPAK bogus directory entry request:  %i\n",nIndex);
            FS_Close(file);
            qVar3 = false;
          }
          else {
            FS_Read(local_134,local_138 * 0x90,1,file);
            uVar4 = 0;
            do {
              uVar1 = *(undefined4 *)((int)local_134 + uVar4 + nIndex * 0x90 + -0x8c);
              *(undefined4 *)(pResource->szFileName + uVar4) =
                   *(undefined4 *)((int)local_134 + uVar4 + nIndex * 0x90 + -0x90);
              *(undefined4 *)(pResource->szFileName + uVar4 + 4) = uVar1;
              uVar4 = uVar4 + 8;
            } while (uVar4 < 0x88);
            FS_Close(file);
            Mem_Free(local_134);
            qVar3 = true;
          }
        }
        else {
          Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_138);
          FS_Close(file);
          qVar3 = false;
        }
      }
      else {
        Con_Printf("HPAK_List:  version mismatch\n");
        FS_Close(file);
        qVar3 = false;
      }
    }
    else {
      Con_Printf("%s is not an HPAK file\n",local_124);
      FS_Close(file);
      qVar3 = false;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// HPAK_ResourceForIndex  @ 0004d260
qboolean HPAK_ResourceForIndex(char *pakname,int nIndex,resource_s *pResource)

{
  qboolean qVar1;
  
                    /* Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  if (cmd_source != src_command) {
    return false;
  }
  qVar1 = HPAK_ResourceForIndex(pakname,nIndex,pResource);
  return qVar1;
}


// HPAK_ValidatePak  @ 00052a60
void HPAK_ValidatePak(char *fullpakname)

{
  uchar *hash;
  undefined4 *puVar1;
  undefined4 uVar2;
  FileHandle_t pvVar3;
  FileHandle_t dst;
  int iVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  void *pInput;
  undefined4 *puVar9;
  hash_pack_queue_t *p;
  char *pcVar10;
  int in_GS_OFFSET;
  int local_364;
  void *local_360;
  uint local_348;
  void *local_344;
  int local_340;
  void *local_33c;
  char local_338 [4];
  int local_334;
  int local_330;
  uchar local_32c [260];
  MD5Context_t local_228 [2];
  MD5Context_t local_124 [2];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (gp_hpak_queue != (hash_pack_queue_t *)0x0) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t iRead@[???]
                       Unresolved local var: FileHandle_t iWrite@[???]
                       Unresolved local var: int cmp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t olddirectory@[???]
                       Unresolved local var: hash_pack_directory_t newdirectory@[???]
                       Unresolved local var: qboolean bExact@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: hash_pack_entry_t * pNewEntry@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
    p = gp_hpak_queue;
    do {
      gp_hpak_queue = p->next;
      pcVar10 = p->pakname;
      if (pcVar10 == (char *)0x0) {
        Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
      }
      else {
        puVar7 = p->data;
        if (puVar7 == (uchar *)0x0) {
          Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
        }
        else {
          iVar4 = (p->resource).nDownloadSize;
          if (iVar4 - 0x400U < 0x1fc01) {
            Q_memset(local_124,0,0x58);
            MD5Init(local_124);
            MD5Update(local_124,puVar7,(p->resource).nDownloadSize);
            MD5Final((uchar *)local_228,local_124);
            hash = (p->resource).rgucMD5_hash;
            iVar4 = Q_memcmp(hash,local_228,0x10);
            if (iVar4 == 0) {
              snprintf((char *)local_32c,0x100,"%s",pcVar10);
              COM_DefaultExtension((char *)local_32c,".hpk");
              COM_FixSlashes((char *)local_32c);
              Q_strncpy((char *)local_124,(char *)local_32c,0xff);
              local_25 = 0;
              pvVar3 = FS_Open((char *)local_32c,"rb");
              if (pvVar3 == (FileHandle_t)0x0) {
                HPAK_CreatePak(pcVar10,&p->resource,puVar7,(FileHandle_t)0x0);
              }
              else {
                COM_StripExtension((char *)local_32c,(char *)local_228);
                COM_DefaultExtension((char *)local_228,".hp2");
                dst = FS_Open((char *)local_228,"w+b");
                if (dst == (FileHandle_t)0x0) {
                  FS_Close(pvVar3);
                  Con_Printf("ERROR: couldn\'t open %s.\n",local_32c);
                }
                else {
                  FS_Read(&hash_pack_header,0xc,1,pvVar3);
                  if (hash_pack_header.version == 1) {
                    FS_Seek(pvVar3,0,FILESYSTEM_SEEK_HEAD);
                    uVar5 = FS_Size(pvVar3);
                    COM_CopyFileChunk(dst,pvVar3,uVar5);
                    FS_Seek(pvVar3,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                    FS_Read(&local_348,4,1,pvVar3);
                    if (local_348 < 0x8001) {
                      local_344 = Mem_Malloc((local_348 * 9 + 9) * 0x10);
                      FS_Read(local_344,local_348 * 0x90,1,pvVar3);
                      FS_Close(pvVar3);
                    /* Unresolved local var: int i@[???] */
                      if (0 < (int)local_348) {
                        iVar4 = 0;
                        local_364 = 0;
                        do {
                          iVar8 = Q_memcmp(hash,(void *)((int)local_344 + iVar4 + 0x4d),0x10);
                          if (iVar8 == 0) {
                            FS_Close(dst);
                            FS_Unlink((char *)local_228);
                            Mem_Free(local_344);
                            goto LAB_00052ab0;
                          }
                          local_364 = local_364 + 1;
                          iVar4 = iVar4 + 0x90;
                        } while (local_364 < (int)local_348);
                      }
                      local_340 = local_348 + 1;
                      local_33c = Mem_Malloc(local_340 * 0x90);
                      Q_memset(local_33c,0,local_340 * 0x90);
                      Q_memcpy(local_33c,local_344,local_348 * 0x90);
                      if (0 < (int)local_348) {
                        iVar4 = 0;
LAB_00053153:
                        iVar8 = iVar4 * 0x90;
                        iVar6 = Q_memcmp(hash,(void *)((int)local_344 + iVar8 + 0x4d),0x10);
                        if (-1 < iVar6) goto LAB_00053148;
                        local_360 = (void *)((int)local_33c + iVar8);
                        for (; iVar4 < (int)local_348; iVar4 = iVar4 + 1) {
                          uVar5 = 0;
                          do {
                            puVar1 = (undefined4 *)((int)local_344 + uVar5 + iVar8);
                            uVar2 = puVar1[1];
                            puVar9 = (undefined4 *)((int)local_33c + uVar5 + iVar8 + 0x90);
                            uVar5 = uVar5 + 8;
                            *puVar9 = *puVar1;
                            puVar9[1] = uVar2;
                          } while (uVar5 < 0x90);
                          iVar8 = iVar8 + 0x90;
                        }
                        if (local_360 == (void *)0x0) goto LAB_00053395;
                        goto LAB_000533ae;
                      }
LAB_00053395:
                      local_360 = (void *)((int)local_33c + local_340 * 0x90 + -0x90);
LAB_000533ae:
                      Q_memset(local_360,0,0x90);
                      FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                      uVar5 = 0;
                      do {
                        uVar2 = *(undefined4 *)((p->resource).szFileName + uVar5);
                        *(undefined4 *)((int)local_360 + uVar5 + 4) =
                             *(undefined4 *)((p->resource).szFileName + uVar5 + 4);
                        *(undefined4 *)((int)local_360 + uVar5) = uVar2;
                        uVar5 = uVar5 + 8;
                      } while (uVar5 < 0x88);
                      uVar5 = FS_Tell(dst);
                      *(uint *)((int)local_360 + 0x88) = uVar5;
                      iVar4 = (p->resource).nDownloadSize;
                      *(int *)((int)local_360 + 0x8c) = iVar4;
                      FS_Write(puVar7,iVar4,1,dst);
                      hash_pack_header.nDirectoryOffset = FS_Tell(dst);
                      FS_Write(&local_340,4,1,dst);
                      if (0 < local_340) {
                        iVar8 = 0;
                        iVar4 = 0;
                        do {
                          iVar8 = iVar8 + 1;
                          pInput = (void *)((int)local_33c + iVar4);
                          iVar4 = iVar4 + 0x90;
                          FS_Write(pInput,0x90,1,dst);
                        } while (iVar8 < local_340);
                      }
                      if (local_33c != (void *)0x0) {
                        Mem_Free(local_33c);
                      }
                      if (local_344 != (void *)0x0) {
                        Mem_Free(local_344);
                      }
                      FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
                      FS_Write(&hash_pack_header,0xc,1,dst);
                      FS_Close(dst);
                      FS_Unlink((char *)local_124);
                      FS_Rename((char *)local_228,(char *)local_124);
                    }
                    else {
                      Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_348);
                      FS_Close(pvVar3);
                      FS_Close(dst);
                      FS_Unlink((char *)local_228);
                    }
                  }
                  else {
                    FS_Close(pvVar3);
                    FS_Close(dst);
                    FS_Unlink((char *)local_228);
                    Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
                  }
                }
              }
            }
            else {
              Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
              pcVar10 = MD5_Print(hash);
              Con_Printf("Purported:  %s\n",pcVar10);
              pcVar10 = MD5_Print((uchar *)local_228);
              Con_Printf("Actual   :  %s\n",pcVar10);
              Con_Printf("Ignoring lump addition\n");
            }
          }
          else {
            Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",iVar4);
          }
        }
      }
LAB_00052ab0:
      Mem_Free(p->pakname);
      Mem_Free(p->data);
      Mem_Free(p);
      p = gp_hpak_queue;
    } while (gp_hpak_queue != (hash_pack_queue_t *)0x0);
  }
  pvVar3 = FS_Open(fullpakname,"rb");
  if (pvVar3 != (FileHandle_t)0x0) {
    FS_Read(local_338,0xc,1,pvVar3);
    if ((local_334 == 1) && (iVar4 = Q_strncmp(local_338,"HPAK",4), iVar4 == 0)) {
      FS_Seek(pvVar3,local_330,FILESYSTEM_SEEK_HEAD);
      FS_Read(&local_340,4,1,pvVar3);
      if (local_340 - 1U < 0x8000) {
        iVar4 = 0;
        local_33c = Mem_Malloc(local_340 * 0x90);
        FS_Read(local_33c,local_340 * 0x90,1,pvVar3);
        if (0 < local_340) {
          do {
            pcVar10 = (char *)(iVar4 * 0x90 + (int)local_33c);
            COM_FileBase(pcVar10,(char *)local_124);
                    /* Unresolved local var: uchar * pData@[???]
                       Unresolved local var: int nDataSize@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???]
                       Unresolved local var: int haderrors@[???] */
            uVar5 = *(uint *)(pcVar10 + 0x8c);
            if (0x1fffe < uVar5 - 1) {
              Mem_Free(local_33c);
              Con_Printf("Mismatched data in HPAK file %s, deleting\n",fullpakname);
              Con_Printf("Unable to MD5 hash data lump %i, size invalid:  %i\n",iVar4 + 1,uVar5);
LAB_00052f28:
              FS_Close(pvVar3);
              FS_RemoveFile(fullpakname,(char *)0x0);
              goto LAB_00052ba2;
            }
            puVar7 = Mem_Malloc(uVar5 + 1);
            Q_memset(puVar7,0,uVar5);
            FS_Seek(pvVar3,*(int *)(pcVar10 + 0x88),FILESYSTEM_SEEK_HEAD);
            FS_Read(puVar7,uVar5,1,pvVar3);
            Q_memset(local_228,0,0x58);
            MD5Init(local_228);
            MD5Update(local_228,puVar7,uVar5);
            MD5Final(local_32c,local_228);
            iVar8 = Q_memcmp(pcVar10 + 0x4d,local_32c,0x10);
            if (iVar8 != 0) {
              Con_Printf("Mismatched data in HPAK file %s, deleting\n",fullpakname);
              if (puVar7 == (uchar *)0x0) {
                Mem_Free(local_33c);
              }
              else {
                Mem_Free(puVar7);
                Mem_Free(local_33c);
              }
              goto LAB_00052f28;
            }
            if (puVar7 != (uchar *)0x0) {
              Mem_Free(puVar7);
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < local_340);
        }
        FS_Close(pvVar3);
        Mem_Free(local_33c);
        goto LAB_00052ba2;
      }
      Con_Printf("ERROR: HPAK %s had bogus # of directory entries:  %i, deleting\n",fullpakname,
                 local_340);
    }
    else {
      Con_Printf("%s is not a PAK file, deleting\n",fullpakname);
    }
    FS_Close(pvVar3);
    FS_RemoveFile(fullpakname,(char *)0x0);
  }
LAB_00052ba2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00053148:
  iVar4 = iVar4 + 1;
  if ((int)local_348 <= iVar4) goto LAB_00053395;
  goto LAB_00053153;
}


// HPAK_Validate_f  @ 000504d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Validate_f(void)

{
  uchar *hash;
  undefined4 uVar1;
  hash_pack_queue_t *p;
  int iVar2;
  FileHandle_t dst;
  char *pcVar3;
  FileHandle_t pvVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  void *pInput;
  undefined4 *puVar9;
  int in_GS_OFFSET;
  undefined4 *puVar10;
  double dVar11;
  MD5Context_t *pMVar12;
  int local_394;
  void *local_38c;
  uint local_378;
  void *local_374;
  int local_370;
  void *local_36c;
  char local_368 [4];
  int local_364;
  int local_360;
  uchar local_35c [16];
  undefined4 local_34c;
  uint local_348;
  MD5Context_t local_32c [2];
  uchar local_228 [260];
  MD5Context_t local_124 [2];
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cmd_source == src_command) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
                    /* Unresolved local var: hash_pack_queue_t * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: FileHandle_t iRead@[???]
                       Unresolved local var: FileHandle_t iWrite@[???]
                       Unresolved local var: int cmp@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int copysize@[???]
                       Unresolved local var: char[260] szTempName@[???]
                       Unresolved local var: char[260] szOriginalName@[???]
                       Unresolved local var: hash_pack_directory_t olddirectory@[???]
                       Unresolved local var: hash_pack_directory_t newdirectory@[???]
                       Unresolved local var: qboolean bExact@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: hash_pack_entry_t * pNewEntry@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
    p = gp_hpak_queue;
    while (p != (hash_pack_queue_t *)0x0) {
      gp_hpak_queue = p->next;
      pcVar3 = p->pakname;
      if (pcVar3 == (char *)0x0) {
        Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
      }
      else {
        puVar7 = p->data;
        if (puVar7 == (uchar *)0x0) {
          Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
        }
        else {
          iVar2 = (p->resource).nDownloadSize;
          if (iVar2 - 0x400U < 0x1fc01) {
            Q_memset(local_124,0,0x58);
            MD5Init(local_124);
            MD5Update(local_124,puVar7,(p->resource).nDownloadSize);
            MD5Final(local_228,local_124);
            hash = (p->resource).rgucMD5_hash;
            iVar2 = Q_memcmp(hash,local_228,0x10);
            if (iVar2 == 0) {
              snprintf((char *)local_32c,0x100,"%s",pcVar3);
              COM_DefaultExtension((char *)local_32c,".hpk");
              COM_FixSlashes((char *)local_32c);
              Q_strncpy((char *)local_124,(char *)local_32c,0xff);
              local_25 = 0;
              pvVar4 = FS_Open((char *)local_32c,"rb");
              if (pvVar4 == (FileHandle_t)0x0) {
                HPAK_CreatePak(pcVar3,&p->resource,puVar7,(FileHandle_t)0x0);
              }
              else {
                COM_StripExtension((char *)local_32c,(char *)local_228);
                COM_DefaultExtension((char *)local_228,".hp2");
                dst = FS_Open((char *)local_228,"w+b");
                if (dst == (FileHandle_t)0x0) {
                  FS_Close(pvVar4);
                  Con_Printf("ERROR: couldn\'t open %s.\n",local_32c);
                }
                else {
                  FS_Read(&hash_pack_header,0xc,1,pvVar4);
                  if (hash_pack_header.version == 1) {
                    FS_Seek(pvVar4,0,FILESYSTEM_SEEK_HEAD);
                    uVar5 = FS_Size(pvVar4);
                    COM_CopyFileChunk(dst,pvVar4,uVar5);
                    FS_Seek(pvVar4,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                    FS_Read(&local_378,4,1,pvVar4);
                    if (local_378 < 0x8001) {
                      local_374 = Mem_Malloc((local_378 * 9 + 9) * 0x10);
                      FS_Read(local_374,local_378 * 0x90,1,pvVar4);
                      FS_Close(pvVar4);
                    /* Unresolved local var: int i@[???] */
                      if (0 < (int)local_378) {
                        iVar2 = 0;
                        local_394 = 0;
                        do {
                          iVar8 = Q_memcmp(hash,(void *)((int)local_374 + iVar2 + 0x4d),0x10);
                          if (iVar8 == 0) {
                            FS_Close(dst);
                            FS_Unlink((char *)local_228);
                            Mem_Free(local_374);
                            goto LAB_00050560;
                          }
                          local_394 = local_394 + 1;
                          iVar2 = iVar2 + 0x90;
                        } while (local_394 < (int)local_378);
                      }
                      local_370 = local_378 + 1;
                      local_36c = Mem_Malloc(local_370 * 0x90);
                      Q_memset(local_36c,0,local_370 * 0x90);
                      Q_memcpy(local_36c,local_374,local_378 * 0x90);
                      if (0 < (int)local_378) {
                        iVar2 = 0;
LAB_00050afb:
                        iVar8 = iVar2 * 0x90;
                        iVar6 = Q_memcmp(hash,(void *)((int)local_374 + iVar8 + 0x4d),0x10);
                        if (-1 < iVar6) goto LAB_00050af0;
                        local_38c = (void *)((int)local_36c + iVar8);
                        for (; iVar2 < (int)local_378; iVar2 = iVar2 + 1) {
                          uVar5 = 0;
                          do {
                            puVar10 = (undefined4 *)((int)local_374 + uVar5 + iVar8);
                            uVar1 = puVar10[1];
                            puVar9 = (undefined4 *)((int)local_36c + uVar5 + iVar8 + 0x90);
                            uVar5 = uVar5 + 8;
                            *puVar9 = *puVar10;
                            puVar9[1] = uVar1;
                          } while (uVar5 < 0x90);
                          iVar8 = iVar8 + 0x90;
                        }
                        if (local_38c == (void *)0x0) goto LAB_00050f49;
                        goto LAB_00050f62;
                      }
LAB_00050f49:
                      local_38c = (void *)((int)local_36c + local_370 * 0x90 + -0x90);
LAB_00050f62:
                      Q_memset(local_38c,0,0x90);
                      FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
                      uVar5 = 0;
                      do {
                        uVar1 = *(undefined4 *)((p->resource).szFileName + uVar5 + 4);
                        *(undefined4 *)((int)local_38c + uVar5) =
                             *(undefined4 *)((p->resource).szFileName + uVar5);
                        *(undefined4 *)((int)local_38c + uVar5 + 4) = uVar1;
                        uVar5 = uVar5 + 8;
                      } while (uVar5 < 0x88);
                      uVar5 = FS_Tell(dst);
                      *(uint *)((int)local_38c + 0x88) = uVar5;
                      iVar2 = (p->resource).nDownloadSize;
                      *(int *)((int)local_38c + 0x8c) = iVar2;
                      iVar8 = 0;
                      FS_Write(puVar7,iVar2,1,dst);
                      hash_pack_header.nDirectoryOffset = FS_Tell(dst);
                      FS_Write(&local_370,4,1,dst);
                      if (0 < local_370) {
                        iVar2 = 0;
                        do {
                          iVar2 = iVar2 + 1;
                          pInput = (void *)((int)local_36c + iVar8);
                          iVar8 = iVar8 + 0x90;
                          FS_Write(pInput,0x90,1,dst);
                        } while (iVar2 < local_370);
                      }
                      if (local_36c != (void *)0x0) {
                        Mem_Free(local_36c);
                      }
                      if (local_374 != (void *)0x0) {
                        Mem_Free(local_374);
                      }
                      FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
                      FS_Write(&hash_pack_header,0xc,1,dst);
                      FS_Close(dst);
                      FS_Unlink((char *)local_124);
                      FS_Rename((char *)local_228,(char *)local_124);
                    }
                    else {
                      Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_378);
                      FS_Close(pvVar4);
                      FS_Close(dst);
                      FS_Unlink((char *)local_228);
                    }
                  }
                  else {
                    FS_Close(pvVar4);
                    FS_Close(dst);
                    FS_Unlink((char *)local_228);
                    Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
                  }
                }
              }
            }
            else {
              Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
              pcVar3 = MD5_Print(hash);
              Con_Printf("Purported:  %s\n",pcVar3);
              pcVar3 = MD5_Print(local_228);
              Con_Printf("Actual   :  %s\n",pcVar3);
              Con_Printf("Ignoring lump addition\n");
            }
          }
          else {
            Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",iVar2);
          }
        }
      }
LAB_00050560:
      Mem_Free(p->pakname);
      Mem_Free(p->data);
      Mem_Free(p);
      p = gp_hpak_queue;
    }
    gp_hpak_queue = p;
    iVar2 = Cmd_Argc();
    if (iVar2 == 2) {
      pcVar3 = Cmd_Argv(1);
      snprintf((char *)local_228,0x100,"%s",pcVar3);
      COM_DefaultExtension((char *)local_228,".hpk");
      Con_Printf("Validating %s.\n",local_228);
      pvVar4 = FS_Open((char *)local_228,"rb");
      if (pvVar4 == (FileHandle_t)0x0) {
        Con_Printf("ERROR: couldn\'t open %s.\n",local_228);
      }
      else {
        FS_Read(local_368,0xc,1,pvVar4);
        iVar2 = Q_strncmp(local_368,"HPAK",4);
        if (iVar2 == 0) {
          if (local_364 == 1) {
            FS_Seek(pvVar4,local_360,FILESYSTEM_SEEK_HEAD);
            FS_Read(&local_370,4,1,pvVar4);
            if (local_370 - 1U < 0x8000) {
              Con_Printf("# of Entries:  %i\n",local_370);
              Con_Printf("# Type Size FileName : MD5 Hash\n");
              local_36c = Mem_Malloc(local_370 * 0x90);
              FS_Read(local_36c,local_370 * 0x90,1,pvVar4);
              if (0 < local_370) {
                iVar2 = 0;
                local_394 = 0;
                    /* Unresolved local var: uchar * pData@[???]
                       Unresolved local var: int nDataSize@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
                do {
                  pcVar3 = (char *)(local_394 + (int)local_36c);
                  COM_FileBase(pcVar3,(char *)local_124);
                  switch(*(undefined4 *)(pcVar3 + 0x40)) {
                  case 0:
                    local_34c = 0x6e756f73;
                    local_348 = CONCAT22(local_348._2_2_,100);
                    break;
                  case 1:
                    local_34c = 0x6e696b73;
                    local_348 = local_348 & 0xffffff00;
                    break;
                  case 2:
                    local_34c = 0x65646f6d;
                    local_348 = CONCAT22(local_348._2_2_,0x6c);
                    break;
                  case 3:
                    local_34c = 0x61636564;
                    local_348 = CONCAT22(local_348._2_2_,0x6c);
                    break;
                  case 4:
                    local_34c = 0x656e6567;
                    local_348 = 0x636972;
                    break;
                  case 5:
                    local_34c = 0x6e657665;
                    local_348 = CONCAT22(local_348._2_2_,0x74);
                    break;
                  default:
                    local_34c = CONCAT22(local_34c._2_2_,0x3f);
                  }
                  pMVar12 = local_124;
                  iVar2 = iVar2 + 1;
                  dVar11 = (double)((float)*(int *)(pcVar3 + 0x48) * 0.0009765625);
                  puVar10 = &local_34c;
                  Con_Printf("%i: %10s %.2fK %s:  ",iVar2,&local_34c,dVar11,pMVar12);
                  uVar5 = *(uint *)(pcVar3 + 0x8c);
                  if (uVar5 - 1 < 0x1ffff) {
                    puVar7 = Mem_Malloc(uVar5 + 1);
                    Q_memset(puVar7,0,uVar5);
                    FS_Seek(pvVar4,*(int *)(pcVar3 + 0x88),FILESYSTEM_SEEK_HEAD);
                    FS_Read(puVar7,uVar5,1,pvVar4);
                    Q_memset(local_32c,0,0x58);
                    MD5Init(local_32c);
                    MD5Update(local_32c,puVar7,uVar5);
                    MD5Final(local_35c,local_32c);
                    iVar8 = Q_memcmp(pcVar3 + 0x4d,local_35c,0x10);
                    if (iVar8 == 0) {
                      Con_Printf(" OK\n");
                    }
                    else {
                      Con_Printf(" MISMATCHED\n");
                      Con_Printf("--------------------\n");
                      pcVar3 = MD5_Print((uchar *)(pcVar3 + 0x4d));
                      Con_Printf(" File  :  %s\n",pcVar3);
                      pcVar3 = MD5_Print(local_35c);
                      Con_Printf(" Actual:  %s\n",pcVar3);
                      Con_Printf("--------------------\n");
                    }
                    if (puVar7 != (uchar *)0x0) {
                      Mem_Free(puVar7);
                    }
                  }
                  else {
                    Con_Printf("Unable to MD5 hash data, size invalid:  %i\n",uVar5,puVar10,dVar11,
                               pMVar12);
                  }
                  local_394 = local_394 + 0x90;
                } while (iVar2 < local_370);
              }
              FS_Close(pvVar4);
              Mem_Free(local_36c);
            }
            else {
              Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_370);
              FS_Close(pvVar4);
            }
          }
          else {
            Con_Printf("hpkval:  version mismatch\n");
            FS_Close(pvVar4);
          }
        }
        else {
          Con_Printf("%s is not an HPAK file\n",local_228);
          FS_Close(pvVar4);
        }
      }
    }
    else {
      Con_Printf("Usage:  hpkval hpkname\n");
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00050af0:
  iVar2 = iVar2 + 1;
  if ((int)local_378 <= iVar2) goto LAB_00050f49;
  goto LAB_00050afb;
}


