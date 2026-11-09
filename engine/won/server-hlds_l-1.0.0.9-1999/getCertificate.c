// getCertificate__11AuthRequesti  @ 08092110
undefined4 getCertificate__11AuthRequesti(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  time_t tVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  char *pcVar13;
  short local_1c6;
  uint local_1c4;
  ushort local_1c0;
  short local_1be;
  int local_1bc;
  undefined4 local_1b8;
  undefined2 local_1b4;
  undefined1 local_1b0 [16];
  char local_1a0 [260];
  undefined1 local_9c [16];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c [12];
  undefined1 local_70 [12];
  undefined4 *local_64;
  undefined4 local_60;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined *local_38;
  undefined *local_34;
  undefined1 local_30 [44];
  
  __15EasyTitanSocketQ210EasySocket10SocketTypeUl(local_30,1,0x8000);
  *(undefined4 *)(param_1 + 0x8090) = 0;
  iVar6 = connect__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0iii
                    (local_30,param_1,*(undefined4 *)(param_1 + 4),5000,1);
  if (iVar6 == 0) {
    if (*(int *)(param_1 + 0x802c) == 0) {
      iVar6 = getPublicKeys__11AuthRequestP15EasyTitanSocket(param_1,local_30);
      if (iVar6 == 0) {
        Error_Printf__11AuthRequestiPce(param_1,1,"Could not obtain pkey block");
        ___15EasyTitanSocket(local_30,2);
        return 0;
      }
    }
    if (*(int *)(param_1 + 0x8038) != 0) {
      DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                (*(undefined4 *)(param_1 + 0x8038));
      *(undefined4 *)(param_1 + 0x8038) = 0;
    }
    if (*(int *)(param_1 + 0x8034) == 0) {
      uVar7 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,0);
      *(undefined4 *)(param_1 + 0x8038) = uVar7;
    }
    else {
      uVar7 = GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8034));
      uVar4 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8034),uVar7);
      uVar7 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(uVar4);
      *(undefined4 *)(param_1 + 0x8038) = uVar7;
    }
    if (*(int *)(param_1 + 0x8038) == 0) {
      Error_Printf__11AuthRequestiPce(param_1,2,"Unable to generate WON session key");
      ___15EasyTitanSocket(local_30,2);
      uVar7 = 0;
    }
    else if (**(int **)(param_1 + 0x8038) == 0) {
      gcc2_compiled_(local_48,0x100);
      appendLong__11WriteBufferl(local_48,0);
      appendLong__11WriteBufferl(local_48,0xca);
      appendLong__11WriteBufferl(local_48,0x28);
      sVar5 = GetBlockId__C23WON_AuthPublicKeyBlock1(*(undefined4 *)(param_1 + 0x802c));
      appendShort__11WriteBuffers(local_48,(int)sVar5);
      appendByte__11WriteBufferc(local_48,*(int *)(param_1 + 0x8040) == 0);
      gcc2_compiled_(local_58,0x100);
      sVar5 = GetBlockId__C23WON_AuthPublicKeyBlock1(*(undefined4 *)(param_1 + 0x802c));
      appendShort__11WriteBuffers(local_58,(int)sVar5);
      sVar5 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8038));
      appendShort__11WriteBuffers(local_58,(int)sVar5);
      uVar4 = GetKeyLen__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8038));
      uVar7 = GetKey__C16WON_CryptKeyBase(*(undefined4 *)(param_1 + 0x8038),uVar4);
      append__11WriteBufferPCvUl(local_58,uVar7);
      if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc]
          == '\0') {
        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
             _8_4_ + 1;
        local_38 = &force_to_data;
      }
      else {
        local_38 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
      }
      uVar11 = 0xffffffff;
      pcVar13 = &g_szGUID;
      do {
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        cVar3 = *pcVar13;
        pcVar13 = pcVar13 + 1;
      } while (cVar3 != '\0');
      replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                (&local_38,0,0xffffffff,&g_szGUID,~uVar11 - 1);
      appendString__11WriteBufferRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                (local_58,&local_38);
      puVar1 = (undefined4 *)(local_38 + -0x10);
      piVar2 = (int *)(local_38 + -8);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        if (*(int *)(local_38 + -0xc) + 0x10U < 0x81) {
          iVar6 = (*(int *)(local_38 + -0xc) + 0x17U >> 3) * 4;
          pthread_mutex_lock((pthread_mutex_t *)
                             _t24__default_alloc_template2b1i0___node_allocator_lock);
          *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar6);
          *(undefined4 **)(&DAT_080ab95c + iVar6) = puVar1;
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
        }
        else {
          free(puVar1);
        }
      }
      GetFirstKey__C23WON_AuthPublicKeyBlock1(&local_1b8,*(undefined4 *)(param_1 + 0x802c));
      uVar7 = NewEGPublicKey__16WON_CryptFactoryUsPCUc(local_1b4,local_1b8);
      uVar8 = getSize__C11WriteBuffer(local_58);
      uVar8 = getBuffer__C11WriteBuffer(local_58,uVar8);
      Encrypt__15WON_EGPublicKeyPCvUl(&local_64,uVar7,uVar8);
      DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(uVar7);
      if (local_64 == (undefined4 *)0x0) {
        Error_Printf__11AuthRequestiPce(param_1,2,"Error encrypting login data.");
        ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
        ___11WriteBuffer(local_58,2);
        ___11WriteBuffer(local_48,2);
        ___15EasyTitanSocket(local_30,2);
        uVar7 = 0;
      }
      else {
        appendShort__11WriteBuffers(local_48,(int)(short)local_60);
        append__11WriteBufferPCvUl(local_48,local_64,local_60);
        uVar7 = getSize__C11WriteBuffer(local_48);
        setLong__11WriteBufferUll(local_48,0,uVar7);
        gcc2_compiled_(local_70);
        iVar6 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                          (param_1,local_48,0xca,0,local_70,local_30,0);
        if (iVar6 == 0) {
          Error_Printf__11AuthRequestiPce
                    (param_1,1,"Could not communicate with WON, check your internet connection");
          ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
          ___11WriteBuffer(local_58,2);
          ___11WriteBuffer(local_48,2);
          ___15EasyTitanSocket(local_30,2);
          uVar7 = 0;
        }
        else {
          readULong__10ReadBufferPUl(local_70,&local_1bc);
          if (local_1bc == 0x2c) {
            iVar6 = readShort__10ReadBufferPs(local_70,&local_1be);
            if ((iVar6 == 0) || (local_1be == 0)) {
              Error_Printf__11AuthRequestiPce
                        (param_1,2,"Invalid message received from Auth server.");
              ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
              ___11WriteBuffer(local_58,2);
              ___11WriteBuffer(local_48,2);
              ___15EasyTitanSocket(local_30,2);
              uVar7 = 0;
            }
            else {
              *(undefined4 *)(param_1 + 0x8094) = 0;
              *(int *)(param_1 + 0x8098) = (int)local_1be;
              iVar6 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
                                (param_1,local_70,*(undefined4 *)(param_1 + 0x8038));
              if (iVar6 == 2) {
                uVar7 = getCertificate__11AuthRequesti(param_1,0);
                ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                ___11WriteBuffer(local_58,2);
                ___11WriteBuffer(local_48,2);
                ___15EasyTitanSocket(local_30,2);
              }
              else {
                ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                ___11WriteBuffer(local_58,2);
                ___11WriteBuffer(local_48,2);
                ___15EasyTitanSocket(local_30,2);
                uVar7 = 0;
              }
            }
          }
          else if (local_1bc == 0x29) {
            uVar11 = readUShort__10ReadBufferPUs(local_70,&local_1c0);
            uVar7 = getTheRest__10ReadBufferPUl(local_70,&local_1c4);
            if (((uVar11 & 1) == 0) || (local_1c0 != local_1c4)) {
              Error_Printf__11AuthRequestiPce(param_1,2,"Error in challenge message.");
              ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
              ___11WriteBuffer(local_58,2);
              ___11WriteBuffer(local_48,2);
              ___15EasyTitanSocket(local_30,2);
              uVar7 = 0;
            }
            else {
              Decrypt__18WON_BFSymmetricKeyPCUcUl
                        (local_7c,*(undefined4 *)(param_1 + 0x8038),uVar7,local_1c0);
              __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                        (&local_64,local_7c);
              ___Q216WON_CryptKeyBase11CryptReturn(local_7c,2);
              if (local_64 == (undefined4 *)0x0) {
                Error_Printf__11AuthRequestiPce(param_1,2,"Error in challenge seed encryption.");
                ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                ___11WriteBuffer(local_58,2);
                ___11WriteBuffer(local_48,2);
                ___15EasyTitanSocket(local_30,2);
                uVar7 = 0;
              }
              else {
                local_8c = *local_64;
                local_88 = local_64[1];
                local_84 = local_64[2];
                local_80 = local_64[3];
                if (*(int *)(param_1 + 0x8034) != 0) {
                  DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                            (*(undefined4 *)(param_1 + 0x8034));
                  *(undefined4 *)(param_1 + 0x8034) = 0;
                }
                uVar7 = NewBFSymmetricKey__16WON_CryptFactoryUsPCUc(8,&local_8c);
                *(undefined4 *)(param_1 + 0x8034) = uVar7;
                storeServerKey__11AuthRequest(param_1);
                strcpy(local_1a0,g_szEXEName);
                iVar6 = MD5_Hash_File(local_9c,local_1a0,1,0,0);
                if (iVar6 == 0) {
                  Error_Printf__11AuthRequestiPce(param_1,2,"Validation failure - 2.");
                  ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                  ___11WriteBuffer(local_58,2);
                  ___11WriteBuffer(local_48,2);
                  ___15EasyTitanSocket(local_30,2);
                  uVar7 = 0;
                }
                else {
                  gcc2_compiled_(local_1b0,0x100);
                  append__11WriteBufferPCvUl(local_1b0,local_9c,0x10);
                  iVar6 = MD5CRCHash__FPUcPcPUi(local_9c,local_1a0,&local_8c);
                  if (iVar6 == 0) {
                    Error_Printf__11AuthRequestiPce(param_1,2,"Validation failure - 3.");
                    ___11WriteBuffer(local_1b0,2);
                    ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                    ___11WriteBuffer(local_58,2);
                    ___11WriteBuffer(local_48,2);
                    ___15EasyTitanSocket(local_30,2);
                    uVar7 = 0;
                  }
                  else {
                    append__11WriteBufferPCvUl(local_1b0,local_9c,0x10);
                    rewind__11WriteBuffer(local_48);
                    appendLong__11WriteBufferl(local_48,0);
                    appendLong__11WriteBufferl(local_48,0xca);
                    appendLong__11WriteBufferl(local_48,0x2a);
                    uVar7 = getSize__C11WriteBuffer(local_1b0);
                    uVar7 = getBuffer__C11WriteBuffer(local_1b0,uVar7);
                    Encrypt__18WON_BFSymmetricKeyPCvUl
                              (local_7c,*(undefined4 *)(param_1 + 0x8038),uVar7);
                    __as__Q216WON_CryptKeyBase11CryptReturnRCQ216WON_CryptKeyBase11CryptReturn
                              (&local_64,local_7c);
                    ___Q216WON_CryptKeyBase11CryptReturn(local_7c,2);
                    if (local_64 == (undefined4 *)0x0) {
                      Error_Printf__11AuthRequestiPce
                                (param_1,2,"Error encrypting checksum response.");
                      ___11WriteBuffer(local_1b0,2);
                      ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                      ___11WriteBuffer(local_58,2);
                      ___11WriteBuffer(local_48,2);
                      ___15EasyTitanSocket(local_30,2);
                      uVar7 = 0;
                    }
                    else {
                      appendShort__11WriteBuffers(local_48,(int)(short)local_60);
                      append__11WriteBufferPCvUl(local_48,local_64,local_60);
                      uVar7 = getSize__C11WriteBuffer(local_48);
                      setLong__11WriteBufferUll(local_48,0,uVar7);
                      iVar6 = request__12TitanRequestP11WriteBufferUlUlP10ReadBufferP15EasyTitanSocketUl
                                        (param_1,local_48,0xca,0x2c,local_70,local_30,0);
                      if (iVar6 == 0) {
                        Error_Printf__11AuthRequestiPce
                                  (param_1,1,
                                   "Did not receive a response from WON Authentication server, please check your internet connection."
                                  );
                        ___11WriteBuffer(local_1b0,2);
                        ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                        ___11WriteBuffer(local_58,2);
                        ___11WriteBuffer(local_48,2);
                        ___15EasyTitanSocket(local_30,2);
                        uVar7 = 0;
                      }
                      else {
                        readShort__10ReadBufferPs(local_70,&local_1c6);
                        *(undefined4 *)(param_1 + 0x8094) = 1;
                        *(int *)(param_1 + 0x8098) = (int)local_1c6;
                        iVar6 = handleLoginReply__11AuthRequestP10ReadBufferP18WON_BFSymmetricKey
                                          (param_1,local_70,*(undefined4 *)(param_1 + 0x8038));
                        if ((iVar6 == 0) || (local_1c6 != 0)) {
                          ___11WriteBuffer(local_1b0,2);
                          ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                          ___11WriteBuffer(local_58,2);
                          ___11WriteBuffer(local_48,2);
                          ___15EasyTitanSocket(local_30,2);
                          uVar7 = 0;
                        }
                        else {
                          *(undefined4 *)(param_1 + 0x8044) = 1;
                          tVar9 = time((time_t *)0x0);
                          iVar6 = GetExpireTime__C20WON_AuthFamilyBuffer
                                            (*(undefined4 *)(param_1 + 0x8030));
                          iVar10 = GetIssueTime__C20WON_AuthFamilyBuffer
                                             (*(undefined4 *)(param_1 + 0x8030));
                          *(time_t *)(param_1 + 0x8048) = tVar9 + (iVar6 - iVar10);
                          iVar6 = GetIssueTime__C20WON_AuthFamilyBuffer
                                            (*(undefined4 *)(param_1 + 0x8030));
                          tVar9 = time((time_t *)0x0);
                          *(int *)(param_1 + 0x804c) = iVar6 - tVar9;
                          ___11WriteBuffer(local_1b0,2);
                          ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
                          ___11WriteBuffer(local_58,2);
                          ___11WriteBuffer(local_48,2);
                          ___15EasyTitanSocket(local_30,2);
                          uVar7 = 1;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            ___Q216WON_CryptKeyBase11CryptReturn(&local_64,2);
            ___11WriteBuffer(local_58,2);
            ___11WriteBuffer(local_48,2);
            ___15EasyTitanSocket(local_30,2);
            uVar7 = 0;
          }
        }
      }
    }
    else {
      Error_Printf__11AuthRequestiPce(param_1,2,"Unable to generate WON session key");
      DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey
                (*(undefined4 *)(param_1 + 0x8038));
      *(undefined4 *)(param_1 + 0x8038) = 0;
      ___15EasyTitanSocket(local_30,2);
      uVar7 = 0;
    }
  }
  else {
    ES_ErrorTypeToString__F12ES_ErrorType(&local_34,iVar6);
    if (*(int *)(local_34 + -0x10) == 0) {
      puVar12 = &DAT_080a8ac3;
    }
    else {
      local_34[*(int *)(local_34 + -0x10)] = 0;
      puVar12 = local_34;
    }
    Error_Printf__11AuthRequestiPce(param_1,1,"Error connecting to Auth server: %s",puVar12);
    puVar1 = (undefined4 *)(local_34 + -0x10);
    piVar2 = (int *)(local_34 + -8);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      if (*(int *)(local_34 + -0xc) + 0x10U < 0x81) {
        iVar6 = (*(int *)(local_34 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar6);
        *(undefined4 **)(&DAT_080ab95c + iVar6) = puVar1;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free(puVar1);
      }
    }
    ___15EasyTitanSocket(local_30,2);
    uVar7 = 0;
  }
  return uVar7;
}


