// storeServerKey__11AuthRequest  @ 08094620
undefined4 storeServerKey__11AuthRequest(int param_1)

{
  FILE *__stream;
  uint uVar1;
  void *__ptr;
  size_t __n;
  FILE *__s;
  undefined1 local_110 [8];
  char local_108 [260];
  
  Auth_HashIP__FUlUsPc(*(undefined4 *)(param_1 + 0x8008),*(undefined2 *)(param_1 + 4),local_110);
  sprintf(local_108,"auth/%s%s.dat",&DAT_080a8fed,local_110);
  if (*(int *)(param_1 + 0x8034) != 0) {
    Auth_CreatePath__FPc(local_108);
    __stream = fopen(local_108,"wb");
    if (__stream != (FILE *)0x0) {
      __n = 1;
      __s = __stream;
      uVar1 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8034));
      uVar1 = uVar1 & 0xffff;
      __ptr = (void *)GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8034));
      fwrite(__ptr,uVar1,__n,__s);
      fflush(__stream);
      fclose(__stream);
      return 1;
    }
  }
  return 0;
}


