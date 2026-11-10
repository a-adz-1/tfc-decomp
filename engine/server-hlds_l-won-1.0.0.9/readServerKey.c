// readServerKey__11AuthRequest  @ 080946e0
undefined4 readServerKey__11AuthRequest(int param_1)

{
  undefined2 uVar1;
  FILE *__stream;
  undefined4 uVar2;
  size_t __size;
  char *__ptr;
  char *pcVar3;
  int iVar4;
  undefined1 local_120 [16];
  undefined1 local_110 [8];
  char local_108 [260];
  
  Auth_HashIP__FUlUsPc(*(undefined4 *)(param_1 + 0x8008),*(undefined2 *)(param_1 + 4),local_110);
  sprintf(local_108,"auth\\%s%s.dat",&DAT_080a8fed,local_110);
  Auth_CreatePath__FPc(local_108);
  __stream = fopen(local_108,"rb");
  if (__stream == (FILE *)0x0) {
    uVar2 = 0;
  }
  else {
    fseek(__stream,0,2);
    __size = ftell(__stream);
    fseek(__stream,0,0);
    __ptr = malloc(__size + 1);
    if (__ptr == (char *)0x0) {
      fclose(__stream);
      uVar2 = 0;
    }
    else {
      __ptr[__size] = '\0';
      fread(__ptr,__size,1,__stream);
      fclose(__stream);
      if (*(int *)(param_1 + 0x8034) != 0) {
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                  (*(undefined4 *)(param_1 + 0x8034));
        *(undefined4 *)(param_1 + 0x8034) = 0;
      }
      gcc2_compiled_(local_120,0x100);
      iVar4 = __size - 1;
      if (-1 < iVar4) {
        pcVar3 = __ptr;
        do {
          appendByte__11WriteBufferc(local_120,(int)*pcVar3);
          pcVar3 = pcVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (-1 < iVar4);
      }
      uVar2 = getBuffer__C11WriteBuffer(local_120);
      uVar1 = getSize__C11WriteBuffer(local_120,uVar2);
      iVar4 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(uVar1);
      *(int *)(param_1 + 0x8034) = iVar4;
      if (iVar4 == 0) {
        ___11WriteBuffer(local_120,2);
        uVar2 = 0;
      }
      else {
        free(__ptr);
        if (**(int **)(param_1 + 0x8034) == 0) {
          ___11WriteBuffer(local_120,2);
          uVar2 = 1;
        }
        else {
          DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int **)(param_1 + 0x8034))
          ;
          *(undefined4 *)(param_1 + 0x8034) = 0;
          ___11WriteBuffer(local_120,2);
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}


