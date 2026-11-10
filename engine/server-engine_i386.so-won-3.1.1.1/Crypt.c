// Crypt_AuthChallenge1__FPviP15authchallenge_s  @ 000ce090
undefined4
Crypt_AuthChallenge1__FPviP15authchallenge_s(undefined2 *param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  size_t __n;
  uint uVar8;
  undefined1 local_44 [16];
  undefined1 local_34 [12];
  undefined1 local_28 [12];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined2 *local_c;
  undefined2 local_6;
  
  if (gAuthRequest == 0) {
    uVar4 = 0;
  }
  else {
    local_10 = GetCertificate__11AuthRequest(gAuthRequest);
    if (local_10 == 0) {
      uVar4 = 0;
    }
    else {
      local_6 = *param_1;
      local_c = param_1 + 1;
      local_14 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(local_c,local_6);
      if (local_14 == 0) {
        uVar4 = 1;
      }
      else {
        iVar5 = IsValid__C20WON_AuthFamilyBuffer(local_14);
        if (iVar5 == 0) {
          DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_14);
          uVar4 = 1;
        }
        else {
          iVar5 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(gAuthRequest,local_14);
          if (iVar5 == 0) {
            DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_14);
            uVar4 = 1;
          }
          else {
            uVar4 = GetUserId__C20WON_AuthCertificate1(local_14);
            *(undefined4 *)(param_3 + 0x34) = uVar4;
            uVar4 = GetPubKey__C20WON_AuthCertificate1(local_14);
            uVar1 = GetPubKeyLen__C20WON_AuthCertificate1(local_14);
            local_18 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar1,uVar4);
            if (local_18 == 0) {
              DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_14);
              uVar4 = 1;
            }
            else {
              local_1c = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
              if (local_1c == 0) {
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_14);
                DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                uVar4 = 1;
              }
              else {
                __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_28,0,0);
                uVar2 = GetKeyLen__C16WON_CryptKeyBase(local_1c);
                uVar8 = (uint)uVar2;
                uVar4 = GetKey__C16WON_CryptKeyBase(local_1c);
                Encrypt__15WON_EGPublicKeyPCvUl(local_34,local_18,uVar4,uVar8);
                __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                          (local_28,local_34);
                ___Q216WON_CryptKeyBase11CryptReturn(local_34,2);
                iVar5 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                if (iVar5 == 0) {
                  DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_14);
                  DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_1c);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_28,2);
                  uVar4 = 1;
                }
                else {
                  if (*(int *)(param_3 + 0x30) != 0) {
                    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                              (*(undefined4 *)(param_3 + 0x30));
                    *(undefined4 *)(param_3 + 0x30) = 0;
                  }
                  *(int *)(param_3 + 0x30) = local_1c;
                  __11WriteBufferUl(local_44,0x100);
                  appendLong__11WriteBufferl(local_44,0xffffffff);
                  appendByte__11WriteBufferc(local_44,0x34);
                  sVar3 = GetRawLen__C20WON_AuthFamilyBuffer(local_10);
                  appendShort__11WriteBuffers(local_44,(int)sVar3);
                  uVar2 = GetRawLen__C20WON_AuthFamilyBuffer(local_10);
                  uVar8 = (uint)uVar2;
                  uVar4 = GetRaw__C20WON_AuthFamilyBuffer(local_10);
                  append__11WriteBufferPCvUl(local_44,uVar4,uVar8);
                  sVar3 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  appendShort__11WriteBuffers(local_44,(int)sVar3);
                  uVar4 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  uVar6 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  append__11WriteBufferPCvUl(local_44,uVar6,uVar4);
                  if (*(int *)(param_3 + 0x2c) != 0) {
                    free(*(void **)(param_3 + 0x2c));
                  }
                  iVar5 = getSize__C11WriteBuffer(local_44);
                  pvVar7 = malloc(iVar5 + 1);
                  *(void **)(param_3 + 0x2c) = pvVar7;
                  __n = getSize__C11WriteBuffer(local_44);
                  pvVar7 = (void *)getBuffer__C11WriteBuffer(local_44);
                  memcpy(*(void **)(param_3 + 0x2c),pvVar7,__n);
                  uVar4 = getSize__C11WriteBuffer(local_44);
                  *(undefined4 *)(param_3 + 0x28) = uVar4;
                  ___11WriteBuffer(local_44,2);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_28,2);
                  uVar4 = 2;
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar4;
}


// Crypt_AuthChallenge2__FPviP15authchallenge_s  @ 000ce550
undefined4
Crypt_AuthChallenge2__FPviP15authchallenge_s(ushort *param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  size_t __n;
  uint uVar8;
  undefined1 local_58 [16];
  int local_48;
  undefined1 local_44 [16];
  undefined1 local_34 [12];
  undefined1 local_28 [12];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  ushort *local_8;
  
  local_c = (uint)*param_1;
  local_8 = param_1 + 1;
  if (gAuthRequest == 0) {
    uVar4 = 0;
  }
  else {
    local_14 = GetCertificate__11AuthRequest(gAuthRequest);
    if (local_14 == 0) {
      uVar4 = 0;
    }
    else {
      local_10 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(local_8,local_c & 0xffff);
      if (local_10 == 0) {
        uVar4 = 1;
      }
      else {
        local_8 = (ushort *)((int)local_8 + local_c);
        iVar5 = IsValid__C20WON_AuthFamilyBuffer(local_10);
        if (iVar5 == 0) {
          DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
          uVar4 = 1;
        }
        else {
          iVar5 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(gAuthRequest,local_10);
          if (iVar5 == 0) {
            DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
            uVar4 = 1;
          }
          else {
            uVar4 = GetPubKey__C20WON_AuthCertificate1(local_10);
            uVar1 = GetPubKeyLen__C20WON_AuthCertificate1(local_10);
            local_18 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar1,uVar4);
            if (local_18 == 0) {
              DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
              uVar4 = 1;
            }
            else {
              local_1c = GetPrivateKey__11AuthRequest(gAuthRequest);
              if (local_1c == 0) {
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
                DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                uVar4 = 1;
              }
              else {
                local_c = (uint)*local_8;
                local_8 = local_8 + 1;
                __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_28,0,0);
                Decrypt__16WON_EGPrivateKeyPCUcUl(local_34,local_1c,local_8,local_c);
                __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                          (local_28,local_34);
                ___Q216WON_CryptKeyBase11CryptReturn(local_34,2);
                iVar5 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                if ((iVar5 != 0) &&
                   (iVar5 = GetLastError__C16WON_CryptKeyBase(local_1c), iVar5 == 0)) {
                  if (gConnectionKey != 0) {
                    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(gConnectionKey);
                    gConnectionKey = 0;
                  }
                  uVar4 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  uVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  gConnectionKey = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(uVar1,uVar4);
                  if (gConnectionKey == 0) {
                    DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
                    DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                    ___Q216WON_CryptKeyBase11CryptReturn(local_28,2);
                    return 1;
                  }
                  __11WriteBufferUl(local_44,0x100);
                  local_48 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
                  if (local_48 == 0) {
                    DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
                    DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                    ___11WriteBuffer(local_44,2);
                    ___Q216WON_CryptKeyBase11CryptReturn(local_28,2);
                    return 1;
                  }
                  sVar2 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  appendShort__11WriteBuffers(local_44,(int)sVar2);
                  uVar4 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  uVar6 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  append__11WriteBufferPCvUl(local_44,uVar6,uVar4);
                  sVar2 = GetKeyLen__C16WON_CryptKeyBase(local_48);
                  appendShort__11WriteBuffers(local_44,(int)sVar2);
                  uVar3 = GetKeyLen__C16WON_CryptKeyBase(local_48);
                  uVar8 = (uint)uVar3;
                  uVar4 = GetKey__C16WON_CryptKeyBase(local_48);
                  append__11WriteBufferPCvUl(local_44,uVar4,uVar8);
                  if (*(int *)(param_3 + 0x30) != 0) {
                    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                              (*(undefined4 *)(param_3 + 0x30));
                    *(undefined4 *)(param_3 + 0x30) = 0;
                  }
                  *(int *)(param_3 + 0x30) = local_48;
                  uVar4 = getSize__C11WriteBuffer(local_44);
                  uVar6 = getBuffer__C11WriteBuffer(local_44);
                  Encrypt__15WON_EGPublicKeyPCvUl(local_34,local_18,uVar6,uVar4);
                  __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                            (local_28,local_34);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_34,2);
                  iVar5 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                  if ((iVar5 != 0) &&
                     (iVar5 = GetLastError__C16WON_CryptKeyBase(local_18), iVar5 == 0)) {
                    __11WriteBufferUl(local_58,0x100);
                    appendLong__11WriteBufferl(local_58,0xffffffff);
                    appendByte__11WriteBufferc(local_58,0x35);
                    sVar2 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                    appendShort__11WriteBuffers(local_58,(int)sVar2);
                    uVar4 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                    uVar6 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_28);
                    append__11WriteBufferPCvUl(local_58,uVar6,uVar4);
                    if (*(int *)(param_3 + 0x2c) != 0) {
                      free(*(void **)(param_3 + 0x2c));
                    }
                    iVar5 = getSize__C11WriteBuffer(local_58);
                    pvVar7 = malloc(iVar5 + 1);
                    *(void **)(param_3 + 0x2c) = pvVar7;
                    __n = getSize__C11WriteBuffer(local_58);
                    pvVar7 = (void *)getBuffer__C11WriteBuffer(local_58);
                    memcpy(*(void **)(param_3 + 0x2c),pvVar7,__n);
                    uVar4 = getSize__C11WriteBuffer(local_58);
                    *(undefined4 *)(param_3 + 0x28) = uVar4;
                    DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
                    DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                    ___11WriteBuffer(local_58,2);
                    ___11WriteBuffer(local_44,2);
                    ___Q216WON_CryptKeyBase11CryptReturn(local_28,2);
                    return 2;
                  }
                  DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
                  DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_48);
                  ___11WriteBuffer(local_44,2);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_28,2);
                  return 1;
                }
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(local_10);
                DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_18);
                ___Q216WON_CryptKeyBase11CryptReturn(local_28,2);
                uVar4 = 1;
              }
            }
          }
        }
      }
    }
  }
  return uVar4;
}


// Crypt_AuthComplete__FPviP15authchallenge_s  @ 000ced00
undefined4
Crypt_AuthComplete__FPviP15authchallenge_s(ushort *param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  void *pvVar6;
  size_t __n;
  ushort *__s2;
  undefined1 local_48 [16];
  int local_38;
  uint local_34;
  short local_30;
  ushort local_2e;
  undefined1 local_2c [12];
  undefined1 local_20 [12];
  int local_14;
  int local_10;
  uint local_c;
  ushort *local_8;
  
  local_c = (uint)*param_1;
  local_8 = param_1 + 1;
  if (gAuthRequest == 0) {
    uVar2 = 0;
  }
  else {
    local_10 = GetCertificate__11AuthRequest(gAuthRequest);
    if (local_10 == 0) {
      uVar2 = 0;
    }
    else {
      local_14 = GetPrivateKey__11AuthRequest(gAuthRequest);
      if (local_14 == 0) {
        uVar2 = 1;
      }
      else {
        __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_20,0,0);
        Decrypt__16WON_EGPrivateKeyPCUcUl(local_2c,local_14,local_8,local_c);
        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                  (local_20,local_2c);
        ___Q216WON_CryptKeyBase11CryptReturn(local_2c,2);
        iVar3 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_20);
        if ((iVar3 != 0) && (iVar3 = GetLastError__C16WON_CryptKeyBase(local_14), iVar3 == 0)) {
          uVar2 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_20);
          uVar4 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_20);
          __10ReadBufferPCcUl(local_2c,uVar4,uVar2);
          local_34 = 1;
          local_38 = *(int *)(param_3 + 0x30);
          if (local_38 == 0) {
            ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
            return 1;
          }
          uVar5 = readUShort__10ReadBufferPUs(local_2c,&local_2e);
          local_34 = local_34 & uVar5;
          local_8 = (ushort *)getDataPtr__10ReadBuffer(local_2c);
          uVar5 = skipBytes__10ReadBufferUl(local_2c,local_2e);
          local_34 = local_34 & uVar5;
          if ((local_34 != 0) &&
             (uVar1 = GetKeyLen__C16WON_CryptKeyBase(local_38), local_2e == uVar1)) {
            uVar5 = (uint)local_2e;
            __s2 = local_8;
            pvVar6 = (void *)GetKey__C16WON_CryptKeyBase(local_38);
            iVar3 = memcmp(pvVar6,__s2,uVar5);
            if (iVar3 != 0) {
              ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
              return 1;
            }
            local_34 = 1;
            uVar5 = readUShort__10ReadBufferPUs(local_2c,&local_30);
            local_34 = local_34 & uVar5;
            local_8 = (ushort *)getDataPtr__10ReadBuffer(local_2c);
            uVar5 = skipBytes__10ReadBufferUl(local_2c,local_30);
            local_34 = local_34 & uVar5;
            __11WriteBufferUl(local_48,0x100);
            appendLong__11WriteBufferl(local_48,0xffffffff);
            appendByte__11WriteBufferc(local_48,0x36);
            appendShort__11WriteBuffers(local_48,(int)local_30);
            append__11WriteBufferPCvUl(local_48,local_8,local_30);
            if (*(int *)(param_3 + 0x2c) != 0) {
              free(*(void **)(param_3 + 0x2c));
            }
            iVar3 = getSize__C11WriteBuffer(local_48);
            pvVar6 = malloc(iVar3 + 1);
            *(void **)(param_3 + 0x2c) = pvVar6;
            __n = getSize__C11WriteBuffer(local_48);
            pvVar6 = (void *)getBuffer__C11WriteBuffer(local_48);
            memcpy(*(void **)(param_3 + 0x2c),pvVar6,__n);
            uVar2 = getSize__C11WriteBuffer(local_48);
            *(undefined4 *)(param_3 + 0x28) = uVar2;
            ___11WriteBuffer(local_48,2);
            ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
            return 2;
          }
          ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
          return 1;
        }
        ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


// Crypt_AuthRequest__FPviP15authchallenge_s  @ 000cdec8
undefined4
Crypt_AuthRequest__FPviP15authchallenge_s(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  size_t __n;
  uint uVar6;
  undefined1 local_14 [16];
  
  if (gAuthRequest == 0) {
    uVar3 = 0;
  }
  else {
    __11WriteBufferUl(local_14,0x100);
    iVar4 = GetCertificate__11AuthRequest(gAuthRequest);
    if (iVar4 == 0) {
      ___11WriteBuffer(local_14,2);
      uVar3 = 0;
    }
    else {
      appendLong__11WriteBufferl(local_14,0xffffffff);
      appendByte__11WriteBufferc(local_14,0x33);
      sVar1 = GetRawLen__C20WON_AuthFamilyBuffer(iVar4);
      appendShort__11WriteBuffers(local_14,(int)sVar1);
      uVar2 = GetRawLen__C20WON_AuthFamilyBuffer(iVar4);
      uVar6 = (uint)uVar2;
      uVar3 = GetRaw__C20WON_AuthFamilyBuffer(iVar4);
      append__11WriteBufferPCvUl(local_14,uVar3,uVar6);
      if (*(int *)(param_3 + 0x2c) != 0) {
        free(*(void **)(param_3 + 0x2c));
      }
      iVar4 = getSize__C11WriteBuffer(local_14);
      pvVar5 = malloc(iVar4 + 1);
      *(void **)(param_3 + 0x2c) = pvVar5;
      __n = getSize__C11WriteBuffer(local_14);
      pvVar5 = (void *)getBuffer__C11WriteBuffer(local_14);
      memcpy(*(void **)(param_3 + 0x2c),pvVar5,__n);
      uVar3 = getSize__C11WriteBuffer(local_14);
      *(undefined4 *)(param_3 + 0x28) = uVar3;
      ___11WriteBuffer(local_14,2);
      uVar3 = 2;
    }
  }
  return uVar3;
}


// Crypt_CreateKey__FiPCUcPPv  @ 000cf5a8
undefined4 Crypt_CreateKey__FiPCUcPPv(undefined2 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (param_3 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    if (param_2 == 0) {
      local_8 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(param_1,0);
      if (local_8 == 0) {
        return 0;
      }
    }
    else {
      local_8 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(param_1,param_2);
    }
    *param_3 = local_8;
    uVar1 = 1;
  }
  return uVar1;
}


// Crypt_DecodeAuthComplete__FPviP15authchallenge_s  @ 000cf140
undefined4
Crypt_DecodeAuthComplete__FPviP15authchallenge_s(ushort *param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  void *__s2;
  int iVar3;
  uint __n;
  
  __n = (uint)*param_1;
  if (*(int *)(param_3 + 0x30) == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = *(undefined4 *)(param_3 + 0x30);
    uVar1 = GetKeyLen__C16WON_CryptKeyBase(uVar2);
    if (__n == uVar1) {
      __s2 = (void *)GetKey__C16WON_CryptKeyBase(uVar2);
      iVar3 = memcmp(param_1 + 1,__s2,__n);
      if (iVar3 == 0) {
        uVar2 = 2;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}


// Crypt_Decrypt__FPCvT0iPvPi  @ 000cf7d0
undefined4
Crypt_Decrypt__FPCvT0iPvPi
          (int param_1,undefined4 param_2,undefined4 param_3,void *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  size_t __n;
  void *__src;
  undefined1 local_20 [12];
  int local_14;
  undefined1 local_10 [12];
  
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_10,0,0);
  local_14 = param_1;
  if (param_1 == 0) {
    ___Q216WON_CryptKeyBase11CryptReturn(local_10,2);
    uVar1 = 0;
  }
  else {
    Decrypt__18WON_BFSymmetricKeyPCUcUl(local_20,param_1,param_2,param_3);
    __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(local_10,local_20);
    ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
    iVar2 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_10);
    if (iVar2 == 0) {
      ___Q216WON_CryptKeyBase11CryptReturn(local_10,2);
      uVar1 = 0;
    }
    else {
      __n = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_10);
      __src = (void *)GetData__CQ216WON_CryptKeyBase11CryptReturn(local_10);
      memcpy(param_4,__src,__n);
      uVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_10);
      *param_5 = uVar1;
      ___Q216WON_CryptKeyBase11CryptReturn(local_10,2);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// Crypt_DeleteAuthData__FP15authchallenge_s  @ 000cddec
void Crypt_DeleteAuthData__FP15authchallenge_s(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(int *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return;
}


// Crypt_DeleteKey__FPPv  @ 000cf618
void Crypt_DeleteKey__FPPv(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_1);
    *param_1 = 0;
  }
  return;
}


// Crypt_DestroyAuthObject__Fv  @ 000cbe6c
void Crypt_DestroyAuthObject__Fv(void)

{
  if (gAuthRequest != 0) {
    if (gAuthRequest != 0) {
      (**(code **)(*(int *)(gAuthRequest + 0x8028) + 8))(gAuthRequest,3);
    }
    gAuthRequest = 0;
  }
  return;
}


// Crypt_Encrypt__FPCvT0iPvPi  @ 000cf658
undefined4
Crypt_Encrypt__FPCvT0iPvPi
          (int param_1,undefined4 param_2,undefined4 param_3,void *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  size_t __n;
  void *__src;
  undefined1 local_20 [12];
  int local_14;
  undefined1 local_10 [12];
  
  __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_10,0,0);
  local_14 = param_1;
  if (param_1 == 0) {
    ___Q216WON_CryptKeyBase11CryptReturn(local_10,2);
    uVar1 = 0;
  }
  else {
    Encrypt__18WON_BFSymmetricKeyPCvUl(local_20,param_1,param_2,param_3);
    __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(local_10,local_20);
    ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
    iVar2 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_10);
    if (iVar2 == 0) {
      ___Q216WON_CryptKeyBase11CryptReturn(local_10,2);
      uVar1 = 0;
    }
    else {
      __n = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_10);
      __src = (void *)GetData__CQ216WON_CryptKeyBase11CryptReturn(local_10);
      memcpy(param_4,__src,__n);
      uVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_10);
      *param_5 = uVar1;
      ___Q216WON_CryptKeyBase11CryptReturn(local_10,2);
      uVar1 = 1;
    }
  }
  return uVar1;
}


// Crypt_GetAuthObject__Fv  @ 000cbcc8
undefined4 Crypt_GetAuthObject__Fv(void)

{
  return gAuthRequest;
}


// Crypt_GetCertificate__FPvPi  @ 000cb844
undefined4 Crypt_GetCertificate__FPvPi(void *param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  void *__src;
  
  if (gAuthRequest == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = GetCertificate__11AuthRequest(gAuthRequest);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      uVar3 = GetRawLen__C20WON_AuthFamilyBuffer(iVar2);
      *param_2 = uVar3 & 0xffff;
      if (*param_2 == 0) {
        uVar1 = 1;
      }
      else {
        uVar3 = *param_2;
        __src = (void *)GetRaw__C20WON_AuthFamilyBuffer(iVar2);
        memcpy(param_1,__src,uVar3);
        uVar1 = 2;
      }
    }
  }
  return uVar1;
}


// Crypt_GetConnectionKey__FPvPi  @ 000cde48
undefined4 Crypt_GetConnectionKey__FPvPi(void *param_1,uint *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  void *__src;
  uint uVar3;
  
  if (gConnectionKey == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = GetKeyLen__C16WON_CryptKeyBase(gConnectionKey);
    uVar3 = (uint)uVar1;
    __src = (void *)GetKey__C16WON_CryptKeyBase(gConnectionKey);
    memcpy(param_1,__src,uVar3);
    uVar3 = GetKeyLen__C16WON_CryptKeyBase(gConnectionKey);
    *param_2 = uVar3 & 0xffff;
    uVar2 = 2;
  }
  return uVar2;
}


// Crypt_GetNewCertificate__Fv  @ 000cb8e0
/* WARNING: Removing unreachable block (ram,0x000cba3d) */

bool Crypt_GetNewCertificate__Fv(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined1 local_12c [4];
  undefined4 local_128;
  undefined4 local_124;
  undefined1 local_120 [272];
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 3;
  local_c = 0;
  __11CServerList(local_120);
  local_124 = 0;
  local_128 = 0;
LAB_000cb920:
  do {
    local_8 = local_8 + -1;
    if ((local_8 < 0) || (local_c != 0)) {
      if ((gAuthRequest != 0) && (local_c == 0)) {
        if ((Callback_Printf != (code *)0x0) && (gAuthRequest != 0)) {
          uVar2 = GetLastError__11AuthRequest(gAuthRequest);
          (*Callback_Printf)(&DAT_000ee6b0,uVar2);
        }
        if (Callback_AuthFailure != (code *)0x0) {
          (*Callback_AuthFailure)();
        }
      }
      bVar4 = local_c != 0;
      ___11CServerList(local_120,2);
      return bVar4;
    }
    ResetAuthList__11CServerList(local_120);
LAB_000cb950:
    do {
      iVar1 = FillInNextAuthServer__11CServerList(local_120);
      if (iVar1 == 0) goto LAB_000cb920;
      if (gAuthRequest == 0) {
        uVar2 = __builtin_new(0x8404);
        uVar3 = GetAuthServerAddress__11CServerList(local_120);
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (local_12c,uVar3);
        uVar3 = GetAuthServerPort__11CServerList(local_120);
        gAuthRequest = __11AuthRequestPCcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                                 (uVar2,g_szExeName,g_szGUID,local_12c,uVar3);
        ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(local_12c,2)
        ;
        if (gAuthRequest == 0) goto LAB_000cb950;
      }
      else {
        uVar2 = GetAuthServerAddress__11CServerList(local_120);
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (local_12c,uVar2);
        uVar2 = GetAuthServerPort__11CServerList(local_120);
        setAddrAndPort__11AuthRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                  (gAuthRequest,local_12c,uVar2);
        ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(local_12c,2)
        ;
      }
      local_10 = getAuthVerifierKey__11AuthRequestPCc(gAuthRequest,"kver.kp");
      if (local_10 == 0) {
        local_10 = 0;
        goto LAB_000cb950;
      }
      local_10 = getCertificate__11AuthRequesti(gAuthRequest,1);
      if (local_10 == 0) {
        iVar1 = ReceivedResponse__11AuthRequest(gAuthRequest);
        if (iVar1 != 0) {
          local_8 = 0;
          goto LAB_000cb920;
        }
        goto LAB_000cb950;
      }
      iVar1 = GetCertificate__11AuthRequest(gAuthRequest);
      if (iVar1 != 0) {
        local_c = 1;
        goto LAB_000cb920;
      }
      iVar1 = ReceivedResponse__11AuthRequest(gAuthRequest);
    } while (iVar1 == 0);
    local_8 = 0;
  } while( true );
}


// Crypt_GetRawBFKey__FPvT0Pi  @ 000cdd70
undefined4 Crypt_GetRawBFKey__FPvT0Pi(int param_1,void *param_2,uint *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  void *__src;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = GetKeyLen__C16WON_CryptKeyBase(param_1);
    uVar3 = (uint)uVar1;
    __src = (void *)GetKey__C16WON_CryptKeyBase(param_1);
    memcpy(param_2,__src,uVar3);
    uVar3 = GetKeyLen__C16WON_CryptKeyBase(param_1);
    *param_3 = uVar3 & 0xffff;
    uVar2 = 2;
  }
  return uVar2;
}


// Crypt_GetUserId__Fv  @ 000cb7ec
undefined4 Crypt_GetUserId__Fv(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (gAuthRequest == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = GetCertificate__11AuthRequest(gAuthRequest);
    if (iVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = GetUserId__C20WON_AuthCertificate1(iVar2);
    }
  }
  return uVar1;
}


// Crypt_Initialize__FP13crypt_parms_s  @ 000cdc48
void Crypt_Initialize__FP13crypt_parms_s(undefined4 *param_1)

{
  g_authType = *param_1;
  strcpy(g_szGUID,(char *)param_1[2]);
  strcpy(g_szServerFile,(char *)param_1[3]);
  strcpy(g_szBaseDir,(char *)param_1[1]);
  strcpy(g_szExeName,(char *)param_1[4]);
  Callback_Printf = param_1[5];
  Callback_AuthFailure = param_1[6];
  if (param_1[7] == 0) {
    Callback_GetLocalizedString = STUB_Callback_GetLocalizedString__FUi;
  }
  else {
    Callback_GetLocalizedString = (code *)param_1[7];
  }
  return;
}


// Crypt_InstanceAuthObject__Fv  @ 000cbcdc
/* WARNING: Removing unreachable block (ram,0x000cbdbd) */

int Crypt_InstanceAuthObject__Fv(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_118 [4];
  undefined1 local_114 [272];
  
  __11CServerList(local_114);
  if (gAuthRequest == 0) {
    uVar2 = __builtin_new(0x8404);
    uVar3 = GetAuthServerAddress__11CServerList(local_114);
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (local_118,uVar3);
    uVar3 = GetAuthServerPort__11CServerList(local_114);
    gAuthRequest = __11AuthRequestPCcT1RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                             (uVar2,g_szExeName,g_szGUID,local_118,uVar3);
    ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(local_118,2);
  }
  iVar1 = gAuthRequest;
  ___11CServerList(local_114,2);
  return iVar1;
}


// Crypt_IsAuthenticated__Fv  @ 000cbec4
undefined4 Crypt_IsAuthenticated__Fv(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (gAuthRequest == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = GetCertificate__11AuthRequest(gAuthRequest);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// Crypt_MD5_File__FPUcPc  @ 000cdd0c
undefined4 Crypt_MD5_File__FPUcPc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = MD5_Hash_File__FPUcPciPUi(param_1,param_2,0,0);
  return uVar1;
}


// Crypt_ParseServers__FPc  @ 000cc1d4
int * Crypt_ParseServers__FPc(undefined4 param_1)

{
  uint16_t uVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined1 local_278 [2];
  uint16_t local_276;
  in_addr local_274;
  char local_268 [256];
  int local_168;
  uint local_164;
  undefined4 local_160;
  uint local_15c;
  char local_158 [64];
  void *local_118;
  size_t local_114;
  FILE *local_110;
  void *local_10c;
  char local_108 [256];
  int local_8;
  
  local_8 = 0;
  local_10c = (void *)0x0;
  local_160 = 0;
  uVar6 = param_1;
  sprintf(local_108,"%s/%s",g_szBaseDir,param_1);
  local_110 = fopen(local_108,"rb");
  if (local_110 == (FILE *)0x0) {
    sprintf(local_108,"valve/%s",param_1,uVar6);
    local_110 = fopen(local_108,"rb");
    if (local_110 == (FILE *)0x0) {
      return (int *)0;
    }
  }
  fseek(local_110,0,2);
  local_114 = ftell(local_110);
  fseek(local_110,0,0);
  if (((int)local_114 < 1) || (0x4000 < (int)local_114)) {
    fclose(local_110);
    local_8 = 0;
  }
  else {
    local_10c = malloc(local_114 + 1);
    if (local_10c == (void *)0x0) {
      fclose(local_110);
      local_8 = 0;
    }
    else {
      fread(local_10c,local_114,1,local_110);
      fclose(local_110);
      *(undefined1 *)((int)local_10c + local_114) = 0;
      local_118 = local_10c;
LAB_000cc390:
      local_118 = (void *)Crypt_Parse__FPc(local_118);
      sVar2 = strlen(&com_token);
      if (sVar2 != 0) {
        local_168 = 1;
        iVar3 = strcasecmp(&com_token,"Auth");
        if (iVar3 == 0) {
          local_164 = 0x1b59;
          local_168 = 0;
        }
        local_118 = (void *)Crypt_Parse__FPc(local_118);
        sVar2 = strlen(&com_token);
        if ((sVar2 == 0) || (iVar3 = strcasecmp(&com_token,"{"), iVar3 != 0)) goto LAB_000cc6b0;
        while( true ) {
          local_118 = (void *)Crypt_Parse__FPc(local_118);
          sVar2 = strlen(&com_token);
          if ((sVar2 == 0) || (iVar3 = strcasecmp(&com_token,"}"), iVar3 == 0)) break;
          sprintf(local_268,"%s",&com_token);
          local_118 = (void *)Crypt_Parse__FPc(local_118);
          sVar2 = strlen(&com_token);
          if ((sVar2 == 0) || (iVar3 = strcasecmp(&com_token,":"), iVar3 != 0)) break;
          local_118 = (void *)Crypt_Parse__FPc(local_118);
          sVar2 = strlen(&com_token);
          if (sVar2 == 0) break;
          local_15c = atoi(&com_token);
          sprintf(local_158,"%s:%i",local_268,local_15c);
          memset(local_278,0,0x10);
          iVar3 = Crypt_ResolveStringAddress__FPcP8sockaddr(local_158,local_278);
          if (iVar3 != 0) {
            uVar1 = ntohs(local_276);
            local_15c = (uint)uVar1;
            if (local_15c == 0) {
              local_15c = local_164;
            }
            pcVar4 = inet_ntoa(local_274);
            sprintf(local_268,"%s",pcVar4);
          }
          if (local_168 == 0) {
            piVar5 = (int *)__builtin_new(0x48);
            strcpy((char *)(piVar5 + 1),local_268);
            *(short *)(piVar5 + 0x11) = (short)local_15c;
            *piVar5 = local_8;
            local_8 = (int)piVar5;
          }
        }
        goto LAB_000cc390;
      }
LAB_000cc6b0:
      free(local_10c);
    }
  }
  return (int *)local_8;
}


// Crypt_Parse__FPc  @ 000cc030
char * Crypt_Parse__FPc(char *param_1)

{
  char cVar1;
  int iVar2;
  int local_c;
  
  local_c = 0;
  com_token = 0;
  if (param_1 == (char *)0x0) {
    com_token = 0;
    return (char *)0x0;
  }
  while( true ) {
    for (; cVar1 = *param_1, cVar1 < '!'; param_1 = param_1 + 1) {
      if (cVar1 == '\0') {
        com_token = 0;
        return (char *)0x0;
      }
    }
    if ((cVar1 != '/') || (param_1[1] != '/')) break;
    for (; (*param_1 != '\0' && (*param_1 != '\n')); param_1 = param_1 + 1) {
    }
  }
  if (cVar1 == '\"') {
    param_1 = param_1 + 1;
    while( true ) {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      if ((cVar1 == '\"') || (cVar1 == '\0')) break;
      (&com_token)[local_c] = cVar1;
      local_c = local_c + 1;
    }
    (&com_token)[local_c] = 0;
    return param_1;
  }
  if ((((cVar1 == '{') || (cVar1 == '}')) || (cVar1 == ')')) ||
     (((cVar1 == '(' || (cVar1 == '\'')) || (iVar2 = local_c, cVar1 == ':')))) {
    com_token = cVar1;
    DAT_00149a41 = 0;
    return param_1 + 1;
  }
  while( true ) {
    local_c = iVar2;
    (&com_token)[local_c] = cVar1;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    if ((cVar1 == '{') || (cVar1 == '}')) break;
    if ((cVar1 == ')') ||
       ((((cVar1 == '(' || (cVar1 == '\'')) || (cVar1 == ':')) || (iVar2 = local_c + 1, cVar1 < '!')
        ))) break;
  }
  (&DAT_00149a41)[local_c] = 0;
  return param_1;
}


// Crypt_ResolveStringAddress__FPcP8sockaddr  @ 000cbf00
undefined4 Crypt_ResolveStringAddress__FPcP8sockaddr(char *param_1,undefined2 *param_2)

{
  uint16_t uVar1;
  int iVar2;
  char *pcVar3;
  in_addr_t iVar4;
  hostent *phVar5;
  char local_8c [128];
  char *local_c;
  
  memset(param_2,0,0x10);
  *param_2 = 2;
  param_2[1] = 0;
  strcpy(local_8c,param_1);
  for (local_c = local_8c; *local_c != '\0'; local_c = local_c + 1) {
    if (*local_c == ':') {
      *local_c = '\0';
      iVar2 = atoi(local_c + 1);
      uVar1 = htons((uint16_t)iVar2);
      param_2[1] = uVar1;
    }
  }
  if (((local_8c[0] < '0') || ('9' < local_8c[0])) ||
     (pcVar3 = strstr(local_8c,"."), pcVar3 == (char *)0x0)) {
    phVar5 = gethostbyname(local_8c);
    if (phVar5 == (hostent *)0x0) {
      return 0;
    }
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)*phVar5->h_addr_list;
  }
  else {
    iVar4 = inet_addr(local_8c);
    *(in_addr_t *)(param_2 + 2) = iVar4;
  }
  return 1;
}


// Crypt_ReturnAPI  @ 000cdd34
undefined4 Crypt_ReturnAPI(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == 1) {
    puVar3 = &cryptapi;
    for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// Crypt_ServiceAuthRefresh__Fd  @ 000cf1d8
void Crypt_ServiceAuthRefresh__Fd(double param_1)

{
  if ((gAuthRequest != 0) && (15.0 <= param_1 - tLastService_543)) {
    tLastService_543 = param_1;
    HandleAuthRefresh__11AuthRequest(gAuthRequest);
  }
  return;
}


// Crypt_Shutdown__Fv  @ 000cdcf8
void Crypt_Shutdown__Fv(void)

{
  DeleteAuthObject__Fv();
  return;
}


// Crypt_Sign__FPciT0i  @ 000cf228
undefined4 Crypt_Sign__FPciT0i(undefined4 param_1,undefined4 param_2,void *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  size_t __n;
  void *__src;
  undefined4 uVar3;
  undefined1 local_20 [12];
  undefined1 local_14 [12];
  undefined4 local_8;
  
  if (gAuthRequest != 0) {
    local_8 = GetPrivateKey__11AuthRequest(gAuthRequest);
    __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_14,0,0);
    Sign__16WON_EGPrivateKeyPCvUl(local_20,local_8,param_1,param_2);
    __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn(local_14,local_20);
    ___Q216WON_CryptKeyBase11CryptReturn(local_20,2);
    iVar1 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_14);
    if (((iVar1 != 0) && (iVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_14), iVar1 != 0))
       && (uVar2 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_14), uVar2 <= param_4)) {
      __n = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_14);
      __src = (void *)GetData__CQ216WON_CryptKeyBase11CryptReturn(local_14);
      memcpy(param_3,__src,__n);
      uVar3 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_14);
      ___Q216WON_CryptKeyBase11CryptReturn(local_14,2);
      return uVar3;
    }
    ___Q216WON_CryptKeyBase11CryptReturn(local_14,2);
  }
  return 0;
}


