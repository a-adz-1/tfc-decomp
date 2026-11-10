// HPAK_AddLump  @ 0005299c
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void HPAK_AddLump(int param_1,int param_2,undefined4 *param_3,void *param_4,FILE *param_5)

{
  void *__ptr;
  int iVar1;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar2;
  long lVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iStack_3bc;
  undefined4 *puStack_398;
  int iStack_390;
  int iStack_38c;
  uint uStack_388;
  void *pvStack_384;
  undefined4 uStack_380;
  char acStack_310 [260];
  char acStack_20c [260];
  char acStack_108 [260];
  
  puVar5 = &stack0xfffffc34;
  if (((param_2 == 0) || (param_3 == (undefined4 *)0x0)) ||
     ((param_4 == (void *)0x0 && (param_5 == (FILE *)0x0)))) {
    pcVar2 = "HPAK_AddLump called with invalid arguments\n";
  }
  else {
    if (0x1fc00 < param_3[0x12] - 0x400) {
LAB_00052bf5:
      Con_Printf();
      return;
    }
    Q_memset();
    MD5Init();
    if (param_4 == (void *)0x0) {
      lVar3 = ftell(param_5);
      __ptr = (void *)Mem_Malloc();
      Q_memset();
      fread(__ptr,param_3[0x12],1,param_5);
      fseek(param_5,lVar3,0);
      MD5Update();
      Mem_Free();
    }
    else {
      MD5Update();
    }
    MD5Final();
    iVar1 = Q_memcmp();
    if (iVar1 == 0) {
      if (param_1 != 0) {
        HPAK_AddToQueue();
        return;
      }
      sprintf(acStack_108,"%s/%s");
      COM_DefaultExtension();
      COM_FixSlashes();
      Q_strcpy(acStack_310,acStack_108);
      iVar1 = Sys_FileOpenRead();
      if (iVar1 < 0) {
        HPAK_CreatePak();
        return;
      }
      __stream = (FILE *)Sys_GetHandle();
      COM_StripExtension();
      COM_DefaultExtension();
      iVar1 = Sys_FileOpenAppend();
      if (iVar1 < 0) goto LAB_00052bf5;
      __stream_00 = (FILE *)Sys_GetHandle();
      Sys_FileRead();
      if (hash_pack_header._4_4_ == 1) {
        fseek(__stream,0,2);
        lVar3 = ftell(__stream);
        fseek(__stream,0,0);
        COM_CopyFileChunk(__stream_00,__stream,lVar3);
        fseek(__stream,hash_pack_header._8_4_,0);
        fread(&uStack_388,4,1,__stream);
        if (0x8000 < uStack_388) {
          Con_Printf();
          Sys_FileClose();
          Sys_FileClose();
          unlink(acStack_20c);
          return;
        }
        pvStack_384 = (void *)Mem_Malloc();
        fread(pvStack_384,0x90,uStack_388,__stream);
        Sys_FileClose();
        iVar1 = HPAK_FindResource(&uStack_388,(int)param_3 + 0x4d);
        if (iVar1 != 0) {
          Sys_FileClose();
          unlink(acStack_20c);
          Mem_Free();
          return;
        }
        iStack_390 = uStack_388 + 1;
        iStack_38c = Mem_Malloc();
        Q_memset();
        Q_memcpy();
        puStack_398 = (undefined4 *)0x0;
        iVar1 = 0;
        if (0 < (int)uStack_388) {
          iVar7 = 0;
          iStack_3bc = 0;
          do {
            iVar4 = Q_memcmp();
            if (iVar4 < 0) {
              puStack_398 = (undefined4 *)(iVar7 + iStack_38c);
              for (; iVar1 < (int)uStack_388; iVar1 = iVar1 + 1) {
                iVar7 = iStack_3bc + iStack_38c;
                puVar6 = (undefined4 *)(iStack_3bc + (int)pvStack_384);
                iStack_3bc = iStack_3bc + 0x90;
                puVar8 = (undefined4 *)(iVar7 + 0x90);
                for (iVar4 = 0x24; iVar4 != 0; iVar4 = iVar4 + -1) {
                  *puVar8 = *puVar6;
                  puVar6 = puVar6 + 1;
                  puVar8 = puVar8 + 1;
                }
              }
              break;
            }
            iVar7 = iVar7 + 0x90;
            iStack_3bc = iStack_3bc + 0x90;
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)uStack_388);
        }
        if (puStack_398 == (undefined4 *)0x0) {
          puStack_398 = (undefined4 *)(iStack_38c + -0x90 + iStack_390 * 0x90);
        }
        Q_memset();
        fseek(__stream_00,hash_pack_header._8_4_,0);
        puVar6 = param_3;
        puVar8 = puStack_398;
        for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        lVar3 = ftell(__stream_00);
        puStack_398[0x22] = lVar3;
        puStack_398[0x23] = param_3[0x12];
        if (param_4 == (void *)0x0) {
          COM_CopyFileChunk();
        }
        else {
          fwrite(param_4,puStack_398[0x23],1,__stream_00);
        }
        hash_pack_header._8_4_ = ftell(__stream_00);
        fwrite(&iStack_390,4,1,__stream_00);
        if (0 < iStack_390) {
          iVar7 = 0;
          iVar1 = 0;
          do {
            fwrite((void *)(iVar7 + iStack_38c),0x90,1,__stream_00);
            iVar7 = iVar7 + 0x90;
            iVar1 = iVar1 + 1;
          } while (iVar1 < iStack_390);
        }
        if (iStack_38c != 0) {
          Mem_Free();
        }
        if (pvStack_384 != (void *)0x0) {
          Mem_Free();
        }
        fseek(__stream_00,0,0);
        fwrite(hash_pack_header,0xc,1,__stream_00);
        Sys_FileClose(uStack_380);
        unlink(acStack_310);
        rename(acStack_20c,acStack_310);
        return;
      }
      Sys_FileClose();
      Sys_FileClose();
      puVar5 = &stack0xfffffc28;
      unlink(acStack_20c);
      pcVar2 = "Invalid .hpk version in HPAK_AddLump\n";
    }
    else {
      Con_Printf();
      MD5_Print();
      Con_Printf();
      MD5_Print();
      puVar5 = &stack0xfffffc18;
      Con_Printf();
      pcVar2 = "Ignoring lump addition\n";
    }
  }
  *(char **)(puVar5 + -4) = pcVar2;
  *(undefined4 *)(puVar5 + -8) = 0x52c66;
  Con_Printf();
  return;
}


// HPAK_AddToQueue  @ 00052808
void HPAK_AddToQueue(undefined4 param_1,undefined4 *param_2,int param_3,FILE *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)Mem_Malloc(0x98);
  if (puVar1 == (undefined4 *)0x0) {
    Sys_Error("Unable to allocate %i bytes for hpak queue!",0x98);
  }
  Q_memset(puVar1,0,0x98);
  uVar2 = Mem_Strdup(param_1);
  *puVar1 = uVar2;
  puVar4 = param_2;
  puVar5 = puVar1;
  for (iVar3 = 0x22; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
  }
  uVar2 = param_2[0x12];
  puVar1[0x23] = uVar2;
  iVar3 = Mem_Malloc(uVar2);
  puVar1[0x24] = iVar3;
  if (iVar3 == 0) {
    Sys_Error("Unable to allocate %i bytes for hpak queue!",puVar1[0x23]);
  }
  if (param_3 == 0) {
    if (param_4 == (FILE *)0x0) {
      Sys_Error("Add to Queue called without data or file pointer!");
    }
    else {
      fread((void *)puVar1[0x24],puVar1[0x23],1,param_4);
    }
  }
  else {
    Q_memcpy(puVar1[0x24],param_3,puVar1[0x23]);
  }
  puVar1[0x25] = gp_hpak_queue;
  gp_hpak_queue = puVar1;
  return;
}


// HPAK_CheckIntegrity  @ 00054f50
void HPAK_CheckIntegrity(undefined4 param_1)

{
  char local_108 [260];
  
  sprintf(local_108,"%s/%s",com_gamedir,param_1);
  COM_DefaultExtension(local_108,&DAT_000a602a);
  COM_FixSlashes(local_108);
  HPAK_ValidatePak(local_108);
  return;
}


// HPAK_CreatePak  @ 00053cb4
/* WARNING: Removing unreachable block (ram,0x00053f4b) */

void HPAK_CreatePak(undefined4 param_1,undefined4 *param_2,int param_3,FILE *param_4)

{
  undefined4 *puVar1;
  FILE *__s;
  long lVar2;
  void *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined1 local_170 [88];
  undefined1 auStack_118 [16];
  char local_108 [260];
  
  if (param_3 == 0) {
    if (param_4 == (FILE *)0x0) goto LAB_00053ce2;
  }
  else if (param_4 != (FILE *)0x0) {
LAB_00053ce2:
    Con_Print("HPAK_CreatePak, must specify one of pData or fpSource\n");
    return;
  }
  sprintf(local_108,"%s/%s",com_gamedir,param_1);
  COM_DefaultExtension(local_108,&DAT_000a602a);
  Con_Printf("Creating HPAK %s.\n",local_108);
  __s = fopen(local_108,"wb");
  if (__s == (FILE *)0x0) {
    Con_Printf("ERROR: couldn\'t open new .hpk, check access rights to %s.\n",local_108);
  }
  else {
    Q_memset(local_170,0,0x58);
    MD5Init(local_170);
    if (param_3 != 0) {
      MD5Update(local_170,param_3,param_2[0x12]);
      FUN_00053e00();
      return;
    }
    lVar2 = ftell(param_4);
    __ptr = (void *)Mem_Malloc(param_2[0x12] + 1);
    Q_memset(__ptr,0,param_2[0x12]);
    fread(__ptr,param_2[0x12],1,param_4);
    fseek(param_4,lVar2,0);
    MD5Update(local_170,__ptr,param_2[0x12]);
    Mem_Free(__ptr);
    MD5Final(auStack_118,local_170);
    iVar3 = Q_memcmp((int)param_2 + 0x4d,auStack_118,0x10);
    if (iVar3 == 0) {
      Q_memset(hash_pack_header,0,0xc);
      Q_strncpy(hash_pack_header,&DAT_000a6032,4);
      hash_pack_header._4_4_ = 1;
      hash_pack_header._8_4_ = 0;
      fwrite(hash_pack_header,0xc,1,__s);
      Q_memset(&hash_pack_dir,0,8);
      hash_pack_dir._0_4_ = 1;
      hash_pack_dir._4_4_ = (undefined4 *)Mem_Malloc(0x90);
      Q_memset(hash_pack_dir._4_4_,0,(int)hash_pack_dir * 0x90);
      puVar1 = hash_pack_dir._4_4_;
      puVar5 = param_2;
      puVar6 = hash_pack_dir._4_4_;
      for (iVar3 = 0x22; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      lVar2 = ftell(__s);
      puVar1[0x22] = lVar2;
      uVar4 = param_2[0x12];
      puVar1[0x23] = uVar4;
      COM_CopyFileChunk(__s,param_4,uVar4);
      lVar2 = ftell(__s);
      fwrite(&hash_pack_dir,4,1,__s);
      iVar3 = 0;
      if (0 < (int)hash_pack_dir) {
        iVar7 = 0;
        do {
          fwrite((void *)(iVar7 + (int)hash_pack_dir._4_4_),0x90,1,__s);
          iVar7 = iVar7 + 0x90;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)hash_pack_dir);
      }
      if (hash_pack_dir._4_4_ != (undefined4 *)0x0) {
        Mem_Free(hash_pack_dir._4_4_);
      }
      hash_pack_dir._4_4_ = (undefined4 *)0x0;
      hash_pack_dir._0_4_ = 0;
      hash_pack_header._8_4_ = lVar2;
      fseek(__s,0,0);
      fwrite(hash_pack_header,0xc,1,__s);
      fclose(__s);
    }
    else {
      Con_Printf("HPAK_CreatePak called with bogus lump, md5 mismatch\n");
      uVar4 = MD5_Print((int)param_2 + 0x4d);
      Con_Printf("Purported:  %s\n",uVar4);
      uVar4 = MD5_Print(auStack_118);
      Con_Printf("Actual   :  %s\n",uVar4);
      Con_Printf("Ignoring lump addition\n");
    }
  }
  return;
}


// HPAK_Extract_f  @ 00054578
void HPAK_Extract_f(void)

{
  size_t __size;
  void *pvVar1;
  int iVar2;
  FILE *__stream;
  char *__format;
  void *__ptr;
  FILE *__s;
  undefined1 *puVar3;
  int iStack_364;
  int iStack_350;
  int iStack_348;
  size_t sStack_344;
  void *pvStack_340;
  char acStack_33c [260];
  char acStack_238 [292];
  char acStack_114 [260];
  undefined1 auStack_10 [4];
  int iStack_c;
  long lStack_8;
  
  iStack_350 = -1;
  if (cmd_source != 1) {
    return;
  }
  HPAK_FlushHostQueue();
  iVar2 = Cmd_Argc();
  if (iVar2 != 3) {
    Con_Printf();
    return;
  }
  Cmd_Argv();
  iVar2 = Q_stricmp();
  if (iVar2 != 0) {
    Cmd_Argv();
    iStack_350 = Q_atoi();
  }
  puVar3 = &stack0xfffffc8c;
  Cmd_Argv();
  sprintf(acStack_114,"%s/%s",com_gamedir);
  COM_DefaultExtension(acStack_114,&DAT_000a602a);
  if (iStack_350 == -1) {
    Con_Printf();
  }
  else {
    Con_Printf("Extracting lump %i from %s\n");
  }
  __stream = fopen(acStack_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return;
  }
  fread(auStack_10,0xc,1,__stream);
  iVar2 = Q_strncmp(auStack_10,&DAT_000a6032,4);
  if (iVar2 == 0) {
    if (iStack_c != 1) {
      Con_Printf();
      goto LAB_0005472b;
    }
    fseek(__stream,lStack_8,0);
    fread(&sStack_344,4,1,__stream);
    if (sStack_344 - 1 < 0x8000) {
      Con_Printf();
      Con_Printf("# Type Size FileName : MD5 Hash\n");
      pvStack_340 = (void *)Mem_Malloc(sStack_344 * 0x90);
      fread(pvStack_340,0x90,sStack_344,__stream);
      iStack_348 = 0;
      if (0 < (int)sStack_344) {
        iStack_364 = 0;
        do {
          pvVar1 = pvStack_340;
          if ((iStack_350 == -1) || (iStack_350 == iStack_348)) {
            COM_FileBase();
            switch(*(undefined4 *)((int)pvVar1 + iStack_364 + 0x40)) {
            case 0:
              __format = "sound";
              break;
            case 1:
              __format = "skin";
              break;
            case 2:
              __format = "model";
              break;
            case 3:
              __format = "decal";
              break;
            case 4:
              __format = "generic";
              break;
            case 5:
              __format = "event";
              break;
            default:
              __format = "?";
            }
            sprintf(acStack_238,__format);
            Con_Printf("Extracting %i: %10s %.2fK %s\n",iStack_348 + 1,acStack_238,
                       (double)((float)*(int *)((int)pvVar1 + iStack_364 + 0x48) * 0.0009765625));
            __size = *(size_t *)((int)pvVar1 + iStack_364 + 0x8c);
            if (__size - 1 < 0x1ffff) {
              __ptr = (void *)Mem_Malloc();
              Q_memset(__ptr,0);
              fseek(__stream,*(long *)((int)pvVar1 + iStack_364 + 0x88),0);
              fread(__ptr,__size,1,__stream);
              sprintf(acStack_33c,"%s\\hpklmps\\lmp%04i.wad");
              COM_FixSlashes(acStack_33c);
              COM_CreatePath(acStack_33c);
              __s = fopen(acStack_33c,"wb");
              if (__s == (FILE *)0x0) {
                Con_Printf();
              }
              else {
                fwrite(__ptr,__size,1,__s);
                fclose(__s);
              }
              if (__ptr != (void *)0x0) {
                Mem_Free();
              }
            }
            else {
              Con_Printf();
            }
          }
          iStack_364 = iStack_364 + 0x90;
          iStack_348 = iStack_348 + 1;
        } while (iStack_348 < (int)sStack_344);
      }
      fclose(__stream);
      Mem_Free();
      return;
    }
  }
  puVar3 = &stack0xfffffc88;
  Con_Printf();
LAB_0005472b:
  *(FILE **)(puVar3 + -4) = __stream;
  *(undefined4 *)(puVar3 + -8) = 0x54737;
  fclose(*(FILE **)(puVar3 + -4));
  return;
}


// HPAK_FindResource  @ 00052790
undefined4 HPAK_FindResource(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *param_1) {
    iVar2 = 0;
    do {
      iVar1 = Q_memcmp(param_2,iVar2 + param_1[1] + 0x4d,0x10);
      if (iVar1 == 0) {
        if (param_3 != (undefined4 *)0x0) {
          puVar3 = (undefined4 *)(iVar2 + param_1[1]);
          for (iVar4 = 0x22; iVar4 != 0; iVar4 = iVar4 + -1) {
            *param_3 = *puVar3;
            puVar3 = puVar3 + 1;
            param_3 = param_3 + 1;
          }
        }
        return 1;
      }
      iVar2 = iVar2 + 0x90;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *param_1);
  }
  return 0;
}


// HPAK_FlushHostQueue  @ 00052928
void HPAK_FlushHostQueue(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (gp_hpak_queue != (undefined4 *)0x0) {
    while (puVar4 = gp_hpak_queue, gp_hpak_queue != (undefined4 *)0x0) {
      puVar2 = gp_hpak_queue + 0x24;
      puVar1 = gp_hpak_queue + 1;
      uVar3 = *gp_hpak_queue;
      gp_hpak_queue = (undefined4 *)gp_hpak_queue[0x25];
      HPAK_AddLump(0,uVar3,puVar1,*puVar2,0);
      Mem_Free(*puVar4);
      Mem_Free(puVar4[0x24]);
      Mem_Free(puVar4);
    }
  }
  return;
}


// HPAK_GetDataPointer  @ 000523dc
undefined4 HPAK_GetDataPointer(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  FILE *__stream;
  int iVar3;
  int iVar4;
  void *__ptr;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int local_128;
  undefined4 local_120;
  size_t local_11c;
  void *local_118;
  char local_114 [260];
  undefined1 local_10 [4];
  int local_c;
  long local_8;
  
  local_128 = 0;
  local_120 = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  iVar3 = gp_hpak_queue;
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
    iVar3 = gp_hpak_queue;
  }
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x94)) {
    iVar2 = Q_stricmp();
    if ((iVar2 == 0) && (iVar2 = Q_memcmp(), iVar2 == 0)) {
      if (param_3 != (int *)0x0) {
        iVar2 = Mem_Malloc();
        if (iVar2 == 0) {
          Sys_Error();
        }
        Q_memcpy();
        *param_3 = iVar2;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = *(int *)(iVar3 + 0x8c);
      }
      return 1;
    }
  }
  sprintf(local_114,"%s/%s");
  COM_DefaultExtension(local_114,&DAT_000a602a);
  __stream = fopen(local_114,"rb");
  if (__stream != (FILE *)0x0) {
    fread(local_10,0xc,1,__stream);
    iVar3 = Q_strncmp(local_10,&DAT_000a6032,4);
    if (iVar3 == 0) {
      if (local_c == 1) {
        fseek(__stream,local_8,0);
        fread(&local_11c,4,1,__stream);
        if (local_11c - 1 < 0x8000) {
          local_118 = (void *)Mem_ZeroMalloc();
          fread(local_118,0x90,local_11c,__stream);
          bVar1 = false;
          iVar3 = 0;
          if (0 < (int)local_11c) {
            iVar2 = 0;
            do {
              local_128 = iVar2 + (int)local_118;
              iVar4 = Q_memcmp();
              if (iVar4 == 0) {
                fseek(__stream,*(long *)(local_128 + 0x88),0);
                bVar1 = true;
                break;
              }
              iVar2 = iVar2 + 0x90;
              iVar3 = iVar3 + 1;
            } while (iVar3 < (int)local_11c);
          }
          if ((((bVar1) && (local_120 = 1, param_3 != (int *)0x0)) && (local_128 != 0)) &&
             (0 < *(int *)(local_128 + 0x8c))) {
            if (param_4 != (int *)0x0) {
              *param_4 = *(int *)(local_128 + 0x8c);
            }
            __ptr = (void *)Mem_Malloc();
            if (__ptr == (void *)0x0) {
              Con_Printf();
              if (param_4 != (int *)0x0) {
                *param_4 = 0;
              }
              uVar5 = FUN_00052760();
              return uVar5;
            }
            fread(__ptr,*(size_t *)(local_128 + 0x8c),1,__stream);
            *param_3 = (int)__ptr;
          }
          Mem_Free();
          fclose(__stream);
          return local_120;
        }
        puVar6 = &stack0xfffffebc;
        Con_Printf();
      }
      else {
        puVar6 = &stack0xfffffec0;
        Con_Printf();
      }
      puVar7 = (undefined4 *)(puVar6 + -4);
      *(FILE **)(puVar6 + -4) = __stream;
    }
    else {
      Con_Printf();
      puVar7 = (undefined4 *)&stack0xfffffeb8;
    }
    puVar7[-1] = 0x525d7;
    fclose((FILE *)*puVar7);
  }
  return 0;
}


// HPAK_GetItem  @ 00054a64
undefined * HPAK_GetItem(int param_1)

{
  void *pvVar1;
  FILE *__stream;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  size_t local_11c;
  void *local_118;
  undefined1 local_10 [4];
  int local_c;
  long local_8;
  
  HPAK_FlushHostQueue();
  sprintf(name_30,"%s/%s");
  COM_DefaultExtension(name_30,&DAT_000a602a);
  __stream = fopen(name_30,"rb");
  if (__stream == (FILE *)0x0) {
    return &DAT_000a68db;
  }
  fread(local_10,0xc,1,__stream);
  iVar2 = Q_strncmp(local_10,&DAT_000a6032,4);
  if (iVar2 == 0) {
    if (local_c != 1) {
      puVar4 = &stack0xfffffecc;
      Con_Printf();
      goto LAB_00054b6f;
    }
    fseek(__stream,local_8,0);
    fread(&local_11c,4,1,__stream);
    if (local_11c - 1 < 0x8000) {
      local_118 = (void *)Mem_Malloc();
      fread(local_118,0x90,local_11c,__stream);
      pvVar1 = local_118;
      iVar2 = local_11c - 1;
      if (param_1 < (int)(local_11c - 1)) {
        iVar2 = param_1;
      }
      COM_FileBase();
      uVar3 = MD5_Print((int)pvVar1 + iVar2 * 0x90 + 0x4d);
      sprintf(name_30,"!MD5%s",uVar3);
      fclose(__stream);
      Mem_Free(local_118);
      return name_30;
    }
  }
  puVar4 = &stack0xfffffec8;
  Con_Printf();
LAB_00054b6f:
  *(FILE **)(puVar4 + -4) = __stream;
  *(undefined4 *)(puVar4 + -8) = 0x54b75;
  fclose(*(FILE **)(puVar4 + -4));
  return &DAT_000a68db;
}


// HPAK_Init  @ 000549f4
void HPAK_Init(void)

{
  Cmd_AddCommand("hpklist",HPAK_List_f);
  Cmd_AddCommand("hpkremove",HPAK_Remove_f);
  Cmd_AddCommand("hpkval",HPAK_Validate_f);
  Cmd_AddCommand("hpkextract",HPAK_Extract_f);
  gp_hpak_queue = 0;
  return;
}


// HPAK_List_f  @ 000539f0
void HPAK_List_f(void)

{
  void *pvVar1;
  FILE *__stream;
  int iVar2;
  char *__format;
  undefined1 *puVar3;
  int local_244;
  size_t local_240;
  void *local_23c;
  char local_238 [32];
  undefined1 local_218 [260];
  char local_114 [260];
  undefined1 local_10 [4];
  int local_c;
  long local_8;
  
  if (cmd_source != 1) {
    return;
  }
  HPAK_FlushHostQueue();
  Cmd_Argv();
  sprintf(local_114,"%s/%s",com_gamedir);
  COM_DefaultExtension(local_114,&DAT_000a602a);
  Con_Printf("Contents for %s.\n",local_114);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return;
  }
  fread(local_10,0xc,1,__stream);
  iVar2 = Q_strncmp(local_10,&DAT_000a6032,4);
  if (iVar2 == 0) {
    if (local_c != 1) {
      puVar3 = &stack0xfffffda0;
      Con_Printf();
      goto LAB_00053b1f;
    }
    fseek(__stream,local_8,0);
    fread(&local_240,4,1,__stream);
    if (local_240 - 1 < 0x8000) {
      Con_Printf();
      Con_Printf("# Type Size FileName : MD5 Hash\n");
      local_23c = (void *)Mem_Malloc();
      fread(local_23c,0x90,local_240,__stream);
      local_244 = 0;
      if (0 < (int)local_240) {
        do {
          pvVar1 = local_23c;
          COM_FileBase();
          switch(*(undefined4 *)((int)pvVar1 + local_244 * 0x90 + 0x40)) {
          case 0:
            __format = "sound";
            break;
          case 1:
            __format = "skin";
            break;
          case 2:
            __format = "model";
            break;
          case 3:
            __format = "decal";
            break;
          case 4:
            __format = "generic";
            break;
          case 5:
            __format = "event";
            break;
          default:
            __format = "?";
          }
          sprintf(local_238,__format);
          MD5_Print();
          iVar2 = local_244 * 0x90;
          local_244 = local_244 + 1;
          Con_Printf("%i: %10s %.2fK %s\n  :  %s\n",local_244,local_238,
                     (double)((float)*(int *)((int)pvVar1 + iVar2 + 0x48) * 0.0009765625),local_218)
          ;
        } while (local_244 < (int)local_240);
      }
      fclose(__stream);
      Mem_Free();
      return;
    }
  }
  puVar3 = &stack0xfffffd9c;
  Con_Printf();
LAB_00053b1f:
  *(FILE **)(puVar3 + -4) = __stream;
  *(undefined4 *)(puVar3 + -8) = 0x53b2b;
  fclose(*(FILE **)(puVar3 + -4));
  return;
}


// HPAK_RemoveLump  @ 000530a0
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void HPAK_RemoveLump(char *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar3;
  int iVar4;
  long lVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iStack_350;
  int iStack_34c;
  int iStack_334;
  int iStack_320;
  int iStack_31c;
  size_t sStack_318;
  void *pvStack_314;
  char local_310 [260];
  char local_20c [260];
  char local_108 [260];
  
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) || (param_2 == 0)) {
    Con_Printf();
    return;
  }
  HPAK_FlushHostQueue();
  Cmd_Argv();
  sprintf(local_108,"%s/%s");
  COM_DefaultExtension(local_108,&DAT_000a602a);
  pcVar3 = local_310;
  Q_strcpy(pcVar3,local_108);
  __stream = fopen(pcVar3,"rb");
  if (__stream == (FILE *)0x0) {
    puVar6 = &stack0xfffffc9c;
    pcVar3 = "Error:  couldn\'t open HPAK file %s for removal.\n";
LAB_000531af:
    *(char **)(puVar6 + -4) = pcVar3;
    *(undefined4 *)(puVar6 + -8) = 0x531b5;
    Con_Printf();
    return;
  }
  COM_StripExtension();
  COM_DefaultExtension();
  __stream_00 = fopen(local_20c,"w+b");
  if (__stream_00 == (FILE *)0x0) {
    fclose(__stream);
    puVar6 = &stack0xfffffc98;
    pcVar3 = "ERROR: couldn\'t create %s.\n";
    goto LAB_000531af;
  }
  fseek(__stream,0,0);
  fseek(__stream_00,0,0);
  fread(hash_pack_header,0xc,1,__stream);
  fwrite(hash_pack_header,0xc,1,__stream_00);
  iVar4 = Q_strncmp(hash_pack_header,&DAT_000a6032);
  if (iVar4 != 0) {
LAB_000532a3:
    Con_Printf();
    fclose(__stream_00);
    fclose(__stream);
    unlink(local_20c);
    return;
  }
  if (hash_pack_header._4_4_ == 1) {
    fseek(__stream,hash_pack_header._8_4_,0);
    fread(&sStack_318,4,1,__stream);
    if (0x7fff < sStack_318 - 1) goto LAB_000532a3;
    if (sStack_318 == 1) {
      Con_Printf();
      fclose(__stream_00);
      fclose(__stream);
      puVar8 = &stack0xfffffc8c;
      unlink(local_20c);
      goto LAB_000533d2;
    }
    pvStack_314 = (void *)Mem_Malloc();
    fread(pvStack_314,0x90,sStack_318,__stream);
    iStack_320 = sStack_318 - 1;
    iStack_31c = Mem_Malloc(iStack_320 * 0x90);
    iVar4 = HPAK_FindResource(&sStack_318,param_2 + 0x4d,0);
    if (iVar4 != 0) {
      Con_Printf();
      iStack_334 = 0;
      if (0 < (int)sStack_318) {
        iStack_34c = 0;
        iStack_350 = 0;
        do {
          puVar1 = (undefined4 *)(iStack_34c + (int)pvStack_314);
          iVar4 = Q_memcmp();
          if (iVar4 != 0) {
            puVar2 = (undefined4 *)(iStack_350 + iStack_31c);
            puVar9 = puVar1;
            puVar10 = puVar2;
            for (iVar4 = 0x24; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            }
            lVar5 = ftell(__stream_00);
            puVar2[0x22] = lVar5;
            fseek(__stream,puVar1[0x22],0);
            COM_CopyFileChunk(__stream_00,__stream);
            iStack_350 = iStack_350 + 0x90;
          }
          iStack_34c = iStack_34c + 0x90;
          iStack_334 = iStack_334 + 1;
        } while (iStack_334 < (int)sStack_318);
      }
      hash_pack_header._8_4_ = ftell(__stream_00);
      fwrite(&iStack_320,4,1,__stream_00);
      iStack_334 = 0;
      if (0 < iStack_320) {
        iVar4 = 0;
        do {
          fwrite((void *)(iVar4 + iStack_31c),0x90,1,__stream_00);
          iVar4 = iVar4 + 0x90;
          iStack_334 = iStack_334 + 1;
        } while (iStack_334 < iStack_320);
      }
      fseek(__stream_00,0,0);
      fwrite(hash_pack_header,0xc,1,__stream_00);
      fclose(__stream_00);
      fclose(__stream);
      unlink(pcVar3);
      rename(local_20c,pcVar3);
      Mem_Free();
      Mem_Free(pvStack_314);
      return;
    }
    puVar7 = &stack0xfffffc98;
    Con_Printf();
  }
  else {
    puVar7 = &stack0xfffffc9c;
    Con_Printf();
  }
  *(FILE **)(puVar7 + -4) = __stream_00;
  *(undefined4 *)(puVar7 + -8) = 0x533c0;
  fclose(*(FILE **)(puVar7 + -4));
  puVar8 = puVar7 + -8;
  *(FILE **)(puVar7 + -8) = __stream;
  *(undefined4 *)(puVar7 + -0xc) = 0x533cc;
  fclose(*(FILE **)(puVar7 + -8));
  pcVar3 = local_20c;
LAB_000533d2:
  *(char **)(puVar8 + -4) = pcVar3;
  *(undefined4 *)(puVar8 + -8) = 0x533d8;
  unlink(*(char **)(puVar8 + -4));
  return;
}


// HPAK_Remove_f  @ 00054068
void HPAK_Remove_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_8c [136];
  
  if (cmd_source == 1) {
    HPAK_FlushHostQueue();
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      uVar2 = Cmd_Argv(2,local_8c);
      uVar2 = Q_atoi(uVar2);
      uVar2 = Cmd_Argv(1,uVar2);
      iVar1 = HPAK_ResourceForIndex(uVar2);
      if (iVar1 == 0) {
        uVar2 = Cmd_Argv(1);
        uVar2 = Cmd_Argv(2,uVar2);
        uVar2 = Q_atoi(uVar2);
        Con_Printf("Could not locate resource %i in %s\n",uVar2);
      }
      else {
        uVar2 = Cmd_Argv(1,local_8c);
        HPAK_RemoveLump(uVar2);
      }
    }
    else {
      Con_Printf("Usage:  hpkremove <hpk> <index>\n");
    }
  }
  return;
}


// HPAK_ResourceForHash  @ 00053814
undefined4 HPAK_ResourceForHash(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  size_t local_11c;
  void *pvStack_118;
  char local_114 [260];
  undefined1 local_10 [4];
  int local_c;
  long local_8;
  
  for (puVar4 = gp_hpak_queue; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)puVar4[0x25]) {
    iVar1 = Q_stricmp();
    if ((iVar1 == 0) && (iVar1 = Q_memcmp((int)puVar4 + 0x51), iVar1 == 0)) {
      if (param_3 != (undefined4 *)0x0) {
        for (iVar1 = 0x22; puVar4 = puVar4 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
          *param_3 = *puVar4;
          param_3 = param_3 + 1;
        }
      }
      return 1;
    }
  }
  sprintf(local_114,"%s/%s");
  COM_DefaultExtension(local_114,&DAT_000a602a);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return 0;
  }
  fread(local_10,0xc,1,__stream);
  iVar1 = Q_strncmp(local_10,&DAT_000a6032,4);
  if (iVar1 == 0) {
    if (local_c != 1) {
      puVar3 = &stack0xfffffecc;
      Con_Printf();
      goto LAB_000539d9;
    }
    fseek(__stream,local_8,0);
    fread(&local_11c,4,1,__stream);
    if (local_11c - 1 < 0x8000) {
      pvStack_118 = (void *)Mem_Malloc();
      fread(pvStack_118,0x90,local_11c,__stream);
      uVar2 = HPAK_FindResource(&local_11c,param_2,param_3);
      fclose(__stream);
      Mem_Free();
      return uVar2;
    }
  }
  puVar3 = &stack0xfffffec8;
  Con_Printf();
LAB_000539d9:
  *(FILE **)(puVar3 + -4) = __stream;
  *(undefined1 **)(puVar3 + -8) = &LAB_000539df;
  fclose(*(FILE **)(puVar3 + -4));
  return 0;
}


// HPAK_ResourceForIndex  @ 00053640
undefined4 HPAK_ResourceForIndex(undefined4 param_1,int param_2,undefined4 *param_3)

{
  FILE *__stream;
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  size_t sStack_11c;
  void *pvStack_118;
  char local_114 [260];
  undefined1 auStack_10 [4];
  int iStack_c;
  long lStack_8;
  
  if (cmd_source != 1) {
    return 0;
  }
  sprintf(local_114,"%s/%s");
  COM_DefaultExtension(local_114,&DAT_000a602a);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return 0;
  }
  fread(auStack_10,0xc,1,__stream);
  iVar1 = Q_strncmp(auStack_10,&DAT_000a6032,4);
  if (iVar1 == 0) {
    if (iStack_c != 1) {
      puVar2 = &stack0xfffffecc;
      Con_Printf();
      goto LAB_0005379d;
    }
    fseek(__stream,lStack_8,0);
    fread(&sStack_11c,4,1,__stream);
    if (((sStack_11c - 1 < 0x8000) && (pvStack_118 = (void *)Mem_Malloc(), 0 < param_2)) &&
       (param_2 <= (int)sStack_11c)) {
      fread(pvStack_118,0x90,sStack_11c,__stream);
      puVar3 = (undefined4 *)((int)pvStack_118 + param_2 * 0x90 + -0x90);
      for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_3 = *puVar3;
        puVar3 = puVar3 + 1;
        param_3 = param_3 + 1;
      }
      fclose(__stream);
      Mem_Free(pvStack_118);
      return 1;
    }
  }
  puVar2 = &stack0xfffffec8;
  Con_Printf();
LAB_0005379d:
  *(FILE **)(puVar2 + -4) = __stream;
  *(undefined4 *)(puVar2 + -8) = 0x537a9;
  fclose(*(FILE **)(puVar2 + -4));
  return 0;
}


// HPAK_ValidatePak  @ 00054c20
void HPAK_ValidatePak(char *param_1)

{
  size_t __size;
  void *pvVar1;
  FILE *__stream;
  int iVar2;
  void *__ptr;
  undefined1 *puVar3;
  char cVar4;
  int local_1a4;
  int local_188;
  size_t local_184;
  void *local_180;
  undefined1 local_17c [88];
  undefined1 local_124 [276];
  undefined1 local_10 [4];
  int local_c;
  long local_8;
  
  HPAK_FlushHostQueue();
  __stream = fopen(param_1,"rb");
  if (__stream == (FILE *)0x0) {
    return;
  }
  fread(local_10,0xc,1,__stream);
  if ((local_c == 1) && (iVar2 = Q_strncmp(), iVar2 == 0)) {
    fseek(__stream,local_8,0);
    fread(&local_184,4,1,__stream);
    if (local_184 - 1 < 0x8000) {
      local_180 = (void *)Mem_Malloc();
      fread(local_180,0x90,local_184,__stream);
      local_188 = 0;
      if (0 < (int)local_184) {
        local_1a4 = 0;
        do {
          pvVar1 = local_180;
          COM_FileBase();
          __size = *(size_t *)((int)pvVar1 + local_1a4 + 0x8c);
          if (__size - 1 < 0x1ffff) {
            __ptr = (void *)Mem_Malloc();
            Q_memset(__ptr);
            fseek(__stream,*(long *)((int)pvVar1 + local_1a4 + 0x88),0);
            fread(__ptr,__size,1,__stream);
            Q_memset();
            MD5Init(local_17c);
            MD5Update(local_17c,__ptr,__size);
            MD5Final(local_124,local_17c);
            iVar2 = Q_memcmp();
            cVar4 = iVar2 != 0;
            if ((bool)cVar4) {
              Con_Printf();
            }
            if (__ptr != (void *)0x0) {
              Mem_Free();
            }
          }
          else {
            cVar4 = '\x02';
          }
          if (cVar4 != '\0') {
            Mem_Free();
            puVar3 = &stack0xfffffe50;
            if (cVar4 == '\x02') {
              Con_Printf();
              Con_Printf("Unable to MD5 hash data lump %i, size invalid:  %i\n",local_188 + 1);
              puVar3 = &stack0xfffffe50;
            }
            goto LAB_00054eec;
          }
          local_1a4 = local_1a4 + 0x90;
          local_188 = local_188 + 1;
        } while (local_188 < (int)local_184);
      }
      fclose(__stream);
      Mem_Free();
      return;
    }
    Con_Printf();
    puVar3 = &stack0xfffffe44;
  }
  else {
    Con_Printf();
    puVar3 = &stack0xfffffe48;
  }
LAB_00054eec:
  *(FILE **)(puVar3 + -4) = __stream;
  *(undefined4 *)(puVar3 + -8) = 0x54ef8;
  fclose(*(FILE **)(puVar3 + -4));
  *(char **)(puVar3 + -8) = param_1;
  *(undefined4 *)(puVar3 + -0xc) = 0x54f01;
  Sys_Unlink();
  return;
}


// HPAK_Validate_f  @ 00054128
void HPAK_Validate_f(void)

{
  size_t __size;
  void *pvVar1;
  int iVar2;
  FILE *__stream;
  void *__ptr;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  char *__format;
  size_t local_2a8;
  void *local_2a4;
  undefined1 auStack_2a0 [88];
  undefined1 auStack_248 [16];
  char local_238 [292];
  char local_114 [260];
  undefined1 local_10 [4];
  int local_c;
  long local_8;
  
  if (cmd_source == 1) {
    HPAK_FlushHostQueue();
    iVar2 = Cmd_Argc();
    if (iVar2 == 2) {
      Cmd_Argv();
      sprintf(local_114,"%s/%s",com_gamedir);
      COM_DefaultExtension(local_114,&DAT_000a602a);
      Con_Printf("Validating %s.\n",local_114);
      __stream = fopen(local_114,"rb");
      if (__stream == (FILE *)0x0) {
        Con_Printf();
      }
      else {
        fread(local_10,0xc,1,__stream);
        iVar2 = Q_strncmp(local_10,&DAT_000a6032,4);
        if (iVar2 == 0) {
          if (local_c == 1) {
            fseek(__stream,local_8,0);
            fread(&local_2a8,4,1,__stream);
            if (local_2a8 - 1 < 0x8000) {
              Con_Printf();
              Con_Printf("# Type Size FileName : MD5 Hash\n");
              local_2a4 = (void *)Mem_Malloc(local_2a8 * 0x90);
              fread(local_2a4,0x90,local_2a8,__stream);
              if (0 < (int)local_2a8) {
                iVar2 = 0;
                do {
                  pvVar1 = local_2a4;
                  COM_FileBase();
                  switch(*(undefined4 *)((int)pvVar1 + iVar2 * 0x90 + 0x40)) {
                  case 0:
                    __format = "sound";
                    break;
                  case 1:
                    __format = "skin";
                    break;
                  case 2:
                    __format = "model";
                    break;
                  case 3:
                    __format = "decal";
                    break;
                  case 4:
                    __format = "generic";
                    break;
                  case 5:
                    __format = "event";
                    break;
                  default:
                    __format = "?";
                  }
                  sprintf(local_238,__format);
                  iVar6 = iVar2 + 1;
                  Con_Printf("%i: %10s %.2fK %s:  ",iVar6,local_238,
                             (double)((float)*(int *)((int)pvVar1 + iVar2 * 0x90 + 0x48) *
                                     0.0009765625));
                  __size = *(size_t *)((int)pvVar1 + iVar2 * 0x90 + 0x8c);
                  if (__size - 1 < 0x1ffff) {
                    __ptr = (void *)Mem_Malloc();
                    Q_memset(__ptr,0);
                    fseek(__stream,*(long *)((int)pvVar1 + iVar2 * 0x90 + 0x88),0);
                    fread(__ptr,__size,1,__stream);
                    Q_memset(auStack_2a0);
                    MD5Init(auStack_2a0);
                    MD5Update(auStack_2a0,__ptr,__size);
                    MD5Final(auStack_248,auStack_2a0);
                    iVar4 = (int)pvVar1 + iVar2 * 0x90 + 0x4d;
                    iVar2 = Q_memcmp(iVar4);
                    if (iVar2 != 0) {
                      Con_Printf();
                      Con_Printf();
                      uVar3 = MD5_Print(iVar4);
                      Con_Printf(" File  :  %s\n",uVar3);
                      uVar3 = MD5_Print(auStack_248);
                      Con_Printf(" Actual:  %s\n",uVar3);
                    }
                    Con_Printf();
                    if (__ptr != (void *)0x0) {
                      Mem_Free();
                    }
                  }
                  else {
                    Con_Printf();
                  }
                  iVar2 = iVar6;
                } while (iVar6 < (int)local_2a8);
              }
              fclose(__stream);
              Mem_Free();
              return;
            }
            puVar5 = &stack0xfffffd24;
            Con_Printf();
          }
          else {
            puVar5 = &stack0xfffffd28;
            Con_Printf();
          }
          *(FILE **)(puVar5 + -4) = __stream;
          *(undefined4 *)(puVar5 + -8) = 0x54293;
          fclose(*(FILE **)(puVar5 + -4));
        }
        else {
          Con_Printf();
          fclose(__stream);
        }
      }
    }
    else {
      Con_Printf();
    }
  }
  return;
}


