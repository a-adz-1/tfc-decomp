// readServerKey__11AuthRequest  @ 000d4b18
undefined4 readServerKey__11AuthRequest(int param_1)

{
  undefined2 uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_124 [16];
  size_t local_114;
  char *local_110;
  char *local_10c;
  FILE *local_108;
  char local_104 [256];
  
  if (g_authType == 0) {
    puVar2 = &DAT_000ef6a6;
  }
  else {
    puVar2 = &DAT_000ef6a1;
  }
  sprintf(local_104,"auth/%s%u-%u.dat",puVar2,*(undefined4 *)(param_1 + 0x8008),
          *(undefined4 *)(param_1 + 4));
  CreatePath__11AuthRequestPc(param_1,local_104);
  local_108 = fopen(local_104,"rb");
  if (local_108 == (FILE *)0x0) {
    uVar3 = 0;
  }
  else {
    fseek(local_108,0,2);
    local_114 = ftell(local_108);
    fseek(local_108,0,0);
    local_10c = malloc(local_114 + 1);
    if (local_10c == (char *)0x0) {
      fclose(local_108);
      uVar3 = 0;
    }
    else {
      local_10c[local_114] = '\0';
      fread(local_10c,local_114,1,local_108);
      fclose(local_108);
      if (*(int *)(param_1 + 0x81a0) != 0) {
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                  (*(undefined4 *)(param_1 + 0x81a0));
        *(undefined4 *)(param_1 + 0x81a0) = 0;
      }
      __11WriteBufferUl(local_124,0x100);
      local_110 = local_10c;
      while (local_114 = local_114 - 1, -1 < (int)local_114) {
        appendByte__11WriteBufferc(local_124,(int)*local_110);
        local_110 = local_110 + 1;
      }
      uVar3 = getBuffer__C11WriteBuffer(local_124);
      uVar1 = getSize__C11WriteBuffer(local_124);
      uVar3 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(uVar1,uVar3);
      *(undefined4 *)(param_1 + 0x81a0) = uVar3;
      if (*(int *)(param_1 + 0x81a0) == 0) {
        ___11WriteBuffer(local_124,2);
        uVar3 = 0;
      }
      else {
        free(local_10c);
        iVar4 = GetLastError__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0));
        if (iVar4 == 0) {
          ___11WriteBuffer(local_124,2);
          uVar3 = 1;
        }
        else {
          DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                    (*(undefined4 *)(param_1 + 0x81a0));
          *(undefined4 *)(param_1 + 0x81a0) = 0;
          ___11WriteBuffer(local_124,2);
          uVar3 = 0;
        }
      }
    }
  }
  return uVar3;
}


