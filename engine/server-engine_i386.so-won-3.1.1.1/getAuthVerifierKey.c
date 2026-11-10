// getAuthVerifierKey__11AuthRequestPCc  @ 000d17f4
undefined4 getAuthVerifierKey__11AuthRequestPCc(int param_1,char *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_24 [16];
  size_t local_14;
  char *local_10;
  char *local_c;
  FILE *local_8;
  
  local_8 = fopen(param_2,"rb");
  if (local_8 == (FILE *)0x0) {
    uVar2 = 0;
  }
  else {
    fseek(local_8,0,2);
    local_14 = ftell(local_8);
    fseek(local_8,0,0);
    local_c = malloc(local_14 + 1);
    if (local_c == (char *)0x0) {
      fclose(local_8);
      uVar2 = 0;
    }
    else {
      local_c[local_14] = '\0';
      fread(local_c,local_14,1,local_8);
      fclose(local_8);
      if (*(int *)(param_1 + 0x81a8) != 0) {
        DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(*(undefined4 *)(param_1 + 0x81a8));
        *(undefined4 *)(param_1 + 0x81a8) = 0;
      }
      __11WriteBufferUl(local_24,0x100);
      local_10 = local_c;
      while (local_14 = local_14 - 1, -1 < (int)local_14) {
        appendByte__11WriteBufferc(local_24,(int)*local_10);
        local_10 = local_10 + 1;
      }
      uVar2 = getBuffer__C11WriteBuffer(local_24);
      uVar1 = getSize__C11WriteBuffer(local_24);
      uVar2 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar1,uVar2);
      *(undefined4 *)(param_1 + 0x81a8) = uVar2;
      if (*(int *)(param_1 + 0x81a8) == 0) {
        ___11WriteBuffer(local_24,2);
        uVar2 = 0;
      }
      else {
        free(local_c);
        iVar3 = GetLastError__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a8));
        if (iVar3 == 0) {
          ___11WriteBuffer(local_24,2);
          uVar2 = 1;
        }
        else {
          ___11WriteBuffer(local_24,2);
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}


