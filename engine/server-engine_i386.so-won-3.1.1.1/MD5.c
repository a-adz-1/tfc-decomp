// MD5_Hash_CachedFile__FPUcT0iiPUi  @ 000cdae4
undefined4
MD5_Hash_CachedFile__FPUcT0iiPUi
          (undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined1 local_5c [88];
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    memset(local_5c,0,0x58);
    MD5Init__FP12MD5Context_t(local_5c);
    if (param_4 != 0) {
      MD5Update__FP12MD5Context_tPCUcUi(local_5c,param_5,0x10);
    }
    MD5Update__FP12MD5Context_tPCUcUi(local_5c,param_2,param_3);
    MD5Final__FPUcP12MD5Context_t(param_1,local_5c);
    uVar1 = 1;
  }
  return uVar1;
}


// MD5_Hash_File  @ 0005ee58
/* WARNING: Removing unreachable block (ram,0x0005f01a) */

void MD5_Hash_File(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                  undefined4 param_5)

{
  int iVar1;
  int local_468;
  undefined1 local_464 [88];
  int local_40c;
  undefined1 local_408 [1024];
  int local_8;
  
  local_8 = FS_Open(param_2,&DAT_000e0b30);
  if (local_8 == 0) {
    FUN_0005f058();
    return;
  }
  local_468 = FS_Size(local_8);
  if (local_468 < 1) {
    FS_Close(local_8);
    FUN_0005f058();
    return;
  }
  Q_memset(local_464,0,0x58);
  MD5Init(local_464);
  if (param_4 != 0) {
    MD5Update(local_464,param_5,0x10);
  }
  while( true ) {
    if (local_468 < 1) {
      FUN_0005f014();
      return;
    }
    if (local_468 < 0x401) {
      local_40c = FS_Read(local_408,local_468,1,local_8);
    }
    else {
      local_40c = FS_Read(local_408,0x400,1,local_8);
    }
    if (0 < local_40c) {
      local_468 = local_468 - local_40c;
      MD5Update(local_464,local_408,local_40c);
    }
    iVar1 = FS_EndOfFile(local_8);
    if (iVar1 != 0) break;
    iVar1 = FS_IsOk(local_8);
    if (iVar1 == 0) {
      if (local_8 != 0) {
        FS_Close(local_8);
      }
      FUN_0005f058();
      return;
    }
  }
  FS_Close(local_8);
  local_8 = 0;
  MD5Final(param_1,local_464);
  FUN_0005f058();
  return;
}


// MD5_Hash_File__FPUcPciPUi  @ 000cd80c
undefined4
MD5_Hash_File__FPUcPciPUi(undefined4 param_1,char *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char *local_870;
  char *local_86c;
  char local_868 [1024];
  size_t local_468;
  undefined1 local_464 [88];
  size_t local_40c;
  undefined1 local_408 [1024];
  FILE *local_8;
  
  memset(local_464,0,0x58);
  MD5Init__FP12MD5Context_t(local_464);
  if (param_3 != 0) {
    MD5Update__FP12MD5Context_tPCUcUi(local_464,param_4,0x10);
  }
  local_86c = param_2;
  do {
    if ((local_86c == (char *)0x0) || (*local_86c == '\0')) {
      MD5Final__FPUcP12MD5Context_t(param_1,local_464);
      return 1;
    }
    if (*local_86c == ';') {
      local_86c = local_86c + 1;
    }
    for (local_870 = local_86c; (*local_870 != '\0' && (*local_870 != ';'));
        local_870 = local_870 + 1) {
    }
    strncpy(local_868,local_86c,(int)local_870 - (int)local_86c);
    local_870[(int)(local_868 + -(int)local_86c)] = '\0';
    local_86c = local_870;
    local_8 = fopen(local_868,"rb");
    if (local_8 == (FILE *)0x0) {
      return 0;
    }
    fseek(local_8,0,2);
    local_468 = ftell(local_8);
    fseek(local_8,0,0);
    if ((int)local_468 < 1) {
      fclose(local_8);
      return 0;
    }
    while (0 < (int)local_468) {
      if ((int)local_468 < 0x401) {
        local_40c = fread(local_408,1,local_468,local_8);
      }
      else {
        local_40c = fread(local_408,1,0x400,local_8);
      }
      if (0 < (int)local_40c) {
        local_468 = local_468 - local_40c;
        MD5Update__FP12MD5Context_tPCUcUi(local_464,local_408,local_40c);
      }
      iVar1 = feof(local_8);
      if (iVar1 != 0) {
        fclose(local_8);
        local_8 = (FILE *)0x0;
        break;
      }
      iVar1 = ferror(local_8);
      if (iVar1 != 0) {
        if (local_8 != (FILE *)0x0) {
          fclose(local_8);
        }
        return 0;
      }
    }
    if (local_8 != (FILE *)0x0) {
      fclose(local_8);
    }
  } while( true );
}


// MD5_Print  @ 0005f064
void MD5_Print(int param_1)

{
  size_t sVar1;
  int local_18;
  char local_14 [15];
  byte local_5;
  
  Q_memset(szReturn_39,0,0x40);
  for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
    local_5 = *(byte *)(param_1 + local_18);
    snprintf(local_14,10,"%02x",(uint)local_5);
    sVar1 = strlen(szReturn_39);
    strncat(szReturn_39,local_14,0x3f - sVar1);
  }
  FUN_0005f10c();
  return;
}


// MD5_Print__FPUc  @ 000cdb70
undefined1 * MD5_Print__FPUc(int param_1)

{
  int local_18;
  char local_14 [15];
  byte local_5;
  
  memset(szReturn_57,0,0x40);
  for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
    local_5 = *(byte *)(param_1 + local_18);
    sprintf(local_14,"%2x",(uint)local_5);
    strcat(szReturn_57,local_14);
  }
  return szReturn_57;
}


