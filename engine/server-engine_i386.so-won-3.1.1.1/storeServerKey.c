// storeServerKey__11AuthRequest  @ 000d4a08
undefined4 storeServerKey__11AuthRequest(int param_1)

{
  ushort uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  FILE *__stream;
  void *__ptr;
  uint __size;
  size_t __n;
  FILE *__s;
  char local_104 [256];
  
  if (g_authType == 0) {
    puVar2 = &DAT_000ef6a6;
  }
  else {
    puVar2 = &DAT_000ef6a1;
  }
  sprintf(local_104,"auth/%s%u-%u.dat",puVar2,*(undefined4 *)(param_1 + 0x8008),
          *(undefined4 *)(param_1 + 4));
  if (*(int *)(param_1 + 0x81a0) == 0) {
    uVar3 = 0;
  }
  else {
    CreatePath__11AuthRequestPc(param_1,local_104);
    __stream = fopen(local_104,"wb");
    if (__stream == (FILE *)0x0) {
      uVar3 = 0;
    }
    else {
      __n = 1;
      __s = __stream;
      uVar1 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0));
      __size = (uint)uVar1;
      __ptr = (void *)GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0));
      fwrite(__ptr,__size,__n,__s);
      fflush(__stream);
      fclose(__stream);
      uVar3 = 1;
    }
  }
  return uVar3;
}


