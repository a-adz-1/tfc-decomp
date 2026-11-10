// COM_AddAppDirectory  @ 0005a62c
void COM_AddAppDirectory(undefined4 param_1)

{
  FS_AddSearchPath(param_1,"PLATFORM");
  return;
}


// COM_AddDefaultDir  @ 0005a660
void COM_AddDefaultDir(char *param_1)

{
  undefined1 *puVar1;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    if (com_gamedir == '\0') {
      puVar1 = (undefined1 *)0x0;
    }
    else {
      puVar1 = &com_gamedir;
    }
    FileSystem_SetGameDirectory(param_1,puVar1);
  }
  return;
}


// COM_BinPrintf  @ 00056ff4
undefined1 * COM_BinPrintf(int param_1,int param_2)

{
  size_t sVar1;
  int local_18;
  char local_14 [15];
  byte local_5;
  
  Q_memset(szReturn_72,0,0x1000);
  for (local_18 = 0; local_18 < param_2; local_18 = local_18 + 1) {
    local_5 = *(byte *)(param_1 + local_18);
    snprintf(local_14,10,"%02x",(uint)local_5);
    sVar1 = strlen(szReturn_72);
    strncat(szReturn_72,local_14,0xfff - sVar1);
  }
  return szReturn_72;
}


// COM_BitOpsInit  @ 000576b0
void COM_BitOpsInit(void)

{
  Q_memset(&bfwrite,0,0xc);
  Q_memset(&bfread,0,0x18);
  return;
}


// COM_BlockSequenceCRCByte  @ 0005cf24
undefined1 COM_BlockSequenceCRCByte(undefined4 param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 auStack_4c [64];
  undefined *puStack_c;
  undefined4 uStack_8;
  
  if ((int)param_3 < 0) {
    Sys_Error("sequence < 0, in COM_BlockSequenceCRCByte\n");
  }
  puStack_c = &pulCRCTable + param_3 % 0x3fc;
  if (0x3c < param_2) {
    param_2 = 0x3c;
  }
  Q_memcpy(auStack_4c,param_1,param_2);
  auStack_4c[param_2] = *puStack_c;
  auStack_4c[param_2 + 1] = puStack_c[1];
  auStack_4c[param_2 + 2] = puStack_c[2];
  auStack_4c[param_2 + 3] = puStack_c[3];
  CRC32_Init(&uStack_8);
  CRC32_ProcessBuffer(&uStack_8,auStack_4c,param_2 + 4);
  uVar1 = CRC32_Final(uStack_8);
  return uVar1;
}


// COM_BuildNumber__Fv  @ 000975d8
undefined4 COM_BuildNumber__Fv(void)

{
  undefined4 uVar1;
  
  uVar1 = build_number();
  return uVar1;
}


// COM_CheckAuthenticationType  @ 0005ad40
void COM_CheckAuthenticationType(void)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  undefined1 local_80c [4];
  undefined1 local_808 [2048];
  int local_8;
  
  iVar1 = COM_CheckParm("-steam");
  if (iVar1 == 0) {
    if ((crypt._56_4_ == 0) || (crypt._60_4_ == 0)) {
      gfUseLANAuthentication = 1;
    }
    else if (noip == 0) {
      lVar2 = (longdouble)Sys_FloatTime();
      local_8 = (*(code *)crypt._56_4_)(local_808,local_80c);
      if (local_8 != 2) {
        Con_Printf("Trying to authenticate with WON servers\n");
        iVar1 = (*(code *)crypt._60_4_)();
        if (iVar1 == 0) {
          gfUseLANAuthentication = 1;
          return;
        }
        iVar1 = (*(code *)crypt._56_4_)(local_808,local_80c);
        if (iVar1 != 2) {
          gfUseLANAuthentication = 1;
          return;
        }
        Con_Printf("WON Authentication successful\n");
      }
      gfUseLANAuthentication = 0;
      lVar3 = (longdouble)Sys_FloatTime();
      DAT_002fd36c = (double)((float)DAT_002fd36c + ((float)lVar3 - (float)lVar2));
    }
    else {
      gfUseLANAuthentication = 1;
    }
  }
  else {
    gfUseLANAuthentication = 1;
  }
  return;
}


// COM_CheckParm  @ 00059828
int COM_CheckParm(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 1;
  while( true ) {
    if (com_argc <= local_8) {
      return 0;
    }
    if ((*(int *)(com_argv + local_8 * 4) != 0) &&
       (iVar1 = Q_strcmp(param_1,*(undefined4 *)(com_argv + local_8 * 4)), iVar1 == 0)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


// COM_CheckPrintMap  @ 0005a890
void COM_CheckPrintMap(int *param_1,undefined4 param_2,int param_3)

{
  if (*param_1 == 0x1e) {
    if (param_3 == 0) {
      Con_Printf(&DAT_000dfd8d,param_2);
    }
  }
  else if (param_3 != 0) {
    Con_Printf("OUTDATED:  %s\n",param_2);
  }
  return;
}


// COM_ClearCustomizationList  @ 00056084
void COM_ClearCustomizationList(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_18;
  int local_10;
  int *local_c;
  
  local_c = *(int **)(param_1 + 0xa0);
  while (local_c != (int *)0x0) {
    piVar1 = (int *)local_c[0x28];
    if ((*local_c != 0) && (local_c[0x27] != 0)) {
      Mem_Free(local_c[0x27]);
    }
    if ((*local_c != 0) && (local_c[0x26] != 0)) {
      if (local_c[0x11] == 3) {
        if ((param_2 != 0) && (cls == 5)) {
          R_DecalRemoveAll(-(*(byte *)((int)local_c + 0x61) + 1));
        }
        puVar2 = (undefined4 *)local_c[0x26];
        Mem_Free(puVar2[4]);
        local_18 = puVar2[1];
        for (local_10 = 0; local_10 < (int)puVar2[2]; local_10 = local_10 + 1) {
          iVar3 = Cache_Check(local_18 + 0x40);
          if (iVar3 != 0) {
            Cache_Free(local_18 + 0x40);
          }
          local_18 = local_18 + 0x44;
        }
        Mem_Free(*puVar2);
        Mem_Free(puVar2[1]);
      }
      Mem_Free(local_c[0x26]);
    }
    Mem_Free(local_c);
    local_c = piVar1;
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return;
}


// COM_CompareFileTime  @ 0005ac64
undefined4 COM_CompareFileTime(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  *param_3 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = FS_GetFileTime(param_1);
    iVar2 = FS_GetFileTime(param_2);
    if (iVar1 < iVar2) {
      *param_3 = 0xffffffff;
    }
    else if (iVar2 < iVar1) {
      *param_3 = 1;
    }
    local_8 = 1;
  }
  return local_8;
}


// COM_CopyFile  @ 00059ec4
void COM_CopyFile(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_1014 [4096];
  uint local_14;
  uint local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = FS_Open(param_1,&DAT_000e017e);
  if (local_8 != 0) {
    local_10 = FS_Size(local_8);
    COM_CreatePath(param_2);
    local_c = FS_Open(param_2,&DAT_000e014b);
    for (; local_10 != 0; local_10 = local_10 - local_14) {
      if (local_10 < 0x1000) {
        local_14 = local_10;
      }
      else {
        local_14 = 0x1000;
      }
      FS_Read(local_1014,local_14,1,local_8);
      FS_Write(local_1014,local_14,1,local_c);
    }
    FS_Close(local_8);
    FS_Close(local_c);
  }
  return;
}


// COM_CopyFileChunk  @ 0005a314
void COM_CopyFileChunk(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 local_408 [1024];
  int local_8;
  
  for (local_8 = param_3; 0x400 < local_8; local_8 = local_8 + -0x400) {
    FS_Read(local_408,0x400,1,param_2);
    FS_Write(local_408,0x400,1,param_1);
  }
  FS_Read(local_408,local_8,1,param_2);
  FS_Write(local_408,local_8,1,param_1);
  FS_Flush(param_2);
  FS_Flush(param_1);
  return;
}


// COM_CreateCustomization  @ 00056214
bool COM_CreateCustomization
               (int param_1,undefined4 *param_2,undefined4 param_3,uint param_4,undefined4 *param_5,
               undefined4 *param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  bVar6 = false;
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
    bVar6 = true;
  }
  else {
    *puVar1 = 1;
    if ((param_4 & 1) == 0) {
      uVar2 = COM_LoadFile(param_2,5,0);
      puVar1[0x27] = uVar2;
    }
    else {
      iVar3 = HPAK_GetDataPointer("custom.hpk",param_2,puVar1 + 0x27,0);
      if (iVar3 == 0) {
        bVar6 = true;
        goto LAB_0005648c;
      }
    }
    if (((*(byte *)(puVar1 + 0x14) & 4) != 0) && (puVar1[0x11] == 3)) {
      *(undefined1 *)((int)puVar1 + 0x61) = (undefined1)param_3;
      iVar3 = CustomDecal_Validate(puVar1[0x27],param_2[0x12]);
      if (iVar3 == 0) {
        bVar6 = true;
      }
      else if ((param_4 & 4) == 0) {
        uVar2 = Mem_ZeroMalloc(0x2c);
        puVar1[0x26] = uVar2;
        puVar5 = (undefined4 *)puVar1[0x26];
        if (((int)param_2[0x12] < 0x400) || (0x4000 < (int)param_2[0x12])) {
          bVar6 = true;
        }
        else {
          iVar3 = CustomDecal_Init(puVar5,puVar1[0x27],param_2[0x12],param_3);
          bVar6 = iVar3 == 0;
          if (!bVar6) {
            if ((int)puVar5[5] < 1) {
              bVar6 = true;
            }
            else {
              if (param_6 != (undefined4 *)0x0) {
                *param_6 = puVar5[5];
              }
              puVar1[0x23] = 1;
              puVar1[0x24] = 0;
              puVar1[0x25] = puVar5[5];
              if ((param_4 & 2) != 0) {
                Mem_Free(*puVar5);
                Mem_Free(puVar5[1]);
                Mem_Free(puVar5[4]);
                Mem_Free(puVar1[0x26]);
                puVar1[0x26] = 0;
              }
            }
          }
        }
      }
    }
  }
LAB_0005648c:
  if (bVar6) {
    if (puVar1[0x27] != 0) {
      Mem_Free(puVar1[0x27]);
    }
    if (puVar1[0x26] != 0) {
      Mem_Free(puVar1[0x26]);
    }
    Mem_Free(puVar1);
  }
  else {
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = puVar1;
    }
    puVar1[0x28] = *(undefined4 *)(param_1 + 0xa0);
    *(undefined4 **)(param_1 + 0xa0) = puVar1;
  }
  return !bVar6;
}


// COM_CreatePath  @ 00059e54
void COM_CreatePath(char *param_1)

{
  char cVar1;
  char *local_8;
  
  local_8 = param_1;
  while (local_8 = local_8 + 1, *local_8 != '\0') {
    if ((*local_8 == '/') || (*local_8 == '\\')) {
      cVar1 = *local_8;
      *local_8 = '\0';
      FS_CreateDirHierarchy(param_1,0);
      *local_8 = cVar1;
    }
  }
  return;
}


// COM_DefaultExtension  @ 000593e8
void COM_DefaultExtension(char *param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  char *local_8;
  
  iVar1 = Q_strlen(param_1);
  local_8 = param_1 + iVar1;
  while ((local_8 = local_8 + -1, *local_8 != '/' && (local_8 != param_1))) {
    if (*local_8 == '.') {
      return;
    }
  }
  sVar2 = strlen(local_8);
  strncat(param_1,param_2,0x104 - sVar2);
  return;
}


// COM_EntsForPlayerSlots  @ 0005aeec
int COM_EntsForPlayerSlots(int param_1)

{
  return (param_1 + -1) * 0xf + 900;
}


// COM_ExpandFilename  @ 00059fcc
bool COM_ExpandFilename(char *param_1)

{
  size_t sVar1;
  char local_108 [260];
  
  FS_GetLocalPath(param_1,local_108,0x104,0x59fdb);
  strcpy(param_1,local_108);
  sVar1 = strlen(param_1);
  return sVar1 != 0;
}


// COM_ExplainDisconnection  @ 000570b8
void COM_ExplainDisconnection(int param_1,char *param_2)

{
  vsnprintf(string_76,0x400,param_2,&stack0x0000000c);
  Q_strncpy(&gszDisconnectReason,string_76,0xff);
  DAT_0036a8ff = 0;
  gfExtendedError = 1;
  if ((param_1 != 0) && (gszDisconnectReason != '#')) {
    Con_Printf(&DAT_000dfd8d,&gszDisconnectReason);
  }
  return;
}


// COM_ExtendedExplainDisconnection  @ 00057160
void COM_ExtendedExplainDisconnection(int param_1,char *param_2)

{
  vsnprintf(string_80,0x400,param_2,&stack0x0000000c);
  Q_strncpy(&gszExtendedDisconnectReason,string_80,0xff);
  DAT_0036b11f = 0;
  if ((param_1 != 0) && (gszExtendedDisconnectReason != '#')) {
    Con_Printf(&DAT_000dfd8d,&gszExtendedDisconnectReason);
  }
  return;
}


// COM_FileBase  @ 000592ac
void COM_FileBase(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  
  uVar2 = 0x592b8;
  local_c = Q_strlen(param_1);
  local_10 = local_c;
  if (0 < local_c) {
    do {
      iVar1 = local_10;
      local_10 = iVar1 + -1;
      if (((local_10 == 0) || (*(char *)(param_1 + local_10) == '.')) ||
         (*(char *)(param_1 + local_10) == '/')) break;
    } while (*(char *)(param_1 + local_10) != '\\');
    if (*(char *)(param_1 + local_10) == '.') {
      local_10 = iVar1 + -2;
    }
    else {
      local_10 = local_c + -1;
    }
    do {
      iVar1 = local_c;
      local_c = iVar1 + -1;
      if ((local_c < 0) || (*(char *)(param_1 + local_c) == '/')) break;
    } while (*(char *)(param_1 + local_c) != '\\');
    if ((local_c < 0) ||
       ((*(char *)(param_1 + local_c) != '/' && (*(char *)(param_1 + local_c) != '\\')))) {
      local_c = 0;
      iVar1 = local_c;
    }
    local_c = iVar1;
    iVar1 = (local_10 - local_c) + 1;
    Q_strncpy(param_2,param_1 + local_c,iVar1,uVar2);
    *(undefined1 *)(param_2 + iVar1) = 0;
  }
  return;
}


// COM_FileExtension  @ 000591fc
undefined8 * COM_FileExtension(char *param_1)

{
  undefined8 *puVar1;
  int local_8;
  
  for (; (*param_1 != '\0' && (*param_1 != '.')); param_1 = param_1 + 1) {
  }
  if (*param_1 == '\0') {
    puVar1 = (undefined8 *)&DAT_000dfd91;
  }
  else {
    local_8 = 0;
    while ((param_1 = param_1 + 1, local_8 < 7 && (*param_1 != '\0'))) {
      *(char *)((int)&exten_285 + local_8) = *param_1;
      local_8 = local_8 + 1;
    }
    *(undefined1 *)((int)&exten_285 + local_8) = 0;
    puVar1 = &exten_285;
  }
  return puVar1;
}


// COM_FileSize  @ 0005a040
undefined4 COM_FileSize(undefined4 param_1)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  iVar1 = FS_Open(param_1,&DAT_000e017e);
  if (iVar1 != 0) {
    local_c = FS_Size(iVar1);
    FS_Close(iVar1);
  }
  return local_c;
}


// COM_FixSlashes  @ 00059e2c
void COM_FixSlashes(char *param_1)

{
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if (*param_1 == '\\') {
      *param_1 = '/';
    }
  }
  return;
}


// COM_FreeFile  @ 0005a2c8
void COM_FreeFile(int param_1)

{
  (*(code *)g_engdstAddrs._324_4_)(&param_1);
  if (param_1 != 0) {
    Mem_Free(param_1);
  }
  return;
}


// COM_GetGameDir  @ 0005acf8
void COM_GetGameDir(char *param_1)

{
  if (param_1 != (char *)0x0) {
    snprintf(param_1,0x103,"%s",&com_gamedir);
  }
  return;
}


// COM_HexConvert  @ 00056f6c
void COM_HexConvert(int param_1,int param_2,byte *param_3)

{
  char cVar1;
  byte bVar2;
  int local_c;
  byte *local_8;
  
  local_8 = param_3;
  for (local_c = 0; local_c < param_2; local_c = local_c + 2) {
    cVar1 = COM_Nibble((int)*(char *)(local_c + param_1));
    bVar2 = COM_Nibble((int)((char *)(local_c + param_1))[1]);
    *local_8 = cVar1 << 4 | bVar2;
    local_8 = local_8 + 1;
  }
  return;
}


// COM_Init  @ 00059acc
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
  Cvar_RegisterVariable(com_filewarning);
  COM_BitOpsInit();
  return;
}


// COM_InitArgv  @ 000598b8
void COM_InitArgv(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  for (local_10 = 0; (local_10 < 0x32 && (local_10 < param_1)); local_10 = local_10 + 1) {
    for (local_c = 0;
        (local_14 < 0xff && (*(char *)(local_c + *(int *)(param_2 + local_10 * 4)) != '\0'));
        local_c = local_c + 1) {
      com_cmdline[local_14] = *(undefined1 *)(local_c + *(int *)(param_2 + local_10 * 4));
      local_14 = local_14 + 1;
    }
    if (0xfe < local_14) break;
    com_cmdline[local_14] = 0x20;
    local_14 = local_14 + 1;
  }
  com_cmdline[local_14] = 0;
  bVar1 = false;
  for (com_argc = 0; (com_argc < 0x32 && (com_argc < param_1)); com_argc = com_argc + 1) {
    (&largv)[com_argc] = *(undefined4 *)(param_2 + com_argc * 4);
    iVar2 = Q_strcmp("-safe",*(undefined4 *)(param_2 + com_argc * 4));
    if (iVar2 == 0) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    for (local_c = 0; local_c < 7; local_c = local_c + 1) {
      (&largv)[com_argc] = *(undefined4 *)(safeargvs + local_c * 4);
      com_argc = com_argc + 1;
    }
  }
  (&largv)[com_argc] = argvdummy;
  com_argv = &largv;
  return;
}


// COM_ListMaps  @ 0005a908
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void COM_ListMaps(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char acStack_113c [4080];
  char local_110 [64];
  undefined1 local_d0 [124];
  int local_54;
  char local_50 [64];
  char *local_10;
  int local_c;
  size_t local_8;
  
  local_8 = 0;
  local_10 = (char *)0x0;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    local_8 = strlen(param_1);
  }
  Con_Printf("-------------\n");
  for (local_c = 1; -1 < local_c; local_c = local_c + -1) {
    strcpy(local_50,"maps/*.bsp");
    local_10 = (char *)Sys_FindFirst();
    while (local_10 != (char *)0x0) {
      snprintf(acStack_113c,0xfff,"maps/%s");
      FS_GetLocalPath();
      pcVar1 = strstr(acStack_113c,&com_gamedir);
      if ((pcVar1 != (char *)0x0) &&
         ((local_8 == 0 || (iVar2 = strncasecmp(local_10,param_1,local_8), iVar2 == 0)))) {
        memset(local_d0,0,0x7c);
        sprintf(local_110,"maps/%s");
        local_54 = FS_Open();
        if (local_54 != 0) {
          FS_Read();
          FS_Close();
        }
        COM_CheckPrintMap();
      }
      local_10 = (char *)Sys_FindNext();
    }
    Sys_FindClose();
  }
  return;
}


// COM_LoadCacheFile  @ 0005a598
void COM_LoadCacheFile(undefined4 param_1,undefined4 param_2)

{
  loadcache = param_2;
  COM_LoadFile(param_1,3,0);
  return;
}


// COM_LoadFile  @ 0005a0b0
int COM_LoadFile(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined1 local_2c [32];
  int local_c;
  int local_8;
  
  (*(code *)g_engdstAddrs._316_4_)(&param_1,&param_2,&param_3);
  local_c = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  local_8 = FS_Open(param_1,&DAT_000e017e);
  if (local_8 == 0) {
    local_c = 0;
  }
  else {
    iVar1 = FS_Size(local_8);
    COM_FileBase(param_1,local_2c);
    if (param_2 == 1) {
      local_c = Hunk_AllocName(iVar1 + 1,local_2c);
    }
    else if (param_2 == 2) {
      local_c = Hunk_TempAlloc(iVar1 + 1);
    }
    else if (param_2 == 0) {
      local_c = Z_Malloc(iVar1 + 1);
    }
    else if (param_2 == 3) {
      local_c = Cache_Alloc(loadcache,iVar1 + 1,local_2c);
    }
    else if (param_2 == 4) {
      if (loadsize < iVar1 + 1) {
        local_c = Hunk_TempAlloc(iVar1 + 1);
      }
      else {
        local_c = loadbuf;
      }
    }
    else if (param_2 == 5) {
      local_c = Mem_Malloc(iVar1 + 1);
    }
    else {
      Sys_Error("COM_LoadFile: bad usehunk");
    }
    if (local_c == 0) {
      Sys_Error("COM_LoadFile: not enough space for %s",param_1);
      FS_Close(local_8);
      local_c = 0;
    }
    else {
      *(undefined1 *)(local_c + iVar1) = 0;
      FS_Read(local_c,iVar1,1,local_8);
      FS_Close(local_8);
      if (param_3 != (int *)0x0) {
        *param_3 = iVar1;
      }
    }
  }
  return local_c;
}


// COM_LoadFileForMe  @ 0005ac2c
undefined4 COM_LoadFileForMe(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = COM_LoadFile(param_1,5,param_2,0x5ac38);
  return uVar1;
}


// COM_LoadFileLimit  @ 0005a3d8
int COM_LoadFileLimit(int param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined1 local_2c [32];
  int local_c;
  int local_8;
  
  local_c = 0;
  if (*param_5 == 0) {
    local_8 = FS_Open(param_1,&DAT_000e017e);
  }
  else {
    local_8 = *param_5;
  }
  if (local_8 == 0) {
    local_c = 0;
  }
  else {
    iVar1 = FS_Size(local_8);
    if (iVar1 < param_2) {
      Sys_Error("COM_LoadFileLimit: invalid seek position for %s",param_1);
    }
    FS_Seek(local_8,param_2,0);
    if (param_3 < iVar1) {
      iVar1 = param_3;
    }
    *param_4 = iVar1;
    if (param_1 != 0) {
      COM_FileBase(param_1,local_2c);
    }
    local_c = Hunk_TempAlloc(iVar1 + 1);
    if (local_c == 0) {
      if (param_1 != 0) {
        Sys_Error("COM_LoadFileLimit: not enough space for %s",param_1);
      }
      FS_Close(local_8);
      local_c = 0;
    }
    else {
      *(undefined1 *)(local_c + iVar1) = 0;
      FS_Read(local_c,iVar1,1,local_8);
      *param_5 = local_8;
    }
  }
  return local_c;
}


// COM_LoadHunkFile  @ 0005a52c
undefined4 COM_LoadHunkFile(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = COM_LoadFile(param_1,1,0,0x5a538);
  return uVar1;
}


// COM_LoadStackFile  @ 0005a5d0
undefined4
COM_LoadStackFile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  loadbuf = param_2;
  loadsize = param_3;
  uVar1 = COM_LoadFile(param_1,4,param_4);
  return uVar1;
}


// COM_LoadTempFile  @ 0005a560
undefined4 COM_LoadTempFile(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = COM_LoadFile(param_1,2,param_2,0x5a56c);
  return uVar1;
}


// COM_Log  @ 0005ab68
void COM_Log(char *param_1,char *param_2)

{
  int iVar1;
  char *local_410;
  char local_408 [1024];
  undefined1 *local_8;
  
  if (param_1 == (char *)0x0) {
    local_410 = "c:\\hllog.txt";
  }
  else {
    local_410 = param_1;
  }
  local_8 = &stack0x0000000c;
  vsnprintf(local_408,0x400,param_2,local_8);
  iVar1 = FS_Open(local_410,&DAT_000e02a7);
  if (iVar1 != 0) {
    FS_FPrintf(iVar1,&DAT_000e0148,local_408);
    FS_Close(iVar1);
  }
  return;
}


// COM_Munge  @ 0005afec
void COM_Munge(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int local_1c;
  uint *local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  local_c = (int)param_2 >> 2;
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    puVar1 = (uint *)(param_1 + local_8 * 4);
    local_10 = *puVar1 ^ ~param_3;
    local_10 = LongSwap(local_10);
    local_18 = &local_10;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      *(byte *)local_18 =
           (byte)*local_18 ^
           ((byte)(local_1c << ((byte)local_1c & 0x1f)) | 0xa5 | (byte)local_1c |
           mungify_table[local_8 + local_1c & 0xf]);
      local_18 = (uint *)((int)local_18 + 1);
    }
    *puVar1 = local_10 ^ param_3;
  }
  return;
}


// COM_Munge2  @ 0005b1d0
void COM_Munge2(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int local_1c;
  uint *local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  local_c = (int)param_2 >> 2;
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    puVar1 = (uint *)(param_1 + local_8 * 4);
    local_10 = *puVar1 ^ ~param_3;
    local_10 = LongSwap(local_10);
    local_18 = &local_10;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      *(byte *)local_18 =
           (byte)*local_18 ^
           ((byte)(local_1c << ((byte)local_1c & 0x1f)) | 0xa5 | (byte)local_1c |
           mungify_table2[local_8 + local_1c & 0xf]);
      local_18 = (uint *)((int)local_18 + 1);
    }
    *puVar1 = local_10 ^ param_3;
  }
  return;
}


// COM_Munge3  @ 0005b3b4
void COM_Munge3(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int local_1c;
  uint *local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  local_c = (int)param_2 >> 2;
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    puVar1 = (uint *)(param_1 + local_8 * 4);
    local_10 = *puVar1 ^ ~param_3;
    local_10 = LongSwap(local_10);
    local_18 = &local_10;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      *(byte *)local_18 =
           (byte)*local_18 ^
           ((byte)(local_1c << ((byte)local_1c & 0x1f)) | 0xa5 | (byte)local_1c |
           mungify_table3[local_8 + local_1c & 0xf]);
      local_18 = (uint *)((int)local_18 + 1);
    }
    *puVar1 = local_10 ^ param_3;
  }
  return;
}


// COM_Nibble  @ 00056f00
char COM_Nibble(char param_1)

{
  if ((param_1 < '0') || ('9' < param_1)) {
    if ((param_1 < 'A') || ('F' < param_1)) {
      if ((param_1 < 'a') || ('f' < param_1)) {
        param_1 = '0';
      }
      else {
        param_1 = param_1 + -0x57;
      }
    }
    else {
      param_1 = param_1 + -0x37;
    }
  }
  else {
    param_1 = param_1 + -0x30;
  }
  return param_1;
}


// COM_NormalizeAngles  @ 0005af1c
void COM_NormalizeAngles(int param_1)

{
  float fVar1;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    fVar1 = *(float *)(param_1 + local_8 * 4);
    if ((byte)(180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) == 1) {
      *(float *)(param_1 + local_8 * 4) = *(float *)(param_1 + local_8 * 4) - 360.0;
    }
    else if (*(float *)(param_1 + local_8 * 4) < -180.0) {
      *(float *)(param_1 + local_8 * 4) = *(float *)(param_1 + local_8 * 4) + 360.0;
    }
  }
  return;
}


// COM_Parse  @ 000594a0
char * COM_Parse(char *param_1)

{
  char cVar1;
  int iVar2;
  int local_c;
  
  if (s_com_token_unget != 0) {
    s_com_token_unget = 0;
    return param_1;
  }
  local_c = 0;
  com_token = 0;
  if (param_1 == (char *)0x0) {
    com_token = 0;
    return (char *)0x0;
  }
  while( true ) {
    for (; cVar1 = *param_1, cVar1 < '!'; param_1 = param_1 + 1) {
      if (cVar1 == '\0') {
        com_token = 0;
        return (char *)0x0;
      }
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
      if (((cVar1 == '\"') || (cVar1 == '\0')) || (0x3fe < local_c)) break;
      (&com_token)[local_c] = cVar1;
      local_c = local_c + 1;
    }
    (&com_token)[local_c] = 0;
    return param_1;
  }
  if (((((cVar1 == '{') || (cVar1 == '}')) ||
       ((cVar1 == ')' || ((cVar1 == '(' || (cVar1 == '\'')))))) ||
      ((com_ignorecolons == 0 && (cVar1 == ':')))) || (iVar2 = local_c, cVar1 == ',')) {
    com_token = cVar1;
    DAT_00149a41 = 0;
    return param_1 + 1;
  }
  do {
    local_c = iVar2;
    (&com_token)[local_c] = cVar1;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    if ((((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
         ((cVar1 == '(' || (cVar1 == '\'')))) || ((com_ignorecolons == 0 && (cVar1 == ':')))) ||
       ((cVar1 == ',' || (0x3fe < local_c + 1)))) break;
    iVar2 = local_c + 1;
  } while (' ' < cVar1);
  (&DAT_00149a41)[local_c] = 0;
  return param_1;
}


// COM_ParseDirectoryFromCmd  @ 0005a720
void COM_ParseDirectoryFromCmd(undefined4 param_1,char *param_2,char *param_3)

{
  int iVar1;
  char *local_8;
  
  iVar1 = COM_CheckParm(param_1);
  local_8 = (char *)0x0;
  if (((iVar1 != 0) && (iVar1 < com_argc + -1)) &&
     ((local_8 = *(char **)(iVar1 * 4 + com_argv + 4), *local_8 == '-' || (*local_8 == '+')))) {
    local_8 = (char *)0x0;
  }
  if (local_8 == (char *)0x0) {
    if (param_3 == (char *)0x0) {
      *param_2 = '\0';
    }
    else {
      strcpy(param_2,param_3);
    }
  }
  else {
    strcpy(param_2,local_8);
  }
  COM_StripTrailingSlash(param_2);
  return;
}


// COM_ParseLine  @ 000596b0
char * COM_ParseLine(char *param_1)

{
  char cVar1;
  int iVar2;
  int local_c;
  
  if (s_com_token_unget == 0) {
    local_c = 0;
    com_token = 0;
    if (param_1 == (char *)0x0) {
      param_1 = (char *)0x0;
    }
    else {
      cVar1 = *param_1;
      iVar2 = local_c;
      do {
        local_c = iVar2;
        (&com_token)[local_c] = cVar1;
        param_1 = param_1 + 1;
        cVar1 = *param_1;
        if (cVar1 < ' ') break;
        iVar2 = local_c + 1;
      } while (local_c + 1 < 0x3ff);
      (&DAT_00149a41)[local_c] = 0;
      if (cVar1 == '\0') {
        param_1 = (char *)0x0;
      }
      else {
        for (; *param_1 < ' '; param_1 = param_1 + 1) {
          if (*param_1 == '\0') {
            return (char *)0x0;
          }
        }
      }
    }
  }
  else {
    s_com_token_unget = 0;
  }
  return param_1;
}


// COM_RemoveEvilChars__FPc  @ 00097604
void COM_RemoveEvilChars__FPc(char *param_1)

{
  char *local_8;
  
  for (local_8 = param_1; (local_8 != (char *)0x0 && (*local_8 != '\0')); local_8 = local_8 + 1) {
    if (*local_8 == '%') {
      *local_8 = ' ';
    }
    else if (*local_8 < ' ') {
      *local_8 = ' ';
    }
  }
  return;
}


// COM_SetupDirectories  @ 0005a7ec
void COM_SetupDirectories(void)

{
  undefined1 *puVar1;
  undefined1 local_204 [512];
  
  com_clientfallback = 0;
  com_gamedir = '\0';
  COM_ParseDirectoryFromCmd("-basedir",local_204,"valve");
  COM_ParseDirectoryFromCmd("-game",&com_gamedir,local_204);
  if (com_gamedir == '\0') {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    puVar1 = &com_gamedir;
  }
  FileSystem_SetGameDirectory(local_204,puVar1);
  return;
}


// COM_Shutdown  @ 0005a624
void COM_Shutdown(void)

{
  return;
}


// COM_SizeofResourceList  @ 0005652c
int COM_SizeofResourceList(int param_1,int param_2)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  Q_memset(param_2,0,0x20,0x5653a);
  for (local_8 = *(int *)(param_1 + 0x80); local_8 != param_1; local_8 = *(int *)(local_8 + 0x80)) {
    local_c = local_c + *(int *)(local_8 + 0x48);
    if ((*(int *)(local_8 + 0x40) == 2) && (*(int *)(local_8 + 0x44) == 1)) {
      *(int *)(param_2 + 0x18) = *(int *)(local_8 + 0x48) + *(int *)(param_2 + 0x18);
    }
    else {
      *(int *)(*(int *)(local_8 + 0x40) * 4 + param_2) =
           *(int *)(local_8 + 0x48) + *(int *)(*(int *)(local_8 + 0x40) * 4 + param_2);
    }
  }
  return local_c;
}


// COM_SkipPath  @ 00059108
char * COM_SkipPath(char *param_1)

{
  char *local_8;
  
  local_8 = param_1;
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if ((*param_1 == '/') || (*param_1 == '\\')) {
      local_8 = param_1 + 1;
    }
  }
  return local_8;
}


// COM_StripExtension  @ 0005914c
void COM_StripExtension(char *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  char *local_c;
  char *local_8;
  
  iVar2 = Q_strlen(param_1);
  local_8 = param_1 + iVar2;
  iVar2 = Q_strlen(param_1);
  local_c = (char *)(param_2 + iVar2);
  bVar1 = false;
  for (; param_1 <= local_8; local_8 = local_8 + -1) {
    if ((bVar1) || (*local_8 != '.')) {
      if ((*local_8 == '/') || (*local_8 == '\\')) {
        bVar1 = true;
      }
      *local_c = *local_8;
    }
    else {
      *local_c = '\0';
      bVar1 = true;
    }
    local_c = local_c + -1;
  }
  return;
}


// COM_StripTrailingSlash  @ 0005a6b8
void COM_StripTrailingSlash(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  if ((0 < (int)sVar1) && ((param_1[sVar1 - 1] == '\\' || (param_1[sVar1 - 1] == '/')))) {
    param_1[sVar1 - 1] = '\0';
  }
  return;
}


// COM_TokenWaiting  @ 00059798
undefined4 COM_TokenWaiting(char *param_1)

{
  char *local_8;
  
  local_8 = param_1;
  while( true ) {
    if ((*local_8 == '\0') || (*local_8 == '\n')) {
      return 0;
    }
    if (((*(ushort *)(__ctype_b + *local_8 * 2) & 0x2000) == 0) ||
       ((*(ushort *)(__ctype_b + *local_8 * 2) & 8) != 0)) break;
    local_8 = local_8 + 1;
  }
  return 1;
}


// COM_UnMunge  @ 0005b0e0
void COM_UnMunge(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  int local_1c;
  uint *local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  local_c = (int)param_2 >> 2;
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    puVar2 = (uint *)(param_1 + local_8 * 4);
    local_10 = *puVar2 ^ param_3;
    local_18 = &local_10;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      *(byte *)local_18 =
           (byte)*local_18 ^
           ((byte)(local_1c << ((byte)local_1c & 0x1f)) | 0xa5 | (byte)local_1c |
           mungify_table[local_8 + local_1c & 0xf]);
      local_18 = (uint *)((int)local_18 + 1);
    }
    uVar1 = LongSwap(local_10);
    *puVar2 = uVar1 ^ ~param_3;
  }
  return;
}


// COM_UnMunge2  @ 0005b2c4
void COM_UnMunge2(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  int local_1c;
  uint *local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  local_c = (int)param_2 >> 2;
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    puVar2 = (uint *)(param_1 + local_8 * 4);
    local_10 = *puVar2 ^ param_3;
    local_18 = &local_10;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      *(byte *)local_18 =
           (byte)*local_18 ^
           ((byte)(local_1c << ((byte)local_1c & 0x1f)) | 0xa5 | (byte)local_1c |
           mungify_table2[local_8 + local_1c & 0xf]);
      local_18 = (uint *)((int)local_18 + 1);
    }
    uVar1 = LongSwap(local_10);
    *puVar2 = uVar1 ^ ~param_3;
  }
  return;
}


// COM_UnMunge3  @ 0005b4a8
void COM_UnMunge3(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  int local_1c;
  uint *local_18;
  uint local_10;
  int local_c;
  int local_8;
  
  param_2 = param_2 & 0xfffffffc;
  if ((int)param_2 < 0) {
    param_2 = param_2 + 3;
  }
  local_c = (int)param_2 >> 2;
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    puVar2 = (uint *)(param_1 + local_8 * 4);
    local_10 = *puVar2 ^ param_3;
    local_18 = &local_10;
    for (local_1c = 0; local_1c < 4; local_1c = local_1c + 1) {
      *(byte *)local_18 =
           (byte)*local_18 ^
           ((byte)(local_1c << ((byte)local_1c & 0x1f)) | 0xa5 | (byte)local_1c |
           mungify_table3[local_8 + local_1c & 0xf]);
      local_18 = (uint *)((int)local_18 + 1);
    }
    uVar1 = LongSwap(local_10);
    *puVar2 = uVar1 ^ ~param_3;
  }
  return;
}


// COM_UngetToken  @ 0005947c
void COM_UngetToken(void)

{
  s_com_token_unget = 1;
  return;
}


// COM_WriteFile  @ 00059d40
void COM_WriteFile(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char local_10c [260];
  int local_8;
  
  snprintf(local_10c,0x104,"%s",param_1);
  COM_FixSlashes(local_10c);
  COM_CreatePath(local_10c);
  local_8 = FS_Open(local_10c,&DAT_000e014b);
  if (local_8 == 0) {
    Sys_Printf("COM_WriteFile: failed on %s\n",local_10c);
  }
  else {
    Sys_Printf("COM_WriteFile: %s\n",local_10c);
    FS_Write(param_2,param_3,1,local_8);
    FS_Close(local_8);
  }
  return;
}


