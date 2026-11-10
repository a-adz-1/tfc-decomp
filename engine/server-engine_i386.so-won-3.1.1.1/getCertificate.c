// getCertificate__11AuthRequesti  @ 000d2220
undefined4 getCertificate__11AuthRequesti(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  short sVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  void *__src;
  time_t tVar9;
  int iVar10;
  size_t __n;
  short local_1d2;
  undefined1 local_1d0 [16];
  char local_1c0 [256];
  undefined1 local_c0 [16];
  undefined1 local_b0 [16];
  undefined1 local_a0 [12];
  undefined4 local_94;
  uint local_90;
  uint local_8c;
  ushort local_86;
  int local_84;
  undefined1 local_80 [12];
  undefined1 local_74 [12];
  undefined4 local_68;
  undefined4 local_64;
  undefined2 local_60;
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [44];
  
  __15EasyTitanSocketQ210EasySocket10SocketTypeUl(local_30,1,0x8000);
  *(undefined4 *)(param_1 + 0x81f4) = 0;
  local_34 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                       (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
  local_38 = 0;
  cVar1 = __ne__H1Z12ES_ErrorType_RCX01T0_b(&local_34,&local_38);
  if (cVar1 == '\0') {
    if ((*(int *)(param_1 + 0x8198) == 0) &&
       (iVar6 = getPublicKeys__11AuthRequestP15EasyTitanSocket(param_1,local_30), iVar6 == 0)) {
      Error_Printf__11AuthRequestiPce(param_1,1,"Could not obtain pkey block");
      ___15EasyTitanSocket(local_30,2);
      uVar5 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x81a4) != 0) {
        DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                  (*(undefined4 *)(param_1 + 0x81a4));
        *(undefined4 *)(param_1 + 0x81a4) = 0;
      }
      if (*(int *)(param_1 + 0x81a0) == 0) {
        uVar5 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
        *(undefined4 *)(param_1 + 0x81a4) = uVar5;
      }
      else {
        uVar5 = GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0));
        uVar2 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a0));
        uVar5 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(uVar2,uVar5);
        *(undefined4 *)(param_1 + 0x81a4) = uVar5;
      }
      if (*(int *)(param_1 + 0x81a4) == 0) {
        Error_Printf__11AuthRequestiPce(param_1,2,"Unable to generate WON session key");
        ___15EasyTitanSocket(local_30,2);
        uVar5 = 0;
      }
      else {
        iVar6 = GetLastError__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a4));
        if (iVar6 == 0) {
          __11WriteBufferUl(local_4c,0x100);
          appendLong__11WriteBufferl(local_4c,0);
          appendLong__11WriteBufferl(local_4c,0xca);
          appendLong__11WriteBufferl(local_4c,0x28);
          sVar3 = GetBlockId__C23WON_AuthPublicKeyBlock1(*(undefined4 *)(param_1 + 0x8198));
          appendShort__11WriteBuffers(local_4c,(int)sVar3);
          appendByte__11WriteBufferc(local_4c,*(int *)(param_1 + 0x81ac) == 0);
          __11WriteBufferUl(local_5c,0x100);
          sVar3 = GetBlockId__C23WON_AuthPublicKeyBlock1(*(undefined4 *)(param_1 + 0x8198));
          appendShort__11WriteBuffers(local_5c,(int)sVar3);
          sVar3 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a4));
          appendShort__11WriteBuffers(local_5c,(int)sVar3);
          uVar4 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a4));
          uVar8 = (uint)uVar4;
          uVar5 = GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x81a4));
          append__11WriteBufferPCvUl(local_5c,uVar5,uVar8);
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (local_3c,param_1 + 0x812c);
          appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (local_5c,local_3c);
          ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (local_3c,2);
          GetFirstKey__C23WON_AuthPublicKeyBlock1(&local_64,*(undefined4 *)(param_1 + 0x8198));
          local_68 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(local_60,local_64);
          uVar5 = getSize__C11WriteBuffer(local_5c);
          uVar7 = getBuffer__C11WriteBuffer(local_5c);
          Encrypt__15WON_EGPublicKeyPCvUl(local_74,local_68,uVar7,uVar5);
          DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(local_68);
          iVar6 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_74);
          if (iVar6 == 0) {
            Error_Printf__11AuthRequestiPce(param_1,2,"Error encrypting login data.");
            ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
            ___11WriteBuffer(local_5c,2);
            ___11WriteBuffer(local_4c,2);
            ___15EasyTitanSocket(local_30,2);
            uVar5 = 0;
          }
          else {
            sVar3 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_74);
            appendShort__11WriteBuffers(local_4c,(int)sVar3);
            uVar5 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_74);
            uVar7 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_74);
            append__11WriteBufferPCvUl(local_4c,uVar7,uVar5);
            uVar5 = getSize__C11WriteBuffer(local_4c);
            setLong__11WriteBufferUll(local_4c,0,uVar5);
            __10ReadBuffer(local_80);
            iVar6 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                              (param_1,local_4c,0xca,0,local_80,local_30,0);
            if (iVar6 == 0) {
              Error_Printf__11AuthRequestiPce
                        (param_1,1,"Could not communicate with WON, check your internet connection")
              ;
              ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
              ___11WriteBuffer(local_5c,2);
              ___11WriteBuffer(local_4c,2);
              ___15EasyTitanSocket(local_30,2);
              uVar5 = 0;
            }
            else {
              readULong__10ReadBufferPUl(local_80,&local_84);
              if (local_84 == 0x2c) {
                iVar6 = readShort__10ReadBufferPs(local_80,&local_86);
                if ((iVar6 == 0) || (local_86 == 0)) {
                  Error_Printf__11AuthRequestiPce
                            (param_1,2,"Invalid message received from Auth server.");
                  ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                  ___11WriteBuffer(local_5c,2);
                  ___11WriteBuffer(local_4c,2);
                  ___15EasyTitanSocket(local_30,2);
                  uVar5 = 0;
                }
                else {
                  *(undefined4 *)(param_1 + 0x81f8) = 0;
                  *(int *)(param_1 + 0x81fc) = (int)(short)local_86;
                  iVar6 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
                                    (param_1,local_80,*(undefined4 *)(param_1 + 0x81a4));
                  if (iVar6 == 2) {
                    uVar5 = getCertificate__11AuthRequesti(param_1,0);
                    ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                    ___11WriteBuffer(local_5c,2);
                    ___11WriteBuffer(local_4c,2);
                    ___15EasyTitanSocket(local_30,2);
                  }
                  else {
                    ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                    ___11WriteBuffer(local_5c,2);
                    ___11WriteBuffer(local_4c,2);
                    ___15EasyTitanSocket(local_30,2);
                    uVar5 = 0;
                  }
                }
              }
              else if (local_84 == 0x29) {
                local_90 = 1;
                uVar8 = readUShort__10ReadBufferPUs(local_80,&local_86);
                local_90 = local_90 & uVar8;
                local_94 = getTheRest__10ReadBufferPUl(local_80,&local_8c);
                if ((local_90 == 0) || (local_86 != local_8c)) {
                  Error_Printf__11AuthRequestiPce(param_1,2,"Error in challenge message.");
                  ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                  ___11WriteBuffer(local_5c,2);
                  ___11WriteBuffer(local_4c,2);
                  ___15EasyTitanSocket(local_30,2);
                  uVar5 = 0;
                }
                else {
                  Decrypt__18WON_BFSymmetricKeyPCUcUl
                            (local_a0,*(undefined4 *)(param_1 + 0x81a4),local_94,local_86);
                  __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                            (local_74,local_a0);
                  ___Q216WON_CryptKeyBase11CryptReturn(local_a0,2);
                  iVar6 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_74);
                  if (iVar6 == 0) {
                    Error_Printf__11AuthRequestiPce(param_1,2,"Error in challenge seed encryption.")
                    ;
                    ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                    ___11WriteBuffer(local_5c,2);
                    ___11WriteBuffer(local_4c,2);
                    ___15EasyTitanSocket(local_30,2);
                    uVar5 = 0;
                  }
                  else {
                    __n = 0x10;
                    __src = (void *)GetData__CQ216WON_CryptKeyBase11CryptReturn(local_74);
                    memcpy(local_b0,__src,__n);
                    if (*(int *)(param_1 + 0x81a0) != 0) {
                      DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                                (*(undefined4 *)(param_1 + 0x81a0));
                      *(undefined4 *)(param_1 + 0x81a0) = 0;
                    }
                    uVar5 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,local_b0);
                    *(undefined4 *)(param_1 + 0x81a0) = uVar5;
                    storeServerKey__11AuthRequest(param_1);
                    strcpy(local_1c0,(char *)(param_1 + 0x802c));
                    if (g_authType == 0) {
                      strcat(local_1c0,";engine_i386.so");
                    }
                    else if (g_authType == 1) {
                      sprintf(local_1c0,"engine_i386.so");
                    }
                    iVar6 = MD5_Hash_File__FPUcPciPUi(local_c0,local_1c0,0,0);
                    if (iVar6 == 0) {
                      Error_Printf__11AuthRequestiPce(param_1,2,"Validation failure - 2.");
                      ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                      ___11WriteBuffer(local_5c,2);
                      ___11WriteBuffer(local_4c,2);
                      ___15EasyTitanSocket(local_30,2);
                      uVar5 = 0;
                    }
                    else {
                      __11WriteBufferUl(local_1d0,0x100);
                      append__11WriteBufferPCvUl(local_1d0,local_c0,0x10);
                      iVar6 = ComputeSeededMD5andCRCForFileGroup__11AuthRequestPUcPcPUi
                                        (param_1,local_c0,local_1c0,local_b0);
                      if (iVar6 == 0) {
                        Error_Printf__11AuthRequestiPce(param_1,2,"Validation failure - 3.");
                        ___11WriteBuffer(local_1d0,2);
                        ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                        ___11WriteBuffer(local_5c,2);
                        ___11WriteBuffer(local_4c,2);
                        ___15EasyTitanSocket(local_30,2);
                        uVar5 = 0;
                      }
                      else {
                        append__11WriteBufferPCvUl(local_1d0,local_c0,0x10);
                        rewind__11WriteBuffer(local_4c);
                        appendLong__11WriteBufferl(local_4c,0);
                        appendLong__11WriteBufferl(local_4c,0xca);
                        appendLong__11WriteBufferl(local_4c,0x2a);
                        uVar5 = getSize__C11WriteBuffer(local_1d0);
                        uVar7 = getBuffer__C11WriteBuffer(local_1d0);
                        Encrypt__18WON_BFSymmetricKeyPCvUl
                                  (local_a0,*(undefined4 *)(param_1 + 0x81a4),uVar7,uVar5);
                        __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                                  (local_74,local_a0);
                        ___Q216WON_CryptKeyBase11CryptReturn(local_a0,2);
                        iVar6 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_74);
                        if (iVar6 == 0) {
                          Error_Printf__11AuthRequestiPce
                                    (param_1,2,"Error encrypting checksum response.");
                          ___11WriteBuffer(local_1d0,2);
                          ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                          ___11WriteBuffer(local_5c,2);
                          ___11WriteBuffer(local_4c,2);
                          ___15EasyTitanSocket(local_30,2);
                          uVar5 = 0;
                        }
                        else {
                          sVar3 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_74);
                          appendShort__11WriteBuffers(local_4c,(int)sVar3);
                          uVar5 = GetLen__CQ216WON_CryptKeyBase11CryptReturn(local_74);
                          uVar7 = GetData__CQ216WON_CryptKeyBase11CryptReturn(local_74);
                          append__11WriteBufferPCvUl(local_4c,uVar7,uVar5);
                          uVar5 = getSize__C11WriteBuffer(local_4c);
                          setLong__11WriteBufferUll(local_4c,0,uVar5);
                          iVar6 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                                            (param_1,local_4c,0xca,0x2c,local_80,local_30,0);
                          if (iVar6 == 0) {
                            Error_Printf__11AuthRequestiPce
                                      (param_1,1,
                                       "Did not receive a response from WON Authentication server, please check your internet connection."
                                      );
                            ___11WriteBuffer(local_1d0,2);
                            ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                            ___11WriteBuffer(local_5c,2);
                            ___11WriteBuffer(local_4c,2);
                            ___15EasyTitanSocket(local_30,2);
                            uVar5 = 0;
                          }
                          else {
                            uVar8 = readShort__10ReadBufferPs(local_80,&local_1d2);
                            local_90 = local_90 & uVar8;
                            *(undefined4 *)(param_1 + 0x81f8) = 1;
                            *(int *)(param_1 + 0x81fc) = (int)local_1d2;
                            iVar6 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
                                              (param_1,local_80,*(undefined4 *)(param_1 + 0x81a4));
                            if ((iVar6 == 0) || (local_1d2 != 0)) {
                              ___11WriteBuffer(local_1d0,2);
                              ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                              ___11WriteBuffer(local_5c,2);
                              ___11WriteBuffer(local_4c,2);
                              ___15EasyTitanSocket(local_30,2);
                              uVar5 = 0;
                            }
                            else {
                              *(undefined4 *)(param_1 + 0x8194) = 1;
                              tVar9 = time((time_t *)0x0);
                              iVar6 = GetExpireTime__C20WON_AuthFamilyBuffer
                                                (*(undefined4 *)(param_1 + 0x819c));
                              iVar10 = GetIssueTime__C20WON_AuthFamilyBuffer
                                                 (*(undefined4 *)(param_1 + 0x819c));
                              *(int *)(param_1 + 0x81b0) = (iVar6 - iVar10) + tVar9;
                              iVar6 = GetIssueTime__C20WON_AuthFamilyBuffer
                                                (*(undefined4 *)(param_1 + 0x819c));
                              tVar9 = time((time_t *)0x0);
                              *(int *)(param_1 + 0x81b4) = iVar6 - tVar9;
                              ___11WriteBuffer(local_1d0,2);
                              ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                              ___11WriteBuffer(local_5c,2);
                              ___11WriteBuffer(local_4c,2);
                              ___15EasyTitanSocket(local_30,2);
                              uVar5 = 1;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else {
                ___Q216WON_CryptKeyBase11CryptReturn(local_74,2);
                ___11WriteBuffer(local_5c,2);
                ___11WriteBuffer(local_4c,2);
                ___15EasyTitanSocket(local_30,2);
                uVar5 = 0;
              }
            }
          }
        }
        else {
          Error_Printf__11AuthRequestiPce(param_1,2,"Unable to generate WON session key");
          DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                    (*(undefined4 *)(param_1 + 0x81a4));
          *(undefined4 *)(param_1 + 0x81a4) = 0;
          ___15EasyTitanSocket(local_30,2);
          uVar5 = 0;
        }
      }
    }
  }
  else {
    ES_ErrorTypeToString__F12ES_ErrorType(local_3c,local_34);
    uVar5 = c_str__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                      (local_3c);
    Error_Printf__11AuthRequestiPce(param_1,1,"Error connecting to Auth server: %s",uVar5);
    ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(local_3c,2);
    ___15EasyTitanSocket(local_30,2);
    uVar5 = 0;
  }
  return uVar5;
}


