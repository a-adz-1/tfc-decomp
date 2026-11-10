// COM_AddGameDirectory  @ 080513d0
void COM_AddGameDirectory(undefined4 param_1,undefined4 param_2,char *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  char *__dest;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int local_210;
  char local_20c [260];
  char local_108 [260];
  
  sprintf(local_20c,"%s/%s",param_2,param_3);
  uVar1 = Info_Serverinfo("*gamedir",param_3,0x200);
  Info_SetValueForStarKey(uVar1);
  strcpy(com_gamedir,local_20c);
  local_210 = 0;
  while( true ) {
    sprintf(local_108,"%s/pak%i.pak",local_20c,local_210);
    COM_FixSlashes(local_108);
    iVar3 = COM_LoadPackFile(local_108);
    if (iVar3 == 0) break;
    puVar2 = malloc(0x218);
    puVar5 = puVar2;
    for (iVar4 = 0x86; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    strcpy((char *)(puVar2 + 0x41),param_3);
    puVar2[0x84] = param_1;
    puVar2[0x82] = iVar3;
    puVar2[0x85] = com_searchpaths;
    com_searchpaths = (char *)puVar2;
    uVar1 = Sys_FileTime(local_108);
    puVar2[0x83] = uVar1;
    local_210 = local_210 + 1;
  }
  __dest = malloc(0x218);
  pcVar6 = __dest;
  for (iVar3 = 0x86; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  strcpy(__dest + 0x104,param_3);
  *(undefined4 *)(__dest + 0x210) = param_1;
  strcpy(__dest,local_20c);
  *(char **)(__dest + 0x214) = com_searchpaths;
  com_searchpaths = __dest;
  return;
}


// COM_BinPrintf  @ 0804e2b0
undefined4 * COM_BinPrintf(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char local_10 [12];
  
  puVar2 = &szReturn_140;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar1 = 0;
  if (0 < param_2) {
    do {
      sprintf(local_10,"%02x",(uint)*(byte *)(iVar1 + param_1));
      strcat((char *)&szReturn_140,local_10);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return &szReturn_140;
}


// COM_BitOpsInit  @ 0804ed10
void COM_BitOpsInit(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  bfwrite = 0;
  DAT_080b4fac = 0;
  DAT_080b4fb0 = 0;
  puVar2 = &bfread;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// COM_BlockSequenceCRCByte  @ 0808c3a0
undefined1 COM_BlockSequenceCRCByte(void *param_1,size_t param_2,uint param_3)

{
  undefined1 uVar1;
  undefined4 local_48;
  undefined1 local_44 [64];
  
  if ((int)param_3 < 0) {
    Sys_Error("sequence < 0, in COM_BlockSequenceCRCByte\n");
  }
  param_3 = param_3 % 0x3fc;
  if (0x3c < (int)param_2) {
    param_2 = 0x3c;
  }
  memcpy(local_44,param_1,param_2);
  local_44[param_2] = pulCRCTable[param_3];
  local_44[param_2 + 1] = pulCRCTable[param_3 + 1];
  local_44[param_2 + 2] = pulCRCTable[param_3 + 2];
  local_44[param_2 + 3] = pulCRCTable[param_3 + 3];
  CRC32_Init(&local_48);
  CRC32_ProcessBuffer(&local_48,local_44,param_2 + 4);
  uVar1 = CRC32_Final(local_48);
  return uVar1;
}


// COM_ChangeGameDir  @ 08051550
void COM_ChangeGameDir(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (com_searchpaths != 0) {
    iVar3 = 0;
    iVar2 = com_searchpaths;
    do {
      iVar1 = *(int *)(iVar2 + 0x214);
      if (*(int *)(iVar2 + 0x210) == 0) {
        COM_FreeSearchPath(iVar2);
      }
      else {
        *(int *)(iVar2 + 0x214) = iVar3;
        iVar3 = iVar2;
      }
      iVar2 = iVar1;
    } while (iVar1 != 0);
  }
  com_searchpaths = 0;
  while (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x214);
    *(int *)(iVar3 + 0x214) = com_searchpaths;
    com_searchpaths = iVar3;
    iVar3 = iVar2;
  }
  COM_AddGameDirectory(0,host_parms,param_1);
  return;
}


// COM_CheckAuthenticationType  @ 08053090
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void COM_CheckAuthenticationType(void)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  undefined1 local_80c [8];
  undefined1 local_804 [2048];
  
  if (((Launcher_GetCertificate == (code *)0x0) ||
      (Launcher_RequestNewClientCertificate == (code *)0x0)) || (noip != 0)) {
    gfUseLANAuthentication = 1;
    return;
  }
  lVar2 = (longdouble)Sys_FloatTime();
  iVar1 = (*Launcher_GetCertificate)(local_804,local_80c);
  if (iVar1 != 2) {
    Con_Printf("Trying to authenticate with WON servers\n");
    iVar1 = (*Launcher_RequestNewClientCertificate)();
    if (iVar1 == 0) {
      gfUseLANAuthentication = 1;
      return;
    }
    iVar1 = (*Launcher_GetCertificate)(local_804,local_80c);
    if (iVar1 != 2) {
      gfUseLANAuthentication = 1;
      return;
    }
    Con_Printf("WON Authentication successful\n");
  }
  gfUseLANAuthentication = 0;
  lVar3 = (longdouble)Sys_FloatTime();
  _DAT_081b9158 = (double)(((float)lVar3 - (float)lVar2) + (float)_DAT_081b9158);
  return;
}


// COM_CheckParm  @ 080500e0
int COM_CheckParm(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (1 < com_argc) {
    do {
      if ((*(int *)(com_argv + iVar2 * 4) != 0) &&
         (iVar1 = Q_strcmp(param_1,*(undefined4 *)(com_argv + iVar2 * 4)), iVar1 == 0)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < com_argc);
  }
  return 0;
}


// COM_CheckRegistered  @ 08050140
void COM_CheckRegistered(void)

{
  return;
}


// COM_ClearCustomizationList  @ 08052790
void COM_ClearCustomizationList(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *__ptr;
  int iVar3;
  int iVar4;
  int local_10;
  
  __ptr = *(int **)(param_1 + 0x80);
  while (__ptr != (int *)0x0) {
    piVar1 = (int *)__ptr[0x20];
    if (*__ptr != 0) {
      if (__ptr[0x1f] != 0) {
        free((void *)__ptr[0x1f]);
      }
      if ((*__ptr != 0) && (__ptr[0x1e] != 0)) {
        if (__ptr[0x11] == 3) {
          if ((param_2 != 0) && (cls == 5)) {
            R_DecalRemoveAll(~(uint)*(byte *)((int)__ptr + 0x61));
          }
          iVar2 = __ptr[0x1e];
          free(*(void **)(iVar2 + 0x10));
          local_10 = *(int *)(iVar2 + 4);
          for (iVar4 = 0; iVar4 < *(int *)(iVar2 + 8); iVar4 = iVar4 + 1) {
            iVar3 = Cache_Check(local_10 + 0x40);
            if (iVar3 != 0) {
              Cache_Free(local_10 + 0x40);
            }
            local_10 = local_10 + 0x44;
          }
          free(*(void **)(iVar2 + 4));
        }
        free((void *)__ptr[0x1e]);
      }
    }
    free(__ptr);
    __ptr = piVar1;
  }
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}


// COM_CloseFile  @ 08050d40
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


// COM_CompareFileTime  @ 08052ab0
undefined4 COM_CompareFileTime(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  FILE *local_8;
  
  uVar1 = 0;
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
        *param_3 = uVar1;
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


// COM_CopyFile  @ 080509d0
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


// COM_CopyFileChunk  @ 08050f50
void COM_CopyFileChunk(FILE *param_1,FILE *param_2,size_t param_3)

{
  undefined1 local_404 [1024];
  
  if (0x400 < (int)param_3) {
    do {
      fread(local_404,0x400,1,param_2);
      fwrite(local_404,0x400,1,param_1);
      param_3 = param_3 - 0x400;
    } while (0x400 < (int)param_3);
  }
  fread(local_404,param_3,1,param_2);
  fwrite(local_404,param_3,1,param_1);
  fflush(param_2);
  fflush(param_1);
  return;
}


// COM_CreateCustomization  @ 080528a0
uint COM_CreateCustomization
               (int param_1,undefined4 *param_2,undefined4 param_3,int param_4,int param_5,
               int param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 *__ptr;
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint local_8;
  
  local_8 = 0;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  __ptr = malloc(0x84);
  puVar2 = __ptr;
  for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar4 = param_2;
  puVar2 = __ptr;
  for (iVar3 = 0x1a; puVar2 = puVar2 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = *puVar4;
    puVar4 = puVar4 + 1;
  }
  if ((int)param_2[0x12] < 1) {
    local_8 = 1;
LAB_08052a17:
    if (local_8 == 0) {
      if (param_7 != (undefined4 *)0x0) {
        *param_7 = __ptr;
      }
      __ptr[0x20] = *(undefined4 *)(param_1 + 0x80);
      *(undefined4 **)(param_1 + 0x80) = __ptr;
      goto LAB_08052a7a;
    }
  }
  else {
    *__ptr = 1;
    if (param_4 == 0) {
      uVar1 = COM_LoadFile(param_2,5,0);
      __ptr[0x1f] = uVar1;
LAB_08052945:
      if ((((*(byte *)(__ptr + 0x14) & 4) == 0) || (__ptr[0x11] != 3)) ||
         (*(undefined1 *)((int)__ptr + 0x61) = (undefined1)param_3, param_6 != 0))
      goto LAB_08052a17;
      puVar2 = malloc(0x2c);
      __ptr[0x1e] = puVar2;
      for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      iVar3 = __ptr[0x1e];
      if (param_2[0x12] - 0x400 < 0x3c01) {
        CustomDecal_Init(iVar3,__ptr[0x1f],param_2[0x12],param_3);
        if (0 < *(int *)(iVar3 + 0x14)) {
          if (param_8 != (undefined4 *)0x0) {
            *param_8 = *(undefined4 *)(iVar3 + 0x14);
          }
          __ptr[0x1b] = 1;
          __ptr[0x1c] = 0;
          __ptr[0x1d] = *(undefined4 *)(iVar3 + 0x14);
          if (param_5 != 0) {
            free(*(void **)(iVar3 + 4));
            free(*(void **)(iVar3 + 0x10));
            free((void *)__ptr[0x1e]);
            __ptr[0x1e] = 0;
          }
          goto LAB_08052a17;
        }
      }
    }
    else {
      iVar3 = HPAK_GetDataPointer("custom.hpk",param_2,__ptr + 0x1f,0);
      if (iVar3 != 0) goto LAB_08052945;
    }
    local_8 = 1;
  }
  if (__ptr[0x1f] != 0) {
    free((void *)__ptr[0x1f]);
  }
  if (__ptr[0x1e] != 0) {
    free((void *)__ptr[0x1e]);
  }
  free(__ptr);
LAB_08052a7a:
  return local_8 ^ 1;
}


// COM_CreatePath  @ 08050990
void COM_CreatePath(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 1);
  cVar1 = *(char *)(param_1 + 1);
  while (cVar1 != '\0') {
    if ((*pcVar2 == '/') || (*pcVar2 == '\\')) {
      cVar1 = *pcVar2;
      *pcVar2 = '\0';
      Sys_mkdir(param_1);
      *pcVar2 = cVar1;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  return;
}


// COM_DefaultExtension  @ 0804ff70
void COM_DefaultExtension(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = param_1 + (~uVar2 - 2);
  cVar1 = *pcVar3;
  while ((cVar1 != '/' && (pcVar3 != param_1))) {
    if (*pcVar3 == '.') {
      return;
    }
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
  }
  strcat(param_1,param_2);
  return;
}


// COM_DestroyMultipleFileList  @ 08050b00
void COM_DestroyMultipleFileList(undefined4 *param_1)

{
  void *pvVar1;
  void *__ptr;
  
  if (param_1 != (undefined4 *)0x0) {
    __ptr = (void *)*param_1;
    while (__ptr != (void *)0x0) {
      pvVar1 = *(void **)((int)__ptr + 0x10c);
      if (*(int *)((int)__ptr + 4) != 0) {
        free(*(void **)((int)__ptr + 4));
      }
      free(__ptr);
      __ptr = pvVar1;
    }
    *param_1 = 0;
  }
  return;
}


// COM_EntsForPlayerSlots  @ 08053160
int COM_EntsForPlayerSlots(int param_1)

{
  return (param_1 + -1) * 0xf + 800;
}


// COM_ExpandFilename  @ 08050a70
undefined4 COM_ExpandFilename(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char local_108 [260];
  
  pcVar2 = com_searchpaths;
  do {
    if (pcVar2 == (char *)0x0) {
      if ((param_1 != (char *)0x0) && (*param_1 != '*')) {
        Sys_Printf("COM_ExpandFilename: can\'t find %s\n",param_1);
      }
      return 0;
    }
    iVar3 = -1;
    pcVar4 = pcVar2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar3 != -2) {
      sprintf(local_108,"%s/%s",pcVar2,param_1);
      iVar3 = Sys_FileTime(local_108);
      if (0 < iVar3) {
        strcpy(param_1,local_108);
        return 1;
      }
    }
    pcVar2 = *(char **)(pcVar2 + 0x214);
  } while( true );
}


// COM_ExplainDisconnection  @ 0804e310
void COM_ExplainDisconnection(int param_1,char *param_2)

{
  vsprintf(string_143,param_2,&stack0x0000000c);
  strncpy(gszDisconnectReason,string_143,0xff);
  gszDisconnectReason[0xff] = 0;
  gfExtendedError = 1;
  if (param_1 != 0) {
    Con_Printf(&DAT_0809ebf5,gszDisconnectReason);
  }
  return;
}


// COM_FOpenFile  @ 08050ce0
void COM_FOpenFile(undefined4 param_1,undefined4 param_2)

{
  COM_FindFileSearch(0,0,param_1,0,param_2);
  return;
}


// COM_FileBase  @ 0804fed0
void COM_FileBase(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  size_t __n;
  
  uVar2 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  for (iVar3 = uVar2 - 2; iVar3 != 0; iVar3 = iVar3 + -1) {
    if (param_1[iVar3] == '.') goto LAB_0804ff20;
    if ((param_1[iVar3] == '/') || (param_1[iVar3] == '\\')) break;
  }
  if (param_1[iVar3] == '.') {
LAB_0804ff20:
    iVar3 = iVar3 + -1;
  }
  else {
    iVar3 = uVar2 - 2;
  }
  iVar4 = uVar2 - 2;
  if (iVar4 < 0) {
LAB_0804ff3f:
    if ((param_1[iVar4] != '/') && (param_1[iVar4] != '\\')) {
      iVar4 = 0;
      goto LAB_0804ff51;
    }
  }
  else if (param_1[iVar4] != '/') {
    do {
      if ((param_1[iVar4] == '\\') || (iVar4 = iVar4 + -1, iVar4 < 0)) break;
    } while (param_1[iVar4] != '/');
    goto LAB_0804ff3f;
  }
  iVar4 = iVar4 + 1;
LAB_0804ff51:
  __n = (iVar3 - iVar4) + 1;
  strncpy(param_2,param_1 + iVar4,__n);
  param_2[__n] = '\0';
  return;
}


// COM_FileExtension  @ 0804fe70
undefined * COM_FileExtension(char *param_1)

{
  int iVar1;
  
  if (*param_1 != '\0') {
    do {
      if (*param_1 == '.') break;
      param_1 = param_1 + 1;
    } while (*param_1 != '\0');
    if (*param_1 != '\0') {
      iVar1 = 0;
      do {
        param_1 = param_1 + 1;
        if (*param_1 == '\0') break;
        (&exten_284)[iVar1] = *param_1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 7);
      (&exten_284)[iVar1] = 0;
      return &exten_284;
    }
  }
  return &DAT_0809ebf8;
}


// COM_FileSeek  @ 08051870
void COM_FileSeek(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  Sys_FileSeek(param_3,param_1 + param_4);
  return;
}


// COM_FileSize  @ 08050d00
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


// COM_FileTell  @ 08051890
int COM_FileTell(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = Sys_FileTell(param_3);
  return iVar1 - param_1;
}


// COM_FindFile  @ 08050840
void COM_FindFile(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  COM_FindFileSearch(0,0,param_1,param_2,param_3);
  return;
}


// COM_FindFileSearch  @ 08050430
undefined4
COM_FindFileSearch(int *param_1,char *param_2,char *param_3,undefined4 *param_4,int *param_5)

{
  char cVar1;
  char *__filename;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  FILE *pFVar6;
  char *pcVar7;
  char *pcVar8;
  int local_10c;
  char local_108 [260];
  
  local_10c = -1;
  bVar4 = false;
  if (param_5 == (int *)0x0) {
LAB_0805046f:
    if (param_4 == (undefined4 *)0x0) {
      Sys_Error("COM_FindFile: neither phFile or file set");
    }
  }
  else {
    if (param_4 != (undefined4 *)0x0) {
      Sys_Error("COM_FindFile: both phFile and file set");
    }
    if (param_5 == (int *)0x0) goto LAB_0805046f;
  }
  pcVar8 = com_searchpaths;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (com_searchpaths == (char *)0x0) goto joined_r0x080507f3;
    do {
      if (pcVar8 == (char *)*param_1) break;
      pcVar8 = *(char **)(pcVar8 + 0x214);
    } while (pcVar8 != (char *)0x0);
    if (pcVar8 == (char *)0x0) goto joined_r0x080507f3;
    pcVar8 = *(char **)(pcVar8 + 0x214);
    if (pcVar8 == (char *)0x0) {
LAB_0805050b:
      if (param_4 != (undefined4 *)0x0) {
        param_4[2] = 0xffffffff;
        com_filesize = 0xffffffff;
        return 0xffffffff;
      }
      *param_5 = 0;
      com_filesize = 0xffffffff;
      return 0xffffffff;
    }
    do {
      iVar5 = strcasecmp(pcVar8 + 0x104,(char *)(*param_1 + 0x104));
      if (iVar5 != 0) break;
      pcVar8 = *(char **)(pcVar8 + 0x214);
    } while (pcVar8 != (char *)0x0);
    if (pcVar8 == (char *)0x0) goto LAB_0805050b;
  }
  if (param_2 == (char *)0x0) {
LAB_080507ce:
    while ((pcVar8 != (char *)0x0 &&
           ((!bVar4 || (iVar5 = strcasecmp(param_2,pcVar8 + 0x104), iVar5 == 0))))) {
      iVar5 = -1;
      pcVar7 = pcVar8;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (iVar5 != -2) {
        sprintf(local_108,"%s/%s",pcVar8,param_3);
        ftLastFile = Sys_FileTime(local_108);
        if (0 < ftLastFile) {
          com_filesize = Sys_FileOpenRead(local_108,&local_10c);
          if (param_4 == (undefined4 *)0x0) {
            Sys_FileClose(local_10c);
            pFVar6 = fopen(local_108,"rb");
            *param_5 = (int)pFVar6;
          }
          else {
            param_4[2] = local_10c;
            *param_4 = 0;
          }
          if (param_1 != (int *)0x0) {
            *param_1 = (int)pcVar8;
            return com_filesize;
          }
          return com_filesize;
        }
      }
      if (*(int *)(pcVar8 + 0x208) != 0) {
        pcVar7 = param_3;
        if ((*param_3 != '\0') && ((*param_3 == '\\' || (*param_3 == '/')))) {
          pcVar7 = param_3 + 1;
        }
        __filename = *(char **)(pcVar8 + 0x208);
        for (local_10c = 0; local_10c < *(int *)(__filename + 0x108); local_10c = local_10c + 1) {
          iVar5 = Q_FileNameCmp(local_10c * 0x40 + *(int *)(__filename + 0x10c),pcVar7);
          if (iVar5 == 0) {
            Sys_Printf("PackFile: %s : %s\n",__filename,pcVar7);
            if (param_4 == (undefined4 *)0x0) {
              ftLastFile = *(int *)(pcVar8 + 0x20c);
              pFVar6 = fopen(__filename,"rb");
              *param_5 = (int)pFVar6;
              setvbuf(pFVar6,(char *)0x0,0,0x4000);
              if (*param_5 != 0) {
                fseek((FILE *)*param_5,
                      *(long *)(*(int *)(__filename + 0x10c) + 0x38 + local_10c * 0x40),0);
              }
            }
            else {
              uVar2 = *(undefined4 *)(__filename + 0x104);
              param_4[2] = uVar2;
              uVar3 = *(undefined4 *)(*(int *)(__filename + 0x10c) + 0x38 + local_10c * 0x40);
              *param_4 = uVar3;
              param_4[1] = *(undefined4 *)(*(int *)(__filename + 0x10c) + 0x3c + local_10c * 0x40);
              Sys_FileSeek(uVar2,uVar3);
            }
            com_filesize = *(undefined4 *)(*(int *)(__filename + 0x10c) + 0x3c + local_10c * 0x40);
            if (param_1 != (int *)0x0) {
              *param_1 = (int)pcVar8;
              return com_filesize;
            }
            return com_filesize;
          }
        }
      }
      pcVar8 = *(char **)(pcVar8 + 0x214);
    }
  }
  else {
    bVar4 = true;
    if (pcVar8 != (char *)0x0) {
      do {
        iVar5 = strcasecmp(param_2,pcVar8 + 0x104);
        if (iVar5 == 0) break;
        pcVar8 = *(char **)(pcVar8 + 0x214);
      } while (pcVar8 != (char *)0x0);
      goto LAB_080507ce;
    }
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '*')) {
    Sys_Printf("FindFile: can\'t find %s\n",param_3);
  }
joined_r0x080507f3:
  if (param_4 == (undefined4 *)0x0) {
    *param_5 = 0;
  }
  else {
    param_4[2] = 0xffffffff;
  }
  com_filesize = 0xffffffff;
  return 0xffffffff;
}


// COM_FixSlashes  @ 08050970
void COM_FixSlashes(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    if (*param_1 == '\\') {
      *param_1 = '/';
    }
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return;
}


// COM_FreeFile  @ 08050f30
void COM_FreeFile(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  return;
}


// COM_FreeSearchPath  @ 08051320
void COM_FreeSearchPath(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(int *)((int)param_1 + 0x208) != 0) {
      Sys_FileClose(*(undefined4 *)(*(int *)((int)param_1 + 0x208) + 0x104));
      if (*(int *)(*(int *)((int)param_1 + 0x208) + 0x10c) != 0) {
        free(*(void **)(*(int *)((int)param_1 + 0x208) + 0x10c));
      }
      free(*(void **)((int)param_1 + 0x208));
    }
    free(param_1);
  }
  return;
}


// COM_GetGameDir  @ 08052b40
void COM_GetGameDir(char *param_1)

{
  if (param_1 != (char *)0x0) {
    strcpy(param_1,com_gamedir);
  }
  return;
}


// COM_GetShortName  @ 08053180
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * COM_GetShortName(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  _szReturnName_411 = 0;
  _DAT_080b4e28 = 0;
  DAT_080b4e2c = 0;
  iVar3 = -1;
  pcVar4 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    pcVar4 = &szReturnName_411;
    iVar3 = 0;
    cVar1 = *param_1;
    while ((cVar1 != '\0' && (iVar3 < 8))) {
      iVar2 = isalpha((int)*param_1);
      if (iVar2 != 0) {
        *pcVar4 = *param_1;
        pcVar4 = pcVar4 + 1;
        iVar3 = iVar3 + 1;
      }
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    }
    *pcVar4 = '\0';
    iVar3 = -1;
    pcVar4 = &szReturnName_411;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar3 != -2) {
      return &szReturnName_411;
    }
  }
  return "Noname";
}


// COM_HexConvert  @ 0804e250
void COM_HexConvert(int param_1,int param_2,byte *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_2) {
    do {
      cVar1 = COM_Nibble((int)*(char *)(param_1 + iVar3));
      bVar2 = COM_Nibble((int)((char *)(param_1 + iVar3))[1]);
      *param_3 = cVar1 << 4 | bVar2;
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 2;
    } while (iVar3 < param_2);
  }
  return;
}


// COM_Init  @ 080502a0
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
  Cvar_RegisterVariable(registered);
  Cvar_RegisterVariable(cmdline);
  Cmd_AddCommand(&DAT_0809ed54,COM_Path_f);
  COM_BitOpsInit();
  COM_InitFilesystem();
  COM_CheckRegistered();
  return;
}


// COM_InitArgv  @ 08050150
void COM_InitArgv(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0;
  do {
    if ((param_1 <= iVar5) || (iVar3 = 0, 0xfe < iVar4)) break;
    do {
      iVar1 = *(int *)(param_2 + iVar5 * 4);
      if (*(char *)(iVar3 + iVar1) == '\0') break;
      (&com_cmdline)[iVar4] = *(undefined1 *)(iVar3 + iVar1);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xff);
    if (0xfe < iVar4) break;
    (&com_cmdline)[iVar4] = 0x20;
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x32);
  (&com_cmdline)[iVar4] = 0;
  bVar2 = false;
  com_argc = 0;
  do {
    iVar4 = com_argc;
    if (param_1 <= com_argc) break;
    (&largv)[com_argc] = *(undefined4 *)(param_2 + com_argc * 4);
    iVar4 = Q_strcmp("-safe",*(undefined4 *)(param_2 + iVar4 * 4));
    if (iVar4 == 0) {
      bVar2 = true;
    }
    com_argc = com_argc + 1;
  } while (com_argc < 0x32);
  if (bVar2) {
    iVar4 = 0;
    do {
      (&largv)[com_argc] = (&safeargvs)[iVar4];
      com_argc = com_argc + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 7);
  }
  (&largv)[com_argc] = argvdummy;
  com_argv = &largv;
  iVar4 = COM_CheckParm("-rogue");
  if (iVar4 != 0) {
    rogue = 1;
    standard_quake = 0;
  }
  iVar4 = COM_CheckParm("-hipnotic");
  if (iVar4 != 0) {
    hipnotic = 1;
    standard_quake = 0;
  }
  return;
}


// COM_InitFilesystem  @ 080515e0
void COM_InitFilesystem(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  undefined4 local_10c;
  char local_108 [260];
  
  iVar2 = COM_CheckParm("-basedir");
  pcVar3 = host_parms;
  if ((iVar2 != 0) && (iVar2 < com_argc + -1)) {
    pcVar3 = *(char **)(com_argv + 4 + iVar2 * 4);
  }
  strcpy(local_108,pcVar3);
  uVar5 = 0xffffffff;
  pcVar3 = local_108;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  if ((0 < (int)(uVar5 - 1)) && ((local_108[uVar5 - 2] == '\\' || (local_108[uVar5 - 2] == '/')))) {
    local_108[uVar5 - 2] = '\0';
  }
  iVar2 = COM_CheckParm("-cachedir");
  if ((iVar2 == 0) || (com_argc + -1 <= iVar2)) {
    pcVar3 = DAT_080cc320;
    if (DAT_080cc320 == (char *)0x0) goto LAB_080516c0;
  }
  else {
    if (**(char **)(com_argv + 4 + iVar2 * 4) == '-') {
LAB_080516c0:
      com_cachedir[0] = 0;
      goto LAB_080516c7;
    }
    pcVar3 = *(char **)(com_argv + 4 + iVar2 * 4);
  }
  strcpy(com_cachedir,pcVar3);
LAB_080516c7:
  COM_AddGameDirectory(1,local_108,"valve");
  iVar2 = COM_CheckParm("-game");
  if ((iVar2 != 0) && (iVar2 < com_argc + -1)) {
    com_modified = 1;
    COM_AddGameDirectory(0,local_108,*(undefined4 *)(com_argv + 4 + iVar2 * 4));
  }
  iVar2 = COM_CheckParm("-path");
  if (iVar2 != 0) {
    com_modified = 1;
    com_searchpaths = (char *)0x0;
    while ((((iVar2 = iVar2 + 1, iVar2 < com_argc && (*(int *)(com_argv + iVar2 * 4) != 0)) &&
            (pcVar3 = *(char **)(com_argv + iVar2 * 4), *pcVar3 != '+')) && (*pcVar3 != '-'))) {
      local_10c = malloc(0x218);
      pcVar3 = local_10c;
      for (iVar6 = 0x86; iVar6 != 0; iVar6 = iVar6 + -1) {
        pcVar3[0] = '\0';
        pcVar3[1] = '\0';
        pcVar3[2] = '\0';
        pcVar3[3] = '\0';
        pcVar3 = pcVar3 + 4;
      }
      pbVar4 = (byte *)COM_FileExtension(*(undefined4 *)(com_argv + iVar2 * 4));
      iVar6 = 4;
      bVar8 = false;
      uVar5 = 0;
      bVar9 = true;
      pbVar7 = &DAT_0809efe9;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar8 = *pbVar4 < *pbVar7;
        bVar9 = *pbVar4 == *pbVar7;
        pbVar4 = pbVar4 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar9) {
        uVar5 = -(uint)bVar8 | 1;
      }
      if (uVar5 == 0) {
        iVar6 = COM_LoadPackFile(*(undefined4 *)(com_argv + iVar2 * 4));
        *(int *)(local_10c + 0x208) = iVar6;
        if (iVar6 == 0) {
          Sys_Error("Couldn\'t load packfile: %s",*(undefined4 *)(com_argv + iVar2 * 4));
        }
      }
      else {
        strcpy(local_10c,*(char **)(com_argv + iVar2 * 4));
      }
      *(char **)(local_10c + 0x214) = com_searchpaths;
      com_searchpaths = local_10c;
    }
  }
  iVar2 = COM_CheckParm("-proghack");
  if (iVar2 != 0) {
    proghack = 1;
  }
  return;
}


// COM_ListMaps  @ 080518b0
void COM_ListMaps(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  size_t local_1c8;
  char local_1c4 [64];
  undefined1 local_184 [128];
  char local_104 [128];
  char local_84 [128];
  
  local_1c8 = 0;
  iVar6 = com_searchpaths;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    uVar7 = 0xffffffff;
    pcVar4 = param_1;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    local_1c8 = ~uVar7 - 1;
  }
  do {
    if (iVar6 == 0) {
      return;
    }
    Con_Printf("\nDir:  %s\n",iVar6 + 0x104);
    Con_Printf("-------------\n");
    if (*(int *)(iVar6 + 0x208) == 0) {
      sprintf(local_1c4,"%s/maps/*.bsp",iVar6 + 0x104);
      pcVar4 = (char *)Sys_FindFirst(local_1c4,0);
      while (pcVar4 != (char *)0x0) {
        if ((local_1c8 == 0) || (iVar5 = strncasecmp(pcVar4,param_1,local_1c8), iVar5 == 0)) {
          Con_Printf("(fs) %s\n",pcVar4);
        }
        pcVar4 = (char *)Sys_FindNext(0);
      }
      Sys_FindClose();
    }
    else {
      iVar5 = *(int *)(iVar6 + 0x208);
      iVar8 = 0;
      if (0 < *(int *)(iVar5 + 0x108)) {
        do {
          iVar2 = iVar8 * 0x40;
          iVar3 = strncasecmp("maps/",(char *)(iVar2 + *(int *)(iVar5 + 0x10c)),4);
          if (iVar3 == 0) {
            gcc2_compiled_(iVar2 + *(int *)(iVar5 + 0x10c),0,local_184,local_104,local_84);
            iVar3 = strcasecmp(local_84,".bsp");
            if (iVar3 == 0) {
              if (local_1c8 == 0) {
                iVar2 = iVar8 << 6;
              }
              else {
                iVar3 = strncasecmp(local_104,param_1,local_1c8);
                if (iVar3 != 0) goto LAB_08051a0c;
              }
              Con_Printf("(pak) %s\n",iVar2 + *(int *)(iVar5 + 0x10c) + 5);
            }
          }
LAB_08051a0c:
          iVar8 = iVar8 + 1;
        } while (iVar8 < *(int *)(iVar5 + 0x108));
      }
    }
    iVar6 = *(int *)(iVar6 + 0x214);
  } while( true );
}


// COM_LoadCacheFile  @ 08051140
void COM_LoadCacheFile(undefined4 param_1,undefined4 param_2)

{
  loadcache = param_2;
  COM_LoadFile(param_1,3,0);
  return;
}


// COM_LoadFile  @ 08050d90
void * COM_LoadFile(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined1 local_30 [32];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  pvVar2 = (void *)0x0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  iVar1 = COM_OpenFile(param_1,&local_10);
  if (local_8 == -1) {
    pvVar2 = (void *)0x0;
  }
  else {
    COM_FileBase(param_1,local_30);
    if (param_2 == 1) {
      pvVar2 = (void *)Hunk_AllocName(iVar1 + 1,local_30);
    }
    else if (param_2 == 2) {
      pvVar2 = (void *)Hunk_TempAlloc(iVar1 + 1);
    }
    else if (param_2 == 0) {
      pvVar2 = (void *)Z_Malloc(iVar1 + 1);
    }
    else if (param_2 == 3) {
      pvVar2 = (void *)Cache_Alloc(loadcache,iVar1 + 1,local_30);
    }
    else if (param_2 == 4) {
      pvVar2 = loadbuf;
      if (loadsize < iVar1 + 1) {
        pvVar2 = (void *)Hunk_TempAlloc(iVar1 + 1);
      }
    }
    else if (param_2 == 5) {
      pvVar2 = malloc(iVar1 + 1);
    }
    else {
      Sys_Error("COM_LoadFile: bad usehunk");
    }
    if (pvVar2 == (void *)0x0) {
      Sys_Error("COM_LoadFile: not enough space for %s",param_1);
      COM_CloseFile(local_10,local_c,local_8);
      pvVar2 = (void *)0x0;
    }
    else {
      *(undefined1 *)(iVar1 + (int)pvVar2) = 0;
      Sys_FileRead(local_8,pvVar2,iVar1);
      COM_CloseFile(local_10,local_c,local_8);
      if (param_3 != (int *)0x0) {
        *param_3 = iVar1;
      }
    }
  }
  return pvVar2;
}


// COM_LoadFileForMe  @ 08052a90
void COM_LoadFileForMe(undefined4 param_1,undefined4 param_2)

{
  COM_LoadFile(param_1,5,param_2);
  return;
}


// COM_LoadFileLimit  @ 08050fe0
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
    local_8 = param_5[2];
    local_c = iVar1;
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
        Sys_Error("COM_LoadFileLimit: not enough space for %s",param_1);
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


// COM_LoadHunkFile  @ 08051100
void COM_LoadHunkFile(undefined4 param_1)

{
  COM_LoadFile(param_1,1,0);
  return;
}


// COM_LoadPackFile  @ 08051190
char * COM_LoadPackFile(char *param_1)

{
  int iVar1;
  char *__dest;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = Sys_FileOpenRead(param_1,&local_14);
  if (iVar1 == -1) {
    __dest = (char *)0x0;
  }
  else {
    Sys_FileRead(local_14,&local_10,0xc);
    if (local_10 != 0x4b434150) {
      Sys_Error("%s is not a packfile",param_1);
    }
    local_c = (*LittleLong)(local_c);
    local_8 = (*LittleLong)(local_8);
    uVar2 = local_8 >> 6;
    if (0x1000 < uVar2) {
      Sys_Error("%s has %i files",param_1,uVar2);
    }
    if (uVar2 != 0x153) {
      com_modified = 1;
    }
    pvVar3 = malloc(uVar2 << 6);
    Sys_FileSeek(local_14,local_c);
    Sys_FileRead(local_14,pvVar3,local_8);
    CRC32_Init(&local_18);
    CRC32_ProcessBuffer(&local_18,pvVar3,local_8);
    if (local_18 != 0x80d5) {
      com_modified = 1;
    }
    if (uVar2 != 0) {
      iVar1 = 0;
      do {
        iVar5 = iVar1 * 0x40;
        uVar4 = (*LittleLong)(*(undefined4 *)((int)pvVar3 + iVar5 + 0x38));
        *(undefined4 *)((int)pvVar3 + iVar5 + 0x38) = uVar4;
        uVar4 = (*LittleLong)(*(undefined4 *)((int)pvVar3 + iVar5 + 0x3c));
        *(undefined4 *)((int)pvVar3 + iVar5 + 0x3c) = uVar4;
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)uVar2);
    }
    __dest = malloc(0x110);
    strcpy(__dest,param_1);
    *(undefined4 *)(__dest + 0x104) = local_14;
    *(uint *)(__dest + 0x108) = uVar2;
    *(void **)(__dest + 0x10c) = pvVar3;
    Con_Printf("Added packfile %s (%i files)\n",param_1,uVar2);
  }
  return __dest;
}


// COM_LoadStackFile  @ 08051160
void COM_LoadStackFile(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  loadbuf = param_2;
  loadsize = param_3;
  COM_LoadFile(param_1,4,0);
  return;
}


// COM_LoadTempFile  @ 08051120
void COM_LoadTempFile(undefined4 param_1,undefined4 param_2)

{
  COM_LoadFile(param_1,2,param_2);
  return;
}


// COM_Log  @ 08052730
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


// COM_MultipleCloseFile  @ 08050c30
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
      goto LAB_08050c86;
    }
    Sys_FileClose(*(undefined4 *)(*(int *)(param_1 + 4) + 8));
LAB_08050c86:
    param_1 = *(int *)(param_1 + 0x10c);
  } while( true );
}


// COM_MultipleOpenFile  @ 08050b50
int COM_MultipleOpenFile(undefined4 param_1,int *param_2)

{
  undefined4 *__ptr;
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
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
      __ptr = malloc(0xc);
      *__ptr = 0;
      __ptr[1] = 0;
      __ptr[2] = 0;
      iVar1 = COM_FindFileSearch(&local_8,0,param_1,__ptr,0);
      if (iVar1 == -1) break;
      piVar2 = malloc(0x110);
      piVar4 = piVar2;
      for (iVar3 = 0x44; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
      }
      *piVar2 = iVar1;
      piVar2[1] = (int)__ptr;
      strcpy((char *)(piVar2 + 2),(char *)(local_8 + 0x104));
      piVar2[0x43] = *param_2;
      *param_2 = (int)piVar2;
      local_10 = local_10 + 1;
    }
    free(__ptr);
  }
  return local_10;
}


// COM_Nibble  @ 0804e210
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


// COM_OpenFile  @ 08050cc0
void COM_OpenFile(undefined4 param_1,undefined4 param_2)

{
  COM_FindFileSearch(0,0,param_1,param_2,0);
  return;
}


// COM_OpenFileInDir  @ 08050ca0
void COM_OpenFileInDir(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  COM_FindFileSearch(0,param_1,param_2,param_3,0);
  return;
}


// COM_Parse  @ 0804ffc0
char * COM_Parse(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  com_token = '\0';
  if (param_1 == (char *)0x0) {
LAB_0804ffd4:
    param_1 = (char *)0x0;
  }
  else {
    while( true ) {
      for (; cVar1 = *param_1, cVar1 < '!'; param_1 = param_1 + 1) {
        if (cVar1 == '\0') goto LAB_0804ffd4;
      }
      if ((cVar1 != '/') || (param_1[1] != '/')) break;
      for (; (*param_1 != '\0' && (*param_1 != '\n')); param_1 = param_1 + 1) {
      }
    }
    if (cVar1 == '\"') {
      param_1 = param_1 + 1;
      while( true ) {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        if ((cVar1 == '\"') || (cVar1 == '\0')) break;
        (&com_token)[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      }
      (&com_token)[iVar2] = 0;
    }
    else if (((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
             ((cVar1 == '(' || (cVar1 == '\'')))) || ((com_ignorecolons == 0 && (cVar1 == ':')))) {
      DAT_080c91c1 = 0;
      param_1 = param_1 + 1;
      com_token = cVar1;
    }
    else {
      while( true ) {
        iVar3 = iVar2;
        (&com_token)[iVar3] = cVar1;
        param_1 = param_1 + 1;
        cVar1 = *param_1;
        if ((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
           ((cVar1 == '(' || (cVar1 == '\'')))) break;
        if (((com_ignorecolons == 0) && (cVar1 == ':')) || (iVar2 = iVar3 + 1, cVar1 < '!')) break;
      }
      (&DAT_080c91c1)[iVar3] = 0;
    }
  }
  return param_1;
}


// COM_Path_f  @ 08050860
void COM_Path_f(void)

{
  int iVar1;
  
  Con_Printf("Current search path:\n");
  for (iVar1 = com_searchpaths; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x214)) {
    if (*(int *)(iVar1 + 0x210) != 0) {
      Con_Printf(&DAT_0809ee34);
    }
    if (*(int *)(iVar1 + 0x208) == 0) {
      Con_Printf(&DAT_0809ee48,iVar1);
    }
    else {
      Con_Printf("%s (%i files)\n",*(undefined4 *)(iVar1 + 0x208),
                 *(undefined4 *)(*(int *)(iVar1 + 0x208) + 0x108));
    }
  }
  return;
}


// COM_Shutdown  @ 08051390
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


// COM_SkipPath  @ 0804fe10
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


// COM_StripExtension  @ 0804fe40
void COM_StripExtension(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while ((cVar1 != '\0' && (*param_1 != '.'))) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    cVar1 = *param_1;
  }
  *param_2 = '\0';
  return;
}


// COM_WriteFile  @ 080508e0
void COM_WriteFile(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char local_108 [260];
  
  sprintf(local_108,"%s/%s",com_gamedir,param_1);
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


