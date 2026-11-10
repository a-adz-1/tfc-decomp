// getAuthVerifierKey__11AuthRequestPCc  @ 00098fe4
undefined4 getAuthVerifierKey__11AuthRequestPCc(int param_1,char *param_2)

{
  undefined2 uVar1;
  FILE *__stream;
  size_t __size;
  char *__ptr;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 local_14 [16];
  
  __stream = fopen(param_2,"rb");
  if (__stream == (FILE *)0x0) {
    return 0;
  }
  fseek(__stream,0,2);
  __size = ftell(__stream);
  fseek(__stream,0,0);
  __ptr = malloc(__size + 1);
  if (__ptr == (char *)0x0) {
    fclose(__stream);
    return 0;
  }
  __ptr[__size] = '\0';
  fread(__ptr,__size,1,__stream);
  fclose(__stream);
  if (*(int *)(param_1 + 0x81a8) != 0) {
    DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(*(int *)(param_1 + 0x81a8));
    *(undefined4 *)(param_1 + 0x81a8) = 0;
  }
  __11WriteBufferUl(local_14,0x100);
  uVar6 = __size - 1;
  if ((int)uVar6 < 0) goto LAB_0009912f;
  uVar2 = ~uVar6 & 3;
  pcVar5 = __ptr;
  if ((int)uVar6 < 0) {
LAB_000990de:
    appendByte__11WriteBufferc(local_14,(int)*pcVar5);
    pcVar5 = pcVar5 + 1;
    uVar6 = uVar6 - 1;
    if ((int)uVar6 < 0) goto LAB_0009912f;
  }
  else if (uVar2 != 0) {
    if (uVar2 < 3) {
      pcVar5 = __ptr;
      if (uVar2 < 2) {
        appendByte__11WriteBufferc(local_14,(int)*__ptr);
        pcVar5 = __ptr + 1;
        uVar6 = __size - 2;
      }
      appendByte__11WriteBufferc(local_14,(int)*pcVar5);
      pcVar5 = pcVar5 + 1;
      uVar6 = uVar6 - 1;
    }
    goto LAB_000990de;
  }
  do {
    appendByte__11WriteBufferc(local_14,(int)*pcVar5);
    appendByte__11WriteBufferc(local_14,(int)pcVar5[1]);
    appendByte__11WriteBufferc(local_14,(int)pcVar5[2]);
    appendByte__11WriteBufferc(local_14,(int)pcVar5[3]);
    pcVar5 = pcVar5 + 4;
    uVar6 = uVar6 - 4;
  } while (-1 < (int)uVar6);
LAB_0009912f:
  uVar3 = getBuffer__C11WriteBuffer(local_14);
  uVar1 = getSize__C11WriteBuffer(local_14,uVar3);
  iVar4 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar1);
  *(int *)(param_1 + 0x81a8) = iVar4;
  if (iVar4 == 0) {
    ___11WriteBuffer(local_14,2);
    uVar3 = 0;
  }
  else {
    free(__ptr);
    if (**(int **)(param_1 + 0x81a8) == 0) {
      ___11WriteBuffer(local_14,2);
      uVar3 = 1;
    }
    else {
      ___11WriteBuffer(local_14,2);
      uVar3 = 0;
    }
  }
  return uVar3;
}


