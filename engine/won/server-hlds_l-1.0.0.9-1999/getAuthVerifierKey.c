// getAuthVerifierKey__11AuthRequestPCc  @ 08091560
undefined4 getAuthVerifierKey__11AuthRequestPCc(int param_1,char *param_2)

{
  undefined2 uVar1;
  FILE *__stream;
  undefined4 uVar2;
  size_t __size;
  char *__ptr;
  char *pcVar3;
  int iVar4;
  undefined1 local_14 [16];
  
  __stream = fopen(param_2,"rb");
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
      if (*(int *)(param_1 + 0x803c) != 0) {
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(*(undefined4 *)(param_1 + 0x803c));
        *(undefined4 *)(param_1 + 0x803c) = 0;
      }
      gcc2_compiled_(local_14,0x100);
      iVar4 = __size - 1;
      if (-1 < iVar4) {
        pcVar3 = __ptr;
        do {
          appendByte__11WriteBufferc(local_14,(int)*pcVar3);
          pcVar3 = pcVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (-1 < iVar4);
      }
      uVar2 = getBuffer__C11WriteBuffer(local_14);
      uVar1 = getSize__C11WriteBuffer(local_14,uVar2);
      iVar4 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar1);
      *(int *)(param_1 + 0x803c) = iVar4;
      if (iVar4 == 0) {
        ___11WriteBuffer(local_14,2);
        uVar2 = 0;
      }
      else {
        free(__ptr);
        if (**(int **)(param_1 + 0x803c) == 0) {
          ___11WriteBuffer(local_14,2);
          uVar2 = 1;
        }
        else {
          ___11WriteBuffer(local_14,2);
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}


