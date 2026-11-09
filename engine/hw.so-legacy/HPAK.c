// HPAK_AddLump  @ 00119f90
void __regparm3
HPAK_AddLump(qboolean bUseQueue,char *pakname,resource_s *pResource,void *pData,
            FileHandle_t fpSource)

{
  uchar *hash;
  undefined4 uVar1;
  hash_pack_entry_t *phVar2;
  int iVar3;
  FileHandle_t pvVar4;
  FileHandle_t dst;
  uint uVar5;
  int iVar6;
  int iVar7;
  void *pInput;
  char *pcVar8;
  void *local_4cc;
  char local_4b4 [260];
  char local_3b0 [260];
  char local_2ac [255];
  undefined1 local_1ad;
  char local_1a8 [260];
  MD5Context_t local_a4;
  uchar local_4c [16];
  uint local_3c;
  void *local_38;
  int local_2c;
  void *local_28;
  
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
  if (pakname == (char *)0x0) {
    if (bUseQueue != false) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no lump to add\n");
      return;
    }
  }
  else if (bUseQueue != false) {
    if (pResource == (resource_s *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
      return;
    }
    if (0x1fc00 < *(int *)(pakname + 0x48) - 0x400U) {
      Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",*(int *)(pakname + 0x48));
      return;
    }
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
    Q_memset(&local_a4,0,0x58);
    MD5Init(&local_a4);
    MD5Update(&local_a4,(uchar *)pResource,*(uint *)(pakname + 0x48));
    MD5Final(local_4c,&local_a4);
    hash = (uchar *)(pakname + 0x4d);
    iVar3 = Q_memcmp(hash,local_4c,0x10);
    if (iVar3 == 0) {
      snprintf(local_4b4,0x100,"%s",bUseQueue);
      COM_DefaultExtension(local_4b4,".hpk");
      COM_FixSlashes(local_4b4);
      Q_strncpy(local_2ac,local_4b4,0xff);
      local_1ad = 0;
      pvVar4 = FS_Open(local_4b4,"rb");
      if (pvVar4 != (FileHandle_t)0x0) {
        COM_StripExtension(local_4b4,local_3b0);
        COM_DefaultExtension(local_3b0,".hp2");
        dst = FS_Open(local_3b0,"w+b");
        if (dst == (FileHandle_t)0x0) {
          FS_Close(pvVar4);
          Con_Printf("ERROR: couldn\'t open %s.\n",local_4b4);
          return;
        }
        FS_Read(&hash_pack_header,0xc,1,pvVar4);
        if (hash_pack_header.version != 1) {
          FS_Close(pvVar4);
          FS_Close(dst);
          FS_Unlink(local_3b0);
          Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
          return;
        }
        FS_Seek(pvVar4,0,FILESYSTEM_SEEK_HEAD);
        uVar5 = FS_Size(pvVar4);
        COM_CopyFileChunk(dst,pvVar4,uVar5);
        FS_Seek(pvVar4,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
        FS_Read(&local_3c,4,1,pvVar4);
        if (0x8000 < local_3c) {
          Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_3c);
          FS_Close(pvVar4);
          FS_Close(dst);
          FS_Unlink(local_3b0);
          return;
        }
        local_38 = Mem_Malloc((local_3c * 9 + 9) * 0x10);
        FS_Read(local_38,local_3c * 0x90,1,pvVar4);
        FS_Close(pvVar4);
                    /* Unresolved local var: int i@[???] */
        if (0 < (int)local_3c) {
          iVar3 = 0;
          local_4cc = (void *)0x0;
          do {
            iVar6 = Q_memcmp(hash,(void *)((int)local_38 + iVar3 + 0x4d),0x10);
            if (iVar6 == 0) {
              FS_Close(dst);
              FS_Unlink(local_3b0);
              Mem_Free(local_38);
              return;
            }
            local_4cc = (void *)((int)local_4cc + 1);
            iVar3 = iVar3 + 0x90;
          } while ((int)local_4cc < (int)local_3c);
        }
        local_2c = local_3c + 1;
        local_28 = Mem_Malloc(local_2c * 0x90);
        Q_memset(local_28,0,local_2c * 0x90);
        Q_memcpy(local_28,local_38,local_3c * 0x90);
        if ((int)local_3c < 1) {
LAB_0011a753:
          local_4cc = (void *)((local_2c * 9 + -9) * 0x10 + (int)local_28);
LAB_0011a5b5:
          Q_memset(local_4cc,0,0x90);
          FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
          uVar5 = 0;
          do {
            uVar1 = *(undefined4 *)(pakname + uVar5 + 4);
            *(undefined4 *)((int)local_4cc + uVar5) = *(undefined4 *)(pakname + uVar5);
            *(undefined4 *)((int)local_4cc + uVar5 + 4) = uVar1;
            uVar5 = uVar5 + 8;
          } while (uVar5 < 0x88);
          uVar5 = FS_Tell(dst);
          *(uint *)((int)local_4cc + 0x88) = uVar5;
          iVar3 = *(int *)(pakname + 0x48);
          *(int *)((int)local_4cc + 0x8c) = iVar3;
          FS_Write(pResource,iVar3,1,dst);
          hash_pack_header.nDirectoryOffset = FS_Tell(dst);
          FS_Write(&local_2c,4,1,dst);
          if (0 < local_2c) {
            iVar3 = 0;
            iVar6 = 0;
            do {
              iVar3 = iVar3 + 1;
              pInput = (void *)((int)local_28 + iVar6);
              iVar6 = iVar6 + 0x90;
              FS_Write(pInput,0x90,1,dst);
            } while (iVar3 < local_2c);
          }
          if (local_28 != (void *)0x0) {
            Mem_Free(local_28);
          }
          if (local_38 != (void *)0x0) {
            Mem_Free(local_38);
          }
          FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
          FS_Write(&hash_pack_header,0xc,1,dst);
          FS_Close(dst);
          FS_Unlink(local_2ac);
          FS_Rename(local_3b0,local_2ac);
          return;
        }
        iVar6 = 0;
        iVar3 = 0;
LAB_0011a3fc:
        iVar7 = Q_memcmp(hash,(void *)((int)local_38 + iVar6 + 0x4d),0x10);
        if (-1 < iVar7) goto LAB_0011a3e8;
        local_4cc = (void *)(iVar6 + (int)local_28);
        if (iVar3 < (int)local_3c) {
          iVar3 = iVar3 + 1;
          iVar6 = iVar3 * 0x90;
          while( true ) {
            uVar5 = 0;
            do {
              uVar1 = *(undefined4 *)((int)local_38 + uVar5 + iVar6 + -0x8c);
              *(undefined4 *)((int)local_28 + uVar5 + iVar6) =
                   *(undefined4 *)((int)local_38 + uVar5 + iVar6 + -0x90);
              *(undefined4 *)((int)local_28 + uVar5 + iVar6 + 4) = uVar1;
              uVar5 = uVar5 + 8;
            } while (uVar5 < 0x90);
            iVar6 = iVar6 + 0x90;
            if ((int)local_3c <= iVar3) break;
            iVar3 = iVar3 + 1;
          }
        }
        if (local_4cc != (void *)0x0) goto LAB_0011a5b5;
        goto LAB_0011a753;
      }
      snprintf(local_1a8,0x100,"%s",bUseQueue);
      COM_DefaultExtension(local_1a8,".hpk");
      Con_Printf("Creating HPAK %s.\n",local_1a8);
      pvVar4 = FS_Open(local_1a8,"wb");
      if (pvVar4 == (FileHandle_t)0x0) {
        Con_Printf("ERROR: couldn\'t open new .hpk, check access rights to %s.\n",local_1a8);
        return;
      }
      Q_memset(&local_a4,0,0x58);
      MD5Init(&local_a4);
      MD5Update(&local_a4,(uchar *)pResource,*(uint *)(pakname + 0x48));
      MD5Final(local_4c,&local_a4);
      iVar3 = Q_memcmp(hash,local_4c,0x10);
      if (iVar3 == 0) {
        Q_memset(&hash_pack_header,0,0xc);
        Q_strncpy(hash_pack_header.szFileStamp,"HPAK",4);
        hash_pack_header.version = 1;
        hash_pack_header.nDirectoryOffset = 0;
        FS_Write(&hash_pack_header,0xc,1,pvVar4);
        Q_memset(&hash_pack_dir,0,8);
        hash_pack_dir.nEntries = 1;
        hash_pack_dir.p_rgEntries = Mem_Malloc(0x90);
        Q_memset(hash_pack_dir.p_rgEntries,0,hash_pack_dir.nEntries * 0x90);
        phVar2 = hash_pack_dir.p_rgEntries;
        uVar5 = 0;
        do {
          uVar1 = *(undefined4 *)(pakname + uVar5 + 4);
          *(undefined4 *)((phVar2->resource).szFileName + uVar5) = *(undefined4 *)(pakname + uVar5);
          *(undefined4 *)((phVar2->resource).szFileName + uVar5 + 4) = uVar1;
          uVar5 = uVar5 + 8;
        } while (uVar5 < 0x88);
        uVar5 = FS_Tell(pvVar4);
        phVar2->nOffset = uVar5;
        iVar3 = *(int *)(pakname + 0x48);
        phVar2->nFileLength = iVar3;
        FS_Write(pResource,iVar3,1,pvVar4);
        uVar5 = FS_Tell(pvVar4);
        FS_Write(&hash_pack_dir,4,1,pvVar4);
        if (0 < hash_pack_dir.nEntries) {
          iVar6 = 0;
          iVar3 = 0;
          do {
            iVar3 = iVar3 + 1;
            pcVar8 = ((hash_pack_dir.p_rgEntries)->resource).szFileName + iVar6;
            iVar6 = iVar6 + 0x90;
            FS_Write(pcVar8,0x90,1,pvVar4);
          } while (iVar3 < hash_pack_dir.nEntries);
        }
        if (hash_pack_dir.p_rgEntries != (hash_pack_entry_t *)0x0) {
          Mem_Free(hash_pack_dir.p_rgEntries);
        }
        hash_pack_dir.p_rgEntries = (hash_pack_entry_t *)0x0;
        hash_pack_dir.nEntries = 0;
        hash_pack_header.nDirectoryOffset = uVar5;
        FS_Seek(pvVar4,0,FILESYSTEM_SEEK_HEAD);
        FS_Write(&hash_pack_header,0xc,1,pvVar4);
        FS_Close(pvVar4);
        return;
      }
      pcVar8 = "HPAK_CreatePak called with bogus lump, md5 mismatch\n";
    }
    else {
      pcVar8 = "HPAK_AddLump called with bogus lump, md5 mismatch\n";
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int32 curpos@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
    Con_Printf(pcVar8);
    pcVar8 = MD5_Print(hash);
    Con_Printf("Purported:  %s\n",pcVar8);
    pcVar8 = MD5_Print(local_4c);
    Con_Printf("Actual   :  %s\n",pcVar8);
    Con_Printf("Ignoring lump addition\n");
    return;
  }
  Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
  return;
LAB_0011a3e8:
  iVar3 = iVar3 + 1;
  iVar6 = iVar6 + 0x90;
  if ((int)local_3c <= iVar3) goto LAB_0011a753;
  goto LAB_0011a3fc;
}


// HPAK_AddLump  @ 0011c830
void HPAK_AddLump(qboolean bUseQueue,char *pakname,resource_s *pResource,void *pData,
                 FileHandle_t fpSource)

{
  undefined4 uVar1;
  int iVar2;
  FileHandle_t file;
  FileHandle_t dst;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uchar *puVar6;
  void *pInput;
  void *local_3cc;
  int local_3c8;
  char local_3b0 [260];
  char local_2ac [260];
  char local_1a8 [255];
  undefined1 local_a9;
  MD5Context_t local_a4;
  uchar local_4c [16];
  uint local_3c;
  void *local_38;
  int local_2c;
  void *local_28;
  
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
  if (pResource == (resource_s *)0x0) {
    if (pakname != (char *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no lump to add\n");
      return;
    }
  }
  else if (pakname != (char *)0x0) {
    if ((fpSource == (FileHandle_t)0x0) && (pData == (void *)0x0)) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
      return;
    }
    if (0x1fc00 < pResource->nDownloadSize - 0x400U) {
      Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",pResource->nDownloadSize);
      return;
    }
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
    Q_memset(&local_a4,0,0x58);
    MD5Init(&local_a4);
    if (pData == (void *)0x0) {
                    /* Unresolved local var: int nOrig@[???]
                       Unresolved local var: uchar * pDiskData@[???] */
      uVar3 = FS_Tell(fpSource);
      puVar6 = Mem_Malloc(pResource->nDownloadSize + 1);
      Q_memset(puVar6,0,pResource->nDownloadSize);
      FS_Read(puVar6,pResource->nDownloadSize,1,fpSource);
      FS_Seek(fpSource,uVar3,FILESYSTEM_SEEK_HEAD);
      MD5Update(&local_a4,puVar6,pResource->nDownloadSize);
      Mem_Free(puVar6);
    }
    else {
      MD5Update(&local_a4,pData,pResource->nDownloadSize);
    }
    MD5Final(local_4c,&local_a4);
    puVar6 = pResource->rgucMD5_hash;
    iVar2 = Q_memcmp(puVar6,local_4c,0x10);
    if (iVar2 != 0) {
      Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
      pcVar5 = MD5_Print(puVar6);
      Con_Printf("Purported:  %s\n",pcVar5);
      pcVar5 = MD5_Print(local_4c);
      Con_Printf("Actual   :  %s\n",pcVar5);
      Con_Printf("Ignoring lump addition\n");
      return;
    }
    if (bUseQueue != false) {
      HPAK_AddToQueue(pakname,pResource,pData,fpSource);
      return;
    }
    snprintf(local_3b0,0x100,"%s",pakname);
    COM_DefaultExtension(local_3b0,".hpk");
    COM_FixSlashes(local_3b0);
    Q_strncpy(local_1a8,local_3b0,0xff);
    local_a9 = 0;
    file = FS_Open(local_3b0,"rb");
    if (file == (FileHandle_t)0x0) {
      HPAK_CreatePak(pakname,pResource,pData,fpSource);
      return;
    }
    COM_StripExtension(local_3b0,local_2ac);
    COM_DefaultExtension(local_2ac,".hp2");
    dst = FS_Open(local_2ac,"w+b");
    if (dst == (FileHandle_t)0x0) {
      FS_Close(file);
      Con_Printf("ERROR: couldn\'t open %s.\n",local_3b0);
      return;
    }
    FS_Read(&hash_pack_header,0xc,1,file);
    if (hash_pack_header.version != 1) {
      FS_Close(file);
      FS_Close(dst);
      FS_Unlink(local_2ac);
      Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
      return;
    }
    FS_Seek(file,0,FILESYSTEM_SEEK_HEAD);
    uVar3 = FS_Size(file);
    COM_CopyFileChunk(dst,file,uVar3);
    FS_Seek(file,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
    FS_Read(&local_3c,4,1,file);
    if (0x8000 < local_3c) {
      Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_3c);
      FS_Close(file);
      FS_Close(dst);
      FS_Unlink(local_2ac);
      return;
    }
    local_38 = Mem_Malloc((local_3c * 9 + 9) * 0x10);
    FS_Read(local_38,local_3c * 0x90,1,file);
    FS_Close(file);
                    /* Unresolved local var: int i@[???] */
    if (0 < (int)local_3c) {
      iVar2 = 0;
      local_3cc = (void *)0x0;
      do {
        iVar4 = Q_memcmp(puVar6,(void *)((int)local_38 + iVar2 + 0x4d),0x10);
        if (iVar4 == 0) {
          FS_Close(dst);
          FS_Unlink(local_2ac);
          Mem_Free(local_38);
          return;
        }
        local_3cc = (void *)((int)local_3cc + 1);
        iVar2 = iVar2 + 0x90;
      } while ((int)local_3cc < (int)local_3c);
    }
    local_2c = local_3c + 1;
    local_28 = Mem_Malloc(local_2c * 0x90);
    Q_memset(local_28,0,local_2c * 0x90);
    Q_memcpy(local_28,local_38,local_3c * 0x90);
    if ((int)local_3c < 1) {
LAB_0011d113:
      local_3cc = (void *)((local_2c * 9 + -9) * 0x10 + (int)local_28);
LAB_0011cf64:
      Q_memset(local_3cc,0,0x90);
      FS_Seek(dst,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
      uVar3 = 0;
      do {
        uVar1 = *(undefined4 *)(pResource->szFileName + uVar3 + 4);
        *(undefined4 *)((int)local_3cc + uVar3) = *(undefined4 *)(pResource->szFileName + uVar3);
        *(undefined4 *)((int)local_3cc + uVar3 + 4) = uVar1;
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x88);
      uVar3 = FS_Tell(dst);
      *(uint *)((int)local_3cc + 0x88) = uVar3;
      iVar2 = pResource->nDownloadSize;
      *(int *)((int)local_3cc + 0x8c) = iVar2;
      if (pData == (void *)0x0) {
        COM_CopyFileChunk(dst,fpSource,iVar2);
      }
      else {
        FS_Write(pData,iVar2,1,dst);
      }
      hash_pack_header.nDirectoryOffset = FS_Tell(dst);
      FS_Write(&local_2c,4,1,dst);
      if (0 < local_2c) {
        iVar4 = 0;
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 1;
          pInput = (void *)((int)local_28 + iVar4);
          iVar4 = iVar4 + 0x90;
          FS_Write(pInput,0x90,1,dst);
        } while (iVar2 < local_2c);
      }
      if (local_28 != (void *)0x0) {
        Mem_Free(local_28);
      }
      if (local_38 != (void *)0x0) {
        Mem_Free(local_38);
      }
      FS_Seek(dst,0,FILESYSTEM_SEEK_HEAD);
      FS_Write(&hash_pack_header,0xc,1,dst);
      FS_Close(dst);
      FS_Unlink(local_1a8);
      FS_Rename(local_2ac,local_1a8);
      return;
    }
    local_3c8 = 0;
    iVar2 = 0;
LAB_0011cce4:
    iVar4 = Q_memcmp(puVar6,(void *)((int)local_38 + iVar2 + 0x4d),0x10);
    if (-1 < iVar4) goto LAB_0011ccd0;
    local_3cc = (void *)(iVar2 + (int)local_28);
    if (local_3c8 < (int)local_3c) {
      iVar2 = (local_3c8 * 9 + 9) * 0x10;
      do {
        uVar3 = 0;
        do {
          uVar1 = *(undefined4 *)((int)local_38 + uVar3 + iVar2 + -0x8c);
          *(undefined4 *)((int)local_28 + uVar3 + iVar2) =
               *(undefined4 *)((int)local_38 + uVar3 + iVar2 + -0x90);
          *(undefined4 *)((int)local_28 + uVar3 + iVar2 + 4) = uVar1;
          uVar3 = uVar3 + 8;
        } while (uVar3 < 0x90);
        local_3c8 = local_3c8 + 1;
        iVar2 = iVar2 + 0x90;
      } while (local_3c8 < (int)local_3c);
    }
    if (local_3cc != (void *)0x0) goto LAB_0011cf64;
    goto LAB_0011d113;
  }
  Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
  return;
LAB_0011ccd0:
  local_3c8 = local_3c8 + 1;
  iVar2 = iVar2 + 0x90;
  if ((int)local_3c <= local_3c8) goto LAB_0011d113;
  goto LAB_0011cce4;
}


// HPAK_AddToQueue  @ 0011b470
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


// HPAK_CheckIntegrity  @ 0011d9a0
void HPAK_CheckIntegrity(char *pakname)

{
  char local_110 [268];
  
                    /* Unresolved local var: char[260] name@[???] */
  snprintf(local_110,0x100,"%s",pakname);
  COM_DefaultExtension(local_110,".hpk");
  COM_FixSlashes(local_110);
  HPAK_ValidatePak(local_110);
  return;
}


// HPAK_CheckSize  @ 0011d460
void HPAK_CheckSize(char *pakname)

{
  float fVar1;
  float fVar2;
  FileHandle_t file;
  uint uVar3;
  char local_110 [264];
  
                    /* Unresolved local var: char[260] fullname@[???]
                       Unresolved local var: float maxSize@[???]
                       Unresolved local var: float actualSize@[???]
                       Unresolved local var: FileHandle_t hfile@[???] */
  if ((hpk_maxsize.value != 0.0) && (pakname != (char *)0x0)) {
    if (hpk_maxsize.value < 0.0) {
      Con_Printf("hpk_maxsize < 0, setting to 0\n");
      Cvar_DirectSet(&hpk_maxsize,"0");
      return;
    }
    snprintf(local_110,0x100,"%s");
    COM_DefaultExtension(local_110,".hpk");
    COM_FixSlashes(local_110);
    fVar2 = hpk_maxsize.value * 1e+06;
    file = FS_Open(local_110,"rb");
    fVar1 = 0.0;
    if (file != (FileHandle_t)0x0) {
      uVar3 = FS_Size(file);
      fVar1 = (float)uVar3;
      FS_Close(file);
    }
    if (fVar2 <= fVar1) {
      Con_Printf("Server: Size of %s > %f MB, deleting.\n",local_110,(double)hpk_maxsize.value);
      Log_Printf("Server: Size of %s > %f MB, deleting.\n",local_110,(double)hpk_maxsize.value);
      FS_RemoveFile(local_110,(char *)0x0);
      return;
    }
  }
  return;
}


// HPAK_CreatePak  @ 0011c380
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
  bool bVar7;
  char local_188 [260];
  MD5Context_t local_84;
  uchar local_2c [28];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int32 curpos@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: hash_pack_entry_t * pCurrentEntry@[???] */
  bVar7 = pData == (void *)0x0;
  if (((fpSource == (FileHandle_t)0x0) || (bVar7)) &&
     ((fpSource != (FileHandle_t)0x0 || (pData != (void *)0x0)))) {
    snprintf(local_188,0x100,"%s",pakname);
    COM_DefaultExtension(local_188,".hpk");
    Con_Printf("Creating HPAK %s.\n",local_188);
    file = FS_Open(local_188,"wb");
    if (file != (FileHandle_t)0x0) {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
      Q_memset(&local_84,0,0x58);
      MD5Init(&local_84);
      if (bVar7) {
                    /* Unresolved local var: int nOrig@[???]
                       Unresolved local var: uchar * pDiskData@[???] */
        uVar4 = FS_Tell(fpSource);
        buf = Mem_Malloc(pResource->nDownloadSize + 1);
        Q_memset(buf,0,pResource->nDownloadSize);
        FS_Read(buf,pResource->nDownloadSize,1,fpSource);
        FS_Seek(fpSource,uVar4,FILESYSTEM_SEEK_HEAD);
        MD5Update(&local_84,buf,pResource->nDownloadSize);
        Mem_Free(buf);
      }
      else {
        MD5Update(&local_84,pData,pResource->nDownloadSize);
      }
      MD5Final(local_2c,&local_84);
      iVar3 = Q_memcmp(pResource->rgucMD5_hash,local_2c,0x10);
      if (iVar3 != 0) {
        Con_Printf("HPAK_CreatePak called with bogus lump, md5 mismatch\n");
        pcVar5 = MD5_Print(pResource->rgucMD5_hash);
        Con_Printf("Purported:  %s\n",pcVar5);
        pcVar5 = MD5_Print(local_2c);
        Con_Printf("Actual   :  %s\n",pcVar5);
        Con_Printf("Ignoring lump addition\n");
        return;
      }
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
        uVar1 = *(undefined4 *)(pResource->szFileName + uVar4);
        *(undefined4 *)((phVar2->resource).szFileName + uVar4 + 4) =
             *(undefined4 *)(pResource->szFileName + uVar4 + 4);
        *(undefined4 *)((phVar2->resource).szFileName + uVar4) = uVar1;
        uVar4 = uVar4 + 8;
      } while (uVar4 < 0x88);
      uVar4 = FS_Tell(file);
      phVar2->nOffset = uVar4;
      iVar3 = pResource->nDownloadSize;
      phVar2->nFileLength = iVar3;
      if (bVar7) {
        COM_CopyFileChunk(file,fpSource,iVar3);
      }
      else {
        FS_Write(pData,iVar3,1,file);
      }
      uVar4 = FS_Tell(file);
      FS_Write(&hash_pack_dir,4,1,file);
      if (0 < hash_pack_dir.nEntries) {
        iVar6 = 0;
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
          pcVar5 = ((hash_pack_dir.p_rgEntries)->resource).szFileName + iVar6;
          iVar6 = iVar6 + 0x90;
          FS_Write(pcVar5,0x90,1,file);
        } while (iVar3 < hash_pack_dir.nEntries);
      }
      if (hash_pack_dir.p_rgEntries != (hash_pack_entry_t *)0x0) {
        Mem_Free(hash_pack_dir.p_rgEntries);
      }
      hash_pack_dir.p_rgEntries = (hash_pack_entry_t *)0x0;
      hash_pack_dir.nEntries = 0;
      hash_pack_header.nDirectoryOffset = uVar4;
      FS_Seek(file,0,FILESYSTEM_SEEK_HEAD);
      FS_Write(&hash_pack_header,0xc,1,file);
      FS_Close(file);
      return;
    }
    Con_Printf("ERROR: couldn\'t open new .hpk, check access rights to %s.\n",local_188);
  }
  else {
    Con_Printf("HPAK_CreatePak, must specify one of pData or fpSource\n");
  }
  return;
}


// HPAK_Extract_f  @ 00119420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Extract_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  FileHandle_t file;
  int iVar4;
  void *dest;
  FileHandle_t file_00;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  double dVar9;
  int local_374;
  char local_368 [260];
  char local_264 [260];
  char local_160 [260];
  undefined4 local_5c;
  uint local_58;
  char local_3c [4];
  int local_38;
  int local_34;
  int local_2c;
  void *local_28;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int nIndex@[???] */
  pcVar2 = Cmd_Argv(2);
  iVar3 = Q_stricmp(pcVar2,"all");
  if (iVar3 == 0) {
    pcVar2 = Cmd_Argv(1);
    pcVar7 = "%s";
    snprintf(local_368,0x100,"%s",pcVar2);
    COM_DefaultExtension(local_368,".hpk");
  }
  else {
    pcVar2 = Cmd_Argv(2);
    iVar3 = Q_atoi(pcVar2);
    pcVar5 = Cmd_Argv(1);
    pcVar7 = "%s";
    pcVar2 = local_368;
    snprintf(pcVar2,0x100,"%s",pcVar5);
    COM_DefaultExtension(pcVar2,".hpk");
    if (iVar3 != -1) {
      Con_Printf("Extracting lump %i from %s\n",iVar3,pcVar2);
      goto LAB_001194a3;
    }
  }
  pcVar2 = pcVar7;
  iVar3 = -1;
  Con_Printf("Extracting all lumps from %s.\n",local_368);
LAB_001194a3:
  file = FS_Open(local_368,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_368,pcVar2);
    return;
  }
  FS_Read(local_3c,0xc,1,file);
  iVar4 = Q_strncmp(local_3c,"HPAK",4);
  if (iVar4 != 0) {
    Con_Printf("%s is not an HPAK file\n",local_368);
    FS_Close(file);
    return;
  }
  if (local_38 != 1) {
    Con_Printf("hpkextract:  version mismatch\n");
    FS_Close(file);
    return;
  }
  FS_Seek(file,local_34,FILESYSTEM_SEEK_HEAD);
  FS_Read(&local_2c,4,1,file);
  if (0x7fff < local_2c - 1U) {
    Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_2c);
    FS_Close(file);
    return;
  }
  Con_Printf("# of Entries:  %i\n",local_2c);
  Con_Printf("# Type Size FileName : MD5 Hash\n");
  local_28 = Mem_Malloc(local_2c * 0x90);
  FS_Read(local_28,local_2c * 0x90,1,file);
  if (0 < local_2c) {
    local_374 = 0;
    iVar4 = local_2c;
    iVar6 = 0;
                    /* Unresolved local var: uchar * pData@[???]
                       Unresolved local var: int nDataSize@[???]
                       Unresolved local var: FileHandle_t fpOutput@[???]
                       Unresolved local var: char[260] szFileOut@[???] */
    do {
      while ((iVar3 != -1 && (iVar3 != iVar6))) {
LAB_00119600:
        iVar6 = iVar6 + 1;
        local_374 = local_374 + 0x90;
        if (iVar4 <= iVar6) goto LAB_001197d4;
      }
      pcVar2 = (char *)((int)local_28 + local_374);
      COM_FileBase(pcVar2,local_264);
      switch(*(undefined4 *)(pcVar2 + 0x40)) {
      case 0:
        local_5c = 0x6e756f73;
        local_58 = CONCAT22(local_58._2_2_,100);
        break;
      case 1:
        local_5c = 0x6e696b73;
        local_58 = local_58 & 0xffffff00;
        break;
      case 2:
        local_5c = 0x65646f6d;
        local_58 = CONCAT22(local_58._2_2_,0x6c);
        break;
      case 3:
        local_5c = 0x61636564;
        local_58 = CONCAT22(local_58._2_2_,0x6c);
        break;
      case 4:
        local_5c = 0x656e6567;
        local_58 = 0x636972;
        break;
      case 5:
        local_5c = 0x6e657665;
        local_58 = CONCAT22(local_58._2_2_,0x74);
        break;
      default:
        local_5c = CONCAT22(local_5c._2_2_,0x3f);
      }
      puVar8 = &local_5c;
      pcVar7 = local_264;
      iVar1 = iVar6 + 1;
      dVar9 = (double)((float)*(int *)(pcVar2 + 0x48) * 0.0009765625);
      Con_Printf("Extracting %i: %10s %.2fK %s\n",iVar1,puVar8,dVar9,pcVar7);
      iVar4 = *(int *)(pcVar2 + 0x8c);
      if (0x1fffe < iVar4 - 1U) {
        Con_Printf("Unable to extract data, size invalid:  %s\n",iVar4,puVar8,dVar9,pcVar7);
        iVar4 = local_2c;
        goto LAB_00119600;
      }
      dest = Mem_Malloc(iVar4 + 1);
      Q_memset(dest,0,iVar4);
      FS_Seek(file,*(int *)(pcVar2 + 0x88),FILESYSTEM_SEEK_HEAD);
      FS_Read(dest,iVar4,1,file);
      snprintf(local_160,0x104,"hpklmps\\lmp%04i.wad",iVar6);
      COM_FixSlashes(local_160);
      COM_CreatePath(local_160);
      file_00 = FS_Open(local_160,"wb");
      if (file_00 == (FileHandle_t)0x0) {
        Con_Printf("Error creating lump file %s\n",local_160);
      }
      else {
        FS_Write(dest,iVar4,1,file_00);
        FS_Close(file_00);
      }
      iVar4 = local_2c;
      if (dest == (void *)0x0) goto LAB_00119600;
      Mem_Free(dest);
      local_374 = local_374 + 0x90;
      iVar4 = local_2c;
      iVar6 = iVar1;
    } while (iVar1 < local_2c);
  }
LAB_001197d4:
  FS_Close(file);
  Mem_Free(local_28);
  return;
}


// HPAK_Extract_f  @ 0011ae70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Extract_f(void)

{
  resource_t *pakname;
  void **ppvVar1;
  char **ppcVar2;
  int iVar3;
  hash_pack_queue_t *in_stack_ffffffe4;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_ffffffe8;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int nIndex@[???] */
  if (cmd_source != src_command) {
    return;
  }
  while (p = gp_hpak_queue, gp_hpak_queue != (hash_pack_queue_t *)0x0) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
    pakname = &gp_hpak_queue->resource;
    ppvVar1 = &gp_hpak_queue->data;
    ppcVar2 = &gp_hpak_queue->pakname;
    gp_hpak_queue = gp_hpak_queue->next;
    HPAK_AddLump((qboolean)*ppcVar2,pakname->szFileName,*ppvVar1,in_stack_ffffffe4,in_stack_ffffffe8
                );
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    in_stack_ffffffe4 = p;
  }
  iVar3 = Cmd_Argc();
  if (iVar3 != 3) {
    Con_Printf("Usage:  hpkextract hpkname [all | single index]\n");
    return;
  }
  HPAK_Extract_f();
  return;
}


// HPAK_FindResource  @ 0011b3c0
qboolean HPAK_FindResource(hash_pack_directory_t *pDir,uchar *hash,resource_s *pResourceEntry)

{
  hash_pack_entry_t *phVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < pDir->nEntries) {
    iVar5 = 0;
    iVar6 = 0;
    do {
      iVar3 = Q_memcmp(hash,(pDir->p_rgEntries->resource).rgucMD5_hash + iVar5,0x10);
      if (iVar3 == 0) {
        if (pResourceEntry != (resource_s *)0x0) {
          phVar1 = pDir->p_rgEntries;
          uVar4 = 0;
          do {
            uVar2 = *(undefined4 *)((phVar1->resource).szFileName + uVar4 + iVar5 + 4);
            *(undefined4 *)(pResourceEntry->szFileName + uVar4) =
                 *(undefined4 *)((phVar1->resource).szFileName + uVar4 + iVar5);
            *(undefined4 *)(pResourceEntry->szFileName + uVar4 + 4) = uVar2;
            uVar4 = uVar4 + 8;
          } while (uVar4 < 0x88);
          return true;
        }
        return true;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x90;
    } while (iVar6 < pDir->nEntries);
  }
  return false;
}


// HPAK_FlushHostQueue  @ 0011b5d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_FlushHostQueue(void)

{
  hash_pack_queue_t *in_stack_ffffffe4;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_ffffffe8;
  
  while (p = gp_hpak_queue, p != (hash_pack_queue_t *)0x0) {
    gp_hpak_queue = p->next;
    HPAK_AddLump((qboolean)p->pakname,(p->resource).szFileName,p->data,in_stack_ffffffe4,
                 in_stack_ffffffe8);
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    in_stack_ffffffe4 = p;
  }
  gp_hpak_queue = p;
  return;
}


// HPAK_GetDataPointer  @ 0011af90
qboolean HPAK_GetDataPointer(char *pakname,resource_s *pResource,uchar **pbuffer,int *bufsize)

{
  void *pvVar1;
  int iVar2;
  uchar *puVar3;
  FileHandle_t file;
  int iVar4;
  size_t size;
  hash_pack_queue_s *phVar5;
  int iVar6;
  qboolean local_158;
  char local_140 [260];
  char local_3c [4];
  int local_38;
  int local_34;
  int local_2c;
  void *local_28;
  
                    /* Unresolved local var: qboolean retval@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bfound@[???] */
  if (pbuffer != (uchar **)0x0) {
    *pbuffer = (uchar *)0x0;
  }
  if (bufsize != (int *)0x0) {
    *bufsize = 0;
  }
  if (gp_hpak_queue != (hash_pack_queue_t *)0x0) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
    phVar5 = gp_hpak_queue;
    do {
      iVar2 = Q_stricmp(phVar5->pakname,pakname);
      if ((iVar2 == 0) &&
         (iVar2 = Q_memcmp((phVar5->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10), iVar2 == 0
         )) {
        if (pbuffer != (uchar **)0x0) {
                    /* Unresolved local var: uchar * pbuf@[???] */
          puVar3 = Mem_Malloc(phVar5->datasize);
          if (puVar3 == (uchar *)0x0) {
            Sys_Error("Error allocating %i bytes for hpak!",phVar5->datasize);
          }
          Q_memcpy(puVar3,phVar5->data,phVar5->datasize);
          *pbuffer = puVar3;
        }
        if (bufsize == (int *)0x0) {
          return true;
        }
        *bufsize = phVar5->datasize;
        return true;
      }
      phVar5 = phVar5->next;
    } while (phVar5 != (hash_pack_queue_s *)0x0);
  }
  snprintf(local_140,0x100,"%s",pakname);
  COM_DefaultExtension(local_140,".hpk");
  file = FS_Open(local_140,"rb");
  if (file != (FileHandle_t)0x0) {
    FS_Read(local_3c,0xc,1,file);
    iVar2 = Q_strncmp(local_3c,"HPAK",4);
    if (iVar2 != 0) {
      Con_Printf("%s is not an HPAK file\n",local_140);
      FS_Close(file);
      return false;
    }
    if (local_38 != 1) {
      Con_Printf("HPAK_List:  version mismatch\n");
      FS_Close(file);
      return false;
    }
    FS_Seek(file,local_34,FILESYSTEM_SEEK_HEAD);
    FS_Read(&local_2c,4,1,file);
    if (local_2c - 1U < 0x8000) {
      local_28 = Mem_ZeroMalloc(local_2c * 0x90);
      FS_Read(local_28,local_2c * 0x90,1,file);
      local_158 = false;
      if (0 < local_2c) {
        iVar6 = 0;
        iVar2 = 0;
        do {
          pvVar1 = local_28;
          iVar4 = Q_memcmp((void *)((int)local_28 + iVar2 + 0x4d),pResource->rgucMD5_hash,0x10);
          if (iVar4 == 0) {
            FS_Seek(file,*(int *)((int)pvVar1 + iVar2 + 0x88),FILESYSTEM_SEEK_HEAD);
            local_158 = true;
            if ((pbuffer != (uchar **)0x0) &&
               (size = *(size_t *)((int)pvVar1 + iVar2 + 0x8c), 0 < (int)size)) {
                    /* Unresolved local var: uchar * p@[???] */
              if (bufsize != (int *)0x0) {
                *bufsize = size;
                size = *(size_t *)((int)pvVar1 + iVar2 + 0x8c);
              }
              puVar3 = Mem_Malloc(size);
              if (puVar3 == (uchar *)0x0) {
                Con_Printf("Couln\'t allocate %i bytes for HPAK entry\n",
                           *(undefined4 *)((int)pvVar1 + iVar2 + 0x8c));
                local_158 = false;
                if (bufsize != (int *)0x0) {
                  *bufsize = 0;
                }
              }
              else {
                FS_Read(puVar3,*(int *)((int)pvVar1 + iVar2 + 0x8c),1,file);
                local_158 = true;
                *pbuffer = puVar3;
              }
            }
            goto LAB_0011b2a1;
          }
          iVar6 = iVar6 + 1;
          iVar2 = iVar2 + 0x90;
        } while (iVar6 < local_2c);
        local_158 = false;
      }
LAB_0011b2a1:
      Mem_Free(local_28);
      FS_Close(file);
      return local_158;
    }
    Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_2c);
    FS_Close(file);
  }
  return false;
}


// HPAK_GetItem  @ 0011d1c0
char * HPAK_GetItem(int item)

{
  FileHandle_t file;
  int iVar1;
  char *pcVar2;
  hash_pack_queue_t *in_stack_fffffea4;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_fffffea8;
  char local_140 [260];
  char local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  void *local_20;
  
  while (p = gp_hpak_queue, p != (hash_pack_queue_t *)0x0) {
    gp_hpak_queue = p->next;
    HPAK_AddLump((qboolean)p->pakname,(p->resource).szFileName,p->data,in_stack_fffffea4,
                 in_stack_fffffea8);
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    in_stack_fffffea4 = p;
  }
  gp_hpak_queue = p;
  snprintf(HPAK_GetItem::name,0x100,"%s","custom");
  COM_DefaultExtension(HPAK_GetItem::name,".hpk");
  file = FS_Open(HPAK_GetItem::name,"rb");
  if (file != (FileHandle_t)0x0) {
    FS_Read(local_3c,0xc,1,file);
    iVar1 = Q_strncmp(local_3c,"HPAK",4);
    if (iVar1 != 0) {
      Con_Printf("%s is not an HPAK file\n",HPAK_GetItem::name);
      FS_Close(file);
      return "";
    }
    if (local_38 == 1) {
      FS_Seek(file,local_34,FILESYSTEM_SEEK_HEAD);
      FS_Read(&local_24,4,1,file);
      if (local_24 - 1U < 0x8000) {
        local_20 = Mem_Malloc(local_24 * 0x90);
        FS_Read(local_20,local_24 * 0x90,1,file);
        if (local_24 + -1 < item) {
          item = local_24 + -1;
        }
        pcVar2 = (char *)(item * 0x90 + (int)local_20);
        COM_FileBase(pcVar2,local_140);
        pcVar2 = MD5_Print((uchar *)(pcVar2 + 0x4d));
        snprintf(HPAK_GetItem::name,0x104,"!MD5%s",pcVar2);
        FS_Close(file);
        Mem_Free(local_20);
        return HPAK_GetItem::name;
      }
      Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_24);
      FS_Close(file);
    }
    else {
      Con_Printf("HPAK_List:  version mismatch\n");
      FS_Close(file);
    }
  }
  return "";
}


// HPAK_Init  @ 0011d150
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


// HPAK_List_f  @ 0011aa70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_List_f(void)

{
  char *pcVar1;
  FileHandle_t file;
  int iVar2;
  char *pcVar3;
  int iVar4;
  hash_pack_queue_t *in_stack_fffffd64;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_fffffd68;
  char local_264 [260];
  char local_160 [260];
  undefined4 local_5c;
  uint local_58;
  char local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  void *local_20;
  
  while (p = gp_hpak_queue, p != (hash_pack_queue_t *)0x0) {
    gp_hpak_queue = p->next;
    HPAK_AddLump((qboolean)p->pakname,(p->resource).szFileName,p->data,in_stack_fffffd64,
                 in_stack_fffffd68);
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    in_stack_fffffd64 = p;
  }
  gp_hpak_queue = p;
  pcVar1 = Cmd_Argv(1);
  snprintf(local_264,0x100,"%s",pcVar1);
  COM_DefaultExtension(local_264,".hpk");
  Con_Printf("Contents for %s.\n",local_264);
  file = FS_Open(local_264,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_264);
    return;
  }
  FS_Read(local_3c,0xc,1,file);
  iVar2 = Q_strncmp(local_3c,"HPAK",4);
  if (iVar2 != 0) {
    Con_Printf("%s is not an HPAK file\n",local_264);
    FS_Close(file);
    return;
  }
  if (local_38 != 1) {
    Con_Printf("HPAK_List:  version mismatch\n");
    FS_Close(file);
    return;
  }
  FS_Seek(file,local_34,FILESYSTEM_SEEK_HEAD);
  FS_Read(&local_24,4,1,file);
  if (local_24 - 1U < 0x8000) {
    Con_Printf("# of Entries:  %i\n",local_24);
    Con_Printf("# Type Size FileName : MD5 Hash\n");
    local_20 = Mem_Malloc(local_24 * 0x90);
    FS_Read(local_20,local_24 * 0x90,1,file);
    if (0 < local_24) {
      iVar4 = 0;
      iVar2 = 0;
      do {
        pcVar1 = (char *)((int)local_20 + iVar4);
        COM_FileBase(pcVar1,local_160);
        switch(*(undefined4 *)(pcVar1 + 0x40)) {
        case 0:
          local_5c = 0x6e756f73;
          local_58 = CONCAT22(local_58._2_2_,100);
          break;
        case 1:
          local_5c = 0x6e696b73;
          local_58 = local_58 & 0xffffff00;
          break;
        case 2:
          local_5c = 0x65646f6d;
          local_58 = CONCAT22(local_58._2_2_,0x6c);
          break;
        case 3:
          local_5c = 0x61636564;
          local_58 = CONCAT22(local_58._2_2_,0x6c);
          break;
        case 4:
          local_5c = 0x656e6567;
          local_58 = 0x636972;
          break;
        case 5:
          local_5c = 0x6e657665;
          local_58 = CONCAT22(local_58._2_2_,0x74);
          break;
        default:
          local_5c = CONCAT22(local_5c._2_2_,0x3f);
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x90;
        pcVar3 = MD5_Print((uchar *)(pcVar1 + 0x4d));
        Con_Printf("%i: %10s %.2fK %s\n  :  %s\n",iVar2,&local_5c,
                   (double)((float)*(int *)(pcVar1 + 0x48) * 0.0009765625),local_160,pcVar3);
      } while (iVar2 < local_24);
    }
    FS_Close(file);
    Mem_Free(local_20);
    return;
  }
  Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_24);
  FS_Close(file);
  return;
}


// HPAK_List_f  @ 0011ae50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_List_f(void)

{
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  if (cmd_source != src_command) {
    return;
  }
  HPAK_List_f();
  return;
}


// HPAK_RemoveLump  @ 0011b630
void HPAK_RemoveLump(char *pakname,resource_s *pResource)

{
  undefined4 uVar1;
  void *pvVar2;
  char *pcVar3;
  FileHandle_t file;
  FileHandle_t file_00;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  hash_pack_queue_t *in_stack_fffffc94;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_fffffc98;
  int local_354;
  int local_34c;
  resource_s local_338;
  char local_234 [260];
  char local_130 [255];
  undefined1 local_31;
  int local_2c;
  void *local_28;
  int local_24;
  void *local_20;
  
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
  if (((pakname == (char *)0x0) || (pResource == (resource_s *)0x0)) || (*pakname == '\0')) {
    Con_Printf("HPAK_RemoveLump:  Invalid arguments\n");
    return;
  }
  while (p = gp_hpak_queue, p != (hash_pack_queue_t *)0x0) {
    gp_hpak_queue = p->next;
    HPAK_AddLump((qboolean)p->pakname,(p->resource).szFileName,p->data,in_stack_fffffc94,
                 in_stack_fffffc98);
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    in_stack_fffffc94 = p;
  }
  gp_hpak_queue = p;
  pcVar3 = Cmd_Argv(1);
  snprintf(local_338.szFileName,0x100,"%s",pcVar3);
  COM_DefaultExtension(local_338.szFileName,".hpk");
  Q_strncpy(local_130,local_338.szFileName,0xff);
  local_31 = 0;
  file = FS_Open(local_130,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("Error:  couldn\'t open HPAK file %s for removal.\n",&local_338);
    return;
  }
  COM_StripExtension(local_338.szFileName,local_234);
  COM_DefaultExtension(local_234,".hp2");
  file_00 = FS_Open(local_234,"w+b");
  if (file_00 == (FileHandle_t)0x0) {
    FS_Close(file);
    Con_Printf("ERROR: couldn\'t create %s.\n",local_234);
    return;
  }
  FS_Seek(file,0,FILESYSTEM_SEEK_HEAD);
  FS_Seek(file_00,0,FILESYSTEM_SEEK_HEAD);
  FS_Read(&hash_pack_header,0xc,1,file);
  FS_Write(&hash_pack_header,0xc,1,file_00);
  iVar4 = Q_strncmp(hash_pack_header.szFileStamp,"HPAK",4);
  if (iVar4 == 0) {
    if (hash_pack_header.version != 1) {
      Con_Printf("ERROR: HPAK version outdated\n");
      goto LAB_0011b836;
    }
    FS_Seek(file,hash_pack_header.nDirectoryOffset,FILESYSTEM_SEEK_HEAD);
    FS_Read(&local_2c,4,1,file);
    if (0x7fff < local_2c - 1U) {
      Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_2c);
      goto LAB_0011b836;
    }
    if (local_2c == 1) {
      Con_Printf("Removing final lump from HPAK, deleting HPAK:\n  %s\n",local_130);
      FS_Close(file_00);
      FS_Close(file);
      FS_Unlink(local_234);
      FS_Unlink(local_130);
      return;
    }
    local_28 = Mem_Malloc(local_2c * 0x90);
    FS_Read(local_28,local_2c * 0x90,1,file);
    local_24 = local_2c + -1;
    local_20 = Mem_Malloc(local_24 * 0x90);
                    /* Unresolved local var: int i@[???] */
    if (0 < local_2c) {
      iVar4 = 0;
      local_34c = 0;
      do {
        iVar5 = Q_memcmp(pResource->rgucMD5_hash,(void *)((int)local_28 + iVar4 + 0x4d),0x10);
        if (iVar5 == 0) {
          Con_Printf("Removing %s from HPAK %s.\n",pResource,&local_338);
          if (0 < local_2c) {
            iVar5 = 0;
            iVar4 = 0;
            local_354 = 0;
            do {
              pvVar8 = local_28;
              iVar6 = Q_memcmp((void *)((int)local_28 + iVar5 + 0x4d),pResource->rgucMD5_hash,0x10);
              pvVar2 = local_20;
              if (iVar6 != 0) {
                uVar7 = 0;
                do {
                  uVar1 = *(undefined4 *)((int)pvVar8 + uVar7 + iVar5);
                  *(undefined4 *)((int)local_20 + uVar7 + local_354 * 0x90 + 4) =
                       *(undefined4 *)((int)pvVar8 + uVar7 + iVar5 + 4);
                  *(undefined4 *)((int)local_20 + uVar7 + local_354 * 0x90) = uVar1;
                  uVar7 = uVar7 + 8;
                } while (uVar7 < 0x90);
                uVar7 = FS_Tell(file_00);
                *(uint *)((int)pvVar2 + local_354 * 0x90 + 0x88) = uVar7;
                FS_Seek(file,*(int *)((int)pvVar8 + iVar5 + 0x88),FILESYSTEM_SEEK_HEAD);
                COM_CopyFileChunk(file_00,file,*(int *)((int)pvVar2 + local_354 * 0x90 + 0x8c));
                local_354 = local_354 + 1;
              }
              iVar4 = iVar4 + 1;
              iVar5 = iVar5 + 0x90;
            } while (iVar4 < local_2c);
          }
          hash_pack_header.nDirectoryOffset = FS_Tell(file_00);
          FS_Write(&local_24,4,1,file_00);
          if (0 < local_24) {
            iVar4 = 0;
            iVar5 = 0;
            do {
              iVar5 = iVar5 + 1;
              pvVar8 = (void *)((int)local_20 + iVar4);
              iVar4 = iVar4 + 0x90;
              FS_Write(pvVar8,0x90,1,file_00);
            } while (iVar5 < local_24);
          }
          FS_Seek(file_00,0,FILESYSTEM_SEEK_HEAD);
          FS_Write(&hash_pack_header,0xc,1,file_00);
          FS_Close(file_00);
          FS_Close(file);
          FS_Unlink(local_130);
          FS_Rename(local_234,local_130);
          Mem_Free(local_20);
          Mem_Free(local_28);
          return;
        }
        local_34c = local_34c + 1;
        iVar4 = iVar4 + 0x90;
      } while (local_34c < local_2c);
    }
    pcVar3 = "ERROR: HPAK doesn\'t contain specified lump:  %s\n";
  }
  else {
    pResource = &local_338;
    pcVar3 = "%s is not an HPAK file\n";
  }
  Con_Printf(pcVar3,pResource);
LAB_0011b836:
  FS_Close(file_00);
  FS_Close(file);
  FS_Unlink(local_234);
  return;
}


// HPAK_Remove_f  @ 0011bf40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Remove_f(void)

{
  resource_t *pakname;
  void **ppvVar1;
  char **ppcVar2;
  int iVar3;
  char *pcVar4;
  qboolean qVar5;
  char *str;
  hash_pack_queue_t *in_stack_ffffff54;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_ffffff58;
  resource_s local_94;
  
                    /* Unresolved local var: resource_t resource@[???] */
  if (cmd_source == src_command) {
    while (p = gp_hpak_queue, gp_hpak_queue != (hash_pack_queue_t *)0x0) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
      pakname = &gp_hpak_queue->resource;
      ppvVar1 = &gp_hpak_queue->data;
      ppcVar2 = &gp_hpak_queue->pakname;
      gp_hpak_queue = gp_hpak_queue->next;
      HPAK_AddLump((qboolean)*ppcVar2,pakname->szFileName,*ppvVar1,in_stack_ffffff54,
                   in_stack_ffffff58);
      Mem_Free(p->pakname);
      Mem_Free(p->data);
      Mem_Free(p);
      in_stack_ffffff54 = p;
    }
    iVar3 = Cmd_Argc();
    if (iVar3 != 3) {
      Con_Printf("Usage:  hpkremove <hpk> <index>\n");
      return;
    }
    pcVar4 = Cmd_Argv(2);
    iVar3 = Q_atoi(pcVar4);
    pcVar4 = Cmd_Argv(1);
    qVar5 = HPAK_ResourceForIndex(pcVar4,iVar3,&local_94);
                    /* Unresolved local var: resource_t resource@[???] */
    if (qVar5 == false) {
      pcVar4 = Cmd_Argv(1);
      str = Cmd_Argv(2);
      iVar3 = Q_atoi(str);
      Con_Printf("Could not locate resource %i in %s\n",iVar3,pcVar4);
    }
    else {
      pcVar4 = Cmd_Argv(1);
      HPAK_RemoveLump(pcVar4,&local_94);
    }
  }
  return;
}


// HPAK_ResourceForHash  @ 0011c060
qboolean HPAK_ResourceForHash(char *pakname,uchar *hash,resource_s *pResourceEntry)

{
  hash_pack_queue_s *phVar1;
  undefined4 uVar2;
  FileHandle_t file;
  int iVar3;
  qboolean qVar4;
  int iVar5;
  uint uVar6;
  int local_150;
  char local_140 [260];
  char local_3c [4];
  int local_38;
  int local_34;
  int local_2c;
  void *local_28;
  
  for (phVar1 = gp_hpak_queue; phVar1 != (hash_pack_queue_t *)0x0; phVar1 = phVar1->next) {
    iVar3 = Q_stricmp(phVar1->pakname,pakname);
    if ((iVar3 == 0) && (iVar3 = Q_memcmp((phVar1->resource).rgucMD5_hash,hash,0x10), iVar3 == 0)) {
      if (pResourceEntry == (resource_s *)0x0) {
        return true;
      }
      uVar6 = 0;
      do {
        uVar2 = *(undefined4 *)((phVar1->resource).szFileName + uVar6 + 4);
        *(undefined4 *)(pResourceEntry->szFileName + uVar6) =
             *(undefined4 *)((phVar1->resource).szFileName + uVar6);
        *(undefined4 *)(pResourceEntry->szFileName + uVar6 + 4) = uVar2;
        uVar6 = uVar6 + 8;
      } while (uVar6 < 0x88);
      return true;
    }
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
  }
  snprintf(local_140,0x100,"%s",pakname);
  COM_DefaultExtension(local_140,".hpk");
  file = FS_Open(local_140,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_140);
  }
  else {
    FS_Read(local_3c,0xc,1,file);
    iVar3 = Q_strncmp(local_3c,"HPAK",4);
    if (iVar3 != 0) {
      Con_Printf("%s is not an HPAK file\n",local_140);
      FS_Close(file);
      return false;
    }
    if (local_38 == 1) {
      FS_Seek(file,local_34,FILESYSTEM_SEEK_HEAD);
      FS_Read(&local_2c,4,1,file);
      if (local_2c - 1U < 0x8000) {
        local_28 = Mem_Malloc(local_2c * 0x90);
        FS_Read(local_28,local_2c * 0x90,1,file);
                    /* Unresolved local var: int i@[???] */
        qVar4 = false;
        if (0 < local_2c) {
          iVar3 = 0;
          local_150 = 0;
          do {
            iVar5 = Q_memcmp(hash,(void *)((int)local_28 + iVar3 + 0x4d),0x10);
            if (iVar5 == 0) {
              qVar4 = true;
              if (pResourceEntry != (resource_s *)0x0) {
                uVar6 = 0;
                do {
                  uVar2 = *(undefined4 *)((int)local_28 + uVar6 + iVar3 + 4);
                  *(undefined4 *)(pResourceEntry->szFileName + uVar6) =
                       *(undefined4 *)((int)local_28 + uVar6 + iVar3);
                  *(undefined4 *)(pResourceEntry->szFileName + uVar6 + 4) = uVar2;
                  uVar6 = uVar6 + 8;
                } while (uVar6 < 0x88);
                qVar4 = true;
              }
              goto LAB_0011c2b6;
            }
            local_150 = local_150 + 1;
            iVar3 = iVar3 + 0x90;
          } while (local_150 < local_2c);
          qVar4 = false;
        }
LAB_0011c2b6:
        FS_Close(file);
        Mem_Free(local_28);
        return qVar4;
      }
      Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_2c);
      FS_Close(file);
    }
    else {
      Con_Printf("HPAK_List:  version mismatch\n");
      FS_Close(file);
    }
  }
  return false;
}


// HPAK_ResourceForIndex  @ 0011bca0
qboolean HPAK_ResourceForIndex(char *pakname,int nIndex,resource_s *pResource)

{
  undefined4 uVar1;
  FileHandle_t file;
  int iVar2;
  uint uVar3;
  qboolean qVar4;
  char local_140 [260];
  char local_3c [4];
  int local_38;
  int local_34;
  int local_2c;
  void *local_28;
  
                    /* Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  qVar4 = false;
  if (cmd_source == src_command) {
    snprintf(local_140,0x100,"%s",pakname);
    COM_DefaultExtension(local_140,".hpk");
    file = FS_Open(local_140,"rb");
    if (file == (FileHandle_t)0x0) {
      Con_Printf("ERROR: couldn\'t open %s.\n",local_140);
    }
    else {
      FS_Read(local_3c,0xc,1,file);
      iVar2 = Q_strncmp(local_3c,"HPAK",4);
      if (iVar2 == 0) {
        if (local_38 == 1) {
          FS_Seek(file,local_34,FILESYSTEM_SEEK_HEAD);
          FS_Read(&local_2c,4,1,file);
          if (local_2c - 1U < 0x8000) {
            local_28 = Mem_Malloc(local_2c * 0x90);
            if ((nIndex < 1) || (local_2c < nIndex)) {
              qVar4 = false;
              Con_Printf("ERROR: HPAK bogus directory entry request:  %i\n",nIndex);
              FS_Close(file);
            }
            else {
              FS_Read(local_28,local_2c * 0x90,1,file);
              iVar2 = nIndex * 9 + -9;
              uVar3 = 0;
              do {
                uVar1 = *(undefined4 *)((int)local_28 + uVar3 + iVar2 * 0x10 + 4);
                *(undefined4 *)(pResource->szFileName + uVar3) =
                     *(undefined4 *)((int)local_28 + uVar3 + iVar2 * 0x10);
                *(undefined4 *)(pResource->szFileName + uVar3 + 4) = uVar1;
                uVar3 = uVar3 + 8;
              } while (uVar3 < 0x88);
              qVar4 = true;
              FS_Close(file);
              Mem_Free(local_28);
            }
          }
          else {
            Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_2c);
            FS_Close(file);
          }
        }
        else {
          Con_Printf("HPAK_List:  version mismatch\n");
          FS_Close(file);
        }
      }
      else {
        Con_Printf("%s is not an HPAK file\n",local_140);
        FS_Close(file);
      }
    }
  }
  return qVar4;
}


// HPAK_ValidatePak  @ 0011d5f0
void HPAK_ValidatePak(char *fullpakname)

{
  uint len;
  FileHandle_t file;
  int iVar1;
  uchar *buf;
  int iVar2;
  int iVar3;
  char *in;
  hash_pack_queue_t *in_stack_fffffe34;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_fffffe38;
  char local_1a4 [260];
  MD5Context_t local_a0;
  uchar local_48 [16];
  char local_38 [4];
  int local_34;
  int local_30;
  int local_2c;
  void *local_28;
  
  while (p = gp_hpak_queue, p != (hash_pack_queue_t *)0x0) {
    gp_hpak_queue = p->next;
    HPAK_AddLump((qboolean)p->pakname,(p->resource).szFileName,p->data,in_stack_fffffe34,
                 in_stack_fffffe38);
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    in_stack_fffffe34 = p;
  }
  gp_hpak_queue = p;
  file = FS_Open(fullpakname,"rb");
  if (file != (FileHandle_t)0x0) {
    FS_Read(local_38,0xc,1,file);
    if ((local_34 == 1) && (iVar1 = Q_strncmp(local_38,"HPAK",4), iVar1 == 0)) {
      FS_Seek(file,local_30,FILESYSTEM_SEEK_HEAD);
      FS_Read(&local_2c,4,1,file);
      if (local_2c - 1U < 0x8000) {
        local_28 = Mem_Malloc(local_2c * 0x90);
        FS_Read(local_28,local_2c * 0x90,1,file);
        if (0 < local_2c) {
          iVar3 = 0;
          iVar1 = 0;
          do {
            in = (char *)((int)local_28 + iVar3);
            COM_FileBase(in,local_1a4);
            len = *(uint *)(in + 0x8c);
            if (0x1fffe < len - 1) {
              Mem_Free(local_28);
              Con_Printf("Mismatched data in HPAK file %s, deleting\n",fullpakname);
              Con_Printf("Unable to MD5 hash data lump %i, size invalid:  %i\n",iVar1 + 1,len);
              goto LAB_0011d6ab;
            }
            buf = Mem_Malloc(len + 1);
            Q_memset(buf,0,len);
            FS_Seek(file,*(int *)(in + 0x88),FILESYSTEM_SEEK_HEAD);
            FS_Read(buf,len,1,file);
            Q_memset(&local_a0,0,0x58);
            MD5Init(&local_a0);
            MD5Update(&local_a0,buf,len);
            MD5Final(local_48,&local_a0);
            iVar2 = Q_memcmp(in + 0x4d,local_48,0x10);
            if (iVar2 != 0) {
              Con_Printf("Mismatched data in HPAK file %s, deleting\n",fullpakname);
            }
            if (buf != (uchar *)0x0) {
              Mem_Free(buf);
            }
            if (iVar2 != 0) {
              Mem_Free(local_28);
              goto LAB_0011d6ab;
            }
            iVar1 = iVar1 + 1;
            iVar3 = iVar3 + 0x90;
          } while (iVar1 < local_2c);
        }
        FS_Close(file);
        Mem_Free(local_28);
        return;
      }
      Con_Printf("ERROR: HPAK %s had bogus # of directory entries:  %i, deleting\n",fullpakname,
                 local_2c);
    }
    else {
      Con_Printf("%s is not a PAK file, deleting\n",fullpakname);
    }
LAB_0011d6ab:
                    /* Unresolved local var: uchar * pData@[???]
                       Unresolved local var: int nDataSize@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???]
                       Unresolved local var: int haderrors@[???] */
    FS_Close(file);
    FS_RemoveFile(fullpakname,(char *)0x0);
  }
  return;
}


// HPAK_Validate_f  @ 00119a30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Validate_f(void)

{
  uint len;
  char *pcVar1;
  FileHandle_t file;
  int iVar2;
  uchar *buf;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  double dVar6;
  char *pcVar7;
  char local_2cc [260];
  char local_1c8 [260];
  MD5Context_t local_c4;
  undefined4 local_6c;
  uint local_68;
  uchar local_4c [16];
  char local_3c [4];
  int local_38;
  int local_34;
  int local_2c;
  void *local_28;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  pcVar1 = Cmd_Argv(1);
  snprintf(local_2cc,0x100,"%s",pcVar1);
  COM_DefaultExtension(local_2cc,".hpk");
  Con_Printf("Validating %s.\n",local_2cc);
  file = FS_Open(local_2cc,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_2cc);
    return;
  }
  FS_Read(local_3c,0xc,1,file);
  iVar2 = Q_strncmp(local_3c,"HPAK",4);
  if (iVar2 != 0) {
    Con_Printf("%s is not an HPAK file\n",local_2cc);
    FS_Close(file);
    return;
  }
  if (local_38 != 1) {
    Con_Printf("hpkval:  version mismatch\n");
    FS_Close(file);
    return;
  }
  FS_Seek(file,local_34,FILESYSTEM_SEEK_HEAD);
  FS_Read(&local_2c,4,1,file);
  if (0x7fff < local_2c - 1U) {
    Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_2c);
    FS_Close(file);
    return;
  }
  iVar4 = 0;
  Con_Printf("# of Entries:  %i\n",local_2c);
  Con_Printf("# Type Size FileName : MD5 Hash\n");
  local_28 = Mem_Malloc(local_2c * 0x90);
  FS_Read(local_28,local_2c * 0x90,1,file);
  iVar2 = 0;
  while (iVar4 < local_2c) {
    pcVar1 = (char *)((int)local_28 + iVar2);
    COM_FileBase(pcVar1,local_1c8);
    switch(*(undefined4 *)(pcVar1 + 0x40)) {
    case 0:
      local_6c = 0x6e756f73;
      local_68 = CONCAT22(local_68._2_2_,100);
      break;
    case 1:
      local_6c = 0x6e696b73;
      local_68 = local_68 & 0xffffff00;
      break;
    case 2:
      local_6c = 0x65646f6d;
      local_68 = CONCAT22(local_68._2_2_,0x6c);
      break;
    case 3:
      local_6c = 0x61636564;
      local_68 = CONCAT22(local_68._2_2_,0x6c);
      break;
    case 4:
      local_6c = 0x656e6567;
      local_68 = 0x636972;
      break;
    case 5:
      local_6c = 0x6e657665;
      local_68 = CONCAT22(local_68._2_2_,0x74);
      break;
    default:
      local_6c = CONCAT22(local_6c._2_2_,0x3f);
    }
    puVar5 = &local_6c;
    pcVar7 = local_1c8;
    iVar4 = iVar4 + 1;
    dVar6 = (double)((float)*(int *)(pcVar1 + 0x48) * 0.0009765625);
    Con_Printf("%i: %10s %.2fK %s:  ",iVar4,puVar5,dVar6,pcVar7);
    len = *(uint *)(pcVar1 + 0x8c);
    if (len - 1 < 0x1ffff) {
                    /* Unresolved local var: uchar * pData@[???]
                       Unresolved local var: int nDataSize@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
      buf = Mem_Malloc(len + 1);
      Q_memset(buf,0,len);
      FS_Seek(file,*(int *)(pcVar1 + 0x88),FILESYSTEM_SEEK_HEAD);
      FS_Read(buf,len,1,file);
      Q_memset(&local_c4,0,0x58);
      MD5Init(&local_c4);
      MD5Update(&local_c4,buf,len);
      MD5Final(local_4c,&local_c4);
      iVar3 = Q_memcmp(pcVar1 + 0x4d,local_4c,0x10);
      if (iVar3 == 0) {
        Con_Printf(" OK\n");
      }
      else {
        Con_Printf(" MISMATCHED\n");
        Con_Printf("--------------------\n");
        pcVar1 = MD5_Print((uchar *)(pcVar1 + 0x4d));
        Con_Printf(" File  :  %s\n",pcVar1);
        pcVar1 = MD5_Print(local_4c);
        Con_Printf(" Actual:  %s\n",pcVar1);
        Con_Printf("--------------------\n");
      }
      if (buf != (uchar *)0x0) {
        Mem_Free(buf);
      }
    }
    else {
      Con_Printf("Unable to MD5 hash data, size invalid:  %i\n",len,puVar5,dVar6,pcVar7);
    }
    iVar2 = iVar2 + 0x90;
  }
  FS_Close(file);
  Mem_Free(local_28);
  return;
}


// HPAK_Validate_f  @ 0011af00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HPAK_Validate_f(void)

{
  resource_t *pakname;
  void **ppvVar1;
  char **ppcVar2;
  int iVar3;
  hash_pack_queue_t *in_stack_ffffffe4;
  hash_pack_queue_t *p;
  FileHandle_t in_stack_ffffffe8;
  
                    /* Unresolved local var: int nCurrent@[???]
                       Unresolved local var: hash_pack_header_t header@[???]
                       Unresolved local var: hash_pack_directory_t directory@[???]
                       Unresolved local var: hash_pack_entry_t * entry@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[260] szFileName@[???]
                       Unresolved local var: char[32] type@[???]
                       Unresolved local var: FileHandle_t fp@[???] */
  if (cmd_source != src_command) {
    return;
  }
  while (p = gp_hpak_queue, gp_hpak_queue != (hash_pack_queue_t *)0x0) {
                    /* Unresolved local var: hash_pack_queue_t * p@[???] */
    pakname = &gp_hpak_queue->resource;
    ppvVar1 = &gp_hpak_queue->data;
    ppcVar2 = &gp_hpak_queue->pakname;
    gp_hpak_queue = gp_hpak_queue->next;
    HPAK_AddLump((qboolean)*ppcVar2,pakname->szFileName,*ppvVar1,in_stack_ffffffe4,in_stack_ffffffe8
                );
    Mem_Free(p->pakname);
    Mem_Free(p->data);
    Mem_Free(p);
    in_stack_ffffffe4 = p;
  }
  iVar3 = Cmd_Argc();
  if (iVar3 != 2) {
    Con_Printf("Usage:  hpkval hpkname\n");
    return;
  }
  HPAK_Validate_f();
  return;
}


