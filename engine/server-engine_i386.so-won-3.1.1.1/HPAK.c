// HPAK_AddLump  @ 000666a4
void HPAK_AddLump(int param_1,int param_2,undefined4 *param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 local_3ac [88];
  undefined1 local_354 [16];
  undefined4 *local_344;
  undefined4 *local_340;
  int local_33c;
  int local_338;
  int local_334;
  int local_330;
  int local_32c;
  undefined1 local_328 [255];
  undefined1 local_229;
  undefined1 local_224 [260];
  undefined4 local_120;
  char local_11c [260];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((param_2 == 0) || (param_3 == (undefined4 *)0x0)) || ((param_4 == 0 && (param_5 == 0)))) {
    if (param_2 == 0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no .pak filename\n");
    }
    else if (param_3 == (undefined4 *)0x0) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no lump to add\n");
    }
    else if ((param_4 == 0) && (param_5 == 0)) {
      Con_Printf("HPAK_AddLump called with invalid arguments:  no file handle\n");
    }
  }
  else if (((int)param_3[0x12] < 0x400) || (0x20000 < (int)param_3[0x12])) {
    Con_Printf("HPAK_AddLump called with bogus lump, size:  %i\n",param_3[0x12]);
  }
  else {
    Q_memset(local_3ac,0,0x58);
    MD5Init(local_3ac);
    if (param_4 == 0) {
      uVar3 = FS_Tell(param_5);
      uVar1 = Mem_Malloc(param_3[0x12] + 1);
      Q_memset(uVar1,0,param_3[0x12]);
      FS_Read(uVar1,param_3[0x12],1,param_5);
      FS_Seek(param_5,uVar3,0);
      MD5Update(local_3ac,uVar1,param_3[0x12]);
      Mem_Free(uVar1);
    }
    else {
      MD5Update(local_3ac,param_4,param_3[0x12]);
    }
    MD5Final(local_354,local_3ac);
    iVar2 = Q_memcmp((int)param_3 + 0x4d,local_354,0x10);
    if (iVar2 == 0) {
      if (param_1 == 0) {
        snprintf(local_11c,0x100,"%s",param_2);
        COM_DefaultExtension(local_11c,&DAT_000e1f87);
        COM_FixSlashes(local_11c);
        Q_strncpy(local_328,local_11c,0xff);
        local_229 = 0;
        local_10 = FS_Open(local_11c,&DAT_000e1f8c);
        if (local_10 == 0) {
          HPAK_CreatePak(param_2,param_3,param_4,param_5);
        }
        else {
          COM_StripExtension(local_11c,local_224);
          COM_DefaultExtension(local_224,&DAT_000e224b);
          local_14 = FS_Open(local_224,&DAT_000e2250);
          if (local_14 == 0) {
            FS_Close(local_10);
            Con_Printf("ERROR: couldn\'t open %s.\n",local_11c);
          }
          else {
            FS_Read(hash_pack_header,0xc,1,local_10);
            if (hash_pack_header._4_4_ == 1) {
              local_120 = FS_Size(local_10);
              COM_CopyFileChunk(local_14,local_10,local_120);
              FS_Seek(local_10,hash_pack_header._8_4_,0);
              FS_Read(&local_330,4,1,local_10);
              if ((local_330 < 0) || (0x8000 < local_330)) {
                Con_Printf("ERROR: .hpk had bogus # of directory entries:  %i\n",local_330);
                FS_Close(local_10);
                FS_Close(local_14);
                FS_Unlink(local_224);
              }
              else {
                local_32c = Mem_Malloc((local_330 + 1) * 0x90);
                FS_Read(local_32c,local_330 * 0x90,1,local_10);
                FS_Close(local_10);
                local_33c = HPAK_FindResource(&local_330,(int)param_3 + 0x4d,0);
                if (local_33c == 0) {
                  local_338 = local_330 + 1;
                  local_334 = Mem_Malloc(local_338 * 0x90);
                  Q_memset(local_334,0,local_338 * 0x90);
                  Q_memcpy(local_334,local_32c,local_330 * 0x90);
                  local_344 = (undefined4 *)0x0;
                  local_8 = 0;
                  while( true ) {
                    if (local_330 <= local_8) goto LAB_00066e04;
                    local_340 = (undefined4 *)(local_32c + local_8 * 0x90);
                    local_18 = Q_memcmp((int)param_3 + 0x4d,(int)local_340 + 0x4d,0x10);
                    if (local_18 < 0) break;
                    local_8 = local_8 + 1;
                  }
                  local_344 = (undefined4 *)(local_334 + local_8 * 0x90);
                  for (local_c = local_8; local_c < local_330; local_c = local_c + 1) {
                    puVar4 = (undefined4 *)(local_32c + local_c * 0x90);
                    puVar5 = (undefined4 *)(local_c * 0x90 + local_334 + 0x90);
                    for (iVar2 = 0x24; iVar2 != 0; iVar2 = iVar2 + -1) {
                      *puVar5 = *puVar4;
                      puVar4 = puVar4 + 1;
                      puVar5 = puVar5 + 1;
                    }
                  }
LAB_00066e04:
                  if (local_344 == (undefined4 *)0x0) {
                    local_344 = (undefined4 *)(local_334 + local_338 * 0x90 + -0x90);
                  }
                  local_340 = local_344;
                  Q_memset(local_344,0,0x90);
                  FS_Seek(local_14,hash_pack_header._8_4_,0);
                  puVar4 = param_3;
                  puVar5 = local_340;
                  for (iVar2 = 0x22; iVar2 != 0; iVar2 = iVar2 + -1) {
                    *puVar5 = *puVar4;
                    puVar4 = puVar4 + 1;
                    puVar5 = puVar5 + 1;
                  }
                  uVar3 = FS_Tell(local_14);
                  local_340[0x22] = uVar3;
                  local_340[0x23] = param_3[0x12];
                  if (param_4 == 0) {
                    COM_CopyFileChunk(local_14,param_5,local_340[0x23]);
                  }
                  else {
                    FS_Write(param_4,local_340[0x23],1,local_14);
                  }
                  hash_pack_header._8_4_ = FS_Tell(local_14);
                  FS_Write(&local_338,4,1,local_14);
                  for (local_8 = 0; local_8 < local_338; local_8 = local_8 + 1) {
                    FS_Write(local_8 * 0x90 + local_334,0x90,1,local_14);
                  }
                  if (local_334 != 0) {
                    Mem_Free(local_334);
                  }
                  if (local_32c != 0) {
                    Mem_Free(local_32c);
                  }
                  FS_Seek(local_14,0,0);
                  FS_Write(hash_pack_header,0xc,1,local_14);
                  FS_Close(local_14);
                  FS_Unlink(local_328);
                  FS_Rename(local_224,local_328);
                  return;
                }
                FS_Close(local_14);
                FS_Unlink(local_224);
                Mem_Free(local_32c);
              }
            }
            else {
              FS_Close(local_10);
              FS_Close(local_14);
              FS_Unlink(local_224);
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
      uVar3 = MD5_Print((int)param_3 + 0x4d);
      Con_Printf("Purported:  %s\n",uVar3);
      uVar3 = MD5_Print(local_354);
      Con_Printf("Actual   :  %s\n",uVar3);
      Con_Printf("Ignoring lump addition\n");
    }
  }
  return;
}


// HPAK_AddToQueue  @ 0006646c
void HPAK_AddToQueue(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  puVar1 = (undefined4 *)Mem_Malloc(0x98);
  if (puVar1 == (undefined4 *)0x0) {
    Sys_Error("Unable to allocate %i bytes for hpak queue!",0x98);
  }
  uVar6 = 0;
  Q_memset(puVar1,0,0x98);
  uVar2 = Mem_Strdup(param_1);
  *puVar1 = uVar2;
  puVar4 = param_2;
  puVar5 = puVar1;
  for (iVar3 = 0x22; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
  }
  puVar1[0x23] = param_2[0x12];
  uVar2 = Mem_Malloc(puVar1[0x23]);
  puVar1[0x24] = uVar2;
  if (puVar1[0x24] == 0) {
    uVar6 = puVar1[0x23];
    Sys_Error("Unable to allocate %i bytes for hpak queue!",uVar6);
  }
  if (param_3 == 0) {
    if (param_4 == 0) {
      Sys_Error("Add to Queue called without data or file pointer!",uVar6);
    }
    else {
      FS_Read(puVar1[0x24],puVar1[0x23],1,param_4);
    }
  }
  else {
    Q_memcpy(puVar1[0x24],param_3,puVar1[0x23]);
  }
  puVar1[0x25] = gp_hpak_queue;
  gp_hpak_queue = puVar1;
  return;
}


// HPAK_CheckIntegrity  @ 00069ed0
void HPAK_CheckIntegrity(undefined4 param_1)

{
  char local_108 [260];
  
  snprintf(local_108,0x100,"%s",param_1);
  COM_DefaultExtension(local_108,&DAT_000e1f87);
  COM_FixSlashes(local_108);
  HPAK_ValidatePak(local_108);
  return;
}


// HPAK_CheckSize  @ 000698e0
void HPAK_CheckSize(int param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float local_110;
  char local_108 [260];
  
  if (((byte)(0.0 < (float)hpk_maxsize._12_4_ |
              (byte)((ushort)((ushort)NAN((float)hpk_maxsize._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)hpk_maxsize._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) &&
     (param_1 != 0)) {
    if (0.0 <= (float)hpk_maxsize._12_4_) {
      snprintf(local_108,0x100,"%s");
      COM_DefaultExtension(local_108,&DAT_000e1f87);
      COM_FixSlashes(local_108);
      fVar1 = (float)hpk_maxsize._12_4_ * 1e+06;
      iVar2 = FS_Open(local_108,&DAT_000e1f8c);
      local_110 = 0.0;
      if (iVar2 != 0) {
        uVar3 = FS_Size(iVar2);
        local_110 = (float)uVar3;
        FS_Close(iVar2);
      }
      if (fVar1 <= local_110) {
        Con_Printf("Server: Size of %s > %f MB, deleting.\n",local_108,
                   (double)(float)hpk_maxsize._12_4_);
        Log_Printf("Server: Size of %s > %f MB, deleting.\n",local_108,
                   (double)(float)hpk_maxsize._12_4_);
        FS_RemoveFile(local_108,0);
      }
    }
    else {
      Con_Printf("hpk_maxsize < 0, setting to 0\n");
      Cvar_DirectSet(hpk_maxsize,&DAT_000e28ff);
    }
  }
  return;
}


// HPAK_CreatePak  @ 000681e4
void HPAK_CreatePak(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 local_180 [88];
  undefined1 local_128 [16];
  undefined4 *local_118;
  int local_114;
  undefined4 local_110;
  char local_10c [260];
  int local_8;
  
  if (((param_3 == 0) || (param_4 == 0)) && ((param_3 != 0 || (param_4 != 0)))) {
    snprintf(local_10c,0x100,"%s",param_1);
    COM_DefaultExtension(local_10c,&DAT_000e1f87);
    Con_Printf("Creating HPAK %s.\n",local_10c);
    local_114 = FS_Open(local_10c,&DAT_000e258a);
    if (local_114 == 0) {
      Con_Printf("ERROR: couldn\'t open new .hpk, check access rights to %s.\n",local_10c);
    }
    else {
      Q_memset(local_180,0,0x58);
      MD5Init(local_180);
      if (param_3 == 0) {
        uVar3 = FS_Tell(param_4);
        uVar1 = Mem_Malloc(param_2[0x12] + 1);
        Q_memset(uVar1,0,param_2[0x12]);
        FS_Read(uVar1,param_2[0x12],1,param_4);
        FS_Seek(param_4,uVar3,0);
        MD5Update(local_180,uVar1,param_2[0x12]);
        Mem_Free(uVar1);
      }
      else {
        MD5Update(local_180,param_3,param_2[0x12]);
      }
      MD5Final(local_128,local_180);
      iVar2 = Q_memcmp((int)param_2 + 0x4d,local_128,0x10);
      if (iVar2 == 0) {
        Q_memset(hash_pack_header,0,0xc);
        Q_strncpy(hash_pack_header,&DAT_000e1f8f,4);
        hash_pack_header._4_4_ = 1;
        hash_pack_header._8_4_ = 0;
        FS_Write(hash_pack_header,0xc,1,local_114);
        Q_memset(&hash_pack_dir,0,8);
        hash_pack_dir = 1;
        DAT_000f1758 = (undefined4 *)Mem_Malloc(0x90);
        Q_memset(DAT_000f1758,0,hash_pack_dir * 0x90);
        local_118 = DAT_000f1758;
        puVar4 = param_2;
        puVar5 = DAT_000f1758;
        for (iVar2 = 0x22; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        uVar3 = FS_Tell(local_114);
        local_118[0x22] = uVar3;
        local_118[0x23] = param_2[0x12];
        if (param_3 == 0) {
          COM_CopyFileChunk(local_114,param_4,local_118[0x23]);
        }
        else {
          FS_Write(param_3,local_118[0x23],1,local_114);
        }
        local_110 = FS_Tell(local_114);
        FS_Write(&hash_pack_dir,4,1,local_114);
        for (local_8 = 0; local_8 < hash_pack_dir; local_8 = local_8 + 1) {
          FS_Write(DAT_000f1758 + local_8 * 0x24,0x90,1,local_114);
        }
        if (DAT_000f1758 != (undefined4 *)0x0) {
          Mem_Free(DAT_000f1758);
        }
        DAT_000f1758 = (undefined4 *)0x0;
        hash_pack_dir = 0;
        hash_pack_header._8_4_ = local_110;
        FS_Seek(local_114,0,0);
        FS_Write(hash_pack_header,0xc,1,local_114);
        FS_Close(local_114);
      }
      else {
        Con_Printf("HPAK_CreatePak called with bogus lump, md5 mismatch\n");
        uVar3 = MD5_Print((int)param_2 + 0x4d);
        Con_Printf("Purported:  %s\n",uVar3);
        uVar3 = MD5_Print(local_128);
        Con_Printf("Actual   :  %s\n",uVar3);
        Con_Printf("Ignoring lump addition\n");
      }
    }
  }
  else {
    Con_Printf("HPAK_CreatePak, must specify one of pData or fpSource\n");
  }
  return;
}


// HPAK_Extract_f  @ 00068ed8
void HPAK_Extract_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  char *pcVar4;
  char local_374 [260];
  int local_270;
  int local_26c;
  int local_268;
  int local_250;
  int local_24c;
  char local_248 [32];
  undefined1 local_228 [260];
  char local_124 [260];
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_250 = -1;
  if (cmd_source == 1) {
    HPAK_FlushHostQueue();
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      puVar3 = &DAT_000e2791;
      uVar2 = Cmd_Argv(2);
      iVar1 = Q_stricmp(uVar2,puVar3);
      if (iVar1 != 0) {
        uVar2 = Cmd_Argv(2);
        local_250 = Q_atoi(uVar2);
      }
      uVar2 = Cmd_Argv(1);
      pcVar4 = "%s";
      snprintf(local_124,0x100,"%s",uVar2);
      COM_DefaultExtension(local_124,&DAT_000e1f87);
      if (local_250 == -1) {
        Con_Printf("Extracting all lumps from %s.\n",local_124);
      }
      else {
        pcVar4 = local_124;
        Con_Printf("Extracting lump %i from %s\n",local_250,pcVar4);
      }
      local_24c = FS_Open(local_124,&DAT_000e1f8c);
      if (local_24c == 0) {
        Con_Printf("ERROR: couldn\'t open %s.\n",local_124,pcVar4);
      }
      else {
        FS_Read(local_14,0xc,1,local_24c);
        iVar1 = Q_strncmp(local_14,&DAT_000e1f8f,4);
        if (iVar1 == 0) {
          if (local_10 == 1) {
            FS_Seek(local_24c,local_c,0);
            FS_Read(&local_1c,4,1,local_24c);
            if ((local_1c < 1) || (0x8000 < local_1c)) {
              Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_1c);
              FS_Close(local_24c);
            }
            else {
              Con_Printf("# of Entries:  %i\n",local_1c);
              Con_Printf("# Type Size FileName : MD5 Hash\n");
              local_18 = Mem_Malloc(local_1c * 0x90);
              FS_Read(local_18,local_1c * 0x90,1,local_24c);
              for (local_8 = 0; local_8 < local_1c; local_8 = local_8 + 1) {
                local_20 = local_18 + local_8 * 0x90;
                if ((local_250 == -1) || (local_250 == local_8)) {
                  COM_FileBase(local_20,local_228);
                  switch(*(undefined4 *)(local_20 + 0x40)) {
                  case 0:
                    sprintf(local_248,"sound");
                    break;
                  case 1:
                    sprintf(local_248,"skin");
                    break;
                  case 2:
                    sprintf(local_248,"model");
                    break;
                  case 3:
                    sprintf(local_248,"decal");
                    break;
                  case 4:
                    sprintf(local_248,"generic");
                    break;
                  case 5:
                    sprintf(local_248,"event");
                    break;
                  default:
                    sprintf(local_248,"?");
                  }
                  Con_Printf("Extracting %i: %10s %.2fK %s\n",local_8 + 1,local_248,
                             (double)((float)*(int *)(local_20 + 0x48) / 1024.0),local_228);
                  local_268 = 0;
                  local_26c = *(int *)(local_20 + 0x8c);
                  if ((local_26c < 1) || (0x1ffff < local_26c)) {
                    Con_Printf("Unable to extract data, size invalid:  %s\n",local_26c);
                  }
                  else {
                    local_268 = Mem_Malloc(local_26c + 1);
                    Q_memset(local_268,0,local_26c);
                    FS_Seek(local_24c,*(undefined4 *)(local_20 + 0x88),0);
                    FS_Read(local_268,local_26c,1,local_24c);
                    snprintf(local_374,0x104,"hpklmps\\lmp%04i.wad",local_8);
                    COM_FixSlashes(local_374);
                    COM_CreatePath(local_374);
                    local_270 = FS_Open(local_374,&DAT_000e258a);
                    if (local_270 == 0) {
                      Con_Printf("Error creating lump file %s\n",local_374);
                    }
                    else {
                      FS_Write(local_268,local_26c,1,local_270);
                      FS_Close(local_270);
                    }
                    if (local_268 != 0) {
                      Mem_Free(local_268);
                    }
                  }
                }
              }
              FS_Close(local_24c);
              Mem_Free(local_18);
            }
          }
          else {
            Con_Printf("hpkextract:  version mismatch\n");
            FS_Close(local_24c);
          }
        }
        else {
          Con_Printf("%s is not an HPAK file\n",local_124);
          FS_Close(local_24c);
        }
      }
    }
    else {
      Con_Printf("Usage:  hpkextract hpkname [all | single index]\n");
    }
  }
  return;
}


// HPAK_FindResource  @ 000663bc
undefined4 HPAK_FindResource(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int local_8;
  
  uVar3 = 0x663ca;
  local_8 = 0;
  while( true ) {
    if (*param_1 <= local_8) {
      return 0;
    }
    iVar1 = Q_memcmp(param_2,param_1[1] + local_8 * 0x90 + 0x4d,0x10,uVar3);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  if (param_3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)(local_8 * 0x90 + param_1[1]);
    for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_3 = *puVar2;
      puVar2 = puVar2 + 1;
      param_3 = param_3 + 1;
    }
  }
  return 1;
}


// HPAK_FlushHostQueue  @ 000665e0
void HPAK_FlushHostQueue(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (gp_hpak_queue != (undefined4 *)0x0) {
    while (puVar3 = gp_hpak_queue, gp_hpak_queue != (undefined4 *)0x0) {
      puVar1 = gp_hpak_queue + 0x24;
      puVar4 = gp_hpak_queue + 1;
      uVar2 = *gp_hpak_queue;
      gp_hpak_queue = (undefined4 *)gp_hpak_queue[0x25];
      HPAK_AddLump(0,uVar2,puVar4,*puVar1,0);
      Mem_Free(*puVar3);
      Mem_Free(puVar3[0x24]);
      Mem_Free(puVar3);
    }
  }
  return;
}


// HPAK_GetDataPointer  @ 00065ee0
undefined4 HPAK_GetDataPointer(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *local_134;
  int local_12c;
  char local_128 [260];
  int local_24;
  int local_20;
  int local_1c;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_24 = 0;
  local_8 = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (gp_hpak_queue != (undefined4 *)0x0) {
    for (local_134 = gp_hpak_queue; local_134 != (undefined4 *)0x0;
        local_134 = (undefined4 *)local_134[0x25]) {
      iVar2 = Q_stricmp(*local_134,param_1);
      if ((iVar2 == 0) && (iVar2 = Q_memcmp((int)local_134 + 0x51,param_2 + 0x4d,0x10), iVar2 == 0))
      {
        if (param_3 != (int *)0x0) {
          iVar2 = Mem_Malloc(local_134[0x23]);
          if (iVar2 == 0) {
            Sys_Error("Error allocating %i bytes for hpak!",local_134[0x23]);
          }
          Q_memcpy(iVar2,local_134[0x24],local_134[0x23]);
          *param_3 = iVar2;
        }
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = local_134[0x23];
        }
        return 1;
      }
    }
  }
  snprintf(local_128,0x100,"%s",param_1);
  COM_DefaultExtension(local_128,&DAT_000e1f87);
  local_c = FS_Open(local_128,&DAT_000e1f8c);
  if (local_c == 0) {
    local_8 = 0;
  }
  else {
    FS_Read(local_18,0xc,1,local_c);
    iVar2 = Q_strncmp(local_18,&DAT_000e1f8f,4);
    if (iVar2 == 0) {
      if (local_14 == 1) {
        FS_Seek(local_c,local_10,0);
        FS_Read(&local_20,4,1,local_c);
        if ((local_20 < 1) || (0x8000 < local_20)) {
          Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_20);
          FS_Close(local_c);
          local_8 = 0;
        }
        else {
          local_1c = Mem_ZeroMalloc(local_20 * 0x90);
          FS_Read(local_1c,local_20 * 0x90,1,local_c);
          bVar1 = false;
          for (local_12c = 0; local_12c < local_20; local_12c = local_12c + 1) {
            local_24 = local_1c + local_12c * 0x90;
            iVar2 = Q_memcmp(local_24 + 0x4d,param_2 + 0x4d,0x10);
            if (iVar2 == 0) {
              FS_Seek(local_c,*(undefined4 *)(local_24 + 0x88),0);
              bVar1 = true;
              break;
            }
          }
          if ((((bVar1) && (local_8 = 1, param_3 != (int *)0x0)) && (local_24 != 0)) &&
             (0 < *(int *)(local_24 + 0x8c))) {
            if (param_4 != (undefined4 *)0x0) {
              *param_4 = *(undefined4 *)(local_24 + 0x8c);
            }
            iVar2 = Mem_Malloc(*(undefined4 *)(local_24 + 0x8c));
            if (iVar2 == 0) {
              Con_Printf("Couln\'t allocate %i bytes for HPAK entry\n",
                         *(undefined4 *)(local_24 + 0x8c));
              if (param_4 != (undefined4 *)0x0) {
                *param_4 = 0;
              }
              local_8 = 0;
            }
            else {
              FS_Read(iVar2,*(undefined4 *)(local_24 + 0x8c),1,local_c);
              *param_3 = iVar2;
            }
          }
          Mem_Free(local_1c);
          FS_Close(local_c);
        }
      }
      else {
        Con_Printf("HPAK_List:  version mismatch\n");
        FS_Close(local_c);
        local_8 = 0;
      }
    }
    else {
      Con_Printf("%s is not an HPAK file\n",local_128);
      FS_Close(local_c);
      local_8 = 0;
    }
  }
  return local_8;
}


// HPAK_GetItem  @ 00069630
undefined1 * HPAK_GetItem(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 local_124 [260];
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  int local_8;
  
  HPAK_FlushHostQueue();
  snprintf(name_45,0x100,"%s","custom");
  COM_DefaultExtension(name_45,&DAT_000e1f87);
  iVar1 = FS_Open(name_45,&DAT_000e1f8c);
  if (iVar1 == 0) {
    puVar4 = &DAT_000e28bb;
  }
  else {
    FS_Read(local_14,0xc,1,iVar1);
    iVar2 = Q_strncmp(local_14,&DAT_000e1f8f,4);
    if (iVar2 == 0) {
      if (local_10 == 1) {
        FS_Seek(iVar1,local_c,0);
        FS_Read(&local_1c,4,1,iVar1);
        if ((local_1c < 1) || (0x8000 < local_1c)) {
          Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_1c);
          FS_Close(iVar1);
          puVar4 = &DAT_000e28bb;
        }
        else {
          local_18 = Mem_Malloc(local_1c * 0x90);
          FS_Read(local_18,local_1c * 0x90,1,iVar1);
          local_8 = local_1c + -1;
          if (param_1 < local_1c + -1) {
            local_8 = param_1;
          }
          local_20 = local_18 + local_8 * 0x90;
          COM_FileBase(local_20,local_124);
          uVar3 = MD5_Print(local_20 + 0x4d);
          snprintf(name_45,0x104,"!MD5%s",uVar3);
          FS_Close(iVar1);
          Mem_Free(local_18);
          puVar4 = name_45;
        }
      }
      else {
        Con_Printf("HPAK_List:  version mismatch\n");
        FS_Close(iVar1);
        puVar4 = &DAT_000e28bb;
      }
    }
    else {
      Con_Printf("%s is not an HPAK file\n",name_45);
      FS_Close(iVar1);
      puVar4 = &DAT_000e28bb;
    }
  }
  return puVar4;
}


// HPAK_Init  @ 00069594
void HPAK_Init(void)

{
  Cmd_AddCommand("hpklist",HPAK_List_f);
  Cmd_AddCommand("hpkremove",HPAK_Remove_f);
  Cmd_AddCommand("hpkval",HPAK_Validate_f);
  Cmd_AddCommand("hpkextract",HPAK_Extract_f);
  gp_hpak_queue = 0;
  return;
}


// HPAK_List_f  @ 00067d78
void HPAK_List_f(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char local_248 [32];
  undefined1 local_228 [260];
  char local_124 [260];
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (cmd_source == 1) {
    HPAK_FlushHostQueue();
    uVar1 = Cmd_Argv(1);
    snprintf(local_124,0x100,"%s",uVar1);
    COM_DefaultExtension(local_124,&DAT_000e1f87);
    Con_Printf("Contents for %s.\n",local_124);
    iVar2 = FS_Open(local_124,&DAT_000e1f8c);
    if (iVar2 == 0) {
      Con_Printf("ERROR: couldn\'t open %s.\n",local_124);
    }
    else {
      FS_Read(local_14,0xc,1,iVar2);
      iVar3 = Q_strncmp(local_14,&DAT_000e1f8f,4);
      if (iVar3 == 0) {
        if (local_10 == 1) {
          FS_Seek(iVar2,local_c,0);
          FS_Read(&local_1c,4,1,iVar2);
          if ((local_1c < 1) || (0x8000 < local_1c)) {
            Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_1c);
            FS_Close(iVar2);
          }
          else {
            Con_Printf("# of Entries:  %i\n",local_1c);
            Con_Printf("# Type Size FileName : MD5 Hash\n");
            local_18 = Mem_Malloc(local_1c * 0x90);
            FS_Read(local_18,local_1c * 0x90,1,iVar2);
            for (local_8 = 0; local_8 < local_1c; local_8 = local_8 + 1) {
              local_20 = local_18 + local_8 * 0x90;
              COM_FileBase(local_20,local_228);
              switch(*(undefined4 *)(local_20 + 0x40)) {
              case 0:
                sprintf(local_248,"sound");
                break;
              case 1:
                sprintf(local_248,"skin");
                break;
              case 2:
                sprintf(local_248,"model");
                break;
              case 3:
                sprintf(local_248,"decal");
                break;
              case 4:
                sprintf(local_248,"generic");
                break;
              case 5:
                sprintf(local_248,"event");
                break;
              default:
                sprintf(local_248,"?");
              }
              uVar1 = MD5_Print(local_20 + 0x4d);
              Con_Printf("%i: %10s %.2fK %s\n  :  %s\n",local_8 + 1,local_248,
                         (double)((float)*(int *)(local_20 + 0x48) / 1024.0),local_228,uVar1);
            }
            FS_Close(iVar2);
            Mem_Free(local_18);
          }
        }
        else {
          Con_Printf("HPAK_List:  version mismatch\n");
          FS_Close(iVar2);
        }
      }
      else {
        Con_Printf("%s is not an HPAK file\n",local_124);
        FS_Close(iVar2);
      }
    }
  }
  return;
}


// HPAK_RemoveLump  @ 00067024
void HPAK_RemoveLump(char *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_338;
  int local_334;
  int local_328;
  int local_324;
  int local_320;
  int local_31c;
  undefined1 local_318 [255];
  undefined1 local_219;
  undefined1 local_214 [260];
  int local_110;
  int local_10c;
  char local_108 [260];
  
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) || (param_2 == 0)) {
    Con_Printf("HPAK_RemoveLump:  Invalid arguments\n");
  }
  else {
    HPAK_FlushHostQueue();
    uVar1 = Cmd_Argv(1);
    snprintf(local_108,0x100,"%s",uVar1);
    COM_DefaultExtension(local_108,&DAT_000e1f87);
    Q_strncpy(local_318,local_108,0xff);
    local_219 = 0;
    local_10c = FS_Open(local_318,&DAT_000e1f8c);
    if (local_10c == 0) {
      Con_Printf("Error:  couldn\'t open HPAK file %s for removal.\n",local_108);
    }
    else {
      COM_StripExtension(local_108,local_214);
      COM_DefaultExtension(local_214,&DAT_000e224b);
      local_110 = FS_Open(local_214,&DAT_000e2250);
      if (local_110 == 0) {
        FS_Close(local_10c);
        Con_Printf("ERROR: couldn\'t create %s.\n",local_214);
      }
      else {
        FS_Seek(local_10c,0,0);
        FS_Seek(local_110,0,0);
        FS_Read(hash_pack_header,0xc,1,local_10c);
        FS_Write(hash_pack_header,0xc,1,local_110);
        iVar2 = Q_strncmp(hash_pack_header,&DAT_000e1f8f,4);
        if (iVar2 == 0) {
          if (hash_pack_header._4_4_ == 1) {
            FS_Seek(local_10c,hash_pack_header._8_4_,0);
            FS_Read(&local_320,4,1,local_10c);
            if ((local_320 < 1) || (0x8000 < local_320)) {
              Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_320);
              FS_Close(local_110);
              FS_Close(local_10c);
              FS_Unlink(local_214);
            }
            else if (local_320 == 1) {
              Con_Printf("Removing final lump from HPAK, deleting HPAK:\n  %s\n",local_318);
              FS_Close(local_110);
              FS_Close(local_10c);
              FS_Unlink(local_214);
              FS_Unlink(local_318);
            }
            else {
              local_31c = Mem_Malloc(local_320 * 0x90);
              FS_Read(local_31c,local_320 * 0x90,1,local_10c);
              local_328 = local_320 + -1;
              local_324 = Mem_Malloc(local_328 * 0x90);
              iVar2 = HPAK_FindResource(&local_320,param_2 + 0x4d,0);
              if (iVar2 == 0) {
                Con_Printf("ERROR: HPAK doesn\'t contain specified lump:  %s\n",param_2);
                FS_Close(local_110);
                FS_Close(local_10c);
                FS_Unlink(local_214);
              }
              else {
                Con_Printf("Removing %s from HPAK %s.\n",param_2,local_108);
                local_334 = 0;
                for (local_338 = 0; local_338 < local_320; local_338 = local_338 + 1) {
                  puVar4 = (undefined4 *)(local_31c + local_338 * 0x90);
                  iVar2 = Q_memcmp((int)puVar4 + 0x4d,param_2 + 0x4d,0x10);
                  if (iVar2 != 0) {
                    puVar3 = (undefined4 *)(local_324 + local_334 * 0x90);
                    local_334 = local_334 + 1;
                    puVar5 = puVar4;
                    puVar6 = puVar3;
                    for (iVar2 = 0x24; iVar2 != 0; iVar2 = iVar2 + -1) {
                      *puVar6 = *puVar5;
                      puVar5 = puVar5 + 1;
                      puVar6 = puVar6 + 1;
                    }
                    uVar1 = FS_Tell(local_110);
                    puVar3[0x22] = uVar1;
                    FS_Seek(local_10c,puVar4[0x22],0);
                    COM_CopyFileChunk(local_110,local_10c,puVar3[0x23]);
                  }
                }
                hash_pack_header._8_4_ = FS_Tell(local_110);
                FS_Write(&local_328,4,1,local_110);
                for (local_338 = 0; local_338 < local_328; local_338 = local_338 + 1) {
                  FS_Write(local_338 * 0x90 + local_324,0x90,1,local_110);
                }
                FS_Seek(local_110,0,0);
                FS_Write(hash_pack_header,0xc,1,local_110);
                FS_Close(local_110);
                FS_Close(local_10c);
                FS_Unlink(local_318);
                FS_Rename(local_214,local_318);
                Mem_Free(local_324);
                Mem_Free(local_31c);
              }
            }
          }
          else {
            Con_Printf("ERROR: HPAK version outdated\n");
            FS_Close(local_110);
            FS_Close(local_10c);
            FS_Unlink(local_214);
          }
        }
        else {
          Con_Printf("%s is not an HPAK file\n",local_108);
          FS_Close(local_110);
          FS_Close(local_10c);
          FS_Unlink(local_214);
        }
      }
    }
  }
  return;
}


// HPAK_Remove_f  @ 00068740
void HPAK_Remove_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 local_8c [136];
  
  if (cmd_source == 1) {
    HPAK_FlushHostQueue();
    iVar1 = Cmd_Argc();
    if (iVar1 == 3) {
      puVar4 = local_8c;
      uVar2 = Cmd_Argv(2);
      uVar2 = Q_atoi(uVar2);
      uVar3 = Cmd_Argv(1);
      iVar1 = HPAK_ResourceForIndex(uVar3,uVar2,puVar4);
      if (iVar1 == 0) {
        uVar2 = Cmd_Argv(1);
        uVar3 = Cmd_Argv(2);
        uVar3 = Q_atoi(uVar3);
        Con_Printf("Could not locate resource %i in %s\n",uVar3,uVar2);
      }
      else {
        puVar4 = local_8c;
        uVar2 = Cmd_Argv(1);
        HPAK_RemoveLump(uVar2,puVar4);
      }
    }
    else {
      Con_Printf("Usage:  hpkremove <hpk> <index>\n");
    }
  }
  return;
}


// HPAK_ResourceForHash  @ 00067a70
undefined4 HPAK_ResourceForHash(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *local_128;
  char local_120 [260];
  int local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (gp_hpak_queue != (undefined4 *)0x0) {
    for (local_128 = gp_hpak_queue; local_128 != (undefined4 *)0x0;
        local_128 = (undefined4 *)local_128[0x25]) {
      iVar1 = Q_stricmp(*local_128,param_1);
      if ((iVar1 == 0) && (iVar1 = Q_memcmp((int)local_128 + 0x51,param_2,0x10), iVar1 == 0)) {
        if (param_3 != (undefined4 *)0x0) {
          for (iVar1 = 0x22; local_128 = local_128 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
            *param_3 = *local_128;
            param_3 = param_3 + 1;
          }
        }
        return 1;
      }
    }
  }
  snprintf(local_120,0x100,"%s",param_1);
  COM_DefaultExtension(local_120,&DAT_000e1f87);
  iVar1 = FS_Open(local_120,&DAT_000e1f8c);
  if (iVar1 == 0) {
    Con_Printf("ERROR: couldn\'t open %s.\n",local_120);
    local_8 = 0;
  }
  else {
    FS_Read(local_14,0xc,1,iVar1);
    iVar2 = Q_strncmp(local_14,&DAT_000e1f8f,4);
    if (iVar2 == 0) {
      if (local_10 == 1) {
        FS_Seek(iVar1,local_c,0);
        FS_Read(&local_1c,4,1,iVar1);
        if ((local_1c < 1) || (0x8000 < local_1c)) {
          Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_1c);
          FS_Close(iVar1);
          local_8 = 0;
        }
        else {
          local_18 = Mem_Malloc(local_1c * 0x90);
          FS_Read(local_18,local_1c * 0x90,1,iVar1);
          local_8 = HPAK_FindResource(&local_1c,param_2,param_3);
          FS_Close(iVar1);
          Mem_Free(local_18);
        }
      }
      else {
        Con_Printf("HPAK_List:  version mismatch\n");
        FS_Close(iVar1);
        local_8 = 0;
      }
    }
    else {
      Con_Printf("%s is not an HPAK file\n",local_120);
      FS_Close(iVar1);
      local_8 = 0;
    }
  }
  return local_8;
}


// HPAK_ResourceForIndex  @ 000677b8
undefined4 HPAK_ResourceForIndex(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char local_120 [260];
  undefined4 *local_1c;
  int local_18;
  int local_14;
  undefined1 local_10 [4];
  int local_c;
  undefined4 local_8;
  
  if (cmd_source == 1) {
    snprintf(local_120,0x100,"%s",param_1);
    COM_DefaultExtension(local_120,&DAT_000e1f87);
    iVar2 = FS_Open(local_120,&DAT_000e1f8c);
    if (iVar2 == 0) {
      Con_Printf("ERROR: couldn\'t open %s.\n",local_120);
      uVar1 = 0;
    }
    else {
      FS_Read(local_10,0xc,1,iVar2);
      iVar3 = Q_strncmp(local_10,&DAT_000e1f8f,4);
      if (iVar3 == 0) {
        if (local_c == 1) {
          FS_Seek(iVar2,local_8,0);
          FS_Read(&local_18,4,1,iVar2);
          if ((local_18 < 1) || (0x8000 < local_18)) {
            Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_18);
            FS_Close(iVar2);
            uVar1 = 0;
          }
          else {
            local_14 = Mem_Malloc(local_18 * 0x90);
            if ((param_2 < 1) || (local_18 < param_2)) {
              Con_Printf("ERROR: HPAK bogus directory entry request:  %i\n",param_2);
              FS_Close(iVar2);
              uVar1 = 0;
            }
            else {
              FS_Read(local_14,local_18 * 0x90,1,iVar2);
              local_1c = (undefined4 *)(local_14 + param_2 * 0x90 + -0x90);
              puVar4 = local_1c;
              for (iVar3 = 0x22; iVar3 != 0; iVar3 = iVar3 + -1) {
                *param_3 = *puVar4;
                puVar4 = puVar4 + 1;
                param_3 = param_3 + 1;
              }
              FS_Close(iVar2);
              Mem_Free(local_14);
              uVar1 = 1;
            }
          }
        }
        else {
          Con_Printf("HPAK_List:  version mismatch\n");
          FS_Close(iVar2);
          uVar1 = 0;
        }
      }
      else {
        Con_Printf("%s is not an HPAK file\n",local_120);
        FS_Close(iVar2);
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// HPAK_ValidatePak  @ 00069ac8
void HPAK_ValidatePak(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined1 local_198 [88];
  undefined1 local_140 [16];
  int local_130;
  int local_12c;
  int local_128;
  undefined1 local_124 [260];
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  int local_8;
  
  HPAK_FlushHostQueue();
  local_128 = FS_Open(param_1,&DAT_000e1f8c);
  if (local_128 != 0) {
    FS_Read(local_14,0xc,1,local_128);
    if ((local_10 == 1) && (iVar1 = Q_strncmp(local_14,&DAT_000e1f8f,4), iVar1 == 0)) {
      FS_Seek(local_128,local_c,0);
      FS_Read(&local_1c,4,1,local_128);
      if ((local_1c < 1) || (0x8000 < local_1c)) {
        Con_Printf("ERROR: HPAK %s had bogus # of directory entries:  %i, deleting\n",param_1,
                   local_1c);
        FS_Close(local_128);
        FS_RemoveFile(param_1,0);
      }
      else {
        local_18 = Mem_Malloc(local_1c * 0x90);
        FS_Read(local_18,local_1c * 0x90,1,local_128);
        for (local_8 = 0; local_8 < local_1c; local_8 = local_8 + 1) {
          local_20 = local_18 + local_8 * 0x90;
          COM_FileBase(local_20,local_124);
          local_12c = 0;
          local_130 = *(int *)(local_20 + 0x8c);
          if ((local_130 < 1) || (0x1ffff < local_130)) {
            cVar2 = '\x02';
          }
          else {
            local_12c = Mem_Malloc(local_130 + 1);
            Q_memset(local_12c,0,local_130);
            FS_Seek(local_128,*(undefined4 *)(local_20 + 0x88),0);
            FS_Read(local_12c,local_130,1,local_128);
            Q_memset(local_198,0,0x58);
            MD5Init(local_198);
            MD5Update(local_198,local_12c,local_130);
            MD5Final(local_140,local_198);
            iVar1 = Q_memcmp(local_20 + 0x4d,local_140,0x10);
            cVar2 = iVar1 != 0;
            if ((bool)cVar2) {
              Con_Printf("Mismatched data in HPAK file %s, deleting\n",param_1);
            }
            if (local_12c != 0) {
              Mem_Free(local_12c);
            }
          }
          if (cVar2 != '\0') {
            Mem_Free(local_18);
            if (cVar2 == '\x02') {
              Con_Printf("Mismatched data in HPAK file %s, deleting\n",param_1);
              Con_Printf("Unable to MD5 hash data lump %i, size invalid:  %i\n",local_8 + 1,
                         local_130);
            }
            FS_Close(local_128);
            FS_RemoveFile(param_1,0);
            return;
          }
        }
        FS_Close(local_128);
        Mem_Free(local_18);
      }
    }
    else {
      Con_Printf("%s is not a PAK file, deleting\n",param_1);
      FS_Close(local_128);
      FS_RemoveFile(param_1,0);
    }
  }
  return;
}


// HPAK_Validate_f  @ 0006884c
void HPAK_Validate_f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_2cc [88];
  undefined1 local_274 [16];
  int local_264;
  int local_260;
  int local_24c;
  char local_248 [32];
  undefined1 local_228 [260];
  char local_124 [260];
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (cmd_source == 1) {
    HPAK_FlushHostQueue();
    iVar1 = Cmd_Argc();
    if (iVar1 == 2) {
      uVar2 = Cmd_Argv(1);
      snprintf(local_124,0x100,"%s",uVar2);
      COM_DefaultExtension(local_124,&DAT_000e1f87);
      Con_Printf("Validating %s.\n",local_124);
      local_24c = FS_Open(local_124,&DAT_000e1f8c);
      if (local_24c == 0) {
        Con_Printf("ERROR: couldn\'t open %s.\n",local_124);
      }
      else {
        FS_Read(local_14,0xc,1,local_24c);
        iVar1 = Q_strncmp(local_14,&DAT_000e1f8f,4);
        if (iVar1 == 0) {
          if (local_10 == 1) {
            FS_Seek(local_24c,local_c,0);
            FS_Read(&local_1c,4,1,local_24c);
            if ((local_1c < 1) || (0x8000 < local_1c)) {
              Con_Printf("ERROR: HPAK had bogus # of directory entries:  %i\n",local_1c);
              FS_Close(local_24c);
            }
            else {
              Con_Printf("# of Entries:  %i\n",local_1c);
              Con_Printf("# Type Size FileName : MD5 Hash\n");
              local_18 = Mem_Malloc(local_1c * 0x90);
              FS_Read(local_18,local_1c * 0x90,1,local_24c);
              for (local_8 = 0; local_8 < local_1c; local_8 = local_8 + 1) {
                local_20 = local_18 + local_8 * 0x90;
                COM_FileBase(local_20,local_228);
                switch(*(undefined4 *)(local_20 + 0x40)) {
                case 0:
                  sprintf(local_248,"sound");
                  break;
                case 1:
                  sprintf(local_248,"skin");
                  break;
                case 2:
                  sprintf(local_248,"model");
                  break;
                case 3:
                  sprintf(local_248,"decal");
                  break;
                case 4:
                  sprintf(local_248,"generic");
                  break;
                case 5:
                  sprintf(local_248,"event");
                  break;
                default:
                  sprintf(local_248,"?");
                }
                Con_Printf("%i: %10s %.2fK %s:  ",local_8 + 1,local_248,
                           (double)((float)*(int *)(local_20 + 0x48) / 1024.0),local_228);
                local_260 = 0;
                local_264 = *(int *)(local_20 + 0x8c);
                if ((local_264 < 1) || (0x1ffff < local_264)) {
                  Con_Printf("Unable to MD5 hash data, size invalid:  %i\n",local_264);
                }
                else {
                  local_260 = Mem_Malloc(local_264 + 1);
                  Q_memset(local_260,0,local_264);
                  FS_Seek(local_24c,*(undefined4 *)(local_20 + 0x88),0);
                  FS_Read(local_260,local_264,1,local_24c);
                  Q_memset(local_2cc,0,0x58);
                  MD5Init(local_2cc);
                  MD5Update(local_2cc,local_260,local_264);
                  MD5Final(local_274,local_2cc);
                  iVar1 = Q_memcmp(local_20 + 0x4d,local_274,0x10);
                  if (iVar1 == 0) {
                    Con_Printf(&DAT_000e271b);
                  }
                  else {
                    Con_Printf(" MISMATCHED\n");
                    Con_Printf("--------------------\n");
                    uVar2 = MD5_Print(local_20 + 0x4d);
                    Con_Printf(" File  :  %s\n",uVar2);
                    uVar2 = MD5_Print(local_274);
                    Con_Printf(" Actual:  %s\n",uVar2);
                    Con_Printf("--------------------\n");
                  }
                  if (local_260 != 0) {
                    Mem_Free(local_260);
                  }
                }
              }
              FS_Close(local_24c);
              Mem_Free(local_18);
            }
          }
          else {
            Con_Printf("hpkval:  version mismatch\n");
            FS_Close(local_24c);
          }
        }
        else {
          Con_Printf("%s is not an HPAK file\n",local_124);
          FS_Close(local_24c);
        }
      }
    }
    else {
      Con_Printf("Usage:  hpkval hpkname\n");
    }
  }
  return;
}


