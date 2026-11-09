// MD5_Hash_CachedFile  @ 0808d120
undefined4
MD5_Hash_CachedFile(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5
                   )

{
  undefined4 uVar1;
  undefined1 local_5c [88];
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    memset(local_5c,0,0x58);
    MD5Init(local_5c);
    if (param_4 != 0) {
      MD5Update(local_5c,param_5,0x10);
    }
    MD5Update(local_5c,param_2,param_3);
    MD5Final(param_1,local_5c);
    uVar1 = 1;
  }
  return uVar1;
}


// MD5_Hash_File  @ 0808cf30
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
LAB_0808cff0:
      memset(local_45c,0,0x58);
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
            goto LAB_0808d0b1;
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
      if (0 < (int)sVar1) goto LAB_0808cff0;
LAB_0808d0b1:
      fclose(local_460);
    }
  }
  return 0;
}


// MD5_Print  @ 0808d1a0
undefined1 * MD5_Print(int param_1)

{
  int iVar1;
  char local_10 [12];
  
  memset(szReturn_136,0,0x40);
  iVar1 = 0;
  do {
    sprintf(local_10,"%2x",(uint)*(byte *)(iVar1 + param_1));
    strcat(szReturn_136,local_10);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  return szReturn_136;
}


