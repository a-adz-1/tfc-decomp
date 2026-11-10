// peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi  @ 000d34bc
undefined4
peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          int param_6,undefined4 param_7,undefined4 *param_8,undefined4 *param_9,int param_10,
          int param_11)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  time_t tVar9;
  undefined4 uVar10;
  void *__s2;
  undefined1 local_7c [12];
  undefined1 local_70 [12];
  undefined4 local_64;
  undefined1 local_60 [16];
  undefined4 local_50;
  undefined1 local_4c [12];
  undefined1 local_40 [12];
  undefined4 local_34;
  uint local_30;
  ushort local_2c;
  short local_2a;
  int local_28;
  undefined1 local_24 [12];
  undefined1 local_18 [16];
  time_t local_8;
  
  local_8 = time((time_t *)0x0);
  if ((((*(int *)(param_1 + 0x819c) == 0) || (*(int *)(param_1 + 0x81b0) < local_8)) ||
      (*(int *)(param_1 + 0x81b0) - local_8 < 0x1e)) &&
     (iVar5 = getCertificate__11AuthRequesti(param_1,1), iVar5 == 0)) {
    uVar4 = 0;
  }
  else {
    __11WriteBufferUl(local_18,0x100);
    appendLong__11WriteBufferl(local_18,0);
    appendLong__11WriteBufferl(local_18,0xcb);
    appendLong__11WriteBufferl(local_18,0x32);
    appendByte__11WriteBufferc(local_18,(int)(char)param_5);
    appendByte__11WriteBufferc(local_18,(int)(char)param_6);
    appendShort__11WriteBuffers(local_18,(int)(short)param_7);
    sVar1 = GetRawLen__C20WON_AuthFamilyBuffer(*(undefined4 *)(param_1 + 0x819c));
    appendShort__11WriteBuffers(local_18,(int)sVar1);
    uVar2 = GetRawLen__C20WON_AuthFamilyBuffer(*(undefined4 *)(param_1 + 0x819c));
    uVar6 = (uint)uVar2;
    uVar4 = GetRaw__C20WON_AuthFamilyBuffer(*(undefined4 *)(param_1 + 0x819c));
    append__11WriteBufferPCvUl(local_18,uVar4,uVar6);
    uVar4 = getSize__C11WriteBuffer(local_18);
    setLong__11WriteBufferUll(local_18,0,uVar4);
    __10ReadBuffer(local_24);
    iVar5 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                      (param_1,local_18,0xcb,0,local_24,param_2,0);
    if (iVar5 == 0) {
      ___11WriteBuffer(local_18,2);
      uVar4 = 0;
    }
    else {
      readULong__10ReadBufferPUl(local_24,&local_28);
      if (local_28 == 0x35) {
        readShort__10ReadBufferPs(local_24,&local_2a);
        if (param_11 == 0) {
          ___11WriteBuffer(local_18,2);
          uVar4 = 0;
        }
        else {
          iVar5 = getCertificate__11AuthRequesti(param_1,1);
          if (iVar5 == 0) {
            ___11WriteBuffer(local_18,2);
            uVar4 = 0;
          }
          else {
            uVar4 = peerLogin__11AuthRequestP15EasyTitanSocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iiiiPP20WON_AuthCertificate1PP18WON_BFSymmetricKeyPUsi
                              (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                               param_9,param_10,0);
            ___11WriteBuffer(local_18,2);
          }
        }
      }
      else if (local_28 == 0x33) {
        local_30 = 1;
        uVar6 = readUShort__10ReadBufferPUs(local_24,&local_2c);
        local_30 = local_30 & uVar6;
        local_34 = getDataPtr__10ReadBuffer(local_24);
        uVar6 = skipBytes__10ReadBufferUl(local_24,local_2c);
        local_30 = local_30 & uVar6;
        if (local_30 == 0) {
          Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message received from peer.");
          ___11WriteBuffer(local_18,2);
          uVar4 = 0;
        }
        else {
          __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_40,0,0);
          Decrypt__16WON_EGPrivateKeyPCUcUl
                    (local_4c,*(undefined4 *)(param_1 + 0x81ac),local_34,local_2c);
          __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                    (local_40,local_4c);
          ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
          uVar6 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_40);
          if (1 < uVar6) {
            puVar7 = (ushort *)GetData__CQ216WON_CryptKeyBase11CryptReturn(local_40);
            uVar2 = *puVar7;
            iVar5 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_40);
            if ((uint)uVar2 == iVar5 - 2U) {
              if (param_6 == 1) {
                iVar5 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_40);
                iVar5 = iVar5 + 2;
                sVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_40);
                uVar4 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(sVar1 + -2,iVar5);
                *param_9 = uVar4;
              }
              uVar6 = readUShort__10ReadBufferPUs(local_24,&local_2c);
              local_30 = local_30 & uVar6;
              local_34 = getDataPtr__10ReadBuffer(local_24);
              uVar6 = skipBytes__10ReadBufferUl(local_24,local_2c);
              local_30 = local_30 & uVar6;
              if (local_30 == 0) {
                Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message received from peer.");
                if (param_6 == 1) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                  *param_9 = 0;
                }
                ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                ___11WriteBuffer(local_18,2);
                return 0;
              }
              uVar4 = NewAuthCertificate1__15WON_AuthFactoryPCUcUs(local_34,local_2c);
              *param_8 = uVar4;
              iVar5 = verifyAuthStuff__11AuthRequestPC20WON_AuthFamilyBuffer(param_1,*param_8);
              if (iVar5 == 0) {
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                *param_8 = 0;
                ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                ___11WriteBuffer(local_18,2);
                return 0;
              }
              iVar8 = GetExpireTime__C20WON_AuthFamilyBuffer(*param_8);
              iVar5 = *(int *)(param_1 + 0x81b4);
              tVar9 = time((time_t *)0x0);
              if (iVar8 - iVar5 < tVar9) {
                Error_Printf__11AuthRequestiPce(param_1,2,"The server\'s certificate has expired.");
              }
              rewind__11WriteBuffer(local_18);
              appendLong__11WriteBufferl(local_18,0);
              appendLong__11WriteBufferl(local_18,0xcb);
              appendLong__11WriteBufferl(local_18,0x34);
              local_50 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
              __11WriteBufferUl(local_60,0x100);
              sVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_40);
              appendShort__11WriteBuffers(local_60,(int)(short)(sVar1 + -2));
              iVar5 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_40);
              iVar5 = iVar5 + -2;
              iVar8 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_40);
              append__11WriteBufferPCvUl(local_60,iVar8 + 2,iVar5);
              uVar2 = GetKeyLen__C16WON_CryptKeyBase(local_50);
              uVar6 = (uint)uVar2;
              uVar4 = GetKey__C16WON_CryptKeyBase(local_50);
              append__11WriteBufferPCvUl(local_60,uVar4,uVar6);
              uVar4 = GetPubKey__C20WON_AuthCertificate1(*param_8);
              uVar3 = GetPubKeyLen__C20WON_AuthCertificate1(*param_8);
              local_64 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(uVar3,uVar4);
              iVar5 = GetLastError__C16WON_CryptKeyBase(local_64);
              if (iVar5 != 0) {
                uVar4 = GetLastError__C16WON_CryptKeyBase(local_64);
                Error_Printf__11AuthRequestiPce
                          (param_1,2,"Error in Client B\'s public key: %s",uVar4);
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                *param_8 = 0;
                DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_64);
                DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_50);
                if (param_6 == 1) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                  *param_9 = 0;
                }
                ___11WriteBuffer(local_60,2);
                ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                ___11WriteBuffer(local_18,2);
                return 0;
              }
              __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_4c,0,0);
              uVar4 = getSize__C11WriteBuffer(local_60);
              uVar10 = getBuffer__C11WriteBuffer(local_60);
              Encrypt__15WON_EGPublicKeyPCvUl(local_70,local_64,uVar10,uVar4);
              __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                        (local_4c,local_70);
              ___Q216WON_CryptKeyBase11CryptReturn(local_70,2);
              iVar5 = GetLastError__C16WON_CryptKeyBase(local_64);
              if (iVar5 != 0) {
                uVar4 = GetLastError__C16WON_CryptKeyBase(local_64);
                Error_Printf__11AuthRequestiPce(param_1,2,"Error Encrypting secret data: %s",uVar4);
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                *param_8 = 0;
                DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_64);
                DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_50);
                if (param_6 == 1) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                  *param_9 = 0;
                }
                ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
                ___11WriteBuffer(local_60,2);
                ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                ___11WriteBuffer(local_18,2);
                return 0;
              }
              DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_64);
              sVar1 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_4c);
              appendShort__11WriteBuffers(local_18,(int)sVar1);
              uVar4 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_4c);
              uVar10 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_4c);
              append__11WriteBufferPCvUl(local_18,uVar10,uVar4);
              uVar4 = getSize__C11WriteBuffer(local_18);
              setLong__11WriteBufferUll(local_18,0,uVar4);
              iVar5 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                                (param_1,local_18,0xcb,0x35,local_24,param_2,0);
              if (iVar5 == 0) {
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                *param_8 = 0;
                DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_50);
                if (param_6 == 1) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                  *param_9 = 0;
                }
                ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
                ___11WriteBuffer(local_60,2);
                ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                ___11WriteBuffer(local_18,2);
                return 0;
              }
              uVar6 = readShort__10ReadBufferPs(local_24,&local_2a);
              local_30 = local_30 & uVar6;
              if ((local_30 == 0) || (local_2a < 0)) {
                if (local_30 == 0) {
                  Error_Printf__11AuthRequestiPce(param_1,2,"Error in message received from peer.");
                }
                else {
                  Error_Printf__11AuthRequestiPce
                            (param_1,2,"Error status on authentication: %d",(int)local_2a);
                }
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                *param_8 = 0;
                DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_50);
                if (param_6 == 1) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                  *param_9 = 0;
                }
                ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
                ___11WriteBuffer(local_60,2);
                ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                ___11WriteBuffer(local_18,2);
                return 0;
              }
              uVar6 = readUShort__10ReadBufferPUs(local_24,&local_2c);
              local_30 = local_30 & uVar6;
              local_34 = getDataPtr__10ReadBuffer(local_24);
              uVar6 = skipBytes__10ReadBufferUl(local_24,local_2c);
              local_30 = local_30 & uVar6;
              if (param_10 != 0) {
                uVar6 = readUShort__10ReadBufferPUs(local_24,param_10);
                local_30 = local_30 & uVar6;
              }
              if (local_30 == 0) {
                Error_Printf__11AuthRequestiPce(param_1,2,"Error in message received from peer.");
                DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
                *param_8 = 0;
                DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_50);
                if (param_6 == 1) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                  *param_9 = 0;
                }
                ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
                ___11WriteBuffer(local_60,2);
                ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                ___11WriteBuffer(local_18,2);
                return 0;
              }
              __Q216WON_CryptKeyBase11CryptReturnPUcUl(local_70,0,0);
              Decrypt__16WON_EGPrivateKeyPCUcUl
                        (local_7c,*(undefined4 *)(param_1 + 0x81ac),local_34,local_2c);
              __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                        (local_70,local_7c);
              ___Q216WON_CryptKeyBase11CryptReturn(local_7c,2);
              puVar7 = (ushort *)GetData__CQ216WON_CryptKeyBase11CryptReturn(local_70);
              local_2c = *puVar7;
              uVar6 = (uint)local_2c;
              iVar5 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_70);
              if ((uVar6 == iVar5 - 2U) &&
                 (uVar2 = GetKeyLen__C16WON_CryptKeyBase(local_50), local_2c == uVar2)) {
                uVar6 = (uint)local_2c;
                __s2 = (void *)GetKey__C16WON_CryptKeyBase(local_50);
                iVar5 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_70);
                iVar5 = memcmp((void *)(iVar5 + 2),__s2,uVar6);
                if (iVar5 == 0) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_50);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_70,2);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
                  ___11WriteBuffer(local_60,2);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
                  ___11WriteBuffer(local_18,2);
                  return 1;
                }
              }
              Error_Printf__11AuthRequestiPce(param_1,2,"Invalid secret returned by peer.");
              DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1(*param_8);
              *param_8 = 0;
              DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(local_50);
              if (param_6 == 1) {
                DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_9);
                *param_9 = 0;
              }
              ___Q216WON_CryptKeyBase11CryptReturn(local_70,2);
              ___Q216WON_CryptKeyBase11CryptReturn(local_4c,2);
              ___11WriteBuffer(local_60,2);
              ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
              ___11WriteBuffer(local_18,2);
              return 0;
            }
          }
          Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message received from peer.");
          ___Q216WON_CryptKeyBase11CryptReturn(local_40,2);
          ___11WriteBuffer(local_18,2);
          uVar4 = 0;
        }
      }
      else {
        Error_Printf__11AuthRequestiPce(param_1,2,"Invalid message type received from peer.");
        ___11WriteBuffer(local_18,2);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}


