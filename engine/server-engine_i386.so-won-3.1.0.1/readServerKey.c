// readServerKey__11AuthRequest  @ 0009be94
undefined4 readServerKey__11AuthRequest(int param_1)

{
  undefined2 uVar1;
  undefined *puVar2;
  FILE *__stream;
  size_t __size;
  char *__ptr;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  undefined1 local_11c [16];
  undefined1 local_10c [8];
  char local_104 [256];
  
  HashIP__11AuthRequestUlUsPc
            (param_1,*(undefined4 *)(param_1 + 0x8008),*(undefined2 *)(param_1 + 4),local_10c);
  puVar2 = &DAT_000b044b;
  if (g_isDedicated != 0) {
    puVar2 = &DAT_000b0446;
  }
  sprintf(local_104,"auth/%s%s.dat",puVar2,local_10c);
  CreatePath__11AuthRequestPc(param_1,local_104);
  __stream = fopen(local_104,"rb");
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
  if (*(int *)(param_1 + 0x81a0) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int *)(param_1 + 0x81a0));
    *(undefined4 *)(param_1 + 0x81a0) = 0;
  }
  __11WriteBufferUl(local_11c,0x100);
  uVar7 = __size - 1;
  if ((int)uVar7 < 0) goto LAB_0009c043;
  uVar3 = ~uVar7 & 3;
  pcVar6 = __ptr;
  if ((int)uVar7 < 0) {
LAB_0009bff1:
    appendByte__11WriteBufferc(local_11c,(int)*pcVar6);
    pcVar6 = pcVar6 + 1;
    uVar7 = uVar7 - 1;
    if ((int)uVar7 < 0) goto LAB_0009c043;
  }
  else if (uVar3 != 0) {
    if (uVar3 < 3) {
      pcVar6 = __ptr;
      if (uVar3 < 2) {
        appendByte__11WriteBufferc(local_11c,(int)*__ptr);
        pcVar6 = __ptr + 1;
        uVar7 = __size - 2;
      }
      appendByte__11WriteBufferc(local_11c,(int)*pcVar6);
      pcVar6 = pcVar6 + 1;
      uVar7 = uVar7 - 1;
    }
    goto LAB_0009bff1;
  }
  do {
    appendByte__11WriteBufferc(local_11c,(int)*pcVar6);
    appendByte__11WriteBufferc(local_11c,(int)pcVar6[1]);
    appendByte__11WriteBufferc(local_11c,(int)pcVar6[2]);
    appendByte__11WriteBufferc(local_11c,(int)pcVar6[3]);
    pcVar6 = pcVar6 + 4;
    uVar7 = uVar7 - 4;
  } while (-1 < (int)uVar7);
LAB_0009c043:
  uVar4 = getBuffer__C11WriteBuffer(local_11c);
  uVar1 = getSize__C11WriteBuffer(local_11c,uVar4);
  iVar5 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(uVar1);
  *(int *)(param_1 + 0x81a0) = iVar5;
  if (iVar5 == 0) {
    ___11WriteBuffer(local_11c,2);
    uVar4 = 0;
  }
  else {
    free(__ptr);
    if (**(int **)(param_1 + 0x81a0) == 0) {
      ___11WriteBuffer(local_11c,2);
      uVar4 = 1;
    }
    else {
      DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int **)(param_1 + 0x81a0));
      *(undefined4 *)(param_1 + 0x81a0) = 0;
      ___11WriteBuffer(local_11c,2);
      uVar4 = 0;
    }
  }
  return uVar4;
}


