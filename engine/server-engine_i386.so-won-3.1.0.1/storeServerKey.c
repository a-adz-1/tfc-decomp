// storeServerKey__11AuthRequest  @ 0009bdcc
undefined4 storeServerKey__11AuthRequest(int param_1)

{
  undefined *puVar1;
  FILE *__stream;
  uint uVar2;
  void *__ptr;
  size_t __n;
  FILE *__s;
  undefined1 local_10c [8];
  char local_104 [256];
  
  HashIP__11AuthRequestUlUsPc
            (param_1,*(undefined4 *)(param_1 + 0x8008),*(undefined2 *)(param_1 + 4),local_10c);
  puVar1 = &DAT_000b044b;
  if (g_isDedicated != 0) {
    puVar1 = &DAT_000b0446;
  }
  sprintf(local_104,"auth/%s%s.dat",puVar1,local_10c);
  if (*(int *)(param_1 + 0x81a0) != 0) {
    CreatePath__11AuthRequestPc(param_1,local_104);
    __stream = fopen(local_104,"wb");
    if (__stream != (FILE *)0x0) {
      __n = 1;
      __s = __stream;
      uVar2 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0));
      uVar2 = uVar2 & 0xffff;
      __ptr = (void *)GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0));
      fwrite(__ptr,uVar2,__n,__s);
      fflush(__stream);
      fclose(__stream);
      return 1;
    }
  }
  return 0;
}


