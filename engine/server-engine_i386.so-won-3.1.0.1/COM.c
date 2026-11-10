// COM_AddGameDirectory  @ 0004d1b8
void COM_AddGameDirectory(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_210;
  char local_20c [260];
  char local_108 [260];
  
  sprintf(local_20c,"%s/%s",param_2,param_3);
  uVar1 = Info_Serverinfo("*gamedir",param_3,0x200);
  Info_SetValueForStarKey(uVar1);
  Q_strcpy(com_gamedir,local_20c);
  local_210 = 0;
  while( true ) {
    sprintf(local_108,"%s/pak%i.pak",local_20c,local_210);
    COM_FixSlashes(local_108);
    iVar3 = COM_LoadPackFile(local_108);
    if (iVar3 == 0) break;
    iVar2 = Mem_ZeroMalloc(0x218);
    Q_strcpy(iVar2 + 0x104,param_3);
    *(undefined4 *)(iVar2 + 0x210) = param_1;
    *(int *)(iVar2 + 0x208) = iVar3;
    *(int *)(iVar2 + 0x214) = com_searchpaths;
    com_searchpaths = iVar2;
    uVar1 = Sys_FileTime(local_108);
    *(undefined4 *)(iVar2 + 0x20c) = uVar1;
    local_210 = local_210 + 1;
  }
  iVar3 = Mem_ZeroMalloc(0x218);
  Q_strcpy(iVar3 + 0x104,param_3);
  *(undefined4 *)(iVar3 + 0x210) = param_1;
  Q_strcpy(iVar3,local_20c);
  *(int *)(iVar3 + 0x214) = com_searchpaths;
  com_searchpaths = iVar3;
  return;
}


// COM_BinPrintf  @ 000499f0
undefined1 * COM_BinPrintf(byte *param_1,uint param_2)

{
  uint uVar1;
  uint local_14;
  char local_10 [12];
  
  Q_memset(szReturn_68,0,0x80);
  local_14 = 0;
  if (0 < (int)param_2) {
    uVar1 = param_2 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          sprintf(local_10,"%02x",(uint)*param_1);
          Q_strcat(szReturn_68,local_10);
        }
        local_14 = (uint)(2 < uVar1);
        sprintf(local_10,"%02x",(uint)param_1[local_14]);
        Q_strcat(szReturn_68,local_10);
        local_14 = local_14 + 1;
      }
      sprintf(local_10,"%02x",(uint)param_1[local_14]);
      Q_strcat(szReturn_68,local_10);
      local_14 = local_14 + 1;
      if ((int)param_2 <= (int)local_14) {
        return szReturn_68;
      }
    }
    do {
      sprintf(local_10,"%02x",(uint)param_1[local_14]);
      Q_strcat(szReturn_68,local_10);
      sprintf(local_10,"%02x",(uint)param_1[local_14 + 1]);
      Q_strcat(szReturn_68,local_10);
      sprintf(local_10,"%02x",(uint)param_1[local_14 + 2]);
      Q_strcat(szReturn_68,local_10);
      sprintf(local_10,"%02x",(uint)param_1[local_14 + 3]);
      Q_strcat(szReturn_68,local_10);
      local_14 = local_14 + 4;
    } while ((int)local_14 < (int)param_2);
  }
  return szReturn_68;
}


// COM_BitOpsInit  @ 00049f94
void COM_BitOpsInit(void)

{
  Q_memset(&bfwrite,0,0xc);
  Q_memset(&bfread,0,0x18);
  return;
}


// COM_BlockSequenceCRCByte  @ 00091004
undefined1 COM_BlockSequenceCRCByte(undefined4 param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  undefined4 local_48;
  undefined1 local_44 [64];
  
  if ((int)param_3 < 0) {
    Sys_Error("sequence < 0, in COM_BlockSequenceCRCByte\n");
  }
  param_3 = param_3 % 0x3fc;
  if (0x3c < param_2) {
    param_2 = 0x3c;
  }
  Q_memcpy(local_44,param_1,param_2);
  local_44[param_2] = (&pulCRCTable)[param_3];
  local_44[param_2 + 1] = (&DAT_000ae4e1)[param_3];
  local_44[param_2 + 2] = (&DAT_000ae4e2)[param_3];
  local_44[param_2 + 3] = (&DAT_000ae4e3)[param_3];
  CRC32_Init(&local_48);
  CRC32_ProcessBuffer(&local_48,local_44,param_2 + 4);
  uVar1 = CRC32_Final(local_48);
  return uVar1;
}


// COM_ChangeGameDir  @ 0004d338
void COM_ChangeGameDir(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = com_searchpaths;
  while (iVar3 != 0) {
    iVar1 = *(int *)(iVar3 + 0x214);
    if (*(int *)(iVar3 + 0x210) == 0) {
      COM_FreeSearchPath(iVar3);
      iVar3 = iVar1;
    }
    else {
      *(int *)(iVar3 + 0x214) = iVar2;
      iVar2 = iVar3;
      iVar3 = iVar1;
    }
  }
  com_searchpaths = 0;
  while (iVar3 = iVar2, iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x214);
    *(int *)(iVar3 + 0x214) = com_searchpaths;
    com_searchpaths = iVar3;
  }
  COM_AddGameDirectory(0,host_parms,param_1);
  return;
}


// COM_CheckAuthenticationType  @ 0004da0c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void COM_CheckAuthenticationType(void)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  undefined1 local_80c [8];
  undefined1 local_804 [2048];
  
  if (((_DAT_003861d8 == (code *)0x0) || (_DAT_003861dc == (code *)0x0)) || (noip != 0)) {
    gfUseLANAuthentication = 1;
    return;
  }
  lVar2 = (longdouble)Sys_FloatTime();
  iVar1 = (*_DAT_003861d8)(local_804,local_80c);
  if (iVar1 != 2) {
    Con_Printf("Trying to authenticate with WON servers\n");
    iVar1 = (*_DAT_003861dc)();
    if (iVar1 == 0) {
      gfUseLANAuthentication = 1;
      return;
    }
    iVar1 = (*_DAT_003861d8)(local_804,local_80c);
    if (iVar1 != 2) {
      gfUseLANAuthentication = 1;
      return;
    }
    Con_Printf("WON Authentication successful\n");
  }
  gfUseLANAuthentication = 0;
  lVar3 = (longdouble)Sys_FloatTime();
  DAT_00384934 = (double)((float)DAT_00384934 + ((float)lVar3 - (float)lVar2));
  return;
}


// COM_CheckParm  @ 0004b86c
int COM_CheckParm(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (1 < com_argc) {
    do {
      iVar1 = *(int *)(com_argv + iVar2 * 4);
      if ((iVar1 != 0) && (iVar1 = Q_strcmp(param_1,iVar1), iVar1 == 0)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < com_argc);
  }
  return 0;
}


// COM_ClearCustomizationList  @ 0004de54
void COM_ClearCustomizationList(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int local_10;
  
  piVar2 = *(int **)(param_1 + 0xa0);
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[0x28];
    iVar4 = *piVar2;
    if (iVar4 != 0) {
      if (piVar2[0x27] != 0) {
        Mem_Free(piVar2[0x27]);
        iVar4 = *piVar2;
      }
      if ((iVar4 != 0) && (iVar4 = piVar2[0x26], iVar4 != 0)) {
        if (piVar2[0x11] == 3) {
          if ((param_2 != 0) && (cls == 5)) {
            R_DecalRemoveAll(~(uint)*(byte *)((int)piVar2 + 0x61));
            iVar4 = piVar2[0x26];
          }
          Mem_Free(*(undefined4 *)(iVar4 + 0x10));
          local_14 = *(int *)(iVar4 + 4);
          for (local_10 = 0; local_10 < *(int *)(iVar4 + 8); local_10 = local_10 + 1) {
            iVar3 = Cache_Check(local_14 + 0x40);
            if (iVar3 != 0) {
              Cache_Free(local_14 + 0x40);
            }
            local_14 = local_14 + 0x44;
          }
          Mem_Free(*(undefined4 *)(iVar4 + 4));
          iVar4 = piVar2[0x26];
        }
        Mem_Free(iVar4);
      }
    }
    Mem_Free(piVar2);
    piVar2 = piVar1;
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return;
}


// COM_CloseFile  @ 0004c84c
void COM_CloseFile(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = com_searchpaths;
  while( true ) {
    if (iVar1 == 0) {
      Sys_FileClose(param_3);
      return;
    }
    if ((*(int *)(iVar1 + 0x208) != 0) && (*(int *)(*(int *)(iVar1 + 0x208) + 0x104) == param_3))
    break;
    iVar1 = *(int *)(iVar1 + 0x214);
  }
  return;
}


// COM_CompareFileTime  @ 0004d944
undefined4 COM_CompareFileTime(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  FILE *local_8;
  
  uVar2 = 0;
  *param_3 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    COM_FOpenFile(param_1,&local_8);
    if (local_8 != (FILE *)0x0) {
      fclose(local_8);
      local_10 = ftLastFile;
      COM_FOpenFile(param_2,&local_8);
      if (local_8 != (FILE *)0x0) {
        fclose(local_8);
        local_c = ftLastFile;
        uVar1 = Sys_CompareFileTime(&local_10,&local_c);
        uVar2 = 1;
        *param_3 = uVar1;
      }
    }
  }
  return uVar2;
}


// COM_CopyFile  @ 0004c494
void COM_CopyFile(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_1008;
  undefined1 local_1004 [4096];
  
  uVar1 = Sys_FileOpenRead(param_1,&local_1008);
  COM_CreatePath(param_2);
  uVar2 = Sys_FileOpenWrite(param_2);
  if (uVar1 != 0) {
    do {
      uVar3 = 0x1000;
      if (uVar1 < 0x1000) {
        uVar3 = uVar1;
      }
      Sys_FileRead(local_1008,local_1004,uVar3);
      Sys_FileWrite(uVar2,local_1004,uVar3);
      uVar1 = uVar1 - uVar3;
    } while (uVar1 != 0);
  }
  Sys_FileClose(local_1008);
  Sys_FileClose(uVar2);
  return;
}


// COM_CopyFileChunk  @ 0004ca3c
void COM_CopyFileChunk(FILE *param_1,FILE *param_2,int param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 local_404 [1024];
  
  puVar4 = &stack0xfffffbec;
  if (0x400 < param_3) {
    uVar1 = 0x400U - param_3 & 0xfff;
    puVar2 = &stack0xfffffbec;
    if (uVar1 == 0) goto LAB_0004cb34;
    if (uVar1 < 0xc00) {
      if (uVar1 < 0x800) {
        puVar2 = &stack0xfffffbec;
        if (uVar1 < 0x400) goto LAB_0004cb34;
        fread(local_404,0x400,1,param_2);
        fwrite(local_404,0x400,1,param_1);
        param_3 = param_3 + -0x400;
      }
      fread(local_404,0x400,1,param_2);
      fwrite(local_404,0x400,1,param_1);
      param_3 = param_3 + -0x400;
    }
    fread(local_404,0x400,1,param_2);
    puVar3 = &stack0xfffffbcc;
    fwrite(local_404,0x400,1,param_1);
    for (param_3 = param_3 + -0x400; puVar4 = puVar3 + 0x20, puVar2 = puVar3 + 0x20, 0x400 < param_3
        ; param_3 = param_3 + -0x1000) {
LAB_0004cb34:
      *(FILE **)(puVar2 + -4) = param_2;
      *(undefined4 *)(puVar2 + -8) = 1;
      *(undefined4 *)(puVar2 + -0xc) = 0x400;
      *(undefined1 **)(puVar2 + -0x10) = local_404;
      *(undefined4 *)(puVar2 + -0x14) = 0x4cb45;
      fread(*(void **)(puVar2 + -0x10),*(size_t *)(puVar2 + -0xc),*(size_t *)(puVar2 + -8),
            *(FILE **)(puVar2 + -4));
      *(FILE **)(puVar2 + -0x14) = param_1;
      *(undefined4 *)(puVar2 + -0x18) = 1;
      *(undefined4 *)(puVar2 + -0x1c) = 0x400;
      *(undefined1 **)(puVar2 + -0x20) = local_404;
      *(undefined4 *)(puVar2 + -0x24) = 0x4cb56;
      fwrite(*(void **)(puVar2 + -0x20),*(size_t *)(puVar2 + -0x1c),*(size_t *)(puVar2 + -0x18),
             *(FILE **)(puVar2 + -0x14));
      *(FILE **)(puVar2 + -4) = param_2;
      *(undefined4 *)(puVar2 + -8) = 1;
      *(undefined4 *)(puVar2 + -0xc) = 0x400;
      *(undefined1 **)(puVar2 + -0x10) = local_404;
      *(undefined4 *)(puVar2 + -0x14) = 0x4cb6a;
      fread(*(void **)(puVar2 + -0x10),*(size_t *)(puVar2 + -0xc),*(size_t *)(puVar2 + -8),
            *(FILE **)(puVar2 + -4));
      *(FILE **)(puVar2 + -0x14) = param_1;
      *(undefined4 *)(puVar2 + -0x18) = 1;
      *(undefined4 *)(puVar2 + -0x1c) = 0x400;
      *(undefined1 **)(puVar2 + -0x20) = local_404;
      *(undefined4 *)(puVar2 + -0x24) = 0x4cb7b;
      fwrite(*(void **)(puVar2 + -0x20),*(size_t *)(puVar2 + -0x1c),*(size_t *)(puVar2 + -0x18),
             *(FILE **)(puVar2 + -0x14));
      *(FILE **)(puVar2 + -4) = param_2;
      *(undefined4 *)(puVar2 + -8) = 1;
      *(undefined4 *)(puVar2 + -0xc) = 0x400;
      *(undefined1 **)(puVar2 + -0x10) = local_404;
      *(undefined4 *)(puVar2 + -0x14) = 0x4cb8f;
      fread(*(void **)(puVar2 + -0x10),*(size_t *)(puVar2 + -0xc),*(size_t *)(puVar2 + -8),
            *(FILE **)(puVar2 + -4));
      *(FILE **)(puVar2 + -0x14) = param_1;
      *(undefined4 *)(puVar2 + -0x18) = 1;
      *(undefined4 *)(puVar2 + -0x1c) = 0x400;
      *(undefined1 **)(puVar2 + -0x20) = local_404;
      *(undefined4 *)(puVar2 + -0x24) = 0x4cba0;
      fwrite(*(void **)(puVar2 + -0x20),*(size_t *)(puVar2 + -0x1c),*(size_t *)(puVar2 + -0x18),
             *(FILE **)(puVar2 + -0x14));
      *(FILE **)(puVar2 + -4) = param_2;
      *(undefined4 *)(puVar2 + -8) = 1;
      *(undefined4 *)(puVar2 + -0xc) = 0x400;
      *(undefined1 **)(puVar2 + -0x10) = local_404;
      *(undefined4 *)(puVar2 + -0x14) = 0x4cbb4;
      fread(*(void **)(puVar2 + -0x10),*(size_t *)(puVar2 + -0xc),*(size_t *)(puVar2 + -8),
            *(FILE **)(puVar2 + -4));
      *(FILE **)(puVar2 + -0x14) = param_1;
      *(undefined4 *)(puVar2 + -0x18) = 1;
      *(undefined4 *)(puVar2 + -0x1c) = 0x400;
      puVar3 = puVar2 + -0x20;
      *(undefined1 **)(puVar2 + -0x20) = local_404;
      *(undefined4 *)(puVar2 + -0x24) = 0x4cbc5;
      fwrite(*(void **)(puVar2 + -0x20),*(size_t *)(puVar2 + -0x1c),*(size_t *)(puVar2 + -0x18),
             *(FILE **)(puVar2 + -0x14));
    }
  }
  *(FILE **)(puVar4 + -4) = param_2;
  *(undefined4 *)(puVar4 + -8) = 1;
  *(int *)(puVar4 + -0xc) = param_3;
  *(undefined1 **)(puVar4 + -0x10) = local_404;
  *(undefined4 *)(puVar4 + -0x14) = 0x4cbed;
  fread(*(void **)(puVar4 + -0x10),*(size_t *)(puVar4 + -0xc),*(size_t *)(puVar4 + -8),
        *(FILE **)(puVar4 + -4));
  *(FILE **)(puVar4 + -0x14) = param_1;
  *(undefined4 *)(puVar4 + -0x18) = 1;
  *(int *)(puVar4 + -0x1c) = param_3;
  *(undefined1 **)(puVar4 + -0x20) = local_404;
  *(undefined4 *)(puVar4 + -0x24) = 0x4cc00;
  fwrite(*(void **)(puVar4 + -0x20),*(size_t *)(puVar4 + -0x1c),*(size_t *)(puVar4 + -0x18),
         *(FILE **)(puVar4 + -0x14));
  *(FILE **)(puVar4 + -4) = param_2;
  *(undefined4 *)(puVar4 + -8) = 0x4cc0c;
  fflush(*(FILE **)(puVar4 + -4));
  *(FILE **)(puVar4 + -8) = param_1;
  *(undefined4 *)(puVar4 + -0xc) = 0x4cc15;
  fflush(*(FILE **)(puVar4 + -8));
  return;
}


// COM_CreateCustomization  @ 0004df98
uint COM_CreateCustomization
               (int param_1,undefined4 *param_2,undefined4 param_3,uint param_4,undefined4 *param_5,
               int *param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_8;
  
  local_8 = 0;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  puVar1 = (undefined4 *)Mem_ZeroMalloc(0xa4);
  puVar4 = param_2;
  puVar5 = puVar1;
  for (iVar3 = 0x22; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
  }
  if ((int)param_2[0x12] < 1) {
    local_8 = 1;
    goto LAB_0004e127;
  }
  *puVar1 = 1;
  if ((param_4 & 1) != 0) {
    iVar3 = HPAK_GetDataPointer("custom.hpk",param_2,puVar1 + 0x27,0);
    if (iVar3 != 0) goto LAB_0004e049;
    goto LAB_0004e022;
  }
  uVar2 = COM_LoadFile(param_2,5,0);
  puVar1[0x27] = uVar2;
LAB_0004e049:
  if (((*(byte *)(puVar1 + 0x14) & 4) == 0) || (puVar1[0x11] != 3)) {
LAB_0004e127:
    if (local_8 == 0) {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = puVar1;
      }
      puVar1[0x28] = *(undefined4 *)(param_1 + 0xa0);
      *(undefined4 **)(param_1 + 0xa0) = puVar1;
      goto LAB_0004e18d;
    }
  }
  else {
    *(undefined1 *)((int)puVar1 + 0x61) = (undefined1)param_3;
    if ((param_4 & 4) != 0) goto LAB_0004e127;
    iVar3 = Mem_ZeroMalloc(0x2c);
    puVar1[0x26] = iVar3;
    if (param_2[0x12] - 0x400 < 0x3c01) {
      CustomDecal_Init(iVar3,puVar1[0x27],param_2[0x12],param_3);
      if (0 < *(int *)(iVar3 + 0x14)) {
        if (param_6 != (int *)0x0) {
          *param_6 = *(int *)(iVar3 + 0x14);
        }
        puVar1[0x23] = 1;
        puVar1[0x24] = 0;
        puVar1[0x25] = *(undefined4 *)(iVar3 + 0x14);
        if ((param_4 & 2) != 0) {
          Mem_Free(*(undefined4 *)(iVar3 + 4));
          Mem_Free(*(undefined4 *)(iVar3 + 0x10));
          Mem_Free(puVar1[0x26]);
          puVar1[0x26] = 0;
        }
        goto LAB_0004e127;
      }
    }
LAB_0004e022:
    local_8 = 1;
  }
  if (puVar1[0x27] != 0) {
    Mem_Free(puVar1[0x27]);
  }
  if (puVar1[0x26] != 0) {
    Mem_Free(puVar1[0x26]);
  }
  Mem_Free(puVar1);
LAB_0004e18d:
  local_8 = local_8 ^ 1;
  return local_8;
}


// COM_CreatePath  @ 0004c440
void COM_CreatePath(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 1);
  cVar1 = *(char *)(param_1 + 1);
  while (cVar1 != '\0') {
    cVar1 = *pcVar2;
    if ((cVar1 == '/') || (cVar1 == '\\')) {
      *pcVar2 = '\0';
      Sys_mkdir(param_1);
      *pcVar2 = cVar1;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  return;
}


// COM_DefaultExtension  @ 0004b6c4
void COM_DefaultExtension(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = Q_strlen(param_1);
  pcVar3 = param_1 + iVar2 + -1;
  cVar1 = param_1[iVar2 + -1];
  while ((cVar1 != '/' && (pcVar3 != param_1))) {
    if (*pcVar3 == '.') {
      return;
    }
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
  }
  Q_strcat(param_1,param_2);
  return;
}


// COM_DestroyMultipleFileList  @ 0004c5ec
void COM_DestroyMultipleFileList(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10c);
      if (*(int *)(iVar2 + 4) != 0) {
        Mem_Free(*(int *)(iVar2 + 4));
      }
      Mem_Free(iVar2);
      iVar2 = iVar1;
    }
    *param_1 = 0;
  }
  return;
}


// COM_EntsForPlayerSlots  @ 0004db04
int COM_EntsForPlayerSlots(int param_1)

{
  return (param_1 + -1) * 0xf + 800;
}


// COM_ExpandFilename  @ 0004c550
undefined4 COM_ExpandFilename(char *param_1)

{
  int iVar1;
  int iVar2;
  char local_108 [260];
  
  iVar1 = com_searchpaths;
  do {
    if (iVar1 == 0) {
      if ((param_1 != (char *)0x0) && (*param_1 != '*')) {
        Sys_Printf("COM_ExpandFilename: can\'t find %s\n",param_1);
      }
      return 0;
    }
    iVar2 = Q_strlen(iVar1);
    if (0 < iVar2) {
      sprintf(local_108,"%s/%s",iVar1,param_1);
      iVar2 = Sys_FileTime(local_108);
      if (0 < iVar2) {
        Q_strcpy(param_1,local_108);
        return 1;
      }
    }
    iVar1 = *(int *)(iVar1 + 0x214);
  } while( true );
}


// COM_ExplainDisconnection  @ 00049b98
void COM_ExplainDisconnection(int param_1,char *param_2)

{
  vsprintf(string_71,param_2,&stack0x0000000c);
  Q_strncpy(gszDisconnectReason,string_71,0xff);
  gszDisconnectReason[0xff] = 0;
  gfExtendedError = 1;
  if (param_1 != 0) {
    Con_Printf(&DAT_000a44fd,gszDisconnectReason);
  }
  return;
}


// COM_FOpenFile  @ 0004c7d4
void COM_FOpenFile(undefined4 param_1,undefined4 param_2)

{
  COM_FindFileSearch(0,0,param_1,0,param_2);
  return;
}


// COM_FileBase  @ 0004b600
void COM_FileBase(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = Q_strlen(param_1);
  iVar2 = iVar2 + -1;
  iVar3 = iVar2;
  if (iVar2 == 0) {
LAB_0004b652:
    iVar4 = iVar2;
    if (*(char *)(iVar3 + param_1) == '.') goto LAB_0004b660;
  }
  else {
    cVar1 = *(char *)(iVar2 + param_1);
    while (cVar1 != '.') {
      if (((cVar1 == '/') || (cVar1 == '\\')) || (iVar3 = iVar3 + -1, iVar3 == 0))
      goto LAB_0004b652;
      cVar1 = *(char *)(iVar3 + param_1);
    }
LAB_0004b660:
    iVar4 = iVar3 + -1;
  }
  if (-1 < iVar2) {
    cVar1 = *(char *)(iVar2 + param_1);
    while ((cVar1 != '/' && (cVar1 != '\\'))) {
      iVar2 = iVar2 + -1;
      if (iVar2 < 0) goto LAB_0004b695;
      cVar1 = *(char *)(iVar2 + param_1);
    }
    if ((-1 < iVar2) && ((cVar1 == '/' || (cVar1 == '\\')))) {
      iVar2 = iVar2 + 1;
      goto LAB_0004b69d;
    }
  }
LAB_0004b695:
  iVar2 = 0;
LAB_0004b69d:
  iVar3 = (iVar4 - iVar2) + 1;
  Q_strncpy(param_2,param_1 + iVar2,iVar3);
  *(undefined1 *)(iVar3 + param_2) = 0;
  return;
}


// COM_FileExtension  @ 0004b530
undefined * COM_FileExtension(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = *param_1;
  if (cVar2 != '\0') {
    do {
      if (cVar2 == '.') break;
      param_1 = param_1 + 1;
      cVar2 = *param_1;
    } while (cVar2 != '\0');
    if (cVar2 != '\0') {
      iVar3 = 0;
      cVar2 = param_1[1];
      if (cVar2 != '\0') {
        iVar3 = 1;
        cVar1 = param_1[2];
        exten_209 = cVar2;
        if (cVar1 != '\0') {
          iVar3 = 2;
          cVar2 = param_1[3];
          DAT_000c22c1 = cVar1;
          if (cVar2 != '\0') {
            iVar3 = 3;
            cVar1 = param_1[4];
            DAT_000c22c2 = cVar2;
            if (cVar1 != '\0') {
              iVar3 = 4;
              cVar2 = param_1[5];
              DAT_000c22c3 = cVar1;
              if (cVar2 != '\0') {
                iVar3 = 5;
                cVar1 = param_1[6];
                DAT_000c22c4 = cVar2;
                if (cVar1 != '\0') {
                  iVar3 = 6;
                  DAT_000c22c5 = cVar1;
                  if (param_1[7] != '\0') {
                    iVar3 = 7;
                    DAT_000c22c6 = param_1[7];
                  }
                }
              }
            }
          }
        }
      }
      (&exten_209)[iVar3] = 0;
      return &exten_209;
    }
  }
  return &DAT_000a4500;
}


// COM_FileSeek  @ 0004d638
void COM_FileSeek(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  Sys_FileSeek(param_3,param_1 + param_4);
  return;
}


// COM_FileSize  @ 0004c800
undefined4 COM_FileSize(undefined4 param_1)

{
  undefined4 uVar1;
  FILE *local_8;
  
  local_8 = (FILE *)0x0;
  uVar1 = COM_FindFileSearch(0,0,param_1,0,&local_8);
  if (local_8 != (FILE *)0x0) {
    fclose(local_8);
  }
  return uVar1;
}


// COM_FileTell  @ 0004d660
int COM_FileTell(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = Sys_FileTell(param_3);
  return iVar1 - param_1;
}


// COM_FindFile  @ 0004c2d8
void COM_FindFile(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  COM_FindFileSearch(0,0,param_1,param_2,param_3);
  return;
}


// COM_FindFileSearch  @ 0004be14
undefined4
COM_FindFileSearch(int *param_1,int param_2,char *param_3,undefined4 *param_4,undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  FILE *pFVar7;
  char *pcVar8;
  int local_120;
  int local_110;
  int local_10c;
  char local_108 [260];
  
  local_10c = -1;
  bVar4 = false;
  if (param_5 == (undefined4 *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      pcVar5 = "COM_FindFile: neither phFile or file set";
      goto LAB_0004be60;
    }
  }
  else if (param_4 != (undefined4 *)0x0) {
    pcVar5 = "COM_FindFile: both phFile and file set";
LAB_0004be60:
    Sys_Error(pcVar5);
  }
  local_110 = com_searchpaths;
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
LAB_0004bf50:
    if (param_2 == 0) {
joined_r0x0004bfac:
      while ((local_110 != 0 &&
             ((!bVar4 || (iVar6 = Q_stricmp(param_2,local_110 + 0x104), iVar6 == 0))))) {
        iVar6 = Q_strlen(local_110);
        if (0 < iVar6) {
          sprintf(local_108,"%s/%s",local_110,param_3);
          ftLastFile = Sys_FileTime(local_108);
          if (0 < ftLastFile) {
            com_filesize = Sys_FileOpenRead(local_108,&local_10c);
            if (param_4 == (undefined4 *)0x0) {
              Sys_FileClose(local_10c);
              pFVar7 = fopen(local_108,"rb");
              *param_5 = pFVar7;
            }
            else {
              param_4[2] = local_10c;
              *param_4 = 0;
            }
            if (param_1 == (int *)0x0) {
              return com_filesize;
            }
            *param_1 = local_110;
            return com_filesize;
          }
        }
        pcVar5 = *(char **)(local_110 + 0x208);
        if (pcVar5 != (char *)0x0) {
          cVar1 = *param_3;
          pcVar8 = param_3;
          if ((cVar1 != '\0') && ((cVar1 == '\\' || (cVar1 == '/')))) {
            pcVar8 = param_3 + 1;
          }
          local_10c = 0;
          local_120 = 0;
          if (0 < *(int *)(pcVar5 + 0x108)) {
            do {
              iVar6 = Q_FileNameCmp(local_120 * 0x40 + *(int *)(pcVar5 + 0x10c),pcVar8);
              if (iVar6 == 0) {
                Sys_Printf("PackFile: %s : %s\n",pcVar5,pcVar8);
                if (param_4 == (undefined4 *)0x0) {
                  ftLastFile = *(int *)(local_110 + 0x20c);
                  pFVar7 = fopen(pcVar5,"rb");
                  *param_5 = pFVar7;
                  setvbuf(pFVar7,(char *)0x0,0,0x4000);
                  if ((FILE *)*param_5 != (FILE *)0x0) {
                    fseek((FILE *)*param_5,
                          *(long *)(*(int *)(pcVar5 + 0x10c) + 0x38 + local_10c * 0x40),0);
                  }
                }
                else {
                  uVar2 = *(undefined4 *)(pcVar5 + 0x104);
                  param_4[2] = uVar2;
                  uVar3 = *(undefined4 *)(*(int *)(pcVar5 + 0x10c) + 0x38 + local_10c * 0x40);
                  *param_4 = uVar3;
                  param_4[1] = *(undefined4 *)(*(int *)(pcVar5 + 0x10c) + 0x3c + local_10c * 0x40);
                  Sys_FileSeek(uVar2,uVar3);
                }
                com_filesize = *(undefined4 *)(*(int *)(pcVar5 + 0x10c) + 0x3c + local_10c * 0x40);
                if (param_1 == (int *)0x0) {
                  return com_filesize;
                }
                *param_1 = local_110;
                return com_filesize;
              }
              iVar6 = local_10c + 1;
              local_120 = local_10c + 1;
              local_10c = iVar6;
            } while (local_120 < *(int *)(pcVar5 + 0x108));
          }
        }
        local_110 = *(int *)(local_110 + 0x214);
      }
    }
    else {
      bVar4 = true;
      if (local_110 != 0) {
        do {
          iVar6 = Q_stricmp(param_2,local_110 + 0x104);
          if (iVar6 == 0) break;
          local_110 = *(int *)(local_110 + 0x214);
        } while (local_110 != 0);
        goto joined_r0x0004bfac;
      }
    }
    if (((param_3 != (char *)0x0) && (*param_3 != '*')) &&
       ((byte)((float)com_filewarning._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)com_filewarning._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)com_filewarning._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
       ) {
      Con_DPrintf("FindFile: can\'t find %s\n",param_3);
    }
joined_r0x0004c29f:
    if (param_4 == (undefined4 *)0x0) {
      *param_5 = 0;
    }
    else {
      param_4[2] = 0xffffffff;
    }
  }
  else {
    if (com_searchpaths != 0) {
      do {
        if (local_110 == *param_1) break;
        local_110 = *(int *)(local_110 + 0x214);
      } while (local_110 != 0);
      if (local_110 != 0) {
        local_110 = *(int *)(local_110 + 0x214);
        if (local_110 != 0) {
          do {
            iVar6 = Q_stricmp(local_110 + 0x104,*param_1 + 0x104);
            if (iVar6 != 0) break;
            local_110 = *(int *)(local_110 + 0x214);
          } while (local_110 != 0);
          if (local_110 != 0) goto LAB_0004bf50;
        }
        goto joined_r0x0004c29f;
      }
    }
    if (param_4 == (undefined4 *)0x0) {
      *param_5 = 0;
    }
    else {
      param_4[2] = 0xffffffff;
    }
  }
  com_filesize = 0xffffffff;
  return 0xffffffff;
}


// COM_FixSlashes  @ 0004c424
void COM_FixSlashes(char *param_1)

{
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if (*param_1 == '\\') {
      *param_1 = '/';
    }
  }
  return;
}


// COM_FreeFile  @ 0004ca18
void COM_FreeFile(int param_1)

{
  if (param_1 != 0) {
    Mem_Free(param_1);
  }
  return;
}


// COM_FreeSearchPath  @ 0004d104
void COM_FreeSearchPath(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x208) != 0) {
      Sys_FileClose(*(undefined4 *)(*(int *)(param_1 + 0x208) + 0x104));
      iVar1 = *(int *)(param_1 + 0x208);
      if (*(int *)(iVar1 + 0x10c) != 0) {
        Mem_Free(*(int *)(iVar1 + 0x10c));
        iVar1 = *(int *)(param_1 + 0x208);
      }
      Mem_Free(iVar1);
    }
    Mem_Free(param_1);
  }
  return;
}


// COM_GetGameDir  @ 0004d9e0
void COM_GetGameDir(int param_1)

{
  if (param_1 != 0) {
    Q_strcpy(param_1,com_gamedir);
  }
  return;
}


// COM_HexConvert  @ 0004983c
void COM_HexConvert(char *param_1,uint param_2,byte *param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  byte *local_8;
  
  local_8 = param_3;
  iVar4 = 0;
  if (0 < (int)param_2) {
    pcVar5 = param_1 + 1;
    uVar3 = param_2 & 7;
    if (uVar3 == 0) goto LAB_00049928;
    if (2 < uVar3) {
      if (4 < uVar3) {
        if (6 < uVar3) goto LAB_00049928;
        cVar1 = COM_Nibble((int)*param_1);
        bVar2 = COM_Nibble((int)param_1[1]);
        iVar4 = 2;
        *param_3 = bVar2 | cVar1 << 4;
        local_8 = param_3 + 1;
        pcVar5 = param_1 + 3;
      }
      cVar1 = COM_Nibble((int)param_1[iVar4]);
      bVar2 = COM_Nibble((int)*pcVar5);
      pcVar5 = pcVar5 + 2;
      iVar4 = iVar4 + 2;
      *local_8 = bVar2 | cVar1 << 4;
      local_8 = local_8 + 1;
    }
    cVar1 = COM_Nibble((int)param_1[iVar4]);
    bVar2 = COM_Nibble((int)*pcVar5);
    pcVar5 = pcVar5 + 2;
    *local_8 = bVar2 | cVar1 << 4;
    local_8 = local_8 + 1;
    for (iVar4 = iVar4 + 2; iVar4 < (int)param_2; iVar4 = iVar4 + 8) {
LAB_00049928:
      cVar1 = COM_Nibble((int)param_1[iVar4]);
      bVar2 = COM_Nibble((int)*pcVar5);
      *local_8 = bVar2 | cVar1 << 4;
      cVar1 = COM_Nibble((int)param_1[iVar4 + 2]);
      bVar2 = COM_Nibble((int)pcVar5[2]);
      local_8[1] = bVar2 | cVar1 << 4;
      cVar1 = COM_Nibble((int)param_1[iVar4 + 4]);
      bVar2 = COM_Nibble((int)pcVar5[4]);
      local_8[2] = bVar2 | cVar1 << 4;
      cVar1 = COM_Nibble((int)param_1[iVar4 + 6]);
      bVar2 = COM_Nibble((int)pcVar5[6]);
      pcVar5 = pcVar5 + 8;
      local_8[3] = bVar2 | cVar1 << 4;
      local_8 = local_8 + 4;
    }
  }
  return;
}


// COM_Init  @ 0004bbb8
void COM_Init(void)

{
  if (swaptest != 1) {
    BigShort = ShortNoSwap;
    LittleShort = ShortSwap;
    BigLong = LongNoSwap;
    LittleLong = LongSwap;
    BigFloat = FloatNoSwap;
    LittleFloat = FloatSwap;
  }
  else {
    BigShort = ShortSwap;
    LittleShort = ShortNoSwap;
    BigLong = LongSwap;
    LittleLong = LongNoSwap;
    BigFloat = FloatSwap;
    LittleFloat = FloatNoSwap;
  }
  bigendien = (uint)(swaptest != 1);
  Cvar_RegisterVariable(cmdline);
  Cvar_RegisterVariable(com_filewarning);
  Cmd_AddCommand(&DAT_000a47d4,COM_Path_f);
  COM_BitOpsInit();
  COM_InitFilesystem();
  return;
}


// COM_InitArgv  @ 0004b8cc
void COM_InitArgv(int param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *local_c;
  int local_8;
  
  iVar5 = 0;
  local_8 = 0;
  local_c = param_2;
  do {
    if ((param_1 <= local_8) || (iVar7 = 0, 0xfe < iVar5)) break;
    uVar4 = 0xffU - iVar5 & 3;
    if (iVar5 < 0xff) {
      if (uVar4 == 0) goto LAB_0004b984;
      if (uVar4 < 2) goto LAB_0004b95f;
      if (uVar4 < 3) {
LAB_0004b944:
        pcVar1 = (char *)(iVar7 + *local_c);
        iVar6 = iVar5;
        if (*pcVar1 != '\0') {
          iVar7 = iVar7 + 1;
          (&com_cmdline)[iVar5] = *pcVar1;
          iVar5 = iVar5 + 1;
          goto LAB_0004b95f;
        }
      }
      else {
        iVar6 = iVar5;
        if (*(char *)*local_c != '\0') {
          iVar7 = 1;
          (&com_cmdline)[iVar5] = *(char *)*local_c;
          iVar5 = iVar5 + 1;
          goto LAB_0004b944;
        }
      }
    }
    else {
LAB_0004b95f:
      pcVar1 = (char *)(iVar7 + *local_c);
      iVar6 = iVar5;
      if (*pcVar1 != '\0') {
        iVar7 = iVar7 + 1;
        (&com_cmdline)[iVar5] = *pcVar1;
        iVar5 = iVar5 + 1;
        if (0xfe < iVar5) break;
LAB_0004b984:
        do {
          iVar6 = iVar5;
          if (*(char *)(iVar7 + *local_c) == '\0') break;
          (&com_cmdline)[iVar5] = *(char *)(iVar7 + *local_c);
          cVar2 = *(char *)(iVar7 + 1 + *local_c);
          iVar6 = iVar5 + 1;
          if (cVar2 == '\0') break;
          (&DAT_000e6861)[iVar5] = cVar2;
          cVar2 = *(char *)(iVar7 + 2 + *local_c);
          iVar6 = iVar5 + 2;
          if (cVar2 == '\0') break;
          (&DAT_000e6862)[iVar5] = cVar2;
          cVar2 = *(char *)(iVar7 + 3 + *local_c);
          iVar6 = iVar5 + 3;
          if (cVar2 == '\0') break;
          iVar7 = iVar7 + 4;
          (&DAT_000e6863)[iVar5] = cVar2;
          iVar5 = iVar5 + 4;
          iVar6 = iVar5;
        } while (iVar5 < 0xff);
      }
    }
    iVar5 = iVar6;
    if (0xfe < iVar6) break;
    (&com_cmdline)[iVar6] = 0x20;
    iVar5 = iVar6 + 1;
    local_c = local_c + 1;
    local_8 = local_8 + 1;
  } while (local_8 < 0x32);
  (&com_cmdline)[iVar5] = 0;
  bVar3 = false;
  com_argc = 0;
  do {
    if (param_1 <= com_argc) break;
    (&largv)[com_argc] = param_2[com_argc];
    iVar5 = Q_strcmp("-safe",param_2[com_argc]);
    if (iVar5 == 0) {
      bVar3 = true;
    }
    com_argc = com_argc + 1;
  } while (com_argc < 0x32);
  if (bVar3) {
    (&largv)[com_argc] = safeargvs;
    com_argc = com_argc + 1;
    (&largv)[com_argc] = PTR_s__nolan_000b2000;
    com_argc = com_argc + 1;
    (&largv)[com_argc] = PTR_FUN_000b2004;
    com_argc = com_argc + 1;
    (&largv)[com_argc] = PTR_s__nocdaudio_000b2008;
    com_argc = com_argc + 1;
    (&largv)[com_argc] = PTR_s__nojoy_000b200c;
    com_argc = com_argc + 1;
    (&largv)[com_argc] = PTR_s__nomouse_000b2010;
    com_argc = com_argc + 1;
    (&largv)[com_argc] = PTR_s__dibonly_000b2014;
    com_argc = com_argc + 1;
  }
  (&largv)[com_argc] = argvdummy;
  com_argv = &largv;
  iVar5 = COM_CheckParm("-rogue");
  if (iVar5 != 0) {
    rogue = 1;
    standard_quake = 0;
  }
  iVar5 = COM_CheckParm("-hipnotic");
  if (iVar5 != 0) {
    hipnotic = 1;
    standard_quake = 0;
  }
  return;
}


// COM_InitFilesystem  @ 0004d3d8
void COM_InitFilesystem(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 local_108 [260];
  
  iVar2 = COM_CheckParm("-basedir");
  uVar5 = host_parms;
  if ((iVar2 != 0) && (iVar2 < com_argc + -1)) {
    uVar5 = *(undefined4 *)(com_argv + 4 + iVar2 * 4);
  }
  Q_strcpy(local_108,uVar5);
  iVar2 = Q_strlen(local_108);
  if (0 < iVar2) {
    cVar1 = local_108[iVar2 + -1];
    if ((cVar1 == '\\') || (cVar1 == '/')) {
      local_108[iVar2 + -1] = 0;
    }
  }
  iVar2 = COM_CheckParm("-cachedir");
  if ((iVar2 == 0) || (com_argc + -1 <= iVar2)) {
    pcVar3 = DAT_000e8bc0;
    if (DAT_000e8bc0 == (char *)0x0) goto LAB_0004d4ac;
  }
  else {
    pcVar3 = *(char **)(com_argv + 4 + iVar2 * 4);
    if (*pcVar3 == '-') {
LAB_0004d4ac:
      com_cachedir = 0;
      goto LAB_0004d4b5;
    }
  }
  Q_strcpy(&com_cachedir,pcVar3);
LAB_0004d4b5:
  COM_AddGameDirectory(1,local_108,"valve");
  iVar2 = COM_CheckParm("-game");
  if ((iVar2 != 0) && (iVar2 < com_argc + -1)) {
    com_modified = 1;
    COM_AddGameDirectory(0,local_108,*(undefined4 *)(com_argv + 4 + iVar2 * 4));
  }
  iVar2 = COM_CheckParm("-path");
  if (iVar2 != 0) {
    com_modified = 1;
    com_searchpaths = 0;
    while ((((iVar2 = iVar2 + 1, iVar2 < com_argc &&
             (pcVar3 = *(char **)(com_argv + iVar2 * 4), pcVar3 != (char *)0x0)) &&
            (cVar1 = *pcVar3, cVar1 != '+')) && (cVar1 != '-'))) {
      iVar4 = Mem_ZeroMalloc(0x218);
      uVar5 = COM_FileExtension(*(undefined4 *)(com_argv + iVar2 * 4),&DAT_000a4a69);
      iVar6 = Q_strcmp(uVar5);
      if (iVar6 == 0) {
        iVar6 = COM_LoadPackFile(*(undefined4 *)(com_argv + iVar2 * 4));
        *(int *)(iVar4 + 0x208) = iVar6;
        if (iVar6 == 0) {
          Sys_Error("Couldn\'t load packfile: %s",*(undefined4 *)(com_argv + iVar2 * 4));
        }
      }
      else {
        Q_strcpy(iVar4,*(undefined4 *)(com_argv + iVar2 * 4));
      }
      *(int *)(iVar4 + 0x214) = com_searchpaths;
      com_searchpaths = iVar4;
    }
  }
  iVar2 = COM_CheckParm("-proghack");
  if (iVar2 != 0) {
    proghack = 1;
  }
  return;
}


// COM_ListMaps  @ 0004d684
void COM_ListMaps(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_1d8;
  int local_1d0;
  int local_1c8;
  char local_1c4 [64];
  undefined1 local_184 [128];
  undefined1 local_104 [128];
  undefined1 local_84 [128];
  
  local_1c8 = 0;
  iVar1 = com_searchpaths;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    local_1c8 = Q_strlen(param_1);
    iVar1 = com_searchpaths;
  }
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x214)) {
    Con_Printf("\nDir:  %s\n",iVar1 + 0x104);
    Con_Printf("-------------\n");
    iVar3 = *(int *)(iVar1 + 0x208);
    if (iVar3 == 0) {
      sprintf(local_1c4,"%s/maps/*.bsp",iVar1 + 0x104);
      iVar3 = Sys_FindFirst(local_1c4,0);
      while (iVar3 != 0) {
        if ((local_1c8 == 0) || (iVar2 = Q_strnicmp(iVar3,param_1,local_1c8), iVar2 == 0)) {
          Con_Printf("(fs) %s\n",iVar3);
        }
        iVar3 = Sys_FindNext(0);
      }
      Sys_FindClose();
    }
    else {
      local_1d0 = 0;
      if (0 < *(int *)(iVar3 + 0x108)) {
        local_1d8 = 0;
        do {
          iVar2 = Q_strnicmp("maps/",local_1d8 + *(int *)(iVar3 + 0x10c),4);
          if (iVar2 == 0) {
            Sys_SplitPath(local_1d8 + *(int *)(iVar3 + 0x10c),0,local_184,local_104,local_84);
            iVar2 = Q_stricmp(local_84,&DAT_000a4ab2);
            if ((iVar2 == 0) &&
               ((local_1c8 == 0 || (iVar2 = Q_strnicmp(local_104,param_1,local_1c8), iVar2 == 0))))
            {
              Con_Printf("(pak) %s\n",local_1d8 + *(int *)(iVar3 + 0x10c) + 5);
            }
          }
          local_1d8 = local_1d8 + 0x40;
          local_1d0 = local_1d0 + 1;
        } while (local_1d0 < *(int *)(iVar3 + 0x108));
      }
    }
  }
  return;
}


// COM_LoadCacheFile  @ 0004cd94
void COM_LoadCacheFile(undefined4 param_1,undefined4 param_2)

{
  loadcache = param_2;
  COM_LoadFile(param_1,3,0);
  return;
}


// COM_LoadFile  @ 0004c89c
int COM_LoadFile(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [32];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  iVar2 = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  iVar1 = COM_OpenFile(param_1,&local_10);
  if (local_8 == -1) {
    iVar2 = 0;
  }
  else {
    COM_FileBase(param_1,local_30);
    if (param_2 == 1) {
      iVar2 = Hunk_AllocName(iVar1 + 1,local_30);
    }
    else if (param_2 == 2) {
      iVar2 = Hunk_TempAlloc(iVar1 + 1);
    }
    else if (param_2 == 0) {
      iVar2 = Z_Malloc(iVar1 + 1);
    }
    else if (param_2 == 3) {
      iVar2 = Cache_Alloc(loadcache,iVar1 + 1,local_30);
    }
    else if (param_2 == 4) {
      iVar2 = loadbuf;
      if (loadsize < iVar1 + 1) {
        iVar2 = Hunk_TempAlloc(iVar1 + 1);
      }
    }
    else if (param_2 == 5) {
      iVar2 = Mem_Malloc(iVar1 + 1);
    }
    else {
      Sys_Error("COM_LoadFile: bad usehunk");
    }
    if (iVar2 == 0) {
      Sys_Error("COM_LoadFile: not enough space for %s",param_1);
      COM_CloseFile(local_10,local_c,local_8);
      iVar2 = 0;
    }
    else {
      *(undefined1 *)(iVar1 + iVar2) = 0;
      Sys_FileRead(local_8,iVar2,iVar1);
      COM_CloseFile(local_10,local_c,local_8);
      if (param_3 != (int *)0x0) {
        *param_3 = iVar1;
      }
    }
  }
  return iVar2;
}


// COM_LoadFileForMe  @ 0004d91c
void COM_LoadFileForMe(undefined4 param_1,undefined4 param_2)

{
  COM_LoadFile(param_1,5,param_2);
  return;
}


// COM_LoadFileLimit  @ 0004cc24
int COM_LoadFileLimit(int param_1,int param_2,int param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [32];
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (param_5[2] == -1) {
    iVar1 = COM_OpenFile(param_1,&local_10);
    local_c = com_filesize;
  }
  else {
    local_10 = *param_5;
    iVar1 = param_5[1];
    local_c = iVar1;
    local_8 = param_5[2];
  }
  if (local_8 == -1) {
    iVar2 = 0;
  }
  else {
    if (iVar1 < param_2) {
      Sys_Error("COM_LoadFileLimit: invalid seek position for %s",param_1);
    }
    COM_FileSeek(local_10,local_c,local_8,param_2);
    if (param_3 < iVar1) {
      iVar1 = param_3;
    }
    *param_4 = iVar1;
    if (param_1 != 0) {
      COM_FileBase(param_1,local_30);
    }
    iVar2 = Hunk_TempAlloc(iVar1 + 1);
    if (iVar2 == 0) {
      if (param_1 != 0) {
        Sys_Error(FUN_000a49c0,param_1);
      }
      COM_CloseFile(local_10,local_c,local_8);
      iVar2 = 0;
    }
    else {
      *(undefined1 *)(iVar1 + iVar2) = 0;
      Sys_FileRead(local_8,iVar2,iVar1);
      *param_5 = local_10;
      param_5[1] = local_c;
      param_5[2] = local_8;
    }
  }
  return iVar2;
}


// COM_LoadHunkFile  @ 0004cd48
void COM_LoadHunkFile(undefined4 param_1)

{
  COM_LoadFile(param_1,1,0);
  return;
}


// COM_LoadPackFile  @ 0004ce04
int COM_LoadPackFile(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = Sys_FileOpenRead(param_1,&local_14);
  if (iVar1 == -1) {
    iVar2 = 0;
  }
  else {
    Sys_FileRead(local_14,&local_10,0xc);
    if (local_10 != 0x4b434150) {
      Sys_Error("%s is not a packfile",param_1);
    }
    local_c = (*LittleLong)(local_c);
    local_8 = (*LittleLong)(local_8);
    uVar3 = local_8 >> 6;
    if (0x1000 < uVar3) {
      Sys_Error("%s has %i files",param_1,uVar3);
    }
    if (uVar3 != 0x153) {
      com_modified = 1;
    }
    iVar1 = Mem_ZeroMalloc(uVar3 << 6);
    Sys_FileSeek(local_14,local_c);
    Sys_FileRead(local_14,iVar1,local_8);
    CRC32_Init(&local_18);
    CRC32_ProcessBuffer(&local_18,iVar1,local_8);
    if (local_18 != 0x80d5) {
      com_modified = 1;
    }
    local_1c = 0;
    if (uVar3 != 0) {
      puVar7 = (undefined4 *)(iVar1 + 0x3c);
      puVar6 = (undefined4 *)(iVar1 + 0x38);
      uVar4 = uVar3 & 3;
      if (uVar4 == 0) goto LAB_0004cfec;
      if (1 < uVar4) {
        if (2 < uVar4) {
          uVar5 = (*LittleLong)(*(undefined4 *)(iVar1 + 0x38));
          *(undefined4 *)(iVar1 + 0x38) = uVar5;
          uVar5 = (*LittleLong)(*(undefined4 *)(iVar1 + 0x3c));
          puVar7 = (undefined4 *)(iVar1 + 0x7c);
          puVar6 = (undefined4 *)(iVar1 + 0x78);
          *(undefined4 *)(iVar1 + 0x3c) = uVar5;
        }
        local_1c = (uint)(2 < uVar4);
        uVar5 = (*LittleLong)(*puVar6);
        *puVar6 = uVar5;
        uVar5 = (*LittleLong)(*puVar7);
        *puVar7 = uVar5;
        puVar7 = puVar7 + 0x10;
        puVar6 = puVar6 + 0x10;
        local_1c = local_1c + 1;
      }
      uVar5 = (*LittleLong)(*puVar6);
      *puVar6 = uVar5;
      uVar5 = (*LittleLong)(*puVar7);
      *puVar7 = uVar5;
      puVar7 = puVar7 + 0x10;
      puVar6 = puVar6 + 0x10;
      for (local_1c = local_1c + 1; (int)local_1c < (int)uVar3; local_1c = local_1c + 4) {
LAB_0004cfec:
        uVar5 = (*LittleLong)(*puVar6);
        *puVar6 = uVar5;
        uVar5 = (*LittleLong)(*puVar7);
        *puVar7 = uVar5;
        uVar5 = (*LittleLong)(puVar6[0x10]);
        puVar6[0x10] = uVar5;
        uVar5 = (*LittleLong)(puVar7[0x10]);
        puVar7[0x10] = uVar5;
        uVar5 = (*LittleLong)(puVar6[0x20]);
        puVar6[0x20] = uVar5;
        uVar5 = (*LittleLong)(puVar7[0x20]);
        puVar7[0x20] = uVar5;
        uVar5 = (*LittleLong)(puVar6[0x30]);
        puVar6[0x30] = uVar5;
        uVar5 = (*LittleLong)(puVar7[0x30]);
        puVar7[0x30] = uVar5;
        puVar7 = puVar7 + 0x40;
        puVar6 = puVar6 + 0x40;
      }
    }
    iVar2 = Mem_Malloc(0x110);
    Q_strcpy(iVar2,param_1);
    *(undefined4 *)(iVar2 + 0x104) = local_14;
    *(uint *)(iVar2 + 0x108) = uVar3;
    *(int *)(iVar2 + 0x10c) = iVar1;
    Con_Printf("Added packfile %s (%i files)\n",param_1,uVar3);
  }
  return iVar2;
}


// COM_LoadStackFile  @ 0004cdc4
void COM_LoadStackFile(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  loadbuf = param_2;
  loadsize = param_3;
  COM_LoadFile(param_1,4,0);
  return;
}


// COM_LoadTempFile  @ 0004cd6c
void COM_LoadTempFile(undefined4 param_1,undefined4 param_2)

{
  COM_LoadFile(param_1,2,param_2);
  return;
}


// COM_Log  @ 0004d8ac
void COM_Log(char *param_1,char *param_2)

{
  FILE *__stream;
  char local_404 [1024];
  
  if (param_1 == (char *)0x0) {
    param_1 = "c:\\hllog.txt";
  }
  vsprintf(local_404,param_2,&stack0x0000000c);
  __stream = fopen(param_1,"a+t");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s",local_404);
    fclose(__stream);
  }
  return;
}


// COM_MultipleCloseFile  @ 0004c704
void COM_MultipleCloseFile(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = com_searchpaths;
    if (param_1 == 0) {
      return;
    }
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x214)) {
      if ((*(int *)(iVar1 + 0x208) != 0) &&
         (*(int *)(*(int *)(iVar1 + 0x208) + 0x104) == *(int *)(*(int *)(param_1 + 4) + 8)))
      goto LAB_0004c765;
    }
    Sys_FileClose(*(undefined4 *)(*(int *)(param_1 + 4) + 8));
LAB_0004c765:
    param_1 = *(int *)(param_1 + 0x10c);
  } while( true );
}


// COM_MultipleOpenFile  @ 0004c648
int COM_MultipleOpenFile(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_10;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  if (param_2 == (int *)0x0) {
    local_10 = 0;
  }
  else {
    *param_2 = 0;
    while( true ) {
      iVar1 = Mem_ZeroMalloc(0xc);
      iVar2 = COM_FindFileSearch(&local_8,0,param_1,iVar1,0);
      if (iVar2 == -1) break;
      piVar3 = (int *)Mem_ZeroMalloc(0x110);
      *piVar3 = iVar2;
      piVar3[1] = iVar1;
      Q_strcpy(piVar3 + 2,local_8 + 0x104);
      piVar3[0x43] = *param_2;
      *param_2 = (int)piVar3;
      local_10 = local_10 + 1;
    }
    Mem_Free(iVar1);
  }
  return local_10;
}


// COM_Munge  @ 0004dcdc
void COM_Munge(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *local_10;
  undefined4 local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  if (0 < (int)param_2 >> 2) {
    local_10 = param_1;
    uVar3 = 0;
    do {
      uVar2 = LongSwap(~param_3 ^ *local_10);
      uVar1 = uVar3 + 1;
      local_8._0_1_ = (byte)uVar2;
      local_8._0_1_ = (byte)local_8 ^ ((&mungify_table)[uVar3 & 0xf] | 0xa5);
      local_8._1_1_ = (byte)((uint)uVar2 >> 8);
      local_8._1_1_ = local_8._1_1_ ^ ((&mungify_table)[uVar1 & 0xf] | 0xa7);
      local_8._2_1_ = (byte)((uint)uVar2 >> 0x10);
      local_8._2_1_ = local_8._2_1_ ^ ((&mungify_table)[uVar3 + 2 & 0xf] | 0xaf);
      local_8._3_1_ = (byte)((uint)uVar2 >> 0x18);
      local_8 = CONCAT13(local_8._3_1_ ^ ((&mungify_table)[uVar3 + 3 & 0xf] | 0xbf),
                         CONCAT12(local_8._2_1_,(undefined2)local_8));
      *local_10 = param_3 ^ local_8;
      local_10 = local_10 + 1;
      uVar3 = uVar1;
    } while ((int)uVar1 < (int)param_2 >> 2);
  }
  return;
}


// COM_Nibble  @ 000497f8
byte COM_Nibble(char param_1)

{
  byte bVar1;
  
  bVar1 = param_1 - 0x30;
  if (9 < bVar1) {
    if ((byte)(param_1 + 0xbfU) < 6) {
      bVar1 = param_1 - 0x37;
    }
    else if ((byte)(param_1 + 0x9fU) < 6) {
      bVar1 = param_1 + 0xa9;
    }
    else {
      bVar1 = 0x30;
    }
  }
  return bVar1;
}


// COM_NormalizeAngles  @ 0004db1c
void COM_NormalizeAngles(float *param_1)

{
  float *pfVar1;
  float fVar2;
  
  pfVar1 = param_1 + 2;
  if ((int)param_1 < (int)param_1 + 9) {
    fVar2 = *param_1;
    if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
        goto LAB_0004db8f;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
LAB_0004db8f:
      *param_1 = fVar2;
    }
    fVar2 = param_1[1];
    if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
        goto LAB_0004dbbf;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
LAB_0004dbbf:
      param_1[1] = fVar2;
    }
    param_1 = param_1 + 2;
  }
  fVar2 = *param_1;
  if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
    if (-180.0 <= fVar2) goto LAB_0004dbfb;
    fVar2 = fVar2 + 360.0;
  }
  else {
    fVar2 = fVar2 - 360.0;
  }
  *param_1 = fVar2;
LAB_0004dbfb:
  param_1 = param_1 + 1;
  do {
    if ((int)pfVar1 < (int)param_1) {
      return;
    }
    fVar2 = *param_1;
    if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
        goto LAB_0004dc27;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
LAB_0004dc27:
      *param_1 = fVar2;
    }
    fVar2 = param_1[1];
    if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
        goto LAB_0004dc53;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
LAB_0004dc53:
      param_1[1] = fVar2;
    }
    fVar2 = param_1[2];
    if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
        goto LAB_0004dc83;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
LAB_0004dc83:
      param_1[2] = fVar2;
    }
    fVar2 = param_1[3];
    if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
        goto LAB_0004dcb3;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
LAB_0004dcb3:
      param_1[3] = fVar2;
    }
    param_1 = param_1 + 4;
  } while( true );
}


// COM_OpenFile  @ 0004c7a8
void COM_OpenFile(undefined4 param_1,undefined4 param_2)

{
  COM_FindFileSearch(0,0,param_1,param_2,0);
  return;
}


// COM_OpenFileInDir  @ 0004c77c
void COM_OpenFileInDir(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  COM_FindFileSearch(0,param_1,param_2,param_3,0);
  return;
}


// COM_Parse  @ 0004b734
char * COM_Parse(char *param_1)

{
  char cVar1;
  int iVar2;
  
  if (s_com_token_unget == 0) {
    iVar2 = 0;
    com_token = 0;
    if (param_1 != (char *)0x0) {
      while( true ) {
        for (; cVar1 = *param_1, cVar1 < '!'; param_1 = param_1 + 1) {
          if (cVar1 == '\0') goto LAB_0004b76f;
        }
        if ((cVar1 != '/') || (param_1[1] != '/')) break;
        for (; (*param_1 != '\0' && (*param_1 != '\n')); param_1 = param_1 + 1) {
        }
      }
      if (cVar1 == '\"') {
        param_1 = param_1 + 1;
        iVar2 = 0;
        while( true ) {
          cVar1 = *param_1;
          param_1 = param_1 + 1;
          if ((cVar1 == '\"') || (cVar1 == '\0')) break;
          (&com_token)[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        }
      }
      else {
        if ((((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
             ((cVar1 == '(' || (cVar1 == '\'')))) || ((com_ignorecolons == 0 && (cVar1 == ':')))) ||
           (cVar1 == ',')) {
          com_token = cVar1;
          DAT_000e5a01._0_1_ = 0;
          return param_1 + 1;
        }
        while( true ) {
          param_1 = param_1 + 1;
          (&com_token)[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
          cVar1 = *param_1;
          if ((((cVar1 == '{') || (cVar1 == '}')) ||
              ((cVar1 == ')' || ((cVar1 == '(' || (cVar1 == '\'')))))) ||
             ((com_ignorecolons == 0 && (cVar1 == ':')))) break;
          if ((cVar1 == ',') || (cVar1 < '!')) break;
        }
      }
      (&com_token)[iVar2] = 0;
      return param_1;
    }
LAB_0004b76f:
    param_1 = (char *)0x0;
  }
  else {
    s_com_token_unget = 0;
  }
  return param_1;
}


// COM_Path_f  @ 0004c304
void COM_Path_f(void)

{
  int iVar1;
  int iVar2;
  
  Con_Printf("Current search path:\n");
  for (iVar2 = com_searchpaths; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x214)) {
    if (*(int *)(iVar2 + 0x210) != 0) {
      Con_Printf(&DAT_000a48b4);
    }
    iVar1 = *(int *)(iVar2 + 0x208);
    if (iVar1 == 0) {
      Con_Printf(&DAT_000a48c8,iVar2);
    }
    else {
      Con_Printf("%s (%i files)\n",iVar1,*(undefined4 *)(iVar1 + 0x108));
    }
  }
  return;
}


// COM_Shutdown  @ 0004d16c
void COM_Shutdown(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = com_searchpaths;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x214);
    COM_FreeSearchPath(iVar2);
    iVar2 = iVar1;
  }
  com_searchpaths = 0;
  return;
}


// COM_SizeofResourceList  @ 0004e1a0
int COM_SizeofResourceList(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  Q_memset(param_2,0,0x1c);
  for (iVar2 = *(int *)(param_1 + 0x80); iVar2 != param_1; iVar2 = *(int *)(iVar2 + 0x80)) {
    iVar3 = *(int *)(iVar2 + 0x48);
    local_8 = local_8 + iVar3;
    if ((*(int *)(iVar2 + 0x40) == 2) && (*(int *)(iVar2 + 0x44) == 1)) {
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + iVar3;
    }
    else {
      piVar1 = (int *)(param_2 + *(int *)(iVar2 + 0x40) * 4);
      *piVar1 = *piVar1 + iVar3;
    }
  }
  return local_8;
}


// COM_SkipPath  @ 0004b358
char * COM_SkipPath(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *param_1;
  pcVar2 = param_1;
  while (cVar1 != '\0') {
    if (*param_1 == '/') {
      pcVar2 = param_1 + 1;
    }
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return pcVar2;
}


// COM_StripExtension  @ 0004b37c
void COM_StripExtension(char *param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar4 = Q_strlen(param_1);
  pcVar6 = param_1 + iVar4;
  iVar4 = Q_strlen(param_1);
  pcVar5 = (char *)(param_2 + iVar4);
  bVar3 = false;
  if (pcVar6 < param_1) {
    return;
  }
  uVar1 = (int)(param_1 + -1) - (int)pcVar6 & 3;
  if ((int)(param_1 + -1) < (int)pcVar6) {
    if (uVar1 == 0) goto LAB_0004b454;
    if (uVar1 < 3) {
      if (uVar1 < 2) {
        cVar2 = *pcVar6;
        if (cVar2 == '.') {
          *pcVar5 = '\0';
          bVar3 = true;
        }
        else {
          if ((cVar2 == '/') || (cVar2 == '\\')) {
            bVar3 = true;
          }
          *pcVar5 = cVar2;
        }
        pcVar6 = pcVar6 + -1;
        pcVar5 = pcVar5 + -1;
      }
      if ((bVar3) || (*pcVar6 != '.')) {
        cVar2 = *pcVar6;
        if ((cVar2 == '/') || (cVar2 == '\\')) {
          bVar3 = true;
        }
        *pcVar5 = cVar2;
      }
      else {
        *pcVar5 = '\0';
        bVar3 = true;
      }
      pcVar6 = pcVar6 + -1;
      pcVar5 = pcVar5 + -1;
    }
  }
  if ((bVar3) || (*pcVar6 != '.')) {
    cVar2 = *pcVar6;
    if ((cVar2 == '/') || (cVar2 == '\\')) {
      bVar3 = true;
    }
    *pcVar5 = cVar2;
  }
  else {
    *pcVar5 = '\0';
    bVar3 = true;
  }
  pcVar6 = pcVar6 + -1;
  pcVar5 = pcVar5 + -1;
  if (pcVar6 < param_1) {
    return;
  }
LAB_0004b454:
  do {
    if ((bVar3) || (*pcVar6 != '.')) {
      cVar2 = *pcVar6;
      if ((cVar2 == '/') || (cVar2 == '\\')) {
        bVar3 = true;
      }
      *pcVar5 = cVar2;
    }
    else {
      *pcVar5 = '\0';
      bVar3 = true;
    }
    if ((bVar3) || (pcVar6[-1] != '.')) {
      cVar2 = pcVar6[-1];
      if ((cVar2 == '/') || (cVar2 == '\\')) {
        bVar3 = true;
      }
      pcVar5[-1] = cVar2;
    }
    else {
      pcVar5[-1] = '\0';
      bVar3 = true;
    }
    if ((bVar3) || (pcVar6[-2] != '.')) {
      cVar2 = pcVar6[-2];
      if ((cVar2 == '/') || (cVar2 == '\\')) {
        bVar3 = true;
      }
      pcVar5[-2] = cVar2;
    }
    else {
      pcVar5[-2] = '\0';
      bVar3 = true;
    }
    if ((bVar3) || (pcVar6[-3] != '.')) {
      cVar2 = pcVar6[-3];
      if ((cVar2 == '/') || (cVar2 == '\\')) {
        bVar3 = true;
      }
      pcVar5[-3] = cVar2;
    }
    else {
      pcVar5[-3] = '\0';
      bVar3 = true;
    }
    pcVar6 = pcVar6 + -4;
    pcVar5 = pcVar5 + -4;
  } while (param_1 <= pcVar6);
  return;
}


// COM_UnMunge  @ 0004dd90
void COM_UnMunge(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *local_14;
  undefined4 local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  if (0 < (int)param_2 >> 2) {
    local_14 = param_1;
    uVar2 = 0;
    do {
      uVar3 = param_3 ^ *local_14;
      uVar1 = uVar2 + 1;
      local_8._0_1_ = (byte)uVar3;
      local_8._0_1_ = (byte)local_8 ^ ((&mungify_table)[uVar2 & 0xf] | 0xa5);
      local_8._1_1_ = (byte)(uVar3 >> 8);
      local_8._1_1_ = local_8._1_1_ ^ ((&mungify_table)[uVar1 & 0xf] | 0xa7);
      local_8._2_1_ = (byte)(uVar3 >> 0x10);
      local_8._2_1_ = local_8._2_1_ ^ ((&mungify_table)[uVar2 + 2 & 0xf] | 0xaf);
      local_8._3_1_ = (byte)(uVar3 >> 0x18);
      local_8 = CONCAT13(local_8._3_1_ ^ ((&mungify_table)[uVar2 + 3 & 0xf] | 0xbf),
                         CONCAT12(local_8._2_1_,(undefined2)local_8));
      uVar2 = LongSwap(local_8);
      *local_14 = uVar2 ^ ~param_3;
      local_14 = local_14 + 1;
      uVar2 = uVar1;
    } while ((int)uVar1 < (int)param_2 >> 2);
  }
  return;
}


// COM_UngetToken  @ 0004b710
void COM_UngetToken(void)

{
  s_com_token_unget = 1;
  return;
}


// COM_WriteFile  @ 0004c390
void COM_WriteFile(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char local_108 [260];
  
  sprintf(local_108,"%s/%s",com_gamedir,param_1);
  COM_FixSlashes(local_108);
  COM_CreatePath(local_108);
  iVar1 = Sys_FileOpenWrite(local_108);
  if (iVar1 == -1) {
    Sys_Printf("COM_WriteFile: failed on %s\n",local_108);
  }
  else {
    Sys_Printf("COM_WriteFile: %s\n",local_108);
    Sys_FileWrite(iVar1,param_2,param_3);
    Sys_FileClose(iVar1);
  }
  return;
}


