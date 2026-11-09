// HPAK_AddLump  @ 08055230
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void HPAK_AddLump(int param_1,int param_2,undefined4 *param_3,void *param_4,FILE *param_5)

{
  byte bVar1;
  byte bVar2;
  void *__s;
  uint uVar3;
  undefined4 uVar4;
  FILE *__stream;
  FILE *__stream_00;
  long lVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  bool bVar12;
  bool bVar13;
  undefined4 *local_398;
  int local_390;
  void *local_38c;
  uint local_388;
  void *local_384;
  undefined4 local_380;
  undefined4 local_37c;
  undefined4 local_378 [22];
  byte local_320 [16];
  char local_310 [260];
  char local_20c [260];
  char local_108 [260];
  
  if (((param_2 == 0) || (param_3 == (undefined4 *)0x0)) ||
     ((param_4 == (void *)0x0 && (param_5 == (FILE *)0x0)))) {
    Con_Printf("HPAK_AddLump called with invalid arguments\n");
  }
  else if (param_3[0x12] - 0x400 < 0x1fc01) {
    puVar9 = local_378;
    for (iVar6 = 0x16; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    MD5Init(local_378);
    if (param_4 == (void *)0x0) {
      lVar5 = ftell(param_5);
      __s = malloc(param_3[0x12] + 1);
      memset(__s,0,param_3[0x12]);
      fread(__s,param_3[0x12],1,param_5);
      fseek(param_5,lVar5,0);
      MD5Update(local_378,__s,param_3[0x12]);
      free(__s);
    }
    else {
      MD5Update(local_378,param_4,param_3[0x12]);
    }
    MD5Final(local_320,local_378);
    iVar6 = 0x10;
    bVar12 = false;
    uVar3 = 0;
    bVar13 = true;
    pbVar8 = (byte *)((int)param_3 + 0x4d);
    pbVar10 = local_320;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar12 = *pbVar8 < *pbVar10;
      bVar13 = *pbVar8 == *pbVar10;
      pbVar8 = pbVar8 + 1;
      pbVar10 = pbVar10 + 1;
    } while (bVar13);
    if (!bVar13) {
      uVar3 = -(uint)bVar12 | 1;
    }
    if (uVar3 == 0) {
      if (param_1 == 0) {
        sprintf(local_108,"%s/%s",com_gamedir,param_2);
        COM_DefaultExtension(local_108,&DAT_0809f84a);
        COM_FixSlashes(local_108);
        strcpy(local_310,local_108);
        iVar6 = Sys_FileOpenRead(local_108,&local_37c);
        if (iVar6 < 0) {
          HPAK_CreatePak(param_2,param_3,param_4,param_5);
        }
        else {
          __stream = (FILE *)Sys_GetHandle(local_37c);
          COM_StripExtension(local_108,local_20c);
          COM_DefaultExtension(local_20c,&DAT_0809faab);
          iVar6 = Sys_FileOpenAppend(local_20c,&local_380);
          if (iVar6 < 0) {
            Con_Printf("ERROR: couldn\'t open %s.\n",local_108);
          }
          else {
            __stream_00 = (FILE *)Sys_GetHandle(local_380);
            Sys_FileRead(local_37c,hash_pack_header,0xc);
            if (hash_pack_header._4_4_ == 1) {
              fseek(__stream,0,2);
              lVar5 = ftell(__stream);
              fseek(__stream,0,0);
              COM_CopyFileChunk(__stream_00,__stream,lVar5);
              fseek(__stream,hash_pack_header._8_4_,0);
              fread(&local_388,4,1,__stream);
              if (local_388 < 0x8001) {
                local_384 = malloc((local_388 + 1) * 0x70);
                fread(local_384,0x70,local_388,__stream);
                Sys_FileClose(local_37c);
                iVar6 = HPAK_FindResource(&local_388,(int)param_3 + 0x4d,0);
                if (iVar6 == 0) {
                  local_390 = local_388 + 1;
                  local_38c = malloc(local_390 * 0x70);
                  memset(local_38c,0,local_390 * 0x70);
                  memcpy(local_38c,local_384,local_388 * 0x70);
                  local_398 = (undefined4 *)0x0;
                  iVar6 = 0;
                  if (0 < (int)local_388) {
LAB_080556d0:
                    iVar7 = 0x10;
                    bVar12 = false;
                    pbVar8 = (byte *)((int)param_3 + 0x4d);
                    pbVar10 = (byte *)((int)local_384 + iVar6 * 0x70 + 0x4d);
                    do {
                      if (iVar7 == 0) break;
                      iVar7 = iVar7 + -1;
                      bVar2 = *pbVar10;
                      bVar1 = *pbVar8;
                      bVar12 = bVar1 < bVar2;
                      pbVar8 = pbVar8 + 1;
                      pbVar10 = pbVar10 + 1;
                    } while (bVar1 == bVar2);
                    if (!bVar12) goto LAB_08055780;
                    local_398 = (undefined4 *)(iVar6 * 0x70 + (int)local_38c);
                    for (; iVar6 < (int)local_388; iVar6 = iVar6 + 1) {
                      puVar9 = (undefined4 *)(iVar6 * 0x70 + (int)local_384);
                      puVar11 = (undefined4 *)((int)local_38c + iVar6 * 0x70 + 0x70);
                      for (iVar7 = 0x1c; iVar7 != 0; iVar7 = iVar7 + -1) {
                        *puVar11 = *puVar9;
                        puVar9 = puVar9 + 1;
                        puVar11 = puVar11 + 1;
                      }
                    }
                  }
LAB_0805578d:
                  if (local_398 == (undefined4 *)0x0) {
                    local_398 = (undefined4 *)(local_390 * 0x70 + -0x70 + (int)local_38c);
                  }
                  puVar9 = local_398;
                  for (iVar6 = 0x1c; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *puVar9 = 0;
                    puVar9 = puVar9 + 1;
                  }
                  fseek(__stream_00,hash_pack_header._8_4_,0);
                  puVar9 = param_3;
                  puVar11 = local_398;
                  for (iVar6 = 0x1a; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *puVar11 = *puVar9;
                    puVar9 = puVar9 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  lVar5 = ftell(__stream_00);
                  local_398[0x1a] = lVar5;
                  local_398[0x1b] = param_3[0x12];
                  if (param_4 == (void *)0x0) {
                    COM_CopyFileChunk(__stream_00,param_5,local_398[0x1b]);
                  }
                  else {
                    fwrite(param_4,local_398[0x1b],1,__stream_00);
                  }
                  hash_pack_header._8_4_ = ftell(__stream_00);
                  fwrite(&local_390,4,1,__stream_00);
                  iVar6 = 0;
                  if (0 < local_390) {
                    do {
                      fwrite((void *)(iVar6 * 0x70 + (int)local_38c),0x70,1,__stream_00);
                      iVar6 = iVar6 + 1;
                    } while (iVar6 < local_390);
                  }
                  if (local_38c != (void *)0x0) {
                    free(local_38c);
                  }
                  if (local_384 != (void *)0x0) {
                    free(local_384);
                  }
                  fseek(__stream_00,0,0);
                  fwrite(hash_pack_header,0xc,1,__stream_00);
                  Sys_FileClose(local_380);
                  unlink(local_310);
                  rename(local_20c,local_310);
                }
                else {
                  Sys_FileClose(local_380);
                  unlink(local_20c);
                  free(local_384);
                }
              }
              else {
                Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_388);
                Sys_FileClose(local_37c);
                Sys_FileClose(local_380);
                unlink(local_20c);
              }
            }
            else {
              Sys_FileClose(local_37c);
              Sys_FileClose(local_380);
              unlink(local_20c);
              Con_Printf("Invalid .hpk version in HPAK_AddLump\n");
            }
          }
        }
      }
      else {
        HPAK_AddToQueue(param_2,param_3,param_4,param_5);
      }
    }
    else {
      Con_Printf("HPAK_AddLump called with bogus lump, md5 mismatch\n");
      uVar4 = MD5_Print((int)param_3 + 0x4d);
      Con_Printf("Purported:  %s\n",uVar4);
      uVar4 = MD5_Print(local_320);
      Con_Printf("Actual   :  %s\n",uVar4);
      Con_Printf("Ignoring lump addition\n");
    }
  }
  else {
    Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",param_3[0x12]);
  }
  return;
LAB_08055780:
  iVar6 = iVar6 + 1;
  if ((int)local_388 <= iVar6) goto LAB_0805578d;
  goto LAB_080556d0;
}


// HPAK_AddToQueue  @ 080550e0
void HPAK_AddToQueue(char *param_1,undefined4 *param_2,void *param_3,FILE *param_4)

{
  size_t __size;
  undefined4 *puVar1;
  char *pcVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = malloc(0x78);
  if (puVar1 == (undefined4 *)0x0) {
    Sys_Error("Unable to allocate %i bytes for hpak queue!",0x78);
  }
  puVar6 = puVar1;
  for (iVar4 = 0x1e; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  pcVar2 = strdup(param_1);
  *puVar1 = pcVar2;
  puVar5 = param_2;
  puVar6 = puVar1;
  for (iVar4 = 0x1a; puVar6 = puVar6 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  __size = param_2[0x12];
  puVar1[0x1b] = __size;
  pvVar3 = malloc(__size);
  puVar1[0x1c] = pvVar3;
  if (pvVar3 == (void *)0x0) {
    Sys_Error("Unable to allocate %i bytes for hpak queue!",puVar1[0x1b]);
  }
  if (param_3 == (void *)0x0) {
    if (param_4 == (FILE *)0x0) {
      Sys_Error("Add to Queue called without data or file pointer!");
    }
    else {
      fread((void *)puVar1[0x1c],puVar1[0x1b],1,param_4);
    }
  }
  else {
    memcpy((void *)puVar1[0x1c],param_3,puVar1[0x1b]);
  }
  puVar1[0x1d] = gp_hpak_queue;
  gp_hpak_queue = puVar1;
  return;
}


// HPAK_CreatePak  @ 080564c0
void HPAK_CreatePak(undefined4 param_1,undefined4 *param_2,void *param_3,FILE *param_4)

{
  FILE *__s;
  void *__s_00;
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  bool bVar10;
  bool bVar11;
  undefined4 local_170 [22];
  byte local_118 [16];
  char local_108 [260];
  
  if (param_3 == (void *)0x0) {
    if (param_4 == (FILE *)0x0) goto LAB_080564e6;
  }
  else if (param_4 != (FILE *)0x0) {
LAB_080564e6:
    Con_Print("HPAK_CreatePak, must specify one of pData or fpSource\n");
    return;
  }
  sprintf(local_108,"%s/%s",com_gamedir,param_1);
  COM_DefaultExtension(local_108,&DAT_0809f84a);
  Con_Printf("Creating HPAK %s.\n",local_108);
  __s = fopen(local_108,"wb");
  if (__s == (FILE *)0x0) {
    Con_Printf("ERROR: couldn\'t open new .hpk, check access rights to %s.\n",local_108);
  }
  else {
    puVar7 = local_170;
    for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    MD5Init(local_170);
    if (param_3 == (void *)0x0) {
      lVar3 = ftell(param_4);
      __s_00 = malloc(param_2[0x12] + 1);
      memset(__s_00,0,param_2[0x12]);
      fread(__s_00,param_2[0x12],1,param_4);
      fseek(param_4,lVar3,0);
      MD5Update(local_170,__s_00,param_2[0x12]);
      free(__s_00);
    }
    else {
      MD5Update(local_170,param_3,param_2[0x12]);
    }
    MD5Final(local_118,local_170);
    iVar4 = 0x10;
    bVar10 = false;
    uVar1 = 0;
    bVar11 = true;
    pbVar5 = (byte *)((int)param_2 + 0x4d);
    pbVar8 = local_118;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar10 = *pbVar5 < *pbVar8;
      bVar11 = *pbVar5 == *pbVar8;
      pbVar5 = pbVar5 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar11);
    if (!bVar11) {
      uVar1 = -(uint)bVar10 | 1;
    }
    if (uVar1 == 0) {
      hash_pack_header._0_4_ = 0;
      hash_pack_header._4_4_ = 0;
      hash_pack_header._8_4_ = 0;
      strncpy(hash_pack_header,"HPAK",4);
      hash_pack_header._4_4_ = 1;
      hash_pack_header._8_4_ = 0;
      fwrite(hash_pack_header,0xc,1,__s);
      DAT_080aa8b0 = (undefined4 *)0x0;
      hash_pack_dir = 1;
      DAT_080aa8b0 = malloc(0x70);
      memset(DAT_080aa8b0,0,hash_pack_dir * 0x70);
      puVar7 = DAT_080aa8b0;
      puVar6 = param_2;
      puVar9 = DAT_080aa8b0;
      for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
      }
      lVar3 = ftell(__s);
      puVar7[0x1a] = lVar3;
      puVar7[0x1b] = param_2[0x12];
      if (param_3 == (void *)0x0) {
        COM_CopyFileChunk(__s,param_4,puVar7[0x1b]);
      }
      else {
        fwrite(param_3,puVar7[0x1b],1,__s);
      }
      lVar3 = ftell(__s);
      fwrite(&hash_pack_dir,4,1,__s);
      iVar4 = 0;
      if (0 < hash_pack_dir) {
        do {
          fwrite(DAT_080aa8b0 + iVar4 * 0x1c,0x70,1,__s);
          iVar4 = iVar4 + 1;
        } while (iVar4 < hash_pack_dir);
      }
      if (DAT_080aa8b0 != (undefined4 *)0x0) {
        free(DAT_080aa8b0);
      }
      DAT_080aa8b0 = (undefined4 *)0x0;
      hash_pack_dir = 0;
      hash_pack_header._8_4_ = lVar3;
      fseek(__s,0,0);
      fwrite(hash_pack_header,0xc,1,__s);
      fclose(__s);
    }
    else {
      Con_Printf("HPAK_CreatePak called with bogus lump, md5 mismatch\n");
      uVar2 = MD5_Print((int)param_2 + 0x4d);
      Con_Printf("Purported:  %s\n",uVar2);
      uVar2 = MD5_Print(local_118);
      Con_Printf("Actual   :  %s\n",uVar2);
      Con_Printf("Ignoring lump addition\n");
    }
  }
  return;
}


// HPAK_Extract_f  @ 08056d80
void HPAK_Extract_f(void)

{
  size_t __n;
  void *pvVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  FILE *__stream;
  void *__s;
  FILE *__s_00;
  undefined1 *puVar5;
  char *__s2;
  int local_350;
  int local_348;
  size_t local_344;
  void *local_340;
  char local_33c [260];
  char local_238 [292];
  char local_114 [260];
  char local_10 [4];
  int local_c;
  long local_8;
  
  local_350 = -1;
  if (cmd_source != 1) {
    return;
  }
  HPAK_FlushHostQueue();
  iVar2 = Cmd_Argc();
  if (iVar2 != 3) {
    Con_Printf();
    return;
  }
  __s2 = "all";
  pcVar3 = (char *)Cmd_Argv();
  iVar2 = strcasecmp(pcVar3,__s2);
  if (iVar2 != 0) {
    uVar4 = Cmd_Argv();
    local_350 = __strtol_internal(uVar4,0);
  }
  Cmd_Argv();
  sprintf(local_114,"%s/%s",com_gamedir);
  COM_DefaultExtension(local_114,&DAT_0809f84a);
  if (local_350 == -1) {
    Con_Printf();
  }
  else {
    Con_Printf("Extracting lump %i from %s\n");
  }
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return;
  }
  fread(local_10,0xc,1,__stream);
  iVar2 = strncmp(local_10,"HPAK",4);
  if (iVar2 == 0) {
    if (local_c != 1) {
      puVar5 = &stack0xfffffca0;
      Con_Printf();
      goto LAB_08056f47;
    }
    fseek(__stream,local_8,0);
    fread(&local_344,4,1,__stream);
    if (local_344 - 1 < 0x8000) {
      Con_Printf();
      Con_Printf("# Type Size FileName : MD5 Hash\n");
      local_340 = malloc(local_344 * 0x70);
      fread(local_340,0x70,local_344,__stream);
      for (local_348 = 0; pvVar1 = local_340, local_348 < (int)local_344; local_348 = local_348 + 1)
      {
        if ((local_350 == -1) || (local_350 == local_348)) {
          COM_FileBase();
          switch(*(undefined4 *)((int)pvVar1 + local_348 * 0x70 + 0x40)) {
          case 0:
            pcVar3 = "sound";
            break;
          case 1:
            pcVar3 = "skin";
            break;
          case 2:
            pcVar3 = "model";
            break;
          case 3:
            pcVar3 = "decal";
            break;
          case 4:
            pcVar3 = "generic";
            break;
          default:
            pcVar3 = "?";
          }
          sprintf(local_238,pcVar3);
          Con_Printf("Extracting %i: %10s %.2fK %s\n",local_348 + 1,local_238,
                     (double)((float)*(int *)((int)pvVar1 + local_348 * 0x70 + 0x48) * 0.0009765625)
                    );
          __n = *(size_t *)((int)pvVar1 + local_348 * 0x70 + 0x6c);
          if (__n - 1 < 0x1ffff) {
            __s = malloc(__n + 1);
            memset(__s,0,__n);
            fseek(__stream,*(long *)((int)pvVar1 + local_348 * 0x70 + 0x68),0);
            fread(__s,__n,1,__stream);
            sprintf(local_33c,"%s\\hpklmps\\lmp%04i.wad");
            COM_FixSlashes(local_33c);
            COM_CreatePath(local_33c);
            __s_00 = fopen(local_33c,"wb");
            if (__s_00 == (FILE *)0x0) {
              Con_Printf();
            }
            else {
              fwrite(__s,__n,1,__s_00);
              fclose(__s_00);
            }
            if (__s != (void *)0x0) {
              free(__s);
            }
          }
          else {
            Con_Printf();
          }
        }
      }
      fclose(__stream);
      free(local_340);
      return;
    }
  }
  puVar5 = &stack0xfffffc9c;
  Con_Printf();
LAB_08056f47:
  *(FILE **)(puVar5 + -4) = __stream;
  *(undefined4 *)(puVar5 + -8) = 0x8056f53;
  fclose(*(FILE **)(puVar5 + -4));
  return;
}


// HPAK_FindResource  @ 08055070
undefined4 HPAK_FindResource(int *param_1,char *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar3 = 0;
  if (0 < *param_1) {
    do {
      puVar1 = (undefined4 *)(iVar3 * 0x70 + param_1[1]);
      iVar2 = 0x10;
      bVar6 = true;
      pcVar4 = param_2;
      pcVar5 = (char *)((int)puVar1 + 0x4d);
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        if (param_3 != (undefined4 *)0x0) {
          for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
            *param_3 = *puVar1;
            puVar1 = puVar1 + 1;
            param_3 = param_3 + 1;
          }
        }
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *param_1);
  }
  return 0;
}


// HPAK_FlushHostQueue  @ 080551c0
void HPAK_FlushHostQueue(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *__ptr;
  
  if (gp_hpak_queue != (undefined4 *)0x0) {
    while (__ptr = gp_hpak_queue, gp_hpak_queue != (undefined4 *)0x0) {
      puVar1 = gp_hpak_queue + 0x1c;
      puVar2 = gp_hpak_queue + 1;
      uVar3 = *gp_hpak_queue;
      gp_hpak_queue = (undefined4 *)gp_hpak_queue[0x1d];
      HPAK_AddLump(0,uVar3,puVar2,*puVar1,0);
      free((void *)*__ptr);
      free((void *)__ptr[0x1c]);
      free(__ptr);
    }
  }
  return;
}


// HPAK_GetDataPointer  @ 08054cc0
undefined4 HPAK_GetDataPointer(char *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  FILE *__stream;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  bool bVar9;
  void *local_128;
  undefined4 local_120;
  size_t local_11c;
  void *local_118;
  char local_114 [260];
  char local_10 [4];
  int local_c;
  long local_8;
  
  local_128 = (void *)0x0;
  local_120 = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  puVar1 = gp_hpak_queue;
  if (gp_hpak_queue != (undefined4 *)0x0) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[0x1d]) {
      iVar2 = strcasecmp((char *)*puVar1,param_1);
      if (iVar2 == 0) {
        iVar2 = 0x10;
        bVar8 = true;
        pcVar6 = (char *)((int)puVar1 + 0x51);
        pcVar7 = (char *)(param_2 + 0x4d);
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          if (param_3 != (undefined4 *)0x0) {
            pvVar3 = malloc(puVar1[0x1b]);
            if (pvVar3 == (void *)0x0) {
              Sys_Error();
            }
            memcpy(pvVar3,(void *)puVar1[0x1c],puVar1[0x1b]);
            *param_3 = pvVar3;
          }
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = puVar1[0x1b];
          }
          return 1;
        }
      }
    }
  }
  sprintf(local_114,"%s/%s");
  COM_DefaultExtension(local_114,&DAT_0809f84a);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return 0;
  }
  fread(local_10,0xc,1,__stream);
  iVar2 = strncmp(local_10,"HPAK",4);
  if (iVar2 == 0) {
    if (local_c != 1) {
      puVar5 = &stack0xfffffec4;
      Con_Printf();
      goto LAB_08054ea7;
    }
    fseek(__stream,local_8,0);
    fread(&local_11c,4,1,__stream);
    if (local_11c - 1 < 0x8000) {
      local_118 = malloc(local_11c * 0x70);
      fread(local_118,0x70,local_11c,__stream);
      bVar8 = false;
      iVar2 = 0;
      if (0 < (int)local_11c) {
        do {
          local_128 = (void *)(iVar2 * 0x70 + (int)local_118);
          iVar4 = 0x10;
          bVar9 = true;
          pcVar6 = (char *)((int)local_128 + 0x4d);
          pcVar7 = (char *)(param_2 + 0x4d);
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pcVar6 == *pcVar7;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar9);
          if (bVar9) {
            fseek(__stream,*(long *)((int)local_128 + 0x68),0);
            bVar8 = true;
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)local_11c);
      }
      if ((((bVar8) && (local_120 = 1, param_3 != (undefined4 *)0x0)) && (local_128 != (void *)0x0))
         && (0 < *(int *)((int)local_128 + 0x6c))) {
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = *(undefined4 *)((int)local_128 + 0x6c);
        }
        pvVar3 = malloc(*(size_t *)((int)local_128 + 0x6c));
        if (pvVar3 == (void *)0x0) {
          Con_Printf();
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = 0;
          }
          local_120 = 0;
        }
        else {
          fread(pvVar3,*(size_t *)((int)local_128 + 0x6c),1,__stream);
          *param_3 = pvVar3;
        }
      }
      free(local_118);
      fclose(__stream);
      return local_120;
    }
  }
  puVar5 = &stack0xfffffec0;
  Con_Printf();
LAB_08054ea7:
  *(FILE **)(puVar5 + -4) = __stream;
  *(undefined4 *)(puVar5 + -8) = 0x8054eb3;
  fclose(*(FILE **)(puVar5 + -4));
  return 0;
}


// HPAK_Init  @ 080571e0
void HPAK_Init(void)

{
  Cmd_AddCommand("hpklist",HPAK_List_f);
  Cmd_AddCommand("hpkremove",HPAK_Remove_f);
  Cmd_AddCommand("hpkval",HPAK_Validate_f);
  Cmd_AddCommand("hpkextract",HPAK_Extract_f);
  gp_hpak_queue = 0;
  return;
}


// HPAK_List_f  @ 08056230
void HPAK_List_f(void)

{
  void *pvVar1;
  FILE *__stream;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *__format;
  size_t local_240;
  void *local_23c;
  char local_238 [32];
  undefined1 local_218 [260];
  char local_114 [260];
  char local_10 [4];
  int local_c;
  long local_8;
  
  if (cmd_source != 1) {
    return;
  }
  HPAK_FlushHostQueue();
  Cmd_Argv();
  sprintf(local_114,"%s/%s",com_gamedir);
  COM_DefaultExtension(local_114,&DAT_0809f84a);
  Con_Printf("Contents for %s.\n",local_114);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return;
  }
  fread(local_10,0xc,1,__stream);
  iVar2 = strncmp(local_10,"HPAK",4);
  if (iVar2 == 0) {
    if (local_c != 1) {
      puVar4 = &stack0xfffffdb0;
      Con_Printf();
      goto LAB_0805633b;
    }
    fseek(__stream,local_8,0);
    fread(&local_240,4,1,__stream);
    if (local_240 - 1 < 0x8000) {
      Con_Printf();
      Con_Printf("# Type Size FileName : MD5 Hash\n");
      local_23c = malloc(local_240 * 0x70);
      fread(local_23c,0x70,local_240,__stream);
      iVar2 = 0;
      if (0 < (int)local_240) {
        do {
          pvVar1 = local_23c;
          COM_FileBase();
          switch(*(undefined4 *)((int)pvVar1 + iVar2 * 0x70 + 0x40)) {
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
          default:
            __format = "?";
          }
          sprintf(local_238,__format);
          MD5_Print();
          iVar3 = iVar2 * 0x70;
          iVar2 = iVar2 + 1;
          Con_Printf("%i: %10s %.2fK %s\n  :  %s\n",iVar2,local_238,
                     (double)((float)*(int *)((int)pvVar1 + iVar3 + 0x48) * 0.0009765625),local_218)
          ;
        } while (iVar2 < (int)local_240);
      }
      fclose(__stream);
      free(local_23c);
      return;
    }
  }
  puVar4 = &stack0xfffffdac;
  Con_Printf();
LAB_0805633b:
  *(FILE **)(puVar4 + -4) = __stream;
  *(undefined4 *)(puVar4 + -8) = 0x8056341;
  fclose(*(FILE **)(puVar4 + -4));
  return;
}


// HPAK_RemoveLump  @ 08055950
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void HPAK_RemoveLump(char *param_1,int param_2)

{
  FILE *__stream;
  FILE *__stream_00;
  int iVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  bool bVar10;
  int local_334;
  int local_330;
  int local_320;
  void *local_31c;
  size_t local_318;
  void *local_314;
  char local_310 [260];
  char local_20c [260];
  char local_108 [260];
  
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) || (param_2 == 0)) {
    Con_Printf();
    return;
  }
  HPAK_FlushHostQueue();
  Cmd_Argv();
  sprintf(local_108,"%s/%s",com_gamedir);
  COM_DefaultExtension(local_108,&DAT_0809f84a);
  strcpy(local_310,local_108);
  __stream = fopen(local_310,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return;
  }
  COM_StripExtension();
  COM_DefaultExtension(local_20c,&DAT_0809faab);
  __stream_00 = fopen(local_20c,"w+b");
  if (__stream_00 == (FILE *)0x0) {
    fclose(__stream);
    Con_Printf("ERROR: couldn\'t create %s.\n");
    return;
  }
  fseek(__stream,0,0);
  fseek(__stream_00,0,0);
  fread(hash_pack_header,0xc,1,__stream);
  fwrite(hash_pack_header,0xc,1,__stream_00);
  iVar1 = strncmp(hash_pack_header,"HPAK",4);
  if (iVar1 == 0) {
    if (hash_pack_header._4_4_ != 1) {
      puVar5 = &stack0xfffffcb8;
      Con_Printf();
      goto LAB_08055c13;
    }
    fseek(__stream,hash_pack_header._8_4_,0);
    fread(&local_318,4,1,__stream);
    if (local_318 - 1 < 0x8000) {
      if (local_318 == 1) {
        Con_Printf();
        fclose(__stream_00);
        fclose(__stream);
        unlink(local_20c);
        unlink(local_310);
        return;
      }
      local_314 = malloc(local_318 * 0x70);
      fread(local_314,0x70,local_318,__stream);
      local_320 = local_318 - 1;
      local_31c = malloc(local_320 * 0x70);
      iVar1 = HPAK_FindResource(&local_318,param_2 + 0x4d,0);
      if (iVar1 != 0) {
        Con_Printf("Removing %s from HPAK %s.\n");
        local_330 = 0;
        local_334 = 0;
        if (0 < (int)local_318) {
          do {
            puVar2 = (undefined4 *)(local_334 * 0x70 + (int)local_314);
            iVar1 = 0x10;
            bVar10 = true;
            pcVar6 = (char *)((int)puVar2 + 0x4d);
            pcVar8 = (char *)(param_2 + 0x4d);
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar10 = *pcVar6 == *pcVar8;
              pcVar6 = pcVar6 + 1;
              pcVar8 = pcVar8 + 1;
            } while (bVar10);
            if (!bVar10) {
              puVar4 = (undefined4 *)(local_330 * 0x70 + (int)local_31c);
              local_330 = local_330 + 1;
              puVar7 = puVar2;
              puVar9 = puVar4;
              for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
                *puVar9 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar9 = puVar9 + 1;
              }
              lVar3 = ftell(__stream_00);
              puVar4[0x1a] = lVar3;
              fseek(__stream,puVar2[0x1a],0);
              COM_CopyFileChunk(__stream_00,__stream,puVar4[0x1b]);
            }
            local_334 = local_334 + 1;
          } while (local_334 < (int)local_318);
        }
        hash_pack_header._8_4_ = ftell(__stream_00);
        fwrite(&local_320,4,1,__stream_00);
        local_334 = 0;
        if (0 < local_320) {
          do {
            fwrite((void *)(local_334 * 0x70 + (int)local_31c),0x70,1,__stream_00);
            local_334 = local_334 + 1;
          } while (local_334 < local_320);
        }
        fseek(__stream_00,0,0);
        fwrite(hash_pack_header,0xc,1,__stream_00);
        fclose(__stream_00);
        fclose(__stream);
        unlink(local_310);
        rename(local_20c,local_310);
        free(local_31c);
        free(local_314);
        return;
      }
    }
  }
  puVar5 = &stack0xfffffcb4;
  Con_Printf();
LAB_08055c13:
  *(FILE **)(puVar5 + -4) = __stream_00;
  *(undefined4 *)(puVar5 + -8) = 0x8055c1f;
  fclose(*(FILE **)(puVar5 + -4));
  *(FILE **)(puVar5 + -8) = __stream;
  *(undefined4 *)(puVar5 + -0xc) = 0x8055c2b;
  fclose(*(FILE **)(puVar5 + -8));
  *(char **)(puVar5 + -0xc) = local_20c;
  *(undefined4 *)(puVar5 + -0x10) = 0x8055c37;
  unlink(*(char **)(puVar5 + -0xc));
  return;
}


// HPAK_Remove_f  @ 08056860
void HPAK_Remove_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_6c [104];
  
  if (cmd_source == 1) {
    HPAK_FlushHostQueue();
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      uVar2 = Cmd_Argv(2,local_6c);
      uVar2 = __strtol_internal(uVar2,0,10,0);
      uVar2 = Cmd_Argv(1,uVar2);
      iVar1 = HPAK_ResourceForIndex(uVar2);
      if (iVar1 == 0) {
        uVar2 = Cmd_Argv(1);
        uVar2 = Cmd_Argv(2,uVar2);
        uVar2 = __strtol_internal(uVar2,0,10,0);
        Con_Printf("Could not locate resource %i in %s\n",uVar2);
      }
      else {
        uVar2 = Cmd_Argv(1,local_6c);
        HPAK_RemoveLump(uVar2);
      }
    }
    else {
      Con_Printf("Usage:  hpkremove <hpk> <index>\n");
    }
  }
  return;
}


// HPAK_ResourceForHash  @ 08056050
undefined4 HPAK_ResourceForHash(char *param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  bool bVar7;
  size_t local_11c;
  void *local_118;
  char local_114 [260];
  char local_10 [4];
  int local_c;
  long local_8;
  
  puVar5 = gp_hpak_queue;
  if (gp_hpak_queue != (undefined4 *)0x0) {
    for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)puVar5[0x1d]) {
      iVar1 = strcasecmp((char *)*puVar5,param_1);
      if (iVar1 == 0) {
        iVar1 = 0x10;
        bVar7 = true;
        pcVar4 = (char *)((int)puVar5 + 0x51);
        pcVar6 = param_2;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          if (param_3 != (undefined4 *)0x0) {
            for (iVar1 = 0x1a; puVar5 = puVar5 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
              *param_3 = *puVar5;
              param_3 = param_3 + 1;
            }
          }
          return 1;
        }
      }
    }
  }
  sprintf(local_114,"%s/%s");
  COM_DefaultExtension(local_114,&DAT_0809f84a);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return 0;
  }
  fread(local_10,0xc,1,__stream);
  iVar1 = strncmp(local_10,"HPAK",4);
  if (iVar1 == 0) {
    if (local_c != 1) {
      puVar3 = &stack0xfffffed4;
      Con_Printf();
      goto LAB_08056211;
    }
    fseek(__stream,local_8,0);
    fread(&local_11c,4,1,__stream);
    if (local_11c - 1 < 0x8000) {
      local_118 = malloc(local_11c * 0x70);
      fread(local_118,0x70,local_11c,__stream);
      uVar2 = HPAK_FindResource(&local_11c,param_2,param_3);
      fclose(__stream);
      free(local_118);
      return uVar2;
    }
  }
  puVar3 = &stack0xfffffed0;
  Con_Printf();
LAB_08056211:
  *(FILE **)(puVar3 + -4) = __stream;
  *(undefined4 *)(puVar3 + -8) = 0x8056217;
  fclose(*(FILE **)(puVar3 + -4));
  return 0;
}


// HPAK_ResourceForIndex  @ 08055e70
undefined4 HPAK_ResourceForIndex(undefined4 param_1,int param_2,undefined4 *param_3)

{
  FILE *__stream;
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  size_t local_11c;
  void *local_118;
  char local_114 [260];
  char local_10 [4];
  int local_c;
  long local_8;
  
  if (cmd_source != 1) {
    return 0;
  }
  sprintf(local_114,"%s/%s");
  COM_DefaultExtension(local_114,&DAT_0809f84a);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return 0;
  }
  fread(local_10,0xc,1,__stream);
  iVar1 = strncmp(local_10,"HPAK",4);
  if (iVar1 == 0) {
    if (local_c != 1) {
      puVar2 = &stack0xfffffed0;
      Con_Printf();
      goto LAB_08055fc8;
    }
    fseek(__stream,local_8,0);
    fread(&local_11c,4,1,__stream);
    if (((local_11c - 1 < 0x8000) && (local_118 = malloc(local_11c * 0x70), 0 < param_2)) &&
       (param_2 <= (int)local_11c)) {
      fread(local_118,0x70,local_11c,__stream);
      puVar3 = (undefined4 *)((int)local_118 + param_2 * 0x70 + -0x70);
      for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_3 = *puVar3;
        puVar3 = puVar3 + 1;
        param_3 = param_3 + 1;
      }
      fclose(__stream);
      free(local_118);
      return 1;
    }
  }
  puVar2 = &stack0xfffffecc;
  Con_Printf();
LAB_08055fc8:
  *(FILE **)(puVar2 + -4) = __stream;
  *(undefined4 *)(puVar2 + -8) = 0x8055fd4;
  fclose(*(FILE **)(puVar2 + -4));
  return 0;
}


// HPAK_Validate_f  @ 08056930
void HPAK_Validate_f(void)

{
  size_t __n;
  void *pvVar1;
  int iVar2;
  FILE *__stream;
  void *__s;
  uint uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  char *__format;
  int local_2ac;
  size_t local_2a8;
  void *local_2a4;
  undefined4 local_2a0 [22];
  byte local_248 [16];
  char local_238 [292];
  char local_114 [260];
  char local_10 [4];
  int local_c;
  long local_8;
  
  if (cmd_source != 1) {
    return;
  }
  HPAK_FlushHostQueue();
  iVar2 = Cmd_Argc();
  if (iVar2 != 2) {
    Con_Printf();
    return;
  }
  Cmd_Argv();
  sprintf(local_114,"%s/%s",com_gamedir);
  COM_DefaultExtension(local_114,&DAT_0809f84a);
  Con_Printf("Validating %s.\n",local_114);
  __stream = fopen(local_114,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf();
    return;
  }
  fread(local_10,0xc,1,__stream);
  iVar2 = strncmp(local_10,"HPAK",4);
  if (iVar2 == 0) {
    if (local_c != 1) {
      puVar5 = &stack0xfffffd38;
      Con_Printf();
      goto LAB_08056a77;
    }
    fseek(__stream,local_8,0);
    fread(&local_2a8,4,1,__stream);
    if (local_2a8 - 1 < 0x8000) {
      Con_Printf();
      Con_Printf("# Type Size FileName : MD5 Hash\n");
      local_2a4 = malloc(local_2a8 * 0x70);
      fread(local_2a4,0x70,local_2a8,__stream);
      local_2ac = 0;
      do {
        pvVar1 = local_2a4;
        if ((int)local_2a8 <= local_2ac) {
          fclose(__stream);
          free(local_2a4);
          return;
        }
        COM_FileBase();
        switch(*(undefined4 *)((int)pvVar1 + local_2ac * 0x70 + 0x40)) {
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
        default:
          __format = "?";
        }
        sprintf(local_238,__format);
        Con_Printf("%i: %10s %.2fK %s:  ",local_2ac + 1,local_238,
                   (double)((float)*(int *)((int)pvVar1 + local_2ac * 0x70 + 0x48) * 0.0009765625));
        __n = *(size_t *)((int)pvVar1 + local_2ac * 0x70 + 0x6c);
        if (__n - 1 < 0x1ffff) {
          __s = malloc(__n + 1);
          memset(__s,0,__n);
          fseek(__stream,*(long *)((int)pvVar1 + local_2ac * 0x70 + 0x68),0);
          fread(__s,__n,1,__stream);
          puVar7 = local_2a0;
          for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          MD5Init();
          MD5Update(local_2a0,__s);
          MD5Final(local_248,local_2a0);
          iVar2 = 0x10;
          bVar9 = false;
          uVar3 = 0;
          bVar10 = true;
          pbVar6 = (byte *)((int)pvVar1 + local_2ac * 0x70 + 0x4d);
          pbVar8 = local_248;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar9 = *pbVar6 < *pbVar8;
            bVar10 = *pbVar6 == *pbVar8;
            pbVar6 = pbVar6 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar10);
          if (!bVar10) {
            uVar3 = -(uint)bVar9 | 1;
          }
          if (uVar3 != 0) {
            Con_Printf();
            Con_Printf();
            uVar4 = MD5_Print((int)pvVar1 + local_2ac * 0x70 + 0x4d);
            Con_Printf(" File  :  %s\n",uVar4);
            uVar4 = MD5_Print(local_248);
            Con_Printf(" Actual:  %s\n",uVar4);
          }
          Con_Printf();
          if (__s != (void *)0x0) {
            free(__s);
          }
        }
        else {
          Con_Printf();
        }
        local_2ac = local_2ac + 1;
      } while( true );
    }
  }
  puVar5 = &stack0xfffffd34;
  Con_Printf();
LAB_08056a77:
  *(FILE **)(puVar5 + -4) = __stream;
  *(undefined4 *)(puVar5 + -8) = 0x8056a83;
  fclose(*(FILE **)(puVar5 + -4));
  return;
}


