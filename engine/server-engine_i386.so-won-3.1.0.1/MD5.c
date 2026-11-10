// MD5_Hash_CachedFile__FPUcT0iiPUi  @ 000960a0
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


// MD5_Hash_File  @ 00091d30
undefined4
MD5_Hash_File(undefined4 param_1,char *param_2,int param_3,int param_4,undefined4 param_5)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  FILE *local_460;
  undefined1 local_45c [88];
  undefined1 local_404 [1024];
  
  if (param_3 == 0) {
    sVar1 = COM_FindFile(param_2,0,&local_460);
    if ((local_460 != (FILE *)0x0) && (sVar1 != 0xffffffff)) {
LAB_00091dfc:
      Q_memset(local_45c,0,0x58);
      MD5Init(local_45c);
      if (param_4 != 0) {
        MD5Update(local_45c,param_5,0x10);
      }
      if (0 < (int)sVar1) {
        do {
          sVar2 = sVar1;
          if (0x400 < (int)sVar1) {
            sVar2 = 0x400;
          }
          sVar2 = fread(local_404,1,sVar2,local_460);
          if (0 < (int)sVar2) {
            sVar1 = sVar1 - sVar2;
            MD5Update(local_45c,local_404,sVar2);
          }
          iVar3 = feof(local_460);
          if (iVar3 != 0) {
            fclose(local_460);
            local_460 = (FILE *)0x0;
            break;
          }
          iVar3 = ferror(local_460);
          if (iVar3 != 0) {
            if (local_460 == (FILE *)0x0) {
              return 0;
            }
            goto LAB_00091ec6;
          }
        } while (0 < (int)sVar1);
      }
      if (local_460 != (FILE *)0x0) {
        fclose(local_460);
      }
      MD5Final(param_1,local_45c);
      return 1;
    }
  }
  else {
    local_460 = fopen(param_2,"rb");
    if (local_460 != (FILE *)0x0) {
      fseek(local_460,0,2);
      sVar1 = ftell(local_460);
      fseek(local_460,0,0);
      if (0 < (int)sVar1) goto LAB_00091dfc;
LAB_00091ec6:
      fclose(local_460);
    }
  }
  return 0;
}


// MD5_Hash_File__FPUcPciPUi  @ 00095ed8
undefined4
MD5_Hash_File__FPUcPciPUi(undefined4 param_1,char *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  FILE *__stream;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  char *local_860;
  char local_85c [1024];
  undefined1 local_45c [88];
  undefined1 local_404 [1024];
  
  memset(local_45c,0,0x58);
  MD5Init__FP12MD5Context_t(local_45c);
  if (param_3 != 0) {
    MD5Update__FP12MD5Context_tPCUcUi(local_45c,param_4,0x10);
  }
  do {
    if ((param_2 == (char *)0x0) || (cVar1 = *param_2, cVar1 == '\0')) {
      MD5Final__FPUcP12MD5Context_t(param_1,local_45c);
      return 1;
    }
    local_860 = param_2;
    if (cVar1 == ';') {
      param_2 = param_2 + 1;
      cVar1 = *param_2;
      local_860 = param_2;
    }
    while ((cVar1 != '\0' && (*param_2 != ';'))) {
      param_2 = param_2 + 1;
      cVar1 = *param_2;
    }
    strncpy(local_85c,local_860,(int)param_2 - (int)local_860);
    local_85c[(int)param_2 - (int)local_860] = '\0';
    __stream = fopen(local_85c,"rb");
    if (__stream == (FILE *)0x0) {
      return 0;
    }
    fseek(__stream,0,2);
    sVar2 = ftell(__stream);
    fseek(__stream,0,0);
    if ((int)sVar2 < 1) {
LAB_00096056:
      fclose(__stream);
      return 0;
    }
    do {
      sVar3 = sVar2;
      if (0x400 < (int)sVar2) {
        sVar3 = 0x400;
      }
      sVar3 = fread(local_404,1,sVar3,__stream);
      if (0 < (int)sVar3) {
        sVar2 = sVar2 - sVar3;
        MD5Update__FP12MD5Context_tPCUcUi(local_45c,local_404,sVar3);
      }
      iVar4 = feof(__stream);
      if (iVar4 != 0) {
        fclose(__stream);
        __stream = (FILE *)0x0;
        break;
      }
      iVar4 = ferror(__stream);
      if (iVar4 != 0) {
        if (__stream == (FILE *)0x0) {
          return 0;
        }
        goto LAB_00096056;
      }
    } while (0 < (int)sVar2);
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
  } while( true );
}


// MD5_Print  @ 00091f14
undefined1 * MD5_Print(int param_1)

{
  int iVar1;
  char local_10 [12];
  
  Q_memset(szReturn_26,0,0x40);
  iVar1 = 0;
  do {
    sprintf(local_10,"%02x",(uint)*(byte *)(iVar1 + param_1));
    Q_strcat(szReturn_26,local_10);
    sprintf(local_10,"%02x",(uint)*(byte *)(param_1 + 1 + iVar1));
    Q_strcat(szReturn_26,local_10);
    sprintf(local_10,"%02x",(uint)*(byte *)(param_1 + 2 + iVar1));
    Q_strcat(szReturn_26,local_10);
    sprintf(local_10,"%02x",(uint)*(byte *)(param_1 + 3 + iVar1));
    Q_strcat(szReturn_26,local_10);
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x10);
  return szReturn_26;
}


// MD5_Print__FPUc  @ 00096104
undefined1 * MD5_Print__FPUc(int param_1)

{
  int iVar1;
  char local_10 [12];
  
  memset(szReturn_38,0,0x40);
  iVar1 = 0;
  do {
    sprintf(local_10,"%2x",(uint)*(byte *)(iVar1 + param_1));
    strcat(szReturn_38,local_10);
    sprintf(local_10,"%2x",(uint)*(byte *)(param_1 + 1 + iVar1));
    strcat(szReturn_38,local_10);
    sprintf(local_10,"%2x",(uint)*(byte *)(param_1 + 2 + iVar1));
    strcat(szReturn_38,local_10);
    sprintf(local_10,"%2x",(uint)*(byte *)(param_1 + 3 + iVar1));
    strcat(szReturn_38,local_10);
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x10);
  return szReturn_38;
}


